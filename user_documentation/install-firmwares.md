# Install softwares

## Wagman firmware installation
In order to manage nodecontroller and extension_node, wagman has to run its management program. Download the latest firmware [here](http://www.mcs.anl.gov/research/projects/waggle/downloads/Wagman/wagman_init_20150517.zip) to your computer.

Unzip the firmware:

```bash
unzip <file-name>
# if you do not have unzip, install it using sudo apt-get install unzip
```

Install avrdude to upload the firmware:

```bash
sudo apt-get install avrdude
```

Connect microUSB-USB cable to wagman with the computer. </br>
<img src="./pictures/Wire_wagman_firmware_update.JPG" width=400 /> </br>

Run install.sh:

```bash
cd wagman_init
./install.sh
```

## Nodecontroller and extension_node firmware installation

**WARNING: before procceding the following steps, plug off wagman's power adapter.

Follow the instruction [here](https://github.com/waggle-sensor/waggle/blob/master/user_documentation/copy_waggle_image_to_memory_card.md) to upload the latest version of both nodecontroller and extension_node firmware. As a result, you will have two micro SD cards for both devices, respectively.

Insert each micro SD card on the designated device (nodecontroller firmware for nodecontroller and extension_node firmware for extension_node). eMMC card should also be inserted on both devices.

Next step: [Waggle boot-ups](./waggle-boot-ups.md)
