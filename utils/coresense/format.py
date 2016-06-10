'''
Library for working with coresense data formats.

Example

>>> import format

>>> data = format.pack('1122', 32, 55, -123, -321)
>>> print(format.unpack(data))

Format Reference

- 1: unsigned 16 bit integer
- 2: signed 16 bit integer
- 3: mac address
- 4: unsigned 24 bit integer
- 5: signed 24 bit integer
- 6: fixed point (-31.999, 31.999)
- 7: array of 4 bytes
- 8: fixed point (-127.99, 127.99)

'''
from functools import partial


def pack_unsigned_int_into(value, buffer, offset, length):
    assert value >= 0

    for i in reversed(range(0, length)):
        buffer[offset + i] = value & 0xFF
        value >>= 8


def unpack_unsigned_int_from(buffer, offset, length):
    value = 0

    for i in range(0, length):
        value <<= 8
        value |= buffer[offset + i]

    return value


def pack_unsigned_int(value, length):
    buffer = bytearray(length)
    pack_unsigned_int_into(value, buffer, 0, length)
    return buffer


def unpack_unsigned_int(buffer):
    return unpack_unsigned_int_from(buffer, 0, len(buffer))


def pack_signed_int_into(value, buffer, offset, length):
    pack_unsigned_int_into(abs(value), buffer, offset, length)

    if value < 0:
        buffer[offset + 0] |= 0x80
    else:
        buffer[offset + 0] &= 0x7F


def unpack_signed_int_from(buffer, offset, length):
    value = buffer[offset + 0] & 0x7F

    for i in range(1, length):
        value <<= 8
        value |= buffer[offset + i]

    if buffer[offset + 0] & 0x80 != 0:
        value = -value

    return value


def pack_signed_int(value, length):
    buffer = bytearray(length)
    pack_signed_int_into(value, buffer, 0, length)
    return buffer


def unpack_signed_int(buffer):
    return unpack_signed_int_from(buffer, 0, len(buffer))


def pack_ufloat_into(value, buffer, offset):
    assert -127.99 <= value <= 127.99

    absvalue = abs(value)
    intpart = int(absvalue)
    fracpart = int(100 * (absvalue - intpart))

    buffer[offset + 0] = intpart & 0x7F
    buffer[offset + 1] = fracpart & 0x7F

    if value < 0:
        buffer[offset + 0] |= 0x80


def unpack_ufloat_from(buffer, offset):
    byte1 = buffer[offset + 0]
    byte2 = buffer[offset + 1]
    # have to be careful here, we do not want three decimal placed here.
    value = (byte1 & 0x7F) + (((byte2 & 0x7F) % 100) * 0.01)
    if (byte1 & 0x80) == 0x80:
        value = value * -1
    return value


def pack_lfloat_into(value, buffer, offset):
    assert -31.999 <= value <= 31.999

    absvalue = abs(value)
    intpart = int(absvalue)
    fracpart = int(1000 * (absvalue - intpart))

    buffer[offset + 0] = (intpart & 0b00011111) << 2
    buffer[offset + 0] |= (fracpart >> 8) & 0b00000011
    buffer[offset + 1] = fracpart & 0xFF

    if value < 0:
        buffer[offset + 0] |= 0x80


def unpack_lfloat_from(buffer, offset):
    byte1 = buffer[offset + 0]
    byte2 = buffer[offset + 1]
    value = ((byte1 & 0x7c) >> 2) + ((((byte1 & 0x03) << 8) | byte2) * 0.001)
    if byte1 & 0x80 != 0:
        value = value * -1
    return value


def pack_macaddr_into(macaddr, buffer, offset):
    assert len(macaddr) == 6
    buffer[offset:offset + 6] = macaddr


def unpack_macaddr_from(buffer, offset):
    return buffer[offset:offset + 6]


def pack_uint8array_into(array, buffer, offset):
    buffer[offset:offset + 4] = array


def unpack_uint8array_from(buffer, offset):
    return buffer[offset:offset + 4]


formatpack = {
    '1': partial(pack_unsigned_int_into, length=2),
    '2': partial(pack_signed_int_into, length=2),

    '4': partial(pack_unsigned_int_into, length=3),
    '5': partial(pack_signed_int_into, length=3),

    '6': pack_ufloat_into,
    '8': pack_lfloat_into,

    '3': pack_macaddr_into,
    '7': pack_uint8array_into,
}

formatunpack = {
    '1': partial(unpack_unsigned_int_from, length=2),
    '2': partial(unpack_signed_int_from, length=2),

    '4': partial(unpack_unsigned_int_from, length=3),
    '5': partial(unpack_signed_int_from, length=3),

    '6': unpack_ufloat_from,
    '8': unpack_lfloat_from,

    '3': unpack_macaddr_from,
    '7': unpack_uint8array_from,
}

formatsize = {
    '1': 2,
    '2': 2,

    '4': 3,
    '5': 3,

    '6': 2,
    '8': 2,

    '3': 6,
    '7': 4,
}

formatdesc = {
    '1': 'unsigned 16 bit integer',
    '2': 'signed 16 bit integer',

    '4': 'unsigned 24 bit integer',
    '5': 'signed 24 bit integer',

    '6': 'fixed point (-31.999, 31.999)',
    '8': 'fixed point (-127.99, 127.99)',

    '3': 'mac address',
    '7': 'array of 4 bytes',
}


def calcsize(format):
    return sum(formatsize[f] for f in format)


def unpack_from(format, buffer, offset=0):
    # This helps with compatibility between Python 2 and 3 in terms
    # of how values in an array are accessed.
    if not isinstance(buffer, bytearray):
        buffer = bytearray(buffer)

    values = []

    for f in format:
        values.append(formatunpack[f](buffer, offset))
        offset += formatsize[f]

    return tuple(values)


def pack_into(format, buffer, offset, *values):
    assert len(format) == len(values)

    for f, v in zip(format, values):
        formatpack[f](v, buffer, offset=offset)
        offset += formatsize[f]


def pack(format, *values):
    buffer = bytearray(calcsize(format))
    pack_into(format, buffer, 0, *values)
    return buffer


def unpack(format, buffer):
    assert calcsize(format) == len(buffer)
    return unpack_from(format, buffer, offset=0)
