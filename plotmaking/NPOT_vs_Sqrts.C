#ifdef __CLING__
#pragma cling optimize(0)
#endif
void NPOT_vs_Sqrts()
{
//=========Macro generated from canvas: dpotvssqrts/
//=========  (Wed May 28 10:55:07 2025) by ROOT version 6.30/04
   TCanvas *dpotvssqrts = new TCanvas("dpotvssqrts", "",900,66,700,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   dpotvssqrts->Range(12.70497,3.285468e+09,21.77643,1.257802e+10);
   dpotvssqrts->SetFillColor(0);
   dpotvssqrts->SetBorderMode(0);
   dpotvssqrts->SetBorderSize(2);
   dpotvssqrts->SetTickx(1);
   dpotvssqrts->SetTicky(1);
   dpotvssqrts->SetLeftMargin(0.14);
   dpotvssqrts->SetBottomMargin(0.14);
   dpotvssqrts->SetFrameBorderMode(0);
   dpotvssqrts->SetFrameBorderMode(0);
   
   Double_t PoTAllVsSqrts_fx1014[48] = { 17.12853, 17.26818, 17.22433, 17.17917, 17.40201, 17.35996, 17.31664, 17.09748, 17.06696, 16.99856, 16.9516, 16.90572, 16.85911, 16.81358, 16.76397, 16.71757, 16.67104,
   16.62377, 16.57698, 16.52852, 16.48146, 16.43395, 16.38631, 14.7608, 14.70774, 14.65483, 14.60243, 14.5495, 17.3367, 17.29449, 17.25071, 17.20592, 17.16429,
   17.12077, 17.07475, 17.0289, 16.98232, 16.93562, 16.88848, 16.84394, 16.79442, 16.74658, 16.698, 16.65049, 16.60224, 16.55508, 17.38262, 20.29476 };
   Double_t PoTAllVsSqrts_fy1014[48] = { 7.177496e+09, 5.495632e+09, 8.60961e+09, 7.042745e+09, 6.850275e+09, 6.440966e+09, 6.82709e+09, 7.567236e+09, 7.106035e+09, 7.142731e+09, 7.407724e+09, 7.489155e+09, 7.509417e+09, 7.504692e+09, 7.134826e+09, 7.268142e+09, 7.309886e+09,
   7.87038e+09, 7.913497e+09, 8.031218e+09, 7.769472e+09, 8.384433e+09, 7.933993e+09, 7.340557e+09, 7.417552e+09, 8.244527e+09, 6.789417e+09, 6.316295e+09, 7.736658e+09, 7.940971e+09, 7.522374e+09, 1.102366e+10, 7.747938e+09,
   5.192753e+09, 7.905784e+09, 7.315968e+09, 8.125177e+09, 6.927492e+09, 6.881361e+09, 7.762412e+09, 8.200674e+09, 7.678648e+09, 7.218528e+09, 7.622823e+09, 7.365095e+09, 6.822665e+09, 8.356703e+09, 1.1e+10 };
   Double_t PoTAllVsSqrts_fex1014[48] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t PoTAllVsSqrts_fey1014[48] = { 3.354643e+07, 2.51327e+07, 3.807124e+07, 3.031471e+07, 2.869812e+07, 2.632282e+07, 2.719604e+07, 2.934115e+07, 2.681733e+07, 2.628713e+07, 2.657471e+07, 2.620587e+07, 2.567865e+07, 2.50876e+07, 2.339461e+07, 2.338268e+07, 2.315152e+07,
   2.453505e+07, 2.437715e+07, 2.446988e+07, 2.35522e+07, 2.526614e+07, 2.388362e+07, 2.224892e+07, 2.24923e+07, 2.520295e+07, 2.089382e+07, 1.961421e+07, 2.43239e+07, 2.532755e+07, 2.434294e+07, 3.657709e+07, 2.621657e+07,
   1.779934e+07, 2.77022e+07, 2.614086e+07, 2.970355e+07, 2.581844e+07, 2.615353e+07, 3.01911e+07, 3.263904e+07, 3.124844e+07, 3.002207e+07, 3.241072e+07, 3.196255e+07, 3.021856e+07, 3.789373e+07, 3.3e+07 };
   TGraphErrors *gre = new TGraphErrors(48,PoTAllVsSqrts_fx1014,PoTAllVsSqrts_fy1014,PoTAllVsSqrts_fex1014,PoTAllVsSqrts_fey1014);
   gre->SetName("PoTAllVsSqrts");
   gre->SetTitle(";#sqrt{s} (MeV);N_{PoT}");
   gre->SetFillStyle(1000);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_PoTAllVsSqrts1014 = new TH1F("Graph_PoTAllVsSqrts1014","",100,13.97497,20.86929);
   Graph_PoTAllVsSqrts1014->SetMinimum(4.586425e+09);
   Graph_PoTAllVsSqrts1014->SetMaximum(1.164876e+10);
   Graph_PoTAllVsSqrts1014->SetDirectory(nullptr);
   Graph_PoTAllVsSqrts1014->SetStats(0);
   Graph_PoTAllVsSqrts1014->SetLineWidth(2);
   Graph_PoTAllVsSqrts1014->SetMarkerStyle(20);
   Graph_PoTAllVsSqrts1014->GetXaxis()->SetTitle("#sqrt{s} (MeV)");
   Graph_PoTAllVsSqrts1014->GetXaxis()->SetLabelFont(42);
   Graph_PoTAllVsSqrts1014->GetXaxis()->SetLabelSize(0.06);
   Graph_PoTAllVsSqrts1014->GetXaxis()->SetTitleSize(0.06);
   Graph_PoTAllVsSqrts1014->GetXaxis()->SetTitleOffset(1.1);
   Graph_PoTAllVsSqrts1014->GetYaxis()->SetTitle("N_{PoT}");
   Graph_PoTAllVsSqrts1014->GetYaxis()->SetLabelFont(42);
   Graph_PoTAllVsSqrts1014->GetYaxis()->SetLabelSize(0.06);
   Graph_PoTAllVsSqrts1014->GetYaxis()->SetTitleSize(0.06);
   Graph_PoTAllVsSqrts1014->GetZaxis()->SetLabelFont(42);
   Graph_PoTAllVsSqrts1014->GetZaxis()->SetLabelSize(0.06);
   Graph_PoTAllVsSqrts1014->GetZaxis()->SetTitleSize(0.06);
   Graph_PoTAllVsSqrts1014->GetZaxis()->SetTitleOffset(0.7);
   gre->SetHistogram(Graph_PoTAllVsSqrts1014);
   
   gre->Draw("ap");
   
   Double_t PoTAllVsSqrtsBelowRes_fx1015[5] = { 14.7608, 14.70774, 14.65483, 14.60243, 14.5495 };
   Double_t PoTAllVsSqrtsBelowRes_fy1015[5] = { 7.340557e+09, 7.417552e+09, 8.244527e+09, 6.789417e+09, 6.316295e+09 };
   Double_t PoTAllVsSqrtsBelowRes_fex1015[5] = { 0, 0, 0, 0, 0 };
   Double_t PoTAllVsSqrtsBelowRes_fey1015[5] = { 2.224892e+07, 2.24923e+07, 2.520295e+07, 2.089382e+07, 1.961421e+07 };
   gre = new TGraphErrors(5,PoTAllVsSqrtsBelowRes_fx1015,PoTAllVsSqrtsBelowRes_fy1015,PoTAllVsSqrtsBelowRes_fex1015,PoTAllVsSqrtsBelowRes_fey1015);
   gre->SetName("PoTAllVsSqrtsBelowRes");
   gre->SetTitle("");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#00ff00");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_PoTAllVsSqrtsBelowRes1015 = new TH1F("Graph_PoTAllVsSqrtsBelowRes1015","",100,14.52837,14.78193);
   Graph_PoTAllVsSqrtsBelowRes1015->SetMinimum(6.099375e+09);
   Graph_PoTAllVsSqrtsBelowRes1015->SetMaximum(8.467035e+09);
   Graph_PoTAllVsSqrtsBelowRes1015->SetDirectory(nullptr);
   Graph_PoTAllVsSqrtsBelowRes1015->SetStats(0);
   Graph_PoTAllVsSqrtsBelowRes1015->SetLineWidth(2);
   Graph_PoTAllVsSqrtsBelowRes1015->SetMarkerStyle(20);
   Graph_PoTAllVsSqrtsBelowRes1015->GetXaxis()->SetLabelFont(42);
   Graph_PoTAllVsSqrtsBelowRes1015->GetXaxis()->SetLabelSize(0.06);
   Graph_PoTAllVsSqrtsBelowRes1015->GetXaxis()->SetTitleSize(0.06);
   Graph_PoTAllVsSqrtsBelowRes1015->GetXaxis()->SetTitleOffset(1.1);
   Graph_PoTAllVsSqrtsBelowRes1015->GetYaxis()->SetLabelFont(42);
   Graph_PoTAllVsSqrtsBelowRes1015->GetYaxis()->SetLabelSize(0.06);
   Graph_PoTAllVsSqrtsBelowRes1015->GetYaxis()->SetTitleSize(0.06);
   Graph_PoTAllVsSqrtsBelowRes1015->GetZaxis()->SetLabelFont(42);
   Graph_PoTAllVsSqrtsBelowRes1015->GetZaxis()->SetLabelSize(0.06);
   Graph_PoTAllVsSqrtsBelowRes1015->GetZaxis()->SetTitleSize(0.06);
   Graph_PoTAllVsSqrtsBelowRes1015->GetZaxis()->SetTitleOffset(0.7);
   gre->SetHistogram(Graph_PoTAllVsSqrtsBelowRes1015);
   
   gre->Draw("p");
   
   Double_t PoTAllVsSqrtsAboveRes_fx1016[1] = { 20.29476 };
   Double_t PoTAllVsSqrtsAboveRes_fy1016[1] = { 1.1e+10 };
   Double_t PoTAllVsSqrtsAboveRes_fex1016[1] = { 0 };
   Double_t PoTAllVsSqrtsAboveRes_fey1016[1] = { 3.3e+07 };
   gre = new TGraphErrors(1,PoTAllVsSqrtsAboveRes_fx1016,PoTAllVsSqrtsAboveRes_fy1016,PoTAllVsSqrtsAboveRes_fex1016,PoTAllVsSqrtsAboveRes_fey1016);
   gre->SetName("PoTAllVsSqrtsAboveRes");
   gre->SetTitle("");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_PoTAllVsSqrtsAboveRes1016 = new TH1F("Graph_PoTAllVsSqrtsAboveRes1016","",100,20.19476,21.39476);
   Graph_PoTAllVsSqrtsAboveRes1016->SetMinimum(1.09604e+10);
   Graph_PoTAllVsSqrtsAboveRes1016->SetMaximum(1.10396e+10);
   Graph_PoTAllVsSqrtsAboveRes1016->SetDirectory(nullptr);
   Graph_PoTAllVsSqrtsAboveRes1016->SetStats(0);
   Graph_PoTAllVsSqrtsAboveRes1016->SetLineWidth(2);
   Graph_PoTAllVsSqrtsAboveRes1016->SetMarkerStyle(20);
   Graph_PoTAllVsSqrtsAboveRes1016->GetXaxis()->SetLabelFont(42);
   Graph_PoTAllVsSqrtsAboveRes1016->GetXaxis()->SetLabelSize(0.06);
   Graph_PoTAllVsSqrtsAboveRes1016->GetXaxis()->SetTitleSize(0.06);
   Graph_PoTAllVsSqrtsAboveRes1016->GetXaxis()->SetTitleOffset(1.1);
   Graph_PoTAllVsSqrtsAboveRes1016->GetYaxis()->SetLabelFont(42);
   Graph_PoTAllVsSqrtsAboveRes1016->GetYaxis()->SetLabelSize(0.06);
   Graph_PoTAllVsSqrtsAboveRes1016->GetYaxis()->SetTitleSize(0.06);
   Graph_PoTAllVsSqrtsAboveRes1016->GetZaxis()->SetLabelFont(42);
   Graph_PoTAllVsSqrtsAboveRes1016->GetZaxis()->SetLabelSize(0.06);
   Graph_PoTAllVsSqrtsAboveRes1016->GetZaxis()->SetTitleSize(0.06);
   Graph_PoTAllVsSqrtsAboveRes1016->GetZaxis()->SetTitleOffset(0.7);
   gre->SetHistogram(Graph_PoTAllVsSqrtsAboveRes1016);
   
   gre->Draw("p");
   dpotvssqrts->Modified();
   dpotvssqrts->SetSelected(dpotvssqrts);
}
