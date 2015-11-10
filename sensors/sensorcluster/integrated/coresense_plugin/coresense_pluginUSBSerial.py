# -*- coding: utf-8 -*-
import threading
import serial
import sys
import time

_preamble = '\xaa'
_postScript = '\x55'

_datLenFieldDelta = 0x02
_protVerFieldDelta = 0x01
_msgCRCFieldDelta = 0x01
_msgPSDelta = 0x02

class usbSerial ( threading.Thread ):
    def __init__ ( self,port):
        self.port = port
        threading.Thread.__init__ ( self )
        self.lastSeq = 0
        self.currentSeq = 0
        self.repeatInt = 0.001
        self.data = []
        self.CoreSenseConf = 1
        self.dataLenBit = 0
        self.packetmismatch = 0

    def run (self):
        print time.asctime()
        #Checking if the port is still available for connection
        try:
            self.ser = serial.Serial(self.port,timeout=0)
            #print "device attached @ " + str(self.ser)
            self.keepAlive = 1
        except:
            #port unavalable. Between Inotify spanning the thread and the current
            #read the port has magically disappeared.
            #print "unable to open serial port"
            self.stop()
        print "> > >  usbSerial initiated on port"+str(self.port)+" @ "+str(time.asctime())
        self.counter = 0
        try:
            self.ser.flushInput()
            self.ser.flushOutput()
        except:
            self.stop()

        #self.scObj = serviceClient(self.port, self.fromdevq,self.todevq)

        while self.keepAlive:
            time.sleep(self.repeatInt)
            try:
                self.counter = self.counter + 1
                if self.ser.inWaiting() > 0:
                    self.marshalData(self.ser.read(self.ser.inWaiting()))
                    self.counter = 0
            except:
                #print "serial port not responding"
                self.stop()

            if (self.counter > 100000 or self.packetmismatch > 10) and (self.CoreSenseConf):
                print "not blade - error - " + str(self.counter) + " and " + str(self.packetmismatch)
                self.stop()
        print "< < <  usbSerial exit - port"+str(self.port)+" @ "+str(time.asctime())
        print ""


    def stop (self):
        self.keepAlive = False
        try :
            self.ser.close()
        except:
            pass


    def marshalData(self,_dataNew):
        self.data.extend(_dataNew)
        #at this point you just need to extract the message, check for crc and acknowledge the
        #receipt.

        while self.keepAlive:

            try:
                del self.data[:self.data.index(_preamble)]
                _preambleLoc = 0
            except:
                break;

            #check protocol version
            if (ord(self.data[_preambleLoc+_protVerFieldDelta]) == 0):
                #it is protocol version 0, and we can parse that data, using this script.

                try :
                    _postscriptLoc = ord(self.data[_preambleLoc+_datLenFieldDelta]) + _msgPSDelta + _datLenFieldDelta
                    if self.data[_postscriptLoc] == _postScript:
                        #we may have a valid packet, go ahead and set bytes
                        _packetCRC = 0
                        packetmismatch = 0

                        for i in range(_preambleLoc + _datLenFieldDelta + 0x01, _postscriptLoc):
                            _packetCRC = ord(self.data[i]) ^ _packetCRC
                            for j in range(8):
                                if (_packetCRC & 0x01):
                                    _packetCRC = (_packetCRC >> 0x01) ^ 0x8C
                                else:
                                    _packetCRC =  _packetCRC >> 0x01

                        if _packetCRC == 0x00:

                            extractedData = self.data[_preambleLoc+1:_postscriptLoc]
                            print time.asctime(), extractedData

                            self.CoreSenseConf = 0

                            try:
                                pass
                                #self.fromdevq.put_nowait(extractedData)
                            except:
                                print "unable to put in buffer"
                        else:
                            print "CRC error.",

                    #bad packet, let us drop the packet
                    try:
                        del self.data[:self.data.index(_postScript)]
                    except:
                        pass

                    try:
                        del self.data[:self.data.index(_preamble)]
                    except:
                        pass

                except:
                    return

            else:
                # we either caught the wrong byte as preamble or have a packet with protocol version that
                # we do not know how to parse, so we will delete a byte and try and catch the preamble in
                #the next cycle
                try:
                        del self.data[1]
                except:
                    pass
                return


