#ifdef __CLING__
#pragma cling optimize(0)
#endif
void fig12_1_paper()
{
//=========Macro generated from canvas: C/C
//=========  (Tue Jun 24 11:37:09 2025) by ROOT version 6.32.06
   TCanvas *C = new TCanvas("C", "C",0,66,1200,802);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   C->Range(16.172,0.81875,17.6018,1.13125);
   C->SetFillColor(0);
   C->SetBorderMode(0);
   C->SetBorderSize(2);
   C->SetTickx(1);
   C->SetTicky(1);
   C->SetFrameBorderMode(0);
   C->SetFrameBorderMode(0);
   
   Double_t ee_BabayagaFull_CalcHepEffi_fx1001[41] = { 17.3635, 17.3399, 17.3193, 17.2956, 17.275, 17.2513, 17.2305, 17.2068, 17.186, 17.1622, 17.1413, 17.1175, 17.0965, 17.0726, 17.0517, 17.0235, 17.0066,
   16.9826, 16.9615, 16.9374, 16.9163, 16.8921, 16.8709, 16.8466, 16.8254, 16.8011, 16.7798, 16.7554, 16.734, 16.7096, 16.6882, 16.6637, 16.6422,
   16.6176, 16.5961, 16.5714, 16.5498, 16.5251, 16.5034, 16.4569, 16.4107 };
   Double_t ee_BabayagaFull_CalcHepEffi_fy1001[41] = { 0.9715283, 0.9763668, 0.9684548, 0.9736712, 0.9719657, 0.971579, 0.9743675, 0.9705833, 0.9705168, 0.9755707, 0.977112, 0.975053, 0.9686237, 0.9774478, 0.9669535, 0.9723065, 0.964932,
   0.9693513, 0.970989, 0.970416, 0.9716363, 0.9706568, 0.9744971, 0.9662751, 0.9720747, 0.9662113, 0.9753935, 0.9703738, 0.9691509, 0.9655713, 0.9712657, 0.970944, 0.9691865,
   0.9682524, 0.9700023, 0.9714008, 0.967472, 0.9681089, 0.963763, 0.969854, 0.9655242 };
   Double_t ee_BabayagaFull_CalcHepEffi_fex1001[41] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t ee_BabayagaFull_CalcHepEffi_fey1001[41] = { 0.002836353, 0.002865429, 0.002830579, 0.002860716, 0.002856489, 0.002857338, 0.002875856, 0.002863541, 0.00286767, 0.002898137, 0.002910963, 0.002906636, 0.00288, 0.002931192, 0.002884078, 0.002912781, 0.002884547,
   0.00291134, 0.002925138, 0.002926808, 0.002938474, 0.002940106, 0.002965594, 0.00293027, 0.002964973, 0.002940099, 0.002991015, 0.002972544, 0.002971546, 0.002960364, 0.00299391, 0.003000744, 0.002997509,
   0.003000338, 0.003014766, 0.003027306, 0.003013439, 0.003025867, 0.003010265, 0.00305385, 0.003046082 };
   TGraphErrors *gre = new TGraphErrors(41,ee_BabayagaFull_CalcHepEffi_fx1001,ee_BabayagaFull_CalcHepEffi_fy1001,ee_BabayagaFull_CalcHepEffi_fex1001,ee_BabayagaFull_CalcHepEffi_fey1001);
   gre->SetName("ee_BabayagaFull_CalcHepEffi");
   gre->SetTitle("Bhabha");
   gre->SetLineWidth(2);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(8);
   gre->SetMarkerSize(0.8);
   
   TH1F *Graph_ee_BabayagaFull_CalcHepEffi1001 = new TH1F("Graph_ee_BabayagaFull_CalcHepEffi1001","Bhabha",100,16.31498,17.45882);
   Graph_ee_BabayagaFull_CalcHepEffi1001->SetMinimum(0.85);
   Graph_ee_BabayagaFull_CalcHepEffi1001->SetMaximum(1.1);
   Graph_ee_BabayagaFull_CalcHepEffi1001->SetDirectory(nullptr);
   Graph_ee_BabayagaFull_CalcHepEffi1001->SetLineWidth(2);

   ci = TColor::GetColor("#000099");
   Graph_ee_BabayagaFull_CalcHepEffi1001->SetMarkerColor(ci);
   Graph_ee_BabayagaFull_CalcHepEffi1001->SetMarkerStyle(8);
   Graph_ee_BabayagaFull_CalcHepEffi1001->GetXaxis()->SetTitle("#sqrt{s} [MeV]");
   Graph_ee_BabayagaFull_CalcHepEffi1001->GetXaxis()->SetLabelFont(42);
   Graph_ee_BabayagaFull_CalcHepEffi1001->GetXaxis()->SetLabelSize(0.05);
   Graph_ee_BabayagaFull_CalcHepEffi1001->GetXaxis()->SetTitleSize(0.06);
   Graph_ee_BabayagaFull_CalcHepEffi1001->GetXaxis()->SetTitleOffset(0.87);
   Graph_ee_BabayagaFull_CalcHepEffi1001->GetYaxis()->SetTitle("#sigma_{BabaYaga}/#sigma_{CalcHep}");
   Graph_ee_BabayagaFull_CalcHepEffi1001->GetYaxis()->SetLabelFont(42);
   Graph_ee_BabayagaFull_CalcHepEffi1001->GetYaxis()->SetLabelSize(0.05);
   Graph_ee_BabayagaFull_CalcHepEffi1001->GetYaxis()->SetTitleSize(0.06);
   Graph_ee_BabayagaFull_CalcHepEffi1001->GetYaxis()->SetTitleOffset(0.95);
   Graph_ee_BabayagaFull_CalcHepEffi1001->GetZaxis()->SetLabelFont(42);
   Graph_ee_BabayagaFull_CalcHepEffi1001->GetZaxis()->SetLabelSize(0.05);
   Graph_ee_BabayagaFull_CalcHepEffi1001->GetZaxis()->SetTitleSize(0.06);
   Graph_ee_BabayagaFull_CalcHepEffi1001->GetZaxis()->SetTitleOffset(1);
   gre->SetHistogram(Graph_ee_BabayagaFull_CalcHepEffi1001);
   
   
   TPaveStats *ptstats = new TPaveStats(0.5217028,0.1354839,0.8814691,0.3354839,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);

   ci = TColor::GetColor("#000099");
   ptstats->SetTextColor(ci);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf =  40.44 / 39");
   ptstats_LaTex = ptstats->AddText("Prob  = 0.4067");
   ptstats_LaTex = ptstats->AddText("p0       = 0.9706 #pm 0.0004585 ");
   ptstats_LaTex = ptstats->AddText("p1       = 0.006039 #pm 0.001695 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   
   TF1 *PrevFitTMP1003 = new TF1("PrevFitTMP","([p0]+[p1]*(x-16.92))",16.31498,17.45882, TF1::EAddToList::kNo);
   PrevFitTMP1003->SetFillColor(19);
   PrevFitTMP1003->SetFillStyle(0);

   ci = TColor::GetColor("#000099");
   PrevFitTMP1003->SetMarkerColor(ci);
   PrevFitTMP1003->SetMarkerStyle(8);
   PrevFitTMP1003->SetLineColor(4);
   PrevFitTMP1003->SetLineWidth(2);
   PrevFitTMP1003->SetChisquare(40.4358);
   PrevFitTMP1003->SetNDF(39);
   PrevFitTMP1003->GetXaxis()->SetLabelFont(42);
   PrevFitTMP1003->GetXaxis()->SetLabelSize(0.05);
   PrevFitTMP1003->GetXaxis()->SetTitleSize(0.06);
   PrevFitTMP1003->GetXaxis()->SetTitleOffset(0.87);
   PrevFitTMP1003->GetYaxis()->SetLabelFont(42);
   PrevFitTMP1003->GetYaxis()->SetLabelSize(0.05);
   PrevFitTMP1003->GetYaxis()->SetTitleSize(0.06);
   PrevFitTMP1003->GetYaxis()->SetTitleOffset(0.95);
   PrevFitTMP1003->SetParameter(0,0.9706424);
   PrevFitTMP1003->SetParError(0,0.0004585102);
   PrevFitTMP1003->SetParLimits(0,0,0);
   PrevFitTMP1003->SetParameter(1,0.006039327);
   PrevFitTMP1003->SetParError(1,0.001695273);
   PrevFitTMP1003->SetParLimits(1,0,0);
   PrevFitTMP1003->SetParent(gre);
   gre->GetListOfFunctions()->Add(PrevFitTMP1003);
   gre->Draw("ap");
   
   TPaveText *pt = new TPaveText(0.4303172,0.94,0.5696828,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextColor(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("Bhabha");
   pt->Draw();
   
   Double_t gg_BabayagaFull_CalcHepEffi_fx1004[41] = { 17.3635, 17.3399, 17.3193, 17.2956, 17.275, 17.2513, 17.2305, 17.2068, 17.186, 17.1622, 17.1413, 17.1175, 17.0965, 17.0726, 17.0517, 17.0235, 17.0066,
   16.9826, 16.9615, 16.9374, 16.9163, 16.8921, 16.8709, 16.8466, 16.8254, 16.8011, 16.7798, 16.7554, 16.734, 16.7096, 16.6882, 16.6637, 16.6422,
   16.6176, 16.5961, 16.5714, 16.5498, 16.5251, 16.5034, 16.4569, 16.4107 };
   Double_t gg_BabayagaFull_CalcHepEffi_fy1004[41] = { 0.9929911, 0.9918345, 0.9830708, 0.9982734, 1.019769, 0.9832277, 1.000523, 1.006795, 0.9998217, 0.9739766, 0.9855988, 0.9686288, 1.001016, 0.9860001, 0.9608192, 0.9747793, 0.9943142,
   0.9807215, 0.9683841, 0.9753639, 0.981322, 0.9477182, 0.9702664, 0.9579453, 0.9818003, 0.9763429, 0.9964764, 0.9635059, 0.9849457, 0.9668314, 0.9846297, 0.9831968, 0.9814585,
   0.9729237, 0.96402, 1.004852, 1.030555, 1.026753, 0.9925405, 0.9612933, 1.008669 };
   Double_t gg_BabayagaFull_CalcHepEffi_fex1004[41] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t gg_BabayagaFull_CalcHepEffi_fey1004[41] = { 0.01601361, 0.01601723, 0.01583937, 0.01624687, 0.01681762, 0.01594773, 0.01640106, 0.01658366, 0.01644357, 0.01584085, 0.01616504, 0.01578101, 0.01661113, 0.0162785, 0.01568335, 0.01606913, 0.01659762,
   0.01629809, 0.0160359, 0.01624519, 0.01644018, 0.01563046, 0.01622264, 0.01594535, 0.01656639, 0.01647242, 0.01702287, 0.01624035, 0.01682722, 0.01641929, 0.01689465, 0.01688334, 0.01687199,
   0.01671348, 0.01653334, 0.01762207, 0.01834662, 0.01829459, 0.01742999, 0.01666305, 0.01800247 };
   gre = new TGraphErrors(41,gg_BabayagaFull_CalcHepEffi_fx1004,gg_BabayagaFull_CalcHepEffi_fy1004,gg_BabayagaFull_CalcHepEffi_fex1004,gg_BabayagaFull_CalcHepEffi_fey1004);
   gre->SetName("gg_BabayagaFull_CalcHepEffi");
   gre->SetTitle("#gamma#gamma");
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#990000");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(21);
   gre->SetMarkerSize(0.8);
   
   TH1F *Graph_gg_BabayagaFull_CalcHepEffi1004 = new TH1F("Graph_gg_BabayagaFull_CalcHepEffi1004","#gamma#gamma",100,16.31498,17.45882);
   Graph_gg_BabayagaFull_CalcHepEffi1004->SetMinimum(0.9204064);
   Graph_gg_BabayagaFull_CalcHepEffi1004->SetMaximum(1.060583);
   Graph_gg_BabayagaFull_CalcHepEffi1004->SetDirectory(nullptr);
   Graph_gg_BabayagaFull_CalcHepEffi1004->SetLineWidth(2);

   ci = TColor::GetColor("#000099");
   Graph_gg_BabayagaFull_CalcHepEffi1004->SetMarkerColor(ci);
   Graph_gg_BabayagaFull_CalcHepEffi1004->SetMarkerStyle(8);
   Graph_gg_BabayagaFull_CalcHepEffi1004->GetXaxis()->SetTitle("#sqrt{s} [MeV]");
   Graph_gg_BabayagaFull_CalcHepEffi1004->GetXaxis()->SetLabelFont(42);
   Graph_gg_BabayagaFull_CalcHepEffi1004->GetXaxis()->SetLabelSize(0.05);
   Graph_gg_BabayagaFull_CalcHepEffi1004->GetXaxis()->SetTitleSize(0.06);
   Graph_gg_BabayagaFull_CalcHepEffi1004->GetXaxis()->SetTitleOffset(0.87);
   Graph_gg_BabayagaFull_CalcHepEffi1004->GetYaxis()->SetTitle("#sigma_{BabaYaga}/#sigma_{CalcHep}");
   Graph_gg_BabayagaFull_CalcHepEffi1004->GetYaxis()->SetLabelFont(42);
   Graph_gg_BabayagaFull_CalcHepEffi1004->GetYaxis()->SetLabelSize(0.05);
   Graph_gg_BabayagaFull_CalcHepEffi1004->GetYaxis()->SetTitleSize(0.06);
   Graph_gg_BabayagaFull_CalcHepEffi1004->GetYaxis()->SetTitleOffset(0.95);
   Graph_gg_BabayagaFull_CalcHepEffi1004->GetZaxis()->SetLabelFont(42);
   Graph_gg_BabayagaFull_CalcHepEffi1004->GetZaxis()->SetLabelSize(0.05);
   Graph_gg_BabayagaFull_CalcHepEffi1004->GetZaxis()->SetTitleSize(0.06);
   Graph_gg_BabayagaFull_CalcHepEffi1004->GetZaxis()->SetTitleOffset(1);
   gre->SetHistogram(Graph_gg_BabayagaFull_CalcHepEffi1004);
   
   
   ptstats = new TPaveStats(0.124374,0.1354839,0.4841402,0.3354839,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);

   ci = TColor::GetColor("#990000");
   ptstats->SetTextColor(ci);
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf =  47.37 / 39");
   ptstats_LaTex = ptstats->AddText("Prob  =  0.168");
   ptstats_LaTex = ptstats->AddText("p0       =  0.984 #pm 0.002577 ");
   ptstats_LaTex = ptstats->AddText("p1       = 0.005863 #pm 0.009649 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   
   TF1 *PrevFitTMP1006 = new TF1("PrevFitTMP","([p0]+[p1]*(x-16.92))",16.31498,17.45882, TF1::EAddToList::kNo);
   PrevFitTMP1006->SetFillColor(19);
   PrevFitTMP1006->SetFillStyle(0);

   ci = TColor::GetColor("#000099");
   PrevFitTMP1006->SetMarkerColor(ci);
   PrevFitTMP1006->SetMarkerStyle(8);
   PrevFitTMP1006->SetLineColor(2);
   PrevFitTMP1006->SetLineWidth(2);
   PrevFitTMP1006->SetChisquare(47.37435);
   PrevFitTMP1006->SetNDF(39);
   PrevFitTMP1006->GetXaxis()->SetLabelFont(42);
   PrevFitTMP1006->GetXaxis()->SetLabelSize(0.05);
   PrevFitTMP1006->GetXaxis()->SetTitleSize(0.06);
   PrevFitTMP1006->GetXaxis()->SetTitleOffset(0.87);
   PrevFitTMP1006->GetYaxis()->SetLabelFont(42);
   PrevFitTMP1006->GetYaxis()->SetLabelSize(0.05);
   PrevFitTMP1006->GetYaxis()->SetTitleSize(0.06);
   PrevFitTMP1006->GetYaxis()->SetTitleOffset(0.95);
   PrevFitTMP1006->SetParameter(0,0.9840147);
   PrevFitTMP1006->SetParError(0,0.002577411);
   PrevFitTMP1006->SetParLimits(0,0,0);
   PrevFitTMP1006->SetParameter(1,0.005862679);
   PrevFitTMP1006->SetParError(1,0.009648515);
   PrevFitTMP1006->SetParLimits(1,0,0);
   PrevFitTMP1006->SetParent(gre);
   gre->GetListOfFunctions()->Add(PrevFitTMP1006);
   gre->Draw(" p");
   
   TLegend *leg = new TLegend(0.6460768,0.7264516,0.8823038,0.8735484,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextFont(62);
   leg->SetLineColor(0);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("ee_BabayagaFull_CalcHepEffi","Bhabha","lpf");
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#000099");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(8);
   entry->SetMarkerSize(0.8);
   entry->SetTextFont(62);
   entry=leg->AddEntry("gg_BabayagaFull_CalcHepEffi","#gamma#gamma","lpf");
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#990000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(0.8);
   entry->SetTextFont(62);
   leg->Draw();
   C->Modified();
   C->SetSelected(C);
}
