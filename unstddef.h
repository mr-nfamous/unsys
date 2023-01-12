/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

#pragma once

#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <stdalign.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <wchar.h>

typedef uint_least16_t  char16_t;
typedef uint_least32_t  char32_t;

#ifndef SEEK_SET
#include <unistd.h>
#endif

#ifndef    SEEK_DATA
#   define SEEK_DATA 3
#   define SEEK_HOLE 4
#endif

#define GETATTR_FAILURE ((size_t) 0-1)
#define SETATTR_FAILURE ((size_t) 0-1)
#define UNSYS_SUCCESS   (0)
#define UNSYS_FAILURE   (0-1)
#define NONCHAR         (0x110000)

#define HASH_FAILURE    UNSYS_FAILURE

#define addrdiff(a, b) (((void*)a)-((void*)b))

#define membersize(t, a)    (sizeof(((t)*)0)->a)
#define sizeofm(t, a)       (sizeof(((t*)0)->a))
#define sssizeofm(t, m)     ((ptrdiff_t)sizeof(((t*)0)->a))
#define ssizeof(x)          ((ptrdiff_t)(sizeof(x)))
#define lengthof(a)         ((sizeof(a))/(sizeof*(a)))
#define stringify(a)        #a
#define stringpify(p, s)    p##s
#define quotify(x)          "\042" #x "\042"

#define BSTRIFY(...)    #__VA_ARGS__
#define BSTRPFY(p,...)  stringpify(p, BSTRIFY(__VA_ARGS__))
#define HSTRIFY(...)    BSTRPFY(u, __VA_ARGS__)
#define USTRIFY(...)    BSTRPFY(U, __VA_ARGS__)

#define BCHRIFY(x)  (*BSTRIFY(x))
#define HCHRIFY(x)  (*HSTRIFY(x))
#define UCHRIFY(x)  (*USTRIFY(x))

#ifndef charize
#define charize(c) ((#c)[0])
#define char16ize(c) (*hstrify(c)
#endif

#define bytelen(i) (i>=16?i>=128?8:i>=64?7:i>=32?6:5:i>=8?4:i>=4?3:i>=2?2:i)
#define wordlen(i) (\
i<0x0100\
?   bytelen(i):i<0x1000\
    ?   i<0x0400\
    ?   i<0x0200\
    ?       011:012:i<0x0800\
    ?       013:014:i<0x4000\
    ?   i <0x2000\
    ?       015:016:i<0x8000\
    ?       017:020)

#if defined(__clang__) || defined(__GNUC__)
#   define UNUSED(identifier) identifier __attribute__((unused))
#else
#   define UNUSED(identifier) identifier
#endif

#ifndef unreachable
#   if defined(__clang__) || defined(__GNUC__)
#       define unreachable() (__builtin_unreachable())
#   elif defined(_MSC_VER)
#       define unreachable() (__assume(0))
#   else
#       include <stdlib.h>
#       define unreachable ((abort)())
#   endif
#endif

typedef struct {
    union {
        const void  *as_mem;
        const char  *as_str;
    };
    const char      *as_mbs;
    const char16_t  *as_s16;
    const char32_t  *as_s32;
} omnistr_t;

#define OMNISTR(s) ((omnistr_t){s, s, (u##s), (U##s)})

typedef struct unsys_c_type c_type_t;

typedef struct unsys_ucs     ucs_t;
typedef struct unsys_ucs_iob ucs_iob_t;
typedef struct unsys_ucs_hdr ucs_hdr_t;
typedef struct unsys_ucs_iov ucs_iov_t;

#ifdef _MSC_VER

char *stpcpy(char[restrict], const char[restrict]);
char *stpncpy(char[restrict], const char[restrict], size_t);

wchar_t *wcpcpy(wchar_t[restrict], const wchar_t[restrict]);
wchar_t *wcpncpy(wchar_t[restrict], const wchar_t[restrict], size_t);

char *strndup(const char[], size_t);

/*
char *
stpcpy(char *dst, const char *src) {
    dst = _memccpy(dst, src, 0, SIZE_MAX);
    return !dst ? dst : dst-1;
}

char *
stpncpy(char *dst, const char *src, size_t len) {
    dst = _memccpy(dst, src, 0, len);
    return !dst ? dst : dst-1;
}

char *
strndup(const char *src, size_t len) {
    size_t nch = _strnlen(src, len);
    char *dup = malloc(nchr+1);
    dup[nchr] = 0;
    return _memcpy(dup, src, nch);
}

char *
strdup(const char *src) {
    size_t len = _strlen(src)+1;
    return _memcpy(malloc(len), len);
}
*/
#   define bstpcpy      stpcpy
#   define hstpcpy      wcpcpy
//  define wstpcpy 

#   define bstpncpy     stpncpy
#   define hstpncpy     wcpncpy
//  define wstpncpy 

#   define bstrbrk      _strpbrk
#   define hstrbrk      _wcspbrk
//  define ustrbrk

#   define bstrcat      _strcat
#   define hstrcat      _wcscat
//  define ustrcat

#   define bstrncat     _strncat
#   define hstrncat     _wcsncat
//  define ustrncat   

#   define bstrchr      _strchr
#   define hstrchr      _wcschr
//  define ustrchr

#   define bstrcmp      _strcmp
#   define hstrcmp      _wcscmp
//  define ustrcmp

#   define bstrncmp     _strncmp
#   define hstrncmp     _wcsncmp
//  define ustrncmp

#   define bstricmp     _stricmp
#   define hstricmp     _wcsicmp
//  define ustricmp 

#   define bstrnicmp    _strnicmp
#   define hstrnicmp    _wcsnicmp
//  define ustrncmp

#   define bstrcpy      _strcpy
#   define hstrcpy      _wcscpy
//  define ustrcpy   

#   define bstrrchr     _strrchr
#   define hstrrchr     _wcsrchr
//  define ustrrchr 

#   define bstrncpy     _strncpy
#   define hstrncpy     _wcsncpy
//  define ustrncpy

#   define bstrrev      _strrev
#   define hstrrev      _wcsrev
//  define ustrrev

#   define bstrset      _strset
#   define hstrset      _wcsset
//  define ustrset

#   define bstrnset     _strnset
#   define hstrnset     _wcsnset
//  define ustrnset

#   define bstrnlen     _strnlen
#   define hstrnlen     _wcsnlen
//  define ustrnlen

#   define bstrlen      _strlen
#   define hstrlen      _wcslen
//  define ustrlen

#   define bstrspn      _strspn
#   define hstrspn      _wcsspn
//  define ustrspn

#   define bstrcspn     _strcspn
#   define hstrcspn     _wcscspn
//  define ustrcspn

#   define bstrstr      _strstr
#   define hstrstr      _wcsstr
//  define ustrstr

#   define bmemccpy     _memccpy

#   define bmemchr      _memchr
#   define hmemchr      _wmemchr
//  define umemchr        

//  define bmemrchr     
//  define hmemrchr    
//  define umemrchr        

//  define bmemmem 
//  define hmemmem 
//  define umemmem 

#   define bmemcmp      _memcmp
#   define hmemcmp      _wmemcmp
//  define umemcmp

#   define bmemcpy      _memcpy
#   define hmemcpy      _wmemcpy
//  define umemcpy

#   define bmemmov      _memmove
#   define hmemmov      _wmemmove
//  define umemmov

#else 

#   define bstpcpy      stpcpy
//  define wstpcpy    
#   define wstpcpy      wcpcpy

#   define bstpncpy     stpncpy
//  define wstpncpy  
#   define wstpncpy     wcpncpy

#   define bstrdup      strdup
//  define hstrdup     
#   define ustrdup      wcsdup

#   define bstrndup     strndup
//  define hstrndup     
//  define ustrndup     

#   define bstrbrk      strpbrk
//  define hstrbrk      
#   define ustrbrk      wcspbrk

#   define bstrcat      strcat
//  define hstrcat  
#   define ustrcat      wcscat

#   define bstrncat     strncat
//  define hstrncat   
#   define ustrncat     wcsncat

#   define bstrchr      strchr
//  define hstrchr
#   define ustrchr      wcschr

#   define bstrcmp      strcmp
//  define hstrcmp
#   define ustrcmp      wcscmp

#   define bstrncmp     strncmp
//  define hstrncmp
#   define ustrncmp     wcsncmp

#   define bstricmp     strcasecmp
//  define hstricmp 
#   define ustricmp     wcscasecmp

#   define bstrnicmp    strncasecmp
//  define hstricmp 
#   define ustrnicmp    wcsncasecmp

#   define bstrcpy      strcpy
//  define hstrcpy   
#   define ustrcpy      wcscpy

#   define bstrncpy     strncpy
//  define hstrncpy
#   define ustrncpy     wcsncpy

//  define bstrrev 
//  define hstrrev 
//  define ustrrev

//  define bstrset
//  define hstrset
//  define ustrset

//  define bstrnset
//  define hstrnset
//  define ustrnset

#   define bstrrchr     strrchr
//  define hstrrchr 
#   define ustrrchr     wcsrchr

#   define bstrnlen     strnlen
//  define hstrnlen
#   define ustrnlen     wcsnlen

#   define bstrlen      strlen
//  define hstrlen
#   define ustrlen      wcslen

#   define bstrspn      strspn
//  define hstrspn
#   define ustrspn      wcsspn

#   define bstrcspn     strcspn
//  define hstrcspn
#   define ustrcspn     wcscspn

#   define bstrstr      strstr
//  define hstrstr   
#   define ustrstr      wcsstr

#   define bmemccpy     memccpy

#   define bmemcpy      memcpy
//  define hmemcpy 
#   define umemcpy      wmemcpy

#   define bmemchr      memchr
//  define hmemchr
#   define umemchr      wmemchr

#   define bmemrchr     memrchr
//  define hmemrchr    
//  define umemrchr

#   define bmemmem      memmem
//  define hmemmem
//  define umemmem

#   define bmemmov      memmove
//  define hmemmov
#   define umemmov      wmemmove

#endif

/* malloc for 8, 16, and 32 bit strings */
static inline void *BMALLOC(size_t nel) {return malloc(nel);}
static inline void *HMALLOC(size_t nel) {return malloc(nel<<1);}
static inline void *UMALLOC(size_t nel) {return malloc(nel<<2);}

/* Allocate the memory for a nul terminated string

-TALLOC(T, N) allocates enough memory to represent N type T 
code units plus the terminator, sets the terminator, then
returns the properly terminated (but still full of garbage).

I.e. HTALLOC(3) returns an 8 byte buffer, as in:
    malloc((3+1)*sizeof(char16_t))

*/

static inline void *
BTALLOC(size_t len) {
    void *mem = BMALLOC(len+1);
    ((char *) mem)[len] = 0;
    return mem;
}

static inline void *
HTALLOC(size_t len) {
    void *mem = HMALLOC(len+1);
    ((char16_t *) mem)[ len ] = 0;
    return mem;
}

static inline void *
UTALLOC(size_t len) {
    void *mem = UMALLOC(len+1);
    ((char32_t *) mem)[ len ] = 0;
    return mem;
}

#define TRISORTER(P, T) \
static inline void P##TRISORT(T *restrict a, T *restrict b, T *restrict c) {\
    T x;\
    if (*a <= *b) {\
        if (*b <= *c) return;\
        if (*a <= *c) x=*b, *b=*c, *c=x;\
        else   x=*a, *a=*c, *c=*b, *b=x;\
        return;\
    }\
    if (*b <= *c) {\
        if (*a <= *c) x=*a, *a=*b, *b=x;\
        else   x=*c, *c=*a, *a=*b, *b=x;\
        return;\
    }\
    x=*a, *a=*c, *c=x;\
}

TRISORTER(B, char)
TRISORTER(H, char16_t)
TRISORTER(W, char32_t)
#undef TRISORTER

#define TRISORT(a,b,c) (_Generic(\
(a),\
char: BTRISORT,\
char16_t: HTRISORT,\
char32_t: WTRISORT)(&(a), &(b), &(c)))