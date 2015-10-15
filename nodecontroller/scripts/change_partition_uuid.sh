#!/bin/bash

#These instructions assume there are a eMMC and an SD-card in the ODROID and jumper 1 should be used to decide from which media the ODROID boots. In my case both media had the odroid stock ubuntu image, and thus they had the same UUID’s. I booted with the SD-card and changed the UUID’s of both partitions of the eMMC.

# This script can go into an infinite umount loop. No timeouts implemented yet.

set -e
set -x

if ! $(hash uuidgen 2>/dev/null) ; then
  apt-get update
  apt-get install -y uuid-runtime
fi

export CURRENT_DEVICE=$(df --output=source  / | grep "^/") ; echo "CURRENT_DEVICE: ${CURRENT_DEVICE}"

if [ ${CURRENT_DEVICE} == "/dev/mmcblk1p2" ] ; then
  export CURRENT_DEVICE="/dev/mmcblk1"
  export OTHER_DEVICE="/dev/mmcblk0"
else
  export CURRENT_DEVICE="/dev/mmcblk0"
  export OTHER_DEVICE="/dev/mmcblk1"
fi



export OLDUUID_2=`blkid ${CURRENT_DEVICE}p2 | grep -o "[0-9a-fA-F-]\{36\}"` ; echo "OLDUUID_2: ${OLDUUID_2}"
export NEWUUID_1=`cat /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w 4 | head -n 1 | tr -d '\n'` ; echo "NEWUUID_1: ${NEWUUID_1}"
export NEWUUID_2=`uuidgen` ; echo "NEWUUID_2: ${NEWUUID_2}"


#modify current boot partition
if [ $(df -h | grep -c ${CURRENT_DEVICE}p1 ) == 1 ] ; then 
  while ! $(umount ${CURRENT_DEVICE}p1) ; do sleep 3 ; done
fi
sleep 1
mkdir -p /media/boot/
mount ${CURRENT_DEVICE}p1 /media/boot/
sleep 1
#modify current boot.scr (just make sure it is using UUID instead of device name)

for file in boot.txt boot.ini ; do
  if [ -e ${file} ] ; then
    sed -i.bak "s/root\=[^ ]*/root=UUID=${OLDUUID_2}/" /media/boot/${file}
  fi
done
# TODO: mkimage may not be needed 
#mkimage -A arm -T script -C none -n boot -d ./boot.txt boot.scr

#unmount the other partitions
set +e
if [ $(df -h | grep -c ${OTHER_DEVICE}p1 ) == 1 ] ; then 
  while ! $(umount ${OTHER_DEVICE}p1) ; do sleep 3 ; done
fi
if [ $(df -h | grep -c ${OTHER_DEVICE}p2 ) == 1 ] ; then 
  while ! $(umount ${OTHER_DEVICE}p2) ; do sleep 3 ; done
fi
set -e
sleep 2

###  change UUID on other devices
tune2fs -U ${NEWUUID_2} ${OTHER_DEVICE}p2

# the boot partition uses FAT16. To change the UUID we use dd
echo -n "${NEWUUID_1}" | dd of=${OTHER_DEVICE}p1 bs=1 seek=39 count=4
# FAT16: (seek=39 count=4)
# FAT32: (seek=67 count=4)
# NTFS: (seek=72 count=8)

# in case /etc/fstab does not use the UUID
sed -i.bak "s/[^ ]*[ $'\t']*\/[ $'\t']/UUID=${OLDUUID_2}\t\/\t/" /etc/fstab
# verify: diff /etc/fstab /etc/fstab.bak

# fstab on other device
mkdir -p /media/other/
mount ${OTHER_DEVICE}p2 /media/other/
sed -i.bak "s/[^ ]*[ $'\t']*\/[ $'\t']/${NEWUUID_2}\t\/\t/" /media/other/etc/fstab
# verify: diff /media/other/etc/fstab /media/other/etc/fstab.bak
set +e
while ! $(umount /media/other/) ; do sleep 3 ; done
set -e

#boot.scr on the boot partition of the other device
mkdir -p /media/other_boot/
mount ${OTHER_DEVICE}p1 /media/other_boot/
for file in boot.txt boot.ini ; do
  if [ -e ${file} ] ; then
    sed -i.bak "s/root\=[^ ]*/root=UUID=${NEWUUID_2}/" /media/other_boot/${file}
  fi
done
#verify: diff ./boot.ini ./boot.ini.bak
# TODO: mkimage may not be needed 
#mkimage -A arm -T script -C none -n boot -d /media/other_boot/boot.ini /media/other_boot/boot.scr
set +e
while ! $(umount /media/other_boot/) ; do sleep 3 ; done
set -e
