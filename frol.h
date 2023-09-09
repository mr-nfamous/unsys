/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

_frol for x86

*/

#ifndef MY_EXTGOP_X86_FROL_H // BOF
#define MY_EXTGOP_X86_FROL_H

#ifndef MY_EXTGOP_FROL_H
#error "extgop/x86/frol.h should only be included by extgop/frol.h"
#endif

#ifndef MY_EXTVEC_H

#else

INLINE Vqbu VQBU_FROL(register Vdbu l)
{
#   define  VQBU_FROL   VQBU_FROL
    return (Vqbu){_mm_castpd_si128(_mm_set_sd(l.V0))};
}

INLINE Vqbi VQBI_FROL(register Vdbi l)
{
#   define  VQBI_FROL   VQBI_FROL
    return (Vqbi){_mm_castpd_si128(_mm_set_sd(l.V0))};
}


INLINE Vqhu VQHU_FROL(register Vdhu l)
{
#   define  VQHU_FROL   VQHU_FROL
    return (Vqhu){_mm_castpd_si128(_mm_set_sd(l.V0))};
}

INLINE Vqhi VQHI_FROL(register Vdhi l)
{
#   define  VQHI_FROL   VQHI_FROL
    return (Vqhi){_mm_castpd_si128(_mm_set_sd(l.V0))};
}


INLINE Vqwu VQWU_FROL(register Vdwu l)
{
#   define  VQWU_FROL   VQWU_FROL
    return (Vqwu){_mm_castpd_si128(_mm_set_sd(l.V0))};
}

INLINE Vqwi VQWI_FROL(register Vdwi l)
{
#   define  VQWI_FROL   VQWI_FROL
    return (Vqwi){_mm_castpd_si128(_mm_set_sd(l.V0))};
}

INLINE Vqwf VQWF_FROL(register Vdwf l)
{
#   define  VQWF_FROL   VQWF_FROL
    return (Vqwf){_mm_castpd_ps(_mm_set_sd(l.V0))};
}


INLINE Vqdu VQDU_FROL(register Vddu l)
{
#   define  VQDU_FROL   VQDU_FROL
    return (Vqdu){_mm_castpd_si128(_mm_set_sd(l.V0))};

}

INLINE Vqdi VQDI_FROL(register Vddi l)
{
#   define  VQDI_FROL   VQDI_FROL
    return (Vqdi){_mm_castpd_si128(_mm_set_sd(l.V0))};
}

INLINE Vqdf VQDF_FROL(register Vddf l)
{
#   define  VQDF_FROL   VQDF_FROL
    return (Vqdf){_mm_set_sd(l.V0)};
}




INLINE Vobu VOBU_FROL(register Vqbu l)
{
#define     VOBU_FROL VOBU_FROL
    return (Vobu)
    {
#if defined(SPC_X86_AVX512F)
        .V0 = _mm256_castsi128_si256(l.V0),
#else
        .V0 = l.V0,
        .V1 = _mm_undefined_si128(),
#endif
    };
}

INLINE Vobi VOBI_FROL(register Vqbi l)
{
#define     VOBI_FROL VOBI_FROL
    return (Vobi)
    {
#if defined(SPC_X86_AVX512F)
        .V0 = _mm256_castsi128_si256(l.V0),
#else
        .V0 = l.V0,
        .V1 = _mm_undefined_si128(),
#endif
    };
}


INLINE Vohu VOHU_FROL(register Vqhu l)
{
#define     VOHU_FROL VOHU_FROL
    return (Vohu)
    {
#if defined(SPC_X86_AVX512F)
        .V0 = _mm256_castsi128_si256(l.V0),
#else
        .V0 = l.V0,
        .V1 = _mm_undefined_si128(),
#endif
    };
}

INLINE Vohi VOHI_FROL(register Vqhi l)
{
#define     VOHI_FROL VOHI_FROL
    return (Vohi)
    {
#if defined(SPC_X86_AVX512F)
        .V0 = _mm256_castsi128_si256(l.V0),
#else
        .V0 = l.V0,
        .V1 = _mm_undefined_si128(),
#endif
    };
}



INLINE Vowu VOWU_FROL(register Vqwu l)
{
#define     VOWU_FROL VOWU_FROL
    return (Vowu)
    {
#if defined(SPC_X86_AVX512F)
        .V0 = _mm256_castsi128_si256(l.V0),
#else
        .V0 = l.V0,
        .V1 = _mm_undefined_si128(),
#endif
    };
}

INLINE Vowi VOWI_FROL(register Vqwi l)
{
#define     VOWI_FROL VOWI_FROL
    return (Vowi)
    {
#if defined(SPC_X86_AVX512F)
        .V0 = _mm256_castsi128_si256(l.V0),
#else
        .V0 = l.V0,
        .V1 = _mm_undefined_si128(),
#endif
    };
}

INLINE Vowf VOWF_FROL(register Vqwf l)
{
#define     VOWF_FROL VOWF_FROL
    return (Vowf)
    {
#if defined(SPC_X86_AVX512F)
        .V0 = _mm256_castps128_ps256(l.V0),
#else
        .V0 = l.V0,
        .V1 = _mm_undefined_ps(),
#endif
    };
}


INLINE Vodu VODU_FROL(register Vqdu l)
{
#define     VODU_FROL VODU_FROL
    return (Vodu)
    {
#if defined(SPC_X86_AVX512F)
        .V0 = _mm256_castsi128_si256(l.V0),
#else
        .V0 = l.V0,
        .V1 = _mm_undefined_si128(),
#endif
    };
}

INLINE Vodi VODI_FROL(register Vqdi l)
{
#define     VODI_FROL VODI_FROL
    return (Vodi)
    {
#if defined(SPC_X86_AVX512F)
        .V0 = _mm256_castsi128_si256(l.V0),
#else
        .V0 = l.V0,
        .V1 = _mm_undefined_si128(),
#endif
    };
}

INLINE Vodf VODF_FROL(register Vqdf l)
{
#define     VODF_FROL VODF_FROL
    return (Vodf)
    {
#if defined(SPC_X86_AVX512F)
        .V0 = _mm256_castpd128_pd256(l.V0),
#else
        .V0 = l.V0,
        .V1 = _mm_undefined_pd(),
#endif
    };
}



INLINE Vsbu VSBU_FROL(register Vobu l)
{
#define     VSBU_FROL VSBU_FROL
    return (Vsbu)
    {
#if defined(SPC_X86_AVX512F)
        .V0 = _mm512_castsi256_si512(l.V0),
#else
        .V0 = l.V0,
        .V1 = l.V1,
        .V2 = _mm_undefined_si128(),
        .V3 = _mm_undefined_si128(),
#endif
    };
}

INLINE Vsbi VSBI_FROL(register Vobi l)
{
#define     VSBI_FROL VSBI_FROL
    return (Vsbi)
    {
#if defined(SPC_X86_AVX512F)
        .V0 = _mm512_castsi256_si512(l.V0),
#else
        .V0 = l.V0,
        .V1 = l.V1,
        .V2 = _mm_undefined_si128(),
        .V3 = _mm_undefined_si128(),
#endif
    };
}


INLINE Vshu VSHU_FROL(register Vohu l)
{
#define     VSHU_FROL VSHU_FROL
    return (Vshu)
    {
#if defined(SPC_X86_AVX512F)
        .V0 = _mm512_castsi256_si512(l.V0),
#else
        .V0 = l.V0,
        .V1 = l.V1,
        .V2 = _mm_undefined_si128(),
        .V3 = _mm_undefined_si128(),
#endif
    };
}

INLINE Vshi VSHI_FROL(register Vohi l)
{
#define     VSHI_FROL VSHI_FROL
    return (Vshi)
    {
#if defined(SPC_X86_AVX512F)
        .V0 = _mm512_castsi256_si512(l.V0),
#else
        .V0 = l.V0,
        .V1 = l.V1,
        .V2 = _mm_undefined_si128(),
        .V3 = _mm_undefined_si128(),
#endif
    };
}



INLINE Vswu VSWU_FROL(register Vowu l)
{
#define     VSWU_FROL VSWU_FROL
    return (Vswu)
    {
#if defined(SPC_X86_AVX512F)
        .V0 = _mm512_castsi256_si512(l.V0),
#else
        .V0 = l.V0,
        .V1 = l.V1,
        .V2 = _mm_undefined_si128(),
        .V3 = _mm_undefined_si128(),
#endif
    };
}

INLINE Vswi VSWI_FROL(register Vowi l)
{
#define     VSWI_FROL VSWI_FROL
    return (Vswi)
    {
#if defined(SPC_X86_AVX512F)
        .V0 = _mm512_castsi256_si512(l.V0),
#else
        .V0 = l.V0,
        .V1 = l.V1,
        .V2 = _mm_undefined_si128(),
        .V3 = _mm_undefined_si128(),
#endif
    };
}

INLINE Vswf VSWF_FROL(register Vowf l)
{
#define     VSWF_FROL VSWF_FROL
    return (Vswf)
    {
#if defined(SPC_X86_AVX512F)
        .V0 = _mm512_castps256_ps512(l.V0),
#else
        .V0 = l.V0,
        .V1 = l.V1,
        .V2 = _mm_undefined_ps(),
        .V3 = _mm_undefined_ps(),
#endif
    };
}


INLINE Vsdu VSDU_FROL(register Vodu l)
{
#define     VSDU_FROL VSDU_FROL
    return (Vsdu)
    {
#if defined(SPC_X86_AVX512F)
        .V0 = _mm512_castsi256_si512(l.V0),
#else
        .V0 = l.V0,
        .V1 = l.V1,
        .V2 = _mm_undefined_si128(),
        .V3 = _mm_undefined_si128(),
#endif
    };
}

INLINE Vsdi VSDI_FROL(register Vodi l)
{
#define     VSDI_FROL VSDI_FROL
    return (Vsdi)
    {
#if defined(SPC_X86_AVX512F)
        .V0 = _mm512_castsi256_si512(l.V0),
#else
        .V0 = l.V0,
        .V1 = l.V1,
        .V2 = _mm_undefined_si128(),
        .V3 = _mm_undefined_si128(),
#endif
    };
}

INLINE Vsdf VSDF_FROL(register Vodf l)
{
#define     VSDF_FROL VSDF_FROL
    return (Vsdf)
    {
#if defined(SPC_X86_AVX512F)
        .V0 = _mm512_castpd256_pd512(l.V0),
#else
        .V0 = l.V0,
        .V1 = l.V1,
        .V2 = _mm_undefined_pd(),
        .V3 = _mm_undefined_pd(),
#endif
    };
}




#endif
#endif // EOF