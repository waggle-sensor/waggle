# Burn the Arduino Micro bootloader on to Wagman:
To burn the Arduino Micro Caterina bootloader on the Wagman,
you will need a AVR ICSP programmer. These instructions have
been tested to work with an AVRISP mkII programmer
(http://www.atmel.com/tools/AVRISPMKII.aspx).

```bash
avrdude -c avrisp2 -P usb -p m32u4 -U flash:w:Caterina-Micro.hex:i

