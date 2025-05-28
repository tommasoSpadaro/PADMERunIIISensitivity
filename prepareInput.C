#include "TFile.h"
#include "TFitResultPtr.h"
#include "TFitResult.h"
#include "TMatrixDSym.h"
#include "TH1F.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "TGraph.h"
#include "TLine.h"
#include "TString.h"
#include "TLegend.h"

double fitfun(double* x, double* par);
double fitfunpulls(double* x, double* par);
double SignalShape(double* x, double* par);

void prepareInput(TString fileout){
  double systOnB = 0.003;
  double systOnPoT = 0.003;
  //  TString dirIn = "X17AnalysisNoPhicutRmaxEnforcedOn12";
  //  TString dirIn = "X17AnalysisPhicutTightRmaxEnforcedOn1";
  //  TString dirIn = "oldphiAnalysis"; // phi cut at pi/6, Rmax enforced on cluster 1 and 2, MC with magnetic field OFF, MC GEANT4
  //  TString dirIn = "newphiAnalysis"; // phi cut tighter, Rmax enforced on cluster 1 ONLY, MC signal with magnetic field ON, MC GEANT4
  //  TString dirIn = "finalAnalysis"; // phi cut tighter, Rmax enforced on cluster 1 ONLY, MC signal and bkg with magnetic field ON, MC GEANT4, POT CORRECTIONS
  TString dirIn = "completeAnalysis"; // phi cut tighter, Rmax enforced on cluster 1 ONLY, MC signal and bkg with magnetic field ON, MC GEANT4, POT CORRECTIONS complete
  
  cout << " opening input files from dir " << dirIn.Data() << endl;
  // open file with the POT vs sqrt(s)
  TFile* filePOT = new TFile(Form("%s/PoTCorrvsSqrt.root",dirIn.Data()),"OLD");  // the same for the two analyses
  TGraphErrors* gPoTInput = (TGraphErrors*) filePOT->Get("PoTCorr");

  cout << " pot file opened " << gPoTInput->GetN() << " points " << endl;
  
  // open file with the bkg/pot vs sqrt(s)
  TFile* fileBkg = new TFile(Form("%s/BackgroundYieldvsSqrtS.root",dirIn.Data()),"OLD"); //OK DONE FROM the sum of ee and gg yields
  TGraphErrors* gBkgInput = (TGraphErrors*) fileBkg->Get("BackgroundYield"); //
  if (gBkgInput == nullptr) gBkgInput = (TGraphErrors*) fileBkg->Get("YieldvsSqrsS_bkg");
  cout << " bkg-from-mc file opened " << gBkgInput->GetN() << " points " << endl;

  // open file with the effisig vs sqrt(s)
  TFile* fileEff = new TFile(Form("%s/SignalEffvsSqrtS.root",dirIn.Data()),"OLD"); //OK
  TGraphAsymmErrors* gEffInput = (TGraphAsymmErrors*) fileEff->Get("SigEffvsS");
  
  cout << " signal effi file opened " << gEffInput->GetN() << " points " << endl;

  // open file with the NObs
  TFile* fileNObs = new TFile(Form("%s/N2ClvsSqrsS_data_all_nosyst_noBkg.root",dirIn.Data()),"OLD");
  TGraphErrors* gNObsInput = (TGraphErrors*) fileNObs->Get("N2ClvsSqrsS_data");


  // open file with the scan periods
  TFile* fileSqrts = new TFile(Form("%s/Sqrts.root",dirIn.Data()),"OLD"); // OK COPIED
  TGraph* gSqrtsInput = (TGraph*) fileSqrts->Get("Sqrts");
  int npts = gSqrtsInput->GetN();
  cout << " sqrts file opened " << endl;

  // open file with the Bkg subtraction correction
  TFile* fileN2NoBkg = new TFile(Form("%s/N2NoBkgOvN2.root",dirIn.Data()),"OLD");
  TGraphErrors* gN2NoBkgOvN2 = (TGraphErrors*) fileN2NoBkg->Get("N2NoBkgOvN2");
  cout << "N2 bkg correction file opened " << gN2NoBkgOvN2->GetN() << endl;

  // open file with the leakage correction
  TFile* fileLoss = new TFile(Form("%s/LossFile.root",dirIn.Data()),"OLD");
  TGraphErrors* gLeakage = (TGraphErrors*) fileLoss->Get("gLeakage");
  cout << "Leakage file opened " << gLeakage->GetN() << endl;

  // open file with the ageing correction (scanscale)
  TFile* fileScanscale = new TFile(Form("%s/ScanscaleCorrFile.root",dirIn.Data()),"OLD");
  TGraphErrors* gScanscale = (TGraphErrors*) fileScanscale->Get("gScanscale");
  cout << "Leakage file opened " << gScanscale->GetN() << endl;

  // open file with the TP correction 
  TFile* fileTP = new TFile(Form("%s/tp_all.root",dirIn.Data()),"OLD");
  TGraphErrors* gRatioTP = (TGraphErrors*) fileTP->Get("ratio_tp");
  cout << "TP file opened " << gRatioTP->GetN() << endl;

  // open file with the cut-stability correction 
  TFile* fileRMax = new TFile(Form("%s/RMaxsystvsSqrtS.root",dirIn.Data()),"OLD");
  TGraphErrors* gRMaxsyst = (TGraphErrors*) fileRMax->Get("gRMaxsyst");
  cout << "RMax file opened " << gRMaxsyst->GetN() << endl;


  
  cout << " input sqrts graph retrieved " << npts << " points " << endl;
  
  TGraphErrors* gPoT = new TGraphErrors(); gPoT->SetName("gPoT");
  TGraphErrors* gBkg = new TGraphErrors(); gBkg->SetName("gBkg");
  TGraphErrors* gEff = new TGraphErrors(); gEff->SetName("gEff");
  TGraphErrors* gNObs = new TGraphErrors();gNObs->SetName("gNObs");
  TGraphErrors* gSqrts = new TGraphErrors();gSqrts->SetName("gSqrts");
  TGraph* gPoTInt = new TGraph(); gPoTInt->SetName("gPoTInt");

  

  double potint = 0;
  for (int i=0; i<npts; i++){
    double xsqrts = gSqrtsInput->GetY()[i]; // s = 2me**2 + 2me*Ebeam -> [(s-2me^2)/2me]
    gSqrts->SetPoint(i,xsqrts,i);

    
//    gPoT->SetPoint(i,xsqrts,gPoTInput->GetY()[i]);    
//    gPoT->SetPointError(i,0.,gPoTInput->GetEY()[i]);

    // correct for the systematic error in the Ehit/POT vs POT fit
    gPoT->SetPoint(i,xsqrts,gPoTInput->GetY()[i]);
    gPoT->SetPointError(i,0.,gPoTInput->GetY()[i]*TMath::Sqrt(systOnPoT*systOnPoT + pow(gPoTInput->GetEY()[i]/gPoTInput->GetY()[i],2)));
    //gPoT->SetPointError(i,0.,gPoTInput->GetY()[i]*systOnPoT);

    potint += gPoTInput->GetY()[i];
    gPoTInt->SetPoint(i,xsqrts,potint); // integrated pot

    
    // correct for the systematic error in B/pot
    gBkg->SetPoint(i,xsqrts,gBkgInput->GetY()[i]);
    gBkg->SetPointError(i,0.,gBkgInput->GetY()[i]*TMath::Sqrt(systOnB*systOnB + pow(gBkgInput->GetEY()[i]/gBkgInput->GetY()[i],2)));
    //gBkg->SetPointError(i,0.,gBkgInput->GetEY()[i]);

    double effperrhigh = gEffInput->GetErrorYhigh(i);
    double effperrlow  = gEffInput->GetErrorYlow(i);
    double effperravg  = 0.5*(effperrhigh + effperrlow);
    double effp = gEffInput->GetY()[i];
    gEff->SetPoint(i,xsqrts,effp);
    gEff->SetPointError(i,0.,effperravg);
    
    gNObs->SetPoint(i,xsqrts,gNObsInput->GetY()[i]);
    gNObs->SetPointError(i,0.,gNObsInput->GetEY()[i]);
    
    cout << " point " << i << " sqrt(s) from eff and from bkg diff " << xsqrts-gEffInput->GetX()[i] << " eff = " << effp << " +"<<effperrhigh << " -" << effperrlow << " asym = " << (effperrhigh-effperrlow)/effperravg
	 << " relErrorPOT = " << gPoT->GetEY()[i]/gPoT->GetY()[i] << " pot = " << gPoT->GetY()[i]
	 << " relErrorBKG = " << gBkg->GetEY()[i]/gBkg->GetY()[i]
	 << " relErrorEFF = " << gEff->GetEY()[i]/gEff->GetY()[i]
	 << " relErrorN2  = " << gNObs->GetEY()[i]/gNObs->GetY()[i]
	 << " relErrorTOT = " << TMath::Sqrt(
					     pow(gPoT->GetEY()[i]/gPoT->GetY()[i],2)+
					     pow(gBkg->GetEY()[i]/gBkg->GetY()[i],2)+
					     pow(gEff->GetEY()[i]/gEff->GetY()[i],2)+
					     pow(gNObs->GetEY()[i]/gNObs->GetY()[i],2)
					     )
         
	 << endl;
  }  
  
  // summary of input graphs

  cout << "PoT TGraphErrors:      " << gPoTInput->GetN() << endl;
  cout << "Bkg/PoT TGraphErrors:  " << gBkgInput->GetN() << endl;
  cout << "Eff TGraphAsymmErrors: " << gEffInput->GetN() << endl;
  cout << "NObs TGraphErrors:     " << gNObsInput->GetN() << endl;
  cout << "Sqrts graph:           " << gSqrtsInput->GetN() << endl;

  TCanvas* inputCanva = new TCanvas("inputGraphs");
  inputCanva->Divide(2,2);
  inputCanva->cd(1); gPoT->Draw("PEA");
  inputCanva->cd(2); gBkg->Draw("PEA");
  inputCanva->cd(3); gEff->Draw("PEA");
  inputCanva->cd(4); gSqrtsInput->Draw("PA");

  // 
  
  int igood[3] = {0,0,0};
  int igoodpd = 0;
  TGraphErrors* ratiosel[3];
  TGraphErrors* ratioselB[3];
  for (int k=0; k<3; k++){
    ratiosel[k] = new TGraphErrors();
    ratiosel[k]->SetName(Form("RatioEffSigOverBPerPOT_%d",k));
    ratioselB[k] = new TGraphErrors();
    ratioselB[k]->SetName(Form("RatioBPerPOT_%d",k));
  }
  TGraph* scanPartVsSqrtsgraph = new TGraph();
  TGraph* scanPartVsPeriodgraph = new TGraph();
  scanPartVsSqrtsgraph->SetName("ScanPartVsSqrts");
  scanPartVsPeriodgraph->SetName("ScanPartVsPeriod");

  for (int i=0; i<npts; i++){
    double xsqrts = gSqrtsInput->GetY()[i];

    // define parts of the scan
    int pd = -2;
    if (xsqrts < 16.2) pd = -1; // below-resonance points
    else {
      if (i<23) pd = 0;
      else pd = 1;
    }

    if (i > 46) pd = -1; // 47, 48, 49, 50, 51, 52 -> either high-intensity or new optics at the end of scan2 

    scanPartVsSqrtsgraph->SetPoint(igoodpd,xsqrts,(double)pd);
    scanPartVsPeriodgraph->SetPoint(igoodpd,i,(double)pd);
    igoodpd++;

    if (pd !=0 && pd != 1) continue; // only consider first and second part of the scan, without the below-resonance points
    if (i == 0) continue; // first effi point has a bug and has higher eff
    double bkgp = gBkg->GetY()[i];
    double bkgperr = gBkg->GetEY()[i];

    double effp = gEff->GetY()[i];
    double effperravg = gEff->GetEY()[i];
    double ratio = effp/bkgp;
    double ratioerr = ratio*sqrt(bkgperr*bkgperr/bkgp/bkgp + effperravg*effperravg/effp/effp);

    ratiosel[0]->SetPoint(igood[0],xsqrts,ratio);
    ratiosel[0]->SetPointError(igood[0],0,ratioerr);
    ratioselB[0]->SetPoint(igood[0],xsqrts,bkgp);
    ratioselB[0]->SetPointError(igood[0],0,bkgperr);
    igood[0]++;

    ratiosel[1+pd]->SetPoint(igood[1+pd],xsqrts,ratio);
    ratiosel[1+pd]->SetPointError(igood[1+pd],0,ratioerr);
    ratioselB[1+pd]->SetPoint(igood[1+pd],xsqrts,bkgp);
    ratioselB[1+pd]->SetPointError(igood[1+pd],0,bkgperr);
    igood[1+pd]++;
  }

  // fit eff/B ratio plots with linear functions
  
  TF1* funRatio[3];
  TF1* funRatioUp[3];
  TF1* funRatioDw[3];
  TFitResultPtr fitres[3]; 
  vector<TMatrixDSym> covs;
  vector<TMatrixDSym> cors;

  for (int k=0; k<3; k++) {
    ratiosel[k]->Sort();
    funRatio[k] = new TF1(Form("funRatio_%d",k),fitfun,16.,18.,2);
    funRatioUp[k] = new TF1(Form("funRatioUp_%d",k),fitfun,16.,18.,2);
    funRatioDw[k] = new TF1(Form("funRatioDw_%d",k),fitfun,16.,18.,2);
    TMatrixDSym cov(2);
    covs.push_back(cov);
    TMatrixDSym cor(2);
    cors.push_back(cor);
  }

  // plot fits
  
  TCanvas* cc =new TCanvas("cc");
  TH1F* ratioframe = cc->DrawFrame(16.2,20E3,17.6,30E3);
  ratioframe->SetTitle(";#sqrt{s} (MeV);#varepsilon_{sig}/B");
  ratioframe->GetYaxis()->SetNdivisions(505);
  ratioframe->GetYaxis()->SetTitleOffset(1.1);
  ratioframe->GetYaxis()->SetLabelSize(0.045);
  int markstyle[3] = {24,20,28};
  int colorstyle[3] = {2,1,4};
  int linestyle[3] = {3,1,2};
  TString labelscan[3] = {"1+2","1","2"};
  TLegend* legoratio = new TLegend(0.2,0.7,0.6,0.85);
  //  legoratio->SetHeader("#varepsilon_{sig}/B:");
  
  for (int kk=0; kk<3; kk++) {
    int k = (kk+1)%3; // 1,2,0
    funRatio[k]->SetParameter(0,ratiosel[k]->GetY()[0]);

    ratiosel[k]->SetMarkerStyle(markstyle[k]);
    ratiosel[k]->SetMarkerColor(colorstyle[k]);
    ratiosel[k]->SetLineColor(colorstyle[k]);
    if (k!=0) ratiosel[k]->Draw("PES");
    funRatio[k]->SetLineStyle(linestyle[k]);
    funRatio[k]->SetLineColor(colorstyle[k]);
    fitres[k] = ratiosel[k]->Fit(funRatio[k],"S","same");
    covs.at(k) = fitres[k]->GetCovarianceMatrix();
    cors.at(k) = fitres[k]->GetCorrelationMatrix();
    
    if (k!=0) legoratio->AddEntry(ratiosel[k],Form("Scan %s: P0 = %d #pm %d, P1 = (%d #pm %d) MeV^{-1}, #chi^{2}/ndf = %.1f / %d, Prob = %.2f",labelscan[k].Data(),
						   (int)(fitres[k]->Parameter(0)+0.5),(int)(fitres[k]->ParError(0)+0.5),
						   (int)(fitres[k]->Parameter(1)+0.5),(int)(fitres[k]->ParError(1)+0.5),
						   fitres[k]->Chi2(),(int)fitres[k]->Ndf(),fitres[k]->Prob()),"P");
    std::cout << "Covariance matrix scan part " << k << " = " << covs.at(k)[0][0] << " , " << covs.at(k)[0][1] << " , " << covs.at(k)[1][1] << endl;
    std::cout << "Covariance matrix scan part " << k << " = " << cors.at(k)[0][0] << " , " << cors.at(k)[0][1] << " , " << cors.at(k)[1][1] << endl;
    if (k==0)   funRatio[k]->Draw("same");
//    if (k==1)   {
//      funRatioUp[k]->SetParameters(funRatio[k]->GetParameter(0),funRatio[k]->GetParameter(1)+funRatio[k]->GetParError(1));
//      funRatioDw[k]->SetParameters(funRatio[k]->GetParameter(0),funRatio[k]->GetParameter(1)-funRatio[k]->GetParError(1));
//      funRatioUp[k]->Draw("same");
//      funRatioDw[k]->Draw("same");
//    }
  }
  legoratio->Draw();
  
  for (int kk=0; kk<3; kk++){
    int k = (kk+1)%3; // 1,2,0
    std::cout << Form("EffiOverBkgObsP0_%d",kk) << " " << funRatio[k]->GetParameter(0) << std::endl;
    std::cout << Form("EffiOverBkgObsP1_%d",kk) << " " << funRatio[k]->GetParameter(1) << std::endl;
    std::cout << Form("EffiOverBkgErrP0_%d",kk) << " " << funRatio[k]->GetParError(0) << std::endl;
    std::cout << Form("EffiOverBkgErrP1_%d",kk) << " " << funRatio[k]->GetParError(1) << std::endl;
    std::cout << Form("EffiOverBkgErrP0P1Corr_%d",kk) << " " << cors.at(k)[0][1] << std::endl;
  }


  // fit B/POT plots with linear functions
  
  TF1* funRatioB[3];
  TFitResultPtr fitresB[3]; 
  vector<TMatrixDSym> covsB;
  vector<TMatrixDSym> corsB;

  for (int k=0; k<3; k++) {
    ratioselB[k]->Sort();
    funRatioB[k] = new TF1(Form("funRatioB_%d",k),fitfun,16.,18.,2);
    TMatrixDSym cov(2);
    covsB.push_back(cov);
    TMatrixDSym cor(2);
    corsB.push_back(cor);
  }

  // plot fits
  
  TCanvas* BPerPotCanva =new TCanvas("BPerPotCanva");
  BPerPotCanva->DrawFrame(16.25,2E-6,17.6,4E-6);

  for (int kk=0; kk<3; kk++) {
    int k = (kk+1)%3; // 1,2,0
    funRatioB[k]->SetParameter(0,ratioselB[k]->GetY()[0]);

    ratioselB[k]->SetMarkerStyle(markstyle[k]);
    ratioselB[k]->SetMarkerColor(colorstyle[k]);
    ratioselB[k]->SetLineColor(colorstyle[k]);
    if (k!=0) ratioselB[k]->Draw("PES");
    funRatioB[k]->SetLineStyle(linestyle[k]);
    funRatioB[k]->SetLineColor(colorstyle[k]);
    fitresB[k] = ratioselB[k]->Fit(funRatioB[k],"S","same");
    covsB.at(k) = fitresB[k]->GetCovarianceMatrix();
    corsB.at(k) = fitresB[k]->GetCorrelationMatrix();
    std::cout << "Covariance matrix scan part " << k << " = " << covsB.at(k)[0][0] << " , " << covsB.at(k)[0][1] << " , " << covsB.at(k)[1][1] << endl;
    std::cout << "Covariance matrix scan part " << k << " = " << corsB.at(k)[0][0] << " , " << corsB.at(k)[0][1] << " , " << corsB.at(k)[1][1] << endl;
    if (k==0)   funRatioB[k]->Draw("same");
  }

  for (int kk=0; kk<3; kk++){
    int k = (kk+1)%3; // 1,2,0
    std::cout << Form("BPerPoTObsP0_%d",kk) << " " << funRatioB[k]->GetParameter(0) << std::endl;
    std::cout << Form("BPerPoTObsP1_%d",kk) << " " << funRatioB[k]->GetParameter(1) << std::endl;
    std::cout << Form("BPerPoTErrP0_%d",kk) << " " << funRatioB[k]->GetParError(0) << std::endl;
    std::cout << Form("BPerPoTErrP1_%d",kk) << " " << funRatioB[k]->GetParError(1) << std::endl;
    std::cout << Form("BPerPoTErrP0P1Corr_%d",kk) << " " << corsB.at(k)[0][1] << std::endl;
  }

  
  
  
  TCanvas* dd = new TCanvas("dd");
  dd->Divide(1,2);
  dd->cd(1);
  scanPartVsSqrtsgraph->SetMarkerStyle(20);
  scanPartVsSqrtsgraph->Draw("PA");  
  dd->cd(2);
  scanPartVsPeriodgraph->SetMarkerStyle(24);
  scanPartVsPeriodgraph->Draw("PA");  

  // patch period 0 because of a bug
  gEff->SetPoint(0,gSqrtsInput->GetY()[0],funRatio[1]->Eval(gSqrtsInput->GetY()[0])*gBkg->GetY()[0]);


  TGraphErrors* gPoTZip = new TGraphErrors(); gPoTZip->SetName("gPoT");
  TGraph* gPoTIntZip = new TGraph(); gPoTIntZip->SetName("gPoTInt");
  TGraphErrors* gBkgZip = new TGraphErrors(); gBkgZip->SetName("gBkg");
  TGraphErrors* gEffZip = new TGraphErrors(); gEffZip->SetName("gEff");
  TGraphErrors* gNObsZip = new TGraphErrors(); gNObsZip->SetName("gNObs");
  TGraphErrors* gSqrtsZip = new TGraphErrors(); gSqrtsZip->SetName("gSqrts");
  TGraphErrors* gN2NoBkgOvN2Zip = new TGraphErrors(); gN2NoBkgOvN2Zip->SetName("gN2NoBkgOvN2");
  TGraphErrors* gLeakageZip = new TGraphErrors(); gLeakage->SetName("gLeakage");
  TGraphErrors* gScanscaleZip = new TGraphErrors(); gScanscaleZip->SetName("gScanscale");
  TGraphErrors* gRatioTPZip = new TGraphErrors(); gRatioTPZip->SetName("gRatioTP");
  TGraphErrors* gRMaxsystZip = new TGraphErrors(); gRMaxsyst->SetName("gRMaxsyst");

  
  TGraph* gScanPartVsSqrtsZip = new TGraph(); gScanPartVsSqrtsZip->SetName("ScanPartVsSqrts");
  TGraph* gScanPartVsPeriodZip = new TGraph(); gScanPartVsPeriodZip->SetName("ScanPartVsPeriod");
  int ipts = 0;


  for (int i=0; i < gPoT->GetN(); i++){
    int dataset = scanPartVsSqrtsgraph->GetY()[i];
    //    cout << " i =  " << i << " dta = " << dataset << " ipts = " << ipts << endl;
    if (dataset <  0) continue;

    //    cout << " writing into potzip" << endl;
    gPoTZip->SetPoint(ipts,gPoT->GetX()[i],gPoT->GetY()[i]);
    gPoTZip->SetPointError(ipts,gPoT->GetEX()[i],gPoT->GetEY()[i]);
    gPoTIntZip->SetPoint(ipts,gPoTInt->GetX()[i],gPoTInt->GetY()[i]);
    //    cout << " writing into bkgzip" << endl;
    gBkgZip->SetPoint(ipts,gBkg->GetX()[i],gBkg->GetY()[i]);
    gBkgZip->SetPointError(ipts,gBkg->GetEX()[i],gBkg->GetEY()[i]);

    //    cout << " writing into effzip" << endl;
    gEffZip->SetPoint(ipts,gEff->GetX()[i],gEff->GetY()[i]);
    gEffZip->SetPointError(ipts,gEff->GetEX()[i],gEff->GetEY()[i]);

    //    cout << " writing into potzip" << endl;
    gNObsZip->SetPoint(ipts,gNObs->GetX()[i],gNObs->GetY()[i]);
    gNObsZip->SetPointError(ipts,gNObs->GetEX()[i],gNObs->GetEY()[i]);

    //    cout << " writing into potzip" << endl;
    gSqrtsZip->SetPoint(ipts,gSqrts->GetX()[i],gSqrts->GetY()[i]);

    gN2NoBkgOvN2Zip->SetPoint(ipts,gNObs->GetX()[i],gN2NoBkgOvN2->GetY()[i]);
    gN2NoBkgOvN2Zip->SetPointError(ipts,gNObs->GetEX()[i],gN2NoBkgOvN2->GetEY()[i]);

    gLeakageZip->SetPoint(ipts,gNObs->GetX()[i],gLeakage->GetY()[i]);
    gLeakageZip->SetPointError(ipts,gNObs->GetEX()[i],gLeakage->GetEY()[i]);

    gScanscaleZip->SetPoint(ipts,gNObs->GetX()[i],gScanscale->GetY()[i]);
    gScanscaleZip->SetPointError(ipts,gNObs->GetEX()[i],gScanscale->GetEY()[i]);

    // points of low sqrts have large bkg subtraction due to the brem -> error inflated by 50%
    double inflaerr = 1;
    if (gSqrts->GetX()[i] < 16.59) inflaerr = 1.5;
    else if (gSqrts->GetX()[i] > 17.3) inflaerr = 1.;
    else  inflaerr = 1.0;

//    gRatioTPZip->SetPoint(ipts,gNObs->GetX()[i],gRatioTP->GetY()[i]);
//    gRatioTPZip->SetPointError(ipts,gNObs->GetEX()[i],gRatioTP->GetEY()[i]*inflaerr);

    gRatioTPZip->SetPoint(ipts,gNObs->GetX()[i],pow(gRatioTP->GetY()[i],2));
    gRatioTPZip->SetPointError(ipts,gNObs->GetEX()[i],2*gRatioTP->GetY()[i]*gRatioTP->GetEY()[i]*inflaerr);

    int tobefilled = 0;
    double valfill = 0;
    double evalfill = 0;
    if (TMath::Abs(gRMaxsyst->GetX()[i]-gNObs->GetX()[i]) < 1E-5) {
      tobefilled = 1;
      valfill = 1.+gRMaxsyst->GetY()[i];
      evalfill = valfill*0.0023;
    } else if (i>0 && TMath::Abs(gRMaxsyst->GetX()[i-1]-gNObs->GetX()[i]) < 1E-5) {
      tobefilled = 1;
      valfill = 1.+gRMaxsyst->GetY()[i-1];
      evalfill = valfill*0.0023;
    }
    if (tobefilled) {
      int nnn =     gRMaxsystZip->GetN();
      gRMaxsystZip->SetPoint(nnn,gNObs->GetX()[i], valfill);
      gRMaxsystZip->SetPointError(nnn,gNObs->GetEX()[i], evalfill);
      //      cout << "fill = " << nnn << " " << gNObs->GetX()[i] << " " << valfill << " +- " << evalfill << endl;
    }
    //    cout << " writing into scanpartvssqrts" << endl;
    gScanPartVsSqrtsZip->SetPoint(ipts,scanPartVsSqrtsgraph->GetX()[i],scanPartVsSqrtsgraph->GetY()[i]);
    //    cout << " writing into scanpartvperiod" << endl;
    gScanPartVsPeriodZip->SetPoint(ipts,scanPartVsPeriodgraph->GetX()[i],scanPartVsPeriodgraph->GetY()[i]);

    ipts++;
  }

  
  const int ncorrs = 5;
  TGraphErrors* corrGraphs[ncorrs] = {gN2NoBkgOvN2Zip,gLeakageZip,gScanscaleZip,gRatioTPZip,gRMaxsystZip};
  double avgZipCorr[ncorrs] = {0,0,0,0,0};
  double errZipCorr[ncorrs] = {0,0,0,0,0};
  for (int q=0; q<ncorrs; q++){
    for (int i=0; i<corrGraphs[q]->GetN(); i++){
      avgZipCorr[q] += corrGraphs[q]->GetY()[i]/pow(corrGraphs[q]->GetEY()[i],2);
      errZipCorr[q] += 1./pow(corrGraphs[q]->GetEY()[i],2);
    }
    avgZipCorr[q] /= errZipCorr[q];
    errZipCorr[q] = 1./TMath::Sqrt(errZipCorr[q]);
    for (int i=0; i<corrGraphs[q]->GetN(); i++){
      corrGraphs[q]->SetPoint(i,i,corrGraphs[q]->GetY()[i]/avgZipCorr[q]);
      corrGraphs[q]->SetPointError(i,0.,corrGraphs[q]->GetEY()[i]/avgZipCorr[q]);
//      corrGraphs[q]->SetPoint(i,corrGraphs[q]->GetX()[i],corrGraphs[q]->GetY()[i]/avgZipCorr[q]);
//      corrGraphs[q]->SetPointError(i,0.,corrGraphs[q]->GetEY()[i]/avgZipCorr[q]);
    }
  }

  // plot scan part definitions
  
  TGraph* gSqrtsZipScan[2];
  for (int i = 0; i < 2; i++){ gSqrtsZipScan[i] = new TGraph(); gSqrtsZipScan[i]->SetName(Form("gPeriodIDVsSqrts_Scan%d",i)); }
  for (int i = 0; i < gSqrtsZip->GetN(); i++){
    int scanpart = gScanPartVsSqrtsZip->GetY()[i];
    int nold = gSqrtsZipScan[scanpart]->GetN();
    gSqrtsZipScan[scanpart]->SetPoint(nold,gSqrtsZip->GetX()[i],gSqrtsZip->GetY()[i]);
  }
  
  TCanvas* dsq = new TCanvas("dsq");
  TH1F* scanparth = (TH1F*) dsq->DrawFrame(16.4,-0.5,17.6,48.5);
  scanparth->SetTitle(";#sqrt{s} (MeV);Energy point ID");
  for (int i=0; i<2 ; i++){
    gSqrtsZipScan[i]->SetMarkerStyle(20+4*i);
    gSqrtsZipScan[i]->SetMarkerSize(1.5);
    gSqrtsZipScan[i]->SetLineWidth(2);
    gSqrtsZipScan[i]->Draw("Psame");  
  }

  // plot of pot vs sqrts paper-grade
  TGraphErrors* gPoTAllVsSqrts = new TGraphErrors(); gPoTAllVsSqrts->SetName("PoTAllVsSqrts");
  TGraphErrors* gPoTAllVsE = new TGraphErrors(); gPoTAllVsE->SetName("PoTAllVsE");
  TGraphErrors* gPoTAllVsSqrtsBelowRes = new TGraphErrors(); gPoTAllVsSqrtsBelowRes->SetName("PoTAllVsSqrtsBelowRes");
  TGraphErrors* gPoTAllVsEBelowRes = new TGraphErrors(); gPoTAllVsEBelowRes->SetName("PoTAllVsEBelowRes");
  for (int i = 0; i < gPoT->GetN(); i++){
    if (i > 46) continue;
    gPoTAllVsSqrts->SetPoint(i,gPoT->GetX()[i],gPoT->GetY()[i]); 
    gPoTAllVsSqrts->SetPointError(i,0.,gPoT->GetEY()[i]); 

    double ebeam = (gPoT->GetX()[i]*gPoT->GetX()[i]-2.*0.511*0.511)/(2.*0.511); // s = 2me^2 + 2me*p -> p = (s-2me^2)/(2me);
    gPoTAllVsE->SetPoint(i,ebeam,gPoT->GetY()[i]); 
    gPoTAllVsE->SetPointError(i,0.,gPoT->GetEY()[i]); 

    if (gPoT->GetX()[i] < 15.5){
      int nold = gPoTAllVsSqrtsBelowRes->GetN();
      gPoTAllVsSqrtsBelowRes->SetPoint(nold,gPoT->GetX()[i],gPoT->GetY()[i]); 
      gPoTAllVsSqrtsBelowRes->SetPointError(nold,0.,gPoT->GetEY()[i]); 
      gPoTAllVsEBelowRes->SetPoint(nold,ebeam,gPoT->GetY()[i]); // s = 2me^2 + 2me*p -> p = (s-2me^2)/(2me);
      gPoTAllVsEBelowRes->SetPointError(nold,0.,gPoT->GetEY()[i]); 
    }
  }
  TGraphErrors* gPoTAllVsSqrtsAboveRes = new TGraphErrors(); gPoTAllVsSqrtsAboveRes->SetName("PoTAllVsSqrtsAboveRes");
  TGraphErrors* gPoTAllVsEAboveRes = new TGraphErrors(); gPoTAllVsEAboveRes->SetName("PoTAllVsEAboveRes");
  const double overResEBeam = 402.5;
  const double overResPOT = 1.1E10;
  double overResSqrts = TMath::Sqrt(2.*0.511*0.511+2.*0.511*overResEBeam);
  int nptsall = gPoTAllVsE->GetN();
  gPoTAllVsSqrts->SetPoint(nptsall,overResSqrts,overResPOT); 
  gPoTAllVsSqrts->SetPointError(nptsall,0.,0.003*overResPOT); 
  gPoTAllVsSqrtsAboveRes->SetPoint(0,overResSqrts,overResPOT); 
  gPoTAllVsSqrtsAboveRes->SetPointError(0,0.,0.003*overResPOT); 

  gPoTAllVsE->SetPoint(nptsall,overResEBeam,overResPOT); // s = 2me^2 + 2me*p -> p = (s-2me^2)/(2me);
  gPoTAllVsE->SetPointError(nptsall,0.,0.003*overResPOT);     
  gPoTAllVsEAboveRes->SetPoint(nptsall,overResEBeam,overResPOT);
  gPoTAllVsEAboveRes->SetPointError(nptsall,0.,0.003*overResPOT);     


  TCanvas* dpotvssqrts = new TCanvas("dpotvssqrts");
  gPoTAllVsSqrts->SetTitle(";#sqrt{s} (MeV);N_{PoT}");
  gPoTAllVsSqrts->SetMarkerStyle(20);gPoTAllVsSqrts->SetMarkerColor(kBlue); gPoTAllVsSqrts->Draw("AP");
  gPoTAllVsSqrtsBelowRes->SetMarkerStyle(20);gPoTAllVsSqrtsBelowRes->SetMarkerColor(kGreen); gPoTAllVsSqrtsBelowRes->Draw("PSame");
  gPoTAllVsSqrtsAboveRes->SetMarkerStyle(20);gPoTAllVsSqrtsAboveRes->SetMarkerColor(kRed); gPoTAllVsSqrtsAboveRes->Draw("PSame");

  TCanvas* dpotvse = new TCanvas("dpotvse");
  gPoTAllVsE->SetTitle(";E_{Beam} (MeV);N_{PoT}");
  gPoTAllVsE->SetMarkerStyle(20)        ;gPoTAllVsE->SetMarkerColor(kBlue)         ; gPoTAllVsE->Draw("AP");
  gPoTAllVsEBelowRes->SetMarkerStyle(20);gPoTAllVsEBelowRes->SetMarkerColor(kGreen); gPoTAllVsEBelowRes->Draw("PSame");
  gPoTAllVsEAboveRes->SetMarkerStyle(20);gPoTAllVsEAboveRes->SetMarkerColor(kRed)  ; gPoTAllVsEAboveRes->Draw("PSame");

  cout << "NPOINTS!!!!!! " << gPoT->GetN() << " " << gPoTZip->GetN() << endl;
    

  // plot of the corrections vs sqrts and vs period
  TString corrStr[ncorrs] = {"Background subtraction","Energy loss correction","Radiation induced correction","Tag and probe correction","Acceptance R_{MaX} stability"};
  double ymincorrs[ncorrs] = {999999,999999,999999,999999,999999};
  double ymaxcorrs[ncorrs] = {-999999,-999999,-999999,-999999,-999999};
  TGraphErrors* corrGraphsVsSqrts[ncorrs];
  for (int q=0; q<ncorrs; q++){
    corrGraphsVsSqrts[q] = new TGraphErrors();
    corrGraphsVsSqrts[q]->SetName(Form("%s",corrStr[q].Data()));
    for (int i = 0; i<corrGraphs[q]->GetN(); i++){
      int nold = corrGraphsVsSqrts[q]->GetN();
      corrGraphsVsSqrts[q]->SetPoint(nold,gScanPartVsSqrtsZip->GetX()[i],corrGraphs[q]->GetY()[i]);
      corrGraphsVsSqrts[q]->SetPointError(nold,0.,corrGraphs[q]->GetEY()[i]);
      if (corrGraphs[q]->GetY()[i]-corrGraphs[q]->GetEY()[i] < ymincorrs[q]) ymincorrs[q] = corrGraphs[q]->GetY()[i]-corrGraphs[q]->GetEY()[i];
      if (corrGraphs[q]->GetY()[i]+corrGraphs[q]->GetEY()[i] > ymaxcorrs[q]) ymaxcorrs[q] = corrGraphs[q]->GetY()[i]+corrGraphs[q]->GetEY()[i];
    }
  }


  //  bool singlecanva = kTRUE; // IF TRUE ONLY PLOT CORRECTION VS SQRTS IN A SINGLE PANEL
  
  for (int q=0; q<ncorrs; q++){
    TCanvas* corrCanva = new TCanvas(Form("%s",corrStr[q].Data())); // {gN2NoBkgOvN2Zip,gLeakageZip,gScanscaleZip,gRatioTPZip,gRMaxsystZip};
    //    corrGraphs[q]->Sort();
    corrCanva->Divide(1,2);
    TH1F* framo = corrCanva->cd(1)->DrawFrame(-2.5,ymincorrs[q]-(ymaxcorrs[q]-ymincorrs[q])*0.01,41.5,ymaxcorrs[q]+(ymaxcorrs[q]-ymincorrs[q])*0.01);
    framo->SetTitle(Form(";Energy point ID;%s",corrStr[q].Data()));
    framo->GetYaxis()->SetNdivisions(404);
    framo->GetYaxis()->SetTitleOffset(0.8);
    corrGraphs[q]->SetMarkerStyle(20+4*q);
    corrGraphs[q]->SetMarkerColor(1);
    corrGraphs[q]->Draw("Psame");
    TH1F* frame = corrCanva->cd(2)->DrawFrame(16.35,ymincorrs[q]-(ymaxcorrs[q]-ymincorrs[q])*0.01,17.45,ymaxcorrs[q]+(ymaxcorrs[q]-ymincorrs[q])*0.01);
    frame->SetTitle(Form(";#sqrt{s} (MeV);%s",corrStr[q].Data()));
    frame->GetYaxis()->SetTitleOffset(0.8);
    frame->GetYaxis()->SetNdivisions(404);
    corrGraphsVsSqrts[q]->SetMarkerStyle(20+4*q);
    corrGraphsVsSqrts[q]->SetMarkerColor(1);
    corrGraphsVsSqrts[q]->Draw("Psame");
    if (corrStr[q].Contains("stability")){
      TLine* linermaxup[2];
      for (int nl = 0; nl < 2; nl++) {
	linermaxup[nl] = new TLine(16.35, (nl==0? (1+0.002) : (1.-0.002)),17.45,(nl==0? (1.+0.002) : (1.-0.002)));
	linermaxup[nl]->SetLineStyle(2);
	linermaxup[nl]->Draw("same");
      }
      cout << "FITTING RMAX " << endl;
      corrGraphsVsSqrts[q]->Fit("pol0","","same");
    }
    if (corrStr[q].Contains("Tag")){
      cout << "FITTING TAGANDPROBE " << endl;
//      TF1* fittp = new TF1("funfitp",fitfun,16.,18.,2);
//      corrGraphsVsSqrts[q]->Fit(fittp,"","same");
      corrGraphsVsSqrts[q]->Fit("pol0","","same");
    }
  }

  
  TFile* outputFile = new TFile(Form("../PADME_sensitivity/input/%s.root",fileout.Data()),"NEW");
  gPoT->Write();
  gPoTInt->Write();
  gBkg->Write();
  gEff->Write();
  gNObs->Write();
  scanPartVsSqrtsgraph->Write();  
  scanPartVsPeriodgraph->Write();
  outputFile->Close();

  TFile* outputFileZip = new TFile(Form("../PADME_sensitivity/input/%s_zip.root",fileout.Data()),"NEW");
  gPoTZip->Write();
  gPoTIntZip->Write();
  gBkgZip->Write();
  gEffZip->Write();
  gNObsZip->Write();
  gScanPartVsSqrtsZip->Write();  
  gScanPartVsPeriodZip->Write();
  outputFileZip->Close();

  // info from the automatic procedure
//==SignalPotAccCorr==  Best chi2 achieved: 24.1649  NDF:  30  with mask starting at:  13  Starting from chi2:   40.0596
//==SignalPotAccCorr==  Mean value on Y:   1.01132  RMS:  0.00792875 Relative spread: 0.00784003  RMS of the pulls/sigma:   0.882887
//==SignalPotAccCorr==  Const:   1.01165 +- 0.00163108   Slope:  -0.0103716 +- 0.00501069
  
  const double massFound = 16.888;
  const double parFound[2] = {1.0116,-0.0103};
  const int maskedNPts = 10;

  // info from the observed limit
  const double massObsMax = 16.9;//17.04;////17.04;//16.92;
  const double couplingObsMax = 0.000559;//0.000543;//0.00052;//
  TFile* filefit = new TFile("/Users/Tommaso1/PADME/PADME_sensitivity/output/statisticalTest_massSteps_76_massRange_16.22_17.74_UseNuis1_seed970084.root");
  TGraph* sbfitobs = (TGraph*) filefit->Get("SBFitOnBToyGraph_im34_ig20_mass16.900000_gven0.000550_pseudoEvts");


  // info from the SB fit to the N/POT obs: pulls
  const double signalpeakini = 13.56;
  const double signalpeakerr = 0.18;
  const double pullsignalpeak = -0.08;
  double signalpeak = signalpeakini + pullsignalpeak*signalpeakerr;
  const double BESini = 0.0025;
  const double BESerr = 0.005;
  const double pullBES = 0.05;
  double BES = BESini + pullBES*BESerr;
  const double signallorewidthini = 1.72;
  const double signallorewidtherr = 0.039;
  const double pullsignallorewidth = 0.05;
  double signallorewidth = signallorewidthini + pullsignallorewidth*signallorewidtherr;

  // overall scale pol1
  const double bkgbiasp0ini = 1.01163;
  const double bkgbiasp0err = 0.0013;
  const double pullbkgbiasp0 = -0.46; // significantly lowers p0  
  double bkgbiasp0 = bkgbiasp0ini + pullbkgbiasp0*bkgbiasp0err;

  const double bkgbiasp1ini = -0.0103;
  const double bkgbiasp1err = 0.004;
  const double pullbkgbiasp1 = -0.35; // significantly lowers p1 -> slope is even more negative
  double bkgbiasp1 = bkgbiasp1ini + pullbkgbiasp0*bkgbiasp0err;

  // bkg/pot pol1
  const double bkgoverpotp0ini = 3.55894e-06;
  const double bkgoverpotp0err = 3.58951e-09;
  const double pullbkgoverpotp0 = -0.36; //lowers bkg/pot p0, but the error was 0.1% relative, so it lowers by 0.03%
  double bkgoverpotp0 = bkgoverpotp0ini + pullbkgoverpotp0*bkgoverpotp0err;
  
  const double bkgoverpotp1ini = 3.86892e-07;
  const double bkgoverpotp1err = 1.24996e-08;
  const double pullbkgoverpotp1 = -0.36; // significantly decreases the positive slope of B/pot
  double bkgoverpotp1 = bkgoverpotp1ini + pullbkgoverpotp1*bkgoverpotp1err; 

    
  TF1* signalShapeFun = new TF1("signalShapeFun",SignalShape,16.,18.,4);
  signalShapeFun->SetParameters(signalpeak,BES,signallorewidth,massObsMax);

  
  TF1* sidebandFit = new TF1("sidebandFit","[0]+[1]*(x-16.92)",15.,19.); 
  sidebandFit->SetParameter(0,parFound[0]);
  sidebandFit->SetParameter(1,parFound[1]);

  
  TGraphErrors* gRZip = new TGraphErrors(); gRZip->SetName("gR");
  TGraphErrors* gRZipScan1 = new TGraphErrors(); gRZipScan1->SetName("gRScan1");
  TGraphErrors* gRZipScan2 = new TGraphErrors(); gRZipScan2->SetName("gRScan2");

  TGraph* PointsSidebandGraph = new TGraph(); PointsSidebandGraph->SetName("SidebandPoints");
  TGraph* bestSignal = new TGraph(); bestSignal->SetName("bestSignal");

  TGraph* relErrNObsZip = new TGraph(); relErrNObsZip->SetName("NObsRelErr");
  TGraph* relErrPoTZip = new TGraph(); relErrPoTZip->SetName("PoTRelErr");
  TGraph* relErrBkgZip = new TGraph(); relErrBkgZip->SetName("BkgRelErr");
  TGraph* relErrRZip = new TGraph(); relErrRZip->SetName("RRelErr");

  const double relerrUnit = 100;
  for (int i=0; i<gPoTZip->GetN(); i++){
    PointsSidebandGraph->SetPoint(i,TMath::Abs(gPoTZip->GetX()[i]-massFound),i);

//what I fit    double rnow = gNObsZip->GetY()[i]/(gPoTZip->GetY()[i]*(bkgoverpotp0ini + bkgoverpotp1ini*(gPoTZip->GetX()[i]-16.92))); 
//what I fit    double ernow = TMath::Sqrt(
//what I fit      pow(gNObsZip->GetEY()[i]/gNObsZip->GetY()[i],2) +
//what I fit      pow(gPoTZip->GetEY()[i]/gPoTZip->GetY()[i],2) 
//what I fit			       )*rnow;

// what ven is fitting
    double rnow = gNObsZip->GetY()[i]/(gPoTZip->GetY()[i]*gBkgZip->GetY()[i]);
    double ernow = TMath::Sqrt(
      pow(gNObsZip->GetEY()[i]/gNObsZip->GetY()[i],2) +
      pow(gPoTZip->GetEY()[i]/gPoTZip->GetY()[i],2) 
      + pow(gBkgZip->GetEY()[i]/gBkgZip->GetY()[i],2)
			       )*rnow;
    
    relErrNObsZip->SetPoint(i,gPoTZip->GetX()[i],gNObsZip->GetEY()[i]/gNObsZip->GetY()[i]*relerrUnit);
    relErrPoTZip->SetPoint(i, gPoTZip->GetX()[i],gPoTZip->GetEY()[i]/gPoTZip->GetY()[i]*relerrUnit);
    relErrBkgZip->SetPoint(i, gPoTZip->GetX()[i],TMath::Sqrt(pow(gBkgZip->GetEY()[i]/gBkgZip->GetY()[i],2))*relerrUnit);
    relErrRZip->SetPoint(i,   gPoTZip->GetX()[i],ernow/rnow*relerrUnit);


    gRZip->SetPoint(i,gPoTZip->GetX()[i],rnow);
    gRZip->SetPointError(i,0.,ernow);

    if (gScanPartVsSqrtsZip->GetY()[i] == 0) {
      int npt = gRZipScan1->GetN();
      gRZipScan1->SetPoint(npt,gPoTZip->GetX()[i],rnow);
      gRZipScan1->SetPointError(npt,0.,ernow);
    } else if (gScanPartVsSqrtsZip->GetY()[i] == 1) {
      int npt = gRZipScan2->GetN();
      gRZipScan2->SetPoint(npt,gPoTZip->GetX()[i],rnow);
      gRZipScan2->SetPointError(npt,0.,ernow);
    } 

    // determine best signal
    bestSignal->SetPoint(i,gPoTZip->GetX()[i],
			 (bkgoverpotp0ini + bkgoverpotp1ini*(gPoTZip->GetX()[i]-16.92))/(bkgoverpotp0 + bkgoverpotp1*(gPoTZip->GetX()[i]-16.92))*
			 //			 gNObsZip->GetY()[i]/gPoTZip->GetY()[i]/(bkgoverpotp0 + bkgoverpotp1*(gPoTZip->GetX()[i]-16.92))*
			 (bkgbiasp0+bkgbiasp1*(gPoTZip->GetX()[i]-16.92))*
			 (1+signalShapeFun->Eval(gPoTZip->GetX()[i])*pow(couplingObsMax,2)*funRatio[0]->Eval(gPoTZip->GetX()[i]))
			 );
    cout << "signal " << bestSignal->GetY()[i] << " sqrts = " << gPoTZip->GetX()[i] << " shape = " << signalShapeFun->Eval(gPoTZip->GetX()[i]) << "eps/B = " << funRatio[0]->Eval(gPoTZip->GetX()[i]) << endl;
  }
  PointsSidebandGraph->Sort();
  int isMasked[100] = {0};
  for (int i=0; i<maskedNPts; i++) isMasked[(int)PointsSidebandGraph->GetY()[i]] = 1;
  
  TGraphErrors* gRZipMasked[3];  //scan1,2,all
  TGraphErrors* gRZipSideband[3];//scan1,2,all
  for (int i=0; i<3; i++){
    gRZipMasked[i] = new TGraphErrors(); gRZipMasked[i]->SetName(Form("gRMasked_scan%d",i));
    gRZipSideband[i] = new TGraphErrors(); gRZipSideband[i]->SetName(Form("gRSideband_scan%d",i));
  }
  TGraph* gRZipPullsSideband = new TGraph(); gRZipPullsSideband->SetName("gRPullsSideband");

  TGraphErrors* gRZipMaskedAtStage[5];   // do not apply bkgsub, loss, ageing, apply all, apply tp also
  TGraphErrors* gRZipSidebandAtStage[5]; // do not apply bkgsub, loss, ageing, apply all, apply tp also
  for (int i=0; i<5; i++){
    gRZipMaskedAtStage[i] = new TGraphErrors();
    gRZipMaskedAtStage[i]->SetName(Form("gRMaskedStage_%d",i));
    gRZipSidebandAtStage[i] = new TGraphErrors();
    gRZipSidebandAtStage[i]->SetName(Form("gRSidebandStage_%d",i));
  }  

  
  double sqrtsMaskedRangeMin = 99999.;
  double sqrtsMaskedRangeMax = -99999.;
  for (int i=0; i<gPoTZip->GetN(); i++){
//    double corrval[4] = {
//      1./corrGraphs[0]->GetY()[i]*corrGraphs[1]->GetY()[i]*corrGraphs[2]->GetY()[i],
//      corrGraphs[1]->GetY()[i]*corrGraphs[2]->GetY()[i],
//      corrGraphs[2]->GetY()[i],
//      1.};
    double corrval[5] = {
      1./corrGraphs[0]->GetY()[i],
      corrGraphs[1]->GetY()[i],
      1./corrGraphs[2]->GetY()[i],
      1.,
      corrGraphs[3]->GetY()[i]};

    if (isMasked[i]) {
      // fill for all scans
      int nnow = gRZipMasked[2]->GetN();
      gRZipMasked[2]->SetPoint(nnow,gRZip->GetX()[i],gRZip->GetY()[i]);
      gRZipMasked[2]->SetPointError(nnow,gRZip->GetEX()[i],gRZip->GetEY()[i]);

      // fill scan-level
      int scanid = gScanPartVsSqrtsZip->GetY()[i];  
      int nnowscan = gRZipMasked[scanid]->GetN();
      gRZipMasked[scanid]->SetPoint(nnowscan,gRZip->GetX()[i],gRZip->GetY()[i]);
      gRZipMasked[scanid]->SetPointError(nnowscan,gRZip->GetEX()[i],gRZip->GetEY()[i]);

      if (gRZip->GetX()[i] < sqrtsMaskedRangeMin) sqrtsMaskedRangeMin = gRZip->GetX()[i];
      if (gRZip->GetY()[i] > sqrtsMaskedRangeMax) sqrtsMaskedRangeMax = gRZip->GetX()[i];

      for (int q=0; q<5; q++) {
	gRZipMaskedAtStage[q]->SetPoint(nnow,gRZip->GetX()[i],gRZip->GetY()[i]*corrval[q]);
	gRZipMaskedAtStage[q]->SetPointError(nnow,0.,gRZip->GetEY()[i]*corrval[q]);
      }
    } else {
      // fill for all scans together
      int nnow = gRZipSideband[2]->GetN();
      gRZipSideband[2]->SetPoint(nnow,gRZip->GetX()[i],gRZip->GetY()[i]);
      gRZipSideband[2]->SetPointError(nnow,gRZip->GetEX()[i],gRZip->GetEY()[i]);
      gRZipPullsSideband->SetPoint(nnow,nnow,(gRZip->GetY()[i]-(parFound[0]+parFound[1]*(gRZip->GetX()[i]-16.92)))/gRZip->GetEY()[i]);
      for (int q=0; q<5; q++) {
	gRZipSidebandAtStage[q]->SetPoint(nnow,gRZip->GetX()[i],gRZip->GetY()[i]*corrval[q]);
	gRZipSidebandAtStage[q]->SetPointError(nnow,0.,gRZip->GetEY()[i]*corrval[q]);
      }

      // fill scan-level
      int scanid = gScanPartVsSqrtsZip->GetY()[i];  
      int nnowscan = gRZipSideband[scanid]->GetN();
      gRZipSideband[scanid]->SetPoint(nnowscan,gRZip->GetX()[i],gRZip->GetY()[i]);
      gRZipSideband[scanid]->SetPointError(nnowscan,gRZip->GetEX()[i],gRZip->GetEY()[i]);
      
    }
  }
  // refine range to fit with the sideband points
  double distanceToRangeMin = 99999;
  double distanceToRangeMax = 99999;
  for (int i=0; i<gRZipSideband[2]->GetN(); i++){    
    if (TMath::Abs(gRZipSideband[2]->GetX()[i]-sqrtsMaskedRangeMin) < distanceToRangeMin) {
      distanceToRangeMin = TMath::Abs(gRZipSideband[2]->GetX()[i]-sqrtsMaskedRangeMin);
    }
    if (TMath::Abs(gRZipSideband[2]->GetX()[i]-sqrtsMaskedRangeMax) < distanceToRangeMax) {
      distanceToRangeMax = TMath::Abs(gRZipSideband[2]->GetX()[i]-sqrtsMaskedRangeMax);
    }
  }

  TCanvas* pullcanva = new TCanvas("pullCanva");
  TH1F* pullframe = pullcanva->DrawFrame(-0.5,-3.,32.5,3.);
  pullframe->SetTitle(";Energy point ID; g_{R} Fit Pulls");
  pullframe->GetYaxis()->SetTitleOffset(1.0);
  pullframe->GetXaxis()->SetLabelOffset(0.006);

  gRZipPullsSideband->SetMarkerStyle(20);
  gRZipPullsSideband->SetMarkerSize(1);
  gRZipPullsSideband->SetMarkerColor(kBlack);
  gRZipPullsSideband->Draw("Psame");
  TF1* funPulls = new TF1("funPulls",fitfunpulls,0.,35.,2);
  funPulls->SetParameter(0,0.);
  funPulls->SetParameter(1,0.);
  funPulls->SetLineColor(kBlue);
  funPulls->SetLineWidth(2);
  funPulls->SetLineStyle(2);
  
  TFitResultPtr fitrespulls = gRZipPullsSideband->Fit(funPulls,"S","same");
  TLegend* legopulls = new TLegend(0.2,0.7,0.8,0.85);
  legopulls->AddEntry(funPulls,Form("#splitline{P0 = %.2f #pm %.2f, P1 = (%.2f #pm %.2f)}{#chi^{2}/ndf = %.1f / %d, Prob = %.2f}",
						   fitrespulls->Parameter(0),fitrespulls->ParError(0),
						   fitrespulls->Parameter(1),fitrespulls->ParError(1),
						   fitrespulls->Chi2(),(int)fitrespulls->Ndf(),fitrespulls->Prob()),"L");
  legopulls->Draw();

  //

  

  
  // gR plots
  TCanvas* rcanva = new TCanvas("rcanva");
  TH1F* framer = rcanva->DrawFrame(16.3,0.98,17.5,1.07);
  framer->SetTitle(";#sqrt{s} (MeV);g_{R}(s)");
  framer->GetYaxis()->SetNdivisions(405);
  framer->GetYaxis()->SetTitleOffset(1.1);
  TLegend* legogr = new TLegend(0.6,0.6,0.85,0.85);
  
  for (int i=0; i<2; i++){
    gRZipSideband[i]->SetMarkerStyle(20+i);
    gRZipSideband[i]->SetMarkerSize(1);
    gRZipSideband[i]->SetMarkerColor(kBlack);
    gRZipSideband[i]->SetLineColor(kBlack);
    gRZipSideband[i]->Draw("Psame");

    gRZipMasked[i]->SetMarkerStyle(20+i);
    gRZipMasked[i]->SetMarkerColor(kRed);
    gRZipMasked[i]->SetLineColor(kRed);
    gRZipMasked[i]->Draw("Psame");

  }
  for (int i=0; i<2; i++) legogr->AddEntry(gRZipSideband[i],Form("Sideband data, scan %d",i+1),"PE");
  for (int i=0; i<2; i++) legogr->AddEntry(gRZipMasked[i],  Form("Masked   data, scan %d",i+1),"PE");
  //  gRZipScan1->Draw("PXsame");

  
//  bestSignal->Sort();
//  bestSignal->SetMarkerStyle(24);
//  bestSignal->SetMarkerColor(kPink);
//  bestSignal->Draw("PLsame");

  sbfitobs->Sort();
  sbfitobs->SetLineStyle(1);
  sbfitobs->SetLineWidth(2);
  sbfitobs->SetLineColor(kOrange+7); sbfitobs->SetMarkerColor(kOrange+7); 
  sbfitobs->Draw("PLsame");


  
  // add sideband fit and interpolation
  TF1* sidebands[3]; // left, window, right
  TF1* sidebandLocalFits[3];
  double rangelineMin[3] = {16.,                                   sqrtsMaskedRangeMin, sqrtsMaskedRangeMax+distanceToRangeMax}; 
  double rangelineMax[3] = {sqrtsMaskedRangeMin-distanceToRangeMin,sqrtsMaskedRangeMax, 18.}; 



  int colors[3] = {kBlue,kRed,kBlue};
  int linemodes[3] = {1,2,1};
  /*
  for (int i=0; i<3; i++){
    cout << "range line " << i << " " << rangelineMin[i] << " -> " << rangelineMax[i] << endl;
    if (i != 1) {
      sidebandLocalFits[i] = new TF1(Form("sidebandLocalFits%d",i),"[0]+[1]*(x-16.92)",rangelineMin[i],rangelineMax[i]); // left, window, right
      sidebandLocalFits[i]->SetParameter(0,parFound[0]);
      sidebandLocalFits[i]->SetParameter(1,parFound[1]);
      TFitResultPtr resfit = gRZipSideband->Fit(sidebandLocalFits[i],"S","same",rangelineMin[i],rangelineMax[i]);
      cout << "Prob of single-sideband fit is " << resfit->Prob() << endl;
    }
    else {
      sidebandLocalFits[i] = new TF1(Form("sidebandLocalFits%d",i),"[0]+[1]*(x-16.92)",rangelineMin[0],rangelineMax[2]); // left and right sidebands
      sidebandLocalFits[i]->SetParameter(0,parFound[0]);
      sidebandLocalFits[i]->SetParameter(1,parFound[1]);
      TFitResultPtr resfit = gRZipSideband->Fit(sidebandLocalFits[i],"S","same",rangelineMin[0],rangelineMax[2]);
      cout << "Prob of full-sideband fit is " << resfit->Prob() << endl;
    }
}
  */
  for (int i=0; i<3; i++){
    sidebands[i] = new TF1(Form("sideband%d",i),"[0]+[1]*(x-16.92)",rangelineMin[i],rangelineMax[i]);
    sidebands[i]->SetParameter(0,parFound[0]);
    sidebands[i]->SetParameter(1,parFound[1]);
    sidebands[i]->SetLineColor(colors[i]); sidebands[i]->SetLineWidth(4); sidebands[i]->SetLineStyle(linemodes[i]);
  }
  for (int i=0; i<3; i++){
    sidebands[i]->Draw("Lsame");
  }
  legogr->AddEntry(sidebands[0],"Sideband fit","L");
  legogr->AddEntry(sidebands[1],"Sideband fit in masked region","L");
  legogr->AddEntry(sbfitobs,"S+B fit","PL");
  legogr->Draw();
  
  // corrections plots
  
  int colorcorr[5] = {kGreen+1,kViolet-2,kMagenta-4,kBlack,kRed+2};
  int stylecorrOpen[5] = {25,26,46,24,28}; // open sysmbols: square, triangle, s.andrew-cross, circle
  int stylecorrFill[5] = {21,22,47,20,34}; // filled sysmbols:
  // corrections at various stages

  TCanvas* canvaStage = new TCanvas("canvaStage");
  canvaStage->DrawFrame(16.3,0.9,17.5,1.1);
  for (int i=0; i<5; i++) { // analysis stages
    gRZipSidebandAtStage[i]->SetMarkerStyle(stylecorrFill[i]);//Open[i]);
    gRZipSidebandAtStage[i]->SetMarkerColor(colorcorr[i]);
    gRZipSidebandAtStage[i]->SetLineColor(colorcorr[i]);
    if (i != 3) gRZipSidebandAtStage[i]->SetMarkerSize(1.4);


    if (i!=3) gRZipSidebandAtStage[i]->Draw("PXsame");
    else      gRZipSidebandAtStage[i]->Draw("Psame");

    gRZipMaskedAtStage[i]->SetMarkerStyle(stylecorrFill[i]);
    gRZipMaskedAtStage[i]->SetMarkerColor(colorcorr[i]);
    gRZipMaskedAtStage[i]->SetLineColor(colorcorr[i]);
    if (i != 3) gRZipMaskedAtStage[i]->SetMarkerSize(1.4);

    if (i !=3) gRZipMaskedAtStage[i]->Draw("PXsame");
    else      gRZipMaskedAtStage[i]->Draw("Psame");
  }
  for (int j=0; j<3; j++) sidebands[j]->Draw("Lsame");
  sbfitobs->Draw("PLsame");
  
//  gRZipScan1->SetMarkerStyle(28);
//  gRZipScan1->Draw("Psame");

  // single corrections one at a time
  
  TCanvas* canvaStageSingleCorr[4];
  for (int i=0; i<5; i++) { // one correction missing at a time
    if (i==3) continue;
    canvaStageSingleCorr[i] = new TCanvas(Form("canvaStage_%d",i));
    canvaStageSingleCorr[i]->DrawFrame(16.3,0.94,17.5,1.06);
    gRZipSidebandAtStage[i]->Draw("PXsame");
    gRZipSidebandAtStage[3]->Draw("Psame");

    gRZipMaskedAtStage[i]->Draw("PXsame");
    gRZipMaskedAtStage[3]->Draw("Psame");

    for (int j=0; j<3; j++) sidebands[j]->Draw("Lsame");
    sbfitobs->SetLineColor(kOrange+7); sbfitobs->Draw("PLsame");
    
  }
//  gRZipScan1->SetMarkerStyle(28);
//  gRZipScan1->Draw("Psame");
  
// plot of N2

  TCanvas* n2canva = new TCanvas("n2canva");
  n2canva->Divide(1,2);
  n2canva->cd(1); gNObsZip->Draw("AP");
  n2canva->cd(2); relErrNObsZip->Draw("AP");
  
  // plot of relative errors
  TLegend* relerrleg = new TLegend(0.2,0.68,0.43,0.88);
  //  relerrleg->SetHeader("Relative errors on g_{R}(s):");
  TString relerrnames[4] = {"g_{R}","N_{2}","N_{PoT}","B"};
  TGraph* relerrGraphs[4] = {relErrRZip,relErrNObsZip,relErrPoTZip,relErrBkgZip};
  TCanvas* relErrs = new TCanvas("relErr");
  int colorcorrRel[4] = {kBlack,kViolet-2,kRed,kGreen+1};
  TH1F* framerelerr = relErrs->DrawFrame(16.2,0.,17.5,0.015*relerrUnit);
  framerelerr->SetTitle(";#sqrt{s} (MeV);Relative error, %");
  framerelerr->GetYaxis()->SetTitleOffset(1.0);
  framerelerr->GetXaxis()->SetLabelOffset(0.006);
  int ordo[4] = {0,1,3,2};
  for (int ii=0; ii<4; ii++){
    int i = ordo[ii];
    relerrGraphs[i]->SetMarkerStyle(stylecorrFill[i]);
    relerrGraphs[i]->SetMarkerColor(colorcorrRel[i]);
    relerrGraphs[i]->SetLineColor(colorcorrRel[i]);
    relerrGraphs[i]->Draw("Psame");
    relerrleg->AddEntry(relerrGraphs[i],relerrnames[i].Data());
  }
  relerrleg->Draw();
}

double fitfun(double* x, double* par){
  return par[0]+par[1]*(x[0]-16.92);//+par[2]*(x[0]-16.92)*(x[0]-16.92);
}

double fitfunpulls(double* x, double* par){
  return par[0]+par[1]*(x[0]-15)/15.;
}


double SignalShape(double* x, double* par){  // return number of signal events produced(not the accepted) / POT at sqrts(s) at gven = 1
  double signalpeak = par[0];
  double bes = par[1];
  double lorewidth = par[2];
  double massn = par[3];
  double sqrts = x[0];
    const double me = 0.511;// MeV
    const double Wb = -7E-6;// MeV
    double eRes = (massn*massn - 2*me*me)/(2.*(me+Wb));
    double eBeam = (sqrts*sqrts - 2*me*me)/(2.*me); // s = 2me^2 + 2meEbeam -> eBeam = (s-2me^2) / 2me
    return signalpeak*TMath::Voigt(eBeam-eRes,bes*eRes,lorewidth*2,5); // last input was 4 but with low BES can have rounding problems
  }

