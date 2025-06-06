#ifdef __CLING__
#pragma cling optimize(0)
#endif
void QtargOvQLG_ASF()
{
//=========Macro generated from canvas: c1/c1
//=========  (Fri May 30 01:11:03 2025) by ROOT version 6.34.08
   TCanvas *c1 = new TCanvas("c1", "c1",155,122,1182,767);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   c1->ToggleEventStatus();
   c1->Range(-6.061001e+10,0.0001979594,2.949008e+11,0.0003204781);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.1704871);
   c1->SetRightMargin(0.08166189);
   c1->SetBottomMargin(0.1410526);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1001[37] = { 1.2951e+10, 2.304733e+10, 3.872439e+10, 5.149254e+10, 6.401765e+10, 7.572666e+10, 8.807682e+10, 1.017242e+11, 1.144541e+11, 1.271983e+11, 1.405523e+11, 1.539957e+11, 1.673891e+11, 1.807809e+11, 1.935747e+11, 2.066202e+11, 2.196889e+11,
   2.337276e+11, 2.475874e+11, 3.786923e+11, 3.916583e+11, 4.042457e+11, 4.225166e+11, 4.354269e+11, 4.441286e+11, 4.574724e+11, 4.693894e+11, 4.826385e+11, 4.940264e+11, 5.052024e+11, 5.178289e+11, 5.312351e+11, 5.437034e+11,
   5.552462e+11, 5.676003e+11, 5.795798e+11, 5.906876e+11 };
   Double_t Graph0_fy1001[37] = { 0.0002501738, 0.000252786, 0.0002303565, 0.000235634, 0.0002480295, 0.0002530036, 0.0002549786, 0.0002480016, 0.0002513778, 0.000259849, 0.0002506197, 0.0002517506, 0.0002547793, 0.0002617623, 0.000259314, 0.0002618881, 0.000262999,
   0.0002693547, 0.0002650914, 0.0002901461, 0.000254524, 0.0003257942, 0.0003062815, 0.000311734, 0.0003013485, 0.0003102523, 0.0002938114, 0.0002885251, 0.0003142072, 0.0003091857, 0.0003147371, 0.0003264072, 0.0003254169,
   0.0003128492, 0.0003374897, 0.0003404876, 0.0003324777 };
   Double_t Graph0_fex1001[37] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0 };
   Double_t Graph0_fey1001[37] = { 7.311627e-06, 6.372921e-06, 5.09523e-06, 5.521399e-06, 5.290829e-06, 5.575978e-06, 5.547602e-06, 5.712298e-06, 5.446808e-06, 5.917187e-06, 5.456575e-06, 5.398382e-06, 5.700029e-06, 5.556056e-06, 5.805098e-06, 5.613215e-06, 5.752513e-06,
   5.520795e-06, 5.869169e-06, 9.967154e-06, 9.69952e-06, 1.064473e-05, 8.966538e-06, 1.01446e-05, 1.220075e-05, 1.007263e-05, 1.962158e-05, 9.662643e-06, 1.072665e-05, 1.068101e-05, 1.016571e-05, 9.856703e-06, 1.058469e-05,
   1.072098e-05, 1.093118e-05, 1.077134e-05, 1.094293e-05 };
   TGraphErrors *gre = new TGraphErrors(37,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("");
   gre->SetFillStyle(1000);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_Graph0100410011001 = new TH1F("Graph_Graph_Graph_Graph0100410011001","",100,0,6.484613e+11);
   Graph_Graph_Graph_Graph0100410011001->SetMinimum(0.000215241);
   Graph_Graph_Graph_Graph0100410011001->SetMaximum(0.0003082262);
   Graph_Graph_Graph_Graph0100410011001->SetDirectory(nullptr);
   
   TPaveStats *ptstats = new TPaveStats(0.1948424,0.5852632,0.3939828,0.8652632,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetFillColor(0);
   ptstats->SetLineColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextColor(0);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("Graph_Graph_Graph010041001");
   ptstats_LaTex->SetTextSize(0.0644);
   ptstats_LaTex = ptstats->AddText("Entries = 0      ");
   ptstats_LaTex = ptstats->AddText("Mean  =      0");
   ptstats_LaTex = ptstats->AddText("Std Dev   =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   Graph_Graph_Graph_Graph0100410011001->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(Graph_Graph_Graph_Graph0100410011001);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph_Graph0100410011001->SetLineColor(ci);
   Graph_Graph_Graph_Graph0100410011001->SetLineWidth(2);
   Graph_Graph_Graph_Graph0100410011001->SetMarkerStyle(20);
   Graph_Graph_Graph_Graph0100410011001->GetXaxis()->SetTitle("POT integrated");
   Graph_Graph_Graph_Graph0100410011001->GetXaxis()->SetRange(1,41);
   Graph_Graph_Graph_Graph0100410011001->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph0100410011001->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph0100410011001->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph_Graph0100410011001->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph_Graph0100410011001->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph0100410011001->GetYaxis()->SetTitle("Q_{tar} / Q_{lead-glass}");
   Graph_Graph_Graph_Graph0100410011001->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph0100410011001->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph0100410011001->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph_Graph0100410011001->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph0100410011001->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph0100410011001->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph_Graph0100410011001->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph0100410011001->GetZaxis()->SetTitleOffset(0.7);
   Graph_Graph_Graph_Graph0100410011001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph_Graph0100410011001);
   
   
   ptstats = new TPaveStats(0.5358166,0.6652632,0.8954155,0.8652632,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf =  20.3 / 17");
   ptstats_LaTex = ptstats->AddText("Prob  =  0.26");
   ptstats_LaTex = ptstats->AddText("p0       = (2.527 #pm 0.013)e-04 ");
   ptstats_LaTex = ptstats->AddText("p1       = 0.109 #pm 0.018 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(1111);
   ptstats->SetFitFormat("5.3g");
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   
   TF1 *PrevFitTMP1003 = new TF1("PrevFitTMP","[p0]*(1+[p1]*(x-1.24E+11)/(2.48E+11))",0,2.658691e+11, TF1::EAddToList::kNo);
   PrevFitTMP1003->SetFillColor(19);
   PrevFitTMP1003->SetFillStyle(0);
   PrevFitTMP1003->SetMarkerStyle(20);

   ci = TColor::GetColor("#cc0000");
   PrevFitTMP1003->SetLineColor(ci);
   PrevFitTMP1003->SetLineStyle(9);
   PrevFitTMP1003->SetLineWidth(2);
   PrevFitTMP1003->SetChisquare(20.27832);
   PrevFitTMP1003->SetNDF(17);
   PrevFitTMP1003->GetXaxis()->SetLabelFont(42);
   PrevFitTMP1003->GetXaxis()->SetLabelSize(0.06);
   PrevFitTMP1003->GetXaxis()->SetTitleOffset(1);
   PrevFitTMP1003->GetXaxis()->SetTitleFont(42);
   PrevFitTMP1003->GetYaxis()->SetLabelFont(42);
   PrevFitTMP1003->GetYaxis()->SetLabelSize(0.06);
   PrevFitTMP1003->GetYaxis()->SetTitleFont(42);
   PrevFitTMP1003->SetParameter(0,0.0002527613);
   PrevFitTMP1003->SetParError(0,1.303919e-06);
   PrevFitTMP1003->SetParLimits(0,0,0);
   PrevFitTMP1003->SetParameter(1,0.1089015);
   PrevFitTMP1003->SetParError(1,0.01841908);
   PrevFitTMP1003->SetParLimits(1,0,0);
   PrevFitTMP1003->SetParent(gre);
   gre->GetListOfFunctions()->Add(PrevFitTMP1003);
   gre->Draw("ap");
   TLatex *   tex = new TLatex(0,0.003,"PADME");
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(1e+10,0.003,"PADME");
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(1.471008e+10,0.0002966744,"PADME");
   tex->SetTextSize(0.07);
   tex->SetLineWidth(2);
   tex->Draw();
   c1->Modified();
   c1->SetSelected(c1);

   c1->Print("QtargOvQLG_ASF.pdf");
}
