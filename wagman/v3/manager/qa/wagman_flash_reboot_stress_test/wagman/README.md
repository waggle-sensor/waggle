# Test Setup Procedure

Flash the Wagman firmware using the command -  __make install__ (if building for the first time) or
__make program__ if flashing a pre-built firmware image. A terse explination of the Wagman firmware
logic is as follows - </br>
* Wagman: Firmware.
    1. Boot up.
    2. Turn off any ports that are on. There is a small delay here to allow the C1+ to gracefully shutdown after re-flashing the Wagman.
    3. Power on C1+.
    4. Power on XU4.
    5. Wait in infinite loop, flashing L and L1 debug LEDs.



