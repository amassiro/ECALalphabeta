
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

   
  std::string output_file_tail = "";
  if (argc >=3) {
    std::cout << " Output file = " << argv[2] << std::endl;
    output_file_tail =  argv[2];
  }

  
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

  TString nametemp;
  nametemp = Form ("testSummary%s.root", output_file_tail.c_str());
  TFile* fileOutSummary = new TFile (nametemp.Data(), "RECREATE");
  TH2F* h_EB_sam0  = new TH2F ("h_EB_sam0", "sam0",   360, 0.5, 360.5,  171, -85.5, 85.5);
  TH2F* h_EB_sam1  = new TH2F ("h_EB_sam1", "sam1",   360, 0.5, 360.5,  171, -85.5, 85.5);
  TH2F* h_EB_sam2  = new TH2F ("h_EB_sam2", "sam2",   360, 0.5, 360.5,  171, -85.5, 85.5);
  TH2F* h_EB_sam3  = new TH2F ("h_EB_sam3", "sam3",   360, 0.5, 360.5,  171, -85.5, 85.5);
  TH2F* h_EB_sam4  = new TH2F ("h_EB_sam4", "sam4",   360, 0.5, 360.5,  171, -85.5, 85.5);
  TH2F* h_EB_sam5  = new TH2F ("h_EB_sam5", "sam5",   360, 0.5, 360.5,  171, -85.5, 85.5);
  TH2F* h_EB_sam6  = new TH2F ("h_EB_sam6", "sam6",   360, 0.5, 360.5,  171, -85.5, 85.5);
  
  TH2F* h_EE_sam0  = new TH2F ("h_EE_sam0", "sam0",   200, 0.5, 200.5,  100, 0.5, 100.5);
  TH2F* h_EE_sam1  = new TH2F ("h_EE_sam1", "sam1",   200, 0.5, 200.5,  100, 0.5, 100.5);
  TH2F* h_EE_sam2  = new TH2F ("h_EE_sam2", "sam2",   200, 0.5, 200.5,  100, 0.5, 100.5);
  TH2F* h_EE_sam3  = new TH2F ("h_EE_sam3", "sam3",   200, 0.5, 200.5,  100, 0.5, 100.5);
  TH2F* h_EE_sam4  = new TH2F ("h_EE_sam4", "sam4",   200, 0.5, 200.5,  100, 0.5, 100.5);
  TH2F* h_EE_sam5  = new TH2F ("h_EE_sam5", "sam5",   200, 0.5, 200.5,  100, 0.5, 100.5);
  TH2F* h_EE_sam6  = new TH2F ("h_EE_sam6", "sam6",   200, 0.5, 200.5,  100, 0.5, 100.5);
  
   
  nametemp = Form ("/tmp/amassiro/testPulses%s.root", output_file_tail.c_str());
  TFile* fileOut = new TFile (nametemp.Data(), "RECREATE");
  
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
        
        //---- FIX: how on Earth can this be negative???
        if (value<0) value = 0;
         
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
     
     for (int ipoint = 0; ipoint < (10-3); ipoint++) {
       gr_pulse->SetPoint (ipoint, ipoint * 25.,  pulse.at(ipoint));
     }  
     
     if (ieta != -99) {
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
       h_EE_sam0  -> Fill (iz < 0 ? ix : ix+100, iy, pulse.at(0));      
       h_EE_sam1  -> Fill (iz < 0 ? ix : ix+100, iy, pulse.at(1));      
       h_EE_sam2  -> Fill (iz < 0 ? ix : ix+100, iy, pulse.at(2));      
       h_EE_sam3  -> Fill (iz < 0 ? ix : ix+100, iy, pulse.at(3));      
       h_EE_sam4  -> Fill (iz < 0 ? ix : ix+100, iy, pulse.at(4));      
       h_EE_sam5  -> Fill (iz < 0 ? ix : ix+100, iy, pulse.at(5));      
       h_EE_sam6  -> Fill (iz < 0 ? ix : ix+100, iy, pulse.at(6));      
     }
     
     
     
     if (!(counter%1000)) {
       std::cout << " counter = " << counter << "  --->  iDet = " << iDet << "     detId = " << detId << " :: ix, iy, iz, ieta, iphi " << ix << " , " << iy << " , "  << iz << " , " << ieta << " , " << iphi << "  " ;
       std::cout << std::endl;
     }
     
     
     
     TString name = Form ("pulse_%d_%d", iDet, detId);
     gr_pulse->Write(name.Data());
    }
    
  }
  
  fileOut->Close();
  
  fileOutSummary->cd();
  h_EB_sam0  -> Write();
  h_EB_sam1  -> Write();
  h_EB_sam2  -> Write();
  h_EB_sam3  -> Write();
  h_EB_sam4  -> Write();
  h_EB_sam5  -> Write();
  h_EB_sam6  -> Write();
  
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



  