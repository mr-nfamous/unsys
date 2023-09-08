
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
/* 
Definitions UNPTR_BODY, UNVAL_BODY, unref_t etc

Types:
    unptr_t: a union whose menbers include all builtin pointer 
    types as *_VAR. e.g., (unptr_t){.CHAR_VAR=0} sets the "c" 
    member to NULL, since the CHAR_VAR macro expands to "c"
    (without quotes, obviously)
  
    unref_t: identical to unptr_t except that all pointer 
    members are const qualified.
    
    unval_t: like unptr_t but the members are not pointers.
    
    All three types have the following writable member:
        unsigned char rval[sizeof(<the type>)];

    Both pointer types have the following writable members:
        intptr_t sval;
        uintptr_t uval;
    
Macros:

    NOTE: all of the following include "unsigned char rval[]"
    members of the corresponding size. This means that the 
    following would be invalid:

        struct {
            UNBOOL_BODY
            UNCHAR_BODY
        }
    (Also, all end in a semicolon)


    UNPTR_BODY: expands to the members of the previously
    mentioned unptr_t union (without braces). In fact, that
    type is exactly defined as 

        typedef union {UNPTR_BODY} unptr_t;
        

    The following two are Like UNPTR_BODY, but for unref_t
    and unval_t:
    
        UNREF_BODY
        UNVAL_BODY



    UNBOOL_BODY expands to "_Bool yval; unsigned char uval;"


    The following expand to the signed variant as sval and 
    to the unsigned variant as uval:
        UNCHAR_BODY
        UNSHRT_BODY
        UNINT_BODY
        UNLONG_BODY
        UNLLONG_BODY
        UNSIZE_BODY
        UNINTPTR_BODY
        UNINT8_BODY
        UNINT16_BODY
        UNINT32_BODY
        UNINT64_BODY
        UNINTMAX_BODY
        UNPTRDIFF_BODY (no unsigned variant)

    The following expand to the corresponding type as "fval":
        UNFLT_BODY
        UNDBL_BODY
        UNLDBL_BODY

*/
#pragma once

#include "unfmt.h"

#define UNPTR_BODY \
    void *                     ADDR_VAR;\
    void **                 ADDRPTR_VAR;\
    char *                     CHAR_VAR;\
    wchar_t *                 WCHAR_VAR;\
    char16_t *               CHAR16_VAR;\
    char32_t *               CHAR32_VAR;\
    float *                     FLT_VAR;\
    double *                    DBL_VAR;\
    long double *              LDBL_VAR;\
    _Bool *                    BOOL_VAR;\
    signed char *             SCHAR_VAR;\
    signed short int *         SHRT_VAR;\
    signed int *                INT_VAR;\
    signed long int *          LONG_VAR;\
    signed long long *        LLONG_VAR;\
    ssize_t *                 SSIZE_VAR;\
    intptr_t *               INTPTR_VAR;\
    ptrdiff_t *             PTRDIFF_VAR;\
    int64_t *                 INT64_VAR;\
    intmax_t *               INTMAX_VAR;\
    unsigned char *           UCHAR_VAR;\
    unsigned short int *      USHRT_VAR;\
    unsigned int *             UINT_VAR;\
    unsigned long int  *      ULONG_VAR;\
    unsigned long long *     ULLONG_VAR;\
    size_t *                   SIZE_VAR;\
    uintptr_t *             UINTPTR_VAR;\
    uint64_t *               UINT64_VAR;\
    uintmax_t *             UINTMAX_VAR;\
    void *                   BIGINT_VAR;\
    wint_t *                   WINT_VAR;\
    uintptr_t       uval;               \
    intptr_t        sval;               \
    unsigned char   rval[sizeof(void *)];

#define UNREF_BODY \
    const void *                     ADDR_VAR;\
    const void **                 ADDRPTR_VAR;\
    const char *                     CHAR_VAR;\
    const wchar_t *                 WCHAR_VAR;\
    const char16_t *               CHAR16_VAR;\
    const char32_t *               CHAR32_VAR;\
    const float *                     FLT_VAR;\
    const double *                    DBL_VAR;\
    const long double *              LDBL_VAR;\
    const _Bool *                    BOOL_VAR;\
    const signed char *             SCHAR_VAR;\
    const signed short int *         SHRT_VAR;\
    const signed int *                INT_VAR;\
    const signed long int *          LONG_VAR;\
    const signed long long *        LLONG_VAR;\
    const ssize_t *                 SSIZE_VAR;\
    const intptr_t *               INTPTR_VAR;\
    const ptrdiff_t *             PTRDIFF_VAR;\
    const int64_t *                 INT64_VAR;\
    const intmax_t *               INTMAX_VAR;\
    const unsigned char *           UCHAR_VAR;\
    const unsigned short int *      USHRT_VAR;\
    const unsigned int *             UINT_VAR;\
    const unsigned long int  *      ULONG_VAR;\
    const unsigned long long *     ULLONG_VAR;\
    const size_t *                   SIZE_VAR;\
    const uintptr_t *             UINTPTR_VAR;\
    const uint64_t *               UINT64_VAR;\
    const uintmax_t *             UINTMAX_VAR;\
    const void *                   BIGINT_VAR;\
    const wint_t *                   WINT_VAR;\
    uintptr_t       uval;               \
    intptr_t        sval;               \
    unsigned char   rval[sizeof(void *)];

#define UNVAL_BODY \
    unsigned char  rval[sizeof(long double)];\
    void *                     ADDR_VAR;\
    void **                 ADDRPTR_VAR;\
    char                       CHAR_VAR;\
    wchar_t                   WCHAR_VAR;\
    char16_t                 CHAR16_VAR;\
    char32_t                 CHAR32_VAR;\
    float                       FLT_VAR;\
    double                      DBL_VAR;\
    long double                LDBL_VAR;\
    _Bool                      BOOL_VAR;\
    signed char               SCHAR_VAR;\
    signed short int           SHRT_VAR;\
    signed int                  INT_VAR;\
    signed long int            LONG_VAR;\
    signed long long          LLONG_VAR;\
    ssize_t                   SSIZE_VAR;\
    intptr_t                 INTPTR_VAR;\
    ptrdiff_t               PTRDIFF_VAR;\
    int64_t                   INT64_VAR;\
    intmax_t                 INTMAX_VAR;\
    unsigned char             UCHAR_VAR;\
    unsigned short int        USHRT_VAR;\
    unsigned int               UINT_VAR;\
    unsigned long int         ULONG_VAR;\
    unsigned long long       ULLONG_VAR;\
    size_t                     SIZE_VAR;\
    uintptr_t               UINTPTR_VAR;\
    uint64_t                 UINT64_VAR;\
    uintmax_t               UINTMAX_VAR;\
    void *                   BIGINT_VAR;\
    wint_t                     WINT_VAR;


#define UNBOOL_BODY \
    unsigned char   rval[sizeof(_Bool)];\
    _Bool           yval;\
    _Bool           uval;

#define UNCHAR_BODY \
    unsigned char   rval[sizeof(char)];\
    char            cval;\
    unsigned char   uval;\
    signed   char   sval;

#define UNWCHAR_BODY \
    unsigned char   rval[sizeof(wchar_t)];\
    wchar_t         cval;

#define UNCHAR16_BODY \
    unsigned char   rval[sizeof(char16_t)];\
    char16_t        cval;

#define UNCHAR32_BODY \
    unsigned char   rval[sizeof(char32_t)];\
    char32_t        cval;

#define UNSHRT_BODY \
    unsigned char   rval[sizeof(short)];\
    unsigned short  uval;\
    signed short    sval;

#define UNINT_BODY \
    unsigned char   rval[sizeof(int)];\
    unsigned        uval;\
    signed          sval;

#define UNLONG_BODY \
    unsigned char       rval[sizeof(signed long int)];\
    unsigned long int   uval;\
    signed   long int   sval;

#define UNLLONG_BODY \
    unsigned char       rval[sizeof(signed long long)];\
    unsigned long long  uval;\
    signed   long long  sval;

#define UNSIZE_BODY \
    signed char         rval[sizeof(size_t)];\
    size_t              uval;\
    ssize_t             sval;

#define UNINTMAX_BODY \
    signed char         rval[sizeof(intmax_t)];\
    intmax_t            sval;\
    uintmax_t           uval;

#define UNPTRDIFF_BODY \
    signed char         rval[sizeof(ptrdiff_t)];\
    ptrdiff_t           sval;

#define UNWINT_BODY \
    signed char         rval[sizeof(wint_t)];\
    wint_t              ival;

#define UNFLT_BODY \
    unsigned char       rval[sizeof(float)];\
    float               fval;

#define UNDBL_BODY \
    unsigned char       rval[sizeof(double)];\
    double              fval;

#define UNLDBL_BODY \
    unsigned char       rval[sizeof(long double)];\
    long double         fval;

#define UNINT8_BODY \
    unsigned char       rval[sizeof(int8_t)];\
    int8_t              sval;\
    uint8_t             uval;

#define UNINT16_BODY \
    unsigned char       rval[sizeof(int16_t)];\
    int16_t             sval;\
    uint16_t            uval;    

#define UNINT32_BODY \
    unsigned char       rval[sizeof(int32_t)];\
    int32_t             sval;\
    uint32_t            uval;

#define UNINT64_BODY \
    unsigned char       rval[sizeof(int64_t)];\
    int64_t             sval;\
    uint64_t            uval;

#define UNINT128_BODY \
    unsigned char       rval[16];\
    uint64_t            wval[4];
    
typedef union unbool       {UNBOOL_BODY}       unbool_t;
typedef union unchar       {UNCHAR_BODY}       unchar_t;
typedef union unshort      {UNSHRT_BODY}      unshort_t;
typedef union unint         {UNINT_BODY}        unint_t;
typedef union unlong       {UNLONG_BODY}       unlong_t;
typedef union unllong     {UNLLONG_BODY}      unllong_t;
typedef union unint8       {UNINT8_BODY}       unint8_t;
typedef union unint16     {UNINT16_BODY}      unint16_t;
typedef union unint32     {UNINT32_BODY}      unint32_t;
typedef union unint64     {UNINT64_BODY}      unint64_t;
typedef union unint128   {UNINT128_BODY}     unint128_t;
typedef union unsize       {UNSIZE_BODY}       unsize_t;
typedef union unintmax   {UNINTMAX_BODY}     unintmax_t;
typedef union unptrdiff {UNPTRDIFF_BODY}    unptrdiff_t;
typedef union unwint       {UNWINT_BODY}       unwint_t;
typedef union unptr         {UNPTR_BODY}        unptr_t;
typedef union unref         {UNREF_BODY}        unref_t;
typedef union unval         {UNVAL_BODY}        unval_t;

#define FLT_MANT_LEN 23
#define FLT_EXPO_LEN 8
#define FLT_SIGN_LEN 1

#define FLT_MANT_OFF 0
#define FLT_EXPO_OFF (FLT_MANT_OFF+FLT_MANT_LEN)
#define FLT_SIGN_OFF (FLT_EXPO_OFF+FLT_EXPO_LEN)

#define FLT_MANT_SIG ((UINT32_C(1)<<FLT_MANT_LEN)-1)
#define FLT_EXPO_SIG ((UINT32_C(1)<<FLT_EXPO_LEN)-1)
#define FLT_SIGN_SIG ((UINT32_C(1)<<FLT_SIGN_LEN)-1)

#define FLT_MANT_AND (FLT_MANT_SIG<<FLT_MANT_OFF)
#define FLT_EXPO_AND (FLT_EXPO_SIG<<FLT_EXPO_OFF)
#define FLT_SIGN_AND (FLT_SIGN_SIG<<FLT_SIGN_OFF)

#define FLT_MANT_XOR (UINT32_MAX^FLT_MANT_AND)
#define FLT_EXPO_XOR (UINT32_MAX^FLT_EXPO_AND)
#define FLT_SIGN_XOR (UINT32_MAX^FLT_SIGN_AND)

#define DBL_MANT_LEN 23
#define DBL_EXPO_LEN 8
#define DBL_SIGN_LEN 1

#define DBL_MANT_OFF 0
#define DBL_EXPO_OFF (DBL_MANT_OFF+DBL_MANT_LEN)
#define DBL_SIGN_OFF (DBL_EXPO_OFF+DBL_EXPO_LEN)

#define DBL_MANT_SIG ((UINT32_C(1)<<DBL_MANT_LEN)-1)
#define DBL_EXPO_SIG ((UINT32_C(1)<<DBL_EXPO_LEN)-1)
#define DBL_SIGN_SIG ((UINT32_C(1)<<DBL_SIGN_LEN)-1)

#define DBL_MANT_AND (DBL_MANT_SIG<<DBL_MANT_OFF)
#define DBL_EXPO_AND (DBL_EXPO_SIG<<DBL_EXPO_OFF)
#define DBL_SIGN_AND (DBL_SIGN_SIG<<DBL_SIGN_OFF)

#define DBL_MANT_XOR (UINT32_MAX^DBL_MANT_AND)
#define DBL_EXPO_XOR (UINT32_MAX^DBL_EXPO_AND)
#define DBL_SIGN_XOR (UINT32_MAX^DBL_SIGN_AND)

/*
#define UNSYS_BOOL32_GETTER(_ATTR) GET_##_ATTR(const void *x) {\
    return (((uint32_t *) x))[0]&(_ATTR##_AND);
}

#define UNSYS_UINT32_GETTER(_ATTR) GET_##_ATTR(const void *x) {\
    return (((uint32_t *) x)[0]&(_ATTR##_AND))>>(_ATTR##_OFF);\
}

#define UNSYS_BOOL32_SETTER(_ATTR) SET_##_ATTR(void *x, _Bool v) {\
    if (v) ((uint32_t *) x)[0] |= (_ATTR##_AND);\
    else   ((uint32_t *) x)[0] &= (_ATTR##_XOR);\
}

#define UNSYS_UINT32_SETTER(_ATTR) SET_##_ATTR(void *x, uint32_t v) {\
    ((uint32_t *) x)[0] &= ((v&(_ATTR##_SIG))<<(_ATTR##_OFF))|(_ATTR##_XOR);\
}
*/


#define UNSYS_BOOL_GETTER(ATTR, TYPE) \
static inline _Bool GET_##ATTR(const void *op) {\
    return (*(TYPE *) op)&ATTR##_AND;\
}

#define UNSYS_UINT_GETTER(ATTR, TYPE) \
static inline TYPE GET_##ATTR(const void *op) {\
    return ((*(TYPE *) op)&ATTR##_AND)>>ATTR##_OFF;\
}

#define UNSYS_BOOL_SETTER(ATTR, TYPE) \
static inline void SET_##ATTR(void *op, _Bool v) {\
    if (v) {(*(TYPE *) op) |= ATTR##_AND;}\
    else   {(*(TYPE *) op) &= ATTR##_XOR;}\
}

#define UNSYS_UINT_SETTER(ATTR, TYPE) \
static inline void SET_##ATTR(void *op, TYPE v) {\
    (*(TYPE *) op) = ((*(TYPE *) op)&ATTR##_XOR)|(v<<ATTR##_OFF);\
}

UNSYS_BOOL_GETTER(FLT_SIGN, uint32_t)
UNSYS_BOOL_SETTER(FLT_SIGN, uint32_t)

UNSYS_UINT_GETTER(FLT_EXPO, uint32_t)

UNSYS_UINT_GETTER(FLT_MANT, uint32_t)
UNSYS_UINT_SETTER(FLT_EXPO, uint32_t)
UNSYS_UINT_SETTER(FLT_MANT, uint32_t)

UNSYS_BOOL_GETTER(DBL_SIGN, uint32_t)
UNSYS_BOOL_SETTER(DBL_SIGN, uint32_t)

UNSYS_UINT_GETTER(DBL_EXPO, uint32_t)

UNSYS_UINT_GETTER(DBL_MANT, uint32_t)
UNSYS_UINT_SETTER(DBL_EXPO, uint32_t)
UNSYS_UINT_SETTER(DBL_MANT, uint32_t)
    


/*
static inline void
SET_FLT_EXPO(void *flt, uint32_t val) {
    const uint32_t m = (*(uint32_t *) flt)&FLT_EXPO_XOR;
    ((uint32_t *) flt)[0] = m|(val<<FLT_EXPO_OFF);
}
static inline void
SET_FLT_MANT(void *flt, uint32_t val) {
    const uint32_t m = (*(uint32_t *) flt)&FLT_MANT_XOR;
    ((uint32_t *) flt)[0] = m|(val<<FLT_MANT_OFF);
}
static inline    _Bool UNSYS_BOOL32_GETTER(FLT_SIGN)
static inline uint32_t UNSYS_UINT32_GETTER(FLT_MANT)
static inline uint32_t UNSYS_UINT32_GETTER(FLT_EXPO)
static inline void  UNSYS_BOOL32_SETTER(FLT_SIGN)
static inline void UNSYS_UINT32_SETTER(FLT_MANT)
static inline void UNSYS_UINT32_SETTER(FLT_EXPO)



typedef union {
    float           fval;
    unsigned
        mant: 23,   // 8388607
        expo: 8,    // 
        sign: 1;
    uint32_t        uval;
    unsigned char   rval[4];
} unfloat_t;

typedef union {
    [0..]:          9007199254740992
    [1..]:          4503599627370496
    [2..]:          2251799813685248
    [4..]:          1125899906842624 
    [8..]:          562949953421312 
    [16..]:         281474976710656
    [32:..]:        140737488355328
    [64..]:         70368744177664
    [128..]:        35184372088832
    [256..512]:     17592186044416
    [512..1024]:    8796093022208
    
    (0, 0,    1} 5e-324
    {0, 1021, 1}    0.25000000000000006
    {0, 1022, 1}    0.5000000000000001
    {0, 1023, 1}    1.0000000000000002
    {0, 1024, 1}    2.0000000000000004
    {0, 1025, 1}    4.000000000000001
    {0, 1026, 1}    8.000000000000002
    double          fval;
    unsigned
        mant: 52,   // 4503599627370495
        expo: 11,   // 2048
        sign: 1;    // 2
    uint64_t        uval;
    unsigned char   rval[8];
} undouble_t;
*/

