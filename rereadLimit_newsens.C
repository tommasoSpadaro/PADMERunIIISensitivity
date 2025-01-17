#include "TMath.h"
#include "TH1D.h"
#include "TProfile.h"
#include "TCanvas.h"
#include "TLine.h"
#include "TFile.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include <iostream>

void rereadfulllim(int seedStem){ // for example 8000

  TString inputFilesStem = "./output/statisticalTest_massSteps_71_massRange_16.22_17.62_UseNuis1_seed";
  if (seedStem==8000) inputFilesStem = "PADME_sensitivity/output/statisticalTest_massSteps_60_massRange_16.32_17.52_UseNuis1_seed";
  const int NPseudo = 30;
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

  TGraph* limit90s[NPseudo]; // UL for the various pseudoevents
  TGraph* limit90sRL[NPseudo]; // RL UL for the various pseudoevents
  TGraph* limitStat;
  const double massmin = 16.22;
  const double massmax = 17.62;

  double limitMin = 999999;
  double limitMax = -99999;
  double limitMinRL = 999999;
  double limitMaxRL = -99999;
  int jgood = 0;
  int jgoodRL = 0;

  for (int j=0; j<NPseudo; j++){
    TFile* filo = new TFile(Form("%s%d.root_limits.root",inputFilesStem.Data(),seedStem+j),"OLD");
    TGraph* grafo = (TGraph*) filo->Get("Limit90");
    limitStat = (TGraph*) filo->Get("FeldmanCousinsLimit90");

    if (grafo->GetN()) {
      cout << "file j = " << j << endl;
      limit90s[jgood] = new TGraph(); limit90s[jgood]->SetName(Form("Lim90_%d",seedStem+j));

      for (int k=0; k < grafo->GetN(); k++){
	limit90s[jgood]->SetPoint(limit90s[jgood]->GetN(),grafo->GetX()[k],grafo->GetY()[k]);
	if (grafo->GetY()[k] < limitMin) limitMin = grafo->GetY()[k];
	if (grafo->GetY()[k] > limitMax) limitMax = grafo->GetY()[k];
      }
      jgood++;
    }

    TGraph* grafoRL = (TGraph*) filo->Get("RolkeLopezLimit90");      
      
    if (grafoRL->GetN()) {
      limit90sRL[jgood] = new TGraph(); limit90sRL[jgood]->SetName(Form("Lim90RL_%d",seedStem+j));
      for (int k=0; k < grafoRL->GetN(); k++){
	limit90sRL[jgoodRL]->SetPoint(limit90sRL[jgoodRL]->GetN(),grafoRL->GetX()[k],grafoRL->GetY()[k]);
	if (grafoRL->GetY()[k] < limitMinRL) limitMinRL = grafoRL->GetY()[k];
	if (grafoRL->GetY()[k] > limitMaxRL) limitMaxRL = grafoRL->GetY()[k];
      }
      jgoodRL++;
    }

    filo->Close();    
  }

  cout << "Graphs and upper limits retrieved for " << jgood << " pseudo events " << endl;

  // evaluate quantiles: 2.5%, 16%, 50%, 66%, 97.5%
  Double_t* qqq = new Double_t[5];
  qqq[0] = 1.-0.5*(1+TMath::Erf(2./TMath::Sqrt(2.))); // -2sigma
  qqq[1] = 1.-0.5*(1+TMath::Erf(1./TMath::Sqrt(2.))); // -1sigma
  qqq[2] = 0.5; // median
  qqq[3] = 0.5*(1+TMath::Erf(1./TMath::Sqrt(2.))); // +1 sigma
  qqq[4] = 0.5*(1+TMath::Erf(2./TMath::Sqrt(2.))); // +2 sigma
  Double_t* xxx = new Double_t[5];
  Double_t* xxxRL = new Double_t[5];

  TGraphAsymmErrors* limit90Exp[2]; // 1, 2 sigma quantiles
  TGraphAsymmErrors* limit90ExpRL[2]; // 1, 2 sigma quantiles
  TGraph* limit90ExpMedian = new TGraph(); limit90ExpMedian->SetName("Median90CLUL");
  TGraph* limit90ExpMedianRL = new TGraph(); limit90ExpMedian->SetName("Median90CLULRL");
  for (int i=0; i<2; i++) {
    limit90Exp[i] = new TGraphAsymmErrors(); limit90Exp[i]->SetName(Form("ExpLimit90CL_%dsigmaCov",2-i));
    limit90ExpRL[i] = new TGraphAsymmErrors(); limit90ExpRL[i]->SetName(Form("ExpLimit90CLRL_%dsigmaCov",2-i));
  }


  // evaluate quantiles for the standard limits

  int npts = limit90s[0]->GetN(); // mass points
  
  cout << "Analyse standard mass limits per mass point " << npts << " limits " << limitMin << " , " << limitMax << endl;
  
  TH1D** limitsPerPoint = new TH1D*[npts]; // define an histogram of limits for each mass point

  for (int k=0; k<npts; k++) {
    
    //    cout << "Book limit histograms " << k << " / " << npts << endl;
    limitsPerPoint[k] = new TH1D(Form("limitPerPoint_%d",k),Form("Limits for mass = %f",limit90s[0]->GetX()[k]),1000.,limitMin,limitMax);

    for (int j=0; j< jgood; j++){
      //      cout << "About to fill limit histograms " << k << " / " << npts << " " << j << " / " << jgood << endl;
      limitsPerPoint[k]->Fill(limit90s[j]->GetY()[k]);
    }

    // evaluate quantiles
    cout << "About to Compute integrals of the limit histograms " << k << " / " << npts << endl;

    limitsPerPoint[k]->ComputeIntegral(); // just a precaution

    cout << "Compute integrals of the limit histograms " << k << " / " << npts << endl;

    for (int i=0; i<5; i++){
      limitsPerPoint[k]->GetQuantiles(1, xxx+i, qqq+i);
      //      std::cout << " point " << k << " mass = " << limit90s[0]->GetX()[k] << "quantile = " << i << " " << xxxRL[i] << std::endl;
    }

    cout << "quantiles of the limit histograms evaluated " << k << " / " << npts << endl;
    limit90ExpMedian->SetPoint(k,limit90s[0]->GetX()[k],xxx[2]);
    for (int i=0; i<2; i++){
      limit90Exp[i]->SetPoint(k,limit90s[0]->GetX()[k],xxx[2]); // median exp limit
      limit90Exp[i]->SetPointError(k,0.,0.,xxx[2]-xxx[i],xxx[4-i]-xxx[2]); // i=0 -> 2sigma coverage, i=1 -> 1sigma coverage
    }
  }


  // evaluate quantiles for the RL evaluation

  int nptsRL = limit90sRL[0]->GetN(); // mass points
  TH1D** limitsPerPointRL = new TH1D*[nptsRL]; // define an histogram of limits for each mass point
  
  cout << "Analyse mass limits per mass point " << npts << " RL: " << limitMinRL << " , " << limitMaxRL << endl;
  
  for (int k=0; k<nptsRL; k++) {
    
    //    cout << "Book RLlimit histograms " << k << " / " << npts << endl;
    limitsPerPointRL[k] = new TH1D(Form("limitPerPointRL_%d",k),Form("RL Limits for mass = %f",limit90sRL[0]->GetX()[k]),1000.,limitMinRL,limitMaxRL);
    for (int j=0; j< jgoodRL; j++){
      //      cout << "About to fill RLlimit histograms " << k << " / " << npts << " " << j << " / " << jgood << endl;
      limitsPerPointRL[k]->Fill(limit90sRL[j]->GetY()[k]);
    }

    // evaluate quantiles
    cout << "About to Compute integrals of the limit histograms " << k << " / " << npts << endl;

    limitsPerPointRL[k]->ComputeIntegral(); // just a precaution

    cout << "Compute integrals of the limit histograms " << k << " / " << npts << endl;

    for (int i=0; i<5; i++){
      limitsPerPointRL[k]->GetQuantiles(1, xxxRL+i, qqq+i);
      //      std::cout << " point " << k << " mass = " << limit90s[0]->GetX()[k] << "quantile = " << i << " " << xxxRL[i] << std::endl;
    }

    cout << "quantiles of the limit histograms evaluated " << k << " / " << npts << endl;
    limit90ExpMedianRL->SetPoint(k,limit90sRL[0]->GetX()[k],xxxRL[2]);
    for (int i=0; i<2; i++){
      limit90ExpRL[i]->SetPoint(k,limit90sRL[0]->GetX()[k],xxxRL[2]); // median exp limit
      limit90ExpRL[i]->SetPointError(k,0.,0.,xxxRL[2]-xxxRL[i],xxxRL[4-i]-xxxRL[2]);
    }
  }

  
  
  cout << "Analyse mass limits per mass point " << npts << endl;
  
  TCanvas* dd =new TCanvas("dd");
  dd->cd(1)->DrawFrame(15.,1E-4,20,1E-3);
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

  limit90Exp[0]->SetFillColor(kGreen);
  limit90Exp[0]->SetFillStyle(3001);
  limit90Exp[0]->Draw("3same");



  // PATCH FOR POT ERROR IMPROVEMENT - WITH 5E10 POT / point and 47 points and 0.3% error on efficiency and 0.3% error on B
  const double improvementFactor = 1.;//0.77; // sqrt(0.6/2. \oplus 0.3)/sqrt(0.6 \oplus 0.3)
  for (int i=0; i<2; i++){
    for (int j=0; j<limit90Exp[i]->GetN(); j++){
      limit90Exp[i]->SetPoint(j,limit90Exp[i]->GetX()[j],limit90Exp[i]->GetY()[j]*improvementFactor);
      limit90Exp[i]->SetPointError(j,0.,0.,limit90Exp[i]->GetEYlow()[j]*improvementFactor,limit90Exp[i]->GetEYhigh()[j]*improvementFactor);
    }
  }
  for (int j=0; j<limit90ExpMedian->GetN(); j++){
    limit90ExpMedian->SetPoint(j,limit90ExpMedian->GetX()[j],limit90ExpMedian->GetY()[j]*improvementFactor);
  }
  for (int j=0; j<limit90ExpMedianRL->GetN(); j++){
    limit90ExpMedianRL->SetPoint(j,limit90ExpMedianRL->GetX()[j],limit90ExpMedianRL->GetY()[j]*improvementFactor);
  }
  
  limit90Exp[1]->SetFillColor(kYellow);
  limit90Exp[1]->SetFillStyle(3001);
  limit90Exp[1]->Draw("3same");

  limit90ExpMedian->SetLineColor(2);
  limit90ExpMedian->SetLineWidth(2);
  limit90ExpMedian->SetLineStyle(1);
  limit90ExpMedian->Draw("Lsame");

  limitStat->SetLineColor(4);
  limitStat->SetLineWidth(1);
  limitStat->SetLineStyle(3);
  limitStat->Draw("Lsame");


  
//  limit90ExpRL[0]->SetFillColor(kBlue);
//  limit90ExpRL[0]->SetFillStyle(3001);
//  limit90ExpRL[0]->Draw("3same");
//
//  limit90ExpRL[1]->SetFillColor(kBlue);
//  limit90ExpRL[1]->SetFillStyle(3001);
//  limit90ExpRL[1]->Draw("3same");

  limit90ExpMedianRL->SetLineColor(1);
  limit90ExpMedianRL->SetLineWidth(1);
  limit90ExpMedianRL->SetLineStyle(2);
  limit90ExpMedianRL->Draw("Lsame");


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
  const double massminLE = 16.22;
  const double massmaxLE = 17.62;
  
  const int nLookEpts = 4;
  double probLookE[nLookEpts];
  int numLookE[nLookEpts] = {0};

  for (int idx=0; idx< jgood; idx++){
    bool outside[nLookEpts]={false,false,false,false};
    for (int k=0; k < limit90s[idx]->GetN(); k++){
      if (limit90s[idx]->GetX()[k] <massminLE || limit90s[idx]->GetX()[k] > massmaxLE) continue;

      // check if in any of the mass points the limit is above median + x sigma
      for (int j=0; j<nLookEpts; j++){
	double ylim = limit90Exp[0]->GetY()[k]+limit90Exp[0]->GetEYhigh()[k]*(1+j*0.5);
	if (limit90s[idx]->GetY()[k] > ylim) {
	  std::cout << "limit outside boundary " << j << " " << limit90s[idx]->GetY()[k] << " " << limit90Exp[0]->GetY()[k] << " " << limit90Exp[0]->GetEYhigh()[k] << " " << ylim << std::endl;
	  outside[j] = true;
	}
      }
    }

    for (int j=0; j<nLookEpts; j++){
      if (outside[j]) numLookE[j]++; // in some point the limit is outside the boundary (upper edge)
    }
  }

  for (int j=0; j<nLookEpts; j++){
    double quantile = 1.-0.5*(1+TMath::Erf((2.+j)/TMath::Sqrt(2.)));
    std::cout << " prob to be outside " << 2+j << " sigma is " << numLookE[j]/(30.) << " vs " << quantile << " ratio = " << numLookE[j]/(30.)/quantile << std::endl;
  }

  TGraph* threesigmalim = new TGraph();
  for (int k=0; k < limit90Exp[0]->GetN(); k++){
    threesigmalim->SetPoint(threesigmalim->GetN(),limit90Exp[0]->GetX()[k],limit90Exp[0]->GetY()[k]+limit90Exp[0]->GetEYhigh()[k]*(1+1*0.5));
  }
  //  threesigmalim->Draw();

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

  limit90Sigmas[1]->SetFillColor(kGreen);
  limit90Sigmas[1]->SetFillStyle(3001);
  limit90Sigmas[1]->Draw("3same");

  limit90Sigmas[0]->SetFillColor(kYellow);
  limit90Sigmas[0]->SetFillStyle(3001);
  limit90Sigmas[0]->Draw("3same");

  limit90Envelope[2]->Draw("Lsame");

  

}



