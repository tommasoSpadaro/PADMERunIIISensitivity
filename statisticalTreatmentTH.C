#include "statisticalTreatmentTH.hh"
#include "TMath.h"
#include "TFitResultPtr.h"
#include "TFitResult.h"
#include "TFitter.h"
#include "TFile.h"
#include "TFeldmanCousins.h"
#include "TDecompChol.h"
#include "TMatrixD.h"
#include "TRolke.h"

#include <iostream>
#include <iomanip>

struct signalPower{
  int isqrts;//index of sqrts point
  double sqrts; // sqrts
  double signalYield;
};

struct by_yield_desc
{
  bool operator()(signalPower const &a, signalPower const &b) const noexcept
  {
    if(a.isqrts==b.isqrts){
      return false;
    }else{
      return a.signalYield > b.signalYield;
    }
  }
};


statisticalTreatmentTH::statisticalTreatmentTH(){
  cout << "Allocating statisticalTreatmentTH " << endl;
  fConfigPtr = statConfig::GetInstance();
  
  fNumberOfGenerations = fConfigPtr->GetNumberOfGenerations(); // number of toys
  fNumberOfGenerationsExpectedLimit = fConfigPtr->GetNumberOfGenerationsExpectedLimit(); // number of pseudo data 

  cout << "Allocating expected CL bands " << endl;
  fNCLBands = 2; // here, number of bands to be done
  fCLBand = new Double_t[fNCLBands];
  fCLBand[0] = 0.68;
  fCLBand[1] = 0.95;
  fNCLAvgs = 1+2*fNCLBands; // median, (left,right)xfNCLBands

  cout << "Allocating expected CL output " << endl;
  fExtractedCLS = new Double_t[fNCLAvgs];  // number of extracted CLS: median, left-right 1 sigma, left-right 2 sigma
  fLabel = "none";

  fErrorImprove = fConfigPtr->GetErrorImprove();
  fUseNuisance = fConfigPtr->GetUseNuisance(); // by default use nuisance

  // init random numbers
  fRndmNumber = new TRandom3();
  fSeed = fConfigPtr->GetSeed();
  fRndmNumber->SetSeed(fSeed);

  // default with minimum verbosity = 0
  // minimum verbosity = 1
  // some verbosity = 2
  // max verbosity = 3
  fVerbosity = fConfigPtr->GetVerbosity();

  // initialise default values of the grid
  
  fMassStep  =  fConfigPtr->GetMassStep(); //0.02;//0.01; //MeV
  fMassMin   =  fConfigPtr->GetMassMin(); //16.22; // MeV
  fMassMax   =  fConfigPtr->GetMassMax(); //17.62; // MeV
  fNMassBins =  (fMassMax-fMassMin)/fMassStep + 1; // 128 linear steps in mass
  
  fNgveBins =  fConfigPtr->GetNgveBins(); //40;
  fgveMin   =  fConfigPtr->GetgveMin(); //1E-4;
  fgveMax   =  fConfigPtr->GetgveMax(); //6E-4;
  fgveStep  =  (fgveMax*fgveMax*fgveMax*fgveMax - fgveMin*fgveMin*fgveMin*fgveMin)/fNgveBins; // linear steps in gve^4

  // number of point used in the frequentist window
  
  fFrequentistNPoints = fConfigPtr->GetFrequentistNPoints(); // number of points for integration for the frequentist methods (FC, RL)  
  
  // input filename

  fInputFileName = fConfigPtr->GetInputFileName();

  // print out of constructor  
  
  cout << "Init Structs " << endl;
  cout << "observables are filled: " << fObservables.isNotFilled << endl;
  cout << "expectedErrors are filled: " << fExpectedErrors.isNotFilled << endl;
  cout << "signalPlusBackground-profiled nuisances are filled: " << fTheta_S.isNotFilled << endl;
  cout << "Background-profiled nuisances are filled: " << fTheta_B.isNotFilled << endl;
  
  initHistograms();
  fIsInitialized = false;
}

statisticalTreatmentTH::~statisticalTreatmentTH(){

  cout << "deleting..." << endl;

  delete[] fCLBand;
  delete[] fExtractedCLS;
  delete fRndmNumber;

  if(fPotGraphUsed  != nullptr) delete fPotGraphUsed ;
  if(fEffiGraphUsed != nullptr) delete fEffiGraphUsed;
  if(fBkgGraphUsed  != nullptr) delete fBkgGraphUsed ;
  if(fNormBkgGraphUsed  != nullptr) delete fNormBkgGraphUsed ;

  delete fLBHisto;
  
  fLSBHisto.clear(); 
  fQobsHisto.clear(); 
  delete fQobsAvgHisto; 
  delete fLB_BtoyHisto; 
  fLSB_BtoyHisto.clear();
  fQbRelHisto.clear();
  fLSB_SBtoyHisto.clear();
  fQsRelHisto.clear();
  
  cout << "..." << endl;

}

void statisticalTreatmentTH::Init(){
  TFile* filo = new TFile(fInputFileName.Data(), "READ");
  TGraphErrors* potGraph = (TGraphErrors*) filo->Get("gPoT");
  TGraphErrors* effiGraph = (TGraphErrors*) filo->Get("gEff");
  TGraphErrors* bkgGraph = (TGraphErrors*) filo->Get("gBkg");

  fObservables.NObs.clear();
  fObservables.SqrtsObs.clear();
  fObservables.POTObs.clear();
  fObservables.SignalEffiLocalObs.clear();
  fObservables.BkgObs.clear();

  fExpectedErrors.POTLocalErr.clear();
  fExpectedErrors.SignalEffiLocalErr.clear();
  fExpectedErrors.BkgErr.clear();

  std::cout << "Reading input file with " << potGraph->GetN() << " points" << std::endl;

  double signalEfficiencyFac = 1.;
  double bkgyieldFac = 1;  
  if (fConfigPtr->GetManipulateInput()){ 
    signalEfficiencyFac = 0.8;
    bkgyieldFac = 0.8;
  }

  
  for (int i=0; i<potGraph->GetN(); i++){
    if (potGraph->GetY()[i] < 1E6) continue; // might add sqrts range or other quality cuts to exclude given points here [e.g.: scan up points vs scan dw points]
    // retrieve Sqrt(s) values
    fObservables.SqrtsObs.push_back(potGraph->GetX()[i]); // sqrt(s) observed
    // retrieve periods of the scan TO BE ACTUALLY IMPLEMENTED!!!!!!!
    if (i%2==0) fObservables.ScanPeriod.push_back(0); // period 0
    else        fObservables.ScanPeriod.push_back(1); // period 1
    // retrieve POT values and errors, set in 1E10 units
    fObservables.POTObs.push_back(potGraph->GetY()[i]/1E10); // POTs observed in 1E10 units    

    
    fExpectedErrors.POTLocalErr.push_back(potGraph->GetEY()[i]/1E10/fErrorImprove); // POTs error
    // retrieve signal efficiencies and errors
    fObservables.SignalEffiLocalObs.push_back(effiGraph->GetY()[i]*signalEfficiencyFac); // signal effi
    fExpectedErrors.SignalEffiLocalErr.push_back(effiGraph->GetEY()[i]*signalEfficiencyFac/fErrorImprove); // signal effi error
    // retrieve expected background and error
    fObservables.BkgObs.push_back(bkgGraph->GetY()[i]*bkgyieldFac); // bkg yield
    fExpectedErrors.BkgErr.push_back(bkgGraph->GetEY()[i]*bkgyieldFac/fErrorImprove); // bkg yield error    
  }
  filo->Close();
  delete filo;
  
  std::cout << "After selection keep " << fObservables.SqrtsObs.size() << " points" << std::endl;

  // store manipulated input in TGraphErrors in memory

  fPotGraphUsed  = new TGraphErrors(fObservables.SqrtsObs.size()); fPotGraphUsed  ->SetName("fPotGraphUsed");
  fEffiGraphUsed = new TGraphErrors(fObservables.SqrtsObs.size()); fEffiGraphUsed ->SetName("fEffiGraphUsed");
  fBkgGraphUsed  = new TGraphErrors(fObservables.SqrtsObs.size()); fBkgGraphUsed  ->SetName("fBkgGraphUsed");
  fNormBkgGraphUsed  = new TGraphErrors(fObservables.SqrtsObs.size()); fNormBkgGraphUsed  ->SetName("fNormBkgGraphUsed");
  for (uint i=0; i<fObservables.SqrtsObs.size(); i++){
    fPotGraphUsed  ->SetPoint(i,fObservables.SqrtsObs.at(i),fObservables.POTObs.at(i));
    fPotGraphUsed  ->SetPointError(i,0.,fExpectedErrors.POTLocalErr.at(i));

    fEffiGraphUsed ->SetPoint(i,fObservables.SqrtsObs.at(i),fObservables.SignalEffiLocalObs.at(i));
    fEffiGraphUsed ->SetPointError(i,0.,fExpectedErrors.SignalEffiLocalErr.at(i));

    fBkgGraphUsed  ->SetPoint(i,fObservables.SqrtsObs.at(i),fObservables.BkgObs.at(i));
    fBkgGraphUsed  ->SetPointError(i,0.,fExpectedErrors.BkgErr.at(i));

    fNormBkgGraphUsed  ->SetPoint(i,fObservables.SqrtsObs.at(i),fObservables.BkgObs.at(i)/fObservables.SignalEffiLocalObs.at(i));
    fNormBkgGraphUsed  ->SetPointError(i,0.,fNormBkgGraphUsed->GetY()[i]*TMath::Sqrt(
										     pow(fExpectedErrors.BkgErr.at(i)/fObservables.BkgObs.at(i),2)+
										     pow(fExpectedErrors.SignalEffiLocalErr.at(i)/fObservables.SignalEffiLocalObs.at(i),2)
										     ));
  }


  // iniialise the other observables

  fObservables.SignalPeakYieldObs = fConfigPtr->GetSignalPeakYield();   // 13.56, times the voigt value at the peak gives a signal yield at the peak of 2.26 x gve^2 for BES = 0.0022 (1.80 x gve^2 at BES=0.005)
  //fObservables.SignalPeakYieldObs = 12.46;          // this, times the voigt value at the peak gives a signal yield at the peak of 2.26 x gve^2 for BES = 0.0022 (1.80 x gve^2 at BES=0.005)
  fObservables.SignalLorentzianWidthObs = fConfigPtr->GetSignalLorentzianWidth();     // 1.72 MeV, estimated value of lorentzian width for the signal shape expressed on pbeam
  //fObservables.SignalLorentzianWidthObs = 0.;       // MeV, estimated value of lorentzian width for the signal shape expressed on pbeam
  fObservables.BESObs = fConfigPtr->GetBES();                     // 0.0025 relative BES
  fObservables.POTScaleObs = fConfigPtr->GetPOTScale();           // 1. absolute relative scale correction on the POT [independent on sqrt(s)]

  fExpectedErrors.SignalPeakYieldErr = fConfigPtr->GetSignalPeakYieldErr();        // 0.18 i.e., 1.4% relative uncertainty on the signal yield at the peak
  fExpectedErrors.SignalLorentzianWidthErr = fConfigPtr->GetSignalLorentzianWidthErr();  // 0.038 MeV, absolute error on the signal lorentzian width
  fExpectedErrors.BESErr = fConfigPtr->GetBESErr();                  // 0.0005 error on the relative BES
  fExpectedErrors.POTScaleErr = fConfigPtr->GetPOTScaleErr();        // 0.01 error on absolute POT scale [independent on the sqrt(s)]
  fExpectedErrors.isNotFilled = false;  // Expected errors is initialised

  // other observables, not necessarily used 

  fObservables.BkgBiasObsP0 = fConfigPtr->GetBkgBiasObsP0();
  fObservables.BkgBiasObsP1 = fConfigPtr->GetBkgBiasObsP1();
  fExpectedErrors.BkgBiasErrP0 = fConfigPtr->GetBkgBiasErrP0();
  fExpectedErrors.BkgBiasErrP1 = fConfigPtr->GetBkgBiasErrP1();
  fExpectedErrors.BkgBiasErrP0P1Corr = fConfigPtr->GetBkgBiasErrP0P1Corr();

  // if needed, diagonalise covariance matrix to be able to generate fluctuations of correlated parameters
  
  for (int i=0; i<2; i++) {
    for (int j=0; j<2; j++) {
      if (i==j) {
	fInvCholeTransBkgBias[i][j] = 1;
	fInvCholeTransEffiOverBkgScan1st[i][j] = 1;
	fInvCholeTransEffiOverBkgScan2nd[i][j] = 1;
      } else {
	fInvCholeTransBkgBias[i][j] = 0;
	fInvCholeTransEffiOverBkgScan1st[i][j] = 0;
	fInvCholeTransEffiOverBkgScan2nd[i][j] = 0;
      }
    }
  }  

  TDecompChol* chole = new TDecompChol(2);
  
  if (fConfigPtr->GetCorrectBkgBias()){ 
    double elements[4] = {
      fExpectedErrors.BkgBiasErrP0*fExpectedErrors.BkgBiasErrP0,
      fExpectedErrors.BkgBiasErrP0*fExpectedErrors.BkgBiasErrP1*fExpectedErrors.BkgBiasErrP0P1Corr,
      fExpectedErrors.BkgBiasErrP0*fExpectedErrors.BkgBiasErrP1*fExpectedErrors.BkgBiasErrP0P1Corr,
      fExpectedErrors.BkgBiasErrP1*fExpectedErrors.BkgBiasErrP1};
    TMatrixDSym cov(2,elements);
    TMatrixDSym invCov = cov.Invert(); // apparently this inverts cov as well
    chole->SetMatrix(invCov);   // use Cholesky decomposition
    chole->Decompose();         // use Cholesky decomposition
    TMatrixD choleTrans = chole->GetU();
    TMatrixD invCholeTrans = choleTrans.Invert();
    for (int i=0; i<2; i++) {
      for (int j=0; j<2; j++) {
	fInvCholeTransBkgBias[i][j] = invCholeTrans[i][j];
      }
    }
  }

  // curves for effi/(bkg/pot) vs sqrt(s)
  
  for (int i=0; i<3; i++){
    fObservables.EffiOverBkgObsP0[i] = fConfigPtr->GetEffiOverBkgObsP0(i);
    fObservables.EffiOverBkgObsP1[i] = fConfigPtr->GetEffiOverBkgObsP1(i);
    fExpectedErrors.EffiOverBkgErrP0[i] = fConfigPtr->GetEffiOverBkgErrP0(i);
    fExpectedErrors.EffiOverBkgErrP1[i] = fConfigPtr->GetEffiOverBkgErrP1(i);
    fExpectedErrors.EffiOverBkgErrP0P1Corr[i] = fConfigPtr->GetEffiOverBkgErrP0P1Corr(i);
  }

  if (fConfigPtr->GetAssumeEffiOverBkgCurve()){ 
    for (int k=0; k<2; k++){ // first, second period of the scan
      double elements[4] = {
	fExpectedErrors.EffiOverBkgErrP0[k]*fExpectedErrors.EffiOverBkgErrP0[k],
	fExpectedErrors.EffiOverBkgErrP0[k]*fExpectedErrors.EffiOverBkgErrP1[k]*fExpectedErrors.EffiOverBkgErrP0P1Corr[k],
	fExpectedErrors.EffiOverBkgErrP0[k]*fExpectedErrors.EffiOverBkgErrP1[k]*fExpectedErrors.EffiOverBkgErrP0P1Corr[k],
	fExpectedErrors.EffiOverBkgErrP1[k]*fExpectedErrors.EffiOverBkgErrP1[k]};
      TMatrixDSym cov(2,elements);
      TMatrixDSym invCov = cov.Invert(); // apparently this inverts cov as well
      chole->SetMatrix(invCov);   // use Cholesky decomposition
      chole->Decompose();         // use Cholesky decomposition
      TMatrixD choleTrans = chole->GetU();
      TMatrixD invCholeTrans = choleTrans.Invert();
      for (int i=0; i<2; i++) {
	for (int j=0; j<2; j++) {
	  if (k==0) fInvCholeTransEffiOverBkgScan1st[i][j] = invCholeTrans[i][j];
	  else      fInvCholeTransEffiOverBkgScan2nd[i][j] = invCholeTrans[i][j];
	}
      }
    }
  }

  delete chole;

  // initialise starting values of the nuisance parameters

  fTheta_S = InitNuisanceToObservables(fObservables); // init but flagged as nonInitialised
  fTheta_B = InitNuisanceToObservables(fObservables); // init but flagged as nonInitialised

  // initialise likelihood

  fLikeli.SetObservables(fObservables);
  fLikeli.SetExpectedErrors(fExpectedErrors);

  // initialize fitters

  initFitters(false); // SB fitter
  initFitters(true); // B fitter
  
  // print out
  
  cout << "Init From histo" << endl;
  cout << "observables are filled: " << fObservables.isNotFilled << endl;
  cout << "expectedErrors are filled: " << fExpectedErrors.isNotFilled << endl;
  cout << "signalPlusBackground-profiled nuisances are filled: " << fTheta_S.isNotFilled << endl;
  cout << "Background-profiled nuisances are filled: " << fTheta_B.isNotFilled << endl;

  // set initflag to TRUE
  fIsInitialized = true;
}



//NOTUSEDANYMORE void statisticalTreatmentTH::InitFromFile(TString filename, double errorImprove, Bool_t useNuisance){
//NOTUSEDANYMORE   fErrorImprove = errorImprove;
//NOTUSEDANYMORE   fUseNuisance = useNuisance;
//NOTUSEDANYMORE   // store info from incoming tgraph
//NOTUSEDANYMORE 
//NOTUSEDANYMORE   TFile* filo = new TFile(filename.Data(), "READ");
//NOTUSEDANYMORE   TGraphErrors* potGraph = (TGraphErrors*) filo->Get("gPoT");
//NOTUSEDANYMORE   TGraphErrors* effiGraph = (TGraphErrors*) filo->Get("gEff");
//NOTUSEDANYMORE   TGraphErrors* bkgGraph = (TGraphErrors*) filo->Get("gBkg");
//NOTUSEDANYMORE 
//NOTUSEDANYMORE   fObservables.NObs.clear();
//NOTUSEDANYMORE   fObservables.SqrtsObs.clear();
//NOTUSEDANYMORE   fObservables.POTObs.clear();
//NOTUSEDANYMORE   fObservables.SignalEffiLocalObs.clear();
//NOTUSEDANYMORE   fObservables.BkgObs.clear();
//NOTUSEDANYMORE 
//NOTUSEDANYMORE   fExpectedErrors.POTLocalErr.clear();
//NOTUSEDANYMORE   fExpectedErrors.SignalEffiLocalErr.clear();
//NOTUSEDANYMORE   fExpectedErrors.BkgErr.clear();
//NOTUSEDANYMORE 
//NOTUSEDANYMORE   std::cout << "Reading input file with " << potGraph->GetN() << " points" << std::endl;
//NOTUSEDANYMORE   
//NOTUSEDANYMORE   for (int i=0; i<potGraph->GetN(); i++){
//NOTUSEDANYMORE     if (potGraph->GetY()[i] < 1E6) continue; // might add sqrts range or other quality cuts to exclude given points here [e.g.: scan up points vs scan dw points]
//NOTUSEDANYMORE     // retrieve Sqrt(s) values
//NOTUSEDANYMORE     fObservables.SqrtsObs.push_back(potGraph->GetX()[i]); // sqrt(s) observed
//NOTUSEDANYMORE     // retrieve POT values and errors, set in 1E10 units
//NOTUSEDANYMORE     fObservables.POTObs.push_back(potGraph->GetY()[i]/1E10); // POTs observed in 1E10 units    
//NOTUSEDANYMORE     fExpectedErrors.POTLocalErr.push_back(potGraph->GetEY()[i]/1E10/fErrorImprove); // POTs error
//NOTUSEDANYMORE     // retrieve signal efficiencies and errors
//NOTUSEDANYMORE     fObservables.SignalEffiLocalObs.push_back(effiGraph->GetY()[i]*0.8); // signal effi
//NOTUSEDANYMORE     fExpectedErrors.SignalEffiLocalErr.push_back(effiGraph->GetEY()[i]*0.8/fErrorImprove); // signal effi error
//NOTUSEDANYMORE     // retrieve expected background and error
//NOTUSEDANYMORE     fObservables.BkgObs.push_back(bkgGraph->GetY()[i]*0.8); // bkg yield
//NOTUSEDANYMORE     fExpectedErrors.BkgErr.push_back(bkgGraph->GetEY()[i]*0.8/fErrorImprove); // bkg yield error    
//NOTUSEDANYMORE   }
//NOTUSEDANYMORE   filo->Close();
//NOTUSEDANYMORE   delete filo;
//NOTUSEDANYMORE   
//NOTUSEDANYMORE   std::cout << "After selection keep " << fObservables.SqrtsObs.size() << " points" << std::endl;
//NOTUSEDANYMORE 
//NOTUSEDANYMORE   // store manipulated input in TGraphErrors in memory
//NOTUSEDANYMORE 
//NOTUSEDANYMORE   fPotGraphUsed  = new TGraphErrors(fObservables.SqrtsObs.size()); fPotGraphUsed  ->SetName("fPotGraphUsed");
//NOTUSEDANYMORE   fEffiGraphUsed = new TGraphErrors(fObservables.SqrtsObs.size()); fEffiGraphUsed ->SetName("fEffiGraphUsed");
//NOTUSEDANYMORE   fBkgGraphUsed  = new TGraphErrors(fObservables.SqrtsObs.size()); fBkgGraphUsed  ->SetName("fBkgGraphUsed");
//NOTUSEDANYMORE   fNormBkgGraphUsed  = new TGraphErrors(fObservables.SqrtsObs.size()); fNormBkgGraphUsed  ->SetName("fNormBkgGraphUsed");
//NOTUSEDANYMORE   for (uint i=0; i<fObservables.SqrtsObs.size(); i++){
//NOTUSEDANYMORE     fPotGraphUsed  ->SetPoint(i,fObservables.SqrtsObs.at(i),fObservables.POTObs.at(i));
//NOTUSEDANYMORE     fPotGraphUsed  ->SetPointError(i,0.,fExpectedErrors.POTLocalErr.at(i));
//NOTUSEDANYMORE 
//NOTUSEDANYMORE     fEffiGraphUsed ->SetPoint(i,fObservables.SqrtsObs.at(i),fObservables.SignalEffiLocalObs.at(i));
//NOTUSEDANYMORE     fEffiGraphUsed ->SetPointError(i,0.,fExpectedErrors.SignalEffiLocalErr.at(i));
//NOTUSEDANYMORE 
//NOTUSEDANYMORE     fBkgGraphUsed  ->SetPoint(i,fObservables.SqrtsObs.at(i),fObservables.BkgObs.at(i));
//NOTUSEDANYMORE     fBkgGraphUsed  ->SetPointError(i,0.,fExpectedErrors.BkgErr.at(i));
//NOTUSEDANYMORE 
//NOTUSEDANYMORE     fNormBkgGraphUsed  ->SetPoint(i,fObservables.SqrtsObs.at(i),fObservables.BkgObs.at(i)/fObservables.SignalEffiLocalObs.at(i));
//NOTUSEDANYMORE     fNormBkgGraphUsed  ->SetPointError(i,0.,fNormBkgGraphUsed->GetY()[i]*TMath::Sqrt(
//NOTUSEDANYMORE 										     pow(fExpectedErrors.BkgErr.at(i)/fObservables.BkgObs.at(i),2)+
//NOTUSEDANYMORE 										     pow(fExpectedErrors.SignalEffiLocalErr.at(i)/fObservables.SignalEffiLocalObs.at(i),2)
//NOTUSEDANYMORE 										     ));
//NOTUSEDANYMORE   }
//NOTUSEDANYMORE 
//NOTUSEDANYMORE 
//NOTUSEDANYMORE   // iniialise the other observables
//NOTUSEDANYMORE 
//NOTUSEDANYMORE   fObservables.SignalPeakYieldObs = 13.56;          // this, times the voigt value at the peak gives a signal yield at the peak of 2.26 x gve^2 for BES = 0.0022 (1.80 x gve^2 at BES=0.005)
//NOTUSEDANYMORE   //fObservables.SignalPeakYieldObs = 12.46;          // this, times the voigt value at the peak gives a signal yield at the peak of 2.26 x gve^2 for BES = 0.0022 (1.80 x gve^2 at BES=0.005)
//NOTUSEDANYMORE   fObservables.SignalLorentzianWidthObs = 1.72;     // MeV, estimated value of lorentzian width for the signal shape expressed on pbeam
//NOTUSEDANYMORE   //fObservables.SignalLorentzianWidthObs = 0.;       // MeV, estimated value of lorentzian width for the signal shape expressed on pbeam
//NOTUSEDANYMORE   fObservables.BESObs = 0.0025;                     // relative BES
//NOTUSEDANYMORE   fObservables.POTScaleObs = 1.;                    // absolute relative scale correction on the POT [independent on sqrt(s)]
//NOTUSEDANYMORE 
//NOTUSEDANYMORE   fExpectedErrors.SignalPeakYieldErr = 0.18;        // i.e., 1.4% relative uncertainty on the signal yield at the peak
//NOTUSEDANYMORE   fExpectedErrors.SignalLorentzianWidthErr = 0.038;  // MeV, absolute error on the signal lorentzian width
//NOTUSEDANYMORE   fExpectedErrors.BESErr = 0.0005;                  // error on the relative BES
//NOTUSEDANYMORE   fExpectedErrors.POTScaleErr = 0.01;               // error on absolute POT scale [independent on the sqrt(s)]
//NOTUSEDANYMORE   fExpectedErrors.isNotFilled = false;  // Expected errors is initialised
//NOTUSEDANYMORE   
//NOTUSEDANYMORE   // initialise starting values of the nuisance parameters
//NOTUSEDANYMORE 
//NOTUSEDANYMORE   fTheta_S = InitNuisanceToObservables(fObservables); // init but flagged as nonInitialised
//NOTUSEDANYMORE   fTheta_B = InitNuisanceToObservables(fObservables); // init but flagged as nonInitialised
//NOTUSEDANYMORE 
//NOTUSEDANYMORE   // initialise likelihood
//NOTUSEDANYMORE 
//NOTUSEDANYMORE   fLikeli.SetObservables(fObservables);
//NOTUSEDANYMORE   fLikeli.SetExpectedErrors(fExpectedErrors);
//NOTUSEDANYMORE 
//NOTUSEDANYMORE   // initialize fitters
//NOTUSEDANYMORE 
//NOTUSEDANYMORE   initFitters(false); // SB fitter
//NOTUSEDANYMORE   initFitters(true); // B fitter
//NOTUSEDANYMORE   
//NOTUSEDANYMORE   // print out
//NOTUSEDANYMORE   
//NOTUSEDANYMORE   cout << "Init From histo" << endl;
//NOTUSEDANYMORE   cout << "observables are filled: " << fObservables.isNotFilled << endl;
//NOTUSEDANYMORE   cout << "expectedErrors are filled: " << fExpectedErrors.isNotFilled << endl;
//NOTUSEDANYMORE   cout << "signalPlusBackground-profiled nuisances are filled: " << fTheta_S.isNotFilled << endl;
//NOTUSEDANYMORE   cout << "Background-profiled nuisances are filled: " << fTheta_B.isNotFilled << endl;
//NOTUSEDANYMORE 
//NOTUSEDANYMORE   // set initflag to TRUE
//NOTUSEDANYMORE   fIsInitialized = true;
//NOTUSEDANYMORE   
//NOTUSEDANYMORE }

nuisancePars statisticalTreatmentTH::InitNuisanceToObservables(observables obs){ 
  nuisancePars nuis;
  nuis.POTTrue = obs.POTObs; // estimated POT per point
  nuis.SignalEffiLocalTrue = obs.SignalEffiLocalObs; // estimated efficiency 
  nuis.SignalPeakYieldTrue = obs.SignalPeakYieldObs; // yield at the resonance peak
  nuis.SignalLorentzianWidthTrue = obs.SignalLorentzianWidthObs; // lorentzian width of the signal shape [in terms of pbeam]
  nuis.BESTrue = obs.BESObs;  // relative beam energy spread 
  nuis.POTScaleTrue = obs.POTScaleObs;             // estimated value of the POT scale
  nuis.BkgTrue = obs.BkgObs;                       // estimated value of the ratio Nbkg/POT per point

  nuis.BkgBiasTrueP0 = obs.BkgBiasObsP0;
  nuis.BkgBiasTrueP1 = obs.BkgBiasObsP1;
  for (int i=0; i<3; i++){
    nuis.EffiOverBkgTrueP0[i] = obs.EffiOverBkgObsP0[i];
    nuis.EffiOverBkgTrueP1[i] = obs.EffiOverBkgObsP1[i];
  }  
  return nuis; // return it flagged as non-filled
}


void statisticalTreatmentTH::initHistograms(){
  const double LMax = 2000; // max of -2 log likelihood
  const int NLBins = 100;   // nbins of -2log likelihood
  double* gveEdges = new double[fNgveBins+1];
  for (uint ig = 0; ig < (uint)fNgveBins+1; ig++) gveEdges[ig] = TMath::Power(fgveMin*fgveMin*fgveMin*fgveMin + ig*fgveStep,0.25);

  
  cout << "Booking histograms in memory...";

  fLBHisto = new TH1D("LBHisto","LB for pseudo data events",NLBins,0,LMax); // LB   for each pseudo-data event
  
  for (uint im = 0; im < (uint)fNMassBins; im++){
    double massn = fMassMin + im*fMassStep;
    fLSBHisto.push_back( new TH2D(Form("LSB_mass%d",im),Form("LSB vs gven for mass = %f ",massn),fNgveBins,gveEdges,NLBins,0,LMax) );
    fQobsHisto.push_back( new TH2D(Form("Qobs_mass%d",im),Form("Oobs vs gven for mass = %f ",massn),fNgveBins,gveEdges,NLBins,-LMax,LMax) );
  }

  fQobsAvgHisto = new TH2D("QobsAvg","Average Qobs",fNMassBins,fMassMin-0.5*fMassStep,fMassMax-0.5*fMassStep,fNgveBins,gveEdges); // average Qobs vs {mass,gven} 

  // histograms for each pseudo data and each toy generated
  
  fLB_BtoyHisto = new TH1D("LB_BtoyHisto","LB for B-toy events",NLBins,0,LMax); // LB for each pseudo-data event and for each generated B-only toy event

  for (uint im = 0; im < fNMassBins; im++){
    double massn = fMassMin + im*fMassStep;
    fLSB_BtoyHisto.push_back( new TH2D(Form("LSB_Btoy_mass%d",im),Form("LSB vs gve for b-toys and mass = %f ",massn),fNgveBins,gveEdges,NLBins,0,LMax) ); 
    fQbRelHisto.push_back( new TH2D(Form("QbRel_Btoy_mass%d",im),Form("Qb-Qobs vs gve for b-toys and mass = %f ",massn),fNgveBins,gveEdges,NLBins,-LMax,LMax) ); 

    fLSB_SBtoyHisto.push_back( new TH2D(Form("LSB_SBtoy_mass%d",im),Form("LSB vs gve for sb-toys and mass = %f ",massn),fNgveBins,gveEdges,NLBins,0,LMax) ) ; 
    
    fQsRelHisto.push_back( new TH2D(Form("QsRel_SBtoy_mass%d",im),Form("Qs-Qobs vs gve for sb-toys and mass = %f ",massn),fNgveBins,gveEdges,2*NLBins,-LMax,LMax) );
  }
  
  cout << "Creating ttree in memory... " ;
   
  fCLsTree = new TTree("fCLSTree","CLS ntuple");
  fCLsTree->Branch("pseudodataid",&fCLsInfo.ipseudodata,"pseudodataid/I");
  fCLsTree->Branch("stSeed",&fCLsInfo.startingSeed,"stSeed/I");
  fCLsTree->Branch("massid",&fCLsInfo.im,"massid/I");
  fCLsTree->Branch("gveid",&fCLsInfo.ig,"gveid/I");
  fCLsTree->Branch("mass",&fCLsInfo.massn,"mass/D");
  fCLsTree->Branch("gven",&fCLsInfo.gven,"gven/D");
  fCLsTree->Branch("Qobs",&fCLsInfo.Qobs,"Qobs/D");
  fCLsTree->Branch("Lb",&fCLsInfo.Lb,"Lb/D");
  fCLsTree->Branch("Ps",&fCLsInfo.Ps,"Ps/D");
  fCLsTree->Branch("Pb",&fCLsInfo.Pb,"Pb/D");
  fCLsTree->Branch("CLs",&fCLsInfo.CLs,"CLs/D");

  fFreqTree = new TTree("fFreqTree","Frequentist ntuple");
  fFreqTree->Branch("pseudodataid",&fFreqInfo.ipseudodata,"pseudodataid/I");
  fFreqTree->Branch("stSeed",&fFreqInfo.startingSeed,"stSeed/I");
  fFreqTree->Branch("massid",&fFreqInfo.im,"massid/I");
  fFreqTree->Branch("mass",&fFreqInfo.massn,"mass/D");
  fFreqTree->Branch("rolke90",&fFreqInfo.rolke90,"rolke90/D");
  fFreqTree->Branch("rolke95",&fFreqInfo.rolke95,"rolke95/D");
  fFreqTree->Branch("feldman90",&fFreqInfo.feldman90,"feldman90/D");
  fFreqTree->Branch("feldman95",&fFreqInfo.feldman95,"feldman95/D");


  
  delete[] gveEdges;
  cout << "... done " <<endl;
}

void statisticalTreatmentTH::ReadOutput(TString filename){
  TFile* filo = new TFile(filename.Data(),"OLD");  
  TTree* fCLsTree = (TTree*) filo->Get("fCLSTree");
  fCLsTree->SetBranchAddress("pseudodataid",&fCLsInfo.ipseudodata);
  fCLsTree->SetBranchAddress("stSeed",&fCLsInfo.startingSeed);
  fCLsTree->SetBranchAddress("massid",&fCLsInfo.im);
  fCLsTree->SetBranchAddress("gveid",&fCLsInfo.ig);
  fCLsTree->SetBranchAddress("mass",&fCLsInfo.massn);
  fCLsTree->SetBranchAddress("gven",&fCLsInfo.gven);
  fCLsTree->SetBranchAddress("Qobs",&fCLsInfo.Qobs);
  fCLsTree->SetBranchAddress("Lb",&fCLsInfo.Lb);
  fCLsTree->SetBranchAddress("Ps",&fCLsInfo.Ps);
  fCLsTree->SetBranchAddress("Pb",&fCLsInfo.Pb);
  fCLsTree->SetBranchAddress("CLs",&fCLsInfo.CLs);

  TTree* fFreqTree = (TTree*) filo->Get("fFreqTree");
  TGraph* limitRL90 = new TGraph(); limitRL90->SetName("RolkeLopezLimit90");
  TGraph* limitRL95 = new TGraph(); limitRL95->SetName("RolkeLopezLimit95");
  TGraph* limitFC90 = new TGraph(); limitFC90->SetName("FeldmanCousinsLimit90");
  TGraph* limitFC95 = new TGraph(); limitFC95->SetName("FeldmanCousinsLimit95");
  if (fFreqTree != nullptr){
    fFreqTree->SetBranchAddress("pseudodataid",&fFreqInfo.ipseudodata);
    fFreqTree->SetBranchAddress("stSeed",&fFreqInfo.startingSeed);
    fFreqTree->SetBranchAddress("massid",&fFreqInfo.im);
    fFreqTree->SetBranchAddress("mass",&fFreqInfo.massn);
    fFreqTree->SetBranchAddress("rolke90",&fFreqInfo.rolke90);
    fFreqTree->SetBranchAddress("rolke95",&fFreqInfo.rolke95);
    fFreqTree->SetBranchAddress("feldman90",&fFreqInfo.feldman90);
    fFreqTree->SetBranchAddress("feldman95",&fFreqInfo.feldman95);

    for (int i=0; i< fFreqTree->GetEntries(); i++){
      fFreqTree->GetEntry(i);
      limitRL90->SetPoint(i,fFreqInfo.massn,fFreqInfo.rolke90);
      limitRL95->SetPoint(i,fFreqInfo.massn,fFreqInfo.rolke95);
      limitFC90->SetPoint(i,fFreqInfo.massn,fFreqInfo.feldman90);
      limitFC95->SetPoint(i,fFreqInfo.massn,fFreqInfo.feldman95);
    }
  }

  
  // fill array of tgraph*

  TGraph* limit90 = new TGraph(); limit90->SetName("Limit90");
  TGraph* limit95 = new TGraph(); limit95->SetName("Limit95");

  vector<TGraph*> gveVSCLs;
  TGraph* gveVSCLsLoc;
  double massOld = -1;

  if (fVerbosity > 1) std::cout << "Input CLs tree has " << fCLsTree->GetEntries() << std::endl; 
  for (int i=0; i< fCLsTree->GetEntries(); i++){
    fCLsTree->GetEntry(i);
    if (fVerbosity > 2) {
      std::cout << " Reading row " << i << " of root file: mass = " << fCLsInfo.massn << " gve = " << fCLsInfo.gven << " CLs " << fCLsInfo.CLs << std::endl; 
    }
    if (massOld == -1) { // first mass
      // init new tgraph
      massOld = fCLsInfo.massn;
      gveVSCLsLoc = new TGraph();
      gveVSCLsLoc->SetName(Form("gveVSCLsLoc%f_graph",massOld));
      gveVSCLsLoc->SetPoint(0,fCLsInfo.CLs,fCLsInfo.gven);
    }
    else {
      if (fCLsInfo.massn != massOld){ // change of mass
	if (fVerbosity > 2) {
	  std::cout << "Printing Graph for mass = " << massOld << std::endl; 
	  for (int j = 0; j< gveVSCLsLoc->GetN(); j++){
	    std::cout << "Point: " << j << " CLs = " << gveVSCLsLoc->GetX()[j] << " gven = " << gveVSCLsLoc->GetY()[j]<< std::endl; 
	  }
	}
	// fill limits, if we can interpolate
	if (gveVSCLsLoc->GetY()[gveVSCLsLoc->GetN()-1] < 0.1) limit90->SetPoint(limit90->GetN(),massOld,gveVSCLsLoc->Eval(0.1));
	if (gveVSCLsLoc->GetY()[gveVSCLsLoc->GetN()-1] < 0.05) limit95->SetPoint(limit95->GetN(),massOld,gveVSCLsLoc->Eval(0.05));

 	// save graph for CLs vs gve at given mass 
	gveVSCLs.push_back(gveVSCLsLoc);

	// init new tgraph
	massOld = fCLsInfo.massn;
	gveVSCLsLoc = new TGraph();
	gveVSCLsLoc->SetName(Form("gveVSCLsLoc%f_graph",massOld));
	gveVSCLsLoc->SetPoint(0,fCLsInfo.CLs,fCLsInfo.gven);

      }
      else {
	gveVSCLsLoc->SetPoint(gveVSCLsLoc->GetN(),fCLsInfo.CLs,fCLsInfo.gven);
      }
    }
  }
  // fill limits, if we can interpolate
  if (gveVSCLsLoc->GetY()[gveVSCLsLoc->GetN()-1] < 0.1) limit90->SetPoint(limit90->GetN(),massOld,gveVSCLsLoc->Eval(0.1));
  if (gveVSCLsLoc->GetY()[gveVSCLsLoc->GetN()-1] < 0.05) limit95->SetPoint(limit95->GetN(),massOld,gveVSCLsLoc->Eval(0.05));
  
  if (fVerbosity > 2) {
    std::cout << "Printing Graph for mass = " << massOld << std::endl; 
    for (int j = 0; j< gveVSCLsLoc->GetN(); j++){
      std::cout << "Point: " << j << " CLs = " << gveVSCLsLoc->GetX()[j] << " gven = " << gveVSCLsLoc->GetY()[j]<< std::endl; 
    }
  }
  // save graph for CLs vs gve at given mass 
  gveVSCLs.push_back(gveVSCLsLoc);


  
  TFile* filout = new TFile(Form("%s_limits.root",filename.Data()),"NEW");  
  limit90->Write();
  limit95->Write();
  for (uint i=0; i<gveVSCLs.size(); i++){
    gveVSCLs.at(i)->Write();
  }
  limitRL90->Write();
  limitRL95->Write();
  limitFC90->Write();
  limitFC95->Write();

  filout->Close();
  delete filout;
  for (uint i=0; i<gveVSCLs.size(); i++){
    delete gveVSCLs.at(i);
  }
  delete limitRL90;
  delete limitRL95;
  delete limitFC90;
  delete limitFC95;

  gveVSCLs.clear();
}


void statisticalTreatmentTH::initFitters(bool bonly){
  int npts = fObservables.SqrtsObs.size();

  // here, update number of pars, introduce the likelihood schemes possible:
  // - with/without using the nuisances
  // - with/without bias correction
  // - with/without using the effi/(bkg/pot) parameterisation
  
  // must change the likelihood interface and the parameters to map inside it
  // must change the parameters that are fixed
  // if NOT using the nuisances --> all the nuisances are fixed 
  // if the bias is NOT applied --> P0 = 1 and P1 = 0 must be fixed

  // if the effi/bkg/pot curve is NOT used --> must fix the EffiOverBkgTrueP0,P1 parameters, must leave free the effisig parameters
  // else --> the EffiOverBkgTrueP0,P1 parameters are fit, the effisig parameters are fixed

  // THE TOY GENERATION PART SHOULD BE CONSISTENT WITH THE CHOICE DONE HERE
  
  int npars = 15+3*npts;
  // aggiungere le due flag di bias/efficurve e 2+4 parametri

  
  double* parinput = new double[npars];
  double* parstep  = new double[npars];
  TString* parnames = new TString[npars];
  
  parnames[0] = "IsBonlyFit"; parinput[0] = 1         ; parstep[0] = 0;
  parnames[1] = "mass"      ; parinput[1] = fMassMin  ; parstep[1] = 0; 
  parnames[2] = "coupling"  ; parinput[2] = fgveMin    ; parstep[2] = 0; 
  for (int i=0; i<npts; i++){
    parnames[3+i] = Form("POTTrue_%d",i)        ; parinput[3+i] = fTheta_S.POTTrue.at(i)                 ; parstep[3+i] = fExpectedErrors.POTLocalErr.at(i)*0.01;
    parnames[3+npts+i] = Form("SigEffTrue_%d",i); parinput[3+npts+i] = fTheta_S.SignalEffiLocalTrue.at(i); parstep[3+npts+i] = fExpectedErrors.SignalEffiLocalErr.at(i)*0.01;    
  }
  parnames[3+2*npts] = "SigPeakYieldTrue"; parinput[3+2*npts] = fTheta_S.SignalPeakYieldTrue             ; parstep[3+2*npts] = fExpectedErrors.SignalPeakYieldErr*0.01;
  parnames[4+2*npts] = "SigLorentzWTrue" ; parinput[4+2*npts] = fTheta_S.SignalLorentzianWidthTrue       ; parstep[4+2*npts] = fExpectedErrors.SignalLorentzianWidthErr*0.01;
  parnames[5+2*npts] = "BESTrue"         ; parinput[5+2*npts] = fTheta_S.BESTrue                         ; parstep[5+2*npts] = fExpectedErrors.BESErr*0.01;
  parnames[6+2*npts] = "POTScaleTrue"    ; parinput[6+2*npts] = fTheta_S.POTScaleTrue                    ; parstep[6+2*npts] = fExpectedErrors.POTScaleErr*0.01;
  for (int i=0; i<npts; i++){
    parnames[7+2*npts+i] = Form("BkgTruePerPOT_%d",i); parinput[7+2*npts+i] = fTheta_S.BkgTrue.at(i)     ; parstep[7+2*npts+i] = fExpectedErrors.BkgErr.at(i)*0.01;    
  }
  parnames[7+3*npts] = "CorrectBkgBias"        ; parinput[7+3*npts] = fConfigPtr->GetCorrectBkgBias()        ; parstep[7+3*npts] = 0.1;    
  parnames[8+3*npts] = "BkgBiasTrueP0"         ; parinput[8+3*npts] = fTheta_S.BkgBiasTrueP0                 ; parstep[8+3*npts] = fExpectedErrors.BkgBiasErrP0*0.01;    
  parnames[9+3*npts] = "BkgBiasTrueP1"         ; parinput[9+3*npts] = fTheta_S.BkgBiasTrueP1                 ; parstep[9+3*npts] = fExpectedErrors.BkgBiasErrP1*0.01;    
  parnames[10+3*npts]= "AssumeEffiOverBkgCurve"; parinput[10+3*npts]= fConfigPtr->GetAssumeEffiOverBkgCurve(); parstep[10+3*npts]= 0.1;    
  parnames[11+3*npts]= "EffiOverBkgTrueP0_0"   ; parinput[11+3*npts]= fTheta_S.EffiOverBkgTrueP0[0]          ; parstep[11+3*npts]= fExpectedErrors.EffiOverBkgErrP0[0]*0.01;    
  parnames[12+3*npts]= "EffiOverBkgTrueP1_0"   ; parinput[12+3*npts]= fTheta_S.EffiOverBkgTrueP1[0]          ; parstep[12+3*npts]= fExpectedErrors.EffiOverBkgErrP1[0]*0.01;    
  parnames[13+3*npts]= "EffiOverBkgTrueP0_1"   ; parinput[13+3*npts]= fTheta_S.EffiOverBkgTrueP0[1]          ; parstep[13+3*npts]= fExpectedErrors.EffiOverBkgErrP0[1]*0.01;    
  parnames[14+3*npts]= "EffiOverBkgTrueP1_1"   ; parinput[14+3*npts]= fTheta_S.EffiOverBkgTrueP1[1]          ; parstep[14+3*npts]= fExpectedErrors.EffiOverBkgErrP1[1]*0.01;    
//  parnames[15+3*npts]= "EffiOverBkgTrueP0_2"   ; parinput[15+3*npts]= fTheta_S.EffiOverBkgTrueP0[2]          ; parstep[15+3*npts]= fExpectedErrors.EffiOverBkgErrP0[2]*0.01;    
//  parnames[16+3*npts]= "EffiOverBkgTrueP1_2"   ; parinput[16+3*npts]= fTheta_S.EffiOverBkgTrueP1[2]          ; parstep[16+3*npts]= fExpectedErrors.EffiOverBkgErrP1[2]*0.01;    

  if (bonly){
    fFitterB.SetFCN(npars, fLikeli); // flag_sb/b, mass, gve, signalPeak, LorentzianW, BES, potscale, 3 array: pottrue, signaleffitrue, bkgtrue
    for (int ip=0; ip < npars; ip++) fFitterB.Config().ParSettings(ip) = ROOT::Fit::ParameterSettings(parnames[ip].Data(),parinput[ip],parstep[ip]);
  
    fFitterB.Config().ParSettings(0).Fix(); // used to define S+B or B fits
    fFitterB.Config().ParSettings(1).Fix(); // mass is always fixed
    fFitterB.Config().ParSettings(2).Fix(); // coupling is always fixed
    fFitterB.Config().ParSettings(7+3*npts).Fix(); // flag to correct the N2cl/pot/(bkg/pot) bias 
    fFitterB.Config().ParSettings(10+3*npts).Fix(); // flag to assume the Effi/(Bkg/pot) curve

    for (uint i=0; i<(uint)npts; i++)              fFitterB.Config().ParSettings(3+npts+i).Fix(); // fix signal effi parameters, if they had been released
    for (uint i=3+2*npts; i<(uint)6+2*npts; i++)   fFitterB.Config().ParSettings(i).Fix();        // fix signal shape parameters
    for (uint i=11+3*npts; i<(uint)15+3*npts; i++) fFitterB.Config().ParSettings(i).Fix();        // fix effi/(bkg/pot) curve parameters, if they had been released
    
    if (fConfigPtr->GetCorrectBkgBias()){ // USE the bias curve, therefore remove the potscale parameter, substituted by the curve
      fFitterB.Config().ParSettings(6+2*npts).Fix();
    } else { // DO NOT USE the bias curve
      for (uint i=8+3*npts; i<(uint)10+3*npts; i++) fFitterB.Config().ParSettings(i).Fix();       // fix P0,P1 of the bias curve 
    }

  }
  else {
    fFitterSB.SetFCN(npars, fLikeli); // flag_sb/b, mass, gve, signalPeak, LorentzianW, BES, potscale, 3 array: pottrue, signaleffitrue, bkgtrue
    for (int ip=0; ip < npars; ip++) fFitterSB.Config().ParSettings(ip) = ROOT::Fit::ParameterSettings(parnames[ip].Data(),parinput[ip],parstep[ip]);
  
    fFitterSB.Config().ParSettings(0).Fix(); // used to define S+B or B fits
    fFitterSB.Config().ParSettings(1).Fix(); // mass is always fixed
    fFitterSB.Config().ParSettings(2).Fix(); // coupling is always fixed
    fFitterSB.Config().ParSettings(7+3*npts).Fix(); // flag to correct the N2cl/pot/(bkg/pot) bias 
    fFitterSB.Config().ParSettings(10+3*npts).Fix(); // flag to assume the Effi/(Bkg/pot) curve
    //    fFitterSB.Config().ParSettings(4+2*npts).Fix(); // to fix the lorentzian width gamma

    if (fConfigPtr->GetCorrectBkgBias()){ // USE the bias curve, therefore remove the potscale parameter, substituted by the curve
      fFitterSB.Config().ParSettings(6+2*npts).Fix();
    } else { // DO NOT use the bias curve
      for (uint i=8+3*npts; i<(uint)10+3*npts; i++) fFitterSB.Config().ParSettings(i).Fix();       // fix P0,P1 of the bias curve <-- should be protected in the likelihood
    }

    if (fConfigPtr->GetAssumeEffiOverBkgCurve()){ // USE the effi/(bkg/pot) curve
      for (uint i=0; i<(uint)npts; i++)              fFitterSB.Config().ParSettings(3+npts+i).Fix(); // fix signal effi point-by-point, if they had been released
    } else { // DO NOT USE the effi/(bkg/pot) curve
      for (uint i=11+3*npts; i<(uint)15+3*npts; i++) fFitterSB.Config().ParSettings(i).Fix();       // fix P0,P1 of the bias curve for all scan subsets
    }
  }

  // if nuisances must be blocked, only allow potscale to be fit
  if (!fUseNuisance) { 
    for (uint ip=0; ip < npars; ip++) {

      if (fConfigPtr->GetCorrectBkgBias()){ // USE the bias curve
	if (ip == 8+3*npts || ip == 9+3*npts) continue; // leave P0,P1 of the bias curve as only fit parameters 
      } else {
	if (ip == 6+2*npts) continue; // leave potscale as only fit parameter
      }
      if (bonly) fFitterB.Config().ParSettings(ip).Fix(); //fix all the parameters
      else      fFitterSB.Config().ParSettings(ip).Fix(); //fix all the parameters
    }
  }
}


void statisticalTreatmentTH::EvaluateExpectedLimit(){
  if (!fIsInitialized){
    std::cout << "Cannot Evaluate expected limit - no init done " << endl;
    exit(1);
  }

  // define temporary structures to be stored in memory 
  double** Qobs = new double*[fNMassBins];
  int** nbGood = new int*[fNMassBins];
  double** Pb = new double*[fNMassBins];
  double** Ps = new double*[fNMassBins];
  nuisancePars** theta_S_i = new nuisancePars*[fNMassBins];
  double** gveFreqRolke = new double*[fNMassBins]; 
  double** gveFreqFeldman = new double*[fNMassBins]; //90, 95% CL

  // zero temporary structures
  for (uint im = 0; im < (uint) fNMassBins; im++) {
    Qobs[im] = new double[fNgveBins];
    nbGood[im] = new int[fNgveBins];
    Pb[im] = new double[fNgveBins];
    Ps[im] = new double[fNgveBins];

    gveFreqRolke[im] = new double[2];
    gveFreqFeldman[im] = new double[2];
    theta_S_i[im] = new nuisancePars[fNgveBins];
    for (uint ig = 0; ig < (uint) fNgveBins; ig++){
      nbGood[im][ig] = 0;
      // should we zero the others? 
    }
  }


  
  for (uint i=0; i< (uint) fNumberOfGenerationsExpectedLimit; i++){
    
    // simulate background only counts
    if (i%10 == 0) cout << "Simulating pseudo data, event " << i << endl;
    
    if (fVerbosity >= 2) {
      cout << "Sqrts = ";
      for (uint j=0; j<(uint) fObservables.SqrtsObs.size(); j++) std::cout << " " << fObservables.SqrtsObs.at(j);
      cout << endl;
      cout << "NObs = ";
      for (uint j=0; j<(uint) fObservables.NObs.size(); j++) std::cout << " " << fObservables.NObs.at(j) ;
      cout << endl;
    }


    if (fConfigPtr->GetGeneMode()) SetNObs(GenerateBackgroundPseudoData(fTheta_B));
    else {
      if (fConfigPtr->GetBkgOnlyGeneMode()) SetNObsFromFile(fConfigPtr->GetInputFileNameNObsFromFile(),i);
      else           SetNObsFromSBFile(fConfigPtr->GetInputFileNameNObsFromFile(),fConfigPtr->GetWantedMassNObsFromFile(),fConfigPtr->GetWantedGveNObsFromFile(),i);
    }
    
    if (fVerbosity >= 2) {
      cout << "After generation of pseudo data Nobs = ";
      for (uint j=0; j<(uint) fObservables.NObs.size(); j++) std::cout << " " << fObservables.NObs.at(j) ;
      cout << endl;
    }

    
    double LB;
    nuisancePars theta_B_i = MaximizeLBGivenNObs(&LB);   // maximize Lb wrt nuisance pars, store "profiled" nuisance pars q_b
    fLBHisto->Fill(LB);
    
    if (fVerbosity >= 2) {
      cout << "Nuisance fit on b-only hypothesis for pseudo data event " << i << " has succeded? " << !(theta_B_i.isNotFilled) << endl;
      cout << "Original nuisance potScale = " << fTheta_B.POTScaleTrue << " , minimum found = " << theta_B_i.POTScaleTrue << " Likelihood = " << LB << endl;
    }
    
    for (uint im = 0; im < (uint) fNMassBins; im++){
      double massn = fMassMin + im*fMassStep;

      // evaluation of upper limits using frequentist methods
      
      if (fVerbosity >= 2) {
	cout << "Evaluate frequentist upper limits " << massn << " " << gveFreqRolke[im][0] << " " << gveFreqRolke[im][1] << " " << gveFreqFeldman[im][0] << " " << gveFreqFeldman[im][1] << endl;
      }
      EvaluateFrequentist(massn,gveFreqRolke[im],gveFreqFeldman[im]);
      if (fVerbosity >= 2) {
	cout << "... done " << massn << " " << gveFreqRolke[im][0] << " " << gveFreqRolke[im][1] << " " << gveFreqFeldman[im][0] << " " << gveFreqFeldman[im][1] << endl;
      }

      for (uint ig = 0; ig < (uint) fNgveBins; ig++){
	double gven = TMath::Power(fgveMin*fgveMin*fgveMin*fgveMin + ig*fgveStep,0.25);

	double LSB;
	theta_S_i[im][ig] = MaximizeLSBGivenNObs(massn,gven,&LSB); // maximize Lsb wrt nuisance pars, return "profiled" nuisance pars and via argument, Lsb    

	if (fVerbosity >= 2) {
	  cout << "Nuisance fit on sb hypothesis for pseudo data event " << i << " and mass,gve = " << massn << " , " << gven << " has succeded? " << !(theta_S_i[im][ig].isNotFilled) << endl;
	  cout << "Original nuisance potScale = " << fTheta_S.POTScaleTrue << " , minimum found = " << theta_S_i[im][ig].POTScaleTrue << " Likelihood = " << LSB << endl;
	  cout << "Original nuisance signalShape = " <<
	    fTheta_S.SignalPeakYieldTrue << " , " << fTheta_S.SignalLorentzianWidthTrue << " , " << fTheta_S.BESTrue << " , found = " <<
	    theta_S_i[im][ig].SignalPeakYieldTrue << " , " << theta_S_i[im][ig].SignalLorentzianWidthTrue << " , " << theta_S_i[im][ig].BESTrue << " Likelihood = " << LSB << endl;
	}

	Qobs[im][ig] = LSB - LB; //was -2*TMath::Log(LSB/LB) = -2Log(LSB) + 2Log(LB) = chi^2_SB - chi^2_B;

	// Fill histograms

	fLSBHisto.at(im)->Fill(gven,LSB);
	fQobsHisto.at(im)->Fill(gven,Qobs[im][ig]);
	fQobsAvgHisto->Fill(massn,gven,Qobs[im][ig]);

	if (fVerbosity >= 2) {
	  cout << "Original nuisance potScale = " << fTheta_S.POTScaleTrue << " , minimum over bs hypothesis on pseudo data event " << i << " mass = " << massn << " coupling = " << gven << " " << theta_S_i[im][ig].POTScaleTrue << " Likelihood = " << LSB << " Qobs = " << Qobs[im][ig] << endl;
	}


      }
    }

    if (i%10 == 0) {
      cout << "Qobs have been evaluated, event " << i << endl;
      for (uint im = 0; im < (uint) fNMassBins; im++){
	double massn = fMassMin + im*fMassStep;
	cout << "mass = " << massn << endl;
	cout << "Qobs = ";
	for (uint ig = 0; ig < (uint) fNgveBins; ig++) cout << " " << Qobs[im][ig];
	cout << endl;
      }
    }
    
    // background only toys

    for (uint im = 0; im < (uint) fNMassBins; im++) {
      for (uint ig = 0; ig < (uint) fNgveBins; ig++){
	nbGood[im][ig] = 0;
      }
    }
    
    for (uint j=0; j<fNumberOfGenerations; j++){

      SetNObs(GenerateBackground(theta_B_i));

      double LB_Btoy;
      nuisancePars theta_B_Btoy = MaximizeLBGivenNObs(&LB_Btoy);   // maximize Lb wrt nuisance pars, store "profiled" nuisance pars q_b

      // fill histograms
      
      fLB_BtoyHisto->Fill(LB_Btoy);

      if (fVerbosity >= 2) {
	cout << "Nuisance fit on b hypothesis for generated toy event " << j << " has succeded? " << !(theta_B_Btoy.isNotFilled) << endl;
	cout << "Original nuisance potScale = " << theta_B_i.POTScaleTrue << " , minimum found = " << theta_B_Btoy.POTScaleTrue << " Likelihood = " << LB_Btoy << endl;
      }
      
      for (uint im = 0; im < (uint) fNMassBins; im++){
	double massn = fMassMin + im*fMassStep;
	for (uint ig = 0; ig < (uint) fNgveBins; ig++){
	  double gven = TMath::Power(fgveMin*fgveMin*fgveMin*fgveMin + ig*fgveStep,0.25);

	  double LSB_Btoy;
	  nuisancePars theta_S_Btoy = MaximizeLSBGivenNObs(massn,gven,&LSB_Btoy); // maximize Lsb wrt nuisance pars, store "profiled" nuisance pars q_s

	  if (fVerbosity >= 2) {
	    cout << "Nuisance fit on sb hypothesis for generated toy event " << j << " mass,gve = " << massn << ","<< gven << " has succeded? " << !(theta_S_Btoy.isNotFilled) << endl;
	    cout << "Original nuisance potScale = " << theta_B_i.POTScaleTrue << " , minimum found = " << theta_S_Btoy.POTScaleTrue << " Likelihood = " << LSB_Btoy << endl;
	  }
	  
	  double Qb = LSB_Btoy - LB_Btoy;//-2*TMath::Log(LSB_Btoy/LB_Btoy);
	  if (Qb < Qobs[im][ig]) nbGood[im][ig]++;

	  // fill histograms

	  fLSB_BtoyHisto.at(im)->Fill(gven,LSB_Btoy);
	  fQbRelHisto.at(im)->Fill(gven,Qb-Qobs[im][ig]);
	}
      }
    }

    // evaluate probabilities for background only
    
    for (uint im = 0; im < (uint) fNMassBins; im++){
      for (uint ig = 0; ig < (uint) fNgveBins; ig++){
	Pb[im][ig] = (double)(nbGood[im][ig])/fNumberOfGenerations;
      }
    }

    if (i%10 == 0) {
      cout << "Pb along the (m,gve) grid have been evaluated, event " << i << endl;
      for (uint im = 0; im < (uint) fNMassBins; im++){
	double massn = fMassMin + im*fMassStep;
	cout << "mass = " << massn << endl;
	cout << "Pb = "; 
	for (uint ig = 0; ig < (uint) fNgveBins; ig++) cout << " " << Pb[im][ig] << " ("<<nbGood[im][ig]<<")/"<<fNumberOfGenerations;
	cout << endl;
      }
    }
    
    // signal + background toys

    for (uint im = 0; im < (uint) fNMassBins; im++){
      double massn = fMassMin + im*fMassStep;
      for (uint ig = 0; ig < (uint) fNgveBins; ig++){
	double gven = TMath::Power(fgveMin*fgveMin*fgveMin*fgveMin + ig*fgveStep,0.25);

	int nsGood = 0;
	for (uint j=0; j< (uint) fNumberOfGenerations; j++){
	  SetNObs(GenerateSignalPlusBackground(massn,gven,theta_S_i[im][ig]));

	  double LSB_SBtoy;
	  nuisancePars theta_S_sbtoy = MaximizeLSBGivenNObs(massn,gven,&LSB_SBtoy); // maximize Lsb wrt nuisance pars, return "profiled" nuisance pars and via argument, Lsb
	  double LB_SBtoy;
	  nuisancePars theta_B_sbtoy = MaximizeLBGivenNObs(&LB_SBtoy);   // maximize Lb wrt nuisance pars, store "profiled" nuisance pars q_b
	  double Qs = LSB_SBtoy - LB_SBtoy;//-2*TMath::Log(LSB_SBtoy/LB_SBtoy); 
	  if (Qs > Qobs[im][ig]) nsGood++;

	  // fill histograms
	  
	  fLSB_SBtoyHisto.at(im)->Fill(gven,LSB_SBtoy);
	  fQsRelHisto.at(im)->Fill(gven,Qs-Qobs[im][ig]);
	}
	Ps[im][ig] = (double)(nsGood)/fNumberOfGenerations;
	double CLs = Ps[im][ig]/(1-Pb[im][ig]);

	// fill histograms and tree
	
	fCLsInfo.ipseudodata = i;
	fCLsInfo.startingSeed = fSeed;
	fCLsInfo.im = im;
	fCLsInfo.ig = ig;
	fCLsInfo.massn = massn;
	fCLsInfo.gven = gven;
	fCLsInfo.Lb = LB;
	fCLsInfo.Qobs = Qobs[im][ig];
	fCLsInfo.Ps = Ps[im][ig];
	fCLsInfo.Pb = Pb[im][ig];
	fCLsInfo.CLs = CLs;

	fCLsTree->Fill();
	
      } // loop over gve bins

      fFreqInfo.ipseudodata = i;
      fFreqInfo.startingSeed = fSeed;
      fFreqInfo.im = im;
      fFreqInfo.massn = massn;
      fFreqInfo.rolke90 = gveFreqRolke[im][0];
      fFreqInfo.rolke95 = gveFreqRolke[im][1];
      fFreqInfo.feldman90 = gveFreqFeldman[im][0];
      fFreqInfo.feldman95 = gveFreqFeldman[im][1];

      fFreqTree->Fill();


    } // loop over mass bins

    if (i%10 == 0) {
      cout << "Analysis of pseudo data event " << i << " completed" << endl;
      for (uint im = 0; im < (uint) fNMassBins; im++){
	double massn = fMassMin + im*fMassStep;
	cout << "mass = " << massn << endl;
	cout << "Ps = ";
	for (uint ig = 0; ig < (uint) fNgveBins; ig++) cout << " " << Ps[im][ig];
	cout << endl;
	cout << "Cls = ";
	for (uint ig = 0; ig < (uint) fNgveBins; ig++) cout << " " << Ps[im][ig]/(1-Pb[im][ig]);
	cout << endl;
      }
    }
    // here might re-loop over the grid to count how often Cls <= alpha, with alpha = 10%, 5%
    
  } // pseudo-data generation

  // delete temporary arrays
  
  for (uint im = 0; im < (uint) fNMassBins; im++) {
    delete[] Qobs[im];
    delete[] nbGood[im];
    delete[] Pb[im];
    delete[] theta_S_i[im];
    delete[] gveFreqRolke[im];
    delete[] gveFreqFeldman[im];
  }
  delete[] Qobs;
  delete[] nbGood;
  delete[] Pb;
  delete[] gveFreqRolke;
  delete[] gveFreqFeldman;
  delete[] theta_S_i;

  // normalise histograms when needed

  for (uint im = 0; im < (uint) fNMassBins; im++){
    for (uint ig = 0; ig < (uint) fNgveBins; ig++){
      fQobsAvgHisto->Scale(1./fNumberOfGenerationsExpectedLimit);
    }
  }
  
  
}


void statisticalTreatmentTH::EvaluateFrequentist(double massn, double* rolkegveUL, double* feldmangveUL){

  if (fVerbosity >= 2)  cout << "in EvaluateFrequentist " << massn << " " << *rolkegveUL << " " << *(rolkegveUL+1) << " " << *feldmangveUL << " " << *(feldmangveUL+1) << endl;

  // identify the points in the mass window
  vector<signalPower> yields;  
  for (uint i=0; i<fObservables.SqrtsObs.size(); i++){
    signalPower yi;
    yi.isqrts = i;
    yi.sqrts = fObservables.SqrtsObs.at(i);
    yi.signalYield = Likelihood::SignalShape(fObservables.SignalPeakYieldObs,fObservables.BESObs,fObservables.SignalLorentzianWidthObs,massn,fObservables.SqrtsObs.at(i));
    yields.push_back(yi);
  }

  if (fVerbosity >= 2) {
    cout << "in EvaluateFrequentist yields vector filled" << endl;
    for (vector<signalPower>::iterator iter = yields.begin(); iter < yields.end(); iter++){
      cout << "sqrts, yield: " << (*iter).isqrts << " " << (*iter).sqrts << " " << (*iter).signalYield << endl;
    }
  }
  std::sort(yields.begin(), yields.end(), by_yield_desc());

  if (fVerbosity >= 2) {
    cout << "in EvaluateFrequentist yields vector sorted" << endl;
    for (vector<signalPower>::iterator iter = yields.begin(); iter < yields.end(); iter++){
      cout << "sqrts, yield: " << (*iter).isqrts << " " << (*iter).sqrts << " " << (*iter).signalYield << endl;
    }
  }
  
  // integrate the expected signal counts in the mass window
  // integrate the observed and expected counts in the mass window
  // evaluate the error on the expected counts
  // evaluate the expected signal counts
  double nobs = 0;
  double nexp = 0;
  double enexp= 0;
  double nsig = 0;
  int npts = 0;
  for (vector<signalPower>::iterator iter = yields.begin(); iter < yields.end(); iter++){
    signalPower yi = *iter;
    int idx = yi.isqrts; 
    double relerrsq = 
      (fExpectedErrors.POTLocalErr.at(idx)/fObservables.POTObs.at(idx)) * (fExpectedErrors.POTLocalErr.at(idx)/fObservables.POTObs.at(idx)) +
      (fExpectedErrors.BkgErr.at(idx)/fObservables.BkgObs.at(idx)) * (fExpectedErrors.BkgErr.at(idx)/fObservables.BkgObs.at(idx));

    // integrals in the window considered
    if (npts < fFrequentistNPoints) {
      nobs += fObservables.NObs.at(idx);
      double NBExp = fObservables.POTObs.at(idx)*1E10*fObservables.BkgObs.at(idx);
      double NSExp = fObservables.POTObs.at(idx)*1E10*yi.signalYield;
      if (fConfigPtr->GetCorrectBkgBias()){
	NBExp *= (fObservables.BkgBiasObsP0 + fObservables.BkgBiasObsP1*(fObservables.SqrtsObs.at(idx)-SQRTSMID));
	NSExp *= (fObservables.BkgBiasObsP0 + fObservables.BkgBiasObsP1*(fObservables.SqrtsObs.at(idx)-SQRTSMID));
      } else {
	NBExp *= fObservables.POTScaleObs;
	NSExp *= fObservables.POTScaleObs;
      }
      if (fConfigPtr->GetAssumeEffiOverBkgCurve()){
	NSExp *= fObservables.BkgObs.at(idx)*(fObservables.EffiOverBkgObsP0[fObservables.ScanPeriod.at(idx)] + fObservables.EffiOverBkgObsP1[fObservables.ScanPeriod.at(idx)]*
					      (fObservables.SqrtsObs.at(idx)-SQRTSMID));
      } else {
	NSExp *= fObservables.SignalEffiLocalObs.at(idx);
      }
      nexp += NBExp; // POT x bkg/POT
      enexp += NBExp*NBExp*relerrsq; // sum of square errors: should we remove the bkg_i error if using the curve?? 
      nsig  += NSExp; // POT x yield/POT x effisig
    }
    npts++;
  }
  enexp = TMath::Sqrt(enexp); // no scale error considered here, should we remove the bkg_i error if using the curve as well??
  
  // evaluate the upper limits at 90% and 95% CL using FC
  // exclude region with Nsig > NUL --> gve^2 x nsig > NUL --> gve > sqrt(NUL/nsig)
  double sigmafrac[2] = {1.28,1.64};
//  TFeldmanCousins FC;
//  FC.SetNbackground(nexp);
//  FC.SetNobserved(nobs);
//  FC.SetMuMax(1E-3*1E-3*nsig);
//  FC.SetMuMin(1E-4*1E-4*nsig);
//  std::cout << "input " << nexp << " " << nobs << " " << 1E-3*1E-3*nsig << " " << 1E-4*1E-4*nsig << std::endl;
  for (int i=0; i<2; i++){
    //    FC.SetCL(0.9+0.05*i);
    //    *(feldmangveUL+i) = 1000;
    //    if (FC.GetUpperLimit() > 0)  *(feldmangveUL+i) = TMath::Sqrt(FC.GetUpperLimit()/nsig);
    if (i==0) *(feldmangveUL+i) = TMath::Sqrt(sigmafrac[0]*TMath::Sqrt(nexp)/nsig);
    else      *(feldmangveUL+i) = TMath::Sqrt(sigmafrac[0]*TMath::Sqrt(nexp+fRndmNumber->Gaus(0.,enexp))/nsig);
  }

  // evaluate the upper limits at 90% and 95% CL using RL

  TRolke RL ;
  for (int i=0; i<2; i++){
    RL.SetCL(0.9);//+0.05*i);
    if (i==0) RL.SetGaussBkgKnownEff(nobs,nexp,enexp,1.);
    else      RL.SetGaussBkgKnownEff(nobs,nexp,enexp/100.,1.);

    *(rolkegveUL+i) = 1000;
    if (RL.GetUpperLimit() > 0) *(rolkegveUL+i) = TMath::Sqrt(RL.GetUpperLimit()/nsig); // exclusion for Nsig > NUL --> gve^2 x nsig > NUL --> gve > sqrt(NUL/nsig)
  }

}


vector<Double_t> statisticalTreatmentTH::GenerateBackgroundPseudoData(nuisancePars nuis){
  vector<Double_t> nobs;  

  // sample pots vs sqrts, potscaletrue, bkgtrue
  double potscale = nuis.POTScaleTrue;
  double bkgbiaspars[2] = {0,0};

  if (fConfigPtr->GetCorrectBkgBias()){ // USE the bias curve, therefore remove the potscale parameter, substituted by the curve
    potscale = 1;
    // here sample the parameters from a bigauss
    double diagpar[2] = { fRndmNumber->Gaus(0.,1),  fRndmNumber->Gaus(0.,1)};
    for (int i=0; i<2; i++){
      bkgbiaspars[i] = 0;
      for (int j=0; j<2; j++){
	bkgbiaspars[i] += fInvCholeTransBkgBias[i][j]*diagpar[j];
      }
      if (i==0) bkgbiaspars[i] += nuis.BkgBiasTrueP0;
      else      bkgbiaspars[i] += nuis.BkgBiasTrueP1;
    }
  } else {
    potscale += fRndmNumber->Gaus(0.,fExpectedErrors.POTScaleErr);
    bkgbiaspars[0] = 1;
    bkgbiaspars[1] = 0;
  }
  
  int npts = nuis.POTTrue.size();
  for (uint i=0; i<npts; i++){
    double bkgtrue = nuis.BkgTrue.at(i);
    double pottrue = nuis.POTTrue.at(i);
    if (fUseNuisance){
      bkgtrue += fRndmNumber->Gaus(0.,fExpectedErrors.BkgErr.at(i));
      pottrue += fRndmNumber->Gaus(0.,fExpectedErrors.POTLocalErr.at(i));
    }
    double poismean = bkgtrue*pottrue*1E10;
    if (fConfigPtr->GetCorrectBkgBias()) {
      poismean *= (bkgbiaspars[0]+bkgbiaspars[1]*(fObservables.SqrtsObs.at(i)-SQRTSMID));
    } else {
      poismean *= potscale;
    }
    nobs.push_back(fRndmNumber->Gaus(poismean,TMath::Sqrt(poismean)));
  }
  return nobs;
}

vector<Double_t> statisticalTreatmentTH::GenerateSignalPlusBackgroundPseudoData(double massn, double gven, nuisancePars nuis){
  vector<Double_t> nobs;  

  // sample potscaletrue or, if needed, the parameters of the bkg bias curve: THOSE ARE SAMPLED ALWAYS, EVEN WHEN NO NUISANCES ARE CHOSEN

  double potscale = nuis.POTScaleTrue;
  double bkgbiaspars[2] = {0,0};
  if (fConfigPtr->GetCorrectBkgBias()){ // USE the bias curve, therefore remove the potscale parameter, substituted by the curve
    potscale = 1;
    // here sample the parameters from a bigauss
    double diagpar[2] = { fRndmNumber->Gaus(0.,1),  fRndmNumber->Gaus(0.,1)};
    for (int i=0; i<2; i++){
      bkgbiaspars[i] = 0;
      for (int j=0; j<2; j++){
	bkgbiaspars[i] += fInvCholeTransBkgBias[i][j]*diagpar[j];
      }
      if (i==0) bkgbiaspars[i] += nuis.BkgBiasTrueP0;
      else      bkgbiaspars[i] += nuis.BkgBiasTrueP1;
    }
  } else {
    potscale += fRndmNumber->Gaus(0.,fExpectedErrors.POTScaleErr);
    bkgbiaspars[0] = 1;
    bkgbiaspars[1] = 0;
  }

  // if needed sample the parameters of the curves for the effi/(bkg/pot) vs sqrts
  
  double efficurvepars[2][2];
  for (int k=0; k<2; k++){ // scan periods
    for (int i=0; i<2; i++) efficurvepars[k][i] = 0;
  }
  if (fConfigPtr->GetAssumeEffiOverBkgCurve()){ // USE the effi curve, therefore do not treat the effi parameters
    if (fUseNuisance){
    // here sample the parameters from a bigauss
      for (int k=0; k<2; k++){ // scan periods
	double diagpar[2] = { fRndmNumber->Gaus(0.,1),  fRndmNumber->Gaus(0.,1)};
	for (int i=0; i<2; i++){
	  efficurvepars[k][i] = 0;
	  for (int j=0; j<2; j++){
	    if (k==0) efficurvepars[k][i] += fInvCholeTransEffiOverBkgScan1st[i][j]*diagpar[j];
	    else      efficurvepars[k][i] += fInvCholeTransEffiOverBkgScan2nd[i][j]*diagpar[j];
	  }
	  if (i==0) efficurvepars[k][i] += nuis.EffiOverBkgTrueP0[k];
	  else      efficurvepars[k][i] += nuis.EffiOverBkgTrueP1[k];
	}
      }
    } else { // here do not use the nuisances -> keep the effioverbkg parameters frozen
      for (int k=0; k<2; k++){
	efficurvepars[k][0] = nuis.EffiOverBkgTrueP0[k];
	efficurvepars[k][1] = nuis.EffiOverBkgTrueP1[k];
      }
    } 
  }

  // sample signal shape parameters
  
  double signalpeak = nuis.SignalPeakYieldTrue;
  double bes = nuis.BESTrue;
  double lorewidth = nuis.SignalLorentzianWidthTrue;
  if (fUseNuisance){
    signalpeak += fRndmNumber->Gaus(0.,fExpectedErrors.SignalPeakYieldErr);
    bes += fRndmNumber->Gaus(0.,fExpectedErrors.BESErr);
    lorewidth += fRndmNumber->Gaus(0.,fExpectedErrors.SignalLorentzianWidthErr);
  }
  
  if (fVerbosity >= 2) {
    std::cout << " generating s+b pseudo data for gven = " << gven << " mass = " << massn << " signalpeak= " << signalpeak << " bes = "<< bes << " lorewidth = " << lorewidth << std::endl;
  }

  int npts = nuis.POTTrue.size();
  for (uint i=0; i<npts; i++){
    double bkgtrue = nuis.BkgTrue.at(i);
    double pottrue = nuis.POTTrue.at(i);
    double effisig = nuis.SignalEffiLocalTrue[i];
    if (fUseNuisance){
      bkgtrue += fRndmNumber->Gaus(0.,fExpectedErrors.BkgErr.at(i));
      pottrue += fRndmNumber->Gaus(0.,fExpectedErrors.POTLocalErr.at(i));
      if (!fConfigPtr->GetAssumeEffiOverBkgCurve()) effisig += fRndmNumber->Gaus(0.,fExpectedErrors.SignalEffiLocalErr.at(i));
    }

    double poismean_b = bkgtrue*pottrue*1E10;
    if (fConfigPtr->GetCorrectBkgBias()){
      poismean_b *= (bkgbiaspars[0]+bkgbiaspars[1]*(fObservables.SqrtsObs.at(i)-SQRTSMID));
    } else {
      poismean_b *= potscale;
    }
    //PROVA    double eRes = (massn*massn - 2*me*me)/(2.*(me+Wb));
    //PROVA    double eBeam = (fObservables.SqrtsObs.at(i)*fObservables.SqrtsObs.at(i) - 2*me*me)/(2.*me); // s = 2me^2 + 2meEbeam -> eBeam = (s-2me^2) / 2me

    double poismean_s = gven*gven*pottrue*1E10*Likelihood::SignalShape(signalpeak,bes,lorewidth,massn,fObservables.SqrtsObs.at(i));
    if (fConfigPtr->GetCorrectBkgBias()){
      poismean_s *= (bkgbiaspars[0]+bkgbiaspars[1]*(fObservables.SqrtsObs.at(i)-SQRTSMID));
    } else {
      poismean_s *= potscale;
    }
    
    if (fConfigPtr->GetAssumeEffiOverBkgCurve()){
      poismean_s *= bkgtrue*(efficurvepars[fObservables.ScanPeriod.at(i)][0] + efficurvepars[fObservables.ScanPeriod.at(i)][1]*(fObservables.SqrtsObs.at(i)-SQRTSMID));
    } else{
      poismean_s *= effisig;
    }
			     
    //    double poismean_s = signalpeak*gven*gven*pottrue*1E10*potscale*effisig*TMath::Voigt(eBeam-eRes,bes*eBeam,lorewidth*2,4);
        
    if (fVerbosity >= 2) {
      std::cout << "point = " << i << " sqrts = " << fObservables.SqrtsObs.at(i) << " bkg= " << poismean_b << " sig= " << poismean_s << std::endl;
    }
    nobs.push_back(poismean_b);
    nobs.push_back(poismean_s);
    nobs.push_back(fRndmNumber->Gaus(poismean_b+poismean_s,TMath::Sqrt(poismean_b+poismean_s)));
  }
  return nobs;
}




vector<Double_t> statisticalTreatmentTH::GenerateBackground(nuisancePars nuis){
  // evaluate bkgmean from pots, potscaletrue OR the P0/P1 bias curve, bkgtrue
  vector<Double_t> nobs;  
  int npts = nuis.POTTrue.size();
  for (uint i=0; i<npts; i++){
    double poismean = nuis.BkgTrue.at(i)*nuis.POTTrue.at(i)*1E10;
    if (fConfigPtr->GetCorrectBkgBias()) poismean *= (nuis.BkgBiasTrueP0 + nuis.BkgBiasTrueP1*(fObservables.SqrtsObs.at(i)-SQRTSMID));
    else                                 poismean *= nuis.POTScaleTrue;
    // sample statistical fluctuation only with nuisances blocked
    nobs.push_back(fRndmNumber->Gaus(poismean,TMath::Sqrt(poismean)));
  }
  return nobs;
}

vector<Double_t> statisticalTreatmentTH::GenerateSignalPlusBackground(double massn, double gven, nuisancePars nuis){
  // sample pots vs sqrts, potscaletrue, bkgtrue
  //  const double k = 3.52; // 3.52 gives 1400 events totally emitted for gve = 1E-3, using BES = 0.5%, see Fig. 1 left of 2403.15387
//PROVA  const double me = 0.511;// MeV
//PROVA  const double Wb = -7E-6;// MeV
  vector<Double_t> nobs;  
  int npts = nuis.POTTrue.size();
  for (uint i=0; i<npts; i++){
    double poismean_b = nuis.BkgTrue.at(i)*nuis.POTTrue.at(i)*1E10;
    if (fConfigPtr->GetCorrectBkgBias()) poismean_b *= (nuis.BkgBiasTrueP0 + nuis.BkgBiasTrueP1*(fObservables.SqrtsObs.at(i)-SQRTSMID));
    else                                 poismean_b *= nuis.POTScaleTrue;

//    double eRes = (massn*massn - 2*me*me)/(2.*(me+Wb));
//    double eBeam = (fObservables.SqrtsObs.at(i)*fObservables.SqrtsObs.at(i) - 2*me*me)/(2.*me); // s = 2me^2 + 2meEbeam -> eBeam = (s-2me^2) / 2me

    double poismean_s = gven*gven*nuis.POTTrue.at(i)*1E10*
      Likelihood::SignalShape(nuis.SignalPeakYieldTrue,nuis.BESTrue,nuis.SignalLorentzianWidthTrue,massn,fObservables.SqrtsObs.at(i));

    if (fConfigPtr->GetCorrectBkgBias()) poismean_s *= (nuis.BkgBiasTrueP0 + nuis.BkgBiasTrueP1*(fObservables.SqrtsObs.at(i)-SQRTSMID));
    else                                 poismean_s *= nuis.POTScaleTrue;

    if (fConfigPtr->GetAssumeEffiOverBkgCurve()) poismean_s *= nuis.BkgTrue.at(i)*(
										   nuis.EffiOverBkgTrueP0[fObservables.ScanPeriod.at(i)] +
										   nuis.EffiOverBkgTrueP1[fObservables.ScanPeriod.at(i)]*(fObservables.SqrtsObs.at(i)-SQRTSMID));
    else                                         poismean_s *= nuis.SignalEffiLocalTrue[i];
    //    double poismean_s = nuis.SignalPeakYieldTrue*gven*gven*nuis.POTTrue.at(i)*1E10*nuis.POTScaleTrue*nuis.SignalEffiLocalTrue[i]*TMath::Voigt(eBeam-eRes,nuis.BESTrue*eBeam,nuis.SignalLorentzianWidthTrue*2,4);

//    double argtight = (fObservables.SqrtsObs.at(i)-massn)*(fObservables.SqrtsObs.at(i)-massn)/(2.*nuis.SignalSigmaHiTrue*nuis.SignalSigmaHiTrue);
//    double argloose = (fObservables.SqrtsObs.at(i)-massn)*(fObservables.SqrtsObs.at(i)-massn)/(2.*nuis.SignalSigmaLoTrue*nuis.SignalSigmaLoTrue);
//    double poismean_s = fObservables.SignalPeakYieldObs*gven*gven*nuis.POTTrue.at(i)*nuis.POTScaleTrue*nuis.SignalEffiLocalTrue[i]*(
//												      TMath::Exp(-argtight)*nuis.SignalRatioTrue + 
//												      TMath::Exp(-argloose)*(1-nuis.SignalSigmaLoTrue)
//												      ); 
  
    nobs.push_back(fRndmNumber->Gaus(poismean_b+poismean_s,TMath::Sqrt(poismean_b+poismean_s)));
  }
  return nobs;
}

nuisancePars statisticalTreatmentTH::MaximizeLSBGivenNObs(double mass, double gve, double* lsb){ // given M,eps maximize Lsb wrt nuisance pars, return "profiled" nuisance pars

  int npts = fObservables.SqrtsObs.size();
  nuisancePars fitNuisance;
  
  fFitterSB.Config().ParSettings(0).SetValue(0); // S+B fit
  fFitterSB.Config().ParSettings(1).SetValue(mass); 
  fFitterSB.Config().ParSettings(2).SetValue(gve); 


  fLikeli.SetObservables(fObservables);
  
  bool okfit = fFitterSB.FitFCN();
  if (!okfit) {
    std::cerr << "LSB Fit failed" << std::endl;
    fitNuisance.isNotFilled = true;
    *lsb = -1;
  }
  else {
    const ROOT::Fit::FitResult & result = fFitterSB.Result();    
    if (fVerbosity == 3) result.Print(std::cout);

    // store output fit results into the nuisance parameters
    const double* parRes = result.GetParams();    
    for (int i=0; i<npts; i++){
      fitNuisance.POTTrue.push_back(parRes[3+i]);      
    }
    fitNuisance.SignalPeakYieldTrue = parRes[3+2*npts];
    fitNuisance.SignalLorentzianWidthTrue = parRes[4+2*npts];
    fitNuisance.BESTrue           = parRes[5+2*npts];

    if (fConfigPtr->GetCorrectBkgBias()){ // USE the bias curve, therefore remove the potscale parameter, substituted by the curve
      fitNuisance.BkgBiasTrueP0 = parRes[8+3*npts]; // p0 bias curve result
      fitNuisance.BkgBiasTrueP1 = parRes[9+3*npts]; // p1 bias curve result
    } else { // DO NOT USE the bias curve, fit the pot scale
      fitNuisance.POTScaleTrue      = parRes[6+2*npts]; // pot scale result
    }

    for (int i=0; i<npts; i++){
      fitNuisance.BkgTrue.push_back(parRes[7+2*npts+i]);
    }

    if (fConfigPtr->GetAssumeEffiOverBkgCurve()){ // USE the effi/(bkg/pot) curve vs sqrt(s) 
      for (int i=0; i<2; i++){
	fitNuisance.EffiOverBkgTrueP0[i] = parRes[11+3*npts+2*i]; // 11+3*npts, 13+3*npts
	fitNuisance.EffiOverBkgTrueP1[i] = parRes[12+3*npts+2*i]; // 12+3*npts, 14+3*npts
      }
    } else { // DO NOT USE the effi/(bkg/pot) curve --> fit the efficiencies point by point
      for (int i=0; i<npts; i++){
	fitNuisance.SignalEffiLocalTrue.push_back(parRes[3+npts+i]);
      }
    }


    fitNuisance.isNotFilled = false;
    
    // store the minimum lsb value [chi^2 like]
    *lsb = result.MinFcnValue();
  }
  return fitNuisance;
}


nuisancePars statisticalTreatmentTH::MaximizeLBGivenNObs(double* lb){ // maximize Lb wrt nuisance pars, return "profiled" nuisance pars

  int npts = fObservables.SqrtsObs.size();
  nuisancePars fitNuisance;
  
  fFitterB.Config().ParSettings(0).SetValue(1); // B fit
  
  fLikeli.SetObservables(fObservables);
  
  bool okfit = fFitterB.FitFCN();
  if (!okfit) {
    std::cerr << "LB Fit failed" << std::endl;
    fitNuisance.isNotFilled = true;
    *lb = -1;
  }
  else {
    const ROOT::Fit::FitResult & result = fFitterB.Result();    
    if (fVerbosity == 3) result.Print(std::cout);

    // store output fit results into the nuisance parameters
    const double* parRes = result.GetParams();    
    for (int i=0; i<npts; i++){
      fitNuisance.POTTrue.push_back(parRes[3+i]);
    }
    if (fConfigPtr->GetCorrectBkgBias()){ // USE the bias curve, therefore remove the potscale parameter, substituted by the curve
      fitNuisance.BkgBiasTrueP0 = parRes[8+3*npts]; // p0 bias curve result
      fitNuisance.BkgBiasTrueP1 = parRes[9+3*npts]; // p1 bias curve result
    } else {
      fitNuisance.POTScaleTrue      = parRes[6+2*npts]; // pot scale result
    }
    for (int i=0; i<npts; i++){
      fitNuisance.BkgTrue.push_back(parRes[7+2*npts+i]);
    }

    
    fitNuisance.isNotFilled = false;
    
    // store the minimum lsb value [chi^2 like]
    *lb = result.MinFcnValue();
  }
  return fitNuisance;
}


void statisticalTreatmentTH::SimulateSignalPlusBkgPseudoDataToFile(TString filename){
  if (!fIsInitialized){
    std::cout << "Cannot SimulateSignalPlusBkgPseudoDataToFile - no init done " << endl;
    exit(1);
  }


  TFile* filo = new TFile(filename.Data(), "NEW");
  if (!filo->IsOpen()) {
    std::cout << "Cannot open output file " << filename.Data() << endl;
    exit(1);
  }


  for (uint im = 0; im < (uint) fNMassBins; im++){
    double massn = fMassMin + im*fMassStep;
    for (uint ig = 0; ig < (uint) fNgveBins; ig++){
      double gven = TMath::Power(fgveMin*fgveMin*fgveMin*fgveMin + ig*fgveStep,0.25);
      TGraph** nobsGraph = new TGraph*[fNumberOfGenerationsExpectedLimit];
      TGraph** nbGraph = new TGraph*[fNumberOfGenerationsExpectedLimit];
      TGraph** nsGraph = new TGraph*[fNumberOfGenerationsExpectedLimit];
      for (int j=0; j<fNumberOfGenerationsExpectedLimit; j++){
	nobsGraph[j] = new TGraph();
	nobsGraph[j]->SetName(Form("gNObs_Mass_%f_gve_%f_%d",massn,gven,j));
	nbGraph[j] = new TGraph();
	nbGraph[j]->SetName(Form("gNb_Mass_%f_gve_%f_%d",massn,gven,j));
	nsGraph[j] = new TGraph();
	nsGraph[j]->SetName(Form("gNs_Mass_%f_gve_%f_%d",massn,gven,j));
	vector<Double_t> gens = GenerateSignalPlusBackgroundPseudoData(massn,gven,fTheta_B);
	vector<Double_t> nb;
	vector<Double_t> ns;
	vector<Double_t> nobs;
	for (uint q = 0; q < gens.size(); q++){
	  if ((q+1)%3 == 1) nb.push_back(gens.at(q));
	  if ((q+1)%3 == 2) ns.push_back(gens.at(q));
	  if ((q+1)%3 == 0) nobs.push_back(gens.at(q));
	}
	SetNObs(nobs);    
	for (uint i=0; i<fObservables.SqrtsObs.size(); i++){
	  nobsGraph[j]->SetPoint(i,fObservables.SqrtsObs.at(i),fObservables.NObs.at(i)); // sqrt(s) observed
	  nbGraph[j]->SetPoint(i,fObservables.SqrtsObs.at(i),nb.at(i)); 
	  nsGraph[j]->SetPoint(i,fObservables.SqrtsObs.at(i),ns.at(i)); 
	}    
	nobsGraph[j]->Write();	
	nbGraph[j]->Write();	
	nsGraph[j]->Write();	
      }
      for (int j=0; j<fNumberOfGenerationsExpectedLimit; j++) {
	delete nbGraph[j];
	delete nsGraph[j];
	delete nobsGraph[j];
      }
      delete[] nbGraph;
      delete[] nsGraph;
      delete[] nobsGraph;
    }
  }
  filo->Close();
  delete filo;
}


void statisticalTreatmentTH::SimulateBkgPseudoDataToFile(TString filename){
  if (!fIsInitialized){
    std::cout << "Cannot SimulateBkgPseudoDataToFile - no init done " << endl;
    exit(1);
  }


  TFile* filo = new TFile(filename.Data(), "NEW");
  if (!filo->IsOpen()) {
    std::cout << "Cannot open output file " << filename.Data() << endl;
    exit(1);
  }
  TGraph** nobsGraph = new TGraph*[fNumberOfGenerationsExpectedLimit];
  for (int j=0; j<fNumberOfGenerationsExpectedLimit; j++){
    nobsGraph[j] = new TGraph();
    nobsGraph[j]->SetName(Form("gNObs_%d",j));
    SetNObs(GenerateBackgroundPseudoData(fTheta_B));    
    for (uint i=0; i<fObservables.SqrtsObs.size(); i++){
      nobsGraph[j]->SetPoint(i,fObservables.SqrtsObs.at(i),fObservables.NObs.at(i)); // sqrt(s) observed
    }    
    nobsGraph[j]->Write();
  }

  filo->Close();
  delete filo;
  for (int j=0; j<fNumberOfGenerationsExpectedLimit; j++) delete nobsGraph[j];
  delete[] nobsGraph;
}

void statisticalTreatmentTH::SetNObsFromSBFile(TString filename, Double_t mass, Double_t gve, Int_t count){

  // find point in mass grid closest to wanted mass
  double mindistmass = 999999;
  int imc = -1;
  for (uint im = 0; im < (uint) fNMassBins; im++){
    double massn = fMassMin + im*fMassStep;
    if (TMath::Abs(massn-mass) < mindistmass){
      mindistmass = TMath::Abs(massn-mass);
      imc = im;
    }
  }

  // find point in gve grid closest to wanted gve
  double mindistgve = 999999;
  int igc = -1;
  for (uint ig = 0; ig < (uint) fNgveBins; ig++){
    double gven = TMath::Power(fgveMin*fgveMin*fgveMin*fgveMin + ig*fgveStep,0.25);
    if (TMath::Abs(gven-gve) < mindistgve){
      mindistgve = TMath::Abs(gven-gve);
      igc = ig;
    }
  }

  
  TFile* filo = new TFile(filename.Data(), "READ");
  if (!filo->IsOpen()) {
    std::cout << "StatisticalTreatment: SetNObsFromSBFile -> Cannot open input file " << filename.Data() << endl;
    exit(1);
  }

  // set strings with fixed precision
  double massn = fMassMin + imc*fMassStep;
  std::stringstream streamMass;
  streamMass << std::fixed << std::setprecision(3) << massn;
  std::string sMass = streamMass.str();

  double gven = TMath::Power(fgveMin*fgveMin*fgveMin*fgveMin + igc*fgveStep,0.25);
  std::stringstream streamGve;
  streamGve << std::fixed << std::setprecision(6) << gven;
  std::string sGve = streamGve.str();

  TString graphname = Form("gNObs_Mass_%s000_gve_%s_%d",sMass.c_str(),sGve.c_str(),count); //gNObs_Mass_17.540000_gve_0.000498_0

  std::cout << "StatisticalTreatment: SetNObsFromSBFile -> Retrieving nobs graph " << graphname.Data() << " from " << filename.Data() << endl;
  TGraph* nobsGraph = (TGraph*) filo->Get(graphname.Data()); 
  if (nobsGraph == nullptr){
    std::cout << "StatisticalTreatment: SetNObsFromSBFile -> Cannot retrieve nobs graph " << graphname.Data() << " from " << filename.Data() << endl;
    exit(1);
  }

  // fill NObs
  fObservables.NObs.clear();
  for (int i=0; i<nobsGraph->GetN(); i++) fObservables.NObs.push_back(nobsGraph->GetY()[i]); // nobs
  fObservables.isNotFilled = false;

  filo->Close();
  delete filo;
}

void statisticalTreatmentTH::SetNObsFromFile(TString filename, Int_t count){
  TFile* filo = new TFile(filename.Data(), "READ");
  if (!filo->IsOpen()) {
    std::cout << "Cannot open input file " << filename.Data() << endl;
    exit(1);
  }

  TGraph* nobsGraph = (TGraph*) filo->Get(Form("gNObs_%d",count));
  if (nobsGraph == nullptr){
    std::cout << "Cannot retrieve nobs graph " << Form("gNObs_%d",count) << " from " << filename.Data() << endl;
    exit(1);
  }

  // fill NObs
  fObservables.NObs.clear();
  for (int i=0; i<nobsGraph->GetN(); i++) fObservables.NObs.push_back(nobsGraph->GetY()[i]); // nobs
  fObservables.isNotFilled = false;

  filo->Close();
  delete filo;
}

void statisticalTreatmentTH::SaveAllHistos(){

  TString outputfilename  = Form("statisticalTest_massSteps_%d_massRange_%g_%g",fNMassBins,fMassMin,fMassMax);
//				 (int)fMassMin,(int)((fMassMin-(int)fMassMin)*1000. + 0.5),
//				 (int)fMassMax,(int)((fMassMax-(int)fMassMax)*1000. + 0.5));
  outputfilename = Form("%s_UseNuis%d",outputfilename.Data(),(int)(fUseNuisance));
  if (fErrorImprove != 1) outputfilename = Form("%s_errorDownBy%d.%d",outputfilename.Data(),(int)fErrorImprove,(int)((fErrorImprove-(int)fErrorImprove)*10+0.5));
  outputfilename = Form("%s_seed%d.root",outputfilename.Data(),fSeed);
  TFile* filo = new TFile(Form("output/%s",outputfilename.Data()),"RECREATE");

  // Manipulated input used
  if(fPotGraphUsed  != nullptr) fPotGraphUsed ->Write();
  if(fEffiGraphUsed != nullptr) fEffiGraphUsed->Write();
  if(fBkgGraphUsed  != nullptr) fBkgGraphUsed ->Write();
  if(fNormBkgGraphUsed  != nullptr) fNormBkgGraphUsed ->Write();

  fLBHisto->Write();
  for (uint im = 0; im < (uint) fNMassBins; im++){
    fLSBHisto.at(im)->Write(); // LSB vs gven for each pseudo-data event at a given mass
    fQobsHisto.at(im)->Write(); // Qobs vs gven for each pseudo-data event at a given mass
  }
  fQobsAvgHisto->Write(); // average Qobs vs {mass,gven} 

  // histograms for each pseudo data and each toy generated
  fLB_BtoyHisto->Write(); // LB for each pseudo-data event and for each generated B-only toy event

  for (uint im = 0; im < (uint) fNMassBins; im++){
    fLSB_BtoyHisto.at(im)->Write();
    fQbRelHisto.at(im)->Write();
    fLSB_SBtoyHisto.at(im)->Write();
    fQsRelHisto.at(im)->Write();
  }


  fCLsTree->Write();
  fFreqTree->Write();
  
//  fHQValueSB->Write();
//  fHQValueB->Write();
//  fHQValueSBInt->Write();
//  fHQValueBInt->Write();
//  fBanPlot->Write();
//  if (fExpectedSignalPlot)   fExpectedSignalPlot->Write();
//  if (fBanPlotCLAvg) {
//    for (Int_t i=0; i<fNCLAvgs; i++) fBanPlotCLAvg[i]->Write();
//  }
  filo->Close();
  delete filo;
}

