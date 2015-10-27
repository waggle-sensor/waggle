#!/bin/bash

###
### This script should probably be run from inside the initramfs
###
AFTER_CRASH_LOG=/var/log/after-crash.log
echo "Crash detected at `date`" >> ${AFTER_CRASH_LOG}

source /etc/profile.d/custom.source

# Check File System
## Probably fsck but we need to unmount the system

# Check cpu, ram, etc
##
if [ -e ${LOCKSTEP_FILE} ]
then
    echo "Found lockstep file" >> ${AFTER_CRASH_LOG}
    /root/self-test/self_test.py --dry-run --stress-cpu
fi

/root/self-test/self_test.py --stress-cpu

# Check Networking
## Maybe use ethtool

################################################################################
# Parse collectl data

## CPU

## Network

## Disk

# Attempt to guess reason for improper shutdown

################################################################################
# Graceful degradation based on conclusion

#/use/bin/setup_cpuset.sh