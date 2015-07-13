//---------- I N C L U D E S --------------------------------------------------
#include <Time.h>
#include <MCP79412RTC.h>
#include <Wire.h>



//---------- C O N S T A N T S ------------------------------------------------
const long UART_BAUD = 57600;



//---------- G L O B A L S ----------------------------------------------------



//---------- S E T U P --------------------------------------------------------
void setup() {
	// Give the user time to connect
	delay(3000);

	// Start serial comms
  Serial.begin(UART_BAUD);

  // Join I2C bus as master
  Wire.begin();

  // Check RTC
  boolean result_RTC = check_RTC();

  if(result_RTC)
  	Serial.println("RTC: pass");
  else
  	Serial.println("RTC: fail");
}

//---------- L O O P ----------------------------------------------------------
void loop() {
	
}



//---------- C H E C K _ R T C ------------------------------------------------
/*
	 Checks that the MCP79412 RTC is read/write functional.

	 Returns TRUE if all is well.
	 Returns FALSE if something is wrong.

	 :rtype: boolean
*/
boolean check_RTC()
{
	// Set system (arduino) time to 30 seconds after epoch
	setTime(0, 0, 0, 1, 1, 1970);

	// Set RTC to the system time
	RTC.set(now());

	// Get time from RTC
	time_t reported_time = RTC.get();

	Serial.println(reported_time);

	// Is reported time the same as the time we set?
	if(reported_time == 30)
			// Exit with success
			return true;

	// Exit with failure
	return false;
}