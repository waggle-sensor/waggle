

# Copy stock image to SD-card
This document explains how to load an odroid stock image or our waggle image onto an SD-card or eMMC.


For our waggle image use this:
```bash
export URL="someurl"
export IMAGE="waggle.img"
```

Alternatively, for the odroid image use this: 
```bash
export URL="http://odroid.in/ubuntu_14.04lts/"
export IMAGE="ubuntu-14.04.3lts-lubuntu-odroid-c1-20150811.img"
```

Download image:
```bash
wget ${URL}${IMAGE}.xz
wget ${URL}/${IMAGE}.xz.md5sum
```
Compare md5sum:
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
df -h
or
diskutil list
```

Set variable:
```bash
export DEVICE_NAME="disk2"
```

Unmount device:
```bash
Linux: umount /dev/${DEVICE_NAME}
OSX:   sudo diskutil unmountDisk /dev/${DEVICE_NAME}
```

Copy .img-image to media (SD-card or eMMC)
```bash
Linux:
sudo dd if=${IMAGE} of=/dev/${DEVICE_NAME} bs=1M conv=fsync
sudo sync
OSX:
sudo dd if=${IMAGE} of=/dev/r${DEVICE_NAME} bs=1m
sudo sync
(Use ctrl-T to see progress)
```


Eject image:
```bash
OSX: sudo diskutil eject /dev/r${DEVICE_NAME}
```

Plug SD-card into ODROID and boot it.


Get your IP address, e.g.:

```bash
ifconfig -a
```

Find IP address of odroid device in your network:
```bash
OSX: brew install nmap
Linux: apt-get install nmap
nmap -sP <yourIP>/24 
```

ssh into your ODROID (waggle image!):
```bash
TODO
```

ssh into your ODROID (odroid ubuntu image!):
```bash
ssh odroid@<ip>
# password: odroid
```



