
# Wagman QA Tests and Scope

The QA test for Wagman is accomplished through a series of pre-power-ON and post-power-ON tests. After
visual inspection of the board for production defects and glaring errors (component orientation, missing
components and such), the board is powered-ON and put through a series of tests here.

# Wagman Design Verification Testing and Coverage

The goal of these tests are to verify that the Wagman has the necessary circuitry and design features that
will enable it to perform all the functionalities outlined in the board design phase.
*To Do: V3 Board Design Requirements, refer to GITHub issues and such*
The following are the list of Unit Tests performed for Design Validation in order, along with the
goals of the tests- </br>

1.  wagman_init_test
  - Wagman power-on.
  - Wagman Atmel chip power-on and communication - including boot loader flashing and USB communication.
  - Proper functioning of on-board I2C communication bus.
  - Wagman's ability to read its unique ID.
  - Wagman's ability to provide visual feedback to tester using two LEDs whose brightness levels can be controlled.

2.  wagman_rtc_timekeep_test
  - Proper functioning of the RTC circuitry.
  - Wagman's ability to keep time when the main 5V power is disconnected.

3.  wagman_environ_sensors_test
  - The proper wiring of on-board sensors: HTU21D, HIH4030, Five Thermistors, and Optoresistor
  - The functioning of the on-board sensors.

4.  wagman_c1p_bootswitch_test
  - The ability to connect the boot-pins of the C1+ or isolate them toward changing the primary boot-up media.
  - Default boot media must be uSD, which is achieved by connecting the bootpins (JP9).

5.  wagman_xu4_bootswitch_test
  - The ability to connect the appropriate boot-pins of the XU4 toward changing the primary boot-up media.
  - Default boot media must be uSD, which is achieved by connecting pins 1 and 2 of the boot selector port (J4).

6.  wagman_heartbeat_test
  -  Wagman's ability to sense heartbeats from five devices connected to it.

7.  wagman_power_thermal_envelope_test
  - Ability to turn on and off five 5V DC power channels.
  - Ability to sense on-board power consumption.
  - Ability to supply a minimum of 2A of current through each of the five ports.
  - Ability to source 10A of current from AC/DC converter.
  - Ability to sense power consumed by devices connected to the five power outputs.
  - Ability to sustain peak power distribution over several tens of minutes without catastrophic failure.
  - Ability to sense heating and temperature change of the various devices connected to the power outputs.

8.  wagman_flash_reboot_stress_test
  - Ability to sustain Odroid XU4 and C1+ under full CPU load (and hence current utilization).
  - Ability to boot XU4 when C1+ is drawing maximum current.
  - Ability to flash Wagman from C1+.
  - Repeatability and predictability of the above.

## Tools and Equipment Required:
*   Wagman board under test
*   5V DC Waggle Power Supply (Digikey 102-1934-ND)
*   Five Thermistors (Digikey 317-1376-ND)
*   Function/Waveform Generator capable of generating 0-5V Square waves, 2 second period and 50% duty cycle
*   Five Resistors 2 ohm 13 watts 5% AXIAL (Digikey CWE-2.0RCT-ND)
*   Multimeter capable of continuity check with beep on continuity enabled
*   Odroid XU4 with waggle image. (Heartbeat implemented and enabled, and stress-ng installed)
*   Odroid C1+ with waggle image. (Heartbeat implemented and enabled, and stress-ng installed)
*   Airsense and Lightsense V3.1 boards.
*   Odroid C1P and XU4 barrel power pigtails
*   Jumper wire kit, male to male (Digikey 1471-1232-ND)
*   12 inches each of 18 gauge wire with red and black insulation.
*   QA computer (With Arduino 1.6.7 installed and configured to work with Waggle code base, udev rules for Waggle hardware installed etc.)

# Wagman Production QA Testing and Coverage

For the production QA test, the following tests are proposed to be performed when the board is
taken off the PCB assembly line -</br>

1.  wagman_init_test
2.  wagman_rtc_timekeep_test
3.  wagman_environ_sensors_test
4.  wagman_c1p_bootswitch_test
5.  wagman_xu4_bootswitch_test
6.  wagman_power_thermal_envelope_test (*only the first sub-part of the test that verifies the relay functionality*).

## Tools and Equipment Required:
*   Wagman board under test
*   5V DC Waggle Power Supply (Digikey 102-1934-ND)
*   Multimeter capable of continuity check with beep on continuity enabled
*   12 inches each of 18 gauge wire with red and black insulation.
*   QA computer (With Arduino 1.6.7 installed and configured to work with Waggle code base, udev rules for Waggle hardware installed etc.)


# Wagman Design Verification Score Sheet

## Success Criteria

# Wagman Production QA Testing Score Sheet

## Success Criteria
