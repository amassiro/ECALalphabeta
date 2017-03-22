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
    /afs/cern.ch/work/e/emanuele/public/ecal/pulseshapes_db/norm_template_histograms_ECAL_Run2016_runs_2*
    
    
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

    
    PlotEBEE         /afs/cern.ch/work/e/emanuele/public/ecal/pulseshapes_db/norm_template_histograms_ECAL_Run2016_runs_271983_272818.txt               new_Run2016_runs_271983_272818
    PlotEBEE         /afs/cern.ch/work/e/emanuele/public/ecal/pulseshapes_db/norm_template_histograms_ECAL_Run2016_runs_273301_273590.txt               new_Run2016_runs_273301_273590
    PlotEBEE         /afs/cern.ch/work/e/emanuele/public/ecal/pulseshapes_db/norm_template_histograms_ECAL_Run2016_runs_274080_274344.txt               new_Run2016_runs_274080_274344
    PlotEBEE         /afs/cern.ch/work/e/emanuele/public/ecal/pulseshapes_db/norm_template_histograms_ECAL_Run2016_runs_274958_275659.txt               new_Run2016_runs_274958_275659
    PlotEBEE         /afs/cern.ch/work/e/emanuele/public/ecal/pulseshapes_db/norm_template_histograms_ECAL_Run2016_runs_275757_275931.txt               new_Run2016_runs_275757_275931
    PlotEBEE         /afs/cern.ch/work/e/emanuele/public/ecal/pulseshapes_db/norm_template_histograms_ECAL_Run2016_runs_276315_276587.txt               new_Run2016_runs_276315_276587
    PlotEBEE         /afs/cern.ch/work/e/emanuele/public/ecal/pulseshapes_db/norm_template_histograms_ECAL_Run2016_runs_277932_277992.txt               new_Run2016_runs_277932_277992
    PlotEBEE         /afs/cern.ch/work/e/emanuele/public/ecal/pulseshapes_db/norm_template_histograms_ECAL_Run2016_runs_278969_278976.txt               new_Run2016_runs_278969_278976
    PlotEBEE         /afs/cern.ch/work/e/emanuele/public/ecal/pulseshapes_db/norm_template_histograms_ECAL_Run2016_runs_279115_279116.txt               new_Run2016_runs_279115_279116
    PlotEBEE         /afs/cern.ch/work/e/emanuele/public/ecal/pulseshapes_db/norm_template_histograms_ECAL_Run2016_runs_279653_279658.txt               new_Run2016_runs_279653_279658
    PlotEBEE         /afs/cern.ch/work/e/emanuele/public/ecal/pulseshapes_db/norm_template_histograms_ECAL_Run2016_runs_279841_279841.txt               new_Run2016_runs_279841_279841
    PlotEBEE         /afs/cern.ch/work/e/emanuele/public/ecal/pulseshapes_db/norm_template_histograms_ECAL_Run2016_runs_281616_282092.txt               new_Run2016_runs_281616_282092
    PlotEBEE         /afs/cern.ch/work/e/emanuele/public/ecal/pulseshapes_db/norm_template_histograms_ECAL_Run2016_runs_282408_283067.txt               new_Run2016_runs_282408_283067
    PlotEBEE         /afs/cern.ch/work/e/emanuele/public/ecal/pulseshapes_db/norm_template_histograms_ECAL_Run2016_runs_283171_283835.txt               new_Run2016_runs_283171_283835
    PlotEBEE         /afs/cern.ch/work/e/emanuele/public/ecal/pulseshapes_db/norm_template_histograms_ECAL_Run2016_runs_283863_284035.txt               new_Run2016_runs_283863_284035



Plots:

    r00t test/compare.C\(\"testSummaryruns_283863_284035.root\",\"testSummaryruns_271983_272818.root\"\)

    
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_271983_272818.root\",\"testSummaryruns_271983_272818.root\",\"271983_272818\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_273301_273590.root\",\"testSummaryruns_273301_273590.root\",\"273301_273590\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_274080_274344.root\",\"testSummaryruns_274080_274344.root\",\"274080_274344\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_274958_275659.root\",\"testSummaryruns_274958_275659.root\",\"274958_275659\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_275757_275931.root\",\"testSummaryruns_275757_275931.root\",\"275757_275931\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_276315_276587.root\",\"testSummaryruns_276315_276587.root\",\"276315_276587\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_277932_277992.root\",\"testSummaryruns_277932_277992.root\",\"277932_277992\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_278969_278976.root\",\"testSummaryruns_278969_278976.root\",\"278969_278976\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_279115_279116.root\",\"testSummaryruns_279115_279116.root\",\"279115_279116\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_279653_279658.root\",\"testSummaryruns_279653_279658.root\",\"279653_279658\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_279841_279841.root\",\"testSummaryruns_279841_279841.root\",\"279841_279841\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_281616_282092.root\",\"testSummaryruns_281616_282092.root\",\"281616_282092\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_282408_283067.root\",\"testSummaryruns_282408_283067.root\",\"282408_283067\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_283171_283835.root\",\"testSummaryruns_283171_283835.root\",\"283171_283835\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_283863_284035.root\",\"testSummaryruns_283863_284035.root\",\"283863_284035\"\)
    
    
    r00t  test/comparePulse.C\(\"testSummarynew_Run2016_runs_271983_272818.root\",\"testSummarynew_Run2016_runs_283863_284035.root\",\"end-beginning\"\)
    
    
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_273301_273590.root\",\"testSummarynew_Run2016_runs_283863_284035.root\",\"end-beginning-273301\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_274080_274344.root\",\"testSummarynew_Run2016_runs_283863_284035.root\",\"end-beginning-274080\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_274958_275659.root\",\"testSummarynew_Run2016_runs_283863_284035.root\",\"end-beginning-274958\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_275757_275931.root\",\"testSummarynew_Run2016_runs_283863_284035.root\",\"end-beginning-275757\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_276315_276587.root\",\"testSummarynew_Run2016_runs_283863_284035.root\",\"end-beginning-276315\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_277932_277992.root\",\"testSummarynew_Run2016_runs_283863_284035.root\",\"end-beginning-277932\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_278969_278976.root\",\"testSummarynew_Run2016_runs_283863_284035.root\",\"end-beginning-278969\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_279115_279116.root\",\"testSummarynew_Run2016_runs_283863_284035.root\",\"end-beginning-279115\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_279653_279658.root\",\"testSummarynew_Run2016_runs_283863_284035.root\",\"end-beginning-279653\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_279841_279841.root\",\"testSummarynew_Run2016_runs_283863_284035.root\",\"end-beginning-279841\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_281616_282092.root\",\"testSummarynew_Run2016_runs_283863_284035.root\",\"end-beginning-281616\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_282408_283067.root\",\"testSummarynew_Run2016_runs_283863_284035.root\",\"end-beginning-282408\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_283171_283835.root\",\"testSummarynew_Run2016_runs_283863_284035.root\",\"end-beginning-283171\"\)
    r00t -q  test/comparePulse.C\(\"testSummarynew_Run2016_runs_283863_284035.root\",\"testSummarynew_Run2016_runs_283863_284035.root\",\"end-beginning-283863\"\)
                                                             
    
    
    
    
SR in PF:
    
    
    ./test-run-8x-data-forECAL.sh 100
    ./test-run-8x-data-forECAL.sh 1000
    ./test-run-8x-data-forECAL.sh 10000
    
    
    gardener.py  l2selfiller   latino_stepB_data_std_numEvent10000.root    std.root
    gardener.py  l2selfiller   latino_stepB_data_highzshighgath_numEvent10000.root    highzshighgath.root
    gardener.py  l2selfiller   latino_stepB_data_highzslowgath_numEvent10000.root     highzslowgath.root
    
    
    r00t  std.root     highzshighgath.root     highzslowgath.root   DrawCompareMultiple.cxx\(\"mll\",80,50,150,\"1\"\)
    
    r00t  std.root     highzshighgath.root     highzslowgath.root   DrawCompareMultiple.cxx\(\"std_vector_electron_full5x5R9[0]\",100,0.5,1.1,\"1\"\)
    r00t  std.root     highzshighgath.root     highzslowgath.root   DrawCompareMultiple.cxx\(\"std_vector_electron_energy5x5[0]\",100,10,100,\"1\"\)
    r00t  std.root     highzshighgath.root     highzslowgath.root   DrawCompareMultiple.cxx\(\"std_vector_electron_ecalPFClusterIso[0]\",100,0,3,\"1\"\)
    r00t  std.root     highzshighgath.root     highzslowgath.root   DrawCompareMultiple.cxx\(\"jetRho\",100,0,100,\"1\"\)
    r00t  std.root     highzshighgath.root     highzslowgath.root   DrawCompareMultiple.cxx\(\"std_vector_lepton_pt[0]\",100,0,100,\"1\"\)
    r00t  std.root     highzshighgath.root     highzslowgath.root   DrawCompareMultiple.cxx\(\"std_vector_electron_R9[0]\",100,0.5,1.1,\"1\"\)
    r00t  std.root     highzshighgath.root     highzslowgath.root   DrawCompareMultiple.cxx\(\"std_vector_lepton_eta[0]\",100,-2.5,2.5,\"1\"\)

    
    
    
    
    ./test-run-8x-data-forECAL-SRPF.sh  2000
    ./test-run-8x-data-forECAL-SRPF.sh  10000
    
    gardener.py  l2selfiller   latino_stepB_data_std_numEvent10000.root    std.root
    gardener.py  l2selfiller   latino_stepB_data_highzshighgath_numEvent10000.root    highzshighgath.root
    gardener.py  l2selfiller   latino_stepB_data_highzslowgath_numEvent10000.root     highzslowgath.root

    
    gardener.py  l2selfiller   latino_stepB_data_NEW_highzshighgath_numEvent2000.root    srpf.root
    gardener.py  l2selfiller   latino_stepB_data_NEW_std_numEvent2000.root          std.root

    gardener.py  l2selfiller   latino_stepB_data_NEW_highzshighgath_numEvent10000.root    srpf.root
    gardener.py  l2selfiller   latino_stepB_data_NEW_std_numEvent10000.root          std.root

    
    cd /afs/cern.ch/work/a/amassiro/Latinos/Framework/CMSSW_8_0_26_patch1/src/LatinoAnalysis/ShapeAnalysis/test/draw/
    r00t  std.root     srpf.root       DrawCompareMultiple.cxx\(\"std_vector_electron_full5x5R9[0]\",100,0.5,1.1,\"1\"\)
    r00t  std.root     srpf.root       DrawCompareMultiple.cxx\(\"std_vector_electron_energy5x5[0]\",100,10,200,\"1\"\)
    r00t  std.root     srpf.root       DrawCompareMultiple.cxx\(\"std_vector_electron_ecalPFClusterIso[0]\",100,0,3,\"1\"\)
    r00t  std.root     srpf.root       DrawCompareMultiple.cxx\(\"jetRho\",100,0,100,\"1\"\)
    r00t  std.root     srpf.root       DrawCompareMultiple.cxx\(\"std_vector_lepton_pt[0]\",100,0,100,\"1\"\)
    r00t  std.root     srpf.root       DrawCompareMultiple.cxx\(\"std_vector_electron_R9[0]\",100,0.5,1.1,\"1\"\)
    r00t  std.root     srpf.root       DrawCompareMultiple.cxx\(\"std_vector_lepton_eta[0]\",100,-2.5,2.5,\"1\"\)
    
    r00t  std.root     srpf.root       DrawCompareMultiple.cxx\(\"std_vector_electron_R9[0]\",100,0.5,1.1,\"abs\(std_vector_lepton_eta[0]\)\<1.5\"\)
    r00t  std.root     srpf.root       DrawCompareMultiple.cxx\(\"std_vector_electron_R9[0]\",100,0.5,1.1,\"abs\(std_vector_lepton_eta[0]\)\>1.5\"\)
    
    r00t  std.root     srpf.root       DrawCompareMultiple.cxx\(\"mll\",100,50,150,\"1\"\)
    r00t  std.root     srpf.root       DrawCompareMultiple.cxx\(\"mll\",100,50,150,\"abs\(std_vector_lepton_eta[0]\)\<1.5\"\)
    r00t  std.root     srpf.root       DrawCompareMultiple.cxx\(\"mll\",100,50,150,\"abs\(std_vector_lepton_eta[0]\)\>1.5\"\)
    
    r00t  std.root     srpf.root       DrawCompareMultiple.cxx\(\"std_vector_electron_ecalPFClusterIso[0]\",100,0,3,\"abs\(std_vector_lepton_eta[0]\)\<1.5\"\)
    r00t  std.root     srpf.root       DrawCompareMultiple.cxx\(\"std_vector_electron_ecalPFClusterIso[0]\",100,0,3,\"abs\(std_vector_lepton_eta[0]\)\>1.5\"\)
    
    
    r00t  std.root     srpf.root       DrawCompareMultiple.cxx\(\"std_vector_electron_full5x5_sigmaIetaIeta[0]\",100,0.0,0.05,\"1\"\)
    r00t  std.root     srpf.root       DrawCompareMultiple.cxx\(\"std_vector_electron_dEtaSeedCalo[0]\",100,-0.02,0.02,\"1\"\)
    r00t  std.root     srpf.root       DrawCompareMultiple.cxx\(\"std_vector_electron_dPhiSeedCalo[0]\",100,-0.02,0.02,\"1\"\)
    
    
    
    
