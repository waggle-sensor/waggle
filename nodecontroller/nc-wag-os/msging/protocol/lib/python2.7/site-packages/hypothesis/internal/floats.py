from __future__ import division, print_function, absolute_import, \
    unicode_literals

import struct


def decompose_float(f):
    as_long = struct.unpack(b'!Q', struct.pack(b'!d', f))[0]

    sign = -1 if (as_long >> 63) else 1
    exponent = as_long >> 52
    mantissa = as_long & ((1 << 53) - 1)
    return (sign, exponent, mantissa)
