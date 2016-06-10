from protocol import FramingProtocol
# from protocol import CoresenseProtocol
from protocol import create_packet
from random import randint
import unittest


def test_basic_decode(testcase, testsequence, testversion, testdata):

    class FramingTestProtocol(FramingProtocol):

        def packet_received(self, sequence, version, data):
            testcase.assertEqual(sequence, testsequence)
            testcase.assertEqual(version, testversion)
            testcase.assertEqual(data, testdata)

    packet = create_packet(testsequence, testversion, testdata)

    protocol = FramingTestProtocol()
    protocol.connection_made()
    protocol.data_received(packet)
    protocol.connection_lost()


def test_broken_packet(testcase, testsequence, testversion, testdata, skip):

    class FramingTestProtocol(FramingProtocol):

        def __init__(self):
            self.got_broken = False

        def invalid_packet(self):
            self.got_broken = True

        def packet_received(self, sequence, version, data):
            testcase.assertEqual(sequence, testsequence)
            testcase.assertEqual(version, testversion)
            testcase.assertEqual(data, testdata)
            testcase.assertTrue(self.got_broken)

    packet = create_packet(testsequence, testversion, testdata)

    protocol = FramingTestProtocol()
    protocol.connection_made()
    protocol.data_received(packet[skip:])
    protocol.data_received(packet)
    protocol.connection_lost()


class TestProtocol(unittest.TestCase):

    def test_basic(self):
        for version in range(16):
            for sequence in range(16):
                data = bytearray([1, 2, 3])
                test_basic_decode(self, version, sequence, data)

    def test_broken(self):
        data = bytearray([0xAA] * 10) + bytearray(range(1, 20))
        test_broken_packet(self, 2, 7, data, 3)

        for version in range(16):
            for sequence in range(16):
                for skip in range(1, 7):
                    data = bytearray(range(1, 20))
                    test_broken_packet(self, version, sequence, data, skip)

    def test_empty(self):
        test_basic_decode(self, 1, 3, bytearray([]))

    def test_special_1(self):
        test_basic_decode(self, 1, 3, bytearray([0xAA]))

    def test_special_2(self):
        test_basic_decode(self, 1, 3, bytearray([0x55]))

    def test_random(self):
        for i in range(10000):
            sequence = randint(0, 15)
            version = randint(0, 15)
            size = randint(0, 240)
            data = bytearray([randint(0, 255) for _ in range(size)])
            test_basic_decode(self, sequence, version, data)


if __name__ == '__main__':
    unittest.main()
