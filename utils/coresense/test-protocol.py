from protocol import FramingProtocol
# from protocol import CoresenseProtocol
from protocol import create_packet
import unittest


class TestProtocol(FramingProtocol):

    def __init__(self):
        self.results = []

    def packet_received(self, sequence, version, data):
        self.results.append((sequence, version, data))


def process_dataset(dataset, start=0, end=None, fragmented=False):
    protocol = TestProtocol()
    protocol.connection_made()

    data = b''.join(create_packet(*entry) for entry in dataset)[start:end]

    if fragmented:
        for x in data:
            protocol.data_received(bytearray([x]))
    else:
        protocol.data_received(data)

    protocol.connection_lost()
    return protocol.results


class TestFramingProtocol(unittest.TestCase):

    def test_basic(self):
        data = bytearray([11, 82, 32, 9, 7])

        for version in range(16):
            for sequence in range(16):
                dataset = [(version, sequence, data)]
                results = process_dataset(dataset)
                self.assertEqual(dataset, results)

    def test_fragmented(self):
        data = bytearray([11, 82, 32, 9, 7])

        for version in range(16):
            for sequence in range(16):
                dataset = [(version, sequence, data)]
                results = process_dataset(dataset, fragmented=True)
                self.assertEqual(dataset, results)

    def test_empty(self):
        dataset = [(1, 3, bytearray([]))]
        results = process_dataset(dataset)
        self.assertEqual(dataset, results)

    def test_special_1(self):
        dataset = [(1, 3, bytearray([0xAA]))]
        results = process_dataset(dataset)
        self.assertEqual(dataset, results)

    def test_special_2(self):
        dataset = [(1, 3, bytearray([0x55]))]
        results = process_dataset(dataset)
        self.assertEqual(dataset, results)

    def test_invalid(self):
        dataset = [(1, 3, bytearray([0xAA, 0x55] * 5))]
        results = process_dataset(dataset, start=1)
        self.assertEqual([], results)

    def test_incomplete(self):
        dataset = [
            (1, 3, bytearray([1, 1, 1])),
            (5, 2, bytearray([2, 2])),
            (2, 3, bytearray([3])),
            (0, 6, bytearray([1, 8, 7])),
        ]

        results = process_dataset(dataset, start=3)
        self.assertEqual(dataset[1:], results)

        results = process_dataset(dataset, start=10)
        self.assertEqual(dataset[2:], results)

        results = process_dataset(dataset, end=-4)
        self.assertEqual(dataset[:-1], results)

        results = process_dataset(dataset, end=-11)
        self.assertEqual(dataset[:-2], results)


if __name__ == '__main__':
    unittest.main()
