# ECALalphabeta


Where:

    /afs/cern.ch/user/a/amassiro/work/ECAL/LocalReco/CMSSW_8_0_26_patch1/src/EcalValidation/ECALalphabeta
    
    
Install:

    cmsrel CMSSW_8_0_26_patch1
    cd CMSSW_8_0_26_patch1/src/
    cmsenv
    mkdir EcalValidation
    cd EcalValidation
    git clone git@github.com:amassiro/ECALalphabeta.git
    scramv1 b -j 5
    
    
Inputs:

    /afs/cern.ch/work/e/emanuele/public/ecal/pulseshapes_db/template_histograms_ECAL_Run2016*
    
    
Run:

    FitAlphaBeta     template_histograms_ECAL_Run2016B_runs_271983_272818.txt        runs_271983_272818

    FitAlphaBeta     template_histograms_ECAL_Run2016B_runs_271983_272818.txt       


    
    FitAlphaBeta      template_histograms_ECAL_Run2016B_runs_271983_272818.txt         runs_271983_272818
    FitAlphaBeta      template_histograms_ECAL_Run2016B_runs_274080_274344.txt         runs_274080_274344
    FitAlphaBeta      template_histograms_ECAL_Run2016B_runs_273301_273590.txt         runs_273301_273590
    FitAlphaBeta      template_histograms_ECAL_Run2016_runs_275757_275931.txt          runs_275757_275931
    FitAlphaBeta      template_histograms_ECAL_Run2016_runs_274958_275659.txt          runs_274958_275659
    FitAlphaBeta      template_histograms_ECAL_Run2016_runs_277932_277992.txt          runs_277932_277992
    FitAlphaBeta      template_histograms_ECAL_Run2016_runs_276315_276587.txt          runs_276315_276587
    FitAlphaBeta      template_histograms_ECAL_Run2016_runs_279115_279116.txt          runs_279115_279116
    FitAlphaBeta      template_histograms_ECAL_Run2016_runs_278969_278976.txt          runs_278969_278976
    FitAlphaBeta      template_histograms_ECAL_Run2016_runs_279841_279841.txt          runs_279841_279841
    FitAlphaBeta      template_histograms_ECAL_Run2016_runs_279653_279658.txt          runs_279653_279658
    FitAlphaBeta      template_histograms_ECAL_Run2016_runs_282408_283067.txt          runs_282408_283067
    FitAlphaBeta      template_histograms_ECAL_Run2016_runs_281616_282092.txt          runs_281616_282092
    FitAlphaBeta      template_histograms_ECAL_Run2016_runs_283171_283835.txt          runs_283171_283835
    FitAlphaBeta      template_histograms_ECAL_Run2016_runs_283863_284035.txt          runs_283863_284035


Plots:

    r00t test/compare.C\(\"testSummaryruns_283863_284035.root\",\"testSummaryruns_271983_272818.root\"\)

