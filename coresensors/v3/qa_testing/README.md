# Coresense QA Tests and Scope

The Coresense system is made of a set of 3 boards -
*   Airsense
*   Lightsense
*   Chemsense

The QA test for the Coresense system is accomplished through a series of pre-power-ON and post-power-ON
tests on each of the above boards. After visual inspection of the boards for production defects and glaring
errors (component orientation, missing components and such), the boards are powered-ON and put through
a series of tests described here.

# Airsense Design Verification Testing and Coverage

The goal of these tests are to verify that the Airsense noard has the necessary circuitry and
design features that will enable it to perform all the functionalities outlined in the board design
phase. </br>
*To Do: V3 Board Design Requirements, refer to GITHub issues and such* </br>
The following Tests are performed in sequence for Design Validation - </br>

1.  Airsense_init_test
  - Airsense power-on.
  - Airsense Atmel chip power-on and USB communication.
  - Proper functioning of on-board I2C communication bus.
  - Airsense's ability to read its unique ID.

2.  Airsense_heartbeat_test
  -  Airsense's ability to generate a heartbeat signal which can be sensed by Wagman.

3.  Airsense_Lightsense_connectivity_test

3.  Airsense_environ_sensors_test
  - The proper wiring and functioning of the on-board sensors.

4.  Lightsense_environ_sensors_test
  - The proper wiring and functioning of the on-board sensors.

5.  Airsense_Chemsense_powercontrol_test

6.  Airsense_Chemsense_connectivity_test
  - The ability to connect the boot-pins of the C1+ or isolate them toward changing the primary boot-up media.
  - Default boot media must be uSD, which is achieved by connecting the bootpins (JP9).


## Tools and Equipment Required:
*   Airsense and Lightsense V3.1 boards to be tested.
*   Optional: Functional Lightsense and Airsense V3.1 boards.
*   5V DC Waggle Power Supply (Digikey 102-1934-ND)
*   Multimeter capable of continuity check with beep on continuity enabled
*   Jumper wire kit, male to male (Digikey 1471-1232-ND)
*   12 inches each of 18 gauge wire with red (Digikey A461626R-100-ND) and black (Digikey A461626B-100-ND) insulation.
*   QA computer (With Arduino 1.6.7 installed and configured to work with Waggle code base, udev rules for Waggle hardware installed etc.)
*   Wagman V3.1

# Coresense Production QA Testing and Coverage

For the production QA test, the following tests are proposed to be performed when the board is
taken off the PCB assembly line -</br>

1.  Airsense_init_test
3.  Airsense_Lightsense_connectivity_test
3.  Airsense_environ_sensors_test
4.  Lightsense_environ_sensors_test
5.  Airsense_Chemsense_powercontrol_test


## Tools and Equipment Required:
*   Airsense and Lightsense V3.1 boards to be tested.
*   Optional: Functional Lightsense and Airsense V3.1 boards.
*   QA computer (With Arduino 1.6.7 installed and configured to work with Waggle code base, udev rules for Waggle hardware installed etc.)


# Coresense Design Verification Score Sheet

## Success Criteria

# Coresense Production QA Testing Score Sheet

## Success Criteria
