/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

#pragma once

#include "ucd/age.h"
#include "ucd/bc.h"

#define UCD_HTTPS(...) "https://www.unicode.org/" #__VA_ARGS__

#define UCD_EMOJI_MODIFIER_BASE                 UCD_EBASE
#define UCD_EMOJI_COMPONENT                     UCD_ECOMP
#define UCD_EMOJI_MODIFIER                      UCD_EMOD
#define UCD_EMOJI                               UCD_EMOJI
#define UCD_EMOJI_PRESENTATION                  UCD_EPRES
#define UCD_EXTENDED_PICTOGRAPHIC               UCD_EXTPICT

#define UCD_COMPOSITION_EXCLUSION               UCD_CE

#define UCD_FULL_COMPOSITION_EXCLUSION          UCD_COMP_EX
#define UCD_CHANGES_WHEN_NFKC_CASEFOLDED        UCD_CWKCF
#define UCD_ASCII_HEX_DIGIT                     UCD_AHEX
#define UCD_BIDI_CONTROL                        UCD_BIDI_C
#define UCD_DEPRECATED                          UCD_DEP
#define UCD_DIACRITIC                           UCD_DIA
#define UCD_EXTENDER                            UCD_EXT
#define UCD_HEX_DIGIT                           UCD_HEX
#define UCD_IDEOGRAPHIC                         UCD_IDEO
#define UCD_IDS_BINARY_OPERATOR                 UCD_IDSB
#define UCD_IDS_TRINARY_OPERATOR                UCD_IDST
#define UCD_JOIN_CONTROL                        UCD_JOIN_C
#define UCD_LOGICAL_ORDER_EXCEPTION             UCD_LOE
#define UCD_NONCHARACTER_CODE_POINT             UCD_NCHAR
#define UCD_OTHER_ALPHABETIC                    UCD_OALPHA
#define UCD_OTHER_DEFAULT_IGNORABLE_CODE_POINT  UCD_ODI
#define UCD_OTHER_GRAPHEME_EXTEND               UCD_OGR_EXT
#define UCD_OTHER_ID_CONTINUE                   UCD_OIDC
#define UCD_OTHER_ID_START                      UCD_OIDS
#define UCD_OTHER_LOWERCASE                     UCD_OLOWER
#define UCD_OTHER_MATH                          UCD_OMATH
#define UCD_OTHER_UPPERCASE                     UCD_OUPPER
#define UCD_PATTERN_SYNTAX                      UCD_PAT_SYN
#define UCD_PATTERN_WHITE_SPACE                 UCD_PAT_WS
#define UCD_PREPENDED_CONCATENATION_MARK        UCD_PCM
#define UCD_QUOTATION_MARK                      UCD_QMARK
#define UCD_REGIONAL_INDICATOR                  UCD_RI
#define UCD_SOFT_DOTTED                         UCD_SD
#define UCD_SENTENCE_TERMINAL                   UCD_STERM
#define UCD_TERMINAL_PUNCTUATION                UCD_TERM
#define UCD_UNIFIED_IDEOGRAPH                   UCD_UIDEO
#define UCD_VARIATION_SELECTOR                  UCD_VS
#define UCD_WSPACE                              UCD_SPACE
#define UCD_WHITE_SPACE                         UCD_SPACE

#define UCD_ALPHABETIC                          UCD_ALPHA
#define UCD_CASE_IGNORABLE                      UCD_CI
#define UCD_CHANGES_WHEN_CASEFOLDED             UCD_CWCF
#define UCD_CHANGES_WHEN_CASEMAPPED             UCD_CWCM
#define UCD_CHANGES_WHEN_LOWERCASED             UCD_CWL
#define UCD_CHANGES_WHEN_TITLECASED             UCD_CWT
#define UCD_CHANGES_WHEN_UPPERCASED             UCD_CWU
#define UCD_DEFAULT_IGNORABLE_CODE_POINT        UCD_DI
#define UCD_GRAPHEME_BASE                       UCD_GR_BASE
#define UCD_GRAPHEME_EXTEND                     UCD_GR_EXT

#define UCD_ID_CONTINUE                         UCD_IDC
#define UCD_ID_START                            UCD_IDS
#define UCD_LOWERCASE                           UCD_LOWER
#define UCD_UPPERCASE                           UCD_UPPER
#define UCD_XID_CONTINUE                        UCD_XIDC
#define UCD_XID_START                           UCD_XIDS
#define UCD_BIDI_MIRRORED                       UCD_BIDI_M
#if 0
#define UCD_GRAPHEME_LINK UCD_GR_LINK
#define UCD_EXPANDS_ON_NFC                      UCD_XO_NFC
#define UCD_EXPANDS_ON_NFD                      UCD_XO_NFD
#define UCD_EXPANDS_ON_NFKC                     UCD_XO_NFKC
#define UCD_EXPANDS_ON_NFKD                     UCD_XO_NFKD
#endif

enum {

/* FICTIONAL */
    UCD_PLANE,   // Plane
/* BINARY */ 
//  emoji/emoji-data.txt
/*  
0023          ; Emoji                # E0.0
231A..231B    ; Emoji_Presentation   # E0.6 
1F3FB..1F3FF  ; Emoji_Modifier       # E1.0 
261D          ; Emoji_Modifier_Base  # E0.6 
0023          ; Emoji_Component      # E0.0 
00A9          ; Extended_Pictographic# E0.6 

NOTE: The default EXTPICT for [1F000..1FAFF] | [1FC00..1FFFD] 
is true according to UAX #44.
*/
    UCD_EMOJI,  // [N] "Emoji"
    UCD_EPRES,  // [N] "Emoji_Presentation"
    UCD_EMOD,   // [N] "Emoji_Modifier"
    UCD_EBASE,  // [N] "Emoji_Modifier_Base"
    UCD_ECOMP,  // [N] "Emoji_Component"
    UCD_EXTPICT,// [N] "Extended_Pictographic"

//  CompositionExclusions.txt
/*  
# (1) Script Specifics
0958    #
# (2) Post Composition Version precomposed characters
2ADC    #

*/
    UCD_CE, //  

// DerivedNormalizationProps.txt
/*  

037A  ; FC_NFKC; 0020 03B9      #
0340..0341    ; Full_Composition_Exclusion #
00C0..00C5    ; NFD_QC; N #
0340..0341    ; NFC_QC; N #
0300..0304    ; NFC_QC; M #
00A0          ; NFKD_QC; N #
00A0          ; NFKC_QC; N # 
0300..0304    ; NFKC_QC; M #
00C0..00C5    ; Expands_On_NFD #
0344          ; Expands_On_NFC #
00A8          ; Expands_On_NFKD #
00A8          ; Expands_On_NFKC #
0041          ; NFKC_CF; 0061           #
0041..005A    ; Changes_When_NFKC_Casefolded #
*/
    UCD_COMP_EX,// [N] "Full_Composition_Exclusion"
    UCD_CWKCF,  // [I] "Changes_When_NFKC_Casefolded"
#if 0
    UCD_XO_NFC, //  "Expands_On_NFC"
    UCD_XO_NFD, //  "Expands_On_NFD"
    UCD_XO_NFKC,//  "Expands_On_NFKC"
    UCD_XO_NFKD,//  "Expands_On_NFKD"
#endif

//  PropList.txt  
/*  
0009..000D    ; White_Space #
061C          ; Bidi_Control #
200C..200D    ; Join_Control #
002D          ; Dash #
002D          ; Hyphen #
0022          ; Quotation_Mark #
0021          ; Terminal_Punctuation #
005E          ; Other_Math #
0030..0039    ; Hex_Digit #
0030..0039    ; ASCII_Hex_Digit #
0345          ; Other_Alphabetic #
3006          ; Ideographic #
005E          ; Diacritic #
00B7          ; Extender #
00AA          ; Other_Lowercase #
2160..216F    ; Other_Uppercase #
FDD0..FDEF    ; Noncharacter_Code_Point #
09BE          ; Other_Grapheme_Extend #
2FF0..2FF1    ; IDS_Binary_Operator #
2FF2..2FF3    ; IDS_Trinary_Operator #
2E80..2E99    ; Radical #
3400..4DBF    ; Unified_Ideograph #
034F          ; Other_Default_Ignorable_Code_Point #
0149          ; Deprecated #
0069..006A    ; Soft_Dotted #
0E40..0E44    ; Logical_Order_Exception #
1885..1886    ; Other_ID_Start #
00B7          ; Other_ID_Continue #
0021          ; Sentence_Terminal #
180B..180D    ; Variation_Selector #
0009..000D    ; Pattern_White_Space #
0021..0023    ; Pattern_Syntax #
0600..0605    ; Prepended_Concatenation_Mark #
1F1E6..1F1FF  ; Regional_Indicator #
*/
    UCD_SPACE,  // [N] "White_Space"
    UCD_BIDI_C, // [N] "Bidi_Control"
    UCD_JOIN_C, // [N] "Join_Control"
    UCD_DASH,   // [I] "Dash"
    UCD_HYPHEN, // [D] "Hyphen"
    UCD_QMARK,  // [I] "Quotation_Mark"
    UCD_TERM,   // [I] "Terminal_Punctuation"
    UCD_OMATH,  // [C] "Other_Math"
    UCD_HEX,    // [I] "Hex_Digit"
    UCD_AHEX,   // [N] "ASCII_Hex_Digit"
    UCD_OALPHA, // [C] "Other_Alphabetic"
    UCD_IDEO,   // [I] "Ideographic"
    UCD_DIA,    // [I] "Diacritic"
    UCD_EXT,    // [I] "Extender"
    UCD_OLOWER, // [C] "Other_Lowercase"
    UCD_OUPPER, // [C] "Other_Uppercase"
    UCD_NCHAR,  // [N] "Noncharacter_Code_Point"
    UCD_OGR_EXT,// [C] "Other_Grapheme_Extend"
    UCD_IDSB,   // [N] "IDS_Binary_Operator"
    UCD_IDST,   // [N] "IDS_Trinary_Operator"
    UCD_RADICAL,// [N] "Radical"
    UCD_UIDEO,  // [N] "Unified_Ideograph"
    UCD_ODI,    // [C] "Other_Default_Ignorable_Code_Point"
    UCD_DEP,    // [N] "Deprecated"
    UCD_SD,     // [N] "Soft_Dotted"
    UCD_LOE,    // [N] "Logical_Order_Exception"
    UCD_OIDS,   // [C] "Other_ID_Start"
    UCD_OIDC,   // [C] "Other_ID_Continue"
    UCD_STERM,  // [I] "Sentence_Terminal"
    UCD_VS,     // [N] "Variation_Selector"
    UCD_PAT_WS, // [N] "Pattern_White_Space"
    UCD_PAT_SYN,// [N] "Pattern_Syntax"
    UCD_RI,     // [N] "Regional_Indicator"
    UCD_PCM,    // [I] "Prepended_Concatenation_Mark"
    
//  DerivedCoreProperties.txt
/*  

002B          ; Math #
0041..005A    ; Alphabetic #
0061..007A    ; Lowercase #
0041..005A    ; Uppercase #
0041..005A    ; Cased 
0027          ; Case_Ignorable #
0041..005A    ; Changes_When_Lowercased #
0061..007A    ; Changes_When_Uppercased #
0061..007A    ; Changes_When_Titlecased #
0041..005A    ; Changes_When_Casefolded #
0041..005A    ; Changes_When_Casemapped #
0041..005A    ; ID_Start #
0030..0039    ; ID_Continue #
0041..005A    ; XID_Start #
0030..0039    ; XID_Continue #
00AD          ; Default_Ignorable_Code_Point #
0300..036F    ; Grapheme_Extend #
0020          ; Grapheme_Base #
094D          ; Grapheme_Link #
*/
    UCD_MATH,   // [I] "Math"
    UCD_ALPHA,  // [I] "Alphabetic"
    UCD_LOWER,  // [I] "Lowercase"
    UCD_UPPER,  // [I] "Uppercase"
    UCD_CASED,  // [I] "Cased"
    UCD_CI,     // [I] "Case_Ignorable"
    UCD_CWL,    // [I] "Changes_When_Lowercased"
    UCD_CWU,    // [I] "Changes_When_Uppercased"
    UCD_CWT,    // [I] "Changes_When_Titlecased"
    UCD_CWCF,   // [I] "Changes_When_Casefolded"
    UCD_CWCM,   // [I] "Changes_When_Casemapped"
    UCD_IDS,    // [I] "ID_Start"
    UCD_IDC,    // [I] "ID_Continue"
    UCD_XIDS,   // [I] "XID_Start"
    UCD_XIDC,   // [I] "XID_Continue"
    UCD_DI,     // [N] "Default_Ignorable_Code_Point"
    UCD_GR_EXT, // [N] "Grapheme_Extend"
    UCD_GR_BASE,// [N] "Grapheme_Base"
#if 0
    UCD_GR_LINK,// [I] "Grapheme_Link"
#endif

/*  extracted/DerivedBinaryProperties.txt
0028          ; "Bidi_Mirrored" #
*/
    UCD_BIDI_M, // 
/* CATALOG */ 
    UCD_AGE,     // Age
    UCD_SC,      // Script
    UCD_BLK,     // Block
/* ENUM */ 
    UCD_BC,      // Bidi_Class
    UCD_BPT,     // Bidi_Paired_Bracket_Type
    UCD_CCC,     // Canonical_Combining_Class
    UCD_DT,      // Decomposition_Type
    UCD_EA,      // East_Asian_Width
    UCD_GC,      // General_Category 
    UCD_GCB,     // Grapheme_Cluster_Break 
    UCD_HST,     // Hangul_Syllable_Type 
    UCD_INPC,    // Indic_Positional_Category 
    UCD_INSC,    // Indic_Syllabic_Category
    UCD_JG,      // Joining_Group
    UCD_JT,      // Joining_Type
    UCD_LB,      // Line_Break 
    UCD_NFC_QC,  // NFC_Quick_Check
    UCD_NFD_QC,  // NFD_Quick_Check
    UCD_NFKC_QC, // NFKC_Quick_Check 
    UCD_NFKD_QC, // NFKD_Quick_Check 
    UCD_NT,      // Numeric_Type
    UCD_SB,      // Sentence_Break 
    UCD_VO,      // Vertical_Orientation 
    UCD_WB,      // Word_Break 
/* CHRMAP */ 
/* STRMAP */ 

    /*

#define UCD_BIDI_CLASS UCD_bc
#define UCD_BIDI_PAIRED_BRACKET_TYPE UCD_bpt
#define UCD_CANONICAL_COMBINING_CLASS UCD_ccc
#define UCD_DECOMPOSITION_TYPE UCD_dt
#define UCD_EAST_ASIAN_WIDTH UCD_ea
#define UCD_GENERAL_CATEGORY UCD_GC
#define UCD_GRAPHEME_CLUSTER_BREAK UCD_GCB
#define UCD_HANGUL_SYLLABLE_TYPE UCD_HST
#define UCD_INDIC_POSITIONAL_CATEGORY UCD_INPC
#define UCD_INDIC_SYLLABIC_CATEGORY UCD_INSC
#define UCD_JOINING_GROUP UCD_JG
#define UCD_JOINING_TYPE UCD_JT
#define UCD_LINE_BREAK UCD_LB
#define UCD_NFC_QUICK_CHECK UCD_NFC_QC
#define UCD_NFD_QUICK_CHECK UCD_NFD_QC
#define UCD_NFKC_QUICK_CHECK UCD_NFKC_QC
#define UCD_NFKD_QUICK_CHECK UCD_NFKD_QC
#define UCD_NUMERIC_TYPE UCD_NT
#define UCD_SENTENCE_BREAK UCD_SB
#define UCD_VERTICAL_ORIENTATION UCD_VO
#define UCD_WORD_BREAK UCD_WB
*/
};


struct UCDEntry {
    unsigned 
        bpt: 2, // N_BPT, O_BPT, C_BPT
        :   0;
    _Bool 
    //  DerivedNormalizationProps.txt
        Full_Composition_Exclusion:    1,
        Changes_When_NFKC_Casefolded:      1,

        Emoji_Presentation: 1,
        Emoji_Modifier: 1,
        Emoji_Modifier_Base: 1,
        Emoji_Component: 1,
        Extended_Pictographic: 1,
        
        Quotation_Mark: 1,
        Terminal_Punctuation: 1,
        Other_Math: 1,
        Hex_Digit: 1,
        ASCII_Hex_Digit: 1,
        Other_Alphabetic: 1,
        Ideographic: 1,
        Diacritic: 1,
        Extender: 1,
        Other_Lowercase: 1,
        Other_Uppercase: 1,
        Noncharacter_Code_Point: 1,
        Other_Grapheme_Extend: 1,
        IDS_Binary_Operator: 1,
        IDS_Trinary_Operator: 1,
        Radical: 1,
        Unified_Ideograph: 1,
        Other_Default_Ignorable_Code_Point: 1,
        Deprecated: 1,
        Soft_Dotted: 1,
        Logical_Order_Exception: 1,
        Other_ID_Start: 1,
        Other_ID_Continue: 1,
        Sentence_Terminal: 1,
        Variation_Selector: 1,
        Pattern_White_Space: 1,
        Pattern_Syntax: 1,
        Regional_Indicator: 1,
        Prepended_Concatenation_Mark: 1,

        Math: 1,
        Alphabetic: 1,
        Lowercase: 1,
        Uppercase: 1,
        Cased: 1,
        Case_Ignorable: 1,
        Changes_When_Lowercased: 1,
        Changes_When_Uppercased: 1,
        Changes_When_Titlecased: 1,
        Changes_When_Casefolded: 1,
        Changes_When_Casemapped: 1,
        ID_Start: 1,
        ID_Continue: 1,
        XID_Start: 1,
        XID_Continue: 1,
        Default_Ignorable_Code_Point: 1,
        Grapheme_Extend: 1,
        Grapheme_Base: 1,
        Grapheme_Link: 1,
        :   0;
};

/*

InPC                     ; Indic_Positional_Category
InSC                     ; Indic_Syllabic_Category
jg                       ; Joining_Group
jt                       ; Joining_Type
lb                       ; Line_Break
NFC_QC                   ; NFC_Quick_Check
NFD_QC                   ; NFD_Quick_Check
NFKC_QC                  ; NFKC_Quick_Check
NFKD_QC                  ; NFKD_Quick_Check
nt                       ; Numeric_Type
SB                       ; Sentence_Break
vo                       ; Vertical_Orientation
WB                       ; Word_Break

*/