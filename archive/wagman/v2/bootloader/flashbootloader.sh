#!/bin/bash
avrdude -c avrisp2 -P usb -p m32u4 -U flash:w:Caterina-Micro.hex:i
