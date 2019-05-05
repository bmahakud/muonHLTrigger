


import os
import sys

File=sys.argv[1]



copy="scp ./%s bmahakud@lxplus.cern.ch:/afs/cern.ch/user/b/bmahakud/work/PostDocWork/MuonHLT/HLTNote2018/FinalDirFeb3_2019ForPaper/BoostedJpsi"%(str(File))

os.system(copy)

