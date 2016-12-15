# -*- coding: utf-8 -*-
import serial
import time

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


def firmware_version(input):
    byte1 = ord(input[0])
    byte2 = ord(input[1])

    hw_maj_version = byte1 >> 5
    hw_min_version = (byte1 & 0x1C) >> 2

    fw_maj_version = ((byte1 & 0x03) << 2) | ((byte2 & 0xC0) >> 6)
    fw_min_version = byte2 & 0x3F

    if fw_min_version < 10:
        values = ((hw_maj_version * 10 + hw_min_version) * 10 + fw_maj_version) * 100 + fw_min_version
    else:
        values = ((hw_maj_version * 10 + hw_min_version) * 10 + fw_maj_version) * 10 + fw_min_version

    return values

def build_info_time(input):
    byte1 = ord(input[0])
    byte2 = ord(input[1])
    byte3 = ord(input[2])
    byte4 = ord(input[3])

    value = byte1 << 24 | byte2 << 16 | byte3 << 8 | byte4

    return value

def parse_sensor (sensor_id,sensor_data):
#"Board MAC" "Board MAC"
    if sensor_id == '0':
        print "Lightsense UID :",
        data = ''
        for i in range(len(sensor_data)):
            data = data + str(format3(sensor_data[i]))
        print  data
        
        print "Metsense UID :",
        data = ''
        for i in range(len(sensor_data)):
            data = data + str(format3(sensor_data[i]))
        print  data

#firmware version
    elif sensor_id == "253":
        hw_sw_version = firmware_version(sensor_data[0:2])
        hw_ver = (hw_sw_version / 1000) / 10.
        fw_ver = (hw_sw_version - hw_ver * 10000) / 100.

        build_time = build_info_time(sensor_data[2:6])
        build_git = '{0:02x}'.format(format1(sensor_data[6:8]))

        print "Metsense hardware version:", hw_ver
        print "Lightsense hardware version:", hw_ver
        print "Coresense firmware version:", fw_ver
        print "Coresense build time:", build_time
        print "Coresense git build:", build_git
        print ""

#alpha firmware
    elif sensor_id == '41':
        print "Sensor:", sensor_id, sensor_list[int(sensor_id)], '@ ',
        print ord(sensor_data[0]), ord(sensor_data[1])

#alpha configuration
    elif sensor_id == '42':
        print "Sensor:", sensor_id, sensor_list[int(sensor_id)], '@ '
        alpha_config = sensor_data
    elif sensor_id == '43':
        alpha_config.extend(sensor_data)
    elif sensor_id == '44':
        alpha_config.extend(sensor_data)
    elif sensor_id == '45':
        alpha_config.extend(sensor_data)
        print alpha_config
                
#"Intel MAC" "Intel MAC"
    elif sensor_id == '32': # sensor id 0x20
        print "Chemsense UID :",
        data = ''
        for i in range(len(sensor_data)):
            data = data + str(format3(sensor_data[i]))
        print  data


def marshalData(_dataNew):
    data.extend(_dataNew)
    bufferLength = len(data)
    while keepAlive:

        try:
            #lock header
            del data[:data.index(_preamble)]
            _preambleLoc = 0
            bufferLength = len(data)
        except:
            #no header found, we ended up purging the data
            del data[:bufferLength]
            break

        if (len(data) < 4):
            #not enough data for a legal packet, we have to wait...
            break
        else:
            if ((ord(data[_preambleLoc+_protVerFieldDelta]) & 0x0f) <> 0):

                #we have a packet of version we do not understand - either wrong version or
                #we have a wrong byte as the header. We will delete a byte and try header lock again.
                del data[0]

            else:
                _msg_seq_num = (ord(data[_preambleLoc+_protVerFieldDelta]) & 0xf0) >> 4

                #it is protocol version 0, and we can parse that data, using this script.

                _postscriptLoc = ord(data[_preambleLoc+_datLenFieldDelta]) + _msgPSDelta + _datLenFieldDelta
                if (_postscriptLoc > _maxPacketSize):
                    #the packet size if huge, it is unlikely that we have cuaght the header, so consume a
                    #byte.
                    del data[0]

                else:
                    if (_postscriptLoc >= bufferLength):
                    #We do not have full packet in the buffer, cannot process.
                        break
                    else:
                        try:
                            if data[_postscriptLoc] <> _postScript:
                                #we probably have not locked to the header, consume and retry locking to header
                                del data[0]
                            else:
                                #we may have a valid packet
                                _packetCRC = 0
                                packetmismatch = 0

                                for i in range(_preambleLoc + _datLenFieldDelta + 0x01, _postscriptLoc):
                                    #print hex(ord(data[i])),
                                    _packetCRC = ord(data[i]) ^ _packetCRC
                                    for j in range(8):
                                        if (_packetCRC & 0x01):
                                            _packetCRC = (_packetCRC >> 0x01) ^ 0x8C
                                        else:
                                            _packetCRC =  _packetCRC >> 0x01
                                print ''
                                if _packetCRC <> 0x00:
                                    #bad packet or we probably have not locked to the header, consume and retry locking to header
                                    #ideally we should be able to throw the whole packet out, but purging just a byte for avoiding corner cases.
                                    del data[0]
                                else:
                                    #print data, ord(data[_postscriptLoc])
                                    print '-------------'
                                    print time.asctime(), _msg_seq_num, _postscriptLoc

                                    #extract the data bytes alone, exclude preamble, prot version, len, crc and postScript
                                    extractedData = data[_preambleLoc+3:_postscriptLoc-1]
                                    consume_ptr = 0x00
                                    CoreSenseConf = 0

                                    del data[:data.index(_postScript)+1]

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
                            print "data len", len(data)
                            print "_postscriptLoc", _postscriptLoc
                            del data[0]
                            pass

def main():
    try:
        ser = serial.Serial(port, baudrate=115200, timeout=1)
    except:
        print "Unable to find sensor boards at ", port
        exit()

    print "Found device, waiting for messages to extract ID info..."

    try:
        ser.flushInput()
        ser.flushOutput()
    except:
        exit()

    while 1:
        time.sleep(repeatInt)
        streamData = ''
        try:
            if ser.inWaiting() > 0:
                streamData = ser.read(ser.inWaiting())

        except:
            print "Serial port connection lost. Exiting."
            exit()

        if streamData <> '':
            marshalData(streamData)
        
        time.sleep(0.001)

    print "<<<<<<<<<<<<>>>>>>>>>>>>>"
    

if __name__ == "__main__":
    port = '/dev/waggle_coresense'
    lastSeq = 0
    currentSeq = 0
    repeatInt = 0.01
    data = []
    CoreSenseConf = 1
    dataLenBit = 0
    packetmismatch = 0
    keepAlive = 1
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
    print time.asctime()
    main()

