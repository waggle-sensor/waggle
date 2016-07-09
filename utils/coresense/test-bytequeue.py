import unittest
from bytequeue import bytequeue


class TestBuffer(unittest.TestCase):

    def test_empty(self):
        buffer = bytequeue(capacity=50)
        self.assertEqual(len(buffer), 0)

    def test_length(self):
        buffer = bytequeue(capacity=50)
        buffer.enqueue(0)
        self.assertEqual(len(buffer), 1)

    def test_index(self):
        buffer = bytequeue(capacity=50)

        buffer.enqueue(31)
        buffer.enqueue(45)
        buffer.enqueue(71)

        self.assertEqual(buffer[0], 31)
        self.assertEqual(buffer[1], 45)
        self.assertEqual(buffer[2], 71)
        self.assertEqual(buffer[0:3], bytearray([31, 45, 71]))

        buffer.dequeue()

        self.assertEqual(buffer[0], 45)
        self.assertEqual(buffer[1], 71)
        self.assertEqual(buffer[0:2], bytearray([45, 71]))

        buffer.dequeue()

        self.assertEqual(buffer[0], 71)
        self.assertEqual(buffer[0:1], bytearray([71]))

    def test_queue(self):
        buffer = bytequeue(capacity=50)

        for x in range(10):
            buffer.enqueue(x)

        for x in range(10):
            self.assertEqual(x, buffer.dequeue())

    def test_mixed(self):
        buffer = bytequeue(capacity=50)

        for x in range(10):
            buffer.enqueue(x)
            self.assertEqual(x, buffer.dequeue())


if __name__ == '__main__':
    unittest.main()
