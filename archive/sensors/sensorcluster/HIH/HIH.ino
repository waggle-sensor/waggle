// HIH_6130_1  - Arduino
//
// Arduino                HIH-6130
// SCL (Analog 5) ------- SCL (term 3)
// SDA (Analog 4) ------- SDA (term 4)
//
// Note 2.2K pullups to 5 VDC on both SDA and SCL
//
// Pin4 ----------------- Vdd (term 8)
//
// Illustrates how to measure relative humidity and temperature.
//
// copyright, Peter H Anderson, Baltimore, MD, Nov, '11
// You may use it, but please give credit.

#include <Wire.h> //I2C library
extern TwoWire Wire1;
byte fetch_humidity_temperature(unsigned int *p_Humidity, unsigned int *p_Temperature);
void print_float(float f, int num_digits);

#define TRUE 1
#define FALSE 0

void setup(void)
{
delay(5000);
   SerialUSB.begin(115200);
   Wire1.begin();
   SerialUSB.println(">>>>>>>>>>>>>>>>>>>>>>>>");  // just to be sure things are working
}

void loop(void)
{
   byte _status;
   unsigned int H_dat, T_dat;
   float RH, T_C;

   while(1)
   {
      _status = fetch_humidity_temperature(&H_dat, &T_dat);

//       switch(_status)
//       {
//           case 0:  SerialUSB.println("Normal.");
//                    break;
//           case 1:  SerialUSB.println("Stale Data.");
//                    break;
//           case 2:  SerialUSB.println("In command mode.");
//                    break;
//           default: SerialUSB.println("Diagnostic.");
//                    break;
//       }

      RH = (float) H_dat * 6.10e-3;
      T_C = (float) T_dat * 1.007e-2 - 40.0;
      SerialUSB.print("RH%:");
      print_float(RH, 1);
      SerialUSB.print("  T_C:");
      print_float(T_C, 2);
      SerialUSB.println();
      delay(1000);
   }
}

byte fetch_humidity_temperature(unsigned int *p_H_dat, unsigned int *p_T_dat)
{
      byte address, Hum_H, Hum_L, Temp_H, Temp_L, _status;
      unsigned int H_dat, T_dat;
      address = 0x27;;
      Wire1.beginTransmission(address);
      Wire1.endTransmission();
      delay(100);

      Wire1.requestFrom((int)address, (int) 4);
      Hum_H = Wire1.read();
      Hum_L = Wire1.read();
      Temp_H = Wire1.read();
      Temp_L = Wire1.read();
      Wire1.endTransmission();

      _status = (Hum_H >> 6) & 0x03;
      Hum_H = Hum_H & 0x3f;
      H_dat = (((unsigned int)Hum_H) << 8) | Hum_L;
      T_dat = (((unsigned int)Temp_H) << 8) | Temp_L;
      T_dat = T_dat / 4;
      *p_H_dat = H_dat;
      *p_T_dat = T_dat;
      return(_status);
}

void print_float(float f, int num_digits)
{
    int f_int;
    int pows_of_ten[4] = {1, 10, 100, 1000};
    int multiplier, whole, fract, d, n;

    multiplier = pows_of_ten[num_digits];
    if (f < 0.0)
    {
        f = -f;
        SerialUSB.print("-");
    }
    whole = (int) f;
    fract = (int) (multiplier * (f - (float)whole));

    SerialUSB.print(whole);
    SerialUSB.print(".");

    for (n=num_digits-1; n>=0; n--) // print each digit with no leading zero suppression
    {
         d = fract / pows_of_ten[n];
         SerialUSB.print(d);
         fract = fract % pows_of_ten[n];
    }
}
