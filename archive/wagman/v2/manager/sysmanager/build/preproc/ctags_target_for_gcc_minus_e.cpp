# 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/build/sketch/sysmanager.ino.cpp"
# 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager//"
# 1 "<command-line>"
# 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/build/sketch/sysmanager.ino.cpp"
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Arduino.h" 1
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




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/stdlib.h" 1 3
/* Copyright (c) 2002, Marek Michalkiewicz
   Copyright (c) 2004,2007 Joerg Wunsch

   Portions of documentation Copyright (c) 1990, 1991, 1993, 1994
   The Regents of the University of California.

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

  $Id$
*/
# 47 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/stdlib.h" 3
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
# 279 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stddef.h" 3 4
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
# 306 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stddef.h" 3 4
/* FreeBSD 5 can't be handled well using "traditional" logic above
   since it no longer defines _BSD_RUNE_T_ yet still desires to export
   rune_t in some cases... */
# 358 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stddef.h" 3 4
/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
    are already defined.  */
/*  BSD/OS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
# 394 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stddef.h" 3 4
/* A null pointer constant.  */
# 48 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/stdlib.h" 2 3






extern "C" {


/** \file */

/** \defgroup avr_stdlib <stdlib.h>: General utilities
    \code #include <stdlib.h> \endcode

    This file declares some basic C macros and functions as
    defined by the ISO standard, plus some AVR-specific extensions.
*/

/*@{*/
/** Result type for function div(). */
typedef struct {
 int quot; /**< The Quotient. */
 int rem; /**< The Remainder. */
} div_t;

/** Result type for function ldiv(). */
typedef struct {
 long quot; /**< The Quotient. */
 long rem; /**< The Remainder. */
} ldiv_t;

/** Comparision function type for qsort(), just for convenience. */
typedef int (*__compar_fn_t)(const void *, const void *);
# 110 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/stdlib.h" 3
/** The abort() function causes abnormal program termination to occur.
    This realization disables interrupts and jumps to _exit() function
    with argument equal to 1. In the limited AVR environment, execution is
    effectively halted by entering an infinite loop. */
extern void abort(void) __attribute__((__noreturn__));

/** The abs() function computes the absolute value of the integer \c i.
   \note The abs() and labs() functions are builtins of gcc.
*/
extern int abs(int __i) __attribute__((__const__));




/** The labs() function computes the absolute value of the long integer
    \c i.
   \note The abs() and labs() functions are builtins of gcc.
*/
extern long labs(long __i) __attribute__((__const__));




/**
     The bsearch() function searches an array of \c nmemb objects, the
     initial member of which is pointed to by \c base, for a member
     that matches the object pointed to by \c key.  The size of each
     member of the array is specified by \c size.

     The contents of the array should be in ascending sorted order
     according to the comparison function referenced by \c compar.
     The \c compar routine is expected to have two arguments which
     point to the key object and to an array member, in that order,
     and should return an integer less than, equal to, or greater than
     zero if the key object is found, respectively, to be less than,
     to match, or be greater than the array member.

     The bsearch() function returns a pointer to a matching member of
     the array, or a null pointer if no match is found.  If two
     members compare as equal, which member is matched is unspecified.
*/
extern void *bsearch(const void *__key, const void *__base, size_t __nmemb,
       size_t __size, int (*__compar)(const void *, const void *));

/* __divmodhi4 and __divmodsi4 from libgcc.a */
/**
     The div() function computes the value \c num/denom and returns
     the quotient and remainder in a structure named \c div_t that
     contains two int members named \c quot and \c rem.
*/
extern div_t div(int __num, int __denom) __asm__("__divmodhi4") __attribute__((__const__));
/**
     The ldiv() function computes the value \c num/denom and returns
     the quotient and remainder in a structure named \c ldiv_t that
     contains two long integer members named \c quot and \c rem.
*/
extern ldiv_t ldiv(long __num, long __denom) __asm__("__divmodsi4") __attribute__((__const__));

/**
     The qsort() function is a modified partition-exchange sort, or
     quicksort.

     The qsort() function sorts an array of \c nmemb objects, the
     initial member of which is pointed to by \c base.  The size of
     each object is specified by \c size.  The contents of the array
     base are sorted in ascending order according to a comparison
     function pointed to by \c compar, which requires two arguments
     pointing to the objects being compared.

     The comparison function must return an integer less than, equal
     to, or greater than zero if the first argument is considered to
     be respectively less than, equal to, or greater than the second.
*/
extern void qsort(void *__base, size_t __nmemb, size_t __size,
    __compar_fn_t __compar);

/**
    The strtol() function converts the string in \c nptr to a long
    value.  The conversion is done according to the given base, which
    must be between 2 and 36 inclusive, or be the special value 0.

    The string may begin with an arbitrary amount of white space (as
    determined by isspace()) followed by a single optional \c '+' or \c '-'
    sign.  If \c base is zero or 16, the string may then include a
    \c "0x" prefix, and the number will be read in base 16; otherwise,
    a zero base is taken as 10 (decimal) unless the next character is
    \c '0', in which case it is taken as 8 (octal).

    The remainder of the string is converted to a long value in the
    obvious manner, stopping at the first character which is not a
    valid digit in the given base.  (In bases above 10, the letter \c 'A'
    in either upper or lower case represents 10, \c 'B' represents 11,
    and so forth, with \c 'Z' representing 35.)

    If \c endptr is not NULL, strtol() stores the address of the first
    invalid character in \c *endptr.  If there were no digits at all,
    however, strtol() stores the original value of \c nptr in \c
    *endptr.  (Thus, if \c *nptr is not \c '\\0' but \c **endptr is \c '\\0'
    on return, the entire string was valid.)

    The strtol() function returns the result of the conversion, unless
    the value would underflow or overflow.  If no conversion could be
    performed, 0 is returned.  If an overflow or underflow occurs, \c
    errno is set to \ref avr_errno "ERANGE" and the function return value
    is clamped to \c LONG_MIN or \c LONG_MAX, respectively.
*/
extern long strtol(const char *__nptr, char **__endptr, int __base);

/**
    The strtoul() function converts the string in \c nptr to an
    unsigned long value.  The conversion is done according to the
    given base, which must be between 2 and 36 inclusive, or be the
    special value 0.

    The string may begin with an arbitrary amount of white space (as
    determined by isspace()) followed by a single optional \c '+' or \c '-'
    sign.  If \c base is zero or 16, the string may then include a
    \c "0x" prefix, and the number will be read in base 16; otherwise,
    a zero base is taken as 10 (decimal) unless the next character is
    \c '0', in which case it is taken as 8 (octal).

    The remainder of the string is converted to an unsigned long value
    in the obvious manner, stopping at the first character which is
    not a valid digit in the given base.  (In bases above 10, the
    letter \c 'A' in either upper or lower case represents 10, \c 'B'
    represents 11, and so forth, with \c 'Z' representing 35.)

    If \c endptr is not NULL, strtoul() stores the address of the first
    invalid character in \c *endptr.  If there were no digits at all,
    however, strtoul() stores the original value of \c nptr in \c
    *endptr.  (Thus, if \c *nptr is not \c '\\0' but \c **endptr is \c '\\0'
    on return, the entire string was valid.)

    The strtoul() function return either the result of the conversion
    or, if there was a leading minus sign, the negation of the result
    of the conversion, unless the original (non-negated) value would
    overflow; in the latter case, strtoul() returns ULONG_MAX, and \c
    errno is set to \ref avr_errno "ERANGE".  If no conversion could 
    be performed, 0 is returned.
*/
extern unsigned long strtoul(const char *__nptr, char **__endptr, int __base);

/**
    The atol() function converts the initial portion of the string
    pointed to by \p s to long integer representation. In contrast to

        \code strtol(s, (char **)NULL, 10); \endcode

    this function does not detect overflow (\c errno is not changed and
    the result value is not predictable), uses smaller memory (flash and
    stack) and works more quickly.
*/
extern long atol(const char *__s) __attribute__((__pure__));

/**
    The atoi() function converts the initial portion of the string
    pointed to by \p s to integer representation. In contrast to

        \code (int)strtol(s, (char **)NULL, 10); \endcode

    this function does not detect overflow (\c errno is not changed and
    the result value is not predictable), uses smaller memory (flash and
    stack) and works more quickly.
*/
extern int atoi(const char *__s) __attribute__((__pure__));

/**
   The exit() function terminates the application.  Since there is no
   environment to return to, \c status is ignored, and code execution
   will eventually reach an infinite loop, thereby effectively halting
   all code processing.  Before entering the infinite loop, interrupts
   are globally disabled.

   In a C++ context, global destructors will be called before halting
   execution.
*/
extern void exit(int __status) __attribute__((__noreturn__));

/**
   The malloc() function allocates \c size bytes of memory.
   If malloc() fails, a NULL pointer is returned.

   Note that malloc() does \e not initialize the returned memory to
   zero bytes.

   See the chapter about \ref malloc "malloc() usage" for implementation
   details.
*/
extern void *malloc(size_t __size) __attribute__((__malloc__));

/**
   The free() function causes the allocated memory referenced by \c
   ptr to be made available for future allocations.  If \c ptr is
   NULL, no action occurs.
*/
extern void free(void *__ptr);

/**
   \c malloc() \ref malloc_tunables "tunable".
*/
extern size_t __malloc_margin;

/**
   \c malloc() \ref malloc_tunables "tunable".
*/
extern char *__malloc_heap_start;

/**
   \c malloc() \ref malloc_tunables "tunable".
*/
extern char *__malloc_heap_end;

/**
   Allocate \c nele elements of \c size each.  Identical to calling
   \c malloc() using <tt>nele * size</tt> as argument, except the
   allocated memory will be cleared to zero.
*/
extern void *calloc(size_t __nele, size_t __size) __attribute__((__malloc__));

/**
   The realloc() function tries to change the size of the region
   allocated at \c ptr to the new \c size value.  It returns a
   pointer to the new region.  The returned pointer might be the
   same as the old pointer, or a pointer to a completely different
   region.

   The contents of the returned region up to either the old or the new
   size value (whatever is less) will be identical to the contents of
   the old region, even in case a new region had to be allocated.

   It is acceptable to pass \c ptr as NULL, in which case realloc()
   will behave identical to malloc().

   If the new memory cannot be allocated, realloc() returns NULL, and
   the region at \c ptr will not be changed.
*/
extern void *realloc(void *__ptr, size_t __size) __attribute__((__malloc__));

extern double strtod(const char *__nptr, char **__endptr);

extern double atof(const char *__nptr);

/** Highest number that can be generated by rand(). */


/**
     The rand() function computes a sequence of pseudo-random integers in the
     range of 0 to \c RAND_MAX (as defined by the header file <stdlib.h>).

     The srand() function sets its argument \c seed as the seed for a new
     sequence of pseudo-random numbers to be returned by rand().  These
     sequences are repeatable by calling srand() with the same seed value.

     If no seed value is provided, the functions are automatically seeded with
     a value of 1.

     In compliance with the C standard, these functions operate on
     \c int arguments.  Since the underlying algorithm already uses
     32-bit calculations, this causes a loss of precision.  See
     \c random() for an alternate set of functions that retains full
     32-bit precision.
*/
extern int rand(void);
/**
   Pseudo-random number generator seeding; see rand().
*/
extern void srand(unsigned int __seed);

/**
   Variant of rand() that stores the context in the user-supplied
   variable located at \c ctx instead of a static library variable
   so the function becomes re-entrant.
*/
extern int rand_r(unsigned long *__ctx);
/*@}*/

/*@{*/
/** \name Non-standard (i.e. non-ISO C) functions.
 \ingroup avr_stdlib
*/
/**
   \brief Convert an integer to a string.

   The function itoa() converts the integer value from \c val into an
   ASCII representation that will be stored under \c s.  The caller
   is responsible for providing sufficient storage in \c s.

   \note The minimal size of the buffer \c s depends on the choice of
   radix. For example, if the radix is 2 (binary), you need to supply a buffer
   with a minimal length of 8 * sizeof (int) + 1 characters, i.e. one
   character for each bit plus one for the string terminator. Using a larger
   radix will require a smaller minimal buffer size.

   \warning If the buffer is too small, you risk a buffer overflow.

   Conversion is done using the \c radix as base, which may be a
   number between 2 (binary conversion) and up to 36.  If \c radix
   is greater than 10, the next digit after \c '9' will be the letter
   \c 'a'.
    
    If radix is 10 and val is negative, a minus sign will be prepended.

   The itoa() function returns the pointer passed as \c s.
*/



extern __inline__ __attribute__((__gnu_inline__))
char *itoa (int __val, char *__s, int __radix)
{
    if (!__builtin_constant_p (__radix)) {
 extern char *__itoa (int, char *, int);
 return __itoa (__val, __s, __radix);
    } else if (__radix < 2 || __radix > 36) {
 *__s = 0;
 return __s;
    } else {
 extern char *__itoa_ncheck (int, char *, unsigned char);
 return __itoa_ncheck (__val, __s, __radix);
    }
}


/**
 \ingroup avr_stdlib
 
   \brief Convert a long integer to a string.

   The function ltoa() converts the long integer value from \c val into an
   ASCII representation that will be stored under \c s.  The caller
   is responsible for providing sufficient storage in \c s.

   \note The minimal size of the buffer \c s depends on the choice of
   radix. For example, if the radix is 2 (binary), you need to supply a buffer
   with a minimal length of 8 * sizeof (long int) + 1 characters, i.e. one
   character for each bit plus one for the string terminator. Using a larger
   radix will require a smaller minimal buffer size.

   \warning If the buffer is too small, you risk a buffer overflow.

   Conversion is done using the \c radix as base, which may be a
   number between 2 (binary conversion) and up to 36.  If \c radix
   is greater than 10, the next digit after \c '9' will be the letter
   \c 'a'.

   If radix is 10 and val is negative, a minus sign will be prepended.

   The ltoa() function returns the pointer passed as \c s.
*/



extern __inline__ __attribute__((__gnu_inline__))
char *ltoa (long __val, char *__s, int __radix)
{
    if (!__builtin_constant_p (__radix)) {
 extern char *__ltoa (long, char *, int);
 return __ltoa (__val, __s, __radix);
    } else if (__radix < 2 || __radix > 36) {
 *__s = 0;
 return __s;
    } else {
 extern char *__ltoa_ncheck (long, char *, unsigned char);
 return __ltoa_ncheck (__val, __s, __radix);
    }
}


/**
 \ingroup avr_stdlib

   \brief Convert an unsigned integer to a string.

   The function utoa() converts the unsigned integer value from \c val into an
   ASCII representation that will be stored under \c s.  The caller
   is responsible for providing sufficient storage in \c s.

   \note The minimal size of the buffer \c s depends on the choice of
   radix. For example, if the radix is 2 (binary), you need to supply a buffer
   with a minimal length of 8 * sizeof (unsigned int) + 1 characters, i.e. one
   character for each bit plus one for the string terminator. Using a larger
   radix will require a smaller minimal buffer size.

   \warning If the buffer is too small, you risk a buffer overflow.

   Conversion is done using the \c radix as base, which may be a
   number between 2 (binary conversion) and up to 36.  If \c radix
   is greater than 10, the next digit after \c '9' will be the letter
   \c 'a'.

   The utoa() function returns the pointer passed as \c s.
*/



extern __inline__ __attribute__((__gnu_inline__))
char *utoa (unsigned int __val, char *__s, int __radix)
{
    if (!__builtin_constant_p (__radix)) {
 extern char *__utoa (unsigned int, char *, int);
 return __utoa (__val, __s, __radix);
    } else if (__radix < 2 || __radix > 36) {
 *__s = 0;
 return __s;
    } else {
 extern char *__utoa_ncheck (unsigned int, char *, unsigned char);
 return __utoa_ncheck (__val, __s, __radix);
    }
}


/**
 \ingroup avr_stdlib
   \brief Convert an unsigned long integer to a string.

   The function ultoa() converts the unsigned long integer value from
   \c val into an ASCII representation that will be stored under \c s.
   The caller is responsible for providing sufficient storage in \c s.

   \note The minimal size of the buffer \c s depends on the choice of
   radix. For example, if the radix is 2 (binary), you need to supply a buffer
   with a minimal length of 8 * sizeof (unsigned long int) + 1 characters,
   i.e. one character for each bit plus one for the string terminator. Using a
   larger radix will require a smaller minimal buffer size.

   \warning If the buffer is too small, you risk a buffer overflow.

   Conversion is done using the \c radix as base, which may be a
   number between 2 (binary conversion) and up to 36.  If \c radix
   is greater than 10, the next digit after \c '9' will be the letter
   \c 'a'.

   The ultoa() function returns the pointer passed as \c s.
*/



extern __inline__ __attribute__((__gnu_inline__))
char *ultoa (unsigned long __val, char *__s, int __radix)
{
    if (!__builtin_constant_p (__radix)) {
 extern char *__ultoa (unsigned long, char *, int);
 return __ultoa (__val, __s, __radix);
    } else if (__radix < 2 || __radix > 36) {
 *__s = 0;
 return __s;
    } else {
 extern char *__ultoa_ncheck (unsigned long, char *, unsigned char);
 return __ultoa_ncheck (__val, __s, __radix);
    }
}


/**  \ingroup avr_stdlib
Highest number that can be generated by random(). */


/**
 \ingroup avr_stdlib
     The random() function computes a sequence of pseudo-random integers in the
     range of 0 to \c RANDOM_MAX (as defined by the header file <stdlib.h>).

     The srandom() function sets its argument \c seed as the seed for a new
     sequence of pseudo-random numbers to be returned by rand().  These
     sequences are repeatable by calling srandom() with the same seed value.

     If no seed value is provided, the functions are automatically seeded with
     a value of 1.
*/
extern long random(void);
/**
 \ingroup avr_stdlib
   Pseudo-random number generator seeding; see random().
*/
extern void srandom(unsigned long __seed);

/**
 \ingroup avr_stdlib
   Variant of random() that stores the context in the user-supplied
   variable located at \c ctx instead of a static library variable
   so the function becomes re-entrant.
*/
extern long random_r(unsigned long *__ctx);

/*@}*/

/*@{*/
/** \name Conversion functions for double arguments.
 \ingroup avr_stdlib
 Note that these functions are not located in the default library,
 <tt>libc.a</tt>, but in the mathematical library, <tt>libm.a</tt>.
 So when linking the application, the \c -lm option needs to be
 specified.
*/
/** \ingroup avr_stdlib
    Bit value that can be passed in \c flags to dtostre(). */

/** \ingroup avr_stdlib
    Bit value that can be passed in \c flags to dtostre(). */

/** \ingroup avr_stdlib
    Bit value that can be passed in \c flags to dtostre(). */




/**
   \ingroup avr_stdlib
   The dtostre() function converts the double value passed in \c val into
   an ASCII representation that will be stored under \c s.  The caller
   is responsible for providing sufficient storage in \c s.

   Conversion is done in the format \c "[-]d.ddde±dd" where there is
   one digit before the decimal-point character and the number of
   digits after it is equal to the precision \c prec; if the precision
   is zero, no decimal-point character appears.  If \c flags has the
   DTOSTRE_UPPERCASE bit set, the letter \c 'E' (rather than \c 'e' ) will be
   used to introduce the exponent.  The exponent always contains two
   digits; if the value is zero, the exponent is \c "00".

   If \c flags has the DTOSTRE_ALWAYS_SIGN bit set, a space character
   will be placed into the leading position for positive numbers.

   If \c flags has the DTOSTRE_PLUS_SIGN bit set, a plus sign will be
   used instead of a space character in this case.

   The dtostre() function returns the pointer to the converted string \c s.
*/
extern char *dtostre(double __val, char *__s, unsigned char __prec,
       unsigned char __flags);

/**
   \ingroup avr_stdlib
   The dtostrf() function converts the double value passed in \c val into
   an ASCII representationthat will be stored under \c s.  The caller
   is responsible for providing sufficient storage in \c s.

   Conversion is done in the format \c "[-]d.ddd".  The minimum field
   width of the output string (including the \c '.' and the possible
   sign for negative values) is given in \c width, and \c prec determines
   the number of digits after the decimal sign. \c width is signed value,
   negative for left adjustment.

   The dtostrf() function returns the pointer to the converted string \c s.
*/
extern char *dtostrf(double __val, signed char __width,
                     unsigned char __prec, char *__s);

/**
   \ingroup avr_stdlib
    Successful termination for exit(); evaluates to 0.
*/


/**
   \ingroup avr_stdlib
    Unsuccessful termination for exit(); evaluates to a non-zero value.
*/


/*@}*/






}
# 24 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Arduino.h" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stdbool.h" 1 3 4
/* Copyright (C) 1998-2013 Free Software Foundation, Inc.

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
 * ISO C Standard:  7.16  Boolean type and values  <stdbool.h>
 */
# 39 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stdbool.h" 3 4
/* Supporting <stdbool.h> in C++ is a GCC extension.  */







/* Signal that all the definitions are present.  */
# 25 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Arduino.h" 2
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
# 26 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Arduino.h" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/math.h" 1 3
/* Copyright (c) 2002,2007-2009 Michael Stumpf

   Portions of documentation Copyright (c) 1990 - 1994
   The Regents of the University of California.

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
   math.h - mathematical functions

   Author : Michael Stumpf
            Michael.Stumpf@t-online.de

   __ATTR_CONST__ added by marekm@linux.org.pl for functions
   that "do not examine any values except their arguments, and have
   no effects except the return value", for better optimization by gcc.
 */




/** \file */
/** \defgroup avr_math <math.h>: Mathematics
    \code #include <math.h> \endcode

    This header file declares basic mathematics constants and
    functions.

    \par Notes:
    - In order to access the functions declared herein, it is usually
      also required to additionally link against the library \c libm.a.
      See also the related \ref faq_libm "FAQ entry".
    - Math functions do not raise exceptions and do not change the
      \c errno variable. Therefore the majority of them are declared
      with const attribute, for better optimization by GCC.	*/


/** \ingroup avr_math	*/
/*@{*/

/** The constant \a e.	*/


/** The logarithm of the \a e to base 2. */


/** The logarithm of the \a e to base 10. */


/** The natural logarithm of the 2.	*/


/** The natural logarithm of the 10.	*/


/** The constant \a pi.	*/


/** The constant \a pi/2.	*/


/** The constant \a pi/4.	*/


/** The constant \a 1/pi.	*/


/** The constant \a 2/pi.	*/


/** The constant \a 2/sqrt(pi).	*/


/** The square root of 2.	*/


/** The constant \a 1/sqrt(2).	*/


/** NAN constant.	*/


/** INFINITY constant.	*/
# 121 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/math.h" 3
extern "C" {


/**
    The cos() function returns the cosine of \a __x, measured in radians.
 */
extern double cos(double __x) __attribute__((__const__));


/**
    The sin() function returns the sine of \a __x, measured in radians.
 */
extern double sin(double __x) __attribute__((__const__));


/**
    The tan() function returns the tangent of \a __x, measured in radians.
 */
extern double tan(double __x) __attribute__((__const__));


/**
    The fabs() function computes the absolute value of a floating-point
    number \a __x.
 */
extern double fabs(double __x) __attribute__((__const__));


/**
    The function fmod() returns the floating-point remainder of <em>__x /
    __y</em>.
 */
extern double fmod(double __x, double __y) __attribute__((__const__));


/**
    The modf() function breaks the argument \a __x into integral and
    fractional parts, each of which has the same sign as the argument. 
    It stores the integral part as a double in the object pointed to by
    \a __iptr.

    The modf() function returns the signed fractional part of \a __x.

    \note This implementation skips writing by zero pointer.  However,
    the GCC 4.3 can replace this function with inline code that does not
    permit to use NULL address for the avoiding of storing.
 */
extern double modf(double __x, double *__iptr);

/** The alias for modf().
 */
extern float modff (float __x, float *__iptr);

/**
    The sqrt() function returns the non-negative square root of \a __x.
 */
extern double sqrt(double __x) __attribute__((__const__));


/**
    The cbrt() function returns the cube root of \a __x.
 */
extern double cbrt(double __x) __attribute__((__const__));


/**
    The hypot() function returns <em>sqrt(__x*__x + __y*__y)</em>. This
    is the length of the hypotenuse of a right triangle with sides of
    length \a __x and \a __y, or the  distance of the point (\a __x, \a
    __y) from the origin. Using this function  instead of the direct
    formula is wise, since the error is much smaller. No underflow with
    small \a __x and \a __y. No overflow if result is in range.
 */
extern double hypot (double __x, double __y) __attribute__((__const__));


/**
    The function square() returns <em>__x * __x</em>.

    \note This function does not belong to the C standard definition.
 */
extern double square(double __x) __attribute__((__const__));


/**
    The floor() function returns the largest integral value less than or
    equal to \a __x, expressed as a floating-point number.
 */
extern double floor(double __x) __attribute__((__const__));


/**
    The ceil() function returns the smallest integral value greater than
    or equal to \a __x, expressed as a floating-point number.
 */
extern double ceil(double __x) __attribute__((__const__));


/**
    The frexp() function breaks a floating-point number into a normalized
    fraction and an integral power of 2.  It stores the integer in the \c
    int object pointed to by \a __pexp.

    If \a __x is a normal float point number, the frexp() function
    returns the value \c v, such that \c v has a magnitude in the
    interval [1/2, 1) or zero, and \a __x equals \c v times 2 raised to
    the power \a __pexp. If \a __x is zero, both parts of the result are
    zero. If \a __x is not a finite number, the frexp() returns \a __x as
    is and stores 0 by \a __pexp.

    \note  This implementation permits a zero pointer as a directive to
    skip a storing the exponent.
 */
extern double frexp(double __x, int *__pexp);


/**
    The ldexp() function multiplies a floating-point number by an integral
    power of 2. It returns the value of \a __x times 2 raised to the power
    \a __exp.
 */
extern double ldexp(double __x, int __exp) __attribute__((__const__));


/**
    The exp() function returns the exponential value of \a __x.
 */
extern double exp(double __x) __attribute__((__const__));


/**
    The cosh() function returns the hyperbolic cosine of \a __x.
 */
extern double cosh(double __x) __attribute__((__const__));


/**
    The sinh() function returns the hyperbolic sine of \a __x.
 */
extern double sinh(double __x) __attribute__((__const__));


/**
    The tanh() function returns the hyperbolic tangent of \a __x.
 */
extern double tanh(double __x) __attribute__((__const__));


/**
    The acos() function computes the principal value of the arc cosine of
    \a __x.  The returned value is in the range [0, pi] radians. A domain
    error occurs for arguments not in the range [-1, +1].
 */
extern double acos(double __x) __attribute__((__const__));


/**
    The asin() function computes the principal value of the arc sine of
    \a __x.  The returned value is in the range [-pi/2, pi/2] radians. A
    domain error occurs for arguments not in the range [-1, +1].
 */
extern double asin(double __x) __attribute__((__const__));


/**
    The atan() function computes the principal value of the arc tangent
    of \a __x.  The returned value is in the range [-pi/2, pi/2] radians.
 */
extern double atan(double __x) __attribute__((__const__));


/**
    The atan2() function computes the principal value of the arc tangent
    of <em>__y / __x</em>, using the signs of both arguments to determine
    the quadrant of the return value.  The returned value is in the range
    [-pi, +pi] radians.
 */
extern double atan2(double __y, double __x) __attribute__((__const__));


/**
    The log() function returns the natural logarithm of argument \a __x.
 */
extern double log(double __x) __attribute__((__const__));


/**
    The log10() function returns the logarithm of argument \a __x to base 10.
 */
extern double log10(double __x) __attribute__((__const__));


/**
    The function pow() returns the value of \a __x to the exponent \a __y.
 */
extern double pow(double __x, double __y) __attribute__((__const__));


/**
    The function isnan() returns 1 if the argument \a __x represents a
    "not-a-number" (NaN) object, otherwise 0.
 */
extern int isnan(double __x) __attribute__((__const__));


/**
    The function isinf() returns 1 if the argument \a __x is positive
    infinity, -1 if \a __x is negative infinity, and 0 otherwise.

    \note The GCC 4.3 can replace this function with inline code that
    returns the 1 value for both infinities (gcc bug #35509).
 */
extern int isinf(double __x) __attribute__((__const__));


/**
    The isfinite() function returns a nonzero value if \a __x is finite:
    not plus or minus infinity, and not NaN.
 */
__attribute__((__const__)) static inline int isfinite (double __x)
{
    unsigned char __exp;
    __asm__ (
 "mov	%0, %C1		\n\t"
 "lsl	%0		\n\t"
 "mov	%0, %D1		\n\t"
 "rol	%0		"
 : "=r" (__exp)
 : "r" (__x) );
    return __exp != 0xff;
}


/**
    The copysign() function returns \a __x but with the sign of \a __y.
    They work even if \a __x or \a __y are NaN or zero.
*/
__attribute__((__const__)) static inline double copysign (double __x, double __y)
{
    __asm__ (
 "bst	%D2, 7	\n\t"
 "bld	%D0, 7	"
 : "=r" (__x)
 : "0" (__x), "r" (__y) );
    return __x;
}


/**
    The signbit() function returns a nonzero value if the value of \a __x
    has its sign bit set.  This is not the same as `\a __x < 0.0',
    because IEEE 754 floating point allows zero to be signed. The
    comparison `-0.0 < 0.0' is false, but `signbit (-0.0)' will return a
    nonzero value.
 */
extern int signbit (double __x) __attribute__((__const__));


/**
    The fdim() function returns <em>max(__x - __y, 0)</em>. If \a __x or
    \a __y or both are NaN, NaN is returned.
 */
extern double fdim (double __x, double __y) __attribute__((__const__));


/**
    The fma() function performs floating-point multiply-add. This is the
    operation <em>(__x * __y) + __z</em>, but the intermediate result is
    not rounded to the destination type.  This can sometimes improve the
    precision of a calculation.
 */
extern double fma (double __x, double __y, double __z) __attribute__((__const__));


/**
    The fmax() function returns the greater of the two values \a __x and
    \a __y. If an argument is NaN, the other argument is returned. If
    both arguments are NaN, NaN is returned.
 */
extern double fmax (double __x, double __y) __attribute__((__const__));


/**
    The fmin() function returns the lesser of the two values \a __x and
    \a __y. If an argument is NaN, the other argument is returned. If
    both arguments are NaN, NaN is returned.
 */
extern double fmin (double __x, double __y) __attribute__((__const__));


/**
    The trunc() function rounds \a __x to the nearest integer not larger
    in absolute value.
 */
extern double trunc (double __x) __attribute__((__const__));


/**
    The round() function rounds \a __x to the nearest integer, but rounds
    halfway cases away from zero (instead of to the nearest even integer).
    Overflow is impossible.

    \return The rounded value. If \a __x is an integral or infinite, \a
    __x itself is returned. If \a __x is \c NaN, then \c NaN is returned.
 */
extern double round (double __x) __attribute__((__const__));


/**
    The lround() function rounds \a __x to the nearest integer, but rounds
    halfway cases away from zero (instead of to the nearest even integer).
    This function is similar to round() function, but it differs in type of
    return value and in that an overflow is possible.

    \return The rounded long integer value. If \a __x is not a finite number
    or an overflow was, this realization returns the \c LONG_MIN value
    (0x80000000).
 */
extern long lround (double __x) __attribute__((__const__));


/**
    The lrint() function rounds \a __x to the nearest integer, rounding the
    halfway cases to the even integer direction. (That is both 1.5 and 2.5
    values are rounded to 2). This function is similar to rint() function,
    but it differs in type of return value and in that an overflow is
    possible.

    \return The rounded long integer value. If \a __x is not a finite
    number or an overflow was, this realization returns the \c LONG_MIN
    value (0x80000000).
 */
extern long lrint (double __x) __attribute__((__const__));



}


/*@}*/
# 27 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Arduino.h" 2

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
# 29 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Arduino.h" 2
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
# 30 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Arduino.h" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/interrupt.h" 1 3
/* Copyright (c) 2002,2005,2007 Marek Michalkiewicz
   Copyright (c) 2007, Dean Camera

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
# 39 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/interrupt.h" 2 3


/* Auxiliary macro for ISR_ALIAS(). */



/** 
\file 
\@{ 
*/


/** \name Global manipulation of the interrupt flag

    The global interrupt flag is maintained in the I bit of the status
    register (SREG).

    Handling interrupts frequently requires attention regarding atomic
    access to objects that could be altered by code running within an
    interrupt context, see <util/atomic.h>.

    Frequently, interrupts are being disabled for periods of time in
    order to perform certain operations without being disturbed; see
    \ref optim_code_reorder for things to be taken into account with
    respect to compiler optimizations.
*/
# 103 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/interrupt.h" 3
/** \name Macros for writing interrupt handler functions */
# 283 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/interrupt.h" 3
/** \name ISR attributes */
# 342 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/interrupt.h" 3
/* \@} */
# 31 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Arduino.h" 2

# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/binary.h" 1
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
# 33 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Arduino.h" 2


extern "C"{


void yield(void);
# 79 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Arduino.h"
// undefine stdlib's abs if encountered
# 108 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Arduino.h"
// avr-libc defines _NOP() since 1.6.2




typedef unsigned int word;



typedef bool boolean;
typedef uint8_t byte;

void init(void);
void initVariant(void);

int atexit(void (*func)()) __attribute__((weak));

void pinMode(uint8_t, uint8_t);
void digitalWrite(uint8_t, uint8_t);
int digitalRead(uint8_t);
int analogRead(uint8_t);
void analogReference(uint8_t mode);
void analogWrite(uint8_t, int);

unsigned long millis(void);
unsigned long micros(void);
void delay(unsigned long);
void delayMicroseconds(unsigned int us);
unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout);
unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout);

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);
uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder);

void attachInterrupt(uint8_t, void (*)(void), int mode);
void detachInterrupt(uint8_t);

void setup(void);
void loop(void);

// Get the bit location within the hardware port of the given virtual pin.
// This comes from the pins_*.c file for the active board configuration.



// On the ATmega1280, the addresses of some of the port registers are
// greater than 255, so we can't store them in uint8_t's.
extern const uint16_t __attribute__((__progmem__)) port_to_mode_PGM[];
extern const uint16_t __attribute__((__progmem__)) port_to_input_PGM[];
extern const uint16_t __attribute__((__progmem__)) port_to_output_PGM[];

extern const uint8_t __attribute__((__progmem__)) digital_pin_to_port_PGM[];
// extern const uint8_t PROGMEM digital_pin_to_bit_PGM[];
extern const uint8_t __attribute__((__progmem__)) digital_pin_to_bit_mask_PGM[];
extern const uint8_t __attribute__((__progmem__)) digital_pin_to_timer_PGM[];

// Get the bit location within the hardware port of the given virtual pin.
// This comes from the pins_*.c file for the active board configuration.
// 
// These perform slightly better as macros compared to inline functions
//
# 218 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Arduino.h"
} // extern "C"



# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/WCharacter.h" 1
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




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/ctype.h" 1 3
/* Copyright (c) 2002,2007 Michael Stumpf
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
   ctype.h - character conversion macros and ctype macros

  Author : Michael Stumpf
           Michael.Stumpf@t-online.de
*/
# 48 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/ctype.h" 3
extern "C" {


/** \file */
/** \defgroup ctype <ctype.h>: Character Operations
    These functions perform various operations on characters.

    \code #include <ctype.h>\endcode 

*/

/** \name Character classification routines

    These functions perform character classification. They return true or
    false status depending whether the character passed to the function falls
    into the function's classification (i.e. isdigit() returns true if its
    argument is any value '0' though '9', inclusive). If the input is not
    an unsigned char value, all of this function return false.	*/

 /* @{ */

/** \ingroup ctype

    Checks for an alphanumeric character. It is equivalent to <tt>(isalpha(c)
    || isdigit(c))</tt>. */

extern int isalnum(int __c) __attribute__((__const__));

/** \ingroup ctype

    Checks for an alphabetic character. It is equivalent to <tt>(isupper(c) ||
    islower(c))</tt>. */

extern int isalpha(int __c) __attribute__((__const__));

/** \ingroup ctype

    Checks whether \c c is a 7-bit unsigned char value that fits into the
    ASCII character set. */

extern int isascii(int __c) __attribute__((__const__));

/** \ingroup ctype

    Checks for a blank character, that is, a space or a tab. */

extern int isblank(int __c) __attribute__((__const__));

/** \ingroup ctype

    Checks for a control character. */

extern int iscntrl(int __c) __attribute__((__const__));

/** \ingroup ctype

    Checks for a digit (0 through 9). */

extern int isdigit(int __c) __attribute__((__const__));

/** \ingroup ctype

    Checks for any printable character except space. */

extern int isgraph(int __c) __attribute__((__const__));

/** \ingroup ctype

    Checks for a lower-case character. */

extern int islower(int __c) __attribute__((__const__));

/** \ingroup ctype

    Checks for any printable character including space. */

extern int isprint(int __c) __attribute__((__const__));

/** \ingroup ctype

    Checks for any printable character which is not a space or an alphanumeric
    character. */

extern int ispunct(int __c) __attribute__((__const__));

/** \ingroup ctype

    Checks for white-space characters.  For the avr-libc library, these are:
    space, form-feed ('\\f'), newline ('\\n'), carriage return ('\\r'),
    horizontal tab ('\\t'), and vertical tab ('\\v'). */

extern int isspace(int __c) __attribute__((__const__));

/** \ingroup ctype

    Checks for an uppercase letter. */

extern int isupper(int __c) __attribute__((__const__));

/** \ingroup ctype

    Checks for a hexadecimal digits, i.e. one of 0 1 2 3 4 5 6 7 8 9 a b c d e
    f A B C D E F. */

extern int isxdigit(int __c) __attribute__((__const__));

/* @} */

/** \name Character convertion routines 

    This realization permits all possible values of integer argument.
    The toascii() function clears all highest bits. The tolower() and
    toupper() functions return an input argument as is, if it is not an
    unsigned char value.	*/

/* @{ */

/** \ingroup ctype

    Converts \c c to a 7-bit unsigned char value that fits into the ASCII
    character set, by clearing the high-order bits.

    \warning Many people will be unhappy if you use this function. This
    function will convert accented letters into random characters. */

extern int toascii(int __c) __attribute__((__const__));

/** \ingroup ctype

    Converts the letter \c c to lower case, if possible. */

extern int tolower(int __c) __attribute__((__const__));

/** \ingroup ctype

    Converts the letter \c c to upper case, if possible. */

extern int toupper(int __c) __attribute__((__const__));

/* @} */


}
# 24 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/WCharacter.h" 2

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
  return ( isalnum(c) == 0 ? false : true);
}


// Checks for an alphabetic character. 
// It is equivalent to (isupper(c) || islower(c)).
inline boolean isAlpha(int c)
{
  return ( isalpha(c) == 0 ? false : true);
}


// Checks whether c is a 7-bit unsigned char value 
// that fits into the ASCII character set.
inline boolean isAscii(int c)
{
  return ( isascii (c) == 0 ? false : true);
}


// Checks for a blank character, that is, a space or a tab.
inline boolean isWhitespace(int c)
{
  return ( isblank (c) == 0 ? false : true);
}


// Checks for a control character.
inline boolean isControl(int c)
{
  return ( iscntrl (c) == 0 ? false : true);
}


// Checks for a digit (0 through 9).
inline boolean isDigit(int c)
{
  return ( isdigit (c) == 0 ? false : true);
}


// Checks for any printable character except space.
inline boolean isGraph(int c)
{
  return ( isgraph (c) == 0 ? false : true);
}


// Checks for a lower-case character.
inline boolean isLowerCase(int c)
{
  return (islower (c) == 0 ? false : true);
}


// Checks for any printable character including space.
inline boolean isPrintable(int c)
{
  return ( isprint (c) == 0 ? false : true);
}


// Checks for any printable character which is not a space 
// or an alphanumeric character.
inline boolean isPunct(int c)
{
  return ( ispunct (c) == 0 ? false : true);
}


// Checks for white-space characters. For the avr-libc library, 
// these are: space, formfeed ('\f'), newline ('\n'), carriage 
// return ('\r'), horizontal tab ('\t'), and vertical tab ('\v').
inline boolean isSpace(int c)
{
  return ( isspace (c) == 0 ? false : true);
}


// Checks for an uppercase letter.
inline boolean isUpperCase(int c)
{
  return ( isupper (c) == 0 ? false : true);
}


// Checks for a hexadecimal digits, i.e. one of 0 1 2 3 4 5 6 7 
// 8 9 a b c d e f A B C D E F.
inline boolean isHexadecimalDigit(int c)
{
  return ( isxdigit (c) == 0 ? false : true);
}


// Converts c to a 7-bit unsigned char value that fits into the 
// ASCII character set, by clearing the high-order bits.
inline int toAscii(int c)
{
  return toascii (c);
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
# 223 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Arduino.h" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/WString.h" 1
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





# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/stdlib.h" 1 3
/* Copyright (c) 2002, Marek Michalkiewicz
   Copyright (c) 2004,2007 Joerg Wunsch

   Portions of documentation Copyright (c) 1990, 1991, 1993, 1994
   The Regents of the University of California.

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

  $Id$
*/
# 27 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/WString.h" 2
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
# 28 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/WString.h" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/ctype.h" 1 3
/* Copyright (c) 2002,2007 Michael Stumpf
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
   ctype.h - character conversion macros and ctype macros

  Author : Michael Stumpf
           Michael.Stumpf@t-online.de
*/
# 29 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/WString.h" 2
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
# 30 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/WString.h" 2

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
# 224 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Arduino.h" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/HardwareSerial.h" 1
/*
  HardwareSerial.h - Hardware serial library for Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

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

  Modified 28 September 2010 by Mark Sproul
  Modified 14 August 2012 by Alarus
  Modified 3 December 2013 by Matthijs Kooijman
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
# 28 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/HardwareSerial.h" 2

# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Stream.h" 1
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
# 26 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Stream.h" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Print.h" 1
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
# 24 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Print.h" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/stdio.h" 1 3
/* Copyright (c) 2002, 2005, 2007 Joerg Wunsch
   All rights reserved.

   Portions of documentation Copyright (c) 1990, 1991, 1993
   The Regents of the University of California.

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

  $Id$
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
# 45 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/stdio.h" 2 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stdarg.h" 1 3 4
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
# 36 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stdarg.h" 3 4
/* Define __gnuc_va_list.  */



typedef __builtin_va_list __gnuc_va_list;


/* Define the standard macros for the user,
   if this invocation was from the user program.  */
# 55 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stdarg.h" 3 4
/* Define va_list, if desired, from __gnuc_va_list. */
/* We deliberately do not define va_list when called from
   stdio.h, because ANSI C says that stdio.h is not supposed to define
   va_list.  stdio.h needs to have access to that data type, 
   but must not use that name.  It should use the name __gnuc_va_list,
   which is safe because it is reserved for the implementation.  */
# 85 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stdarg.h" 3 4
/* The macro _VA_LIST_ is the same thing used by this file in Ultrix.
   But on BSD NET2 we must not test or define or undef it.
   (Note that the comments in NET 2's ansi.h
   are incorrect for _VA_LIST_--see stdio.h!)  */

/* The macro _VA_LIST_DEFINED is used in Windows NT 3.5  */

/* The macro _VA_LIST is used in SCO Unix 3.2.  */

/* The macro _VA_LIST_T_H is used in the Bull dpx2  */

/* The macro __va_list__ is used by BeOS.  */

typedef __gnuc_va_list va_list;
# 46 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/stdio.h" 2 3



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
# 50 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/stdio.h" 2 3

/** \file */
/** \defgroup avr_stdio <stdio.h>: Standard IO facilities
    \code #include <stdio.h> \endcode

    <h3>Introduction to the Standard IO facilities</h3>

    This file declares the standard IO facilities that are implemented
    in \c avr-libc.  Due to the nature of the underlying hardware,
    only a limited subset of standard IO is implemented.  There is no
    actual file implementation available, so only device IO can be
    performed.  Since there's no operating system, the application
    needs to provide enough details about their devices in order to
    make them usable by the standard IO facilities.

    Due to space constraints, some functionality has not been
    implemented at all (like some of the \c printf conversions that
    have been left out).  Nevertheless, potential users of this
    implementation should be warned: the \c printf and \c scanf families of functions, although
    usually associated with presumably simple things like the
    famous "Hello, world!" program, are actually fairly complex
    which causes their inclusion to eat up a fair amount of code space.
    Also, they are not fast due to the nature of interpreting the
    format string at run-time.  Whenever possible, resorting to the
    (sometimes non-standard) predetermined conversion facilities that are
    offered by avr-libc will usually cost much less in terms of speed
    and code size.

    <h3>Tunable options for code size vs. feature set</h3>

    In order to allow programmers a code size vs. functionality tradeoff,
    the function vfprintf() which is the heart of the printf family can be
    selected in different flavours using linker options.  See the
    documentation of vfprintf() for a detailed description.  The same
    applies to vfscanf() and the \c scanf family of functions.

    <h3>Outline of the chosen API</h3>

    The standard streams \c stdin, \c stdout, and \c stderr are
    provided, but contrary to the C standard, since avr-libc has no
    knowledge about applicable devices, these streams are not already
    pre-initialized at application startup.  Also, since there is no
    notion of "file" whatsoever to avr-libc, there is no function
    \c fopen() that could be used to associate a stream to some device.
    (See \ref stdio_note1 "note 1".)  Instead, the function \c fdevopen()
    is provided to associate a stream to a device, where the device
    needs to provide a function to send a character, to receive a
    character, or both.  There is no differentiation between "text" and
    "binary" streams inside avr-libc.  Character \c \\n is sent
    literally down to the device's \c put() function.  If the device
    requires a carriage return (\c \\r) character to be sent before
    the linefeed, its \c put() routine must implement this (see
    \ref stdio_note2 "note 2").

    As an alternative method to fdevopen(), the macro
    fdev_setup_stream() might be used to setup a user-supplied FILE
    structure.

    It should be noted that the automatic conversion of a newline
    character into a carriage return - newline sequence breaks binary
    transfers.  If binary transfers are desired, no automatic
    conversion should be performed, but instead any string that aims
    to issue a CR-LF sequence must use <tt>"\r\n"</tt> explicitly.

    For convenience, the first call to \c fdevopen() that opens a
    stream for reading will cause the resulting stream to be aliased
    to \c stdin.  Likewise, the first call to \c fdevopen() that opens
    a stream for writing will cause the resulting stream to be aliased
    to both, \c stdout, and \c stderr.  Thus, if the open was done
    with both, read and write intent, all three standard streams will
    be identical.  Note that these aliases are indistinguishable from
    each other, thus calling \c fclose() on such a stream will also
    effectively close all of its aliases (\ref stdio_note3 "note 3").

    It is possible to tie additional user data to a stream, using
    fdev_set_udata().  The backend put and get functions can then
    extract this user data using fdev_get_udata(), and act
    appropriately.  For example, a single put function could be used
    to talk to two different UARTs that way, or the put and get
    functions could keep internal state between calls there.

    <h3>Format strings in flash ROM</h3>

    All the \c printf and \c scanf family functions come in two flavours: the
    standard name, where the format string is expected to be in
    SRAM, as well as a version with the suffix "_P" where the format
    string is expected to reside in the flash ROM.  The macro
    \c PSTR (explained in \ref avr_pgmspace) becomes very handy
    for declaring these format strings.

    \anchor stdio_without_malloc
    <h3>Running stdio without malloc()</h3>

    By default, fdevopen() requires malloc().  As this is often
    not desired in the limited environment of a microcontroller, an
    alternative option is provided to run completely without malloc().

    The macro fdev_setup_stream() is provided to prepare a
    user-supplied FILE buffer for operation with stdio.

    <h4>Example</h4>

    \code
    #include <stdio.h>

    static int uart_putchar(char c, FILE *stream);

    static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL,
                                             _FDEV_SETUP_WRITE);

    static int
    uart_putchar(char c, FILE *stream)
    {

      if (c == '\n')
        uart_putchar('\r', stream);
      loop_until_bit_is_set(UCSRA, UDRE);
      UDR = c;
      return 0;
    }

    int
    main(void)
    {
      init_uart();
      stdout = &mystdout;
      printf("Hello, world!\n");

      return 0;
    }
    \endcode

    This example uses the initializer form FDEV_SETUP_STREAM() rather
    than the function-like fdev_setup_stream(), so all data
    initialization happens during C start-up.

    If streams initialized that way are no longer needed, they can be
    destroyed by first calling the macro fdev_close(), and then
    destroying the object itself.  No call to fclose() should be
    issued for these streams.  While calling fclose() itself is
    harmless, it will cause an undefined reference to free() and thus
    cause the linker to link the malloc module into the application.

    <h3>Notes</h3>

    \anchor stdio_note1 \par Note 1:
    It might have been possible to implement a device abstraction that
    is compatible with \c fopen() but since this would have required
    to parse a string, and to take all the information needed either
    out of this string, or out of an additional table that would need to be
    provided by the application, this approach was not taken.

    \anchor stdio_note2 \par Note 2:
    This basically follows the Unix approach: if a device such as a
    terminal needs special handling, it is in the domain of the
    terminal device driver to provide this functionality.  Thus, a
    simple function suitable as \c put() for \c fdevopen() that talks
    to a UART interface might look like this:

    \code
    int
    uart_putchar(char c, FILE *stream)
    {

      if (c == '\n')
        uart_putchar('\r');
      loop_until_bit_is_set(UCSRA, UDRE);
      UDR = c;
      return 0;
    }
    \endcode

    \anchor stdio_note3 \par Note 3:
    This implementation has been chosen because the cost of maintaining
    an alias is considerably smaller than the cost of maintaining full
    copies of each stream.  Yet, providing an implementation that offers
    the complete set of standard streams was deemed to be useful.  Not
    only that writing \c printf() instead of <tt>fprintf(mystream, ...)</tt>
    saves typing work, but since avr-gcc needs to resort to pass all
    arguments of variadic functions on the stack (as opposed to passing
    them in registers for functions that take a fixed number of
    parameters), the ability to pass one parameter less by implying
    \c stdin or stdout will also save some execution time.
*/



/*
 * This is an internal structure of the library that is subject to be
 * changed without warnings at any time.  Please do *never* reference
 * elements of it beyond by using the official interfaces provided.
 */
struct __file {
 char *buf; /* buffer pointer */
 unsigned char unget; /* ungetc() buffer */
 uint8_t flags; /* flags, see below */
# 261 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/stdio.h" 3
 int size; /* size of buffer */
 int len; /* characters read or written so far */
 int (*put)(char, struct __file *); /* function to write one char to device */
 int (*get)(struct __file *); /* function to read one char from device */
 void *udata; /* User defined and accessible data. */
};



/*@{*/
/**
   \c FILE is the opaque structure that is passed around between the
   various standard IO functions.
*/


/**
   Stream that will be used as an input stream by the simplified
   functions that don't take a \c stream argument.

   The first stream opened with read intent using \c fdevopen()
   will be assigned to \c stdin.
*/


/**
   Stream that will be used as an output stream by the simplified
   functions that don't take a \c stream argument.

   The first stream opened with write intent using \c fdevopen()
   will be assigned to both, \c stdin, and \c stderr.
*/


/**
   Stream destined for error output.  Unless specifically assigned,
   identical to \c stdout.

   If \c stderr should point to another stream, the result of
   another \c fdevopen() must be explicitly assigned to it without
   closing the previous \c stderr (since this would also close
   \c stdout).
*/


/**
   \c EOF declares the value that is returned by various standard IO
   functions in case of an error.  Since the AVR platform (currently)
   doesn't contain an abstraction for actual files, its origin as
   "end of file" is somewhat meaningless here.
*/


/** This macro inserts a pointer to user defined data into a FILE
    stream object.

    The user data can be useful for tracking state in the put and get
    functions supplied to the fdevopen() function. */


/** This macro retrieves a pointer to user defined data from a FILE
    stream object. */
# 361 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/stdio.h" 3
/**
 * Return code for an error condition during device read.
 *
 * To be used in the get function of fdevopen().
 */


/**
 * Return code for an end-of-file condition during device read.
 *
 * To be used in the get function of fdevopen().
 */
# 397 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/stdio.h" 3
extern "C" {



/*
 * Doxygen documentation can be found in fdevopen.c.
 */

extern struct __file *__iob[];
# 416 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/stdio.h" 3
/* New prototype for avr-libc 1.4 and above. */
extern struct __file *fdevopen(int (*__put)(char, struct __file*), int (*__get)(struct __file*));




/**
   This function closes \c stream, and disallows and further
   IO to and from it.

   When using fdevopen() to setup the stream, a call to fclose() is
   needed in order to free the internal resources allocated.

   If the stream has been set up using fdev_setup_stream() or
   FDEV_SETUP_STREAM(), use fdev_close() instead.

   It currently always returns 0 (for success).
*/
extern int fclose(struct __file *__stream);

/**
   This macro frees up any library resources that might be associated
   with \c stream.  It should be called if \c stream is no longer
   needed, right before the application is going to destroy the
   \c stream object itself.

   (Currently, this macro evaluates to nothing, but this might change
   in future versions of the library.)
*/






/**
   \c vfprintf is the central facility of the \c printf family of
   functions.  It outputs values to \c stream under control of a
   format string passed in \c fmt.  The actual values to print are
   passed as a variable argument list \c ap.

   \c vfprintf returns the number of characters written to \c stream,
   or \c EOF in case of an error.  Currently, this will only happen
   if \c stream has not been opened with write intent.

   The format string is composed of zero or more directives: ordinary
   characters (not \c %), which are copied unchanged to the output
   stream; and conversion specifications, each of which results in
   fetching zero or more subsequent arguments.  Each conversion
   specification is introduced by the \c % character.  The arguments must
   properly correspond (after type promotion) with the conversion
   specifier.  After the \c %, the following appear in sequence:

   - Zero or more of the following flags:
      <ul>
      <li> \c # The value should be converted to an "alternate form".  For
            c, d, i, s, and u conversions, this option has no effect.
            For o conversions, the precision of the number is
            increased to force the first character of the output
            string to a zero (except if a zero value is printed with
            an explicit precision of zero).  For x and X conversions,
            a non-zero result has the string `0x' (or `0X' for X
            conversions) prepended to it.</li>
      <li> \c 0 (zero) Zero padding.  For all conversions, the converted
            value is padded on the left with zeros rather than blanks.
            If a precision is given with a numeric conversion (d, i,
            o, u, i, x, and X), the 0 flag is ignored.</li>
      <li> \c - A negative field width flag; the converted value is to be
            left adjusted on the field boundary.  The converted value
            is padded on the right with blanks, rather than on the
            left with blanks or zeros.  A - overrides a 0 if both are
            given.</li>
      <li> ' ' (space) A blank should be left before a positive number
            produced by a signed conversion (d, or i).</li>
      <li> \c + A sign must always be placed before a number produced by a
            signed conversion.  A + overrides a space if both are
            used.</li>
      </ul>
      
   -   An optional decimal digit string specifying a minimum field width.
       If the converted value has fewer characters than the field width, it
       will be padded with spaces on the left (or right, if the left-adjustment
       flag has been given) to fill out the field width.
   -   An optional precision, in the form of a period . followed by an
       optional digit string.  If the digit string is omitted, the
       precision is taken as zero.  This gives the minimum number of
       digits to appear for d, i, o, u, x, and X conversions, or the
       maximum number of characters to be printed from a string for \c s
       conversions.
   -   An optional \c l or \c h length modifier, that specifies that the
       argument for the d, i, o, u, x, or X conversion is a \c "long int"
       rather than \c int. The \c h is ignored, as \c "short int" is
       equivalent to \c int.
   -   A character that specifies the type of conversion to be applied.

   The conversion specifiers and their meanings are:

   - \c diouxX The int (or appropriate variant) argument is converted
           to signed decimal (d and i), unsigned octal (o), unsigned
           decimal (u), or unsigned hexadecimal (x and X) notation.
           The letters "abcdef" are used for x conversions; the
           letters "ABCDEF" are used for X conversions.  The
           precision, if any, gives the minimum number of digits that
           must appear; if the converted value requires fewer digits,
           it is padded on the left with zeros.
   - \c p  The <tt>void *</tt> argument is taken as an unsigned integer,
           and converted similarly as a <tt>%\#x</tt> command would do.
   - \c c  The \c int argument is converted to an \c "unsigned char", and the
           resulting character is written.
   - \c s  The \c "char *" argument is expected to be a pointer to an array
           of character type (pointer to a string).  Characters from
           the array are written up to (but not including) a
           terminating NUL character; if a precision is specified, no
           more than the number specified are written.  If a precision
           is given, no null character need be present; if the
           precision is not specified, or is greater than the size of
           the array, the array must contain a terminating NUL
           character.
   - \c %  A \c % is written.  No argument is converted.  The complete
           conversion specification is "%%".
   - \c eE The double argument is rounded and converted in the format
           \c "[-]d.ddde±dd" where there is one digit before the
           decimal-point character and the number of digits after it
           is equal to the precision; if the precision is missing, it
           is taken as 6; if the precision is zero, no decimal-point
           character appears.  An \e E conversion uses the letter \c 'E'
           (rather than \c 'e') to introduce the exponent.  The exponent
           always contains two digits; if the value is zero,
           the exponent is 00.
   - \c fF The double argument is rounded and converted to decimal notation
           in the format \c "[-]ddd.ddd", where the number of digits after the
           decimal-point character is equal to the precision specification.
           If the precision is missing, it is taken as 6; if the precision
           is explicitly zero, no decimal-point character appears.  If a
           decimal point appears, at least one digit appears before it.
   - \c gG The double argument is converted in style \c f or \c e (or
           \c F or \c E for \c G conversions).  The precision
           specifies the number of significant digits.  If the
           precision is missing, 6 digits are given; if the precision
           is zero, it is treated as 1.  Style \c e is used if the
           exponent from its conversion is less than -4 or greater
           than or equal to the precision.  Trailing zeros are removed
           from the fractional part of the result; a decimal point
           appears only if it is followed by at least one digit.
   - \c S  Similar to the \c s format, except the pointer is expected to
           point to a program-memory (ROM) string instead of a RAM string.

   In no case does a non-existent or small field width cause truncation of a
   numeric field; if the result of a conversion is wider than the field
   width, the field is expanded to contain the conversion result.

   Since the full implementation of all the mentioned features becomes
   fairly large, three different flavours of vfprintf() can be
   selected using linker options.  The default vfprintf() implements
   all the mentioned functionality except floating point conversions.
   A minimized version of vfprintf() is available that only implements
   the very basic integer and string conversion facilities, but only
   the \c # additional option can be specified using conversion
   flags (these flags are parsed correctly from the format
   specification, but then simply ignored).  This version can be
   requested using the following \ref gcc_minusW "compiler options":

   \code
   -Wl,-u,vfprintf -lprintf_min
   \endcode

   If the full functionality including the floating point conversions
   is required, the following options should be used:

   \code
   -Wl,-u,vfprintf -lprintf_flt -lm
   \endcode

   \par Limitations:
   - The specified width and precision can be at most 255.

   \par Notes:
   - For floating-point conversions, if you link default or minimized
     version of vfprintf(), the symbol \c ? will be output and double
     argument will be skiped. So you output below will not be crashed.
     For default version the width field and the "pad to left" ( symbol
     minus ) option will work in this case.
   - The \c hh length modifier is ignored (\c char argument is
     promouted to \c int). More exactly, this realization does not check
     the number of \c h symbols.
   - But the \c ll length modifier will to abort the output, as this
     realization does not operate \c long \c long arguments.
   - The variable width or precision field (an asterisk \c * symbol)
     is not realized and will to abort the output.

 */

extern int vfprintf(struct __file *__stream, const char *__fmt, va_list __ap);

/**
   Variant of \c vfprintf() that uses a \c fmt string that resides
   in program memory.
*/
extern int vfprintf_P(struct __file *__stream, const char *__fmt, va_list __ap);

/**
   The function \c fputc sends the character \c c (though given as type
   \c int) to \c stream.  It returns the character, or \c EOF in case
   an error occurred.
*/
extern int fputc(int __c, struct __file *__stream);



/* putc() function implementation, required by standard */
extern int putc(int __c, struct __file *__stream);

/* putchar() function implementation, required by standard */
extern int putchar(int __c);



/**
   The macro \c putc used to be a "fast" macro implementation with a
   functionality identical to fputc().  For space constraints, in
   \c avr-libc, it is just an alias for \c fputc.
*/


/**
   The macro \c putchar sends character \c c to \c stdout.
*/


/**
   The function \c printf performs formatted output to stream
   \c stdout.  See \c vfprintf() for details.
*/
extern int printf(const char *__fmt, ...);

/**
   Variant of \c printf() that uses a \c fmt string that resides
   in program memory.
*/
extern int printf_P(const char *__fmt, ...);

/**
   The function \c vprintf performs formatted output to stream
   \c stdout, taking a variable argument list as in vfprintf().

   See vfprintf() for details.
*/
extern int vprintf(const char *__fmt, va_list __ap);

/**
   Variant of \c printf() that sends the formatted characters
   to string \c s.
*/
extern int sprintf(char *__s, const char *__fmt, ...);

/**
   Variant of \c sprintf() that uses a \c fmt string that resides
   in program memory.
*/
extern int sprintf_P(char *__s, const char *__fmt, ...);

/**
   Like \c sprintf(), but instead of assuming \c s to be of infinite
   size, no more than \c n characters (including the trailing NUL
   character) will be converted to \c s.

   Returns the number of characters that would have been written to
   \c s if there were enough space.
*/
extern int snprintf(char *__s, size_t __n, const char *__fmt, ...);

/**
   Variant of \c snprintf() that uses a \c fmt string that resides
   in program memory.
*/
extern int snprintf_P(char *__s, size_t __n, const char *__fmt, ...);

/**
   Like \c sprintf() but takes a variable argument list for the
   arguments.
*/
extern int vsprintf(char *__s, const char *__fmt, va_list ap);

/**
   Variant of \c vsprintf() that uses a \c fmt string that resides
   in program memory.
*/
extern int vsprintf_P(char *__s, const char *__fmt, va_list ap);

/**
   Like \c vsprintf(), but instead of assuming \c s to be of infinite
   size, no more than \c n characters (including the trailing NUL
   character) will be converted to \c s.

   Returns the number of characters that would have been written to
   \c s if there were enough space.
*/
extern int vsnprintf(char *__s, size_t __n, const char *__fmt, va_list ap);

/**
   Variant of \c vsnprintf() that uses a \c fmt string that resides
   in program memory.
*/
extern int vsnprintf_P(char *__s, size_t __n, const char *__fmt, va_list ap);
/**
   The function \c fprintf performs formatted output to \c stream.
   See \c vfprintf() for details.
*/
extern int fprintf(struct __file *__stream, const char *__fmt, ...);

/**
   Variant of \c fprintf() that uses a \c fmt string that resides
   in program memory.
*/
extern int fprintf_P(struct __file *__stream, const char *__fmt, ...);

/**
   Write the string pointed to by \c str to stream \c stream.

   Returns 0 on success and EOF on error.
*/
extern int fputs(const char *__str, struct __file *__stream);

/**
   Variant of fputs() where \c str resides in program memory.
*/
extern int fputs_P(const char *__str, struct __file *__stream);

/**
   Write the string pointed to by \c str, and a trailing newline
   character, to \c stdout.
*/
extern int puts(const char *__str);

/**
   Variant of puts() where \c str resides in program memory.
*/
extern int puts_P(const char *__str);

/**
   Write \c nmemb objects, \c size bytes each, to \c stream.
   The first byte of the first object is referenced by \c ptr.

   Returns the number of objects successfully written, i. e.
   \c nmemb unless an output error occured.
 */
extern size_t fwrite(const void *__ptr, size_t __size, size_t __nmemb,
         struct __file *__stream);

/**
   The function \c fgetc reads a character from \c stream.  It returns
   the character, or \c EOF in case end-of-file was encountered or an
   error occurred.  The routines feof() or ferror() must be used to
   distinguish between both situations.
*/
extern int fgetc(struct __file *__stream);



/* getc() function implementation, required by standard */
extern int getc(struct __file *__stream);

/* getchar() function implementation, required by standard */
extern int getchar(void);



/**
   The macro \c getc used to be a "fast" macro implementation with a
   functionality identical to fgetc().  For space constraints, in
   \c avr-libc, it is just an alias for \c fgetc.
*/


/**
   The macro \c getchar reads a character from \c stdin.  Return
   values and error handling is identical to fgetc().
*/


/**
   The ungetc() function pushes the character \c c (converted to an
   unsigned char) back onto the input stream pointed to by \c stream.
   The pushed-back character will be returned by a subsequent read on
   the stream.

   Currently, only a single character can be pushed back onto the
   stream.
   
   The ungetc() function returns the character pushed back after the
   conversion, or \c EOF if the operation fails.  If the value of the
   argument \c c character equals \c EOF, the operation will fail and
   the stream will remain unchanged.
*/
extern int ungetc(int __c, struct __file *__stream);

/**
   Read at most <tt>size - 1</tt> bytes from \c stream, until a
   newline character was encountered, and store the characters in the
   buffer pointed to by \c str.  Unless an error was encountered while
   reading, the string will then be terminated with a \c NUL
   character.

   If an error was encountered, the function returns NULL and sets the
   error flag of \c stream, which can be tested using ferror().
   Otherwise, a pointer to the string will be returned.  */
extern char *fgets(char *__str, int __size, struct __file *__stream);

/**
   Similar to fgets() except that it will operate on stream \c stdin,
   and the trailing newline (if any) will not be stored in the string.
   It is the caller's responsibility to provide enough storage to hold
   the characters read.  */
extern char *gets(char *__str);

/**
   Read \c nmemb objects, \c size bytes each, from \c stream,
   to the buffer pointed to by \c ptr.

   Returns the number of objects successfully read, i. e.
   \c nmemb unless an input error occured or end-of-file was
   encountered.  feof() and ferror() must be used to distinguish
   between these two conditions.
 */
extern size_t fread(void *__ptr, size_t __size, size_t __nmemb,
        struct __file *__stream);

/**
   Clear the error and end-of-file flags of \c stream.
 */
extern void clearerr(struct __file *__stream);


/* fast inlined version of clearerr() */



/**
   Test the end-of-file flag of \c stream.  This flag can only be cleared
   by a call to clearerr().
 */
extern int feof(struct __file *__stream);


/* fast inlined version of feof() */



/**
   Test the error flag of \c stream.  This flag can only be cleared
   by a call to clearerr().
 */
extern int ferror(struct __file *__stream);


/* fast inlined version of ferror() */



extern int vfscanf(struct __file *__stream, const char *__fmt, va_list __ap);

/**
   Variant of vfscanf() using a \c fmt string in program memory.
 */
extern int vfscanf_P(struct __file *__stream, const char *__fmt, va_list __ap);

/**
   The function \c fscanf performs formatted input, reading the
   input data from \c stream.

   See vfscanf() for details.
 */
extern int fscanf(struct __file *__stream, const char *__fmt, ...);

/**
   Variant of fscanf() using a \c fmt string in program memory.
 */
extern int fscanf_P(struct __file *__stream, const char *__fmt, ...);

/**
   The function \c scanf performs formatted input from stream \c stdin.

   See vfscanf() for details.
 */
extern int scanf(const char *__fmt, ...);

/**
   Variant of scanf() where \c fmt resides in program memory.
 */
extern int scanf_P(const char *__fmt, ...);

/**
   The function \c vscanf performs formatted input from stream
   \c stdin, taking a variable argument list as in vfscanf().

   See vfscanf() for details.
*/
extern int vscanf(const char *__fmt, va_list __ap);

/**
   The function \c sscanf performs formatted input, reading the
   input data from the buffer pointed to by \c buf.

   See vfscanf() for details.
 */
extern int sscanf(const char *__buf, const char *__fmt, ...);

/**
   Variant of sscanf() using a \c fmt string in program memory.
 */
extern int sscanf_P(const char *__buf, const char *__fmt, ...);
# 938 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/stdio.h" 3
static __inline__ int fflush(struct __file *stream __attribute__((unused)))
{
 return 0;
}



}


/*@}*/

/*
 * The following constants are currently not used by avr-libc's
 * stdio subsystem.  They are defined here since the gcc build
 * environment expects them to be here.
 */
# 25 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Print.h" 2

# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/WString.h" 1
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
# 27 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Print.h" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Printable.h" 1
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




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/stdlib.h" 1 3
/* Copyright (c) 2002, Marek Michalkiewicz
   Copyright (c) 2004,2007 Joerg Wunsch

   Portions of documentation Copyright (c) 1990, 1991, 1993, 1994
   The Regents of the University of California.

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

  $Id$
*/
# 24 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Printable.h" 2

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
# 28 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Print.h" 2






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
# 27 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Stream.h" 2

// compatability macros for testing
/*
#define   getInt()            parseInt()
#define   getInt(ignore)    parseInt(ignore)
#define   getFloat()          parseFloat()
#define   getFloat(ignore)  parseFloat(ignore)
#define   getString( pre_string, post_string, buffer, length)
readBytesBetween( pre_string, terminator, buffer, length)
*/

// This enumeration provides the lookahead options for parseInt(), parseFloat()
// The rules set out here are used until either the first valid character is found
// or a time out occurs due to lack of input.
enum LookaheadMode{
    SKIP_ALL, // All invalid characters are ignored.
    SKIP_NONE, // Nothing is skipped, and the stream is not touched unless the first waiting character is valid.
    SKIP_WHITESPACE // Only tabs, spaces, line feeds & carriage returns are skipped.
};



class Stream : public Print
{
  protected:
    unsigned long _timeout; // number of milliseconds to wait for the next char before aborting timed read
    unsigned long _startMillis; // used for timeout measurement
    int timedRead(); // private method to read stream with timeout
    int timedPeek(); // private method to peek stream with timeout
    int peekNextDigit(LookaheadMode lookahead, bool detectDecimal); // returns the next numeric digit in the stream or -1 if timeout

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

  bool find(char target) { return find (&target, 1); }

  bool findUntil(char *target, char *terminator); // as find but search ends if the terminator string is found
  bool findUntil(uint8_t *target, char *terminator) { return findUntil((char *)target, terminator); }

  bool findUntil(char *target, size_t targetLen, char *terminate, size_t termLen); // as above but search ends if the terminate string is found
  bool findUntil(uint8_t *target, size_t targetLen, char *terminate, size_t termLen) {return findUntil((char *)target, targetLen, terminate, termLen); }

  long parseInt(LookaheadMode lookahead = SKIP_ALL, char ignore = '\x01' /* a char not found in a valid ASCII numeric field*/);
  // returns the first valid (long) integer value from the current position.
  // lookahead determines how parseInt looks ahead in the stream.
  // See LookaheadMode enumeration at the top of the file.
  // Lookahead is terminated by the first character that is not a valid part of an integer.
  // Once parsing commences, 'ignore' will be skipped in the stream.

  float parseFloat(LookaheadMode lookahead = SKIP_ALL, char ignore = '\x01' /* a char not found in a valid ASCII numeric field*/);
  // float version of parseInt

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
  long parseInt(char ignore) { return parseInt(SKIP_ALL, ignore); }
  float parseFloat(char ignore) { return parseFloat(SKIP_ALL, ignore); }
  // These overload exists for compatibility with any class that has derived
  // Stream and used parseFloat/Int with a custom ignore character. To keep
  // the public API simple, these overload remains protected.

  struct MultiTarget {
    const char *str; // string you're searching for
    size_t len; // length of string you're searching for
    size_t index; // index used by the search routine.
  };

  // This allows you to search for an arbitrary number of strings.
  // Returns index of the target that is found first or -1 if timeout occurs.
  int findMulti(struct MultiTarget *targets, int tCount);
};
# 30 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/HardwareSerial.h" 2

// Define constants and variables for buffering incoming serial data.  We're
// using a ring buffer (I think), in which head is the index of the location
// to which to write the next incoming character and tail is the index of the
// location from which to read.
// NOTE: a "power of 2" buffer size is reccomended to dramatically
//       optimize all the modulo operations for ring buffers.
// WARNING: When buffer sizes are increased to > 256, the buffer index
// variables are automatically increased in size, but the extra
// atomicity guards needed for that are not implemented. This will
// often work, but occasionally a race condition can occur that makes
// Serial behave erratically. See https://github.com/arduino/Arduino/issues/2405
# 59 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/HardwareSerial.h"
typedef uint8_t tx_buffer_index_t;




typedef uint8_t rx_buffer_index_t;


// Define config for Serial.begin(baud, config);
# 93 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/HardwareSerial.h"
class HardwareSerial : public Stream
{
  protected:
    volatile uint8_t * const _ubrrh;
    volatile uint8_t * const _ubrrl;
    volatile uint8_t * const _ucsra;
    volatile uint8_t * const _ucsrb;
    volatile uint8_t * const _ucsrc;
    volatile uint8_t * const _udr;
    // Has any byte been written to the UART since begin()
    bool _written;

    volatile rx_buffer_index_t _rx_buffer_head;
    volatile rx_buffer_index_t _rx_buffer_tail;
    volatile tx_buffer_index_t _tx_buffer_head;
    volatile tx_buffer_index_t _tx_buffer_tail;

    // Don't put any members after these buffers, since only the first
    // 32 bytes of this struct can be accessed quickly using the ldd
    // instruction.
    unsigned char _rx_buffer[64];
    unsigned char _tx_buffer[64];

  public:
    inline HardwareSerial(
      volatile uint8_t *ubrrh, volatile uint8_t *ubrrl,
      volatile uint8_t *ucsra, volatile uint8_t *ucsrb,
      volatile uint8_t *ucsrc, volatile uint8_t *udr);
    void begin(unsigned long baud) { begin(baud, 0x06); }
    void begin(unsigned long, uint8_t);
    void end();
    virtual int available(void);
    virtual int peek(void);
    virtual int read(void);
    int availableForWrite(void);
    virtual void flush(void);
    virtual size_t write(uint8_t);
    inline size_t write(unsigned long n) { return write((uint8_t)n); }
    inline size_t write(long n) { return write((uint8_t)n); }
    inline size_t write(unsigned int n) { return write((uint8_t)n); }
    inline size_t write(int n) { return write((uint8_t)n); }
    using Print::write; // pull in write(str) and write(buf, size) from Print
    operator bool() { return true; }

    // Interrupt handlers - Not intended to be called externally
    inline void _rx_complete_irq(void);
    void _tx_udr_empty_irq(void);
};






  extern HardwareSerial Serial1;
# 159 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/HardwareSerial.h"
extern void serialEventRun(void) __attribute__((weak));
# 225 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Arduino.h" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/USBAPI.h" 1
/*
  USBAPI.h
  Copyright (c) 2005-2014 Arduino.  All right reserved.

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
# 24 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/USBAPI.h" 2
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
# 25 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/USBAPI.h" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/eeprom.h" 1 3
/* Copyright (c) 2002, 2003, 2004, 2007 Marek Michalkiewicz
   Copyright (c) 2005, 2006 Bjoern Haase
   Copyright (c) 2008 Atmel Corporation
   Copyright (c) 2008 Wouter van Gulik
   Copyright (c) 2009 Dmitry Xmelkov
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
# 39 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/eeprom.h" 2 3
# 570 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/eeprom.h" 3
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
# 147 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stddef.h" 3 4
typedef int ptrdiff_t;
# 157 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stddef.h" 3 4
/* If this symbol has done its job, get rid of it.  */




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
# 412 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/lib/gcc/avr/4.8.1/include/stddef.h" 3 4
/* Offset of member MEMBER in a struct of type TYPE. */






/* Type whose alignment is supported in every context and is at least
   as great as that of any standard type not using alignment
   specifiers.  */
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;






  typedef decltype(nullptr) nullptr_t;
# 571 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/eeprom.h" 2 3


/** \defgroup avr_eeprom <avr/eeprom.h>: EEPROM handling
    \code #include <avr/eeprom.h> \endcode

    This header file declares the interface to some simple library
    routines suitable for handling the data EEPROM contained in the
    AVR microcontrollers.  The implementation uses a simple polled
    mode interface.  Applications that require interrupt-controlled
    EEPROM access to ensure that no time will be wasted in spinloops
    will have to deploy their own implementation.

    \par Notes:

    - In addition to the write functions there is a set of update ones.
    This functions read each byte first and skip the burning if the
    old value is the same with new.  The scaning direction is from
    high address to low, to obtain quick return in common cases.

    - All of the read/write functions first make sure the EEPROM is
    ready to be accessed.  Since this may cause long delays if a
    write operation is still pending, time-critical applications
    should first poll the EEPROM e. g. using eeprom_is_ready() before
    attempting any actual I/O.  But this functions are not wait until
    SELFPRGEN in SPMCSR becomes zero.  Do this manually, if your
    softwate contains the Flash burning.

    - As these functions modify IO registers, they are known to be
    non-reentrant.  If any of these functions are used from both,
    standard and interrupt context, the applications must ensure
    proper protection (e.g. by disabling interrupts before accessing
    them).

    - All write functions force erase_and_write programming mode.
    
    - For Xmega the EEPROM start address is 0, like other architectures.
    The reading functions add the 0x2000 value to use EEPROM mapping into
    data space.
 */


extern "C" {
# 623 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/eeprom.h" 3
/** \def EEMEM
    \ingroup avr_eeprom
    Attribute expression causing a variable to be allocated within the
    .eeprom section.	*/


/** \def eeprom_is_ready
    \ingroup avr_eeprom
    \returns 1 if EEPROM is ready for a new read/write operation, 0 if not.
 */
# 646 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/eeprom.h" 3
/** \def eeprom_busy_wait
    \ingroup avr_eeprom
    Loops until the eeprom is no longer busy.
    \returns Nothing.
 */



/** \ingroup avr_eeprom
    Read one byte from EEPROM address \a __p.
 */
uint8_t __eerd_byte_m32u4 (const uint8_t *__p) __attribute__((__pure__));

/** \ingroup avr_eeprom
    Read one 16-bit word (little endian) from EEPROM address \a __p.
 */
uint16_t __eerd_word_m32u4 (const uint16_t *__p) __attribute__((__pure__));

/** \ingroup avr_eeprom
    Read one 32-bit double word (little endian) from EEPROM address \a __p.
 */
uint32_t __eerd_dword_m32u4 (const uint32_t *__p) __attribute__((__pure__));

/** \ingroup avr_eeprom
    Read one float value (little endian) from EEPROM address \a __p.
 */
float __eerd_float_m32u4 (const float *__p) __attribute__((__pure__));

/** \ingroup avr_eeprom
    Read a block of \a __n bytes from EEPROM address \a __src to SRAM
    \a __dst.
 */
void __eerd_block_m32u4 (void *__dst, const void *__src, size_t __n);


/** \ingroup avr_eeprom
    Write a byte \a __value to EEPROM address \a __p.
 */
void __eewr_byte_m32u4 (uint8_t *__p, uint8_t __value);

/** \ingroup avr_eeprom
    Write a word \a __value to EEPROM address \a __p.
 */
void __eewr_word_m32u4 (uint16_t *__p, uint16_t __value);

/** \ingroup avr_eeprom
    Write a 32-bit double word \a __value to EEPROM address \a __p.
 */
void __eewr_dword_m32u4 (uint32_t *__p, uint32_t __value);

/** \ingroup avr_eeprom
    Write a float \a __value to EEPROM address \a __p.
 */
void __eewr_float_m32u4 (float *__p, float __value);

/** \ingroup avr_eeprom
    Write a block of \a __n bytes to EEPROM address \a __dst from \a __src.
    \note The argument order is mismatch with common functions like strcpy().
 */
void __eewr_block_m32u4 (const void *__src, void *__dst, size_t __n);


/** \ingroup avr_eeprom
    Update a byte \a __value to EEPROM address \a __p.
 */
void __eeupd_byte_m32u4 (uint8_t *__p, uint8_t __value);

/** \ingroup avr_eeprom
    Update a word \a __value to EEPROM address \a __p.
 */
void __eeupd_word_m32u4 (uint16_t *__p, uint16_t __value);

/** \ingroup avr_eeprom
    Update a 32-bit double word \a __value to EEPROM address \a __p.
 */
void __eeupd_dword_m32u4 (uint32_t *__p, uint32_t __value);

/** \ingroup avr_eeprom
    Update a float \a __value to EEPROM address \a __p.
 */
void __eeupd_float_m32u4 (float *__p, float __value);

/** \ingroup avr_eeprom
    Update a block of \a __n bytes to EEPROM address \a __dst from \a __src.
    \note The argument order is mismatch with common functions like strcpy().
 */
void __eeupd_block_m32u4 (const void *__src, void *__dst, size_t __n);


/** \name IAR C compatibility defines	*/
/*@{*/

/** \def _EEPUT
    \ingroup avr_eeprom
    Write a byte to EEPROM. Compatibility define for IAR C.	*/


/** \def __EEPUT
    \ingroup avr_eeprom
    Write a byte to EEPROM. Compatibility define for IAR C.	*/


/** \def _EEGET
    \ingroup avr_eeprom
    Read a byte from EEPROM. Compatibility define for IAR C.	*/


/** \def __EEGET
    \ingroup avr_eeprom
    Read a byte from EEPROM. Compatibility define for IAR C.	*/


/*@}*/


}
# 26 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/USBAPI.h" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/interrupt.h" 1 3
/* Copyright (c) 2002,2005,2007 Marek Michalkiewicz
   Copyright (c) 2007, Dean Camera

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
# 27 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/USBAPI.h" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/util/delay.h" 1 3
/* Copyright (c) 2002, Marek Michalkiewicz
   Copyright (c) 2004,2005,2007 Joerg Wunsch
   Copyright (c) 2007  Florin-Viorel Petrov
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
# 42 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/util/delay.h" 3
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
# 43 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/util/delay.h" 2 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/util/delay_basic.h" 1 3
/* Copyright (c) 2002, Marek Michalkiewicz
   Copyright (c) 2007 Joerg Wunsch
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
# 38 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/util/delay_basic.h" 2 3


static inline void _delay_loop_1(uint8_t __count) __attribute__((always_inline));
static inline void _delay_loop_2(uint16_t __count) __attribute__((always_inline));


/** \file */
/** \defgroup util_delay_basic <util/delay_basic.h>: Basic busy-wait delay loops
    \code
    #include <util/delay_basic.h>
    \endcode

    The functions in this header file implement simple delay loops
    that perform a busy-waiting.  They are typically used to
    facilitate short delays in the program execution.  They are
    implemented as count-down loops with a well-known CPU cycle
    count per loop iteration.  As such, no other processing can
    occur simultaneously.  It should be kept in mind that the
    functions described here do not disable interrupts.

    In general, for long delays, the use of hardware timers is
    much preferrable, as they free the CPU, and allow for
    concurrent processing of other events while the timer is
    running.  However, in particular for very short delays, the
    overhead of setting up a hardware timer is too much compared
    to the overall delay time.

    Two inline functions are provided for the actual delay algorithms.

*/

/** \ingroup util_delay_basic

    Delay loop using an 8-bit counter \c __count, so up to 256
    iterations are possible.  (The value 256 would have to be passed
    as 0.)  The loop executes three CPU cycles per iteration, not
    including the overhead the compiler needs to setup the counter
    register.

    Thus, at a CPU speed of 1 MHz, delays of up to 768 microseconds
    can be achieved.
*/
void
_delay_loop_1(uint8_t __count)
{
 __asm__ volatile (
  "1: dec %0" "\n\t"
  "brne 1b"
  : "=r" (__count)
  : "0" (__count)
 );
}

/** \ingroup util_delay_basic

    Delay loop using a 16-bit counter \c __count, so up to 65536
    iterations are possible.  (The value 65536 would have to be
    passed as 0.)  The loop executes four CPU cycles per iteration,
    not including the overhead the compiler requires to setup the
    counter register pair.

    Thus, at a CPU speed of 1 MHz, delays of up to about 262.1
    milliseconds can be achieved.
 */
void
_delay_loop_2(uint16_t __count)
{
 __asm__ volatile (
  "1: sbiw %0,1" "\n\t"
  "brne 1b"
  : "=w" (__count)
  : "0" (__count)
 );
}
# 44 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/util/delay.h" 2 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/math.h" 1 3
/* Copyright (c) 2002,2007-2009 Michael Stumpf

   Portions of documentation Copyright (c) 1990 - 1994
   The Regents of the University of California.

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
   math.h - mathematical functions

   Author : Michael Stumpf
            Michael.Stumpf@t-online.de

   __ATTR_CONST__ added by marekm@linux.org.pl for functions
   that "do not examine any values except their arguments, and have
   no effects except the return value", for better optimization by gcc.
 */
# 45 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/util/delay.h" 2 3

/** \file */
/** \defgroup util_delay <util/delay.h>: Convenience functions for busy-wait delay loops
    \code
    #define F_CPU 1000000UL  // 1 MHz
    //#define F_CPU 14.7456E6
    #include <util/delay.h>
    \endcode

    \note As an alternative method, it is possible to pass the
    F_CPU macro down to the compiler from the Makefile.
    Obviously, in that case, no \c \#define statement should be
    used.

    The functions in this header file are wrappers around the basic
    busy-wait functions from <util/delay_basic.h>.  They are meant as
    convenience functions where actual time values can be specified
    rather than a number of cycles to wait for.  The idea behind is
    that compile-time constant expressions will be eliminated by
    compiler optimization so floating-point expressions can be used
    to calculate the number of delay cycles needed based on the CPU
    frequency passed by the macro F_CPU.

    \note In order for these functions to work as intended, compiler
    optimizations <em>must</em> be enabled, and the delay time
    <em>must</em> be an expression that is a known constant at
    compile-time.  If these requirements are not met, the resulting
    delay will be much longer (and basically unpredictable), and
    applications that otherwise do not use floating-point calculations
    will experience severe code bloat by the floating-point library
    routines linked into the application.

    The functions available allow the specification of microsecond, and
    millisecond delays directly, using the application-supplied macro
    F_CPU as the CPU clock frequency (in Hertz).

*/


static inline void _delay_us(double __us) __attribute__((always_inline));
static inline void _delay_ms(double __ms) __attribute__((always_inline));
# 101 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/util/delay.h" 3
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/math.h" 1 3
/* Copyright (c) 2002,2007-2009 Michael Stumpf

   Portions of documentation Copyright (c) 1990 - 1994
   The Regents of the University of California.

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
   math.h - mathematical functions

   Author : Michael Stumpf
            Michael.Stumpf@t-online.de

   __ATTR_CONST__ added by marekm@linux.org.pl for functions
   that "do not examine any values except their arguments, and have
   no effects except the return value", for better optimization by gcc.
 */
# 102 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/util/delay.h" 2 3


/**
   \ingroup util_delay

   Perform a delay of \c __ms milliseconds, using _delay_loop_2().

   The macro F_CPU is supposed to be defined to a
   constant defining the CPU clock frequency (in Hertz).

   The maximal possible delay is 262.14 ms / F_CPU in MHz.

   When the user request delay which exceed the maximum possible one,
   _delay_ms() provides a decreased resolution functionality. In this
   mode _delay_ms() will work with a resolution of 1/10 ms, providing
   delays up to 6.5535 seconds (independent from CPU frequency).  The
   user will not be informed about decreased resolution.

   If the avr-gcc toolchain has __builtin_avr_delay_cycles(unsigned long)
   support, maximal possible delay is 4294967.295 ms/ F_CPU in MHz. For
   values greater than the maximal possible delay, overflows results in
   no delay i.e., 0ms.

   Conversion of __us into clock cycles may not always result in integer.
   By default, the clock cycles rounded up to next integer. This ensures that
   the user gets atleast __us microseconds of delay.

   Alternatively, user can define __DELAY_ROUND_DOWN__ and __DELAY_ROUND_CLOSEST__
   to round down and round to closest integer.

   Note: The new implementation of _delay_ms(double __ms) with 
    __builtin_avr_delay_cycles(unsigned long) support is not backward compatible. 
   User can define __DELAY_BACKWARD_COMPATIBLE__ to get a backward compatible delay.
   Also, the backward compatible
   algorithm will be chosen if the code is compiled in a <em>freestanding
   environment</em> (GCC option \c -ffreestanding), as the math functions
   required for rounding are not available to the compiler then.

 */
void
_delay_ms(double __ms)
{
 double __tmp ;



 uint32_t __ticks_dc;
 extern void __builtin_avr_delay_cycles(unsigned long);
 __tmp = ((16000000L) / 1e3) * __ms;
# 159 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/util/delay.h" 3
  //round up by default
  __ticks_dc = (uint32_t)(ceil(fabs(__tmp)));


 __builtin_avr_delay_cycles(__ticks_dc);
# 186 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/util/delay.h" 3
}

/**
   \ingroup util_delay

   Perform a delay of \c __us microseconds, using _delay_loop_1().

   The macro F_CPU is supposed to be defined to a
   constant defining the CPU clock frequency (in Hertz).

   The maximal possible delay is 768 us / F_CPU in MHz.

   If the user requests a delay greater than the maximal possible one,
   _delay_us() will automatically call _delay_ms() instead.  The user
   will not be informed about this case.

   If the avr-gcc toolchain has __builtin_avr_delay_cycles(unsigned long)
   support, maximal possible delay is 4294967.295 us/ F_CPU in MHz. For
   values greater than the maximal possible delay, overflow results in
   no delay i.e., 0us.
  
   Conversion of __us into clock cycles may not always result in integer.
   By default, the clock cycles rounded up to next integer. This ensures that
   the user gets atleast __us microseconds of delay.

   Alternatively, user can define __DELAY_ROUND_DOWN__ and __DELAY_ROUND_CLOSEST__
   to round down and round to closest integer.
 
   Note: The new implementation of _delay_us(double __us) with 
    __builtin_avr_delay_cycles(unsigned long) support is not backward compatible.
   User can define __DELAY_BACKWARD_COMPATIBLE__ to get a backward compatible delay.
   Also, the backward compatible
   algorithm will be chosen if the code is compiled in a <em>freestanding
   environment</em> (GCC option \c -ffreestanding), as the math functions
   required for rounding are not available to the compiler then.

 */
void
_delay_us(double __us)
{
 double __tmp ;



 uint32_t __ticks_dc;
 extern void __builtin_avr_delay_cycles(unsigned long);
 __tmp = ((16000000L) / 1e6) * __us;
# 241 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/util/delay.h" 3
  //round up by default
  __ticks_dc = (uint32_t)(ceil(fabs(__tmp)));


 __builtin_avr_delay_cycles(__ticks_dc);
# 268 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/util/delay.h" 3
}
# 28 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/USBAPI.h" 2

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Arduino.h" 1
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
# 34 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/USBAPI.h" 2

// This definitions is usefull if you want to reduce the EP_SIZE to 16
// at the moment only 64 and 16 as EP_SIZE for all EPs are supported except the control endpoint






# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/USBDesc.h" 1
/*
   Copyright (c) 2011, Peter Barrett
   Copyright (c) 2015, Arduino LLC

   Permission to use, copy, modify, and/or distribute this software for
   any purpose with or without fee is hereby granted, provided that the
   above copyright notice and this permission notice appear in all copies.

   THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
   WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
   WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR
   BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES
   OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
   WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
   ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
   SOFTWARE.
 */
# 44 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/USBAPI.h" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/USBCore.h" 1

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




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/USBAPI.h" 1
/*
  USBAPI.h
  Copyright (c) 2005-2014 Arduino.  All right reserved.

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
# 22 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/USBCore.h" 2

//	Standard requests
# 36 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/USBCore.h"
// bmRequestType
# 56 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/USBCore.h"
//	Class requests
# 66 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/USBCore.h"
//	Descriptors
# 79 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/USBCore.h"
// usb_20.pdf Table 9.6 Standard Feature Selectors




// usb_20.pdf Figure 9-4. Information Returned by a GetStatus() Request to a Device
# 98 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/USBCore.h"
// bMaxPower in Configuration Descriptor


// bEndpointAddress in Endpoint Descriptor
# 129 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/USBCore.h"
//	Device
typedef struct {
 u8 len; // 18
 u8 dtype; // 1 USB_DEVICE_DESCRIPTOR_TYPE
 u16 usbVersion; // 0x200
 u8 deviceClass;
 u8 deviceSubClass;
 u8 deviceProtocol;
 u8 packetSize0; // Packet 0
 u16 idVendor;
 u16 idProduct;
 u16 deviceVersion; // 0x100
 u8 iManufacturer;
 u8 iProduct;
 u8 iSerialNumber;
 u8 bNumConfigurations;
} DeviceDescriptor;

//	Config
typedef struct {
 u8 len; // 9
 u8 dtype; // 2
 u16 clen; // total length
 u8 numInterfaces;
 u8 config;
 u8 iconfig;
 u8 attributes;
 u8 maxPower;
} ConfigDescriptor;

//	String

//	Interface
typedef struct
{
 u8 len; // 9
 u8 dtype; // 4
 u8 number;
 u8 alternate;
 u8 numEndpoints;
 u8 interfaceClass;
 u8 interfaceSubClass;
 u8 protocol;
 u8 iInterface;
} InterfaceDescriptor;

//	Endpoint
typedef struct
{
 u8 len; // 7
 u8 dtype; // 5
 u8 addr;
 u8 attr;
 u16 packetSize;
 u8 interval;
} EndpointDescriptor;

// Interface Association Descriptor
// Used to bind 2 interfaces together in CDC compostite device
typedef struct
{
 u8 len; // 8
 u8 dtype; // 11
 u8 firstInterface;
 u8 interfaceCount;
 u8 functionClass;
 u8 funtionSubClass;
 u8 functionProtocol;
 u8 iInterface;
} IADDescriptor;

//	CDC CS interface descriptor
typedef struct
{
 u8 len; // 5
 u8 dtype; // 0x24
 u8 subtype;
 u8 d0;
 u8 d1;
} CDCCSInterfaceDescriptor;

typedef struct
{
 u8 len; // 4
 u8 dtype; // 0x24
 u8 subtype;
 u8 d0;
} CDCCSInterfaceDescriptor4;

typedef struct
{
    u8 len;
    u8 dtype; // 0x24
    u8 subtype; // 1
    u8 bmCapabilities;
    u8 bDataInterface;
} CMFunctionalDescriptor;

typedef struct
{
    u8 len;
    u8 dtype; // 0x24
    u8 subtype; // 1
    u8 bmCapabilities;
} ACMFunctionalDescriptor;

typedef struct
{
 //	IAD
 IADDescriptor iad; // Only needed on compound device

 //	Control
 InterfaceDescriptor cif; // 
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
# 45 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/USBAPI.h" 2

//================================================================================
//================================================================================
//	USB
# 58 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/USBAPI.h"
class USBDevice_
{
public:
 USBDevice_();
 bool configured();

 void attach();
 void detach(); // Serial port goes down too...
 void poll();
 bool wakeupHost(); // returns false, when wakeup cannot be processed
};
extern USBDevice_ USBDevice;

//================================================================================
//================================================================================
//	Serial over CDC (Serial1 is the physical port)

struct ring_buffer;
# 88 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/USBAPI.h"
class Serial_ : public Stream
{
private:
 int peek_buffer;
public:
 Serial_() { peek_buffer = -1; };
 void begin(unsigned long);
 void begin(unsigned long, uint8_t);
 void end(void);

 virtual int available(void);
 virtual int peek(void);
 virtual int read(void);
 int availableForWrite(void);
 virtual void flush(void);
 virtual size_t write(uint8_t);
 virtual size_t write(const uint8_t*, size_t);
 using Print::write; // pull in write(str) and write(buf, size) from Print
 operator bool();

 volatile uint8_t _rx_buffer_head;
 volatile uint8_t _rx_buffer_tail;
 unsigned char _rx_buffer[64];

 // This method allows processing "SEND_BREAK" requests sent by
 // the USB host. Those requests indicate that the host wants to
 // send a BREAK signal and are accompanied by a single uint16_t
 // value, specifying the duration of the break. The value 0
 // means to end any current break, while the value 0xffff means
 // to start an indefinite break.
 // readBreak() will return the value of the most recent break
 // request, but will return it at most once, returning -1 when
 // readBreak() is called again (until another break request is
 // received, which is again returned once).
 // This also mean that if two break requests are received
 // without readBreak() being called in between, the value of the
 // first request is lost.
 // Note that the value returned is a long, so it can return
 // 0-0xffff as well as -1.
 int32_t readBreak();

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
extern Serial_ Serial;



//================================================================================
//================================================================================
//  Low level API

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
int CDC_GetDescriptor(int i);
bool CDC_Setup(USBSetup& setup);

//================================================================================
//================================================================================





int USB_SendControl(uint8_t flags, const void* d, int len);
int USB_RecvControl(void* d, int len);

uint8_t USB_Available(uint8_t ep);
uint8_t USB_SendSpace(uint8_t ep);
int USB_Send(uint8_t ep, const void* data, int len); // blocking
int USB_Recv(uint8_t ep, void* data, int len); // non-blocking
int USB_Recv(uint8_t ep); // non-blocking
void USB_Flush(uint8_t ep);
# 226 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Arduino.h" 2




uint16_t makeWord(uint16_t w);
uint16_t makeWord(byte h, byte l);



unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout = 1000000L);
unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout = 1000000L);

void tone(uint8_t _pin, unsigned int frequency, unsigned long duration = 0);
void noTone(uint8_t _pin);

// WMath prototypes
long random(long);
long random(long, long);
void randomSeed(unsigned long);
long map(long, long, long, long, long);



# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/variants/micro/pins_arduino.h" 1
/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
*/

# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/variants/micro/../leonardo/pins_arduino.h" 1
/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
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
# 27 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/variants/micro/../leonardo/pins_arduino.h" 2

// Workaround for wrong definitions in "iom32u4.h".
// This should be fixed in the AVR toolchain.
# 100 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/variants/micro/../leonardo/pins_arduino.h"
static const uint8_t SDA = 2;
static const uint8_t SCL = 3;




// Map SPI port to 'new' pins D14..D17
static const uint8_t SS = 17;
static const uint8_t MOSI = 16;
static const uint8_t MISO = 14;
static const uint8_t SCK = 15;

// Mapping of analog pins as digital I/O
// A6-A11 share with digital pins
static const uint8_t A0 = 18;
static const uint8_t A1 = 19;
static const uint8_t A2 = 20;
static const uint8_t A3 = 21;
static const uint8_t A4 = 22;
static const uint8_t A5 = 23;
static const uint8_t A6 = 24; // D4
static const uint8_t A7 = 25; // D6
static const uint8_t A8 = 26; // D8
static const uint8_t A9 = 27; // D9
static const uint8_t A10 = 28; // D10
static const uint8_t A11 = 29; // D12






//	__AVR_ATmega32U4__ has an unusual mapping of pins to channels
extern const uint8_t __attribute__((__progmem__)) analog_pin_to_channel_PGM[];
# 346 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/variants/micro/../leonardo/pins_arduino.h"
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





// Alias SerialUSB to Serial
# 24 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/variants/micro/pins_arduino.h" 2
# 250 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Arduino.h" 2
# 2 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/build/sketch/sysmanager.ino.cpp" 2
# 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/build/sketch/sysmanager.ino.cpp"
# 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
//---------- I N C L U D E S --------------------------------------------------
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
# 3 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/interrupt.h" 1 3
/* Copyright (c) 2002,2005,2007 Marek Michalkiewicz
   Copyright (c) 2007, Dean Camera

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
# 4 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/sleep.h" 1 3
/* Copyright (c) 2002, 2004 Theodore A. Roth
   Copyright (c) 2004, 2007, 2008 Eric B. Weddington
   Copyright (c) 2005, 2006, 2007 Joerg Wunsch
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
# 39 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/sleep.h" 2 3



/** \file */

/** \defgroup avr_sleep <avr/sleep.h>: Power Management and Sleep Modes

    \code #include <avr/sleep.h>\endcode

    Use of the \c SLEEP instruction can allow an application to reduce its
    power comsumption considerably. AVR devices can be put into different
    sleep modes. Refer to the datasheet for the details relating to the device
    you are using.

    There are several macros provided in this header file to actually
    put the device into sleep mode.  The simplest way is to optionally
    set the desired sleep mode using \c set_sleep_mode() (it usually
    defaults to idle mode where the CPU is put on sleep but all
    peripheral clocks are still running), and then call
    \c sleep_mode(). This macro automatically sets the sleep enable bit, goes 
    to sleep, and clears the sleep enable bit.
    
    Example:
    \code
    #include <avr/sleep.h>

    ...
      set_sleep_mode(<mode>);
      sleep_mode();
    \endcode
    
    Note that unless your purpose is to completely lock the CPU (until a 
    hardware reset), interrupts need to be enabled before going to sleep.

    As the \c sleep_mode() macro might cause race conditions in some
    situations, the individual steps of manipulating the sleep enable
    (SE) bit, and actually issuing the \c SLEEP instruction, are provided
    in the macros \c sleep_enable(), \c sleep_disable(), and
    \c sleep_cpu().  This also allows for test-and-sleep scenarios that
    take care of not missing the interrupt that will awake the device
    from sleep.

    Example:
    \code
    #include <avr/interrupt.h>
    #include <avr/sleep.h>

    ...
      set_sleep_mode(<mode>);
      cli();
      if (some_condition)
      {
        sleep_enable();
        sei();
        sleep_cpu();
        sleep_disable();
      }
      sei();
    \endcode

    This sequence ensures an atomic test of \c some_condition with
    interrupts being disabled.  If the condition is met, sleep mode
    will be prepared, and the \c SLEEP instruction will be scheduled
    immediately after an \c SEI instruction.  As the intruction right
    after the \c SEI is guaranteed to be executed before an interrupt
    could trigger, it is sure the device will really be put to sleep.

    Some devices have the ability to disable the Brown Out Detector (BOD) before 
    going to sleep. This will also reduce power while sleeping. If the
    specific AVR device has this ability then an additional macro is defined:
    \c sleep_bod_disable(). This macro generates inlined assembly code
    that will correctly implement the timed sequence for disabling the BOD
    before sleeping. However, there is a limited number of cycles after the
    BOD has been disabled that the device can be put into sleep mode, otherwise
    the BOD will not truly be disabled. Recommended practice is to disable
    the BOD (\c sleep_bod_disable()), set the interrupts (\c sei()), and then
    put the device to sleep (\c sleep_cpu()), like so:

    \code
    #include <avr/interrupt.h>
    #include <avr/sleep.h>

    ...
      set_sleep_mode(<mode>);
      cli();
      if (some_condition)
      {
        sleep_enable();
        sleep_bod_disable();
        sei();
        sleep_cpu();
        sleep_disable();
      }
      sei();
    \endcode
*/


/* Define an internal sleep control register and an internal sleep enable bit mask. */
# 162 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/sleep.h" 3
/* Define set_sleep_mode() and sleep mode values per device. */
# 640 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/sleep.h" 3
/** \ingroup avr_sleep

    Put the device in sleep mode. How the device is brought out of sleep mode
    depends on the specific mode selected with the set_sleep_mode() function.
    See the data sheet for your device for more details. */
# 683 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/sleep.h" 3
/** \ingroup avr_sleep

    Put the device into sleep mode.  The SE bit must be set
    beforehand, and it is recommended to clear it afterwards.
*/
# 755 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/sleep.h" 3
/*@}*/
# 5 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/power.h" 1 3
/* Copyright (c) 2006, 2007, 2008  Eric B. Weddington
   Copyright (c) 2011 Frédéric Nadeau
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
# 36 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/power.h" 2 3



/** \file */
/** \defgroup avr_power <avr/power.h>: Power Reduction Management

\code #include <avr/power.h>\endcode

Many AVRs contain a Power Reduction Register (PRR) or Registers (PRRx) that 
allow you to reduce power consumption by disabling or enabling various on-board 
peripherals as needed. Some devices have the XTAL Divide Control Register
(XDIV) which offer similar functionality as System Clock Prescale
Register (CLKPR).

There are many macros in this header file that provide an easy interface
to enable or disable on-board peripherals to reduce power. See the table below.

\note Not all AVR devices have a Power Reduction Register (for example
the ATmega8). On those devices without a Power Reduction Register, the
power reduction macros are not available..

\note Not all AVR devices contain the same peripherals (for example, the LCD
interface), or they will be named differently (for example, USART and 
USART0). Please consult your device's datasheet, or the header file, to 
find out which macros are applicable to your device.

\note For device using the XTAL Divide Control Register (XDIV), when prescaler
is used, Timer/Counter0 can only be used in asynchronous mode. Keep in mind
that Timer/Counter0 source shall be less than ¼th of peripheral clock.
Therefore, when using a typical 32.768 kHz crystal, one shall not scale
the clock below 131.072 kHz.

*/


/** \addtogroup avr_power

\anchor avr_powermacros
<small>
<center>
<table border="3">
  <tr>
    <td width="10%"><strong>Power Macro</strong></td>
    <td width="15%"><strong>Description</strong></td>
    <td width="75%"><strong>Applicable for device</strong></td>
  </tr>

  <tr>
   <td>power_aca_disable()</td>
    <td> Disable The Analog Comparator On PortA </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_aca_enable()</td>
    <td> Enable The Analog Comparator On PortA </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_acb_disable()</td>
    <td> Disable The Analog Comparator On PortB </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_acb_enable()</td>
    <td> Enable The Analog Comparator On PortB </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_adc_disable()</td>
     <td>Disable the Analog to Digital Converter module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561, ATmega128RFA1, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega32U4, ATmega16U4, ATmega32U6, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, AT90PWM81, AT90PWM161, ATmega165, ATmega165A, ATmega165P, ATmega165PA, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega645A, ATmega645P, ATmega6450, ATmega6450A, ATmega6450P, ATmega169, ATmega169A, ATmega169P, ATmega169PA, ATmega329, ATmega329A, ATmega329P, ATmega329PA, ATmega3290, ATmega3290A, ATmega3290P, ATmega3290PA, ATmega649, ATmega649A, ATmega649P, ATmega6490, ATmega6490A, ATmega6490P, ATmega164A, ATmega164P, ATmega324A, ATmega324P, ATmega324PA, ATmega644P, ATmega644A, ATmega644PA, ATmega644, ATmega164PA, ATmega48, ATmega48A, ATmega48PA, ATmega48P, ATmega48PB, ATmega88, ATmega88A, ATmega88P, ATmega88PA, ATmega88PB, ATmega168, ATmega168A, ATmega168P, ATmega168PA, ATmega168PB, ATmega328, ATmega328P, ATtiny48, ATtiny88, ATtiny828, ATtiny441, ATtiny24, ATtiny24A, ATtiny44, ATtiny44A, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny261A, ATtiny461, ATtiny461A, ATtiny861, ATtiny861A, ATtiny43U, ATmega1284, ATmega1284P, ATmega16M1, ATmega32C1, ATmega32M1, ATmega64C1, ATmega64M1, ATtiny167, ATtiny87, ATA5505, ATA5272, ATA6612C, ATA6613C, ATA6614Q, ATA6616C, ATA6617C, ATA664251, ATtiny1634, ATtiny4, ATtiny5, ATtiny9, ATtiny10, ATtiny13A, ATtiny20, ATtiny40</td>
  </tr>

  <tr>
   <td>power_adc_enable()</td>
     <td>Enable the Analog to Digital Converter module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561, ATmega128RFA1, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega32U4, ATmega16U4, ATmega32U6, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, AT90PWM81, AT90PWM161, ATmega165, ATmega165A, ATmega165P, ATmega165PA, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega645A, ATmega645P, ATmega6450, ATmega6450A, ATmega6450P, ATmega169, ATmega169A, ATmega169P, ATmega169PA, ATmega329, ATmega329A, ATmega329P, ATmega329PA, ATmega3290, ATmega3290A, ATmega3290P, ATmega3290PA, ATmega649, ATmega649A, ATmega649P, ATmega6490, ATmega6490A, ATmega6490P, ATmega164A, ATmega164P, ATmega324A, ATmega324P, ATmega324PA, ATmega644P, ATmega644A, ATmega644PA, ATmega644, ATmega164PA, ATmega48, ATmega48A, ATmega48PA, ATmega48P, ATmega48PB, ATmega88, ATmega88A, ATmega88P, ATmega88PA, ATmega88PB, ATmega168, ATmega168A, ATmega168P, ATmega168PA, ATmega168PB, ATmega328, ATmega328P, ATtiny48, ATtiny88, ATtiny828, ATtiny441, ATtiny24, ATtiny24A, ATtiny44, ATtiny44A, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny261A, ATtiny461, ATtiny461A, ATtiny861, ATtiny861A, ATtiny43U, ATmega1284, ATmega1284P, ATmega16M1, ATmega32C1, ATmega32M1, ATmega64C1, ATmega64M1, ATtiny167, ATtiny87, ATA5505, ATA5272, ATA6612C, ATA6613C, ATA6614Q, ATA6616C, ATA6617C, ATA664251, ATtiny1634, ATtiny4, ATtiny5, ATtiny9, ATtiny10, ATtiny13A, ATtiny20, ATtiny40</td>
  </tr>

  <tr>
   <td>power_adca_disable()</td>
    <td> Disable the Analog to Digital Converter module On PortA </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_adca_enable()</td>
    <td> Enable the Analog to Digital Converter module On PortA </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_adcb_disable()</td>
    <td> Disable the Analog to Digital Converter module On PortB </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_adcb_enable()</td>
    <td> Enable the Analog to Digital Converter module On PortB </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_aes_disable()</td>
    <td> Disable the AES module </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega32A4U, ATxmega32A4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega192A3, ATxmega192A3U, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3, AT90SCR100</td>
  </tr>

  <tr>
   <td>power_aes_enable()</td>
    <td> Enable the AES module </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega32A4U, ATxmega32A4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega192A3, ATxmega192A3U, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3, AT90SCR100</td>
  </tr>

  <tr>
   <td>power_all_disable()</td>
     <td>Disable all modules.</td>
    <td>ATxmega384C3, ATxmega256A3BU, ATxmega16A4U, ATxmega32A4U, ATxmega64A3U, ATxmega64A4U, ATxmega128A3U, ATxmega128A4U, ATxmega192A3U, ATxmega256A3U, ATxmega384C3, ATxmega256A3BU, ATxmega16A4U, ATxmega32A4U, ATxmega64A3U, ATxmega64A4U, ATxmega128A3U, ATxmega128A4U, ATxmega192A3U, ATxmega256A3U, ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega64D4, ATxmega128D4, ATxmega16D4, ATxmega32D4, ATxmega32D3, ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3, ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561, ATmega128RFA1, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega32U4, ATmega16U4, ATmega32U6, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, AT90PWM81, AT90PWM161, ATmega165, ATmega165A, ATmega165P, ATmega165PA, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega645A, ATmega645P, ATmega6450, ATmega6450A, ATmega6450P, ATmega169, ATmega169A, ATmega169P, ATmega169PA, ATmega329, ATmega329A, ATmega329P, ATmega329PA, ATmega3290, ATmega3290A, ATmega3290P, ATmega3290PA, ATmega649, ATmega649A, ATmega649P, ATmega6490, ATmega6490A, ATmega6490P, ATmega164A, ATmega164P, ATmega324A, ATmega324P, ATmega324PA, ATmega644P, ATmega644A, ATmega644PA, ATmega644, ATmega164PA, ATmega406, ATtiny828, ATtiny828, ATtiny441, ATtiny24, ATtiny24A, ATtiny44, ATtiny44A, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny261A, ATtiny461, ATtiny461A, ATtiny861, ATtiny861A, ATtiny43U, ATmega1284, ATmega1284P, ATmega32HVB, ATmega32HVBrevB, ATmega16HVB, ATmega16HVBrevB, ATA5790, ATA5795, ATmega16M1, ATmega32C1, ATmega32M1, ATmega64C1, ATmega64M1, ATtiny167, ATtiny87, ATA5505, ATA5272, ATA6616C, ATA6617C, ATA664251, ATtiny1634, AT90USB82, AT90USB162, ATmega8U2, ATmega16U2, ATmega32U2, AT90SCR100, ATtiny4, ATtiny5, ATtiny9, ATtiny10, ATtiny13A, ATtiny20, ATtiny40</td>
  </tr>

  <tr>
   <td>power_all_enable()</td>
     <td>Enable all modules.</td>
    <td>ATxmega384C3, ATxmega256A3BU, ATxmega16A4U, ATxmega32A4U, ATxmega64A3U, ATxmega64A4U, ATxmega128A3U, ATxmega128A4U, ATxmega192A3U, ATxmega256A3U, ATxmega384C3, ATxmega256A3BU, ATxmega16A4U, ATxmega32A4U, ATxmega64A3U, ATxmega64A4U, ATxmega128A3U, ATxmega128A4U, ATxmega192A3U, ATxmega256A3U, ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega64D4, ATxmega128D4, ATxmega16D4, ATxmega32D4, ATxmega32D3, ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3, ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561, ATmega128RFA1, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega32U4, ATmega16U4, ATmega32U6, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, AT90PWM81, AT90PWM161, ATmega165, ATmega165A, ATmega165P, ATmega165PA, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega645A, ATmega645P, ATmega6450, ATmega6450A, ATmega6450P, ATmega169, ATmega169A, ATmega169P, ATmega169PA, ATmega329, ATmega329A, ATmega329P, ATmega329PA, ATmega3290, ATmega3290A, ATmega3290P, ATmega3290PA, ATmega649, ATmega649A, ATmega649P, ATmega6490, ATmega6490A, ATmega6490P, ATmega164A, ATmega164P, ATmega324A, ATmega324P, ATmega324PA, ATmega644P, ATmega644A, ATmega644PA, ATmega644, ATmega164PA, ATmega406, ATtiny828, ATtiny828, ATtiny441, ATtiny24, ATtiny24A, ATtiny44, ATtiny44A, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny261A, ATtiny461, ATtiny461A, ATtiny861, ATtiny861A, ATtiny43U, ATmega1284, ATmega1284P, ATmega32HVB, ATmega32HVBrevB, ATmega16HVB, ATmega16HVBrevB, ATA5790, ATA5795, ATmega16M1, ATmega32C1, ATmega32M1, ATmega64C1, ATmega64M1, ATtiny167, ATtiny87, ATA5505, ATA5272, ATA6616C, ATA6617C, ATA664251, ATtiny1634, AT90USB82, AT90USB162, ATmega8U2, ATmega16U2, ATmega32U2, AT90SCR100, ATtiny4, ATtiny5, ATtiny9, ATtiny10, ATtiny13A, ATtiny20, ATtiny40</td>
  </tr>

  <tr>
   <td>power_can_disable()</td>
    <td> Disable the CAN module </td>
    <td>ATmega16M1, ATmega32C1, ATmega32M1, ATmega64C1, ATmega64M1</td>
  </tr>

  <tr>
   <td>power_can_enable()</td>
    <td> Enable the CAN module </td>
    <td>ATmega16M1, ATmega32C1, ATmega32M1, ATmega64C1, ATmega64M1</td>
  </tr>

  <tr>
   <td>power_cinterface_disable()</td>
    <td> Disable the CINTERFACE module </td>
    <td>ATA5790, ATA5795, ATA5702M322</td>
  </tr>

  <tr>
   <td>power_cinterface_enable()</td>
    <td> Enable the CINTERFACE module </td>
    <td>ATA5790, ATA5795, ATA5702M322</td>
  </tr>

  <tr>
   <td>power_crypto_disable()</td>
    <td> Disable the CRYPTO module </td>
    <td>ATA5790, ATA5795, ATA5702M322</td>
  </tr>

  <tr>
   <td>power_crypto_enable()</td>
    <td> Enable the CRYPTO module </td>
    <td>ATA5790, ATA5795, ATA5702M322</td>
  </tr>

  <tr>
   <td>power_daca_disable()</td>
    <td> Disable the DAC module on PortA </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega32A4U, ATxmega32A4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega192A3, ATxmega192A3U, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_daca_enable()</td>
    <td> Enable the DAC module on PortA </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega32A4U, ATxmega32A4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega192A3, ATxmega192A3U, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_dacb_disable()</td>
    <td> Disable the DAC module on PortB </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega32A4U, ATxmega32A4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega192A3, ATxmega192A3U, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_dacb_enable()</td>
    <td> Enable the DAC module on PortB </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega32A4U, ATxmega32A4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega192A3, ATxmega192A3U, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_dma_disable()</td>
    <td> Disable the DMA module </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega32A4U, ATxmega32A4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega192A3, ATxmega192A3U, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_dma_enable()</td>
    <td> Enable the DMA module </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega32A4U, ATxmega32A4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega192A3, ATxmega192A3U, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_ebi_disable()</td>
    <td> Disable the EBI module </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega32A4U, ATxmega32A4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega192A3, ATxmega192A3U, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_ebi_enable()</td>
    <td> Enable the EBI module </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega32A4U, ATxmega32A4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega192A3, ATxmega192A3U, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_evsys_disable()</td>
    <td> Disable the EVSYS module </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_evsys_enable()</td>
    <td> Enable the EVSYS module </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_hiresc_disable()</td>
    <td> Disable the HIRES module on PortC </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_hiresc_enable()</td>
    <td> Enable the HIRES module on PortC </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_hiresd_disable()</td>
    <td> Disable the HIRES module on PortD </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_hiresd_enable()</td>
    <td> Enable the HIRES module on PortD </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_hirese_disable()</td>
    <td> Disable the HIRES module on PortE </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_hirese_enable()</td>
    <td> Enable the HIRES module on PortE </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_hiresf_disable()</td>
    <td> Disable the HIRES module on PortF </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_hiresf_enable()</td>
    <td> Enable the HIRES module on PortF </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_hsspi_disable()</td>
    <td> Disable the HSPPI module </td>
    <td>AT90SCR100</td>
  </tr>

  <tr>
   <td>power_hsspi_enable()</td>
    <td> Enable the HSPPI module </td>
    <td>AT90SCR100</td>
  </tr>

  <tr>
   <td>power_irdriver_disable()</td>
    <td> Disable the IRDRIVER module </td>
    <td>ATA5790, ATA5795</td>
  </tr>

  <tr>
   <td>power_irdriver_enable()</td>
    <td> Enable the IRDRIVER module </td>
    <td>ATA5790, ATA5795</td>
  </tr>

  <tr>
   <td>power_kb_disable()</td>
    <td> Disable the KB module </td>
    <td>AT90SCR100</td>
  </tr>

  <tr>
   <td>power_kb_enable()</td>
    <td> Enable the KB module </td>
    <td>AT90SCR100</td>
  </tr>

  <tr>
   <td>power_lcd_disable()</td>
     <td>Disable the LCD module.</td>
    <td>ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3, ATmega169, ATmega169A, ATmega169P, ATmega169PA, ATmega329, ATmega329A, ATmega329P, ATmega329PA, ATmega3290, ATmega3290A, ATmega3290P, ATmega3290PA, ATmega649, ATmega649A, ATmega649P, ATmega6490, ATmega6490A, ATmega6490P</td>
  </tr>

  <tr>
   <td>power_lcd_enable()</td>
     <td>Enable the LCD module.</td>
    <td>ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3, ATmega169, ATmega169A, ATmega169P, ATmega169PA, ATmega329, ATmega329A, ATmega329P, ATmega329PA, ATmega3290, ATmega3290A, ATmega3290P, ATmega3290PA, ATmega649, ATmega649A, ATmega649P, ATmega6490, ATmega6490A, ATmega6490P</td>
  </tr>

  <tr>
   <td>power_lfreceiver_disable()</td>
    <td> Disable the LFRECEIVER module </td>
    <td>ATA5790, ATA5702M322</td>
  </tr>

  <tr>
   <td>power_lfreceiver_enable()</td>
    <td> Enable the LFRECEIVER module </td>
    <td>ATA5790, ATA5702M322</td>
  </tr>

  <tr>
   <td>power_lin_disable()</td>
    <td> Disable the LIN module </td>
    <td>ATmega16M1, ATmega32C1, ATmega32M1, ATmega64C1, ATmega64M1, ATtiny167, ATtiny87, ATA5505, ATA5272, ATA6616C, ATA6617C, ATA664251</td>
  </tr>

  <tr>
   <td>power_lin_enable()</td>
    <td> Enable the LIN module </td>
    <td>ATmega16M1, ATmega32C1, ATmega32M1, ATmega64C1, ATmega64M1, ATtiny167, ATtiny87, ATA5505, ATA5272, ATA6616C, ATA6617C, ATA664251</td>
  </tr>

  <tr>
   <td>power_psc0_disable()</td>
     <td>Disable the Power Stage Controller 0 module.</td>
    <td>AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316</td>
  </tr>

  <tr>
   <td>power_psc0_enable()</td>
     <td>Enable the Power Stage Controller 0 module.</td>
    <td>AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316</td>
  </tr>

  <tr>
   <td>power_psc1_disable()</td>
     <td>Disable the Power Stage Controller 1 module.</td>
    <td>AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316</td>
  </tr>

  <tr>
   <td>power_psc1_enable()</td>
     <td>Enable the Power Stage Controller 1 module.</td>
    <td>AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316</td>
  </tr>

  <tr>
   <td>power_psc2_disable()</td>
     <td>Disable the Power Stage Controller 2 module.</td>
    <td>AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, AT90PWM81, AT90PWM161</td>
  </tr>

  <tr>
   <td>power_psc2_enable()</td>
     <td>Enable the Power Stage Controller 2 module.</td>
    <td>AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, AT90PWM81, AT90PWM161</td>
  </tr>

  <tr>
   <td>power_psc_disable()</td>
    <td> Disable the Power Stage Controller module </td>
    <td>ATmega16M1, ATmega32C1, ATmega32M1, ATmega64C1, ATmega64M1</td>
  </tr>

  <tr>
   <td>power_psc_enable()</td>
    <td> Enable the Power Stage Controller module </td>
    <td>ATmega16M1, ATmega32C1, ATmega32M1, ATmega64C1, ATmega64M1</td>
  </tr>

  <tr>
   <td>power_pscr_disable()</td>
     <td>Disable the Reduced Power Stage Controller module.</td>
    <td>AT90PWM81, AT90PWM161</td>
  </tr>

  <tr>
   <td>power_pscr_enable()</td>
     <td>Enable the Reduced Power Stage Controller module.</td>
    <td>AT90PWM81, AT90PWM161</td>
  </tr>

  <tr>
   <td>power_rtc_disable()</td>
    <td> Disable the RTC module </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_rtc_enable()</td>
    <td> Enable the RTC module </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_sci_disable()</td>
    <td> Disable the SCI module </td>
    <td>AT90SCR100</td>
  </tr>

  <tr>
   <td>power_sci_enable()</td>
    <td> Enable the SCI module </td>
    <td>AT90SCR100</td>
  </tr>

  <tr>
   <td>power_spi_disable()</td>
     <td>Disable the Serial Peripheral Interface module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561, ATmega128RFA1, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega32U4, ATmega16U4, ATmega32U6, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, AT90PWM81, AT90PWM161, ATmega165, ATmega165A, ATmega165P, ATmega165PA, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega645A, ATmega645P, ATmega6450, ATmega6450A, ATmega6450P, ATmega169, ATmega169A, ATmega169P, ATmega169PA, ATmega329, ATmega329A, ATmega329P, ATmega329PA, ATmega3290, ATmega3290A, ATmega3290P, ATmega3290PA, ATmega649, ATmega649A, ATmega649P, ATmega6490, ATmega6490A, ATmega6490P, ATmega164A, ATmega164P, ATmega324A, ATmega324P, ATmega324PA, ATmega644P, ATmega644A, ATmega644PA, ATmega644, ATmega164PA, ATmega48, ATmega48A, ATmega48PA, ATmega48P, ATmega48PB, ATmega88, ATmega88A, ATmega88P, ATmega88PA, ATmega88PB, ATmega168, ATmega168A, ATmega168P, ATmega168PA, ATmega168PB, ATmega328, ATmega328P, ATtiny48, ATtiny88, ATtiny828, ATtiny441, ATmega1284, ATmega1284P, ATmega32HVB, ATmega32HVBrevB, ATmega16HVB, ATmega16HVBrevB, ATA5790, ATA5795, ATmega16M1, ATmega32C1, ATmega32M1, ATmega64C1, ATmega64M1, ATtiny167, ATtiny87, ATA5505, ATA5272, ATA6612C, ATA6613C, ATA6614Q, ATA6616C, ATA6617C, ATA664251, AT90USB82, AT90USB162, ATmega8U2, ATmega16U2, ATmega32U2, AT90SCR100, ATtiny20, ATtiny40</td>
  </tr>

  <tr>
   <td>power_spi_enable()</td>
     <td>Enable the Serial Peripheral Interface module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561, ATmega128RFA1, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega32U4, ATmega16U4, ATmega32U6, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, AT90PWM81, AT90PWM161, ATmega165, ATmega165A, ATmega165P, ATmega165PA, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega645A, ATmega645P, ATmega6450, ATmega6450A, ATmega6450P, ATmega169, ATmega169A, ATmega169P, ATmega169PA, ATmega329, ATmega329A, ATmega329P, ATmega329PA, ATmega3290, ATmega3290A, ATmega3290P, ATmega3290PA, ATmega649, ATmega649A, ATmega649P, ATmega6490, ATmega6490A, ATmega6490P, ATmega164A, ATmega164P, ATmega324A, ATmega324P, ATmega324PA, ATmega644P, ATmega644A, ATmega644PA, ATmega644, ATmega164PA, ATmega48, ATmega48A, ATmega48PA, ATmega48P, ATmega48PB, ATmega88, ATmega88A, ATmega88P, ATmega88PA, ATmega88PB, ATmega168, ATmega168A, ATmega168P, ATmega168PA, ATmega168PB, ATmega328, ATmega328P, ATtiny48, ATtiny88, ATtiny828, ATtiny441, ATmega1284, ATmega1284P, ATmega32HVB, ATmega32HVBrevB, ATmega16HVB, ATmega16HVBrevB, ATA5790, ATA5795, ATmega16M1, ATmega32C1, ATmega32M1, ATmega64C1, ATmega64M1, ATtiny167, ATtiny87, ATA5505, ATA5272, ATA6612C, ATA6613C, ATA6614Q, ATA6616C, ATA6617C, ATA664251, AT90USB82, AT90USB162, ATmega8U2, ATmega16U2, ATmega32U2, AT90SCR100, ATtiny20, ATtiny40</td>
  </tr>

  <tr>
   <td>power_spic_disable()</td>
    <td> Disable the SPI module on PortC </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_spic_enable()</td>
    <td> Enable the SPI module on PortC </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_spid_disable()</td>
    <td> Disable the SPI module on PortD </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4</td>
  </tr>

  <tr>
   <td>power_spid_enable()</td>
    <td> Enable the SPI module on PortD </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4</td>
  </tr>

  <tr>
   <td>power_spie_disable()</td>
    <td> Disable the SPI module on PortE </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_spie_enable()</td>
    <td> Enable the SPI module on PortE </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_spif_disable()</td>
    <td> Disable the SPI module on PortF </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_spif_enable()</td>
    <td> Enable the SPI module on PortF </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_tc0c_disable()</td>
    <td> Disable the TC0 module on PortC </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_tc0c_enable()</td>
    <td> Enable the TC0 module on PortC </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_tc0d_disable()</td>
    <td> Disable the TC0 module on PortD </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4</td>
  </tr>

  <tr>
   <td>power_tc0d_enable()</td>
    <td> Enable the TC0 module on PortD </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4</td>
  </tr>

  <tr>
   <td>power_tc0e_disable()</td>
    <td> Disable the TC0 module on PortE </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_tc0e_enable()</td>
    <td> Enable the TC0 module on PortE </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_tc0f_disable()</td>
    <td> Disable the TC0 module on PortF </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4</td>
  </tr>

  <tr>
   <td>power_tc0f_enable()</td>
    <td> Enable the TC0 module on PortF </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4</td>
  </tr>

  <tr>
   <td>power_tc1c_disable()</td>
    <td> Disable the TC1 module on PortC </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_tc1c_enable()</td>
    <td> Enable the TC1 module on PortC </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_tc1d_disable()</td>
    <td> Disable the TC1 module on PortD </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_tc1d_enable()</td>
    <td> Enable the TC1 module on PortD </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_tc1e_disable()</td>
    <td> Disable the TC1 module on PortE </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_tc1e_enable()</td>
    <td> Enable the TC1 module on PortE </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_tc1f_disable()</td>
    <td> Disable the TC1 module on PortF </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_tc1f_enable()</td>
    <td> Enable the TC1 module on PortF </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_timer0_disable()</td>
     <td>Disable the Timer 0 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561, ATmega128RFA1, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega32U4, ATmega16U4, ATmega32U6, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, ATmega164A, ATmega164P, ATmega324A, ATmega324P, ATmega324PA, ATmega644P, ATmega644A, ATmega644PA, ATmega644, ATmega164PA, ATmega406, ATmega48, ATmega48A, ATmega48PA, ATmega48P, ATmega48PB, ATmega88, ATmega88A, ATmega88P, ATmega88PA, ATmega88PB, ATmega168, ATmega168A, ATmega168P, ATmega168PA, ATmega168PB, ATmega328, ATmega328P, ATtiny48, ATtiny88, ATtiny828, ATtiny24, ATtiny24A, ATtiny44, ATtiny44A, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny261A, ATtiny441, ATtiny461, ATtiny461A, ATtiny861, ATtiny861A, ATtiny43U, ATmega1284, ATmega1284P, ATmega32HVB, ATmega32HVBrevB, ATmega16HVB, ATmega16HVBrevB, ATmega16M1, ATmega32C1, ATmega32M1, ATmega64C1, ATmega64M1, ATtiny167, ATtiny87, ATA5505, ATA5272, ATA6612C, ATA6613C, ATA6614Q, ATA6616C, ATA6617C, ATA664251, ATtiny1634, AT90USB82, AT90USB162, ATmega8U2, ATmega16U2, ATmega32U2, AT90SCR100, ATtiny4, ATtiny5, ATtiny9, ATtiny10, ATtiny13A, ATtiny20, ATtiny40</td>
  </tr>

  <tr>
   <td>power_timer0_enable()</td>
     <td>Enable the Timer 0 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561, ATmega128RFA1, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega32U4, ATmega16U4, ATmega32U6, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, ATmega164A, ATmega164P, ATmega324A, ATmega324P, ATmega324PA, ATmega644P, ATmega644A, ATmega644PA, ATmega644, ATmega164PA, ATmega406, ATmega48, ATmega48A, ATmega48PA, ATmega48P, ATmega48PB, ATmega88, ATmega88A, ATmega88P, ATmega88PB, ATmega88PA, ATmega168, ATmega168A, ATmega168P, ATmega168PA, ATmega168PB, ATmega328, ATmega328P, ATtiny48, ATtiny88, ATtiny828, ATtiny24, ATtiny24A, ATtiny44, ATtiny44A, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny261A, ATtiny441, ATtiny461, ATtiny461A, ATtiny861, ATtiny861A, ATtiny43U, ATmega1284, ATmega1284P, ATmega32HVB, ATmega32HVBrevB, ATmega16HVB, ATmega16HVBrevB, ATmega16M1, ATmega32C1, ATmega32M1, ATmega64C1, ATmega64M1, ATtiny167, ATtiny87, ATA5505, ATA5272, ATA6612C, ATA6613C, ATA6614Q, ATA6616C, ATA6617C, ATA664251, ATtiny1634, AT90USB82, AT90USB162, ATmega8U2, ATmega16U2, ATmega32U2, AT90SCR100, ATtiny4, ATtiny5, ATtiny9, ATtiny10, ATtiny13A, ATtiny20, ATtiny40</td>
  </tr>

  <tr>
   <td>power_timer1_disable()</td>
     <td>Disable the Timer 1 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561, ATmega128RFA1, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega32U4, ATmega16U4, ATmega32U6, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, AT90PWM81, AT90PWM161, ATmega165, ATmega165A, ATmega165P, ATmega165PA, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega645A, ATmega645P, ATmega6450, ATmega6450A, ATmega6450P, ATmega169, ATmega169A, ATmega169P, ATmega169PA, ATmega329, ATmega329A, ATmega329P, ATmega329PA, ATmega3290, ATmega3290A, ATmega3290P, ATmega3290PA, ATmega649, ATmega649A, ATmega649P, ATmega6490, ATmega6490A, ATmega6490P, ATmega164A, ATmega164P, ATmega324A, ATmega324P, ATmega324PA, ATmega644P, ATmega644A, ATmega644PA, ATmega644, ATmega164PA, ATmega406, ATmega48, ATmega48A, ATmega48PA, ATmega48P, ATmega48PB, ATmega88, ATmega88A, ATmega88P, ATmega88PA, ATmega88PB, ATmega168, ATmega168A, ATmega168P, ATmega168PA, ATmega168PB, ATmega328, ATmega328P, ATtiny48, ATtiny88, ATtiny828, ATtiny441, ATtiny24, ATtiny24A, ATtiny44, ATtiny44A, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny261A, ATtiny461, ATtiny461A, ATtiny861, ATtiny861A, ATtiny43U, ATmega1284, ATmega1284P, ATmega32HVB, ATmega32HVBrevB, ATmega16HVB, ATmega16HVBrevB, ATA5790, ATA5795, ATmega16M1, ATmega32C1, ATmega32M1, ATmega64C1, ATmega64M1, ATtiny167, ATtiny87, ATA5505, ATA5272, ATA6612C, ATA6613C, ATA6614Q, ATA6616C, ATA6617C, ATA664251, ATtiny1634, AT90USB82, AT90USB162, ATmega8U2, ATmega16U2, ATmega32U2, AT90SCR100, ATtiny20, ATtiny40</td>
  </tr>

  <tr>
   <td>power_timer1_enable()</td>
     <td>Enable the Timer 1 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561, ATmega128RFA1, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega32U4, ATmega16U4, ATmega32U6, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, AT90PWM81, AT90PWM161, ATmega165, ATmega165A, ATmega165P, ATmega165PA, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega645A, ATmega645P, ATmega6450, ATmega6450A, ATmega6450P, ATmega169, ATmega169A, ATmega169P, ATmega169PA, ATmega329, ATmega329A, ATmega329P, ATmega329PA, ATmega3290, ATmega3290A, ATmega3290P, ATmega3290PA, ATmega649, ATmega649A, ATmega649P, ATmega6490, ATmega6490A, ATmega6490P, ATmega164A, ATmega164P, ATmega324A, ATmega324P, ATmega324PA, ATmega644P, ATmega644A, ATmega644PA, ATmega644, ATmega164PA, ATmega406, ATmega48, ATmega48A, ATmega48PA, ATmega48P, ATmega48PB, ATmega88, ATmega88A, ATmega88P, ATmega88PA, ATmega88PB, ATmega168, ATmega168A, ATmega168P, ATmega168PA, ATmega168PB, ATmega328, ATmega328P, ATtiny48, ATtiny88, ATtiny828, ATtiny441, ATtiny24, ATtiny24A, ATtiny44, ATtiny44A, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny261A, ATtiny461, ATtiny461A, ATtiny861, ATtiny861A, ATtiny43U, ATmega1284, ATmega1284P, ATmega32HVB, ATmega32HVBrevB, ATmega16HVB, ATmega16HVBrevB, ATA5790, ATA5795, ATmega16M1, ATmega32C1, ATmega32M1, ATmega64C1, ATmega64M1, ATtiny167, ATtiny87, ATA5505, ATA5272, ATA6612C, ATA6613C, ATA6614Q, ATA6616C, ATA6617C, ATA664251, ATtiny1634, AT90USB82, AT90USB162, ATmega8U2, ATmega16U2, ATmega32U2, AT90SCR100, ATtiny20, ATtiny40</td>
  </tr>

  <tr>
   <td>power_timer2_disable()</td>
     <td>Disable the Timer 2 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561, ATmega128RFA1, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega32U4, ATmega16U4, ATmega32U6, ATmega164A, ATmega164P, ATmega324A, ATmega324P, ATmega324PA, ATmega644P, ATmega644A, ATmega644PA, ATmega644, ATmega164PA, ATmega48, ATmega48A, ATmega48PA, ATmega48PB, ATmega48P, ATmega88, ATmega88A, ATmega88P, ATmega88PA, ATmega88PB, ATmega168, ATmega168A, ATmega168P, ATmega168PA, ATmega168PB, ATmega328, ATmega328P, ATtiny48, ATtiny88, ATtiny828, ATtiny441, ATmega1284, ATmega1284P, ATA5790, ATA5795, ATA6612C, ATA6613C, ATA6614Q, AT90SCR100</td>
  </tr>

  <tr>
   <td>power_timer2_enable()</td>
     <td>Enable the Timer 2 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561, ATmega128RFA1, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega32U4, ATmega16U4, ATmega32U6, ATmega164A, ATmega164P, ATmega324A, ATmega324P, ATmega324PA, ATmega644P, ATmega644A, ATmega644PA, ATmega644, ATmega164PA, ATmega48, ATmega48A, ATmega48PA, ATmega48PB, ATmega48P, ATmega88, ATmega88A, ATmega88P, ATmega88PA, ATmega88PB, ATmega168, ATmega168A, ATmega168P, ATmega168PA, ATmega168PB, ATmega328, ATmega328P, ATtiny48, ATtiny88, ATtiny828, ATtiny441, ATmega1284, ATmega1284P, ATA5790, ATA5795, ATA6612C, ATA6613C, ATA6614Q, AT90SCR100</td>
  </tr>

  <tr>
   <td>power_timer3_disable()</td>
     <td>Disable the Timer 3 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561, ATmega128RFA1, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega32U4, ATmega16U4, ATmega32U6, ATmega1284, ATmega1284P, ATA5790, ATA5795</td>
  </tr>

  <tr>
   <td>power_timer3_enable()</td>
     <td>Enable the Timer 3 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561, ATmega128RFA1, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega32U4, ATmega16U4, ATmega32U6, ATmega1284, ATmega1284P, ATA5790, ATA5795</td>
  </tr>

  <tr>
   <td>power_timer4_disable()</td>
     <td>Disable the Timer 4 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561, ATmega128RFA1</td>
  </tr>

  <tr>
   <td>power_timer4_enable()</td>
     <td>Enable the Timer 4 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561, ATmega128RFA1</td>
  </tr>

  <tr>
   <td>power_timermodulator_disable()</td>
    <td> Disable the TIMERMODULATOR module </td>
    <td>ATA5790, ATA5795</td>
  </tr>

  <tr>
   <td>power_timermodulator_enable()</td>
    <td> Enable the TIMERMODULATOR module </td>
    <td>ATA5790, ATA5795</td>
  </tr>

  <tr>
   <td>power_twi_disable()</td>
    <td>Disable the Two Wire Interface module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561, ATmega128RFA1, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega32U4, ATmega16U4, ATmega32U6, ATmega164A, ATmega164P, ATmega324A, ATmega324P, ATmega324PA, ATmega644P, ATmega644A, ATmega644PA, ATmega644, ATmega164PA, ATmega406, ATmega48, ATmega48A, ATmega48PA, ATmega48P, ATmega48PB, ATmega88, ATmega88A, ATmega88P, ATmega88PA, ATmega88PB, ATmega168, ATmega168A, ATmega168P, ATmega168PA, ATmega168PB, ATmega328, ATmega328P, ATtiny48, ATtiny88, ATtiny828, ATtiny441, ATmega1284, ATmega1284P, ATmega32HVB, ATmega32HVBrevB, ATmega16HVB, ATmega16HVBrevB, ATA6612C, ATA6613C, ATA6614Q, ATtiny1634, AT90SCR100, ATtiny20, ATtiny40, ATA5702M322</td>
  </tr>

  <tr>
   <td>power_twi_enable()</td>
    <td>Enable the Two Wire Interface module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561, ATmega128RFA1, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega32U4, ATmega16U4, ATmega32U6, ATmega164A, ATmega164P, ATmega324A, ATmega324P, ATmega324PA, ATmega644P, ATmega644A, ATmega644PA, ATmega644, ATmega164PA, ATmega406, ATmega48, ATmega48A, ATmega48PA, ATmega48P, ATmega48PB, ATmega88, ATmega88A, ATmega88P, ATmega88PA, ATmega88PB, ATmega168, ATmega168A, ATmega168P, ATmega168PA, ATmega168PB, ATmega328, ATmega328P, ATtiny48, ATtiny88, ATtiny828, ATtiny441, ATmega1284, ATmega1284P, ATmega32HVB, ATmega32HVBrevB, ATmega16HVB, ATmega16HVBrevB, ATA6612C, ATA6613C, ATA6614Q, ATtiny1634, AT90SCR100, ATtiny20, ATtiny40, ATA5702M322</td>
  </tr>

  <tr>
   <td>power_twic_disable()</td>
    <td>Disable the Two Wire Interface module on PortC </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_twic_enable()</td>
    <td>Enable the Two Wire Interface module on PortC </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_twid_disable()</td>
    <td>Disable the Two Wire Interface module on PortD </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_twid_enable()</td>
    <td>Enable the Two Wire Interface module on PortD </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_twie_disable()</td>
    <td>Disable the Two Wire Interface module on PortE </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4</td>
  </tr>

  <tr>
   <td>power_twie_enable()</td>
    <td>Enable the Two Wire Interface module on PortE </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4</td>
  </tr>

  <tr>
   <td>power_twif_disable()</td>
    <td>Disable the Two Wire Interface module on PortF </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_twif_enable()</td>
    <td>Disable the Two Wire Interface module on PortF </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_usart0_disable()</td>
     <td>Disable the USART 0 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561, ATmega128RFA1, ATmega32U4, ATmega16U4, ATmega165, ATmega165A, ATmega165P, ATmega165PA, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega645A, ATmega645P, ATmega6450, ATmega6450A, ATmega6450P, ATmega169, ATmega169A, ATmega169P, ATmega169PA, ATmega329, ATmega329A, ATmega329P, ATmega329PA, ATmega3290, ATmega3290A, ATmega3290P, ATmega3290PA, ATmega649, ATmega649A, ATmega649P, ATmega6490, ATmega6490A, ATmega6490P, ATmega164A, ATmega164P, ATmega324A, ATmega324P, ATmega324PA, ATmega644P, ATmega644A, ATmega644PA, ATmega644, ATmega164PA, ATmega48, ATmega48A, ATmega48PA, ATmega48PB, ATmega48P, ATmega88, ATmega88A, ATmega88P, ATmega88PA, ATmega88PB, ATmega168, ATmega168A, ATmega168P, ATmega168PA, ATmega168PB, ATmega328, ATmega328P, ATtiny48, ATtiny88, ATtiny828, ATtiny441, ATA6612C, ATA6613C, ATA6614Q, ATmega1284, ATmega1284P, ATtiny1634, AT90SCR100</td>
  </tr>

  <tr>
   <td>power_usart0_enable()</td>
     <td>Enable the USART 0 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561, ATmega128RFA1, ATmega32U4, ATmega16U4, ATmega165, ATmega165A, ATmega165P, ATmega165PA, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega645A, ATmega645P, ATmega6450, ATmega6450A, ATmega6450P, ATmega169, ATmega169A, ATmega169P, ATmega169PA, ATmega329, ATmega329A, ATmega329P, ATmega329PA, ATmega3290, ATmega3290A, ATmega3290P, ATmega3290PA, ATmega649, ATmega649A, ATmega649P, ATmega6490, ATmega6490A, ATmega6490P, ATmega164A, ATmega164P, ATmega324A, ATmega324P, ATmega324PA, ATmega644P, ATmega644A, ATmega644PA, ATmega644, ATmega164PA, ATmega48, ATmega48A, ATmega48PA, ATmega48PB, ATmega48P, ATmega88, ATmega88A, ATmega88P, ATmega88PA, ATmega88PB, ATmega168, ATmega168A, ATmega168P, ATmega168PA, ATmega168PB, ATmega328, ATmega328P, ATtiny48, ATtiny88, ATtiny828, ATtiny441, ATA6612C, ATA6613C, ATA6614Q, ATmega1284, ATmega1284P, ATtiny1634, AT90SCR100</td>
  </tr>

  <tr>
   <td>power_usart1_disable()</td>
     <td>Disable the USART 1 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561, ATmega128RFA1, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega32U4, ATmega16U4, ATmega32U6, ATmega164A, ATmega164P, ATmega324A, ATmega324P, ATmega324PA, ATmega644P, ATmega644A, ATmega644PA, ATmega1284P, ATtiny441, ATtiny1634, AT90USB82, AT90USB162, ATmega8U2, ATmega16U2, ATmega32U2</td>
  </tr>

  <tr>
   <td>power_usart1_enable()</td>
     <td>Enable the USART 1 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561, ATmega128RFA1, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega32U4, ATmega16U4, ATmega32U6, ATmega164A, ATmega164P, ATmega324A, ATmega324P, ATmega324PA, ATmega644P, ATmega644A, ATmega644PA, ATmega1284P, ATtiny441, ATtiny1634, AT90USB82, AT90USB162, ATmega8U2, ATmega16U2, ATmega32U2</td>
  </tr>

  <tr>
   <td>power_usart2_disable()</td>
     <td>Disable the USART 2 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
   <td>power_usart2_enable()</td>
     <td>Enable the USART 2 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
   <td>power_usart3_disable()</td>
     <td>Disable the USART 3 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
   <td>power_usart3_enable()</td>
     <td>Enable the USART 3 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
   <td>power_usart_disable()</td>
     <td>Disable the USART module.</td>
    <td>AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316</td>
  </tr>

  <tr>
   <td>power_usart_enable()</td>
     <td>Enable the USART module.</td>
    <td>AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316</td>
  </tr>

  <tr>
   <td>power_usartc0_disable()</td>
    <td> Disable the USART0 module on PortC </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_usartc0_enable()</td>
    <td> Enable the USART0 module on PortC </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_usartc1_disable()</td>
    <td> Disable the USART1 module on PortC </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega32A4U, ATxmega32A4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega192A3, ATxmega192A3U, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3</td>
  </tr>

  <tr>
   <td>power_usartc1_enable()</td>
    <td> Enable the USART1 module on PortC </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega32A4U, ATxmega32A4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega192A3, ATxmega192A3U, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3</td>
  </tr>

  <tr>
   <td>power_usartd0_disable()</td>
    <td> Disable the USART0 module on PortD </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4</td>
  </tr>

  <tr>
   <td>power_usartd0_enable()</td>
    <td> Enable the USART0 module on PortD </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4</td>
  </tr>

  <tr>
   <td>power_usartd1_disable()</td>
    <td> Disable the USART1 module on PortD </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega32A4U, ATxmega32A4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega192A3, ATxmega192A3U, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_usartd1_enable()</td>
    <td> Enable the USART1 module on PortE </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega32A4U, ATxmega32A4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega192A3, ATxmega192A3U, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_usarte0_disable()</td>
    <td> Disable the USART0 module on PortE </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_usarte0_enable()</td>
    <td> Enable the USART0 module on PortE </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3</td>
  </tr>

  <tr>
   <td>power_usarte1_disable()</td>
    <td> Disable the USART1 module on PortE </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega32A4U, ATxmega32A4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega192A3, ATxmega192A3U, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_usarte1_enable()</td>
    <td> Enable the USART1 module on PortE </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega32A4U, ATxmega32A4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega192A3, ATxmega192A3U, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_usartf0_disable()</td>
    <td> Disable the USART0 module on PortF </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4</td>
  </tr>

  <tr>
   <td>power_usartf0_enable()</td>
    <td> Enable the USART0 module on PortF </td>
    <td>ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega16A4, ATxmega16A4U, ATxmega16D4, ATxmega32A4, ATxmega32A4U, ATxmega32D4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega32D3, ATxmega64D3, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega128D3, ATxmega192A3, ATxmega192A3U, ATxmega192D3, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3, ATxmega64D4, ATxmega128D4</td>
  </tr>

  <tr>
   <td>power_usartf1_disable()</td>
    <td> Disable the USART1 module on PortF </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega32A4U, ATxmega32A4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega192A3, ATxmega192A3U, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_usartf1_enable()</td>
    <td> Enable the USART1 module on PortF </td>
    <td>ATxmega16A4, ATxmega16A4U, ATxmega32A4U, ATxmega32A4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmega64A3U, ATxmega64A4U, ATxmega128A1, ATxmega128A1U, ATxmega128A3, ATxmega128A3U, ATxmega128A4U, ATxmega192A3, ATxmega192A3U, ATxmega256A3, ATxmega256A3U, ATxmega256A3B, ATxmega256A3BU, ATxmega384C3</td>
  </tr>

  <tr>
   <td>power_usb_disable()</td>
     <td>Disable the USB module.</td>
    <td>ATxmega384C3, ATxmega256A3BU, ATxmega16A4U, ATxmega32A4U, ATxmega64A3U, ATxmega64A4U, ATxmega128A3U, ATxmega128A4U, ATxmega192A3U, ATxmega256A3U, ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega32U4, ATmega16U4, ATmega32U6, AT90USB82, AT90USB162, ATmega8U2, ATmega16U2, ATmega32U2, AT90SCR100</td>
  </tr>

  <tr>
   <td>power_usb_enable()</td>
     <td>Enable the USB module.</td>
    <td>ATxmega384C3, ATxmega256A3BU, ATxmega16A4U, ATxmega32A4U, ATxmega64A3U, ATxmega64A4U, ATxmega128A3U, ATxmega128A4U, ATxmega192A3U, ATxmega256A3U, ATxmega16C4, ATxmega32C4, ATxmega32C3, ATxmega64C3, ATxmega128C3, ATxmega192C3, ATxmega256C3, ATxmega64B1, ATxmega64B3, ATxmega128B1, ATxmega128B3, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega32U4, ATmega16U4, ATmega32U6, AT90USB82, AT90USB162, ATmega8U2, ATmega16U2, ATmega32U2, AT90SCR100</td>
  </tr>

  <tr>
   <td>power_usbh_disable()</td>
    <td> Disable the USBH module </td>
    <td>AT90SCR100</td>
  </tr>

  <tr>
   <td>power_usbh_enable()</td>
    <td> Enable the USBH module </td>
    <td>AT90SCR100</td>
  </tr>

  <tr>
   <td>power_usi_disable()</td>
     <td>Disable the Universal Serial Interface module.</td>
    <td>ATtiny24, ATtiny24A, ATtiny44, ATtiny44A, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny261A, ATtiny461, ATtiny461A, ATtiny861, ATtiny861A, ATtiny43U, ATtiny167, ATtiny87, ATA5505, ATA5272, ATA6616C, ATA6617C, ATA664251, ATtiny1634</td>
  </tr>

  <tr>
   <td>power_usi_enable()</td>
     <td>Enable the Universal Serial Interface module.</td>
    <td>ATtiny24, ATtiny24A, ATtiny44, ATtiny44A, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny261A, ATtiny461, ATtiny461A, ATtiny861, ATtiny861A, ATtiny43U, ATtiny167, ATtiny87, ATA5505, ATA5272, ATA6616C, ATA6617C, ATA664251, ATtiny1634</td>
  </tr>

  <tr>
   <td>power_vadc_disable()</td>
     <td>Disable the Voltage ADC module.</td>
    <td>ATmega406, ATmega32HVB, ATmega32HVBrevB, ATmega16HVB, ATmega16HVBrevB</td>
  </tr>

  <tr>
   <td>power_vadc_enable()</td>
     <td>Enable the Voltage ADC module.</td>
    <td>ATmega406, ATmega32HVB, ATmega32HVBrevB, ATmega16HVB, ATmega16HVBrevB</td>
  </tr>

  <tr>
   <td>power_vmonitor_disable()</td>
    <td> Disable the VMONITOR module </td>
    <td>ATA5790, ATA5795</td>
  </tr>

  <tr>
   <td>power_vmonitor_enable()</td>
    <td> Enable the VMONITOR module </td>
    <td>ATA5790, ATA5795</td>
  </tr>

  <tr>
   <td>power_vrm_disable()</td>
    <td> Disable the VRM module </td>
    <td>ATmega32HVB, ATmega32HVBrevB, ATmega16HVB, ATmega16HVBrevB</td>
  </tr>

  <tr>
   <td>power_vrm_enable()</td>
    <td> Enable the VRM module </td>
    <td>ATmega32HVB, ATmega32HVBrevB, ATmega16HVB, ATmega16HVBrevB</td>
  </tr>

  <tr>
    <td>power_clock_output_enable()</td>
    <td>Enable clock output module</td>
    <td>ATA5702M322, ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_clock_output_disable()</td>
    <td>Enable clock output module</td>
    <td>ATA5702M322, ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_voltage_monitor_enable()</td>
    <td>Enable voltage monitor module</td>
    <td>ATA5702M322, ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_voltage_monitor_disable()</td>
    <td>Disable voltage monitor module</td>
    <td>ATA5702M322, ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_crc_enable()</td>
    <td>Enable CRC module</td>
    <td>ATA5702M322, ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_crc_disable()</td>
    <td>Disable CRC module</td>
    <td>ATA5702M322, ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_transmit_dsp_control_enable()</td>
    <td>Enable Transmit DSP control module</td>
    <td>ATA5702M322, ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_transmit_dsp_control_disable()</td>
    <td>Disable Transmit DSP control module</td>
    <td>ATA5702M322, ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_receive_dsp_control_enable()</td>
    <td>Enable Receive DSP control module</td>
    <td>ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_receive_dsp_control_disable()</td>
    <td>Disable Receive DSP control module</td>
    <td>ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_sequencer_state_machine_enable()</td>
    <td>Enable power sequencer state machine</td>
    <td>ATA5702M322, ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_sequencer_state_machine_disable()</td>
    <td>Disable power sequencer state machine</td>
    <td>ATA5702M322, ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_tx_modulator_enable()</td>
    <td>Enable Tx modulator</td>
    <td>ATA5702M322, ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_tx_modulator_disable()</td>
    <td>Disable Tx modulator</td>
    <td>ATA5702M322, ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_rssi_buffer_enable()</td>
    <td>Enable RSSI buffer</td>
    <td>ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_rssi_buffer_disable()</td>
    <td>Disable RSSI buffer</td>
    <td>ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_id_scan_enable()</td>
    <td>Enable ID Scan</td>
    <td>ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_id_scan_disable()</td>
    <td>Disable ID Scan</td>
    <td>ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_data_fifo_enable()</td>
    <td>Enable data FIFO</td>
    <td>ATA5702M322, ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_data_fifo_disable()</td>
    <td>Disable data FIFO</td>
    <td>ATA5702M322, ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_preamble_rssi_fifo_enable()</td>
    <td>Enable preamble/RSSI FIFO</td>
    <td>ATA5702M322, ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_preamble_rssi_fifo_disable()</td>
    <td>Disable preamble/RSSI FIFO</td>
    <td>ATA5702M322, ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_rx_buffer_A_enable()</td>
    <td>Enable receive buffer for data path A</td>
    <td>ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_rx_buffer_A_disable()</td>
    <td>Disable receive buffer for data path A</td>
    <td>ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_rx_buffer_B_enable()</td>
    <td>Enable receive buffer for data path B</td>
    <td>ATA5782, ATA5831</td>
  </tr>

  <tr>
    <td>power_rx_buffer_B_disable()</td>
    <td>Disable receive buffer for data path B</td>
    <td>ATA5782, ATA5831</td>
  </tr>

</table>
</center>
</small>

@} */

// Xmega A series has AES, EBI and DMA bits
// Include any other device on need basis
# 3107 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/power.h" 3
/** \addtogroup avr_power

Some of the newer AVRs contain a System Clock Prescale Register (CLKPR) that
allows you to decrease the system clock frequency and the power consumption
when the need for processing power is low.
On some earlier AVRs (ATmega103, ATmega64, ATmega128), similar
functionality can be achieved through the XTAL Divide Control Register.
Below are two macros and an enumerated type that can be used to
interface to the Clock Prescale Register or
XTAL Divide Control Register.

\note Not all AVR devices have a clock prescaler. On those devices
without a Clock Prescale Register or XTAL Divide Control Register, these
macros are not available.
*/


/** \addtogroup avr_power
\code 
typedef enum
{
    clock_div_1 = 0,
    clock_div_2 = 1,
    clock_div_4 = 2,
    clock_div_8 = 3,
    clock_div_16 = 4,
    clock_div_32 = 5,
    clock_div_64 = 6,
    clock_div_128 = 7,
    clock_div_256 = 8,
    clock_div_1_rc = 15, // ATmega128RFA1 only
} clock_div_t;
\endcode
Clock prescaler setting enumerations for device using
System Clock Prescale Register.

\code
typedef enum
{
    clock_div_1 = 1,
    clock_div_2 = 2,
    clock_div_4 = 4,
    clock_div_8 = 8,
    clock_div_16 = 16,
    clock_div_32 = 32,
    clock_div_64 = 64,
    clock_div_128 = 128
} clock_div_t;
\endcode
Clock prescaler setting enumerations for device using
XTAL Divide Control Register.

*/
typedef enum
{
    clock_div_1 = 0,
    clock_div_2 = 1,
    clock_div_4 = 2,
    clock_div_8 = 3,
    clock_div_16 = 4,
    clock_div_32 = 5,
    clock_div_64 = 6,
    clock_div_128 = 7,
    clock_div_256 = 8
# 3180 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/power.h" 3
} clock_div_t;


static __inline__ void clock_prescale_set(clock_div_t) __attribute__((__always_inline__));

/** \addtogroup avr_power
\code clock_prescale_set(x) \endcode

Set the clock prescaler register select bits, selecting a system clock
division setting. This function is inlined, even if compiler
optimizations are disabled.

The type of \c x is \c clock_div_t.

\note For device with XTAL Divide Control Register (XDIV), \c x can actually range
from 1 to 129. Thus, one does not need to use \c clock_div_t type as argument.
*/
void clock_prescale_set(clock_div_t __x)
{
    uint8_t __tmp = (1 << (7));
    __asm__ __volatile__ (
        "in __tmp_reg__,__SREG__" "\n\t"
        "cli" "\n\t"
        "sts %1, %0" "\n\t"
        "sts %1, %2" "\n\t"
        "out __SREG__, __tmp_reg__"
        : /* no outputs */
        : "d" (__tmp),
          "M" (((uint16_t) &((*(volatile uint8_t *)(0x61))))),
          "d" (__x)
        : "r0");
}

/** \addtogroup avr_power
\code clock_prescale_get() \endcode
Gets and returns the clock prescaler register setting. The return type is \c clock_div_t.

\note For device with XTAL Divide Control Register (XDIV), return can actually
range from 1 to 129. Care should be taken has the return value could differ from the
typedef enum clock_div_t. This should only happen if clock_prescale_set was previously
called with a value other than those defined by \c clock_div_t.
*/
# 6 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/tools/avr/avr/include/avr/eeprom.h" 1 3
/* Copyright (c) 2002, 2003, 2004, 2007 Marek Michalkiewicz
   Copyright (c) 2005, 2006 Bjoern Haase
   Copyright (c) 2008 Atmel Corporation
   Copyright (c) 2008 Wouter van Gulik
   Copyright (c) 2009 Dmitry Xmelkov
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
# 7 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/libraries/Wire/Wire.h" 1
/*
  TwoWire.h - TWI/I2C library for Arduino & Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

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

  Modified 2012 by Todd Krein (todd@krein.org) to implement repeated starts
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
# 26 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/libraries/Wire/Wire.h" 2
# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Stream.h" 1
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
# 27 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/libraries/Wire/Wire.h" 2



// WIRE_HAS_END means Wire has end()


class TwoWire : public Stream
{
  private:
    static uint8_t rxBuffer[];
    static uint8_t rxBufferIndex;
    static uint8_t rxBufferLength;

    static uint8_t txAddress;
    static uint8_t txBuffer[];
    static uint8_t txBufferIndex;
    static uint8_t txBufferLength;

    static uint8_t transmitting;
    static void (*user_onRequest)(void);
    static void (*user_onReceive)(int);
    static void onRequestService(void);
    static void onReceiveService(uint8_t*, int);
  public:
    TwoWire();
    void begin();
    void begin(uint8_t);
    void begin(int);
    void end();
    void setClock(uint32_t);
    void beginTransmission(uint8_t);
    void beginTransmission(int);
    uint8_t endTransmission(void);
    uint8_t endTransmission(uint8_t);
    uint8_t requestFrom(uint8_t, uint8_t);
    uint8_t requestFrom(uint8_t, uint8_t, uint8_t);
 uint8_t requestFrom(uint8_t, uint8_t, uint32_t, uint8_t, uint8_t);
    uint8_t requestFrom(int, int);
    uint8_t requestFrom(int, int, int);
    virtual size_t write(uint8_t);
    virtual size_t write(const uint8_t *, size_t);
    virtual int available(void);
    virtual int read(void);
    virtual int peek(void);
    virtual void flush(void);
    void onReceive( void (*)(int) );
    void onRequest( void (*)(void) );

    inline size_t write(unsigned long n) { return write((uint8_t)n); }
    inline size_t write(long n) { return write((uint8_t)n); }
    inline size_t write(unsigned int n) { return write((uint8_t)n); }
    inline size_t write(int n) { return write((uint8_t)n); }
    using Print::write;
};

extern TwoWire Wire;
# 8 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino" 2
# 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/build/sketch/./libs/HTU21D/HTU21D.h" 1
    /*
 HTU21D Humidity Sensor Library
 By: Nathan Seidle
 SparkFun Electronics
 Date: September 22nd, 2013
 License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

 Get humidity and temperature from the HTU21D sensor.

 */



# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Arduino.h" 1
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
# 15 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/build/sketch/./libs/HTU21D/HTU21D.h" 2




# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/libraries/Wire/Wire.h" 1
/*
  TwoWire.h - TWI/I2C library for Arduino & Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

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

  Modified 2012 by Todd Krein (todd@krein.org) to implement repeated starts
*/
# 20 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/build/sketch/./libs/HTU21D/HTU21D.h" 2
# 31 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/build/sketch/./libs/HTU21D/HTU21D.h"
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
# 9 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino" 2
# 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/build/sketch/./libs/Time/Time.h" 1
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
# 15 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/build/sketch/./libs/Time/Time.h" 2






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
# 75 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/build/sketch/./libs/Time/Time.h"
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
# 10 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino" 2
# 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/build/sketch/./libs/MCP79412RTC/MCP79412RTC.h" 1
/*----------------------------------------------------------------------*
 * MCP79412RTC.h - Arduino library for the Microchip MCP7941x           *
 * Real-Time Clocks. This library is intended for use with the Arduino  *
 * Time.h library, http://www.arduino.cc/playground/Code/Time           *
 *                                                                      *
 * This library is a drop-in replacement for the DS1307RTC.h library    *
 * by Michael Margolis that is supplied with the Arduino Time library   *
 * above. To change from using a DS1307 RTC to an MCP7941x RTC, it is   *
 * only necessary to change the #include statement to include this      *
 * library instead of DS1307RTC.h.                                      *
 *                                                                      *
 * In addition, this library implements functions to support the        *
 * additional features of the MCP7941x.                                 *
 *                                                                      *
 * Jack Christensen 29Jul2012                                           *
 *                                                                      *
 * This work is licensed under the Creative Commons Attribution-        *
 * ShareAlike 3.0 Unported License. To view a copy of this license,     *
 * visit http://creativecommons.org/licenses/by-sa/3.0/ or send a       *
 * letter to Creative Commons, 171 Second Street, Suite 300,            *
 * San Francisco, California, 94105, USA.                               *
 *----------------------------------------------------------------------*/



# 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/build/sketch/./libs/MCP79412RTC/../Time/Time.h" 1
/*
  time.h - low level time and date functions
*/

/*
  July 3 2011 - fixed elapsedSecsThisWeek macro (thanks Vincent Valdy for this)
              - fixed  daysToTime_t macro (thanks maniacbug)
*/
# 27 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/build/sketch/./libs/MCP79412RTC/MCP79412RTC.h" 2


# 1 "/home/rajesh/Desktop/arduino-1.6.6_nightly/hardware/arduino/avr/cores/arduino/Arduino.h" 1
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
# 30 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/build/sketch/./libs/MCP79412RTC/MCP79412RTC.h" 2




//MCP7941x I2C Addresses



//MCP7941x Register Addresses
# 58 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/build/sketch/./libs/MCP79412RTC/MCP79412RTC.h"
//Control Register bits
# 67 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/build/sketch/./libs/MCP79412RTC/MCP79412RTC.h"
enum {SQWAVE_1_HZ, SQWAVE_4096_HZ, SQWAVE_8192_HZ, SQWAVE_32768_HZ, SQWAVE_NONE};

//Other Control Bits





                    //VBAT is cleared by software, clearing VBAT also clears the timestamp registers



//Alarm Control Bits





enum {ALM_MATCH_SECONDS, ALM_MATCH_MINUTES, ALM_MATCH_HOURS, ALM_MATCH_DAY, ALM_MATCH_DATE, ALM_RESERVED_5, ALM_RESERVED_6, ALM_MATCH_DATETIME, ALM_DISABLE};
//Note ALM_MATCH_DAY triggers alarm at midnight



class MCP79412RTC
{
    public:
        MCP79412RTC();
        static time_t get(void);
        static void set(time_t t);
        static boolean read(tmElements_t &tm);
        static void write(tmElements_t &tm);
        void sramWrite(byte addr, byte value);
        void sramWrite(byte addr, byte *values, byte nBytes);
        byte sramRead(byte addr);
        void sramRead(byte addr, byte *values, byte nBytes);
        void eepromWrite(byte addr, byte value);
        void eepromWrite(byte addr, byte *values, byte nBytes);
        byte eepromRead(byte addr);
        void eepromRead(byte addr, byte *values, byte nBytes);
        int calibRead(void);
        void calibWrite(int value);
        void idRead(byte *uniqueID);
        void getEUI64(byte *uniqueID);
        boolean powerFail(time_t *powerDown, time_t *powerUp);
        void squareWave(uint8_t freq);
        void setAlarm(uint8_t alarmNumber, time_t alarmTime);
        void enableAlarm(uint8_t alarmNumber, uint8_t alarmType);
        boolean alarm(uint8_t alarmNumber);
        void out(boolean level);
        void alarmPolarity(boolean polarity);
        boolean isRunning(void);
        void vbaten(boolean enable);

    private:
        static void ramWrite(byte addr, byte value);
        static void ramWrite(byte addr, byte *values, byte nBytes);
        static byte ramRead(byte addr);
        static void ramRead(byte addr, byte *values, byte nBytes);
        static byte eepromWait(void);
        static uint8_t dec2bcd(uint8_t num);
        static uint8_t bcd2dec(uint8_t num);
};

extern MCP79412RTC RTC;
# 11 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino" 2
# 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/build/sketch/./libs/SoftReset/SoftReset.h" 1
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
# 26 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/build/sketch/./libs/SoftReset/SoftReset.h" 2
# 12 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino" 2



//---------- C O N S T A N T S ------------------------------------------------
//#define BOOT_POST




// Node controller (JP1)


// Network switch (JP2)


// Guest node 1 (JP3)


// Guest node 2 (JP4)


// Guest node 3 (JP5)


// Thermistors (JP10)





// Light detector


// Period of heartbeat for ODroids (ms)
// This needs to be small and an even number


// Delay before enabling relay after disabling it


// Delay after bad environment reading during boot (seconds)

// Delay after bad power reading during boot (seconds)


// I2C addresses for current sensors







// Resolution of current sensors (with 8A range) (mA)


// Time (ms) to give node controller to prepare to receive message

// Time (ms) to give node controller to prepare for shutdown

// Time (ms) to give node controller to acquire the time from the internet


// Period of SysMon's requests for updated time from NC


// Special characters for interacting with the node controller
# 90 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
// Messages to send to node controller
# 99 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
// Currently no implementation of heartbeat for switch.
// Most switches will not have a reliable source of heartbeat to tie into.
// Could use NC to emulate heartbeat for switch.
# 113 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
// Messages that might be received from node controller
# 124 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
//---------- G L O B A L S ----------------------------------------------------
volatile byte _timer1_cycle = false;

HTU21D SysMon_HTU21D;

boolean _NC_running = false;
boolean _switch_running = false;
boolean _GN1_running = false;
boolean _GN2_running = false;
boolean _GN3_running = false;

byte count_status_report = 0;
long count_time_update_request = 0;
byte count_timeout_heartbeat_NC = 0;
byte count_timeout_heartbeat_switch = 0;
byte count_timeout_heartbeat_GN1 = 0;
byte count_timeout_heartbeat_GN2 = 0;
byte count_timeout_heartbeat_GN3 = 0;
byte count_timeout_power_SysMon = 0;
byte count_timeout_power_NC = 0;
byte count_timeout_power_switch = 0;
byte count_timeout_power_GN1 = 0;
byte count_timeout_power_GN2 = 0;
byte count_timeout_power_GN3 = 0;
byte count_timeout_environ_SysMon = 0;
byte count_timeout_environ_NC = 0;
byte count_timeout_temp_processor_NC = 0;
byte count_timeout_temp_switch = 0;
byte count_timeout_temp_GN1 = 0;
byte count_timeout_temp_GN2 = 0;
byte count_timeout_temp_GN3 = 0;
unsigned int count_device_reboot = 0;

unsigned int latest_power_SysMon;
int latest_environ_temp_SysMon_NC;
byte latest_environ_hum_SysMon_NC;
unsigned int latest_power_NC;
unsigned int latest_temp_NC;
unsigned int latest_power_switch;
unsigned int latest_temp_switch;
unsigned int latest_power_GN1;
unsigned int latest_temp_GN1;
unsigned int latest_power_GN2;
unsigned int latest_temp_GN2;
unsigned int latest_power_GN3;
unsigned int latest_temp_GN3;

// EEPROM addresses whose values are set by node controller:
uint32_t __attribute__((section(".eeprom"))) E_USART_BAUD;
uint16_t __attribute__((section(".eeprom"))) E_USART_RX_BUFFER_SIZE;
uint8_t __attribute__((section(".eeprom"))) E_STATUS_REPORT_PERIOD;
uint8_t __attribute__((section(".eeprom"))) E_MAX_NUM_SOS_BOOT_ATTEMPTS;
uint8_t __attribute__((section(".eeprom"))) E_MAX_NUM_SUBSYSTEM_BOOT_ATTEMPTS;
uint8_t __attribute__((section(".eeprom"))) E_MAX_NUM_PRIMARY_BOOT_ATTEMPTS;
uint16_t __attribute__((section(".eeprom"))) E_DEVICE_REBOOT_PERIOD;
uint8_t __attribute__((section(".eeprom"))) E_PRESENT_SWITCH;
uint16_t __attribute__((section(".eeprom"))) E_BOOT_TIME_NC;
uint16_t __attribute__((section(".eeprom"))) E_CONFIG_TIME_NC;
uint8_t __attribute__((section(".eeprom"))) E_BOOT_TIME_SWITCH;
uint16_t __attribute__((section(".eeprom"))) E_BOOT_TIME_GN1;
uint16_t __attribute__((section(".eeprom"))) E_BOOT_TIME_GN2;
uint16_t __attribute__((section(".eeprom"))) E_BOOT_TIME_GN3;
uint8_t __attribute__((section(".eeprom"))) E_PRESENT_GN1;
uint8_t __attribute__((section(".eeprom"))) E_PRESENT_GN2;
uint8_t __attribute__((section(".eeprom"))) E_PRESENT_GN3;
uint8_t __attribute__((section(".eeprom"))) E_HEARTBEAT_TIMEOUT_NC;
uint8_t __attribute__((section(".eeprom"))) E_HEARTBEAT_TIMEOUT_SWITCH;
uint8_t __attribute__((section(".eeprom"))) E_HEARTBEAT_TIMEOUT_GN1;
uint8_t __attribute__((section(".eeprom"))) E_HEARTBEAT_TIMEOUT_GN2;
uint8_t __attribute__((section(".eeprom"))) E_HEARTBEAT_TIMEOUT_GN3;
uint8_t __attribute__((section(".eeprom"))) E_ENVIRON_TIMEOUT_SYSMON;
uint8_t __attribute__((section(".eeprom"))) E_ENVIRON_TIMEOUT_NC;
uint8_t __attribute__((section(".eeprom"))) E_TEMP_PROCESSOR_TIMEOUT_NC;
uint8_t __attribute__((section(".eeprom"))) E_TEMP_TIMEOUT_SWITCH;
uint8_t __attribute__((section(".eeprom"))) E_TEMP_TIMEOUT_GN1;
uint8_t __attribute__((section(".eeprom"))) E_TEMP_TIMEOUT_GN2;
uint8_t __attribute__((section(".eeprom"))) E_TEMP_TIMEOUT_GN3;
uint8_t __attribute__((section(".eeprom"))) E_POWER_TIMEOUT_SYSMON;
uint8_t __attribute__((section(".eeprom"))) E_POWER_TIMEOUT_NC;
uint8_t __attribute__((section(".eeprom"))) E_POWER_TIMEOUT_SWITCH;
uint8_t __attribute__((section(".eeprom"))) E_POWER_TIMEOUT_GN1;
uint8_t __attribute__((section(".eeprom"))) E_POWER_TIMEOUT_GN2;
uint8_t __attribute__((section(".eeprom"))) E_POWER_TIMEOUT_GN3;
uint16_t __attribute__((section(".eeprom"))) E_TEMP_MIN_SYSMON;
uint16_t __attribute__((section(".eeprom"))) E_TEMP_MAX_SYSMON;
uint16_t __attribute__((section(".eeprom"))) E_TEMP_MIN_NC;
uint16_t __attribute__((section(".eeprom"))) E_TEMP_MAX_NC;
uint16_t __attribute__((section(".eeprom"))) E_TEMP_MIN_PROCESSOR_NC;
uint16_t __attribute__((section(".eeprom"))) E_TEMP_MAX_PROCESSOR_NC;
uint16_t __attribute__((section(".eeprom"))) E_TEMP_MIN_SWITCH;
uint16_t __attribute__((section(".eeprom"))) E_TEMP_MAX_SWITCH;
uint16_t __attribute__((section(".eeprom"))) E_TEMP_MIN_GN1;
uint16_t __attribute__((section(".eeprom"))) E_TEMP_MAX_GN1;
uint16_t __attribute__((section(".eeprom"))) E_TEMP_MIN_GN2;
uint16_t __attribute__((section(".eeprom"))) E_TEMP_MAX_GN2;
uint16_t __attribute__((section(".eeprom"))) E_TEMP_MIN_GN3;
uint16_t __attribute__((section(".eeprom"))) E_TEMP_MAX_GN3;
uint8_t __attribute__((section(".eeprom"))) E_HUMIDITY_MIN_SYSMON;
uint8_t __attribute__((section(".eeprom"))) E_HUMIDITY_MAX_SYSMON;
uint8_t __attribute__((section(".eeprom"))) E_HUMIDITY_MIN_NC;
uint8_t __attribute__((section(".eeprom"))) E_HUMIDITY_MAX_NC;
uint16_t __attribute__((section(".eeprom"))) E_MILLIAMP_MAX_SYSMON;
uint16_t __attribute__((section(".eeprom"))) E_MILLIAMP_MAX_NC;
uint16_t __attribute__((section(".eeprom"))) E_MILLIAMP_MAX_SWITCH;
uint16_t __attribute__((section(".eeprom"))) E_MILLIAMP_MAX_GN1;
uint16_t __attribute__((section(".eeprom"))) E_MILLIAMP_MAX_GN2;
uint16_t __attribute__((section(".eeprom"))) E_MILLIAMP_MAX_GN3;
// EEPROM addresses whose values are not set by node controller:
uint8_t __attribute__((section(".eeprom"))) E_NC_ENABLED;
uint8_t __attribute__((section(".eeprom"))) E_SWITCH_ENABLED;
uint8_t __attribute__((section(".eeprom"))) E_GN1_ENABLED;
uint8_t __attribute__((section(".eeprom"))) E_GN2_ENABLED;
uint8_t __attribute__((section(".eeprom"))) E_GN3_ENABLED;
uint8_t __attribute__((section(".eeprom"))) E_POST_RESULT;
uint8_t __attribute__((section(".eeprom"))) E_TIMER_TEST_INCOMPLETE;
uint8_t __attribute__((section(".eeprom"))) E_NUM_SOS_BOOT_ATTEMPTS;
uint8_t __attribute__((section(".eeprom"))) E_NUM_PRIMARY_BOOT_ATTEMPTS;
uint8_t __attribute__((section(".eeprom"))) E_FIRST_BOOT;



//---------- S E T U P --------------------------------------------------------
/*
 *  Call all appropriate boot routines, depending on enabled/disabled status
 *  of POST.
 *
 *  :rtype: none
 */
void setup()
{
    // Disable watchdog to avoid a reset loop
    __asm__ __volatile__ ( "in __tmp_reg__, __SREG__" "\n\t" "cli" "\n\t" "sts %0, %1" "\n\t" "sts %0, __zero_reg__" "\n\t" "out __SREG__,__tmp_reg__" "\n\t" : /* no outputs */ : "M" (((uint16_t) &((*(volatile uint8_t *)(0x60))))), "r" ((uint8_t)((1 << (4)) | (1 << (3)))) : "r0" );


    delay(4000);
    Serial.begin(57600);
    Serial.println("S0");


    // Is POST enabled?
# 311 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
    // Boot SysMon, node controller, and ethernet switch.  Boot successful?

    Serial.println("S3");


    if(boot_primary())
    {
        // Boot the guest nodes

        Serial.println("S4");

        boot_GN(1);
        boot_GN(2);
        boot_GN(3);
    }

    else
    {

        Serial.println("S5");



        // Grab how many boot attempts have occurred (+1 for this attempt)
        byte num_attempts = __eerd_byte_m32u4(&E_NUM_PRIMARY_BOOT_ATTEMPTS) + 1;

        // Add failed boot attempt to the counter
        __eeupd_byte_m32u4(&E_NUM_PRIMARY_BOOT_ATTEMPTS, num_attempts);

        // Number of boot attempts not yet reached maximum allowed?
        if(num_attempts < __eerd_byte_m32u4(&E_MAX_NUM_PRIMARY_BOOT_ATTEMPTS))
        {

            Serial.println(num_attempts);
            Serial.println(__eerd_byte_m32u4(&E_MAX_NUM_PRIMARY_BOOT_ATTEMPTS));
            Serial.println("Soft Restart");
            delay(2000);

            delay(2000);
//             soft_restart();
        }
        else
        {
            // Clear the counter for number of primary boot attempts.
            // We want to start with a clean slate after reset.
            __eeupd_byte_m32u4(&E_NUM_PRIMARY_BOOT_ATTEMPTS, 0);

            // Give it time to write to EEPROM, just to be sure
            delay(10);


            Serial.println("S.");


            // We're done trying, so go to sleep
            sleep_SysMon();
        }


    }

}



//---------- L O O P ----------------------------------------------------------
/*
 *  Main operation of SysMon.  Monitors the system and keeps track of any
 *  timeouts, then responds appropriately to them.  Any devices that are turned
 *  off but not permanently disabled are rebooted after some time.
 *
 *  :rtype: none
 */
void loop()
{

    // Has the timer finished a cycle?
    if(_timer1_cycle)
    {

        Serial.println("T1");

        // Increment status report counter
        count_status_report++;

        // Increment time request counter
        count_time_update_request++;

        //////
        // Increment/clear timeouts...
        //////

        // Is SysMon's environment unacceptable?
        if(!check_environ_SysMon())
            // Increment counter
            count_timeout_environ_SysMon++;
        else
            // Reset counter (we want to track timeouts, not accumulations)
            count_timeout_environ_SysMon = 0;

        // Is SysMon's power draw unacceptable?
        if(!check_power_SysMon())
            count_timeout_power_SysMon++;
        else
            count_timeout_power_SysMon = 0;


        // Is node controller operating?
        if(_NC_running)
        {
            // Is the node controller's environment unacceptable?
            if(!check_environ_NC())
                count_timeout_environ_NC++;
            else
                count_timeout_environ_NC = 0;

            // Is the node controller's processor temperature unacceptable?
            if(!check_temp_NC())
                count_timeout_temp_processor_NC++;
            else
                count_timeout_temp_processor_NC = 0;

            // Is the node controller's power draw unacceptable?
            if(!check_power_NC())
                count_timeout_power_NC++;
            else
                count_timeout_power_NC = 0;

            // Is the node controller's heartbeat not detected?
            if(!check_heartbeat_odroid(5))
                count_timeout_heartbeat_NC++;
            else
                count_timeout_heartbeat_NC = 0;
        }


        // Is ethernet switch operating?
        if(_switch_running)
        {
            // Is the ethernet switch's temperature unacceptable?
            if(!check_temp_switch())
                count_timeout_temp_switch++;
            else
                count_timeout_temp_switch = 0;

            // Is the ethernet switch's power draw unacceptable?
            if(!check_power_switch())
                count_timeout_power_switch++;
            else
                count_timeout_power_switch = 0;
        }


        // Is guest node 1 operating?
        if(_GN1_running)
        {
            // Is the guest node's temperature unacceptable?
            if(!check_temp_GN(1))
                count_timeout_temp_GN1++;
            else
                count_timeout_temp_GN1 = 0;

            // Is the guest node's power draw unacceptable?
            if(!check_power_GN(1))
                count_timeout_power_GN1++;
            else
                count_timeout_power_GN1 = 0;

            // Is the guest node's heartbeat not detected?
            if(!check_heartbeat_odroid(9))
                count_timeout_heartbeat_GN1++;
            else
                count_timeout_heartbeat_GN1 = 0;
        }


        // Is guest node 2 operating?
        if(_GN2_running)
        {
            // Is the guest node's temperature unacceptable?
            if(!check_temp_GN(2))
                count_timeout_temp_GN2++;
            else
                count_timeout_temp_GN2 = 0;

            // Is the guest node's power draw unacceptable?
            if(!check_power_GN(2))
                count_timeout_power_GN2++;
            else
                count_timeout_power_GN2 = 0;

            // Is the guest node's heartbeat not detected?
            if(!check_heartbeat_odroid(11))
                count_timeout_heartbeat_GN2++;
            else
                count_timeout_heartbeat_GN2 = 0;
        }


        // Is guest node 3 operating?
        if(_GN3_running)
        {
            // Is the guest node's temperature unacceptable?
            if(!check_temp_GN(3))
                count_timeout_temp_GN3++;
            else
                count_timeout_temp_GN3 = 0;

            // Is the guest node's power draw unacceptable?
            if(!check_power_GN(3))
                count_timeout_power_GN3++;
            else
                count_timeout_power_GN3 = 0;

            // Is the guest node's heartbeat not detected?
            if(!check_heartbeat_odroid(13))
                count_timeout_heartbeat_GN3++;
            else
                count_timeout_heartbeat_GN3 = 0;
        }


        // Increment counter for rebooting devices that aren't running
        count_device_reboot++;


        //////
        // React to timeouts...
        //////

        // Bad power timeout for SysMon?
        if(count_timeout_power_SysMon >= __eerd_byte_m32u4(&E_POWER_TIMEOUT_SYSMON))
        {
            // Inform node controller of the problem
            send_problem("SM,p");

            // Clear all of SysMon's timeout counters
            count_timeout_power_SysMon = 0;
            count_timeout_environ_SysMon = 0;

            // Reboot SysMon
            do { __asm__ __volatile__ ( "in __tmp_reg__,__SREG__" "\n\t" "cli" "\n\t" "wdr" "\n\t" "sts %0,%1" "\n\t" "out __SREG__,__tmp_reg__" "\n\t" "sts %0,%2" "\n\t" : /* no outputs */ : "M" (((uint16_t) &((*(volatile uint8_t *)(0x60))))), "r" ((1 << (4)) | (1 << (3))), "r" ((uint8_t) ((0 & 0x08 ? (1 << (5)) : 0x00) | (1 << (3)) | (0 & 0x07)) ) : "r0" ); for(;;) { } } while(0);
        }
        // Bad environment timeout for SysMon?
        else if(count_timeout_environ_SysMon >= __eerd_byte_m32u4(&E_ENVIRON_TIMEOUT_SYSMON))
        {
            // Inform node controller of the problem
            send_problem("SM,e");

            // Clear all of SysMon's timeout counters
            count_timeout_power_SysMon = 0;
            count_timeout_environ_SysMon = 0;

            // Reboot SysMon
            do { __asm__ __volatile__ ( "in __tmp_reg__,__SREG__" "\n\t" "cli" "\n\t" "wdr" "\n\t" "sts %0,%1" "\n\t" "out __SREG__,__tmp_reg__" "\n\t" "sts %0,%2" "\n\t" : /* no outputs */ : "M" (((uint16_t) &((*(volatile uint8_t *)(0x60))))), "r" ((1 << (4)) | (1 << (3))), "r" ((uint8_t) ((0 & 0x08 ? (1 << (5)) : 0x00) | (1 << (3)) | (0 & 0x07)) ) : "r0" ); for(;;) { } } while(0);
        }


        // Is node controller operating?
        if(_NC_running)
        {
            // Bad heartbeat timeout for NC?
            if(count_timeout_heartbeat_NC >= __eerd_byte_m32u4(&E_HEARTBEAT_TIMEOUT_NC))
            {
                // Inform node controller of the problem
                send_problem("NC,h");

                // Clear all of NC's timeout counters
                count_timeout_power_NC = 0;
                count_timeout_temp_processor_NC = 0;
                count_timeout_environ_NC = 0;
                count_timeout_heartbeat_NC = 0;

                // Reboot the node controller
                boot_NC();
            }
            // Bad power timeout for NC?
            else if(count_timeout_power_NC >= __eerd_byte_m32u4(&E_POWER_TIMEOUT_NC))
            {
                // Inform node controller of the problem
                send_problem("NC,p");

                // Clear all of NC's timeout counters
                count_timeout_power_NC = 0;
                count_timeout_temp_processor_NC = 0;
                count_timeout_environ_NC = 0;
                count_timeout_heartbeat_NC = 0;

                // Reboot the node controller
                boot_NC();
            }
            // Bad environment timeout for NC?
            else if(count_timeout_environ_NC >= __eerd_byte_m32u4(&E_ENVIRON_TIMEOUT_NC))
            {
                // Inform node controller of the problem
                send_problem("NC,e");

                // Clear all of NC's timeout counters
                count_timeout_power_NC = 0;
                count_timeout_temp_processor_NC = 0;
                count_timeout_environ_NC = 0;
                count_timeout_heartbeat_NC = 0;

                // Reboot the node controller
                boot_NC();
            }
            // Bad processor temperature timeout for NC?
            else if(count_timeout_temp_processor_NC >= __eerd_byte_m32u4(&E_TEMP_PROCESSOR_TIMEOUT_NC))
            {
                // Inform node controller of the problem
                send_problem("NC,t");

                // Clear all of NC's timeout counters
                count_timeout_power_NC = 0;
                count_timeout_temp_processor_NC = 0;
                count_timeout_environ_NC = 0;
                count_timeout_heartbeat_NC = 0;

                // Reboot the node controller
                boot_NC();
            }
        }


        // Is ethernet switch operating?
        if(_switch_running)
        {
            // Bad power timeout for ethernet switch?
            if(count_timeout_power_switch >= __eerd_byte_m32u4(&E_POWER_TIMEOUT_SWITCH))
            {
                // Inform node controller of the problem
                send_problem("SW,p");

                // Clear all of switch's timeout counters
                count_timeout_power_switch = 0;
                count_timeout_temp_switch = 0;

                // Reboot the switch
                boot_switch();
            }
            // Bad temperature timeout for ethernet switch?
            else if(count_timeout_temp_switch >= __eerd_byte_m32u4(&E_TEMP_TIMEOUT_SWITCH))
            {
                // Inform node controller of the problem
                send_problem("SW,t");

                // Clear all of switch's timeout counters
                count_timeout_power_switch = 0;
                count_timeout_temp_switch = 0;

                // Reboot the switch
                boot_switch();

                // Clear latest readings, in case the device failed to boot.
                // This is so the status report doesn't keep reporting the last
                // non-zero values.
                latest_power_switch = 0;
                latest_temp_switch = 0;
            }
        }


        // Is guest node 1 operating?
        if(_GN1_running)
        {
            // Bad power timeout for guest node 1?
            if(count_timeout_power_GN1 >= __eerd_byte_m32u4(&E_POWER_TIMEOUT_GN1))
            {
                // Inform node controller of the problem
                send_problem("GN1,p");

                // Clear all of guest node's timeout counters
                count_timeout_power_GN1 = 0;
                count_timeout_temp_GN1 = 0;
                count_timeout_heartbeat_GN1 = 0;

                // Reboot guest node
                boot_GN(1);

                // Clear latest readings, in case the device failed to boot.
                // This is so the status report doesn't keep reporting the last
                // non-zero values.
                latest_power_GN1 = 0;
                latest_temp_GN1 = 0;
            }
            // Bad temperature timeout for guest node 1?
            else if(count_timeout_temp_GN1 >= __eerd_byte_m32u4(&E_TEMP_TIMEOUT_GN1))
            {
                // Inform node controller of the problem
                send_problem("GN1,t");

                // Clear all of guest node's timeout counters
                count_timeout_power_GN1 = 0;
                count_timeout_temp_GN1 = 0;
                count_timeout_heartbeat_GN1 = 0;

                // Reboot guest node
                boot_GN(1);

                // Clear latest readings, in case the device failed to boot.
                // This is so the status report doesn't keep reporting the last
                // non-zero values.
                latest_power_GN1 = 0;
                latest_temp_GN1 = 0;
            }
            // Bad heartbeat timeout for guest node 1?
            else if(count_timeout_heartbeat_GN1 >= __eerd_byte_m32u4(&E_HEARTBEAT_TIMEOUT_GN1))
            {
                // Inform node controller of the problem
                send_problem("GN1,h");

                // Clear all of guest node's timeout counters
                count_timeout_power_GN1 = 0;
                count_timeout_temp_GN1 = 0;
                count_timeout_heartbeat_GN1 = 0;

                // Reboot guest node
                boot_GN(1);

                // Clear latest readings, in case the device failed to boot.
                // This is so the status report doesn't keep reporting the last
                // non-zero values.
                latest_power_GN1 = 0;
                latest_temp_GN1 = 0;
            }
        }


        // Is guest node 2 operating?
        if(_GN2_running)
        {
            // Bad power timeout for guest node 2?
            if(count_timeout_power_GN2 >= __eerd_byte_m32u4(&E_POWER_TIMEOUT_GN2))
            {
                // Inform node controller of the problem
                send_problem("GN2,p");

                // Clear all of guest node's timeout counters
                count_timeout_power_GN2 = 0;
                count_timeout_temp_GN2 = 0;
                count_timeout_heartbeat_GN2 = 0;

                // Reboot guest node
                boot_GN(2);

                // Clear latest readings, in case the device failed to boot.
                // This is so the status report doesn't keep reporting the last
                // non-zero values.
                latest_power_GN2 = 0;
                latest_temp_GN2 = 0;
            }
            // Bad temperature timeout for guest node 2?
            else if(count_timeout_temp_GN2 >= __eerd_byte_m32u4(&E_TEMP_TIMEOUT_GN2))
            {
                // Inform node controller of the problem
                send_problem("GN2,t");

                // Clear all of guest node's timeout counters
                count_timeout_power_GN2 = 0;
                count_timeout_temp_GN2 = 0;
                count_timeout_heartbeat_GN2 = 0;

                // Reboot guest node
                boot_GN(2);

                // Clear latest readings, in case the device failed to boot.
                // This is so the status report doesn't keep reporting the last
                // non-zero values.
                latest_power_GN2 = 0;
                latest_temp_GN2 = 0;
            }
            // Bad heartbeat timeout for guest node 2?
            else if(count_timeout_heartbeat_GN2 >= __eerd_byte_m32u4(&E_HEARTBEAT_TIMEOUT_GN2))
            {
                // Inform node controller of the problem
                send_problem("GN2,h");

                // Clear all of guest node's timeout counters
                count_timeout_power_GN2 = 0;
                count_timeout_temp_GN2 = 0;
                count_timeout_heartbeat_GN2 = 0;

                // Reboot guest node
                boot_GN(2);

                // Clear latest readings, in case the device failed to boot.
                // This is so the status report doesn't keep reporting the last
                // non-zero values.
                latest_power_GN2 = 0;
                latest_temp_GN2 = 0;
            }
        }


        // Is guest node 3 operating?
        if(_GN3_running)
        {
            // Bad power timeout for guest node 3?
            if(count_timeout_power_GN3 >= __eerd_byte_m32u4(&E_POWER_TIMEOUT_GN3))
            {
                // Inform node controller of the problem
                send_problem("GN3,p");

                // Clear all of guest node's timeout counters
                count_timeout_power_GN3 = 0;
                count_timeout_temp_GN3 = 0;
                count_timeout_heartbeat_GN3 = 0;

                // Reboot guest node
                boot_GN(3);

                // Clear latest readings, in case the device failed to boot.
                // This is so the status report doesn't keep reporting the last
                // non-zero values.
                latest_power_GN3 = 0;
                latest_temp_GN3 = 0;
            }
            // Bad temperature timeout for guest node 3?
            else if(count_timeout_temp_GN3 >= __eerd_byte_m32u4(&E_TEMP_TIMEOUT_GN3))
            {
                // Inform node controller of the problem
                send_problem("GN3,t");

                // Clear all of guest node's timeout counters
                count_timeout_power_GN3 = 0;
                count_timeout_temp_GN3 = 0;
                count_timeout_heartbeat_GN3 = 0;

                // Reboot guest node
                boot_GN(3);

                // Clear latest readings, in case the device failed to boot.
                // This is so the status report doesn't keep reporting the last
                // non-zero values.
                latest_power_GN3 = 0;
                latest_temp_GN3 = 0;
            }
            // Bad heartbeat timeout for guest node 3?
            else if(count_timeout_heartbeat_GN3 >= __eerd_byte_m32u4(&E_HEARTBEAT_TIMEOUT_GN3))
            {
                // Inform node controller of the problem
                send_problem("GN3,h");

                // Clear all of guest node's timeout counters
                count_timeout_power_GN3 = 0;
                count_timeout_temp_GN3 = 0;
                count_timeout_heartbeat_GN3 = 0;

                // Reboot guest node
                boot_GN(3);

                // Clear latest readings, in case the device failed to boot.
                // This is so the status report doesn't keep reporting the last
                // non-zero values.
                latest_power_GN3 = 0;
                latest_temp_GN3 = 0;
            }
        }


        // Time to send a status report?
        if(count_status_report >= __eerd_byte_m32u4(&E_STATUS_REPORT_PERIOD))
        {
            // Clear the counter
            count_status_report = 0;

            // Send it
            send_status();
        }


        // Time to request updated time from NC?
        if(count_time_update_request >= 3600)
        {
            // Clear the counter
            count_time_update_request = 0;

            // Request time
            get_time_NC();
        }

        // Received a new serial character?
        if(Serial.available() > 0)
        {
            char incoming = Serial.read();

            // Which request was received?
            if(incoming == '1')
                send_time();
            else if(incoming == '2')
                send_status();
            else if(incoming == '3')
                boot_NC();
            else if(incoming == '4')
                boot_switch();
            else if(incoming == '5')
                boot_GN(1);
            else if(incoming == '6')
                boot_GN(2);
            else if(incoming == '7')
                boot_GN(3);
        }


        // Time to try to reboot any devices that aren't running?
        if(count_device_reboot >= __eerd_word_m32u4(&E_DEVICE_REBOOT_PERIOD))
        {
            // Clear the counter
            count_device_reboot = 0;

            // Is the node controller enabled but not running?
            if((! _NC_running) && __eerd_byte_m32u4(&E_NC_ENABLED))
                // Try to boot the node controller
                boot_NC();

            // Is the ethernet switch enabled but not running?
            if((! _switch_running) && __eerd_byte_m32u4(&E_SWITCH_ENABLED)
                && __eerd_byte_m32u4(&E_PRESENT_SWITCH))
                // Try to boot the switch
                boot_switch();

            // Is the guest node present & enabled but not running?
            if((! _GN1_running) && __eerd_byte_m32u4(&E_GN1_ENABLED)
                && __eerd_byte_m32u4(&E_PRESENT_GN1))
                // Try to boot the guest node
                boot_GN(1);

            // Is the guest node present & enabled but not running?
            if((! _GN2_running) && __eerd_byte_m32u4(&E_GN2_ENABLED)
                && __eerd_byte_m32u4(&E_PRESENT_GN2))
                // Try to boot the guest node
                boot_GN(2);

            // Is the guest node present & enabled but not running?
            if((! _GN3_running) && __eerd_byte_m32u4(&E_GN3_ENABLED)
                && __eerd_byte_m32u4(&E_PRESENT_GN3))
                // Try to boot the guest node
                boot_GN(3);
        }


        // Clear the flag for the next timer cycle
        _timer1_cycle = false;
    }
}



//---------- C H E C K _ E N V I R O N _ N C ----------------------------------
/*
 *  Reads the HTU21D sensor.
 *
 *  Return TRUE: environment is acceptable.
 *  Return FALSE: environment is unacceptable.
 *
 *  :rtype: boolean
 */
boolean check_environ_NC()
{
    // Read temperature and truncate it (so we don't deal with floats)
    latest_environ_temp_SysMon_NC = (int)SysMon_HTU21D.readTemperature();

    // Read humidity and truncate it (so we don't deal with floats)
    latest_environ_hum_SysMon_NC = (byte)SysMon_HTU21D.readHumidity();

    // Is measured temperature acceptable?
    if(((int)__eerd_word_m32u4(&E_TEMP_MIN_NC) < latest_environ_temp_SysMon_NC)
        && (latest_environ_temp_SysMon_NC < (int)__eerd_word_m32u4(&E_TEMP_MAX_NC))
        && (__eerd_byte_m32u4(&E_HUMIDITY_MIN_NC) < latest_environ_hum_SysMon_NC)
        && (latest_environ_hum_SysMon_NC < __eerd_byte_m32u4(&E_HUMIDITY_MAX_NC)))
    {
        // Exit with success
        return true;
    }

    // Exit with failure
    return false;
}



//---------- C H E C K _ E N V I R O N _ S Y S M O N --------------------------
/*
 *  Reads the HTU21D sensor.
 *
 *  Return TRUE: environment is acceptable.
 *  Return FALSE: environment is unacceptable.
 *
 *  :rtype: boolean
 */
boolean check_environ_SysMon()
{
    // Read temperature and truncate it (so we don't deal with floats)
    latest_environ_temp_SysMon_NC = (int)SysMon_HTU21D.readTemperature();

    // Read humidity and truncate it (so we don't deal with floats)
    latest_environ_hum_SysMon_NC = (byte)SysMon_HTU21D.readHumidity();

    // Is measured temperature acceptable?
    if(((int)__eerd_word_m32u4(&E_TEMP_MIN_SYSMON) < latest_environ_temp_SysMon_NC)
        && (latest_environ_temp_SysMon_NC < (int)__eerd_word_m32u4(&E_TEMP_MAX_SYSMON))
        && (__eerd_byte_m32u4(&E_HUMIDITY_MIN_SYSMON) < latest_environ_hum_SysMon_NC)
        && (latest_environ_hum_SysMon_NC < __eerd_byte_m32u4(&E_HUMIDITY_MAX_SYSMON)))
    {
        // Exit with success
        return true;
    }

    // Exit with failure
    return false;
}



//---------- C H E C K _ H E A R T B E A T _ O D R O I D ----------------------
/*
 *  Checks that the ODroid is alive and sending a heartbeat.
 *
 *  Return TRUE: heartbeat is good.
 *  Return FALSE: heartbeat is not good.
 *
 *  :param byte device: the pin number of the device being checked
 *
 *  :rtype: boolean
 */
boolean check_heartbeat_odroid(byte device)
{
    boolean result = false;

    // Get first heartbeat sample
    byte sample1 = digitalRead(device);

    // Wait for half the heartbeat period
    delay(40 / 2);

    // Get second heartbeat sample
    byte sample2 = digitalRead(device);

    // Are the samples different? (which indicates a changing heartbeat)
    if(sample1 != sample2)
        // Success!
        result = true;
    else
    {
        // Trying one more time, in case we encountered edges...

        // Wait just a bit to move past possible edges
        delay(2);

        // Get first heartbeat sample
        sample1 = digitalRead(device);

        // Wait for half the heartbeat period
        delay(40 / 2);

        // Get second heartbeat sample
        sample2 = digitalRead(device);

        // Are the samples different? (which indicates a changing heartbeat)
        if(sample1 != sample2)
            // Success!
            result = true;
    }

    delay(2000);

    return result;
}



//---------- C H E C K _ P O W E R _ G N --------------------------------------
/*
 *  Reads the specified guest node's current sensor.
 *
 *  Return TRUE: guest node is drawing expected current.
 *  Return FALSE: guest node is drawing no/too much current.
 *
 *  :param byte gn: which guest node's power draw to check (1, 2 or 3)
 *
 *  :rtype: boolean
 */
boolean check_power_GN(byte gn)
{
    byte msb, csb, lsb;
    int addr;

    // Which guest node is being checked?
    switch (gn) {
        case 1:
            // Assign the correct I2C address
            addr = 0x68;
            break;

        case 2:
            // Assign the correct I2C address
            addr = 0x6A;
            break;

        case 3:
            // Assign the correct I2C address
            addr = 0x6B;
            break;

        default:
            // Invalid guest node, so exit with failure
            return false;
    }

    // Start I2C transaction with current sensor
    Wire.beginTransmission(addr);
    // Tell sensor we want to read "data" register
    Wire.write(0);
    // Sensor expects restart condition, so end I2C transaction (no stop bit)
    Wire.endTransmission(0);
    // Ask sensor for data
    Wire.requestFrom(addr, 3);

    // Read the 3 bytes that the sensor returns
    if(Wire.available())
    {
        msb = Wire.read();
        // We only care about the data, so the mask hides the SYNC flag
        csb = Wire.read() & 0x01;
        lsb = Wire.read();
    }
    else
        // Exit with failure
        return false;

    // End I2C transaction (with stop bit)
    Wire.endTransmission(1);

    // Calculate milliamps from raw sensor data
    unsigned int milliamps = ((csb << 8) | lsb) * 16;

    // Which guest node is being checked?
    switch (gn) {
        case 1:
            // Store power reading in global variable
            latest_power_GN1 = milliamps;

            // Is measured current below allowed maximum?
            if(latest_power_GN1 < __eerd_word_m32u4(&E_MILLIAMP_MAX_GN1))
                // Exit with success
                return true;

            break;

        case 2:
            // Store power reading in global variable
            latest_power_GN2 = milliamps;

            // Is measured current below allowed maximum?
            if(latest_power_GN2 < __eerd_word_m32u4(&E_MILLIAMP_MAX_GN2))
                // Exit with success
                return true;

            break;

        case 3:
            // Store power reading in global variable
            latest_power_GN3 = milliamps;

            // Is measured current below allowed maximum?
            if(latest_power_GN3 < __eerd_word_m32u4(&E_MILLIAMP_MAX_GN3))
                // Exit with success
                return true;

            break;

        default:
            // Invalid guest node, so exit with failure
            return false;
    }

    // Exit with failure
    return false;
}



//---------- C H E C K _ P O W E R _ N C --------------------------------------
/*
 *  Reads the node controller's current sensor.
 *
 *  Return TRUE: node controller is drawing expected current.
 *  Return FALSE: node controller is drawing no/too much current.
 *
 *  :rtype: boolean
 */
boolean check_power_NC()
{
    byte msb, csb, lsb;

    // Start I2C transaction with current sensor
    Wire.beginTransmission(0x62);
    // Tell sensor we want to read "data" register
    Wire.write(0);
    // Sensor expects restart condition, so end I2C transaction (no stop bit)
    Wire.endTransmission(0);
    // Ask sensor for data
    Wire.requestFrom(0x62, 3);

    // Read the 3 bytes that the sensor returns
    if(Wire.available())
    {
        msb = Wire.read();
        // We only care about the data, so the mask hides the SYNC flag
        csb = Wire.read() & 0x01;
        lsb = Wire.read();
    }
    else
        // Exit with failure
        return false;

    // End I2C transaction (with stop bit)
    Wire.endTransmission(1);

    // Calculate milliamps from raw sensor data
    latest_power_NC = ((csb << 8) | lsb) * 16;

    // Is measured current below allowed maximum?
    if(latest_power_NC < __eerd_word_m32u4(&E_MILLIAMP_MAX_NC))
        // Exit with success
        return true;

    // Exit with failure
    return false;
}



//---------- C H E C K _ P O W E R _ S W I T C H ------------------------------
/*
 *  Reads the network switch's current sensor.
 *
 *  Return TRUE: switch is drawing expected current.
 *  Return FALSE: switch is drawing no/too much current.
 *
 *  :rtype: boolean
 */
boolean check_power_switch()
{
    byte msb, csb, lsb;

    // Start I2C transaction with current sensor
    Wire.beginTransmission(0x63);
    // Tell sensor we want to read "data" register
    Wire.write(0);
    // Sensor expects restart condition, so end I2C transaction (no stop bit)
    Wire.endTransmission(0);
    // Ask sensor for data
    Wire.requestFrom(0x63, 3);

    // Read the 3 bytes that the sensor returns
    if(Wire.available())
    {
        msb = Wire.read();
        // We only care about the data, so the mask hides the SYNC flag
        csb = Wire.read() & 0x01;
        lsb = Wire.read();
    }
    else
        // Exit with failure
        return false;

    // End I2C transaction (with stop bit)
    Wire.endTransmission(1);

    // Calculate milliamps from raw sensor data
    latest_power_switch = ((csb << 8) | lsb) * 16;

    // Is measured current below allowed maximum?
    if(latest_power_switch < __eerd_word_m32u4(&E_MILLIAMP_MAX_SWITCH))
        // Exit with success
        return true;

    // Exit with failure
    return false;
}



//---------- C H E C K _ P O W E R _ S Y S M O N ------------------------------
/*
 *  Reads the SysMon's current sensor.
 *
 *  Return TRUE: SysMon is drawing expected current.
 *  Return FALSE: SysMon is drawing too much current.
 *
 *  :rtype: boolean
 */
boolean check_power_SysMon()
{
    byte msb, csb, lsb;

    // Start I2C transaction with current sensor
    Wire.beginTransmission(0x60);
    // Tell sensor we want to read "data" register
    Wire.write(0);
    // Sensor expects restart condition, so end I2C transaction (no stop bit)
    Wire.endTransmission(0);
    // Ask sensor for data
    Wire.requestFrom(0x60, 3);

    // Read the 3 bytes that the sensor returns
    if(Wire.available())
    {
        msb = Wire.read();
        // We only care about the data, so the mask hides the SYNC flag
        csb = Wire.read() & 0x01;
        lsb = Wire.read();
    }
    else
        // Exit with failure
        return false;

    // End I2C transaction (with stop bit)
    Wire.endTransmission(1);

    // Calculate milliamps from raw sensor data
    latest_power_SysMon = ((csb << 8) | lsb) * 16;

    // Is measured current below allowed maximum?
    if(latest_power_SysMon < __eerd_word_m32u4(&E_MILLIAMP_MAX_SYSMON))
        // Exit with success
        return true;

    // Exit with failure
    return false;
}



//---------- C H E C K _ T E M P _ G N ----------------------------------------
/*
 *  Reads the thermistor for the specified guest node.
 *
 *  Return TRUE: temperature is acceptable.
 *  Return FALSE: temperature is unacceptable.
 *
 *  :param byte gn: which guest node's temperature to check (1, 2 or 3)
 *
 *  :rtype: boolean
 */
boolean check_temp_GN(byte gn)
{
    // Which guest node is being checked?
    switch (gn) {
        case 1:
            // Get ADC result from thermistor
            latest_temp_GN1 = analogRead(A2);

            // Is measured temperature acceptable?
            if((__eerd_word_m32u4(&E_TEMP_MIN_GN1) < latest_temp_GN1)
                && (latest_temp_GN1 < __eerd_word_m32u4(&E_TEMP_MAX_GN1)))
            {
                // Exit with success
                return true;
            }
            else
                // Exit with failure
                return false;

        case 2:
            // Get ADC result from thermistor
            latest_temp_GN2 = analogRead(A3);

            // Is measured temperature acceptable?
            if((__eerd_word_m32u4(&E_TEMP_MIN_GN2) < latest_temp_GN2)
                && (latest_temp_GN2 < __eerd_word_m32u4(&E_TEMP_MAX_GN2)))
            {
                // Exit with success
                return true;
            }
            else
                // Exit with failure
                return false;

        case 3:
            // Get ADC result from thermistor
            latest_temp_GN3 = analogRead(A4);

            // Is measured temperature acceptable?
            if((__eerd_word_m32u4(&E_TEMP_MIN_GN3) < latest_temp_GN3)
                && (latest_temp_GN3 < __eerd_word_m32u4(&E_TEMP_MAX_GN3)))
            {
                // Exit with success
                return true;
            }
            else
                // Exit with failure
                return false;

        default:
            // Invalid guest node, so exit with failure
            return false;
    }
}



//---------- C H E C K _ T E M P _ N C ----------------------------------------
/*
 *  Reads the node controller's thermistor to determine if the processor's
 *  temperature is within the safe operating parameters.
 *
 *  Return TRUE: temperature is safe.
 *  Return FALSE: temperature is unsafe.
 *
 *  :rtype: boolean
 */
boolean check_temp_NC()
{
    // Read thermistor
    latest_temp_NC = analogRead(A0);

    // Is measured temperature acceptable?
    if((__eerd_word_m32u4(&E_TEMP_MIN_PROCESSOR_NC) < latest_temp_NC)
        && (latest_temp_NC < __eerd_word_m32u4(&E_TEMP_MAX_PROCESSOR_NC)))
    {
        // Exit with success
        return true;
    }

    // Exit with failure
    return false;
}



//---------- C H E C K _ T E M P _ S W I T C H --------------------------------
/*
 *  Reads the switch's thermistor to determine if the temperature is within
 *  the safe operating parameters.
 *
 *  Return TRUE: temperature is safe.
 *  Return FALSE: temperature is unsafe.
 *
 *  :rtype: boolean
 */
boolean check_temp_switch()
{
    // Read thermistor
    latest_temp_switch = analogRead(A1);

    // Is measured temperature acceptable?
    if((__eerd_word_m32u4(&E_TEMP_MIN_SWITCH) < latest_temp_switch)
        && (latest_temp_switch < __eerd_word_m32u4(&E_TEMP_MAX_SWITCH)))
    {
        // Exit with success
        return true;
    }

    // Exit with failure
    return false;
}



//---------- G E T _ T I M E _ N C --------------------------------------------
/*
 *  Requests a time update from the node controller.  If an update is received,
 *  the RTC is set to the new time.
 *
 *  :rtype: none
 */
void get_time_NC()
{
    // Send request
    Serial.println('*');

    // Save the node controller's response into a string.
    // Default timeout value is 1 second
    String received_time = "";
    received_time = Serial.readStringUntil('!');

    // Was time received?
    if(received_time.length() > 0)
    {
        // Convert received time (string) to a number
        unsigned long seconds_since_epoch = received_time.toInt();

        // Set RTC time
        RTC.set(seconds_since_epoch);
    }
}



//---------- P O W E R _ C Y C L E  -------------------------------------------
/*
 *  Power cycle the device specified by the argument.
 *
 *  :param byte device: pin number of the relay to power cycle
 *
 *  :rtype: none
 */
void power_cycle(byte device)
{
    // Turn off the device
    digitalWrite(device, 0x0);
    // Wait for it...
    delay(2000);
    // Turn on the device
    digitalWrite(device, 0x1);
}



//---------- S E N D _ P R O B L E M ------------------------------------------
/*
 *  Sends a problem report to the node controller.
 *
 *  :param String problem: description of the problem
 *
 *  :rtype: none
 */
void send_problem(String problem)
{
    // Tell the node controller that a problem report is coming
    Serial.println('#');

    // Give it time to get ready
    delay(10);

    // Prepend the timestamp
    problem = String(RTC.get()) + ',' + problem;

    // Send problem report
    Serial.println(problem);

    // Give it time to send, in case another message is going to be sent
    // right after this
    delay(10);
}



//---------- S E N D _ S T A T U S --------------------------------------------
/*
 *  Sends a status report of all important info to the node controller.
 *
 *  Message structure:
 *  RTC time (seconds since epoch),
 *  Light level (ADC value),
 *  Current draw (SysMon) (mA),
 *  Environment temperature (SysMon & NC) (Celsius),
 *  Relative humidity (SysMon & NC) (%),
 *  Current draw (NC) (mA),
 *  Temperature of processor (NC) (ADC value),
 *  Enabled/disabled (switch),
 *  Running/not running (switch),
 *  Current draw (switch) (mA),
 *  Temperature (switch) (ADC value),
 *  Enabled/disabled (GN 1),
 *  Running/not running (GN 1),
 *  Current draw (GN 1) (mA),
 *  Temperature (GN 1) (ADC value),
 *  Enabled/disabled (GN 2),
 *  Running/not running (GN 2),
 *  Current draw (GN 2) (mA),
 *  Temperature (GN 2) (ADC value),
 *  Enabled/disabled (GN 3),
 *  Running/not running (GN 3),
 *  Current draw (GN 3) (mA),
 *  Temperature (GN 3) (ADC value)
 *
 *  :rtype: none
 */
void send_status()
{
    String message = "";

    // Tell the node controller that a status report is coming
    Serial.println('@');

    // Give it time to get ready
    delay(10);

    // Assemble the message
    message += String(RTC.get()) + ',';
    message += String(analogRead(A5)) + ',';
    message += String(latest_power_SysMon) + ',';
    message += String(latest_environ_temp_SysMon_NC) + ',';
    message += String(latest_environ_hum_SysMon_NC) + ',';
    message += String(latest_power_NC) + ',';
    message += String(latest_temp_NC) + ',';
    if(__eerd_byte_m32u4(&E_SWITCH_ENABLED))
        message += String(1) + ',';
    else
        message += String(0) + ',';
    message += String(_switch_running) + ',';
    message += String(latest_power_switch) + ',';
    message += String(latest_temp_switch) + ',';
    if(__eerd_byte_m32u4(&E_GN1_ENABLED))
        message += String(1) + ',';
    else
        message += String(0) + ',';
    message += String(_GN1_running) + ',';
    message += String(latest_power_GN1) + ',';
    message += String(latest_temp_GN1) + ',';
    if(__eerd_byte_m32u4(&E_GN2_ENABLED))
        message += String(1) + ',';
    else
        message += String(0) + ',';
    message += String(_GN2_running) + ',';
    message += String(latest_power_GN2) + ',';
    message += String(latest_temp_GN2) + ',';
    if(__eerd_byte_m32u4(&E_GN3_ENABLED))
        message += String(1) + ',';
    else
        message += String(0) + ',';
    message += String(_GN3_running) + ',';
    message += String(latest_power_GN3) + ',';
    message += String(latest_temp_GN3);

    // Send it
    Serial.println(message);
}



//---------- S E N D _ T I M E ------------------------------------------------
/*
 *  Sends the RTC time to the node controller.
 *
 *  :rtype: none
 */
void send_time()
{
    // Tell the node controller that a time report is coming
    Serial.println('(');

    // Give it time to get ready
    delay(10);

    // Get time from RTC and send it to the node controller
    Serial.println(RTC.get());
}



//---------- S L E E P _ S Y S M O N ------------------------------------------
/*
 *  Puts SysMon into sleep mode.
 *
 *  :rtype: none
 */
void sleep_SysMon()
{
    // Try disabling watchdog before noInterrupts() and see if chip
    // stays asleep.
    // Disable interrupts to stop things from waking up SysMon
    // noInterrupts();

    // Go to sleep
    // sleep_mode();



    // Temporary patch until sleep is working.
    // Should disable/clear all timer registers.
    // Should disable watchdog.
    // The goal is to have minimal core activity.
    // Infinite loop with nop().
    digitalWrite(4, 0x0);
    digitalWrite(6, 0x0);
    digitalWrite(8, 0x0);
    digitalWrite(10, 0x0);
    digitalWrite(12, 0x0);
    while(1);
}



//---------- T I M E R 1 _ O V E R F L O W _ I N T E R R U P T ----------------
/*
 *  Interrupt for Timer1 overflow.  Resets the watchdog and increments the
 *  counter used to tell the MCU when to check the environment.
 *
 *  :rtype: none
 */
extern "C" void __vector_20 /* Timer/Counter1 Overflow */ (void) __attribute__ ((signal,used, externally_visible)) ; void __vector_20 /* Timer/Counter1 Overflow */ (void)
{
    // Reset watchdog
    __asm__ __volatile__ ("wdr");

    // Set the flag to indicate a complete timer cycle
    _timer1_cycle = true;
}
# 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/POST.ino"
//---------- C O N S T A N T S ------------------------------------------------
const byte RESET_POWER_ON = 0;
const byte RESET_EXTERNAL = 1;
const byte RESET_BROWN_OUT = 2;
const byte RESET_WATCHDOG = 3;
const byte RESET_JTAG = 4;
const byte RESET_USB = 5;

const byte FAIL_GPRF = 1;
const byte FAIL_STACK = 2;
const byte FAIL_SREG = 3;
const byte FAIL_SRAM = 4;
const byte FAIL_FLASH = 5;
const byte FAIL_WATCHDOG = 6;
const byte FAIL_ADC = 7;
const byte FAIL_TIMER1 = 8;
const byte FAIL_INTERRUPT = 9;

const boolean FATAL_GPRF = true;
const boolean FATAL_STACK = true;
const boolean FATAL_SREG = true;
const boolean FATAL_SRAM = true;
const boolean FATAL_FLASH = true;
const boolean FATAL_WATCHDOG = false;
const boolean FATAL_ADC = false;
const boolean FATAL_TIMER1 = false;
const boolean FATAL_INTERRUPT = false;

const int ADC_TEST_THRESHOLD = 512;



//---------- G L O B A L S ----------------------------------------------------
boolean _SOS_boot_mode = false;
boolean _watchdog_good = false;
volatile boolean _external_interrupt = false;



//---------- P O S T ----------------------------------------------------------
/*
   Power on self test.  This subroutine calls the tests to verify correct
   operation of the MCU.  Nothing external to the MCU is tested here.

   If everything is working correctly, this function will return true.
   If a fatal failure occurs, the MCU will sleep, thus preventing the rest of
   the MCU's program from running. If a non-fatal failure occurs, the function
   will return false.  Failures will (attempt to) be recorded into EEPROM.

   Note: This POST is not perfect.  There is some redundancy and a few
   assumptions are made, so do not rely solely on this for mission-critical
   applications.

   Adapted from Atmel Application Note AVR998 (c) 2006 Atmel.

   :rtype: boolean
*/
boolean POST()
{
  // Find reason for reset
  byte reason = find_reset_reason();

  // Disable watchdog so it doesn't reset the chip before we're ready
  __asm__ __volatile__ ( "in __tmp_reg__, __SREG__" "\n\t" "cli" "\n\t" "sts %0, %1" "\n\t" "sts %0, __zero_reg__" "\n\t" "out __SREG__,__tmp_reg__" "\n\t" : /* no outputs */ : "M" (((uint16_t) &((*(volatile uint8_t *)(0x60))))), "r" ((uint8_t)((1 << (4)) | (1 << (3)))) : "r0" );

  Serial.begin(57600);

  delay(1000);

  // General Purpose Register File failed?
 if(!gprf_test())
  test_failure(FAIL_GPRF, FATAL_GPRF);

  Serial.println("GPRF");
  delay(5);

 // Stack pointer failed?
 if(!stack_pointer_test())
  test_failure(FAIL_STACK, FATAL_STACK);

  Serial.println("stack");
  delay(5);

 // Status register (SREG) test failed?
 if(!status_register_test())
  test_failure(FAIL_SREG, FATAL_SREG);

  Serial.println("SREG");
  delay(5);

 // SRAM test failed?
 if(!sram_test())
  test_failure(FAIL_SRAM, FATAL_SRAM);

  Serial.println("SRAM");
  delay(5);

 // Flash test failed?
 //if(!flash_test())
  //test_failure(FAIL_FLASH, FATAL_FLASH);

 // Watchdog test failed?
 if(!watchdog_test(reason))
  test_failure(FAIL_WATCHDOG, FATAL_WATCHDOG);
  else
    // Mark watchdog as functional (used to test the timer)
    _watchdog_good = true;

  Serial.println("watchdog");
  delay(5);

  // ADC test failed?
  if(!ADC_test())
    test_failure(FAIL_ADC, FATAL_ADC);

  Serial.println("ADC");
  delay(5);

  // Timer1 test failed?
  if(!timer1_test())
    test_failure(FAIL_TIMER1, FATAL_TIMER1);

  Serial.println("Timer");
  delay(5);

  // Interrupt controller test failed?
  if(!interrupt_test())
    test_failure(FAIL_INTERRUPT, FATAL_INTERRUPT);

  Serial.println("interrupt");
  delay(5);

  // Did anything non-fatal fail?
  if(_SOS_boot_mode)
  {
    Serial.println("SOS");
    delay(10);
    // Exit test with failure
    return false;
  }

  // Exit test with success
  return true;
}



//---------- G P R F _ T E S T ------------------------------------------------
/*
	 Checks the General Purpose Register File (R31 - R0) for stuck bits.
	 Return of TRUE means it passed the test.
	 Return of FALSE means it failed the test.

	 This code is designed to work in the default Arduino environment, so 
	 setting compiler flags is not an option.  The "optimize(0)" attribute is 
	 used to prevent the compiler from optimizing this function.  All of the
   tests in the POST routine disable optimization, to be safe, because much
   of what is happening has no effect outside the function.

	 :rtype: boolean
*/
__attribute__((optimize(0))) boolean gprf_test()
{
 boolean result;

 // This is done in assembly because we're pretty close to metal here.
 // Each register (R31 - R0) has 0x55 and 0xAA written to and read from it, 
 // to verify that there aren't any stuck bits.
 asm volatile(
  // ZH register
  "R31_0x55_TST:                             \n\t"
    "							ldi   R31, 0x55              \n\t"
    "             cpi   R31, 0x55              \n\t"
    "             breq  R31_0xAA_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R31_0xAA_TST:  													 \n\t"
    "							ldi   R31, 0xAA              \n\t"
    "             cpi   R31, 0xAA              \n\t"
    "             breq  R30_0x55_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    // ZL register
    "R30_0x55_TST:                             \n\t"
    "							ldi   R30, 0x55              \n\t"
    "             cpi   R30, 0x55              \n\t"
    "             breq  R30_0xAA_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R30_0xAA_TST:  													 \n\t"
    "							ldi   R30, 0xAA              \n\t"
    "             cpi   R30, 0xAA              \n\t"
    "             breq  R29_0x55_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"

    // YH register
    "R29_0x55_TST:                             \n\t"
    "							mov   R31, R29     ; save R29\n\t"
    "							ldi   R29, 0x55              \n\t"
    "             cpi   R29, 0x55              \n\t"
    "             breq  R29_0xAA_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R29_0xAA_TST:  													 \n\t"
    "							ldi   R29, 0xAA              \n\t"
    "             cpi   R29, 0xAA              \n\t"
    "             breq  R29_END_TST            \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R29_END_TST: 														 \n\t"
    "							mov   R29, R31  ; restore R29\n\t"
    // YL register
    "R28_0x55_TST:                             \n\t"
    "							mov   R31, R28     ; save R28\n\t"
    "							ldi   R28, 0x55              \n\t"
    "             cpi   R28, 0x55              \n\t"
    "             breq  R28_0xAA_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R28_0xAA_TST:  													 \n\t"
    "							ldi   R28, 0xAA              \n\t"
    "             cpi   R28, 0xAA              \n\t"
    "             breq  R28_END_TST            \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R28_END_TST: 														 \n\t"
    "							mov   R28, R31  ; restore R28\n\t"

    // XH register
    "R27_0x55_TST:                             \n\t"
    "							ldi   R27, 0x55              \n\t"
    "             cpi   R27, 0x55              \n\t"
    "             breq  R27_0xAA_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R27_0xAA_TST:  													 \n\t"
    "							ldi   R27, 0xAA              \n\t"
    "             cpi   R27, 0xAA              \n\t"
    "             breq  R26_0x55_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    // XL register
    "R26_0x55_TST:                             \n\t"
    "							ldi   R26, 0x55              \n\t"
    "             cpi   R26, 0x55              \n\t"
    "             breq  R26_0xAA_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R26_0xAA_TST:  													 \n\t"
    "							ldi   R26, 0xAA              \n\t"
    "             cpi   R26, 0xAA              \n\t"
    "             breq  RX_TST                 \n\t"
    "							jmp   Fail_GPRF              \n\t"

    // R25 - R0
    "RX_TST:     															 \n\t"
    "							ldi   R30, 0x00    ; clear ZL\n\t"
    "             ldi   R31, 0x00    ; clear ZH\n\t"
    "RX_0x55_TST:   													 \n\t"
    "							ldi   R25, 0x55              \n\t"
    "             st    Z, R25                 \n\t"
    "             ldi   R25, 0x00              \n\t"
    "             ld    R25, Z                 \n\t"
    "             cpi   R25, 0x55              \n\t"
    "             breq  RX_0xAA_TST            \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "RX_0xAA_TST:   													 \n\t"
    "							ldi   R25, 0xAA              \n\t"
    "             ST    Z, R25                 \n\t"
    "             ldi   R25, 0x00              \n\t"
    "             ld    R25, Z+                \n\t"
    "             cpi   R25, 0xAA              \n\t"
    "             breq  RX_TST_2               \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "RX_TST_2:      													 \n\t"
    "							cpi   r30, 25; test until R25\n\t"
    "             brne  RX_0x55_TST            \n\t"
    "							clr   r1 ; R1 must be cleared\n\t"
    "							jmp   Pass_GPRF 						 \n\t"
  );

 // Test failure
  asm volatile(
    "Fail_GPRF:																 \n\t"
  );
  result = false;

  // Test success
  asm volatile(
    "Pass_GPRF:                                \n\t"
 );
 result = true;

  // Is the result TRUE?
 if(result)
    // Exit test with success
    return true;
  else
    // Exit test with failure
    return false;
}



//---------- S T A C K _ P O I N T E R _ T E S T ------------------------------
/*
	 Checks the stack pointer for stuck bits.
	 Return of TRUE means it passed the test.
	 Return of FALSE means it failed the test.

	 This code is designed to work in the default Arduino environment, so 
   setting compiler flags is not an option.  The "optimize(0)" attribute is 
   used to prevent the compiler from optimizing this function.  All of the
   tests in the POST routine disable optimization, to be safe, because much
   of what is happening has no effect outside the function.

	 :rtype: boolean
*/
__attribute__((optimize(0))) boolean stack_pointer_test()
{
 boolean result;

 // This is done in assembly because we're pretty close to metal here.
 // Each register (SPL & SPH) has 0x55 and 0xAA written to and read from it,
 // to verify that there aren't any stuck bits.
 asm volatile(
  "SP_TST:																	 \n\t"
   // Save stack pointer   
   "						in    R23, 0x3E              \n\t"
      "           in    R22, 0x3D              \n\t"

      // SPL register
      "SPL_0x55_TST:  												 \n\t"
      "						ldi   R24, 0x55              \n\t"
      "           out   0x3D, R24              \n\t"
      "           in    R24, 0x3D              \n\t"
      "           cpi   R24, 0x55              \n\t"
      "           breq  SPL_0xAA_TST           \n\t"
      "           jmp   Fail_SP                \n\t"
      "SPL_0xAA_TST:  												 \n\t"
      "						ldi   R24, 0xAA              \n\t"
      "           out   0x3D, R24              \n\t"
      "           in    R24, 0x3D              \n\t"
      "           cpi   R24, 0xAA              \n\t"
      "           breq  SPH_0x55_TST           \n\t"
      "           jmp   Fail_SP                \n\t"
      // SPH register
      "SPH_0x55_TST:  												 \n\t"
      "						ldi   R25, 0x07			         \n\t"
      "           andi  R25, 0x55              \n\t"
      "           out   0x3E, R25              \n\t"
      "           in    R24, 0x3E              \n\t"
      "           cp    R24, R25               \n\t"
      "           breq  SPH_0xAA_TST           \n\t"
      "           jmp   Fail_SP                \n\t"
      "SPH_0xAA_TST:  												 \n\t"
      "						ldi   R25, 0x07              \n\t"
      "           andi  R25, 0xAA              \n\t"
      "           out   0x3E, R25              \n\t"
      "           in    R24, 0x3E              \n\t"
      "           cp    R24, R25               \n\t"
      "           breq  RESTORE_SP             \n\t"
      "           jmp   Fail_SP                \n\t"

      // Restore stack pointer
      "RESTORE_SP:    												 \n\t"
      "						out   0x3E, R23              \n\t"
      "           out   0x3D, R22              \n\t"
      "           jmp   Pass_SP                \n\t"
  );

 // Test failure
  asm volatile(
    "Fail_SP:																   \n\t"
  );
  result = false;

  // Test success
  asm volatile(
    "Pass_SP:																   \n\t"
 );
 result = true;

 // Is the result TRUE?
  if(result)
    // Exit test with success
    return true;
  else
    // Exit test with failure
    return false;
}



//---------- S T A T U S _ R E G I S T E R _ T E S T --------------------------
/*
   Checks the status register (SREG) for stuck bits.
   Return of TRUE means it passed the test.
	 Return of FALSE means it failed the test.

	 This code is designed to work in the default Arduino environment, so 
   setting compiler flags is not an option.  The "optimize(0)" attribute is 
   used to prevent the compiler from optimizing this function.  All of the
   tests in the POST routine disable optimization, to be safe, because much
   of what is happening has no effect outside the function.

   :rtype: boolean
*/
__attribute__((optimize(0))) boolean status_register_test()
{
 byte read_sreg, save_sreg;

 // Save current state of SREG
 save_sreg = (*(volatile uint8_t *)((0x3F) + 0x20));

 // Write value to SREG
 (*(volatile uint8_t *)((0x3F) + 0x20)) = 0x55;

 // Read value in SREG
 read_sreg = (*(volatile uint8_t *)((0x3F) + 0x20));

 // Restore original state of SREG
 (*(volatile uint8_t *)((0x3F) + 0x20)) = save_sreg;

 // Is the value read from SREG not the expected value?
 if(read_sreg != 0x55)
  // Exit test with failure
  return false;
 else
 {
  // Save current state of SREG
  save_sreg = (*(volatile uint8_t *)((0x3F) + 0x20));

  // Write value to SREG
  (*(volatile uint8_t *)((0x3F) + 0x20)) = 0xAA;

  // Read value in SREG
  read_sreg = (*(volatile uint8_t *)((0x3F) + 0x20));

  // Restore original state of SREG
  (*(volatile uint8_t *)((0x3F) + 0x20)) = save_sreg;

  // Is the value read from SREG the expected value?
  if(read_sreg == 0xAA)
   // Exit test with success
   return true;
  else
   // Exit test with failure
   return false;
 }
}



//---------- S R A M _ T E S T ------------------------------------------------
/*
   Checks the SRAM for stuck bits.
   Return of TRUE means it passed the test.
	 Return of FALSE means it failed the test.

	 This code is designed to work in the default Arduino environment, so 
   setting compiler flags is not an option.  The "optimize(0)" attribute is 
   used to prevent the compiler from optimizing this function.  All of the
   tests in the POST routine disable optimization, to be safe, because much
   of what is happening has no effect outside the function.

   :rtype: boolean
*/
__attribute__((optimize(0))) boolean sram_test()
{
  boolean result;

  // This is done in assembly because we're pretty close to metal here.
  // Each RAM address (0x0100 - 0x0AFF) has 0x55 and 0xAA written to and read from it, 
  // to verify that there aren't any stuck bits.
  asm volatile(
    "LD_INITS:                                 \n\t"
    "             ldi   R31, 0x01              \n\t"
    "             ldi   R30, 0x00              \n\t"
    "             ldi   R28, 0x55              \n\t"
    "             ldi   R29, 0xAA              \n\t"
    "CHECK_DONE:                               \n\t"
                  // Compare ZH to 0x0A
    "             cpi   R31, 0x0A              \n\t"
    "             brne  LOOP                   \n\t"
                  // Compare ZL to 0xFF
    "             cpi   R30, 0xFF              \n\t"
                  // If both match, test complete
    "             breq  Pass_RAM               \n\t"
    "LOOP:                                     \n\t"
                  // Temp store contents in R26
    "             ld    R26, Z                 \n\t"
                  // Store 0x55 at RAM location
    "             st    Z, R28                 \n\t"
                  // Read to confirm 0x55
    "             ld    R27, Z                 \n\t"
    "             cpi   R27, 0x55              \n\t"
                  // If equal, continue to 0xAA Test
    "             brne  Fail_RAM               \n\t"
                  // Store 0xAA at RAM location
    "             st    Z, R29                 \n\t"
                  // Read to confirm 0xAA
    "             ld    R27, Z                 \n\t"
                  // Place old contents back in, increment addr
    "             st    Z+, R26                \n\t"
    "             cpi   R27, 0xAA              \n\t"
    "             brne  Fail_RAM               \n\t"
                  // If equal, continue to next iteration
    "             jmp   CHECK_DONE             \n\t"
  );

  // Test failure
  asm volatile(
    "Fail_RAM:                                 \n\t"
  );
  result = false;

  // Test success
  asm volatile(
    "Pass_RAM:                                 \n\t"
  );
  result = true;

  // Is the result TRUE?
  if(result)
    // Exit test with success
    return true;
  else
    // Exit test with failure
    return false;
}



//---------- W A T C H D O G _ T E S T ----------------------------------------
/*
	 Checks the reason for reset.  If it was a watchdog reset, we move on.
	 If it wasn't, enable the watchdog and wait.
	 Return of TRUE means it passed the test.
	 Return of FALSE means it failed the test.

	 This code is designed to work in the default Arduino environment, so 
   setting compiler flags is not an option.  The "optimize(0)" attribute is 
   used to prevent the compiler from optimizing this function.  All of the
   tests in the POST routine disable optimization, to be safe, because much
   of what is happening has no effect outside the function.

   :rtype: boolean
*/
__attribute__((optimize(0))) boolean watchdog_test(byte reason)
{
  Serial.println(reason);
  delay(100);

  // Was reset not due to watchdog?
  //if((reason & RESET_WATCHDOG) != RESET_WATCHDOG)
  if(reason != RESET_WATCHDOG)
  {
    Serial.println("not watchdog reset");
    __asm__ __volatile__ ( "in __tmp_reg__,__SREG__" "\n\t" "cli" "\n\t" "wdr" "\n\t" "sts %0,%1" "\n\t" "out __SREG__,__tmp_reg__" "\n\t" "sts %0,%2" "\n\t" : /* no outputs */ : "M" (((uint16_t) &((*(volatile uint8_t *)(0x60))))), "r" ((1 << (4)) | (1 << (3))), "r" ((uint8_t) ((9 & 0x08 ? (1 << (5)) : 0x00) | (1 << (3)) | (9 & 0x07)) ) : "r0" );
    Serial.println("enabled");
    delay(9000);
    Serial.println("watchdog did not reset");
    return false;
  }

  //if((reason & RESET_WATCHDOG) == RESET_WATCHDOG)
  if(reason == RESET_WATCHDOG)
  {
    pinMode(4, 0x1);
    digitalWrite(4, 0x1);
  }
  return true;
}



//---------- A D C _ T E S T --------------------------------------------------
/*
   Checks that the ADC is functioning correctly.
   Return of TRUE means it passed the test.
   Return of FALSE means it failed the test.

   This code is designed to work in the default Arduino environment, so 
   setting compiler flags is not an option.  The "optimize(0)" attribute is 
   used to prevent the compiler from optimizing this function.  All of the
   tests in the POST routine disable optimization, to be safe, because much
   of what is happening has no effect outside the function.

   :rtype: boolean
*/
__attribute__((optimize(0))) boolean ADC_test()
{
  // Set AREF to the ATmega's internal reference
  analogReference(3);

  // Wait, then read ADC a few times to let things settle down.
  // ATmega32U4 datasheet recommends this.
  delay(50);
  analogRead(3);
  analogRead(3);
  analogRead(3);

  // Read ADC with INTERNAL as input
  int value = analogRead(3);

  // Is the reported ADC value close enough?
  // Theoretically, the value should be 1023 (10-bit conversion)
  if(value > ADC_TEST_THRESHOLD)
    // Exit test with success
    return true;
  else
    // Exit test with failure
    return false;
}



//---------- T I M E R 1 _ T E S T --------------------------------------------
/*
   Checks all registers for stuck bits and lets the timer overflow, which
   tests the timer and the interrupt (thus, the interrupt controller, too).
   Return of TRUE means it passed the test.
   Return of FALSE means it failed the test.

   This code is designed to work in the default Arduino environment, so 
   setting compiler flags is not an option.  The "optimize(0)" attribute is 
   used to prevent the compiler from optimizing this function.  All of the
   tests in the POST routine disable optimization, to be safe, because much
   of what is happening has no effect outside the function.

   :rtype: boolean
*/
__attribute__((optimize(0))) boolean timer1_test()
{
  // Disable interrupts (since we're fiddling with interrupt controls)
  __asm__ __volatile__ ("cli" ::: "memory");

  /* These comments apply to all register tests in this function */
  // Load first test value
  (*(volatile uint8_t *)(0x80)) = 0x55;
  // Is the register not storing the test value?
  // See datasheet for unused bits
  if(((*(volatile uint8_t *)(0x80)) & 0x55) != 0x55)
    // Exit test with failure
    return false;
  // Load second test value
  (*(volatile uint8_t *)(0x80)) = 0xAA;
  // Is the register not storing the test value?
  // See datasheet for unused bits
  if(((*(volatile uint8_t *)(0x80)) & 0xAA) != 0xAA)
    // Exit test with failure
    return false;
  // Reset the register
  (*(volatile uint8_t *)(0x80)) = 0;

  (*(volatile uint8_t *)(0x81)) = 0x55;
  if(((*(volatile uint8_t *)(0x81)) & 0x55) != 0x55)
    return false;
  (*(volatile uint8_t *)(0x81)) = 0xAA;
  if(((*(volatile uint8_t *)(0x81)) & 0xAA) != 0x8A)
    return false;
  (*(volatile uint8_t *)(0x81)) = 0;

  (*(volatile uint16_t *)(0x84)) = 0x5555;
  if(((*(volatile uint16_t *)(0x84)) & 0x5555) != 0x5555)
    return false;
  (*(volatile uint16_t *)(0x84)) = 0xAAAA;
  if(((*(volatile uint16_t *)(0x84)) & 0xAAAA) != 0xAAAA)
    return false;
  (*(volatile uint16_t *)(0x84)) = 0;

  (*(volatile uint16_t *)(0x88)) = 0x5555;
  if(((*(volatile uint16_t *)(0x88)) & 0x5555) != 0x5555)
    return false;
  (*(volatile uint16_t *)(0x88)) = 0xAAAA;
  if(((*(volatile uint16_t *)(0x88)) & 0xAAAA) != 0xAAAA)
    return false;
  (*(volatile uint16_t *)(0x88)) = 0;

  (*(volatile uint8_t *)(0x6F)) = 0x55;
  if(((*(volatile uint8_t *)(0x6F)) & 0x55) != 0x05)
    return false;
  (*(volatile uint8_t *)(0x6F)) = 0xAA;
  if(((*(volatile uint8_t *)(0x6F)) & 0xAA) != 0x2A)
    return false;
  (*(volatile uint8_t *)(0x6F)) = 0;

  // Enable interrupts
  __asm__ __volatile__ ("sei" ::: "memory");

  // Did we arrive here after a watchdog reset due to a bad timer?
  if(__eerd_byte_m32u4(&E_TIMER_TEST_INCOMPLETE))
    // Exit test with failure
    return false;

  // Did watchdog pass its test?
  // If it did not, we have no reliable way to test the timer without failure
  // resulting in an infinite loop.  An infinite loop prevents us from
  // getting to the partial boot sequence, so if the watchdog is bad, we'll
  // have to trust that the timer works, without this explicit test.
  if(_watchdog_good)
  {
    // Mark timer test as incomplete
    __eeupd_byte_m32u4(&E_TIMER_TEST_INCOMPLETE, 1);

    // Enable watchdog
    __asm__ __volatile__ ( "in __tmp_reg__,__SREG__" "\n\t" "cli" "\n\t" "wdr" "\n\t" "sts %0,%1" "\n\t" "out __SREG__,__tmp_reg__" "\n\t" "sts %0,%2" "\n\t" : /* no outputs */ : "M" (((uint16_t) &((*(volatile uint8_t *)(0x60))))), "r" ((1 << (4)) | (1 << (3))), "r" ((uint8_t) ((2 & 0x08 ? (1 << (5)) : 0x00) | (1 << (3)) | (2 & 0x07)) ) : "r0" );

    // Start timer (with prescaler of clk/8)
    (*(volatile uint8_t *)(0x81)) = (1 << 1);

    // Wait for counter to overflow
    while(! ((*(volatile uint8_t *)((0x16) + 0x20)) & (1 << (0))));

    // Disable watchdog
    __asm__ __volatile__ ( "in __tmp_reg__, __SREG__" "\n\t" "cli" "\n\t" "sts %0, %1" "\n\t" "sts %0, __zero_reg__" "\n\t" "out __SREG__,__tmp_reg__" "\n\t" : /* no outputs */ : "M" (((uint16_t) &((*(volatile uint8_t *)(0x60))))), "r" ((uint8_t)((1 << (4)) | (1 << (3)))) : "r0" );

    // Clear the clock prescaling (this turns off the timer)
    (*(volatile uint8_t *)(0x81)) = 0;
    // Clear the timer's counter
    (*(volatile uint16_t *)(0x84)) = 0;
    // Clear the overflow flag
    (*(volatile uint8_t *)((0x16) + 0x20)) = (1 << (0));

    // Mark timer test as complete
    __eeupd_byte_m32u4(&E_TIMER_TEST_INCOMPLETE, 0);
  }

  // Exit test with success
  return true;
}



//---------- I N T E R R U P T _ T E S T --------------------------------------
/*
   Checks that the interrupt controller executes interrupt service routines.
   Return of TRUE means it passed the test.
   Return of FALSE means it failed the test.

   This code is designed to work in the default Arduino environment, so 
   setting compiler flags is not an option.  The "optimize(0)" attribute is 
   used to prevent the compiler from optimizing this function.  All of the
   tests in the POST routine disable optimization, to be safe, because much
   of what is happening has no effect outside the function.

   :rtype: boolean
*/
__attribute__((optimize(0))) boolean interrupt_test()
{
  // Set pin INT0 to output (to enable software control of interrupt)
  pinMode(0, 0x1);

  // Enable INT0 interrupt.  Without setting any bits in EICRA, the default
  // is for an interrupt to trigger when the pin is low.
  (*(volatile uint8_t *)((0x1D) + 0x20)) |= (1 << (0));

  // Trigger the interrupt
  digitalWrite(0, 0x0);

  // Give the pin time to change state (if necessary)
  delay(1);

  // Did the interrupt fire?
  if(_external_interrupt)
    // Exit with success
    return true;
  else
    // Exit with failure
    return false;
}



//---------- E X T E R N A L _ I N T 0 _ I N T E R R U P T --------------------
/*
   Interrupt for external interrupt INT0.

   :rtype: none
*/
extern "C" void __vector_1 /* External Interrupt Request 0 */ (void) __attribute__ ((signal,used, externally_visible)) ; void __vector_1 /* External Interrupt Request 0 */ (void)
{
  // Disable INT0 interrupt
  (*(volatile uint8_t *)((0x1D) + 0x20)) = 0;

  // Set flag to indicate that the ISR executed
  _external_interrupt = true;
}



//---------- F I N D _ R E S E T _ R E A S O N --------------------------------
/*
   Reads the MCU status register (MCUSR) for the reset flag.

   :rtype: byte
*/
byte find_reset_reason()
{
 byte i;
 byte mask = 0x01;

 // Check bits 0-5 in MCUSR
 for(i = 0; i < 6; i++)
 {
    // Is the current bit set?
  if((*(volatile uint8_t *)((0x34) + 0x20)) & mask)
   // Found the reset flag, so exit the loop
   break;

  // Shift the mask left by 1
  mask <<= 1;
 }

  // Clear MCUSR
  (*(volatile uint8_t *)((0x34) + 0x20)) = 0;

 // Return the reset reason
 return i;
}



//---------- T E S T _ F A I L U R E ------------------------------------------
/*
	 Saves the reason for POST failure into EEPROM and aborts/modifies boot-up.

	 :param byte reason: reason for POST failure
	 :param boolean fatal: POST failure is/not fatal
*/
void test_failure(byte reason, boolean fatal)
{
 // Save POST failure to EEPROM
 __eeupd_byte_m32u4(&E_POST_RESULT, reason);

 // Allow time for EEPROM to finish writing
 delay(5);

 // Is POST failure fatal?
 if(fatal)
  // Go to sleep
  sleep();
 else
  // Set flag for SOS boot mode
    _SOS_boot_mode = true;
}



//---------- S L E E P --------------------------------------------------------
/*
	 Puts Atmel chip to sleep (power-down mode).
*/
void sleep()
{
 // Disable interrupts so nothing weird happens
 __asm__ __volatile__ ("cli" ::: "memory");

 // Set power-down mode to draw the least amount of power possible
 do { (*(volatile uint8_t *)((0x33) + 0x20)) = (((*(volatile uint8_t *)((0x33) + 0x20)) & ~((1 << (1)) | (1 << (2)) | (1 << (3)))) | ((1 << (2)))); } while(0);

 // Enable sleep
 do { (*(volatile uint8_t *)((0x33) + 0x20)) |= (uint8_t)(1 << (0)); } while(0);

 // Go to sleep
 do { do { (*(volatile uint8_t *)((0x33) + 0x20)) |= (uint8_t)(1 << (0)); } while(0); do { __asm__ __volatile__ ( "sleep" "\n\t" :: ); } while(0); do { (*(volatile uint8_t *)((0x33) + 0x20)) &= (uint8_t)(~(1 << (0))); } while(0); } while (0);

 // Chew on this until the chip falls asleep
 while(1);
}
# 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/boot_SOS.ino"
//---------- C O N S T A N T S ------------------------------------------------
const byte NO_WATCHDOG = 1;
const byte NO_TIMER = 2;
const byte NO_ADC = 3;
const byte NO_INTERRUPT = 4;



//---------- G L O B A L S ----------------------------------------------------
byte SOS_mode;



//---------- B O O T _ S O S --------------------------------------------------
/*
   If a non-critical internal component failed the POST, this subroutine 
   attempts to boot enough to let the node controller inform the cloud there
   is a problem.

   :rtype: none
*/
void boot_SOS()
{
 // // Initialize/start internal components
 // init_SOS();

 // // Check that SysMon is drawing an expected amount of power
 // check_power_self();

 // // Check that the SysMon's environment is suitable.
 // // If the check fails, it could be the environment or the I2C
 // check_environ_self();

 // // Get datum about number of times SOS boot mode has been tried
 // byte num_tries = eeprom_read_byte(&E_NUM_SOS_BOOT_ATTEMPTS);

 // // Has SOS boot been tried too many times?
 // if(num_tries >= eeprom_read_byte(&E_MAX_NUM_SOS_BOOT_ATTEMPTS))
 // 	// Something isn't working, so go to sleep
 // 	sleep();

 // // Record that SOS boot mode was attempted
 // eeprom_update_byte(&E_NUM_SOS_BOOT_ATTEMPTS, ++num_tries);

 // // ADC ok?
 // if(SOS_mode != NO_ADC)
 // 	// Check that the node controller's environment is suitable
 // 	check_environ_nc();
 // // ADC not ok?
 // else if(SOS_mode == NO_ADC)
 // 	// This is here as notice that proceeding without ADC introduces some
 // 	// risk to the node controller, since its environ. can't be measured.
 // 	asm("nop");

 // // Is the node controller not enabled?
 // if(!eeprom_read_byte(&E_NC_ENABLED))
 // 	// Nothing for us to do, so go to sleep
 // 	sleep();

 // // Enable power to node controller

 // // Check that the node controller is drawing an expected amount of power
 // check_power_nc();

 // // Check that the node controller is alive (sending a "heartbeat")
 // check_heartbeat_nc();

 // // Report the POST failure to the node controller
 // report_failure_POST();
}



//---------- I N I T _ S O S --------------------------------------------------
/*
   Initializes/starts all necessary ports, peripherals, interrupts, etc.

   :rtype: none
*/
void init_SOS()
{
 //  // What is the cause of the POST failure?
 // switch (eeprom_read_byte(&E_POST_RESULT)) {
 //     case FAIL_WATCHDOG:
 //       SOS_mode = NO_WATCHDOG;
 //       break;
 //     case FAIL_TIMER1:
 //       SOS_mode = NO_TIMER;
 //       break;
 //     case FAIL_ADC:
 //     	SOS_mode = NO_ADC;
 //     	break;
 //     case FAIL_INTERRUPT:
 //     	SOS_mode = NO_INTERRUPT;
 //     	break;
 //     // This shouldn't happen, but just in case...
 //     default:
 //       sleep();
 // }

 // // Watchdog, timer, and interrupts ok?
 // if((SOS_mode != NO_WATCHDOG) && (SOS_mode != NO_TIMER) && 
 // 	(SOS_mode != NO_INTERRUPT))
 // 	// Enable watchdog with 2 second timeout
 // 	wdt_enable(WDTO_2S);
 // // Watchdog, timer, or interrupts not ok?
 // else
 // 	// This is here as notice that proceeding without the watchdog introduces
 // 	// the risk of SysMon hanging forever.
 // 	asm("nop");

 // // Timer ok?
 // if(SOS_mode != NO_TIMER)
 // {
 // 	// Interrupts ok?
 // 	if(SOS_mode != NO_INTERRUPT)
 // 		// Enable Timer1 overflow interrupt
 // 		TIMSK1 |= _BV(TOIE1);

 // 	// Start Timer1 with prescaler of clk/256 (timeout of approx. 1 second)
 // 	TCCR1B |= _BV(CS12);
 // }

 // // Join I2C bus as master.
 // // We're hoping I2C works, because we don't currently have a way to test it
 // Wire.begin();

 // // Enable serial comms.
 // // We're hoping UART works, because we don't currently have a way to test it
 //  Serial.begin(eeprom_read_dword(&E_USART_BAUD));
}



//---------- R E P O R T _ F A I L U R E _ P O S T ----------------------------
/*
   Sends info about the POST failure to the node controller, waits for
   the node controller to send failure info to the cloud (or until timeout),
   then goes to sleep

   :rtype: none
*/
void report_failure_POST()
{

}
# 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/boot_gn.ino"
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
      pin_relay = 8;
      pin_heartbeat = 9;
      problem_temp = "GN1,t";
      problem_power = "GN1,p";
      problem_heartbeat = "GN1,h";
      enabled = &E_GN1_ENABLED;
      present = &E_PRESENT_GN1;
      boot_time = &E_BOOT_TIME_GN1;

      break;
    case 2:
      // Mark guest node as not operational
      _GN2_running = false;

      // Assign variables for this guest node
      pin_relay = 10;
      pin_heartbeat = 11;
      problem_temp = "GN2,t";
      problem_power = "GN2,p";
      problem_heartbeat = "GN2,h";
      enabled = &E_GN2_ENABLED;
      present = &E_PRESENT_GN2;
      boot_time = &E_BOOT_TIME_GN2;

      break;
    case 3:
      // Mark guest node as not operational
      _GN3_running = false;

      // Assign variables for this guest node
      pin_relay = 12;
      pin_heartbeat = 13;
      problem_temp = "GN3,t";
      problem_power = "GN3,p";
      problem_heartbeat = "GN3,h";
      enabled = &E_GN3_ENABLED;
      present = &E_PRESENT_GN3;
      boot_time = &E_BOOT_TIME_GN3;

      break;
    // Invalid guest node
    default:
      return;
  }

  // Make sure the device is off
  digitalWrite(pin_relay, 0x0);

  // Give the device time to rest
  delay(2000);

  // Is guest node enabled and expected to be present?
  if(__eerd_byte_m32u4(enabled) && __eerd_byte_m32u4(present))
  {
    // Is the guest node's temperature outside of safe parameters?
    if(!check_temp_GN(gn))
    {
      // Giving the guest node one more chance...

      // Wait for things to settle down, perhaps
      delay((long)5 * 1000L);

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
    digitalWrite(pin_relay, 0x1);

    // Give the guest node time to boot
    delay((long)__eerd_word_m32u4(boot_time) * 1000L);

    // Is the guest node not drawing an expected amount of power?
    if(!check_power_GN(gn))
    {
      // Giving the guest node one more chance...

      // Power cycle the guest node
      power_cycle(pin_relay);

      // Give the guest node time to boot
      delay((long)__eerd_word_m32u4(boot_time) * 1000L);

      // Is the guest node not drawing an expected amount of power?
      if(!check_power_GN(gn))
      {
        // Turn off the guest node
        digitalWrite(pin_relay, 0x0);

        // Inform node controller of failure
        send_problem(problem_power);

        // Mark GN as dead
        __eeupd_byte_m32u4(enabled, 0);

        // Exit with failure
        return;
      }
    }

    // Is the guest node alive (sending a heartbeat)?
    if(!check_heartbeat_odroid(pin_heartbeat))
    {
      // Start at 1 boot attempt, since we had to boot to get here
      byte boot_attempts = 1;
      boolean _heartbeat_detected = false;

      // Try to get a heartbeat from the GN as many times as allowed
      while (boot_attempts < __eerd_byte_m32u4(&E_MAX_NUM_SUBSYSTEM_BOOT_ATTEMPTS))
      {
        // Is heartbeat not detected?
        if(!check_heartbeat_odroid(pin_heartbeat))
        {
          // Power cycle the guest node
          power_cycle(pin_relay);

          // Give the guest node time to boot
          delay((long)__eerd_word_m32u4(boot_time) * 1000L);
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
        digitalWrite(pin_relay, 0x0);

        // Inform node controller of failure
        send_problem(problem_heartbeat);

        // Exit with failure
        return;
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
}
# 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/boot_primary.ino"
//---------- B O O T _ P R I M A R Y ------------------------------------------
/*
 *  Starts/initializes/boots self, node controller, and ethernet switch.
 *  Conditions for and operation of the node controller and ethernet switch are
 *  verified before completing boot sequence.
 *
 *  Return TRUE: boot procedure executed successfully.
 *  Return FALSE: boot procedure failed.
 *
 *  :rtype: boolean
 */
boolean boot_primary()
{
    // Initialize/start internal components

    Serial.println("BP0");


    init_primary();


    Serial.println("BP1");


    // Is this the first ever boot?
    if(__eerd_byte_m32u4(&E_FIRST_BOOT) != 0)
        // Assign default parameters
        set_default_eeprom();


    Serial.println("BP2");


    // Booted SysMon successfully?
    if(!boot_SysMon())
        // Skip the rest of the boot sequence

        return false;


    Serial.println("BP3");


    // Booted node controller successfully?
    if(!boot_NC())
        // Skip the rest of the boot sequence
        return false;



    Serial.println("BP4");


    // Give node controller the chance to acquire the time from the internet
    delay(20000);


    Serial.println("BP5");


    // Request time from node controller
    get_time_NC();

    // Request operating parameters from node controller
    get_params_core();

    // Request guest node parameters from node controller
    get_params_GNs();

    // Boot ethernet switch
    boot_switch();

    // Everything is good, so exit sequence with success
    return true;
}



//---------- B O O T _ N C ----------------------------------------------------
/*
 *   Boots the node controller.  Checks environment, power draw, and heartbeat.
 *
 *   This function is overloaded, with the default type being POWER_ON_BOOT.
 *
 *   Return TRUE: everything is good, boot successful.
 *   Return FALSE: something went wrong, boot unsuccessful.
 *
 *   :rtype: boolean
 */

boolean boot_NC(void)
{

    Serial.println("BNC0");

    return boot_NC(0x00);
}


boolean boot_NC(boolean which_type)
{

    if (which_type == 0x01)
    {

        Serial.println("BNC1");

    // Tell NC that it is about to be shut down, in case this is a reboot
    Serial.println('?');
    // Give it time to shut down properly
    delay((long)5000);

    // Turn NC off (disable the relay)
    digitalWrite(4, 0x0);

    // Give the device time to rest
    delay(2000);

    // Mark NC as not operational
    _NC_running = false;

    }


    Serial.println("BNC2");


    // Is the node controller not enabled?
    if(!__eerd_byte_m32u4(&E_NC_ENABLED))
        // Exit with failure
        return false;


    Serial.println("BNC3");


    // Is the node controller's environment not suitable?
    if(!check_environ_NC())
    {
        // Giving the node controller one more chance...

        // Wait for things to settle down, perhaps
        delay((long)5 * 1000L);

        // Is the node controller's environment not suitable?
        if(!check_environ_NC())
            // Exit with failure
            return false;
    }


    Serial.println("BNC4");


    // Is the node controller's processor temperature not suitable?
    if(!check_temp_NC())
    {
        // Giving the node controller one more chance...

        Serial.println("BNC4.1");

        // Wait for things to settle down, perhaps
        delay((long)5 * 1000L);

        // Is the node controller's environment not suitable?
        if(!check_temp_NC())

            Serial.println("BNC4.2");

            // Exit with failure
            return false;
    }



    Serial.println("BNC5");


    // Enable power to node controller
    digitalWrite(4, 0x1);

    // Give NC time to be configured, in case this is a new NC...

    // Set serial receive timeout to time specified by parameter
//     Serial.setTimeout((long)eeprom_read_word(&E_CONFIG_TIME_NC) * 1000L);
    // Wait for notification from NC that it is configured for WagMan
    String config_WagMan = Serial.readStringUntil('!');
    // Return serial receive timeout to default (1000 ms)
    Serial.setTimeout(1000L);
    // Did NC fail to notify us that it is configured?


    Serial.println("BNC6");


    if(config_WagMan != "=")
        // Exit with failure
        return false;


    Serial.println("BNC7");


    // Is the node controller not drawing an expected amount of power?
    if(!check_power_NC())
    {
        // Giving the node controller one more chance...

        // Power cycle the node controller
        power_cycle(4);

        // Give the node controller time to boot
        delay((long)__eerd_word_m32u4(&E_BOOT_TIME_NC) * 1000L);

        // Is the node controller not drawing an expected amount of power?
        if(!check_power_NC())
        {
            // Turn off the node controller
            digitalWrite(4, 0x0);

            // Mark NC as dead
            __eeupd_byte_m32u4(&E_NC_ENABLED, 0);

            // Exit with failure
            return false;
        }
    }


    Serial.println("BNC8");


    // Is the node controller alive (sending a heartbeat)?
    if(!check_heartbeat_odroid(5))
    {
        // Start at 1 boot attempt, since we had to boot to get here
        byte boot_attempts = 1;
        boolean _heartbeat_detected = false;

        // Try to get a heartbeat from the NC as many times as allowed
        while(boot_attempts < __eerd_byte_m32u4(&E_MAX_NUM_SUBSYSTEM_BOOT_ATTEMPTS))
        {
            // Is heartbeat not detected?
            if(!check_heartbeat_odroid(5))
            {
                // Power cycle the node controller
                power_cycle(4);

                // Give the node controller time to boot
                delay((long)__eerd_word_m32u4(&E_BOOT_TIME_NC) * 1000L);
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
            // Turn off the node controller
            digitalWrite(4, 0x0);

            // Exit with failure
            return false;
        }
    }


    Serial.println("BNC9");


    // Mark NC as operational
    _NC_running = true;

    // Exit with success
    return true;
}



//---------- B O O T _ S W I T C H --------------------------------------------
/*
 *   Boots the ethernet switch.  Checks environment and power draw.
 *   If something goes wrong, the node controller is notified.
 *
 *   :rtype: none
 */
void boot_switch()
{
    // Mark switch as not operational
    _switch_running = false;

    // Make sure the device is off
    digitalWrite(6, 0x0);

    // Give the device time to rest
    delay(2000);

    // Is the ethernet switch disabled or not present?
    if(!(__eerd_byte_m32u4(&E_SWITCH_ENABLED)
        && __eerd_byte_m32u4(&E_PRESENT_SWITCH)))
    {
        // Exit with failure
        return;
    }

    // Is the ethernet switch's temperature outside of safe parameters?
    if(!check_temp_switch())
    {
        // Giving the switch one more chance...

        // Wait for things to settle down, perhaps
        delay((long)5 * 1000L);

        // Is the ethernet switch's temperature outside of safe parameters?
        if(!check_temp_switch())
        {
            // Inform node controller of failure
            send_problem("SW,t");

            // Exit with failure
            return;
        }
    }

    // Enable power to ethernet switch
    digitalWrite(6, 0x1);

    // Give the ethernet switch time to boot
    delay((long)__eerd_byte_m32u4(&E_BOOT_TIME_SWITCH) * 1000L);

    // Is the ethernet switch not drawing an expected amount of power?
    if(!check_power_switch())
    {
        // Giving the ethernet switch one more chance...

        // Power cycle the switch
        power_cycle(6);

        // Give the switch time to boot
        delay((long)__eerd_byte_m32u4(&E_BOOT_TIME_SWITCH) * 1000L);

        // Is the ethernet switch not drawing an expected amount of power?
        if(!check_power_switch())
        {
            // Turn off the switch
            digitalWrite(6, 0x0);

            // Inform node controller of failure
            send_problem("SW,p");

            // Mark switch as dead
            __eeupd_byte_m32u4(&E_SWITCH_ENABLED, 0);

            // Exit with failure
            return;
        }
    }

    // Mark switch as operational
    _switch_running = true;
}



//---------- B O O T _ S Y S M O N --------------------------------------------
/*
 *   Checks environment and power draw for SysMon.
 *
 *   Return TRUE: everything is good.
 *   Return FALSE: environment/power draw is unacceptable.
 *
 *   :rtype: boolean
 */
boolean boot_SysMon()
{
    // Is SysMon drawing too much power?
    if(!check_power_SysMon())
    {
        // Giving SysMon one more chance...

        // Wait for things to settle down, perhaps
        delay((long)1 * 1000L);

        // Is SysMon drawing too much power?
        if(!check_power_SysMon())
            // Exit with failure
            return false;
    }

    // Is SysMon's environment outside of safe bounds?
    if(!check_environ_SysMon())
    {
        // Giving SysMon one more chance...

        // Wait for things to settle down, perhaps
        delay((long)5 * 1000L);

        // Is SysMon's environment outside of safe bounds?
        if(!check_environ_SysMon())
            // Exit with failure
            return false;
    }

    // Exit with success
    return true;
}



//---------- G E T _ P A R A M S _ C O R E ------------------------------------
/*
 *  Request operating parameters from the node controller.  If parameters are
 *  different than what is already stored, the parameter is updated.  If the
 *  parameters are the same or not received, the previously stored values will
 *  be used.
 *
 *  :rtype: none
 */
void get_params_core()
{
    // Send request
    Serial.println('$');

    // Save the node controller's response into a string.
    // Default timeout value is 1 second
    String received_params = "";
    received_params = Serial.readStringUntil('!');

    // Were parameters received?
    if(received_params.length() > 0)
    {
        /* Order of parameters (coming from node controller):
         *
         *        USART baud rate
         *        USART RX buffer size
         *        Period at which status reports are sent to node controller
         *        Max number of SOS boot attempts
         *        Max number of subsystem boot attempts
         *        Max number of primary boot attempts
         *        Time to wait before trying to reboot non-running devices
         *        Present/not present (switch)
         *        Node controller boot time
         *        Node controller first-time configuration time
         *        Ethernet switch boot time
         *        Heartbeat timeout (node controller)
         *        Heartbeat timeout (switch)
         *        Environment timeout (system monitor)
         *        Environment timeout (node controller)
         *        Processor temperature timeout (node controller)
         *        Temperature timeout (switch)
         *        Power timeout (system monitor)
         *        Power timeout (node controller)
         *        Power timeout (switch)
         *        Minimum temperature of environment (Celsius) (system monitor)
         *        Maximum temperature of environment (Celsius) (system monitor)
         *        Minimum temperature of environment (Celsius) (node controller)
         *        Maximum temperature of environment (Celsius) (node controller)
         *        Minimum temperature of processor (Celsius) (node controller)
         *        Maximum temperature of processor (Celsius) (node controller)
         *        Minimum temperature (Celsius) (switch)
         *        Maximum temperature (Celsius) (switch)
         *        Minimum relative humidity (%) (system monitor)
         *        Maximum relative humidity (%) (system monitor)
         *        Minimum relative humidity (%) (NC)
         *        Maximum relative humidity (%) (NC)
         *        Maximum amp draw (mA) (system monitor)
         *        Maximum amp draw (mA) (node controller)
         *        Maximum amp draw (mA) (switch)
         */

        // Temporary strings for holding each parameter
        String USART_baud = "";
        String USART_RX_buffer_size = "";
        String status_report_period = "";
        String max_num_SOS_boot_attempts = "";
        String max_num_subsystem_boot_attempts = "";
        String max_num_primary_boot_attempts = "";
        String device_reboot_period = "";
        String present_switch = "";
        String NC_boot_time = "";
        String NC_config_time = "";
        String switch_boot_time = "";
        String heartbeat_timeout_NC = "";
        String heartbeat_timeout_switch = "";
        String environ_timeout_SysMon = "";
        String environ_timeout_NC = "";
        String temp_processor_timeout_NC = "";
        String temp_timeout_switch = "";
        String power_timeout_SysMon = "";
        String power_timeout_NC = "";
        String power_timeout_switch = "";
        String min_temp_SysMon = "";
        String max_temp_SysMon = "";
        String min_temp_NC = "";
        String max_temp_NC = "";
        String min_temp_processor_NC = "";
        String max_temp_processor_NC = "";
        String min_temp_switch = "";
        String max_temp_switch = "";
        String min_humidity_SysMon = "";
        String max_humidity_SysMon = "";
        String min_humidity_NC = "";
        String max_humidity_NC = "";
        String max_amp_SysMon = "";
        String max_amp_NC = "";
        String max_amp_switch = "";

        // Index for iterating thru the received string
        int i = 0;

        // Parse the received list of parameters:
        while(received_params[i] != ',')
            USART_baud += received_params[i++];
        // Skip delimiter
        i++;

        while(received_params[i] != ',')
            USART_RX_buffer_size += received_params[i++];
        i++;

        while(received_params[i] != ',')
            status_report_period += received_params[i++];
        i++;

        while(received_params[i] != ',')
            max_num_SOS_boot_attempts += received_params[i++];
        i++;

        while(received_params[i] != ',')
            max_num_subsystem_boot_attempts += received_params[i++];
        i++;

        while(received_params[i] != ',')
            max_num_primary_boot_attempts += received_params[i++];
        i++;

        while(received_params[i] != ',')
            device_reboot_period += received_params[i++];
        i++;

        while(received_params[i] != ',')
            present_switch += received_params[i++];
        i++;

        while(received_params[i] != ',')
            NC_boot_time += received_params[i++];
        i++;

        while(received_params[i] != ',')
            NC_config_time += received_params[i++];
        i++;

        while(received_params[i] != ',')
            switch_boot_time += received_params[i++];
        i++;

        while(received_params[i] != ',')
            heartbeat_timeout_NC += received_params[i++];
        i++;

        while(received_params[i] != ',')
            heartbeat_timeout_switch += received_params[i++];
        i++;

        while(received_params[i] != ',')
            environ_timeout_SysMon += received_params[i++];
        i++;

        while(received_params[i] != ',')
            environ_timeout_NC += received_params[i++];
        i++;

        while(received_params[i] != ',')
            temp_processor_timeout_NC += received_params[i++];
        i++;

        while(received_params[i] != ',')
            temp_timeout_switch += received_params[i++];
        i++;

        while(received_params[i] != ',')
            power_timeout_SysMon += received_params[i++];
        i++;

        while(received_params[i] != ',')
            power_timeout_NC += received_params[i++];
        i++;

        while(received_params[i] != ',')
            power_timeout_switch += received_params[i++];
        i++;

        while(received_params[i] != ',')
            min_temp_SysMon += received_params[i++];
        i++;

        while(received_params[i] != ',')
            max_temp_SysMon += received_params[i++];
        i++;

        while(received_params[i] != ',')
            min_temp_NC += received_params[i++];
        i++;

        while(received_params[i] != ',')
            max_temp_NC += received_params[i++];
        i++;

        while(received_params[i] != ',')
            min_temp_processor_NC += received_params[i++];
        i++;

        while(received_params[i] != ',')
            max_temp_processor_NC += received_params[i++];
        i++;

        while(received_params[i] != ',')
            min_temp_switch += received_params[i++];
        i++;

        while(received_params[i] != ',')
            max_temp_switch += received_params[i++];
        i++;

        while(received_params[i] != ',')
            min_humidity_SysMon += received_params[i++];
        i++;

        while(received_params[i] != ',')
            max_humidity_SysMon += received_params[i++];
        i++;

        while(received_params[i] != ',')
            min_humidity_NC += received_params[i++];
        i++;

        while(received_params[i] != ',')
            max_humidity_NC += received_params[i++];
        i++;

        while(received_params[i] != ',')
            max_amp_SysMon += received_params[i++];
        i++;

        while(received_params[i] != ',')
            max_amp_NC += received_params[i++];
        i++;

        while(received_params[i] != ',')
            max_amp_switch += received_params[i++];

        // Store new parameters in EEPROM
        __eeupd_dword_m32u4(&E_USART_BAUD, USART_baud.toInt());
        __eeupd_word_m32u4(&E_USART_RX_BUFFER_SIZE, (uint16_t)USART_RX_buffer_size.toInt());
        __eeupd_byte_m32u4(&E_STATUS_REPORT_PERIOD, (uint8_t)status_report_period.toInt());
        __eeupd_byte_m32u4(&E_MAX_NUM_SOS_BOOT_ATTEMPTS, (uint8_t)max_num_SOS_boot_attempts.toInt());
        __eeupd_byte_m32u4(&E_MAX_NUM_SUBSYSTEM_BOOT_ATTEMPTS, (uint8_t)max_num_subsystem_boot_attempts.toInt());
        __eeupd_byte_m32u4(&E_MAX_NUM_PRIMARY_BOOT_ATTEMPTS, (uint8_t)max_num_primary_boot_attempts.toInt());
        __eeupd_word_m32u4(&E_DEVICE_REBOOT_PERIOD, (uint16_t)device_reboot_period.toInt());
        __eeupd_byte_m32u4(&E_PRESENT_SWITCH, (uint8_t)present_switch.toInt());
        __eeupd_word_m32u4(&E_BOOT_TIME_NC, (uint16_t)NC_boot_time.toInt());
        __eeupd_word_m32u4(&E_CONFIG_TIME_NC, (uint16_t)NC_config_time.toInt());
        __eeupd_byte_m32u4(&E_BOOT_TIME_SWITCH, (uint8_t)switch_boot_time.toInt());
        __eeupd_byte_m32u4(&E_HEARTBEAT_TIMEOUT_NC, (uint8_t)heartbeat_timeout_NC.toInt());
        __eeupd_byte_m32u4(&E_HEARTBEAT_TIMEOUT_SWITCH, (uint8_t)heartbeat_timeout_switch.toInt());
        __eeupd_byte_m32u4(&E_ENVIRON_TIMEOUT_SYSMON, (uint8_t)environ_timeout_SysMon.toInt());
        __eeupd_byte_m32u4(&E_ENVIRON_TIMEOUT_NC, (uint8_t)environ_timeout_NC.toInt());
        __eeupd_byte_m32u4(&E_TEMP_PROCESSOR_TIMEOUT_NC, (uint8_t)temp_processor_timeout_NC.toInt());
        __eeupd_byte_m32u4(&E_TEMP_TIMEOUT_SWITCH, (uint8_t)temp_timeout_switch.toInt());
        __eeupd_byte_m32u4(&E_POWER_TIMEOUT_SYSMON, (uint8_t)power_timeout_SysMon.toInt());
        __eeupd_byte_m32u4(&E_POWER_TIMEOUT_NC, (uint8_t)power_timeout_NC.toInt());
        __eeupd_byte_m32u4(&E_POWER_TIMEOUT_SWITCH, (uint8_t)power_timeout_switch.toInt());
        __eeupd_word_m32u4(&E_TEMP_MIN_SYSMON, (uint16_t)min_temp_SysMon.toInt());
        __eeupd_word_m32u4(&E_TEMP_MAX_SYSMON, (uint16_t)max_temp_SysMon.toInt());
        __eeupd_word_m32u4(&E_TEMP_MIN_NC, (uint16_t)min_temp_NC.toInt());
        __eeupd_word_m32u4(&E_TEMP_MAX_NC, (uint16_t)max_temp_NC.toInt());
        __eeupd_word_m32u4(&E_TEMP_MIN_PROCESSOR_NC, (uint16_t)min_temp_processor_NC.toInt());
        __eeupd_word_m32u4(&E_TEMP_MAX_PROCESSOR_NC, (uint16_t)max_temp_processor_NC.toInt());
        __eeupd_word_m32u4(&E_TEMP_MIN_SWITCH, (uint16_t)min_temp_switch.toInt());
        __eeupd_word_m32u4(&E_TEMP_MAX_SWITCH, (uint16_t)max_temp_switch.toInt());
        __eeupd_byte_m32u4(&E_HUMIDITY_MIN_SYSMON, (uint8_t)min_humidity_SysMon.toInt());
        __eeupd_byte_m32u4(&E_HUMIDITY_MAX_SYSMON, (uint8_t)max_humidity_SysMon.toInt());
        __eeupd_byte_m32u4(&E_HUMIDITY_MIN_NC, (uint8_t)min_humidity_NC.toInt());
        __eeupd_byte_m32u4(&E_HUMIDITY_MAX_NC, (uint8_t)max_humidity_NC.toInt());
        __eeupd_word_m32u4(&E_MILLIAMP_MAX_SYSMON, (uint16_t)max_amp_SysMon.toInt());
        __eeupd_word_m32u4(&E_MILLIAMP_MAX_NC, (uint16_t)max_amp_NC.toInt());
        __eeupd_word_m32u4(&E_MILLIAMP_MAX_SWITCH, (uint16_t)max_amp_switch.toInt());
    }
}



//---------- G E T _ P A R A M S _ G N S --------------------------------------
/*
 *  Requests information about the guest nodes from the node controller.
 *
 *  :rtype: none
 */
void get_params_GNs()
{
    // Send request
    Serial.println('^');

    // Save the node controller's response into a string.
    // Default timeout value is 1 second
    String received_params = "";
    received_params = Serial.readStringUntil('!');

    // Were parameters received?
    if(received_params.length() > 0)
    {
        /* Order of parameters (coming from node controller):
         *
         *        Present/not present (guest node 1)
         *        Present/not present (guest node 2)
         *        Present/not present (guest node 3)
         *        Boot time (guest node 1) (seconds)
         *        Boot time (guest node 2) (seconds)
         *        Boot time (guest node 3) (seconds)
         *        Heartbeat timeout (guest node 1)
         *        Heartbeat timeout (guest node 2)
         *        Heartbeat timeout (guest node 3)
         *        Temperature timeout (guest node 1)
         *        Temperature timeout (guest node 2)
         *        Temperature timeout (guest node 3)
         *        Power timeout (guest node 1)
         *        Power timeout (guest node 2)
         *        Power timeout (guest node 3)
         *        Minimum temperature (Celsius) (guest node 1)
         *        Maximum temperature (Celsius) (guest node 1)
         *        Minimum temperature (Celsius) (guest node 2)
         *        Maximum temperature (Celsius) (guest node 2)
         *        Minimum temperature (Celsius) (guest node 3)
         *        Maximum temperature (Celsius) (guest node 3)
         *        Maximum amp draw (mA) (guest node 1)
         *        Maximum amp draw (mA) (guest node 2)
         *        Maximum amp draw (mA) (guest node 3)
         */

        // Temporary strings for holding each parameter
        String present_GN1 = "";
        String present_GN2 = "";
        String present_GN3 = "";
        String boot_time_GN1 = "";
        String boot_time_GN2 = "";
        String boot_time_GN3 = "";
        String heartbeat_timeout_GN1 = "";
        String heartbeat_timeout_GN2 = "";
        String heartbeat_timeout_GN3 = "";
        String temp_timeout_GN1 = "";
        String temp_timeout_GN2 = "";
        String temp_timeout_GN3 = "";
        String power_timeout_GN1 = "";
        String power_timeout_GN2 = "";
        String power_timeout_GN3 = "";
        String min_temp_GN1 = "";
        String max_temp_GN1 = "";
        String min_temp_GN2 = "";
        String max_temp_GN2 = "";
        String min_temp_GN3 = "";
        String max_temp_GN3 = "";
        String max_amp_GN1 = "";
        String max_amp_GN2 = "";
        String max_amp_GN3 = "";

        // Index for iterating thru the received string
        int i = 0;

        // Parse the received list of parameters:
        while(received_params[i] != ',')
            present_GN1 += received_params[i++];
        // Skip delimiter
        i++;

        while(received_params[i] != ',')
            present_GN2 += received_params[i++];
        i++;

        while(received_params[i] != ',')
            present_GN3 += received_params[i++];
        i++;

        while(received_params[i] != ',')
            boot_time_GN1 += received_params[i++];
        i++;

        while(received_params[i] != ',')
            boot_time_GN2 += received_params[i++];
        i++;

        while(received_params[i] != ',')
            boot_time_GN3 += received_params[i++];
        i++;

        while(received_params[i] != ',')
            heartbeat_timeout_GN1 += received_params[i++];
        i++;

        while(received_params[i] != ',')
            heartbeat_timeout_GN2 += received_params[i++];
        i++;

        while(received_params[i] != ',')
            heartbeat_timeout_GN3 += received_params[i++];
        i++;

        while(received_params[i] != ',')
            temp_timeout_GN1 += received_params[i++];
        i++;

        while(received_params[i] != ',')
            temp_timeout_GN2 += received_params[i++];
        i++;

        while(received_params[i] != ',')
            temp_timeout_GN3 += received_params[i++];
        i++;

        while(received_params[i] != ',')
            power_timeout_GN1 += received_params[i++];
        i++;

        while(received_params[i] != ',')
            power_timeout_GN2 += received_params[i++];
        i++;

        while(received_params[i] != ',')
            power_timeout_GN3 += received_params[i++];
        i++;

        while(received_params[i] != ',')
            min_temp_GN1 += received_params[i++];
        i++;

        while(received_params[i] != ',')
            max_temp_GN1 += received_params[i++];
        i++;

        while(received_params[i] != ',')
            min_temp_GN2 += received_params[i++];
        i++;

        while(received_params[i] != ',')
            max_temp_GN2 += received_params[i++];
        i++;

        while(received_params[i] != ',')
            min_temp_GN3 += received_params[i++];
        i++;

        while(received_params[i] != ',')
            max_temp_GN3 += received_params[i++];
        i++;

        while(received_params[i] != ',')
            max_amp_GN1 += received_params[i++];
        i++;

        while(received_params[i] != ',')
            max_amp_GN2 += received_params[i++];
        i++;

        while(received_params[i] != ',')
            max_amp_GN3 += received_params[i++];

        // Store new parameters in EEPROM
        __eeupd_byte_m32u4(&E_PRESENT_GN1, (uint8_t)present_GN1.toInt());
        __eeupd_byte_m32u4(&E_PRESENT_GN2, (uint8_t)present_GN2.toInt());
        __eeupd_byte_m32u4(&E_PRESENT_GN3, (uint8_t)present_GN3.toInt());
        __eeupd_word_m32u4(&E_BOOT_TIME_GN1, (uint16_t)boot_time_GN1.toInt());
        __eeupd_word_m32u4(&E_BOOT_TIME_GN2, (uint16_t)boot_time_GN2.toInt());
        __eeupd_word_m32u4(&E_BOOT_TIME_GN3, (uint16_t)boot_time_GN3.toInt());
        __eeupd_byte_m32u4(&E_HEARTBEAT_TIMEOUT_GN1, (uint8_t)heartbeat_timeout_GN1.toInt());
        __eeupd_byte_m32u4(&E_HEARTBEAT_TIMEOUT_GN2, (uint8_t)heartbeat_timeout_GN2.toInt());
        __eeupd_byte_m32u4(&E_HEARTBEAT_TIMEOUT_GN3, (uint8_t)heartbeat_timeout_GN3.toInt());
        __eeupd_byte_m32u4(&E_TEMP_TIMEOUT_GN1, (uint8_t)temp_timeout_GN1.toInt());
        __eeupd_byte_m32u4(&E_TEMP_TIMEOUT_GN2, (uint8_t)temp_timeout_GN2.toInt());
        __eeupd_byte_m32u4(&E_TEMP_TIMEOUT_GN3, (uint8_t)temp_timeout_GN3.toInt());
        __eeupd_byte_m32u4(&E_POWER_TIMEOUT_GN1, (uint8_t)power_timeout_GN1.toInt());
        __eeupd_byte_m32u4(&E_POWER_TIMEOUT_GN2, (uint8_t)power_timeout_GN2.toInt());
        __eeupd_byte_m32u4(&E_POWER_TIMEOUT_GN3, (uint8_t)power_timeout_GN3.toInt());
        __eeupd_word_m32u4(&E_TEMP_MIN_GN1, (uint16_t)min_temp_GN1.toInt());
        __eeupd_word_m32u4(&E_TEMP_MAX_GN1, (uint16_t)max_temp_GN1.toInt());
        __eeupd_word_m32u4(&E_TEMP_MIN_GN2, (uint16_t)min_temp_GN2.toInt());
        __eeupd_word_m32u4(&E_TEMP_MAX_GN2, (uint16_t)max_temp_GN2.toInt());
        __eeupd_word_m32u4(&E_TEMP_MIN_GN3, (uint16_t)min_temp_GN3.toInt());
        __eeupd_word_m32u4(&E_TEMP_MAX_GN3, (uint16_t)max_temp_GN3.toInt());
        __eeupd_word_m32u4(&E_MILLIAMP_MAX_GN1, (uint16_t)max_amp_GN1.toInt());
        __eeupd_word_m32u4(&E_MILLIAMP_MAX_GN2, (uint16_t)max_amp_GN2.toInt());
        __eeupd_word_m32u4(&E_MILLIAMP_MAX_GN3, (uint16_t)max_amp_GN3.toInt());
    }
}

//---------- I N I T _ C U R R E N T _ S E N S O R ------------------------------------------
/*
 *  Initializes the appropriate current sensor with the correct gain value.
 *
 *  :rtype: none
 */


void init_current_sensor(byte Which_Current_Sensor)
{
    // Start I2C transaction with switch's current sensor
    Wire.beginTransmission(Which_Current_Sensor);
    // Tell sensor we're writing to "gain" register
    Wire.write(0x04);
    // Write 3 expected bytes to "gain" register (select 8 amp range)
    Wire.write(0x00);
    Wire.write(0x00);
    Wire.write(0x02);
    // End I2C transaction (with stop bit)
    Wire.endTransmission(1);
}

//---------- I N I T _ P R I M A R Y ------------------------------------------
/*
 *  Initializes/starts all necessary ports, peripherals, interrupts, etc.
 *
 *  :rtype: none
 */
void init_primary()
{

    Serial.println("Booting Primary...");

    // Enable interrupts
    __asm__ __volatile__ ("sei" ::: "memory");

    // Set sleep mode to "power down" (turns off all clocks).
    // See datasheet and sleep.h file.
    do { (*(volatile uint8_t *)((0x33) + 0x20)) = (((*(volatile uint8_t *)((0x33) + 0x20)) & ~((1 << (1)) | (1 << (2)) | (1 << (3)))) | ((1 << (2)))); } while(0);

    // Start watchdog with 2 second timeout
    __asm__ __volatile__ ( "in __tmp_reg__,__SREG__" "\n\t" "cli" "\n\t" "wdr" "\n\t" "sts %0,%1" "\n\t" "out __SREG__,__tmp_reg__" "\n\t" "sts %0,%2" "\n\t" : /* no outputs */ : "M" (((uint16_t) &((*(volatile uint8_t *)(0x60))))), "r" ((1 << (4)) | (1 << (3))), "r" ((uint8_t) ((7 & 0x08 ? (1 << (5)) : 0x00) | (1 << (3)) | (7 & 0x07)) ) : "r0" );

    Serial.println("WD enabled to 2 Seconds...");

    // Make sure all the Timer1 registers are cleared
    (*(volatile uint8_t *)(0x80)) = 0;
    (*(volatile uint8_t *)(0x81)) = 0;
    (*(volatile uint8_t *)(0x82)) = 0;
    (*(volatile uint16_t *)(0x84)) = 0;
    (*(volatile uint16_t *)(0x88)) = 0;
    (*(volatile uint16_t *)(0x8A)) = 0;
    (*(volatile uint16_t *)(0x8C)) = 0;
    (*(volatile uint16_t *)(0x86)) = 0;
    (*(volatile uint8_t *)(0x6F)) = 0;

    // Enable Timer1 overflow interrupt
    (*(volatile uint8_t *)(0x6F)) = (1 << (0));

    // Start Timer1 with prescaler of clk/256 (timeout of approx. 1 second)
    (*(volatile uint8_t *)(0x81)) = (1 << (2));

    // Join I2C bus as master
    Wire.begin();

    // Enable serial comms
    Serial.begin(__eerd_dword_m32u4(&E_USART_BAUD));

    Serial.println("Serial Communication Enabled...");


    // Clear POST result to avoid confusion if a future boot fails
    __eeupd_byte_m32u4(&E_POST_RESULT, 0);

    // Clear the number of SOS boot attempts to start with a clean slate
    // for the next partial boot failure
    __eeupd_byte_m32u4(&E_NUM_SOS_BOOT_ATTEMPTS, 0);

    // Clear the number of primary boot attempts to start with a clean slate
    // for the next boot failure
//     eeprom_update_byte(&E_NUM_PRIMARY_BOOT_ATTEMPTS, 0);

    // Clear the flag for the timer test being incomplete, otherwise the next
    // POST may incorrectly mark the timer as malfunctioning
    __eeupd_byte_m32u4(&E_TIMER_TEST_INCOMPLETE, 0);

    // Set ADC reference voltage to Vcc
    analogReference(1);

    // Read ADC channels to settle them down

    analogRead(A5);
    analogRead(A0);
    analogRead(A1);
    analogRead(A2);
    analogRead(A3);
    analogRead(A4);

    // Start HTU21D
    SysMon_HTU21D.begin();

    init_current_sensor(0x60);
    init_current_sensor(0x62);
    init_current_sensor(0x63);
    init_current_sensor(0x68);
    init_current_sensor(0x6A);
    init_current_sensor(0x6B);


//     // Start I2C transaction with SysMon's current sensor
//     Wire.beginTransmission(ADDR_CURRENT_SENSOR_SYSMON);
//     // Tell sensor we're writing to "gain" register
//     Wire.write(0x04);
//     // Write 3 expected bytes to "gain" register (select 8 amp range)
//     Wire.write(0x00);
//     Wire.write(0x00);
//     Wire.write(0x02);
//     // End I2C transaction (with stop bit)
//     Wire.endTransmission(1);
//
//     // Start I2C transaction with NC's current sensor
//     Wire.beginTransmission(ADDR_CURRENT_SENSOR_NC);
//     // Tell sensor we're writing to "gain" register
//     Wire.write(0x04);
//     // Write 3 expected bytes to "gain" register (select 8 amp range)
//     Wire.write(0x00);
//     Wire.write(0x00);
//     Wire.write(0x02);
//     // End I2C transaction (with stop bit)
//     Wire.endTransmission(1);
//
//     // Start I2C transaction with switch's current sensor
//     Wire.beginTransmission(ADDR_CURRENT_SENSOR_SWITCH);
//     // Tell sensor we're writing to "gain" register
//     Wire.write(0x04);
//     // Write 3 expected bytes to "gain" register (select 8 amp range)
//     Wire.write(0x00);
//     Wire.write(0x00);
//     Wire.write(0x02);
//     // End I2C transaction (with stop bit)
//     Wire.endTransmission(1);
//
//     // Start I2C transaction with GN1's current sensor
//     Wire.beginTransmission(ADDR_CURRENT_SENSOR_GN1);
//     // Tell sensor we're writing to "gain" register
//     Wire.write(0x04);
//     // Write 3 expected bytes to "gain" register (select 8 amp range)
//     Wire.write(0x00);
//     Wire.write(0x00);
//     Wire.write(0x02);
//     // End I2C transaction (with stop bit)
//     Wire.endTransmission(1);
//
//     // Start I2C transaction with GN2's current sensor
//     Wire.beginTransmission(ADDR_CURRENT_SENSOR_GN2);
//     // Tell sensor we're writing to "gain" register
//     Wire.write(0x04);
//     // Write 3 expected bytes to "gain" register (select 8 amp range)
//     Wire.write(0x00);
//     Wire.write(0x00);
//     Wire.write(0x02);
//     // End I2C transaction (with stop bit)
//     Wire.endTransmission(1);
//
//     // Start I2C transaction with GN3's current sensor
//     Wire.beginTransmission(ADDR_CURRENT_SENSOR_GN3);
//     // Tell sensor we're writing to "gain" register
//     Wire.write(0x04);
//     // Write 3 expected bytes to "gain" register (select 8 amp range)
//     Wire.write(0x00);
//     Wire.write(0x00);
//     Wire.write(0x02);
//     // End I2C transaction (with stop bit)
//     Wire.endTransmission(1);

    // Give relays time to settle down, in case there was a chip reset
//     delay(POWER_CYCLE_DELAY);

    // Set relay pins to output mode
    pinMode(4, 0x1);
    pinMode(6, 0x1);
    pinMode(8, 0x1);
    pinMode(10, 0x1);
    pinMode(12, 0x1);

    // Set heartbeat pins to input mode (just for clarity)
    pinMode(5, 0x0);
    pinMode(7, 0x0);
    pinMode(9, 0x0);
    pinMode(11, 0x0);
    pinMode(13, 0x0);


    Serial.println("Finished the boot sequence ... I have not powered ON anything yet...");

}



//---------- S E T _ D E F A U L T _ E E P R O M ------------------------------
/*
 *   Assigns default values to the parameters stored in EEPROM.  This function
 *   is only executed on the first boot of a new SysMon, to avoid writing to
 *   EEPROM every time.
 *
 *   Note: EEPROM only stores raw data, meaning no data types.  If you want to
 *   store a negative number, you'll have to store it as the two's complement
 *   value, then type cast it when you're reading it.
 *
 *   :rtype: none
 */
void set_default_eeprom()
{
    // EEPROM addresses whose values are set by node controller:
    __eeupd_dword_m32u4(&E_USART_BAUD, 57600);
    __eeupd_word_m32u4(&E_USART_RX_BUFFER_SIZE, 200);
    __eeupd_byte_m32u4(&E_STATUS_REPORT_PERIOD, 30);
    __eeupd_byte_m32u4(&E_MAX_NUM_SOS_BOOT_ATTEMPTS, 5);
    __eeupd_byte_m32u4(&E_MAX_NUM_SUBSYSTEM_BOOT_ATTEMPTS, 5);
    __eeupd_byte_m32u4(&E_MAX_NUM_PRIMARY_BOOT_ATTEMPTS, 5);
    __eeupd_word_m32u4(&E_DEVICE_REBOOT_PERIOD, 60);
    __eeupd_byte_m32u4(&E_PRESENT_SWITCH, 0);
    __eeupd_word_m32u4(&E_BOOT_TIME_NC, 40);
    __eeupd_word_m32u4(&E_CONFIG_TIME_NC, 180);
    __eeupd_byte_m32u4(&E_BOOT_TIME_SWITCH, 15);
    __eeupd_word_m32u4(&E_BOOT_TIME_GN1, 10);
    __eeupd_word_m32u4(&E_BOOT_TIME_GN2, 10);
    __eeupd_word_m32u4(&E_BOOT_TIME_GN3, 10);
    __eeupd_byte_m32u4(&E_PRESENT_GN1, 0);
    __eeupd_byte_m32u4(&E_PRESENT_GN2, 0);
    __eeupd_byte_m32u4(&E_PRESENT_GN3, 0);
    __eeupd_byte_m32u4(&E_HEARTBEAT_TIMEOUT_NC, 5);
    __eeupd_byte_m32u4(&E_HEARTBEAT_TIMEOUT_SWITCH, 5);
    __eeupd_byte_m32u4(&E_HEARTBEAT_TIMEOUT_GN1, 5);
    __eeupd_byte_m32u4(&E_HEARTBEAT_TIMEOUT_GN2, 5);
    __eeupd_byte_m32u4(&E_HEARTBEAT_TIMEOUT_GN3, 5);
    __eeupd_byte_m32u4(&E_ENVIRON_TIMEOUT_SYSMON, 5);
    __eeupd_byte_m32u4(&E_ENVIRON_TIMEOUT_NC, 5);
    __eeupd_byte_m32u4(&E_TEMP_PROCESSOR_TIMEOUT_NC, 5);
    __eeupd_byte_m32u4(&E_TEMP_TIMEOUT_SWITCH, 5);
    __eeupd_byte_m32u4(&E_TEMP_TIMEOUT_GN1, 5);
    __eeupd_byte_m32u4(&E_TEMP_TIMEOUT_GN2, 5);
    __eeupd_byte_m32u4(&E_TEMP_TIMEOUT_GN3, 5);
    __eeupd_byte_m32u4(&E_POWER_TIMEOUT_SYSMON, 5);
    __eeupd_byte_m32u4(&E_POWER_TIMEOUT_NC, 5);
    __eeupd_byte_m32u4(&E_POWER_TIMEOUT_SWITCH, 5);
    __eeupd_byte_m32u4(&E_POWER_TIMEOUT_GN1, 5);
    __eeupd_byte_m32u4(&E_POWER_TIMEOUT_GN2, 5);
    __eeupd_byte_m32u4(&E_POWER_TIMEOUT_GN3, 5);
    __eeupd_word_m32u4(&E_TEMP_MIN_SYSMON, 0);
    __eeupd_word_m32u4(&E_TEMP_MAX_SYSMON, 100);
    __eeupd_word_m32u4(&E_TEMP_MIN_NC, 0);
    __eeupd_word_m32u4(&E_TEMP_MAX_NC, 100);
    // Temperatures below are ADC values (see WagMan.py on node controller)
    __eeupd_word_m32u4(&E_TEMP_MIN_PROCESSOR_NC, 115);
    __eeupd_word_m32u4(&E_TEMP_MAX_PROCESSOR_NC, 969);
    __eeupd_word_m32u4(&E_TEMP_MIN_SWITCH, 417);
    __eeupd_word_m32u4(&E_TEMP_MAX_SWITCH, 969);
    __eeupd_word_m32u4(&E_TEMP_MIN_GN1, 417);
    __eeupd_word_m32u4(&E_TEMP_MAX_GN1, 969);
    __eeupd_word_m32u4(&E_TEMP_MIN_GN2, 417);
    __eeupd_word_m32u4(&E_TEMP_MAX_GN2, 969);
    __eeupd_word_m32u4(&E_TEMP_MIN_GN3, 417);
    __eeupd_word_m32u4(&E_TEMP_MAX_GN3, 969);
    __eeupd_byte_m32u4(&E_HUMIDITY_MIN_SYSMON, 0);
    __eeupd_byte_m32u4(&E_HUMIDITY_MAX_SYSMON, 100);
    __eeupd_byte_m32u4(&E_HUMIDITY_MIN_NC, 0);
    __eeupd_byte_m32u4(&E_HUMIDITY_MAX_NC, 100);
    __eeupd_word_m32u4(&E_MILLIAMP_MAX_SYSMON, 5000);
    __eeupd_word_m32u4(&E_MILLIAMP_MAX_NC, 2500);
    __eeupd_word_m32u4(&E_MILLIAMP_MAX_SWITCH, 1500);
    __eeupd_word_m32u4(&E_MILLIAMP_MAX_GN1, 1500);
    __eeupd_word_m32u4(&E_MILLIAMP_MAX_GN2, 1500);
    __eeupd_word_m32u4(&E_MILLIAMP_MAX_GN3, 1500);

    // Save the indicator that this SysMon has booted before
    __eeupd_byte_m32u4(&E_FIRST_BOOT, 0);

    // Clear the counter for number of primary boot attempts
    __eeupd_byte_m32u4(&E_NUM_PRIMARY_BOOT_ATTEMPTS, 0);
}
