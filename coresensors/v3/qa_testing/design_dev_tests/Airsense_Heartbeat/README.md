# Test Scope and Coverage

This test evaluates the following aspects of Airsense design. </br>
*   Airsense's ability to generate a heartbeat signal which can be sensed by Wagman. </br>

# Test Setup Procedure

## Test Events Timeline
* Wagman is loaded with firmware that tests the presence of Airsense heartbeat.
* Airsense is loaded with firmware that generates the heartbeat.

## Electrical Connection
-   Connect Lightsense to Airsense using CAT6 cable between Lightsense's RJ45 jack and Airsense's RJ45 jack
    labeled __Light__.  </br>
    <img src="./resources/RJ45AirtoLight.jpg" width="320"><img src="./resources/RJ45_Light.jpg" width="209">
-   Connect a micro USB cable between Lightsense and QA computer.
-   Connect the 4 wires (Red, Black, White and Yellow) between Lightsense and Wagman's Port 3 (J6). </br>
    <img src="./resources/Wagman_LightSense.jpg" width="256"><img src="./resources/Light_sense_Wagman_connection.jpg" width="320">
-   Set the mode slide switch on Lightsense toward the left (closer to R1 label on the board).</br>
    <img src="./resources/PowerSlideSwitchLight.jpg" width="320">
-   Connect micro-USB cable between Wagman's J3 and QA computer.
-   Connect 5V DC power to Wagman.

__Please make sure only the Wagman, Airsense and Lightsense under test are connected to the QA computer.
No other Arduino Micro and Due/derivatives can be connected at this time.__

## Testing Procedure
__The Coresense boards are powered by Wagman during the test.__</br>

*  In the Wagman folder - First issue the command *make program*.
*  On completing the above, change to the coresense folder, and issue command *make program*
*  On completing the above, change back to the Wagman folder and issue the command *make test*

__To exit the screen session created for the test, press Control+a, followed by k and y.__

## Test Log
This test is evaluated and scored on the __Coresense QA Test__ document.

# Success Criteria
The test is considered __PASSED__ if all the sub-tests under the Airsense Heartbeat Test pass.

