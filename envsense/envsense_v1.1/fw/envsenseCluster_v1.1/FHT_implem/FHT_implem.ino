/*
fht_adc_serial.pde
guest openmusiclabs.com 7.7.14
example sketch for testing the fht library.
it takes in data on ADC0 (Analog0) and processes them
with the fht. the data is sent out over the serial
port at 115.2kb.
*/
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <HMC5883.h>
#define BUFF_SIZE 30
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);
int x_val=0,y_val=0,z_val=0;
#define LIN_OUT 1 // use the lin output function
#define FHT_N 256 // set to 256 point fht

#include <FHT.h> // include the library

void setup(void) {
  Serial.begin(115200); // use the serial port
  Serial.println("Startup");
//   TIMSK0 = 0; // turn off timer0 for lower jitter
  delay(1000);
    if(!mag.begin())
    {
        /* There was a problem detecting the HMC5883 ... check your connections */
        Serial.println("Ooops, no HMC5883 detected ... Check your wiring!");
        while(1);
    }
  
  // Initially, data NOT ready
  mag.setDataReady(0);
  
  
  // Set Single measurement mode on sensor
  mag.setSingleMeasurementMode();

  // For timing purposes
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  digitalWrite(2,LOW);
}

void loop(void) {
    while(1) { // reduces jitter
        for (int i = 0; i<FHT_N; i++)
        {
            
            digitalWrite(4,HIGH); // For timing purposes
            mag.setSingleMeasurementMode();
  
            digitalWrite(4,LOW);
            delay(3); // Give sensor time to take measurement
            while((mag.getDataReady() & 0x01) != 0x01); //wait until data is ready
            
            // Read 16 bit Y value output
            int16_t y_val;
            Wire.beginTransmission(HMC5883_ADDRESS_MAG);  // Open communication w/ HMC
            Wire.write(HMC5883_REGISTER_MAG_OUT_Y_H_M);   // Send call to register Y output
            Wire.endTransmission();
            Wire.beginTransmission(HMC5883_ADDRESS_MAG);     // Begin reading
            Wire.requestFrom(HMC5883_ADDRESS_MAG, 2);     // Request 2 bytes
            while(!Wire.available()) {};
            uint8_t vha = Wire.read();
            uint8_t vla = Wire.read();
            Wire.endTransmission();
            
            y_val = vha << 8 | vla;          // Adjust output for MSB's and LSB's
            fht_input[i] = y_val; // put real data into bins
//             Serial.print(fht_input[i]);
//             Serial.print(" ");
        }
        fht_window(); // window the data for better frequency response
        fht_reorder(); // reorder the data before doing the fht
        fht_run(); // process the data in the fht
        fht_mag_lin(); // take the output of the fht

        int dominant_idx = 0;
        float sample_rate = 189.0;
        for (byte i = 0 ; i < FHT_N/2 ; i++) {
            if(fht_lin_out[i] > fht_lin_out[dominant_idx] )
                dominant_idx = i; 
//             Serial.print(fht_lin_out[i]);
//             Serial.print(" ");
        }
        Serial.print("\n");
        float freq = dominant_idx*sample_rate/FHT_N;
//         Serial.print("Dominant frequency: ");
        float speed_mph = freq * 2.433; // Constant obtained experimentally
        Serial.print(freq);
        Serial.print("\t");
        Serial.println(speed_mph);
//         delay(500);
//          Adafruit_HMC5883_Unified test = Adafruit_HMC5883_Unified(23181);
//             sensors_event_t test_event;
//             
//             
//             test.begin();
//             for(int a = 0; a<10; a++)
//             // Perform test 10 times
//             {
//                 test.getEvent(&test_event);   // read sensor
//                 delay(500);
//             }
//         
    }
}
