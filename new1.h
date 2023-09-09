/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳
_new1 for arm targets

*/
#ifndef MY_EXTGOP_ARM_NEW1_H // BOF
#define MY_EXTGOP_ARM_NEW1_H

#ifndef MY_EXTVEC_H

#else

INLINE Vdbu VDBU_NEW1
(
    Bu x00, Bu x01, Bu x02, Bu x03,
    Bu x04, Bu x05, Bu x06, Bu x07
)
{
    register Vdbu a;
    a[0x0]=x00, a[0x1]=x01, a[0x2]=x02, a[0x3]=x03,
    a[0x4]=x04, a[0x5]=x05, a[0x6]=x06, a[0x7]=x07;
    return a;
}

INLINE Vdbi VDBI_NEW1
(
    Bi x00, Bi x01, Bi x02, Bi x03,
    Bi x04, Bi x05, Bi x06, Bi x07
)
{
    register Vdbi a;
    a[0x0]=x00, a[0x1]=x01, a[0x2]=x02, a[0x3]=x03,
    a[0x4]=x04, a[0x5]=x05, a[0x6]=x06, a[0x7]=x07;
    return a;
}


INLINE Vdhu VDHU_NEW1(Hu x0, Hu x1, Hu x2, Hu x3)
{
    register Vdhu a;
    a[0x0]=x0, a[0x1]=x1, a[0x2]=x2, a[0x3]=x3;
    return a;
}

INLINE Vdhi VDHI_NEW1(Hi x0, Hi x1, Hi x2, Hi x3)
{
    register Vdhi a;
    a[0x0]=x0, a[0x1]=x1, a[0x2]=x2, a[0x3]=x3;
    return  a;
}


INLINE Vdwu VDWU_NEW1(Wu x0, Wu x1)
{
    register Vdwu a;
    a[0x0]=x0, a[0x1]=x1;
    return  a;
}

INLINE Vdwi VDWI_NEW1(Wi x0, Wi x1)
{
    register Vdwi a;
    a[0x0]=x0, a[0x1]=x1;
    return  a;
}

INLINE Vdwf VDWF_NEW1(Wf x0, Wf x1)
{
    register Vdwf a;
    a[0x0]=x0, a[0x1]=x1;
    return  a;
}


INLINE Vddu VDDU_NEW1(Du x0) {return vdup_n_u64(x0);}
INLINE Vddi VDDI_NEW1(Di x0) {return vdup_n_s64(x0);}
INLINE Vddf VDDF_NEW1(Df x0) {return vdup_n_f64(x0);}

#define     VDBU_NEW1   VDBU_NEW1
#define     VDBI_NEW1   VDBI_NEW1

#define     VDHU_NEW1   VDHU_NEW1
#define     VDHI_NEW1   VDHI_NEW1

#define     VDWU_NEW1   VDWU_NEW1
#define     VDWI_NEW1   VDWI_NEW1
#define     VDWF_NEW1   VDWF_NEW1

#define     VDDU_NEW1   vdup_n_u64
#define     VDDI_NEW1   vdup_n_s64
#define     VDDF_NEW1   vdup_n_f64


INLINE Vqbu VQBU_NEW1
(
    Bu x0, Bu x1, Bu x2, Bu x3, Bu x4, Bu x5, Bu x6, Bu x7,
    Bu x8, Bu x9, Bu xa, Bu xb, Bu xc, Bu xd, Bu xe, Bu xf
)
{
    register Vqbu a;
    a[0x0]=x0, a[0x1]=x1, a[0x2]=x2, a[0x3]=x3,
    a[0x4]=x4, a[0x5]=x5, a[0x6]=x6, a[0x7]=x7,
    a[0x8]=x8, a[0x9]=x9, a[0xa]=xa, a[0xb]=xb,
    a[0xc]=xc, a[0xd]=xd, a[0xe]=xe, a[0xf]=xf;
    return a;
}

INLINE Vqbi VQBI_NEW1
(
    Bi x0, Bi x1, Bi x2, Bi x3, Bi x4, Bi x5, Bi x6, Bi x7,
    Bi x8, Bi x9, Bi xa, Bi xb, Bi xc, Bi xd, Bi xe, Bi xf
)
{
    register Vqbi a;
    a[0x0]=x0, a[0x1]=x1, a[0x2]=x2, a[0x3]=x3,
    a[0x4]=x4, a[0x5]=x5, a[0x6]=x6, a[0x7]=x7,
    a[0x8]=x8, a[0x9]=x9, a[0xa]=xa, a[0xb]=xb,
    a[0xc]=xc, a[0xd]=xd, a[0xe]=xe, a[0xf]=xf;
    return a;
}


INLINE Vqhu VQHU_NEW1
(
    Hu x0, Hu x1, Hu x2, Hu x3, Hu x4, Hu x5, Hu x6, Hu x7
)
{
    register Vqhu a;
    a[0x0]=x0, a[0x1]=x1, a[0x2]=x2, a[0x3]=x3,
    a[0x4]=x4, a[0x5]=x5, a[0x6]=x6, a[0x7]=x7;
    return a;
}

INLINE Vqhi VQHI_NEW1
(
    Hi x0, Hi x1, Hi x2, Hi x3, 
    Hi x4, Hi x5, Hi x6, Hi x7
)
{
    register Vqhi a;
    a[0x0]=x0, a[0x1]=x1, a[0x2]=x2, a[0x3]=x3,
    a[0x4]=x4, a[0x5]=x5, a[0x6]=x6, a[0x7]=x7;
    return a;
}


INLINE Vqwu VQWU_NEW1(Wu x0, Wu x1, Wu x2, Wu x3)
{
    register Vqwu a;
    a[0x0]=x0, a[0x1]=x1, a[0x2]=x2, a[0x3]=x3;
    return a;
}

INLINE Vqwi VQWI_NEW1(Wi x0, Wi x1, Wi x2, Wi x3)
{
    register Vqwi a;
    a[0x0]=x0, a[0x1]=x1, a[0x2]=x2, a[0x3]=x3;
    return a;
}

INLINE Vqwf VQWF_NEW1(Wf x0, Wf x1, Wf x2, Wf x3)
{
    register Vqwf a;
    a[0x0]=x0, a[0x1]=x1, a[0x2]=x2, a[0x3]=x3;
    return a;
}


INLINE Vqdu VQDU_NEW1(Du x0, Du x1)
{
    register Vqdu a;
    a[0x0]=x0, a[0x1]=x1;
    return a;
}

INLINE Vqdi VQDI_NEW1(Di x0, Di x1)
{
    register Vqdi a;
    a[0x0]=x0, a[0x1]=x1;
    return a;
}

INLINE Vqdf VQDF_NEW1(Df x0, Df x1)
{
    register Vqdf a;
    a[0x0]=x0, a[0x1]=x1;
    return a;
}

#define     VQBU_NEW1   VQBU_NEW1
#define     VQBI_NEW1   VQBI_NEW1

#define     VQHU_NEW1   VQHU_NEW1
#define     VQHI_NEW1   VQHI_NEW1

#define     VQWU_NEW1   VQWU_NEW1
#define     VQWI_NEW1   VQWI_NEW1
#define     VQWF_NEW1   VQWF_NEW1

#define     VQDU_NEW1   VQDU_NEW1
#define     VQDI_NEW1   VQDI_NEW1
#define     VQDF_NEW1   VQDF_NEW1

#define     MY_VOB_NEW1(            \
    T,                              \
    b00,b01,b02,b03,b04,b05,b06,b07, b08,b09,b0a,b0b,b0c,b0d,b0e,b0f,   \
    b10,b11,b12,b13,b14,b15,b16,b17, b18,b19,b1a,b1b,b1c,b1d,b1e,b1f    \
)                                   \
(VOB ## T ## _TYPE)                 \
{                                   \
    .V0=VQB ## T ## _NEW1(          \
        (b00), (b01), (b02), (b03), (b04), (b05), (b06), (b07), \
        (b08), (b09), (b0a), (b0b), (b0c), (b0d), (b0e), (b0f)  \
    ),                              \
    .V1=VQB ## T ## _NEW1(          \
        (b10), (b11), (b12), (b13), (b14), (b15), (b16), (b17), \
        (b18), (b19), (b1a), (b1b), (b1c), (b1d), (b1e), (b1f)  \
    ),                              \
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
#define     VOBU_NEW1(...) MY_VOB_NEW1(U, __VA_ARGS__)
    return  VOBU_NEW1(
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
#define     VOBI_NEW1(...) MY_VOB_NEW1(I,__VA_ARGS__)
    return  VOBI_NEW1(
        x00,x01,x02,x03,x04,x05,x06,x07,
        x08,x09,x0a,x0b,x0c,x0d,x0e,x0f,
        x10,x11,x12,x13,x14,x15,x16,x17,
        x18,x19,x1a,x1b,x1c,x1d,x1e,x1f
    );
}

#define     MY_VOH_NEW1(T,      \
    h0,h1,h2,h3,h4,h5,h6,h7,    \
    h8,h9,ha,hb,hc,hd,he,hf     \
)                               \
(VOH ## T ## _TYPE)             \
{                               \
    .V0=VQH ## T ## _NEW1(      \
        (h0), (h1), (h2), (h3), \
        (h4), (h5), (h6), (h7)  \
    ),                          \
    .V1=VQH ## T ## _NEW1(      \
        (h8), (h9), (ha), (hb), \
        (hc), (hd), (he), (hf)  \
    ),                          \
}


INLINE Vohu VOHU_NEW1
(
    Hu x0, Hu x1, Hu x2, Hu x3,
    Hu x4, Hu x5, Hu x6, Hu x7,
    Hu x8, Hu x9, Hu xa, Hu xb,
    Hu xc, Hu xd, Hu xe, Hu xf
)
{
#define     VOHU_NEW1(...)  MY_VOH_NEW1(U, __VA_ARGS__)
    return  VOHU_NEW1(x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,xa,xb,xc,xd,xe,xf);
}

INLINE Vohi VOHI_NEW1
(
    Hi x0, Hi x1, Hi x2, Hi x3,
    Hi x4, Hi x5, Hi x6, Hi x7,
    Hi x8, Hi x9, Hi xa, Hi xb,
    Hi xc, Hi xd, Hi xe, Hi xf
)
{
#define     VOHI_NEW1(...)  MY_VOH_NEW1(I, __VA_ARGS__)
    return  VOHI_NEW1(x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,xa,xb,xc,xd,xe,xf );
}

#define     MY_VOW_NEW1(T,w0,w1,w2,w3,w4,w5,w6,w7)  \
(VOW ## T ## _TYPE)                                 \
{                                                   \
    .V0=VQW ## T ## _NEW1((w0), (w1), (w2), (w3)),  \
    .V1=VQW ## T ## _NEW1((w4), (w5), (w6), (w7))   \
}



INLINE Vowu VOWU_NEW1
(
    Wu x0, Wu x1, Wu x2, Wu x3,
    Wu x4, Wu x5, Wu x6, Wu x7
)
{
#define     VOWU_NEW1(...)  MY_VOW_NEW1(U, __VA_ARGS__)
    return  VOWU_NEW1(x0,x1,x2,x3,x4,x5,x6,x7);
}

INLINE Vowi VOWI_NEW1
(
    Wi x0, Wi x1, Wi x2, Wi x3,
    Wi x4, Wi x5, Wi x6, Wi x7
)
{
#define     VOWI_NEW1(...)  MY_VOW_NEW1(I, __VA_ARGS__)
    return  VOWI_NEW1(x0,x1,x2,x3,x4,x5,x6,x7);
}

INLINE Vowf VOWF_NEW1
(
    Wf x0, Wf x1, Wf x2, Wf x3,
    Wf x4, Wf x5, Wf x6, Wf x7
)
{
#define     VOWF_NEW1(...)  MY_VOW_NEW1(F, __VA_ARGS__)
    return  VOWF_NEW1(x0,x1,x2,x3,x4,x5,x6,x7);
}

#define     MY_VOD_NEW1(T,d0,d1,d2,d3)  \
(VOD ## T ## _TYPE)                     \
{                                       \
    .V0=VQD ## T ## _NEW1((d0), (d1)),  \
    .V1=VQD ## T ## _NEW1((d2), (d3))   \
}


INLINE Vodu VODU_NEW1
(
    Du x0, Du x1, Du x2, Du x3
)
{
#define     VODU_NEW1(...)  MY_VOD_NEW1(U, __VA_ARGS__)
    return  VODU_NEW1(x0,x1,x2,x3);
}

INLINE Vodi VODI_NEW1
(
    Di x0, Di x1, Di x2, Di x3
)
{
#define     VODI_NEW1(...)  MY_VOD_NEW1(I, __VA_ARGS__)
    return  VODI_NEW1(x0,x1,x2,x3);
}

INLINE Vodf VODF_NEW1
(
    Df x0, Df x1, Df x2, Df x3
)
{
#define     VODF_NEW1(...)  MY_VOD_NEW1(F, __VA_ARGS__)
    return  VODF_NEW1(x0,x1,x2,x3);
}


#define     MY_VSB_NEW1(            \
    T,                              \
    b00,b01,b02,b03,b04,b05,b06,b07, b08,b09,b0a,b0b,b0c,b0d,b0e,b0f,   \
    b10,b11,b12,b13,b14,b15,b16,b17, b18,b19,b1a,b1b,b1c,b1d,b1e,b1f,   \
    b20,b21,b22,b23,b24,b25,b26,b27, b28,b29,b2a,b2b,b2c,b2d,b2e,b2f,   \
    b30,b31,b32,b33,b34,b35,b36,b37, b38,b39,b3a,b3b,b3c,b3d,b3e,b3f    \
)                                   \
(VSB ## T ## _TYPE)                 \
{                                   \
    .V0=VQB ## T ## _NEW1(          \
        (b00), (b01), (b02), (b03), (b04), (b05), (b06), (b07), \
        (b08), (b09), (b0a), (b0b), (b0c), (b0d), (b0e), (b0f)  \
    ),                              \
    .V1=VQB ## T ## _NEW1(          \
        (b10), (b11), (b12), (b13), (b14), (b15), (b16), (b17), \
        (b18), (b19), (b1a), (b1b), (b1c), (b1d), (b1e), (b1f)  \
    ),                              \
    .V2=VQB ## T ## _NEW1(          \
        (b20), (b21), (b22), (b23), (b24), (b25), (b26), (b27), \
        (b28), (b29), (b2a), (b2b), (b2c), (b2d), (b2e), (b2f)  \
    ),                              \
    .V3=VQB ## T ## _NEW1(          \
        (b30), (b31), (b32), (b33), (b34), (b35), (b36), (b37), \
        (b38), (b39), (b3a), (b3b), (b3c), (b3d), (b3e), (b3f)  \
    ),                              \
}

#define     MY_VSH_NEW1(T,          \
    h00,h01,h02,h03,h04,h05,h06,h07,\
    h08,h09,h0a,h0b,h0c,h0d,h0e,h0f,\
    h10,h11,h12,h13,h14,h15,h16,h17,\
    h18,h19,h1a,h1b,h1c,h1d,h1e,h1f \
)                                   \
(VSH ## T ## _TYPE)                 \
{                                   \
    .V0=VQH ## T ## _NEW1(          \
        (h00), (h01), (h02), (h03), \
        (h04), (h05), (h06), (h07)  \
    ),                              \
    .V1=VQH ## T ## _NEW1(          \
        (h08), (h09), (h0a), (h0b), \
        (h0c), (h0d), (h0e), (h0f)  \
    ),                              \
    .V2=VQH ## T ## _NEW1(          \
        (h10), (h11), (h12), (h13), \
        (h14), (h15) ,(h16), (h17)  \
    ),                              \
    .V3=VQH ## T ## _NEW1(          \
        (h18), (h19), (h1a), (h1b), \
        (h1c), (h1d), (h1e), (h1f)  \
    ),                              \
}


#define     MY_VSW_NEW1(\
    T,                  \
    w0,w1,w2,w3,        \
    w4,w5,w6,w7,        \
    w8,w9,wa,wb,        \
    wc,wd,we,wf         \
)                       \
(VSW ## T ## _TYPE)     \
{                               \
    .V0=VQW ## T ## _NEW1((w0), (w1), (w2), (w3)),  \
    .V1=VQW ## T ## _NEW1((w4), (w5), (w6), (w7)),  \
    .V2=VQW ## T ## _NEW1((w8), (w9), (wa), (wb)),  \
    .V3=VQW ## T ## _NEW1((wc), (wd), (we), (wf)),  \
}

#define     MY_VSD_NEW1(T,d0,d1,d2,d3,d4,d5,d6,d7) \
(VSD ## T ## _TYPE)                     \
{                                       \
    .V0=VQD ## T ## _NEW1((d0), (d1)),  \
    .V1=VQD ## T ## _NEW1((d2), (d3)),  \
    .V2=VQD ## T ## _NEW1((d4), (d5)),  \
    .V3=VQD ## T ## _NEW1((d6), (d7)),  \
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
#define     VSBU_NEW1(...) MY_VSB_NEW1(U,__VA_ARGS__)
    return  VSBU_NEW1(
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
#define     VSBI_NEW1(...) MY_VSB_NEW1(I,__VA_ARGS__)
    return  VSBI_NEW1(
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
#define     VSHU_NEW1(...)  MY_VSH_NEW1(U, __VA_ARGS__)
    return  VSHU_NEW1(
        x00,x01,x02,x03,x04,x05,x06,x07,\
        x08,x09,x0a,x0b,x0c,x0d,x0e,x0f,\
        x10,x11,x12,x13,x14,x15,x16,x17,\
        x18,x19,x1a,x1b,x1c,x1d,x1e,x1f \
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
#define     VSHI_NEW1(...)  MY_VSH_NEW1(I, __VA_ARGS__)
    return  VSHI_NEW1(
        x00,x01,x02,x03,x04,x05,x06,x07,\
        x08,x09,x0a,x0b,x0c,x0d,x0e,x0f,\
        x10,x11,x12,x13,x14,x15,x16,x17,\
        x18,x19,x1a,x1b,x1c,x1d,x1e,x1f \
    );
}


INLINE Vswu VSWU_NEW1
(
    Wu x00, Wu x01, Wu x02, Wu x03,
    Wu x04, Wu x05, Wu x06, Wu x07,
    Wu x08, Wu x09, Wu x0a, Wu x0b,
    Wu x0c, Wu x0d, Wu x0e, Wu x0f
)
{
#define     VSWU_NEW1(...)  MY_VSW_NEW1(U, __VA_ARGS__)
    return  VSWU_NEW1(
        x00,x01,x02,x03,x04,x05,x06,x07,\
        x08,x09,x0a,x0b,x0c,x0d,x0e,x0f
    );
}

INLINE Vswi VSWI_NEW1
(
    Wi x00, Wi x01, Wi x02, Wi x03,
    Wi x04, Wi x05, Wi x06, Wi x07,
    Wi x08, Wi x09, Wi x0a, Wi x0b,
    Wi x0c, Wi x0d, Wi x0e, Wi x0f
)
{
#define     VSWI_NEW1(...)  MY_VSW_NEW1(I, __VA_ARGS__)
    return  VSWI_NEW1(
        x00,x01,x02,x03,x04,x05,x06,x07,
        x08,x09,x0a,x0b,x0c,x0d,x0e,x0f
    );
}

INLINE Vswf VSWF_NEW1
(
    Wf x00, Wf x01, Wf x02, Wf x03,
    Wf x04, Wf x05, Wf x06, Wf x07,
    Wf x08, Wf x09, Wf x0a, Wf x0b,
    Wf x0c, Wf x0d, Wf x0e, Wf x0f
)
{
#define     VSWF_NEW1(...)  MY_VSW_NEW1(F, __VA_ARGS__)
    return  VSWF_NEW1(
        x00,x01,x02,x03,x04,x05,x06,x07,
        x08,x09,x0a,x0b,x0c,x0d,x0e,x0f
    );
}


INLINE Vsdu VSDU_NEW1
(
    Du x00, Du x01, Du x02, Du x03,
    Du x04, Du x05, Du x06, Du x07
)
{
#define     VSDU_NEW1(...)  MY_VSD_NEW1(U, __VA_ARGS__)
    return  VSDU_NEW1(x00,x01,x02,x03,x04,x05,x06,x07);
}

INLINE Vsdi VSDI_NEW1
(
    Di x00, Di x01, Di x02, Di x03,
    Di x04, Di x05, Di x06, Di x07
)
{
#define     VSDI_NEW1(...)  MY_VSD_NEW1(I, __VA_ARGS__)
    return  VSDI_NEW1(x00,x01,x02,x03,x04,x05,x06,x07);
}

INLINE Vsdf VSDF_NEW1
(
    Df x00, Df x01, Df x02, Df x03,
    Df x04, Df x05, Df x06, Df x07
)
{
#define     VSDF_NEW1(...)  MY_VSD_NEW1(F, __VA_ARGS__)
    return  VSDF_NEW1(x00,x01,x02,x03,x04,x05,x06,x07);
}

#endif 

#endif // EOF