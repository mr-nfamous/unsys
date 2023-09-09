/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

    _fror(r) 
    
    Initialize the upper half of a value with 'r'. The lower
    half of the result is undefined.

*/

#ifndef MY_EXTGOP_FROR_H // BOF
#define MY_EXTGOP_FROR_H

#ifndef MY_EXTDEF_H
#include  "extdef.h"
#endif

#ifndef MY_ISA
#   error "MY_ISA undefined"

#elif MY_ISA == ISA_ARM
#   include "extgop/arm/fror.h"

#elif MY_ISA == ISA_X86
#   include "extgop/x86/fror.h"

#elif MY_ISA == ISA_PPC

#elif MY_ISA == ISA_RV

#else
#   error "unknown value of MY_ISA"
#endif

#ifndef MY_EXTVEC_H
#else
#endif

#endif // EOF
