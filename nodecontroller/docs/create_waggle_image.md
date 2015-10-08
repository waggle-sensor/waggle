

1) Copy ODROID ubuntu image onto SD-card, boot the ODROID and ssh into it as root. Follow these instructions: [copy_image_to_sd_card.md](./copy_image_to_sd_card.md)

2) Download and execute create_waggle_image.sh.
```bash
wget https://raw.githubusercontent.com/waggle-sensor/waggle/master/nodecontroller/scripts/create_waggle_image.sh
chmod +x create_waggle_image.sh
./create_waggle_image.sh
```

3) deploy first_boot.sh
```bash
wget https://raw.githubusercontent.com/waggle-sensor/waggle/master/nodecontroller/scripts/first_boot.sh
chmod +x first_boot.sh
```

# Shrink image

TODO: e2fsck, resize2fs, fdisk

