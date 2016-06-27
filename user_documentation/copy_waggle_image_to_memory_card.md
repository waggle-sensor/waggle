
# Copy waggle image to SD-card (Linux/OSX)

This document explains how to load a waggle image onto an SD-card or eMMC. These instructions are for Linux/OSX systems. If you need instructions for Windows, please contact us.

## Download

First, using a web browser, choose an image for your ODROID model (e.g. C1/C1+, XU3, U, X2, X) from our download page: 

http://www.mcs.anl.gov/research/projects/waggle/downloads/

You do not need to download the image with your browser at this point, just specify the image filename in the variable IMAGE below. The environment variable IMAGE contains the image filename without the url and without the suffix ".xz"! This makes it easier to run other commands later, as they then can simply be copied into the terminal without changes. Now paste these two lines (including your changes to the second line) into your terminal:

```bash
export URL="http://www.mcs.anl.gov/research/projects/waggle/downloads/waggle_images/nodecontroller/odroid-c1/" # for nodecontroller
export IMAGE="waggle-nodecontroller-MODEL-VERSION.img"  # do not include the ".xz" suffix !
# or
export URL="http://www.mcs.anl.gov/research/projects/waggle/downloads/waggle_images/extension_node/ODROID_MODEL" # for extensionnode
export IMAGE="waggle-guestnode-MODEL-VERSION.img"  # do not include the ".xz" suffix !
```

Alternatively, if you want to use a plain (non-waggle) odroid image: 
```bash
export URL="http://odroid.in/ubuntu_14.04lts/"
export IMAGE="ubuntu-14.04.3lts-lubuntu-odroid-c1-20151020.img" # e.g. for the ODROID-C1 and ODROID-C1+ 
# or
export IMAGE="ubuntu-14.04.1lts-lubuntu-odroid-xu3-20151020.img" # e.g. for the ODROID-XU3
```
(If you are only looking for a stock Odroid image, choose the corresponding "ubuntu" image for your device, not the "server" or the "xubuntu" image.)

To download your waggle image paste these two lines (without modifications) into your terminal:
```bash
wget ${URL}/${IMAGE}.xz
wget ${URL}/${IMAGE}.xz.md5sum
```

After we have downloaded these two files, we want to be sure that the files were correctly downloaded. For this we compare the actual md5sum of the image with the official md5sum. If both md5sum's are identical everything is ok.
```bash
# Linux
md5sum ${IMAGE}.xz > ${IMAGE}.xz.local_md5sum
# OSX
md5 -r ${IMAGE}.xz > ${IMAGE}.xz.local_md5sum

diff ${IMAGE}.xz.md5sum ${IMAGE}.xz.local_md5sum
```

Uncompress the image:
```bash
unxz ${IMAGE}.xz
```

## Write image to memory card
You can now plug your memory card (SD-card or eMMC) into your computer, either using an USB adapter or using SD-slot adapter. To figure out the correct device file corresponding to your memory card use one of the commands below:
```bash
# Linux
df -h
# or
lsblk
# OSX
diskutil list
```

Now set the DEVICE_NAME environment variable, but do not include the path "/dev/".

**WARNING: It is critical that you specify the correct device! If you specify the wrong device, you might loose data on your computer !!!!**
```bash
# e.g. for device /dev/disk2
export DEVICE_NAME="disk2"
# e.g. for device /dev/sdc with multiple partitions such as /dev/sdc1 and /dev/sdc2
export DEVICE_NAME="sdc"
```

Unmount the device:
```bash
# Linux: 
umount /dev/${DEVICE_NAME}?
# OSX:
sudo diskutil unmountDisk /dev/${DEVICE_NAME}
```

Copy image file to your memory card (SD-card or eMMC)
```bash
# Linux:
sudo dd if=${IMAGE} of=/dev/${DEVICE_NAME} bs=1M conv=fsync
sudo sync
# OSX:
sudo dd if=${IMAGE} of=/dev/r${DEVICE_NAME} bs=1m
sudo sync
# (Use ctrl-T to see progress of "dd")
```


Eject image (OSX only):
```bash
# OSX: 
sudo diskutil eject /dev/r${DEVICE_NAME}
```

You can now safely disconnect the memory card from your computer.

