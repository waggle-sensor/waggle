# Test Setup Procedure

Flash the Wagman firmware using the command -  *make install* (if building for the first time) or
*make program* if flashing a pre-built firmware image. A terse explination of the Wagman firmware
logic is as follows - </br>
* Boot up.
* Turn off any ports that are on. There is a small delay here to allow the C1+ to gracefully shutdown after it has finished re-flashing the Wagman.
* Power on C1+.
* Power on XU4.
* Wait in infinite loop, flashing L and L1 debug LEDs.



