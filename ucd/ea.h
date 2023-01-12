
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#ifndef UCD_EA_H
#define UCD_EA_H
/* extracted/DerivedEastAsianWidth.txt

0000..001F    ; N
00A1          ; A #
20A9          ; H #
1100..115F    ; W #
3000          ; F #
0020          ; Na #

*/

#define  N_EA  0
#define  A_EA  1
#define  H_EA  2
#define  W_EA  3
#define  F_EA  4
#define NA_EA  5
#define N__EA  6

struct ucd_enum {
    int v;
    const char **names;
};
#define UCD_ENUM(v, ...) (struct ucd_enum){v,{__VA_ARGS__, 0}}
static const struct ucd_enum_def {
    int id;
    struct ucd_enum *list;
} ucd_ea_enum = {
    UCD_EA,
    (struct ucd_enum[]){
        UCD_ENUM(N_EA, "N"),
        UCD_ENUM(A_EA, "A"),
        UCD_ENUM(H_EA, "H"),
        UCD_ENUM(W_EA, "W"),
        UCD_ENUM(F_EA, "F"),
        UCD_ENUM(NA_EA, "NA"),
    },
};

#define   NEUTRAL_EA  N_EA
#define AMBIGUOUS_EA  A_EA
#define HALFWIDTH_EA  H_EA
#define      WIDE_EA  W_EA
#define FULLWIDTH_EA  F_EA
#define    NARROW_EA NA_EA

#endif