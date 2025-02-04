#ifndef STATISTICALTREATMENTTH_HH
#define STATISTICALTREATMENTTH_HH

//#include "nuisancePars.hh"
#include "statConfig.hh"
#include "TMath.h"
#include <Fit/Fitter.h>
#include "TH1D.h"
#include "TH2D.h"
#include "TTree.h"
#include "TGraphErrors.h"
#include "TRandom3.h"

using namespace std;
#define SQRTSMID 16.92

struct CLsinfo{
  int ipseudodata;
  int startingSeed;
  int im;
  int ig;
  double massn;
  double gven;
  double Qobs;
  double Lb;
  double Ps;
  int NsValid;
  double Pb;
  int NbValid;
  double CLs;
};

struct Freqinfo{
  int ipseudodata;
  int startingSeed;
  int im;
  double massn;
  double rolke90;
  double rolke95;
  double feldman90;
  double feldman95;
};


struct observables{
  bool isNotFilled = true; // true if struct is not filled
  vector<Double_t> NObs;           // counts per sqrts
  vector<Double_t> SqrtsObs;       // estimated sqrts per point
  vector<Int_t> ScanPeriod;        // scan period index for that point
  vector<Double_t> POTObs;         // estimated POT per point, in 1E10 units
  vector<Double_t> SignalEffiLocalObs;  // estimated efficiency
  Double_t POTScaleObs;            // absolute relative scale correction on the POT [independent on sqrt(s)]
  vector<Double_t> BkgObs;         // estimated Number of bkg / POT per point
  Double_t SignalPeakYieldObs;     // estimated signal yield at the peak
  Double_t SignalLorentzianWidthObs;       // estimated value of Lorentzian width for the signal shape
  Double_t BESObs;                 // estimated value of the BES
  Double_t BkgBiasObsP0;              // estimated value of par0 of the pol1 used to fit in sideband the bias data/mc [nobs/(bkg/pot)/pot] vs sqrt(s)
  Double_t BkgBiasObsP1;              // estimated value of par1 of the pol1 used to fit in sideband the bias data/mc [nobs/(bkg/pot)/pot] vs sqrt(s)
  Double_t EffiOverBkgObsP0[3];       // estimated value of par0 of the pol1 used to fit in sideband the ratio effisig/(bkg/pot) vs sqrt(s): 2 periods of the scan [period 1, 2, total]
  Double_t EffiOverBkgObsP1[3];       // estimated value of par1 of the pol1 used to fit in sideband the ratio effisig/(bkg/pot) vs sqrt(s): 2 periods of the scan [period 1, 2, total]
  Double_t BkgPerPOTVsSqrtsParObs[2];    // pol1 fit of B/POT vs sqrt(s): parameter values
};

struct expectedErrors{
  bool isNotFilled = true; // true if struct is not filled
  vector<Double_t> POTLocalErr;           // error on the POT in 1E10 units, uncorrelated point per point
  vector<Double_t> SignalEffiLocalErr;   // error on the signal efficiency, uncorrelated point per point
  Double_t POTScaleErr;       // error on absolute POT scale [independent on the sqrt(s)]
  vector<Double_t> BkgErr; // absolute error on the bkg ratio
  Double_t SignalPeakYieldErr; // error on the signal peak yield
  Double_t SignalLorentzianWidthErr;  // absolute error on the signal Lorentzian width
  Double_t BESErr;            // absolute error on the BES
  Double_t BkgBiasErrP0;              // estimated error on par0 of the pol1 used to fit in sideband the bias data/mc [nobs/(bkg/pot)/pot] vs sqrt(s)
  Double_t BkgBiasErrP1;              // estimated error on par1 of the pol1 used to fit in sideband the bias data/mc [nobs/(bkg/pot)/pot] vs sqrt(s)
  Double_t BkgBiasErrP0P1Corr;        // estimated correlation on the errors of par0 and par1 of the pol1 used to fit in sideband the bias data/mc [nobs/(bkg/pot)/pot] vs sqrt(s)
  Double_t EffiOverBkgErrP0[3];       // estimated error on par0 of the pol1 used to fit in sideband the ratio effisig/(bkg/pot) vs sqrt(s): 2 periods of the scan [period 1, 2, total]
  Double_t EffiOverBkgErrP1[3];       // estimated error on par1 of the pol1 used to fit in sideband the ratio effisig/(bkg/pot) vs sqrt(s): 2 periods of the scan [period 1, 2, total]
  Double_t EffiOverBkgErrP0P1Corr[3]; // estimated correlation on the errors of par0 and par1 of the pol1 used to fit in sideband the ratio effisig/(bkg/pot) vs sqrt(s): 3 periods of the scan [period 1, 2, total]
  Double_t BkgPerPOTVsSqrtsParErr[2]; // pol1 fit of B/POT vs sqrt(s): parameter errors
  Double_t BkgPerPOTVsSqrtsP0P1Corr;  // pol1 fit of B/POT vs sqrt(s): parameter P0P1 correlation
  //  vector<Double_t> SqrtsErr;      // error on the sqrts per point
};

struct nuisancePars{
  bool isNotFilled = true; // true if struct is not filled
  vector<Double_t> POTTrue;         // true POT per point in 1E10 units 
  vector<Double_t> SignalEffiLocalTrue;  // true value of the ratio of signal/background efficiency per point (relative correction to the signal counts)
  Double_t POTScaleTrue;         // true value of the POT scale
  vector<Double_t> BkgTrue ;     // true value of the background counts/POT
  Double_t SignalPeakYieldTrue;  // true value of the yield on resonance
  Double_t SignalLorentzianWidthTrue;    // true Lorentzian width for the signal shape
  Double_t BESTrue;              // true value of the BES
  Double_t BkgBiasTrueP0;              // true value of par0 of the pol1 used to fit in sideband the bias data/mc [nobs/(bkg/pot)/pot] vs sqrt(s)
  Double_t BkgBiasTrueP1;              // true value of par1 of the pol1 used to fit in sideband the bias data/mc [nobs/(bkg/pot)/pot] vs sqrt(s)
  Double_t EffiOverBkgTrueP0[3];       // true value of par0 of the pol1 used to fit in sideband the ratio effisig/(bkg/pot) vs sqrt(s): 2 periods of the scan [period 1, 2, total]
  Double_t EffiOverBkgTrueP1[3];       // true value of par1 of the pol1 used to fit in sideband the ratio effisig/(bkg/pot) vs sqrt(s): 2 periods of the scan [period 1, 2, total]
  Double_t BkgPerPOTVsSqrtsParTrue[2];  // pol1 fit of B/POT vs sqrt(s): parameter values
  //  vector<Double_t> SqrtsTrue;       // true sqrts per point
};

class Likelihood {
 public:
  // observables 
  observables fObservables; // temporary value
  expectedErrors fExpectedErrors;
  const double log2pi = 1.8378771;
  const double me = 0.511; // MeV
  const double Wb = -7E-6; // MeV
  //  const double k = 3.52; // 3.52 gives 1400 events totally emitted for gve = 1E-3, using BES = 0.5%, see Fig. 1 left of 2403.15387 
  void SetObservables(observables Obs){fObservables = Obs;}
  void SetExpectedErrors(expectedErrors Errs){fExpectedErrors = Errs;}

  static Double_t SignalShape(double signalpeak,double bes,double lorewidth,double massn, double sqrts){ // return number of signal events produced(not the accepted) / POT at sqrts(s) at gven = 1
    const double me = 0.511;// MeV
    const double Wb = -7E-6;// MeV
    double eRes = (massn*massn - 2*me*me)/(2.*(me+Wb));
    double eBeam = (sqrts*sqrts - 2*me*me)/(2.*me); // s = 2me^2 + 2meEbeam -> eBeam = (s-2me^2) / 2me
    return signalpeak*TMath::Voigt(eBeam-eRes,bes*eRes,lorewidth*2,5); // last input was 4 but with low BES can have rounding problems
  }

  Likelihood(){}
  
  Likelihood(observables Obs, expectedErrors Errs) :
    fObservables(Obs), fExpectedErrors(Errs) {}
  // input: nominal sqrts, Nobs,  
   double operator()(const double *par) {
     int npts = fObservables.NObs.size();

     // fit parameters are the signal mass and coupling and the nuisances 
     // par0 = 0 <-- signal+background fit; = 1 <-- background only fit
     // par1 = mass
     // par2 = coupling
     // par{3,       3+npts-1} = POTTrue in 1E10 units <-- remain a fit parameter only for the S+B fit when not using the Effi/Bkg curve 
     // par{3+npts,3+2npts-1} = SignalEffiLocalTrue
     // par[3+2npts] = SignalPeakYieldTrue
     // par[4+2npts] = SignalLorentzianWidthTrue
     // par[5+2npts] = BESTrueTrue
     // par[6+2npts] = POTScaleTrue
     // par{7+2npts,7+3npts-1} = BkgTrue/POT <-- when fitting B-only OR if using the Effi/Bkg curve, this becomes Bkg times POT!
     // par[7+3*npts] = CorrectBkgBias
     // par[8+3*npts] = BkgBiasTrueP0
     // par[9+3*npts] = BkgBiasTrueP1
     // par[10+3*npts]= AssumeEffiOverBkgCurve [0: no; 1: yes but with two separate scan periods; 2: yes with all the scan treated as a whole
     // par[11+3*npts]= EffiOverBkgTrueP0_0 <-- constant term, first period of the scan
     // par[12+3*npts]= EffiOverBkgTrueP1_0 <-- slope, first period of the scan
     // par[13+3*npts]= EffiOverBkgTrueP0_1 <-- constant term, second period of the scan
     // par[14+3*npts]= EffiOverBkgTrueP1_1 <-- slope, second period of the scan
     // par[15+3*npts]= EffiOverBkgTrueP0_2 <-- constant term, total scan
     // par[16+3*npts]= EffiOverBkgTrueP1_2 <-- slope, total scan
     // par[17+3*npts]= StraightFitMode     <-- always fixed. If 1: fit N2/(POT x B) and keep POT,B as observables; if 2: fit N2(POT x B) and keep POT,B as nuisances 
     // par[18+3*npts]= BkgFitMode          <---if set to 1, will use a pol1 fit for B/POT vs sqrt(s)
     // par[19+3*npts]= BkgFitP0            <---parameter 0 of a pol1 fit for B/POT vs sqrt(s)
     // par[20+3*npts]= BkgFitP1            <---parameter 1 of a pol1 fit for B/POT vs sqrt(s)
     bool isSBfit = (par[0]==0);
     double mass = par[1];
     double gve  = par[2];
     double signalPeakYieldTrue = par[3+2*npts];
     double signalLorentzianWidthTrue  = par[4+2*npts];
     double BESTrue   = par[5+2*npts];
     double potScaleTrue = par[6+2*npts];
     int potTrueIdx = 3;
     int effiTrueIdx = 3 + npts;
     int bkgTrueIdx = 7 + 2*npts;
     bool useBkgBias = par[7+3*npts];
     double bkgBiasTrueP0 = par[8+3*npts];
     double bkgBiasTrueP1 = par[9+3*npts];
     int assumeEffiOverBkgCurve = par[10+3*npts];
     double effiOverBkgTrueP0[3] = {par[11+3*npts],par[13+3*npts],par[15+3*npts]};
     double effiOverBkgTrueP1[3] = {par[12+3*npts],par[14+3*npts],par[16+3*npts]};
     int straightFitMode = par[17+3*npts];
//     int bkgFitMode = par[18+3*npts];
//     double bkgFitP0 = par[19+3*npts];
//     double bkgFitP1 = par[20+3*npts];

     //calculate -2log(likelihood)

     Double_t chisq = 0;
     Double_t delta = 0;

     // BIAS CORRECTION FOR THE POT (aka POTSCALE)
     if (useBkgBias){ 
       double oneMinusRho2 = (1.-fExpectedErrors.BkgBiasErrP0P1Corr*fExpectedErrors.BkgBiasErrP0P1Corr);
       delta =
	 pow((fObservables.BkgBiasObsP0 - bkgBiasTrueP0)/fExpectedErrors.BkgBiasErrP0,2)/oneMinusRho2 +  
	 pow((fObservables.BkgBiasObsP1 - bkgBiasTrueP1)/fExpectedErrors.BkgBiasErrP1,2)/oneMinusRho2 
	 -2*(fObservables.BkgBiasObsP0 - bkgBiasTrueP0)*(fObservables.BkgBiasObsP1 - bkgBiasTrueP1)*fExpectedErrors.BkgBiasErrP0P1Corr/(fExpectedErrors.BkgBiasErrP0*fExpectedErrors.BkgBiasErrP1*oneMinusRho2);
       chisq += delta;// + 2.*TMath::Log(fExpectedErrors.BkgBiasErrP0*fExpectedErrors.BkgBiasErrP1*TMath::Sqrt(oneMinusRho2)) + 2*log2pi;
     } else {
       delta = (fObservables.POTScaleObs - potScaleTrue)/(fExpectedErrors.POTScaleErr); // absolute scale of the POT
       chisq += delta*delta;// + 2.*TMath::Log(fExpectedErrors.POTScaleErr) + log2pi;
     }

     if (isSBfit){ // signal + background fit

       // signal shape nuisances
       delta = (fObservables.SignalPeakYieldObs - signalPeakYieldTrue)/(fExpectedErrors.SignalPeakYieldErr); // error on peak yield
       chisq += delta*delta;// + 2.*TMath::Log(fExpectedErrors.SignalPeakYieldErr) + log2pi;

       delta = (fObservables.SignalLorentzianWidthObs - signalLorentzianWidthTrue)/(fExpectedErrors.SignalLorentzianWidthErr); // error on lorentzian width
       chisq += delta*delta;// + 2.*TMath::Log(fExpectedErrors.SignalLorentzianWidthErr) + log2pi;

       delta = (fObservables.BESObs - BESTrue)/(fExpectedErrors.BESErr); // error on relative BES
       chisq += delta*delta;// + 2.*TMath::Log(fExpectedErrors.BESErr) + log2pi;

       // if using effi/bkg curve, include the errors on the parameters in the likelihood 
       if (assumeEffiOverBkgCurve){ // parameterisation of the effi/(bkg/pot) vs sqrt(s) with two scan periods
	 int kmin = 2;
	 int kmax = 3;
	 if (assumeEffiOverBkgCurve==1) {
	   kmin = 0;
	   kmax = 2;
	 }
	 for (int k=kmin; k<kmax; k++){ 
	   double oneMinusRho2 = (1.-fExpectedErrors.EffiOverBkgErrP0P1Corr[k]*fExpectedErrors.EffiOverBkgErrP0P1Corr[k]);
	   delta =
	     pow((fObservables.EffiOverBkgObsP0[k] - effiOverBkgTrueP0[k])/fExpectedErrors.EffiOverBkgErrP0[k],2)/oneMinusRho2 +  
	     pow((fObservables.EffiOverBkgObsP1[k] - effiOverBkgTrueP1[k])/fExpectedErrors.EffiOverBkgErrP1[k],2)/oneMinusRho2 
	     -2*(fObservables.EffiOverBkgObsP0[k] - effiOverBkgTrueP0[k])*(fObservables.EffiOverBkgObsP1[k] - effiOverBkgTrueP1[k])*
	     fExpectedErrors.EffiOverBkgErrP0P1Corr[k]/(fExpectedErrors.EffiOverBkgErrP0[k]*fExpectedErrors.EffiOverBkgErrP1[k]*oneMinusRho2);
	   chisq += delta;// + 2.*TMath::Log(fExpectedErrors.EffiOverBkgErrP0[k]*fExpectedErrors.EffiOverBkgErrP1[k]*TMath::Sqrt(oneMinusRho2)) + 2*log2pi;
	 }
       } // else -> will use errors on the single-point efficiencies
     }

     //     std::cout << "chisq step 1a is " << chisq << endl;

     if (straightFitMode == 1){ // do not fit B, POT but only use N2/(B POT). ALWAYS Assume effi/b as a linear function of sqrt(s)

       for (uint i=0; i < npts; i++) {        
	 delta = (fObservables.NObs.at(i)/(fObservables.BkgObs.at(i)*1E10)); // N2/((POT B)x1E10) 

	 double relerrsq = 
	   (fExpectedErrors.BkgErr.at(i)/fObservables.BkgObs.at(i))*(fExpectedErrors.BkgErr.at(i)/fObservables.BkgObs.at(i)) +
	   (1./fObservables.NObs.at(i));

	 // bias on the POT
	 double expval = 0;
	 if (useBkgBias) expval = (bkgBiasTrueP0 + bkgBiasTrueP1*(fObservables.SqrtsObs.at(i)-SQRTSMID));  // (BiasP0 + BiasP1*(sqrt(s)-16.92))
	 else            expval = potScaleTrue;                                                            // POT_scale_true

	 // expected number of signal events (0 if background-only fit)
	 double sc = 0;
	 if (isSBfit) {
	   int iperiod = 2;
	   if (assumeEffiOverBkgCurve == 1) iperiod = fObservables.ScanPeriod.at(i); //0 or 1
	   sc = gve*gve*Likelihood::SignalShape(signalPeakYieldTrue,BESTrue,signalLorentzianWidthTrue,mass,fObservables.SqrtsObs.at(i))*
	     (effiOverBkgTrueP0[iperiod] + effiOverBkgTrueP1[iperiod]*(fObservables.SqrtsObs.at(i)-SQRTSMID)); // effi/B = (linear func)
	 }

	 expval *= (1.+sc);
	 chisq += (delta-expval)*(delta-expval)/(delta*delta*relerrsq);
       }

       //       if (!isSBfit) cout << " and at the end " << chisq << endl;

     } else if (straightFitMode == 2){ // Fit N2/(B POT) but use BxPOT as nuisances

       for (uint i=0; i < npts; i++) {        

       // bkg/pot per point nuisances
	 delta = (fObservables.BkgObs.at(i) - par[bkgTrueIdx + i])/fExpectedErrors.BkgErr.at(i); // true values of bkg x pot vs sqrt(s)
	 chisq += delta*delta;// + 2.*TMath::Log(fExpectedErrors.BkgErr.at(i)) + log2pi;

	 // bias on the POT
	 double expval = 0;
	 if (useBkgBias) expval = (bkgBiasTrueP0 + bkgBiasTrueP1*(fObservables.SqrtsObs.at(i)-SQRTSMID));  // (BiasP0 + BiasP1*(sqrt(s)-16.92))
	 else            expval = potScaleTrue;                                                            // POT_scale_true
	 
	 // expected number of signal events (0 if background-only fit)
	 double sc = 0;
	 if (isSBfit) {
	   int iperiod = 2;
	   if (assumeEffiOverBkgCurve == 1) iperiod = fObservables.ScanPeriod.at(i); //0 or 1
	   sc = gve*gve*Likelihood::SignalShape(signalPeakYieldTrue,BESTrue,signalLorentzianWidthTrue,mass,fObservables.SqrtsObs.at(i))*
	     (effiOverBkgTrueP0[iperiod] + effiOverBkgTrueP1[iperiod]*(fObservables.SqrtsObs.at(i)-SQRTSMID)); // effi/B = (linear func)
	 }

	 expval *= (1.+sc);

	 // statistical term
	 double bc = par[bkgTrueIdx + i]*1E10; // (Nbkg/POT)true x POT_i_true
	 delta = (fObservables.NObs.at(i)/bc - expval)/(TMath::Sqrt(fObservables.NObs.at(i))/bc);
	 chisq += delta*delta;// + 2.*TMath::Log(errcount) + log2pi;	 
       }
     } else { // standard fit mode: N2  = F(s) POT x (B + epsilon S ) or F(s) POT B (1 + G(s) S)

       for (uint i=0; i < npts; i++) {        
	 double bc = par[bkgTrueIdx + i]*1E10;

	 delta = (fObservables.BkgObs.at(i) - par[bkgTrueIdx + i])/fExpectedErrors.BkgErr.at(i); // true values of bkg/pot vs sqrt(s)
	 chisq += delta*delta;// + 2.*TMath::Log(fExpectedErrors.BkgErr.at(i)) + log2pi;

	 if (!assumeEffiOverBkgCurve){
	   // expected number of bkg events       
	   bc *= par[potTrueIdx + i]; // (Nbkg/POT)true x POT_i_true

	   // local error on the pot
	   double errpotloc = fExpectedErrors.POTLocalErr.at(i);
	   delta = (fObservables.POTObs.at(i) - par[potTrueIdx + i])/errpotloc; // true values of the POT per point
	   chisq += delta*delta;// + 2.*TMath::Log(errpotloc) + log2pi;
	 }

	 if (useBkgBias) bc *= (bkgBiasTrueP0 + bkgBiasTrueP1*(fObservables.SqrtsObs.at(i)-SQRTSMID));  // (Nbkg/POT)true x POT_i_true x (BiasP0 + BiasP1*(sqrt(s)-16.92))
	 else            bc *= potScaleTrue;                                                         // (Nbkg/POT)true x POT_i_true x POT_scale_true

	 // expected number of signal events
	 double sc = 0;
	 if (isSBfit) {

	   sc = 1E10*gve*gve*Likelihood::SignalShape(signalPeakYieldTrue,BESTrue,signalLorentzianWidthTrue,mass,fObservables.SqrtsObs.at(i));
	   if (useBkgBias) sc *= (bkgBiasTrueP0 + bkgBiasTrueP1*(fObservables.SqrtsObs.at(i)-SQRTSMID));  // (BiasP0 + BiasP1*(sqrt(s)-16.92))
	   else            sc *= potScaleTrue;                                                         // POT_scale_true

	   if (assumeEffiOverBkgCurve){
	     int iperiod = 2;
	     if (assumeEffiOverBkgCurve == 1) iperiod = fObservables.ScanPeriod.at(i); //0 or 1

	     sc *= par[bkgTrueIdx + i]*(effiOverBkgTrueP0[iperiod] + effiOverBkgTrueP1[iperiod]*(fObservables.SqrtsObs.at(i)-SQRTSMID)); // effi = (bkg/pot)*(linear func)
	   } else {
	     sc *= par[potTrueIdx+i]*par[bkgTrueIdx + i]*par[effiTrueIdx+i]; // effi
	     delta = (fObservables.SignalEffiLocalObs.at(i)-par[effiTrueIdx + i])/fExpectedErrors.SignalEffiLocalErr.at(i); 
	     chisq += delta*delta;// + 2.*TMath::Log(fExpectedErrors.SignalEffiLocalErr.at(i)) + log2pi; // chi^2 from effi_i
	   }
	 
	   //PROVA	 sc = signalPeakYieldTrue*gve*gve*par[potTrueIdx + i]*1E10*potScaleTrue*par[effiTrueIdx + i]*TMath::Voigt(eBeam-eRes,BESTrue*eBeam,signalLorentzianWidthTrue*2,4);
	   //	 std::cout << "mass = " << mass << " gve = " << gve << " eRes = " << eRes << " eBeam = " << eBeam << " signal = " << sc << endl;

	   //	 if (i==23 || i==46) std::cout << "chisq step 2 i = " << i << " is " << chisq << endl;
	 
	 } 

	 // statistical term
	 double errcount = TMath::Sqrt(sc+bc);
	 delta = (fObservables.NObs.at(i) - sc - bc)/errcount;
	 chisq += delta*delta;// + 2.*TMath::Log(errcount) + log2pi;	 
       }
     } // standard fit mode: N2  = F(s) POT x (B + epsilon S ) or F(s) POT B (1 + G(s) S)
     //     std::cout << "chisq step 3 is " << chisq << endl;
     //     if (!isSBfit) cout << endl;
     return chisq;
   } // operator ()
}; // Likelihood class



class statisticalTreatmentTH{
  
public:
  statisticalTreatmentTH();
  ~statisticalTreatmentTH();

  void SetVerbosity(int verbosity){fVerbosity = verbosity;}

  void Init();
  void InitFromFile(TString filename, bool useNuisance){InitFromFile(filename,1.,useNuisance);} // set filename with init info, no modified improvement factor, useNuisance flag
  void InitFromFile(TString filename, Double_t errorImprovementFactor, bool useNuisance); // set filename with init info, improvementFactor, useNuisance flag

  void ReadOutput(TString filename);       // set filename with input CLs info -> perform limits
  void SaveAllHistos();
  
  void OverrideRandomSeed(int seed){fSeed = seed; fRndmNumber->SetSeed(seed);}
  void InitParallelization(int parallelLevel, int parallelID){fParallelLevel = parallelLevel; fParallelID = parallelID;}// number of parallel instances, instanceID
  
  // to be run only AFTER INIT:
  void EvaluateExpectedLimit();//Bool_t toyOfToy, Bool_t bOnlyFile, Double_t wantedMass, Double_t wantedGve, TString filename);// if toyOfToy == false -> nobs from filename. if bOnlyFile == false -> use SBfile 
  void EvaluateExpectedLimitFreqOnly(); // Only do the frequentist method and fill the frequentist tree

  void SimulateBkgPseudoDataToFile(TString filename); // can generate and write to a file pseudodata background-only distributions
  void SimulateSignalPlusBkgPseudoDataToFile(TString filename); // can generate and write to a file pseudodata signal + bkg distributions scanning over the mass,gve grid

  // parameters for the nuisance-par distributions can be modified externally via the following, overriding the initalised values:
  void SetPOTErrors(double rGlobal, vector<double> rLocal) {
    fExpectedErrors.POTScaleErr = rGlobal;
    fExpectedErrors.POTLocalErr = rLocal;
  }
  void SetEfficiencyErrors(vector<double> rLocal) { fExpectedErrors.SignalEffiLocalErr = rLocal; } 
  void SetSignalShapeErrors(double errPeakYield, double errLorentzianWidth){
    fExpectedErrors.SignalPeakYieldErr = errPeakYield;
    fExpectedErrors.SignalLorentzianWidthErr = errLorentzianWidth;
  }
  void SetBESError(double beserr) {fExpectedErrors.BESErr = beserr;}
  void SetBKGParErrors(vector<Double_t> bkgerr){ fExpectedErrors.BkgErr = bkgerr; }

  // The NObs distribution can be overridden via SetNObs:
  void SetNObs(vector<Double_t> val){fObservables.NObs.clear(); fObservables.NObs = val; fObservables.isNotFilled = false;} 
  // The NObs distribution can be readout from an external file:
  void SetObservablesFromFile(TString filename, Int_t count); // read instance #count from the file of observables graphs
  void SetObservablesFromSBFile(TString filename, Double_t mass, Double_t gve, Int_t count); // read instance #count from the file of observable graphs, retrieve the mass,gve point closest to the wanted
  
// definition of the mass-epsilon grid with public methods
  void OverrideMassGrid(double mmin, double mmax, int nmsteps){fNMassBins = nmsteps; fMassMin = mmin; fMassMax = mmax;}
  //  void SetEpsilonGrid(double emin, double emax, int nesteps, int optionLog); //if optionLog = 1 make log steps
  
private:  
  Bool_t fIsInitialized;
  nuisancePars InitNuisanceToObservables(observables obs); // init Starting values of the nuisances to the observables
  void initHistograms();
  void initFitters(bool bonly); // pass 1 for b-only fit, 0 otherwise; the value of fUseNuisance set to 0 will fix all the parameters
  void GenerateBackgroundPseudoData(nuisancePars nuis); // generate observables under B hypothesis using input nuisance Nuis, modifies fObservables
  void GenerateSignalPlusBackgroundPseudoData(double massn, double gven, nuisancePars nuis); // generate observables under S+B hypothesis using input nuisance Nuis, modifies fObservables

  void GenerateBackground(nuisancePars nuis); // generate observables under B hypothesis using input nuisance Nuis, modifies fObservables
  void GenerateSignalPlusBackground(double mass, double gve, nuisancePars nuis); // generate observable under S+B hypothesis using input nuisance Nuis, modifies fObservables

  nuisancePars MaximizeLSBGivenNObs(double mass, double gve, double* lsb); // given M,eps maximize Lsb wrt nuisance pars, return "profiled" nuisance pars
  nuisancePars MaximizeLBGivenNObs(double* lb); //  maximize Lb wrt store nuisance pars, return "profiled" nuisance pars q_s
  double EvaluateLSBGivenNObs(double mass, double gve, nuisancePars nuis, bool* okfit); // given M,eps evaluate Lsb with frozen nuisance pars
  double EvaluateLBGivenNObs(nuisancePars nuis, bool* okfit); // evaluate Lb with frozen nuisance pars

private:
  statConfig* fConfigPtr;
  CLsinfo fCLsInfo;   // Cls evaluations
  Freqinfo fFreqInfo; // rolke and feldman evaluations
  TTree* fCLsTree;
  TTree* fFreqTree;
  Double_t fErrorImprove;
  Bool_t fUseNuisance;
  TString fInputFileName;
  // manipulated input graphs
  TGraphErrors* fPotGraphUsed;
  TGraphErrors* fEffiGraphUsed;
  TGraphErrors* fBkgGraphUsed;
  TGraphErrors* fNormBkgGraphUsed;
  
  // obs histograms on pseudo-data
  TH1D* fLBHisto; // LB   for each pseudo-data event
  vector<TH2D*> fLSBHisto; // LSB vs gven for each pseudo-data event at a given mass
  vector<TH2D*> fQobsHisto; // Qobs vs gven for each pseudo-data event at a given mass
  TH2D* fQobsAvgHisto; // average Qobs vs {mass,gven} 

  // histograms for each pseudo data and each toy generated
  TH1D* fLB_BtoyHisto; // LB for each pseudo-data event and for each generated B-only toy event

  vector<TH2D*> fLSB_BtoyHisto; // LSB vs gven for each pseudo-data event and for each generated B-only toy event 
  vector<TH2D*> fQbRelHisto;     // Qb-Qobs vs gven for each pseudo-data event and for each generated B-only toy event 

  vector<TH2D*> fLB_SBtoyHisto; // LB vs gven for each pseudo-data event and for each generated SB toy event 
  vector<TH2D*> fLSB_SBtoyHisto; // LSB vs gven for each pseudo-data event and for each generated SB toy event 
  vector<TH2D*> fQsRelHisto;     // Qs-Qobs vs gven for each pseudo-data event and for each generated SB toy event 


  // observables  
  observables fObservables;
  observables fObservablesInit; // value at the init time 

  // expected errors
  expectedErrors fExpectedErrors;

  // inverse transpose of the matrix to generate correlated parameters for the bkgBiasCurve
  double fInvCholeTransBkgBias[2][2];

  // inverse transpose of the matrix to generate correlated parameters for the effi/(bkg/pot) curve (one curve for each scan period)
  double fInvCholeTransEffiOverBkgScan1st[2][2];
  double fInvCholeTransEffiOverBkgScan2nd[2][2];
  double fInvCholeTransEffiOverBkgScanAll[2][2];
  
  // profiled nuisance pars
  nuisancePars fTheta_S; // profiled nuisance pars from the minimum of Lsb given the observed data
  nuisancePars fTheta_B; // profiled nuisance pars from the minimum of Lb  given the observed data 

  // parallelization level and instance

  int fParallelLevel;
  int fParallelID;
  
  // parameters of the toy generations

  Int_t fNumberOfGenerations;
  Int_t fNumberOfGenerationsExpectedLimit;
  
  // parameters of the band generation
  
  Int_t fNCLBands; //number of bands to be evaluated
  Double_t* fCLBand;
  Int_t fNCLAvgs;  //number of cls evaluated at inputCL confidence level (median + left-right for each band) 
  TString fLabel;
  Double_t* fExtractedCLS;

  // random numbers engine
  TRandom3* fRndmNumber;
  int fSeed;
  
  // verbosity
  Int_t fVerbosity;

  // likelihood object
  Likelihood fLikeli;
  // fitter objects
  ROOT::Fit::Fitter fFitterSB;
  ROOT::Fit::Fitter fFitterB;
  
  // grid parameters
  int fNMassBins;
  double fMassMin;
  double fMassMax;
  double fMassStep;
  int fNgveBins;
  double fgveMin;
  double fgveMax;
  double fgveStep;

  // evaluation using frequentist methods
  int fFrequentistNPoints;
  void EvaluateFrequentist(double, double*, double*); // rolkelopez[2] and feldmancousins[2] results for 90% and 95% CL
};

#endif

