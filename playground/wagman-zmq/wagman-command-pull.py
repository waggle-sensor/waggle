'''
Only job is to pull commands from wagman-server. Pretty simple...
'''
from serial import Serial
import zmq


context = zmq.Context()

pull = context.socket(zmq.PULL)
pull.bind('tcp://*:5554')

with Serial('/dev/waggle_sysmon', 57600) as serial:
    while True:
        message = pull.recv()
        serial.write(message)
