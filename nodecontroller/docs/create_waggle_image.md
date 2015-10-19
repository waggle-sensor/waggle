

### 1) Boot the stock odroid ubuntu image
   1. Copy ODROID ubuntu image onto SD-card, see [copy_image_to_sd_card.md](./copy_image_to_sd_card.md).
   2. Boot the ODROID with SD-card.
   3. ssh into ODROID as root ! Do not ssh as "odroid", and if you do accidentally, reboot! Otherwise the waggle script cannot rename the default user.

### 2) Download and execute create_waggle_image.sh. 
```bash
wget https://raw.githubusercontent.com/waggle-sensor/waggle/master/nodecontroller/scripts/create_waggle_image.sh
chmod +x create_waggle_image.sh
./create_waggle_image.sh
```
### 3) Shutdown
Execute "shutdown -h now". Stick SD-card in your Laptop/PC.

### 4) Shrink image

These instructions assume you shrink the image directly on the ODROID, but you can use the same instruction to shronk the image on an SD-card plugged into your computer.

After preparing the ubuntu image for waggle, we need to boot from another device (e.g. eMMC) on the ODROID to shrink the filesystem (and the partition) and to make a disk dump (dd).
```bash
# find device (this step is manual unless you know the device name)
blkid -c /dev/null

# When the SD-card is connected via USB to the ODROID, the device is probably /dev/sda .
# When the SD-card is plugged into the SD-card slot (and you booted from eMMC), the devis is probably /dev/mmcblk1 .

export DEVICE=/dev/sda

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

# unmount in case it is already mounted (it might be already mounted, but with another mount point)
if [ $(df -h | grep -c ${DEVICE}${DEV_SUFFIX}2 ) == 1 ] ; then 
  while ! $(umount ${DEVICE}${DEV_SUFFIX}2) ; do sleep 3 ; done
fi


# extract the report.txt from the new waggle image
mkdir -p /media/waggle/
mount ${DEVICE}${DEV_SUFFIX}2 /media/waggle/
cp /media/waggle/root/report.txt .

if [ $(df -h | grep -c ${DEVICE}${DEV_SUFFIX}2 ) == 1 ] ; then 
  while ! $(umount ${DEVICE}${DEV_SUFFIX}2) ; do sleep 3 ; done
fi


# just for information: dumpe2fs -h ${DEVICE}${DEV_SUFFIX}2

# verify partition:
e2fsck -f -y ${DEVICE}${DEV_SUFFIX}2

# shrink filesystem to 2GB (that does not shrink the partition!)
# compute size of second partition: 
#   200MB for the root partition
#   2024MB-200MB=1824M for the second partition that may be to conservative !)
# TODO: calculation should ideally be automated !
resize2fs ${DEVICE}${DEV_SUFFIX}2 1824m

# detect start position of second partition
export START=$(fdisk -l ${DEVICE} | grep "${DEVICE}${DEV_SUFFIX}2" | awk '{print $2}') ; echo ${START}

### fdisk (shrink partition)
# fdisk: (d)elete partition 2 ; (c)reate new partiton 2 ; specify start posirion and size of new partiton
echo -e "d\n2\nn\np\n2\n${START}\n+1824M\nw\n" | fdisk ${DEVICE}

partprobe  ${DEVICE}
#partprobe  ${DEVICE}${DEV_SUFFIX}2    needed???

### REBOOT !??!? ####
# may require reboot before we can do diskdump !?
# dd should work anyway… no need for kernel to be updated !?
# plug in again ?
resize2fs ${DEVICE}${DEV_SUFFIX}2 (not needed ?)


# Variant A: create archive on ODROID and push final result to remote location
# or
# Variant B: Pull disk dump from ODROID and create image archive on PC 

###  Variant A  ###
# on ONDROID
#  create diskdump 
dd if=${DEVICE} of=./newimage.iso bs=1M count=2000

# compress (xz --keep option to save space)
xz newimage.iso
md5sum newimage.iso.xz > newimage.iso.xz.md5sum
scp report.txt newimage.iso.xz newimage.iso.xz.md5sum <to_somewhere>

###  Variant A2  ###
dd if=${DEVICE} bs=1M count=2000 | xz --stdout - > newimage.iso.xz


###  Variant B  ###
# on your computer
scp root@<odroid_ip>:/root/report.txt .
ssh root@<odroid_ip> "dd if=${DEVICE} bs=1M count=2000" | dd of="newimage.iso" bs=1m

xz --keep newimage.iso

# Linux:
md5sum newimage.iso.xz > newimage.iso.xz.md5sum
# OSX:
md5 -r newimage.iso.xz > newimage.iso.xz.md5sum

```
