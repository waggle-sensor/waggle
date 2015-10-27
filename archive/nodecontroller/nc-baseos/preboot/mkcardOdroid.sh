#! /bin/sh
# mkcard.sh v0.5
# (c) Copyright 2009 Graeme Gregory <dp@xora.org.uk>
# Licensed under terms of GPLv2
#
# Parts of the procudure base on the work of Denys Dmytriyenko
# http://wiki.omap.com/index.php/MMC_Boot_Format

export LC_ALL=C

if [ -z `which bc` ]; then
	echo "no bc binary found"
	exit 1;
fi

if [ $# -ne 1 ]; then
	echo "Usage: $0 <drive>"
	exit 1;
fi

DRIVE=$1

###
### Clear out the first 10M Bytes of the SD-Card
###
## if: read from FILE instead of stdin
## of:  write to FILE instead of stdout
## bs: read and write up to BYTES bytes at a time
## count: copy only BLOCKS input blocks

dd if=/dev/zero of=$DRIVE bs=1M count=10

### Obtain size of SD-Card in bytes
SIZE=`fdisk -l $DRIVE | grep Disk | grep bytes | awk '{print $5}'`

echo DISK SIZE - $SIZE bytes

### Compute number of cylinders
CYLINDERS=`echo $SIZE/255/63/512 | bc`

echo CYLINDERS - $CYLINDERS

set -x

{
echo 1,9,0x0C,*
echo 10,,,-
} | sfdisk -D -H 255 -S 63 -C $CYLINDERS $DRIVE

sleep 1

if [ -b ${DRIVE}1 ]; then
	umount ${DRIVE}1
#	mkfs.vfat -F 32 -n "boot" ${DRIVE}1
    mkfs.ext4 -L "boot" ${DRIVE}1
else
	if [ -b ${DRIVE}p1 ]; then
		umount ${DRIVE}p1
#		mkfs.vfat -F 32 -n "boot" ${DRIVE}p1
		mkfs.ext4 -j -L "boot" ${DRIVE}p1
	else
		echo "Cant find boot partition in /dev"
	fi
fi

if [ -b ${DRIVE}2 ]; then
	umount ${DRIVE}2
	mkfs.ext4 -L "rootfs" ${DRIVE}2
else
	if [ -b ${DRIVE}p2 ]; then
		umount ${DRIVE}p2
		mkfs.ext4 -j -L "rootfs" ${DRIVE}p2
	else
		echo "Cant find rootfs partition in /dev"
	fi
fi

