import time
import threading
import commands
from sw_l1_InotifyKernel import *

if __name__ == "__main__":
    commL = communicatorLoader()
    Monitor('/dev')
    print "--------------------------------------"
    commL.stop()
    while len(threading.enumerate()) > 1:
        print threading.enumerate()
        time.sleep(1)
        print "shutting down..."
    commands.getoutput("rm *.pyc")
