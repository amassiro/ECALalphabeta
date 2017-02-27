
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
  float value;
  
  if(!file.is_open())
  {
    std::cerr << "** ERROR: Can't open '" << argv[1] << "' for input" << std::endl;
    return false;
  }
  
  TFile* fileOut = new TFile ("test.root", "RECREATE");
  
  int counter = 0;
  while(!file.eof()) {

    int iDet = 0;
    int detId = 0;
    
    getline(file,buffer);
    if (buffer != ""){ ///---> save from empty line at the end!
      std::stringstream line( buffer );      
      line >> num; 
      iDet = num;
      
      line >> num; 
      detId = num;
      
      for (int i=0; i<(10-3); i++) {
        line >> value; 
        pulse.push_back(value);
      }
    }
    
    counter++;
    
    if (!(counter%100)) {std::cout << " counter = " << counter << "  --->  iDet = " << iDet << "     detId = " << detId << std::endl;
    }
    
     
    gr_pulse->Clear();
    
    function_alphabeta->SetParameter (0, 1.1);   // A
    function_alphabeta->SetParameter (1, 0.0);   // t_0    
    function_alphabeta->SetParameter (2, 20.0);   // alpha
    function_alphabeta->SetParameter (3, 43.0);   // beta
    
    for (int ipoint = 0; ipoint < (10-3); ipoint++) {
      gr_pulse->SetPoint (ipoint, ipoint * 25.,  pulse.at(ipoint));
    }  
    
    gr_pulse->Fit ("function_alphabeta", "Q");
    
    TString name = Form ("pulse_%d_%d", iDet, detId);
    gr_pulse->Write(name.Data());
    
  }
  
  fileOut->Close();
  
  std::cout << std::endl;
  
}



  