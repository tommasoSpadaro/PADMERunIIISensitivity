#ifdef __CLING__
#pragma cling optimize(0)
#endif
void Fig22b()
{
//=========Macro generated from canvas: dd/resultC
//=========  (Tue Jun 24 15:55:20 2025) by ROOT version 6.30/04
   TCanvas *dd = new TCanvas("dd", "resultC",0,66,970,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   dd->Range(15.53947,-0.000125,18.82895,0.001125);
   dd->SetFillColor(0);
   dd->SetBorderMode(0);
   dd->SetBorderSize(2);
   dd->SetTickx(1);
   dd->SetTicky(1);
   dd->SetLeftMargin(0.14);
   dd->SetBottomMargin(0.14);
   dd->SetFrameBorderMode(0);
   dd->SetFrameBorderMode(0);
   
   TH2D *framepl__1 = new TH2D("framepl__1","",100,16,18.5,100,5e-05,0.001);
   framepl__1->SetStats(0);
   framepl__1->SetLineWidth(2);
   framepl__1->SetMarkerStyle(20);
   framepl__1->GetXaxis()->SetTitle("M_{X} (MeV)");
   framepl__1->GetXaxis()->SetLabelFont(42);
   framepl__1->GetXaxis()->SetLabelOffset(0.006);
   framepl__1->GetXaxis()->SetLabelSize(0.06);
   framepl__1->GetXaxis()->SetTitleSize(0.05);
   framepl__1->GetXaxis()->SetTitleOffset(1.1);
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
   0.0001150434, 0.000125487, 0.0001202171, 0.0001275383, 0.0001118796, 0.0001161978, 0.0001349669, 0.0001076184, 0.0001268015, 0.0001581342, 0.0001435615, 0.0002158584, 0.0002359711, 0.0004653728, 0.0009110226, 0.001132821 };
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
   
   Double_t ExpLimit90CL_2sigmaCov_fx3005[72] = { 16.22, 16.24, 16.26, 16.28, 16.3, 16.32, 16.34, 16.36, 16.38, 16.4, 16.42, 16.44, 16.46, 16.48, 16.5, 16.52, 16.54,
   16.56, 16.58, 16.6, 16.62, 16.64, 16.66, 16.68, 16.7, 16.72, 16.74, 16.76, 16.78, 16.8, 16.82, 16.84, 16.86,
   16.88, 16.9, 16.92, 16.94, 16.96, 16.98, 17, 17.02, 17.04, 17.06, 17.08, 17.1, 17.12, 17.14, 17.16, 17.18,
   17.2, 17.22, 17.24, 17.26, 17.28, 17.3, 17.32, 17.34, 17.36, 17.38, 17.4, 17.42, 17.44, 17.46, 17.48, 17.5,
   17.52, 17.54, 17.56, 17.58, 17.6, 17.62, 17.64 };
   Double_t ExpLimit90CL_2sigmaCov_fy3005[72] = { 0.001435946, 0.001376968, 0.001167824, 0.0009824518, 0.0008171325, 0.0006809473, 0.0005889336, 0.0005135587, 0.0004682559, 0.0004446648, 0.000432597, 0.0004213005, 0.0004202311, 0.0004178979, 0.0004148734, 0.0003999324, 0.0003900492,
   0.0003805316, 0.0003730748, 0.0003695491, 0.0003707855, 0.0003745925, 0.0003755824, 0.0003894401, 0.0003996213, 0.0004173535, 0.0004320031, 0.0004502601, 0.0004742833, 0.0005007261, 0.0005300465, 0.0005654332, 0.0005866653,
   0.000612797, 0.0006213714, 0.0006120711, 0.0005955119, 0.0005615619, 0.0005281411, 0.0004950228, 0.0004671974, 0.0004378597, 0.0004052775, 0.000387048, 0.0003746853, 0.0003649226, 0.0003656345, 0.0003639105, 0.0003611885,
   0.0003569239, 0.0003515217, 0.0003525687, 0.0003589201, 0.0003650123, 0.0003738007, 0.0003710181, 0.0003724606, 0.0003731785, 0.00038081, 0.0004034501, 0.0004403025, 0.0005085034, 0.0006043586, 0.0007302536, 0.0008654035,
   0.001043581, 0.00118461, 0.001384227, 0.001513071, 0.001675487, 0.001776203, 0.00206474 };
   Double_t ExpLimit90CL_2sigmaCov_felx3005[72] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0 };
   Double_t ExpLimit90CL_2sigmaCov_fely3005[72] = { 0.0004143522, 0.000581905, 0.0003945369, 0.0003945124, 0.0003487157, 0.00020189, 0.0001879681, 0.0002193534, 0.00015452, 0.0001190123, 0.000116863, 0.000126295, 0.0001397433, 0.0001457168, 0.0001859974, 0.0001275035, 0.0001360746,
   0.0001374452, 0.0001441988, 0.0001003031, 0.000122255, 0.0001348283, 0.0001459062, 0.0001310824, 0.0001175217, 0.0001449246, 0.0001595742, 0.0001745091, 0.0001604235, 0.0001440208, 0.0001563016, 0.0001590236, 0.0001530351,
   0.0001846109, 0.0001957074, 0.0001980954, 0.0002250891, 0.0002204815, 0.0001925049, 0.0001681528, 0.0001512156, 0.0001348881, 0.0001131941, 0.000131966, 0.0001131447, 8.478841e-05, 9.532757e-05, 9.794032e-05, 0.0001072139,
   0.0001280479, 0.0001574323, 0.0001130521, 0.000137734, 0.0001282425, 0.0001580587, 0.0001315016, 0.0001348183, 0.0001242479, 0.000110503, 0.000120133, 0.0001460972, 0.0001409099, 0.0002012711, 0.000251444, 0.0002668236,
   0.0003460423, 0.0003707426, 0.0005488311, 0.0005702791, 0.0005824893, 0.0006648968, 0.00112196 };
   Double_t ExpLimit90CL_2sigmaCov_fehx3005[72] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0 };
   Double_t ExpLimit90CL_2sigmaCov_fehy3005[72] = { 0.0007682192, 0.0008206455, 0.0003700385, 0.0003270055, 0.0002764349, 0.0002256461, 0.0001562108, 0.0001444801, 0.0001446308, 0.0001568109, 0.0001711245, 0.0001757457, 0.0001452578, 0.0001296595, 0.0001204729, 0.0001172669, 0.0001155545,
   0.000112062, 0.0001270849, 0.0001448209, 0.0001544728, 0.0001800082, 0.0001932287, 0.0002011474, 0.0002127427, 0.0002014691, 0.0001824828, 0.0001654989, 0.0001735745, 0.0001660789, 0.0001476467, 0.0001252702, 0.0001118442,
   0.0001084491, 0.0001099627, 0.00011508, 0.000122412, 0.0001262194, 0.0001414932, 0.0001717822, 0.0001697723, 0.0001820703, 0.00018531, 0.0001675527, 0.0001679198, 0.0001776825, 0.0001660824, 0.0001525814, 0.0001531815,
   0.0001574461, 0.0001547894, 0.000153159, 0.0001450845, 0.0001571715, 0.0001482593, 0.0001401536, 0.0001527977, 0.0002140869, 0.0002935611, 0.0004070236, 0.0005226062, 0.0006612814, 0.000802845, 0.0009060979, 0.001043153,
   0.001179768, 0.0008461946, 0.0008428129, 0.000715224, 0.000564811, 0.0004876055, 0.000218001 };
   grae = new TGraphAsymmErrors(72,ExpLimit90CL_2sigmaCov_fx3005,ExpLimit90CL_2sigmaCov_fy3005,ExpLimit90CL_2sigmaCov_felx3005,ExpLimit90CL_2sigmaCov_fehx3005,ExpLimit90CL_2sigmaCov_fely3005,ExpLimit90CL_2sigmaCov_fehy3005);
   grae->SetName("ExpLimit90CL_2sigmaCov");
   grae->SetTitle("");

   ci = 1179;
   color = new TColor(ci, 0.4, 0.4, 1, " ", 0.35);
   grae->SetFillColor(ci);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_ExpLimit90CL_2sigmaCov3005 = new TH1F("Graph_ExpLimit90CL_2sigmaCov3005","",100,16.078,17.782);
   Graph_ExpLimit90CL_2sigmaCov3005->SetMinimum(0.0001746805);
   Graph_ExpLimit90CL_2sigmaCov3005->SetMaximum(0.002491607);
   Graph_ExpLimit90CL_2sigmaCov3005->SetDirectory(nullptr);
   Graph_ExpLimit90CL_2sigmaCov3005->SetStats(0);
   Graph_ExpLimit90CL_2sigmaCov3005->SetLineWidth(2);
   Graph_ExpLimit90CL_2sigmaCov3005->SetMarkerStyle(20);
   Graph_ExpLimit90CL_2sigmaCov3005->GetXaxis()->SetLabelFont(42);
   Graph_ExpLimit90CL_2sigmaCov3005->GetXaxis()->SetLabelSize(0.06);
   Graph_ExpLimit90CL_2sigmaCov3005->GetXaxis()->SetTitleSize(0.06);
   Graph_ExpLimit90CL_2sigmaCov3005->GetXaxis()->SetTitleOffset(1.1);
   Graph_ExpLimit90CL_2sigmaCov3005->GetYaxis()->SetLabelFont(42);
   Graph_ExpLimit90CL_2sigmaCov3005->GetYaxis()->SetLabelSize(0.06);
   Graph_ExpLimit90CL_2sigmaCov3005->GetYaxis()->SetTitleSize(0.06);
   Graph_ExpLimit90CL_2sigmaCov3005->GetZaxis()->SetLabelFont(42);
   Graph_ExpLimit90CL_2sigmaCov3005->GetZaxis()->SetLabelSize(0.06);
   Graph_ExpLimit90CL_2sigmaCov3005->GetZaxis()->SetTitleSize(0.06);
   Graph_ExpLimit90CL_2sigmaCov3005->GetZaxis()->SetTitleOffset(0.7);
   grae->SetHistogram(Graph_ExpLimit90CL_2sigmaCov3005);
   
   grae->Draw("3");
   
   Double_t ExpLimit90CL_1sigmaCov_fx3006[72] = { 16.22, 16.24, 16.26, 16.28, 16.3, 16.32, 16.34, 16.36, 16.38, 16.4, 16.42, 16.44, 16.46, 16.48, 16.5, 16.52, 16.54,
   16.56, 16.58, 16.6, 16.62, 16.64, 16.66, 16.68, 16.7, 16.72, 16.74, 16.76, 16.78, 16.8, 16.82, 16.84, 16.86,
   16.88, 16.9, 16.92, 16.94, 16.96, 16.98, 17, 17.02, 17.04, 17.06, 17.08, 17.1, 17.12, 17.14, 17.16, 17.18,
   17.2, 17.22, 17.24, 17.26, 17.28, 17.3, 17.32, 17.34, 17.36, 17.38, 17.4, 17.42, 17.44, 17.46, 17.48, 17.5,
   17.52, 17.54, 17.56, 17.58, 17.6, 17.62, 17.64 };
   Double_t ExpLimit90CL_1sigmaCov_fy3006[72] = { 0.001435946, 0.001376968, 0.001167824, 0.0009824518, 0.0008171325, 0.0006809473, 0.0005889336, 0.0005135587, 0.0004682559, 0.0004446648, 0.000432597, 0.0004213005, 0.0004202311, 0.0004178979, 0.0004148734, 0.0003999324, 0.0003900492,
   0.0003805316, 0.0003730748, 0.0003695491, 0.0003707855, 0.0003745925, 0.0003755824, 0.0003894401, 0.0003996213, 0.0004173535, 0.0004320031, 0.0004502601, 0.0004742833, 0.0005007261, 0.0005300465, 0.0005654332, 0.0005866653,
   0.000612797, 0.0006213714, 0.0006120711, 0.0005955119, 0.0005615619, 0.0005281411, 0.0004950228, 0.0004671974, 0.0004378597, 0.0004052775, 0.000387048, 0.0003746853, 0.0003649226, 0.0003656345, 0.0003639105, 0.0003611885,
   0.0003569239, 0.0003515217, 0.0003525687, 0.0003589201, 0.0003650123, 0.0003738007, 0.0003710181, 0.0003724606, 0.0003731785, 0.00038081, 0.0004034501, 0.0004403025, 0.0005085034, 0.0006043586, 0.0007302536, 0.0008654035,
   0.001043581, 0.00118461, 0.001384227, 0.001513071, 0.001675487, 0.001776203, 0.00206474 };
   Double_t ExpLimit90CL_1sigmaCov_felx3006[72] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0 };
   Double_t ExpLimit90CL_1sigmaCov_fely3006[72] = { 0.0002060276, 0.000242866, 0.0002331361, 0.0001658248, 0.0001153808, 9.025073e-05, 9.405802e-05, 7.000151e-05, 7.768209e-05, 5.274654e-05, 5.284236e-05, 6.426868e-05, 6.550096e-05, 6.17344e-05, 7.504449e-05, 6.162796e-05, 6.167499e-05,
   5.855946e-05, 5.001345e-05, 4.988541e-05, 5.329944e-05, 5.492887e-05, 4.613348e-05, 5.671058e-05, 6.200117e-05, 7.146331e-05, 7.856391e-05, 8.836457e-05, 8.929038e-05, 9.143033e-05, 7.598808e-05, 7.650852e-05, 7.97243e-05,
   9.49678e-05, 0.0001056131, 0.0001107704, 0.0001181294, 0.0001119802, 9.741765e-05, 9.530867e-05, 9.543611e-05, 9.026374e-05, 7.361472e-05, 6.774815e-05, 5.854425e-05, 4.657989e-05, 4.138548e-05, 4.765433e-05, 4.690026e-05,
   5.309886e-05, 5.38846e-05, 5.252633e-05, 5.428031e-05, 5.899495e-05, 6.754835e-05, 6.566625e-05, 5.985217e-05, 6.377702e-05, 5.313216e-05, 6.035554e-05, 5.75741e-05, 7.124705e-05, 7.551043e-05, 9.770033e-05, 0.0001387437,
   0.0001710732, 0.0001680149, 0.0002309547, 0.0002397666, 0.0003179432, 0.0003214624, 0.0006606731 };
   Double_t ExpLimit90CL_1sigmaCov_fehx3006[72] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0 };
   Double_t ExpLimit90CL_1sigmaCov_fehy3006[72] = { 0.0002823334, 0.0002235027, 0.0002228283, 0.0001842179, 0.0001498601, 0.0001092174, 7.815237e-05, 8.225368e-05, 7.85204e-05, 7.888644e-05, 7.701242e-05, 8.067702e-05, 7.544562e-05, 6.746945e-05, 6.084159e-05, 6.324554e-05, 5.912956e-05,
   6.251881e-05, 6.42699e-05, 6.92768e-05, 7.291886e-05, 7.670846e-05, 8.989839e-05, 9.418768e-05, 9.003097e-05, 9.951928e-05, 9.650408e-05, 9.962554e-05, 8.533306e-05, 8.205632e-05, 7.623362e-05, 6.720286e-05, 7.250052e-05,
   6.072061e-05, 5.940495e-05, 6.30432e-05, 6.107824e-05, 6.649472e-05, 7.126386e-05, 7.604857e-05, 7.096141e-05, 6.627343e-05, 7.274595e-05, 7.146355e-05, 6.204978e-05, 7.388122e-05, 8.04649e-05, 7.253499e-05, 6.621387e-05,
   6.892297e-05, 7.641596e-05, 9.396263e-05, 7.961725e-05, 6.954036e-05, 5.68347e-05, 5.990819e-05, 7.189771e-05, 8.380914e-05, 7.443655e-05, 8.075805e-05, 0.0001292702, 0.0001699515, 0.0002230491, 0.0002639322, 0.0002812173,
   0.0002535126, 0.0002423144, 0.0002211138, 0.0003815392, 0.0005151273, 0.0004328715, 0.0001492359 };
   grae = new TGraphAsymmErrors(72,ExpLimit90CL_1sigmaCov_fx3006,ExpLimit90CL_1sigmaCov_fy3006,ExpLimit90CL_1sigmaCov_felx3006,ExpLimit90CL_1sigmaCov_fehx3006,ExpLimit90CL_1sigmaCov_fely3006,ExpLimit90CL_1sigmaCov_fehy3006);
   grae->SetName("ExpLimit90CL_1sigmaCov");
   grae->SetTitle("");

   ci = 1180;
   color = new TColor(ci, 0, 0, 1, " ", 0.35);
   grae->SetFillColor(ci);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_ExpLimit90CL_1sigmaCov3006 = new TH1F("Graph_ExpLimit90CL_1sigmaCov3006","",100,16.078,17.782);
   Graph_ExpLimit90CL_1sigmaCov3006->SetMinimum(0.0001060032);
   Graph_ExpLimit90CL_1sigmaCov3006->SetMaximum(0.00240561);
   Graph_ExpLimit90CL_1sigmaCov3006->SetDirectory(nullptr);
   Graph_ExpLimit90CL_1sigmaCov3006->SetStats(0);
   Graph_ExpLimit90CL_1sigmaCov3006->SetLineWidth(2);
   Graph_ExpLimit90CL_1sigmaCov3006->SetMarkerStyle(20);
   Graph_ExpLimit90CL_1sigmaCov3006->GetXaxis()->SetLabelFont(42);
   Graph_ExpLimit90CL_1sigmaCov3006->GetXaxis()->SetLabelSize(0.06);
   Graph_ExpLimit90CL_1sigmaCov3006->GetXaxis()->SetTitleSize(0.06);
   Graph_ExpLimit90CL_1sigmaCov3006->GetXaxis()->SetTitleOffset(1.1);
   Graph_ExpLimit90CL_1sigmaCov3006->GetYaxis()->SetLabelFont(42);
   Graph_ExpLimit90CL_1sigmaCov3006->GetYaxis()->SetLabelSize(0.06);
   Graph_ExpLimit90CL_1sigmaCov3006->GetYaxis()->SetTitleSize(0.06);
   Graph_ExpLimit90CL_1sigmaCov3006->GetZaxis()->SetLabelFont(42);
   Graph_ExpLimit90CL_1sigmaCov3006->GetZaxis()->SetLabelSize(0.06);
   Graph_ExpLimit90CL_1sigmaCov3006->GetZaxis()->SetTitleSize(0.06);
   Graph_ExpLimit90CL_1sigmaCov3006->GetZaxis()->SetTitleOffset(0.7);
   grae->SetHistogram(Graph_ExpLimit90CL_1sigmaCov3006);
   
   grae->Draw("3");
   
   Double_t Median90CLUL_fx3[72] = { 16.22, 16.24, 16.26, 16.28, 16.3, 16.32, 16.34, 16.36, 16.38, 16.4, 16.42, 16.44, 16.46, 16.48, 16.5, 16.52, 16.54,
   16.56, 16.58, 16.6, 16.62, 16.64, 16.66, 16.68, 16.7, 16.72, 16.74, 16.76, 16.78, 16.8, 16.82, 16.84, 16.86,
   16.88, 16.9, 16.92, 16.94, 16.96, 16.98, 17, 17.02, 17.04, 17.06, 17.08, 17.1, 17.12, 17.14, 17.16, 17.18,
   17.2, 17.22, 17.24, 17.26, 17.28, 17.3, 17.32, 17.34, 17.36, 17.38, 17.4, 17.42, 17.44, 17.46, 17.48, 17.5,
   17.52, 17.54, 17.56, 17.58, 17.6, 17.62, 17.64 };
   Double_t Median90CLUL_fy3[72] = { 0.001435946, 0.001376968, 0.001167824, 0.0009824518, 0.0008171325, 0.0006809473, 0.0005889336, 0.0005135587, 0.0004682559, 0.0004446648, 0.000432597, 0.0004213005, 0.0004202311, 0.0004178979, 0.0004148734, 0.0003999324, 0.0003900492,
   0.0003805316, 0.0003730748, 0.0003695491, 0.0003707855, 0.0003745925, 0.0003755824, 0.0003894401, 0.0003996213, 0.0004173535, 0.0004320031, 0.0004502601, 0.0004742833, 0.0005007261, 0.0005300465, 0.0005654332, 0.0005866653,
   0.000612797, 0.0006213714, 0.0006120711, 0.0005955119, 0.0005615619, 0.0005281411, 0.0004950228, 0.0004671974, 0.0004378597, 0.0004052775, 0.000387048, 0.0003746853, 0.0003649226, 0.0003656345, 0.0003639105, 0.0003611885,
   0.0003569239, 0.0003515217, 0.0003525687, 0.0003589201, 0.0003650123, 0.0003738007, 0.0003710181, 0.0003724606, 0.0003731785, 0.00038081, 0.0004034501, 0.0004403025, 0.0005085034, 0.0006043586, 0.0007302536, 0.0008654035,
   0.001043581, 0.00118461, 0.001384227, 0.001513071, 0.001675487, 0.001776203, 0.00206474 };
   graph = new TGraph(72,Median90CLUL_fx3,Median90CLUL_fy3);
   graph->SetName("Median90CLUL");
   graph->SetTitle("");

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Median90CLUL3 = new TH1F("Graph_Median90CLUL3","",100,16.078,17.782);
   Graph_Median90CLUL3->SetMinimum(0.0001801999);
   Graph_Median90CLUL3->SetMaximum(0.002236062);
   Graph_Median90CLUL3->SetDirectory(nullptr);
   Graph_Median90CLUL3->SetStats(0);
   Graph_Median90CLUL3->SetLineWidth(2);
   Graph_Median90CLUL3->SetMarkerStyle(20);
   Graph_Median90CLUL3->GetXaxis()->SetLabelFont(42);
   Graph_Median90CLUL3->GetXaxis()->SetLabelSize(0.06);
   Graph_Median90CLUL3->GetXaxis()->SetTitleSize(0.06);
   Graph_Median90CLUL3->GetXaxis()->SetTitleOffset(1.1);
   Graph_Median90CLUL3->GetYaxis()->SetLabelFont(42);
   Graph_Median90CLUL3->GetYaxis()->SetLabelSize(0.06);
   Graph_Median90CLUL3->GetYaxis()->SetTitleSize(0.06);
   Graph_Median90CLUL3->GetZaxis()->SetLabelFont(42);
   Graph_Median90CLUL3->GetZaxis()->SetLabelSize(0.06);
   Graph_Median90CLUL3->GetZaxis()->SetTitleSize(0.06);
   Graph_Median90CLUL3->GetZaxis()->SetTitleOffset(0.7);
   graph->SetHistogram(Graph_Median90CLUL3);
   
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
   
   leg = new TLegend(0.64,0.6,0.85,0.73,NULL,"brNDC");
   leg->SetTextFont(62);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   entry=leg->AddEntry("NULL","90% CL UL: B + S #splitline{M_{X} = 16.9 MeV}{g_{ve} = 5 #times 10^{-4}}","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("ExpLimit90CL_2sigmaCov","CLs #pm2#sigma","f");

   ci = 1179;
   color = new TColor(ci, 0.4, 0.4, 1, " ", 0.35);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("ExpLimit90CL_1sigmaCov","CLs #pm1#sigma","f");

   ci = 1180;
   color = new TColor(ci, 0, 0, 1, " ", 0.35);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   leg->Draw();
   dd->Modified();
   dd->SetSelected(dd);
}
