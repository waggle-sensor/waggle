#!/bin/bash

#### IMPORTANT WARNING:
#### This script was supposed to take screenshoot based on a provided number of frames per second.
#### However, this is not feasible, for high FPS number, as the required time for taking the screenshot
#### and writing the image file creates a delay that makes it impossible to meet the requested FPS number
#### 




### CONFIGURATIO VARIABLES
## Specify the amount of frame (screenshots) you want to acquire in a second; frames per second (FPS)
FRAMES_PER_SECOND=1
## Specify the output directory; default `date +%Y.%m.%d.%H.%M`
#if [ $1 ]
#then 
OUT_DIR=`date +%Y.%m.%d.%H.%M`
mkdir ${OUT_DIR}
#fi


## Compute sleep time based on FPS number
SLEEP_TIME=`echo "scale=10;1/${FRAMES_PER_SECOND}" | bc`
echo ${SLEEP_TIME}

## Initial wait before starting capturing
sleep 1

## Start capturing screenshoots
echo "[`date`] Start capturing"
F_CNT=0
while true
do
    sleep ${SLEEP_TIME}
    OUT_FILE=${OUT_DIR}/`printf "%010d" ${F_CNT}`.jpg
    echo "$OUT_FILE"
    import -window root ${OUT_FILE}
    F_CNT=$(($F_CNT+1))
done
echo "[`date`] Stop capturing"
