from format import pack_unsigned_int, unpack_unsigned_int
from format import pack_signed_int, unpack_signed_int
from format import unpack, pack
from format import pack_macaddr_into, unpack_macaddr_from
from random import randint
import unittest


class TestFormat(unittest.TestCase):

    # should also test against known values!
    def test_unsigned(self):
        for length in range(1, 4):
            maxint = 2 ** (8 * length) - 1
            for _ in range(10000):
                value = randint(0,  maxint)

                self.assertEqual(
                    unpack_unsigned_int(pack_unsigned_int(value, length)),
                    value)

    def test_signed(self):
        for length in range(1, 4):
            maxint = 2 ** (8 * length - 1) - 1
            for _ in range(10000):
                value = randint(-maxint,  maxint)
                self.assertEqual(
                    unpack_signed_int(pack_signed_int(value, length)),
                    value)

    def test_macaddr(self):
        buffer = bytearray(6)
        macaddr = 'AABBCCDDEEFF'
        pack_macaddr_into(macaddr, buffer, 0)
        assert unpack_macaddr_from(buffer, 0) == macaddr

    def test_ufloat(self):
        values = (123.2, 100.12)
        format = '66'
        self.assertEqual(unpack(format, pack(format, *values)), values)

        values = (12.2, 10.12)
        format = '66'
        self.assertEqual(unpack(format, pack(format, *values)), values)

    def test_lfloat(self):
        values = (12.123, 1.321)
        format = '88'
        self.assertEqual(unpack(format, pack(format, *values)), values)

        values = (9.1, 3.1)
        format = '88'
        self.assertEqual(unpack(format, pack(format, *values)), values)

    def test_format(self):
        values = (1, 6, 3, 199)
        format = '1111'
        self.assertEqual(unpack(format, pack(format, *values)), values)

        values = (-43, 12, 3991)
        format = '211'
        self.assertEqual(unpack(format, pack(format, *values)), values)

        macaddr = 'AABBCCDDEEFF'
        values = (macaddr, 3212, -99912, 32943)
        format = '3154'
        self.assertEqual(unpack(format, pack(format, *values)), values)


if __name__ == '__main__':
    unittest.main()
