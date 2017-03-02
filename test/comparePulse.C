

void comparePulse( std::string file1 = "file1.root", std::string file2 = "file2.root", std::string nameFile = "test") {
  
  
  std::cout << " file1 =    " << file1    << std::endl;
  std::cout << " file2 =    " << file2    << std::endl;
  
  TFile* _file0 = new TFile (file1.c_str(), "READ");
  TFile* _file1 = new TFile (file2.c_str(), "READ");
  
//   gStyle->SetOptStat(0);
//   gStyle->SetOptFit(0);
  
  
  TCanvas* cc = new TCanvas("cc","", 800, 800);
  cc->Divide(1,2);
  
  TH2F* h1 = (TH2F*) _file0 -> Get ("h_EB_sam2");
  TH2F* h2 = (TH2F*) _file1 -> Get ("h_EB_sam2");
  
  h1->SetStats(0);
  h2->SetStats(0);
  
  h1->GetXaxis()->SetTitle("iphi");
  h1->GetYaxis()->SetTitle("ieta");
  
  cc->cd(1);
  h1->Draw("colz");
  h1->GetZaxis()->SetRangeUser(0.995, 1.005);
  cc->cd(2);
  h2->Draw("colz");
  h2->GetZaxis()->SetRangeUser(0.995, 1.005);
  
  
  
  TCanvas* ccDiff = new TCanvas("ccDiff","Difference", 800, 400);
  
  TH2F* hdiff = (TH2F*) (_file1 -> Get ("h_EB_sam2")) -> Clone ("diff");
  hdiff->GetXaxis()->SetTitle("iphi");
  hdiff->GetYaxis()->SetTitle("ieta");
  hdiff->Add(h1, -1);
  hdiff->GetZaxis()->SetRangeUser(-0.01, 0.01);
  hdiff->Draw("colz");
  hdiff->GetZaxis()->SetRangeUser(-0.01, 0.01);
  
  
  TString nameOut = Form ("deltaMax_%s.png", nameFile.c_str());
  ccDiff->SaveAs(nameOut.Data());
  

  TCanvas* ccRatio = new TCanvas("ccRatio","Ratio", 800, 800);
  ccRatio->Divide(1,2);
  
  ccRatio->cd(1);
  
  TH2F* hratio = (TH2F*) (_file1 -> Get ("h_EB_sam2")) -> Clone ("ratio");
  hratio->GetXaxis()->SetTitle("iphi");
  hratio->GetYaxis()->SetTitle("ieta");
  hratio->Divide(h1);
  hratio->GetZaxis()->SetRangeUser(0.995, 1.005);
  hratio->Draw("colz");
  hratio->GetZaxis()->SetRangeUser(0.995, 1.005);
  
  
  ccRatio->cd(2);
  
  TH1F* hratio1D = new TH1F ("hratio1D", "EB", 100, 0.99, 1.01);
  
  for (int ibinX=0; ibinX<360; ibinX++) {
    for (int ibinY=0; ibinY<171; ibinY++) {
      if (ibinY != 85) {
        hratio1D->Fill(hratio->GetBinContent(ibinX+1, ibinY+1));
      }
    }
  }
  hratio1D->SetLineColor(kRed);
  hratio1D->SetLineWidth(2);
 
  
  hratio1D->SetStats(1);
  hratio1D->Draw();
  hratio1D->GetXaxis()->SetTitle("A2/A1");
  
  
  nameOut = Form ("ratioMax_%s.png", nameFile.c_str());
  ccRatio->SaveAs(nameOut.Data());
  
  

  
  TCanvas* ccEE = new TCanvas("ccEE","", 800, 800);
  ccEE->Divide(1,2);
  
  TH2F* h1EE = (TH2F*) _file0 -> Get ("h_EE_sam2");
  TH2F* h2EE = (TH2F*) _file1 -> Get ("h_EE_sam2");
  
  h1EE->SetStats(0);
  h2EE->SetStats(0);
  
  
  h1EE->GetXaxis()->SetTitle("iphi");
  h1EE->GetYaxis()->SetTitle("ieta");
  
  ccEE->cd(1);
  h1EE->Draw("colz");
  h1EE->GetZaxis()->SetRangeUser(0.99, 1.01);
  ccEE->cd(2);
  h2EE->Draw("colz");
  h2EE->GetZaxis()->SetRangeUser(0.99, 1.01);
  
  
  
  TCanvas* ccEEDiff = new TCanvas("ccEEDiff","Difference", 800, 400);
  
  TH2F* hdiffEE = (TH2F*) (_file1 -> Get ("h_EE_sam2")) -> Clone ("diff");
  hdiffEE->GetXaxis()->SetTitle("iphi");
  hdiffEE->GetYaxis()->SetTitle("ieta");
  hdiffEE->Add(h1EE, -1);
  hdiffEE->GetZaxis()->SetRangeUser(-0.01, 0.01);
  hdiffEE->Draw("colz");
  hdiffEE->GetZaxis()->SetRangeUser(-0.01, 0.01);
  
  
  nameOut = Form ("deltaMax_EE__%s.png", nameFile.c_str());
  ccEEDiff->SaveAs(nameOut.Data());
  
  
  TCanvas* ccEERatio = new TCanvas("ccEERatio","Ratio", 800, 800);
  ccEERatio->Divide(1,2);
  
  ccEERatio->cd(1);
  
  TH2F* hratioEE = (TH2F*) (_file1 -> Get ("h_EE_sam2")) -> Clone ("ratio");
  hratioEE->GetXaxis()->SetTitle("iphi");
  hratioEE->GetYaxis()->SetTitle("ieta");
  hratioEE->Divide(h1EE);
  hratioEE->GetZaxis()->SetRangeUser(0.99, 1.01);
  hratioEE->Draw("colz");
  hratioEE->GetZaxis()->SetRangeUser(0.99, 1.01);
  
  
  ccEERatio->cd(2);
  
  TH1F* hEEratio1D = new TH1F ("hEEratio1D", "EE", 100, 0.98, 1.02);
    
  for (int ibinX=0; ibinX<200; ibinX++) {
    for (int ibinY=0; ibinY<100; ibinY++) {
      if (hratioEE->GetBinContent(ibinX+1, ibinY+1) != 0) {
        hEEratio1D->Fill(hratioEE->GetBinContent(ibinX+1, ibinY+1));
      }
    }
  }
  hEEratio1D->SetLineColor(kRed);
  hEEratio1D->SetLineWidth(2);
  
  hEEratio1D->SetStats(1);
  hEEratio1D->Draw();
  hEEratio1D->GetXaxis()->SetTitle("A2/A1");
  
  
  nameOut = Form ("ratioMax_EE_%s.png", nameFile.c_str());
  ccEERatio->SaveAs(nameOut.Data());
  
  
}