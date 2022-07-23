
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

#pragma once

#include <limits.h>
#include <unistd.h>

#include "unstddef.h"
#include "wstring.h"

static_assert( CHAR_BIT == 8,           "CHAR_BIT != 8");
static_assert(UCHAR_MAX == 0x000000FFU, "UCHAR_MAX != 0xFFU");
static_assert(USHRT_MAX == 0x0000FFFFU, "USHRT_MAX != 0xFFFFU");
static_assert( UINT_MAX == 0xFFFFFFFFU, "UINT_MAX != 0xFFFFFFFFU");
static_assert(
    (UINTMAX_MAX == 0xFFFFFFFFFFFFFFFFULL)
&&  (ULLONG_MAX == UINTMAX_MAX),
    "ULLONG_MAX > expected to be 64 bits wide");
static_assert(SCHAR_MAX == 0x0000007F,  "SCHAR_MAX != 0x7F");
static_assert( SHRT_MAX == 0x00007FFF,  "SHRT_MAX != 0x7FFF");
static_assert(  INT_MAX == 0x7FFFFFFF,  "INT_MAX != 0x7FFFFFFF");

/* Do NOT reorder these */
enum {
#if   (_POSIX_V7_ILP32_OFFBIG > 0)
    C__LP32=1,
#elif (_POSIX_V7_LP64_OFF64 > 0)
    C__LP64=1,
#elif (_WIN64) 
    C__IL32=1,
#elif (_WIN32)
    C__LP32=1,
#elif  (_POSIX_V7_ILP32_OFF32 > 0) || (_POSIX_V7_LPBIG_OFFBIG > 0)
#   error "unsupported C data model"
#else
#   error "compiler missing data model macro definitions"
#endif

#if   !defined(WINT_MAX)
#   error "missing WINT_MAX definition"

#elif !defined(WINT_MIN)
#   error "missing WINT_MIN definition"

#elif !defined(WCHAR_MIN)
#   error "missing WCHAR_MIN definition"

#elif !defined(WCHAR_MAX) 
#   error "missing WCHAR_MAX definition"

#elif !defined(SIG_ATOMIC_MAX)
#   error "missing SIG_ATOMIC_MAX definition"

#elif !defined(SIG_ATOMIC_MIN)
#   error "missing SIG_ATOMIC_MIN definition"
#endif

#if !defined(BOOL_WIDTH)
#   define BOOL_WIDTH       1
#   define CHAR_WIDTH       8
#   define UCHAR_WIDTH      8
#   define SCHAR_WIDTH      8
#   define SHRT_WIDTH       16
#   define USHRT_WIDTH      16
#   define INT_WIDTH        32
#   define UINT_WIDTH       32 
#   define LLONG_WIDTH      64
#   define ULLONG_WIDTH     64
#   define INTMAX_WIDTH     64
#   define UINTMAX_WIDTH    64
#   if   (0 < C__LP64)
#       define PTRDIFF_WIDTH    64
#       define SIZE_WIDTH       64
#       define LONG_WIDTH       64
#       define ULONG_WIDTH      64
#       define INTPTR_WIDTH     64
#       define UINTPTR_WIDTH    64
#   elif (0 < C__IL32)
#       define PTRDIFF_WIDTH    64
#       define SIZE_WIDTH       64
#       define INTPTR_WIDTH     64
#       define UINTPTR_WIDTH    64
#       define LONG_WIDTH       32 
#       define ULONG_WIDTH      32 
#   else
#       define PTRDIFF_WIDTH    32
#       define SIZE_WIDTH       32
#       define INTPTR_WIDTH     32
#       define UINTPTR_WIDTH    32
#       define LONG_WIDTH       32 
#       define ULONG_WIDTH      32 
#   endif

#   if  WCHAR_MAX == UINT_MAX
#       define WCHAR_WIDTH      UINT_WIDTH
#   elif WCHAR_MAX == USHRT_MAX
#       define WCHAR_WIDTH      USHRT_WIDTH
#   elif WCHAR_MAX == UCHAR_MAX
#       define WCHAR_WIDTH      UCHAR_WIDTH
#   elif WCHAR_MAX == INT_MAX
#       define WCHAR_WIDTH      INT_WIDTH
#   elif WCHAR_MAX == SHRT_MAX
#       define WCHAR_WIDTH      SHRT_WIDTH
#   elif WCHAR_MAX == SCHAR_MAX
#       define WCHAR_WIDTH      SCHAR_WIDTH
#   else
#       error "unable to guess WCHAR_WIDTH from WCHAR_MAX"
#   endif

#   if WINT_MAX == UINT_MAX
#       define WINT_WIDTH UINT_WIDTH
#   elif WINT_MAX == INT_MAX
#       define WINT_WIDTH INT_WIDTH
#   else
#       error "unable to guess WINT_WIDTH from WINT_MAX"
#   endif

#   if (!SIG_ATOMIC_MIN)
#       if   (SIG_ATOMIC_MAX == UINT8_MAX)
#           define SIG_ATOMIC_WIDTH 8
#       elif (SIG_ATOMIC_MAX == UINT16_MAX)
#           define SIG_ATOMIC_WIDTH 16
#       elif (SIG_ATOMIC_MAX == UINT32_MAX)
#           define SIG_ATOMIC_WIDTH 32
#       elif (SIG_ATOMIC_MAX) == UINT64_MAX)
#           define SIG_ATOMIC_WIDTH 64
#       endif
#   elif (SIG_ATOMIC_MAX ==  INT8_MAX)
#       define SIG_ATOMIC_WIDTH 8
#   elif (SIG_ATOMIC_MAX ==  INT16_MAX)
#       define SIG_ATOMIC_WIDTH 16
#   elif (SIG_ATOMIC_MAX ==  INT32_MAX)
#       define SIG_ATOMIC_WIDTH 32
#   elif (SIG_ATOMIC_MAX ==  INT64_MAX)
#       define SIG_ATOMIC_WIDTH 64
#   endif

#   ifndef SIG_ATOMIC_WIDTH
#       error("can't determine SIG_ATOMIC_WIDTH automatically")
#   endif

#   define         INT8_WIDTH    8
#   define        UINT8_WIDTH    8
#   define        INT16_WIDTH   16
#   define       UINT16_WIDTH   16
#   define        INT32_WIDTH   32
#   define       UINT32_WIDTH   32
#   define        INT64_WIDTH   64
#   define       UINT64_WIDTH   64
#   define   INT_LEAST8_WIDTH    8
#   define  UINT_LEAST8_WIDTH    8
#   define  INT_LEAST16_WIDTH   16
#   define UINT_LEAST16_WIDTH   16
#   define  INT_LEAST32_WIDTH   32
#   define UINT_LEAST32_WIDTH   32
#   define  INT_LEAST64_WIDTH   64
#   define UINT_LEAST64_WIDTH   64
/*  NOTE:
    The INT_FASTN_MIN/MAX macros are worse than 
    useless. DO NOT USE THEM OR THE _WIDTH CONSTANTS 
    DERIVED FROM THEM */
#   if         UINT_FAST8_MAX == 0xFFU
#       define UINT_FAST8_WIDTH 8
#       define  INT_FAST8_WIDTH 8
#   elif       UINT_FAST8_MAX == 0xFFFFU
#       define UINT_FAST8_WIDTH 16
#       define  INT_FAST8_WIDTH 16
#   elif       UINT_FAST8_MAX == 0xFFFFFFFFU
#       define UINT_FAST8_WIDTH 32
#       define  INT_FAST8_WIDTH 32
#   elif       UINT_FAST8_MAX == 0xFFFFFFFFFFFFFFFFULL
#       define UINT_FAST8_WIDTH 64
#       define  INT_FAST8_WIDTH 64
#   else
#       error "couldn't guess INT_FAST8_WIDTH"
#   endif

#   if         UINT_FAST16_MAX == UINT16_MAX
#       define UINT_FAST16_WIDTH    16
#       define  INT_FAST16_WIDTH    16
#   elif       UINT_FAST16_MAX == UINT32_MAX
#       define UINT_FAST16_WIDTH    32
#       define  INT_FAST16_WIDTH    32
#   elif       UINT_FAST16_MAX == UINT64_MAX
#       define UINT_FAST16_WIDTH    64
#       define  INT_FAST16_WIDTH    64
#   else
#       error "couldn't guess INT_FAST16_WIDTH"
#   endif
#   if         UINT_FAST32_MAX == UINT32_MAX
#       define UINT_FAST32_WIDTH    32
#       define  INT_FAST32_WIDTH    32
#   elif       UINT_FAST32_MAX == UINT64_MAX
#       define UINT_FAST32_WIDTH    64
#       define  INT_FAST32_WIDTH    64
#   else
#       error "couldn't guess INT_FAST32_WIDTH"
#   endif
#   if         UINT_FAST64_MAX == UINT64_MAX
#       define  INT_FAST64_WIDTH    64
#       define UINT_FAST64_WIDTH    64
#   else
#       error "couldn't guess INT_FAST64_WIDTH"
#   endif
#endif
};
