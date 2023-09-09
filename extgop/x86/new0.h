/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳

_new0 for x86 targets

*/

#ifndef MY_EXTGOP_INIT_H
#error "this file must not be explicitly included"
#endif

#ifndef MY_EXTGOP_X86_INIT_H // BOF
#define MY_EXTGOP_X86_INIT_H

#ifndef MY_EXTVEC_H

#else

INLINE Vdbu VDBU_NEW0() {return (Vdbu){0.0};}
INLINE Vdbi VDBI_NEW0() {return (Vdbi){0.0};}

INLINE Vdhu VDHU_NEW0() {return (Vdhu){0.0};}
INLINE Vdhi VDHI_NEW0() {return (Vdhi){0.0};}

INLINE Vdwu VDWU_NEW0() {return (Vdwu){0.0};}
INLINE Vdwi VDWI_NEW0() {return (Vdwi){0.0};}
INLINE Vdwf VDWF_NEW0() {return (Vdwf){0.0};}

INLINE Vddu VDDU_NEW0() {return (Vddu){0.0};}
INLINE Vddi VDDI_NEW0() {return (Vddi){0.0};}
INLINE Vddf VDDF_NEW0() {return (Vddf){0.0};}

#define     VDBU_NEW0() (Vdbu){0.0}
#define     VDBI_NEW0() (Vdbi){0.0}

#define     VDHU_NEW0() (Vdhu){0.0}
#define     VDHI_NEW0() (Vdhi){0.0}

#define     VDWU_NEW0() (Vdwu){0.0}
#define     VDWI_NEW0() (Vdwi){0.0}
#define     VDWF_NEW0() (Vdwf){0.0}

#define     VDDU_NEW0() (Vddu){0.0}
#define     VDDI_NEW0() (Vddi){0.0}
#define     VDDF_NEW0() (Vddf){0.0}

INLINE Vqbu VQBU_NEW0() {return (Vqbu){_mm_setzero_si128()};}
INLINE Vqbi VQBI_NEW0() {return (Vqbi){_mm_setzero_si128()};}

INLINE Vqhu VQHU_NEW0() {return (Vqhu){_mm_setzero_si128()};}
INLINE Vqhi VQHI_NEW0() {return (Vqhi){_mm_setzero_si128()};}

INLINE Vqwu VQWU_NEW0() {return (Vqwu){_mm_setzero_si128()};}
INLINE Vqwi VQWI_NEW0() {return (Vqwi){_mm_setzero_si128()};}
INLINE Vqwf VQWF_NEW0() {return (Vqwf){_mm_setzero_ps()};}

INLINE Vqdu VQDU_NEW0() {return (Vqdu){_mm_setzero_si128()};}
INLINE Vqdi VQDI_NEW0() {return (Vqdi){_mm_setzero_si128()};}
INLINE Vqdf VQDF_NEW0() {return (Vqdf){_mm_setzero_pd()};}


#define     VQBU_NEW0() (Vqbu){_mm_setzero_si128()}
#define     VQBI_NEW0() (Vqbi){_mm_setzero_si128()}

#define     VQHU_NEW0() (Vqhu){_mm_setzero_si128()}
#define     VQHI_NEW0() (Vqhi){_mm_setzero_si128()}

#define     VQWU_NEW0() (Vqwu){_mm_setzero_si128()}
#define     VQWI_NEW0() (Vqwi){_mm_setzero_si128()}
#define     VQWF_NEW0() (Vqwf){_mm_setzero_ps()}

#define     VQDU_NEW0() (Vqdu){_mm_setzero_si128()}
#define     VQDI_NEW0() (Vqdi){_mm_setzero_si128()}
#define     VQDF_NEW0() (Vqdf){_mm_setzero_pd()}


#if defined(SPC_X86_AVX512F)
#   define  MY_VO_ZEROS(F)  F()
#   define  MY_VOZ_ZEROS    MY_VO_ZEROS(_mm256_setzero_si256)
#   define  MY_VOWF_ZEROS   MY_VO_ZEROS(_mm256_setzero_ps)
#   define  MY_VODF_ZEROS   MY_VO_ZEROS(_mm256_setzero_pd)

#   define  MY_VS_ZEROS(F)  F()
#   define  MY_VSZ_ZEROS    MY_VS_ZEROS(_mm512_setzero_si512)
#   define  MY_VSWF_ZEROS   MY_VS_ZEROS(_mm512_setzero_ps)
#   define  MY_VSDF_ZEROS   MY_VS_ZEROS(_mm512_setzero_pd)
#else
#   define  MY_VO_ZEROS(F) .V0=F(), .V1=F()
#   define  MY_VOZ_ZEROS    MY_VO_ZEROS(_mm_setzero_si128)
#   define  MY_VOWF_ZEROS   MY_VO_ZEROS(_mm_setzero_ps)
#   define  MY_VODF_ZEROS   MY_VO_ZEROS(_mm_setzero_pd)

#   define  MY_VS_ZEROS(F) .V0=F(), .V1=F(), .V2=F(), .V3=F()
#   define  MY_VSZ_ZEROS    MY_VS_ZEROS(_mm_setzero_si128)
#   define  MY_VSWF_ZEROS   MY_VS_ZEROS(_mm_setzero_ps)
#   define  MY_VSDF_ZEROS   MY_VS_ZEROS(_mm_setzero_pd)
#   endif


INLINE Vobu VOBU_NEW0()
{
#define     VOBU_NEW0() (Vobu){MY_VOZ_ZEROS}
    return  VOBU_NEW0();
}

INLINE Vobi VOBI_NEW0()
{
#define     VOBI_NEW0() (Vobi){MY_VOZ_ZEROS}
    return  VOBI_NEW0();
}


INLINE Vohu VOHU_NEW0()
{
#define     VOHU_NEW0() (Vohu){MY_VOZ_ZEROS}
    return  VOHU_NEW0();
}

INLINE Vohi VOHI_NEW0()
{
#define     VOHI_NEW0() (Vohi){MY_VOZ_ZEROS}
    return  VOHI_NEW0();
}


INLINE Vowu VOWU_NEW0()
{
#define     VOWU_NEW0() (Vowu){MY_VOZ_ZEROS}
    return  VOWU_NEW0();
}

INLINE Vowi VOWI_NEW0()
{
#define     VOWI_NEW0() (Vowi){MY_VOZ_ZEROS}
    return  VOWI_NEW0();
}

INLINE Vowf VOWF_NEW0()
{
#define     VOWF_NEW0() (Vowf){MY_VOWF_ZEROS}
    return  VOWF_NEW0();
}


INLINE Vodu VODU_NEW0()
{
#define     VODU_NEW0() (Vodu){MY_VOZ_ZEROS}
    return  VODU_NEW0();
}

INLINE Vodi VODI_NEW0()
{
#define     VODI_NEW0() (Vodi){MY_VOZ_ZEROS}
    return  VODI_NEW0();
}


INLINE Vodf VODF_NEW0()
{
#define     VODF_NEW0() (Vodf){MY_VODF_ZEROS}
    return  VODF_NEW0();
}

INLINE Vsbu VSBU_NEW0()
{
#define     VSBU_NEW0() (Vsbu){MY_VSZ_ZEROS}
    return  VSBU_NEW0();
}

INLINE Vsbi VSBI_NEW0()
{
#define     VSBI_NEW0() (Vsbi){MY_VSZ_ZEROS}
    return  VSBI_NEW0();
}


INLINE Vshu VSHU_NEW0()
{
#define     VSHU_NEW0() (Vshu){MY_VSZ_ZEROS}
    return  VSHU_NEW0();
}

INLINE Vshi VSHI_NEW0()
{
#define     VSHI_NEW0() (Vshi){MY_VSZ_ZEROS}
    return  VSHI_NEW0();
}


INLINE Vswu VSWU_NEW0()
{
#define     VSWU_NEW0() (Vswu){MY_VSZ_ZEROS}
    return  VSWU_NEW0();
}

INLINE Vswi VSWI_NEW0()
{
#define     VSWI_NEW0() (Vswi){MY_VSZ_ZEROS}
    return  VSWI_NEW0();
}

INLINE Vswf VSWF_NEW0()
{
#define     VSWF_NEW0() (Vswf){MY_VSWF_ZEROS}
    return  VSWF_NEW0();
}


INLINE Vsdu VSDU_NEW0()
{
#define     VSDU_NEW0() (Vsdu){MY_VSZ_ZEROS}
    return  VSDU_NEW0();
}

INLINE Vsdi VSDI_NEW0()
{
#define     VSDI_NEW0() (Vsdi){MY_VSZ_ZEROS}
    return  VSDI_NEW0();
}

INLINE Vsdf VSDF_NEW0()
{
#define     VSDF_NEW0() (Vsdf){MY_VSDF_ZEROS}
    return  VSDF_NEW0();
}

#endif

#endif // EOF
