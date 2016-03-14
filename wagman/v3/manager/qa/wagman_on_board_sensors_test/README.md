# Test Scope and Coverage

This test evaluates the following aspects of Wagman system design. </br>
1. Proper functioning if on-board I2C communication bus, A/D lines, PWM ports and digital inputs. </br>
2. The proper wiring of on-board sensors.</br>
    *   HTU21D
    *   HIH4030
    *   Five Thermistors, four of which are sampled using MCP3428 A/D converter.
    *   Six ACS764 Current Sensors
    *   RTC MCP79412
3. The functioning of the on-board sensors.</br>
4. Wagman's ability to sense heart-beat input from various boards at 1.8, 3.3 and 5V levels.</br>
5. Wagman's ability to switch boot modes for C1+ and XU4.</br>
6. Wagman's unique ID. </br>
7. Wagman's ability to keep time when power is disconnected. </br>
</br>

# Test Setup Procedure

This test proceeds in three phases - </br>
* Initial RTC time setting phase.
* Second board evaluation phase.
* Final board re-evaluation phase.

The board is powered down with the USB and DC 5V connections removed, and then reconnected again
after 30 seconds between the second and final phase. This enables testing of the ability to keep
time on CR2030 battery.

## Electrical Connection


## Test Events Timeline
* Step 1: Wagman is loaded with firmware that sets the RTC clock.
* Step 2: Wagman is loaded with firmware that tests the on-board sensing capabilities.
* Step 3: Wagman begins sequential testing process, with input from tester.
* Step 4: Wagman is powered down, and USB disconnected for 30 seconds after the test in Step 3 is finished.
* Step 5: Wagman is powered back on, and the sequential testing process is performed again.

## Test Log

This test is evaluated and scored on the {Wagman sensor test document}.

###Example Events Verification

###Success Criteria

The test is considered PASSED if all the sub-tests in {Wagman sensor test document} pass.

