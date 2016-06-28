There is one problem that the sensor values of four sensors in lightsensor become 65535, and never come back.

Sensor: 13 TSL260RD @  65535
Sensor: 14 TSL250RD @  65535
Sensor: 15 MLX75305 @  65535
Sensor: 16 ML8511 @  65535

We changed all C-standard functions in chemsense.ino to a local function, and most of variables are static.
