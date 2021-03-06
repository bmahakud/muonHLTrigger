#Step-1: Ntuple Maker
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
git clone https://github.com/bmahakud/muonHLTrigger MuonHLTNtuples
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

#CRAB

There are example crab configs available for crab submission: CrabConfig_MC.py, CrabConfig_DataA_v1.py



# Step-2: Produce Efficiency plots running on top of Ntuples produced from the previous step.

Macros are available inside the directory :
https://github.com/bmahakud/muonHLTrigger/tree/master/Tools/Macros

How to run the macros:
The following command is used to run all the macros. You can run one by one. First the check the input file locations before running the commands.
```
python RunMacroAll.py 
```

If you want to run one by one , the command should be like the following
```
root -l -b -q 'readNtuplesPostfilter_L1WrtOffline.C("/eos/uscms/store/user/bmahakud/ProductionHLTAN_LPC_IterL3HighStat/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/ProductionHLTAN_LPC_IterL3HighStat/181130_193653/0000/muonNtupleData_*.root","DYMC2018")
```

After completing this step, you will get several root files , inside which efficiency plots will be stored. You can proceed to the next step to produce plots using the root files obtained in this step.
Different kinds of root macros available to produce efficiencies : L1 eff, L2 Eff,  L3 Eff wrt. L1 etc.
```
Diff_Cascade_IterL3.C                       readNtuplesPostfilter_L1WrtOffline.C
KinePlot_BoostedIterL3.C                    readNtuplesPre_CascadeAndTkMu.C
L2NSeedingPlots_forAN.C                     readNtuplesPrefilter_IterL3.C
MuonOffHltTrackMatch_Cascade.C              readNtuplesPrefilter_IterL3_IO2fromL1nL2.C
MuonOffHltTrackMatch_IterL3_PtResolution.C  readNtuplesPrefilter_IterL3_IOFromL1.C
OIFromCode_readNtuplesPostfilter_forAN.C    readNtuplesPrefilter_IterL3_IOFromL2.C
readNtuplesPost_CascadeMu50.C               readNtuplesPrefilter_IterL3_L2EffoverL1.C
readNtuplesPost_CascadeOnly.C               readNtuplesPrefilter_IterL3_L2IneffoverL1.C
readNtuplesPost_CascadenTkMu.C              readNtuplesPrefilter_IterL3_L2Purity.C
readNtuplesPost_TkMuOnly.C                  readNtuplesPrefilter_IterL3_OIonly.C
readNtuplesPostfilter_BoostedIterL3.C       readNtuplesPrefilter_IterL3_PixelPair.C
readNtuplesPostfilter_IterL3.C              readNtuplesPrefilter_SharedHitsIterL3.C
readNtuplesPostfilter_IterL3_L2overL1Eff.C  readNtuplesPrefilter_forANBoostedJPsi.C
readNtuplesPostfilter_IterL3_OIonly.C

```

# Step-3: Make plots

All macros have been put in my public area: /afs/cern.ch/user/b/bmahakud/public/PlotterMacros/Macros. There are different folders inside the directory. Each folder contains the root file and the corresponding macro. The list of folders available are :
```
April92019       CPUtimeVsSeeds                   InputFiles         IterL3vsIOvsOI      TimingPlots
BoostedJpsi      DataVsMCIterL3                   IOiterations       Level-1MuonTrigger  TriggerPerformancesInData
BoostedJPsi      DiffHitlessHitbased              IOnOIinDiffPeriod  Level-2Trigger
CascadeAndTkMu   ForJanImpactParameterResolution  IterL3_InsideOut   PromptLowPt
CascadeVsIterL3  GroupedVsStandard                IterL3_OutsideIn   README.md
copyToNote.sh    HighLevelMuonTrigger             IterL3Stuff        SFOptimization
```

For any queries email to: bibhu.phy@gmail.com







# Debugger

The same Ntupler can be used as a debugger. The relevant dependencies for using it as debugger has beed added in this version of ntupler.  You just need to change the .cc file inside Analysis/plugins
https://github.com/bmahakud/muonHLTrigger/blob/master/Analyzers/plugins/MuonNtuples.cc_DebuggerVersion
```
cd Analysis/plugins
mv MuonNtuples.cc_DebuggerVersion MuonNtuples.cc

```
compile and run the code : 
```
cmsRun BoostedJPsi102XMC.py 
```

If you need to add more functions and details needed to debug, one can copy relevant details from 
https://github.com/JanFSchulte/MuonHLTNtuples/blob/master/Debugger/plugins/MuonHLTDebugger.cc















