#pragma once
#include <math.h>

int include_math_h(Lib *self, FILE *file) {

        /*
    __basedef(math_h, "<math.h>")

    __dentr(enums, Enum[])
        __predef("M")
            EDEF_(M,E)
            EDEF_(M,LOG2E)
            EDEF_(M,LOG10E)
            EDEF_(M,LN2)
            EDEF_(M,LN10)
            EDEF_(M,PI)
            EDEF_(M,PI_2)
            EDEF_(M,PI_4)
            EDEF_(M,1_PI)
            EDEF_(M,2_PI)
            EDEF_(M,2_SQRTPI)
            EDEF_(M,SQRT2)
            EDEF_(M,SQRT1_2)
        __preend("M")
    __dexit(enums)

    __dentr(structs, Struct[])
    __dexit(structs)
    __baseret(math_h)
        */
    return 0;
}

int test_math_h(Lib *self, FILE *file) {
#   ifndef BLTN_ILOGB
#   define BLTN_ILOGB ilogb
#   endif
#   ifndef BLTN_ABS
#   define BLTN_ABS abs 
#   endif
#   ifndef BLTN_ILOGBL
#   define BLTN_ILOGBL ilogbl
#   endif
#   ifndef BLTN_ILOGBF
#   define BLTN_ILOGBF ilogbf
#   endif
#   ifndef BLTN_LRINT
#   define BLTN_LRINT lrint
#   endif
#   ifndef BLTN_LROUND
#   define BLTN_LROUND lround
#   endif
#   ifndef BLTN_LRINTF
#   define BLTN_LRINTF lrintf
#   endif
#   ifndef BLTN_LROUNDF
#   define BLTN_LROUNDF lroundf
#   endif
#   ifndef BLTN_LRINTL
#   define BLTN_LRINTL lrintl
#   endif
#   ifndef BLTN_LROUNDL
#   define BLTN_LROUNDL lroundl
#   endif
#   ifndef BLTN_LLRINTL
#   define BLTN_LLRINTL llrintl
#   endif
#   ifndef BLTN_LLROUNDL
#   define BLTN_LLROUNDL llroundl
#   endif
#   ifndef BLTN_LLRINT
#   define BLTN_LLRINT llrint
#   endif
#   ifndef BLTN_LLROUND
#   define BLTN_LLROUND llround
#   endif
#   ifndef BLTN_LLRINTF
#   define BLTN_LLRINTF llrintf
#   endif
#   ifndef BLTN_LLROUNDF
#   define BLTN_LLROUNDF llroundf
#   endif
#   ifndef BLTN_ACOSHL
#   define BLTN_ACOSHL acoshl
#   endif
#   ifndef BLTN_ACOSL
#   define BLTN_ACOSL acosl
#   endif
#   ifndef BLTN_ASINHL
#   define BLTN_ASINHL asinhl
#   endif
#   ifndef BLTN_ASINL
#   define BLTN_ASINL asinl
#   endif
#   ifndef BLTN_ATAN2L
#   define BLTN_ATAN2L atan2l
#   endif
#   ifndef BLTN_ATANHL
#   define BLTN_ATANHL atanhl
#   endif

#   ifndef BLTN_ATANL
#   define BLTN_ATANL atanl
#   endif

#   ifndef BLTN_CBRTL
#   define BLTN_CBRTL cbrtl
#   endif

#   ifndef BLTN_CEILL
#   define BLTN_CEILL ceill
#   endif

#   ifndef BLTN_COPYSIGNL
#   define BLTN_COPYSIGNL copysignl
#   endif

#   ifndef BLTN_COSHL
#   define BLTN_COSHL coshl
#   endif

#   ifndef BLTN_COSL
#   define BLTN_COSL cosl
#   endif

#   ifndef BLTN_ERFCL
#   define BLTN_ERFCL erfcl
#   endif

#   ifndef BLTN_ERFL
#   define BLTN_ERFL erfl
#   endif

#   ifndef BLTN_EXP2L
#   define BLTN_EXP2L exp2l
#   endif

#   ifndef BLTN_EXPL
#   define BLTN_EXPL expl
#   endif

#   ifndef BLTN_EXPM1L
#   define BLTN_EXPM1L expm1l
#   endif

#   ifndef BLTN_FABSL
#   define BLTN_FABSL fabsl
#   endif

#   ifndef BLTN_FDIML
#   define BLTN_FDIML fdiml
#   endif

#   ifndef BLTN_FLOORL
#   define BLTN_FLOORL floorl
#   endif

#   ifndef BLTN_FMAL
#   define BLTN_FMAL fmal
#   endif

#   ifndef BLTN_FMAXL
#   define BLTN_FMAXL fmaxl
#   endif

#   ifndef BLTN_FMINL
#   define BLTN_FMINL fminl
#   endif

#   ifndef BLTN_FMODL
#   define BLTN_FMODL fmodl
#   endif

#   ifndef BLTN_FREXPL
#   define BLTN_FREXPL frexpl
#   endif

#   ifndef BLTN_HYPOTL
#   define BLTN_HYPOTL hypotl
#   endif

#   ifndef BLTN_LDEXPL
#   define BLTN_LDEXPL ldexpl
#   endif

#   ifndef BLTN_LGAMMAL
#   define BLTN_LGAMMAL lgammal
#   endif

#   ifndef BLTN_LOG10L
#   define BLTN_LOG10L log10l
#   endif

#   ifndef BLTN_LOG1PL
#   define BLTN_LOG1PL log1pl
#   endif

#   ifndef BLTN_LOG2L
#   define BLTN_LOG2L log2l
#   endif

#   ifndef BLTN_LOGBL
#   define BLTN_LOGBL logbl
#   endif

#   ifndef BLTN_LOGL
#   define BLTN_LOGL logl
#   endif

#   ifndef BLTN_MODFL
#   define BLTN_MODFL modfl
#   endif

#   ifndef BLTN_NEARBYINTL
#   define BLTN_NEARBYINTL nearbyintl
#   endif

#   ifndef BLTN_NEXTAFTERL
#   define BLTN_NEXTAFTERL nextafterl
#   endif

#   ifndef BLTN_NEXTTOWARDL
#   define BLTN_NEXTTOWARDL nexttowardl
#   endif

#   ifndef BLTN_POWL
#   define BLTN_POWL powl
#   endif

#   ifndef BLTN_REMAINDERL
#   define BLTN_REMAINDERL remainderl
#   endif

#   ifndef BLTN_REMQUOL
#   define BLTN_REMQUOL remquol
#   endif

#   ifndef BLTN_RINTL
#   define BLTN_RINTL rintl
#   endif

#   ifndef BLTN_ROUNDL
#   define BLTN_ROUNDL roundl
#   endif

#   ifndef BLTN_SCALBLNL
#   define BLTN_SCALBLNL scalblnl
#   endif

#   ifndef BLTN_SCALBNL
#   define BLTN_SCALBNL scalbnl
#   endif

#   ifndef BLTN_SINHL
#   define BLTN_SINHL sinhl
#   endif

#   ifndef BLTN_SINL
#   define BLTN_SINL sinl
#   endif

#   ifndef BLTN_SQRTL
#   define BLTN_SQRTL sqrtl
#   endif

#   ifndef BLTN_TANHL
#   define BLTN_TANHL tanhl
#   endif

#   ifndef BLTN_TANL
#   define BLTN_TANL tanl
#   endif

#   ifndef BLTN_TGAMMAL
#   define BLTN_TGAMMAL tgammal
#   endif

#   ifndef BLTN_TRUNCL
#   define BLTN_TRUNCL truncl
#   endif

#   ifndef BLTN_NANL
#   define BLTN_NANL nanl
#   endif

#   ifndef BLTN_JN
#   define BLTN_JN jn
#   endif

#   ifndef BLTN_YN
#   define BLTN_YN yn
#   endif

#   ifndef BLTN_ACOS
#   define BLTN_ACOS acos
#   endif

#   ifndef BLTN_ACOSH
#   define BLTN_ACOSH acosh
#   endif

#   ifndef BLTN_ASIN
#   define BLTN_ASIN asin
#   endif

#   ifndef BLTN_ASINH
#   define BLTN_ASINH asinh
#   endif

#   ifndef BLTN_ATAN
#   define BLTN_ATAN atan
#   endif

#   ifndef BLTN_ATAN2
#   define BLTN_ATAN2 atan2
#   endif

#   ifndef BLTN_ATANH
#   define BLTN_ATANH atanh
#   endif

#   ifndef BLTN_CBRT
#   define BLTN_CBRT cbrt
#   endif

#   ifndef BLTN_CEIL
#   define BLTN_CEIL ceil
#   endif

#   ifndef BLTN_COPYSIGN
#   define BLTN_COPYSIGN copysign
#   endif

#   ifndef BLTN_COS
#   define BLTN_COS cos
#   endif

#   ifndef BLTN_COSH
#   define BLTN_COSH cosh
#   endif

#   ifndef BLTN_ERF
#   define BLTN_ERF erf
#   endif

#   ifndef BLTN_ERFC
#   define BLTN_ERFC erfc
#   endif

#   ifndef BLTN_EXP
#   define BLTN_EXP exp
#   endif

#   ifndef BLTN_EXP2
#   define BLTN_EXP2 exp2
#   endif

#   ifndef BLTN_EXPM1
#   define BLTN_EXPM1 expm1
#   endif

#   ifndef BLTN_FABS
#   define BLTN_FABS fabs
#   endif

#   ifndef BLTN_FDIM
#   define BLTN_FDIM fdim
#   endif

#   ifndef BLTN_FLOOR
#   define BLTN_FLOOR floor
#   endif

#   ifndef BLTN_FMA
#   define BLTN_FMA fma
#   endif

#   ifndef BLTN_FMAX
#   define BLTN_FMAX fmax
#   endif

#   ifndef BLTN_FMIN
#   define BLTN_FMIN fmin
#   endif

#   ifndef BLTN_FMOD
#   define BLTN_FMOD fmod
#   endif

#   ifndef BLTN_FREXP
#   define BLTN_FREXP frexp
#   endif

#   ifndef BLTN_HYPOT
#   define BLTN_HYPOT hypot
#   endif

#   ifndef BLTN_J0
#   define BLTN_J0 j0
#   endif

#   ifndef BLTN_J1
#   define BLTN_J1 j1
#   endif

#   ifndef BLTN_LDEXP
#   define BLTN_LDEXP ldexp
#   endif

#   ifndef BLTN_LGAMMA
#   define BLTN_LGAMMA lgamma
#   endif

#   ifndef BLTN_LOG
#   define BLTN_LOG log
#   endif

#   ifndef BLTN_LOG10
#   define BLTN_LOG10 log10
#   endif

#   ifndef BLTN_LOG1P
#   define BLTN_LOG1P log1p
#   endif

#   ifndef BLTN_LOG2
#   define BLTN_LOG2 log2
#   endif

#   ifndef BLTN_LOGB
#   define BLTN_LOGB logb
#   endif

#   ifndef BLTN_MODF
#   define BLTN_MODF modf
#   endif

#   ifndef BLTN_NEARBYINT
#   define BLTN_NEARBYINT nearbyint
#   endif

#   ifndef BLTN_NEXTAFTER
#   define BLTN_NEXTAFTER nextafter
#   endif

#   ifndef BLTN_NEXTTOWARD
#   define BLTN_NEXTTOWARD nexttoward
#   endif

#   ifndef BLTN_POW
#   define BLTN_POW pow
#   endif

#   ifndef BLTN_REMAINDER
#   define BLTN_REMAINDER remainder
#   endif

#   ifndef BLTN_REMQUO
#   define BLTN_REMQUO remquo
#   endif

#   ifndef BLTN_RINT
#   define BLTN_RINT rint
#   endif

#   ifndef BLTN_ROUND
#   define BLTN_ROUND round
#   endif

#   ifndef BLTN_SCALBLN
#   define BLTN_SCALBLN scalbln
#   endif

#   ifndef BLTN_SCALBN
#   define BLTN_SCALBN scalbn
#   endif

#   ifndef BLTN_SIN
#   define BLTN_SIN sin
#   endif

#   ifndef BLTN_SINH
#   define BLTN_SINH sinh
#   endif

#   ifndef BLTN_SQRT
#   define BLTN_SQRT sqrt
#   endif

#   ifndef BLTN_TAN
#   define BLTN_TAN tan
#   endif

#   ifndef BLTN_TANH
#   define BLTN_TANH tanh
#   endif

#   ifndef BLTN_TGAMMA
#   define BLTN_TGAMMA tgamma
#   endif

#   ifndef BLTN_TRUNC
#   define BLTN_TRUNC trunc
#   endif

#   ifndef BLTN_Y0
#   define BLTN_Y0 y0
#   endif

#   ifndef BLTN_Y1
#   define BLTN_Y1 y1
#   endif

#   ifndef BLTN_NAN
#   define BLTN_NAN nan
#   endif

#   ifndef BLTN_ACOSF
#   define BLTN_ACOSF acosf
#   endif

#   ifndef BLTN_ACOSHF
#   define BLTN_ACOSHF acoshf
#   endif

#   ifndef BLTN_ASINF
#   define BLTN_ASINF asinf
#   endif

#   ifndef BLTN_ASINHF
#   define BLTN_ASINHF asinhf
#   endif

#   ifndef BLTN_ATAN2F
#   define BLTN_ATAN2F atan2f
#   endif

#   ifndef BLTN_ATANF
#   define BLTN_ATANF atanf
#   endif

#   ifndef BLTN_ATANHF
#   define BLTN_ATANHF atanhf
#   endif

#   ifndef BLTN_CBRTF
#   define BLTN_CBRTF cbrtf
#   endif

#   ifndef BLTN_CEILF
#   define BLTN_CEILF ceilf
#   endif

#   ifndef BLTN_COPYSIGNF
#   define BLTN_COPYSIGNF copysignf
#   endif

#   ifndef BLTN_COSF
#   define BLTN_COSF cosf
#   endif

#   ifndef BLTN_COSHF
#   define BLTN_COSHF coshf
#   endif

#   ifndef BLTN_ERFCF
#   define BLTN_ERFCF erfcf
#   endif

#   ifndef BLTN_ERFF
#   define BLTN_ERFF erff
#   endif

#   ifndef BLTN_EXP2F
#   define BLTN_EXP2F exp2f
#   endif

#   ifndef BLTN_EXPF
#   define BLTN_EXPF expf
#   endif

#   ifndef BLTN_EXPM1F
#   define BLTN_EXPM1F expm1f
#   endif

#   ifndef BLTN_FABSF
#   define BLTN_FABSF fabsf
#   endif

#   ifndef BLTN_FDIMF
#   define BLTN_FDIMF fdimf
#   endif

#   ifndef BLTN_FLOORF
#   define BLTN_FLOORF floorf
#   endif

#   ifndef BLTN_FMAF
#   define BLTN_FMAF fmaf
#   endif

#   ifndef BLTN_FMAXF
#   define BLTN_FMAXF fmaxf
#   endif

#   ifndef BLTN_FMINF
#   define BLTN_FMINF fminf
#   endif

#   ifndef BLTN_FMODF
#   define BLTN_FMODF fmodf
#   endif

#   ifndef BLTN_FREXPF
#   define BLTN_FREXPF frexpf
#   endif

#   ifndef BLTN_HYPOTF
#   define BLTN_HYPOTF hypotf
#   endif

#   ifndef BLTN_LDEXPF
#   define BLTN_LDEXPF ldexpf
#   endif

#   ifndef BLTN_LGAMMAF
#   define BLTN_LGAMMAF lgammaf
#   endif

#   ifndef BLTN_LOG10F
#   define BLTN_LOG10F log10f
#   endif

#   ifndef BLTN_LOG1PF
#   define BLTN_LOG1PF log1pf
#   endif

#   ifndef BLTN_LOG2F
#   define BLTN_LOG2F log2f
#   endif

#   ifndef BLTN_LOGBF
#   define BLTN_LOGBF logbf
#   endif

#   ifndef BLTN_LOGF
#   define BLTN_LOGF logf
#   endif

#   ifndef BLTN_MODFF
#   define BLTN_MODFF modff
#   endif

#   ifndef BLTN_NANF
#   define BLTN_NANF nanf
#   endif

#   ifndef BLTN_NEARBYINTF
#   define BLTN_NEARBYINTF nearbyintf
#   endif

#   ifndef BLTN_NEXTAFTERF
#   define BLTN_NEXTAFTERF nextafterf
#   endif

#   ifndef BLTN_NEXTTOWARDF
#   define BLTN_NEXTTOWARDF nexttowardf
#   endif

#   ifndef BLTN_POWF
#   define BLTN_POWF powf
#   endif

#   ifndef BLTN_REMAINDERF
#   define BLTN_REMAINDERF remainderf
#   endif

#   ifndef BLTN_REMQUOF
#   define BLTN_REMQUOF remquof
#   endif

#   ifndef BLTN_RINTF
#   define BLTN_RINTF rintf
#   endif

#   ifndef BLTN_ROUNDF
#   define BLTN_ROUNDF roundf
#   endif

#   ifndef BLTN_SCALBLNF
#   define BLTN_SCALBLNF scalblnf
#   endif

#   ifndef BLTN_SCALBNF
#   define BLTN_SCALBNF scalbnf
#   endif

#   ifndef BLTN_SINF
#   define BLTN_SINF sinf
#   endif

#   ifndef BLTN_SINHF
#   define BLTN_SINHF sinhf
#   endif

#   ifndef BLTN_SQRTF
#   define BLTN_SQRTF sqrtf
#   endif

#   ifndef BLTN_TANF
#   define BLTN_TANF tanf
#   endif

#   ifndef BLTN_TANHF
#   define BLTN_TANHF tanhf
#   endif

#   ifndef BLTN_TGAMMAF
#   define BLTN_TGAMMAF tgammaf
#   endif

#   ifndef BLTN_TRUNCF
#   define BLTN_TRUNCF truncf
#   endif
    /*
    self->acos=BLTN_ACOS;
    self->jn=BLTN_JN;
    self->yn=BLTN_YN;
    self->acosh=BLTN_ACOSH;
    self->asin=BLTN_ASIN;
    self->asinh=BLTN_ASINH;
    self->atan=BLTN_ATAN;
    self->atan2=BLTN_ATAN2;
    self->atanh=BLTN_ATANH;
    self->cbrt=BLTN_CBRT;
    self->ceil=BLTN_CEIL;
    self->copysign=BLTN_COPYSIGN;
    self->cos=BLTN_COS;
    self->cosh=BLTN_COSH;
    self->erf=BLTN_ERF;
    self->erfc=BLTN_ERFC;
    self->exp=BLTN_EXP;
    self->exp2=BLTN_EXP2;
    self->expm1=BLTN_EXPM1;
    self->fabs=BLTN_FABS;
    self->fdim=BLTN_FDIM;
    self->floor=BLTN_FLOOR;
    self->fma=BLTN_FMA;
    self->fmax=BLTN_FMAX;
    self->fmin=BLTN_FMIN;
    self->fmod=BLTN_FMOD;
    self->frexp=BLTN_FREXP;
    self->hypot=BLTN_HYPOT;
    self->j0=BLTN_J0;
    self->j1=BLTN_J1;
    self->ldexp=BLTN_LDEXP;
    self->lgamma=BLTN_LGAMMA;
    self->log=BLTN_LOG;
    self->log10=BLTN_LOG10;
    self->log1p=BLTN_LOG1P;
    self->log2=BLTN_LOG2;
    self->logb=BLTN_LOGB;
    self->modf=BLTN_MODF;
    self->nearbyint=BLTN_NEARBYINT;
    self->nextafter=BLTN_NEXTAFTER;
    self->nexttoward=BLTN_NEXTTOWARD;
    self->remainder=BLTN_REMAINDER;
    self->pow=BLTN_POW;
    self->remquo=BLTN_REMQUO;
    self->rint=BLTN_RINT;
    self->round=BLTN_ROUND;
    self->scalbln=BLTN_SCALBLN;
    self->scalbn=BLTN_SCALBN;
    self->sin=BLTN_SIN;
    self->sinh=BLTN_SINH;
    self->sqrt=BLTN_SQRT;
    self->tan=BLTN_TAN;
    self->tanh=BLTN_TANH;
    self->tgamma=BLTN_TGAMMA;
    self->trunc=BLTN_TRUNC;
    
    self->y0=BLTN_Y0;
    self->y1=BLTN_Y1;
    self->nan=BLTN_NAN;
    
    self->ilogb=BLTN_ILOGB;
    self->lrint=BLTN_LRINT;
    self->llrint=BLTN_LLRINT;
    
    self->ilogbl=BLTN_ILOGBL;
    self->ilogbf=BLTN_ILOGBF;
    
    self->lrintf=BLTN_LRINTF;
    self->lrintl=BLTN_LRINTL;
    
    self->llrintl=BLTN_LLRINTL;
    self->llrintf=BLTN_LLRINTF;
    
    self->lroundf=BLTN_LROUNDF;
    self->lround=BLTN_LROUND;
    self->lroundl=BLTN_LROUNDL;
    
    self->llroundl=BLTN_LLROUNDL;
    self->llround=BLTN_LLROUND;
    self->llroundf=BLTN_LLROUNDF;
    
    
    self->acoshl=BLTN_ACOSHL;
    self->acosl=BLTN_ACOSL;
    
    self->asinhl=BLTN_ASINHL;
    
    self->asinl=BLTN_ASINL;
    self->atan2l=BLTN_ATAN2L;
    self->atanhl=BLTN_ATANHL;
    self->atanl=BLTN_ATANL;
    self->cbrtl=BLTN_CBRTL;
    self->ceill=BLTN_CEILL;
    self->copysignl=BLTN_COPYSIGNL;
    self->coshl=BLTN_COSHL;
    self->cosl=BLTN_COSL;
    self->erfcl=BLTN_ERFCL;
    self->erfl=BLTN_ERFL;
    self->exp2l=BLTN_EXP2L;
    self->expl=BLTN_EXPL;
    self->expm1l=BLTN_EXPM1L;
    self->fabsl=BLTN_FABSL;
    self->fdiml=BLTN_FDIML;
    self->floorl=BLTN_FLOORL;
    self->fmal=BLTN_FMAL;
    self->fmaxl=BLTN_FMAXL;
    self->fminl=BLTN_FMINL;
    self->fmodl=BLTN_FMODL;
    self->frexpl=BLTN_FREXPL;
    self->hypotl=BLTN_HYPOTL;
    self->ldexpl=BLTN_LDEXPL;
    self->lgammal=BLTN_LGAMMAL;
    self->log10l=BLTN_LOG10L;
    self->log1pl=BLTN_LOG1PL;
    self->log2l=BLTN_LOG2L;
    self->logbl=BLTN_LOGBL;
    self->logl=BLTN_LOGL;
    self->modfl=BLTN_MODFL;
    self->nearbyintl=BLTN_NEARBYINTL;
    self->nextafterl=BLTN_NEXTAFTERL;
    self->nexttowardl=BLTN_NEXTTOWARDL;
    self->powl=BLTN_POWL;
    self->remainderl=BLTN_REMAINDERL;
    self->remquol=BLTN_REMQUOL;
    self->rintl=BLTN_RINTL;
    self->roundl=BLTN_ROUNDL;
    self->scalblnl=BLTN_SCALBLNL;
    self->scalbnl=BLTN_SCALBNL;
    self->sinhl=BLTN_SINHL;
    self->sinl=BLTN_SINL;
    self->sqrtl=BLTN_SQRTL;
    
    self->tanhl=BLTN_TANHL;
    
    self->tanl=BLTN_TANL;
    
    self->tgammal=BLTN_TGAMMAL;
    self->truncl=BLTN_TRUNCL;
    self->nanl=BLTN_NANL;
    
    self->acosf=BLTN_ACOSF;
    self->acoshf=BLTN_ACOSHF;
    self->asinf=BLTN_ASINF;
    self->asinhf=BLTN_ASINHF;
    self->atan2f=BLTN_ATAN2F;
    self->atanf=BLTN_ATANF;
    self->atanhf=BLTN_ATANHF;
    self->cbrtf=BLTN_CBRTF;
    self->ceilf=BLTN_CEILF;
    self->copysignf=BLTN_COPYSIGNF;
    self->cosf=BLTN_COSF;
    self->coshf=BLTN_COSHF;
    self->erfcf=BLTN_ERFCF;
    self->erff=BLTN_ERFF;
    self->exp2f=BLTN_EXP2F;
    self->expf=BLTN_EXPF;
    self->expm1f=BLTN_EXPM1F;
    self->fabsf=BLTN_FABSF;
    self->fdimf=BLTN_FDIMF;
    self->floorf=BLTN_FLOORF;
    self->fmaf=BLTN_FMAF;
    self->fmaxf=BLTN_FMAXF;
    self->fminf=BLTN_FMINF;
    self->fmodf=BLTN_FMODF;
    self->frexpf=BLTN_FREXPF;
    self->hypotf=BLTN_HYPOTF;
    self->ldexpf=BLTN_LDEXPF;
    self->lgammaf=BLTN_LGAMMAF;
    self->log10f=BLTN_LOG10F;
    self->log1pf=BLTN_LOG1PF;
    self->log2f=BLTN_LOG2F;
    self->logbf=BLTN_LOGBF;
    self->logf=BLTN_LOGF;
    self->modff=BLTN_MODFF;
    self->nanf=BLTN_NANF;
    self->nearbyintf=BLTN_NEARBYINTF;
    self->nextafterf=BLTN_NEXTAFTERF;
    self->nexttowardf=BLTN_NEXTTOWARDF;
    self->powf=BLTN_POWF;
    self->remainderf=BLTN_REMAINDERF;
    self->remquof=BLTN_REMQUOF;
    self->rintf=BLTN_RINTF;
    self->roundf=BLTN_ROUNDF;
    self->scalblnf=BLTN_SCALBLNF;
    self->scalbnf=BLTN_SCALBNF;
    self->sinf=BLTN_SINF;
    self->sinhf=BLTN_SINHF;
    self->sqrtf=BLTN_SQRTF;
    self->tanf=BLTN_TANF;
    self->tanhf=BLTN_TANHF;
    self->tgammaf=BLTN_TGAMMAF;
    self->truncf=BLTN_TRUNCF;
    */
    return 0;
}