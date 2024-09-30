#include <stdlib.h>
#include <iostream>

//#include "TFile.h"
//#include "TNtuple.h"
//#include "TDirectoryFile.h"
//#include "TDirectory.h"

#include "TApplication.h"
#include "TStyle.h"
#include "statisticalTreatmentTH.hh"
#include "statConfig.hh"

void usage()
{
  printf("./<executable> <inputFileName> <seed> \n"
         "--- inputFileName = name of ROOT file with input distributions\n");
}


int main(int argc, char **argv)
{
  if (argc != 3)
  {
    usage();
    exit(1);
  }

  TApplication app("app", &argc, argv);
  gStyle->SetOptFit(1111);

  printf("Initializing statistical treatment classes...\n");

  printf("...init of statConfig\n");
  statConfig* configPtr = statConfig::GetInstance();
  configPtr->readConfigFromFile("/Users/Tommaso1/PADME/PADME_sensitivity/input/config_generic.txt");



  statisticalTreatmentTH* statT = new statisticalTreatmentTH();  
  printf("...done\n");

  //Open input file and retrieve the necessary information.

  printf("Opening necessary input files...\n");
  statT->InitFromFile(app.Argv(1),2.,false);
  //  statT->InitFromFile(app.Argv(1),true); //default error
  statT->SetVerbosity(1);
  printf("...done\n");

  printf("Setting random seed...\n");
  statT->OverrideRandomSeed(atoi(app.Argv(2)));
  printf("...done\n");
  
//  printf("Setting parallelization level %d... process index %d \n",atoi(app.Argv(4)), atoi(app.Argv(5)));
//  statT->InitParallelization(atoi(app.Argv(4)),atoi(app.Argv(5)) );
//  printf("...done\n");

  printf("Launching expected limit evaluation...\n");
  statT->EvaluateExpectedLimit(true,false,0.,0.,"null"); // do the toyoftoy expected limit
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
