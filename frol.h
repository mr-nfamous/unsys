/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳

_frol for arm targets

*/

#ifndef MY_EXTGOP_X86_FROL_H // BOF
#define MY_EXTGOP_X86_FROL_H

#ifndef MY_EXTGOP_FROL_H
#error "extgop/arm/frol.h should only be included by extgop/frol.h"
#endif

#ifndef MY_EXTVEC_H

#else

INLINE Vqbu VQBU_FROL(register Vdbu l)
{
#   define  VQBU_FROL(l)  \
vreinterpretq_u8_u64(vdupq_lane_u64(vreinterpret_u64_u8(l), 0))
    return  VQBU_FROL(l);
}

INLINE Vqbi VQBI_FROL(register Vdbi l)
{
#   define  VQBI_FROL(l) \
vreinterpretq_s8_u64(vdupq_lane_u64(vreinterpret_u64_s8(l), 0))
    return  VQBI_FROL(l);
}


INLINE Vqhu VQHU_FROL(register Vdhu l)
{
#   define  VQHU_FROL(l) \
vreinterpretq_u16_u64(vdupq_lane_u64(vreinterpret_u64_u16(l), 0))
    return  VQHU_FROL(l);
}

INLINE Vqhi VQHI_FROL(register Vdhi l)
{
#   define  VQHI_FROL(l) \
vreinterpretq_s16_u64(vdupq_lane_u64(vreinterpret_u64_s16(l), 0))
    return  VQHI_FROL(l);
}


INLINE Vqwu VQWU_FROL(register Vdwu l)
{
#   define  VQWU_FROL(l) \
vreinterpretq_u32_u64(vdupq_lane_u64(vreinterpret_u64_u32(l), 0))
    return  VQWU_FROL(l);
}

INLINE Vqwi VQWI_FROL(register Vdwi l)
{
#   define  VQWI_FROL(l) \
vreinterpretq_s32_u64(vdupq_lane_u64(vreinterpret_u64_s32(l), 0))
    return  VQWI_FROL(l);
}

INLINE Vqwf VQWF_FROL(register Vdwf l)
{
#   define  VQWF_FROL(l) \
vreinterpretq_f32_u64(vdupq_lane_u64(vreinterpret_u64_f32(l), 0))
    return  VQWF_FROL(l);
}


INLINE Vqdu VQDU_FROL(register Vddu l)
{
#   define  VQDU_FROL(l)    vdupq_lane_u64(l, 0)
    return  VQDU_FROL(l);
}

INLINE Vqdi VQDI_FROL(register Vddi l)
{
#   define  VQDI_FROL(l)    vdupq_lane_s64(l, 0)
    return  VQDI_FROL(l);
}

INLINE Vqdf VQDF_FROL(register Vddf l)
{
#   define  VQDF_FROL(l)    vdupq_lane_f64(l, 0)
    return  VQDF_FROL(l);
}


INLINE Vobu VOBU_FROL(register Vqbu l)
{
#define     VOBU_FROL(l)    (Vobu){.V0=l}
    return  VOBU_FROL(l);
}

INLINE Vobi VOBI_FROL(register Vqbi l)
{
#define     VOBI_FROL(l)    (Vobi){.V0=l}
    return  VOBI_FROL(l);
}


INLINE Vohu VOHU_FROL(register Vqhu l)
{
#define     VOHU_FROL(l)    (Vohu){.V0=l}
    return  VOHU_FROL(l);
}

INLINE Vohi VOHI_FROL(register Vqhi l)
{
#define     VOHI_FROL(l)    (Vohi){.V0=l}
    return  VOHI_FROL(l);
}


INLINE Vowu VOWU_FROL(register Vqwu l)
{
#define     VOWU_FROL(l)    (Vowu){.V0=l}
    return  VOWU_FROL(l);
}

INLINE Vowi VOWI_FROL(register Vqwi l)
{
#define     VOWI_FROL(l)    (Vowi){.V0=l}
    return  VOWI_FROL(l);
}

INLINE Vowf VOWF_FROL(register Vqwf l)
{
#define     VOWF_FROL(l)    (Vowf){.V0=l}
    return  VOWF_FROL(l);
}


INLINE Vodu VODU_FROL(register Vqdu l)
{
#define     VODU_FROL(l)    (Vodu){.V0=l}
    return  VODU_FROL(l);
}

INLINE Vodi VODI_FROL(register Vqdi l)
{
#define     VODI_FROL(l)    (Vodi){.V0=l}
    return  VODI_FROL(l);
}

INLINE Vodf VODF_FROL(register Vqdf l)
{
#define     VODF_FROL(l)    (Vodf){.V0=l}
    return  VODF_FROL(l);
}


INLINE Vsbu VSBU_FROL(register Vobu l)
{
#define     VSBU_FROL(l)    (Vsbu){.V0=(l).V0, .V1=(l).V1}
    return  VSBU_FROL(l);
}

INLINE Vsbi VSBI_FROL(register Vobi l)
{
#define     VSBI_FROL(l)    (Vsbi){.V0=(l).V0, .V1=(l).V1}
    return  VSBI_FROL(l);
}


INLINE Vshu VSHU_FROL(register Vohu l)
{
#define     VSHU_FROL(l)    (Vshu){.V0=(l).V0, .V1=(l).V1}
    return  VSHU_FROL(l);
}

INLINE Vshi VSHI_FROL(register Vohi l)
{
#define     VSHI_FROL(l)    (Vshi){.V0=(l).V0, .V1=(l).V1}
    return  VSHI_FROL(l);
}


INLINE Vswu VSWU_FROL(register Vowu l)
{
#define     VSWU_FROL(l)    (Vswu){.V0=(l).V0, .V1=(l).V1}
    return  VSWU_FROL(l);}

INLINE Vswi VSWI_FROL(register Vowi l)
{
#define     VSWI_FROL(l)    (Vswi){.V0=(l).V0, .V1=(l).V1}
    return  VSWI_FROL(l);
}

INLINE Vswf VSWF_FROL(register Vowf l)
{
#define     VSWF_FROL(l)    (Vswf){.V0=(l).V0, .V1=(l).V1}
    return  VSWF_FROL(l);
}


INLINE Vsdu VSDU_FROL(register Vodu l)
{
#define     VSDU_FROL(l)    (Vsdu){.V0=(l).V0, .V1=(l).V1}
    return  VSDU_FROL(l);
}

INLINE Vsdi VSDI_FROL(register Vodi l)
{
#define     VSDI_FROL(l)    (Vsdi){.V0=(l).V0, .V1=(l).V1}
    return  VSDI_FROL(l);
}

INLINE Vsdf VSDF_FROL(register Vodf l)
{
#define     VSDF_FROL(l)    (Vsdf){.V0=(l).V0, .V1=(l).V1}
    return  VSDF_FROL(l);
}


#endif

#endif // EOF