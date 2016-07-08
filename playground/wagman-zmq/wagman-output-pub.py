'''
Only job is to publish output read from the Wagman. These can be consumed by
any subscriber. In particular, each command server you have will subscribe to
the publisher.
'''
from serial import Serial
import zmq


context = zmq.Context()

pub = context.socket(zmq.PUB)
pub.bind('tcp://*:5555')

with Serial('/dev/waggle_sysmon', 57600) as serial:
    while True:
        # read serial data and split packets as we have been doing
        pub.send(resulting_packet_data)
