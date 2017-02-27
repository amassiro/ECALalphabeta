
//---- std include ----
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <fstream> 

//---- ROOT
#include "TF1.h"
#include "TGraph.h"
#include "TString.h"
#include "TFile.h"
#include "TH2F.h"


//---- ECAL 
#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "DataFormats/EcalDetId/interface/EEDetId.h"
// #include "DataFormats/EcalDetId/interface/EcalSubdetector.h"


int main(int argc, char** argv) {
  
  std::cout << " AlphaBeta fit " << std::endl;
  
  std::vector<float> pulse;

//                             1               2               3               4               5               6               7               8               9              10              11              12              
//   1     838926974       0.010910        0.755050        0.999907        0.897665        0.682446        0.486593        0.328723        0.214375        0.138427        0.089311        0.058433        0.039428        
  
//   pulse.clear();
//   pulse.push_back(0.010910);
//   pulse.push_back(0.755050);
//   pulse.push_back(0.999907);
//   pulse.push_back(0.897665);
//   pulse.push_back(0.682446);
//   pulse.push_back(0.486593);
//   pulse.push_back(0.328723);
//   pulse.push_back(0.214375);
//   pulse.push_back(0.138427);
//   pulse.push_back(0.089311);
//   pulse.push_back(0.058433);
//   pulse.push_back(0.039428);
  
  //                                                       A    [ (1 + Dt / (alpha*beta)) ^ alpha ] * exp (- Dt/beta)  
  TF1 *function_alphabeta = new TF1("function_alphabeta","[0] * pow(1 + (x-[1]) / ([2]*[3]) , [2] ) * exp ( - (x-[1]) / [3])",0,25*7);
  
  TGraph* gr_pulse = new TGraph ();
  gr_pulse->SetMarkerSize(2);
  gr_pulse->SetMarkerStyle(20);
  
   
  std::cout << " Input file = " << argv[1] << std::endl;
  
  std::ifstream file (argv[1]); 
  
  std::string buffer;
  int num;
  unsigned int unum;
  float value;
  
  if(!file.is_open())
  {
    std::cerr << "** ERROR: Can't open '" << argv[1] << "' for input" << std::endl;
    return false;
  }

  TFile* fileOutSummary = new TFile ("testSummary.root", "RECREATE");
  TH2F* h_EB_alpha = new TH2F ("h_EB_alpha", "alpha", 360, 0.5, 360.5,  171, -85.5, 85.5);                //  360,0.5,360.5,171,-85.5,85.5               360, 0, 360, 85*2+1, -85, 85
  TH2F* h_EB_beta  = new TH2F ("h_EB_beta",  "beta",  360, 0.5, 360.5,  171, -85.5, 85.5);
  TH2F* h_EB_time  = new TH2F ("h_EB_time",  "time",  360, 0.5, 360.5,  171, -85.5, 85.5);
  TH2F* h_EB_ampl  = new TH2F ("h_EB_ampl",  "ampl",  360, 0.5, 360.5,  171, -85.5, 85.5);
  TH2F* h_EB_max   = new TH2F ("h_EB_max",   "max",   360, 0.5, 360.5,  171, -85.5, 85.5);
  TH2F* h_EB_chi2  = new TH2F ("h_EB_chi2", "chi2",   360, 0.5, 360.5,  171, -85.5, 85.5);
  TH2F* h_EB_occupancy  = new TH2F ("h_EB_occupancy", "occupancy",   360, 0.5, 360.5,  171, -85.5, 85.5);
  TH2F* h_EB_sam0  = new TH2F ("h_EB_sam0", "sam0",   360, 0.5, 360.5,  171, -85.5, 85.5);
  TH2F* h_EB_sam1  = new TH2F ("h_EB_sam1", "sam1",   360, 0.5, 360.5,  171, -85.5, 85.5);
  TH2F* h_EB_sam2  = new TH2F ("h_EB_sam2", "sam2",   360, 0.5, 360.5,  171, -85.5, 85.5);
  TH2F* h_EB_sam3  = new TH2F ("h_EB_sam3", "sam3",   360, 0.5, 360.5,  171, -85.5, 85.5);
  TH2F* h_EB_sam4  = new TH2F ("h_EB_sam4", "sam4",   360, 0.5, 360.5,  171, -85.5, 85.5);
  TH2F* h_EB_sam5  = new TH2F ("h_EB_sam5", "sam5",   360, 0.5, 360.5,  171, -85.5, 85.5);
  TH2F* h_EB_sam6  = new TH2F ("h_EB_sam6", "sam6",   360, 0.5, 360.5,  171, -85.5, 85.5);
  
  TH2F* h_EE_alpha = new TH2F ("h_EE_alpha", "alpha", 200, 0.5, 200.5,  100, 0.5, 100.5);
  TH2F* h_EE_beta  = new TH2F ("h_EE_beta",  "beta",  200, 0.5, 200.5,  100, 0.5, 100.5);
  TH2F* h_EE_time  = new TH2F ("h_EE_time",  "time",  200, 0.5, 200.5,  100, 0.5, 100.5);
  TH2F* h_EE_ampl  = new TH2F ("h_EE_ampl",  "ampl",  200, 0.5, 200.5,  100, 0.5, 100.5);
  TH2F* h_EE_max   = new TH2F ("h_EE_max",   "max",   200, 0.5, 200.5,  100, 0.5, 100.5);
  TH2F* h_EE_chi2  = new TH2F ("h_EE_chi2", "chi2",   200, 0.5, 200.5,  100, 0.5, 100.5);
  TH2F* h_EE_occupancy  = new TH2F ("h_EE_occupancy", "occupancy",   200, 0.5, 200.5,  100, 0.5, 100.5);
  TH2F* h_EE_sam0  = new TH2F ("h_EE_sam0", "sam0",   200, 0.5, 200.5,  100, 0.5, 100.5);
  TH2F* h_EE_sam1  = new TH2F ("h_EE_sam1", "sam1",   200, 0.5, 200.5,  100, 0.5, 100.5);
  TH2F* h_EE_sam2  = new TH2F ("h_EE_sam2", "sam2",   200, 0.5, 200.5,  100, 0.5, 100.5);
  TH2F* h_EE_sam3  = new TH2F ("h_EE_sam3", "sam3",   200, 0.5, 200.5,  100, 0.5, 100.5);
  TH2F* h_EE_sam4  = new TH2F ("h_EE_sam4", "sam4",   200, 0.5, 200.5,  100, 0.5, 100.5);
  TH2F* h_EE_sam5  = new TH2F ("h_EE_sam5", "sam5",   200, 0.5, 200.5,  100, 0.5, 100.5);
  TH2F* h_EE_sam6  = new TH2F ("h_EE_sam6", "sam6",   200, 0.5, 200.5,  100, 0.5, 100.5);
  

  TFile* fileOut = new TFile ("testPulses.root", "RECREATE");
  
  int counter = 0;
  while(!file.eof()) {

    int iDet = 0;
    int detId = 0;
    
    pulse.clear();
    
    getline(file,buffer);
    if (buffer != ""){ ///---> save from empty line at the end!
      std::stringstream line( buffer );      
      line >> num; 
      iDet = num;
      
      line >> unum; 
      detId = unum;
      
      for (int i=0; i<(10-3); i++) {
        line >> value; 
        pulse.push_back(value);
      }
     
     counter++;
     
     int ieta, iphi, ix, iy, iz;
     
     if ( DetId(detId).subdetId() == 1) {
       ieta = EBDetId(detId).ieta();
       iphi = EBDetId(detId).iphi();
       ix = -99;
       iy = -99;
       iz = -99;
     }
     else {
       ieta = -99;
       iphi = -99;
       ix   = EEDetId(detId).ix();
       iy   = EEDetId(detId).iy();
       iz   = EEDetId(detId).zside();
     }
     
     
     
     gr_pulse->Clear();
     
     function_alphabeta->SetParameter (0, 1.1);   // A
     function_alphabeta->SetParameter (1, 0.0);   // t_0    
     function_alphabeta->SetParameter (2, 20.0);   // alpha
     function_alphabeta->SetParameter (3, 43.0);   // beta
     
     function_alphabeta->SetParLimits (2, 0, 200);   // alpha
     function_alphabeta->SetParLimits (3, 0, 200);   // beta
     
     
     for (int ipoint = 0; ipoint < (10-3); ipoint++) {
       gr_pulse->SetPoint (ipoint, ipoint * 25.,  pulse.at(ipoint));
     }  
     
     gr_pulse->Fit ("function_alphabeta", "Q");
     
     //---- improved the fit if chi2 is too big
     if (function_alphabeta->GetChisquare() > 0.3) { //---- threshold set after looking at the plot
       gr_pulse->Fit ("function_alphabeta", "QM");       
     }
     
     if (ieta != -99) {
       h_EB_alpha -> Fill (iphi, ieta, function_alphabeta->GetParameter(2));
       h_EB_beta  -> Fill (iphi, ieta, function_alphabeta->GetParameter(3));
       h_EB_time  -> Fill (iphi, ieta, function_alphabeta->GetParameter(1));
       h_EB_ampl  -> Fill (iphi, ieta, function_alphabeta->GetParameter(0));
       h_EB_max   -> Fill (iphi, ieta, function_alphabeta->GetMaximum());
       h_EB_chi2  -> Fill (iphi, ieta, function_alphabeta->GetChisquare());
       h_EB_occupancy  -> Fill (iphi, ieta, 1);
       h_EB_sam0  -> Fill (iphi, ieta,  pulse.at(0));
       h_EB_sam1  -> Fill (iphi, ieta,  pulse.at(1));
       h_EB_sam2  -> Fill (iphi, ieta,  pulse.at(2));
       h_EB_sam3  -> Fill (iphi, ieta,  pulse.at(3));
       h_EB_sam4  -> Fill (iphi, ieta,  pulse.at(4));
       h_EB_sam5  -> Fill (iphi, ieta,  pulse.at(5));
       h_EB_sam6  -> Fill (iphi, ieta,  pulse.at(6));
     }
     else {
       // thanks SimonePigazzini for the mapping
       h_EE_alpha -> Fill (iz < 0 ? ix : ix+100, iy, function_alphabeta->GetParameter(2));
       h_EE_beta  -> Fill (iz < 0 ? ix : ix+100, iy, function_alphabeta->GetParameter(3));
       h_EE_time  -> Fill (iz < 0 ? ix : ix+100, iy, function_alphabeta->GetParameter(1));
       h_EE_ampl  -> Fill (iz < 0 ? ix : ix+100, iy, function_alphabeta->GetParameter(0));
       h_EE_max   -> Fill (iz < 0 ? ix : ix+100, iy, function_alphabeta->GetMaximum());
       h_EE_chi2  -> Fill (iz < 0 ? ix : ix+100, iy, function_alphabeta->GetChisquare());      
       h_EE_occupancy  -> Fill (iz < 0 ? ix : ix+100, iy, 1);      
       h_EE_sam0  -> Fill (iz < 0 ? ix : ix+100, iy, pulse.at(0));      
       h_EE_sam1  -> Fill (iz < 0 ? ix : ix+100, iy, pulse.at(1));      
       h_EE_sam2  -> Fill (iz < 0 ? ix : ix+100, iy, pulse.at(2));      
       h_EE_sam3  -> Fill (iz < 0 ? ix : ix+100, iy, pulse.at(3));      
       h_EE_sam4  -> Fill (iz < 0 ? ix : ix+100, iy, pulse.at(4));      
       h_EE_sam5  -> Fill (iz < 0 ? ix : ix+100, iy, pulse.at(5));      
       h_EE_sam6  -> Fill (iz < 0 ? ix : ix+100, iy, pulse.at(6));      
     }
     
     
     
     if (!(counter%1000)) {
       std::cout << " counter = " << counter << "  --->  iDet = " << iDet << "     detId = " << detId << " :: ix, iy, iz, ieta, iphi " << ix << " , " << iy << " , "  << iz << " , " << ieta << " , " << iphi << " , " ;
       std::cout << " [0] = " << function_alphabeta->GetParameter(0) ;
       std::cout << " [1] = " << function_alphabeta->GetParameter(1) ;
       std::cout << " [2] = " << function_alphabeta->GetParameter(2) ;
       std::cout << " [3] = " << function_alphabeta->GetParameter(3) << std::endl;
     }
     
     
     
     TString name = Form ("pulse_%d_%d", iDet, detId);
     gr_pulse->Write(name.Data());
    }
    
  }
  
  fileOut->Close();
  
  fileOutSummary->cd();
  h_EB_alpha -> Write();
  h_EB_beta  -> Write();
  h_EB_time  -> Write();
  h_EB_ampl  -> Write();
  h_EB_max   -> Write();
  h_EB_chi2  -> Write();
  h_EB_occupancy  -> Write();
  h_EB_sam0  -> Write();
  h_EB_sam1  -> Write();
  h_EB_sam2  -> Write();
  h_EB_sam3  -> Write();
  h_EB_sam4  -> Write();
  h_EB_sam5  -> Write();
  h_EB_sam6  -> Write();
  
  h_EE_alpha -> Write();
  h_EE_beta  -> Write();
  h_EE_time  -> Write();
  h_EE_ampl  -> Write();
  h_EE_max   -> Write();
  h_EE_chi2  -> Write();
  h_EE_occupancy  -> Write();
  h_EE_sam0  -> Write();
  h_EE_sam1  -> Write();
  h_EE_sam2  -> Write();
  h_EE_sam3  -> Write();
  h_EE_sam4  -> Write();
  h_EE_sam5  -> Write();
  h_EE_sam6  -> Write();
  
  fileOutSummary->Close();
  
  std::cout << std::endl;
  
}



  