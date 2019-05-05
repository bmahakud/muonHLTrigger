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
Once it compiles well copy the OI seeder from Area.  These are the same as in the CMSSW_10_2_10. I have made few changes to store the number of OI seeds per muon in my version. You can look and compare.

```
cd RecoMuon/TrackerSeedGenerator/plugins
cp /afs/cern.ch/user/b/bmahakud/public/MuonOISeeders_v3p5/TSGForOIFromL2.h .
cp /afs/cern.ch/user/b/bmahakud/public/MuonOISeeders_v3p5/TSGForOIFromL2.cc .
cd -
git clone https://github.com/bmahakud/muonHLTrigger
scram b -j 8
voms-proxy-init -voms cms 
```
If the code compiles fine , you can run 
