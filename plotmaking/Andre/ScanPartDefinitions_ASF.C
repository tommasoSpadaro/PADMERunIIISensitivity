#ifdef __CLING__
#pragma cling optimize(0)
#endif
void ScanPartDefinitions_ASF()
{
//=========Macro generated from canvas: dsq/
//=========  (Thu May 29 23:37:03 2025) by ROOT version 6.34.08
   TCanvas *dsq = new TCanvas("dsq", "",132,175,700,554);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   dsq->Range(16.1782,-10.29265,17.75798,55.58807);
   dsq->SetFillColor(0);
   dsq->SetBorderMode(0);
   dsq->SetBorderSize(2);
   dsq->SetTickx(1);
   dsq->SetTicky(1);
   dsq->SetLeftMargin(0.1404011);
   dsq->SetBottomMargin(0.1410526);
   dsq->SetFrameBorderMode(0);
   dsq->SetFrameBorderMode(0);
   
   TH1F *hframe__9__1__1 = new TH1F("hframe__9__1__1","",1000,16.4,17.6);
   hframe__9__1__1->SetMinimum(-1);
   hframe__9__1__1->SetMaximum(49);
   hframe__9__1__1->SetDirectory(nullptr);
   hframe__9__1__1->SetStats(0);
   hframe__9__1__1->SetLineWidth(2);
   hframe__9__1__1->SetMarkerStyle(20);
   hframe__9__1__1->GetXaxis()->SetTitle("#sqrt{s} (MeV)");
   hframe__9__1__1->GetXaxis()->SetLabelFont(42);
   hframe__9__1__1->GetXaxis()->SetLabelSize(0.05);
   hframe__9__1__1->GetXaxis()->SetTitleSize(0.05);
   hframe__9__1__1->GetXaxis()->SetTitleOffset(1.1);
   hframe__9__1__1->GetXaxis()->SetTitleFont(42);
   hframe__9__1__1->GetYaxis()->SetTitle("Energy point ID");
   hframe__9__1__1->GetYaxis()->SetLabelFont(42);
   hframe__9__1__1->GetYaxis()->SetLabelSize(0.05);
   hframe__9__1__1->GetYaxis()->SetTitleSize(0.05);
   hframe__9__1__1->GetYaxis()->SetTitleFont(42);
   hframe__9__1__1->GetZaxis()->SetLabelFont(42);
   hframe__9__1__1->GetZaxis()->SetLabelSize(0.06);
   hframe__9__1__1->GetZaxis()->SetTitleSize(0.06);
   hframe__9__1__1->GetZaxis()->SetTitleOffset(0.7);
   hframe__9__1__1->Draw(" ");
   
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
   
   TH1F *Graph_Graph_Graph_gPeriodIDVsSqrts_Scan0111 = new TH1F("Graph_Graph_Graph_gPeriodIDVsSqrts_Scan0111","",100,16.28474,17.50358);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan0111->SetMinimum(0);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan0111->SetMaximum(24.2);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan0111->SetDirectory(nullptr);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan0111->SetStats(0);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan0111->SetLineWidth(2);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan0111->SetMarkerStyle(20);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan0111->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan0111->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan0111->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan0111->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan0111->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan0111->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan0111->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan0111->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan0111->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan0111->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan0111->GetZaxis()->SetTitleOffset(0.7);
   graph->SetHistogram(Graph_Graph_Graph_gPeriodIDVsSqrts_Scan0111);
   
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
   
   TH1F *Graph_Graph_Graph_gPeriodIDVsSqrts_Scan1222 = new TH1F("Graph_Graph_Graph_gPeriodIDVsSqrts_Scan1222","",100,16.47233,17.46537);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan1222->SetMinimum(26.2);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan1222->SetMaximum(47.8);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan1222->SetDirectory(nullptr);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan1222->SetStats(0);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan1222->SetLineWidth(2);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan1222->SetMarkerStyle(20);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan1222->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan1222->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan1222->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan1222->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan1222->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan1222->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan1222->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan1222->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan1222->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan1222->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_gPeriodIDVsSqrts_Scan1222->GetZaxis()->SetTitleOffset(0.7);
   graph->SetHistogram(Graph_Graph_Graph_gPeriodIDVsSqrts_Scan1222);
   
   graph->Draw("p");
   TLatex *   tex = new TLatex(17.34832,49.81367,"PADME");
   tex->SetTextSize(0.06315789);
   tex->SetLineWidth(2);
   tex->Draw();
   dsq->Modified();
   dsq->SetSelected(dsq);
   dsq->ToggleToolBar();

   dsq->Print("ScanPartDefinitions_ASF.pdf");
}
