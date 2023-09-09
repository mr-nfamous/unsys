/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

    _frol(l) 

    Move value to the lower half of a twice-as-big value. 
    The upper half of the result is full of garbage.
    

*/

#ifndef MY_EXTGOP_FROL_H // BOF
#define MY_EXTGOP_FROL_H

#ifndef MY_EXTDEF_H
#include  "extdef.h"
#endif

#ifndef MY_ISA
#   error "MY_ISA undefined"

#elif MY_ISA == ISA_ARM
#   include "extgop/arm/frol.h"

#elif MY_ISA == ISA_X86
#   include "extgop/x86/frol.h"

#elif MY_ISA == ISA_PPC

#elif MY_ISA == ISA_RV

#else
#   error "unknown value of MY_ISA"
#endif

#endif // EOF
