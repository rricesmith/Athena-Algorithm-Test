
from AthenaCommon.GlobalFlags import globalflags
globalflags.InputFormat.set_Value_and_Lock('pool')
import AthenaPoolCnvSvc.ReadAthenaPool
svcMgr.EventSelector.InputCollections = ["g4.HITS.root"]

alg = CfgMgr.Alg()
athAlgSeq += alg

#jps.AthenaCommonFlags.FilesInput= ["g4.HITS.root"]
#jps.AthenaCommonFlags.AccessMode="ClassAccess"

theApp.EvtMax=-1
alg.McEventCollection = "TruthEvent"

#jps.AthenaCommonFlags.HistOutputs = ["HIST:testHist.root"]
svcMgr += CfgMgr.THistSvc()
svcMgr.THistSvc.Output += ["HIST DATAFILE='myfile.root' OPT='RECREATE'"]