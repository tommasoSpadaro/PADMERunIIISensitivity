#ifdef __CLING__
#pragma cling optimize(0)
#endif
void Fig20()
{
//=========Macro generated from canvas: passcanva/
//=========  (Wed Jul  2 09:48:07 2025) by ROOT version 6.30/04
   TCanvas *passcanva = new TCanvas("passcanva", "",900,66,700,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   passcanva->Range(-0.319209,-0.2227147,1.258192,1.356233);
   passcanva->SetFillColor(0);
   passcanva->SetBorderMode(0);
   passcanva->SetBorderSize(2);
   passcanva->SetTickx(1);
   passcanva->SetTicky(1);
   passcanva->SetLeftMargin(0.1389685);
   passcanva->SetBottomMargin(0.1410526);
   passcanva->SetFrameBorderMode(0);
   passcanva->SetFrameBorderMode(0);
   
   TH1F *hframe__2 = new TH1F("hframe__2","",1000,-0.1,1.1);
   hframe__2->SetMinimum(0);
   hframe__2->SetMaximum(1.2);
   hframe__2->SetDirectory(nullptr);
   hframe__2->SetStats(0);
   hframe__2->SetLineWidth(2);
   hframe__2->SetMarkerStyle(20);
   hframe__2->GetXaxis()->SetTitle("Additional relative uncertainty (%)");
   hframe__2->GetXaxis()->SetLabelFont(42);
   hframe__2->GetXaxis()->SetLabelSize(0.06);
   hframe__2->GetXaxis()->SetTitleSize(0.06);
   hframe__2->GetXaxis()->SetTitleOffset(1.1);
   hframe__2->GetYaxis()->SetTitle("Fraction accepted");
   hframe__2->GetYaxis()->SetLabelFont(42);
   hframe__2->GetYaxis()->SetLabelSize(0.06);
   hframe__2->GetYaxis()->SetTitleSize(0.06);
   hframe__2->GetZaxis()->SetLabelFont(42);
   hframe__2->GetZaxis()->SetLabelSize(0.06);
   hframe__2->GetZaxis()->SetTitleSize(0.06);
   hframe__2->GetZaxis()->SetTitleOffset(0.7);
   hframe__2->Draw("");
   
   Double_t P_{rej}_prob0.200000_fx3001[10] = { 0, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.1 };
   Double_t P_{rej}_prob0.200000_fy3001[10] = { 0.98, 0.96, 0.9133333, 0.7866667, 0.68, 0.4933333, 0.2933333, 0.1933333, 0.1059603, 0.03333333 };
   Double_t P_{rej}_prob0.200000_felx3001[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t P_{rej}_prob0.200000_fely3001[10] = { 0.01907178, 0.02312753, 0.0294536, 0.03877606, 0.04258319, 0.04394803, 0.03888283, 0.03324363, 0.02539901, 0.01432377 };
   Double_t P_{rej}_prob0.200000_fehx3001[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t P_{rej}_prob0.200000_fehy3001[10] = { 0.01086531, 0.01575345, 0.02317024, 0.03459084, 0.03998429, 0.04404377, 0.04187266, 0.037736, 0.03128282, 0.02192022 };
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(10,P_{rej}_prob0.200000_fx3001,P_{rej}_prob0.200000_fy3001,P_{rej}_prob0.200000_felx3001,P_{rej}_prob0.200000_fehx3001,P_{rej}_prob0.200000_fely3001,P_{rej}_prob0.200000_fehy3001);
   grae->SetName("P_{rej}_prob0.200000");
   grae->SetTitle("");
   grae->SetFillStyle(1000);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_P_{rej}_prob0dO2000003001 = new TH1F("Graph_P_{rej}_prob0dO2000003001","",100,0,1.21);
   Graph_P_{rej}_prob0dO2000003001->SetMinimum(0.01710861);
   Graph_P_{rej}_prob0dO2000003001->SetMaximum(1.088051);
   Graph_P_{rej}_prob0dO2000003001->SetDirectory(nullptr);
   Graph_P_{rej}_prob0dO2000003001->SetStats(0);
   Graph_P_{rej}_prob0dO2000003001->SetLineWidth(2);
   Graph_P_{rej}_prob0dO2000003001->SetMarkerStyle(20);
   Graph_P_{rej}_prob0dO2000003001->GetXaxis()->SetLabelFont(42);
   Graph_P_{rej}_prob0dO2000003001->GetXaxis()->SetLabelSize(0.06);
   Graph_P_{rej}_prob0dO2000003001->GetXaxis()->SetTitleSize(0.06);
   Graph_P_{rej}_prob0dO2000003001->GetXaxis()->SetTitleOffset(1.1);
   Graph_P_{rej}_prob0dO2000003001->GetYaxis()->SetLabelFont(42);
   Graph_P_{rej}_prob0dO2000003001->GetYaxis()->SetLabelSize(0.06);
   Graph_P_{rej}_prob0dO2000003001->GetYaxis()->SetTitleSize(0.06);
   Graph_P_{rej}_prob0dO2000003001->GetZaxis()->SetLabelFont(42);
   Graph_P_{rej}_prob0dO2000003001->GetZaxis()->SetLabelSize(0.06);
   Graph_P_{rej}_prob0dO2000003001->GetZaxis()->SetTitleSize(0.06);
   Graph_P_{rej}_prob0dO2000003001->GetZaxis()->SetTitleOffset(0.7);
   grae->SetHistogram(Graph_P_{rej}_prob0.2000003001);
   
   grae->Draw("pe");
   
   Double_t P_{rej}_prob0.400000_fx3002[10] = { 0, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.1 };
   Double_t P_{rej}_prob0.400000_fy3002[10] = { 0.92, 0.8133333, 0.74, 0.6066667, 0.4066667, 0.2533333, 0.1533333, 0.08666667, 0.0397351, 0 };
   Double_t P_{rej}_prob0.400000_felx3002[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t P_{rej}_prob0.400000_fely3002[10] = { 0.02870836, 0.03736144, 0.04077045, 0.04383421, 0.04261642, 0.03693713, 0.03012856, 0.02317024, 0.01564988, 0 };
   Double_t P_{rej}_prob0.400000_fehx3002[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t P_{rej}_prob0.400000_fehy3002[10] = { 0.02229386, 0.03276559, 0.03728753, 0.04229971, 0.04395853, 0.0405194, 0.03525257, 0.0294536, 0.02297939, 0.01219847 };
   grae = new TGraphAsymmErrors(10,P_{rej}_prob0.400000_fx3002,P_{rej}_prob0.400000_fy3002,P_{rej}_prob0.400000_felx3002,P_{rej}_prob0.400000_fehx3002,P_{rej}_prob0.400000_fely3002,P_{rej}_prob0.400000_fehy3002);
   grae->SetName("P_{rej}_prob0.400000");
   grae->SetTitle("");
   grae->SetFillStyle(1000);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_P_{rej}_prob0dO4000003002 = new TH1F("Graph_P_{rej}_prob0dO4000003002","",100,0,1.21);
   Graph_P_{rej}_prob0dO4000003002->SetMinimum(0);
   Graph_P_{rej}_prob0dO4000003002->SetMaximum(1.036523);
   Graph_P_{rej}_prob0dO4000003002->SetDirectory(nullptr);
   Graph_P_{rej}_prob0dO4000003002->SetStats(0);
   Graph_P_{rej}_prob0dO4000003002->SetLineWidth(2);
   Graph_P_{rej}_prob0dO4000003002->SetMarkerStyle(20);
   Graph_P_{rej}_prob0dO4000003002->GetXaxis()->SetLabelFont(42);
   Graph_P_{rej}_prob0dO4000003002->GetXaxis()->SetLabelSize(0.06);
   Graph_P_{rej}_prob0dO4000003002->GetXaxis()->SetTitleSize(0.06);
   Graph_P_{rej}_prob0dO4000003002->GetXaxis()->SetTitleOffset(1.1);
   Graph_P_{rej}_prob0dO4000003002->GetYaxis()->SetLabelFont(42);
   Graph_P_{rej}_prob0dO4000003002->GetYaxis()->SetLabelSize(0.06);
   Graph_P_{rej}_prob0dO4000003002->GetYaxis()->SetTitleSize(0.06);
   Graph_P_{rej}_prob0dO4000003002->GetZaxis()->SetLabelFont(42);
   Graph_P_{rej}_prob0dO4000003002->GetZaxis()->SetLabelSize(0.06);
   Graph_P_{rej}_prob0dO4000003002->GetZaxis()->SetTitleSize(0.06);
   Graph_P_{rej}_prob0dO4000003002->GetZaxis()->SetTitleOffset(0.7);
   grae->SetHistogram(Graph_P_{rej}_prob0.4000003002);
   
   grae->Draw("pe");
   
   TLegend *leg = new TLegend(0.6,0.56,0.87,0.86,NULL,"brNDC");
   leg->SetTextFont(62);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("NULL","Effect of validation cut 1","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("P_{rej}_prob0.200000","P(#chi^{2}>#chi^{2}_{Min}) > 0.2","P");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("P_{rej}_prob0.400000","P(#chi^{2}>#chi^{2}_{Min}) > 0.4","P");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(24);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   leg->Draw();
   passcanva->Modified();
   passcanva->SetSelected(passcanva);
}
