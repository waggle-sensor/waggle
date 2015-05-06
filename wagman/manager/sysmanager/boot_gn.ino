//---------- C O N S T A N T S ------------------------------------------------




//---------- G L O B A L S ----------------------------------------------------




//---------- B O O T _ G N ----------------------------------------------------
/*
   

   :rtype: none
*/
void boot_gn()
{
	// Is guest node 2 enabled?
	if(eeprom_read_byte(&E_GN2_ENABLED))
	{
		// Set relay pin to output mode
		pinMode(PIN_RELAY2, OUTPUT);
		// Enable the relay (turn on the guest node)
  	digitalWrite(PIN_RELAY2, HIGH);
	}
}