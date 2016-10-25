


Purpose of this test is to verify that the replaced heatsink is functional, i.e. it dissipates the heat of the CPU correctly.

## Instructions

1. Insert stress-test SD-card into unpowered ODROID.
2. The XU4 boot switch must have SD-card selected. If the swicth has been replaced by three wires, short the uSD and center wire to make sure the SD-card will be booted. (Keep the wires shorted the whole time, in case of a reboot. A breadboard is helpful for this.)
3. Plug the label printer into one of USB ports on ODROID.
4. (Optional) If time keeping is required, plug a lan cable into Ethernet port on ODROID. And then, plug a battery into the battery slot.
6. Plug power connector into ODROID.
7. After 3-4 minutes one of the followings will happen:
  - Success: Label printer prints barcode label (without "ERROR")
  - Error 1: Label printer prints barcode label with "ERROR"
  - Error 2: Label printer does not print a label.
8. On success stick the new label on top of the Ethernet port of the Odroid. The barcode should go on top and the text should go to the side. The barcode should be placed entirely on the top and not folded across the edge.
9. Make sure that the Odroid is powered off by confirming ALIVE (blue) LED is off in about 10 seconds after the test. And then, unplug the power, Ethernet cable, and label printer USB cable.
