#ifdef __CLING__
#pragma cling optimize(0)
#endif
void ScanPartDefinitions()
{
//=========Macro generated from canvas: dsq/
//=========  (Wed May 28 10:55:48 2025) by ROOT version 6.30/04
   TCanvas *dsq = new TCanvas("dsq", "",900,66,700,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   dsq->Range(16.17895,-9.526316,17.75789,54.94737);
   dsq->SetFillColor(0);
   dsq->SetBorderMode(0);
   dsq->SetBorderSize(2);
   dsq->SetTickx(1);
   dsq->SetTicky(1);
   dsq->SetLeftMargin(0.14);
   dsq->SetBottomMargin(0.14);
   dsq->SetFrameBorderMode(0);
   dsq->SetFrameBorderMode(0);
   
   TH1F *hframe__9 = new TH1F("hframe__9","",1000,16.4,17.6);
   hframe__9->SetMinimum(-0.5);
   hframe__9->SetMaximum(48.5);
   hframe__9->SetDirectory(nullptr);
   hframe__9->SetStats(0);
   hframe__9->SetLineWidth(2);
   hframe__9->SetMarkerStyle(20);
   hframe__9->GetXaxis()->SetTitle("#sqrt{s} (MeV)");
   hframe__9->GetXaxis()->SetLabelFont(42);
   hframe__9->GetXaxis()->SetLabelSize(0.06);
   hframe__9->GetXaxis()->SetTitleSize(0.06);
   hframe__9->GetXaxis()->SetTitleOffset(1.1);
   hframe__9->GetYaxis()->SetTitle("Energy point ID");
   hframe__9->GetYaxis()->SetLabelFont(42);
   hframe__9->GetYaxis()->SetLabelSize(0.06);
   hframe__9->GetYaxis()->SetTitleSize(0.06);
   hframe__9->GetZaxis()->SetLabelFont(42);
   hframe__9->GetZaxis()->SetLabelSize(0.06);
   hframe__9->GetZaxis()->SetTitleSize(0.06);
   hframe__9->GetZaxis()->SetTitleOffset(0.7);
   hframe__9->Draw(" ");
   
   Double_t gPeriodIDVsSqrts_Scan0_fx1[23] = { 17.12853, 17.26818, 17.22433, 17.17917, 17.40201, 17.35996, 17.31664, 17.09748, 17.06696, 16.99856, 16.9516, 16.90572, 16.85911, 16.81358, 16.76397, 16.71757, 16.67104,
   16.62377, 16.57698, 16.52852, 16.48146, 16.43395, 16.38631 };
   Double_t gPeriodIDVsSqrts_Scan0_fy1[23] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
   17, 18, 19, 20, 21, 22 };
   TGraph *graph = new TGraph(23,gPeriodIDVsSqrts_Scan0_fx1,gPeriodIDVsSqrts_Scan0_fy1);
   graph->SetName("gPeriodIDVsSqrts_Scan0");
   graph->SetTitle("");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   graph->SetMarkerStyle(20);
   graph->SetMarkerSize(1.5);
   
   TH1F *Graph_gPeriodIDVsSqrts_Scan01 = new TH1F("Graph_gPeriodIDVsSqrts_Scan01","",100,16.28474,17.50358);
   Graph_gPeriodIDVsSqrts_Scan01->SetMinimum(0);
   Graph_gPeriodIDVsSqrts_Scan01->SetMaximum(24.2);
   Graph_gPeriodIDVsSqrts_Scan01->SetDirectory(nullptr);
   Graph_gPeriodIDVsSqrts_Scan01->SetStats(0);
   Graph_gPeriodIDVsSqrts_Scan01->SetLineWidth(2);
   Graph_gPeriodIDVsSqrts_Scan01->SetMarkerStyle(20);
   Graph_gPeriodIDVsSqrts_Scan01->GetXaxis()->SetLabelFont(42);
   Graph_gPeriodIDVsSqrts_Scan01->GetXaxis()->SetLabelSize(0.06);
   Graph_gPeriodIDVsSqrts_Scan01->GetXaxis()->SetTitleSize(0.06);
   Graph_gPeriodIDVsSqrts_Scan01->GetXaxis()->SetTitleOffset(1.1);
   Graph_gPeriodIDVsSqrts_Scan01->GetYaxis()->SetLabelFont(42);
   Graph_gPeriodIDVsSqrts_Scan01->GetYaxis()->SetLabelSize(0.06);
   Graph_gPeriodIDVsSqrts_Scan01->GetYaxis()->SetTitleSize(0.06);
   Graph_gPeriodIDVsSqrts_Scan01->GetZaxis()->SetLabelFont(42);
   Graph_gPeriodIDVsSqrts_Scan01->GetZaxis()->SetLabelSize(0.06);
   Graph_gPeriodIDVsSqrts_Scan01->GetZaxis()->SetTitleSize(0.06);
   Graph_gPeriodIDVsSqrts_Scan01->GetZaxis()->SetTitleOffset(0.7);
   graph->SetHistogram(Graph_gPeriodIDVsSqrts_Scan01);
   
   graph->Draw("p");
   
   Double_t gPeriodIDVsSqrts_Scan1_fx2[19] = { 17.3367, 17.29449, 17.25071, 17.20592, 17.16429, 17.12077, 17.07475, 17.0289, 16.98232, 16.93562, 16.88848, 16.84394, 16.79442, 16.74658, 16.698, 16.65049, 16.60224,
   16.55508, 17.38262 };
   Double_t gPeriodIDVsSqrts_Scan1_fy2[19] = { 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44,
   45, 46 };
   graph = new TGraph(19,gPeriodIDVsSqrts_Scan1_fx2,gPeriodIDVsSqrts_Scan1_fy2);
   graph->SetName("gPeriodIDVsSqrts_Scan1");
   graph->SetTitle("");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   graph->SetMarkerStyle(24);
   graph->SetMarkerSize(1.5);
   
   TH1F *Graph_gPeriodIDVsSqrts_Scan12 = new TH1F("Graph_gPeriodIDVsSqrts_Scan12","",100,16.47233,17.46537);
   Graph_gPeriodIDVsSqrts_Scan12->SetMinimum(26.2);
   Graph_gPeriodIDVsSqrts_Scan12->SetMaximum(47.8);
   Graph_gPeriodIDVsSqrts_Scan12->SetDirectory(nullptr);
   Graph_gPeriodIDVsSqrts_Scan12->SetStats(0);
   Graph_gPeriodIDVsSqrts_Scan12->SetLineWidth(2);
   Graph_gPeriodIDVsSqrts_Scan12->SetMarkerStyle(20);
   Graph_gPeriodIDVsSqrts_Scan12->GetXaxis()->SetLabelFont(42);
   Graph_gPeriodIDVsSqrts_Scan12->GetXaxis()->SetLabelSize(0.06);
   Graph_gPeriodIDVsSqrts_Scan12->GetXaxis()->SetTitleSize(0.06);
   Graph_gPeriodIDVsSqrts_Scan12->GetXaxis()->SetTitleOffset(1.1);
   Graph_gPeriodIDVsSqrts_Scan12->GetYaxis()->SetLabelFont(42);
   Graph_gPeriodIDVsSqrts_Scan12->GetYaxis()->SetLabelSize(0.06);
   Graph_gPeriodIDVsSqrts_Scan12->GetYaxis()->SetTitleSize(0.06);
   Graph_gPeriodIDVsSqrts_Scan12->GetZaxis()->SetLabelFont(42);
   Graph_gPeriodIDVsSqrts_Scan12->GetZaxis()->SetLabelSize(0.06);
   Graph_gPeriodIDVsSqrts_Scan12->GetZaxis()->SetTitleSize(0.06);
   Graph_gPeriodIDVsSqrts_Scan12->GetZaxis()->SetTitleOffset(0.7);
   graph->SetHistogram(Graph_gPeriodIDVsSqrts_Scan12);
   
   graph->Draw("p");
   dsq->Modified();
   dsq->SetSelected(dsq);
}
