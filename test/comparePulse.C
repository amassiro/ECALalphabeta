

void comparePulse( std::string file1 = "file1.root", std::string file2 = "file2.root", std::string nameFile = "test") {
  
  
  std::cout << " file1 =    " << file1    << std::endl;
  std::cout << " file2 =    " << file2    << std::endl;
  
  TFile* _file0 = new TFile (file1.c_str(), "READ");
  TFile* _file1 = new TFile (file2.c_str(), "READ");
  
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);
  
  
  TCanvas* cc = new TCanvas("cc","", 800, 800);
  cc->Divide(1,2);
  
  TH2F* h1 = (TH2F*) _file0 -> Get ("h_EB_sam2");
  TH2F* h2 = (TH2F*) _file1 -> Get ("h_EB_sam2");
  
  h1->GetXaxis()->SetTitle("iphi");
  h1->GetYaxis()->SetTitle("ieta");
  
  cc->cd(1);
  h1->Draw("colz");
  h1->GetZaxis()->SetRangeUser(0.995, 1.005);
  cc->cd(2);
  h2->Draw("colz");
  h2->GetZaxis()->SetRangeUser(0.995, 1.005);
  
  
  
  TCanvas* ccDiff = new TCanvas("ccDiff","", 800, 400);
  
  TH2F* hdiff = (TH2F*) (_file1 -> Get ("h_EB_sam2")) -> Clone ("diff");
  hdiff->GetXaxis()->SetTitle("iphi");
  hdiff->GetYaxis()->SetTitle("ieta");
  hdiff->Add(h1, -1);
  hdiff->GetZaxis()->SetRangeUser(-0.01, 0.01);
  hdiff->Draw("colz");
  hdiff->GetZaxis()->SetRangeUser(-0.01, 0.01);
  
  
  TString nameOut = Form ("deltaMax_%s.png", nameFile.c_str());
  ccDiff->SaveAs(nameOut.Data());
  

  TCanvas* ccRatio = new TCanvas("ccRatio","", 800, 400);
  
  TH2F* hratio = (TH2F*) (_file1 -> Get ("h_EB_sam2")) -> Clone ("ratio");
  hratio->GetXaxis()->SetTitle("iphi");
  hratio->GetYaxis()->SetTitle("ieta");
  hratio->Divide(h1);
  hratio->GetZaxis()->SetRangeUser(0.995, 1.005);
  hratio->Draw("colz");
  hratio->GetZaxis()->SetRangeUser(0.995, 1.005);
  
  
  nameOut = Form ("ratioMax_%s.png", nameFile.c_str());
  ccRatio->SaveAs(nameOut.Data());








  
  TCanvas* ccEE = new TCanvas("ccEE","", 800, 800);
  ccEE->Divide(1,2);
  
  TH2F* h1EE = (TH2F*) _file0 -> Get ("h_EE_sam2");
  TH2F* h2EE = (TH2F*) _file1 -> Get ("h_EE_sam2");
  
  h1EE->GetXaxis()->SetTitle("iphi");
  h1EE->GetYaxis()->SetTitle("ieta");
  
  ccEE->cd(1);
  h1EE->Draw("colz");
  h1EE->GetZaxis()->SetRangeUser(0.99, 1.01);
  ccEE->cd(2);
  h2EE->Draw("colz");
  h2EE->GetZaxis()->SetRangeUser(0.99, 1.01);
  
  
  
  TCanvas* ccEEDiff = new TCanvas("ccEEDiff","", 800, 400);
  
  TH2F* hdiffEE = (TH2F*) (_file1 -> Get ("h_EE_sam2")) -> Clone ("diff");
  hdiffEE->GetXaxis()->SetTitle("iphi");
  hdiffEE->GetYaxis()->SetTitle("ieta");
  hdiffEE->Add(h1EE, -1);
  hdiffEE->GetZaxis()->SetRangeUser(-0.01, 0.01);
  hdiffEE->Draw("colz");
  hdiffEE->GetZaxis()->SetRangeUser(-0.01, 0.01);
  
  
  nameOut = Form ("deltaMax_EE__%s.png", nameFile.c_str());
  ccEEDiff->SaveAs(nameOut.Data());
  
  
  TCanvas* ccEERatio = new TCanvas("ccEERatio","", 800, 400);
  
  TH2F* hratioEE = (TH2F*) (_file1 -> Get ("h_EE_sam2")) -> Clone ("ratio");
  hratioEE->GetXaxis()->SetTitle("iphi");
  hratioEE->GetYaxis()->SetTitle("ieta");
  hratioEE->Divide(h1EE);
  hratioEE->GetZaxis()->SetRangeUser(0.99, 1.01);
  hratioEE->Draw("colz");
  hratioEE->GetZaxis()->SetRangeUser(0.99, 1.01);
  
  
  nameOut = Form ("ratioMax_EE_%s.png", nameFile.c_str());
  ccEERatio->SaveAs(nameOut.Data());
  
  
}