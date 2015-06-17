#!/bin/bash
avrdude -C/root/ship/avrdude.conf -v -patmega2560 -cwiring -P/dev/ttyACM0 -b115200 -D -Uflash:w:/root/ship/envsenseCluster.cpp.hex:i 




