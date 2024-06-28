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
  printf("./<executable> <inputFileName> \n"
         "--- inputFileName = name of ROOT file with input CLs\n");
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
  statisticalTreatmentTH* statT = new statisticalTreatmentTH();  
  printf("...done\n");

  //Open input file and retrieve the necessary information.

  printf("Opening necessary input files...\n");
  statT->SetVerbosity(3);
  statT->ReadOutput(app.Argv(1));
  printf("DONE!\n");

  // app.Run();
  return 0;
}
