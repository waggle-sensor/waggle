from protocol import CoresenseProtocol
from protocol import create_packet
from protocol import create_packet_from_subpackets
import unittest


class TestProtocol(CoresenseProtocol):

    def __init__(self):
        self.results = []

    def subpacket_received(self, sensor, valid, data):
        self.results.append((sensor, valid, data))


def process_subpacket_data(sequence, version, subpackets):
    data = create_packet_from_subpackets(sequence, version, subpackets)
    protocol = TestProtocol()
    protocol.connection_made()
    protocol.data_received(data)
    protocol.connection_lost()
    return protocol.results


class TestCoresenseProtocol(unittest.TestCase):

    def test_empty(self):
        results = process_subpacket_data(0, 0, [])
        self.assertEqual([], results)

    def test_basic(self):
        subpackets = [
            (0x00, True, bytearray([1, 1, 1])),
            (0x01, True, bytearray([2, 2])),
            (0x03, True, bytearray([4, 3])),
        ]

        results = process_subpacket_data(0, 0, subpackets)
        self.assertEqual(subpackets, results)

    def test_broken(self):
        protocol = TestProtocol()
        protocol.connection_made()

        data = create_packet(0, 0, bytearray([0, 10, 1, 2, 3]))
        self.assertRaises(IndexError, protocol.data_received, data)

        protocol.connection_lost()

        self.assertEqual(len(protocol.results), 0)

    def test_broken_tail(self):
        protocol = TestProtocol()
        protocol.connection_made()

        data = create_packet(3, 5, bytearray([0x00, 1, 1, 0x01, 3, 7, 8]))
        self.assertRaises(IndexError, protocol.data_received, data)

        protocol.connection_lost()

        self.assertEqual(len(protocol.results), 1)


if __name__ == '__main__':
    unittest.main()
