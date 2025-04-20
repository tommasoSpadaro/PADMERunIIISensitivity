#include "TMath.h"
#include "TH1D.h"
#include "TProfile.h"
#include "TCanvas.h"
#include "TLine.h"
#include "TLatex.h"
#include "TFile.h"
#include "TF1.h"
#include "TH2D.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "TLegend.h"
#include <iostream>
#include "TEfficiency.h"

void rereadfulllim(int seedStem, int clsoption, bool overlay, int overlaymode, TString infilename1, TString infilename2, bool saveout, TString outfilename){ // for example 8000
  TString clsstring = "";
  if (clsoption == 1) clsstring = "CLsb";

  // clsoption = 0, 1 -> use CLs, CLsb
  // overlay -> if true, overlay curves in the input filename(s) 
  // if (overlay)
  //     overlaymode = 1 || 3 -> overlay a band upper limit curve
  //     overlaymode = 2 || 3 -> overlay a 90CL curve "Limit90"
  // infilename1 -> file with expected band for S+B
  // infilename2 -> file with obs limit to be overlaid, e.g.:
  //             -> /Users/Tommaso1/PADME/PADME_sensitivity/output/statisticalTest_massSteps_33_massRange_16.32_17.6_UseNuis1_seed820001.root_limits.root
  //             -> /Users/Tommaso1/PADME/PADME_sensitivity/output/statisticalTest_massSteps_33_massRange_16.32_17.6_UseNuis1_seed970051.root_limits <-- POL1 fit from Ven
  //             -> /Users/Tommaso1/PADME/PADME_sensitivity/output/statisticalTest_massSteps_33_massRange_16.32_17.6_UseNuis1_seed970061.root_limits <-- POL0 fit from Tom using Ven sideb.
  //             -> /Users/Tommaso1/PADME/PADME_sensitivity/output/statisticalTest_massSteps_33_massRange_16.32_17.6_UseNuis1_seed970072.root_limits <-- POL1 fit from Ven, straightfit=2
  //             -> /Users/Tommaso1/PADME/PADME_sensitivity/output/statisticalTest_massSteps_33_massRange_16.32_17.6_UseNuis1_seed970081.root_limits <-- POL1 fit from Ven, straightfit=2, extended range in gve, finer binning in mass [WAS STRAIGHT FIT 2 OK?!]
  //            -> /Users/Tommaso1/PADME/PADME_sensitivity/output/statisticalTest_massSteps_33_massRange_16.32_17.6_UseNuis1_seed970082.root_limits <-- POL1 fit from Ven, straightfit=1, extended range in gve, finer binning in mass, B vs sqrt(s) pol1 separate PER SCAN, 0.3% added on B error [GOES WITH 990000 SERIES]
  //            -> /Users/Tommaso1/PADME/PADME_sensitivity/output/statisticalTest_massSteps_33_massRange_16.32_17.6_UseNuis1_seed970083.root_limits <-- POL1 fit from Ven, extended range in gve, standard binning in mass, straightfitmode = 2, 0.3% added on B error [GOES WITH 980000 OR 991000 BKG SERIES]
  //            -> /Users/Tommaso1/PADME/PADME_sensitivity/output/statisticalTest_massSteps_76_massRange_16.22_17.74_UseNuis1_seed970084.root_limits <-- POL1 fit from Ven, extended range in gve, FINER binning in mass, straightfitmode = 2, 0.3% added on B error [GOES WITH 980000 OR 991000 BKG SERIES]
  //            -> /Users/Tommaso1/PADME/PADME_sensitivity/output/statisticalTest_massSteps_76_massRange_16.22_17.74_UseNuis1_seed970085.root_limits <-- POL1 fit from Ven, FINER binning in mass, straightfitmode = 2, 0.3% added on B error, 0.1% on POT, slope vs potint with 0.007 error [GOES WITH 995000 BKG SERIES]
  //            -> /Users/Tommaso1/PADME/PADME_sensitivity/output/statisticalTest_massSteps_76_massRange_16.22_17.74_UseNuis1_seed970086.root_limits <-- POL1 fit from Ven, FINER binning in mass, straightfitmode = 2, 0.3% added on B error, 0.1% on POT, slope vs potint with 0.004 error [GOES WITH 996000 BKG SERIES]
  //
  // saveout -> if true, save output in outfilename
  //
  // outfilename -> root filename with the limit curves (median, +-1sigma, +-2 sigma coverages)
  
  TString inputFilesStem = "./output/statisticalTest_massSteps_71_massRange_16.22_17.62_UseNuis1_seed";
  int NPseudo = 30;
  double massMin = 16.22;
  double massMax = 17.62;
  if (seedStem==8000) inputFilesStem = "./output/statisticalTest_massSteps_60_massRange_16.32_17.52_UseNuis1_seed";
  if (seedStem==28000 || seedStem==40000) {
    inputFilesStem = "./output/statisticalTest_massSteps_24_massRange_16.22_17.62_UseNuis1_seed";
    NPseudo = 90; // maybe 91
  }
  if (seedStem==50000) {
    inputFilesStem = "./output/statisticalTest_massSteps_26_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 98; // maybe 91
    massMax = 17.74;
  }
  if (seedStem==60000) {
    inputFilesStem = "./output/statisticalTest_massSteps_26_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 100; 
    massMax = 17.74;
  }
  if (seedStem==70000) {
    inputFilesStem = "./output/statisticalTest_massSteps_26_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 100; 
    massMax = 17.74;
  }
  if (seedStem==80000) {
    inputFilesStem = "./output/statisticalTest_massSteps_26_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 200; 
    massMax = 17.74;
  }
  if (seedStem==90000) {
    inputFilesStem = "./output/statisticalTest_massSteps_26_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 98; 
    massMax = 17.74;
  }
  if (seedStem==100000) {
    inputFilesStem = "./output/statisticalTest_massSteps_26_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 48; 
    massMax = 17.74;
  }
  if (seedStem==110000) {
    inputFilesStem = "./output/statisticalTest_massSteps_26_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 199; 
    massMax = 17.74;
  }
  if (seedStem==120000) {
    inputFilesStem = "./output/statisticalTest_massSteps_26_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 40; 
    massMax = 17.74;
  }
  if (seedStem==130000) {
    inputFilesStem = "./output/statisticalTest_massSteps_26_massRange_16.22_17.74_UseNuis1_errorDownBy10.0_seed";
    NPseudo = 140; 
    massMax = 17.74;
  }
  if (seedStem==140000) {
    inputFilesStem = "./output/statisticalTest_massSteps_26_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 200; 
    massMax = 17.74;
  }
  if (seedStem==150000) {
    inputFilesStem = "./output/statisticalTest_massSteps_26_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 200; 
    massMax = 17.74;
  }
  if (seedStem==160000) {
    inputFilesStem = "./output/statisticalTest_massSteps_26_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 135; 
    massMax = 17.74;
  }
  if (seedStem==170000) {
    inputFilesStem = "./output/statisticalTest_massSteps_26_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 200; 
    massMax = 17.74;
  }
  if (seedStem==180000) {
    inputFilesStem = "./output/statisticalTest_massSteps_26_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 193; 
    massMax = 17.74;
  }
  if (seedStem==190000) {
    inputFilesStem = "./output/statisticalTest_massSteps_26_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 30; 
    massMax = 17.74;
  }
  if (seedStem==200000) {
    inputFilesStem = "./output/statisticalTest_massSteps_26_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 200; 
    massMax = 17.74;
  }
  if (seedStem==210000) {
    inputFilesStem = "./output/statisticalTest_massSteps_26_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 129; 
    massMax = 17.74;
  }
  if (seedStem==220000) {
    inputFilesStem = "./output/statisticalTest_massSteps_26_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 30; 
    massMax = 17.74;
  }
  if (seedStem==230000) {
    inputFilesStem = "./output/statisticalTest_massSteps_26_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 100; 
    massMax = 17.74;
  }
  if (seedStem==240000) {
    inputFilesStem = "./output/statisticalTest_massSteps_26_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 250; 
    massMax = 17.74;
  }
  if (seedStem==250000) {
    inputFilesStem = "./output/statisticalTest_massSteps_26_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 20; 
    massMax = 17.74;
  }
  if (seedStem==260000) {
    inputFilesStem = "./output/statisticalTest_massSteps_26_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 1000; 
    massMax = 17.74;
  }
  if (seedStem==510000) {
    inputFilesStem = "./output/statisticalTest_massSteps_26_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 45; 
    massMax = 17.74;
  }
  if (seedStem==520000) {
    inputFilesStem = "./output/statisticalTest_massSteps_26_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 90; 
    massMax = 17.74;
  }
  if (seedStem==900000) {
    inputFilesStem = "./output/statisticalTest_massSteps_33_massRange_16.32_17.6_UseNuis1_seed";
    NPseudo = 316; 
    massMax = 17.74;
  }
  if (seedStem==910000) {
    inputFilesStem = "./output/statisticalTest_massSteps_33_massRange_16.32_17.6_UseNuis1_seed";
    NPseudo = 97; 
    massMax = 17.74;
  }
  if (seedStem==980000) {
    inputFilesStem = "./output/statisticalTest_massSteps_33_massRange_16.32_17.6_UseNuis1_seed";
    NPseudo = 300; 
    massMax = 17.74;
  }
  if (seedStem==990000) {
    inputFilesStem = "./output/statisticalTest_massSteps_33_massRange_16.32_17.6_UseNuis1_seed";
    NPseudo = 250; 
    massMax = 17.74;
  }
  if (seedStem==991000) {
    inputFilesStem = "./output/statisticalTest_massSteps_33_massRange_16.32_17.6_UseNuis1_seed";
    NPseudo = 300; 
    massMax = 17.74;
  }
  if (seedStem==992000) {
    inputFilesStem = "./output/statisticalTest_massSteps_33_massRange_16.32_17.6_UseNuis1_seed";
    NPseudo = 119; 
    massMax = 17.74;
  }
  if (seedStem==993000) { // S+B
    inputFilesStem = "./output/statisticalTest_massSteps_76_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 150; 
    massMax = 17.74;
  }
  if (seedStem==994000) { // S+B
    inputFilesStem = "./output/statisticalTest_massSteps_76_massRange_16.22_17.74_UseNuis1_seed";
    NPseudo = 150; 
    massMax = 17.74;
  }
  if (seedStem==995000) { // B only
    inputFilesStem = "./output/statisticalTest_massSteps_33_massRange_16.32_17.6_UseNuis1_seed";
    NPseudo = 224; 
    massMax = 17.74;
  }
  if (seedStem==996000) { // B only
    inputFilesStem = "./output/statisticalTest_massSteps_33_massRange_16.32_17.6_UseNuis1_seed";
    NPseudo = 350; 
    massMax = 17.74;
  }
   
  //use 100+j for the normal events
  // 3000+j for efficurveON events analysed with efficurveON
  // 5000+j for efficurveON events analysed with efficurve ON but yield down by 0.5
  // 6000+j for efficurveON events analysed with efficurve ON and the NEW analysis of RunIII 
  // 7000+j for efficurveON events analysed with efficurve ON and the RunIV projection with 5.0E10PerPoint_0.3pctEffi
  // 8000+j for efficurveON events analysed with efficurve ON and the RunIV projection with 10.E10PerPoint_0.2pctEffi
  // 10000+j for efficurveON events analysed with efficurve ON and the NEW analysis of RunIII but S/B as with no e- motion
  // 20000+j for efficurveOFF events analysed with efficurve OFF and the FINAL analysis of RunIII with 0.5% POT error
  // 21000+j for efficurveON events analysed with efficurve ON and the FINAL analysis of RunIII with 0.5% POT error
  // 22000+j for efficurveOFF events analysed with efficurve ON and the FINAL analysis of RunIII with 0.5% POT error
  // 23000+j for efficurveON events analysed with efficurve ON and the FINAL analysis of RunIII with 1.0% POT error
  // 24000+j for efficurveON events analysed with efficurve ON and the FINAL analysis of RunIII with 0.5%/1.0% POT error depending on the scan part
  // 25000+j for efficurveON events analysed with efficurve ON and the FINAL analysis of RunIII with 0.5%/1.0% POT error depending on the scan part and signal(16.90, 8E-4) + bkg
  // 26000+j for efficurveON events analysed with efficurve ON and the FINAL analysis of RunIII with 0.5%/1.0% POT error depending on the scan part and signal(16.90, 7E-4) + bkg
  // 27000+j for efficurveON events analysed with efficurve ON and the FINAL analysis of RunIII with 0.5%/1.0% POT error depending on the scan part and signal(16.90, 1E-4) + bkg
  // 28000+j for efficurveON events analysed with efficurve ON and the FINAL analysis of RunIII with 0.5%/1.0% POT error depending on the scan part with bkg-only pseudoevents
  // 28000+j for efficurveON events analysed with efficurve ON and the FINAL analysis of RunIII with 0.5%/1.0% POT error depending on the scan part with bkg-only pseudoevents fewer mass points, 90 evts
  // 50000+j for efficurveON events analysed with efficurve ON and the FINAL analysis of RunIII with 0.5%/1.0% POT error depending on the scan part with bkg-only pseudoevents + straightFitMode ON
  // 70000+j for efficurveON events analysed with efficurve ON and the FINAL analysis of RunIII with 0.5%/1.0% POT error depending on the scan part with signal(16.90, 6E-4) pseudoevents + straightFitMode ON
  // 80000+j for efficurveON events analysed with efficurve ON and the FINAL analysis of RunIII with 0.5%/1.0% POT error depending on the scan part with bkg-only pseudoevents + straightFitMode ON POT=1E10
  // 90000+j for efficurveON events analysed with efficurve ON and the FINAL analysis of RunIII with 0.5%/1.0% POT error depending on the scan part with bkg-only pseudoevents + straightFitMode ON POT=1E10 and single curve for effi/bkg for the entire scan
  // 100000+j effcurvON, FINAL analysis RunIII with 0.5%/1.0% POT error, bkg-only pseudoevents + straightFitMode ON POT=1E10, single effi/b curve, DO NOT MINIMIZE ON THE TOYS
  // 110000+j effcurvON, FINAL analysis RunIII with 0.5%/1.0% POT error, bkg-only pseudoevents + straightFitMode=1 POT=1E10, single effi/b curve, DO NOT MINIMIZE ON THE TOYS
  // 120000+j effcurvON, FINAL analysis RunIII with 0.5%/1.0% POT error, bkg-only pseudoevents + straightFitMode=2 POT=1E10, assumeeffioverb=2, DO NOT MINIMIZE ON THE TOYS, new code
  // 130000+j effcurvON, FINAL analysis RunIII with 0.5%/1.0% POT error, bkg-only pseudoevents + straightFitMode=2 POT=1E10, assumeeffioverb=1, DO NOT MINIMIZE ON THE TOYS, new code, Error on B down by x10
  // 140000+j effcurvON, FINAL anal RunIII with 0.5%/1.0% dPOT, pot 1E10, bkg-only pseudoevents with b error down by 10, straightFitMode=1, assumeeffioverb=2, MINIMIZE ON THE TOYS, new code, use B fit vs sqrt(s) (but bkg from pseudoevents was not using it!)
  // 150000+j effcurvON, FINAL anal RunIII with 0.5%/1.0% dPOT, pot 1E10, bkg-only pseudoevents with b/pot curve, straightFitMode=1, assumeeffioverb=2, MINIMIZE ON THE TOYS, new code, use B fit vs sqrt(s)
  // 160000+j effcurvON, FINAL anal RunIII with 0.5%/1.0% dPOT, pot 1E10, bkg-only pseudoevents with b/pot curve, straightFitMode=2, assumeeffioverb=2, MINIMIZE ON THE TOYS, new code, use B fit vs sqrt(s)
  // 170000+j effcurvON, FINAL anal RunIII with 0.5%/1.0% dPOT, pot 1E10, bkg-only pseudoevents with b/pot curve, straightFitMode=2, assumeeffioverb=2, MINIMIZE ON THE TOYS, new code, use B fit vs sqrt(s), carry the POT as observables!
  // 180000+j effcurvON, RunIII with 0.5%/1.0% dPOT, pot 1E10, bkg-only pseudoevents with b/pot curve, straightFitMode=2, assumeeffioverb=2, MINIMIZE ON THE TOYS, new generation of pseudoevents, evaluate asimptotic limits
  // 190000+j effcurvON, RunIII with 0.5%/1.0% dPOT, pot 1E10, bkg-only pseudoevents with b/pot curve, straightFitMode=1, assumeeffioverb=2, MINIMIZE ON THE TOYS, new generation of pseudoevents, evaluate asimptotic limits
  // 210000+j effcurvON, RunIII with 1.0% dPOT, pot 1E10, bkg-only pseudoevents with b/pot curve, straightFitMode=1, assumeeffioverb=2, MINIMIZE ON THE TOYS, new generation of pseudoevents, evaluate asimptotic limits, store pulls
  // 220000+j effcurvON, RunIII with 2.0% dPOT, pot 1E10, bkg-only pseudoevents with b/pot curve, straightFitMode=1, assumeeffioverb=2, MINIMIZE ON THE TOYS, new generation of pseudoevents, evaluate asimptotic limits, store pulls, NEW CODE FOR EVENT GENERATION
  // 230000+j effcurvON, RunIII with 1.0% dPOT, pot 1E10, bkg-only pseudoevents with b/pot curve, straightFitMode=2, assumeeffioverb=2, MINIMIZE ON THE TOYS, new generation of pseudoevents, evaluate asimptotic limits, store pulls
  // 240000+j effcurvON, RunIII with 1.0% dPOT, pot 1E10, bkg-only pseudoevents with b/pot curve, straightFitMode=1, assumeeffioverb=2, MINIMIZE ON THE TOYS, new generation of pseudoevents, evaluate asimptotic limits, store pulls, BUG FIX ON P0,P1 of B/pot curve
  // 250000+j effcurvON, RunIII with 1.0% dPOT, pot 1E10, S+B pseudoevents {16.92,0.65E-3} with b/pot curve, straightFitMode=1, assumeeffioverb=2, MINIMIZE ON THE TOYS, new generation of pseudoevents, evaluate asimptotic limits, store pulls, BUG FIX ON P0,P1 of B/pot curve
  // 260000+j effcurvON, RunIII with 1.0% dPOT, pot 1E10, bkg-only pseudoevents with b/pot curve, straightFitMode=1, assumeeffioverb=2, MINIMIZE ON THE TOYS, new generation of pseudoevents, evaluate asimptotic limits, store pulls, BUG FIX ON P0,P1 of B/pot curve
  // 510000+j effcurvON, RunIII FINAL, pot corrections, B, b/pot curve, straightFitMode=1, assumeeffioverb=2, MINIMIZE ON THE TOYS, new generation of pseudoevents, evaluate asimptotic limits, store pulls, BUG FIX ON P0,P1 of B/pot curve, scale 1.00 with 0.003 error
  // 520000+j effcurvON, RunIII FINAL, pot corrections, B, b/pot curve, straightFitMode=1, assumeeffioverb=2, MINIMIZE ON THE TOYS, new generation of pseudoevents, evaluate asimptotic limits, store pulls, BUG FIX ON P0,P1 of B/pot curve, scale 1.00 with 0.021 error
  // 900000+j effcurvON, RunIII FINAL, pot corrections, b/pot curve, straightFitMode=1, assumeeffioverb=2, MINIMIZE ON THE TOYS, new generation of pseudoevents, evaluate asimptotic limits, store pulls, BUG FIX ON P0,P1 of B/pot curve, scale with a 1.01 offset and -0.01 slope with error from venelin's fit
  // 910000+j effcurvON, RunIII FINAL, pot corrections, b/pot curve, straightFitMode=1, assumeeffioverb=2, MINIMIZE ON THE TOYS, new generation of pseudoevents, evaluate asimptotic limits, store pulls, BUG FIX ON P0,P1 of B/pot curve, scale with a P0: 1.00 offset and 2.1% error, ADD 0.5% on B as systematic error on each point
  // 980000+j effcurvON, RunIII FINAL, pot corrections, straightFitMode=2, assumeeffioverb=2, MINIMIZE ON THE TOYS, new generation of pseudoevents, evaluate asimptotic limits, store pulls and fitresult graphs, scale with a P1 using Ven's fit results, ADD 0.5% on B as systematic error on each point
  // 990000+j effcurvON, RunIII FINAL, pot corrections, straightFitMode=1 + B vs sqrt(s) with the parameters from the 2 scans, assumeeffioverb=2, MINIMIZE ON THE TOYS, new generation of pseudoevents, evaluate asimptotic limits, store pulls and fitresult graphs, scale with a P1 using Ven's fit results, ADD 0.3% on B as systematic error on each point
  // 991000+j effcurvON, RunIII FINAL, pot corrections, straightFitMode=2 + B vs sqrt(s) with the parameters from the 2 scans, assumeeffioverb=2, MINIMIZE ON THE TOYS, new generation of pseudoevents, evaluate asimptotic limits, store pulls and fitresult graphs, scale with a P1 using Ven's fit results, ADD 0.3% on B as systematic error on each point
  // 992000+j effcurvON, RunIII FINAL, pot corrections, straightFitMode=2 + B vs sqrt(s) with the parameters from the 2 scans, assumeeffioverb=2, MINIMIZE ON THE TOYS, new generation of pseudoevents, evaluate asimptotic limits, store pulls and fitresult graphs, scale with a P1 using Ven's fit results, ADD 0.0 B as systematic error on each point
  // 993000+j effcurvON, RunIII FINAL, pot corrections, straightFitMode=2 + B vs sqrt(s) with the parameters from the 2 scans, assumeeffioverb=2, MINIMIZE ON THE TOYS, new generation of pseudoevents, evaluate asimptotic limits, store pulls and fitresult graphs, scale with a P1 using Ven's fit results, ADD 0.3% B as systematic error per point, S+B TOYS WITH M=16.9,g=5.5E-4
  // 994000+j effcurvON, RunIII FINAL, pot corrections, straightFitMode=2 + B vs sqrt(s) with the parameters from the 2 scans, assumeeffioverb=2, MINIMIZE ON THE TOYS, new generation of pseudoevents, evaluate asimptotic limits, store pulls and fitresult graphs, scale with a P1 using Ven's fit results, ADD 0.3% B as systematic error per point, S+B TOYS WITH M=16.9,g=5.0E-4
  // 995000+j effcurvON, RunIII FINAL, pot corrections, straightFitMode=2, assumeeffioverb=2, MINIMIZE ON THE TOYS, new generation of pseudoevents, evaluate asimptotic limits, store pulls and fitresult graphs, scale with a P1 using Ven's fit results, ADD 0.3% B as systematic error and 0.1% on POT syst for on each point, use POTSLOPE corr, 0.7% err
  // 996000+j effcurvON, RunIII FINAL, pot corrections, straightFitMode=2, assumeeffioverb=2, MINIMIZE ON THE TOYS, new generation of pseudoevents, evaluate asimptotic limits, store pulls and fitresult graphs, scale with a P1 using Ven's fit results, ADD 0.3% B as systematic error and 0.1% on POT syst for on each point, use POTSLOPE corr, 0.4% err
  
  TGraph** limit90s = new TGraph*[NPseudo]; // UL for the various pseudoevents
  TGraph** limit90sRL = new TGraph*[NPseudo]; // RL UL for the various pseudoevents
  TGraph* limitStat = nullptr;

  double limitMin = 999999;
  double limitMax = -99999;
  double limitMinRL = 999999;
  double limitMaxRL = -99999;
  int jgood = 0;
  int jgoodRL = 0;
  int pseudoev[10000] = {0};
  TCanvas* canvaAllLim = new TCanvas("canvaAllLim");
  canvaAllLim->Divide(6,5);
  for (int j=0; j<NPseudo; j++){
    if (seedStem==170000 && j==23) continue;
    if (seedStem==190000 && j==170) continue;
    if (seedStem==230000 && j<30) continue;
    if (seedStem==900000 && j==0) continue;
    if (seedStem==910000 && j==0) continue;
    if (seedStem==980000 && (j==0||j==35||j==46||j==51||j==54||j==65||j==91||j==98 ||j==121||j==128||j==160||j==171||j==177||j==188||j==218||j==251||j==253||j==255||j==256||j==296)) continue;
    if (seedStem==990000 && j==0) continue;
    if (seedStem==991000 && j==0) continue;
    if (seedStem==992000 && j==0) continue;
    if (seedStem==993000 && j==0) continue;
    if (seedStem==994000 && j==0) continue;
    if (seedStem==995000 && j==0) continue;
    if (seedStem==996000 && j==0) continue;
    
    TFile* filo = new TFile(Form("%s%d.root_limits.root",inputFilesStem.Data(),seedStem+j),"OLD");
    TGraph* grafo = (TGraph*) filo->Get(Form("Limit90%s",clsstring.Data()));
    limitStat = (TGraph*) filo->Get("FeldmanCousinsLimit90");

    if (grafo->GetN()) {
      //      cout << "file j = " << j << endl;
      limit90s[jgood] = new TGraph(); limit90s[jgood]->SetName(Form("Lim90_%d",seedStem+j));

      for (int k=0; k < grafo->GetN(); k++){
	limit90s[jgood]->SetPoint(limit90s[jgood]->GetN(),grafo->GetX()[k],grafo->GetY()[k]);
	if (grafo->GetY()[k] < limitMin && grafo->GetY()[k] > 0) limitMin = grafo->GetY()[k];
	if (grafo->GetY()[k] > limitMax && grafo->GetY()[k] < 1) limitMax = grafo->GetY()[k];
      }
      canvaAllLim->cd(jgood+1);
      limit90s[jgood]->Draw("AP");
      pseudoev[jgood] = seedStem+j;
      jgood++;
    }

    TGraph* grafoRL = (TGraph*) filo->Get("RolkeLopezLimit90");      
      
    if (grafoRL->GetN()) {
      limit90sRL[jgoodRL] = new TGraph(); limit90sRL[jgoodRL]->SetName(Form("Lim90RL_%d",seedStem+j));
      for (int k=0; k < grafoRL->GetN(); k++){
	limit90sRL[jgoodRL]->SetPoint(limit90sRL[jgoodRL]->GetN(),grafoRL->GetX()[k],grafoRL->GetY()[k]);
	if (grafoRL->GetY()[k] < limitMinRL) limitMinRL = grafoRL->GetY()[k];
	if (grafoRL->GetY()[k] > limitMaxRL) limitMaxRL = grafoRL->GetY()[k];
      }
      jgoodRL++;
    }

    filo->Close();    
  }

  cout << "Graphs and upper limits retrieved for " << jgood << " pseudo events for standard limit and " << jgoodRL << " for RL limits" << endl;

  // evaluate quantiles: 2.5%, 16%, 50%, 66%, 97.5%
  Double_t* qqq = new Double_t[5];
  qqq[0] = 1.-0.5*(1+TMath::Erf(2./TMath::Sqrt(2.))); // -2sigma.. 2.27% --> for 250 events = 5.7 events
  qqq[1] = 1.-0.5*(1+TMath::Erf(1./TMath::Sqrt(2.))); // -1sigma..15.87% 
  qqq[2] = 0.5; // median
  qqq[3] = 0.5*(1+TMath::Erf(1./TMath::Sqrt(2.))); // +1 sigma.. 84.13% = 1 - 0.1587
  qqq[4] = 0.5*(1+TMath::Erf(2./TMath::Sqrt(2.))); // +2 sigma.. 97.72% = 1 - 0.0227 --> for 250 events = 244.3 events
  Double_t* xxx = new Double_t[5];
  Double_t* xxxFit = new Double_t[5];
  Double_t* xxxRL = new Double_t[5];

  TGraphAsymmErrors* limit90Exp[2]; // 1, 2 sigma quantiles
  TGraphAsymmErrors* limit90ExpRL[2]; // 1, 2 sigma quantiles
  TGraph* limit90ExpMedian = new TGraph(); limit90ExpMedian->SetName("Median90CLUL");
  TGraph* limit90ExpMedianPlus1Sigma = new TGraph(); limit90ExpMedianPlus1Sigma->SetName("Median90CLULPlus2Sigma");
  TGraph* limit90ExpMedianPlus2Sigma = new TGraph(); limit90ExpMedianPlus2Sigma->SetName("Median90CLULPlus2Sigma");
  TGraph* limit90ExpMedianRL = new TGraph(); limit90ExpMedianRL->SetName("Median90CLULRL");
  for (int i=0; i<2; i++) {
    limit90Exp[i] = new TGraphAsymmErrors(); limit90Exp[i]->SetName(Form("ExpLimit90CL_%dsigmaCov",2-i));
    limit90ExpRL[i] = new TGraphAsymmErrors(); limit90ExpRL[i]->SetName(Form("ExpLimit90CLRL_%dsigmaCov",2-i));
  }


  // evaluate quantiles for the standard limits

  TCanvas* canvaQuantileAllLim = new TCanvas("canvaQuantileAllLim");
  canvaQuantileAllLim->Divide(6,5);
  TCanvas* canvaQuantileAllLimFit = new TCanvas("canvaQuantileAllLimFit");
  canvaQuantileAllLimFit->Divide(6,5);

  int npts = 0;
  TH1D** limitsPerPoint = 0; // define an histogram of limits for each mass point
  TH1D** histofun = 0; // define an histogram of limits for each mass point

  if (jgood) {
    npts = limit90s[0]->GetN(); // mass points
    limitsPerPoint = new TH1D*[npts]; // define an histogram of limits for each mass point
    histofun = new TH1D*[npts]; // define an histogram of limits for each mass point
  }
  
  cout << "Analyse standard mass limits per mass point " << npts << " limits " << limitMin << " , " << limitMax << endl;
  
  for (int k=0; k<npts; k++) {
    
    //    cout << "Book limit histograms " << k << " / " << npts << endl;
    limitsPerPoint[k] = new TH1D(Form("limitPerPoint_%d",k),Form("Limits for mass = %f",limit90s[0]->GetX()[k]),200.,limitMin,limitMax);

    for (int j=0; j< jgood; j++){
      //      cout << "About to fill limit histograms " << k << " / " << npts << " " << j << " / " << jgood << endl;
      limitsPerPoint[k]->Fill(limit90s[j]->GetY()[k]);
//      if (limit90s[j]->GetY()[k] > 0.66E-3) {
//	cout << " Mass " << limit90s[0]->GetX()[k] << " coupling limit " << limit90s[j]->GetY()[k] << " event = " << pseudoev[j] << endl;
//      }
    }

    canvaQuantileAllLim->cd(k+1);
    limitsPerPoint[k]->Draw("");
    
    // evaluate quantiles
    //    cout << "About to Compute integrals of the limit histograms " << k << " / " << npts << endl;

    limitsPerPoint[k]->ComputeIntegral(); // just a precaution

    //    cout << "Compute integrals of the limit histograms " << k << " / " << npts << endl;

    for (int i=0; i<5; i++){
      limitsPerPoint[k]->GetQuantiles(1, xxx+i, qqq+i);
      //      std::cout << " point " << k << " mass = " << limit90s[0]->GetX()[k] << "quantile = " << i << " " << xxxRL[i] << std::endl;
    }

    // try to evaluate quantiles with fitting function

    TF1 * flim = new TF1("flim","2.*gaus(x,[0],[1],[2])*ROOT::Math::normal_cdf([3]*x,1,0)",0,1E-2);
    flim->SetParameters(10,limitsPerPoint[k]->GetMean(),limitsPerPoint[k]->GetRMS(),4);
    limitsPerPoint[k]->Fit("flim","MS","",1.E-4,1E-3);     
    histofun[k] = (TH1D*) limitsPerPoint[k]->Clone(Form("%sClone",limitsPerPoint[k]->GetName()));
    double xw = (histofun[k]->GetXaxis()->GetXmax()-histofun[k]->GetXaxis()->GetXmin())/histofun[k]->GetXaxis()->GetNbins();
    for (int i=0; i<histofun[k]->GetXaxis()->GetNbins(); i++) histofun[k]->SetBinContent(i+1,flim->Eval(histofun[k]->GetXaxis()->GetXmin() + (i+0.5)*xw));
    histofun[k]->ComputeIntegral(); // just a precaution
    for (int i=0; i<5; i++){
      histofun[k]->GetQuantiles(1, xxxFit+i, qqq+i);
    }    
    cout << "quantiles of the limit histograms " << k << " / " << npts << " "
	 << xxx[0] << " vs " << xxxFit[0] << " "
	 << xxx[1] << " vs " << xxxFit[1] << " "
	 << xxx[2] << " vs " << xxxFit[2] << " "
	 << xxx[3] << " vs " << xxxFit[3] << " "
	 << xxx[4] << " vs " << xxxFit[4] << " "
	 << endl;

    limit90ExpMedian->SetPoint(k,limit90s[0]->GetX()[k],xxx[2]);
    limit90ExpMedianPlus1Sigma->SetPoint(k,limit90s[0]->GetX()[k],xxx[3]);
    limit90ExpMedianPlus2Sigma->SetPoint(k,limit90s[0]->GetX()[k],xxx[4]);
    for (int i=0; i<2; i++){
      limit90Exp[i]->SetPoint(k,limit90s[0]->GetX()[k],xxx[2]); // median exp limit
      limit90Exp[i]->SetPointError(k,0.,0.,xxx[2]-xxx[i],xxx[4-i]-xxx[2]); // i=0 -> 2sigma coverage, i=1 -> 1sigma coverage
    }
    cout << "done quantiles " << k << " / " << npts << endl;
  }


  // evaluate quantiles for the RL evaluation

  int nptsRL = limit90sRL[0]->GetN(); // mass points
  TH1D** limitsPerPointRL = new TH1D*[nptsRL]; // define an histogram of limits for each mass point
  
  //  cout << "Analyse mass limits per mass point " << npts << " RL: " << limitMinRL << " , " << limitMaxRL << endl;
  
  for (int k=0; k<nptsRL; k++) {
    
    //    cout << "Book RLlimit histograms " << k << " / " << npts << endl;
    limitsPerPointRL[k] = new TH1D(Form("limitPerPointRL_%d",k),Form("RL Limits for mass = %f",limit90sRL[0]->GetX()[k]),1000.,limitMinRL,limitMaxRL);
    for (int j=0; j< jgoodRL; j++){
      //      cout << "About to fill RLlimit histograms " << k << " / " << npts << " " << j << " / " << jgood << endl;
      limitsPerPointRL[k]->Fill(limit90sRL[j]->GetY()[k]);
    }

    // evaluate quantiles
    //    cout << "About to Compute integrals of the limit histograms " << k << " / " << npts << endl;

    limitsPerPointRL[k]->ComputeIntegral(); // just a precaution

    //    cout << "Compute integrals of the limit histograms " << k << " / " << npts << endl;

    for (int i=0; i<5; i++){
      limitsPerPointRL[k]->GetQuantiles(1, xxxRL+i, qqq+i);
      //      std::cout << " point " << k << " mass = " << limit90s[0]->GetX()[k] << "quantile = " << i << " " << xxxRL[i] << std::endl;
    }

    //    cout << "quantiles of the limit histograms evaluated " << k << " / " << npts << endl;
    limit90ExpMedianRL->SetPoint(k,limit90sRL[0]->GetX()[k],xxxRL[2]);
    for (int i=0; i<2; i++){
      limit90ExpRL[i]->SetPoint(k,limit90sRL[0]->GetX()[k],xxxRL[2]); // median exp limit
      limit90ExpRL[i]->SetPointError(k,0.,0.,xxxRL[2]-xxxRL[i],xxxRL[4-i]-xxxRL[2]);
    }
  }

  // calcolo look-elsewhere

  double massminLE = 16.6;//16.85-3*0.04;//16.6;//massMin;
  double massmaxLE = 17.2;//16.85+3*0.04;//17.2;//massMax;
  
  const int nLookEpts = 48; // 16 points between median and 1 sigma, 16 points between 1 sigma and 2 sigma, 16 above 2 sigma
  double probLookE[nLookEpts];
  int numLookE[nLookEpts] = {0};

  for (int idx=0; idx< jgood; idx++){
    bool outside[nLookEpts]={false};
    for (int k=0; k < limit90s[idx]->GetN(); k++){
      if (limit90s[idx]->GetX()[k] <massminLE || limit90s[idx]->GetX()[k] > massmaxLE) continue;

      // check if in any of the mass points the limit is above median + x sigma
      for (int j=0; j<nLookEpts; j++){
	int zone = j/16; //0, 1, 2
	int inzone = j%16; // 0-->15
	double ylim = 0;
	if (zone == 0) { // median--1sigma
	  ylim = limit90Exp[0]->GetY()[k]+limit90Exp[1]->GetEYhigh()[k]*(j/16.); //median, median + 0.0625sigma, +0.125sigma,..., +0.9375sigma
	} else if (zone == 1) {//1sigma -- 2sigma
	  ylim = limit90Exp[0]->GetY()[k]+limit90Exp[1]->GetEYhigh()[k]+(limit90Exp[0]->GetEYhigh()[k]-limit90Exp[1]->GetEYhigh()[k])*(inzone/16.); //1sigma, 1s + 0.0625(sigma2-sigma).., +0.125sigma2-sigma1,,..., +0.9375(sigma2-sigma)
	} else { // 2sigma onward
	  ylim = limit90Exp[0]->GetY()[k]+limit90Exp[0]->GetEYhigh()[k]*(1+inzone/8.); //2sigma, 2sigma+1/8. 2sigma, 0.25x2sigma,...
	}
	//	cout << "idx= " << idx <<  " lookE point " << j << " zone = " << zone << " inzone = " << inzone << " ylim = " << ylim << endl;
	if (limit90s[idx]->GetY()[k] > ylim) {
	  //	  std::cout << "limit outside boundary " << limit90s[idx]->GetX()[k] << " " << j << " " << limit90s[idx]->GetY()[k] << " " << limit90Exp[0]->GetY()[k] << " " << limit90Exp[0]->GetEYhigh()[k] << " " << ylim << std::endl;
	  outside[j] = true;
	}
      }
    }

    for (int j=0; j<nLookEpts; j++){
      if (outside[j]) numLookE[j]++; // in some point the limit is outside the boundary (upper edge)
    }
  }

  TGraph* trueProb[3]; // -1 sigma, 0, 1 sigma statistical
  TGraphAsymmErrors* probAfterLE; // -1 sigma, 0, 1 sigma statistical

  for (int q = 0; q<3; q++)  {
    trueProb[q] = new TGraph(); trueProb[q]->SetName(Form("TrueProb%d",q-1));
  }
  TH1D* nume = new TH1D("nume","",1,0,1);
  TH1D* deno = new TH1D("deno","",1,0,1);
  for (int j=0; j<nLookEpts; j++){
    nume->SetBinContent(1,numLookE[j]);
    deno->SetBinContent(1,jgood);
    TEfficiency effo(*nume,*deno);
    int zone = j/16; //0, 1, 2
    int inzone = j%16; // 0-->15
    double ylim = 0;
    double numsigma = 0;
    if (zone == 0) numsigma = inzone/16.;
    else if (zone == 1) numsigma = 1+inzone/16.;
    else                numsigma = 2+inzone*0.25;
    trueProb[0]->SetPoint(j,numsigma,effo.GetEfficiency(1)+effo.GetEfficiencyErrorUp(1));
    trueProb[1]->SetPoint(j,numsigma,effo.GetEfficiency(1));
    trueProb[2]->SetPoint(j,numsigma,effo.GetEfficiency(1)-effo.GetEfficiencyErrorLow(1));
  }



  
  // kloe treatment

  const int kloepts = 41;
  double kloem[kloepts];
  double kloesigmaul[kloepts]; //nb
  kloem[0] = 4.2301 ; kloesigmaul[0] =  1.2898e-10;
  kloem[1] = 5.9222 ; kloesigmaul[1] =  8.6237e-11;
  kloem[2] = 8.4602 ; kloesigmaul[2] =  1.7355e-10;
  kloem[3] = 9.3063 ; kloesigmaul[3] =  2.0561e-10;
  kloem[4] = 12.690 ; kloesigmaul[4] =  2.1455e-10;
  kloem[5] = 16.074 ; kloesigmaul[5] =  2.0136e-10;
  kloem[6] = 16.920 ; kloesigmaul[6] =  1.7361e-10;
  kloem[7] = 18.613 ; kloesigmaul[7] =  1.4969e-10;
  kloem[8] = 20.305 ; kloesigmaul[8] =  3.3490e-10;
  kloem[9] = 22.843 ; kloesigmaul[9] =  2.2393e-10;
  kloem[10] = 23.689 ; kloesigmaul[10] =  2.8272e-10;
  kloem[11] = 26.227 ; kloesigmaul[11] =  1.8904e-10;
  kloem[12] = 28.765 ; kloesigmaul[12] =  2.5980e-10;
  kloem[13] = 30.457 ; kloesigmaul[13] =  2.7687e-10;
  kloem[14] = 32.149 ; kloesigmaul[14] =  2.1022e-10;
  kloem[15] = 33.841 ; kloesigmaul[15] =  1.8514e-10;
  kloem[16] = 36.379 ; kloesigmaul[16] =  2.1476e-10;
  kloem[17] = 40.609 ; kloesigmaul[17] =  1.8916e-10;
  kloem[18] = 42.301 ; kloesigmaul[18] =  2.3882e-10;
  kloem[19] = 43.993 ; kloesigmaul[19] =  2.0592e-10;
  kloem[20] = 47.377 ; kloesigmaul[20] =  2.2416e-10;
  kloem[21] = 48.223 ; kloesigmaul[21] =  2.7127e-10;
  kloem[22] = 49.915 ; kloesigmaul[22] =  2.1489e-10;
  kloem[23] = 51.607 ; kloesigmaul[23] =  2.1040e-10;
  kloem[24] = 54.992 ; kloesigmaul[24] =  2.1953e-10;
  kloem[25] = 59.222 ; kloesigmaul[25] =  2.1957e-10;
  kloem[26] = 62.606 ; kloesigmaul[26] =  2.1961e-10;
  kloem[27] = 64.298 ; kloesigmaul[27] =  2.1962e-10;
  kloem[28] = 65.990 ; kloesigmaul[28] =  2.4941e-10;
  kloem[29] = 68.528 ; kloesigmaul[29] =  2.1506e-10;
  kloem[30] = 71.912 ; kloesigmaul[30] =  2.1969e-10;
  kloem[31] = 76.142 ; kloesigmaul[31] =  2.1973e-10;
  kloem[32] = 78.680 ; kloesigmaul[32] =  2.1515e-10;
  kloem[33] = 81.218 ; kloesigmaul[33] =  2.1066e-10;
  kloem[34] = 83.756 ; kloesigmaul[34] =  2.2932e-10;
  kloem[35] = 87.140 ; kloesigmaul[35] =  2.2454e-10;
  kloem[36] = 91.371 ; kloesigmaul[36] =  2.1987e-10;
  kloem[37] = 94.755 ; kloesigmaul[37] =  2.2942e-10;
  kloem[38] = 98.985 ; kloesigmaul[38] =  2.1533e-10;
  kloem[39] = 99.831 ; kloesigmaul[39] =  2.2466e-10;
  kloem[40] = 102.37 ; kloesigmaul[40] =  2.3943e-10;

  const int nptskloeuleps = 15;
  double kloemuleps[nptskloeuleps], kloeuleps[nptskloeuleps];
  kloemuleps[0 ] = 5.1805 ; kloeuleps[0 ] =  0.0000029463;
  kloemuleps[1 ] = 6.2319 ; kloeuleps[1 ] =  0.0000030612;
  kloemuleps[2 ] = 7.5897 ; kloeuleps[2 ] =  0.0000032413;
  kloemuleps[3 ] = 9.3576 ; kloeuleps[3 ] =  0.0000033679;
  kloemuleps[4 ] = 11.257 ; kloeuleps[4 ] =  0.0000035659;
  kloemuleps[5 ] = 13.542 ; kloeuleps[5 ] =  0.0000037755;
  kloemuleps[6 ] = 17.114 ; kloeuleps[6 ] =  0.0000040742;
  kloemuleps[7 ] = 23.577 ; kloeuleps[7 ] =  0.0000046537;
  kloemuleps[8 ] = 30.163 ; kloeuleps[8 ] =  0.0000049281;
  kloemuleps[9 ] = 34.969 ; kloeuleps[9 ] =  0.0000051198;
  kloemuleps[10] = 43.648 ; kloeuleps[10] =  0.0000053200;
  kloemuleps[11] = 62.376 ; kloeuleps[11] =  0.0000051279;
  kloemuleps[12] = 77.845 ; kloeuleps[12] =  0.0000048485;
  kloemuleps[13] = 103.35 ; kloeuleps[13] =  0.0000053325;
  kloemuleps[14] = 124.37 ; kloeuleps[14] =  0.0000068188;
  TGraph* kloeulepsG = new TGraph(nptskloeuleps);
  for (int i=0; i<nptskloeuleps; i++) kloeulepsG->SetPoint(i,kloemuleps[i],kloeuleps[i]);

  TGraph* kloefacG = new TGraph(kloepts);
  for (int i=0; i<kloepts; i++){
    double kloefac = kloeulepsG->Eval(kloem[i])/kloesigmaul[i];
    kloefacG->SetPoint(i,kloem[i],kloefac);
  }
  TCanvas* kloecanva = new TCanvas("");
  kloecanva->DrawFrame(1.,1,100.,1E5);
  kloefacG->SetMarkerStyle(20);
  kloefacG->Draw("P");
  TF1* radiatorFac = new TF1("radiatorFac","[0]+[1]*x",0,200.);
  kloefacG->Fit("radiatorFac","","same");
  
  // plot na64, kloe  
  TGraphAsymmErrors* kloelim = new TGraphAsymmErrors(); kloelim->SetName("KLOE_2015");
  kloelim->AddPoint(15.,(6E-4+1E-2)/2.);
  kloelim->SetPointError(0,0.,0.,(6E-4+1E-2)/2.-6E-4,1E-2-(6E-4+1E-2)/2.);
  kloelim->AddPoint(20.,(6.2E-4+1E-2)/2.);
  kloelim->SetPointError(1,0.,0.,(6.2E-4+1E-2)/2.-6.2E-4,1E-2-(6.2E-4+1E-2)/2.);

  const double gveOverEps = 0.303;//sqrt(4pi alpha_em)
  TGraph* kloeulcorr = new TGraph(kloepts);
  for (int i=0; i<kloepts; i++) {
    kloeulcorr->SetPoint(i,kloem[i],0.303*TMath::Sqrt(kloesigmaul[i]*radiatorFac->Eval(kloem[i])));
  }
  
  TGraphAsymmErrors* na64lim = new TGraphAsymmErrors(); na64lim->SetName("NA64_2019");
  na64lim->AddPoint(15.,(2.3E-4+3.5E-5)/2.);
  na64lim->SetPointError(0,0.,0.,(2.3E-4+3.5E-5)/2.-3.5E-5,2.3E-4-(2.3E-4+3.5E-5)/2.);
  na64lim->AddPoint(20.,(1.6E-4+4.0E-5)/2.);
  na64lim->SetPointError(1,0.,0.,(1.6E-4+4.0E-5)/2.-4.0E-5,1.6E-4-(1.6E-4+4.0E-5)/2.);


  //  PLOT OF UPPER LIMITS
  
  TCanvas* dd =new TCanvas("dd");
  TH2D* framepl = new TH2D("framepl",";M_{X} (MeV);g_{ve};",100,16.,18.5,100,5E-5,1E-3);
  framepl->Draw("");
  framepl->GetYaxis()->SetMaxDigits(3);
  framepl->SetStats(kFALSE);
  framepl->SetLabelSize(0.04,"X");
  framepl->SetLabelSize(0.04,"Y");
  framepl->SetTitleSize(0.05,"X");
  framepl->SetTitleSize(0.05,"Y");
  framepl->SetTitleOffset(0.8,"X");
  framepl->SetTitleOffset(0.8,"Y");


  // KLOE
  
  kloelim->SetFillColor(kGray);
  kloelim->SetFillStyle(3001);
  kloelim->Draw("3same");

//  kloeulcorr->SetLineColor(2);
//  kloeulcorr->SetMarkerStyle(24);
//  kloeulcorr->SetMarkerColor(2);
//  kloeulcorr->Draw("PLsame");

// NA64
  
  na64lim->SetFillColor(kGray);
  na64lim->SetFillStyle(3001);
  na64lim->Draw("3same");


  if (jgood) {

    limit90Exp[0]->SetFillColor(overlay? 41 : kYellow+1 );
    limit90Exp[0]->SetFillStyle(1001);
    limit90Exp[0]->Draw("3same");

    limit90Exp[1]->SetFillColor(overlay? 30 : kGreen+1);
    limit90Exp[1]->SetFillStyle(1001);
    limit90Exp[1]->Draw("3same");

    limit90ExpMedian->SetLineColor(overlay? kBlue : kRed);
    limit90ExpMedian->SetLineWidth(3);
    limit90ExpMedian->SetLineStyle(overlay? 2 : 1);
    limit90ExpMedian->Draw("Lsame");
  }

  TLegend *lego   = new TLegend(0.65,0.32,0.88,0.58);
  TLegend *lego_sb = new TLegend(0.65,0.60,0.88,0.75);
  TLegend *lego_obs = new TLegend(0.65,0.22,0.88,0.30);

  lego->SetHeader("90% CL UL: B-only");
  lego_sb->SetHeader("90% CL UL: B + S #splitline{M_{X} = 16.9 MeV}{g_{ve} = 5 #times 10^{-4}}");
  lego_sb->SetNColumns(2);
  if (clsoption == 0) {
    lego->AddEntry(limit90ExpMedian,"CLs Median","L");
    lego->AddEntry(limit90Exp[0],"CLs #pm2#sigma","f");
    lego->AddEntry(limit90Exp[1],"CLs #pm1#sigma","f");
  }
  else {
    lego->AddEntry(limit90ExpMedian,"CLsb Median","L");
    lego->AddEntry(limit90Exp[0],"CLsb #pm2#sigma","f");
    lego->AddEntry(limit90Exp[1],"CLsb #pm1#sigma","f");
  }
  
  if (!overlay){
    limit90ExpMedianRL->SetLineColor(kBlack);
    limit90ExpMedianRL->SetLineWidth(2);
    limit90ExpMedianRL->SetLineStyle(2);
    limit90ExpMedianRL->Draw("Lsame");
    lego->AddEntry(limit90ExpMedianRL,"RL median","L");
  }

  limitStat->SetLineColor(kBlue);
  limitStat->SetLineWidth(2);
  limitStat->SetLineStyle(3);
  limitStat->Draw("Lsame");
  lego->AddEntry(limitStat,"Bkg stat only","L");

  
  double maxDeviation = -99999;
  TGraph* quantileOneSided = new TGraph(); quantileOneSided->SetName("quantileOneSided");
  TGraphAsymmErrors* pvalueG = new TGraphAsymmErrors(); pvalueG->SetName("p-value");
  TGraphAsymmErrors* qvalueG = new TGraphAsymmErrors(); qvalueG->SetName("equivalent-Nsigma");

  if (overlay) {
    TGraph* limit90ExpMedianIn = nullptr;
    if (overlaymode != 1 && overlaymode != 2 && overlaymode != 3) {
      cout << "Internal inconsistency: if overlay = true, overlaymode must be 1,2 or 3"<< endl;
      return;
    }
    if (overlaymode == 1 || overlaymode == 3) { // wants to retrieve the expected band
      TFile* filoIn = new TFile(infilename1.Data(),"OLD");
      TGraphAsymmErrors* limit90ExpIn[2];
      for (int i=0; i<2; i++) limit90ExpIn[i] = (TGraphAsymmErrors*) filoIn->Get(Form("ExpLimit90CL_%dsigmaCov",2-i));      
      limit90ExpMedianIn = (TGraphAsymmErrors*) filoIn->Get(Form("Median90CLUL"));
      limit90ExpIn[0]->SetFillColorAlpha(kBlue-7,0.35);
      limit90ExpIn[0]->SetFillStyle(1001);
      limit90ExpIn[1]->SetFillColorAlpha(kBlue,0.35);
      limit90ExpIn[1]->SetFillStyle(1001);
      limit90ExpIn[0]->Draw("3same");
      limit90ExpIn[1]->Draw("3same");
      lego_sb->AddEntry(limit90ExpIn[0],"CLs #pm2#sigma","f");    
      lego_sb->AddEntry(limit90ExpIn[1],"CLs #pm1#sigma","f");    
    }
    if (overlaymode == 2 || overlaymode == 3) { // wants to retrieve the obs limit
      TFile* filoIn = new TFile(infilename2.Data(),"OLD");
      limit90ExpMedianIn = (TGraph*) filoIn->Get("Limit90");
      //      limit90ObsRL = (TGraph*) filoIn->Get("RolkeLopezLimit90");
    }

    // evaluate PCL method observed limit and evaluate the maximum number of sigmas of which it exceeds the median UL
    
    for (int q = 0; q<10000; q++) quantileOneSided->SetPoint(q,1.-0.5*(1.+TMath::Erf(float(5*q/10000.)/TMath::Sqrt(2.))),5*q/10000.);
    
    int indexOfMaxDeviation = -1;
    TGraph* limit90ExpMedianPCL = new TGraph();
    for (int q = 0; q< limit90ExpMedianIn->GetN(); q++){
      double medianX = limit90ExpMedianIn->GetX()[q];
      double limmedian = limit90ExpMedian->Eval(medianX);
      double limmedianPlus1Sigma = limit90ExpMedianPlus1Sigma->Eval(medianX);
      double limmedianPlus2Sigma = limit90ExpMedianPlus2Sigma->Eval(medianX);
      if (limit90ExpMedianIn->GetY()[q] < limmedian)
	limit90ExpMedianPCL->SetPoint(q,limit90ExpMedianIn->GetX()[q],limmedian);
      else
	limit90ExpMedianPCL->SetPoint(q,limit90ExpMedianIn->GetX()[q],limit90ExpMedianIn->GetY()[q]);

      double deltawrtmedian = limit90ExpMedianPCL->GetY()[q]-limmedian;
      double deviation = 0;
      if (deltawrtmedian < (limmedianPlus1Sigma-limmedian)) { // below 1 sigma
	deviation =  deltawrtmedian/(limmedianPlus1Sigma-limmedian);
      }
      else if (deltawrtmedian < (limmedianPlus2Sigma-limmedian)) { // above 1 sigma, below 2sigma
	deviation =  1 + (deltawrtmedian-(limmedianPlus1Sigma-limmedian))/(limmedianPlus2Sigma-limmedianPlus1Sigma);
      } else {
	deviation =  deltawrtmedian/(limmedianPlus2Sigma-limmedian)*2;
      }
      int pvalueGnpt = pvalueG->GetN();
      pvalueG->SetPoint(pvalueGnpt,limit90ExpMedianIn->GetX()[q],trueProb[1]->Eval(deviation));
      pvalueG->SetPointError(pvalueGnpt,0.,0.,trueProb[1]->Eval(deviation)-trueProb[0]->Eval(deviation),trueProb[2]->Eval(deviation)-trueProb[1]->Eval(deviation));
      qvalueG->SetPoint(pvalueGnpt,limit90ExpMedianIn->GetX()[q],quantileOneSided->Eval(trueProb[1]->Eval(deviation)));
      qvalueG->SetPointError(pvalueGnpt,0.,0.,
			     quantileOneSided->Eval(trueProb[1]->Eval(deviation)) - quantileOneSided->Eval(trueProb[0]->Eval(deviation)),
			     quantileOneSided->Eval(trueProb[2]->Eval(deviation)) - quantileOneSided->Eval(trueProb[1]->Eval(deviation))
			     );

      cout << "DEviation " << deviation << " " << medianX << " " << limmedianPlus2Sigma << endl;
      if (deviation > maxDeviation) {
	maxDeviation = deviation;
	indexOfMaxDeviation = q;
      }
    }
    cout << "Max deviation = " << maxDeviation << " Mass of max deviation " << limit90ExpMedianPCL->GetX()[indexOfMaxDeviation] << " coupling of max deviation " << limit90ExpMedianPCL->GetY()[indexOfMaxDeviation] << endl;


    if (clsoption == 1) {      
      limit90ExpMedianIn->SetLineColor(kRed);
      limit90ExpMedianIn->SetLineWidth(2);
      limit90ExpMedianIn->SetLineStyle(2);
      limit90ExpMedianIn->Draw("Lsame");
      limit90ExpMedianPCL->SetLineColor(kRed);
      limit90ExpMedianPCL->SetLineWidth(2);
      limit90ExpMedianPCL->SetLineStyle(1);
      limit90ExpMedianPCL->Draw("Lsame");
      if (overlaymode == 2) {
	//	limit90ObsRL->SetLineColor(kBlue);
	//      limit90ObsRL->Draw("Lsame");
      }
      lego_obs->AddEntry(limit90ExpMedianPCL,"Observed PCL","L");    
      lego_obs->AddEntry(limit90ExpMedianIn,"Observed limit","L");    
    }
    else {
      limit90ExpMedianIn->SetLineColor(kRed);
      limit90ExpMedianIn->SetLineWidth(3);
      limit90ExpMedianIn->SetLineStyle(1);
      limit90ExpMedianIn->Draw("Lsame");
      lego_obs->AddEntry(limit90ExpMedianIn,"Observed limit","L");    
    }
  }

  TLatex kloeleg; kloeleg.SetTextSize(0.04); kloeleg.DrawText(17.8,9E-4,"KLOE, 2015");
  TLatex na64leg; na64leg.SetTextSize(0.04); na64leg.DrawText(17.8,1E-4,"NA64, 2019");
  lego->Draw();
  if (overlay) {
    if (overlaymode == 1 || overlaymode == 3) lego_sb->Draw(""); // wants to show the S+B expected band
    if (overlaymode == 2 || overlaymode == 3) lego_obs->Draw(""); // wants to show the Obs limit
  }
  
//  if (seedStem == 6000) {
//    TFile* filo = new TFile(Form("%s%d.root_limits.root",inputFilesStem.Data(),10004),"OLD");
//    TGraph* grafo = (TGraph*) filo->Get("Limit90");
//    for (int j=0; j<grafo->GetN(); j++){
//      if (j==43){//grafo->GetY()[j] > 1E-3 && j>2 && j < grafo->GetN()-2){ // patch it
//	//
//	grafo->RemovePoint(j);
//	grafo->SetPoint(j,grafo->GetX()[j],grafo->Eval(grafo->GetX()[j]));
//      }
//    }
//    grafo->SetLineColor(kPink);
//    grafo->SetLineStyle(2);
//    grafo->SetLineWidth(2);
//    grafo->Draw("Lsame");
//  }


  
  // evaluate look-elsewhere effect at 2, 3, 4, 5 sigma

  // use mass range

  if (overlay) {
    TCanvas* quantileCanva = new TCanvas("quantileCanva");
    quantileOneSided->Draw("AP");
    TCanvas* pvalueCanva = new TCanvas("pvalueCanva");
    pvalueCanva->Divide(1,2);
    pvalueCanva->cd(1); pvalueG->SetMarkerStyle(20); pvalueCanva->DrawFrame(16.,0.,18.5,1.); pvalueG->Draw("Psame");
    pvalueCanva->cd(2); qvalueG->SetMarkerStyle(24); qvalueG->Draw("AP");
    cout << "Deviation " << maxDeviation << " corresponds to true prob = " <<
      trueProb[1]->Eval(maxDeviation) << " - " <<
      trueProb[1]->Eval(maxDeviation)-trueProb[0]->Eval(maxDeviation) << " + " <<
      trueProb[2]->Eval(maxDeviation)-trueProb[1]->Eval(maxDeviation) << endl;
    cout << "Equivalent gaussian 1-sided sigma effects are "
	 << quantileOneSided->Eval(trueProb[1]->Eval(maxDeviation)) << " - " 
	 << quantileOneSided->Eval(trueProb[1]->Eval(maxDeviation))-quantileOneSided->Eval(trueProb[0]->Eval(maxDeviation)) << " + " 
	 << quantileOneSided->Eval(trueProb[2]->Eval(maxDeviation))-quantileOneSided->Eval(trueProb[1]->Eval(maxDeviation)) << endl; 
  }

  for (int j=0; j<nLookEpts; j++){
    double nsigmatest = trueProb[1]->GetX()[j];
    double quantile = 1.-0.5*(1+TMath::Erf((nsigmatest)/TMath::Sqrt(2.)));
    //    double quantile = 1.-0.5*(1+TMath::Erf((2.+j*0.25)/TMath::Sqrt(2.)));
    std::cout << " prob to be outside " << nsigmatest << " sigma is " << 1.*numLookE[j]/jgood << " vs " << quantile << " ratio = " << 1.*numLookE[j]/jgood/quantile << std::endl;
  }

  TGraph* twosigmalim = new TGraph();
  for (int k=0; k < limit90Exp[0]->GetN(); k++){
    twosigmalim->SetPoint(twosigmalim->GetN(),limit90Exp[0]->GetX()[k],limit90Exp[0]->GetY()[k]+limit90Exp[0]->GetEYhigh()[k]*(1+2*0.125));
  }
  //  twosigmalim->Draw();

//PER DOPO - MISSING  // limit with no nuisance
//PER DOPO - MISSING  TFile* fila = new TFile("PADME_sensitivity/output/statisticalTest_massSteps_71_massRange_16.22_17.62_UseNuis0_errorDownBy2.0_seed8501.root_limits.root");
//PER DOPO - MISSING  TGraph* nonuis = (TGraph*) fila->Get("Limit90");
//PER DOPO - MISSING  nonuis->SetLineColor(4);
//PER DOPO - MISSING  //  nonuis->Draw("Lsame");
//PER DOPO - MISSING
//PER DOPO - MISSING  // limit with no nuisance and no electron motion
//PER DOPO - MISSING  TFile* filanoel = new TFile("PADME_sensitivity/output/statisticalTest_massSteps_71_massRange_16.22_17.62_UseNuis0_errorDownBy2.0_seed2002.root_limits.root");
//PER DOPO - MISSING  TGraph* nonuisnoel = (TGraph*) filanoel->Get("Limit90");
//PER DOPO - MISSING  nonuisnoel->SetLineColor(5);
//PER DOPO - MISSING  //  nonuisnoel->Draw("Lsame");
//PER DOPO - MISSING
//PER DOPO - MISSING  // limit with no nuisance and no electron motion
//PER DOPO - MISSING  //  TFile* filaruniv = new TFile("PADME_sensitivity/output/statisticalTest_massSteps_71_massRange_16.22_17.62_UseNuis0_errorDownBy2.0_seed3001.root_limits.root");
//PER DOPO - MISSING  TFile* filaruniv = new TFile("PADME_sensitivity/output/statisticalTest_massSteps_71_massRange_16.22_17.62_UseNuis0_errorDownBy2.0_seed4001.root_limits.root");
//PER DOPO - MISSING  TGraph* nonuisruniv = (TGraph*) filaruniv->Get("Limit90");
//PER DOPO - MISSING  nonuisruniv->SetLineColor(1);
//PER DOPO - MISSING  nonuisruniv->Draw("Lsame");
//PER DOPO - MISSING
//PER DOPO - MISSING  // RL no nuisance
//PER DOPO - MISSING  TGraph* nonuisRL = (TGraph*) fila->Get("RolkeLopezLimit95");
//PER DOPO - MISSING  nonuisRL->SetLineColor(2);
//PER DOPO - MISSING  //  nonuisRL->Draw("Lsame");
//PER DOPO - MISSING
//PER DOPO - MISSING  // RL with nuisance
//PER DOPO - MISSING  TGraph* sinuisRL = (TGraph*) fila->Get("RolkeLopezLimit90");
//PER DOPO - MISSING  sinuisRL->SetLineColor(7);
//PER DOPO - MISSING  //  sinuisRL->Draw("Lsame");
//PER DOPO - MISSING
//PER DOPO - MISSING  // Pure background stat
//PER DOPO - MISSING  TGraph* pureBkgStat = (TGraph*) fila->Get("FeldmanCousinsLimit90");
//PER DOPO - MISSING  pureBkgStat->SetLineColor(3);
//PER DOPO - MISSING  //  pureBkgStat->Draw("Lsame");

  if (saveout){
    TFile* filoOut = new TFile(outfilename.Data(),"NEW");
    limit90Exp[0]->Write();
    limit90Exp[1]->Write();
    limit90ExpMedian->Write();
    filoOut->Write();
    filoOut->Close();
  } 

}


void rereadlim(){
  TString inputFiles[4] = {
    "output/massRange_16.00_18.20_errorDownBy2.0_seeds0_to_101.root_limits.root", "output/massRange_16.10_17.42_errorDownBy2.0_seeds3000_to_3066.root_limits.root", "output/massRange_16.00_18.20_errorDownBy2.0_seeds2000_to_2101.root_limits.root", "output/massRange_16.00_18.20_errorDownBy2.0_seeds1000_to_1101.root_limits.root"};

  
  TH1D* limspread = new TH1D("limspread","",40,3E-4,8E-4);
  TProfile* limspreadprof = new TProfile("limspreadprof","",60,16.,17.4,3E-4,1E-3,"S");
  TGraph* grafi[4];
  TFile* fili[4];
  for (int i=0; i<4; i++){
    fili[i] = new TFile(inputFiles[i].Data(),"OLD");
    grafi[i] = (TGraph*) fili[i]->Get("Limit90");
    std::cout << "grafo = " << grafi[i] << " i = " << i << " file = " << fili[i] << std::endl;
    for (int j=0; j < grafi[i]->GetN(); j++){
      if (grafi[i]->GetX()[j] >16.3 && grafi[i]->GetX()[j] < 17.15) limspread->Fill(grafi[i]->GetY()[j]);
      limspreadprof->Fill(grafi[i]->GetX()[j],grafi[i]->GetY()[j]);
    }
  }

  double sigmas = 4.8E-5;// from the fit of limspread
  TCanvas* cc =new TCanvas("cc");
  limspread->Draw("");
  TCanvas* dd =new TCanvas("dd");
  dd->cd(1)->DrawFrame(15.,1E-4,20,1E-3);
		       //  limspreadprof->Draw("P");


  // plot na64, kloe  
  TGraphAsymmErrors* kloelim = new TGraphAsymmErrors(); kloelim->SetName("KLOE_2015");
  kloelim->AddPoint(15.,(6E-4+1E-2)/2.);
  kloelim->SetPointError(0,0.,0.,(6E-4+1E-2)/2.-6E-4,1E-2-(6E-4+1E-2)/2.);
  kloelim->AddPoint(20.,(6.2E-4+1E-2)/2.);
  kloelim->SetPointError(1,0.,0.,(6.2E-4+1E-2)/2.-6.2E-4,1E-2-(6.2E-4+1E-2)/2.);


  TGraphAsymmErrors* na64lim = new TGraphAsymmErrors(); na64lim->SetName("NA64_2019");
  na64lim->AddPoint(15.,(2.3E-4+3.5E-5)/2.);
  na64lim->SetPointError(0,0.,0.,(2.3E-4+3.5E-5)/2.-3.5E-5,2.3E-4-(2.3E-4+3.5E-5)/2.);
  na64lim->AddPoint(20.,(1.6E-4+4.0E-5)/2.);
  na64lim->SetPointError(1,0.,0.,(1.6E-4+4.0E-5)/2.-4.0E-5,1.6E-4-(1.6E-4+4.0E-5)/2.);

  kloelim->SetFillColor(kGray);
  kloelim->SetFillStyle(3001);
  kloelim->Draw("3same");
  na64lim->SetFillColor(kGray);
  na64lim->SetFillStyle(3001);
  na64lim->Draw("3same");


  
  TGraph* limit90Envelope[5]; // -2sigma, -1 sigma, median, 1 sigma, 2 sigma
  TGraphErrors* limit90Sigmas[2];// 1sigma, 2sigma
  int npts = limspreadprof->GetXaxis()->GetNbins();
  for (int i=0; i<5; i++) {
    limit90Envelope[i] = new TGraph();
    limit90Envelope[i]->SetName(Form("Limit90_%d",i));
  }
  for (int i=0; i<2; i++) {
    limit90Sigmas[i] = new TGraphErrors();
    limit90Sigmas[i]->SetName(Form("Limit90_%d_sigma",i+1));
  }
  for (int j=0; j<npts; j++){
    double mean = limspreadprof->GetBinContent(j);
    double xpos = limspreadprof->GetXaxis()->GetBinCenter(j);
    if (xpos < 16.05) continue;

    for (int i=0; i<5; i++){
      //      limit90Envelope->SetPoint(j,mean+(-2+i)*limspread->GetRMS());
      limit90Envelope[i]->AddPoint(limspreadprof->GetXaxis()->GetBinCenter(j),mean+(-2+i)*sigmas);
    }
    limit90Sigmas[0]->AddPoint(limspreadprof->GetXaxis()->GetBinCenter(j),mean);
    limit90Sigmas[0]->SetPointError(limit90Sigmas[0]->GetN()-1,limspreadprof->GetXaxis()->GetBinWidth(j)*0.5,sigmas);

    limit90Sigmas[1]->AddPoint(limspreadprof->GetXaxis()->GetBinCenter(j),mean);
    limit90Sigmas[1]->SetPointError(limit90Sigmas[1]->GetN()-1,limspreadprof->GetXaxis()->GetBinWidth(j)*0.5,2*sigmas);
  }

  limit90Sigmas[1]->SetFillColor(kYellow+1);
  limit90Sigmas[1]->SetFillStyle(3001);
  limit90Sigmas[1]->Draw("3same");

  limit90Sigmas[0]->SetFillColor(kGreen+1);
  limit90Sigmas[0]->SetFillStyle(3001);
  limit90Sigmas[0]->Draw("3same");

  limit90Envelope[2]->Draw("Lsame");

  

}



