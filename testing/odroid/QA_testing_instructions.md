


Purpose of this test is to verify that the replaced heatsink is functional, i.e. it dissipates the heat of the CPU correctly.

## Instructions

1. Insert stress-test SD-card into unpowered ODROID.
2. The XU4 boot switch must have SD-card selected. If the swicth has been replaced by three wires, short the uSD and center wire to make sure the SD-card will be booted. (Keep the wires shorted the whole time, in case of a reboot. A breadboard is helpful for this.)
3. Plug the label printer into one of USB ports on ODROID.
4. Plug power connector into ODROID.
5. After 3-4 minutes one of the followings will happen:
  - Success: Label printer prints barcode label (without "ERR" or "FAILED")
  - Error 1: Label printer prints barcode label with "ERRxxx", where xxx indicates error code
  - Error 2: Label printer prints barcode label with "FAILED" which means that the error is unknown.
6. On success stick the new label on top of the Ethernet port of the Odroid. The barcode should go on top and the text should go to the side. The barcode should be placed entirely on the top and not folded across the edge.
7. Make sure that the Odroid is powered off by confirming ALIVE (blue) LED is off in about 10 seconds after the test. And then, unplug the power and label printer USB cable.

## Error codes

If you see one of the following numbers (along with ERR) on QR code sticker underneath the MAC address, then the stress test has failed with the corresponding reason.

* 404: No model name found
* 405: Model name is unknown
* 500x: Stress-test failed; the number x is one of the followings:
       1: Error; incorrect user options or a fatal resource issue in the stress-ng stressor harness (for example, out of memory).
       2: One or more stressors failed.
       3: One or more stressors failed to initialise because of lack of resources, for example ENOMEM (no memory) and ENOSPC (no space on file system).
* 600: Stress-test result not found
* 900: Unknown error
