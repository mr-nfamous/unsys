
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
/*
    "?"         anything 
    "a"         match "a"
    "a*"        match "a" then "bc" in "789abc"
    "*9"        match "78" then "9" in "789abc"
    "[ad]"      match "a" | "d" 
    "[~a]"      match anything but "a"
    "[a]+"      matches one or more "a"
    "[a..z]"    match any c if "a" <= c && c <= "z"
    "[a..*]"    match any c if "a" <= c
    "[*..a]"    match any c if "a" >= c 
    "\p{ascii}" match any c if isascii(c) is true 
    "\P{ascii}" match any c if isaacii(c) is false
    "[[a..f]~~[cd]]" matches "a", "b", "e", and "f"
    "(`)*(?=0)" matches two grave accents with any number
                of any character between them apart from 
                gravr accent obviously 
    ""
*/
#pragma once

#if CHAR_MIN
#error "char is required to be an unsigned type"
#endif

#include "unstddef.h"
#include "unascii.h"

static 
const char CHARMAP_ID[256] = {
    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 
    16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 
    64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
    96, 97, 98, 99, 100,101,102,103,104,105,106,107,108,109,110,111,
    112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
    128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,
    144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,
    160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,
    176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,
    192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,
    208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,
    224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,
    240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,
};

typedef 
union {
    void            *any;
    char            *u8;
    char16_t        *u16;
    char32_t        *u32;
    union {
        intptr_t    s;
        uintptr_t   u;
    } addr;
}   unchar_t;

typedef 
struct {
    /*  Bitarray used primarily for boolean properties */
    int             cmax;
    int             tmax;
    unsigned int    bits[1];
}   uncharattr_t;

typedef 
struct {
    /*  Used for translation tables */
    unchar_t    map;
    size_t      len;
    unchar_t    clr;
}   untrans_t;

typedef 
struct {
    void   *src;
    size_t  len;
}   unmem_t;

/* Check for homogeneously typed strings */
bool unstrisalnum(const char *);
bool unstrisalpha(const char *);
bool unstrisascii(const char *); 
bool unstrisblank(const char *);
bool unstriscntrl(const char *);
bool unstrisdigit(const char *);
bool unstrisgraph(const char *);
bool unstrislower(const char *); 
bool unstrisupper(const char *); 
bool unstrisprint(const char *); 
bool unstrispunct(const char *); 
bool unstrisspace(const char *);
bool unstrisbdigit(const char *);
bool unstrisodigit(const char *);
bool unstrisxdigit(const char *);

/* String comparison ops */
bool unstrlt(const char *, const char *);
bool unstrle(const char *, const char *);
bool unstreq(const char *, const char *);
bool unstrne(const char *, const char *);
bool unstrgt(const char *, const char *);
bool unstrge(const char *, const char *);

int unmkbtrans(untrans_t *, char [256], const unmem_t *);
int unmkwtrans(untrans_t *, unmem_t *, const unmem_t *);


/*
In house implementation of <string.h> plus some
additional functions inspired by library extensions 
of popular compilers. 

    *(un)memrev
    *(un)strrev
        strrev(s, &n) computes the length of s, storing 
        it at the address given as the second argument 
        and then reverses the contents of s, excluding
        the nul terminator. I.e. strrev(str, &len), where 
        str equals "abcd" initially, rearranges the bytes 
        to "dcba" and stores 4 in *len. MSVC has a similar
        function.
        memrev is identical except the second argument
        is exactly the number of bytes to reverse.
        
    *(un)memcset
        memset until the end or until a specific byte
        value is encountered. E.g: memcset(s, 0, 8, 0)
        would fill s with up to 8 zeros, terminating
        if any byte before s[7] is 0.

    *(un)memmem
    *(un)memrmem
        memmem(str, 40, sub, 2) scans up to 40 bytes 
        of str, from left to right, for the 2 byte
        substring sub, returning a pointer to the first 
        byte of the match.
        memrmem is identical except the search proceeds
        from right to left from the end of the input.
        e.g. memrmem("0123456789", 10, "56", 2) would
        go something like: 
            8!=5; 
            7!=5; 
            6!=5; 
            5==5 && 6==6: return &str[5]

    *(un)strupr
    *(un)strnupr
        strupr(s, &len) replaces ['a'..'z'] with the
        corresponding uppercase ASCII character and
        stores the length of s in len. strnupr is the
        same except the second argument is a limit
        to the number of bytes to transform.

    *(un)strlwr
    *(un)strnlwr
        Identical to strupr/strnupr except uppercase 
        characters are replaced by the corresponding
        lowercase character.

    *strmul:
        strmul(str, 1) is identical to strdup, while 
        strmul("01", 3) tries to allocate a buffer 
        large enough to store 3*2+1 bytes and then
        copy "01" into it 3 times in sequence. The
        caller is responsible for calling free.

    *stpcat/stpncat:
        stpcat(a, b) appends b to a and returns a 
        pointer to a's terminating nul.
        stpncat(a, b, z) is identical except if a is 
        longer than z bytes, the equivalent of calling 
        stpcpy(a+z, b) is returned. a must be large
        enough to fit at least z+strlen(b)+1 bytes.

        *strhash/strihash:
        strhash(a, &z) transforms a into a pseudorandom
        31 bit unsigned int and stores the length of a 
        at (if not NULL). strihash is equivalent except 
        the bytes in a for which isalpha is true are
        symbolically replaced with 256+[c-T], where 
        c is the alphabetical byte and T is 'A'(65) for 
        uppercase or 'a'(97) for lowercase. 
        When used as the index in e.g. 6 bit hash 
        table, the result should be right shifted by 
        31-6 (25) instead of the probably more common 
        approach of taking modulus.
        
    *stricmp/strnicmp:
        Compare two byte strings by the semantics 
        elaborated on in the section about strhash. E.g.
        stricmp("A_b", "a_B", &n) would return 0 for 
        equal, because internally, "A_b" is converted 
        to {256+'A'-'A, '_', 256+'b'-'b'} and "a_B"
        to {256+'a'-'a', '_', 256+'B'-'B'}, which is
        {256, 95, 257} for both.
        The difference between stricmp and strnicmp is 
        the third argument is a limit on the number of
        bytes to compare instead of a pointer at which
        the number of bytes, excluding the nul, that 
        participated in the comparison.
        A similar function exists in POSIX, strcasecmp, 
        which can be found in <strings.h>.
        
        
*/

/* Reverse a string */
void *unmemrev (void *, size_t);
char *unstrrev (char *, size_t *);

/* Initialize a block of memory */
char *unstrset (char *, int);
char *unstrnset(char *, int, size_t);
void *unmemset (void *, int, size_t);
void *unmemcset(void *, int, size_t, int);

/* Initialize memory to range of values */
void *unmemrange(void *, int, int, size_t);

/* Copy from one string to the start of another */
char *unstrcpy (char *restrict, const char *restrict);
char *unstpcpy (char *restrict, const char *restrict);
char *unstrncpy(char *restrict, const char *restrict,      size_t);
char *unstpncpy(char *restrict, const char *restrict,      size_t);
void *unmemcpy (void *restrict, const void *restrict,      size_t);
void *unmemccpy(void *restrict, const void *restrict, int, size_t);
void *unmemmove(void *,         const void *,              size_t);

/* Copy from one string to the end of another */
char *unstrcat (char *restrict, const char *restrict);
char *unstpcat (char *restrict, const char *restrict);
char *unstrncat(char *restrict, const char *restrict, size_t);
char *unstpncat(char *restrict, const char *restrict, size_t);
void *unmemcat (void *restrict, size_t, const void *restrict, size_t);

/* Locate individual characters  */
char *unstrchr (const char *, int);
char *unstrnchr(const char *, int, size_t);
char *unstrrchr(const char *, int);
void *unmemchr (const void *, int, size_t);
void *unmemrchr(const void *, int, size_t);
char *unstrpbrk(const char *restrict, const char *restrict);
size_t unstrspn (const char *restrict, const char *restrict);
size_t unstrcspn(const char *restrict, const char *restrict);
size_t unmembcnt(const void *, int, size_t);

/* Get the index of string's terminating nul */
size_t unstrlen    (char_c *restrict);
size_t unstrnlen   (char_c *restrict, size_t);

/* Locate substrings */
void *unmemmem (const void *restrict, size_t, const void *restrict, size_t);
void *unmemrmem(const void *restrict, size_t, const void *restrict, size_t);
char *unstrstr (char_c *restrict, char_c *restrict);
char *unstrrstr(char_c *restrict, char_c *restrict);

/* Transform ASCII string to uppercase */
char *unstrupr (char *, size_t *);
char *unstrnupr(char *, size_t);

/* Transform ASCII string to lowercase */
char *unstrlwr (char *, size_t *);
char *unstrnlwr(char *, size_t);

/* Get a duplicate string */
char *unstrdup (const char *restrict);
char *unstrndup(const char *restrict, size_t);

int unmemcmp    (void_c *, size_t, void_c *, size_t);
int unstrcmp    (char_c *, char_c *);
int unstricmp   (char_c *, char_c *);
int unstrncmp   (char_c *, char_c *, size_t);
int unstrnicmp  (char_c *, char_c *, size_t);

/*  Get the hash table index of a string */
hash_t unmemhash   (const void *, size_t);
hash_t unstrhash   (const char *);
hash_t unstrihash   (const char *);

ptrdiff_t unstrlfnd(char_c *restrict, char_c *restrict);

int unstrfmt(char *, const char *[]);
