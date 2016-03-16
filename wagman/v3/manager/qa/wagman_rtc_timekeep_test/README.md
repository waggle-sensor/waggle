# Test Scope and Coverage

This test evaluates the following aspects of Wagman system design. </br>
1. Wagman's ability to keep time when power is disconnected. </br>
</br>

# Test Setup Procedure

## Test Events Timeline
* Phase 1: Wagman is loaded with firmware that sets the RTC clock.
* Phase 2: Wagman is loaded with firmware that tests the RTC clock.

## Electrical Connection
*  Insert CR 3020 battery into Wagman.
*  Connect micro-USB cable between Wagman's J3 and QA computer.
*  Connect 5V DC power to Wagman using J10. Follow __Wagman Connection Guide__ for polarity details.

## Testing Procedure
*  Initialize the Wagman RTC by issuing command *make initialize* in the Wagman subfolder.
*  After initializing the board, unplug USB and Power to Wagman.
*  After 30 seconds, power the Wagman back up and plug the USB cable into it.
*  Continue with the test by issuing the command *make test* and follow the on-screen prompts.

## Test Log
This test is evaluated and scored on the __Wagman sensor test document__.

# Success Criteria
The test is considered __PASSED__ if the time printed increments in successive prints.

