import zmq
import sys


context = zmq.Context()

socket = context.socket(zmq.REQ)
socket.connect('tcp://localhost:5556')
socket.send_string(sys.argv[1])
print(socket.recv())
