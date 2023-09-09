/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

_fror for arm targets

*/

#ifndef MY_EXTGOP_ARM_FROR_H // BOF
#define MY_EXTGOP_ARM_FROR_H

#ifndef MY_EXTGOP_FROR_H
#error "extgop/arm/fror.h should only be included by extgop/fror.h"
#endif

#ifndef MY_EXTVEC_H

#else

INLINE Vqbu VQBU_FROR(register Vdbu r)
{
#   define  VQBU_FROR(r) vcombine_u8(vdup_n_u8(0), r)
    return  VQBU_FROR(r);
}

INLINE Vqbi VQBI_FROR(register Vdbi r)
{
#   define  VQBI_FROR(r) vcombine_s8(vdup_n_s8(0), r)
    return  VQBI_FROR(r);
}


INLINE Vqhu VQHU_FROR(register Vdhu r)
{
#   define  VQHU_FROR(r) vcombine_u16(vdup_n_u16(0), r)
    return  VQHU_FROR(r);
}

INLINE Vqhi VQHI_FROR(register Vdhi r)
{
#   define  VQHI_FROR(r) vcombine_s16(vdup_n_s16(0), r)
    return  VQHI_FROR(r);
}


INLINE Vqwu VQWU_FROR(register Vdwu r)
{
#   define  VQWU_FROR(r) vcombine_u32(vdup_n_u32(0), r)
    return  VQWU_FROR(r);
}

INLINE Vqwi VQWI_FROR(register Vdwi r)
{
#   define  VQWI_FROR(r) vcombine_s32(vdup_n_s32(0), r)
    return  VQWI_FROR(r);
}

INLINE Vqwf VQWF_FROR(register Vdwf r)
{
#   define  VQWF_FROR(r) vcombine_f32(vdup_n_f32(0), r)
    return  VQWF_FROR(r);
}


INLINE Vqdu VQDU_FROR(register Vddu r)
{
#   define  VQDU_FROR(r) vcombine_u64(vdup_n_u64(0), r)
    return  VQDU_FROR(r);
}

INLINE Vqdi VQDI_FROR(register Vddi r)
{
#   define  VQDI_FROR(r) vcombine_s64(vdup_n_s64(0), r)
    return  VQDI_FROR(r);
}

INLINE Vqdf VQDF_FROR(register Vddf r)
{
#   define  VQDF_FROR(r) vcombine_f64(vdup_n_f64(0), r)
    return  VQDF_FROR(r);
}


INLINE Vobu VOBU_FROR(register Vqbu r)
{
#define     VOBU_FROR(r)    (Vobu){.V1=r}
    return  VOBU_FROR(r);
}

INLINE Vobi VOBI_FROR(register Vqbi r)
{
#define     VOBI_FROR(r)    (Vobi){.V1=r}
    return  VOBI_FROR(r);
}


INLINE Vohu VOHU_FROR(register Vqhu r)
{
#define     VOHU_FROR(r)    (Vohu){.V1=r}
    return  VOHU_FROR(r);
}

INLINE Vohi VOHI_FROR(register Vqhi r)
{
#define     VOHI_FROR(r)    (Vohi){.V1=r}
    return  VOHI_FROR(r);
}


INLINE Vowu VOWU_FROR(register Vqwu r)
{
#define     VOWU_FROR(r)    (Vowu){.V1=r}
    return  VOWU_FROR(r);
}

INLINE Vowi VOWI_FROR(register Vqwi r)
{
#define     VOWI_FROR(r)    (Vowi){.V1=r}
    return  VOWI_FROR(r);
}

INLINE Vowf VOWF_FROR(register Vqwf r)
{
#define     VOWF_FROR(r)    (Vowf){.V1=r}
    return  VOWF_FROR(r);
}


INLINE Vodu VODU_FROR(register Vqdu r)
{
#define     VODU_FROR(r)    (Vodu){.V1=r}
    return  VODU_FROR(r);
}

INLINE Vodi VODI_FROR(register Vqdi r)
{
#define     VODI_FROR(r)    (Vodi){.V1=r}
    return  VODI_FROR(r);
}

INLINE Vodf VODF_FROR(register Vqdf r)
{
#define     VODF_FROR(r)    (Vodf){.V1=r}
    return  VODF_FROR(r);
}


INLINE Vsbu VSBU_FROR(register Vobu r)
{
#define     VSBU_FROR(r)    (Vsbu){.V2=(r).V0, .V3=(r).V1}
    return  VSBU_FROR(r);
}

INLINE Vsbi VSBI_FROR(register Vobi r)
{
#define     VSBI_FROR(r)    (Vsbi){.V2=(r).V0, .V3=(r).V1}
    return  VSBI_FROR(r);
}


INLINE Vshu VSHU_FROR(register Vohu r)
{
#define     VSHU_FROR(r)    (Vshu){.V2=(r).V0, .V3=(r).V1}
    return  VSHU_FROR(r);
}

INLINE Vshi VSHI_FROR(register Vohi r)
{
#define     VSHI_FROR(r)    (Vshi){.V2=(r).V0, .V3=(r).V1}
    return  VSHI_FROR(r);
}


INLINE Vswu VSWU_FROR(register Vowu r)
{
#define     VSWU_FROR(r)    (Vswu){.V2=(r).V0, .V3=(r).V1}
    return  VSWU_FROR(r);}

INLINE Vswi VSWI_FROR(register Vowi r)
{
#define     VSWI_FROR(r)    (Vswi){.V2=(r).V0, .V3=(r).V1}
    return  VSWI_FROR(r);
}

INLINE Vswf VSWF_FROR(register Vowf r)
{
#define     VSWF_FROR(r)    (Vswf){.V2=(r).V0, .V3=(r).V1}
    return  VSWF_FROR(r);
}


INLINE Vsdu VSDU_FROR(register Vodu r)
{
#define     VSDU_FROR(r)    (Vsdu){.V2=(r).V0, .V3=(r).V1}
    return  VSDU_FROR(r);
}

INLINE Vsdi VSDI_FROR(register Vodi r)
{
#define     VSDI_FROR(r)    (Vsdi){.V2=(r).V0, .V3=(r).V1}
    return  VSDI_FROR(r);
}

INLINE Vsdf VSDF_FROR(register Vodf r)
{
#define     VSDF_FROR(r)    (Vsdf){.V2=(r).V0, .V3=(r).V1}
    return  VSDF_FROR(r);
}



#endif


#endif // EOF
