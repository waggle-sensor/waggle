import time
import multiprocessing
import router
import data_proc
import forward
import reg_proc
from commands import getoutput as bash
from localconfig import *

bash('mkdir '+LOCAL_DIR)
funcs = [router.run,
         data_proc.run,
         forward.run,
         reg_proc.run]
print forward.run.__name__

procs_list = [multiprocessing.Process(target = i) for i in funcs]
print procs_list
exit()
for procs in procs_list:
    procs.start()

    #we have to restart the processes when they die, so need to add that feature
