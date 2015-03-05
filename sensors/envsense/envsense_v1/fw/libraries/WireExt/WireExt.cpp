/*
  WireExt.h - TWI/I2C extension library for Arduino & Wiring
  Copyright (c) 2010 fenrir(M.Naruoka).  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

extern "C" {
  #include <stdlib.h>
  #include <string.h>
  #include <inttypes.h>
  #include <avr/io.h>
  #include <compat/twi.h>
  
  void twi_reply(uint8_t);
  void twi_stop(void);
  void twi_releaseBus(void);
}

#include "WireExt.h"

// Initialize Class Variables //////////////////////////////////////////////////

// Constructors ////////////////////////////////////////////////////////////////

TwoWireExt::TwoWireExt(){
}

// Public Methods //////////////////////////////////////////////////////////////
/**
 * start receiption transaction
 * 
 * @param address slave address
 * @param new_twbr new value for twbr register
 * @return when negative value is returned, the transaction has been failed to start.
 * othereise successfully started.
 */
int8_t TwoWireExt::beginReception(uint8_t address, int new_twbr){
  orig_twbr = TWBR;
  TWBR = (uint8_t)new_twbr; // clock change
  
  // send start condition w/o IE
  TWCR = _BV(TWEN) | _BV(TWEA) | _BV(TWINT) | _BV(TWSTA);
  
  while(!(TWCR & _BV(TWINT)));
  switch(TW_STATUS){
    case TW_START:     // sent start condition
    case TW_REP_START: // sent repeated start condition
      // copy device address and r/w bit to output register and ack
      TWDR = TW_READ | (address << 1);
      TWCR = _BV(TWEN) | _BV(TWINT) | _BV(TWEA);
      break;
    case TW_BUS_ERROR: // bus error, illegal stop/start
    default:
      twi_stop();
      return -1;
  }
  
  while(!(TWCR & _BV(TWINT)));
  switch(TW_STATUS){
    case TW_MR_SLA_ACK: // SLA+R transmitted, ACK received
      break;
    case TW_MR_ARB_LOST: // arbitration lost in SLA+R or NACK 
      twi_releaseBus();
      return -1;
    case TW_MR_SLA_NACK: // SLA+R transmitted, NACK received
    case TW_BUS_ERROR: // bus error, illegal stop/start
    default:
      twi_stop();
      return -1;
  }
  
  return 0;
}

/**
 * start receiption transaction
 * 
 * @param address slave address
 * @return when negative value is returned, the transaction has been failed to start.
 * othereise successfully started.
 */
int8_t TwoWireExt::beginReception(uint8_t address){
  return beginReception(address, TWBR);
}

void TwoWireExt::endReception(){
  TWCR = _BV(TWEN) | _BV(TWINT);
  while(!(TWCR & _BV(TWINT)));
  twi_stop();
  
  TWBR = orig_twbr;
}
uint8_t TwoWireExt::get_byte(){
  // clear flag and prepare for sending ack
  TWCR = _BV(TWEN) | _BV(TWINT) | _BV(TWEA);
  while(!(TWCR & _BV(TWINT)));
  switch(TW_STATUS){
    case TW_MR_DATA_ACK: // data received, ACK returned
      break;
    default:
      return 0;
  }
  uint8_t res = TWDR;
  return res;
}


// Preinstantiate Objects //////////////////////////////////////////////////////

TwoWireExt WireExt = TwoWireExt();


