#!/bin/bash
sleep 40
#nmcli dev wifi connect uchicago
#sleep 60
date -s @$(curl "beehive.wa8.gl/beehive/time/epoch.txt")
#ssh -f -N -T -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no -R 45671:localhost:22 ucaot1@140.221.14.151
#sleep 20
cd /root/waggle/core/frameworks/node/nodecontroller/
./clean_dir.sh
screen -d -m python run_nc.py
cd /root/waggle/core/frameworks/node/genericnode/
./clean_dir.sh
screen -d -m python run_gm.py
sleep 600
sleep 600
sleep 600
sleep 600
sleep 600
sleep 600
sleep 600
sleep 600
sleep 600
sleep 600
shutdown -r now
