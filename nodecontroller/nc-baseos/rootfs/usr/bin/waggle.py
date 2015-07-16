#!/usr/bin/python

import sys
import time
import os
import signal

WAGGLE_PID=os.environ['WAGGLE_PID']

def receive_signal(signum, stack):
    print 'Received:', signum
    exit(0)


def start():
    signal.signal(signal.SIGUSR1, receive_signal)

    while True:
        hostname = "localhost"
        print "Sending ping @ {}".format(hostname)
        response = os.system("ping -c 1 " + hostname)
        print "{}:{}".format(hostname, response)
        time.sleep(1)

def stop():
    print "WAGGLE_PID: {}".format(WAGGLE_PID)
    if (os.path.isfile(WAGGLE_PID)):
        waggle_file = open(WAGGLE_PID, "r")
        pid = waggle_file.readline()
        pid = int(pid.rstrip())
        print "--{}--".format(pid)
        os.kill(pid, signal.SIGUSR1)
    else:
        print "Waggle is not running"
        
def use():
    print "{}".format(sys.argv[0]) + " {start|stop}"

if __name__ == "__main__":
    if (len(sys.argv) != 2):
        use()
        exit(1)
    
    cmd = sys.argv[1]

    if (cmd == "start"):
        start()
    elif (cmd == "stop"):
        stop()
    else:
        use()
        exit(1)

    exit(0)
