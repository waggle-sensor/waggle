from protocol import CoresenseProtocol
from serial import Serial
from format import unpack
import sys


class CoresenseIDProtocol(CoresenseProtocol):

    def subpacket_received(self, sensor, valid, data):
        if sensor == 0x00:
            print('airsense id:', unpack('3', data)[0])
        elif sensor == 0x20:
            print('chemsense id:', unpack('3', data)[0])


serial = Serial(sys.argv[1], 115200, timeout=10)

protocol = CoresenseIDProtocol()
protocol.connection_made()

while True:
    protocol.data_received(serial.read())

protocol.connection_lost()
