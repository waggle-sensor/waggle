from protocol import CoresenseProtocol
from serial import Serial
from format import unpack
import sys


sensorspec = {
    0x00: ('MACADDR', '3', ['MAC Address']),
    0x01: ('TMP112', '6', ['Temperature']),
    0x02: ('HTU21D', '66', ['Temperature', 'RH']),
    0x03: ('HIH4030', '1', ['RH']),
    0x04: ('BMP180', '64', ['Temperature', 'Pressure']),
    0x05: ('PR103J2', '1', ['Temperature']),
    0x06: ('TSL250RD', '1', ['Light Intensity']),
    0x07: ('MMA8452Q', '6666', ['Accel.X', 'Accel.Y', 'Accel.Z', 'Vibration']),
    0x08: ('SPV1840LR5H-B', '1', ['Sound Intensity']),
    0x09: ('TSYS01', '6', ['Temperature']),
    0x0A: ('HMC5883L', '888', ['Mag.X', 'Mag.Y', 'Mag.Z']),
    0x0B: ('HIH6130', '66', ['Temperature', 'RH']),
    0x0C: ('APDS-9006-020', '1', ['Luminance']),
    0x0D: ('TSL260RD', '1', ['IR Light Intensity']),
    0x0E: ('TSL250RD', '1', ['Light Intensity']),
    0x0F: ('MLX75305', '1', ['Light Intensity']),
    0x10: ('ML8511', '1', ['UV Light Intensity']),
    0x12: ('MLX90614', '6', ['Temperature']),
    0x13: ('TMP421', '6', ['Temperature']),
}


class CoresensePluginProtocol(CoresenseProtocol):

    def packet_start(self, sequence, version):
        print('Start Packet')
        print('  Sequence:', sequence)
        print('  Version:', version)
        print()

    def packet_end(self):
        print('End packet')
        print()

    def subpacket_received(self, sensor, valid, data):
        print('  Start Subpacket')
        print('    Sensor: {:02X}'.format(sensor))
        print('    Valid:', valid)
        print('    Raw Data:', ' '.join(map(format_hex, data)))

        # self.show_unpacked_values(sensor, valid, data)

        print('  End Subpacket')
        print()

    def show_unpacked_values(self, sensor, valid, data):
        if sensor in sensorspec:
            name, fmt, fields = sensorspec[sensor]

            print('    Sensor Name:', name)
            print('    Sensor Values:')

            values = unpack(fmt, data)

            for field, value in zip(fields, values):
                print('    - {}: {}'.format(field, value))
        else:
            print('    Sensor Name: ?')
            print('    Sensor Values: ?')

    def invalid_packet(self, exc):
        print('!! Bad packet!', exc)

    def invalid_subpacket(self, exc):
        print('!!!! Bad subpacket!', exc)


def format_hex(x):
    return '{:02X}'.format(x)


def format_mac(macaddr):
    return ''.join(map(format_hex, macaddr))


if len(sys.argv) != 2:
    print('Usage: {} device'.format(sys.argv[0]))
    sys.exit(1)

serial = Serial(sys.argv[1], 115200)

protocol = CoresensePluginProtocol()
protocol.connection_made()

while True:
    protocol.data_received(serial.read())

protocol.connection_lost()
