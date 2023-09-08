/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#pragma once

#include "unstddef.h"
#include "stg.h"
#include "repr.h"
#include "error.h"

#define txt_generic(F, t) \
_Generic(*(t),\
char32_t:U##F,\
char16_t:H##F,\
char:    B##F,\
uint8_t: B##F,\
default: U##F)

#define UCS_A 0 // no code points > 0x7f
#define UCS_B 1 // no code points > 0xff
#define UCS_H 2 // no code points > 0xffff
#define UCS_U 3 // no code points > 0x10ffff

#define END_OF_UCS (0-1)

/*
    #  {'.'} => char set
    {"."} => str set 
    #name => set of 
    
    format("%_<5c", 'k')        => "__k__"
    format("%`>+11.0'8ld, 9999L)  => ```+009'999"
    
        : "%[%]"
    afmt: "%1[#]"
    jpad: "%1s"
    just: "%1[<->^]"
    slen: "%16[*0123456789]"
    sign: "%1[+]"
    prec: "%1[.]"
    gsep: "%1[^*0123456789]"
    zpad: "%1[0]"
    plen: "%16[*0123456789]"
    lmod: "%2[hljtzL]"
    spec: "%1[ABCEFGSXabcdefgnopux]"
    
    #//             
        'a' | 'A' | 
        'b' | 'B' |
        'c' | 'C' | # // "%# ^"
        'e' | 'E' |
        'f' | 'F' |
        'g' | 'G' 
        'i' | 
        'd' | 
        'n' |
        'p' | # // "%_^010.:0:6p" => "_0x00b33f_"
        'P' | # // "%.8P" => "  0xDEADB33F"
        's' |
        'u' | 
        'o' | 
        'x' | 'X' | 
    
"%" "*" "%[1-9]""
*/ 

struct print_format {
    char flag[2];   // "%1[#]"
    char jpad[2];   // "%1c"
    char just[2];   // "%1[<->^]"
    char slen[16];  // "%15[*0123456789]"
    char sign[2];   // "%1[+]"
    char prec[2];   // "%1[.]"
    char gsep[2];   // "%1[^*0123456789]"
    char zpad[2];   // "%1[0]"
    char plen[16];  // "%15[*0123456789]"
    char lmod[3];   // "%2[hljtzL]"
    char spec[2];   // "%1[ABCEFGSXabcdefgnopux]"
};


typedef unsigned short ccs_t;

enum {
    undefined_ccs,
    cmap_ccs,
    hmap_ccs,
    wmap_ccs,
    us_ascii_ccs, // ccs=US-ASCII,
#define                       ascii_ccs us_ascii_ccs // "US-ASCII"
#define                       ascii_ccs us_ascii_ccs // "ASCII"
#define                     csascii_ccs us_ascii_ccs // "csASCII"
#define              ansi_x3_4_1968_ccs us_ascii_ccs // "ANSI_X3.4-1968"
#define              ansi_x3_4_1986_ccs us_ascii_ccs // "ANSI_X3.4-1986"
#define                      cp_367_ccs us_ascii_ccs // "cp367"
#define                     ibm_367_ccs us_ascii_ccs // "IBM367"
#define                    iso_ir_6_ccs us_ascii_ccs // "iso-ir-6"
#define            iso_646_irv_1991_ccs us_ascii_ccs // "ISO_646.irv:1991"
#define                          us_ccs us_ascii_ccs // "us"
// are these really equivalent to US-ASCII?
#define         iso_10646_ucs_basic_ccs us_ascii_ccs // "ISO-10646-UCS-Basic"
#define              csunicodeascii_ccs us_ascii_ccs // "csUnicodeASCII"

    latin_1_ccs, // ccs=ISO-8859-1
#define                  iso_8859_1_ccs latin_1_ccs // "ISO-8859-1"
#define                csisolatin_1_ccs latin_1_ccs // "csISOLatin1"
#define                      cp_819_ccs latin_1_ccs // "CP819"
#define                          l1_ccs latin_1_ccs // "l1"
#define                  iso_ir_100_ccs latin_1_ccs // "iso-ir-100"
#define                     latin_1_ccs latin_1_ccs // "latin1"
#define                     ibm_819_ccs latin_1_ccs // "IBM819"
// equivalent to ISO-8859-1 ?
#define   iso_10646_unicode_latin_1_ccs latin_1_ccs // "ISO-10646-Unicode-Latin1"
#define            csunicodelatin_1_ccs latin_1_ccs // "csUnicodeLatin1"
#define ucs_1_ccs latin_1_ccs
    ucs_2_ccs, // ccs=UCS-2
#define                   csunicode_ccs ucs_2_ccs
#define             iso_10646_ucs_2_ccs ucs_2_ccs // "ISO-10646-UCS-2"


    ucs_4_ccs, // ccs=UCS-4
#define             iso_10646_ucs_4_ccs ucs_4_ccs // "ISO-10646-UCS-4"


    utf_8_ccs, // ccs=UTF-8
#define                     csutf_8_ccs utf_8_ccs // "UTF-8"
    utf_16_ccs,     // ccs=UTF-16
    utf_16be_ccs,   // ccs=UTF-16BE
    utf_16le_ccs,   // ccs=UTF-16LE
    utf_32be_ccs,   // ccs=UTF-32BE
    utf_32le_ccs,   // ccs=UTF-32LE
    utf_32_ccs,     // ccs=UTF-32
    utf_7_ccs,      //  ccs=UTF-7
};

static inline word_t
DECODE_EXC(ptrdiff_t *off, ptrdiff_t *old) {
    errno = EILSEQ;
    if (old != NULL) (*off=*old);
    return NONCHAR;
}

static inline void *
ENCODE_EXC(void) {
    errno = EILSEQ;
    return NULL;
}

static inline ccs_t
MIBENUM_TO_CCS(int mib) {
    switch (mib) {
        case 3:     return us_ascii_ccs;
        case 4:     return    ucs_1_ccs;
        case 106:   return    utf_8_ccs;
        case 1000:  return    ucs_2_ccs;
        case 1001:  return    ucs_4_ccs;
        case 1012:  return    utf_7_ccs;
        case 1013:  return utf_16be_ccs;
        case 1014:  return utf_16le_ccs;
        case 1015:  return   utf_16_ccs;
        case 1017:  return   utf_32_ccs;
        case 1018:  return utf_32be_ccs;
        case 1019:  return utf_32le_ccs;
        default:    return undefined_ccs;
    }
}

struct unsys_ucs {
    union {
        void        *buf;
        signed char *ucs_a, *a;
        char        *ucs_b, *b;
        char16_t    *ucs_h, *h;
        char32_t    *ucs_u, *u;
    };
    size_t          nel;
    unsigned 
        ccs:    16,
        stg:    16,
        nbrk:   8,
        bnul:   1,
        ucs:    3,
        sorted: 1,
        rdy:    1,
        :       0;
    const char32_t *brk;
    ptrdiff_t       min;
    ptrdiff_t       max;
    ptrdiff_t       end;
};

static inline int
UCS_INIT(
    ucs_t             *restrict obj, 
    unsigned                    ucs, 
    void              *restrict buf, 
    size_t                      nel, 
    const char32_t *restrict    brk
) 
{
    size_t len = 0;
    if (!nel) return 0-(errno=ENOMEM);
    if (brk) {
        size_t max = 256;
        for (; max && brk[len]; max--, len++) {}
        if (!max && brk[len])  return 0-(errno=ENOSPC);
        len++;
    }
    *obj = (ucs_t){
        .buf = buf, 
        .ucs = ucs, 
        .nel = nel, 
        .stg = FREE_STG, 
        .nbrk =len,
        .brk = brk,
    };
    switch (ucs) {
        default: unreachable();
        case UCS_A: {
            obj->ccs = ascii_ccs;
            if (!buf) obj->stg=HEAP_STG, obj->buf=malloc(nel*sizeof*obj->a);
            return 0;
        }
        case UCS_B: {
            obj->ccs = ucs_1_ccs;
            if (!buf) obj->stg=HEAP_STG, obj->buf=malloc(len*sizeof*obj->b);
            return 0;
        }
        case UCS_H: {
            obj->ccs = ucs_2_ccs;
            if (!buf) obj->stg=HEAP_STG, obj->buf=malloc(len*sizeof*obj->h);
            return 0;
        }
        case UCS_U: {
            obj->ccs = ucs_4_ccs;
            if (!buf) obj->stg=HEAP_STG, obj->buf=malloc(len*sizeof*obj->u);
            return 0;
        }
    }
}
       
static inline ucs_t *
UCS_FROMUSTR
(
    ucs_t                   *ucs,
    const char32_t *restrict src,
    size_t                   nel,
    const char32_t *restrict brk
)
{
    size_t len;
    if (ucs == NULL) {
        ucs = malloc(sizeof*ucs);
    }
    return ucs;
}

/*
    if (!src_nel) return 0-(errno=ENOMEM);
    
    switch (src_type) {
        case UCS_A: {
            dst->hdr.ccs = ascii_ccs;
            if ()
            break;
        }
        case UCS_B: {
            dst->hdr.ccs = ucs_1_ccs;
            break;
        }
        case UCS_H: {
            dst->hdr.ccs = ucs_2_ccs;
            break;
        }
        case UCS_W: {
            dst->hdr.ccs = ucs_4_ccs;
            break;
        }
    }
        case AS_WORD: {
            dst->hdrccs = ucs_4_ccs;
            break;
        }
        default: return 0-(EILSEQ);
    }
            if (dst->)
        case UCS_B: goto b;
        case UCS_H: goto h;
        case UCS_U: goto u;
        default: unreachable();
    }
    while (0) {
        i = *(  signed char *) str != 0;
        break;

        b: {ucs->hdr.ucs = ucs_1_ccs;}
        i = *(unsigned char *) str != 0;
        break;
    }
        
    }
    c: {
#   define ucsinit_rdy(T, bcpy, hcpy, ucpy)
    const T *min=str, *max=str, *end=str;   
    for (;; i++) {
        if (end[i] <= *min) { 
            if (!*(min=end)) break; continue;
        }
        if (end[i] > *max) max = end;
    }
    switch (dst.
    
    i++;
    }
    
    if (!ucs->mem.p) {
        ucs->mem = malloc(ucs->hdr.ucs )
        ucs->hdr.stg = HEAP_STG;
    }
    else {
        
    }
    }
    if (*max > 0x7f) {
        ucs->hdr.ccs = ascii_ccs;
        
            
        }
    }
    ucs->ccs = (*max > 0x7f) ? ucs_1_ccs : ascii_ccs;

    ucs->mem.nel = i;
    
    f
}
static inline int
UCSINIT(ucs_t *ucs, const void *wcs, as_t t) {
    size_t i;
    switch (t&0xff) {
        case AS_CHAR:
        case AS_SCHAR:
        case AS_UCHAR: {
            
        }
    }

}
*/

#define STATIC_UCS_B(str) {\
    .hdr = {.ccs=ucs_1_ccs, .stg=HEAP_STG, .ucs=UCS_B, .end=1},\
    .mem = {{str}, (sizeof (char[]){str})},\
    .min = (0-1),\
    .max = (0-1)}

#define STATIC_UCS_H(str) {\
    .hdr = {.ccs=ucs_2_ccs, .stg=HEAP_STG, .ucs=UCS_H, .end=1},\
    .mem = {{u##str}, (sizeof (char[]){str})},\
    .min = (0-1),\
    .max = (0-1)}

#define STATIC_UCS_U(str) {\
    .hdr = {.ccs=ucs_4_ccs, .stg=HEAP_STG, .ucs=UCS_U, .end=1},\
    .mem = {{U##str}, (sizeof (char[]){str})},\
    .min = (0-1),\
    .max = (0-1)}

struct Codec_name {
    char    str[40];
    char    nul;
    uint8_t len;
};

typedef struct unsys_codec Codec_t;

typedef void       *(*Codec_encoder_t)(const Codec_t *,       void *, va_list);
typedef uintptr_t   (*Codec_decoder_t)(const Codec_t *, const void *, void *);
typedef bool        (*Codec_matcher_t)(const Codec_t *, const char *, word_t);

struct unsys_codec {
    struct Codec_name   name;
    unsigned short      repr; // change to as_t
    void               *info;
    Codec_encoder_t     encode;
    Codec_decoder_t     decode;
    Codec_matcher_t     match;
};

static inline ptrdiff_t
SET_END_OF_UCS(ptrdiff_t *pos, ptrdiff_t nel) {
    *pos = END_OF_UCS;
    return nel;
}

static inline bool *
ENCODE_BOOL  (bool *dst, word_t src) {
    *dst++ = src ? 1 : 0;
    return dst;
}

static inline void *
ENCODE_BYTE (uint8_t *dst, word_t src) {
    *dst++ = (uint8_t) src;
    return dst;
}

static inline void *
ENCODE_HWORD(uint16_t *dst, word_t src) {
    if ((uintptr_t) dst%sizeof*dst) {
        uint16_t v = (uint16_t) src;
        (void) memcpy(dst, &v, sizeof*dst);
    }
    else {
        *dst = (uint16_t) src;
    }
    return dst+1;
}

static inline void *
ENCODE_WORD (uint32_t *dst, word_t src) {
    if ((uintptr_t) dst%sizeof*dst) {
        uint32_t v = (uint32_t) src;
        (void) memcpy(dst, &v, sizeof*dst);
    }
    else {
        *dst = (uint32_t) src;
    }
    return dst+1;
}

static inline void *
ENCODE_DWORD(uint64_t *dst, dword_t src) {
    *dst++ = (uint64_t) src;
    return dst;
}

static inline uintptr_t
DECODE_BOOL(const bool *src, ptrdiff_t *off) {
    if (off != NULL) {
        ptrdiff_t i = *off;
        bool v = src[i++];
        off[0] = i;
        return v;
    }
    return src[0];
}

static inline uintptr_t
DECODE_BYTE(const uint8_t *src, ptrdiff_t *off) {
    if (off != NULL) {
        ptrdiff_t i = *off;
        uint8_t v = src[i++];
        off[0] = i;
        return v;
    }
    return src[0];
}

static inline char *
ENCODE_UC1(char dst[], char32_t chr) {
    *dst++ = (char) chr;
    return dst;
}

static inline char *
ENCODE_UC2(char dst[], char32_t chr) {
    *dst++ = (char)(0xc0|(chr>>6));
    *dst++ = (char)(0x80|(chr&0x3f));
    return dst;
}

static inline char *
ENCODE_UC3(char dst[], char32_t chr) {
    *dst++ = (char)(      0xe0|(chr>>12));
    *dst++ = (char)(0x80|(0x3f&(chr>> 6)));
    *dst++ = (char)(0x80|(0x3f&(chr)));
    return dst;
}

static inline char *
ENCODE_UC4(char dst[], char32_t chr) {
    *dst++ = (char)(      0xf0|(chr>>18));
    *dst++ = (char)(0x80|(0x3f&(chr>>12)));
    *dst++ = (char)(0x80|(0x3f&(chr>> 6)));
    *dst++ = (char)(0x80|(0x3f&(chr>> 0)));
    return dst;
}

static inline char *
ENCODE_UTF_8(char dst[], char32_t chr) {
    if (chr > 0x7f) {
        if (chr > 0x7ff) {
            if (chr > 0xffff) {
                if (chr > 0x10ffff) return ENCODE_EXC();
                return ENCODE_UC4(dst, chr);
            }
            return ENCODE_UC3(dst, chr);
        }
        return ENCODE_UC2(dst, chr);
    }
    return ENCODE_UC1(dst, chr);
}

static inline ptrdiff_t
NEXT_UTF_8(void *restrict *restrict dst, size_t len, char32_t chr) {
    if (chr > 0x7f) {
        if (chr > 0x7ff) {
            if (chr > 0xffff) {
                if (chr > 0x10ffff) return 0-(errno=EILSEQ);
                if (len < 4) return 0;
                *dst = ENCODE_UC4(*dst, chr);
                return 4;
            }
            if (len < 3) return 0;
            *dst = ENCODE_UC3(*dst, chr);
            return 3;
        }
        if (len < 2) return 0;   
        *dst = ENCODE_UC2(*dst, chr);
        return 2;
    }
    if (!len) return 0;
    *dst = ENCODE_UC4(*dst, chr);
    return 1;
}

static inline char32_t
DECODE_UTF_8(const char src[], ptrdiff_t *off) {
    ptrdiff_t i = *off;
    char32_t u = src[i++];
    if (u < 0x80) {
        *off = i;
        return u;
    }
    if (u < 0xc2 || u > 0xf4) err: {
        return DECODE_EXC(0, 0);
    }
    char32_t b = src[i++];
    if (u < 0xe0) {
        if (b < 0x80 || 0xbf < b) goto err;
        *off = i;
        return ((u-0xc0)<<6)|(b&0x3f);
    }
    char32_t c;
    if (u < 0xf0) {
        if (b > 0xbf || b < (u == 0xe0 ? 0xa0 : 0x80)) goto err;
        c = src[i++];
        if (c > 0xbf || c < 0x80) goto err;
        *off = i;
        return ((u-0xe0)<<12)|((b&0x3f)<<6)|(c&0x3f);
    }
    if (u < 0xf1) {
        if (b < 0x90 || 0xbf < b) goto err;
    }
    else {
        if (b < 0x80 || b > (u == 0xf4 ? 0x8f : 0xbf)) goto err;
    }
    c = src[i++];
    if (c < 0x80 || 0xbf < c) goto err;
    char32_t d = src[i++];
    if (d < 0x80 || 0xbf < d) goto err;
    *off = i;
    return ((u-0xf0)<<18)|((0x3f&b)<<12)|((0x3f&c)<<6)|((0x3f&d));
}

/*
ptrdiff_t
ascii_decode
(
    const void*restrict src,
    size_t              len,
    ucs_t     *restrict dst,
    ptrdiff_t *restrict pos
)
{
    ptrdiff_t c = *pos;
    ptrdiff_t b = 0;
    if (c < 0) return 0-(errno=EINVAL);
    const size_t nel = dst->mem.nel;
    {
#   define ascii_decode(m, T) \
    for (; c < nel; b++, c++) {\
        dst->mem.m[c] = ((char *) src)[b];\
        if (dst->mem.m[c] > 0x7f) goto eilseq;}\
    return (*pos=b*(ptrdiff_t) sizeof(T));
    }
    switch (dst->hdr.ucs)
    {
        case UCS_B: {ascii_decode(b, char);}
        case UCS_H: {ascii_decode(h, char16_t);}
        case UCS_U: {ascii_decode(u, char32_t);}
        default: unreachable();
    }
#   undef ascii_decode
    eilseq: {return 0-(errno=EILSEQ);}
    enomem: {return 0-(errno=ENOMEM);}
}

#define ASCII_FMBSLEN(l, P, T) \

    switch (src->hdr.ucs) 
    {
        case UCS_B: {ascii_encode(b, char);}
        case UCS_H: {ascii_encode(h, char16_t);}
        case UCS_U: {ascii_encode(u, char32_t);}
        default: unreachable();
    }

    eilseq: {return 0-(errno=EILSEQ);}
#   undef ascii_encode
}
*/

// char (*cunt(void))[5][2]  {return &five_pairs;}

/*
word_t utf_8_ucnext(ucs_t *restrict src, ptrdiff_t *restrict off);
word_t utf_16le_ucnext(ucs_t *restrict src, ptrdiff_t *restrict off);
word_t utf_16be_ucnext(ucs_t *restrict src, ptrdiff_t *restrict off);
word_t utf_16be_ucnext(ucs_t *restrict src, ptrdiff_t *restrict off);

ptrdiff_t
utf_32be_encode(
    void         **restrict dst,
    size_t                  len,
    const ucs_tn  *restrict src,
) 
{
    ptrdiff_t n;
    if (!len || !(n=src->mem.nel)) return 0;
    char32_t *d = *dst;
    switch (src->hdr.ucs) {
        case UCS_U: {
            if ((len/=sizeof(char32_t)) < n) n = (ptrdiff_t) len;
            n = MEMNTOW(d, src->mem.u, n, AS_WORD); 
            break;
        }
        case UCS_H: {
            len /= 2;
            if (len < n) n = (ptrdiff_t) len;
            n = MEMNTOW(d, src->mem.h, n, AS_HWORD);
            break;
        }
            b = n*sizeof(char32_t);
            if (b > len) b = (ptrdiff_t) len;
            if (!(b/=sizeof()))
            break;
        }
        case UCS_H: {
            n = MEMTOW(d, src, n, AS_UINT|AS_NETORDER); 
            
            for (; i <; i++) {
                if (i >= src->mem.nel) break;
                SWAP4(p, src->mem.u+i);
            }
            return i*4;
        }
        case UCS_H: {
            for (; i < len && 
        }
        
            MEMTO
        }
    }
}
*/
/*
{
s = 0123456789
d =     456789
a = 0123012345
c           45
m =     0123
? =     012345
6-4=2

d =        789ab
s = 01234
l =      5

l = d-s = 7



o(verlap) = 4-0
l = 6-o

n = 6
s =  012345
l =        6789
d =      456789   
a = l-d (2)
o = n-a

*/

void badmove(void *d, const void *s, size_t n) {
    ptrdiff_t i;
    if (n == 0) return;
    if (d <= s) return;
    void *l = (void *) s+n;
    size_t o;
    if (l <= d) {
        for (i=0; i < n; i++) {
            ((byte_t *) d)[i] = ((byte_t *) s)[i];
        }
        return;
    }
    size_t a = (size_t)(l-d);
    byte_t *m = malloc(a);
    for (i=0; i < a; i++) m[i] = ((byte_t *) d)[i];
    o = n-a;
    for (i=0; i < o; i++) {
        ((byte_t *) d)[i] = ((byte_t *) s)[i];
    }
    for (a=0; i < n; i++, a++) {
        ((byte_t *) d)[i] = m[a];
    }
    free(m);
}

ptrdiff_t
utf_16_decode
(
    const void    *restrict src, // char16_t, actually 
    size_t                  len,
    ucs_t         *restrict dst,
    ptrdiff_t     *restrict off
);


ptrdiff_t 
utf_16_encode
(
    char                dst[restrict],
    size_t              len,
    const char16_t      src[restrict],
    size_t              nel,
    ptrdiff_t *restrict off
);

/*
An encoding {name} requires the following subroutines which
are used to convert between the different representations a
string can have. Using "UTF-16LE":

ptr
    * a name_ccs enumeration identifying it 
    * name_encode (dst, len, src, nel, off)
    * name_decode (dst, len, src, nel, off)
    * name_mbnext (src, len, off)
    * name_ucnext (src, len, off)
    * name_ucinit 
subroutines:

size_t 
mbsrtowcs(
    wchar_t     *restrict dst, 
    const char **restrict src,
    size_t                len, 
    mbstate_t   *restrict ps
);

size_t 
wcsrtombs(
    char            *restrict dst, 
    const wchar_t  **restrict src,
    size_t                    len, 
    mbstate_t       *restrict ps);

ptrdiff_t
ucs_mbslen(
    const void *restrict mbs,
    ssize_t              len,
    ccs_t                ccs)

    Get the number of code units in the array that results 
    from using {ccs} to decode up to the first {len} bytes
    of memory at the address {mbs}.
    
    I.e., {ucs_mbslen} decodes the input bytes without need
    of memory to store the result.
    {
        len = ucs_hmbslen(
            src=(char*){(char[]{38,32,38,32,0,0}}, 
            6,
            utf_16le_ccs
        )
    }
    Based on that example, the following would occur:
        * {len} set to 3, since 3 UTF-16 code units are what
        those 6 bytes get decoded as.
        * {src} is incremented by 6
        
    Note that it's possible to directly call 
    
    beginning at
    
    by decoding up to {len} bytes from {mbs} usi
    
    located at {mbp} 
    using {ccs} encoding.
    
    Put another way, {ucs_mbslen} decodes the byte sequence
    without storing more state than is necessary to compute 
    the length and provide diagnostic information if an error
    occurs.
    
    {ucs_mbslen(u"xyz", )
    g
    without actually storing the deco
    that
    is pointed to bt 
    the 
    
    a {len} byte memory block 
    
    harray of code units than 
    an array of {len} bytes is
    located at the address pointed 
    to by {mbs}, is decoded as 
    that begin at the address 
    representation  
    
    Get the size in bytes of the array of code units {mbs} is
    decoded as using {
    needed to store an array of code 
    units o
    xe
    Determine the number of bytes needed to store an array 
ptrdiff_t
ucs_encode(
    void          *restrict dst,
    size_t                  len,
    ccs_t                   ccs,
    const ucs_t   *restrict src,
    ptrdiff_t     *restrict off)
    
    Encode the compact representation of a Unicode string
    using the algorithm specified by {ccs}. The result is
    copied into the {len} element array {dst} whose element
    type is determined by the encoding. If {dst} is NULL, 
    the encoder will simply skip the "write to dst" step.
    
    If {off} is NULL, the codec automatically calls the init
    routine if one is defined. Otherwise, it assumes that it 
    points to a {ptrdiff_t} containing the index of the next
    code point in {src}. 
    
    The result is the number of encoded elements that were or
    would have been copied to {dst} or an integer equal to
    the negated error number at the instant {encode} returns.    

    If {off} was provided and {encode} returns because the 
    last code point was successfully converted, it's value
    is set to -1. 
);
    
    
*/

/*
ptrdiff_t
utf_8_encode
(
    void          *restrict dst, 
    size_t                  len, 
    const ucs_t   *restrict src,
    ptrdiff_t     *restrict pos
)
{
    void *const stp = dst;
    ptrdiff_t x; 
    if (!pos || !dst || !src || *pos < 0) {
        return 0-(errno=EINVAL);
#       define utf_8_encode(m) \
    for (; *pos < src->mem.nel; len-=x, pos[0]++) {\
        x = NEXT_UTF_8(&dst, len, src->mem.m[*pos]);\
        if (x < 1) return x < 0 ? x : dst-stp;\
    } break
    }
    switch (src->hdr.ucs)
    {
        case UCS_B: {utf_8_encode(b);}
        case UCS_H: {utf_8_encode(h);}
        case UCS_U: {utf_8_encode(u);}
#       undef        utf_8_encode
        default: unreachable();
    }
    return dst-stp;
}

void
test_utf_8_encode(void) {
    ucs_t src = STATIC_UCS_U("ﬀuck you");
    char dst[256] = {0};
    ptrdiff_t pos = 0;
    ptrdiff_t put = utf_8_encode(dst, sizeof dst, src, &pos);
    const unsigned char utf[] = {
        239,172,128,117,99,107,32,121,111,195,188,
        0
    };
    if (memcmp(dst, utf, sizeof utf)) {
        printf("line %d: utf_8_encode failed",__LINE__);
        exit(1);
    }
}
*/

/*

#define ASCII_FENCODE(as, P, T) \
static inline ptrdiff_t \
ASCII_##P##MBNEXT(\
    char      *restrict dst,\
    const T   *restrict ucs,\
    size_t              nel,\
    ptrdiff_t *restrict pos)\
{\
    if (!nel) return !pos ? 0 : SET_END_OF_UCS(pos, 0);\
    if (!pos) return ((*dst = *ucs) > 0x7f) ? 0-(errno=EILSEQ) : 1;\
    if (*pos == END_OF_UCS) return 0;\
    if (*pos >= nel)        return SET_END_OF_UCS(pos, 0);\
    if (0x7f < (*dst=ucs[*pos])) return 0-(errno=EILSEQ);\
    return ((*pos+=1), 1);\
}\
\
static inline ptrdiff_t \
ASCII_##P##ENCODE\
(\
    void     **restrict dst,\
    size_t              len,\
    const T   *restrict src,\
    size_t              nel,\
    ptrdiff_t *restrict pos\
)\
{\
    if (!src) return 0-(errno=ENOMEM);\
    if (*pos == END_OF_UCS) return 0;\
    char *restrict nex = *dst;\
    char    *const end =  nex+len;\
    for ( ; *pos < nel && nex < end;) {\
        if (0x7f < (*nex++=src[*pos])) {\
            *dst = nex;\
            return 0-(errno=EILSEQ);\
        }\
    }\
    return SET_END_OF_UCS(pos, (void *) nex-(void *) *dst);\
}\
\
static ptrdiff_t ascii_##as##mbnext(\
    char      *restrict dst,\
    const T   *restrict src,\
    size_t              nel,\
    ptrdiff_t *restrict pos)\
{   return ASCII_##P##MBNEXT(dst, src, nel, pos);}\
\
static ptrdiff_t ascii_##as##encode \
(\
    void     **restrict dst,\
    size_t              len,\
    const T   *restrict src,\
    size_t              nel,\
    ptrdiff_t *restrict pos\
)\
{   return ASCII_##P##ENCODE(dst, len, src, nel, pos);}

ASCII_FENCODE(b, B, char)
ASCII_FENCODE(h, H, char16_t)
ASCII_FENCODE(u, U, char32_t)
#undef ASCII_FENCODE

#define ucs_MEM_FROM_TYPE(ucs, type) _Generic(\
    ((type *) 0),\
    char *:     (((ucs_t *) ucs)->mem.b),\
    char16_t *: (((ucs_t *) ucs)->mem.h),\
    char32_t *: (((ucs_t *) ucs)->mem.u))

#define encoding_api(ccs, api) \
ccs##_##api##_f[] = {\
    [UCS_B] = ccs##_b##api##_f\
    [UCS_H] = ccs##_h##api##_f\
    [UCS_U] = ccs##_s##api##_f}


static void *encoding_api(ascii, mbnext);
static void *encoding_api(ascii, encode);

ptrdiff_t
ascii_encode
(
    void     **restrict dst,
    size_t              len,
    ucs_t     *restrict src,
    ptrdiff_t *restrict off
)
{
    ptrdiff_t   pos;
    if (!off) pos=0, off=&pos;
    if (!dst) {
        if (len) return 0-(errno=EINVAL);
        dst = &(char[1]){0};
    }
    switch (src->ucs) {
        case UCS_B: return ASCII_BENCODE(dst, len, src->mem.b, src->nel, off);
        case UCS_H: return ASCII_HENCODE(dst, len, src->mem.b, src->nel, off);
        case UCS_U: return ASCII_UENCODE(dst, len, src->mem.b, src->nel, off);
        default: unreachable();
    }
}

void
ascii_encode_test(void) {
    char        dst[256] = {0};
    ptrdiff_t   off = 0;
    ucs_t       src = STATIC_UCS_H("0123456789ABCDEF");
    char16_t   *ptr = src
    ptrdiff_t   end = ascii_encode(dst, sizeof dst, &src, &off);
    if (memcmp(dst, "0123456789ABCDEF", 17)) {
        printf("dst != 0123456789ABCDEF\n");
        exit(1);
    }
}

*/
