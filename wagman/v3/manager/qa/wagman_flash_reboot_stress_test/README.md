# Test Scope and Coverage

This test evaluates the following aspects of Wagman system design. </br>
1. Ability to sustain Odroid XU4 and C1+ under full CPU load (and hence current utilization).</br>
2. Ability to boot XU4 when C1+ is drawing maximum current.</br>
3. Ability to flash Wagman from C1+.</br>
4. Repeatability and predictability of the above.</br>
</br>

# Test Setup Procedure

This test involves a XU4, C1+ and Wagman, with the following logic programmed into each of them.

* Wagman: Firmware.
    1. Boot up.
    2. Turn off any ports that are on. There is a small delay here to allow the C1+ to gracefully shutdown after re-flashing the Wagman.
    3. Power on C1+.
    4. Power on XU4.
    5. Wait in infinite loop, flashing leds.

* C1+: init.d script which executes a shell script
    1. Start startup.sh shell script on booting using init.d stress-test script.
    2. Notify of start of stress test.
    3. Perform CPU and Disk I/O stress test for 180 seconds.
    4. Notify completion of stress test.
    5. Re-flash the wagman with the same firmware.
    6. On successful flashing, shutdown.
    7. If flashing is unsuccessful, stay on.

* XU4: init.d script which executes a shell script
    1. Start startup.sh shell script on booting using init.d stress-test script.
    2. Notify of start of stress test.
    3. Perform CPU and Disk I/O stress test for 180 seconds.
    4. Notify completion of stress test.
    5. Shutdown

### Events Timeline
* T = 0      : Wagman Boots
* Boot + 35s : Wagman turns off all the ports (if in on state earlier), including C1+
* Boot + X1s : Wagman boots C1+
* Boot + X2s : C1+ starts stress
* Boot + X3s : Wagman boots XU4
* Boot + X4s : XU4 starts stress
* Boot + X5s : C1+ finishes stress
* Boot + X6s : XU4 finishes stress
* Boot + X7s : XU4 shutsdown
* Boot + X8s : C1+ starts Wagman re-flash
* Boot + X10s : Wagman reboots
* Boot + X11s : C1+ shutsdown (if re-flash successful, else stays powered on.)
* Boot + X12s : Wagman turns off all the ports, including C1+


###Example Events Verification
* 140.221.10.98 - - [14/Mar/2016:11:25:44 -0500] "GET /flashsuccess_Wagman/node?=C1P36890 HTTP/1.1" 404 458 "-" "curl/7.35.0" </br>
__{end of previous flash}__ </br></br>
__{current cycle}__
* 140.221.10.98 - - [14/Mar/2016:11:28:01 -0500] "GET /startingstress/node?=C1P36890 HTTP/1.1" 404 453 "-" "curl/7.35.0"
* 140.221.10.98 - - [14/Mar/2016:11:29:05 -0500] "GET /startingstress/node?=XU411316 HTTP/1.1" 404 453 "-" "curl/7.35.0"
* 140.221.10.98 - - [14/Mar/2016:11:31:12 -0500] "GET /endstress/node?=C1P36890 HTTP/1.1" 404 448 "-" "curl/7.35.0"
* 140.221.10.98 - - [14/Mar/2016:11:32:16 -0500] "GET /endstress/node?=XU411316 HTTP/1.1" 404 448 "-" "curl/7.35.0"
* 140.221.10.98 - - [14/Mar/2016:11:32:27 -0500] "GET /startflash_Wagman/node?=C1P36890 HTTP/1.1" 404 456 "-" "curl/7.35.0"
* 140.221.10.98 - - [14/Mar/2016:11:32:33 -0500] "GET /endflash_Wagman/node?=C1P36890 HTTP/1.1" 404 454 "-" "curl/7.35.0"
* 140.221.10.98 - - [14/Mar/2016:11:32:33 -0500] "GET /flashsuccess_Wagman/node?=C1P36890 HTTP/1.1" 404 458 "-" "curl/7.35.0" </br>
</br>
__{start of next cycle}__
* 140.221.10.98 - - [14/Mar/2016:11:34:00 -0500] "GET /startingstress/node?=C1P36890 HTTP/1.1" 404 453 "-" "curl/7.35.0"
