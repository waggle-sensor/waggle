void post() { 
    int testing_bit = EEPROM.read(testing_addr);
    int current_sensor = 1;
    if(testing_bit==0)      // Just beginning POST
    {
        Serial.println("Commencing POST");
        for(int i = 1; i <= numSensors; i++)
        {
            EEPROM.write(i, 0);     // clear "tested" array
            EEPROM.write(i+128, 0); // clear "passed" array
        }
        EEPROM.write(testing_addr, 1);   // POST has begun
    }
    else        // obtain next sensor to be tested (to resume post after WatchDog triggered)
    {
       for(int j = 1; j <= numSensors; j++)
       {
           if(EEPROM.read(j)==1)
           {
               current_sensor=j;
           }
       }
       current_sensor++;
       Serial.print("Test Failed, resuming from sensor ");
       Serial.println(current_sensor);
    }
    
    testing_bit = EEPROM.read(testing_addr);
    if(testing_bit==1)  // continue to watchdog testing loop
    {
        wdt_enable(WDTO_2S);    // Two Second Watchdog enabled
        for(int k = current_sensor; k<=numSensors; k++)     // Test Sensors
        {
            
            #ifdef SHT75_ADD              // k=1
            if(k==1)
            {
                EEPROM.write(k,1);
                Serial.print("Testing SHT75\t");
                                
                float SHT75_1_temperature;
                float SHT75_1_humidity;
                uint16_t SHT75_1_rawData;
                uint8_t SHT75_1_error;
                Sensirion SHT75_1_tempSensor = Sensirion(SHT75_1_dataPin, SHT75_1_sclkPin);
                
                SHT75_1_error = SHT75_1_tempSensor.measTemp(&SHT75_1_rawData);
                SHT75_1_temperature = SHT75_1_tempSensor.calcTemp(SHT75_1_rawData);
                SHT75_1_error = SHT75_1_tempSensor.measHumi(&SHT75_1_rawData);
                SHT75_1_humidity = SHT75_1_tempSensor.calcHumi(SHT75_1_rawData, SHT75_1_temperature);
                
                EEPROM.write(k+128,1);
                Serial.println("Test passed successfully");
            }
            #endif
            
            #ifdef BMP180_ADD             // k=2
            if(k==2)
            {
                EEPROM.write(k, 1);
                
                Serial.print("Testing BMP\t");
                Wire.begin();
                Adafruit_BMP085_Unified BMP_180_1 = Adafruit_BMP085_Unified(10085);
                float BMP_180_1_temperature, BMP_180_1_pressure;
                BMP_180_1.begin();
                BMP_180_1.getTemperature(&BMP_180_1_temperature);
                BMP_180_1.getPressure(&BMP_180_1_pressure);
                
                EEPROM.write(k+128, 1);  // Test complete
                Serial.println("Test passed successfully");
            }
            #endif          
                        // Single Wire devices
            #ifdef RHT03_ADD              // k=3
            if(k==3)
            {
                EEPROM.write(k, 1);
                
                dht RHT03_1;
                int chk_RHT03_1;
                
                Serial.print("Testing RHT03\t");
                
                chk_RHT03_1 = RHT03_1.read22(RHT03_1_PIN);
                
                EEPROM.write(k+128, 1);  // Test complete
                Serial.println("Test passed successfully");
            }
            #endif
            
            #ifdef TMP102_ADD             // k=4
            if(k==4)
            {
                EEPROM.write(k, 1);
                
                const int tmp102_1_Address = 0x48;
                float tmp102_1_temperature;
                byte tmp102_1_MSB, tmp102_1_LSB;
                int err;
                Wire.begin();
                
                Serial.print("Testing TMP102\t");
                
                err = Wire.requestFrom(tmp102_1_Address,2);
                if (err != 0) {
                    byte tmp102_1_MSB = Wire.read();
                    byte tmp102_1_LSB = Wire.read();
                    tmp102_1_temperature = (((tmp102_1_MSB << 8) | tmp102_1_LSB) >> 4) * 0.11250 + 32; //it's a 12bit int, using two's compliment for negative
                }
                
                EEPROM.write(k+128, 1);  // Test complete
                Serial.println("Test passed successfully");
            }
            #endif

            // Two Wire devices
            #ifdef SHT15_ADD              // k=5
            #define SHT15_1_dataPin  11     // SHT15_1 serial data
            #define SHT15_1_sclkPin  12     // SHT15_1 serial clock
            if(k==5)
            {
                EEPROM.write(k, 1);
                
                float SHT15_1_temperature;
                float SHT15_1_humidity;
                uint16_t SHT15_1_rawData;
                uint8_t SHT15_1_error;
                
                Serial.print("Testing SHT15\t");
                
                Sensirion SHT15_1_tempSensor = Sensirion(SHT15_1_dataPin, SHT15_1_sclkPin);
                SHT15_1_error = SHT15_1_tempSensor.measTemp(&SHT15_1_rawData);
                SHT15_1_temperature = SHT15_1_tempSensor.calcTemp(SHT15_1_rawData);
                SHT15_1_error = SHT15_1_tempSensor.measHumi(&SHT15_1_rawData);
                SHT15_1_humidity = SHT15_1_tempSensor.calcHumi(SHT15_1_rawData, SHT15_1_temperature);
                
                EEPROM.write(k+128, 1);  // Test complete
                Serial.println("Test passed successfully");
            }
            #endif

            #ifdef MMA8452        // k=6
            if(k==6)
            {
                EEPROM.write(k,1);
                int accelCount[3]; // Stores the 12-bit signed value
                float accelG[3]; // Stores the real accel value in g's
                
                Serial.print("Testing MMA\t");

                #ifndef I2C_INIT_ADD
                i2c_init();
                #endif //I2C_INIT_ADD
                
                MMA_found = initMMA8452();
                bool good_data = readAccelData(accelCount); // Read the x/y/z adc values
                
                EEPROM.write(k+128, 1); // Test complete
                Serial.println("Test passed successfully");
            }
            #endif
            
            #ifdef HIH6130_ADD            // k=7
            if(k==7)
            {
                EEPROM.write(k,1);
                Serial.print("Testing HIH6130\t");
                
                
                HIH_6130_1_hih.start();
                HIH_6130_1_hih.update();
                
                EEPROM.write(k+128,1);
                Serial.println("Test passed successfully");
            }
            #endif
            
            // // 1-wire devices
            #ifdef DS18B20_ADD            // k=8
            if(k==8)
            {
                EEPROM.write(k,1);
                Serial.print("Testing DS18B20\t");
                
                float data = DS18B20_1_getTemp();
                
                EEPROM.write(k+128,1);  // Test complete
                Serial.println("Test passed successfully");
            }
            #endif

            
            #ifdef MLX90614_ADD   // k=9
            if(k==9)
            {
                EEPROM.write(k,1);
                start_err = i2c_start(dev+I2C_WRITE);
                write_err = i2c_write(0x07);

                Serial.print("Testing MLX\t");
                
                start_err = i2c_start(dev+I2C_WRITE);
                write_err = i2c_write(0x07);

                // read
                rep_start_err = i2c_rep_start(dev+I2C_READ);
                data_low = i2c_readAck(); //Read 1 byte and then send ack
                data_high = i2c_readAck(); //Read 1 byte and then send ack
                pec = i2c_readNak();
                i2c_stop();       
                
                
                EEPROM.write(k+128, 1); // Test complete
                Serial.println("Test passed successfully");
            }
            #endif
            
            // Analog Inputs
            #ifdef GA1A1S201WP_ADD       // k=10
            if(k==10)
            {
                EEPROM.write(k, 1);
                Serial.print("Testing GA1A\t");
                
                AMBI_1_Value = analogRead(AMBI_1_Pin);
                
                EEPROM.write(k+128, 1);
                Serial.println("Test passed successfully");
            }
            #endif

                        
            #ifdef THERMIS_100K_ADD      // k=11
            if(k==11)
            {
                EEPROM.write(k, 1);
                Serial.print("Testing THERMIS\t");
                
                THERMIS_1_Value = analogRead(THERMIS_100K_Pin);
                
                EEPROM.write(k+128, 1);
                Serial.println("Test passed successfully");
            }
            #endif

                        
            #ifdef MAX4466_ADD          // k=12
            if(k==12)
            {
                EEPROM.write(k, 1);
                Serial.print("Testing MAX\t");
                
                int data = analogRead(MAX4466_PIN);
                
                EEPROM.write(k+128, 1);  // Test complete
                Serial.println("Test passed successfully");
            }
            #endif
            
            #ifdef TMP421_ADD           // k=13
            if(k==13)
            {
                EEPROM.write(k, 1);
                pinMode(A2, INPUT);        // GND pin
                pinMode(A3, INPUT);        // VCC pin
                digitalWrite(A3, LOW);     // turn off pullups
                
                Serial.print("Testing TMP421\t");
                
                TMP421_1_temperature = TMP421_1.GetTemperature();
                
                EEPROM.write(k+128, 1);
                Serial.println("Test passed successfully");
                wdt_reset();
            }                
            #endif
            
            #ifdef IR_D6T_44L_06_ADD    // k=14
            if(k==14)
            {
                EEPROM.write(k,1);
                int rbuf[35];
                float tdata[16];
                float t_PTAT;
                float tPEC;
                bool data_check;
                
                Serial.print("Testing IR_D6T\t");

                for (k = 0; k < 35; k++) {
                    if (k == 34) {
                        rbuf[k] = i2c_readNak();
                    }
                    else {
                        rbuf[k] = i2c_readAck();
                    }
                }
                i2c_stop();
                
                EEPROM.write(k+128, 1); // Test complete
                Serial.println("Test passed successfully");
            }
            #endif
            
            #ifdef HIH4030_ADD          // k=15
            if(k==15)
            {
                EEPROM.write(k, 1);
                Serial.print("Testing HIH4030\t");
                
                HIH4030_1_Value = analogRead(HIH4030_PIN);
                
                EEPROM.write(k+128, 1);  // Test complete
                Serial.println("Test passed successfully");
            }
            #endif

                        
            #ifdef PhoRes_ADD           // k=16
            if(k==16)
            {
                EEPROM.write(k,1);
                Serial.print("Testing PhoRes\t");
                
                PhoRes_1_Value = analogRead(PhoRes_PIN);
                
                EEPROM.write(k+128, 1); // Test complete
                Serial.println("Test passed successfully");
            }
            #endif
                        
            #ifdef WindVel_ADD           // k=17
            if(k==17)
            {
                EEPROM.write(k,1);
                EEPROM.write(k+128,1);
            }
            #endif

            #ifdef HTU21D_ADD            // k=18
            if(k==18)
            {
                EEPROM.write(k, 1);
                
                Serial.print("Testing HTU21D\t");
                
                myHumidity.begin();
                HTU21D_T = myHumidity.readTemperature();
                HTU21D_H = myHumidity.readHumidity();
                HTU21D_T = myHumidity.readTemperature();
                HTU21D_H = myHumidity.readHumidity();
                
                EEPROM.write(k+128, 1);  // Test complete
                Serial.println("Test passed successfully");
            }
            #endif
            
            #ifdef HMC5883_ADD          // k=19
            if(k==19)
            {
                EEPROM.write(k, 1);
                Serial.print("Testing HMC\t");
                
                Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(23181);
                sensors_event_t HMC5883_event;
                
                
                mag.begin();
                mag.getEvent(&HMC5883_event);
                
                EEPROM.write(k+128, 1);  // Test complete
                Serial.println("Test passed successfully");
            }
            #endif
            
            wdt_reset();
        }
    }
    EEPROM.write(testing_addr, 0);      // Self test complete
    Serial.println("POST TEST RESULTS:");
    Serial.print("SHT75: ");
    if(EEPROM.read(1+128))
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    
    Serial.print("BMP180: ");
    if(EEPROM.read(2+128))
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    
    Serial.print("RHT03: ");
    if(EEPROM.read(3+128))
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    
    Serial.print("TMP102: ");
    if(EEPROM.read(4+128))
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    
    Serial.print("SHT15: ");
    if(EEPROM.read(5+128))
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    
    Serial.print("MMA8452: ");
    if(EEPROM.read(6+128))
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    
    Serial.print("HIH6030: ");
    if(EEPROM.read(7+128))
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    
    Serial.print("DS18B20: ");
    if(EEPROM.read(8+128))
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    
    Serial.print("MLX90614: ");
    if(EEPROM.read(9+128))
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    
    Serial.print("GA1A1S201WP: ");
    if(EEPROM.read(10+128))
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    
    Serial.print("THERMIS_100K: ");
    if(EEPROM.read(11+128))
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    
    Serial.print("MAX4466: ");
    if(EEPROM.read(12+128))
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    
    Serial.print("TMP421: ");
    if(EEPROM.read(13+128))
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    
    Serial.print("IR_D6T: ");
    if(EEPROM.read(14+128))
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    
    Serial.print("HIH4030: ");
    if(EEPROM.read(15+128))
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    
    Serial.print("PhoRes: ");
    if(EEPROM.read(16+128))
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    
    Serial.print("WindVel: ");
    if(EEPROM.read(17+128))
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    
    Serial.print("HTU21D: ");
    if(EEPROM.read(18+128))
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    
    Serial.print("HMC5883: ");
    if(EEPROM.read(19+128))
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    
    wdt_reset();        
        
}
