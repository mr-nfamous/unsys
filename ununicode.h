
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

#pragma once

/*
There are 1,114,111 possible Unicode code points 
spread evenly across 17 planes, each composed of
65534 characters followed by 2 noncharacters.
Each plane is then divided into variably sized but
contiguous subregions beginning at one of the 4096
16 code point boundaries in each plane. 

As hinted at previously, each code point is either a
designated character or an undesignated noncharacter.
Designated characters comprise the bulk of the code 
space, with only 66 undesignated, 34 of which are 
the last two code points of each plane and another
32 near the end of the BMP at [u+fdd0..u+fdef].

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
    
*/

#define UNICODE_MAX 0x10FFFF

typedef struct {
    char *chr;
    char *end;
}   unhexstr_t;


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
    "\\0",      "\\x01",    "\\x02",    "\\x03",
    "\\x04",    "\\x05",    "\\x06",    "\\a",
    "\\b",      "\\t",      "\\n",      "\\v",
    "\\f",      "\\r",      "\\x0f",    "\\x0f",
    "\\x10",    "\\x11",    "\\x12",    "\\x13",
    "\\x14",    "\\x15",    "\\x16",    "\\x17",
    "\\x18",    "\\x19",    "\\x1a",    "\\x1b",
    "\\x1c",    "\\x1d",    "\\x1e",    "\\x1f",
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


static const char 
    *UNICODE_ESCAPE_UTF_32_FMT[] = {
        ""  "\134U%08X"  "",  
        "\047\134U%08X\047", 
        "\042\134U%08X\042",    0,
},
    *UNICODE_ESCAPE_UTF_16_FMT[] = {
        ""  "\134u%04X"  "",  
        "\047\134u%04X\047", 
        "\042\134u%04X\042",    0,
},
    *UNICODE_ESCAPE_ASCII_FMT[] = {
        ""  "\134x%02X"  "",
        "\047\134x%02X\047",
        "\042\134x%02X\042", 0,
},
    DIGIT_VALUE[256] = {
        ['0']= 0,1, 2, 3, 4, 5, 6, 7, 8, 9,
        //     0  1  2  3  4  5  6  7  8  9
        ['A']=10,11,12,13,14,15,16,17,18,19,20,21,22,
        //     A  B  C  D  E  F  G  H  I  J  K  L  M 
        ['N']=23,24,25,26,27,28,29,30,31,32,33,34,35,
        //     N  O  P  Q  R  S  T  U  V  W  X  Y  Z 
        ['a']=10,11,12,13,14,15,16,17,18,19,20,21,22,
        //     a  b  c  d  e  f  g  h  i  j  k  l  m
        ['n']=23,24,25,26,27,28,29,30,31,32,33,34,35,
        //     n  o  p  q  r  s  t  u  v  w  x  y  z 
};

static const unsigned char UTF_8_SEQ[] = {
/*  The first byte of a UTF-8 encoded code point 
    [0] = illegal sequence [0x80..0xc1] && [0xf5..0xff]
    [1] = 1 byte/ASCII
    [2] = 2 byte sequence (code points [0x80..0x7FF])
    [3] = 3 byte sequence (code points [0x800..0xFFFF])
    [4] = 4 byte sequence ([0x10000..0x10FFFF])
*/
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,
};

static const unsigned char UTF_8_CBI[256] = {
/*  For continuation byte b:
        if (UTF_8_CBI[b] != 0xfe) then it's valid 
        otherwise, it ain't 
*/
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    [0x80]=0x00, [0x81]=0x01, [0x82]=0x02, [0x83]=0x03,
    [0x84]=0x04, [0x85]=0x05, [0x86]=0x06, [0x87]=0x07,
    [0x88]=0x08, [0x89]=0x09, [0x8a]=0x0a, [0x8b]=0x0b,
    [0x8c]=0x0c, [0x8d]=0x0d, [0x8e]=0x0e, [0x8f]=0x0f,
    [0x90]=0x10, [0x91]=0x11, [0x92]=0x12, [0x93]=0x13,
    [0x94]=0x14, [0x95]=0x15, [0x96]=0x16, [0x97]=0x17,
    [0x98]=0x18, [0x99]=0x19, [0x9a]=0x1a, [0x9b]=0x1b,
    [0x9c]=0x1c, [0x9d]=0x1d, [0x9e]=0x1e, [0x9f]=0x1f,
    [0xa0]=0x20, [0xa1]=0x21, [0xa2]=0x22, [0xa3]=0x23,
    [0xa4]=0x24, [0xa5]=0x25, [0xa6]=0x26, [0xa7]=0x27,
    [0xa8]=0x28, [0xa9]=0x29, [0xaa]=0x2a, [0xab]=0x2b,
    [0xac]=0x2c, [0xad]=0x2d, [0xae]=0x2e, [0xaf]=0x2f,
    [0xb0]=0x30, [0xb1]=0x31, [0xb2]=0x32, [0xb3]=0x33,
    [0xb4]=0x34, [0xb5]=0x35, [0xb6]=0x36, [0xb7]=0x37,
    [0xb8]=0x38, [0xb9]=0x39, [0xba]=0x3a, [0xbb]=0x3b,
    [0xbc]=0x3c, [0xbd]=0x3d, [0xbe]=0x3e, [0xbf]=0x3f,    
/*
    0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
    0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
    0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,
    0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,
    0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,
    0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,
    0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,
    0x38,0x39,0x3a,0x3b,0x3c,0x3d,0x3e,0x3f,
*/ 
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
};

static const unsigned char UTF_8_ECB[64] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,
    0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,
    0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,
    0x98,0x99,0x9a,0x9b,0x9c,0x9d,0x9e,0x9f,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,
    0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,
    0xb0,0xb1,0xb2,0xb3,0xb4,0xb5,0xb6,0xb7,
    0xb8,0xb9,0xba,0xbb,0xbc,0xbd,0xbe,0xbf,
};

static const unsigned char UTF_8_ES2[32] = {
/*  Encodes the start byte for [0x80..0x7ff]
*/  0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,
    0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,
    0xd0,0xd1,0xd2,0xd3,0xd4,0xd5,0xd6,0xd7,
    0xd8,0xd9,0xda,0xdb,0xdc,0xdd,0xde,0xdf,
};

static const unsigned char UTF_8_ES3[16] = {
/*  Encodes the start byte for [0x800..0xffff]
*/  0xe0,0xe1,0xe2,0xe3,0xe4,0xe5,0xe6,0xe7,
    0xe8,0xe9,0xea,0xeb,0xec,0xed,0xee,0xef,
};

static const unsigned char UTF_8_ES4[16] = {
/*  Encodes the start byte for [0x10000..0x10FFFF]
*/  0xf0,0xf1,0xf2,0xf3,0xf4,0xf5,0xf6,0xf7,
    0xf8,0xf9,0xfa,0xfb,0xfc,0xfd,0xfe,0xff,
};

static const char32_t 
UTF_8_MB1[256] = {
/*  Decode a UTF-8 encoded code point's start byte
    [U+000000..U+00007F][1] <— MB1 (not multibyte)
    [U+000080..U+0007FF][2] <— MB2
    [U+000800..U+00FFFF][3] <— MB3
    [U+010000..U+10FFFF][4] <— MB4
*/  000,001,002,003,004,005,006,007,010,011,012,013,014,015,016,017,
    020,021,022,023,024,025,026,027,030,031,032,033,034,035,036,037,
    ' ','!','"','#','$','%','&',047,'(',')','*','+',',','-','.','/',
    '0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?',
    '@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
    'P','Q','R','S','T','U','V','W','X','Y','Z','[',0x5c,']','^','_',
    '`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
    'p','q','r','s','t','u','v','w','x','y','z','{','|','}','~',127,
    000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
    000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
    000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
    000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
    [0xc0]=0x000000,[0xc1]=0x000000,[0xc2]=0x000080,[0xc3]=0x0000c0,
    [0xc4]=0x000100,[0xc5]=0x000140,[0xc6]=0x000180,[0xc7]=0x0001c0,
    [0xc8]=0x000200,[0xc9]=0x000240,[0xca]=0x000280,[0xcb]=0x0002c0,
    [0xcc]=0x000300,[0xcd]=0x000340,[0xce]=0x000380,[0xcf]=0x0003c0,
    [0xd0]=0x000400,[0xd1]=0x000440,[0xd2]=0x000480,[0xd3]=0x0004c0,
    [0xd4]=0x000500,[0xd5]=0x000540,[0xd6]=0x000580,[0xd7]=0x0005c0,
    [0xd8]=0x000600,[0xd9]=0x000640,[0xda]=0x000680,[0xdb]=0x0006c0,
    [0xdc]=0x000700,[0xdd]=0x000740,[0xde]=0x000780,[0xdf]=0x0007c0,
    [0xe0]=0x000000,[0xe1]=0x001000,[0xe2]=0x002000,[0xe3]=0x003000,
    [0xe4]=0x004000,[0xe5]=0x005000,[0xe6]=0x006000,[0xe7]=0x007000,
    [0xe8]=0x008000,[0xe9]=0x009000,[0xea]=0x00a000,[0xeb]=0x00b000,
    [0xec]=0x00c000,[0xed]=0x00d000,[0xee]=0x00e000,[0xef]=0x00f000,
    [0xf0]=0x000000,[0xf1]=0x040000,[0xf2]=0x080000,[0xf3]=0x0C0000,
    [0xf4]=0x100000,[0xf5]=0x000000,[0xf6]=0x000000,[0xf7]=0x000000,
    [0xff]=0x000000,
};

static const char32_t 
UTF_8_MB4[64] = {
/*  Decode s[1] of 4 byte sequence
*/  0x000000, 0x001000, 0x002000, 0x003000,
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
};

static const uint16_t 
UTF_8_MB3[64] = {
/*  Decodes s[2] of four byte sequence and s[1] of 
    three byte sequences
*/  0x0000, 0x0040, 0x0080, 0x00c0,
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
};

static const uint8_t 
UTF_8_MB2[64] = {
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
};

static inline int
FPUTC_UNICODE_ESCAPE(char32_t c, FILE *f, int q) {
    if ((q < 0) || (q > 2)) {
        return (errno=EINVAL), -1;
    }
    if (c > 0x10FFFF) {
        return (errno=EILSEQ), -1;
    }
    if (c > 0x00FFFF) {
        return fprintf(f, UNICODE_ESCAPE_UTF_32_FMT[q], c);
    }
    if (c > 0x0000FF) {
        return fprintf(f, UNICODE_ESCAPE_UTF_16_FMT[q], c);
    }
    else {
        return fprintf(f, UNICODE_ESCAPE_ASCII_FMT[q], c);
    }
}

static inline int 
PUTC_UNICODE_ESCAPE(char32_t c, int q) {
    return FPUTC_UNICODE_ESCAPE(c, stdout, q);
}

static inline int 
UTF_8_ENCODE(unmbs_t *restrict s) {
    if (s->eof) {
        return -1;
    }
    unsigned a = (unsigned) *s->dst++;
    unsigned b;
    unsigned c;
    if (a > 0x10FFFFU) {
        errno = EILSEQ;
        s->eof = 0;
        s->dst--;
        return (0-1);
    }
    if (a < 0x80U) {
        s->src[s->len++] = (unsigned char) a;
        if (!a) {
            return 0-(s->eof=1);
        }
    }
    else {
        b = a&0x3fu;
        a = a>>6;
        if (a < 0x20u) {
            s->src[s->len++] = UTF_8_ES2[a];
        }
        else {
            c = a&0x3FU;
            if (a > 0x3ffU) {
                s->src[s->len++] = UTF_8_ES4[(a>>12)];
                s->src[s->len++] = UTF_8_ECB[(a>>6)&0x3FU];
            }
            else {
                s->src[s->len++] = UTF_8_ES3[(a>>6)];
            }
            s->src[s->len++] = UTF_8_ECB[c];
        }
        s->src[s->len++] = UTF_8_ECB[b];
    }
    return 0;
}

static inline char32_t
UTF_8_DECODE(char **ptr) {
    char i;
    char *restrict src = *ptr;
    const char  y = UTF_8_SEQ[*src];
    char32_t  ord = UTF_8_MB1[*src++];
    switch (y) {
        case 4: {
            if ((i=UTF_8_CBI[*src++]) == 0xFEU) break;
            ord += UTF_8_MB4[i];
        }
        case 3: {
            if ((i=UTF_8_CBI[*src++]) == 0xFEU) break;
            ord += UTF_8_MB3[i];
        }
        case 2: {
            if ((i=UTF_8_CBI[*src++]) == 0xFEU) break;
            ord += UTF_8_MB2[i];
        }
        case 1: {
            *ptr = src;
            return ord;
        }
    }
    errno = EILSEQ;
    *ptr = NULL;
    return WEOF;
}

static inline char32_t
UTF_8_DECODE_2(const char src[restrict], size_t *restrict i) {
    char        c;
    const char  y = UTF_8_SEQ[src[*i]];
    char32_t    v = UTF_8_MB1[src[*i++]];
    switch (y) {
        case 4: {
            c = UTF_8_CBI[src[*i++]];
            if (c == 0xFEU) {
                break;
            }
            v = UTF_8_MB4[c];
        }
        case 3: {
            c = UTF_8_CBI[src[*i++]];
            if (c == 0xFEU) {
                break;
            }
            v += UTF_8_MB3[c];
        }
        case 2: {
            c = UTF_8_CBI[src[*i++]];
            if (c == 0xFEU) {
                break;
            }
            v += UTF_8_MB2[c];
        }
        case 5:
        case 1: {
            return v;
        }
    }
    errno = EILSEQ;
    return 0;
}

static const uint32_t
DIGIT_SEP[8] = {
    [0x1f/0x20]=0b00000000000000000000000000000000U,
    [0x3f/0x20]=0b00000000000000000000000010000000U, // 39%32=(1,7)
#if defined(UNSYS_UNDERSCORE_IS_DIGIT_SEP)
    [0x5f/0x20]=0b10000000000000000000000000000000U, // 95%32=(2,31)
#else
    [0x5f/0x20]=0b00000000000000000000000000000000U,
#endif
    [0x7f/0x20]=0b00000000000000000000000000000000U,
    [0x9f/0x20]=0b00000000000000000000000000000000U,
    [0xbf/0x20]=0b00000000000000000000000000000000U,
    [0xdf/0x20]=0b00000000000000000000000000000000U,
    [0xff/0x20]=0b00000000000000000000000000000000U,
};

static inline int 
HEX_DECODE(unhexstr_t *restrict hex, char *restrict dst) {
    if (hex->end) {
        return errno;
    }
    char x;
    the_lhs: {
        if (!ISXDIGIT(x=*hex->chr)) {
            if (ISSPACE(x)) {
                hex->chr++;
                goto the_lhs;
            }
            goto the_end;
        }
    }
    the_rhs: {
        if (!ISXDIGIT(*++hex->chr)) {
            if (DIGIT_SEP[*hex->chr/32]&(1U<<*hex->chr%32)) {
                goto the_rhs;
            }
            errno = EILSEQ;
            goto the_end;
        }
        *dst = (DIGIT_VALUE[x]<<4)|DIGIT_VALUE[*hex->chr++];
        return 0;
    }
    the_end: {
        hex->end = hex->chr;
        hex->chr = NULL;
    }
    return errno;
}
     
static inline char32_t
UTF_16_DECODE_NATIVE(const char16_t *restrict *src) {
    char32_t v = *(*src)++;
    if ((v < 0xD800) || (v > 0xDFFF)) {
        return v;
    }
    return 0x10000+0x400*(v-0xD800)+(v-0xDC00);
}

static inline char32_t
UTF_16_DECODE_SWAPPED(const char32_t *restrict *src) {
    union {
        char16_t    v;
        char        b[2];
    } str = {*(*src)++};
    char t = str.b[0];
    str.b[0] = str.b[1];
    str.b[1] = t;
    if ((str.v < 0xD800) || (str.v > 0xDFFF)) {
        return str.v;
    }
    return 0x10000+0x400*(str.v-0xd800)+(str.v-0xdc00);
}

static inline ptrdiff_t
UTF_8_REPRS(const char src[restrict], char dst[restrict]) {
    ptrdiff_t off = 0; /* src offset */
    ptrdiff_t pos = 1; /* dst offset */
    *dst = '"';
    while (1) {
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

static inline ptrdiff_t
UTF_8_REPR(const char src[restrict], FILE *dst) {
    ptrdiff_t pos = PTRDIFF_C(0);
    ptrdiff_t ret;
    ptrdiff_t put;
    if (fputc('"', dst) < 0) {
        fail: {
            return PTRDIFF_C(0)-1;
        }
    }
    else {
        ret = PTRDIFF_C(1);
    }
    while (1) {
        const wint_t chr = (wint_t) UTF_8_DECODE(src+pos, &pos);
        if (chr == WEOF) {
            goto fail;
        }
        if (chr == 0) {
            if (fprintf(dst, "\"") < 0) {
                goto fail;
            }
            return ret+1;
        }
        if (chr > 0x7F) {
            if (chr > 0xFFFF) {
                put = UNICODE_ESC_32F((char32_t) chr, dst);
            }
            else {
                put = UNICODE_ESC_16F((char16_t) chr, dst);
            }
            if (put < 0) {
                goto fail;
            }
            ret += put;
        }
        else {
            if (fputs(ASCII_REPR[chr], dst) < 0) {
                goto fail;
            }
            ret+= ASCII_REPR_LEN[chr];
            pos++;
        }
    }
}
