import urllib.request
import struct
from base64 import b64decode
import sys


def decode_alphasense(data):
    bincounts = struct.unpack_from('<16H', data, offset=0)
    mtof = [x / 3 for x in struct.unpack_from('<4B', data, offset=32)]
    sample_flow_rate = struct.unpack_from('<f', data, offset=36)[0]
    pressure = struct.unpack_from('<I', data, offset=40)[0]
    temperature = pressure / 10.0
    checksum = struct.unpack_from('<H', data, offset=48)[0]
    pmvalues = struct.unpack_from('<fff', data, offset=50)

    values = {
        'bins': bincounts,
        'mtof': mtof,
        'sample flow rate': sample_flow_rate,
        'pm1': pmvalues[0],
        'pm2.5': pmvalues[1],
        'pm10': pmvalues[2],
        'error': sum(bincounts) & 0xFF != checksum,
    }

    if temperature > 500:
        values['pressure'] = pressure
    else:
        values['temperature'] = temperature

    return values


def unpack_row(line):
    fields = list(map(str.strip, line.split(';')))

    data = {}

    for entry in fields[8][1:-1].split(','):
        key, value = map(str.strip, entry.split(':'))
        key = key[1:].strip()
        value = value[:-1].strip()
        data[key] = value

    result = {}

    result['node_id'] = fields[0]
    result['date'] = fields[1]
    result['plugin_name'] = fields[2]
    result['plugin_version'] = float(fields[3])
    result['plugin_instance'] = fields[4]
    result['timestamp'] = fields[5]
    result['sensor'] = fields[6]
    result['meta'] = fields[7]
    result['values'] = data

    return result


def get_rows_from_url(url):
    with urllib.request.urlopen(url) as response:
        for line in response:
            line = line.decode('utf-8')
            if not line.startswith('#'):
                yield unpack_row(line)


def get_alphasense_data_from_url(url):
    for result in get_rows_from_url(url):
        if result['plugin_name'] == 'alphasense' and 'data' in result['values']:
            timestamp = result['timestamp']
            yield timestamp, decode_alphasense(b64decode(result['values']['data']))


if __name__ == '__main__':
    url = sys.argv[1]

    print('timestamp,pm1,pm2.5,pm10,bin0,bin1,bin2,bin3,bin4,bin5,bin6,bin7,bin8,bin9,bin10,bin11,bin12,bin13,bin14,bin15')

    for timestamp, data in get_alphasense_data_from_url(url):
        pm10 = data['pm10']
        pm25 = data['pm2.5']
        pm1 = data['pm1']
        bins = data['bins']

        # get particulate values + bin counts
        values = [timestamp, pm1, pm25, pm10] + list(bins) + [data['error']]

        # write csv-like row from data
        print(','.join(map(str, values)))
