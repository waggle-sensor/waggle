//---------- B O O T _ G N 1 --------------------------------------------------
/*
   Boots guest node 1.  Checks temperature, power draw, and heartbeat.
   If something goes wrong, the node controller is notified.

   Return TRUE: guest node booted successfully.
   Return FALSE: guest node did not boot successfully.

   :rtype: boolean
*/
boolean boot_GN1()
{
  // Mark guest node as not operational
  _GN1_running = false;

  // Make sure the device is off
  digitalWrite(PIN_RELAY_GN1, LOW);

  // Give the relay time to move
  delay(100);

  // Is guest node 1 enabled and expected to be present?
  if(eeprom_read_byte(&E_GN1_ENABLED) && eeprom_read_byte(&E_PRESENT_GN1))
  {
    // Is the guest node's temperature outside of safe parameters?
    if(!check_temp_GN(1))
    {
      // Giving the guest node one more chance...

      // Wait for things to settle down, perhaps
      delay((long)BOOT_BAD_ENVIRON_WAIT_TIME * 1000L);

      // Is the guest node's temperature outside of safe parameters?
      if(!check_temp_GN(1))
      {
        // Inform node controller of failure
        send_problem(PROBLEM_GN1_TEMP);

        // Exit with failure
        return false;
      }
    }

    // Turn on the guest node
    digitalWrite(PIN_RELAY_GN1, HIGH);

    // Give the guest node time to boot
    delay((long)eeprom_read_word(&E_BOOT_TIME_GN1) * 1000L);

    // Is the guest node not drawing an expected amount of power?
    if(!check_power_GN(1))
    {
      // Giving the guest node one more chance...

      // Power cycle the guest node
      power_cycle(PIN_RELAY_GN1);

      // Give the guest node time to boot
      delay((long)eeprom_read_word(&E_BOOT_TIME_GN1) * 1000L);

      // Is the guest node not drawing an expected amount of power?
      if(!check_power_GN(1))
      {
        // Turn off the guest node
        digitalWrite(PIN_RELAY_GN1, LOW);

        // Inform node controller of failure
        send_problem(PROBLEM_GN1_POWER);

        // Mark GN as dead
        eeprom_update_byte(&E_GN1_ENABLED, 0);

        // Exit with failure
        return false;
      }
    }

    // Is the guest node alive (sending a "heartbeat")?
    if(!check_heartbeat_odroid(PIN_HEARTBEAT_GN1))
    {
      byte boot_attempts = 0;
      boolean _heartbeat_detected = false;

      // Try to get a heartbeat from the GN as many times as allowed
      while (boot_attempts < eeprom_read_byte(&E_MAX_NUM_SUBSYSTEM_BOOT_ATTEMPTS))
      {
        // Is "heartbeat" not detected?
        if(!check_heartbeat_odroid(PIN_HEARTBEAT_GN1))
        {
          // Power cycle the guest node
          power_cycle(PIN_RELAY_GN1);

          // Give the guest node time to boot
          delay((long)eeprom_read_word(&E_BOOT_TIME_GN1) * 1000L);
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
        digitalWrite(PIN_RELAY_GN1, LOW);

        // Inform node controller of failure
        send_problem(PROBLEM_GN1_HEARTBEAT);

        // Exit with failure
        return false;
      }
    }

    // Mark guest node as operational
    _GN1_running = true;

    // Exit with success
    return true;
  }
  else
    // Exit with failure
    return false;
}



//---------- B O O T _ G N 2 --------------------------------------------------
/*
   Boots guest node 2.  Checks temperature, power draw, and heartbeat.
   If something goes wrong, the node controller is notified.

   Return TRUE: guest node booted successfully.
   Return FALSE: guest node did not boot successfully.

   :rtype: boolean
*/
boolean boot_GN2()
{
  // Mark guest node as not operational
  _GN2_running = false;

  // Make sure the device is off
  digitalWrite(PIN_RELAY_GN2, LOW);

  // Give the relay time to move
  delay(100);

  // Is guest node 2 enabled and expected to be present?
  if(eeprom_read_byte(&E_GN2_ENABLED) && eeprom_read_byte(&E_PRESENT_GN2))
  {
    // Is the guest node's temperature outside of safe parameters?
    if(!check_temp_GN(2))
    {
      // Giving the guest node one more chance...

      // Wait for things to settle down, perhaps
      delay((long)BOOT_BAD_ENVIRON_WAIT_TIME * 1000L);

      // Is the guest node's temperature outside of safe parameters?
      if(!check_temp_GN(2))
      {
        // Inform node controller of failure
        send_problem(PROBLEM_GN2_TEMP);

        // Exit with failure
        return false;
      }
    }

    // Turn on the guest node
    digitalWrite(PIN_RELAY_GN2, HIGH);

    // Give the guest node time to boot
    delay((long)eeprom_read_word(&E_BOOT_TIME_GN2) * 1000L);

    // Is the guest node not drawing an expected amount of power?
    if(!check_power_GN(2))
    {
      // Giving the guest node one more chance...

      // Power cycle the guest node
      power_cycle(PIN_RELAY_GN2);

      // Give the guest node time to boot
      delay((long)eeprom_read_word(&E_BOOT_TIME_GN2) * 1000L);

      // Is the guest node not drawing an expected amount of power?
      if(!check_power_GN(2))
      {
        // Turn off the guest node
        digitalWrite(PIN_RELAY_GN2, LOW);

        // Inform node controller of failure
        send_problem(PROBLEM_GN2_POWER);

        // Mark GN as dead
        eeprom_update_byte(&E_GN2_ENABLED, 0);

        // Exit with failure
        return false;
      }
    }

    // Is the guest node alive (sending a "heartbeat")?
    if(!check_heartbeat_odroid(PIN_HEARTBEAT_GN2))
    {
      byte boot_attempts = 0;
      boolean _heartbeat_detected = false;

      // Try to get a heartbeat from the GN as many times as allowed
      while (boot_attempts < eeprom_read_byte(&E_MAX_NUM_SUBSYSTEM_BOOT_ATTEMPTS))
      {
        // Is "heartbeat" not detected?
        if(!check_heartbeat_odroid(PIN_HEARTBEAT_GN2))
        {
          // Power cycle the guest node
          power_cycle(PIN_RELAY_GN2);

          // Give the guest node time to boot
          delay((long)eeprom_read_word(&E_BOOT_TIME_GN2) * 1000L);
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
        digitalWrite(PIN_RELAY_GN2, LOW);

        // Inform node controller of failure
        send_problem(PROBLEM_GN2_HEARTBEAT);

        // Exit with failure
        return false;
      }
    }

    // Mark guest node as operational
    _GN2_running = true;

    // Exit with success
    return true;
  }
  else
    // Exit with failure
    return false;
}



//---------- B O O T _ G N 3 --------------------------------------------------
/*
   Boots guest node 3.  Checks temperature, power draw, and heartbeat.
   If something goes wrong, the node controller is notified.

   Return TRUE: guest node booted successfully.
   Return FALSE: guest node did not boot successfully.

   :rtype: boolean
*/
boolean boot_GN3()
{
  // Mark guest node as not operational
  _GN3_running = false;

  // Make sure the device is off
  digitalWrite(PIN_RELAY_GN3, LOW);

  // Give the relay time to move
  delay(100);

  // Is guest node 3 enabled and expected to be present?
  if(eeprom_read_byte(&E_GN3_ENABLED) && eeprom_read_byte(&E_PRESENT_GN3))
  {
    // Is the guest node's temperature outside of safe parameters?
    if(!check_temp_GN(3))
    {
      // Giving the guest node one more chance...

      // Wait for things to settle down, perhaps
      delay((long)BOOT_BAD_ENVIRON_WAIT_TIME * 1000L);

      // Is the guest node's temperature outside of safe parameters?
      if(!check_temp_GN(3))
      {
        // Inform node controller of failure
        send_problem(PROBLEM_GN3_TEMP);

        // Exit with failure
        return false;
      }
    }

    // Turn on the guest node
    digitalWrite(PIN_RELAY_GN3, HIGH);

    // Give the guest node time to boot
    delay((long)eeprom_read_word(&E_BOOT_TIME_GN3) * 1000L);

    // Is the guest node not drawing an expected amount of power?
    if(!check_power_GN(3))
    {
      // Giving the guest node one more chance...

      // Power cycle the guest node
      power_cycle(PIN_RELAY_GN3);

      // Give the guest node time to boot
      delay((long)eeprom_read_word(&E_BOOT_TIME_GN3) * 1000L);

      // Is the guest node not drawing an expected amount of power?
      if(!check_power_GN(3))
      {
        // Turn off the guest node
        digitalWrite(PIN_RELAY_GN3, LOW);

        // Inform node controller of failure
        send_problem(PROBLEM_GN3_POWER);

        // Mark GN as dead
        eeprom_update_byte(&E_GN3_ENABLED, 0);

        // Exit with failure
        return false;
      }
    }

    // Is the guest node alive (sending a "heartbeat")?
    if(!check_heartbeat_odroid(PIN_HEARTBEAT_GN3))
    {
      byte boot_attempts = 0;
      boolean _heartbeat_detected = false;

      // Try to get a heartbeat from the GN as many times as allowed
      while (boot_attempts < eeprom_read_byte(&E_MAX_NUM_SUBSYSTEM_BOOT_ATTEMPTS))
      {
        // Is "heartbeat" not detected?
        if(!check_heartbeat_odroid(PIN_HEARTBEAT_GN3))
        {
          // Power cycle the guest node
          power_cycle(PIN_RELAY_GN3);

          // Give the guest node time to boot
          delay((long)eeprom_read_word(&E_BOOT_TIME_GN3) * 1000L);
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
        digitalWrite(PIN_RELAY_GN3, LOW);

        // Inform node controller of failure
        send_problem(PROBLEM_GN3_HEARTBEAT);

        // Exit with failure
        return false;
      }
    }

    // Mark guest node as operational
    _GN3_running = true;

    // Exit with success
    return true;
  }
  else
    // Exit with failure
    return false;
}