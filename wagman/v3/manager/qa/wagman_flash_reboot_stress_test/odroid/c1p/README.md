# Contents

This folder contains the init.d and other scripts and files for the wagman flash reboot and stress test for the C1+. A brief
description on the execution logic follows -

* C1+: init.d script which executes a shell script
    1. Start startup.sh shell script on booting using init.d stress-test script.
    2. Notify of start of stress test.
    3. Perform CPU and Disk I/O stress test for 180 seconds.
    4. Notify completion of stress test.
    5. Re-flash the wagman with the same firmware.
    6. On successful flashing, shutdown.
    7. If flashing is unsuccessful, stay on.
