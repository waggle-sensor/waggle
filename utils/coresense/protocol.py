HEADER_BYTE = 0xAA
FOOTER_BYTE = 0x55
HEADER_LENGTH = 3
FOOTER_LENGTH = 2


class FramingProtocol(object):

    def connection_made(self):
        self.buffer = bytearray()

    def connection_lost(self):
        pass

    def data_received(self, data):
        for x in data:
            self.buffer.append(x)

        self.drop_incomplete(start=0)

        while True:
            if len(self.buffer) < HEADER_LENGTH:
                break

            # unpack header
            sequence = (self.buffer[1] >> 4) & 0x0F
            version = self.buffer[1] & 0x0F
            length = self.buffer[2]

            # ensure that we have at least enough for single packet
            if len(self.buffer) < HEADER_LENGTH + length + FOOTER_LENGTH:
                break

            # unpack footer
            data = self.buffer[HEADER_LENGTH:HEADER_LENGTH + length]
            crc = self.buffer[HEADER_LENGTH + length + 0]
            end = self.buffer[HEADER_LENGTH + length + 1]

            if end != FOOTER_BYTE:
                self.invalid_packet(self, ValueError('Bad end byte.'))
                self.drop_incomplete(start=1)
                continue

            if compute_crc(data) != crc:
                self.invalid_packet(self, ValueError('Bad CRC.'))
                self.drop_incomplete(start=1)
                continue

            # received a good packet (up to crc / footer check...)
            self.packet_received(sequence, version, data)
            del self.buffer[:HEADER_LENGTH + length + FOOTER_LENGTH]

    def drop_incomplete(self, start):
        try:
            offset = self.buffer.index(HEADER_BYTE, start)
            del self.buffer[:offset]
        except ValueError:
            del self.buffer[:]

    def packet_received(self, sequence, version, data):
        pass

    def invalid_packet(self, exc):
        pass


class CoresenseProtocol(FramingProtocol):

    def packet_received(self, sequence, version, data):
        self.process_subpackets(data)

    def subpacket_received(self, sensor, valid, data):
        pass

    def process_subpackets(self, data):
        offset = 0

        while offset < len(data):
            sensor = data[offset + 0]
            valid = (data[offset + 1] & 0x80) != 0
            length = data[offset + 1] & 0x7F
            offset += 2

            if offset + length > len(data):
                raise IndexError('sensor {} subpacket has invalid length'.format(sensor))

            subpacket_data = data[offset:offset + length]
            offset += length

            self.subpacket_received(sensor, valid, subpacket_data)

    def invalid_subpacket(self, exc):
        pass


def create_packet(sequence, version, data):
    sequence_version = ((sequence & 0x0F) << 4) | (version & 0x0F)
    header = bytearray([0xAA, sequence_version, len(data)])
    footer = bytearray([compute_crc(data), 0x55])
    return bytearray([]).join([header, data, footer])


def create_subpacket(sensor, valid, data):
    flag = (0x80 if valid else 0) | (len(data) & 0x7F)
    return bytearray([sensor, flag]) + data


def create_packet_from_subpackets(sequence, version, subpackets):
    subpacket_data = bytearray([]).join(create_subpacket(sensor, valid, data)
                                        for sensor, valid, data in subpackets)
    return create_packet(sequence, version, subpacket_data)


def compute_crc(data, crc=0):
    for byte in data:
        crc ^= byte
        for j in range(8):
            if crc & 1 != 0:
                crc = (crc >> 1) ^ 0x8C
            else:
                crc >>= 1
    return crc
