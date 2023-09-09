/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

_fror for x86

*/

#ifndef MY_EXTGOP_X86_FROR_H // BOF
#define MY_EXTGOP_X86_FROR_H

#ifndef MY_EXTGOP_FROR_H
#error "extgop/x86/fror.h should only be included by extgop/fror.h"
#endif

#ifndef MY_EXTVEC_H

#else


INLINE Vqbu VQBU_FROR(register Vdbu r)
{
#define     VQBU_FROR   VQBU_FROR
    register __m128d m = _mm_set_sd(r.V0);
    return (Vqbu){_mm_castpd_si128(_mm_shuffle_pd(m, m, 1))};
}

INLINE Vqbi VQBI_FROR(register Vdbi r)
{
#define     VQBI_FROR   VQBI_FROR
    register __m128d m = _mm_set_sd(r.V0);
    return (Vqbi){_mm_castpd_si128(_mm_shuffle_pd(m, m, 1))};
}


INLINE Vqhu VQHU_FROR(register Vdhu r)
{
#define     VQHU_FROR   VQHU_FROR
    register __m128d m = _mm_set_sd(r.V0);
    return (Vqhu){_mm_castpd_si128(_mm_shuffle_pd(m, m, 1))};
}

INLINE Vqhi VQHI_FROR(register Vdhi r)
{
#define     VQHI_FROR   VQHI_FROR
    register __m128d m = _mm_set_sd(r.V0);
    return (Vqhi){_mm_castpd_si128(_mm_shuffle_pd(m, m, 1))};
}


INLINE Vqwu VQWU_FROR(register Vdwu r)
{
#define     VQWU_FROR   VQWU_FROR
    register __m128d m = _mm_set_sd(r.V0);
    return (Vqwu){_mm_castpd_si128(_mm_shuffle_pd(m, m, 1))};
}

INLINE Vqwi VQWI_FROR(register Vdwi r)
{
#define     VQWI_FROR   VQWI_FROR
    register __m128d m = _mm_set_sd(r.V0);
    return (Vqwi){_mm_castpd_si128(_mm_shuffle_pd(m, m, 1))};
}

INLINE Vqwf VQWF_FROR(register Vdwf r)
{
#define     VQWF_FROR   VQWF_FROR
    register __m128d m = _mm_set_sd(r.V0);
    return (Vqwf){_mm_castpd_ps(_mm_shuffle_pd(m, m, 1))};
}


INLINE Vqdu VQDU_FROR(register Vddu r)
{
#define     VQDU_FROR   VQDU_FROR
    register __m128d m = _mm_set_sd(r.V0);
    return (Vqdu){_mm_castpd_si128(_mm_shuffle_pd(m, m, 1))};
}

INLINE Vqdi VQDI_FROR(register Vddi r)
{
#define     VQDI_FROR   VQDI_FROR
    register __m128d m = _mm_set_sd(r.V0);
    return (Vqdi){_mm_castpd_si128(_mm_shuffle_pd(m, m, 1))};
}

INLINE Vqdf VQDF_FROR(register Vddf r)
{
#define     VQDF_FROR   VQDF_FROR
    register Vqdf m = {_mm_set_sd(r.V0)};
    m.V0 = _mm_shuffle_pd(m.V0, m.V0, 1);
    return m;
}


INLINE Vobu VOBU_FROR(register Vqbu r)
{
#define     VOBU_FROR VOBU_FROR
    return (Vobu)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm256_setr_m128i(_mm_undefined_si128(), r.V0),
#else
        .V0=_mm_undefined_si128(),
        .V1=r.V0,
#endif
    };
}

INLINE Vobi VOBI_FROR(register Vqbi r)
{
#define     VOBI_FROR VOBI_FROR
    return (Vobi)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm256_setr_m128i(_mm_undefined_si128(), r.V0),
#else
        .V0=_mm_undefined_si128(),
        .V1=r.V0,
#endif
    };
}


INLINE Vohu VOHU_FROR(register Vqhu r)
{
#define     VOHU_FROR VOHU_FROR
    return (Vohu)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm256_setr_m128i(_mm_undefined_si128(), r.V0),
#else
        .V0=_mm_undefined_si128(),
        .V1=r.V0,
#endif
    };
}

INLINE Vohi VOHI_FROR(register Vqhi r)
{
#define     VOHI_FROR VOHI_FROR
    return (Vohi)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm256_setr_m128i(_mm_undefined_si128(), r.V0),
#else
        .V0=_mm_undefined_si128(),
        .V1=r.V0,
#endif
    };
}


INLINE Vowu VOWU_FROR(register Vqwu r)
{
#define     VOWU_FROR VOWU_FROR
    return (Vowu)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm256_setr_m128i(_mm_undefined_si128(), r.V0),
#else
        .V0=_mm_undefined_si128(),
        .V1=r.V0,
#endif
    };
}

INLINE Vowi VOWI_FROR(register Vqwi r)
{
#define     VOWI_FROR VOWI_FROR
    return (Vowi)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm256_setr_m128i(_mm_undefined_si128(), r.V0),
#else
        .V0=_mm_undefined_si128(),
        .V1=r.V0,
#endif
    };
}

INLINE Vowf VOWF_FROR(register Vqwf r)
{
#define     VOWF_FROR VOWF_FROR
    return (Vowf)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm256_setr_m128(_mm_undefined_ps(), r.V0),
#else
        .V0=_mm_undefined_ps(),
        .V1=r.V0,
#endif
    };
}


INLINE Vodu VODU_FROR(register Vqdu r)
{
#define     VODU_FROR VODU_FROR
    return (Vodu)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm256_setr_m128i(_mm_undefined_si128(), r.V0),
#else
        .V0=_mm_undefined_si128(),
        .V1=r.V0,
#endif
    };
}

INLINE Vodi VODI_FROR(register Vqdi r)
{
#define     VODI_FROR VODI_FROR
    return (Vodi)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm256_setr_m128i(_mm_undefined_si128(), r.V0),
#else
        .V0=_mm_undefined_si128(),
        .V1=r.V0,
#endif
    };
}

INLINE Vodf VODF_FROR(register Vqdf r)
{
#define     VODF_FROR VODF_FROR
    return (Vodf)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm256_setr_m128d(_mm_undefined_pd(), r.V0),
#else
        .V0=_mm_undefined_pd(),
        .V1=r.V0,
#endif
    };
}


INLINE Vsbu VSBU_FROR(register Vobu r)
{
#define     VSBU_FROR   VSBU_FROR
    return (Vsbu)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm512_inserti64x4(
            _mm512_undefined_epi32(),
            r.V0,
            1
        ),
#else
        .V0=_mm_undefined_si128(),
        .V1=_mm_undefined_si128(),
        .V2=r.V0,
        .V3=r.V1,
#endif
    };
}

INLINE Vsbi VSBI_FROR(register Vobi r)
{
#define     VSBI_FROR   VSBI_FROR
    return (Vsbi)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm512_inserti64x4(
            _mm512_undefined_epi32(),
            r.V0,
            1
        ),
#else
        .V0=_mm_undefined_si128(),
        .V1=_mm_undefined_si128(),
        .V2=r.V0,
        .V3=r.V1,
#endif
    };
}


INLINE Vshu VSHU_FROR(register Vohu r)
{
#define     VSHU_FROR   VSHU_FROR
    return (Vshu)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm512_inserti64x4(
            _mm512_undefined_epi32(),
            r.V0,
            1
        ),
#else
        .V0=_mm_undefined_si128(),
        .V1=_mm_undefined_si128(),
        .V2=r.V0,
        .V3=r.V1,
#endif
    };
}

INLINE Vshi VSHI_FROR(register Vohi r)
{
#define     VSHI_FROR   VSHI_FROR
    return (Vshi)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm512_inserti64x4(
            _mm512_undefined_epi32(),
            r.V0,
            1
        ),
#else
        .V0=_mm_undefined_si128(),
        .V1=_mm_undefined_si128(),
        .V2=r.V0,
        .V3=r.V1,
#endif
    };
}


INLINE Vswu VSWU_FROR(register Vowu r)
{
#define     VSWU_FROR   VSWU_FROR
    return (Vswu)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm512_inserti64x4(
            _mm512_undefined_epi32(),
            r.V0,
            1
        ),
#else
        .V0=_mm_undefined_si128(),
        .V1=_mm_undefined_si128(),
        .V2=r.V0,
        .V3=r.V1,
#endif
    };
}

INLINE Vswi VSWI_FROR(register Vowi r)
{
#define     VSWI_FROR   VSWI_FROR
    return (Vswi)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm512_inserti64x4(
            _mm512_undefined_epi32(),
            r.V0,
            1
        ),
#else
        .V0=_mm_undefined_si128(),
        .V1=_mm_undefined_si128(),
        .V2=r.V0,
        .V3=r.V1,
#endif
    };
}

INLINE Vswf VSWF_FROR(register Vowf r)
{
#define     VSWF_FROR   VSWF_FROR
    return (Vswf)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm512_castsi512_ps(
            _mm512_inserti64x4(
                _mm512_undefined_epi32(),
                _mm256_castps_si256(r.V0),
                1
            )
        ),
#else
        .V0=_mm_undefined_ps(),
        .V1=_mm_undefined_ps(),
        .V2=r.V0,
        .V3=r.V1,
#endif
    };
}


INLINE Vsdu VSDU_FROR(register Vodu r)
{
#define     VSDU_FROR   VSDU_FROR
    return (Vsdu)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm512_inserti64x4(
            _mm512_undefined_epi32(),
            r.V0,
            1
        ),
#else
        .V0=_mm_undefined_si128(),
        .V1=_mm_undefined_si128(),
        .V2=r.V0,
        .V3=r.V1,
#endif
    };
}

INLINE Vsdi VSDI_FROR(register Vodi r)
{
#define     VSDI_FROR   VSDI_FROR
    return (Vsdi)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm512_inserti64x4(
            _mm512_undefined_epi32(),
            r.V0,
            1
        ),
#else
        .V0=_mm_undefined_si128(),
        .V1=_mm_undefined_si128(),
        .V2=r.V0,
        .V3=r.V1,
#endif
    };
}

INLINE Vsdf VSDF_FROR(register Vodf r)
{
#define     VSDF_FROR   VSDF_FROR
    return (Vsdf)
    {
#if defined(SPC_X86_AVX512F)
        .V0=_mm512_insertf64x4(_mm512_undefined_pd(),r.V0,1),
#else
        .V0=_mm_undefined_pd(),
        .V1=_mm_undefined_pd(),
        .V2=r.V0,
        .V3=r.V1,
#endif
    };
}



#endif


#endif // EOF
