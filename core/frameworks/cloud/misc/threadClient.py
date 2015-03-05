#!/usr/bin/env python
from waggleUtil import *
import sys
import re
import time
import threading

NUM_OP = 0
LATENCY_SUM = 0
S = threading.Semaphore()

class Monitor():
    def __init__(self, filePath, timer):
        self.timer = timer
        self.filePath = filePath
        #self.numOp = 0
        #self.latencySum = 0
        self.fileStream = None
        if self.filePath == None:
            print "File path is None, not to write file."
        else:
            bufsize = 10000
            self.fileStream = open(self.filePath, 'a+', bufsize)        
        self.semaphore = threading.BoundedSemaphore()

    def write_file(self, dataStr):
        if self.fileStream == None:
            print "File stream is None, check if the path is set."
            return
        else:
            self.fileStream.write(dataStr.encode("UTF-8"))
            return

    def close_file(self):
        self.fileStream.close()

def monitor(): # may need mutex
        time.sleep(3)        
        latencyAvg = LATENCY_SUM / NUM_OP
        
        global LATENCY_SUM
        global NUM_OP
        global S
        S.acquire()
        LATENCY_SUM = 0
        NUM_OP = 0
        print "work: NUM_OP = " + str(NUM_OP)
        print "work: LATENCY_SUM = " + str(LATENCY_SUM)
        S.release()
        
def work():
    global LATENCY_SUM
    global NUM_OP
    for i in range (0, 10):
        time.sleep(1)
        NUM_OP = NUM_OP + 1
        LATENCY_SUM = LATENCY_SUM + 10
        print "work: NUM_OP = " + str(NUM_OP)
        print "work: LATENCY_SUM = " + str(LATENCY_SUM)

def run(self):
        while True:
            try:
                self.monitor()
                time.sleep(self.timer)
            except KeyboardInterrupt:
                self.close_file()
                print "KeyboardInterrupt, record file flushed."
                return


if __name__  == '__main__':
    filePath = "trafic_rec_" + time.strftime("%m%d_%H%M%S")

    LATENCY_SUM = 0
    NUM_OP = 0
    #print "Output file: " + filePath
    #m = Monitor(filePath, 1)
    t1 = threading.Thread(name='monitor', target=monitor)
    t2 = threading.Thread(name='work', target=work) 
    t1.start()
    t2.start()
