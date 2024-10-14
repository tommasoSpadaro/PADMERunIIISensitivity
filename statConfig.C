#include "statConfig.hh"

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "TObjArray.h"
#include "TObjString.h"

using namespace std;
statConfig* statConfig::fInstance = 0;

statConfig::statConfig(){
  stringFieldFlag sFFI = kIntegerField;
  stringFieldFlag sFFD = kDoubleField;
  stringFieldFlag sFFB = kBooleanField;
  stringFieldFlag sFFS = kStringField;

  // default settings

  // GeneMode settings
  
  fGeneMode = kFALSE; // if true, generate output files with toys of toys
  fFieldStrings.push_back(std::pair{"GeneMode",sFFB});

  fBkgOnlyGeneMode = kFALSE; // if true, generate output files with background-only, otherwise signal+background
  fFieldStrings.push_back(std::pair{"BkgOnlyGeneMode",sFFB});

  fGeneOutputFileName = "output/GeneToyMC.root"; // output filename for gene toy-of-toy MC 
  fFieldStrings.push_back(std::pair{"GeneOutputFileName",sFFS});

  // ReadMode settings
  
  fReadMode = kFALSE; // if true, obtain CLs from the output of a previous run in standard mode
  fFieldStrings.push_back(std::pair{"ReadMode",sFFB});
  
  // ToyOfToy Mode

  fToyOfToyMode = kTRUE;              // if true -> generate background pseudo data while making the expected limit
  fFieldStrings.push_back(std::pair{"ToyOfToyMode",sFFB});

  fInputFileNameNObsFromFile = "output/geneNObsSigPlusBkg.root"; // if ToyOfToyMode == kFALSE: filename where the input NObs must be retrieved
  fFieldStrings.push_back(std::pair{"InputFileNameNObsFromFile",sFFS});

  fBkgOnlyNObsFromFile = kFALSE;      // if ToyOfToyMode == kFALSE: use the bkg-only NObs from the input file
  fFieldStrings.push_back(std::pair{"BkgOnlyNObsFromFile",sFFB});

  fWantedMassNObsFromFile = 0;        // if ToyOfToyMode == kFALSE: mass to be used to retrieve S+B NObs from input file [ONLY IF BkgOnlyNObsFromFile = kFALSE]
  fFieldStrings.push_back(std::pair{"WantedMassNObsFromFile",sFFD});

  fWantedGveNObsFromFile = 0;         // if ToyOfToyMode == kFALSE: gve  to be used to retrieve S+B NObs from input file [ONLY IF BkgOnlyNObsFromFile = kFALSE]
  fFieldStrings.push_back(std::pair{"WantedGveNObsFromFile",sFFD});
  
  // Other settings
  
  fNumberOfGenerations = 200; // number of toys
  fFieldStrings.push_back(std::pair{"NumberOfGenerations",sFFI});
  
  fNumberOfGenerationsExpectedLimit = 1; // number of pseudo data 
  fFieldStrings.push_back(std::pair{"NumberOfGenerationsExpectedLimit",sFFI});

  fUseNuisance = true; // by default use nuisance
  fFieldStrings.push_back(std::pair{"UseNuisance",sFFB});

  fCorrectBkgBias = true; // by default do not correct for bkg bias vs sqrt(s)
  fFieldStrings.push_back(std::pair{"CorrectBkgBias",sFFB});

  fAssumeEffiOverBkgCurve = true; // by default do not assume a curve for effi/(bkg/pot) vs sqrt(s)
  fFieldStrings.push_back(std::pair{"AssumeEffiOverBkgCurve",sFFB});

  fEvaluateExpLimit = true;
  fFieldStrings.push_back(std::pair{"EvaluateExpLimit",sFFB});

  fSeed = 0;
  fFieldStrings.push_back(std::pair{"Seed",sFFI});

  fVerbosity = 0;
  fFieldStrings.push_back(std::pair{"Verbosity",sFFI});

  // mass bins
  fMassStep  = 0.02;   // MeV
  fFieldStrings.push_back(std::pair{"MassStep",sFFD});

  fMassMin   =  16.22; // MeV
  fFieldStrings.push_back(std::pair{"MassMin",sFFD});

  fMassMax   =  17.62; // MeV
  fFieldStrings.push_back(std::pair{"MassMax",sFFD});

  // coupling bins
  fNgveBins =  20;
  fFieldStrings.push_back(std::pair{"NgveBins",sFFI});

  fgveMin   =  1E-4;
  fFieldStrings.push_back(std::pair{"MassMin",sFFD});

  fgveMax   =  4E-4;
  fFieldStrings.push_back(std::pair{"MassMax",sFFD});

  // number of points of the scan used in the frequentist window  
  fFrequentistNPoints = 2; // number of points for integration for the frequentist methods (FC, RL)  
  fFieldStrings.push_back(std::pair{"FrequentistNPoints",sFFI});
  
  // input MC information
  fInputFileName = "input/InputToyMC_MM.root";
  fFieldStrings.push_back(std::pair{"InputFileName",sFFS});
  
  fManipulateInput = false; // if true -> apply modification to the input errors
  fFieldStrings.push_back(std::pair{"ManipulateInput",sFFB});

  fErrorImprove = 1.; // factor used to decrease the relative errors on the input
  fFieldStrings.push_back(std::pair{"ErrorImprove",sFFD});

  // input parameters for signal shape
  fSignalPeakYield = 13.56;      // peak yield ~ 2.26 x gve^2 if BES = 0.0022
  fFieldStrings.push_back(std::pair{"SignalPeakYield",sFFD});

  fSignalPeakYieldErr = 0.18;      // relative error ~ 1.4%
  fFieldStrings.push_back(std::pair{"SignalPeakYieldErr",sFFD});

  fSignalLorentzianWidth = 1.72; // MeV
  fFieldStrings.push_back(std::pair{"SignalLorentzianWidth",sFFD});

  fSignalLorentzianWidthErr = 0.039; // MeV
  fFieldStrings.push_back(std::pair{"SignalLorentzianWidthErr",sFFD});

  fBES = 0.0025; // relative error
  fFieldStrings.push_back(std::pair{"BES",sFFD});

  fBESErr = 0.0005; // error on the relative spread
  fFieldStrings.push_back(std::pair{"BESErr",sFFD});

  fPOTScale = 1.;
  fFieldStrings.push_back(std::pair{"POTScale",sFFD});

  fPOTScaleErr = 0.01; 
  fFieldStrings.push_back(std::pair{"POTScaleErr",sFFD});

  // Constant and slope nuisance pars to correct biases of Nobs via linear fit of Nobs/(background/pot)/pot sqrt(s)

  fBkgBiasObsP0 = 1E-6;
  fFieldStrings.push_back(std::pair{"BkgBiasObsP0",sFFD});

  fBkgBiasObsP1 = 1E-3;
  fFieldStrings.push_back(std::pair{"BkgBiasObsP1",sFFD});

  fBkgBiasErrP0 = 1E-7;
  fFieldStrings.push_back(std::pair{"BkgBiasErrP0",sFFD});

  fBkgBiasErrP1 = 1E-4;
  fFieldStrings.push_back(std::pair{"BkgBiasErrP1",sFFD});

  fBkgBiasErrP0P1Corr = 0;
  fFieldStrings.push_back(std::pair{"BkgErrP0P1Corr",sFFD});

  // Constant and slope nuisance pars of a linear fit of effi/(background/pot) sqrt(s):

  // period 1 of the scan corresponds to index 0: periods < 23

  fEffiOverBkgObsP0[0] = 4.82E-5;
  fFieldStrings.push_back(std::pair{"EffiOverBkgObsP0_0",sFFD});

  fEffiOverBkgObsP1[0] = -2.43E-6; //MeV^-1
  fFieldStrings.push_back(std::pair{"EffiOverBkgObsP1_0",sFFD});

  fEffiOverBkgErrP0[0] = 1.2E-7;
  fFieldStrings.push_back(std::pair{"EffiOverBkgErrP0_0",sFFD});

  fEffiOverBkgErrP1[0] = 3.8E-7; //MeV^-1
  fFieldStrings.push_back(std::pair{"EffiOverBkgErrP1_0",sFFD});

  fEffiOverBkgErrP0P1Corr[0] = -0.06;
  fFieldStrings.push_back(std::pair{"EffiOverBkgErrP0P1Corr_0",sFFD});

  // period 2 of the scan corresponds to index 1: periods >= 23 and not in the below-energy scan part

  fEffiOverBkgObsP0[1] = 4.77E-5;
  fFieldStrings.push_back(std::pair{"EffiOverBkgObsP0_1",sFFD});

  fEffiOverBkgObsP1[1] = -1.40E-6; //MeV^-1
  fFieldStrings.push_back(std::pair{"EffiOverBkgObsP1_1",sFFD});

  fEffiOverBkgErrP0[1] = 1.3E-7;
  fFieldStrings.push_back(std::pair{"EffiOverBkgErrP0_1",sFFD});

  fEffiOverBkgErrP1[1] = 3.8E-7; //MeV^-1
  fFieldStrings.push_back(std::pair{"EffiOverBkgErrP1_1",sFFD});

  fEffiOverBkgErrP0P1Corr[1] = -0.52;
  fFieldStrings.push_back(std::pair{"EffiOverBkgErrP0P1Corr_1",sFFD});

  // the scan as a whole corresponds to index 2: all periods together

  fEffiOverBkgObsP0[2] = 4.799E-5;
  fFieldStrings.push_back(std::pair{"EffiOverBkgObsP0_2",sFFD});

  fEffiOverBkgObsP1[2] = -2.06E-6; //MeV^-1
  fFieldStrings.push_back(std::pair{"EffiOverBkgObsP1_2",sFFD});

  fEffiOverBkgErrP0[2] = 0.86E-7;
  fFieldStrings.push_back(std::pair{"EffiOverBkgErrP0_2",sFFD});

  fEffiOverBkgErrP1[2] = 2.6E-7; //MeV^-1
  fFieldStrings.push_back(std::pair{"EffiOverBkgErrP1_2",sFFD});

  fEffiOverBkgErrP0P1Corr[2] = -0.32;
  fFieldStrings.push_back(std::pair{"EffiOverBkgErrP0P1Corr_2",sFFD});

  
}

statConfig::~statConfig(){
}

// read from config file

void statConfig::readConfigFromFile(TString datacardName){
  std::ifstream inputStream;
  inputStream.open(datacardName.Data());
  if (!inputStream){
    std::cerr << "Cannot open input file ---" << datacardName.Data() << "---" << std::endl;
    exit(2);
  }
  char s[1000];
  while (!inputStream){
    inputStream.getline(s,256);
    TString sStr(s);

    // loop over vector of available fieldstrings

    if (useInputString(sStr) == -1) {
      exit(1);
    }
  }
  inputStream.close();

  if (fGeneMode && fReadMode) {
    std::cerr << "Both GeneMode and ReadMode set: should choose only one of the two" << std::endl;
    exit(3);
  }
  if (fGeneMode) {
    std::cout << "statConfig>> GeneMode ON BkgOnlyGeneMode " << fBkgOnlyGeneMode << " output filename " << fGeneOutputFileName.Data() << std::endl;
  }
  else if (fReadMode) {
    std::cout << "statConfig>> ReadMode ON InputFile " << fInputFileName.Data() << std::endl;
  }
  else {
    std::cout << "Make ToyOfToys? " << fToyOfToyMode << std::endl;
    if (!fToyOfToyMode) {
      std::cout << "Read NObs from input file " << fInputFileNameNObsFromFile.Data() << std::endl;
      if (fBkgOnlyNObsFromFile) {
	std::cout << "Read the background-only NObs" << std::endl;
      } else {
	std::cout << "Read signal+background NObs with wanted mass and couplings = " << fWantedMassNObsFromFile << " , " << fWantedGveNObsFromFile << std::endl;
      }
    }
  }

  return;
}

// use line from input config file to assign values to the permitted fields

int statConfig::useInputString(TString sStr){
  
  // check format of input string
  
  TObjArray *values = sStr.Tokenize(" ");
  if (values->GetEntries() != 2) {
    std::cerr << "Wrong input format: number of fields=" << values->GetEntries() << " string--" << sStr.Data() << "--" << std::endl;
    return -1;
  }
  TString fieldString = ((TObjString *)(values->At(0)))->GetString();

  bool catchInputString = kFALSE;
  for (auto & element : fFieldStrings) {

    // check if string is among those managed
    if (fieldString.EqualTo(element.first)){
      catchInputString = kTRUE;
      
      TString valueString = ((TObjString *)(values->At(1)))->GetString();
      if (element.second == kIntegerField){      
	int inputstrvalI = valueString.Atoi();

	if (fieldString.EqualTo("NumberOfGenerations")) fNumberOfGenerations = inputstrvalI;
	else if (fieldString.EqualTo("NumberOfGenerationsExpectedLimit")) fNumberOfGenerationsExpectedLimit = inputstrvalI;
	else if (fieldString.EqualTo("Seed")) fSeed = inputstrvalI;
	else if (fieldString.EqualTo("Verbosity")) fVerbosity = inputstrvalI;
	else if (fieldString.EqualTo("NgveBins")) fNgveBins = inputstrvalI;
	else if (fieldString.EqualTo("FrequentistNPoints")) fFrequentistNPoints = inputstrvalI;
	else {
	  std::cerr << "Wrong input field string for integer value: " << fieldString.Data() << std::endl;
	  return -1;	  
        }
      }
      else if (element.second == kDoubleField){      
	double inputstrvalD = valueString.Atof();

	if (fieldString.EqualTo("WantedMassNObsFromFile")) fWantedMassNObsFromFile = inputstrvalD;
	else if (fieldString.EqualTo("WantedGveNObsFromFile")) fWantedGveNObsFromFile = inputstrvalD;
	else if (fieldString.EqualTo("MassStep")) fMassStep = inputstrvalD;
	else if (fieldString.EqualTo("MassMin")) fMassMin = inputstrvalD;
	else if (fieldString.EqualTo("MassMax")) fMassMax = inputstrvalD;
	else if (fieldString.EqualTo("gveMin")) fgveMin = inputstrvalD;
	else if (fieldString.EqualTo("gveMax")) fgveMax = inputstrvalD;
	else if (fieldString.EqualTo("ErrorImprove")) fErrorImprove = inputstrvalD;
	else if (fieldString.EqualTo("SignalPeakYield")) fSignalPeakYield = inputstrvalD;
	else if (fieldString.EqualTo("SignalPeakYieldErr")) fSignalPeakYieldErr = inputstrvalD;
	else if (fieldString.EqualTo("SignalLorentzianWidth")) fSignalLorentzianWidth = inputstrvalD;
	else if (fieldString.EqualTo("SignalLorentzianWidthErr")) fSignalLorentzianWidthErr = inputstrvalD;
	else if (fieldString.EqualTo("BES")) fBES = inputstrvalD;
	else if (fieldString.EqualTo("BESErr")) fBESErr = inputstrvalD;
	else if (fieldString.EqualTo("POTScale")) fPOTScale = inputstrvalD;
	else if (fieldString.EqualTo("POTScaleErr")) fPOTScaleErr = inputstrvalD;
	else if (fieldString.EqualTo("BkgBiasObsP0")) fBkgBiasObsP0 = inputstrvalD;
	else if (fieldString.EqualTo("BkgBiasObsP1")) fBkgBiasObsP1 = inputstrvalD;
	else if (fieldString.EqualTo("BkgBiasErrP0")) fBkgBiasErrP0 = inputstrvalD;
	else if (fieldString.EqualTo("BkgBiasErrP1")) fBkgBiasErrP1 = inputstrvalD;
	else if (fieldString.EqualTo("BkgBiasErrP0P1Corr")) fBkgBiasErrP0P1Corr = inputstrvalD;
	else if (fieldString.EqualTo("EffiOverBkgObsP0_0")) fEffiOverBkgObsP0[0] = inputstrvalD*1E-5;
	else if (fieldString.EqualTo("EffiOverBkgObsP1_0")) fEffiOverBkgObsP1[0] = inputstrvalD*1E-5;
	else if (fieldString.EqualTo("EffiOverBkgErrP0_0")) fEffiOverBkgErrP0[0] = inputstrvalD*1E-5;
	else if (fieldString.EqualTo("EffiOverBkgErrP1_0")) fEffiOverBkgErrP1[0] = inputstrvalD*1E-5;
	else if (fieldString.EqualTo("EffiOverBkgErrP0P1Corr_0")) fEffiOverBkgErrP0P1Corr[0] = inputstrvalD;
	else if (fieldString.EqualTo("EffiOverBkgObsP0_1")) fEffiOverBkgObsP0[1] = inputstrvalD*1E-5;
	else if (fieldString.EqualTo("EffiOverBkgObsP1_1")) fEffiOverBkgObsP1[1] = inputstrvalD*1E-5;
	else if (fieldString.EqualTo("EffiOverBkgErrP0_1")) fEffiOverBkgErrP0[1] = inputstrvalD*1E-5;
	else if (fieldString.EqualTo("EffiOverBkgErrP1_1")) fEffiOverBkgErrP1[1] = inputstrvalD*1E-5;
	else if (fieldString.EqualTo("EffiOverBkgErrP0P1Corr_1")) fEffiOverBkgErrP0P1Corr[1] = inputstrvalD;
	else if (fieldString.EqualTo("EffiOverBkgObsP0_2")) fEffiOverBkgObsP0[2] = inputstrvalD*1E-5;
	else if (fieldString.EqualTo("EffiOverBkgObsP1_2")) fEffiOverBkgObsP1[2] = inputstrvalD*1E-5;
	else if (fieldString.EqualTo("EffiOverBkgErrP0_2")) fEffiOverBkgErrP0[2] = inputstrvalD*1E-5;
	else if (fieldString.EqualTo("EffiOverBkgErrP1_2")) fEffiOverBkgErrP1[2] = inputstrvalD*1E-5;
	else if (fieldString.EqualTo("EffiOverBkgErrP0P1Corr_2")) fEffiOverBkgErrP0P1Corr[2] = inputstrvalD;
	else {
	  std::cerr << "Wrong input field string for double value: " << fieldString.Data() << std::endl;
	  return -1;
	}
      }
      else if (element.second == kBooleanField){      
	bool inputstrvalB = valueString.Atoi();
	if (fieldString.EqualTo("GeneMode")) fGeneMode = inputstrvalB;
	else if (fieldString.EqualTo("BkgOnlyGeneMode")) fBkgOnlyGeneMode = inputstrvalB;
	else if (fieldString.EqualTo("ReadMode")) fReadMode = inputstrvalB;
	else if (fieldString.EqualTo("ToyOfToyMode")) fToyOfToyMode = inputstrvalB;
	else if (fieldString.EqualTo("BkgOnlyNObsFromFile")) fBkgOnlyNObsFromFile = inputstrvalB;
	else if (fieldString.EqualTo("UseNuisance")) fUseNuisance = inputstrvalB;
	else if (fieldString.EqualTo("CorrectBkgBias")) fCorrectBkgBias = inputstrvalB;
	else if (fieldString.EqualTo("AssumeEffiOverBkgCurve")) fAssumeEffiOverBkgCurve = inputstrvalB;
	else if (fieldString.EqualTo("EvaluateExpLimit")) fEvaluateExpLimit = inputstrvalB;
	else if (fieldString.EqualTo("ManipulateInput")) fManipulateInput = inputstrvalB;
	else {
	  std::cerr << "Wrong input field string for bool value: " << fieldString.Data() << std::endl;
	  return -1;
	}
      }
      else if (element.second == kStringField){      
	TString inputstrvalS = valueString.Data();
	if (fieldString.EqualTo("InputFileName")) fInputFileName = inputstrvalS.Data();
	else if (fieldString.EqualTo("GeneOutputFileName")) fGeneOutputFileName = inputstrvalS.Data();
	else {
	  std::cerr << "Wrong input field string for string value: " << fieldString.Data() << std::endl;
	  return -1;
	}      
      }
      else {
	std::cerr << "Wrong input field format: " << element.second << std::endl;
	return -1;
      }
    }
  }
  if (!catchInputString){
    std::cerr << "Cannot manage input string " << fieldString.Data() << std::endl;
    return -1;
  }
  return 0;
  
}


statConfig * statConfig::GetInstance(){
  if ( fInstance == 0 ) { fInstance = new statConfig(); }
  return fInstance;
}
