
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

#pragma once 

#include <assert.h>
#include <float.h>
#include <sys/types.h>
#include <float.h>
#include <iso646.h>
#include <stdalign.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdnoreturn.h>

#ifndef static_assert
#define static_assert _Static_assert
#endif

// #include <uchar.h>
// #include <wchar.h>

typedef                     _Bool    bit_t;
typedef                      char   char_t;
typedef               signed char  schar_t;
typedef             unsigned char  uchar_t;
typedef       short   signed int   short_t;
typedef       short unsigned int  ushort_t;
typedef               signed int     int_t;
typedef             unsigned int    uint_t;
typedef        long   signed int    long_t;
typedef        long unsigned int   ulong_t;
typedef        long   signed long  llong_t;
typedef        long unsigned long ullong_t;
typedef        long   double     ldouble_t;
typedef const                void   void_c;
typedef const               _Bool    bit_c;
typedef const                char   char_c;
typedef const         signed char  schar_c;
typedef const       unsigned char  uchar_c;
typedef const short   signed  int  short_c;
typedef const short unsigned  int ushort_c;
typedef const         signed  int    int_c;
typedef const       unsigned  int   uint_c;
typedef const long    signed  int   long_c;
typedef const long  unsigned  int  ulong_c;
typedef const long    signed long  llong_c;
typedef const long  unsigned long ullong_c;
typedef const          float       float_c;
typedef const         double      double_c;
typedef const long    double     ldouble_c;
typedef const      uintmax_t     uintmax_c;
typedef const       intmax_t      intmax_c;
typedef const      uintptr_t     uintptr_c;
typedef const       intptr_t      intptr_c;
typedef const      ptrdiff_t     ptrdiff_c;
typedef const        ssize_t       ssize_c;
typedef const         size_t        size_c;

typedef struct {
    int         k;
    union {
        unsigned u;
        signed   s;
    };
} kw_t;

typedef signed
    errno_t, // type of an E[A-Z]+
    signo_t, // type of SIG[A-Z]+ consts
    nchar_t, // return type of printf() etc
    fileno_t; // return type of fileno()

typedef unsigned hash_t; // type of hash values

#define UN_HASHED 0xFFFFFFFFU
union hashstate {
    struct {
        uint16_t a;
        uint32_t b;
    };
    uint64_t v;
};
union unchar;
union unshort;
union unint;
union unlong;
union unllong;
union unfloat;
union undouble;
union undouble;

typedef union unfloat {
    char    b[sizeof(float)];
    float   f;
} unfloat_t;

typedef union undouble {
    char    b[sizeof(double)];
    double  f;
} undouble_t;

typedef union unldouble {
    char        b[sizeof(long double)];
    long double f;
} unldouble_t;

typedef union unbyte {
    char            c[1];
    unsigned char   u;
    signed   char   s;
} unbyte_t;

typedef union unshort {
    char           c[2];
    union unbyte   b[2];
    unsigned short u;
    signed   short s;
} unshort_t;

typedef union unint {
    char            c[4];
    union unbyte    b[4];
    union unshort   h[2];
    //union unint     i[1];
    unsigned  int   u;
    signed    int   s;
} unint_t;

typedef union unlong {
    char            c[sizeof(long)];
    union unbyte    b[sizeof(long)/1U];
    union unshort   h[sizeof(long)/2U];
    union unint     i[sizeof(long)/4U];
    //union unlong    l[1];
    unsigned long   u;
    signed   long   s;
} unlong_t;

typedef union unllong {
    char                c[sizeof(long long)];
    union unbyte        b[sizeof(long long)/1U];
    union unshort       h[sizeof(long long)/2U];
    union unint         i[sizeof(long long)/4U];
    union unlong        l[sizeof(long long)/sizeof(long)];
    unsigned long long  u;
    signed   long long  s;
} unllong_t;

typedef union unindex {
    char            c[sizeof(void *)];
    void           *p;
    size_t          z;
    ptrdiff_t       t;
    intptr_t        s;
    uintptr_t       u;
} unindex_t;

typedef union unpointer {
    void                *void_p;
    void                *void_pp;
    intptr_t            i;
    uintptr_t           u;
    ptrdiff_t           t;
    size_t              z;
    _Bool               *bool_p;
    _Bool              **bool_pp;
    char                *char_p;
    char               **char_pp;
    unsigned char       *uchar_p;
    signed   char       *schar_p;
    unsigned short      *ushort_p;
    unsigned int        *uint_p;
    unsigned long       *ulong_p;
    unsigned long long  *ullong_p;
    signed int          *int_p;
    signed long         *long_p;
    signed long long    *llong_p;
    wchar_t             *wchar_p;
    size_t              *size_p;
    ptrdiff_t           *ptrdiff_p;
    intptr_t            *intptr_p;
    uintptr_t           *uintptr_p;
    intmax_t            *intmax_p;
    uintmax_t           *uintmax_p;
    float               *float_p;
    double              *double_p;
    long double         *ldouble_p;
} unpointer_t;

/*


struct memry {
    union {
        union {
            void       *p;
            intptr_t    i;
            uintptr_t   u;
        } addr;
        char        *c;
        wchar_t     *wcs;
        uchar_t     *uhh;
        schar_t     *hh;
        short_t     *h;
        ushort_t    *uh;
        uint_t      *u;
        int_t       *i;
        long_t      *l;
        llong_t     *ll;
        ullong_t    *ull;
        intmax_t    *j;
        uintmax_t   *uj;
        size_t      *z;
        ptrdiff_t   *t;
        intptr_t    *sp;
        uintptr_t   *up;
        _Bool       *bp;
        clockid_t   *clockid_p;
        clock_t     *clock_p;
        dev_t       *dev_p;
        time_t      *time_p;
        id_t        *id_p;
        gid_t       *gid_p;
        uid_t       *uid_p;
        pid_t       *pid_p;
        ino_t       *ino_p;
        mode_t      *mode_p;
        off_t       *off_p;
    };
    struct {
        union {
            unsigned attr;
            struct {
                unsigned 
                    dur:            4,
                    is_r:           1,
                    is_x:           1,
                    is_w:           1,
                    is_ascii:       1, 
                    is_fixed:       1,
                    is_hashed:      1,
                    is_locked:      1,
                    :               0;
            };
        };
        union {
            hash_t hash;
        };
        union {
            size_t      u;
            ptrdiff_t   s;
        } size;
    };
};
*/

