
# Manually 
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

Use the steps in this script. (TODO: create separate shrink_image script !)
https://github.com/waggle-sensor/waggle/blob/master/nodecontroller/scripts/waggle_autobuild_final.sh



## Auto-build setup
This approach is used to automatically create the waggle production images.

The waggle image auto-build setup requires a “master” and a “slave” memory device on the odroid. The master device can run a normal ubuntu image and the slave device is used to create the waggle image. Default operation mode is the master device. The master will copy a clean ubuntu image onto the slave and create init scripts on the slave. 
Then the boot order needs to be changed. This can be done either manually (switching jumper 1) or by using Wagman. In both cases the boot order has to be switched to slave-master and the odroid had to be turned off and on again to let the slave prepare the waggle image. Once the slave has finished, Wagman (or the user) will invoke a reboot and the master memory device takes over control again. The master can make small modifications to the waggle image, shrink the partition and upload the final waggle image. 

#First time starting from the master

The master memory device needs to be prepared a bit. You may need to resize the partition and file system and you may have to change its UUID. The UUID has to be different from the UUID of the slave!

Copy image to memory:
https://github.com/waggle-sensor/waggle/blob/master/nodecontroller/docs/copy_image_to_sd_card.md

Change its UUID: (Do that before you boot from the master!)
https://github.com/waggle-sensor/waggle/blob/master/nodecontroller/scripts/change_partition_uuid.sh


In case you are not sure from what device you are booting from
```bash
cat /sys/block/$(df / | grep -o "mmcblk[0-9]")/device/uevent | grep "MMC_TYPE" | cut -d '=' -f 2
```

Resize filesystem and partition
```bash
source /usr/local/bin/fs_resize.sh ; resize_p2
# or if file not found
wget https://raw.githubusercontent.com/waggle-sensor/waggle/master/nodecontroller/scripts/resize.sh
chmod +x resize.sh
./resize.sh
```
and execute this script another time after booting

Change resolution (for the stock ubuntu image)
```bash
sed -i.bak -e "s/^setenv m /# setenv m/" -e "s/# setenv m \"1440x900p60hz\"/setenv m \"1440x900p60hz\"/" ./boot.ini
```

Copy private ssh key to /root/waggle-id_rsa
```bash
chmod 600 /root/waggle-id_rsa
```

# Init step
```bash
wget https://raw.githubusercontent.com/waggle-sensor/waggle/master/nodecontroller/scripts/waggle_autobuild_init.sh
chmod +x waggle_autobuild_init.sh
./waggle_autobuild_init.sh
```

Reboot with slave-master boot order !

Let slave build waggle image.

Reboot with master-slave boot order !

# Final step
```bash
wget https://raw.githubusercontent.com/waggle-sensor/waggle/master/nodecontroller/scripts/waggle_autobuild_final.sh
chmod +x waggle_autobuild_final.sh
```
