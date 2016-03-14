# Test Setup Procedure

The XU4 and C1+ folders here each contain an init.d script and a bin folder. To set up the Odroids for the
test, please follow the instructions below. </br>
* On a new Waggle Odroid device, copy stresstest file into /etc/init.d folder
* Copy bin folder into /root/
* Change execute flag for startup.sh and stresstest by using commands - *chmod +x /root/bin/startup.sh* and *chmod +x /etc/init.d/stresstest*
* Add init hooks using command - *update-rc.d stresstest defaults 99*
* shutdown the device.

