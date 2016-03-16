# Test Scope and Coverage

This test evaluates the following aspects of Wagman system design. </br>
*   The proper wiring of on-board sensors.
    -   HTU21D
    -   HIH4030
    -   Five Thermistors, four of which are sampled using MCP3428 A/D converter
    -   Optoresistor
*    The functioning of the on-board sensors.
</br>

# Test Setup Procedure

## Test Events Timeline
* Wagman is loaded with firmware and the sensor test is conducted.

## Electrical Connection
*  Connect micro-USB cable between Wagman's J3 and QA computer.
*  Connect 5V DC power to Wagman.

__Please make sure only the Wagman under test is connected to the QA computer. No other Wagman or Arduino Micro/derivatives can be connected at this time.__

## Testing Procedure
*   Start the test by issuing the command *make run* in the Wagman subfolder
    and follow the on-screen prompts.

    __To exit the screen session created for the test, press Control+a, followed by k and y.__

## Test Log
This test is evaluated and scored on the __Wagman sensor test document__.

# Success Criteria
The test is considered __PASSED__ if all the subtests under the Environmental Sensors Test pass.



