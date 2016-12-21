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
_maxPacketSize = 256

__lenFmt1 = 2
__lenFmt2 = 2
__lenFmt3 = 6
__lenFmt4 = 3
__lenFmt5 = 3
__lenFmt6 = 2
__lenFmt7 = 4
__lenFmt8 = 3

sensor_list = ["Board MAC","TMP112","HTU21D","GP2Y1010AU0F","BMP180","PR103J2","TSL250RD","MMA8452Q","SPV1840LR5H-B","TSYS01","HMC5883L","HIH6130","APDS-9006-020","TSL260RD","TSL250RD","MLX75305","ML8511","D6T","MLX90614","TMP421","SPV1840LR5H-B","Total reducing gases","Ethanol (C2H5-OH)","Nitrogen Di-oxide (NO2)","Ozone (03)","Hydrogen Sulphide (H2S)","Total Oxidizing gases","Carbon Monoxide (C0)","Sulfur Dioxide (SO2)","SHT25","LPS25H","Si1145","Intel MAC"]

#decoded_output = ['0' for x in range(16)]

def format1 (input):
    #F1 - unsigned int_16 output, {0-0xffff} - Byte1 Byte2 (16 bit number)
    byte1 = ord(input[0])
    byte2 = ord(input[1])
    value = (byte1 << 8) | byte2
    return value


def format2 (input):
    #F2 - int_16 output , +-{0-0x7fff} - 1S|7Bits Byte2
    byte1 = ord(input[0])
    byte2 = ord(input[1])
    value = ((byte1 & 0x7F) << 8 ) | byte2
    if byte1 & 0x80 == 0x80:
        value = value * -1
    return value

def format3 (input):
    #F3 - hex string, {0-0xffffffffffff} - Byte1 Byte2 Byte3 Byte4 Byte5 Byte6
    return str(hex(ord(input)))[2:]

def format4 (input):
    #F4 - unsigned long_24 input, {0-0xffffff} - Byte1 Byte2 Byte3
    byte1 = ord(input[0])
    byte2 = ord(input[1])
    byte3 = ord(input[2])
    value = (byte1 << 16) | (byte2 << 8) | (byte3)
    return value

def format5 (input):
    #F5 - long_24 input, +-{0-0x7fffff} - 1S|7Bits Byte2 Byte3
    byte1 = ord(input[0])
    byte2 = ord(input[1])
    byte3 = ord(input[2])
    value = ((byte1 & 0x7F) << 16) | (byte2 << 8) | (byte3)
    if byte1 & 0x80 == 0x80:
        value = value * -1
    return value

def format6 (input):
    #F6 - float input, +-{0-127}.{0-99} - 1S|7Bit_Int 0|7Bit_Frac{0-99}
    byte1 = ord(input[0])
    byte2 = ord(input[1])
    #have to be careful here, we do not want three decimal placed here.
    value = (byte1 & 0x7F) + (((byte2 & 0x7F) % 100) * 0.01)
    if (byte1 & 0x80) == 0x80:
        value = value * -1
    return value

def format7 (input):
    #F7 - byte input[4], {0-0xffffffff} - Byte1 Byte2 Byte3 Byte4
    byte1 = ord(input[0])
    byte2 = ord(input[1])
    byte3 = ord(input[0])
    byte4 = ord(input[1])
    value = [byte1,byte2,byte3,byte4]
    return value

def format8 (input):
    #F8 - float input, +-{0-31}.{0-999} - 1S|5Bit_Int|2MSBit_Frac  8LSBits_Frac
    byte1 = ord(input[0])
    byte2 = ord(input[1])
    value = ((byte1 & 0x7c) >> 2) + ( ( ((byte1 & 0x03) << 8) | byte2 ) * 0.001)
    if (byte1 & 0x80) == 0x80:
        value = value * -1
    return value

def parse_sensor (sensor_id,sensor_data):
    if sensor_id == '0':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        data = ''
        for i in range(len(sensor_data)):
            data = data + str(format3(sensor_data[i]))
        print  data
        pass

    elif sensor_id == '1':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format6(sensor_data)

    elif sensor_id == '2':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format6(sensor_data[0:0+__lenFmt6]), format6(sensor_data[0+__lenFmt6:0+__lenFmt6+__lenFmt6])

    elif sensor_id == '3':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format5(sensor_data)

    elif sensor_id == '4':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format6(sensor_data[0:0+__lenFmt6]), format5(sensor_data[0+__lenFmt6:0+__lenFmt6+__lenFmt5])

    elif sensor_id == '5':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format1(sensor_data)

    elif sensor_id == '6':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format1(sensor_data)

    elif sensor_id == '7':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format6(sensor_data[0:0+__lenFmt6]), format6(sensor_data[0+__lenFmt6:0+__lenFmt6*2]),format6(sensor_data[0+__lenFmt6*2:0+__lenFmt6*3]),format6(sensor_data[0+__lenFmt6*3:0+__lenFmt6*4])

    elif sensor_id == '8':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format1(sensor_data)

    elif sensor_id == '9':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format6(sensor_data)

    elif sensor_id == '10':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format8(sensor_data[0:2]),format8(sensor_data[2:4]),format8(sensor_data[4:6])

    elif sensor_id == '11':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format6(sensor_data[0:2]), format6(sensor_data[2:4])

    elif sensor_id == '12':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format1(sensor_data)

    elif sensor_id == '13':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format1(sensor_data)

    elif sensor_id == '14':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format1(sensor_data)

    elif sensor_id == '15':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format1(sensor_data)

    elif sensor_id == '16':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format1(sensor_data)

    elif sensor_id == '17':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        data = ''
        for i in xrange(len(sensor_data)/2):
            data = data + str(format6(sensor_data[2*i:2*(i+1)])) + ' '
        print  data

    elif sensor_id == '18':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format6(sensor_data)

    elif sensor_id == '19':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format6(sensor_data)

    elif sensor_id == '20':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format1(sensor_data)

    elif sensor_id == '21':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print str(format5(sensor_data))

    elif sensor_id == '22':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print str(format5(sensor_data))

    elif sensor_id == '23':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  str(format5(sensor_data))

    elif sensor_id == '24':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  str(format5(sensor_data))

    elif sensor_id == '25':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  str(format5(sensor_data))

    elif sensor_id == '26':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  str(format5(sensor_data))

    elif sensor_id == '27':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  str(format5(sensor_data))

    elif sensor_id == '28':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  str(format5(sensor_data))

    elif sensor_id == '29':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format2(sensor_data[0:2]),format2(sensor_data[2:4])

    elif sensor_id == '30':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format2(sensor_data[0:2]), format4(sensor_data[2:5])

    elif sensor_id == '31':
        print "Sensor:", sensor_id, sensor_list[int(sensor_id)],'@ ',
        print  format1(sensor_data)

    elif sensor_id == '32':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        data = ''
        for i in range(len(sensor_data)):
            data = data + str(format3(sensor_data[i]))
        print  data

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
            self.ser = serial.Serial(self.port,timeout=0)
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
                        if (_postscriptLoc > bufferLength+2):
                        #We do not have full packet in the buffer, cannot process.
                            break
                        else:
                            if self.data[_postscriptLoc] <> _postScript:
                                #we probably have not locked to the header, consume and retry locking to header
                                del self.data[0]
                            else:
                                #we may have a valid packet
                                _packetCRC = 0
                                packetmismatch = 0

                                for i in range(_preambleLoc + _datLenFieldDelta + 0x01, _postscriptLoc):
                                    print ord(self.data[i]),
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
                                    print '-------------'
                                    print time.asctime(), _msg_seq_num, _postscriptLoc
                                    #extract the data bytes alone, exclude preamble, prot version, len, crc and postScript
                                    extractedData = self.data[_preambleLoc+3:_postscriptLoc-1]
                                    consume_ptr = 0x00
                                    self.CoreSenseConf = 0

                                    del self.data[:self.data.index(_postScript)+1]

                                    while consume_ptr < len(extractedData):
                                        This_id = str(ord(extractedData[consume_ptr]))
                                        This_id_msg_size_valid = ord(extractedData [consume_ptr+1])
                                        This_id_msg_size = This_id_msg_size_valid & 0x7F
                                        This_id_msg_valid = (This_id_msg_size_valid & 0x80) >> 7
                                        This_id_msg = extractedData[consume_ptr+2:consume_ptr+2+This_id_msg_size]
                                        #print (int(This_id)), This_id_msg_valid, This_id_msg_size, This_id_msg
                                        consume_ptr = consume_ptr + 2 + This_id_msg_size
                                        if (This_id_msg_valid == 1):
                                            try:
                                                parse_sensor (This_id, This_id_msg)
                                                pass
                                            except:
                                                pass
                                        else:
                                            pass
