import signal
import time

def handler(signum, frame):
    print "I am exiting"
    exit()

signal.signal(signal.SIGINT, handler)

while 1:
    time.sleep(10)
