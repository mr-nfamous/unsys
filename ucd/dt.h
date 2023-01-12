/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 
UCD property "Decomposition_Type", aka "dt"
*/

#ifndef UCD_DT_H
#define UCD_DT_H

#define NONE_DT 0
#define  CAN_DT 1
#define  COM_DT 2
#define FONT_DT 3
#define   NB_DT 4
#define INIT_DT 5
#define  MED_DT 6
#define  FIN_DT 7
#define  ISO_DT 8
#define  ENC_DT 9
#define  SUP_DT 10
#define  SUB_DT 11
#define VERT_DT 12
#define WIDE_DT 13
#define  NAR_DT 14
#define  SML_DT 15
#define  SQR_DT 16
#define  FRA_DT 17

/* extracted/DerivedDecompositionType.txt
00C0..00C5    ; Canonical #
00A8          ; Compat #
2102          ; Font #
00A0          ; Nobreak #
FB54          ; Initial #
FB55          ; Medial #
FB51          ; Final #
FB50          ; Isolated #
2460..2473    ; Circle #
00AA          ; Super #
1D62..1D6A    ; Sub #
309F          ; Vertical #
3000          ; Wide #
FF61          ; Narrow #
FE50..FE52    ; Small #
3250          ; Square #
00BC..00BE    ; Fraction #*/

static const char
*UCD_DT_PATTERNS[] = {
    [NONE_DT]   = "None",
    [CAN_DT]    = "Canonical",
    [COM_DT]    = "Compat",
    [FONT_DT]   = "Font",
    [NB_DT]     = "Nobreak",
    [INIT_DT]   = "Initial",
    [MED_DT]    = "Medial",
    [FIN_DT]    = "Final",
    [ISO_DT]    = "Isolated",
    [ENC_DT]    = "Circle",
    [SUP_DT]    = "Super",
    [SUB_DT]    = "Sub",
    [VERT_DT]   = "Vertical",
    [WIDE_DT]   = "Wide",
    [NAR_DT]    = "Narrow",
    [SML_DT]    = "Small",
    [SQR_DT]    = "Square",
    [FRA_DT]    = "Fraction",
};

#define   CANONICAL_DT  CAN_DT
#define      COMPAT_DT  COM_DT  
#define     NOBREAK_DT   NB_DT
#define     INITIAL_DT INIT_DT
#define      MEDIAL_DT  MED_DT
#define       FINAL_DT  FIN_DT
#define    ISOLATED_DT  ISO_DT
#define      CIRCLE_DT  ENC_DT
#define   SUBSCRIPT_DT  SUB_DT
#define SUPERSCRIPT_DT  SUP_DT
#define    VERTICAL_DT VERT_DT
#define      NARROW_DT  NAR_DT
#define       SMALL_DT  SML_DT
#define      SQUARE_DT  SQR_DT
#define    FRACTION_DT  FRA_DT
#define        FRAC_DT  FRA_DT

#endif
