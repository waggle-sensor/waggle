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
  Serial.println("Setup complete");
  Serial.flush();
}

void loop(void) {
    while(1) { // reduces jitter
//         cli();  // UDRE interrupt slows this way down on arduino1.0
//         Serial.println("cli");
        sensors_event_t HMC5883_event;
//         Serial.println(millis());
        for (int i = 0; i<FHT_N; i++)
        {
            mag.getEvent(&HMC5883_event);
            y_val = HMC5883_event.magnetic.y;
            fht_input[i] = y_val; // put real data into bins
            Serial.print(fht_input[i]);
            Serial.print(" ");
//             Serial.print(millis());
//             Serial.print(" ");
            delay(50);
        }
//         Serial.print("\n");
        fht_window(); // window the data for better frequency response
        fht_reorder(); // reorder the data before doing the fht
        fht_run(); // process the data in the fht
        fht_mag_lin(); // take the output of the fht
//         sei();
        int dominant_idx = 0;
        float sample_rate = 160.0;
        for (byte i = 0 ; i < FHT_N/2 ; i++) {
            if(fht_lin_out[i] > fht_lin_out[dominant_idx] )//&& i <= max_index)
                dominant_idx = i; 
            Serial.print(fht_lin_out[i]);
            Serial.print(" ");
        }
        Serial.print("\n");
        float freq = dominant_idx*sample_rate/FHT_N;
//         Serial.print("Dominant frequency: ");
        float speed_mph = freq;
        Serial.print(speed_mph);
        Serial.print("\t");
        Serial.println(dominant_idx);
        delay(500);
        
    }
}
