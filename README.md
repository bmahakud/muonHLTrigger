# muonHLTrigger
This code setup is used to produce plots for the  http://bmahakud.web.cern.ch/bmahakud/MuonHLT/NoteLatest/AN-17-185_temp.pdf and in general could be used to produce intermediate plots while running re-HLT. To setup the framework, instructions are given in 10_2_10, but should work in other versions of cmssw without much problem.
```
cmsrel CMSSW_10_2_10 
cd src
cmsenv
git cms-addpkg HLTrigger/Configuration
git cms-addpkg RecoMuon/TrackerSeedGenerator
scram b -j 8
```
