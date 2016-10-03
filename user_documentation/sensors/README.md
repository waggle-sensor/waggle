<img src="./SensorTable_files/SensorTable_htm_dbb4dd19ca8f2c5c.png" width=500 />

# Waggle Sensors

## Airsense

<img src="./SensorTable_files/SensorTable_htm_6665a28b3edceb8f.png" width=500 />

* Size: 55x145x15mm
* Interface: USB-Serial, I2C	
* CPU: Atmel SAM3X8E ARM Cortex-M3 CPU

### Parts list
| Part Name | Measurement | Range | Accuracy | Datasheet |
| ------------- |------------- | ------------- |------------- |------------- |
| TMP112 | Temperature |-40 to +125 °C |	±1 °C | [Datasheet](./airsense/tmp112.pdf)|
|HTU21D | Temperature <br> Relative Humidity | -40 to +125 °C <br> 0 to 100 %RH | ±1 °C <br> ±2 %RH | [Datasheet](./airsense/htu21d.pdf)|
| HIH4030 | Humidity | 0 to 100 %RH | ±3.5 %RH | [Datasheet](./airsense/htu4030.pdf)|
| BMP180 | Temperature <br> Atmospheric Pressure | -40 to +85 °C <br> 300 to 1100 hPa | ±1.0°C <br> ±0.02 hPa | [Datasheet](./airsense/bmp180.pdf)|
| PR103J2 | Temperature | -55 to +80 °C | ±0.05 °C | [Datasheet](./airsense/pr103j2.pdf)|
| TSL250RD | Light Intensity, λp = 640nm | 0 to 124 μW/cm2 | 16 μW/cm2 | [Datasheet](./airsense/tsl250rd.pdf) |
| MMA8452Q | 3 axis acceleration | ±8 g | ±20 mg | [Datasheet](./airsense/mma8452q.pdf) |
| SPV1840LR5H-B | Instantaneous Sound Sample | Acoustic Overload Point <br> to 121 dB SPL | -38 dBV/Pa | [Datasheet](./airsense/spv1840lr5h-b.pdf) |
| TSYS01 | Temperature | -40°C to +125 °C | 0.5 °C | [Datasheet](./airsense/tsys01.pdf) |

## Lightsense

<img src="./SensorTable_files/SensorTable_htm_2a5e3330e7bb0891.png" width=500 />

* Size: 40x57x15mm
* Interface: I2C 	
* CPU: None

### Parts list
| Part Name | Measurement | Range | Accuracy | Datasheet |
| ------------- |------------- | ------------- |------------- |------------- |
| HMC5883L | 3 axis magnetic field intensity | ±8 gauss | ±0.002 gauss | [Datasheet](./lightsense/hmc5883l.pdf) |
| HIH6130 | Temperature <br> Relative Humidity | -25 to +85 °C <br> 0 to 100 %RH | ±1.0 °C <br> ±0.05 %RH | [Datasheet](./lightsense/hih6130.pdf) |
| APDS-9006-020 | Light Intensity, λp = 500 nm | 0 to 1000 LUX | ±0.68 % | [Datasheet](./lightsense/apd9006020.pdf) |
| TSL260RD | Light Intensity, λp = 940 nm | 0 to 132 μW/cm2 | ±15 μW/cm2 | [Datasheet](./lightsense/tsl260rd.pdf) |
| TSL250RD | Light Intensity, λp = 640 nm | 0 to 124 μW/cm2 | ±16 μW/cm2 | [Datasheet](./lightsense/tsl250rd.pdf) |
| MLX75305 | Light Intensity, λp = 700 nm | 0 to 160 μW/cm2 | ±15 μW/cm2 | [Datasheet](./lightsense/mlx75305c.pdf) |
| ML8511 | Light Intensity, λp = 365 nm | 0 to 15 mW/cm2 | ±1 % | [Datasheet](./lightsense/ml8511.pdf) |
| TMP421 | Temperature | –55 to +127 °C | ±1.5 °C | [Datasheet](./lightsense/tmp421.pdf) |
| MLX90614 | Temperature | -40 to +85 C | ±0.5 °C | [Datasheet](./lightsense/mlx90614.pdf) |

## Chemsense

<img src="./SensorTable_files/SensorTable_htm_74b9e9c053e66ad9.png" width=500 />

* Size: 65x130x15mm
* Interface: USB-Serial, UART 	
* CPU: Intel Microprocessor

### Parts list
| Part Name | Measurement | Range | Accuracy | Datasheet |
| ------------- |------------- | ------------- |------------- |------------- |
| SHT25 | Temperature <br> Relative Humidity | -40 to +125 °C <br> 0 to 100 %RH | ±0.04 °C <br> ±0.04 %RH | [Datasheet](./chemsense/sht25.pdf) |
| LPS25H | Temperature <br> Atmospheric Pressure | -30 to +105°C <br> 260 to 1260  hPa | ±2 °C <br> ±0.1 hPa | [Datasheet](./chemsense/lps25h.pdf) |
| Si1145 | Light Intensity (UV) <br> Light Intensity, λp = 760 nm <br> Light Intensity, λp = 560 nm |   |   | [Datasheet](./chemsense/si1145.pdf) | 
| Sulfur Dioxide | SO2 Concentration | 0 to 20 ppm | ±3% of reading | [Datasheet](./chemsesne/so2.pdf) |
| Hydrogen Sulfide | H2S Concentration | 0 to 50 ppm | ±3% of reading | [Datasheet](./chemsesne/h2s.pdf) |
| Ozone | O3 Concentration | 0 to 20 ppm | ±3% of reading | [Datasheet](./chemsesne/o3.pdf) |
| Nitrous Oxide | NO2 Concentration | 0 to 20 ppm | ±3% of reading | [Datasheet](./chemsesne/no2.pdf) |
| Carbon Monoxide | CO Concentration | 0 to 1,000 ppm | ±2% of reading | [Datasheet](./chemsesne/co.pdf) |
| BMI160 | 3 axis acceleration <br> 3 axis orientation | ±16g <br> 2000°/s | 300μg/√Hz <br> 0.07°/s rms| [Datasheet](./chemsesne/ 	bmi160.pdf) |
| Total Reducing Gases | Reducing Gases Concentration | 0 to 20 ppm | ±3% of reading | [Datasheet](./chemsesne/) |
| Total Oxidizing Gases | Oxidizing Gases Concentration | 0 to 20 ppm | ±3% of reading | [Datasheet](./chemsesne/) |

## OPC-N2

<img src="./SensorTable_files/SensorTable_htm_53dff78b647db13c.jpg" width=500 />

* Size: 65x75x60mm 	
* Interface: USB Storage, SPI

### Parts list
| Part Name | Measurement | Range | Accuracy | Datasheet |
| ------------- |------------- | ------------- |------------- |------------- |
| OPC-N2 | PM1 in μg/m3 <br> PM2.5 in μg/m3 <br> PM10 in μg/m3 |  |  |  [Datasheet](./opc/opcN2.pdf) |
