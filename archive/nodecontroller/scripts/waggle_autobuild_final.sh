#!/bin/bash

# this script is specifically for (auto-)building images on the odroid.

set -e
set -x


# this is the device where we will build the waggle image
export CURRENT_DEVICE=$(df --output=source / | grep "^/") ; echo "CURRENT_DEVICE: ${CURRENT_DEVICE}" 
if [ ${CURRENT_DEVICE} == "/dev/mmcblk1p2" ] ; then 
  export DEVICE_NAME="mmcblk0" 
else 
  export DEVICE_NAME="mmcblk1"
fi
echo "DEVICE_NAME: ${DEVICE_NAME}"




# find device (this step is manual unless you know the device name)
# blkid -c /dev/null

# When the SD-card is connected via USB to the ODROID, the device is probably /dev/sda .
# When the SD-card is plugged into the SD-card slot (and you booted from eMMC), the devis is probably /dev/mmcblk1 .

export DEVICE=/dev/${DEVICE_NAME} ; echo "DEVICE: ${DEVICE}"

#####################################

export DEV_SUFFIX="unknown"

if [[ $DEVICE =~ ^"/dev/sd" ]] ; then
  export DEV_SUFFIX=""
fi
if [[ $DEVICE =~ ^"/dev/mmcblk" ]] ; then
  export DEV_SUFFIX="p"
fi
if [[ $DEVICE =~ ^"/dev/disk" ]] ; then
  export DEV_SUFFIX="s"
fi

if [ ${DEV_SUFFIX}x == "unknownx" ] ; then
  echo "error: Device type unknown"
  exit 1
fi

echo "DEV_SUFFIX: ${DEV_SUFFIX}"

# unmount in case it is already mounted (it might be already mounted, but with another mount point)
if [ $(df -h | grep -c ${DEVICE}${DEV_SUFFIX}2 ) == 1 ] ; then 
  while ! $(umount ${DEVICE}${DEV_SUFFIX}2) ; do sleep 3 ; done
fi

export DATE=`date +"%Y%m%d"` ; echo "DATE: ${DATE}"
export NEW_IMAGE="waggle-odroid-c1-${DATE}.img" ; echo "NEW_IMAGE: ${NEW_IMAGE}"

# extract the report.txt from the new waggle image
export WAGGLE_ROOT="/media/waggle/"
mkdir -p ${WAGGLE_ROOT}
mount ${DEVICE}${DEV_SUFFIX}2 ${WAGGLE_ROOT}
cp ${WAGGLE_ROOT}/root/report.txt ./${NEW_IMAGE}.report.txt
cp ${WAGGLE_ROOT}/root/rc.local.log ./${NEW_IMAGE}.rc.local.log

# put original rc.local inplace again
cat <<EOF > ${WAGGLE_ROOT}/etc/rc.local
#!/bin/sh -e
#
# rc.local
#
# This script is executed at the end of each multiuser runlevel.
# Make sure that the script will "exit 0" on success or any other
# value on error.
#
# In order to enable or disable this script just change the execution
# bits.
#
# By default this script does nothing.

[ ! -f /etc/ssh/ssh_host_dsa_key ]; dpkg-reconfigure openssh-server

exit 0
EOF

#get size
export FILESYSTEM_SIZE_KB=`df -BK --output=used ${DEVICE}${DEV_SUFFIX}2 | grep -o "[0-9]\+"` ; echo "FILESYSTEM_SIZE_KB: ${FILESYSTEM_SIZE_KB}"

# add 300MB
export NEW_PARTITION_SIZE_KB=$(echo "${FILESYSTEM_SIZE_KB} + (1024)*300" | bc) ; echo "NEW_PARTITION_SIZE_KB: ${NEW_PARTITION_SIZE_KB}"

if [ $(df -h | grep -c ${DEVICE}${DEV_SUFFIX}2 ) == 1 ] ; then 
  while ! $(umount ${DEVICE}${DEV_SUFFIX}2) ; do sleep 3 ; done
fi


# just for information: dumpe2fs -h ${DEVICE}${DEV_SUFFIX}2

# verify partition:
e2fsck -f -y ${DEVICE}${DEV_SUFFIX}2

# shrink filesystem (that does not shrink the partition!)
resize2fs ${DEVICE}${DEV_SUFFIX}2 ${NEW_PARTITION_SIZE_KB}K

# detect start position of second partition
export START=$(fdisk -l ${DEVICE} | grep "${DEVICE}${DEV_SUFFIX}2" | awk '{print $2}') ; echo "partition START: ${START}"

export SECTOR_SIZE=`fdisk -l ${DEVICE} | grep "Sector size" | grep -o ": [0-9]*" | grep -o "[0-9]*"` ; echo "SECTOR_SIZE: ${SECTOR_SIZE}"

export FRONT_SIZE_KB=`echo "${SECTOR_SIZE} * ${START} / 1024" | bc` ; echo "FRONT_SIZE_KB: ${FRONT_SIZE_KB}"



### fdisk (shrink partition)
# fdisk: (d)elete partition 2 ; (c)reate new partiton 2 ; specify start posirion and size of new partiton
echo -e "d\n2\nn\np\n2\n${START}\n+${NEW_PARTITION_SIZE_KB}K\nw\n" | fdisk ${DEVICE}

partprobe  ${DEVICE}

set +e
resize2fs ${DEVICE}${DEV_SUFFIX}2
set -e

# does not show the new size
fdisk -l ${DEVICE}

# shows the new size (-b for bytes)
partx --show ${DEVICE}${DEV_SUFFIX}2


e2fsck -f ${DEVICE}${DEV_SUFFIX}2

# add size of boot partition
COMBINED_SIZE_KB=`echo "${NEW_PARTITION_SIZE_KB} + ${FRONT_SIZE_KB}" | bc` ; echo "COMBINED_SIZE_KB: ${COMBINED_SIZE_KB}"

#export BLOCK_SIZE=`blockdev --getbsz ${DEVICE}`


# from kb to mb
export BLOCKS_TO_WRITE=`echo "${COMBINED_SIZE_KB}/1024" | bc` ; echo "BLOCKS_TO_WRITE: ${BLOCKS_TO_WRITE}"





dd if=${DEVICE} bs=1M count=${BLOCKS_TO_WRITE} | xz -1 --stdout - > ${NEW_IMAGE}.xz
# xz -1 creates a 560MB file in 18.5 minutes


if [ -e ./waggle-id_rsa ] ; then
  md5sum ${NEW_IMAGE}.xz > ${NEW_IMAGE}.xz.md5sum 
  scp -o "StrictHostKeyChecking no" -v -i ./waggle-id_rsa ${NEW_IMAGE}.xz ${NEW_IMAGE}.xz.md5sum waggle@terra.mcs.anl.gov:/mcs/www.mcs.anl.gov/research/projects/waggle/downloads
  
  if [ -e ${NEW_IMAGE}.report.txt ] ; then 
    scp -o "StrictHostKeyChecking no" -v -i ./waggle-id_rsa ${NEW_IMAGE}.report.txt waggle@terra.mcs.anl.gov:/mcs/www.mcs.anl.gov/research/projects/waggle/downloads
  fi
fi



###################################################

# Variant A: create archive on ODROID and push final result to remote location
# or
# Variant B: Pull disk dump from ODROID and create image archive on PC 
 


###  Variant A  ###
# on ONDROID
#  create diskdump 
#dd if=${DEVICE} of=./newimage.img bs=1M count=${BLOCKS_TO_WRITE}

# compress (xz --keep option to save space)
#xz newimage.img
#md5sum newimage.img.xz > newimage.img.xz.md5sum
#scp report.txt newimage.img.xz newimage.img.xz.md5sum <to_somewhere>

###  Variant A2  ###


###  Variant B  ###
# on your computer
#scp root@<odroid_ip>:/root/report.txt .
#ssh root@<odroid_ip> "dd if=${DEVICE} bs=1M count=${BLOCKS_TO_WRITE}" | dd of="newimage.img" bs=1m
#xz --keep newimage.img
# Linux:
#md5sum newimage.img.xz > newimage.img.xz.md5sum
# OSX:
#md5 -r newimage.img.xz > newimage.img.xz.md5sum
