#!/bin/bash
avrdude -C./avrdude.conf -v -patmega32u4 -cstk500v2 -Pusb -Uflash:w:./Caterina-Micro.hex:i -Ulock:w:0x2F:m

