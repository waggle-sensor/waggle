
# Copy ubuntu or waggle image to SD-card

This document explains how to load an odroid **stock ubuntu image** or our **waggle image** onto an SD-card or eMMC. Please note that the image you use has to be specific for your ODROID model (e.g. C1/C1+, XU3, U, X2, X).


For our waggle image use this:
```bash
export URL="http://www.mcs.anl.gov/research/projects/waggle/downloads/"
export IMAGE="waggle-odroid-c1-VERSION.iso"  # do not include the ".xz" suffix !
```

Alternatively, for the odroid image use this: 
```bash
export URL="http://odroid.in/ubuntu_14.04lts/"
export IMAGE="ubuntu-14.04.3lts-lubuntu-odroid-c1-20150811.img" # e.g. for the ODROID-C1 and ODROID-C1+ 
# or
export IMAGE="ubuntu-14.04.1lts-lubuntu-odroid-xu3-20150212.img" # e.g. for the ODROID-XU3
```
To find images for other ODROID models or to find newer images than those listed above, go to http://odroid.in/ubuntu_14.04lts/. When looking for an image there, choose the corresponding "ubuntu" image for your device, not the "server" or the "xubuntu" image. The environment variable IMAGE above contains the image filename without the url and without the suffix ".xz". This makes it easier to run the following commands, as they can simply be copied into a terminal without changes.

Download image (you can also use your browser to download the image):
```bash
wget ${URL}${IMAGE}.xz
wget ${URL}/${IMAGE}.xz.md5sum
```
Compare md5 checksum (this step is optional but highly recommended):
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

To ssh into your ODROID you may need to first figure out its IP address. If your computer is in the same internal network as the ODROID and you do not know the IP address, you can follow the steps below. If you have access to your router's admin page, you could also find the IP address there. In case the ODROID is not connected to a private network you might have to attach a monitor and keyboard to the ODROID.

First, get your computer's IP address, e.g.:
```text
ifconfig -a
```
or more specific:
```bash
# Linux
ifconfig -a | grep -o "inet addr:[0-9\.]\+" | grep -v 127.0.0.1 | grep -o "[0-9\.]\+"
# OSX
ifconfig -a | grep -o "inet [0-9\.]\+" | grep -v 127.0.0.1 | grep -o "[0-9\.]\+"
```
Example output:
```text
130.202.135.120   # public IP, do not use with nmap
10.10.10.120      # IP in private network, use that !
```

Your computer might have more than one IP address assigned. Make sure that for the following step you use the IP address for the local network to which the ODROID also is connected. Possible private IPv4 address spaces: 10.0.0.0 - 10.255.255.255, 172.16.0.0 - 172.31.255.255 and 192.168.0.0 - 192.168.255.255 .

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
If the output does not include hostnames, you might have a hard time to figure out which of the listed devices is your ODROID. You can point nmap to a DNS server. Assuming your IP is 10.10.10.120 and your router is acting as a DNS server with IP address 10.10.10.1, you could run nmap like this:

```bash
nmap -sP --dns-servers=10.10.10.1 10.10.10.120/24  
```

Now you should be able to ssh into your ODROID:
```bash
# waggle image:
ssh waggle@<odroid_ip>
#password: waggle

# stock ubuntu image:
ssh odroid@<odroid_ip>
#password: odroid
```



