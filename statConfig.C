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
  
  fNumberOfGenerations = 200; // number of toys
  fFieldStrings.push_back(std::pair{"NumberOfGenerations",sFFI});
  
  fNumberOfGenerationsExpectedLimit = 1; // number of pseudo data 
  fFieldStrings.push_back(std::pair{"NumberOfGenerationsExpectedLimit",sFFI});

  fUseNuisance = true; // by default use nuisance
  fFieldStrings.push_back(std::pair{"UseNuisance",sFFB});

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

  // other external nuisance pars. In case of background-scaled obs events assumed to vary linear with sqrt(s), here the constant and slope parameters might enter
  fPOTScale = 1.;
  fFieldStrings.push_back(std::pair{"POTScale",sFFD});

  fPOTScaleErr = 0.01; 
  fFieldStrings.push_back(std::pair{"POTScaleErr",sFFD});

  fBkgObsP0 = 1E-6;
  fFieldStrings.push_back(std::pair{"BkgObsP0",sFFD});

  fBkgObsP1 = 1E-3;
  fFieldStrings.push_back(std::pair{"BkgObsP1",sFFD});

  fBkgErrP0 = 1E-7;
  fFieldStrings.push_back(std::pair{"BkgErrP0",sFFD});

  fBkgErrP1 = 1E-4;
  fFieldStrings.push_back(std::pair{"BkgErrP1",sFFD});

  fBkgErrP0P1Corr = 0;
  fFieldStrings.push_back(std::pair{"BkgErrP0P1Corr",sFFD});

  
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

	if (fieldString.EqualTo("MassStep")) fMassStep = inputstrvalD;
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
	else if (fieldString.EqualTo("BkgObsP0")) fBkgObsP0 = inputstrvalD;
	else if (fieldString.EqualTo("BkgObsP1")) fBkgObsP1 = inputstrvalD;
	else if (fieldString.EqualTo("BkgErrP0")) fBkgErrP0 = inputstrvalD;
	else if (fieldString.EqualTo("BkgErrP1")) fBkgErrP1 = inputstrvalD;
	else if (fieldString.EqualTo("BkgErrP0P1Corr")) fBkgErrP0P1Corr = inputstrvalD;
	else {
	  std::cerr << "Wrong input field string for double value: " << fieldString.Data() << std::endl;
	  return -1;
	}
      }
      else if (element.second == kBooleanField){      
	bool inputstrvalB = valueString.Atoi();
	if (fieldString.EqualTo("UseNuisance")) fUseNuisance = inputstrvalB;
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
