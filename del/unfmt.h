
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

Each C scalar type can be identified by a single ASCII letter.
The letters were selected to match as closely as possible to
either C printf or Python "struct" format specification.

Note that all unsigned ints use uppercase, except size_t. 
There's a good chance this might be changed soon.

               unsys   printf  Python 
    void                AS_VOID     'x'     ---     "x"
    void *              AS_ADDR     'a'     "p"     ---
    void **             AS_ADDRPTR  'A'     "p"     ---

    char                AS_CHAR     'c'     "c"     [†]
    char16_t            AS_CHAR16   'u'     ---     [†]
    char32_t            AS_CHAR32   'U'     ---     [†]
    wchar_t             AS_WCHAR    's'     "lc"    "u"

    _Float16            AS_HALF     'e'     ---     "e"
    float               AS_FLT      'f'     ---     "f"
    double              AS_DBL      'd'     "g"     "d"
    long double         AS_LDBL     'D'     "Lg"    ---
    ---                 AS_BIGFLT   'E'     ---     ---

    _Bool               AS_BOOL     'y'     "i"     "?"

    signed char         AS_CHAR     'b'     "hhi"   "b"
    signed short        AS_SHRT     'h'     "hi"    "h"
    signed int          AS_INT      'i'     "i"     "i"
    signed long         AS_LONG     'l'     "li"    "l"
    signed long long    AS_LLONG    'v'     "lli"   ---
    __int128            AS_XLONG    'm'     ---     ---
    ssize_t             AS_SSIZE    'Z'     "zi"    "n"
    intptr_t            AS_INTPTR   'p'     ---     ---
    ptrdiff_t           AS_PTRDIFF  't'     "td"    ---
    int8_t              AS_INT8     'b'     PRIi8   "b"
    int16_t             AS_INT16    'h'     PRIi16  "h"
    int32_t             AS_INT32    'i'     PRIi32  "i"
    int64_t             AS_INT64    'q'     PRIi64  "q"
    intmax_t            AS_INTMAX   'j'     "ji"    ---

    unsigned char       AS_UCHAR    'B'     "hhi"   "b"
    unsigned short      AS_USHRT    'H'     "hi"    "h"
    unsigned int        AS_UINT     'I'     "i"     "i"
    unsigned long       AS_ULONG    'L'     "lu"    "l"
    unsigned long long  AS_ULLONG   'V'     "llu"   ---
    unsigned __int128   AS_XLONG    'M'     ---     ---
    size_t              AS_SIZE     'z'     "zu"    "N"
    uintptr_t           AS_UINTPTR  'P'     ---     "P' 
    uint8_t             AS_UINT8    'B'     PRIi8   "B"
    uint16_t            AS_UINT16   'H'     PRIi16  "H"
    uint32_t            AS_UINT32   'I'     PRIi32  "I"
    uint64_t            AS_UINT64   'Q'     PRIi64  "Q"
    uintmax_t           AS_UINTMAX  'J'     "ju"    ---

    wint_t              AS_WINT     'C'     "C"     ---
    ---                 AS_BIGINT   'Y'     ---     [‡]

    [†] An extraordinary amount of effort has gone into making
        sure Python's Unicode strings are impossible to confuse 
        with bytes

    [‡] PyLongObject is a 15/30 bit digit "bigint" type 


*/
#pragma once

/* Keep these in pairs until the MSVC charizing op is std */

#define    VOID_FMT 'x'
#define    VOID_VAR  x

#define    ADDR_FMT 'a'
#define    ADDR_VAR  a

#define ADDRPTR_FMT 'A'
#define ADDRPTR_VAR  A

#define  OBJECT_FMT 'o'
#define  OBJECT_VAR  o

#define    HALF_FMT 'e'
#define    HALF_VAR  e

#define     FLT_FMT 'f'
#define     FLT_VAR  f

#define     DBL_FMT 'd'
#define     DBL_VAR  d

#define    LDBL_FMT 'D'
#define    LDBL_VAR  D

#define  BIGFLT_FMT 'E'
#define  BIGFLT_VAR  E

#define    CHAR_FMT 'c'
#define    CHAR_VAR  c

#define   WCHAR_FMT 's'
#define   WCHAR_VAR  s

#define  CHAR16_FMT 'u'
#define  CHAR16_VAR  u

#define  CHAR32_FMT 'U'
#define  CHAR32_VAR  U

#define    WINT_FMT 'C'
#define    WINT_VAR  C 

#define  BIGINT_FMT 'Y'
#define  BIGINT_VAR  Y

#define    BOOL_FMT 'y'
#define    BOOL_VAR  y

#define   SCHAR_FMT 'b'
#define   SCHAR_VAR  b

#define    SHRT_FMT 'h'
#define    SHRT_VAR  h

#define     INT_FMT 'i'
#define     INT_VAR  i

#define    LONG_FMT 'l'
#define    LONG_VAR  l

#define   LLONG_FMT 'v'
#define   LLONG_VAR  v

#define   XLONG_FMT 'm'
#define   XLONG_VAR  m

#define   SSIZE_FMT 'Z'
#define   SSIZE_VAR  Z

#define PTRDIFF_FMT 't'
#define PTRDIFF_VAR  t

#define  INTPTR_FMT 'p'
#define  INTPTR_VAR  p

#define    INT8_FMT SCHAR_FMT
#define    INT8_VAR SCHAR_VAR

#define   INT16_FMT SHRT_FMT
#define   INT16_VAR SHRT_VAR

#define   INT32_FMT INT_FMT
#define   INT32_VAR INT_VAR

#define   INT64_FMT 'q'
#define   INT64_VAR  q

#define  INTMAX_FMT 'j'
#define  INTMAX_VAR  j

#define   UCHAR_FMT 'B'
#define   UCHAR_VAR  B

#define   USHRT_FMT 'H'
#define   USHRT_VAR  H

#define    UINT_FMT 'I'
#define    UINT_VAR  I

#define   ULONG_FMT 'L'
#define   ULONG_VAR  L

#define  ULLONG_FMT 'v'
#define  ULLONG_VAR  V

#define  UXLONG_FMT 'M'
#define  UXLONG_VAR  M

#define    SIZE_FMT 'z'
#define    SIZE_VAR  z

#define UINTPTR_FMT 'P'
#define UINTPTR_VAR  P

#define   UINT8_FMT UCHAR_FMT
#define   UINT8_VAR UCHAR_VAR

#define  UINT16_FMT USHRT_FMT
#define  UINT16_VAR USHRT_VAR

#define  UINT32_FMT UINT_FMT
#define  UINT32_VAR INT_VAR

#define  UINT64_FMT 'Q'
#define  UINT64_VAR  Q

#define UINTMAX_FMT 'J'
#define UINTMAX_VAR  J

