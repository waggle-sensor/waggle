This folder contains firmware version 3 for core sensors including Intel Chemsense board and Alpha sensor with airsense and lightsense board version 3.1 (July 11, 2016).

The folder "stubs" is nothing, so please ignore the folder. Someday it will be removed.

##Integrated
The codes were cleaned up.
Heart beat (HBEAT) switch voltage HIGH/LOW every 1 sec.
A whole packet is printed every 24 secs.
Selected sensors in Airsense/Ligntsense board get data every 1 sec to average sensor values.
Alpha sensor is integrated in the code, but v3.1 airsense board does not support SPI communication. So Alpha sensor can be tested alone, but not together including air/light/chemsense boards.
Since configuration data from Alpha sensor is too long (256 bytes) so that it does not fit into the sub-packet, the data seperated into four sub-packets.

Use [config.cpp](./integrated/config.cpp) to control options for the codes, such as including/excluding sensors.

To print only MAC address, make sure to turn on
```bash
#define PRINT_ADDRESS 0x01
```
in [config.cpp](./integrated/config.cpp), and comment out lines that write whole packet in [integrated.ino](./integrated/integrated.ino) (shown below).
```bach
for (byte i = 0x00; i < packet_whole[0x02] + 0x05; i++)
  SerialUSB.write(packet_whole[i]);
```

##v3.3
Include averaging some of sensors on Air/Lightsense boards.

##Tools and equipments
* each of sensor boards
* two len cables
* one micro-usb cable
