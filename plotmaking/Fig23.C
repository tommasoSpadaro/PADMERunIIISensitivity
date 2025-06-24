#ifdef __CLING__
#pragma cling optimize(0)
#endif
void Fig23()
{
//=========Macro generated from canvas: dd/resultC
//=========  (Tue Jun 24 15:36:18 2025) by ROOT version 6.30/04
   TCanvas *dd = new TCanvas("dd", "resultC",0,66,970,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   dd->Range(0,0,1,1);
   dd->SetFillColor(0);
   dd->SetBorderMode(0);
   dd->SetBorderSize(2);
   dd->SetTickx(1);
   dd->SetTicky(1);
   dd->SetLeftMargin(0.14);
   dd->SetBottomMargin(0.14);
   dd->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: dd_1
   TPad *dd_1__0 = new TPad("dd_1", "dd_1",0,0.35,1,1);
   dd_1__0->Draw();
   dd_1__0->cd();
   dd_1__0->Range(15.53947,5e-05,18.82895,0.001105556);
   dd_1__0->SetFillColor(0);
   dd_1__0->SetBorderMode(0);
   dd_1__0->SetBorderSize(2);
   dd_1__0->SetTickx(1);
   dd_1__0->SetTicky(1);
   dd_1__0->SetLeftMargin(0.14);
   dd_1__0->SetBottomMargin(0);
   dd_1__0->SetFrameLineWidth(2);
   dd_1__0->SetFrameBorderMode(0);
   dd_1__0->SetFrameLineWidth(2);
   dd_1__0->SetFrameBorderMode(0);
   
   TH2D *framepl__1 = new TH2D("framepl__1","",100,16,18.5,100,5e-05,0.001);
   framepl__1->SetStats(0);
   framepl__1->SetLineWidth(2);
   framepl__1->SetMarkerStyle(20);
   framepl__1->GetXaxis()->SetTitle("M_{X} (MeV)");
   framepl__1->GetXaxis()->SetLabelFont(42);
   framepl__1->GetXaxis()->SetLabelSize(0.04);
   framepl__1->GetXaxis()->SetTitleSize(0.05);
   framepl__1->GetXaxis()->SetTitleOffset(0.8);
   framepl__1->GetYaxis()->SetTitle("g_{ve}");
   framepl__1->GetYaxis()->SetNdivisions(3000505);
   framepl__1->GetYaxis()->SetLabelFont(42);
   framepl__1->GetYaxis()->SetLabelSize(0.065);
   framepl__1->GetYaxis()->SetTitleSize(0.08);
   framepl__1->GetYaxis()->SetTitleOffset(0.6);
   framepl__1->GetZaxis()->SetLabelFont(42);
   framepl__1->GetZaxis()->SetLabelSize(0.06);
   framepl__1->GetZaxis()->SetTitleSize(0.06);
   framepl__1->GetZaxis()->SetTitleOffset(0.7);
   framepl__1->Draw("");
   
   Double_t KLOE_2015_fx3001[2] = { 15, 20 };
   Double_t KLOE_2015_fy3001[2] = { 0.0053, 0.00531 };
   Double_t KLOE_2015_felx3001[2] = { 0, 0 };
   Double_t KLOE_2015_fely3001[2] = { 0.0047, 0.00469 };
   Double_t KLOE_2015_fehx3001[2] = { 0, 0 };
   Double_t KLOE_2015_fehy3001[2] = { 0.0047, 0.00469 };
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(2,KLOE_2015_fx3001,KLOE_2015_fy3001,KLOE_2015_felx3001,KLOE_2015_fehx3001,KLOE_2015_fely3001,KLOE_2015_fehy3001);
   grae->SetName("KLOE_2015");
   grae->SetTitle("");
   grae->SetFillColor(17);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_KLOE_20153001 = new TH1F("Graph_KLOE_20153001","",100,14.5,20.5);
   Graph_KLOE_20153001->SetMinimum(0.00054);
   Graph_KLOE_20153001->SetMaximum(0.01094);
   Graph_KLOE_20153001->SetDirectory(nullptr);
   Graph_KLOE_20153001->SetStats(0);
   Graph_KLOE_20153001->SetLineWidth(2);
   Graph_KLOE_20153001->SetMarkerStyle(20);
   Graph_KLOE_20153001->GetXaxis()->SetLabelFont(42);
   Graph_KLOE_20153001->GetXaxis()->SetLabelSize(0.06);
   Graph_KLOE_20153001->GetXaxis()->SetTitleSize(0.06);
   Graph_KLOE_20153001->GetXaxis()->SetTitleOffset(1.1);
   Graph_KLOE_20153001->GetYaxis()->SetLabelFont(42);
   Graph_KLOE_20153001->GetYaxis()->SetLabelSize(0.06);
   Graph_KLOE_20153001->GetYaxis()->SetTitleSize(0.06);
   Graph_KLOE_20153001->GetZaxis()->SetLabelFont(42);
   Graph_KLOE_20153001->GetZaxis()->SetLabelSize(0.06);
   Graph_KLOE_20153001->GetZaxis()->SetTitleSize(0.06);
   Graph_KLOE_20153001->GetZaxis()->SetTitleOffset(0.7);
   grae->SetHistogram(Graph_KLOE_20153001);
   
   grae->Draw("3");
   
   Double_t NA64_2019_fx3002[2] = { 15, 20 };
   Double_t NA64_2019_fy3002[2] = { 0.0001325, 0.0001 };
   Double_t NA64_2019_felx3002[2] = { 0, 0 };
   Double_t NA64_2019_fely3002[2] = { 9.75e-05, 6e-05 };
   Double_t NA64_2019_fehx3002[2] = { 0, 0 };
   Double_t NA64_2019_fehy3002[2] = { 9.75e-05, 6e-05 };
   grae = new TGraphAsymmErrors(2,NA64_2019_fx3002,NA64_2019_fy3002,NA64_2019_felx3002,NA64_2019_fehx3002,NA64_2019_fely3002,NA64_2019_fehy3002);
   grae->SetName("NA64_2019");
   grae->SetTitle("");
   grae->SetFillColor(14);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_NA64_20193002 = new TH1F("Graph_NA64_20193002","",100,14.5,20.5);
   Graph_NA64_20193002->SetMinimum(1.55e-05);
   Graph_NA64_20193002->SetMaximum(0.0002495);
   Graph_NA64_20193002->SetDirectory(nullptr);
   Graph_NA64_20193002->SetStats(0);
   Graph_NA64_20193002->SetLineWidth(2);
   Graph_NA64_20193002->SetMarkerStyle(20);
   Graph_NA64_20193002->GetXaxis()->SetLabelFont(42);
   Graph_NA64_20193002->GetXaxis()->SetLabelSize(0.06);
   Graph_NA64_20193002->GetXaxis()->SetTitleSize(0.06);
   Graph_NA64_20193002->GetXaxis()->SetTitleOffset(1.1);
   Graph_NA64_20193002->GetYaxis()->SetLabelFont(42);
   Graph_NA64_20193002->GetYaxis()->SetLabelSize(0.06);
   Graph_NA64_20193002->GetYaxis()->SetTitleSize(0.06);
   Graph_NA64_20193002->GetZaxis()->SetLabelFont(42);
   Graph_NA64_20193002->GetZaxis()->SetLabelSize(0.06);
   Graph_NA64_20193002->GetZaxis()->SetTitleSize(0.06);
   Graph_NA64_20193002->GetZaxis()->SetTitleOffset(0.7);
   grae->SetHistogram(Graph_NA64_20193002);
   
   grae->Draw("3");
   
   Double_t ExpLimit90CL_2sigmaCov_fx3003[33] = { 16.32, 16.36, 16.4, 16.44, 16.48, 16.52, 16.56, 16.6, 16.64, 16.68, 16.72, 16.76, 16.8, 16.84, 16.88, 16.92, 16.96,
   17, 17.04, 17.08, 17.12, 17.16, 17.2, 17.24, 17.28, 17.32, 17.36, 17.4, 17.44, 17.48, 17.52, 17.56, 17.6 };
   Double_t ExpLimit90CL_2sigmaCov_fy3003[33] = { 0.0007456788, 0.0005484426, 0.0004824755, 0.0004771752, 0.0004704768, 0.0004465209, 0.0004188704, 0.0004065831, 0.0004059841, 0.0004014096, 0.0003944563, 0.0003870529, 0.0003805497, 0.0003724375, 0.0003724375, 0.0003772454, 0.0003778073,
   0.0003779947, 0.0003843368, 0.0003716408, 0.0003706964, 0.0003861992, 0.0003828905, 0.000388508, 0.0003982141, 0.0004025532, 0.0004068418, 0.0004282513, 0.0005331418, 0.0007638186, 0.001085874, 0.001404566, 0.001612803 };
   Double_t ExpLimit90CL_2sigmaCov_felx3003[33] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t ExpLimit90CL_2sigmaCov_fely3003[33] = { 0.0002904837, 0.0001857749, 0.0001636238, 0.0001421503, 0.0001517487, 0.0001386573, 0.0001380445, 0.0001360847, 0.0001463502, 0.0001260159, 0.0001190626, 0.0001076797, 0.0001301486, 0.0001461813, 0.0001089824, 0.0001182721, 0.0001148067,
   0.0001150434, 0.000125487, 0.0001202171, 0.0001275383, 0.0001118796, 0.0001161978, 0.0001349669, 0.0001076184, 0.0001268015, 0.0001581342, 0.0001435615, 0.0002158584, 0.0002359711, 0.0004653728, 0.0009110226, 0.001165414 };
   Double_t ExpLimit90CL_2sigmaCov_fehx3003[33] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t ExpLimit90CL_2sigmaCov_fehy3003[33] = { 0.0004405024, 0.0002668924, 0.0002128128, 0.0002056993, 0.0001983109, 0.0001700616, 0.0001543501, 0.0001637634, 0.0001428124, 0.0001449276, 0.0001546982, 0.0001472576, 0.0001468758, 0.0001600068, 0.0001437654, 0.0001497049, 0.0001708101,
   0.0001767157, 0.000168246, 0.000155509, 0.0001621613, 0.0001683875, 0.0001695275, 0.0001709161, 0.0001726694, 0.0001846271, 0.0002130556, 0.0004701359, 0.0007237743, 0.0007219937, 0.0005848824, 0.0008248511, 0.0006227211 };
   grae = new TGraphAsymmErrors(33,ExpLimit90CL_2sigmaCov_fx3003,ExpLimit90CL_2sigmaCov_fy3003,ExpLimit90CL_2sigmaCov_felx3003,ExpLimit90CL_2sigmaCov_fehx3003,ExpLimit90CL_2sigmaCov_fely3003,ExpLimit90CL_2sigmaCov_fehy3003);
   grae->SetName("ExpLimit90CL_2sigmaCov");
   grae->SetTitle("");
   grae->SetFillColor(41);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_ExpLimit90CL_2sigmaCov3003 = new TH1F("Graph_ExpLimit90CL_2sigmaCov3003","",100,16.192,17.728);
   Graph_ExpLimit90CL_2sigmaCov3003->SetMinimum(2.532943e-05);
   Graph_ExpLimit90CL_2sigmaCov3003->SetMaximum(0.00243645);
   Graph_ExpLimit90CL_2sigmaCov3003->SetDirectory(nullptr);
   Graph_ExpLimit90CL_2sigmaCov3003->SetStats(0);
   Graph_ExpLimit90CL_2sigmaCov3003->SetLineWidth(2);
   Graph_ExpLimit90CL_2sigmaCov3003->SetMarkerStyle(20);
   Graph_ExpLimit90CL_2sigmaCov3003->GetXaxis()->SetLabelFont(42);
   Graph_ExpLimit90CL_2sigmaCov3003->GetXaxis()->SetLabelSize(0.06);
   Graph_ExpLimit90CL_2sigmaCov3003->GetXaxis()->SetTitleSize(0.06);
   Graph_ExpLimit90CL_2sigmaCov3003->GetXaxis()->SetTitleOffset(1.1);
   Graph_ExpLimit90CL_2sigmaCov3003->GetYaxis()->SetLabelFont(42);
   Graph_ExpLimit90CL_2sigmaCov3003->GetYaxis()->SetLabelSize(0.06);
   Graph_ExpLimit90CL_2sigmaCov3003->GetYaxis()->SetTitleSize(0.06);
   Graph_ExpLimit90CL_2sigmaCov3003->GetZaxis()->SetLabelFont(42);
   Graph_ExpLimit90CL_2sigmaCov3003->GetZaxis()->SetLabelSize(0.06);
   Graph_ExpLimit90CL_2sigmaCov3003->GetZaxis()->SetTitleSize(0.06);
   Graph_ExpLimit90CL_2sigmaCov3003->GetZaxis()->SetTitleOffset(0.7);
   grae->SetHistogram(Graph_ExpLimit90CL_2sigmaCov3003);
   
   grae->Draw("3");
   
   Double_t ExpLimit90CL_1sigmaCov_fx3004[33] = { 16.32, 16.36, 16.4, 16.44, 16.48, 16.52, 16.56, 16.6, 16.64, 16.68, 16.72, 16.76, 16.8, 16.84, 16.88, 16.92, 16.96,
   17, 17.04, 17.08, 17.12, 17.16, 17.2, 17.24, 17.28, 17.32, 17.36, 17.4, 17.44, 17.48, 17.52, 17.56, 17.6 };
   Double_t ExpLimit90CL_1sigmaCov_fy3004[33] = { 0.0007456788, 0.0005484426, 0.0004824755, 0.0004771752, 0.0004704768, 0.0004465209, 0.0004188704, 0.0004065831, 0.0004059841, 0.0004014096, 0.0003944563, 0.0003870529, 0.0003805497, 0.0003724375, 0.0003724375, 0.0003772454, 0.0003778073,
   0.0003779947, 0.0003843368, 0.0003716408, 0.0003706964, 0.0003861992, 0.0003828905, 0.000388508, 0.0003982141, 0.0004025532, 0.0004068418, 0.0004282513, 0.0005331418, 0.0007638186, 0.001085874, 0.001404566, 0.001612803 };
   Double_t ExpLimit90CL_1sigmaCov_felx3004[33] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t ExpLimit90CL_1sigmaCov_fely3004[33] = { 0.000118898, 8.31281e-05, 8.182931e-05, 7.641821e-05, 7.6369e-05, 6.59717e-05, 6.789755e-05, 6.285332e-05, 6.29353e-05, 6.081552e-05, 6.336868e-05, 6.491993e-05, 5.980175e-05, 6.236174e-05, 5.405464e-05, 5.803152e-05, 5.828874e-05,
   5.449262e-05, 6.701796e-05, 6.318193e-05, 5.231354e-05, 6.282953e-05, 6.270046e-05, 5.905307e-05, 6.009971e-05, 6.420276e-05, 6.264224e-05, 6.560246e-05, 8.26547e-05, 0.0001197982, 0.0001874382, 0.000296228, 0.0003331773 };
   Double_t ExpLimit90CL_1sigmaCov_fehx3004[33] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t ExpLimit90CL_1sigmaCov_fehy3004[33] = { 0.0001698423, 0.0001077543, 9.907086e-05, 9.202744e-05, 8.621697e-05, 7.809322e-05, 7.115239e-05, 7.78531e-05, 6.726614e-05, 6.931747e-05, 7.417704e-05, 7.565433e-05, 7.37267e-05, 8.070626e-05, 7.491935e-05, 7.131715e-05, 7.799971e-05,
   8.958077e-05, 7.123157e-05, 6.909962e-05, 7.786763e-05, 7.547402e-05, 7.929165e-05, 8.314167e-05, 8.128371e-05, 8.698469e-05, 8.416464e-05, 0.0001006525, 0.0001420215, 0.0002283061, 0.0002607787, 0.0002975011, 0.0005721971 };
   grae = new TGraphAsymmErrors(33,ExpLimit90CL_1sigmaCov_fx3004,ExpLimit90CL_1sigmaCov_fy3004,ExpLimit90CL_1sigmaCov_felx3004,ExpLimit90CL_1sigmaCov_fehx3004,ExpLimit90CL_1sigmaCov_fely3004,ExpLimit90CL_1sigmaCov_fehy3004);
   grae->SetName("ExpLimit90CL_1sigmaCov");
   grae->SetTitle("");
   grae->SetFillColor(30);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_ExpLimit90CL_1sigmaCov3004 = new TH1F("Graph_ExpLimit90CL_1sigmaCov3004","",100,16.192,17.728);
   Graph_ExpLimit90CL_1sigmaCov3004->SetMinimum(0.0001208048);
   Graph_ExpLimit90CL_1sigmaCov3004->SetMaximum(0.002372654);
   Graph_ExpLimit90CL_1sigmaCov3004->SetDirectory(nullptr);
   Graph_ExpLimit90CL_1sigmaCov3004->SetStats(0);
   Graph_ExpLimit90CL_1sigmaCov3004->SetLineWidth(2);
   Graph_ExpLimit90CL_1sigmaCov3004->SetMarkerStyle(20);
   Graph_ExpLimit90CL_1sigmaCov3004->GetXaxis()->SetLabelFont(42);
   Graph_ExpLimit90CL_1sigmaCov3004->GetXaxis()->SetLabelSize(0.06);
   Graph_ExpLimit90CL_1sigmaCov3004->GetXaxis()->SetTitleSize(0.06);
   Graph_ExpLimit90CL_1sigmaCov3004->GetXaxis()->SetTitleOffset(1.1);
   Graph_ExpLimit90CL_1sigmaCov3004->GetYaxis()->SetLabelFont(42);
   Graph_ExpLimit90CL_1sigmaCov3004->GetYaxis()->SetLabelSize(0.06);
   Graph_ExpLimit90CL_1sigmaCov3004->GetYaxis()->SetTitleSize(0.06);
   Graph_ExpLimit90CL_1sigmaCov3004->GetZaxis()->SetLabelFont(42);
   Graph_ExpLimit90CL_1sigmaCov3004->GetZaxis()->SetLabelSize(0.06);
   Graph_ExpLimit90CL_1sigmaCov3004->GetZaxis()->SetTitleSize(0.06);
   Graph_ExpLimit90CL_1sigmaCov3004->GetZaxis()->SetTitleOffset(0.7);
   grae->SetHistogram(Graph_ExpLimit90CL_1sigmaCov3004);
   
   grae->Draw("3");
   
   Double_t Median90CLUL_fx1[33] = { 16.32, 16.36, 16.4, 16.44, 16.48, 16.52, 16.56, 16.6, 16.64, 16.68, 16.72, 16.76, 16.8, 16.84, 16.88, 16.92, 16.96,
   17, 17.04, 17.08, 17.12, 17.16, 17.2, 17.24, 17.28, 17.32, 17.36, 17.4, 17.44, 17.48, 17.52, 17.56, 17.6 };
   Double_t Median90CLUL_fy1[33] = { 0.0007456788, 0.0005484426, 0.0004824755, 0.0004771752, 0.0004704768, 0.0004465209, 0.0004188704, 0.0004065831, 0.0004059841, 0.0004014096, 0.0003944563, 0.0003870529, 0.0003805497, 0.0003724375, 0.0003724375, 0.0003772454, 0.0003778073,
   0.0003779947, 0.0003843368, 0.0003716408, 0.0003706964, 0.0003861992, 0.0003828905, 0.000388508, 0.0003982141, 0.0004025532, 0.0004068418, 0.0004282513, 0.0005331418, 0.0007638186, 0.001085874, 0.001404566, 0.001612803 };
   TGraph *graph = new TGraph(33,Median90CLUL_fx1,Median90CLUL_fy1);
   graph->SetName("Median90CLUL");
   graph->SetTitle("");
   graph->SetFillStyle(1000);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineStyle(2);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Median90CLUL1 = new TH1F("Graph_Median90CLUL1","",100,16.192,17.728);
   Graph_Median90CLUL1->SetMinimum(0.0002464858);
   Graph_Median90CLUL1->SetMaximum(0.001737013);
   Graph_Median90CLUL1->SetDirectory(nullptr);
   Graph_Median90CLUL1->SetStats(0);
   Graph_Median90CLUL1->SetLineWidth(2);
   Graph_Median90CLUL1->SetMarkerStyle(20);
   Graph_Median90CLUL1->GetXaxis()->SetLabelFont(42);
   Graph_Median90CLUL1->GetXaxis()->SetLabelSize(0.06);
   Graph_Median90CLUL1->GetXaxis()->SetTitleSize(0.06);
   Graph_Median90CLUL1->GetXaxis()->SetTitleOffset(1.1);
   Graph_Median90CLUL1->GetYaxis()->SetLabelFont(42);
   Graph_Median90CLUL1->GetYaxis()->SetLabelSize(0.06);
   Graph_Median90CLUL1->GetYaxis()->SetTitleSize(0.06);
   Graph_Median90CLUL1->GetZaxis()->SetLabelFont(42);
   Graph_Median90CLUL1->GetZaxis()->SetLabelSize(0.06);
   Graph_Median90CLUL1->GetZaxis()->SetTitleSize(0.06);
   Graph_Median90CLUL1->GetZaxis()->SetTitleOffset(0.7);
   graph->SetHistogram(Graph_Median90CLUL1);
   
   graph->Draw("l");
   
   Double_t FeldmanCousinsLimit90_fx2[33] = { 16.32, 16.36, 16.4, 16.44, 16.48, 16.52, 16.56, 16.6, 16.64, 16.68, 16.72, 16.76, 16.8, 16.84, 16.88, 16.92, 16.96,
   17, 17.04, 17.08, 17.12, 17.16, 17.2, 17.24, 17.28, 17.32, 17.36, 17.4, 17.44, 17.48, 17.52, 17.56, 17.6 };
   Double_t FeldmanCousinsLimit90_fy2[33] = { 0.0005841477, 0.0004392687, 0.0003642305, 0.0003356629, 0.0003266906, 0.0003081934, 0.0002883497, 0.0002829166, 0.0002831951, 0.0002830235, 0.0002825151, 0.0002815608, 0.0002807201, 0.0002776925, 0.0002793404, 0.0002815064, 0.0002768929,
   0.0002824696, 0.0002826098, 0.0002717196, 0.0002743508, 0.0002712904, 0.0002601383, 0.0002653161, 0.0002751591, 0.000272088, 0.0002685401, 0.0002930186, 0.0003784987, 0.0005271916, 0.0007077187, 0.0008950098, 0.001082905 };
   graph = new TGraph(33,FeldmanCousinsLimit90_fx2,FeldmanCousinsLimit90_fy2);
   graph->SetName("FeldmanCousinsLimit90");
   graph->SetTitle("");

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineStyle(3);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_FeldmanCousinsLimit902 = new TH1F("Graph_FeldmanCousinsLimit902","",100,16.192,17.728);
   Graph_FeldmanCousinsLimit902->SetMinimum(0.0001778617);
   Graph_FeldmanCousinsLimit902->SetMaximum(0.001165182);
   Graph_FeldmanCousinsLimit902->SetDirectory(nullptr);
   Graph_FeldmanCousinsLimit902->SetStats(0);
   Graph_FeldmanCousinsLimit902->SetLineWidth(2);
   Graph_FeldmanCousinsLimit902->SetMarkerStyle(20);
   Graph_FeldmanCousinsLimit902->GetXaxis()->SetLabelFont(42);
   Graph_FeldmanCousinsLimit902->GetXaxis()->SetLabelSize(0.06);
   Graph_FeldmanCousinsLimit902->GetXaxis()->SetTitleSize(0.06);
   Graph_FeldmanCousinsLimit902->GetXaxis()->SetTitleOffset(1.1);
   Graph_FeldmanCousinsLimit902->GetYaxis()->SetLabelFont(42);
   Graph_FeldmanCousinsLimit902->GetYaxis()->SetLabelSize(0.06);
   Graph_FeldmanCousinsLimit902->GetYaxis()->SetTitleSize(0.06);
   Graph_FeldmanCousinsLimit902->GetZaxis()->SetLabelFont(42);
   Graph_FeldmanCousinsLimit902->GetZaxis()->SetLabelSize(0.06);
   Graph_FeldmanCousinsLimit902->GetZaxis()->SetTitleSize(0.06);
   Graph_FeldmanCousinsLimit902->GetZaxis()->SetTitleOffset(0.7);
   graph->SetHistogram(Graph_FeldmanCousinsLimit902);
   
   graph->Draw("l");
   
   Double_t Limit90_fx3[75] = { 16.22, 16.24, 16.26, 16.28, 16.3, 16.32, 16.34, 16.36, 16.38, 16.4, 16.42, 16.44, 16.46, 16.48, 16.5, 16.52, 16.54,
   16.56, 16.58, 16.6, 16.62, 16.64, 16.66, 16.68, 16.7, 16.72, 16.74, 16.76, 16.78, 16.8, 16.82, 16.84, 16.86,
   16.88, 16.9, 16.92, 16.94, 16.96, 16.98, 17, 17.02, 17.04, 17.06, 17.08, 17.1, 17.12, 17.14, 17.16, 17.18,
   17.2, 17.22, 17.24, 17.26, 17.28, 17.3, 17.32, 17.34, 17.36, 17.38, 17.4, 17.42, 17.44, 17.46, 17.48, 17.5,
   17.52, 17.54, 17.56, 17.58, 17.6, 17.62, 17.64, 17.66, 17.68, 17.72 };
   Double_t Limit90_fy3[75] = { 0.001414559, 0.001434534, 0.001022348, 0.0008663482, 0.0007883777, 0.0006677409, 0.0005379125, 0.0004748263, 0.0004248814, 0.0004099984, 0.0004534625, 0.0004329768, 0.000457606, 0.0004476402, 0.000471426, 0.0004648586, 0.0004580005,
   0.0004143565, 0.0003770859, 0.0003473749, 0.0003544455, 0.0003181691, 0.0003371502, 0.0003544137, 0.000369548, 0.0003897471, 0.0004115586, 0.0004264531, 0.0004429471, 0.0004731301, 0.0004808648, 0.0004955855, 0.0005201148,
   0.000547896, 0.0005598785, 0.0005506359, 0.0005203321, 0.0004949267, 0.0004709538, 0.0004814272, 0.0004871744, 0.0005048149, 0.0004870222, 0.0004691466, 0.0004576068, 0.0004381751, 0.0004123326, 0.0003997946, 0.0003565928,
   0.0003712458, 0.0003598175, 0.0003529306, 0.0003453741, 0.0003181711, 0.0003251132, 0.0003594008, 0.0003385272, 0.0003552751, 0.0003320798, 0.0003425392, 0.000391874, 0.0004517871, 0.0005395835, 0.000641853, 0.0007845525,
   0.0008806787, 0.001047005, 0.001100906, 0.001680797, 0.001552166, 0.001590074, 0.002035636, 0.001859256, 0.001286641, 0.0015419 };
   graph = new TGraph(75,Limit90_fx3,Limit90_fy3);
   graph->SetName("Limit90");
   graph->SetTitle("");

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Limit903 = new TH1F("Graph_Limit903","",100,16.07,17.87);
   Graph_Limit903->SetMinimum(0.0001464224);
   Graph_Limit903->SetMaximum(0.002207382);
   Graph_Limit903->SetDirectory(nullptr);
   Graph_Limit903->SetStats(0);
   Graph_Limit903->SetLineWidth(2);
   Graph_Limit903->SetMarkerStyle(20);
   Graph_Limit903->GetXaxis()->SetLabelFont(42);
   Graph_Limit903->GetXaxis()->SetLabelSize(0.06);
   Graph_Limit903->GetXaxis()->SetTitleSize(0.06);
   Graph_Limit903->GetXaxis()->SetTitleOffset(1.1);
   Graph_Limit903->GetYaxis()->SetLabelFont(42);
   Graph_Limit903->GetYaxis()->SetLabelSize(0.06);
   Graph_Limit903->GetYaxis()->SetTitleSize(0.06);
   Graph_Limit903->GetZaxis()->SetLabelFont(42);
   Graph_Limit903->GetZaxis()->SetLabelSize(0.06);
   Graph_Limit903->GetZaxis()->SetTitleSize(0.06);
   Graph_Limit903->GetZaxis()->SetTitleOffset(0.7);
   graph->SetHistogram(Graph_Limit903);
   
   graph->Draw("l");
   
   TLegend *leg = new TLegend(0.64,0.65,0.85,0.88,NULL,"brNDC");
   leg->SetTextFont(62);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("NULL","90% CL UL: past experiments","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("KLOE_2015","KLOE 2015","f");
   entry->SetFillColor(17);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("NA64_2019","NA64 2019","f");
   entry->SetFillColor(14);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   leg->Draw();
   
   leg = new TLegend(0.64,0.32,0.85,0.58,NULL,"brNDC");
   leg->SetTextFont(62);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   entry=leg->AddEntry("NULL","90% CL UL: B-only","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Median90CLUL","CLs Median","L");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(2);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("ExpLimit90CL_2sigmaCov","CLs #pm2#sigma","f");
   entry->SetFillColor(41);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("ExpLimit90CL_1sigmaCov","CLs #pm1#sigma","f");
   entry->SetFillColor(30);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("FeldmanCousinsLimit90","Bkg stat only","L");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(3);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   leg->Draw();
   
   leg = new TLegend(0.64,0.22,0.85,0.3,NULL,"brNDC");
   leg->SetTextFont(62);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   entry=leg->AddEntry("Limit90","Observed limit","L");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   leg->Draw();
   
   TH2D *framepl__2 = new TH2D("framepl__2","",100,16,18.5,100,5e-05,0.001);
   framepl__2->SetStats(0);
   framepl__2->SetLineWidth(2);
   framepl__2->SetMarkerStyle(20);
   framepl__2->GetXaxis()->SetTitle("M_{X} (MeV)");
   framepl__2->GetXaxis()->SetLabelFont(42);
   framepl__2->GetXaxis()->SetLabelSize(0.04);
   framepl__2->GetXaxis()->SetTitleSize(0.05);
   framepl__2->GetXaxis()->SetTitleOffset(0.8);
   framepl__2->GetYaxis()->SetTitle("g_{ve}");
   framepl__2->GetYaxis()->SetNdivisions(3000505);
   framepl__2->GetYaxis()->SetLabelFont(42);
   framepl__2->GetYaxis()->SetLabelSize(0.065);
   framepl__2->GetYaxis()->SetTitleSize(0.08);
   framepl__2->GetYaxis()->SetTitleOffset(0.6);
   framepl__2->GetZaxis()->SetLabelFont(42);
   framepl__2->GetZaxis()->SetLabelSize(0.06);
   framepl__2->GetZaxis()->SetTitleSize(0.06);
   framepl__2->GetZaxis()->SetTitleOffset(0.7);
   framepl__2->Draw("sameaxis");
   dd_1__0->Modified();
   dd->cd();
  
// ------------>Primitives in pad: dd_2
   TPad *dd_2__1 = new TPad("dd_2", "dd_2",0,0,1,0.35);
   dd_2__1->Draw();
   dd_2__1->cd();
   dd_2__1->Range(15.53947,-4.405485,18.82895,0.30103);
   dd_2__1->SetFillColor(0);
   dd_2__1->SetBorderMode(0);
   dd_2__1->SetBorderSize(2);
   dd_2__1->SetLogy();
   dd_2__1->SetTickx(1);
   dd_2__1->SetTicky(1);
   dd_2__1->SetLeftMargin(0.14);
   dd_2__1->SetTopMargin(0);
   dd_2__1->SetBottomMargin(0.4);
   dd_2__1->SetFrameBorderMode(0);
   dd_2__1->SetFrameBorderMode(0);
   
   TH2D *frameplprob__3 = new TH2D("frameplprob__3","",100,16,18.5,110,0.003,2);
   frameplprob__3->SetStats(0);
   frameplprob__3->SetLineWidth(2);
   frameplprob__3->SetMarkerStyle(20);
   frameplprob__3->GetXaxis()->SetTitle("M_{X} (MeV)");
   frameplprob__3->GetXaxis()->SetLabelFont(42);
   frameplprob__3->GetXaxis()->SetLabelOffset(0.06);
   frameplprob__3->GetXaxis()->SetLabelSize(0.14);
   frameplprob__3->GetXaxis()->SetTitleSize(0.16);
   frameplprob__3->GetXaxis()->SetTitleOffset(1.1);
   frameplprob__3->GetYaxis()->SetTitle("P value");
   frameplprob__3->GetYaxis()->SetNdivisions(404);
   frameplprob__3->GetYaxis()->SetLabelFont(42);
   frameplprob__3->GetYaxis()->SetLabelSize(0.12);
   frameplprob__3->GetYaxis()->SetTitleSize(0.15);
   frameplprob__3->GetYaxis()->SetTitleOffset(0.3);
   frameplprob__3->GetZaxis()->SetLabelFont(42);
   frameplprob__3->GetZaxis()->SetLabelSize(0.06);
   frameplprob__3->GetZaxis()->SetTitleSize(0.06);
   frameplprob__3->GetZaxis()->SetTitleOffset(0.7);
   frameplprob__3->Draw("");
   
   Double_t LocalP_fx3005[60] = { 16.32, 16.36, 16.4, 16.44, 16.48, 16.52, 16.56, 16.6, 16.64, 16.68, 16.72, 16.76, 16.8, 16.84, 16.88, 16.92, 16.96,
   17, 17.04, 17.08, 17.12, 17.16, 17.2, 17.24, 17.28, 17.32, 17.36, 17.4, 17.44, 17.48, 16.34, 16.38, 16.42,
   16.46, 16.5, 16.54, 16.58, 16.62, 16.66, 16.7, 16.74, 16.78, 16.82, 16.86, 16.9, 16.94, 16.98, 17.02, 17.06,
   17.1, 17.14, 17.18, 17.22, 17.26, 17.3, 17.34, 17.38, 17.42, 17.46, 17.5 };
   Double_t LocalP_fy3005[60] = { 0.7792642, 0.8528428, 0.8528428, 0.7684564, 0.6577181, 0.4731544, 0.5618729, 0.8528428, 0.9364548, 0.8361204, 0.632107, 0.3478261, 0.1438127, 0.06397306, 0.01003344, 0.01006711, 0.1170569,
   0.147651, 0.08080808, 0.114094, 0.2274247, 0.5083612, 0.6120401, 0.8020134, 0.9297659, 0.7692308, 0.852349, 0.9328859, 0.8662207, 0.852349, 0.8160535, 0.8528428, 0.8106496,
   0.7130872, 0.5654362, 0.5175136, 0.7073579, 0.8946488, 0.8862876, 0.7341137, 0.4899666, 0.2458194, 0.1038929, 0.03700325, 0.01005028, 0.06356199, 0.1323539, 0.1142295, 0.09745102,
   0.1707594, 0.367893, 0.5602007, 0.7070268, 0.8658897, 0.8494983, 0.8107899, 0.8926174, 0.8995533, 0.8592849, 0.8454131 };
   Double_t LocalP_felx3005[60] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t LocalP_fely3005[60] = { 0.02450125, 0.02076425, 0.02076425, 0.02498861, 0.02840677, 0.03048087, 0.02993718, 0.02076425, 0.01410346, 0.02173833, 0.02889247, 0.0295503, 0.02311391, 0.01745074, 0.009615843, 0.009647789, 0.0215367,
   0.02336375, 0.01896629, 0.021386, 0.02670999, 0.03034098, 0.02925266, 0.02352687, 0.01479841, 0.02491471, 0.02082959, 0.01450367, 0.01991986, 0.02082959, 0.02263275, 0.02076425, 0.02287643,
   0.02669769, 0.02944382, 0.03020902, 0.02535072, 0.01743386, 0.0179209, 0.0253154, 0.02922139, 0.02633211, 0.02028233, 0.01353329, 0.009631816, 0.01559225, 0.02245023, 0.02116502, 0.02017615,
   0.024048, 0.02852549, 0.02979682, 0.02638977, 0.01916264, 0.01985656, 0.02287215, 0.01766663, 0.01721176, 0.02037472, 0.02128445 };
   Double_t LocalP_fehx3005[60] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t LocalP_fehy3005[60] = { 0.02648091, 0.02329345, 0.02329345, 0.02689613, 0.02951941, 0.03029202, 0.03037108, 0.02329345, 0.01733907, 0.02413981, 0.02982038, 0.0284807, 0.02055889, 0.01419651, 0.005436857, 0.005455085, 0.01877055,
   0.02082959, 0.01587164, 0.01858612, 0.02477909, 0.03039959, 0.03003915, 0.02568094, 0.01796908, 0.02682129, 0.02336375, 0.01771555, 0.02255304, 0.02336375, 0.02488718, 0.02329345, 0.02509479,
   0.02820777, 0.02990572, 0.03033155, 0.02683226, 0.02031626, 0.02073944, 0.02698009, 0.02915054, 0.0245198, 0.0173777, 0.009816684, 0.005445971, 0.01211282, 0.01980007, 0.01835061, 0.01722888,
   0.02168261, 0.02758934, 0.03021937, 0.02786005, 0.02182501, 0.02239518, 0.02509252, 0.02053965, 0.02013429, 0.0229584, 0.02376911 };
   grae = new TGraphAsymmErrors(60,LocalP_fx3005,LocalP_fy3005,LocalP_felx3005,LocalP_fehx3005,LocalP_fely3005,LocalP_fehy3005);
   grae->SetName("LocalP");
   grae->SetTitle("");
   grae->SetFillStyle(1000);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_LocalP3005 = new TH1F("Graph_LocalP3005","",100,16.202,17.618);
   Graph_LocalP3005->SetMinimum(0.0003758415);
   Graph_LocalP3005->SetMaximum(1.049132);
   Graph_LocalP3005->SetDirectory(nullptr);
   Graph_LocalP3005->SetStats(0);
   Graph_LocalP3005->SetLineWidth(2);
   Graph_LocalP3005->SetMarkerStyle(20);
   Graph_LocalP3005->GetXaxis()->SetLabelFont(42);
   Graph_LocalP3005->GetXaxis()->SetLabelSize(0.06);
   Graph_LocalP3005->GetXaxis()->SetTitleSize(0.06);
   Graph_LocalP3005->GetXaxis()->SetTitleOffset(1.1);
   Graph_LocalP3005->GetYaxis()->SetLabelFont(42);
   Graph_LocalP3005->GetYaxis()->SetLabelSize(0.06);
   Graph_LocalP3005->GetYaxis()->SetTitleSize(0.06);
   Graph_LocalP3005->GetZaxis()->SetLabelFont(42);
   Graph_LocalP3005->GetZaxis()->SetLabelSize(0.06);
   Graph_LocalP3005->GetZaxis()->SetTitleSize(0.06);
   Graph_LocalP3005->GetZaxis()->SetTitleOffset(0.7);
   grae->SetHistogram(Graph_LocalP3005);
   
   grae->Draw("p");
   
   Double_t p-value_fx3006[60] = { 16.32, 16.34, 16.36, 16.38, 16.4, 16.42, 16.44, 16.46, 16.48, 16.5, 16.52, 16.54, 16.56, 16.58, 16.6, 16.62, 16.64,
   16.66, 16.68, 16.7, 16.72, 16.74, 16.76, 16.78, 16.8, 16.82, 16.84, 16.86, 16.88, 16.9, 16.92, 16.94, 16.96,
   16.98, 17, 17.02, 17.04, 17.06, 17.08, 17.1, 17.12, 17.14, 17.16, 17.18, 17.2, 17.22, 17.24, 17.26, 17.28,
   17.3, 17.32, 17.34, 17.36, 17.38, 17.4, 17.42, 17.44, 17.46, 17.48, 17.5 };
   Double_t p-value_fy3006[60] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.9847732, 0.9698048, 0.9565217, 1, 1, 1, 1, 1,
   1, 1, 1, 1, 0.9621085, 0.9264346, 0.8148819, 0.6108265, 0.5551864, 0.4485455, 0.2380668, 0.05278397, 0.03865855, 0.07942612, 0.2854797, 0.5152909,
   0.6673186, 0.644612, 0.5988661, 0.4692067, 0.5138121, 0.5699054, 0.6469203, 0.7948943, 0.9424292, 0.9811158, 1, 1, 1, 1, 1, 1,
   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
   Double_t p-value_felx3006[60] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t p-value_fely3006[60] = { 0.008631159, 0.01676572, 0.01420253, 0.01898894, 0.01540429, 0.004086324, 0.009162493, 0.001753702, 0.003812224, -0.006737159, -0.009735791, -0.01176463, -0.001191136, 0.00911551, 0.0161232, 0.01497835, 0.02965961,
   0.02143701, 0.01407323, 0.007059867, -0.001189974, -0.01095728, -0.01516624, -0.02296969, -0.02941667, -0.03014924, -0.03053124, -0.02719248, -0.01605264, -0.01461079, -0.01863517, -0.02849694, -0.03044878,
   -0.02826299, -0.02878463, -0.02959537, -0.03057435, -0.03045828, -0.02999141, -0.02873597, -0.02393399, -0.01350389, -0.007639644, 0.006205271, 0.0008808985, 0.005148565, 0.007861884, 0.01173124, 0.02169262,
   0.01945493, 0.009555362, 0.01643951, 0.01245147, 0.02020584, 0.01838482, 0.01541578, 0.01146151, 0.01184098, 0.01050241, 0.01148301 };
   Double_t p-value_fehx3006[60] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t p-value_fehy3006[60] = { 0.0004690399, 0.006262286, 0.004436842, 0.007845612, 0.005292703, -0.002767684, 0.000847444, -0.004428923, -0.002962892, -0.01076582, -0.01341058, -0.01524402, -0.006526168, 0.0008139839, 0.005804693, 0.00498936, 0.01544501,
   0.009589068, 0.004344757, -0.0006499974, -0.00652534, -0.01451205, -0.01833032, -0.02522822, -0.03020033, -0.03053907, -0.03016776, -0.02532525, -0.01265851, -0.01106552, -0.01550987, -0.02697321, -0.03055676,
   -0.02944851, -0.02980826, -0.0302943, -0.03035688, -0.03055582, -0.03048531, -0.02977602, -0.02604348, -0.01682418, -0.01154225, -0.00125862, -0.005050513, -0.002011182, -7.881952e-05, 0.002676846, 0.009771103,
   0.008177477, 0.001127236, 0.006029966, 0.003189779, 0.008712257, 0.00741537, 0.005300886, 0.002484751, 0.002754996, 0.0018017, 0.002500063 };
   grae = new TGraphAsymmErrors(60,p-value_fx3006,p-value_fy3006,p-value_felx3006,p-value_fehx3006,p-value_fely3006,p-value_fehy3006);
   grae->SetName("p-value");
   grae->SetTitle("");
   grae->SetFillStyle(1000);
   grae->SetLineColor(2);
   grae->SetMarkerColor(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_pmIvalue3006 = new TH1F("Graph_pmIvalue3006","",100,16.202,17.618);
   Graph_pmIvalue3006->SetMinimum(0.0347927);
   Graph_pmIvalue3006->SetMaximum(1.113124);
   Graph_pmIvalue3006->SetDirectory(nullptr);
   Graph_pmIvalue3006->SetStats(0);
   Graph_pmIvalue3006->SetLineWidth(2);
   Graph_pmIvalue3006->SetMarkerStyle(20);
   Graph_pmIvalue3006->GetXaxis()->SetLabelFont(42);
   Graph_pmIvalue3006->GetXaxis()->SetLabelSize(0.06);
   Graph_pmIvalue3006->GetXaxis()->SetTitleSize(0.06);
   Graph_pmIvalue3006->GetXaxis()->SetTitleOffset(1.1);
   Graph_pmIvalue3006->GetYaxis()->SetLabelFont(42);
   Graph_pmIvalue3006->GetYaxis()->SetLabelSize(0.06);
   Graph_pmIvalue3006->GetYaxis()->SetTitleSize(0.06);
   Graph_pmIvalue3006->GetZaxis()->SetLabelFont(42);
   Graph_pmIvalue3006->GetZaxis()->SetLabelSize(0.06);
   Graph_pmIvalue3006->GetZaxis()->SetTitleSize(0.06);
   Graph_pmIvalue3006->GetZaxis()->SetTitleOffset(0.7);
   grae->SetHistogram(Graph_p-value3006);
   
   grae->Draw("p");
   
   leg = new TLegend(0.64,0.52,0.85,0.78,NULL,"brNDC");
   leg->SetTextFont(62);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   entry=leg->AddEntry("p-value","Global probability","P");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("LocalP","Local probability","P");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   leg->Draw();
   dd_2__1->Modified();
   dd->cd();
   dd->Modified();
   dd->SetSelected(dd);
}
