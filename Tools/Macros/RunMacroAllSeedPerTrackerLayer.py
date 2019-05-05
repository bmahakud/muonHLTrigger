import sys,os

#path="/eos/uscms/store/user/bmahakud/ProductionHLTAN_LPC_IterL3HighStat/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/ProductionHLTAN_LPC_IterL3HighStat/181130_193653/0000/muonNtupleData_*.root"

#path="/eos/uscms/store/user/bmahakud/SingleMu_PromptReco2018A_v1_Crv2/SingleMuon/SingleMu_PromptReco2018A_v1_Crv2/190203_010755/0000/muonNtuple_*.root"
#path="/eos/uscms/store/user/bmahakud/SingleMu_PromptReco2018B_v1/SingleMuon/SingleMu_PromptReco2018B_v1/190203_010528/0000/muonNtuple_*.root"
path1="/eos/uscms/store/user/bmahakud/OneSeedPerTrackerLayerMC92X/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/OneSeedPerTrackerLayerMC92X/190211_182945/0000/muonNtuple_*.root"
sample1="MC92XOneSeedPerTrackerLayer"

path2="/eos/uscms/store/user/bmahakud/ThreeSeedPerTrackerLayerMC92X/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/ThreeSeedPerTrackerLayerMC92X/190211_183137/0000/muonNtuple_*.root"
sample2="MC92XThreeSeedPerTrackerLayer"


command6 ="root -l -b -q 'readNtuplesPostfilter_IterL3_OIonly.C(\"%s\",\"%s\")'"%(str(path1),str(sample1))

os.system(command6)


command7 ="root -l -b -q 'readNtuplesPostfilter_IterL3_OIonly.C(\"%s\",\"%s\")'"%(str(path2),str(sample2))

os.system(command7)
















