# Coresense QA Tests and Scope

The Coresense system is made of a set of 3 boards -
*   Airsense
*   Lightsense
*   Chemsense

and the optional Alphasense OPC -

*   Alphasense OPC-N2

The QA test for the Coresense system is accomplished through a series of pre-power-ON and post-power-ON
tests on the Airsense, Lightsense and Chemsense boards. After visual inspection of the boards for
production defects and assembly errors (component orientation, missing components and such), the boards
are powered-ON and put through a series of tests. The initial QA testing on the Chemsense board is performed
by the *Advanced Sensors Group at Intel* and the testing for the *OPC-N2 is performed by Alphasense*.

# Design Verification Testing and Coverage

The goals of these tests are to verify that the sensor boards have the necessary circuitry and
design features that will enable them to perform all the functionalities outlined in the board design
phase. The following Tests are performed in sequence for Design Validation - </br>

1.  Airsense Initialization
    - Airsense power-on.
    - Airsense Atmel chip power-on and USB communication.
    - Proper functioning of on-board I2C communication bus.
    - Airsense's ability to read its unique ID.

2.  Airsense Heartbeat
    -  Airsense's ability to generate a heartbeat signal which can be sensed by Wagman.

3.  Airsense-Lightsense Connectivity
    - Airsense's ability to communicate with sensors on the Lightsense using the I2C bus.

3.  Airsense Environmental Sensors Test
    - The proper wiring and functioning of the on-board sensors.

4.  Lightsense Environmental Sensors Test
    - The proper wiring and functioning of the on-board sensors.

5.  Chemsense Power Control and Connectivity Test
    - Airsense's ability to turn ON or OFF the power to the Chemsense board.
    - RS232 Communication between Airsense and Chemsense.

6. OPC-N2 Connectivity Test
    - SPI communication between Airsense and OPC-N2

7. External RJ45 Connectivity Test
    -  I2C communication through EXT RJ-45 Jack.

## Tools and Equipment Required:
*   Airsense and Lightsense V3.1 boards to be tested.
*   Optional: Functional Lightsense and Airsense V3.1 boards.
*   Wagman V3.1
*   Airsense test assembly consisting of AEXT and ACHEM dongles.
*   5V DC Waggle Power Supply (Digikey 102-1934-ND)
*   Jumper wire kit, male to male (Digikey 1471-1232-ND)
*   12 inches each of 18 gauge wire with red (Digikey A461626R-100-ND) and black (Digikey A461626B-100-ND) insulation.
*   QA computer (With Arduino 1.6.7 installed and configured to work with Waggle code base, udev rules for Waggle hardware installed etc.)
*   Optional: Funtional Chemsense and OPC-N2 sensors.

# Coresense Production QA Testing and Coverage

For the production QA test, the following tests are proposed to be performed when the board is
taken off the PCB assembly line -</br>

1.  Airsense Initialization
2.  Airsense-Lightsense Connectivity
3.  Airsense Environmental Sensors Test
4.  Lightsense Environmental Sensors Test
5.  Chemsense Power Control and Connectivity Test
6.  External RJ45 Connectivity Test

## Tools and Equipment Required:
*   Airsense and Lightsense V3.1 boards to be tested.
*   Optional: Functional Lightsense and Airsense V3.1 boards.
*   QA computer (With Arduino 1.6.7 installed and configured to work with Waggle code base, udev rules for Waggle hardware installed etc.)
*   Airsense test assembly consisting of AEXT and ACHEM dongles.


# Coresense Design Verification Score Sheet

## Success Criteria

# Coresense Production QA Testing Score Sheet

## Success Criteria
