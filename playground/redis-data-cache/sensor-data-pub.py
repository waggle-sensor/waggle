"""
Publishes data from coresense board. Basically just forwards data from serial
port to a more convinient form. (One which many subscribers can listen too
simultaneously! Think logging or streaming in addition to only caching or
putting in the database!)

I'm also using TCP, but this can be done using IPC instead. Just change
tcp://... to something like ipc://sensordata.

Sean
"""
import zmq
import coresense
import datetime


context = zmq.Context()
socket = context.socket(zmq.PUB)
socket.bind('tcp://*:12345')

conn = coresense.Connection('/dev/ttyACM0')

while True:
    message = conn.recv()
    datetime_string = str(datetime.datetime.now())
    for entry in message.entries:
        value_string = ','.join('{}:{}'.format(k, v) for k, v in entry.values)
        string = ','.join([entry.sensor, datetime_string, value_string])
        socket.send_string(string)
