/*
FHT_implem.ino

example sketch for testing the windvel sensor.
This sketch takes data on the I2C bus for the HMC5883, at 
address 0x1E. It samples measurements 
with the fht. 
*/
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <HMC5883.h>
#define BUFF_SIZE 30

#define LIN_OUT 1 // use the lin output function
#define FHT_N 256 // set to 256 point fht
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);
int y_val=0;
// DELAY: 1  - Sampling Rate: 310  Hz    Max observed freq: 155   Hz   Max observed speed: 168.6 m/s
// DELAY: 2  - Sampling Rate: 238  Hz    Max observed freq: 119   Hz   Max observed speed: 129.4 m/s
// DELAY: 3  - Sampling Rate: 192  Hz    Max observed freq: 96    Hz   Max observed speed: 104.4 m/s
// DELAY: 4  - Sampling Rate: 160  Hz    Max observed freq: 80    Hz   Max observed speed: 87.0  m/s
// DELAY: 5  - Sampling Rate: 139  Hz    Max observed freq: 69.5  Hz   Max observed speed: 75.6  m/s
// DELAY: 6  - Sampling Rate: 121  Hz    Max observed freq: 60.5  Hz   Max observed speed: 65.8  m/s
// DELAY: 7  - Sampling Rate: 109  Hz    Max observed freq: 54.5  Hz   Max observed speed: 59.3  m/s
// DELAY: 8  - Sampling Rate: 98.4 Hz    Max observed freq: 49.20 Hz   Max observed speed: 53.5  m/s
// DELAY: 9  - Sampling Rate: 89.3 Hz    Max observed freq: 44.65 Hz   Max observed speed: 48.6  m/s
// DELAY: 10 - Sampling Rate: 81.7 Hz    Max observed freq: 41.35 Hz   Max observed speed: 45.0  m/s
// DELAY: 15 - Sampling Rate: 58.1 Hz    Max observed freq: 29.05 Hz   Max observed speed: 31.6  m/s
// DELAY: 20 - Sampling Rate: 45.0 Hz    Max observed freq: 20.50 Hz   Max observed speed: 22.3  m/s
// DELAY: 25 - Sampling Rate: 36.8 Hz    Max observed freq: 18.40 Hz   Max observed speed: 20.0  m/s
int sample_delay = 4;// Give sensor time to take measurement (must be >= 1)
float sample_rate = 160.0;
// This delay sets the sampling frequency. 
// The rest of the measurement takes ~2.4 ms

#include <FHT.h> // include the library

void setup(void) {
  Serial.begin(115200); // use the serial port
  Serial.println("Startup");
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
            

        for (int i = 0; i<FHT_N; i++)   // Take FHT_N samples
        {
            digitalWrite(4,HIGH); // For timing purposes
            mag.setSingleMeasurementMode();
  
            digitalWrite(4,LOW);
            delay(sample_delay); // Give sensor time to take measurement (must be >= 1)
            // This delay sets the sampling frequency. 
            // The rest of the measurement takes ~2.4 ms
            
            while((mag.getDataReady() & 0x01) != 0x01); //do nothing until data is ready
            // DRDY bit monitoring only needed for high sampling frequencies
            
            // Read 16 bit Y value output
            int16_t y_val;
            Wire.beginTransmission(HMC5883_ADDRESS_MAG);  // Open communication w/ HMC
            Wire.write(HMC5883_REGISTER_MAG_OUT_Y_H_M);   // Send call to register Y output
            Wire.endTransmission();
            Wire.beginTransmission(HMC5883_ADDRESS_MAG);     // Begin reading
            Wire.requestFrom(HMC5883_ADDRESS_MAG, 2);     // Request 2 bytes
            while(!Wire.available()) {};    // Wait for data
            uint8_t vha = Wire.read();
            uint8_t vla = Wire.read();
            Wire.endTransmission();
            
            y_val = vha << 8 | vla;          // Adjust output for MSB's and LSB's
            fht_input[i] = y_val; // put real data into bins
//             Serial.print(fht_input[i]);
//             Serial.print(" ");
        }
//         for(int i = 0; i<FHT_N; i++)
//             Serial.println(fht_input[i]);
        fht_window(); // window the data for better frequency response
        fht_reorder(); // reorder the data before doing the fht
        fht_run(); // process the data in the fht
        fht_mag_lin(); // take the output of the fht, store in "fht_lin_out"

        int dominant_idx = 0;
        for (byte i = 0 ; i < FHT_N/2 ; i++) {      // output has FHT_N/2 bins
            if(fht_lin_out[i] > fht_lin_out[dominant_idx] )
                dominant_idx = i; 
            Serial.print(fht_lin_out[i]);
            Serial.print(" ");
        }
        Serial.print("\n");
        float freq = dominant_idx*sample_rate/FHT_N;
//         Serial.print("Dominant frequency: ");
        float speed_mps = freq * 1.0876; 
        // Constant obtained experimentally
        // By calibrating with Vaavud amometer
        Serial.print(freq);
        Serial.print("\t");
        Serial.println(speed_mps);
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
