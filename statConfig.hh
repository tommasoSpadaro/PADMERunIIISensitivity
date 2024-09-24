#ifndef STATCONFIG_HH
#define STATCONFIG_HH

#include <stdlib.h>
#include <iostream>
#include "TString.h"

enum stringFieldFlag{
  kIntegerField  = 0,
  kDoubleField  = 1,
  kBooleanField = 2,
  kStringField = 3
};


class statConfig{
public:
  static statConfig* GetInstance();  
  void readConfigFromFile(TString datacardName);


  Int_t GetNumberOfGenerations(){return fNumberOfGenerations;} // number of toys
  Int_t GetNumberOfGenerationsExpectedLimit(){return fNumberOfGenerationsExpectedLimit;} // number of pseudo data 

  Bool_t GetUseNuisance(){return fUseNuisance;} // by default true = use nuisances
  Bool_t GetEvaluateExpLimit(){return fEvaluateExpLimit;}
  Int_t GetSeed(){return fSeed;}
  Int_t GetVerbosity(){return fVerbosity;}

  // mass bins
  Double_t GetMassStep(){return fMassStep;} // MeV
  Double_t GetMassMin(){return fMassMin;}   // MeV
  Double_t GetMassMax(){return fMassMax;}   // MeV

  // coupling bins
  Int_t GetNgveBins(){return fNgveBins;}
  Double_t GetgveMin(){return fgveMin;}
  Double_t GetgveMax(){return fgveMax;}

  // number of points of the scan used in the frequentist window  
  Int_t GetFrequentistNPoints(){return fFrequentistNPoints;} // n pts for integration for frequentist methods (FC, RL)  

  // input MC information
  TString GetInputFileName(){return fInputFileName;} // path relative to the executable or absolute path
  Bool_t GetManipulateInput(){return fManipulateInput;} // if true -> apply modification to the input errors
  Double_t GetErrorImprove(){return fErrorImprove;} // factor used to decrease the relative errors on the input

  // input parameters for signal shape
  Double_t GetSignalPeakYield(){return fSignalPeakYield;}         // peak yield ~ 2.26 x gve^2 if BES = 0.0022
  Double_t GetSignalPeakYieldErr(){return fSignalPeakYieldErr;}   // relative error ~ 1.4%
  Double_t GetSignalLorentzianWidth(){return fSignalLorentzianWidth;}       // MeV
  Double_t GetSignalLorentzianWidthErr(){return fSignalLorentzianWidthErr;} // MeV
  Double_t GetBES(){return fBES;}       // relative spread
  Double_t GetBESErr(){return fBESErr;} // error on the relative spread

  // other external nuisance pars. In case of background-scaled obs events assumed to vary linear with sqrt(s), here the constant and slope parameters might enter
  Double_t GetPOTScale(){return fPOTScale;}
  Double_t GetPOTScaleErr(){return fPOTScaleErr;} 

  
private:
  statConfig();
  ~statConfig();
  static statConfig* fInstance;
  
  std::vector<std::pair<const char*, stringFieldFlag>> fFieldStrings;
  int useInputString(TString);

  
  Int_t fNumberOfGenerations; // number of toys
  Int_t fNumberOfGenerationsExpectedLimit; // number of pseudo data 

  Bool_t fUseNuisance; // by default use nuisance
  Bool_t fEvaluateExpLimit;
  Int_t fSeed;
  Int_t fVerbosity;

  // mass bins
  Double_t fMassStep; // MeV
  Double_t fMassMin ; // MeV
  Double_t fMassMax ; // MeV

  // coupling bins
  Int_t fNgveBins;
  Double_t fgveMin;
  Double_t fgveMax;

  // number of points of the scan used in the frequentist window  
  Int_t fFrequentistNPoints; // number of points for integration for the frequentist methods (FC, RL)  

  // input MC information
  TString fInputFileName ; // path relative to the executable or absolute path
  Bool_t fManipulateInput; // if true -> apply modification to the input errors
  Double_t fErrorImprove ; // factor used to decrease the relative errors on the input

  // input parameters for signal shape
  Double_t fSignalPeakYield;      // peak yield ~ 2.26 x gve^2 if BES = 0.0022
  Double_t fSignalPeakYieldErr;   // relative error ~ 1.4%
  Double_t fSignalLorentzianWidth;    // MeV
  Double_t fSignalLorentzianWidthErr; // MeV
  Double_t fBES; // relative spread
  Double_t fBESErr; // error on the relative spread

  // other external nuisance pars. In case of background-scaled obs events assumed to vary linear with sqrt(s), here the constant and slope parameters might enter
  Double_t fPOTScale;
  Double_t fPOTScaleErr; 

  
};
#endif
