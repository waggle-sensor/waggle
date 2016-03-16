# Test Scope and Coverage

This test evaluates the following aspects of Wagman system design. </br>
1. Wagman power-on.</br>
2. Wagman Atmel chip power-on and communication - including boot loader flashing and USB communication.</br>
3. Proper functioning of on-board I2C communication bus </br>
4. Wagman's ability to read its unique ID. </br>
5. Wagman's ability to provide visual feedback to tester using two LEDs whose brightness levels can be controlled. </br>
</br>

# Test Setup Procedure

## Test Events Timeline
* Phase 1: Wagman is flashed with bootloader using Atmel AVRISP mkII.
* Phase 2: Wagman is loaded with firmware that tests on-board communication and debug LEDs.

## Electrical Connection
*  Connect micro-USB cable between Wagman's J3 and QA computer.
*  Connect 5V DC power to Wagman using J10. Follow __Wagman Connection Guide__ for polarity details.
*  For bootloader flashing connect the Atmel AVRISP mkII to the J2 of Wagman.

## Testing Procedure
*   Power on Wagman by connecting the 5V DC power as shown in figure below. Red is +5V and Black is ground. </br>
<img src="./resources/power_connect.jpg" width="320">
*   Check if the Yellow "ON" LED lights up. The L and L1 debug LEDs are to the left of the ON LED. </br>
<img src="./resources/coin_cell_battery_debug_LED.jpg" width="320">
*   Connect the Atmel AVRISP mkII to the QA computer and connect it to J2 of
    Wagman as shown below. </br>
<img src="./resources/avrisp_connect.jpg" width="320">
*   Program the Arduino bootloader for Arduino micro board.
    - On the Arduino GUI (Version 1.6.7), choose the Arduino Micro board. </br>
<img src="./resources/micro_board_select.jpg" width="320">
    - Choose the AVRISP mkII programmer. </br>
<img src="./resources/bootloader_type_select.jpg" width="320">
    - Burn the bootloader. </br>
<img src="./resources/burn_bootloader.jpg" width="320">

*   On completion of the above step, connect the board to the QA computer using a micro-USB cable.
    __Please make sure only the Wagman under test is connected to the QA computer. No other Wagman or
    Arduino Micro/derivatives can be connected at this time.__

*   Initialize the Wagman by issuing the command *make run* in the Wagman subfolder
    and follow the on-screen prompts.

    __To exit the screen session created for the test, press Control+a, followed by k and y.__

## Test Log
This test is evaluated and scored on the __Wagman sensor test document__.

# Success Criteria
The test is considered __PASSED__ if all the sub-tests in the Initialization Test (Wagman sensor test document)
pass.
