#ifdef __CLING__
#pragma cling optimize(0)
#endif
void fig12_2_paper()
{
//=========Macro generated from canvas: C/C
//=========  (Tue Jun 24 11:39:05 2025) by ROOT version 6.32.06
   TCanvas *C = new TCanvas("C", "C",0,66,1200,802);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   C->Range(16.172,0.90375,17.6018,1.06625);
   C->SetFillColor(0);
   C->SetBorderMode(0);
   C->SetBorderSize(2);
   C->SetTickx(1);
   C->SetTicky(1);
   C->SetFrameBorderMode(0);
   C->SetFrameBorderMode(0);
   
   Double_t FullSM_BabayagaFull_CalcHepEffi_fx1007[41] = { 17.3635, 17.3399, 17.3193, 17.2956, 17.275, 17.2513, 17.2305, 17.2068, 17.186, 17.1622, 17.1413, 17.1175, 17.0965, 17.0726, 17.0517, 17.0235, 17.0066,
   16.9826, 16.9615, 16.9374, 16.9163, 16.8921, 16.8709, 16.8466, 16.8254, 16.8011, 16.7798, 16.7554, 16.734, 16.7096, 16.6882, 16.6637, 16.6422,
   16.6176, 16.5961, 16.5714, 16.5498, 16.52527, 16.5034, 16.4569, 16.4107 };
   Double_t FullSM_BabayagaFull_CalcHepEffi_fy1007[41] = { 0.975215, 0.9790382, 0.9709799, 0.9778864, 0.9800003, 0.9735947, 0.9788444, 0.9767385, 0.9755278, 0.9752909, 0.978589, 0.9739205, 0.9741599, 0.9789392, 0.9658699, 0.9727396, 0.9699692,
   0.9713293, 0.9705309, 0.9712809, 0.9733222, 0.9665499, 0.9737504, 0.964799, 0.9737763, 0.9679815, 0.9790469, 0.9691577, 0.9718958, 0.9657927, 0.9735955, 0.9730869, 0.9713345,
   0.9690741, 0.9689412, 0.9771553, 0.9780733, 0.9780261, 0.9687385, 0.9683249, 0.9729435 };
   Double_t FullSM_BabayagaFull_CalcHepEffi_fex1007[41] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t FullSM_BabayagaFull_CalcHepEffi_fey1007[41] = { 0.003995396, 0.004033395, 0.003987651, 0.004033088, 0.004037067, 0.004026726, 0.004058768, 0.004047013, 0.00405172, 0.004082462, 0.004105234, 0.004094775, 0.004075245, 0.004136704, 0.004068594, 0.004112394, 0.004085362,
   0.004116519, 0.00413094, 0.004137784, 0.004156906, 0.004147245, 0.004191413, 0.004142982, 0.004199446, 0.004166827, 0.004242557, 0.004207351, 0.004216478, 0.004196296, 0.004249473, 0.004259783, 0.00425717,
   0.004258781, 0.004276077, 0.004310492, 0.004303373, 0.00432001, 0.004289529, 0.004335911, 0.004348038 };
   TGraphErrors *gre = new TGraphErrors(41,FullSM_BabayagaFull_CalcHepEffi_fx1007,FullSM_BabayagaFull_CalcHepEffi_fy1007,FullSM_BabayagaFull_CalcHepEffi_fex1007,FullSM_BabayagaFull_CalcHepEffi_fey1007);
   gre->SetName("FullSM_BabayagaFull_CalcHepEffi");
   gre->SetTitle("Bhabha + #gamma#gamma");
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(8);
   gre->SetMarkerSize(0.8);
   
   TH1F *Graph_FullSM_BabayagaFull_CalcHepEffi1007 = new TH1F("Graph_FullSM_BabayagaFull_CalcHepEffi1007","Bhabha + #gamma#gamma",100,16.31498,17.45882);
   Graph_FullSM_BabayagaFull_CalcHepEffi1007->SetMinimum(0.92);
   Graph_FullSM_BabayagaFull_CalcHepEffi1007->SetMaximum(1.05);
   Graph_FullSM_BabayagaFull_CalcHepEffi1007->SetDirectory(nullptr);
   Graph_FullSM_BabayagaFull_CalcHepEffi1007->SetLineWidth(2);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_FullSM_BabayagaFull_CalcHepEffi1007->SetMarkerColor(ci);
   Graph_FullSM_BabayagaFull_CalcHepEffi1007->SetMarkerStyle(8);
   Graph_FullSM_BabayagaFull_CalcHepEffi1007->GetXaxis()->SetTitle("#sqrt{s} [MeV]");
   Graph_FullSM_BabayagaFull_CalcHepEffi1007->GetXaxis()->SetLabelFont(42);
   Graph_FullSM_BabayagaFull_CalcHepEffi1007->GetXaxis()->SetLabelSize(0.05);
   Graph_FullSM_BabayagaFull_CalcHepEffi1007->GetXaxis()->SetTitleSize(0.06);
   Graph_FullSM_BabayagaFull_CalcHepEffi1007->GetXaxis()->SetTitleOffset(0.87);
   Graph_FullSM_BabayagaFull_CalcHepEffi1007->GetYaxis()->SetTitle("#sigma_{BabaYaga}/#sigma_{CalcHep}");
   Graph_FullSM_BabayagaFull_CalcHepEffi1007->GetYaxis()->SetLabelFont(42);
   Graph_FullSM_BabayagaFull_CalcHepEffi1007->GetYaxis()->SetLabelSize(0.05);
   Graph_FullSM_BabayagaFull_CalcHepEffi1007->GetYaxis()->SetTitleSize(0.06);
   Graph_FullSM_BabayagaFull_CalcHepEffi1007->GetYaxis()->SetTitleOffset(0.95);
   Graph_FullSM_BabayagaFull_CalcHepEffi1007->GetZaxis()->SetLabelFont(42);
   Graph_FullSM_BabayagaFull_CalcHepEffi1007->GetZaxis()->SetLabelSize(0.05);
   Graph_FullSM_BabayagaFull_CalcHepEffi1007->GetZaxis()->SetTitleSize(0.06);
   Graph_FullSM_BabayagaFull_CalcHepEffi1007->GetZaxis()->SetTitleOffset(1);
   gre->SetHistogram(Graph_FullSM_BabayagaFull_CalcHepEffi1007);
   
   
   TPaveStats *ptstats = new TPaveStats(0.5166945,0.6554839,0.8764608,0.8554839,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf =  35.04 / 39");
   ptstats_LaTex = ptstats->AddText("Prob  =  0.651");
   ptstats_LaTex = ptstats->AddText("p0       = 0.9731 #pm 0.0006489 ");
   ptstats_LaTex = ptstats->AddText("p1       = 0.005751 #pm 0.002402 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   
   TF1 *PrevFitTMP1009 = new TF1("PrevFitTMP","([p0]+[p1]*(x-16.92))",16.31498,17.45882, TF1::EAddToList::kNo);
   PrevFitTMP1009->SetFillColor(19);
   PrevFitTMP1009->SetFillStyle(0);

   ci = TColor::GetColor("#000099");
   PrevFitTMP1009->SetMarkerColor(ci);
   PrevFitTMP1009->SetMarkerStyle(8);
   PrevFitTMP1009->SetLineColor(2);
   PrevFitTMP1009->SetLineWidth(2);
   PrevFitTMP1009->SetChisquare(35.0415);
   PrevFitTMP1009->SetNDF(39);
   PrevFitTMP1009->GetXaxis()->SetLabelFont(42);
   PrevFitTMP1009->GetXaxis()->SetLabelSize(0.05);
   PrevFitTMP1009->GetXaxis()->SetTitleSize(0.06);
   PrevFitTMP1009->GetXaxis()->SetTitleOffset(0.87);
   PrevFitTMP1009->GetYaxis()->SetLabelFont(42);
   PrevFitTMP1009->GetYaxis()->SetLabelSize(0.05);
   PrevFitTMP1009->GetYaxis()->SetTitleSize(0.06);
   PrevFitTMP1009->GetYaxis()->SetTitleOffset(0.95);
   PrevFitTMP1009->SetParameter(0,0.9730831);
   PrevFitTMP1009->SetParError(0,0.0006489471);
   PrevFitTMP1009->SetParLimits(0,0,0);
   PrevFitTMP1009->SetParameter(1,0.005750564);
   PrevFitTMP1009->SetParError(1,0.00240179);
   PrevFitTMP1009->SetParLimits(1,0,0);
   PrevFitTMP1009->SetParent(gre);
   gre->GetListOfFunctions()->Add(PrevFitTMP1009);
   gre->Draw("ap");
   
   TPaveText *pt = new TPaveText(0.3985977,0.9377097,0.6014023,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("Bhabha + #gamma#gamma");
   pt->Draw();
   
   TLegend *leg = new TLegend(0.1310518,0.7496774,0.3672788,0.8593548,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextFont(62);
   leg->SetLineColor(0);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("FullSM_BabayagaFull_CalcHepEffi","Bhabha + #gamma#gamma","lpf");
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(8);
   entry->SetMarkerSize(0.8);
   entry->SetTextFont(62);
   leg->Draw();
   C->Modified();
   C->SetSelected(C);
}
