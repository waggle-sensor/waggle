#!/bin/bash

#This starts all necessary parts of the nodecontroller
cd nc-wag-os/waggled/DataCache
python Data_Cache.py start #start the Data Data_Cache
cd ..
cd Communications
./background_comms.sh #start the background_comms