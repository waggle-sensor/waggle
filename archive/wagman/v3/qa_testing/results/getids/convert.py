def format_mac(mac):
    return ''.join(map(format_block, mac.split(':')[2:]))


def format_block(x):
    return '{:02X}'.format(int(x, 16))


def cleanup(line):
    return line.strip()


def relevant(line):
    return not line.startswith('#')


for line in filter(relevant, map(cleanup, open('boards.csv'))):
    ident, mac = line.split(',')
    print(','.join([ident, format_mac(mac)]))
