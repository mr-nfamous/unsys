/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 
_new0 for arm
*/
#ifndef MY_EXTGOP_INIT_H
#error "extgop/arm/new0.h should be included by extgop/init.h"
#endif

#ifndef MY_EXTGOP_ARM_NEW0_H
#define MY_EXTGOP_ARM_NEW0_H

#ifndef MY_EXTVEC_H

#else

INLINE Vdbu VDBU_NEW0(void) {return vdup_n_u8(0);}
INLINE Vdbi VDBI_NEW0(void) {return vdup_n_s8(0);}

INLINE Vdhu VDHU_NEW0(void) {return vdup_n_u16(0);}
INLINE Vdhi VDHI_NEW0(void) {return vdup_n_s16(0);}
INLINE Vdhf VDHF_NEW0(void) {return vdup_n_f16(0);}

INLINE Vdwu VDWU_NEW0(void) {return vdup_n_u32(0);}
INLINE Vdwi VDWI_NEW0(void) {return vdup_n_s32(0);}
INLINE Vdwf VDWF_NEW0(void) {return vdup_n_f32(0);}

INLINE Vddu VDDU_NEW0(void) {return vdup_n_u64(0);}
INLINE Vddi VDDI_NEW0(void) {return vdup_n_s64(0);}
INLINE Vddf VDDF_NEW0(void) {return vdup_n_f64(0);}


INLINE Vqbu VQBU_NEW0(void) {return vdupq_n_u8(0);}
INLINE Vqbi VQBI_NEW0(void) {return vdupq_n_s8(0);}

INLINE Vqhu VQHU_NEW0(void) {return vdupq_n_u16(0);}
INLINE Vqhi VQHI_NEW0(void) {return vdupq_n_s16(0);}
INLINE Vqhf VQHF_NEW0(void) {return vdupq_n_f16(0);}

INLINE Vqwu VQWU_NEW0(void) {return vdupq_n_u32(0);}
INLINE Vqwi VQWI_NEW0(void) {return vdupq_n_s32(0);}
INLINE Vqwf VQWF_NEW0(void) {return vdupq_n_f32(0);}

INLINE Vqdu VQDU_NEW0(void) {return vdupq_n_u64(0);}
INLINE Vqdi VQDI_NEW0(void) {return vdupq_n_s64(0);}
INLINE Vqdf VQDF_NEW0(void) {return vdupq_n_f64(0);}

#define MY_VD_ZEROS(t) vdup_n_##t(0)
#define MY_VQ_ZEROS(t) vdupq_n_##t(0)
#define MY_VO_ZEROS(t) .V0=MY_VQ_ZEROS(t), .V1=MY_VQ_ZEROS(t)
#define MY_VS_ZEROS(t) MY_VO_ZEROS(t), .V2=MY_VQ_ZEROS(t), .V3=MY_VQ_ZEROS(t)   

INLINE Vobu VOBU_NEW0(void) 
{
#   define  VOBU_NEW0() (Vobu){MY_VO_ZEROS(u8)}
    return  VOBU_NEW0();
}

INLINE Vobi VOBI_NEW0(void) 
{
#   define  VOBI_NEW0() (Vobi){MY_VO_ZEROS(s8)}
    return  VOBI_NEW0();
}


INLINE Vohu VOHU_NEW0(void) 
{
#   define  VOHU_NEW0() (Vohu){MY_VO_ZEROS(u16)}
    return  VOHU_NEW0();
}

INLINE Vohi VOHI_NEW0(void) 
{
#   define  VOHI_NEW0() (Vohi){MY_VO_ZEROS(s16)}
    return  VOHI_NEW0();
}

INLINE Vowu VOWU_NEW0(void) 
{
#   define  VOWU_NEW0() (Vowu){MY_VO_ZEROS(u32)}
    return  VOWU_NEW0();
}

INLINE Vowi VOWI_NEW0(void) 
{
#   define  VOWI_NEW0() (Vowi){MY_VO_ZEROS(s32)}
    return  VOWI_NEW0();
}

INLINE Vowf VOWF_NEW0(void) 
{
#   define  VOWF_NEW0() (Vowf){MY_VO_ZEROS(f32)}
    return  VOWF_NEW0();
}

INLINE Vodu VODU_NEW0(void) 
{
#   define  VODU_NEW0() (Vodu){MY_VO_ZEROS(u64)}
    return  VODU_NEW0();
}

INLINE Vodi VODI_NEW0(void) 
{
#   define  VODI_NEW0() (Vodi){MY_VO_ZEROS(s64)}
    return  VODI_NEW0();
}

INLINE Vodf VODF_NEW0(void) 
{
#   define  VODF_NEW0() (Vodf){MY_VO_ZEROS(f64)}
    return  VODF_NEW0();
}
INLINE Vsbu VSBU_NEW0(void) 
{
#   define  VSBU_NEW0() (Vsbu){MY_VS_ZEROS(u8)}
    return  VSBU_NEW0();
}

INLINE Vsbi VSBI_NEW0(void) 
{
#   define  VSBI_NEW0() (Vsbi){MY_VS_ZEROS(s8)}
    return  VSBI_NEW0();
}


INLINE Vshu VSHU_NEW0(void) 
{
#   define  VSHU_NEW0() (Vshu){MY_VS_ZEROS(u16)}
    return  VSHU_NEW0();
}

INLINE Vshi VSHI_NEW0(void) 
{
#   define  VSHI_NEW0() (Vshi){MY_VS_ZEROS(s16)}
    return  VSHI_NEW0();
}

INLINE Vswu VSWU_NEW0(void) 
{
#   define  VSWU_NEW0() (Vswu){MY_VS_ZEROS(u32)}
    return  VSWU_NEW0();
}

INLINE Vswi VSWI_NEW0(void) 
{
#   define  VSWI_NEW0() (Vswi){MY_VS_ZEROS(s32)}
    return  VSWI_NEW0();
}

INLINE Vswf VSWF_NEW0(void) 
{
#   define  VSWF_NEW0() (Vswf){MY_VS_ZEROS(f32)}
    return  VSWF_NEW0();
}

INLINE Vsdu VSDU_NEW0(void) 
{
#   define  VSDU_NEW0() (Vsdu){MY_VS_ZEROS(u64)}
    return  VSDU_NEW0();
}

INLINE Vsdi VSDI_NEW0(void) 
{
#   define  VSDI_NEW0() (Vsdi){MY_VS_ZEROS(s64)}
    return  VSDI_NEW0();
}

INLINE Vsdf VSDF_NEW0(void) 
{
#   define  VSDF_NEW0() (Vsdf){MY_VS_ZEROS(f64)}
    return  VSDF_NEW0();
}


#undef F
#undef V
#endif

#endif // EOF