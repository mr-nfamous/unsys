
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

#pragma once

#include <uchar.h>
#include <wchar.h>

/*
    #include <ctype.h>
    #include <string.h>
    #include <stdarg.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
*/
typedef const wchar_t   wchar_c;
typedef const wint_t    wint_c;
typedef const char16_t  char16_c;
typedef const char32_t  char32_c;

typedef struct {
    union {
        void        *uc_data;
        char        *uc_1;
        char16_t    *uc_2;
        char32_t    *uc_4; 
    };
    union {
        unsigned ob_flags;
        unsigned 
            ob_type:    16,
            ob_dtor:    4,  // DTOR_AUTO, DTOR_FREE, DTOR_MMAP
            readonly:   1,  // entire string unwritable 
            has_hash:   1,  // valid ob_hash 
            has_size:   1,  // valid ob_size 
            :           0;
    };
    hash_t    ob_hash;  // string's hash code
    size_t    ob_size;  // length in bytes of chrs field 
    unsigned  uc_size;  // number of code points in string 
    union {
        unsigned uc_flags;
        unsigned 
            has_data:   1,  // valid uc_data
            has_nchr:   1,  // valid uc_size 
            has_cmax:   1,  // valid cmax 
            uc_dtor:    4,  // uc_data destructor
            cmax:       21, // wide enough enough for [0x0..0x10FFFF+1]
            :           0;
    };
}   unstr_t;

typedef struct {
    char32_t   *dst; // decoded array of code points
    char       *src; // encoded array of bytes
    size_t      len; // 
    char        err; //
    bool        eof; // encoding/decoding complete 
} unmbs_t;

#include "ununicode.h"