#!/bin/bash
#This starts all necessary parts of the nodecontroller

cd waggle/nodecontroller/nc-wag-os/waggled/
#scan for node's IP and write to a file
python NC_scanner.py
cd ..
cd DataCache
python Data_Cache.py start #start the Data Data_Cache
cd ..
cd Communications
./background_comms.sh #start the background_comms