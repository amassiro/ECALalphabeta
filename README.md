# ECALalphabeta


Where

    /afs/cern.ch/user/a/amassiro/work/ECAL/LocalReco/CMSSW_8_0_26_patch1/src/EcalValidation/ECALalphabeta
    
    
Install

    cmsrel CMSSW_8_0_26_patch1
    cd CMSSW_8_0_26_patch1/src/
    cmsenv
    mkdir EcalValidation
    cd EcalValidation
    git clone git@github.com:amassiro/ECALalphabeta.git
    scramv1 b -j 5
    

Run

    FitAlphaBeta     template_histograms_ECAL_Run2016B_runs_271983_272818.txt        runs_271983_272818

    FitAlphaBeta     template_histograms_ECAL_Run2016B_runs_271983_272818.txt       

