import sys,os

path="/eos/uscms/store/user/bmahakud/ProductionCasTest_v1/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/ProductionCasTest_v1/181205_133338/0000/CascadeTkMuCorrNew.root"

sample="MC92XDY"

command1 ="root -l -b -q 'readNtuplesPost_CascadenTkMu.C(\"%s\",\"%s\")'"%(str(path),str(sample))
command2 ="root -l -b -q 'readNtuplesPost_CascadeOnly.C(\"%s\",\"%s\")'"%(str(path),str(sample))
command3 ="root -l -b -q 'readNtuplesPost_TkMuOnly.C(\"%s\",\"%s\")'"%(str(path),str(sample))
command4 ="root -l -b -q 'MuonOffHltTrackMatch_Cascade.C(\"%s\",\"%s\")'"%(str(path),str(sample))



os.system(command1)
os.system(command2)
os.system(command3)
os.system(command4)
















