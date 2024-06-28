#include <stdlib.h>
#include <iostream>

//#include "TFile.h"
//#include "TNtuple.h"
//#include "TDirectoryFile.h"
//#include "TDirectory.h"

#include "TApplication.h"
#include "TStyle.h"
#include "statisticalTreatmentTH.hh"

void usage()
{
  printf("./<executable> <inputFileName> <seed> <bkgonly> <outputFileName> \n"
         "--- inputFileName = name of ROOT file with input distributions\n"
         "--- seed = initial seed of random number engine\n"
         "--- bkgonly = 1/0 for bkg only / sig+bkg generation\n"
         "--- outputFileName = name of ROOT file with output distributions\n");
}


int main(int argc, char **argv)
{
  if (argc != 5)
  {
    usage();
    exit(1);
  }

  TApplication app("app", &argc, argv);

  printf("Initializing statistical treatment classes...\n");
  statisticalTreatmentTH* statT = new statisticalTreatmentTH();  
  printf("...done\n");

  //Open input file and retrieve the necessary information.

  printf("Opening necessary input files...\n");
  statT->InitFromFile(app.Argv(1),90.,false);
  //  statT->InitFromFile(app.Argv(1),true); //default error
  statT->SetVerbosity(1);
  printf("...done\n");

  printf("Setting random seed...\n");
  statT->InitRandomSeed(atoi(app.Argv(2)));
  printf("...done\n");
  
  bool bkgonly = true;
  if (atoi(app.Argv(3)) == 0) bkgonly = false;

  if (bkgonly) {
    printf("Generating background only pseudodata to output file...\n");
    statT->SimulateBkgPseudoDataToFile(app.Argv(4)); // do the toyoftoy background only simulation
  }
  else{
    printf("Generating signal + background pseudodata to output file...\n");
    statT->SimulateSignalPlusBkgPseudoDataToFile(app.Argv(4)); // do the toyoftoy signal + background simulation
  }
  printf("...done\n");
  return 0;
}
