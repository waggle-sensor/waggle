#!/bin/bash

#sets up the gpio pin to do node controller heartbeat
cd /sys/class/gpio
echo 204 > export
cd gpio204
echo out > direction
