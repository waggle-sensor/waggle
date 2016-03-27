"""
Subscribes to data being published by sensor board and pushes it into the Redis
data cache.

Sean
"""
import zmq
from redis import Redis


context = zmq.Context()

socket = context.socket(zmq.SUB)
socket.setsockopt_string(zmq.SUBSCRIBE, '')
socket.connect('tcp://localhost:12345')

redis = Redis()

while True:
    msg = socket.recv_string()
    redis.lpush('sensor-data', msg)
