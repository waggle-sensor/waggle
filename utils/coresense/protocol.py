HEADERSIZE = 3
FOOTERSIZE = 2


class FramingProtocol(object):

    def connection_made(self):
        self.data = bytearray(1024)
        self.size = 0

    def connection_lost(self):
        self.size = 0

    def data_received(self, data):
        for byte in data:
            self.data[self.size] = byte  # check for overflow?
            self.size += 1
            if self.size == len(self.data):
                self.process_candidates()
        self.process_candidates()

    def align_candidates(self, start):
        try:
            offset = self.data.index(bytearray([0xAA]), start, self.size)
            newsize = self.size - offset
            self.data[:newsize] = self.data[offset:self.size]
            self.size = newsize
        except ValueError:
            self.size = 0

    def process_candidates(self):
        while True:
            if self.size < HEADERSIZE:
                break

            header = self.data[0]
            sequence = (self.data[1] >> 4) & 0x0F
            version = self.data[1] & 0x0F
            length = self.data[2]

            # don't have entire packet
            if self.size < length + HEADERSIZE + FOOTERSIZE:
                break

            packetdata = self.data[3:3 + length]
            crc = self.data[3 + length + 0]
            footer = self.data[3 + length + 1]

            if header == 0xAA and footer == 0x55 and crc == compute_crc(packetdata):
                self.packet_received(sequence, version, packetdata)
                self.align_candidates(length + HEADERSIZE + FOOTERSIZE)
            else:
                self.invalid_packet(exc=None)
                self.align_candidates(1)

    def packet_received(self, sequence, version, data):
        pass

    def invalid_packet(self, exc):
        pass


class CoresenseProtocol(FramingProtocol):

    def packet_received(self, sequence, version, data):
        self.packet_start(sequence, version)
        self.process_subpackets(data)
        self.packet_end()

    def packet_start(sequence, version):
        pass

    def packet_end():
        pass

    def subpacket_received(self, sensor, valid, data):
        pass

    def process_subpackets(self, data):
        offset = 0

        while offset < len(data):
            try:
                sensor = data[offset + 0]
                valid = (data[offset + 1] & 0x80) != 0
                length = data[offset + 1] & 0x7F
                offset += 2

                subpacket_data = data[offset:offset + length]
                offset += length
            except Exception as exc:
                self.invalid_subpacket(exc=exc)
                break

            self.subpacket_received(sensor, valid, subpacket_data)

    def invalid_subpacket(self, exc):
        pass


def create_packet(sequence, version, data):
    sequence_version = ((sequence & 0x0F) << 4) | (version & 0x0F)
    header = bytearray([0xAA, sequence_version, len(data)])
    footer = bytearray([compute_crc(data), 0x55])
    return header + data + footer  # join instead...?


def create_subpacket(sensor, valid, data):
    flag = (0x80 if valid else 0) | (len(data) & 0x7F)
    return bytearray([sensor, flag]) + data


def create_packet_from_subpackets(sequence, version, subpackets):
    return create_packet(sequence, version, bytearray([]).join(
        create_subpacket(sensor, valid, data) for sensor, valid, data in subpackets))


def compute_crc(data, crc=0):
    for byte in data:
        crc ^= byte
        for j in range(8):
            if crc & 1 != 0:
                crc = (crc >> 1) ^ 0x8C
            else:
                crc >>= 1
    return crc
