#ifdef __CLING__
#pragma cling optimize(0)
#endif
void RelativeUncorrelatedErrors_gR_ASF()
{
//=========Macro generated from canvas: relErr/
//=========  (Thu May 29 19:32:26 2025) by ROOT version 6.34.08
   TCanvas *relErr = new TCanvas("relErr", "",563,134,700,554);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   relErr->Range(15.96261,-0.2961789,17.67082,1.810687);
   relErr->SetFillColor(0);
   relErr->SetBorderMode(0);
   relErr->SetBorderSize(2);
   relErr->SetTickx(1);
   relErr->SetTicky(1);
   relErr->SetLeftMargin(0.1389685);
   relErr->SetBottomMargin(0.1410526);
   relErr->SetFrameBorderMode(0);
   relErr->SetFrameBorderMode(0);
   
   TH1F *hframe__1__1__1__1__1 = new TH1F("hframe__1__1__1__1__1","",1000,16.2,17.5);
   hframe__1__1__1__1__1->SetMinimum(0.001);
   hframe__1__1__1__1__1->SetMaximum(1.6);
   hframe__1__1__1__1__1->SetDirectory(nullptr);
   hframe__1__1__1__1__1->SetStats(0);
   hframe__1__1__1__1__1->SetLineWidth(2);
   hframe__1__1__1__1__1->SetMarkerStyle(20);
   hframe__1__1__1__1__1->GetXaxis()->SetTitle("#sqrt{s} (MeV)");
   hframe__1__1__1__1__1->GetXaxis()->SetLabelFont(42);
   hframe__1__1__1__1__1->GetXaxis()->SetLabelOffset(0.006);
   hframe__1__1__1__1__1->GetXaxis()->SetLabelSize(0.05);
   hframe__1__1__1__1__1->GetXaxis()->SetTitleSize(0.05);
   hframe__1__1__1__1__1->GetXaxis()->SetTitleOffset(1.1);
   hframe__1__1__1__1__1->GetXaxis()->SetTitleFont(42);
   hframe__1__1__1__1__1->GetYaxis()->SetTitle("Relative error (%)");
   hframe__1__1__1__1__1->GetYaxis()->SetLabelFont(42);
   hframe__1__1__1__1__1->GetYaxis()->SetLabelSize(0.05);
   hframe__1__1__1__1__1->GetYaxis()->SetTitleSize(0.05);
   hframe__1__1__1__1__1->GetYaxis()->SetTitleOffset(1);
   hframe__1__1__1__1__1->GetYaxis()->SetTitleFont(42);
   hframe__1__1__1__1__1->GetZaxis()->SetLabelFont(42);
   hframe__1__1__1__1__1->GetZaxis()->SetLabelSize(0.06);
   hframe__1__1__1__1__1->GetZaxis()->SetTitleSize(0.06);
   hframe__1__1__1__1__1->GetZaxis()->SetTitleOffset(0.7);
   hframe__1__1__1__1__1->Draw(" ");
   
   Double_t RRelErr_fx1[42] = { 17.12853, 17.26818, 17.22433, 17.17917, 17.40201, 17.35996, 17.31664, 17.09748, 17.06696, 16.99856, 16.9516, 16.90572, 16.85911, 16.81358, 16.76397, 16.71757, 16.67104,
   16.62377, 16.57698, 16.52852, 16.48146, 16.43395, 16.38631, 17.3367, 17.29449, 17.25071, 17.20592, 17.16429, 17.12077, 17.07475, 17.0289, 16.98232, 16.93562,
   16.88848, 16.84394, 16.79442, 16.74658, 16.698, 16.65049, 16.60224, 16.55508, 17.38262 };
   Double_t RRelErr_fy1[42] = { 0.9209543, 0.9782272, 0.8767792, 0.9131112, 0.9063762, 0.9191777, 0.901499, 0.8815331, 0.8897985, 0.8857918, 0.8977001, 0.8703327, 0.8693725, 0.8691921, 0.8770097, 0.8742446, 0.8751486,
   0.8565962, 0.8590875, 0.8511101, 0.8591216, 0.8475182, 0.8599076, 0.8357782, 0.8384099, 0.8480547, 0.7832188, 0.8519811, 0.9502494, 0.8534189, 0.8717465, 0.8572628, 0.8914456,
   0.9024093, 0.8808472, 0.8750874, 0.8990783, 0.9125538, 0.9086763, 0.9236873, 0.9413941, 0.8874004 };
   TGraph *graph = new TGraph(42,RRelErr_fx1,RRelErr_fy1);
   graph->SetName("RRelErr");
   graph->SetTitle("");
   graph->SetFillStyle(1000);
   graph->SetMarkerStyle(21);
   
   TH1F *Graph_Graph_Graph_Graph_Graph_RRelErr11111 = new TH1F("Graph_Graph_Graph_Graph_Graph_RRelErr11111","",100,16.28474,17.50358);
   Graph_Graph_Graph_Graph_Graph_RRelErr11111->SetMinimum(0.763718);
   Graph_Graph_Graph_Graph_Graph_RRelErr11111->SetMaximum(0.9977281);
   Graph_Graph_Graph_Graph_Graph_RRelErr11111->SetDirectory(nullptr);
   Graph_Graph_Graph_Graph_Graph_RRelErr11111->SetStats(0);
   Graph_Graph_Graph_Graph_Graph_RRelErr11111->SetLineWidth(2);
   Graph_Graph_Graph_Graph_Graph_RRelErr11111->SetMarkerStyle(20);
   Graph_Graph_Graph_Graph_Graph_RRelErr11111->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_Graph_RRelErr11111->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_Graph_Graph_RRelErr11111->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_RRelErr11111->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph_Graph_Graph_RRelErr11111->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_Graph_RRelErr11111->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_Graph_Graph_RRelErr11111->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_RRelErr11111->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_Graph_RRelErr11111->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_Graph_Graph_RRelErr11111->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_RRelErr11111->GetZaxis()->SetTitleOffset(0.7);
   graph->SetHistogram(Graph_Graph_Graph_Graph_Graph_RRelErr11111);
   
   graph->Draw("p");
   
   Double_t NObsRelErr_fx2[42] = { 17.12853, 17.26818, 17.22433, 17.17917, 17.40201, 17.35996, 17.31664, 17.09748, 17.06696, 16.99856, 16.9516, 16.90572, 16.85911, 16.81358, 16.76397, 16.71757, 16.67104,
   16.62377, 16.57698, 16.52852, 16.48146, 16.43395, 16.38631, 17.3367, 17.29449, 17.25071, 17.20592, 17.16429, 17.12077, 17.07475, 17.0289, 16.98232, 16.93562,
   16.88848, 16.84394, 16.79442, 16.74658, 16.698, 16.65049, 16.60224, 16.55508, 17.38262 };
   Double_t NObsRelErr_fy2[42] = { 0.607571, 0.6995865, 0.5604191, 0.6224399, 0.6233333, 0.6458952, 0.6293372, 0.6014159, 0.6207697, 0.6201265, 0.6145379, 0.6071692, 0.6096881, 0.6141097, 0.6276636, 0.6244534, 0.6285209,
   0.6024096, 0.603021, 0.5983159, 0.6100887, 0.5912576, 0.6099017, 0.5845796, 0.5814768, 0.5964932, 0.4933753, 0.5913759, 0.7240477, 0.5860944, 0.6076697, 0.5817294, 0.6253098,
   0.6349388, 0.5975906, 0.5816551, 0.6100527, 0.6244356, 0.6125837, 0.6275305, 0.6455268, 0.5688836 };
   graph = new TGraph(42,NObsRelErr_fx2,NObsRelErr_fy2);
   graph->SetName("NObsRelErr");
   graph->SetTitle("");
   graph->SetFillStyle(1000);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#cc33ff");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#cc33ff");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_Graph_Graph_Graph_NObsRelErr22222 = new TH1F("Graph_Graph_Graph_Graph_Graph_NObsRelErr22222","",100,16.28474,17.50358);
   Graph_Graph_Graph_Graph_Graph_NObsRelErr22222->SetMinimum(0.4703081);
   Graph_Graph_Graph_Graph_Graph_NObsRelErr22222->SetMaximum(0.7471149);
   Graph_Graph_Graph_Graph_Graph_NObsRelErr22222->SetDirectory(nullptr);
   Graph_Graph_Graph_Graph_Graph_NObsRelErr22222->SetStats(0);
   Graph_Graph_Graph_Graph_Graph_NObsRelErr22222->SetLineWidth(2);
   Graph_Graph_Graph_Graph_Graph_NObsRelErr22222->SetMarkerStyle(20);
   Graph_Graph_Graph_Graph_Graph_NObsRelErr22222->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_Graph_NObsRelErr22222->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_Graph_Graph_NObsRelErr22222->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_NObsRelErr22222->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph_Graph_Graph_NObsRelErr22222->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_Graph_NObsRelErr22222->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_Graph_Graph_NObsRelErr22222->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_NObsRelErr22222->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_Graph_NObsRelErr22222->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_Graph_Graph_NObsRelErr22222->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_NObsRelErr22222->GetZaxis()->SetTitleOffset(0.7);
   graph->SetHistogram(Graph_Graph_Graph_Graph_Graph_NObsRelErr22222);
   
   graph->Draw("p");
   
   Double_t BkgRelErr_fx3[42] = { 17.12853, 17.26818, 17.22433, 17.17917, 17.40201, 17.35996, 17.31664, 17.09748, 17.06696, 16.99856, 16.9516, 16.90572, 16.85911, 16.81358, 16.76397, 16.71757, 16.67104,
   16.62377, 16.57698, 16.52852, 16.48146, 16.43395, 16.38631, 17.3367, 17.29449, 17.25071, 17.20592, 17.16429, 17.12077, 17.07475, 17.0289, 16.98232, 16.93562,
   16.88848, 16.84394, 16.79442, 16.74658, 16.698, 16.65049, 16.60224, 16.55508, 17.38262 };
   Double_t BkgRelErr_fy3[42] = { 0.5104576, 0.5082955, 0.5090541, 0.5109432, 0.5074128, 0.5105774, 0.5078865, 0.5148376, 0.5137747, 0.5144188, 0.5472767, 0.5161225, 0.5168726, 0.5163457, 0.5173687, 0.5204433, 0.5201327,
   0.5231428, 0.5286825, 0.5230428, 0.5234398, 0.5271548, 0.5261583, 0.5078837, 0.5129213, 0.5085971, 0.5098213, 0.5115205, 0.5111123, 0.5118927, 0.5128425, 0.512685, 0.5145493,
   0.5164757, 0.5172072, 0.5186982, 0.5201609, 0.5194799, 0.5192839, 0.5206447, 0.522824, 0.5081646 };
   graph = new TGraph(42,BkgRelErr_fx3,BkgRelErr_fy3);
   graph->SetName("BkgRelErr");
   graph->SetTitle("");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#00cc00");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#00cc00");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_Graph_Graph_BkgRelErr33333 = new TH1F("Graph_Graph_Graph_Graph_Graph_BkgRelErr33333","",100,16.28474,17.50358);
   Graph_Graph_Graph_Graph_Graph_BkgRelErr33333->SetMinimum(0.5034264);
   Graph_Graph_Graph_Graph_Graph_BkgRelErr33333->SetMaximum(0.5512631);
   Graph_Graph_Graph_Graph_Graph_BkgRelErr33333->SetDirectory(nullptr);
   Graph_Graph_Graph_Graph_Graph_BkgRelErr33333->SetStats(0);
   Graph_Graph_Graph_Graph_Graph_BkgRelErr33333->SetLineWidth(2);
   Graph_Graph_Graph_Graph_Graph_BkgRelErr33333->SetMarkerStyle(20);
   Graph_Graph_Graph_Graph_Graph_BkgRelErr33333->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_Graph_BkgRelErr33333->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_Graph_Graph_BkgRelErr33333->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_BkgRelErr33333->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph_Graph_Graph_BkgRelErr33333->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_Graph_BkgRelErr33333->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_Graph_Graph_BkgRelErr33333->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_BkgRelErr33333->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_Graph_BkgRelErr33333->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_Graph_Graph_BkgRelErr33333->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_BkgRelErr33333->GetZaxis()->SetTitleOffset(0.7);
   graph->SetHistogram(Graph_Graph_Graph_Graph_Graph_BkgRelErr33333);
   
   graph->Draw("p");
   
   Double_t PoTRelErr_fx4[42] = { 17.12853, 17.26818, 17.22433, 17.17917, 17.40201, 17.35996, 17.31664, 17.09748, 17.06696, 16.99856, 16.9516, 16.90572, 16.85911, 16.81358, 16.76397, 16.71757, 16.67104,
   16.62377, 16.57698, 16.52852, 16.48146, 16.43395, 16.38631, 17.3367, 17.29449, 17.25071, 17.20592, 17.16429, 17.12077, 17.07475, 17.0289, 16.98232, 16.93562,
   16.88848, 16.84394, 16.79442, 16.74658, 16.698, 16.65049, 16.60224, 16.55508, 17.38262 };
   Double_t PoTRelErr_fy4[42] = { 0.4673835, 0.4573214, 0.4421947, 0.4304388, 0.4189339, 0.4086782, 0.3983548, 0.3877394, 0.3773881, 0.3680263, 0.3587433, 0.3499175, 0.3419527, 0.3342922, 0.3278933, 0.3217147, 0.3167152,
   0.3117391, 0.3080453, 0.3046845, 0.3031377, 0.3013459, 0.301029, 0.314398, 0.3189478, 0.3236071, 0.3318053, 0.3383684, 0.3427726, 0.3504042, 0.3573123, 0.3655742, 0.3726954,
   0.3800633, 0.3889397, 0.3980044, 0.4069523, 0.4159029, 0.42518, 0.4339734, 0.4429143, 0.4534531 };
   graph = new TGraph(42,PoTRelErr_fx4,PoTRelErr_fy4);
   graph->SetName("PoTRelErr");
   graph->SetTitle("");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetMarkerColor(2);
   graph->SetMarkerStyle(47);
   
   TH1F *Graph_Graph_Graph_Graph_Graph_PoTRelErr44444 = new TH1F("Graph_Graph_Graph_Graph_Graph_PoTRelErr44444","",100,16.28474,17.50358);
   Graph_Graph_Graph_Graph_Graph_PoTRelErr44444->SetMinimum(0.2843935);
   Graph_Graph_Graph_Graph_Graph_PoTRelErr44444->SetMaximum(0.4840189);
   Graph_Graph_Graph_Graph_Graph_PoTRelErr44444->SetDirectory(nullptr);
   Graph_Graph_Graph_Graph_Graph_PoTRelErr44444->SetStats(0);
   Graph_Graph_Graph_Graph_Graph_PoTRelErr44444->SetLineWidth(2);
   Graph_Graph_Graph_Graph_Graph_PoTRelErr44444->SetMarkerStyle(20);
   Graph_Graph_Graph_Graph_Graph_PoTRelErr44444->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_Graph_PoTRelErr44444->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_Graph_Graph_PoTRelErr44444->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_PoTRelErr44444->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph_Graph_Graph_PoTRelErr44444->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_Graph_PoTRelErr44444->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_Graph_Graph_PoTRelErr44444->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_PoTRelErr44444->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph_Graph_PoTRelErr44444->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_Graph_Graph_PoTRelErr44444->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_PoTRelErr44444->GetZaxis()->SetTitleOffset(0.7);
   graph->SetHistogram(Graph_Graph_Graph_Graph_Graph_PoTRelErr44444);
   
   graph->Draw("p");
   
   TLegend *leg = new TLegend(0.1819484,0.6505263,0.4111748,0.8694737,NULL,"brNDC");
   leg->SetBorderSize(0);

   ci = TColor::GetColor("#000000");
   leg->SetTextColor(ci);
   leg->SetTextSize(0.03984064);

   ci = TColor::GetColor("#000000");
   leg->SetLineColor(ci);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("RRelErr","g_{R}","lpf");
   entry->SetFillStyle(1000);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("NObsRelErr","N_{2}","lpf");
   entry->SetFillStyle(1000);

   ci = TColor::GetColor("#cc33ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#cc33ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("BkgRelErr","B","lpf");
   entry->SetFillStyle(1000);

   ci = TColor::GetColor("#00cc00");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#00cc00");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("PoTRelErr","N_{POT}","lpf");
   entry->SetFillStyle(1000);
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(47);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   leg->Draw();
   TLatex *   tex = new TLatex(17.14465,1.403583,"PADME");
   tex->SetTextSize(0.06736843);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(17.0682,1.371888,"");
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(17.078,1.385176,"");
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(17.10251,1.402893,"");
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(17.02654,1.451616,"");
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(16.94812,1.367458,"");
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(16.99959,1.230148,"");
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(17.11476,1.261154,"");
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(17.2716,1.203572,"");
   tex->SetLineWidth(2);
   tex->Draw();
   relErr->Modified();
   relErr->SetSelected(relErr);
   relErr->ToggleToolBar();

   relErr->Print("RelativeUncorrelatedErrors_gR_ASF.pdf");
}
