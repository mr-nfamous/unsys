/* °′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳   

Extends <stdint.h> 

    uint64_VMUL(v[2], a, b) => prod
        Multiply two uint64_Multiply and store the result
        as a uint64_t pair representing the upper and
        lower 64 bits of the product.
        Returns the pointer to the upper 64 bits.
    
    uint64_VDIV(v[2], d, *m) => quotient
        Divide a 128 bit unsigned integer stored as a pair
        of two uint64_t values representing the upper and 
        lower 64 bits by a uint64_t dividend. The remainder
        is stored in m and the quotient is returned. The
        caller is responsible for ensuring the inputs won't
        result in a quotient wider than 64 bits.

    BITLEN(uint16_t n)
        A macro that replaces the result of an integer 
        constant expression with the number of digits in 
        its base 2 representation, i.e it's "bit length".
        The following example show its primary intended use 
        case: dynamic updating the width of a bitfield. 
        
            enum repr {
                CHAR_REPR,
                ...
                LLONG_REPR,
                INTMAX_REPR,
                ENUM_REPR_MAX,
            };
            struct something {
                ...
                unsigned 
                    repr: BITLEN((ENUM_REPR_MAX-1));
            };
        Note: for arguments other than symbolic constants that
        evaluate to int literals (including enum members), 
        parentheses are required.

    BITLEN8(uint8_t n) 
    BITLEN16(uint16_t n)
    BITLEN32(uint32_t n)
    BITLEN64(uint64_t n)
    BITLENX(uint128_t n) *not available on windows
        Compute the length of the binary representation of an
        instance of the corresponding fixed width unsigned int

    BITLENB(unsigned char c)
    BITLENH(unsigned short n)
    BITLENU(unsigned int n)
    BITLENL(unsigned long n)
    BITLENQ(unsigned long long n) 
    BITLENJ(uintmax_t n)
        Calculate the length of the binary representation of an
        instance of the corresponding unsigned int

    BITLENV(uint64_t v[2]) 
        Calculate the length of the binary representation
        of a 128 bit integer stored as a uint64_t couple.

    int_DIVMOD(int a, int b) 
    long_DIVMOD(long a, long b) 
    llong_DIVMOD(llong, llong b) 
    intmax_DIVMOD(intmax_t a, intmax_t b)

        The same as $div except that the result actually makes 
        sense:
            
            (+)/(+) = (+)%(+)  +5/+2 = +2 mod +1 (+2*+2 = +4; +4++1 = +5)
            (+)/(-) = (-)%(-)  +5/-2 = -3 mod -1 (-2*-3 = +6; +6+-2 = +5)
            (-)/(+) = (+)%(-)  -5/+2 = -3 mod +1 (+2*-3 = -6; -6++1 = -5)
            (-)/(-) = (-)%(+)  -5/-2 = +2 mod -1 (-2*+2 = -4; -4+-2 = -5)

*/
#pragma once

#include <errno.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#ifndef SIZE_C
#   if SIZE_MAX == UINT32_MAX
#       define SIZE_C UINT32_C
#   elif SIZE_MAX == UINT64_MAX
#       define SIZE_C UINT64_C
#   else 
#       error "unsupported value of SIZE_MAX"
#   endif
#endif

#define INT8_NEG(i)             (0-i)
#define INT16_NEG(i)            (0-i)
#define INT32_NEG(i)            (0-i)

#if LONG_MAX == INTMAX_MAX
#   define INT64_NEG(i)         (0L-i)
#   define INTMAX_NEG(i)        (0L-i)
#else
#   define INTMAX_NEG_C(i)      (0LL-i)
#   define INT64_NEG(i)         (0LL-i)
#endif

#if SIZE_MAX == UINT_MAX
#   define PTRDIFF_NEG(i)       (0-i) 

#elif SIZE_MAX == ULONG_MAX 
#   define PTRDIFF_NEG(i)       (0L-i##L)

#elif SIZE_MAX == ULLONG_MAX    
#   define PTRDIFF_NEG(n)       (0LL-n##LL)

#endif


#define ZERO                INT32_C(0)
#define ONE                 INT32_C(1)
#define TEN                 INT32_C(10)
#define HUNDRED             INT32_C(100)
#define THOUSAND            INT32_C(1000)
#define MILLION             INT32_C(1000000)
#define BILLION             INT32_C(1000000000)
#define TRILLION            INT64_C(1000000000000)
#define QUADRILLION         INT64_C(1000000000000000)
#define QUINTILLION         INT64_C(1000000000000000000)

#define BITLEN(i)  (\
  i < 0x0100        \
? i > 0x000f        \
? i > 0x003f        \
? i > 0x007f?010:007\
: i < 0x0020?005:006\
: i > 0x0003        \
? i < 0x0008?003:004\
: i > 0x0001?002:i  \
: i < 0x1000        \
? i < 0x0400        \
? i < 0x0200?011:012\
: i < 0x0800?013:014\
: i < 0x4000        \
? i > 0x2000?015:016\
: i < 0x8000?017:020)

#define BITLEN16 BITLENH

#define BITLEN8 BITLENB


static const unsigned char 
BYTELEN[] = {
    // bit length lookup table
    0,1,2,2,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
    6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
    7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
    7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
};

static inline unsigned char
BITLENJ(unsigned long long i) {
    return
    i <= 0x00000000FFFFFFFFULL
    ?   i <= 0x000000000000FFFFULL
        ?   i <= 0x00000000000000FFULL
            ?   BYTELEN[i]
            :   BYTELEN[i>>010]+010
        :   i <= 0x0000000000FFFFFFULL
            ?   BYTELEN[i>>020]+020
            :   BYTELEN[i>>030]+030
    :   i <= 0x0000FFFFFFFFFFFFULL
            ?   i <= 0x000000FFFFFFFFFFULL
                ?   BYTELEN[i>>040]+040
                :   BYTELEN[i>>050]+050
            :   i <= 0x00FFFFFFFFFFFFFFULL
                ?   BYTELEN[i>>060]+060
                :   BYTELEN[i>>070]+070;
}

intmax_t  imaxabs(intmax_t);
imaxdiv_t imaxdiv(intmax_t, intmax_t);
intmax_t  strtoimax(const char *, char **, int);
uintmax_t strtoumax(const char *, char**, int);
intmax_t  wcstoimax(const wchar_t *, wchar_t **, int);
uintmax_t wcstoumax(const wchar_t *, wchar_t **, int);

static inline unsigned char
BITLENB(unsigned char i) {
    return BYTELEN[i];
}

static inline unsigned char
BITLENH(unsigned short i) {
    return i > 0xFFU ? BYTELEN[i>>8]+8 : BYTELEN[i];
}

static inline unsigned char
BITLENU(unsigned int i) {
    return 
    i < 0x10000U
    ?   i < 0x100U
        ?   BYTELEN[i] 
        :   BYTELEN[i>>010]+010
    :   i < 0x10000U
        ?   BYTELEN[i>>020]+020
        :   BYTELEN[i>>030]+030;
}

#if LONG_MAX == INT_MAX

#   define BITLEN32 BITLENL
#   define BITLEN64 BITLENJ

static inline unsigned char
BITLENL(unsigned long i) {
    return 
    i < 0x10000UL
    ?   i < 0x100UL
        ?   BYTELEN[i]
        :   BYTELEN[i>>010]+010
    :   i < 0x10000UL
        ?   BYTELEN[i>>020]+020
        :   BYTELEN[i>>030]+030;
}

#else

#   define BITLEN32 BITLENU
#   define BITLEN64 BITLENL

static inline unsigned char
BITLENL(unsigned long i) {
    return
    i <= 0x00000000FFFFFFFFUL
    ?   i <= 0x000000000000FFFFUL
        ?   i <= 0x00000000000000FFUL
            ?   BYTELEN[i]
            :   BYTELEN[i>>010]+010
        :   i <= 0x0000000000FFFFFFUL
            ?   BYTELEN[i>>020]+020
            :   BYTELEN[i>>030]+030
    :   i <= 0x0000FFFFFFFFFFFFUL
            ?   i <= 0x000000FFFFFFFFFFUL
                ?   BYTELEN[i>>040]+040
                :   BYTELEN[i>>050]+050
            :   i <= 0x00FFFFFFFFFFFFFFUL
                ?   BYTELEN[i>>060]+060
                :   BYTELEN[i>>070]+070;
}

#endif

#if defined(__SIZEOF_INT128__)

typedef   signed __int128  int128_t;
typedef unsigned __int128 uint128_t;

static inline char
BITLENX(uint128_t i) {
    uint64_t j = (uint64_t)(i>>64);
    return j ? BITLEN64(j)+64 : BITLEN64((uint64_t)(i));
}

#   if 0

    static inline uint64_t
    _udiv128(uint64_t hi, uint64_t lo, uint64_t d, uint64_t *mod) {
        uint128_t n = ((uint128_t)(hi)<<64)|lo;
        return  *mod=(uint64_t)(n%d), (uint64_t)(n/d);
    }
    
    static inline uint64_t
    _umul128(uint64_t a, uint64_t b, uint64_t *hi) {
        __uint128_t p = (__uint128_t) a*b;
        *hi = (uint64_t)  (p>>64);
        return (uint64_t) (p&UINT64_MAX);
    }

#   endif

static inline uint64_t *
uint64_VADD(uint64_t v[2], uint64_t a[2], uint64_t b[2]) {
    union {
        uint128_t   i;
        uint64_t    v[2];
    } j = {(uint128_t) a[0]<<64|a[1]};
    j.i += (uint128_t) b[0]<<64|b[1];
    uint64_t lo = j.v[1];
    j.v[1]=*j.v, *j.v=lo;
    return memcpy(v, j.v, 16);
}

static inline uint64_t *
uint64_VSUB(uint64_t v[2], uint64_t a[2], uint64_t b[2]) {
    union {
        uint128_t   i;
        uint64_t    v[2];
    } j = {(uint128_t) a[0]<<64|a[1]};
    j.i -= (uint128_t) b[0]<<64|b[1];
    uint64_t lo = j.v[1];
    j.v[1]=*j.v, *j.v=lo;
    return memcpy(v, j.v, 16);
}

static inline uint64_t *
uint64_VMUL(uint64_t v[2], uint64_t a, uint64_t b) {
    union {
        uint128_t i;
        uint64_t  v[2];
    } c;
    c.i = (uint128_t) a*b;
    uint64_t d  = c.v[1];
    c.v[1]=*c.v, *c.v=d;
    return memcpy(v, c.v, 16);
}

static inline uint64_t *
uint64_VDIV(uint64_t v[2], uint64_t a[2], uint64_t b) {
    union {
        uint128_t i;
        uint64_t  v[2];
    } q = {.v={a[1], a[0]}};
    uint64_t p[2] = {[1]=q.i%b};
    if ((q.i/=b) > UINT64_MAX) {
        return errno=ERANGE, NULL;
    }
    p[0] = (uint64_t) q.i;
    return memcpy((void *) v, (void *) p, 16);
}


static inline uint64_t
UINT64_MUL128(uint64_t a, uint64_t b, uint64_t *lo) {
    __uint128_t p = (__uint128_t) a*b;
    *lo = (uint64_t)  (p&UINT64_MAX);
    return (uint64_t) (p>>64);
}

#elif defined(_MSC_VER) 

#   include <intrin.h>

#   if defined(_M_IX64) 
#       pragma intrinsic(_umul128) 
#   else 
#       error "x64 is required on Windows"
#   endif

static inline uint64_t *
uint64_VADD(uint64_t v[2], uint64_t a[2], uint64_t b[2]) {
    const uint64_t m = UINT32_MAX;
    uint64_t b_lo = (a[1]&  m)+(b[1]&m);
    uint64_t b_hi = (a[1]>>32)+(b[1]>>32)+(b_lo>>32);
    uint64_t a_lo = (a[0]&  m)+(b[0]&  m)+(b_hi>>32);
    uint64_t a_hi = (a[0]>>32)+(b[0]>>32)+(a_lo>>32);
    return memcpy(
        (void *) v,
        (void *) &((uint64_t []){
            (b_hi<<32)|(b_lo&m),
            (a_hi<<32)|(b_hi&m),
        }),
        sizeof v);
}

static inline uint64_t *
uint64_VMUL(uint64_t v[2], uint64_t a, uint64_t b) {
    return v[1]=_umul128(a, b, v), v;
}

static inline uint64_t
uint64_VDIV(const uint64_t v[2], uint64_t d, uint64_t *m) {
    return _udiv128(v[0], v[1], d, m);
}

#else
#   error "no builtin 128 bit division"

static inline uint64_t
_umul128(uint64_t a, uint64_t b, uint64_t *hi) {
    const uint64_t l = a>>32;
    const uint64_t r = b>>32;
    const uint64_t t = (a&UINT32_MAX)*(b&UINT32_MAX);
    const uint64_t u = (a&UINT32_MAX)*r;
    const uint64_t v = (b&UINT32_MAX)*l
    const uint64_t p = (v&UINT32_MAX)+(t>>32)+u;
    return *hi=(v>>32)+(p>>32)+l*r, (p<<32)|(t&UINT32_MAX);
}

static inline uint64_t
UINT64_MUL128(uint64_t a, uint64_t b, uint64_t *lo) {
    const uint64_t l = a>>32;
    const uint64_t r = b>>32;
    const uint64_t t = (a&UINT32_MAX)*(b&UINT32_MAX);
    const uint64_t u = (a&UINT32_MAX)*r;
    const uint64_t v = (b&UINT32_MAX)*l
    const uint64_t p = (v&UINT32_MAX)+(t>>32)+u;
    return *lo=(p<<32)|(t&UINT32_MAX),(v>>32)+r*l+(p>>32); 
}

#endif

static inline int
int_DIVMOD(int *v, int n, int d) {
    div_t x = div(n, d);
    return  (n < 0)
        ?   (d < 0)
        ?   ((*v=x.rem),   x.quot)
        :   ((*v=x.rem+d), x.quot-1)
        :   (d < 0)
        ?   ((*v=x.rem+d), x.quot-1)
        :   ((*v=x.rem),   x.quot);
}

static inline long
long_DIVMOD(long *v, long n, long d) {
    ldiv_t x = ldiv(n, d);
    return  (n < 0L)
        ?   (d < 0L)
        ?   ((*v=x.rem),   x.quot)
        :   ((*v=x.rem+d), x.quot-1L)
        :   (d < 0L)
        ?   ((*v=x.rem+d), x.quot-1L)
        :   ((*v=x.rem),   x.quot);
}

static inline long long
llong_DIVMOD(long long *v, long long n, long long d) {
    lldiv_t x = lldiv(n, d);
    return  (n < 0LL)
        ?   (d < 0LL)
        ?   ((*v=x.rem),   x.quot)
        :   ((*v=x.rem+d), x.quot-1LL)
        :   (d < 0LL)
        ?   ((*v=x.rem+d), x.quot-1LL)
        :   ((*v=x.rem),   x.quot);
}

static inline intmax_t
intmax_DIVMOD(intmax_t *v, intmax_t n, intmax_t d) {
    imaxdiv_t x = imaxdiv(n, d);
    return  (n < INTMAX_C(0))
        ?   (d < INTMAX_C(0))
        ?   ((*v=x.rem),   x.quot)
        :   ((*v=x.rem+d), x.quot-INTMAX_C(1))
        :   (d < INTMAX_C(0))
        ?   ((*v=x.rem+d), x.quot-INTMAX_C(1))
        :   ((*v=x.rem),   x.quot);
}

int
time_mul(time_t *v, time_t a, long b) {
    if (a && b) {
        if (a < INT64_C(0)) {
            if ((b < (INT64_MAX/a+1)) || (b > (INT64_MIN/a))) {
                return (errno=ERANGE);
            }
        }
        else {
            if ((b < (INT64_MIN/a+1)) || (b > (INT64_MAX/a))) {
                return (errno=ERANGE);
            }
        }
    }
    *v = a*b;
    return 0;
}