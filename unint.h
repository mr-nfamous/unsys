
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

#pragma once

#include <stdint.h>
#include <stdlib.h>
static 
const unsigned char 
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

#ifndef SIZE_C
#   if SIZE_MAX == UINT32_MAX
#       define SIZE_C UINT32_C
#   elif SIZE_MAX == UINT64_MAX
#       define SIZE_C UINT64_C
#   else 
#       error "unsupported value of SIZE_MAX"
#   endif
#endif

#if defined(_MSC_VER) 

#   include <intrin.h>
#   ifdef _M_IX64
#       pragma intrinsic(_umul128)
#   endif

static uint64_t 
UINT64_MUL128(uint64_t a, uint64_t b, uint64_t *lo) {
    uint64_t hi;
    return *lo=_umul128(a, b, &hi), hi;
}

#elif defined(__SIZEOF_INT128__)

typedef   signed __int128  int128_t;
typedef unsigned __int128 uint128_t;

static inline char
BITLENX(uint128_t i) {
    uint64_t j = (uint64_t) (i>>64);
    return j ? BITLENJ(j)+64 : BITLENJ((uint64_t) i);
}

static inline uint64_t
_umul128(uint64_t a, uint64_t b, uint64_t *hi) {
    __uint128_t p = (__uint128_t) a*b;
    *hi = (uint64_t)  (p>>64);
    return (uint64_t) (p&UINT64_MAX);
}

static inline uint64_t
UINT64_MUL128(uint64_t a, uint64_t b, uint64_t *lo) {
    __uint128_t p = (__uint128_t) a*b;
    *lo = (uint64_t)  (p&UINT64_MAX);
    return (uint64_t) (p>>64);
}

#else

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

typedef struct {
    intmax_t quot;
    intmax_t rem;
} imaxdiv_t;

intmax_t  strtoimax(const char *, char **, int);
uintmax_t strtoumax(const char *, char**, int);
intmax_t  wcstoimax(const wchar_t *, wchar_t **, int);
uintmax_t wcstoumax(const wchar_t *, wchar_t **, int);
intmax_t  imaxabs(intmax_t);
imaxdiv_t imaxdiv(intmax_t, intmax_t);

/* 
Number of bits needed to represent uint8_t value
as an integer constant expression. 

#define UN_BITLEN(i) (        \
    i  <  0x00000010U         \
    ?   i < 0x000004U         \
        ?   i < 0x02U ? i : 2 \
        :   i < 0x08U ? 3 : 4 \
    :   i < 0x000040U         \
        ?   i < 0x20U ? 5 : 6 \
        :   i < 0x80U ? 7 : 8 )

The actual macro is easier on the parser
*/

#define UN_BITLEN(i) (i<16u\
?i< 4u?i< 2u?i:2:i<  8u?3:4\
:i<64u?i<32u?5:6:i<128u?7:8)


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

static inline int
UN_DIVMOD(int *v, int n, int d) {
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
UN_LDIVMOD(long *v, long n, long d) {
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
UN_LLDIVMOD(long long *v, long long n, long long d) {
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
UN_JDIVMOD(intmax_t *v, intmax_t n, intmax_t d) {
    imaxdiv_t x = imaxdiv(n, d);
    return  (n < INTMAX_C(0))
        ?   (d < INTMAX_C(0))
        ?   ((*v=x.rem),   x.quot)
        :   ((*v=x.rem+d), x.quot-INTMAX_C(1))
        :   (d < INTMAX_C(0))
        ?   ((*v=x.rem+d), x.quot-INTMAX_C(1))
        :   ((*v=x.rem),   x.quot);
}

