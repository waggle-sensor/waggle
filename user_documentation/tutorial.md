# Set up waggle node
This explains how to set up a waggle node that includes wagman, nodecontroller, and extension_node.

## Parts list
A waggle node consists of following parts:

### Wagman
 * Wagman
 * Power adapter
 * MicroUSB-USB cable

### Nodecontroller
 * Odroid-C1+
 * Power cable
 * Micro SD card
 * eMMC card
 * Lan cable
 * Ethernet-USB adapter
 * Heart-beat cable
 
### Extension_node
 * Odroid-XU4
 * Power cable
 * Micro SD card
 * eMMC card
 * Heart-beat cable

### Miscellaneous
 * Micro SD-USB adapter

## Overall diagram
System diagram is depicted below. 

## Instructions on assembling
1) Connect nodecontroller's power and heart-beat cable to Wagman board. Those cables must be plugged in PORT 1 (Refer to [Wagman] (https://raw.githubusercontent.com/waggle-sensor/waggle/master/wagman/v3/resources/WagmanAnnotated.jpg)).

And then, put the power cable to nodecontroller and the heart-beat cable to PIN 3 of nodecontroller.

2) Connect extension_node's power cable and heart-beat cable to Wagman board. Those cables must be plugged in PORT 2 (Refer to [Wagman] (https://raw.githubusercontent.com/waggle-sensor/waggle/master/wagman/v3/resources/WagmanAnnotated.jpg)).

And then, put the power cable to extension_node and the heart-beat cable to PIN 3 of extension_node.

3) Connect lan cable to extension_node with nodecontroller.

4) Connect Ethernet-USB adapter to nodecontroller.

5) Connect power adapter to Wagman.

## Install softwares

### Wagman firmware installation
In order to manage nodecontroller and extension_node, Wagman has to run its management program. Download the latest firmware [here] (black:) to your computer.

Unzip the firmware:

```bash
unzip <file-name>
# if you do not have unzip, install it using sudo apt-get install unzip
```

Install avrdude to upload the firmware:

```bash
sudo apt-get install avrdude
```

Connect microUSB-USB cable to Wagman with the computer.

Run install.sh:

```bash
cd wagman_init
./install.sh
```

### Nodecontroller and extension_node firmware installation

**WARNING: before procceding the following steps, plug off wagman's the power adapter.

Follow the instruction [here] (https://github.com/waggle-sensor/waggle/blob/master/user_documentation/copy_waggle_image_to_memory_card.md) to upload the latest version of both nodecontroller and extension_node firmware. As a result, you will have two micro SD cards for both devices, respectively.

Insert each micro SD card on the designated device (nodecontroller firmware for nodecontroller and extension_node firmware for extension_node). eMMC card should also be inserted on each board.

## Waggle boot-ups
