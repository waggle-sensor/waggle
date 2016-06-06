char incoming[256] = "";
char * token;
char * taken;
String one = " ";
String two = " ";


#define MAX_FMT_SIZE 6
byte formatted_data_buffer[MAX_FMT_SIZE];

uint8_t sqn = 0;
int type = 0;
int sq_num;
int16_t shh;
int16_t hex;
int16_t form5;
int16_t form2;

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
//	SerialUSB.println("...");
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
		//Serial.print(one.substring(0, 3));
		//Serial.print(" ");
		String oneP = one.substring(0, 3);

//		String two = " ";
		two = one.substring(4);	
		Serial.println(two);

		if (oneP == "BAD")					//string
		    type = 0;
		else if (oneP == "SQN")					//uint8
		    type = 1;
		else if (oneP == "SHH" | oneP == "LPP")					//uint16 from string: format1
		    type = 2;
		else if (oneP == "SUV" | oneP == "SVL" | oneP == "SIR")	//uint16 from hex deciamal from string: format1
		    type = 3;
		else if (sqn == 1 & two != "1")  			//the last for if else, int24: format5
		    type = 4;
		else							//for default, int16: format2
		    type = 9;

/*
		else if (oneP == "SHT" | oneP == "LPT") 		//int16: format2
		    type = default;
		else
		    type = default;
		    //if (sqn == 2  | sqn == 3)    // the last one??????????? the last for swich case int16: format2
*/

		switch(type)
		{
		    case 0:	//string "BAD"
			Serial.println(two);
			break;

		    case 1:	//uint8 "SQN"
			sq_num = (int)strtol(two.c_str(), NULL, 16);   //hex string to int
			sqn = sq_num;
			Serial.println(sqn);

			while (sqn > 4)
			{
			    sqn = sqn % 4;
			    //Serial.println("sqn");
			    //Serial.println(sqn);
			}
			break;

		    case 2: 	//uint16 from string: format1 "SHH"
			shh = two.toInt();
			Serial.println(shh);
			break;

		    case 3: 	//uint16 from hex deciamal from string: format1 "SUV" "SVL" "SIR"
//			hex = (int)strtol(two.c_str(), NULL, 16);   //hex string to int
			//uint16_t value = hex; 
//			Serial.println(hex);
//			format1(hex);
			break;

		    case 4:	//int24: format5 sqn == 1 & two != "1"
//			form5 = two.toInt();
//			Serial.println(form5);
//			Serial.println("test, format5");    ////////the first test of formatting
//			format5(form5);
//			Serial.write(formatted_data_buffer, 3);
			break;

		    default:
//			form2 = two.toInt();
//			Serial.write(formatted_data_buffer, 2); 
//			Serial.println(form2);
			break;

/*		    case 5: //int16: format2 sqn == 2  | sqn == 3
			int16_t value = two.toInt(); 
			//Serial.println(value);
			break;

		    default:
			
*/
		}
/*
		if (one.substring(0, 3) == "BAD")
		{
		    //Serial.println(two);   //String
		}

		if (oneP == "SQN")
		{
		    int num = (int)strtol(two.c_str(), NULL, 16);   //hex string to int
		    sqn = num;
		    //Serial.println(sqn);

		    while (sqn > 4)
		    {
			sqn = sqn % 4;
			//Serial.println("sqn");
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
		    //Serial.println(value);
//		    format1(int(value));
		    
		}

		if (sqn == 1 & two != "1")
		{
		    int16_t value = two.toInt();
		    Serial.println(value);
		    Serial.println("test, format5");    ////////the first test of formatting
		    format5(value);
		    Serial.write(formatted_data_buffer, 3);
		}

		if (sqn == 2 | sqn == 3)
		{
		    int16_t value = two.toInt(); 
		    //Serial.println(value);
		}

//	    }
//	    else
//	    {
//		Serial.println(one.substring(1, 4));
//		Serial.println(one.substring(5));
//	    }
*/
	    token = strtok(NULL, " ");
	    one = " ";
	    two = " ";
	}
	memset(incoming, 0, 256);
    }
}
