import sys,os

#path="/eos/uscms/store/user/bmahakud/IOcorrWIter3_SingleMu_PromptReco2018A_v1/SingleMuon/IOcorrWIter3_SingleMu_PromptReco2018A_v1/190213_170619/0000/muonNtuple_125.root"

path="root://cmseos.fnal.gov//store/user/bmahakud/IOcorrWIter3_SingleMu_PromptReco2018A_v1/SingleMuon/IOcorrWIter3_SingleMu_PromptReco2018A_v1/190213_170619/0000/muonNtuple.root"

sample="PromptRecoA1"

command1 ="root -l -b -q 'readNtuplesPrefilter_IterL3.C(\"%s\",\"%s\")'"%(str(path),str(sample))
command2 ="root -l -b -q 'readNtuplesPrefilter_IterL3_OIonly.C(\"%s\",\"%s\")'"%(str(path),str(sample))
command3="root -l -b -q 'readNtuplesPrefilter_IterL3_IO2fromL1nL2.C(\"%s\",\"%s\")'"%(str(path),str(sample))
command4="root -l -b -q 'readNtuplesPrefilter_IterL3_IOFromL1.C(\"%s\",\"%s\")'"%(str(path),str(sample))
#os.system(command1)
#os.system(command2)
#os.system(command3)
os.system(command4)






#root -l -b -q 'readNtuplesPostfilter_L1WrtOffline.C("/eos/uscms/store/user/bmahakud/ProductionHLTAN_LPC_IterL3HighStat/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/ProductionHLTAN_LPC_IterL3HighStat/181130_193653/0000/muonNtupleData_*.root","DYMC2018")'


#root -l -b -q 'readNtuplesPrefilter_IterL3.C("/eos/uscms/store/user/bmahakud/ProductionHLTAN_LPC_IterL3HighStat/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/ProductionHLTAN_LPC_IterL3HighStat/181130_193653/0000/muonNtupleData_*.root","DYMC2018")'


#root -l -b -q 'readNtuplesPostfilter_IterL3.C("/eos/uscms/store/user/bmahakud/ProductionHLTAN_LPC_IterL3HighStat/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/ProductionHLTAN_LPC_IterL3HighStat/181130_193653/0000/muonNtupleData_*.root","DYMC2018")'


#root -l -b -q 'readNtuplesPrefilter_IterL3_OIonly.C("/eos/uscms/store/user/bmahakud/ProductionHLTAN_LPC_IterL3HighStat/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/ProductionHLTAN_LPC_IterL3HighStat/181130_193653/0000/muonNtupleData_*.root","DYMC2018")'



#root -l -b -q 'readNtuplesPostfilter_IterL3_OIonly.C("/eos/uscms/store/user/bmahakud/ProductionHLTAN_LPC_IterL3HighStat/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/ProductionHLTAN_LPC_IterL3HighStat/181130_193653/0000/muonNtupleData_*.root","DYMC2018")'


#root -l -b -q 'readNtuplesPrefilter_IterL3_IOFromL1.C("/eos/uscms/store/user/bmahakud/ProductionHLTAN_LPC_IterL3HighStat/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/ProductionHLTAN_LPC_IterL3HighStat/181130_193653/0000/muonNtupleData_*.root","DYMC2018")'

#root -l -b -q 'readNtuplesPrefilter_IterL3_IOFromL2.C("/eos/uscms/store/user/bmahakud/ProductionHLTAN_LPC_IterL3HighStat/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/ProductionHLTAN_LPC_IterL3HighStat/181130_193653/0000/muonNtupleData_*.root","DYMC2018")'

#root -l -b -q 'readNtuplesPrefilter_IterL3_L2EffoverL1.C("/eos/uscms/store/user/bmahakud/ProductionHLTAN_LPC_IterL3HighStat/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/ProductionHLTAN_LPC_IterL3HighStat/181130_193653/0000/muonNtupleData_*.root","DYMC2018")'


#root -l -b -q 'MuonOffHltTrackMatch_IterL3_PtResolution.C("/eos/uscms/store/user/bmahakud/ProductionHLTAN_LPC_IterL3HighStat/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/ProductionHLTAN_LPC_IterL3HighStat/181130_193653/0000/muonNtupleData_*.root","DYMC2018")'

#readNtuplesPrefilter_IterL3_IO2fromL1nL2.C
















