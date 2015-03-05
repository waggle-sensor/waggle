#!/usr/bin/env python
import logging
import pika
#from vectorClock import *
import time
#from time import sleep
import os
import socket
import uuid
import threading
import sys

from waggleUtil import *


NUM_OP = 0
NUM_OP_TOTAL = 0
LATENCY_SUM = 0
M_RUN = 1
S = threading.Semaphore()


logging.basicConfig()


class NodeDataClient:

    def __init__(self, RMQ_ip, port, user, passwd, exch, rout_key):
        """ Initializer of data client, all parameters needed to be filled so to access the remote server. Please see example at the bottom for use.
        """
        self.RMQHost = RMQ_ip
        self.RMQPort = int(port)
        self.RMQUser = user
        self.RMQPassWd = passwd
        self.RMQExchange = exch
        self.RMQRoutingKey = rout_key
        self.credentials = pika.PlainCredentials(self.RMQUser, self.RMQPassWd) #'clients','Ruza3que'
        
        self.connection = pika.BlockingConnection(pika.ConnectionParameters(host = self.RMQHost, port = self.RMQPort, credentials= self.credentials)) #host='192.168.1.29', port= 5672
        #connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
        self.channel = self.connection.channel()
        #self.channel.queue_declare(queue = self.RMQRoutingKey) #'hello'
        self.delimiter0 = DELIMITERS[0]
        

    def _unitTest(self, param):
        print param
        src = '/home/ubuntu/private/test.blob'
        dest = '149.165.149.3:/export/permanent/waggle_datastore/BLOBSTORE/'
        self._blob_transfer(src, dest)
        return 0

    def _send(self, msg):
        """ 
        ========= DO NOT use this function in your code directly!!! ==========
        This is a low level function, you should only use msg_send(msg) or multi_send(msgArray)
        """
        '''
        self.connection = pika.BlockingConnection(pika.ConnectionParameters(host = self.RMQHost, port = self.RMQPort, credentials= self.credentials)) #host='192.168.1.29', port= 5672
        #connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
        self.channel = self.connection.channel()
        #self.channel.queue_declare(queue = self.RMQRoutingKey) #'hello'
        self.delimiter0 = DELIMITERS[0]

        localClock = int(round(1000*1000*time.time()))
        #strToSend = getLanIP() + self.delimiter + dataName + self.delimiter + dataType + self.delimiter + DataValue + self.delimiter + str(localClock)

        '''
        global NUM_OP
        global LATENCY_SUM
        start = time.time()
        ret = self.channel.basic_publish(
            exchange = self.RMQExchange, routing_key = self.RMQRoutingKey, body = msg
            )
        end = time.time()
        #S.acquire()
        LATENCY_SUM = LATENCY_SUM + (end - start)*1000
        #print NUM_OP
        #S.acquire()
        #print "Send Latency: " + str((end - start)*1000) + " ms"
        #print "Connection last latency: " + str((end - connStart)*1000) + " ms"
        #print 'ret = ' + ret # " [x] Msg sent: " + msg 
        #self.close()
    
    def close(self):
        """ 
        Close connection. Call this after you finish use client to save server side resource.
        You need to recreate the DataClient object to send data if you called this, so put this at the end of your logic session.

        Note: you may get warning like this:
        WARNING:pika.adapters.base_connection:Unknown state on disconnect: 0
        This is due to a known pika bug, the warning is printed when connection.close() is called, but won't affect the behavior of the program.
        """
        self.connection.close()
   
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

    def monitor(self): # may need mutex
        time.sleep(self.timer)
        global LATENCY_SUM
        global NUM_OP
        global S
        if 0 == NUM_OP:
            NUM_OP = 1
        latencyAvg = LATENCY_SUM / NUM_OP

        print "NUM_OP = " + str(NUM_OP)
        S.acquire()
        LATENCY_SUM = 0
        NUM_OP = 0
        print "work: LATENCY_SUM = " + str(LATENCY_SUM)
        print latencyAvg
        self.write_file(str(latencyAvg) + "\n")
        S.release()

def runMonitor(filePath, time_sec):
    m = Monitor(filePath, time_sec)
    while 1 == M_RUN:
        try:
            m.monitor()
        except KeyboardInterrupt:
            m.close_file()
            print "KeyboardInterrupt, record file flushed."
            return


#============================================================
def work(dataClient, numOp):
    #for msg in load:
    #    dataClient._send(msg)
        #sleep(1)
    global LATENCY_SUM
    global NUM_OP
    global M_RUN
    for i in range(0, opNum):
        start = time.time()
        msg = randomStringGen(strLen)
        dataClient._send(msg)
        #time.sleep(0.05)
        end = time.time()
        NUM_OP = NUM_OP + 1
        LATENCY_SUM  = LATENCY_SUM + (end - start)*1000
        #print  NUM_OP 
    M_RUN = 0


if __name__  == '__main__':
    #Test case and example
    #sys.argv
    RMQ_ip = '149.165.149.8'
    RMQ_port = 5672
    RMQ_user = 'clients'
    RMQ_passwd = 'Ruza3que'
    RMQ_exchange = ''
    RMQ_routing_key = 'sizeTest'
    dataClient = NodeDataClient(RMQ_ip, RMQ_port, RMQ_user, RMQ_passwd, RMQ_exchange, RMQ_routing_key)

    filePath = "queue_latency_avg_" + time.strftime("%m%d_%H%M%S")
    opNum = int(sys.argv[1])
    strLen = 100
    time_sec = 1
    thread_monitor = threading.Thread(target = runMonitor, args=(filePath, time_sec,) )
    thread_work = threading.Thread(target = work, args=(dataClient,opNum,) )
    thread_monitor.start()
    thread_work.start()
    #dataClient.connection.close()
'''    
    load=[]
    for i in range(0, opNum):
        load.append(randomStringGen(strLen))

    #for it in load:
    #    print it 

    #dataClient._unitTest('testing: _blob_transfer')
    msg1 = "test"
    start = time.time()
    #for msg in load:
    #    dataClient._send(msg)
        #sleep(1)
    for i in range(0, opNum):
        msg = randomStringGen(strLen)
        dataClient._send(msg)
    end = time.time()
    meanLatency = (end - start)*1000/opNum
    print "meanLatency = " + str(meanLatency)
'''
        #sleep(0.5)
    #dataClient.multi_send( msgArray)

    #Sample data for blob
'''
    nameB = ['SourcePath','DestPath','File_UUID', 'Notes']
    typeB = ['s','s','s','s']
    dataB = ['/home/ubuntu/private/test.blob','149.165.149.3:/export/permanent/waggle_datastore/BLOBSTORE/', str(uuid.uuid1()),'Test blob_send()']
    unitB = ['','','','']
    noteB = ['note1','note2','note3','note4']

    blobSrc = '/home/ubuntu/private/test2.blob'
    blobDest = '149.165.149.3:/export/permanent/waggle_datastore/BLOBSTORE/'
    successMsg = NodeDataClient.msg_gen('instance-VM123', 'sensor-186', str(time.time()), nameB, typeB, dataB, unitB, noteB)
    #dataClient.blob_send(blobSrc, blobDest, successMsg)
'''

