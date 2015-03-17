import time
import multiprocessing
import cloud_router
import cloud_data_proc
import cloud_forward
import cloud_reg_proc
from commands import getoutput as bash
from cloud_localconfig import *


if __name__ == '__main__':
    bash('mkdir '+LOCAL_DIR)
    funcs = [cloud_router.run,
         cloud_data_proc.run,
         cloud_forward.run,
         cloud_reg_proc.run]
    process_list = {}
    #start all the processes
    for procs in funcs:
        process_list[procs] = multiprocessing.Process(target = procs)
        process_list[procs].start()

    #auto restart processes if they die
    while 1:
        time.sleep(5)
        print time.asctime(), "I am alive and watching..."
        for procs in process_list:
            if process_list[procs].is_alive() == False:
                print procs
                process_list[procs] = multiprocessing.Process(target = procs)
                process_list[procs].start()

