#ifdef __CLING__
#pragma cling optimize(0)
#endif
void Fig22a()
{
//=========Macro generated from canvas: dd/resultC
//=========  (Tue Jun 24 15:47:05 2025) by ROOT version 6.30/04
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
   framepl__1->GetXaxis()->SetLabelOffset(0.008);
   framepl__1->GetXaxis()->SetLabelSize(0.06);
   framepl__1->GetXaxis()->SetTitleSize(0.05);
   framepl__1->GetXaxis()->SetTitleOffset(1.2);
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
   0.0003779947, 0.0003843368, 0.0003716408, 0.0003706964, 0.0003861992, 0.0003828905, 0.000388508, 0.0003982141, 0.0004025532, 0.0004068418, 0.0004282513, 0.0005331418, 0.0007638186, 0.001088978, 0.001407929, 0.001623667 };
   Double_t ExpLimit90CL_2sigmaCov_felx3003[33] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t ExpLimit90CL_2sigmaCov_fely3003[33] = { 0.0002904837, 0.0001857749, 0.0001636238, 0.0001421503, 0.0001517487, 0.0001386573, 0.0001380445, 0.0001360847, 0.0001463502, 0.0001260159, 0.0001190626, 0.0001076797, 0.0001301486, 0.0001461813, 0.0001089824, 0.0001182721, 0.0001148067,
   0.0001150434, 0.000125487, 0.0001202171, 0.0001275383, 0.0001118796, 0.0001161978, 0.0001349669, 0.0001076184, 0.0001268015, 0.0001581342, 0.0001435615, 0.0002158584, 0.0002359711, 0.0004345622, 0.0008225314, 0.00111013 };
   Double_t ExpLimit90CL_2sigmaCov_fehx3003[33] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t ExpLimit90CL_2sigmaCov_fehy3003[33] = { 0.0004405024, 0.0002668924, 0.0002128128, 0.0002056993, 0.0001983109, 0.0001700616, 0.0001543501, 0.0001637634, 0.0001428124, 0.0001449276, 0.0001546982, 0.0001472576, 0.0001468758, 0.0001600068, 0.0001437654, 0.0001497049, 0.0001708101,
   0.0001767157, 0.000168246, 0.000155509, 0.0001621613, 0.0001683875, 0.0001695275, 0.0001709161, 0.0001726694, 0.0001846271, 0.0002130556, 0.0004701359, 0.0007237743, 0.0007219937, 0.0005827669, 0.0008216119, 0.0006121038 };
   grae = new TGraphAsymmErrors(33,ExpLimit90CL_2sigmaCov_fx3003,ExpLimit90CL_2sigmaCov_fy3003,ExpLimit90CL_2sigmaCov_felx3003,ExpLimit90CL_2sigmaCov_fehx3003,ExpLimit90CL_2sigmaCov_fely3003,ExpLimit90CL_2sigmaCov_fehy3003);
   grae->SetName("ExpLimit90CL_2sigmaCov");
   grae->SetTitle("");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#cccc00");
   grae->SetFillColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_ExpLimit90CL_2sigmaCov3003 = new TH1F("Graph_ExpLimit90CL_2sigmaCov3003","",100,16.192,17.728);
   Graph_ExpLimit90CL_2sigmaCov3003->SetMinimum(2.530472e-05);
   Graph_ExpLimit90CL_2sigmaCov3003->SetMaximum(0.002436722);
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
   0.0003779947, 0.0003843368, 0.0003716408, 0.0003706964, 0.0003861992, 0.0003828905, 0.000388508, 0.0003982141, 0.0004025532, 0.0004068418, 0.0004282513, 0.0005331418, 0.0007638186, 0.001088978, 0.001407929, 0.001623667 };
   Double_t ExpLimit90CL_1sigmaCov_felx3004[33] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t ExpLimit90CL_1sigmaCov_fely3004[33] = { 0.000118898, 8.31281e-05, 8.182931e-05, 7.641821e-05, 7.6369e-05, 6.59717e-05, 6.789755e-05, 6.285332e-05, 6.29353e-05, 6.081552e-05, 6.336868e-05, 6.491993e-05, 5.980175e-05, 6.236174e-05, 5.405464e-05, 5.803152e-05, 5.828874e-05,
   5.449262e-05, 6.701796e-05, 6.318193e-05, 5.231354e-05, 6.282953e-05, 6.270046e-05, 5.905307e-05, 6.009971e-05, 6.420276e-05, 6.264224e-05, 6.560246e-05, 8.26547e-05, 0.0001197982, 0.00018807, 0.0002734073, 0.0003318541 };
   Double_t ExpLimit90CL_1sigmaCov_fehx3004[33] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t ExpLimit90CL_1sigmaCov_fehy3004[33] = { 0.0001698423, 0.0001077543, 9.907086e-05, 9.202744e-05, 8.621697e-05, 7.809322e-05, 7.115239e-05, 7.78531e-05, 6.726614e-05, 6.931747e-05, 7.417704e-05, 7.565433e-05, 7.37267e-05, 8.070626e-05, 7.491935e-05, 7.131715e-05, 7.799971e-05,
   8.958077e-05, 7.123157e-05, 6.909962e-05, 7.786763e-05, 7.547402e-05, 7.929165e-05, 8.314167e-05, 8.128371e-05, 8.698469e-05, 8.416464e-05, 0.0001006525, 0.0001420215, 0.0002283061, 0.0002590535, 0.0002975857, 0.0005624817 };
   grae = new TGraphAsymmErrors(33,ExpLimit90CL_1sigmaCov_fx3004,ExpLimit90CL_1sigmaCov_fy3004,ExpLimit90CL_1sigmaCov_felx3004,ExpLimit90CL_1sigmaCov_fehx3004,ExpLimit90CL_1sigmaCov_fely3004,ExpLimit90CL_1sigmaCov_fehy3004);
   grae->SetName("ExpLimit90CL_1sigmaCov");
   grae->SetTitle("");

   ci = TColor::GetColor("#00cc00");
   grae->SetFillColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_ExpLimit90CL_1sigmaCov3004 = new TH1F("Graph_ExpLimit90CL_1sigmaCov3004","",100,16.192,17.728);
   Graph_ExpLimit90CL_1sigmaCov3004->SetMinimum(0.0001206899);
   Graph_ExpLimit90CL_1sigmaCov3004->SetMaximum(0.002373918);
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
   0.0003779947, 0.0003843368, 0.0003716408, 0.0003706964, 0.0003861992, 0.0003828905, 0.000388508, 0.0003982141, 0.0004025532, 0.0004068418, 0.0004282513, 0.0005331418, 0.0007638186, 0.001088978, 0.001407929, 0.001623667 };
   TGraph *graph = new TGraph(33,Median90CLUL_fx1,Median90CLUL_fy1);
   graph->SetName("Median90CLUL");
   graph->SetTitle("");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Median90CLUL1 = new TH1F("Graph_Median90CLUL1","",100,16.192,17.728);
   Graph_Median90CLUL1->SetMinimum(0.0002453993);
   Graph_Median90CLUL1->SetMaximum(0.001748964);
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
   
   Double_t Median90CLULRL_fx2[33] = { 16.32, 16.36, 16.4, 16.44, 16.48, 16.52, 16.56, 16.6, 16.64, 16.68, 16.72, 16.76, 16.8, 16.84, 16.88, 16.92, 16.96,
   17, 17.04, 17.08, 17.12, 17.16, 17.2, 17.24, 17.28, 17.32, 17.36, 17.4, 17.44, 17.48, 17.52, 17.56, 17.6 };
   Double_t Median90CLULRL_fy2[33] = { 0.0008035956, 0.0006030671, 0.0004986322, 0.0004609288, 0.0004499181, 0.0004271182, 0.0003948645, 0.0003931963, 0.0003961992, 0.0003938159, 0.0003921953, 0.0003808509, 0.0003845212, 0.0003630558, 0.0003751787, 0.0003771807, 0.0003838538,
   0.0003870792, 0.0003811846, 0.0003680384, 0.0003668373, 0.0003764021, 0.0003655026, 0.0003770377, 0.0003785153, 0.000365169, 0.0003710636, 0.000404207, 0.0005266594, 0.0007325264, 0.000976764, 0.001234126, 0.00148993 };
   graph = new TGraph(33,Median90CLULRL_fx2,Median90CLULRL_fy2);
   graph->SetName("Median90CLULRL");
   graph->SetTitle("");
   graph->SetFillStyle(1000);
   graph->SetLineStyle(2);
   graph->SetLineWidth(2);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Median90CLULRL2 = new TH1F("Graph_Median90CLULRL2","",100,16.192,17.728);
   Graph_Median90CLULRL2->SetMinimum(0.0002503684);
   Graph_Median90CLULRL2->SetMaximum(0.001602617);
   Graph_Median90CLULRL2->SetDirectory(nullptr);
   Graph_Median90CLULRL2->SetStats(0);
   Graph_Median90CLULRL2->SetLineWidth(2);
   Graph_Median90CLULRL2->SetMarkerStyle(20);
   Graph_Median90CLULRL2->GetXaxis()->SetLabelFont(42);
   Graph_Median90CLULRL2->GetXaxis()->SetLabelSize(0.06);
   Graph_Median90CLULRL2->GetXaxis()->SetTitleSize(0.06);
   Graph_Median90CLULRL2->GetXaxis()->SetTitleOffset(1.1);
   Graph_Median90CLULRL2->GetYaxis()->SetLabelFont(42);
   Graph_Median90CLULRL2->GetYaxis()->SetLabelSize(0.06);
   Graph_Median90CLULRL2->GetYaxis()->SetTitleSize(0.06);
   Graph_Median90CLULRL2->GetZaxis()->SetLabelFont(42);
   Graph_Median90CLULRL2->GetZaxis()->SetLabelSize(0.06);
   Graph_Median90CLULRL2->GetZaxis()->SetTitleSize(0.06);
   Graph_Median90CLULRL2->GetZaxis()->SetTitleOffset(0.7);
   graph->SetHistogram(Graph_Median90CLULRL2);
   
   graph->Draw("l");
   
   Double_t FeldmanCousinsLimit90_fx3[33] = { 16.32, 16.36, 16.4, 16.44, 16.48, 16.52, 16.56, 16.6, 16.64, 16.68, 16.72, 16.76, 16.8, 16.84, 16.88, 16.92, 16.96,
   17, 17.04, 17.08, 17.12, 17.16, 17.2, 17.24, 17.28, 17.32, 17.36, 17.4, 17.44, 17.48, 17.52, 17.56, 17.6 };
   Double_t FeldmanCousinsLimit90_fy3[33] = { 0.0005841477, 0.0004392687, 0.0003642305, 0.0003356629, 0.0003266906, 0.0003081934, 0.0002883497, 0.0002829166, 0.0002831951, 0.0002830235, 0.0002825151, 0.0002815608, 0.0002807201, 0.0002776925, 0.0002793404, 0.0002815064, 0.0002768929,
   0.0002824696, 0.0002826098, 0.0002717196, 0.0002743508, 0.0002712904, 0.0002601383, 0.0002653161, 0.0002751591, 0.000272088, 0.0002685401, 0.0002930186, 0.0003784987, 0.0005271916, 0.0007077187, 0.0008950098, 0.001082905 };
   graph = new TGraph(33,FeldmanCousinsLimit90_fx3,FeldmanCousinsLimit90_fy3);
   graph->SetName("FeldmanCousinsLimit90");
   graph->SetTitle("");

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineStyle(3);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_FeldmanCousinsLimit903 = new TH1F("Graph_FeldmanCousinsLimit903","",100,16.192,17.728);
   Graph_FeldmanCousinsLimit903->SetMinimum(0.0001778617);
   Graph_FeldmanCousinsLimit903->SetMaximum(0.001165182);
   Graph_FeldmanCousinsLimit903->SetDirectory(nullptr);
   Graph_FeldmanCousinsLimit903->SetStats(0);
   Graph_FeldmanCousinsLimit903->SetLineWidth(2);
   Graph_FeldmanCousinsLimit903->SetMarkerStyle(20);
   Graph_FeldmanCousinsLimit903->GetXaxis()->SetLabelFont(42);
   Graph_FeldmanCousinsLimit903->GetXaxis()->SetLabelSize(0.06);
   Graph_FeldmanCousinsLimit903->GetXaxis()->SetTitleSize(0.06);
   Graph_FeldmanCousinsLimit903->GetXaxis()->SetTitleOffset(1.1);
   Graph_FeldmanCousinsLimit903->GetYaxis()->SetLabelFont(42);
   Graph_FeldmanCousinsLimit903->GetYaxis()->SetLabelSize(0.06);
   Graph_FeldmanCousinsLimit903->GetYaxis()->SetTitleSize(0.06);
   Graph_FeldmanCousinsLimit903->GetZaxis()->SetLabelFont(42);
   Graph_FeldmanCousinsLimit903->GetZaxis()->SetLabelSize(0.06);
   Graph_FeldmanCousinsLimit903->GetZaxis()->SetTitleSize(0.06);
   Graph_FeldmanCousinsLimit903->GetZaxis()->SetTitleOffset(0.7);
   graph->SetHistogram(Graph_FeldmanCousinsLimit903);
   
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

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("ExpLimit90CL_2sigmaCov","CLs #pm2#sigma","f");

   ci = TColor::GetColor("#cccc00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("ExpLimit90CL_1sigmaCov","CLs #pm1#sigma","f");

   ci = TColor::GetColor("#00cc00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Median90CLULRL","RL median","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(2);
   entry->SetLineWidth(2);
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
   dd->Modified();
   dd->SetSelected(dd);
}
