import os

path="root://cmseos.fnal.gov//store/user/bmahakud/IOcorrWIter3_SingleMu_PromptReco2018A_v1/SingleMuon/IOcorrWIter3_SingleMu_PromptReco2018A_v1/190213_170619/0000/muonNtuple.root"

sample="PromptRecoA1"

command1 ="root -l -b -q 'readNtuplesPrefilter_IterL3_L2EffoverL1.C(\"%s\",\"%s\")'"%(str(path),str(sample))

os.system(command1)

