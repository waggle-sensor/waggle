# 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/nc_power_on/build/sketch/libs/Time/DateStrings.cpp"
# 1 "/digital/github/waggle/wagman/manager/nc_power_on//"
# 1 "<command-line>"
# 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/nc_power_on/build/sketch/libs/Time/DateStrings.cpp"
/* DateStrings.cpp
 * Definitions for date strings for use with the Time library
 *
 * Updated for Arduino 1.5.7 18 July 2014
 *
 * No memory is consumed in the sketch if your code does not call any of the string methods
 * You can change the text of the strings, make sure the short strings are each exactly 3 characters 
 * the long strings can be any length up to the constant dt_MAX_STRING_LEN defined in Time.h
 * 
 */


# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/pgmspace.h" 1 3
/* Copyright (c) 2002-2007  Marek Michalkiewicz
   Copyright (c) 2006, Carlos Lamas
   Copyright (c) 2009-2010, Jan Waclawek
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.
   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */

/*
   pgmspace.h

   Contributors:
     Created by Marek Michalkiewicz <marekm@linux.org.pl>
     Eric B. Weddington <eric@ecentral.com>
     Wolfgang Haidinger <wh@vmars.tuwien.ac.at> (pgm_read_dword())
     Ivanov Anton <anton@arc.com.ru> (pgm_read_float())
 */

/** \file */
/** \defgroup avr_pgmspace <avr/pgmspace.h>: Program Space Utilities
    \code
    #include <avr/io.h>
    #include <avr/pgmspace.h>
    \endcode

    The functions in this module provide interfaces for a program to access
    data stored in program space (flash memory) of the device.  In order to
    use these functions, the target device must support either the \c LPM or
    \c ELPM instructions.

    \note These functions are an attempt to provide some compatibility with
    header files that come with IAR C, to make porting applications between
    different compilers easier.  This is not 100% compatibility though (GCC
    does not have full support for multiple address spaces yet).

    \note If you are working with strings which are completely based in ram,
    use the standard string functions described in \ref avr_string.

    \note If possible, put your constant tables in the lower 64 KB and use
    pgm_read_byte_near() or pgm_read_word_near() instead of
    pgm_read_byte_far() or pgm_read_word_far() since it is more efficient that
    way, and you can still use the upper 64K for executable code.
    All functions that are suffixed with a \c _P \e require their
    arguments to be in the lower 64 KB of the flash ROM, as they do
    not use ELPM instructions.  This is normally not a big concern as
    the linker setup arranges any program space constants declared
    using the macros from this header file so they are placed right after
    the interrupt vectors, and in front of any executable code.  However,
    it can become a problem if there are too many of these constants, or
    for bootloaders on devices with more than 64 KB of ROM.
    <em>All these functions will not work in that situation.</em>

    \note For <b>Xmega</b> devices, make sure the NVM controller
    command register (\c NVM.CMD or \c NVM_CMD) is set to 0x00 (NOP)
    before using any of these functions.
*/





# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/inttypes.h" 1 3
/* Copyright (c) 2004,2005,2007 Joerg Wunsch
   Copyright (c) 2005, Carlos Lamas
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stdint.h" 1 3 4
# 9 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stdint.h" 3 4
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/stdint.h" 1 3 4
/* Copyright (c) 2002,2004,2005 Marek Michalkiewicz
   Copyright (c) 2005, Carlos Lamas
   Copyright (c) 2005,2007 Joerg Wunsch
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */

/*
 * ISO/IEC 9899:1999  7.18 Integer types <stdint.h>
 */




/** \file */
/** \defgroup avr_stdint <stdint.h>: Standard Integer Types
    \code #include <stdint.h> \endcode

    Use [u]intN_t if you need exactly N bits.

    Since these typedefs are mandated by the C99 standard, they are preferred
    over rolling your own typedefs.  */

/*
 * __USING_MINT8 is defined to 1 if the -mint8 option is in effect.
 */






/* Integer types */
# 119 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/stdint.h" 3 4
/* actual implementation goes here */

typedef signed int int8_t __attribute__((__mode__(__QI__)));
typedef unsigned int uint8_t __attribute__((__mode__(__QI__)));
typedef signed int int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int uint16_t __attribute__ ((__mode__ (__HI__)));
typedef signed int int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int uint32_t __attribute__ ((__mode__ (__SI__)));

typedef signed int int64_t __attribute__((__mode__(__DI__)));
typedef unsigned int uint64_t __attribute__((__mode__(__DI__)));




/** \name Integer types capable of holding object pointers
    These allow you to declare variables of the same size as a pointer. */

/*@{*/

/** \ingroup avr_stdint
    Signed pointer compatible type. */

typedef int16_t intptr_t;

/** \ingroup avr_stdint
    Unsigned pointer compatible type. */

typedef uint16_t uintptr_t;

/*@}*/

/** \name Minimum-width integer types
   Integer types having at least the specified width */

/*@{*/

/** \ingroup avr_stdint
    signed int with at least 8 bits. */

typedef int8_t int_least8_t;

/** \ingroup avr_stdint
    unsigned int with at least 8 bits. */

typedef uint8_t uint_least8_t;

/** \ingroup avr_stdint
    signed int with at least 16 bits. */

typedef int16_t int_least16_t;

/** \ingroup avr_stdint
    unsigned int with at least 16 bits. */

typedef uint16_t uint_least16_t;

/** \ingroup avr_stdint
    signed int with at least 32 bits. */

typedef int32_t int_least32_t;

/** \ingroup avr_stdint
    unsigned int with at least 32 bits. */

typedef uint32_t uint_least32_t;


/** \ingroup avr_stdint
    signed int with at least 64 bits.
    \note This type is not available when the compiler
    option -mint8 is in effect. */

typedef int64_t int_least64_t;

/** \ingroup avr_stdint
    unsigned int with at least 64 bits.
    \note This type is not available when the compiler
    option -mint8 is in effect. */

typedef uint64_t uint_least64_t;


/*@}*/


/** \name Fastest minimum-width integer types
   Integer types being usually fastest having at least the specified width */

/*@{*/

/** \ingroup avr_stdint
    fastest signed int with at least 8 bits. */

typedef int8_t int_fast8_t;

/** \ingroup avr_stdint
    fastest unsigned int with at least 8 bits. */

typedef uint8_t uint_fast8_t;

/** \ingroup avr_stdint
    fastest signed int with at least 16 bits. */

typedef int16_t int_fast16_t;

/** \ingroup avr_stdint
    fastest unsigned int with at least 16 bits. */

typedef uint16_t uint_fast16_t;

/** \ingroup avr_stdint
    fastest signed int with at least 32 bits. */

typedef int32_t int_fast32_t;

/** \ingroup avr_stdint
    fastest unsigned int with at least 32 bits. */

typedef uint32_t uint_fast32_t;


/** \ingroup avr_stdint
    fastest signed int with at least 64 bits.
    \note This type is not available when the compiler
    option -mint8 is in effect. */

typedef int64_t int_fast64_t;

/** \ingroup avr_stdint
    fastest unsigned int with at least 64 bits.
    \note This type is not available when the compiler
    option -mint8 is in effect. */

typedef uint64_t uint_fast64_t;


/*@}*/


/** \name Greatest-width integer types
   Types designating integer data capable of representing any value of
   any integer type in the corresponding signed or unsigned category */

/*@{*/






/** \ingroup avr_stdint
    largest signed int available. */

typedef int64_t intmax_t;

/** \ingroup avr_stdint
    largest unsigned int available. */

typedef uint64_t uintmax_t;


/*@}*/

/* Helping macro */







/** \name Limits of specified-width integer types
   C++ implementations should define these macros only when
   __STDC_LIMIT_MACROS is defined before <stdint.h> is included */

/*@{*/

/** \ingroup avr_stdint
    largest positive value an int8_t can hold. */



/** \ingroup avr_stdint
    smallest negative value an int8_t can hold. */



/** \ingroup avr_stdint
    largest value an uint8_t can hold. */
# 324 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/stdint.h" 3 4
/** \ingroup avr_stdint
    largest positive value an int16_t can hold. */



/** \ingroup avr_stdint
    smallest negative value an int16_t can hold. */



/** \ingroup avr_stdint
    largest value an uint16_t can hold. */



/** \ingroup avr_stdint
    largest positive value an int32_t can hold. */



/** \ingroup avr_stdint
    smallest negative value an int32_t can hold. */



/** \ingroup avr_stdint
    largest value an uint32_t can hold. */





/** \ingroup avr_stdint
    largest positive value an int64_t can hold. */



/** \ingroup avr_stdint
    smallest negative value an int64_t can hold. */



/** \ingroup avr_stdint
    largest value an uint64_t can hold. */



/*@}*/

/** \name Limits of minimum-width integer types */
/*@{*/

/** \ingroup avr_stdint
    largest positive value an int_least8_t can hold. */



/** \ingroup avr_stdint
    smallest negative value an int_least8_t can hold. */



/** \ingroup avr_stdint
    largest value an uint_least8_t can hold. */



/** \ingroup avr_stdint
    largest positive value an int_least16_t can hold. */



/** \ingroup avr_stdint
    smallest negative value an int_least16_t can hold. */



/** \ingroup avr_stdint
    largest value an uint_least16_t can hold. */



/** \ingroup avr_stdint
    largest positive value an int_least32_t can hold. */



/** \ingroup avr_stdint
    smallest negative value an int_least32_t can hold. */



/** \ingroup avr_stdint
    largest value an uint_least32_t can hold. */



/** \ingroup avr_stdint
    largest positive value an int_least64_t can hold. */



/** \ingroup avr_stdint
    smallest negative value an int_least64_t can hold. */



/** \ingroup avr_stdint
    largest value an uint_least64_t can hold. */



/*@}*/

/** \name Limits of fastest minimum-width integer types */

/*@{*/

/** \ingroup avr_stdint
    largest positive value an int_fast8_t can hold. */



/** \ingroup avr_stdint
    smallest negative value an int_fast8_t can hold. */



/** \ingroup avr_stdint
    largest value an uint_fast8_t can hold. */



/** \ingroup avr_stdint
    largest positive value an int_fast16_t can hold. */



/** \ingroup avr_stdint
    smallest negative value an int_fast16_t can hold. */



/** \ingroup avr_stdint
    largest value an uint_fast16_t can hold. */



/** \ingroup avr_stdint
    largest positive value an int_fast32_t can hold. */



/** \ingroup avr_stdint
    smallest negative value an int_fast32_t can hold. */



/** \ingroup avr_stdint
    largest value an uint_fast32_t can hold. */



/** \ingroup avr_stdint
    largest positive value an int_fast64_t can hold. */



/** \ingroup avr_stdint
    smallest negative value an int_fast64_t can hold. */



/** \ingroup avr_stdint
    largest value an uint_fast64_t can hold. */



/*@}*/

/** \name Limits of integer types capable of holding object pointers */

/*@{*/

/** \ingroup avr_stdint
    largest positive value an intptr_t can hold. */



/** \ingroup avr_stdint
    smallest negative value an intptr_t can hold. */



/** \ingroup avr_stdint
    largest value an uintptr_t can hold. */



/*@}*/

/** \name Limits of greatest-width integer types */

/*@{*/

/** \ingroup avr_stdint
    largest positive value an intmax_t can hold. */



/** \ingroup avr_stdint
    smallest negative value an intmax_t can hold. */



/** \ingroup avr_stdint
    largest value an uintmax_t can hold. */



/*@}*/

/** \name Limits of other integer types
    C++ implementations should define these macros only when
    __STDC_LIMIT_MACROS is defined before <stdint.h> is included */

/*@{*/

/** \ingroup avr_stdint
    largest positive value a ptrdiff_t can hold. */



/** \ingroup avr_stdint
    smallest negative value a ptrdiff_t can hold. */




/* Limits of sig_atomic_t */
/* signal.h is currently not implemented (not avr/signal.h) */

/** \ingroup avr_stdint
    largest positive value a sig_atomic_t can hold. */



/** \ingroup avr_stdint
    smallest negative value a sig_atomic_t can hold. */




/** \ingroup avr_stdint
    largest value a size_t can hold. */




/* Limits of wchar_t */
/* wchar.h is currently not implemented */
/* #define WCHAR_MAX */
/* #define WCHAR_MIN */


/* Limits of wint_t */
/* wchar.h is currently not implemented */
/* #define WINT_MAX */
/* #define WINT_MIN */






/** \name Macros for integer constants
    C++ implementations should define these macros only when
    __STDC_CONSTANT_MACROS is defined before <stdint.h> is included.

    These definitions are valid for integer constants without suffix and
    for macros defined as integer constant without suffix */

/** \ingroup avr_stdint
    define a constant of type int8_t */



/** \ingroup avr_stdint
    define a constant of type uint8_t */
# 626 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/stdint.h" 3 4
/** \ingroup avr_stdint
    define a constant of type int16_t */



/** \ingroup avr_stdint
    define a constant of type uint16_t */



/** \ingroup avr_stdint
    define a constant of type int32_t */



/** \ingroup avr_stdint
    define a constant of type uint32_t */





/** \ingroup avr_stdint
    define a constant of type int64_t */



/** \ingroup avr_stdint
    define a constant of type uint64_t */



/** \ingroup avr_stdint
    define a constant of type intmax_t */



/** \ingroup avr_stdint
    define a constant of type uintmax_t */



/*@}*/
# 10 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stdint.h" 2 3 4
# 38 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/inttypes.h" 2 3

/** \file */
/** \defgroup avr_inttypes <inttypes.h>: Integer Type conversions
    \code #include <inttypes.h> \endcode

    This header file includes the exact-width integer definitions from
    <tt><stdint.h></tt>, and extends them with additional facilities
    provided by the implementation.

    Currently, the extensions include two additional integer types
    that could hold a "far" pointer (i.e. a code pointer that can
    address more than 64 KB), as well as standard names for all printf
    and scanf formatting options that are supported by the \ref avr_stdio.
    As the library does not support the full range of conversion
    specifiers from ISO 9899:1999, only those conversions that are
    actually implemented will be listed here.

    The idea behind these conversion macros is that, for each of the
    types defined by <stdint.h>, a macro will be supplied that portably
    allows formatting an object of that type in printf() or scanf()
    operations.  Example:

    \code
    #include <inttypes.h>

    uint8_t smallval;
    int32_t longval;
    ...
    printf("The hexadecimal value of smallval is %" PRIx8
           ", the decimal value of longval is %" PRId32 ".\n",
	   smallval, longval);
    \endcode
*/

/** \name Far pointers for memory access >64K */

/*@{*/
/** \ingroup avr_inttypes
    signed integer type that can hold a pointer > 64 KB */
typedef int32_t int_farptr_t;

/** \ingroup avr_inttypes
    unsigned integer type that can hold a pointer > 64 KB */
typedef uint32_t uint_farptr_t;
/*@}*/




/** \name macros for printf and scanf format specifiers

    For C++, these are only included if __STDC_LIMIT_MACROS
    is defined before including <inttypes.h>.
 */

/*@{*/
/** \ingroup avr_inttypes
    decimal printf format for int8_t */

/** \ingroup avr_inttypes
    decimal printf format for int_least8_t */

/** \ingroup avr_inttypes
    decimal printf format for int_fast8_t */


/** \ingroup avr_inttypes
    integer printf format for int8_t */

/** \ingroup avr_inttypes
    integer printf format for int_least8_t */

/** \ingroup avr_inttypes
    integer printf format for int_fast8_t */



/** \ingroup avr_inttypes
    decimal printf format for int16_t */

/** \ingroup avr_inttypes
    decimal printf format for int_least16_t */

/** \ingroup avr_inttypes
    decimal printf format for int_fast16_t */


/** \ingroup avr_inttypes
    integer printf format for int16_t */

/** \ingroup avr_inttypes
    integer printf format for int_least16_t */

/** \ingroup avr_inttypes
    integer printf format for int_fast16_t */



/** \ingroup avr_inttypes
    decimal printf format for int32_t */

/** \ingroup avr_inttypes
    decimal printf format for int_least32_t */

/** \ingroup avr_inttypes
    decimal printf format for int_fast32_t */


/** \ingroup avr_inttypes
    integer printf format for int32_t */

/** \ingroup avr_inttypes
    integer printf format for int_least32_t */

/** \ingroup avr_inttypes
    integer printf format for int_fast32_t */
# 173 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/inttypes.h" 3
/** \ingroup avr_inttypes
    decimal printf format for intptr_t */

/** \ingroup avr_inttypes
    integer printf format for intptr_t */


/** \ingroup avr_inttypes
    octal printf format for uint8_t */

/** \ingroup avr_inttypes
    octal printf format for uint_least8_t */

/** \ingroup avr_inttypes
    octal printf format for uint_fast8_t */


/** \ingroup avr_inttypes
    decimal printf format for uint8_t */

/** \ingroup avr_inttypes
    decimal printf format for uint_least8_t */

/** \ingroup avr_inttypes
    decimal printf format for uint_fast8_t */


/** \ingroup avr_inttypes
    hexadecimal printf format for uint8_t */

/** \ingroup avr_inttypes
    hexadecimal printf format for uint_least8_t */

/** \ingroup avr_inttypes
    hexadecimal printf format for uint_fast8_t */


/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint8_t */

/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint_least8_t */

/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint_fast8_t */



/** \ingroup avr_inttypes
    octal printf format for uint16_t */

/** \ingroup avr_inttypes
    octal printf format for uint_least16_t */

/** \ingroup avr_inttypes
    octal printf format for uint_fast16_t */


/** \ingroup avr_inttypes
    decimal printf format for uint16_t */

/** \ingroup avr_inttypes
    decimal printf format for uint_least16_t */

/** \ingroup avr_inttypes
    decimal printf format for uint_fast16_t */


/** \ingroup avr_inttypes
    hexadecimal printf format for uint16_t */

/** \ingroup avr_inttypes
    hexadecimal printf format for uint_least16_t */

/** \ingroup avr_inttypes
    hexadecimal printf format for uint_fast16_t */


/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint16_t */

/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint_least16_t */

/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint_fast16_t */



/** \ingroup avr_inttypes
    octal printf format for uint32_t */

/** \ingroup avr_inttypes
    octal printf format for uint_least32_t */

/** \ingroup avr_inttypes
    octal printf format for uint_fast32_t */


/** \ingroup avr_inttypes
    decimal printf format for uint32_t */

/** \ingroup avr_inttypes
    decimal printf format for uint_least32_t */

/** \ingroup avr_inttypes
    decimal printf format for uint_fast32_t */


/** \ingroup avr_inttypes
    hexadecimal printf format for uint32_t */

/** \ingroup avr_inttypes
    hexadecimal printf format for uint_least32_t */

/** \ingroup avr_inttypes
    hexadecimal printf format for uint_fast32_t */


/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint32_t */

/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint_least32_t */

/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint_fast32_t */
# 328 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/inttypes.h" 3
/** \ingroup avr_inttypes
    octal printf format for uintptr_t */

/** \ingroup avr_inttypes
    decimal printf format for uintptr_t */

/** \ingroup avr_inttypes
    hexadecimal printf format for uintptr_t */

/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uintptr_t */
# 355 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/inttypes.h" 3
/** \ingroup avr_inttypes
    decimal scanf format for int16_t */

/** \ingroup avr_inttypes
    decimal scanf format for int_least16_t */

/** \ingroup avr_inttypes
    decimal scanf format for int_fast16_t */


/** \ingroup avr_inttypes
    generic-integer scanf format for int16_t */

/** \ingroup avr_inttypes
    generic-integer scanf format for int_least16_t */

/** \ingroup avr_inttypes
    generic-integer scanf format for int_fast16_t */



/** \ingroup avr_inttypes
    decimal scanf format for int32_t */

/** \ingroup avr_inttypes
    decimal scanf format for int_least32_t */

/** \ingroup avr_inttypes
    decimal scanf format for int_fast32_t */


/** \ingroup avr_inttypes
    generic-integer scanf format for int32_t */

/** \ingroup avr_inttypes
    generic-integer scanf format for int_least32_t */

/** \ingroup avr_inttypes
    generic-integer scanf format for int_fast32_t */
# 412 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/inttypes.h" 3
/** \ingroup avr_inttypes
    decimal scanf format for intptr_t */

/** \ingroup avr_inttypes
    generic-integer scanf format for intptr_t */
# 435 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/inttypes.h" 3
/** \ingroup avr_inttypes
    octal scanf format for uint16_t */

/** \ingroup avr_inttypes
    octal scanf format for uint_least16_t */

/** \ingroup avr_inttypes
    octal scanf format for uint_fast16_t */


/** \ingroup avr_inttypes
    decimal scanf format for uint16_t */

/** \ingroup avr_inttypes
    decimal scanf format for uint_least16_t */

/** \ingroup avr_inttypes
    decimal scanf format for uint_fast16_t */


/** \ingroup avr_inttypes
    hexadecimal scanf format for uint16_t */

/** \ingroup avr_inttypes
    hexadecimal scanf format for uint_least16_t */

/** \ingroup avr_inttypes
    hexadecimal scanf format for uint_fast16_t */



/** \ingroup avr_inttypes
    octal scanf format for uint32_t */

/** \ingroup avr_inttypes
    octal scanf format for uint_least32_t */

/** \ingroup avr_inttypes
    octal scanf format for uint_fast32_t */


/** \ingroup avr_inttypes
    decimal scanf format for uint32_t */

/** \ingroup avr_inttypes
    decimal scanf format for uint_least32_t */

/** \ingroup avr_inttypes
    decimal scanf format for uint_fast32_t */


/** \ingroup avr_inttypes
    hexadecimal scanf format for uint32_t */

/** \ingroup avr_inttypes
    hexadecimal scanf format for uint_least32_t */

/** \ingroup avr_inttypes
    hexadecimal scanf format for uint_fast32_t */
# 517 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/inttypes.h" 3
/** \ingroup avr_inttypes
    octal scanf format for uintptr_t */

/** \ingroup avr_inttypes
    decimal scanf format for uintptr_t */

/** \ingroup avr_inttypes
    hexadecimal scanf format for uintptr_t */


/*@}*/
# 87 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/pgmspace.h" 2 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stddef.h" 1 3 4
/* Copyright (C) 1989-2013 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.17  Common definitions  <stddef.h>
 */






/* Any one of these symbols __need_* means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done.  */
# 46 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stddef.h" 3 4
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */

/* On 4.3bsd-net2, make sure ansi.h is included, so we have
   one less case to deal with in the following.  */



/* On FreeBSD 5, machine/ansi.h does not exist anymore... */




/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
   defined if the corresponding type is *not* defined.
   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_ */
# 92 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 117 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 162 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stddef.h" 3 4
/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 212 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stddef.h" 3 4
typedef unsigned int size_t;
# 238 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stddef.h" 3 4
/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 358 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stddef.h" 3 4
/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
    are already defined.  */
/*  BSD/OS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
# 394 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stddef.h" 3 4
/* A null pointer constant.  */
# 88 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/pgmspace.h" 2 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/io.h" 1 3
/* Copyright (c) 2002,2003,2005,2006,2007 Marek Michalkiewicz, Joerg Wunsch
   Copyright (c) 2007 Eric B. Weddington
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */

/** \file */
/** \defgroup avr_io <avr/io.h>: AVR device-specific IO definitions
    \code #include <avr/io.h> \endcode

    This header file includes the apropriate IO definitions for the
    device that has been specified by the <tt>-mmcu=</tt> compiler
    command-line switch.  This is done by diverting to the appropriate
    file <tt>&lt;avr/io</tt><em>XXXX</em><tt>.h&gt;</tt> which should
    never be included directly.  Some register names common to all
    AVR devices are defined directly within <tt>&lt;avr/common.h&gt;</tt>,
    which is included in <tt>&lt;avr/io.h&gt;</tt>,
    but most of the details come from the respective include file.

    Note that this file always includes the following files:
    \code 
    #include <avr/sfr_defs.h>
    #include <avr/portpins.h>
    #include <avr/common.h>
    #include <avr/version.h>
    \endcode
    See \ref avr_sfr for more details about that header file.

    Included are definitions of the IO register set and their
    respective bit values as specified in the Atmel documentation.
    Note that inconsistencies in naming conventions,
    so even identical functions sometimes get different names on
    different devices.

    Also included are the specific names useable for interrupt
    function definitions as documented
    \ref avr_signames "here".

    Finally, the following macros are defined:

    - \b RAMEND
    <br>
    The last on-chip RAM address.
    <br>
    - \b XRAMEND
    <br>
    The last possible RAM location that is addressable. This is equal to 
    RAMEND for devices that do not allow for external RAM. For devices 
    that allow external RAM, this will be larger than RAMEND.
    <br>
    - \b E2END
    <br>
    The last EEPROM address.
    <br>
    - \b FLASHEND
    <br>
    The last byte address in the Flash program space.
    <br>
    - \b SPM_PAGESIZE
    <br>
    For devices with bootloader support, the flash pagesize
    (in bytes) to be used for the \c SPM instruction. 
    - \b E2PAGESIZE
    <br>
    The size of the EEPROM page.
    
*/




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/sfr_defs.h" 1 3
/* Copyright (c) 2002, Marek Michalkiewicz <marekm@amelek.gda.pl>
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.  */

/* avr/sfr_defs.h - macros for accessing AVR special function registers */

/* $Id$ */




/** \defgroup avr_sfr_notes Additional notes from <avr/sfr_defs.h>
    \ingroup avr_sfr

   The \c <avr/sfr_defs.h> file is included by all of the \c <avr/ioXXXX.h>
   files, which use macros defined here to make the special function register
   definitions look like C variables or simple constants, depending on the
   <tt>_SFR_ASM_COMPAT</tt> define.  Some examples from \c <avr/iocanxx.h> to
   show how to define such macros:

\code
#define PORTA   _SFR_IO8(0x02)
#define EEAR    _SFR_IO16(0x21)
#define UDR0    _SFR_MEM8(0xC6)
#define TCNT3   _SFR_MEM16(0x94)
#define CANIDT  _SFR_MEM32(0xF0)
\endcode

   If \c _SFR_ASM_COMPAT is not defined, C programs can use names like
   <tt>PORTA</tt> directly in C expressions (also on the left side of
   assignment operators) and GCC will do the right thing (use short I/O
   instructions if possible).  The \c __SFR_OFFSET definition is not used in
   any way in this case.

   Define \c _SFR_ASM_COMPAT as 1 to make these names work as simple constants
   (addresses of the I/O registers).  This is necessary when included in
   preprocessed assembler (*.S) source files, so it is done automatically if
   \c __ASSEMBLER__ is defined.  By default, all addresses are defined as if
   they were memory addresses (used in \c lds/sts instructions).  To use these
   addresses in \c in/out instructions, you must subtract 0x20 from them.

   For more backwards compatibility, insert the following at the start of your
   old assembler source file:

\code
#define __SFR_OFFSET 0
\endcode

   This automatically subtracts 0x20 from I/O space addresses, but it's a
   hack, so it is recommended to change your source: wrap such addresses in
   macros defined here, as shown below.  After this is done, the
   <tt>__SFR_OFFSET</tt> definition is no longer necessary and can be removed.

   Real example - this code could be used in a boot loader that is portable
   between devices with \c SPMCR at different addresses.

\verbatim
<avr/iom163.h>: #define SPMCR _SFR_IO8(0x37)
<avr/iom128.h>: #define SPMCR _SFR_MEM8(0x68)
\endverbatim

\code
#if _SFR_IO_REG_P(SPMCR)
	out	_SFR_IO_ADDR(SPMCR), r24
#else
	sts	_SFR_MEM_ADDR(SPMCR), r24
#endif
\endcode

   You can use the \c in/out/cbi/sbi/sbic/sbis instructions, without the
   <tt>_SFR_IO_REG_P</tt> test, if you know that the register is in the I/O
   space (as with \c SREG, for example).  If it isn't, the assembler will
   complain (I/O address out of range 0...0x3f), so this should be fairly
   safe.

   If you do not define \c __SFR_OFFSET (so it will be 0x20 by default), all
   special register addresses are defined as memory addresses (so \c SREG is
   0x5f), and (if code size and speed are not important, and you don't like
   the ugly \#if above) you can always use lds/sts to access them.  But, this
   will not work if <tt>__SFR_OFFSET</tt> != 0x20, so use a different macro
   (defined only if <tt>__SFR_OFFSET</tt> == 0x20) for safety:

\code
	sts	_SFR_ADDR(SPMCR), r24
\endcode

   In C programs, all 3 combinations of \c _SFR_ASM_COMPAT and
   <tt>__SFR_OFFSET</tt> are supported - the \c _SFR_ADDR(SPMCR) macro can be
   used to get the address of the \c SPMCR register (0x57 or 0x68 depending on
   device). */
# 125 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/sfr_defs.h" 3
/* These only work in C programs.  */
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/inttypes.h" 1 3
/* Copyright (c) 2004,2005,2007 Joerg Wunsch
   Copyright (c) 2005, Carlos Lamas
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */
# 127 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/sfr_defs.h" 2 3
# 194 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/sfr_defs.h" 3
/** \name Bit manipulation */

/*@{*/
/** \def _BV
    \ingroup avr_sfr

    \code #include <avr/io.h>\endcode

    Converts a bit number into a byte value.

    \note The bit shift is performed by the compiler which then inserts the
    result into the code. Thus, there is no run-time overhead when using
    _BV(). */



/*@}*/
# 219 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/sfr_defs.h" 3
/** \name IO register bit manipulation */

/*@{*/



/** \def bit_is_set
    \ingroup avr_sfr

    \code #include <avr/io.h>\endcode

    Test whether bit \c bit in IO register \c sfr is set. 
    This will return a 0 if the bit is clear, and non-zero
    if the bit is set. */



/** \def bit_is_clear
    \ingroup avr_sfr

    \code #include <avr/io.h>\endcode

    Test whether bit \c bit in IO register \c sfr is clear. 
    This will return non-zero if the bit is clear, and a 0
    if the bit is set. */



/** \def loop_until_bit_is_set
    \ingroup avr_sfr

    \code #include <avr/io.h>\endcode

    Wait until bit \c bit in IO register \c sfr is set. */



/** \def loop_until_bit_is_clear
    \ingroup avr_sfr

    \code #include <avr/io.h>\endcode

    Wait until bit \c bit in IO register \c sfr is clear. */



/*@}*/
# 100 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/io.h" 2 3
# 144 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/io.h" 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/iom32u4.h" 1 3
/* Copyright (c) 2008 Atmel Corporation

   All rights reserved.



   Redistribution and use in source and binary forms, with or without

   modification, are permitted provided that the following conditions are met:



   * Redistributions of source code must retain the above copyright

     notice, this list of conditions and the following disclaimer.



   * Redistributions in binary form must reproduce the above copyright

     notice, this list of conditions and the following disclaimer in

     the documentation and/or other materials provided with the

     distribution.



   * Neither the name of the copyright holders nor the names of

     contributors may be used to endorse or promote products derived

     from this software without specific prior written permission.



  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"

  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE

  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE

  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE

  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR

  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF

  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS

  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN

  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)

  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE

  POSSIBILITY OF SUCH DAMAGE. 

*/
# 32 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/iom32u4.h" 3
/* $Id: iom32u4.h 2225 2011-03-02 16:27:26Z arcanum $ */

/* avr/iom32u4.h - definitions for ATmega32U4. */

/* This file should only be included from <avr/io.h>, never directly. */
# 53 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/iom32u4.h" 3
/* Registers and associated bit numbers */
# 1356 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/iom32u4.h" 3
/* Interrupt Vectors */
/* Interrupt Vector 0 is the reset vector. */
# 1471 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/iom32u4.h" 3
/* Constants */
# 1485 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/iom32u4.h" 3
/* Fuses */


/* Low Fuse Byte */
# 1499 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/iom32u4.h" 3
/* High Fuse Byte */
# 1510 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/iom32u4.h" 3
/* Extended Fuse Byte */
# 1519 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/iom32u4.h" 3
/* Lock Bits */






/* Signature */
# 145 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/io.h" 2 3
# 616 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/io.h" 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/portpins.h" 1 3
/* Copyright (c) 2003  Theodore A. Roth
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */




/* This file should only be included from <avr/io.h>, never directly. */





/* Define Generic PORTn, DDn, and PINn values. */

/* Port Data Register (generic) */
# 54 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/portpins.h" 3
/* Port Data Direction Register (generic) */
# 64 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/portpins.h" 3
/* Port Input Pins (generic) */
# 74 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/portpins.h" 3
/* Define PORTxn an Pxn values for all possible port pins if not defined already by io.h. */

/* PORT A */
# 119 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/portpins.h" 3
/* PORT B */
# 162 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/portpins.h" 3
/* PORT C */
# 205 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/portpins.h" 3
/* PORT D */
# 248 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/portpins.h" 3
/* PORT E */
# 291 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/portpins.h" 3
/* PORT F */
# 334 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/portpins.h" 3
/* PORT G */
# 377 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/portpins.h" 3
/* PORT H */
# 420 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/portpins.h" 3
/* PORT J */
# 463 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/portpins.h" 3
/* PORT K */
# 506 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/portpins.h" 3
/* PORT L */
# 617 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/io.h" 2 3

# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/common.h" 1 3
/* Copyright (c) 2007 Eric B. Weddington
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */





# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/sfr_defs.h" 1 3
/* Copyright (c) 2002, Marek Michalkiewicz <marekm@amelek.gda.pl>
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.  */

/* avr/sfr_defs.h - macros for accessing AVR special function registers */

/* $Id$ */
# 38 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/common.h" 2 3

/* 
This purpose of this header is to define registers that have not been 
previously defined in the individual device IO header files, and to define 
other symbols that are common across AVR device families.

This file is designed to be included in <avr/io.h> after the individual
device IO header files, and after <avr/sfr_defs.h>

*/

/*------------ Registers Not Previously Defined ------------*/

/* 
These are registers that are not previously defined in the individual
IO header files, OR they are defined here because they are used in parts of
avr-libc even if a device is not selected but a general architecture has
been selected.
*/


/*
Stack pointer register.

AVR architecture 1 has no RAM, thus no stack pointer. 

All other architectures do have a stack pointer.  Some devices have only
less than 256 bytes of possible RAM locations (128 Bytes of SRAM
and no option for external RAM), thus SPH is officially "reserved"
for them.
*/
# 98 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/common.h" 3
/* Status Register */
# 108 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/common.h" 3
/* SREG bit definitions */
# 206 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/common.h" 3
/*------------ Common Symbols ------------*/

/* 
Generic definitions for registers that are common across multiple AVR devices
and families.
*/

/* Pointer registers definitions */
# 224 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/common.h" 3
/* Status Register */
# 234 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/common.h" 3
/* Stack Pointer (combined) Register */
# 244 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/common.h" 3
/* Stack Pointer High Register */
# 255 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/common.h" 3
/* Stack Pointer Low Register */
# 265 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/common.h" 3
/* RAMPD Register */
# 275 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/common.h" 3
/* RAMPX Register */
# 285 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/common.h" 3
/* RAMPY Register */
# 295 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/common.h" 3
/* RAMPZ Register */
# 305 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/common.h" 3
/* Extended Indirect Register */
# 315 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/common.h" 3
/*------------ Workaround to old compilers (4.1.2 and earlier)  ------------*/
# 619 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/io.h" 2 3

# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/version.h" 1 3
/* Copyright (c) 2005, Joerg Wunsch                               -*- c -*-
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */

/** \defgroup avr_version <avr/version.h>: avr-libc version macros
    \code #include <avr/version.h> \endcode

    This header file defines macros that contain version numbers and
    strings describing the current version of avr-libc.

    The version number itself basically consists of three pieces that
    are separated by a dot: the major number, the minor number, and
    the revision number.  For development versions (which use an odd
    minor number), the string representation additionally gets the
    date code (YYYYMMDD) appended.

    This file will also be included by \c <avr/io.h>.  That way,
    portable tests can be implemented using \c <avr/io.h> that can be
    used in code that wants to remain backwards-compatible to library
    versions prior to the date when the library version API had been
    added, as referenced but undefined C preprocessor macros
    automatically evaluate to 0.
*/




/** \ingroup avr_version
    String literal representation of the current library version. */


/** \ingroup avr_version
    Numerical representation of the current library version.

    In the numerical representation, the major number is multiplied by
    10000, the minor number by 100, and all three parts are then
    added.  It is intented to provide a monotonically increasing
    numerical value that can easily be used in numerical checks.
 */


/** \ingroup avr_version
    String literal representation of the release date. */


/** \ingroup avr_version
    Numerical representation of the release date. */


/** \ingroup avr_version
    Library major version number. */


/** \ingroup avr_version
    Library minor version number. */


/** \ingroup avr_version
    Library revision number. */
# 621 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/io.h" 2 3





/* Include fuse.h after individual IO header files. */
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/fuse.h" 1 3
/* Copyright (c) 2007, Atmel Corporation
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */

/* avr/fuse.h - Fuse API */




/* This file must be explicitly included by <avr/io.h>. */





/** \file */
/** \defgroup avr_fuse <avr/fuse.h>: Fuse Support

    \par Introduction

    The Fuse API allows a user to specify the fuse settings for the specific
    AVR device they are compiling for. These fuse settings will be placed
    in a special section in the ELF output file, after linking.

    Programming tools can take advantage of the fuse information embedded in
    the ELF file, by extracting this information and determining if the fuses
    need to be programmed before programming the Flash and EEPROM memories.
    This also allows a single ELF file to contain all the
    information needed to program an AVR. 

    To use the Fuse API, include the <avr/io.h> header file, which in turn
    automatically includes the individual I/O header file and the <avr/fuse.h>
    file. These other two files provides everything necessary to set the AVR
    fuses.
    
    \par Fuse API
    
    Each I/O header file must define the FUSE_MEMORY_SIZE macro which is
    defined to the number of fuse bytes that exist in the AVR device.
    
    A new type, __fuse_t, is defined as a structure. The number of fields in 
    this structure are determined by the number of fuse bytes in the 
    FUSE_MEMORY_SIZE macro.
    
    If FUSE_MEMORY_SIZE == 1, there is only a single field: byte, of type
    unsigned char.
    
    If FUSE_MEMORY_SIZE == 2, there are two fields: low, and high, of type
    unsigned char.
    
    If FUSE_MEMORY_SIZE == 3, there are three fields: low, high, and extended,
    of type unsigned char.
    
    If FUSE_MEMORY_SIZE > 3, there is a single field: byte, which is an array
    of unsigned char with the size of the array being FUSE_MEMORY_SIZE.
    
    A convenience macro, FUSEMEM, is defined as a GCC attribute for a 
    custom-named section of ".fuse".
    
    A convenience macro, FUSES, is defined that declares a variable, __fuse, of
    type __fuse_t with the attribute defined by FUSEMEM. This variable
    allows the end user to easily set the fuse data.

    \note If a device-specific I/O header file has previously defined FUSEMEM,
    then FUSEMEM is not redefined. If a device-specific I/O header file has
    previously defined FUSES, then FUSES is not redefined.

    Each AVR device I/O header file has a set of defined macros which specify the
    actual fuse bits available on that device. The AVR fuses have inverted
    values, logical 1 for an unprogrammed (disabled) bit and logical 0 for a
    programmed (enabled) bit. The defined macros for each individual fuse
    bit represent this in their definition by a bit-wise inversion of a mask.
    For example, the FUSE_EESAVE fuse in the ATmega128 is defined as:
    \code
    #define FUSE_EESAVE      ~_BV(3)
    \endcode
    \note The _BV macro creates a bit mask from a bit number. It is then 
    inverted to represent logical values for a fuse memory byte.
    
    To combine the fuse bits macros together to represent a whole fuse byte,
    use the bitwise AND operator, like so:
    \code
    (FUSE_BOOTSZ0 & FUSE_BOOTSZ1 & FUSE_EESAVE & FUSE_SPIEN & FUSE_JTAGEN)
    \endcode
    
    Each device I/O header file also defines macros that provide default values
    for each fuse byte that is available. LFUSE_DEFAULT is defined for a Low
    Fuse byte. HFUSE_DEFAULT is defined for a High Fuse byte. EFUSE_DEFAULT
    is defined for an Extended Fuse byte.
    
    If FUSE_MEMORY_SIZE > 3, then the I/O header file defines macros that
    provide default values for each fuse byte like so:
    FUSE0_DEFAULT
    FUSE1_DEFAULT
    FUSE2_DEFAULT
    FUSE3_DEFAULT
    FUSE4_DEFAULT
    ....
    
    \par API Usage Example
    
    Putting all of this together is easy. Using C99's designated initializers:
    
    \code
    #include <avr/io.h>

    FUSES = 
    {
        .low = LFUSE_DEFAULT,
        .high = (FUSE_BOOTSZ0 & FUSE_BOOTSZ1 & FUSE_EESAVE & FUSE_SPIEN & FUSE_JTAGEN),
        .extended = EFUSE_DEFAULT,
    };

    int main(void)
    {
        return 0;
    }
    \endcode
    
    Or, using the variable directly instead of the FUSES macro,
    
    \code
    #include <avr/io.h>

    __fuse_t __fuse __attribute__((section (".fuse"))) = 
    {
        .low = LFUSE_DEFAULT,
        .high = (FUSE_BOOTSZ0 & FUSE_BOOTSZ1 & FUSE_EESAVE & FUSE_SPIEN & FUSE_JTAGEN),
        .extended = EFUSE_DEFAULT,
    };

    int main(void)
    {
        return 0;
    }
    \endcode
    
    If you are compiling in C++, you cannot use the designated intializers so
    you must do:

    \code
    #include <avr/io.h>

    FUSES = 
    {
        LFUSE_DEFAULT, // .low
        (FUSE_BOOTSZ0 & FUSE_BOOTSZ1 & FUSE_EESAVE & FUSE_SPIEN & FUSE_JTAGEN), // .high
        EFUSE_DEFAULT, // .extended
    };

    int main(void)
    {
        return 0;
    }
    \endcode
    
    
    However there are a number of caveats that you need to be aware of to
    use this API properly.
    
    Be sure to include <avr/io.h> to get all of the definitions for the API.
    The FUSES macro defines a global variable to store the fuse data. This 
    variable is assigned to its own linker section. Assign the desired fuse 
    values immediately in the variable initialization.
    
    The .fuse section in the ELF file will get its values from the initial 
    variable assignment ONLY. This means that you can NOT assign values to 
    this variable in functions and the new values will not be put into the
    ELF .fuse section.
    
    The global variable is declared in the FUSES macro has two leading 
    underscores, which means that it is reserved for the "implementation",
    meaning the library, so it will not conflict with a user-named variable.
    
    You must initialize ALL fields in the __fuse_t structure. This is because
    the fuse bits in all bytes default to a logical 1, meaning unprogrammed. 
    Normal uninitialized data defaults to all locgial zeros. So it is vital that
    all fuse bytes are initialized, even with default data. If they are not,
    then the fuse bits may not programmed to the desired settings.
    
    Be sure to have the -mmcu=<em>device</em> flag in your compile command line and
    your linker command line to have the correct device selected and to have 
    the correct I/O header file included when you include <avr/io.h>.

    You can print out the contents of the .fuse section in the ELF file by
    using this command line:
    \code
    avr-objdump -s -j .fuse <ELF file>
    \endcode
    The section contents shows the address on the left, then the data going from
    lower address to a higher address, left to right.

*/
# 239 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/fuse.h" 3
typedef struct
{
    unsigned char low;
    unsigned char high;
    unsigned char extended;
} __fuse_t;
# 628 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/io.h" 2 3

/* Include lock.h after individual IO header files. */
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/lock.h" 1 3
/* Copyright (c) 2007, Atmel Corporation
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */

/* avr/lock.h - Lock Bits API */





/** \file */
/** \defgroup avr_lock <avr/lock.h>: Lockbit Support

    \par Introduction

    The Lockbit API allows a user to specify the lockbit settings for the 
    specific AVR device they are compiling for. These lockbit settings will be 
    placed in a special section in the ELF output file, after linking.

    Programming tools can take advantage of the lockbit information embedded in
    the ELF file, by extracting this information and determining if the lockbits
    need to be programmed after programming the Flash and EEPROM memories.
    This also allows a single ELF file to contain all the
    information needed to program an AVR. 

    To use the Lockbit API, include the <avr/io.h> header file, which in turn
    automatically includes the individual I/O header file and the <avr/lock.h>
    file. These other two files provides everything necessary to set the AVR
    lockbits.
    
    \par Lockbit API
    
    Each I/O header file may define up to 3 macros that controls what kinds
    of lockbits are available to the user.
    
    If __LOCK_BITS_EXIST is defined, then two lock bits are available to the
    user and 3 mode settings are defined for these two bits.
    
    If __BOOT_LOCK_BITS_0_EXIST is defined, then the two BLB0 lock bits are
    available to the user and 4 mode settings are defined for these two bits.
    
    If __BOOT_LOCK_BITS_1_EXIST is defined, then the two BLB1 lock bits are
    available to the user and 4 mode settings are defined for these two bits.

    If __BOOT_LOCK_APPLICATION_TABLE_BITS_EXIST is defined then two lock bits
    are available to set the locking mode for the Application Table Section 
    (which is used in the XMEGA family).
    
    If __BOOT_LOCK_APPLICATION_BITS_EXIST is defined then two lock bits are
    available to set the locking mode for the Application Section (which is used
    in the XMEGA family).
    
    If __BOOT_LOCK_BOOT_BITS_EXIST is defined then two lock bits are available
    to set the locking mode for the Boot Loader Section (which is used in the
    XMEGA family).

    The AVR lockbit modes have inverted values, logical 1 for an unprogrammed 
    (disabled) bit and logical 0 for a programmed (enabled) bit. The defined 
    macros for each individual lock bit represent this in their definition by a 
    bit-wise inversion of a mask. For example, the LB_MODE_3 macro is defined 
    as:
    \code
    #define LB_MODE_3  (0xFC)
`   \endcode
    
    To combine the lockbit mode macros together to represent a whole byte,
    use the bitwise AND operator, like so:
    \code
    (LB_MODE_3 & BLB0_MODE_2)
    \endcode
    
    <avr/lock.h> also defines a macro that provides a default lockbit value:
    LOCKBITS_DEFAULT which is defined to be 0xFF.

    See the AVR device specific datasheet for more details about these
    lock bits and the available mode settings.
    
    A convenience macro, LOCKMEM, is defined as a GCC attribute for a 
    custom-named section of ".lock".
    
    A convenience macro, LOCKBITS, is defined that declares a variable, __lock, 
    of type unsigned char with the attribute defined by LOCKMEM. This variable
    allows the end user to easily set the lockbit data.

    \note If a device-specific I/O header file has previously defined LOCKMEM,
    then LOCKMEM is not redefined. If a device-specific I/O header file has
    previously defined LOCKBITS, then LOCKBITS is not redefined. LOCKBITS is
    currently known to be defined in the I/O header files for the XMEGA devices.

    \par API Usage Example
    
    Putting all of this together is easy:
    
    \code
    #include <avr/io.h>

    LOCKBITS = (LB_MODE_1 & BLB0_MODE_3 & BLB1_MODE_4);

    int main(void)
    {
        return 0;
    }
    \endcode
    
    Or:
    
    \code
    #include <avr/io.h>

    unsigned char __lock __attribute__((section (".lock"))) = 
        (LB_MODE_1 & BLB0_MODE_3 & BLB1_MODE_4);

    int main(void)
    {
        return 0;
    }
    \endcode
    
    
    
    However there are a number of caveats that you need to be aware of to
    use this API properly.
    
    Be sure to include <avr/io.h> to get all of the definitions for the API.
    The LOCKBITS macro defines a global variable to store the lockbit data. This 
    variable is assigned to its own linker section. Assign the desired lockbit 
    values immediately in the variable initialization.
    
    The .lock section in the ELF file will get its values from the initial 
    variable assignment ONLY. This means that you can NOT assign values to 
    this variable in functions and the new values will not be put into the
    ELF .lock section.
    
    The global variable is declared in the LOCKBITS macro has two leading 
    underscores, which means that it is reserved for the "implementation",
    meaning the library, so it will not conflict with a user-named variable.
    
    You must initialize the lockbit variable to some meaningful value, even
    if it is the default value. This is because the lockbits default to a 
    logical 1, meaning unprogrammed. Normal uninitialized data defaults to all 
    locgial zeros. So it is vital that all lockbits are initialized, even with 
    default data. If they are not, then the lockbits may not programmed to the 
    desired settings and can possibly put your device into an unrecoverable 
    state.
    
    Be sure to have the -mmcu=<em>device</em> flag in your compile command line and
    your linker command line to have the correct device selected and to have 
    the correct I/O header file included when you include <avr/io.h>.

    You can print out the contents of the .lock section in the ELF file by
    using this command line:
    \code
    avr-objdump -s -j .lock <ELF file>
    \endcode

*/
# 200 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/lock.h" 3
/* Lock Bit Modes */
# 631 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/io.h" 2 3
# 89 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/pgmspace.h" 2 3
# 102 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
/**
   \ingroup avr_pgmspace
   \def PROGMEM

   Attribute to use in order to declare an object being located in
   flash ROM.
 */



extern "C" {
# 382 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
/* Although in C, we can get away with just using __c, it does not work in
   C++. We need to use &__c[0] to avoid the compiler puking. Dave Hylands
   explaned it thusly,

     Let's suppose that we use PSTR("Test"). In this case, the type returned
     by __c is a prog_char[5] and not a prog_char *. While these are
     compatible, they aren't the same thing (especially in C++). The type
     returned by &__c[0] is a prog_char *, which explains why it works
     fine. */
# 403 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
/* The real thing. */
# 611 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
/*
Macro to read data from program memory for avr tiny parts(tiny 4/5/9/10/20/40).
why:
- LPM instruction is not available in AVR_TINY instruction set.
- Programs are executed starting from address 0x0000 in program memory.
But it must be addressed starting from 0x4000 when accessed via data memory.
Reference: TINY device (ATTiny 4,5,9,10,20 and 40) datasheets
Bug: avrtc-536
*/
# 632 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
/** \ingroup avr_pgmspace
    \def pgm_read_byte_near(address_short)
    Read a byte from the program space with a 16-bit (near) address. 
    \note The address is a byte address.
    The address is in the program space. */



/** \ingroup avr_pgmspace
    \def pgm_read_word_near(address_short)
    Read a word from the program space with a 16-bit (near) address. 
    \note The address is a byte address. 
    The address is in the program space. */



/** \ingroup avr_pgmspace
    \def pgm_read_dword_near(address_short)
    Read a double word from the program space with a 16-bit (near) address. 
    \note The address is a byte address. 
    The address is in the program space. */




/** \ingroup avr_pgmspace
    \def pgm_read_float_near(address_short)
    Read a float from the program space with a 16-bit (near) address. 
    \note The address is a byte address. 
    The address is in the program space. */




/** \ingroup avr_pgmspace
    \def pgm_read_ptr_near(address_short)
    Read a pointer from the program space with a 16-bit (near) address. 
    \note The address is a byte address. 
    The address is in the program space. */






/* Only for devices with more than 64K of program memory.
   RAMPZ must be defined (see iom103.h, iom128.h).
*/

/* The classic functions are needed for ATmega103. */
# 959 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
/* 
Check for architectures that implement RAMPD (avrxmega3, avrxmega5, 
avrxmega7) as they need to save/restore RAMPZ for ELPM macros so it does
not interfere with data accesses. 
*/
# 992 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
/** \ingroup avr_pgmspace
    \def pgm_read_byte_far(address_long)
    Read a byte from the program space with a 32-bit (far) address. 

    \note The address is a byte address. 
    The address is in the program space. */



/** \ingroup avr_pgmspace
    \def pgm_read_word_far(address_long)
    Read a word from the program space with a 32-bit (far) address. 

    \note The address is a byte address.
    The address is in the program space. */



/** \ingroup avr_pgmspace
    \def pgm_read_dword_far(address_long)
    Read a double word from the program space with a 32-bit (far) address. 

    \note The address is a byte address.
    The address is in the program space. */



/** \ingroup avr_pgmspace
    \def pgm_read_float_far(address_long)
    Read a float from the program space with a 32-bit (far) address. 

    \note The address is a byte address.
    The address is in the program space. */



/** \ingroup avr_pgmspace
    \def pgm_read_ptr_far(address_long)
    Read a pointer from the program space with a 32-bit (far) address. 

    \note The address is a byte address.
    The address is in the program space. */





/** \ingroup avr_pgmspace
    \def pgm_read_byte(address_short)
    Read a byte from the program space with a 16-bit (near) address. 

    \note The address is a byte address. 
    The address is in the program space. */



/** \ingroup avr_pgmspace
    \def pgm_read_word(address_short)
    Read a word from the program space with a 16-bit (near) address. 

    \note The address is a byte address. 
    The address is in the program space. */



/** \ingroup avr_pgmspace
    \def pgm_read_dword(address_short)
    Read a double word from the program space with a 16-bit (near) address. 

    \note The address is a byte address. 
    The address is in the program space. */



/** \ingroup avr_pgmspace
    \def pgm_read_float(address_short)
    Read a float from the program space with a 16-bit (near) address. 

    \note The address is a byte address. 
    The address is in the program space. */



/** \ingroup avr_pgmspace
    \def pgm_read_ptr(address_short)
    Read a pointer from the program space with a 16-bit (near) address. 

    \note The address is a byte address. 
    The address is in the program space. */



/* pgm_get_far_address() macro

   This macro facilitates the obtention of a 32 bit "far" pointer (only 24 bits
   used) to data even passed the 64KB limit for the 16 bit ordinary pointer. It
   is similar to the '&' operator, with some limitations.

   Comments:

   - The overhead is minimal and it's mainly due to the 32 bit size operation.

   - 24 bit sizes guarantees the code compatibility for use in future devices.

   - hh8() is an undocumented feature but seems to give the third significant byte
     of a 32 bit data and accepts symbols, complementing the functionality of hi8()
     and lo8(). There is not an equivalent assembler function to get the high
     significant byte.

   - 'var' has to be resolved at linking time as an existing symbol, i.e, a simple
     type variable name, an array name (not an indexed element of the array, if the
     index is a constant the compiler does not complain but fails to get the address
     if optimization is enabled), a struct name or a struct field name, a function
     identifier, a linker defined identifier,...

   - The returned value is the identifier's VMA (virtual memory address) determined
     by the linker and falls in the corresponding memory region. The AVR Harvard
     architecture requires non overlapping VMA areas for the multiple address spaces
     in the processor: Flash ROM, RAM, and EEPROM. Typical offset for this are
     0x00000000, 0x00800xx0, and 0x00810000 respectively, derived from the linker
	 script used and linker options. The value returned can be seen then as a
     universal pointer.

*/
# 1137 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/pgmspace.h" 3
extern const void * memchr_P(const void *, int __val, size_t __len) __attribute__((__const__));
extern int memcmp_P(const void *, const void *, size_t) __attribute__((__pure__));
extern void *memccpy_P(void *, const void *, int __val, size_t);
extern void *memcpy_P(void *, const void *, size_t);
extern void *memmem_P(const void *, size_t, const void *, size_t) __attribute__((__pure__));
extern const void * memrchr_P(const void *, int __val, size_t __len) __attribute__((__const__));
extern char *strcat_P(char *, const char *);
extern const char * strchr_P(const char *, int __val) __attribute__((__const__));
extern const char * strchrnul_P(const char *, int __val) __attribute__((__const__));
extern int strcmp_P(const char *, const char *) __attribute__((__pure__));
extern char *strcpy_P(char *, const char *);
extern int strcasecmp_P(const char *, const char *) __attribute__((__pure__));
extern char *strcasestr_P(const char *, const char *) __attribute__((__pure__));
extern size_t strcspn_P(const char *__s, const char * __reject) __attribute__((__pure__));
extern size_t strlcat_P (char *, const char *, size_t );
extern size_t strlcpy_P (char *, const char *, size_t );
extern size_t __strlen_P(const char *) __attribute__((__const__)); /* program memory can't change */
extern size_t strnlen_P(const char *, size_t) __attribute__((__const__)); /* program memory can't change */
extern int strncmp_P(const char *, const char *, size_t) __attribute__((__pure__));
extern int strncasecmp_P(const char *, const char *, size_t) __attribute__((__pure__));
extern char *strncat_P(char *, const char *, size_t);
extern char *strncpy_P(char *, const char *, size_t);
extern char *strpbrk_P(const char *__s, const char * __accept) __attribute__((__pure__));
extern const char * strrchr_P(const char *, int __val) __attribute__((__const__));
extern char *strsep_P(char **__sp, const char * __delim);
extern size_t strspn_P(const char *__s, const char * __accept) __attribute__((__pure__));
extern char *strstr_P(const char *, const char *) __attribute__((__pure__));
extern char *strtok_P(char *__s, const char * __delim);
extern char *strtok_rP(char *__s, const char * __delim, char **__last);

extern size_t strlen_PF (uint_farptr_t src) __attribute__((__const__)); /* program memory can't change */
extern size_t strnlen_PF (uint_farptr_t src, size_t len) __attribute__((__const__)); /* program memory can't change */
extern void *memcpy_PF (void *dest, uint_farptr_t src, size_t len);
extern char *strcpy_PF (char *dest, uint_farptr_t src);
extern char *strncpy_PF (char *dest, uint_farptr_t src, size_t len);
extern char *strcat_PF (char *dest, uint_farptr_t src);
extern size_t strlcat_PF (char *dst, uint_farptr_t src, size_t siz);
extern char *strncat_PF (char *dest, uint_farptr_t src, size_t len);
extern int strcmp_PF (const char *s1, uint_farptr_t s2) __attribute__((__pure__));
extern int strncmp_PF (const char *s1, uint_farptr_t s2, size_t n) __attribute__((__pure__));
extern int strcasecmp_PF (const char *s1, uint_farptr_t s2) __attribute__((__pure__));
extern int strncasecmp_PF (const char *s1, uint_farptr_t s2, size_t n) __attribute__((__pure__));
extern char *strstr_PF (const char *s1, uint_farptr_t s2);
extern size_t strlcpy_PF (char *dst, uint_farptr_t src, size_t siz);
extern int memcmp_PF(const void *, uint_farptr_t, size_t) __attribute__((__pure__));


__attribute__((__always_inline__)) static inline size_t strlen_P(const char * s);
static inline size_t strlen_P(const char *s) {
  return __builtin_constant_p(__builtin_strlen(s))
     ? __builtin_strlen(s) : __strlen_P(s);
}




}
# 14 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/nc_power_on/build/sketch/libs/Time/DateStrings.cpp" 2
# 22 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/nc_power_on/build/sketch/libs/Time/DateStrings.cpp"
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/string.h" 1 3
/* Copyright (c) 2002,2007 Marek Michalkiewicz
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */

/*
   string.h

   Contributors:
     Created by Marek Michalkiewicz <marekm@linux.org.pl>
 */






# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stddef.h" 1 3 4
/* Copyright (C) 1989-2013 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.17  Common definitions  <stddef.h>
 */






/* Any one of these symbols __need_* means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done.  */
# 46 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stddef.h" 3 4
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */

/* On 4.3bsd-net2, make sure ansi.h is included, so we have
   one less case to deal with in the following.  */



/* On FreeBSD 5, machine/ansi.h does not exist anymore... */




/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
   defined if the corresponding type is *not* defined.
   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_ */
# 92 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 117 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 162 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stddef.h" 3 4
/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 238 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stddef.h" 3 4
/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 358 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stddef.h" 3 4
/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
    are already defined.  */
/*  BSD/OS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
# 394 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stddef.h" 3 4
/* A null pointer constant.  */
# 46 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/string.h" 2 3
# 56 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/string.h" 3
extern "C" {


/** \file */
/** \defgroup avr_string <string.h>: Strings
    \code #include <string.h> \endcode

    The string functions perform string operations on NULL terminated
    strings. 

    \note If the strings you are working on resident in program space (flash),
    you will need to use the string functions described in \ref avr_pgmspace. */


/** \ingroup avr_string

    This macro finds the first (least significant) bit set in the
    input value.

    This macro is very similar to the function ffs() except that
    it evaluates its argument at compile-time, so it should only
    be applied to compile-time constant expressions where it will
    reduce to a constant itself.
    Application of this macro to expressions that are not constant
    at compile-time is not recommended, and might result in a huge
    amount of code generated.

    \returns The _FFS() macro returns the position of the first
    (least significant) bit set in the word val, or 0 if no bits are set.
    The least significant bit is position 1.  Only 16 bits of argument
    are evaluted.
*/
# 111 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/string.h" 3
extern int ffs (int __val) __attribute__((__const__));
extern int ffsl (long __val) __attribute__((__const__));
extern int ffsll (long long __val) __attribute__((__const__));
extern void *memccpy(void *, const void *, int, size_t);
extern void *memchr(const void *, int, size_t) __attribute__((__pure__));
extern int memcmp(const void *, const void *, size_t) __attribute__((__pure__));
extern void *memcpy(void *, const void *, size_t);
extern void *memmem(const void *, size_t, const void *, size_t) __attribute__((__pure__));
extern void *memmove(void *, const void *, size_t);
extern void *memrchr(const void *, int, size_t) __attribute__((__pure__));
extern void *memset(void *, int, size_t);
extern char *strcat(char *, const char *);
extern char *strchr(const char *, int) __attribute__((__pure__));
extern char *strchrnul(const char *, int) __attribute__((__pure__));
extern int strcmp(const char *, const char *) __attribute__((__pure__));
extern char *strcpy(char *, const char *);
extern int strcasecmp(const char *, const char *) __attribute__((__pure__));
extern char *strcasestr(const char *, const char *) __attribute__((__pure__));
extern size_t strcspn(const char *__s, const char *__reject) __attribute__((__pure__));
extern char *strdup(const char *s1);
extern size_t strlcat(char *, const char *, size_t);
extern size_t strlcpy(char *, const char *, size_t);
extern size_t strlen(const char *) __attribute__((__pure__));
extern char *strlwr(char *);
extern char *strncat(char *, const char *, size_t);
extern int strncmp(const char *, const char *, size_t) __attribute__((__pure__));
extern char *strncpy(char *, const char *, size_t);
extern int strncasecmp(const char *, const char *, size_t) __attribute__((__pure__));
extern size_t strnlen(const char *, size_t) __attribute__((__pure__));
extern char *strpbrk(const char *__s, const char *__accept) __attribute__((__pure__));
extern char *strrchr(const char *, int) __attribute__((__pure__));
extern char *strrev(char *);
extern char *strsep(char **, const char *);
extern size_t strspn(const char *__s, const char *__accept) __attribute__((__pure__));
extern char *strstr(const char *, const char *) __attribute__((__pure__));
extern char *strtok(char *, const char *);
extern char *strtok_r(char *, const char *, char **);
extern char *strupr(char *);


}
# 23 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/nc_power_on/build/sketch/libs/Time/DateStrings.cpp" 2
# 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/nc_power_on/build/sketch/libs/Time/Time.h" 1
/*
  time.h - low level time and date functions
*/

/*
  July 3 2011 - fixed elapsedSecsThisWeek macro (thanks Vincent Valdy for this)
              - fixed  daysToTime_t macro (thanks maniacbug)
*/





# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/inttypes.h" 1 3
/* Copyright (c) 2004,2005,2007 Joerg Wunsch
   Copyright (c) 2005, Carlos Lamas
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */
# 15 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/nc_power_on/build/sketch/libs/Time/Time.h" 2






typedef unsigned long time_t;



// This ugly hack allows us to define C++ overloaded functions, when included
// from within an extern "C", as newlib's sys/stat.h does.  Actually it is
// intended to include "time.h" from the C library (on ARM, but AVR does not
// have that file at all).  On Mac and Windows, the compiler will find this
// "Time.h" instead of the C library "time.h", so we may cause other weird
// and unpredictable effects by conflicting with the C library header "time.h",
// but at least this hack lets us define C++ functions as intended.  Hopefully
// nothing too terrible will result from overriding the C library header?!
extern "C++" {
typedef enum {timeNotSet, timeNeedsSync, timeSet
} timeStatus_t ;

typedef enum {
    dowInvalid, dowSunday, dowMonday, dowTuesday, dowWednesday, dowThursday, dowFriday, dowSaturday
} timeDayOfWeek_t;

typedef enum {
    tmSecond, tmMinute, tmHour, tmWday, tmDay,tmMonth, tmYear, tmNbrFields
} tmByteFields;

typedef struct {
  uint8_t Second;
  uint8_t Minute;
  uint8_t Hour;
  uint8_t Wday; // day of week, sunday is day 1
  uint8_t Day;
  uint8_t Month;
  uint8_t Year; // offset from 1970; 
} tmElements_t, TimeElements, *tmElementsPtr_t;

//convenience macros to convert to and from tm years 





typedef time_t(*getExternalTime)();
//typedef void  (*setExternalTime)(const time_t); // not used in this version


/*==============================================================================*/
/* Useful Constants */
# 75 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/nc_power_on/build/sketch/libs/Time/Time.h"
/* Useful Macros for getting elapsed time */






// The following macros are used in calculating alarms and assume the clock is set to a date later than Jan 1 1971
// Always set the correct time before settting alarms







/* Useful Macros for converting elapsed time to a time_t */





/*============================================================================*/
/*  time and date functions   */
int hour(); // the hour now 
int hour(time_t t); // the hour for the given time
int hourFormat12(); // the hour now in 12 hour format
int hourFormat12(time_t t); // the hour for the given time in 12 hour format
uint8_t isAM(); // returns true if time now is AM
uint8_t isAM(time_t t); // returns true the given time is AM
uint8_t isPM(); // returns true if time now is PM
uint8_t isPM(time_t t); // returns true the given time is PM
int minute(); // the minute now 
int minute(time_t t); // the minute for the given time
int second(); // the second now 
int second(time_t t); // the second for the given time
int day(); // the day now 
int day(time_t t); // the day for the given time
int weekday(); // the weekday now (Sunday is day 1) 
int weekday(time_t t); // the weekday for the given time 
int month(); // the month now  (Jan is month 1)
int month(time_t t); // the month for the given time
int year(); // the full four digit year: (2009, 2010 etc) 
int year(time_t t); // the year for the given time

time_t now(); // return the current time as seconds since Jan 1 1970 
void setTime(time_t t);
void setTime(int hr,int min,int sec,int day, int month, int yr);
void adjustTime(long adjustment);

/* date strings */

char* monthStr(uint8_t month);
char* dayStr(uint8_t day);
char* monthShortStr(uint8_t month);
char* dayShortStr(uint8_t day);

/* time sync functions	*/
timeStatus_t timeStatus(); // indicates if time has been set and recently synchronized
void setSyncProvider( getExternalTime getTimeFunction); // identify the external time provider
void setSyncInterval(time_t interval); // set the number of seconds between re-sync

/* low level functions to convert to and from system time                     */
void breakTime(time_t time, tmElements_t &tm); // break time_t into elements
time_t makeTime(tmElements_t &tm); // convert time elements into time_t

} // extern "C++"
# 24 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/nc_power_on/build/sketch/libs/Time/DateStrings.cpp" 2

// the short strings for each day or month must be exactly dt_SHORT_STR_LEN


static char buffer[9 /* length of longest date string (excluding terminating null)*/+1]; // must be big enough for longest string and the terminating null

const char monthStr0[] __attribute__((__progmem__)) = "";
const char monthStr1[] __attribute__((__progmem__)) = "January";
const char monthStr2[] __attribute__((__progmem__)) = "February";
const char monthStr3[] __attribute__((__progmem__)) = "March";
const char monthStr4[] __attribute__((__progmem__)) = "April";
const char monthStr5[] __attribute__((__progmem__)) = "May";
const char monthStr6[] __attribute__((__progmem__)) = "June";
const char monthStr7[] __attribute__((__progmem__)) = "July";
const char monthStr8[] __attribute__((__progmem__)) = "August";
const char monthStr9[] __attribute__((__progmem__)) = "September";
const char monthStr10[] __attribute__((__progmem__)) = "October";
const char monthStr11[] __attribute__((__progmem__)) = "November";
const char monthStr12[] __attribute__((__progmem__)) = "December";

const __attribute__((__progmem__)) char * const __attribute__((__progmem__)) monthNames_P[] =
{
    monthStr0,monthStr1,monthStr2,monthStr3,monthStr4,monthStr5,monthStr6,
    monthStr7,monthStr8,monthStr9,monthStr10,monthStr11,monthStr12
};

const char monthShortNames_P[] __attribute__((__progmem__)) = "ErrJanFebMarAprMayJunJulAugSepOctNovDec";

const char dayStr0[] __attribute__((__progmem__)) = "Err";
const char dayStr1[] __attribute__((__progmem__)) = "Sunday";
const char dayStr2[] __attribute__((__progmem__)) = "Monday";
const char dayStr3[] __attribute__((__progmem__)) = "Tuesday";
const char dayStr4[] __attribute__((__progmem__)) = "Wednesday";
const char dayStr5[] __attribute__((__progmem__)) = "Thursday";
const char dayStr6[] __attribute__((__progmem__)) = "Friday";
const char dayStr7[] __attribute__((__progmem__)) = "Saturday";

const __attribute__((__progmem__)) char * const __attribute__((__progmem__)) dayNames_P[] =
{
   dayStr0,dayStr1,dayStr2,dayStr3,dayStr4,dayStr5,dayStr6,dayStr7
};

const char dayShortNames_P[] __attribute__((__progmem__)) = "ErrSunMonTueWedThuFriSat";

/* functions to return date strings */

char* monthStr(uint8_t month)
{
    strcpy_P(buffer, (const char *)(__extension__({ uint16_t __addr16 = (uint16_t)((uint16_t)(&(monthNames_P[month]))); uint16_t __result; __asm__ __volatile__ ( "lpm %A0, Z+" "\n\t" "lpm %B0, Z" "\n\t" : "=r" (__result), "=z" (__addr16) : "1" (__addr16) ); __result; })));
    return buffer;
}

char* monthShortStr(uint8_t month)
{
   for (int i=0; i < 3 /* the length of short strings*/; i++)
      buffer[i] = (__extension__({ uint16_t __addr16 = (uint16_t)((uint16_t)(&(monthShortNames_P[i+ (month*3 /* the length of short strings*/)]))); uint8_t __result; __asm__ __volatile__ ( "lpm %0, Z" "\n\t" : "=r" (__result) : "z" (__addr16) ); __result; }));
   buffer[3 /* the length of short strings*/] = 0;
   return buffer;
}

char* dayStr(uint8_t day)
{
   strcpy_P(buffer, (const char *)(__extension__({ uint16_t __addr16 = (uint16_t)((uint16_t)(&(dayNames_P[day]))); uint16_t __result; __asm__ __volatile__ ( "lpm %A0, Z+" "\n\t" "lpm %B0, Z" "\n\t" : "=r" (__result), "=z" (__addr16) : "1" (__addr16) ); __result; })));
   return buffer;
}

char* dayShortStr(uint8_t day)
{
   uint8_t index = day*3 /* the length of short strings*/;
   for (int i=0; i < 3 /* the length of short strings*/; i++)
      buffer[i] = (__extension__({ uint16_t __addr16 = (uint16_t)((uint16_t)(&(dayShortNames_P[index + i]))); uint8_t __result; __asm__ __volatile__ ( "lpm %0, Z" "\n\t" : "=r" (__result) : "z" (__addr16) ); __result; }));
   buffer[3 /* the length of short strings*/] = 0;
   return buffer;
}
