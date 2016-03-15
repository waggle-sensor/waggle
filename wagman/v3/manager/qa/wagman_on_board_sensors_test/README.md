# Test Scope and Coverage

This test evaluates the following aspects of Wagman system design. </br>
1. Proper functioning if on-board I2C communication bus, A/D lines, PWM ports and digital inputs. </br>
2. The proper wiring of on-board sensors.</br>
* HTU21D </br>
* HIH4030 </br>
* Five Thermistors, four of which are sampled using MCP3428 A/D converter </br>
* Six ACS764 Current Sensors </br>
* RTC MCP79412 </br>
* Optoresistor
3. The functioning of the on-board sensors.</br>
4. Wagman's ability to sense heart-beat input from various boards at 1.8, 3.3 and 5V levels.</br>
5. Wagman's ability to switch boot modes for C1+ and XU4.</br>
6. Wagman's unique ID. </br>
7. Wagman's ability to keep time when power is disconnected. </br>
8. Wagman's ability to control power on five output channels. </br>
9. Wagman's ability to provide visual feedback to tester using two LEDs whose brightness levels can be controlled. </br>
</br>

# Test Setup Procedure

This test proceeds in three phases - </br>
* Initial RTC time setting phase.
* Second board evaluation phase.
* Final board re-evaluation phase.

The board is powered down with the USB and DC 5V connections removed, and then reconnected again
after 30 seconds between the second and final phase. This enables testing of the ability to keep
time on CR2030 battery.
</br>
To finish this test successfully, in addition of the Wagman with all the on-board sensors, 5 thermistors
and a multi-meter with continuity check capability is required.
</br>
For step-by-step procedure, follow README nodes in the sub-folders.

## Electrical Connection
*  Connect 5 thermistors to ports J5, J6, J7, J8 and J9 of Wagman following the __Wagman Connection Guide__
*  Connect 5V DC power to Wagman using J10. Follow __Wagman Connection Guide__ for polarity details.
*  Connect micro-USB cable between Wagman's J3 and QA computer.

## Test Events Timeline
* Step 1: Wagman is loaded with firmware that sets the RTC clock.
* Step 2: Wagman is loaded with firmware that tests the on-board sensing capabilities.
* Step 3: Wagman begins sequential testing process, with input from tester.
* Step 4: Wagman is powered down, and USB disconnected for 30 seconds after the test in Step 3 is finished.
* Step 5: Wagman is powered back on, and the sequential testing process is performed again.

## Test Log

This test is evaluated and scored on the __Wagman sensor test document__.

###Example Events Verification

###Success Criteria

The test is considered PASSED if all the sub-tests in __Wagman sensor test document__ pass.

