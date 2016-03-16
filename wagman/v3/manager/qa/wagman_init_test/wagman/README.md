## Testing Procedure
*   Power on Wagman by connecting the 5V DC power as shown in figure below. Red is +5V and Black is ground. </br>
<img src="../resources/power_connect.jpg" width="320">
*   Check if the Yellow "ON" LED lights up. The L and L1 debug LEDs are to the left of the ON LED. </br>
<img src="../resources/coin_cell_battery_debug_LED.jpg" width="320">
*   Connect the Atmel AVRISP mkII to the QA computer and connect it to J2 of
    Wagman as shown below. </br>
<img src="../resources/avrisp_connect.jpg" width="320">
*   Program the Arduino bootloader for Arduino micro board.
    - On the Arduino GUI (Version 1.6.7), choose the Arduino Micro board. </br>
<img src="../resources/micro_board_select.jpg" width="320">
    - Choose the AVRISP mkII programmer. </br>
<img src="../resources/bootloader_type_select.jpg" width="320">
    - Burn the bootloader. </br>
<img src="../resources/burn_bootloader.jpg" width="320">

*   On completion of the above step, connect the board to the QA computer using a micro-USB cable.
    __Please make sure only the Wagman under test is connected to the QA computer. No other Wagman or
    Arduino Micro/derivatives can be connected at this time.__

*   Initialize the Wagman by issuing the command *make initialize* in the Wagman subfolder
    and follow the on-screen prompts.
