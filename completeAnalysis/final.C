#ifdef __CLING__
#pragma cling optimize(0)
#endif
void final()
{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Apr  2 16:04:56 2025) by ROOT version 6.34.04
   TCanvas *c1 = new TCanvas("c1", "c1",241,131,1125,809);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   c1->SetHighLightColor(2);
   c1->Range(0,0,1,1);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.14);
   c1->SetBottomMargin(0.14);
   c1->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: c1_1
   TPad *c1_1__0 = new TPad("c1_1", "c1_1",0.000890472,0.3388747,0.9991095,0.9974425);
   c1_1__0->Draw();
   c1_1__0->cd();
   c1_1__0->Range(-59.77803,-0.1807882,55.16394,1.168573);
   c1_1__0->SetFillColor(0);
   c1_1__0->SetBorderMode(0);
   c1_1__0->SetBorderSize(2);
   c1_1__0->SetTickx(1);
   c1_1__0->SetTicky(1);
   c1_1__0->SetLeftMargin(0.1400535);
   c1_1__0->SetTopMargin(0.04854369);
   c1_1__0->SetBottomMargin(0.1339806);
   c1_1__0->SetFrameBorderMode(0);
   c1_1__0->SetFrameBorderMode(0);
   
   Double_t Norm_fx1001[27] = { -64.96669, -60.04776, -55.02636, -50.00496, -44.98356, -39.96215, -35.04323, -30.02183, -25.00043, -19.97902, -14.95762, -10.0387, -5.017295, 0.004106956, 5.025509, 10.04691, 14.96584,
   19.98724, 25.00864, 30.03004, 34.94897, 39.97037, 44.99177, 50.01317, 55.03457, 59.9535, 64.9749 };
   Double_t Norm_fy1001[27] = { -0.0006219826, -0.0006219826, 0.1797576, 0.484148, 0.7349883, 0.8054491, 0.7659911, 0.7265331, 0.7237146, 0.7716279, 0.8618177, 0.9520075, 0.9914655, 0.9999208, 0.9914655, 0.9491891, 0.8561809,
   0.7603542, 0.7011672, 0.687075, 0.7039856, 0.7208962, 0.667346, 0.5405167, 0.3432265, 0.1318442, 0.1318442 };
   Double_t Norm_fex1001[27] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t Norm_fey1001[27] = { 0, 0, 0.0009538542, 0.001229696, 0.0007924368, 0.0005309538, 0.000465531, 0.0005358526, 0.0004459165, 0.0004554563, 0.0004586504, 0.0003596618, 0.0002438957, 0.00266888, 0.0002387123, 0.0003832104, 0.0005549656,
   0.0005372362, 0.000542398, 0.0005751553, 0.0006116977, 0.000594667, 0.0007398054, 0.0009694133, 0.0008852829, 0.0007494783, 0.0007494783 };
   TGraphErrors *gre = new TGraphErrors(27,Norm_fx1001,Norm_fy1001,Norm_fex1001,Norm_fey1001);
   gre->SetName("Norm");
   gre->SetTitle("MC");
   gre->SetFillStyle(1000);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Norm10011001 = new TH1F("Graph_Graph_Norm10011001","MC",100,-78,78);
   Graph_Graph_Norm10011001->SetMinimum(0);
   Graph_Graph_Norm10011001->SetMaximum(1.10307);
   Graph_Graph_Norm10011001->SetDirectory(nullptr);
   Graph_Graph_Norm10011001->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph_Norm10011001->SetLineColor(ci);
   Graph_Graph_Norm10011001->SetLineWidth(2);
   Graph_Graph_Norm10011001->SetMarkerStyle(20);
   Graph_Graph_Norm10011001->GetXaxis()->SetTitle("Y [mm]");
   Graph_Graph_Norm10011001->GetXaxis()->SetRange(23,78);
   Graph_Graph_Norm10011001->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Norm10011001->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph_Norm10011001->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Norm10011001->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph_Norm10011001->GetYaxis()->SetTitle("E / E_{y=0}");
   Graph_Graph_Norm10011001->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Norm10011001->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph_Norm10011001->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Norm10011001->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Norm10011001->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_Norm10011001->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Norm10011001->GetZaxis()->SetTitleOffset(1);
   Graph_Graph_Norm10011001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Norm10011001);
   
   gre->Draw("ap");
   
   Double_t GDati_fx1[23] = { -70.08586, -64.92677, -54.96033, -50.21161, -44.99389, -40.18655, -30.16149, -25.06101, -20.19505, -15.09458, -10.28724, 4.838297, 9.880142, 14.80474, 19.84658, 24.8298, 29.81302,
   34.79623, 39.83808, 44.70405, 49.74589, 54.78773, 59.71233 };
   Double_t GDati_fy1[23] = { 0.1153525, 0.1632049, 0.3861058, 0.5209526, 0.8821981, 0.7982286, 0.7572037, 0.7135299, 0.7773473, 0.8516865, 0.9669879, 1.000147, 0.9801588, 0.8724681, 0.7707476, 0.7199187, 0.7438136,
   0.811388, 0.7472772, 0.6666574, 0.423066, 0.2035558, 0.1355416 };
   TGraph *graph = new TGraph(23,GDati_fx1,GDati_fy1);
   graph->SetName("GDati");
   graph->SetTitle("TB data");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_GDati11 = new TH1F("Graph_Graph_GDati11","TB data",100,-83.77506,72.75664);
   Graph_Graph_GDati11->SetMinimum(0.004583752);
   Graph_Graph_GDati11->SetMaximum(1.333809);
   Graph_Graph_GDati11->SetDirectory(nullptr);
   Graph_Graph_GDati11->SetLineWidth(2);
   Graph_Graph_GDati11->SetMarkerStyle(20);
   Graph_Graph_GDati11->GetXaxis()->SetLabelFont(42);
   Graph_Graph_GDati11->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph_GDati11->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_GDati11->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph_GDati11->GetYaxis()->SetLabelFont(42);
   Graph_Graph_GDati11->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph_GDati11->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_GDati11->GetZaxis()->SetLabelFont(42);
   Graph_Graph_GDati11->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_GDati11->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_GDati11->GetZaxis()->SetTitleOffset(0.7);
   graph->SetHistogram(Graph_Graph_GDati11);
   
   graph->Draw("p");
   
   TLegend *leg = new TLegend(0,0,0,0,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextFont(62);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Norm","MC","lpf");
   entry->SetFillStyle(1000);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("GDati","TB data","lpf");
   entry->SetFillStyle(1000);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   leg->Draw();
   TLatex *   tex = new TLatex(-40,1,"PADME");
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(-30.71457,0.9998415,"Preliminary");
   tex->SetTextFont(52);
   tex->SetLineWidth(2);
   tex->Draw();
   
   leg = new TLegend(0.6895629,0.3009709,0.8751115,0.5106796,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(62);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   entry=leg->AddEntry("Norm","MC","lpf");
   entry->SetFillStyle(1000);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("GDati","TB data","lpf");
   entry->SetFillStyle(1000);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   leg->Draw();
   c1_1__0->Modified();
   c1->cd();
  
// ------------>Primitives in pad: c1_2
   TPad *c1_2__1 = new TPad("c1_2", "c1_2",0,-0,1,0.3196931);
   c1_2__1->Draw();
   c1_2__1->cd();
   c1_2__1->Range(-59.0735,0.7904526,54.92616,1.213242);
   c1_2__1->SetFillColor(0);
   c1_2__1->SetBorderMode(0);
   c1_2__1->SetBorderSize(2);
   c1_2__1->SetTickx(1);
   c1_2__1->SetTicky(1);
   c1_2__1->SetLeftMargin(0.1406946);
   c1_2__1->SetTopMargin(0.007407408);
   c1_2__1->SetBottomMargin(0.2407408);
   c1_2__1->SetFrameBorderMode(0);
   c1_2__1->SetFrameBorderMode(0);
   
   Double_t __fx1002[21] = { -54.96033, -50.21161, -44.99389, -40.18655, -30.16149, -25.06101, -20.19505, -15.09458, -10.28724, 4.838297, 9.880142, 14.80474, 19.84658, 24.8298, 29.81302, 34.79623, 39.83808,
   44.70405, 49.74589, 54.78773, 59.71233 };
   Double_t __fy1002[21] = { 2.151114, 1.076553, 1.19971, 0.992414, 1.040216, 0.9842916, 1.007391, 0.9871977, 1.015358, 1.00795, 1.031772, 1.019484, 1.013883, 1.024888, 1.084172, 1.151586, 1.036837,
   0.9993894, 0.7842487, 0.5938062, 1.032138 };
   Double_t __fex1002[21] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0 };
   Double_t __fey1002[21] = { 0.08434784, 0.03111812, 0.02043958, 0.01866056, 0.02062062, 0.02070088, 0.01944811, 0.01739456, 0.01575499, 0.01511897, 0.01579535, 0.01754005, 0.01974482, 0.0213689, 0.02188267, 0.02131265, 0.02082986,
   0.02251387, 0.02784159, 0.04378436, 0.1143755 };
   gre = new TGraphErrors(21,__fx1002,__fy1002,__fex1002,__fey1002);
   gre->SetName("");
   gre->SetTitle("");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph10021002 = new TH1F("Graph_Graph_Graph10021002","",100,-66.42759,71.1796);
   Graph_Graph_Graph10021002->SetMinimum(0.8922353);
   Graph_Graph_Graph10021002->SetMaximum(1.210111);
   Graph_Graph_Graph10021002->SetDirectory(nullptr);
   Graph_Graph_Graph10021002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph10021002->SetLineColor(ci);
   Graph_Graph_Graph10021002->SetLineWidth(2);
   Graph_Graph_Graph10021002->SetMarkerStyle(20);
   Graph_Graph_Graph10021002->GetXaxis()->SetTitle("Y [mm]");
   Graph_Graph_Graph10021002->GetXaxis()->SetRange(18,80);
   Graph_Graph_Graph10021002->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph10021002->GetXaxis()->SetLabelSize(0.09);
   Graph_Graph_Graph10021002->GetXaxis()->SetTitleSize(0.09);
   Graph_Graph_Graph10021002->GetXaxis()->SetTitleOffset(1);
   Graph_Graph_Graph10021002->GetYaxis()->SetTitle("Ratio");
   Graph_Graph_Graph10021002->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph10021002->GetYaxis()->SetLabelOffset(0.006);
   Graph_Graph_Graph10021002->GetYaxis()->SetLabelSize(0.09);
   Graph_Graph_Graph10021002->GetYaxis()->SetTitleSize(0.09);
   Graph_Graph_Graph10021002->GetYaxis()->SetTitleOffset(0.5);
   Graph_Graph_Graph10021002->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph10021002->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph10021002->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph10021002->GetZaxis()->SetTitleOffset(1);
   Graph_Graph_Graph10021002->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph10021002);
   
   
   TPaveStats *ptstats = new TPaveStats(0.1647373,0.7074074,0.4265361,0.9259259,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 9.086 / 10");
   ptstats_LaTex = ptstats->AddText("Prob  = 0.524");
   ptstats_LaTex = ptstats->AddText("p0       = 1.012 #pm 0.005429 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   
   TF1 *PrevFitTMP1004 = new TF1("PrevFitTMP","pol0",-43.03437,28.52137, TF1::EAddToList::kNo);
   PrevFitTMP1004->SetFillColor(19);
   PrevFitTMP1004->SetFillStyle(0);
   PrevFitTMP1004->SetMarkerStyle(20);

   ci = TColor::GetColor("#cc0000");
   PrevFitTMP1004->SetLineColor(ci);
   PrevFitTMP1004->SetLineWidth(3);
   PrevFitTMP1004->SetChisquare(9.086066);
   PrevFitTMP1004->SetNDF(10);
   PrevFitTMP1004->GetXaxis()->SetLabelFont(42);
   PrevFitTMP1004->GetXaxis()->SetLabelSize(0.06);
   PrevFitTMP1004->GetXaxis()->SetTitleSize(0.06);
   PrevFitTMP1004->GetXaxis()->SetTitleOffset(1.1);
   PrevFitTMP1004->GetYaxis()->SetLabelFont(42);
   PrevFitTMP1004->GetYaxis()->SetLabelSize(0.06);
   PrevFitTMP1004->GetYaxis()->SetTitleSize(0.06);
   PrevFitTMP1004->SetParameter(0,1.01152);
   PrevFitTMP1004->SetParError(0,0.005429409);
   PrevFitTMP1004->SetParLimits(0,0,0);
   PrevFitTMP1004->SetParent(gre);
   gre->GetListOfFunctions()->Add(PrevFitTMP1004);
   gre->Draw("ap");
   c1_2__1->Modified();
   c1->cd();
   c1->Modified();
   c1->SetSelected(c1);
}
