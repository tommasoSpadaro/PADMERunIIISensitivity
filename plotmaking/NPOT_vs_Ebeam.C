#ifdef __CLING__
#pragma cling optimize(0)
#endif
void NPOT_vs_Ebeam()
{
//=========Macro generated from canvas: dpotvse/
//=========  (Wed May 28 10:54:19 2025) by ROOT version 6.30/04
   TCanvas *dpotvse = new TCanvas("dpotvse", "",900,66,700,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   dpotvse->Range(143.7322,3.285468e+09,453.0164,1.257802e+10);
   dpotvse->SetFillColor(0);
   dpotvse->SetBorderMode(0);
   dpotvse->SetBorderSize(2);
   dpotvse->SetTickx(1);
   dpotvse->SetTicky(1);
   dpotvse->SetLeftMargin(0.14);
   dpotvse->SetBottomMargin(0.14);
   dpotvse->SetFrameBorderMode(0);
   dpotvse->SetFrameBorderMode(0);
   
   Double_t PoTAllVsE_fx1011[48] = { 286.56, 291.26, 289.78, 288.26, 295.8, 294.37, 292.9, 285.52, 284.5, 282.22, 280.66, 279.14, 277.6, 276.1, 274.47, 272.95, 271.43,
   269.89, 268.37, 266.8, 265.28, 263.75, 262.22, 212.68, 211.15, 209.63, 208.13, 206.62, 293.58, 292.15, 290.67, 289.16, 287.76,
   286.3, 284.76, 283.23, 281.68, 280.13, 278.57, 277.1, 275.47, 273.9, 272.31, 270.76, 269.19, 267.66, 295.14, 402.5 };
   Double_t PoTAllVsE_fy1011[48] = { 7.177496e+09, 5.495632e+09, 8.60961e+09, 7.042745e+09, 6.850275e+09, 6.440966e+09, 6.82709e+09, 7.567236e+09, 7.106035e+09, 7.142731e+09, 7.407724e+09, 7.489155e+09, 7.509417e+09, 7.504692e+09, 7.134826e+09, 7.268142e+09, 7.309886e+09,
   7.87038e+09, 7.913497e+09, 8.031218e+09, 7.769472e+09, 8.384433e+09, 7.933993e+09, 7.340557e+09, 7.417552e+09, 8.244527e+09, 6.789417e+09, 6.316295e+09, 7.736658e+09, 7.940971e+09, 7.522374e+09, 1.102366e+10, 7.747938e+09,
   5.192753e+09, 7.905784e+09, 7.315968e+09, 8.125177e+09, 6.927492e+09, 6.881361e+09, 7.762412e+09, 8.200674e+09, 7.678648e+09, 7.218528e+09, 7.622823e+09, 7.365095e+09, 6.822665e+09, 8.356703e+09, 1.1e+10 };
   Double_t PoTAllVsE_fex1011[48] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t PoTAllVsE_fey1011[48] = { 3.354643e+07, 2.51327e+07, 3.807124e+07, 3.031471e+07, 2.869812e+07, 2.632282e+07, 2.719604e+07, 2.934115e+07, 2.681733e+07, 2.628713e+07, 2.657471e+07, 2.620587e+07, 2.567865e+07, 2.50876e+07, 2.339461e+07, 2.338268e+07, 2.315152e+07,
   2.453505e+07, 2.437715e+07, 2.446988e+07, 2.35522e+07, 2.526614e+07, 2.388362e+07, 2.224892e+07, 2.24923e+07, 2.520295e+07, 2.089382e+07, 1.961421e+07, 2.43239e+07, 2.532755e+07, 2.434294e+07, 3.657709e+07, 2.621657e+07,
   1.779934e+07, 2.77022e+07, 2.614086e+07, 2.970355e+07, 2.581844e+07, 2.615353e+07, 3.01911e+07, 3.263904e+07, 3.124844e+07, 3.002207e+07, 3.241072e+07, 3.196255e+07, 3.021856e+07, 3.789373e+07, 3.3e+07 };
   TGraphErrors *gre = new TGraphErrors(48,PoTAllVsE_fx1011,PoTAllVsE_fy1011,PoTAllVsE_fex1011,PoTAllVsE_fey1011);
   gre->SetName("PoTAllVsE");
   gre->SetTitle(";E_{Beam} (MeV);N_{PoT}");
   gre->SetFillStyle(1000);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_PoTAllVsE1011 = new TH1F("Graph_PoTAllVsE1011","",100,187.032,422.088);
   Graph_PoTAllVsE1011->SetMinimum(4.586425e+09);
   Graph_PoTAllVsE1011->SetMaximum(1.164876e+10);
   Graph_PoTAllVsE1011->SetDirectory(nullptr);
   Graph_PoTAllVsE1011->SetStats(0);
   Graph_PoTAllVsE1011->SetLineWidth(2);
   Graph_PoTAllVsE1011->SetMarkerStyle(20);
   Graph_PoTAllVsE1011->GetXaxis()->SetTitle("E_{Beam} (MeV)");
   Graph_PoTAllVsE1011->GetXaxis()->SetLabelFont(42);
   Graph_PoTAllVsE1011->GetXaxis()->SetLabelSize(0.06);
   Graph_PoTAllVsE1011->GetXaxis()->SetTitleSize(0.06);
   Graph_PoTAllVsE1011->GetXaxis()->SetTitleOffset(1.1);
   Graph_PoTAllVsE1011->GetYaxis()->SetTitle("N_{PoT}");
   Graph_PoTAllVsE1011->GetYaxis()->SetLabelFont(42);
   Graph_PoTAllVsE1011->GetYaxis()->SetLabelSize(0.06);
   Graph_PoTAllVsE1011->GetYaxis()->SetTitleSize(0.06);
   Graph_PoTAllVsE1011->GetYaxis()->SetTitleOffset(0.9);
   Graph_PoTAllVsE1011->GetZaxis()->SetLabelFont(42);
   Graph_PoTAllVsE1011->GetZaxis()->SetLabelSize(0.06);
   Graph_PoTAllVsE1011->GetZaxis()->SetTitleSize(0.06);
   Graph_PoTAllVsE1011->GetZaxis()->SetTitleOffset(0.7);
   gre->SetHistogram(Graph_PoTAllVsE1011);
   
   gre->Draw("ap");
   
   Double_t PoTAllVsEBelowRes_fx1012[5] = { 212.68, 211.15, 209.63, 208.13, 206.62 };
   Double_t PoTAllVsEBelowRes_fy1012[5] = { 7.340557e+09, 7.417552e+09, 8.244527e+09, 6.789417e+09, 6.316295e+09 };
   Double_t PoTAllVsEBelowRes_fex1012[5] = { 0, 0, 0, 0, 0 };
   Double_t PoTAllVsEBelowRes_fey1012[5] = { 2.224892e+07, 2.24923e+07, 2.520295e+07, 2.089382e+07, 1.961421e+07 };
   gre = new TGraphErrors(5,PoTAllVsEBelowRes_fx1012,PoTAllVsEBelowRes_fy1012,PoTAllVsEBelowRes_fex1012,PoTAllVsEBelowRes_fey1012);
   gre->SetName("PoTAllVsEBelowRes");
   gre->SetTitle("");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#00ff00");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_PoTAllVsEBelowRes1012 = new TH1F("Graph_PoTAllVsEBelowRes1012","",100,206.014,213.286);
   Graph_PoTAllVsEBelowRes1012->SetMinimum(6.099375e+09);
   Graph_PoTAllVsEBelowRes1012->SetMaximum(8.467035e+09);
   Graph_PoTAllVsEBelowRes1012->SetDirectory(nullptr);
   Graph_PoTAllVsEBelowRes1012->SetStats(0);
   Graph_PoTAllVsEBelowRes1012->SetLineWidth(2);
   Graph_PoTAllVsEBelowRes1012->SetMarkerStyle(20);
   Graph_PoTAllVsEBelowRes1012->GetXaxis()->SetLabelFont(42);
   Graph_PoTAllVsEBelowRes1012->GetXaxis()->SetLabelSize(0.06);
   Graph_PoTAllVsEBelowRes1012->GetXaxis()->SetTitleSize(0.06);
   Graph_PoTAllVsEBelowRes1012->GetXaxis()->SetTitleOffset(1.1);
   Graph_PoTAllVsEBelowRes1012->GetYaxis()->SetLabelFont(42);
   Graph_PoTAllVsEBelowRes1012->GetYaxis()->SetLabelSize(0.06);
   Graph_PoTAllVsEBelowRes1012->GetYaxis()->SetTitleSize(0.06);
   Graph_PoTAllVsEBelowRes1012->GetZaxis()->SetLabelFont(42);
   Graph_PoTAllVsEBelowRes1012->GetZaxis()->SetLabelSize(0.06);
   Graph_PoTAllVsEBelowRes1012->GetZaxis()->SetTitleSize(0.06);
   Graph_PoTAllVsEBelowRes1012->GetZaxis()->SetTitleOffset(0.7);
   gre->SetHistogram(Graph_PoTAllVsEBelowRes1012);
   
   gre->Draw("p");
   
   Double_t PoTAllVsEAboveRes_fx1013[48] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 402.5 };
   Double_t PoTAllVsEAboveRes_fy1013[48] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.1e+10 };
   Double_t PoTAllVsEAboveRes_fex1013[48] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t PoTAllVsEAboveRes_fey1013[48] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3.3e+07 };
   gre = new TGraphErrors(48,PoTAllVsEAboveRes_fx1013,PoTAllVsEAboveRes_fy1013,PoTAllVsEAboveRes_fex1013,PoTAllVsEAboveRes_fey1013);
   gre->SetName("PoTAllVsEAboveRes");
   gre->SetTitle("");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_PoTAllVsEAboveRes1013 = new TH1F("Graph_PoTAllVsEAboveRes1013","",100,0,442.75);
   Graph_PoTAllVsEAboveRes1013->SetMinimum(0);
   Graph_PoTAllVsEAboveRes1013->SetMaximum(1.21363e+10);
   Graph_PoTAllVsEAboveRes1013->SetDirectory(nullptr);
   Graph_PoTAllVsEAboveRes1013->SetStats(0);
   Graph_PoTAllVsEAboveRes1013->SetLineWidth(2);
   Graph_PoTAllVsEAboveRes1013->SetMarkerStyle(20);
   Graph_PoTAllVsEAboveRes1013->GetXaxis()->SetLabelFont(42);
   Graph_PoTAllVsEAboveRes1013->GetXaxis()->SetLabelSize(0.06);
   Graph_PoTAllVsEAboveRes1013->GetXaxis()->SetTitleSize(0.06);
   Graph_PoTAllVsEAboveRes1013->GetXaxis()->SetTitleOffset(1.1);
   Graph_PoTAllVsEAboveRes1013->GetYaxis()->SetLabelFont(42);
   Graph_PoTAllVsEAboveRes1013->GetYaxis()->SetLabelSize(0.06);
   Graph_PoTAllVsEAboveRes1013->GetYaxis()->SetTitleSize(0.06);
   Graph_PoTAllVsEAboveRes1013->GetZaxis()->SetLabelFont(42);
   Graph_PoTAllVsEAboveRes1013->GetZaxis()->SetLabelSize(0.06);
   Graph_PoTAllVsEAboveRes1013->GetZaxis()->SetTitleSize(0.06);
   Graph_PoTAllVsEAboveRes1013->GetZaxis()->SetTitleOffset(0.7);
   gre->SetHistogram(Graph_PoTAllVsEAboveRes1013);
   
   gre->Draw("p");
   dpotvse->Modified();
   dpotvse->SetSelected(dpotvse);
}
