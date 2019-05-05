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
If the code compiles fine , you can run the following config file. Even though the name suggests for boostedJPsi, but it works for all MC scenario. You can change the input root files accordingly. 

```
cmsRun BoostedJPsi102XMC.py
```

Or you can generate your own configuration file using the 

```
hltGetConfiguration /online/collisions/2018/2e34/v3.5/HLT/V12 --globaltag 102X_upgrade2018_realistic_v1 --path HLTriggerFirstPath,HLT_IsoMu27_v*,HLT_Mu50_v*,HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v*,HLTriggerFinalPath,HLTAnalyzerEndpath --input root://cms-xrd-global.cern.ch//store/mc/RunIIFall18DRPremix/JPsiToMuMu_Pt20to100-pythia8-gun/GEN-SIM-RAW/102X_upgrade2018_realistic_v11_ext1-v1/60000/B7988D29-0AC8-5F46-89E4-EC42AA3ACE26.root --mc --process TEST --full --offline --l1-emulator uGT --l1 L1Menu_Collisions2018_v1_0_0-d1_xml --prescale none --max-events 10 --output none > HLT_MC.py

```
Or for the muon HLT paper, the config files could be generated using the instructions in the twiki

https://twiki.cern.ch/twiki/bin/viewauth/CMS/MuonHLTPerformanceStudies















