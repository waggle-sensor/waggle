# Test Scope and Coverage

This test evaluates the following aspects of Wagman system design. </br>
1.  Wagman's ability to sense heartbeats from five devices connected to it. </br>

The wagman board is designed with five multifunction ports each of which can
be used to monitor the heartbeat from an external device. Ports J6, J7 and J8
are wired for inputs at 5V logic, port J9 is wired for 3.3V logic and
port J5 is wired for 1.8V logic. J9 is designated for the C1+ board which acts
as the node controller, and J6 port is specifically designed for a XU4 board.
</br>


# Test Setup Procedure

## Test Events Timeline
* Wagman is loaded with firmware that tests the presence of heartbeats.

## Electrical Connection
*   Connect the various heartbeat lines as follows -
    -   Connect heartbeat and ground from C1+ to heartbeat (pin 3) and ground pin (pin 4) of J9 (PORT1).
    -   Connect heartbeat and ground from XU4 to heartbeat (pin 3) and ground pin (pin 4) of J5 (PORT2).
    -   Connect heartbeat and ground from LightSense to heartbeat and ground pin of J6 (PORT3).
    -   Make one of the following conections -
        -   Set a wave-generator to output square waves with a time period of 2 seconds and a 50%
            duty cycle. Connect the wave output and ground to J7 and J8.
        -   Connect pin 1 of J7 to heartbeat pin (pin 3) of J7, and similarly pin 1 of J8 to heartbeat pin (pin 3) of J8.
*   Connect micro-USB cable between Wagman's J3 and QA computer.
*   Connect 5V DC power to Wagman.

__Please make sure only the Wagman under test is connected to the QA computer. No other Wagman or Arduino Micro/derivatives can be connected at this time.__

## Testing Procedure
*  Start the test by issuing the command *make run* and follow the on-screen prompts.
__To exit the screen session created for the test, press Control+a, followed by k and y.__

## Test Log
This test is evaluated and scored on the __Wagman sensor test document__.

# Success Criteria
The test is considered __PASSED__ if all the sub-tests under the Wagman Heartbeat Test pass.

