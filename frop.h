/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

_frop for arm targets

*/

#ifndef MY_EXTGOP_ARM_FROP_H // BOF
#define MY_EXTGOP_ARM_FROP_H

#ifndef MY_EXTGOP_FROP_H
#error "extgop/arm/frop.h should only be included by extgop/frop.h"
#endif

#ifndef MY_EXTVEC_H

#else


INLINE Vqbu VQBU_FROP(register Vdbu l, register Vdbu r)
{
#   define  VQBU_FROP   vcombine_u8
    return  VQBU_FROP(l, r);
}

INLINE Vqbi VQBI_FROP(register Vdbi l, register Vdbi r)
{
#   define  VQBI_FROP   vcombine_s8
    return  VQBI_FROP(l, r);
}


INLINE Vqhu VQHU_FROP(register Vdhu l, register Vdhu r)
{
#   define  VQHU_FROP   vcombine_u16
    return  VQHU_FROP(l, r);
}

INLINE Vqhi VQHI_FROP(register Vdhi l, register Vdhi r)
{
#   define  VQHI_FROP   vcombine_s16
    return  VQHI_FROP(l, r);
}


INLINE Vqwu VQWU_FROP(register Vdwu l, register Vdwu r)
{
#   define  VQWU_FROP   vcombine_u32
    return  VQWU_FROP(l, r);
}

INLINE Vqwi VQWI_FROP(register Vdwi l, register Vdwi r)
{
#   define  VQWI_FROP   vcombine_s32
    return  VQWI_FROP(l, r);
}

INLINE Vqwf VQWF_FROP(register Vdwf l, register Vdwf r)
{
#   define  VQWF_FROP   vcombine_f32
    return  VQWF_FROP(l, r);
}


INLINE Vqdu VQDU_FROP(register Vddu l, register Vddu r)
{
#   define  VQDU_FROP   vcombine_u64
    return  VQDU_FROP(l, r);
}

INLINE Vqdi VQDI_FROP(register Vddi l, register Vddi r)
{
#   define  VQDI_FROP   vcombine_s64
    return  VQDI_FROP(l, r);
}

INLINE Vqdf VQDF_FROP(register Vddf l, register Vddf r)
{
#   define  VQDF_FROP   vcombine_f64
    return  VQDF_FROP(l, r);
}



INLINE Vobu VOBU_FROP(register Vqbu l, register Vqbu r)
{
#   define  VOBU_FROP(l, r) (Vobu){.V0=(l), .V1=(r)};
    return  VOBU_FROP(l, r);
}

INLINE Vobi VOBI_FROP(register Vqbi l, register Vqbi r)
{
#   define  VOBI_FROP(l, r) (Vobi){.V0=(l), .V1=(r)};
    return  VOBI_FROP(l, r);
}


INLINE Vohu VOHU_FROP(register Vqhu l, register Vqhu r)
{
#   define  VOHU_FROP(l, r) (Vohu){.V0=(l), .V1=(r)};
    return  VOHU_FROP(l, r);
}

INLINE Vohi VOHI_FROP(register Vqhi l, register Vqhi r)
{
#   define  VOHI_FROP(l, r) (Vohi){.V0=(l), .V1=(r)};
    return  VOHI_FROP(l, r);
}


INLINE Vowu VOWU_FROP(register Vqwu l, register Vqwu r)
{
    return (Vowu){.V0=l, .V1=r};
#   define  VOWU_FROP   VOWU_FROP
}

INLINE Vowi VOWI_FROP(register Vqwi l, register Vqwi r)
{
#   define  VOWI_FROP(l, r) (Vowi){.V0=(l), .V1=(r)};
    return  VOWI_FROP(l, r);
}

INLINE Vowf VOWF_FROP(register Vqwf l, register Vqwf r)
{
#   define  VOWF_FROP(l, r) (Vowf){.V0=(l), .V1=(r)};
    return  VOWF_FROP(l, r);
}


INLINE Vodu VODU_FROP(register Vqdu l, register Vqdu r)
{
#   define  VODU_FROP(l, r) (Vodu){.V0=(l), .V1=(r)};
    return  VODU_FROP(l, r);
}

INLINE Vodi VODI_FROP(register Vqdi l, register Vqdi r)
{
#   define  VODI_FROP(l, r) (Vodi){.V0=(l), .V1=(r)};
    return  VODI_FROP(l, r);
}

INLINE Vodf VODF_FROP(register Vqdf l, register Vqdf r)
{
#   define  VODF_FROP(l, r) (Vodf){.V0=(l), .V1=(r)};
    return  VODF_FROP(l, r);
}



INLINE Vsbu VSBU_FROP(register Vobu l, register Vobu r)
{
#   define  VSBU_FROP   VSBU_FROP
    return (Vsbu){.V0=l.V0, .V1=l.V1, .V2=r.V0, .V3=r.V1};
}

INLINE Vsbi VSBI_FROP(register Vobi l, register Vobi r)
{
#   define  VSBI_FROP   VSBI_FROP
    return (Vsbi){.V0=l.V0, .V1=l.V1, .V2=r.V0, .V3=r.V1};
}


INLINE Vshu VSHU_FROP(register Vohu l, register Vohu r)
{
#   define  VSHU_FROP   VSHU_FROP
    return (Vshu){.V0=l.V0, .V1=l.V1, .V2=r.V0, .V3=r.V1};
}

INLINE Vshi VSHI_FROP(register Vohi l, register Vohi r)
{
#   define  VSHI_FROP   VSHI_FROP
    return (Vshi){.V0=l.V0, .V1=l.V1, .V2=r.V0, .V3=r.V1};
}


INLINE Vswu VSWU_FROP(register Vowu l, register Vowu r)
{
#   define  VSWU_FROP   VSWU_FROP
    return (Vswu){.V0=l.V0, .V1=l.V1, .V2=r.V0, .V3=r.V1};
}

INLINE Vswi VSWI_FROP(register Vowi l, register Vowi r)
{
#   define  VSWI_FROP   VSWI_FROP
    return (Vswi){.V0=l.V0, .V1=l.V1, .V2=r.V0, .V3=r.V1};
}

INLINE Vswf VSWF_FROP(register Vowf l, register Vowf r)
{
#   define  VSWF_FROP   VSWF_FROP
    return (Vswf){.V0=l.V0, .V1=l.V1, .V2=r.V0, .V3=r.V1};
}


INLINE Vsdu VSDU_FROP(register Vodu l, register Vodu r)
{
#   define  VSDU_FROP   VSDU_FROP
    return (Vsdu){.V0=l.V0, .V1=l.V1, .V2=r.V0, .V3=r.V1};
}

INLINE Vsdi VSDI_FROP(register Vodi l, register Vodi r)
{
#   define  VSDI_FROP   VSDI_FROP
    return (Vsdi){.V0=l.V0, .V1=l.V1, .V2=r.V0, .V3=r.V1};
}

INLINE Vsdf VSDF_FROP(register Vodf l, register Vodf r)
{
#   define  VSDF_FROP   VSDF_FROP
    return (Vsdf){.V0=l.V0, .V1=l.V1, .V2=r.V0, .V3=r.V1};
}

#endif

#endif // EOF
