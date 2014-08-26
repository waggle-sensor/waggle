#!/usr/bin/env python
import logging
import pika
#from vectorClock import *
import time
import os
import socket
import uuid

#from waggle.common.util import *
#from waggle.common.messaging import msg_gen # temporary
from waggle.common.messaging2 import DELIMITERS
from waggle.common.messaging2 import *

#global VECTOR_CLOCK
#VECTOR_CLOCK = VectorClock('|:|')
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
        credentials = pika.PlainCredentials(self.RMQUser, self.RMQPassWd) #'clients','Ruza3que'
        self.connection = pika.BlockingConnection(pika.ConnectionParameters(host = self.RMQHost, port = self.RMQPort, credentials= credentials)) #host='192.168.1.29', port= 5672
        #connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
        self.channel = self.connection.channel()
        #self.channel.queue_declare(queue = self.RMQRoutingKey) #'hello'
        self.delimiter0 = DELIMITERS[0]
    
    def _unitTest(self, param):
        if __name__ == "__main__":
            print param
        src = '/home/ubuntu/private/test.blob'
        dest = '149.165.149.3:/home/ubuntu/waggleData/blobs/'
        self._blob_transfer(src, dest)
        return 0

    def _send(self, msg):
        """ 
        ========= DO NOT use this function in your code directly!!! ==========
        This is a low level function, you should only use msg_send(msg) or multi_send(msgArray)
        """
        localClock = int(round(1000*1000*time.time()))
        #strToSend = getLanIP() + self.delimiter + dataName + self.delimiter + dataType + self.delimiter + DataValue + self.delimiter + str(localClock)
        self.channel.basic_publish(
            exchange = self.RMQExchange, routing_key = self.RMQRoutingKey, body = msg
            )
        if __name__ == "__main__":
            print " [x] Msg sent: " + msg 
    
    def multi_send(self, msgArray):
        """ Same as msg_send, but accept an array of msg and send.
            Parameters
            ----------
            msgArray: array of str
                Messages that will be sent
            Please see example at the bottom for use.
            Example:
                msg1 = msg_gen(...)
                msg2 = msg_gen(...)
                msg3 = msg_gen(...)
                msgArray = [msg1, msg2, msg3]
                multi_send(msgArray)
        """
        actualSentMsg = '2' + self.delimiter0 + arrayToStr(msgArray, 1)
        ## 1 for msg_send while 2 for multi_send()
        self._send(actualSentMsg)

    def msg_send(self, msg):
        """ Send a string to remote RMQ server, msg has to be a string
            Please see example at the bottom for use.
        """
        actualSentMsg = '1' + self.delimiter0 + msg
        # 1 for msg_send while 2 for multi_send()
        self._send(msg)

    @staticmethod
    def msg_gen(instID, sensorID, readTime, paramName, paramType, paramVal, paramUnit, paramNote):
        """
        Depreciated: use waggle.common.messaging : msg_gen instead
        """
        return msg_gen(instID, sensorID, readTime, paramName, paramType, paramVal, paramUnit, paramNote)

    def _blob_transfer(self, blobSrc, blobDest):# not done, not tested
        """ 
            Parameters used as same as in blob_send.
        """
        global_ID = str(uuid.uuid1())# make a UUID based on the host ID and current time
        if __name__ == "__main__":
            print 'blobSrc = ' + blobSrc
            print 'blobDest = ' + blobDest
        cmd = 'scp ' + blobSrc + ' ubuntu@' + blobDest + global_ID
        if __name__ == "__main__":
            print 'cmd = ' + cmd
        out = runLinuxCMD(cmd)
        if __name__ == "__main__":
            print 'out = ' + out
        ret = [0, cmd, out]
        return ret #return a list of status
        pass

    def blob_send(self, blobSrc, blobDest, successMsg):# done, half tested
        # consider blob msg as a speical case of msg for msg_send()
        """ 
        Parameters
        ----------
            blobSrc: str 
                local file full path. eg: /home/bob/music/heyjude.mp3
            blobDest: str
                remote file full path 149.165.149.14:/export/permanent/waggle_datastore/BLOBSTORE/heyjude.mp3, but no username here.
            successMsg: is the msg object that will be stored in db if blob is successfully transferred. 
        """
        #TODO: test basic blob sending, make proper message to insert to cassandra db

        tag = ''
        ret = 0
        status = self._blob_transfer(blobSrc, blobDest)

        if 0 == status[0]: 
            tag = '3'
            msg = successMsg #3 for blob msg
            ret = 0
        else: # transfer fails
            tag = '-3'
            # Making failMsg
            
            #nameB = ['SourcePath','DestPath','File_UUID', 'Status']
            #typeB = ['s','s','s','s']
            #dataB = ['/home/ubuntu/private/test.blob','149.165.149.3:/home/ubuntu/waggleData/blobs/', 'N/A','Failed']
            #unitB = ['','','','']
            #noteB = ['','','','']

            rec = Record.msg_parse(tag + self.delimiter0 + successMsg)[0]
            #Use the same msg as successMsg, but use a fail tag to tell server.
            msg = msg_gen(rec.instID, rec.sensorID, rec.readTime, rec.paramName, rec.paramType, rec.paramVal, paramUnit, rec.paramNote)
            ret = -1
        actualSentMsg = tag + self.delimiter0 + msg #3 for blob msg
        self._send(actualSentMsg)
        return ret  

    def close(self):
        """ 
        Close connection. Call this after you finish use client to save server side resource.
        You need to recreate the DataClient object to send data if you called this, so put this at the end of your logic session.

        Note: you may get warning like this:
        WARNING:pika.adapters.base_connection:Unknown state on disconnect: 0
        This is due to a known pika bug, the warning is printed when connection.close() is called, but won't affect the behavior of the program.
        """
        self.connection.close()
   



#============================================================
if __name__ == "__main__":
    #Test case and example
    RMQ_ip = '149.165.149.8'
    RMQ_port = 5672
    RMQ_user = 'clients'
    RMQ_passwd = 'Ruza3que'
    RMQ_exchange = ''
    RMQ_routing_key = 'weather'
    dataClient = NodeDataClient(RMQ_ip, RMQ_port, RMQ_user, RMQ_passwd, RMQ_exchange, RMQ_routing_key)
   

    data_payload = DataPayload("inst_id", "sens_id", "time_read")
    for i in xrange(4):
        data_payload.add_item("name" + str(i), "s", "valu" + str(i),
                           "unit" + str(i), "note" + str(i))

    data_str = data_payload.encode()
    data_payload1 = DataPayload.decode(data_str)



    data_msg = Message()
    data_msg.append(data_payload)
    data_msg.append(data_payload)

    data_msg_str = data_msg.encode()
    #msg1 = Message.decode(msg_str)

    dataClient.msg_send(data_msg_str)
    
    
    #!! Registration Payload
    
    #######################################################
    #!! Registration Payload
'''
    reg_payload = RegistrationPayload(str(get_mac_addr()), "cpu_version", "hw_v", "sw_v")
    for j in xrange(3):
        reg_payload.add_sensor() # may take arguments later
        reg_payload.sensors[j].sensor_id = "sens_id"
        reg_payload.sensors[j].communication_direction = "0 (ping-only)"
        reg_payload.sensors[j].time_interval = 123
        reg_payload.sensors[j].time_interval_type = "settable"
        for i in xrange(5-j):
            reg_payload.sensors[j].add_field("name" + str(i), "s", "valu" + str(i),
                               "unit" + str(i))
    reg_msg = Message()
    reg_msg.append(reg_payload)
    print reg_msg.header.msg_type
    reg_msg.header.msg_type = 0
    dataClient.msg_send(reg_msg.encode())
''' 
 
    #dataClient._unitTest('testing: _blob_transfer')
    
    
"""    
    #Sample msg data for general data
    names = ['name1','name2','name3','name4']
    types = ['type1','type2','type3','type4']
    data = ['data1','data2','data3','data4']
    unit = ['unit1','unit2','unit3','unit4']
    note = ['note1','note2','note3','note4']
    
    msg1 = NodeDataClient.msg_gen('instance-124', 'sensor-456', str(time.time()), names, types, data, unit, note)
    time.sleep(2)
    msg2 = NodeDataClient.msg_gen('instance-125', 'sensor-456', str(time.time()), names, types, data, unit, note)
    msgArray = [msg1, msg2]
    
    dataClient.msg_send(msg1)
    dataClient.multi_send( msgArray)
    
    #Sample data for blob
    nameB = ['SourcePath','DestPath','File_UUID', 'Notes']
    typeB = ['s','s','s','s']
    dataB = ['/home/ubuntu/private/test.blob','149.165.149.3:/home/ubuntu/waggleData/blobs/', str(uuid.uuid1()),'Test blob_send()']
    unitB = ['','','','']
    noteB = ['note1','note2','note3','note4']
    
    blobSrc = '/home/ubuntu/private/test2.blob'
    blobDest = '149.165.149.3:/home/ubuntu/waggleData/blobs/'
    successMsg = NodeDataClient.msg_gen('instance-VM123', 'sensor-186', str(time.time()), nameB, typeB, dataB, unitB, noteB)
    #dataClient.blob_send(blobSrc, blobDest, successMsg)
    
    
    #dataClient.connection.close()
"""
