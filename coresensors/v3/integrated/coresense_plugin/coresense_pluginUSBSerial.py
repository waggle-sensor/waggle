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

__lenFmt1 = 2
__lenFmt2 = 2
__lenFmt3 = 6
__lenFmt4 = 3
__lenFmt5 = 3
__lenFmt6 = 2
__lenFmt7 = 4
__lenFmt8 = 3

#sensor_list = ["Board MAC","TMP112","HTU21D","GP2Y1010AU0F","BMP180","PR103J2","TSL250RD","MMA8452Q","SPV1840LR5H-B","TSYS01","HMC5883L","HIH6130","APDS-9006-020","TSL260RD","TSL250RD","MLX75305","ML8511","D6T","MLX90614","TMP421","SPV1840LR5H-B","Total reducing gases","Ethanol (C2H5-OH)","Nitrogen Di-oxide (NO2)","Ozone (03)","Hydrogen Sulphide (H2S)","Total Oxidizing gases","Carbon Monoxide (C0)","Sulfur Dioxide (SO2)","SHT25","LPS25H","Si1145","Intel MAC"]
sensor_list = ["Board MAC","TMP112","HTU21D","HIH4030","BMP180","PR103J2","TSL250RD","MMA8452Q","SPV1840LR5H-B","TSYS01","HMC5883L","HIH6130","APDS-9006-020","TSL260RD","TSL250RD","MLX75305","ML8511","D6T","MLX90614","TMP421","SPV1840LR5H-B","Total reducing gases","Ethanol (C2H5-OH)","Nitrogen Di-oxide (NO2)","Ozone (03)","Hydrogen Sulphide (H2S)","Total Oxidizing gases","Carbon Monoxide (C0)","Sulfur Dioxide (SO2)","SHT25","LPS25H","Si1145","Intel MAC","CO ADC temp","IAQ/IRR ADC temp","O3/NO2 ADC temp","SO2/H2S ADC temp","CO LMP temp","Accelerometer","Gyroscope", "alpha histo", "alpha firmware", "alpha conf a", "alpha conf b", "alpha conf c", "alpha conf d"]
#decoded_output = ['0' for x in range(16)]

#### alpha        
def lininterp(a, b, n):
    assert isinstance(n, int) and n > 1
    return tuple(a + i * (b - a) / (n - 1) for i in range(n))

bin_sizes = lininterp(0.38, 17.0, 16)
bin_units = {
    'bins': 'particle / second',
    'mtof': 'second',
    'sample flow rate': 'sample / second',
    'pm1': 'microgram / meter^3',
    'pm2.5': 'microgram / meter^3',
    'pm10': 'microgram / meter^3',
    'temperature': 'celcius',
    'pressure': 'pascal',
}


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
#"Board MAC" "Board MAC"
    if sensor_id == '0':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        data = ''
        for i in range(len(sensor_data)):
            data = data + str(format3(sensor_data[i]))
        print  data
        pass



def decode17(data):

    data = bytearray(data)

    bincounts = struct.unpack_from('<16B', data, offset=0)
    checksum = struct.unpack_from('<H', data, offset=48)[0]
    mtof = [x / 3 for x in struct.unpack_from('<4B', data, offset=32)]
    sample_flow_rate = struct.unpack_from('<I', data, offset=36)[0]
    pmvalues = struct.unpack_from('<fff', data, offset=50)
    pressure = struct.unpack_from('<I', data, offset=40)[0]
    temperature = pressure / 10.0


    values = {
        'bins': bincounts,
        'mtof': mtof,
        'sample flow rate': sample_flow_rate,
        'pm1': pmvalues[0],
        'pm2.5': pmvalues[1],
        'pm10': pmvalues[2],
        'error': sum(bincounts) & 0xFF != checksum,
    }

    if temperature > 200:
        values['pressure'] = pressure
    else:
        values['temperature'] = temperature

    return values

def alphasense_histo(raw_data):
    data = decode17(raw_data)

    for size, count in zip(bin_sizes, data['bins']):
        print('{: 3.4f} {:>6}'.format(size, count))
    print()

    for pm in ['pm1', 'pm2.5', 'pm10']:
        print('{} {}'.format(pm, data[pm]))
    print()

    print(data)
    print(repr(raw_data))


def parse_sensor (sensor_id,sensor_data):
#"Board MAC" "Board MAC"
    if sensor_id == '0':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        data = ''
        for i in range(len(sensor_data)):
            data = data + str(format3(sensor_data[i]))
        print  data
        pass

#alpha histo
    elif sensor_id == '40':
        print "Sensor:", sensor_id, sensor_list[int(sensor_id)], '@ ',
        alphasense_histo(sensor_data)

#alpha firmware
    elif sensor_id == '41':
        print "Sensor:", sensor_id, sensor_list[int(sensor_id)], '@ ',
        print ord(sensor_data[0]), ord(sensor_data[1])

#alpha configuration
    elif sensor_id == '42':
        print "Sensor:", sensor_id, sensor_list[int(sensor_id)], '@ ',
        alpha_config = sensor_data
    elif sensor_id == '43':
        alpha_config.extend(sensor_data)
    elif sensor_id == '44':
        alpha_config.extend(sensor_data)
    elif sensor_id == '45':
        alpha_config.extend(sensor_data)
        print alpha_config
        
        


#"TMP112" "TMP112"
    elif sensor_id == '1':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format6(sensor_data)
#"HTU21D" "HTU21D"
    elif sensor_id == '2':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format6(sensor_data[0:0+__lenFmt6]), format6(sensor_data[0+__lenFmt6:0+__lenFmt6+__lenFmt6])
#"GP2Y1010AU0F" has been chaned into "HIH4030": how does the date format changed?
    elif sensor_id == '3':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format5(sensor_data)
#"BMP180" "BMP180"
    elif sensor_id == '4':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format6(sensor_data[0:0+__lenFmt6]), format5(sensor_data[0+__lenFmt6:0+__lenFmt6+__lenFmt5])
#"PR103J2" "PR103J2"
    elif sensor_id == '5':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format1(sensor_data)
#"TSL250RD" "TSL250RD"
    elif sensor_id == '6':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format1(sensor_data)
#"MMA8452Q" "MMA8452Q"
    elif sensor_id == '7':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format6(sensor_data[0:0+__lenFmt6]), format6(sensor_data[0+__lenFmt6:0+__lenFmt6*2]),format6(sensor_data[0+__lenFmt6*2:0+__lenFmt6*3]),format6(sensor_data[0+__lenFmt6*3:0+__lenFmt6*4])
#"SPV1840LR5H-B" "SPV1840LR5H-B"
    elif sensor_id == '8':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format1(sensor_data)
#"TSYS01" "TSYS01"
    elif sensor_id == '9':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format6(sensor_data)
#"HMC5883L" "HMC5883L"
    elif sensor_id == '10':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format8(sensor_data[0:2]),format8(sensor_data[2:4]),format8(sensor_data[4:6])
#"HIH6130" "HIH6130"
    elif sensor_id == '11':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format6(sensor_data[0:2]), format6(sensor_data[2:4])
#"APDS-9006-020" "APDS-9006-020"
    elif sensor_id == '12':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format1(sensor_data)
#"TSL260RD" "TSL260RD"
    elif sensor_id == '13':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format1(sensor_data)
#"TSL250RD" "TSL250RD"
    elif sensor_id == '14':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format1(sensor_data)
#"MLX75305" "MLX75305"
    elif sensor_id == '15':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format1(sensor_data)
#"ML8511" "ML8511"
    elif sensor_id == '16':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format1(sensor_data)
#"D6T" has been removed
    elif sensor_id == '17':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        data = ''
        for i in xrange(len(sensor_data)/2):
            data = data + str(format6(sensor_data[2*i:2*(i+1)])) + ' '
        print  data
#"MLX90614" "MLX90614"
    elif sensor_id == '18':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format6(sensor_data)
#"TMP421" "TMP421"
    elif sensor_id == '19':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format6(sensor_data)
#"SPV1840LR5H-B" has been removed
    #elif sensor_id == '20':
        #print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        #print  format1(sensor_data)
#"Total reducing gases" "Total reducing gases"
    elif sensor_id == '21':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print str(format5(sensor_data))
#"Ethanol (C2H5-OH)" has been removed
    #elif sensor_id == '22':
        #print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        #print str(format5(sensor_data))
#"Nitrogen Di-oxide (NO2)" "Nitrogen Di-oxide (NO2)"
    elif sensor_id == '23':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  str(format5(sensor_data))
#"Ozone (03)" "Ozone (03)"
    elif sensor_id == '24':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  str(format5(sensor_data))
#"Hydrogen Sulphide (H2S)" "Hydrogen Sulphide (H2S)"
    elif sensor_id == '25': #sensor id 0x19
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  str(format5(sensor_data))
#"Total Oxidizing gases" "Total Oxidizing gases"
    elif sensor_id == '26':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  str(format5(sensor_data))
#"Carbon Monoxide (C0)" "Carbon Monoxide (C0)"
    elif sensor_id == '27':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  str(format5(sensor_data))
#"Sulfur Dioxide (SO2)" "Sulfur Dioxide (SO2)"
    elif sensor_id == '28':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  str(format5(sensor_data))
#"SHT25" "SHT25"
    elif sensor_id == '29':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format2(sensor_data[0:2]),format2(sensor_data[2:4])
#"LPS25H" "LPS25H"
    elif sensor_id == '30':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format2(sensor_data[0:2]),format4(sensor_data[2:5])
#"Si1145" "Si1145"
    elif sensor_id == '31':
        print "Sensor:", sensor_id, sensor_list[int(sensor_id)],'@ ',
        print  hex(format1(sensor_data[0:2])),hex(format2(sensor_data[2:4])),hex(format2(sensor_data[4:6]))
#"Intel MAC" "Intel MAC"
    elif sensor_id == '32': # sensor id 0x20
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        data = ''
        for i in range(len(sensor_data)):
            data = data + str(format3(sensor_data[i]))
        print  data
#"CO ADC temp"
    elif sensor_id == '33':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format2(sensor_data)
#"IAQ/IRR ADC temp"
    elif sensor_id == '34':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format2(sensor_data)
#"O3/NO2 ADC temp"
    elif sensor_id == '35':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format2(sensor_data)
#"SO2/H2S ADC temp"
    elif sensor_id == '36':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format2(sensor_data)
#"CO LMP temp"
    elif sensor_id == '37':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format2(sensor_data)
#"Accelerometer"
    elif sensor_id == '38':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format2(sensor_data[0:2]),format2(sensor_data[2:4]),format2(sensor_data[4:6]),format4(sensor_data[6:9])
#"Gyroscope"
    elif sensor_id == '39':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@ ',
        print  format2(sensor_data[0:2]),format2(sensor_data[2:4]),format2(sensor_data[4:6]),format4(sensor_data[6:9])



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

        self.failCount = 0
        self.file = open('failed.txt', 'w+')
        self.cumulativeCount = 0
        self.failBuffer = Queue.Queue()

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
                                        print self.data
                                        print '-------------'
                                        print time.asctime(), _msg_seq_num, _postscriptLoc
                                        
                                        # SH put data into buffer to store into a file
                                        try:
                                            self.failBuffer.put(self.data[0:_postscriptLoc])
                                            if self.failBuffer.qsize() > 20:
                                                if self.failCount > 0:
                                                    self.file.write(self.failBuffer.get())
                                                    self.file.write("\r\n")
                                                    self.failCount = self.failCount - 1
                                                else:
                                                    self.failBuffer.get()
                                        except:
                                            print "Error while writing file"
                                            print "failcount was ", self.failCount
                                            pass

                                        #extract the data bytes alone, exclude preamble, prot version, len, crc and postScript
                                        extractedData = self.data[_preambleLoc+3:_postscriptLoc-1]
                                        consume_ptr = 0x00
                                        self.CoreSenseConf = 0

                                        del self.data[:self.data.index(_postScript)+1]

                                        #print ":".join("{:02x}".format(ord(c)) for c in extractedData)

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
                                            
                                            if This_id == '16':
                                                if format1(This_id_msg) == 0xffff:
                                                    # ERROR FOUND~!!!!!!!!!!!!!!!!!!!
                                                    self.failCount = 20
                                                    self.cumulativeCount = self.cumulativeCount + 1
                                                    if self.cumulativeCount > 50:
                                                        # I do not want to see any more.... Get me out of here!
                                                        self.stop()
                                                        break



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
                            except:
                                print "ERRor"
                                print "buffer len", bufferLength
                                print "data len", len(self.data)
                                print "_postscriptLoc", _postscriptLoc
                                del self.data[0]
                                pass
