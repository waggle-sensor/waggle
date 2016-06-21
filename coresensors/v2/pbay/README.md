This folder is for test coresensors (v2 airsense and lightsense) with the New Intel chemsense board (Jun 21, 2016).

The integrated folder contains codes for testing all sensor boards, get data, parse the data, and pack them into a packet. So the goal for the test is

* get data from all sensor boards
* parse them into designated byte format
* make sub-packets
* gather the sub-packets into a packet (a super-packet)
* parse the super-packet into human readable form using python script

Tools and equipments require are:

* each of sensor boards
* one len cable and one mini-use cable (when you do it with SerialUSB communication)
  or two len cable (when you do it with IIC communication)
* jumper lines to connect a Intel chemsense board and an airsense board
