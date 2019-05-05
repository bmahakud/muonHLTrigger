import sys,os

#path="/eos/uscms/store/user/bmahakud/ProductionHLTAN_LPC_IterL3HighStat/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/ProductionHLTAN_LPC_IterL3HighStat/181130_193653/0000/muonNtupleData_*.root"

#path="/eos/uscms/store/user/bmahakud/SingleMu_PromptReco2018A_v1_Crv2/SingleMuon/SingleMu_PromptReco2018A_v1_Crv2/190203_010755/0000/muonNtuple_*.root"
#path="/eos/uscms/store/user/bmahakud/SingleMu_PromptReco2018B_v1/SingleMuon/SingleMu_PromptReco2018B_v1/190203_010528/0000/muonNtuple_*.root"
path="/eos/uscms/store/user/bmahakud/SingleMu_PromptReco2018C_v2/SingleMuon/SingleMu_PromptReco2018C_v2/190203_010428/0000/muonNtuple_*.root"
sample="PromptReco2018Cv2"

command1 ="root -l -b -q 'readNtuplesPostfilter_L1WrtOffline.C(\"%s\",\"%s\")'"%(str(path),str(sample))
command2 ="root -l -b -q 'readNtuplesPrefilter_IterL3_L2EffoverL1.C(\"%s\",\"%s\")'"%(str(path),str(sample))
command3 ="root -l -b -q 'readNtuplesPrefilter_IterL3.C(\"%s\",\"%s\")'"%(str(path),str(sample))
command4 ="root -l -b -q 'readNtuplesPostfilter_IterL3.C(\"%s\",\"%s\")'"%(str(path),str(sample))
command5 ="root -l -b -q 'readNtuplesPrefilter_IterL3_OIonly.C(\"%s\",\"%s\")'"%(str(path),str(sample))
command6 ="root -l -b -q 'readNtuplesPostfilter_IterL3_OIonly.C(\"%s\",\"%s\")'"%(str(path),str(sample))
command7 ="root -l -b -q 'readNtuplesPrefilter_IterL3_IOFromL1.C(\"%s\",\"%s\")'"%(str(path),str(sample))
command8 ="root -l -b -q 'readNtuplesPrefilter_IterL3_IOFromL2.C(\"%s\",\"%s\")'"%(str(path),str(sample))
command9 ="root -l -b -q 'MuonOffHltTrackMatch_IterL3_PtResolution.C(\"%s\",\"%s\")'"%(str(path),str(sample))
command10="root -l -b -q 'readNtuplesPrefilter_IterL3_IO2fromL1nL2.C(\"%s\",\"%s\")'"%(str(path),str(sample))


os.system(command1)
os.system(command2)
os.system(command3)
os.system(command4)
os.system(command5)
os.system(command6)
os.system(command7)
os.system(command8)
os.system(command9)
os.system(command10)








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
















