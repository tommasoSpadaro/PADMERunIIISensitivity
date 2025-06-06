#ifdef __CLING__
#pragma cling optimize(0)
#endif
void NPOT_vs_Sqrts_ASF()
{
//=========Macro generated from canvas: dpotvssqrts/
//=========  (Thu May 29 23:33:59 2025) by ROOT version 6.34.08
   TCanvas *dpotvssqrts = new TCanvas("dpotvssqrts", "",173,224,700,554);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   dpotvssqrts->Range(12.70496,3.285469e+09,21.77644,1.257801e+10);
   dpotvssqrts->SetFillColor(0);
   dpotvssqrts->SetBorderMode(0);
   dpotvssqrts->SetBorderSize(2);
   dpotvssqrts->SetTickx(1);
   dpotvssqrts->SetTicky(1);
   dpotvssqrts->SetLeftMargin(0.14);
   dpotvssqrts->SetBottomMargin(0.14);
   dpotvssqrts->SetFrameBorderMode(0);
   dpotvssqrts->SetFrameBorderMode(0);
   
   Double_t PoTAllVsSqrts_fx1001[48] = { 17.12373, 17.26669, 17.2277, 17.17572, 17.39666, 17.35767, 17.31868, 17.09774, 17.07175, 16.99377, 16.95478, 16.90279, 16.86381, 16.81182, 16.75983, 16.72085, 16.66886,
   16.62987, 16.57789, 16.5259, 16.48691, 16.43492, 16.38294, 14.75839, 14.70641, 14.65442, 14.60244, 14.55045, 17.33168, 17.29269, 17.2537, 17.20171, 17.16272,
   17.12373, 17.07175, 17.03276, 16.98077, 16.94178, 16.8898, 16.83781, 16.79882, 16.74684, 16.69485, 16.65586, 16.60388, 16.55189, 17.38366, 20.29485 };
   Double_t PoTAllVsSqrts_fy1001[48] = { 7.178556e+09, 5.496116e+09, 8.606674e+09, 7.041613e+09, 6.845981e+09, 6.435153e+09, 6.826418e+09, 7.569821e+09, 7.100303e+09, 7.13943e+09, 7.413315e+09, 7.491568e+09, 7.511132e+09, 7.511132e+09, 7.13943e+09, 7.276373e+09, 7.315499e+09,
   7.86327e+09, 7.92196e+09, 8.039339e+09, 7.765454e+09, 8.391478e+09, 7.941523e+09, 7.335062e+09, 7.413315e+09, 8.234972e+09, 6.787291e+09, 6.317773e+09, 7.745891e+09, 7.941523e+09, 7.530695e+09, 1.103252e+10, 7.745891e+09,
   5.183104e+09, 7.902397e+09, 7.315499e+09, 8.117593e+09, 6.924234e+09, 6.885107e+09, 7.765454e+09, 8.195846e+09, 7.687201e+09, 7.217683e+09, 7.628511e+09, 7.374189e+09, 6.826418e+09, 8.352352e+09, 1.099339e+10 };
   Double_t PoTAllVsSqrts_fex1001[48] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t PoTAllVsSqrts_fey1001[48] = { 3.354643e+07, 2.51327e+07, 3.807124e+07, 3.031471e+07, 2.869812e+07, 2.632282e+07, 2.719604e+07, 2.934115e+07, 2.681733e+07, 2.628713e+07, 2.657471e+07, 2.620587e+07, 2.567865e+07, 2.50876e+07, 2.339461e+07, 2.338268e+07, 2.315152e+07,
   2.453505e+07, 2.437715e+07, 2.446988e+07, 2.35522e+07, 2.526614e+07, 2.388362e+07, 2.224892e+07, 2.24923e+07, 2.520295e+07, 2.089382e+07, 1.961421e+07, 2.43239e+07, 2.532755e+07, 2.434294e+07, 3.657709e+07, 2.621657e+07,
   1.779934e+07, 2.77022e+07, 2.614086e+07, 2.970355e+07, 2.581844e+07, 2.615353e+07, 3.01911e+07, 3.263904e+07, 3.124844e+07, 3.002207e+07, 3.241072e+07, 3.196255e+07, 3.021856e+07, 3.789373e+07, 3.3e+07 };
   TGraphErrors *gre = new TGraphErrors(48,PoTAllVsSqrts_fx1001,PoTAllVsSqrts_fy1001,PoTAllVsSqrts_fex1001,PoTAllVsSqrts_fey1001);
   gre->SetName("PoTAllVsSqrts");
   gre->SetTitle(";#sqrt{s} (MeV);N_{PoT}");
   gre->SetFillStyle(1000);
   gre->SetMarkerColor(4);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_PoTAllVsSqrts101410011001 = new TH1F("Graph_Graph_Graph_PoTAllVsSqrts101410011001","",100,13.97497,20.86929);
   Graph_Graph_Graph_PoTAllVsSqrts101410011001->SetMinimum(4.586425e+09);
   Graph_Graph_Graph_PoTAllVsSqrts101410011001->SetMaximum(1.164876e+10);
   Graph_Graph_Graph_PoTAllVsSqrts101410011001->SetDirectory(nullptr);
   Graph_Graph_Graph_PoTAllVsSqrts101410011001->SetStats(0);
   Graph_Graph_Graph_PoTAllVsSqrts101410011001->SetLineWidth(2);
   Graph_Graph_Graph_PoTAllVsSqrts101410011001->SetMarkerStyle(20);
   Graph_Graph_Graph_PoTAllVsSqrts101410011001->GetXaxis()->SetTitle("#sqrt{s} (MeV)");
   Graph_Graph_Graph_PoTAllVsSqrts101410011001->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph_PoTAllVsSqrts101410011001->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_PoTAllVsSqrts101410011001->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph_PoTAllVsSqrts101410011001->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph_PoTAllVsSqrts101410011001->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph_PoTAllVsSqrts101410011001->GetYaxis()->SetTitle("N_{POT}");
   Graph_Graph_Graph_PoTAllVsSqrts101410011001->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph_PoTAllVsSqrts101410011001->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_PoTAllVsSqrts101410011001->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph_PoTAllVsSqrts101410011001->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph_Graph_PoTAllVsSqrts101410011001->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph_PoTAllVsSqrts101410011001->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph_PoTAllVsSqrts101410011001->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_PoTAllVsSqrts101410011001->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_PoTAllVsSqrts101410011001->GetZaxis()->SetTitleOffset(0.7);
   gre->SetHistogram(Graph_Graph_Graph_PoTAllVsSqrts101410011001);
   
   gre->Draw("ap");
   
   Double_t PoTAllVsSqrtsBelowRes_fx1002[5] = { 14.7608, 14.70774, 14.65483, 14.60243, 14.5495 };
   Double_t PoTAllVsSqrtsBelowRes_fy1002[5] = { 7.340557e+09, 7.417552e+09, 8.244527e+09, 6.789417e+09, 6.316295e+09 };
   Double_t PoTAllVsSqrtsBelowRes_fex1002[5] = { 0, 0, 0, 0, 0 };
   Double_t PoTAllVsSqrtsBelowRes_fey1002[5] = { 2.224892e+07, 2.24923e+07, 2.520295e+07, 2.089382e+07, 1.961421e+07 };
   gre = new TGraphErrors(5,PoTAllVsSqrtsBelowRes_fx1002,PoTAllVsSqrtsBelowRes_fy1002,PoTAllVsSqrtsBelowRes_fex1002,PoTAllVsSqrtsBelowRes_fey1002);
   gre->SetName("PoTAllVsSqrtsBelowRes");
   gre->SetTitle("");
   gre->SetFillStyle(1000);
   gre->SetMarkerColor(3);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_PoTAllVsSqrtsBelowRes101510021002 = new TH1F("Graph_Graph_Graph_PoTAllVsSqrtsBelowRes101510021002","",100,14.52837,14.78193);
   Graph_Graph_Graph_PoTAllVsSqrtsBelowRes101510021002->SetMinimum(6.099375e+09);
   Graph_Graph_Graph_PoTAllVsSqrtsBelowRes101510021002->SetMaximum(8.467035e+09);
   Graph_Graph_Graph_PoTAllVsSqrtsBelowRes101510021002->SetDirectory(nullptr);
   Graph_Graph_Graph_PoTAllVsSqrtsBelowRes101510021002->SetStats(0);
   Graph_Graph_Graph_PoTAllVsSqrtsBelowRes101510021002->SetLineWidth(2);
   Graph_Graph_Graph_PoTAllVsSqrtsBelowRes101510021002->SetMarkerStyle(20);
   Graph_Graph_Graph_PoTAllVsSqrtsBelowRes101510021002->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph_PoTAllVsSqrtsBelowRes101510021002->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_PoTAllVsSqrtsBelowRes101510021002->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_PoTAllVsSqrtsBelowRes101510021002->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph_PoTAllVsSqrtsBelowRes101510021002->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph_PoTAllVsSqrtsBelowRes101510021002->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_PoTAllVsSqrtsBelowRes101510021002->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_PoTAllVsSqrtsBelowRes101510021002->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph_PoTAllVsSqrtsBelowRes101510021002->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_PoTAllVsSqrtsBelowRes101510021002->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_PoTAllVsSqrtsBelowRes101510021002->GetZaxis()->SetTitleOffset(0.7);
   gre->SetHistogram(Graph_Graph_Graph_PoTAllVsSqrtsBelowRes101510021002);
   
   gre->Draw("p");
   
   Double_t PoTAllVsSqrtsAboveRes_fx1003[1] = { 20.29476 };
   Double_t PoTAllVsSqrtsAboveRes_fy1003[1] = { 1.1e+10 };
   Double_t PoTAllVsSqrtsAboveRes_fex1003[1] = { 0 };
   Double_t PoTAllVsSqrtsAboveRes_fey1003[1] = { 3.3e+07 };
   gre = new TGraphErrors(1,PoTAllVsSqrtsAboveRes_fx1003,PoTAllVsSqrtsAboveRes_fy1003,PoTAllVsSqrtsAboveRes_fex1003,PoTAllVsSqrtsAboveRes_fey1003);
   gre->SetName("PoTAllVsSqrtsAboveRes");
   gre->SetTitle("");
   gre->SetFillStyle(1000);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_PoTAllVsSqrtsAboveRes101610031003 = new TH1F("Graph_Graph_Graph_PoTAllVsSqrtsAboveRes101610031003","",100,20.19476,21.39476);
   Graph_Graph_Graph_PoTAllVsSqrtsAboveRes101610031003->SetMinimum(1.09604e+10);
   Graph_Graph_Graph_PoTAllVsSqrtsAboveRes101610031003->SetMaximum(1.10396e+10);
   Graph_Graph_Graph_PoTAllVsSqrtsAboveRes101610031003->SetDirectory(nullptr);
   Graph_Graph_Graph_PoTAllVsSqrtsAboveRes101610031003->SetStats(0);
   Graph_Graph_Graph_PoTAllVsSqrtsAboveRes101610031003->SetLineWidth(2);
   Graph_Graph_Graph_PoTAllVsSqrtsAboveRes101610031003->SetMarkerStyle(20);
   Graph_Graph_Graph_PoTAllVsSqrtsAboveRes101610031003->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph_PoTAllVsSqrtsAboveRes101610031003->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_PoTAllVsSqrtsAboveRes101610031003->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_PoTAllVsSqrtsAboveRes101610031003->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph_PoTAllVsSqrtsAboveRes101610031003->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph_PoTAllVsSqrtsAboveRes101610031003->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_PoTAllVsSqrtsAboveRes101610031003->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_PoTAllVsSqrtsAboveRes101610031003->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph_PoTAllVsSqrtsAboveRes101610031003->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_PoTAllVsSqrtsAboveRes101610031003->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_PoTAllVsSqrtsAboveRes101610031003->GetZaxis()->SetTitleOffset(0.7);
   gre->SetHistogram(Graph_Graph_Graph_PoTAllVsSqrtsAboveRes101610031003);
   
   gre->Draw("p");
   TLatex *   tex = new TLatex(14.34251,1.079776e+10,"PADME");
   tex->SetTextSize(0.06736842);
   tex->SetLineWidth(2);
   tex->Draw();
   dpotvssqrts->Modified();
   dpotvssqrts->SetSelected(dpotvssqrts);
   dpotvssqrts->ToggleToolBar();

   dpotvssqrts->Print("NPOT_vs_Sqrts_ASF.pdf");
}
