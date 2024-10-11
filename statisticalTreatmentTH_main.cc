#include <stdlib.h>
#include <iostream>

//#include "TFile.h"
//#include "TNtuple.h"
//#include "TDirectoryFile.h"
//#include "TDirectory.h"

#include "TApplication.h"
#include "TStyle.h"

#if defined(VFIT)
#include "statisticalTreatmentTH_vfit.hh"
#else
#include "statisticalTreatmentTH.hh"
#endif

#include "statConfig.hh"

void usage()
{
  printf("./<executable> <inputConfigFileName> \n"
         "--- inputConfigFileName = name of input config file\n");
}


int main(int argc, char **argv)
{
  if (argc != 2)
  {
    usage();
    exit(1);
  }

  TApplication app("app", &argc, argv);
  gStyle->SetOptFit(1111);

  printf("Initializing statistical treatment classes...\n");

  printf("...init of statConfig\n");
  statConfig* configPtr = statConfig::GetInstance();
  configPtr->readConfigFromFile(app.Argv(1));
  printf("...done\n");

  printf("Allocating statisticalTreatment class object...\n");
  statisticalTreatmentTH* statT = new statisticalTreatmentTH();  
  printf("...done\n");


  // read-mode: re-read output from a previous run, to evaluate the CLs
  
  if (configPtr->GetReadMode()) { 
    printf("ReadMode: opening necessary input files...\n");
    statT->SetVerbosity(3); // override any verbosity to set a high-verbosity level
    statT->ReadOutput(configPtr->GetInputFileName().Data());
    printf("...done\n");
    return 0;
  }    

  // gene-mode: generate output from toys-of-toys, either background only or signal+background
  
  if (configPtr->GetGeneMode()) { 
    printf("GeneMode: setup...\n");
    std::cout << "GeneMode background-only: " << configPtr->GetBkgOnlyGeneMode() << std::endl;

    statT->Init();
    if (configPtr->GetBkgOnlyGeneMode()){
      std::cout << "Generating background only pseudodata to output file with name--" << configPtr->GetGeneOutputFileName().Data() << std::endl;
      statT->SimulateBkgPseudoDataToFile(configPtr->GetGeneOutputFileName()); // do the toyoftoy background only simulation
    }
    else {
      std::cout << "Generating signal + background pseudodata to output file with name---" << configPtr->GetGeneOutputFileName().Data() << std::endl;
      statT->SimulateSignalPlusBkgPseudoDataToFile(configPtr->GetGeneOutputFileName()); // do the toyoftoy background only simulation
    }
    printf("...done\n");
    return 0;
  }    

  // Standard mode
  
  //Open input file and retrieve the necessary information.

  printf("Initializing statisticalTreatment object...\n");
  statT->Init();
  printf("...done\n");
  
//  printf("Opening necessary input files...\n");
//  statT->InitFromFile(app.Argv(1),2.,false);
//  //  statT->InitFromFile(app.Argv(1),true); //default error
//  statT->SetVerbosity(1);
//  printf("...done\n");
//
//  printf("Setting random seed...\n");
//  statT->OverrideRandomSeed(atoi(app.Argv(2)));
//  printf("...done\n");
  
//  printf("Setting parallelization level %d... process index %d \n",atoi(app.Argv(4)), atoi(app.Argv(5)));
//  statT->InitParallelization(atoi(app.Argv(4)),atoi(app.Argv(5)) );
//  printf("...done\n");

  printf("Launching expected limit evaluation...\n");
  statT->EvaluateExpectedLimit();//true,false,0.,0.,"null"); // do the toyoftoy expected limit
  //  statT->EvaluateExpectedLimit(false,false,16.8,6.E-4,"output/geneNObsSigPlusBkg.root"); // read from file the nobs to evaluate the expected limit
  //  statT->EvaluateExpectedLimit(false,false,16.8,8.E-4,"output/geneNObsSigPlusBkg.root"); // read from file the nobs to evaluate the expected limit
  printf("...done\n");

  // to be done: here retrieve the output and generate the plots
  printf("saving all histos\n");
  statT->SaveAllHistos();
  printf("DONE!\n");

  // app.Run();
  return 0;
}
