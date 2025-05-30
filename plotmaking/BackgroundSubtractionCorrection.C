#ifdef __CLING__
#pragma cling optimize(0)
#endif
void BackgroundSubtractionCorrection()
{
//=========Macro generated from canvas: Background subtraction/
//=========  (Wed May 28 10:50:46 2025) by ROOT version 6.30/04
   TCanvas *Background_subtraction = new TCanvas("Background subtraction", "",900,66,700,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   Background_subtraction->Range(0,0,1,1);
   Background_subtraction->SetFillColor(0);
   Background_subtraction->SetBorderMode(0);
   Background_subtraction->SetBorderSize(2);
   Background_subtraction->SetTickx(1);
   Background_subtraction->SetTicky(1);
   Background_subtraction->SetLeftMargin(0.14);
   Background_subtraction->SetBottomMargin(0.14);
   Background_subtraction->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: Background subtraction_1
   TPad *Background__6 = new TPad("Background subtraction_1", "Background subtraction_1",0.01,0.51,0.99,0.99);
   Background__6->Draw();
   Background__6->cd();
   Background__6->Range(-10.60526,0.9790273,47.28947,1.014084);
   Background__6->SetFillColor(0);
   Background__6->SetBorderMode(0);
   Background__6->SetBorderSize(2);
   Background__6->SetTickx(1);
   Background__6->SetTicky(1);
   Background__6->SetLeftMargin(0.14);
   Background__6->SetBottomMargin(0.14);
   Background__6->SetFrameBorderMode(0);
   Background__6->SetFrameBorderMode(0);
   
   TH1F *hframe__7 = new TH1F("hframe__7","",1000,-2.5,41.5);
   hframe__7->SetMinimum(0.9839352);
   hframe__7->SetMaximum(1.010578);
   hframe__7->SetDirectory(nullptr);
   hframe__7->SetStats(0);
   hframe__7->SetLineWidth(2);
   hframe__7->SetMarkerStyle(20);
   hframe__7->GetXaxis()->SetTitle("Energy point ID");
   hframe__7->GetXaxis()->SetLabelFont(42);
   hframe__7->GetXaxis()->SetLabelSize(0.06);
   hframe__7->GetXaxis()->SetTitleSize(0.06);
   hframe__7->GetXaxis()->SetTitleOffset(1.1);
   hframe__7->GetYaxis()->SetTitle("Background subtraction");
   hframe__7->GetYaxis()->SetNdivisions(404);
   hframe__7->GetYaxis()->SetLabelFont(42);
   hframe__7->GetYaxis()->SetLabelSize(0.06);
   hframe__7->GetYaxis()->SetTitleSize(0.06);
   hframe__7->GetYaxis()->SetTitleOffset(0.8);
   hframe__7->GetZaxis()->SetLabelFont(42);
   hframe__7->GetZaxis()->SetLabelSize(0.06);
   hframe__7->GetZaxis()->SetTitleSize(0.06);
   hframe__7->GetZaxis()->SetTitleOffset(0.7);
   hframe__7->Draw(" ");
   
   Double_t gN2NoBkgOvN2_fx1009[42] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
   17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
   33, 34, 35, 36, 37, 38, 39, 40, 41 };
   Double_t gN2NoBkgOvN2_fy1009[42] = { 1.003312, 1.003824, 0.999191, 0.9943999, 1.004546, 1.000374, 0.9881919, 1.002374, 1.003613, 1.00118, 0.9969095, 0.9999726, 0.9985126, 0.9932358, 1.000578, 0.9985634, 0.9985533,
   1.006968, 1.005861, 1.008901, 1.005486, 1.008066, 1.004688, 0.9994277, 0.9941543, 0.9995586, 0.9930887, 0.9961398, 0.9976745, 0.9941725, 0.9975303, 0.990504, 0.9980961,
   1.000101, 1.003376, 1.002899, 0.9957205, 1.008855, 1.001578, 0.9935611, 1.008643, 0.9857681 };
   Double_t gN2NoBkgOvN2_fex1009[42] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t gN2NoBkgOvN2_fey1009[42] = { 0.001489397, 0.00170805, 0.001417364, 0.001628151, 0.001513137, 0.001619333, 0.001713477, 0.001485108, 0.001518152, 0.001545351, 0.001579884, 0.001526794, 0.001549593, 0.001618943, 0.001571236, 0.001586538, 0.00159699,
   0.001433569, 0.001448286, 0.001400491, 0.00146977, 0.001393983, 0.001478853, 0.001475908, 0.001523525, 0.001504538, 0.001301928, 0.001528547, 0.001851356, 0.001535436, 0.001555379, 0.00156108, 0.001594073,
   0.001595102, 0.001464199, 0.001430482, 0.00158141, 0.001462214, 0.001521954, 0.001650745, 0.001514388, 0.001571775 };
   TGraphErrors *gre = new TGraphErrors(42,gN2NoBkgOvN2_fx1009,gN2NoBkgOvN2_fy1009,gN2NoBkgOvN2_fex1009,gN2NoBkgOvN2_fey1009);
   gre->SetName("gN2NoBkgOvN2");
   gre->SetTitle("");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_gN2NoBkgOvN21009 = new TH1F("Graph_gN2NoBkgOvN21009","",100,0,45.1);
   Graph_gN2NoBkgOvN21009->SetMinimum(0.9815843);
   Graph_gN2NoBkgOvN21009->SetMaximum(1.012929);
   Graph_gN2NoBkgOvN21009->SetDirectory(nullptr);
   Graph_gN2NoBkgOvN21009->SetStats(0);
   Graph_gN2NoBkgOvN21009->SetLineWidth(2);
   Graph_gN2NoBkgOvN21009->SetMarkerStyle(20);
   Graph_gN2NoBkgOvN21009->GetXaxis()->SetLabelFont(42);
   Graph_gN2NoBkgOvN21009->GetXaxis()->SetLabelSize(0.06);
   Graph_gN2NoBkgOvN21009->GetXaxis()->SetTitleSize(0.06);
   Graph_gN2NoBkgOvN21009->GetXaxis()->SetTitleOffset(1.1);
   Graph_gN2NoBkgOvN21009->GetYaxis()->SetLabelFont(42);
   Graph_gN2NoBkgOvN21009->GetYaxis()->SetLabelSize(0.06);
   Graph_gN2NoBkgOvN21009->GetYaxis()->SetTitleSize(0.06);
   Graph_gN2NoBkgOvN21009->GetZaxis()->SetLabelFont(42);
   Graph_gN2NoBkgOvN21009->GetZaxis()->SetLabelSize(0.06);
   Graph_gN2NoBkgOvN21009->GetZaxis()->SetTitleSize(0.06);
   Graph_gN2NoBkgOvN21009->GetZaxis()->SetTitleOffset(0.7);
   gre->SetHistogram(Graph_gN2NoBkgOvN21009);
   
   gre->Draw("p");
   Background__6->Modified();
   Background_subtraction->cd();
  
// ------------>Primitives in pad: Background subtraction_2
   TPad *Background__7 = new TPad("Background subtraction_2", "Background subtraction_2",0.01,0.01,0.99,0.49);
   Background__7->Draw();
   Background__7->cd();
   Background__7->Range(16.14737,0.9790273,17.59474,1.014084);
   Background__7->SetFillColor(0);
   Background__7->SetBorderMode(0);
   Background__7->SetBorderSize(2);
   Background__7->SetTickx(1);
   Background__7->SetTicky(1);
   Background__7->SetLeftMargin(0.14);
   Background__7->SetBottomMargin(0.14);
   Background__7->SetFrameBorderMode(0);
   Background__7->SetFrameBorderMode(0);
   
   TH1F *hframe__8 = new TH1F("hframe__8","",1000,16.35,17.45);
   hframe__8->SetMinimum(0.9839352);
   hframe__8->SetMaximum(1.010578);
   hframe__8->SetDirectory(nullptr);
   hframe__8->SetStats(0);
   hframe__8->SetLineWidth(2);
   hframe__8->SetMarkerStyle(20);
   hframe__8->GetXaxis()->SetTitle("#sqrt{s} (MeV)");
   hframe__8->GetXaxis()->SetLabelFont(42);
   hframe__8->GetXaxis()->SetLabelSize(0.06);
   hframe__8->GetXaxis()->SetTitleSize(0.06);
   hframe__8->GetXaxis()->SetTitleOffset(1.1);
   hframe__8->GetYaxis()->SetTitle("Background subtraction");
   hframe__8->GetYaxis()->SetNdivisions(404);
   hframe__8->GetYaxis()->SetLabelFont(42);
   hframe__8->GetYaxis()->SetLabelSize(0.06);
   hframe__8->GetYaxis()->SetTitleSize(0.06);
   hframe__8->GetYaxis()->SetTitleOffset(0.8);
   hframe__8->GetZaxis()->SetLabelFont(42);
   hframe__8->GetZaxis()->SetLabelSize(0.06);
   hframe__8->GetZaxis()->SetTitleSize(0.06);
   hframe__8->GetZaxis()->SetTitleOffset(0.7);
   hframe__8->Draw(" ");
   
   Double_t Background_subtraction_fx1010[42] = { 17.12853, 17.26818, 17.22433, 17.17917, 17.40201, 17.35996, 17.31664, 17.09748, 17.06696, 16.99856, 16.9516, 16.90572, 16.85911, 16.81358, 16.76397, 16.71757, 16.67104,
   16.62377, 16.57698, 16.52852, 16.48146, 16.43395, 16.38631, 17.3367, 17.29449, 17.25071, 17.20592, 17.16429, 17.12077, 17.07475, 17.0289, 16.98232, 16.93562,
   16.88848, 16.84394, 16.79442, 16.74658, 16.698, 16.65049, 16.60224, 16.55508, 17.38262 };
   Double_t Background_subtraction_fy1010[42] = { 1.003312, 1.003824, 0.999191, 0.9943999, 1.004546, 1.000374, 0.9881919, 1.002374, 1.003613, 1.00118, 0.9969095, 0.9999726, 0.9985126, 0.9932358, 1.000578, 0.9985634, 0.9985533,
   1.006968, 1.005861, 1.008901, 1.005486, 1.008066, 1.004688, 0.9994277, 0.9941543, 0.9995586, 0.9930887, 0.9961398, 0.9976745, 0.9941725, 0.9975303, 0.990504, 0.9980961,
   1.000101, 1.003376, 1.002899, 0.9957205, 1.008855, 1.001578, 0.9935611, 1.008643, 0.9857681 };
   Double_t Background_subtraction_fex1010[42] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t Background_subtraction_fey1010[42] = { 0.001489397, 0.00170805, 0.001417364, 0.001628151, 0.001513137, 0.001619333, 0.001713477, 0.001485108, 0.001518152, 0.001545351, 0.001579884, 0.001526794, 0.001549593, 0.001618943, 0.001571236, 0.001586538, 0.00159699,
   0.001433569, 0.001448286, 0.001400491, 0.00146977, 0.001393983, 0.001478853, 0.001475908, 0.001523525, 0.001504538, 0.001301928, 0.001528547, 0.001851356, 0.001535436, 0.001555379, 0.00156108, 0.001594073,
   0.001595102, 0.001464199, 0.001430482, 0.00158141, 0.001462214, 0.001521954, 0.001650745, 0.001514388, 0.001571775 };
   gre = new TGraphErrors(42,Background_subtraction_fx1010,Background_subtraction_fy1010,Background_subtraction_fex1010,Background_subtraction_fey1010);
   gre->SetName("Background subtraction");
   gre->SetTitle("");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_BackgroundsPsubtraction1010 = new TH1F("Graph_BackgroundsPsubtraction1010","",100,16.28474,17.50358);
   Graph_BackgroundsPsubtraction1010->SetMinimum(0.9815843);
   Graph_BackgroundsPsubtraction1010->SetMaximum(1.012929);
   Graph_BackgroundsPsubtraction1010->SetDirectory(nullptr);
   Graph_BackgroundsPsubtraction1010->SetStats(0);
   Graph_BackgroundsPsubtraction1010->SetLineWidth(2);
   Graph_BackgroundsPsubtraction1010->SetMarkerStyle(20);
   Graph_BackgroundsPsubtraction1010->GetXaxis()->SetLabelFont(42);
   Graph_BackgroundsPsubtraction1010->GetXaxis()->SetLabelSize(0.06);
   Graph_BackgroundsPsubtraction1010->GetXaxis()->SetTitleSize(0.06);
   Graph_BackgroundsPsubtraction1010->GetXaxis()->SetTitleOffset(1.1);
   Graph_BackgroundsPsubtraction1010->GetYaxis()->SetLabelFont(42);
   Graph_BackgroundsPsubtraction1010->GetYaxis()->SetLabelSize(0.06);
   Graph_BackgroundsPsubtraction1010->GetYaxis()->SetTitleSize(0.06);
   Graph_BackgroundsPsubtraction1010->GetZaxis()->SetLabelFont(42);
   Graph_BackgroundsPsubtraction1010->GetZaxis()->SetLabelSize(0.06);
   Graph_BackgroundsPsubtraction1010->GetZaxis()->SetTitleSize(0.06);
   Graph_BackgroundsPsubtraction1010->GetZaxis()->SetTitleOffset(0.7);
   gre->SetHistogram(Graph_BackgroundsPsubtraction1010);
   
   gre->Draw("p");
   Background__7->Modified();
   Background_subtraction->cd();
   Background_subtraction->Modified();
   Background_subtraction->SetSelected(Background_subtraction);
}
