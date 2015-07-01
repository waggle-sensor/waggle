#!/bin/bash
avrdude -C./avrdude.conf -v -patmega2560 -cwiring -P/dev/ttyACM0 -b115200 -D -Uflash:w:./initialBoot.cpp.hex:i 




