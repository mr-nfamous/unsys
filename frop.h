/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

    _frop(l, r) 

    Reconstruct a value previously split into equal length
    upper ('r') and lower ('l') halves. 

*/

#ifndef MY_EXTGOP_FROP_H // BOF
#define MY_EXTGOP_FROP_H

#ifndef MY_EXTDEF_H
#include  "extdef.h"
#endif

#ifndef MY_ISA
#   error "MY_ISA undefined"

#elif MY_ISA == ISA_ARM
#   include "extgop/arm/frop.h"

#elif MY_ISA == ISA_X86
#   include "extgop/x86/frop.h"

#elif MY_ISA == ISA_PPC

#elif MY_ISA == ISA_RV

#else
#   error "unknown value of MY_ISA"
#endif

INLINE  Xhu XHU_FROP(Bu l, Bu r) {return (Xhu){.Lo=l, .Hi=r};}
INLINE  Xhi XHI_FROP(Bi l, Bi r) {return (Xhi){.Lo=l, .Hi=r};}
INLINE  Xhf XHF_FROP(Bu l, Bu r) {return (Xh){.U={.Lo=l, .Hi=r}}.F;}

INLINE  Xwu XWU_FROP(Hu l, Hu r) {return (Xwu){.Lo=l, .Hi=r};}
INLINE  Xwi XWI_FROP(Hi l, Hi r) {return (Xwi){.Lo=l, .Hi=r};}
INLINE  Xwf XWF_FROP(Hu l, Hu r) {return (Xw){.U={.Lo=l, .Hi=r}}.F;}

INLINE  Xdu XDU_FROP(Wu l, Wu r) {return (Xdu){.Lo=l, .Hi=r};}
INLINE  Xdi XDI_FROP(Wi l, Wi r) {return (Xdi){.Lo=l, .Hi=r};}
INLINE  Xdf XDF_FROP(Wu l, Wu r) {return (Xd){.U={.Lo=l, .Hi=r}}.F;}

INLINE  Xqu XQU_FROP(Du l, Du r) {return (Xqu){.Lo=l, .Hi=r};}
INLINE  Xqi XQI_FROP(Di l, Di r) {return (Xqi){.Lo=l, .Hi=r};}
INLINE  Xqf XQF_FROP(Du l, Du r) {return (Xq){.U={.Lo=l, .Hi=r}}.F;}


#define XHU_FROP(l, r) (Xhu){.Lo=(l), .Hi=(r)}
#define XHI_FROP(l, r) (Xhi){.Lo=(l), .Hi=(r)}
#define XHF_FROP(l, r) (Xh){.U={.Lo=(l), .Hi=(r)}}.F

#define XWU_FROP(l, r) (Xwu){.Lo=(l), .Hi=(r)}
#define XWI_FROP(l, r) (Xwi){.Lo=(l), .Hi=(r)}
#define XWF_FROP(l, r) (Xw){.U={.Lo=(l), .Hi=(r)}}.F

#define XDU_FROP(l, r) (Xdu){.Lo=(l), .Hi=(r)}
#define XDI_FROP(l, r) (Xdi){.Lo=(l), .Hi=(r)}
#define XDF_FROP(l, r) (Xd){.U={.Lo=(l), .Hi=(r)}}.F

#define XQU_FROP(l, r) (Xqu){.Lo=(l), .Hi=(r)}
#define XQI_FROP(l, r) (Xqi){.Lo=(l), .Hi=(r)}
#define XQF_FROP(l, r) (Xq){.U.Lo=(l), .U.Hi=(r)}.F


Xhu fropxhu(Bu, Bu);
Xhi fropxhi(Bi, Bi);
Xhf fropxhf(Bu, Bu);

Xwu fropxwu(Hu, Hu);
Xwi fropxwi(Hi, Hi);
Xwf fropxwf(Hu, Hu);

Xdu fropxdu(Wu, Wu);
Xdi fropxdi(Wi, Wi);
Xdf fropxdf(Wu, Wu);

Xqu fropxqu(Du, Du);
Xqi fropxqi(Di, Di);
Xqf fropxqf(Du, Du);

#define fropxhu XHU_FROP
#define fropxhi XHI_FROP
#define fropxhf XHF_FROP

#define fropxwu XWU_FROP
#define fropxwi XWI_FROP
#define fropxwf XWF_FROP

#define fropxdu XDU_FROP
#define fropxdi XDI_FROP
#define fropxdf XDF_FROP

#define fropxqu XQU_FROP
#define fropxqi XQI_FROP
#define fropxqf XQF_FROP

#ifndef MY_EXTVEC_H
#else

Vqbu fropqbu(register Vdbu, register Vdbu);
Vqbi fropqbi(register Vdbi, register Vdbi);

Vqhu fropqhu(register Vdhu, register Vdhu);
Vqhi fropqhi(register Vdhi, register Vdhi);

Vqwu fropqwu(register Vdwu, register Vdwu);
Vqwi fropqwi(register Vdwi, register Vdwi);
Vqwf fropqwf(register Vdwf, register Vdwf);

Vqdu fropqdu(register Vddu, register Vddu);
Vqdi fropqdi(register Vddi, register Vddi);
Vqdf fropqdf(register Vddf, register Vddf);


Vobu fropobu(register Vqbu, register Vqbu);
Vobi fropobi(register Vqbi, register Vqbi);

Vohu fropohu(register Vqhu, register Vqhu);
Vohi fropohi(register Vqhi, register Vqhi);

Vowu fropowu(register Vqwu, register Vqwu);
Vowi fropowi(register Vqwi, register Vqwi);
Vowf fropowf(register Vqwf, register Vqwf);

Vodu fropodu(register Vqdu, register Vqdu);
Vodi fropodi(register Vqdi, register Vqdi);
Vodf fropodf(register Vqdf, register Vqdf);


Vsbu fropsbu(register Vobu, register Vobu);
Vsbi fropsbi(register Vobi, register Vobi);

Vshu fropshu(register Vohu, register Vohu);
Vshi fropshi(register Vohi, register Vohi);

Vswu fropswu(register Vowu, register Vowu);
Vswi fropswi(register Vowi, register Vowi);
Vswf fropswf(register Vowf, register Vowf);

Vsdu fropsdu(register Vodu, register Vodu);
Vsdi fropsdi(register Vodi, register Vodi);
Vsdf fropsdf(register Vodf, register Vodf);


#define fropqbu VQBU_FROP
#define fropqbi VQBI_FROP

#define fropqhu VQHU_FROP
#define fropqhi VQHI_FROP

#define fropqwu VQWU_FROP
#define fropqwi VQWI_FROP
#define fropqwf VQWF_FROP

#define fropqdu VQDU_FROP
#define fropqdu VQDU_FROP
#define fropqdf VQDF_FROP

#define fropobu VOBU_FROP
#define fropobi VOBI_FROP

#define fropohu VOHU_FROP
#define fropohi VOHI_FROP

#define fropowu VOWU_FROP
#define fropowi VOWI_FROP
#define fropowf VOWF_FROP

#define fropodu VODU_FROP
#define fropodu VODU_FROP
#define fropodf VODF_FROP

#define fropsbu VSBU_FROP
#define fropsbi VSBI_FROP

#define fropshu VSHU_FROP
#define fropshi VSHI_FROP

#define fropswu VSWU_FROP
#define fropswi VSWI_FROP
#define fropswf VSWF_FROP

#define fropsdu VSDU_FROP
#define fropsdu VSDU_FROP
#define fropsdf VSDF_FROP

#endif // defined(MY_EXTVEC_H)

#endif // EOF