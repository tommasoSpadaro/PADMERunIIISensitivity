#ifdef __CLING__
#pragma cling optimize(0)
#endif
void RMaxStability_ASF()
{
//=========Macro generated from canvas: Acceptance R_{MaX} stability/
//=========  (Fri May 30 00:02:33 2025) by ROOT version 6.34.08
   TCanvas *Acceptance_RMaX_stability = new TCanvas("Acceptance R_{MaX} stability", "",163,311,700,527);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   Acceptance_RMaX_stability->Range(0,0,1,1);
   Acceptance_RMaX_stability->SetFillColor(0);
   Acceptance_RMaX_stability->SetBorderMode(0);
   Acceptance_RMaX_stability->SetBorderSize(2);
   Acceptance_RMaX_stability->SetTickx(1);
   Acceptance_RMaX_stability->SetTicky(1);
   Acceptance_RMaX_stability->SetLeftMargin(0.14);
   Acceptance_RMaX_stability->SetBottomMargin(0.14);
   Acceptance_RMaX_stability->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: Acceptance R_{MaX} stability_1
   TPad *Acceptance__0 = new TPad("Acceptance R_{MaX} stability_1", "Acceptance R_{MaX} stability_1",0.01,0.51,0.99,0.99);
   Acceptance__0->Draw();
   Acceptance__0->cd();
   Acceptance__0->Range(-10.60526,0.9883158,47.28947,1.014632);
   Acceptance__0->SetFillColor(0);
   Acceptance__0->SetBorderMode(0);
   Acceptance__0->SetBorderSize(2);
   Acceptance__0->SetTickx(1);
   Acceptance__0->SetTicky(1);
   Acceptance__0->SetLeftMargin(0.14);
   Acceptance__0->SetBottomMargin(0.14);
   Acceptance__0->SetFrameBorderMode(0);
   Acceptance__0->SetFrameBorderMode(0);
   
   TH1F *hframe__1__1 = new TH1F("hframe__1__1","",1000,-2.5,41.5);
   hframe__1__1->SetMinimum(0.992);
   hframe__1__1->SetMaximum(1.012);
   hframe__1__1->SetDirectory(nullptr);
   hframe__1__1->SetStats(0);
   hframe__1__1->SetLineWidth(2);
   hframe__1__1->SetMarkerStyle(20);
   hframe__1__1->GetXaxis()->SetTitle("Energy point ID");
   hframe__1__1->GetXaxis()->SetLabelFont(42);
   hframe__1__1->GetXaxis()->SetLabelSize(0.06);
   hframe__1__1->GetXaxis()->SetTitleSize(0.06);
   hframe__1__1->GetXaxis()->SetTitleOffset(1.1);
   hframe__1__1->GetXaxis()->SetTitleFont(42);
   hframe__1__1->GetYaxis()->SetTitle("Acceptance R_{Max} stability");
   hframe__1__1->GetYaxis()->SetNdivisions(512);
   hframe__1__1->GetYaxis()->SetLabelFont(42);
   hframe__1__1->GetYaxis()->SetLabelSize(0.06);
   hframe__1__1->GetYaxis()->SetTitleSize(0.06);
   hframe__1__1->GetYaxis()->SetTitleOffset(0.8);
   hframe__1__1->GetYaxis()->SetTitleFont(42);
   hframe__1__1->GetZaxis()->SetLabelFont(42);
   hframe__1__1->GetZaxis()->SetLabelSize(0.06);
   hframe__1__1->GetZaxis()->SetTitleSize(0.06);
   hframe__1__1->GetZaxis()->SetTitleOffset(0.7);
   hframe__1__1->Draw(" ");
   
   Double_t __fx1001[41] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
   17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
   33, 34, 35, 36, 37, 38, 39, 40 };
   Double_t __fy1001[41] = { 0.9978657, 0.9991548, 1.000855, 0.9970159, 0.9972961, 1.003064, 1.001659, 0.9989649, 1.001466, 0.9993423, 0.9955243, 0.9969419, 0.9987997, 0.9962668, 0.9997057, 0.998176, 0.9979927,
   0.9985409, 0.9950961, 0.9957755, 0.9983814, 1.001029, 0.9984819, 1.002459, 1.000995, 1.002025, 0.9997302, 0.9978949, 1.001468, 1.005232, 1.002895, 1.000549, 1.002456,
   1.003133, 1.001657, 1.001709, 1.00264, 0.9992372, 1.001832, 1.00157, 1.005644 };
   Double_t __fex1001[41] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t __fey1001[41] = { 0.002295091, 0.002298056, 0.002301966, 0.002293137, 0.002293781, 0.002307048, 0.002303816, 0.002297619, 0.002303372, 0.002298487, 0.002289706, 0.002292966, 0.002297239, 0.002291414, 0.002299323, 0.002295805, 0.002295383,
   0.002296644, 0.002288721, 0.002290284, 0.002296277, 0.002302366, 0.002296508, 0.002305656, 0.00230229, 0.002304656, 0.002299379, 0.002295158, 0.002303375, 0.002312034, 0.002306659, 0.002301264, 0.002305649,
   0.002307206, 0.00230381, 0.002303931, 0.002306073, 0.002298245, 0.002304213, 0.00230361, 0.002312982 };
   TGraphErrors *gre = new TGraphErrors(41,__fx1001,__fy1001,__fex1001,__fey1001);
   gre->SetName("");
   gre->SetTitle("");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(36);
   
   TH1F *Graph_Graph_Graph10011001 = new TH1F("Graph_Graph_Graph10011001","",100,0,44);
   Graph_Graph_Graph10011001->SetMinimum(0.9912924);
   Graph_Graph_Graph10011001->SetMaximum(1.009472);
   Graph_Graph_Graph10011001->SetDirectory(nullptr);
   Graph_Graph_Graph10011001->SetStats(0);
   Graph_Graph_Graph10011001->SetLineWidth(2);
   Graph_Graph_Graph10011001->SetMarkerStyle(20);
   Graph_Graph_Graph10011001->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph10011001->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph10011001->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph10011001->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph10011001->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph10011001->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph10011001->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph10011001->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph10011001->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph10011001->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph10011001->GetZaxis()->SetTitleOffset(0.7);
   gre->SetHistogram(Graph_Graph_Graph10011001);
   
   gre->Draw("p");
   TLatex *   tex = new TLatex(-0.3625566,1.008485,"PADME");
   tex->SetTextSize(0.1140351);
   tex->SetLineWidth(2);
   tex->Draw();
   Acceptance__0->Modified();
   Acceptance_RMaX_stability->cd();
  
// ------------>Primitives in pad: Acceptance R_{MaX} stability_2
   TPad *Acceptance__1 = new TPad("Acceptance R_{MaX} stability_2", "Acceptance R_{MaX} stability_2",0.01,0.01,0.99,0.49);
   Acceptance__1->Draw();
   Acceptance__1->cd();
   Acceptance__1->Range(16.14737,0.9883158,17.59474,1.014632);
   Acceptance__1->SetFillColor(0);
   Acceptance__1->SetBorderMode(0);
   Acceptance__1->SetBorderSize(2);
   Acceptance__1->SetTickx(1);
   Acceptance__1->SetTicky(1);
   Acceptance__1->SetLeftMargin(0.14);
   Acceptance__1->SetBottomMargin(0.14);
   Acceptance__1->SetFrameBorderMode(0);
   Acceptance__1->SetFrameBorderMode(0);
   
   TH1F *hframe__2__2 = new TH1F("hframe__2__2","",1000,16.35,17.45);
   hframe__2__2->SetMinimum(0.992);
   hframe__2__2->SetMaximum(1.012);
   hframe__2__2->SetDirectory(nullptr);
   hframe__2__2->SetStats(0);
   hframe__2__2->SetLineWidth(2);
   hframe__2__2->SetMarkerStyle(20);
   hframe__2__2->GetXaxis()->SetTitle("#sqrt{s} (MeV)");
   hframe__2__2->GetXaxis()->SetLabelFont(42);
   hframe__2__2->GetXaxis()->SetLabelSize(0.06);
   hframe__2__2->GetXaxis()->SetTitleSize(0.06);
   hframe__2__2->GetXaxis()->SetTitleOffset(1.1);
   hframe__2__2->GetXaxis()->SetTitleFont(42);
   hframe__2__2->GetYaxis()->SetTitle("Acceptance R_{Max} stability");
   hframe__2__2->GetYaxis()->SetNdivisions(512);
   hframe__2__2->GetYaxis()->SetLabelFont(42);
   hframe__2__2->GetYaxis()->SetLabelSize(0.06);
   hframe__2__2->GetYaxis()->SetTitleSize(0.06);
   hframe__2__2->GetYaxis()->SetTitleOffset(0.8);
   hframe__2__2->GetYaxis()->SetTitleFont(42);
   hframe__2__2->GetZaxis()->SetLabelFont(42);
   hframe__2__2->GetZaxis()->SetLabelSize(0.06);
   hframe__2__2->GetZaxis()->SetTitleSize(0.06);
   hframe__2__2->GetZaxis()->SetTitleOffset(0.7);
   hframe__2__2->Draw(" ");
   
   TPaveStats *ptstats = new TPaveStats(0.3274955,0.7116228,0.5716332,0.8563596,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 49.29 / 40");
   ptstats_LaTex = ptstats->AddText("Prob  = 0.1489");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(1100);
   ptstats->Draw();
   
   Double_t AcceptancesPR_lBMaXrBsPstability_fx1002[41] = { 17.12853, 17.26818, 17.22433, 17.17917, 17.40201, 17.35996, 17.31664, 17.09748, 17.06696, 16.99856, 16.9516, 16.90572, 16.85911, 16.81358, 16.76397, 16.71757, 16.67104,
   16.62377, 16.57698, 16.52852, 16.48146, 16.43395, 16.38631, 17.3367, 17.29449, 17.25071, 17.20592, 17.16429, 17.12077, 17.07475, 17.0289, 16.98232, 16.93562,
   16.88848, 16.84394, 16.79442, 16.74658, 16.698, 16.65049, 16.60224, 16.55508 };
   Double_t AcceptancesPR_lBMaXrBsPstability_fy1002[41] = { 0.9978657, 0.9991548, 1.000855, 0.9970159, 0.9972961, 1.003064, 1.001659, 0.9989649, 1.001466, 0.9993423, 0.9955243, 0.9969419, 0.9987997, 0.9962668, 0.9997057, 0.998176, 0.9979927,
   0.9985409, 0.9950961, 0.9957755, 0.9983814, 1.001029, 0.9984819, 1.002459, 1.000995, 1.002025, 0.9997302, 0.9978949, 1.001468, 1.005232, 1.002895, 1.000549, 1.002456,
   1.003133, 1.001657, 1.001709, 1.00264, 0.9992372, 1.001832, 1.00157, 1.005644 };
   Double_t AcceptancesPR_lBMaXrBsPstability_fex1002[41] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t AcceptancesPR_lBMaXrBsPstability_fey1002[41] = { 0.002295091, 0.002298056, 0.002301966, 0.002293137, 0.002293781, 0.002307048, 0.002303816, 0.002297619, 0.002303372, 0.002298487, 0.002289706, 0.002292966, 0.002297239, 0.002291414, 0.002299323, 0.002295805, 0.002295383,
   0.002296644, 0.002288721, 0.002290284, 0.002296277, 0.002302366, 0.002296508, 0.002305656, 0.00230229, 0.002304656, 0.002299379, 0.002295158, 0.002303375, 0.002312034, 0.002306659, 0.002301264, 0.002305649,
   0.002307206, 0.00230381, 0.002303931, 0.002306073, 0.002298245, 0.002304213, 0.00230361, 0.002312982 };
   gre = new TGraphErrors(41,AcceptancesPR_lBMaXrBsPstability_fx1002,AcceptancesPR_lBMaXrBsPstability_fy1002,AcceptancesPR_lBMaXrBsPstability_fex1002,AcceptancesPR_lBMaXrBsPstability_fey1002);
   gre->SetName("Acceptance R_{MaX} stability");
   gre->SetTitle("");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(36);
   
   TH1F *Graph_Graph_AcceptancesPR_lBMaXrBsPstability10021002 = new TH1F("Graph_Graph_AcceptancesPR_lBMaXrBsPstability10021002","",100,16.28474,17.50358);
   Graph_Graph_AcceptancesPR_lBMaXrBsPstability10021002->SetMinimum(0.9912924);
   Graph_Graph_AcceptancesPR_lBMaXrBsPstability10021002->SetMaximum(1.009472);
   Graph_Graph_AcceptancesPR_lBMaXrBsPstability10021002->SetDirectory(nullptr);
   Graph_Graph_AcceptancesPR_lBMaXrBsPstability10021002->SetStats(0);
   Graph_Graph_AcceptancesPR_lBMaXrBsPstability10021002->SetLineWidth(2);
   Graph_Graph_AcceptancesPR_lBMaXrBsPstability10021002->SetMarkerStyle(20);
   Graph_Graph_AcceptancesPR_lBMaXrBsPstability10021002->GetXaxis()->SetLabelFont(42);
   Graph_Graph_AcceptancesPR_lBMaXrBsPstability10021002->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph_AcceptancesPR_lBMaXrBsPstability10021002->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_AcceptancesPR_lBMaXrBsPstability10021002->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph_AcceptancesPR_lBMaXrBsPstability10021002->GetYaxis()->SetLabelFont(42);
   Graph_Graph_AcceptancesPR_lBMaXrBsPstability10021002->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph_AcceptancesPR_lBMaXrBsPstability10021002->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_AcceptancesPR_lBMaXrBsPstability10021002->GetZaxis()->SetLabelFont(42);
   Graph_Graph_AcceptancesPR_lBMaXrBsPstability10021002->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_AcceptancesPR_lBMaXrBsPstability10021002->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_AcceptancesPR_lBMaXrBsPstability10021002->GetZaxis()->SetTitleOffset(0.7);
   gre->SetHistogram(Graph_Graph_AcceptancesPR_lBMaXrBsPstability10021002);
   
   
   TF1 *pol01003 = new TF1("pol0","pol0",16.28474,17.50358, TF1::EAddToList::kNo);
   pol01003->SetFillColor(19);
   pol01003->SetFillStyle(0);
   pol01003->SetMarkerStyle(20);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#cc0000");
   pol01003->SetLineColor(ci);
   pol01003->SetLineWidth(3);
   pol01003->SetChisquare(49.29188);
   pol01003->SetNDF(40);
   pol01003->GetXaxis()->SetLabelFont(42);
   pol01003->GetXaxis()->SetLabelSize(0.06);
   pol01003->GetXaxis()->SetTitleSize(0.06);
   pol01003->GetXaxis()->SetTitleOffset(1.1);
   pol01003->GetYaxis()->SetLabelFont(42);
   pol01003->GetYaxis()->SetLabelSize(0.06);
   pol01003->GetYaxis()->SetTitleSize(0.06);
   pol01003->SetParameter(0,1);
   pol01003->SetParError(0,0.0003592008);
   pol01003->SetParLimits(0,0,0);
   pol01003->SetParent(gre);
   gre->GetListOfFunctions()->Add(pol01003);
   
   ptstats = new TPaveStats(0.3274955,0.7116228,0.5716332,0.8563596,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 49.29 / 40");
   ptstats_LaTex = ptstats->AddText("Prob  = 0.1489");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(1100);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("p");
   TLine *line = new TLine(16.35,1.002,17.45,1.002);
   line->SetLineStyle(2);
   line->Draw();
   line = new TLine(16.35,0.998,17.45,0.998);
   line->SetLineStyle(2);
   line->Draw();
   Acceptance__1->Modified();
   Acceptance_RMaX_stability->cd();
   Acceptance_RMaX_stability->Modified();
   Acceptance_RMaX_stability->SetSelected(Acceptance_RMaX_stability);
   Acceptance_RMaX_stability->ToggleToolBar();

   Acceptance_RMaX_stability->Print("Acceptance_RMaX_stability_ASF.pdf");
}
