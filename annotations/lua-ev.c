/* lua-ev.c
 * author: xjdrew
 * date: 2014-07-13
 */

/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.2 Diagnostics	<assert.h>
 */
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* These are defined by the user (or the compiler)
   to specify the desired environment:

   __STRICT_ANSI__	ISO Standard C.
   _ISOC99_SOURCE	Extensions to ISO C89 from ISO C99.
   _ISOC11_SOURCE	Extensions to ISO C99 from ISO C11.
   _POSIX_SOURCE	IEEE Std 1003.1.
   _POSIX_C_SOURCE	If ==1, like _POSIX_SOURCE; if >=2 add IEEE Std 1003.2;
            if >=199309L, add IEEE Std 1003.1b-1993;
            if >=199506L, add IEEE Std 1003.1c-1995;
            if >=200112L, all of IEEE 1003.1-2004
            if >=200809L, all of IEEE 1003.1-2008
   _XOPEN_SOURCE	Includes POSIX and XPG things.  Set to 500 if
            Single Unix conformance is wanted, to 600 for the
            sixth revision, to 700 for the seventh revision.
   _XOPEN_SOURCE_EXTENDED XPG things and X/Open Unix extensions.
   _LARGEFILE_SOURCE	Some more functions for correct standard I/O.
   _LARGEFILE64_SOURCE	Additional functionality from LFS for large files.
   _FILE_OFFSET_BITS=N	Select default filesystem interface.
   _ATFILE_SOURCE	Additional *at interfaces.
   _GNU_SOURCE		All of the above, plus GNU extensions.
   _DEFAULT_SOURCE	The default set of features (taking precedence over
            __STRICT_ANSI__).
   _REENTRANT		Select additionally reentrant object.
   _THREAD_SAFE		Same as _REENTRANT, often used by other systems.
   _FORTIFY_SOURCE	If set to numeric value > 0 additional security
            measures are defined, according to level.

   The `-ansi' switch to the GNU C compiler, and standards conformance
   options such as `-std=c99', define __STRICT_ANSI__.  If none of
   these are defined, or if _DEFAULT_SOURCE is defined, the default is
   to have _POSIX_SOURCE set to one and _POSIX_C_SOURCE set to
   200809L, as well as enabling miscellaneous functions from BSD and
   SVID.  If more than one of these are defined, they accumulate.  For
   example __STRICT_ANSI__, _POSIX_SOURCE and _POSIX_C_SOURCE together
   give you ISO C, 1003.1, and 1003.2, but nothing else.

   These are defined by this file and are used by the
   header files to decide what to declare or define:

   __USE_ISOC11		Define ISO C11 things.
   __USE_ISOC99		Define ISO C99 things.
   __USE_ISOC95		Define ISO C90 AMD1 (C95) things.
   __USE_POSIX		Define IEEE Std 1003.1 things.
   __USE_POSIX2		Define IEEE Std 1003.2 things.
   __USE_POSIX199309	Define IEEE Std 1003.1, and .1b things.
   __USE_POSIX199506	Define IEEE Std 1003.1, .1b, .1c and .1i things.
   __USE_XOPEN		Define XPG things.
   __USE_XOPEN_EXTENDED	Define X/Open Unix things.
   __USE_UNIX98		Define Single Unix V2 things.
   __USE_XOPEN2K        Define XPG6 things.
   __USE_XOPEN2KXSI     Define XPG6 XSI things.
   __USE_XOPEN2K8       Define XPG7 things.
   __USE_XOPEN2K8XSI    Define XPG7 XSI things.
   __USE_LARGEFILE	Define correct standard I/O things.
   __USE_LARGEFILE64	Define LFS things with separate names.
   __USE_FILE_OFFSET64	Define 64bit interface as default.
   __USE_MISC		Define things from 4.3BSD or System V Unix.
   __USE_ATFILE		Define *at interfaces and AT_* constants for them.
   __USE_GNU		Define GNU extensions.
   __USE_REENTRANT	Define reentrant/thread-safe *_r functions.
   __USE_FORTIFY_LEVEL	Additional security measures used, according to level.

   The macros `__GNU_LIBRARY__', `__GLIBC__', and `__GLIBC_MINOR__' are
   defined by this file unconditionally.  `__GNU_LIBRARY__' is provided
   only for compatibility.  All new code should use the other symbols
   to test for features.

   All macros listed above as possibly being defined by this file are
   explicitly undefined if they are not explicitly defined.
   Feature-test macros that are not defined by the user or compiler
   but are implied by the other feature-test macros defined (or by the
   lack of any definitions) are defined by the file.  */

/* Undefine everything, so we get a clean slate.  */
/* Suppress kernel-name space pollution unless user expressedly asks
   for it.  */

/* Convenience macros to test the versions of glibc and gcc.
   Use them like this:
   #if __GNUC_PREREQ (2,8)
   ... code requiring gcc 2.8 or later ...
   #endif
   Note - they won't work for gcc1 or glibc1, since the _MINOR macros
   were not defined then.  */

/* _BSD_SOURCE and _SVID_SOURCE are deprecated aliases for
   _DEFAULT_SOURCE.  If _DEFAULT_SOURCE is present we do not
   issue a warning; the expectation is that the source is being
   transitioned to use the new macro.  */
/* If _GNU_SOURCE was defined by the user, turn on all the other features.  */
/* If nothing (other than _GNU_SOURCE and _DEFAULT_SOURCE) is defined,
   define _DEFAULT_SOURCE.  */
/* This is to enable the ISO C11 extension.  */

/* This is to enable the ISO C99 extension.  */

/* This is to enable the ISO C90 Amendment 1:1995 extension.  */

/* This is to enable compatibility for ISO C++11.

   So far g++ does not provide a macro.  Check the temporary macro for
   now, too.  */

/* If none of the ANSI/POSIX macros are defined, or if _DEFAULT_SOURCE
   is defined, use POSIX.1-2008 (or another version depending on
   _XOPEN_SOURCE).  */
/* Get definitions of __STDC_* predefined macros, if the compiler has
   not preincluded this header automatically.  */

/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */

/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */

/* We do not support C11 <threads.h>.  */

/* This macro indicates that the installed library is the GNU C Library.
   For historic reasons the value now is 6 and this will stay from now
   on.  The use of this variable is deprecated.  Use __GLIBC__ and
   __GLIBC_MINOR__ now (see below) when you want to test for a specific
   GNU C library version and use the values in <gnu/lib-names.h> to get
   the sonames of the shared libraries.  */

/* Major and minor version number of the GNU C library package.  Use
   these macros to test for features in specific releases.  */

/* This is here only because every header file already includes this one.  */

/* Copyright (C) 1992-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* We are almost always included from features.h. */

/* The GNU libc does not support any K&R compilers or the traditional mode
   of ISO C compilers anymore.  Check for some of the combinations not
   anymore supported.  */

/* Some user header file might have defined this before.  */

/* All functions, except those with callbacks or those that
   synchronize memory, are leaf functions.  */
/* GCC can always grok prototypes.  For C++ programs we add throw()
   to help it optimize the function calls.  But this works only with
   gcc 2.8.x and egcs.  For gcc 3.2 and up we even mark C functions
   as non-throwing using a function attribute since programs can use
   the -fexceptions options for C code as well.  */
/* These two macros are not used in glibc anymore.  They are kept here
   only because some other projects expect the macros to be defined.  */

/* For these things, GCC behaves the ANSI way normally,
   and the non-ANSI way under -traditional.  */

/* This is not a typedef so `const __ptr_t' does the right thing.  */

/* C++ needs to know that types and declarations are C, not C++.  */
/* The standard library needs the functions from the ISO C90 standard
   in the std namespace.  At the same time we want to be safe for
   future changes and we include the ISO C99 code in the non-standard
   namespace __c99.  The C++ wrapper header take case of adding the
   definitions to the global namespace.  */
/* For compatibility we do not add the declarations into any
   namespace.  They will end up in the global namespace which is what
   old code expects.  */
/* Fortify support.  */
/* Support for flexible arrays.  */

/* GCC 2.97 supports C99 flexible array members.  */
/* __asm__ ("xyz") is used throughout the headers to rename functions
   at the assembly language level.  This is wrapped by the __REDIRECT
   macro, in order to support compilers that can do this some other
   way.  When compilers don't support asm-names at all, we have to do
   preprocessor tricks instead (which don't have exactly the right
   semantics, but it's the best we can do).

   Example:
   int __REDIRECT(setpgrp, (__pid_t pid, __pid_t pgrp), setpgid); */
/*
#elif __SOME_OTHER_COMPILER__

# define __REDIRECT(name, proto, alias) name proto; \
    _Pragma("let " #name " = " #alias)
*/

/* GCC has various useful declarations that can be made with the
   `__attribute__' syntax.  All of the ways we use this do fine if
   they are omitted for compilers that don't understand it. */

/* At some point during the gcc 2.96 development the `malloc' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.  */

/* Tell the compiler which arguments to an allocation function
   indicate the size of the allocation.  */

/* At some point during the gcc 2.96 development the `pure' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.  */

/* This declaration tells the compiler that the value is constant.  */

/* At some point during the gcc 3.1 development the `used' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.  */
/* gcc allows marking deprecated functions.  */

/* At some point during the gcc 2.8 development the `format_arg' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.
   If several `format_arg' attributes are given for the same function, in
   gcc-3.0 and older, all but the last one are ignored.  In newer gccs,
   all designated arguments are considered.  */

/* At some point during the gcc 2.97 development the `strfmon' format
   attribute for functions was introduced.  We don't want to use it
   unconditionally (although this would be possible) since it
   generates warnings.  */

/* The nonull function attribute allows to mark pointer parameters which
   must not be NULL.  */

/* If fortification mode, we warn about unused results of certain
   function calls which can lead to problems.  */
/* Forces a function to be always inlined.  */

/* Associate error messages with the source location of the call site rather
   than with the source location inside the function.  */

/* GCC 4.3 and above with -std=c99 or -std=gnu99 implements ISO C99
   inline semantics, unless -fgnu89-inline is used.  Using __GNUC_STDC_INLINE__
   or __GNUC_GNU_INLINE is not a good enough check for gcc because gcc versions
   older than 4.3 may define these macros and still not guarantee GNU inlining
   semantics.

   clang++ identifies itself as gcc-4.2, but has support for GNU inlining
   semantics, that can be checked fot by using the __GNUC_STDC_INLINE_ and
   __GNUC_GNU_INLINE__ macro definitions.  */
/* GCC 4.3 and above allow passing all anonymous arguments of an
   __extern_always_inline function to some other vararg function.  */

/* It is possible to compile containing GCC extensions even if GCC is
   run in pedantic mode if the uses are carefully marked using the
   `__extension__' keyword.  But this is not generally available before
   version 2.8.  */

/* __restrict is known in EGCS 1.2 and above. */

/* ISO C99 also allows to declare arrays as non-overlapping.  The syntax is
     array_name[restrict]
   GCC 3.1 supports this.  */
/* Determine the wordsize from the preprocessor defines.  */
/* Both x86-64 and x32 use the 64-bit system call interface.  */

/* If we don't have __REDIRECT, prototypes will be missing if
   __USE_FILE_OFFSET64 but not __USE_LARGEFILE[64]. */

/* Decide whether we can define 'extern inline' functions in headers.  */

/* This is here only because every header file already includes this one.
   Get the definitions of all the appropriate `__stub_FUNCTION' symbols.
   <gnu/stubs.h> contains `#define __stub_FUNCTION' when FUNCTION is a stub
   that will always return failure (and set errno to ENOSYS).  */

/* This file is automatically generated.
   This file selects the right generated file of `__stub_FUNCTION' macros
   based on the architecture being compiled for.  */

/* This file is automatically generated.
   It defines a symbol `__stub_FUNCTION' for each function
   in the C library which is a stub, meaning it will fail
   every time called, usually setting errno to ENOSYS.  */

/* void assert (int expression);

   If NDEBUG is defined, do nothing.
   If not, and EXPRESSION is zero, print an error message and abort.  */
/* This prints an "Assertion failed" message and aborts.  */
extern void __assert_fail(const char *__assertion, const char *__file,
                          unsigned int __line, const char *__function)
    __attribute__((__nothrow__)) __attribute__((__noreturn__));

/* Likewise, but prints the error text for ERRNUM.  */
extern void __assert_perror_fail(int __errnum, const char *__file,
                                 unsigned int __line, const char *__function)
    __attribute__((__nothrow__)) __attribute__((__noreturn__));

/* The following is not at all used here but needed for standard
   compliance.  */
extern void __assert(const char *__assertion, const char *__file, int __line)
    __attribute__((__nothrow__)) __attribute__((__noreturn__));
/* Version 2.4 and later of GCC define a magical variable `__PRETTY_FUNCTION__'
   which contains the name of the function currently being defined.
   This is broken in G++ before version 2.6.
   C9x has a similar variable called __func__, but prefer the GCC one since
   it demangles C++ function names.  */
/* Define ISO C stdio on top of C++ iostreams.
   Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.19 Input/output	<stdio.h>
 */
/*===---- stddef.h - Basic type definitions --------------------------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */
/* Always define size_t when modules are available. */

typedef long unsigned int size_t;
/* Some C libraries expect to see a wint_t here. Others (notably MinGW) will use
__WINT_TYPE__ directly; accommodate both by requiring __need_wint_t */

/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */

/* Determine the wordsize from the preprocessor defines.  */
/* Both x86-64 and x32 use the 64-bit system call interface.  */

/* Convenience types.  */
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;

/* Fixed-size types, underlying types depend on word size and compiler.  */
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;

/* quad_t is also 64 bits.  */

typedef long int __quad_t;
typedef unsigned long int __u_quad_t;

/* The machine-dependent file <bits/typesizes.h> defines __*_T_TYPE
   macros for each of the OS types we define below.  The definitions
   of those macros must use the following macros for underlying types.
   We define __S<SIZE>_TYPE and __U<SIZE>_TYPE for the signed and unsigned
   variants of each of the following integer types on this machine.

    16		-- "natural" 16-bit type (always short)
    32		-- "natural" 32-bit type (always int)
    64		-- "natural" 64-bit type (long or long long)
    LONG32		-- 32-bit type, traditionally long
    QUAD		-- 64-bit type, always long long
    WORD		-- natural type of __WORDSIZE bits (int or long)
    LONGWORD	-- type of __WORDSIZE bits, traditionally long

   We distinguish WORD/LONGWORD, 32/LONG32, and 64/QUAD so that the
   conventional uses of `long' or `long long' type modifiers match the
   types we define, even when a less-adorned type would be the same size.
   This matters for (somewhat) portably writing printf/scanf formats for
   these types, where using the appropriate l or ll format modifiers can
   make the typedefs and the formats match up across all GNU platforms.  If
   we used `long' when it's 64 bits where `long long' is expected, then the
   compiler would warn about the formats not matching the argument types,
   and the programmer changing them to shut up the compiler would break the
   program's portability.

   Here we assume what is presently the case in all the GCC configurations
   we support: long long is always 64 bits, long is always word/address size,
   and int is always 32 bits.  */
/* No need to mark the typedef with __extension__.   */

/* bits/typesizes.h -- underlying types for *_t.  Linux/x86-64 version.
   Copyright (C) 2012-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* See <bits/types.h> for the meaning of these macros.  This file exists so
   that <bits/types.h> need not vary across different GNU platforms.  */

/* X32 kernel interface is 64-bit.  */
/* Tell the libc code that off_t and off64_t are actually the same type
   for all ABI purposes, even if possibly expressed as different base types
   for C type-checking purposes.  */

/* Same for ino_t and ino64_t.  */

/* Number of descriptors that can fit in an `fd_set'.  */

typedef unsigned long int __dev_t;   /* Type of device numbers.  */
typedef unsigned int __uid_t;        /* Type of user identifications.  */
typedef unsigned int __gid_t;        /* Type of group identifications.  */
typedef unsigned long int __ino_t;   /* Type of file serial numbers.  */
typedef unsigned long int __ino64_t; /* Type of file serial numbers (LFS).*/
typedef unsigned int __mode_t;       /* Type of file attribute bitmasks.  */
typedef unsigned long int __nlink_t; /* Type of file link counts.  */
typedef long int __off_t;            /* Type of file sizes and offsets.  */
typedef long int __off64_t; /* Type of file sizes and offsets (LFS).  */
typedef int __pid_t;        /* Type of process identifications.  */
typedef struct {
    int __val[2];
} __fsid_t;                         /* Type of file system IDs.  */
typedef long int __clock_t;         /* Type of CPU usage counts.  */
typedef unsigned long int __rlim_t; /* Type for resource measurement.  */
typedef unsigned long int
    __rlim64_t;                    /* Type for resource measurement (LFS).  */
typedef unsigned int __id_t;       /* General type for IDs.  */
typedef long int __time_t;         /* Seconds since the Epoch.  */
typedef unsigned int __useconds_t; /* Count of microseconds.  */
typedef long int __suseconds_t;    /* Signed count of microseconds.  */

typedef int __daddr_t; /* The type of a disk address.  */
typedef int __key_t;   /* Type of an IPC key.  */

/* Clock ID used in clock and timer functions.  */
typedef int __clockid_t;

/* Timer ID returned by `timer_create'.  */
typedef void *__timer_t;

/* Type to represent block size.  */
typedef long int __blksize_t;

/* Types from the Large File Support interface.  */

/* Type to count number of disk blocks.  */
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;

/* Type to count file system blocks.  */
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;

/* Type to count file system nodes.  */
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;

/* Type of miscellaneous file system fields.  */
typedef long int __fsword_t;

typedef long int __ssize_t; /* Type of a byte count, or error.  */

/* Signed long type used in system calls.  */
typedef long int __syscall_slong_t;
/* Unsigned long type used in system calls.  */
typedef unsigned long int __syscall_ulong_t;

/* These few don't really vary by system, they always correspond
   to one of the other defined types.  */
typedef __off64_t __loff_t; /* Type of file sizes and offsets (LFS).  */
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;

/* Duplicates info from stdint.h but this is used in unistd.h.  */
typedef long int __intptr_t;

/* Duplicate info from sys/socket.h.  */
typedef unsigned int __socklen_t;

/* Define outside of namespace so the C++ is happy.  */
struct _IO_FILE;

/* The opaque type of streams.  This is the definition used elsewhere.  */
typedef struct _IO_FILE FILE;
/* The opaque type of streams.  This is the definition used elsewhere.  */
typedef struct _IO_FILE __FILE;
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Written by Per Bothner <bothner@cygnus.com>.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.

   As a special exception, if you link the code in this file with
   files compiled with a GNU compiler to produce an executable,
   that does not cause the resulting executable to be covered by
   the GNU Lesser General Public License.  This exception does not
   however invalidate any other reasons why the executable file
   might be covered by the GNU Lesser General Public License.
   This exception applies to code released by its copyright holders
   in files containing the exception.  */

/* This file is needed by libio to define various configuration parameters.
   These are always the same in the GNU C library.  */

/* Define types for libio in terms of the standard internal type names.  */

/*===---- stddef.h - Basic type definitions --------------------------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */
/* Some C libraries expect to see a wint_t here. Others (notably MinGW) will use
__WINT_TYPE__ directly; accommodate both by requiring __need_wint_t */

/* Copyright (C) 1995-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *      ISO C99 Standard: 7.24
 *	Extended multibyte and wide character utilities	<wchar.h>
 */
/* Conversion state information.  */
typedef struct {
    int __count;
    union {
        unsigned int __wch;

        char __wchb[4];
    } __value; /* Value so far.  */
} __mbstate_t;

/* The rest of the file is only used if used if __need_mbstate_t is not
   defined.  */
/* Undefine all __need_* constants in case we are included to get those
   constants but the whole file was already read.  */
typedef struct {
    __off_t __pos;
    __mbstate_t __state;
} _G_fpos_t;
typedef struct {
    __off64_t __pos;
    __mbstate_t __state;
} _G_fpos64_t;
/* These library features are always available in the GNU C library.  */

/* This is defined by <bits/stat.h> if `st_blksize' exists.  */
/* ALL of these should be defined in _G_config.h */
/* This define avoids name pollution if we're using GNU stdarg.h */

/*===---- stdarg.h - Variable argument handling ----------------------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

typedef __builtin_va_list va_list;

/* GCC always defines __va_copy, but does not define va_copy unless in c99 mode
 * or -ansi is not specified, since it was not part of C90.
 */
typedef __builtin_va_list __gnuc_va_list;
/* Magic numbers and bits for the _flags field.
   The magic numbers use the high-order bits of _flags;
   the remaining bits are available for variable flags.
   Note: The magic numbers must all be negative if stdio
   emulation is desired. */
/* These are "formatting flags" matching the iostream fmtflags enum values. */
struct _IO_jump_t;
struct _IO_FILE;

/* Handle lock.  */

typedef void _IO_lock_t;

/* A streammarker remembers a position in a buffer. */

struct _IO_marker {
    struct _IO_marker *_next;
    struct _IO_FILE *_sbuf;
    /* If _pos >= 0
   it points to _buf->Gbase()+_pos. FIXME comment */
    /* if _pos < 0, it points to _buf->eBptr()+_pos. FIXME comment */
    int _pos;
};

/* This is the structure from the libstdc++ codecvt class.  */
enum __codecvt_result {
    __codecvt_ok,
    __codecvt_partial,
    __codecvt_error,
    __codecvt_noconv
};
struct _IO_FILE {
    int _flags; /* High-order word is _IO_MAGIC; rest is flags. */

    /* The following pointers correspond to the C++ streambuf protocol. */
    /* Note:  Tk uses the _IO_read_ptr and _IO_read_end fields directly. */
    char *_IO_read_ptr;   /* Current read pointer */
    char *_IO_read_end;   /* End of get area. */
    char *_IO_read_base;  /* Start of putback+get area. */
    char *_IO_write_base; /* Start of put area. */
    char *_IO_write_ptr;  /* Current put pointer. */
    char *_IO_write_end;  /* End of put area. */
    char *_IO_buf_base;   /* Start of reserve area. */
    char *_IO_buf_end;    /* End of reserve area. */
    /* The following fields are used to support backing up and undo. */
    char *_IO_save_base;   /* Pointer to start of non-current get area. */
    char *_IO_backup_base; /* Pointer to first valid character of backup area */
    char *_IO_save_end;    /* Pointer to end of non-current get area. */

    struct _IO_marker *_markers;

    struct _IO_FILE *_chain;

    int _fileno;

    int _flags2;

    __off_t _old_offset; /* This used to be _offset but it's too small.  */

    /* 1+column number of pbase(); 0 is unknown. */
    unsigned short _cur_column;
    signed char _vtable_offset;
    char _shortbuf[1];

    /*  char* _save_gptr;  char* _save_egptr; */

    _IO_lock_t *_lock;
    __off64_t _offset;

    void *__pad1;
    void *__pad2;
    void *__pad3;
    void *__pad4;

    size_t __pad5;
    int _mode;
    /* Make sure we don't get into trouble again.  */
    char _unused2[15 * sizeof(int) - 4 * sizeof(void *) - sizeof(size_t)];
};

typedef struct _IO_FILE _IO_FILE;

struct _IO_FILE_plus;

extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
/* Functions to do I/O and file management for a stream.  */

/* Read NBYTES bytes from COOKIE into a buffer pointed to by BUF.
   Return number of bytes read.  */
typedef __ssize_t __io_read_fn(void *__cookie, char *__buf, size_t __nbytes);

/* Write N bytes pointed to by BUF to COOKIE.  Write all N bytes
   unless there is an error.  Return number of bytes written.  If
   there is an error, return 0 and do not write anything.  If the file
   has been opened for append (__mode.__append set), then set the file
   pointer to the end of the file and then do the write; if not, just
   write at the current file pointer.  */
typedef __ssize_t __io_write_fn(void *__cookie, const char *__buf, size_t __n);

/* Move COOKIE's file position to *POS bytes from the
   beginning of the file (if W is SEEK_SET),
   the current position (if W is SEEK_CUR),
   or the end of the file (if W is SEEK_END).
   Set *POS to the new file position.
   Returns zero if successful, nonzero if not.  */
typedef int __io_seek_fn(void *__cookie, __off64_t *__pos, int __w);

/* Close COOKIE.  */
typedef int __io_close_fn(void *__cookie);
extern int __underflow(_IO_FILE *);
extern int __uflow(_IO_FILE *);
extern int __overflow(_IO_FILE *, int);
extern int _IO_getc(_IO_FILE *__fp);
extern int _IO_putc(int __c, _IO_FILE *__fp);
extern int _IO_feof(_IO_FILE *__fp) __attribute__((__nothrow__));
extern int _IO_ferror(_IO_FILE *__fp) __attribute__((__nothrow__));

extern int _IO_peekc_locked(_IO_FILE *__fp);

/* This one is for Emacs. */

extern void _IO_flockfile(_IO_FILE *) __attribute__((__nothrow__));
extern void _IO_funlockfile(_IO_FILE *) __attribute__((__nothrow__));
extern int _IO_ftrylockfile(_IO_FILE *) __attribute__((__nothrow__));
extern int _IO_vfscanf(_IO_FILE *__restrict, const char *__restrict,
                       __gnuc_va_list, int *__restrict);
extern int _IO_vfprintf(_IO_FILE *__restrict, const char *__restrict,
                        __gnuc_va_list);
extern __ssize_t _IO_padn(_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn(_IO_FILE *, void *, size_t);

extern __off64_t _IO_seekoff(_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos(_IO_FILE *, __off64_t, int);

extern void _IO_free_backup_area(_IO_FILE *) __attribute__((__nothrow__));

typedef __gnuc_va_list va_list;
typedef __off_t off_t;
typedef __ssize_t ssize_t;

/* The type of the second argument to `fgetpos' and `fsetpos'.  */

typedef _G_fpos_t fpos_t;
/* The possibilities for the third argument to `setvbuf'.  */

/* Default buffer size.  */

/* End of file character.
   Some things throughout the library rely on this being -1.  */

/* The possibilities for the third argument to `fseek'.
   These values should not be changed.  */
/* Default path prefix for `tempnam' and `tmpnam'.  */

/* Get the values:
   L_tmpnam	How long an array of chars must be to be passed to `tmpnam'.
   TMP_MAX	The minimum number of unique filenames generated by tmpnam
        (and tempnam when it uses tmpnam's name space),
        or tempnam (the two are separate).
   L_ctermid	How long an array to pass to `ctermid'.
   L_cuserid	How long an array to pass to `cuserid'.
   FOPEN_MAX	Minimum number of files that can be open at once.
   FILENAME_MAX	Maximum length of a filename.  */

/* Copyright (C) 1994-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* Standard streams.  */
extern struct _IO_FILE *stdin;  /* Standard input stream.  */
extern struct _IO_FILE *stdout; /* Standard output stream.  */
extern struct _IO_FILE *stderr; /* Standard error output stream.  */
/* C89/C99 say they're macros.  Make them happy.  */

/* Remove file FILENAME.  */
extern int remove(const char *__filename) __attribute__((__nothrow__));
/* Rename file OLD to NEW.  */
extern int rename(const char *__old, const char *__new)
    __attribute__((__nothrow__));

/* Rename file OLD relative to OLDFD to NEW relative to NEWFD.  */
extern int renameat(int __oldfd, const char *__old, int __newfd,
                    const char *__new) __attribute__((__nothrow__));

/* Create a temporary file and open it read/write.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */

extern FILE *tmpfile(void);
/* Generate a temporary filename.  */
extern char *tmpnam(char *__s) __attribute__((__nothrow__));

/* This is the reentrant variant of `tmpnam'.  The only difference is
   that it does not allow S to be NULL.  */
extern char *tmpnam_r(char *__s) __attribute__((__nothrow__));

/* Generate a unique temporary filename using up to five characters of PFX
   if it is not NULL.  The directory to put this file in is searched for
   as follows: First the environment variable "TMPDIR" is checked.
   If it contains the name of a writable directory, that directory is used.
   If not and if DIR is not NULL, that value is checked.  If that fails,
   P_tmpdir is tried and finally "/tmp".  The storage for the filename
   is allocated by `malloc'.  */
extern char *tempnam(const char *__dir, const char *__pfx)
    __attribute__((__nothrow__)) __attribute__((__malloc__));

/* Close STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fclose(FILE *__stream);
/* Flush STREAM, or all streams if STREAM is NULL.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fflush(FILE *__stream);

/* Faster versions when locking is not required.

   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern int fflush_unlocked(FILE *__stream);
/* Open a file and create a new stream for it.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern FILE *fopen(const char *__restrict __filename,
                   const char *__restrict __modes);
/* Open a file, replacing an existing stream with it.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern FILE *freopen(const char *__restrict __filename,
                     const char *__restrict __modes, FILE *__restrict __stream);
/* Create a new stream that refers to an existing system file descriptor.  */
extern FILE *fdopen(int __fd, const char *__modes) __attribute__((__nothrow__));
/* Create a new stream that refers to a memory buffer.  */
extern FILE *fmemopen(void *__s, size_t __len, const char *__modes)
    __attribute__((__nothrow__));

/* Open a stream that writes into a malloc'd buffer that is expanded as
   necessary.  *BUFLOC and *SIZELOC are updated with the buffer's location
   and the number of characters written on fflush or fclose.  */
extern FILE *open_memstream(char **__bufloc, size_t *__sizeloc)
    __attribute__((__nothrow__));

/* If BUF is NULL, make STREAM unbuffered.
   Else make it use buffer BUF, of size BUFSIZ.  */
extern void setbuf(FILE *__restrict __stream, char *__restrict __buf)
    __attribute__((__nothrow__));
/* Make STREAM use buffering mode MODE.
   If BUF is not NULL, use N bytes of it for buffering;
   else allocate an internal buffer N bytes long.  */
extern int setvbuf(FILE *__restrict __stream, char *__restrict __buf,
                   int __modes, size_t __n) __attribute__((__nothrow__));

/* If BUF is NULL, make STREAM unbuffered.
   Else make it use SIZE bytes of BUF for buffering.  */
extern void setbuffer(FILE *__restrict __stream, char *__restrict __buf,
                      size_t __size) __attribute__((__nothrow__));

/* Make STREAM line-buffered.  */
extern void setlinebuf(FILE *__stream) __attribute__((__nothrow__));

/* Write formatted output to STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fprintf(FILE *__restrict __stream, const char *__restrict __format,
                   ...);
/* Write formatted output to stdout.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int printf(const char *__restrict __format, ...);
/* Write formatted output to S.  */
extern int sprintf(char *__restrict __s, const char *__restrict __format, ...)
    __attribute__((__nothrow__));

/* Write formatted output to S from argument list ARG.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int vfprintf(FILE *__restrict __s, const char *__restrict __format,
                    __gnuc_va_list __arg);
/* Write formatted output to stdout from argument list ARG.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int vprintf(const char *__restrict __format, __gnuc_va_list __arg);
/* Write formatted output to S from argument list ARG.  */
extern int vsprintf(char *__restrict __s, const char *__restrict __format,
                    __gnuc_va_list __arg) __attribute__((__nothrow__));

/* Maximum chars of output to write in MAXLEN.  */
extern int snprintf(char *__restrict __s, size_t __maxlen,
                    const char *__restrict __format, ...)
    __attribute__((__nothrow__)) __attribute__((__format__(__printf__, 3, 4)));

extern int vsnprintf(char *__restrict __s, size_t __maxlen,
                     const char *__restrict __format, __gnuc_va_list __arg)
    __attribute__((__nothrow__)) __attribute__((__format__(__printf__, 3, 0)));
/* Write formatted output to a file descriptor.  */
extern int vdprintf(int __fd, const char *__restrict __fmt,
                    __gnuc_va_list __arg)
    __attribute__((__format__(__printf__, 2, 0)));
extern int dprintf(int __fd, const char *__restrict __fmt, ...)
    __attribute__((__format__(__printf__, 2, 3)));

/* Read formatted input from STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fscanf(FILE *__restrict __stream, const char *__restrict __format,
                  ...);
/* Read formatted input from stdin.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int scanf(const char *__restrict __format, ...);
/* Read formatted input from S.  */
extern int sscanf(const char *__restrict __s, const char *__restrict __format,
                  ...) __attribute__((__nothrow__));

/* For strict ISO C99 or POSIX compliance disallow %as, %aS and %a[
   GNU extension which conflicts with valid %a followed by letter
   s, S or [.  */
extern int
fscanf(FILE *__restrict __stream, const char *__restrict __format, ...) __asm__(
    ""
    "__isoc99_fscanf");

extern int scanf(const char *__restrict __format, ...) __asm__(
    ""
    "__isoc99_scanf");

extern int
sscanf(const char *__restrict __s, const char *__restrict __format, ...) __asm__(
    ""
    "__isoc99_sscanf") __attribute__((__nothrow__));
/* Read formatted input from S into argument list ARG.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int vfscanf(FILE *__restrict __s, const char *__restrict __format,
                   __gnuc_va_list __arg)
    __attribute__((__format__(__scanf__, 2, 0)));

/* Read formatted input from stdin into argument list ARG.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int vscanf(const char *__restrict __format, __gnuc_va_list __arg)
    __attribute__((__format__(__scanf__, 1, 0)));

/* Read formatted input from S into argument list ARG.  */
extern int vsscanf(const char *__restrict __s, const char *__restrict __format,
                   __gnuc_va_list __arg) __attribute__((__nothrow__))
__attribute__((__format__(__scanf__, 2, 0)));

/* For strict ISO C99 or POSIX compliance disallow %as, %aS and %a[
   GNU extension which conflicts with valid %a followed by letter
   s, S or [.  */
extern int
vfscanf(FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__(
    ""
    "__isoc99_vfscanf")

    __attribute__((__format__(__scanf__, 2, 0)));
extern int
vscanf(const char *__restrict __format, __gnuc_va_list __arg) __asm__(
    ""
    "__isoc99_vscanf")

    __attribute__((__format__(__scanf__, 1, 0)));
extern int
vsscanf(const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__(
    ""
    "__isoc99_vsscanf") __attribute__((__nothrow__))

__attribute__((__format__(__scanf__, 2, 0)));
/* Read a character from STREAM.

   These functions are possible cancellation points and therefore not
   marked with __THROW.  */
extern int fgetc(FILE *__stream);
extern int getc(FILE *__stream);

/* Read a character from stdin.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int getchar(void);

/* The C standard explicitly says this is a macro, so we always do the
   optimization for it.  */

/* These are defined in POSIX.1:1996.

   These functions are possible cancellation points and therefore not
   marked with __THROW.  */
extern int getc_unlocked(FILE *__stream);
extern int getchar_unlocked(void);

/* Faster version when locking is not necessary.

   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern int fgetc_unlocked(FILE *__stream);

/* Write a character to STREAM.

   These functions are possible cancellation points and therefore not
   marked with __THROW.

   These functions is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fputc(int __c, FILE *__stream);
extern int putc(int __c, FILE *__stream);

/* Write a character to stdout.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int putchar(int __c);

/* The C standard explicitly says this can be a macro,
   so we always do the optimization for it.  */

/* Faster version when locking is not necessary.

   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern int fputc_unlocked(int __c, FILE *__stream);

/* These are defined in POSIX.1:1996.

   These functions are possible cancellation points and therefore not
   marked with __THROW.  */
extern int putc_unlocked(int __c, FILE *__stream);
extern int putchar_unlocked(int __c);

/* Get a word (int) from STREAM.  */
extern int getw(FILE *__stream);

/* Write a word (int) to STREAM.  */
extern int putw(int __w, FILE *__stream);

/* Get a newline-terminated string of finite length from STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern char *fgets(char *__restrict __s, int __n, FILE *__restrict __stream);
/* Read up to (and including) a DELIMITER from STREAM into *LINEPTR
   (and null-terminate it). *LINEPTR is a pointer returned from malloc (or
   NULL), pointing to *N characters of space.  It is realloc'd as
   necessary.  Returns the number of characters read (not including the
   null terminator), or -1 on error or EOF.

   These functions are not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation they are cancellation points and
   therefore not marked with __THROW.  */
extern __ssize_t __getdelim(char **__restrict __lineptr, size_t *__restrict __n,
                            int __delimiter, FILE *__restrict __stream);
extern __ssize_t getdelim(char **__restrict __lineptr, size_t *__restrict __n,
                          int __delimiter, FILE *__restrict __stream);

/* Like `getdelim', but reads up to a newline.

   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern __ssize_t getline(char **__restrict __lineptr, size_t *__restrict __n,
                         FILE *__restrict __stream);

/* Write a string to STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fputs(const char *__restrict __s, FILE *__restrict __stream);

/* Write a string, followed by a newline, to stdout.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int puts(const char *__s);

/* Push a character back onto the input buffer of STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int ungetc(int __c, FILE *__stream);

/* Read chunks of generic data from STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern size_t fread(void *__restrict __ptr, size_t __size, size_t __n,
                    FILE *__restrict __stream);
/* Write chunks of generic data to STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern size_t fwrite(const void *__restrict __ptr, size_t __size, size_t __n,
                     FILE *__restrict __s);
/* Faster versions when locking is not necessary.

   These functions are not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation they are cancellation points and
   therefore not marked with __THROW.  */
extern size_t fread_unlocked(void *__restrict __ptr, size_t __size, size_t __n,
                             FILE *__restrict __stream);
extern size_t fwrite_unlocked(const void *__restrict __ptr, size_t __size,
                              size_t __n, FILE *__restrict __stream);

/* Seek to a certain position on STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fseek(FILE *__stream, long int __off, int __whence);
/* Return the current position of STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern long int ftell(FILE *__stream);
/* Rewind to the beginning of STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern void rewind(FILE *__stream);

/* The Single Unix Specification, Version 2, specifies an alternative,
   more adequate interface for the two functions above which deal with
   file offset.  `long int' is not the right type.  These definitions
   are originally defined in the Large File Support API.  */

/* Seek to a certain position on STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fseeko(FILE *__stream, __off_t __off, int __whence);
/* Return the current position of STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern __off_t ftello(FILE *__stream);
/* Get STREAM's position.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fgetpos(FILE *__restrict __stream, fpos_t *__restrict __pos);
/* Set STREAM's position.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fsetpos(FILE *__stream, const fpos_t *__pos);
/* Clear the error and EOF indicators for STREAM.  */
extern void clearerr(FILE *__stream) __attribute__((__nothrow__));
/* Return the EOF indicator for STREAM.  */
extern int feof(FILE *__stream) __attribute__((__nothrow__));
/* Return the error indicator for STREAM.  */
extern int ferror(FILE *__stream) __attribute__((__nothrow__));

/* Faster versions when locking is not required.  */
extern void clearerr_unlocked(FILE *__stream) __attribute__((__nothrow__));
extern int feof_unlocked(FILE *__stream) __attribute__((__nothrow__));
extern int ferror_unlocked(FILE *__stream) __attribute__((__nothrow__));

/* Print a message describing the meaning of the value of errno.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern void perror(const char *__s);

/* Provide the declarations for `sys_errlist' and `sys_nerr' if they
   are available on this system.  Even if available, these variables
   should not be used directly.  The `strerror' function provides
   all the necessary functionality.  */

/* Declare sys_errlist and sys_nerr, or don't.  Compatibility (do) version.
   Copyright (C) 2002-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* sys_errlist and sys_nerr are deprecated.  Use strerror instead.  */

extern int sys_nerr;
extern const char *const sys_errlist[];

/* Return the system file descriptor for STREAM.  */
extern int fileno(FILE *__stream) __attribute__((__nothrow__));

/* Faster version when locking is not required.  */
extern int fileno_unlocked(FILE *__stream) __attribute__((__nothrow__));

/* Create a new stream connected to a pipe running the given command.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern FILE *popen(const char *__command, const char *__modes);

/* Close a stream opened by popen and return the status of its child.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int pclose(FILE *__stream);

/* Return the name of the controlling terminal.  */
extern char *ctermid(char *__s) __attribute__((__nothrow__));
/* These are defined in POSIX.1:1996.  */

/* Acquire ownership of STREAM.  */
extern void flockfile(FILE *__stream) __attribute__((__nothrow__));

/* Try to acquire ownership of STREAM but do not block if it is not
   possible.  */
extern int ftrylockfile(FILE *__stream) __attribute__((__nothrow__));

/* Relinquish the ownership granted for STREAM.  */
extern void funlockfile(FILE *__stream) __attribute__((__nothrow__));
/* If we are compiling with optimizing read this file.  It contains
   several optimizing inline functions and macros.  */

/*
** $Id: lua.h,v 1.329 2015/11/13 17:18:42 roberto Exp $
** Lua - A Scripting Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
*/

/*===---- stddef.h - Basic type definitions --------------------------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */
/* Always define miscellaneous pieces when modules are available. */
/* __need_wint_t is intentionally not defined here. */

/* Always define ptrdiff_t when modules are available. */

typedef long int ptrdiff_t;
/* ISO9899:2011 7.20 (C11 Annex K): Define rsize_t if __STDC_WANT_LIB_EXT1__ is
 * enabled. */
/* Always define wchar_t when modules are available. */

typedef int wchar_t;
/*===---- __stddef_max_align_t.h - Definition of max_align_t for modules ---===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */
// Define 'max_align_t' to match the GCC definition.
typedef struct {
    long long __clang_max_align_nonce1
        __attribute__((__aligned__(__alignof__(long long))));
    long double __clang_max_align_nonce2
        __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;

/* Some C libraries expect to see a wint_t here. Others (notably MinGW) will use
__WINT_TYPE__ directly; accommodate both by requiring __need_wint_t */

/*
** $Id: luaconf.h,v 1.254 2015/10/21 18:17:40 roberto Exp $
** Configuration file for Lua
** See Copyright Notice in lua.h
*/

/*===---- limits.h - Standard header for integer sizes --------------------===*\
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
\*===----------------------------------------------------------------------===*/

/* The system's limits.h may, in turn, try to #include_next GCC's limits.h.
   Avert this #include_next madness. */

/* System headers include a number of constants from POSIX in <limits.h>.
   Include it if we're hosted. */

/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.10/5.2.4.2.1 Sizes of integer types	<limits.h>
 */

/* Maximum length of any multibyte character in any locale.
   We define this value here since the gcc header does not define
   the correct value.  */

/* If we are not using GNU CC we have to define all the symbols ourself.
   Otherwise use gcc's definitions (see below).  */
/* Get the compiler's limits.h, which defines almost all the ISO constants.

   We put this #include_next outside the double inclusion check because
   it should be possible to include this file more than once and still get
   the definitions from gcc's header.  */

/* The <limits.h> files in some gcc versions don't define LLONG_MIN,
   LLONG_MAX, and ULLONG_MAX.  Instead only the values gcc defined for
   ages are available.  */
/* POSIX adds things to <limits.h>.  */

/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	POSIX Standard: 2.9.2 Minimum Values	Added to <limits.h>
 *
 *	Never include this file directly; use <limits.h> instead.
 */

/* These are the standard-mandated minimum values.  */

/* Minimum number of operations in one list I/O call.  */

/* Minimal number of outstanding asynchronous I/O operations.  */

/* Maximum length of arguments to `execve', including environment.  */

/* Maximum simultaneous processes per real user ID.  */

/* Minimal number of timer expiration overruns.  */

/* Maximum length of a host name (not including the terminating null)
   as returned from the GETHOSTNAME function.  */

/* Maximum link count of a file.  */

/* Maximum length of login name.  */

/* Number of bytes in a terminal canonical input queue.  */

/* Number of bytes for which space will be
   available in a terminal input queue.  */

/* Maximum number of message queues open for a process.  */

/* Maximum number of supported message priorities.  */

/* Number of bytes in a filename.  */

/* Number of simultaneous supplementary group IDs per process.  */

/* Number of files one process can have open at once.  */
/* Number of bytes in a pathname.  */

/* Number of bytes than can be written atomically to a pipe.  */

/* The number of repeated occurrences of a BRE permitted by the
   REGEXEC and REGCOMP functions when using the interval notation.  */

/* Minimal number of realtime signals reserved for the application.  */

/* Number of semaphores a process can have.  */

/* Maximal value of a semaphore.  */

/* Number of pending realtime signals.  */

/* Largest value of a `ssize_t'.  */

/* Number of streams a process can have open at once.  */

/* The number of bytes in a symbolic link.  */

/* The number of symbolic links that can be traversed in the
   resolution of a pathname in the absence of a loop.  */

/* Number of timer for a process.  */

/* Maximum number of characters in a tty name.  */

/* Maximum length of a timezone name (element of `tzname').  */
/* Maximum clock resolution in nanoseconds.  */

/* Get the implementation-specific values for the above.  */

/* Minimum guaranteed maximum values for system limits.  Linux version.
   Copyright (C) 1993-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation; either version 2.1 of the
   License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; see the file COPYING.LIB.  If
   not, see <http://www.gnu.org/licenses/>.  */

/* The kernel header pollutes the namespace with the NR_OPEN symbol
   and defines LINK_MAX although filesystems have different maxima.  A
   similar thing is true for OPEN_MAX: the limit can be changed at
   runtime and therefore the macro must not be defined.  Remove this
   after including the header if necessary.  */
/* The kernel sources contain a file with all the needed information.  */

/* Have to remove NR_OPEN?  */

/* Have to remove LINK_MAX?  */

/* Have to remove OPEN_MAX?  */

/* Have to remove ARG_MAX?  */

/* The number of data keys per process.  */

/* This is the value this implementation supports.  */

/* Controlling the iterations of destructors for thread-specific data.  */

/* Number of iterations this implementation does.  */

/* The number of threads per process.  */

/* We have no predefined limit on the number of threads.  */

/* Maximum amount by which a process can descrease its asynchronous I/O
   priority level.  */

/* Minimum size for a thread.  We are free to choose a reasonable value.  */

/* Maximum number of timer expiration overruns.  */

/* Maximum tty name length.  */

/* Maximum login name length.  This is arbitrary.  */

/* Maximum host name length.  */

/* Maximum message queue priority level.  */

/* Maximum value the semaphore can have.  */

/* This value is a guaranteed minimum maximum.
   The current maximum can be got from `sysconf'.  */

/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; include <limits.h> instead.
 */

/* The maximum `ibase' and `obase' values allowed by the `bc' utility.  */

/* The maximum number of elements allowed in an array by the `bc' utility.  */

/* The maximum `scale' value allowed by the `bc' utility.  */

/* The maximum length of a string constant accepted by the `bc' utility.  */

/* The maximum number of weights that can be assigned to an entry of
   the LC_COLLATE `order' keyword in the locale definition file.  */

/* The maximum number of expressions that can be nested
   within parentheses by the `expr' utility.  */

/* The maximum length, in bytes, of an input line.  */

/* The maximum number of repeated occurrences of a regular expression
   permitted when using the interval notation `\{M,N\}'.  */

/* The maximum number of bytes in a character class name.  We have no
   fixed limit, 2048 is a high number.  */

/* These values are implementation-specific,
   and may vary within the implementation.
   Their precise values can be obtained from sysconf.  */
/* This value is defined like this in regex.h.  */

/* Many system headers try to "help us out" by defining these.  No really, we
   know how big each datatype is. */
/* C90/99 5.2.4.2.1 */
/* C99 5.2.4.2.1: Added long long.
   C++11 18.3.3.2: same contents as the Standard C Library header <limits.h>.
 */
/* LONG_LONG_MIN/LONG_LONG_MAX/ULONG_LONG_MAX are a GNU extension.  It's too bad
   that we don't have something like #pragma poison that could be used to
   deprecate a macro - the code should just use LLONG_MAX and friends.
 */
/*===---- stddef.h - Basic type definitions --------------------------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

/*
** ===================================================================
** Search for "@@" to find all configurable definitions.
** ===================================================================
*/

/*
** {====================================================================
** System Configuration: macros to adapt (if needed) Lua to some
** particular platform, for instance compiling it with 32-bit numbers or
** restricting it to C89.
** =====================================================================
*/

/*
@@ LUA_32BITS enables Lua with 32-bit integers and 32-bit floats. You
** can also define LUA_32BITS in the make file, but changing here you
** ensure that all software connected to Lua will be compiled with the
** same configuration.
*/
/* #undef LUA_32BITS */

/*
@@ LUA_USE_C89 controls the use of non-ISO-C89 features.
** Define it if you want Lua to avoid the use of a few C99 features
** or Windows-specific features on Windows.
*/
/* #undef LUA_USE_C89 */

/*
** By default, Lua on Windows use (some) specific Windows features
*/
/* #undef LUA_USE_WINDOWS */

/* #undef LUA_DL_DLL */

/*
@@ LUA_C89_NUMBERS ensures that Lua uses the largest types available for
** C89 ('long' and 'double'); Windows always has '__int64', so it does
** not need to use this case.
*/

/*
@@ LUAI_BITSINT defines the (minimum) number of bits in an 'int'.
*/
/* avoid undefined shifts */
/*
@@ LUA_INT_TYPE defines the type for Lua integers.
@@ LUA_FLOAT_TYPE defines the type for Lua floats.
** Lua should work fine with any mix of these options (if supported
** by your C compiler). The usual configurations are 64-bit integers
** and 'double' (the default), 32-bit integers and 'float' (for
** restricted platforms), and 'long'/'double' (for C compilers not
** compliant with C99, which may not have support for 'long long').
*/

/* predefined options for LUA_INT_TYPE */

/* predefined options for LUA_FLOAT_TYPE */
/*
** default configuration for 64-bit Lua ('long long' and 'double')
*/
/* }================================================================== */

/*
** {==================================================================
** Configuration for Paths.
** ===================================================================
*/

/*
@@ LUA_PATH_DEFAULT is the default path that Lua uses to look for
** Lua libraries.
@@ LUA_CPATH_DEFAULT is the default path that Lua uses to look for
** C libraries.
** CHANGE them if your machine has a non-conventional directory
** hierarchy or if you want to install your libraries in
** non-conventional directories.
*/

/* #undef LUA_LDIR */
/* #undef LUA_CDIR */

/*
@@ LUA_DIRSEP is the directory separator (for submodules).
** CHANGE it if your machine does not use "/" as the directory separator
** and is not Windows. (On Windows Lua automatically uses "\".)
*/

/* }================================================================== */

/*
** {==================================================================
** Marks for exported symbols in the C code
** ===================================================================
*/

/*
@@ LUA_API is a mark for all core API functions.
@@ LUALIB_API is a mark for all auxiliary library functions.
@@ LUAMOD_API is a mark for all standard library opening functions.
** CHANGE them if you need to define those functions in some special way.
** For instance, if you want to create one Windows DLL with the core and
** the libraries, you may want to use the following definition (define
** LUA_BUILD_AS_DLL to get it).
*/
/* more often than not the libs go together with the core */

/*
@@ LUAI_FUNC is a mark for all extern functions that are not to be
** exported to outside modules.
@@ LUAI_DDEF and LUAI_DDEC are marks for all extern (const) variables
** that are not to be exported to outside modules (LUAI_DDEF for
** definitions and LUAI_DDEC for declarations).
** CHANGE them if you need to mark them in some special way. Elf/gcc
** (versions 3.2 and later) mark them as "hidden" to optimize access
** when Lua is compiled as a shared library. Not all elf targets support
** this attribute. Unfortunately, gcc does not offer a way to check
** whether the target offers that support, and those without support
** give a warning about it. To avoid these warnings, change to the
** default definition.
*/
/* }================================================================== */

/*
** {==================================================================
** Compatibility with previous versions
** ===================================================================
*/

/*
@@ LUA_COMPAT_5_2 controls other macros for compatibility with Lua 5.2.
@@ LUA_COMPAT_5_1 controls other macros for compatibility with Lua 5.1.
** You can define it to get all options, or change specific options
** to fit your specific needs.
*/

/*
@@ LUA_COMPAT_MATHLIB controls the presence of several deprecated
** functions in the mathematical library.
*/

/*
@@ LUA_COMPAT_BITLIB controls the presence of library 'bit32'.
*/

/*
@@ LUA_COMPAT_IPAIRS controls the effectiveness of the __ipairs metamethod.
*/

/*
@@ LUA_COMPAT_APIINTCASTS controls the presence of macros for
** manipulating other integer types (lua_pushunsigned, lua_tounsigned,
** luaL_checkint, luaL_checklong, etc.)
*/

/* Incompatibilities from 5.2 -> 5.3 */

/*
@@ LUA_COMPAT_UNPACK controls the presence of global 'unpack'.
** You can replace it with 'table.unpack'.
*/

/*
@@ LUA_COMPAT_LOADERS controls the presence of table 'package.loaders'.
** You can replace it with 'package.searchers'.
*/

/*
@@ macro 'lua_cpcall' emulates deprecated function lua_cpcall.
** You can call your C function directly (with light C functions).
*/

/*
@@ LUA_COMPAT_LOG10 defines the function 'log10' in the math library.
** You can rewrite 'log10(x)' as 'log(x, 10)'.
*/

/*
@@ LUA_COMPAT_LOADSTRING defines the function 'loadstring' in the base
** library. You can rewrite 'loadstring(s)' as 'load(s)'.
*/

/*
@@ LUA_COMPAT_MAXN defines the function 'maxn' in the table library.
*/

/*
@@ The following macros supply trivial compatibility for some
** changes in the API. The macros themselves document how to
** change your code to avoid using them.
*/

/*
@@ LUA_COMPAT_MODULE controls compatibility with previous
** module functions 'module' (Lua) and 'luaL_register' (C).
*/

/*
@@ LUA_COMPAT_FLOATSTRING makes Lua format integral floats without a
@@ a float mark ('.0').
** This macro is not on by default even in compatibility mode,
** because this is not really an incompatibility.
*/
/* #define LUA_COMPAT_FLOATSTRING */

/* }================================================================== */

/*
** {==================================================================
** Configuration for Numbers.
** Change these definitions if no predefined LUA_FLOAT_* / LUA_INT_*
** satisfy your needs.
** ===================================================================
*/

/*
@@ LUA_NUMBER is the floating-point type used by Lua.
@@ LUAI_UACNUMBER is the result of an 'usual argument conversion'
@@ over a floating number.
@@ l_mathlim(x) corrects limit name 'x' to the proper float type
** by prefixing it with one of FLT/DBL/LDBL.
@@ LUA_NUMBER_FRMLEN is the length modifier for writing floats.
@@ LUA_NUMBER_FMT is the format for writing floats.
@@ lua_number2str converts a float to a string.
@@ l_mathop allows the addition of an 'l' or 'f' to all math operations.
@@ l_floor takes the floor of a float.
@@ lua_str2number converts a decimal numeric string to a number.
*/

/* The following definitions are good for most cases here */

/*
@@ lua_numbertointeger converts a float number to an integer, or
** returns 0 if float is not within the range of a lua_Integer.
** (The range comparisons are tricky because of rounding. The tests
** here assume a two-complement representation, where MININTEGER always
** has an exact representation as a float; MAXINTEGER may not have one,
** and therefore its conversion to float may have an ill-defined value.)
*/

/* now the variable definitions */
/*
@@ LUA_INTEGER is the integer type used by Lua.
**
@@ LUA_UNSIGNED is the unsigned version of LUA_INTEGER.
**
@@ LUAI_UACINT is the result of an 'usual argument conversion'
@@ over a lUA_INTEGER.
@@ LUA_INTEGER_FRMLEN is the length modifier for reading/writing integers.
@@ LUA_INTEGER_FMT is the format for writing integers.
@@ LUA_MAXINTEGER is the maximum value for a LUA_INTEGER.
@@ LUA_MININTEGER is the minimum value for a LUA_INTEGER.
@@ lua_integer2str converts an integer to a string.
*/

/* The following definitions are good for most cases here */

/*
** use LUAI_UACINT here to avoid problems with promotions (which
** can turn a comparison between unsigneds into a signed comparison)
*/

/* now the variable definitions */
/* use presence of macro LLONG_MAX as proxy for C99 compliance */

/* use ISO C99 stuff */
/* }================================================================== */

/*
** {==================================================================
** Dependencies with C99 and other C details
** ===================================================================
*/

/*
@@ l_sprintf is equivalent to 'snprintf' or 'sprintf' in C89.
** (All uses in Lua have only one format item.)
*/

/*
@@ lua_strx2number converts an hexadecimal numeric string to a number.
** In C99, 'strtod' does that conversion. Otherwise, you can
** leave 'lua_strx2number' undefined and Lua will provide its own
** implementation.
*/

/*
@@ lua_number2strx converts a float to an hexadecimal numeric string.
** In C99, 'sprintf' (with format specifiers '%a'/'%A') does that.
** Otherwise, you can leave 'lua_number2strx' undefined and Lua will
** provide its own implementation.
*/

/*
** 'strtof' and 'opf' variants for math functions are not valid in
** C89. Otherwise, the macro 'HUGE_VALF' is a good proxy for testing the
** availability of these variants. ('math.h' is already included in
** all files that use these macros.)
*/
/*
@@ LUA_KCONTEXT is the type of the context ('ctx') for continuation
** functions.  It must be a numerical type; Lua will use 'intptr_t' if
** available, otherwise it will use 'ptrdiff_t' (the nearest thing to
** 'intptr_t' in C89)
*/

/*===---- stdint.h - Standard header for sized integer types --------------===*\
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
\*===----------------------------------------------------------------------===*/

// AIX system headers need stdint.h to be re-enterable while _STD_TYPES_T
// is defined until an inclusion of it without _STD_TYPES_T occurs, in which
// case the header guard macro is defined.

/* If we're hosted, fall back to the system's stdint.h, which might have
 * additional definitions.
 */

// C99 7.18.3 Limits of other integer types
//
//  Footnote 219, 220: C++ implementations should define these macros only when
//  __STDC_LIMIT_MACROS is defined before <stdint.h> is included.
//
//  Footnote 222: C++ implementations should define these macros only when
//  __STDC_CONSTANT_MACROS is defined before <stdint.h> is included.
//
// C++11 [cstdint.syn]p2:
//
//  The macros defined by <cstdint> are provided unconditionally. In particular,
//  the symbols __STDC_LIMIT_MACROS and __STDC_CONSTANT_MACROS (mentioned in
//  footnotes 219, 220, and 222 in the C standard) play no role in C++.
//
// C11 removed the problematic footnotes.
//
// Work around this inconsistency by always defining those macros in C++ mode,
// so that a C library implementation which follows the C99 standard can be
// used in C++.
/* Copyright (C) 1997-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	ISO C99: 7.18 Integer types <stdint.h>
 */

/* wchar_t type related definitions.
   Copyright (C) 2000-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* The fallback definitions, for when __WCHAR_MAX__ or __WCHAR_MIN__
   are not defined, give the right value and type as long as both int
   and wchar_t are 32-bit types.  Adding L'\0' to a constant value
   ensures that the type is correct; it is necessary to use (L'\0' +
   0) rather than just L'\0' so that the type in C++ is the promoted
   version of wchar_t rather than the distinct wchar_t type itself.
   Because wchar_t in preprocessor #if expressions is treated as
   intmax_t or uintmax_t, the expression (L'\0' - 1) would have the
   wrong value for WCHAR_MAX in such expressions and so cannot be used
   to define __WCHAR_MAX in the unsigned case.  */
/* Determine the wordsize from the preprocessor defines.  */
/* Both x86-64 and x32 use the 64-bit system call interface.  */

/* Exact integral types.  */

/* Signed.  */

/* There is some amount of overlap with <sys/types.h> as known by inet code */

typedef signed char int8_t;
typedef short int int16_t;
typedef int int32_t;

typedef long int int64_t;

/* Unsigned.  */
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

typedef unsigned int uint32_t;

typedef unsigned long int uint64_t;

/* Small types.  */

/* Signed.  */
typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;

typedef long int int_least64_t;

/* Unsigned.  */
typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;

typedef unsigned long int uint_least64_t;

/* Fast types.  */

/* Signed.  */
typedef signed char int_fast8_t;

typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;

/* Unsigned.  */
typedef unsigned char uint_fast8_t;

typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
/* Types for `void *' pointers.  */

typedef long int intptr_t;

typedef unsigned long int uintptr_t;
/* Largest integral types.  */

typedef long int intmax_t;
typedef unsigned long int uintmax_t;
/* Limits of integral types.  */

/* Minimum of signed integral types.  */

/* Maximum of signed integral types.  */

/* Maximum of unsigned integral types.  */

/* Minimum of signed integral types having a minimum size.  */

/* Maximum of signed integral types having a minimum size.  */

/* Maximum of unsigned integral types having a minimum size.  */

/* Minimum of fast signed integral types having a minimum size.  */
/* Maximum of fast signed integral types having a minimum size.  */
/* Maximum of fast unsigned integral types having a minimum size.  */
/* Values to test for integral types holding `void *' pointer.  */
/* Minimum for largest signed integral type.  */

/* Maximum for largest signed integral type.  */

/* Maximum for largest unsigned integral type.  */

/* Limits of other integer types.  */

/* Limits of `ptrdiff_t' type.  */
/* Limits of `sig_atomic_t'.  */

/* Limit of `size_t' type.  */
/* Limits of `wchar_t'.  */

/* These constants might also be defined in <wchar.h>.  */

/* Limits of `wint_t'.  */

/* Signed.  */
/* Unsigned.  */
/* Maximal type.  */

/*
@@ lua_getlocaledecpoint gets the locale "radix character" (decimal point).
** Change that if you do not want to use C locales. (Code using this
** macro must include header 'locale.h'.)
*/

/* }================================================================== */

/*
** {==================================================================
** Language Variations
** =====================================================================
*/

/*
@@ LUA_NOCVTN2S/LUA_NOCVTS2N control how Lua performs some
** coercions. Define LUA_NOCVTN2S to turn off automatic coercion from
** numbers to strings. Define LUA_NOCVTS2N to turn off automatic
** coercion from strings to numbers.
*/
/* #define LUA_NOCVTN2S */
/* #define LUA_NOCVTS2N */

/*
@@ LUA_USE_APICHECK turns on several consistency checks on the C API.
** Define it as a help when debugging C code.
*/

/* }================================================================== */

/*
** {==================================================================
** Macros that affect the API and must be stable (that is, must be the
** same when you compile Lua and when you compile code that links to
** Lua). You probably do not want/need to change them.
** =====================================================================
*/

/*
@@ LUAI_MAXSTACK limits the size of the Lua stack.
** CHANGE it if you need a different limit. This limit is arbitrary;
** its only purpose is to stop Lua from consuming unlimited stack
** space (and to reserve some numbers for pseudo-indices).
*/

/*
@@ LUA_EXTRASPACE defines the size of a raw memory area associated with
** a Lua state with very fast access.
** CHANGE it if you need a different size.
*/

/*
@@ LUA_IDSIZE gives the maximum size for the description of the source
@@ of a function in debug information.
** CHANGE it if you want a different size.
*/

/*
@@ LUAL_BUFFERSIZE is the buffer size used by the lauxlib buffer system.
** CHANGE it if it uses too much C-stack space. (For long double,
** 'string.format("%.99f", 1e4932)' needs ~5030 bytes, so a
** smaller buffer would force a memory allocation for each call to
** 'string.format'.)
*/

/* }================================================================== */

/*
@@ LUA_QL describes how error messages quote program elements.
** Lua does not use these macros anymore; they are here for
** compatibility only.
*/

/* =================================================================== */

/*
** Local configuration. You can use this space to add your redefinitions
** without modifying the main part of the file.
*/
/* mark for precompiled code ('<esc>Lua') */

/* option for multiple returns in 'lua_pcall' and 'lua_call' */

/*
** Pseudo-indices
** (-LUAI_MAXSTACK is the minimum valid index; we keep some free empty
** space after that to help overflow detection)
*/

/* thread status */
typedef struct lua_State lua_State;

/*
** basic types
*/
/* minimum Lua stack available to a C function */

/* predefined values in the registry */

/* type of numbers in Lua */
typedef double lua_Number;

/* type for integer functions */
typedef long long lua_Integer;

/* unsigned integer type */
typedef unsigned long long lua_Unsigned;

/* type for continuation-function contexts */
typedef intptr_t lua_KContext;

/*
** Type for C functions registered with Lua
*/
typedef int (*lua_CFunction)(lua_State *L);

/*
** Type for continuation functions
*/
typedef int (*lua_KFunction)(lua_State *L, int status, lua_KContext ctx);

/*
** Type for functions that read/write blocks when loading/dumping Lua chunks
*/
typedef const char *(*lua_Reader)(lua_State *L, void *ud, size_t *sz);

typedef int (*lua_Writer)(lua_State *L, const void *p, size_t sz, void *ud);

/*
** Type for memory-allocation functions
*/
typedef void *(*lua_Alloc)(void *ud, void *ptr, size_t osize, size_t nsize);

/*
** generic extra include file
*/

/*
** RCS ident string
*/
extern const char lua_ident[];

/*
** state manipulation
*/
extern lua_State *(lua_newstate)(lua_Alloc f, void *ud);
extern void(lua_close)(lua_State *L);
extern lua_State *(lua_newthread)(lua_State *L);

extern lua_CFunction(lua_atpanic)(lua_State *L, lua_CFunction panicf);

extern const lua_Number *(lua_version)(lua_State *L);

/*
** basic stack manipulation
*/
extern int(lua_absindex)(lua_State *L, int idx);
extern int(lua_gettop)(lua_State *L);
extern void(lua_settop)(lua_State *L, int idx);
extern void(lua_pushvalue)(lua_State *L, int idx);
extern void(lua_rotate)(lua_State *L, int idx, int n);
extern void(lua_copy)(lua_State *L, int fromidx, int toidx);
extern int(lua_checkstack)(lua_State *L, int n);

extern void(lua_xmove)(lua_State *from, lua_State *to, int n);

/*
** access functions (stack -> C)
*/

extern int(lua_isnumber)(lua_State *L, int idx);
extern int(lua_isstring)(lua_State *L, int idx);
extern int(lua_iscfunction)(lua_State *L, int idx);
extern int(lua_isinteger)(lua_State *L, int idx);
extern int(lua_isuserdata)(lua_State *L, int idx);
extern int(lua_type)(lua_State *L, int idx);
extern const char *(lua_typename)(lua_State *L, int tp);

extern lua_Number(lua_tonumberx)(lua_State *L, int idx, int *isnum);
extern lua_Integer(lua_tointegerx)(lua_State *L, int idx, int *isnum);
extern int(lua_toboolean)(lua_State *L, int idx);
extern const char *(lua_tolstring)(lua_State *L, int idx, size_t *len);
extern size_t(lua_rawlen)(lua_State *L, int idx);
extern lua_CFunction(lua_tocfunction)(lua_State *L, int idx);
extern void *(lua_touserdata)(lua_State *L, int idx);
extern lua_State *(lua_tothread)(lua_State *L, int idx);
extern const void *(lua_topointer)(lua_State *L, int idx);

/*
** Comparison and arithmetic functions
*/
extern void(lua_arith)(lua_State *L, int op);

extern int(lua_rawequal)(lua_State *L, int idx1, int idx2);
extern int(lua_compare)(lua_State *L, int idx1, int idx2, int op);

/*
** push functions (C -> stack)
*/
extern void(lua_pushnil)(lua_State *L);
extern void(lua_pushnumber)(lua_State *L, lua_Number n);
extern void(lua_pushinteger)(lua_State *L, lua_Integer n);
extern const char *(lua_pushlstring)(lua_State *L, const char *s, size_t len);
extern const char *(lua_pushstring)(lua_State *L, const char *s);
extern const char *(lua_pushvfstring)(lua_State *L, const char *fmt,
                                      va_list argp);
extern const char *(lua_pushfstring)(lua_State *L, const char *fmt, ...);
extern void(lua_pushcclosure)(lua_State *L, lua_CFunction fn, int n);
extern void(lua_pushboolean)(lua_State *L, int b);
extern void(lua_pushlightuserdata)(lua_State *L, void *p);
extern int(lua_pushthread)(lua_State *L);

/*
** get functions (Lua -> stack)
*/
extern int(lua_getglobal)(lua_State *L, const char *name);
extern int(lua_gettable)(lua_State *L, int idx);
extern int(lua_getfield)(lua_State *L, int idx, const char *k);
extern int(lua_geti)(lua_State *L, int idx, lua_Integer n);
extern int(lua_rawget)(lua_State *L, int idx);
extern int(lua_rawgeti)(lua_State *L, int idx, lua_Integer n);
extern int(lua_rawgetp)(lua_State *L, int idx, const void *p);

extern void(lua_createtable)(lua_State *L, int narr, int nrec);
extern void *(lua_newuserdata)(lua_State *L, size_t sz);
extern int(lua_getmetatable)(lua_State *L, int objindex);
extern int(lua_getuservalue)(lua_State *L, int idx);

/*
** set functions (stack -> Lua)
*/
extern void(lua_setglobal)(lua_State *L, const char *name);
extern void(lua_settable)(lua_State *L, int idx);
extern void(lua_setfield)(lua_State *L, int idx, const char *k);
extern void(lua_seti)(lua_State *L, int idx, lua_Integer n);
extern void(lua_rawset)(lua_State *L, int idx);
extern void(lua_rawseti)(lua_State *L, int idx, lua_Integer n);
extern void(lua_rawsetp)(lua_State *L, int idx, const void *p);
extern int(lua_setmetatable)(lua_State *L, int objindex);
extern void(lua_setuservalue)(lua_State *L, int idx);

/*
** 'load' and 'call' functions (load and run Lua code)
*/
extern void(lua_callk)(lua_State *L, int nargs, int nresults, lua_KContext ctx,
                       lua_KFunction k);

extern int(lua_pcallk)(lua_State *L, int nargs, int nresults, int errfunc,
                       lua_KContext ctx, lua_KFunction k);

extern int(lua_load)(lua_State *L, lua_Reader reader, void *dt,
                     const char *chunkname, const char *mode);

extern int(lua_dump)(lua_State *L, lua_Writer writer, void *data, int strip);

/*
** coroutine functions
*/
extern int(lua_yieldk)(lua_State *L, int nresults, lua_KContext ctx,
                       lua_KFunction k);
extern int(lua_resume)(lua_State *L, lua_State *from, int narg);
extern int(lua_status)(lua_State *L);
extern int(lua_isyieldable)(lua_State *L);

/*
** garbage-collection function and options
*/
extern int(lua_gc)(lua_State *L, int what, int data);

/*
** miscellaneous functions
*/

extern int(lua_error)(lua_State *L);

extern int(lua_next)(lua_State *L, int idx);

extern void(lua_concat)(lua_State *L, int n);
extern void(lua_len)(lua_State *L, int idx);

extern size_t(lua_stringtonumber)(lua_State *L, const char *s);

extern lua_Alloc(lua_getallocf)(lua_State *L, void **ud);
extern void(lua_setallocf)(lua_State *L, lua_Alloc f, void *ud);

/*
** {==============================================================
** some useful macros
** ===============================================================
*/
/* }============================================================== */

/*
** {==============================================================
** compatibility macros for unsigned conversions
** ===============================================================
*/

/* }============================================================== */

/*
** {======================================================================
** Debug API
** =======================================================================
*/

/*
** Event codes
*/

/*
** Event masks
*/

typedef struct lua_Debug lua_Debug; /* activation record */

/* Functions to be called by the debugger in specific events */
typedef void (*lua_Hook)(lua_State *L, lua_Debug *ar);

extern int(lua_getstack)(lua_State *L, int level, lua_Debug *ar);
extern int(lua_getinfo)(lua_State *L, const char *what, lua_Debug *ar);
extern const char *(lua_getlocal)(lua_State *L, const lua_Debug *ar, int n);
extern const char *(lua_setlocal)(lua_State *L, const lua_Debug *ar, int n);
extern const char *(lua_getupvalue)(lua_State *L, int funcindex, int n);
extern const char *(lua_setupvalue)(lua_State *L, int funcindex, int n);

extern void *(lua_upvalueid)(lua_State *L, int fidx, int n);
extern void(lua_upvaluejoin)(lua_State *L, int fidx1, int n1, int fidx2,
                             int n2);

extern void(lua_sethook)(lua_State *L, lua_Hook func, int mask, int count);
extern lua_Hook(lua_gethook)(lua_State *L);
extern int(lua_gethookmask)(lua_State *L);
extern int(lua_gethookcount)(lua_State *L);

struct lua_Debug {
    int event;
    const char *name;      /* (n) */
    const char *namewhat;  /* (n) 'global', 'local', 'field', 'method' */
    const char *what;      /* (S) 'Lua', 'C', 'main', 'tail' */
    const char *source;    /* (S) */
    int currentline;       /* (l) */
    int linedefined;       /* (S) */
    int lastlinedefined;   /* (S) */
    unsigned char nups;    /* (u) number of upvalues */
    unsigned char nparams; /* (u) number of parameters */
    char isvararg;         /* (u) */
    char istailcall;       /* (t) */
    char short_src[60];    /* (S) */
    /* private part */
    struct CallInfo *i_ci; /* active function */
};

/* }====================================================================== */

/******************************************************************************
 * Copyright (C) 1994-2015 Lua.org, PUC-Rio.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 ******************************************************************************/
/*
** $Id: lauxlib.h,v 1.129 2015/11/23 11:29:43 roberto Exp $
** Auxiliary functions for building Lua libraries
** See Copyright Notice in lua.h
*/

/*===---- stddef.h - Basic type definitions --------------------------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

/* extra error code for 'luaL_load' */

typedef struct luaL_Reg {
    const char *name;
    lua_CFunction func;
} luaL_Reg;

extern void(luaL_checkversion_)(lua_State *L, lua_Number ver, size_t sz);

extern int(luaL_getmetafield)(lua_State *L, int obj, const char *e);
extern int(luaL_callmeta)(lua_State *L, int obj, const char *e);
extern const char *(luaL_tolstring)(lua_State *L, int idx, size_t *len);
extern int(luaL_argerror)(lua_State *L, int arg, const char *extramsg);
extern const char *(luaL_checklstring)(lua_State *L, int arg, size_t *l);
extern const char *(luaL_optlstring)(lua_State *L, int arg, const char *def,
                                     size_t *l);
extern lua_Number(luaL_checknumber)(lua_State *L, int arg);
extern lua_Number(luaL_optnumber)(lua_State *L, int arg, lua_Number def);

extern lua_Integer(luaL_checkinteger)(lua_State *L, int arg);
extern lua_Integer(luaL_optinteger)(lua_State *L, int arg, lua_Integer def);

extern void(luaL_checkstack)(lua_State *L, int sz, const char *msg);
extern void(luaL_checktype)(lua_State *L, int arg, int t);
extern void(luaL_checkany)(lua_State *L, int arg);

extern int(luaL_newmetatable)(lua_State *L, const char *tname);
extern void(luaL_setmetatable)(lua_State *L, const char *tname);
extern void *(luaL_testudata)(lua_State *L, int ud, const char *tname);
extern void *(luaL_checkudata)(lua_State *L, int ud, const char *tname);

extern void(luaL_where)(lua_State *L, int lvl);
extern int(luaL_error)(lua_State *L, const char *fmt, ...);

extern int(luaL_checkoption)(lua_State *L, int arg, const char *def,
                             const char *const lst[]);

extern int(luaL_fileresult)(lua_State *L, int stat, const char *fname);
extern int(luaL_execresult)(lua_State *L, int stat);

/* predefined references */

extern int(luaL_ref)(lua_State *L, int t);
extern void(luaL_unref)(lua_State *L, int t, int ref);

extern int(luaL_loadfilex)(lua_State *L, const char *filename,
                           const char *mode);

extern int(luaL_loadbufferx)(lua_State *L, const char *buff, size_t sz,
                             const char *name, const char *mode);
extern int(luaL_loadstring)(lua_State *L, const char *s);

extern lua_State *(luaL_newstate)(void);

extern lua_Integer(luaL_len)(lua_State *L, int idx);

extern const char *(luaL_gsub)(lua_State *L, const char *s, const char *p,
                               const char *r);

extern void(luaL_setfuncs)(lua_State *L, const luaL_Reg *l, int nup);

extern int(luaL_getsubtable)(lua_State *L, int idx, const char *fname);

extern void(luaL_traceback)(lua_State *L, lua_State *L1, const char *msg,
                            int level);

extern void(luaL_requiref)(lua_State *L, const char *modname,
                           lua_CFunction openf, int glb);

/*
** ===============================================================
** some useful macros
** ===============================================================
*/
/*
** {======================================================
** Generic Buffer manipulation
** =======================================================
*/

typedef struct luaL_Buffer {
    char *b;     /* buffer address */
    size_t size; /* buffer size */
    size_t n;    /* number of characters in buffer */
    lua_State *L;
    char initb[8192]; /* initial buffer */
} luaL_Buffer;
extern void(luaL_buffinit)(lua_State *L, luaL_Buffer *B);
extern char *(luaL_prepbuffsize)(luaL_Buffer *B, size_t sz);
extern void(luaL_addlstring)(luaL_Buffer *B, const char *s, size_t l);
extern void(luaL_addstring)(luaL_Buffer *B, const char *s);
extern void(luaL_addvalue)(luaL_Buffer *B);
extern void(luaL_pushresult)(luaL_Buffer *B);
extern void(luaL_pushresultsize)(luaL_Buffer *B, size_t sz);
extern char *(luaL_buffinitsize)(lua_State *L, luaL_Buffer *B, size_t sz);

/* }====================================================== */

/*
** {======================================================
** File handles for IO library
** =======================================================
*/

/*
** A file handle is a userdata with metatable 'LUA_FILEHANDLE' and
** initial structure 'luaL_Stream' (it may contain other fields
** after that initial structure).
*/

typedef struct luaL_Stream {
    FILE *f;              /* stream (NULL for incompletely created streams) */
    lua_CFunction closef; /* to close stream (NULL for closed streams) */
} luaL_Stream;

/* }====================================================== */

/* compatibility with old module system */

extern void(luaL_pushmodule)(lua_State *L, const char *modname, int sizehint);
extern void(luaL_openlib)(lua_State *L, const char *libname, const luaL_Reg *l,
                          int nup);

/*
** {==================================================================
** "Abstraction Layer" for basic report of messages and errors
** ===================================================================
*/

/* print a string */

/* print a newline and flush the output */

/* print an error message */

/* }================================================================== */

/*
** {============================================================
** Compatibility with deprecated conversions
** =============================================================
*/
/* }============================================================ */

/* for compatible with lua5.1 */
inline static void _add_unsigned_constant(lua_State *L, const char *name,
                                          unsigned int value) {
    lua_pushinteger(L, value);
    lua_setfield(L, -2, name);
}
/*
 * libev native API header
 *
 * Copyright (c) 2007,2008,2009,2010,2011,2012,2015 Marc Alexander Lehmann
 * <libev@schmorp.de> All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modifica-
 * tion, are permitted provided that the following conditions are met:
 *
 *   1.  Redistributions of source code must retain the above copyright notice,
 *       this list of conditions and the following disclaimer.
 *
 *   2.  Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MER-
 * CHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO
 * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPE-
 * CIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTH-
 * ERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Alternatively, the contents of this file may be used under the terms of
 * the GNU General Public License ("GPL") version 2 or any later version,
 * in which case the provisions of the GPL are applicable instead of
 * the above. If you wish to allow the use of your version of this file
 * only under the terms of the GPL and not to allow others to use your
 * version of this file under the BSD license, indicate your decision
 * by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL. If you do not delete the
 * provisions above, a recipient may use your version of this file under
 * either the BSD or the GPL.
 */
/*****************************************************************************/

/* pre-4.0 compatibility */
/* these priorities are inclusive, higher priorities will be invoked earlier */
/*****************************************************************************/

/*****************************************************************************/

typedef double ev_tstamp;

/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.21 String handling	<string.h>
 */
/* Get size_t and NULL from <stddef.h>.  */

/*===---- stddef.h - Basic type definitions --------------------------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */
/* Some C libraries expect to see a wint_t here. Others (notably MinGW) will use
__WINT_TYPE__ directly; accommodate both by requiring __need_wint_t */

/* Tell the caller that we provide correct C++ prototypes.  */

/* Copy N bytes of SRC to DEST.  */
extern void *memcpy(void *__restrict __dest, const void *__restrict __src,
                    size_t __n) __attribute__((__nothrow__))
__attribute__((__nonnull__(1, 2)));
/* Copy N bytes of SRC to DEST, guaranteeing
   correct behavior for overlapping strings.  */
extern void *memmove(void *__dest, const void *__src, size_t __n)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 2)));

/* Copy no more than N bytes of SRC to DEST, stopping when C is found.
   Return the position in DEST one byte past where C was copied,
   or NULL if C was not found in the first N bytes of SRC.  */

extern void *memccpy(void *__restrict __dest, const void *__restrict __src,
                     int __c, size_t __n) __attribute__((__nothrow__))
__attribute__((__nonnull__(1, 2)));

/* Set N bytes of S to C.  */
extern void *memset(void *__s, int __c, size_t __n) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));

/* Compare N bytes of S1 and S2.  */
extern int memcmp(const void *__s1, const void *__s2, size_t __n)
    __attribute__((__nothrow__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

/* Search N bytes of S for C.  */
extern void *memchr(const void *__s, int __c, size_t __n)
    __attribute__((__nothrow__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));
/* Copy SRC to DEST.  */
extern char *strcpy(char *__restrict __dest, const char *__restrict __src)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 2)));
/* Copy no more than N characters of SRC to DEST.  */
extern char *strncpy(char *__restrict __dest, const char *__restrict __src,
                     size_t __n) __attribute__((__nothrow__))
__attribute__((__nonnull__(1, 2)));

/* Append SRC onto DEST.  */
extern char *strcat(char *__restrict __dest, const char *__restrict __src)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 2)));
/* Append no more than N characters from SRC onto DEST.  */
extern char *strncat(char *__restrict __dest, const char *__restrict __src,
                     size_t __n) __attribute__((__nothrow__))
__attribute__((__nonnull__(1, 2)));

/* Compare S1 and S2.  */
extern int strcmp(const char *__s1, const char *__s2)
    __attribute__((__nothrow__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
/* Compare N characters of S1 and S2.  */
extern int strncmp(const char *__s1, const char *__s2, size_t __n)
    __attribute__((__nothrow__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

/* Compare the collated forms of S1 and S2.  */
extern int strcoll(const char *__s1, const char *__s2)
    __attribute__((__nothrow__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
/* Put a transformation of SRC into no more than N bytes of DEST.  */
extern size_t strxfrm(char *__restrict __dest, const char *__restrict __src,
                      size_t __n) __attribute__((__nothrow__))
__attribute__((__nonnull__(2)));

/* The following functions are equivalent to the both above but they
   take the locale they use for the collation as an extra argument.
   This is not standardsized but something like will come.  */

/* Definition of locale datatype.
   Copyright (C) 1997-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Ulrich Drepper <drepper@cygnus.com>, 1997.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* Structure for reentrant locale using functions.  This is an
   (almost) opaque type for the user level programs.  The file and
   this data structure is not standardized.  Don't rely on it.  It can
   go away without warning.  */
typedef struct __locale_struct {
    /* Note: LC_ALL is not a valid index into this array.  */
    struct __locale_data *__locales[13]; /* 13 = __LC_LAST. */

    /* To increase the speed of this solution we add some special members.  */
    const unsigned short int *__ctype_b;
    const int *__ctype_tolower;
    const int *__ctype_toupper;

    /* Note: LC_ALL is not a valid index into this array.  */
    const char *__names[13];
} * __locale_t;

/* POSIX 2008 makes locale_t official.  */
typedef __locale_t locale_t;

/* Compare the collated forms of S1 and S2 using rules from L.  */
extern int strcoll_l(const char *__s1, const char *__s2, __locale_t __l)
    __attribute__((__nothrow__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2, 3)));
/* Put a transformation of SRC into no more than N bytes of DEST.  */
extern size_t strxfrm_l(char *__dest, const char *__src, size_t __n,
                        __locale_t __l) __attribute__((__nothrow__))
__attribute__((__nonnull__(2, 4)));

/* Duplicate S, returning an identical malloc'd string.  */
extern char *strdup(const char *__s) __attribute__((__nothrow__))
__attribute__((__malloc__)) __attribute__((__nonnull__(1)));

/* Return a malloc'd copy of at most N bytes of STRING.  The
   resultant string is terminated even if no null terminator
   appears before STRING[N].  */

extern char *strndup(const char *__string, size_t __n)
    __attribute__((__nothrow__)) __attribute__((__malloc__))
    __attribute__((__nonnull__(1)));
/* Find the first occurrence of C in S.  */
extern char *strchr(const char *__s, int __c) __attribute__((__nothrow__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));

/* Find the last occurrence of C in S.  */
extern char *strrchr(const char *__s, int __c) __attribute__((__nothrow__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));
/* Return the length of the initial segment of S which
   consists entirely of characters not in REJECT.  */
extern size_t strcspn(const char *__s, const char *__reject)
    __attribute__((__nothrow__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
/* Return the length of the initial segment of S which
   consists entirely of characters in ACCEPT.  */
extern size_t strspn(const char *__s, const char *__accept)
    __attribute__((__nothrow__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
/* Find the first occurrence in S of any character in ACCEPT.  */
extern char *strpbrk(const char *__s, const char *__accept)
    __attribute__((__nothrow__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

/* Find the first occurrence of NEEDLE in HAYSTACK.  */
extern char *strstr(const char *__haystack, const char *__needle)
    __attribute__((__nothrow__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

/* Divide S into tokens separated by characters in DELIM.  */
extern char *strtok(char *__restrict __s, const char *__restrict __delim)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(2)));

/* Divide S into tokens separated by characters in DELIM.  Information
   passed between calls are stored in SAVE_PTR.  */
extern char *__strtok_r(char *__restrict __s, const char *__restrict __delim,
                        char **__restrict __save_ptr)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(2, 3)));

extern char *strtok_r(char *__restrict __s, const char *__restrict __delim,
                      char **__restrict __save_ptr) __attribute__((__nothrow__))
__attribute__((__nonnull__(2, 3)));
/* Return the length of S.  */
extern size_t strlen(const char *__s) __attribute__((__nothrow__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));

/* Find the length of STRING, but scan at most MAXLEN characters.
   If no '\0' terminator is found in that many characters, return MAXLEN.  */
extern size_t strnlen(const char *__string, size_t __maxlen)
    __attribute__((__nothrow__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));

/* Return a string describing the meaning of the `errno' code in ERRNUM.  */
extern char *strerror(int __errnum) __attribute__((__nothrow__));

/* Reentrant version of `strerror'.
   There are 2 flavors of `strerror_r', GNU which returns the string
   and may or may not use the supplied temporary buffer and POSIX one
   which fills the string into the buffer.
   To use the POSIX version, -D_XOPEN_SOURCE=600 or -D_POSIX_C_SOURCE=200112L
   without -D_GNU_SOURCE is needed, otherwise the GNU version is
   preferred.  */

/* Fill BUF with a string describing the meaning of the `errno' code in
   ERRNUM.  */

extern int strerror_r(int __errnum, char *__buf, size_t __buflen) __asm__(
    ""
    "__xpg_strerror_r") __attribute__((__nothrow__))
__attribute__((__nonnull__(2)));
/* Translate error number to string according to the locale L.  */
extern char *strerror_l(int __errnum, __locale_t __l)
    __attribute__((__nothrow__));

/* We define this function always since `bzero' is sometimes needed when
   the namespace rules does not allow this.  */
extern void __bzero(void *__s, size_t __n) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));

/* Copy N bytes of SRC to DEST (like memmove, but args reversed).  */
extern void bcopy(const void *__src, void *__dest, size_t __n)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 2)));

/* Set N bytes of S to 0.  */
extern void bzero(void *__s, size_t __n) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));

/* Compare N bytes of S1 and S2 (same as memcmp).  */
extern int bcmp(const void *__s1, const void *__s2, size_t __n)
    __attribute__((__nothrow__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

/* Find the first occurrence of C in S (same as strchr).  */
extern char *index(const char *__s, int __c) __attribute__((__nothrow__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));

/* Find the last occurrence of C in S (same as strrchr).  */
extern char *rindex(const char *__s, int __c) __attribute__((__nothrow__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));

/* Return the position of the first bit set in I, or 0 if none are set.
   The least-significant bit is position 1, the most-significant 32.  */
extern int ffs(int __i) __attribute__((__nothrow__)) __attribute__((__const__));

/* The following two functions are non-standard but necessary for non-32 bit
   platforms.  */

/* Compare S1 and S2, ignoring case.  */
extern int strcasecmp(const char *__s1, const char *__s2)
    __attribute__((__nothrow__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

/* Compare no more than N chars of S1 and S2, ignoring case.  */
extern int strncasecmp(const char *__s1, const char *__s2, size_t __n)
    __attribute__((__nothrow__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
/* Return the next DELIM-delimited token from *STRINGP,
   terminating it with a '\0', and update *STRINGP to point past it.  */
extern char *strsep(char **__restrict __stringp, const char *__restrict __delim)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 2)));

/* Return a string describing the meaning of the signal number in SIG.  */
extern char *strsignal(int __sig) __attribute__((__nothrow__));

/* Copy SRC to DEST, returning the address of the terminating '\0' in DEST.  */
extern char *__stpcpy(char *__restrict __dest, const char *__restrict __src)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 2)));
extern char *stpcpy(char *__restrict __dest, const char *__restrict __src)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 2)));

/* Copy no more than N characters of SRC to DEST, returning the address of
   the last character written into DEST.  */
extern char *__stpncpy(char *__restrict __dest, const char *__restrict __src,
                       size_t __n) __attribute__((__nothrow__))
__attribute__((__nonnull__(1, 2)));
extern char *stpncpy(char *__restrict __dest, const char *__restrict __src,
                     size_t __n) __attribute__((__nothrow__))
__attribute__((__nonnull__(1, 2)));

/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.14 Signal handling <signal.h>
 */
/* __sig_atomic_t, __sigset_t, and related definitions.  Linux version.
   Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

typedef int __sig_atomic_t;

/* A `sigset_t' has a bit for each signal.  */

typedef struct {
    unsigned long int __val[(1024 / (8 * sizeof(unsigned long int)))];
} __sigset_t;

/* We only want to define these functions if <signal.h> was actually
   included; otherwise we were included just to define the types.  Since we
   are namespace-clean, it wouldn't hurt to define extra macros.  But
   trouble can be caused by functions being defined (e.g., any global
   register vars declared later will cause compilation errors).  */
/* Return a mask that includes the bit for SIG only.  */

/* Return the word index for SIG.  */
/* These functions needn't check for a bogus signal number -- error
   checking is done in the non __ versions.  */

extern int __sigismember(const __sigset_t *, int);
extern int __sigaddset(__sigset_t *, int);
extern int __sigdelset(__sigset_t *, int);

/* An integral type that can be modified atomically, without the
   possibility of a signal arriving in the middle of the operation.  */

typedef __sig_atomic_t sig_atomic_t;
typedef __sigset_t sigset_t;

/* Signal number definitions.  Linux version.
   Copyright (C) 1995-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* Fake signal functions.  */
/* Signals.  */
/* These are the hard limits of the kernel.  These values should not be
   used directly at user level.  */

typedef __pid_t pid_t;

typedef __uid_t uid_t;

/* We need `struct timespec' later on.  */

/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.23 Date and time	<time.h>
 */
/* POSIX.1b structure for a time value.  This is like a `struct timeval' but
   has nanoseconds instead of microseconds.  */
struct timespec {
    __time_t tv_sec;           /* Seconds.  */
    __syscall_slong_t tv_nsec; /* Nanoseconds.  */
};

/* Get the `siginfo_t' type plus the needed symbols.  */

/* siginfo_t, sigevent and constants.  Linux x86-64 version.
   Copyright (C) 2012-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* Determine the wordsize from the preprocessor defines.  */
/* Both x86-64 and x32 use the 64-bit system call interface.  */

/* Type for data associated with a signal.  */
typedef union sigval {
    int sival_int;
    void *sival_ptr;
} sigval_t;
typedef __clock_t __sigchld_clock_t;

typedef struct {
    int si_signo; /* Signal number.  */
    int si_errno; /* If non-zero, an errno value associated with
                   this signal, as defined in <errno.h>.  */
    int si_code;  /* Signal code.  */

    union {
        int _pad[((128 / sizeof(int)) - 4)];

        /* kill().  */
        struct {
            __pid_t si_pid; /* Sending process ID.  */
            __uid_t si_uid; /* Real user ID of sending process.  */
        } _kill;

        /* POSIX.1b timers.  */
        struct {
            int si_tid;         /* Timer ID.  */
            int si_overrun;     /* Overrun count.  */
            sigval_t si_sigval; /* Signal value.  */
        } _timer;

        /* POSIX.1b signals.  */
        struct {
            __pid_t si_pid;     /* Sending process ID.  */
            __uid_t si_uid;     /* Real user ID of sending process.  */
            sigval_t si_sigval; /* Signal value.  */
        } _rt;

        /* SIGCHLD.  */
        struct {
            __pid_t si_pid; /* Which child.  */
            __uid_t si_uid; /* Real user ID of sending process.  */
            int si_status;  /* Exit value or signal.  */
            __sigchld_clock_t si_utime;
            __sigchld_clock_t si_stime;
        } _sigchld;

        /* SIGILL, SIGFPE, SIGSEGV, SIGBUS.  */
        struct {
            void *si_addr;         /* Faulting insn/memory ref.  */
            short int si_addr_lsb; /* Valid LSB of the reported address.  */
            struct {
                void *_lower;
                void *_upper;
            } si_addr_bnd;
        } _sigfault;

        /* SIGPOLL.  */
        struct {
            long int si_band; /* Band event for SIGPOLL.  */
            int si_fd;
        } _sigpoll;

        /* SIGSYS.  */
        struct {
            void *_call_addr;   /* Calling user insn.  */
            int _syscall;       /* Triggering system call number.  */
            unsigned int _arch; /* AUDIT_ARCH_* of syscall.  */
        } _sigsys;
    } _sifields;
} siginfo_t;

/* X/Open requires some more fields with fixed names.  */
/* Values for `si_code'.  Positive values are reserved for kernel-generated
   signals.  */
enum {
    SI_ASYNCNL = -60, /* Sent by asynch name lookup completion.  */

    SI_TKILL = -6, /* Sent by tkill.  */

    SI_SIGIO, /* Sent by queued SIGIO. */

    SI_ASYNCIO, /* Sent by AIO completion.  */

    SI_MESGQ, /* Sent by real time mesq state change.  */

    SI_TIMER, /* Sent by timer expiration.  */

    SI_QUEUE, /* Sent by sigqueue.  */

    SI_USER, /* Sent by kill, sigsend.  */

    SI_KERNEL = 0x80 /* Send by kernel.  */

};

/* `si_code' values for SIGILL signal.  */
enum {
    ILL_ILLOPC = 1, /* Illegal opcode.  */

    ILL_ILLOPN, /* Illegal operand.  */

    ILL_ILLADR, /* Illegal addressing mode.  */

    ILL_ILLTRP, /* Illegal trap. */

    ILL_PRVOPC, /* Privileged opcode.  */

    ILL_PRVREG, /* Privileged register.  */

    ILL_COPROC, /* Coprocessor error.  */

    ILL_BADSTK /* Internal stack error.  */

};

/* `si_code' values for SIGFPE signal.  */
enum {
    FPE_INTDIV = 1, /* Integer divide by zero.  */

    FPE_INTOVF, /* Integer overflow.  */

    FPE_FLTDIV, /* Floating point divide by zero.  */

    FPE_FLTOVF, /* Floating point overflow.  */

    FPE_FLTUND, /* Floating point underflow.  */

    FPE_FLTRES, /* Floating point inexact result.  */

    FPE_FLTINV, /* Floating point invalid operation.  */

    FPE_FLTSUB /* Subscript out of range.  */

};

/* `si_code' values for SIGSEGV signal.  */
enum {
    SEGV_MAPERR = 1, /* Address not mapped to object.  */

    SEGV_ACCERR /* Invalid permissions for mapped object.  */

};

/* `si_code' values for SIGBUS signal.  */
enum {
    BUS_ADRALN = 1, /* Invalid address alignment.  */

    BUS_ADRERR, /* Non-existant physical address.  */

    BUS_OBJERR, /* Object specific hardware error.  */

    BUS_MCEERR_AR, /* Hardware memory error: action required.  */

    BUS_MCEERR_AO /* Hardware memory error: action optional.  */

};
/* `si_code' values for SIGCHLD signal.  */
enum {
    CLD_EXITED = 1, /* Child has exited.  */

    CLD_KILLED, /* Child was killed.  */

    CLD_DUMPED, /* Child terminated abnormally.  */

    CLD_TRAPPED, /* Traced child has trapped.  */

    CLD_STOPPED, /* Child has stopped.  */

    CLD_CONTINUED /* Stopped child has continued.  */

};

/* `si_code' values for SIGPOLL signal.  */
enum {
    POLL_IN = 1, /* Data input available.  */

    POLL_OUT, /* Output buffers available.  */

    POLL_MSG, /* Input message available.   */

    POLL_ERR, /* I/O error.  */

    POLL_PRI, /* High priority input available.  */

    POLL_HUP /* Device disconnected.  */

};
/* Structure to transport application-defined values with signals.  */

/* Forward declaration.  */

typedef union pthread_attr_t pthread_attr_t;

typedef struct sigevent {
    sigval_t sigev_value;
    int sigev_signo;
    int sigev_notify;

    union {
        int _pad[((64 / sizeof(int)) - 4)];

        /* When SIGEV_SIGNAL and SIGEV_THREAD_ID set, LWP ID of the
              thread to receive the signal.  */
        __pid_t _tid;

        struct {
            void (*_function)(sigval_t); /* Function to start.  */
            pthread_attr_t *_attribute;  /* Thread attributes.  */
        } _sigev_thread;
    } _sigev_un;
} sigevent_t;

/* POSIX names to access some of the members.  */

/* `sigev_notify' values.  */
enum {
    SIGEV_SIGNAL = 0, /* Notify via signal.  */

    SIGEV_NONE, /* Other notification: meaningless.  */

    SIGEV_THREAD, /* Deliver via thread creation.  */

    SIGEV_THREAD_ID = 4 /* Send signal to specific thread.  */

};

/* Type of a signal handler.  */
typedef void (*__sighandler_t)(int);

/* The X/Open definition of `signal' specifies the SVID semantic.  Use
   the additional function `sysv_signal' when X/Open compatibility is
   requested.  */
extern __sighandler_t __sysv_signal(int __sig, __sighandler_t __handler)
    __attribute__((__nothrow__));

/* Set the handler for the signal SIG to HANDLER, returning the old
   handler, or SIG_ERR on error.
   By default `signal' has the BSD semantic.  */

extern __sighandler_t signal(int __sig, __sighandler_t __handler)
    __attribute__((__nothrow__));
/* Send signal SIG to process number PID.  If PID is zero,
   send SIG to all processes in the current process's process group.
   If PID is < -1, send SIG to all processes in process group - PID.  */

extern int kill(__pid_t __pid, int __sig) __attribute__((__nothrow__));

/* Send SIG to all processes in process group PGRP.
   If PGRP is zero, send SIG to all processes in
   the current process's process group.  */
extern int killpg(__pid_t __pgrp, int __sig) __attribute__((__nothrow__));

/* Raise signal SIG, i.e., send SIG to yourself.  */
extern int raise(int __sig) __attribute__((__nothrow__));

/* SVID names for the same things.  */
extern __sighandler_t ssignal(int __sig, __sighandler_t __handler)
    __attribute__((__nothrow__));
extern int gsignal(int __sig) __attribute__((__nothrow__));

/* Print a message describing the meaning of the given signal number.  */
extern void psignal(int __sig, const char *__s);

/* Print a message describing the meaning of the given signal information.  */
extern void psiginfo(const siginfo_t *__pinfo, const char *__s);

/* The `sigpause' function in X/Open defines the argument as the
   signal number.  This requires redirecting to another function
   because the default version in glibc uses an old BSD interface.

   This function is a cancellation point and therefore not marked with
   __THROW.  */
/* None of the following functions should be used anymore.  They are here
   only for compatibility.  A single word (`int') is not guaranteed to be
   enough to hold a complete signal mask and therefore these functions
   simply do not work in many situations.  Use `sigprocmask' instead.  */

/* Compute mask for signal SIG.  */

/* Block signals in MASK, returning the old mask.  */
extern int sigblock(int __mask) __attribute__((__nothrow__))
__attribute__((__deprecated__));

/* Set the mask of blocked signals to MASK, returning the old mask.  */
extern int sigsetmask(int __mask) __attribute__((__nothrow__))
__attribute__((__deprecated__));

/* Return currently selected signal mask.  */
extern int siggetmask(void) __attribute__((__nothrow__))
__attribute__((__deprecated__));
/* 4.4 BSD uses the name `sig_t' for this.  */

typedef __sighandler_t sig_t;

/* Clear all signals from SET.  */
extern int sigemptyset(sigset_t *__set) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));

/* Set all signals in SET.  */
extern int sigfillset(sigset_t *__set) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));

/* Add SIGNO to SET.  */
extern int sigaddset(sigset_t *__set, int __signo) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));

/* Remove SIGNO from SET.  */
extern int sigdelset(sigset_t *__set, int __signo) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));

/* Return 1 if SIGNO is in SET, 0 if not.  */
extern int sigismember(const sigset_t *__set, int __signo)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
/* Get the system-specific definitions of `struct sigaction'
   and the `SA_*' and `SIG_*'. constants.  */

/* The proper definitions for Linux's sigaction.
   Copyright (C) 1993-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* Structure describing the action to be taken when a signal arrives.  */
struct sigaction {
    /* Signal handler.  */

    union {
        /* Used if SA_SIGINFO is not set.  */
        __sighandler_t sa_handler;
        /* Used if SA_SIGINFO is set.  */
        void (*sa_sigaction)(int, siginfo_t *, void *);
    } __sigaction_handler;

    /* Additional set of signals to be blocked.  */
    __sigset_t sa_mask;

    /* Special flags.  */
    int sa_flags;

    /* Restore handler.  */
    void (*sa_restorer)(void);
};

/* Bits in `sa_flags'.  */
/* Some aliases for the SA_ constants.  */

/* Values for the HOW argument to `sigprocmask'.  */

/* Get and/or change the set of blocked signals.  */
extern int sigprocmask(int __how, const sigset_t *__restrict __set,
                       sigset_t *__restrict __oset)
    __attribute__((__nothrow__));

/* Change the set of blocked signals to SET,
   wait until a signal arrives, and restore the set of blocked signals.

   This function is a cancellation point and therefore not marked with
   __THROW.  */
extern int sigsuspend(const sigset_t *__set) __attribute__((__nonnull__(1)));

/* Get and/or set the action for signal SIG.  */
extern int sigaction(int __sig, const struct sigaction *__restrict __act,
                     struct sigaction *__restrict __oact)
    __attribute__((__nothrow__));

/* Put in SET all signals that are blocked and waiting to be delivered.  */
extern int sigpending(sigset_t *__set) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));

/* Select any of pending signals from SET or wait for any to arrive.

   This function is a cancellation point and therefore not marked with
   __THROW.  */
extern int sigwait(const sigset_t *__restrict __set, int *__restrict __sig)
    __attribute__((__nonnull__(1, 2)));

/* Select any of pending signals from SET and place information in INFO.

   This function is a cancellation point and therefore not marked with
   __THROW.  */
extern int sigwaitinfo(const sigset_t *__restrict __set,
                       siginfo_t *__restrict __info)
    __attribute__((__nonnull__(1)));

/* Select any of pending signals from SET and place information in INFO.
   Wait the time specified by TIMEOUT if no signal is pending.

   This function is a cancellation point and therefore not marked with
   __THROW.  */
extern int sigtimedwait(const sigset_t *__restrict __set,
                        siginfo_t *__restrict __info,
                        const struct timespec *__restrict __timeout)
    __attribute__((__nonnull__(1)));

/* Send signal SIG to the process PID.  Associate data in VAL with the
   signal.  */
extern int sigqueue(__pid_t __pid, int __sig, const union sigval __val)
    __attribute__((__nothrow__));

/* Names of the signals.  This variable exists only for compatibility.
   Use `strsignal' instead (see <string.h>).  */
extern const char *const _sys_siglist[65];
extern const char *const sys_siglist[65];

/* Get machine-dependent `struct sigcontext' and signal subcodes.  */

/* Copyright (C) 2002-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
struct _fpx_sw_bytes {
    __uint32_t magic1;
    __uint32_t extended_size;
    __uint64_t xstate_bv;
    __uint32_t xstate_size;
    __uint32_t padding[7];
};

struct _fpreg {
    unsigned short significand[4];
    unsigned short exponent;
};

struct _fpxreg {
    unsigned short significand[4];
    unsigned short exponent;
    unsigned short padding[3];
};

struct _xmmreg {
    __uint32_t element[4];
};
struct _fpstate {
    /* FPU environment matching the 64-bit FXSAVE layout.  */
    __uint16_t cwd;
    __uint16_t swd;
    __uint16_t ftw;
    __uint16_t fop;
    __uint64_t rip;
    __uint64_t rdp;
    __uint32_t mxcsr;
    __uint32_t mxcr_mask;
    struct _fpxreg _st[8];
    struct _xmmreg _xmm[16];
    __uint32_t padding[24];
};

struct sigcontext {
    __uint64_t r8;
    __uint64_t r9;
    __uint64_t r10;
    __uint64_t r11;
    __uint64_t r12;
    __uint64_t r13;
    __uint64_t r14;
    __uint64_t r15;
    __uint64_t rdi;
    __uint64_t rsi;
    __uint64_t rbp;
    __uint64_t rbx;
    __uint64_t rdx;
    __uint64_t rax;
    __uint64_t rcx;
    __uint64_t rsp;
    __uint64_t rip;
    __uint64_t eflags;
    unsigned short cs;
    unsigned short gs;
    unsigned short fs;
    unsigned short __pad0;
    __uint64_t err;
    __uint64_t trapno;
    __uint64_t oldmask;
    __uint64_t cr2;
    __extension__ union {
        struct _fpstate *fpstate;
        __uint64_t __fpstate_word;
    };
    __uint64_t __reserved1[8];
};

struct _xsave_hdr {
    __uint64_t xstate_bv;
    __uint64_t reserved1[2];
    __uint64_t reserved2[5];
};

struct _ymmh_state {
    __uint32_t ymmh_space[64];
};

struct _xstate {
    struct _fpstate fpstate;
    struct _xsave_hdr xstate_hdr;
    struct _ymmh_state ymmh;
};

/* Restore the state saved in SCP.  */
extern int sigreturn(struct sigcontext *__scp) __attribute__((__nothrow__));

/*===---- stddef.h - Basic type definitions --------------------------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */
/* Some C libraries expect to see a wint_t here. Others (notably MinGW) will use
__WINT_TYPE__ directly; accommodate both by requiring __need_wint_t */

/* If INTERRUPT is nonzero, make signal SIG interrupt system calls
   (causing them to fail with EINTR); if INTERRUPT is zero, make system
   calls be restarted after signal SIG.  */
extern int siginterrupt(int __sig, int __interrupt)
    __attribute__((__nothrow__));

/* sigstack, sigaltstack definitions.
   Copyright (C) 1998-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* Structure describing a signal stack (obsolete).  */
struct sigstack {
    void *ss_sp;    /* Signal stack pointer.  */
    int ss_onstack; /* Nonzero if executing on this stack.  */
};

/* Possible values for `ss_flags.'.  */
enum {
    SS_ONSTACK = 1,

    SS_DISABLE

};

/* Minimum stack size for a signal handler.  */

/* System default stack size.  */

/* Alternate, preferred interface.  */
typedef struct sigaltstack {
    void *ss_sp;
    int ss_flags;
    size_t ss_size;
} stack_t;

/* This will define `ucontext_t' and `mcontext_t'.  */

/* Copyright (C) 2001-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.14 Signal handling <signal.h>
 */

/* We need the signal context definitions even if they are not used
   included in <signal.h>.  */

/* Type for general register.  */
__extension__ typedef long long int greg_t;

/* Number of general registers.  */

/* Container for all general registers.  */
typedef greg_t gregset_t[23];
struct _libc_fpxreg {
    unsigned short int significand[4];
    unsigned short int exponent;
    unsigned short int padding[3];
};

struct _libc_xmmreg {
    __uint32_t element[4];
};

struct _libc_fpstate {
    /* 64-bit FXSAVE format.  */
    __uint16_t cwd;
    __uint16_t swd;
    __uint16_t ftw;
    __uint16_t fop;
    __uint64_t rip;
    __uint64_t rdp;
    __uint32_t mxcsr;
    __uint32_t mxcr_mask;
    struct _libc_fpxreg _st[8];
    struct _libc_xmmreg _xmm[16];
    __uint32_t padding[24];
};

/* Structure to describe FPU registers.  */
typedef struct _libc_fpstate *fpregset_t;

/* Context to describe whole processor state.  */
typedef struct {
    gregset_t gregs;
    /* Note that fpregs is a pointer.  */
    fpregset_t fpregs;
    __extension__ unsigned long long __reserved1[8];
} mcontext_t;

/* Userlevel context.  */
typedef struct ucontext {
    unsigned long int uc_flags;
    struct ucontext *uc_link;
    stack_t uc_stack;
    mcontext_t uc_mcontext;
    __sigset_t uc_sigmask;
    struct _libc_fpstate __fpregs_mem;
} ucontext_t;

/* Run signals handlers on the stack specified by SS (if not NULL).
   If OSS is not NULL, it is filled in with the old signal stack status.
   This interface is obsolete and on many platform not implemented.  */
extern int sigstack(struct sigstack *__ss, struct sigstack *__oss)
    __attribute__((__nothrow__)) __attribute__((__deprecated__));

/* Alternate signal handler stack interface.
   This interface should always be preferred over `sigstack'.  */
extern int sigaltstack(const struct sigaltstack *__restrict __ss,
                       struct sigaltstack *__restrict __oss)
    __attribute__((__nothrow__));
/* Some of the functions for handling signals in threaded programs must
   be defined here.  */

/* Copyright (C) 2002-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* Determine the wordsize from the preprocessor defines.  */
/* Both x86-64 and x32 use the 64-bit system call interface.  */
/* Thread identifiers.  The structure of the attribute type is not
   exposed on purpose.  */
typedef unsigned long int pthread_t;

union pthread_attr_t {
    char __size[56];
    long int __align;
};

typedef struct __pthread_internal_list {
    struct __pthread_internal_list *__prev;
    struct __pthread_internal_list *__next;
} __pthread_list_t;
/* Data structures for mutex handling.  The structure of the attribute
   type is not exposed on purpose.  */
typedef union {
    struct __pthread_mutex_s {
        int __lock;
        unsigned int __count;
        int __owner;

        unsigned int __nusers;

        /* KIND must stay at this position in the structure to maintain
           binary compatibility.  */
        int __kind;

        short __spins;
        short __elision;
        __pthread_list_t __list;

        /* Mutex __spins initializer used by PTHREAD_MUTEX_INITIALIZER.  */
    } __data;
    char __size[40];
    long int __align;
} pthread_mutex_t;

typedef union {
    char __size[4];
    int __align;
} pthread_mutexattr_t;

/* Data structure for conditional variable handling.  The structure of
   the attribute type is not exposed on purpose.  */
typedef union {
    struct {
        int __lock;
        unsigned int __futex;
        __extension__ unsigned long long int __total_seq;
        __extension__ unsigned long long int __wakeup_seq;
        __extension__ unsigned long long int __woken_seq;
        void *__mutex;
        unsigned int __nwaiters;
        unsigned int __broadcast_seq;
    } __data;
    char __size[48];
    __extension__ long long int __align;
} pthread_cond_t;

typedef union {
    char __size[4];
    int __align;
} pthread_condattr_t;

/* Keys for thread-specific data */
typedef unsigned int pthread_key_t;

/* Once-only execution */
typedef int pthread_once_t;

/* Data structure for read-write lock variable handling.  The
   structure of the attribute type is not exposed on purpose.  */
typedef union {
    struct {
        int __lock;
        unsigned int __nr_readers;
        unsigned int __readers_wakeup;
        unsigned int __writer_wakeup;
        unsigned int __nr_readers_queued;
        unsigned int __nr_writers_queued;
        int __writer;
        int __shared;
        signed char __rwelision;

        unsigned char __pad1[7];

        unsigned long int __pad2;
        /* FLAGS must stay at this position in the structure to maintain
           binary compatibility.  */
        unsigned int __flags;

    } __data;
    char __size[56];
    long int __align;
} pthread_rwlock_t;

typedef union {
    char __size[8];
    long int __align;
} pthread_rwlockattr_t;

/* POSIX spinlock data type.  */
typedef volatile int pthread_spinlock_t;

/* POSIX barriers data type.  The structure of the type is
   deliberately not exposed.  */
typedef union {
    char __size[32];
    long int __align;
} pthread_barrier_t;

typedef union {
    char __size[4];
    int __align;
} pthread_barrierattr_t;
/* Signal handling function for threaded programs.
   Copyright (C) 1998-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation; either version 2.1 of the
   License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; see the file COPYING.LIB.  If
   not, see <http://www.gnu.org/licenses/>.  */
/* Functions for handling signals. */

/* Modify the signal mask for the calling thread.  The arguments have
   the same meaning as for sigprocmask(2). */
extern int pthread_sigmask(int __how, const __sigset_t *__restrict __newmask,
                           __sigset_t *__restrict __oldmask)
    __attribute__((__nothrow__));

/* Send signal SIGNO to the given thread. */
extern int pthread_kill(pthread_t __threadid, int __signo)
    __attribute__((__nothrow__));

/* The following functions are used internally in the C library and in
   other code which need deep insights.  */

/* Return number of available real-time signal with highest priority.  */
extern int __libc_current_sigrtmin(void) __attribute__((__nothrow__));
/* Return number of available real-time signal with lowest priority.  */
extern int __libc_current_sigrtmax(void) __attribute__((__nothrow__));

/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	POSIX Standard: 5.6 File Characteristics	<sys/stat.h>
 */
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.23 Date and time	<time.h>
 */
/* Returned by `time'.  */
typedef __time_t time_t;

/* The Single Unix specification says that some more types are
   available here.  */

typedef __dev_t dev_t;

typedef __gid_t gid_t;

typedef __ino_t ino_t;

typedef __mode_t mode_t;

typedef __nlink_t nlink_t;
/* Copyright (C) 1999-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* Versions of the `struct stat' data structure.  */
/* x86-64 versions of the `xmknod' interface.  */

struct stat {
    __dev_t st_dev; /* Device.  */

    __ino_t st_ino; /* File serial number.	*/

    __nlink_t st_nlink; /* Link count.  */
    __mode_t st_mode;   /* File mode.  */

    __uid_t st_uid; /* User ID of the file's owner.	*/
    __gid_t st_gid; /* Group ID of the file's group.*/

    int __pad0;

    __dev_t st_rdev; /* Device number, if device.  */

    __off_t st_size; /* Size of file, in bytes.  */

    __blksize_t st_blksize; /* Optimal block size for I/O.  */

    __blkcnt_t st_blocks; /* Number 512-byte blocks allocated. */

    /* Nanosecond resolution timestamps are stored in a format
       equivalent to 'struct timespec'.  This is the type used
       whenever possible but the Unix namespace rules do not allow the
       identifier 'timespec' to appear in the <sys/stat.h> header.
       Therefore we have to handle the use of this header in strictly
       standard-compliant sources special.  */
    struct timespec st_atim; /* Time of last access.  */
    struct timespec st_mtim; /* Time of last modification.  */
    struct timespec st_ctim; /* Time of last status change.  */
    __syscall_slong_t __glibc_reserved[3];
};
/* Tell code we have these members.  */

/* Nanosecond resolution time values are supported.  */

/* Encoding of the file mode.  */

/* File types.  */
/* POSIX.1b objects.  Note that these macros always evaluate to zero.  But
   they do it by enforcing the correct use of the macros.  */

/* Protection bits.  */
/* Test macros for file types.	*/
/* These are from POSIX.1b.  If the objects are not implemented using separate
   distinct file types, the macros always will evaluate to zero.  Unlike the
   other S_* macros the following three take a pointer to a `struct stat'
   object as the argument.  */

/* Protection bits.  */

/* Save swapped text after use (sticky bit).  This is pretty well obsolete.  */

/* Read, write, and execute by owner.  */
/* Read, write, and execute by group.  */

/* Read, write, and execute by others.  */

/* Macros for common mode bit masks.  */
/* Get file attributes for FILE and put them in BUF.  */
extern int stat(const char *__restrict __file, struct stat *__restrict __buf)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 2)));

/* Get file attributes for the file, device, pipe, or socket
   that file descriptor FD is open on and put them in BUF.  */
extern int fstat(int __fd, struct stat *__buf) __attribute__((__nothrow__))
__attribute__((__nonnull__(2)));
/* Similar to stat, get the attributes for FILE and put them in BUF.
   Relative path names are interpreted relative to FD unless FD is
   AT_FDCWD.  */

extern int fstatat(int __fd, const char *__restrict __file,
                   struct stat *__restrict __buf, int __flag)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(2, 3)));
/* Get file attributes about FILE and put them in BUF.
   If FILE is a symbolic link, do not follow it.  */
extern int lstat(const char *__restrict __file, struct stat *__restrict __buf)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 2)));
/* Set file access permissions for FILE to MODE.
   If FILE is a symbolic link, this affects its target instead.  */
extern int chmod(const char *__file, __mode_t __mode)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));

/* Set file access permissions for FILE to MODE.
   If FILE is a symbolic link, this affects the link itself
   rather than its target.  */
extern int lchmod(const char *__file, __mode_t __mode)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));

/* Set file access permissions of the file FD is open on to MODE.  */

extern int fchmod(int __fd, __mode_t __mode) __attribute__((__nothrow__));

/* Set file access permissions of FILE relative to
   the directory FD is open on.  */
extern int fchmodat(int __fd, const char *__file, __mode_t __mode, int __flag)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(2)));

/* Set the file creation mask of the current process to MASK,
   and return the old creation mask.  */
extern __mode_t umask(__mode_t __mask) __attribute__((__nothrow__));

/* Create a new directory named PATH, with permission bits MODE.  */
extern int mkdir(const char *__path, __mode_t __mode)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));

/* Like mkdir, create a new directory with permission bits MODE.  But
   interpret relative PATH names relative to the directory associated
   with FD.  */
extern int mkdirat(int __fd, const char *__path, __mode_t __mode)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(2)));

/* Create a device file named PATH, with permission and special bits MODE
   and device number DEV (which can be constructed from major and minor
   device numbers with the `makedev' macro above).  */

extern int mknod(const char *__path, __mode_t __mode, __dev_t __dev)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));

/* Like mknod, create a new device file with permission bits MODE and
   device number DEV.  But interpret relative PATH names relative to
   the directory associated with FD.  */
extern int mknodat(int __fd, const char *__path, __mode_t __mode, __dev_t __dev)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(2)));

/* Create a new FIFO named PATH, with permission bits MODE.  */
extern int mkfifo(const char *__path, __mode_t __mode)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));

/* Like mkfifo, create a new FIFO with permission bits MODE.  But
   interpret relative PATH names relative to the directory associated
   with FD.  */
extern int mkfifoat(int __fd, const char *__path, __mode_t __mode)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(2)));

/* Set file access and modification times relative to directory file
   descriptor.  */
extern int utimensat(int __fd, const char *__path,
                     const struct timespec __times[2], int __flags)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(2)));

/* Set file access and modification times of the file associated with FD.  */
extern int futimens(int __fd, const struct timespec __times[2])
    __attribute__((__nothrow__));

/* To allow the `struct stat' structure and the file type `mode_t'
   bits to vary without changing shared library major version number,
   the `stat' family of functions and `mknod' are in fact inline
   wrappers around calls to `xstat', `fxstat', `lxstat', and `xmknod',
   which all take a leading version-number argument designating the
   data structure and bits used.  <bits/stat.h> defines _STAT_VER with
   the version number corresponding to `struct stat' as defined in
   that file; and _MKNOD_VER with the version number corresponding to
   the S_IF* macros defined therein.  It is arranged that when not
   inlined these function are always statically linked; that way a
   dynamically-linked executable always encodes the version number
   corresponding to the data structures it uses, so the `x' functions
   in the shared library can adapt without needing to recompile all
   callers.  */
/* Wrappers for stat and mknod system calls.  */

extern int __fxstat(int __ver, int __fildes, struct stat *__stat_buf)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(3)));
extern int __xstat(int __ver, const char *__filename, struct stat *__stat_buf)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(2, 3)));
extern int __lxstat(int __ver, const char *__filename, struct stat *__stat_buf)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(2, 3)));
extern int __fxstatat(int __ver, int __fildes, const char *__filename,
                      struct stat *__stat_buf, int __flag)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(3, 4)));
extern int __xmknod(int __ver, const char *__path, __mode_t __mode,
                    __dev_t *__dev) __attribute__((__nothrow__))
__attribute__((__nonnull__(2, 4)));

extern int __xmknodat(int __ver, int __fd, const char *__path, __mode_t __mode,
                      __dev_t *__dev) __attribute__((__nothrow__))
__attribute__((__nonnull__(3, 5)));

/* support multiple event loops? */

struct ev_loop;
/* EV_INLINE is used for functions in header files */
/* EV_PROTOTYPES can be used to switch of prototype declarations */

/*****************************************************************************/

/* eventmask, revents, events... */
enum {
    EV_UNDEF = (int)0xFFFFFFFF, /* guaranteed to be invalid */
    EV_NONE = 0x00,             /* no events */
    EV_READ = 0x01,             /* ev_io detected read will not block */
    EV_WRITE = 0x02,            /* ev_io detected write will not block */
    EV__IOFDSET = 0x80,         /* internal use only */
    EV_IO = EV_READ,            /* alias for type-detection */
    EV_TIMER = 0x00000100,      /* timer timed out */

    EV_TIMEOUT = EV_TIMER, /* pre 4.0 API compatibility */

    EV_PERIODIC = 0x00000200,  /* periodic timer timed out */
    EV_SIGNAL = 0x00000400,    /* signal was received */
    EV_CHILD = 0x00000800,     /* child/pid had status change */
    EV_STAT = 0x00001000,      /* stat data changed */
    EV_IDLE = 0x00002000,      /* event loop is idling */
    EV_PREPARE = 0x00004000,   /* event loop about to poll */
    EV_CHECK = 0x00008000,     /* event loop finished poll */
    EV_EMBED = 0x00010000,     /* embedded event loop needs sweep */
    EV_FORK = 0x00020000,      /* event loop resumed in child */
    EV_CLEANUP = 0x00040000,   /* event loop resumed in child */
    EV_ASYNC = 0x00080000,     /* async intra-loop signal */
    EV_CUSTOM = 0x01000000,    /* for use by user code */
    EV_ERROR = (int)0x80000000 /* sent when an error occurs */
};

/* can be used to add custom fields to all watchers, while losing binary
 * compatibility */
/* not official, do not use */

/*
 * struct member types:
 * private: you may look at them, but not change them,
 *          and they might not mean anything to you.
 * ro: can be read anytime, but only changed when the watcher isn't active.
 * rw: can be read and modified anytime, even when the watcher is active.
 *
 * some internal details that might be helpful for debugging:
 *
 * active is either 0, which means the watcher is not active,
 *           or the array index of the watcher (periodics, timers)
 *           or the array index + 1 (most other watchers)
 *           or simply 1 for watchers that aren't in some array.
 * pending is either 0, in which case the watcher isn't,
 *           or the array index + 1 in the pendings array.
 */

/* shared by all watchers */
/* base class, nothing to see here unless you subclass */
typedef struct ev_watcher {
    int active;
    int pending;
    int priority;
    void *data;
    void (*cb)(struct ev_loop *loop, struct ev_watcher *w, int revents);
} ev_watcher;

/* base class, nothing to see here unless you subclass */
typedef struct ev_watcher_list {
    int active;
    int pending;
    int priority;
    void *data;
    void (*cb)(struct ev_loop *loop, struct ev_watcher_list *w, int revents);
    struct ev_watcher_list *next;
} ev_watcher_list;

/* base class, nothing to see here unless you subclass */
typedef struct ev_watcher_time {
    int active;
    int pending;
    int priority;
    void *data;
    void (*cb)(struct ev_loop *loop, struct ev_watcher_time *w, int revents);
    ev_tstamp at;
} ev_watcher_time;

/* invoked when fd is either EV_READable or EV_WRITEable */
/* revent EV_READ, EV_WRITE */
typedef struct ev_io {
    int active;
    int pending;
    int priority;
    void *data;
    void (*cb)(struct ev_loop *loop, struct ev_io *w, int revents);
    struct ev_watcher_list *next;

    int fd;     /* ro */
    int events; /* ro */
} ev_io;

/* invoked after a specific time, repeatable (based on monotonic clock) */
/* revent EV_TIMEOUT */
typedef struct ev_timer {
    int active;
    int pending;
    int priority;
    void *data;
    void (*cb)(struct ev_loop *loop, struct ev_timer *w, int revents);
    ev_tstamp at;

    ev_tstamp repeat; /* rw */
} ev_timer;

/* invoked at some specific time, possibly repeating at regular intervals (based
 * on UTC) */
/* revent EV_PERIODIC */
typedef struct ev_periodic {
    int active;
    int pending;
    int priority;
    void *data;
    void (*cb)(struct ev_loop *loop, struct ev_periodic *w, int revents);
    ev_tstamp at;

    ev_tstamp offset;                                                 /* rw */
    ev_tstamp interval;                                               /* rw */
    ev_tstamp (*reschedule_cb)(struct ev_periodic *w, ev_tstamp now); /* rw */
} ev_periodic;

/* invoked when the given signal has been received */
/* revent EV_SIGNAL */
typedef struct ev_signal {
    int active;
    int pending;
    int priority;
    void *data;
    void (*cb)(struct ev_loop *loop, struct ev_signal *w, int revents);
    struct ev_watcher_list *next;

    int signum; /* ro */
} ev_signal;

/* invoked when sigchld is received and waitpid indicates the given pid */
/* revent EV_CHILD */
/* does not support priorities */
typedef struct ev_child {
    int active;
    int pending;
    int priority;
    void *data;
    void (*cb)(struct ev_loop *loop, struct ev_child *w, int revents);
    struct ev_watcher_list *next;

    int flags;   /* private */
    int pid;     /* ro */
    int rpid;    /* rw, holds the received pid */
    int rstatus; /* rw, holds the exit status, use the macros from sys/wait.h */
} ev_child;

/* st_nlink = 0 means missing file or other error */

typedef struct stat ev_statdata;

/* invoked each time the stat data changes for a given path */
/* revent EV_STAT */
typedef struct ev_stat {
    int active;
    int pending;
    int priority;
    void *data;
    void (*cb)(struct ev_loop *loop, struct ev_stat *w, int revents);
    struct ev_watcher_list *next;

    ev_timer timer;     /* private */
    ev_tstamp interval; /* ro */
    const char *path;   /* ro */
    ev_statdata prev;   /* ro */
    ev_statdata attr;   /* ro */

    int wd; /* wd for inotify, fd for kqueue */
} ev_stat;

/* invoked when the nothing else needs to be done, keeps the process from
 * blocking */
/* revent EV_IDLE */
typedef struct ev_idle {
    int active;
    int pending;
    int priority;
    void *data;
    void (*cb)(struct ev_loop *loop, struct ev_idle *w, int revents);
} ev_idle;

/* invoked for each run of the mainloop, just before the blocking call */
/* you can still change events in any way you like */
/* revent EV_PREPARE */
typedef struct ev_prepare {
    int active;
    int pending;
    int priority;
    void *data;
    void (*cb)(struct ev_loop *loop, struct ev_prepare *w, int revents);
} ev_prepare;

/* invoked for each run of the mainloop, just after the blocking call */
/* revent EV_CHECK */
typedef struct ev_check {
    int active;
    int pending;
    int priority;
    void *data;
    void (*cb)(struct ev_loop *loop, struct ev_check *w, int revents);
} ev_check;

/* the callback gets invoked before check in the child process when a fork was
 * detected */
/* revent EV_FORK */
typedef struct ev_fork {
    int active;
    int pending;
    int priority;
    void *data;
    void (*cb)(struct ev_loop *loop, struct ev_fork *w, int revents);
} ev_fork;

/* is invoked just before the loop gets destroyed */
/* revent EV_CLEANUP */
typedef struct ev_cleanup {
    int active;
    int pending;
    int priority;
    void *data;
    void (*cb)(struct ev_loop *loop, struct ev_cleanup *w, int revents);
} ev_cleanup;

/* used to embed an event loop inside another */
/* the callback gets invoked when the event loop has handled events, and can be
 * 0 */
typedef struct ev_embed {
    int active;
    int pending;
    int priority;
    void *data;
    void (*cb)(struct ev_loop *loop, struct ev_embed *w, int revents);

    struct ev_loop *other; /* ro */
    ev_io io;              /* private */
    ev_prepare prepare;    /* private */
    ev_check check;        /* unused */
    ev_timer timer;        /* unused */
    ev_periodic periodic;  /* unused */
    ev_idle idle;          /* unused */
    ev_fork fork;          /* private */

    ev_cleanup cleanup; /* unused */

} ev_embed;

/* invoked when somebody calls ev_async_send on the watcher */
/* revent EV_ASYNC */
typedef struct ev_async {
    int active;
    int pending;
    int priority;
    void *data;
    void (*cb)(struct ev_loop *loop, struct ev_async *w, int revents);

    sig_atomic_t volatile sent; /* private */
} ev_async;

/* the presence of this union forces similar struct layout */
union ev_any_watcher {
    struct ev_watcher w;
    struct ev_watcher_list wl;

    struct ev_io io;
    struct ev_timer timer;
    struct ev_periodic periodic;
    struct ev_signal signal;
    struct ev_child child;

    struct ev_stat stat;

    struct ev_idle idle;

    struct ev_prepare prepare;
    struct ev_check check;

    struct ev_fork fork;

    struct ev_cleanup cleanup;

    struct ev_embed embed;

    struct ev_async async;
};

/* flag bits for ev_default_loop and ev_loop_new */
enum {
    /* the default */
    EVFLAG_AUTO = 0x00000000U, /* not quite a mask */
    /* flag bits */
    EVFLAG_NOENV = 0x01000000U,     /* do NOT consult environment */
    EVFLAG_FORKCHECK = 0x02000000U, /* check for a fork in each iteration */
    /* debugging/feature disable */
    EVFLAG_NOINOTIFY = 0x00100000U, /* do not attempt to use inotify */

    EVFLAG_NOSIGFD = 0, /* compatibility to pre-3.9 */

    EVFLAG_SIGNALFD = 0x00200000U, /* attempt to use signalfd */
    EVFLAG_NOSIGMASK = 0x00400000U /* avoid modifying the signal mask */
};

/* method bits to be ored together */
enum {
    EVBACKEND_SELECT = 0x00000001U, /* about anywhere */
    EVBACKEND_POLL = 0x00000002U,   /* !win */
    EVBACKEND_EPOLL = 0x00000004U,  /* linux */
    EVBACKEND_KQUEUE = 0x00000008U, /* bsd */
    EVBACKEND_DEVPOLL = 0x00000010U,
    /* solaris 8 */               /* NYI */
    EVBACKEND_PORT = 0x00000020U, /* solaris 10 */
    EVBACKEND_ALL = 0x0000003FU,  /* all known backends */
    EVBACKEND_MASK = 0x0000FFFFU  /* all future backends */
};

extern int ev_version_major(void);
extern int ev_version_minor(void);

extern unsigned int ev_supported_backends(void);
extern unsigned int ev_recommended_backends(void);
extern unsigned int ev_embeddable_backends(void);

extern ev_tstamp ev_time(void);
extern void ev_sleep(ev_tstamp delay); /* sleep for a while */

/* Sets the allocation function to use, works like realloc.
 * It is used to allocate and free memory.
 * If it returns zero when memory needs to be allocated, the library might abort
 * or take some potentially destructive action.
 * The default is your system realloc function.
 */
extern void ev_set_allocator(void *(*cb)(void *ptr, long size));

/* set the callback function to call on a
 * retryable syscall error
 * (such as failed select, poll, epoll_wait)
 */
extern void ev_set_syserr_cb(void (*cb)(const char *msg));

/* the default loop is the only one that handles signals and child watchers */
/* you can call this as often as you like */
extern struct ev_loop *ev_default_loop(unsigned int flags);

static inline struct ev_loop *ev_default_loop_uc_(void) {
    extern struct ev_loop *ev_default_loop_ptr;

    return ev_default_loop_ptr;
}

static inline int ev_is_default_loop(struct ev_loop *loop) {
    return loop == ev_default_loop_uc_();
}

/* create and destroy alternative loops that don't handle signals */
extern struct ev_loop *ev_loop_new(unsigned int flags);

extern ev_tstamp ev_now(
    struct ev_loop *loop); /* time w.r.t. timers and the eventloop, updated
                              after each poll */
/* destroy event loops, also works for the default loop */
extern void ev_loop_destroy(struct ev_loop *loop);

/* this needs to be called after fork, to duplicate the loop */
/* when you want to re-use it in the child */
/* you can call it in either the parent or the child */
/* you can actually call it at any time, anywhere :) */
extern void ev_loop_fork(struct ev_loop *loop);

extern unsigned int ev_backend(
    struct ev_loop *loop); /* backend in use by loop */

extern void ev_now_update(struct ev_loop *loop); /* update event loop time */
/* ev_run flags values */
enum {
    EVRUN_NOWAIT = 1, /* do not block/wait */
    EVRUN_ONCE = 2    /* block *once* only */
};

/* ev_break how values */
enum {
    EVBREAK_CANCEL = 0, /* undo unloop */
    EVBREAK_ONE = 1,    /* unloop once */
    EVBREAK_ALL = 2     /* unloop all loops */
};

extern int ev_run(struct ev_loop *loop, int flags);
extern void ev_break(struct ev_loop *loop, int how); /* break out of the loop */

/*
 * ref/unref can be used to add or remove a refcount on the mainloop. every
 * watcher keeps one reference. if you have a long-running watcher you never
 * unregister that should not keep ev_loop from running, unref() after starting,
 * and ref() before stopping.
 */
extern void ev_ref(struct ev_loop *loop);
extern void ev_unref(struct ev_loop *loop);

/*
 * convenience function, wait for a single event, without registering an event
 * watcher if timeout is < 0, do wait indefinitely
 */
extern void ev_once(struct ev_loop *loop, int fd, int events, ev_tstamp timeout,
                    void (*cb)(int revents, void *arg), void *arg);

extern unsigned int ev_iteration(
    struct ev_loop *loop); /* number of loop iterations */
extern unsigned int ev_depth(
    struct ev_loop *loop); /* #ev_loop enters - #ev_loop leaves */
extern void ev_verify(struct ev_loop *loop); /* abort if loop data corrupted */

extern void ev_set_io_collect_interval(
    struct ev_loop *loop,
    ev_tstamp interval); /* sleep at least this time, default 0 */
extern void ev_set_timeout_collect_interval(
    struct ev_loop *loop,
    ev_tstamp interval); /* sleep at least this time, default 0 */

/* advanced stuff for threading etc. support, see docs */
extern void ev_set_userdata(struct ev_loop *loop, void *data);
extern void *ev_userdata(struct ev_loop *loop);
typedef void (*ev_loop_callback)(struct ev_loop *loop);
extern void ev_set_invoke_pending_cb(struct ev_loop *loop,
                                     ev_loop_callback invoke_pending_cb);
/* C++ doesn't allow the use of the ev_loop_callback typedef here, so we need to
 * spell it out */
extern void ev_set_loop_release_cb(struct ev_loop *loop,
                                   void (*release)(struct ev_loop *loop),
                                   void (*acquire)(struct ev_loop *loop));

extern unsigned int ev_pending_count(
    struct ev_loop *loop); /* number of pending events, if any */
extern void ev_invoke_pending(
    struct ev_loop *loop); /* invoke all pending watchers */

/*
 * stop/start the timer handling.
 */
extern void ev_suspend(struct ev_loop *loop);
extern void ev_resume(struct ev_loop *loop);

/* these may evaluate ev multiple times, and the other arguments at most once */
/* either use ev_init + ev_TYPE_set, or the ev_TYPE_init macro, below, to first
 * initialise a watcher */
/* stopping (enabling, adding) a watcher does nothing if it is already running
 */
/* stopping (disabling, deleting) a watcher does nothing unless it's already
 * running */

/* feeds an event into a watcher as if the event actually occurred */
/* accepts any ev_watcher type */
extern void ev_feed_event(struct ev_loop *loop, void *w, int revents);
extern void ev_feed_fd_event(struct ev_loop *loop, int fd, int revents);

extern void ev_feed_signal(int signum);
extern void ev_feed_signal_event(struct ev_loop *loop, int signum);

extern void ev_invoke(struct ev_loop *loop, void *w, int revents);
extern int ev_clear_pending(struct ev_loop *loop, void *w);

extern void ev_io_start(struct ev_loop *loop, ev_io *w);
extern void ev_io_stop(struct ev_loop *loop, ev_io *w);

extern void ev_timer_start(struct ev_loop *loop, ev_timer *w);
extern void ev_timer_stop(struct ev_loop *loop, ev_timer *w);
/* stops if active and no repeat, restarts if active and repeating, starts if
 * inactive and repeating */
extern void ev_timer_again(struct ev_loop *loop, ev_timer *w);
/* return remaining time */
extern ev_tstamp ev_timer_remaining(struct ev_loop *loop, ev_timer *w);

extern void ev_periodic_start(struct ev_loop *loop, ev_periodic *w);
extern void ev_periodic_stop(struct ev_loop *loop, ev_periodic *w);
extern void ev_periodic_again(struct ev_loop *loop, ev_periodic *w);

/* only supported in the default loop */

extern void ev_signal_start(struct ev_loop *loop, ev_signal *w);
extern void ev_signal_stop(struct ev_loop *loop, ev_signal *w);

/* only supported in the default loop */

extern void ev_child_start(struct ev_loop *loop, ev_child *w);
extern void ev_child_stop(struct ev_loop *loop, ev_child *w);

extern void ev_stat_start(struct ev_loop *loop, ev_stat *w);
extern void ev_stat_stop(struct ev_loop *loop, ev_stat *w);
extern void ev_stat_stat(struct ev_loop *loop, ev_stat *w);

extern void ev_idle_start(struct ev_loop *loop, ev_idle *w);
extern void ev_idle_stop(struct ev_loop *loop, ev_idle *w);

extern void ev_prepare_start(struct ev_loop *loop, ev_prepare *w);
extern void ev_prepare_stop(struct ev_loop *loop, ev_prepare *w);

extern void ev_check_start(struct ev_loop *loop, ev_check *w);
extern void ev_check_stop(struct ev_loop *loop, ev_check *w);

extern void ev_fork_start(struct ev_loop *loop, ev_fork *w);
extern void ev_fork_stop(struct ev_loop *loop, ev_fork *w);

extern void ev_cleanup_start(struct ev_loop *loop, ev_cleanup *w);
extern void ev_cleanup_stop(struct ev_loop *loop, ev_cleanup *w);

/* only supported when loop to be embedded is in fact embeddable */
extern void ev_embed_start(struct ev_loop *loop, ev_embed *w);
extern void ev_embed_stop(struct ev_loop *loop, ev_embed *w);
extern void ev_embed_sweep(struct ev_loop *loop, ev_embed *w);

extern void ev_async_start(struct ev_loop *loop, ev_async *w);
extern void ev_async_stop(struct ev_loop *loop, ev_async *w);
extern void ev_async_send(struct ev_loop *loop, ev_async *w);
static inline void ev_loop(struct ev_loop *loop, int flags) {
    ev_run(loop, flags);
}
static inline void ev_unloop(struct ev_loop *loop, int how) {
    ev_break(loop, how);
}
static inline void ev_default_destroy(void) {
    ev_loop_destroy(ev_default_loop(0));
}
static inline void ev_default_fork(void) { ev_loop_fork(ev_default_loop(0)); }

static inline unsigned int ev_loop_count(struct ev_loop *loop) {
    return ev_iteration(loop);
}
static inline unsigned int ev_loop_depth(struct ev_loop *loop) {
    return ev_depth(loop);
}
static inline void ev_loop_verify(struct ev_loop *loop) { ev_verify(loop); }
typedef struct loop_t {
    struct ev_loop *loop;
} loop_t;

/*
 *    internal function
 */
inline static loop_t *get_loop(lua_State *L, int index) {
    loop_t *lo = (loop_t *)luaL_checkudata(L, index, "loop_metatable");
    return lo;
}

inline static void setloop(lua_State *L, struct ev_loop *loop) {
    loop_t *lo = (loop_t *)lua_newuserdata(L, sizeof(loop_t));
    (lua_getfield(L, (-1000000 - 1000), ("loop_metatable")));
    lua_setmetatable(L, -2);

    lo->loop = loop;
}

static int traceback(lua_State *L) {
    const char *msg = lua_tolstring(L, (1), ((void *)0));
    if (msg)
        luaL_traceback(L, L, msg, 1);
    else {
        lua_pushstring(L,
                       ""
                       "(no error message)");
    }
    return 1;
}

// *L = ev_userdata(loop)
// L statck:
//  -1: trace
//  -2: ud
//  -3: lua function
static void watcher_cb(struct ev_loop *loop, void *w, int revents) {
    lua_State *L = ev_userdata(loop);
    int traceback = lua_gettop(L);
    int r;

    ((L != ((void *)0)) ? (void)(0)
                        : __assert_fail("L != NULL", "../src/lua-ev.c", 70,
                                        __PRETTY_FUNCTION__));
    (((lua_type(L, (traceback)) == 6))
         ? (void)(0)
         : __assert_fail("lua_isfunction(L, traceback)", "../src/lua-ev.c", 71,
                         __PRETTY_FUNCTION__));
    (((lua_type(L, (traceback - 2)) == 6))
         ? (void)(0)
         : __assert_fail("lua_isfunction(L, traceback - 2)", "../src/lua-ev.c",
                         72, __PRETTY_FUNCTION__));
    lua_pushvalue(L, traceback - 2);  // function
    lua_pushvalue(L, traceback - 1);  // ud
    lua_pushlightuserdata(L, (void *)w);
    lua_pushinteger(L, revents);

    r = lua_pcallk(L, (3), (0), (traceback), 0, ((void *)0));
    if (r == 0) {
        return;
    }
    printf("watcher(%p) event:%x, callback failed, errcode:%d, msg: %s", w,
           revents, r, lua_tolstring(L, (-1), ((void *)0)));
    lua_settop(L, -(1) - 1);
    return;
}

/*
 *    end
 */

static int ev_version(lua_State *L) {
    lua_pushinteger(L, ev_version_major());
    lua_pushinteger(L, ev_version_minor());
    return 2;
}

/*
 * loop function
 */
static int default_loop(lua_State *L) {
    unsigned int flags = (unsigned int)luaL_optinteger(L, 1, EVFLAG_AUTO);
    struct ev_loop *loop = ev_default_loop(flags);
    setloop(L, loop);
    return 1;
}

static int new_loop(lua_State *L) {
    unsigned int flags = (unsigned int)luaL_optinteger(L, 1, EVFLAG_AUTO);
    struct ev_loop *loop = ev_loop_new(flags);
    setloop(L, loop);
    return 1;
}

static int loop_destroy(lua_State *L) {
    loop_t *lo = get_loop(L, 1);
    struct ev_loop *loop = lo->loop;
    if (loop) {
        lo->loop = 0;
        ev_loop_destroy(loop);
    }
    return 0;
}

static int loop_tostring(lua_State *L) {
    loop_t *lo = get_loop(L, 1);
    lua_pushfstring(L, "loop: %p", lo);
    return 1;
}

// void ev_*(loop)

// int/unsigned/boolean/number ev_*(loop)

// void ev_*(loop, arg1)
// int/unsigned/boolean/number ev_*(loop, arg1)
static int loop_loop_fork(lua_State *L) {
    loop_t *lo = get_loop(L, 1);
    ev_loop_fork(lo->loop);
    return 0;
}
static int loop_is_default_loop(lua_State *L) {
    loop_t *lo = get_loop(L, 1);
    lua_pushboolean(L, ev_is_default_loop(lo->loop));
    return 1;
}
static int loop_iteration(lua_State *L) {
    loop_t *lo = get_loop(L, 1);
    lua_pushinteger(L, ev_iteration(lo->loop));
    return 1;
}
static int loop_depth(lua_State *L) {
    loop_t *lo = get_loop(L, 1);
    lua_pushinteger(L, ev_depth(lo->loop));
    return 1;
}
static int loop_backend(lua_State *L) {
    loop_t *lo = get_loop(L, 1);
    lua_pushinteger(L, ev_backend(lo->loop));
    return 1;
}
static int loop_suspend(lua_State *L) {
    loop_t *lo = get_loop(L, 1);
    ev_suspend(lo->loop);
    return 0;
}
static int loop_resume(lua_State *L) {
    loop_t *lo = get_loop(L, 1);
    ev_resume(lo->loop);
    return 0;
}
static int loop_verify(lua_State *L) {
    loop_t *lo = get_loop(L, 1);
    ev_verify(lo->loop);
    return 0;
}

static int loop_now(lua_State *L) {
    loop_t *lo = get_loop(L, 1);
    lua_pushnumber(L, ev_now(lo->loop));
    return 1;
}
static int loop_now_update(lua_State *L) {
    loop_t *lo = get_loop(L, 1);
    ev_now_update(lo->loop);
    return 0;
}
static int loop_break(lua_State *L) {
    loop_t *lo = get_loop(L, 1);
    int a1 = luaL_checkinteger(L, 2);
    ev_break(lo->loop, a1);
    return 0;
}
static int loop_ref(lua_State *L) {
    loop_t *lo = get_loop(L, 1);
    ev_ref(lo->loop);
    return 0;
}
static int loop_unref(lua_State *L) {
    loop_t *lo = get_loop(L, 1);
    ev_unref(lo->loop);
    return 0;
}
static int loop_pending_count(lua_State *L) {
    loop_t *lo = get_loop(L, 1);
    lua_pushinteger(L, ev_pending_count(lo->loop));
    return 1;
}

// L statck:
//  4: ud
//  3: cb
//  2: flags
//  1: loop
static int loop_run(lua_State *L) {
    struct ev_loop *loop;
    loop_t *lo = get_loop(L, 1);
    int flags = luaL_checkinteger(L, 2);
    luaL_checktype(L, 3, 6);
    luaL_checkany(L, 4);
    lua_pushcclosure(L, (traceback), 0);

    loop = lo->loop;
    ev_set_userdata(loop, L);
    lua_pushboolean(L, ev_run(loop, flags));
    ev_set_userdata(loop, ((void *)0));
    return 1;
}

static const struct luaL_Reg mt_loop[] = {{"__gc", loop_destroy},
                                          {"__tostring", loop_tostring},
                                          {((void *)0), ((void *)0)}};

static const struct luaL_Reg methods_loop[] = {
    {"loop_fork", loop_loop_fork},
    {"is_default_loop", loop_is_default_loop},
    {"iteration", loop_iteration},
    {"depth", loop_depth},
    {"backend", loop_backend},
    {"suspend", loop_suspend},
    {"resume", loop_resume},
    {"run", loop_run},
    {"verify", loop_verify},

    {"now", loop_now},
    {"now_update", loop_now_update},
    {"_break", loop_break},
    {"ref", loop_ref},
    {"unref", loop_unref},
    {"pending_count", loop_pending_count},

    {((void *)0), ((void *)0)}};

/*
 *  end
 */

// watcher
// ev_io
static int new_io(lua_State *L) {
    ev_io *w = (ev_io *)lua_newuserdata(L, sizeof(*w));
    (lua_getfield(L, (-1000000 - 1000),
                  ("watcher_"
                   "io"
                   "_metatable")));
    lua_setmetatable(L, -2);
    return 1;
}
inline static ev_io *get_io(lua_State *L, int index) {
    ev_io *w = (ev_io *)luaL_checkudata(L, index,
                                        "watcher_"
                                        "io"
                                        "_metatable");
    return w;
}
static int io_tostring(lua_State *L) {
    ev_io *w = get_io(L, 1);
    lua_pushfstring(L, "%s: %p", "io", w);
    return 1;
}
static int io_id(lua_State *L) {
    ev_io *w = get_io(L, 1);
    lua_pushlightuserdata(L, (void *)w);
    return 1;
}
static int io_start(lua_State *L) {
    ev_io *w = get_io(L, 1);
    loop_t *lo = get_loop(L, 2);
    ev_io_start(lo->loop, w);
    return 1;
}
static int io_stop(lua_State *L) {
    ev_io *w = get_io(L, 1);
    loop_t *lo = get_loop(L, 2);
    ev_io_stop(lo->loop, w);
    return 1;
}
static int io_is_active(lua_State *L) {
    ev_io *w = get_io(L, 1);
    lua_pushboolean(L, (0 + ((ev_watcher *)(void *)(w))->active));
    return 1;
}
static int io_is_pending(lua_State *L) {
    ev_io *w = get_io(L, 1);
    lua_pushboolean(L, (0 + ((ev_watcher *)(void *)(w))->pending));
    return 1;
}
static int io_get_priority(lua_State *L) {
    ev_io *w = get_io(L, 1);
    lua_pushinteger(L, (+(((ev_watcher *)(void *)(w))->priority)));
    return 1;
}
static int io_set_priority(lua_State *L) {
    ev_io *w = get_io(L, 1);
    int priority = luaL_checkinteger(L, 2);
    ((ev_watcher *)(void *)(w))->priority = (priority);
    return 0;
}

static int io_init(lua_State *L) {
    ev_io *w = get_io(L, 1);
    int fd = luaL_checkinteger(L, 2);
    int revents = luaL_checkinteger(L, 3);
    do {
        do {
            ((ev_watcher *)(void *)((w)))->active =
                ((ev_watcher *)(void *)((w)))->pending = 0;
            ((ev_watcher *)(void *)(((w))))->priority = (0);
            ((((w)))->cb = ((watcher_cb)),
             memmove(&((ev_watcher *)(((w))))->cb, &(((w)))->cb,
                     sizeof((((w)))->cb)));
        } while (0);
        do {
            ((w))->fd = ((fd));
            ((w))->events = ((revents)) | EV__IOFDSET;
        } while (0);
    } while (0);
    return 0;
}

static const struct luaL_Reg mt_io[] = {{"__tostring", io_tostring},
                                        {((void *)0), ((void *)0)}};

static const struct luaL_Reg methods_io[] = {{"id", io_id},
                                             {"start", io_start},
                                             {"stop", io_stop},
                                             {"init", io_init},
                                             {"is_active", io_is_active},
                                             {"is_pending", io_is_pending},
                                             {"get_priority", io_get_priority},
                                             {"set_priority", io_set_priority},
                                             {((void *)0), ((void *)0)}};

// ev_timer
static int new_timer(lua_State *L) {
    ev_timer *w = (ev_timer *)lua_newuserdata(L, sizeof(*w));
    (lua_getfield(L, (-1000000 - 1000),
                  ("watcher_"
                   "timer"
                   "_metatable")));
    lua_setmetatable(L, -2);
    return 1;
}
inline static ev_timer *get_timer(lua_State *L, int index) {
    ev_timer *w = (ev_timer *)luaL_checkudata(L, index,
                                              "watcher_"
                                              "timer"
                                              "_metatable");
    return w;
}
static int timer_tostring(lua_State *L) {
    ev_timer *w = get_timer(L, 1);
    lua_pushfstring(L, "%s: %p", "timer", w);
    return 1;
}
static int timer_id(lua_State *L) {
    ev_timer *w = get_timer(L, 1);
    lua_pushlightuserdata(L, (void *)w);
    return 1;
}
static int timer_start(lua_State *L) {
    ev_timer *w = get_timer(L, 1);
    loop_t *lo = get_loop(L, 2);
    ev_timer_start(lo->loop, w);
    return 1;
}
static int timer_stop(lua_State *L) {
    ev_timer *w = get_timer(L, 1);
    loop_t *lo = get_loop(L, 2);
    ev_timer_stop(lo->loop, w);
    return 1;
}
static int timer_is_active(lua_State *L) {
    ev_timer *w = get_timer(L, 1);
    lua_pushboolean(L, (0 + ((ev_watcher *)(void *)(w))->active));
    return 1;
}
static int timer_is_pending(lua_State *L) {
    ev_timer *w = get_timer(L, 1);
    lua_pushboolean(L, (0 + ((ev_watcher *)(void *)(w))->pending));
    return 1;
}
static int timer_get_priority(lua_State *L) {
    ev_timer *w = get_timer(L, 1);
    lua_pushinteger(L, (+(((ev_watcher *)(void *)(w))->priority)));
    return 1;
}
static int timer_set_priority(lua_State *L) {
    ev_timer *w = get_timer(L, 1);
    int priority = luaL_checkinteger(L, 2);
    ((ev_watcher *)(void *)(w))->priority = (priority);
    return 0;
}

static int timer_init(lua_State *L) {
    ev_timer *w = get_timer(L, 1);
    double after = luaL_checknumber(L, 2);
    double repeat = luaL_optnumber(L, 3, 0);
    do {
        do {
            ((ev_watcher *)(void *)((w)))->active =
                ((ev_watcher *)(void *)((w)))->pending = 0;
            ((ev_watcher *)(void *)(((w))))->priority = (0);
            ((((w)))->cb = ((watcher_cb)),
             memmove(&((ev_watcher *)(((w))))->cb, &(((w)))->cb,
                     sizeof((((w)))->cb)));
        } while (0);
        do {
            ((ev_watcher_time *)((w)))->at = ((after));
            ((w))->repeat = ((repeat));
        } while (0);
    } while (0);
    return 0;
}

static int timer_again(lua_State *L) {
    ev_timer *w = get_timer(L, 1);
    loop_t *lo = get_loop(L, 2);
    ev_timer_again(lo->loop, w);
    return 0;
}

static const struct luaL_Reg mt_timer[] = {{"__tostring", timer_tostring},
                                           {((void *)0), ((void *)0)}};

static const struct luaL_Reg methods_timer[] = {
    {"id", timer_id},
    {"start", timer_start},
    {"stop", timer_stop},
    {"init", timer_init},
    {"is_active", timer_is_active},
    {"is_pending", timer_is_pending},
    {"get_priority", timer_get_priority},
    {"set_priority", timer_set_priority},
    {"again", timer_again},
    {((void *)0), ((void *)0)}};

// ev_signal
static int new_signal(lua_State *L) {
    ev_signal *w = (ev_signal *)lua_newuserdata(L, sizeof(*w));
    (lua_getfield(L, (-1000000 - 1000),
                  ("watcher_"
                   "signal"
                   "_metatable")));
    lua_setmetatable(L, -2);
    return 1;
}
inline static ev_signal *get_signal(lua_State *L, int index) {
    ev_signal *w = (ev_signal *)luaL_checkudata(L, index,
                                                "watcher_"
                                                "signal"
                                                "_metatable");
    return w;
}
static int signal_tostring(lua_State *L) {
    ev_signal *w = get_signal(L, 1);
    lua_pushfstring(L, "%s: %p", "signal", w);
    return 1;
}
static int signal_id(lua_State *L) {
    ev_signal *w = get_signal(L, 1);
    lua_pushlightuserdata(L, (void *)w);
    return 1;
}
static int signal_start(lua_State *L) {
    ev_signal *w = get_signal(L, 1);
    loop_t *lo = get_loop(L, 2);
    ev_signal_start(lo->loop, w);
    return 1;
}
static int signal_stop(lua_State *L) {
    ev_signal *w = get_signal(L, 1);
    loop_t *lo = get_loop(L, 2);
    ev_signal_stop(lo->loop, w);
    return 1;
}
static int signal_is_active(lua_State *L) {
    ev_signal *w = get_signal(L, 1);
    lua_pushboolean(L, (0 + ((ev_watcher *)(void *)(w))->active));
    return 1;
}
static int signal_is_pending(lua_State *L) {
    ev_signal *w = get_signal(L, 1);
    lua_pushboolean(L, (0 + ((ev_watcher *)(void *)(w))->pending));
    return 1;
}
static int signal_get_priority(lua_State *L) {
    ev_signal *w = get_signal(L, 1);
    lua_pushinteger(L, (+(((ev_watcher *)(void *)(w))->priority)));
    return 1;
}
static int signal_set_priority(lua_State *L) {
    ev_signal *w = get_signal(L, 1);
    int priority = luaL_checkinteger(L, 2);
    ((ev_watcher *)(void *)(w))->priority = (priority);
    return 0;
}

static int signal_init(lua_State *L) {
    ev_signal *w = get_signal(L, 1);
    int signum = luaL_checkinteger(L, 2);
    do {
        do {
            ((ev_watcher *)(void *)((w)))->active =
                ((ev_watcher *)(void *)((w)))->pending = 0;
            ((ev_watcher *)(void *)(((w))))->priority = (0);
            ((((w)))->cb = ((watcher_cb)),
             memmove(&((ev_watcher *)(((w))))->cb, &(((w)))->cb,
                     sizeof((((w)))->cb)));
        } while (0);
        do {
            ((w))->signum = ((signum));
        } while (0);
    } while (0);
    return 0;
}

static const struct luaL_Reg mt_signal[] = {{"__tostring", signal_tostring},
                                            {((void *)0), ((void *)0)}};

static const struct luaL_Reg methods_signal[] = {
    {"id", signal_id},
    {"start", signal_start},
    {"stop", signal_stop},
    {"init", signal_init},
    {"is_active", signal_is_active},
    {"is_pending", signal_is_pending},
    {"get_priority", signal_get_priority},
    {"set_priority", signal_set_priority},
    {((void *)0), ((void *)0)}};

// ev_prepare
static int new_prepare(lua_State *L) {
    ev_prepare *w = (ev_prepare *)lua_newuserdata(L, sizeof(*w));
    (lua_getfield(L, (-1000000 - 1000),
                  ("watcher_"
                   "prepare"
                   "_metatable")));
    lua_setmetatable(L, -2);
    return 1;
}
inline static ev_prepare *get_prepare(lua_State *L, int index) {
    ev_prepare *w = (ev_prepare *)luaL_checkudata(L, index,
                                                  "watcher_"
                                                  "prepare"
                                                  "_metatable");
    return w;
}
static int prepare_tostring(lua_State *L) {
    ev_prepare *w = get_prepare(L, 1);
    lua_pushfstring(L, "%s: %p", "prepare", w);
    return 1;
}
static int prepare_id(lua_State *L) {
    ev_prepare *w = get_prepare(L, 1);
    lua_pushlightuserdata(L, (void *)w);
    return 1;
}
static int prepare_start(lua_State *L) {
    ev_prepare *w = get_prepare(L, 1);
    loop_t *lo = get_loop(L, 2);
    ev_prepare_start(lo->loop, w);
    return 1;
}
static int prepare_stop(lua_State *L) {
    ev_prepare *w = get_prepare(L, 1);
    loop_t *lo = get_loop(L, 2);
    ev_prepare_stop(lo->loop, w);
    return 1;
}
static int prepare_is_active(lua_State *L) {
    ev_prepare *w = get_prepare(L, 1);
    lua_pushboolean(L, (0 + ((ev_watcher *)(void *)(w))->active));
    return 1;
}
static int prepare_is_pending(lua_State *L) {
    ev_prepare *w = get_prepare(L, 1);
    lua_pushboolean(L, (0 + ((ev_watcher *)(void *)(w))->pending));
    return 1;
}
static int prepare_get_priority(lua_State *L) {
    ev_prepare *w = get_prepare(L, 1);
    lua_pushinteger(L, (+(((ev_watcher *)(void *)(w))->priority)));
    return 1;
}
static int prepare_set_priority(lua_State *L) {
    ev_prepare *w = get_prepare(L, 1);
    int priority = luaL_checkinteger(L, 2);
    ((ev_watcher *)(void *)(w))->priority = (priority);
    return 0;
}

static int prepare_init(lua_State *L) {
    ev_prepare *w = get_prepare(L, 1);
    do {
        do {
            ((ev_watcher *)(void *)((w)))->active =
                ((ev_watcher *)(void *)((w)))->pending = 0;
            ((ev_watcher *)(void *)(((w))))->priority = (0);
            ((((w)))->cb = ((watcher_cb)),
             memmove(&((ev_watcher *)(((w))))->cb, &(((w)))->cb,
                     sizeof((((w)))->cb)));
        } while (0);
        ;
    } while (0);
    return 0;
}

static const struct luaL_Reg mt_prepare[] = {{"__tostring", prepare_tostring},
                                             {((void *)0), ((void *)0)}};

static const struct luaL_Reg methods_prepare[] = {
    {"id", prepare_id},
    {"start", prepare_start},
    {"stop", prepare_stop},
    {"init", prepare_init},
    {"is_active", prepare_is_active},
    {"is_pending", prepare_is_pending},
    {"get_priority", prepare_get_priority},
    {"set_priority", prepare_set_priority},
    {((void *)0), ((void *)0)}};

// ev_check
static int new_check(lua_State *L) {
    ev_check *w = (ev_check *)lua_newuserdata(L, sizeof(*w));
    (lua_getfield(L, (-1000000 - 1000),
                  ("watcher_"
                   "check"
                   "_metatable")));
    lua_setmetatable(L, -2);
    return 1;
}
inline static ev_check *get_check(lua_State *L, int index) {
    ev_check *w = (ev_check *)luaL_checkudata(L, index,
                                              "watcher_"
                                              "check"
                                              "_metatable");
    return w;
}
static int check_tostring(lua_State *L) {
    ev_check *w = get_check(L, 1);
    lua_pushfstring(L, "%s: %p", "check", w);
    return 1;
}
static int check_id(lua_State *L) {
    ev_check *w = get_check(L, 1);
    lua_pushlightuserdata(L, (void *)w);
    return 1;
}
static int check_start(lua_State *L) {
    ev_check *w = get_check(L, 1);
    loop_t *lo = get_loop(L, 2);
    ev_check_start(lo->loop, w);
    return 1;
}
static int check_stop(lua_State *L) {
    ev_check *w = get_check(L, 1);
    loop_t *lo = get_loop(L, 2);
    ev_check_stop(lo->loop, w);
    return 1;
}
static int check_is_active(lua_State *L) {
    ev_check *w = get_check(L, 1);
    lua_pushboolean(L, (0 + ((ev_watcher *)(void *)(w))->active));
    return 1;
}
static int check_is_pending(lua_State *L) {
    ev_check *w = get_check(L, 1);
    lua_pushboolean(L, (0 + ((ev_watcher *)(void *)(w))->pending));
    return 1;
}
static int check_get_priority(lua_State *L) {
    ev_check *w = get_check(L, 1);
    lua_pushinteger(L, (+(((ev_watcher *)(void *)(w))->priority)));
    return 1;
}
static int check_set_priority(lua_State *L) {
    ev_check *w = get_check(L, 1);
    int priority = luaL_checkinteger(L, 2);
    ((ev_watcher *)(void *)(w))->priority = (priority);
    return 0;
}

static int check_init(lua_State *L) {
    ev_check *w = get_check(L, 1);
    do {
        do {
            ((ev_watcher *)(void *)((w)))->active =
                ((ev_watcher *)(void *)((w)))->pending = 0;
            ((ev_watcher *)(void *)(((w))))->priority = (0);
            ((((w)))->cb = ((watcher_cb)),
             memmove(&((ev_watcher *)(((w))))->cb, &(((w)))->cb,
                     sizeof((((w)))->cb)));
        } while (0);
        ;
    } while (0);
    return 0;
}

static const struct luaL_Reg mt_check[] = {{"__tostring", check_tostring},
                                           {((void *)0), ((void *)0)}};

static const struct luaL_Reg methods_check[] = {
    {"id", check_id},
    {"start", check_start},
    {"stop", check_stop},
    {"init", check_init},
    {"is_active", check_is_active},
    {"is_pending", check_is_pending},
    {"get_priority", check_get_priority},
    {"set_priority", check_set_priority},
    {((void *)0), ((void *)0)}};

// ev_idle
static int new_idle(lua_State *L) {
    ev_idle *w = (ev_idle *)lua_newuserdata(L, sizeof(*w));
    (lua_getfield(L, (-1000000 - 1000),
                  ("watcher_"
                   "idle"
                   "_metatable")));
    lua_setmetatable(L, -2);
    return 1;
}
inline static ev_idle *get_idle(lua_State *L, int index) {
    ev_idle *w = (ev_idle *)luaL_checkudata(L, index,
                                            "watcher_"
                                            "idle"
                                            "_metatable");
    return w;
}
static int idle_tostring(lua_State *L) {
    ev_idle *w = get_idle(L, 1);
    lua_pushfstring(L, "%s: %p", "idle", w);
    return 1;
}
static int idle_id(lua_State *L) {
    ev_idle *w = get_idle(L, 1);
    lua_pushlightuserdata(L, (void *)w);
    return 1;
}
static int idle_start(lua_State *L) {
    ev_idle *w = get_idle(L, 1);
    loop_t *lo = get_loop(L, 2);
    ev_idle_start(lo->loop, w);
    return 1;
}
static int idle_stop(lua_State *L) {
    ev_idle *w = get_idle(L, 1);
    loop_t *lo = get_loop(L, 2);
    ev_idle_stop(lo->loop, w);
    return 1;
}
static int idle_is_active(lua_State *L) {
    ev_idle *w = get_idle(L, 1);
    lua_pushboolean(L, (0 + ((ev_watcher *)(void *)(w))->active));
    return 1;
}
static int idle_is_pending(lua_State *L) {
    ev_idle *w = get_idle(L, 1);
    lua_pushboolean(L, (0 + ((ev_watcher *)(void *)(w))->pending));
    return 1;
}
static int idle_get_priority(lua_State *L) {
    ev_idle *w = get_idle(L, 1);
    lua_pushinteger(L, (+(((ev_watcher *)(void *)(w))->priority)));
    return 1;
}
static int idle_set_priority(lua_State *L) {
    ev_idle *w = get_idle(L, 1);
    int priority = luaL_checkinteger(L, 2);
    ((ev_watcher *)(void *)(w))->priority = (priority);
    return 0;
}

static int idle_init(lua_State *L) {
    ev_idle *w = get_idle(L, 1);
    do {
        do {
            ((ev_watcher *)(void *)((w)))->active =
                ((ev_watcher *)(void *)((w)))->pending = 0;
            ((ev_watcher *)(void *)(((w))))->priority = (0);
            ((((w)))->cb = ((watcher_cb)),
             memmove(&((ev_watcher *)(((w))))->cb, &(((w)))->cb,
                     sizeof((((w)))->cb)));
        } while (0);
        ;
    } while (0);
    return 0;
}

static const struct luaL_Reg mt_idle[] = {{"__tostring", idle_tostring},
                                          {((void *)0), ((void *)0)}};

static const struct luaL_Reg methods_idle[] = {
    {"id", idle_id},
    {"start", idle_start},
    {"stop", idle_stop},
    {"init", idle_init},
    {"is_active", idle_is_active},
    {"is_pending", idle_is_pending},
    {"get_priority", idle_get_priority},
    {"set_priority", idle_set_priority},
    {((void *)0), ((void *)0)}};

// create_metatable_*
static void create_metatable_loop(lua_State *L) {
    if (luaL_newmetatable(L, "loop_metatable")) {
        luaL_setfuncs(L, mt_loop, 0);
        (luaL_checkversion_(L, 503,
                            (sizeof(lua_Integer) * 16 + sizeof(lua_Number))),
         lua_createtable(L, 0,
                         sizeof(methods_loop) / sizeof((methods_loop)[0]) - 1),
         luaL_setfuncs(L, methods_loop, 0));
        lua_setfield(L, -2, "__index");
    }
    lua_settop(L, -(1) - 1);
}
static void create_metatable_io(lua_State *L) {
    if (luaL_newmetatable(L,
                          "watcher_"
                          "io"
                          "_metatable")) {
        luaL_setfuncs(L, mt_io, 0);
        (luaL_checkversion_(L, 503,
                            (sizeof(lua_Integer) * 16 + sizeof(lua_Number))),
         lua_createtable(L, 0,
                         sizeof(methods_io) / sizeof((methods_io)[0]) - 1),
         luaL_setfuncs(L, methods_io, 0));
        lua_setfield(L, -2, "__index");
    }
    lua_settop(L, -(1) - 1);
}
static void create_metatable_timer(lua_State *L) {
    if (luaL_newmetatable(L,
                          "watcher_"
                          "timer"
                          "_metatable")) {
        luaL_setfuncs(L, mt_timer, 0);
        (luaL_checkversion_(L, 503,
                            (sizeof(lua_Integer) * 16 + sizeof(lua_Number))),
         lua_createtable(
             L, 0, sizeof(methods_timer) / sizeof((methods_timer)[0]) - 1),
         luaL_setfuncs(L, methods_timer, 0));
        lua_setfield(L, -2, "__index");
    }
    lua_settop(L, -(1) - 1);
}
static void create_metatable_signal(lua_State *L) {
    if (luaL_newmetatable(L,
                          "watcher_"
                          "signal"
                          "_metatable")) {
        luaL_setfuncs(L, mt_signal, 0);
        (luaL_checkversion_(L, 503,
                            (sizeof(lua_Integer) * 16 + sizeof(lua_Number))),
         lua_createtable(
             L, 0, sizeof(methods_signal) / sizeof((methods_signal)[0]) - 1),
         luaL_setfuncs(L, methods_signal, 0));
        lua_setfield(L, -2, "__index");
    }
    lua_settop(L, -(1) - 1);
}
static void create_metatable_prepare(lua_State *L) {
    if (luaL_newmetatable(L,
                          "watcher_"
                          "prepare"
                          "_metatable")) {
        luaL_setfuncs(L, mt_prepare, 0);
        (luaL_checkversion_(L, 503,
                            (sizeof(lua_Integer) * 16 + sizeof(lua_Number))),
         lua_createtable(
             L, 0, sizeof(methods_prepare) / sizeof((methods_prepare)[0]) - 1),
         luaL_setfuncs(L, methods_prepare, 0));
        lua_setfield(L, -2, "__index");
    }
    lua_settop(L, -(1) - 1);
}
static void create_metatable_check(lua_State *L) {
    if (luaL_newmetatable(L,
                          "watcher_"
                          "check"
                          "_metatable")) {
        luaL_setfuncs(L, mt_check, 0);
        (luaL_checkversion_(L, 503,
                            (sizeof(lua_Integer) * 16 + sizeof(lua_Number))),
         lua_createtable(
             L, 0, sizeof(methods_check) / sizeof((methods_check)[0]) - 1),
         luaL_setfuncs(L, methods_check, 0));
        lua_setfield(L, -2, "__index");
    }
    lua_settop(L, -(1) - 1);
}
static void create_metatable_idle(lua_State *L) {
    if (luaL_newmetatable(L,
                          "watcher_"
                          "idle"
                          "_metatable")) {
        luaL_setfuncs(L, mt_idle, 0);
        (luaL_checkversion_(L, 503,
                            (sizeof(lua_Integer) * 16 + sizeof(lua_Number))),
         lua_createtable(L, 0,
                         sizeof(methods_idle) / sizeof((methods_idle)[0]) - 1),
         luaL_setfuncs(L, methods_idle, 0));
        lua_setfield(L, -2, "__index");
    }
    lua_settop(L, -(1) - 1);
}

struct luaL_Reg ev_module_methods[] = {
    {"version", ev_version},      {"default_loop", default_loop},
    {"new_loop", new_loop},       {"new_io", new_io},
    {"new_timer", new_timer},     {"new_signal", new_signal},
    {"new_prepare", new_prepare}, {"new_check", new_check},
    {"new_idle", new_idle},       {((void *)0), ((void *)0)}};

extern int luaopen_levent_ev_c(lua_State *L) {
    luaL_checkversion_(L, 503, (sizeof(lua_Integer) * 16 + sizeof(lua_Number)));

    // call create metatable
    create_metatable_loop(L);
    create_metatable_io(L);
    create_metatable_timer(L);
    create_metatable_signal(L);
    create_metatable_prepare(L);
    create_metatable_check(L);
    create_metatable_idle(L);

    (luaL_checkversion_(L, 503,
                        (sizeof(lua_Integer) * 16 + sizeof(lua_Number))),
     lua_createtable(
         L, 0, sizeof(ev_module_methods) / sizeof((ev_module_methods)[0]) - 1),
     luaL_setfuncs(L, ev_module_methods, 0));

    // add constant
    _add_unsigned_constant(L, "EV_READ", EV_READ);
    _add_unsigned_constant(L, "EV_WRITE", EV_WRITE);
    ;
    _add_unsigned_constant(L, "EV_TIMER", EV_TIMER);
    ;
    _add_unsigned_constant(L, "EV_PERIODIC", EV_PERIODIC);
    ;
    _add_unsigned_constant(L, "EV_SIGNAL", EV_SIGNAL);
    ;
    _add_unsigned_constant(L, "EV_CHILD", EV_CHILD);
    ;
    _add_unsigned_constant(L, "EV_STAT", EV_STAT);
    ;
    _add_unsigned_constant(L, "EV_IDLE", EV_IDLE);
    ;
    _add_unsigned_constant(L, "EV_PREPARE", EV_PREPARE);
    ;
    _add_unsigned_constant(L, "EV_CHECK", EV_CHECK);
    ;
    _add_unsigned_constant(L, "EV_EMBED", EV_EMBED);
    ;
    _add_unsigned_constant(L, "EV_FORK", EV_FORK);
    ;
    _add_unsigned_constant(L, "EV_CLEANUP", EV_CLEANUP);
    ;
    _add_unsigned_constant(L, "EV_ASYNC", EV_ASYNC);
    ;
    _add_unsigned_constant(L, "EV_CUSTOM", EV_CUSTOM);
    ;
    _add_unsigned_constant(L, "EV_ERROR", EV_ERROR);
    ;

    // break
    _add_unsigned_constant(L, "EVBREAK_ONE", EVBREAK_ONE);
    ;
    _add_unsigned_constant(L, "EVBREAK_ALL", EVBREAK_ALL);
    ;

    // priority
    _add_unsigned_constant(L, "EV_MINPRI", (((0x7f) & 4) ? -2 : 0));
    ;
    _add_unsigned_constant(L, "EV_MAXPRI", (((0x7f) & 4) ? +2 : 0));
    ;
    return 1;
}
