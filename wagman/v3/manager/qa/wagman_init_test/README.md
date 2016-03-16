# Test Scope and Coverage

This test evaluates the following aspects of Wagman system design. </br>
1. Wagman power-on.
2. Wagman Atmel chip power-on and communication - including boot loader flashing and USB communication.
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
*   Power on Wagman by connecting the 5V DC power as shown in figure below.
*   Check if the Yellow "ON" LED lights up.
*   Connect the Atmel AVRISP mkII to the QA computer and connect it to J2 of
    Wagman as shown below.
*   Program the Arduino bootloader for Arduino micro board.
    - On the Arduino GUI (Version 1.6.7), choose the Arduino Micro board.
    - Choose the AVRISP mkII programmer.
    - Burn the bootloader.

*   On completion of the above step, connect the board to the QA computer using a micro-USB cable.
    __Please make sure only the Wagman under test is connected to the QA computer. No other Wagman or
    Arduino Micro/derivatives can be connected at this time.__

*   Initialize the Wagman by issuing the command *make initialize* in the Wagman subfolder
    and follow the on-screen prompts.

## Test Log
This test is evaluated and scored on the __Wagman sensor test document__.

# Success Criteria
The test is considered __PASSED__ if all the sub-tests in the Initialization test (Wagman sensor test document)
pass.
