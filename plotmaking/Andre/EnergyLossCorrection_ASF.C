#ifdef __CLING__
#pragma cling optimize(0)
#endif
void EnergyLossCorrection_ASF()
{
//=========Macro generated from canvas: Energy loss correction/
//=========  (Thu May 29 20:37:40 2025) by ROOT version 6.34.08
   TCanvas *Energy_loss_correction = new TCanvas("Energy loss correction", "",266,200,700,527);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   Energy_loss_correction->Range(0,0,1,1);
   Energy_loss_correction->SetFillColor(0);
   Energy_loss_correction->SetBorderMode(0);
   Energy_loss_correction->SetBorderSize(2);
   Energy_loss_correction->SetTickx(1);
   Energy_loss_correction->SetTicky(1);
   Energy_loss_correction->SetLeftMargin(0.14);
   Energy_loss_correction->SetBottomMargin(0.14);
   Energy_loss_correction->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: Energy loss correction_1
   TPad *Energy__0 = new TPad("Energy loss correction_1", "Energy loss correction_1",0.01,0.51,0.99,0.99);
   Energy__0->Draw();
   Energy__0->cd();
   Energy__0->Range(-10.60526,0.9352632,47.28947,1.040526);
   Energy__0->SetFillColor(0);
   Energy__0->SetBorderMode(0);
   Energy__0->SetBorderSize(2);
   Energy__0->SetTickx(1);
   Energy__0->SetTicky(1);
   Energy__0->SetLeftMargin(0.14);
   Energy__0->SetBottomMargin(0.14);
   Energy__0->SetFrameBorderMode(0);
   Energy__0->SetFrameBorderMode(0);
   
   TH1F *hframe__1__1 = new TH1F("hframe__1__1","",1000,-2.5,41.5);
   hframe__1__1->SetMinimum(0.95);
   hframe__1__1->SetMaximum(1.03);
   hframe__1__1->SetDirectory(nullptr);
   hframe__1__1->SetStats(0);
   hframe__1__1->SetLineWidth(2);
   hframe__1__1->SetMarkerStyle(20);
   hframe__1__1->GetXaxis()->SetTitle("Energy point ID");
   hframe__1__1->GetXaxis()->SetLabelFont(42);
   hframe__1__1->GetXaxis()->SetLabelSize(0.06);
   hframe__1__1->GetXaxis()->SetTitleSize(0.06);
   hframe__1__1->GetXaxis()->SetTitleOffset(1.1);
   hframe__1__1->GetXaxis()->SetTitleFont(42);
   hframe__1__1->GetYaxis()->SetTitle("Energy loss correction");
   hframe__1__1->GetYaxis()->SetNdivisions(404);
   hframe__1__1->GetYaxis()->SetLabelFont(42);
   hframe__1__1->GetYaxis()->SetLabelSize(0.06);
   hframe__1__1->GetYaxis()->SetTitleSize(0.06);
   hframe__1__1->GetYaxis()->SetTitleOffset(0.8);
   hframe__1__1->GetYaxis()->SetTitleFont(42);
   hframe__1__1->GetZaxis()->SetLabelFont(42);
   hframe__1__1->GetZaxis()->SetLabelSize(0.06);
   hframe__1__1->GetZaxis()->SetTitleSize(0.06);
   hframe__1__1->GetZaxis()->SetTitleOffset(0.7);
   hframe__1__1->Draw(" ");
   
   Double_t __fx1001[42] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
   17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
   33, 34, 35, 36, 37, 38, 39, 40, 41 };
   Double_t __fy1001[42] = { 0.9944352, 1.014291, 1.008072, 1.005927, 1.016724, 1.012942, 1.010146, 1.009457, 1.004909, 1.003082, 1.015807, 1.013836, 1.009644, 1.012485, 1.019631, 1.022899, 1.021129,
   1.02123, 1.022159, 1.012793, 1.011487, 1.01472, 1.020656, 0.9730698, 0.9598112, 0.9856738, 0.9792465, 0.9865644, 0.9935748, 1.002941, 0.969795, 0.9729065, 0.9826323,
   0.9725767, 0.9760711, 0.9830819, 0.9784367, 0.9653267, 0.9803185, 0.9857538, 0.9884436, 0.99728 };
   Double_t __fex1001[42] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t __fey1001[42] = { 0.0002818612, 0.0002659186, 0.0002486143, 0.0002682301, 0.0002359447, 0.0002321721, 0.0002507024, 0.0003141871, 0.0002445756, 0.0002504034, 0.000258126, 0.0002522125, 0.0002737013, 0.0002504168, 0.0002661665, 0.0002374665, 0.0002711027,
   0.0002526671, 0.000285678, 0.0002489368, 0.000308858, 0.0002538352, 0.0002520592, 0.0002855566, 0.0002830013, 0.000254472, 0.0002583728, 0.0002831612, 0.000266051, 0.0002992531, 0.0002832055, 0.0003010965, 0.0002860951,
   0.0002815842, 0.0003160256, 0.0002724671, 0.0002627021, 0.0003161987, 0.0003181038, 0.0002632203, 0.000306904, 0.0002640171 };
   TGraphErrors *gre = new TGraphErrors(42,__fx1001,__fy1001,__fex1001,__fey1001);
   gre->SetName("");
   gre->SetTitle("");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(4);
   
   TH1F *Graph_Graph_Graph10011001 = new TH1F("Graph_Graph_Graph10011001","",100,0,45.1);
   Graph_Graph_Graph10011001->SetMinimum(0.9531674);
   Graph_Graph_Graph10011001->SetMaximum(1.029497);
   Graph_Graph_Graph10011001->SetDirectory(nullptr);
   Graph_Graph_Graph10011001->SetStats(0);
   Graph_Graph_Graph10011001->SetLineWidth(2);
   Graph_Graph_Graph10011001->SetMarkerStyle(20);
   Graph_Graph_Graph10011001->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph10011001->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph10011001->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph10011001->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph10011001->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph10011001->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph10011001->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph10011001->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph10011001->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph10011001->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph10011001->GetZaxis()->SetTitleOffset(0.7);
   gre->SetHistogram(Graph_Graph_Graph10011001);
   
   gre->Draw("p");
   TLatex *   tex = new TLatex(32.81494,1.015018,"PADME");
   tex->SetTextSize(0.09649123);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(34.3384,1.019174,"");
   tex->SetLineWidth(2);
   tex->Draw();
   Energy__0->Modified();
   Energy_loss_correction->cd();
  
// ------------>Primitives in pad: Energy loss correction_2
   TPad *Energy__1 = new TPad("Energy loss correction_2", "Energy loss correction_2",0.01,0.01,0.99,0.49);
   Energy__1->Draw();
   Energy__1->cd();
   Energy__1->Range(16.14737,0.9352632,17.59474,1.040526);
   Energy__1->SetFillColor(0);
   Energy__1->SetBorderMode(0);
   Energy__1->SetBorderSize(2);
   Energy__1->SetTickx(1);
   Energy__1->SetTicky(1);
   Energy__1->SetLeftMargin(0.14);
   Energy__1->SetBottomMargin(0.14);
   Energy__1->SetFrameBorderMode(0);
   Energy__1->SetFrameBorderMode(0);
   
   TH1F *hframe__2__2 = new TH1F("hframe__2__2","",1000,16.35,17.45);
   hframe__2__2->SetMinimum(0.95);
   hframe__2__2->SetMaximum(1.03);
   hframe__2__2->SetDirectory(nullptr);
   hframe__2__2->SetStats(0);
   hframe__2__2->SetLineWidth(2);
   hframe__2__2->SetMarkerStyle(20);
   hframe__2__2->GetXaxis()->SetTitle("#sqrt{s} (MeV)");
   hframe__2__2->GetXaxis()->SetLabelFont(42);
   hframe__2__2->GetXaxis()->SetLabelSize(0.06);
   hframe__2__2->GetXaxis()->SetTitleSize(0.06);
   hframe__2__2->GetXaxis()->SetTitleOffset(1.1);
   hframe__2__2->GetXaxis()->SetTitleFont(42);
   hframe__2__2->GetYaxis()->SetTitle("Energy loss correction");
   hframe__2__2->GetYaxis()->SetNdivisions(404);
   hframe__2__2->GetYaxis()->SetLabelFont(42);
   hframe__2__2->GetYaxis()->SetLabelSize(0.06);
   hframe__2__2->GetYaxis()->SetTitleSize(0.06);
   hframe__2__2->GetYaxis()->SetTitleOffset(0.8);
   hframe__2__2->GetYaxis()->SetTitleFont(42);
   hframe__2__2->GetZaxis()->SetLabelFont(42);
   hframe__2__2->GetZaxis()->SetLabelSize(0.06);
   hframe__2__2->GetZaxis()->SetTitleSize(0.06);
   hframe__2__2->GetZaxis()->SetTitleOffset(0.7);
   hframe__2__2->Draw(" ");
   
   Double_t EnergysPlosssPcorrection_fx1002[42] = { 17.12853, 17.26818, 17.22433, 17.17917, 17.40201, 17.35996, 17.31664, 17.09748, 17.06696, 16.99856, 16.9516, 16.90572, 16.85911, 16.81358, 16.76397, 16.71757, 16.67104,
   16.62377, 16.57698, 16.52852, 16.48146, 16.43395, 16.38631, 17.3367, 17.29449, 17.25071, 17.20592, 17.16429, 17.12077, 17.07475, 17.0289, 16.98232, 16.93562,
   16.88848, 16.84394, 16.79442, 16.74658, 16.698, 16.65049, 16.60224, 16.55508, 17.38262 };
   Double_t EnergysPlosssPcorrection_fy1002[42] = { 0.9944352, 1.014291, 1.008072, 1.005927, 1.016724, 1.012942, 1.010146, 1.009457, 1.004909, 1.003082, 1.015807, 1.013836, 1.009644, 1.012485, 1.019631, 1.022899, 1.021129,
   1.02123, 1.022159, 1.012793, 1.011487, 1.01472, 1.020656, 0.9730698, 0.9598112, 0.9856738, 0.9792465, 0.9865644, 0.9935748, 1.002941, 0.969795, 0.9729065, 0.9826323,
   0.9725767, 0.9760711, 0.9830819, 0.9784367, 0.9653267, 0.9803185, 0.9857538, 0.9884436, 0.99728 };
   Double_t EnergysPlosssPcorrection_fex1002[42] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t EnergysPlosssPcorrection_fey1002[42] = { 0.0002818612, 0.0002659186, 0.0002486143, 0.0002682301, 0.0002359447, 0.0002321721, 0.0002507024, 0.0003141871, 0.0002445756, 0.0002504034, 0.000258126, 0.0002522125, 0.0002737013, 0.0002504168, 0.0002661665, 0.0002374665, 0.0002711027,
   0.0002526671, 0.000285678, 0.0002489368, 0.000308858, 0.0002538352, 0.0002520592, 0.0002855566, 0.0002830013, 0.000254472, 0.0002583728, 0.0002831612, 0.000266051, 0.0002992531, 0.0002832055, 0.0003010965, 0.0002860951,
   0.0002815842, 0.0003160256, 0.0002724671, 0.0002627021, 0.0003161987, 0.0003181038, 0.0002632203, 0.000306904, 0.0002640171 };
   gre = new TGraphErrors(42,EnergysPlosssPcorrection_fx1002,EnergysPlosssPcorrection_fy1002,EnergysPlosssPcorrection_fex1002,EnergysPlosssPcorrection_fey1002);
   gre->SetName("Energy loss correction");
   gre->SetTitle("");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(4);
   
   TH1F *Graph_Graph_EnergysPlosssPcorrection10021002 = new TH1F("Graph_Graph_EnergysPlosssPcorrection10021002","",100,16.28474,17.50358);
   Graph_Graph_EnergysPlosssPcorrection10021002->SetMinimum(0.9531674);
   Graph_Graph_EnergysPlosssPcorrection10021002->SetMaximum(1.029497);
   Graph_Graph_EnergysPlosssPcorrection10021002->SetDirectory(nullptr);
   Graph_Graph_EnergysPlosssPcorrection10021002->SetStats(0);
   Graph_Graph_EnergysPlosssPcorrection10021002->SetLineWidth(2);
   Graph_Graph_EnergysPlosssPcorrection10021002->SetMarkerStyle(20);
   Graph_Graph_EnergysPlosssPcorrection10021002->GetXaxis()->SetLabelFont(42);
   Graph_Graph_EnergysPlosssPcorrection10021002->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph_EnergysPlosssPcorrection10021002->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_EnergysPlosssPcorrection10021002->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph_EnergysPlosssPcorrection10021002->GetYaxis()->SetLabelFont(42);
   Graph_Graph_EnergysPlosssPcorrection10021002->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph_EnergysPlosssPcorrection10021002->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_EnergysPlosssPcorrection10021002->GetZaxis()->SetLabelFont(42);
   Graph_Graph_EnergysPlosssPcorrection10021002->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_EnergysPlosssPcorrection10021002->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_EnergysPlosssPcorrection10021002->GetZaxis()->SetTitleOffset(0.7);
   gre->SetHistogram(Graph_Graph_EnergysPlosssPcorrection10021002);
   
   gre->Draw("p");
   Energy__1->Modified();
   Energy_loss_correction->cd();
   Energy_loss_correction->Modified();
   Energy_loss_correction->SetSelected(Energy_loss_correction);
   Energy_loss_correction->ToggleToolBar();
}
