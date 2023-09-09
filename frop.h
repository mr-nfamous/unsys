/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

_frop for x86

*/

#ifndef MY_EXTGOP_X86_FROP_H // BOF
#define MY_EXTGOP_X86_FROP_H

#ifndef MY_EXTGOP_FROP_H
#error "extgop/x86/frop.h should only be included by extgop/frop.h"
#endif

#ifndef MY_EXTVEC_H

#else


INLINE Vqbu VQBU_FROP(register Vdbu l, register Vdbu r)
{
#   define  VQBU_FROP   VQBU_FROP
    return (Vqbu){_mm_castpd_si128(_mm_setr_pd(l.V0, r.V0))};
}

INLINE Vqbi VQBI_FROP(register Vdbi l, register Vdbi r)
{
#   define  VQBI_FROP   VQBI_FROP
    return (Vqbi){_mm_castpd_si128(_mm_setr_pd(l.V0, r.V0))};
}


INLINE Vqhu VQHU_FROP(register Vdhu l, register Vdhu r)
{
#   define  VQHU_FROP   VQHU_FROP
    return (Vqhu){_mm_castpd_si128(_mm_setr_pd(l.V0, r.V0))};
}

INLINE Vqhi VQHI_FROP(register Vdhi l, register Vdhi r)
{
#   define  VQHI_FROP   VQHI_FROP
    return (Vqhi){_mm_castpd_si128(_mm_setr_pd(l.V0, r.V0))};
}


INLINE Vqwu VQWU_FROP(register Vdwu l, register Vdwu r)
{
#   define  VQWU_FROP   VQWU_FROP
    return (Vqwu){_mm_castpd_si128(_mm_setr_pd(l.V0, r.V0))};
}

INLINE Vqwi VQWI_FROP(register Vdwi l, register Vdwi r)
{
#   define  VQWI_FROP   VQWI_FROP
    return (Vqwi){_mm_castpd_si128(_mm_setr_pd(l.V0, r.V0))};
}

INLINE Vqwf VQWF_FROP(register Vdwf l, register Vdwf r)
{
#   define  VQWF_FROP   VQWF_FROP
    return (Vqwf){_mm_castpd_ps(_mm_setr_pd(l.V0, r.V0))};
}


INLINE Vqdu VQDU_FROP(register Vddu l, register Vddu r)
{
#   define  VQDU_FROP   VQDU_FROP
    return (Vqdu){_mm_castpd_si128(_mm_setr_pd(l.V0, r.V0))};
}

INLINE Vqdi VQDI_FROP(register Vddi l, register Vddi r)
{
#   define  VQDI_FROP   VQDI_FROP
    return (Vqdi){_mm_castpd_si128(_mm_setr_pd(l.V0, r.V0))};
}

INLINE Vqdf VQDF_FROP(register Vddf l, register Vddf r)
{
#   define  VQDF_FROP   VQDF_FROP
    return (Vqdf){_mm_setr_pd(l.V0, r.V0)};
}

/*
o = {.Lo=l, .Hi=r}

    __m256i _mm256_set_m128i (__m128i r, __m128i l)
    __m256i _mm256_setr_m128i(__m128i l, __m128i r)
    __m256  _mm256_set_m128  (__m128  r, __m128  l)
    __m256  _mm256_setr_m128 (__m128  l, __m128  r)
    __m256d _mm256_set_m128d (__m128d r, __m128d l)
    __m256d _mm256_setr_m128d(__m128d l, __m128d r)
*/

INLINE Vobu VOBU_FROP(register Vqbu l, register Vqbu r)
{
#define     VOBU_FROP   VOBU_FROP
    return (Vobu)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm256_setr_m128i(l.V0, r.V0),
#else
        .V0=l.V0, .V1=r.V0,
#endif
    };
}

INLINE Vobi VOBI_FROP(register Vqbi l, register Vqbi r)
{
#define     VOBI_FROP   VOBI_FROP
    return (Vobi)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm256_setr_m128i(l.V0, r.V0),
#else
        .V0=l.V0, .V1=r.V0,
#endif
    };
}


INLINE Vohu VOHU_FROP(register Vqhu l, register Vqhu r)
{
#define     VOHU_FROP   VOHU_FROP
    return (Vohu)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm256_setr_m128i(l.V0, r.V0),
#else
        .V0=l.V0, .V1=r.V0,
#endif
    };
}

INLINE Vohi VOHI_FROP(register Vqhi l, register Vqhi r)
{
#define     VOHI_FROP   VOHI_FROP
    return (Vohi)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm256_setr_m128i(l.V0, r.V0),
#else
        .V0=l.V0, .V1=r.V0,
#endif
    };
}


INLINE Vowu VOWU_FROP(register Vqwu l, register Vqwu r)
{
#define     VOWU_FROP   VOWU_FROP
    return (Vowu)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm256_setr_m128i(l.V0, r.V0),
#else
        .V0=l.V0, .V1=r.V0,
#endif
    };
}

INLINE Vowi VOWI_FROP(register Vqwi l, register Vqwi r)
{
#define     VOWI_FROP   VOWI_FROP
    return (Vowi)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm256_setr_m128i(l.V0, r.V0),
#else
        .V0=l.V0, .V1=r.V0,
#endif
    };
}

INLINE Vowf VOWF_FROP(register Vqwf l, register Vqwf r)
{
#define     VOWF_FROP   VOWF_FROP
    return (Vowf)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm256_setr_m128(l.V0, r.V0),
#else
        .V0=l.V0, .V1=r.V0,
#endif
    };
}


INLINE Vodu VODU_FROP(register Vqdu l, register Vqdu r)
{
#define     VODU_FROP   VODU_FROP
    return (Vodu)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm256_setr_m128i(l.V0, r.V0),
#else
        .V0=l.V0, .V1=r.V0,
#endif
    };
}

INLINE Vodi VODI_FROP(register Vqdi l, register Vqdi r)
{
#define     VODI_FROP   VODI_FROP
    return (Vodi)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm256_setr_m128i(l.V0, r.V0),
#else
        .V0=l.V0, .V1=r.V0,
#endif
    };
}

INLINE Vodf VODF_FROP(register Vqdf l, register Vqdf r)
{
#define     VODF_FROP   VODF_FROP
    return (Vodf)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm256_setr_m128d(l.V0, r.V0),
#else
        .V0=l.V0, .V1=r.V0,
#endif
    };
}

INLINE Vsbu VSBU_FROP(register Vobu l, register Vobu r)
{
#define     VSBU_FROP   VSBU_FROP
    return (Vsbu)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm512_inserti64x4(
            _mm512_castsi256_si512(l.V0),
            r.V0,
            1
        ),
#else
        .V0=l.V0,   .V1=l.V1,
        .V2=r.V0,   .V3=r.V1,
#endif
    };
}

INLINE Vsbi VSBI_FROP(register Vobi l, register Vobi r)
{
#define     VSBI_FROP   VSBI_FROP
    return (Vsbi)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm512_inserti64x4(
            _mm512_castsi256_si512(l.V0),
            r.V0,
            1
        ),
#else
        .V0=l.V0,   .V1=l.V1,
        .V2=r.V0,   .V3=r.V1,
#endif
    };
}


INLINE Vshu VSHU_FROP(register Vohu l, register Vohu r)
{
#define     VSHU_FROP   VSHU_FROP
    return (Vshu)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm512_inserti64x4(
            _mm512_castsi256_si512(l.V0),
            r.V0,
            1
        ),
#else
        .V0=l.V0,   .V1=l.V1,
        .V2=r.V0,   .V3=r.V1,
#endif
    };
}

INLINE Vshi VSHI_FROP(register Vohi l, register Vohi r)
{
#define     VSHI_FROP   VSHI_FROP
    return (Vshi)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm512_inserti64x4(
            _mm512_castsi256_si512(l.V0),
            r.V0,
            1
        ),
#else
        .V0=l.V0,   .V1=l.V1,
        .V2=r.V0,   .V3=r.V1,
#endif
    };
}


INLINE Vswu VSWU_FROP(register Vowu l, register Vowu r)
{
#define     VSWU_FROP   VSWU_FROP
    return (Vswu)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm512_inserti64x4(
            _mm512_castsi256_si512(l.V0),
            r.V0,
            1
        ),
#else
        .V0=l.V0,   .V1=l.V1,
        .V2=r.V0,   .V3=r.V1,
#endif
    };
}

INLINE Vswi VSWI_FROP(register Vowi l, register Vowi r)
{
#define     VSWI_FROP   VSWI_FROP
    return (Vswi)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm512_inserti64x4(
            _mm512_castsi256_si512(l.V0),
            r.V0,
            1
        ),
#else
        .V0=l.V0,   .V1=l.V1,
        .V2=r.V0,   .V3=r.V1,
#endif
    };
}

INLINE Vswf VSWF_FROP(register Vowf l, register Vowf r)
{
#define     VSWF_FROP   VSWF_FROP
    return (Vswf)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm512_castsi512_ps(
            _mm512_inserti64x4(
                _mm512_castps_si512(_mm512_castps256_ps512(l.V0)),
                _mm256_castps_si256(r.V0),
                1
            )
        ),
#else
        .V0=l.V0,   .V1=l.V1,
        .V2=r.V0,   .V3=r.V1,
#endif
    };
}


INLINE Vsdu VSDU_FROP(register Vodu l, register Vodu r)
{
#define     VSDU_FROP   VSDU_FROP
    return (Vsdu)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm512_inserti64x4(
            _mm512_castsi256_si512(l.V0),
            r.V0,
            1
        ),
#else
        .V0=l.V0,   .V1=l.V1,
        .V2=r.V0,   .V3=r.V1,
#endif
    };
}

INLINE Vsdi VSDI_FROP(register Vodi l, register Vodi r)
{
#define     VSDI_FROP   VSDI_FROP
    return (Vsdi)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm512_inserti64x4(
            _mm512_castsi256_si512(l.V0),
            r.V0,
            1
        ),
#else
        .V0=l.V0,   .V1=l.V1,
        .V2=r.V0,   .V3=r.V1,
#endif
    };
}

INLINE Vsdf VSDF_FROP(register Vodf l, register Vodf r)
{
#define     VSDF_FROP   VSDF_FROP
    return (Vsdf)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm512_insertf64x4(
            _mm512_castpd256_pd512(l.V0), 
            r.V0, 
            1
        ),
#else
        .V0=l.V0,   .V1=l.V1,
        .V2=r.V0,   .V3=r.V1,
#endif
    };
}


#endif


#endif // EOF