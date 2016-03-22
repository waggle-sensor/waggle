# Test Scope and Coverage

This test evaluates the following aspects of Airsense system design. </br>
* Airsense power-on.
* Airsense Atmel chip power-on and USB communication.
* Airsense's ability to read its unique ID.
* Proper functioning of on-board I2C communication bus.

</br>
# Test Setup Procedure

## Test Events Timeline
* Airsense is flashed with the test firmware and the functionality is verified.

## Electrical Connection

-   Connect Lightsense to Airsense using CAT6 cable between Lightsense's RJ45 jack and Airsense's RJ45 jack
    labeled __Light__.  </br>
<img src="./resources/RJ45AirtoLight.jpg" width="320"><img src="./resources/RJ45_Light.jpg" width="209">
-   Connect a micro USB cable between Lightsense and QA computer.
-   Connect the 4 wires between Lightsense and Wagman's Port 3 (J6). </br>
<img src="./resources/Wagman_LightSense.jpg" width="256"><img src="./resources/Light_sense_Wagman_connection.jpg" width="320">
-   Set the mode slide switch on Lightsense toward the left (closer to R1 label on the board).</br>
<img src="./resources/PowerSlideSwitchLight.jpg" width="320">


## Testing Procedure
__To exit the screen session created for the test, press Control+a, followed by k and y.__

## Test Log
This test is evaluated and scored on the __Wagman sensor test document__.

# Success Criteria
The test is considered __PASSED__ if all the sub-tests in the Initialization Test (Wagman sensor test document)
pass.
