# Test Scope and Coverage

This test evaluates the following aspects of Airsense system design. </br>
* Airsense power-on.
* Airsense Atmel chip power-on and USB communication.
* Airsense's ability to read its unique ID.
* Proper functioning of on-board I2C communication bus.

</br>
# Test Setup Proceduere

## Test Events Timeline
* Visual inspection is performed on the Airsense board.
* Airsense is flashed with the test firmware and the functionality is verified under 3 different setups. 

## Electrical Connection

* Setup 1: Airsense and Lightsense powered over USB through Lightsense.

    -   Connect Lightsense to Airsense using CAT6 cable between Lightsense's RJ45 jack and Airsense's RJ45 jack
    labeled __Light__.  </br>
    <img src="./resources/RJ45AirtoLight.jpg" width="320"><img src="./resources/RJ45_Light.jpg" width="209">
    -   Connect a micro USB cable between Lightsense and QA computer.
    -   Set the mode slide switch on Lightsense toward the right (away from the R1 label on the board). </br>
    <img src="./resources/PowerSlideSwitchLight.jpg" width="320">

* Setup 2: Airsense and Lightsense powered over 4 PIN connector in Lightsense. 

    -   Connect Lightsense to Airsense using CAT6 cable between Lightsense's RJ45 jack and Airsense's RJ45 jack
    labeled __Light__.  </br>
    <img src="./resources/RJ45AirtoLight.jpg" width="320"><img src="./resources/RJ45_Light.jpg" width="209">
    -   Connect a micro USB cable between Lightsense and QA computer.
    -   Connect the 4 wires between Lightsense and Wagman's Port 3 (J6). </br>
    <img src="./resources/Wagman_LightSense.jpg" width="256"><img src="./resources/Light_sense_Wagman_connection.jpg" width="320">
    -   Set the mode slide switch on Lightsense toward the left (closer to R1 label on the board).</br>
    <img src="./resources/PowerSlideSwitchLight.jpg" width="320">
    -   Connect micro-USB cable between Wagman's J3 and QA computer.
    -   Connect 5V DC power to Wagman.


* Setup 3: Airsense and Lightsense powered over EXT RJ-45 Port in Airsense. 
    -   Connect Lightsense to Airsense using CAT6 cable between Lightsense's RJ45 jack and Airsense's RJ45 jack
    labeled __Light__.  </br>
    <img src="./resources/RJ45AirtoLight.jpg" width="320"><img src="./resources/RJ45_Light.jpg" width="209">
    -   Set the mode slide switch on Lightsense toward the left (closer to R1 label on the board).</br>
    <img src="./resources/PowerSlideSwitchLight.jpg" width="320">
    -   Connect a micro USB cable between Lightsense and QA computer.
    -   Connect AEXT breakout connector to EXT port of Airsense. 
    -   Connect 5V power supply to the barrel jack of the AEXT breakout. 

**In the above setups, use pre-tested and verified Lightsense and Wagman boards if available.**

## Testing Procedure
*   Setup 1:
    -   Complete electrical connections. 
    -   Perform test by issuing command *make run* in the coresense directory.

*   Setup 2:
    -  In the Wagman folder - First issue the command *make install*.
    -  On completing the above, perform test by issuing command *make run* in the coresense directory.

*   Setup 3:
    -   Complete electrical connections. 
    -   Perform test by issuing command *make run* in the coresense directory.
    
__To exit the screen session created for the test, press Control+a, followed by k and y.__

## Test Log
This test is evaluated and scored on the __Coresense test document__.

# Success Criteria
The test is considered __PASSED__ if all the sub-tests in the Initialization Test (Coresense test document)
pass.
