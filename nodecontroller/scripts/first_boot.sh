#!/bin/bash

if [ ! -e /root/first_boot ] ; then
  exit 0
fi

set -x

### hostname
export USE_MAC=1
export UNIQUE="undefined"
if [ ${USE_MAC} == 1 ] ; then
  export UNIQUE=`ifconfig eth0 | head -n 1 | grep -o "[[:xdigit:]:]\{17\}" | sed 's/://g'`
  if [ ! ${#UNIQUE} -ge 12 ]; then
    echo "error: could not extract MAC address"
    exit
  fi
else
  # use serial number from SD-card
  # some devices do not have a unique MAC address, they could use this code
  export CID_FILE="/sys/block/mmcblk0/device/cid"
  if [ ! -e ${CID_FILE} ] ; then 
    echo "error: File not found: ${CID_FILE}" 
    exit 1 
  fi
  export UNIQUE=`python -c "cid = '$(cat ${CID_FILE})' ; len=len(cid) ; mid=cid[:2] ; psn=cid[-14:-6] ; print mid+'_'+psn"`
  if [ ! ${#UNIQUE} -ge 11 ]; then
    echo "error: could not create unique identifier from SD-card serial number"
    exit
  fi
fi
echo waggle_${UNIQUE} > /etc/hostname

# new host keys
rm /etc/ssh/ssh_host*
dpkg-reconfigure openssh-server


rm -f /root/first_boot
