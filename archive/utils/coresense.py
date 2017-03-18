import re
import struct


specification = '''
00
Board MAC
macaddr MAC Address

01
TMP112
ufloat Temperature

02
HTU21D
ufloat Temperature
ufloat Humidity

03
GP2Y1010AU0F
int24 Dust

04
BMP180
ufloat Temperature
int24 Atm Pressure

05
PR103J2
uint16 Temperature

06
TSL250RD
uint16 Light

07
MMA8452Q
ufloat Accel X
ufloat Accel Y
ufloat Accel Z
ufloat RMS

08
SPV1840LR5H-B
uint16 Sound Pressure

09
TSYS01
ufloat Temperature

0A
HMC5883L
lfloat B Field X
lfloat B Field Y
lfloat B Field Z

0B
HIH6130
ufloat Temperature
ufloat Humidity

0C
APDS-9006-020
uint16 Light

0D
TSL260RD
uint16 Light

0E
TSL250RD
uint16 Light

0F
MLX75305
uint16 Light

10
ML8511
uint16 Light

12
MLX90614
ufloat Temperature

13
TMP421
ufloat Temperature

14
SPV1840LR5H-B
uint16 Sound Pressure

15
Total reducing gases
int24 Concentration

16
Ethanol (C2H5-OH)
int24 Concentration

17
Nitrogen Di-oxide (NO2)
int24 Concentration

18
Ozone (03)
int24 Concentration

19
Hydrogen Sulphide (H2S)
int24 Concentration

1A
Total Oxidizing gases
int24 Concentration

1B
Carbon Monoxide (C0)
int24 Concentration

1C
Sulfur Dioxide (SO2)
int24 Concentration

1D
SHT25
int16 Temperature
int16 Humidity

1E
LPS25H
int16 ???
uint24 ???

1F
Si1145
uint16 ???

20
Intel MAC
macaddr MAC Address

FE
Sensor Health
uint8array Status
'''


def uint16(input):
    'unsigned 16-bit integer'
    byte1 = ord(input[0])
    byte2 = ord(input[1])
    value = (byte1 << 8) | byte2
    return value

uint16.length = 2


def int16(input):
    'signed 16-bit integer'
    byte1 = ord(input[0])
    byte2 = ord(input[1])
    value = ((byte1 & 0x7F) << 8) | byte2
    return value if byte1 & 0x80 == 0 else -value

int16.length = 2


def uint24(input):
    'unsigned 24-bit integer'
    byte1 = ord(input[0])
    byte2 = ord(input[1])
    byte3 = ord(input[2])
    value = (byte1 << 16) | (byte2 << 8) | (byte3)
    return value

uint24.length = 3


def int24(input):
    'signed 24-bit integer'
    byte1 = ord(input[0])
    byte2 = ord(input[1])
    byte3 = ord(input[2])
    value = ((byte1 & 0x7F) << 16) | (byte2 << 8) | (byte3)
    return value if byte1 & 0x80 == 0 else -value

int24.length = 3


def ufloat(input):
    byte1 = ord(input[0])
    byte2 = ord(input[1])
    # have to be careful here, we do not want three decimal placed here.
    value = (byte1 & 0x7F) + (((byte2 & 0x7F) % 100) * 0.01)
    if (byte1 & 0x80) == 0x80:
        value = value * -1
    return value

ufloat.length = 2


def lfloat(input):
    byte1 = ord(input[0])
    byte2 = ord(input[1])
    value = ((byte1 & 0x7c) >> 2) + ((((byte1 & 0x03) << 8) | byte2) * 0.001)
    if byte1 & 0x80 != 0:
        value = value * -1
    return value

lfloat.length = 2


def macaddr(input):
    return ''.join(map(lambda b: '{:02X}'.format(ord(b)), input))

macaddr.length = 6


def uint8array(input):
    'unsigned 8-bit integer[4]'
    # F7 - byte input[4], {0-0xffffffff} - Byte1 Byte2 Byte3 Byte4
    byte1 = ord(input[0])
    byte2 = ord(input[1])
    byte3 = ord(input[2])
    byte4 = ord(input[3])
    return [byte1, byte2, byte3, byte4]

uint8array.length = 4


# build decoder dictionary from format spec
sensor_table = {}

for block in re.split('\n\n+', specification.strip()):
    lines = block.splitlines()
    number = int(lines[0], 16)
    sensor = lines[1]
    fields = []

    for field in lines[2:]:
        field_type, _, field_name = field.partition(' ')
        field_func = globals()[field_type]
        fields.append((field_name, field_func))

    sensor_table[number] = (sensor, fields)


def pack_subpackets(subpackets):
    packet = []

    for ident, valid, body in subpackets:
        assert 0 <= ident < 256
        assert len(body) < 128

        length = len(body) | 0x80 if valid else len(body)
        header = struct.pack('>BB', ident, length)

        packet.append(header)
        packet.append(body)

    return b''.join(packet)


def unpack_subpackets(packet):
    subpackets = []

    offset = 0

    while offset < len(packet):
        # unpack subpacket header
        ident, length = struct.unpack_from('>BB', packet, offset)
        valid = length & 0x80 != 0
        length = length & ~0x80
        offset += 2

        # unpack subpacket content
        content = packet[offset:offset + length]
        offset += length

        subpackets.append((ident, valid, content))

    return subpackets


def unpack_sensor_subpacket(subpacket):
    ident, valid, content = subpacket
    sensor_name, sensor_fields = sensor_table[ident]
    sensor_values = []

    offset = 0

    for field_name, field_unpack in sensor_fields:
        field_value = field_unpack(content[offset:offset + field_unpack.length])
        sensor_values.append((field_name, field_value))
        offset += field_unpack.length

    return (sensor_name, sensor_values)


def unpack_sensor_subpackets(subpackets):
    return list(map(unpack_sensor_subpacket, subpackets))


def run_tests():
    print('testing single subpacket')

    subpackets = [
        (0x01, True, b'3212'),
    ]

    assert unpack_subpackets(pack_subpackets(subpackets)) == subpackets

    print('testing multiple subpackets 1')

    subpackets = [
        (0x01, True, b'3212awe'),
        (0x13, True, b'aaskdjelrkjiofs'),
    ]

    assert unpack_subpackets(pack_subpackets(subpackets)) == subpackets

    print('testing multiple subpackets 2')

    subpackets = [
        (0x01, True, b'3212awe'),
        (0x03, False, b'123f'),
        (0x13, True, b'aaskdjelrkjiofs'),
    ]

    assert unpack_subpackets(pack_subpackets(subpackets)) == subpackets

    print('testing empty')

    subpackets = []
    assert unpack_subpackets(pack_subpackets(subpackets)) == subpackets

    print('testing empty content 1')

    subpackets = [
        (0x01, True, b''),
    ]

    assert unpack_subpackets(pack_subpackets(subpackets)) == subpackets

    print('testing empty content 2')

    subpackets = [
        (0x01, True, b''),
        (0x01, False, b'a'),
        (0x01, True, b'ab'),
    ]

    assert unpack_subpackets(pack_subpackets(subpackets)) == subpackets

    print('all tests passed')


if __name__ == '__main__':
    run_tests()
