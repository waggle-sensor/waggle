# 1 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/integrated.ino.cpp"
# 1 "/digital/github/waggle/sensors/sensorcluster/integrated//"
# 1 "<command-line>"
# 1 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/integrated.ino.cpp"
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 1
/*
  Arduino.h - Main include file for the Arduino SDK
  Copyright (c) 2005-2013 Arduino Team.  All right reserved.

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




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stdint.h" 1 3 4
# 9 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stdint.h" 3 4
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdint.h" 1 3 4
/*
 * Copyright (c) 2004, 2005 by
 * Ralf Corsepius, Ulm/Germany. All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software
 * is freely granted, provided that this notice is preserved.
 */




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/_default_types.h" 1 3 4
/*
 *  $Id$
 */




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/features.h" 1 3 4
/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id$
 */





extern "C" {


/* Macro to test version of GCC.  Returns 0 for non-GCC or too old GCC. */
# 37 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/features.h" 3 4
/* Version with trailing underscores for BSD compatibility. */


/* RTEMS adheres to POSIX -- 1003.1b with some features from annexes.  */
# 93 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/features.h" 3 4
/* XMK loosely adheres to POSIX -- 1003.1 */
# 207 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/features.h" 3 4
/* Per the permission given in POSIX.1-2008 section 2.2.1, define
 * _POSIX_C_SOURCE if _XOPEN_SOURCE is defined and _POSIX_C_SOURCE is not.
 * (_XOPEN_SOURCE indicates that XSI extensions are desired by an application.)
 * This permission is first granted in 2008, but use it for older ones, also.
 * Allow for _XOPEN_SOURCE to be empty (from the earliest form of it, before it
 * was required to have specific values).
 */
# 227 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/features.h" 3 4
}
# 9 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/_default_types.h" 2 3 4

/*
 * Guess on types by examining *_MIN / *_MAX defines.
 */

/* GCC >= 3.3.0 has __<val>__ implicitly defined. */
# 23 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/_default_types.h" 3 4
extern "C" {



typedef signed char __int8_t;
typedef unsigned char __uint8_t;
# 37 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef short int __int16_t;
typedef short unsigned int __uint16_t;
# 55 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long int __int32_t;
typedef long unsigned int __uint32_t;
# 77 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long long int __int64_t;
typedef long long unsigned int __uint64_t;
# 104 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef signed char __int_least8_t;
typedef unsigned char __uint_least8_t;
# 126 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef short int __int_least16_t;
typedef short unsigned int __uint_least16_t;
# 144 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long int __int_least32_t;
typedef long unsigned int __uint_least32_t;
# 158 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long long int __int_least64_t;
typedef long long unsigned int __uint_least64_t;
# 168 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef int __intptr_t;
typedef unsigned int __uintptr_t;
# 181 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/_default_types.h" 3 4
}
# 13 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdint.h" 2 3 4


extern "C" {



/* gcc > 3.2 implicitly defines the values we are interested */






/* Check if "long long" is 64bit wide */
/* Modern GCCs provide __LONG_LONG_MAX__, SUSv3 wants LLONG_MAX */





/* Check if "long" is 64bit or 32bit wide */







typedef __int8_t int8_t ;
typedef __uint8_t uint8_t ;




typedef __int_least8_t int_least8_t;
typedef __uint_least8_t uint_least8_t;




typedef __int16_t int16_t ;
typedef __uint16_t uint16_t ;




typedef __int_least16_t int_least16_t;
typedef __uint_least16_t uint_least16_t;




typedef __int32_t int32_t ;
typedef __uint32_t uint32_t ;




typedef __int_least32_t int_least32_t;
typedef __uint_least32_t uint_least32_t;




typedef __int64_t int64_t ;
typedef __uint64_t uint64_t ;




typedef __int_least64_t int_least64_t;
typedef __uint_least64_t uint_least64_t;



/*
 * Fastest minimum-width integer types
 *
 * Assume int to be the fastest type for all types with a width 
 * less than __INT_MAX__ rsp. INT_MAX
 */

  typedef int int_fast8_t;
  typedef unsigned int uint_fast8_t;
# 105 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdint.h" 3 4
  typedef int int_fast16_t;
  typedef unsigned int uint_fast16_t;
# 115 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdint.h" 3 4
  typedef int int_fast32_t;
  typedef unsigned int uint_fast32_t;
# 125 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdint.h" 3 4
  typedef long long int int_fast64_t;
  typedef long long unsigned int uint_fast64_t;







/*
 * Fall back to [u]int_least<N>_t for [u]int_fast<N>_t types
 * not having been defined, yet.
 * Leave undefined, if [u]int_least<N>_t should not be available.
 */
# 171 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdint.h" 3 4
/* Greatest-width integer types */
/* Modern GCCs provide __INTMAX_TYPE__ */

  typedef long long int intmax_t;






/* Modern GCCs provide __UINTMAX_TYPE__ */

  typedef long long unsigned int uintmax_t;






typedef __intptr_t intptr_t;
typedef __uintptr_t uintptr_t;
# 215 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdint.h" 3 4
/* Limits of Specified-Width Integer Types */
# 407 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdint.h" 3 4
/* This must match size_t in stddef.h, currently long unsigned int */






/* This must match sig_atomic_t in <signal.h> (currently int) */



/* This must match ptrdiff_t  in <stddef.h> (currently long int) */
# 433 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdint.h" 3 4
/* wint_t is unsigned int on almost all GCC targets.  */
# 445 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdint.h" 3 4
/** Macros for minimum-width integer constant expressions */
# 498 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdint.h" 3 4
/** Macros for greatest-width integer constant expression */
# 514 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdint.h" 3 4
}
# 10 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stdint.h" 2 3 4
# 24 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdlib.h" 1 3
/*
 * stdlib.h
 *
 * Definitions for common types, variables, and functions.
 */




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/ieeefp.h" 1 3



/* This file can define macros to choose variations of the IEEE float
   format:

   _FLT_LARGEST_EXPONENT_IS_NORMAL

	Defined if the float format uses the largest exponent for finite
	numbers rather than NaN and infinity representations.  Such a
	format cannot represent NaNs or infinities at all, but it's FLT_MAX
	is twice the IEEE value.

   _FLT_NO_DENORMALS

	Defined if the float format does not support IEEE denormals.  Every
	float with a zero exponent is taken to be a zero representation.
 
   ??? At the moment, there are no equivalent macros above for doubles and
   the macros are not fully supported by --enable-newlib-hw-fp.

   __IEEE_BIG_ENDIAN

        Defined if the float format is big endian.  This is mutually exclusive
        with __IEEE_LITTLE_ENDIAN.

   __IEEE_LITTLE_ENDIAN
 
        Defined if the float format is little endian.  This is mutually exclusive
        with __IEEE_BIG_ENDIAN.

   Note that one of __IEEE_BIG_ENDIAN or __IEEE_LITTLE_ENDIAN must be specified for a
   platform or error will occur.

   __IEEE_BYTES_LITTLE_ENDIAN

        This flag is used in conjunction with __IEEE_BIG_ENDIAN to describe a situation 
	whereby multiple words of an IEEE floating point are in big endian order, but the
	words themselves are little endian with respect to the bytes.

   _DOUBLE_IS_32BITS 

        This is used on platforms that support double by using the 32-bit IEEE
        float type.

   _FLOAT_ARG

        This represents what type a float arg is passed as.  It is used when the type is
        not promoted to double.
	
*/


/* ARM traditionally used big-endian words; and within those words the
   byte ordering was big or little endian depending upon the target.
   Modern floating-point formats are naturally ordered; in this case
   __VFP_FP__ will be defined, even if soft-float.  */
# 217 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/ieeefp.h" 3
/* necv70 was __IEEE_LITTLE_ENDIAN. */
# 11 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdlib.h" 2 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/_ansi.h" 1 3
/* Provide support for both ANSI and non-ANSI environments.  */

/* Some ANSI environments are "broken" in the sense that __STDC__ cannot be
   relied upon to have it's intended meaning.  Therefore we must use our own
   concoction: _HAVE_STDC.  Always use _HAVE_STDC instead of __STDC__ in newlib
   sources!

   To get a strict ANSI C environment, define macro __STRICT_ANSI__.  This will
   "comment out" the non-ANSI parts of the ANSI header files (non-ANSI header
   files aren't affected).  */




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/newlib.h" 1 3
/* newlib.h.  Generated from newlib.hin by configure.  */
/* newlib.hin.  Manually edited from the output of autoheader to
   remove all PACKAGE_ macros which will collide with any user
   package using newlib header files and having its own package name,
   version, etc...  */




/* EL/IX level */
/* #undef _ELIX_LEVEL */

/* Newlib version */


/* C99 formats support (such as %a, %zu, ...) in IO functions like
 * printf/scanf enabled */
/* #undef _WANT_IO_C99_FORMATS */

/* long long type support in IO functions like printf/scanf enabled */


/* Register application finalization function using atexit. */


/* long double type support in IO functions like printf/scanf enabled */
/* #undef _WANT_IO_LONG_DOUBLE */

/* Positional argument support in printf functions enabled.  */
/* #undef _WANT_IO_POS_ARGS */

/* Optional reentrant struct support.  Used mostly on platforms with
   very restricted storage.  */
/* #undef _WANT_REENT_SMALL */

/* Multibyte supported */
/* #undef _MB_CAPABLE */

/* MB_LEN_MAX */


/* ICONV enabled */
/* #undef _ICONV_ENABLED */

/* Enable ICONV external CCS files loading capabilities */
/* #undef _ICONV_ENABLE_EXTERNAL_CCS */

/* Define if the linker supports .preinit_array/.init_array/.fini_array
 * sections.  */


/* True if atexit() may dynamically allocate space for cleanup
   functions.  */


/* True if long double supported.  */


/* Define if compiler supports -fno-tree-loop-distribute-patterns. */


/* True if long double supported and it is equal to double.  */


/* Define if ivo supported in streamio.  */


/* Define if fseek functions support seek optimization.  */


/* Define if wide char orientation is supported.  */


/* Define if unbuffered stream file optimization is supported.  */


/* Define if lite version of exit supported.  */
/* #undef _LITE_EXIT */

/* Define if declare atexit data as global.  */
/* #undef _REENT_GLOBAL_ATEXIT */

/*
 * Iconv encodings enabled ("to" direction)
 */
/* #undef _ICONV_TO_ENCODING_BIG5 */
/* #undef _ICONV_TO_ENCODING_CP775 */
/* #undef _ICONV_TO_ENCODING_CP850 */
/* #undef _ICONV_TO_ENCODING_CP852 */
/* #undef _ICONV_TO_ENCODING_CP855 */
/* #undef _ICONV_TO_ENCODING_CP866 */
/* #undef _ICONV_TO_ENCODING_EUC_JP */
/* #undef _ICONV_TO_ENCODING_EUC_TW */
/* #undef _ICONV_TO_ENCODING_EUC_KR */
/* #undef _ICONV_TO_ENCODING_ISO_8859_1 */
/* #undef _ICONV_TO_ENCODING_ISO_8859_10 */
/* #undef _ICONV_TO_ENCODING_ISO_8859_11 */
/* #undef _ICONV_TO_ENCODING_ISO_8859_13 */
/* #undef _ICONV_TO_ENCODING_ISO_8859_14 */
/* #undef _ICONV_TO_ENCODING_ISO_8859_15 */
/* #undef _ICONV_TO_ENCODING_ISO_8859_2 */
/* #undef _ICONV_TO_ENCODING_ISO_8859_3 */
/* #undef _ICONV_TO_ENCODING_ISO_8859_4 */
/* #undef _ICONV_TO_ENCODING_ISO_8859_5 */
/* #undef _ICONV_TO_ENCODING_ISO_8859_6 */
/* #undef _ICONV_TO_ENCODING_ISO_8859_7 */
/* #undef _ICONV_TO_ENCODING_ISO_8859_8 */
/* #undef _ICONV_TO_ENCODING_ISO_8859_9 */
/* #undef _ICONV_TO_ENCODING_ISO_IR_111 */
/* #undef _ICONV_TO_ENCODING_KOI8_R */
/* #undef _ICONV_TO_ENCODING_KOI8_RU */
/* #undef _ICONV_TO_ENCODING_KOI8_U */
/* #undef _ICONV_TO_ENCODING_KOI8_UNI */
/* #undef _ICONV_TO_ENCODING_UCS_2 */
/* #undef _ICONV_TO_ENCODING_UCS_2_INTERNAL */
/* #undef _ICONV_TO_ENCODING_UCS_2BE */
/* #undef _ICONV_TO_ENCODING_UCS_2LE */
/* #undef _ICONV_TO_ENCODING_UCS_4 */
/* #undef _ICONV_TO_ENCODING_UCS_4_INTERNAL */
/* #undef _ICONV_TO_ENCODING_UCS_4BE */
/* #undef _ICONV_TO_ENCODING_UCS_4LE */
/* #undef _ICONV_TO_ENCODING_US_ASCII */
/* #undef _ICONV_TO_ENCODING_UTF_16 */
/* #undef _ICONV_TO_ENCODING_UTF_16BE */
/* #undef _ICONV_TO_ENCODING_UTF_16LE */
/* #undef _ICONV_TO_ENCODING_UTF_8 */
/* #undef _ICONV_TO_ENCODING_WIN_1250 */
/* #undef _ICONV_TO_ENCODING_WIN_1251 */
/* #undef _ICONV_TO_ENCODING_WIN_1252 */
/* #undef _ICONV_TO_ENCODING_WIN_1253 */
/* #undef _ICONV_TO_ENCODING_WIN_1254 */
/* #undef _ICONV_TO_ENCODING_WIN_1255 */
/* #undef _ICONV_TO_ENCODING_WIN_1256 */
/* #undef _ICONV_TO_ENCODING_WIN_1257 */
/* #undef _ICONV_TO_ENCODING_WIN_1258 */

/*
 * Iconv encodings enabled ("from" direction)
 */
/* #undef _ICONV_FROM_ENCODING_BIG5 */
/* #undef _ICONV_FROM_ENCODING_CP775 */
/* #undef _ICONV_FROM_ENCODING_CP850 */
/* #undef _ICONV_FROM_ENCODING_CP852 */
/* #undef _ICONV_FROM_ENCODING_CP855 */
/* #undef _ICONV_FROM_ENCODING_CP866 */
/* #undef _ICONV_FROM_ENCODING_EUC_JP */
/* #undef _ICONV_FROM_ENCODING_EUC_TW */
/* #undef _ICONV_FROM_ENCODING_EUC_KR */
/* #undef _ICONV_FROM_ENCODING_ISO_8859_1 */
/* #undef _ICONV_FROM_ENCODING_ISO_8859_10 */
/* #undef _ICONV_FROM_ENCODING_ISO_8859_11 */
/* #undef _ICONV_FROM_ENCODING_ISO_8859_13 */
/* #undef _ICONV_FROM_ENCODING_ISO_8859_14 */
/* #undef _ICONV_FROM_ENCODING_ISO_8859_15 */
/* #undef _ICONV_FROM_ENCODING_ISO_8859_2 */
/* #undef _ICONV_FROM_ENCODING_ISO_8859_3 */
/* #undef _ICONV_FROM_ENCODING_ISO_8859_4 */
/* #undef _ICONV_FROM_ENCODING_ISO_8859_5 */
/* #undef _ICONV_FROM_ENCODING_ISO_8859_6 */
/* #undef _ICONV_FROM_ENCODING_ISO_8859_7 */
/* #undef _ICONV_FROM_ENCODING_ISO_8859_8 */
/* #undef _ICONV_FROM_ENCODING_ISO_8859_9 */
/* #undef _ICONV_FROM_ENCODING_ISO_IR_111 */
/* #undef _ICONV_FROM_ENCODING_KOI8_R */
/* #undef _ICONV_FROM_ENCODING_KOI8_RU */
/* #undef _ICONV_FROM_ENCODING_KOI8_U */
/* #undef _ICONV_FROM_ENCODING_KOI8_UNI */
/* #undef _ICONV_FROM_ENCODING_UCS_2 */
/* #undef _ICONV_FROM_ENCODING_UCS_2_INTERNAL */
/* #undef _ICONV_FROM_ENCODING_UCS_2BE */
/* #undef _ICONV_FROM_ENCODING_UCS_2LE */
/* #undef _ICONV_FROM_ENCODING_UCS_4 */
/* #undef _ICONV_FROM_ENCODING_UCS_4_INTERNAL */
/* #undef _ICONV_FROM_ENCODING_UCS_4BE */
/* #undef _ICONV_FROM_ENCODING_UCS_4LE */
/* #undef _ICONV_FROM_ENCODING_US_ASCII */
/* #undef _ICONV_FROM_ENCODING_UTF_16 */
/* #undef _ICONV_FROM_ENCODING_UTF_16BE */
/* #undef _ICONV_FROM_ENCODING_UTF_16LE */
/* #undef _ICONV_FROM_ENCODING_UTF_8 */
/* #undef _ICONV_FROM_ENCODING_WIN_1250 */
/* #undef _ICONV_FROM_ENCODING_WIN_1251 */
/* #undef _ICONV_FROM_ENCODING_WIN_1252 */
/* #undef _ICONV_FROM_ENCODING_WIN_1253 */
/* #undef _ICONV_FROM_ENCODING_WIN_1254 */
/* #undef _ICONV_FROM_ENCODING_WIN_1255 */
/* #undef _ICONV_FROM_ENCODING_WIN_1256 */
/* #undef _ICONV_FROM_ENCODING_WIN_1257 */
/* #undef _ICONV_FROM_ENCODING_WIN_1258 */
# 16 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/_ansi.h" 2 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/config.h" 1 3



# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/ieeefp.h" 1 3
# 5 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/config.h" 2 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/features.h" 1 3
/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id$
 */
# 6 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/config.h" 2 3





/* exceptions first */







/* 16 bit integer machines */
# 112 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/config.h" 3
/* For the PowerPC eabi, force the _impure_ptr to be in .sdata */
# 122 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/config.h" 3
/* Configure small REENT structure for Xilinx MicroBlaze platforms */
# 184 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/config.h" 3
/* This block should be kept in sync with GCC's limits.h.  The point
   of having these definitions here is to not include limits.h, which
   would pollute the user namespace, while still using types of the
   the correct widths when deciding how to define __int32_t and
   __int64_t.  */
# 209 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/config.h" 3
/* End of block that should be kept in sync with GCC's limits.h.  */
# 247 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/config.h" 3
/* Define return type of read/write routines.  In POSIX, the return type
   for read()/write() is "ssize_t" but legacy newlib code has been using
   "int" for some time.  If not specified, "int" is defaulted.  */



/* Define `count' parameter of read/write routines.  In POSIX, the `count'
   parameter is "size_t" but legacy newlib code has been using "int" for some
   time.  If not specified, "int" is defaulted.  */
# 266 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/config.h" 3
/* See if small reent asked for at configuration time and
   is not chosen by the platform by default.  */






/* If _MB_EXTENDED_CHARSETS_ALL is set, we want all of the extended
   charsets.  The extended charsets add a few functions and a couple
   of tables of a few K each. */
# 17 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/_ansi.h" 2 3

/* First try to figure out whether we really are in an ANSI C environment.  */
/* FIXME: This probably needs some work.  Perhaps sys/config.h can be
   prevailed upon to give us a clue.  */





/*  ISO C++.  */
# 102 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/_ansi.h" 3
/* Support gcc's __attribute__ facility.  */







/*  The traditional meaning of 'extern inline' for GCC is not
  to emit the function body unless the address is explicitly
  taken.  However this behaviour is changing to match the C99
  standard, which uses 'extern inline' to indicate that the
  function body *must* be emitted.  Likewise, a function declared
  without either 'extern' or 'static' defaults to extern linkage
  (C99 6.2.2p5), and the compiler may choose whether to use the
  inline version or call the extern linkage version (6.7.4p6).
  If we are using GCC, but do not have the new behaviour, we need
  to use extern inline; if we are using a new GCC with the
  C99-compatible behaviour, or a non-GCC compiler (which we will
  have to hope is C99, since there is no other way to achieve the
  effect of omitting the function if it isn't referenced) we use
  'static inline', which c99 defines to mean more-or-less the same
  as the Gnu C 'extern inline'.  */




/* We're using GCC in C99 mode, or an unknown compiler which
  we just have to hope obeys the C99 semantics of inline.  */
# 12 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdlib.h" 2 3




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 1 3 4
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
# 46 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */

/* On 4.3bsd-net2, make sure ansi.h is included, so we have
   one less case to deal with in the following.  */



/* On FreeBSD 5, machine/ansi.h does not exist anymore... */




/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
   defined if the corresponding type is *not* defined.
   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_ */
# 92 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 117 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 162 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 212 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
typedef unsigned int size_t;
# 238 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 279 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* On BSD/386 1.1, at least, machine/ansi.h defines _BSD_WCHAR_T_
   instead of _WCHAR_T_, and _BSD_RUNE_T_ (which, unlike the other
   symbols in the _FOO_T_ family, stays defined even after its
   corresponding type is defined).  If we define wchar_t, then we
   must undef _WCHAR_T_; for BSD/386 1.1 (and perhaps others), if
   we undef _WCHAR_T_, then we must also define rune_t, since 
   headers like runetype.h assume that if machine/ansi.h is included,
   and _BSD_WCHAR_T_ is not defined, then rune_t is available.
   machine/ansi.h says, "Note that _WCHAR_T_ and _RUNE_T_ must be of
   the same type." */
# 306 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* FreeBSD 5 can't be handled well using "traditional" logic above
   since it no longer defines _BSD_RUNE_T_ yet still desires to export
   rune_t in some cases... */
# 358 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
    are already defined.  */
/*  BSD/OS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
# 394 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* A null pointer constant.  */
# 17 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdlib.h" 2 3

# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/reent.h" 1 3
/* This header file provides the reentrancy.  */

/* WARNING: All identifiers here must begin with an underscore.  This file is
   included by stdio.h and others and we therefore must only use identifiers
   in the namespace allotted to us.  */



extern "C" {



# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/_ansi.h" 1 3
/* Provide support for both ANSI and non-ANSI environments.  */

/* Some ANSI environments are "broken" in the sense that __STDC__ cannot be
   relied upon to have it's intended meaning.  Therefore we must use our own
   concoction: _HAVE_STDC.  Always use _HAVE_STDC instead of __STDC__ in newlib
   sources!

   To get a strict ANSI C environment, define macro __STRICT_ANSI__.  This will
   "comment out" the non-ANSI parts of the ANSI header files (non-ANSI header
   files aren't affected).  */
# 14 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/reent.h" 2 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 1 3 4
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





/* snaroff@next.com says the NeXT needs this.  */




/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */

/* On 4.3bsd-net2, make sure ansi.h is included, so we have
   one less case to deal with in the following.  */



/* On FreeBSD 5, machine/ansi.h does not exist anymore... */




/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
   defined if the corresponding type is *not* defined.
   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_ */
# 92 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 117 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 147 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
typedef int ptrdiff_t;
# 157 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* If this symbol has done its job, get rid of it.  */




/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 238 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 358 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
    are already defined.  */
/*  BSD/OS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
# 394 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* A null pointer constant.  */
# 412 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* Offset of member MEMBER in a struct of type TYPE. */






/* Type whose alignment is supported in every context and is at least
   as great as that of any standard type not using alignment
   specifiers.  */
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;






  typedef decltype(nullptr) nullptr_t;
# 15 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/reent.h" 2 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/_types.h" 1 3
/* ANSI C namespace clean utility typedefs */

/* This file defines various typedefs needed by the system calls that support
   the C library.  Basically, they're just the POSIX versions with an '_'
   prepended.  This file lives in the `sys' directory so targets can provide
   their own if desired (or they can put target dependant conditionals here).
*/




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/_types.h" 1 3
/*
 *  $Id$
 */



# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/_default_types.h" 1 3
/*
 *  $Id$
 */
# 8 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/_types.h" 2 3
# 13 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/_types.h" 2 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/lock.h" 1 3



/* dummy lock routines for single-threaded aps */

typedef int _LOCK_T;
typedef int _LOCK_RECURSIVE_T;

# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/_ansi.h" 1 3
/* Provide support for both ANSI and non-ANSI environments.  */

/* Some ANSI environments are "broken" in the sense that __STDC__ cannot be
   relied upon to have it's intended meaning.  Therefore we must use our own
   concoction: _HAVE_STDC.  Always use _HAVE_STDC instead of __STDC__ in newlib
   sources!

   To get a strict ANSI C environment, define macro __STRICT_ANSI__.  This will
   "comment out" the non-ANSI parts of the ANSI header files (non-ANSI header
   files aren't affected).  */
# 10 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/lock.h" 2 3
# 14 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/_types.h" 2 3


typedef long _off_t;



typedef short __dev_t;



typedef unsigned short __uid_t;


typedef unsigned short __gid_t;



__extension__ typedef long long _off64_t;


/*
 * We need fpos_t for the following, but it doesn't have a leading "_",
 * so we use _fpos_t instead.
 */

typedef long _fpos_t; /* XXX must match off_t in <sys/types.h> */
    /* (and must be `long' for now) */
# 51 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/_types.h" 3
/* If __SIZE_TYPE__ is defined (gcc) we define ssize_t based on size_t.
   We simply change "unsigned" to "signed" for this single definition
   to make sure ssize_t and size_t only differ by their signedness. */

typedef signed int _ssize_t;
# 67 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/_types.h" 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 1 3 4
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
# 46 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */

/* On 4.3bsd-net2, make sure ansi.h is included, so we have
   one less case to deal with in the following.  */



/* On FreeBSD 5, machine/ansi.h does not exist anymore... */




/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
   defined if the corresponding type is *not* defined.
   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_ */
# 92 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 117 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 157 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* If this symbol has done its job, get rid of it.  */




/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 238 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 353 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
typedef unsigned int wint_t;




/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
    are already defined.  */
/*  BSD/OS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
# 394 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* A null pointer constant.  */
# 412 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* Offset of member MEMBER in a struct of type TYPE. */
# 68 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/_types.h" 2 3


/* Conversion state information.  */
typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    unsigned char __wchb[4];
  } __value; /* Value so far.  */
} _mbstate_t;



typedef _LOCK_RECURSIVE_T _flock_t;



/* Iconv descriptor type */
typedef void *_iconv_t;
# 16 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/reent.h" 2 3






typedef unsigned long __ULong;
# 38 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/reent.h" 3
struct _reent;

/*
 * If _REENT_SMALL is defined, we make struct _reent as small as possible,
 * by having nearly everything possible allocated at first use.
 */

struct _Bigint
{
  struct _Bigint *_next;
  int _k, _maxwds, _sign, _wds;
  __ULong _x[1];
};

/* needed by reentrant structure */
struct __tm
{
  int __tm_sec;
  int __tm_min;
  int __tm_hour;
  int __tm_mday;
  int __tm_mon;
  int __tm_year;
  int __tm_wday;
  int __tm_yday;
  int __tm_isdst;
};

/*
 * atexit() support.
 */



struct _on_exit_args {
 void * _fnargs[32 /* must be at least 32 to guarantee ANSI conformance */]; /* user fn args */
 void * _dso_handle[32 /* must be at least 32 to guarantee ANSI conformance */];
 /* Bitmask is set if user function takes arguments.  */
 __ULong _fntypes; /* type of exit routine -
				   Must have at least _ATEXIT_SIZE bits */
 /* Bitmask is set if function was registered via __cxa_atexit.  */
 __ULong _is_cxa;
};
# 91 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/reent.h" 3
struct _atexit {
 struct _atexit *_next; /* next in list */
 int _ind; /* next index in this table */
 /* Some entries may already have been called, and will be NULL.  */
 void (*_fns[32 /* must be at least 32 to guarantee ANSI conformance */])(void); /* the table itself */
        struct _on_exit_args _on_exit_args;
};
# 108 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/reent.h" 3
/*
 * Stdio buffers.
 *
 * This and __FILE are defined here because we need them for struct _reent,
 * but we don't want stdio.h included when stdlib.h is.
 */

struct __sbuf {
 unsigned char *_base;
 int _size;
};

/*
 * Stdio state variables.
 *
 * The following always hold:
 *
 *	if (_flags&(__SLBF|__SWR)) == (__SLBF|__SWR),
 *		_lbfsize is -_bf._size, else _lbfsize is 0
 *	if _flags&__SRD, _w is 0
 *	if _flags&__SWR, _r is 0
 *
 * This ensures that the getc and putc macros (or inline functions) never
 * try to write or read from a file that is in `read' or `write' mode.
 * (Moreover, they can, and do, automatically switch from read mode to
 * write mode, and back, on "r+" and "w+" files.)
 *
 * _lbfsize is used only to make the inline line-buffered output stream
 * code as compact as possible.
 *
 * _ub, _up, and _ur are used when ungetc() pushes back more characters
 * than fit in the current _bf, or when ungetc() pushes back a character
 * that does not match the previous one in _bf.  When this happens,
 * _ub._base becomes non-nil (i.e., a stream has ungetc() data iff
 * _ub._base!=NULL) and _up and _ur save the current values of _p and _r.
 */
# 179 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/reent.h" 3
struct __sFILE {
  unsigned char *_p; /* current position in (some) buffer */
  int _r; /* read space left for getc() */
  int _w; /* write space left for putc() */
  short _flags; /* flags, below; this FILE is free if 0 */
  short _file; /* fileno, if Unix descriptor, else -1 */
  struct __sbuf _bf; /* the buffer (at least 1 byte, if !NULL) */
  int _lbfsize; /* 0 or -_bf._size, for inline putc */





  /* operations */
  void * _cookie; /* cookie passed to io functions */

  int (* _read) (struct _reent *, void *, char *, int)
                                          ;
  int (* _write) (struct _reent *, void *, const char *, int)

                                   ;
  _fpos_t (* _seek) (struct _reent *, void *, _fpos_t, int);
  int (* _close) (struct _reent *, void *);

  /* separate buffer for long sequences of ungetc() */
  struct __sbuf _ub; /* ungetc buffer */
  unsigned char *_up; /* saved _p when _p is doing ungetc data */
  int _ur; /* saved _r when _r is counting ungetc data */

  /* tricks to meet minimum requirements even when malloc() fails */
  unsigned char _ubuf[3]; /* guarantee an ungetc() buffer */
  unsigned char _nbuf[1]; /* guarantee a getc() buffer */

  /* separate buffer for fgetline() when line crosses buffer boundary */
  struct __sbuf _lb; /* buffer for fgetline() */

  /* Unix stdio files get aligned to block boundaries on fseek() */
  int _blksize; /* stat.st_blksize (may be != _bf._size) */
  _off_t _offset; /* current lseek offset */


  struct _reent *_data; /* Here for binary compatibility? Remove? */



  _flock_t _lock; /* for thread-safety locking */

  _mbstate_t _mbstate; /* for wide char stdio functions. */
  int _flags2; /* for future use */
};
# 285 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/reent.h" 3
typedef struct __sFILE __FILE;



struct _glue
{
  struct _glue *_next;
  int _niobs;
  __FILE *_iobs;
};

/*
 * rand48 family support
 *
 * Copyright (c) 1993 Martin Birgmeier
 * All rights reserved.
 *
 * You may redistribute unmodified or modified versions of this source
 * code provided that the above copyright notice and this and the
 * following conditions are retained.
 *
 * This software is provided ``as is'', and comes with no warranties
 * of any kind. I shall in no event be liable for anything that happens
 * to anyone/anything when using this software.
 */







struct _rand48 {
  unsigned short _seed[3];
  unsigned short _mult[3];
  unsigned short _add;




};

/* How big the some arrays are.  */




/*
 * struct _reent
 *
 * This structure contains *all* globals needed by the library.
 * It's raison d'etre is to facilitate threads by making all library routines
 * reentrant.  IE: All state information is contained here.
 */
# 569 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/reent.h" 3
struct _reent
{
  int _errno; /* local copy of errno */

  /* FILE is a big struct and may change over time.  To try to achieve binary
     compatibility with future versions, put stdin,stdout,stderr here.
     These are pointers into member __sf defined below.  */
  __FILE *_stdin, *_stdout, *_stderr;

  int _inc; /* used by tmpnam */
  char _emergency[25];

  int _current_category; /* used by setlocale */
  const char *_current_locale;

  int __sdidinit; /* 1 means stdio has been init'd */

  void (* __cleanup) (struct _reent *);

  /* used by mprec routines */
  struct _Bigint *_result;
  int _result_k;
  struct _Bigint *_p5s;
  struct _Bigint **_freelist;

  /* used by some fp conversion routines */
  int _cvtlen; /* should be size_t */
  char *_cvtbuf;

  union
    {
      struct
        {
          unsigned int _unused_rand;
          char * _strtok_last;
          char _asctime_buf[26];
          struct __tm _localtime_buf;
          int _gamma_signgam;
          __extension__ unsigned long long _rand_next;
          struct _rand48 _r48;
          _mbstate_t _mblen_state;
          _mbstate_t _mbtowc_state;
          _mbstate_t _wctomb_state;
          char _l64a_buf[8];
          char _signal_buf[24];
          int _getdate_err;
          _mbstate_t _mbrlen_state;
          _mbstate_t _mbrtowc_state;
          _mbstate_t _mbsrtowcs_state;
          _mbstate_t _wcrtomb_state;
          _mbstate_t _wcsrtombs_state;
   int _h_errno;
        } _reent;
  /* Two next two fields were once used by malloc.  They are no longer
     used. They are used to preserve the space used before so as to
     allow addition of new reent fields and keep binary compatibility.   */
      struct
        {

          unsigned char * _nextf[30];
          unsigned int _nmalloc[30];
        } _unused;
    } _new;


  /* atexit stuff */
  struct _atexit *_atexit; /* points to head of LIFO stack */
  struct _atexit _atexit0; /* one guaranteed table, required by ANSI */


  /* signal info */
  void (**(_sig_func))(int);

  /* These are here last so that __FILE can grow without changing the offsets
     of the above members (on the off chance that future binary compatibility
     would be broken otherwise).  */
  struct _glue __sglue; /* root of glue chain */
  __FILE __sf[3]; /* first three file descriptors */
};
# 748 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/reent.h" 3
/* This value is used in stdlib/misc.c.  reent/reent.c has to know it
   as well to make sure the freelist is correctly free'd.  Therefore
   we define it here, rather than in stdlib/misc.c, as before. */


/*
 * All references to struct _reent are via this pointer.
 * Internally, newlib routines that need to reference it should use _REENT.
 */





extern struct _reent *_impure_ptr ;
extern struct _reent *const _global_impure_ptr ;

void _reclaim_reent (struct _reent *);

/* #define _REENT_ONLY define this to get only reentrant routines */
# 788 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/reent.h" 3
}
# 19 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdlib.h" 2 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/stdlib.h" 1 3



/* place holder so platforms may add stdlib.h extensions */
# 20 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdlib.h" 2 3

# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/alloca.h" 1 3
/* libc/include/alloca.h - Allocate memory on stack */

/* Written 2000 by Werner Almesberger */
/* Rearranged for general inclusion by stdlib.h.
   2001, Corinna Vinschen <vinschen@redhat.com> */




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/_ansi.h" 1 3
/* Provide support for both ANSI and non-ANSI environments.  */

/* Some ANSI environments are "broken" in the sense that __STDC__ cannot be
   relied upon to have it's intended meaning.  Therefore we must use our own
   concoction: _HAVE_STDC.  Always use _HAVE_STDC instead of __STDC__ in newlib
   sources!

   To get a strict ANSI C environment, define macro __STRICT_ANSI__.  This will
   "comment out" the non-ANSI parts of the ANSI header files (non-ANSI header
   files aren't affected).  */
# 11 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/alloca.h" 2 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/reent.h" 1 3
/* This header file provides the reentrancy.  */

/* WARNING: All identifiers here must begin with an underscore.  This file is
   included by stdio.h and others and we therefore must only use identifiers
   in the namespace allotted to us.  */
# 12 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/alloca.h" 2 3
# 22 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdlib.h" 2 3






extern "C" {

typedef struct
{
  int quot; /* quotient */
  int rem; /* remainder */
} div_t;

typedef struct
{
  long quot; /* quotient */
  long rem; /* remainder */
} ldiv_t;




typedef struct
{
  long long int quot; /* quotient */
  long long int rem; /* remainder */
} lldiv_t;




typedef int (*__compar_fn_t) (const void *, const void *);







int __locale_mb_cur_max (void);



void abort (void) __attribute__ ((noreturn));
int abs (int);
int atexit (void (*__func)(void));
double atof (const char *__nptr);

float atoff (const char *__nptr);

int atoi (const char *__nptr);
int _atoi_r (struct _reent *, const char *__nptr);
long atol (const char *__nptr);
long _atol_r (struct _reent *, const char *__nptr);
void * bsearch (const void * __key, const void * __base, size_t __nmemb, size_t __size, __compar_fn_t _compar)



                                ;
void * calloc (size_t __nmemb, size_t __size) __attribute__ ((nothrow));
div_t div (int __numer, int __denom);
void exit (int __status) __attribute__ ((noreturn));
void free (void *) __attribute__ ((nothrow));
char * getenv (const char *__string);
char * _getenv_r (struct _reent *, const char *__string);
char * _findenv (const char *, int *);
char * _findenv_r (struct _reent *, const char *, int *);

extern char *suboptarg; /* getsubopt(3) external variable */
int getsubopt (char **, char * const *, char **);

long labs (long);
ldiv_t ldiv (long __numer, long __denom);
void * malloc (size_t __size) __attribute__ ((nothrow));
int mblen (const char *, size_t);
int _mblen_r (struct _reent *, const char *, size_t, _mbstate_t *);
int mbtowc (wchar_t *__restrict, const char *__restrict, size_t);
int _mbtowc_r (struct _reent *, wchar_t *__restrict, const char *__restrict, size_t, _mbstate_t *);
int wctomb (char *, wchar_t);
int _wctomb_r (struct _reent *, char *, wchar_t, _mbstate_t *);
size_t mbstowcs (wchar_t *__restrict, const char *__restrict, size_t);
size_t _mbstowcs_r (struct _reent *, wchar_t *__restrict, const char *__restrict, size_t, _mbstate_t *);
size_t wcstombs (char *__restrict, const wchar_t *__restrict, size_t);
size_t _wcstombs_r (struct _reent *, char *__restrict, const wchar_t *__restrict, size_t, _mbstate_t *);


char * mkdtemp (char *);
int mkostemp (char *, int);
int mkostemps (char *, int, int);
int mkstemp (char *);
int mkstemps (char *, int);
char * mktemp (char *) __attribute__ ((__warning__ ("the use of `mktemp' is dangerous; use `mkstemp' instead")));

char * _mkdtemp_r (struct _reent *, char *);
int _mkostemp_r (struct _reent *, char *, int);
int _mkostemps_r (struct _reent *, char *, int, int);
int _mkstemp_r (struct _reent *, char *);
int _mkstemps_r (struct _reent *, char *, int);
char * _mktemp_r (struct _reent *, char *) __attribute__ ((__warning__ ("the use of `mktemp' is dangerous; use `mkstemp' instead")));

void qsort (void * __base, size_t __nmemb, size_t __size, __compar_fn_t _compar);
int rand (void);
void * realloc (void * __r, size_t __size) __attribute__ ((nothrow));

void * reallocf (void * __r, size_t __size);
char * realpath (const char *__restrict path, char *__restrict resolved_path);

void srand (unsigned __seed);
double strtod (const char *__restrict __n, char **__restrict __end_PTR);
double _strtod_r (struct _reent *,const char *__restrict __n, char **__restrict __end_PTR);

float strtof (const char *__restrict __n, char **__restrict __end_PTR);


/* the following strtodf interface is deprecated...use strtof instead */




long strtol (const char *__restrict __n, char **__restrict __end_PTR, int __base);
long _strtol_r (struct _reent *,const char *__restrict __n, char **__restrict __end_PTR, int __base);
unsigned long strtoul (const char *__restrict __n, char **__restrict __end_PTR, int __base);
unsigned long _strtoul_r (struct _reent *,const char *__restrict __n, char **__restrict __end_PTR, int __base);

int system (const char *__string);


long a64l (const char *__input);
char * l64a (long __input);
char * _l64a_r (struct _reent *,long __input);
int on_exit (void (*__func)(int, void *),void * __arg);
void _Exit (int __status) __attribute__ ((noreturn));
int putenv (char *__string);
int _putenv_r (struct _reent *, char *__string);
void * _reallocf_r (struct _reent *, void *, size_t);
int setenv (const char *__string, const char *__value, int __overwrite);
int _setenv_r (struct _reent *, const char *__string, const char *__value, int __overwrite);

char * gcvt (double,int,char *);
char * gcvtf (float,int,char *);
char * fcvt (double,int,int *,int *);
char * fcvtf (float,int,int *,int *);
char * ecvt (double,int,int *,int *);
char * ecvtbuf (double, int, int*, int*, char *);
char * fcvtbuf (double, int, int*, int*, char *);
char * ecvtf (float,int,int *,int *);
char * dtoa (double, int, int, int *, int*, char**);
int rand_r (unsigned *__seed);

double drand48 (void);
double _drand48_r (struct _reent *);
double erand48 (unsigned short [3]);
double _erand48_r (struct _reent *, unsigned short [3]);
long jrand48 (unsigned short [3]);
long _jrand48_r (struct _reent *, unsigned short [3]);
void lcong48 (unsigned short [7]);
void _lcong48_r (struct _reent *, unsigned short [7]);
long lrand48 (void);
long _lrand48_r (struct _reent *);
long mrand48 (void);
long _mrand48_r (struct _reent *);
long nrand48 (unsigned short [3]);
long _nrand48_r (struct _reent *, unsigned short [3]);
unsigned short *
       seed48 (unsigned short [3]);
unsigned short *
       _seed48_r (struct _reent *, unsigned short [3]);
void srand48 (long);
void _srand48_r (struct _reent *, long);
long long atoll (const char *__nptr);
long long _atoll_r (struct _reent *, const char *__nptr);
long long llabs (long long);
lldiv_t lldiv (long long __numer, long long __denom);


long long strtoll (const char *__restrict __n, char **__restrict __end_PTR, int __base);


long long _strtoll_r (struct _reent *, const char *__restrict __n, char **__restrict __end_PTR, int __base);


unsigned long long strtoull (const char *__restrict __n, char **__restrict __end_PTR, int __base);


unsigned long long _strtoull_r (struct _reent *, const char *__restrict __n, char **__restrict __end_PTR, int __base);


void cfree (void *);
int unsetenv (const char *__string);
int _unsetenv_r (struct _reent *, const char *__string);
# 221 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdlib.h" 3
char * _dtoa_r (struct _reent *, double, int, int, int *, int*, char**);

void * _malloc_r (struct _reent *, size_t) __attribute__ ((nothrow));
void * _calloc_r (struct _reent *, size_t, size_t) __attribute__ ((nothrow));
void _free_r (struct _reent *, void *) __attribute__ ((nothrow));
void * _realloc_r (struct _reent *, void *, size_t) __attribute__ ((nothrow));
void _mstats_r (struct _reent *, char *);

int _system_r (struct _reent *, const char *);

void __eprintf (const char *, const char *, unsigned int, const char *);

/* On platforms where long double equals double.  */


extern long double strtold (const char *__restrict, char **__restrict);



}
# 25 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/string.h" 1 3
/*
 * string.h
 *
 * Definitions for memory and string functions.
 */




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/_ansi.h" 1 3
/* Provide support for both ANSI and non-ANSI environments.  */

/* Some ANSI environments are "broken" in the sense that __STDC__ cannot be
   relied upon to have it's intended meaning.  Therefore we must use our own
   concoction: _HAVE_STDC.  Always use _HAVE_STDC instead of __STDC__ in newlib
   sources!

   To get a strict ANSI C environment, define macro __STRICT_ANSI__.  This will
   "comment out" the non-ANSI parts of the ANSI header files (non-ANSI header
   files aren't affected).  */
# 11 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/string.h" 2 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/reent.h" 1 3
/* This header file provides the reentrancy.  */

/* WARNING: All identifiers here must begin with an underscore.  This file is
   included by stdio.h and others and we therefore must only use identifiers
   in the namespace allotted to us.  */
# 12 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/string.h" 2 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include-fixed/sys/cdefs.h" 1 3 4
/*  DO NOT EDIT THIS FILE.

    It has been auto-edited by fixincludes from:

	"/home/cmaglie/toolchain/gcc-arm-none-eabi-4_8-2014q1-20140314/install-native/arm-none-eabi/usr/include/sys/cdefs.h"

    This had to be done to correct non-standard usages in the
    original, manufacturer supplied header file.  */

/* libc/sys/linux/sys/cdefs.h - Helper macros for K&R vs. ANSI C compat. */

/* Written 2000 by Werner Almesberger */

/*-
 * Copyright (c) 1991, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Berkeley Software Design, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)cdefs.h	8.8 (Berkeley) 1/9/95
 * $FreeBSD$
 */




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/_default_types.h" 1 3 4
/*
 *  $Id$
 */
# 53 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include-fixed/sys/cdefs.h" 2 3 4
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/features.h" 1 3 4
/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id$
 */
# 54 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include-fixed/sys/cdefs.h" 2 3 4
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 1 3 4
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
# 55 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include-fixed/sys/cdefs.h" 2 3 4
# 78 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include-fixed/sys/cdefs.h" 3 4
/*
 * Testing against Clang-specific extensions.
 */
# 103 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include-fixed/sys/cdefs.h" 3 4
/*
 * This code has been put in place to help reduce the addition of
 * compiler specific defines in FreeBSD code.  It helps to aid in
 * having a compiler-agnostic source tree.
 */
# 141 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include-fixed/sys/cdefs.h" 3 4
/*
 * Compiler memory barriers, specific to gcc and clang.
 */
# 155 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include-fixed/sys/cdefs.h" 3 4
/* XXX: if __GNUC__ >= 2: not tested everywhere originally, where replaced */
# 169 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include-fixed/sys/cdefs.h" 3 4
/*
 * The __CONCAT macro is used to concatenate parts of symbol names, e.g.
 * with "#define OLD(foo) __CONCAT(old,foo)", OLD(foo) produces oldfoo.
 * The __CONCAT macro is a bit tricky to use if it must work in non-ANSI
 * mode -- there must be no spaces between its arguments, and for nested
 * __CONCAT's, all the __CONCAT's must be at the left.  __CONCAT can also
 * concatenate double-quoted strings produced by the __STRING macro, but
 * this only works with ANSI C.
 *
 * __XSTRING is like __STRING, but it expands any macros in its argument
 * first.  It is only available with ANSI C.
 */
# 226 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include-fixed/sys/cdefs.h" 3 4
/*
 * Compiler-dependent macros to help declare dead (non-returning) and
 * pure (no side effects) functions, and unused variables.  They are
 * null except for versions of gcc that are known to support the features
 * properly (old versions of gcc-2 supported the dead and pure features
 * in a different (wrong) way).  If we do not provide an implementation
 * for a given compiler, let the compile fail if it is told to use
 * a feature that we cannot live without.
 */
# 278 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include-fixed/sys/cdefs.h" 3 4
/*
 * Keywords added in C11.
 */
# 301 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include-fixed/sys/cdefs.h" 3 4
/*
 * No native support for _Atomic(). Place object in structure to prevent
 * most forms of direct non-atomic access.
 */
# 330 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include-fixed/sys/cdefs.h" 3 4
/* XXX: Change this to test against C++11 when clang in base supports it. */
# 341 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include-fixed/sys/cdefs.h" 3 4
/*
 * Emulation of C11 _Generic().  Unlike the previously defined C11
 * keywords, it is not possible to implement this using exactly the same
 * syntax.  Therefore implement something similar under the name
 * __generic().  Unlike _Generic(), this macro can only distinguish
 * between a single type, so it requires nested invocations to
 * distinguish multiple cases.
 */
# 397 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include-fixed/sys/cdefs.h" 3 4
/* XXX: should use `#if __STDC_VERSION__ < 199901'. */




/*
 * GCC 2.95 provides `__restrict' as an extension to C90 to support the
 * C99-specific `restrict' type qualifier.  We happen to use `__restrict' as
 * a way to define the `restrict' type qualifier without disturbing older
 * software that is unaware of C99 keywords.
 */
# 416 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include-fixed/sys/cdefs.h" 3 4
/*
 * GNU C version 2.96 adds explicit branch prediction so that
 * the CPU back-end can hint the processor and also so that
 * code blocks can be reordered such that the predicted path
 * sees a more linear flow, thus improving cache behavior, etc.
 *
 * The following two macros provide us with a way to utilize this
 * compiler feature.  Use __predict_true() if you expect the expression
 * to evaluate to true, and __predict_false() if you expect the
 * expression to evaluate to false.
 *
 * A few notes about usage:
 *
 *	* Generally, __predict_false() error condition checks (unless
 *	  you have some _strong_ reason to do otherwise, in which case
 *	  document it), and/or __predict_true() `no-error' condition
 *	  checks, assuming you want to optimize for the no-error case.
 *
 *	* Other than that, if you don't know the likelihood of a test
 *	  succeeding from empirical or other `hard' evidence, don't
 *	  make predictions.
 *
 *	* These are meant to be used in places that are run `a lot'.
 *	  It is wasteful to make predictions in code that is run
 *	  seldomly (e.g. at subsystem initialization time) as the
 *	  basic block reordering that this affects can often generate
 *	  larger code.
 */
# 464 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include-fixed/sys/cdefs.h" 3 4
/*
 * Given the pointer x to the member m of the struct s, return
 * a pointer to the containing structure.  When using GCC, we first
 * assign pointer x to a local variable, to check that its type is
 * compatible with member m.
 */
# 480 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include-fixed/sys/cdefs.h" 3 4
/*
 * Compiler-dependent macros to declare that functions take printf-like
 * or scanf-like arguments.  They are null except for versions of gcc
 * that are known to support the features properly (old versions of gcc-2
 * didn't permit keeping the keywords out of the application namespace).
 */
# 504 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include-fixed/sys/cdefs.h" 3 4
/* Compiler-dependent macros that rely on FreeBSD-specific extensions. */
# 595 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include-fixed/sys/cdefs.h" 3 4
/*-
 * The following definitions are an extension of the behavior originally
 * implemented in <sys/_posix.h>, but with a different level of granularity.
 * POSIX.1 requires that the macros we test be defined before any standard
 * header file is included.
 *
 * Here's a quick run-down of the versions:
 *  defined(_POSIX_SOURCE)		1003.1-1988
 *  _POSIX_C_SOURCE == 1		1003.1-1990
 *  _POSIX_C_SOURCE == 2		1003.2-1992 C Language Binding Option
 *  _POSIX_C_SOURCE == 199309		1003.1b-1993
 *  _POSIX_C_SOURCE == 199506		1003.1c-1995, 1003.1i-1995,
 *					and the omnibus ISO/IEC 9945-1: 1996
 *  _POSIX_C_SOURCE == 200112		1003.1-2001
 *  _POSIX_C_SOURCE == 200809		1003.1-2008
 *
 * In addition, the X/Open Portability Guide, which is now the Single UNIX
 * Specification, defines a feature-test macro which indicates the version of
 * that specification, and which subsumes _POSIX_C_SOURCE.
 *
 * Our macros begin with two underscores to avoid namespace screwage.
 */

/* Deal with IEEE Std. 1003.1-1990, in which _POSIX_C_SOURCE == 1. */





/* Deal with IEEE Std. 1003.2-1992, in which _POSIX_C_SOURCE == 2. */





/* Deal with various X/Open Portability Guides and Single UNIX Spec. */
# 647 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include-fixed/sys/cdefs.h" 3 4
/*
 * Deal with all versions of POSIX.  The ordering relative to the tests above is
 * important.
 */
# 678 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include-fixed/sys/cdefs.h" 3 4
/*-
 * Deal with _ANSI_SOURCE:
 * If it is defined, and no other compilation environment is explicitly
 * requested, then define our internal feature-test macros to zero.  This
 * makes no difference to the preprocessor (undefined symbols in preprocessing
 * expressions are defined to have value zero), but makes it more convenient for
 * a test program to print out the values.
 *
 * If a program mistakenly defines _ANSI_SOURCE and some other macro such as
 * _POSIX_C_SOURCE, we will assume that it wants the broader compilation
 * environment (and in fact we will never get here).
 */
# 13 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/string.h" 2 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/features.h" 1 3
/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id$
 */
# 14 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/string.h" 2 3



# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 1 3 4
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
# 46 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */

/* On 4.3bsd-net2, make sure ansi.h is included, so we have
   one less case to deal with in the following.  */



/* On FreeBSD 5, machine/ansi.h does not exist anymore... */




/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
   defined if the corresponding type is *not* defined.
   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_ */
# 92 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 117 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 157 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* If this symbol has done its job, get rid of it.  */




/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 238 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 358 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
    are already defined.  */
/*  BSD/OS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
# 394 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* A null pointer constant.  */
# 412 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* Offset of member MEMBER in a struct of type TYPE. */
# 18 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/string.h" 2 3

extern "C" {

void * memchr (const void *, int, size_t);
int memcmp (const void *, const void *, size_t);
void * memcpy (void * , const void * , size_t);
void * memmove (void *, const void *, size_t);
void * memset (void *, int, size_t);
char *strcat (char *, const char *);
char *strchr (const char *, int);
int strcmp (const char *, const char *);
int strcoll (const char *, const char *);
char *strcpy (char *, const char *);
size_t strcspn (const char *, const char *);
char *strerror (int);
size_t strlen (const char *);
char *strncat (char *, const char *, size_t);
int strncmp (const char *, const char *, size_t);
char *strncpy (char *, const char *, size_t);
char *strpbrk (const char *, const char *);
char *strrchr (const char *, int);
size_t strspn (const char *, const char *);
char *strstr (const char *, const char *);


char *strtok (char *, const char *);


size_t strxfrm (char *, const char *, size_t);


char *strtok_r (char *, const char *, char **);

int bcmp (const void *, const void *, size_t);
void bcopy (const void *, void *, size_t);
void bzero (void *, size_t);
int ffs (int);
char *index (const char *, int);
void * memccpy (void * , const void * , int, size_t);
void * mempcpy (void *, const void *, size_t);
void * memmem (const void *, size_t, const void *, size_t);
void * memrchr (const void *, int, size_t);
void * rawmemchr (const void *, int);
char *rindex (const char *, int);
char *stpcpy (char *, const char *);
char *stpncpy (char *, const char *, size_t);
int strcasecmp (const char *, const char *);
char *strcasestr (const char *, const char *);
char *strchrnul (const char *, int);


char *strdup (const char *);


char *_strdup_r (struct _reent *, const char *);


char *strndup (const char *, size_t);


char *_strndup_r (struct _reent *, const char *, size_t);
/* There are two common strerror_r variants.  If you request
   _GNU_SOURCE, you get the GNU version; otherwise you get the POSIX
   version.  POSIX requires that #undef strerror_r will still let you
   invoke the underlying function, but that requires gcc support.  */




int strerror_r (int, char *, size_t) __asm__ ("" /* stringify without expanding x */ /* expand x, then stringify */ "__xpg_strerror_r");





size_t strlcat (char *, const char *, size_t);
size_t strlcpy (char *, const char *, size_t);
int strncasecmp (const char *, const char *, size_t);
size_t strnlen (const char *, size_t);
char *strsep (char **, const char *);
char *strlwr (char *);
char *strupr (char *);

char *strsignal (int __signo);





/* Recursive version of strerror.  */
char * _strerror_r (struct _reent *, int, int, int *);
# 124 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/string.h" 3
/* These function names are used on Windows and perhaps other systems.  */
# 140 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/string.h" 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/string.h" 1 3
/* This is a dummy <sys/string.h> used as a placeholder for
   systems that need to have a special header file.  */
# 141 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/string.h" 2 3

}
# 26 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/math.h" 1 3




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/reent.h" 1 3
/* This header file provides the reentrancy.  */

/* WARNING: All identifiers here must begin with an underscore.  This file is
   included by stdio.h and others and we therefore must only use identifiers
   in the namespace allotted to us.  */
# 6 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/math.h" 2 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/ieeefp.h" 1 3
# 7 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/math.h" 2 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/_ansi.h" 1 3
/* Provide support for both ANSI and non-ANSI environments.  */

/* Some ANSI environments are "broken" in the sense that __STDC__ cannot be
   relied upon to have it's intended meaning.  Therefore we must use our own
   concoction: _HAVE_STDC.  Always use _HAVE_STDC instead of __STDC__ in newlib
   sources!

   To get a strict ANSI C environment, define macro __STRICT_ANSI__.  This will
   "comment out" the non-ANSI parts of the ANSI header files (non-ANSI header
   files aren't affected).  */
# 8 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/math.h" 2 3

extern "C" {

/* __dmath, __fmath, and __ldmath are only here for backwards compatibility
 * in case any code used them.  They are no longer used by Newlib, itself,
 * other than legacy.  */
union __dmath
{
  double d;
  __ULong i[2];
};

union __fmath
{
  float f;
  __ULong i[1];
};


union __ldmath
{
  long double ld;
  __ULong i[4];
};


/* Natural log of 2 */



 /* gcc >= 3.3 implicitly defines builtins for HUGE_VALx values.  */
# 105 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/math.h" 3
/* Reentrant ANSI C functions.  */


extern double atan (double);
extern double cos (double);
extern double sin (double);
extern double tan (double);
extern double tanh (double);
extern double frexp (double, int *);
extern double modf (double, double *);
extern double ceil (double);
extern double fabs (double);
extern double floor (double);


/* Non reentrant ANSI C functions.  */



extern double acos (double);
extern double asin (double);
extern double atan2 (double, double);
extern double cosh (double);
extern double sinh (double);
extern double exp (double);
extern double ldexp (double, int);
extern double log (double);
extern double log10 (double);
extern double pow (double, double);
extern double sqrt (double);
extern double fmod (double, double);





/* ISO C99 types and macros. */

/* FIXME:  FLT_EVAL_METHOD should somehow be gotten from float.h (which is hard,
 * considering that the standard says the includes it defines should not
 * include other includes that it defines) and that value used.  (This can be
 * solved, but autoconf has a bug which makes the solution more difficult, so
 * it has been skipped for now.)  */






    typedef float float_t;
    typedef double double_t;
# 198 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/math.h" 3
extern int __isinff (float x);
extern int __isinfd (double x);
extern int __isnanf (float x);
extern int __isnand (double x);
extern int __fpclassifyf (float x);
extern int __fpclassifyd (double x);
extern int __signbitf (float x);
extern int __signbitd (double x);
# 217 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/math.h" 3
/* Note: isinf and isnan were once functions in newlib that took double
 *       arguments.  C99 specifies that these names are reserved for macros
 *       supporting multiple floating point types.  Thus, they are
 *       now defined as macros.  Implementations of the old functions
 *       taking double arguments still exist for compatibility purposes
 *       (prototypes for them are in <ieeefp.h>).  */
# 256 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/math.h" 3
/* Non ANSI double precision functions.  */

extern double infinity (void);
extern double nan (const char *);
extern int finite (double);
extern double copysign (double, double);
extern double logb (double);
extern int ilogb (double);

extern double asinh (double);
extern double cbrt (double);
extern double nextafter (double, double);
extern double rint (double);
extern double scalbn (double, int);

extern double exp2 (double);
extern double scalbln (double, long int);
extern double tgamma (double);
extern double nearbyint (double);
extern long int lrint (double);
extern long long int llrint (double);
extern double round (double);
extern long int lround (double);
extern long long int llround (double);
extern double trunc (double);
extern double remquo (double, double, int *);
extern double fdim (double, double);
extern double fmax (double, double);
extern double fmin (double, double);
extern double fma (double, double, double);


extern double log1p (double);
extern double expm1 (double);



extern double acosh (double);
extern double atanh (double);
extern double remainder (double, double);
extern double gamma (double);
extern double lgamma (double);
extern double erf (double);
extern double erfc (double);
extern double log2 (double);





extern double hypot (double, double);




/* Single precision versions of ANSI functions.  */

extern float atanf (float);
extern float cosf (float);
extern float sinf (float);
extern float tanf (float);
extern float tanhf (float);
extern float frexpf (float, int *);
extern float modff (float, float *);
extern float ceilf (float);
extern float fabsf (float);
extern float floorf (float);


extern float acosf (float);
extern float asinf (float);
extern float atan2f (float, float);
extern float coshf (float);
extern float sinhf (float);
extern float expf (float);
extern float ldexpf (float, int);
extern float logf (float);
extern float log10f (float);
extern float powf (float, float);
extern float sqrtf (float);
extern float fmodf (float, float);


/* Other single precision functions.  */

extern float exp2f (float);
extern float scalblnf (float, long int);
extern float tgammaf (float);
extern float nearbyintf (float);
extern long int lrintf (float);
extern long long llrintf (float);
extern float roundf (float);
extern long int lroundf (float);
extern long long int llroundf (float);
extern float truncf (float);
extern float remquof (float, float, int *);
extern float fdimf (float, float);
extern float fmaxf (float, float);
extern float fminf (float, float);
extern float fmaf (float, float, float);

extern float infinityf (void);
extern float nanf (const char *);
extern int finitef (float);
extern float copysignf (float, float);
extern float logbf (float);
extern int ilogbf (float);

extern float asinhf (float);
extern float cbrtf (float);
extern float nextafterf (float, float);
extern float rintf (float);
extern float scalbnf (float, int);
extern float log1pf (float);
extern float expm1f (float);


extern float acoshf (float);
extern float atanhf (float);
extern float remainderf (float, float);
extern float gammaf (float);
extern float lgammaf (float);
extern float erff (float);
extern float erfcf (float);
extern float log2f (float);
extern float hypotf (float, float);


/* On platforms where long double equals double.  */

/* Reentrant ANSI C functions.  */

extern long double atanl (long double);
extern long double cosl (long double);
extern long double sinl (long double);
extern long double tanl (long double);
extern long double tanhl (long double);
extern long double frexpl (long double value, int *);
extern long double modfl (long double, long double *);
extern long double ceill (long double);
extern long double fabsl (long double);
extern long double floorl (long double);
extern long double log1pl (long double);
extern long double expm1l (long double);

/* Non reentrant ANSI C functions.  */


extern long double acosl (long double);
extern long double asinl (long double);
extern long double atan2l (long double, long double);
extern long double coshl (long double);
extern long double sinhl (long double);
extern long double expl (long double);
extern long double ldexpl (long double, int);
extern long double logl (long double);
extern long double log10l (long double);
extern long double powl (long double, long double);
extern long double sqrtl (long double);
extern long double fmodl (long double, long double);
extern long double hypotl (long double, long double);


extern long double copysignl (long double, long double);
extern long double nanl (const char *);
extern int ilogbl (long double);
extern long double asinhl (long double);
extern long double cbrtl (long double);
extern long double nextafterl (long double, long double);
extern long double rintl (long double);
extern long double scalbnl (long double, int);
extern long double exp2l (long double);
extern long double scalblnl (long double, long);
extern long double tgammal (long double);
extern long double nearbyintl (long double);
extern long int lrintl (long double);
extern long long int llrintl (long double);
extern long double roundl (long double);
extern long lroundl (long double);
extern long long int llroundl (long double);
extern long double truncl (long double);
extern long double remquol (long double, long double, int *);
extern long double fdiml (long double, long double);
extern long double fmaxl (long double, long double);
extern long double fminl (long double, long double);
extern long double fmal (long double, long double, long double);

extern long double acoshl (long double);
extern long double atanhl (long double);
extern long double remainderl (long double, long double);
extern long double lgammal (long double);
extern long double erfl (long double);
extern long double erfcl (long double);
# 463 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/math.h" 3
extern double drem (double, double);
extern void sincos (double, double *, double *);
extern double gamma_r (double, int *);
extern double lgamma_r (double, int *);

extern double y0 (double);
extern double y1 (double);
extern double yn (int, double);
extern double j0 (double);
extern double j1 (double);
extern double jn (int, double);

extern float dremf (float, float);
extern void sincosf (float, float *, float *);
extern float gammaf_r (float, int *);
extern float lgammaf_r (float, int *);

extern float y0f (float);
extern float y1f (float);
extern float ynf (int, float);
extern float j0f (float);
extern float j1f (float);
extern float jnf (int, float);

/* GNU extensions */

extern double exp10 (double);


extern double pow10 (double);


extern float exp10f (float);


extern float pow10f (float);






/* The gamma functions use a global variable, signgam.  */


extern int *__signgam (void);




/* The exception structure passed to the matherr routine.  */
/* We have a problem when using C++ since `exception' is a reserved
   name in C++.  */

struct __exception



{
  int type;
  char *name;
  double arg1;
  double arg2;
  double retval;
  int err;
};


extern int matherr (struct __exception *e);




/* Values for the type field of struct exception.  */
# 545 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/math.h" 3
/* Useful constants.  */
# 572 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/math.h" 3
/* Global control over fdlibm error handling.  */

enum __fdlibm_version
{
  __fdlibm_ieee = -1,
  __fdlibm_svid,
  __fdlibm_xopen,
  __fdlibm_posix
};




extern enum __fdlibm_version __fdlib_version;
# 594 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/math.h" 3
}
# 27 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2

// some libraries and sketches depend on this
// AVR stuff, assuming Arduino.h or WProgram.h
// automatically includes it...
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/avr/pgmspace.h" 1
/*
  pgmspace.h - Definitions for compatibility with AVR pgmspace macros

  Copyright (c) 2015 Arduino LLC

  Based on work of Paul Stoffregen on Teensy 3 (http://pjrc.com)

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE
*/




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/inttypes.h" 1 3
/*
 * Copyright (c) 2004, 2005 by
 * Ralf Corsepius, Ulm/Germany. All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software
 * is freely granted, provided that this notice is preserved.
 */

/**
 *  @file  inttypes.h
 */




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/features.h" 1 3
/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id$
 */
# 17 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/inttypes.h" 2 3


# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 1 3 4
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
# 46 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */

/* On 4.3bsd-net2, make sure ansi.h is included, so we have
   one less case to deal with in the following.  */



/* On FreeBSD 5, machine/ansi.h does not exist anymore... */




/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
   defined if the corresponding type is *not* defined.
   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_ */
# 92 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 117 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 157 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* If this symbol has done its job, get rid of it.  */




/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 238 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 358 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
    are already defined.  */
/*  BSD/OS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
# 394 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* A null pointer constant.  */
# 412 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* Offset of member MEMBER in a struct of type TYPE. */
# 20 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/inttypes.h" 2 3

/* Don't use __STDINT_EXP test since GCC's stdint.h provides different
   macros than newlib's stdint.h. */
# 32 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/inttypes.h" 3
/* 8-bit types */
# 78 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/inttypes.h" 3
/* 16-bit types */
# 124 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/inttypes.h" 3
/* 32-bit types */
# 175 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/inttypes.h" 3
/* 64-bit types */
# 229 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/inttypes.h" 3
/* max-bit types */
# 254 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/inttypes.h" 3
/* ptr types */
# 280 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/inttypes.h" 3
typedef struct {
  intmax_t quot;
  intmax_t rem;
} imaxdiv_t;


extern "C" {


extern intmax_t imaxabs(intmax_t j);
extern imaxdiv_t imaxdiv(intmax_t numer, intmax_t denomer);
extern intmax_t strtoimax(const char *, char **, int);
extern uintmax_t strtoumax(const char *, char **, int);
extern intmax_t wcstoimax(const wchar_t *, wchar_t **, int);
extern uintmax_t wcstoumax(const wchar_t *, wchar_t **, int);


}
# 31 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/avr/pgmspace.h" 2







typedef void prog_void;
typedef char prog_char;
typedef unsigned char prog_uchar;
typedef int8_t prog_int8_t;
typedef uint8_t prog_uint8_t;
typedef int16_t prog_int16_t;
typedef uint16_t prog_uint16_t;
typedef int32_t prog_int32_t;
typedef uint32_t prog_uint32_t;
# 32 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/avr/interrupt.h" 1
# 33 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/binary.h" 1
/*
  binary.h - Definitions for binary constants
  Copyright (c) 2006 David A. Mellis.  All right reserved.

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
# 35 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/itoa.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/





extern "C"{
# 32 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/itoa.h"
extern char* itoa( int value, char *string, int radix ) ;
extern char* ltoa( long value, char *string, int radix ) ;
extern char* utoa( unsigned long value, char *string, int radix ) ;
extern char* ultoa( unsigned long value, char *string, int radix ) ;



} // extern "C"
# 36 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2


extern "C"{


// Includes Atmel CMSIS
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/




/*
 * Core and peripherals registers definitions
 */
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */






/*
 * ----------------------------------------------------------------------------
 * SAM3 family
 * ----------------------------------------------------------------------------
 */

/* SAM3N series */
# 66 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam.h"
/* Entire SAM3N series */



/* SAM3S series */
# 95 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam.h"
/* Entire SAM3S series */


/* SAM3SD8 series */
# 107 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam.h"
/* Entire SAM3SD8 series */


/* SAM3U series */
# 123 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam.h"
/* Entire SAM3U series */


/* SAM3XA series */
# 142 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam.h"
/* Entire SAM3XA series */


/*
 * ----------------------------------------------------------------------------
 * SAM4 family
 * ----------------------------------------------------------------------------
 */


/* Entire SAM3 Family */


/* SAM4S series */
# 164 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam.h"
/* Entire SAM4S series */


/* Entire SAM4 Family */


/*
 * ----------------------------------------------------------------------------
 * SAM9 family
 * ----------------------------------------------------------------------------
 */

/*
 * ----------------------------------------------------------------------------
 * SAM7 family
 * ----------------------------------------------------------------------------
 */



/*
 * ----------------------------------------------------------------------------
 * Whole SAM product line
 * ----------------------------------------------------------------------------
 */


/*
 * ----------------------------------------------------------------------------
 * Header inclusion
 * ----------------------------------------------------------------------------
 */


# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */
# 59 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3.h"
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3xa.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */
# 44 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3xa.h"
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/** \addtogroup SAM3X8E_definitions SAM3X8E definitions
  This file defines all structures and symbols for SAM3X8E:
    - registers and bitfields
    - peripheral base address
    - peripheral ID
    - PIO definitions
*/
/*@{*/


 extern "C" {







typedef volatile uint32_t RoReg; /**< Read only 32-bit register (volatile const unsigned int) */

typedef volatile uint32_t WoReg; /**< Write only 32-bit register (volatile unsigned int) */
typedef volatile uint32_t RwReg; /**< Read-Write 32-bit register (volatile unsigned int) */


/* ************************************************************************** */
/*   CMSIS DEFINITIONS FOR SAM3X8E */
/* ************************************************************************** */
/** \addtogroup SAM3X8E_cmsis CMSIS Definitions */
/*@{*/

/**< Interrupt Number Definition */
typedef enum IRQn
{
/******  Cortex-M3 Processor Exceptions Numbers ******************************/
  NonMaskableInt_IRQn = -14, /**<  2 Non Maskable Interrupt                */
  MemoryManagement_IRQn = -12, /**<  4 Cortex-M3 Memory Management Interrupt */
  BusFault_IRQn = -11, /**<  5 Cortex-M3 Bus Fault Interrupt         */
  UsageFault_IRQn = -10, /**<  6 Cortex-M3 Usage Fault Interrupt       */
  SVCall_IRQn = -5, /**< 11 Cortex-M3 SV Call Interrupt           */
  DebugMonitor_IRQn = -4, /**< 12 Cortex-M3 Debug Monitor Interrupt     */
  PendSV_IRQn = -2, /**< 14 Cortex-M3 Pend SV Interrupt           */
  SysTick_IRQn = -1, /**< 15 Cortex-M3 System Tick Interrupt       */
/******  SAM3X8E specific Interrupt Numbers *********************************/

  SUPC_IRQn = 0, /**<  0 SAM3X8E Supply Controller (SUPC) */
  RSTC_IRQn = 1, /**<  1 SAM3X8E Reset Controller (RSTC) */
  RTC_IRQn = 2, /**<  2 SAM3X8E Real Time Clock (RTC) */
  RTT_IRQn = 3, /**<  3 SAM3X8E Real Time Timer (RTT) */
  WDT_IRQn = 4, /**<  4 SAM3X8E Watchdog Timer (WDT) */
  PMC_IRQn = 5, /**<  5 SAM3X8E Power Management Controller (PMC) */
  EFC0_IRQn = 6, /**<  6 SAM3X8E Enhanced Flash Controller 0 (EFC0) */
  EFC1_IRQn = 7, /**<  7 SAM3X8E Enhanced Flash Controller 1 (EFC1) */
  UART_IRQn = 8, /**<  8 SAM3X8E Universal Asynchronous Receiver Transceiver (UART) */
  SMC_IRQn = 9, /**<  9 SAM3X8E Static Memory Controller (SMC) */
  PIOA_IRQn = 11, /**< 11 SAM3X8E Parallel I/O Controller A, (PIOA) */
  PIOB_IRQn = 12, /**< 12 SAM3X8E Parallel I/O Controller B (PIOB) */
  PIOC_IRQn = 13, /**< 13 SAM3X8E Parallel I/O Controller C (PIOC) */
  PIOD_IRQn = 14, /**< 14 SAM3X8E Parallel I/O Controller D (PIOD) */
  USART0_IRQn = 17, /**< 17 SAM3X8E USART 0 (USART0) */
  USART1_IRQn = 18, /**< 18 SAM3X8E USART 1 (USART1) */
  USART2_IRQn = 19, /**< 19 SAM3X8E USART 2 (USART2) */
  USART3_IRQn = 20, /**< 20 SAM3X8E USART 3 (USART3) */
  HSMCI_IRQn = 21, /**< 21 SAM3X8E Multimedia Card Interface (HSMCI) */
  TWI0_IRQn = 22, /**< 22 SAM3X8E Two-Wire Interface 0 (TWI0) */
  TWI1_IRQn = 23, /**< 23 SAM3X8E Two-Wire Interface 1 (TWI1) */
  SPI0_IRQn = 24, /**< 24 SAM3X8E Serial Peripheral Interface (SPI0) */
  SSC_IRQn = 26, /**< 26 SAM3X8E Synchronous Serial Controller (SSC) */
  TC0_IRQn = 27, /**< 27 SAM3X8E Timer Counter 0 (TC0) */
  TC1_IRQn = 28, /**< 28 SAM3X8E Timer Counter 1 (TC1) */
  TC2_IRQn = 29, /**< 29 SAM3X8E Timer Counter 2 (TC2) */
  TC3_IRQn = 30, /**< 30 SAM3X8E Timer Counter 3 (TC3) */
  TC4_IRQn = 31, /**< 31 SAM3X8E Timer Counter 4 (TC4) */
  TC5_IRQn = 32, /**< 32 SAM3X8E Timer Counter 5 (TC5) */
  TC6_IRQn = 33, /**< 33 SAM3X8E Timer Counter 6 (TC6) */
  TC7_IRQn = 34, /**< 34 SAM3X8E Timer Counter 7 (TC7) */
  TC8_IRQn = 35, /**< 35 SAM3X8E Timer Counter 8 (TC8) */
  PWM_IRQn = 36, /**< 36 SAM3X8E Pulse Width Modulation Controller (PWM) */
  ADC_IRQn = 37, /**< 37 SAM3X8E ADC Controller (ADC) */
  DACC_IRQn = 38, /**< 38 SAM3X8E DAC Controller (DACC) */
  DMAC_IRQn = 39, /**< 39 SAM3X8E DMA Controller (DMAC) */
  UOTGHS_IRQn = 40, /**< 40 SAM3X8E USB OTG High Speed (UOTGHS) */
  TRNG_IRQn = 41, /**< 41 SAM3X8E True Random Number Generator (TRNG) */
  EMAC_IRQn = 42, /**< 42 SAM3X8E Ethernet MAC (EMAC) */
  CAN0_IRQn = 43, /**< 43 SAM3X8E CAN Controller 0 (CAN0) */
  CAN1_IRQn = 44, /**< 44 SAM3X8E CAN Controller 1 (CAN1) */

  PERIPH_COUNT_IRQn = 45 /**< Number of peripheral IDs */
} IRQn_Type;

typedef struct _DeviceVectors
{
  /* Stack pointer */
  void* pvStack;

  /* Cortex-M handlers */
  void* pfnReset_Handler;
  void* pfnNMI_Handler;
  void* pfnHardFault_Handler;
  void* pfnMemManage_Handler;
  void* pfnBusFault_Handler;
  void* pfnUsageFault_Handler;
  void* pfnReserved1_Handler;
  void* pfnReserved2_Handler;
  void* pfnReserved3_Handler;
  void* pfnReserved4_Handler;
  void* pfnSVC_Handler;
  void* pfnDebugMon_Handler;
  void* pfnReserved5_Handler;
  void* pfnPendSV_Handler;
  void* pfnSysTick_Handler;

  /* Peripheral handlers */
  void* pfnSUPC_Handler; /*  0 Supply Controller */
  void* pfnRSTC_Handler; /*  1 Reset Controller */
  void* pfnRTC_Handler; /*  2 Real Time Clock */
  void* pfnRTT_Handler; /*  3 Real Time Timer */
  void* pfnWDT_Handler; /*  4 Watchdog Timer */
  void* pfnPMC_Handler; /*  5 Power Management Controller */
  void* pfnEFC0_Handler; /*  6 Enhanced Flash Controller 0 */
  void* pfnEFC1_Handler; /*  7 Enhanced Flash Controller 1 */
  void* pfnUART_Handler; /*  8 Universal Asynchronous Receiver Transceiver */
  void* pfnSMC_Handler; /*  9 Static Memory Controller */
  void* pvReserved10;
  void* pfnPIOA_Handler; /* 11 Parallel I/O Controller A, */
  void* pfnPIOB_Handler; /* 12 Parallel I/O Controller B */
  void* pfnPIOC_Handler; /* 13 Parallel I/O Controller C */
  void* pfnPIOD_Handler; /* 14 Parallel I/O Controller D */
  void* pvReserved15;
  void* pvReserved16;
  void* pfnUSART0_Handler; /* 17 USART 0 */
  void* pfnUSART1_Handler; /* 18 USART 1 */
  void* pfnUSART2_Handler; /* 19 USART 2 */
  void* pfnUSART3_Handler; /* 20 USART 3 */
  void* pfnHSMCI_Handler; /* 21 Multimedia Card Interface */
  void* pfnTWI0_Handler; /* 22 Two-Wire Interface 0 */
  void* pfnTWI1_Handler; /* 23 Two-Wire Interface 1 */
  void* pfnSPI0_Handler; /* 24 Serial Peripheral Interface */
  void* pvReserved25;
  void* pfnSSC_Handler; /* 26 Synchronous Serial Controller */
  void* pfnTC0_Handler; /* 27 Timer Counter 0 */
  void* pfnTC1_Handler; /* 28 Timer Counter 1 */
  void* pfnTC2_Handler; /* 29 Timer Counter 2 */
  void* pfnTC3_Handler; /* 30 Timer Counter 3 */
  void* pfnTC4_Handler; /* 31 Timer Counter 4 */
  void* pfnTC5_Handler; /* 32 Timer Counter 5 */
  void* pfnTC6_Handler; /* 33 Timer Counter 6 */
  void* pfnTC7_Handler; /* 34 Timer Counter 7 */
  void* pfnTC8_Handler; /* 35 Timer Counter 8 */
  void* pfnPWM_Handler; /* 36 Pulse Width Modulation Controller */
  void* pfnADC_Handler; /* 37 ADC Controller */
  void* pfnDACC_Handler; /* 38 DAC Controller */
  void* pfnDMAC_Handler; /* 39 DMA Controller */
  void* pfnUOTGHS_Handler; /* 40 USB OTG High Speed */
  void* pfnTRNG_Handler; /* 41 True Random Number Generator */
  void* pfnEMAC_Handler; /* 42 Ethernet MAC */
  void* pfnCAN0_Handler; /* 43 CAN Controller 0 */
  void* pfnCAN1_Handler; /* 44 CAN Controller 1 */
} DeviceVectors;

/* Cortex-M3 core handlers */
void Reset_Handler ( void );
void NMI_Handler ( void );
void HardFault_Handler ( void );
void MemManage_Handler ( void );
void BusFault_Handler ( void );
void UsageFault_Handler ( void );
void SVC_Handler ( void );
void DebugMon_Handler ( void );
void PendSV_Handler ( void );
void SysTick_Handler ( void );

/* Peripherals handlers */
void ADC_Handler ( void );
void CAN0_Handler ( void );
void CAN1_Handler ( void );
void DACC_Handler ( void );
void DMAC_Handler ( void );
void EFC0_Handler ( void );
void EFC1_Handler ( void );
void EMAC_Handler ( void );
void HSMCI_Handler ( void );
void PIOA_Handler ( void );
void PIOB_Handler ( void );
void PIOC_Handler ( void );
void PIOD_Handler ( void );
void PMC_Handler ( void );
void PWM_Handler ( void );
void RSTC_Handler ( void );
void RTC_Handler ( void );
void RTT_Handler ( void );
void SMC_Handler ( void );
void SPI0_Handler ( void );
void SSC_Handler ( void );
void SUPC_Handler ( void );
void TC0_Handler ( void );
void TC1_Handler ( void );
void TC2_Handler ( void );
void TC3_Handler ( void );
void TC4_Handler ( void );
void TC5_Handler ( void );
void TC6_Handler ( void );
void TC7_Handler ( void );
void TC8_Handler ( void );
void TRNG_Handler ( void );
void TWI0_Handler ( void );
void TWI1_Handler ( void );
void UART_Handler ( void );
void UOTGHS_Handler ( void );
void USART0_Handler ( void );
void USART1_Handler ( void );
void USART2_Handler ( void );
void USART3_Handler ( void );
void WDT_Handler ( void );

/**
 * \brief Configuration of the Cortex-M3 Processor and Core Peripherals
 */






/*
 * \brief CMSIS includes
 */

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h" 1
/**************************************************************************//**
 * @file     core_cm3.h
 * @brief    CMSIS Cortex-M3 Core Peripheral Access Layer Header File
 * @version  V2.11
 * @date     08. September 2011
 *
 * @note
 * Copyright (C) 2009-2011 ARM Limited. All rights reserved.
 *
 * @par
 * ARM Limited (ARM) is supplying this software for use with Cortex-M
 * processor based microcontrollers.  This file can be freely distributed
 * within development tools that are supporting such ARM based processors.
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/





 extern "C" {






/** \mainpage CMSIS Cortex-M3

  This documentation describes the CMSIS Cortex-M Core Peripheral Access Layer.
  It consists of:

     - Cortex-M Core Register Definitions
     - Cortex-M functions
     - Cortex-M instructions

  The CMSIS Cortex-M3 Core Peripheral Access Layer contains C and assembly functions that ease
  access to the Cortex-M Core
 */

/** \defgroup CMSIS_MISRA_Exceptions  CMSIS MISRA-C:2004 Compliance Exceptions
  CMSIS violates following MISRA-C2004 Rules:
  
   - Violates MISRA 2004 Required Rule 8.5, object/function definition in header file.<br>
     Function definitions in header files are used to allow 'inlining'. 

   - Violates MISRA 2004 Required Rule 18.4, declaration of union type or object of union type: '{...}'.<br>
     Unions are used for effective representation of core registers.
   
   - Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.<br>
     Function-like macros are used to allow more efficient code. 

 */


/*******************************************************************************
 *                 CMSIS definitions
 ******************************************************************************/
/** \defgroup CMSIS_core_definitions CMSIS Core Definitions
  This file defines all structures and symbols for CMSIS core:
   - CMSIS version number
   - Cortex-M core
   - Cortex-M core Revision Number
  @{
 */

/*  CMSIS CM3 definitions */
# 122 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cmInstr.h" 1
/**************************************************************************//**
 * @file     core_cmInstr.h
 * @brief    CMSIS Cortex-M Core Instruction Access Header File
 * @version  V2.10
 * @date     19. July 2011
 *
 * @note
 * Copyright (C) 2009-2011 ARM Limited. All rights reserved.
 *
 * @par
 * ARM Limited (ARM) is supplying this software for use with Cortex-M 
 * processor based microcontrollers.  This file can be freely distributed 
 * within development tools that are supporting such ARM based processors. 
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/





/* ##########################  Core Instruction Access  ######################### */
/** \defgroup CMSIS_Core_InstructionInterface CMSIS Core Instruction Interface
  Access to dedicated instructions
  @{
*/
# 263 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cmInstr.h"
/* GNU gcc specific functions */

/** \brief  No Operation

    No Operation does nothing. This instruction can be used for code alignment purposes.
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ void __NOP(void)
{
  __asm /*!< asm keyword for GNU Compiler          */ volatile ("nop");
}


/** \brief  Wait For Interrupt

    Wait For Interrupt is a hint instruction that suspends execution
    until one of a number of events occurs.
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ void __WFI(void)
{
  __asm /*!< asm keyword for GNU Compiler          */ volatile ("wfi");
}


/** \brief  Wait For Event

    Wait For Event is a hint instruction that permits the processor to enter
    a low-power state until one of a number of events occurs.
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ void __WFE(void)
{
  __asm /*!< asm keyword for GNU Compiler          */ volatile ("wfe");
}


/** \brief  Send Event

    Send Event is a hint instruction. It causes an event to be signaled to the CPU.
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ void __SEV(void)
{
  __asm /*!< asm keyword for GNU Compiler          */ volatile ("sev");
}


/** \brief  Instruction Synchronization Barrier

    Instruction Synchronization Barrier flushes the pipeline in the processor, 
    so that all instructions following the ISB are fetched from cache or 
    memory, after the instruction has been completed.
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ void __ISB(void)
{
  __asm /*!< asm keyword for GNU Compiler          */ volatile ("isb");
}


/** \brief  Data Synchronization Barrier

    This function acts as a special kind of Data Memory Barrier. 
    It completes when all explicit memory accesses before this instruction complete.
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ void __DSB(void)
{
  __asm /*!< asm keyword for GNU Compiler          */ volatile ("dsb");
}


/** \brief  Data Memory Barrier

    This function ensures the apparent order of the explicit memory operations before 
    and after the instruction, without ensuring their completion.
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ void __DMB(void)
{
  __asm /*!< asm keyword for GNU Compiler          */ volatile ("dmb");
}


/** \brief  Reverse byte order (32 bit)

    This function reverses the byte order in integer value.

    \param [in]    value  Value to reverse
    \return               Reversed value
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ uint32_t __REV(uint32_t value)
{
  uint32_t result;

  __asm /*!< asm keyword for GNU Compiler          */ volatile ("rev %0, %1" : "=r" (result) : "r" (value) );
  return(result);
}


/** \brief  Reverse byte order (16 bit)

    This function reverses the byte order in two unsigned short values.

    \param [in]    value  Value to reverse
    \return               Reversed value
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ uint32_t __REV16(uint32_t value)
{
  uint32_t result;

  __asm /*!< asm keyword for GNU Compiler          */ volatile ("rev16 %0, %1" : "=r" (result) : "r" (value) );
  return(result);
}


/** \brief  Reverse byte order in signed short value

    This function reverses the byte order in a signed short value with sign extension to integer.

    \param [in]    value  Value to reverse
    \return               Reversed value
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ int32_t __REVSH(int32_t value)
{
  uint32_t result;

  __asm /*!< asm keyword for GNU Compiler          */ volatile ("revsh %0, %1" : "=r" (result) : "r" (value) );
  return(result);
}




/** \brief  Reverse bit order of value

    This function reverses the bit order of the given value.

    \param [in]    value  Value to reverse
    \return               Reversed value
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ uint32_t __RBIT(uint32_t value)
{
  uint32_t result;

   __asm /*!< asm keyword for GNU Compiler          */ volatile ("rbit %0, %1" : "=r" (result) : "r" (value) );
   return(result);
}


/** \brief  LDR Exclusive (8 bit)

    This function performs a exclusive LDR command for 8 bit value.

    \param [in]    ptr  Pointer to data
    \return             value of type uint8_t at (*ptr)
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ uint8_t __LDREXB(volatile uint8_t *addr)
{
    uint8_t result;

   __asm /*!< asm keyword for GNU Compiler          */ volatile ("ldrexb %0, [%1]" : "=r" (result) : "r" (addr) );
   return(result);
}


/** \brief  LDR Exclusive (16 bit)

    This function performs a exclusive LDR command for 16 bit values.

    \param [in]    ptr  Pointer to data
    \return        value of type uint16_t at (*ptr)
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ uint16_t __LDREXH(volatile uint16_t *addr)
{
    uint16_t result;

   __asm /*!< asm keyword for GNU Compiler          */ volatile ("ldrexh %0, [%1]" : "=r" (result) : "r" (addr) );
   return(result);
}


/** \brief  LDR Exclusive (32 bit)

    This function performs a exclusive LDR command for 32 bit values.

    \param [in]    ptr  Pointer to data
    \return        value of type uint32_t at (*ptr)
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ uint32_t __LDREXW(volatile uint32_t *addr)
{
    uint32_t result;

   __asm /*!< asm keyword for GNU Compiler          */ volatile ("ldrex %0, [%1]" : "=r" (result) : "r" (addr) );
   return(result);
}


/** \brief  STR Exclusive (8 bit)

    This function performs a exclusive STR command for 8 bit values.

    \param [in]  value  Value to store
    \param [in]    ptr  Pointer to location
    \return          0  Function succeeded
    \return          1  Function failed
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ uint32_t __STREXB(uint8_t value, volatile uint8_t *addr)
{
   uint32_t result;

   __asm /*!< asm keyword for GNU Compiler          */ volatile ("strexb %0, %2, [%1]" : "=r" (result) : "r" (addr), "r" (value) );
   return(result);
}


/** \brief  STR Exclusive (16 bit)

    This function performs a exclusive STR command for 16 bit values.

    \param [in]  value  Value to store
    \param [in]    ptr  Pointer to location
    \return          0  Function succeeded
    \return          1  Function failed
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ uint32_t __STREXH(uint16_t value, volatile uint16_t *addr)
{
   uint32_t result;

   __asm /*!< asm keyword for GNU Compiler          */ volatile ("strexh %0, %2, [%1]" : "=r" (result) : "r" (addr), "r" (value) );
   return(result);
}


/** \brief  STR Exclusive (32 bit)

    This function performs a exclusive STR command for 32 bit values.

    \param [in]  value  Value to store
    \param [in]    ptr  Pointer to location
    \return          0  Function succeeded
    \return          1  Function failed
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ uint32_t __STREXW(uint32_t value, volatile uint32_t *addr)
{
   uint32_t result;

   __asm /*!< asm keyword for GNU Compiler          */ volatile ("strex %0, %2, [%1]" : "=r" (result) : "r" (addr), "r" (value) );
   return(result);
}


/** \brief  Remove the exclusive lock

    This function removes the exclusive lock which is created by LDREX.

 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ void __CLREX(void)
{
  __asm /*!< asm keyword for GNU Compiler          */ volatile ("clrex");
}


/** \brief  Signed Saturate

    This function saturates a signed value.

    \param [in]  value  Value to be saturated
    \param [in]    sat  Bit position to saturate to (1..32)
    \return             Saturated value
 */
# 536 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cmInstr.h"
/** \brief  Unsigned Saturate

    This function saturates an unsigned value.

    \param [in]  value  Value to be saturated
    \param [in]    sat  Bit position to saturate to (0..31)
    \return             Saturated value
 */
# 552 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cmInstr.h"
/** \brief  Count leading zeros

    This function counts the number of leading zeros of a data value.

    \param [in]  value  Value to count the leading zeros
    \return             number of leading zeros in value
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ uint8_t __CLZ(uint32_t value)
{
  uint8_t result;

  __asm /*!< asm keyword for GNU Compiler          */ volatile ("clz %0, %1" : "=r" (result) : "r" (value) );
  return(result);
}
# 583 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cmInstr.h"
/*@}*/ /* end of group CMSIS_Core_InstructionInterface */
# 123 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cmFunc.h" 1
/**************************************************************************//**
 * @file     core_cmFunc.h
 * @brief    CMSIS Cortex-M Core Function Access Header File
 * @version  V2.10
 * @date     26. July 2011
 *
 * @note
 * Copyright (C) 2009-2011 ARM Limited. All rights reserved.
 *
 * @par
 * ARM Limited (ARM) is supplying this software for use with Cortex-M 
 * processor based microcontrollers.  This file can be freely distributed 
 * within development tools that are supporting such ARM based processors. 
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/





/* ###########################  Core Function Access  ########################### */
/** \ingroup  CMSIS_Core_FunctionInterface   
    \defgroup CMSIS_Core_RegAccFunctions CMSIS Core Register Access Functions
  @{
 */
# 301 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cmFunc.h"
/* GNU gcc specific functions */

/** \brief  Enable IRQ Interrupts

  This function enables IRQ interrupts by clearing the I-bit in the CPSR.
  Can only be executed in Privileged modes.
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ void __enable_irq(void)
{
  __asm /*!< asm keyword for GNU Compiler          */ volatile ("cpsie i");
}


/** \brief  Disable IRQ Interrupts

  This function disables IRQ interrupts by setting the I-bit in the CPSR.
  Can only be executed in Privileged modes.
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ void __disable_irq(void)
{
  __asm /*!< asm keyword for GNU Compiler          */ volatile ("cpsid i");
}


/** \brief  Get Control Register

    This function returns the content of the Control Register.

    \return               Control Register value
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ uint32_t __get_CONTROL(void)
{
  uint32_t result;

  __asm /*!< asm keyword for GNU Compiler          */ volatile ("MRS %0, control" : "=r" (result) );
  return(result);
}


/** \brief  Set Control Register

    This function writes the given value to the Control Register.

    \param [in]    control  Control Register value to set
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ void __set_CONTROL(uint32_t control)
{
  __asm /*!< asm keyword for GNU Compiler          */ volatile ("MSR control, %0" : : "r" (control) );
}


/** \brief  Get ISPR Register

    This function returns the content of the ISPR Register.

    \return               ISPR Register value
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ uint32_t __get_IPSR(void)
{
  uint32_t result;

  __asm /*!< asm keyword for GNU Compiler          */ volatile ("MRS %0, ipsr" : "=r" (result) );
  return(result);
}


/** \brief  Get APSR Register

    This function returns the content of the APSR Register.

    \return               APSR Register value
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ uint32_t __get_APSR(void)
{
  uint32_t result;

  __asm /*!< asm keyword for GNU Compiler          */ volatile ("MRS %0, apsr" : "=r" (result) );
  return(result);
}


/** \brief  Get xPSR Register

    This function returns the content of the xPSR Register.

    \return               xPSR Register value
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ uint32_t __get_xPSR(void)
{
  uint32_t result;

  __asm /*!< asm keyword for GNU Compiler          */ volatile ("MRS %0, xpsr" : "=r" (result) );
  return(result);
}


/** \brief  Get Process Stack Pointer

    This function returns the current value of the Process Stack Pointer (PSP).

    \return               PSP Register value
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ uint32_t __get_PSP(void)
{
  register uint32_t result;

  __asm /*!< asm keyword for GNU Compiler          */ volatile ("MRS %0, psp\n" : "=r" (result) );
  return(result);
}


/** \brief  Set Process Stack Pointer

    This function assigns the given value to the Process Stack Pointer (PSP).

    \param [in]    topOfProcStack  Process Stack Pointer value to set
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ void __set_PSP(uint32_t topOfProcStack)
{
  __asm /*!< asm keyword for GNU Compiler          */ volatile ("MSR psp, %0\n" : : "r" (topOfProcStack) );
}


/** \brief  Get Main Stack Pointer

    This function returns the current value of the Main Stack Pointer (MSP).

    \return               MSP Register value
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ uint32_t __get_MSP(void)
{
  register uint32_t result;

  __asm /*!< asm keyword for GNU Compiler          */ volatile ("MRS %0, msp\n" : "=r" (result) );
  return(result);
}


/** \brief  Set Main Stack Pointer

    This function assigns the given value to the Main Stack Pointer (MSP).

    \param [in]    topOfMainStack  Main Stack Pointer value to set
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ void __set_MSP(uint32_t topOfMainStack)
{
  __asm /*!< asm keyword for GNU Compiler          */ volatile ("MSR msp, %0\n" : : "r" (topOfMainStack) );
}


/** \brief  Get Priority Mask

    This function returns the current state of the priority mask bit from the Priority Mask Register.

    \return               Priority Mask value
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ uint32_t __get_PRIMASK(void)
{
  uint32_t result;

  __asm /*!< asm keyword for GNU Compiler          */ volatile ("MRS %0, primask" : "=r" (result) );
  return(result);
}


/** \brief  Set Priority Mask

    This function assigns the given value to the Priority Mask Register.

    \param [in]    priMask  Priority Mask
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ void __set_PRIMASK(uint32_t priMask)
{
  __asm /*!< asm keyword for GNU Compiler          */ volatile ("MSR primask, %0" : : "r" (priMask) );
}




/** \brief  Enable FIQ

    This function enables FIQ interrupts by clearing the F-bit in the CPSR.
    Can only be executed in Privileged modes.
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ void __enable_fault_irq(void)
{
  __asm /*!< asm keyword for GNU Compiler          */ volatile ("cpsie f");
}


/** \brief  Disable FIQ

    This function disables FIQ interrupts by setting the F-bit in the CPSR.
    Can only be executed in Privileged modes.
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ void __disable_fault_irq(void)
{
  __asm /*!< asm keyword for GNU Compiler          */ volatile ("cpsid f");
}


/** \brief  Get Base Priority

    This function returns the current value of the Base Priority register.

    \return               Base Priority register value
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ uint32_t __get_BASEPRI(void)
{
  uint32_t result;

  __asm /*!< asm keyword for GNU Compiler          */ volatile ("MRS %0, basepri_max" : "=r" (result) );
  return(result);
}


/** \brief  Set Base Priority

    This function assigns the given value to the Base Priority register.

    \param [in]    basePri  Base Priority value to set
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ void __set_BASEPRI(uint32_t value)
{
  __asm /*!< asm keyword for GNU Compiler          */ volatile ("MSR basepri, %0" : : "r" (value) );
}


/** \brief  Get Fault Mask

    This function returns the current value of the Fault Mask register.

    \return               Fault Mask register value
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ uint32_t __get_FAULTMASK(void)
{
  uint32_t result;

  __asm /*!< asm keyword for GNU Compiler          */ volatile ("MRS %0, faultmask" : "=r" (result) );
  return(result);
}


/** \brief  Set Fault Mask

    This function assigns the given value to the Fault Mask register.

    \param [in]    faultMask  Fault Mask value to set
 */
__attribute__( ( always_inline ) ) static inline /*!< inline keyword for GNU Compiler       */ void __set_FAULTMASK(uint32_t faultMask)
{
  __asm /*!< asm keyword for GNU Compiler          */ volatile ("MSR faultmask, %0" : : "r" (faultMask) );
}
# 606 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cmFunc.h"
/*@} end of CMSIS_Core_RegAccFunctions */
# 124 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h" 2
# 132 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
/* check device defines and use defaults */
# 155 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
/* IO definitions (access restrictions to peripheral registers) */
# 164 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
/*@} end of group CMSIS_core_definitions */



/*******************************************************************************
 *                 Register Abstraction
 ******************************************************************************/
/** \defgroup CMSIS_core_register CMSIS Core Register
  Core Register contain:
  - Core Register
  - Core NVIC Register
  - Core SCB Register
  - Core SysTick Register
  - Core Debug Register
  - Core MPU Register
*/

/** \ingroup  CMSIS_core_register
    \defgroup CMSIS_CORE CMSIS Core
  Type definitions for the Cortex-M Core Registers
  @{
 */

/** \brief  Union type to access the Application Program Status Register (APSR).
 */
typedef union
{
  struct
  {

    uint32_t _reserved0:27; /*!< bit:  0..26  Reserved                           */





    uint32_t Q:1; /*!< bit:     27  Saturation condition flag          */
    uint32_t V:1; /*!< bit:     28  Overflow condition code flag       */
    uint32_t C:1; /*!< bit:     29  Carry condition code flag          */
    uint32_t Z:1; /*!< bit:     30  Zero condition code flag           */
    uint32_t N:1; /*!< bit:     31  Negative condition code flag       */
  } b; /*!< Structure used for bit  access                  */
  uint32_t w; /*!< Type      used for word access                  */
} APSR_Type;


/** \brief  Union type to access the Interrupt Program Status Register (IPSR).
 */
typedef union
{
  struct
  {
    uint32_t ISR:9; /*!< bit:  0.. 8  Exception number                   */
    uint32_t _reserved0:23; /*!< bit:  9..31  Reserved                           */
  } b; /*!< Structure used for bit  access                  */
  uint32_t w; /*!< Type      used for word access                  */
} IPSR_Type;


/** \brief  Union type to access the Special-Purpose Program Status Registers (xPSR).
 */
typedef union
{
  struct
  {
    uint32_t ISR:9; /*!< bit:  0.. 8  Exception number                   */

    uint32_t _reserved0:15; /*!< bit:  9..23  Reserved                           */





    uint32_t T:1; /*!< bit:     24  Thumb bit        (read 0)          */
    uint32_t IT:2; /*!< bit: 25..26  saved IT state   (read 0)          */
    uint32_t Q:1; /*!< bit:     27  Saturation condition flag          */
    uint32_t V:1; /*!< bit:     28  Overflow condition code flag       */
    uint32_t C:1; /*!< bit:     29  Carry condition code flag          */
    uint32_t Z:1; /*!< bit:     30  Zero condition code flag           */
    uint32_t N:1; /*!< bit:     31  Negative condition code flag       */
  } b; /*!< Structure used for bit  access                  */
  uint32_t w; /*!< Type      used for word access                  */
} xPSR_Type;


/** \brief  Union type to access the Control Registers (CONTROL).
 */
typedef union
{
  struct
  {
    uint32_t nPRIV:1; /*!< bit:      0  Execution privilege in Thread mode */
    uint32_t SPSEL:1; /*!< bit:      1  Stack to be used                   */
    uint32_t FPCA:1; /*!< bit:      2  FP extension active flag           */
    uint32_t _reserved0:29; /*!< bit:  3..31  Reserved                           */
  } b; /*!< Structure used for bit  access                  */
  uint32_t w; /*!< Type      used for word access                  */
} CONTROL_Type;

/*@} end of group CMSIS_CORE */


/** \ingroup  CMSIS_core_register
    \defgroup CMSIS_NVIC CMSIS NVIC
  Type definitions for the Cortex-M NVIC Registers
  @{
 */

/** \brief  Structure type to access the Nested Vectored Interrupt Controller (NVIC).
 */
typedef struct
{
  volatile /*!< defines 'read / write' permissions              */ uint32_t ISER[8]; /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register           */
       uint32_t RESERVED0[24];
  volatile /*!< defines 'read / write' permissions              */ uint32_t ICER[8]; /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register         */
       uint32_t RSERVED1[24];
  volatile /*!< defines 'read / write' permissions              */ uint32_t ISPR[8]; /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register          */
       uint32_t RESERVED2[24];
  volatile /*!< defines 'read / write' permissions              */ uint32_t ICPR[8]; /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register        */
       uint32_t RESERVED3[24];
  volatile /*!< defines 'read / write' permissions              */ uint32_t IABR[8]; /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register           */
       uint32_t RESERVED4[56];
  volatile /*!< defines 'read / write' permissions              */ uint8_t IP[240]; /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
       uint32_t RESERVED5[644];
  volatile /*!< defines 'write only' permissions                */ uint32_t STIR; /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register     */
} NVIC_Type;

/* Software Triggered Interrupt Register Definitions */



/*@} end of group CMSIS_NVIC */


/** \ingroup  CMSIS_core_register
    \defgroup CMSIS_SCB CMSIS SCB
  Type definitions for the Cortex-M System Control Block Registers
  @{
 */

/** \brief  Structure type to access the System Control Block (SCB).
 */
typedef struct
{
  volatile /*!< defines 'read only' permissions                 */ uint32_t CPUID; /*!< Offset: 0x000 (R/ )  CPUID Base Register                                   */
  volatile /*!< defines 'read / write' permissions              */ uint32_t ICSR; /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register                  */
  volatile /*!< defines 'read / write' permissions              */ uint32_t VTOR; /*!< Offset: 0x008 (R/W)  Vector Table Offset Register                          */
  volatile /*!< defines 'read / write' permissions              */ uint32_t AIRCR; /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register      */
  volatile /*!< defines 'read / write' permissions              */ uint32_t SCR; /*!< Offset: 0x010 (R/W)  System Control Register                               */
  volatile /*!< defines 'read / write' permissions              */ uint32_t CCR; /*!< Offset: 0x014 (R/W)  Configuration Control Register                        */
  volatile /*!< defines 'read / write' permissions              */ uint8_t SHP[12]; /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) */
  volatile /*!< defines 'read / write' permissions              */ uint32_t SHCSR; /*!< Offset: 0x024 (R/W)  System Handler Control and State Register             */
  volatile /*!< defines 'read / write' permissions              */ uint32_t CFSR; /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register                    */
  volatile /*!< defines 'read / write' permissions              */ uint32_t HFSR; /*!< Offset: 0x02C (R/W)  HardFault Status Register                             */
  volatile /*!< defines 'read / write' permissions              */ uint32_t DFSR; /*!< Offset: 0x030 (R/W)  Debug Fault Status Register                           */
  volatile /*!< defines 'read / write' permissions              */ uint32_t MMFAR; /*!< Offset: 0x034 (R/W)  MemManage Fault Address Register                      */
  volatile /*!< defines 'read / write' permissions              */ uint32_t BFAR; /*!< Offset: 0x038 (R/W)  BusFault Address Register                             */
  volatile /*!< defines 'read / write' permissions              */ uint32_t AFSR; /*!< Offset: 0x03C (R/W)  Auxiliary Fault Status Register                       */
  volatile /*!< defines 'read only' permissions                 */ uint32_t PFR[2]; /*!< Offset: 0x040 (R/ )  Processor Feature Register                            */
  volatile /*!< defines 'read only' permissions                 */ uint32_t DFR; /*!< Offset: 0x048 (R/ )  Debug Feature Register                                */
  volatile /*!< defines 'read only' permissions                 */ uint32_t ADR; /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register                            */
  volatile /*!< defines 'read only' permissions                 */ uint32_t MMFR[4]; /*!< Offset: 0x050 (R/ )  Memory Model Feature Register                         */
  volatile /*!< defines 'read only' permissions                 */ uint32_t ISAR[5]; /*!< Offset: 0x060 (R/ )  Instruction Set Attributes Register                   */
       uint32_t RESERVED0[5];
  volatile /*!< defines 'read / write' permissions              */ uint32_t CPACR; /*!< Offset: 0x088 (R/W)  Coprocessor Access Control Register                   */
} SCB_Type;

/* SCB CPUID Register Definitions */
# 347 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
/* SCB Interrupt Control State Register Definitions */
# 378 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
/* SCB Vector Table Offset Register Definitions */
# 390 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
/* SCB Application Interrupt and Reset Control Register Definitions */
# 412 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
/* SCB System Control Register Definitions */
# 422 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
/* SCB Configuration Control Register Definitions */
# 441 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
/* SCB System Handler Control and State Register Definitions */
# 484 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
/* SCB Configurable Fault Status Registers Definitions */
# 494 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
/* SCB Hard Fault Status Registers Definitions */
# 504 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
/* SCB Debug Fault Status Register Definitions */
# 520 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
/*@} end of group CMSIS_SCB */


/** \ingroup  CMSIS_core_register
    \defgroup CMSIS_SCnSCB CMSIS System Control and ID Register not in the SCB
  Type definitions for the Cortex-M System Control and ID Register not in the SCB
  @{
 */

/** \brief  Structure type to access the System Control and ID Register not in the SCB.
 */
typedef struct
{
       uint32_t RESERVED0[1];
  volatile /*!< defines 'read only' permissions                 */ uint32_t ICTR; /*!< Offset: 0x004 (R/ )  Interrupt Controller Type Register      */

  volatile /*!< defines 'read / write' permissions              */ uint32_t ACTLR; /*!< Offset: 0x008 (R/W)  Auxiliary Control Register      */



} SCnSCB_Type;

/* Interrupt Controller Type Register Definitions */



/* Auxiliary Control Register Definitions */
# 557 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
/*@} end of group CMSIS_SCnotSCB */


/** \ingroup  CMSIS_core_register
    \defgroup CMSIS_SysTick CMSIS SysTick
  Type definitions for the Cortex-M System Timer Registers
  @{
 */

/** \brief  Structure type to access the System Timer (SysTick).
 */
typedef struct
{
  volatile /*!< defines 'read / write' permissions              */ uint32_t CTRL; /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
  volatile /*!< defines 'read / write' permissions              */ uint32_t LOAD; /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register       */
  volatile /*!< defines 'read / write' permissions              */ uint32_t VAL; /*!< Offset: 0x008 (R/W)  SysTick Current Value Register      */
  volatile /*!< defines 'read only' permissions                 */ uint32_t CALIB; /*!< Offset: 0x00C (R/ )  SysTick Calibration Register        */
} SysTick_Type;

/* SysTick Control / Status Register Definitions */
# 589 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
/* SysTick Reload Register Definitions */



/* SysTick Current Register Definitions */



/* SysTick Calibration Register Definitions */
# 607 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
/*@} end of group CMSIS_SysTick */


/** \ingroup  CMSIS_core_register
    \defgroup CMSIS_ITM CMSIS ITM
  Type definitions for the Cortex-M Instrumentation Trace Macrocell (ITM)
  @{
 */

/** \brief  Structure type to access the Instrumentation Trace Macrocell Register (ITM).
 */
typedef struct
{
  volatile /*!< defines 'write only' permissions                */ union
  {
    volatile /*!< defines 'write only' permissions                */ uint8_t u8; /*!< Offset: 0x000 ( /W)  ITM Stimulus Port 8-bit                   */
    volatile /*!< defines 'write only' permissions                */ uint16_t u16; /*!< Offset: 0x000 ( /W)  ITM Stimulus Port 16-bit                  */
    volatile /*!< defines 'write only' permissions                */ uint32_t u32; /*!< Offset: 0x000 ( /W)  ITM Stimulus Port 32-bit                  */
  } PORT [32]; /*!< Offset: 0x000 ( /W)  ITM Stimulus Port Registers               */
       uint32_t RESERVED0[864];
  volatile /*!< defines 'read / write' permissions              */ uint32_t TER; /*!< Offset: 0xE00 (R/W)  ITM Trace Enable Register                 */
       uint32_t RESERVED1[15];
  volatile /*!< defines 'read / write' permissions              */ uint32_t TPR; /*!< Offset: 0xE40 (R/W)  ITM Trace Privilege Register              */
       uint32_t RESERVED2[15];
  volatile /*!< defines 'read / write' permissions              */ uint32_t TCR; /*!< Offset: 0xE80 (R/W)  ITM Trace Control Register                */
} ITM_Type;

/* ITM Trace Privilege Register Definitions */



/* ITM Trace Control Register Definitions */
# 666 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
/*@}*/ /* end of group CMSIS_ITM */



/** \ingroup  CMSIS_core_register
    \defgroup CMSIS_MPU CMSIS MPU
  Type definitions for the Cortex-M Memory Protection Unit (MPU)
  @{
 */

/** \brief  Structure type to access the Memory Protection Unit (MPU).
 */
typedef struct
{
  volatile /*!< defines 'read only' permissions                 */ uint32_t TYPE; /*!< Offset: 0x000 (R/ )  MPU Type Register                              */
  volatile /*!< defines 'read / write' permissions              */ uint32_t CTRL; /*!< Offset: 0x004 (R/W)  MPU Control Register                           */
  volatile /*!< defines 'read / write' permissions              */ uint32_t RNR; /*!< Offset: 0x008 (R/W)  MPU Region RNRber Register                     */
  volatile /*!< defines 'read / write' permissions              */ uint32_t RBAR; /*!< Offset: 0x00C (R/W)  MPU Region Base Address Register               */
  volatile /*!< defines 'read / write' permissions              */ uint32_t RASR; /*!< Offset: 0x010 (R/W)  MPU Region Attribute and Size Register         */
  volatile /*!< defines 'read / write' permissions              */ uint32_t RBAR_A1; /*!< Offset: 0x014 (R/W)  MPU Alias 1 Region Base Address Register       */
  volatile /*!< defines 'read / write' permissions              */ uint32_t RASR_A1; /*!< Offset: 0x018 (R/W)  MPU Alias 1 Region Attribute and Size Register */
  volatile /*!< defines 'read / write' permissions              */ uint32_t RBAR_A2; /*!< Offset: 0x01C (R/W)  MPU Alias 2 Region Base Address Register       */
  volatile /*!< defines 'read / write' permissions              */ uint32_t RASR_A2; /*!< Offset: 0x020 (R/W)  MPU Alias 2 Region Attribute and Size Register */
  volatile /*!< defines 'read / write' permissions              */ uint32_t RBAR_A3; /*!< Offset: 0x024 (R/W)  MPU Alias 3 Region Base Address Register       */
  volatile /*!< defines 'read / write' permissions              */ uint32_t RASR_A3; /*!< Offset: 0x028 (R/W)  MPU Alias 3 Region Attribute and Size Register */
} MPU_Type;

/* MPU Type Register */
# 703 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
/* MPU Control Register */
# 713 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
/* MPU Region Number Register */



/* MPU Region Base Address Register */
# 727 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
/* MPU Region Attribute and Size Register */
# 740 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
/*@} end of group CMSIS_MPU */



/** \ingroup  CMSIS_core_register
    \defgroup CMSIS_CoreDebug CMSIS Core Debug
  Type definitions for the Cortex-M Core Debug Registers
  @{
 */

/** \brief  Structure type to access the Core Debug Register (CoreDebug).
 */
typedef struct
{
  volatile /*!< defines 'read / write' permissions              */ uint32_t DHCSR; /*!< Offset: 0x000 (R/W)  Debug Halting Control and Status Register    */
  volatile /*!< defines 'write only' permissions                */ uint32_t DCRSR; /*!< Offset: 0x004 ( /W)  Debug Core Register Selector Register        */
  volatile /*!< defines 'read / write' permissions              */ uint32_t DCRDR; /*!< Offset: 0x008 (R/W)  Debug Core Register Data Register            */
  volatile /*!< defines 'read / write' permissions              */ uint32_t DEMCR; /*!< Offset: 0x00C (R/W)  Debug Exception and Monitor Control Register */
} CoreDebug_Type;

/* Debug Halting Control and Status Register */
# 797 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
/* Debug Core Register Selector Register */






/* Debug Exception and Monitor Control Register */
# 844 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
/*@} end of group CMSIS_CoreDebug */


/** \ingroup  CMSIS_core_register
  @{
 */

/* Memory mapping of Cortex-M3 Hardware */
# 871 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/CMSIS/Include/core_cm3.h"
/*@} */



/*******************************************************************************
 *                Hardware Abstraction Layer
 ******************************************************************************/
/** \defgroup CMSIS_Core_FunctionInterface CMSIS Core Function Interface
  Core Function Interface contains:
  - Core NVIC Functions
  - Core SysTick Functions
  - Core Debug Functions
  - Core Register Access Functions
*/



/* ##########################   NVIC functions  #################################### */
/** \ingroup  CMSIS_Core_FunctionInterface
    \defgroup CMSIS_Core_NVICFunctions CMSIS Core NVIC Functions
  @{
 */

/** \brief  Set Priority Grouping

  This function sets the priority grouping field using the required unlock sequence.
  The parameter PriorityGroup is assigned to the field SCB->AIRCR [10:8] PRIGROUP field.
  Only values from 0..7 are used.
  In case of a conflict between priority grouping and available
  priority bits (__NVIC_PRIO_BITS) the smallest possible priority group is set.

    \param [in]      PriorityGroup  Priority grouping field
 */
static inline /*!< inline keyword for GNU Compiler       */ void NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  uint32_t reg_value;
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07); /* only values 0..7 are used          */

  reg_value = ((SCB_Type *) ((0xE000E000UL) /*!< System Control Space Base Address  */ + 0x0D00UL) /*!< System Control Block Base Address  */ ) /*!< SCB configuration struct           */->AIRCR; /* read old register configuration    */
  reg_value &= ~((0xFFFFUL << 16 /*!< SCB AIRCR: VECTKEY Position */) /*!< SCB AIRCR: VECTKEY Mask */ | (7UL << 8 /*!< SCB AIRCR: PRIGROUP Position */) /*!< SCB AIRCR: PRIGROUP Mask */); /* clear bits to change               */
  reg_value = (reg_value |
                ((uint32_t)0x5FA << 16 /*!< SCB AIRCR: VECTKEY Position */) |
                (PriorityGroupTmp << 8)); /* Insert write key and priorty group */
  ((SCB_Type *) ((0xE000E000UL) /*!< System Control Space Base Address  */ + 0x0D00UL) /*!< System Control Block Base Address  */ ) /*!< SCB configuration struct           */->AIRCR = reg_value;
}


/** \brief  Get Priority Grouping

  This function gets the priority grouping from NVIC Interrupt Controller.
  Priority grouping is SCB->AIRCR [10:8] PRIGROUP field.

    \return                Priority grouping field
 */
static inline /*!< inline keyword for GNU Compiler       */ uint32_t NVIC_GetPriorityGrouping(void)
{
  return ((((SCB_Type *) ((0xE000E000UL) /*!< System Control Space Base Address  */ + 0x0D00UL) /*!< System Control Block Base Address  */ ) /*!< SCB configuration struct           */->AIRCR & (7UL << 8 /*!< SCB AIRCR: PRIGROUP Position */) /*!< SCB AIRCR: PRIGROUP Mask */) >> 8 /*!< SCB AIRCR: PRIGROUP Position */); /* read priority grouping field */
}


/** \brief  Enable External Interrupt

    This function enables a device specific interrupt in the NVIC interrupt controller.
    The interrupt number cannot be a negative value.

    \param [in]      IRQn  Number of the external interrupt to enable
 */
static inline /*!< inline keyword for GNU Compiler       */ void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) /*!< System Control Space Base Address  */ + 0x0100UL) /*!< NVIC Base Address                  */ ) /*!< NVIC configuration struct          */->ISER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F)); /* enable interrupt */
}


/** \brief  Disable External Interrupt

    This function disables a device specific interrupt in the NVIC interrupt controller.
    The interrupt number cannot be a negative value.

    \param [in]      IRQn  Number of the external interrupt to disable
 */
static inline /*!< inline keyword for GNU Compiler       */ void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) /*!< System Control Space Base Address  */ + 0x0100UL) /*!< NVIC Base Address                  */ ) /*!< NVIC configuration struct          */->ICER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F)); /* disable interrupt */
}


/** \brief  Get Pending Interrupt

    This function reads the pending register in the NVIC and returns the pending bit
    for the specified interrupt.

    \param [in]      IRQn  Number of the interrupt for get pending
    \return             0  Interrupt status is not pending
    \return             1  Interrupt status is pending
 */
static inline /*!< inline keyword for GNU Compiler       */ uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((uint32_t) ((((NVIC_Type *) ((0xE000E000UL) /*!< System Control Space Base Address  */ + 0x0100UL) /*!< NVIC Base Address                  */ ) /*!< NVIC configuration struct          */->ISPR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0)); /* Return 1 if pending else 0 */
}


/** \brief  Set Pending Interrupt

    This function sets the pending bit for the specified interrupt.
    The interrupt number cannot be a negative value.

    \param [in]      IRQn  Number of the interrupt for set pending
 */
static inline /*!< inline keyword for GNU Compiler       */ void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) /*!< System Control Space Base Address  */ + 0x0100UL) /*!< NVIC Base Address                  */ ) /*!< NVIC configuration struct          */->ISPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F)); /* set interrupt pending */
}


/** \brief  Clear Pending Interrupt

    This function clears the pending bit for the specified interrupt.
    The interrupt number cannot be a negative value.

    \param [in]      IRQn  Number of the interrupt for clear pending
 */
static inline /*!< inline keyword for GNU Compiler       */ void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) /*!< System Control Space Base Address  */ + 0x0100UL) /*!< NVIC Base Address                  */ ) /*!< NVIC configuration struct          */->ICPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F)); /* Clear pending interrupt */
}


/** \brief  Get Active Interrupt

    This function reads the active register in NVIC and returns the active bit.
    \param [in]      IRQn  Number of the interrupt for get active
    \return             0  Interrupt status is not active
    \return             1  Interrupt status is active
 */
static inline /*!< inline keyword for GNU Compiler       */ uint32_t NVIC_GetActive(IRQn_Type IRQn)
{
  return((uint32_t)((((NVIC_Type *) ((0xE000E000UL) /*!< System Control Space Base Address  */ + 0x0100UL) /*!< NVIC Base Address                  */ ) /*!< NVIC configuration struct          */->IABR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0)); /* Return 1 if active else 0 */
}


/** \brief  Set Interrupt Priority

    This function sets the priority for the specified interrupt. The interrupt
    number can be positive to specify an external (device specific)
    interrupt, or negative to specify an internal (core) interrupt.

    Note: The priority cannot be set for every core interrupt.

    \param [in]      IRQn  Number of the interrupt for set priority
    \param [in]  priority  Priority to set
 */
static inline /*!< inline keyword for GNU Compiler       */ void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if(IRQn < 0) {
    ((SCB_Type *) ((0xE000E000UL) /*!< System Control Space Base Address  */ + 0x0D00UL) /*!< System Control Block Base Address  */ ) /*!< SCB configuration struct           */->SHP[((uint32_t)(IRQn) & 0xF)-4] = ((priority << (8 - 4 /**< SAM3X8E uses 4 Bits for the Priority Levels */)) & 0xff); } /* set Priority for Cortex-M  System Interrupts */
  else {
    ((NVIC_Type *) ((0xE000E000UL) /*!< System Control Space Base Address  */ + 0x0100UL) /*!< NVIC Base Address                  */ ) /*!< NVIC configuration struct          */->IP[(uint32_t)(IRQn)] = ((priority << (8 - 4 /**< SAM3X8E uses 4 Bits for the Priority Levels */)) & 0xff); } /* set Priority for device specific Interrupts  */
}


/** \brief  Get Interrupt Priority

    This function reads the priority for the specified interrupt. The interrupt
    number can be positive to specify an external (device specific)
    interrupt, or negative to specify an internal (core) interrupt.

    The returned priority value is automatically aligned to the implemented
    priority bits of the microcontroller.

    \param [in]   IRQn  Number of the interrupt for get priority
    \return             Interrupt Priority
 */
static inline /*!< inline keyword for GNU Compiler       */ uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{

  if(IRQn < 0) {
    return((uint32_t)(((SCB_Type *) ((0xE000E000UL) /*!< System Control Space Base Address  */ + 0x0D00UL) /*!< System Control Block Base Address  */ ) /*!< SCB configuration struct           */->SHP[((uint32_t)(IRQn) & 0xF)-4] >> (8 - 4 /**< SAM3X8E uses 4 Bits for the Priority Levels */))); } /* get priority for Cortex-M  system interrupts */
  else {
    return((uint32_t)(((NVIC_Type *) ((0xE000E000UL) /*!< System Control Space Base Address  */ + 0x0100UL) /*!< NVIC Base Address                  */ ) /*!< NVIC configuration struct          */->IP[(uint32_t)(IRQn)] >> (8 - 4 /**< SAM3X8E uses 4 Bits for the Priority Levels */))); } /* get priority for device specific interrupts  */
}


/** \brief  Encode Priority

    This function encodes the priority for an interrupt with the given priority group,
    preemptive priority value and sub priority value.
    In case of a conflict between priority grouping and available
    priority bits (__NVIC_PRIO_BITS) the samllest possible priority group is set.

    The returned priority value can be used for NVIC_SetPriority(...) function

    \param [in]     PriorityGroup  Used priority group
    \param [in]   PreemptPriority  Preemptive priority value (starting from 0)
    \param [in]       SubPriority  Sub priority value (starting from 0)
    \return                        Encoded priority for the interrupt
 */
static inline /*!< inline keyword for GNU Compiler       */ uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07); /* only values 0..7 are used          */
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > 4 /**< SAM3X8E uses 4 Bits for the Priority Levels */) ? 4 /**< SAM3X8E uses 4 Bits for the Priority Levels */ : 7 - PriorityGroupTmp;
  SubPriorityBits = ((PriorityGroupTmp + 4 /**< SAM3X8E uses 4 Bits for the Priority Levels */) < 7) ? 0 : PriorityGroupTmp - 7 + 4 /**< SAM3X8E uses 4 Bits for the Priority Levels */;

  return (
           ((PreemptPriority & ((1 << (PreemptPriorityBits)) - 1)) << SubPriorityBits) |
           ((SubPriority & ((1 << (SubPriorityBits )) - 1)))
         );
}


/** \brief  Decode Priority

    This function decodes an interrupt priority value with the given priority group to
    preemptive priority value and sub priority value.
    In case of a conflict between priority grouping and available
    priority bits (__NVIC_PRIO_BITS) the samllest possible priority group is set.

    The priority value can be retrieved with NVIC_GetPriority(...) function

    \param [in]         Priority   Priority value
    \param [in]     PriorityGroup  Used priority group
    \param [out] pPreemptPriority  Preemptive priority value (starting from 0)
    \param [out]     pSubPriority  Sub priority value (starting from 0)
 */
static inline /*!< inline keyword for GNU Compiler       */ void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* pPreemptPriority, uint32_t* pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07); /* only values 0..7 are used          */
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > 4 /**< SAM3X8E uses 4 Bits for the Priority Levels */) ? 4 /**< SAM3X8E uses 4 Bits for the Priority Levels */ : 7 - PriorityGroupTmp;
  SubPriorityBits = ((PriorityGroupTmp + 4 /**< SAM3X8E uses 4 Bits for the Priority Levels */) < 7) ? 0 : PriorityGroupTmp - 7 + 4 /**< SAM3X8E uses 4 Bits for the Priority Levels */;

  *pPreemptPriority = (Priority >> SubPriorityBits) & ((1 << (PreemptPriorityBits)) - 1);
  *pSubPriority = (Priority ) & ((1 << (SubPriorityBits )) - 1);
}


/** \brief  System Reset

    This function initiate a system reset request to reset the MCU.
 */
static inline /*!< inline keyword for GNU Compiler       */ void NVIC_SystemReset(void)
{
  __DSB(); /* Ensure all outstanding memory accesses included
                                                                  buffered write are completed before reset */
  ((SCB_Type *) ((0xE000E000UL) /*!< System Control Space Base Address  */ + 0x0D00UL) /*!< System Control Block Base Address  */ ) /*!< SCB configuration struct           */->AIRCR = ((0x5FA << 16 /*!< SCB AIRCR: VECTKEY Position */) |
                 (((SCB_Type *) ((0xE000E000UL) /*!< System Control Space Base Address  */ + 0x0D00UL) /*!< System Control Block Base Address  */ ) /*!< SCB configuration struct           */->AIRCR & (7UL << 8 /*!< SCB AIRCR: PRIGROUP Position */) /*!< SCB AIRCR: PRIGROUP Mask */) |
                 (1UL << 2 /*!< SCB AIRCR: SYSRESETREQ Position */) /*!< SCB AIRCR: SYSRESETREQ Mask */); /* Keep priority group unchanged */
  __DSB(); /* Ensure completion of memory access */
  while(1); /* wait until reset */
}

/*@} end of CMSIS_Core_NVICFunctions */



/* ##################################    SysTick function  ############################################ */
/** \ingroup  CMSIS_Core_FunctionInterface
    \defgroup CMSIS_Core_SysTickFunctions CMSIS Core SysTick Functions
  @{
 */



/** \brief  System Tick Configuration

    This function initialises the system tick timer and its interrupt and start the system tick timer.
    Counter is in free running mode to generate periodical interrupts.

    \param [in]  ticks  Number of ticks between two interrupts
    \return          0  Function succeeded
    \return          1  Function failed
 */
static inline /*!< inline keyword for GNU Compiler       */ uint32_t SysTick_Config(uint32_t ticks)
{
  if (ticks > (0xFFFFFFUL << 0 /*!< SysTick LOAD: RELOAD Position */) /*!< SysTick LOAD: RELOAD Mask */) return (1); /* Reload value impossible */

  ((SysTick_Type *) ((0xE000E000UL) /*!< System Control Space Base Address  */ + 0x0010UL) /*!< SysTick Base Address               */ ) /*!< SysTick configuration struct       */->LOAD = (ticks & (0xFFFFFFUL << 0 /*!< SysTick LOAD: RELOAD Position */) /*!< SysTick LOAD: RELOAD Mask */) - 1; /* set reload register */
  NVIC_SetPriority (SysTick_IRQn, (1<<4 /**< SAM3X8E uses 4 Bits for the Priority Levels */) - 1); /* set Priority for Cortex-M0 System Interrupts */
  ((SysTick_Type *) ((0xE000E000UL) /*!< System Control Space Base Address  */ + 0x0010UL) /*!< SysTick Base Address               */ ) /*!< SysTick configuration struct       */->VAL = 0; /* Load the SysTick Counter Value */
  ((SysTick_Type *) ((0xE000E000UL) /*!< System Control Space Base Address  */ + 0x0010UL) /*!< SysTick Base Address               */ ) /*!< SysTick configuration struct       */->CTRL = (1UL << 2 /*!< SysTick CTRL: CLKSOURCE Position */) /*!< SysTick CTRL: CLKSOURCE Mask */ |
                   (1UL << 1 /*!< SysTick CTRL: TICKINT Position */) /*!< SysTick CTRL: TICKINT Mask */ |
                   (1UL << 0 /*!< SysTick CTRL: ENABLE Position */) /*!< SysTick CTRL: ENABLE Mask */; /* Enable SysTick IRQ and SysTick Timer */
  return (0); /* Function successful */
}



/*@} end of CMSIS_Core_SysTickFunctions */



/* ##################################### Debug In/Output function ########################################### */
/** \ingroup  CMSIS_Core_FunctionInterface
    \defgroup CMSIS_core_DebugFunctions CMSIS Core Debug Functions
  @{
 */

extern volatile int32_t ITM_RxBuffer; /*!< external variable to receive characters                    */



/** \brief  ITM Send Character

    This function transmits a character via the ITM channel 0.
    It just returns when no debugger is connected that has booked the output.
    It is blocking when a debugger is connected, but the previous character send is not transmitted.

    \param [in]     ch  Character to transmit
    \return             Character to transmit
 */
static inline /*!< inline keyword for GNU Compiler       */ uint32_t ITM_SendChar (uint32_t ch)
{
  if ((((CoreDebug_Type *) (0xE000EDF0UL) /*!< Core Debug Base Address            */) /*!< Core Debug configuration struct    */->DEMCR & (1UL << 24 /*!< CoreDebug DEMCR: TRCENA Position */) /*!< CoreDebug DEMCR: TRCENA Mask */) && /* Trace enabled */
      (((ITM_Type *) (0xE0000000UL) /*!< ITM Base Address                   */ ) /*!< ITM configuration struct           */->TCR & (1UL << 0 /*!< ITM TCR: ITM Enable bit Position */) /*!< ITM TCR: ITM Enable bit Mask */) && /* ITM enabled */
      (((ITM_Type *) (0xE0000000UL) /*!< ITM Base Address                   */ ) /*!< ITM configuration struct           */->TER & (1UL << 0) ) ) /* ITM Port #0 enabled */
  {
    while (((ITM_Type *) (0xE0000000UL) /*!< ITM Base Address                   */ ) /*!< ITM configuration struct           */->PORT[0].u32 == 0);
    ((ITM_Type *) (0xE0000000UL) /*!< ITM Base Address                   */ ) /*!< ITM configuration struct           */->PORT[0].u8 = (uint8_t) ch;
  }
  return (ch);
}


/** \brief  ITM Receive Character

    This function inputs a character via external variable ITM_RxBuffer.
    It just returns when no debugger is connected that has booked the output.
    It is blocking when a debugger is connected, but the previous character send is not transmitted.

    \return             Received character
    \return         -1  No character received
 */
static inline /*!< inline keyword for GNU Compiler       */ int32_t ITM_ReceiveChar (void) {
  int32_t ch = -1; /* no character available */

  if (ITM_RxBuffer != 0x5AA55AA5 /*!< value identifying ITM_RxBuffer is ready for next character */) {
    ch = ITM_RxBuffer;
    ITM_RxBuffer = 0x5AA55AA5 /*!< value identifying ITM_RxBuffer is ready for next character */; /* ready for next character */
  }

  return (ch);
}


/** \brief  ITM Check Character

    This function checks external variable ITM_RxBuffer whether a character is available or not.
    It returns '1' if a character is available and '0' if no character is available.

    \return          0  No character available
    \return          1  Character available
 */
static inline /*!< inline keyword for GNU Compiler       */ int32_t ITM_CheckChar (void) {

  if (ITM_RxBuffer == 0x5AA55AA5 /*!< value identifying ITM_RxBuffer is ready for next character */) {
    return (0); /* no character available */
  } else {
    return (1); /*    character available */
  }
}

/*@} end of CMSIS_core_DebugFunctions */






}
# 261 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/system_sam3xa.h" 1
/*! \file *********************************************************************
 *
 * \brief CMSIS Cortex-M# Device Peripheral Access Layer Header File
 *           for SAM3 devices.
 *
 * $asf_license$
 *
 * \par Purpose
 *
 * This file provides basic support for Cortex-M processor based 
 * microcontrollers.
 *
 * \author               Atmel Corporation: http://www.atmel.com \n
 *                       Support and FAQ: http://support.atmel.no/
 *
 ******************************************************************************/




/* @cond 0 */
/**INDENT-OFF**/

extern "C" {

/**INDENT-ON**/
/* @endcond */



extern uint32_t SystemCoreClock; /* System Clock Frequency (Core Clock) */

/**
 * @brief Setup the microcontroller system.
 * Initialize the System and update the SystemCoreClock variable.
 */
void SystemInit(void);

/**
 * @brief Updates the SystemCoreClock with current core Clock 
 * retrieved from cpu registers.
 */
void SystemCoreClockUpdate(void);

/** 
 * Initialize flash.
 */
void system_init_flash(uint32_t dw_clk);

/* @cond 0 */
/**INDENT-OFF**/

}

/**INDENT-ON**/
/* @endcond */
# 263 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2


/*@}*/

/* ************************************************************************** */
/**  SOFTWARE PERIPHERAL API DEFINITION FOR SAM3X8E */
/* ************************************************************************** */
/** \addtogroup SAM3X8E_api Peripheral Software API */
/*@{*/

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_adc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Analog-to-digital Converter */
/* ============================================================================= */
/** \addtogroup SAM3XA_ADC Analog-to-digital Converter */
/*@{*/


/** \brief Adc hardware registers */
typedef struct {
  WoReg ADC_CR; /**< \brief (Adc Offset: 0x00) Control Register */
  RwReg ADC_MR; /**< \brief (Adc Offset: 0x04) Mode Register */
  RwReg ADC_SEQR1; /**< \brief (Adc Offset: 0x08) Channel Sequence Register 1 */
  RwReg ADC_SEQR2; /**< \brief (Adc Offset: 0x0C) Channel Sequence Register 2 */
  WoReg ADC_CHER; /**< \brief (Adc Offset: 0x10) Channel Enable Register */
  WoReg ADC_CHDR; /**< \brief (Adc Offset: 0x14) Channel Disable Register */
  RoReg ADC_CHSR; /**< \brief (Adc Offset: 0x18) Channel Status Register */
  RoReg Reserved1[1];
  RoReg ADC_LCDR; /**< \brief (Adc Offset: 0x20) Last Converted Data Register */
  WoReg ADC_IER; /**< \brief (Adc Offset: 0x24) Interrupt Enable Register */
  WoReg ADC_IDR; /**< \brief (Adc Offset: 0x28) Interrupt Disable Register */
  RoReg ADC_IMR; /**< \brief (Adc Offset: 0x2C) Interrupt Mask Register */
  RoReg ADC_ISR; /**< \brief (Adc Offset: 0x30) Interrupt Status Register */
  RoReg Reserved2[2];
  RoReg ADC_OVER; /**< \brief (Adc Offset: 0x3C) Overrun Status Register */
  RwReg ADC_EMR; /**< \brief (Adc Offset: 0x40) Extended Mode Register */
  RwReg ADC_CWR; /**< \brief (Adc Offset: 0x44) Compare Window Register */
  RwReg ADC_CGR; /**< \brief (Adc Offset: 0x48) Channel Gain Register */
  RwReg ADC_COR; /**< \brief (Adc Offset: 0x4C) Channel Offset Register */
  RoReg ADC_CDR[16]; /**< \brief (Adc Offset: 0x50) Channel Data Register */
  RoReg Reserved3[1];
  RwReg ADC_ACR; /**< \brief (Adc Offset: 0x94) Analog Control Register */
  RoReg Reserved4[19];
  RwReg ADC_WPMR; /**< \brief (Adc Offset: 0xE4) Write Protect Mode Register */
  RoReg ADC_WPSR; /**< \brief (Adc Offset: 0xE8) Write Protect Status Register */
  RoReg Reserved5[5];
  RwReg ADC_RPR; /**< \brief (Adc Offset: 0x100) Receive Pointer Register */
  RwReg ADC_RCR; /**< \brief (Adc Offset: 0x104) Receive Counter Register */
  RoReg Reserved6[2];
  RwReg ADC_RNPR; /**< \brief (Adc Offset: 0x110) Receive Next Pointer Register */
  RwReg ADC_RNCR; /**< \brief (Adc Offset: 0x114) Receive Next Counter Register */
  RoReg Reserved7[2];
  WoReg ADC_PTCR; /**< \brief (Adc Offset: 0x120) Transfer Control Register */
  RoReg ADC_PTSR; /**< \brief (Adc Offset: 0x124) Transfer Status Register */
} Adc;

/* -------- ADC_CR : (ADC Offset: 0x00) Control Register -------- */


/* -------- ADC_MR : (ADC Offset: 0x04) Mode Register -------- */
# 144 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_adc.h"
/* -------- ADC_SEQR1 : (ADC Offset: 0x08) Channel Sequence Register 1 -------- */
# 169 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_adc.h"
/* -------- ADC_SEQR2 : (ADC Offset: 0x0C) Channel Sequence Register 2 -------- */
# 194 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_adc.h"
/* -------- ADC_CHER : (ADC Offset: 0x10) Channel Enable Register -------- */
# 211 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_adc.h"
/* -------- ADC_CHDR : (ADC Offset: 0x14) Channel Disable Register -------- */
# 228 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_adc.h"
/* -------- ADC_CHSR : (ADC Offset: 0x18) Channel Status Register -------- */
# 245 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_adc.h"
/* -------- ADC_LCDR : (ADC Offset: 0x20) Last Converted Data Register -------- */




/* -------- ADC_IER : (ADC Offset: 0x24) Interrupt Enable Register -------- */
# 272 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_adc.h"
/* -------- ADC_IDR : (ADC Offset: 0x28) Interrupt Disable Register -------- */
# 294 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_adc.h"
/* -------- ADC_IMR : (ADC Offset: 0x2C) Interrupt Mask Register -------- */
# 316 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_adc.h"
/* -------- ADC_ISR : (ADC Offset: 0x30) Interrupt Status Register -------- */
# 338 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_adc.h"
/* -------- ADC_OVER : (ADC Offset: 0x3C) Overrun Status Register -------- */
# 355 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_adc.h"
/* -------- ADC_EMR : (ADC Offset: 0x40) Extended Mode Register -------- */
# 370 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_adc.h"
/* -------- ADC_CWR : (ADC Offset: 0x44) Compare Window Register -------- */






/* -------- ADC_CGR : (ADC Offset: 0x48) Channel Gain Register -------- */
# 426 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_adc.h"
/* -------- ADC_COR : (ADC Offset: 0x4C) Channel Offset Register -------- */
# 459 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_adc.h"
/* -------- ADC_CDR[16] : (ADC Offset: 0x50) Channel Data Register -------- */


/* -------- ADC_ACR : (ADC Offset: 0x94) Analog Control Register -------- */




/* -------- ADC_WPMR : (ADC Offset: 0xE4) Write Protect Mode Register -------- */




/* -------- ADC_WPSR : (ADC Offset: 0xE8) Write Protect Status Register -------- */



/* -------- ADC_RPR : (ADC Offset: 0x100) Receive Pointer Register -------- */



/* -------- ADC_RCR : (ADC Offset: 0x104) Receive Counter Register -------- */



/* -------- ADC_RNPR : (ADC Offset: 0x110) Receive Next Pointer Register -------- */



/* -------- ADC_RNCR : (ADC Offset: 0x114) Receive Next Counter Register -------- */



/* -------- ADC_PTCR : (ADC Offset: 0x120) Transfer Control Register -------- */




/* -------- ADC_PTSR : (ADC Offset: 0x124) Transfer Status Register -------- */



/*@}*/
# 274 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_can.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Controller Area Network */
/* ============================================================================= */
/** \addtogroup SAM3XA_CAN Controller Area Network */
/*@{*/


/** \brief CanMb hardware registers */
typedef struct {
  RwReg CAN_MMR; /**< \brief (CanMb Offset: 0x0) Mailbox Mode Register */
  RwReg CAN_MAM; /**< \brief (CanMb Offset: 0x4) Mailbox Acceptance Mask Register */
  RwReg CAN_MID; /**< \brief (CanMb Offset: 0x8) Mailbox ID Register */
  RwReg CAN_MFID; /**< \brief (CanMb Offset: 0xC) Mailbox Family ID Register */
  RwReg CAN_MSR; /**< \brief (CanMb Offset: 0x10) Mailbox Status Register */
  RwReg CAN_MDL; /**< \brief (CanMb Offset: 0x14) Mailbox Data Low Register */
  RwReg CAN_MDH; /**< \brief (CanMb Offset: 0x18) Mailbox Data High Register */
  RwReg CAN_MCR; /**< \brief (CanMb Offset: 0x1C) Mailbox Control Register */
} CanMb;
/** \brief Can hardware registers */

typedef struct {
  RwReg CAN_MR; /**< \brief (Can Offset: 0x0000) Mode Register */
  WoReg CAN_IER; /**< \brief (Can Offset: 0x0004) Interrupt Enable Register */
  WoReg CAN_IDR; /**< \brief (Can Offset: 0x0008) Interrupt Disable Register */
  RoReg CAN_IMR; /**< \brief (Can Offset: 0x000C) Interrupt Mask Register */
  RoReg CAN_SR; /**< \brief (Can Offset: 0x0010) Status Register */
  RwReg CAN_BR; /**< \brief (Can Offset: 0x0014) Baudrate Register */
  RoReg CAN_TIM; /**< \brief (Can Offset: 0x0018) Timer Register */
  RoReg CAN_TIMESTP; /**< \brief (Can Offset: 0x001C) Timestamp Register */
  RoReg CAN_ECR; /**< \brief (Can Offset: 0x0020) Error Counter Register */
  WoReg CAN_TCR; /**< \brief (Can Offset: 0x0024) Transfer Command Register */
  WoReg CAN_ACR; /**< \brief (Can Offset: 0x0028) Abort Command Register */
  RoReg Reserved1[46];
  RwReg CAN_WPMR; /**< \brief (Can Offset: 0x00E4) Write Protect Mode Register */
  RoReg CAN_WPSR; /**< \brief (Can Offset: 0x00E8) Write Protect Status Register */
  RoReg Reserved2[69];
  CanMb CAN_MB[8]; /**< \brief (Can Offset: 0x200) MB = 0 .. 7 */
} Can;

/* -------- CAN_MR : (CAN Offset: 0x0000) Mode Register -------- */
# 87 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_can.h"
/* -------- CAN_IER : (CAN Offset: 0x0004) Interrupt Enable Register -------- */
# 109 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_can.h"
/* -------- CAN_IDR : (CAN Offset: 0x0008) Interrupt Disable Register -------- */
# 131 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_can.h"
/* -------- CAN_IMR : (CAN Offset: 0x000C) Interrupt Mask Register -------- */
# 153 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_can.h"
/* -------- CAN_SR : (CAN Offset: 0x0010) Status Register -------- */
# 178 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_can.h"
/* -------- CAN_BR : (CAN Offset: 0x0014) Baudrate Register -------- */
# 197 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_can.h"
/* -------- CAN_TIM : (CAN Offset: 0x0018) Timer Register -------- */


/* -------- CAN_TIMESTP : (CAN Offset: 0x001C) Timestamp Register -------- */


/* -------- CAN_ECR : (CAN Offset: 0x0020) Error Counter Register -------- */




/* -------- CAN_TCR : (CAN Offset: 0x0024) Transfer Command Register -------- */
# 218 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_can.h"
/* -------- CAN_ACR : (CAN Offset: 0x0028) Abort Command Register -------- */
# 227 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_can.h"
/* -------- CAN_WPMR : (CAN Offset: 0x00E4) Write Protect Mode Register -------- */




/* -------- CAN_WPSR : (CAN Offset: 0x00E8) Write Protect Status Register -------- */



/* -------- CAN_MMR : (CAN Offset: N/A) Mailbox Mode Register -------- */
# 251 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_can.h"
/* -------- CAN_MAM : (CAN Offset: N/A) Mailbox Acceptance Mask Register -------- */







/* -------- CAN_MID : (CAN Offset: N/A) Mailbox ID Register -------- */







/* -------- CAN_MFID : (CAN Offset: N/A) Mailbox Family ID Register -------- */


/* -------- CAN_MSR : (CAN Offset: N/A) Mailbox Status Register -------- */
# 279 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_can.h"
/* -------- CAN_MDL : (CAN Offset: N/A) Mailbox Data Low Register -------- */



/* -------- CAN_MDH : (CAN Offset: N/A) Mailbox Data High Register -------- */



/* -------- CAN_MCR : (CAN Offset: N/A) Mailbox Control Register -------- */







/*@}*/
# 275 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_chipid.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Chip Identifier */
/* ============================================================================= */
/** \addtogroup SAM3XA_CHIPID Chip Identifier */
/*@{*/


/** \brief Chipid hardware registers */
typedef struct {
  RoReg CHIPID_CIDR; /**< \brief (Chipid Offset: 0x0) Chip ID Register */
  RoReg CHIPID_EXID; /**< \brief (Chipid Offset: 0x4) Chip ID Extension Register */
} Chipid;

/* -------- CHIPID_CIDR : (CHIPID Offset: 0x0) Chip ID Register -------- */
# 152 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_chipid.h"
/* -------- CHIPID_EXID : (CHIPID Offset: 0x4) Chip ID Extension Register -------- */



/*@}*/
# 276 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_dacc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Digital-to-Analog Converter Controller */
/* ============================================================================= */
/** \addtogroup SAM3XA_DACC Digital-to-Analog Converter Controller */
/*@{*/


/** \brief Dacc hardware registers */
typedef struct {
  WoReg DACC_CR; /**< \brief (Dacc Offset: 0x00) Control Register */
  RwReg DACC_MR; /**< \brief (Dacc Offset: 0x04) Mode Register */
  RoReg Reserved1[2];
  WoReg DACC_CHER; /**< \brief (Dacc Offset: 0x10) Channel Enable Register */
  WoReg DACC_CHDR; /**< \brief (Dacc Offset: 0x14) Channel Disable Register */
  RoReg DACC_CHSR; /**< \brief (Dacc Offset: 0x18) Channel Status Register */
  RoReg Reserved2[1];
  WoReg DACC_CDR; /**< \brief (Dacc Offset: 0x20) Conversion Data Register */
  WoReg DACC_IER; /**< \brief (Dacc Offset: 0x24) Interrupt Enable Register */
  WoReg DACC_IDR; /**< \brief (Dacc Offset: 0x28) Interrupt Disable Register */
  RoReg DACC_IMR; /**< \brief (Dacc Offset: 0x2C) Interrupt Mask Register */
  RoReg DACC_ISR; /**< \brief (Dacc Offset: 0x30) Interrupt Status Register */
  RoReg Reserved3[24];
  RwReg DACC_ACR; /**< \brief (Dacc Offset: 0x94) Analog Current Register */
  RoReg Reserved4[19];
  RwReg DACC_WPMR; /**< \brief (Dacc Offset: 0xE4) Write Protect Mode register */
  RoReg DACC_WPSR; /**< \brief (Dacc Offset: 0xE8) Write Protect Status register */
  RoReg Reserved5[7];
  RwReg DACC_TPR; /**< \brief (Dacc Offset: 0x108) Transmit Pointer Register */
  RwReg DACC_TCR; /**< \brief (Dacc Offset: 0x10C) Transmit Counter Register */
  RoReg Reserved6[2];
  RwReg DACC_TNPR; /**< \brief (Dacc Offset: 0x118) Transmit Next Pointer Register */
  RwReg DACC_TNCR; /**< \brief (Dacc Offset: 0x11C) Transmit Next Counter Register */
  WoReg DACC_PTCR; /**< \brief (Dacc Offset: 0x120) Transfer Control Register */
  RoReg DACC_PTSR; /**< \brief (Dacc Offset: 0x124) Transfer Status Register */
} Dacc;

/* -------- DACC_CR : (DACC Offset: 0x00) Control Register -------- */

/* -------- DACC_MR : (DACC Offset: 0x04) Mode Register -------- */
# 130 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_dacc.h"
/* -------- DACC_CHER : (DACC Offset: 0x10) Channel Enable Register -------- */


/* -------- DACC_CHDR : (DACC Offset: 0x14) Channel Disable Register -------- */


/* -------- DACC_CHSR : (DACC Offset: 0x18) Channel Status Register -------- */


/* -------- DACC_CDR : (DACC Offset: 0x20) Conversion Data Register -------- */



/* -------- DACC_IER : (DACC Offset: 0x24) Interrupt Enable Register -------- */




/* -------- DACC_IDR : (DACC Offset: 0x28) Interrupt Disable Register -------- */




/* -------- DACC_IMR : (DACC Offset: 0x2C) Interrupt Mask Register -------- */




/* -------- DACC_ISR : (DACC Offset: 0x30) Interrupt Status Register -------- */




/* -------- DACC_ACR : (DACC Offset: 0x94) Analog Current Register -------- */
# 173 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_dacc.h"
/* -------- DACC_WPMR : (DACC Offset: 0xE4) Write Protect Mode register -------- */




/* -------- DACC_WPSR : (DACC Offset: 0xE8) Write Protect Status register -------- */



/* -------- DACC_TPR : (DACC Offset: 0x108) Transmit Pointer Register -------- */



/* -------- DACC_TCR : (DACC Offset: 0x10C) Transmit Counter Register -------- */



/* -------- DACC_TNPR : (DACC Offset: 0x118) Transmit Next Pointer Register -------- */



/* -------- DACC_TNCR : (DACC Offset: 0x11C) Transmit Next Counter Register -------- */



/* -------- DACC_PTCR : (DACC Offset: 0x120) Transfer Control Register -------- */




/* -------- DACC_PTSR : (DACC Offset: 0x124) Transfer Status Register -------- */



/*@}*/
# 277 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_dmac.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR DMA Controller */
/* ============================================================================= */
/** \addtogroup SAM3XA_DMAC DMA Controller */
/*@{*/


/** \brief DmacCh_num hardware registers */
typedef struct {
  RwReg DMAC_SADDR; /**< \brief (DmacCh_num Offset: 0x0) DMAC Channel Source Address Register */
  RwReg DMAC_DADDR; /**< \brief (DmacCh_num Offset: 0x4) DMAC Channel Destination Address Register */
  RwReg DMAC_DSCR; /**< \brief (DmacCh_num Offset: 0x8) DMAC Channel Descriptor Address Register */
  RwReg DMAC_CTRLA; /**< \brief (DmacCh_num Offset: 0xC) DMAC Channel Control A Register */
  RwReg DMAC_CTRLB; /**< \brief (DmacCh_num Offset: 0x10) DMAC Channel Control B Register */
  RwReg DMAC_CFG; /**< \brief (DmacCh_num Offset: 0x14) DMAC Channel Configuration Register */
  RoReg Reserved1[4];
} DmacCh_num;
/** \brief Dmac hardware registers */

typedef struct {
  RwReg DMAC_GCFG; /**< \brief (Dmac Offset: 0x000) DMAC Global Configuration Register */
  RwReg DMAC_EN; /**< \brief (Dmac Offset: 0x004) DMAC Enable Register */
  RwReg DMAC_SREQ; /**< \brief (Dmac Offset: 0x008) DMAC Software Single Request Register */
  RwReg DMAC_CREQ; /**< \brief (Dmac Offset: 0x00C) DMAC Software Chunk Transfer Request Register */
  RwReg DMAC_LAST; /**< \brief (Dmac Offset: 0x010) DMAC Software Last Transfer Flag Register */
  RoReg Reserved1[1];
  WoReg DMAC_EBCIER; /**< \brief (Dmac Offset: 0x018) DMAC Error, Chained Buffer Transfer Completed Interrupt and Buffer Transfer Completed Interrupt Enable register. */
  WoReg DMAC_EBCIDR; /**< \brief (Dmac Offset: 0x01C) DMAC Error, Chained Buffer Transfer Completed Interrupt and Buffer Transfer Completed Interrupt Disable register. */
  RoReg DMAC_EBCIMR; /**< \brief (Dmac Offset: 0x020) DMAC Error, Chained Buffer Transfer Completed Interrupt and Buffer transfer completed Mask Register. */
  RoReg DMAC_EBCISR; /**< \brief (Dmac Offset: 0x024) DMAC Error, Chained Buffer Transfer Completed Interrupt and Buffer transfer completed Status Register. */
  WoReg DMAC_CHER; /**< \brief (Dmac Offset: 0x028) DMAC Channel Handler Enable Register */
  WoReg DMAC_CHDR; /**< \brief (Dmac Offset: 0x02C) DMAC Channel Handler Disable Register */
  RoReg DMAC_CHSR; /**< \brief (Dmac Offset: 0x030) DMAC Channel Handler Status Register */
  RoReg Reserved2[2];
  DmacCh_num DMAC_CH_NUM[6]; /**< \brief (Dmac Offset: 0x3C) ch_num = 0 .. 5 */
  RoReg Reserved3[46];
  RwReg DMAC_WPMR; /**< \brief (Dmac Offset: 0x1E4) DMAC Write Protect Mode Register */
  RoReg DMAC_WPSR; /**< \brief (Dmac Offset: 0x1E8) DMAC Write Protect Status Register */
} Dmac;

/* -------- DMAC_GCFG : (DMAC Offset: 0x000) DMAC Global Configuration Register -------- */



/* -------- DMAC_EN : (DMAC Offset: 0x004) DMAC Enable Register -------- */

/* -------- DMAC_SREQ : (DMAC Offset: 0x008) DMAC Software Single Request Register -------- */
# 92 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_dmac.h"
/* -------- DMAC_CREQ : (DMAC Offset: 0x00C) DMAC Software Chunk Transfer Request Register -------- */
# 105 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_dmac.h"
/* -------- DMAC_LAST : (DMAC Offset: 0x010) DMAC Software Last Transfer Flag Register -------- */
# 118 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_dmac.h"
/* -------- DMAC_EBCIER : (DMAC Offset: 0x018) DMAC Error, Chained Buffer Transfer Completed Interrupt and Buffer Transfer Completed Interrupt Enable register. -------- */
# 137 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_dmac.h"
/* -------- DMAC_EBCIDR : (DMAC Offset: 0x01C) DMAC Error, Chained Buffer Transfer Completed Interrupt and Buffer Transfer Completed Interrupt Disable register. -------- */
# 156 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_dmac.h"
/* -------- DMAC_EBCIMR : (DMAC Offset: 0x020) DMAC Error, Chained Buffer Transfer Completed Interrupt and Buffer transfer completed Mask Register. -------- */
# 175 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_dmac.h"
/* -------- DMAC_EBCISR : (DMAC Offset: 0x024) DMAC Error, Chained Buffer Transfer Completed Interrupt and Buffer transfer completed Status Register. -------- */
# 194 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_dmac.h"
/* -------- DMAC_CHER : (DMAC Offset: 0x028) DMAC Channel Handler Enable Register -------- */
# 213 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_dmac.h"
/* -------- DMAC_CHDR : (DMAC Offset: 0x02C) DMAC Channel Handler Disable Register -------- */
# 226 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_dmac.h"
/* -------- DMAC_CHSR : (DMAC Offset: 0x030) DMAC Channel Handler Status Register -------- */
# 251 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_dmac.h"
/* -------- DMAC_SADDR : (DMAC Offset: N/A) DMAC Channel Source Address Register -------- */



/* -------- DMAC_DADDR : (DMAC Offset: N/A) DMAC Channel Destination Address Register -------- */



/* -------- DMAC_DSCR : (DMAC Offset: N/A) DMAC Channel Descriptor Address Register -------- */



/* -------- DMAC_CTRLA : (DMAC Offset: N/A) DMAC Channel Control A Register -------- */
# 298 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_dmac.h"
/* -------- DMAC_CTRLB : (DMAC Offset: N/A) DMAC Channel Control B Register -------- */
# 322 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_dmac.h"
/* -------- DMAC_CFG : (DMAC Offset: N/A) DMAC Channel Configuration Register -------- */
# 354 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_dmac.h"
/* -------- DMAC_WPMR : (DMAC Offset: 0x1E4) DMAC Write Protect Mode Register -------- */




/* -------- DMAC_WPSR : (DMAC Offset: 0x1E8) DMAC Write Protect Status Register -------- */




/*@}*/
# 278 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_efc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Embedded Flash Controller */
/* ============================================================================= */
/** \addtogroup SAM3XA_EFC Embedded Flash Controller */
/*@{*/


/** \brief Efc hardware registers */
typedef struct {
  RwReg EEFC_FMR; /**< \brief (Efc Offset: 0x00) EEFC Flash Mode Register */
  WoReg EEFC_FCR; /**< \brief (Efc Offset: 0x04) EEFC Flash Command Register */
  RoReg EEFC_FSR; /**< \brief (Efc Offset: 0x08) EEFC Flash Status Register */
  RoReg EEFC_FRR; /**< \brief (Efc Offset: 0x0C) EEFC Flash Result Register */
} Efc;

/* -------- EEFC_FMR : (EFC Offset: 0x00) EEFC Flash Mode Register -------- */






/* -------- EEFC_FCR : (EFC Offset: 0x04) EEFC Flash Command Register -------- */
# 65 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_efc.h"
/* -------- EEFC_FSR : (EFC Offset: 0x08) EEFC Flash Status Register -------- */



/* -------- EEFC_FRR : (EFC Offset: 0x0C) EEFC Flash Result Register -------- */



/*@}*/
# 279 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_emac.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Ethernet MAC 10/100 */
/* ============================================================================= */
/** \addtogroup SAM3XA_EMAC Ethernet MAC 10/100 */
/*@{*/


/** \brief EmacSa hardware registers */
typedef struct {
  RwReg EMAC_SAxB; /**< \brief (EmacSa Offset: 0x0) Specific Address 1 Bottom Register */
  RwReg EMAC_SAxT; /**< \brief (EmacSa Offset: 0x4) Specific Address 1 Top Register */
} EmacSa;
/** \brief Emac hardware registers */

typedef struct {
  RwReg EMAC_NCR; /**< \brief (Emac Offset: 0x00) Network Control Register */
  RwReg EMAC_NCFGR; /**< \brief (Emac Offset: 0x04) Network Configuration Register */
  RoReg EMAC_NSR; /**< \brief (Emac Offset: 0x08) Network Status Register */
  RoReg Reserved1[2];
  RwReg EMAC_TSR; /**< \brief (Emac Offset: 0x14) Transmit Status Register */
  RwReg EMAC_RBQP; /**< \brief (Emac Offset: 0x18) Receive Buffer Queue Pointer Register */
  RwReg EMAC_TBQP; /**< \brief (Emac Offset: 0x1C) Transmit Buffer Queue Pointer Register */
  RwReg EMAC_RSR; /**< \brief (Emac Offset: 0x20) Receive Status Register */
  RwReg EMAC_ISR; /**< \brief (Emac Offset: 0x24) Interrupt Status Register */
  WoReg EMAC_IER; /**< \brief (Emac Offset: 0x28) Interrupt Enable Register */
  WoReg EMAC_IDR; /**< \brief (Emac Offset: 0x2C) Interrupt Disable Register */
  RoReg EMAC_IMR; /**< \brief (Emac Offset: 0x30) Interrupt Mask Register */
  RwReg EMAC_MAN; /**< \brief (Emac Offset: 0x34) Phy Maintenance Register */
  RwReg EMAC_PTR; /**< \brief (Emac Offset: 0x38) Pause Time Register */
  RwReg EMAC_PFR; /**< \brief (Emac Offset: 0x3C) Pause Frames Received Register */
  RwReg EMAC_FTO; /**< \brief (Emac Offset: 0x40) Frames Transmitted Ok Register */
  RwReg EMAC_SCF; /**< \brief (Emac Offset: 0x44) Single Collision Frames Register */
  RwReg EMAC_MCF; /**< \brief (Emac Offset: 0x48) Multiple Collision Frames Register */
  RwReg EMAC_FRO; /**< \brief (Emac Offset: 0x4C) Frames Received Ok Register */
  RwReg EMAC_FCSE; /**< \brief (Emac Offset: 0x50) Frame Check Sequence Errors Register */
  RwReg EMAC_ALE; /**< \brief (Emac Offset: 0x54) Alignment Errors Register */
  RwReg EMAC_DTF; /**< \brief (Emac Offset: 0x58) Deferred Transmission Frames Register */
  RwReg EMAC_LCOL; /**< \brief (Emac Offset: 0x5C) Late Collisions Register */
  RwReg EMAC_ECOL; /**< \brief (Emac Offset: 0x60) Excessive Collisions Register */
  RwReg EMAC_TUND; /**< \brief (Emac Offset: 0x64) Transmit Underrun Errors Register */
  RwReg EMAC_CSE; /**< \brief (Emac Offset: 0x68) Carrier Sense Errors Register */
  RwReg EMAC_RRE; /**< \brief (Emac Offset: 0x6C) Receive Resource Errors Register */
  RwReg EMAC_ROV; /**< \brief (Emac Offset: 0x70) Receive Overrun Errors Register */
  RwReg EMAC_RSE; /**< \brief (Emac Offset: 0x74) Receive Symbol Errors Register */
  RwReg EMAC_ELE; /**< \brief (Emac Offset: 0x78) Excessive Length Errors Register */
  RwReg EMAC_RJA; /**< \brief (Emac Offset: 0x7C) Receive Jabbers Register */
  RwReg EMAC_USF; /**< \brief (Emac Offset: 0x80) Undersize Frames Register */
  RwReg EMAC_STE; /**< \brief (Emac Offset: 0x84) SQE Test Errors Register */
  RwReg EMAC_RLE; /**< \brief (Emac Offset: 0x88) Received Length Field Mismatch Register */
  RoReg Reserved2[1];
  RwReg EMAC_HRB; /**< \brief (Emac Offset: 0x90) Hash Register Bottom [31:0] Register */
  RwReg EMAC_HRT; /**< \brief (Emac Offset: 0x94) Hash Register Top [63:32] Register */
  EmacSa EMAC_SA[4]; /**< \brief (Emac Offset: 0x98) sa = 1 .. 4 */
  RwReg EMAC_TID; /**< \brief (Emac Offset: 0xB8) Type ID Checking Register */
  RoReg Reserved3[1];
  RwReg EMAC_USRIO; /**< \brief (Emac Offset: 0xC0) User Input/Output Register */
} Emac;

/* -------- EMAC_NCR : (EMAC Offset: 0x00) Network Control Register -------- */
# 103 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_emac.h"
/* -------- EMAC_NCFGR : (EMAC Offset: 0x04) Network Configuration Register -------- */
# 130 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_emac.h"
/* -------- EMAC_NSR : (EMAC Offset: 0x08) Network Status Register -------- */


/* -------- EMAC_TSR : (EMAC Offset: 0x14) Transmit Status Register -------- */







/* -------- EMAC_RBQP : (EMAC Offset: 0x18) Receive Buffer Queue Pointer Register -------- */



/* -------- EMAC_TBQP : (EMAC Offset: 0x1C) Transmit Buffer Queue Pointer Register -------- */



/* -------- EMAC_RSR : (EMAC Offset: 0x20) Receive Status Register -------- */



/* -------- EMAC_ISR : (EMAC Offset: 0x24) Interrupt Status Register -------- */
# 166 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_emac.h"
/* -------- EMAC_IER : (EMAC Offset: 0x28) Interrupt Enable Register -------- */
# 179 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_emac.h"
/* -------- EMAC_IDR : (EMAC Offset: 0x2C) Interrupt Disable Register -------- */
# 192 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_emac.h"
/* -------- EMAC_IMR : (EMAC Offset: 0x30) Interrupt Mask Register -------- */
# 205 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_emac.h"
/* -------- EMAC_MAN : (EMAC Offset: 0x34) Phy Maintenance Register -------- */
# 224 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_emac.h"
/* -------- EMAC_PTR : (EMAC Offset: 0x38) Pause Time Register -------- */



/* -------- EMAC_PFR : (EMAC Offset: 0x3C) Pause Frames Received Register -------- */



/* -------- EMAC_FTO : (EMAC Offset: 0x40) Frames Transmitted Ok Register -------- */



/* -------- EMAC_SCF : (EMAC Offset: 0x44) Single Collision Frames Register -------- */



/* -------- EMAC_MCF : (EMAC Offset: 0x48) Multiple Collision Frames Register -------- */



/* -------- EMAC_FRO : (EMAC Offset: 0x4C) Frames Received Ok Register -------- */



/* -------- EMAC_FCSE : (EMAC Offset: 0x50) Frame Check Sequence Errors Register -------- */



/* -------- EMAC_ALE : (EMAC Offset: 0x54) Alignment Errors Register -------- */



/* -------- EMAC_DTF : (EMAC Offset: 0x58) Deferred Transmission Frames Register -------- */



/* -------- EMAC_LCOL : (EMAC Offset: 0x5C) Late Collisions Register -------- */



/* -------- EMAC_ECOL : (EMAC Offset: 0x60) Excessive Collisions Register -------- */



/* -------- EMAC_TUND : (EMAC Offset: 0x64) Transmit Underrun Errors Register -------- */



/* -------- EMAC_CSE : (EMAC Offset: 0x68) Carrier Sense Errors Register -------- */



/* -------- EMAC_RRE : (EMAC Offset: 0x6C) Receive Resource Errors Register -------- */



/* -------- EMAC_ROV : (EMAC Offset: 0x70) Receive Overrun Errors Register -------- */



/* -------- EMAC_RSE : (EMAC Offset: 0x74) Receive Symbol Errors Register -------- */



/* -------- EMAC_ELE : (EMAC Offset: 0x78) Excessive Length Errors Register -------- */



/* -------- EMAC_RJA : (EMAC Offset: 0x7C) Receive Jabbers Register -------- */



/* -------- EMAC_USF : (EMAC Offset: 0x80) Undersize Frames Register -------- */



/* -------- EMAC_STE : (EMAC Offset: 0x84) SQE Test Errors Register -------- */



/* -------- EMAC_RLE : (EMAC Offset: 0x88) Received Length Field Mismatch Register -------- */



/* -------- EMAC_HRB : (EMAC Offset: 0x90) Hash Register Bottom [31:0] Register -------- */



/* -------- EMAC_HRT : (EMAC Offset: 0x94) Hash Register Top [63:32] Register -------- */



/* -------- EMAC_SAxB : (EMAC Offset: N/A) Specific Address 1 Bottom Register -------- */



/* -------- EMAC_SAxT : (EMAC Offset: N/A) Specific Address 1 Top Register -------- */



/* -------- EMAC_TID : (EMAC Offset: 0xB8) Type ID Checking Register -------- */



/* -------- EMAC_USRIO : (EMAC Offset: 0xC0) User Input/Output Register -------- */



/*@}*/
# 280 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_gpbr.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR General Purpose Backup Register */
/* ============================================================================= */
/** \addtogroup SAM3XA_GPBR General Purpose Backup Register */
/*@{*/


/** \brief Gpbr hardware registers */
typedef struct {
  RwReg SYS_GPBR[8]; /**< \brief (Gpbr Offset: 0x0) General Purpose Backup Register */
} Gpbr;

/* -------- SYS_GPBR[8] : (GPBR Offset: 0x0) General Purpose Backup Register -------- */




/*@}*/
# 281 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_hsmci.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR High Speed MultiMedia Card Interface */
/* ============================================================================= */
/** \addtogroup SAM3XA_HSMCI High Speed MultiMedia Card Interface */
/*@{*/


/** \brief Hsmci hardware registers */
typedef struct {
  WoReg HSMCI_CR; /**< \brief (Hsmci Offset: 0x00) Control Register */
  RwReg HSMCI_MR; /**< \brief (Hsmci Offset: 0x04) Mode Register */
  RwReg HSMCI_DTOR; /**< \brief (Hsmci Offset: 0x08) Data Timeout Register */
  RwReg HSMCI_SDCR; /**< \brief (Hsmci Offset: 0x0C) SD/SDIO Card Register */
  RwReg HSMCI_ARGR; /**< \brief (Hsmci Offset: 0x10) Argument Register */
  WoReg HSMCI_CMDR; /**< \brief (Hsmci Offset: 0x14) Command Register */
  RwReg HSMCI_BLKR; /**< \brief (Hsmci Offset: 0x18) Block Register */
  RwReg HSMCI_CSTOR; /**< \brief (Hsmci Offset: 0x1C) Completion Signal Timeout Register */
  RoReg HSMCI_RSPR[4]; /**< \brief (Hsmci Offset: 0x20) Response Register */
  RoReg HSMCI_RDR; /**< \brief (Hsmci Offset: 0x30) Receive Data Register */
  WoReg HSMCI_TDR; /**< \brief (Hsmci Offset: 0x34) Transmit Data Register */
  RoReg Reserved1[2];
  RoReg HSMCI_SR; /**< \brief (Hsmci Offset: 0x40) Status Register */
  WoReg HSMCI_IER; /**< \brief (Hsmci Offset: 0x44) Interrupt Enable Register */
  WoReg HSMCI_IDR; /**< \brief (Hsmci Offset: 0x48) Interrupt Disable Register */
  RoReg HSMCI_IMR; /**< \brief (Hsmci Offset: 0x4C) Interrupt Mask Register */
  RwReg HSMCI_DMA; /**< \brief (Hsmci Offset: 0x50) DMA Configuration Register */
  RwReg HSMCI_CFG; /**< \brief (Hsmci Offset: 0x54) Configuration Register */
  RoReg Reserved2[35];
  RwReg HSMCI_WPMR; /**< \brief (Hsmci Offset: 0xE4) Write Protection Mode Register */
  RoReg HSMCI_WPSR; /**< \brief (Hsmci Offset: 0xE8) Write Protection Status Register */
  RoReg Reserved3[69];
  RwReg HSMCI_FIFO[256]; /**< \brief (Hsmci Offset: 0x200) FIFO Memory Aperture0 */
} Hsmci;

/* -------- HSMCI_CR : (HSMCI Offset: 0x00) Control Register -------- */





/* -------- HSMCI_MR : (HSMCI Offset: 0x04) Mode Register -------- */
# 84 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_hsmci.h"
/* -------- HSMCI_DTOR : (HSMCI Offset: 0x08) Data Timeout Register -------- */
# 98 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_hsmci.h"
/* -------- HSMCI_SDCR : (HSMCI Offset: 0x0C) SD/SDIO Card Register -------- */
# 110 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_hsmci.h"
/* -------- HSMCI_ARGR : (HSMCI Offset: 0x10) Argument Register -------- */



/* -------- HSMCI_CMDR : (HSMCI Offset: 0x14) Command Register -------- */
# 164 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_hsmci.h"
/* -------- HSMCI_BLKR : (HSMCI Offset: 0x18) Block Register -------- */
# 173 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_hsmci.h"
/* -------- HSMCI_CSTOR : (HSMCI Offset: 0x1C) Completion Signal Timeout Register -------- */
# 187 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_hsmci.h"
/* -------- HSMCI_RSPR[4] : (HSMCI Offset: 0x20) Response Register -------- */


/* -------- HSMCI_RDR : (HSMCI Offset: 0x30) Receive Data Register -------- */


/* -------- HSMCI_TDR : (HSMCI Offset: 0x34) Transmit Data Register -------- */



/* -------- HSMCI_SR : (HSMCI Offset: 0x40) Status Register -------- */
# 224 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_hsmci.h"
/* -------- HSMCI_IER : (HSMCI Offset: 0x44) Interrupt Enable Register -------- */
# 251 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_hsmci.h"
/* -------- HSMCI_IDR : (HSMCI Offset: 0x48) Interrupt Disable Register -------- */
# 278 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_hsmci.h"
/* -------- HSMCI_IMR : (HSMCI Offset: 0x4C) Interrupt Mask Register -------- */
# 305 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_hsmci.h"
/* -------- HSMCI_DMA : (HSMCI Offset: 0x50) DMA Configuration Register -------- */
# 314 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_hsmci.h"
/* -------- HSMCI_CFG : (HSMCI Offset: 0x54) Configuration Register -------- */




/* -------- HSMCI_WPMR : (HSMCI Offset: 0xE4) Write Protection Mode Register -------- */




/* -------- HSMCI_WPSR : (HSMCI Offset: 0xE8) Write Protection Status Register -------- */
# 333 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_hsmci.h"
/* -------- HSMCI_FIFO[256] : (HSMCI Offset: 0x200) FIFO Memory Aperture0 -------- */




/*@}*/
# 282 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_matrix.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR AHB Bus Matrix */
/* ============================================================================= */
/** \addtogroup SAM3XA_MATRIX AHB Bus Matrix */
/*@{*/


/** \brief Matrix hardware registers */
typedef struct {
  RwReg MATRIX_MCFG[6]; /**< \brief (Matrix Offset: 0x0000) Master Configuration Register */
  RoReg Reserved1[10];
  RwReg MATRIX_SCFG[9]; /**< \brief (Matrix Offset: 0x0040) Slave Configuration Register */
  RoReg Reserved2[7];
  RwReg MATRIX_PRAS0; /**< \brief (Matrix Offset: 0x0080) Priority Register A for Slave 0 */
  RoReg Reserved3[1];
  RwReg MATRIX_PRAS1; /**< \brief (Matrix Offset: 0x0088) Priority Register A for Slave 1 */
  RoReg Reserved4[1];
  RwReg MATRIX_PRAS2; /**< \brief (Matrix Offset: 0x0090) Priority Register A for Slave 2 */
  RoReg Reserved5[1];
  RwReg MATRIX_PRAS3; /**< \brief (Matrix Offset: 0x0098) Priority Register A for Slave 3 */
  RoReg Reserved6[1];
  RwReg MATRIX_PRAS4; /**< \brief (Matrix Offset: 0x00A0) Priority Register A for Slave 4 */
  RoReg Reserved7[1];
  RwReg MATRIX_PRAS5; /**< \brief (Matrix Offset: 0x00A8) Priority Register A for Slave 5 */
  RoReg Reserved8[1];
  RwReg MATRIX_PRAS6; /**< \brief (Matrix Offset: 0x00B0) Priority Register A for Slave 6 */
  RoReg Reserved9[1];
  RwReg MATRIX_PRAS7; /**< \brief (Matrix Offset: 0x00B8) Priority Register A for Slave 7 */
  RoReg Reserved10[1];
  RwReg MATRIX_PRAS8; /**< \brief (Matrix Offset: 0x00C0) Priority Register A for Slave 8 */
  RoReg Reserved11[1];
  RoReg Reserved12[14];
  RwReg MATRIX_MRCR; /**< \brief (Matrix Offset: 0x0100) Master Remap Control Register */
  RoReg Reserved13[4];
  RwReg CCFG_SYSIO; /**< \brief (Matrix Offset: 0x0114) System I/O Configuration register */
  RoReg Reserved14[51];
  RwReg MATRIX_WPMR; /**< \brief (Matrix Offset: 0x1E4) Write Protect Mode Register */
  RoReg MATRIX_WPSR; /**< \brief (Matrix Offset: 0x1E8) Write Protect Status Register */
} Matrix;

/* -------- MATRIX_MCFG[6] : (MATRIX Offset: 0x0000) Master Configuration Register -------- */



/* -------- MATRIX_SCFG[9] : (MATRIX Offset: 0x0040) Slave Configuration Register -------- */
# 90 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_matrix.h"
/* -------- MATRIX_PRAS0 : (MATRIX Offset: 0x0080) Priority Register A for Slave 0 -------- */
# 109 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_matrix.h"
/* -------- MATRIX_PRAS1 : (MATRIX Offset: 0x0088) Priority Register A for Slave 1 -------- */
# 128 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_matrix.h"
/* -------- MATRIX_PRAS2 : (MATRIX Offset: 0x0090) Priority Register A for Slave 2 -------- */
# 147 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_matrix.h"
/* -------- MATRIX_PRAS3 : (MATRIX Offset: 0x0098) Priority Register A for Slave 3 -------- */
# 166 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_matrix.h"
/* -------- MATRIX_PRAS4 : (MATRIX Offset: 0x00A0) Priority Register A for Slave 4 -------- */
# 185 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_matrix.h"
/* -------- MATRIX_PRAS5 : (MATRIX Offset: 0x00A8) Priority Register A for Slave 5 -------- */
# 204 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_matrix.h"
/* -------- MATRIX_PRAS6 : (MATRIX Offset: 0x00B0) Priority Register A for Slave 6 -------- */
# 223 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_matrix.h"
/* -------- MATRIX_PRAS7 : (MATRIX Offset: 0x00B8) Priority Register A for Slave 7 -------- */
# 242 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_matrix.h"
/* -------- MATRIX_PRAS8 : (MATRIX Offset: 0x00C0) Priority Register A for Slave 8 -------- */
# 261 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_matrix.h"
/* -------- MATRIX_MRCR : (MATRIX Offset: 0x0100) Master Remap Control Register -------- */
# 270 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_matrix.h"
/* -------- CCFG_SYSIO : (MATRIX Offset: 0x0114) System I/O Configuration register -------- */

/* -------- MATRIX_WPMR : (MATRIX Offset: 0x1E4) Write Protect Mode Register -------- */




/* -------- MATRIX_WPSR : (MATRIX Offset: 0x1E8) Write Protect Status Register -------- */




/*@}*/
# 283 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pdc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Peripheral DMA Controller */
/* ============================================================================= */
/** \addtogroup SAM3XA_PDC Peripheral DMA Controller */
/*@{*/


/** \brief Pdc hardware registers */
typedef struct {
  RwReg PERIPH_RPR; /**< \brief (Pdc Offset: 0x0) Receive Pointer Register */
  RwReg PERIPH_RCR; /**< \brief (Pdc Offset: 0x4) Receive Counter Register */
  RwReg PERIPH_TPR; /**< \brief (Pdc Offset: 0x8) Transmit Pointer Register */
  RwReg PERIPH_TCR; /**< \brief (Pdc Offset: 0xC) Transmit Counter Register */
  RwReg PERIPH_RNPR; /**< \brief (Pdc Offset: 0x10) Receive Next Pointer Register */
  RwReg PERIPH_RNCR; /**< \brief (Pdc Offset: 0x14) Receive Next Counter Register */
  RwReg PERIPH_TNPR; /**< \brief (Pdc Offset: 0x18) Transmit Next Pointer Register */
  RwReg PERIPH_TNCR; /**< \brief (Pdc Offset: 0x1C) Transmit Next Counter Register */
  WoReg PERIPH_PTCR; /**< \brief (Pdc Offset: 0x20) Transfer Control Register */
  RoReg PERIPH_PTSR; /**< \brief (Pdc Offset: 0x24) Transfer Status Register */
} Pdc;

/* -------- PERIPH_RPR : (PDC Offset: 0x0) Receive Pointer Register -------- */



/* -------- PERIPH_RCR : (PDC Offset: 0x4) Receive Counter Register -------- */



/* -------- PERIPH_TPR : (PDC Offset: 0x8) Transmit Pointer Register -------- */



/* -------- PERIPH_TCR : (PDC Offset: 0xC) Transmit Counter Register -------- */



/* -------- PERIPH_RNPR : (PDC Offset: 0x10) Receive Next Pointer Register -------- */



/* -------- PERIPH_RNCR : (PDC Offset: 0x14) Receive Next Counter Register -------- */



/* -------- PERIPH_TNPR : (PDC Offset: 0x18) Transmit Next Pointer Register -------- */



/* -------- PERIPH_TNCR : (PDC Offset: 0x1C) Transmit Next Counter Register -------- */



/* -------- PERIPH_PTCR : (PDC Offset: 0x20) Transfer Control Register -------- */




/* -------- PERIPH_PTSR : (PDC Offset: 0x24) Transfer Status Register -------- */



/*@}*/
# 284 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Parallel Input/Output Controller */
/* ============================================================================= */
/** \addtogroup SAM3XA_PIO Parallel Input/Output Controller */
/*@{*/


/** \brief Pio hardware registers */
typedef struct {
  WoReg PIO_PER; /**< \brief (Pio Offset: 0x0000) PIO Enable Register */
  WoReg PIO_PDR; /**< \brief (Pio Offset: 0x0004) PIO Disable Register */
  RoReg PIO_PSR; /**< \brief (Pio Offset: 0x0008) PIO Status Register */
  RoReg Reserved1[1];
  WoReg PIO_OER; /**< \brief (Pio Offset: 0x0010) Output Enable Register */
  WoReg PIO_ODR; /**< \brief (Pio Offset: 0x0014) Output Disable Register */
  RoReg PIO_OSR; /**< \brief (Pio Offset: 0x0018) Output Status Register */
  RoReg Reserved2[1];
  WoReg PIO_IFER; /**< \brief (Pio Offset: 0x0020) Glitch Input Filter Enable Register */
  WoReg PIO_IFDR; /**< \brief (Pio Offset: 0x0024) Glitch Input Filter Disable Register */
  RoReg PIO_IFSR; /**< \brief (Pio Offset: 0x0028) Glitch Input Filter Status Register */
  RoReg Reserved3[1];
  WoReg PIO_SODR; /**< \brief (Pio Offset: 0x0030) Set Output Data Register */
  WoReg PIO_CODR; /**< \brief (Pio Offset: 0x0034) Clear Output Data Register */
  RwReg PIO_ODSR; /**< \brief (Pio Offset: 0x0038) Output Data Status Register */
  RoReg PIO_PDSR; /**< \brief (Pio Offset: 0x003C) Pin Data Status Register */
  WoReg PIO_IER; /**< \brief (Pio Offset: 0x0040) Interrupt Enable Register */
  WoReg PIO_IDR; /**< \brief (Pio Offset: 0x0044) Interrupt Disable Register */
  RoReg PIO_IMR; /**< \brief (Pio Offset: 0x0048) Interrupt Mask Register */
  RoReg PIO_ISR; /**< \brief (Pio Offset: 0x004C) Interrupt Status Register */
  WoReg PIO_MDER; /**< \brief (Pio Offset: 0x0050) Multi-driver Enable Register */
  WoReg PIO_MDDR; /**< \brief (Pio Offset: 0x0054) Multi-driver Disable Register */
  RoReg PIO_MDSR; /**< \brief (Pio Offset: 0x0058) Multi-driver Status Register */
  RoReg Reserved4[1];
  WoReg PIO_PUDR; /**< \brief (Pio Offset: 0x0060) Pull-up Disable Register */
  WoReg PIO_PUER; /**< \brief (Pio Offset: 0x0064) Pull-up Enable Register */
  RoReg PIO_PUSR; /**< \brief (Pio Offset: 0x0068) Pad Pull-up Status Register */
  RoReg Reserved5[1];
  RwReg PIO_ABSR; /**< \brief (Pio Offset: 0x0070) Peripheral AB Select Register */
  RoReg Reserved6[3];
  WoReg PIO_SCIFSR; /**< \brief (Pio Offset: 0x0080) System Clock Glitch Input Filter Select Register */
  WoReg PIO_DIFSR; /**< \brief (Pio Offset: 0x0084) Debouncing Input Filter Select Register */
  RoReg PIO_IFDGSR; /**< \brief (Pio Offset: 0x0088) Glitch or Debouncing Input Filter Clock Selection Status Register */
  RwReg PIO_SCDR; /**< \brief (Pio Offset: 0x008C) Slow Clock Divider Debouncing Register */
  RoReg Reserved7[4];
  WoReg PIO_OWER; /**< \brief (Pio Offset: 0x00A0) Output Write Enable */
  WoReg PIO_OWDR; /**< \brief (Pio Offset: 0x00A4) Output Write Disable */
  RoReg PIO_OWSR; /**< \brief (Pio Offset: 0x00A8) Output Write Status Register */
  RoReg Reserved8[1];
  WoReg PIO_AIMER; /**< \brief (Pio Offset: 0x00B0) Additional Interrupt Modes Enable Register */
  WoReg PIO_AIMDR; /**< \brief (Pio Offset: 0x00B4) Additional Interrupt Modes Disables Register */
  RoReg PIO_AIMMR; /**< \brief (Pio Offset: 0x00B8) Additional Interrupt Modes Mask Register */
  RoReg Reserved9[1];
  WoReg PIO_ESR; /**< \brief (Pio Offset: 0x00C0) Edge Select Register */
  WoReg PIO_LSR; /**< \brief (Pio Offset: 0x00C4) Level Select Register */
  RoReg PIO_ELSR; /**< \brief (Pio Offset: 0x00C8) Edge/Level Status Register */
  RoReg Reserved10[1];
  WoReg PIO_FELLSR; /**< \brief (Pio Offset: 0x00D0) Falling Edge/Low Level Select Register */
  WoReg PIO_REHLSR; /**< \brief (Pio Offset: 0x00D4) Rising Edge/ High Level Select Register */
  RoReg PIO_FRLHSR; /**< \brief (Pio Offset: 0x00D8) Fall/Rise - Low/High Status Register */
  RoReg Reserved11[1];
  RoReg PIO_LOCKSR; /**< \brief (Pio Offset: 0x00E0) Lock Status */
  RwReg PIO_WPMR; /**< \brief (Pio Offset: 0x00E4) Write Protect Mode Register */
  RoReg PIO_WPSR; /**< \brief (Pio Offset: 0x00E8) Write Protect Status Register */
} Pio;

/* -------- PIO_PER : (PIO Offset: 0x0000) PIO Enable Register -------- */
# 131 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_PDR : (PIO Offset: 0x0004) PIO Disable Register -------- */
# 164 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_PSR : (PIO Offset: 0x0008) PIO Status Register -------- */
# 197 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_OER : (PIO Offset: 0x0010) Output Enable Register -------- */
# 230 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_ODR : (PIO Offset: 0x0014) Output Disable Register -------- */
# 263 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_OSR : (PIO Offset: 0x0018) Output Status Register -------- */
# 296 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_IFER : (PIO Offset: 0x0020) Glitch Input Filter Enable Register -------- */
# 329 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_IFDR : (PIO Offset: 0x0024) Glitch Input Filter Disable Register -------- */
# 362 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_IFSR : (PIO Offset: 0x0028) Glitch Input Filter Status Register -------- */
# 395 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_SODR : (PIO Offset: 0x0030) Set Output Data Register -------- */
# 428 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_CODR : (PIO Offset: 0x0034) Clear Output Data Register -------- */
# 461 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_ODSR : (PIO Offset: 0x0038) Output Data Status Register -------- */
# 494 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_PDSR : (PIO Offset: 0x003C) Pin Data Status Register -------- */
# 527 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_IER : (PIO Offset: 0x0040) Interrupt Enable Register -------- */
# 560 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_IDR : (PIO Offset: 0x0044) Interrupt Disable Register -------- */
# 593 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_IMR : (PIO Offset: 0x0048) Interrupt Mask Register -------- */
# 626 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_ISR : (PIO Offset: 0x004C) Interrupt Status Register -------- */
# 659 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_MDER : (PIO Offset: 0x0050) Multi-driver Enable Register -------- */
# 692 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_MDDR : (PIO Offset: 0x0054) Multi-driver Disable Register -------- */
# 725 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_MDSR : (PIO Offset: 0x0058) Multi-driver Status Register -------- */
# 758 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_PUDR : (PIO Offset: 0x0060) Pull-up Disable Register -------- */
# 791 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_PUER : (PIO Offset: 0x0064) Pull-up Enable Register -------- */
# 824 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_PUSR : (PIO Offset: 0x0068) Pad Pull-up Status Register -------- */
# 857 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_ABSR : (PIO Offset: 0x0070) Peripheral AB Select Register -------- */
# 890 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_SCIFSR : (PIO Offset: 0x0080) System Clock Glitch Input Filter Select Register -------- */
# 923 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_DIFSR : (PIO Offset: 0x0084) Debouncing Input Filter Select Register -------- */
# 956 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_IFDGSR : (PIO Offset: 0x0088) Glitch or Debouncing Input Filter Clock Selection Status Register -------- */
# 989 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_SCDR : (PIO Offset: 0x008C) Slow Clock Divider Debouncing Register -------- */



/* -------- PIO_OWER : (PIO Offset: 0x00A0) Output Write Enable -------- */
# 1026 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_OWDR : (PIO Offset: 0x00A4) Output Write Disable -------- */
# 1059 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_OWSR : (PIO Offset: 0x00A8) Output Write Status Register -------- */
# 1092 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_AIMER : (PIO Offset: 0x00B0) Additional Interrupt Modes Enable Register -------- */
# 1125 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_AIMDR : (PIO Offset: 0x00B4) Additional Interrupt Modes Disables Register -------- */
# 1158 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_AIMMR : (PIO Offset: 0x00B8) Additional Interrupt Modes Mask Register -------- */
# 1191 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_ESR : (PIO Offset: 0x00C0) Edge Select Register -------- */
# 1224 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_LSR : (PIO Offset: 0x00C4) Level Select Register -------- */
# 1257 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_ELSR : (PIO Offset: 0x00C8) Edge/Level Status Register -------- */
# 1290 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_FELLSR : (PIO Offset: 0x00D0) Falling Edge/Low Level Select Register -------- */
# 1323 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_REHLSR : (PIO Offset: 0x00D4) Rising Edge/ High Level Select Register -------- */
# 1356 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_FRLHSR : (PIO Offset: 0x00D8) Fall/Rise - Low/High Status Register -------- */
# 1389 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_LOCKSR : (PIO Offset: 0x00E0) Lock Status -------- */
# 1422 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h"
/* -------- PIO_WPMR : (PIO Offset: 0x00E4) Write Protect Mode Register -------- */




/* -------- PIO_WPSR : (PIO Offset: 0x00E8) Write Protect Status Register -------- */




/*@}*/
# 285 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pmc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Power Management Controller */
/* ============================================================================= */
/** \addtogroup SAM3XA_PMC Power Management Controller */
/*@{*/


/** \brief Pmc hardware registers */
typedef struct {
  WoReg PMC_SCER; /**< \brief (Pmc Offset: 0x0000) System Clock Enable Register */
  WoReg PMC_SCDR; /**< \brief (Pmc Offset: 0x0004) System Clock Disable Register */
  RoReg PMC_SCSR; /**< \brief (Pmc Offset: 0x0008) System Clock Status Register */
  RoReg Reserved1[1];
  WoReg PMC_PCER0; /**< \brief (Pmc Offset: 0x0010) Peripheral Clock Enable Register 0 */
  WoReg PMC_PCDR0; /**< \brief (Pmc Offset: 0x0014) Peripheral Clock Disable Register 0 */
  RoReg PMC_PCSR0; /**< \brief (Pmc Offset: 0x0018) Peripheral Clock Status Register 0 */
  RwReg CKGR_UCKR; /**< \brief (Pmc Offset: 0x001C) UTMI Clock Register */
  RwReg CKGR_MOR; /**< \brief (Pmc Offset: 0x0020) Main Oscillator Register */
  RoReg CKGR_MCFR; /**< \brief (Pmc Offset: 0x0024) Main Clock Frequency Register */
  RwReg CKGR_PLLAR; /**< \brief (Pmc Offset: 0x0028) PLLA Register */
  RoReg Reserved2[1];
  RwReg PMC_MCKR; /**< \brief (Pmc Offset: 0x0030) Master Clock Register */
  RoReg Reserved3[1];
  RwReg PMC_USB; /**< \brief (Pmc Offset: 0x0038) USB Clock Register */
  RoReg Reserved4[1];
  RwReg PMC_PCK[3]; /**< \brief (Pmc Offset: 0x0040) Programmable Clock 0 Register */
  RoReg Reserved5[5];
  WoReg PMC_IER; /**< \brief (Pmc Offset: 0x0060) Interrupt Enable Register */
  WoReg PMC_IDR; /**< \brief (Pmc Offset: 0x0064) Interrupt Disable Register */
  RoReg PMC_SR; /**< \brief (Pmc Offset: 0x0068) Status Register */
  RoReg PMC_IMR; /**< \brief (Pmc Offset: 0x006C) Interrupt Mask Register */
  RwReg PMC_FSMR; /**< \brief (Pmc Offset: 0x0070) Fast Startup Mode Register */
  RwReg PMC_FSPR; /**< \brief (Pmc Offset: 0x0074) Fast Startup Polarity Register */
  WoReg PMC_FOCR; /**< \brief (Pmc Offset: 0x0078) Fault Output Clear Register */
  RoReg Reserved6[26];
  RwReg PMC_WPMR; /**< \brief (Pmc Offset: 0x00E4) Write Protect Mode Register */
  RoReg PMC_WPSR; /**< \brief (Pmc Offset: 0x00E8) Write Protect Status Register */
  RoReg Reserved7[5];
  WoReg PMC_PCER1; /**< \brief (Pmc Offset: 0x0100) Peripheral Clock Enable Register 1 */
  WoReg PMC_PCDR1; /**< \brief (Pmc Offset: 0x0104) Peripheral Clock Disable Register 1 */
  RoReg PMC_PCSR1; /**< \brief (Pmc Offset: 0x0108) Peripheral Clock Status Register 1 */
  RwReg PMC_PCR; /**< \brief (Pmc Offset: 0x010C) Peripheral Control Register */
} Pmc;

/* -------- PMC_SCER : (PMC Offset: 0x0000) System Clock Enable Register -------- */




/* -------- PMC_SCDR : (PMC Offset: 0x0004) System Clock Disable Register -------- */




/* -------- PMC_SCSR : (PMC Offset: 0x0008) System Clock Status Register -------- */




/* -------- PMC_PCER0 : (PMC Offset: 0x0010) Peripheral Clock Enable Register 0 -------- */
# 123 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pmc.h"
/* -------- PMC_PCDR0 : (PMC Offset: 0x0014) Peripheral Clock Disable Register 0 -------- */
# 154 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pmc.h"
/* -------- PMC_PCSR0 : (PMC Offset: 0x0018) Peripheral Clock Status Register 0 -------- */
# 185 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pmc.h"
/* -------- CKGR_UCKR : (PMC Offset: 0x001C) UTMI Clock Register -------- */




/* -------- CKGR_MOR : (PMC Offset: 0x0020) Main Oscillator Register -------- */
# 207 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pmc.h"
/* -------- CKGR_MCFR : (PMC Offset: 0x0024) Main Clock Frequency Register -------- */



/* -------- CKGR_PLLAR : (PMC Offset: 0x0028) PLLA Register -------- */
# 222 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pmc.h"
/* -------- PMC_MCKR : (PMC Offset: 0x0030) Master Clock Register -------- */
# 241 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pmc.h"
/* -------- PMC_USB : (PMC Offset: 0x0038) USB Clock Register -------- */




/* -------- PMC_PCK[3] : (PMC Offset: 0x0040) Programmable Clock 0 Register -------- */
# 263 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pmc.h"
/* -------- PMC_IER : (PMC Offset: 0x0060) Interrupt Enable Register -------- */
# 274 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pmc.h"
/* -------- PMC_IDR : (PMC Offset: 0x0064) Interrupt Disable Register -------- */
# 285 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pmc.h"
/* -------- PMC_SR : (PMC Offset: 0x0068) Status Register -------- */
# 299 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pmc.h"
/* -------- PMC_IMR : (PMC Offset: 0x006C) Interrupt Mask Register -------- */
# 310 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pmc.h"
/* -------- PMC_FSMR : (PMC Offset: 0x0070) Fast Startup Mode Register -------- */
# 331 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pmc.h"
/* -------- PMC_FSPR : (PMC Offset: 0x0074) Fast Startup Polarity Register -------- */
# 348 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pmc.h"
/* -------- PMC_FOCR : (PMC Offset: 0x0078) Fault Output Clear Register -------- */

/* -------- PMC_WPMR : (PMC Offset: 0x00E4) Write Protect Mode Register -------- */




/* -------- PMC_WPSR : (PMC Offset: 0x00E8) Write Protect Status Register -------- */



/* -------- PMC_PCER1 : (PMC Offset: 0x0100) Peripheral Clock Enable Register 1 -------- */
# 373 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pmc.h"
/* -------- PMC_PCDR1 : (PMC Offset: 0x0104) Peripheral Clock Disable Register 1 -------- */
# 387 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pmc.h"
/* -------- PMC_PCSR1 : (PMC Offset: 0x0108) Peripheral Clock Status Register 1 -------- */
# 401 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pmc.h"
/* -------- PMC_PCR : (PMC Offset: 0x010C) Peripheral Control Register -------- */
# 413 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pmc.h"
/*@}*/
# 286 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Pulse Width Modulation Controller */
/* ============================================================================= */
/** \addtogroup SAM3XA_PWM Pulse Width Modulation Controller */
/*@{*/


/** \brief PwmCh_num hardware registers */
typedef struct {
  RwReg PWM_CMR; /**< \brief (PwmCh_num Offset: 0x0) PWM Channel Mode Register */
  RwReg PWM_CDTY; /**< \brief (PwmCh_num Offset: 0x4) PWM Channel Duty Cycle Register */
  RwReg PWM_CDTYUPD; /**< \brief (PwmCh_num Offset: 0x8) PWM Channel Duty Cycle Update Register */
  RwReg PWM_CPRD; /**< \brief (PwmCh_num Offset: 0xC) PWM Channel Period Register */
  RwReg PWM_CPRDUPD; /**< \brief (PwmCh_num Offset: 0x10) PWM Channel Period Update Register */
  RwReg PWM_CCNT; /**< \brief (PwmCh_num Offset: 0x14) PWM Channel Counter Register */
  RwReg PWM_DT; /**< \brief (PwmCh_num Offset: 0x18) PWM Channel Dead Time Register */
  RwReg PWM_DTUPD; /**< \brief (PwmCh_num Offset: 0x1C) PWM Channel Dead Time Update Register */
} PwmCh_num;
/** \brief PwmCmp hardware registers */
typedef struct {
  RwReg PWM_CMPV; /**< \brief (PwmCmp Offset: 0x0) PWM Comparison 0 Value Register */
  RwReg PWM_CMPVUPD; /**< \brief (PwmCmp Offset: 0x4) PWM Comparison 0 Value Update Register */
  RwReg PWM_CMPM; /**< \brief (PwmCmp Offset: 0x8) PWM Comparison 0 Mode Register */
  RwReg PWM_CMPMUPD; /**< \brief (PwmCmp Offset: 0xC) PWM Comparison 0 Mode Update Register */
} PwmCmp;
/** \brief Pwm hardware registers */


typedef struct {
  RwReg PWM_CLK; /**< \brief (Pwm Offset: 0x00) PWM Clock Register */
  WoReg PWM_ENA; /**< \brief (Pwm Offset: 0x04) PWM Enable Register */
  WoReg PWM_DIS; /**< \brief (Pwm Offset: 0x08) PWM Disable Register */
  RoReg PWM_SR; /**< \brief (Pwm Offset: 0x0C) PWM Status Register */
  WoReg PWM_IER1; /**< \brief (Pwm Offset: 0x10) PWM Interrupt Enable Register 1 */
  WoReg PWM_IDR1; /**< \brief (Pwm Offset: 0x14) PWM Interrupt Disable Register 1 */
  RoReg PWM_IMR1; /**< \brief (Pwm Offset: 0x18) PWM Interrupt Mask Register 1 */
  RoReg PWM_ISR1; /**< \brief (Pwm Offset: 0x1C) PWM Interrupt Status Register 1 */
  RwReg PWM_SCM; /**< \brief (Pwm Offset: 0x20) PWM Sync Channels Mode Register */
  RoReg Reserved1[1];
  RwReg PWM_SCUC; /**< \brief (Pwm Offset: 0x28) PWM Sync Channels Update Control Register */
  RwReg PWM_SCUP; /**< \brief (Pwm Offset: 0x2C) PWM Sync Channels Update Period Register */
  WoReg PWM_SCUPUPD; /**< \brief (Pwm Offset: 0x30) PWM Sync Channels Update Period Update Register */
  WoReg PWM_IER2; /**< \brief (Pwm Offset: 0x34) PWM Interrupt Enable Register 2 */
  WoReg PWM_IDR2; /**< \brief (Pwm Offset: 0x38) PWM Interrupt Disable Register 2 */
  RoReg PWM_IMR2; /**< \brief (Pwm Offset: 0x3C) PWM Interrupt Mask Register 2 */
  RoReg PWM_ISR2; /**< \brief (Pwm Offset: 0x40) PWM Interrupt Status Register 2 */
  RwReg PWM_OOV; /**< \brief (Pwm Offset: 0x44) PWM Output Override Value Register */
  RwReg PWM_OS; /**< \brief (Pwm Offset: 0x48) PWM Output Selection Register */
  WoReg PWM_OSS; /**< \brief (Pwm Offset: 0x4C) PWM Output Selection Set Register */
  WoReg PWM_OSC; /**< \brief (Pwm Offset: 0x50) PWM Output Selection Clear Register */
  WoReg PWM_OSSUPD; /**< \brief (Pwm Offset: 0x54) PWM Output Selection Set Update Register */
  WoReg PWM_OSCUPD; /**< \brief (Pwm Offset: 0x58) PWM Output Selection Clear Update Register */
  RwReg PWM_FMR; /**< \brief (Pwm Offset: 0x5C) PWM Fault Mode Register */
  RoReg PWM_FSR; /**< \brief (Pwm Offset: 0x60) PWM Fault Status Register */
  WoReg PWM_FCR; /**< \brief (Pwm Offset: 0x64) PWM Fault Clear Register */
  RwReg PWM_FPV; /**< \brief (Pwm Offset: 0x68) PWM Fault Protection Value Register */
  RwReg PWM_FPE1; /**< \brief (Pwm Offset: 0x6C) PWM Fault Protection Enable Register 1 */
  RwReg PWM_FPE2; /**< \brief (Pwm Offset: 0x70) PWM Fault Protection Enable Register 2 */
  RoReg Reserved2[2];
  RwReg PWM_ELMR[2]; /**< \brief (Pwm Offset: 0x7C) PWM Event Line 0 Mode Register */
  RoReg Reserved3[11];
  RwReg PWM_SMMR; /**< \brief (Pwm Offset: 0xB0) PWM Stepper Motor Mode Register */
  RoReg Reserved4[12];
  WoReg PWM_WPCR; /**< \brief (Pwm Offset: 0xE4) PWM Write Protect Control Register */
  RoReg PWM_WPSR; /**< \brief (Pwm Offset: 0xE8) PWM Write Protect Status Register */
  RoReg Reserved5[7];
  RwReg PWM_TPR; /**< \brief (Pwm Offset: 0x108) Transmit Pointer Register */
  RwReg PWM_TCR; /**< \brief (Pwm Offset: 0x10C) Transmit Counter Register */
  RoReg Reserved6[2];
  RwReg PWM_TNPR; /**< \brief (Pwm Offset: 0x118) Transmit Next Pointer Register */
  RwReg PWM_TNCR; /**< \brief (Pwm Offset: 0x11C) Transmit Next Counter Register */
  WoReg PWM_PTCR; /**< \brief (Pwm Offset: 0x120) Transfer Control Register */
  RoReg PWM_PTSR; /**< \brief (Pwm Offset: 0x124) Transfer Status Register */
  RoReg Reserved7[2];
  PwmCmp PWM_CMP[8]; /**< \brief (Pwm Offset: 0x130) 0 .. 7 */
  RoReg Reserved8[20];
  PwmCh_num PWM_CH_NUM[8]; /**< \brief (Pwm Offset: 0x200) ch_num = 0 .. 7 */
} Pwm;

/* -------- PWM_CLK : (PWM Offset: 0x00) PWM Clock Register -------- */
# 125 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_ENA : (PWM Offset: 0x04) PWM Enable Register -------- */
# 134 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_DIS : (PWM Offset: 0x08) PWM Disable Register -------- */
# 143 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_SR : (PWM Offset: 0x0C) PWM Status Register -------- */
# 152 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_IER1 : (PWM Offset: 0x10) PWM Interrupt Enable Register 1 -------- */
# 169 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_IDR1 : (PWM Offset: 0x14) PWM Interrupt Disable Register 1 -------- */
# 186 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_IMR1 : (PWM Offset: 0x18) PWM Interrupt Mask Register 1 -------- */
# 203 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_ISR1 : (PWM Offset: 0x1C) PWM Interrupt Status Register 1 -------- */
# 220 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_SCM : (PWM Offset: 0x20) PWM Sync Channels Mode Register -------- */
# 238 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_SCUC : (PWM Offset: 0x28) PWM Sync Channels Update Control Register -------- */

/* -------- PWM_SCUP : (PWM Offset: 0x2C) PWM Sync Channels Update Period Register -------- */






/* -------- PWM_SCUPUPD : (PWM Offset: 0x30) PWM Sync Channels Update Period Update Register -------- */



/* -------- PWM_IER2 : (PWM Offset: 0x34) PWM Interrupt Enable Register 2 -------- */
# 272 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_IDR2 : (PWM Offset: 0x38) PWM Interrupt Disable Register 2 -------- */
# 293 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_IMR2 : (PWM Offset: 0x3C) PWM Interrupt Mask Register 2 -------- */
# 314 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_ISR2 : (PWM Offset: 0x40) PWM Interrupt Status Register 2 -------- */
# 335 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_OOV : (PWM Offset: 0x44) PWM Output Override Value Register -------- */
# 352 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_OS : (PWM Offset: 0x48) PWM Output Selection Register -------- */
# 369 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_OSS : (PWM Offset: 0x4C) PWM Output Selection Set Register -------- */
# 386 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_OSC : (PWM Offset: 0x50) PWM Output Selection Clear Register -------- */
# 403 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_OSSUPD : (PWM Offset: 0x54) PWM Output Selection Set Update Register -------- */
# 420 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_OSCUPD : (PWM Offset: 0x58) PWM Output Selection Clear Update Register -------- */
# 437 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_FMR : (PWM Offset: 0x5C) PWM Fault Mode Register -------- */
# 447 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_FSR : (PWM Offset: 0x60) PWM Fault Status Register -------- */




/* -------- PWM_FCR : (PWM Offset: 0x64) PWM Fault Clear Register -------- */



/* -------- PWM_FPV : (PWM Offset: 0x68) PWM Fault Protection Value Register -------- */
# 473 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_FPE1 : (PWM Offset: 0x6C) PWM Fault Protection Enable Register 1 -------- */
# 486 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_FPE2 : (PWM Offset: 0x70) PWM Fault Protection Enable Register 2 -------- */
# 499 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_ELMR[2] : (PWM Offset: 0x7C) PWM Event Line 0 Mode Register -------- */
# 508 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_SMMR : (PWM Offset: 0xB0) PWM Stepper Motor Mode Register -------- */
# 517 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_WPCR : (PWM Offset: 0xE4) PWM Write Protect Control Register -------- */
# 530 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_WPSR : (PWM Offset: 0xE8) PWM Write Protect Status Register -------- */
# 546 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_TPR : (PWM Offset: 0x108) Transmit Pointer Register -------- */



/* -------- PWM_TCR : (PWM Offset: 0x10C) Transmit Counter Register -------- */



/* -------- PWM_TNPR : (PWM Offset: 0x118) Transmit Next Pointer Register -------- */



/* -------- PWM_TNCR : (PWM Offset: 0x11C) Transmit Next Counter Register -------- */



/* -------- PWM_PTCR : (PWM Offset: 0x120) Transfer Control Register -------- */




/* -------- PWM_PTSR : (PWM Offset: 0x124) Transfer Status Register -------- */


/* -------- PWM_CMPV : (PWM Offset: N/A) PWM Comparison 0 Value Register -------- */




/* -------- PWM_CMPVUPD : (PWM Offset: N/A) PWM Comparison 0 Value Update Register -------- */




/* -------- PWM_CMPM : (PWM Offset: N/A) PWM Comparison 0 Mode Register -------- */
# 597 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_CMPMUPD : (PWM Offset: N/A) PWM Comparison 0 Mode Update Register -------- */
# 608 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_CMR : (PWM Offset: N/A) PWM Channel Mode Register -------- */
# 630 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h"
/* -------- PWM_CDTY : (PWM Offset: N/A) PWM Channel Duty Cycle Register -------- */



/* -------- PWM_CDTYUPD : (PWM Offset: N/A) PWM Channel Duty Cycle Update Register -------- */



/* -------- PWM_CPRD : (PWM Offset: N/A) PWM Channel Period Register -------- */



/* -------- PWM_CPRDUPD : (PWM Offset: N/A) PWM Channel Period Update Register -------- */



/* -------- PWM_CCNT : (PWM Offset: N/A) PWM Channel Counter Register -------- */


/* -------- PWM_DT : (PWM Offset: N/A) PWM Channel Dead Time Register -------- */






/* -------- PWM_DTUPD : (PWM Offset: N/A) PWM Channel Dead Time Update Register -------- */







/*@}*/
# 287 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_rstc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Reset Controller */
/* ============================================================================= */
/** \addtogroup SAM3XA_RSTC Reset Controller */
/*@{*/


/** \brief Rstc hardware registers */
typedef struct {
  WoReg RSTC_CR; /**< \brief (Rstc Offset: 0x00) Control Register */
  RoReg RSTC_SR; /**< \brief (Rstc Offset: 0x04) Status Register */
  RwReg RSTC_MR; /**< \brief (Rstc Offset: 0x08) Mode Register */
} Rstc;

/* -------- RSTC_CR : (RSTC Offset: 0x00) Control Register -------- */






/* -------- RSTC_SR : (RSTC Offset: 0x04) Status Register -------- */





/* -------- RSTC_MR : (RSTC Offset: 0x08) Mode Register -------- */
# 70 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_rstc.h"
/*@}*/
# 288 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_rtc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Real-time Clock */
/* ============================================================================= */
/** \addtogroup SAM3XA_RTC Real-time Clock */
/*@{*/


/** \brief Rtc hardware registers */
typedef struct {
  RwReg RTC_CR; /**< \brief (Rtc Offset: 0x00) Control Register */
  RwReg RTC_MR; /**< \brief (Rtc Offset: 0x04) Mode Register */
  RwReg RTC_TIMR; /**< \brief (Rtc Offset: 0x08) Time Register */
  RwReg RTC_CALR; /**< \brief (Rtc Offset: 0x0C) Calendar Register */
  RwReg RTC_TIMALR; /**< \brief (Rtc Offset: 0x10) Time Alarm Register */
  RwReg RTC_CALALR; /**< \brief (Rtc Offset: 0x14) Calendar Alarm Register */
  RoReg RTC_SR; /**< \brief (Rtc Offset: 0x18) Status Register */
  WoReg RTC_SCCR; /**< \brief (Rtc Offset: 0x1C) Status Clear Command Register */
  WoReg RTC_IER; /**< \brief (Rtc Offset: 0x20) Interrupt Enable Register */
  WoReg RTC_IDR; /**< \brief (Rtc Offset: 0x24) Interrupt Disable Register */
  RoReg RTC_IMR; /**< \brief (Rtc Offset: 0x28) Interrupt Mask Register */
  RoReg RTC_VER; /**< \brief (Rtc Offset: 0x2C) Valid Entry Register */
  RoReg Reserved1[45];
  RwReg RTC_WPMR; /**< \brief (Rtc Offset: 0xE4) Write Protect Mode Register */
} Rtc;

/* -------- RTC_CR : (RTC Offset: 0x00) Control Register -------- */
# 72 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_rtc.h"
/* -------- RTC_MR : (RTC Offset: 0x04) Mode Register -------- */

/* -------- RTC_TIMR : (RTC Offset: 0x08) Time Register -------- */
# 85 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_rtc.h"
/* -------- RTC_CALR : (RTC Offset: 0x0C) Calendar Register -------- */
# 101 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_rtc.h"
/* -------- RTC_TIMALR : (RTC Offset: 0x10) Time Alarm Register -------- */
# 115 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_rtc.h"
/* -------- RTC_CALALR : (RTC Offset: 0x14) Calendar Alarm Register -------- */
# 124 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_rtc.h"
/* -------- RTC_SR : (RTC Offset: 0x18) Status Register -------- */





/* -------- RTC_SCCR : (RTC Offset: 0x1C) Status Clear Command Register -------- */





/* -------- RTC_IER : (RTC Offset: 0x20) Interrupt Enable Register -------- */





/* -------- RTC_IDR : (RTC Offset: 0x24) Interrupt Disable Register -------- */





/* -------- RTC_IMR : (RTC Offset: 0x28) Interrupt Mask Register -------- */





/* -------- RTC_VER : (RTC Offset: 0x2C) Valid Entry Register -------- */




/* -------- RTC_WPMR : (RTC Offset: 0xE4) Write Protect Mode Register -------- */





/*@}*/
# 289 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_rtt.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Real-time Timer */
/* ============================================================================= */
/** \addtogroup SAM3XA_RTT Real-time Timer */
/*@{*/


/** \brief Rtt hardware registers */
typedef struct {
  RwReg RTT_MR; /**< \brief (Rtt Offset: 0x00) Mode Register */
  RwReg RTT_AR; /**< \brief (Rtt Offset: 0x04) Alarm Register */
  RoReg RTT_VR; /**< \brief (Rtt Offset: 0x08) Value Register */
  RoReg RTT_SR; /**< \brief (Rtt Offset: 0x0C) Status Register */
} Rtt;

/* -------- RTT_MR : (RTT Offset: 0x00) Mode Register -------- */






/* -------- RTT_AR : (RTT Offset: 0x04) Alarm Register -------- */



/* -------- RTT_VR : (RTT Offset: 0x08) Value Register -------- */


/* -------- RTT_SR : (RTT Offset: 0x0C) Status Register -------- */



/*@}*/
# 290 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_smc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Static Memory Controller */
/* ============================================================================= */
/** \addtogroup SAM3XA_SMC Static Memory Controller */
/*@{*/


/** \brief SmcCs_number hardware registers */
typedef struct {
  RwReg SMC_SETUP; /**< \brief (SmcCs_number Offset: 0x0) SMC Setup Register */
  RwReg SMC_PULSE; /**< \brief (SmcCs_number Offset: 0x4) SMC Pulse Register */
  RwReg SMC_CYCLE; /**< \brief (SmcCs_number Offset: 0x8) SMC Cycle Register */
  RwReg SMC_TIMINGS; /**< \brief (SmcCs_number Offset: 0xC) SMC Timings Register */
  RwReg SMC_MODE; /**< \brief (SmcCs_number Offset: 0x10) SMC Mode Register */
} SmcCs_number;
/** \brief Smc hardware registers */

typedef struct {
  RwReg SMC_CFG; /**< \brief (Smc Offset: 0x000) SMC NFC Configuration Register */
  WoReg SMC_CTRL; /**< \brief (Smc Offset: 0x004) SMC NFC Control Register */
  RoReg SMC_SR; /**< \brief (Smc Offset: 0x008) SMC NFC Status Register */
  WoReg SMC_IER; /**< \brief (Smc Offset: 0x00C) SMC NFC Interrupt Enable Register */
  WoReg SMC_IDR; /**< \brief (Smc Offset: 0x010) SMC NFC Interrupt Disable Register */
  RoReg SMC_IMR; /**< \brief (Smc Offset: 0x014) SMC NFC Interrupt Mask Register */
  RwReg SMC_ADDR; /**< \brief (Smc Offset: 0x018) SMC NFC Address Cycle Zero Register */
  RwReg SMC_BANK; /**< \brief (Smc Offset: 0x01C) SMC Bank Address Register */
  WoReg SMC_ECC_CTRL; /**< \brief (Smc Offset: 0x020) SMC ECC Control Register */
  RwReg SMC_ECC_MD; /**< \brief (Smc Offset: 0x024) SMC ECC Mode Register */
  RoReg SMC_ECC_SR1; /**< \brief (Smc Offset: 0x028) SMC ECC Status 1 Register */
  RoReg SMC_ECC_PR0; /**< \brief (Smc Offset: 0x02C) SMC ECC Parity 0 Register */
  RoReg SMC_ECC_PR1; /**< \brief (Smc Offset: 0x030) SMC ECC parity 1 Register */
  RoReg SMC_ECC_SR2; /**< \brief (Smc Offset: 0x034) SMC ECC status 2 Register */
  RoReg SMC_ECC_PR2; /**< \brief (Smc Offset: 0x038) SMC ECC parity 2 Register */
  RoReg SMC_ECC_PR3; /**< \brief (Smc Offset: 0x03C) SMC ECC parity 3 Register */
  RoReg SMC_ECC_PR4; /**< \brief (Smc Offset: 0x040) SMC ECC parity 4 Register */
  RoReg SMC_ECC_PR5; /**< \brief (Smc Offset: 0x044) SMC ECC parity 5 Register */
  RoReg SMC_ECC_PR6; /**< \brief (Smc Offset: 0x048) SMC ECC parity 6 Register */
  RoReg SMC_ECC_PR7; /**< \brief (Smc Offset: 0x04C) SMC ECC parity 7 Register */
  RoReg SMC_ECC_PR8; /**< \brief (Smc Offset: 0x050) SMC ECC parity 8 Register */
  RoReg SMC_ECC_PR9; /**< \brief (Smc Offset: 0x054) SMC ECC parity 9 Register */
  RoReg SMC_ECC_PR10; /**< \brief (Smc Offset: 0x058) SMC ECC parity 10 Register */
  RoReg SMC_ECC_PR11; /**< \brief (Smc Offset: 0x05C) SMC ECC parity 11 Register */
  RoReg SMC_ECC_PR12; /**< \brief (Smc Offset: 0x060) SMC ECC parity 12 Register */
  RoReg SMC_ECC_PR13; /**< \brief (Smc Offset: 0x064) SMC ECC parity 13 Register */
  RoReg SMC_ECC_PR14; /**< \brief (Smc Offset: 0x068) SMC ECC parity 14 Register */
  RoReg SMC_ECC_PR15; /**< \brief (Smc Offset: 0x06C) SMC ECC parity 15 Register */
  SmcCs_number SMC_CS_NUMBER[8]; /**< \brief (Smc Offset: 0x70) CS_number = 0 .. 7 */
  RwReg SMC_OCMS; /**< \brief (Smc Offset: 0x110) SMC OCMS Register */
  WoReg SMC_KEY1; /**< \brief (Smc Offset: 0x114) SMC OCMS KEY1 Register */
  WoReg SMC_KEY2; /**< \brief (Smc Offset: 0x118) SMC OCMS KEY2 Register */
  RoReg Reserved1[50];
  WoReg SMC_WPCR; /**< \brief (Smc Offset: 0x1E4) Write Protection Control Register */
  RoReg SMC_WPSR; /**< \brief (Smc Offset: 0x1E8) Write Protection Status Register */
} Smc;

/* -------- SMC_CFG : (SMC Offset: 0x000) SMC NFC Configuration Register -------- */
# 112 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_smc.h"
/* -------- SMC_CTRL : (SMC Offset: 0x004) SMC NFC Control Register -------- */


/* -------- SMC_SR : (SMC Offset: 0x008) SMC NFC Status Register -------- */
# 130 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_smc.h"
/* -------- SMC_IER : (SMC Offset: 0x00C) SMC NFC Interrupt Enable Register -------- */
# 140 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_smc.h"
/* -------- SMC_IDR : (SMC Offset: 0x010) SMC NFC Interrupt Disable Register -------- */
# 150 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_smc.h"
/* -------- SMC_IMR : (SMC Offset: 0x014) SMC NFC Interrupt Mask Register -------- */
# 160 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_smc.h"
/* -------- SMC_ADDR : (SMC Offset: 0x018) SMC NFC Address Cycle Zero Register -------- */



/* -------- SMC_BANK : (SMC Offset: 0x01C) SMC Bank Address Register -------- */



/* -------- SMC_ECC_CTRL : (SMC Offset: 0x020) SMC ECC Control Register -------- */


/* -------- SMC_ECC_MD : (SMC Offset: 0x024) SMC ECC Mode Register -------- */
# 183 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_smc.h"
/* -------- SMC_ECC_SR1 : (SMC Offset: 0x028) SMC ECC Status 1 Register -------- */
# 208 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_smc.h"
/* -------- SMC_ECC_PR0 : (SMC Offset: 0x02C) SMC ECC Parity 0 Register -------- */
# 225 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_smc.h"
/* -------- SMC_ECC_PR1 : (SMC Offset: 0x030) SMC ECC parity 1 Register -------- */
# 238 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_smc.h"
/* -------- SMC_ECC_SR2 : (SMC Offset: 0x034) SMC ECC status 2 Register -------- */
# 263 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_smc.h"
/* -------- SMC_ECC_PR2 : (SMC Offset: 0x038) SMC ECC parity 2 Register -------- */
# 274 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_smc.h"
/* -------- SMC_ECC_PR3 : (SMC Offset: 0x03C) SMC ECC parity 3 Register -------- */
# 285 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_smc.h"
/* -------- SMC_ECC_PR4 : (SMC Offset: 0x040) SMC ECC parity 4 Register -------- */
# 296 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_smc.h"
/* -------- SMC_ECC_PR5 : (SMC Offset: 0x044) SMC ECC parity 5 Register -------- */
# 307 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_smc.h"
/* -------- SMC_ECC_PR6 : (SMC Offset: 0x048) SMC ECC parity 6 Register -------- */
# 318 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_smc.h"
/* -------- SMC_ECC_PR7 : (SMC Offset: 0x04C) SMC ECC parity 7 Register -------- */
# 329 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_smc.h"
/* -------- SMC_ECC_PR8 : (SMC Offset: 0x050) SMC ECC parity 8 Register -------- */






/* -------- SMC_ECC_PR9 : (SMC Offset: 0x054) SMC ECC parity 9 Register -------- */






/* -------- SMC_ECC_PR10 : (SMC Offset: 0x058) SMC ECC parity 10 Register -------- */






/* -------- SMC_ECC_PR11 : (SMC Offset: 0x05C) SMC ECC parity 11 Register -------- */






/* -------- SMC_ECC_PR12 : (SMC Offset: 0x060) SMC ECC parity 12 Register -------- */






/* -------- SMC_ECC_PR13 : (SMC Offset: 0x064) SMC ECC parity 13 Register -------- */






/* -------- SMC_ECC_PR14 : (SMC Offset: 0x068) SMC ECC parity 14 Register -------- */






/* -------- SMC_ECC_PR15 : (SMC Offset: 0x06C) SMC ECC parity 15 Register -------- */






/* -------- SMC_SETUP : (SMC Offset: N/A) SMC Setup Register -------- */
# 398 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_smc.h"
/* -------- SMC_PULSE : (SMC Offset: N/A) SMC Pulse Register -------- */
# 411 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_smc.h"
/* -------- SMC_CYCLE : (SMC Offset: N/A) SMC Cycle Register -------- */






/* -------- SMC_TIMINGS : (SMC Offset: N/A) SMC Timings Register -------- */
# 439 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_smc.h"
/* -------- SMC_MODE : (SMC Offset: N/A) SMC Mode Register -------- */
# 459 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_smc.h"
/* -------- SMC_OCMS : (SMC Offset: 0x110) SMC OCMS Register -------- */


/* -------- SMC_KEY1 : (SMC Offset: 0x114) SMC OCMS KEY1 Register -------- */



/* -------- SMC_KEY2 : (SMC Offset: 0x118) SMC OCMS KEY2 Register -------- */



/* -------- SMC_WPCR : (SMC Offset: 0x1E4) Write Protection Control Register -------- */




/* -------- SMC_WPSR : (SMC Offset: 0x1E8) Write Protection Status Register -------- */





/*@}*/
# 291 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_spi.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Serial Peripheral Interface */
/* ============================================================================= */
/** \addtogroup SAM3XA_SPI Serial Peripheral Interface */
/*@{*/


/** \brief Spi hardware registers */
typedef struct {
  WoReg SPI_CR; /**< \brief (Spi Offset: 0x00) Control Register */
  RwReg SPI_MR; /**< \brief (Spi Offset: 0x04) Mode Register */
  RoReg SPI_RDR; /**< \brief (Spi Offset: 0x08) Receive Data Register */
  WoReg SPI_TDR; /**< \brief (Spi Offset: 0x0C) Transmit Data Register */
  RoReg SPI_SR; /**< \brief (Spi Offset: 0x10) Status Register */
  WoReg SPI_IER; /**< \brief (Spi Offset: 0x14) Interrupt Enable Register */
  WoReg SPI_IDR; /**< \brief (Spi Offset: 0x18) Interrupt Disable Register */
  RoReg SPI_IMR; /**< \brief (Spi Offset: 0x1C) Interrupt Mask Register */
  RoReg Reserved1[4];
  RwReg SPI_CSR[4]; /**< \brief (Spi Offset: 0x30) Chip Select Register */
  RoReg Reserved2[41];
  RwReg SPI_WPMR; /**< \brief (Spi Offset: 0xE4) Write Protection Control Register */
  RoReg SPI_WPSR; /**< \brief (Spi Offset: 0xE8) Write Protection Status Register */
} Spi;

/* -------- SPI_CR : (SPI Offset: 0x00) Control Register -------- */




/* -------- SPI_MR : (SPI Offset: 0x04) Mode Register -------- */
# 75 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_spi.h"
/* -------- SPI_RDR : (SPI Offset: 0x08) Receive Data Register -------- */




/* -------- SPI_TDR : (SPI Offset: 0x0C) Transmit Data Register -------- */







/* -------- SPI_SR : (SPI Offset: 0x10) Status Register -------- */
# 97 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_spi.h"
/* -------- SPI_IER : (SPI Offset: 0x14) Interrupt Enable Register -------- */







/* -------- SPI_IDR : (SPI Offset: 0x18) Interrupt Disable Register -------- */







/* -------- SPI_IMR : (SPI Offset: 0x1C) Interrupt Mask Register -------- */







/* -------- SPI_CSR[4] : (SPI Offset: 0x30) Chip Select Register -------- */
# 146 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_spi.h"
/* -------- SPI_WPMR : (SPI Offset: 0xE4) Write Protection Control Register -------- */




/* -------- SPI_WPSR : (SPI Offset: 0xE8) Write Protection Status Register -------- */




/*@}*/
# 292 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_ssc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Synchronous Serial Controller */
/* ============================================================================= */
/** \addtogroup SAM3XA_SSC Synchronous Serial Controller */
/*@{*/


/** \brief Ssc hardware registers */
typedef struct {
  WoReg SSC_CR; /**< \brief (Ssc Offset: 0x0) Control Register */
  RwReg SSC_CMR; /**< \brief (Ssc Offset: 0x4) Clock Mode Register */
  RoReg Reserved1[2];
  RwReg SSC_RCMR; /**< \brief (Ssc Offset: 0x10) Receive Clock Mode Register */
  RwReg SSC_RFMR; /**< \brief (Ssc Offset: 0x14) Receive Frame Mode Register */
  RwReg SSC_TCMR; /**< \brief (Ssc Offset: 0x18) Transmit Clock Mode Register */
  RwReg SSC_TFMR; /**< \brief (Ssc Offset: 0x1C) Transmit Frame Mode Register */
  RoReg SSC_RHR; /**< \brief (Ssc Offset: 0x20) Receive Holding Register */
  WoReg SSC_THR; /**< \brief (Ssc Offset: 0x24) Transmit Holding Register */
  RoReg Reserved2[2];
  RoReg SSC_RSHR; /**< \brief (Ssc Offset: 0x30) Receive Sync. Holding Register */
  RwReg SSC_TSHR; /**< \brief (Ssc Offset: 0x34) Transmit Sync. Holding Register */
  RwReg SSC_RC0R; /**< \brief (Ssc Offset: 0x38) Receive Compare 0 Register */
  RwReg SSC_RC1R; /**< \brief (Ssc Offset: 0x3C) Receive Compare 1 Register */
  RoReg SSC_SR; /**< \brief (Ssc Offset: 0x40) Status Register */
  WoReg SSC_IER; /**< \brief (Ssc Offset: 0x44) Interrupt Enable Register */
  WoReg SSC_IDR; /**< \brief (Ssc Offset: 0x48) Interrupt Disable Register */
  RoReg SSC_IMR; /**< \brief (Ssc Offset: 0x4C) Interrupt Mask Register */
  RoReg Reserved3[37];
  RwReg SSC_WPMR; /**< \brief (Ssc Offset: 0xE4) Write Protect Mode Register */
  RoReg SSC_WPSR; /**< \brief (Ssc Offset: 0xE8) Write Protect Status Register */
} Ssc;

/* -------- SSC_CR : (SSC Offset: 0x0) Control Register -------- */





/* -------- SSC_CMR : (SSC Offset: 0x4) Clock Mode Register -------- */



/* -------- SSC_RCMR : (SSC Offset: 0x10) Receive Clock Mode Register -------- */
# 110 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_ssc.h"
/* -------- SSC_RFMR : (SSC Offset: 0x14) Receive Frame Mode Register -------- */
# 136 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_ssc.h"
/* -------- SSC_TCMR : (SSC Offset: 0x18) Transmit Clock Mode Register -------- */
# 170 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_ssc.h"
/* -------- SSC_TFMR : (SSC Offset: 0x1C) Transmit Frame Mode Register -------- */
# 197 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_ssc.h"
/* -------- SSC_RHR : (SSC Offset: 0x20) Receive Holding Register -------- */


/* -------- SSC_THR : (SSC Offset: 0x24) Transmit Holding Register -------- */



/* -------- SSC_RSHR : (SSC Offset: 0x30) Receive Sync. Holding Register -------- */


/* -------- SSC_TSHR : (SSC Offset: 0x34) Transmit Sync. Holding Register -------- */



/* -------- SSC_RC0R : (SSC Offset: 0x38) Receive Compare 0 Register -------- */



/* -------- SSC_RC1R : (SSC Offset: 0x3C) Receive Compare 1 Register -------- */



/* -------- SSC_SR : (SSC Offset: 0x40) Status Register -------- */
# 230 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_ssc.h"
/* -------- SSC_IER : (SSC Offset: 0x44) Interrupt Enable Register -------- */
# 239 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_ssc.h"
/* -------- SSC_IDR : (SSC Offset: 0x48) Interrupt Disable Register -------- */
# 248 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_ssc.h"
/* -------- SSC_IMR : (SSC Offset: 0x4C) Interrupt Mask Register -------- */
# 257 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_ssc.h"
/* -------- SSC_WPMR : (SSC Offset: 0xE4) Write Protect Mode Register -------- */




/* -------- SSC_WPSR : (SSC Offset: 0xE8) Write Protect Status Register -------- */




/*@}*/
# 293 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_supc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Supply Controller */
/* ============================================================================= */
/** \addtogroup SAM3XA_SUPC Supply Controller */
/*@{*/


/** \brief Supc hardware registers */
typedef struct {
  WoReg SUPC_CR; /**< \brief (Supc Offset: 0x00) Supply Controller Control Register */
  RwReg SUPC_SMMR; /**< \brief (Supc Offset: 0x04) Supply Controller Supply Monitor Mode Register */
  RwReg SUPC_MR; /**< \brief (Supc Offset: 0x08) Supply Controller Mode Register */
  RwReg SUPC_WUMR; /**< \brief (Supc Offset: 0x0C) Supply Controller Wake Up Mode Register */
  RwReg SUPC_WUIR; /**< \brief (Supc Offset: 0x10) Supply Controller Wake Up Inputs Register */
  RoReg SUPC_SR; /**< \brief (Supc Offset: 0x14) Supply Controller Status Register */
} Supc;

/* -------- SUPC_CR : (SUPC Offset: 0x00) Supply Controller Control Register -------- */
# 60 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_supc.h"
/* -------- SUPC_SMMR : (SUPC Offset: 0x04) Supply Controller Supply Monitor Mode Register -------- */
# 92 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_supc.h"
/* -------- SUPC_MR : (SUPC Offset: 0x08) Supply Controller Mode Register -------- */
# 106 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_supc.h"
/* -------- SUPC_WUMR : (SUPC Offset: 0x0C) Supply Controller Wake Up Mode Register -------- */
# 135 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_supc.h"
/* -------- SUPC_WUIR : (SUPC Offset: 0x10) Supply Controller Wake Up Inputs Register -------- */
# 232 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_supc.h"
/* -------- SUPC_SR : (SUPC Offset: 0x14) Supply Controller Status Register -------- */
# 309 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_supc.h"
/*@}*/
# 294 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_tc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Timer Counter */
/* ============================================================================= */
/** \addtogroup SAM3XA_TC Timer Counter */
/*@{*/


/** \brief TcChannel hardware registers */
typedef struct {
  RwReg TC_CCR; /**< \brief (TcChannel Offset: 0x0) Channel Control Register */
  RwReg TC_CMR; /**< \brief (TcChannel Offset: 0x4) Channel Mode Register */
  RwReg TC_SMMR; /**< \brief (TcChannel Offset: 0x8) Stepper Motor Mode Register */
  RoReg Reserved1[1];
  RwReg TC_CV; /**< \brief (TcChannel Offset: 0x10) Counter Value */
  RwReg TC_RA; /**< \brief (TcChannel Offset: 0x14) Register A */
  RwReg TC_RB; /**< \brief (TcChannel Offset: 0x18) Register B */
  RwReg TC_RC; /**< \brief (TcChannel Offset: 0x1C) Register C */
  RwReg TC_SR; /**< \brief (TcChannel Offset: 0x20) Status Register */
  RwReg TC_IER; /**< \brief (TcChannel Offset: 0x24) Interrupt Enable Register */
  RwReg TC_IDR; /**< \brief (TcChannel Offset: 0x28) Interrupt Disable Register */
  RwReg TC_IMR; /**< \brief (TcChannel Offset: 0x2C) Interrupt Mask Register */
  RoReg Reserved2[4];
} TcChannel;
/** \brief Tc hardware registers */

typedef struct {
  TcChannel TC_CHANNEL[3]; /**< \brief (Tc Offset: 0x0) channel = 0 .. 2 */
  WoReg TC_BCR; /**< \brief (Tc Offset: 0xC0) Block Control Register */
  RwReg TC_BMR; /**< \brief (Tc Offset: 0xC4) Block Mode Register */
  WoReg TC_QIER; /**< \brief (Tc Offset: 0xC8) QDEC Interrupt Enable Register */
  WoReg TC_QIDR; /**< \brief (Tc Offset: 0xCC) QDEC Interrupt Disable Register */
  RoReg TC_QIMR; /**< \brief (Tc Offset: 0xD0) QDEC Interrupt Mask Register */
  RoReg TC_QISR; /**< \brief (Tc Offset: 0xD4) QDEC Interrupt Status Register */
  RwReg TC_FMR; /**< \brief (Tc Offset: 0xD8) Fault Mode Register */
  RoReg Reserved1[2];
  RwReg TC_WPMR; /**< \brief (Tc Offset: 0xE4) Write Protect Mode Register */
} Tc;

/* -------- TC_CCR : (TC Offset: N/A) Channel Control Register -------- */



/* -------- TC_CMR : (TC Offset: N/A) Channel Mode Register -------- */
# 185 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_tc.h"
/* -------- TC_SMMR : (TC Offset: N/A) Stepper Motor Mode Register -------- */


/* -------- TC_CV : (TC Offset: N/A) Counter Value -------- */


/* -------- TC_RA : (TC Offset: N/A) Register A -------- */



/* -------- TC_RB : (TC Offset: N/A) Register B -------- */



/* -------- TC_RC : (TC Offset: N/A) Register C -------- */



/* -------- TC_SR : (TC Offset: N/A) Status Register -------- */
# 215 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_tc.h"
/* -------- TC_IER : (TC Offset: N/A) Interrupt Enable Register -------- */
# 224 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_tc.h"
/* -------- TC_IDR : (TC Offset: N/A) Interrupt Disable Register -------- */
# 233 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_tc.h"
/* -------- TC_IMR : (TC Offset: N/A) Interrupt Mask Register -------- */
# 242 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_tc.h"
/* -------- TC_BCR : (TC Offset: 0xC0) Block Control Register -------- */

/* -------- TC_BMR : (TC Offset: 0xC4) Block Mode Register -------- */
# 274 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_tc.h"
/* -------- TC_QIER : (TC Offset: 0xC8) QDEC Interrupt Enable Register -------- */



/* -------- TC_QIDR : (TC Offset: 0xCC) QDEC Interrupt Disable Register -------- */



/* -------- TC_QIMR : (TC Offset: 0xD0) QDEC Interrupt Mask Register -------- */



/* -------- TC_QISR : (TC Offset: 0xD4) QDEC Interrupt Status Register -------- */




/* -------- TC_FMR : (TC Offset: 0xD8) Fault Mode Register -------- */


/* -------- TC_WPMR : (TC Offset: 0xE4) Write Protect Mode Register -------- */





/*@}*/
# 295 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_trng.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR True Random Number Generator */
/* ============================================================================= */
/** \addtogroup SAM3XA_TRNG True Random Number Generator */
/*@{*/


/** \brief Trng hardware registers */
typedef struct {
  WoReg TRNG_CR; /**< \brief (Trng Offset: 0x00) Control Register */
  RoReg Reserved1[3];
  WoReg TRNG_IER; /**< \brief (Trng Offset: 0x10) Interrupt Enable Register */
  WoReg TRNG_IDR; /**< \brief (Trng Offset: 0x14) Interrupt Disable Register */
  RoReg TRNG_IMR; /**< \brief (Trng Offset: 0x18) Interrupt Mask Register */
  RoReg TRNG_ISR; /**< \brief (Trng Offset: 0x1C) Interrupt Status Register */
  RoReg Reserved2[12];
  RoReg TRNG_ODATA; /**< \brief (Trng Offset: 0x50) Output Data Register */
} Trng;

/* -------- TRNG_CR : (TRNG Offset: 0x00) Control Register -------- */




/* -------- TRNG_IER : (TRNG Offset: 0x10) Interrupt Enable Register -------- */

/* -------- TRNG_IDR : (TRNG Offset: 0x14) Interrupt Disable Register -------- */

/* -------- TRNG_IMR : (TRNG Offset: 0x18) Interrupt Mask Register -------- */

/* -------- TRNG_ISR : (TRNG Offset: 0x1C) Interrupt Status Register -------- */

/* -------- TRNG_ODATA : (TRNG Offset: 0x50) Output Data Register -------- */



/*@}*/
# 296 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_twi.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Two-wire Interface */
/* ============================================================================= */
/** \addtogroup SAM3XA_TWI Two-wire Interface */
/*@{*/


/** \brief Twi hardware registers */
typedef struct {
  WoReg TWI_CR; /**< \brief (Twi Offset: 0x00) Control Register */
  RwReg TWI_MMR; /**< \brief (Twi Offset: 0x04) Master Mode Register */
  RwReg TWI_SMR; /**< \brief (Twi Offset: 0x08) Slave Mode Register */
  RwReg TWI_IADR; /**< \brief (Twi Offset: 0x0C) Internal Address Register */
  RwReg TWI_CWGR; /**< \brief (Twi Offset: 0x10) Clock Waveform Generator Register */
  RoReg Reserved1[3];
  RoReg TWI_SR; /**< \brief (Twi Offset: 0x20) Status Register */
  WoReg TWI_IER; /**< \brief (Twi Offset: 0x24) Interrupt Enable Register */
  WoReg TWI_IDR; /**< \brief (Twi Offset: 0x28) Interrupt Disable Register */
  RoReg TWI_IMR; /**< \brief (Twi Offset: 0x2C) Interrupt Mask Register */
  RoReg TWI_RHR; /**< \brief (Twi Offset: 0x30) Receive Holding Register */
  WoReg TWI_THR; /**< \brief (Twi Offset: 0x34) Transmit Holding Register */
  RoReg Reserved2[50];
  RwReg TWI_RPR; /**< \brief (Twi Offset: 0x100) Receive Pointer Register */
  RwReg TWI_RCR; /**< \brief (Twi Offset: 0x104) Receive Counter Register */
  RwReg TWI_TPR; /**< \brief (Twi Offset: 0x108) Transmit Pointer Register */
  RwReg TWI_TCR; /**< \brief (Twi Offset: 0x10C) Transmit Counter Register */
  RwReg TWI_RNPR; /**< \brief (Twi Offset: 0x110) Receive Next Pointer Register */
  RwReg TWI_RNCR; /**< \brief (Twi Offset: 0x114) Receive Next Counter Register */
  RwReg TWI_TNPR; /**< \brief (Twi Offset: 0x118) Transmit Next Pointer Register */
  RwReg TWI_TNCR; /**< \brief (Twi Offset: 0x11C) Transmit Next Counter Register */
  WoReg TWI_PTCR; /**< \brief (Twi Offset: 0x120) Transfer Control Register */
  RoReg TWI_PTSR; /**< \brief (Twi Offset: 0x124) Transfer Status Register */
} Twi;

/* -------- TWI_CR : (TWI Offset: 0x00) Control Register -------- */
# 76 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_twi.h"
/* -------- TWI_MMR : (TWI Offset: 0x04) Master Mode Register -------- */
# 87 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_twi.h"
/* -------- TWI_SMR : (TWI Offset: 0x08) Slave Mode Register -------- */



/* -------- TWI_IADR : (TWI Offset: 0x0C) Internal Address Register -------- */



/* -------- TWI_CWGR : (TWI Offset: 0x10) Clock Waveform Generator Register -------- */
# 105 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_twi.h"
/* -------- TWI_SR : (TWI Offset: 0x20) Status Register -------- */
# 121 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_twi.h"
/* -------- TWI_IER : (TWI Offset: 0x24) Interrupt Enable Register -------- */
# 136 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_twi.h"
/* -------- TWI_IDR : (TWI Offset: 0x28) Interrupt Disable Register -------- */
# 151 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_twi.h"
/* -------- TWI_IMR : (TWI Offset: 0x2C) Interrupt Mask Register -------- */
# 166 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_twi.h"
/* -------- TWI_RHR : (TWI Offset: 0x30) Receive Holding Register -------- */


/* -------- TWI_THR : (TWI Offset: 0x34) Transmit Holding Register -------- */



/* -------- TWI_RPR : (TWI Offset: 0x100) Receive Pointer Register -------- */



/* -------- TWI_RCR : (TWI Offset: 0x104) Receive Counter Register -------- */



/* -------- TWI_TPR : (TWI Offset: 0x108) Transmit Pointer Register -------- */



/* -------- TWI_TCR : (TWI Offset: 0x10C) Transmit Counter Register -------- */



/* -------- TWI_RNPR : (TWI Offset: 0x110) Receive Next Pointer Register -------- */



/* -------- TWI_RNCR : (TWI Offset: 0x114) Receive Next Counter Register -------- */



/* -------- TWI_TNPR : (TWI Offset: 0x118) Transmit Next Pointer Register -------- */



/* -------- TWI_TNCR : (TWI Offset: 0x11C) Transmit Next Counter Register -------- */



/* -------- TWI_PTCR : (TWI Offset: 0x120) Transfer Control Register -------- */




/* -------- TWI_PTSR : (TWI Offset: 0x124) Transfer Status Register -------- */



/*@}*/
# 297 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uart.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Universal Asynchronous Receiver Transmitter */
/* ============================================================================= */
/** \addtogroup SAM3XA_UART Universal Asynchronous Receiver Transmitter */
/*@{*/


/** \brief Uart hardware registers */
typedef struct {
  WoReg UART_CR; /**< \brief (Uart Offset: 0x0000) Control Register */
  RwReg UART_MR; /**< \brief (Uart Offset: 0x0004) Mode Register */
  WoReg UART_IER; /**< \brief (Uart Offset: 0x0008) Interrupt Enable Register */
  WoReg UART_IDR; /**< \brief (Uart Offset: 0x000C) Interrupt Disable Register */
  RoReg UART_IMR; /**< \brief (Uart Offset: 0x0010) Interrupt Mask Register */
  RoReg UART_SR; /**< \brief (Uart Offset: 0x0014) Status Register */
  RoReg UART_RHR; /**< \brief (Uart Offset: 0x0018) Receive Holding Register */
  WoReg UART_THR; /**< \brief (Uart Offset: 0x001C) Transmit Holding Register */
  RwReg UART_BRGR; /**< \brief (Uart Offset: 0x0020) Baud Rate Generator Register */
  RoReg Reserved1[55];
  RwReg UART_RPR; /**< \brief (Uart Offset: 0x100) Receive Pointer Register */
  RwReg UART_RCR; /**< \brief (Uart Offset: 0x104) Receive Counter Register */
  RwReg UART_TPR; /**< \brief (Uart Offset: 0x108) Transmit Pointer Register */
  RwReg UART_TCR; /**< \brief (Uart Offset: 0x10C) Transmit Counter Register */
  RwReg UART_RNPR; /**< \brief (Uart Offset: 0x110) Receive Next Pointer Register */
  RwReg UART_RNCR; /**< \brief (Uart Offset: 0x114) Receive Next Counter Register */
  RwReg UART_TNPR; /**< \brief (Uart Offset: 0x118) Transmit Next Pointer Register */
  RwReg UART_TNCR; /**< \brief (Uart Offset: 0x11C) Transmit Next Counter Register */
  WoReg UART_PTCR; /**< \brief (Uart Offset: 0x120) Transfer Control Register */
  RoReg UART_PTSR; /**< \brief (Uart Offset: 0x124) Transfer Status Register */
} Uart;

/* -------- UART_CR : (UART Offset: 0x0000) Control Register -------- */







/* -------- UART_MR : (UART Offset: 0x0004) Mode Register -------- */
# 86 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uart.h"
/* -------- UART_IER : (UART Offset: 0x0008) Interrupt Enable Register -------- */
# 97 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uart.h"
/* -------- UART_IDR : (UART Offset: 0x000C) Interrupt Disable Register -------- */
# 108 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uart.h"
/* -------- UART_IMR : (UART Offset: 0x0010) Interrupt Mask Register -------- */
# 119 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uart.h"
/* -------- UART_SR : (UART Offset: 0x0014) Status Register -------- */
# 130 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uart.h"
/* -------- UART_RHR : (UART Offset: 0x0018) Receive Holding Register -------- */


/* -------- UART_THR : (UART Offset: 0x001C) Transmit Holding Register -------- */



/* -------- UART_BRGR : (UART Offset: 0x0020) Baud Rate Generator Register -------- */



/* -------- UART_RPR : (UART Offset: 0x100) Receive Pointer Register -------- */



/* -------- UART_RCR : (UART Offset: 0x104) Receive Counter Register -------- */



/* -------- UART_TPR : (UART Offset: 0x108) Transmit Pointer Register -------- */



/* -------- UART_TCR : (UART Offset: 0x10C) Transmit Counter Register -------- */



/* -------- UART_RNPR : (UART Offset: 0x110) Receive Next Pointer Register -------- */



/* -------- UART_RNCR : (UART Offset: 0x114) Receive Next Counter Register -------- */



/* -------- UART_TNPR : (UART Offset: 0x118) Transmit Next Pointer Register -------- */



/* -------- UART_TNCR : (UART Offset: 0x11C) Transmit Next Counter Register -------- */



/* -------- UART_PTCR : (UART Offset: 0x120) Transfer Control Register -------- */




/* -------- UART_PTSR : (UART Offset: 0x124) Transfer Status Register -------- */



/*@}*/
# 298 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR USB On-The-Go Interface */
/* ============================================================================= */
/** \addtogroup SAM3XA_UOTGHS USB On-The-Go Interface */
/*@{*/


/** \brief UotghsDevdma hardware registers */
typedef struct {
  RwReg UOTGHS_DEVDMANXTDSC; /**< \brief (UotghsDevdma Offset: 0x0) Device DMA Channel Next Descriptor Address Register */
  RwReg UOTGHS_DEVDMAADDRESS; /**< \brief (UotghsDevdma Offset: 0x4) Device DMA Channel Address Register */
  RwReg UOTGHS_DEVDMACONTROL; /**< \brief (UotghsDevdma Offset: 0x8) Device DMA Channel Control Register */
  RwReg UOTGHS_DEVDMASTATUS; /**< \brief (UotghsDevdma Offset: 0xC) Device DMA Channel Status Register */
} UotghsDevdma;
/** \brief UotghsHstdma hardware registers */
typedef struct {
  RwReg UOTGHS_HSTDMANXTDSC; /**< \brief (UotghsHstdma Offset: 0x0) Host DMA Channel Next Descriptor Address Register */
  RwReg UOTGHS_HSTDMAADDRESS; /**< \brief (UotghsHstdma Offset: 0x4) Host DMA Channel Address Register */
  RwReg UOTGHS_HSTDMACONTROL; /**< \brief (UotghsHstdma Offset: 0x8) Host DMA Channel Control Register */
  RwReg UOTGHS_HSTDMASTATUS; /**< \brief (UotghsHstdma Offset: 0xC) Host DMA Channel Status Register */
} UotghsHstdma;
/** \brief Uotghs hardware registers */


typedef struct {
  RwReg UOTGHS_DEVCTRL; /**< \brief (Uotghs Offset: 0x0000) Device General Control Register */
  RoReg UOTGHS_DEVISR; /**< \brief (Uotghs Offset: 0x0004) Device Global Interrupt Status Register */
  WoReg UOTGHS_DEVICR; /**< \brief (Uotghs Offset: 0x0008) Device Global Interrupt Clear Register */
  WoReg UOTGHS_DEVIFR; /**< \brief (Uotghs Offset: 0x000C) Device Global Interrupt Set Register */
  RoReg UOTGHS_DEVIMR; /**< \brief (Uotghs Offset: 0x0010) Device Global Interrupt Mask Register */
  WoReg UOTGHS_DEVIDR; /**< \brief (Uotghs Offset: 0x0014) Device Global Interrupt Disable Register */
  WoReg UOTGHS_DEVIER; /**< \brief (Uotghs Offset: 0x0018) Device Global Interrupt Enable Register */
  RwReg UOTGHS_DEVEPT; /**< \brief (Uotghs Offset: 0x001C) Device Endpoint Register */
  RoReg UOTGHS_DEVFNUM; /**< \brief (Uotghs Offset: 0x0020) Device Frame Number Register */
  RoReg Reserved1[55];
  RwReg UOTGHS_DEVEPTCFG[10]; /**< \brief (Uotghs Offset: 0x100) Device Endpoint Configuration Register (n = 0) */
  RoReg Reserved2[2];
  RoReg UOTGHS_DEVEPTISR[10]; /**< \brief (Uotghs Offset: 0x130) Device Endpoint Status Register (n = 0) */
  RoReg Reserved3[2];
  WoReg UOTGHS_DEVEPTICR[10]; /**< \brief (Uotghs Offset: 0x160) Device Endpoint Clear Register (n = 0) */
  RoReg Reserved4[2];
  WoReg UOTGHS_DEVEPTIFR[10]; /**< \brief (Uotghs Offset: 0x190) Device Endpoint Set Register (n = 0) */
  RoReg Reserved5[2];
  RoReg UOTGHS_DEVEPTIMR[10]; /**< \brief (Uotghs Offset: 0x1C0) Device Endpoint Mask Register (n = 0) */
  RoReg Reserved6[2];
  WoReg UOTGHS_DEVEPTIER[10]; /**< \brief (Uotghs Offset: 0x1F0) Device Endpoint Enable Register (n = 0) */
  RoReg Reserved7[2];
  WoReg UOTGHS_DEVEPTIDR[10]; /**< \brief (Uotghs Offset: 0x220) Device Endpoint Disable Register (n = 0) */
  RoReg Reserved8[50];
  UotghsDevdma UOTGHS_DEVDMA[7]; /**< \brief (Uotghs Offset: 0x310) n = 1 .. 7 */
  RoReg Reserved9[32];
  RwReg UOTGHS_HSTCTRL; /**< \brief (Uotghs Offset: 0x0400) Host General Control Register */
  RoReg UOTGHS_HSTISR; /**< \brief (Uotghs Offset: 0x0404) Host Global Interrupt Status Register */
  WoReg UOTGHS_HSTICR; /**< \brief (Uotghs Offset: 0x0408) Host Global Interrupt Clear Register */
  WoReg UOTGHS_HSTIFR; /**< \brief (Uotghs Offset: 0x040C) Host Global Interrupt Set Register */
  RoReg UOTGHS_HSTIMR; /**< \brief (Uotghs Offset: 0x0410) Host Global Interrupt Mask Register */
  WoReg UOTGHS_HSTIDR; /**< \brief (Uotghs Offset: 0x0414) Host Global Interrupt Disable Register */
  WoReg UOTGHS_HSTIER; /**< \brief (Uotghs Offset: 0x0418) Host Global Interrupt Enable Register */
  RwReg UOTGHS_HSTPIP; /**< \brief (Uotghs Offset: 0x0041C) Host Pipe Register */
  RwReg UOTGHS_HSTFNUM; /**< \brief (Uotghs Offset: 0x0420) Host Frame Number Register */
  RwReg UOTGHS_HSTADDR1; /**< \brief (Uotghs Offset: 0x0424) Host Address 1 Register */
  RwReg UOTGHS_HSTADDR2; /**< \brief (Uotghs Offset: 0x0428) Host Address 2 Register */
  RwReg UOTGHS_HSTADDR3; /**< \brief (Uotghs Offset: 0x042C) Host Address 3 Register */
  RoReg Reserved10[52];
  RwReg UOTGHS_HSTPIPCFG[10]; /**< \brief (Uotghs Offset: 0x500) Host Pipe Configuration Register (n = 0) */
  RoReg Reserved11[2];
  RoReg UOTGHS_HSTPIPISR[10]; /**< \brief (Uotghs Offset: 0x530) Host Pipe Status Register (n = 0) */
  RoReg Reserved12[2];
  WoReg UOTGHS_HSTPIPICR[10]; /**< \brief (Uotghs Offset: 0x560) Host Pipe Clear Register (n = 0) */
  RoReg Reserved13[2];
  WoReg UOTGHS_HSTPIPIFR[10]; /**< \brief (Uotghs Offset: 0x590) Host Pipe Set Register (n = 0) */
  RoReg Reserved14[2];
  RoReg UOTGHS_HSTPIPIMR[10]; /**< \brief (Uotghs Offset: 0x5C0) Host Pipe Mask Register (n = 0) */
  RoReg Reserved15[2];
  WoReg UOTGHS_HSTPIPIER[10]; /**< \brief (Uotghs Offset: 0x5F0) Host Pipe Enable Register (n = 0) */
  RoReg Reserved16[2];
  WoReg UOTGHS_HSTPIPIDR[10]; /**< \brief (Uotghs Offset: 0x620) Host Pipe Disable Register (n = 0) */
  RoReg Reserved17[2];
  RwReg UOTGHS_HSTPIPINRQ[10]; /**< \brief (Uotghs Offset: 0x650) Host Pipe IN Request Register (n = 0) */
  RoReg Reserved18[2];
  RwReg UOTGHS_HSTPIPERR[10]; /**< \brief (Uotghs Offset: 0x680) Host Pipe Error Register (n = 0) */
  RoReg Reserved19[26];
  UotghsHstdma UOTGHS_HSTDMA[7]; /**< \brief (Uotghs Offset: 0x710) n = 1 .. 7 */
  RoReg Reserved20[32];
  RwReg UOTGHS_CTRL; /**< \brief (Uotghs Offset: 0x0800) General Control Register */
  RoReg UOTGHS_SR; /**< \brief (Uotghs Offset: 0x0804) General Status Register */
  WoReg UOTGHS_SCR; /**< \brief (Uotghs Offset: 0x0808) General Status Clear Register */
  WoReg UOTGHS_SFR; /**< \brief (Uotghs Offset: 0x080C) General Status Set Register */
  RoReg Reserved21[7];
  RoReg UOTGHS_FSM; /**< \brief (Uotghs Offset: 0x082C) General Finite State Machine Register */
} Uotghs;

/* -------- UOTGHS_DEVCTRL : (UOTGHS Offset: 0x0000) Device General Control Register -------- */
# 143 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_DEVISR : (UOTGHS Offset: 0x0004) Device Global Interrupt Status Register -------- */
# 167 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_DEVICR : (UOTGHS Offset: 0x0008) Device Global Interrupt Clear Register -------- */







/* -------- UOTGHS_DEVIFR : (UOTGHS Offset: 0x000C) Device Global Interrupt Set Register -------- */
# 189 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_DEVIMR : (UOTGHS Offset: 0x0010) Device Global Interrupt Mask Register -------- */
# 213 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_DEVIDR : (UOTGHS Offset: 0x0014) Device Global Interrupt Disable Register -------- */
# 237 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_DEVIER : (UOTGHS Offset: 0x0018) Device Global Interrupt Enable Register -------- */
# 261 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_DEVEPT : (UOTGHS Offset: 0x001C) Device Endpoint Register -------- */
# 280 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_DEVFNUM : (UOTGHS Offset: 0x0020) Device Frame Number Register -------- */





/* -------- UOTGHS_DEVEPTCFG[10] : (UOTGHS Offset: 0x100) Device Endpoint Configuration Register (n = 0) -------- */
# 319 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_DEVEPTISR[10] : (UOTGHS Offset: 0x130) Device Endpoint Status Register (n = 0) -------- */
# 355 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_DEVEPTICR[10] : (UOTGHS Offset: 0x160) Device Endpoint Clear Register (n = 0) -------- */
# 368 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_DEVEPTIFR[10] : (UOTGHS Offset: 0x190) Device Endpoint Set Register (n = 0) -------- */
# 382 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_DEVEPTIMR[10] : (UOTGHS Offset: 0x1C0) Device Endpoint Mask Register (n = 0) -------- */
# 405 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_DEVEPTIER[10] : (UOTGHS Offset: 0x1F0) Device Endpoint Enable Register (n = 0) -------- */
# 427 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_DEVEPTIDR[10] : (UOTGHS Offset: 0x220) Device Endpoint Disable Register (n = 0) -------- */
# 448 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_DEVDMANXTDSC : (UOTGHS Offset: N/A) Device DMA Channel Next Descriptor Address Register -------- */



/* -------- UOTGHS_DEVDMAADDRESS : (UOTGHS Offset: N/A) Device DMA Channel Address Register -------- */



/* -------- UOTGHS_DEVDMACONTROL : (UOTGHS Offset: N/A) Device DMA Channel Control Register -------- */
# 468 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_DEVDMASTATUS : (UOTGHS Offset: N/A) Device DMA Channel Status Register -------- */
# 477 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_HSTCTRL : (UOTGHS Offset: 0x0400) Host General Control Register -------- */
# 487 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_HSTISR : (UOTGHS Offset: 0x0404) Host Global Interrupt Status Register -------- */
# 511 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_HSTICR : (UOTGHS Offset: 0x0408) Host Global Interrupt Clear Register -------- */







/* -------- UOTGHS_HSTIFR : (UOTGHS Offset: 0x040C) Host Global Interrupt Set Register -------- */
# 533 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_HSTIMR : (UOTGHS Offset: 0x0410) Host Global Interrupt Mask Register -------- */
# 557 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_HSTIDR : (UOTGHS Offset: 0x0414) Host Global Interrupt Disable Register -------- */
# 581 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_HSTIER : (UOTGHS Offset: 0x0418) Host Global Interrupt Enable Register -------- */
# 605 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_HSTPIP : (UOTGHS Offset: 0x0041C) Host Pipe Register -------- */
# 624 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_HSTFNUM : (UOTGHS Offset: 0x0420) Host Frame Number Register -------- */
# 634 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_HSTADDR1 : (UOTGHS Offset: 0x0424) Host Address 1 Register -------- */
# 647 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_HSTADDR2 : (UOTGHS Offset: 0x0428) Host Address 2 Register -------- */
# 660 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_HSTADDR3 : (UOTGHS Offset: 0x042C) Host Address 3 Register -------- */






/* -------- UOTGHS_HSTPIPCFG[10] : (UOTGHS Offset: 0x500) Host Pipe Configuration Register (n = 0) -------- */
# 706 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_HSTPIPISR[10] : (UOTGHS Offset: 0x530) Host Pipe Status Register (n = 0) -------- */
# 736 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_HSTPIPICR[10] : (UOTGHS Offset: 0x560) Host Pipe Clear Register (n = 0) -------- */
# 746 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_HSTPIPIFR[10] : (UOTGHS Offset: 0x590) Host Pipe Set Register (n = 0) -------- */
# 758 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_HSTPIPIMR[10] : (UOTGHS Offset: 0x5C0) Host Pipe Mask Register (n = 0) -------- */
# 774 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_HSTPIPIER[10] : (UOTGHS Offset: 0x5F0) Host Pipe Enable Register (n = 0) -------- */
# 789 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_HSTPIPIDR[10] : (UOTGHS Offset: 0x620) Host Pipe Disable Register (n = 0) -------- */
# 804 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_HSTPIPINRQ[10] : (UOTGHS Offset: 0x650) Host Pipe IN Request Register (n = 0) -------- */




/* -------- UOTGHS_HSTPIPERR[10] : (UOTGHS Offset: 0x680) Host Pipe Error Register (n = 0) -------- */
# 818 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_HSTDMANXTDSC : (UOTGHS Offset: N/A) Host DMA Channel Next Descriptor Address Register -------- */



/* -------- UOTGHS_HSTDMAADDRESS : (UOTGHS Offset: N/A) Host DMA Channel Address Register -------- */



/* -------- UOTGHS_HSTDMACONTROL : (UOTGHS Offset: N/A) Host DMA Channel Control Register -------- */
# 838 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_HSTDMASTATUS : (UOTGHS Offset: N/A) Host DMA Channel Status Register -------- */
# 847 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_CTRL : (UOTGHS Offset: 0x0800) General Control Register -------- */
# 877 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_SR : (UOTGHS Offset: 0x0804) General Status Register -------- */
# 895 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_SCR : (UOTGHS Offset: 0x0808) General Status Clear Register -------- */
# 905 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_SFR : (UOTGHS Offset: 0x080C) General Status Set Register -------- */
# 915 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/* -------- UOTGHS_FSM : (UOTGHS Offset: 0x082C) General Finite State Machine Register -------- */
# 935 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h"
/*@}*/
# 299 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_usart.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Universal Synchronous Asynchronous Receiver Transmitter */
/* ============================================================================= */
/** \addtogroup SAM3XA_USART Universal Synchronous Asynchronous Receiver Transmitter */
/*@{*/


/** \brief Usart hardware registers */
typedef struct {
  WoReg US_CR; /**< \brief (Usart Offset: 0x0000) Control Register */
  RwReg US_MR; /**< \brief (Usart Offset: 0x0004) Mode Register */
  WoReg US_IER; /**< \brief (Usart Offset: 0x0008) Interrupt Enable Register */
  WoReg US_IDR; /**< \brief (Usart Offset: 0x000C) Interrupt Disable Register */
  RoReg US_IMR; /**< \brief (Usart Offset: 0x0010) Interrupt Mask Register */
  RoReg US_CSR; /**< \brief (Usart Offset: 0x0014) Channel Status Register */
  RoReg US_RHR; /**< \brief (Usart Offset: 0x0018) Receiver Holding Register */
  WoReg US_THR; /**< \brief (Usart Offset: 0x001C) Transmitter Holding Register */
  RwReg US_BRGR; /**< \brief (Usart Offset: 0x0020) Baud Rate Generator Register */
  RwReg US_RTOR; /**< \brief (Usart Offset: 0x0024) Receiver Time-out Register */
  RwReg US_TTGR; /**< \brief (Usart Offset: 0x0028) Transmitter Timeguard Register */
  RoReg Reserved1[5];
  RwReg US_FIDI; /**< \brief (Usart Offset: 0x0040) FI DI Ratio Register */
  RoReg US_NER; /**< \brief (Usart Offset: 0x0044) Number of Errors Register */
  RoReg Reserved2[1];
  RwReg US_IF; /**< \brief (Usart Offset: 0x004C) IrDA Filter Register */
  RwReg US_MAN; /**< \brief (Usart Offset: 0x0050) Manchester Encoder Decoder Register */
  RwReg US_LINMR; /**< \brief (Usart Offset: 0x0054) LIN Mode Register */
  RwReg US_LINIR; /**< \brief (Usart Offset: 0x0058) LIN Identifier Register */
  RoReg Reserved3[34];
  RwReg US_WPMR; /**< \brief (Usart Offset: 0xE4) Write Protect Mode Register */
  RoReg US_WPSR; /**< \brief (Usart Offset: 0xE8) Write Protect Status Register */
  RoReg Reserved4[5];
  RwReg US_RPR; /**< \brief (Usart Offset: 0x100) Receive Pointer Register */
  RwReg US_RCR; /**< \brief (Usart Offset: 0x104) Receive Counter Register */
  RwReg US_TPR; /**< \brief (Usart Offset: 0x108) Transmit Pointer Register */
  RwReg US_TCR; /**< \brief (Usart Offset: 0x10C) Transmit Counter Register */
  RwReg US_RNPR; /**< \brief (Usart Offset: 0x110) Receive Next Pointer Register */
  RwReg US_RNCR; /**< \brief (Usart Offset: 0x114) Receive Next Counter Register */
  RwReg US_TNPR; /**< \brief (Usart Offset: 0x118) Transmit Next Pointer Register */
  RwReg US_TNCR; /**< \brief (Usart Offset: 0x11C) Transmit Next Counter Register */
  WoReg US_PTCR; /**< \brief (Usart Offset: 0x120) Transfer Control Register */
  RoReg US_PTSR; /**< \brief (Usart Offset: 0x124) Transfer Status Register */
} Usart;

/* -------- US_CR : (USART Offset: 0x0000) Control Register -------- */
# 98 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_usart.h"
/* -------- US_MR : (USART Offset: 0x0004) Mode Register -------- */
# 159 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_usart.h"
/* -------- US_IER : (USART Offset: 0x0008) Interrupt Enable Register -------- */
# 185 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_usart.h"
/* -------- US_IDR : (USART Offset: 0x000C) Interrupt Disable Register -------- */
# 211 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_usart.h"
/* -------- US_IMR : (USART Offset: 0x0010) Interrupt Mask Register -------- */
# 237 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_usart.h"
/* -------- US_CSR : (USART Offset: 0x0014) Channel Status Register -------- */
# 265 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_usart.h"
/* -------- US_RHR : (USART Offset: 0x0018) Receiver Holding Register -------- */



/* -------- US_THR : (USART Offset: 0x001C) Transmitter Holding Register -------- */




/* -------- US_BRGR : (USART Offset: 0x0020) Baud Rate Generator Register -------- */






/* -------- US_RTOR : (USART Offset: 0x0024) Receiver Time-out Register -------- */



/* -------- US_TTGR : (USART Offset: 0x0028) Transmitter Timeguard Register -------- */



/* -------- US_FIDI : (USART Offset: 0x0040) FI DI Ratio Register -------- */



/* -------- US_NER : (USART Offset: 0x0044) Number of Errors Register -------- */


/* -------- US_IF : (USART Offset: 0x004C) IrDA Filter Register -------- */



/* -------- US_MAN : (USART Offset: 0x0050) Manchester Encoder Decoder Register -------- */
# 323 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_usart.h"
/* -------- US_LINMR : (USART Offset: 0x0054) LIN Mode Register -------- */
# 339 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_usart.h"
/* -------- US_LINIR : (USART Offset: 0x0058) LIN Identifier Register -------- */



/* -------- US_WPMR : (USART Offset: 0xE4) Write Protect Mode Register -------- */




/* -------- US_WPSR : (USART Offset: 0xE8) Write Protect Status Register -------- */



/* -------- US_RPR : (USART Offset: 0x100) Receive Pointer Register -------- */



/* -------- US_RCR : (USART Offset: 0x104) Receive Counter Register -------- */



/* -------- US_TPR : (USART Offset: 0x108) Transmit Pointer Register -------- */



/* -------- US_TCR : (USART Offset: 0x10C) Transmit Counter Register -------- */



/* -------- US_RNPR : (USART Offset: 0x110) Receive Next Pointer Register -------- */



/* -------- US_RNCR : (USART Offset: 0x114) Receive Next Counter Register -------- */



/* -------- US_TNPR : (USART Offset: 0x118) Transmit Next Pointer Register -------- */



/* -------- US_TNCR : (USART Offset: 0x11C) Transmit Next Counter Register -------- */



/* -------- US_PTCR : (USART Offset: 0x120) Transfer Control Register -------- */




/* -------- US_PTSR : (USART Offset: 0x124) Transfer Status Register -------- */



/*@}*/
# 300 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_wdt.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Watchdog Timer */
/* ============================================================================= */
/** \addtogroup SAM3XA_WDT Watchdog Timer */
/*@{*/


/** \brief Wdt hardware registers */
typedef struct {
  WoReg WDT_CR; /**< \brief (Wdt Offset: 0x00) Control Register */
  RwReg WDT_MR; /**< \brief (Wdt Offset: 0x04) Mode Register */
  RoReg WDT_SR; /**< \brief (Wdt Offset: 0x08) Status Register */
} Wdt;

/* -------- WDT_CR : (WDT Offset: 0x00) Control Register -------- */




/* -------- WDT_MR : (WDT Offset: 0x04) Mode Register -------- */
# 65 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/component/component_wdt.h"
/* -------- WDT_SR : (WDT Offset: 0x08) Status Register -------- */



/*@}*/
# 301 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
/*@}*/

/* ************************************************************************** */
/*   REGISTER ACCESS DEFINITIONS FOR SAM3X8E */
/* ************************************************************************** */
/** \addtogroup SAM3X8E_reg Registers Access Definitions */
/*@{*/

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_hsmci.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for HSMCI peripheral ========== */
# 310 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_ssc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for SSC peripheral ========== */
# 311 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_spi0.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for SPI0 peripheral ========== */
# 312 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_tc0.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for TC0 peripheral ========== */
# 313 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_tc1.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for TC1 peripheral ========== */
# 314 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_tc2.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for TC2 peripheral ========== */
# 315 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_twi0.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for TWI0 peripheral ========== */
# 316 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_twi1.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for TWI1 peripheral ========== */
# 317 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_pwm.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for PWM peripheral ========== */
# 318 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_usart0.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for USART0 peripheral ========== */
# 319 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_usart1.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for USART1 peripheral ========== */
# 320 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_usart2.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for USART2 peripheral ========== */
# 321 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_usart3.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for USART3 peripheral ========== */
# 322 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_uotghs.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for UOTGHS peripheral ========== */
# 323 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_emac.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for EMAC peripheral ========== */
# 324 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_can0.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for CAN0 peripheral ========== */
# 325 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_can1.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for CAN1 peripheral ========== */
# 326 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_trng.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for TRNG peripheral ========== */
# 327 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_adc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for ADC peripheral ========== */
# 328 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_dmac.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for DMAC peripheral ========== */
# 329 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_dacc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for DACC peripheral ========== */
# 330 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_smc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for SMC peripheral ========== */
# 331 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_matrix.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for MATRIX peripheral ========== */
# 332 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_pmc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for PMC peripheral ========== */
# 333 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_uart.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for UART peripheral ========== */
# 334 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_chipid.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for CHIPID peripheral ========== */
# 335 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_efc0.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for EFC0 peripheral ========== */
# 336 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_efc1.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for EFC1 peripheral ========== */
# 337 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_pioa.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for PIOA peripheral ========== */
# 338 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_piob.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for PIOB peripheral ========== */
# 339 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_pioc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for PIOC peripheral ========== */
# 340 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_piod.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for PIOD peripheral ========== */
# 341 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_rstc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for RSTC peripheral ========== */
# 342 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_supc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for SUPC peripheral ========== */
# 343 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_rtt.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for RTT peripheral ========== */
# 344 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_wdt.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for WDT peripheral ========== */
# 345 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_rtc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for RTC peripheral ========== */
# 346 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_gpbr.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/* ========== Register definition for GPBR peripheral ========== */
# 347 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
/*@}*/

/* ************************************************************************** */
/*   PERIPHERAL ID DEFINITIONS FOR SAM3X8E */
/* ************************************************************************** */
/** \addtogroup SAM3X8E_id Peripheral Ids Definitions */
/*@{*/
# 398 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h"
/*@}*/

/* ************************************************************************** */
/*   BASE ADDRESS DEFINITIONS FOR SAM3X8E */
/* ************************************************************************** */
/** \addtogroup SAM3X8E_base Peripheral Base Address Definitions */
/*@{*/
# 505 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h"
/*@}*/

/* ************************************************************************** */
/*   PIO DEFINITIONS FOR SAM3X8E */
/* ************************************************************************** */
/** \addtogroup SAM3X8E_pio Peripheral Pio Definitions */
/*@{*/

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/pio/pio_sam3x8e.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */
# 137 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/pio/pio_sam3x8e.h"
/* ========== Pio definition for ADC peripheral ========== */
# 156 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/pio/pio_sam3x8e.h"
/* ========== Pio definition for CAN0 peripheral ========== */


/* ========== Pio definition for CAN1 peripheral ========== */


/* ========== Pio definition for DACC peripheral ========== */




/* ========== Pio definition for EBI peripheral ========== */
# 261 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/pio/pio_sam3x8e.h"
/* ========== Pio definition for EMAC peripheral ========== */
# 281 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/pio/pio_sam3x8e.h"
/* ========== Pio definition for HSMCI peripheral ========== */
# 297 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/pio/pio_sam3x8e.h"
/* ========== Pio definition for PMC peripheral ========== */






/* ========== Pio definition for PWM peripheral ========== */
# 356 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/pio/pio_sam3x8e.h"
/* ========== Pio definition for SPI0 peripheral ========== */
# 367 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/pio/pio_sam3x8e.h"
/* ========== Pio definition for SSC peripheral ========== */






/* ========== Pio definition for TC0 peripheral ========== */
# 384 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/pio/pio_sam3x8e.h"
/* ========== Pio definition for TC1 peripheral ========== */
# 400 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/pio/pio_sam3x8e.h"
/* ========== Pio definition for TC2 peripheral ========== */
# 410 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/pio/pio_sam3x8e.h"
/* ========== Pio definition for TWI0 peripheral ========== */


/* ========== Pio definition for TWI1 peripheral ========== */


/* ========== Pio definition for UART peripheral ========== */


/* ========== Pio definition for UOTGHS peripheral ========== */


/* ========== Pio definition for USART0 peripheral ========== */





/* ========== Pio definition for USART1 peripheral ========== */





/* ========== Pio definition for USART2 peripheral ========== */





/* ========== Pio definition for USART3 peripheral ========== */





/* ========== Pio indexes ========== */
# 514 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h" 2
/*@}*/

/* ************************************************************************** */
/*   MEMORY MAPPING DEFINITIONS FOR SAM3X8E */
/* ************************************************************************** */
# 552 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h"
/* ************************************************************************** */
/*   ELECTRICAL DEFINITIONS FOR SAM3X8E */
/* ************************************************************************** */

/* Device characteristics */
# 567 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h"
/* Embedded Flash Write Wait State */


/* Embedded Flash Read Wait State (VDDCORE set at 1.65V) */







}


/*@}*/
# 45 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3xa/include/sam3xa.h" 2
# 60 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam3.h" 2
# 199 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/CMSIS/Device/ATMEL/sam.h" 2
# 26 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2

/* Define attribute */






/* Define NO_INIT attribute */






/*
 * Peripherals
 */
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/adc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011-2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/../chip.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 34 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/adc.h" 2

/// @cond 0
/**INDENT-OFF**/

extern "C" {

/**INDENT-ON**/
/// @endcond

/* The max adc sample freq definition*/

/* The min adc sample freq definition*/

/* The normal adc startup time*/

/* The fast adc startup time*/


/* Definitions for ADC resolution */

enum adc_resolution_t {
 ADC_10_BITS = (0x1u << 4) /**< \brief (ADC_MR) 10-bit resolution */, /* ADC 10-bit resolution */
 ADC_12_BITS = (0x0u << 4) /**< \brief (ADC_MR) 12-bit resolution */ /* ADC 12-bit resolution */
};
# 71 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/adc.h"
/* Definitions for ADC trigger */
enum adc_trigger_t {
 ADC_TRIG_SW = (0x0u << 0) /**< \brief (ADC_MR) Hardware triggers are disabled. Starting a conversion is only possible by software. */, /* Starting a conversion is only possible by software. */
 ADC_TRIG_EXT = (((0x0u << 1) /**< \brief (ADC_MR) External : ADCTRG */ << 1) &
         (0x7u << 1) /**< \brief (ADC_MR) Trigger Selection */) | (0x1u << 0) /**< \brief (ADC_MR) Trigger Enable */, /* External trigger */
 ADC_TRIG_TIO_CH_0 = ((0x1u << 1) /**< \brief (ADC_MR) TIOA Output of the Timer Counter Channel 0 */ & (0x7u << 1) /**< \brief (ADC_MR) Trigger Selection */) |
           (0x1u << 0) /**< \brief (ADC_MR) Trigger Enable */, /* TIO Output of the Timer Counter Channel 0 */
 ADC_TRIG_TIO_CH_1 = ((0x2u << 1) /**< \brief (ADC_MR) TIOA Output of the Timer Counter Channel 1 */ & (0x7u << 1) /**< \brief (ADC_MR) Trigger Selection */) |
           (0x1u << 0) /**< \brief (ADC_MR) Trigger Enable */, /* TIO Output of the Timer Counter Channel 1 */
 ADC_TRIG_TIO_CH_2 = ((0x3u << 1) /**< \brief (ADC_MR) TIOA Output of the Timer Counter Channel 2 */ & (0x7u << 1) /**< \brief (ADC_MR) Trigger Selection */) |
           (0x1u << 0) /**< \brief (ADC_MR) Trigger Enable */, /* TIO Output of the Timer Counter Channel 2 */

 ADC_TRIG_PWM_EVENT_LINE_0 = ((0x4u << 1) /**< \brief (ADC_MR) PWM Event Line 0 */ & (0x7u << 1) /**< \brief (ADC_MR) Trigger Selection */) |
               (0x1u << 0) /**< \brief (ADC_MR) Trigger Enable */, /* PWM Event Line 0 */
 ADC_TRIG_PWM_EVENT_LINE_1 = ((0x5u << 1) /**< \brief (ADC_MR) PWM Event Line 0 */ & (0x7u << 1) /**< \brief (ADC_MR) Trigger Selection */) |
               (0x1u << 0) /**< \brief (ADC_MR) Trigger Enable */ /* PWM Event Line 1 */

} ;


/* Definitions for ADC channel number */
enum adc_channel_num_t {
 ADC_CHANNEL_0 = 0,
 ADC_CHANNEL_1 = 1,
 ADC_CHANNEL_2 = 2,
 ADC_CHANNEL_3 = 3,
 ADC_CHANNEL_4 = 4,
 ADC_CHANNEL_5 = 5,
 ADC_CHANNEL_6 = 6,
 ADC_CHANNEL_7 = 7,
 ADC_CHANNEL_8 = 8,
 ADC_CHANNEL_9 = 9,
 ADC_CHANNEL_10 = 10,
 ADC_CHANNEL_11 = 11,
 ADC_CHANNEL_12 = 12,
 ADC_CHANNEL_13 = 13,
 ADC_CHANNEL_14 = 14,
 ADC_TEMPERATURE_SENSOR = 15,
} ;
# 123 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/adc.h"
/* Definitions for ADC gain value */
enum adc_gainvalue_t{
 ADC_GAINVALUE_0 = 0,
 ADC_GAINVALUE_1 = 1,
 ADC_GAINVALUE_2 = 2,
 ADC_GAINVALUE_3 = 3
};
/* Definitions for ADC analog settling time */

enum adc_settling_time_t{
 ADC_SETTLING_TIME_0 = (0x0u << 20) /**< \brief (ADC_MR) 3 periods of ADCClock */,
 ADC_SETTLING_TIME_1 = (0x1u << 20) /**< \brief (ADC_MR) 5 periods of ADCClock */,
 ADC_SETTLING_TIME_2 = (0x2u << 20) /**< \brief (ADC_MR) 9 periods of ADCClock */,
 ADC_SETTLING_TIME_3 = (0x3u << 20) /**< \brief (ADC_MR) 17 periods of ADCClock */
};



uint32_t adc_init(Adc *p_adc, const uint32_t ul_mck,
                            const uint32_t ul_adc_clock, const uint8_t uc_startup);
void adc_configure_trigger(Adc *p_adc, const enum adc_trigger_t trigger,
    const uint8_t uc_freerun);
void adc_configure_power_save(Adc *p_adc, const uint8_t uc_sleep, const uint8_t uc_fwup);
void adc_configure_sequence(Adc *p_adc, const enum adc_channel_num_t ch_list[],
                                                               const uint8_t uc_num);
void adc_enable_tag(Adc *p_adc);
void adc_disable_tag(Adc *p_adc);
enum adc_channel_num_t adc_get_tag(const Adc *p_adc);
void adc_start_sequencer(Adc *p_adc);
void adc_stop_sequencer(Adc *p_adc);
void adc_set_comparison_mode(Adc *p_adc, const uint8_t uc_mode);
uint32_t adc_get_comparison_mode(const Adc *p_adc);
void adc_set_comparison_window(Adc *p_adc, const uint16_t us_low_threshold,
                                                                        const uint16_t us_high_threshold);
void adc_set_comparison_channel(Adc *p_adc, const enum adc_channel_num_t channel);
void adc_set_writeprotect(Adc *p_adc, const uint32_t ul_enable);
uint32_t adc_get_writeprotect_status(const Adc *p_adc);
void adc_check(Adc* p_adc, const uint32_t ul_mck);
uint32_t adc_get_overrun_status(const Adc *p_adc);







void adc_set_resolution(Adc *p_adc, const enum adc_resolution_t resolution);
void adc_start(Adc *p_adc);
void adc_stop(Adc *p_adc);
void adc_enable_channel(Adc *p_adc, const enum adc_channel_num_t adc_ch);
void adc_disable_channel(Adc *p_adc, const enum adc_channel_num_t adc_ch);
void adc_enable_all_channel(Adc *p_adc);
void adc_disable_all_channel(Adc *p_adc);
uint32_t adc_get_channel_status(const Adc *p_adc, const enum adc_channel_num_t adc_ch);
uint32_t adc_get_channel_value(const Adc *p_adc,const enum adc_channel_num_t adc_ch);
uint32_t adc_get_latest_value(const Adc *p_adc);
uint32_t adc_get_actual_adc_clock(const Adc *p_adc, const uint32_t ul_mck);
void adc_enable_interrupt(Adc *p_adc, const uint32_t ul_source);
void adc_disable_interrupt(Adc *p_adc, const uint32_t ul_source);
uint32_t adc_get_status(const Adc *p_adc);
uint32_t adc_get_interrupt_mask(const Adc *p_adc);
Pdc *adc_get_pdc_base(const Adc *p_adc);


void adc_configure_timing(Adc *p_adc, const uint8_t uc_tracking,
                                         const enum adc_settling_time_t settling, const uint8_t uc_transfer);
void adc_enable_anch( Adc *p_adc );
void adc_disable_anch( Adc *p_adc );
void adc_enable_channel_differential_input(Adc *p_adc, const enum adc_channel_num_t channel);
void adc_disable_channel_differential_input(Adc *p_adc, const enum adc_channel_num_t channel);
void adc_enable_channel_input_offset(Adc *p_adc, const enum adc_channel_num_t channel);
void adc_disable_channel_input_offset(Adc *p_adc, const enum adc_channel_num_t channel);
void adc_set_channel_input_gain(Adc *p_adc, const enum adc_channel_num_t channel,
                                                       const enum adc_gainvalue_t uc_gain);
void adc_set_bias_current(Adc *p_adc, const uint8_t uc_ibctl);
void adc_enable_ts(Adc *p_adc);
void adc_disable_ts(Adc *p_adc);
# 240 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/adc.h"
/// @cond 0
/**INDENT-OFF**/

}

/**INDENT-ON**/
/// @endcond
# 45 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/dacc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011-2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/../chip.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 34 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/dacc.h" 2

/// @cond 0
/**INDENT-OFF**/

extern "C" {

/**INDENT-ON**/
/// @endcond

//! DACC return codes
typedef enum dacc_rc {
 DACC_RC_OK = 0, //!< Operation OK
 DACC_RC_INVALID_PARAM //!< Invalid parameter
} dacc_rc_t;





//! DACC resolution in number of data bits


//! DACC max data value


void dacc_reset(Dacc *p_dacc);
uint32_t dacc_set_trigger(Dacc *p_dacc, uint32_t ul_trigger);
void dacc_disable_trigger(Dacc *p_dacc);
uint32_t dacc_set_transfer_mode(Dacc *p_dacc, uint32_t ul_mode);
void dacc_enable_interrupt(Dacc *p_dacc, uint32_t ul_interrupt_mask);
void dacc_disable_interrupt(Dacc *p_dacc, uint32_t ul_interrupt_mask);
uint32_t dacc_get_interrupt_mask(Dacc *p_dacc);
uint32_t dacc_get_interrupt_status(Dacc *p_dacc);
void dacc_write_conversion_data(Dacc *p_dacc, uint32_t ul_data);
void dacc_set_writeprotect(Dacc *p_dacc, uint32_t ul_enable);
uint32_t dacc_get_writeprotect_status(Dacc *p_dacc);
Pdc *dacc_get_pdc_base(Dacc *p_dacc);
# 80 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/dacc.h"
uint32_t dacc_set_channel_selection(Dacc *p_dacc, uint32_t ul_channel);
void dacc_enable_flexible_selection(Dacc *p_dacc);

uint32_t dacc_set_power_save(Dacc *p_dacc, uint32_t ul_sleep_mode,
  uint32_t ul_fast_wakeup_mode);
uint32_t dacc_set_timing(Dacc *p_dacc, uint32_t ul_refresh, uint32_t ul_maxs,
  uint32_t ul_startup);
uint32_t dacc_enable_channel(Dacc *p_dacc, uint32_t ul_channel);
uint32_t dacc_disable_channel(Dacc *p_dacc, uint32_t ul_channel);
uint32_t dacc_get_channel_status(Dacc *p_dacc);
uint32_t dacc_set_analog_control(Dacc *p_dacc, uint32_t ul_analog_control);
uint32_t dacc_get_analog_control(Dacc *p_dacc);


/// @cond 0
/**INDENT-OFF**/

}

/**INDENT-ON**/
/// @endcond
# 47 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2


# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/interrupt_sam_nvic.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011-2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/../chip.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 34 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/interrupt_sam_nvic.h" 2

/**
 * \weakgroup interrupt_group
 *
 * @{
 */

/**
 * \name Interrupt Service Routine definition
 *
 * @{
 */

/**
 * \brief Define service routine
 *
 * \note For NVIC devices the interrupt service routines are predefined to
 *       add to vector table in binary generation, so there is no service
 *       register at run time. The routine collections are in exceptions.h.
 *
 * Usage:
 * \code
 * ISR(foo_irq_handler)
 * {
 *      // Function definition
 *      ...
 * }
 * \endcode
 *
 * \param func Name for the function.
 */



/**
 * \brief Initialize interrupt vectors
 *
 * For NVIC the interrupt vectors are put in vector table. So nothing
 * to do to initialize them, except defined the vector function with
 * right name.
 *
 * This must be called prior to \ref irq_register_handler.
 */




/**
 * \brief Register handler for interrupt
 *
 * For NVIC the interrupt vectors are put in vector table. So nothing
 * to do to register them, except defined the vector function with
 * right name.
 *
 * Usage:
 * \code
 * irq_initialize_vectors();
 * irq_register_handler(foo_irq_handler);
 * \endcode
 *
 * \note The function \a func must be defined with the \ref ISR macro.
 * \note The functions prototypes can be found in the device exception header
 *       files (exceptions.h).
 */




//@}
# 117 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/interrupt_sam_nvic.h"
typedef uint32_t irqflags_t;
extern int g_interrupt_enabled;

static inline irqflags_t cpu_irq_save(void)
{
 irqflags_t flags = g_interrupt_enabled;
 do { __disable_irq(); __DMB(); g_interrupt_enabled = 0; } while (0);
 return flags;
}

static inline int cpu_irq_is_enabled_flags(irqflags_t flags)
{
 return (flags);
}

static inline void cpu_irq_restore(irqflags_t flags)
{
 if (cpu_irq_is_enabled_flags(flags))
  do { g_interrupt_enabled = 1; __DMB(); __enable_irq(); } while (0);
}



/**
 * \weakgroup interrupt_deprecated_group
 * @{
 */





//@}

//@}
# 50 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/efc.h" 1
/**
 * \file
 *
 * \brief Embedded Flash Controller (EFC) driver for SAM.
 *
 * Copyright (c) 2011-2012 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */




# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/../chip.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 48 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/efc.h" 2

/// @cond 0
/**INDENT-OFF**/

extern "C" {

/**INDENT-ON**/
/// @endcond

/*! \name EFC return codes */
//! @{
typedef enum efc_rc {
 EFC_RC_OK = 0, //!< Operation OK
 EFC_RC_YES = 0, //!< Yes
 EFC_RC_NO = 1, //!< No
 EFC_RC_ERROR = 1, //!< General error
 EFC_RC_INVALID, //!< Invalid argument input
 EFC_RC_NOT_SUPPORT = 0xFFFFFFFF //!< Operation is not supported
} efc_rc_t;
//! @}

/*! \name EFC command */
//! @{
# 101 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/efc.h"
//! @}

/*! The IAP function entry address */


/*! \name EFC access mode */
//! @{


//! @}

uint32_t efc_init(Efc *p_efc, uint32_t ul_access_mode, uint32_t ul_fws);
void efc_enable_frdy_interrupt(Efc *p_efc);
void efc_disable_frdy_interrupt(Efc *p_efc);
void efc_set_flash_access_mode(Efc *p_efc, uint32_t ul_mode);
uint32_t efc_get_flash_access_mode(Efc *p_efc);
void efc_set_wait_state(Efc *p_efc, uint32_t ul_fws);
uint32_t efc_get_wait_state(Efc *p_efc);
uint32_t efc_perform_command(Efc *p_efc, uint32_t ul_command, uint32_t ul_argument);
uint32_t efc_get_status(Efc *p_efc);
uint32_t efc_get_result(Efc *p_efc);
uint32_t efc_perform_read_sequence(Efc *p_efc, uint32_t ul_cmd_st, uint32_t ul_cmd_sp, uint32_t *p_ul_buf, uint32_t ul_size);

/// @cond 0
/**INDENT-OFF**/

}

/**INDENT-ON**/
/// @endcond
# 51 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/gpbr.h" 1
/**
 * \file
 *
 * \brief General Purpose Backup Registers (GPBR) driver for SAM.
 *
 * Copyright (c) 2011-2012 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */




# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/../chip.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 48 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/gpbr.h" 2

/// @cond 0
/**INDENT-OFF**/

extern "C" {

/**INDENT-ON**/
/// @endcond

/** GPBR register number type */
typedef enum gpbr_num_type {
 GPBR0 = 0,
 GPBR1,
 GPBR2,
 GPBR3,
 GPBR4,
 GPBR5,
 GPBR6,
 GPBR7
} gpbr_num_t;

uint32_t gpbr_read(gpbr_num_t ul_reg_num);
void gpbr_write(gpbr_num_t ul_reg_num, uint32_t ul_value);

/// @cond 0
/**INDENT-OFF**/

}

/**INDENT-ON**/
/// @endcond
# 52 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/pio.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011-2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




/*
 *         Headers
 */

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/../chip.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 38 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/pio.h" 2



/*
 *         Global Definitions
 */
typedef enum _EPioType
{
  PIO_NOT_A_PIN, /* Not under control of a peripheral. */
  PIO_PERIPH_A, /* The pin is controlled by the associated signal of peripheral A. */
  PIO_PERIPH_B, /* The pin is controlled by the associated signal of peripheral B. */




  PIO_INPUT, /* The pin is an input. */
  PIO_OUTPUT_0, /* The pin is an output and has a default level of 0. */
  PIO_OUTPUT_1 /* The pin is an output and has a default level of 1. */
} EPioType ;


/*  Default pin configuration (no attribute). */

/*  The internal pin pull-up is active. */

/*  The internal glitch filter is active. */

/*  The pin is open-drain. */


/*  The internal debouncing filter is active. */


/*  Enable additional interrupt modes. */


/*  Interrupt High Level/Rising Edge detection is active. */

/*  Interrupt Edge detection is active. */


/*  Low level interrupt is active */

/*  High level interrupt is active */

/*  Falling edge interrupt is active */

/*  Rising edge interrupt is active */



 extern "C" {


/*
 *  The #attribute# field is a bitmask that can either be set to PIO_DEFAULt,
 *  or combine (using bitwise OR '|') any number of the following constants:
 *     - PIO_PULLUP
 *     - PIO_DEGLITCH
 *     - PIO_DEBOUNCE
 *     - PIO_OPENDRAIN
 *     - PIO_IT_LOW_LEVEL
 *     - PIO_IT_HIGH_LEVEL
 *     - PIO_IT_FALL_EDGE
 *     - PIO_IT_RISE_EDGE
 */


/*
 *         Global Functions
 */
extern void PIO_DisableInterrupt( Pio* pPio, const uint32_t dwMask ) ;
extern void PIO_PullUp( Pio* pPio, const uint32_t dwMask, const uint32_t dwPullUpEnable ) ;
extern void PIO_SetDebounceFilter( Pio* pPio, const uint32_t dwMask, const uint32_t dwCuttOff ) ;

extern void PIO_Set( Pio* pPio, const uint32_t dwMask ) ;
extern void PIO_Clear( Pio* pPio, const uint32_t dwMask ) ;
extern uint32_t PIO_Get( Pio* pPio, const EPioType dwType, const uint32_t dwMask ) ;

extern void PIO_SetPeripheral( Pio* pPio, const EPioType dwType, const uint32_t dwMask ) ;
extern void PIO_SetInput( Pio* pPio, uint32_t dwMask, uint32_t dwAttribute ) ;
extern void PIO_SetOutput( Pio* pPio, uint32_t dwMask, uint32_t dwDefaultValue,
                                      uint32_t dwMultiDriveEnable, uint32_t dwPullUpEnable ) ;

extern uint32_t PIO_Configure( Pio* pPio, const EPioType dwType, const uint32_t dwMask, const uint32_t dwAttribute ) ;

extern uint32_t PIO_GetOutputDataStatus( const Pio* pPio, const uint32_t dwMask ) ;



}
# 53 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/pmc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011-2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */



# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/../chip.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 33 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/pmc.h" 2

/// @cond 0
/**INDENT-OFF**/

extern "C" {

/**INDENT-ON**/
/// @endcond

/** Bit mask for peripheral clocks (PCER0) */


/** Bit mask for peripheral clocks (PCER1) */


/** Loop counter timeout value */


/** Key to unlock CKGR_MOR register */


/** Key used to write SUPC registers */


/** PMC xtal statup time */


/** Mask to access fast startup input */


/** PMC_WPMR Write Protect KEY, unlock it */


/** Using external oscillator */


/** Oscillator in bypass mode */






/**
 * \name Master clock (MCK) Source and Prescaler configuration
 *
 * The following functions may be used to select the clock source and
 * prescaler for the master clock.
 */
//@{

void pmc_mck_set_prescaler(uint32_t ul_pres);
void pmc_mck_set_source(uint32_t ul_source);
uint32_t pmc_switch_mck_to_sclk(uint32_t ul_pres);
uint32_t pmc_switch_mck_to_mainck(uint32_t ul_pres);
uint32_t pmc_switch_mck_to_pllack(uint32_t ul_pres);




uint32_t pmc_switch_mck_to_upllck(uint32_t ul_pres);


//@}

/**
 * \name Slow clock (SLCK) oscillator and configuration
 *
 */
//@{

void pmc_switch_sclk_to_32kxtal(uint32_t ul_bypass);
uint32_t pmc_osc_is_ready_32kxtal(void);

//@}

/**
 * \name Main Clock (MAINCK) oscillator and configuration
 *
 */
//@{

void pmc_switch_mainck_to_fastrc(uint32_t ul_moscrcf);
void pmc_osc_enable_fastrc(uint32_t ul_rc);
void pmc_osc_disable_fastrc(void);
void pmc_switch_mainck_to_xtal(uint32_t ul_bypass);
void pmc_osc_disable_xtal(uint32_t ul_bypass);
uint32_t pmc_osc_is_ready_mainck(void);

//@}

/**
 * \name PLL oscillator and configuration
 *
 */
//@{

void pmc_enable_pllack(uint32_t mula, uint32_t pllacount, uint32_t diva);
void pmc_disable_pllack(void);
uint32_t pmc_is_locked_pllack(void);
# 141 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/pmc.h"
void pmc_enable_upll_clock(void);
void pmc_disable_upll_clock(void);
uint32_t pmc_is_locked_upll(void);


//@}

/**
 * \name Peripherals clock configuration
 *
 */
//@{

uint32_t pmc_enable_periph_clk(uint32_t ul_id);
uint32_t pmc_disable_periph_clk(uint32_t ul_id);
void pmc_enable_all_periph_clk(void);
void pmc_disable_all_periph_clk(void);
uint32_t pmc_is_periph_clk_enabled(uint32_t ul_id);

//@}

/**
 * \name Programmable clock Source and Prescaler configuration
 *
 * The following functions may be used to select the clock source and
 * prescaler for the specified programmable clock.
 */
//@{

void pmc_pck_set_prescaler(uint32_t ul_id, uint32_t ul_pres);
void pmc_pck_set_source(uint32_t ul_id, uint32_t ul_source);
uint32_t pmc_switch_pck_to_sclk(uint32_t ul_id, uint32_t ul_pres);
uint32_t pmc_switch_pck_to_mainck(uint32_t ul_id, uint32_t ul_pres);
uint32_t pmc_switch_pck_to_pllack(uint32_t ul_id, uint32_t ul_pres);




uint32_t pmc_switch_pck_to_upllck(uint32_t ul_id, uint32_t ul_pres);

void pmc_enable_pck(uint32_t ul_id);
void pmc_disable_pck(uint32_t ul_id);
void pmc_enable_all_pck(void);
void pmc_disable_all_pck(void);
uint32_t pmc_is_pck_enabled(uint32_t ul_id);

//@}

/**
 * \name USB clock configuration
 *
 */
//@{


void pmc_switch_udpck_to_pllack(uint32_t ul_usbdiv);





void pmc_switch_udpck_to_upllck(uint32_t ul_usbdiv);


void pmc_enable_udpck(void);
void pmc_disable_udpck(void);


//@}

/**
 * \name Interrupt and status management
 *
 */
//@{

void pmc_enable_interrupt(uint32_t ul_sources);
void pmc_disable_interrupt(uint32_t ul_sources);
uint32_t pmc_get_interrupt_mask(void);
uint32_t pmc_get_status(void);

//@}

/**
 * \name Power management
 *
 * The following functions are used to configure sleep mode and additionnal
 * wake up inputs.
 */
//@{

void pmc_set_fast_startup_input(uint32_t ul_inputs);
void pmc_clr_fast_startup_input(uint32_t ul_inputs);
void pmc_enable_sleepmode(uint8_t uc_type);
void pmc_enable_waitmode(void);
void pmc_enable_backupmode(void);

//@}

/**
 * \name Write protection
 *
 */
//@{

void pmc_set_writeprotect(uint32_t ul_enable);
uint32_t pmc_get_writeprotect_status(void);

//@}

/// @cond 0
/**INDENT-OFF**/

}

/**INDENT-ON**/
/// @endcond

//! @}

/**
 * \page sam_pmc_quickstart Quick start guide for the SAM PMC module
 *
 * This is the quick start guide for the \ref pmc_group "PMC module", with
 * step-by-step instructions on how to configure and use the driver in a
 * selection of use cases.
 *
 * The use cases contain several code fragments. The code fragments in the
 * steps for setup can be copied into a custom initialization function, while
 * the steps for usage can be copied into, e.g., the main application function.
 *
 * \section pmc_use_cases PMC use cases
 * - \ref pmc_basic_use_case Basic use case - Switch Main Clock sources
 * - \ref pmc_use_case_2 Advanced use case - Configure Programmable Clocks
 *
 * \section pmc_basic_use_case Basic use case - Switch Main Clock sources
 * In this use case, the PMC module is configured for a variety of system clock
 * sources and speeds. A LED is used to visually indicate the current clock
 * speed as the source is switched.
 *
 * \section pmc_basic_use_case_setup Setup
 *
 * \subsection pmc_basic_use_case_setup_prereq Prerequisites
 * -# \ref gpio_group "General Purpose I/O Management (gpio)"
 *
 * \subsection pmc_basic_use_case_setup_code Code
 * The following function needs to be added to the user application, to flash a
 * board LED a variable number of times at a rate given in CPU ticks.
 *
 * \code
 * #define FLASH_TICK_COUNT   0x00012345
 *
 * void flash_led(uint32_t tick_count, uint8_t flash_count)
 * {
 *     SysTick->CTRL = SysTick_CTRL_ENABLE_Msk;
 *     SysTick->LOAD = tick_count;
 *
 *     while (flash_count--)
 *     {
 *         gpio_toggle_pin(LED0_GPIO);
 *         while (!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
 *         gpio_toggle_pin(LED0_GPIO);
 *         while (!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
 *     }
 * }
 * \endcode
 *
 * \section pmc_basic_use_case_usage Use case
 *
 * \subsection pmc_basic_use_case_usage_code Example code
 * Add to application C-file:
 * \code
 *    for (;;)
 *    {
 *        pmc_switch_mainck_to_fastrc(CKGR_MOR_MOSCRCF_12_MHz);
 *        flash_led(FLASH_TICK_COUNT, 5);
 *        pmc_switch_mainck_to_fastrc(CKGR_MOR_MOSCRCF_8_MHz);
 *        flash_led(FLASH_TICK_COUNT, 5);
 *        pmc_switch_mainck_to_fastrc(CKGR_MOR_MOSCRCF_4_MHz);
 *        flash_led(FLASH_TICK_COUNT, 5);
 *        pmc_switch_mainck_to_xtal(0);
 *        flash_led(FLASH_TICK_COUNT, 5);
 *    }
 * \endcode
 *
 * \subsection pmc_basic_use_case_usage_flow Workflow
 * -# Wrap the code in an infinite loop:
 *   \code
 *   for (;;)
 *   \endcode
 * -# Switch the Master CPU frequency to the internal 12MHz RC oscillator, flash
 *    a LED on the board several times:
 *   \code
 *   pmc_switch_mainck_to_fastrc(CKGR_MOR_MOSCRCF_12_MHz);
 *   flash_led(FLASH_TICK_COUNT, 5);
 *   \endcode
 * -# Switch the Master CPU frequency to the internal 8MHz RC oscillator, flash
 *    a LED on the board several times:
 *   \code
 *   pmc_switch_mainck_to_fastrc(CKGR_MOR_MOSCRCF_8_MHz);
 *   flash_led(FLASH_TICK_COUNT, 5);
 *   \endcode
 * -# Switch the Master CPU frequency to the internal 4MHz RC oscillator, flash
 *    a LED on the board several times:
 *   \code
 *   pmc_switch_mainck_to_fastrc(CKGR_MOR_MOSCRCF_4_MHz);
 *   flash_led(FLASH_TICK_COUNT, 5);
 *   \endcode
 * -# Switch the Master CPU frequency to the external crystal oscillator, flash
 *    a LED on the board several times:
 *   \code
 *   pmc_switch_mainck_to_xtal(0);
 *   flash_led(FLASH_TICK_COUNT, 5);
 *   \endcode
 */

/**
 * \page pmc_use_case_2 Use case #2 - Configure Programmable Clocks
 * In this use case, the PMC module is configured to start the Slow Clock from
 * an attached 32KHz crystal, and start one of the Programmable Clock modules
 * sourced from the Slow Clock divided down with a prescale factor of 64.
 *
 * \section pmc_use_case_2_setup Setup
 *
 * \subsection pmc_use_case_2_setup_prereq Prerequisites
 * -# \ref pio_group "Parallel Input/Output Controller (pio)"
 *
 * \subsection pmc_use_case_2_setup_code Code
 * The following code must be added to the user application:
 * \code
 * 	pio_set_peripheral(PIOA, PIO_PERIPH_B, PIO_PA17);
 * \endcode
 *
 * \subsection pmc_use_case_2_setup_code_workflow Workflow
 * -# Configure the PCK1 pin to output on a specific port pin (in this case,
 *    PIOA pin 17) of the microcontroller.
 *   \code
 *   pio_set_peripheral(PIOA, PIO_PERIPH_B, PIO_PA17);
 *   \endcode
 *   \note The peripheral selection and pin will vary according to your selected
 *       SAM device model. Refer to the "Peripheral Signal Multiplexing on I/O
 *       Lines" of your device's datasheet.
 *
 * \section pmc_use_case_2_usage Use case
 * The generated PCK1 clock output can be viewed on an oscilloscope attached to
 * the correct pin of the microcontroller.
 *
 * \subsection pmc_use_case_2_usage_code Example code
 * Add to application C-file:
 * \code
 *  pmc_switch_sclk_to_32kxtal(PMC_OSC_XTAL);
 *  pmc_switch_pck_to_sclk(PMC_PCK_1, PMC_PCK_PRES_CLK_64);
 *  pmc_enable_pck(PMC_PCK_1);
 *
 *  for (;;)
 *  {
 *      // Do Nothing
 *  }
 * \endcode
 *
 * \subsection pmc_use_case_2_usage_flow Workflow
 * -# Switch the Slow Clock source input to an external 32KHz crystal:
 *   \code
 *   pmc_switch_sclk_to_32kxtal(PMC_OSC_XTAL);
 *   \endcode
 * -# Switch the Programmable Clock module PCK1 source clock to the Slow Clock,
 *    with a prescaler of 64:
 *   \code
 *   pmc_switch_pck_to_sclk(PMC_PCK_1, PMC_PCK_PRES_CLK_64);
 *   \endcode
 * -# Enable Programmable Clock module PCK1:
 *   \code
 *   pmc_enable_pck(PMC_PCK_1);
 *   \endcode
 * -# Enter an infinite loop:
 *   \code
 *   for (;;)
 *   {
 *      // Do Nothing
 *   }
 *   \endcode
 */
# 54 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/pwmc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011-2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/**
 * \file
 *
 * \par Purpose
 *
 * Interface for configuration the Pulse Width Modulation Controller (PWM) peripheral.
 *
 * \par Usage
 *
 *    -# Configures PWM clocks A & B to run at the given frequencies using
 *       \ref PWMC_ConfigureClocks().
 *    -# Configure PWMC channel using \ref PWMC_ConfigureChannel(), \ref PWMC_ConfigureChannelExt()
 *       \ref PWMC_SetPeriod(), \ref PWMC_SetDutyCycle() and \ref PWMC_SetDeadTime().
 *    -# Enable & disable channel using \ref PWMC_EnableChannel() and
 *       \ref PWMC_DisableChannel().
 *    -# Enable & disable the period interrupt for the given PWM channel using
 *       \ref PWMC_EnableChannelIt() and \ref PWMC_DisableChannelIt().
 *    -# Enable & disable the selected interrupts sources on a PWMC peripheral
 *       using  \ref PWMC_EnableIt() and \ref PWMC_DisableIt().
 *    -# Control syncronous channel using \ref PWMC_ConfigureSyncChannel(),
 *       \ref PWMC_SetSyncChannelUpdatePeriod() and \ref PWMC_SetSyncChannelUpdateUnlock().
 *    -# Control PWM override output using \ref PWMC_SetOverrideValue(),
 *       \ref PWMC_EnableOverrideOutput() and \ref PWMC_DisableOverrideOutput().
 *    -# Send data through the transmitter using \ref PWMC_WriteBuffer().
 *
 */




/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/../chip.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 65 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/pwmc.h" 2




 extern "C" {


/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/

extern void PWMC_ConfigureChannel( Pwm* pPwm, uint32_t ul_channel, uint32_t prescaler, uint32_t alignment, uint32_t polarity ) ;
extern void PWMC_ConfigureChannelExt( Pwm* pPwm, uint32_t ul_channel, uint32_t prescaler, uint32_t alignment, uint32_t polarity,
                                      uint32_t countEventSelect, uint32_t DTEnable, uint32_t DTHInverte, uint32_t DTLInverte ) ;

extern void PWMC_ConfigureClocks(uint32_t clka, uint32_t clkb, uint32_t mck ) ;
extern void PWMC_SetPeriod( Pwm* pPwm, uint32_t ul_channel, uint16_t period ) ;
extern void PWMC_SetDutyCycle( Pwm* pPwm, uint32_t ul_channel, uint16_t duty ) ;
extern void PWMC_SetDeadTime( Pwm* pPwm, uint32_t ul_channel, uint16_t timeH, uint16_t timeL ) ;
extern void PWMC_ConfigureSyncChannel( Pwm* pPwm, uint32_t ul_channels, uint32_t updateMode, uint32_t requestMode, uint32_t requestComparisonSelect ) ;
extern void PWMC_SetSyncChannelUpdatePeriod( Pwm* pPwm, uint8_t period ) ;
extern void PWMC_SetSyncChannelUpdateUnlock( Pwm* pPwm ) ;
extern void PWMC_EnableChannel( Pwm* pPwm, uint32_t ul_channel ) ;
extern void PWMC_DisableChannel( Pwm* pPwm, uint32_t ul_channel ) ;
extern void PWMC_EnableChannelIt( Pwm* pPwm, uint32_t ul_channel ) ;
extern void PWMC_DisableChannelIt( Pwm* pPwm, uint32_t ul_channel ) ;
extern void PWMC_EnableIt( Pwm* pPwm, uint32_t sources1, uint32_t sources2 ) ;
extern void PWMC_DisableIt( Pwm* pPwm, uint32_t sources1, uint32_t sources2 ) ;
extern uint8_t PWMC_WriteBuffer(Pwm *pwmc, void *buffer, uint32_t length ) ;
extern void PWMC_SetOverrideValue( Pwm* pPwm, uint32_t value ) ;
extern void PWMC_EnableOverrideOutput( Pwm* pPwm, uint32_t value, uint32_t sync ) ;
extern void PWMC_DisableOverrideOutput( Pwm* pPwm, uint32_t value, uint32_t sync ) ;
extern void PWMC_SetFaultMode( Pwm* pPwm, uint32_t mode ) ;
extern void PWMC_FaultClear( Pwm* pPwm, uint32_t fault ) ;
extern void PWMC_SetFaultProtectionValue( Pwm* pPwm, uint32_t value ) ;
extern void PWMC_EnableFaultProtection( Pwm* pPwm, uint32_t ul_channel, uint32_t value ) ;
extern void PWMC_ConfigureComparisonUnit( Pwm* pPwm, uint32_t x, uint32_t value, uint32_t mode ) ;
extern void PWMC_ConfigureEventLineMode( Pwm* pPwm, uint32_t x, uint32_t mode ) ;


}
# 55 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/rstc.h" 1
/**
 * \file
 *
 * \brief Reset Controller (RSTC) driver for SAM.
 *
 * Copyright (c) 2011-2012 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */




# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/../chip.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 48 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/rstc.h" 2


extern "C" {


/** Definitions of Reset Controller Status */
/** Reset cause */





/** NRST Pin Level */



void rstc_set_external_reset(Rstc* p_rstc, const uint32_t ul_length);
void rstc_enable_user_reset(Rstc* p_rstc);
void rstc_disable_user_reset(Rstc* p_rstc);
void rstc_enable_user_reset_interrupt(Rstc* p_rstc);
void rstc_disable_user_reset_interrupt(Rstc* p_rstc);
void rstc_start_software_reset(Rstc* p_rstc);
void rstc_reset_extern(Rstc *p_rstc);
uint32_t rstc_get_status(Rstc* p_rstc);
uint32_t rstc_get_reset_cause(Rstc* p_rstc);


}
# 56 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/rtc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011-2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/**
 * \file
 *
 * Interface for Real Time Clock (RTC) controller.
 *
 */




/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/../chip.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 44 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/rtc.h" 2



/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/
# 60 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/rtc.h"
/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/


 extern "C" {


extern void RTC_SetHourMode( Rtc* pRtc, uint32_t dwMode ) ;

extern uint32_t RTC_GetHourMode( Rtc* pRtc ) ;

extern void RTC_EnableIt( Rtc* pRtc, uint32_t dwSources ) ;

extern void RTC_DisableIt( Rtc* pRtc, uint32_t dwSources ) ;

extern int RTC_SetTime( Rtc* pRtc, uint8_t ucHour, uint8_t ucMinute, uint8_t ucSecond ) ;

extern void RTC_GetTime( Rtc* pRtc, uint8_t *pucHour, uint8_t *pucMinute, uint8_t *pucSecond ) ;

extern int RTC_SetTimeAlarm( Rtc* pRtc, uint8_t *pucHour, uint8_t *pucMinute, uint8_t *pucSecond ) ;

extern void RTC_GetDate( Rtc* pRtc, uint16_t *pwYear, uint8_t *pucMonth, uint8_t *pucDay, uint8_t *pucWeek ) ;

extern int RTC_SetDate( Rtc* pRtc, uint16_t wYear, uint8_t ucMonth, uint8_t ucDay, uint8_t ucWeek ) ;

extern int RTC_SetDateAlarm( Rtc* pRtc, uint8_t *pucMonth, uint8_t *pucDay ) ;

extern void RTC_ClearSCCR( Rtc* pRtc, uint32_t dwMask ) ;

extern uint32_t RTC_GetSR( Rtc* pRtc, uint32_t dwMask ) ;


}
# 57 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/rtt.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011-2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/**
 * \file
 *
 * \par Purpose
 *
 * Interface for Real Time Timer (RTT) controller.
 *
 * \par Usage
 *
 * -# Changes the prescaler value of the given RTT and restarts it
 *    using \ref RTT_SetPrescaler().
 * -# Get current value of the RTT using \ref RTT_GetTime().
 * -# Enables the specified RTT interrupt using \ref RTT_EnableIT().
 * -# Get the status register value of the given RTT using \ref RTT_GetStatus().
 * -# Configures the RTT to generate an alarm at the given time
 *    using \ref RTT_SetAlarm().
 */




/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/../chip.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 56 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/rtt.h" 2



/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/


 extern "C" {


extern void RTT_SetPrescaler( Rtt* pRtt, uint16_t wPrescaler ) ;

extern uint32_t RTT_GetTime( Rtt* pRtt ) ;

extern void RTT_EnableIT( Rtt* pRtt, uint32_t dwSources ) ;

extern uint32_t RTT_GetStatus( Rtt *pRtt ) ;

extern void RTT_SetAlarm( Rtt *pRtt, uint32_t dwTime ) ;


}
# 58 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/spi.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011-2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/**
 * \file
 *
 * Interface for Serial Peripheral Interface (SPI) controller.
 *
 */




/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/../chip.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 45 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/spi.h" 2

/*----------------------------------------------------------------------------
 *        Macros
 *----------------------------------------------------------------------------*/

/**
 *
 * Here are several macros which should be used when configuring a SPI
 * peripheral.
 *
 * \section spi_configuration_macros SPI Configuration Macros
 * - \ref SPI_PCS
 * - \ref SPI_SCBR
 * - \ref SPI_DLYBS
 * - \ref SPI_DLYBCT
 */

/** Calculate the PCS field value given the chip select NPCS value */


/** Calculates the value of the CSR SCBR field given the baudrate and MCK. */


/** Calculates the value of the CSR DLYBS field given the desired delay (in ns) */


/** Calculates the value of the CSR DLYBCT field given the desired delay (in ns) */


/*------------------------------------------------------------------------------ */


 extern "C" {


/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/

extern void SPI_Enable( Spi* spi ) ;
extern void SPI_Disable( Spi* spi ) ;
extern void SPI_EnableIt( Spi* spi, uint32_t dwSources ) ;
extern void SPI_DisableIt( Spi* spi, uint32_t dwSources ) ;

extern void SPI_Configure( Spi* spi, uint32_t dwId, uint32_t dwConfiguration ) ;
extern void SPI_ConfigureNPCS( Spi* spi, uint32_t dwNpcs, uint32_t dwConfiguration ) ;

extern uint32_t SPI_Read( Spi* spi ) ;
extern void SPI_Write( Spi* spi, uint32_t dwNpcs, uint16_t wData ) ;

extern uint32_t SPI_GetStatus( Spi* spi ) ;
extern uint32_t SPI_IsFinished( Spi* pSpi ) ;
# 113 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/spi.h"
}
# 59 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/ssc.h" 1
/**
 * \file
 *
 * \brief Synchronous Serial Controller (SSC) driver for SAM.
 *
 * Copyright (c) 2011-2012 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */




# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/../chip.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 48 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/ssc.h" 2

/// @cond 0
/**INDENT-OFF**/

extern "C" {

/**INDENT-ON**/
/// @endcond

//! Receive stop selection.



//! Compare register ID.



//! SSC module default timeout. */


//! \brief SSC driver return codes.
enum ssc_return_code {
 SSC_RC_OK = 0, //!< OK
 SSC_RC_YES = 0, //!< Yes
 SSC_RC_NO = 1, //!< No
 SSC_RC_ERROR = 1, //!< General error
 SSC_RC_INVALID = 0xFFFFFFFF //!< Parameter invalid
};

//! Data frame structure.
typedef struct {
 //! Data bits length per transfer, should be 0 to 31.
 uint32_t ul_datlen;
 //! Bit sequence LSBF or MSBF.
 //! For receiver configuration, SSC_RFMR_MSBF or 0.
 //! For transmitter configuration, SSC_TFMR_MSBF or 0.
 uint32_t ul_msbf;
 //! Data number per frame, should be 0 to 15.
 uint32_t ul_datnb;
 //! Frame Sync. length should be 0 to 15.
 uint32_t ul_fslen;
 //! Frame Sync. length extension field, should be 0 to 15.
 uint32_t ul_fslen_ext;
 //! Frame Sync. output selection.
 //! For receiver configuration, one of SSC_RFMR_FSOS_NONE, SSC_RFMR_FSOS_NEGATIVE, SSC_RFMR_FSOS_POSITIVE,
 //! SSC_RFMR_FSOS_LOW, SSC_RFMR_FSOS_HIGH or SSC_RFMR_FSOS_TOGGLING.
 //! For transmitter configuration, one of SSC_TFMR_FSOS_NONE, SSC_TFMR_FSOS_NEGATIVE, SSC_TFMR_FSOS_POSITIVE
 //! SSC_TFMR_FSOS_LOW, SSC_TFMR_FSOS_HIGH, SSC_TFMR_FSOS_TOGGLING,
 uint32_t ul_fsos;
 //! Frame Sync. edge detection.
 //! For receiver configuration, SSC_RFMR_FSEDGE_POSITIVE or SSC_RFMR_FSEDGE_NEGATIVE.
 //! For transmitter configuration, SSC_TFMR_FSEDGE_POSITIVE or SSC_TFMR_FSEDGE_NEGATIVE.
 uint32_t ul_fsedge;
} data_frame_opt_t;

//! Clock mode structure.
typedef struct {
 //! Communication clock selection.
 //! For receiver configuration, one of SSC_RCMR_CKS_MCK, SSC_RCMR_CKS_TK or SSC_RCMR_CKS_RK.
 //! For transmitter configuration, one of SSC_TCMR_CKS_MCK, SSC_TCMR_CKS_TK or SSC_TCMR_CKS_RK.
 uint32_t ul_cks;
 //! Communication clock output mode selection.
 //! For receiver configuration, one of SSC_RCMR_CKO_NONE, SSC_RCMR_CKO_CONTINUOUS or SSC_RCMR_CKO_TRANSFER.
 //! For transmitter configuration, one of SSC_TCMR_CKO_NONE, SSC_TCMR_CKO_CONTINUOUS or SSC_TCMR_CKO_TRANSFER.
 uint32_t ul_cko;
 //! Communication clock inversion.
 //! For receiver configuration, SSC_RCMR_CKI or 0.
 //! For transmitter configuration, SSC_TCMR_CKI or 0.
 uint32_t ul_cki;
 //! Communication clock gating selection.
 //! For receiver configuration, one of SSC_RCMR_CKG_NONE, SSC_RCMR_CKG_CONTINUOUS and SSC_RCMR_CKG_TRANSFER.
 //! For transmitter configuration, one of SSC_TCMR_CKG_NONE, SSC_TCMR_CKG_CONTINUOUS and SSC_TCMR_CKG_TRANSFER.
 uint32_t ul_ckg;
 //! Period divider selection, should be 0 to 255.
 uint32_t ul_period;
 //! Communication start delay, should be 0 to 255.
 uint32_t ul_sttdly;
 //! Communication start selection.
 //! For receiver configuration, one of SSC_RCMR_START_CONTINUOUS, SSC_RCMR_START_TRANSMIT, SSC_RCMR_START_RF_LOW,
 //! SSC_RCMR_START_RF_HIGH, SSC_RCMR_START_RF_FALLING, SSC_RCMR_START_RF_RISING, SSC_RCMR_START_RF_LEVEL,
 //! SSC_RCMR_START_RF_EDGE or SSC_RCMR_START_CMP_0.
 //! For transmitter configuration, one of SSC_TCMR_START_CONTINUOUS, SSC_TCMR_START_TRANSMIT, SSC_TCMR_START_RF_LOW,
 //! SSC_TCMR_START_RF_HIGH, SSC_TCMR_START_RF_FALLING, SSC_TCMR_START_RF_RISING, SSC_TCMR_START_RF_LEVEL,
 //! SSC_TCMR_START_RF_EDGE or SSC_TCMR_START_CMP_0.
 uint32_t ul_start_sel;
} clock_opt_t;

//! SSC working role in I2S mode.





//! Bit for SSC Audio channel left.

//! Bit for SSC Audio channel right.

//! SSC Audio Channel modes.
enum {
 //! Mono, left channel enabled.
 SSC_AUDIO_MONO_LEFT = ((1 << 0)),
 //! Mono, right channel enabled.
 SSC_AUDIO_MONO_RIGHT = ((1 << 1)),
 //! Stereo, two channels.
 SSC_AUDIO_STERO = ((1 << 0) | (1 << 1))
};

uint32_t ssc_set_clock_divider(Ssc *p_ssc, uint32_t ul_bitclock, uint32_t ul_mck);
void ssc_i2s_set_transmitter(Ssc *p_ssc, uint32_t ul_mode,
  uint32_t ul_cks, uint32_t ul_ch_mode, uint32_t ul_datlen);
void ssc_i2s_set_receiver(Ssc *p_ssc, uint32_t ul_mode,
  uint32_t ul_cks, uint32_t ul_ch_mode, uint32_t ul_datlen);
void ssc_reset(Ssc *p_ssc);
void ssc_enable_rx(Ssc *p_ssc);
void ssc_disable_rx(Ssc *p_ssc);
void ssc_enable_tx(Ssc *p_ssc);
void ssc_disable_tx(Ssc *p_ssc);
void ssc_set_normal_mode(Ssc *p_ssc);
void ssc_set_loop_mode(Ssc *p_ssc);
void ssc_set_rx_stop_selection(Ssc *p_ssc, uint32_t ul_sel);
void ssc_set_td_default_level(Ssc *p_ssc, uint32_t ul_level);
void ssc_enable_tx_frame_sync_data(Ssc *p_ssc);
void ssc_disable_tx_frame_sync_data(Ssc *p_ssc);
void ssc_set_receiver(Ssc *p_ssc, clock_opt_t *p_rx_clk_opt, data_frame_opt_t *p_rx_data_frame);
void ssc_set_transmitter(Ssc *p_ssc, clock_opt_t *p_tx_clk_opt, data_frame_opt_t *p_tx_data_frame);
void ssc_set_rx_compare(Ssc *p_ssc, uint32_t ul_id, uint32_t ul_value);
uint32_t ssc_get_rx_compare(Ssc *p_ssc, uint32_t ul_id);
void ssc_enable_interrupt(Ssc *p_ssc, uint32_t ul_sources);
void ssc_disable_interrupt(Ssc *p_ssc, uint32_t ul_sources);
uint32_t ssc_get_interrupt_mask(Ssc *p_ssc);
uint32_t ssc_get_status(Ssc *p_ssc);
uint32_t ssc_is_tx_ready(Ssc *p_ssc);
uint32_t ssc_is_tx_empty(Ssc *p_ssc);
uint32_t ssc_is_rx_ready(Ssc *p_ssc);
uint32_t ssc_is_tx_enabled(Ssc *p_ssc);
uint32_t ssc_is_rx_enabled(Ssc *p_ssc);







uint32_t ssc_write(Ssc *p_ssc, uint32_t ul_frame);
uint32_t ssc_read(Ssc *p_ssc, uint32_t *ul_data);
void ssc_write_sync_data(Ssc *p_ssc, uint32_t ul_frame);
uint32_t ssc_read_sync_data(Ssc *p_ssc);

void *ssc_get_tx_access(Ssc *p_ssc);
void *ssc_get_rx_access(Ssc *p_ssc);

void ssc_set_writeprotect(Ssc *p_ssc, uint32_t ul_enable);
uint32_t ssc_get_writeprotect_status(Ssc *p_ssc);

/// @cond 0
/**INDENT-OFF**/

}

/**INDENT-ON**/
/// @endcond
# 60 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/tc.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011-2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/**
 *  \file
 *
 *  \section Purpose
 *
 *  Interface for configuring and using Timer Counter (TC) peripherals.
 *
 *  \section Usage
 *  -# Optionally, use TC_FindMckDivisor() to let the program find the best
 *     TCCLKS field value automatically.
 *  -# Configure a Timer Counter in the desired mode using TC_Configure().
 *  -# Start or stop the timer clock using TC_Start() and TC_Stop().
 */




/*------------------------------------------------------------------------------
 *         Headers
 *------------------------------------------------------------------------------*/

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/../chip.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 52 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/tc.h" 2



/*------------------------------------------------------------------------------
 *         Global functions
 *------------------------------------------------------------------------------*/


 extern "C" {


extern void TC_Configure( Tc *pTc, uint32_t dwChannel, uint32_t dwMode ) ;

extern void TC_Start( Tc *pTc, uint32_t dwChannel ) ;

extern void TC_Stop( Tc *pTc, uint32_t dwChannel ) ;

extern uint32_t TC_FindMckDivisor( uint32_t dwFreq, uint32_t dwMCk, uint32_t *dwDiv, uint32_t *dwTcClks, uint32_t dwBoardMCK ) ;

extern uint32_t TC_ReadCV(Tc *p_tc, uint32_t ul_channel);

extern uint32_t TC_GetStatus(Tc *p_tc, uint32_t ul_channel);

extern void TC_SetRA(Tc *tc, uint32_t chan, uint32_t v) ;

extern void TC_SetRB(Tc *tc, uint32_t chan, uint32_t v) ;

extern void TC_SetRC(Tc *tc, uint32_t chan, uint32_t v) ;


}
# 61 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/twi.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011-2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/**
 * \file
 *
 * Interface for configuration the Two Wire Interface (TWI) peripheral.
 *
 */




/*------------------------------------------------------------------------------
 *         Headers
 *------------------------------------------------------------------------------*/

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/../chip.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 45 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/twi.h" 2



/*----------------------------------------------------------------------------
 *        Macros
 *----------------------------------------------------------------------------*/
/* Returns 1 if the TXRDY bit (ready to transmit data) is set in the given status register value.*/


/* Returns 1 if the RXRDY bit (ready to receive data) is set in the given status register value.*/


/* Returns 1 if the TXCOMP bit (transfer complete) is set in the given status register value.*/



 extern "C" {


/*----------------------------------------------------------------------------
 *        External function
 *----------------------------------------------------------------------------*/

extern void TWI_ConfigureMaster(Twi *pTwi, uint32_t twck, uint32_t mck);

extern void TWI_SetClock( Twi *pTwi, uint32_t dwTwCk, uint32_t dwMCk );

extern void TWI_ConfigureSlave(Twi *pTwi, uint8_t slaveAddress);

extern void TWI_Disable(Twi *pTwi);

extern void TWI_Stop(Twi *pTwi);

extern void TWI_StartRead(
    Twi *pTwi,
    uint8_t address,
    uint32_t iaddress,
    uint8_t isize);

extern uint8_t TWI_ReadByte(Twi *pTwi);

extern void TWI_WriteByte(Twi *pTwi, uint8_t byte);

extern void TWI_StartWrite(
    Twi *pTwi,
    uint8_t address,
    uint32_t iaddress,
    uint8_t isize,
    uint8_t byte);

extern uint8_t TWI_ByteReceived(Twi *pTwi);

extern uint8_t TWI_ByteSent(Twi *pTwi);

extern uint8_t TWI_TransferComplete(Twi *pTwi);

extern void TWI_EnableIt(Twi *pTwi, uint32_t sources);

extern void TWI_DisableIt(Twi *pTwi, uint32_t sources);

extern uint32_t TWI_GetStatus(Twi *pTwi);

extern uint32_t TWI_GetMaskedStatus(Twi *pTwi);

extern void TWI_SendSTOPCondition(Twi *pTwi);


}
# 62 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/usart.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011-2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/**
 * \file
 *
 * \par Purpose
 *
 * This module provides several definitions and methods for using an USART
 * peripheral.
 *
 * \par Usage
 *
 * -# Enable the USART peripheral clock in the PMC.
 * -# Enable the required USART PIOs (see pio.h).
 * -# Configure the UART by calling USART_Configure.
 * -# Enable the transmitter and/or the receiver of the USART using
 *    USART_SetTransmitterEnabled and USART_SetReceiverEnabled.
 * -# Send data through the USART using the USART_Write and
 *    USART_WriteBuffer methods.
 * -# Receive data from the USART using the USART_Read and
 *    USART_ReadBuffer functions; the availability of data can be polled
 *    with USART_IsDataAvailable.
 * -# Disable the transmitter and/or the receiver of the USART with
 *    USART_SetTransmitterEnabled and USART_SetReceiverEnabled.
 */




/*------------------------------------------------------------------------------
 *         Headers
 *------------------------------------------------------------------------------*/

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/../chip.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 62 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/usart.h" 2



/*------------------------------------------------------------------------------
 *         Definitions
 *------------------------------------------------------------------------------*/

/** \section USART_mode USART modes
 * This section lists several common operating modes for an USART peripheral.
 *
 * \b Modes
 * - USART_MODE_ASYNCHRONOUS
 * - USART_MODE_IRDA
 */

/** Basic asynchronous mode, i.e. 8 bits no parity.*/


/** IRDA mode*/


/** SPI mode*/
# 95 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/usart.h"
 extern "C" {


/*------------------------------------------------------------------------------*/
/*         Exported functions                                                   */
/*------------------------------------------------------------------------------*/

extern void USART_Configure( Usart *usart, uint32_t mode, uint32_t baudrate, uint32_t masterClock ) ;
extern uint32_t USART_GetStatus( Usart *usart ) ;
extern void USART_EnableIt( Usart *usart,uint32_t mode ) ;
extern void USART_DisableIt( Usart *usart,uint32_t mode ) ;
extern void USART_SetTransmitterEnabled( Usart *usart, uint8_t enabled ) ;

extern void USART_SetReceiverEnabled( Usart *usart, uint8_t enabled ) ;

extern void USART_Write( Usart *usart, uint16_t data, volatile uint32_t timeOut ) ;

extern uint8_t USART_WriteBuffer( Usart *usart, void *buffer, uint32_t size ) ;

extern uint16_t USART_Read( Usart *usart, volatile uint32_t timeOut ) ;

extern uint8_t USART_ReadBuffer( Usart *usart, void *buffer, uint32_t size ) ;

extern uint8_t USART_IsDataAvailable( Usart *usart ) ;

extern void USART_SetIrdaFilter(Usart *pUsart, uint8_t filter);

extern void USART_PutChar( Usart *usart, uint8_t c ) ;

extern uint32_t USART_IsRxReady( Usart *usart ) ;

extern uint8_t USART_GetChar( Usart *usart ) ;


}
# 63 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/wdt.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011-2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/**
 * \file
 *
 * \section Purpose
 * Interface for Watchdog Timer (WDT) controller.
 *
 * \section Usage
 * -# Enable watchdog with given mode using \ref WDT_Enable().
 * -# Disable watchdog using \ref WDT_Disable()
 * -# Restart the watchdog using \ref WDT_Restart().
 * -# Get watchdog status using \ref  WDT_GetStatus().
 * -# Caculate watchdog period value using \ref WDT_GetPeriod().
 */




# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/../chip.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 48 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/wdt.h" 2




 extern "C" {


/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/

extern void WDT_Enable( Wdt* pWDT, uint32_t dwMode ) ;

extern void WDT_Disable( Wdt* pWDT ) ;

extern void WDT_Restart( Wdt* pWDT ) ;

extern uint32_t WDT_GetStatus( Wdt* pWDT ) ;

extern uint32_t WDT_GetPeriod( uint32_t dwMs ) ;


}
# 64 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/timetick.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011-2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/**
 *  \file
 *
 *  \par Purpose
 *
 *  Methods and definitions for Global time tick and wait functions.
 *
 *  Defines a common and simpliest use of Time Tick, to increase tickCount
 *  every 1ms, the application can get this value through GetTickCount().
 *
 *  \par Usage
 *
 *  -# Configure the System Tick with TimeTick_Configure() when MCK changed
 *     \note
 *     Must be done before any invoke of GetTickCount(), Wait() or Sleep().
 *  -# Uses GetTickCount to get current tick value.
 *  -# Uses Wait to wait several ms.
 *  -# Uses Sleep to enter wait for interrupt mode to wait several ms.
 *
 */




/*----------------------------------------------------------------------------
 *         Headers
 *----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------
 *         Definitions
 *----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 *         Global functions
 *----------------------------------------------------------------------------*/

extern uint32_t TimeTick_Configure( uint32_t dwNew_MCK ) ;

extern void TimeTick_Increment( void ) ;

extern uint32_t GetTickCount( void ) ;

extern void Wait( volatile uint32_t dwMs ) ;

extern void Sleep( volatile uint32_t dwMs ) ;
# 66 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/USB_device.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011-2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */






extern void UDD_WaitIN(void);
extern void UDD_WaitOUT(void);
extern void UDD_ClearIN(void);
extern void UDD_ClearOUT(void);
extern uint32_t UDD_WaitForINOrOUT(void);
extern void UDD_ClearRxFlag(unsigned char bEndpoint);
extern uint32_t UDD_ReceivedSetupInt(void);
extern void UDD_ClearSetupInt(void);
extern uint32_t UDD_ReadWriteAllowed(uint32_t ep);
extern uint32_t UDD_FifoByteCount(uint32_t ep);
extern uint8_t UDD_FifoFree(void);
extern void UDD_ReleaseRX(uint32_t ep);
extern void UDD_ReleaseTX(uint32_t ep);
extern uint8_t UDD_FrameNumber(void);
extern uint8_t UDD_GetConfiguration(void);

extern uint32_t UDD_Send(uint32_t ep, const void* data, uint32_t len);
extern void UDD_Send8(uint32_t ep, uint8_t data );
extern uint8_t UDD_Recv8(uint32_t ep);
extern void UDD_Recv(uint32_t ep, uint8_t* data, uint32_t len);

extern void UDD_InitEndpoints(const uint32_t* eps_table, const uint32_t ul_eps_table_size);
extern void UDD_InitControl(int end);
extern uint32_t UDD_Init(void);
extern void UDD_InitEP( uint32_t ul_ep, uint32_t ul_ep_cfg );

extern void UDD_Attach(void);
extern void UDD_Detach(void);

extern void UDD_SetStack(void (*pf_isr)(void));
extern void UDD_SetAddress(uint32_t addr);
extern void UDD_Stall(void);
extern uint32_t UDD_GetFrameNumber(void);

/*! \name Usual Types
 */

//! @{

typedef unsigned char Bool; //!< Boolean.





typedef int8_t S8; //!< 8-bit signed integer.
typedef uint8_t U8; //!< 8-bit unsigned integer.
typedef int16_t S16; //!< 16-bit signed integer.
typedef uint16_t U16; //!< 16-bit unsigned integer.
typedef uint16_t le16_t;
typedef uint16_t be16_t;
typedef int32_t S32; //!< 32-bit signed integer.
typedef uint32_t U32; //!< 32-bit unsigned integer.
typedef uint32_t le32_t;
typedef uint32_t be32_t;
typedef int64_t S64; //!< 64-bit signed integer.
typedef uint64_t U64; //!< 64-bit unsigned integer.
typedef float F32; //!< 32-bit floating-point number.
typedef double F64; //!< 64-bit floating-point number.
typedef uint32_t iram_size_t;

//! @}

/*! \name Bit-Field Handling
 */
//! @{

/*! \brief Reads the bits of a value specified by a given bit-mask.
 *
 * \param value Value to read bits from.
 * \param mask  Bit-mask indicating bits to read.
 *
 * \return Read bits.
 */


/*! \brief Writes the bits of a C lvalue specified by a given bit-mask.
 *
 * \param lvalue  C lvalue to write bits to.
 * \param mask    Bit-mask indicating bits to write.
 * \param bits    Bits to write.
 *
 * \return Resulting value with written bits.
 */



/*! \brief Tests the bits of a value specified by a given bit-mask.
 *
 * \param value Value of which to test bits.
 * \param mask  Bit-mask indicating bits to test.
 *
 * \return \c 1 if at least one of the tested bits is set, else \c 0.
 */


/*! \brief Clears the bits of a C lvalue specified by a given bit-mask.
 *
 * \param lvalue  C lvalue of which to clear bits.
 * \param mask    Bit-mask indicating bits to clear.
 *
 * \return Resulting value with cleared bits.
 */


/*! \brief Sets the bits of a C lvalue specified by a given bit-mask.
 *
 * \param lvalue  C lvalue of which to set bits.
 * \param mask    Bit-mask indicating bits to set.
 *
 * \return Resulting value with set bits.
 */


/*! \brief Toggles the bits of a C lvalue specified by a given bit-mask.
 *
 * \param lvalue  C lvalue of which to toggle bits.
 * \param mask    Bit-mask indicating bits to toggle.
 *
 * \return Resulting value with toggled bits.
 */


/*! \brief Reads the bit-field of a value specified by a given bit-mask.
 *
 * \param value Value to read a bit-field from.
 * \param mask  Bit-mask indicating the bit-field to read.
 *
 * \return Read bit-field.
 */


/*! \brief Writes the bit-field of a C lvalue specified by a given bit-mask.
 *
 * \param lvalue    C lvalue to write a bit-field to.
 * \param mask      Bit-mask indicating the bit-field to write.
 * \param bitfield  Bit-field to write.
 *
 * \return Resulting value with written bit-field.
 */


//! @}

/*! \name Token Paste
 *
 * Paste N preprocessing tokens together, these tokens being allowed to be \#defined.
 *
 * May be used only within macros with the tokens passed as arguments if the tokens are \#defined.
 *
 * For example, writing TPASTE2(U, WIDTH) within a macro \#defined by
 * UTYPE(WIDTH) and invoked as UTYPE(UL_WIDTH) with UL_WIDTH \#defined as 32 is
 * equivalent to writing U32.
 */

//! @{
# 202 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/USB_device.h"
//! @}

/*! \name Absolute Token Paste
 *
 * Paste N preprocessing tokens together, these tokens being allowed to be \#defined.
 *
 * No restriction of use if the tokens are \#defined.
 *
 * For example, writing ATPASTE2(U, UL_WIDTH) anywhere with UL_WIDTH \#defined
 * as 32 is equivalent to writing U32.
 */

//! @{
# 226 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/USB_device.h"
//! @}

/*! \brief Counts the trailing zero bits of the given value considered as a 32-bit integer.
 *
 * \param u Value of which to count the trailing zero bits.
 *
 * \return The count of trailing zero bits in \a u.
 */
# 272 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/USB_device.h"
/*! \name Zero-Bit Counting
 *
 * Under GCC, __builtin_clz and __builtin_ctz behave like macros when
 * applied to constant expressions (values known at compile time), so they are
 * more optimized than the use of the corresponding assembly instructions and
 * they can be used as constant expressions e.g. to initialize objects having
 * static storage duration, and like the corresponding assembly instructions
 * when applied to non-constant expressions (values unknown at compile time), so
 * they are more optimized than an assembly periphrasis. Hence, clz and ctz
 * ensure a possible and optimized behavior for both constant and non-constant
 * expressions.
 */
//! @{

/*! \brief Counts the leading zero bits of the given value considered as a 32-bit integer.
 *
 * \param u Value of which to count the leading zero bits.
 *
 * \return The count of leading zero bits in \a u.
 */
# 332 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/USB_device.h"
/*! \name Mathematics
 *
 * The same considerations as for clz and ctz apply here but GCC does not
 * provide built-in functions to access the assembly instructions abs, min and
 * max and it does not produce them by itself in most cases, so two sets of
 * macros are defined here:
 *   - Abs, Min and Max to apply to constant expressions (values known at
 *     compile time);
 *   - abs, min and max to apply to non-constant expressions (values unknown at
 *     compile time), abs is found in stdlib.h.
 */
//! @{

/*! \brief Takes the absolute value of \a a.
 *
 * \param a Input value.
 *
 * \return Absolute value of \a a.
 *
 * \note More optimized if only used with values known at compile time.
 */


/*! \brief Takes the minimal value of \a a and \a b.
 *
 * \param a Input value.
 * \param b Input value.
 *
 * \return Minimal value of \a a and \a b.
 *
 * \note More optimized if only used with values known at compile time.
 */


/*! \brief Takes the maximal value of \a a and \a b.
 *
 * \param a Input value.
 * \param b Input value.
 *
 * \return Maximal value of \a a and \a b.
 *
 * \note More optimized if only used with values known at compile time.
 */


// abs() is already defined by stdlib.h

/*! \brief Takes the minimal value of \a a and \a b.
 *
 * \param a Input value.
 * \param b Input value.
 *
 * \return Minimal value of \a a and \a b.
 *
 * \note More optimized if only used with values unknown at compile time.
 */


/*! \brief Takes the maximal value of \a a and \a b.
 *
 * \param a Input value.
 * \param b Input value.
 *
 * \return Maximal value of \a a and \a b.
 *
 * \note More optimized if only used with values unknown at compile time.
 */


//! @}
# 67 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/USB_host.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011-2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */
# 41 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/USB_host.h"
//! \brief Device speed
/*typedef enum {
	UHD_SPEED_LOW  = 0,
	UHD_SPEED_FULL = 1,
	UHD_SPEED_HIGH = 2,
} uhd_speed_t;*/

//! States of USBB interface
typedef enum {
 UHD_STATE_NO_VBUS = 0,
 UHD_STATE_DISCONNECTED = 1,
 UHD_STATE_CONNECTED = 2,
 UHD_STATE_ERROR = 3,
} uhd_vbus_state_t;

//extern uhd_speed_t uhd_get_speed(void);

extern void UHD_SetStack(void (*pf_isr)(void));
extern void UHD_Init(void);
extern void UHD_BusReset(void);
extern uhd_vbus_state_t UHD_GetVBUSState(void);
extern uint32_t UHD_Pipe0_Alloc(uint32_t ul_add, uint32_t ul_ep_size);
extern uint32_t UHD_Pipe_Alloc(uint32_t ul_dev_addr, uint32_t ul_dev_ep, uint32_t ul_type, uint32_t ul_dir, uint32_t ul_maxsize, uint32_t ul_interval, uint32_t ul_nb_bank);
extern void UHD_Pipe_Free(uint32_t ul_pipe);
extern uint32_t UHD_Pipe_Read(uint32_t ul_pipe, uint32_t ul_size, uint8_t* data);
extern void UHD_Pipe_Write(uint32_t ul_pipe, uint32_t ul_size, uint8_t* data);
extern void UHD_Pipe_Send(uint32_t ul_pipe, uint32_t ul_token_type);
extern uint32_t UHD_Pipe_Is_Transfer_Complete(uint32_t ul_pipe, uint32_t ul_token_type);
# 68 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2


# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/can.h" 1
/**
 * \file
 *
 * \brief Controller Area Network (CAN) driver module for SAM.
 *
 * Copyright (c) 2011 - 2012 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */




# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/../chip.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 48 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/can.h" 2

/** @cond 0 */
/**INDENT-OFF**/

extern "C" {

/**INDENT-ON**/
/** @endcond */

/** Define the Mailbox mask for eight mailboxes. */


/** Disable all interrupt mask */


/** Define the typical baudrate for CAN communication in KHz. */
# 74 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/can.h"
/** Define the mailbox mode. */







/** Define CAN mailbox transfer status code. */





/** Define the struct for CAN message mailbox. */
typedef struct {
 uint32_t ul_mb_idx;
 uint8_t uc_obj_type; //! Mailbox object type, one of the six different objects.
 uint8_t uc_id_ver; //! 0 stands for standard frame, 1 stands for extended frame.
 uint8_t uc_length; //! Received data length or transmitted data length.
 uint8_t uc_tx_prio; //! Mailbox priority, no effect in receive mode.
 uint32_t ul_status; //! Mailbox status register value.
 uint32_t ul_id_msk; //! No effect in transmit mode.
 uint32_t ul_id; //! Received frame ID or the frame ID to be transmitted.
 uint32_t ul_fid; //! Family ID.
 uint32_t ul_datal;
 uint32_t ul_datah;
} can_mb_conf_t;

/**
 * \defgroup sam_driver_can_group Controller Area Network (CAN) Driver
 *
 * See \ref sam_can_quickstart.
 *
 * \par Purpose
 *
 * The CAN controller provides all the features required to implement
 * the serial communication protocol CAN defined by Robert Bosch GmbH,
 * the CAN specification. This is a driver for configuration, enabling,
 * disabling and use of the CAN peripheral.
 *
 * @{
 */

uint32_t can_init(Can *p_can, uint32_t ul_mck, uint32_t ul_baudrate);

void can_enable(Can *p_can);
void can_disable(Can *p_can);

void can_disable_low_power_mode(Can *p_can);
void can_enable_low_power_mode(Can *p_can);

void can_disable_autobaud_listen_mode(Can *p_can);
void can_enable_autobaud_listen_mode(Can *p_can);

void can_disable_overload_frame(Can *p_can);
void can_enable_overload_frame(Can *p_can);

void can_set_timestamp_capture_point(Can *p_can, uint32_t ul_flag);

void can_disable_time_triggered_mode(Can *p_can);
void can_enable_time_triggered_mode(Can *p_can);

void can_disable_timer_freeze(Can *p_can);
void can_enable_timer_freeze(Can *p_can);

void can_disable_tx_repeat(Can *p_can);
void can_enable_tx_repeat(Can *p_can);

void can_set_rx_sync_stage(Can *p_can, uint32_t ul_stage);

void can_enable_interrupt(Can *p_can, uint32_t dw_mask);
void can_disable_interrupt(Can *p_can, uint32_t dw_mask);

uint32_t can_get_interrupt_mask(Can *p_can);

uint32_t can_get_status(Can *p_can);

uint32_t can_get_internal_timer_value(Can *p_can);

uint32_t can_get_timestamp_value(Can *p_can);

uint8_t can_get_tx_error_cnt(Can *p_can);
uint8_t can_get_rx_error_cnt(Can *p_can);

void can_reset_internal_timer(Can *p_can);

void can_global_send_transfer_cmd(Can *p_can, uint8_t uc_mask);
void can_global_send_abort_cmd(Can *p_can, uint8_t uc_mask);

/*
 * Mailbox functions
 */
void can_mailbox_set_timemark(Can *p_can, uint8_t uc_index, uint16_t us_cnt);
uint32_t can_mailbox_get_status(Can *p_can, uint8_t uc_index);
void can_mailbox_send_transfer_cmd(Can *p_can, uint8_t uc_index);
void can_mailbox_send_abort_cmd(Can *p_can, uint8_t uc_index);
void can_mailbox_init(Can *p_can, can_mb_conf_t *p_mailbox);
uint32_t can_mailbox_read(Can *p_can, can_mb_conf_t *p_mailbox);
uint32_t can_mailbox_write(Can *p_can, can_mb_conf_t *p_mailbox);
uint32_t can_mailbox_tx_remote_frame(Can *p_can, can_mb_conf_t *p_mailbox);
void can_reset_all_mailbox(Can *p_can);

// from wilfredo
uint32_t can_reset_mailbox_data(can_mb_conf_t *p_mailbox);

/** @} */

/** @cond 0 */
/**INDENT-OFF**/

}

/**INDENT-ON**/
/** @endcond */

/**
 * \page sam_can_quickstart Quickstart guide for SAM CAN module.
 *
 * This is the quickstart guide for the \ref sam_drivers_can_group "SAM CAN module",
 * with step-by-step instructions on how to configure and use the drivers in a
 * selection of use cases.
 *
 * The use cases contain several code fragments. The code fragments in the
 * steps for setup can be copied into a custom initialization function, while
 * the steps for usage can be copied into, e.g., the main application function.
 *
 * \section can_basic_use_case Basic use case
 * In this basic use case, as CAN module needs to work in network, two CAN modules
 * need to be configured. CAN0 mailbox 0 is configured as transmitter, and CAN1 mailbox 0
 * is configured as receiver. The communication baudrate is 1Mbit/s.
 *
 * \section can_basic_use_case_setup Setup steps
 *
 * \subsection can_basic_use_case_setup_prereq Prerequisites
 *  - \ref group_pmc "Power Management Controller driver"
 *  - \ref group_sn65hvd234_transceiver "CAN transceiver driver"
 *
 * \subsection can_basic_use_case_setup_code Example code
 * Add to application initialization:
 * \code
 *    can_mb_conf_t can0_mailbox;
 *    can_mb_conf_t can1_mailbox;
 *
 *    pmc_enable_periph_clk(ID_CAN0);
 *    pmc_enable_periph_clk(ID_CAN1);
 *
 *    can_init(CAN0, ul_sysclk, CAN_BPS_1000K);
 *    can_init(CAN1, ul_sysclk, CAN_BPS_1000K);
 *
 *    can_reset_all_mailbox(CAN0);
 *    can_reset_all_mailbox(CAN1);
 *
 *    can1_mailbox.ul_mb_idx = 0;
 *    can1_mailbox.uc_obj_type = CAN_MB_RX_MODE;
 *    can1_mailbox.ul_id_msk = CAN_MAM_MIDvA_Msk | CAN_MAM_MIDvB_Msk;
 *    can1_mailbox.ul_id = CAN_MID_MIDvA(0x07);
 *    can_mailbox_init(CAN1, &can1_mailbox);
 *
 *    can0_mailbox.ul_mb_idx = 0;
 *    can0_mailbox.uc_obj_type = CAN_MB_TX_MODE;
 *    can0_mailbox.uc_tx_prio = 15;
 *    can0_mailbox.uc_id_ver = 0;
 *    can0_mailbox.ul_id_msk = 0;
 *    can_mailbox_init(CAN0, &can0_mailbox);
 *
 *    can0_mailbox.ul_id = CAN_MID_MIDvA(0x07);
 *    can0_mailbox.ul_datal = 0x12345678;
 *    can0_mailbox.ul_datah = 0x87654321;
 *    can0_mailbox.uc_length = 8;
 *    can_mailbox_write(CAN0, &can0_mailbox);
 * \endcode
 *
 * \subsection can_basic_use_case_setup_flow Workflow
 * -# Define the CAN0 and CAN1 Transfer mailbox structure:
 *   - \code
 *    can_mb_conf_t can0_mailbox;
 *    can_mb_conf_t can1_mailbox;
 *   \endcode
 * -# Enable the module clock for CAN0 and CAN1:
 *   - \code
 *    pmc_enable_periph_clk(ID_CAN0);
 *    pmc_enable_periph_clk(ID_CAN1);
 *   \endcode
 * -# Initialize CAN0 and CAN1, baudrate is 1Mb/s:
 *   - \code
 *    can_init(CAN0, ul_sysclk, CAN_BPS_1000K);
 *    can_init(CAN1, ul_sysclk, CAN_BPS_1000K);
 *   \endcode
 *   - \note The CAN transceiver should be configured before initializing the CAN module.
 * -# Reset all CAN0 and CAN1 mailboxes:
 *   - \code
 *    can_reset_all_mailbox(CAN0);
 *    can_reset_all_mailbox(CAN1);
 *   \endcode
 * -# Initialize CAN1 mailbox 0 as receiver, frame ID is 0x07:
 *   - \code
 *    can1_mailbox.ul_mb_idx = 0;
 *    can1_mailbox.uc_obj_type = CAN_MB_RX_MODE;
 *    can1_mailbox.ul_id_msk = CAN_MAM_MIDvA_Msk | CAN_MAM_MIDvB_Msk;
 *    can1_mailbox.ul_id = CAN_MID_MIDvA(0x07);
 *    can_mailbox_init(CAN1, &can1_mailbox);
 *   \endcode
 * -# Initialize CAN0 mailbox 0 as transmitter, transmit priority is 15:
 *   - \code
 *    can0_mailbox.ul_mb_idx = 0;
 *    can0_mailbox.uc_obj_type = CAN_MB_TX_MODE;
 *    can0_mailbox.uc_tx_prio = 15;
 *    can0_mailbox.uc_id_ver = 0;
 *    can0_mailbox.ul_id_msk = 0;
 *    can_mailbox_init(CAN0, &can0_mailbox);
 *   \endcode
 * -# Prepare transmit ID, data and data length in CAN0 mailbox 0:
 *   - \code
 *    can0_mailbox.ul_id = CAN_MID_MIDvA(0x07);
 *    can0_mailbox.ul_datal = 0x12345678;
 *    can0_mailbox.ul_datah = 0x87654321;
 *    can0_mailbox.uc_length = 8;
 *    can_mailbox_write(CAN0, &can0_mailbox);
 *   \endcode
 *
 * \section can_basic_use_case_usage Usage steps
 *
 * \subsection can_basic_use_case_usage_code Example code
 * Add to, e.g., main loop in application C-file:
 * \code
 *    can_global_send_transfer_cmd(CAN0, CAN_TCR_MB0);
 *
 *    while (!(can_mailbox_get_status(CAN1, 0) & CAN_MSR_MRDY)) {
 *    }
 *
 *    can_mailbox_read(CAN1, &can1_mailbox);
 * \endcode
 *
 * \subsection can_basic_use_case_usage_flow Workflow
 * -# Send out data in CAN0 mailbox 0:
 *   - \code can_global_send_transfer_cmd(CAN0, CAN_TCR_MB0); \endcode
 * -# Wait for CAN1 mailbox 0 to receive the data:
 *   - \code
 *    while (!(can_mailbox_get_status(CAN1, 0) & CAN_MSR_MRDY)) {
 *    }
 *   \endcode
 * -# Read the received data from CAN1 mailbox 0:
 *   - \code can_mailbox_read(CAN1, &can1_mailbox); \endcode
 *
 * \section can_use_cases Advanced use cases
 * For more advanced use of the CAN driver, see the following use cases:
 * - \subpage can_use_case_1 : Two CAN modules work in PRODUCER and CONSUMER mode
 * respectively, use CAN interrupt handler to check whether the communication has been
 * completed.
 */

/**
 * \page can_use_case_1 Use case #1
 *
 * In this use case, CAN0 mailbox 0 works in PRODUCER mode, and CAN1 mailbox 0
 * works in CONSUMER mode. While CAN1 mailbox 0 receives a data frame from the bus,
 * an interrupt is triggered.
 *
 * \section can_use_case_1_setup Setup steps
 *
 * \subsection can_basic_use_case_setup_prereq Prerequisites
 *  - \ref group_pmc "Power Management Controller driver"
 *  - \ref group_sn65hvd234_transceiver "CAN transceiver driver"
 *
 * \subsection can_use_case_1_setup_code Example code
 * Add to application C-file:
 * \code
 *    can_mb_conf_t can0_mailbox;
 *    can_mb_conf_t can1_mailbox;
 *    volatile uint32_t g_ul_recv_status = 0;
 * \endcode
 *
 * \code
 *    void CAN1_Handler(void)
 *    {
 *        uint32_t ul_status;
 *
 *        ul_status = can_mailbox_get_status(CAN1, 0);
 *        if ((ul_status & CAN_MSR_MRDY) == CAN_MSR_MRDY) {
 *            can1_mailbox.ul_mb_idx = 0;
 *            can1_mailbox.ul_status = ul_status;
 *            can_mailbox_read(CAN1, &can1_mailbox);
 *            g_ul_recv_status = 1;
 *        }
 *    }
 * \endcode
 *
 * \code
 *    pmc_enable_periph_clk(ID_CAN0);
 *    pmc_enable_periph_clk(ID_CAN1);
 *
 *    can_init(CAN0, ul_sysclk, CAN_BPS_1000K);
 *    can_init(CAN1, ul_sysclk, CAN_BPS_1000K);
 *
 *    can_reset_all_mailbox(CAN0);
 *    can_reset_all_mailbox(CAN1);
 *
 *    can0_mailbox.ul_mb_idx = 0;
 *    can0_mailbox.uc_obj_type = CAN_MB_PRODUCER_MODE;
 *    can0_mailbox.ul_id_msk = 0;
 *    can0_mailbox.ul_id = CAN_MID_MIDvA(0x0b);
 *    can_mailbox_init(CAN0, &can0_mailbox);
 *
 *    can0_mailbox.ul_datal = 0x11223344;
 *    can0_mailbox.ul_datah = 0x44332211;
 *    can0_mailbox.uc_length = 8;
 *    can_mailbox_write(CAN0, &can0_mailbox);
 *
 *    can1_mailbox.ul_mb_idx = 0;
 *    can1_mailbox.uc_obj_type = CAN_MB_CONSUMER_MODE;
 *    can1_mailbox.uc_tx_prio = 15;
 *    can1_mailbox.ul_id_msk = CAN_MID_MIDvA_Msk | CAN_MID_MIDvB_Msk;
 *    can1_mailbox.ul_id = CAN_MID_MIDvA(0x0b);
 *    can_mailbox_init(CAN1, &can1_mailbox);
 *
 *    can_enable_interrupt(CAN1, CAN_IER_MB0);
 *    NVIC_EnableIRQ(CAN1_IRQn);
 * \endcode
 *
 * \subsection can_use_case_1_setup_flow Workflow
 * -# Define the CAN0 and CAN1 Transfer mailbox structure:
 *   - \code
 *    can_mb_conf_t can0_mailbox;
 *    can_mb_conf_t can1_mailbox;
 *   \endcode
 * -# Define the receive flag that is changed in CAN1 ISR handler:
 *   - \code volatile uint32_t g_ul_recv_status = 0; \endcode
 * -# Define the CAN1 ISR handler in the application:
 *   - \code void CAN1_Handler(void); \endcode
 * -# In CAN1_Handler(), get CAN1 mailbox 0 status:
 *   - \code ul_status = can_mailbox_get_status(CAN1, 0); \endcode
 * -# In CAN1_Handler(), check whether the mailbox 0 has received a data frame:
 *   - \code
 *    if ((ul_status & CAN_MSR_MRDY) == CAN_MSR_MRDY) {
 *        can1_mailbox.ul_mb_idx = 0;
 *        can1_mailbox.ul_status = ul_status;
 *        can_mailbox_read(CAN1, &can1_mailbox);
 *        g_ul_recv_status = 1;
 *    }
 *   \endcode
 * -# In CAN1_Handler(), if mailbox 0 is ready, read the received data from CAN1 mailbox 0:
 *   - \code
 *    can1_mailbox.ul_mb_idx = 0;
 *    can1_mailbox.ul_status = ul_status;
 *    can_mailbox_read(CAN1, &can1_mailbox);
 *   \endcode
 * -# In CAN1_Handler(), if mailbox 0 is ready, set up the receive flag:
 *   - \code g_ul_recv_status = 1; \endcode
 * -# Enable the module clock for CAN0 and CAN1:
 *   - \code
 *    pmc_enable_periph_clk(ID_CAN0);
 *    pmc_enable_periph_clk(ID_CAN1);
 *   \endcode
 * -# Initialize CAN0 and CAN1, baudrate is 1Mb/s:
 *   - \code
 *    can_init(CAN0, ul_sysclk, CAN_BPS_1000K);
 *    can_init(CAN1, ul_sysclk, CAN_BPS_1000K);
 *   \endcode
 *   - \note The CAN transceiver should be configured before initializing the CAN module.
 * -# Reset all CAN0 and CAN1 mailboxes:
 *   - \code
 *    can_reset_all_mailbox(CAN0);
 *    can_reset_all_mailbox(CAN1);
 *   \endcode
 * -# Initialize CAN0 mailbox 0 as PRODUCER:
 *   - \code
 *    can0_mailbox.ul_mb_idx = 0;
 *    can0_mailbox.uc_obj_type = CAN_MB_PRODUCER_MODE;
 *    can0_mailbox.ul_id_msk = 0;
 *    can0_mailbox.ul_id = CAN_MID_MIDvA(0x0b);
 *    can_mailbox_init(CAN0, &can0_mailbox);
 *   \endcode
 * -# Prepare the response information when it receives a remote frame:
 *   - \code
 *    can0_mailbox.ul_datal = 0x11223344;
 *    can0_mailbox.ul_datah = 0x44332211;
 *    can0_mailbox.uc_length = 8;
 *    can_mailbox_write(CAN0, &can0_mailbox);
 *   \endcode
 * -# Initialize CAN1 mailbox 0 as CONSUMER:
 *   - \code
 *    can1_mailbox.ul_mb_idx = 0;
 *    can1_mailbox.uc_obj_type = CAN_MB_CONSUMER_MODE;
 *    can1_mailbox.uc_tx_prio = 15;
 *    can1_mailbox.ul_id_msk = CAN_MID_MIDvA_Msk | CAN_MID_MIDvB_Msk;
 *    can1_mailbox.ul_id = CAN_MID_MIDvA(0x0b);
 *    can_mailbox_init(CAN1, &can1_mailbox);
 *   \endcode
 * -# Enable the CAN1 mailbox 0 interrupt:
 *   - \code
 *    can_enable_interrupt(CAN1, CAN_IER_MB0);
 *    NVIC_EnableIRQ(CAN1_IRQn);
 *   \endcode
 *
 * \section can_use_case_1_usage Usage steps
 *
 * \subsection can_use_case_1_usage_code Example code
 * \code
 *    can_global_send_transfer_cmd(CAN0, CAN_TCR_MB0);
 *    can_global_send_transfer_cmd(CAN1, CAN_TCR_MB0);
 *
 *    while (!g_ul_recv_status) {
 *    }
 * \endcode
 *
 * \subsection can_use_case_1_usage_flow Workflow
 * -# Enable CAN0 mailbox 0 to receive remote frame and respond it:
 *   - \code can_global_send_transfer_cmd(CAN0, CAN_TCR_MB0); \endcode
 * -# Enable CAN1 mailbox 0 to send out a remote frame and then receive data frame from bus:
 *   - \code can_global_send_transfer_cmd(CAN1, CAN_TCR_MB0); \endcode
 * -# Wait for the communication to be completed.
 *   - \code
 *    while (!g_ul_recv_status) {
 *    }
 *   \endcode
 */
# 71 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/emac.h" 1
 /**
 * \file
 *
 * \brief EMAC (Ethernet MAC) driver for SAM.
 *
 * Copyright (c) 2011-2012 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */




# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/../chip.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 48 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/emac.h" 2
//#include "conf_eth.h"

/// @cond 0
/**INDENT-OFF**/

extern "C" {

/**INDENT-ON**/
/// @endcond

/** The buffer addresses written into the descriptors must be aligned, so the
    last few bits are zero.  These bits have special meaning for the EMAC
    peripheral and cannot be used as part of the address. */
# 93 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/emac.h"
/** The MAC can support frame lengths up to 1536 bytes */





/** EMAC clock speed */





/** EMAC maintain code default value*/


/** EMAC maintain start of frame default value*/


/** EMAC maintain read/write*/


/** EMAC maintain read only*/


/** EMAC address length */


/**
 * \brief Return codes for EMAC APIs.
 */
typedef enum {
 EMAC_OK = 0, /** Operation OK */
 EMAC_TIMEOUT = 1, /** EMAC operation timeout */
 EMAC_TX_BUSY, /** TX in progress */
 EMAC_RX_NULL, /** No data received */
 EMAC_SIZE_TOO_SMALL, /** Buffer size not enough */
 EMAC_PARAM, /** Parameter error, TX packet invalid or RX size too small */
 EMAC_INVALID = 0xFF, /* Invalid */
} emac_status_t;






/** Receive buffer descriptor struct */
typedef struct emac_rx_descriptor {
 union emac_rx_addr {
  uint32_t val;
  struct emac_rx_addr_bm {
   uint32_t b_ownership:1, /**< User clear, EMAC sets this to 1 once it has successfully written a frame to memory */
   b_wrap:1, /**< Marks last descriptor in receive buffer */
   addr_dw:30; /**< Address in number of DW */
  } bm;
 } addr; /**< Address, Wrap & Ownership */
 union emac_rx_status {
  uint32_t val;
  struct emac_rx_status_bm {
   uint32_t len:12, /** Length of frame including FCS */
   offset:2, /** Receive buffer offset,  bits 13:12 of frame length for jumbo frame */
   b_sof:1, /** Start of frame */
   b_eof:1, /** End of frame */
   b_cfi:1, /** Concatenation Format Indicator */
   vlan_priority:3, /** VLAN priority (if VLAN detected) */
   b_priority_detected:1, /** Priority tag detected */
   b_vlan_detected:1, /**< VLAN tag detected */
   b_type_id_match:1, /**< Type ID match */
   b_addr4match:1, /**< Address register 4 match */
   b_addr3match:1, /**< Address register 3 match */
   b_addr2match:1, /**< Address register 2 match */
   b_addr1match:1, /**< Address register 1 match */
   reserved:1,
   b_ext_addr_match:1, /**< External address match */
   b_uni_hash_match:1, /**< Unicast hash match */
   b_multi_hash_match:1, /**< Multicast hash match */
   b_boardcast_detect:1; /**< Global broadcast address detected */
  } bm;
 } status;
} __attribute__ ((packed, aligned(8))) emac_rx_descriptor_t; /* GCC */

/** Transmit buffer descriptor struct */
typedef struct emac_tx_descriptor {
 uint32_t addr;
 union emac_tx_status {
  uint32_t val;
  struct emac_tx_status_bm {
   uint32_t len:11, /**< Length of buffer */
   reserved:4,
   b_last_buffer:1, /**< Last buffer (in the current frame) */
   b_no_crc:1, /**< No CRC */
   reserved1:10,
   b_exhausted:1, /**< Buffer exhausted in mid frame */
   b_underrun:1, /**< Transmit underrun */
   b_error:1, /**< Retry limit exceeded, error detected */
   b_wrap:1, /**< Marks last descriptor in TD list */
   b_used:1; /**< User clear, EMAC sets this to 1 once a frame has been successfully transmitted */
  } bm;
 } status;
} __attribute__ ((packed, aligned(8))) emac_tx_descriptor_t; /* GCC */





/**
 * \brief Input parameters when initializing the emac module mode.
 */
typedef struct emac_options {
 /*  Enable/Disable CopyAllFrame */
 uint8_t uc_copy_all_frame;
 /* Enable/Disable NoBroadCast */
 uint8_t uc_no_boardcast;
 /* MAC address */
 uint8_t uc_mac_addr[(6)];
} emac_options_t;

/** RX callback */
typedef void (*emac_dev_tx_cb_t) (uint32_t ul_status);
/** Wakeup callback */
typedef void (*emac_dev_wakeup_cb_t) (void);

/**
 * EMAC driver structure.
 */
typedef struct emac_device {

 /** Pointer to HW register base */
 Emac *p_hw;
 /**
	 * Pointer to allocated TX buffer.
	 * Section 3.6 of AMBA 2.0 spec states that burst should not cross
	 * 1K Boundaries.
	 * Receive buffer manager writes are burst of 2 words => 3 lsb bits
	 * of the address shall be set to 0.
	 */
 uint8_t *p_tx_buffer;
 /** Pointer to allocated RX buffer */
 uint8_t *p_rx_buffer;
 /** Pointer to Rx TDs (must be 8-byte aligned) */
 emac_rx_descriptor_t *p_rx_dscr;
 /** Pointer to Tx TDs (must be 8-byte aligned) */
 emac_tx_descriptor_t *p_tx_dscr;
 /** Optional callback to be invoked once a frame has been received */
 emac_dev_tx_cb_t func_rx_cb;
 /** Optional callback to be invoked once several TDs have been released */
 emac_dev_wakeup_cb_t func_wakeup_cb;
 /** Optional callback list to be invoked once TD has been processed */
 emac_dev_tx_cb_t *func_tx_cb_list;
 /** RX TD list size */
 uint16_t us_rx_list_size;
 /** RX index for current processing TD */
 uint16_t us_rx_idx;
 /** TX TD list size */
 uint16_t us_tx_list_size;
 /** Circular buffer head pointer by upper layer (buffer to be sent) */
 uint16_t us_tx_head;
 /** Circular buffer tail pointer incremented by handlers (buffer sent) */
 uint16_t us_tx_tail;

 /** Number of free TD before wakeup callback is invoked */
 uint8_t uc_wakeup_threshold;
} emac_device_t;

/**
 * \brief Write network control value.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param ul_ncr   Network control value.
 */
static inline void emac_network_control(Emac* p_emac, uint32_t ul_ncr)
{
 p_emac->EMAC_NCR = ul_ncr;
}

/**
 * \brief Get network control value.
 *
 * \param p_emac   Pointer to the EMAC instance.
 */

static inline uint32_t emac_get_network_control(Emac* p_emac)
{
 return p_emac->EMAC_NCR;
}

/**
 * \brief Enable/Disable EMAC receive.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param uc_enable   0 to disable EMAC receiver, else to enable it.
 */
static inline void emac_enable_receive(Emac* p_emac, uint8_t uc_enable)
{
 if (uc_enable) {
  p_emac->EMAC_NCR |= (0x1u << 2) /**< \brief (EMAC_NCR) Receive enable */;
 } else {
  p_emac->EMAC_NCR &= ~(0x1u << 2) /**< \brief (EMAC_NCR) Receive enable */;
 }
}

/**
 * \brief Enable/Disable EMAC transmit.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param uc_enable   0 to disable EMAC transmit, else to enable it.
 */
static inline void emac_enable_transmit(Emac* p_emac, uint8_t uc_enable)
{
 if (uc_enable) {
  p_emac->EMAC_NCR |= (0x1u << 3) /**< \brief (EMAC_NCR) Transmit enable */;
 } else {
  p_emac->EMAC_NCR &= ~(0x1u << 3) /**< \brief (EMAC_NCR) Transmit enable */;
 }
}

/**
 * \brief Enable/Disable EMAC management.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param uc_enable   0 to disable EMAC management, else to enable it.
 */
static inline void emac_enable_management(Emac* p_emac, uint8_t uc_enable)
{
 if (uc_enable) {
  p_emac->EMAC_NCR |= (0x1u << 4) /**< \brief (EMAC_NCR) Management port enable */;
 } else {
  p_emac->EMAC_NCR &= ~(0x1u << 4) /**< \brief (EMAC_NCR) Management port enable */;
 }
}

/**
 * \brief Clear all statistics registers.
 *
 * \param p_emac   Pointer to the EMAC instance.
 */
static inline void emac_clear_statistics(Emac* p_emac)
{
 p_emac->EMAC_NCR |= (0x1u << 5) /**< \brief (EMAC_NCR) Clear statistics registers */;
}

/**
 * \brief Increase all statistics registers.
 *
 * \param p_emac   Pointer to the EMAC instance.
 */
static inline void emac_increase_statistics(Emac* p_emac)
{
 p_emac->EMAC_NCR |= (0x1u << 6) /**< \brief (EMAC_NCR) Increment statistics registers */;
}

/**
 * \brief Enable/Disable statistics registers writing.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param uc_enable   0 to disable the statistics registers writing, else to enable it.
 */
static inline void emac_enable_statistics_write(Emac* p_emac,
  uint8_t uc_enable)
{
 if (uc_enable) {
  p_emac->EMAC_NCR |= (0x1u << 7) /**< \brief (EMAC_NCR) Write enable for statistics registers */;
 } else {
  p_emac->EMAC_NCR &= ~(0x1u << 7) /**< \brief (EMAC_NCR) Write enable for statistics registers */;
 }
}

/**
 * \brief In half-duplex mode, forces collisions on all received frames.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param uc_enable   0 to disable the back pressure, else to enable it.
 */
static inline void emac_enable_back_pressure(Emac* p_emac, uint8_t uc_enable)
{
 if (uc_enable) {
  p_emac->EMAC_NCR |= (0x1u << 8) /**< \brief (EMAC_NCR) Back pressure */;
 } else {
  p_emac->EMAC_NCR &= ~(0x1u << 8) /**< \brief (EMAC_NCR) Back pressure */;
 }
}

/**
 * \brief Start transmission.
 *
 * \param p_emac   Pointer to the EMAC instance.
 */
static inline void emac_start_transmission(Emac* p_emac)
{
 p_emac->EMAC_NCR |= (0x1u << 9) /**< \brief (EMAC_NCR) Start transmission */;
}

/**
 * \brief Halt transmission.
 *
 * \param p_emac   Pointer to the EMAC instance.
 */
static inline void emac_halt_transmission(Emac* p_emac)
{
 p_emac->EMAC_NCR |= (0x1u << 10) /**< \brief (EMAC_NCR) Transmit halt */;
}

/**
 * \brief Set up network configuration register.
 *
 * \param p_emac   Pointer to the EMAC instance.
  * \param ul_cfg   Network configuration value.
 */
static inline void emac_set_configure(Emac* p_emac, uint32_t ul_cfg)
{
 p_emac->EMAC_NCFGR = ul_cfg;
}

/**
 * \brief Get network configuration.
 *
 * \param p_emac   Pointer to the EMAC instance.
 *
 * \return Network configuration.
 */
static inline uint32_t emac_get_configure(Emac* p_emac)
{
 return p_emac->EMAC_NCFGR;
}

/**
 * \brief Set speed.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param uc_speed 1 to indicate 100Mbps, 0 to 10Mbps.
 */
static inline void emac_set_speed(Emac* p_emac, uint8_t uc_speed)
{
 if (uc_speed) {
  p_emac->EMAC_NCFGR |= (0x1u << 0) /**< \brief (EMAC_NCFGR) Speed */;
 } else {
  p_emac->EMAC_NCFGR &= ~(0x1u << 0) /**< \brief (EMAC_NCFGR) Speed */;
 }
}

/**
 * \brief Enable/Disable Full-Duplex mode.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param uc_enable   0 to disable the Full-Duplex mode, else to enable it.
 */
static inline void emac_enable_full_duplex(Emac* p_emac, uint8_t uc_enable)
{
 if (uc_enable) {
  p_emac->EMAC_NCFGR |= (0x1u << 1) /**< \brief (EMAC_NCFGR) Full Duplex */;
 } else {
  p_emac->EMAC_NCFGR &= ~(0x1u << 1) /**< \brief (EMAC_NCFGR) Full Duplex */;
 }
}

/**
 * \brief Enable/Disable Copy(Receive) All Valid Frames.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param uc_enable   0 to disable copying all valid frames, else to enable it.
 */
static inline void emac_enable_copy_all(Emac* p_emac, uint8_t uc_enable)
{
 if (uc_enable) {
  p_emac->EMAC_NCFGR |= (0x1u << 4) /**< \brief (EMAC_NCFGR) Copy All Frames */;
 } else {
  p_emac->EMAC_NCFGR &= ~(0x1u << 4) /**< \brief (EMAC_NCFGR) Copy All Frames */;
 }
}

/**
 * \brief Enable/Disable jumbo frames (up to 10240 bytes).
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param uc_enable   0 to disable the jumbo frames, else to enable it.
 */
static inline void emac_enable_jumbo_frames(Emac* p_emac, uint8_t uc_enable)
{
 if (uc_enable) {
  p_emac->EMAC_NCFGR |= (0x1u << 3) /**< \brief (EMAC_NCFGR) Jumbo Frames */;
 } else {
  p_emac->EMAC_NCFGR &= ~(0x1u << 3) /**< \brief (EMAC_NCFGR) Jumbo Frames */;
 }
}

/**
 * \brief Disable/Enable broadcast receiving.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param uc_enable   1 to disable the broadcast, else to enable it.
 */
static inline void emac_disable_broadcast(Emac* p_emac, uint8_t uc_enable)
{
 if (uc_enable) {
  p_emac->EMAC_NCFGR |= (0x1u << 5) /**< \brief (EMAC_NCFGR) No Broadcast */;
 } else {
  p_emac->EMAC_NCFGR &= ~(0x1u << 5) /**< \brief (EMAC_NCFGR) No Broadcast */;
 }
}

/**
 * \brief Enable/Disable multicast hash.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param uc_enable   0 to disable the multicast hash, else to enable it.
 */
static inline void emac_enable_multicast_hash(Emac* p_emac, uint8_t uc_enable)
{
 if (uc_enable) {
  p_emac->EMAC_NCFGR |= (0x1u << 7) /**< \brief (EMAC_NCFGR) Unicast Hash Enable */;
 } else {
  p_emac->EMAC_NCFGR &= ~(0x1u << 7) /**< \brief (EMAC_NCFGR) Unicast Hash Enable */;
 }
}

/**
 * \brief Enable/Disable big frames (over 1518, up to 1536).
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param uc_enable   0 to disable big frames else to enable it.
 */
static inline void emac_enable_big_frame(Emac* p_emac, uint8_t uc_enable)
{
 if (uc_enable) {
  p_emac->EMAC_NCFGR |= (0x1u << 8) /**< \brief (EMAC_NCFGR) Receive 1536 bytes frames */;
 } else {
  p_emac->EMAC_NCFGR &= ~(0x1u << 8) /**< \brief (EMAC_NCFGR) Receive 1536 bytes frames */;
 }
}

/**
 * \brief Set MDC clock divider.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param ul_mck   EMAC MCK.
 *
 * \return EMAC_OK if successfully.
 */
static inline uint8_t emac_set_clock(Emac* p_emac, uint32_t ul_mck)
{
 uint32_t ul_clk;

 if (ul_mck > (160*1000*1000)) {
  return EMAC_INVALID;
 } else if (ul_mck > (80*1000*1000)) {
  ul_clk = (0x3u << 10) /**< \brief (EMAC_NCFGR) MCK divided by 64 (MCK up to 160 MHz). */;
 } else if (ul_mck > (40*1000*1000)) {
  ul_clk = (0x2u << 10) /**< \brief (EMAC_NCFGR) MCK divided by 32 (MCK up to 80 MHz). */;
 } else if (ul_mck > (20*1000*1000)) {
  ul_clk = (0x1u << 10) /**< \brief (EMAC_NCFGR) MCK divided by 16 (MCK up to 40 MHz). */;
 } else {
  ul_clk = (0x0u << 10) /**< \brief (EMAC_NCFGR) MCK divided by 8 (MCK up to 20 MHz). */;
 }

 p_emac->EMAC_NCFGR &= ~(0x3u << 10) /**< \brief (EMAC_NCFGR) MDC clock divider */;
 p_emac->EMAC_NCFGR |= ul_clk;

 return EMAC_OK;
}

/**
 * \brief Enable/Disable retry test.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param uc_enable   0 to disable the EMAC receiver, else to enable it.
 */
static inline void emac_enable_retry_test(Emac* p_emac, uint8_t uc_enable)
{
 if (uc_enable) {
  p_emac->EMAC_NCFGR |= (0x1u << 12) /**< \brief (EMAC_NCFGR) Retry test */;
 } else {
  p_emac->EMAC_NCFGR &= ~(0x1u << 12) /**< \brief (EMAC_NCFGR) Retry test */;
 }
}

/**
 * \brief Enable/Disable pause (when a valid pause frame is received).
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param uc_enable   0 to disable pause frame, else to enable it.
 */
static inline void emac_enable_pause_frame(Emac* p_emac, uint8_t uc_enable)
{
 if (uc_enable) {
  p_emac->EMAC_NCFGR |= (0x1u << 13) /**< \brief (EMAC_NCFGR) Pause Enable */;
 } else {
  p_emac->EMAC_NCFGR &= ~(0x1u << 13) /**< \brief (EMAC_NCFGR) Pause Enable */;
 }
}

/**
 * \brief Set receive buffer offset to 0 ~ 3.
 *
 * \param p_emac   Pointer to the EMAC instance.
 */
static inline void emac_set_rx_buffer_offset(Emac* p_emac, uint8_t uc_offset)
{
 p_emac->EMAC_NCFGR &= ~(0x3u << 14) /**< \brief (EMAC_NCFGR) Receive Buffer Offset */;
 p_emac->EMAC_NCFGR |=
   ((0x3u << 14) /**< \brief (EMAC_NCFGR) Receive Buffer Offset */ & ((uc_offset) << 14));
}

/**
 * \brief Enable/Disable receive length field checking.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param uc_enable   0 to disable receive length field checking, else to enable it.
 */
static inline void emac_enable_rx_length_check(Emac* p_emac, uint8_t uc_enable)
{
 if (uc_enable) {
  p_emac->EMAC_NCFGR |= (0x1u << 16) /**< \brief (EMAC_NCFGR) Receive Length field Checking Enable */;
 } else {
  p_emac->EMAC_NCFGR &= ~(0x1u << 16) /**< \brief (EMAC_NCFGR) Receive Length field Checking Enable */;
 }
}

/**
 * \brief Enable/Disable discarding FCS field of received frames.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param uc_enable   0 to disable discarding FCS field of received frames, else to enable it.
 */
static inline void emac_enable_discard_fcs(Emac* p_emac, uint8_t uc_enable)
{
 if (uc_enable) {
  p_emac->EMAC_NCFGR |= (0x1u << 17) /**< \brief (EMAC_NCFGR) Discard Receive FCS */;
 } else {
  p_emac->EMAC_NCFGR &= ~(0x1u << 17) /**< \brief (EMAC_NCFGR) Discard Receive FCS */;
 }
}


/**
 * \brief Enable/Disable frames to be received in half-duplex mode
 * while transmitting.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param uc_enable   0 to disable the received in half-duplex mode, else to enable it.
 */
static inline void emac_enable_efrhd(Emac* p_emac, uint8_t uc_enable)
{
 if (uc_enable) {
  p_emac->EMAC_NCFGR |= (0x1u << 18) /**< \brief (EMAC_NCFGR)  */;
 } else {
  p_emac->EMAC_NCFGR &= ~(0x1u << 18) /**< \brief (EMAC_NCFGR)  */;
 }
}

/**
 * \brief Enable/Disable ignore RX FCS.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param uc_enable   0 to disable ignore RX FCS, else to enable it.
 */
static inline void emac_enable_ignore_rx_fcs(Emac* p_emac, uint8_t uc_enable)
{
 if (uc_enable) {
  p_emac->EMAC_NCFGR |= (0x1u << 19) /**< \brief (EMAC_NCFGR) Ignore RX FCS */;
 } else {
  p_emac->EMAC_NCFGR &= ~(0x1u << 19) /**< \brief (EMAC_NCFGR) Ignore RX FCS */;
 }
}

/**
 * \brief Get Network Status.
 *
 * \param p_emac   Pointer to the EMAC instance.
 *
 * \return Network status.
 */
static inline uint32_t emac_get_status(Emac* p_emac)
{
 return p_emac->EMAC_NSR;
}

/**
 * \brief Get MDIO IN pin status.
 *
 * \param p_emac   Pointer to the EMAC instance.
 *
 * \return MDIO IN pin status.
 */
static inline uint8_t emac_get_MDIO(Emac* p_emac)
{
 return ((p_emac->EMAC_NSR & (0x1u << 1) /**< \brief (EMAC_NSR)  */) > 0);
}

/**
 * \brief Check if PHY is idle.
 *
 * \param p_emac   Pointer to the EMAC instance.
 *
 * \return  1 if PHY is idle.
 */
static inline uint8_t emac_is_phy_idle(Emac* p_emac)
{
 return ((p_emac->EMAC_NSR & (0x1u << 2) /**< \brief (EMAC_NSR)  */) > 0);
}

/**
 * \brief Return transmit status.
 *
 * \param p_emac   Pointer to the EMAC instance.
 *
 * \return  Transmit status.
 */
static inline uint32_t emac_get_tx_status(Emac* p_emac)
{
 return p_emac->EMAC_TSR;
}

/**
 * \brief Clear transmit status.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param ul_status   Transmit status.
 */
static inline void emac_clear_tx_status(Emac* p_emac, uint32_t ul_status)
{
 p_emac->EMAC_TSR = ul_status;
}

/**
 * \brief Return receive status.
 *
 * \param p_emac   Pointer to the EMAC instance.
 */
static inline uint32_t emac_get_rx_status(Emac* p_emac)
{
 return p_emac->EMAC_RSR;
}

/**
 * \brief Clear receive status.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param ul_status   Receive status.
 */
static inline void emac_clear_rx_status(Emac* p_emac, uint32_t ul_status)
{
 p_emac->EMAC_RSR = ul_status;
}

/**
 * \brief Set Rx Queue.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param ul_addr   Rx queue address.
 */
static inline void emac_set_rx_queue(Emac* p_emac, uint32_t ul_addr)
{
 p_emac->EMAC_RBQP = (0x3fffffffu << 2) /**< \brief (EMAC_RBQP) Receive buffer queue pointer address */ & ul_addr;
}

/**
 * \brief Get Rx Queue Address.
 *
 * \param p_emac   Pointer to the EMAC instance.
 *
 * \return  Rx queue address.
 */
static inline uint32_t emac_get_rx_queue(Emac* p_emac)
{
 return p_emac->EMAC_RBQP;
}

/**
 * \brief Set Tx Queue.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param ul_addr  Tx queue address.
 */
static inline void emac_set_tx_queue(Emac* p_emac, uint32_t ul_addr)
{
 p_emac->EMAC_TBQP = (0x3fffffffu << 2) /**< \brief (EMAC_TBQP) Transmit buffer queue pointer address */ & ul_addr;
}

/**
 * \brief Get Tx Queue.
 *
 * \param p_emac   Pointer to the EMAC instance.
 *
 * \return  Rx queue address.
 */
static inline uint32_t emac_get_tx_queue(Emac* p_emac)
{
 return p_emac->EMAC_TBQP;
}

/**
 * \brief Enable interrupt(s).
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param ul_source   Interrupt source(s) to be enabled.
 */
static inline void emac_enable_interrupt(Emac* p_emac, uint32_t ul_source)
{
 p_emac->EMAC_IER = ul_source;
}

/**
 * \brief Disable interrupt(s).
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param ul_source   Interrupt source(s) to be disabled.
 */
static inline void emac_disable_interrupt(Emac* p_emac, uint32_t ul_source)
{
 p_emac->EMAC_IDR = ul_source;
}

/**
 * \brief Return interrupt status.
 *
 * \param p_emac   Pointer to the EMAC instance.
 *
 * \return Interrupt status.
 */
static inline uint32_t emac_get_interrupt_status(Emac* p_emac)
{
 return p_emac->EMAC_ISR;
}

/**
 * \brief Return interrupt mask.
 *
 * \param p_emac   Pointer to the EMAC instance.
 *
 * \return Interrupt mask.
 */
static inline uint32_t emac_get_interrupt_mask(Emac* p_emac)
{
 return p_emac->EMAC_IMR;
}

/**
 * \brief Execute PHY maintenance command.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param uc_phy_addr   PHY address.
 * \param uc_reg_addr   Register address.
 * \param uc_rw   1 to Read, 0 to write.
 * \param us_data   Data to be performed, write only.
 */
static inline void emac_maintain_phy(Emac* p_emac,
  uint8_t uc_phy_addr, uint8_t uc_reg_addr, uint8_t uc_rw,
  uint16_t us_data)
{
 /* Wait until bus idle */
 while ((p_emac->EMAC_NSR & (0x1u << 2) /**< \brief (EMAC_NSR)  */) == 0);
 /* Write maintain register */
 p_emac->EMAC_MAN = (((0x3u << 16) /**< \brief (EMAC_MAN)  */ & (((10)) << 16)))
   | (((0x3u << 30) /**< \brief (EMAC_MAN) Start of frame */ & (((1)) << 30)))
   | (((0x1fu << 23) /**< \brief (EMAC_MAN) PHY Address */ & ((uc_phy_addr) << 23)))
   | (((0x1fu << 18) /**< \brief (EMAC_MAN) Register Address */ & ((uc_reg_addr) << 18)))
   | (((0x3u << 28) /**< \brief (EMAC_MAN) Read-write */ & (((uc_rw ? (2) : (1))) << 28)))
   | (((0xffffu << 0) /**< \brief (EMAC_MAN)  */ & ((us_data) << 0)));
}

/**
 * \brief Get PHY maintenance data returned.
 *
 * \param p_emac   Pointer to the EMAC instance.
 *
 * \return Get PHY data.
 */
static inline uint16_t emac_get_phy_data(Emac* p_emac)
{
 /* Wait until bus idle */
 while ((p_emac->EMAC_NSR & (0x1u << 2) /**< \brief (EMAC_NSR)  */) == 0);
 /* Return data */
 return (uint16_t) (p_emac->EMAC_MAN & (0xffffu << 0) /**< \brief (EMAC_MAN)  */);
}

/**
 * \brief Set pause time.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param us_pause_time   Pause time.
 */
static inline void emac_set_pause_time(Emac* p_emac, uint16_t us_pause_time)
{
 p_emac->EMAC_PTR = us_pause_time;
}

/**
 * \brief Set Hash.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param ul_hash_top   Hash top.
 * \param ul_hash_bottom   Hash bottom.
 */
static inline void emac_set_hash(Emac* p_emac, uint32_t ul_hash_top,
  uint32_t ul_hash_bottom)
{
 p_emac->EMAC_HRB = ul_hash_bottom;
 p_emac->EMAC_HRT = ul_hash_top;
}

/**
 * \brief Set 64 bits Hash.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param ull_hash   64 bits hash value.
 */
static inline void emac_set_hash64(Emac* p_emac, uint64_t ull_hash)
{
 p_emac->EMAC_HRB = (uint32_t) ull_hash;
 p_emac->EMAC_HRT = (uint32_t) (ull_hash >> 32);
}

/**
 * \brief Set MAC Address.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param uc_index  EMAC specific address register index.
 * \param p_mac_addr  EMAC address.
 */
static inline void emac_set_address(Emac* p_emac, uint8_t uc_index,
  uint8_t* p_mac_addr)
{
 p_emac->EMAC_SA[uc_index].EMAC_SAxB = (p_mac_addr[3] << 24)
   | (p_mac_addr[2] << 16)
   | (p_mac_addr[1] << 8)
   | (p_mac_addr[0]);
 p_emac->EMAC_SA[uc_index].EMAC_SAxT = (p_mac_addr[5] << 8)
   | (p_mac_addr[4]);
}

/**
 * \brief Set MAC Address via 2 dword.
  *
 * \param p_emac   Pointer to the EMAC instance.
 * \param uc_index  EMAC specific address register index.
 * \param ul_mac_top  EMAC top address.
 * \param ul_mac_bottom  EMAC bottom address.
 */
static inline void emac_set_address32(Emac* p_emac, uint8_t uc_index,
  uint32_t ul_mac_top, uint32_t ul_mac_bottom)
{
 p_emac->EMAC_SA[uc_index].EMAC_SAxB = ul_mac_bottom;
 p_emac->EMAC_SA[uc_index].EMAC_SAxT = ul_mac_top;
}

/**
 * \brief Set MAC Address via int64.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param uc_index  EMAC specific address register index.
 * \param ull_mac  64-bit EMAC address.
 */
static inline void emac_set_address64(Emac* p_emac, uint8_t uc_index,
  uint64_t ull_mac)
{
 p_emac->EMAC_SA[uc_index].EMAC_SAxB = (uint32_t) ull_mac;
 p_emac->EMAC_SA[uc_index].EMAC_SAxT = (uint32_t) (ull_mac >> 32);
}

/**
 * \brief Set type ID.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param us_type_id   Type to be set.
 */
static inline void emac_set_type_id(Emac* p_emac, uint16_t us_type_id)
{
 p_emac->EMAC_TID = (((0xffffu << 0) /**< \brief (EMAC_TID) Type ID checking */ & ((us_type_id) << 0)));
}

/**
 * \brief Get type ID.
 *
 * \param p_emac   Pointer to the EMAC instance.
 *
 * \return Type ID.
 */
static inline uint16_t emac_get_type_id(Emac* p_emac)
{
 return (p_emac->EMAC_TID & (0xffffu << 0) /**< \brief (EMAC_TID) Type ID checking */);
}

/**
 * \brief Enable/Disable RMII.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param uc_enable   0 to disable the RMII mode, else to enable it.
 */
static inline void emac_enable_rmii(Emac* p_emac, uint8_t uc_enable)
{
 if (uc_enable) {
  p_emac->EMAC_USRIO |= (0x1u << 0) /**< \brief (EMAC_USRIO) Reduce MII */;
 } else {
  p_emac->EMAC_USRIO &= ~(0x1u << 0) /**< \brief (EMAC_USRIO) Reduce MII */;
 }
}

/**
 * \brief Enable/Disable transceiver input clock.
 *
 * \param p_emac   Pointer to the EMAC instance.
 * \param uc_enable   0 to disable transceiver input clock, else to enable it.
 */
static inline void emac_enable_transceiver_clock(Emac* p_emac,
  uint8_t uc_enable)
{
 if (uc_enable) {
  p_emac->EMAC_USRIO |= (0x1u << 1) /**< \brief (EMAC_USRIO) Clock Enable */;
 } else {
  p_emac->EMAC_USRIO &= ~(0x1u << 1) /**< \brief (EMAC_USRIO) Clock Enable */;
 }
}

uint8_t emac_phy_read(Emac* p_emac, uint8_t uc_phy_address, uint8_t uc_address,
  uint32_t* p_value);
uint8_t emac_phy_write(Emac* p_emac, uint8_t uc_phy_address,
  uint8_t uc_address, uint32_t ul_value);
void emac_dev_init(Emac* p_emac, emac_device_t* p_emac_dev,
  emac_options_t* p_opt);
uint32_t emac_dev_read(emac_device_t* p_emac_dev, uint8_t* p_frame,
  uint32_t ul_frame_size, uint32_t* p_rcv_size);
uint32_t emac_dev_write(emac_device_t* p_emac_dev, void *p_buffer,
  uint32_t ul_size, emac_dev_tx_cb_t func_tx_cb);
uint32_t emac_dev_get_tx_load(emac_device_t* p_emac_dev);
void emac_dev_set_rx_callback(emac_device_t* p_emac_dev,
  emac_dev_tx_cb_t func_rx_cb);
uint8_t emac_dev_set_tx_wakeup_callback(emac_device_t* p_emac_dev,
  emac_dev_wakeup_cb_t func_wakeup, uint8_t uc_threshold);
void emac_dev_reset(emac_device_t* p_emac_dev);
void emac_handler(emac_device_t* p_emac_dev);

/// @cond 0
/**INDENT-OFF**/

}

/**INDENT-ON**/
/// @endcond

/**
 * \page emac_quickstart Quickstart guide for EMAC driver.
 *
 * This is the quickstart guide for the \ref emac_group "Ethernet MAC",
 * with step-by-step instructions on how to configure and use the driver in a
 * selection of use cases.
 *
 * The use cases contain several code fragments. The code fragments in the
 * steps for setup can be copied into a custom initialization function, while
 * the steps for usage can be copied into, e.g., the main application function.
 *
 * \section emac_basic_use_case Basic use case
 * In the basic use case, the EMAC driver are configured for:
 * - PHY component DM9161A is used
 * - EMAC uses RMII mode
 * - The number of receive buffer is 16
 * - The number of transfer buffer is 8
 * - MAC address is set to 00-04-25-1c-a0-02
 * - IP address is set to 192.168.0.2
 * - IP address is set to 192.168.0.2
 * - Gateway is set to 192.168.0.1
 * - Network mask is 255.255.255.0
 * - PHY operation max retry count is 1000000
 * - EMAC is configured to not support copy all frame and support broadcast
 * - The reset PIN of DM9161A is connected to the NRST of SAM3X
 * - The data will be read from the ethernet
 *
 * \section emac_basic_use_case_setup Setup steps
 *
 * \subsection emac_basic_use_case_setup_prereq Prerequisites
 * -# \ref sysclk_group "System Clock Management (sysclock)"
 * -# \ref pio_group "Parallel Input/Output Controller (pio)"
 * -# \ref pmc_group "Power Management Controller (pmc)"
 * -# \ref sam_drivers_rstc_group "Reset Controller (RSTC)"
 * -# \ref dm9161a_ethernet_phy_group "PHY component (DM9161A)"
 *
 * \subsection emac_basic_use_case_setup_code Example code
 * Content of conf_eth.h
 * \code
 * #define EMAC_RX_BUFFERS                               16
 * #define EMAC_TX_BUFFERS                               8
 * #define MAC_PHY_RETRY_MAX                             1000000
 * #define ETHERNET_CONF_ETHADDR0                        0x00
 * #define ETHERNET_CONF_ETHADDR0                        0x00
 * #define ETHERNET_CONF_ETHADDR1                        0x04
 * #define ETHERNET_CONF_ETHADDR2                        0x25
 * #define ETHERNET_CONF_ETHADDR3                        0x1C
 * #define ETHERNET_CONF_ETHADDR4                        0xA0
 * #define ETHERNET_CONF_ETHADDR5                        0x02
 * #define ETHERNET_CONF_IPADDR0                         192
 * #define ETHERNET_CONF_IPADDR1                         168
 * #define ETHERNET_CONF_IPADDR2                         0
 * #define ETHERNET_CONF_IPADDR3                         2
 * #define ETHERNET_CONF_GATEWAY_ADDR0                   192
 * #define ETHERNET_CONF_GATEWAY_ADDR1                   168
 * #define ETHERNET_CONF_GATEWAY_ADDR2                   0
 * #define ETHERNET_CONF_GATEWAY_ADDR3                   1
 * #define ETHERNET_CONF_NET_MASK0                       255
 * #define ETHERNET_CONF_NET_MASK1                       255
 * #define ETHERNET_CONF_NET_MASK2                       255
 * #define ETHERNET_CONF_NET_MASK3                       0
 * #define ETH_PHY_MODE                                  BOARD_EMAC_MODE_RMII
 * \endcode
 *
 * A specific emac device and the receive data buffer must be defined; another ul_frm_size should be defined
 * to trace the actual size of the data received.
 * \code
 * static emac_device_t gs_emac_dev;
 * static volatile uint8_t gs_uc_eth_buffer[EMAC_FRAME_LENTGH_MAX];
 *
 * uint32_t ul_frm_size;
 * \endcode
 *
 * Add to application C-file:
 * \code
 *   void emac_init(void)
 *   {
 *       sysclk_init();
 *
 *       board_init();
 *
 *       rstc_set_external_reset(RSTC, 13);
 *       rstc_reset_extern(RSTC);
 *       while (rstc_get_status(RSTC) & RSTC_SR_NRSTL) {
 *       };
 *
 *       ul_delay = sysclk_get_cpu_hz() / 1000 / 3 * 400;
 *       while (ul_delay--);
 *
 *       pmc_enable_periph_clk(ID_EMAC);
 *
 *       emac_option.uc_copy_all_frame = 0;
 *       emac_option.uc_no_boardcast = 0;
 *       memcpy(emac_option.uc_mac_addr, gs_uc_mac_address, sizeof(gs_uc_mac_address));
 *       gs_emac_dev.p_hw = EMAC;
 *
 *       emac_dev_init(EMAC, &gs_emac_dev, &emac_option);
 *
 *       NVIC_EnableIRQ(EMAC_IRQn);
 *
 *       ethernet_phy_init(EMAC, BOARD_EMAC_PHY_ADDR, sysclk_get_cpu_hz()
 *
 *       ethernet_phy_auto_negotiate(EMAC, BOARD_EMAC_PHY_ADDR
 *
 *       ethernet_phy_set_link(EMAC, BOARD_EMAC_PHY_ADDR, 1)
 * \endcode
 *
 * \subsection emac_basic_use_case_setup_flow Workflow
 * -# Ensure that conf_emac.h is present and contains the
 * following configuration symbol. This configuration file is used
 * by the driver and should not be included by the user.
 *   - \code
 *        #define EMAC_RX_BUFFERS                               16
 *        #define EMAC_TX_BUFFERS                               8
 *        #define MAC_PHY_RETRY_MAX                             1000000
 *        #define ETHERNET_CONF_ETHADDR0                        0x00
 *        #define ETHERNET_CONF_ETHADDR0                        0x00
 *        #define ETHERNET_CONF_ETHADDR1                        0x04
 *        #define ETHERNET_CONF_ETHADDR2                        0x25
 *        #define ETHERNET_CONF_ETHADDR3                        0x1C
 *        #define ETHERNET_CONF_ETHADDR4                        0xA0
 *        #define ETHERNET_CONF_ETHADDR5                        0x02
 *        #define ETHERNET_CONF_IPADDR0                         192
 *        #define ETHERNET_CONF_IPADDR1                         168
 *        #define ETHERNET_CONF_IPADDR2                         0
 *        #define ETHERNET_CONF_IPADDR3                         2
 *        #define ETHERNET_CONF_GATEWAY_ADDR0                   192
 *        #define ETHERNET_CONF_GATEWAY_ADDR1                   168
 *        #define ETHERNET_CONF_GATEWAY_ADDR2                   0
 *        #define ETHERNET_CONF_GATEWAY_ADDR3                   1
 *        #define ETHERNET_CONF_NET_MASK0                       255
 *        #define ETHERNET_CONF_NET_MASK1                       255
 *        #define ETHERNET_CONF_NET_MASK2                       255
 *        #define ETHERNET_CONF_NET_MASK3                       0
 *        #define ETH_PHY_MODE                                  BOARD_EMAC_MODE_RMII
 *   \endcode
 * -# Enable the system clock:
 *   - \code sysclk_init(); \endcode
 * -# Enable PIO configurations for EMAC:
 *   - \code board_init(); \endcode
 * -# Reset PHY; this is required by the DM9161A component:
 *   - \code
 *         rstc_set_external_reset(RSTC, 13);
 *         rstc_reset_extern(RSTC);
 *         while (rstc_get_status(RSTC) & RSTC_SR_NRSTL) {
 *         };
 * \endcode
 * -# Wait for PHY ready:
 *   - \code
 *         ul_delay = sysclk_get_cpu_hz() / 1000 / 3 * 400;
 *         while (ul_delay--);
 * \endcode
 * -# Enable PMC clock for EMAC:
 *   - \code pmc_enable_periph_clk(ID_EMAC); \endcode
 * -# Set the EMAC options; it's set to copy all frame and support broadcast:
 *   - \code
 *         emac_option.uc_copy_all_frame = 0;
 *         emac_option.uc_no_boardcast = 0;
 *         memcpy(emac_option.uc_mac_addr, gs_uc_mac_address, sizeof(gs_uc_mac_address));
 *         gs_emac_dev.p_hw = EMAC;
 * \endcode
 * -# Initialize EMAC device with the filled option:
 *   - \code
 *         emac_dev_init(EMAC, &gs_emac_dev, &emac_option);
 * \endcode
 * -# Enable the interrupt service for EMAC:
 *   - \code
 *         NVIC_EnableIRQ(EMAC_IRQn);
 * \endcode
 * -# Initialize the PHY component:
 *   - \code
 *         ethernet_phy_init(EMAC, BOARD_EMAC_PHY_ADDR, sysclk_get_cpu_hz());
 * \endcode
  * -# The link will be established based on auto negotiation.
 *   - \code
 *         ethernet_phy_auto_negotiate(EMAC, BOARD_EMAC_PHY_ADDR);
 * \endcode
 * -# Establish the ethernet link; the network can be worked from now on:
 *   - \code
 *         ethernet_phy_set_link(EMAC, BOARD_EMAC_PHY_ADDR, 1);
 * \endcode
 *
 * \section emac_basic_use_case_usage Usage steps
 * \subsection emac_basic_use_case_usage_code Example code
 * Add to, e.g., main loop in application C-file:
 * \code
 *    emac_dev_read(&gs_emac_dev, (uint8_t *) gs_uc_eth_buffer, sizeof(gs_uc_eth_buffer), &ul_frm_size));
 * \endcode
 *
 * \subsection emac_basic_use_case_usage_flow Workflow
 * -# Start reading the data from the ethernet:
 *   - \code emac_dev_read(&gs_emac_dev, (uint8_t *) gs_uc_eth_buffer, sizeof(gs_uc_eth_buffer), &ul_frm_size)); \endcode
 */
# 72 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/trng.h" 1
/**
 * \file
 *
 * \brief API for SAM TRNG.
 *
 * Copyright (c) 2011-2012 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */




# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/../chip.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 48 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/trng.h" 2

/// @cond 0
/**INDENT-OFF**/

extern "C" {

/**INDENT-ON**/
/// @endcond

void trng_enable(Trng *p_trng);
void trng_disable(Trng *p_trng);
void trng_enable_interrupt(Trng *p_trng);
void trng_disable_interrupt(Trng *p_trng);
uint32_t trng_get_interrupt_mask(Trng *p_trng);
uint32_t trng_get_interrupt_status(Trng *p_trng);
uint32_t trng_read_output_data(Trng *p_trng);

/// @cond 0
/**INDENT-OFF**/

}

/**INDENT-ON**/
/// @endcond
# 73 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/uotghs_device.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011-2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */
# 42 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/uotghs_device.h"
// Control Endpoint






// CDC Endpoints
# 70 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/uotghs_device.h"
// HID Endpoints







// Various definitions
# 99 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/uotghs_device.h"
//! \ingroup usb_device_group
//! \defgroup udd_group USB Device Driver (UDD)
//! UOTGHS low-level driver for USB device mode
//!
//! @{


// Bit pos is not defined in SAM header file but we need it.



//! @name UOTGHS Device IP properties
//! These macros give access to IP properties
//! @{
  //! Get maximal number of endpoints


  //! Get maximal number of banks of endpoints

  //! Get maximal size of endpoint (3X, 1024/64)

  //! Get DMA support of endpoints

  //! Get High Band Width support of endpoints

//! @}

//! @name UOTGHS Device speeds management
//! @{
  //! Enable/disable device low-speed mode


  //! Test if device low-speed mode is forced


  //! Enable high speed mode

  //! Disable high speed mode

  //! Test if controller is in full speed mode

//! @}

//! @name UOTGHS Device HS test mode management
//! @{

  //! Enable high speed test mode





//! @}

//! @name UOTGHS Device vbus management
//! @{
# 163 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/uotghs_device.h"
//! @}


//! @name UOTGHS device attach control
//! These macros manage the UOTGHS Device attach.
//! @{
  //! Detaches from USB bus

  //! Attaches to USB bus

  //! Test if the device is detached

//! @}


//! @name UOTGHS device bus events control
//! These macros manage the UOTGHS Device bus events.
//! @{

//! Initiates a remote wake-up event
//! @{


//! @}

//! Manage upstream resume event (=remote wakeup)
//! The USB driver sends a resume signal called "Upstream Resume"
//! @{






//! @}

//! Manage downstream resume event (=remote wakeup from host)
//! The USB controller detects a valid "End of Resume" signal initiated by the host
//! @{






//! @}

//! Manage wake-up event (=usb line activity)
//! The USB controller is reactivated by a filtered non-idle signal from the lines
//! @{






//! @}

//! Manage reset event
//! Set when a USB "End of Reset" has been detected
//! @{






//! @}

//! Manage start of frame event
//! @{
# 242 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/uotghs_device.h"
//! @}

//! Manage Micro start of frame event (High Speed Only)
//! @{
# 254 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/uotghs_device.h"
//! @}

//! Manage suspend event
//! @{






//! @}

//! @}

//! @name UOTGHS device address control
//! These macros manage the UOTGHS Device address.
//! @{
  //! enables USB device address

  //! disables USB device address


  //! configures the USB device address

  //! gets the currently configured USB device address

//! @}


//! @name UOTGHS Device endpoint drivers
//! These macros manage the common features of the endpoints.
//! @{

//! Generic macro for UOTGHS registers that can be arrayed
//! @{

//! @}

//! @name UOTGHS Device endpoint configuration
//! @{
  //! enables the selected endpoint

  //! disables the selected endpoint

  //! tests if the selected endpoint is enabled

  //! resets the selected endpoint





  //! Tests if the selected endpoint is being reset


  //! Configures the selected endpoint type

  //! Gets the configured selected endpoint type

  //! Enables the bank autoswitch for the selected endpoint

  //! Disables the bank autoswitch for the selected endpoint


  //! Configures the selected endpoint direction

  //! Gets the configured selected endpoint direction


  //! Bounds given integer size to allowed range and rounds it up to the nearest
  //! available greater size, then applies register format of UOTGHS controller
  //! for endpoint size bit-field.

  //! Configures the selected endpoint size

  //! Gets the configured selected endpoint size

  //! Configures the selected endpoint number of banks

  //! Gets the configured selected endpoint number of banks

  //! Allocates the configuration selected endpoint in DPRAM memory

  //! un-allocates the configuration selected endpoint in DPRAM memory



  //! Configures selected endpoint in one step
# 352 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/uotghs_device.h"
  //! Tests if current endpoint is configured

  //! Returns the control direction


  //! Resets the data toggle sequence

  //! Tests if the data toggle sequence is being reset

  //! Returns data toggle

//! @}


//! @name UOTGHS Device control endpoint
//! These macros control the endpoints.
//! @{

//! @name UOTGHS Device control endpoint interrupts
//! These macros control the endpoints interrupts.
//! @{
  //! Enables the selected endpoint interrupt

  //! Disables the selected endpoint interrupt

  //! Tests if the selected endpoint interrupt is enabled

  //! Tests if an interrupt is triggered by the selected endpoint

  //! Returns the lowest endpoint number generating an endpoint interrupt or MAX_PEP_NB if none





//! @}

//! @name UOTGHS Device control endpoint errors
//! These macros control the endpoint errors.
//! @{
  //! Enables the STALL handshake

  //! Disables the STALL handshake

  //! Tests if STALL handshake request is running

  //! Tests if STALL sent

  //! ACKs STALL sent

  //! Raises STALL sent

  //! Enables STALL sent interrupt

  //! Disables STALL sent interrupt

  //! Tests if STALL sent interrupt is enabled


  //! Tests if NAK OUT received

  //! ACKs NAK OUT received

  //! Raises NAK OUT received

  //! Enables NAK OUT interrupt

  //! Disables NAK OUT interrupt

  //! Tests if NAK OUT interrupt is enabled


  //! Tests if NAK IN received

  //! ACKs NAK IN received

  //! Raises NAK IN received

  //! Enables NAK IN interrupt

  //! Disables NAK IN interrupt

  //! Tests if NAK IN interrupt is enabled


  //! ACKs endpoint isochronous overflow interrupt

  //! Raises endpoint isochronous overflow interrupt

  //! Tests if an overflow occurs

  //! Enables overflow interrupt

  //! Disables overflow interrupt

  //! Tests if overflow interrupt is enabled


  //! ACKs endpoint isochronous underflow interrupt

  //! Raises endpoint isochronous underflow interrupt

  //! Tests if an underflow occurs

  //! Enables underflow interrupt

  //! Disables underflow interrupt

  //! Tests if underflow interrupt is enabled


  //! Tests if CRC ERROR ISO OUT detected

  //! ACKs CRC ERROR ISO OUT detected

  //! Raises CRC ERROR ISO OUT detected

  //! Enables CRC ERROR ISO OUT detected interrupt

  //! Disables CRC ERROR ISO OUT detected interrupt

  //! Tests if CRC ERROR ISO OUT detected interrupt is enabled

//! @}

//! @name UOTGHS Device control endpoint transfer
//! These macros control the endpoint transfer.
//! @{

  //! Tests if endpoint read allowed

  //! Tests if endpoint write allowed


  //! Returns the byte count

  //! Clears FIFOCON bit

  //! Tests if FIFOCON bit set


  //! Returns the number of busy banks

  //! Returns the number of the current bank

  //! Kills last bank


  //! Tests if last bank killed

  //! Forces all banks full (OUT) or free (IN) interrupt

  //! Unforces all banks full (OUT) or free (IN) interrupt

  //! Enables all banks full (OUT) or free (IN) interrupt

  //! Disables all banks full (OUT) or free (IN) interrupt

  //! Tests if all banks full (OUT) or free (IN) interrupt enabled


  //! Tests if SHORT PACKET received

  //! ACKs SHORT PACKET received

  //! Raises SHORT PACKET received

  //! Enables SHORT PACKET received interrupt

  //! Disables SHORT PACKET received interrupt

  //! Tests if SHORT PACKET received interrupt is enabled


  //! Tests if SETUP received

  //! ACKs SETUP received

  //! Raises SETUP received

  //! Enables SETUP received interrupt

  //! Disables SETUP received interrupt

  //! Tests if SETUP received interrupt is enabled


  //! Tests if OUT received

  //! ACKs OUT received

  //! Raises OUT received

  //! Enables OUT received interrupt

  //! Disables OUT received interrupt

  //! Tests if OUT received interrupt is enabled


  //! Tests if IN sending

  //! ACKs IN sending

  //! Raises IN sending

  //! Enables IN sending interrupt

  //! Disables IN sending interrupt

  //! Tests if IN sending interrupt is enabled



  //! 8-bit access to FIFO data register of selected endpoint.
  //! @param ep Endpoint of which to access FIFO data register
  //! @return Volatile 8-bit data pointer to FIFO data register
  //! @warning It is up to the user of this macro to make sure that all accesses
  //! are aligned with their natural boundaries
  //! @warning It is up to the user of this macro to make sure that used HSB
  //! addresses are identical to the DPRAM internal pointer modulo 32 bits.



//! @}

/*********************************************************************************************************************/

//! @name UOTGHS IP properties
//! These macros give access to IP properties (not defined in 3X)
//! @{
   //! Get IP name part 1 or 2


   //! Get IP version

   //! Get DPRAM size (FIFO maximal size) in bytes

   //! Get size of USBB PB address space

//! @}

//! @name UOTGHS OTG ID pin management
//! The ID pin come from the USB OTG connector (A and B receptable) and
//! allows to select the USB mode host or device.
//! The USBB hardware can manage it automaticaly. This feature is optional.
//! When otg_ID_PIN equals true in conf_usb_host.h, the USB_ID must be defined in board.h.
//!
//! @{
   //! PIO, PIO ID and MASK for USB_ID according to configuration from OTG_ID


   //! Input USB_ID from its pin




   //! Enable external OTG_ID pin (listened to by USB)

   //! Disable external OTG_ID pin (ignored by USB)

   //! Test if external OTG_ID pin enabled (listened to by USB)

   //! Disable external OTG_ID pin and force device mode

   //! Test if device mode is forced

   //! Disable external OTG_ID pin and force host mode

   //! Test if host mode is forced


//! @name UOTGHS OTG ID pin interrupt management
//! These macros manage the ID pin interrupt
//! @{
# 635 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/uotghs_device.h"
//! @}

//! @name USBB OTG Vbus management
//! @{
# 647 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/uotghs_device.h"
//! @}

//! @name UOTGHS OTG main management
//! These macros allows to enable/disable pad and UOTGHS hardware
//! @{
  //! Enable USB macro

  //! Disable USB macro



  //! Enable OTG pad

  //! Disable OTG pad



  //! Check Clock Usable
  //! For parts with HS feature, this one corresponding at UTMI clock


  //! Stop (freeze) internal USB clock




  //! Configure time-out of specified OTG timer




  //! Get configured time-out of specified OTG timer






  //! Get the dual-role device state of the internal USB finite state machine of the UOTGHS controller

//! @}

//! @name UOTGHS OTG hardware protocol
//! These macros manages the hardware OTG protocol
//! @{
  //! Initiates a Host Negociation Protocol

  //! Accepts a Host Negociation Protocol

  //! Rejects a Host Negociation Protocol

  //! initiates a Session Request Protocol

  //! Selects VBus as SRP method


  //! Selects data line as SRP method


  //! Tests if a HNP occurs

  //! Tests if a SRP from device occurs


  //! Enables HNP error interrupt

  //! Disables HNP error interrupt


  //! ACKs HNP error interrupt

  //! Raises HNP error interrupt

  //! Tests if a HNP error occurs


  //! Enables role exchange interrupt

  //! Disables role exchange interrupt


  //! ACKs role exchange interrupt

  //! Raises role exchange interrupt

  //! Tests if a role exchange occurs


  //! Eenables SRP interrupt

  //! Disables SRP interrupt


  //! ACKs SRP interrupt

  //! Raises SRP interrupt

  //! Tests if a SRP occurs

//! @}

//! @}
# 74 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/uotghs_host.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011-2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */




//! \ingroup usb_host_group
//! \defgroup uhd_group USB Host Driver (UHD)
//! UOTGHS low-level driver for USB host mode
//!
//! @{

//! @name UOTGHS Host IP properties
//!
//! @{
//! Get maximal number of endpoints


//! @}

//! @name Host Vbus line control
//!
//! VBOF is an optional output pin which allows to enable or disable
//! the external VBus generator.
//!
//! @{
//! Enables hardware control of USB_VBOF output pin when a Vbus error occur

//! Disables hardware control of USB_VBOF output pin when a Vbus error occur


//! Pin and function for USB_VBOF according to configuration from USB_VBOF


//! Output USB_VBOF onto its pin




//! Set USB_VBOF output pin polarity


//! Requests VBus activation

//! Requests VBus deactivation

//! Tests if VBus activation has been requested

//! @}

//! @name Host Vbus line monitoring
//!
//! The VBus level is always checked by USBC hardware.
//!
//! @{





//! @}







//! @name USB device connection/disconnection monitoring
//! @{
# 108 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/uotghs_host.h"
//! @}

//! @name USB device speed control
//! @{




//! Enable high speed mode

//! Disable high speed mode

//! @}

//! @name Bus events control
//! These macros manage the bus events: reset, SOF, resume, wakeup.
//! @{

//! Initiates a reset event
//! @{
# 137 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/uotghs_host.h"
//! @}

//! Initiates a SOF events
//! @{
# 152 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/uotghs_host.h"
//! @}

//! Initiates a resume event
//! It is called downstream resume event.
//! @{
# 165 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/uotghs_host.h"
//! @}

//! Detection of a wake-up event
//! A wake-up event is received when the host controller is in the suspend mode:
//! - and an upstream resume from the peripheral is detected.
//! - and a peripheral disconnection is detected.
//! @{
# 183 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/uotghs_host.h"
//! @}
//! @}


//! @name Pipes management
//! @{

//! USB address of pipes
//! @{






//! @}

//! Pipe enable
//! Enable, disable, reset, freeze
//! @{
# 219 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/uotghs_host.h"
//! @}

//! Pipe configuration
//! @{
# 240 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/uotghs_host.h"
//! Bounds given integer size to allowed range and rounds it up to the nearest
//! available greater size, then applies register format of UOTGHS controller
//! for pipe size bit-field.
# 254 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/uotghs_host.h"
//! Enable PING management only available in HS mode

//#endif
# 268 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/uotghs_host.h"
//! @}

//! Pipe main interrupts management
//! @{




//! returns the lowest pipe number generating a pipe interrupt or UOTGHS_EPT_NUM if none


//! @}

//! Pipe overflow and underflow for isochronous and interrupt endpoints
//! @{
# 294 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/uotghs_host.h"
//! @}

//! USB packet errors management
//! @{
# 316 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/uotghs_host.h"
//! @}

//! Pipe data management
//! @{
# 372 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/uotghs_host.h"
//! @}

//! Maximum transfer size on USB DMA


//! Get 64-, 32-, 16- or 8-bit access to FIFO data register of selected pipe.
//! @param p      Target Pipe number
//! @param scale  Data scale in bits: 64, 32, 16 or 8
//! @return       Volatile 64-, 32-, 16- or 8-bit data pointer to FIFO data register
//! @warning It is up to the user of this macro to make sure that all accesses
//! are aligned with their natural boundaries except 64-bit accesses which
//! require only 32-bit alignment.
//! @warning It is up to the user of this macro to make sure that used HSB
//! addresses are identical to the DPRAM internal pointer modulo 32 bits.
# 75 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 2
# 43 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/wiring_constants.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/





extern "C"{
# 46 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/wiring_constants.h"
enum BitOrder {
 LSBFIRST = 0,
 MSBFIRST = 1
};

//      LOW 0
//      HIGH 1







// undefine stdlib's abs if encountered
# 91 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/wiring_constants.h"
typedef unsigned int word;



typedef bool boolean ;
typedef uint8_t byte ;


} // extern "C"
# 45 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2





void yield(void);

/* sketch */
extern void setup( void ) ;
extern void loop( void ) ;

//#define NOT_A_PIN 0  // defined in pio.h/EPioType




typedef enum _EExt_Interrupts
{
  EXTERNAL_INT_0=0,
  EXTERNAL_INT_1=1,
  EXTERNAL_INT_2=2,
  EXTERNAL_INT_3=3,
  EXTERNAL_INT_4=4,
  EXTERNAL_INT_5=5,
  EXTERNAL_INT_6=6,
  EXTERNAL_INT_7=7,
  EXTERNAL_NUM_INTERRUPTS
} EExt_Interrupts ;

typedef void (*voidFuncPtr)( void ) ;

/* Define attribute */
# 85 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h"
/* Definitions and types for pins */
typedef enum _EAnalogChannel
{
  NO_ADC=-1,
  ADC0=0,
  ADC1,
  ADC2,
  ADC3,
  ADC4,
  ADC5,
  ADC6,
  ADC7,
  ADC8,
  ADC9,
  ADC10,
  ADC11,
  ADC12,
  ADC13,
  ADC14,
  ADC15,
  DA0,
  DA1
} EAnalogChannel ;



// Definitions for PWM channels
typedef enum _EPWMChannel
{
  NOT_ON_PWM=-1,
  PWM_CH0=0,
  PWM_CH1,
  PWM_CH2,
  PWM_CH3,
  PWM_CH4,
  PWM_CH5,
  PWM_CH6,
  PWM_CH7
} EPWMChannel ;

// Definitions for TC channels
typedef enum _ETCChannel
{
  NOT_ON_TIMER=-1,
  TC0_CHA0=0,
  TC0_CHB0,
  TC0_CHA1,
  TC0_CHB1,
  TC0_CHA2,
  TC0_CHB2,
  TC1_CHA3,
  TC1_CHB3,
  TC1_CHA4,
  TC1_CHB4,
  TC1_CHA5,
  TC1_CHB5,
  TC2_CHA6,
  TC2_CHB6,
  TC2_CHA7,
  TC2_CHB7,
  TC2_CHA8,
  TC2_CHB8
} ETCChannel ;

/**
 * Pin Attributes to be OR-ed
 */






/* Types used for the tables below */
typedef struct _PinDescription
{
  Pio* pPort ;
  uint32_t ulPin ;
  uint32_t ulPeripheralId ;
  EPioType ulPinType ;
  uint32_t ulPinConfiguration ;
  uint32_t ulPinAttribute ;
  EAnalogChannel ulAnalogChannel ; /* Analog pin in the Arduino context (label on the board) */
  EAnalogChannel ulADCChannelNumber ; /* ADC Channel number in the SAM device */
  EPWMChannel ulPWMChannel ;
  ETCChannel ulTCChannel ;
} PinDescription ;

/* Pins table to be instanciated into variant.cpp */
extern const PinDescription g_APinDescription[] ;


} // extern "C"

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/WCharacter.h" 1
/*
 WCharacter.h - Character utility functions for Wiring & Arduino
 Copyright (c) 2010 Hernando Barragan.  All right reserved.

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




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/ctype.h" 1 3



# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/_ansi.h" 1 3
/* Provide support for both ANSI and non-ANSI environments.  */

/* Some ANSI environments are "broken" in the sense that __STDC__ cannot be
   relied upon to have it's intended meaning.  Therefore we must use our own
   concoction: _HAVE_STDC.  Always use _HAVE_STDC instead of __STDC__ in newlib
   sources!

   To get a strict ANSI C environment, define macro __STRICT_ANSI__.  This will
   "comment out" the non-ANSI parts of the ANSI header files (non-ANSI header
   files aren't affected).  */
# 5 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/ctype.h" 2 3

extern "C" {

int isalnum (int __c);
int isalpha (int __c);
int iscntrl (int __c);
int isdigit (int __c);
int isgraph (int __c);
int islower (int __c);
int isprint (int __c);
int ispunct (int __c);
int isspace (int __c);
int isupper (int __c);
int isxdigit (int __c);
int tolower (int __c);
int toupper (int __c);


int isblank (int __c);



int isascii (int __c);
int toascii (int __c);
# 43 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/ctype.h" 3
const

extern char *__ctype_ptr__;
# 108 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/ctype.h" 3
/* For C++ backward-compatibility only.  */
extern const char _ctype_[];

}
# 24 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/WCharacter.h" 2


extern "C" {


// WCharacter.h prototypes

inline boolean isAlphaNumeric(int c) __attribute__((always_inline));
inline boolean isAlpha(int c) __attribute__((always_inline));
inline boolean isAscii(int c) __attribute__((always_inline));
inline boolean isWhitespace(int c) __attribute__((always_inline));
inline boolean isControl(int c) __attribute__((always_inline));
inline boolean isDigit(int c) __attribute__((always_inline));
inline boolean isGraph(int c) __attribute__((always_inline));
inline boolean isLowerCase(int c) __attribute__((always_inline));
inline boolean isPrintable(int c) __attribute__((always_inline));
inline boolean isPunct(int c) __attribute__((always_inline));
inline boolean isSpace(int c) __attribute__((always_inline));
inline boolean isUpperCase(int c) __attribute__((always_inline));
inline boolean isHexadecimalDigit(int c) __attribute__((always_inline));
inline int toAscii(int c) __attribute__((always_inline));
inline int toLowerCase(int c) __attribute__((always_inline));
inline int toUpperCase(int c)__attribute__((always_inline));



// Checks for an alphanumeric character.
// It is equivalent to (isalpha(c) || isdigit(c)).
inline boolean isAlphaNumeric(int c)
{
  return ( isalnum(c) == 0 ? 0x0 : 0x1);
}


// Checks for an alphabetic character.
// It is equivalent to (isupper(c) || islower(c)).
inline boolean isAlpha(int c)
{
  return ( isalpha(c) == 0 ? 0x0 : 0x1);
}


// Checks whether c is a 7-bit unsigned char value
// that fits into the ASCII character set.
inline boolean isAscii(int c)
{
/*  return ( isascii(c) == 0 ? false : true); */
  return ( (c & ~0x7f) != 0 ? 0x0 : 0x1);
}


// Checks for a blank character, that is, a space or a tab.
inline boolean isWhitespace(int c)
{
  return ( isblank (c) == 0 ? 0x0 : 0x1);
}


// Checks for a control character.
inline boolean isControl(int c)
{
  return ( iscntrl (c) == 0 ? 0x0 : 0x1);
}


// Checks for a digit (0 through 9).
inline boolean isDigit(int c)
{
  return ( isdigit (c) == 0 ? 0x0 : 0x1);
}


// Checks for any printable character except space.
inline boolean isGraph(int c)
{
  return ( isgraph (c) == 0 ? 0x0 : 0x1);
}


// Checks for a lower-case character.
inline boolean isLowerCase(int c)
{
  return (islower (c) == 0 ? 0x0 : 0x1);
}


// Checks for any printable character including space.
inline boolean isPrintable(int c)
{
  return ( isprint (c) == 0 ? 0x0 : 0x1);
}


// Checks for any printable character which is not a space
// or an alphanumeric character.
inline boolean isPunct(int c)
{
  return ( ispunct (c) == 0 ? 0x0 : 0x1);
}


// Checks for white-space characters. For the avr-libc library,
// these are: space, formfeed ('\f'), newline ('\n'), carriage
// return ('\r'), horizontal tab ('\t'), and vertical tab ('\v').
inline boolean isSpace(int c)
{
  return ( isspace (c) == 0 ? 0x0 : 0x1);
}


// Checks for an uppercase letter.
inline boolean isUpperCase(int c)
{
  return ( isupper (c) == 0 ? 0x0 : 0x1);
}


// Checks for a hexadecimal digits, i.e. one of 0 1 2 3 4 5 6 7
// 8 9 a b c d e f A B C D E F.
inline boolean isHexadecimalDigit(int c)
{
  return ( isxdigit (c) == 0 ? 0x0 : 0x1);
}


// Converts c to a 7-bit unsigned char value that fits into the
// ASCII character set, by clearing the high-order bits.
inline int toAscii(int c)
{
/*  return toascii (c); */
  return (c & 0x7f);
}


// Warning:
// Many people will be unhappy if you use this function.
// This function will convert accented letters into random
// characters.

// Converts the letter c to lower case, if possible.
inline int toLowerCase(int c)
{
  return tolower (c);
}


// Converts the letter c to upper case, if possible.
inline int toUpperCase(int c)
{
  return toupper (c);
}


}
# 180 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/WString.h" 1
/*
  WString.h - String library for Wiring & Arduino
  ...mostly rewritten by Paul Stoffregen...
  Copyright (c) 2009-10 Hernando Barragan.  All right reserved.
  Copyright 2011, Paul Stoffregen, paul@pjrc.com

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





# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdlib.h" 1 3
/*
 * stdlib.h
 *
 * Definitions for common types, variables, and functions.
 */
# 27 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/WString.h" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/string.h" 1 3
/*
 * string.h
 *
 * Definitions for memory and string functions.
 */
# 28 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/WString.h" 2

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/avr/pgmspace.h" 1
/*
  pgmspace.h - Definitions for compatibility with AVR pgmspace macros

  Copyright (c) 2015 Arduino LLC

  Based on work of Paul Stoffregen on Teensy 3 (http://pjrc.com)

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE
*/
# 30 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/WString.h" 2

// When compiling programs with this class, the following gcc parameters
// dramatically increase performance and memory (RAM) efficiency, typically
// with little or no increase in code size.
//     -felide-constructors
//     -std=c++0x

class __FlashStringHelper;


// An inherited class for holding the result of a concatenation.  These
// result objects are assumed to be writable by subsequent concatenations.
class StringSumHelper;

// The string class
class String
{
 // use a function pointer to allow for "if (s)" without the
 // complications of an operator bool(). for more information, see:
 // http://www.artima.com/cppsource/safebool.html
 typedef void (String::*StringIfHelperType)() const;
 void StringIfHelper() const {}

public:
 // constructors
 // creates a copy of the initial value.
 // if the initial value is null or invalid, or if memory allocation
 // fails, the string will be marked as invalid (i.e. "if (s)" will
 // be false).
 String(const char *cstr = "");
 String(const String &str);
 String(const __FlashStringHelper *str);

 String(String &&rval);
 String(StringSumHelper &&rval);

 explicit String(char c);
 explicit String(unsigned char, unsigned char base=10);
 explicit String(int, unsigned char base=10);
 explicit String(unsigned int, unsigned char base=10);
 explicit String(long, unsigned char base=10);
 explicit String(unsigned long, unsigned char base=10);
 explicit String(float, unsigned char decimalPlaces=2);
 explicit String(double, unsigned char decimalPlaces=2);
 ~String(void);

 // memory management
 // return true on success, false on failure (in which case, the string
 // is left unchanged).  reserve(0), if successful, will validate an
 // invalid string (i.e., "if (s)" will be true afterwards)
 unsigned char reserve(unsigned int size);
 inline unsigned int length(void) const {return len;}

 // creates a copy of the assigned value.  if the value is null or
 // invalid, or if the memory allocation fails, the string will be 
 // marked as invalid ("if (s)" will be false).
 String & operator = (const String &rhs);
 String & operator = (const char *cstr);
 String & operator = (const __FlashStringHelper *str);

 String & operator = (String &&rval);
 String & operator = (StringSumHelper &&rval);


 // concatenate (works w/ built-in types)

 // returns true on success, false on failure (in which case, the string
 // is left unchanged).  if the argument is null or invalid, the 
 // concatenation is considered unsucessful.  
 unsigned char concat(const String &str);
 unsigned char concat(const char *cstr);
 unsigned char concat(char c);
 unsigned char concat(unsigned char c);
 unsigned char concat(int num);
 unsigned char concat(unsigned int num);
 unsigned char concat(long num);
 unsigned char concat(unsigned long num);
 unsigned char concat(float num);
 unsigned char concat(double num);
 unsigned char concat(const __FlashStringHelper * str);

 // if there's not enough memory for the concatenated value, the string
 // will be left unchanged (but this isn't signalled in any way)
 String & operator += (const String &rhs) {concat(rhs); return (*this);}
 String & operator += (const char *cstr) {concat(cstr); return (*this);}
 String & operator += (char c) {concat(c); return (*this);}
 String & operator += (unsigned char num) {concat(num); return (*this);}
 String & operator += (int num) {concat(num); return (*this);}
 String & operator += (unsigned int num) {concat(num); return (*this);}
 String & operator += (long num) {concat(num); return (*this);}
 String & operator += (unsigned long num) {concat(num); return (*this);}
 String & operator += (float num) {concat(num); return (*this);}
 String & operator += (double num) {concat(num); return (*this);}
 String & operator += (const __FlashStringHelper *str){concat(str); return (*this);}

 friend StringSumHelper & operator + (const StringSumHelper &lhs, const String &rhs);
 friend StringSumHelper & operator + (const StringSumHelper &lhs, const char *cstr);
 friend StringSumHelper & operator + (const StringSumHelper &lhs, char c);
 friend StringSumHelper & operator + (const StringSumHelper &lhs, unsigned char num);
 friend StringSumHelper & operator + (const StringSumHelper &lhs, int num);
 friend StringSumHelper & operator + (const StringSumHelper &lhs, unsigned int num);
 friend StringSumHelper & operator + (const StringSumHelper &lhs, long num);
 friend StringSumHelper & operator + (const StringSumHelper &lhs, unsigned long num);
 friend StringSumHelper & operator + (const StringSumHelper &lhs, float num);
 friend StringSumHelper & operator + (const StringSumHelper &lhs, double num);
 friend StringSumHelper & operator + (const StringSumHelper &lhs, const __FlashStringHelper *rhs);

 // comparison (only works w/ Strings and "strings")
 operator StringIfHelperType() const { return buffer ? &String::StringIfHelper : 0; }
 int compareTo(const String &s) const;
 unsigned char equals(const String &s) const;
 unsigned char equals(const char *cstr) const;
 unsigned char operator == (const String &rhs) const {return equals(rhs);}
 unsigned char operator == (const char *cstr) const {return equals(cstr);}
 unsigned char operator != (const String &rhs) const {return !equals(rhs);}
 unsigned char operator != (const char *cstr) const {return !equals(cstr);}
 unsigned char operator < (const String &rhs) const;
 unsigned char operator > (const String &rhs) const;
 unsigned char operator <= (const String &rhs) const;
 unsigned char operator >= (const String &rhs) const;
 unsigned char equalsIgnoreCase(const String &s) const;
 unsigned char startsWith( const String &prefix) const;
 unsigned char startsWith(const String &prefix, unsigned int offset) const;
 unsigned char endsWith(const String &suffix) const;

 // character acccess
 char charAt(unsigned int index) const;
 void setCharAt(unsigned int index, char c);
 char operator [] (unsigned int index) const;
 char& operator [] (unsigned int index);
 void getBytes(unsigned char *buf, unsigned int bufsize, unsigned int index=0) const;
 void toCharArray(char *buf, unsigned int bufsize, unsigned int index=0) const
  {getBytes((unsigned char *)buf, bufsize, index);}
 const char * c_str() const { return buffer; }

 // search
 int indexOf( char ch ) const;
 int indexOf( char ch, unsigned int fromIndex ) const;
 int indexOf( const String &str ) const;
 int indexOf( const String &str, unsigned int fromIndex ) const;
 int lastIndexOf( char ch ) const;
 int lastIndexOf( char ch, unsigned int fromIndex ) const;
 int lastIndexOf( const String &str ) const;
 int lastIndexOf( const String &str, unsigned int fromIndex ) const;
 String substring( unsigned int beginIndex ) const { return substring(beginIndex, len); };
 String substring( unsigned int beginIndex, unsigned int endIndex ) const;

 // modification
 void replace(char find, char replace);
 void replace(const String& find, const String& replace);
 void remove(unsigned int index);
 void remove(unsigned int index, unsigned int count);
 void toLowerCase(void);
 void toUpperCase(void);
 void trim(void);

 // parsing/conversion
 long toInt(void) const;
 float toFloat(void) const;

protected:
 char *buffer; // the actual char array
 unsigned int capacity; // the array length minus one (for the '\0')
 unsigned int len; // the String length (not counting the '\0')
protected:
 void init(void);
 void invalidate(void);
 unsigned char changeBuffer(unsigned int maxStrLen);
 unsigned char concat(const char *cstr, unsigned int length);

 // copy and move
 String & copy(const char *cstr, unsigned int length);
 String & copy(const __FlashStringHelper *pstr, unsigned int length);

 void move(String &rhs);

};

class StringSumHelper : public String
{
public:
 StringSumHelper(const String &s) : String(s) {}
 StringSumHelper(const char *p) : String(p) {}
 StringSumHelper(char c) : String(c) {}
 StringSumHelper(unsigned char num) : String(num) {}
 StringSumHelper(int num) : String(num) {}
 StringSumHelper(unsigned int num) : String(num) {}
 StringSumHelper(long num) : String(num) {}
 StringSumHelper(unsigned long num) : String(num) {}
 StringSumHelper(float num) : String(num) {}
 StringSumHelper(double num) : String(num) {}
};
# 181 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Tone.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 182 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/WMath.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/




extern long random( long ) ;
extern long random( long, long ) ;
extern void randomSeed( uint32_t dwSeed ) ;
extern long map( long, long, long, long, long ) ;

extern uint16_t makeWord( uint16_t w ) ;
extern uint16_t makeWord( uint8_t h, uint8_t l ) ;
# 183 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/HardwareSerial.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/inttypes.h" 1 3
/*
 * Copyright (c) 2004, 2005 by
 * Ralf Corsepius, Ulm/Germany. All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software
 * is freely granted, provided that this notice is preserved.
 */

/**
 *  @file  inttypes.h
 */
# 23 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/HardwareSerial.h" 2

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Stream.h" 1
/*
  Stream.h - base class for character-based streams.
  Copyright (c) 2010 David A. Mellis.  All right reserved.

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

  parsing functions based on TextFinder library by Michael Margolis
*/




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/inttypes.h" 1 3
/*
 * Copyright (c) 2004, 2005 by
 * Ralf Corsepius, Ulm/Germany. All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software
 * is freely granted, provided that this notice is preserved.
 */

/**
 *  @file  inttypes.h
 */
# 26 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Stream.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Print.h" 1
/*
  Print.h - Base class that provides print() and println()
  Copyright (c) 2008 David A. Mellis.  All right reserved.

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




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/inttypes.h" 1 3
/*
 * Copyright (c) 2004, 2005 by
 * Ralf Corsepius, Ulm/Germany. All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software
 * is freely granted, provided that this notice is preserved.
 */

/**
 *  @file  inttypes.h
 */
# 24 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Print.h" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdio.h" 1 3
/*
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	@(#)stdio.h	5.3 (Berkeley) 3/15/86
 */

/*
 * NB: to fit things in six character monocase externals, the
 * stdio code uses the prefix `__s' for stdio objects, typically
 * followed by a three-character attempt at a mnemonic.
 */




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/_ansi.h" 1 3
/* Provide support for both ANSI and non-ANSI environments.  */

/* Some ANSI environments are "broken" in the sense that __STDC__ cannot be
   relied upon to have it's intended meaning.  Therefore we must use our own
   concoction: _HAVE_STDC.  Always use _HAVE_STDC instead of __STDC__ in newlib
   sources!

   To get a strict ANSI C environment, define macro __STRICT_ANSI__.  This will
   "comment out" the non-ANSI parts of the ANSI header files (non-ANSI header
   files aren't affected).  */
# 30 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdio.h" 2 3





# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 1 3 4
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
# 46 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */

/* On 4.3bsd-net2, make sure ansi.h is included, so we have
   one less case to deal with in the following.  */



/* On FreeBSD 5, machine/ansi.h does not exist anymore... */




/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
   defined if the corresponding type is *not* defined.
   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_ */
# 92 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 117 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 157 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* If this symbol has done its job, get rid of it.  */




/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 238 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 358 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
    are already defined.  */
/*  BSD/OS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
# 394 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* A null pointer constant.  */
# 412 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* Offset of member MEMBER in a struct of type TYPE. */
# 36 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdio.h" 2 3


# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stdarg.h" 1 3 4
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
 * ISO C Standard:  7.15  Variable arguments  <stdarg.h>
 */
# 36 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stdarg.h" 3 4
/* Define __gnuc_va_list.  */



typedef __builtin_va_list __gnuc_va_list;


/* Define the standard macros for the user,
   if this invocation was from the user program.  */
# 39 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdio.h" 2 3

/*
 * <sys/reent.h> defines __FILE, _fpos_t.
 * They must be defined there because struct _reent needs them (and we don't
 * want reent.h to include this file.
 */

# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/reent.h" 1 3
/* This header file provides the reentrancy.  */

/* WARNING: All identifiers here must begin with an underscore.  This file is
   included by stdio.h and others and we therefore must only use identifiers
   in the namespace allotted to us.  */
# 47 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdio.h" 2 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/types.h" 1 3
/* unified sys/types.h: 
   start with sef's sysvi386 version.
   merge go32 version -- a few ifdefs.
   h8300hms, h8300xray, and sysvnecv70 disagree on the following types:

   typedef int gid_t;
   typedef int uid_t;
   typedef int dev_t;
   typedef int ino_t;
   typedef int mode_t;
   typedef int caddr_t;

   however, these aren't "reasonable" values, the sysvi386 ones make far 
   more sense, and should work sufficiently well (in particular, h8300 
   doesn't have a stat, and the necv70 doesn't matter.) -- eichin
 */



# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/_ansi.h" 1 3
/* Provide support for both ANSI and non-ANSI environments.  */

/* Some ANSI environments are "broken" in the sense that __STDC__ cannot be
   relied upon to have it's intended meaning.  Therefore we must use our own
   concoction: _HAVE_STDC.  Always use _HAVE_STDC instead of __STDC__ in newlib
   sources!

   To get a strict ANSI C environment, define macro __STRICT_ANSI__.  This will
   "comment out" the non-ANSI parts of the ANSI header files (non-ANSI header
   files aren't affected).  */
# 21 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/types.h" 2 3




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/_types.h" 1 3
/*
 *  $Id$
 */
# 26 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/types.h" 2 3
# 61 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/types.h" 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/_types.h" 1 3
/* ANSI C namespace clean utility typedefs */

/* This file defines various typedefs needed by the system calls that support
   the C library.  Basically, they're just the POSIX versions with an '_'
   prepended.  This file lives in the `sys' directory so targets can provide
   their own if desired (or they can put target dependant conditionals here).
*/
# 62 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/types.h" 2 3







# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 1 3 4
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
# 70 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/types.h" 2 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/types.h" 1 3



/*
 *  The following section is RTEMS specific and is needed to more
 *  closely match the types defined in the BSD machine/types.h.
 *  This is needed to let the RTEMS/BSD TCP/IP stack compile.
 */
# 19 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/types.h" 3
typedef long int __off_t;
typedef int __pid_t;

__extension__ typedef long long int __loff_t;
# 71 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/types.h" 2 3

/* To ensure the stat struct's layout doesn't change when sizeof(int), etc.
   changes, we assume sizeof short and long never change and have all types
   used to define struct stat use them and not int where possible.
   Where not possible, _ST_INTxx are used.  It would be preferable to not have
   such assumptions, but until the extra fluff is necessary, it's avoided.
   No 64 bit targets use stat yet.  What to do about them is postponed
   until necessary.  */
# 91 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/types.h" 3
/* also defined in mingw/gmon.h and in w32api/winsock[2].h */

typedef unsigned char u_char;



typedef unsigned short u_short;



typedef unsigned int u_int;



typedef unsigned long u_long;





typedef unsigned short ushort; /* System V compatibility */
typedef unsigned int uint; /* System V compatibility */
typedef unsigned long ulong; /* System V compatibility */



typedef unsigned long /* clock() */ clock_t;




typedef long /* time() */ time_t;





/* Time Value Specification Structures, P1003.1b-1993, p. 261 */

struct timespec {
  time_t tv_sec; /* Seconds */
  long tv_nsec; /* Nanoseconds */
};


struct itimerspec {
  struct timespec it_interval; /* Timer period */
  struct timespec it_value; /* Timer expiration */
};


typedef long daddr_t;



typedef char * caddr_t;
# 155 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/types.h" 3
typedef unsigned short ino_t;
# 176 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/types.h" 3
/*
 * All these should be machine specific - right now they are all broken.
 * However, for all of Cygnus' embedded targets, we want them to all be
 * the same.  Otherwise things like sizeof (struct stat) might depend on
 * how the file was compiled (e.g. -mint16 vs -mint32, etc.).
 */


typedef _off_t off_t;
typedef __dev_t dev_t;
typedef __uid_t uid_t;
typedef __gid_t gid_t;





typedef int pid_t;







typedef long key_t;

typedef _ssize_t ssize_t;
# 217 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/types.h" 3
typedef unsigned int mode_t __attribute__ ((__mode__ (__SI__)));




typedef unsigned short nlink_t;

/* We don't define fd_set and friends if we are compiling POSIX
   source, or if we have included (or may include as indicated
   by __USE_W32_SOCKETS) the W32api winsock[2].h header which
   defines Windows versions of them.   Note that a program which
   includes the W32api winsock[2].h header must know what it is doing;
   it must not call the cygwin32 select function.
*/



/*
 * Select uses bit masks of file descriptors in longs.
 * These macros manipulate such bit fields (the filesystem macros use chars).
 * FD_SETSIZE may be defined by the user, but the default here
 * should be >= NOFILE (param.h).
 */




typedef long fd_mask;





/* We use a macro for fd_set so that including Sockets.h afterwards
   can work.  */
typedef struct _types_fd_set {
 fd_mask fds_bits[(((64)+(((sizeof (fd_mask) * 8 /* number of bits in a byte */) /* bits per mask */)-1))/((sizeof (fd_mask) * 8 /* number of bits in a byte */) /* bits per mask */))];
} _types_fd_set;
# 275 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/types.h" 3
typedef unsigned long clockid_t;




typedef unsigned long timer_t;



typedef unsigned long useconds_t;
typedef long suseconds_t;

# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/features.h" 1 3
/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id$
 */
# 288 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/types.h" 2 3


/* Cygwin will probably never have full posix compliance due to little things
 * like an inability to set the stackaddress. Cygwin is also using void *  
 * pointers rather than structs to ensure maximum binary compatability with
 * previous releases.
 * This means that we don't use the types defined here, but rather in
 * <cygwin/types.h>
 */
# 485 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/types.h" 3
/* POSIX Barrier Types */
# 497 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/types.h" 3
/* POSIX Spin Lock Types */






/* POSIX Reader/Writer Lock Types */
# 48 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdio.h" 2 3

extern "C" {

typedef __FILE FILE;




typedef _fpos_t fpos_t;





# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/stdio.h" 1 3




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/reent.h" 1 3
/* This header file provides the reentrancy.  */

/* WARNING: All identifiers here must begin with an underscore.  This file is
   included by stdio.h and others and we therefore must only use identifiers
   in the namespace allotted to us.  */
# 6 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/stdio.h" 2 3

/* Internal locking macros, used to protect stdio functions.  In the
   general case, expand to nothing. Use __SSTR flag in FILE _flags to
   detect if FILE is private to sprintf/sscanf class of functions; if
   set then do nothing as lock is not initialised. */
# 63 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdio.h" 2 3





 /* RD and WR are never simultaneously asserted */
# 84 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdio.h" 3
/* _flags2 flags */


/*
 * The following three definitions are for ANSI C, which took them
 * from System V, which stupidly took internal interface macros and
 * made them official arguments to setvbuf(), without renaming them.
 * Hence, these ugly _IOxxx names are *supposed* to appear in user code.
 *
 * Although these happen to match their counterparts above, the
 * implementation does not rely on that (so these could be renumbered).
 */
# 150 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdio.h" 3
/*
 * Functions defined in ANSI C standard.
 */
# 162 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdio.h" 3
FILE * tmpfile (void);
char * tmpnam (char *);
int fclose (FILE *);
int fflush (FILE *);
FILE * freopen (const char *, const char *, FILE *);
void setbuf (FILE *, char *);
int setvbuf (FILE *, char *, int, size_t);
int fprintf (FILE *, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
                                                            ;
int fscanf (FILE *, const char *, ...) __attribute__ ((__format__ (__scanf__, 2, 3)))
                                                           ;
int iprintf (const char *, ...) __attribute__ ((__format__ (__printf__, 1, 2)))
                                                            ;
int scanf (const char *, ...) __attribute__ ((__format__ (__scanf__, 1, 2)))
                                                           ;
int sscanf (const char *, const char *, ...) __attribute__ ((__format__ (__scanf__, 2, 3)))
                                                           ;
int vfprintf (FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
                                                            ;
int vprintf (const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 1, 0)))
                                                            ;
int vsprintf (char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
                                                            ;
int fgetc (FILE *);
char * fgets (char *, int, FILE *);
int fputc (int, FILE *);
int fputs (const char *, FILE *);
int getc (FILE *);
int getchar (void);
char * gets (char *);
int putc (int, FILE *);
int putchar (int);
int puts (const char *);
int ungetc (int, FILE *);
size_t fread (void * , size_t _size, size_t _n, FILE *);
size_t fwrite (const void * , size_t _size, size_t _n, FILE *);



int fgetpos (FILE *, fpos_t *);

int fseek (FILE *, long, int);



int fsetpos (FILE *, const fpos_t *);

long ftell ( FILE *);
void rewind (FILE *);
void clearerr (FILE *);
int feof (FILE *);
int ferror (FILE *);
void perror (const char *);

FILE * fopen (const char * _name, const char * _type);
int sprintf (char *, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
                                                            ;
int remove (const char *);
int rename (const char *, const char *);
# 230 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdio.h" 3
int fseeko (FILE *, off_t, int);
off_t ftello ( FILE *);




int asiprintf (char **, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
                                                            ;
char * asniprintf (char *, size_t *, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
                                                            ;
char * asnprintf (char *, size_t *, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
                                                            ;
int asprintf (char **, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
                                                            ;

int diprintf (int, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
                                                            ;

int fcloseall (void);
int fiprintf (FILE *, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
                                                            ;
int fiscanf (FILE *, const char *, ...) __attribute__ ((__format__ (__scanf__, 2, 3)))
                                                           ;
int iprintf (const char *, ...) __attribute__ ((__format__ (__printf__, 1, 2)))
                                                            ;
int iscanf (const char *, ...) __attribute__ ((__format__ (__scanf__, 1, 2)))
                                                           ;
int siprintf (char *, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
                                                            ;
int siscanf (const char *, const char *, ...) __attribute__ ((__format__ (__scanf__, 2, 3)))
                                                           ;
int snprintf (char *, size_t, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
                                                            ;
int sniprintf (char *, size_t, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
                                                            ;
char * tempnam (const char *, const char *);
int vasiprintf (char **, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
                                                            ;
char * vasniprintf (char *, size_t *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
                                                            ;
char * vasnprintf (char *, size_t *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
                                                            ;
int vasprintf (char **, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
                                                            ;
int vdiprintf (int, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
                                                            ;
int vfiprintf (FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
                                                            ;
int vfiscanf (FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)))
                                                           ;
int vfscanf (FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)))
                                                           ;
int viprintf (const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 1, 0)))
                                                            ;
int viscanf (const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 1, 0)))
                                                           ;
int vscanf (const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 1, 0)))
                                                           ;
int vsiprintf (char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
                                                            ;
int vsiscanf (const char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)))
                                                           ;
int vsniprintf (char *, size_t, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
                                                            ;
int vsnprintf (char *, size_t, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
                                                            ;
int vsscanf (const char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)))
                                                           ;



/*
 * Routines in POSIX 1003.1:2001.
 */



FILE * fdopen (int, const char *);

int fileno (FILE *);
int getw (FILE *);
int pclose (FILE *);
FILE * popen (const char *, const char *);
int putw (int, FILE *);
void setbuffer (FILE *, char *, int);
int setlinebuf (FILE *);
int getc_unlocked (FILE *);
int getchar_unlocked (void);
void flockfile (FILE *);
int ftrylockfile (FILE *);
void funlockfile (FILE *);
int putc_unlocked (int, FILE *);
int putchar_unlocked (int);


/*
 * Routines in POSIX 1003.1:200x.
 */




int dprintf (int, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
                                                            ;

FILE * fmemopen (void *, size_t, const char *);
/* getdelim - see __getdelim for now */
/* getline - see __getline for now */
FILE * open_memstream (char **, size_t *);



int vdprintf (int, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
                                                            ;



/*
 * Recursive versions of the above.
 */

int _asiprintf_r (struct _reent *, char **, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
                                                            ;
char * _asniprintf_r (struct _reent *, char *, size_t *, const char *, ...) __attribute__ ((__format__ (__printf__, 4, 5)))
                                                            ;
char * _asnprintf_r (struct _reent *, char *, size_t *, const char *, ...) __attribute__ ((__format__ (__printf__, 4, 5)))
                                                            ;
int _asprintf_r (struct _reent *, char **, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
                                                            ;
int _diprintf_r (struct _reent *, int, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
                                                            ;
int _dprintf_r (struct _reent *, int, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
                                                            ;
int _fclose_r (struct _reent *, FILE *);
int _fcloseall_r (struct _reent *);
FILE * _fdopen_r (struct _reent *, int, const char *);
int _fflush_r (struct _reent *, FILE *);
int _fgetc_r (struct _reent *, FILE *);
char * _fgets_r (struct _reent *, char *, int, FILE *);




int _fgetpos_r (struct _reent *, FILE *, fpos_t *);
int _fsetpos_r (struct _reent *, FILE *, const fpos_t *);

int _fiprintf_r (struct _reent *, FILE *, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
                                                            ;
int _fiscanf_r (struct _reent *, FILE *, const char *, ...) __attribute__ ((__format__ (__scanf__, 3, 4)))
                                                           ;
FILE * _fmemopen_r (struct _reent *, void *, size_t, const char *);
FILE * _fopen_r (struct _reent *, const char *, const char *);
FILE * _freopen_r (struct _reent *, const char *, const char *, FILE *);
int _fprintf_r (struct _reent *, FILE *, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
                                                            ;
int _fpurge_r (struct _reent *, FILE *);
int _fputc_r (struct _reent *, int, FILE *);
int _fputs_r (struct _reent *, const char *, FILE *);
size_t _fread_r (struct _reent *, void * , size_t _size, size_t _n, FILE *);
int _fscanf_r (struct _reent *, FILE *, const char *, ...) __attribute__ ((__format__ (__scanf__, 3, 4)))
                                                           ;
int _fseek_r (struct _reent *, FILE *, long, int);
int _fseeko_r (struct _reent *, FILE *, _off_t, int);
long _ftell_r (struct _reent *, FILE *);
_off_t _ftello_r (struct _reent *, FILE *);
void _rewind_r (struct _reent *, FILE *);
size_t _fwrite_r (struct _reent *, const void * , size_t _size, size_t _n, FILE *);
int _getc_r (struct _reent *, FILE *);
int _getc_unlocked_r (struct _reent *, FILE *);
int _getchar_r (struct _reent *);
int _getchar_unlocked_r (struct _reent *);
char * _gets_r (struct _reent *, char *);
int _iprintf_r (struct _reent *, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
                                                            ;
int _iscanf_r (struct _reent *, const char *, ...) __attribute__ ((__format__ (__scanf__, 2, 3)))
                                                           ;
FILE * _open_memstream_r (struct _reent *, char **, size_t *);
void _perror_r (struct _reent *, const char *);
int _printf_r (struct _reent *, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
                                                            ;
int _putc_r (struct _reent *, int, FILE *);
int _putc_unlocked_r (struct _reent *, int, FILE *);
int _putchar_unlocked_r (struct _reent *, int);
int _putchar_r (struct _reent *, int);
int _puts_r (struct _reent *, const char *);
int _remove_r (struct _reent *, const char *);
int _rename_r (struct _reent *, const char *_old, const char *_new)
                                          ;
int _scanf_r (struct _reent *, const char *, ...) __attribute__ ((__format__ (__scanf__, 2, 3)))
                                                           ;
int _siprintf_r (struct _reent *, char *, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
                                                            ;
int _siscanf_r (struct _reent *, const char *, const char *, ...) __attribute__ ((__format__ (__scanf__, 3, 4)))
                                                           ;
int _sniprintf_r (struct _reent *, char *, size_t, const char *, ...) __attribute__ ((__format__ (__printf__, 4, 5)))
                                                            ;
int _snprintf_r (struct _reent *, char *, size_t, const char *, ...) __attribute__ ((__format__ (__printf__, 4, 5)))
                                                            ;
int _sprintf_r (struct _reent *, char *, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
                                                            ;
int _sscanf_r (struct _reent *, const char *, const char *, ...) __attribute__ ((__format__ (__scanf__, 3, 4)))
                                                           ;
char * _tempnam_r (struct _reent *, const char *, const char *);
FILE * _tmpfile_r (struct _reent *);
char * _tmpnam_r (struct _reent *, char *);
int _ungetc_r (struct _reent *, int, FILE *);
int _vasiprintf_r (struct _reent *, char **, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
                                                            ;
char * _vasniprintf_r (struct _reent*, char *, size_t *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 4, 0)))
                                                            ;
char * _vasnprintf_r (struct _reent*, char *, size_t *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 4, 0)))
                                                            ;
int _vasprintf_r (struct _reent *, char **, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
                                                            ;
int _vdiprintf_r (struct _reent *, int, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
                                                            ;
int _vdprintf_r (struct _reent *, int, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
                                                            ;
int _vfiprintf_r (struct _reent *, FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
                                                            ;
int _vfiscanf_r (struct _reent *, FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 3, 0)))
                                                           ;
int _vfprintf_r (struct _reent *, FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
                                                            ;
int _vfscanf_r (struct _reent *, FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 3, 0)))
                                                           ;
int _viprintf_r (struct _reent *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
                                                            ;
int _viscanf_r (struct _reent *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)))
                                                           ;
int _vprintf_r (struct _reent *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
                                                            ;
int _vscanf_r (struct _reent *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)))
                                                           ;
int _vsiprintf_r (struct _reent *, char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
                                                            ;
int _vsiscanf_r (struct _reent *, const char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 3, 0)))
                                                           ;
int _vsniprintf_r (struct _reent *, char *, size_t, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 4, 0)))
                                                            ;
int _vsnprintf_r (struct _reent *, char *, size_t, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 4, 0)))
                                                            ;
int _vsprintf_r (struct _reent *, char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
                                                            ;
int _vsscanf_r (struct _reent *, const char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 3, 0)))
                                                           ;

/* Other extensions.  */

int fpurge (FILE *);
ssize_t __getdelim (char **, size_t *, int, FILE *);
ssize_t __getline (char **, size_t *, FILE *);
# 505 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdio.h" 3
/*
 * Routines internal to the implementation.
 */

int __srget_r (struct _reent *, FILE *);
int __swbuf_r (struct _reent *, int, FILE *);

/*
 * Stdio function-access interface.
 */
# 533 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdio.h" 3
FILE *funopen (const void * __cookie, int (*__readfn)(void * __cookie, char *__buf, int __n), int (*__writefn)(void * __cookie, const char *__buf, int __n), fpos_t (*__seekfn)(void * __cookie, fpos_t __off, int __whence), int (*__closefn)(void * __cookie))





                                   ;
FILE *_funopen_r (struct _reent *, const void * __cookie, int (*__readfn)(void * __cookie, char *__buf, int __n), int (*__writefn)(void * __cookie, const char *__buf, int __n), fpos_t (*__seekfn)(void * __cookie, fpos_t __off, int __whence), int (*__closefn)(void * __cookie))





                                   ;







typedef ssize_t cookie_read_function_t(void *__cookie, char *__buf, size_t __n);
typedef ssize_t cookie_write_function_t(void *__cookie, const char *__buf,
     size_t __n);




typedef int cookie_seek_function_t(void *__cookie, off_t *__off, int __whence);

typedef int cookie_close_function_t(void *__cookie);
typedef struct
{
  /* These four struct member names are dictated by Linux; hopefully,
     they don't conflict with any macros.  */
  cookie_read_function_t *read;
  cookie_write_function_t *write;
  cookie_seek_function_t *seek;
  cookie_close_function_t *close;
} cookie_io_functions_t;
FILE *fopencookie (void *__cookie, const char *__mode, cookie_io_functions_t __functions)
                                                         ;
FILE *_fopencookie_r (struct _reent *, void *__cookie, const char *__mode, cookie_io_functions_t __functions)
                                                         ;



/*
 * The __sfoo macros are here so that we can 
 * define function versions in the C library.
 */
# 626 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdio.h" 3
/*
 * This has been tuned to generate reasonable code on the vax using pcc
 */
# 670 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdio.h" 3
/* fast always-buffered version, true iff error */
# 685 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdio.h" 3
}
# 25 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Print.h" 2

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/WString.h" 1
/*
  WString.h - String library for Wiring & Arduino
  ...mostly rewritten by Paul Stoffregen...
  Copyright (c) 2009-10 Hernando Barragan.  All right reserved.
  Copyright 2011, Paul Stoffregen, paul@pjrc.com

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
# 27 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Print.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Printable.h" 1
/*
  Printable.h - Interface class that allows printing of complex types
  Copyright (c) 2011 Adrian McEwen.  All right reserved.

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




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdlib.h" 1 3
/*
 * stdlib.h
 *
 * Definitions for common types, variables, and functions.
 */
# 24 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Printable.h" 2

class Print;

/** The Printable class provides a way for new classes to allow themselves to be printed.
    By deriving from Printable and implementing the printTo method, it will then be possible
    for users to print out instances of this class by passing them into the usual
    Print::print and Print::println methods.
*/

class Printable
{
  public:
    virtual size_t printTo(Print& p) const = 0;
};
# 28 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Print.h" 2






class Print
{
  private:
    int write_error;
    size_t printNumber(unsigned long, uint8_t);
    size_t printFloat(double, uint8_t);
  protected:
    void setWriteError(int err = 1) { write_error = err; }
  public:
    Print() : write_error(0) {}

    int getWriteError() { return write_error; }
    void clearWriteError() { setWriteError(0); }

    virtual size_t write(uint8_t) = 0;
    size_t write(const char *str) {
      if (str == __null) return 0;
      return write((const uint8_t *)str, strlen(str));
    }
    virtual size_t write(const uint8_t *buffer, size_t size);
    size_t write(const char *buffer, size_t size) {
      return write((const uint8_t *)buffer, size);
    }

    size_t print(const __FlashStringHelper *);
    size_t print(const String &);
    size_t print(const char[]);
    size_t print(char);
    size_t print(unsigned char, int = 10);
    size_t print(int, int = 10);
    size_t print(unsigned int, int = 10);
    size_t print(long, int = 10);
    size_t print(unsigned long, int = 10);
    size_t print(double, int = 2);
    size_t print(const Printable&);

    size_t println(const __FlashStringHelper *);
    size_t println(const String &s);
    size_t println(const char[]);
    size_t println(char);
    size_t println(unsigned char, int = 10);
    size_t println(int, int = 10);
    size_t println(unsigned int, int = 10);
    size_t println(long, int = 10);
    size_t println(unsigned long, int = 10);
    size_t println(double, int = 2);
    size_t println(const Printable&);
    size_t println(void);
};
# 27 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Stream.h" 2

// compatability macros for testing
/*
#define   getInt()            parseInt()
#define   getInt(skipChar)    parseInt(skipchar)
#define   getFloat()          parseFloat()
#define   getFloat(skipChar)  parseFloat(skipChar)
#define   getString( pre_string, post_string, buffer, length)
readBytesBetween( pre_string, terminator, buffer, length)
*/

class Stream : public Print
{
  protected:
    unsigned long _timeout; // number of milliseconds to wait for the next char before aborting timed read
    unsigned long _startMillis; // used for timeout measurement
    int timedRead(); // private method to read stream with timeout
    int timedPeek(); // private method to peek stream with timeout
    int peekNextDigit(); // returns the next numeric digit in the stream or -1 if timeout

  public:
    virtual int available() = 0;
    virtual int read() = 0;
    virtual int peek() = 0;
    virtual void flush() = 0;

    Stream() {_timeout=1000;}

// parsing methods

  void setTimeout(unsigned long timeout); // sets maximum milliseconds to wait for stream data, default is 1 second

  bool find(char *target); // reads data from the stream until the target string is found
  bool find(uint8_t *target) { return find ((char *)target); }
  // returns true if target string is found, false if timed out (see setTimeout)

  bool find(char *target, size_t length); // reads data from the stream until the target string of given length is found
  bool find(uint8_t *target, size_t length) { return find ((char *)target, length); }
  // returns true if target string is found, false if timed out

  bool findUntil(char *target, char *terminator); // as find but search ends if the terminator string is found
  bool findUntil(uint8_t *target, char *terminator) { return findUntil((char *)target, terminator); }

  bool findUntil(char *target, size_t targetLen, char *terminate, size_t termLen); // as above but search ends if the terminate string is found
  bool findUntil(uint8_t *target, size_t targetLen, char *terminate, size_t termLen) {return findUntil((char *)target, targetLen, terminate, termLen); }


  long parseInt(); // returns the first valid (long) integer value from the current position.
  // initial characters that are not digits (or the minus sign) are skipped
  // integer is terminated by the first character that is not a digit.

  float parseFloat(); // float version of parseInt

  size_t readBytes( char *buffer, size_t length); // read chars from stream into buffer
  size_t readBytes( uint8_t *buffer, size_t length) { return readBytes((char *)buffer, length); }
  // terminates if length characters have been read or timeout (see setTimeout)
  // returns the number of characters placed in the buffer (0 means no valid data found)

  size_t readBytesUntil( char terminator, char *buffer, size_t length); // as readBytes with terminator character
  size_t readBytesUntil( char terminator, uint8_t *buffer, size_t length) { return readBytesUntil(terminator, (char *)buffer, length); }
  // terminates if length characters have been read, timeout, or if the terminator character  detected
  // returns the number of characters placed in the buffer (0 means no valid data found)

  // Arduino String functions to be added here
  String readString();
  String readStringUntil(char terminator);

  protected:
  long parseInt(char skipChar); // as above but the given skipChar is ignored
  // as above but the given skipChar is ignored
  // this allows format characters (typically commas) in values to be ignored

  float parseFloat(char skipChar); // as above but the given skipChar is ignored

  struct MultiTarget {
    const char *str; // string you're searching for
    size_t len; // length of string you're searching for
    size_t index; // index used by the search routine.
  };

  // This allows you to search for an arbitrary number of strings.
  // Returns index of the target that is found first or -1 if timeout occurs.
  int findMulti(struct MultiTarget *targets, int tCount);
};
# 25 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/HardwareSerial.h" 2

class HardwareSerial : public Stream
{
  public:
    virtual void begin(unsigned long);
    virtual void end();
    virtual int available(void) = 0;
    virtual int peek(void) = 0;
    virtual int read(void) = 0;
    virtual void flush(void) = 0;
    virtual size_t write(uint8_t) = 0;
    using Print::write; // pull in write(str) and write(buf, size) from Print
    virtual operator bool() = 0;
};

extern void serialEventRun(void) __attribute__((weak));
# 184 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/wiring_pulse.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/





 extern "C" {


unsigned long countPulseASM(const volatile uint32_t *port, uint32_t bit, uint32_t stateMask, unsigned long maxloops);
/*
 * \brief Measures the length (in microseconds) of a pulse on the pin; state is HIGH
 * or LOW, the type of pulse to measure.  Works on pulses from 2-3 microseconds
 * to 3 minutes in length, but must be called at least a few dozen microseconds
 * before the start of the pulse.
 */
extern uint32_t pulseIn( uint32_t ulPin, uint32_t ulState, uint32_t ulTimeout = 1000000L ) ;
extern uint32_t pulseInLong( uint8_t pin, uint8_t state, unsigned long timeout = 1000000L ) ;


}
# 185 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2



// Include board variant
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/variants/arduino_due_x/variant.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/




/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */


/** Master clock frequency */


/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 1
/*
  Arduino.h - Main include file for the Arduino SDK
  Copyright (c) 2005-2013 Arduino Team.  All right reserved.

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
# 37 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/variants/arduino_due_x/variant.h" 2

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/UARTClass.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/




# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/HardwareSerial.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 23 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/UARTClass.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/RingBuffer.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/






// Define constants and variables for buffering incoming serial data.  We're
// using a ring buffer (I think), in which head is the index of the location
// to which to write the next incoming character and tail is the index of the
// location from which to read.


class RingBuffer
{
  public:
    volatile uint8_t _aucBuffer[128] ;
    volatile int _iHead ;
    volatile int _iTail ;

  public:
    RingBuffer( void ) ;
    void store_char( uint8_t c ) ;
} ;
# 24 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/UARTClass.h" 2

// Includes Atmel CMSIS
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 27 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/UARTClass.h" 2
# 35 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/UARTClass.h"
class UARTClass : public HardwareSerial
{
  public:
    enum UARTModes {
      Mode_8N1 = (0x3u << 6) /**< \brief (US_MR) Character length is 8 bits */ | (0x0u << 12) /**< \brief (US_MR) 1 stop bit */ | (0x4u << 9) /**< \brief (UART_MR) No parity */,
      Mode_8E1 = (0x3u << 6) /**< \brief (US_MR) Character length is 8 bits */ | (0x0u << 12) /**< \brief (US_MR) 1 stop bit */ | (0x0u << 9) /**< \brief (UART_MR) Even parity */,
      Mode_8O1 = (0x3u << 6) /**< \brief (US_MR) Character length is 8 bits */ | (0x0u << 12) /**< \brief (US_MR) 1 stop bit */ | (0x1u << 9) /**< \brief (UART_MR) Odd parity */,
      Mode_8M1 = (0x3u << 6) /**< \brief (US_MR) Character length is 8 bits */ | (0x0u << 12) /**< \brief (US_MR) 1 stop bit */ | (0x3u << 9) /**< \brief (UART_MR) Mark: parity forced to 1 */,
      Mode_8S1 = (0x3u << 6) /**< \brief (US_MR) Character length is 8 bits */ | (0x0u << 12) /**< \brief (US_MR) 1 stop bit */ | (0x2u << 9) /**< \brief (UART_MR) Space: parity forced to 0 */,
    };
    UARTClass(Uart* pUart, IRQn_Type dwIrq, uint32_t dwId, RingBuffer* pRx_buffer, RingBuffer* pTx_buffer);

    void begin(const uint32_t dwBaudRate);
    void begin(const uint32_t dwBaudRate, const UARTModes config);
    void end(void);
    int available(void);
    int availableForWrite(void);
    int peek(void);
    int read(void);
    void flush(void);
    size_t write(const uint8_t c);
    using Print::write; // pull in write(str) and write(buf, size) from Print

    void setInterruptPriority(uint32_t priority);
    uint32_t getInterruptPriority();

    void IrqHandler(void);

    operator bool() { return 0x1; }; // UART always active

  protected:
    void init(const uint32_t dwBaudRate, const uint32_t config);

    RingBuffer *_rx_buffer;
    RingBuffer *_tx_buffer;

    Uart* _pUart;
    IRQn_Type _dwIrq;
    uint32_t _dwId;

};
# 39 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/variants/arduino_due_x/variant.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/USARTClass.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/




# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/UARTClass.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 23 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/USARTClass.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/RingBuffer.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 24 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/USARTClass.h" 2

// Includes Atmel CMSIS
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/chip.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 27 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/USARTClass.h" 2

// Define config for Serial.begin(baud, config);
# 66 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/USARTClass.h"
class USARTClass : public UARTClass
{
  public:
    // 8x1 bit modes are inherited from UARTClass
    enum USARTModes {
      Mode_5N1 = (0x0u << 6) /**< \brief (US_MR) Character length is 5 bits */ | (0x4u << 9) /**< \brief (US_MR) No parity */ | (0x0u << 12) /**< \brief (US_MR) 1 stop bit */,
      Mode_6N1 = (0x1u << 6) /**< \brief (US_MR) Character length is 6 bits */ | (0x4u << 9) /**< \brief (US_MR) No parity */ | (0x0u << 12) /**< \brief (US_MR) 1 stop bit */,
      Mode_7N1 = (0x2u << 6) /**< \brief (US_MR) Character length is 7 bits */ | (0x4u << 9) /**< \brief (US_MR) No parity */ | (0x0u << 12) /**< \brief (US_MR) 1 stop bit */,
      Mode_5N2 = (0x0u << 6) /**< \brief (US_MR) Character length is 5 bits */ | (0x4u << 9) /**< \brief (US_MR) No parity */ | (0x2u << 12) /**< \brief (US_MR) 2 stop bits */,
      Mode_6N2 = (0x1u << 6) /**< \brief (US_MR) Character length is 6 bits */ | (0x4u << 9) /**< \brief (US_MR) No parity */ | (0x2u << 12) /**< \brief (US_MR) 2 stop bits */,
      Mode_7N2 = (0x2u << 6) /**< \brief (US_MR) Character length is 7 bits */ | (0x4u << 9) /**< \brief (US_MR) No parity */ | (0x2u << 12) /**< \brief (US_MR) 2 stop bits */,
      Mode_8N2 = (0x3u << 6) /**< \brief (US_MR) Character length is 8 bits */ | (0x4u << 9) /**< \brief (US_MR) No parity */ | (0x2u << 12) /**< \brief (US_MR) 2 stop bits */,
      Mode_5E1 = (0x0u << 6) /**< \brief (US_MR) Character length is 5 bits */ | (0x0u << 9) /**< \brief (US_MR) Even parity */ | (0x0u << 12) /**< \brief (US_MR) 1 stop bit */,
      Mode_6E1 = (0x1u << 6) /**< \brief (US_MR) Character length is 6 bits */ | (0x0u << 9) /**< \brief (US_MR) Even parity */ | (0x0u << 12) /**< \brief (US_MR) 1 stop bit */,
      Mode_7E1 = (0x2u << 6) /**< \brief (US_MR) Character length is 7 bits */ | (0x0u << 9) /**< \brief (US_MR) Even parity */ | (0x0u << 12) /**< \brief (US_MR) 1 stop bit */,
      Mode_5E2 = (0x0u << 6) /**< \brief (US_MR) Character length is 5 bits */ | (0x0u << 9) /**< \brief (US_MR) Even parity */ | (0x2u << 12) /**< \brief (US_MR) 2 stop bits */,
      Mode_6E2 = (0x1u << 6) /**< \brief (US_MR) Character length is 6 bits */ | (0x0u << 9) /**< \brief (US_MR) Even parity */ | (0x2u << 12) /**< \brief (US_MR) 2 stop bits */,
      Mode_7E2 = (0x2u << 6) /**< \brief (US_MR) Character length is 7 bits */ | (0x0u << 9) /**< \brief (US_MR) Even parity */ | (0x2u << 12) /**< \brief (US_MR) 2 stop bits */,
      Mode_8E2 = (0x3u << 6) /**< \brief (US_MR) Character length is 8 bits */ | (0x0u << 9) /**< \brief (US_MR) Even parity */ | (0x2u << 12) /**< \brief (US_MR) 2 stop bits */,
      Mode_5O1 = (0x0u << 6) /**< \brief (US_MR) Character length is 5 bits */ | (0x1u << 9) /**< \brief (US_MR) Odd parity */ | (0x0u << 12) /**< \brief (US_MR) 1 stop bit */,
      Mode_6O1 = (0x1u << 6) /**< \brief (US_MR) Character length is 6 bits */ | (0x1u << 9) /**< \brief (US_MR) Odd parity */ | (0x0u << 12) /**< \brief (US_MR) 1 stop bit */,
      Mode_7O1 = (0x2u << 6) /**< \brief (US_MR) Character length is 7 bits */ | (0x1u << 9) /**< \brief (US_MR) Odd parity */ | (0x0u << 12) /**< \brief (US_MR) 1 stop bit */,
      Mode_5O2 = (0x0u << 6) /**< \brief (US_MR) Character length is 5 bits */ | (0x1u << 9) /**< \brief (US_MR) Odd parity */ | (0x2u << 12) /**< \brief (US_MR) 2 stop bits */,
      Mode_6O2 = (0x1u << 6) /**< \brief (US_MR) Character length is 6 bits */ | (0x1u << 9) /**< \brief (US_MR) Odd parity */ | (0x2u << 12) /**< \brief (US_MR) 2 stop bits */,
      Mode_7O2 = (0x2u << 6) /**< \brief (US_MR) Character length is 7 bits */ | (0x1u << 9) /**< \brief (US_MR) Odd parity */ | (0x2u << 12) /**< \brief (US_MR) 2 stop bits */,
      Mode_8O2 = (0x3u << 6) /**< \brief (US_MR) Character length is 8 bits */ | (0x1u << 9) /**< \brief (US_MR) Odd parity */ | (0x2u << 12) /**< \brief (US_MR) 2 stop bits */,
      Mode_5M1 = (0x0u << 6) /**< \brief (US_MR) Character length is 5 bits */ | (0x3u << 9) /**< \brief (US_MR) Parity forced to 1 (Mark) */ | (0x0u << 12) /**< \brief (US_MR) 1 stop bit */,
      Mode_6M1 = (0x1u << 6) /**< \brief (US_MR) Character length is 6 bits */ | (0x3u << 9) /**< \brief (US_MR) Parity forced to 1 (Mark) */ | (0x0u << 12) /**< \brief (US_MR) 1 stop bit */,
      Mode_7M1 = (0x2u << 6) /**< \brief (US_MR) Character length is 7 bits */ | (0x3u << 9) /**< \brief (US_MR) Parity forced to 1 (Mark) */ | (0x0u << 12) /**< \brief (US_MR) 1 stop bit */,
      Mode_5M2 = (0x0u << 6) /**< \brief (US_MR) Character length is 5 bits */ | (0x3u << 9) /**< \brief (US_MR) Parity forced to 1 (Mark) */ | (0x2u << 12) /**< \brief (US_MR) 2 stop bits */,
      Mode_6M2 = (0x1u << 6) /**< \brief (US_MR) Character length is 6 bits */ | (0x3u << 9) /**< \brief (US_MR) Parity forced to 1 (Mark) */ | (0x2u << 12) /**< \brief (US_MR) 2 stop bits */,
      Mode_7M2 = (0x2u << 6) /**< \brief (US_MR) Character length is 7 bits */ | (0x3u << 9) /**< \brief (US_MR) Parity forced to 1 (Mark) */ | (0x2u << 12) /**< \brief (US_MR) 2 stop bits */,
      Mode_8M2 = (0x3u << 6) /**< \brief (US_MR) Character length is 8 bits */ | (0x3u << 9) /**< \brief (US_MR) Parity forced to 1 (Mark) */ | (0x2u << 12) /**< \brief (US_MR) 2 stop bits */,
      Mode_5S1 = (0x0u << 6) /**< \brief (US_MR) Character length is 5 bits */ | (0x2u << 9) /**< \brief (US_MR) Parity forced to 0 (Space) */ | (0x0u << 12) /**< \brief (US_MR) 1 stop bit */,
      Mode_6S1 = (0x1u << 6) /**< \brief (US_MR) Character length is 6 bits */ | (0x2u << 9) /**< \brief (US_MR) Parity forced to 0 (Space) */ | (0x0u << 12) /**< \brief (US_MR) 1 stop bit */,
      Mode_7S1 = (0x2u << 6) /**< \brief (US_MR) Character length is 7 bits */ | (0x2u << 9) /**< \brief (US_MR) Parity forced to 0 (Space) */ | (0x0u << 12) /**< \brief (US_MR) 1 stop bit */,
      Mode_5S2 = (0x0u << 6) /**< \brief (US_MR) Character length is 5 bits */ | (0x2u << 9) /**< \brief (US_MR) Parity forced to 0 (Space) */ | (0x2u << 12) /**< \brief (US_MR) 2 stop bits */,
      Mode_6S2 = (0x1u << 6) /**< \brief (US_MR) Character length is 6 bits */ | (0x2u << 9) /**< \brief (US_MR) Parity forced to 0 (Space) */ | (0x2u << 12) /**< \brief (US_MR) 2 stop bits */,
      Mode_7S2 = (0x2u << 6) /**< \brief (US_MR) Character length is 7 bits */ | (0x2u << 9) /**< \brief (US_MR) Parity forced to 0 (Space) */ | (0x2u << 12) /**< \brief (US_MR) 2 stop bits */,
      Mode_8S2 = (0x3u << 6) /**< \brief (US_MR) Character length is 8 bits */ | (0x2u << 9) /**< \brief (US_MR) Parity forced to 0 (Space) */ | (0x2u << 12) /**< \brief (US_MR) 2 stop bits */,
    };

    USARTClass(Usart* pUsart, IRQn_Type dwIrq, uint32_t dwId, RingBuffer* pRx_buffer, RingBuffer* pTx_buffer);

    void begin(const uint32_t dwBaudRate);
    void begin(const uint32_t dwBaudRate, const USARTModes config);
    void begin(const uint32_t dwBaudRate, const UARTModes config);

  protected:
    Usart* _pUsart;
};
# 40 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/variants/arduino_due_x/variant.h" 2



extern "C"{


/**
 * Libc porting layers
 */

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/syscalls.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

/**
  * \file syscalls.h
  *
  * Implementation of newlib syscall.
  *
  */

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/stdio.h" 1 3
/*
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	@(#)stdio.h	5.3 (Berkeley) 3/15/86
 */

/*
 * NB: to fit things in six character monocase externals, the
 * stdio code uses the prefix `__s' for stdio objects, typically
 * followed by a three-character attempt at a mnemonic.
 */
# 30 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/syscalls.h" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stdarg.h" 1 3 4
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
 * ISO C Standard:  7.15  Variable arguments  <stdarg.h>
 */
# 36 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stdarg.h" 3 4
/* Define __gnuc_va_list.  */






/* Define the standard macros for the user,
   if this invocation was from the user program.  */
# 55 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stdarg.h" 3 4
/* Define va_list, if desired, from __gnuc_va_list. */
/* We deliberately do not define va_list when called from
   stdio.h, because ANSI C says that stdio.h is not supposed to define
   va_list.  stdio.h needs to have access to that data type, 
   but must not use that name.  It should use the name __gnuc_va_list,
   which is safe because it is reserved for the implementation.  */
# 85 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stdarg.h" 3 4
/* The macro _VA_LIST_ is the same thing used by this file in Ultrix.
   But on BSD NET2 we must not test or define or undef it.
   (Note that the comments in NET 2's ansi.h
   are incorrect for _VA_LIST_--see stdio.h!)  */

/* The macro _VA_LIST_DEFINED is used in Windows NT 3.5  */

/* The macro _VA_LIST is used in SCO Unix 3.2.  */

/* The macro _VA_LIST_T_H is used in the Bull dpx2  */

/* The macro __va_list__ is used by BeOS.  */

typedef __gnuc_va_list va_list;
# 31 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/syscalls.h" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/types.h" 1 3
/* unified sys/types.h: 
   start with sef's sysvi386 version.
   merge go32 version -- a few ifdefs.
   h8300hms, h8300xray, and sysvnecv70 disagree on the following types:

   typedef int gid_t;
   typedef int uid_t;
   typedef int dev_t;
   typedef int ino_t;
   typedef int mode_t;
   typedef int caddr_t;

   however, these aren't "reasonable" values, the sysvi386 ones make far 
   more sense, and should work sufficiently well (in particular, h8300 
   doesn't have a stat, and the necv70 doesn't matter.) -- eichin
 */
# 32 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/syscalls.h" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/stat.h" 1 3




extern "C" {


# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/_ansi.h" 1 3
/* Provide support for both ANSI and non-ANSI environments.  */

/* Some ANSI environments are "broken" in the sense that __STDC__ cannot be
   relied upon to have it's intended meaning.  Therefore we must use our own
   concoction: _HAVE_STDC.  Always use _HAVE_STDC instead of __STDC__ in newlib
   sources!

   To get a strict ANSI C environment, define macro __STRICT_ANSI__.  This will
   "comment out" the non-ANSI parts of the ANSI header files (non-ANSI header
   files aren't affected).  */
# 9 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/stat.h" 2 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/time.h" 1 3
/*
 * time.h
 * 
 * Struct and function declarations for dealing with time.
 */




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/_ansi.h" 1 3
/* Provide support for both ANSI and non-ANSI environments.  */

/* Some ANSI environments are "broken" in the sense that __STDC__ cannot be
   relied upon to have it's intended meaning.  Therefore we must use our own
   concoction: _HAVE_STDC.  Always use _HAVE_STDC instead of __STDC__ in newlib
   sources!

   To get a strict ANSI C environment, define macro __STRICT_ANSI__.  This will
   "comment out" the non-ANSI parts of the ANSI header files (non-ANSI header
   files aren't affected).  */
# 11 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/time.h" 2 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/reent.h" 1 3
/* This header file provides the reentrancy.  */

/* WARNING: All identifiers here must begin with an underscore.  This file is
   included by stdio.h and others and we therefore must only use identifiers
   in the namespace allotted to us.  */
# 12 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/time.h" 2 3



# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 1 3 4
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
# 46 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */

/* On 4.3bsd-net2, make sure ansi.h is included, so we have
   one less case to deal with in the following.  */



/* On FreeBSD 5, machine/ansi.h does not exist anymore... */




/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
   defined if the corresponding type is *not* defined.
   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_ */
# 92 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 117 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 157 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* If this symbol has done its job, get rid of it.  */




/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 238 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 358 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
    are already defined.  */
/*  BSD/OS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
# 394 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* A null pointer constant.  */
# 412 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/lib/gcc/arm-none-eabi/4.8.3/include/stddef.h" 3 4
/* Offset of member MEMBER in a struct of type TYPE. */
# 16 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/time.h" 2 3

/* Get _CLOCKS_PER_SEC_ */
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/machine/time.h" 1 3
# 19 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/time.h" 2 3
# 27 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/time.h" 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/types.h" 1 3
/* unified sys/types.h: 
   start with sef's sysvi386 version.
   merge go32 version -- a few ifdefs.
   h8300hms, h8300xray, and sysvnecv70 disagree on the following types:

   typedef int gid_t;
   typedef int uid_t;
   typedef int dev_t;
   typedef int ino_t;
   typedef int mode_t;
   typedef int caddr_t;

   however, these aren't "reasonable" values, the sysvi386 ones make far 
   more sense, and should work sufficiently well (in particular, h8300 
   doesn't have a stat, and the necv70 doesn't matter.) -- eichin
 */
# 28 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/time.h" 2 3

extern "C" {

struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
};

clock_t clock (void);
double difftime (time_t _time2, time_t _time1);
time_t mktime (struct tm *_timeptr);
time_t time (time_t *_timer);

char *asctime (const struct tm *_tblock);
char *ctime (const time_t *_time);
struct tm *gmtime (const time_t *_timer);
struct tm *localtime (const time_t *_timer);

size_t strftime (char * _s, size_t _maxsize, const char * _fmt, const struct tm * _t)

                                        ;

char *asctime_r (const struct tm *, char *)
                       ;
char *ctime_r (const time_t *, char *);
struct tm *gmtime_r (const time_t *, struct tm *)
                            ;
struct tm *localtime_r (const time_t *, struct tm *)
                            ;

}


extern "C" {



char *strptime (const char *, const char *, struct tm *)

                            ;
void tzset (void);
void _tzset_r (struct _reent *);

typedef struct __tzrule_struct
{
  char ch;
  int m;
  int n;
  int d;
  int s;
  time_t change;
  long offset; /* Match type of _timezone. */
} __tzrule_type;

typedef struct __tzinfo_struct
{
  int __tznorth;
  int __tzyear;
  __tzrule_type __tzrule[2];
} __tzinfo_type;

__tzinfo_type *__gettzinfo (void);

/* getdate functions */
# 122 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/time.h" 3
/* defines for the opengroup specifications Derived from Issue 1 of the SVID.  */
extern long _timezone;
extern int _daylight;
extern char *_tzname[2];

/* POSIX defines the external tzname being defined in time.h */






}


# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/features.h" 1 3
/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id$
 */
# 138 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/time.h" 2 3
# 203 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/time.h" 3
extern "C" {


/* CPU-time Clock Attributes, P1003.4b/D8, p. 54 */

/* values for the clock enable attribute */




/* values for the pthread cputime_clock_allowed attribute */


                           /*   CPU-time clock attached to that thread */
                           /*   shall be accessible. */

                           /*   thread shall not have a CPU-time clock */
                           /*   accessible. */

/* Manifest Constants, P1003.1b-1993, p. 262 */



/* Flag indicating time is "absolute" with respect to the clock
   associated with a time.  */



/* Manifest Constants, P1003.4b/D8, p. 55 */
# 281 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/time.h" 3
}
# 10 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/stat.h" 2 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/types.h" 1 3
/* unified sys/types.h: 
   start with sef's sysvi386 version.
   merge go32 version -- a few ifdefs.
   h8300hms, h8300xray, and sysvnecv70 disagree on the following types:

   typedef int gid_t;
   typedef int uid_t;
   typedef int dev_t;
   typedef int ino_t;
   typedef int mode_t;
   typedef int caddr_t;

   however, these aren't "reasonable" values, the sysvi386 ones make far 
   more sense, and should work sufficiently well (in particular, h8300 
   doesn't have a stat, and the necv70 doesn't matter.) -- eichin
 */
# 11 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/stat.h" 2 3

/* dj's stat defines _STAT_H_ */


/* It is intended that the layout of this structure not change when the
   sizes of any of the basic types change (short, int, long) [via a compile
   time option].  */







struct stat
{
  dev_t st_dev;
  ino_t st_ino;
  mode_t st_mode;
  nlink_t st_nlink;
  uid_t st_uid;
  gid_t st_gid;
  dev_t st_rdev;
  off_t st_size;







  /* SysV/sco doesn't have the rest... But Solaris, eabi does.  */





  time_t st_atime;
  long st_spare1;
  time_t st_mtime;
  long st_spare2;
  time_t st_ctime;
  long st_spare3;
  long st_blksize;
  long st_blocks;
  long st_spare4[2];


};
# 145 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/stat.h" 3
int chmod ( const char *__path, mode_t __mode );
int fchmod (int __fd, mode_t __mode);
int fstat ( int __fd, struct stat *__sbuf );
int mkdir ( const char *_path, mode_t __mode );
int mkfifo ( const char *__path, mode_t __mode );
int stat ( const char * __path, struct stat * __sbuf );
mode_t umask ( mode_t __mask );
# 168 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/stat.h" 3
/* Provide prototypes for most of the _<systemcall> names that are
   provided in newlib for some compilers.  */
# 183 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/sys/stat.h" 3
}
# 33 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/syscalls.h" 2

/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/

extern "C" {


extern caddr_t _sbrk( int incr ) ;

extern int link( char *cOld, char *cNew ) ;

extern int _close( int file ) ;

extern int _fstat( int file, struct stat *st ) ;

extern int _isatty( int file ) ;

extern int _lseek( int file, int ptr, int dir ) ;

extern int _read(int file, char *ptr, int len) ;

extern int _write( int file, char *ptr, int len ) ;


}
# 51 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/variants/arduino_due_x/variant.h" 2


/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array






//#define analogInPinToBit(P)        ( )




/*
 * portModeRegister(..) should return a register to set pin mode
 * INPUT or OUTPUT by setting the corresponding bit to 0 or 1.
 * Unfortunately on SAM architecture the PIO_OSR register is
 * read-only and can be set only through the enable/disable registers
 * pair PIO_OER/PIO_ODR.
 */
// #define portModeRegister(port)   ( &(port->PIO_OSR) )

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAM
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

// Interrupts


// LEDs
# 99 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/variants/arduino_due_x/variant.h"
/*
 * SPI Interfaces
 */
# 129 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/variants/arduino_due_x/variant.h"
static const uint8_t SS = (10u);
static const uint8_t SS1 = (4u);
static const uint8_t SS2 = (52u);
static const uint8_t SS3 = (78u);
static const uint8_t MOSI = (75u);
static const uint8_t MISO = (74u);
static const uint8_t SCK = (76u);

/*
 * Wire Interfaces
 */
# 156 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/variants/arduino_due_x/variant.h"
/*
 * UART/USART Interfaces
 */
// Serial

// Serial1

// Serial2

// Serial3


/*
 * USB Interfaces
 */


/*
 * Analog pins
 */
static const uint8_t A0 = 54;
static const uint8_t A1 = 55;
static const uint8_t A2 = 56;
static const uint8_t A3 = 57;
static const uint8_t A4 = 58;
static const uint8_t A5 = 59;
static const uint8_t A6 = 60;
static const uint8_t A7 = 61;
static const uint8_t A8 = 62;
static const uint8_t A9 = 63;
static const uint8_t A10 = 64;
static const uint8_t A11 = 65;
static const uint8_t DAC0 = 66;
static const uint8_t DAC1 = 67;
static const uint8_t CANRX = 68;
static const uint8_t CANTX = 69;


/*
 * Complementary CAN pins
 */
static const uint8_t CAN1RX = 88;
static const uint8_t CAN1TX = 89;

// CAN0

// CAN1



/*
 * DACC
 */






/*
 * PWM
 */







/*
 * TC
 */
# 236 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/variants/arduino_due_x/variant.h"
}


/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/



extern UARTClass Serial;
extern USARTClass Serial1;
extern USARTClass Serial2;
extern USARTClass Serial3;



// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
# 190 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/wiring.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.
  Copyright (c) 2013 by Paul Stoffregen <paul@pjrc.com> (delayMicroseconds)

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/





extern "C" {


/**
 *
 */
extern void initVariant( void ) ;
extern void init( void ) ;

/**
 * \brief Returns the number of milliseconds since the Arduino board began running the current program.
 *
 * This number will overflow (go back to zero), after approximately 50 days.
 *
 * \return Number of milliseconds since the program started (uint32_t)
 */
extern uint32_t millis( void ) ;

/**
 * \brief Returns the number of microseconds since the Arduino board began running the current program.
 *
 * This number will overflow (go back to zero), after approximately 70 minutes. On 16 MHz Arduino boards
 * (e.g. Duemilanove and Nano), this function has a resolution of four microseconds (i.e. the value returned is
 * always a multiple of four). On 8 MHz Arduino boards (e.g. the LilyPad), this function has a resolution
 * of eight microseconds.
 *
 * \note There are 1,000 microseconds in a millisecond and 1,000,000 microseconds in a second.
 */
extern uint32_t micros( void ) ;

/**
 * \brief Pauses the program for the amount of time (in miliseconds) specified as parameter.
 * (There are 1000 milliseconds in a second.)
 *
 * \param dwMs the number of milliseconds to pause (uint32_t)
 */
extern void delay( uint32_t dwMs ) ;

/**
 * \brief Pauses the program for the amount of time (in microseconds) specified as parameter.
 *
 * \param dwUs the number of microseconds to pause (uint32_t)
 */
static inline void delayMicroseconds(uint32_t) __attribute__((always_inline, unused));
static inline void delayMicroseconds(uint32_t usec){
    /*
     * Based on Paul Stoffregen's implementation
     * for Teensy 3.0 (http://www.pjrc.com/)
     */
    if (usec == 0) return;
    uint32_t n = usec * (84000000 / 3000000);
    asm volatile(
        "L_%=_delayMicroseconds:" "\n\t"
        "subs   %0, #1" "\n\t"
        "bne    L_%=_delayMicroseconds" "\n"
        : "+r" (n) :
    );
}


}
# 192 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/wiring_digital.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/





 extern "C" {


/**
 * \brief Configures the specified pin to behave either as an input or an output. See the description of digital pins for details.
 *
 * \param ulPin The number of the pin whose mode you wish to set
 * \param ulMode Either INPUT or OUTPUT
 */
extern void pinMode( uint32_t dwPin, uint32_t dwMode ) ;

/**
 * \brief Write a HIGH or a LOW value to a digital pin.
 *
 * If the pin has been configured as an OUTPUT with pinMode(), its voltage will be set to the
 * corresponding value: 5V (or 3.3V on 3.3V boards) for HIGH, 0V (ground) for LOW.
 *
 * If the pin is configured as an INPUT, writing a HIGH value with digitalWrite() will enable an internal
 * 20K pullup resistor (see the tutorial on digital pins). Writing LOW will disable the pullup. The pullup
 * resistor is enough to light an LED dimly, so if LEDs appear to work, but very dimly, this is a likely
 * cause. The remedy is to set the pin to an output with the pinMode() function.
 *
 * \note Digital pin PIN_LED is harder to use as a digital input than the other digital pins because it has an LED
 * and resistor attached to it that's soldered to the board on most boards. If you enable its internal 20k pull-up
 * resistor, it will hang at around 1.7 V instead of the expected 5V because the onboard LED and series resistor
 * pull the voltage level down, meaning it always returns LOW. If you must use pin PIN_LED as a digital input, use an
 * external pull down resistor.
 *
 * \param dwPin the pin number
 * \param dwVal HIGH or LOW
 */
extern void digitalWrite( uint32_t dwPin, uint32_t dwVal ) ;

/**
 * \brief Reads the value from a specified digital pin, either HIGH or LOW.
 *
 * \param ulPin The number of the digital pin you want to read (int)
 *
 * \return HIGH or LOW
 */
extern int digitalRead( uint32_t ulPin ) ;


}
# 193 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/wiring_analog.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/





extern "C" {


/*
 * \brief SAM3 products have only one reference for ADC
 */
typedef enum _eAnalogReference
{
  AR_DEFAULT,
} eAnalogReference ;

/*
 * \brief Configures the reference voltage used for analog input (i.e. the value used as the top of the input range).
 * This function is kept only for compatibility with existing AVR based API.
 *
 * \param ulMmode Should be set to AR_DEFAULT.
 */
extern void analogReference( eAnalogReference ulMode ) ;

/*
 * \brief Writes an analog value (PWM wave) to a pin.
 *
 * \param ulPin
 * \param ulValue
 */
extern void analogWrite( uint32_t ulPin, uint32_t ulValue ) ;

/*
 * \brief Reads the value from the specified analog pin.
 *
 * \param ulPin
 *
 * \return Read value from selected pin, if no error.
 */
extern uint32_t analogRead( uint32_t ulPin ) ;

/*
 * \brief Set the resolution of analogRead return values. Default is 10 bits (range from 0 to 1023).
 *
 * \param res
 */
extern void analogReadResolution(int res);

/*
 * \brief Set the resolution of analogWrite parameters. Default is 8 bits (range from 0 to 255).
 *
 * \param res
 */
extern void analogWriteResolution(int res);

extern void analogOutputInit( void ) ;


}
# 194 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/wiring_shift.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/





 extern "C" {


/*
 * \brief
 */
extern uint32_t shiftIn( uint32_t ulDataPin, uint32_t ulClockPin, uint32_t ulBitOrder ) ;


/*
 * \brief
 */
extern void shiftOut( uint32_t ulDataPin, uint32_t ulClockPin, uint32_t ulBitOrder, uint32_t ulVal ) ;



}
# 195 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/WInterrupts.h" 1
/*
  Copyright (c) 2011-2012 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/




# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 1
/*
  Arduino.h - Main include file for the Arduino SDK
  Copyright (c) 2005-2013 Arduino Team.  All right reserved.

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
# 23 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/WInterrupts.h" 2


extern "C" {


void attachInterrupt(uint32_t pin, void (*callback)(void), uint32_t mode);

void detachInterrupt(uint32_t pin);


}
# 196 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/watchdog.h" 1
/*
  Copyright (c) 2014 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/






// Watchdog functions

/*
 * \brief Enable the watchdog with the specified timeout. Should only be called once.
 *
 * \param timeount in milliseconds.
 */
void watchdogEnable (uint32_t timeout);

/*
 * \brief Disable the watchdog timer. Should only be called once.
 *
 */
void watchdogDisable (void);

/*
 * \brief Reset the watchdog counter.
 *
 */
void watchdogReset (void);

/*
 * \brief Watchdog initialize hook. This function is called from init(). If the user does not provide
 * this function, then the default action is to disable watchdog.
 */
void watchdogSetup (void);
# 198 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2

// USB Device




# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/USB/USBDesc.h" 1
// Copyright (c) 2010, Peter Barrett
/*
** Permission to use, copy, modify, and/or distribute this software for
** any purpose with or without fee is hereby granted, provided that the
** above copyright notice and this permission notice appear in all copies.
**
** THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
** WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR
** BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES
** OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
** WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
** ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
** SOFTWARE.
*/
# 205 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/USB/USBCore.h" 1
// Copyright (c) 2010, Peter Barrett
/*
** Permission to use, copy, modify, and/or distribute this software for
** any purpose with or without fee is hereby granted, provided that the
** above copyright notice and this permission notice appear in all copies.
**
** THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
** WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR
** BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES
** OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
** WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
** ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
** SOFTWARE.
*/




//	Standard requests
# 33 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/USB/USBCore.h"
// bmRequestType
# 53 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/USB/USBCore.h"
//	Class requests
# 62 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/USB/USBCore.h"
//	Descriptors
# 87 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/USB/USBCore.h"
// bMaxPower in Configuration Descriptor


// bEndpointAddress in Endpoint Descriptor
# 120 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/USB/USBCore.h"

# 120 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/USB/USBCore.h"
#pragma pack(1)
# 120 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/USB/USBCore.h"


//	Device
typedef struct {
 uint8_t len; // 18
 uint8_t dtype; // 1 USB_DEVICE_DESCRIPTOR_TYPE
 uint16_t usbVersion; // 0x200
 uint8_t deviceClass;
 uint8_t deviceSubClass;
 uint8_t deviceProtocol;
 uint8_t packetSize0; // Packet 0
 uint16_t idVendor;
 uint16_t idProduct;
 uint16_t deviceVersion; // 0x100
 uint8_t iManufacturer;
 uint8_t iProduct;
 uint8_t iSerialNumber;
 uint8_t bNumConfigurations;
} DeviceDescriptor;

//	Config
typedef struct {
 uint8_t len; // 9
 uint8_t dtype; // 2
 uint16_t clen; // total length
 uint8_t numInterfaces;
 uint8_t config;
 uint8_t iconfig;
 uint8_t attributes;
 uint8_t maxPower;
} ConfigDescriptor;

//	Device Qualifier (only needed for USB2.0 devices)
typedef struct {
 uint8_t bLength;
 uint8_t dtype;
 uint16_t bDescriptorType;
 uint8_t bDeviceClass;
 uint8_t bDeviceSubClass;
 uint8_t bDeviceProtocol;
 uint8_t bMaxPacketSize0;
 uint8_t bNumConfigurations;
} QualifierDescriptor;

//	String

//	Interface
typedef struct
{
 uint8_t len; // 9
 uint8_t dtype; // 4
 uint8_t number;
 uint8_t alternate;
 uint8_t numEndpoints;
 uint8_t interfaceClass;
 uint8_t interfaceSubClass;
 uint8_t protocol;
 uint8_t iInterface;
} InterfaceDescriptor;

//	Endpoint
typedef struct
{
 uint8_t len; // 7
 uint8_t dtype; // 5
 uint8_t addr;
 uint8_t attr;
 uint16_t packetSize;
 uint8_t interval;
} EndpointDescriptor;

// Interface Association Descriptor
// Used to bind 2 interfaces together in CDC compostite device
typedef struct
{
 uint8_t len; // 8
 uint8_t dtype; // 11
 uint8_t firstInterface;
 uint8_t interfaceCount;
 uint8_t functionClass;
 uint8_t funtionSubClass;
 uint8_t functionProtocol;
 uint8_t iInterface;
} IADDescriptor;

//	CDC CS interface descriptor
typedef struct
{
 uint8_t len; // 5
 uint8_t dtype; // 0x24
 uint8_t subtype;
 uint8_t d0;
 uint8_t d1;
} CDCCSInterfaceDescriptor;

typedef struct
{
 uint8_t len; // 4
 uint8_t dtype; // 0x24
 uint8_t subtype;
 uint8_t d0;
} CDCCSInterfaceDescriptor4;

typedef struct
{
    uint8_t len;
    uint8_t dtype; // 0x24
    uint8_t subtype; // 1
    uint8_t bmCapabilities;
    uint8_t bDataInterface;
} CMFunctionalDescriptor;

typedef struct
{
    uint8_t len;
    uint8_t dtype; // 0x24
    uint8_t subtype; // 1
    uint8_t bmCapabilities;
} ACMFunctionalDescriptor;

typedef struct
{
 //	IAD
 IADDescriptor iad; // Only needed on compound device

 //	Control
 InterfaceDescriptor cif;
 CDCCSInterfaceDescriptor header;
 CMFunctionalDescriptor callManagement; // Call Management
 ACMFunctionalDescriptor controlManagement; // ACM
 CDCCSInterfaceDescriptor functionalDescriptor; // CDC_UNION
 EndpointDescriptor cifin;

 //	Data
 InterfaceDescriptor dif;
 EndpointDescriptor in;
 EndpointDescriptor out;
} CDCDescriptor;

typedef struct
{
 InterfaceDescriptor msc;
 EndpointDescriptor in;
 EndpointDescriptor out;
} MSCDescriptor;


# 266 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/USB/USBCore.h"
#pragma pack()
# 266 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/USB/USBCore.h"

# 206 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/USB/USBAPI.h" 1
/*
  Copyright (c) 2012 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/






# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/RingBuffer.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 25 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/USB/USBAPI.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Stream.h" 1
/*
  Stream.h - base class for character-based streams.
  Copyright (c) 2010 David A. Mellis.  All right reserved.

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

  parsing functions based on TextFinder library by Michael Margolis
*/
# 26 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/USB/USBAPI.h" 2

//================================================================================
//================================================================================
//	USB

class USBDevice_
{
public:
 USBDevice_();
 bool configured();

 bool attach();
 bool detach(); // Serial port goes down too...
 void poll();
};
extern USBDevice_ USBDevice;

//================================================================================
//================================================================================
//	Serial over CDC (Serial1 is the physical port)

class Serial_ : public Stream
{
private:
 RingBuffer *_cdc_rx_buffer;
public:
 void begin(uint32_t baud_count);
 void begin(uint32_t baud_count, uint8_t config);
 void end(void);

 virtual int available(void);
 virtual void accept(void);
 virtual int peek(void);
 virtual int read(void);
 virtual void flush(void);
 virtual size_t write(uint8_t);
 virtual size_t write(const uint8_t *buffer, size_t size);
 using Print::write; // pull in write(str) from Print
 operator bool();

 // These return the settings specified by the USB host for the
 // serial port. These aren't really used, but are offered here
 // in case a sketch wants to act on these settings.
 uint32_t baud();
 uint8_t stopbits();
 uint8_t paritytype();
 uint8_t numbits();
 bool dtr();
 bool rts();
 enum {
  ONE_STOP_BIT = 0,
  ONE_AND_HALF_STOP_BIT = 1,
  TWO_STOP_BITS = 2,
 };
 enum {
  NO_PARITY = 0,
  ODD_PARITY = 1,
  EVEN_PARITY = 2,
  MARK_PARITY = 3,
  SPACE_PARITY = 4,
 };
};
extern Serial_ SerialUSB;

//================================================================================
//================================================================================
//	Low level API

typedef struct
{
 uint8_t bmRequestType;
 uint8_t bRequest;
 uint8_t wValueL;
 uint8_t wValueH;
 uint16_t wIndex;
 uint16_t wLength;
} USBSetup;

//================================================================================
//================================================================================
//	MSC 'Driver'

int MSC_GetInterface(uint8_t* interfaceNum);
int MSC_GetDescriptor(int i);
bool MSC_Setup(USBSetup& setup);
bool MSC_Data(uint8_t rx,uint8_t tx);

//================================================================================
//================================================================================
//	CSC 'Driver'

int CDC_GetInterface(uint8_t* interfaceNum);
int CDC_GetOtherInterface(uint8_t* interfaceNum);
int CDC_GetDescriptor(int i);
bool CDC_Setup(USBSetup& setup);

//================================================================================
//================================================================================




void USBD_InitControl(int end);
int USBD_SendControl(uint8_t flags, const void* d, uint32_t len);
int USBD_RecvControl(void* d, uint32_t len);
uint8_t USBD_SendInterfaces(void);
bool USBD_ClassInterfaceRequest(USBSetup& setup);


uint32_t USBD_Available(uint32_t ep);
uint32_t USBD_SendSpace(uint32_t ep);
uint32_t USBD_Send(uint32_t ep, const void* d, uint32_t len);
uint32_t USBD_Recv(uint32_t ep, void* data, uint32_t len); // non-blocking
uint32_t USBD_Recv(uint32_t ep); // non-blocking
void USBD_Flush(uint32_t ep);
uint32_t USBD_Connected(void);
# 207 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 2
# 2 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/integrated.ino.cpp" 2
# 1 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/integrated.ino.cpp"
# 1 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/integrated.ino"
// #include "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.4/libraries/Wire/Wire.h"
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/libraries/Wire/Wire.h" 1
/*
 * TwoWire.h - TWI/I2C library for Arduino Due
 * Copyright (c) 2011 Cristian Maglie <c.maglie@arduino.cc>
 * All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */




// Include Atmel CMSIS driver
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/system/libsam/include/twi.h" 1
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011-2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/**
 * \file
 *
 * Interface for configuration the Two Wire Interface (TWI) peripheral.
 *
 */
# 26 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/libraries/Wire/Wire.h" 2

# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Stream.h" 1
/*
  Stream.h - base class for character-based streams.
  Copyright (c) 2010 David A. Mellis.  All right reserved.

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

  parsing functions based on TextFinder library by Michael Margolis
*/
# 28 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/libraries/Wire/Wire.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/variants/arduino_due_x/variant.h" 1
/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
# 29 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/libraries/Wire/Wire.h" 2



class TwoWire : public Stream {
public:
 TwoWire(Twi *twi, void(*begin_cb)(void));
 void begin();
 void begin(uint8_t);
 void begin(int);
 void setClock(uint32_t);
 void beginTransmission(uint8_t);
 void beginTransmission(int);
 uint8_t endTransmission(void);
    uint8_t endTransmission(uint8_t);
 uint8_t requestFrom(uint8_t, uint8_t);
    uint8_t requestFrom(uint8_t, uint8_t, uint8_t);
    uint8_t requestFrom(uint8_t, uint8_t, uint32_t, uint8_t);
 uint8_t requestFrom(int, int);
    uint8_t requestFrom(int, int, int);
 virtual size_t write(uint8_t);
 virtual size_t write(const uint8_t *, size_t);
 virtual int available(void);
 virtual int read(void);
 virtual int peek(void);
 virtual void flush(void);
 void onReceive(void(*)(int));
 void onRequest(void(*)(void));

    inline size_t write(unsigned long n) { return write((uint8_t)n); }
    inline size_t write(long n) { return write((uint8_t)n); }
    inline size_t write(unsigned int n) { return write((uint8_t)n); }
    inline size_t write(int n) { return write((uint8_t)n); }
    using Print::write;

 void onService(void);

private:
 // RX Buffer
 uint8_t rxBuffer[255];
 uint8_t rxBufferIndex;
 uint8_t rxBufferLength;

 // TX Buffer
 uint8_t txAddress;
 uint8_t txBuffer[255];
 uint8_t txBufferLength;

 // Service buffer
 uint8_t srvBuffer[255];
 uint8_t srvBufferIndex;
 uint8_t srvBufferLength;

 // Callback user functions
 void (*onRequestCallback)(void);
 void (*onReceiveCallback)(int);

 // Called before initialization
 void (*onBeginCallback)(void);

 // TWI instance
 Twi *twi;

 // TWI state
 enum TwoWireStatus {
  UNINITIALIZED,
  MASTER_IDLE,
  MASTER_SEND,
  MASTER_RECV,
  SLAVE_IDLE,
  SLAVE_RECV,
  SLAVE_SEND
 };
 TwoWireStatus status;

 // TWI clock frequency
 static const uint32_t TWI_CLOCK = 100000;
 uint32_t twiClock;

 // Timeouts (
 static const uint32_t RECV_TIMEOUT = 100000;
 static const uint32_t XMIT_TIMEOUT = 100000;
};


extern TwoWire Wire;


extern TwoWire Wire1;
# 3 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/integrated.ino" 2
// extern TwoWire Wire1;
TwoWire *wirex=&Wire1;
# 1 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/config.cpp" 1

/** Constants *************************************************************************/
# 68 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/config.cpp"
/**************************************************************************************/
# 77 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/config.cpp"
// AirsenseBoard



    // #define GP2Y1010AU0F_include 0x01
# 90 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/config.cpp"
// Lightsense board
# 99 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/config.cpp"
    // #define D6T_include 0x01
    // #define MLX90614_include 0x01




// Chemsense board
# 121 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/config.cpp"
// #define system_health_include 0x01
// #define RANDOMIZE_VALID 0x01
// #define SERIAL_DEBUG 0x01
// #define PRINT_BUFFER 0x01


// #define I2C_INTERFACE 0x01
// #define I2C_PACKET_SIZE 163
// #define I2C_INTERFACE_CONST_SIZE 0x01
# 6 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/integrated.ino" 2
// #include "dataFormats.cpp"


# 1 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/./libs/MCP342X_Waggle/MCP342X_Waggle.h" 1



# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 1
/*
  Arduino.h - Main include file for the Arduino SDK
  Copyright (c) 2005-2013 Arduino Team.  All right reserved.

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
# 5 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/./libs/MCP342X_Waggle/MCP342X_Waggle.h" 2


class MCP342X {
public:
 static const byte L = 0;
 static const byte H = 1;
 static const byte F = 2;

 static const byte CHANNEL_0 = 0;
 static const byte CHANNEL_1 = 1;
 static const byte CHANNEL_2 = 2;
 static const byte CHANNEL_3 = 3;

 static const byte GAIN_1 = 0;
 static const byte GAIN_2 = 1;
 static const byte GAIN_4 = 2;
 static const byte GAIN_8 = 3;

 void init(byte A0, byte A1);
 void selectChannel(byte channel, byte gain = GAIN_1);
 unsigned int readADC();
private:
 //communication register
 static const byte BIT_RDY = 7; //data ready
 static const byte BIT_C1 = 6; //channel select
 static const byte BIT_C0 = 5; //channel select
 static const byte BIT_OC = 4; //conversion mode (one shot/continuous)
 static const byte BIT_S1 = 3; //sample rate
 static const byte BIT_S0 = 2; //sample rate
 static const byte BIT_G1 = 1; //gain
 static const byte BIT_G0 = 0; //gain

// 	static const double VRef = 2.048;
 byte I2C_ADDRESS;
};
# 10 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/integrated.ino" 2
MCP342X mcp3428_1;
MCP342X mcp3428_2;




# 1 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/./libs/HTU21D/HTU21D.h" 1
/*
 HTU21D Humidity Sensor Library
 By: Nathan Seidle
 SparkFun Electronics
 Date: September 22nd, 2013
 License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

 Get humidity and temperature from the HTU21D sensor.

 */



# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 1
/*
  Arduino.h - Main include file for the Arduino SDK
  Copyright (c) 2005-2013 Arduino Team.  All right reserved.

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
# 15 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/./libs/HTU21D/HTU21D.h" 2




# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/libraries/Wire/Wire.h" 1
/*
 * TwoWire.h - TWI/I2C library for Arduino Due
 * Copyright (c) 2011 Cristian Maglie <c.maglie@arduino.cc>
 * All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
# 20 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/./libs/HTU21D/HTU21D.h" 2
# 31 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/./libs/HTU21D/HTU21D.h"
class HTU21D {

public:
  HTU21D();

  //Public Functions
  void begin();
  float readHumidity(void);
  float readTemperature(void);
  void setResolution(byte resBits);

  //Public Variables

private:
  //Private Functions

  byte read_user_register(void);
  byte check_crc(uint16_t message_from_sensor, uint8_t check_value_from_sensor);

  //Private Variables

};
# 17 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/integrated.ino" 2
HTU21D myHumidity;



# 1 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/./libs/Adafruit_Sensor-master/Adafruit_Sensor.h" 1
/*
* Copyright (C) 2008 The Android Open Source Project
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software< /span>
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

/* Update by K. Townsend (Adafruit Industries) for lighter typedefs, and
 * extended sensor support to include color, voltage and current */





# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 1
/*
  Arduino.h - Main include file for the Arduino SDK
  Copyright (c) 2005-2013 Arduino Team.  All right reserved.

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
# 25 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/./libs/Adafruit_Sensor-master/Adafruit_Sensor.h" 2
# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Print.h" 1
/*
  Print.h - Base class that provides print() and println()
  Copyright (c) 2008 David A. Mellis.  All right reserved.

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
# 26 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/./libs/Adafruit_Sensor-master/Adafruit_Sensor.h" 2




/* Intentionally modeled after sensors.h in the Android API:
 * https://github.com/android/platform_hardware_libhardware/blob/master/include/hardware/sensors.h */

/* Constants */
# 44 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/./libs/Adafruit_Sensor-master/Adafruit_Sensor.h"
/** Sensor types */
typedef enum
{
  SENSOR_TYPE_ACCELEROMETER = (1), /**< Gravity + linear acceleration */
  SENSOR_TYPE_MAGNETIC_FIELD = (2),
  SENSOR_TYPE_ORIENTATION = (3),
  SENSOR_TYPE_GYROSCOPE = (4),
  SENSOR_TYPE_LIGHT = (5),
  SENSOR_TYPE_PRESSURE = (6),
  SENSOR_TYPE_PROXIMITY = (8),
  SENSOR_TYPE_GRAVITY = (9),
  SENSOR_TYPE_LINEAR_ACCELERATION = (10), /**< Acceleration not including gravity */
  SENSOR_TYPE_ROTATION_VECTOR = (11),
  SENSOR_TYPE_RELATIVE_HUMIDITY = (12),
  SENSOR_TYPE_AMBIENT_TEMPERATURE = (13),
  SENSOR_TYPE_VOLTAGE = (15),
  SENSOR_TYPE_CURRENT = (16),
  SENSOR_TYPE_COLOR = (17)
} sensors_type_t;

/** struct sensors_vec_s is used to return a vector in a common format. */
typedef struct {
    union {
        float v[3];
        struct {
            float x;
            float y;
            float z;
        };
        /* Orientation sensors */
        struct {
            float roll; /**< Rotation around the longitudinal axis (the plane body, 'X axis'). Roll is positive and increasing when moving downward. -90°<=roll<=90° */
            float pitch; /**< Rotation around the lateral axis (the wing span, 'Y axis'). Pitch is positive and increasing when moving upwards. -180°<=pitch<=180°) */
            float heading; /**< Angle between the longitudinal axis (the plane body) and magnetic north, measured clockwise when viewing from the top of the device. 0-359° */
        };
    };
    int8_t status;
    uint8_t reserved[3];
} sensors_vec_t;

/** struct sensors_color_s is used to return color data in a common format. */
typedef struct {
    union {
        float c[3];
        /* RGB color space */
        struct {
            float r; /**< Red component */
            float g; /**< Green component */
            float b; /**< Blue component */
        };
    };
    uint32_t rgba; /**< 24-bit RGBA value */
} sensors_color_t;

/* Sensor event (36 bytes) */
/** struct sensor_event_s is used to provide a single sensor event in a common format. */
typedef struct
{
    int32_t version; /**< must be sizeof(struct sensors_event_t) */
    int32_t sensor_id; /**< unique sensor identifier */
    int32_t type; /**< sensor type */
    int32_t reserved0; /**< reserved */
    int32_t timestamp; /**< time is in milliseconds */
    union
    {
        float data[4];
        sensors_vec_t acceleration; /**< acceleration values are in meter per second per second (m/s^2) */
        sensors_vec_t magnetic; /**< magnetic vector values are in micro-Tesla (uT) */
        sensors_vec_t orientation; /**< orientation values are in degrees */
        sensors_vec_t gyro; /**< gyroscope values are in rad/s */
        float temperature; /**< temperature is in degrees centigrade (Celsius) */
        float distance; /**< distance in centimeters */
        float light; /**< light in SI lux units */
        float pressure; /**< pressure in hectopascal (hPa) */
        float relative_humidity; /**< relative humidity in percent */
        float current; /**< current in milliamps (mA) */
        float voltage; /**< voltage in volts (V) */
        sensors_color_t color; /**< color in RGB component values */
    };
} sensors_event_t;

/* Sensor details (40 bytes) */
/** struct sensor_s is used to describe basic information about a specific sensor. */
typedef struct
{
    char name[12]; /**< sensor name */
    int32_t version; /**< version of the hardware + driver */
    int32_t sensor_id; /**< unique sensor identifier */
    int32_t type; /**< this sensor's type (ex. SENSOR_TYPE_LIGHT) */
    float max_value; /**< maximum value of this sensor's value in SI units */
    float min_value; /**< minimum value of this sensor's value in SI units */
    float resolution; /**< smallest difference between two values reported by this sensor */
    int32_t min_delay; /**< min delay in microseconds between events. zero = not a constant rate */
} sensor_t;

class Adafruit_Sensor {
 public:
  // Constructor(s)
  Adafruit_Sensor() {}
  virtual ~Adafruit_Sensor() {}

  // These must be defined by the subclass
  virtual void enableAutoRange(bool enabled) {};
  virtual bool getEvent(sensors_event_t*) = 0;
  virtual void getSensor(sensor_t*) = 0;

 private:
  bool _autoRange;
};
# 22 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/integrated.ino" 2
# 1 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/./libs/Adafruit_BMP085_Unified-master/Adafruit_BMP085_U.h" 1
/***************************************************************************
  This is a library for the BMP085 pressure sensor

  Designed specifically to work with the Adafruit BMP085 or BMP180 Breakout
  ----> http://www.adafruit.com/products/391
  ----> http://www.adafruit.com/products/1603

  These displays use I2C to communicate, 2 pins are required to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/




# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 1
/*
  Arduino.h - Main include file for the Arduino SDK
  Copyright (c) 2005-2013 Arduino Team.  All right reserved.

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
# 22 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/./libs/Adafruit_BMP085_Unified-master/Adafruit_BMP085_U.h" 2




# 1 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/./libs/Adafruit_BMP085_Unified-master/../Adafruit_Sensor-master/Adafruit_Sensor.h" 1
/*
* Copyright (C) 2008 The Android Open Source Project
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software< /span>
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

/* Update by K. Townsend (Adafruit Industries) for lighter typedefs, and
 * extended sensor support to include color, voltage and current */
# 27 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/./libs/Adafruit_BMP085_Unified-master/Adafruit_BMP085_U.h" 2





# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/libraries/Wire/Wire.h" 1
/*
 * TwoWire.h - TWI/I2C library for Arduino Due
 * Copyright (c) 2011 Cristian Maglie <c.maglie@arduino.cc>
 * All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
# 33 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/./libs/Adafruit_BMP085_Unified-master/Adafruit_BMP085_U.h" 2


/*=========================================================================
    I2C ADDRESS/BITS
    -----------------------------------------------------------------------*/

/*=========================================================================*/

/*=========================================================================
    REGISTERS
    -----------------------------------------------------------------------*/
    enum
    {
      BMP085_REGISTER_CAL_AC1 = 0xAA, // R   Calibration data (16 bits)
      BMP085_REGISTER_CAL_AC2 = 0xAC, // R   Calibration data (16 bits)
      BMP085_REGISTER_CAL_AC3 = 0xAE, // R   Calibration data (16 bits)
      BMP085_REGISTER_CAL_AC4 = 0xB0, // R   Calibration data (16 bits)
      BMP085_REGISTER_CAL_AC5 = 0xB2, // R   Calibration data (16 bits)
      BMP085_REGISTER_CAL_AC6 = 0xB4, // R   Calibration data (16 bits)
      BMP085_REGISTER_CAL_B1 = 0xB6, // R   Calibration data (16 bits)
      BMP085_REGISTER_CAL_B2 = 0xB8, // R   Calibration data (16 bits)
      BMP085_REGISTER_CAL_MB = 0xBA, // R   Calibration data (16 bits)
      BMP085_REGISTER_CAL_MC = 0xBC, // R   Calibration data (16 bits)
      BMP085_REGISTER_CAL_MD = 0xBE, // R   Calibration data (16 bits)
      BMP085_REGISTER_CHIPID = 0xD0,
      BMP085_REGISTER_VERSION = 0xD1,
      BMP085_REGISTER_SOFTRESET = 0xE0,
      BMP085_REGISTER_CONTROL = 0xF4,
      BMP085_REGISTER_TEMPDATA = 0xF6,
      BMP085_REGISTER_PRESSUREDATA = 0xF6,
      BMP085_REGISTER_READTEMPCMD = 0x2E,
      BMP085_REGISTER_READPRESSURECMD = 0x34
    };
/*=========================================================================*/

/*=========================================================================
    MODE SETTINGS
    -----------------------------------------------------------------------*/
    typedef enum
    {
      BMP085_MODE_ULTRALOWPOWER = 0,
      BMP085_MODE_STANDARD = 1,
      BMP085_MODE_HIGHRES = 2,
      BMP085_MODE_ULTRAHIGHRES = 3
    } bmp085_mode_t;
/*=========================================================================*/

/*=========================================================================
    CALIBRATION DATA
    -----------------------------------------------------------------------*/
    typedef struct
    {
      int16_t ac1;
      int16_t ac2;
      int16_t ac3;
      uint16_t ac4;
      uint16_t ac5;
      uint16_t ac6;
      int16_t b1;
      int16_t b2;
      int16_t mb;
      int16_t mc;
      int16_t md;
    } bmp085_calib_data;
/*=========================================================================*/

class Adafruit_BMP085_Unified : public Adafruit_Sensor
{
  public:
    Adafruit_BMP085_Unified(int32_t sensorID = -1);

    bool begin(bmp085_mode_t mode = BMP085_MODE_ULTRAHIGHRES);
    void getTemperature(float *temp);
    void getPressure(float *pressure);
    float pressureToAltitude(float seaLvel, float atmospheric);
    float seaLevelForAltitude(float altitude, float atmospheric);
    // Note that the next two functions are just for compatibility with old
    // code that passed the temperature as a third parameter.  A newer
    // calculation is used which does not need temperature.
    float pressureToAltitude(float seaLevel, float atmospheric, float temp);
    float seaLevelForAltitude(float altitude, float atmospheric, float temp);
    bool getEvent(sensors_event_t*);
    void getSensor(sensor_t*);

  private:
    int32_t computeB5(int32_t ut);
    int32_t _sensorID;
};
# 23 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/integrated.ino" 2
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);
sensors_event_t event;
# 56 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/integrated.ino"
typedef enum TSYS_KPoly_E //structure to hold calibration values from temperature sensor registers
{
    TSYS_K4 = 0,
    TSYS_K3,
    TSYS_K2,
    TSYS_K1,
    TSYS_K0
}
TSYS_KPoly_T;
uint16_t TSYS_coefficents[5];



# 1 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/./libs/HMC5883L_waggle/HMC5883L_waggle.h" 1
/***************************************************************************
  This is a library for the HMC5883 magnentometer/compass

  Designed specifically to work with the Adafruit HMC5883 Breakout
  http://www.adafruit.com/products/1746

  These displays use I2C to communicate, 2 pins are required to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution

  ###########################################################################

  Modified Wed Oct 28 15:01:41 CDT 2015:
  Original files obtained from -
  https://github.com/adafruit/HMC5883_Sensor

  Modifications  (WG, RxS) -
  1. Added support for using sensor on both Wire1 and Wire buses.
  2. Default output in gauss and not Tesla.
  3. Changed filenames.

  ***************************************************************************/




# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/cores/arduino/Arduino.h" 1
/*
  Arduino.h - Main include file for the Arduino SDK
  Copyright (c) 2005-2013 Arduino Team.  All right reserved.

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
# 33 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/./libs/HMC5883L_waggle/HMC5883L_waggle.h" 2




# 1 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/./libs/HMC5883L_waggle/../Adafruit_Sensor-master/Adafruit_Sensor.h" 1
/*
* Copyright (C) 2008 The Android Open Source Project
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software< /span>
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

/* Update by K. Townsend (Adafruit Industries) for lighter typedefs, and
 * extended sensor support to include color, voltage and current */
# 38 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/./libs/HMC5883L_waggle/HMC5883L_waggle.h" 2





# 1 "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.6/libraries/Wire/Wire.h" 1
/*
 * TwoWire.h - TWI/I2C library for Arduino Due
 * Copyright (c) 2011 Cristian Maglie <c.maglie@arduino.cc>
 * All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
# 44 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/./libs/HMC5883L_waggle/HMC5883L_waggle.h" 2



/*=========================================================================
    I2C ADDRESS/BITS
    -----------------------------------------------------------------------*/

/*=========================================================================*/

/*=========================================================================
    REGISTERS
    -----------------------------------------------------------------------*/
    typedef enum
    {
      HMC5883_REGISTER_MAG_CRA_REG_M = 0x00,
      HMC5883_REGISTER_MAG_CRB_REG_M = 0x01,
      HMC5883_REGISTER_MAG_MR_REG_M = 0x02,
      HMC5883_REGISTER_MAG_OUT_X_H_M = 0x03,
      HMC5883_REGISTER_MAG_OUT_X_L_M = 0x04,
      HMC5883_REGISTER_MAG_OUT_Z_H_M = 0x05,
      HMC5883_REGISTER_MAG_OUT_Z_L_M = 0x06,
      HMC5883_REGISTER_MAG_OUT_Y_H_M = 0x07,
      HMC5883_REGISTER_MAG_OUT_Y_L_M = 0x08,
      HMC5883_REGISTER_MAG_SR_REG_Mg = 0x09,
      HMC5883_REGISTER_MAG_IRA_REG_M = 0x0A,
      HMC5883_REGISTER_MAG_IRB_REG_M = 0x0B,
      HMC5883_REGISTER_MAG_IRC_REG_M = 0x0C,
      HMC5883_REGISTER_MAG_TEMP_OUT_H_M = 0x31,
      HMC5883_REGISTER_MAG_TEMP_OUT_L_M = 0x32
    } hmc5883MagRegisters_t;
/*=========================================================================*/

/*=========================================================================
    MAGNETOMETER GAIN SETTINGS
    -----------------------------------------------------------------------*/
    typedef enum
    {
      HMC5883_MAGGAIN_1_3 = 0x20, // +/- 1.3
      HMC5883_MAGGAIN_1_9 = 0x40, // +/- 1.9
      HMC5883_MAGGAIN_2_5 = 0x60, // +/- 2.5
      HMC5883_MAGGAIN_4_0 = 0x80, // +/- 4.0
      HMC5883_MAGGAIN_4_7 = 0xA0, // +/- 4.7
      HMC5883_MAGGAIN_5_6 = 0xC0, // +/- 5.6
      HMC5883_MAGGAIN_8_1 = 0xE0 // +/- 8.1
    } hmc5883MagGain;
/*=========================================================================*/

/*=========================================================================
    INTERNAL MAGNETOMETER DATA TYPE
    -----------------------------------------------------------------------*/
    typedef struct hmc5883MagData_s
    {
        float x;
        float y;
        float z;
      float orientation;
    } hmc5883MagData;
/*=========================================================================*/

/*=========================================================================
    CHIP ID
    -----------------------------------------------------------------------*/

/*=========================================================================*/


/* Unified sensor driver for the magnetometer */
class HMC5883_Sensor : public Adafruit_Sensor
{
  public:
    HMC5883_Sensor(int32_t sensorID = -1, TwoWire * wire = __null);
    HMC5883_Sensor(TwoWire * wire);

    bool begin(void);
    void setMagGain(hmc5883MagGain gain);
    bool getEvent(sensors_event_t*);
    void getSensor(sensor_t*);

  private:
    hmc5883MagGain _magGain;
    hmc5883MagData _magData; // Last read magnetometer data will be available here
    int32_t _sensorID;
    TwoWire *_wire;

    void write8(byte address, byte reg, byte value);
    byte read8(byte address, byte reg);
    void read(void);
};
# 70 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/integrated.ino" 2
HMC5883_Sensor HMC5883_Magnetometer = HMC5883_Sensor(&Wire1);
# 80 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/integrated.ino"
# 1 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/./libs/LibTempTMP421/LibTempTMP421.h" 1
/*
  LibTemperature - A Temperature Sensor Library for Arduino.

  Supported Temperature Sensor modules:
    TMP421-Breakout Module - http://www.moderndevice.com/products/tmp421-temperature-sensor

  Created by Christopher Ladden at Modern Device on December 2009.

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




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/sam/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/arm-none-eabi/include/inttypes.h" 1 3
/*
 * Copyright (c) 2004, 2005 by
 * Ralf Corsepius, Ulm/Germany. All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software
 * is freely granted, provided that this notice is preserved.
 */

/**
 *  @file  inttypes.h
 */
# 28 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/build/sketch/./libs/LibTempTMP421/LibTempTMP421.h" 2

class LibTempTMP421
{
  private:
    uint8_t getRegisterValue(void);
    void setPtrLoc(uint8_t ptrLoc);

  public:
    LibTempTMP421();
    float GetTemperature(void);
};
# 81 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/integrated.ino" 2
LibTempTMP421 TMP421_Sensor = LibTempTMP421();


byte formatted_data_buffer[6];

// Airsense board
byte MAC_ID[6 + 2] = {0x00, 134,3,1,8,1,0,1}; // MAC address
byte TMP112[2 + 2]; // ambient temp
byte HTU21D[(2 * 2) + 2]; // ambient RH & temp
// byte GP2Y1010AU0F[LENGTH_FORMAT2 + 2]; // dust density
byte BMP180[3 + 2 + 2]; // atmospheric pressure
byte PR103J2[2 + 2]; // light
byte TSL250RD_1[2 + 2]; // ambient light (400-950nm)
byte MMA8452Q[(2 * 4) + 2]; // 3-axis accel for traffic flow
byte SPV1840LR5HB_1[2 + 2]; // sound pressure
byte TSYS01[2 + 2]; // ambient temp

// Lightsense board
byte HMC5883L[(2 * 3) + 2]; // magnetic field strength for traffic flow
byte HIH6130[(2 * 2) + 2]; // temp and RH inside transparent box
byte APDS9006020[2 + 2]; // ambient light inside cavity
byte TSL260RD[2 + 2]; // solar near IR
byte TSL250RD_2[2 + 2]; // solar visible light
byte MLX75305[2 + 2]; // solar visible light
byte ML8511[2 + 2]; // solar UV
byte D6T[(2 * 17) + 2]; // temp of surrounding objects
byte MLX90614[2 + 2]; // temp of pavement
byte TMP421[2 + 2]; // temp inside transparent box
byte SPV1840LR5HB_2[2 + 2]; // sound pressure

// chemsense board
byte total_reducing_gases[3 + 2]; // ambient concentration
byte ethanol[3 + 2]; // ambient concentration
byte nitrogen_dioxide[3 + 2]; // ambient concentration
byte ozone[3 + 2]; // ambient concentration
byte hydrogen_sulphide[3 + 2]; // ambient concentration
byte total_oxidizing_gases[3 + 2]; // ambient concentration
byte carbon_monoxide[3 + 2]; // ambient concentration
byte sulfur_dioxide[3 + 2]; // ambient concentration

byte SHT25[(2 * 2) + 2]; // ambient temp and RH
byte LPS25H[2 + 3 + 2]; // atmospheric temperature and pressure
byte Si1145[2 + 2]; // UV

byte chemsense_MAC_ID[6 + 2] = {0,0,0,0,0,0,0,0}; // MAC address of chemsense board



// Whole packet
byte packet_whole[170 + 5];
byte sensor_health[0x04 +2];
// Data sub-packet
byte packet_data[170];
// Sub-packets for each format


// These lengths are calculated at packet assembly
byte length_whole_actual;
byte length_data_actual;


unsigned char buffer [150];
unsigned char parameter[15];
unsigned char cnt = 0;
boolean chemsense_ready = 0x0;
long param_value;
unsigned char attenuate = 0;
byte valid;


byte packet_seq_number = 0x00;

float Temp_float[3];
byte Temp_byte[5];
uint16_t Temp_uint16;
long Temp_long;
int Temp_int[3];

char inByte;
char ChemSensed = 0;
char Chemsense_locked = 0;
unsigned long LOOPING;

// CRC-8
byte crc = 0x00;
byte I2C_READ_COMPLETE = 0x1;
/**************************************************************************************/
# 187 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/integrated.ino"
void ALL_SENSOR_READ ()
{

    airsense_acquire();



    lightsense_acquire();
# 203 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/integrated.ino"
        while (Serial3.available() > 0)
        {
            Serial3.read();
        }
        ChemSensed = 0;
        Chemsense_locked = 0;
        LOOPING = millis();
        while(1)
        {
            chemsense_aquire();
            if (ChemSensed == 1)
            {
                chemsense_pack();
                break;
            }

            if ( millis() - LOOPING > 3000)
            {



                ChemSensed = 0;
                break;
            }
        }



    assemble_packet_empty();
    assemble_packet_whole();
}

/** Arduino: setup ********************************************************************/
void setup()
{
    // Let us wait for the processor and the sensors to settle down
    delay(6000);
# 249 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/integrated.ino"
    Serial3.begin(115200);
    //     Setup the I2C buffer
    for (byte i=0x00; i<170 + 5; i++)
    {
        packet_whole[i] = 0x00;
    }
    assemble_packet_empty();


    Sensors_Setup();
    ALL_SENSOR_READ ();







}
/**************************************************************************************/


void loop()
{


    ALL_SENSOR_READ();
    for(int i = 0; i < packet_whole[0x02]+0x05; i++)
    {
        SerialUSB.write(packet_whole[i]);
    }
    SerialUSB.flush();
    delay(3000);
# 293 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/integrated.ino"
    delay(1);
}
# 1 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/CRC_8_Waggle.ino"
/** Calculate CRC8 ********************************************************************/
byte CRC_calc(byte length_data)
{
    byte crc = 0x00;

    for (int i = 0x03; i < (length_data + 0x03); i++) // 0x03 accounts for header
        crc = CRC_8_Waggle(packet_whole[i], crc);

    return crc;
}
/**************************************************************************************/


/** Calculate CRC, byte by byte *******************************************************/
byte CRC_8_Waggle(byte data, byte crc)
{
    byte i;

    crc ^= data;

    for (i=0x00; i < 0x08; i++)
    {
        if (crc & 0x01)
            crc = (crc >> 0x01) ^ 0x8C;
        else
            crc = crc >> 0x01;
    }

    return(crc);
}
/**************************************************************************************/
# 1 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/HIH.ino"

 void HIH_fetch_humidity_temperature()
 {
     Wire1.beginTransmission(0x27);
     Wire1.endTransmission();
     delay(100);

     Wire1.requestFrom((int)0x27, (int) 4);

     Temp_byte[1] = Wire1.read();
     Temp_byte[2] = Wire1.read();
     Temp_byte[3] = Wire1.read();
     Temp_byte[4] = Wire1.read();

     Wire1.endTransmission();

     Temp_byte[0] = (Temp_byte[1] >> 6) & 0x03;

     Temp_byte[1] = Temp_byte[1] & 0x3f;
     Temp_int[0] = (((unsigned int)Temp_byte[1]) << 8) | Temp_byte[2];

     Temp_int[1] = (((unsigned int)Temp_byte[3]) << 8) | Temp_byte[4];
     Temp_int[1] = Temp_int[1] / 4;

     Temp_float[1] = (float) Temp_int[0] * 6.10e-3;
     Temp_float[0] = (float) Temp_int[1] * 1.007e-2 - 40.0;
 }
# 1 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/TMP112.ino"






void TMP112_CONFIG()
{
    Wire1.beginTransmission(0x48); // start transmission to device
    Wire1.write(0x01); // sends register address to read from
    Wire1.write(0x60); // write data
    Wire1.write(0xB0); // write data
    Wire1.endTransmission(); // end transmission
    delay(100);
    Wire1.beginTransmission(0x48); // start transmission to device
    Wire1.write(0x01); // sends register address to read from
    Wire1.endTransmission(); // end transmission
    delay(100);
    Wire1.beginTransmission(0x48); // start transmission to device
    Wire1.requestFrom(0x48, 2);// send data n-bytes read
    Temp_byte[0] = Wire1.read(); // receive DATA
    Temp_byte[1] = Wire1.read();// receive DATA
    Wire1.endTransmission(); // end transmission
}

void TMP112_read()
{
    Wire1.beginTransmission(0x48); // start transmission to device
    Wire1.write(0x00); // sends register address to read from
    Wire1.endTransmission(); // end transmission
    delay(100);
    Wire1.beginTransmission(0x48); // start transmission to device
    Wire1.requestFrom(0x48, 2);// send data n-bytes read
    Temp_byte[0] = Wire1.read(); // receive DATA
    Temp_byte[1] = Wire1.read();// receive DATA
    Wire1.endTransmission(); // end transmission

    if ((Temp_byte[0] & 0x80) == 0x00)
    {
        // it is a positive temperature
        Temp_uint16 = Temp_byte[0];
        Temp_uint16 = Temp_uint16 << 5;
        Temp_uint16 = Temp_uint16 | (Temp_byte[1] >> 3);
        Temp_float[0] = (Temp_uint16 & 0x0FFF)*0.0625;
    }
    else
    {
        Temp_byte[0] = ~Temp_byte[0];
        Temp_byte[1] = ~Temp_byte[1];
        Temp_uint16 = Temp_byte[0];
        Temp_uint16 = Temp_uint16 << 5;
        Temp_uint16 = Temp_uint16 | (Temp_byte[1] >> 3);
        Temp_float[0] = (Temp_uint16 & 0x0FFF)*-0.0625;
    }
}
# 1 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/TSYS01.ino"


void TSYS01_CONFIG()
{
    TSYS01INIT();
    TSYS_Get_Coeff();
}

void TSYS01_read()
{
    TSYS01GetTemp();
}

void TSYS01INIT()
{
    Wire1.beginTransmission(0x76 /*address left shifted by arduino as required to match datasheet*/);
    Wire1.write(0x1E);
    Wire1.endTransmission();
    delay(50);
}


void TSYS_Get_Coeff(void) //gathers calibration coefficients to array
{
    for (uint8_t n =0; n<5;n++)
    {
        Wire1.beginTransmission(0x76 /*address left shifted by arduino as required to match datasheet*/);
        Wire1.write(0xA2+(n*2));
        Wire1.endTransmission();
        Wire1.requestFrom(0x76 /*address left shifted by arduino as required to match datasheet*/,2);
        uint8_t Ai = Wire1.read();
        uint8_t Bi = Wire1.read();
        uint16_t x = (uint16_t)Ai << 8;
        x+=Bi;
        TSYS_coefficents[n] =x;
    }
}


float TSYS_ScaleTemp_C(uint16_t rawAdc)
{

    float retVal =
    (-2)* (float)TSYS_coefficents[TSYS_K4] * (float)pow(10,-21) * pow(rawAdc,4) +
    4 * (float)TSYS_coefficents[TSYS_K3] * (float)pow(10,-16) * pow(rawAdc,3) +
    (-2) * (float)TSYS_coefficents[TSYS_K2] * (float)pow(10,-11) * pow(rawAdc,2) +
    1 * (float)TSYS_coefficents[TSYS_K1] * (float)pow(10,-6) * rawAdc +
    (-1.5) * (float)TSYS_coefficents[TSYS_K0] * (float)pow(10,-2);

    return retVal;

}

void TSYS01GetTemp()
{
    Wire1.beginTransmission(0x76 /*address left shifted by arduino as required to match datasheet*/);
    Wire1.write(0x48 /*commands sensor to begin measurement / output calculation*/); //Start measurement process
    Wire1.endTransmission();
    delay(10);

    Wire1.beginTransmission(0x76 /*address left shifted by arduino as required to match datasheet*/);
    Wire1.write(0x00 /*requests most recent output from measurement*/); //Request measurement
    Wire1.endTransmission();

    Wire1.requestFrom(0x76 /*address left shifted by arduino as required to match datasheet*/,3); //read in 24 bit output
    Temp_byte[0] = Wire1.read();
    Temp_byte[1] = Wire1.read();
    Temp_byte[2] = Wire1.read(); //not used but necessary if 24bit conversion method is found (shifts below return 24bit output / 256 per TSYS01 datasheet conversion equations

    Temp_float[0] = TSYS_ScaleTemp_C((((unsigned long)Temp_byte[0] << 8) | ((unsigned long)Temp_byte[1]))); //convert and cast to Temp with scaling equation
}
# 1 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/airsense.ino"
void airsense_acquire (void)
{






    TMP112_read();


    TMP112[0] = 0x01;
    TMP112[1] = (1 << 7) | 2;

    format6(Temp_float[0]); // Put it into format 1
    TMP112[2] = formatted_data_buffer[0];
    TMP112[3] = formatted_data_buffer[1];
# 27 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/airsense.ino"
    Temp_float[1] = myHumidity.readHumidity();
    Temp_float[0] = myHumidity.readTemperature();

    HTU21D[0] = 0x02;
    HTU21D[1] = (1 << 7) | (2 * 2);

    format6(Temp_float[0]); // Put it into format 1
    HTU21D[2] = formatted_data_buffer[0];
    HTU21D[3] = formatted_data_buffer[1];

    format6(Temp_float[1]); // Put it into format 1
    HTU21D[4] = formatted_data_buffer[0];
    HTU21D[5] = formatted_data_buffer[1];
# 54 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/airsense.ino"
    BMP180[0] = 0x04;
    bmp.getEvent(&event);
    /* Display the results (barometric pressure is measure in Pascals) */
    if (event.pressure)
    {
        BMP180[1] = (1 << 7) | (2 + 3);
        Temp_long = long(event.pressure);
        bmp.getTemperature(&Temp_float[0]);
        format6(Temp_float[0]);
        BMP180[2] = formatted_data_buffer[0];
        BMP180[3] = formatted_data_buffer[1];
        format5(Temp_long);
        BMP180[4] = formatted_data_buffer[0];
        BMP180[5] = formatted_data_buffer[1];
        BMP180[6] = formatted_data_buffer[2];

    }
    else
    {
        BMP180[1] = (0 << 7) | (2 + 3);
    }
# 88 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/airsense.ino"
    PR103J2[0] = 0x05;
    PR103J2[1] = (1 << 7) | 2;
    Temp_uint16 = analogRead(0);
    format1(Temp_uint16);
    PR103J2[2] = formatted_data_buffer[0];
    PR103J2[3] = formatted_data_buffer[1];
# 103 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/airsense.ino"
    TSL250RD_1[0] = 0x06;
    TSL250RD_1[1] = (1 << 7) | 2;

    Temp_uint16 = analogRead(1);
    format1(Temp_uint16);
    TSL250RD_1[2] = formatted_data_buffer[0];
    TSL250RD_1[3] = formatted_data_buffer[1];
# 118 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/airsense.ino"
    MMA8452_read();

    MMA8452Q[0] = 0x07;
    MMA8452Q[1] = (1 << 7) | (2 * 4);

    format6(Temp_float[0]); // Put it into format 1
    MMA8452Q[2] = formatted_data_buffer[0];
    MMA8452Q[3] = formatted_data_buffer[1];

    format6(Temp_float[1]); // Put it into format 1
    MMA8452Q[4] = formatted_data_buffer[0];
    MMA8452Q[5] = formatted_data_buffer[1];


    format6(Temp_float[2]); // Put it into format 1
    MMA8452Q[6] = formatted_data_buffer[0];
    MMA8452Q[7] = formatted_data_buffer[1];


    format6(0); // Put it into format 1
    MMA8452Q[8] = formatted_data_buffer[0];
    MMA8452Q[9] = formatted_data_buffer[1];
# 155 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/airsense.ino"
    TSYS01_read();
    TSYS01[0] = 0x09;
    TSYS01[1] = (1 << 7) | 2;
    format6(Temp_float[0]); // Put it into format 2
    TSYS01[2] = formatted_data_buffer[0];
    TSYS01[3] = formatted_data_buffer[1];
# 169 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/airsense.ino"
    long SPV_1_AMPV[100];
    double SPV_1_AMPV_AVG = 0;

    for(int i = 0; i < 100; i++)
    {
        SPV_1_AMPV[i] = 512 - analogRead(5);
        if (SPV_1_AMPV[i] < 0)
        {
            SPV_1_AMPV[i] = SPV_1_AMPV[i] * -1;
        }
        delay(1);
    }

    for(int i = 0; i < 100; i++)
    {
        SPV_1_AMPV_AVG = ((SPV_1_AMPV_AVG * i) + SPV_1_AMPV[i]) / (i+1);
    }

    SPV1840LR5HB_1[0] = 0x08;
    SPV1840LR5HB_1[1] = (1 << 7) | 2;

    format1(int(SPV_1_AMPV_AVG * 10));

    SPV1840LR5HB_1[2] = formatted_data_buffer[0];
    SPV1840LR5HB_1[3] = formatted_data_buffer[1];
# 202 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/airsense.ino"
}
# 1 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/chemsense.ino"
void chemsense_parse_value (byte pidx)
{
    param_value = 0;
    for (byte idx = 0; idx < pidx; idx ++)
    {
        if (parameter[idx] != 0x2d)
        {
            parameter[idx] = parameter[idx] - 48;
            param_value = (param_value * 10) + parameter[idx];
        }
    }

    if (parameter[0] == 0x2d)
    {
        param_value = param_value * (-1);
    }
//     SerialUSB.println(param_value);
    return;
}

void chemsense_aquire (void)
{

//     let us acquire a line of chemsense data
    while (Serial3.available())
    {
        // every line of data terminates with a newline and carriage return char, lock to the carriage return,
        // parse the next line in full, until the newline char is encountered

        //read a byte of data from serial buffer
        inByte = Serial3.read();

        //check if we have locked to carriage return - end of previous line.
        if (inByte == '\r')
        {
            cnt = 0;
            Chemsense_locked = 1;
        }

        //given that we are locked in, let us proceed to fill the
        //char buffer with ASCIIs we are receiving
        if (Chemsense_locked == 1)
        {
            // we have seen a newline char, a complete line of data has been acquired
            if (inByte == '\n')
            {
                cnt = cnt + 1;
                ChemSensed = 1;
                chemsense_ready = 0x1;
            }
            //not a newline char, continue to fill the buffer
            else
            {
                //fill the buffer only if the data received by serial is under the allocated buffer length
                if ( cnt < 150 )
                {
                    buffer[cnt] = inByte;
                    cnt = cnt + 1;
                }
            }
        }
    }
    return;
}

// Chemsense line output -
// 72f1addaffff,25600,29720,6644,1563,-25510,23,4103258,-1238233,-123432,8388606,-58790,-1495769,2432,5739770,-271490
// 72f1addaffff,25600,29720,6644,1563,-25510,23,4103258,-1224139,-151913,8388606,-58558,-1514697,2425,5741330,-270681
// 0   MAC - 6 Bytes
// 1   HDC_Temp - Ignore
// 2   HDC_RH - Ignore
// 3   SHT_Temp - 2 Bytes (15 bits + sign) (14 bits raw, encoded as is)
// 4   SHT_RH - 2 Bytes (15 bits + sign) (12 bits raw, encoded as is)
// 5   LPS_Temp - 2 Bytes (15 bits + sign) (16 bits raw, encoded after right shifting by 1)
// 6   UV - 2 Bytes (16 bits) (16 bits raw, encoded as is)
// 7   Pressure - 3 Bytes (24 bits) (24 bits raw, encoded as is)
// 8   H2S - 3 Bytes (23 bits + sign) (The AFE produces 23 bits precision output + sign bit)
// 9   O3 - 3 Bytes (23 bits + sign) (The AFE produces 23 bits precision output + sign bit)
// 10  NO2 - 3 Bytes (23 bits + sign) (The AFE produces 23 bits precision output + sign bit)
// 11  CO - 3 Bytes (23 bits + sign) (The AFE produces 23 bits precision output + sign bit)
// 12  SO2 - 3 Bytes (23 bits + sign) (The AFE produces 23 bits precision output + sign bit)
// 13  TotalOX - 3 Bytes (23 bits + sign) (The AFE produces 23 bits precision output + sign bit)
// 14  TotalRed - 3 Bytes (23 bits + sign) (The AFE produces 23 bits precision output + sign bit)
// 15  ETOH - 3 Bytes (23 bits + sign) (The AFE produces 23 bits precision output + sign bit)

void chemsense_pack (void)
{
    // if there is data to be packed, acquired earlier using chemsense acquire, then
    // let us pack the data
    if (chemsense_ready == 0x1)
    {
        chemsense_ready = 0x0;

        byte count = 0, pidx = 0;

        for (byte index = 0; index < cnt; index ++)
        {
            // Tokenize the buffer with ',' as the delimiter, count the number of
            // tokens (count variable) and the length of the MACID field, also
            // grab the MAC ID field from buffer

            if (buffer[index] != ',')
            {
                if ((count == 0) && (pidx < 15))
                {
                    pidx = pidx + 1;
                }
            }
            else
            {
                count = count + 1;
            }
        }

        // check if a valid line of data was acquired.

        if ((count == 15) && (pidx == 13))
        {
            byte count = 0, pidx = 0;
            // parse the valid line of data
            for (byte index = 0 + 1; index < cnt; index ++)
            {

                // segregate every token, one by one.
                if ((buffer[index] != ',') && (pidx < 15))
                {
                    parameter[pidx] = buffer[index];
                    pidx = pidx + 1;
                }

                // a token has been segregated as the next char is the delimiter ','
                else
                {

                    if (count == 0)
                    {

                        // chemsense MAC address (format 3)
                        valid = 1;
                        chemsense_MAC_ID[0] = 0x20;
                        chemsense_MAC_ID[1] = (valid << 7) | 6;
                        for (byte idx = 0; idx < pidx; idx ++)
                        {
                            if ((parameter[idx] > 96) && (parameter[idx] < 103))
                            {
                                parameter[idx] = parameter[idx] - 87;
                            }
                            else
                            {
                                parameter[idx] = parameter[idx] - 48;
                            }

                            if (idx % 2 == 0)
                            {
                                parameter[idx] = parameter[idx] << 4;
                            }
                            chemsense_MAC_ID[(idx/2)+2] = chemsense_MAC_ID[(idx/2)+2] | parameter[idx];
                        }
# 167 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/chemsense.ino"
                    }


                    else if (count == 3)
                    {

                        valid = 1;
                        chemsense_parse_value(pidx);
                        format2(int(param_value));
                        SHT25[0] = 0x1D;
                        SHT25[1] = (valid << 7) | ((2) * 2);
                        SHT25[2] = formatted_data_buffer[0];
                        SHT25[3] = formatted_data_buffer[1];





                    }
                    else if (count == 4)
                    {
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format2(int(param_value));
                        SHT25[0] = 0x1D;
                        SHT25[1] = (valid << 7) | ((2) * 2);
                        SHT25[4] = formatted_data_buffer[0];
                        SHT25[5] = formatted_data_buffer[1];




                    }



                    else if (count == 5)
                    {
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format2(int(param_value) >> 1); // have to check if this is needed.
                        LPS25H[0] = 0x1E;
                        LPS25H[1] = (valid << 7) | (2 + 3);
                        LPS25H[2] = formatted_data_buffer[0];
                        LPS25H[3] = formatted_data_buffer[1];




                    }

                   else if (count == 7)
                   {
                       valid = 1;
                       chemsense_parse_value(pidx);
                       format4(long(param_value));
                       LPS25H[0] = 0x1E;
                       LPS25H[1] = (valid << 7) | (2 + 3);
                       LPS25H[4] = formatted_data_buffer[0];
                       LPS25H[5] = formatted_data_buffer[1];
                       LPS25H[6] = formatted_data_buffer[2];





                   }



                    else if (count == 6)
                    {
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format1(int(param_value));
                        Si1145[0] = 0x1F;
                        Si1145[1] = (valid << 7) | (2);
                        Si1145[2] = formatted_data_buffer[0];
                        Si1145[3] = formatted_data_buffer[1];




                    }



                    else if (count == 8)
                    {
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format5(long(param_value));
                        hydrogen_sulphide[0] = 0x19;
                        hydrogen_sulphide[1] = (valid << 7) | (3);
                        hydrogen_sulphide[2] = formatted_data_buffer[0];
                        hydrogen_sulphide[3] = formatted_data_buffer[1];
                        hydrogen_sulphide[4] = formatted_data_buffer[2];




                    }



                    else if (count == 9)
                    {

                        valid = 1;
                        chemsense_parse_value(pidx);
                        format5(long(param_value));
                        ozone[0] = 0x18;
                        ozone[1] = (valid << 7) | (3);
                        ozone[2] = formatted_data_buffer[0];
                        ozone[3] = formatted_data_buffer[1];
                        ozone[4] = formatted_data_buffer[2];




                    }



                    else if (count == 10)
                    {
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format5(long(param_value));
                        nitrogen_dioxide[0] = 0x17;
                        nitrogen_dioxide[1] = (valid << 7) | (3);
                        nitrogen_dioxide[2] = formatted_data_buffer[0];
                        nitrogen_dioxide[3] = formatted_data_buffer[1];
                        nitrogen_dioxide[4] = formatted_data_buffer[2];




                    }



                    else if (count == 11)
                    {
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format5(long(param_value));
                        carbon_monoxide[0] = 0x1B;
                        carbon_monoxide[1] = (valid << 7) | (3);
                        carbon_monoxide[2] = formatted_data_buffer[0];
                        carbon_monoxide[3] = formatted_data_buffer[1];
                        carbon_monoxide[4] = formatted_data_buffer[2];




                    }



                    else if (count == 12)
                    {
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format5(long(param_value));
                        sulfur_dioxide[0] = 0x1C;
                        sulfur_dioxide[1] = (valid << 7) | (3);
                        sulfur_dioxide[2] = formatted_data_buffer[0];
                        sulfur_dioxide[3] = formatted_data_buffer[1];
                        sulfur_dioxide[4] = formatted_data_buffer[2];




                    }



                    else if (count == 13)
                    {
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format5(long(param_value));
                        total_oxidizing_gases[0] = 0x1A;
                        total_oxidizing_gases[1] = (valid << 7) | (3);
                        total_oxidizing_gases[2] = formatted_data_buffer[0];
                        total_oxidizing_gases[3] = formatted_data_buffer[1];
                        total_oxidizing_gases[4] = formatted_data_buffer[2];




                    }



                    else if (count == 14)
                    {
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format5(long(param_value));
                        total_reducing_gases[0] = 0x15;
                        total_reducing_gases[1] = (valid << 7) | (3);
                        total_reducing_gases[2] = formatted_data_buffer[0];
                        total_reducing_gases[3] = formatted_data_buffer[1];
                        total_reducing_gases[4] = formatted_data_buffer[2];




                    }


                    count = count + 1;
                    pidx = 0;
                }
            }


            valid = 1;
            chemsense_parse_value(pidx-1);
            format5(long(param_value));
            ethanol[0] = 0x16;
            ethanol[1] = (valid << 7) | (3);
            ethanol[2] = formatted_data_buffer[0];
            ethanol[3] = formatted_data_buffer[1];
            ethanol[4] = formatted_data_buffer[2];





        }
        cnt = 0;
        ChemSensed = 1;
    }
}
# 1 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/dataFormats.ino"
// Packet formatters -
// F1 - unsigned int_16 input, {0-0xffff} - Byte1 Byte2 (16 bit number)
// F2 - int_16 input , +-{0-0x7fff} - 1S|7Bits Byte2
// F3 - byte input[6], {0-0xffffffffffff} - Byte1 Byte2 Byte3 Byte4 Byte5 Byte6
// F4 - unsigned long_24 input, {0-0xffffff} - Byte1 Byte2 Byte3
// F5 - long_24 input, +-{0-0x7fffff} - 1S|7Bits Byte2 Byte3
// F6 - float input, +-{0-127}.{0-99} - 1S|7Bit_Int 0|7Bit_Frac{0-99}
// F7 - byte input[4], {0-0xffffffff} - Byte1 Byte2 Byte3 Byte4
// F8 - float input, +-{0-31}.{0-999} - 1S|5Bit_Int|2MSBit_Frac  8LSBits_Frac


/** Format 1 assembler ****************************************************************/
// F1 - {0-0xffff} - Byte1 Byte2 (16 bit number)
void format1(unsigned int input)
{
    // Assemble sub-packet
    formatted_data_buffer[0] = (input & 0xff00) >> 8;
    formatted_data_buffer[1] = input & 0xff;
}
/**************************************************************************************/



/** Format 2 assembler ****************************************************************/
// F2 - +-{0-0x7fff} - 1S|7Bits Byte2
void format2(int input)
{

    byte _negative;
    // Input negative?
    if (input < 0) {
        _negative = 1;
    }
    else {
        _negative = 0;
    }
    // Get abs. value of input
    input = ((input)>0?(input):-(input));
    // Assemble sub-packet
    formatted_data_buffer[0] = (_negative << 7) | ((input & 0x7f00) >> 8);
    formatted_data_buffer[1] = input & 0xff;
}
/**************************************************************************************/


/** Format 3 assembler ****************************************************************/
// F3 - {0-0xffffffffffff} - Byte1 Byte2 Byte3 Byte4 Byte5 Byte6
void format3(byte *input)
{
    // Assemble sub-packet
    formatted_data_buffer[0] = input[0];
    formatted_data_buffer[1] = input[1];
    formatted_data_buffer[2] = input[2];
    formatted_data_buffer[3] = input[3];
    formatted_data_buffer[4] = input[4];
    formatted_data_buffer[5] = input[5];
}
/**************************************************************************************/

/** Format 4 assembler ****************************************************************/
// F4 - {0-0xffffff} - Byte1 Byte2 Byte3
void format4(unsigned long input)
{
    // Assemble sub-packet
    formatted_data_buffer[0] = (input & 0xff0000) >> 16;
    formatted_data_buffer[1] = (input & 0xff00) >> 8;
    formatted_data_buffer[2] = (input & 0xff);
}
/**************************************************************************************/



/** Format 5 assembler ****************************************************************/
// F5 - +-{0-0x7fffff} - 1S|7Bits Byte2 Byte3
void format5(long input)
{
    // Flag to store pos/neg info
    byte _negative;

    // Input negative?
    if (input < 0) {
        _negative = 1;
    }
    else {
        _negative = 0;
    }

    // Get abs. value of input
    input = ((input)>0?(input):-(input));
    // Assemble sub-packet
    formatted_data_buffer[0] = (_negative << 7) | ((input & 0x7f0000) >> 16);
    formatted_data_buffer[1] = (input & 0xff00) >> 8;
    formatted_data_buffer[2] = (input & 0xff);
}
/**************************************************************************************/


/** Format 6 assembler ****************************************************************/
// F6 - +-{0-127}.{0-99} - 1S|7Bit_Int 0|7Bit_Frac{0-99}

void format6(float input)
{
    // Flag to store pos/neg info
    byte _negative;

    // Input negative?
    if (input < 0) {
        _negative = 1;
    }
    else {
        _negative = 0;
    }

    // Get abs. value of input
    input = ((input)>0?(input):-(input));
    // Extract integer component
    unsigned int integer = (int)input;
    // Extract fractional component (and turn it into an integer)
    unsigned int fractional = ((int)(input*100) - integer*100);

    // Assemble sub-packet
    formatted_data_buffer[0] = (_negative << 7) | integer;
    formatted_data_buffer[1] = (fractional & 0x7F);
}
/**************************************************************************************/

/** Format 7 assembler ****************************************************************/
// F7 - {0-0xffffffff} - Byte1 Byte2 Byte3 Byte4
void format7(byte *input)
{
    // Assemble sub-packet
    formatted_data_buffer[0] = input[0];
    formatted_data_buffer[1] = input[1];
    formatted_data_buffer[2] = input[2];
    formatted_data_buffer[3] = input[3];
}
/**************************************************************************************/

/** Format 8 assembler ****************************************************************/
// F8 - +-{0-31}.{0-999} - 1S|5Bit_Int|2MSBit_Frac  8LSBits_Frac
void format8(float input)
{
    // Flag to store pos/neg info
    byte _negative;

    // Input negative?
    if (input < 0) {
        _negative = 1;
    }
    else {
        _negative = 0;
    }

    // Get abs. value of input
    input = ((input)>0?(input):-(input));
    // Extract integer component
    int integer = (int)input;
    // Extract fractional component (and turn it into an integer)
    int fractional = int((input - integer) * 1000);

    // Assemble sub-packet
    formatted_data_buffer[0] = (_negative << 7) | ((integer & 0x1F) << 2) | ((fractional & 0x0300) >> 8);
    formatted_data_buffer[1] = (fractional & 0x00FF);;
}
/**************************************************************************************/
# 1 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/lightsense.ino"
void lightsense_acquire (void)
{






    HIH_fetch_humidity_temperature();
    HIH6130[0] = 0x0B;
    HIH6130[1] = (1 << 7) | (2 * 2);
    format6(Temp_float[0]);
    HIH6130[2] = formatted_data_buffer[0];
    HIH6130[3] = formatted_data_buffer[1];
    format6(Temp_float[1]);
    HIH6130[4] = formatted_data_buffer[0];
    HIH6130[5] = formatted_data_buffer[1];
# 27 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/lightsense.ino"
    sensors_event_t event;
    HMC5883_Magnetometer.getEvent(&event);


    HMC5883L[0] = 0x0A;
    HMC5883L[1] = (1 << 7) | (2 * 3);
    format8(event.magnetic.x);
    HMC5883L[2] = formatted_data_buffer[0];
    HMC5883L[3] = formatted_data_buffer[1];
    format8(event.magnetic.y);
    HMC5883L[4] = formatted_data_buffer[0];
    HMC5883L[5] = formatted_data_buffer[1];
    format8(event.magnetic.z);
    HMC5883L[6] = formatted_data_buffer[0];
    HMC5883L[7] = formatted_data_buffer[1];
# 55 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/lightsense.ino"
    Temp_float[0] = TMP421_Sensor.GetTemperature();
    TMP421[0] = 0x13;
    TMP421[1] = (1 << 7) | 2;
    format6(Temp_float[0]);
    TMP421[2] = formatted_data_buffer[0];
    TMP421[3] = formatted_data_buffer[1];







    mcp3428_2.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
    format1(mcp3428_2.readADC());
    APDS9006020[0] = 0x0C;
    APDS9006020[1] = (valid << 7) | 2;
    APDS9006020[2] = formatted_data_buffer[0];
    APDS9006020[3] = formatted_data_buffer[1];







    mcp3428_1.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
    format1(mcp3428_1.readADC());
    TSL260RD[0] = 0x0D;
    TSL260RD[1] = (1 << 7) | 2;
    TSL260RD[2] = formatted_data_buffer[0];
    TSL260RD[3] = formatted_data_buffer[1];







    mcp3428_1.selectChannel(MCP342X::CHANNEL_3, MCP342X::GAIN_1);
    format1(mcp3428_1.readADC());
    TSL250RD_2[0] = 0x0E;
    TSL250RD_2[1] = (1 << 7) | 2;
    TSL250RD_2[2] = formatted_data_buffer[0];
    TSL250RD_2[3] = formatted_data_buffer[1];







    mcp3428_1.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
    format1(mcp3428_1.readADC());
    MLX75305[0] = 0x0F;
    MLX75305[1] = (1 << 7) | 2;
    MLX75305[2] = formatted_data_buffer[0];
    MLX75305[3] = formatted_data_buffer[1];







    mcp3428_1.selectChannel(MCP342X::CHANNEL_2, MCP342X::GAIN_1);
    format1(mcp3428_1.readADC());
    ML8511[0] = 0x10;
    ML8511[1] = (valid << 7) | 2;
    ML8511[2] = formatted_data_buffer[0];
    ML8511[3] = formatted_data_buffer[1];







    mcp3428_2.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
    format1(mcp3428_2.readADC());
    SPV1840LR5HB_2[0] = 0x14;
    SPV1840LR5HB_2[1] = (1 << 7) | 2;
    SPV1840LR5HB_2[2] = formatted_data_buffer[0];
    SPV1840LR5HB_2[3] = formatted_data_buffer[1];






}
# 1 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/mma84521.ino"


void MMA8452_read()
{
    readAccelData(Temp_int);

    for (int i = 0 ; i < 3 ; i++)
    {
        Temp_float[i] = (float) Temp_int[i] / ((1<<12)/(2*2 /* Sets full-scale range to +/-2, 4, or 8g. Used to calc real g values.*/)); // get actual g value, this depends on scale being set
    }

}

void readAccelData(int *destination)
{
    byte rawData[6]; // x/y/z accel register data stored here

    MMA8452readRegisters(0x01, 6, rawData); // Read the six raw data registers into data array

    // Loop to calculate 12-bit ADC and g value for each axis
    for(int i = 0; i < 3 ; i++)
    {
        int gCount = (rawData[i*2] << 8) | rawData[(i*2)+1]; //Combine the two 8 bit registers into one 12-bit number
        gCount >>= 4; //The registers are left align, here we right align the 12-bit integer

        // If the number is negative, we have to make it so manually (no 12-bit data type)
        if (rawData[i*2] > 0x7F)
        {
            gCount -= 0x1000;
        }

        destination[i] = gCount; //Record this gCount into the 3 int array
    }
}

// Initialize the MMA8452 registers
// See the many application notes for more info on setting all of these registers:
// http://www.freescale.com/webapp/sps/site/prod_summary.jsp?code=MMA8452Q
void MMA8452_CONFIG()
{
    MMA8452Standby(); // Must be in standby to change registers
    // Set up the full scale range to 2, 4, or 8g.
    byte fsr = 2 /* Sets full-scale range to +/-2, 4, or 8g. Used to calc real g values.*/;
    if(fsr > 8) fsr = 8; //Easy error check
    fsr >>= 2; // Neat trick, see page 22. 00 = 2G, 01 = 4A, 10 = 8G
    MMA8452writeRegister(0x0E, fsr);
    //The default data rate is 800Hz and we don't modify it in this example code
    MMA8452Active(); // Set to active to start reading
}

// Sets the MMA8452 to standby mode. It must be in standby to change most register settings
void MMA8452Standby()
{
    byte c = MMA8452readRegister(0x2A);
    MMA8452writeRegister(0x2A, c & ~(0x01)); //Clear the active bit to go into standby
}

// Sets the MMA8452 to active mode. Needs to be in this mode to output data
void MMA8452Active()
{
    byte c = MMA8452readRegister(0x2A);
    MMA8452writeRegister(0x2A, c | 0x01); //Set the active bit to begin detection
}

// Read bytesToRead sequentially, starting at addressToRead into the dest byte array
void MMA8452readRegisters(byte addressToRead, int bytesToRead, byte * dest)
{
    Wire1.requestFrom((uint8_t) 0x1C, (uint8_t) bytesToRead, (uint32_t) addressToRead, (uint8_t) 1);
    while(Wire1.available() < bytesToRead); //Hang out until we get the # of bytes we expect
    for(int x = 0 ; x < bytesToRead ; x++)
        dest[x] = Wire1.read();
}

// Read a single byte from addressToRead and return it as a byte
byte MMA8452readRegister(byte addressToRead)
{
    Wire1.requestFrom((uint8_t) 0x1C, (uint8_t) 1, (uint32_t) addressToRead, (uint8_t) 1);
    while(!Wire1.available()) ; //Wait for the data to come back
    return Wire1.read(); //Return this one byte
}

// Writes a single byte (dataToWrite) into addressToWrite
void MMA8452writeRegister(byte addressToWrite, byte dataToWrite)
{
    Wire1.beginTransmission(0x1C);
    Wire1.write(addressToWrite);
    Wire1.write(dataToWrite);
    Wire1.endTransmission(); //Stop transmitting
}
# 1 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/packet_assembler.ino"
/** Assemble empty packet *************************************************************/
void assemble_packet_empty()
{
    packet_whole[0x00] = 0xAA;
    packet_whole[0x01] = ((packet_seq_number & 0x0f) << 4) | 0x00 /* Lower nibble*/;
    packet_whole[0x02] = 0x00;
    packet_whole[0x03] = 0x00;
    packet_whole[0x04] = 0x55;
}
/**************************************************************************************/


/** Assemble whole packet *************************************************************/
void assemble_packet_whole()
{
    int packet_whole_index = 3; // start at 3 to account for header




    // Append MAC_ID
    for (int i = 0; i < sizeof(MAC_ID); i++)
    {
        packet_whole[packet_whole_index] = MAC_ID[i];
        // Increment index for whole packet
        packet_whole_index++;
    }



    // Append TMP112
    for (int i = 0; i < sizeof(TMP112); i++)
    {
        packet_whole[packet_whole_index] = TMP112[i];
        // Increment index for whole packet
        packet_whole_index++;
    }



    // Append HTU21D
    for (int i = 0; i < sizeof(HTU21D); i++)
    {
        packet_whole[packet_whole_index] = HTU21D[i];

        // Increment index for whole packet
        packet_whole_index++;
    }
# 64 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/packet_assembler.ino"
    // Append BMP180
    for (int i = 0; i < sizeof(BMP180); i++)
    {
        packet_whole[packet_whole_index] = BMP180[i];

        // Increment index for whole packet
        packet_whole_index++;
    }



    // Append PR103J2
    for (int i = 0; i < sizeof(PR103J2); i++)
    {
        packet_whole[packet_whole_index] = PR103J2[i];

        // Increment index for whole packet
        packet_whole_index++;
    }



    // Append TSL250RD_1
    for (int i = 0; i < sizeof(TSL250RD_1); i++)
    {
        packet_whole[packet_whole_index] = TSL250RD_1[i];

        // Increment index for whole packet
        packet_whole_index++;
    }



    // Append MMA8452Q
    for (int i = 0; i < sizeof(MMA8452Q); i++)
    {
        packet_whole[packet_whole_index] = MMA8452Q[i];

        // Increment index for whole packet
        packet_whole_index++;
    }



    // Append SPV1840LR5HB_1
    for (int i = 0; i < sizeof(SPV1840LR5HB_1); i++)
    {
        packet_whole[packet_whole_index] = SPV1840LR5HB_1[i];

        // Increment index for whole packet
        packet_whole_index++;
    }



    // Append TSYS01
    for (int i = 0; i < sizeof(TSYS01); i++)
    {
        packet_whole[packet_whole_index] = TSYS01[i];

        // Increment index for whole packet
        packet_whole_index++;
    }



    // Append HMC5883L
    for (int i = 0; i < sizeof(HMC5883L); i++)
    {
        packet_whole[packet_whole_index] = HMC5883L[i];

        // Increment index for whole packet
        packet_whole_index++;
    }



    // Append HIH6130
    for (int i = 0; i < sizeof(HIH6130); i++)
    {
        packet_whole[packet_whole_index] = HIH6130[i];

        // Increment index for whole packet
        packet_whole_index++;
    }



    // Append APDS9006020
    for (int i = 0; i < sizeof(APDS9006020); i++)
    {
        packet_whole[packet_whole_index] = APDS9006020[i];

        // Increment index for whole packet
        packet_whole_index++;
    }



    // Append TSL260RD
    for (int i = 0; i < sizeof(TSL260RD); i++)
    {
        packet_whole[packet_whole_index] = TSL260RD[i];

        // Increment index for whole packet
        packet_whole_index++;
    }



    // Append TSL250RD_2
    for (int i = 0; i < sizeof(TSL250RD_2); i++)
    {
        packet_whole[packet_whole_index] = TSL250RD_2[i];

        // Increment index for whole packet
        packet_whole_index++;
    }



    // Append MLX75305
    for (int i = 0; i < sizeof(MLX75305); i++)
    {
        packet_whole[packet_whole_index] = MLX75305[i];

        // Increment index for whole packet
        packet_whole_index++;
    }



    // Append ML8511
    for (int i = 0; i < sizeof(ML8511); i++)
    {
        packet_whole[packet_whole_index] = ML8511[i];

        // Increment index for whole packet
        packet_whole_index++;
    }
# 229 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/packet_assembler.ino"
    // Append TMP421
    for (int i = 0; i < sizeof(TMP421); i++)
    {
        packet_whole[packet_whole_index] = TMP421[i];

        // Increment index for whole packet
        packet_whole_index++;
    }



    // Append SPV1840LR5HB_2
    for (int i = 0; i < sizeof(SPV1840LR5HB_2); i++)
    {
        packet_whole[packet_whole_index] = SPV1840LR5HB_2[i];

        // Increment index for whole packet
        packet_whole_index++;
    }



    if (ChemSensed == 1)
    {


        // Append total_reducing_gases



        for (int i = 0; i < sizeof(total_reducing_gases); i++)
        {
            packet_whole[packet_whole_index] = total_reducing_gases[i];
            // Increment index for whole packet
            packet_whole_index++;
        }




        // Append ethanol



        for (int i = 0; i < sizeof(ethanol); i++)
        {
            packet_whole[packet_whole_index] = ethanol[i];

            // Increment index for whole packet
            packet_whole_index++;
        }



        // Append nitrogen_dioxide



        for (int i = 0; i < sizeof(nitrogen_dioxide); i++)
        {
            packet_whole[packet_whole_index] = nitrogen_dioxide[i];

            // Increment index for whole packet
            packet_whole_index++;
        }



        // Append ozone



        for (int i = 0; i < sizeof(ozone); i++)
        {
            packet_whole[packet_whole_index] = ozone[i];

            // Increment index for whole packet
            packet_whole_index++;
        }



        // Append hydrogen_sulphide



        for (int i = 0; i < sizeof(hydrogen_sulphide); i++)
        {
            packet_whole[packet_whole_index] = hydrogen_sulphide[i];

            // Increment index for whole packet
            packet_whole_index++;
        }



        // Append total_oxidizing_gases



        for (int i = 0; i < sizeof(total_oxidizing_gases); i++)
        {
            packet_whole[packet_whole_index] = total_oxidizing_gases[i];

            // Increment index for whole packet
            packet_whole_index++;
        }



        // Append carbon_monoxide



        for (int i = 0; i < sizeof(carbon_monoxide); i++)
        {
            packet_whole[packet_whole_index] = carbon_monoxide[i];

            // Increment index for whole packet
            packet_whole_index++;
        }



        // Append sulfur_dioxide



        for (int i = 0; i < sizeof(sulfur_dioxide); i++)
        {
            packet_whole[packet_whole_index] = sulfur_dioxide[i];

            // Increment index for whole packet
            packet_whole_index++;
        }



        // Append sensirion



        for (int i = 0; i < sizeof(SHT25); i++)
        {
            packet_whole[packet_whole_index] = SHT25[i];

            // Increment index for whole packet
            packet_whole_index++;
        }



        // Append LPS25H



        for (int i = 0; i < sizeof(LPS25H); i++)
        {
            packet_whole[packet_whole_index] = LPS25H[i];

            // Increment index for whole packet
            packet_whole_index++;
        }




        // Append Si1145



        for (int i = 0; i < sizeof(Si1145); i++)
        {
            packet_whole[packet_whole_index] = Si1145[i];

            // Increment index for whole packet
            packet_whole_index++;
        }




        // Append chemsense_MAC_ID
        for (int i = 0; i < sizeof(chemsense_MAC_ID); i++)
        {
            packet_whole[packet_whole_index] = chemsense_MAC_ID[i];

            // Increment index for whole packet
            packet_whole_index++;
        }


    }
# 434 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/packet_assembler.ino"
    // Length
    packet_whole[0x02] = packet_whole_index - 0x03;
    packet_seq_number++;
    packet_whole[0x01] = ((packet_seq_number & 0x0f) << 4) | 0x00 /* Lower nibble*/;

    // Append CRC8
    packet_whole[packet_whole_index] = CRC_calc(packet_whole_index - 0x03);
    packet_whole[++packet_whole_index] = 0x55;




}
/**************************************************************************************/
# 1 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/sensors_setup.ino"
void Sensors_Setup(void)
{
# 14 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/sensors_setup.ino"
TMP112_CONFIG();
# 31 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/sensors_setup.ino"
bmp.begin();
# 52 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/sensors_setup.ino"
MMA8452_CONFIG(); //Test and intialize the MMA8452







TSYS01_CONFIG();
# 118 "/media/rajesh/Bharadwaja/github/waggle/sensors/sensorcluster/integrated/sensors_setup.ino"
mcp3428_1.init(MCP342X::L, MCP342X::L);
mcp3428_2.init(MCP342X::L, MCP342X::F);



HMC5883_Magnetometer.begin();

return;
}
