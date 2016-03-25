# Contents

This folder contains the __stresstest__ (init.d) and other scripts and files for the wagman flash reboot and stress test for the XU4. A brief
description on the execution logic follows -
* Start startup.sh shell script on booting using init.d stress-test script.
* Notify of the start of stress test.
* Perform CPU and Disk I/O stress test for 180 seconds.
* Notify completion of stress test.
* Shutdown
