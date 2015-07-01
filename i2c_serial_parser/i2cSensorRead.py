import serial
import time
Link_unavailable = True
PORT_DEV='/dev/ttyACM1'

sensor_list = ["Board MAC","TMP112","HTU21D","GP2Y1010AU0F","BMP180","PR103J2","TSL250RD","MMA8452Q","SPV1840LR5H-B","TSYS01","HMC5883L","HIH6130","APDS-9006-020","TSL260RD","TSL250RD","MLX75305","ML8511","D6T","MLX90614","TMP421","SPV1840LR5H-B","Total reducing gases","Ethanol (C2H5-OH)","Nitrogen Di-oxide (NO2)","Ozone (03)","Hydrogen Sulphide (H2S)","Total Oxidizing gases","Carbon Monoxide (C0)","Sulfur Dioxide (SO2)","Temperature and Humidity (Sensirion)","Atmospheric Pressure (Bosh)","Intel MAC"]


def calc_crc (data_byte,CRC_Value):
    CRC_Value = data_byte ^ CRC_Value
    for j in range(8):
        if (CRC_Value  & 0x01):
            CRC_Value  = (CRC_Value  >> 0x01) ^ 0x8C
        else:
            CRC_Value  =  CRC_Value  >> 0x01
    return CRC_Value


def format1 (input):
    byte1 = int(input[0])
    byte2 = int(input[1])
    value = (byte1 & 0x7F) + ((byte2 & 0x7F) * 0.01)
    if byte2 & 0x80 == 0x80:
        value = value * -1
    return value

def format2 (input):
    byte1 = int(input[0])
    byte2 = int(input[1])
    value = ((byte1 & 0x7F) << 8 )+ byte2
    return value

def format3 (input):
    return hex(int(input))

def format4 (input):
    byte1 = int(input[0])
    byte2 = int(input[1])
    value = ((byte1 & 0x3c) >> 2) + ((((byte1 & 0x03) << 8) + byte2) * 0.001)
    if byte1 & 0x40 == 0x40:
        value = value * -1
    return value

def format5 (input):
    return input

def format6 (input):
    byte1 = int(input[0])
    byte2 = int(input[1])
    byte3 = int(input[2])
    value = ((byte1 & 0x3F) << 16 ) + (byte2 << 8) + byte1
    if (byte1 & 0x40) == 0x40:
        value = value * -1
    return value

def formatNULL (input):
    return input

def parse_sensor (sensor_id,sensor_data):

    if sensor_id == '0':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        data = str(format3(sensor_data[-1]))+':'+str(format3(sensor_data[-2]))+ \
        ':'+str(format3(sensor_data[-3]))+':'+str(format3(sensor_data[2]))+ \
        ':'+str(format3(sensor_data[1]))+':'+str(format3(sensor_data[0]))
        print "Data:", data

    elif sensor_id == '1':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format1(sensor_data)

    elif sensor_id == '2':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format1(sensor_data[0:2]), format1(sensor_data[2:4])

    elif sensor_id == '3':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format2(sensor_data)

    elif sensor_id == '4':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format1(sensor_data[0:2]), format6(sensor_data[2:5])

    elif sensor_id == '5':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format2(sensor_data)

    elif sensor_id == '6':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format2(sensor_data)

    elif sensor_id == '7':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format1(sensor_data[0:2]), format1(sensor_data[2:4]),format1(sensor_data[4:6]),format1(sensor_data[6:8])

    elif sensor_id == '8':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format2(sensor_data)

    elif sensor_id == '9':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format2(sensor_data)

    elif sensor_id == '10':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format4(sensor_data[0:2]),format4(sensor_data[2:4]),format4(sensor_data[4:6])

    elif sensor_id == '11':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format1(sensor_data[0:2]), format1(sensor_data[2:4])

    elif sensor_id == '12':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format2(sensor_data)

    elif sensor_id == '13':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format2(sensor_data)

    elif sensor_id == '14':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format2(sensor_data)

    elif sensor_id == '15':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format2(sensor_data)

    elif sensor_id == '16':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format2(sensor_data)

    elif sensor_id == '17':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        data = ''
        for i in xrange(len(sensor_data)/2):
            data = data + str(format1(sensor_data[2*i:2*(i+1)])) + ' '
        print "Data:", data


    elif sensor_id == '18':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format1(sensor_data)

    elif sensor_id == '19':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format1(sensor_data)

    elif sensor_id == '20':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format2(sensor_data)

    elif sensor_id == '21':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format2(sensor_data)

    elif sensor_id == '22':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format2(sensor_data)

    elif sensor_id == '23':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format2(sensor_data)

    elif sensor_id == '24':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format2(sensor_data)

    elif sensor_id == '25':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format2(sensor_data)

    elif sensor_id == '26':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format2(sensor_data)

    elif sensor_id == '27':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format2(sensor_data)

    elif sensor_id == '28':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format2(sensor_data)

    elif sensor_id == '29':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format1(sensor_data[0:2]),format1(sensor_data[2:4])

    elif sensor_id == '30':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", format6(sensor_data)

    elif sensor_id == '31':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        data = str(format3(sensor_data[-1]))+':'+str(format3(sensor_data[-2]))+ \
        ':'+str(format3(sensor_data[-3]))+':'+str(format3(sensor_data[2]))+ \
        ':'+str(format3(sensor_data[1]))+':'+str(format3(sensor_data[0]))
        print "Data:", data

    elif sensor_id == '255':
        print "Sensor:", sensor_id,sensor_list[int(sensor_id)],'@',
        print "Data:", formatNULL(sensor_data)


while Link_unavailable:
    try:
        link = serial.Serial(PORT_DEV,115200)
        Link_unavailable = False
        link.flushInput()
        link.flushOutput()
    except:
        print "Waiting for device...",str(time.asctime())
        time.sleep(3)


while 1:
    data = link.readline()
    data_bytes = data.split(',')[:-1]
    try:
        if data_bytes[0x00] == '170':
            protocol = data_bytes[1]
            print "------------------------"
            if protocol == '0':
                print 'protocol version:', protocol,
                length_of_packet = int(data_bytes[0x02])
                print "Packet Length:",length_of_packet
                if len(data_bytes) > length_of_packet+4:
                    if data_bytes[length_of_packet+4] == '85':
                        CRC_Value = 0x00
                        #we will calculate the CRC with teh CRC byte included, and
                        #that should give us zero.
                        for current_byte in range(length_of_packet+1):
                            CRC_Value = calc_crc( int(data_bytes[current_byte+3]), CRC_Value)
                        if CRC_Value == 0:
                            print "====>Packet CRC correct."
                            consume_ptr = 0x03
                            while consume_ptr < length_of_packet:
                                This_id = data_bytes[consume_ptr]
                                This_id_msg_size_valid = int(data_bytes [consume_ptr+1])
                                This_id_msg_size = This_id_msg_size_valid & 0x7F
                                This_id_msg_valid = (This_id_msg_size_valid & 0x80) >> 7
                                This_id_msg = data_bytes [consume_ptr+2:consume_ptr+2+This_id_msg_size]
                                if (This_id_msg_valid == 1):
                                    parse_sensor (This_id, This_id_msg)
                                else:
                                    parse_sensor (This_id, This_id_msg)
                                    print "Invalid Message from sensor_id - ", This_id
                                consume_ptr = consume_ptr + 2 + This_id_msg_size

                        else:
                            print "Invalid CRC, not parsing packet.<===="
    except:
        pass
