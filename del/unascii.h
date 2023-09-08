/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#pragma once

#include "unctype.h"

static const unsigned int
CTYPE_ASCII [256] = {
    [000] = UN_ASCII|UN_CNTRL,    
    [001] = UN_ASCII|UN_CNTRL,    
    [002] = UN_ASCII|UN_CNTRL,    
    [003] = UN_ASCII|UN_CNTRL,   
    [004] = UN_ASCII|UN_CNTRL,   
    [005] = UN_ASCII|UN_CNTRL,    
    [006] = UN_ASCII|UN_CNTRL,  
    [007] = UN_ASCII|UN_CNTRL,         // \a
    [010] = UN_ASCII|UN_CNTRL,         // \b
    [011] = UN_ASCII|UN_CNTRL|UN_SPACE|UN_BLANK, // \t
    [012] = UN_ASCII|UN_CNTRL|UN_SPACE,// \n
    [013] = UN_ASCII|UN_CNTRL|UN_SPACE,// \v
    [014] = UN_ASCII|UN_CNTRL|UN_SPACE,// \f
    [015] = UN_ASCII|UN_CNTRL|UN_SPACE,// \r
    [016] = UN_ASCII|UN_CNTRL, 
    [017] = UN_ASCII|UN_CNTRL,   
    [020] = UN_ASCII|UN_CNTRL,   
    [021] = UN_ASCII|UN_CNTRL,  
    [022] = UN_ASCII|UN_CNTRL,   
    [023] = UN_ASCII|UN_CNTRL,   
    [024] = UN_ASCII|UN_CNTRL, 
    [025] = UN_ASCII|UN_CNTRL, 
    [026] = UN_ASCII|UN_CNTRL, 
    [027] = UN_ASCII|UN_CNTRL, 
    [030] = UN_ASCII|UN_CNTRL,   
    [031] = UN_ASCII|UN_CNTRL,  
    [032] = UN_ASCII|UN_CNTRL,  
    [033] = UN_ASCII|UN_CNTRL,  
    [034] = UN_ASCII|UN_CNTRL, 
    [035] = UN_ASCII|UN_CNTRL,   
    [036] = UN_ASCII|UN_CNTRL, 
    [037] = UN_ASCII|UN_CNTRL,
    [' '] = UN_ASCII|UN_SPACE|UN_BLANK,
    ['!'] = UN_ASCII|UN_PUNCT,
    ['"'] = UN_ASCII|UN_PUNCT,
    ['#'] = UN_ASCII|UN_PUNCT,
    ['$'] = UN_ASCII|UN_PUNCT,
    ['%'] = UN_ASCII|UN_PUNCT,
    ['&'] = UN_ASCII|UN_PUNCT,
    [047] = UN_ASCII|UN_PUNCT,
    ['('] = UN_ASCII|UN_PUNCT,
    [')'] = UN_ASCII|UN_PUNCT,
    ['*'] = UN_ASCII|UN_PUNCT,
    ['+'] = UN_ASCII|UN_PUNCT,
    [','] = UN_ASCII|UN_PUNCT,
    ['-'] = UN_ASCII|UN_PUNCT,
    ['.'] = UN_ASCII|UN_PUNCT,
    ['/'] = UN_ASCII|UN_PUNCT,
    ['0'] = UN_ASCII|UN_DIGIT|UN_XDIGIT,
    ['1'] = UN_ASCII|UN_DIGIT|UN_XDIGIT,
    ['2'] = UN_ASCII|UN_DIGIT|UN_XDIGIT,
    ['3'] = UN_ASCII|UN_DIGIT|UN_XDIGIT,
    ['4'] = UN_ASCII|UN_DIGIT|UN_XDIGIT,
    ['5'] = UN_ASCII|UN_DIGIT|UN_XDIGIT,
    ['6'] = UN_ASCII|UN_DIGIT|UN_XDIGIT,
    ['7'] = UN_ASCII|UN_DIGIT|UN_XDIGIT,
    ['8'] = UN_ASCII|UN_DIGIT|UN_XDIGIT,
    ['9'] = UN_ASCII|UN_DIGIT|UN_XDIGIT,
    [':'] = UN_ASCII|UN_PUNCT,
    [';'] = UN_ASCII|UN_PUNCT,
    ['<'] = UN_ASCII|UN_PUNCT,
    ['='] = UN_ASCII|UN_PUNCT,
    ['>'] = UN_ASCII|UN_PUNCT,
    ['?'] = UN_ASCII|UN_PUNCT,
    ['@'] = UN_ASCII|UN_PUNCT,
    ['A'] = UN_ASCII|UN_UPPER|UN_XDIGIT,
    ['B'] = UN_ASCII|UN_UPPER|UN_XDIGIT,
    ['C'] = UN_ASCII|UN_UPPER|UN_XDIGIT,
    ['D'] = UN_ASCII|UN_UPPER|UN_XDIGIT,
    ['E'] = UN_ASCII|UN_UPPER|UN_XDIGIT,
    ['F'] = UN_ASCII|UN_UPPER|UN_XDIGIT,
    ['G'] = UN_ASCII|UN_UPPER,
    ['H'] = UN_ASCII|UN_UPPER,
    ['I'] = UN_ASCII|UN_UPPER,
    ['J'] = UN_ASCII|UN_UPPER,
    ['K'] = UN_ASCII|UN_UPPER,
    ['L'] = UN_ASCII|UN_UPPER,
    ['M'] = UN_ASCII|UN_UPPER,
    ['N'] = UN_ASCII|UN_UPPER,
    ['O'] = UN_ASCII|UN_UPPER,
    ['P'] = UN_ASCII|UN_UPPER,
    ['Q'] = UN_ASCII|UN_UPPER,
    ['R'] = UN_ASCII|UN_UPPER, 
    ['S'] = UN_ASCII|UN_UPPER,
    ['T'] = UN_ASCII|UN_UPPER,
    ['U'] = UN_ASCII|UN_UPPER,
    ['V'] = UN_ASCII|UN_UPPER,
    ['W'] = UN_ASCII|UN_UPPER,
    ['X'] = UN_ASCII|UN_UPPER,
    ['Y'] = UN_ASCII|UN_UPPER,
    ['Z'] = UN_ASCII|UN_UPPER,
    ['['] = UN_ASCII|UN_PUNCT,
    [0134]= UN_ASCII|UN_PUNCT,
    [']'] = UN_ASCII|UN_PUNCT,
    ['^'] = UN_ASCII|UN_PUNCT,
    ['_'] = UN_ASCII|UN_PUNCT,
    ['`'] = UN_ASCII|UN_PUNCT,
    ['a'] = UN_ASCII|UN_LOWER|UN_XDIGIT,
    ['b'] = UN_ASCII|UN_LOWER|UN_XDIGIT,
    ['c'] = UN_ASCII|UN_LOWER|UN_XDIGIT,
    ['d'] = UN_ASCII|UN_LOWER|UN_XDIGIT,
    ['e'] = UN_ASCII|UN_LOWER|UN_XDIGIT,
    ['f'] = UN_ASCII|UN_LOWER|UN_XDIGIT,
    ['g'] = UN_ASCII|UN_LOWER,
    ['h'] = UN_ASCII|UN_LOWER,
    ['i'] = UN_ASCII|UN_LOWER,
    ['j'] = UN_ASCII|UN_LOWER,
    ['k'] = UN_ASCII|UN_LOWER,
    ['l'] = UN_ASCII|UN_LOWER,
    ['m'] = UN_ASCII|UN_LOWER,
    ['n'] = UN_ASCII|UN_LOWER,
    ['o'] = UN_ASCII|UN_LOWER,
    ['p'] = UN_ASCII|UN_LOWER,
    ['q'] = UN_ASCII|UN_LOWER,
    ['r'] = UN_ASCII|UN_LOWER,
    ['s'] = UN_ASCII|UN_LOWER,
    ['t'] = UN_ASCII|UN_LOWER,
    ['u'] = UN_ASCII|UN_LOWER,
    ['v'] = UN_ASCII|UN_LOWER,
    ['w'] = UN_ASCII|UN_LOWER,
    ['x'] = UN_ASCII|UN_LOWER,
    ['y'] = UN_ASCII|UN_LOWER,
    ['z'] = UN_ASCII|UN_LOWER,
    ['{'] = UN_ASCII|UN_PUNCT,
    ['|'] = UN_ASCII|UN_PUNCT,
    ['}'] = UN_ASCII|UN_PUNCT,
    ['~'] = UN_ASCII|UN_PUNCT,
    [0x7f]= UN_ASCII|UN_CNTRL,
};

static inline bool 
ISALPHA(char c) {
    return CTYPE_ASCII[c]&UN_ALPHA;
}

static inline bool 
ISALNUM(char c) {
    return CTYPE_ASCII[c]&UN_ALNUM;
}

static inline bool 
ISASCII(char c) {
    return c < 128;
}

static inline bool 
ISBLANK(char c) {
    return CTYPE_ASCII[c]&UN_BLANK;
}

static inline bool 
ISCNTRL(char c) {
    return CTYPE_ASCII[c]&UN_CNTRL;
}

static inline bool 
ISDIGIT(char c) {
    return CTYPE_ASCII[c]&UN_DIGIT;
}

static inline bool 
ISSPACE(char c) {
    return CTYPE_ASCII[c]&UN_SPACE;
}

static inline bool 
ISLOWER(char c) {
    return CTYPE_ASCII[c]&UN_LOWER;
}

static inline bool 
ISPRINT(char c) {
    return CTYPE_ASCII[c]&UN_PRINT;
}

static inline bool 
ISUPPER(char c) {
    return CTYPE_ASCII[c]&UN_UPPER;
}

static inline bool 
ISGRAPH(char c) {
    return CTYPE_ASCII[c]&UN_GRAPH;
}

static inline bool 
ISXDIGIT(char c) {
    return CTYPE_ASCII[c]&UN_XDIGIT;
}
