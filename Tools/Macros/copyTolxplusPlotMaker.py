import os
import sys

filename=sys.argv[1]

command="scp ./%s bmahakud@lxplus.cern.ch:/afs/cern.ch/user/b/bmahakud/work/PostDocWork/MuonHLT/HLTNote2018/FinalDirFeb3_2019ForPaper/InputFiles"%(filename)
os.system(command)
