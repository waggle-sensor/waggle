This folder is for test V3 Intel Chemsense board and integrate codes for sensor boards inclusing airsense and lightsense (Jun 21, 2016).

The folder "stubs" is nothing, so please never mind. Someday it will be removed.

Coresense folder contains codes for testing chemsense board. The goal for the test is 
* get data from Chemsense board
* parse them into designated byte format
* make sub-packets
* decode the sub-packet into human reable form of information using python script

Integrated folder contains codes for testing all sensor boards, and confirming validity of packets. So the goal for the test is
* get data from all sensor boards
* parse them into designated byte format
* make sub-packets
* gather the sub-packets into a packet (or a super-packet)
* decode the super-packet into human reable form of information using python script

Tools and equipments require for the both are:
* each of sensor boards
* two len cables
* one micro-usb cable
