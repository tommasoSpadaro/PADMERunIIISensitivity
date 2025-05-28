#ifdef __CLING__
#pragma cling optimize(0)
#endif
void RelativeUncorrelatedErrors_gR()
{
//=========Macro generated from canvas: relErr/
//=========  (Tue May 27 15:57:50 2025) by ROOT version 6.30/04
   TCanvas *relErr = new TCanvas("relErr", "",900,66,700,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   relErr->Range(15.96053,-0.2763158,17.67105,1.697368);
   relErr->SetFillColor(0);
   relErr->SetBorderMode(0);
   relErr->SetBorderSize(2);
   relErr->SetTickx(1);
   relErr->SetTicky(1);
   relErr->SetLeftMargin(0.14);
   relErr->SetBottomMargin(0.14);
   relErr->SetFrameBorderMode(0);
   relErr->SetFrameBorderMode(0);
   
   TH1F *hframe__1 = new TH1F("hframe__1","",1000,16.2,17.5);
   hframe__1->SetMinimum(0);
   hframe__1->SetMaximum(1.5);
   hframe__1->SetDirectory(nullptr);
   hframe__1->SetStats(0);
   hframe__1->SetLineWidth(2);
   hframe__1->SetMarkerStyle(20);
   hframe__1->GetXaxis()->SetTitle("#sqrt{s} (MeV)");
   hframe__1->GetXaxis()->SetLabelFont(42);
   hframe__1->GetXaxis()->SetLabelOffset(0.006);
   hframe__1->GetXaxis()->SetLabelSize(0.06);
   hframe__1->GetXaxis()->SetTitleSize(0.06);
   hframe__1->GetXaxis()->SetTitleOffset(1.1);
   hframe__1->GetYaxis()->SetTitle("Relative error, %");
   hframe__1->GetYaxis()->SetLabelFont(42);
   hframe__1->GetYaxis()->SetLabelSize(0.06);
   hframe__1->GetYaxis()->SetTitleSize(0.06);
   hframe__1->GetYaxis()->SetTitleOffset(1);
   hframe__1->GetZaxis()->SetLabelFont(42);
   hframe__1->GetZaxis()->SetLabelSize(0.06);
   hframe__1->GetZaxis()->SetTitleSize(0.06);
   hframe__1->GetZaxis()->SetTitleOffset(0.7);
   hframe__1->Draw(" ");
   
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
   
   TH1F *Graph_RRelErr1 = new TH1F("Graph_RRelErr1","",100,16.28474,17.50358);
   Graph_RRelErr1->SetMinimum(0.763718);
   Graph_RRelErr1->SetMaximum(0.9977281);
   Graph_RRelErr1->SetDirectory(nullptr);
   Graph_RRelErr1->SetStats(0);
   Graph_RRelErr1->SetLineWidth(2);
   Graph_RRelErr1->SetMarkerStyle(20);
   Graph_RRelErr1->GetXaxis()->SetLabelFont(42);
   Graph_RRelErr1->GetXaxis()->SetLabelSize(0.06);
   Graph_RRelErr1->GetXaxis()->SetTitleSize(0.06);
   Graph_RRelErr1->GetXaxis()->SetTitleOffset(1.1);
   Graph_RRelErr1->GetYaxis()->SetLabelFont(42);
   Graph_RRelErr1->GetYaxis()->SetLabelSize(0.06);
   Graph_RRelErr1->GetYaxis()->SetTitleSize(0.06);
   Graph_RRelErr1->GetZaxis()->SetLabelFont(42);
   Graph_RRelErr1->GetZaxis()->SetLabelSize(0.06);
   Graph_RRelErr1->GetZaxis()->SetTitleSize(0.06);
   Graph_RRelErr1->GetZaxis()->SetTitleOffset(0.7);
   graph->SetHistogram(Graph_RRelErr1);
   
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
   
   TH1F *Graph_NObsRelErr2 = new TH1F("Graph_NObsRelErr2","",100,16.28474,17.50358);
   Graph_NObsRelErr2->SetMinimum(0.4703081);
   Graph_NObsRelErr2->SetMaximum(0.7471149);
   Graph_NObsRelErr2->SetDirectory(nullptr);
   Graph_NObsRelErr2->SetStats(0);
   Graph_NObsRelErr2->SetLineWidth(2);
   Graph_NObsRelErr2->SetMarkerStyle(20);
   Graph_NObsRelErr2->GetXaxis()->SetLabelFont(42);
   Graph_NObsRelErr2->GetXaxis()->SetLabelSize(0.06);
   Graph_NObsRelErr2->GetXaxis()->SetTitleSize(0.06);
   Graph_NObsRelErr2->GetXaxis()->SetTitleOffset(1.1);
   Graph_NObsRelErr2->GetYaxis()->SetLabelFont(42);
   Graph_NObsRelErr2->GetYaxis()->SetLabelSize(0.06);
   Graph_NObsRelErr2->GetYaxis()->SetTitleSize(0.06);
   Graph_NObsRelErr2->GetZaxis()->SetLabelFont(42);
   Graph_NObsRelErr2->GetZaxis()->SetLabelSize(0.06);
   Graph_NObsRelErr2->GetZaxis()->SetTitleSize(0.06);
   Graph_NObsRelErr2->GetZaxis()->SetTitleOffset(0.7);
   graph->SetHistogram(Graph_NObsRelErr2);
   
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
   
   TH1F *Graph_BkgRelErr3 = new TH1F("Graph_BkgRelErr3","",100,16.28474,17.50358);
   Graph_BkgRelErr3->SetMinimum(0.5034264);
   Graph_BkgRelErr3->SetMaximum(0.5512631);
   Graph_BkgRelErr3->SetDirectory(nullptr);
   Graph_BkgRelErr3->SetStats(0);
   Graph_BkgRelErr3->SetLineWidth(2);
   Graph_BkgRelErr3->SetMarkerStyle(20);
   Graph_BkgRelErr3->GetXaxis()->SetLabelFont(42);
   Graph_BkgRelErr3->GetXaxis()->SetLabelSize(0.06);
   Graph_BkgRelErr3->GetXaxis()->SetTitleSize(0.06);
   Graph_BkgRelErr3->GetXaxis()->SetTitleOffset(1.1);
   Graph_BkgRelErr3->GetYaxis()->SetLabelFont(42);
   Graph_BkgRelErr3->GetYaxis()->SetLabelSize(0.06);
   Graph_BkgRelErr3->GetYaxis()->SetTitleSize(0.06);
   Graph_BkgRelErr3->GetZaxis()->SetLabelFont(42);
   Graph_BkgRelErr3->GetZaxis()->SetLabelSize(0.06);
   Graph_BkgRelErr3->GetZaxis()->SetTitleSize(0.06);
   Graph_BkgRelErr3->GetZaxis()->SetTitleOffset(0.7);
   graph->SetHistogram(Graph_BkgRelErr3);
   
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

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(47);
   
   TH1F *Graph_PoTRelErr4 = new TH1F("Graph_PoTRelErr4","",100,16.28474,17.50358);
   Graph_PoTRelErr4->SetMinimum(0.2843935);
   Graph_PoTRelErr4->SetMaximum(0.4840189);
   Graph_PoTRelErr4->SetDirectory(nullptr);
   Graph_PoTRelErr4->SetStats(0);
   Graph_PoTRelErr4->SetLineWidth(2);
   Graph_PoTRelErr4->SetMarkerStyle(20);
   Graph_PoTRelErr4->GetXaxis()->SetLabelFont(42);
   Graph_PoTRelErr4->GetXaxis()->SetLabelSize(0.06);
   Graph_PoTRelErr4->GetXaxis()->SetTitleSize(0.06);
   Graph_PoTRelErr4->GetXaxis()->SetTitleOffset(1.1);
   Graph_PoTRelErr4->GetYaxis()->SetLabelFont(42);
   Graph_PoTRelErr4->GetYaxis()->SetLabelSize(0.06);
   Graph_PoTRelErr4->GetYaxis()->SetTitleSize(0.06);
   Graph_PoTRelErr4->GetZaxis()->SetLabelFont(42);
   Graph_PoTRelErr4->GetZaxis()->SetLabelSize(0.06);
   Graph_PoTRelErr4->GetZaxis()->SetTitleSize(0.06);
   Graph_PoTRelErr4->GetZaxis()->SetTitleOffset(0.7);
   graph->SetHistogram(Graph_PoTRelErr4);
   
   graph->Draw("p");
   
   TLegend *leg = new TLegend(0.2,0.68,0.43,0.88,NULL,"brNDC");
   leg->SetTextFont(62);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
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
   entry=leg->AddEntry("PoTRelErr","N_{PoT}","lpf");
   entry->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ff0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(47);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   leg->Draw();
   relErr->Modified();
   relErr->SetSelected(relErr);
}
