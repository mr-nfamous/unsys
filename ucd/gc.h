/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

/* extracted/DerivedGeneralCategory.txt

10FFFE..10FFFF; Cn #
0041..005A    ; Lu #
0061..007A    ; Ll #
01C5          ; Lt #
02B0..02C1    ; Lm #
00AA          ; Lo #
0300..036F    ; Mn #
0488..0489    ; Me #
0903          ; Mc #
0030..0039    ; Nd #
00B2..00B3    ; No #
0020          ; Zs #
2028          ; Zl #
2029          ; Zp #
0000..001F    ; Cc #
00AD          ; Cf #
E000..F8FF    ; Co #
D800..DFFF    ; Cs #
002D          ; Pd #
0028          ; Ps #
0029          ; Pe #
005F          ; Pc #
0021..0023    ; Po #
002B          ; Sm #
0024          ; Sc #
005E          ; Sk #
00A6          ; So #
00AB          ; Pi #
00BB          ; Pf #

*/
#ifndef UCD_GC_H
#define UCD_GC_H

#define BISP_AUTO (0) // choose at first use 
#define BISP_LEAF (1) // dead end 
#define BISP_STEM (2) // list
#define BISP_TRIE (3) // trie
#define BISP_TYPE (0x3)

#define BISP_LATIN_TRIE BISP_TRIE, 256, (BISP[256])
#define BISP_ASCII_TRIE BISP_TRIE, 128, (BISP[128])

#define BISP_IGNORE_CASE    (1<<14)
#define BISP_NEGATE         (1<<15)

typedef struct bisp BISP;

typedef struct ucd_enum {
    int key;
    int val;
} UCD_ENUM;

typedef struct bisp {
    unsigned short type;
    unsigned short size;
    void        *index;   
    const char *match;
    BISP       *table;
} BISP;
    
struct bisp_tree {
    unsigned type;
    unsigned size;
    BISP *tree;
    void *data;
};

struct bisp_tree UCD_PROPERTY_MATCH = {
    BISP_ASCII_TRIE
    {
        ['a'] = {
            BISP_AUTO, 1, 
            &(UCD_ENUM){UCD_GC, 
        },
    }
}
/*

    <ab|cd>         = "(?:^ab$)|(?:^cd$)"
    <ab/$/cd>       = "(?:^ab(?:cd)?$"
    <ab/$/cd/$/ef>  = "(?:^ab(?:cd(?:ef)?)?$)"
    
*/
#define CN_GC   0  // <cn|unassigned>
#define CO_GC   1  // <co|other>
#define CC_GC   2  // <cc|control|cntrl>
#define CF_GC   3  // <cf|fmt|format>
#define CS_GC   4  // <cs|sgt|surrogate>

#define ZS_GC   5  // <zs|ssep|sp/$/ace/$/sep/$/arator>
#define ZL_GC   6  // <zl|lsep|linesep/arator>
#define ZP_GC   7  // <zp|psep|paragraphsep/arator>

#define MN_GC   8  // <mn|nsmark|nonspacing/mark>
#define MC_GC   9  // <mc|smark|spacing/mark>
#define ME_GC   10 // <me|emark|enclosing/mark>

#define SO_GC   11 // <so|osym|othersymbol>
#define SK_GC   12 // <sk|msym|mod/$/ifier/$/symbol>
#define SC_GC   13 // <sc|csym|currency#symbol>
#define SM_GC   14 // <sm|msym|math#symbol>

#define PO_GC   15 // <po|opunct|otherpunct#uation>
#define PI_GC   16 // <pi|ipunct|init#ial#punct#uation>
#define PF_GC   17 // <pf|fpunct|final#punct#uation
#define PS_GC   18 // <po|opunct|open#punct#uation>
#define PE_GC   19 // <pe|cpunct|close#punct#uation>
#define PC_GC   20 // <pc|jpunct|connector#punct#uation>
#define PD_GC   21 // <pd|dpunct|ash_Punctuation

#define NO_GC   22 // Other_Number
#define ND_GC   23 // Decimal_Number 
#define NL_GC   24 // Letter_Number

#define LO_GC   25 // Other_Letter
#define LM_GC   26 // Modifier_Letter
#define LL_GC   27 // Lowercase_Letter
#define LU_GC   28 // Uppercase_Letter
#define LT_GC   29 // Titlecase_Letter

#define       OTHER_GC  C_GC
#define  UNASSIGNED_GC CN_GC
#define       CNTRL_GC CC_GC
#define     CONTROL_GC CC_GC
#define      FORMAT_GC CF_GC
#define PRIVATE_USE_GC CO_GC
#define   SURROGATE_GC CS_GC
#define           SEPARATOR_GC Z_GC
#define     SPACE_SEPARATOR_GC ZS_GC
#define      LINE_SEPARATOR_GC ZL_GC
#define PARAGRAPH_SEPARATOR_GC ZP_GC
#define            MARK_GC M_GC
#define  COMBINING_MARK_GC M_GC 
#define NONSPACING_MARK_GC MN_GC
#define    SPACING_MARK_GC MC_GC
#define  ENCLOSING_MARK_GC ME_GC
#define          SYMBOL_GC  S_GC
#define    OTHER_SYMBOL_GC SO_GC
#define MODIFIER_SYMBOL_GC SK_GC
#define CURRENCY_SYMBOL_GC SC_GC
#define     MATH_SYMBOL_GC SM_GC

#define           PUNCTUATION_GC  P_GC
#define     OTHER_PUNCTUATION_GC PO_GC
#define   INITIAL_PUNCTUATION_GC PI_GC
#define     FINAL_PUNCTUATION_GC PF_GC
#define      OPEN_PUNCTUATION_GC PS_GC
#define     CLOSE_PUNCTUATION_GC PE_GC
#define CONNECTOR_PUNCTUATION_GC PC_GC
#define      DASH_PUNCTUATION_GC PD_GC

#define           PUNCT_GC  P_GC
#define     OTHER_PUNCT_GC PO_GC
#define   INITIAL_PUNCT_GC PI_GC
#define     FINAL_PUNCT_GC PF_GC
#define      OPEN_PUNCT_GC PS_GC
#define     CLOSE_PUNCT_GC PE_GC
#define CONNECTOR_PUNCT_GC PC_GC
#define      DASH_PUNCT_GC PD_GC

#define          DIGIT_GC ND_GC
#define         NUMBER_GC  N_GC
#define   OTHER_NUMBER_GC NO_GC
#define DECIMAL_NUMBER_GC ND_GC
#define  LETTER_NUMBER_GC NL_GC

#define           LETTER_GC L_GC
#define     OTHER_LETTER_GC LO_GC
#define  MODIFIER_LETTER_GC LM_GC
#define     CASED_LETTER_GC LC_GC
#define LOWERCASE_LETTER_GC LL_GC
#define UPPERCASE_LETTER_GC LU_GC
#define TITLECASE_LETTER_GC LT_GC

#endif
