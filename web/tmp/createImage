
Users of waggle should not need to build the waggle image on their own, but if they want to, here are the instructions to do that (see Section "Manually"). Further below there are also instructions on how to do automatic (e.g. nightly) waggle image builds. Those instructions are mostly of interest to the waggle team itself.


# Manually 
### 1) Boot the stock odroid ubuntu image
   1. Copy ODROID ubuntu image onto SD-card, see [copy_waggle_image_to_memory_card.md](https://github.com/waggle-sensor/waggle/blob/master/user_documentation/copy_waggle_image_to_memory_card.md).
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

Use the steps in this script. (TODO: create separate shrink_image script !)
https://github.com/waggle-sensor/waggle/blob/master/nodecontroller/scripts/waggle_autobuild_final.sh



# Auto-build setup
This approach is used to automatically create the waggle production images.

The waggle image auto-build setup requires a “master” and a “slave” memory device on the odroid. The master device can run a normal ubuntu image and the slave device (e.g. a USB stick) is used to create the waggle image. Default operation mode is the master device. The master will copy a clean ubuntu image onto the slave and create init scripts on the slave. Then the boot partition of the master will be modified to boot into the root partition of the slave.


### First time starting from the master

You may have to resize filesystem and partition of the master first to have enough space to store the disk images:
```bash
source /usr/local/bin/fs_resize.sh ; resize_p2
# or if file not found
wget https://raw.githubusercontent.com/waggle-sensor/waggle/master/nodecontroller/scripts/resize.sh
chmod +x resize.sh
./resize.sh
```

In case you are not sure what device you just booted from
```bash
cat /sys/block/$(df / | grep -o "mmcblk[0-9]")/device/uevent | grep "MMC_TYPE" | cut -d '=' -f 2
```

In case you use a monitor with the ODROID and you have to change resolution (e.g. for the stock ubuntu image)
```bash
sed -i.bak -e "s/^setenv m /# setenv m/" -e "s/# setenv m \"1440x900p60hz\"/setenv m \"1440x900p60hz\"/" ./boot.ini
```

Clone the nodecontroller repository:
```bash
git clone https://github.com/waggle-sensor/nodecontroller.git
```

Only for the waggle team: Copy private ssh key to /root/waggle-id_rsa and set correct permissions. The script will automatically upload the new waggle image to our download server.
```bash
chmod 600 /root/waggle-id_rsa
```

### Init step
This script will download an ubuntu image, write it to the slave memory device and modify the boot partition of the master device. It will also deploy some init scripts so that the waggle images can be build once the slave starts. Run the script without arguments to get a list of available devices.

```bash
cd nodecontroller/scripts
./waggle_autobuild_init.sh <device>
```

Reboot to let the slave create the waggle image. It will automaticall reboot the master afterwards.
```bash
reboot ; exit
```


### Final step
This script will copy some log files out of the new waggle image, do some clean-up, and shrink filesystem and partition, copy the new image into a file amd compress it. (Note for waggle team members: if you copied the waggle-id_rsa, this script will also upload the image to the waggle download server.)
```bash
./waggle_autobuild_final.sh <device>
```
