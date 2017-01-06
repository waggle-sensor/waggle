#ifdef ALPHASENSE_INCLUDE
void alphasense_on() 
{
	//** POWER ON
	SPI.beginTransaction(set1);
    digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
    delay(100);

    val1 = SPI.transfer(0x03);
    delay(100);
    val2 = SPI.transfer(0x00);
    delay(100);
    
    digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
    SPI.endTransaction();

#ifdef ALPAH_DEBUG
    SerialUSB.print(val1, HEX);
    SerialUSB.print(val2, HEX);
#endif
}

void alphasense_off()
{
    //** POWER OFF
    SPI.beginTransaction(set1);
    digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
    delay(100);

	val1 = SPI.transfer(0x03);
	delay(100);
    val2 = SPI.transfer(0x01);
    delay(100);

	digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
    SPI.endTransaction();

#ifdef ALPAH_DEBUG
    SerialUSB.print(val1, HEX);
    SerialUSB.print(val2, HEX);
#endif
}

void alphasense_firmware()
{
    alpha_firmware[1] = (1 << 7) | LENGTH_ALPHA_FIRMWARE;

	//** Get firmware    
    SPI.beginTransaction(set1);
    digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
    delay(100);
    
    SPI.transfer(0x12);    // 0xF3
    delay(100);

    alpha_firmware[2] = SPI.transfer(0x12);
    delay(100);
    alpha_firmware[3] = SPI.transfer(0x12);
    delay(100);

    digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
    SPI.endTransaction();

#ifdef ALPHA_DEBUG
    SerialUSB.write(alpha_firmware[0]);
    SerialUSB.write(alpha_firmware[1]);
#endif
}


void alphasense_serial()
{
    alpha_serial[1] = (1 << 7) | LENGTH_ALPHA_SERIAL;

    //** Get serial
    SPI.beginTransaction(set1);
    digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
    delay(100);
    
    SPI.transfer(0x10);    // 0xF3
    delay(100);

    for (i = 0; i < 20; i++)
    {
        alpha_firmware[i + 2] = SPI.transfer(0x10);
        delay(100);
    }

    digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
    SPI.endTransaction();

#ifdef ALPHA_DEBUG
    for (i = 0; i < 20; i++)
        SerialUSB.write(alpha_firmware[i]);
#endif
}


void alphasense_histo()
{
    alpha_histogram[1] = (1 << 7) | LENGTH_ALPHA_HISTOGRAM;

    SPI.beginTransaction(set1);
    digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
    delay(100);

    SPI.transfer(0x30);   // 0xF3
    delay(100);
    
    for (i = 0; i < 62; i++)
    {
	    alpha_histogram[i + 2] = SPI.transfer(0x30);
	    delay(100);
	}

    digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
    SPI.endTransaction();	

#ifdef ALPHA_DEBUG
    for (i = 0; i < 62; i++)
    	SerialUSB.write(alpha_histogram[i]);
#endif
}

void alphasense_config()
{
    alpha_config_a[1] = (1 << 7) | LENGTH_ALPHA_CONFIG_A;
    alpha_config_b[1] = (1 << 7) | LENGTH_ALPHA_CONFIG_B;
    alpha_config_c[1] = (1 << 7) | LENGTH_ALPHA_CONFIG_C;
    alpha_config_d[1] = (1 << 7) | LENGTH_ALPHA_CONFIG_D;

    SPI.beginTransaction(set1);
    digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
    delay(100);

    SPI.transfer(0x3C);   // 0xF3
    delay(100);
    
    for (i = 0; i < 64; i++)
    {
	    alpha_config_a[i + 2] = SPI.transfer(0x3C);
	    delay(100);
	}

    for (i = 0; i < 64; i++)
    {
        alpha_config_b[i + 2] = SPI.transfer(0x3C);
        delay(100);
    }

    for (i = 0; i < 64; i++)
    {
        alpha_config_c[i + 2] = SPI.transfer(0x3C);
        delay(100);
    }

    for (i = 0; i < 64; i++)
    {
        alpha_config_d[i + 2] = SPI.transfer(0x3C);
        delay(100);
    }

    digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
    SPI.endTransaction();

#ifdef ALPHA_DEBUG
    for (i = 0; i < 64; i++)
	    SerialUSB.print(alpha_config_a[i], HEX);
    for (i = 0; i < 64; i++)
        SerialUSB.print(alpha_config_b[i], HEX);
    for (i = 0; i < 64; i++)
        SerialUSB.print(alpha_config_c[i], HEX);
    for (i = 0; i < 64; i++)
        SerialUSB.print(alpha_config_d[i], HEX);
#endif
}

#endif
