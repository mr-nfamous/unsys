/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#ifndef UCD_QC_H
#define UCD_QC_H
/*  DerivedNormalizationProps.txt
# @missing: 0000..10FFFF; NFD_QC; Yes
00C0..00C5    ; NFD_QC; N #
# @missing: 0000..10FFFF; NFC_QC; Yes
0340..0341    ; NFC_QC; N #
0300..0304    ; NFC_QC; M #
# @missing: 0000..10FFFF; NFKD_QC; Yes
00A0          ; NFKD_QC; N #
# @missing: 0000..10FFFF; NFKC_QC; Yes
00A0          ; NFKC_QC; N #
0300..0304    ; NFKC_QC; M #
*/
#define Y_NFC_QC 0
#define N_NFC_QC 1
#define M_NFC_QC 2

#define Y_NFD_QC 0
#define N_NFD_QC 1

#define Y_NFKD_QC 0
#define N_NFKD_QC 1

#define Y_NFKC_QC 0
#define N_NFKC_QC 1
#define M_NFKC_QC 2

#define    YES_NFC_QC     Y_NFC_QC
#define     NO_NFC_QC     N_NFC_QC
#define  MAYBE_NFC_QC MAYBE_NFC_QC
#define   YES_NFKC_QC    Y_NFKC_QC
#define    NO_NFKC_QC    N_NFKC_QC
#define MAYBE_NFKC_QC    M_NFKC_QC

#endif