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

#ifndef WireExt_h
#define WireExt_h

#include <inttypes.h>

class TwoWireExt
{
  private:
    uint8_t orig_twbr;
  public:
    TwoWireExt();
    int8_t beginReception(uint8_t);
    int8_t beginReception(uint8_t, int);
    void endReception(void);
    uint8_t get_byte();
};

extern TwoWireExt WireExt;

#endif