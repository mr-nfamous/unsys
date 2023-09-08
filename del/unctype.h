

/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#pragma once

#include <stdbool.h>

//                    fedcba9876543210
#define UN_ASCII    0b0000000010000000
#define UN_PRINT    0b0000000001111110
#define UN_CNTRL    0b0000000000000001
#define UN_BLANK    0b0000000000000010
#define UN_SPACE    0b0000000000000100
#define UN_PUNCT    0b0000000000001000
#define UN_DIGIT    0b0000000000010000
//                    |___|___|...|...
#define UN_LOWER    0b0000000000100000
#define UN_UPPER    0b0000000001000000
//                    |___|___|...|...
#define UN_XDIGIT   0b0000000100000000

#define UN_ALPHA (UN_LOWER|UN_UPPER)
#define UN_ALNUM (UN_ALPHA|UN_DIGIT)
#define UN_GRAPH (UN_PUNCT|UN_ALNUM|UN_SPACE)

int unisalnum(int);
int unisalpha(int);
int unisascii(int);
int unisblank(int);
int uniscntrl(int);
int unisdigit(int);
int unisgraph(int);
int unislower(int);
int unisspace(int);
int unisprint(int);
int unisupper(int);
int unisxdigit(int);
int untoupper(int);
int untolower(int);
