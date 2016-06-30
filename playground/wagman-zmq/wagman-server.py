'''
This establishes a listener for incoming messages and manages syncing up the
req / rep message, command push and subscribing to the correct output.
'''
import zmq
import time


context = zmq.Context()

# Subscribes to Wagman publisher to get outgoing message.
sub = context.socket(zmq.SUB)
sub.connect('tcp://localhost:5555')

# Give the subscriber a chance to connect.
time.sleep(1)

# Connects to Wagman command pull to which it feeds commands from req.
push = context.socket(zmq.PUSH)
push.connect('tcp://localhost:5554')

time.sleep(1)

# Listens for incoming req / rep sequences.
rep = context.socket(zmq.REP)
rep.bind('tcp://*:5556')


while True:
    msg = rep.recv()

    # should do this with a timeout
    sub.setsockopt(zmq.SUBSCRIBE, msg)
    push.send(msg)
    output = sub.recv()
    sub.setsockopt(zmq.UNSUBSCRIBE, msg)

    rep.send(output)
