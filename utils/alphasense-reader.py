'''
Alphasense reader using the USB-ISS interface. The only real dependency
is on the set_spi_mode and transfer_data functions. This could easily be
replaced with some other layer.

Example:

Suppose that the Alphasense is device /dev/ttyACM0. You can simple run:

python alphasense.py /dev/ttyACM0

USB-ISS Reference:
https://www.robot-electronics.co.uk/htm/usb_iss_tech.htm

Alphasense Reference:
waggle-sensor/waggle/docs/alphasense-opc-n2/
'''
from serial import Serial
from time import sleep
import struct
import sys


def linspace(a, b, n):
    return [a + i * (b - a) / (n - 1) for i in range(n)]


def spi_divisor(sck):
    divisor = (6000000 / sck) - 1

    if int(divisor) != divisor:
        raise ValueError('Nonintegral SCK divisor.')

    return int(divisor)


def set_spi_mode(device, mode, freq):
    device.write(bytes([0x5A, 0x02, mode, spi_divisor(freq)]))
    response = device.read(2)
    if response[0] == 0:
        if response[1] == 0x05:
            raise RuntimeError('Unknown Command')
        elif response[1] == 0x06:
            raise RuntimeError('Internal Error 1')
        elif response[1] == 0x07:
            raise RuntimeError('Internal Error 2')
        else:
            raise RuntimeError('Undocumented Error')


def transfer_data(device, data):
    device.write(bytes([0x61] + data))
    response = device.read(1 + len(data))
    if response[0] == 0:
        raise RuntimeError('Transmission failed.')
    return response[1:]


def power_on(device, fan=True, laser=True):
    if fan and laser:
        transfer_data(device, [0x03, 0x00])
    elif fan:
        transfer_data(device, [0x03, 0x04])
    elif laser:
        transfer_data(device, [0x03, 0x02])


def power_off(device, fan=True, laser=True):
    if fan and laser:
        transfer_data(device, [0x03, 0x01])
    elif fan:
        transfer_data(device, [0x03, 0x05])
    elif laser:
        transfer_data(device, [0x03, 0x03])


def set_laser_power(device, power):
    transfer_data(device, [0x42, 0x01, power])


def set_fan_power(device, power):
    transfer_data(device, [0x42, 0x00, power])


def get_info_string(device):
    transfer_data(device, [0x3F])
    sleep(0.01)
    response = transfer_data(device, [0x3F] * 60)
    return response.decode()


def ping(device):
    response = transfer_data(device, [0xCF])
    return response[0] == 0xF3


def read_config(device):
    raise NotImplementedError

    transfer_data(device, [0x3C])
    sleep(0.01)

    result = bytearray(256)

    for i in range(256):
        result[i] = transfer_data(device, [0x3C])[0]
        sleep(0.001)

    print(struct.unpack_from('<16H', result, 0))


def read_histogram(device):
    response = bytearray(62)

    transfer_data(device, [0x30])
    sleep(0.5)

    for i in range(len(response)):
        response[i] = transfer_data(device, [0x30])[0]
        sleep(0.01)

    binsizes = linspace(0.38, 17.0, 16)
    bincounts = struct.unpack_from('<16B', response, offset=0)

    # TODO unpack remaining data from alphasense

    return list(zip(binsizes, bincounts))


if len(sys.argv) != 2:
    print('Usage: {} device-name'.format(sys.argv[0]))
    sys.exit(1)

device = Serial(sys.argv[1])

try:
    set_spi_mode(device, 0x92, 500000)  # 0x902
    sleep(1)

    power_on(device)
    sleep(1)

    while True:
        bindata = read_histogram(device)

        for size, count in bindata:
            print('{: 3.4f} {:>6}'.format(size, count))
        print()

        sleep(10)

finally:
    device.close()
