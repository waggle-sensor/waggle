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
wait 10 ms

for i in 0..61
    30 -> AS
    wait 1 ms
    histdata[i] <- AS
```

## Histogram Layout (Firmware Version 18)

*This struct is written assuming little endian byte layout, 2 byte short
and 4 byte int!*

```
struct {
    unsigned short bins[16];
    unsigned char mtof[4];
    unsigned int sample_flow_rate;
    unsigned int temperature_pressure;
    unsigned int sample_period;
    unsigned short checksum;
    float pm1;
    float pm25;
    float pm10;
};
```
