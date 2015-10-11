

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

TODO: e2fsck, resize2fs, fdisk

