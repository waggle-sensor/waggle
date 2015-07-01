#!/usr/bin/env python


import sys
sys.path.append("..")
from utilities import packetmaker
from send import send


""" A python script that creates a registration message from the NC and sends it to the internal communication to put in the DC. """ 

registration = packetmaker.registration_packet()
print 'Registration packet made...' 

send(registration)