/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#ifndef UCD_SB_H
#define UCD_SB_H

/*
auxiliary/SentenceBreakProperty.txt
000D          ; CR #
000A          ; LF #
0300..036F    ; Extend #
0085          ; Sep #
00AD          ; Format #
0009          ; Sp #
0061..007A    ; Lower #
0041..005A    ; Upper #
01BB          ; OLetter #
0030..0039    ; Numeric #
002E          ; ATerm #
0021          ; STerm #
0022          ; Close #
002C          ; SContinue #
*/

#define XX_SB 0 // Other 
#define CR_SB 1 // 
#define LF_SB 2 // 
#define EX_SB 3 // Extend
#define SE_SB 4 // Sep
#define FO_SB 5 // Format
#define SP_SB 6 // Space
#define LO_SB 7 // Lower
#define UP_SB 8 // Upper 
#define LE_SB 9 // OLetter
#define NU_SB 10// Numeric
#define AT_SB 11// ATerm
#define ST_SB 12// STerm
#define CL_SB 13// Close 
#define SC_SB 14// SContinue

#define     ATerm_SB AT_SB
#define     Close_SB CL_SB
#define    Extend_SB EX_SB
#define    Format_SB FO_SB
#define   OLetter_SB LE_SB
#define     Lower_SB LO_SB
#define   Numeric_SB NU_SB
#define SContinue_SB SC_SB
#define       Sep_SB SE_SB
#define        Sp_SB SP_SB
#define     STerm_SB ST_SB
#define     Upper_SB UP_SB
#define     Other_SB XX_SB
