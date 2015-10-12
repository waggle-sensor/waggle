

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


# extract the report.txt from the new waggle image
mkdir -p /media/waggle/
mount ${DEVICE}2 /media/waggle/
cp /media/waggle/root/report.txt .
umount /media/waggle/

# just for information: dumpe2fs -h ${DEVICE}2

# verify partition:
e2fsck -f ${DEVICE}2

# shrink filesystem to 2GB (that does not shrink the partition!)
# compute size of second partition: 
#   200MB for the root partition
#   2024MB-200MB=1824M for the second partition that may be to conservative !)
# TODO: calculation should ideally be automated !
resize2fs ${DEVICE}2 1824m

# detect start position of second partition
export START=$(fdisk -l ${DEVICE} | grep "${DEVICE}2" ) | awk '{print $2}'; echo ${START}

### fdisk (shrink partition)
# fdisk: (d)elete partition 2 ; (c)reate new partiton 2 ; specify start posirion and size of new partiton
echo -e "d\n2\nn\np\n2\n${START}\n+1824M\nw\n" | fdisk ${DEVICE}

partprobe  ${DEVICE}
#partprobe  ${DEVICE}2    needed???

### REBOOT !??!? ####
# may require reboot before we can do diskdump !?
# dd should work anyway… no need for kernel to be updated !?
# plug in again ?
resize2fs ${DEVICE}2 (not needed ?)


# create diskdump (either locally or directly scp disk dump to remote location)
dd if=/dev/sda of=./newimage.iso bs=1M count=2000


# compress image xv or gzip ?

Linux:
md5sum <file> > <file>.md5sum
OSX:
md5 -r <file> > <file>.md5sum


#On your laptop
#scp root@192.168.1.13:/root/report.txt .
#ssh root@192.168.1.13 "dd if=/dev/sda bs=1M count=2000" | dd of="newimage.iso" bs=1m

```
