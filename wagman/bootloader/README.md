# Burn the Arduino Micro bootloader on to Wagman:
To burn the Arduino Micro Caterina bootloader on the Wagman,
you will need an AVR ICSP programmer. This instruction has
been tested to work with an AVRISP mkII programmer on 
Ubuntu 14.04 system with avrdude version 6.0.1.
(http://www.atmel.com/tools/AVRISPMKII.aspx).

```bash
avrdude -c avrisp2 -P usb -p m32u4 -U flash:w:Caterina-Micro.hex:i

