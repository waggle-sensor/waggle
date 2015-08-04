//---------- B O O T _ G N ----------------------------------------------------
/*
   Boots guest node.  Checks temperature, power draw, and heartbeat.
   If something goes wrong, the node controller is notified.

   :param byte gn: which guest node to boot (1, 2, or 3)

   :rtype: none
*/
void boot_GN(byte gn)
{
  byte pin_relay, pin_heartbeat;
  String problem_temp, problem_power, problem_heartbeat;
  byte *enabled, *present;
  unsigned int *boot_time;


  // Which guest node is being booted?
  switch (gn) {
    case 1:
      // Mark guest node as not operational
      _GN1_running = false;

      // Assign variables for this guest node
      pin_relay = PIN_RELAY_GN1;
      pin_heartbeat = PIN_HEARTBEAT_GN1;
      problem_temp = PROBLEM_GN1_TEMP;
      problem_power = PROBLEM_GN1_POWER;
      problem_heartbeat = PROBLEM_GN1_HEARTBEAT;
      enabled = &E_GN1_ENABLED;
      present = &E_PRESENT_GN1;
      boot_time = &E_BOOT_TIME_GN1;

      break;
    case 2:
      // Mark guest node as not operational
      _GN2_running = false;

      // Assign variables for this guest node
      pin_relay = PIN_RELAY_GN2;
      pin_heartbeat = PIN_HEARTBEAT_GN2;
      problem_temp = PROBLEM_GN2_TEMP;
      problem_power = PROBLEM_GN2_POWER;
      problem_heartbeat = PROBLEM_GN2_HEARTBEAT;
      enabled = &E_GN2_ENABLED;
      present = &E_PRESENT_GN2;
      boot_time = &E_BOOT_TIME_GN2;
      
      break;
    case 3:
      // Mark guest node as not operational
      _GN3_running = false;

      // Assign variables for this guest node
      pin_relay = PIN_RELAY_GN3;
      pin_heartbeat = PIN_HEARTBEAT_GN3;
      problem_temp = PROBLEM_GN3_TEMP;
      problem_power = PROBLEM_GN3_POWER;
      problem_heartbeat = PROBLEM_GN3_HEARTBEAT;
      enabled = &E_GN3_ENABLED;
      present = &E_PRESENT_GN3;
      boot_time = &E_BOOT_TIME_GN3;
      
      break;
    // Invalid guest node
    default:
      return;
  }

  // Make sure the device is off
  digitalWrite(pin_relay, LOW);

  // Give the relay time to move
  delay(100);

  // Is guest node enabled and expected to be present?
  if(eeprom_read_byte(enabled) && eeprom_read_byte(present))
  {
    // Is the guest node's temperature outside of safe parameters?
    if(!check_temp_GN(gn))
    {
      // Giving the guest node one more chance...

      // Wait for things to settle down, perhaps
      delay((long)BOOT_BAD_ENVIRON_WAIT_TIME * 1000L);

      // Is the guest node's temperature outside of safe parameters?
      if(!check_temp_GN(gn))
      {
        // Inform node controller of failure
        send_problem(problem_temp);

        // Exit with failure
        return;
      }
    }

    // Turn on the guest node
    digitalWrite(pin_relay, HIGH);

    // Give the guest node time to boot
    delay((long)eeprom_read_word(boot_time) * 1000L);

    // Is the guest node not drawing an expected amount of power?
    if(!check_power_GN(gn))
    {
      // Giving the guest node one more chance...

      // Power cycle the guest node
      power_cycle(pin_relay);

      // Give the guest node time to boot
      delay((long)eeprom_read_word(boot_time) * 1000L);

      // Is the guest node not drawing an expected amount of power?
      if(!check_power_GN(gn))
      {
        // Turn off the guest node
        digitalWrite(pin_relay, LOW);

        // Inform node controller of failure
        send_problem(problem_power);

        // Mark GN as dead
        eeprom_update_byte(enabled, 0);

        // Exit with failure
        return;
      }
    }

    // Is the guest node alive (sending a "heartbeat")?
    if(!check_heartbeat_odroid(pin_heartbeat))
    {
      byte boot_attempts = 0;
      boolean _heartbeat_detected = false;

      // Try to get a heartbeat from the GN as many times as allowed
      while (boot_attempts < eeprom_read_byte(&E_MAX_NUM_SUBSYSTEM_BOOT_ATTEMPTS))
      {
        // Is "heartbeat" not detected?
        if(!check_heartbeat_odroid(pin_heartbeat))
        {
          // Power cycle the guest node
          power_cycle(pin_relay);

          // Give the guest node time to boot
          delay((long)eeprom_read_word(boot_time) * 1000L);
        }
        else
          // Indicate that a heartbeat was detected
          _heartbeat_detected = true;

        // Increment counter for number of attempts
        boot_attempts++;
      }

      // Still no heartbeat detected?
      if(!_heartbeat_detected)
      {
        // Turn off the guest node
        digitalWrite(pin_relay, LOW);

        // Inform node controller of failure
        send_problem(problem_heartbeat);

        // Exit with failure
        return;
      }
    }
  }

  // Which guest node is being booted?
  switch (gn) {
    case 1:
      // Mark guest node as operational
      _GN1_running = true;

      break;
    case 2:
      // Mark guest node as operational
      _GN2_running = true;
      
      break;
    case 3:
      // Mark guest node as operational
      _GN3_running = true;
      
      break;
    // Invalid guest node
    default:
      return;
  }
}