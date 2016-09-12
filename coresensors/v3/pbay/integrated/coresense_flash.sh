#!/bin/bash
echo
echo "___Coresense Flashing Utility___"
echo
if [ $# -eq 0 ]
then
echo "No Coresense firmware file provided."
echo "Correct usage - coresenseflash firmware.ino.bin"
echo
exit
fi

if [ ${1: -8} != ".ino.bin" ]
then
echo "Incorrect Coresense firmware file provided. The firmware file has .ino.bin extension."
echo
exit
fi

echo "Resetting Coresense board to bootloader mode... (Step 1/2)"
echo
stty -F /dev/waggle_coresense 1200 hupcl; sleep 2
echo "Flashing Coresense board with new firmware... (Step 2/2)"
echo
/usr/bin/bossac -i -d --port=waggle_coresense -U true -e -w -v -b $1 -R
echo 
echo ">>>>>>>>>>>> Firmware flash process completed <<<<<<<<<<<<<"
echo


