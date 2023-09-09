/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 
    _init(a, ...)
    Construct a value from the variable arguments list and
    assign it to 'a'. If no arguments are provided, the 
    operation should initialize 'a' to all-zero.

    _new0(T)
    Obtain the null value of type T. 

    _new1(T, ...)
    Construct a new object from a fixed number of arguments
    that depends in the type.

*/

#ifndef MY_EXTGOP_INIT_H // BOF
#define MY_EXTGOP_INIT_H

#ifndef MY_EXTDEF_H
#include  "extdef.h"
#endif

#ifndef MY_ISA
#   error "MY_ISA undefined"

#elif MY_ISA == ISA_ARM
#   include "extgop/arm/new0.h"
#   include "extgop/arm/new1.h"

#elif MY_ISA == ISA_X86
#   include "extgop/x86/new1.h"
#   include "extgop/x86/new0.h"

#elif MY_ISA == ISA_PPC

#elif MY_ISA == ISA_RV

#else
#   error "unknown value of MY_ISA"
#endif

#define MY_FIRST1(_, _1,_2,...)        _1
#define MY_FIRST2(_, _1,_2,...)        _1,_2
#define MY_FIRST4(_, _1,_2,_3,_4,...)  _1,_2,_3,_4
#define MY_FIRST8(_, _1,_2,_3,_4,_5,_6,_7,_8,...) _1,_2,_3,_4, _5,_6,_7,_8
#define MY_FIRST16(                 \
    _,  _1,_2,_3,_4, _5,_6,_7,_8,   \
        _9,_a,_b,_c, _d,_e,_f,_g,   \
    ...                             \
)_1,_2,_3,_4, _5,_6,_7,_8, _9,_a,_b,_c, _d,_e,_f,_g

#define MY_FIRST32(                 \
    _,                              \
    p00,p01,p02,p03,p04,p05,p06,p07,\
    p10,p11,p12,p13,p14,p15,p16,p17,\
    p20,p21,p22,p23,p24,p25,p26,p27,\
    p30,p31,p32,p33,p34,p35,p36,p37,\
    ...                             \
)   p00,p01,p02,p03,p04,p05,p06,p07,\
    p10,p11,p12,p13,p14,p15,p16,p17,\
    p20,p21,p22,p23,p24,p25,p26,p27,\
    p30,p31,p32,p33,p34,p35,p36,p37

#define MY_FIRST64(                 \
    _,                              \
    p00,p01,p02,p03,p04,p05,p06,p07,\
    p10,p11,p12,p13,p14,p15,p16,p17,\
    p20,p21,p22,p23,p24,p25,p26,p27,\
    p30,p31,p32,p33,p34,p35,p36,p37,\
    p40,p41,p42,p43,p44,p45,p46,p47,\
    p50,p51,p52,p53,p54,p55,p56,p57,\
    p60,p61,p62,p63,p64,p65,p66,p67,\
    p70,p71,p72,p73,p74,p75,p76,p77,\
    ...                             \
)   p00,p01,p02,p03,p04,p05,p06,p07,\
    p10,p11,p12,p13,p14,p15,p16,p17,\
    p20,p21,p22,p23,p24,p25,p26,p27,\
    p30,p31,p32,p33,p34,p35,p36,p37,\
    p40,p41,p42,p43,p44,p45,p46,p47,\
    p50,p51,p52,p53,p54,p55,p56,p57,\
    p60,p61,p62,p63,p64,p65,p66,p67,\
    p70,p71,p72,p73,p74,p75,p76,p77 

#define     MY_INITPREP(...)    MY_INITPREP_PADDING, ##__VA_ARGS__

#define     MY_INIT1_P1(...)        \
    MY_INIT1_P2(                    \
        MY_INITPREP(__VA_ARGS__),   \
        0                           \
    )

#define     MY_INIT2_P1(...)        \
    MY_INIT2_P2(                    \
        MY_INITPREP(__VA_ARGS__),   \
        0,0                         \
    )

#define     MY_INIT4_P1(...)        \
    MY_INIT4_P2(                    \
        MY_INITPREP(__VA_ARGS__),   \
        0,0,0,0                     \
    )

#define     MY_INIT8_P1(...)        \
    MY_INIT8_P2(                    \
        MY_INITPREP(__VA_ARGS__),   \
        0,0,0,0, 0,0,0,0            \
    )

#define     MY_INIT16_P1(...)       \
    MY_INIT16_P2(                   \
        MY_INITPREP(__VA_ARGS__),   \
        0,0,0,0, 0,0,0,0,           \
        0,0,0,0, 0,0,0,0            \
)

#define     MY_INIT32_P1(...)       \
    MY_INIT32_P2(                   \
        MY_INITPREP(__VA_ARGS__),   \
        0,0,0,0, 0,0,0,0,           \
        0,0,0,0, 0,0,0,0,           \
        0,0,0,0, 0,0,0,0,           \
        0,0,0,0, 0,0,0,0            \
)

#define     MY_INIT64_P1(...)       \
    MY_INIT64_P2(                   \
        MY_INITPREP(__VA_ARGS__),   \
        0,0,0,0, 0,0,0,0,           \
        0,0,0,0, 0,0,0,0,           \
        0,0,0,0, 0,0,0,0,           \
        0,0,0,0, 0,0,0,0,           \
        0,0,0,0, 0,0,0,0,           \
        0,0,0,0, 0,0,0,0,           \
        0,0,0,0, 0,0,0,0,           \
        0,0,0,0, 0,0,0,0            \
)

#define MY_INIT2_P2(...)    MY_FIRST2(__VA_ARGS__)
#define MY_INIT4_P2(...)    MY_FIRST4(__VA_ARGS__)
#define MY_INIT8_P2(...)    MY_FIRST8(__VA_ARGS__)
#define MY_INIT16_P2(...)   MY_FIRST16(__VA_ARGS__)
#define MY_INIT32_P2(...)   MY_FIRST32(__VA_ARGS__)
#define MY_INIT64_P2(...)   MY_FIRST64(__VA_ARGS__)

#define MY_INIT(N, T, A, ...)               \
(                                           \
    ((void) _Generic((A), T ## _TYPE: 0)),  \
    (                                       \
        (A)=MY_CALL1(                       \
            T##_NEW1,                       \
            MY_INIT##N##_P1(__VA_ARGS__)    \
        )                                   \
    )                                       \
)

#define VDBU_INIT(a, ...) MY_INIT(8, VDBU, a, __VA_ARGS__)
#define VDBI_INIT(a, ...) MY_INIT(8, VDBI, a, __VA_ARGS__)

#define VDHU_INIT(a, ...) MY_INIT(4, VDHU, a, __VA_ARGS__)
#define VDHI_INIT(a, ...) MY_INIT(4, VDHI, a, __VA_ARGS__)

#define VDWU_INIT(a, ...) MY_INIT(2, VDWU, a, __VA_ARGS__)
#define VDWI_INIT(a, ...) MY_INIT(2, VDWI, a, __VA_ARGS__)
#define VDWF_INIT(a, ...) MY_INIT(2, VDWF, a, __VA_ARGS__)

#define VDDU_INIT(a, ...) MY_INIT(1, VDDU, a, __VA_ARGS__)
#define VDDI_INIT(a, ...) MY_INIT(1, VDDI, a, __VA_ARGS__)
#define VDDF_INIT(a, ...) MY_INIT(1, VDDF, a, __VA_ARGS__)


#define VQBU_INIT(a, ...) MY_INIT(16,VQBU, a, __VA_ARGS__)
#define VQBI_INIT(a, ...) MY_INIT(16,VQBI, a, __VA_ARGS__)

#define VQHU_INIT(a, ...) MY_INIT(8, VQHU, a, __VA_ARGS__)
#define VQHI_INIT(a, ...) MY_INIT(8, VQHI, a, __VA_ARGS__)

#define VQWU_INIT(a, ...) MY_INIT(4, VQWU, a, __VA_ARGS__)
#define VQWI_INIT(a, ...) MY_INIT(4, VQWI, a, __VA_ARGS__)
#define VQWF_INIT(a, ...) MY_INIT(4, VQWF, a, __VA_ARGS__)

#define VQDU_INIT(a, ...) MY_INIT(2, VQDU, a, __VA_ARGS__)
#define VQDI_INIT(a, ...) MY_INIT(2, VQDI, a, __VA_ARGS__)
#define VQDF_INIT(a, ...) MY_INIT(2, VQDF, a, __VA_ARGS__)



#define VOBU_INIT(a, ...) MY_INIT(32,VOBU, a, __VA_ARGS__)
#define VOBI_INIT(a, ...) MY_INIT(32,VOBI, a, __VA_ARGS__)

#define VOHU_INIT(a, ...) MY_INIT(16, VOHU, a, __VA_ARGS__)
#define VOHI_INIT(a, ...) MY_INIT(16, VOHI, a, __VA_ARGS__)

#define VOWU_INIT(a, ...) MY_INIT(8, VOWU, a, __VA_ARGS__)
#define VOWI_INIT(a, ...) MY_INIT(8, VOWI, a, __VA_ARGS__)
#define VOWF_INIT(a, ...) MY_INIT(8, VOWF, a, __VA_ARGS__)

#define VODU_INIT(a, ...) MY_INIT(4, VODU, a, __VA_ARGS__)
#define VODI_INIT(a, ...) MY_INIT(4, VODI, a, __VA_ARGS__)
#define VODF_INIT(a, ...) MY_INIT(4, VODF, a, __VA_ARGS__)



#define VSBU_INIT(a, ...) MY_INIT(64,VSBU, a, __VA_ARGS__)
#define VSBI_INIT(a, ...) MY_INIT(64,VSBI, a, __VA_ARGS__)

#define VSHU_INIT(a, ...) MY_INIT(32, VSHU, a, __VA_ARGS__)
#define VSHI_INIT(a, ...) MY_INIT(32, VSHI, a, __VA_ARGS__)

#define VSWU_INIT(a, ...) MY_INIT(16, VSWU, a, __VA_ARGS__)
#define VSWI_INIT(a, ...) MY_INIT(16, VSWI, a, __VA_ARGS__)
#define VSWF_INIT(a, ...) MY_INIT(16, VSWF, a, __VA_ARGS__)

#define VSDU_INIT(a, ...) MY_INIT(8, VSDU, a, __VA_ARGS__)
#define VSDI_INIT(a, ...) MY_INIT(8, VSDI, a, __VA_ARGS__)
#define VSDF_INIT(a, ...) MY_INIT(8, VSDF, a, __VA_ARGS__)


Vdbu new0dbu();
Vdbi new0dbi();

Vdhu new0dhu();
Vdhi new0dhi();

Vdwu new0dwu();
Vdwi new0dwi();
Vdwf new0dwf();

Vddu new0ddu();
Vddi new0ddi();
Vddf new0ddf();


Vqbu new0qbu();
Vqbi new0qbi();

Vqhu new0qhu();
Vqhi new0qhi();

Vqwu new0qwu();
Vqwi new0qwi();
Vqwf new0qwf();

Vqdu new0qdu();
Vqdi new0qdi();
Vqdf new0qdf();


Vobu new0obu();
Vobi new0obi();

Vohu new0ohu();
Vohi new0ohi();

Vowu new0owu();
Vowi new0owi();
Vowf new0owf();

Vodu new0odu();
Vodi new0odi();
Vodf new0odf();


Vsbu new0sbu();
Vsbi new0sbi();

Vshu new0shu();
Vshi new0shi();

Vswu new0swu();
Vswi new0swi();
Vswf new0swf();

Vsdu new0sdu();
Vsdi new0sdi();
Vsdf new0sdf();




Vdbu new1dbu(Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu);
Vdbi new1dbi(Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi);

Vdhu new1dhu(Hu, Hu, Hu, Hu);
Vdhi new1dhi(Hi, Hi, Hi, Hi);

Vdwu new1dwu(Wu, Wu);
Vdwi new1dwi(Wi, Wi);
Vdwf new1dwf(Wf, Wf);

Vddu new1ddu(Du);
Vddi new1ddi(Di);
Vddf new1ddf(Df);


Vqbu new1qbu(Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu);
Vqbi new1qbi(Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi);

Vqhu new1qhu(Hu, Hu, Hu, Hu, Hu, Hu, Hu, Hu);
Vqhi new1qhi(Hi, Hi, Hi, Hi, Hi, Hi, Hi, Hi);

Vqwu new1qwu(Wu, Wu, Wu, Wu);
Vqwi new1qwi(Wi, Wi, Wi, Wi);
Vqwf new1qwf(Wf, Wf, Wf, Wf);

Vqdu new1qdu(Du, Du);
Vqdi new1qdi(Di, Di);
Vqdf new1qdf(Df, Df);

Vobu new1obu
(
    Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu,
    Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu
);

Vobi new1obi
(
    Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi,
    Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi
);


Vohu new1ohu
(
    Hu, Hu, Hu, Hu, Hu, Hu, Hu, Hu,
    Hu, Hu, Hu, Hu, Hu, Hu, Hu, Hu
);

Vohi new1ohi
(
    Hi, Hi, Hi, Hi, Hi, Hi, Hi, Hi,
    Hi, Hi, Hi, Hi, Hi, Hi, Hi, Hi
);


Vowu new1owu
(
    Wu, Wu, Wu, Wu,
    Wu, Wu, Wu, Wu
);

Vowi new1owi
(
    Wi, Wi, Wi, Wi,
    Wi, Wi, Wi, Wi
);

Vowf new1owf
(
    Wf, Wf, Wf, Wf,
    Wf, Wf, Wf, Wf
);


Vodu new1odu
(
    Du,Du,  
    Du,Du
);

Vodi new1odi
(
    Di,Di,  
    Di,Di
);

Vodf new1odf
(
    Df,Df,  
    Df,Df
);



Vsbu new1sbu
(
    Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu,
    Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu,
    Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu,
    Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu, Bu
);

Vsbi new1sbi
(
    Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi,
    Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi,
    Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi,
    Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi, Bi
);


Vshu new1shu
(
    Hu, Hu, Hu, Hu, Hu, Hu, Hu, Hu,
    Hu, Hu, Hu, Hu, Hu, Hu, Hu, Hu,
    Hu, Hu, Hu, Hu, Hu, Hu, Hu, Hu,
    Hu, Hu, Hu, Hu, Hu, Hu, Hu, Hu
);

Vshi new1shi
(
    Hi, Hi, Hi, Hi, Hi, Hi, Hi, Hi,
    Hi, Hi, Hi, Hi, Hi, Hi, Hi, Hi,
    Hi, Hi, Hi, Hi, Hi, Hi, Hi, Hi,
    Hi, Hi, Hi, Hi, Hi, Hi, Hi, Hi
);


Vswu new1swu
(
    Wu, Wu, Wu, Wu,
    Wu, Wu, Wu, Wu,
    Wu, Wu, Wu, Wu,
    Wu, Wu, Wu, Wu
);

Vswi new1swi
(
    Wi, Wi, Wi, Wi,
    Wi, Wi, Wi, Wi,
    Wi, Wi, Wi, Wi,
    Wi, Wi, Wi, Wi
);

Vswf new1swf
(
    Wf, Wf, Wf, Wf,
    Wf, Wf, Wf, Wf,
    Wf, Wf, Wf, Wf,
    Wf, Wf, Wf, Wf
);


Vsdu new1sdu(Du,Du,   Du,Du,   Du,Du,   Du,Du);

Vsdi new1sdi(Di,Di,   Di,Di,   Di,Di,   Di,Di);

Vsdf new1sdf(Df,Df,   Df,Df,   Df,Df,   Df,Df);



#define     new0dbu     VDBU_NEW0
#define     new0dbi     VDBI_NEW0
#define     new0dhu     VDHU_NEW0
#define     new0dhi     VDHI_NEW0
#define     new0dwu     VDWU_NEW0
#define     new0dwi     VDWI_NEW0
#define     new0dwf     VDWF_NEW0
#define     new0ddu     VDDU_NEW0
#define     new0ddi     VDDI_NEW0
#define     new0ddf     VDDF_NEW0

#define     new0qbu     VQBU_NEW0
#define     new0qbi     VQBI_NEW0
#define     new0qhu     VQHU_NEW0
#define     new0qhi     VQHI_NEW0
#define     new0qwu     VQWU_NEW0
#define     new0qwi     VQWI_NEW0
#define     new0qwf     VQWF_NEW0
#define     new0qdu     VQDU_NEW0
#define     new0qdi     VQDI_NEW0
#define     new0qdf     VQDF_NEW0

#define     new0obu     VOBU_NEW0
#define     new0obi     VOBI_NEW0
#define     new0ohu     VOHU_NEW0
#define     new0ohi     VOHI_NEW0
#define     new0owu     VOWU_NEW0
#define     new0owi     VOWI_NEW0
#define     new0owf     VOWF_NEW0
#define     new0odu     VODU_NEW0
#define     new0odi     VODI_NEW0
#define     new0odf     VODF_NEW0

#define     new0sbu     VSBU_NEW0
#define     new0sbi     VSBI_NEW0
#define     new0shu     VSHU_NEW0
#define     new0shi     VSHI_NEW0
#define     new0swu     VSWU_NEW0
#define     new0swi     VSWI_NEW0
#define     new0swf     VSWF_NEW0
#define     new0sdu     VSDU_NEW0
#define     new0sdi     VSDI_NEW0
#define     new0sdf     VSDF_NEW0

#define _new0_funcof(T) \
MY_FUNCOF(\
    new1,\
    (T){0},\
    NONE,\
    B_DR,\
    B_DR,\
    B_DR,\
    B_DR \
)
#define _new0(T) (_new1_funcof(T)())


#define     new1dbu     VDBU_NEW1
#define     new1dbi     VDBI_NEW1
#define     new1dhu     VDHU_NEW1
#define     new1dhi     VDHI_NEW1
#define     new1dwu     VDWU_NEW1
#define     new1dwi     VDWI_NEW1
#define     new1dwf     VDWF_NEW1
#define     new1ddu     VDDU_NEW1
#define     new1ddi     VDDI_NEW1
#define     new1ddf     VDDF_NEW1

#define     new1qbu     VQBU_NEW1
#define     new1qbi     VQBI_NEW1
#define     new1qhu     VQHU_NEW1
#define     new1qhi     VQHI_NEW1
#define     new1qwu     VQWU_NEW1
#define     new1qwi     VQWI_NEW1
#define     new1qwf     VQWF_NEW1
#define     new1qdu     VQDU_NEW1
#define     new1qdi     VQDI_NEW1
#define     new1qdf     VQDF_NEW1

#define     new1obu     VOBU_NEW1
#define     new1obi     VOBI_NEW1
#define     new1ohu     VOHU_NEW1
#define     new1ohi     VOHI_NEW1
#define     new1owu     VOWU_NEW1
#define     new1owi     VOWI_NEW1
#define     new1owf     VOWF_NEW1
#define     new1odu     VODU_NEW1
#define     new1odi     VODI_NEW1
#define     new1odf     VODF_NEW1

#define     new1sbu     VSBU_NEW1
#define     new1sbi     VSBI_NEW1
#define     new1shu     VSHU_NEW1
#define     new1shi     VSHI_NEW1
#define     new1swu     VSWU_NEW1
#define     new1swi     VSWI_NEW1
#define     new1swf     VSWF_NEW1
#define     new1sdu     VSDU_NEW1
#define     new1sdi     VSDI_NEW1
#define     new1sdf     VSDF_NEW1
#define _new1_funcof(T) \
MY_FUNCOF(\
    new1,\
    (T){0},\
    NONE,\
    B_DR,\
    B_DR,\
    B_DR,\
    B_DR \
)
#define _new1(T, ...) (_new1_funcof(T)(__VA_ARGS__))

#endif // EOF
