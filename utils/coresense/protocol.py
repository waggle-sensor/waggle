from bytequeue import bytequeue

HEADER_BYTE = 0xAA
FOOTER_BYTE = 0x55
HEADER_LENGTH = 3
FOOTER_LENGTH = 2


class FramingProtocol(object):

    def connection_made(self):
        self.buffer = bytequeue(capacity=4096)

    def connection_lost(self):
        pass

    def data_received(self, data):
        for byte in data:
            self.buffer.enqueue(byte)

        while True:
            while len(self.buffer) > 0 and self.buffer[0] != HEADER_BYTE:
                self.buffer.dequeue()

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
                self.buffer.dequeue()
                continue

            if compute_crc(data) != crc:
                self.invalid_packet(self, ValueError('Bad CRC.'))
                self.buffer.dequeue()
                continue

            self.packet_received(sequence, version, data)

            # clear packet from buffer
            for _ in range(HEADER_LENGTH + length + FOOTER_LENGTH):
                self.buffer.dequeue()

    def packet_received(self, sequence, version, data):
        pass

    def invalid_packet(self, exc):
        pass


class CoresenseProtocol(FramingProtocol):

    def packet_received(self, sequence, version, data):
        self.packet_start(sequence, version)
        self.process_subpackets(data)
        self.packet_end()

    def packet_start(self, sequence, version):
        pass

    def packet_end(self):
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
