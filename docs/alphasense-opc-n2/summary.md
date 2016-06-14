# Alphasense Summary

## SPI Mode and Clock Settings

* The SPI mode is a Mode 1 device, where the idle state for the clock is low
and data is transmitted on the leading edge (transition from idle to active
clock) and is received on the trailing edge of the signal.

* SPI clock acceptable frequency range: 300-750kHz. (Other frequencies may
also be acceptable, but are untested).

## Command List (Firmware Version 18)

### Power On Fan and Laser

```
03 -> AS
00 -> AS

F3 <- AS
03 <- AS
```

### Power Off Fan and Laser

```
03 -> AS
01 -> AS

F3 <- AS
03 <- AS
```

### Read Histogram

```
histdata :: 62 byte buffer

30 -> AS
F3 <- AS
sleep 10 ms

for i in 0..61
    30 -> AS
    sleep 1 ms
    histdata[i] <- AS
```
