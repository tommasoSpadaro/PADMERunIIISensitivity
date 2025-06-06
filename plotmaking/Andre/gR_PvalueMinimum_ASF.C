#ifdef __CLING__
#pragma cling optimize(0)
#endif
void gR_PvalueMinimum_ASF()
{
//=========Macro generated from canvas: rcanva/
//=========  (Thu May 29 19:57:45 2025) by ROOT version 6.34.08
   TCanvas *rcanva = new TCanvas("rcanva", "",428,94,1084,625);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   rcanva->Range(16.07895,0.9578947,17.65789,1.115789);
   rcanva->SetFillColor(0);
   rcanva->SetBorderMode(0);
   rcanva->SetBorderSize(2);
   rcanva->SetTickx(1);
   rcanva->SetTicky(1);
   rcanva->SetLeftMargin(0.14);
   rcanva->SetBottomMargin(0.14);
   rcanva->SetFrameBorderMode(0);
   rcanva->SetFrameBorderMode(0);
   
   TH1F *hframe__1__1 = new TH1F("hframe__1__1","",1000,16.3,17.5);
   hframe__1__1->SetMinimum(0.98);
   hframe__1__1->SetMaximum(1.1);
   hframe__1__1->SetDirectory(nullptr);
   hframe__1__1->SetStats(0);
   hframe__1__1->SetLineWidth(2);
   hframe__1__1->SetMarkerStyle(20);
   hframe__1__1->GetXaxis()->SetTitle("#sqrt{s} (MeV)");
   hframe__1__1->GetXaxis()->SetLabelFont(42);
   hframe__1__1->GetXaxis()->SetLabelSize(0.05);
   hframe__1__1->GetXaxis()->SetTitleSize(0.05);
   hframe__1__1->GetXaxis()->SetTitleOffset(1.1);
   hframe__1__1->GetXaxis()->SetTitleFont(42);
   hframe__1__1->GetYaxis()->SetTitle("g_{R}(s)");
   hframe__1__1->GetYaxis()->SetNdivisions(508);
   hframe__1__1->GetYaxis()->SetLabelFont(42);
   hframe__1__1->GetYaxis()->SetLabelSize(0.05);
   hframe__1__1->GetYaxis()->SetTitleSize(0.05);
   hframe__1__1->GetYaxis()->SetTitleOffset(1);
   hframe__1__1->GetYaxis()->SetTitleFont(42);
   hframe__1__1->GetZaxis()->SetLabelFont(42);
   hframe__1__1->GetZaxis()->SetLabelSize(0.06);
   hframe__1__1->GetZaxis()->SetTitleSize(0.06);
   hframe__1__1->GetZaxis()->SetTitleOffset(0.7);
   hframe__1__1->Draw(" ");
   
   Double_t gRSideband_scan0_fx1001[18] = { 17.12853, 17.26818, 17.22433, 17.17917, 17.40201, 17.35996, 17.31664, 17.09748, 17.06696, 16.76397, 16.71757, 16.67104, 16.62377, 16.57698, 16.52852, 16.48146, 16.43395,
   16.38631 };
   Double_t gRSideband_scan0_fy1001[18] = { 1.026729, 1.008153, 1.004202, 1.0069, 1.00892, 1.008644, 0.9971677, 1.012684, 1.013415, 1.015387, 1.018996, 1.00392, 1.023403, 1.01427, 1.019369, 1.017359, 1.012938,
   1.012131 };
   Double_t gRSideband_scan0_fex1001[18] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0 };
   Double_t gRSideband_scan0_fey1001[18] = { 0.009455707, 0.009862029, 0.00880463, 0.009194117, 0.009144612, 0.009271229, 0.008989457, 0.008927146, 0.00901735, 0.008905039, 0.008908521, 0.008785793, 0.008766435, 0.008713469, 0.008675957, 0.008740352, 0.008584832,
   0.00870339 };
   TGraphErrors *gre = new TGraphErrors(18,gRSideband_scan0_fx1001,gRSideband_scan0_fy1001,gRSideband_scan0_fex1001,gRSideband_scan0_fey1001);
   gre->SetName("gRSideband_scan0");
   gre->SetTitle("");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_gRSideband_scan010011001 = new TH1F("Graph_Graph_gRSideband_scan010011001","",100,16.28474,17.50358);
   Graph_Graph_gRSideband_scan010011001->SetMinimum(0.9833775);
   Graph_Graph_gRSideband_scan010011001->SetMaximum(1.040986);
   Graph_Graph_gRSideband_scan010011001->SetDirectory(nullptr);
   Graph_Graph_gRSideband_scan010011001->SetStats(0);
   Graph_Graph_gRSideband_scan010011001->SetLineWidth(2);
   Graph_Graph_gRSideband_scan010011001->SetMarkerStyle(20);
   Graph_Graph_gRSideband_scan010011001->GetXaxis()->SetLabelFont(42);
   Graph_Graph_gRSideband_scan010011001->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph_gRSideband_scan010011001->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_gRSideband_scan010011001->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph_gRSideband_scan010011001->GetYaxis()->SetLabelFont(42);
   Graph_Graph_gRSideband_scan010011001->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph_gRSideband_scan010011001->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_gRSideband_scan010011001->GetZaxis()->SetLabelFont(42);
   Graph_Graph_gRSideband_scan010011001->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_gRSideband_scan010011001->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_gRSideband_scan010011001->GetZaxis()->SetTitleOffset(0.7);
   gre->SetHistogram(Graph_Graph_gRSideband_scan010011001);
   
   gre->Draw("p");
   
   Double_t gRMasked_scan0_fx1002[5] = { 16.99856, 16.9516, 16.90572, 16.85911, 16.81358 };
   Double_t gRMasked_scan0_fy1002[5] = { 1.012926, 1.00132, 1.028507, 1.019103, 1.001825 };
   Double_t gRMasked_scan0_fex1002[5] = { 0, 0, 0, 0, 0 };
   Double_t gRMasked_scan0_fey1002[5] = { 0.008972418, 0.008988851, 0.008951434, 0.008859802, 0.008707782 };
   gre = new TGraphErrors(5,gRMasked_scan0_fx1002,gRMasked_scan0_fy1002,gRMasked_scan0_fex1002,gRMasked_scan0_fey1002);
   gre->SetName("gRMasked_scan0");
   gre->SetTitle("");
   gre->SetFillStyle(1000);
   gre->SetLineColor(2);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_gRMasked_scan010021002 = new TH1F("Graph_Graph_gRMasked_scan010021002","",100,16.79508,17.01706);
   Graph_Graph_gRMasked_scan010021002->SetMinimum(0.9878185);
   Graph_Graph_gRMasked_scan010021002->SetMaximum(1.041971);
   Graph_Graph_gRMasked_scan010021002->SetDirectory(nullptr);
   Graph_Graph_gRMasked_scan010021002->SetStats(0);
   Graph_Graph_gRMasked_scan010021002->SetLineWidth(2);
   Graph_Graph_gRMasked_scan010021002->SetMarkerStyle(20);
   Graph_Graph_gRMasked_scan010021002->GetXaxis()->SetLabelFont(42);
   Graph_Graph_gRMasked_scan010021002->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph_gRMasked_scan010021002->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_gRMasked_scan010021002->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph_gRMasked_scan010021002->GetYaxis()->SetLabelFont(42);
   Graph_Graph_gRMasked_scan010021002->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph_gRMasked_scan010021002->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_gRMasked_scan010021002->GetZaxis()->SetLabelFont(42);
   Graph_Graph_gRMasked_scan010021002->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_gRMasked_scan010021002->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_gRMasked_scan010021002->GetZaxis()->SetTitleOffset(0.7);
   gre->SetHistogram(Graph_Graph_gRMasked_scan010021002);
   
   gre->Draw("p");
   
   Double_t gRSideband_scan1_fx1003[14] = { 17.3367, 17.29449, 17.25071, 17.20592, 17.16429, 17.12077, 17.07475, 17.0289, 16.74658, 16.698, 16.65049, 16.60224, 16.55508, 17.38262 };
   Double_t gRSideband_scan1_fy1003[14] = { 1.01311, 1.010204, 1.004076, 1.012958, 1.001418, 1.006629, 1.013572, 1.024655, 1.008143, 1.020783, 1.00488, 0.9986968, 1.030587, 0.9903024 };
   Double_t gRSideband_scan1_fex1003[14] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t gRSideband_scan1_fey1003[14] = { 0.008467352, 0.008469653, 0.008515116, 0.007933675, 0.008531893, 0.009565486, 0.008650014, 0.008932393, 0.009063992, 0.009315198, 0.009131111, 0.009224836, 0.009701889, 0.008787948 };
   gre = new TGraphErrors(14,gRSideband_scan1_fx1003,gRSideband_scan1_fy1003,gRSideband_scan1_fex1003,gRSideband_scan1_fey1003);
   gre->SetName("gRSideband_scan1");
   gre->SetTitle("");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(21);
   
   TH1F *Graph_Graph_gRSideband_scan110031003 = new TH1F("Graph_Graph_gRSideband_scan110031003","",100,16.47233,17.46537);
   Graph_Graph_gRSideband_scan110031003->SetMinimum(0.975637);
   Graph_Graph_gRSideband_scan110031003->SetMaximum(1.046167);
   Graph_Graph_gRSideband_scan110031003->SetDirectory(nullptr);
   Graph_Graph_gRSideband_scan110031003->SetStats(0);
   Graph_Graph_gRSideband_scan110031003->SetLineWidth(2);
   Graph_Graph_gRSideband_scan110031003->SetMarkerStyle(20);
   Graph_Graph_gRSideband_scan110031003->GetXaxis()->SetLabelFont(42);
   Graph_Graph_gRSideband_scan110031003->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph_gRSideband_scan110031003->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_gRSideband_scan110031003->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph_gRSideband_scan110031003->GetYaxis()->SetLabelFont(42);
   Graph_Graph_gRSideband_scan110031003->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph_gRSideband_scan110031003->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_gRSideband_scan110031003->GetZaxis()->SetLabelFont(42);
   Graph_Graph_gRSideband_scan110031003->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_gRSideband_scan110031003->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_gRSideband_scan110031003->GetZaxis()->SetTitleOffset(0.7);
   gre->SetHistogram(Graph_Graph_gRSideband_scan110031003);
   
   gre->Draw("p");
   
   Double_t gRMasked_scan1_fx1004[5] = { 16.98232, 16.93562, 16.88848, 16.84394, 16.79442 };
   Double_t gRMasked_scan1_fy1004[5] = { 1.005783, 1.032281, 1.017949, 1.020221, 1.02862 };
   Double_t gRMasked_scan1_fex1004[5] = { 0, 0, 0, 0, 0 };
   Double_t gRMasked_scan1_fey1004[5] = { 0.008622201, 0.009202225, 0.009186063, 0.008986588, 0.009001324 };
   gre = new TGraphErrors(5,gRMasked_scan1_fx1004,gRMasked_scan1_fy1004,gRMasked_scan1_fex1004,gRMasked_scan1_fey1004);
   gre->SetName("gRMasked_scan1");
   gre->SetTitle("");
   gre->SetFillStyle(1000);
   gre->SetLineColor(2);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(21);
   
   TH1F *Graph_Graph_gRMasked_scan110041004 = new TH1F("Graph_Graph_gRMasked_scan110041004","",100,16.77563,17.00111);
   Graph_Graph_gRMasked_scan110041004->SetMinimum(0.9927282);
   Graph_Graph_gRMasked_scan110041004->SetMaximum(1.045916);
   Graph_Graph_gRMasked_scan110041004->SetDirectory(nullptr);
   Graph_Graph_gRMasked_scan110041004->SetStats(0);
   Graph_Graph_gRMasked_scan110041004->SetLineWidth(2);
   Graph_Graph_gRMasked_scan110041004->SetMarkerStyle(20);
   Graph_Graph_gRMasked_scan110041004->GetXaxis()->SetLabelFont(42);
   Graph_Graph_gRMasked_scan110041004->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph_gRMasked_scan110041004->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_gRMasked_scan110041004->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph_gRMasked_scan110041004->GetYaxis()->SetLabelFont(42);
   Graph_Graph_gRMasked_scan110041004->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph_gRMasked_scan110041004->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_gRMasked_scan110041004->GetZaxis()->SetLabelFont(42);
   Graph_Graph_gRMasked_scan110041004->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_gRMasked_scan110041004->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_gRMasked_scan110041004->GetZaxis()->SetTitleOffset(0.7);
   gre->SetHistogram(Graph_Graph_gRMasked_scan110041004);
   
   gre->Draw("p");
   
   Double_t SBFitOnBToyGraph_im34_ig20_mass1690_gven000550_pseudoEvts_fx1[42] = { 16.38631, 16.43395, 16.48146, 16.52852, 16.55508, 16.57698, 16.60224, 16.62377, 16.65049, 16.67104, 16.698, 16.71757, 16.74658, 16.76397, 16.79442, 16.81358, 16.84394,
   16.85911, 16.88848, 16.90572, 16.93562, 16.9516, 16.98232, 16.99856, 17.0289, 17.06696, 17.07475, 17.09748, 17.12077, 17.12853, 17.16429, 17.17917, 17.20592,
   17.22433, 17.25071, 17.26818, 17.29449, 17.31664, 17.3367, 17.35996, 17.38262, 17.40201 };
   Double_t SBFitOnBToyGraph_im34_ig20_mass1690_gven000550_pseudoEvts_fy1[42] = { 1.016472, 1.016021, 1.015587, 1.015178, 1.014962, 1.014794, 1.014617, 1.014485, 1.014354, 1.014288, 1.01427, 1.014329, 1.014598, 1.014924, 1.016034, 1.017325, 1.020888,
   1.023341, 1.027377, 1.027602, 1.023607, 1.02063, 1.016067, 1.014466, 1.012493, 1.011022, 1.010797, 1.010226, 1.009738, 1.009591, 1.008984, 1.008756, 1.008373,
   1.008124, 1.007782, 1.007563, 1.007243, 1.006981, 1.006748, 1.006481, 1.006225, 1.006008 };
   TGraph *graph = new TGraph(42,SBFitOnBToyGraph_im34_ig20_mass1690_gven000550_pseudoEvts_fx1,SBFitOnBToyGraph_im34_ig20_mass1690_gven000550_pseudoEvts_fy1);
   graph->SetName("SBFitOnBToyGraph_im34_ig20_mass1690_gven000550_pseudoEvts");
   graph->SetTitle("");
   graph->SetFillStyle(1000);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff6600");
   graph->SetLineColor(ci);
   graph->SetLineWidth(2);

   ci = TColor::GetColor("#ff6600");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_SBFitOnBToyGraph_im34_ig20_mass16dO900000_gven0dO000550_pseudoEvts11 = new TH1F("Graph_Graph_SBFitOnBToyGraph_im34_ig20_mass16dO900000_gven0dO000550_pseudoEvts11","",100,16.28474,17.50358);
   Graph_Graph_SBFitOnBToyGraph_im34_ig20_mass16dO900000_gven0dO000550_pseudoEvts11->SetMinimum(1.003849);
   Graph_Graph_SBFitOnBToyGraph_im34_ig20_mass16dO900000_gven0dO000550_pseudoEvts11->SetMaximum(1.029762);
   Graph_Graph_SBFitOnBToyGraph_im34_ig20_mass16dO900000_gven0dO000550_pseudoEvts11->SetDirectory(nullptr);
   Graph_Graph_SBFitOnBToyGraph_im34_ig20_mass16dO900000_gven0dO000550_pseudoEvts11->SetStats(0);
   Graph_Graph_SBFitOnBToyGraph_im34_ig20_mass16dO900000_gven0dO000550_pseudoEvts11->SetLineWidth(2);
   Graph_Graph_SBFitOnBToyGraph_im34_ig20_mass16dO900000_gven0dO000550_pseudoEvts11->SetMarkerStyle(20);
   Graph_Graph_SBFitOnBToyGraph_im34_ig20_mass16dO900000_gven0dO000550_pseudoEvts11->GetXaxis()->SetLabelFont(42);
   Graph_Graph_SBFitOnBToyGraph_im34_ig20_mass16dO900000_gven0dO000550_pseudoEvts11->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph_SBFitOnBToyGraph_im34_ig20_mass16dO900000_gven0dO000550_pseudoEvts11->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_SBFitOnBToyGraph_im34_ig20_mass16dO900000_gven0dO000550_pseudoEvts11->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph_SBFitOnBToyGraph_im34_ig20_mass16dO900000_gven0dO000550_pseudoEvts11->GetYaxis()->SetLabelFont(42);
   Graph_Graph_SBFitOnBToyGraph_im34_ig20_mass16dO900000_gven0dO000550_pseudoEvts11->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph_SBFitOnBToyGraph_im34_ig20_mass16dO900000_gven0dO000550_pseudoEvts11->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_SBFitOnBToyGraph_im34_ig20_mass16dO900000_gven0dO000550_pseudoEvts11->GetZaxis()->SetLabelFont(42);
   Graph_Graph_SBFitOnBToyGraph_im34_ig20_mass16dO900000_gven0dO000550_pseudoEvts11->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_SBFitOnBToyGraph_im34_ig20_mass16dO900000_gven0dO000550_pseudoEvts11->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_SBFitOnBToyGraph_im34_ig20_mass16dO900000_gven0dO000550_pseudoEvts11->GetZaxis()->SetTitleOffset(0.7);
   graph->SetHistogram(Graph_Graph_SBFitOnBToyGraph_im34_ig20_mass16dO900000_gven0dO000550_pseudoEvts11);
   
   graph->Draw("pl");
   
   TF1 *sideband01 = new TF1("sideband0","[0]+[1]*(x-16.92)",16,16.76397, TF1::EAddToList::kDefault);
   sideband01->SetFillColor(19);
   sideband01->SetFillStyle(0);
   sideband01->SetMarkerStyle(20);
   sideband01->SetLineColor(4);
   sideband01->SetLineWidth(3);
   sideband01->GetXaxis()->SetLabelFont(42);
   sideband01->GetXaxis()->SetLabelSize(0.06);
   sideband01->GetXaxis()->SetTitleSize(0.06);
   sideband01->GetXaxis()->SetTitleOffset(1.1);
   sideband01->GetYaxis()->SetLabelFont(42);
   sideband01->GetYaxis()->SetLabelSize(0.06);
   sideband01->GetYaxis()->SetTitleSize(0.06);
   sideband01->SetParameter(0,1.0116);
   sideband01->SetParError(0,0);
   sideband01->SetParLimits(0,0,0);
   sideband01->SetParameter(1,-0.0103);
   sideband01->SetParError(1,0);
   sideband01->SetParLimits(1,0,0);
   sideband01->Draw("Lsame");
   
   TF1 *sideband12 = new TF1("sideband1","[0]+[1]*(x-16.92)",16.79442,16.99856, TF1::EAddToList::kDefault);
   sideband12->SetFillColor(19);
   sideband12->SetFillStyle(0);
   sideband12->SetMarkerStyle(20);
   sideband12->SetLineColor(2);
   sideband12->SetLineStyle(2);
   sideband12->SetLineWidth(3);
   sideband12->GetXaxis()->SetLabelFont(42);
   sideband12->GetXaxis()->SetLabelSize(0.06);
   sideband12->GetXaxis()->SetTitleSize(0.06);
   sideband12->GetXaxis()->SetTitleOffset(1.1);
   sideband12->GetYaxis()->SetLabelFont(42);
   sideband12->GetYaxis()->SetLabelSize(0.06);
   sideband12->GetYaxis()->SetTitleSize(0.06);
   sideband12->SetParameter(0,1.0116);
   sideband12->SetParError(0,0);
   sideband12->SetParLimits(0,0,0);
   sideband12->SetParameter(1,-0.0103);
   sideband12->SetParError(1,0);
   sideband12->SetParLimits(1,0,0);
   sideband12->Draw("Lsame");
   
   TF1 *sideband23 = new TF1("sideband2","[0]+[1]*(x-16.92)",17.0289,18, TF1::EAddToList::kDefault);
   sideband23->SetFillColor(19);
   sideband23->SetFillStyle(0);
   sideband23->SetMarkerStyle(20);
   sideband23->SetLineColor(4);
   sideband23->SetLineWidth(3);
   sideband23->GetXaxis()->SetLabelFont(42);
   sideband23->GetXaxis()->SetLabelSize(0.06);
   sideband23->GetXaxis()->SetTitleSize(0.06);
   sideband23->GetXaxis()->SetTitleOffset(1.1);
   sideband23->GetYaxis()->SetLabelFont(42);
   sideband23->GetYaxis()->SetLabelSize(0.06);
   sideband23->GetYaxis()->SetTitleSize(0.06);
   sideband23->SetParameter(0,1.0116);
   sideband23->SetParError(0,0);
   sideband23->SetParLimits(0,0,0);
   sideband23->SetParameter(1,-0.0103);
   sideband23->SetParError(1,0);
   sideband23->SetParLimits(1,0,0);
   sideband23->Draw("Lsame");
   
   TLegend *leg = new TLegend(0.5508318,0.5514834,0.8743068,0.8656195,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(62);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("gRSideband_scan0","Sideband data, scan 1","PE");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("gRSideband_scan1","Sideband data, scan 2","PE");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("gRMasked_scan0","Masked data, scan 1","PE");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("gRMasked_scan1","Masked data, scan 2","PE");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("sideband0","Sideband fit","L");
   entry->SetLineColor(4);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("sideband1","Sideband fit in masked region","L");
   entry->SetLineColor(2);
   entry->SetLineStyle(2);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("SBFitOnBToyGraph_im34_ig20_mass1690_gven000550_pseudoEvts","S+B fit","PL");

   ci = TColor::GetColor("#ff6600");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#ff6600");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   leg->Draw();
   TLatex *   tex = new TLatex(16.35475,1.085754,"PADME");
   tex->SetTextSize(0.08);
   tex->SetLineWidth(2);
   tex->Draw();
   rcanva->Modified();
   rcanva->SetSelected(rcanva);
   rcanva->ToggleToolBar();

   rcanva->Print("gR_PvalueMinimum_ASF.pdf");
}
