#ifdef __CLING__
#pragma cling optimize(0)
#endif
void LeakageCorrection()
{
//=========Macro generated from canvas: Radiation induced correction/
//=========  (Wed May 28 10:50:17 2025) by ROOT version 6.30/04
   TCanvas *Radiation induced correction = new TCanvas("Radiation induced correction", "",900,66,700,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   Radiation->Range(0,0,1,1);
   Radiation->SetFillColor(0);
   Radiation->SetBorderMode(0);
   Radiation->SetBorderSize(2);
   Radiation->SetTickx(1);
   Radiation->SetTicky(1);
   Radiation->SetLeftMargin(0.14);
   Radiation->SetBottomMargin(0.14);
   Radiation->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: Radiation induced correction_1
   TPad *Radiation__2 = new TPad("Radiation induced correction_1", "Radiation induced correction_1",0.01,0.51,0.99,0.99);
   Radiation__2->Draw();
   Radiation__2->cd();
   Radiation__2->Range(-10.60526,0.9352196,47.28947,1.068274);
   Radiation__2->SetFillColor(0);
   Radiation__2->SetBorderMode(0);
   Radiation__2->SetBorderSize(2);
   Radiation__2->SetTickx(1);
   Radiation__2->SetTicky(1);
   Radiation__2->SetLeftMargin(0.14);
   Radiation__2->SetBottomMargin(0.14);
   Radiation__2->SetFrameBorderMode(0);
   Radiation__2->SetFrameBorderMode(0);
   
   TH1F *hframe__3 = new TH1F("hframe__3","",1000,-2.5,41.5);
   hframe__3->SetMinimum(0.9538472);
   hframe__3->SetMaximum(1.054968);
   hframe__3->SetDirectory(nullptr);
   hframe__3->SetStats(0);
   hframe__3->SetLineWidth(2);
   hframe__3->SetMarkerStyle(20);
   hframe__3->GetXaxis()->SetTitle("Energy point ID");
   hframe__3->GetXaxis()->SetLabelFont(42);
   hframe__3->GetXaxis()->SetLabelSize(0.06);
   hframe__3->GetXaxis()->SetTitleSize(0.06);
   hframe__3->GetXaxis()->SetTitleOffset(1.1);
   hframe__3->GetYaxis()->SetTitle("Radiation induced correction");
   hframe__3->GetYaxis()->SetNdivisions(404);
   hframe__3->GetYaxis()->SetLabelFont(42);
   hframe__3->GetYaxis()->SetLabelSize(0.06);
   hframe__3->GetYaxis()->SetTitleSize(0.06);
   hframe__3->GetYaxis()->SetTitleOffset(0.8);
   hframe__3->GetZaxis()->SetLabelFont(42);
   hframe__3->GetZaxis()->SetLabelSize(0.06);
   hframe__3->GetZaxis()->SetTitleSize(0.06);
   hframe__3->GetZaxis()->SetTitleOffset(0.7);
   hframe__3->Draw(" ");
   
   Double_t gScanscale_fx1005[42] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
   17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
   33, 34, 35, 36, 37, 38, 39, 40, 41 };
   Double_t gScanscale_fy1005[42] = { 0.9514393, 0.9531289, 0.9557525, 0.9578893, 0.9599854, 0.9619449, 0.9640117, 0.9662956, 0.9684259, 0.9705587, 0.9727935, 0.9750433, 0.9772847, 0.9795258, 0.9816668, 0.98385, 0.9860371,
   0.9883865, 0.9907452, 0.9931115, 0.9953925, 0.9978558, 1.000195, 1.012646, 1.014816, 1.016923, 1.01998, 1.022141, 1.023597, 1.02583, 1.027825, 1.030042, 1.031948,
   1.033818, 1.035931, 1.038175, 1.040261, 1.042193, 1.04426, 1.046265, 1.048124, 1.050416 };
   Double_t gScanscale_fex1005[42] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t gScanscale_fey1005[42] = { -0.003399235, -0.003280419, -0.003095928, -0.00294567, -0.002798272, -0.002660478, -0.002515139, -0.002354533, -0.002204726, -0.002054749, -0.001897597, -0.001739391, -0.001581776, -0.001424178, -0.001273618, -0.001120096, -0.0009663002,
   -0.0008010896, -0.0006352188, -0.0004688203, -0.0003084209, -0.0001352011, 2.928599e-05, 0.0009048842, 0.001057471, 0.001205602, 0.001420618, 0.001572549, 0.001674952, 0.001831985, 0.001972227, 0.002128144, 0.00226216,
   0.002393682, 0.002542273, 0.002700039, 0.00284677, 0.002982608, 0.003127993, 0.00326897, 0.003399689, 0.003560878 };
   TGraphErrors *gre = new TGraphErrors(42,gScanscale_fx1005,gScanscale_fy1005,gScanscale_fex1005,gScanscale_fey1005);
   gre->SetName("gScanscale");
   gre->SetTitle("");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(28);
   
   TH1F *Graph_gScanscale1005 = new TH1F("Graph_gScanscale1005","",100,0,45.1);
   Graph_gScanscale1005->SetMinimum(0.9411855);
   Graph_gScanscale1005->SetMaximum(1.064231);
   Graph_gScanscale1005->SetDirectory(nullptr);
   Graph_gScanscale1005->SetStats(0);
   Graph_gScanscale1005->SetLineWidth(2);
   Graph_gScanscale1005->SetMarkerStyle(20);
   Graph_gScanscale1005->GetXaxis()->SetLabelFont(42);
   Graph_gScanscale1005->GetXaxis()->SetLabelSize(0.06);
   Graph_gScanscale1005->GetXaxis()->SetTitleSize(0.06);
   Graph_gScanscale1005->GetXaxis()->SetTitleOffset(1.1);
   Graph_gScanscale1005->GetYaxis()->SetLabelFont(42);
   Graph_gScanscale1005->GetYaxis()->SetLabelSize(0.06);
   Graph_gScanscale1005->GetYaxis()->SetTitleSize(0.06);
   Graph_gScanscale1005->GetZaxis()->SetLabelFont(42);
   Graph_gScanscale1005->GetZaxis()->SetLabelSize(0.06);
   Graph_gScanscale1005->GetZaxis()->SetTitleSize(0.06);
   Graph_gScanscale1005->GetZaxis()->SetTitleOffset(0.7);
   gre->SetHistogram(Graph_gScanscale1005);
   
   gre->Draw("p");
   Radiation__2->Modified();
   Radiation->cd();
  
// ------------>Primitives in pad: Radiation induced correction_2
   TPad *Radiation__3 = new TPad("Radiation induced correction_2", "Radiation induced correction_2",0.01,0.01,0.99,0.49);
   Radiation__3->Draw();
   Radiation__3->cd();
   Radiation__3->Range(16.14737,0.9352196,17.59474,1.068274);
   Radiation__3->SetFillColor(0);
   Radiation__3->SetBorderMode(0);
   Radiation__3->SetBorderSize(2);
   Radiation__3->SetTickx(1);
   Radiation__3->SetTicky(1);
   Radiation__3->SetLeftMargin(0.14);
   Radiation__3->SetBottomMargin(0.14);
   Radiation__3->SetFrameBorderMode(0);
   Radiation__3->SetFrameBorderMode(0);
   
   TH1F *hframe__4 = new TH1F("hframe__4","",1000,16.35,17.45);
   hframe__4->SetMinimum(0.9538472);
   hframe__4->SetMaximum(1.054968);
   hframe__4->SetDirectory(nullptr);
   hframe__4->SetStats(0);
   hframe__4->SetLineWidth(2);
   hframe__4->SetMarkerStyle(20);
   hframe__4->GetXaxis()->SetTitle("#sqrt{s} (MeV)");
   hframe__4->GetXaxis()->SetLabelFont(42);
   hframe__4->GetXaxis()->SetLabelSize(0.06);
   hframe__4->GetXaxis()->SetTitleSize(0.06);
   hframe__4->GetXaxis()->SetTitleOffset(1.1);
   hframe__4->GetYaxis()->SetTitle("Radiation induced correction");
   hframe__4->GetYaxis()->SetNdivisions(404);
   hframe__4->GetYaxis()->SetLabelFont(42);
   hframe__4->GetYaxis()->SetLabelSize(0.06);
   hframe__4->GetYaxis()->SetTitleSize(0.06);
   hframe__4->GetYaxis()->SetTitleOffset(0.8);
   hframe__4->GetZaxis()->SetLabelFont(42);
   hframe__4->GetZaxis()->SetLabelSize(0.06);
   hframe__4->GetZaxis()->SetTitleSize(0.06);
   hframe__4->GetZaxis()->SetTitleOffset(0.7);
   hframe__4->Draw(" ");
   
   Double_t Radiation induced correction_fx1006[42] = { 17.12853, 17.26818, 17.22433, 17.17917, 17.40201, 17.35996, 17.31664, 17.09748, 17.06696, 16.99856, 16.9516, 16.90572, 16.85911, 16.81358, 16.76397, 16.71757, 16.67104,
   16.62377, 16.57698, 16.52852, 16.48146, 16.43395, 16.38631, 17.3367, 17.29449, 17.25071, 17.20592, 17.16429, 17.12077, 17.07475, 17.0289, 16.98232, 16.93562,
   16.88848, 16.84394, 16.79442, 16.74658, 16.698, 16.65049, 16.60224, 16.55508, 17.38262 };
   Double_t Radiation induced correction_fy1006[42] = { 0.9514393, 0.9531289, 0.9557525, 0.9578893, 0.9599854, 0.9619449, 0.9640117, 0.9662956, 0.9684259, 0.9705587, 0.9727935, 0.9750433, 0.9772847, 0.9795258, 0.9816668, 0.98385, 0.9860371,
   0.9883865, 0.9907452, 0.9931115, 0.9953925, 0.9978558, 1.000195, 1.012646, 1.014816, 1.016923, 1.01998, 1.022141, 1.023597, 1.02583, 1.027825, 1.030042, 1.031948,
   1.033818, 1.035931, 1.038175, 1.040261, 1.042193, 1.04426, 1.046265, 1.048124, 1.050416 };
   Double_t Radiation induced correction_fex1006[42] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t Radiation induced correction_fey1006[42] = { -0.003399235, -0.003280419, -0.003095928, -0.00294567, -0.002798272, -0.002660478, -0.002515139, -0.002354533, -0.002204726, -0.002054749, -0.001897597, -0.001739391, -0.001581776, -0.001424178, -0.001273618, -0.001120096, -0.0009663002,
   -0.0008010896, -0.0006352188, -0.0004688203, -0.0003084209, -0.0001352011, 2.928599e-05, 0.0009048842, 0.001057471, 0.001205602, 0.001420618, 0.001572549, 0.001674952, 0.001831985, 0.001972227, 0.002128144, 0.00226216,
   0.002393682, 0.002542273, 0.002700039, 0.00284677, 0.002982608, 0.003127993, 0.00326897, 0.003399689, 0.003560878 };
   gre = new TGraphErrors(42,Radiation induced correction_fx1006,Radiation induced correction_fy1006,Radiation induced correction_fex1006,Radiation induced correction_fey1006);
   gre->SetName("Radiation induced correction");
   gre->SetTitle("");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(28);
   
   TH1F *Graph_RadiationsPinducedsPcorrection1006 = new TH1F("Graph_RadiationsPinducedsPcorrection1006","",100,16.28474,17.50358);
   Graph_RadiationsPinducedsPcorrection1006->SetMinimum(0.9411855);
   Graph_RadiationsPinducedsPcorrection1006->SetMaximum(1.064231);
   Graph_RadiationsPinducedsPcorrection1006->SetDirectory(nullptr);
   Graph_RadiationsPinducedsPcorrection1006->SetStats(0);
   Graph_RadiationsPinducedsPcorrection1006->SetLineWidth(2);
   Graph_RadiationsPinducedsPcorrection1006->SetMarkerStyle(20);
   Graph_RadiationsPinducedsPcorrection1006->GetXaxis()->SetLabelFont(42);
   Graph_RadiationsPinducedsPcorrection1006->GetXaxis()->SetLabelSize(0.06);
   Graph_RadiationsPinducedsPcorrection1006->GetXaxis()->SetTitleSize(0.06);
   Graph_RadiationsPinducedsPcorrection1006->GetXaxis()->SetTitleOffset(1.1);
   Graph_RadiationsPinducedsPcorrection1006->GetYaxis()->SetLabelFont(42);
   Graph_RadiationsPinducedsPcorrection1006->GetYaxis()->SetLabelSize(0.06);
   Graph_RadiationsPinducedsPcorrection1006->GetYaxis()->SetTitleSize(0.06);
   Graph_RadiationsPinducedsPcorrection1006->GetZaxis()->SetLabelFont(42);
   Graph_RadiationsPinducedsPcorrection1006->GetZaxis()->SetLabelSize(0.06);
   Graph_RadiationsPinducedsPcorrection1006->GetZaxis()->SetTitleSize(0.06);
   Graph_RadiationsPinducedsPcorrection1006->GetZaxis()->SetTitleOffset(0.7);
   gre->SetHistogram(Graph_Radiation induced correction1006);
   
   gre->Draw("p");
   Radiation__3->Modified();
   Radiation->cd();
   Radiation->Modified();
   Radiation induced correction->SetSelected(Radiation induced correction);
}
