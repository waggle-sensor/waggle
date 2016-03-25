#!/bin/bash
sleep 15
curl advaitha.pw/startingstress/node?=$(hostname)
sleep 5
stress-ng --cpu 8 --io 2 --vm 1 --vm-bytes 500M --timeout 180s --metrics-brief
sleep 5
curl advaitha.pw/endstress/node?=$(hostname)
sleep 2
shutdown -h now

