# -*- coding: utf-8 -*-
import threading
import serial
import sys
import time
import Queue
import struct

_preamble = '\xaa'
_postScript = '\x55'

_datLenFieldDelta = 0x02
_protVerFieldDelta = 0x01
_msgCRCFieldDelta = 0x01
_msgPSDelta = 0x02
_maxPacketSize = 256


class usbSerial ( threading.Thread ):


    def __init__ ( self,port):
        self.port = port
        threading.Thread.__init__ ( self )
        self.lastSeq = 0
        self.currentSeq = 0
        self.repeatInt = 0.01
        self.data = []
        self.CoreSenseConf = 1
        self.dataLenBit = 0
        self.packetmismatch = 0
        self.keepAlive = 1

    def run (self):
        print time.asctime()
        #Checking if the port is still available for connection
        try:
            self.ser = serial.Serial(self.port, baudrate=115200, timeout=0)
        except:
            #port unavalable. Between Inotify spanning the thread and the current
            #read the port has magically disappeared.
            self.keepAlive = 0
            self.stop()

        print "> > >  usbSerial initiated on port"+str(self.port)+" @ "+str(time.asctime())
        self.counter = 0

        try:
            self.ser.flushInput()
            self.ser.flushOutput()
        except:
            self.stop()

        while self.keepAlive:
            time.sleep(self.repeatInt)
            streamData = ''
            try:
                self.counter = self.counter + 1
                if self.ser.inWaiting() > 0:
                    streamData = self.ser.read(self.ser.inWaiting())
                    self.counter = 0
            except:
                print "Serial port connection lost."
                self.stop()

            if streamData <> '':
                self.marshalData(streamData)

            if (self.counter > 100000 or self.packetmismatch > 10) and (self.CoreSenseConf):
                print "not blade - error - " + str(self.counter) + " and " + str(self.packetmismatch)
                self.stop()

        print "< < <  usbSerial exit - port"+str(self.port)+" @ "+str(time.asctime())
        print ""


    def stop (self):
        self.keepAlive = False
        try :
            self.ser.close()
            self.file.close()
        except:
            pass


    def marshalData(self,_dataNew):
        self.data.extend(_dataNew)
        bufferLength = len(self.data)
        while self.keepAlive:

            print(_dataNew)
            print("DATA_NEW")

            try:
                #lock header
                del self.data[:self.data.index(_preamble)]
                _preambleLoc = 0
                bufferLength = len(self.data)
            except:
                #no header found, we ended up purging the data
                del self.data[:bufferLength]
                break

            if (len(self.data) < 4):
                #not enough data for a legal packet, we have to wait...
                break
            else:
                if ((ord(self.data[_preambleLoc+_protVerFieldDelta]) & 0x0f) <> 0):

                    #we have a packet of version we do not understand - either wrong version or
                    #we have a wrong byte as the header. We will delete a byte and try header lock again.
                    del self.data[0]

                else:
                    _msg_seq_num = (ord(self.data[_preambleLoc+_protVerFieldDelta]) & 0xf0) >> 4

                    #it is protocol version 0, and we can parse that data, using this script.

                    _postscriptLoc = ord(self.data[_preambleLoc+_datLenFieldDelta]) + _msgPSDelta + _datLenFieldDelta
                    if (_postscriptLoc > _maxPacketSize):
                        #the packet size if huge, it is unlikely that we have cuaght the header, so consume a
                        #byte.
                        del self.data[0]

                    else:
                        if (_postscriptLoc >= bufferLength):
                        #We do not have full packet in the buffer, cannot process.
                            break
                        else:
                            try:
                                if self.data[_postscriptLoc] <> _postScript:
                                    #we probably have not locked to the header, consume and retry locking to header
                                    del self.data[0]
                                else:
                                    #we may have a valid packet
                                    _packetCRC = 0
                                    packetmismatch = 0

                                    for i in range(_preambleLoc + _datLenFieldDelta + 0x01, _postscriptLoc):
                                        #print hex(ord(self.data[i])),
                                        _packetCRC = ord(self.data[i]) ^ _packetCRC
                                        for j in range(8):
                                            if (_packetCRC & 0x01):
                                                _packetCRC = (_packetCRC >> 0x01) ^ 0x8C
                                            else:
                                                _packetCRC =  _packetCRC >> 0x01
                                    print ''
                                    if _packetCRC <> 0x00:
                                        #bad packet or we probably have not locked to the header, consume and retry locking to header
                                        #ideally we should be able to throw the whole packet out, but purging just a byte for avoiding corner cases.
                                        del self.data[0]
                                    else:
                                        # print self.data, ord(self.data[_postscriptLoc])
                                        # print '-------------'
                                        print time.asctime(), _msg_seq_num, _postscriptLoc
                
                                        extractedData = self.data[_preambleLoc+3:_postscriptLoc-1]
                                        consume_ptr = 0x00
                                        self.CoreSenseConf = 0

                                        del self.data[:self.data.index(_postScript)+1]

                                        #print ":".join("{:02x}".format(ord(c)) for c in extractedData)

                                        sensors = {'light':False, 'chem':False, 'met':False}

                                        while consume_ptr < len(extractedData):

                                            try:
                                                This_id = str(ord(extractedData[consume_ptr]))
                                                This_id_msg_size_valid = ord(extractedData [consume_ptr+1])
                                                This_id_msg_size = This_id_msg_size_valid & 0x7F
                                                #print This_id_msg_size
                                                This_id_msg_valid = (This_id_msg_size_valid & 0x80) >> 7
                                                This_id_msg = extractedData[consume_ptr+2:consume_ptr+2+This_id_msg_size]
                                                
                                            except Exception,e:
                                                print "ERROR!!!!"
                                                print str(e)
                                                print "consume_ptr: ", consume_ptr, " len(extractedData): ", len(extractedData)
                                                pass
                                            
                                            consume_ptr = consume_ptr + 2 + This_id_msg_size
                                            if (This_id_msg_valid == 1):

                                                if int(This_id) >= 0 and int(This_id) <= 9:
                                                    if sensors['met'] == True:
                                                        continue
                                                    sensors['met'] = True

                                                if int(This_id) >= 10 and int(This_id) <= 20:
                                                    if sensors['light'] == True:
                                                        continue
                                                    sensors['light'] = True

                                                if int(This_id) >= 21 and int(This_id) <= 39:
                                                    if sensors['chem'] == True:
                                                        continue
                                                    sensors['chem'] = True
                                            else:
                                                pass

                                        print("Met %r, light %r, chem %r" % (sensors['met'], sensors['light'], sensors['chem']))
                            except:
                                print "ERRor"
                                print "buffer len", bufferLength
                                print "data len", len(self.data)
                                print "_postscriptLoc", _postscriptLoc
                                del self.data[0]
                                pass
