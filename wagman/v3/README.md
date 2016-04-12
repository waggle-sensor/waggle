# Wagman Layout and Features:

The Wagman V3.1 board is capable of managing upto 5 devices through power control, power monitoring, 
heartbeat monitoring and device temperature monitoring. The figure below shows a Wagman with annotations 
pointing out to the various capabilities, sensors and connectors on board. 

<img src="./resources/WagmanAnnotated.png" width="640">

## Onboard Sensors: 

The Wagman V3.1 board has a set of on-board sensors that include - 
  * HT21D - Digital Temperature and Humidity Sensor
  * HIH4030 - Analog Humidity Sensor
  * ACS764 Current Sensors
  * Thermistors for sensing temperature of connected devices
  * An Opto-resistor to provide a measure of brightness in the vicinity of the Wagman. 

## Time Keeping and Unique ID:

In addition to the above sensors, the Wagman can keep time using a real-time clock chip - MCP79412, 
which also provides the Wagman with a 6-byte unique ID. 

## Power distribution, control and metering: 
There are 5 current sensed switched output ports on the Wagman numbered Port 1 to 5 with the following features - 

  * Each port has one 5V power output, one Thermistor input (2 pins) and one heartbeat input. An optional 
  reset pin can be used to reset a device (by toggling the line) powered by an external source. The reset 
  feature and 5V power cannot be used at the same time on a port. 
  * Port 1 is uniquely configured to maintain power state across Atmel 32U4 resets. This port is reserved for the 
  Node Controller.

## Odroid Specific Features:

The Wagman is configured to be able to support boot media switch on two connected Odroid single board computers as follows - 
  * __C1+ Boot Switch__: This is a two pin connector that is bridged in the default state to choose uSD as the default boot 
  media of the C1+ Node controller. The two pins can be disconnected by the Atmel 32U4 Processor to choose the eMMC boot media. 
  * __XU4 Boot Switch__: This is a three pin connector where the center pin (PIN 2) can be bridged to either the right (PIN 1) 
  or left (PIN 3) pins. The default state bridges PIN 1 and PIN 2, with PIN 3 isolated to choose uSD boot media on the connected XU4, and the 
  Atmel 32U4 processor can bridge PIN 2 and PIN 3, isolating PIN 1 to choose eMMC boot media. 

## Feedback LEDs:
The WagMan board has 5 status LEDs with the following features - 
  * A On LED stays on if the board is receiving 5V DC power. 
  * RX LED that blinks to signify input of data through the USB port to the board. 
  * TX LED that blinks to signify output of data from the board through the USB port. 
  * LEDs L and L1 - These can be brightness controlled (connected to PWM port) by the Atmel 32U4 to provide state information.
