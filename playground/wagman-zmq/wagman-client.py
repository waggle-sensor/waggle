import zmq
import sys


context = zmq.Context()

socket = context.socket(zmq.REQ)
socket.connect('tcp://localhost:5556')
socket.setsockopt(zmq.LINGER, 0)
socket.setsockopt(zmq.RCVTIMEO, 8000)

socket.send_string(' '.join(sys.argv[1:]))
socket.recv_string()
