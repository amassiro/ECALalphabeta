

void compare( std::string file1 = "file1.root", std::string file2 = "file2.root") {
  
  
  std::cout << " file1 =    " << file1    << std::endl;
  std::cout << " file2 =    " << file2    << std::endl;
  
  TFile* _file0 = new TFile (file1.c_str(), "READ");
  TFile* _file1 = new TFile (file2.c_str(), "READ");
  
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);
  
  
  TCanvas* cc = new TCanvas("cc","", 800, 800);
  cc->Divide(1,2);
  
  TH2F* h1 = (TH2F*) _file0 -> Get ("h_EB_ampl");
  TH2F* h2 = (TH2F*) _file1 -> Get ("h_EB_ampl");
  
  
  cc->cd(1);
  h1->Draw("colz");
  h1->GetZaxis()->SetRangeUser(0.8, 1.2);
  cc->cd(2);
  h2->Draw("colz");
  h2->GetZaxis()->SetRangeUser(0.8, 1.2);
  
  
  
  TCanvas* ccRatio = new TCanvas("ccRatio","", 800, 400);
  
  TH2F* hdiff = (TH2F*) (_file0 -> Get ("h_EB_ampl")) -> Clone ("diff");
  hdiff->Add(h2, -1);
  hdiff->GetZaxis()->SetRangeUser(-0.02, 0.02);
  hdiff->Draw("colz");
  
  
  
  
  
  
  TCanvas* cc_time = new TCanvas("cc_time","", 800, 800);
  cc_time->Divide(1,2);
  
  TH2F* h1_time = (TH2F*) _file0 -> Get ("h_EB_time");
  TH2F* h2_time = (TH2F*) _file1 -> Get ("h_EB_time");
  
  
  cc_time->cd(1);
  h1_time->Draw("colz");
  h1_time->GetZaxis()->SetRangeUser(-5.0, 5.0);
  cc_time->cd(2);
  h2_time->Draw("colz");
  h2_time->GetZaxis()->SetRangeUser(-5.0, 5.0);
  
  
  
  TCanvas* cc_timeRatio = new TCanvas("cc_timeRatio","", 800, 400);
  
  TH2F* h_timediff = (TH2F*) (_file0 -> Get ("h_EB_time")) -> Clone ("timediff");
  h_timediff->Add(h2_time, -1);
  h_timediff->GetZaxis()->SetRangeUser(-5.0, 5.0);
  h_timediff->Draw("colz");
  
  
}