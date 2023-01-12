/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#ifndef UCD_WB_H
#define UCD_WB_H

/* auxiliary/WordBreakProperty.txt

NOTE the following are not official UCD symbols:
    EXT for Extend
    XNL for ExtendNumLet
    WSS for WSegSpace 

# @missing: 0000..10FFFF; Other
0022          ; Double_Quote #
0027          ; Single_Quote #
05D0..05EA    ; Hebrew_Letter #
000D          ; CR #
000A          ; LF #
000B..000C    ; Newline #
0300..036F    ; Extend #
1F1E6..1F1FF  ; Regional_Indicator #
00AD          ; Format #
3031..3035    ; Katakana #
0041..005A    ; ALetter #
003A          ; MidLetter #
002C          ; MidNum #
002E          ; MidNumLet #
0030..0039    ; Numeric #
005F          ; ExtendNumLet #
200D          ; ZWJ #
0020          ; WSegSpace #

*/
#define  XX_WB 0 // Other 
#define  DQ_WB 1 // Double_Quote 
#define  HL_WB 2 // Hebrew_Letter 
#define  SQ_WB 3 // Single_Quote 
#define  CR_WB 4 // CR 
#define  LF_WB 5 // LF 
#define  NL_WB 6 // Newline 
#define EXT_WB 7 // Extend*
#define  RI_WB 8 // Regional_Indicator 
#define  FO_WB 9 // Format 
#define  KA_WB 10// Katakana 
#define  LE_WB 11// ALetter 
#define  ML_WB 12// MidLetter 
#define  MN_WB 13// MidNum 
#define  MB_WB 14// MidNumLet 
#define  NU_WB 15// Numeric 
#define XNL_WB 16// ExtendNumLet*
#define ZWJ_WB 17// ZWJ 
#define WSS_WB 18// WSegSpace*

#define    CARRIAGE_RETURN_WB  CR_WB
#define          WSEGSPACE_WB WSS_WB
#define       DOUBLE_QUOTE_WB  DQ_WB
#define                 EX_WB XNL_WB
#define       EXTENDNUMLET_WB XNL_WB
#define             EXTEND_WB EXT_WB
#define             FORMAT_WB  FO_WB
#define      HEBREW_LETTER_WB  HL_WB
#define           KATAKANA_WB  KA_WB
#define            ALETTER_WB  LE_WB
#define          LINE_FEED_WB  LF_WB
#define          MIDNUMLET_WB  MB_WB
#define          MIDLETTER_WB  ML_WB
#define             MIDNUM_WB  MN_WB
#define            NEWLINE_WB  NL_WB
#define            NUMERIC_WB  NU_WB
#define REGIONAL_INDICATOR_WB  RI_WB
#define       SINGLE_QUOTE_WB  SQ_WB
#define              OTHER_WB  XX_WB
#define                ZWJ_WB ZWJ_WB

#endif
