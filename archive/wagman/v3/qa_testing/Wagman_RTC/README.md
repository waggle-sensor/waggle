# Test Scope and Coverage

This test evaluates the following aspects of Wagman system design. </br>
1.  Proper functioning of the RTC circuitry.</br>
2.  Wagman's ability to keep time when the main 5V power is disconnected. </br>
</br>

# Test Setup Procedure

## Test Events Timeline
* Phase 1: Wagman is loaded with firmware that sets the RTC clock.
* Phase 2: Wagman is loaded with firmware that tests the RTC clock.

## Electrical Connection
*  Insert CR 3020 battery into Wagman. The +ve of the battery should face up, and -ve should press against the board.</br>
<img src="./resources/coin_cell_battery_debug_LED.jpg" width="320">
*  Connect micro-USB cable between Wagman's J3 and QA computer.
*  Connect 5V DC power to Wagman.

__Please make sure only the Wagman under test is connected to the QA computer. No other Wagman or Arduino Micro/derivatives can be connected at this time.__
## Testing Procedure
*  Initialize the Wagman RTC by issuing command *make program* in the Wagman subfolder.
*  After initializing the board, unplug USB and Power to Wagman.
*  After 30 seconds, power the Wagman back up and plug the USB cable into it.
*  Continue with the test by issuing the command *make test* and follow the on-screen prompts.
__To exit the screen session created for the test, press Control+a, followed by k and y.__

## Test Log
This test is evaluated and scored on the __Wagman QA Scoresheet__.

# Success Criteria
The test is considered __PASSED__ if the time printed increments in successive prints.

