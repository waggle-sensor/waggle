boot_SOS.ino
============

**boot_SOS**

|    If a non-critical internal component failed the POST, this subroutine 
|    attempts to boot enough to let the node controller inform the cloud there
|    is a problem.
|

   :returns:
      none

---------

**init_SOS**

|    Initializes/starts all necessary ports, peripherals, interrupts, etc.
|

   :returns:
      none

---------

**report_failure_POST**

|    Sends info about the POST failure to the node controller, waits for
|    the node controller to send failure info to the cloud (or until timeout),
|    then goes to sleep
|

   :returns:
      none