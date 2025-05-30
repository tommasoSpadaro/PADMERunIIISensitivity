#ifdef __CLING__
#pragma cling optimize(0)
#endif
void TagAndProbeCorr()
{
//=========Macro generated from canvas: Tag and probe correction/
//=========  (Wed May 28 10:49:31 2025) by ROOT version 6.30/04
   TCanvas *Tag_and_probe_correction = new TCanvas("Tag and probe correction", "",900,66,700,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   Tag_and_probe_correction->Range(0,0,1,1);
   Tag_and_probe_correction->SetFillColor(0);
   Tag_and_probe_correction->SetBorderMode(0);
   Tag_and_probe_correction->SetBorderSize(2);
   Tag_and_probe_correction->SetTickx(1);
   Tag_and_probe_correction->SetTicky(1);
   Tag_and_probe_correction->SetLeftMargin(0.14);
   Tag_and_probe_correction->SetBottomMargin(0.14);
   Tag_and_probe_correction->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: Tag and probe correction_1
   TPad *Tag__0 = new TPad("Tag and probe correction_1", "Tag and probe correction_1",0.01,0.51,0.99,0.99);
   Tag__0->Draw();
   Tag__0->cd();
   Tag__0->Range(-10.60526,0.895222,47.28947,1.084422);
   Tag__0->SetFillColor(0);
   Tag__0->SetBorderMode(0);
   Tag__0->SetBorderSize(2);
   Tag__0->SetTickx(1);
   Tag__0->SetTicky(1);
   Tag__0->SetLeftMargin(0.14);
   Tag__0->SetBottomMargin(0.14);
   Tag__0->SetFrameBorderMode(0);
   Tag__0->SetFrameBorderMode(0);
   
   TH1F *hframe__1 = new TH1F("hframe__1","",1000,-2.5,41.5);
   hframe__1->SetMinimum(0.92171);
   hframe__1->SetMaximum(1.065502);
   hframe__1->SetDirectory(nullptr);
   hframe__1->SetStats(0);
   hframe__1->SetLineWidth(2);
   hframe__1->SetMarkerStyle(20);
   hframe__1->GetXaxis()->SetTitle("Energy point ID");
   hframe__1->GetXaxis()->SetLabelFont(42);
   hframe__1->GetXaxis()->SetLabelSize(0.06);
   hframe__1->GetXaxis()->SetTitleSize(0.06);
   hframe__1->GetXaxis()->SetTitleOffset(1.1);
   hframe__1->GetYaxis()->SetTitle("Tag and probe correction");
   hframe__1->GetYaxis()->SetNdivisions(404);
   hframe__1->GetYaxis()->SetLabelFont(42);
   hframe__1->GetYaxis()->SetLabelSize(0.06);
   hframe__1->GetYaxis()->SetTitleSize(0.06);
   hframe__1->GetYaxis()->SetTitleOffset(0.8);
   hframe__1->GetZaxis()->SetLabelFont(42);
   hframe__1->GetZaxis()->SetLabelSize(0.06);
   hframe__1->GetZaxis()->SetTitleSize(0.06);
   hframe__1->GetZaxis()->SetTitleOffset(0.7);
   hframe__1->Draw(" ");
   
   Double_t gRatioTP_fx1001[42] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
   17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
   33, 34, 35, 36, 37, 38, 39, 40, 41 };
   Double_t gRatioTP_fy1001[42] = { 0.9653157, 0.9821663, 1.040522, 0.9755274, 1.024487, 1.015691, 1.009968, 1.005492, 0.9989658, 0.9862509, 1.023646, 1.004755, 1.025542, 0.9897898, 1.034313, 1.004568, 1.007708,
   1.000844, 1.017439, 0.981537, 0.9743422, 0.9536991, 0.9801878, 1.02941, 1.027122, 0.9675629, 1.033734, 1.014986, 1.012468, 1.023675, 1.016821, 1.002855, 0.9848139,
   0.9860235, 0.974163, 0.9638195, 0.988247, 0.987406, 0.9595034, 0.9618753, 0.9776346, 1.042838 };
   Double_t gRatioTP_fex1001[42] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t gRatioTP_fey1001[42] = { 0.02151043, 0.02410935, 0.02161758, 0.02158431, 0.02286843, 0.02327728, 0.0223906, 0.02183823, 0.02190836, 0.02190175, 0.02289437, 0.02164873, 0.02219269, 0.02172602, 0.02294937, 0.0221836, 0.02219998,
   0.02159703, 0.03320996, 0.03171855, 0.03186191, 0.03057934, 0.03222275, 0.0216081, 0.0217599, 0.02036175, 0.01911124, 0.02158556, 0.02511173, 0.02142916, 0.02191946, 0.02086188, 0.02149863,
   0.02190794, 0.02044428, 0.02014992, 0.02127322, 0.02191492, 0.02075106, 0.02166696, 0.03361209, 0.02125416 };
   TGraphErrors *gre = new TGraphErrors(42,gRatioTP_fx1001,gRatioTP_fy1001,gRatioTP_fex1001,gRatioTP_fey1001);
   gre->SetName("gRatioTP");
   gre->SetTitle("");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(32);
   
   TH1F *Graph_gRatioTP1001 = new TH1F("Graph_gRatioTP1001","",100,0,45.1);
   Graph_gRatioTP1001->SetMinimum(0.9090225);
   Graph_gRatioTP1001->SetMaximum(1.07819);
   Graph_gRatioTP1001->SetDirectory(nullptr);
   Graph_gRatioTP1001->SetStats(0);
   Graph_gRatioTP1001->SetLineWidth(2);
   Graph_gRatioTP1001->SetMarkerStyle(20);
   Graph_gRatioTP1001->GetXaxis()->SetLabelFont(42);
   Graph_gRatioTP1001->GetXaxis()->SetLabelSize(0.06);
   Graph_gRatioTP1001->GetXaxis()->SetTitleSize(0.06);
   Graph_gRatioTP1001->GetXaxis()->SetTitleOffset(1.1);
   Graph_gRatioTP1001->GetYaxis()->SetLabelFont(42);
   Graph_gRatioTP1001->GetYaxis()->SetLabelSize(0.06);
   Graph_gRatioTP1001->GetYaxis()->SetTitleSize(0.06);
   Graph_gRatioTP1001->GetZaxis()->SetLabelFont(42);
   Graph_gRatioTP1001->GetZaxis()->SetLabelSize(0.06);
   Graph_gRatioTP1001->GetZaxis()->SetTitleSize(0.06);
   Graph_gRatioTP1001->GetZaxis()->SetTitleOffset(0.7);
   gre->SetHistogram(Graph_gRatioTP1001);
   
   gre->Draw("p");
   Tag__0->Modified();
   Tag_and_probe_correction->cd();
  
// ------------>Primitives in pad: Tag and probe correction_2
   TPad *Tag__1 = new TPad("Tag and probe correction_2", "Tag and probe correction_2",0.01,0.01,0.99,0.49);
   Tag__1->Draw();
   Tag__1->cd();
   Tag__1->Range(16.14737,0.895222,17.59474,1.084422);
   Tag__1->SetFillColor(0);
   Tag__1->SetBorderMode(0);
   Tag__1->SetBorderSize(2);
   Tag__1->SetTickx(1);
   Tag__1->SetTicky(1);
   Tag__1->SetLeftMargin(0.14);
   Tag__1->SetBottomMargin(0.14);
   Tag__1->SetFrameBorderMode(0);
   Tag__1->SetFrameBorderMode(0);
   
   TH1F *hframe__2 = new TH1F("hframe__2","",1000,16.35,17.45);
   hframe__2->SetMinimum(0.92171);
   hframe__2->SetMaximum(1.065502);
   hframe__2->SetDirectory(nullptr);
   hframe__2->SetStats(0);
   hframe__2->SetLineWidth(2);
   hframe__2->SetMarkerStyle(20);
   hframe__2->GetXaxis()->SetTitle("#sqrt{s} (MeV)");
   hframe__2->GetXaxis()->SetLabelFont(42);
   hframe__2->GetXaxis()->SetLabelSize(0.06);
   hframe__2->GetXaxis()->SetTitleSize(0.06);
   hframe__2->GetXaxis()->SetTitleOffset(1.1);
   hframe__2->GetYaxis()->SetTitle("Tag and probe correction");
   hframe__2->GetYaxis()->SetNdivisions(404);
   hframe__2->GetYaxis()->SetLabelFont(42);
   hframe__2->GetYaxis()->SetLabelSize(0.06);
   hframe__2->GetYaxis()->SetTitleSize(0.06);
   hframe__2->GetYaxis()->SetTitleOffset(0.8);
   hframe__2->GetZaxis()->SetLabelFont(42);
   hframe__2->GetZaxis()->SetLabelSize(0.06);
   hframe__2->GetZaxis()->SetTitleSize(0.06);
   hframe__2->GetZaxis()->SetTitleOffset(0.7);
   hframe__2->Draw(" ");
   
   Double_t Tag_and_probe_correction_fx1002[42] = { 17.12853, 17.26818, 17.22433, 17.17917, 17.40201, 17.35996, 17.31664, 17.09748, 17.06696, 16.99856, 16.9516, 16.90572, 16.85911, 16.81358, 16.76397, 16.71757, 16.67104,
   16.62377, 16.57698, 16.52852, 16.48146, 16.43395, 16.38631, 17.3367, 17.29449, 17.25071, 17.20592, 17.16429, 17.12077, 17.07475, 17.0289, 16.98232, 16.93562,
   16.88848, 16.84394, 16.79442, 16.74658, 16.698, 16.65049, 16.60224, 16.55508, 17.38262 };
   Double_t Tag_and_probe_correction_fy1002[42] = { 0.9653157, 0.9821663, 1.040522, 0.9755274, 1.024487, 1.015691, 1.009968, 1.005492, 0.9989658, 0.9862509, 1.023646, 1.004755, 1.025542, 0.9897898, 1.034313, 1.004568, 1.007708,
   1.000844, 1.017439, 0.981537, 0.9743422, 0.9536991, 0.9801878, 1.02941, 1.027122, 0.9675629, 1.033734, 1.014986, 1.012468, 1.023675, 1.016821, 1.002855, 0.9848139,
   0.9860235, 0.974163, 0.9638195, 0.988247, 0.987406, 0.9595034, 0.9618753, 0.9776346, 1.042838 };
   Double_t Tag_and_probe_correction_fex1002[42] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t Tag_and_probe_correction_fey1002[42] = { 0.02151043, 0.02410935, 0.02161758, 0.02158431, 0.02286843, 0.02327728, 0.0223906, 0.02183823, 0.02190836, 0.02190175, 0.02289437, 0.02164873, 0.02219269, 0.02172602, 0.02294937, 0.0221836, 0.02219998,
   0.02159703, 0.03320996, 0.03171855, 0.03186191, 0.03057934, 0.03222275, 0.0216081, 0.0217599, 0.02036175, 0.01911124, 0.02158556, 0.02511173, 0.02142916, 0.02191946, 0.02086188, 0.02149863,
   0.02190794, 0.02044428, 0.02014992, 0.02127322, 0.02191492, 0.02075106, 0.02166696, 0.03361209, 0.02125416 };
   gre = new TGraphErrors(42,Tag_and_probe_correction_fx1002,Tag_and_probe_correction_fy1002,Tag_and_probe_correction_fex1002,Tag_and_probe_correction_fey1002);
   gre->SetName("Tag and probe correction");
   gre->SetTitle("");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(32);
   
   TH1F *Graph_TagsPandsPprobesPcorrection1002 = new TH1F("Graph_TagsPandsPprobesPcorrection1002","",100,16.28474,17.50358);
   Graph_TagsPandsPprobesPcorrection1002->SetMinimum(0.9090225);
   Graph_TagsPandsPprobesPcorrection1002->SetMaximum(1.07819);
   Graph_TagsPandsPprobesPcorrection1002->SetDirectory(nullptr);
   Graph_TagsPandsPprobesPcorrection1002->SetStats(0);
   Graph_TagsPandsPprobesPcorrection1002->SetLineWidth(2);
   Graph_TagsPandsPprobesPcorrection1002->SetMarkerStyle(20);
   Graph_TagsPandsPprobesPcorrection1002->GetXaxis()->SetLabelFont(42);
   Graph_TagsPandsPprobesPcorrection1002->GetXaxis()->SetLabelSize(0.06);
   Graph_TagsPandsPprobesPcorrection1002->GetXaxis()->SetTitleSize(0.06);
   Graph_TagsPandsPprobesPcorrection1002->GetXaxis()->SetTitleOffset(1.1);
   Graph_TagsPandsPprobesPcorrection1002->GetYaxis()->SetLabelFont(42);
   Graph_TagsPandsPprobesPcorrection1002->GetYaxis()->SetLabelSize(0.06);
   Graph_TagsPandsPprobesPcorrection1002->GetYaxis()->SetTitleSize(0.06);
   Graph_TagsPandsPprobesPcorrection1002->GetZaxis()->SetLabelFont(42);
   Graph_TagsPandsPprobesPcorrection1002->GetZaxis()->SetLabelSize(0.06);
   Graph_TagsPandsPprobesPcorrection1002->GetZaxis()->SetTitleSize(0.06);
   Graph_TagsPandsPprobesPcorrection1002->GetZaxis()->SetTitleOffset(0.7);
   gre->SetHistogram(Graph_TagsPandsPprobesPcorrection1002);
   
   
   TF1 *pol01003 = new TF1("pol0","pol0",16.28474,17.50358, TF1::EAddToList::kNo);
   pol01003->SetFillColor(19);
   pol01003->SetFillStyle(0);
   pol01003->SetMarkerStyle(20);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#cc0000");
   pol01003->SetLineColor(ci);
   pol01003->SetLineWidth(3);
   pol01003->SetChisquare(48.58781);
   pol01003->SetNDF(41);
   pol01003->GetXaxis()->SetLabelFont(42);
   pol01003->GetXaxis()->SetLabelSize(0.06);
   pol01003->GetXaxis()->SetTitleSize(0.06);
   pol01003->GetXaxis()->SetTitleOffset(1.1);
   pol01003->GetYaxis()->SetLabelFont(42);
   pol01003->GetYaxis()->SetLabelSize(0.06);
   pol01003->GetYaxis()->SetTitleSize(0.06);
   pol01003->SetParameter(0,1);
   pol01003->SetParError(0,0.003491389);
   pol01003->SetParLimits(0,0,0);
   pol01003->SetParent(gre);
   gre->GetListOfFunctions()->Add(pol01003);
   
   TPaveStats *ptstats = new TPaveStats(0.6812759,0.2116228,0.8742471,0.3695175,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 48.59 / 41");
   ptstats_LaTex = ptstats->AddText("Prob  = 0.1938");
   ptstats_LaTex = ptstats->AddText("p0       =     1 #pm 0.003491 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("p");
   Tag__1->Modified();
   Tag_and_probe_correction->cd();
   Tag_and_probe_correction->Modified();
   Tag_and_probe_correction->SetSelected(Tag_and_probe_correction);
}
