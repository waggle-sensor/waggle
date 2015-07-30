# TSYS01

This code provides I2C communication with a TSYS01 sensor (http://www.digikey.com/product-search/en?x=0&y=0&lang=en&site=us&keywords=tsys010)

getCoeffs() reads the prom calibration constants for the given sensor during setup()

TSYS01GetTemp() requests then reads the 24bit ADC output, converts it to 16 and applies scaleTemp_C to calculate the sensed temperature, per the datasheet:
http://www.telemeter.info/documents/datenblatt_tsys01_telemeter.pdf

This code has only been tested on a Teensy 3.0, but will be further developed and tested on a PIC32 platform in the future. It should be compatible with most systems using the Arduino IDE / Wire library

The minimum time between requesting and subsequently reading a sensor measurement seems to be 10ms (experimentally determined - 7ms works but can intermittently fail.)


