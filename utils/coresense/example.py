from protocol import CoresenseProtocol
from protocol import create_packet_from_subpackets


class CoresensePluginProtocol(CoresenseProtocol):

    def packet_start(self, sequence, version):
        print('# packet')
        print('sequence:', sequence)
        print('version:', version)
        print()

    def packet_end(self):
        print('>>>')
        print()

    def subpacket_received(self, sensor, valid, data):
        print('## subpacket')
        print('sensor:', sensor)
        print('valid:', valid)
        print('data:', list(data))
        print()


protocol = CoresensePluginProtocol()

packet = create_packet_from_subpackets(0, 1, [
    (12, True, bytearray([1, 2, 3])),
    (12, True, bytearray([6, 5, 4])),
])

protocol.connection_made()

# this is where you can feed data into the protocol as you receive it.
protocol.data_received(packet)

# you can build a packet up incrementally by calling this multiple times.
protocol.data_received(packet[:3])
protocol.data_received(packet[3:])

# this
protocol.connection_lost()
