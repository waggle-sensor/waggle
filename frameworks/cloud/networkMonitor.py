#!/usr/bin/env python
from waggleUtil import *
import sys
import re
import time

class Monitor():
    def __init__(self, filePath, timer):
        self.timer = timer
        self.filePath = filePath
        self.lastRX = 0
        self.lastTX = 0
        self.fileStream = None
    def write_file(self, dataStr):
        bufsize = 10000  #100000000
        if self.filePath == None:
            print "File path is None, not to write file."
            return
        self.fileStream = open(self.filePath, 'a+', bufsize)
        self.fileStream.write(dataStr.encode("UTF-8"))

    def close_file(self):
        self.fileStream.close()

    def monitor(self):
        exp = "ifconfig eth0|grep bytes | awk '{print $2  \" \" $6}'"
        ret = runLinuxCMD(exp)
        #print ret
        dat =  re.split('[\W]+', ret)
        #print dat
        RX = int(dat[3])
        TX = int(dat[5])
        recv = RX - self.lastRX
        sent = TX - self.lastTX
        self.lastRX = RX
        self.lastTX = TX
        print "Inbound: " + str(recv) + "; Outbound: " + str(sent)
        self.write_file(str(recv) + "\t" + str(sent) + "\n") 

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
    print "Output file: " + filePath
    m = Monitor(filePath, float(sys.argv[1]))

    m.run()
