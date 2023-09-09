/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳
_new1 for x86
*/

#ifndef MY_EXTGOP_X86_NEW_H // BOF
#define MY_EXTGOP_X86_NEW_H

#ifndef MY_EXTVEC_H

#else

INLINE Vdbu VDBU_NEW1
(Bu x0, Bu x1, Bu x2, Bu x3, Bu x4, Bu x5, Bu x6, Bu x7)
{
#define     VDBU_NEW1(b0,b1,b2,b3,b4,b5,b6,b7)  \
(Vdbu)                      \
{                           \
    .V0=_mm_cvtsd_f64(      \
        _mm_castsi128_pd(   \
            _mm_set_epi8(   \
                0,0,0,0,    \
                0,0,0,0,    \
                (b7), (b6), \
                (b5), (b4), \
                (b3), (b2), \
                (b1), (b0)  \
            )               \
        )                   \
    ),                      \
}
    return VDBU_NEW1(x0,x1,x2,x3, x4,x5,x6,x7);
}

INLINE Vdbi VDBI_NEW1
(Bi x0, Bi x1, Bi x2, Bi x3, Bi x4, Bi x5, Bi x6, Bi x7)
{
#define     VDBI_NEW1(b0,b1,b2,b3,b4,b5,b6,b7)  \
(Vdbi)                      \
{                           \
    .V0=_mm_cvtsd_f64(      \
        _mm_castsi128_pd(   \
            _mm_set_epi8(   \
                0,0,0,0,    \
                0,0,0,0,    \
                (b7), (b6), \
                (b5), (b4), \
                (b3), (b2), \
                (b1), (b0)  \
            )               \
        )                   \
    ),                      \
}
    return VDBI_NEW1(x0,x1,x2,x3, x4,x5,x6,x7);
}


INLINE Vdhu VDHU_NEW1(Hu x0, Hu x1, Hu x2, Hu x3)
{
#define     VDHU_NEW1(h0,h1,h2,h3)  \
(Vdhu)                          \
{                           \
    .V0=_mm_cvtsd_f64(      \
        _mm_castsi128_pd(   \
            _mm_set_epi16(  \
                0, 0, 0, 0, \
                (h3),(h2),  \
                (h1),(h0)   \
            )           \
        )           \
    ),          \
}
    return  VDHU_NEW1(x0,x1, x2,x3);
}

INLINE Vdhi VDHI_NEW1(Hi x0, Hi x1, Hi x2, Hi x3)
{
#define     VDHI_NEW1(h0,h1,h2,h3)  \
(Vdhi)                          \
{                           \
    .V0=_mm_cvtsd_f64(      \
        _mm_castsi128_pd(   \
            _mm_set_epi16(  \
                0, 0, 0, 0, \
                (h3),(h2),  \
                (h1),(h0)   \
            )           \
        )           \
    ),          \
}
    return  VDHI_NEW1(x0,x1, x2,x3);
}


INLINE Vdwu VDWU_NEW1(Wu x0, Wu x1)
{
#define     VDWU_NEW1(w0, w1)   \
(Vdwu)                      \
{                           \
    _mm_cvtsd_f64(          \
        _mm_castsi128_pd(   \
            _mm_set_epi32(  \
                0, 0,       \
                (w1),(w0)   \
            )               \
        )               \
    )               \
}
    return VDWU_NEW1(x0, x1);
}

INLINE Vdwi VDWI_NEW1(Wi x0, Wi x1)
{
#define     VDWI_NEW1(w0, w1)   \
(Vdwi)                      \
{                           \
    _mm_cvtsd_f64(          \
        _mm_castsi128_pd(   \
            _mm_set_epi32(  \
                0, 0,       \
                (w1), (w0)  \
            )               \
        )               \
    )               \
}
    return VDWI_NEW1(x0, x1);
}

INLINE Vdwf VDWF_NEW1(Wf x0, Wf x1)
{
#define     VDWF_NEW1(w0, w1)   \
(Vdwf)                          \
{                               \
    _mm_cvtsd_f64(              \
        _mm_castps_pd(          \
            _mm_set_ps(         \
                0.f, 0.f,       \
                (w1), (w0)      \
            )                   \
        )                       \
    )                           \
}
    return VDWF_NEW1(x0, x1);
}


INLINE Vddu VDDU_NEW1(Du x0)
{
#   define  VDDU_NEW1(d0) (Vddu){.V0=UINT64_ASTF(d0)}
    return  VDDU_NEW1(x0);
}

INLINE Vddi VDDI_NEW1(Di x0)
{
#   define  VDDI_NEW1(d0) (Vddi){.V0=UINT64_ASTF(d0)}
    return  VDDI_NEW1(x0);
}

INLINE Vddf VDDF_NEW1(Df x0)
{
#   define  VDDF_NEW1(d0) (Vddf){.V0=x0}
    return  VDDF_NEW1(x0);
}



INLINE Vqbu VQBU_NEW1
(
    Bu x0, Bu x1, Bu x2, Bu x3, Bu x4, Bu x5, Bu x6, Bu x7,
    Bu x8, Bu x9, Bu xa, Bu xb, Bu xc, Bu xd, Bu xe, Bu xf
)
{
#define     VQBU_NEW1(          \
    b0,b1,b2,b3,b4,b5,b6,b7,    \
    b8,b9,ba,bb,bc,bd,be,bf     \
)                               \
(Vqbu)                          \
{                               \
    _mm_set_epi8(               \
        (bf), (be), (bd), (bc), \
        (ba), (ba), (b9), (b8), \
        (b7), (b6), (b5), (b4), \
        (b3), (b2), (b1), (b0)  \
    )                           \
}
    return  VQBU_NEW1(
        x0, x1, x2, x3, x4, x5, x6, x7,
        x8, x9, xa, xb, xc, xd, xe, xf
    );
}

INLINE Vqbi VQBI_NEW1
(
    Bi x0, Bi x1, Bi x2, Bi x3, Bi x4, Bi x5, Bi x6, Bi x7,
    Bi x8, Bi x9, Bi xa, Bi xb, Bi xc, Bi xd, Bi xe, Bi xf
)
{
#define     VQBI_NEW1(          \
    b0,b1,b2,b3,b4,b5,b6,b7,    \
    b8,b9,ba,bb,bc,bd,be,bf     \
)                               \
(Vqbi)                          \
{                               \
    _mm_set_epi8(               \
        (bf), (be), (bd), (bc), \
        (ba), (ba), (b9), (b8), \
        (b7), (b6), (b5), (b4), \
        (b3), (b2), (b1), (b0)  \
    )                           \
}
    return  VQBI_NEW1(
        x0, x1, x2, x3, x4, x5, x6, x7,
        x8, x9, xa, xb, xc, xd, xe, xf
    );
}


INLINE Vqhu VQHU_NEW1
(
    Hu x0, Hu x1, Hu x2, Hu x3, Hu x4, Hu x5, Hu x6, Hu x7
)
{
#define     VQHU_NEW1(              \
    h0,h1,h2,h3, h4,h5,h6,h7        \
)                                   \
(Vqhu)                              \
{                                   \
    _mm_set_epi16(                  \
        (h7), (h6), (h5), (h4),     \
        (h3), (h2), (h1), (h0)      \
    )                               \
}
    return  VQHU_NEW1(x0, x1, x2, x3, x4, x5, x6, x7);
}

INLINE Vqhi VQHI_NEW1
(
    Hu x0, Hu x1, Hu x2, Hu x3, Hu x4, Hu x5, Hu x6, Hu x7
)
{
#define     VQHI_NEW1(              \
    h0,h1,h2,h3, h4,h5,h6,h7        \
)                                   \
(Vqhi)                              \
{                                   \
    _mm_set_epi16(                  \
        (h7), (h6), (h5), (h4),     \
        (h3), (h2), (h1), (h0)      \
    )                               \
}
    return  VQHI_NEW1(x0, x1, x2, x3, x4, x5, x6, x7);
}


INLINE Vqwu VQWU_NEW1
(
    Wu x0, Wu x1, Wu x2, Wu x3
)
{
#define     VQWU_NEW1(w0,w1,w2,w3)  \
(Vqwu)                              \
{_mm_set_epi32((w3),(w2),(w1),(w0))}
    return  VQWU_NEW1(x0, x1, x2, x3);
}

INLINE Vqwi VQWI_NEW1
(
    Wi x0, Wi x1, Wi x2, Wi x3
)
{
#define     VQWI_NEW1(w0,w1,w2,w3)  \
(Vqwi)                              \
{_mm_set_epi32((w3),(w2),(w1),(w0))}
    return  VQWI_NEW1(x0, x1, x2, x3);
}

INLINE Vqwf VQWF_NEW1
(
    Wf x0, Wf x1, Wf x2, Wf x3
)
{
#define     VQWF_NEW1(w0,w1,w2,w3)  \
(Vqwf)                              \
{_mm_set_ps((w3),(w2),(w1),(w0))}
    return  VQWF_NEW1(x0, x1, x2, x3);
}


INLINE Vqdu VQDU_NEW1
(
    Du x0, Du x1
)
{
#define     VQDU_NEW1(d0, d1)   (Vqdu){_mm_set_epi64x((d0), (d1))}
    return  VQDU_NEW1(x0, x1);
}

INLINE Vqdi VQDI_NEW1
(
    Di x0, Di x1
)
{
#define     VQDI_NEW1(d0, d1)   (Vqdi){_mm_set_epi64x((d0), (d1))}
    return  VQDI_NEW1(x0, x1);
}

INLINE Vqdf VQDF_NEW1
(
    Df x0, Df x1
)
{
#define     VQDF_NEW1(d0, d1)   (Vqdf){_mm_set_pd((d0), (d1))}
    return  VQDF_NEW1(x0, x1);
}



INLINE Vobu VOBU_NEW1
(
    Bu x00, Bu x01, Bu x02, Bu x03,     
    Bu x04, Bu x05, Bu x06, Bu x07,
    Bu x08, Bu x09, Bu x0a, Bu x0b,   
    Bu x0c, Bu x0d, Bu x0e, Bu x0f,
    Bu x10, Bu x11, Bu x12, Bu x13, 
    Bu x14, Bu x15, Bu x16, Bu x17,
    Bu x18, Bu x19, Bu x1a, Bu x1b,
    Bu x1c, Bu x1d, Bu x1e, Bu x1f
)
{
#if defined(SPC_X86_AVX512F)

#   define  VOBU_NEW1(                  \
        b00,b01,b02,b03,b04,b05,b06,b07,\
        b08,b09,b0a,b0b,b0c,b0d,b0e,b0f,\
        b10,b11,b12,b13,b14,b15,b16,b17,\
        b18,b19,b1a,b1b,b1c,b1d,b1e,b1f \
)                                   \
(Vobu)                              \
{                                   \
    _mm256_set_epi8(                \
        (b1f), (b1e), (b1d), (b1c), \
        (b1b), (b1a), (b19), (b18), \
        (b17), (b16), (b15), (b14), \
        (b13), (b12), (b11), (b10), \
        (b0f), (b0e), (b0d), (b0c), \
        (b0b), (b0a), (b09), (b08), \
        (b07), (b06), (b05), (b04), \
        (b03), (b02), (b01), (b00)  \
    )   \
}

#else

#   define  VOBU_NEW1(                  \
        b00,b01,b02,b03,b04,b05,b06,b07,\
        b08,b09,b0a,b0b,b0c,b0d,b0e,b0f,\
        b10,b11,b12,b13,b14,b15,b16,b17,\
        b18,b19,b1a,b1b,b1c,b1d,b1e,b1f \
)                                   \
(Vobu)                              \
{                                   \
    .V0=_mm_set_epi8(               \
        (b0f), (b0e), (b0d), (b0c), \
        (b0b), (b0a), (b09), (b08), \
        (b07), (b06), (b05), (b04), \
        (b03), (b02), (b01), (b00)  \
    ),                              \
    .V1=_mm_set_epi8(               \
        (b1f), (b1e), (b1d), (b1c), \
        (b1b), (b1a), (b19), (b18), \
        (b17), (b16), (b15), (b14), \
        (b13), (b12), (b11), (b10)  \
    ),                              \
}

#endif

    return VOBU_NEW1(
        x00,x01,x02,x03,x04,x05,x06,x07,
        x08,x09,x0a,x0b,x0c,x0d,x0e,x0f,
        x10,x11,x12,x13,x14,x15,x16,x17,
        x18,x19,x1a,x1b,x1c,x1d,x1e,x1f
    );
}

INLINE Vobi VOBI_NEW1
(
    Bi x00, Bi x01, Bi x02, Bi x03,     
    Bi x04, Bi x05, Bi x06, Bi x07,
    Bi x08, Bi x09, Bi x0a, Bi x0b,   
    Bi x0c, Bi x0d, Bi x0e, Bi x0f,
    Bi x10, Bi x11, Bi x12, Bi x13, 
    Bi x14, Bi x15, Bi x16, Bi x17,
    Bi x18, Bi x19, Bi x1a, Bi x1b,
    Bi x1c, Bi x1d, Bi x1e, Bi x1f
)
{
#if defined(SPC_X86_AVX512F)

#   define  VOBI_NEW1(                  \
        b00,b01,b02,b03,b04,b05,b06,b07,\
        b08,b09,b0a,b0b,b0c,b0d,b0e,b0f,\
        b10,b11,b12,b13,b14,b15,b16,b17,\
        b18,b19,b1a,b1b,b1c,b1d,b1e,b1f \
)                                   \
(Vobi)                              \
{                                   \
    _mm256_set_epi8(                \
        (b1f), (b1e), (b1d), (b1c), \
        (b1b), (b1a), (b19), (b18), \
        (b17), (b16), (b15), (b14), \
        (b13), (b12), (b11), (b10), \
        (b0f), (b0e), (b0d), (b0c), \
        (b0b), (b0a), (b09), (b08), \
        (b07), (b06), (b05), (b04), \
        (b03), (b02), (b01), (b00)  \
    )   \
}

#else

#   define  VOBI_NEW1(                  \
        b00,b01,b02,b03,b04,b05,b06,b07,\
        b08,b09,b0a,b0b,b0c,b0d,b0e,b0f,\
        b10,b11,b12,b13,b14,b15,b16,b17,\
        b18,b19,b1a,b1b,b1c,b1d,b1e,b1f \
)                                   \
(Vobi)                              \
{                                   \
    .V0=_mm_set_epi8(               \
        (b0f), (b0e), (b0d), (b0c), \
        (b0b), (b0a), (b09), (b08), \
        (b07), (b06), (b05), (b04), \
        (b03), (b02), (b01), (b00)  \
    ),                              \
    .V1=_mm_set_epi8(               \
        (b1f), (b1e), (b1d), (b1c), \
        (b1b), (b1a), (b19), (b18), \
        (b17), (b16), (b15), (b14), \
        (b13), (b12), (b11), (b10)  \
    ),                              \
}

#endif

    return VOBI_NEW1(
        x00,x01,x02,x03,x04,x05,x06,x07,
        x08,x09,x0a,x0b,x0c,x0d,x0e,x0f,
        x10,x11,x12,x13,x14,x15,x16,x17,
        x18,x19,x1a,x1b,x1c,x1d,x1e,x1f
    );
}


INLINE Vohu VOHU_NEW1
(
    Hu x0, Hu x1, Hu x2, Hu x3,
    Hu x4, Hu x5, Hu x6, Hu x7,
    Hu x8, Hu x9, Hu xa, Hu xb,
    Hu xc, Hu xd, Hu xe, Hu xf
)
{
#if defined(SPC_X86_AVX512F)
#   define  VOHU_NEW1(          \
        h0,h1,h2,h3,h4,h5,h6,h7,\
        h8,h9,ha,hb,hc,hd,he,hf \
)                               \
(Vohu)                          \
{                               \
    _mm256_set_epi16(           \
        (hf), (he), (hd), (hc), \
        (hb), (ha), (h9), (h8), \
        (h7), (h6), (h5), (h4), \
        (h3), (h2), (h1), (h0)  \
    )   \
}

#else

#   define  VOHU_NEW1(          \
        h0,h1,h2,h3,h4,h5,h6,h7,\
        h8,h9,ha,hb,hc,hd,he,hf \
)                               \
(Vohu)                          \
{                               \
    .V0=_mm_set_epi16(          \
        (h7), (h6), (h5), (h4), \
        (h3), (h2), (h1), (h0)  \
    ),                          \
    .V1=_mm_set_epi16(          \
        (hf), (he), (hd), (hc), \
        (hb), (ha), (h9), (h8)  \
    ),\
}

#endif

    return VOHU_NEW1(
        x0,x1,x2,x3,x4,x5,x6,x7,
        x8,x9,xa,xb,xc,xd,xe,xf
    );
}

INLINE Vohi VOHI_NEW1
(
    Hi x0, Hi x1, Hi x2, Hi x3,
    Hi x4, Hi x5, Hi x6, Hi x7,
    Hi x8, Hi x9, Hi xa, Hi xb,
    Hi xc, Hi xd, Hi xe, Hi xf
)
{
#if defined(SPC_X86_AVX512F)

#   define  VOHI_NEW1(          \
        h0,h1,h2,h3,h4,h5,h6,h7,\
        h8,h9,ha,hb,hc,hd,he,hf \
)                               \
(Vohi)                          \
{                               \
    _mm256_set_epi16(           \
        (hf), (he), (hd), (hc), \
        (hb), (ha), (h9), (h8), \
        (h7), (h6), (h5), (h4), \
        (h3), (h2), (h1), (h0)  \
    )   \
}

#else

#   define  VOHI_NEW1(          \
        h0,h1,h2,h3,h4,h5,h6,h7,\
        h8,h9,ha,hb,hc,hd,he,hf \
)                               \
(Vohi)                          \
{                               \
    .V0=_mm_set_epi16(          \
        (h7), (h6), (h5), (h4), \
        (h3), (h2), (h1), (h0)  \
    ),                          \
    .V1=_mm_set_epi16(          \
        (hf), (he), (hd), (hc), \
        (hb), (ha), (h9), (h8)  \
    ),\
}

#endif

    return VOHI_NEW1(
        x0,x1,x2,x3,x4,x5,x6,x7,
        x8,x9,xa,xb,xc,xd,xe,xf
    );
}


INLINE Vowu VOWU_NEW1
(
    Wu x0, Wu x1, Wu x2, Wu x3,
    Wu x4, Wu x5, Wu x6, Wu x7
)
{
#if defined(SPC_X86_AVX512F)
#   define  VOWU_NEW1(w0,w1,w2,w3,w4,w5,w6,w7) \
(Vowu) \
{_mm256_set_epi32((w7),(w6),(w5),(w4),(w3),(w2),(w1),(w0))}

#else

#   define  VOWU_NEW1(w0,w1,w2,w3,w4,w5,w6,w7)  \
(Vowu)                                          \
{                                               \
    .V0=_mm_set_epi32((w3), (w2), (w1), (w0)),  \
    .V1=_mm_set_epi32((w7), (w6), (w5), (w4)),  \
}
#endif

    return VOWU_NEW1(x0,x1,x2,x3,x4,x5,x6,x7);
}

INLINE Vowi VOWI_NEW1
(
    Wi x0, Wi x1, Wi x2, Wi x3,
    Wi x4, Wi x5, Wi x6, Wi x7
)
{
#if defined(SPC_X86_AVX512F)
#   define  VOWI_NEW1(w0,w1,w2,w3,w4,w5,w6,w7) \
(Vowi) \
{_mm256_set_epi32((w7),(w6),(w5),(w4),(w3),(w2),(w1),(w0))}

#else

#   define  VOWI_NEW1(w0,w1,w2,w3,w4,w5,w6,w7)  \
(Vowi)                                          \
{                                               \
    .V0=_mm_set_epi32((w3), (w2), (w1), (w0)),  \
    .V1=_mm_set_epi32((w7), (w6), (w5), (w4)),  \
}
#endif

    return VOWI_NEW1(x0,x1,x2,x3,x4,x5,x6,x7);
}

INLINE Vowf VOWF_NEW1
(
    Wf x0, Wf x1, Wf x2, Wf x3,
    Wf x4, Wf x5, Wf x6, Wf x7
)
{
#if defined(SPC_X86_AVX512F)
#   define  VOWF_NEW1(w0,w1,w2,w3,w4,w5,w6,w7) \
(Vowf) \
{_mm256_set_ps((w7),(w6),(w5),(w4),(w3),(w2),(w1),(w0))}

#else

#   define  VOWF_NEW1(w0,w1,w2,w3,w4,w5,w6,w7)  \
(Vowf)                                          \
{                                               \
    .V0=_mm_set_ps((w3), (w2), (w1), (w0)),     \
    .V1=_mm_set_ps((w7), (w6), (w5), (w4)),     \
}
#endif

    return VOWF_NEW1(x0,x1,x2,x3,x4,x5,x6,x7);
}


INLINE Vodu VODU_NEW1
(
    Du x0, Du x1, Du x2, Du x3
)
{
#if defined(SPC_X86_AVX512F)
#   define  VODU_NEW1(d0, d1, d2, d3)   \
(Vodu)                                  \
{_mm256_set_epi64x((d3),(d2),(d1),(d0))}

#else
#   define  VODU_NEW1(d0, d1, d2, d3)   \
(Vodu)                                  \
{                                       \
    .V0=_mm_set_epi64x((d1), (d0)),     \
    .V1=_mm_set_epi64x((d3), (d2)),     \
}
#endif

    return VODU_NEW1(x0, x1, x2, x3);
}

INLINE Vodi VODI_NEW1
(
    Di x0, Di x1, Di x2, Di x3
)
{
#if defined(SPC_X86_AVX512F)
#   define  VODI_NEW1(d0, d1, d2, d3)   \
(Vodi)                                  \
{_mm256_set_epi64x((d3),(d2),(d1),(d0))}

#else
#   define  VODI_NEW1(d0, d1, d2, d3)   \
(Vodi)                                  \
{                                       \
    .V0=_mm_set_epi64x((d1), (d0)),     \
    .V1=_mm_set_epi64x((d3), (d2)),     \
}
#endif

    return VODI_NEW1(x0, x1, x2, x3);
}

INLINE Vodf VODF_NEW1
(
    Df x0, Df x1, Df x2, Df x3
)
{
#if defined(SPC_X86_AVX512F)
#   define  VODF_NEW1(d0, d1, d2, d3)   \
(Vodf)                                  \
{_mm256_set_pd((d3), (d2), (d1), (d0))}

#else
#   define  VODF_NEW1(d0, d1, d2, d3)   \
(Vodf)                                  \
{                                       \
    .V0=_mm_set_pd((d1), (d0)),         \
    .V1=_mm_set_pd((d3), (d2)),         \
}
#endif

    return VODF_NEW1(x0, x1, x2, x3);
}



INLINE Vsbu VSBU_NEW1
(
    Bu x00, Bu x01, Bu x02, Bu x03,     
    Bu x04, Bu x05, Bu x06, Bu x07,
    Bu x08, Bu x09, Bu x0a, Bu x0b,   
    Bu x0c, Bu x0d, Bu x0e, Bu x0f,
    Bu x10, Bu x11, Bu x12, Bu x13, 
    Bu x14, Bu x15, Bu x16, Bu x17,
    Bu x18, Bu x19, Bu x1a, Bu x1b,
    Bu x1c, Bu x1d, Bu x1e, Bu x1f,
    Bu x20, Bu x21, Bu x22, Bu x23,
    Bu x24, Bu x25, Bu x26, Bu x27,
    Bu x28, Bu x29, Bu x2a, Bu x2b,
    Bu x2c, Bu x2d, Bu x2e, Bu x2f,
    Bu x30, Bu x31, Bu x32, Bu x33,
    Bu x34, Bu x35, Bu x36, Bu x37,
    Bu x38, Bu x39, Bu x3a, Bu x3b,
    Bu x3c, Bu x3d, Bu x3e, Bu x3f 
)
{
#if defined(SPC_X86_AVX512F)
#   define  VSBU_NEW1(              \
    b00,b01,b02,b03,b04,b05,b06,b07,\
    b08,b09,b0a,b0b,b0c,b0d,b0e,b0f,\
    b10,b11,b12,b13,b14,b15,b16,b17,\
    b18,b19,b1a,b1b,b1c,b1d,b1e,b1f,\
    b20,b21,b22,b23,b24,b25,b26,b27,\
    b28,b29,b2a,b2b,b2c,b2d,b2e,b2f,\
    b30,b31,b32,b33,b34,b35,b36,b37,\
    b38,b39,b3a,b3b,b3c,b3d,b3e,b3f \
)                                   \
(Vsbu)                          \
{                           \
    _mm512_set_epi8(    \
        (b3f),(b3e),(b3d),(b3c),\
        (b3b),(b3a),(b39),(b38),\
        (b37),(b36),(b35),(b34),\
        (b33),(b32),(b31),(b30),\
        (b2f),(b2e),(b2d),(b2c),\
        (b2b),(b2a),(b29),(b28),\
        (b27),(b26),(b25),(b24),\
        (b23),(b22),(b21),(b20),\
        (b1f),(b1e),(b1d),(b1c),\
        (b1b),(b1a),(b19),(b18),\
        (b17),(b16),(b15),(b14),\
        (b13),(b12),(b11),(b10),\
        (b0f),(b0e),(b0d),(b0c),\
        (b0b),(b0a),(b09),(b08),\
        (b07),(b06),(b05),(b04),\
        (b03),(b02),(b01),(b00) \
    )   \
}

#else
#define     VSBU_NEW1(          \
    b00,b01,b02,b03,b04,b05,b06,b07,\
    b08,b09,b0a,b0b,b0c,b0d,b0e,b0f,\
    b10,b11,b12,b13,b14,b15,b16,b17,\
    b18,b19,b1a,b1b,b1c,b1d,b1e,b1f,\
    b20,b21,b22,b23,b24,b25,b26,b27,\
    b28,b29,b2a,b2b,b2c,b2d,b2e,b2f,\
    b30,b31,b32,b33,b34,b35,b36,b37,\
    b38,b39,b3a,b3b,b3c,b3d,b3e,b3f \
)                               \
(Vsbu)                          \
{                               \
    .V0=_mm_set_epi8(           \
        (b0f),(b0e),(b0d),(b0c),\
        (b0b),(b0a),(b09),(b08),\
        (b07),(b06),(b05),(b04),\
        (b03),(b02),(b01),(b00) \
    ),                          \
    .V1=_mm_set_epi8(           \
        (b1f),(b1e),(b1d),(b1c),\
        (b1b),(b1a),(b19),(b18),\
        (b17),(b16),(b15),(b14),\
        (b13),(b12),(b11),(b10) \
    ),                          \
    .V2=_mm_set_epi8(           \
        (b2f),(b2e),(b2d),(b2c),\
        (b2b),(b2a),(b29),(b28),\
        (b27),(b26),(b25),(b24),\
        (b23),(b22),(b21),(b20) \
    ),                          \
    .V3=_mm_set_epi8(           \
        (b3f),(b3e),(b3d),(b3c),\
        (b3b),(b3a),(b39),(b38),\
        (b37),(b36),(b35),(b34),\
        (b33),(b32),(b31),(b30) \
    )   \
}

#endif
    return VSBU_NEW1(
        x00,x01,x02,x03,x04,x05,x06,x07,
        x08,x09,x0a,x0b,x0c,x0d,x0e,x0f,
        x10,x11,x12,x13,x14,x15,x16,x17,
        x18,x19,x1a,x1b,x1c,x1d,x1e,x1f,
        x20,x21,x22,x23,x24,x25,x26,x27,
        x28,x29,x2a,x2b,x2c,x2d,x2e,x2f,
        x30,x31,x32,x33,x34,x35,x36,x37,
        x38,x39,x3a,x3b,x3c,x3d,x3e,x3f 
    );
}

INLINE Vsbi VSBI_NEW1
(
    Bi x00, Bi x01, Bi x02, Bi x03,     
    Bi x04, Bi x05, Bi x06, Bi x07,
    Bi x08, Bi x09, Bi x0a, Bi x0b,   
    Bi x0c, Bi x0d, Bi x0e, Bi x0f,
    Bi x10, Bi x11, Bi x12, Bi x13, 
    Bi x14, Bi x15, Bi x16, Bi x17,
    Bi x18, Bi x19, Bi x1a, Bi x1b,
    Bi x1c, Bi x1d, Bi x1e, Bi x1f,
    Bi x20, Bi x21, Bi x22, Bi x23,
    Bi x24, Bi x25, Bi x26, Bi x27,
    Bi x28, Bi x29, Bi x2a, Bi x2b,
    Bi x2c, Bi x2d, Bi x2e, Bi x2f,
    Bi x30, Bi x31, Bi x32, Bi x33,
    Bi x34, Bi x35, Bi x36, Bi x37,
    Bi x38, Bi x39, Bi x3a, Bi x3b,
    Bi x3c, Bi x3d, Bi x3e, Bi x3f 
)
{
#if defined(SPC_X86_AVX512F)
#   define  VSBI_NEW1(              \
    b00,b01,b02,b03,b04,b05,b06,b07,\
    b08,b09,b0a,b0b,b0c,b0d,b0e,b0f,\
    b10,b11,b12,b13,b14,b15,b16,b17,\
    b18,b19,b1a,b1b,b1c,b1d,b1e,b1f,\
    b20,b21,b22,b23,b24,b25,b26,b27,\
    b28,b29,b2a,b2b,b2c,b2d,b2e,b2f,\
    b30,b31,b32,b33,b34,b35,b36,b37,\
    b38,b39,b3a,b3b,b3c,b3d,b3e,b3f \
)                                   \
(Vsbi)                          \
{                           \
    _mm512_set_epi8(    \
        (b3f),(b3e),(b3d),(b3c),\
        (b3b),(b3a),(b39),(b38),\
        (b37),(b36),(b35),(b34),\
        (b33),(b32),(b31),(b30),\
        (b2f),(b2e),(b2d),(b2c),\
        (b2b),(b2a),(b29),(b28),\
        (b27),(b26),(b25),(b24),\
        (b23),(b22),(b21),(b20),\
        (b1f),(b1e),(b1d),(b1c),\
        (b1b),(b1a),(b19),(b18),\
        (b17),(b16),(b15),(b14),\
        (b13),(b12),(b11),(b10),\
        (b0f),(b0e),(b0d),(b0c),\
        (b0b),(b0a),(b09),(b08),\
        (b07),(b06),(b05),(b04),\
        (b03),(b02),(b01),(b00) \
    )   \
}

#else
#define     VSBI_NEW1(  \
    b00,b01,b02,b03,b04,b05,b06,b07,\
    b08,b09,b0a,b0b,b0c,b0d,b0e,b0f,\
    b10,b11,b12,b13,b14,b15,b16,b17,\
    b18,b19,b1a,b1b,b1c,b1d,b1e,b1f,\
    b20,b21,b22,b23,b24,b25,b26,b27,\
    b28,b29,b2a,b2b,b2c,b2d,b2e,b2f,\
    b30,b31,b32,b33,b34,b35,b36,b37,\
    b38,b39,b3a,b3b,b3c,b3d,b3e,b3f \
)                               \
(Vsbi)                          \
{                               \
    .V0=_mm_set_epi8(           \
        (b0f),(b0e),(b0d),(b0c),\
        (b0a),(b0a),(b09),(b08),\
        (b07),(b06),(b05),(b04),\
        (b03),(b02),(b01),(b00) \
    ),                          \
    .V1=_mm_set_epi8(           \
        (b1f),(b1e),(b1d),(b1c),\
        (b1b),(b1a),(b19),(b18),\
        (b17),(b16),(b15),(b14),\
        (b13),(b12),(b11),(b10) \
    ),                          \
    .V2=_mm_set_epi8(           \
        (b2f),(b2e),(b2d),(b2c),\
        (b2b),(b2a),(b29),(b28),\
        (b27),(b26),(b25),(b24),\
        (b23),(b22),(b21),(b20) \
    ),                          \
    .V3=_mm_set_epi8(           \
        (b3f),(b3e),(b3d),(b3c),\
        (b3b),(b3a),(b39),(b38),\
        (b37),(b36),(b35),(b34),\
        (b33),(b32),(b31),(b30) \
    )   \
}

#endif
    return VSBI_NEW1(
        x00,x01,x02,x03,x04,x05,x06,x07,
        x08,x09,x0a,x0b,x0c,x0d,x0e,x0f,
        x10,x11,x12,x13,x14,x15,x16,x17,
        x18,x19,x1a,x1b,x1c,x1d,x1e,x1f,
        x20,x21,x22,x23,x24,x25,x26,x27,
        x28,x29,x2a,x2b,x2c,x2d,x2e,x2f,
        x30,x31,x32,x33,x34,x35,x36,x37,
        x38,x39,x3a,x3b,x3c,x3d,x3e,x3f 
    );
}


INLINE Vshu VSHU_NEW1
(
    Hu x00, Hu x01, Hu x02, Hu x03,
    Hu x04, Hu x05, Hu x06, Hu x07,
    Hu x08, Hu x09, Hu x0a, Hu x0b,
    Hu x0c, Hu x0d, Hu x0e, Hu x0f,
    Hu x10, Hu x11, Hu x12, Hu x13,
    Hu x14, Hu x15, Hu x16, Hu x17,
    Hu x18, Hu x19, Hu x1a, Hu x1b,
    Hu x1c, Hu x1d, Hu x1e, Hu x1f
)
{
#if defined(SPC_X86_AVX512F)

#   define  VSHU_NEW1(                  \
        h00,h01,h02,h03,h04,h05,h06,h07,\
        h08,h09,h0a,h0b,h0c,h0d,h0e,h0f,\
        h10,h11,h12,h13,h14,h15,h16,h17,\
        h18,h19,h1a,h1b,h1c,h1d,h1e,h1f \
)                                       \
(Vshu)                                  \
{                                       \
    _mm512_set_epi16(                   \
        (h1f),(h1e),(h1d),(h1c),(h1b),(h1a),(h19),(h18),\
        (h17),(h16),(h15),(h14),(h13),(h12),(h11),(h10),\
        (h0f),(h0e),(h0d),(h0c),(h0b),(h0a),(h09),(h08),\
        (h07),(h06),(h05),(h04),(h03),(h02),(h01),(h00) \
    )   \
}

#else

#   define  VSHU_NEW1(                  \
        h00,h01,h02,h03,h04,h05,h06,h07,\
        h08,h09,h0a,h0b,h0c,h0d,h0e,h0f,\
        h10,h11,h12,h13,h14,h15,h16,h17,\
        h18,h19,h1a,h1b,h1c,h1d,h1e,h1f \
)                                       \
(Vshu)                                  \
{                                       \
    .V0=_mm_set_epi16((h07),(h06),(h05),(h04),(h03),(h02),(h01),(h00)),\
    .V1=_mm_set_epi16((h0f),(h0e),(h0d),(h0c),(h0b),(h0a),(h09),(h08)),\
    .V2=_mm_set_epi16((h17),(h16),(h15),(h14),(h13),(h12),(h11),(h10)),\
    .V3=_mm_set_epi16((h1f),(h1e),(h1d),(h1c),(h1b),(h1a),(h19),(h18)),\
}

#endif

    return VSHU_NEW1(
        x00,x01,x02,x03,x04,x05,x06,x07,
        x08,x09,x0a,x0b,x0c,x0d,x0e,x0f,
        x10,x11,x12,x13,x14,x15,x16,x17,
        x18,x19,x1a,x1b,x1c,x1d,x1e,x1f
    );
}

INLINE Vshi VSHI_NEW1
(
    Hi x00, Hi x01, Hi x02, Hi x03,
    Hi x04, Hi x05, Hi x06, Hi x07,
    Hi x08, Hi x09, Hi x0a, Hi x0b,
    Hi x0c, Hi x0d, Hi x0e, Hi x0f,
    Hi x10, Hi x11, Hi x12, Hi x13,
    Hi x14, Hi x15, Hi x16, Hi x17,
    Hi x18, Hi x19, Hi x1a, Hi x1b,
    Hi x1c, Hi x1d, Hi x1e, Hi x1f
)
{
#if defined(SPC_X86_AVX512F)

#   define  VSHI_NEW1(                  \
        h00,h01,h02,h03,h04,h05,h06,h07,\
        h08,h09,h0a,h0b,h0c,h0d,h0e,h0f,\
        h10,h11,h12,h13,h14,h15,h16,h17,\
        h18,h19,h1a,h1b,h1c,h1d,h1e,h1f \
)                                       \
(Vshi)                                  \
{                                       \
    _mm512_set_epi16(                   \
        (h1f),(h1e),(h1d),(h1c),(h1b),(h1a),(h19),(h18),\
        (h17),(h16),(h15),(h14),(h13),(h12),(h11),(h10),\
        (h0f),(h0e),(h0d),(h0c),(h0b),(h0a),(h09),(h08),\
        (h07),(h06),(h05),(h04),(h03),(h02),(h01),(h00) \
    )   \
}

#else

#   define  VSHI_NEW1(                  \
        h00,h01,h02,h03,h04,h05,h06,h07,\
        h08,h09,h0a,h0b,h0c,h0d,h0e,h0f,\
        h10,h11,h12,h13,h14,h15,h16,h17,\
        h18,h19,h1a,h1b,h1c,h1d,h1e,h1f \
)                                       \
(Vshi)                                  \
{                                       \
    .V0=_mm_set_epi16((h07),(h06),(h05),(h04),(h03),(h02),(h01),(h00)),\
    .V1=_mm_set_epi16((h0f),(h0e),(h0d),(h0c),(h0b),(h0a),(h09),(h08)),\
    .V2=_mm_set_epi16((h17),(h16),(h15),(h14),(h13),(h12),(h11),(h10)),\
    .V3=_mm_set_epi16((h1f),(h1e),(h1d),(h1c),(h1b),(h1a),(h19),(h18)),\
}

#endif

    return VSHI_NEW1(
        x00,x01,x02,x03,x04,x05,x06,x07,
        x08,x09,x0a,x0b,x0c,x0d,x0e,x0f,
        x10,x11,x12,x13,x14,x15,x16,x17,
        x18,x19,x1a,x1b,x1c,x1d,x1e,x1f
    );
}


INLINE Vswu VSWU_NEW1
(
    Wu x0, Wu x1, Wu x2, Wu x3,
    Wu x4, Wu x5, Wu x6, Wu x7,
    Wu x8, Wu x9, Wu xa, Wu xb,
    Wu xc, Wu xd, Wu xe, Wu xf
)
{
#if defined(SPC_X86_AVX512F)
#   define  VSWU_NEW1(                  \
        w0,w1,w2,w3,w4,w5,w6,w7,        \
        w8,w9,wa,wb,wc,wd,we,wf         \
)                                       \
(Vswu)                                  \
{                                       \
    _mm512_set_epi32(                   \
        (wf),(we),(wd),(wc),(wb),(wa),(w9),(w8),\
        (w7),(w6),(w5),(w4),(w3),(w2),(w1),(w0) \
    )   \
}

#else

#   define  VSWU_NEW1(                      \
        w0,w1,w2,w3,w4,w5,w6,w7,            \
        w8,w9,wa,wb,wc,wd,we,wf             \
)                                           \
(Vswu)                                      \
{                                           \
    .V0=_mm_set_epi32((w3),(w2),(w1),(w0)), \
    .V1=_mm_set_epi32((w7),(w6),(w5),(w4)), \
    .V2=_mm_set_epi32((wb),(wa),(w9),(w8)), \
    .V3=_mm_set_epi32((wf),(we),(wd),(wc)), \
}
#endif

    return VSWU_NEW1(x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,xa,xb,xc,xd,xe,xf);
}

INLINE Vswi VSWI_NEW1
(
    Wi x0, Wi x1, Wi x2, Wi x3,
    Wi x4, Wi x5, Wi x6, Wi x7,
    Wi x8, Wi x9, Wi xa, Wi xb,
    Wi xc, Wi xd, Wi xe, Wi xf
)
{
#if defined(SPC_X86_AVX512F)
#   define  VSWI_NEW1(                  \
        w0,w1,w2,w3,w4,w5,w6,w7,        \
        w8,w9,wa,wb,wc,wd,we,wf         \
)                                       \
(Vswi)                                  \
{                                       \
    _mm512_set_epi32(                   \
        (wf),(we),(wd),(wc),(wb),(wa),(w9),(w8),\
        (w7),(w6),(w5),(w4),(w3),(w2),(w1),(w0) \
    )   \
}

#else

#   define  VSWI_NEW1(                      \
        w0,w1,w2,w3,w4,w5,w6,w7,            \
        w8,w9,wa,wb,wc,wd,we,wf             \
)                                           \
(Vswi)                                      \
{                                           \
    .V0=_mm_set_epi32((w3),(w2),(w1),(w0)), \
    .V1=_mm_set_epi32((w7),(w6),(w5),(w4)), \
    .V2=_mm_set_epi32((wb),(wa),(w9),(w8)), \
    .V3=_mm_set_epi32((wf),(we),(wd),(wc)), \
}
#endif

    return VSWI_NEW1(x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,xa,xb,xc,xd,xe,xf);
}

INLINE Vswf VSWF_NEW1
(
    Wf x0, Wf x1, Wf x2, Wf x3,
    Wf x4, Wf x5, Wf x6, Wf x7,
    Wf x8, Wf x9, Wf xa, Wf xb,
    Wf xc, Wf xd, Wf xe, Wf xf
)
{
#if defined(SPC_X86_AVX512F)
#   define  VSWF_NEW1(          \
        w0,w1,w2,w3,w4,w5,w6,w7,\
        w8,w9,wa,wb,wc,wd,we,wf \
)                               \
(Vswf)                          \
{                               \
    _mm512_set_ps(              \
        (wf), (we), (wd), (wc), \
        (wb), (wa), (w9), (w8), \
        (w7), (w6), (w5), (w4), \
        (w3), (w2), (w1), (w0)  \
    )   \
}

#else

#   define  VSWF_NEW1(                      \
        w0,w1,w2,w3,w4,w5,w6,w7,            \
        w8,w9,wa,wb,wc,wd,we,wf             \
)                                           \
(Vswf)                                      \
{                                           \
    .V0=_mm_set_ps((w3), (w2), (w1), (w0)), \
    .V1=_mm_set_ps((w7), (w6), (w5), (w4)), \
    .V2=_mm_set_ps((wb), (wa), (w9), (w8)), \
    .V3=_mm_set_ps((wf), (we), (wd), (wc)), \
}
#endif

    return VSWF_NEW1(x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,xa,xb,xc,xd,xe,xf);
}


INLINE Vsdu VSDU_NEW1
(
    Du x0, Du x1, Du x2, Du x3,
    Du x4, Du x5, Du x6, Du x7
)
{
#if defined(SPC_X86_AVX512F)
#   define  VSDU_NEW1(d0,d1,d2,d3,d4,d5,d6,d7)  \
(Vsdu)                          \
{                               \
    _mm512_set_epi64(           \
        (d7),(d6),(d5),(d4),    \
        (d3),(d2),(d1),(d0)     \
    )   \
}

#else

#   define  VSDU_NEW1(              \
        d0,d1,d2,d3,d4,d5,d6,d7     \
)                                   \
(Vsdu)                              \
{                                   \
    .V0=_mm_set_epi64x((d1),(d0)),   \
    .V1=_mm_set_epi64x((d3),(d2)),   \
    .V2=_mm_set_epi64x((d5),(d4)),   \
    .V3=_mm_set_epi64x((d7),(d6)),   \
}
#endif

    return VSDU_NEW1(x0,x1,x2,x3,x4,x5,x6,x7);
}

INLINE Vsdi VSDI_NEW1
(
    Di x0, Di x1, Di x2, Di x3,
    Di x4, Di x5, Di x6, Di x7
)
{
#if defined(SPC_X86_AVX512F)
#   define  VSDI_NEW1(d0,d1,d2,d3,d4,d5,d6,d7)  \
(Vsdi)                          \
{                               \
    _mm512_set_epi64(           \
        (d7),(d6),(d5),(d4),    \
        (d3),(d2),(d1),(d0)     \
    )   \
}

#else

#   define  VSDI_NEW1(              \
        d0,d1,d2,d3,d4,d5,d6,d7     \
)                                   \
(Vsdi)                              \
{                                   \
    .V0=_mm_set_epi64x((d1),(d0)),  \
    .V1=_mm_set_epi64x((d3),(d2)),  \
    .V2=_mm_set_epi64x((d5),(d4)),  \
    .V3=_mm_set_epi64x((d7),(d6)),  \
}
#endif

    return VSDI_NEW1(x0,x1,x2,x3,x4,x5,x6,x7);
}

INLINE Vsdf VSDF_NEW1
(
    Df x0, Df x1, Df x2, Df x3,
    Df x4, Df x5, Df x6, Df x7
)
{
#if defined(SPC_X86_AVX512F)
#   define  VSDF_NEW1(d0,d1,d2,d3,d4,d5,d6,d7)  \
(Vsdf)                          \
{                               \
    _mm512_set_pd(              \
        (d7), (d6), (d5), (d4), \
        (d3), (d2), (d1), (d0)  \
    )   \
}

#else

#   define  VSDF_NEW1(          \
        d0,d1,d2,d3,d4,d5,d6,d7 \
)                               \
(Vsdf)                          \
{                               \
    .V0=_mm_set_pd((d1), (d0)), \
    .V1=_mm_set_pd((d3), (d2)), \
    .V2=_mm_set_pd((d5), (d4)), \
    .V3=_mm_set_pd((d7), (d6)), \
}
#endif

    return VSDF_NEW1(x0,x1,x2,x3,x4,x5,x6,x7);
}

#endif // EOF
