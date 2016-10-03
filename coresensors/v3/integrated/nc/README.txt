To update coresense firmware with binary file,
put the bin folder in this folder and,
DO:
$ make program

The bin is coresense version 3.2 (Aug 4th, 2016)
* can detect if the chemsense board is disconnected from the first time or in the middle of the performing
* send a heartbeat signal every second
* send a packet every 24 seconds
* alpha sensor is not included in the packet data
* some of temperature is converted to human readable and packetized, but other data are raw integer
