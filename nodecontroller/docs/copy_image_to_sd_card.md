
# Copy ubuntu or waggle image to SD-card

This document explains how to load an odroid **stock ubuntu image** or our **waggle image** onto an SD-card or eMMC. Please note that the image you use has to be specific for your ODROID model (e.g. C1/C1+, XU3, U, X2, X).


For our waggle image use this:
```bash
export URL="someurl"
export IMAGE="waggle.img"  (this will appear soon)
```

Alternatively, for the odroid image use this: 
```bash
export URL="http://odroid.in/ubuntu_14.04lts/"
export IMAGE="ubuntu-14.04.3lts-lubuntu-odroid-c1-20150811.img" # e.g. for the ODROID-C1 and ODROID-C1+ 
# or
export IMAGE="ubuntu-14.04.1lts-lubuntu-odroid-xu3-20150212.img" # e.g. for the ODROID-XU3
```
To find images for other ODROID models or to find newer images than those listed above, go to http://odroid.in/ubuntu_14.04lts/. When looking for an image there, choose the corresponding "ubuntu" image for your device, not the "server" or the "xubuntu" image. The environment variable IMAGE above contains the image filename without the url and without the suffix ".xz". This makes it easier to run the following commands, as they can simply be copied into a terminal without changes.

Download image:
```bash
wget ${URL}${IMAGE}.xz
wget ${URL}/${IMAGE}.xz.md5sum
```
Compare md5 checksum:
```bash
md5 ${IMAGE}.xz
cat ${IMAGE}.xz.md5sum
```

Uncompress:
```bash
unxz ${IMAGE}.xz
```

Detect SD-card device:
```bash
# Linux
df -h
# or
lsblk
# OSX
diskutil list
```

Set DEVICE_NAME variable, but do not include the path "/dev/":
```bash
# e.g. for device /dev/disk2
export DEVICE_NAME="disk2" 
```

Unmount device:
```bash
# Linux: 
umount /dev/${DEVICE_NAME}
# OSX:
sudo diskutil unmountDisk /dev/${DEVICE_NAME}
```

Copy .img-image to media (SD-card or eMMC)
```bash
# Linux:
sudo dd if=${IMAGE} of=/dev/${DEVICE_NAME} bs=1M conv=fsync
sudo sync
# OSX:
sudo dd if=${IMAGE} of=/dev/r${DEVICE_NAME} bs=1m
sudo sync
# (Use ctrl-T to see progress)
```


Eject image:
```bash
# OSX: 
sudo diskutil eject /dev/r${DEVICE_NAME}
```

Now plug SD-card into your ODROID and boot it.

Get your IP address, e.g.:
```text
ifconfig -a
```

Install nmap:
```bash
# Linux:
apt-get install nmap
# OSX:
brew install nmap
```

Find IP address of odroid device in your network:
```bash
nmap -sP <yourIP>/24 
```

ssh into your ODROID:
```bash
# waggle image:
ssh waggle@<odroid_ip>
#password: waggle

# stock ubuntu image:
ssh odroid@<odroid_ip>
#password: odroid
```



