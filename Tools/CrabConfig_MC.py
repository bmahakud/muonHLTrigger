import sys


from CRABClient.UserUtilities import config

config = config()

config.JobType.pluginName   = 'Analysis'
config.JobType.outputFiles  = ['muonNtuple.root']#, 'DQMIO.root']muonNtupleDataIOIter2.root

config.Data.unitsPerJob     = 5000
config.Data.totalUnits      = 1000000
config.Data.splitting       = 'EventAwareLumiBased'

config.Data.useParent       = True #!!!!
#config.Data.useParent       = False #!!!!

config.Site.storageSite     = 'T3_US_FNALLPC' #'T3_US_FNALLPC'
config.JobType.numCores     = 1
config.JobType.maxMemoryMB  = 2500

from CRABAPI.RawCommand import crabCommand
from CRABClient.ClientExceptions import ClientException
from httplib import HTTPException

tag = "DYJets_Fall102XFlat"

    # We want to put all the CRAB project directories from the tasks we submit here into one common directory.
    # That's why we need to set this parameter (here or above in the configuration file, it does not matter, we will not overwrite it).
config.General.workArea   = tag
config.Data.outLFNDirBase = '/store/user/bmahakud/' + tag



config.JobType.psetName    = 'hlt_DY102XMC.py' # 'hlt_2018.py'#'hlt_2018_CkfTrajectoryBuilder.py'#'hlt_2018.py'
config.General.requestName = tag
#config.Data.inputDataset   = '/DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIAutumn18DR-FlatPU28to62NZS_102X_upgrade2018_realistic_v15-v1/AODSIM'
#config.Data.inputDataset = '/JPsiToMuMu_Pt20to100-pythia8-gun/RunIIAutumn18DRPremix-102X_upgrade2018_realistic_v15_ext1-v1/AODSIM'
config.Data.inputDataset ='/DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall18DR-FlatPU0to70_102X_upgrade2018_realistic_v11-v1/AODSIM'

#/DisplacedSUSY_stopToBottom_M_900_1000mm_TuneCP5_13TeV_pythia8/RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/MINIAODSIM
config.Data.outputDatasetTag   = tag
#print 'submitting config:'
#        print config
#        submit(config)
