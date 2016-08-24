from collections import namedtuple
from datetime import datetime
import requests
import re
import sys

Row = namedtuple('Row', [
    'node_id',
    'date',
    'plugin_name',
    'plugin_version',
    'plugin_instance',
    'timestamp',
    'sensor',
    'meta',
    'values'])


def parse_date(s):
    return datetime.strptime(s, '%Y-%m-%d')


def parse_timestamp(s):
    if '.' in s:
        return datetime.strptime(s, '%Y-%m-%d %H:%M:%S.%f')
    else:
        return datetime.strptime(s, '%Y-%m-%d %H:%M:%S')


values_pattern = re.compile("'([^']+):([^']+)'")


def parse_values(s):
    return dict(values_pattern.findall(s))


def parse_row(line):
    row = line.split(';')

    return Row(node_id=row[0],
               date=parse_date(row[1]),
               plugin_name=row[2],
               plugin_version=row[3],
               plugin_instance=row[4],
               timestamp=parse_timestamp(row[5]),
               sensor=row[6],
               meta=row[7],
               values=parse_values(row[8]))


def get_entries(node_id, date):
    node_id = node_id.lower()
    date_str = date.strftime('%Y-%m-%d')
    url = 'http://beehive1.mcs.anl.gov/api/1/nodes/{}/export?date={}'.format(node_id, date_str)

    r = requests.get(url)

    if r.status_code != 200:
        return

    for line in r.iter_lines():
        if not line.startswith(b'#'):
            yield parse_row(line.decode())


def decode_alphasense_data(data):
    from base64 import b64decode
    import struct

    data = b64decode(data)

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
        'error': sum(bincounts) & 0xFFFF != checksum,
    }

    if temperature > 500:
        values['pressure'] = pressure
    else:
        values['temperature'] = temperature

    for i, count in enumerate(bincounts):
        yield '', 'bin{}'.format(i), count

    yield '', 'pm1', pmvalues[0]
    yield '', 'pm2.5', pmvalues[1]
    yield '', 'pm10', pmvalues[2]

decoders = {
    ('alphasense', 'data', 'data'): decode_alphasense_data,
    ('alphasense', 'config', 'firmware'): None,
    ('alphasense', 'config', 'config'): None,
}

if len(sys.argv) != 3:
    print('usage:', sys.argv[0], 'node-id', 'YYYY-MM-DD')
    sys.exit(1)

resource_node_id = sys.argv[1].lower()
resource_date = datetime.strptime(sys.argv[2], '%Y-%m-%d')

entries = []

for row in get_entries(resource_node_id, resource_date):
    for k, v in row.values.items():
        signature = (row.plugin_name, row.sensor, k)
        if signature in decoders and decoders[signature] is not None:
            for s2, k2, v2 in decoders[signature](v):
                entries.append((row.timestamp, row.plugin_name, s2, k2, v2))
        else:
            entries.append((row.timestamp, row.plugin_name, row.sensor, k, v))

entries.sort()

for row in entries:
    print(','.join(map(str, row)))
