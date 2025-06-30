#ifdef __CLING__
#pragma cling optimize(0)
#endif
void pullGausFitBoxOpening()
{
//=========Macro generated from canvas: c1/c1
//=========  (Mon Jun 30 00:49:41 2025) by ROOT version 6.34.08
   TCanvas *c1 = new TCanvas("c1", "c1",272,429,800,602);
   gStyle->SetOptFit(1);
   c1->Range(-12.5,-1.647332,12.5,13.32841);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetBottomMargin(0.11);
   c1->SetFrameBorderMode(0);
   c1->SetFrameLineWidth(2);
   c1->SetFrameBorderMode(0);
   gStyle->SetStatFormat("5.2g");
   gStyle->SetFitFormat("5.2g");

   TH1F *Pulls_wrt_line_0dO000000_0dO000000__4 = new TH1F("Pulls_wrt_line_0dO000000_0dO000000__4","",25,-10,10);
   Pulls_wrt_line_0dO000000_0dO000000__4->SetBinContent(11,2);
   Pulls_wrt_line_0dO000000_0dO000000__4->SetBinContent(12,9);
   Pulls_wrt_line_0dO000000_0dO000000__4->SetBinContent(13,11);
   Pulls_wrt_line_0dO000000_0dO000000__4->SetBinContent(14,7);
   Pulls_wrt_line_0dO000000_0dO000000__4->SetBinContent(15,3);
   Pulls_wrt_line_0dO000000_0dO000000__4->SetEntries(32);
   
   TF1 *gaus7 = new TF1("gaus","gaus",-4,4, TF1::EAddToList::kNo);
   gaus7->SetFillColor(19);
   gaus7->SetFillStyle(0);
   gaus7->SetLineColor(2);
   gaus7->SetLineWidth(2);
   gaus7->SetChisquare(0.466861);
   gaus7->SetNDF(2);
   gaus7->GetXaxis()->SetLabelFont(42);
   gaus7->GetXaxis()->SetTitleOffset(1);
   gaus7->GetXaxis()->SetTitleFont(42);
   gaus7->GetYaxis()->SetLabelFont(42);
   gaus7->GetYaxis()->SetTitleFont(42);
   gaus7->SetParameter(0,11.26747);
   gaus7->SetParError(0,2.599894);
   gaus7->SetParLimits(0,0,0);
   gaus7->SetParameter(1,-1.236665e-10);
   gaus7->SetParError(1,0.01908098);
   gaus7->SetParLimits(1,0,0);
   gaus7->SetParameter(2,0.9152522);
   gaus7->SetParError(2,0.1585589);
   gaus7->SetParLimits(2,0,8.485281);
   gaus7->SetParent(Pulls_wrt_line_0dO000000_0dO000000__4);
   Pulls_wrt_line_0dO000000_0dO000000__4->GetListOfFunctions()->Add(gaus7);
   
   TPaveStats *ptstats = new TPaveStats(0.1453634,0.4913194,0.4197995,0.8246528,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetLineWidth(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("Entries = 32     ");
   ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf =  0.47 / 2");
   ptstats_LaTex = ptstats->AddText("Prob  =  0.79");
   ptstats_LaTex = ptstats->AddText("Constant =    11 #pm 2.6 ");
   ptstats_LaTex = ptstats->AddText("Mean     = -1.2e-10 #pm 1.9e-02 ");
   ptstats_LaTex = ptstats->AddText("Sigma    =  0.92 #pm 0.16 ");
   ptstats->SetOptStat(10);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   Pulls_wrt_line_0dO000000_0dO000000__4->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(Pulls_wrt_line_0dO000000_0dO000000__4);
   Pulls_wrt_line_0dO000000_0dO000000__4->SetLineWidth(3);
   Pulls_wrt_line_0dO000000_0dO000000__4->SetLineColor(1);
   Pulls_wrt_line_0dO000000_0dO000000__4->GetXaxis()->SetTitle("Pull of the g_{R}(s) fit");
   Pulls_wrt_line_0dO000000_0dO000000__4->GetXaxis()->SetRange(1,100);
   Pulls_wrt_line_0dO000000_0dO000000__4->GetXaxis()->SetLabelFont(42);
   Pulls_wrt_line_0dO000000_0dO000000__4->GetXaxis()->SetLabelSize(0.04);
   Pulls_wrt_line_0dO000000_0dO000000__4->GetXaxis()->SetTitleSize(0.05);
   Pulls_wrt_line_0dO000000_0dO000000__4->GetXaxis()->SetTitleOffset(0.9);
   Pulls_wrt_line_0dO000000_0dO000000__4->GetYaxis()->SetLabelFont(42);
   Pulls_wrt_line_0dO000000_0dO000000__4->GetYaxis()->SetLabelSize(0.04);
   Pulls_wrt_line_0dO000000_0dO000000__4->GetYaxis()->SetTitleFont(42);
   Pulls_wrt_line_0dO000000_0dO000000__4->GetZaxis()->SetLabelFont(42);
   Pulls_wrt_line_0dO000000_0dO000000__4->GetZaxis()->SetTitleOffset(1);
   Pulls_wrt_line_0dO000000_0dO000000__4->GetZaxis()->SetTitleFont(42);
   Pulls_wrt_line_0dO000000_0dO000000__4->Draw("");
   c1->Modified();
   c1->SetSelected(c1);
}
