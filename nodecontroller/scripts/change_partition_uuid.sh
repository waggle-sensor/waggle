#!/bin/bash

#These instructions assume there are a eMMC and an SD-card in the ODROID and jumper 1 should be used to decide from which media the ODROID boots. In my case both media had the odroid stock ubuntu image, and thus they had the same UUID’s. I booted with the SD-card and changed the UUID’s of both partitions of the eMMC.


set -e
set -x

if ! $(hash uuidgen 2>/dev/null) ; then
  apt-get update
  apt-get install -y uuid-runtime
fi

export CURRENT_DEVICE=$(df --output=source  / | grep "^/") ; echo "CURRENT_DEVICE: ${CURRENT_DEVICE}"

if [ ${CURRENT_DEVICE} == "/dev/mmcblk1p2" ] ; then
  export OTHER_DEVICE="/dev/mmcblk0"
else
  export OTHER_DEVICE="/dev/mmcblk1"
fi



export OLDUUID_2=`blkid ${OTHER_DEVICE}p2 | grep -o "[0-9a-fA-F-]\{36\}"` ; echo "OLDUUID_2: ${OLDUUID_2}"
export NEWUUID_2=`uuidgen` ; echo "NEWUUID_2: ${NEWUUID_2}"

#modify current boot.scr (just make sure it is using UUID instead of device name)
cd /media/boot
for file in boot.txt boot.ini ; do
  if [ -e ${file} ] ; then
    sed -i.bak "s/root\=[^ ]*/root=UUID=${OLDUUID_2}/" ${file}
  fi
done
# TODO: mkimage may not be needed 
#mkimage -A arm -T script -C none -n boot -d ./boot.txt boot.scr

#unmount the other partitions
set +e
umount ${OTHER_DEVICE}p1
umount ${OTHER_DEVICE}p2
set -e
sleep 2

###  change UUID on other devices
tune2fs -U ${NEWUUID_2} ${OTHER_DEVICE}p2

# the boot partition uses FAT16. To change the UUID we use dd
echo -n "abcd" | dd of=${OTHER_DEVICE}p1 bs=1 seek=39 count=4
# FAT16: (seek=39 count=4)
# FAT32: (seek=67 count=4)
# NTFS: (seek=72 count=8)

# in case /etc/fstab does not use the UUID
sed -i.bak "s/[^ ]*[ $'\t']*\/[ $'\t']/${OLDUUID_2}\t\/\t/" /etc/fstab
# verify: diff /etc/fstab /etc/fstab.bak

# fstab on other device
mkdir -p /media/other/
mount ${OTHER_DEVICE}p2 /media/other/
sed -i.bak "s/[^ ]*[ $'\t']*\/[ $'\t']/${NEWUUID_2}\t\/\t/" /media/other/etc/fstab
# verify: diff /media/other/etc/fstab /media/other/etc/fstab.bak
umount /media/other/

#boot.scr on the boot partition of the other device
mkdir -p /media/other_boot/
mount  ${OTHER_DEVICE}p1 /media/other_boot/
cd /media/other_boot/
for file in boot.txt boot.ini ; do
  if [ -e ${file} ] ; then
    sed -i.bak "s/root\=[^ ]*/root=UUID=${NEWUUID_2}/" ${file}
  fi
done
#verify: diff ./boot.ini ./boot.ini.bak
# TODO: mkimage may not be needed 
#mkimage -A arm -T script -C none -n boot -d ./boot.ini boot.scr
umount /media/other_boot/
