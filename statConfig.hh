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

  // Gene mode
  
  Int_t GetGeneMode(){return fGeneMode;}
  TString GetGeneOutputFileName(){return fGeneOutputFileName;}

  // Read mode
  
  Bool_t GetReadMode(){return fReadMode;}

  // Obs-Limit mode

  Bool_t GetObsLimitMode(){return fObsLimitMode;}
  
  // Standard mode [if no readmode and no genemode and no obslimitmode]

  Bool_t GetToyOfToyMode(){return fToyOfToyMode;} // if true -> generate background pseudo data while making the expected limit

  // if ToyOfToyMode == kFALSE:
  TString GetInputFileNameNObsFromFile(){return fInputFileNameNObsFromFile;} // filename where the input NObs must be retrieved
  Bool_t GetBkgOnlyPseudoEvents(){return fBkgOnlyPseudoEvents;}// use the bkg-only NObs from the input file
  Double_t GetWantedMassPseudoEvents(){return fWantedMassPseudoEvents;} // mass to be used to retrieve S+B NObs from input file [ONLY IF BkgOnlyPseudoEvents = kFALSE]
  Double_t GetWantedGvePseudoEvents(){return fWantedGvePseudoEvents;}   // gve  to be used to retrieve S+B NObs from input file [ONLY IF BkgOnlyPseudoEvents = kFALSE]
  Int_t    GetFirstEventNObsFromFile(){return fFirstEventNObsFromFile;} // first event to be used when retrieving NObs from input file [ONLY IF BkgOnlyPseudoEvents = kFALSE]
  
  // Other settings
  Int_t GetNumberOfGenerations(){return fNumberOfGenerations;} // number of toys
  Int_t GetNumberOfGenerationsExpectedLimit(){return fNumberOfGenerationsExpectedLimit;} // number of pseudo data events

  Bool_t GetUseNuisance(){return fUseNuisance;} // by default true = use nuisances
  Bool_t GetCorrectBkgBias(){return fCorrectBkgBias;} // by default false = do not correct bkg bias
  Int_t GetAssumeBkgOverPotCurve(){return fAssumeBkgOverPotCurve;} // by default false
  Int_t  GetAssumeEffiOverBkgCurve(){return fAssumeEffiOverBkgCurve;} // by default false = do not assume sqrt(s) dependence of effi/(bkg/pot)
  Int_t GetStraightFitMode(){return fStraightFitMode;} // by default false. If true -> greatly reduce number of nuisances fitting N2/POT/B with functions of sqrt(s)
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

  // P0,P1 parameters of the Nobs/(bkg/pot)/pot vs sqrt(s) shape
  Double_t GetBkgBiasObsP0(){return fBkgBiasObsP0;}
  Double_t GetBkgBiasObsP1(){return fBkgBiasObsP1;}
  Double_t GetBkgBiasErrP0(){return fBkgBiasErrP0;}
  Double_t GetBkgBiasErrP1(){return fBkgBiasErrP1;}
  Double_t GetBkgBiasErrP0P1Corr(){return fBkgBiasErrP0P1Corr;}

  Bool_t GetUsePOTSlopeCorrection(){return fUsePOTSlopeCorrection;}
  Double_t GetPOTSlopeCorrectionObs(){return fPOTSlopeCorrectionObs;}
  Double_t GetPOTSlopeCorrectionErr(){return fPOTSlopeCorrectionErr;}
private:
  statConfig();
  ~statConfig();
  static statConfig* fInstance;
  
  std::vector<std::pair<const char*, stringFieldFlag>> fFieldStrings;
  int useInputString(TString);

  // gene mode
  Int_t fGeneMode; // if 1 -> generate toys-of-toys distributions
  TString fGeneOutputFileName; // name of gene-MC output file
  // read mode
  Bool_t fReadMode;
  // obs-limit mode
  Bool_t fObsLimitMode;
  
  // standard setup
  Bool_t fToyOfToyMode;               // if true -> generate pseudo events while making the expected limit
  Bool_t fBkgOnlyPseudoEvents;        // if true -> generate/retrieve background-only pseudoevents
  Double_t fWantedMassPseudoEvents;   // if fBkgOnlyPseudoEvents = false: mass to be used for S+B pseudoevents
  Double_t fWantedGvePseudoEvents;    // if fBkgOnlyPseudoEvents = false: gve  to be used for S+B pseudoevents
  TString fInputFileNameNObsFromFile; // if ToyOfToyMode == kFALSE: filename where the input pseudoevents must be retrieved
  Int_t fFirstEventNObsFromFile;      // if ToyOfToyMode == kFALSE: first event to be read from the input file
  
  // other settings
  Int_t fNumberOfGenerations; // number of toys
  Int_t fNumberOfGenerationsExpectedLimit; // number of pseudo data 

  Bool_t fUseNuisance; // by default use nuisance
  Bool_t fCorrectBkgBias; // by default do not correct it
  Int_t fAssumeBkgOverPotCurve; // by default do not use it
  Int_t fAssumeEffiOverBkgCurve; // by default do not assume it
  Int_t fStraightFitMode; // by default do not use it (0). If set to 1: simple likelihood without B,POT nuisance. If set to 2: likelihood of ratiofit + B,POT nuisances
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

  Double_t fPOTScale;
  Double_t fPOTScaleErr; 

  // other external nuisance pars. In case of bias on obs events (due to bkg) assumed to vary linear with sqrt(s), here the constant and slope parameters might enter

  Double_t fBkgBiasObsP0;
  Double_t fBkgBiasObsP1;
  Double_t fBkgBiasErrP0;
  Double_t fBkgBiasErrP1;
  Double_t fBkgBiasErrP0P1Corr;

  Bool_t  fUsePOTSlopeCorrection;
  Double_t fPOTSlopeCorrectionObs;
  Double_t fPOTSlopeCorrectionErr;

  
};
#endif
