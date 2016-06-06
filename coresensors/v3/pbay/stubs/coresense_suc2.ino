char incoming[256] = "";
char * token;
char * taken;
String one = " ";
String two = " ";
uint8_t sqn = 0;

void setup()
{
    SerialUSB.begin(115200);    //sendData
    while(!SerialUSB) {;}
    Serial.begin(115200);       //getData
    while(!Serial) {;}
}

void loop()
{
    SerialUSB.println(">>get data packets and parse and send back?<<");
    while (1)
    {
        SerialUSB.println("...");
	SerialUSB.readBytes(incoming, 256);
//	Serial.write(incoming);

	token = strtok(incoming, " ");
//	taken = token;
//	Serial.println(token);

	while (token != NULL)
	{
//	    value = strtok(taken, "=");
	    String one = " ";
	    one = token;
//	    Serial.println(token);	   

//	    if (one.substring(0, 1) != ">")
//	    {
		Serial.print(one.substring(0, 3));
		Serial.print(" ");
		String oneP = one.substring(0, 3);

//		String two = " ";
		two = one.substring(4);	
		Serial.println(two);

		if (one.substring(0, 3) == "BAD")
		{
		    Serial.println(two);   //String
		}

		if (oneP == "SQN")
		{
		    int num = (int)strtol(two.c_str(), NULL, 16);   //hex string to int
		    sqn = num;
		    Serial.println(sqn);

		    while (sqn > 4)
		    {
			sqn = sqn % 4;
			Serial.println("sqn");
			//Serial.println(sqn);
		    }
		    
		}

		if (oneP == "SHH")
		{
		    int16_t value = two.toInt();
		    Serial.println(value);
		}

		if (oneP == "SUV" | oneP == "SVL" | oneP == "SIR")
		{
		    int num = (int)strtol(two.c_str(), NULL, 16);   //hex string to int
		    uint16_t value = num; 
		    Serial.println(value);
		}

		if (sqn == 1)
		{
//		    int24_t value = two.toInt(); //int24???????????
//		    Serial.println(value);
		}

		if (sqn == 2 | sqn == 3)
		{
		    int16_t value = two.toInt(); 
		    Serial.println(value);
		}

		
		//strcpy(taken, two); 

	/*	if (one.substring(0, 3) == "BAD")
		{
		    Serial.println(two);   //String
		}
		else if (one.substring(0,3) == "IRR")
		{
		    int num = (int)strtol(two.c_str(), NULL, 16);   //hex string to int
		    Serial.println(num);
		}
		else
		{
		    Serial.println(two.toInt()); //int
		    Serial.print(" ");
		}*/
//	    }
//	    else
//	    {
//		Serial.println(one.substring(1, 4));
//		Serial.println(one.substring(5));
//	    }

	    token = strtok(NULL, " ");
	    one = " ";
	    two = " ";
	}
	memset(incoming, 0, 256);
    }
}
