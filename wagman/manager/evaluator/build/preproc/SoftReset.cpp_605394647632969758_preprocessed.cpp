# 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/evaluator/build/sketch/libs/SoftReset/SoftReset.cpp"
# 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/evaluator//"
# 1 "<command-line>"
# 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/evaluator/build/sketch/libs/SoftReset/SoftReset.cpp"
/* Copyright (C) 2012 by Victor Aprea <victor.aprea@wickeddevice.com>

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  */

# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/wdt.h" 1 3
/* Copyright (c) 2002, 2004 Marek Michalkiewicz
   Copyright (c) 2005, 2006, 2007 Eric B. Weddington
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
   avr/wdt.h - macros for AVR watchdog timer
 */




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
# 42 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/wdt.h" 2 3


/** \file */
/** \defgroup avr_watchdog <avr/wdt.h>: Watchdog timer handling
    \code #include <avr/wdt.h> \endcode

    This header file declares the interface to some inline macros
    handling the watchdog timer present in many AVR devices.  In order
    to prevent the watchdog timer configuration from being
    accidentally altered by a crashing application, a special timed
    sequence is required in order to change it.  The macros within
    this header file handle the required sequence automatically
    before changing any value.  Interrupts will be disabled during
    the manipulation.

    \note Depending on the fuse configuration of the particular
    device, further restrictions might apply, in particular it might
    be disallowed to turn off the watchdog timer.

    Note that for newer devices (ATmega88 and newer, effectively any
    AVR that has the option to also generate interrupts), the watchdog
    timer remains active even after a system reset (except a power-on
    condition), using the fastest prescaler value (approximately 15
    ms).  It is therefore required to turn off the watchdog early
    during program startup, the datasheet recommends a sequence like
    the following:

    \code
    #include <stdint.h>
    #include <avr/wdt.h>

    uint8_t mcusr_mirror __attribute__ ((section (".noinit")));

    void get_mcusr(void)       __attribute__((naked))       __attribute__((section(".init3")));
));
    void get_mcusr(void)
    {
      mcusr_mirror = MCUSR;
      MCUSR = 0;
      wdt_disable();
    }
    \endcode

    Saving the value of MCUSR in \c mcusr_mirror is only needed if the
    application later wants to examine the reset source, but in particular, 
    clearing the watchdog reset flag before disabling the
    watchdog is required, according to the datasheet.
*/


/**
   \ingroup avr_watchdog
   Reset the watchdog timer.  When the watchdog timer is enabled,
   a call to this instruction is required before the timer expires,
   otherwise a watchdog-initiated device reset will occur. 
*/
# 123 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/wdt.h" 3
/**
   \ingroup avr_watchdog
   Enable the watchdog timer, configuring it for expiry after
   \c timeout (which is a combination of the \c WDP0 through
   \c WDP2 bits to write into the \c WDTCR register; For those devices 
   that have a \c WDTCSR register, it uses the combination of the \c WDP0 
   through \c WDP3 bits).

   See also the symbolic constants \c WDTO_15MS et al.
*/
# 379 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/wdt.h" 3
/* Use STS instruction. */
# 594 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/wdt.h" 3
/**
   \ingroup avr_watchdog
   Symbolic constants for the watchdog timeout.  Since the watchdog
   timer is based on a free-running RC oscillator, the times are
   approximate only and apply to a supply voltage of 5 V.  At lower
   supply voltages, the times will increase.  For older devices, the
   times will be as large as three times when operating at Vcc = 3 V,
   while the newer devices (e. g. ATmega128, ATmega8) only experience
   a negligible change.

   Possible timeout values are: 15 ms, 30 ms, 60 ms, 120 ms, 250 ms,
   500 ms, 1 s, 2 s.  (Some devices also allow for 4 s and 8 s.)
   Symbolic constants are formed by the prefix
   \c WDTO_, followed by the time.

   Example that would select a watchdog timer expiry of approximately
   500 ms:
   \code
   wdt_enable(WDTO_500MS);
   \endcode
*/


/** \ingroup avr_watchdog
    See \c WDT0_15MS */


/** \ingroup avr_watchdog See
    \c WDT0_15MS */


/** \ingroup avr_watchdog
    See \c WDT0_15MS */


/** \ingroup avr_watchdog
    See \c WDT0_15MS */


/** \ingroup avr_watchdog
    See \c WDT0_15MS */


/** \ingroup avr_watchdog
    See \c WDT0_15MS */


/** \ingroup avr_watchdog
    See \c WDT0_15MS */




/** \ingroup avr_watchdog
    See \c WDT0_15MS
    Note: This is only available on the 
    ATtiny2313, 
    ATtiny24, ATtiny44, ATtiny84, ATtiny84A,
    ATtiny25, ATtiny45, ATtiny85, 
    ATtiny261, ATtiny461, ATtiny861, 
    ATmega48, ATmega88, ATmega168,
    ATmega48P, ATmega88P, ATmega168P, ATmega328P,
    ATmega164P, ATmega324P, ATmega644P, ATmega644,
    ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561,
    ATmega8HVA, ATmega16HVA, ATmega32HVB,
    ATmega406, ATmega1284P,
    ATmega256RFR2, ATmega128RFR2, ATmega64RFR2,
    ATmega2564RFR2, ATmega1284RFR2, ATmega644RFR2,
    AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316,
    AT90PWM81, AT90PWM161,
    AT90USB82, AT90USB162,
    AT90USB646, AT90USB647, AT90USB1286, AT90USB1287,
    ATtiny48, ATtiny88.
    */


/** \ingroup avr_watchdog
    See \c WDT0_15MS
    Note: This is only available on the 
    ATtiny2313, 
    ATtiny24, ATtiny44, ATtiny84, ATtiny84A,
    ATtiny25, ATtiny45, ATtiny85, 
    ATtiny261, ATtiny461, ATtiny861, 
    ATmega48, ATmega48A, ATmega48PA, ATmega88, ATmega168,
    ATmega48P, ATmega88P, ATmega168P, ATmega328P,
    ATmega164P, ATmega324P, ATmega644P, ATmega644,
    ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561,
    ATmega8HVA, ATmega16HVA, ATmega32HVB,
    ATmega406, ATmega1284P,
    ATmega256RFR2, ATmega128RFR2, ATmega64RFR2,
    ATmega2564RFR2, ATmega1284RFR2, ATmega644RFR2,
    AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316,
    AT90PWM81, AT90PWM161,
    AT90USB82, AT90USB162,
    AT90USB646, AT90USB647, AT90USB1286, AT90USB1287,
    ATtiny48, ATtiny88,
    ATxmega16a4u, ATxmega32a4u,
    ATxmega16c4, ATxmega32c4,
    ATxmega128c3, ATxmega192c3, ATxmega256c3.
    */
# 23 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/evaluator/build/sketch/libs/SoftReset/SoftReset.cpp" 2

void wdt_init(void) __attribute__((naked)) __attribute__((section(".init3")));
// Function Implementation
void wdt_init(void)
{
    (*(volatile uint8_t *)((0x34) + 0x20)) = 0;
    __asm__ __volatile__ ( "in __tmp_reg__, __SREG__" "\n\t" "cli" "\n\t" "sts %0, %1" "\n\t" "sts %0, __zero_reg__" "\n\t" "out __SREG__,__tmp_reg__" "\n\t" : /* no outputs */ : "M" (((uint16_t) &((*(volatile uint8_t *)(0x60))))), "r" ((uint8_t)((1 << (4)) | (1 << (3)))) : "r0" );

    return;
}
