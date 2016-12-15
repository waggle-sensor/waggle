import threading
import serial
import sys
import time
import struct

_preamble = 0xaa
_postScript = 0x55

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

    def _firmware_version(self, input):
        byte1 = input[0]
        byte2 = input[1]

        hw_maj_version = byte1 >> 5
        hw_min_version = (byte1 & 0x1C) >> 2

        fw_maj_version = ((byte1 & 0x03) << 2) | ((byte2 & 0xC0) >> 6)
        fw_min_version = byte2 & 0x3F

        if fw_min_version < 10:
            values = ((hw_maj_version * 10 + hw_min_version) * 10 + fw_maj_version) * 100 + fw_min_version
        else:
            values = ((hw_maj_version * 10 + hw_min_version) * 10 + fw_maj_version) * 10 + fw_min_version

        return values

    def run (self):
        print(time.asctime())
        #Checking if the port is still available for connection
        try:
            self.ser = serial.Serial(self.port, baudrate=115200, timeout=0)
        except:
            #port unavalable. Between Inotify spanning the thread and the current
            #read the port has magically disappeared.
            self.keepAlive = 0
            self.stop()

        print("> > >  usbSerial initiated on port"+str(self.port)+" @ "+str(time.asctime()))
        self.counter = 0

        try:
            self.ser.flushInput()
            self.ser.flushOutput()
        except:
            self.stop()

        current_time = time.time()
        timeout = current_time + 30 # wait 30 sec
        print("We are intentionally waiting %d sec to allow the sensor board initiated" % 30)

        while self.keepAlive:
            current_time = time.time()
            time.sleep(self.repeatInt)
            streamData = ''
            try:
                self.counter = self.counter + 1
                if self.ser.inWaiting() > 0:
                    streamData = self.ser.read(self.ser.inWaiting())
                    self.counter = 0
            except:
                print("Serial port connection lost.")
                self.stop()

            # drop data while waiting
            if timeout > current_time:
                continue

            if streamData != '':
                self.marshalData(streamData)

            if (self.counter > 100000 or self.packetmismatch > 10) and (self.CoreSenseConf):
                print("not blade - error - " + str(self.counter) + " and " + str(self.packetmismatch))
                self.stop()

        print("< < <  usbSerial exit - port"+str(self.port)+" @ "+str(time.asctime()))
        print("")


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

            try:
                #lock header
                del self.data[:self.data.index(_preamble)]
                _preambleLoc = 0
                bufferLength = len(self.data)
            except Exception as e:
                #no header found, we ended up purging the data
                del self.data[:bufferLength]
                break

            if (len(self.data) < 4):
                #not enough data for a legal packet, we have to wait...
                break
            else:
                if ((self.data[_preambleLoc+_protVerFieldDelta]) & 0x0f) != 0:

                    #we have a packet of version we do not understand - either wrong version or
                    #we have a wrong byte as the header. We will delete a byte and try header lock again.
                    del self.data[0]

                else:
                    _msg_seq_num = (self.data[_preambleLoc+_protVerFieldDelta] & 0xf0) >> 4

                    #it is protocol version 0, and we can parse that data, using this script.

                    _postscriptLoc = self.data[_preambleLoc+_datLenFieldDelta] + _msgPSDelta + _datLenFieldDelta
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
                                if self.data[_postscriptLoc] != _postScript:
                                    #we probably have not locked to the header, consume and retry locking to header
                                    del self.data[0]
                                else:
                                    #we may have a valid packet
                                    _packetCRC = 0
                                    packetmismatch = 0

                                    for i in range(_preambleLoc + _datLenFieldDelta + 0x01, _postscriptLoc):
                                        #print(hex(ord(self.data[i])),)
                                        _packetCRC = self.data[i] ^ _packetCRC
                                        for j in range(8):
                                            if (_packetCRC & 0x01):
                                                _packetCRC = (_packetCRC >> 0x01) ^ 0x8C
                                            else:
                                                _packetCRC =  _packetCRC >> 0x01
                                    print('')
                                    if _packetCRC != 0x00:
                                        #bad packet or we probably have not locked to the header, consume and retry locking to header
                                        #ideally we should be able to throw the whole packet out, but purging just a byte for avoiding corner cases.
                                        del self.data[0]
                                    else:
                                        # print(self.data, ord(self.data[_postscriptLoc]))
                                        # print('-------------')
                                        print(time.asctime(), _msg_seq_num, _postscriptLoc)
                
                                        extractedData = self.data[_preambleLoc+3:_postscriptLoc-1]
                                        consume_ptr = 0x00
                                        self.CoreSenseConf = 0

                                        del self.data[:self.data.index(_postScript)+1]

                                        # print(":".join("{:02x}".format(c) for c in extractedData))

                                        sensors = {'light':False, 'chem':False, 'met':False, 'ver':'', 'firmware_check':False}

                                        while consume_ptr < len(extractedData):

                                            try:
                                                This_id = str(extractedData[consume_ptr])
                                                This_id_msg_size_valid = extractedData [consume_ptr+1]
                                                This_id_msg_size = This_id_msg_size_valid & 0x7F
                                                #print(This_id_msg_size)
                                                This_id_msg_valid = (This_id_msg_size_valid & 0x80) >> 7
                                                This_id_msg = extractedData[consume_ptr+2:consume_ptr+2+This_id_msg_size]
                                                
                                            except Exception as e:
                                                print("ERROR!!!!")
                                                print(str(e))
                                                print("consume_ptr: ", consume_ptr, " len(extractedData): ", len(extractedData))
                                                pass
                                            
                                            consume_ptr = consume_ptr + 2 + This_id_msg_size
                                            if (This_id_msg_valid == 1):

                                                if int(This_id) >= 0 and int(This_id) <= 9:
                                                    if sensors['met'] == True:
                                                        continue
                                                    sensors['met'] = True

                                                elif int(This_id) >= 10 and int(This_id) <= 20:
                                                    if sensors['light'] == True:
                                                        continue
                                                    sensors['light'] = True

                                                elif int(This_id) >= 21 and int(This_id) <= 39:
                                                    if sensors['chem'] == True:
                                                        continue
                                                    sensors['chem'] = True
                                                elif int(This_id) == 253:
                                                    hw_sw_version = self._firmware_version(This_id_msg[0:2])
                                                    hw_ver = (hw_sw_version / 1000) / 10.
                                                    fw_ver = (hw_sw_version - int(hw_ver*10)*1000) / 100.

                                                    sensors['ver'] = "%.1f %.2f" % (hw_ver, fw_ver)
                                            else:
                                                pass

                                        if sensors['ver'] == '':
                                            print("Test failed: Firmware version does not exist")
                                        else:
                                            chem = sensors['ver'][-1]
                                            if (chem == '2' and sensors['chem'] == False) or \
                                                (chem == '1' and sensors['chem'] == True):
                                                sensors['firmware_check'] = False
                                            elif (chem == '2' and sensors['chem'] == True) or \
                                                (chem == '1' and sensors['chem'] == False):
                                                sensors['firmware_check'] = True
                                            else: 
                                                print("Test failed: Firmware version does not exist")
                                                
                                        print("Met %r, light %r, chem %r, ver %s, firmware_check %r" % (sensors['met'], sensors['light'], sensors['chem'], sensors['ver'], sensors['firmware_check']))
                            except:
                                print("ERRor")
                                print("buffer len", bufferLength)
                                print("data len", len(self.data))
                                print("_postscriptLoc", _postscriptLoc)
                                del self.data[0]
                                pass
