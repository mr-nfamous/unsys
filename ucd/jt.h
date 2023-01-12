/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#ifndef UCD_JT_H
#define UCD_JT_H
/* extracted/DerivedJoiningType.txt
# @missing: 0000..10FFFF; Non_Joining
0640          ; C #
0620          ; D #
0622..0625    ; R #
A872          ; L #
00AD          ; T #

*/

#define U_JT 0 // Non_Joining
#define C_JT 1 // Join_Causing
#define D_JT 2 // Dual_Joining
#define R_JT 3 // Right_Joining
#define L_JT 4 // Left_Joining
#define T_JT 5 // Transparent

#define   NON_JOINING_JT U_JT
#define  JOIN_CAUSING_JT C_JT
#define  DUAL_JOINING_JT D_JT
#define  LEFT_JOINING_JT L_JT
#define RIGHT_JOINING_JT R_JT
#define   TRANSPARENT_JT T_JT

#endif
