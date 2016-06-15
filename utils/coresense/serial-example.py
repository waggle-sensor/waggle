from protocol import CoresenseProtocol
from serial import Serial
import sys


def format_hex(x):
    return '{:02X}'.format(x)


class CoresensePluginProtocol(CoresenseProtocol):

    def packet_start(self, sequence, version):
        print('start packet')
        print('sequence:', sequence)
        print('version:', version)
        print()

    def packet_end(self):
        print('end packet')
        print()

    def subpacket_received(self, sensor, valid, data):
        print('start subpacket')
        print('sensor:', sensor)
        print('valid:', valid)
        print('data:', ' '.join(map(format_hex, data)))
        print('end subpacket')
        print()

    def invalid_packet(self):
        print('bad packet!')

    def invalid_subpacket(self):
        print('bad subpacket!')


if len(sys.argv) != 2:
    print('Usage: {} device'.format(sys.argv[0]))
    sys.exit(1)

serial = Serial(sys.argv[1], 115200)

protocol = CoresensePluginProtocol()
protocol.connection_made()

while True:
    protocol.data_received(serial.read())

protocol.connection_lost()
