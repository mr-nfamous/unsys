
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/mman.h>
#include <wchar.h>
#include <uchar.h>

#define UNICODE_MAX 0x10FFFF

enum {
    UTF_8_BTP_NULL, /* 0; these bytes never occur in valid UTF-8 */
    UTF_8_BTP_SING, /* 1; the ASCII characters: [0x000000..0x00007f] */
    UTF_8_BTP_DOUB, /* 2; the first byte of:    [0x000080..0x0007FF] */
    UTF_8_BTP_TRIP, /* 3; the first byte of:    [0x000800..0x00FFFF] */
    UTF_8_BTP_QUAD, /* 4; the first byte of:    [0x00ffff..0x10FFFF] */
    UTF_8_BTP_CONT, /* 5; continuation byte */
};

static
const char *ASCII_REPR[128] = {

    "\\0",   "\\x01", "\\x02", "\\x03",
    "\\x04", "\\x05", "\\x06", "\\a",
    "\\b",   "\\t",   "\\n",   "\\v",
    "\\f",   "\\r",   "\\x0f", "\\x0f",
    "\\x10", "\\x11", "\\x12", "\\x13",
    "\\x14", "\\x15", "\\x16", "\\x17",
    "\\x18", "\\x19", "\\x1a", "\\x1b",
    "\\x1c", "\\x1d", "\\x1e", "\\x1f",
    " ",   "!",   "\\\"","#",   "$",   "%",   "&",   "'",
    "(",   ")",   "*",   "+",   ",",   "-",   ".",   "/",
    "0",   "1",   "2",   "3",   "4",   "5",   "6",   "7",
    "8",   "9",   ":",   ";",   "<",   "=",   ">",   "?",
    "@",   "A",   "B",   "C",   "D",   "E",   "F",   "G",
    "H",   "I",   "J",   "K",   "L",   "M",   "N",   "O",
    "P",   "Q",   "R",   "S",   "T",   "U",   "V",   "W",
    "X",   "Y",   "Z",   "[",   "\\\\","]",   "^",   "_",
    "`",   "a",   "b",   "c",   "d",   "e",   "f",   "g",
    "h",   "i",   "j",   "k",   "l",   "m",   "n",   "o",    
    "p",   "q",   "r",   "s",   "t",   "u",   "v",   "w",
    "x",   "y",   "z",   "{",   "|",   "}",   "~",   "\\x7f",
};

static 
const signed char ASCII_REPR_LEN[128] = {
    2,4,4,4,4,4,4,2,2,2,2,2,2,2,4,4,
    4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
    1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,
};
    
struct UTF_8_DATA {
    char        BTP[256];
    char        CBI[256];
    char32_t    MB1[256];
    char        MB2[64];
    char16_t    MB3[64];
    char32_t    MB4[64];
    char        SB4[16];
    char        SB3[16];
    char        SB2[32];
    char        CBO[64];
};

static
const struct UTF_8_DATA 
UTF_8 = {

    .BTP = {
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
        5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
        5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
        5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
        0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
        2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
        3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
        4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,
    },

    .CBI = {
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
        0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
        0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
        0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,
        0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,
        0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,
        0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,
        0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,
        0x38,0x39,0x3a,0x3b,0x3c,0x3d,0x3e,0x3f,   
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    },

    .MB1 = {
        000,001,002,003,004,005,006,007,
        010,011,012,013,014,015,016,017,
        020,021,022,023,024,025,026,027,
        030,031,032,033,034,035,036,037,
        ' ','!','"','#','$','%','&',047,
        '(',')','*','+',',','-','.','/',
        '0','1','2','3','4','5','6','7',
        '8','9',':',';','<','=','>','?',
        '@','A','B','C','D','E','F','G',
        'H','I','J','K','L','M','N','O',
        'P','Q','R','S','T','U','V','W',
        'X','Y','Z','[',0x5c,']','^','_',
        '`','a','b','c','d','e','f','g',
        'h','i','j','k','l','m','n','o',
        'p','q','r','s','t','u','v','w',
        'x','y','z','{','|','}','~',127,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        [0xc2]=0x000080,[0xc3]=0x0000c0,
        [0xc4]=0x000100,[0xc5]=0x000140,
        [0xc6]=0x000180,[0xc7]=0x0001c0,
        [0xc8]=0x000200,[0xc9]=0x000240,
        [0xca]=0x000280,[0xcb]=0x0002c0,
        [0xcc]=0x000300,[0xcd]=0x000340,
        [0xce]=0x000380,[0xcf]=0x0003c0,
        [0xd0]=0x000400,[0xd1]=0x000440,
        [0xd2]=0x000480,[0xd3]=0x0004c0,
        [0xd4]=0x000500,[0xd5]=0x000540,
        [0xd6]=0x000580,[0xd7]=0x0005c0,
        [0xd8]=0x000600,[0xd9]=0x000640,
        [0xda]=0x000680,[0xdb]=0x0006c0,
        [0xdc]=0x000700,[0xdd]=0x000740,
        [0xde]=0x000780,[0xdf]=0x0007c0,
        [0xe0]=0x000000,[0xe1]=0x001000,
        [0xe2]=0x002000,[0xe3]=0x003000,
        [0xe4]=0x004000,[0xe5]=0x005000,
        [0xe6]=0x006000,[0xe7]=0x007000,
        [0xe8]=0x008000,[0xe9]=0x009000,
        [0xea]=0x00a000,[0xeb]=0x00b000,
        [0xec]=0x00c000,[0xed]=0x00d000,
        [0xee]=0x00e000,[0xef]=0x00f000,
        [0xf0]=0x000000,[0xf1]=0x040000,
        [0xf2]=0x080000,[0xf3]=0x0C0000,
        [0xf4]=0x100000,
    },

    .MB2 = {
        0x00, 0x01, 0x02, 0x03,
        0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0a, 0x0b,
        0x0c, 0x0d, 0x0e, 0x0f,
        0x10, 0x11, 0x12, 0x13,
        0x14, 0x15, 0x16, 0x17,
        0x18, 0x19, 0x1a, 0x1b,
        0x1c, 0x1d, 0x1e, 0x1f,
        0x20, 0x21, 0x22, 0x23,
        0x24, 0x25, 0x26, 0x27,
        0x28, 0x29, 0x2a, 0x2b,
        0x2c, 0x2d, 0x2e, 0x2f,
        0x30, 0x31, 0x32, 0x33,
        0x34, 0x35, 0x36, 0x37,
        0x38, 0x39, 0x3a, 0x3b,
        0x3c, 0x3d, 0x3e, 0x3f,
    },

    .MB3 = {
        0x0000, 0x0040, 0x0080, 0x00c0,
        0x0100, 0x0140, 0x0180, 0x01c0,
        0x0200, 0x0240, 0x0280, 0x02c0,
        0x0300, 0x0340, 0x0380, 0x03c0,
        0x0400, 0x0440, 0x0480, 0x04c0,
        0x0500, 0x0540, 0x0580, 0x05c0,
        0x0600, 0x0640, 0x0680, 0x06c0,
        0x0700, 0x0740, 0x0780, 0x07c0,
        0x0800, 0x0840, 0x0880, 0x08c0,
        0x0900, 0x0940, 0x0980, 0x09c0,
        0x0a00, 0x0a40, 0x0a80, 0x0ac0,
        0x0b00, 0x0b40, 0x0b80, 0x0bc0,
        0x0c00, 0x0c40, 0x0c80, 0x0cc0,
        0x0d00, 0x0d40, 0x0d80, 0x0dc0,
        0x0e00, 0x0e40, 0x0e80, 0x0ec0,
        0x0f00, 0x0f40, 0x0f80, 0x0fc0,
    },

    .MB4 = {
        0x000000, 0x001000, 0x002000, 0x003000,
        0x004000, 0x005000, 0x006000, 0x007000,
        0x008000, 0x009000, 0x00a000, 0x00b000,
        0x00c000, 0x00d000, 0x00e000, 0x00f000,
        0x010000, 0x011000, 0x012000, 0x013000,
        0x014000, 0x015000, 0x016000, 0x017000,
        0x018000, 0x019000, 0x01a000, 0x01b000,
        0x01c000, 0x01d000, 0x01e000, 0x01f000,
        0x020000, 0x021000, 0x022000, 0x023000,
        0x024000, 0x025000, 0x026000, 0x027000,
        0x028000, 0x029000, 0x02a000, 0x02b000,
        0x02c000, 0x02d000, 0x02e000, 0x02f000,
        0x030000, 0x031000, 0x032000, 0x033000,
        0x034000, 0x035000, 0x036000, 0x037000,
        0x038000, 0x039000, 0x03a000, 0x03b000,
        0x03c000, 0x03d000, 0x03e000, 0x03f000,
    },
    
    .SB4 = {
        0xf0,0xf1,0xf2,0xf3,0xf4,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    },
    
    .SB3 = {
        0xe0,0xe1,0xe2,0xe3,0xe4,0xe5,0xe6,0xe7,
        0xe8,0xe9,0xea,0xeb,0xec,0xed,0xee,0xef,
    },
    
    .SB2 = {
        0x00,0x00,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,
        0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,
        0xd0,0xd1,0xd2,0xd3,0xd4,0xd5,0xd6,0xd7,
        0xd8,0xd9,0xda,0xdb,0xdc,0xdd,0xde,0xdf,
    },
    .CBO = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,
        0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,
        0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,
        0x98,0x99,0x9a,0x9b,0x9c,0x9d,0x9e,0x9f,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,
        0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,
        0xb0,0xb1,0xb2,0xb3,0xb4,0xb5,0xb6,0xb7,
        0xb8,0xb9,0xba,0xbb,0xbc,0xbd,0xbe,0xbf,
    },
    
};

static inline char32_t
UTF_8_DECODE(const char src[restrict], ptrdiff_t *restrict pos) {
    ptrdiff_t       i = *pos;
    ptrdiff_t       c = src[i];
    const ptrdiff_t t = UTF_8.BTP[c];
    ptrdiff_t       b = src[i++];
    char32_t        v = UTF_8.MB1[b];
    switch (t) {
        case UTF_8_BTP_QUAD: {
            b = src[i++];
            c = UTF_8.CBI[b];
            if (c == 0xFF) {
                break;
            }
            v = UTF_8.MB4[c];
        }
        case UTF_8_BTP_TRIP: {
            b = src[i++];
            c = UTF_8.CBI[b];
            if (c == 0xFF) {
                break;
            }
            v += UTF_8.MB3[(ptrdiff_t) c];
        }
        case UTF_8_BTP_DOUB: {
            b = src[i++];
            c = UTF_8.CBI[b];
            if (c == 0xFF) {
                break;
            }
            v += UTF_8.MB2[c];
        }
        case UTF_8_BTP_SING: {
            *pos = i;
            return v;
        }
    }
    errno = EILSEQ;
    return (char32_t) WEOF;
}

static inline ptrdiff_t
UTF_8_ENCODE(char32_t src, char dst[restrict]) {
    const uint32_t c = (unsigned) src;
    if (src > 0x7F) {
        if (src > 0x7FF) {
            if (src > 0xFFFF) {
                if (src > UNICODE_MAX) {
                    errno = EILSEQ;
                    return 0;
                }
                dst[0]  = UTF_8.SB4[017&(c>>18)];
                dst[1]  = UTF_8.CBO[077&(c>>12)];
                dst[2]  = UTF_8.CBO[077&(c>> 6)];
                dst[3]  = UTF_8.CBO[077&(c)];
                return 4;
            }
            dst[0]      = UTF_8.SB3[017&(c>>12)];
            dst[1]      = UTF_8.CBO[077&(c>> 6)];
            dst[2]      = UTF_8.CBO[077&(c)];
            return 3;
        }
        dst[0]          = UTF_8.SB2[037&(c>>6)];
        dst[1]          = UTF_8.CBO[077&(c)];
        return 2;
    }
    dst[0] = (char) c;
    return 1;
    
}

static inline ptrdiff_t
UNICODE_ESC_32F(char32_t src, FILE *restrict dst) {
    return fprintf(dst, "\\U%08X", (unsigned) src);
}

static inline ptrdiff_t
UNICODE_ESC_16F(char16_t src, FILE *restrict dst) {
    return fprintf(dst, "\\u%04X", (unsigned) src);
}

static inline ptrdiff_t
UNICODE_ESC_8F(char      src, FILE *restrict dst) {
    return fprintf(dst, "\\x%02X", (unsigned) src);
}

static inline ptrdiff_t
UNICODE_ESC_32S(char32_t src, char *restrict dst) {
    return snprintf(dst, 16, "\\U%08X", (unsigned) src);
}

static inline ptrdiff_t
UNICODE_ESC_16S(char16_t src, char *restrict dst) {
    return snprintf(dst, 16, "\\u%04X", (unsigned) src);
}

static inline ptrdiff_t
UNICODE_ESC_8S(char src, char *restrict dst) {
    return snprintf(dst, 16, "\\x%02X", (unsigned) src);
}


static inline ptrdiff_t
UTF_8_REPRS(const char src[restrict], char dst[restrict]) {
    ptrdiff_t off = 0; /* src offset */
    ptrdiff_t pos = 1; /* dst offset */
    *dst = '"';
    int safe = 0;
    while (1) {
        assert(safe++ < 1024);
        const wint_t chr = (wint_t) UTF_8_DECODE(src, &off);
        if (chr == WEOF) {
            fail: {
                return PTRDIFF_C(0)-1;
            }
        }
        if (chr == 0x00) {
            dst[pos++] = '"';
            dst[pos] = 0;
            return pos;
        }
        if (chr > 0x7F) {
            if (chr > 0xFFFF) {
                pos += UNICODE_ESC_32S((char32_t) chr, dst+pos);
            }
            else {
                pos += UNICODE_ESC_16S((char16_t) chr, dst+pos);
            }
        }
        else {
            const char *seq = ASCII_REPR[chr];
            while (*seq) {
                dst[pos++] = *seq++;
            }
        }
    }
}

/*
('Cc', 65)
('Cf', 37)
('Cn', 1150)
('Ll', 1148)
('Lm', 182)
('Lo', 3469)
('Lt', 31)
('Lu', 977)
('Mc', 206)
('Me', 10)
('Mn', 892)
('Nd', 290)
('Nl', 42)
('No', 232)
('Pc', 4)
('Pd', 16)
('Pe', 43)
('Pf', 10)
('Pi', 12)
('Po', 306)
('Ps', 46)
('Sc', 48)
('Sk', 67)
('Sm', 920)
('So', 2067)
('Zl', 1)
('Zp', 1)
('Zs', 16)
;2026;HORIZONTAL ELLIPSIS;Po;0;ON;<compat> 002E 002E 002E;;;;N;;;;;
0    1                   2  3 4  4

 0060;GRAVE ACCENT;Sk;0;ON;;;;;N;SPACING GRAVE;;;;
0    1            2  3 4  56789 A             BCDE

[0] = CODE: "0060"
[1] = NAME: "GRAVE ACCENT"
[2] = GC:   "Sk"
[3] = CCC:  "0"
[4] = BC:   "ON"
[5] = DM:  ""
[6] = DEC:  ""
[7] = DIG: 
[8] = NUM:
[9] = MIRRORED: ""
[A] = OLD NAME
[B] = COMMENT
[C] = UPPER
[D] = LOWER
[E] = TITLE

        ["C", "Cc|Cf|Cn|Co|Cs"],
        ["L", "Ll|Lm|Lo|Lt|Lu"],
        ["M", "Mc|Me|Mc"],
        ["N", "Nd|Nl|No"],
        ["P", "Pc|Pd|Pe|Pf|Pi|Po|Ps"],
        ["S", "Sc|Sk|Sm|So"],
        ["Z", "Zl|Zp|Zs"],
        ]

     ––––––––––––––––––--+-ISCHR-+-ISDES-+
    GRAPH | L M N P S Zs|#######|#######|
    ––––––+–––––––––––––+#######|#######|
    FORMA | Cf Zl Zp    |#######|#######|
    ––––––+–––––––––––––+#######|#######|
    CNTRL | Cc          |#######|#######|
    ––––––+–––––––––––––+#######|#######|
    PRIVT | Co          |#######|#######|
    ––––––+–––––––––––––+–NOCHR-+#######|
    SRGTE | Cs          |       |#######|
    ––––––+–––––––––––––+       |#######|
    NOCHR |             |       |#######|
    ––––––+ Cn +--------+-------+-UNDES-+
    RESRV |             |               |
    ––––––+–––––––––––––––––––––––––----+
    
    111 11111
    
    Alphabetic(C) =>
            Other_Alphabetic(C)
        ||  General_Category(C) in {Nl,Lu,Ll,Lt,Lm,Lo}
 
    Case_Ignorable(C) =>
            Word_Break(C) in {MidLetter,MidNumLet,Single_Quote}
        ||  gc(c) in {Mn,Me,Cf,Lm,Sk}

    ID_Start(c) =>
            gc(c) in {Lu,Ll,Lt,Lm,Lo,Nl}
        ||  Other_ID_Start(c)

    ID_Continue(c) =>
            ID_Start(c) 
        ||  gc(c) in {Mn,Mc,Nd,Pc}
        ||  Other_ID_Continue(c)

    Default_Ignorable_Code_Point(c) =>
            Other_Default_Ignorable_Code_Point(c)
        ||  Variation_Selector(c)
        ||  gc(c) in {Cf} 
        &!  White_Space(c)
        &!  c in [FFF9..FFFB]
        &!  c in [13430..13438]

    Grapheme_Extend(c) => 
            Other_Grapheme_Extend(c)
        ||  gc(c) in {Me, Mn}

    Grapheme_Base(c) =>
            c in [0..10FFFF]
        &!  gc(c) in {Cc,Cf,Cs,Co,Cn,Zl,Zp}
        &!  Grapheme_Extend(c)

CHARMAP
.cf         : Case_Folding
.equideo    : Equivalent_Unified_Ideograph
.fc_nfkc    : FC_NFKC_Closure
.isc        : ISO_Comment
.lc         : Lowercase_Mapping
.nfkc_cf    : NFKC_Casefold
.scf        : Simple_Case_Folding
.slc        : Simple_Lowercase_Mapping
.stc        : Simple_Titlecase_Mapping
.suc        : Simple_Uppercase_Mapping
.tc         : Titlecase_Mapping
.uc         : Uppercase_Mapping

STRMAP 

.bmg            : Bidi_Mirroring_Glyph
<BidiMirroring.txt>

.bpb            : Bidi_Paired_Bracket
<BidiBrackets.txt>

.dm             : Decomposition_Mapping
.na             : Name
.name_alias     : Name_Alias
.nv             : Numeric_Value
.scx            : Script_Extensions
.na1            : Unicode_1_Name


BOOLEAN

<PropList.txt>
    .ahex   : ASCII_Hex_Digit                   000030..000066 N=22
    .bidi_c : Bidi_Control                      00061C..002069 N=12
    .dash   : Dash                              00002D..010EAD N=30
    .dep    : Deprecated                        000149..0E0001 N=15
    .dia    : Diacritic                         00005E..01E94A N=1064
    .ext    : Extender                          0000B7..01E946 N=50
    .hex    : Hex_Digit                         000030..00FF46 N=44
    .hyphen : Hyphen                            00002D..00FF65 N=11
    .ideo   : Ideographic                       003006..03134A N=101661
    .idsb   : IDS_Binary_Operator               002FF0..002FFB N=10
    .idst   : IDS_Trinary_Operator              002FF2..002FF3 N=2
    .join_c : Join_Control                      00200C..00200D N=2
    .qmark  : Quotation_Mark                    000022..00FF63 N=30
    .term   : Terminal_Punctuation              000021..01DA8A N=276
    .omath  : Other_Math                        00005E..01EEBB N=1362
    .oalpha : Other_Alphabetic                  000345..01F189 N=1404
    .olower : Other_Lowercase                   0000AA..0107BA N=244
    .oupper : Other_Uppercase                   002160..01F189 N=120
    .nchar  : Noncharacter_Code_Point           00FDD0..10ffff N=66
    .ogr_ext: Other_Grapheme_Extend             0009BE..0E007F N=127
    .radical: Radical                           002E80..002FD5 N=329
    .uideo  : Unified_Ideograph                 003400..03134A N=92865
    .sd     : Soft_Dotted                       000069..01DF1A N=47
    .oids   : Other_ID_Start                    001885..00309C N=6
    .oidc   : Other_ID_Continue                 0000B7..0019DA N=12
    .sterm  : Sentence_Terminal                 000021..01DA88 N=152
    .vs     : Variation_Selector                00180B..0E01EF N=260
    .pat_ws : Pattern_White_Space               000009..002029 N=11
    .pat_syn: Pattern_Syntax                    000021..00FE46 N=2760
    .ri     : Regional_Indicator                01F1E6..01F1FF N=26
    .ws     : White_Space                       000009..003000 N=25
    .pcm    : Prepended_Concatenation_Mark      000600..0110CD N=13
    .odi    :Other_Default_Ignorable_Code_Point 00034F..0E0FFF N=3776

<emoji/emoji-data.txt>
    .emoji  : Emoji                             000023..01FAF6 N=1404
    .ecomp  : Emoji_Component                   000023..0E007F N=146
    .emod   : Emoji_Modifier                    01F3FB..01F3FF N=5
    .ebase  : Emoji_Modifier_Base               00261D..01FAF6 N=132
    .epres  : Emoji_Presentation                00231A..01FAF6 N=1185
    .extpic : Extended_Pictographic             0000A9..01FFFD N=3537

<DerivedCoreProperties.txt>
    .di     : Default_Ignorable_Code_Point      0000AD..0E0FFF N=4174
    .math   : Math                              00002B..01EEF1 N=2310
    .alpha  : Alphabetic                        000041..03134A N=133396
    .lower  : Lowercase                         000061..01E943 N=2471
    .upper  : Uppercase                         000041..01F189 N=1951
    .cased  : Cased                             000041..01F189 N=4453 
    .ci     : Case_Ignorable                    000027..0E01EF N=2602
    .cwl    : Changes_When_Lowercased           000041..01E921 N=1433
    .cwu    : Changes_When_Uppercased           000061..01E943 N=1525
    .cwt    : Changes_When_Titlecased           000061..01E943 N=1452
    .cwcf   : Changes_When_Casefolded           000041..01E921 N=1506
    .cwcm   : Changes_When_Casemapped           000041..01E943 N=2927
    .ids    : ID_Start                          000041..03134A N=131997
    .idc    : ID_Continue                       000030..0E01EF N=135072
    .xidc   : XID_Continue                      000030..0E01EF N=135053
    .xids   : XID_Start                         000041..03134A N=131974
    .gr_ext : Grapheme_Extend                   000300..0E01EF N=2090
    .gr_base: Grapheme_Base                     000020..03134A N=142539
    .gr_link: Grapheme_Link                     00094D..011D97 N=63

<extracted/DerivedBinaryProperties.txt>
    .bidi_m : Bidi_Mirrored                     000028..01D7C3 N=553

<CompositionExclusions.txt>
    .ce     : Composition_Exclusion             000958..00FB4E N=67

<DerivedNormalizationProps.txt>
    .fc_nfkc: FC_NFKC_Closure 037A..1F190 N=637
    .xo_nfc : Expands_On_NFC 0344..1D1C0 N=85 !DEP 6,0
    .xo_nfd : Expands_On_NFD 1D1BB..1D1C0 N=12216 !DEP 6,0
    .xo_nfkc: Expands_On_NFKC 00A8..1F248 N=1237 !DEP 6,0
    .xo_nfkd: Expands_On_NFKD 00A8..1F248 N=13390 !DEP 6,0
    .cwkcf  : Changes_When_NFKC_Casefolded 0041..E0FFF N=10429
    .nfkc_cf: NFKC_Casefold //0041..E0FFF N=10429
    
    .comp_ex : Full_Composition_Exclusion 0340..2FA1D N=1120
    
    .nfd_qc     : NFD_Quick_Check 00C0..2FA1D N=13233 (screwed)

.loe        : Logical_Order_Exception

037A
ENUMERATED 

CATALOG 
.age
<DerivedAge.txt>
    V1_1  : 1.1     // 000000..00ffff N=33979   1993-06
    V2_0  : 2.0     // 000591..10ffff N=144521  1996-07
    V2_1  : 2.1     // 0020AC..00FFFC N=2       1998-05
    V3_0  : 3.0     // 0001F6..00FFFB N=10307   1999-09
    V3_1  : 3.1     // 0003F4..0E007F N=44978   2001-03
    V3_2  : 3.2     // 000220..00FF60 N=1016    2002-03
    V4_0  : 4.0     // 000221..0E01EF N=1226    2003-04
    V4_1  : 4.1     // 000237..01D6A5 N=1273    2005-03
    V5_0  : 5.0     // 000242..01D7CB N=1369    2006-07
    V5_1  : 5.1     // 000370..01F093 N=1624    2008-03
    V5_2  : 5.2     // 000524..02B734 N=6648    2009-10
    V6_0  : 6.0     // 000526..02B81D N=2088    2010-10
    V6_1  : 6.1     // 00058F..01F634 N=732     2012-01
    V6_2  : 6.2     // 0020BA         N=1       2012-09
    V6_3  : 6.3     // 00061C..002069 N=5       2013-09
    V7_0  : 7.0     // 00037F..01F8AD N=2834    2014-06
    V8_0  : 8.0     // 0008B3..02CEA1 N=7716    2015-06
    V9_0  : 9.0     // 0008B6..01F991 N=7500    2016-06
    V10_0 : 10.0    // 000860..02EBE0 N=8518    2017-06
    V11_0 : 11.0    // 000560..01FA6D N=684     2018-06
    V12_0 : 12.0    // 000C77..01FA95 N=554     2019-03
    V12_1 : 12.1    // 0032FF         N=1       2019-05
    V13_0 : 13.0    // 0008BE..03134A N=5930    2020-03
    V14_0 : 14.0    // 00061D..02B738 N=838     2021-09


.vo : Vertical_Orientation
<VerticalOrientation.txt>
    R : Rotated // []
    Tr : Transformed_Rotated // []
    Tu : Transformed_Upright // []
    U : Upright // []


.nt : Numeric_Type
<extracted/DerivedNumericType.txt>
    De   :  Decimal // N=660    000030..01FBF9
    Di   :  Digit   // N=128    0000B2..01F10A
    Nu   :  Numeric // N=1084   0000BC..02F890
    None :  None    //


.hst : Hangul_Syllable_Type
<HangulSyllableType.txt>
    L   : Leading_Jamo      // N=125    001100..00A97C
    LV  : LV_Syllable       // N=10773  00AC01..00D7A3
    LVT : LVT_Syllable      // N=399    00AC00..00D788
    T   : Trailing_Jamo     // N=137    0011A8..00d7fb
    V   : Vowel_Jamo        // N=95     001160..00D7C6
    NA  : Not_Applicable    // N=...

.inpc : Indic_Positional_Category
<IndicPositionalCategory.txt>
    Bottom                  // 
    Bottom_And_Left         // 
    Bottom_And_Right        // 
    Left                    // 093F..11EF5
    Left_And_Right          // 
    NA                      // 
    Overstruck              // 
    Right                   // 0903..11EF6
    Top                     // 
    Top_And_Bottom          // 
    Top_And_Bottom_And_Left // 
    Top_And_Bottom_And_Right// 
    Top_And_Left            // 
    Top_And_Left_And_Right  // 
    Top_And_Right           // 
    Visual_Order_Left       // 

.insc : Indic_Syllabic_Category
<IndicSyllabicCategory.txt>
0903 ; Visarga # Mc DEVANAGARI SIGN VISARGA
"%x ; %{.insc} #"
    Avagraha // 
    Bindu // 
    Brahmi_Joining_Number // 
    Cantillation_Mark // 
    Consonant // 
    Consonant_Dead // 
    Consonant_Final // 
    Consonant_Head_Letter // 
    Consonant_Initial_Postfixed // 
    Consonant_Killer // 
    Consonant_Medial // 
    Consonant_Placeholder // 
    Consonant_Preceding_Repha // 
    Consonant_Prefixed // 
    Consonant_Subjoined // 
    Consonant_Succeeding_Repha // 
    Consonant_With_Stacker // 
    Gemination_Mark // 
    Invisible_Stacker // 
    Joiner // 
    Modifying_Letter // 
    Non_Joiner // 
    Nukta // 
    Number // 
    Number_Joiner // 
    Other // 
    Pure_Killer // 
    Register_Shifter // 
    Syllable_Modifier // 
    Tone_Letter // 
    Tone_Mark // 
    Virama // 
    Visarga // 
    Vowel // 
    Vowel_Dependent // 
    Vowel_Independent // 


.jg : Joining_Group
<ArabicShaping.txt>
<extracted/DerivedJoiningGroup.txt>
    African_Feh         // N=1      0008BB
    African_Noon        // N=1      0008BD
    African_Qaf         // N=2      0008BC..0008C4
    Ain                 // N=9      000639..0008C3
    Alaph               // N=1      000710
    Alef                // N=29     000622..000822
    Beh                 // N=27     000628..0008c0
    Beth                // N=2      000712..00072d
    Burushaski_Yeh_Barree // N=2    00077A..00077B
    Dal                 // N=15     00062F..0008ae
    Dalath_Rish         // N=4      000715..00072f
    E                   // N=1      000725
    Farsi_Yeh           // N=7      00063D..000776
    Fe                  // N=1      00074F
    Feh                 // N=10     000641..0008a4
    Final_Semkath       // N=1      000724
    Gaf                 // N=17     00063B..0008c8
    Gamal               // N=3      000713..00072e
    Hah                 // N=22     00062C..0008C6
    Hanifi_Rohingya_Kinna_Ya // N=4 010D19..010D23
    Hanifi_Rohingya_Pa  // N=3      010D02..010D1C
    He                  // N=1      000717
    Heh                 // N=1      000647
    Heh_Goal            // N=2      0006C1..0006C2
    Heth                // N=1      00071A
    Kaf                 // N=6      000643..0008B4
    Kaph                // N=1      00071F
    Khaph               // N=1      00074E
    Knotted_Heh         // N=2      0006BE..0006FF
    Lam                 // N=8      000644..0008C7
    Lamadh              // N=1      000720
    Malayalam_Bha       // N=1      000866
    Malayalam_Ja        // N=1      000861
    Malayalam_Lla       // N=1      000868
    Malayalam_Llla      // N=1      000869
    Malayalam_Nga       // N=1      000860
    Malayalam_Nna       // N=1      000864
    Malayalam_Nnna      // N=1      000865
    Malayalam_Nya       // N=1      000862
    Malayalam_Ra        // N=1      000867
    Malayalam_Ssa       // N=1      00086A
    Malayalam_Tta       // N=1      000863
    Manichaean_Aleph    // N=1      010AC0
    Manichaean_Ayin     // N=2      010AD9..010ADA
    Manichaean_Beth     // N=2      010AC1..010AC2
    Manichaean_Daleth   // N=1      010ac5
    Manichaean_Dhamedh  // N=1      010ad4
    Manichaean_Five     // N=1      010aec
    Manichaean_Gimel    // N=2      010ac3..010ac4
    Manichaean_Heth     // N=1      010acd
    Manichaean_Hundred  // N=1      010aef
    Manichaean_Kaph     // N=3      010ad0..010ad2
    Manichaean_Lamedh   // N=1      010ad3
    Manichaean_Mem      // N=1      010ad6
    Manichaean_Nun      // N=1      010ad7
    Manichaean_One      // N=1      010aeb
    Manichaean_Pe       // N=2      010adb..010adc
    Manichaean_Qoph     // N=3      010ADE..010AE0
    Manichaean_Resh     // N=1      010AE1
    Manichaean_Sadhe    // N=1      010ADD
    Manichaean_Samekh   // N=1      010AD8
    Manichaean_Taw      // N=1      010AE4
    Manichaean_Ten      // N=1      010AED
    Manichaean_Teth     // N=1      010ACE
    Manichaean_Thamedh  // N=1      010AD5
    Manichaean_Twenty   // N=1      010AEE
    Manichaean_Waw      // N=1      010AC7
    Manichaean_Yodh     // N=1      010ACF
    Manichaean_Zayin    // N=1      010AC9..010ACA
    Meem                // N=4      000645..0008A7
    Mim                 // N=1      000721
    Noon                // N=9      000646..000889
    Nun                 // N=1      000722
    Nya                 // N=1      0006BD
    Pe                  // N=1      000726
    Qaf                 // N=6      000642..0008B5
    Qaph                // N=1      000729
    Reh                 // N=19     000631..0008B9
    Reversed_Pe         // N=1      000727
    Rohingya_Yeh        // N=1      0008AC
    Sad                 // N=6      000635..0008AF
    Sadhe               // N=1      000728
    Seen                // N=11     000633..00077E
    Semkath             // N=1      000723
    Shin                // N=1      00072B
    Straight_Waw        // N=1      0008B1
    Swash_Kaf           // N=1      0006AA
    Syriac_Waw          // N=1      000718
    Tah                 // N=6      000637..0008A3
    Taw                 // N=1      00072C
    Teh_Marbuta         // N=3      000629..0006D5
    Teh_Marbuta_Goal    // N=1      0006C3
    Teth                // N=2      00071B..00071C
    Thin_Yeh            // N=1      000886
    Vertical_Tail       // N=1      00088E
    Waw                 // N=16     000624..0008AB
    Yeh                 // N=11     000620..0008BA
    Yeh_Barree          // N=2      0006D2..0006D3
    Yeh_With_Tail       // N=1      0006CD
    Yudh                // N=1      00071D
    Yudh_He             // N=1      00071E
    Zain                // N=1      000719
    Zhain               // N=1      00074D
    No_Joining_Group    // 

.jt : Joining_Type
<extracted/DerivedJoiningType.txt>
    C : Join_Causing    // N=7      [\u0640..\u200D]
    D : Dual_Joining    // N=610    [\U00000620..\U0001e943]
    L : Left_Joining    // N=5      [\U0000a872..\U00010fcb]
    R : Right_Joining   // N=152    [\U00000622..\U00010fc9]
    T : Transparent     // N=2108   [\U000000ad..\U000e01ef]
    U : Non_Joining     // N=...



.jsn : Jamo_Short_Name
    JSN; A ; A 
    JSN; AE ; AE 
    JSN; B ; B 
    JSN; BB ; BB 
    JSN; BS ; BS 
    JSN; C ; C 
    JSN; D ; D 
    JSN; DD ; DD 
    JSN; E ; E 
    JSN; EO ; EO 
    JSN; EU ; EU 
    JSN; G ; G 
    JSN; GG ; GG 
    JSN; GS ; GS 
    JSN; H ; H 
    JSN; I ; I 
    JSN; J ; J 
    JSN; JJ ; JJ 
    JSN; K ; K 
    JSN; L ; L 
    JSN; LB ; LB 
    JSN; LG ; LG 
    JSN; LH ; LH 
    JSN; LM ; LM 
    JSN; LP ; LP 
    JSN; LS ; LS 
    JSN; LT ; LT 
    JSN; M ; M 
    JSN; N ; N 
    JSN; NG ; NG 
    JSN; NH ; NH 
    JSN; NJ ; NJ 
    JSN; O ; O 
    JSN; OE ; OE 
    JSN; P ; P 
    JSN; R ; R 
    JSN; S ; S 
    JSN; SS ; SS 
    JSN; T ; T 
    JSN; U ; U 
    JSN; WA ; WA 
    JSN; WAE ; WAE 
    JSN; WE ; WE 
    JSN; WEO ; WEO 
    JSN; WI ; WI 
    JSN; YA ; YA 
    JSN; YAE ; YAE 
    JSN; YE ; YE 
    JSN; YEO ; YEO 
    JSN; YI ; YI 
    JSN; YO ; YO
    JSN; YU ; YU

# Line_Break (lb)
<LineBreak.txt>
<extracted/DerivedLineBreak.txt>

Not Tailorable
    BK : Mandatory_Break    // N=4      00000b..002029  (\v\f)
    CM : Combining_Mark     // N=2399   000000..0E01EF  
    CR : Carriage_Return    // N=1      00000d          (\r)
    LF : Line_Feed          // N=1      00000a          (\n)
    GL : Glue               // N=26     0000a0..016FE4  
    NL : Next_Line          // N=1      000085
    SP : Space              // N=1      000020          ( )
    WJ : Word_Joiner        // N=2      002026..00feff
    ZW : ZWSpace            // N=1      00200b
    ZWJ: ZWJ                // N=1      00200d

Tailorable:
    CJ : Conditional_Japanese_Starter // N=58 003041..01b167
    AI : Ambiguous          // N=707    01F170..01F1AC  (§)
    AL : Alphabetic         // N=22043  01FB94..01FBCA  (#)
    B2 : Break_Both         // N=3      002014..002E3B  (\u2E3A)
    BA : Break_After        // N=247    000009..01DA8A  (\t)
    BB : Break_Before       // N=45     0000b4..011C70  (´)
    CB : Contingent_Break   // N=1      00fffc          (￼)
    CL : Close_Punctuation  // N=95     000028..0145CF
    CP : Close_Parenthesis  // N=2      000029..00005d
    EB : E_Base             // N=132    00261d..01faf6
    EM : E_Modifier         // N=5      01f3fb..01f3ff
    EX : Exclamation        // N=40     000021..011c71  (!)
    H2 : H2                 // N=399    00AC00..00D788
    H3 : H3                 // N=10773  00AC01..00D7A3
    HL : Hebrew_Letter      // N=75     0005D0..00FB4F
    HY : Hyphen             // N=1      00002d          (-)
    ID : Ideographic        // N=172456 00231A..03FFFD
    IN : Inseparable        // N=6      002024..010AF6
    IS : Infix_Numeric      // N=13     00002c..00fe14  (,)
    JL : JL                 // N=125    001100..00a97c
    JT : JT                 // N=137    0011a8..00d7fb
    JV : JV                 // N=95     001160..00d7c6
    NS : Nonstarter         // N=33     0017D6..01f67b
    NU : Numeric            // N=652    000030..01fbf9  (0)
    OP : Open_Punctuation   // N=92     000028..01e95f
    PO : Postfix_Numeric    // N=37     000025..01ecac  (%)
    PR : Prefix_Numeric     // N=67     000024..01e2ff  ($)
    QU : Quotation          // N=39     000022..01f678  (")
    RI : Regional_Indicator // N=26     01f1e6..01f1ff
    SA : Complex_Context    // N=757    000E01..011746
    SG : Surrogate          // N=2400   00D800..00DFFF
    SY : Break_Symbols      // N=1      00002f          (/)
    XX : Unknown // N []


.nfc_qc : NFC_Quick_Check
    M : Maybe
    N : No
    Y : Yes 
.nfkc_qc : NFKC_Quick_Check
    M : Maybe
    N : No
    Y : Yes 

.wb : Word_Break
<Word_Break.txt>

    DQ:  Double_Quote       // N=1      ["]
    SQ:  Single_Quote       // N=1      [']
    CR                      // N=1      [\r]
    EB:  E_Base             // N=0
    EBG: E_Base_GAZ         // N=0
    EM:  E_Modifier         // N=0 
    EX:  ExtendNumLet       // N=11     [_\u203f\u2040]...
    Extend                  // N=2512   [\u0300..\u036F]
    FO:  Format             // N=64     [\xad\U0001D173..\U0001D17A\U000E0001]..
    GAZ: Glue_After_Zwj     // N=0
    HL:  Hebrew_Letter      // N=0
    LF                      // N=1      [\n]
    NL:  Newline            // N=5      [\v\f\x85\u2028\u2029]
    RI:  Regional_Indicator // N=26     [\U0001F1E6..\U0001F1FF]
    KA:  Katakana           // N=330    [\u3031..\u3035]..
    LE:  ALetter            // N=29336  [A..Za..zªµºÀ..Öà..öø..]..
    ML:  MidLetter          // N=9      [:·]...
    MN:  MidNum             // N=15     [,;;]...
    MB:  MidNumLet          // N=7      [.'\u2018\u2019\u2024\uff07\uff0e]
    NU:  Numeric            // N=661    [0..9]...
    ZWJ                     // N=1      [\u200d] 
    WSegSpace               // N=14     [ \u2000..\u2006]...
    XX:  Other              // N=...

.gcb : Grapheme_Cluster_Break
<GraphemeBreakProperty.txt>

    CN:  Control            // N=3886   [\u0000..\u0009]
    CR                      // N=1      [\r]
    EB:  E_Base             // N=0
    EBG: E_Base_GAZ         // N=0
    EM:  E_Modifier         // N=0 
    EX:  Extend             // N=2095   [\u0300..\u036F\U000E0100..\U000E01EF]
    GAZ: Glue_After_Zwj     // N=0
    L                       // N=125    [\u1100..\u115F\uA960..\uA97C]
    LF                      // N=1      [\n]
    LV                      // N=399    [\uac00\ud788]..
    LVT                     // N=10773  [\uAC01..\uAC1B\uD789..\uD7A3]
    PP:  Prepend            // N=26     [\u0600..\u0605]
    RI:  Regional_Indicator // N=26     [\U0001F1E6..\U0001F1FF]
    SM:  SpacingMark        // N=388    [\u0903\U0001D16D]..
    T                       // N=137    [\u11A8..\u11FF\uD7CB..\uD7FB]
    V                       // N=95     [\u1160..\u11A7\uD7B0..\uD7C6]
    XX:  Other              // N=...
    ZWJ                     // N=1      [\u200d] 

.sc
<Scripts.txt>
    Adlm : Adlam
    Aghb : Caucasian_Albanian
    Ahom : Ahom
    Arab : Arabic
    Armi : Imperial_Aramaic
    Armn : Armenian
    Avst : Avestan
    Bali : Balinese
    Bamu : Bamum
    Bass : Bassa_Vah
    Batk : Batak
    Beng : Bengali
    Bhks : Bhaiksuki
    Bopo : Bopomofo
    Brah : Brahmi
    Brai : Braille
    Bugi : Buginese
    Buhd : Buhid
    Cakm : Chakma
    Cans : Canadian_Aboriginal
    Cari : Carian
    Cham : Cham
    Cher : Cherokee
    Chrs : Chorasmian
    Copt : Coptic                           ; Qaac
    Cprt : Cypriot
    Cyrl : Cyrillic
    Deva : Devanagari
    Diak : Dives_Akuru
    Dogr : Dogra
    Dsrt : Deseret
    Dupl : Duployan
    Egyp : Egyptian_Hieroglyphs
    Elba : Elbasan
    Elym : Elymaic
    Ethi : Ethiopic
    Geor : Georgian
    Glag : Glagolitic
    Gong : Gunjala_Gondi
    Gonm : Masaram_Gondi
    Goth : Gothic
    Gran : Grantha
    Grek : Greek
    Gujr : Gujarati
    Guru : Gurmukhi
    Hang : Hangul
    Hani : Han
    Hano : Hanunoo
    Hatr : Hatran
    Hebr : Hebrew
    Hira : Hiragana
    Hluw : Anatolian_Hieroglyphs
    Hmng : Pahawh_Hmong
    Hmnp : Nyiakeng_Puachue_Hmong
    Hrkt : Katakana_Or_Hiragana
    Hung : Old_Hungarian
    Ital : Old_Italic
    Java : Javanese
    Kali : Kayah_Li
    Kana : Katakana
    Khar : Kharoshthi
    Khmr : Khmer
    Khoj : Khojki
    Kits : Khitan_Small_Script
    Knda : Kannada
    Kthi : Kaithi
    Lana : Tai_Tham
    Laoo : Lao
    Latn : Latin
    Lepc : Lepcha
    Limb : Limbu
    Lina : Linear_A
    Linb : Linear_B
    Lisu : Lisu
    Lyci : Lycian
    Lydi : Lydian
    Mahj : Mahajani
    Maka : Makasar
    Mand : Mandaic
    Mani : Manichaean
    Marc : Marchen
    Medf : Medefaidrin
    Mend : Mende_Kikakui
    Merc : Meroitic_Cursive
    Mero : Meroitic_Hieroglyphs
    Mlym : Malayalam
    Modi : Modi
    Mong : Mongolian
    Mroo : Mro
    Mtei : Meetei_Mayek
    Mult : Multani
    Mymr : Myanmar
    Nand : Nandinagari
    Narb : Old_North_Arabian
    Nbat : Nabataean
    Newa : Newa
    Nkoo : Nko
    Nshu : Nushu
    Ogam : Ogham
    Olck : Ol_Chiki
    Orkh : Old_Turkic
    Orya : Oriya
    Osge : Osage
    Osma : Osmanya
    Palm : Palmyrene
    Pauc : Pau_Cin_Hau
    Perm : Old_Permic
    Phag : Phags_Pa
    Phli : Inscriptional_Pahlavi
    Phlp : Psalter_Pahlavi
    Phnx : Phoenician
    Plrd : Miao
    Prti : Inscriptional_Parthian
    Rjng : Rejang
    Rohg : Hanifi_Rohingya
    Runr : Runic
    Samr : Samaritan
    Sarb : Old_South_Arabian
    Saur : Saurashtra
    Sgnw : SignWriting
    Shaw : Shavian
    Shrd : Sharada
    Sidd : Siddham
    Sind : Khudawadi
    Sinh : Sinhala
    Sogd : Sogdian
    Sogo : Old_Sogdian
    Sora : Sora_Sompeng
    Soyo : Soyombo
    Sund : Sundanese
    Sylo : Syloti_Nagri
    Syrc : Syriac
    Tagb : Tagbanwa
    Takr : Takri
    Tale : Tai_Le
    Talu : New_Tai_Lue
    Taml : Tamil
    Tang : Tangut
    Tavt : Tai_Viet
    Telu : Telugu
    Tfng : Tifinagh
    Tglg : Tagalog
    Thaa : Thaana
    Thai : Thai
    Tibt : Tibetan
    Tirh : Tirhuta
    Ugar : Ugaritic
    Vaii : Vai
    Wara : Warang_Citi
    Wcho : Wancho
    Xpeo : Old_Persian
    Xsux : Cuneiform
    Yezi : Yezidi
    Yiii : Yi
    Zanb : Zanabazar_Square
    Zinh : Inherited                        ; Qaai
    Zyyy : Common
    Zzzz : Unknown


.sb : Sentence_Break
<SentenceBreakProperty.txt>
    AT: ATerm       // N=4      [.\u2024\ufe52\uff0e]
    CL: Close       // N=195    ["'()[]{}«»\U0001F676..\U0001F678]..
    CR              // N=1      [\r]
    EX: Extend      // N=2508   [\u0300..\u036\U000E0100..\U000E01EF]..
    FO: Format      // N=65     [\xad\U000E0001]
    LE: OLetter     // N=127761 [\u01B\U000B30000..\U0003134A]..
    LF              // N=1      [\n]
    LO: Lower       // N=2424   [a..z\U0001E922..\U0001E943]..
    NU: Numeric     // N=662    [0..9\U0001FBF0..\U0001FBF9]..
    SC: SContinue   // N=26     [,-:\uFF64]
    SE: Sep         // N=3      [\x85\u2028\u2029]
    SP: Sp          // N=20     [\t\u3000]
    ST: STerm       // N=149    [!?\U0001DA88] 
    UP: Upper       // N=1936   [A..Z\U0001F170..\U0001F189]..
    XX: Other       // N=...
    

.eaw : East_Asian_Width
<extracted/DerivedEastAsianWidth.txt>
    A  : Ambiguous  // N=138739     0000A1..10fffd
    F  : Fullwidth  // N=104        003000..00FFE6
    H  : Halfwidth  // N=123        0020A9..00FFEE
    Na : Narrow     // N=111        000020..002986
    W  : Wide       // N=182390     001100..03FFFD
    N  : Neutral    // N=792645     000000..0E007F

.bc : Bidi_Class
<DerivedBidiClass.txt>
    AL  :  Arabic_Letter             // N=1088 
    AN  :  Arabic_Number             // N=63
    B   :  Paragraph_Separator       // N=7 
    BN  :  Boundary_Neutral          // N=4016
    CS  :  Common_Separator          // N=15
    EN  :  European_Number           // N=168       000590..01FBF9
    ES  :  European_Separator        // N=12        00002B..00FF0D
    ET  :  European_Terminator       // N=92        
    NSM :  Nonspacing_Mark           // N=1958      
    ON  :  Other_Neutral             // N=6000      
    S   :  Segment_Separator         // N=3         
    WS  :  White_Space               // N=17
    L   :  Left_To_Right             // N=1096333   000041..10FFFD
    LRE :  Left_To_Right_Embedding   // N=1         00202a
    LRI :  Left_To_Right_Isolate     // N=1         002066
    LRO :  Left_To_Right_Override    // N=1         00202d
    R   :  Right_To_Left             // N=3711      
    RLE :  Right_To_Left_Embedding   // N=1         00202b
    RLI :  Right_To_Left_Isolate     // N=1         002067
    RLO :  Right_To_Left_Override    // N=1         00202e
    PDF :  Pop_Directional_Format    // N=1         00202c
    PDI :  Pop_Directional_Isolate   // N=1         002069
    FSI :  First_Strong_Isolate      // N=1         002068

.bpt : Bidi_Paired_Bracket_Type
    c:  Closed 
    o:  Open 
    n:  None 

.ccc : Canonical_Combining_Class
    NR   : Not_Reordered        = 0,    // N=1113200 000000..10ffff
    OV   : Overlay              = 1,    // N=32     000334..01d169
    HANR : Han_Reading          = 6,    // N=2      016FF0..016FF1
    NK   : Nukta                = 7,    // N=27     00093C..01E94A
    KV   : Kana_Voicing         = 8,    // N=2      003099..00309A
    VR   : Virama               = 9,    // N=63     00094D..011D97
    CCC10                       = 10,   // N=1      0005B0
    CCC11                       = 11,   // N=1      0005B1
    CCC12                       = 12,   // N=1      0005B2 
    CCC13                       = 13,   // N=1      0005B3
    CCC14                       = 14,   // N=1      0005B4
    CCC15                       = 15,   // N=1      0005B5
    CCC16                       = 16,   // N=1      0005B6
    CCC17                       = 17,   // N=1      0005B7
    CCC18                       = 18,   // N=2      0005B8..0005C7
    CCC19                       = 19,   // N=2      0005B9..0005BA
    CCC20                       = 20,   // N=1      0005BB
    CCC21                       = 21,   // N=1      0005BC
    CCC22                       = 22,   // N=1      0005BD
    CCC23                       = 23,   // N=1      0005BF
    CCC24                       = 24,   // N=1      0005C1
    CCC25                       = 25,   // N=1      0005C2
    CCC26                       = 26,   // N=1      00FB1E
    CCC27                       = 27,   // N=2      00064B..0008F0
    CCC28                       = 28,   // N=2      00064C..0008F1
    CCC29                       = 29,   // N=2      00064D..0008F2
    CCC30                       = 30,   // N=2      000618..00064E
    CCC31                       = 31,   // N=2      000619..00064F
    CCC32                       = 32,   // N=2      00061A..000650
    CCC33                       = 33,   // N=1      000651
    CCC34                       = 34,   // N=1      000652
    CCC35                       = 35,   // N=1      000670
    CCC36                       = 36,   // N=1      000711
    CCC84                       = 84,   // N=1      000C55
    CCC91                       = 91,   // N=1      000C56
    CCC103                      = 103,  // N=2      000E38..000E39
    CCC107                      = 107,  // N=4      000E48..000E4B
    CCC118                      = 118,  // N=2      000EB8..000EB9
    CCC122                      = 122,  // N=4      000EC8..000ECB
    CCC129                      = 129,  // N=1      000F71
    CCC130                      = 130,  // N=6      000F72..000F80
    CCC132                      = 132,  // N=1      000F74
    CCC133                      = 133,  // N=0
    ATBL : Attached_Below_Left  = 200,  // N=0
    ATB  : Attached_Below       = 202,  // N=5      000321..001DD0
    ATA  : Attached_Above       = 214,  // N=1      001DCE
    ATAR : Attached_Above_Right = 216,  // N=9      00031B..01D172
    BL   : Below_Left           = 218,  // N=2      001DFA..00302A
    B    : Below                = 220,  // N=177    000316..01e8d6
    BR   : Below_Right          = 222,  // N=4      00059A..00302D
    L    : Left                 = 224,  // N=2      00302E..00302F
    R    : Right                = 226,  // N=1      01D16D
    AL   : Above_Left           = 228,  // N=5      0005AE..00302b
    A    : Above                = 230,  // N=508    000300..01E949
    AR   : Above_Right          = 232,  // N=5      000315..00302C
    DB   : Double_Below         = 233,  // N=4      00035C..001DFC
    DA   : Double_Above         = 234,  // N=5      00035D..001DCD
    IS   : Iota_Subscript       = 240,  // N=1      000345


.dt : Decomposition_Type
<extracted/DerivedDecompositionType.txt>
    Can  : Canonical // 0000C0..02FA1D N=13233
    Com  : Compat    // 0000A8..01F248 N=720
    Enc  : Circle    // 002460..01F251 N=240
    Fin  : Final     // 00FB51..00FEFC N=240
    Font : Font      // 002102..01FBF9 N=1194
    Fra  : Fraction  // 0000BC..002189 N=20
    Init : Initial   // 00FB54..00FEF3 N=171
    Iso  : Isolated  // 00FB50..00FEFB N=238
    Med  : Medial    // 00FB55..00FEF4 N=82
    Nar  : Narrow    // 00FF61..00FFEE N=122
    Nb   : Nobreak   // 0000A0..00202F N=5
    Sml  : Small     // 00FE50..00FE6B N=26
    Sqr  : Square    // 003250..01F23B N=286
    Sub  : Sub       // 001D62..002C7C N=38
    Sup  : Super     // 0000AA..01F16C N=213   
    Vert : Vertical  // 00309F..00FE48 N=35
    Wide : Wide      // 003000..00FFE6 N=104   
    None : None      //                N=1097144

0378..
    7   6   5   4   3   2   1   0
    0   0   0   0   0   0   0   0
    
    # Cc | Cf | Cn | Co | Cs
    #              | Lm | Lo 
    # Ll | Lt | Lu |
    # Mc | Me | Mn
    # Nd | Nl | No
    # Pc | Pd | Pe | Pf | Pi | Po | Ps
    # Sc | Sk | Sm | So
    # Zl | Zp | Zs

#   define UCD_GC_C 0x00
#   define UCD_GC_Z 0x10
#   define UCD_GC_M 0x20
#   define UCD_GC_S 0x30
#   define UCD_GC_P 0x40
#   define UCD_GC_N 0x50
#   define UCD_GC_L 0x60

    Cn : unassigned             // 000378..10FFFF N=829834
    Cc : Control                // 000000..00009f N=65
    Cf : Format                 // 0000AD..0E007F N=163
    Co : Private_Use            // 00E000..10FFFD N=137468
    Cs : Surrogate              // 00D800..00DFFF N=2048

    Ll : Lowercase_Letter       // 000061..01E943 N=2227
    Lm : Modifier_Letter        // 0002B0..01E94B N=334
    Lo : Other_Letter           // 0000AA..03134A N=127333
    Lt : Titlecase_Letter       // 0001C5..001FFC N=31
    Lu : Uppercase_Letter       // 000041..01E921 N=1831
    
    Mc : Spacing_Mark           // 000903..01D172 N=445
    Me : Enclosing_Mark         // 000488..00A672 N=13
    Mn : Nonspacing_Mark        // 000300..0E01EF N=1950

    Nd : Decimal_Number         // 000030..01FBF9 N=660
    Nl : Letter_Number          // 0016EE..01246E N=236
    No : Other_Number           // 0000B2..01F10C N=895

    Pc : Connector_Punctuation  // 00005F..00FF3F N=10
    Pd : Dash_Punctuation       // 00002D..010EAD N=26
    Pe : Close_Punctuation      // 000029..00FF63 N=77
    Pf : Final_Punctuation      // 0000BB..002E21 N=10
    Pi : Initial_Punctuation    // 0000AB..002E20 N=12
    Po : Other_Punctuation      // 000021..01E95F N=605
    Ps : Open_Punctuation       // 000028..00FF62 N=79

    Sc : Currency_Symbol        // 000024..01ECB0 N=63
    Sk : Modifier_Symbol        // 00005E..01F3FF N=125
    Sm : Math_Symbol            // 00002B..01EEF1 N=948
    So : Other_Symbol           // 0000A6..01FBCA N=6605

    Zl : Line_Separator         // 002028         N=1
    Zp : Paragraph_Separator    // 002029         N=1
    Zs : Space_Separator        // 000020..003000 N=17
    
g: (graphic)
    l: (letter)
        g:l:m      (modifier)
        g:l:o      (other)
        g:l:l:c   (lowercase)
        g:l:u:c   (uppercase)
        g:l:t:c   (titlecase)
    m: (mark)
        g:m:n      (nonspacing)
        g:m:c      (combining)
        g:m:e      (enclosing)
    n:
        g:n:d   (decimal)
        g:n:l   (letter)
        
N [n] Number
Nd[n] Decimal Digit
Nl[n] Letter 
No[n] Other

Z [n] Separator
Zs[n] Space
Zl[n] Line
Zp[n] Paragraph

C [n] Other
Cc[n] Control
Cf[n] Format
Cs[n] Surrogate
Co[n] Private Use
Cn[n] Unassigned

P [i] Punctuation
Pc[i] Connector
Pd[i] Dash
Ps[i] Open 
Pe[i] Close
Pi[i] Initial quote 
Pf[i] Final quote
Po[i] Other

S [i] Symbol
Sm[i] Math
Sc[i] Currency
Sk[i] Modifier
So[i] Other

*/

#define UCD_GC_PM 0xE0 /* 0b'1110'0000 */
#define UCD_GC_PS 5  

typedef enum {
/*  gc=L (Letter) 
    Ll (lowercase)
    Lu (uppercase)
    Lt (titlecase)
    Lo (other)
    Lm (mark)
*/
    GC_L = 0,
#   define GC_L_M (GC_L<<UCD_GC_PS)

/*  gc=M; (Mark)
    
*/
    GC_M = 1,
#   define GC_N_M (GC_N<<UCD_GC_PS)

    GC_N = 2,
#   define GC_M_M (GC_M<<UCD_GC_PS)
    GC_P = 3,
#   define GC_P_M (GC_P<<UCD_GC_PS)
    GC_S = 4,
#   define GC_S_M (GC_S<<UCD_GC_PS)
    GC_Z = 5,
#   define GC_Z_M (GC_Z<<UCD_GC_PS)
    GC_C = 6,
#   define GC_C_M (GC_C<<UCD_GC_PS)

} UCD_GC_B;

int main(void) {
    errno = 0;
    ptrdiff_t pos = 0;
    char strs[] =
        "\xf0\x9f\x93\x80"  /* dvd */
        "\xef\xac\x83"  ;   /* LATIN SMALL LIGATURE FFI */
    char dvd_str[5] = {0};
    char ffi_str[4] = {0};
    ptrdiff_t dvd_len = UTF_8_ENCODE(U'💽', dvd_str);
    ptrdiff_t ffi_len = UTF_8_ENCODE(U'ﬃ', ffi_str);
    ptrdiff_t dvd_rln = UTF_8_REPR(strs, stdout);
    printf("\n");
    
    printf(
        "dvd_str = %s\n"
        "ffi_str = %s\n",
        dvd_str,
        ffi_str);
    printf(
        "dvd = \"%lc\"\n"
        "ffi = \"%lc\"\n",
        (wint_t) UTF_8_DECODE(strs, &pos),
        (wint_t) UTF_8_DECODE(strs, &pos));

}

/*
os.system("clang /sdcard/Pyth")
c11.clang("/sdcard/Python/unsys/ununicode.c", "untest", includes=["/sdcard/Python/unsys"], libraries=["m"])

*/
