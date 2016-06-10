This folder is for test Chemsense board and integrate codes for sensor boards inclusing airsense and lightsense.

Coresense folder contains codes for testing chemsense board. The goal for the test is 
* get data from Chemsense board
* parse them into designated byte format
* make sub-packets

Integrated folder contains codes for testing all sensor boards, and confirming validity of packets. So the goal for the test is
* get data from all sensor boards
* parse them into designated byte format
* make sub-packets
* gather the sub-packets into a packet (or a super-packet)
* decode the super-packet into human reable form of information using python script
