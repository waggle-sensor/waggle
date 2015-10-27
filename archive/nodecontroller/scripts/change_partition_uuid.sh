#!/bin/bash
set -e
set -x

# Do not try to change the UUID's of partitions of eMMC or SD-cards plugged into their native odroid slot. 
# If you want to use an odroid for this, connect the memory via USB-adapter (e.g. device /dev/sda ).

export OTHER_DEVICE="/dev/sda"


if ! $(hash uuidgen 2>/dev/null) ; then
  apt-get update
  apt-get install -y uuid-runtime
fi

export NEWUUID_1=`cat /dev/urandom | tr -dc 'A-Z0-9' | fold -w 4 | head -n 1 | tr -d '\n'` ; echo "NEWUUID_1: ${NEWUUID_1}"
export NEWUUID_2=`uuidgen` ; echo "NEWUUID_2: ${NEWUUID_2}"

# turn ASCII into HEX representation, eg: "5A51-334D"
export NEWUUID_1_HEX=`echo -n "${NEWUUID_1}" | od -t x2 | head -n 1 | sed "s/^0000000 \([^ ]*\) \([^ ]*\)/\2-\1/" | tr '[a-z]' '[A-Z]' | tr -d '\n'` ; echo "NEWUUID_1_HEX: ${NEWUUID_1_HEX}"



#unmount the other partitions
set +e
if [ $(df -h | grep -c ${OTHER_DEVICE}1 ) == 1 ] ; then 
  while ! $(umount ${OTHER_DEVICE}1) ; do sleep 3 ; done
fi
if [ $(df -h | grep -c ${OTHER_DEVICE}2 ) == 1 ] ; then 
  while ! $(umount ${OTHER_DEVICE}2) ; do sleep 3 ; done
fi
set -e
sleep 2

###  change UUID on other devices
tune2fs -U ${NEWUUID_2} ${OTHER_DEVICE}2

# the boot partition uses FAT16. To change the UUID we use dd
echo -n "${NEWUUID_1}" | dd of=${OTHER_DEVICE}1 bs=1 seek=39 count=4
# FAT16: (seek=39 count=4)
# FAT32: (seek=67 count=4)
# NTFS: (seek=72 count=8)


# fstab on other device
mkdir -p /media/other/
mount ${OTHER_DEVICE}2 /media/other/
sed -i.bak -e "s/[^ ]*[ $'\t']*\/[ $'\t']/UUID=${NEWUUID_2}\t\/\t/" \
           -e "s/[^ ]*[ $'\t']*\/media\/boot[ $'\t']/UUID=${NEWUUID_1_HEX}\t\/media\/boot\t/" /media/other/etc/fstab
# verify: diff /media/other/etc/fstab /media/other/etc/fstab.bak
set +e
while ! $(umount /media/other/) ; do sleep 3 ; done
set -e

#boot.scr on the boot partition of the other device
mkdir -p /media/other_boot/
mount ${OTHER_DEVICE}1 /media/other_boot/
for file in boot.txt boot.ini ; do
  if [ -e /media/other_boot/${file} ] ; then
    sed -i.bak -e "s/root\=[^ ]*/root=UUID=${NEWUUID_2}/" /media/other_boot/${file}
  fi
done
#verify: diff ./boot.ini ./boot.ini.bak
# TODO: mkimage may not be needed 
#mkimage -A arm -T script -C none -n boot -d /media/other_boot/boot.ini /media/other_boot/boot.scr
set +e
while ! $(umount /media/other_boot/) ; do sleep 3 ; done


#maybe needed
#fix boot partition
#dosfsck -t -a -w  /dev/mmcblk1p1
