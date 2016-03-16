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
    -   Connect heartbeat and ground from C1+ to heartbeat (pin 3) and ground pin (pin 4) of J9 (PORT1). Yellow is heartbeat and
        and black is ground. For more information, read [Source Code documentation](https://github.com/waggle-sensor/waggle_image/blob/master/heartbeat.sh).</br>
    <img src="./resources/C1P_heartbeat.jpg" width="320">
    -   Connect heartbeat and ground from XU4 to heartbeat (pin 3) and ground pin (pin 4) of J5 (PORT2). Yellow is heartbeat and
        and black is ground. For more information, read [Source Code documentation](https://github.com/waggle-sensor/waggle_image/blob/master/heartbeat.sh).</br>
    <img src="./resources/XU4_HBT_PINS.jpg" width="320">
    -   Connect Lightsense to Airsense using CAT6 cable between Lightsense's RJ45 jack and Airsense's RJ45 jack
        labeled __Light__.  </br>
    <img src="./resources/RJ45AirtoLight.jpg" width="320"><img src="./resources/RJ45_Light.jpg" width="209">
    -   Connect a micro USB cable between Lightsense and QA computer.
    -   Connect the 4 wires between Lightsense and Wagman's Port 3 (J6). </br>
    <img src="./resources/power_connect.jpg" width="320">
    -   Set the mode slide switch on Lightsense toward the left (closer to R1 label on the board).</br>
    <img src="./resources/PowerSlideSwitchLight.jpg" width="320">
    -   Make one of the following conections -
        -   Set a wave-generator to output square waves with a time period of 2 seconds and a 50%
            duty cycle. Connect the wave output and ground to J7 and J8.
        -   Connect pin 1 of J7 to heartbeat pin (pin 3) of J7, and similarly pin 1 of J8 to heartbeat pin (pin 3) of J8.</br>
        <img src="./resources/Short_PIN3_PIN1.jpg" width="320">
*   Connect micro-USB cable between Wagman's J3 and QA computer.
*   Connect 5V DC power to Wagman.

__Please make sure only the Wagman under test is connected to the QA computer. No other Wagman or Arduino Micro/derivatives can be connected at this time.__

## Testing Procedure
__Only the Coresense boards are powered by Wagman during the test.__</br>
__The Odroids XU4 and C1P have to be powered on independently.__</br>

*  In the Wagman folder - First issue the command *make install*.
*  On completing the above, change to the coresense folder, and issue command *make install*
*  On completing the above, change back to the Wagman folder and issue the command *make test*

__To exit the screen session created for the test, press Control+a, followed by k and y.__

## Test Log
This test is evaluated and scored on the __Wagman sensor test document__.

# Success Criteria
The test is considered __PASSED__ if all the sub-tests under the Wagman Heartbeat Test pass.

