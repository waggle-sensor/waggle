
# WagMan

# port 1 (C1+ nodecontroller)
- see C1+ connections

# port 2  (XU4 extension node)
- see XU4 connections

# port 3 (LightSense)
- WagMan port 3 slots 1-4 to LightSense friction mount slots 1-4 (slot 1 on the right side is marked with a little circle on the board) <br>
color coding of wires if applicable:
```text
1. gray  -> reset
2. red   -> 5V
3. white -> heartbeat
4. black -> gnd
```
Switch on the LightSense below friction mount has to switched inside.


- WagMan/battery thermistor to port 3 (slots 5 and 6)


# port 4
- metal frame thermistor to port 4 (slots 5 and 6)

# port5
- AC/DC thermistor to port 5 (slots 5 and 6)




# C1+ connections

## USB connections

- C1+ USB to Lightsense micro USB using aluminium USB cable (which one exactly?)
- C1+ USB to WagMan micro USB using normal USB cable (which one exactly?)
- C1+ USB to microUSB/RJ45-adapter ("CAT6 USB BKT1") using normal USB cable (which one exactly?)
- C1+ USB to ?

## plain wires
- Heartbeat: C1+ GPIO pin 3 to WagMan port 1, slot 3 (slot 1 is right most)
- SRE J9 to C1+ GPIO pins 39 and 27 (order does not matter) (SRE is the little device plugged on top of the WagMan next to the C1+) 

## power
- power: C1+ power barrel socket to WagMan port 1 ( 5V (slot 2) and ground (slot 4) ) using barrel connector wire (2.5mm outer diameter)

# XU4 connections

## USB connections
- XU4 USB (2-port USB) to camera (LightSense, non-coated camera) using camera wire
- XU4 USB (2-port USB) to microUSB/RJ45-adapter ("CAT6 USB BKT1"), outer micro USB using aluminium USB cable
- XU4 USB (1-port USB) to microUSB/RJ45-adapter ("CAT6 USB BKT1"), the outer micro USB on other side using aluminium USB cable


## Ethernet
- C1+ RJ45 to XU4 RJ45 using ethernet cable

## plain wires
- Heartbeat: XU4 GPIO pin 4 to WagMan port 2, slot 3 (slot 1 is right most)
- Bootselector: XU4 bootselector eMMC to WagMan J4 right slot, XU4 bootselector uSD to WagMan J4 left slot, XU4 bootselector common (middle) to WagMan J4 middle slot

## power
- power: XU4 power barrel socket to WagMan port 2 ( 5V (slot 2) and ground (slot 4) ) using barrel connector wire (5.5mm outer diameter)

# CoreSense
- LightSense is id connected to C1+, see above
- LightSense RJ45 to AirSense RJ45 using ethernet cable (which one exactly?)
- AirSense RJ45 to ChemSeense RJ45 using ethernet cable (which one exactly?)

# Serial connection
- C1+ UART CON5
- XU4 UART CON1


# Other
- CAT6 USB BKT2



