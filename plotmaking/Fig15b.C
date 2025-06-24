#ifdef __CLING__
#pragma cling optimize(0)
#endif
void Fig15b()
{
//=========Macro generated from canvas: c1/c1
//=========  (Fri May 23 11:49:36 2025) by ROOT version 6.34.04
   TCanvas *c1 = new TCanvas("c1", "c1",16,66,1337,916);
   gStyle->SetOptFit(0);
   gStyle->SetOptTitle(0);
   c1->Range(-1.194534e+11,0.2539474,7.337851e+11,0.5828947);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.14);
   c1->SetBottomMargin(0.14);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1004[41] = { 1.2951e+10, 2.304733e+10, 3.872439e+10, 5.149254e+10, 6.401765e+10, 7.548125e+10, 8.807682e+10, 1.017242e+11, 1.144541e+11, 1.271983e+11, 1.405523e+11, 1.539957e+11, 1.673891e+11, 1.807809e+11, 1.935747e+11, 2.066202e+11, 2.196889e+11,
   2.337276e+11, 2.478225e+11, 2.619621e+11, 2.75592e+11, 2.903113e+11, 3.042886e+11, 3.786923e+11, 3.916583e+11, 4.042457e+11, 4.225166e+11, 4.354269e+11, 4.441286e+11, 4.574724e+11, 4.693894e+11, 4.826385e+11, 4.940264e+11,
   5.052024e+11, 5.178289e+11, 5.312351e+11, 5.437034e+11, 5.552462e+11, 5.676003e+11, 5.795798e+11, 5.906876e+11 };
   Double_t Graph0_fy1004[41] = { 0.4056318, 0.3848001, 0.386982, 0.3958472, 0.4042597, 0.4008451, 0.4048577, 0.4012034, 0.4025306, 0.411349, 0.4184233, 0.4172431, 0.4256389, 0.4255518, 0.4188164, 0.4239595, 0.4253773,
   0.4286636, 0.4236476, 0.4040195, 0.4089101, 0.4102002, 0.4116711, 0.4154841, 0.4279469, 0.4228625, 0.4302447, 0.4336681, 0.4255063, 0.4265276, 0.4428874, 0.442128, 0.4395303,
   0.4387246, 0.4409408, 0.4339532, 0.438631, 0.4497603, 0.4416773, 0.4376316, 0.4335084 };
   Double_t Graph0_fex1004[41] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t Graph0_fey1004[41] = { 0.003789979, 0.01251133, 0.02329312, 0.009190558, 0.003544835, 0.009646639, 0.004156168, 0.007256725, 0.01337866, 0.01048743, 0.01055759, 0.004590763, 0.0135517, 0.007772133, 0.006887998, 0.006733402, 0.009205957,
   0.009307331, 0.01249501, 0.005543571, 0.01091008, 0.01713111, 0.009281093, 0.01227441, 0.01030612, 0.01165459, 0.01535408, 0.01068928, 0.02094832, 0.004034033, 0.004777467, 0.01528738, 0.008129833,
   0.009745996, 0.003854208, 0.01292266, 0.008100386, 0.007621176, 0.01631647, 0.004019187, 0.00995855 };
   TGraphErrors *gre = new TGraphErrors(41,Graph0_fx1004,Graph0_fy1004,Graph0_fex1004,Graph0_fey1004);
   gre->SetName("Graph0");
   gre->SetTitle("");
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(1.3);
   
   TH1F *Graph_Graph01004 = new TH1F("Graph_Graph01004","",100,0,6.484613e+11);
   Graph_Graph01004->SetMinimum(0.3);
   Graph_Graph01004->SetMaximum(0.55);
   Graph_Graph01004->SetDirectory(nullptr);
   
   TPaveStats *ptstats = new TPaveStats(0.1676218,0.5978947,0.3667622,0.8778947,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetFillColor(0);
   ptstats->SetLineColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextColor(0);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("Graph0");
   ptstats_LaTex->SetTextSize(0.0644);
   ptstats_LaTex = ptstats->AddText("Entries = 0      ");
   ptstats_LaTex = ptstats->AddText("Mean  =      0");
   ptstats_LaTex = ptstats->AddText("Std Dev   =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   Graph_Graph01004->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(Graph_Graph01004);
   Graph_Graph01004->SetLineWidth(2);
   Graph_Graph01004->SetMarkerStyle(20);
   Graph_Graph01004->GetXaxis()->SetTitle("PoT Integrated");
   Graph_Graph01004->GetXaxis()->SetLabelFont(42);
   Graph_Graph01004->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph01004->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph01004->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph01004->GetYaxis()->SetTitle("E_{ECAL} / N_{PoT} [MeV]");
   Graph_Graph01004->GetYaxis()->SetDecimals();
   Graph_Graph01004->GetYaxis()->SetLabelFont(42);
   Graph_Graph01004->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph01004->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph01004->GetYaxis()->SetTitleOffset(1.14);
   Graph_Graph01004->GetZaxis()->SetLabelFont(42);
   Graph_Graph01004->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph01004->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph01004->GetZaxis()->SetTitleOffset(0.7);
   gre->SetHistogram(Graph_Graph01004);
   
   
   TF1 *ff1005 = new TF1("ff","[0]*(1+[1]*(x-3.018E+11)/(5.777E+11))",0,6.484613e+11, TF1::EAddToList::kNo);
   ff1005->SetFillColor(19);
   ff1005->SetFillStyle(0);
   ff1005->SetMarkerStyle(20);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#cc0000");
   ff1005->SetLineColor(ci);
   ff1005->SetLineStyle(7);
   ff1005->SetLineWidth(1);
   ff1005->SetChisquare(39.09576);
   ff1005->SetNDF(39);
   ff1005->GetXaxis()->SetLabelFont(42);
   ff1005->GetXaxis()->SetLabelSize(0.06);
   ff1005->GetXaxis()->SetTitleSize(0.06);
   ff1005->GetXaxis()->SetTitleOffset(1.1);
   ff1005->GetYaxis()->SetLabelFont(42);
   ff1005->GetYaxis()->SetLabelSize(0.06);
   ff1005->GetYaxis()->SetTitleSize(0.06);
   ff1005->SetParameter(0,0.4221188);
   ff1005->SetParError(0,0.001098018);
   ff1005->SetParLimits(0,0,0);
   ff1005->SetParameter(1,0.09544524);
   ff1005->SetParError(1,0.007426999);
   ff1005->SetParLimits(1,0,0);
   ff1005->SetParent(gre);
   gre->GetListOfFunctions()->Add(ff1005);
   
   ptstats = new TPaveStats(0.5610487,0.6850394,0.882397,0.8515186,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 39.1 / 39");
   ptstats_LaTex = ptstats->AddText("Prob  = 0.466");
   ptstats_LaTex = ptstats->AddText("p0       = 0.422 #pm 0.001 ");
   ptstats_LaTex = ptstats->AddText("p1       = 0.095 #pm 0.007 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ap");
   c1->Modified();
   c1->SetSelected(c1);
}
