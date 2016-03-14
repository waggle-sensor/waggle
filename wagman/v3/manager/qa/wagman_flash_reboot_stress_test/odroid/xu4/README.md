# Contents

This folder contains the init.d and other scripts and files for the wagman flash reboot and stress test for the XU4. A brief
description on the execution logic follows -

* XU4: init.d script which executes a shell script
    1. Start startup.sh shell script on booting using init.d stress-test script.
    2. Notify of start of stress test.
    3. Perform CPU and Disk I/O stress test for 180 seconds.
    4. Notify completion of stress test.
    5. Shutdown
