#!/bin/bash
sleep 15
curl advaitha.pw/startingstress/node?=$(hostname)
sleep 5
stress-ng --cpu 4 --io 2 --vm 1 --vm-bytes 500M --timeout 180s --metrics-brief
sleep 5
curl advaitha.pw/endstress/node?=$(hostname)
sleep 75
curl advaitha.pw/startflash_Wagman/node?=$(hostname)
touch /root/bin/log_file.txt
echo $(date) >> /root/bin/log_file.txt
cd /root/bin/
make program
echo "***********" >> /root/bin/log_file.txt
curl advaitha.pw/endflash_Wagman/node?=$(hostname)
programmed=`(cat flash_avr.log | grep "verifi" | wc -l)`
mv flash_avr.log flash_avr$(date +%s).log
if [ $programmed -gt "0" ]
then
    curl advaitha.pw/flashsuccess_Wagman/node?=$(hostname)
    sleep 2
    shutdown -h now
else
    curl advaitha.pw/flasherror_Wagman/node?=$(hostname)
    sleep 2
fi
