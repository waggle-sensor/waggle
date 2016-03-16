# Test Scope and Coverage

This test evaluates the following aspects of Wagman system design. </br>
1. Ability to turn on and off five 5V DC power channels.</br>
2. Ability to sense on-board power consumption.</br>
3. Ability to supply a minimum of 2A of current through each of the five ports.</br>
4. Ability to source 10A of current from AC/DC converter.</br>
5. Ability to sense power consumed by devices connected to the five power outputs.</br>
6. Ability to sustain peak power distribution over several tens of minutes without catastrophic failure.</br>
7. Ability to sense heating and temperature change of the various devices connected to the power outputs.</br>
</br>


# Test Setup Procedure

## Test Events Timeline
* Phase 1: Wagman is tested to verify its ability to turn on and off five output power channels.
* Phase 2: Wagman is tested to verify its power delivery and temperature sensing capabilities (scope items 3 to 7).

## Electrical Connection
*  Connect micro-USB cable between Wagman's J3 and QA computer.
*  Connect 5V DC power to Wagman.
*  Connect five 2 ohm resistors (20 watt dissipation) to the five output ports (J5, J6, J7, J8 and J9)
    between +5V (pin 2) and GND (pin 4).
*  Connect the two leads of the thermistors to PINS 5 and 6 of J5, J6, J7, J8 and J9 as shown below.</br>
<img src="./resources/Thermistor_wiring.jpg" width="200">
*  Secure the five thermistor bulbs to the five resistor loads such that the bulbs are heated by the
    resistors. The thermistor bulbs can be secured using heat resistant tape.</br>
<img src="./resources/Thermistor.jpg" width="160">

__Please make sure only the Wagman under test is connected to the QA computer. No other Wagman or Arduino Micro/derivatives can be connected at this time.__

## Testing Procedure
*  Start test by issuing the command *make run* and follow the on-screen prompts.
__To exit the screen session created for the test, press Control+a, followed by k and y.__

## Test Log
This test is evaluated and scored on the __Wagman sensor test document__. This test pushes Wagman to 125% of the design
requirements, drawing 12.5 watts on each of the five output channels.

# Success Criteria
The test is considered __PASSED__ if the subtests of the Wagman Power and Thermal Envelope Test pass.
