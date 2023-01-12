/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

/* VerticalOrientation.txt
0000..001F     ; R  #

*/
#ifndef UCD_VO_H
#define UCD_VO_H

#define  T_VO (001)
#define  R_VO (002)
#define  U_VO (010)
#define TU_VO (T_VO|U_VO)
#define TR_VO (T_VO|R_VO)

#define             ROTATED_VO R_VO
#define             UPRIGHT_VO U_VO
#define         TRANSFORMED_VO  T_VO
#define TRANSFORMED_ROTATED_VO TR_VO
#define TRANSFORMED_UPRIGHT_VO TU_VO

#endif
