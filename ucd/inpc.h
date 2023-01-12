/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#ifndef UCD_INPC_H
#define UCD_INPC_H
/*
0903          ; Right #
093F          ; Left #
0E40..0E44    ; Visual_Order_Left #
09CB..09CC    ; Left_And_Right #
0900..0902    ; Top #
093C          ; Bottom #
0C48          ; Top_And_Bottom #
0AC9          ; Top_And_Right #
0B48          ; Top_And_Left #
0B4C          ; Top_And_Left_And_Right #
1B3B          ; Bottom_And_Right #
A9BF          ; Bottom_And_Left #
1B3D          ; Top_And_Bottom_And_Right #
103C          ; Top_And_Bottom_And_Left #
1CD4          ; Overstruck #
*/


#define  NA_INPC 0 // NA 
#define   R_INPC 1 // Right
#define   L_INPC 2 // Left 
#define  VL_INPC 3 // Visual_Order_Left 
#define  LR_INPC 4 // Left_And_Right
#define   T_INPC 5 // Top 
#define   B_INPC 6 // Bottom
#define  TB_INPC 7 // Top_And_Bottom 
#define  TR_INPC 8 // Top_And_Right
#define  TL_INPC 9 // Top_And_Left 
#define TLR_INPC 10// Top_And_Left_And_Right 
#define  BR_INPC 11// Bottom_And_Right 
#define  BL_INPC 12// Bottom_And_Left 
#define TBR_INPC 13// Top_And_Bottom_And_Right 
#define TBL_INPC 14// Top_And_Bottom_And_Left
#define   O_INPC 15// Overstruck
#define                    RIGHT_INPC   R_INPC
#define                     LEFT_INPC   L_INPC
#define        VISUAL_ORDER_LEFT_INPC  VL_INPC
#define           LEFT_AND_RIGHT_INPC  LR_INPC
#define                      TOP_INPC   T_INPC
#define                   BOTTOM_INPC   B_INPC
#define           TOP_AND_BOTTOM_INPC  TB_INPC
#define            TOP_AND_RIGHT_INPC  TR_INPC
#define             TOP_AND_LEFT_INPC  TL_INPC
#define   TOP_AND_LEFT_AND_RIGHT_INPC TLR_INPC
#define         BOTTOM_AND_RIGHT_INPC  BR_INPC
#define          BOTTOM_AND_LEFT_INPC  BL_INPC
#define TOP_AND_BOTTOM_AND_RIGHT_INPC TBR_INPC
#define  TOP_AND_BOTTOM_AND_LEFT_INPC TBL_INPC
#define               OVERSTRUCK_INPC   O_INPC
#endif
