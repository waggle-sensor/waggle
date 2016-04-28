void testnew ()
{
    SerialUSB.print("MAC:");
    #ifdef SERIAL_DEBUG
    for (int i=0; i<8; i++)
    {
        SerialUSB.print(MAC_ID[i],HEX);

        if (i < 7)
        {
            SerialUSB.print("-");
        }
        else
        {
            SerialUSB.print("\r\n");
        }
    }
    #endif

    SerialUSB.print("SEQ_NO:");
    SerialUSB.println(test_seq++);
    #ifdef AIRSENSE_INCLUDE
    airsense_acquire();
    #endif

    #ifdef LIGHTSENSE_INCLUDE
    lightsense_acquire();
    #endif


    #ifdef CHEMSENSE_INCLUDE

    #ifdef SERIAL_DEBUG
    SerialUSB.println("Acquiring ChemSense Data.");
    #endif
    while(1)
    {
        while (Serial3.available() > 0)
        {
            SerialUSB.print(Serial3.read(), HEX);
        }
    }
    ChemSensed = 0;
    Chemsense_locked = 0;
    LOOPING = millis();
    while(1)
    {
        chemsense_aquire();
        if (ChemSensed == 1)
        {
            chemsense_pack();
            break;
        }

        if (  millis() - LOOPING > 3000)
        {
            #ifdef SERIAL_DEBUG
            SerialUSB.println("Intel Board Missing.");
            #endif
            ChemSensed = 0;
            break;
        }
    }

    #endif
    delay(5000);

}
