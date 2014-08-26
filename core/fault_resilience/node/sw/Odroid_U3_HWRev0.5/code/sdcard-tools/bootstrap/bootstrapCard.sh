#!/bin/bash


###
### This script should completely automate the process of generating a basic SD-Card installation
###


DRIVE=$1

MK_CARD_DIR=/digital/g/projects/forest/getziadz/code/sdcardTools/mkcard
MK_CARD_SCRIPT=${MK_CARD_DIR}/mkcardOdroid.sh

## Format SD-Card
${MK_CARD_SCRIPT} ${DRIVE}

## Flash signed U-Boot
UB_FLASH_DIR=/digital/g/projects/forest/getziadz/code/sdcardTools/odroidSingedUBoot
UB_FLASH_SCRIPT=${UB_FLASH_DIR}/sd_fusing.sh

${UB_FLASH_CARD_SCRIPT} ${DRIVE}

## Copy rootfs

ROOTFS_SRC_DIR=

cp -r ${ROOTFS_SRC_DIR} /media/rootfs/

## Copy kernel

KERNEL_DIR=

make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- modules_install INSTALL_MOD_PATH=/media/rootfs/
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- firmware_install INSTALL_FW_PATH=/media/rootfs/lib/firmware

sudo cp .config /media/rootfs/boot/config-`cat ./include/config/kernel.release`
sudo cp .config /media/boot/config-`cat ./include/config/kernel.release`

cp arch/arm/boot/zImage /media/boot/

## Generate and copy Initramfs

## Configure ethernet