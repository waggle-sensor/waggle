# -*- coding: utf-8 -*-
import threading
import serial
import sys
import time
from serial import Serial


class UnknownSensorError(Exception):

    def __init__(self, sensor_id):
        self.sensor_id = sensor_id

    def __str__(self):
        return 'Unknown sensor ID {}.'.format(self.sensor_id)


def crc8(data, start, end):
    remainder = 0

    for i in range(start, end):
        remainder ^= ord(data[i])
        for j in range(8):
            if remainder & 1 != 0:
                remainder = (remainder >> 1) ^ 0x8C
            else:
                remainder >>= 1

    return remainder


_preamble = '\xaa'
_postScript = '\x55'

_datLenFieldDelta = 0x02
_protVerFieldDelta = 0x01
_msgCRCFieldDelta = 0x01
_msgPSDelta = 0x02
_maxPacketSize = 256


def format1(input):
    """
    unsigned 16-bit integer
    """
    byte1 = ord(input[0])
    byte2 = ord(input[1])
    value = (byte1 << 8) | byte2
    return value

format1.length = 2


def format2(input):
    """
    signed 16-bit integer
    """
    byte1 = ord(input[0])
    byte2 = ord(input[1])
    value = ((byte1 & 0x7F) << 8) | byte2
    return value if byte1 & 0x80 == 0 else -value

format2.length = 2


def format3(input):
    """
    hex string
    """
    return str(hex(ord(input)))[2:]  # explain [2:]?

format3.length = 6


def format4(input):
    """
    unsigned 24-bit integer
    """
    byte1 = ord(input[0])
    byte2 = ord(input[1])
    byte3 = ord(input[2])
    value = (byte1 << 16) | (byte2 << 8) | (byte3)
    return value

format4.length = 3


def format5(input):
    """
    signed 24-bit integer
    """
    byte1 = ord(input[0])
    byte2 = ord(input[1])
    byte3 = ord(input[2])
    value = ((byte1 & 0x7F) << 16) | (byte2 << 8) | (byte3)
    return value if byte1 & 0x80 == 0 else -value

format5.length = 3


def format5str(input):
    return str(format5str)

format5str.length = format5.length


def format6(input):
    # F6 - float input, +-{0-127}.{0-99} - 1S|7Bit_Int 0|7Bit_Frac{0-99}
    byte1 = ord(input[0])
    byte2 = ord(input[1])
    # have to be careful here, we do not want three decimal placed here.
    value = (byte1 & 0x7F) + (((byte2 & 0x7F) % 100) * 0.01)
    if (byte1 & 0x80) == 0x80:
        value = value * -1
    return value

format6.length = 2


def format7(input):
    # F7 - byte input[4], {0-0xffffffff} - Byte1 Byte2 Byte3 Byte4
    byte1 = ord(input[0])
    byte2 = ord(input[1])
    byte3 = ord(input[0])
    byte4 = ord(input[1])
    return [byte1, byte2, byte3, byte4]

format7.length = 4


def format8(input):
    # F8 - float input, +-{0-31}.{0-999} - 1S|5Bit_Int|2MSBit_Frac 8LSBits_Frac
    byte1 = ord(input[0])
    byte2 = ord(input[1])
    value = ((byte1 & 0x7c) >> 2) + ((((byte1 & 0x03) << 8) | byte2) * 0.001)
    if byte1 & 0x80 != 0:
        value = value * -1
    return value

format8.length = 2


def string3(input):
    return ''.join([str(format3(byte)) for byte in input])

string3.length = -1


def string6(input):
    return ''.join([str(format6(byte)) for byte in input])

string6.length = -1


def sensor17(input):
    return string6(input[::2])

sensor17.length = -1


sensor_table = {
    0x00: ('Board MAC', [('MAC Address', string3)]),
    0x01: ('TMP112', [('Temperature', format6)]),
    0x02: ('HTU21D', [('Temperature', format6),
                      ('Humidity', format6)]),
    0x03: ('GP2Y1010AU0F', [('Dust', format5)]),
    0x04: ('BMP180', [('Temperature', format6),
                      ('Atm Pressure', format5)]),
    0x05: ('PR103J2', [('Light', format1)]),
    0x06: ('TSL250RD', [('Light', format1)]),
    0x07: ('MMA8452Q', [('Accel X', format6),
                        ('Accel Y', format6),
                        ('Accel Z', format6),
                        ('RMS', format6)]),
    0x08: ('SPV1840LR5H-B', [('Sound Pressure', format1)]),
    0x09: ('TSYS01', [('Temperature', format6)]),
    0x0A: ('HMC5883L', [('B Field X', format8),
                        ('B Field Y', format8),
                        ('B Field Z', format8)]),
    0x0B: ('HIH6130', [('Temperature', format6),
                       ('Humidity', format6)]),
    0x0C: ('APDS-9006-020', [('Light', format1)]),
    0x0D: ('TSL260RD', [('Light', format1)]),
    0x0E: ('TSL250RD', [('Light', format1)]),
    0x0F: ('MLX75305', [('Light', format1)]),
    0x10: ('ML8511', [('Light', format1)]),
    0x11: ('D6T', [('Temperatures', sensor17)]),
    0x12: ('MLX90614', [('Temperature', format6)]),
    0x13: ('TMP421', [('Temperature', format6)]),
    0x14: ('SPV1840LR5H-B', [('Sound Pressure', format1)]),
    0x15: ('Total reducing gases', [('Concentration', format5str)]),
    0x16: ('Ethanol (C2H5-OH)', [('Concentration', format5str)]),
    0x17: ('Nitrogen Di-oxide (NO2)', [('Concentration', format5str)]),
    0x18: ('Ozone (03)', [('Concentration', format5str)]),
    0x19: ('Hydrogen Sulphide (H2S)', [('Concentration', format5str)]),
    0x1A: ('Total Oxidizing gases', [('Concentration', format5str)]),
    0x1B: ('Carbon Monoxide (C0)', [('Concentration', format5str)]),
    0x1C: ('Sulfur Dioxide (SO2)', [('Concentration', format5str)]),
    0x1D: ('SHT25', [('Temperature', format2),
                     ('Humidity', format2)]),
    0x1E: ('LPS25H', [('???', format2),
                      ('???', format4)]),
    0x1F: ('Si1145', [('???', format1)]),
    0x20: ('Intel MAC', [('MAC Address', string3)]),
    0xFE: ('Sensor Health', [('Status', format7)]),
}


def sensor_format_blocks(formats):
    start = 0

    for _, fmt in formats:
        if fmt.length < 0:
            yield start, None
            break
        else:
            yield start, start + fmt.length
            start += fmt.length


def unpack_sensor_data(sensor_format, sensor_data):
    return [fmt(sensor_data[start:end])
            for (_, fmt), (start, end) in zip(sensor_format,
                                              sensor_format_blocks(sensor_format))]


def parse_sensor(sensor_id, sensor_data):
    if sensor_id not in sensor_table:
        raise UnknownSensorError(sensor_id=sensor_id)

    sensor_name, sensor_format = sensor_table[sensor_id]
    values = unpack_sensor_data(sensor_format, sensor_data)

    print '@ {} ({})'.format(sensor_name, sensor_id)

    for (name, _), value in zip(sensor_format, values):
        print '- {}: {}'.format(name, value)
    print


class usbSerial(threading.Thread):
    def __init__(self, port):
        self.port = port
        threading.Thread.__init__(self)
        self.lastSeq = 0
        self.currentSeq = 0
        self.repeatInt = 0.01
        self.data = []
        self.CoreSenseConf = 1
        self.dataLenBit = 0
        self.packetmismatch = 0
        self.keepAlive = 1

    def run(self):
        try:
            self.ser = serial.Serial(self.port, timeout=0)
        except:
            self.keepAlive = 0
            self.stop()

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

            if streamData != '':
                self.marshalData(streamData)

            if (self.counter > 100000 or self.packetmismatch > 10) and (self.CoreSenseConf):
                print "not blade - error - " + str(self.counter) + " and " + str(self.packetmismatch)
                self.stop()

    def stop(self):
        self.keepAlive = False
        try:
            self.ser.close()
        except:
            pass

    def marshalData(self, _dataNew):
        self.data.extend(_dataNew)
        bufferLength = len(self.data)
        while self.keepAlive:

            try:
                # lock header
                del self.data[:self.data.index(_preamble)]
                _preambleLoc = 0
                bufferLength = len(self.data)
            except:
                # no header found, we ended up purging the data
                del self.data[:bufferLength]
                break

            if (len(self.data) < 4):
                # not enough data for a legal packet, we have to wait...
                break
            else:
                if ((ord(self.data[_preambleLoc+_protVerFieldDelta]) & 0x0f) != 0):

                    # we have a packet of version we do not understand - either wrong version or
                    # we have a wrong byte as the header. We will delete a byte and try header lock again.
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
                        # We do not have full packet in the buffer, cannot process.
                            break
                        else:
                            if self.data[_postscriptLoc] != _postScript:
                                #we probably have not locked to the header, consume and retry locking to header
                                del self.data[0]
                            else:
                                # we may have a valid packet

                                _packetCRC = crc8(self.data, _preambleLoc + _datLenFieldDelta + 1, _postscriptLoc)
                                packetmismatch = 0

                                if _packetCRC != 0:
                                    # bad packet or we probably have not locked to the header, consume and retry locking to header
                                    # ideally we should be able to throw the whole packet out, but purging just a byte for avoiding corner cases.
                                    del self.data[0]

                                else:

                                    # print time.asctime(), _msg_seq_num, _postscriptLoc
                                    # extract the data bytes alone, exclude preamble, prot version, len, crc and postScript
                                    extractedData = self.data[_preambleLoc+3:_postscriptLoc-1]
                                    fullPaket = self.data[_preambleLoc:_postscriptLoc+1]
                                    # print fullPaket
                                    consume_ptr = 0x00
                                    self.CoreSenseConf = 0

                                    del self.data[:self.data.index(_postScript) + 1]

                                    print '-------------'

                                    while consume_ptr < len(extractedData):
                                        This_id = ord(extractedData[consume_ptr])
                                        This_id_msg_size_valid = ord(extractedData [consume_ptr+1])
                                        This_id_msg_size = This_id_msg_size_valid & 0x7F
                                        This_id_msg_valid = (This_id_msg_size_valid & 0x80) >> 7
                                        This_id_msg = extractedData[consume_ptr+2:consume_ptr+2+This_id_msg_size]

                                        consume_ptr = consume_ptr + 2 + This_id_msg_size

                                        if (This_id_msg_valid == 1):
                                            try:
                                                parse_sensor (This_id, This_id_msg)
                                                pass
                                            except Exception as e:
                                                print e
                                        else:
                                            pass


if __name__ == '__main__':
    reader = usbSerial('/dev/tty.usbmodem1421')
    reader.run()
