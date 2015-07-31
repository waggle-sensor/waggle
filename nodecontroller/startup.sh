#!/bin/bash
#This starts all necessary parts of the nodecontroller

cd nc-wag-os/waggled/
#scan for node's IP and write to a file
python NC_scanner.py
cd DataCache/
#start the Data Data_Cache
python Data_Cache.py start 
cd ..
cd Communications/
#start the background_comms
./background_comms.sh 
