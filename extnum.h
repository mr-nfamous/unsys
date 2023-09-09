/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

#ifndef MY_EXTNUM_H
#define MY_EXTNUM_H

#ifndef MY_FLOAT_H
#define MY_FLOAT_H
#define __STDC_WANT_IEC_60559_TYPES_EXT__
#include <float.h>
#endif // !defined(MY_FLOAT_H)

#ifndef MY_EXTDEF_H
#include  "extdef.h"
#endif

#if (MY_ISA == ISA_ARM) && !defined(MY_ARM_NEON_H)
#   define MY_ARM_NEON_H
#   include  <arm_neon.h>
#endif


/*  NB_@

    Number classification
            <math.h>
    0                       NB_ZERO
    +0.0    FP_ZERO         NB_ZERO
    -0.0    FP_ZERO         NB_ZERO|NB_SIGN
    +1.0    FP_NORMAL       NB_NORM
    -1.0    FP_NORMAL       NB_NORM|NB_SIGN
            FP_SUBNORMAL    NB_TINY
            FP_INFINITY     NB_HUGE
    +inf    FP_INFINITY     NB_PINF = (NB_HUGE)
    -inf    FP_INFINITY     NB_NINF = (NB_HUGE|NB_SIGN)
    ±qnan   FP_NAN          NB_QNAN
    ±snan   FP_NAN          NB_SNAN
*/


#ifndef NB_ZERO
#define NB_ZERO (0x00)              // zero
#define NB_NORM (0x01)              // normal
#define NB_TINY (0x02)              // subnormal
#define NB_HUGE (0x04)              // infinity
#define NB_QNAN (NB_TINY|NB_HUGE)   // NaN
#define NB_SNAN (NB_QNAN|NB_SIGN)   // NaN (signaling)
#define NB_SIGN (0x80)              // signed
#define NB_PINF (NB_HUGE)           // +∞
#define NB_NINF (NB_HUGE|NB_SIGN)   // -∞
#endif

/*
    Directed rounding modes

    * DR_PREV
        I.e. towards zero, aka truncate
        -1.5 => -1.0 (+0.5)
        +1.5 => +1.0 (-0.5)

    * DR_NEXT
        I.e. towards the integer further from zero
        -1.5 => -2.0 (-0.5)
        +1.5 => +2.0 (+0.5)

    * DR_PINF
        I.e. towards positive infinity. AKA ceil
        -1.5 => -1.0 (+0.5)
        +1.5 => +2.0 (+0.5)

    * DR_NINF
        I.e. towards negative infinity. AKA floor
        -1.5 => -2.0 (-0.5)
        +1.5 => +1.0 (-0.5)

    * DR_EVEN
        I.e. towards the closest even integer
        -1.5 => -2.0 (-0.5)
        -2.5 => -2.0 (+0.5)

    * DR_ODD
        I.e. towards the closest odd integer
        -1.5 => -1.0 (+0.5)
        -2.5 => -3.0 (-0.5)

    * DR_NEAR
        I.e. towards the closest integer. `DROUND_NEAR` is
        combined with one of the other modes to determine
        what happens if a tie occurs.

*/

#define DR_PREV     (0)
#define DR_NEXT     (1)
#define DR_PINF     (2)
#define DR_NINF     (3)
#define DR_EVEN     (4)
#define DR_ODD      (5)

#define DR_NEAR     (0x80)

#define DEFINE_GBM(S,W,K,M) ((M>>(K-W))<<S)

#define DEFINE_YBM(I)   (1u<<I##_BFS)
#define DEFINE_BBM(I,W) DEFINE_GBM(I##_BFS, W, 0010, 0xffu)
#define DEFINE_HBM(I,W) DEFINE_GBM(I##_BFS, W, 0020, 0xffffu)
#define DEFINE_WBM(I,W) DEFINE_GBM(I##_BFS, W, 0040, 0xffffffffu)
#define DEFINE_DBM(I,W) DEFINE_GBM(I##_BFS, W, 0100, 0xffffffffffffffffu)

#define MY_TGSN(_, F) F(_)

#define     BYTE_(_)            BYTE_ ## _
#define     BYTE_TYPE           union Byte
#define     BYTE_I              SCHAR_
#define     BYTE_U              UCHAR_
#define     BYTE_UTYPE          unsigned char
#define     BYTE_ITYPE          signed char
#define     BYTE_SN(_)          _ ## b
#define     BYTE_SNU(_)         MY_TGSN(_,BYTE_U(SN))
#define     BYTE_SNI(_)         MY_TGSN(_,BYTE_I(SN))
#define     BYTE_SNF(_)         MY_TGSN(_,BYTE_F(SN))

#define     BYTE_LOG2SZ         (0)
#define     BYTE_SIZE           SIZE_C(1)
#define     BYTE_WIDTH          NDIG_C(8)   // "1111" "1111"
#define     BYTE_UDIG           NDIG_C(3)   // "255"
#define     BYTE_IDIG           NDIG_C(4)   // "-127"
#define     BYTE_XDIG           NDIG_C(2)   // "7f"
#define     BYTE_ODIG           NDIG_C(3)   // "377"
#define     BYTE_IMIN           (BYTE_TYPE){.I=BYTE_I(MIN)}
#define     BYTE_IMAX           (BYTE_TYPE){.I=BYTE_I(MAX)}
#define     BYTE_UMAX           (BYTE_TYPE){.U=BYTE_U(MAX)}
#define     BYTE_TGKI(_)        MY_TGCASE(BYTE_I, _)
#define     BYTE_TGKU(_)        MY_TGCASE(BYTE_U, _)
#if defined(_MSC_VER)
#   define  BYTE_TGKC(_)
#else
#   define  BYTE_TGKC(_)        char:CHAR_SN(_),
#endif

#define     HALF_(_)            HALF_ ## _
#define     HALF_I              SHRT_
#define     HALF_U              USHRT_
#define     HALF_F              FLT16_
#define     HALF_UTYPE          unsigned short
#define     HALF_ITYPE          short 
#define     HALF_FTYPE          flt16_t
#define     HALF_SN(_)          _ ## h
#define     HALF_SNU(_)         MY_TGSN(_,HALF_U(SN))
#define     HALF_SNI(_)         MY_TGSN(_,HALF_I(SN))
#define     HALF_SNF(_)         MY_TGSN(_,HALF_F(SN))
#define     HALF_TYPE           union Half
#define     HALF_LOG2SZ         (1)
#define     HALF_SIZE           (WORD_SIZE>>1)
#define     HALF_WIDTH          NDIG_C(16)
#define     HALF_UDIG           NDIG_C(5)   // "65535"
#define     HALF_IDIG           NDIG_C(6)   // "-32768"
#define     HALF_XDIG           NDIG_C(4)   // "7fff"
#define     HALF_ODIG           NDIG_C(6)   // "177777"


#define     HALF_IMIN   (HALF_TYPE){.I=HALF_I(MIN)}
#define     HALF_IMAX   (HALF_TYPE){.I=HALF_I(MAX)}
#define     HALF_UMAX   (HALF_TYPE){.U=HALF_U(MAX)}

#define     HALF_NMIN   (HALF_TYPE){.U=UINT16_C(0x8400)}
#define     HALF_PMIN   (HALF_TYPE){.U=UINT16_C(0x0400)}
#define     HALF_NMAX   (HALF_TYPE){.U=UINT16_C(0xfbff)}
#define     HALF_PMAX   (HALF_TYPE){.U=UINT16_C(0x7bff)}
#define     HALF_NINF   (HALF_TYPE){.U=UINT16_C(0xfc00)}
#define     HALF_PINF   (HALF_TYPE){.U=UINT16_C(0x7c00)}
#define     HALF_QNAN   (HALF_TYPE){.U=UINT16_C(0x7e00)}

#define     HALF_TGKU(_)        MY_TGCASE(HALF_U, _)
#define     HALF_TGKI(_)        MY_TGCASE(HALF_I, _)
#define     HALF_TGKF(_)        MY_TGCASE(HALF_F, _)
#define     HALF_TGKG(_)        HALF_TGKI   HALF_TGKU
#define     HALF_TGKS(_)        HALF_TGKI   HALF_TGKF
#define     HALF_TGKR(_)        HALF_TGKG   HALF_TGKF

#define     HALF_TGXI(_)        MY_TGCASE(XHI_,   _)
#define     HALF_TGX(_)         MY_TGCASE(XHI_,   _)


#define     WORD_(_)            WORD_ ## _
#define     WORD_U              UINT_
#define     WORD_I              INT_
#define     WORD_F              FLT_
#define     WORD_UTYPE          unsigned int

#define     WORD_XU             XWU_
#define     WORD_XI             XWI_
#define     WORD_XF             XWF_
#define     WORD_XTYPE          union Xd
#define     WORD_XUTYPE         struct Xwu
#define     WORD_XITYPE         struct Xwi
#define     WORD_XFTYPE         struct Xwf

#define     WORD_ITYPE          int
#define     WORD_FTYPE          float 
#define     WORD_SN(_)          _ ## w

#define     WORD_SNU(_)         MY_TGSN(_,WORD_U(SN))
#define     WORD_SNI(_)         MY_TGSN(_,WORD_I(SN))
#define     WORD_SNF(_)         MY_TGSN(_,WORD_F(SN))

#define     WORD_TYPE           union Word
#define     WORD_LOG2SZ         (2)
#define     WORD_SIZE           SIZE_C(4)
#define     WORD_WIDTH          NDIG_C(32)
#define     WORD_UDIG           NDIG_C(10)  // "4294967295"
#define     WORD_IDIG           NDIG_C(11)  // "-2147483648"
#define     WORD_XDIG           NDIG_C(8)   // "7fffffff"
#define     WORD_ODIG           NDIG_C(11)  // 37777777777

#define     WORD_IMIN   (WORD_TYPE){.I=WORD_I(MIN)}
#define     WORD_IMAX   (WORD_TYPE){.I=WORD_I(MAX)}
#define     WORD_UMAX   (WORD_TYPE){.U=WORD_U(MAX)}

#define     WORD_NMIN   (WORD_TYPE){.U=UINT32_C(0x80800000)}
#define     WORD_PMIN   (WORD_TYPE){.U=UINT32_C(0x00800000)}
#define     WORD_NMAX   (WORD_TYPE){.U=UINT32_C(0xff7fffff)}
#define     WORD_PMAX   (WORD_TYPE){.U=UINT32_C(0x7f7fffff)}
#define     WORD_NINF   (WORD_TYPE){.U=UINT32_C(0xff800000)}
#define     WORD_PINF   (WORD_TYPE){.U=UINT32_C(0x7f800000)}
#define     WORD_QNAN   (WORD_TYPE){.U=UINT32_C(0x7fc00000)}

#define     WORD_TGXINT(_) \
XWU_TYPE:XWU_TGNAME(_),\
XWI_TYPE:XWI_TGNAME(_),

#define     WORD_TGXFLT(_) \
XWF_TYPE:XWF_TGNAME(_),

#define WORD_TGX(_) WORD_TGXINT(_) WORD_TGXFLT(_)

#define     DWRD_(_)            DWRD_ ## _
#define     DWRD_F              DBL_
#define     DWRD_FTYPE          double

#define     DWRD_XU             XDU_
#define     DWRD_XI             XDI_
#define     DWRD_XF             XDF_
#define     DWRD_XTYPE          union Xd
#define     DWRD_XUTYPE         struct Xdu
#define     DWRD_XITYPE         struct Xdi
#define     DWRD_XFTYPE         struct Xdf
#define     DWRD_SN(_)          _ ## d
#define     DWRD_SNU(_)         MY_TGSN(_,DWRD_U(SN))
#define     DWRD_SNI(_)         MY_TGSN(_,DWRD_I(SN))
#define     DWRD_SNF(_)         MY_TGSN(_,DWRD_F(SN))

#define     DWRD_TYPE           union Dwrd
#define     DWRD_LOG2SZ         (3)
#define     DWRD_SIZE           (2*WORD_SIZE)
#define     DWRD_WIDTH          NDIG_C(64)
#define     DWRD_UDIG           NDIG_C(20)  // "18446744073709551615"
#define     DWRD_IDIG           NDIG_C(20)  // "-9223372036854775808"
#define     DWRD_FDIG           NDIG_C(15)
#define     DWRD_XDIG           NDIG_C(16)  // "7fffffffffffffff"
#define     DWRD_UMAX   (DWRD_TYPE){.U=DWRD_U(MAX)}
#define     DWRD_IMAX   (DWRD_TYPE){.I=DWRD_I(MAX)}
#define     DWRD_IMIN   (DWRD_TYPE){.I=DWRD_I(MIN)}
#define     DWRD_NMIN   (DWRD_TYPE){.U=UINT64_C(0x8010000000000000)}
#define     DWRD_PMIN   (DWRD_TYPE){.U=UINT64_C(0x0010000000000000)}
#define     DWRD_NMAX   (DWRD_TYPE){.U=UINT64_C(0xffefffffffffffff)}
#define     DWRD_PMAX   (DWRD_TYPE){.U=UINT64_C(0x7fefffffffffffff)}
#define     DWRD_NINF   (DWRD_TYPE){.U=UINT64_C(0xfff0000000000000)}
#define     DWRD_PINF   (DWRD_TYPE){.U=UINT64_C(0x7ff0000000000000)}
#define     DWRD_QNAN   (DWRD_TYPE){.U=UINT64_C(0x7ff8000000000000)}

#define     DWRD_TGXINT(_)      \
XDU_TYPE:XDU_TGNAME(_),\
XDI_TYPE:XDI_TGNAME(_),

#define     DWRD_TGXFLT(_)     \
XDF_TYPE:XDF_TGNAME(_),

#define DWRD_TGX(_) DWRD_TGXINT(_) DWRD_TGXFLT(_)


#define     QUAD_(_)            QUAD_ ## _
#define     QUAD_SN(_)          _ ## q

#define     QUAD_SNU(_) MY_TGSN(_,QUAD_U(SN))
#define     QUAD_SNI(_) MY_TGSN(_,QUAD_I(SN))
#define     QUAD_SNF(_) MY_TGSN(_,QUAD_F(SN))

#define     QUAD_TYPE           union Quad
#define     QUAD_F              FLT128_
#define     QUAD_LOG2SZ         (4)
#define     QUAD_SIZE           (4*WORD_SIZE)
#define     QUAD_WIDTH          NDIG_C(128)
// "-170141183460469231731687303715884105728"
// "340282366920938463463374607431768211455"
#define     QUAD_IDIG           NDIG_C(40)
#define     QUAD_UDIG           NDIG_C(39)
#define     QUAD_FDIG           NDIG_C(33)
#define     QUAD_IMIN   (QUAD_TYPE){.I=QUAD_I(MIN)}
#define     QUAD_IMAX   (QUAD_TYPE){.I=QUAD_I(MAX)}
#define     QUAD_UMAX   (QUAD_TYPE){.I=QUAD_U(MAX)}
#define     QUAD_NMIN   (QUAD_TYPE)     \
{                                       \
    .Lo=UINT64_C(0x0000000000000000),   \
    .Hi=UINT64_C(0x8001000000000000),   \
}

#define     QUAD_PMIN   (QUAD_TYPE)     \
{                                       \
    .Lo=UINT64_C(0x0000000000000000),   \
    .Hi=UINT64_C(0x0001000000000000),   \
}

#define     QUAD_NMAX   (QUAD_TYPE)     \
{                                       \
    .Lo=UINT64_C(0xffffffffffffffff),   \
    .Hi=UINT64_C(0xfffeffffffffffff),   \
}

#define     QUAD_PMAX   (QUAD_TYPE)     \
{                                       \
    .Lo=UINT64_C(0xffffffffffffffff),   \
    .Hi=UINT64_C(0x7ffeffffffffffff),   \
}

#define     QUAD_NINF   (QUAD_TYPE)     \
{                                       \
    .Lo=UINT64_C(0x0000000000000000),   \
    .Hi=UINT64_C(0xffff000000000000)    \
}

#define     QUAD_PINF   (QUAD_TYPE)     \
{                                       \
    .Lo=UINT64_C(0x0000000000000000),   \
    .Hi=UINT64_C(0x7fff000000000000),   \
}

#define     QUAD_QNAN   (QUAD_TYPE)     \
{                                       \
    .Lo=UINT64_C(0x0000000000000000),   \
    .Hi=UINT64_C(0x7fff800000000000),   \
}

#define     QUAD_TGXINT(_)      \
XQU_TYPE:XQU_TGNAME(_),    \
XQI_TYPE:XQI_TGNAME(_),

#define     QUAD_TGXFLT(_) \
XQF_TYPE:XQF_TGNAME(_),

#define     QUAD_TGX(_) QUAD_TGXINT(_) QUAD_TGXFLT(_)


#define     OCTA_(_)            OCTA_ ## _
#define     OCTA_LOG2SZ         (5)
#define     OCTA_SIZE           (8*WORD_SIZE)
#define     OCTA_WIDTH          (BYTE_WIDTH<<OCTA_LOG2SZ)

#define     OCTA_BU             VOBU_
#define     OCTA_BI             VOBI_

#define     OCTA_HU             VOHU_
#define     OCTA_HI             VOHI_
#define     OCTA_HF             VOHF_

#define     OCTA_WU             VOWU_
#define     OCTA_WI             VOWI_
#define     OCTA_WF             VOWF_

#define     OCTA_DU             VODU_
#define     OCTA_DI             VODI_
#define     OCTA_DF             VODF_
#define     OCTA_NLONG          (DWRD_NLONG<<2)
#define     OCTA_TGNAME(_)      _ ## o

#define     SEXD_(_)            SEXD_##_
#define     SEXD_LOG2SZ         (6)

#define     XHU_(_)             XHU_ ## _
#define     XHU_SN(_)           _ ## xhu
#define     XHU_TYPE            struct Xhu
#define     XHU_STG             HALF_

#define     XHI_(_)             XHI_ ## _
#define     XHI_SN(_)           _ ## xhi
#define     XHI_TYPE            struct Xhi
#define     XHI_STG             HALF_

#define     XHF_(_)             XHF_ ## _
#define     XHF_SN(_)           _ ## xhf
#define     XHF_TYPE            struct Xhf
#define     XHF_STG             HALF_


#define     XWU_(_)             XWU_ ## _
#define     XWU_SN(_)           _ ## xwu
#define     XWU_TYPE            struct Xwu
#define     XWU_STG             WORD_

#define     XWI_(_)             XWI_ ## _
#define     XWI_SN(_)           _ ## xwi
#define     XWI_TYPE            struct Xwi
#define     XWI_STG             WORD_

#define     XWF_(_)             XWF_ ## _
#define     XWF_SN(_)           _ ## xwf
#define     XWF_TYPE            struct Xwf
#define     XWF_STG             WORD_


#define     XDU_(_)             XDU_ ## _
#define     XDU_SN(_)           _ ## xdu
#define     XDU_TYPE            struct Xdu
#define     XDU_STG             DWRD_

#define     XDI_(_)             XDI_ ## _
#define     XDI_SN(_)           _ ## xdi
#define     XDI_TYPE            struct Xdi
#define     XDI_STG             DWRD_

#define     XDF_(_)             XDF_ ## _
#define     XDF_SN(_)           _ ## xdf
#define     XDF_TYPE            struct Xdf
#define     XDF_STG             DWRD_



#define     XQU_(_)             XQU_ ## _
#define     XQU_SN(_)           _ ## xqu
#define     XQU_TYPE            struct Xqu
#define     XQU_STG             QUAD_

#define     XQI_(_)             XQI_ ## _
#define     XQI_SN(_)           _ ## xqi
#define     XQI_TYPE            struct Xqi
#define     XQI_STG             QUAD_

#define     XQF_(_)             XQF_ ## _
#define     XQF_SN(_)           _ ## xqf
#define     XQF_TYPE            struct Xqf
#define     XQF_STG             QUAD_

#define     DWRD_NLONG          (1+ (LONG_MAX== INT_MAX))
#define     QUAD_NLONG          (2*DWRD_NLONG)
#define     QUAD_NLLONG         (1+(LLONG_MAX==LONG_MAX))

#if QUAD_NLONG == 4

#   define  _Int32x             long int

#   define  LONG_SN(_)          _ ## li
#   define  LONG_STG            WORD_

#   define  ULONG_SN(_)         _ ## lu
#   define  ULONG_STG           WORD_

#   define  LLONG_SN            INT64_SN
#   define  LLONG_STG           DWRD_

#   define  LLONG_SN            INT64_SN
#   define  ULLONG_STG          DWRD_

#   define  INT32X_(_)          INT32X_ ## _
#   define  INT32X_TYPE         _Int32x
#   define  INT32X_BASE         LONG_
#   define  INT32X_SN           INT32X_BASE(SN)
#   define  INT32X_STG          INT32X_BASE(STG)
#   define  INT32X_MAX          INT32X_BASE(MAX)
#   define  INT32X_MIN          INT32X_BASE(MIN)
#   define  INT32X_SIZE         INT32X_BASE(SIZE)
#   define  INT32X_WIDTH        INT32X_BASE(WIDTH)
#   define  INT32X_DIG          INT32X_BASE(DIG)
#   define  INT32X_SIGNEDNESS   INT32X_BASE(SIGNEDNESS)
#   define  INT32X_DFMT         INT32X_BASE(DFMT)
#   define  INT32X_C(C)         C ## L

#   define  UINT32X_(_)         UINT32X_ ## _
#   define  UINT32X_TYPE        unsigned _Int32x
#   define  UINT32X_BASE        ULONG_
#   define  UINT32X_SN          UINT32X_BASE(SN)
#   define  UINT32X_STG         UINT32X_BASE(STG)
#   define  UINT32X_SIZE        UINT32X_BASE(SIZE)
#   define  UINT32X_WIDTH       UINT32X_BASE(WIDTH)
#   define  UINT32X_DIG         UINT32X_BASE(DIG)
#   define  UINT32X_ODIG        UINT32X_BASE(ODIG)
#   define  UINT32X_XDIG        UINT32X_BASE(XDIG)
#   define  UINT32X_SIGNEDNESS  UINT32X_BASE(SIGNEDNESS)

#   define  UINT32X_DFMT        UINT32X_BASE(DFMT)
#   define  UINT32X_OFMT        UINT32X_BASE(OFMT)
#   define  UINT32X_XFMT        UINT32X_BASE(XFMT)
#   define  UINT32X_UFMT        UINT32X_BASE(UFMT)
#   define  UINT32X_C(C)        C ## UL

#   define  WORD_LI             LONG_
#   define  WORD_LU             ULONG_
#   define  WORD_LITYPE         long
#   define  WORD_LUTYPE         unsigned long
#   define  WORD_LTYPE          union Wl

#   define  DWRD_I              LLONG_
#   define  DWRD_U              ULLONG_
#   define  DWRD_ITYPE          long long
#   define  DWRD_UTYPE          unsigned long long

#elif QUAD_NLLONG == 2

#   define  _Int64x             long long int

#   define  LONG_SN             INT64_SN
#   define  LONG_STG            DWRD_

#   define  ULONG_SN            UINT64_SN
#   define  ULONG_STG           DWRD_

#   define  LLONG_SN(_)         _ ## li
#   define  LLONG_STG           DWRD_

#   define  ULLONG_SN(_)        _ ## lu
#   define  ULLONG_STG          DWRD_

#   define  INT64X_(_)          INT64X_ ## _
#   define  INT64X_BASE         LONG_
#   define  INT64X_TYPE         _Int64x
#   define  INT64X_STG          INT64X_BASE(STG)
#   define  INT64X_MAX          INT64X_BASE(MAX)
#   define  INT64X_MIN          INT64X_BASE(MIN)
#   define  INT64X_SIZE         INT64X_BASE(SIZE)
#   define  INT64X_WIDTH        INT64X_BASE(WIDTH)
#   define  INT64X_DIG          INT64X_BASE(DIG)
#   define  INT64X_SIGNEDNESS   INT64X_BASE(SIGNEDNESS)
#   define  INT64X_DFMT         "li"
#   define  INT64X_C(C)         C ## LL

#   define  UINT64X_(_)         UINT64X_ ## _
#   define  UINT64X_BASE        ULONG_
#   define  UINT64X_TYPE        unsigned _Int64x
#   define  UINT64X_SN          UINT64X_BASE(SN)
#   define  UINT64X_STG         UINT64X_BASE(STG)
#   define  UINT64X_SIZE        UINT64X_BASE(SIZE)
#   define  UINT64X_WIDTH       UINT64X_BASE(WIDTH)
#   define  UINT64X_DIG         UINT64X_BASE(DIG)
#   define  UINT64X_ODIG        UINT64X_BASE(ODIG)
#   define  UINT64X_XDIG        UINT64X_BASE(XDIG)
#   define  UINT64X_SIGNEDNESS  UINT64X_BASE(SIGNEDNESS)
#   define  UINT64X_DFMT        UINT64X_BASE(DFMT)
#   define  UINT64X_OFMT        UINT64X_BASE(OFMT)
#   define  UINT64X_DFMT        UINT64X_BASE(DFMT)
#   define  UINT64X_XFMT        UINT64X_BASE(XFMT)
#   define  UINT64X_UFMT        UINT64X_BASE(UFMT)
#   define  UINT64X_C(C)        C ## ULL

#   define  DWRD_I              LONG_
#   define  DWRD_LI             LLONG_
#   define  DWRD_U              ULONG_
#   define  DWRD_LU             ULLONG_
#   define  DWRD_ITYPE          long
#   define  DWRD_LITYPE         long long
#   define  DWRD_UTYPE          unsigned long
#   define  DWRD_LUTYPE         unsigned long long
#   define  DWRD_LTYPE          union Dl

#else

#   define  LONG_SN             INT64_SN
#   define  ULONG_SN            UINT64_SN

#   define  LONG_STG            DWRD_
#   define  ULONG_STG           DWRD_

#   define  LLONG_STG           QUAD_
#   define  ULLONG_STG          QUAD_

#   define  DWRD_I              LONG_
#   define  DWRD_U              ULONG_
#   define  DWRD_ITYPE          long
#   define  DWRD_UTYPE          unsigned long

#   define  QUAD_I              LLONG_
#   define  QUAD_U              ULLONG_
#   define  QUAD_ITYPE          long long
#   define  QUAD_UTYPE          unsigned long long
#endif

#if defined(__SIZEOF_INT128__) && (QUAD_NLLONG==2)

#   define  INT128X_(_)         INT128X_ ## _
#   define  INT128X_TYPE        __int128
#   define  INT128X_STG         QUAD_
#   define  INT128X_SN(_)      _ ## qi

#   define  UINT128X_(_)        UINT128X_ ## _
#   define  UINT128X_TYPE       unsigned __int128
#   define  UINT128X_STG        QUAD_
#   define  UINT128X_SN(_)      _ ## qu

#   define  QUAD_I              INT128X_
#   define  QUAD_U              UINT128X_
#   define  QUAD_ITYPE          __int128
#   define  QUAD_UTYPE          unsigned __int128
#endif

#ifndef QUAD_I
#   define  QUAD_I              XQI_
#   define  QUAD_U              XQU_
#   define  QUAD_ITYPE          struct Xqi
#   define  QUAD_UTYPE          struct Xqu
#endif

#define     BOOL_(_)            BOOL_ ## _
#define     BOOL_SN(_)          _ ## y
#define     BOOL_TYPE           bool
#define     BOOL_WIDTH          NDIG_C(1)


#define     CHAR_(_)            CHAR_ ## _
#define     CHAR_SN(_)          _ ## bc
#define     CHAR_TYPE           char
#define     CHAR_STG            BYTE_
#define     CHAR_SIZE           CHAR_STG(SIZE)
#define     CHAR_WIDTH          CHAR_STG(WIDTH)
#define     CHAR_SIGNEDNESS     (0!=CHAR_MIN)
#define     CHAR_C(C)           #C


#define     UCHAR_(_)           UCHAR_ ## _
#define     UCHAR_SN(_)         _ ## bu
#define     UCHAR_STG           BYTE_
#define     UCHAR_SIZE          UCHAR_STG(SIZE)
#define     UCHAR_WIDTH         UCHAR_STG(WIDTH)
#define     UCHAR_DIG           UCHAR_STG(UDIG)
#define     UCHAR_ODIG          UCHAR_STG(ODIG)
#define     UCHAR_XDIG          UCHAR_STG(XDIG)
#define     UCHAR_SIGNEDNESS    (0)
#define     UCHAR_OFMT          "hho"
#define     UCHAR_DFMT          "hhu"
#define     UCHAR_XFMT          "hhx"
#define     UCHAR_UFMT          "hhX"
#if defined(_MSC_VER)
#   define  UCHAR_C(C)          C ## ui8
#else
#   define  UCHAR_C(C)          (C&255)
#endif

#define     SCHAR_(_)           SCHAR_ ## _
#define     SCHAR_SN(_)         _ ## bi
#define     SCHAR_STG           BYTE_
#define     SCHAR_SIZE          SCHAR_STG(SIZE)
#define     SCHAR_WIDTH         SCHAR_STG(WIDTH)
#define     SCHAR_DIG           SCHAR_STG(IDIG)
#define     SCHAR_SIGNEDNESS    (1)
#define     SCHAR_DFMT          "hhi"
#ifndef  SCHAR_C // [1] => [2]
#if defined(_MSC_VER) // [2] => [3]
#   define  SCHAR_C(C)          C ## i8
#else
#   define  SCHAR_C(C)          (C&255)
#endif // [3] => [2]
#endif // [2] => [1]

#if CHAR_SIGNEDNESS && defined(_MSC_VER)
#   define SCHAR_TYPE           char
#elif defined(_MSC_VER)
#   define UCHAR_TYPE           char
#endif

#ifndef SCHAR_TYPE
#define SCHAR_TYPE              signed char
#endif

#ifndef UCHAR_TYPE
#define UCHAR_TYPE              unsigned char
#endif


#define     USHRT_(_)           USHRT_ ## _
#define     USHRT_SN(_)         _ ## hu
#define     USHRT_TYPE          unsigned short
#define     USHRT_STG           HALF_
#define     USHRT_SIZE          USHRT_STG(SIZE)
#define     USHRT_WIDTH         USHRT_STG(WIDTH)
#define     USHRT_DIG           USHRT_STG(UDIG)
#define     USHRT_ODIG          USHRT_STG(ODIG)
#define     USHRT_XDIG          USHRT_STG(XDIG)
#define     USHRT_SIGNEDNESS    (0)
#define     USHRT_OFMT          "ho"
#define     USHRT_DFMT          "hu"
#define     USHRT_XFMT          "hx"
#define     USHRT_UFMT          "hX"
#ifndef  USHRT_C
#if defined(_MSC_VER)
#   define  USHRT_C(C)          C ## ui16
#else
#   define  USHRT_C(C)          (C&65535)
#endif
#endif

#define     SHRT_(_)            SHRT_ ## _
#define     SHRT_SN(_)          _ ## hi
#define     SHRT_TYPE           short
#define     SHRT_(_)            SHRT_ ## _
#define     SHRT_STG            HALF_
#define     SHRT_SIZE           SHRT_STG(SIZE)
#define     SHRT_WIDTH          SHRT_STG(WIDTH)
#define     SHRT_DIG            SHRT_STG(IDIG)
#define     SHRT_SIGNEDNESS     (1)
#define     SHRT_TGNAME(_)      _ ## hi
#define     SHRT_DFMT           "hi"
#ifndef  SHRT_C
#if defined(_MSC_VER)
#   define  SHRT_C(C)           C ## i16
#else
#   define  SHRT_C(C)           (C&65535)
#endif
#endif

#define     UINT_(_)            UINT_ ## _
#define     UINT_SN(_)          _ ## wu
#define     UINT_TYPE           unsigned int
#define     UINT_STG            WORD_
#define     UINT_SIZE           UINT_STG(SIZE)
#define     UINT_WIDTH          UINT_STG(WIDTH)
#define     UINT_DIG            UINT_STG(UDIG)
#define     UINT_ODIG           UINT_STG(ODIG)
#define     UINT_XDIG           UINT_STG(XDIG)
#define     UINT_SIGNEDNESS     (0)
#define     UINT_C(C)           C ## U
#define     UINT_OFMT           "o"
#define     UINT_DFMT           "u"
#define     UINT_XFMT           "x"
#define     UINT_UFMT           "X"

#define     INT_(_)             INT_ ## _
#define     INT_SN(_)           _ ## wi
#define     INT_TYPE            int
#define     INT_STG             WORD_
#define     INT_SIZE            INT_STG(SIZE)
#define     INT_WIDTH           INT_STG(WIDTH)
#define     INT_DIG             INT_STG(IDIG)
#define     INT_SIGNEDNESS      (1)
#define     INT_DFMT            "i"
#define     INT_C(C)            C


#define     ULONG_(_)           ULONG_ ## _
#define     ULONG_TYPE          unsigned long
#define     ULONG_SIZE          ULONG_STG(SIZE)
#define     ULONG_WIDTH         ULONG_STG(WIDTH)
#define     ULONG_DIG           ULONG_STG(UDIG)
#define     ULONG_ODIG          ULONG_STG(ODIG)
#define     ULONG_XDIG          ULONG_STG(XDIG)
#define     ULONG_SIGNEDNESS    (0)
#define     ULONG_OFMT          "lo"
#define     ULONG_DFMT          "lu"
#define     ULONG_XFMT          "lx"
#define     ULONG_UFMT          "lX"
#define     ULONG_C(C)          C ## UL


#define     LONG_(_)            LONG_ ## _
#define     LONG_TYPE           long
#define     LONG_SIZE           LONG_STG(SIZE)
#define     LONG_WIDTH          LONG_STG(WIDTH)
#define     LONG_DIG            LONG_STG(IDIG)
#define     LONG_SIGNEDNESS     (1)
#define     LONG_DFMT           "li"
#define     LONG_C(C)           C ## L


#define     ULLONG_(_)          ULLONG_ ## _
#define     ULLONG_TYPE         unsigned long long
#define     ULLONG_SIZE         ULLONG_STG(SIZE)
#define     ULLONG_WIDTH        ULLONG_STG(WIDTH)
#define     ULLONG_DIG          ULLONG_STG(UDIG)
#define     ULLONG_ODIG         ULLONG_STG(ODIG)
#define     ULLONG_XDIG         ULLONG_STG(XDIG)
#define     ULLONG_OFMT         "llo"
#define     ULLONG_DFMT         "llu"
#define     ULLONG_XFMT         "llx"
#define     ULLONG_UFMT         "llX"
#define     ULLONG_SIGNEDNESS   (0)
#define     ULLONG_C(C)         C ## ULL

#define     LLONG_(_)           LLONG_ ## _
#define     LLONG_TYPE          long long
#define     LLONG_SIZE          LLONG_STG(SIZE)
#define     LLONG_WIDTH         LLONG_STG(WIDTH)
#define     LLONG_DIG           LLONG_STG(IDIG)
#define     LLONG_SIGNEDNESS    (1)
#define     LLONG_DFMT          "lli"
#define     LLONG_C(C)          C ## LL


#define     UINT8_(_)           UINT8_ ## _
#define     UINT8_SN(_)         _ ## bu
#define     UINT8_TYPE          uint8_t
#define     UINT8_STG           BYTE_
#define     UINT8_BASE          UINT8_STG(U)
#define     UINT8_SIZE          UINT8_BASE(SIZE)
#define     UINT8_WIDTH         UINT8_BASE(WIDTH)
#define     UINT8_DIG           UINT8_BASE(DIG)
#define     UINT8_ODIG          UINT8_BASE(ODIG)
#define     UINT8_XDIG          UINT8_BASE(XDIG)
#define     UINT8_SIGNEDNESS    UINT8_BASE(SIGNEDNESS)
#define     UINT8_DFMT          UINT8_BASE(DFMT)
#define     UINT8_OFMT          UINT8_BASE(OFMT)
#define     UINT8_XFMT          UINT8_BASE(XFMT)
#define     UINT8_UFMT          UINT8_BASE(UFMT)

#define     INT8_(_)            INT8_ ## _
#define     INT8_SN(_)          _ ## bi
#define     INT8_TYPE           int8_t
#define     INT8_STG            BYTE_
#define     INT8_BASE           INT8_STG(I)
#define     INT8_SIZE           INT8_BASE(SIZE)
#define     INT8_WIDTH          INT8_BASE(WIDTH)
#define     INT8_DIG            INT8_BASE(DIG)
#define     INT8_ODIG           INT8_BASE(ODIG)
#define     INT8_XDIG           INT8_BASE(XDIG)
#define     INT8_SIGNEDNESS     INT8_BASE(SIGNEDNESS)


#define     UINT16_(_)          UINT16_ ## _
#define     UINT16_SN(_)        _ ## hu
#define     UINT16_TYPE         uint16_t
#define     UINT16_STG          HALF_
#define     UINT16_BASE         UINT16_STG(U)
#define     UINT16_DFMT         UINT16_BASE(DFMT)
#define     UINT16_OFMT         UINT16_BASE(OFMT)
#define     UINT16_XFMT         UINT16_BASE(XFMT)
#define     UINT16_UFMT         UINT16_BASE(UFMT)
#define     UINT16_SIZE         UINT16_BASE(SIZE)
#define     UINT16_WIDTH        UINT16_BASE(WIDTH)
#define     UINT16_DIG          UINT16_BASE(DIG)
#define     UINT16_ODIG         UINT16_BASE(ODIG)
#define     UINT16_XDIG         UINT16_BASE(XDIG)
#define     UINT16_SIGNEDNESS   UINT16_BASE(SIGNEDNESS)
#define     UINT16_DFMT         UINT16_BASE(DFMT)
#define     UINT16_OFMT         UINT16_BASE(OFMT)
#define     UINT16_XFMT         UINT16_BASE(XFMT)
#define     UINT16_UFMT         UINT16_BASE(UFMT)

#define     INT16_(_)           INT16_ ## _
#define     INT16_SN(_)         _ ## hi
#define     INT16_TYPE          int16_t
#define     INT16_STG           HALF_
#define     INT16_BASE          INT16_STG(I)
#define     INT16_SIZE          INT16_BASE(SIZE)
#define     INT16_WIDTH         INT16_BASE(WIDTH)
#define     INT16_DIG           INT16_BASE(DIG)
#define     INT16_ODIG          INT16_BASE(ODIG)
#define     INT16_XDIG          INT16_BASE(XDIG)
#define     INT16_SIGNEDNESS    INT16_BASE(SIGNEDNESS)


#define     UINT32_(_)          UINT32_ ## _
#define     UINT32_SN(_)        _ ## wu
#define     UINT32_TYPE         uint32_t
#define     UINT32_STG          WORD_
#define     UINT32_BASE         UINT32_STG(U)
#define     UINT32_DFMT         UINT32_BASE(DFMT)
#define     UINT32_OFMT         UINT32_BASE(OFMT)
#define     UINT32_XFMT         UINT32_BASE(XFMT)
#define     UINT32_UFMT         UINT32_BASE(UFMT)
#define     UINT32_SIZE         UINT32_BASE(SIZE)
#define     UINT32_WIDTH        UINT32_BASE(WIDTH)
#define     UINT32_DIG          UINT32_BASE(DIG)
#define     UINT32_ODIG         UINT32_BASE(ODIG)
#define     UINT32_XDIG         UINT32_BASE(XDIG)
#define     UINT32_SIGNEDNESS   UINT32_BASE(SIGNEDNESS)
#define     UINT32_DFMT         UINT32_BASE(DFMT)
#define     UINT32_OFMT         UINT32_BASE(OFMT)
#define     UINT32_XFMT         UINT32_BASE(XFMT)
#define     UINT32_UFMT         UINT32_BASE(UFMT)

#define     INT32_(_)           INT32_ ## _
#define     INT32_SN(_)         _ ## wi
#define     INT32_TYPE          int32_t
#define     INT32_STG           WORD_
#define     INT32_BASE          INT32_STG(I)
#define     INT32_SIZE          INT32_BASE(SIZE)
#define     INT32_WIDTH         INT32_BASE(WIDTH)
#define     INT32_DIG           INT32_BASE(DIG)
#define     INT32_ODIG          INT32_BASE(ODIG)
#define     INT32_XDIG          INT32_BASE(XDIG)
#define     INT32_SIGNEDNESS    INT32_BASE(SIGNEDNESS)

#define     UINT64_(_)          UINT64_ ## _
#define     UINT64_SN(_)        _ ## du
#define     UINT64_TYPE         uint64_t
#define     UINT64_STG          DWRD_
#define     UINT64_BASE         UINT64_STG(U)
#define     UINT64_DFMT         UINT64_BASE(DFMT)
#define     UINT64_OFMT         UINT64_BASE(OFMT)
#define     UINT64_XFMT         UINT64_BASE(XFMT)
#define     UINT64_UFMT         UINT64_BASE(UFMT)
#define     UINT64_SIZE         UINT64_BASE(SIZE)
#define     UINT64_WIDTH        UINT64_BASE(WIDTH)
#define     UINT64_DIG          UINT64_BASE(DIG)
#define     UINT64_ODIG         UINT64_BASE(ODIG)
#define     UINT64_XDIG         UINT64_BASE(XDIG)
#define     UINT64_SIGNEDNESS   UINT64_BASE(SIGNEDNESS)
#define     UINT64_DFMT         UINT64_BASE(DFMT)
#define     UINT64_OFMT         UINT64_BASE(OFMT)
#define     UINT64_XFMT         UINT64_BASE(XFMT)
#define     UINT64_UFMT         UINT64_BASE(UFMT)

#define     INT64_(_)           INT64_ ## _
#define     INT64_SN(_)         _ ## di
#define     INT64_TYPE          int64_t
#define     INT64_STG           DWRD_
#define     INT64_BASE          INT64_STG(I)
#define     INT64_SIZE          INT64_BASE(SIZE)
#define     INT64_WIDTH         INT64_BASE(WIDTH)
#define     INT64_DIG           INT64_BASE(DIG)
#define     INT64_ODIG          INT64_BASE(ODIG)
#define     INT64_XDIG          INT64_BASE(XDIG)
#define     INT64_SIGNEDNESS    INT64_BASE(SIGNEDNESS)


#define     UINT128_(_)         UINT128_ ## _
#define     UINT128_SN(_)       _ ## qu
#define     UINT128_TYPE        uint128_t
#define     UINT128_STG         QUAD_
#define     UINT128_BASE        UINT128_STG(U)
#define     UINT128_DFMT        UINT128_BASE(DFMT)
#define     UINT128_OFMT        UINT128_BASE(OFMT)
#define     UINT128_XFMT        UINT128_BASE(XFMT)
#define     UINT128_UFMT        UINT128_BASE(UFMT)
#define     UINT128_SIZE        UINT128_BASE(SIZE)
#define     UINT128_WIDTH       UINT128_BASE(WIDTH)
#define     UINT128_DIG         UINT128_BASE(DIG)
#define     UINT128_ODIG        UINT128_BASE(ODIG)
#define     UINT128_XDIG        UINT128_BASE(XDIG)
#define     UINT128_SIGNEDNESS  UINT128_BASE(SIGNEDNESS)
#define     UINT128_DFMT        UINT128_BASE(DFMT)
#define     UINT128_OFMT        UINT128_BASE(OFMT)
#define     UINT128_XFMT        UINT128_BASE(XFMT)
#define     UINT128_UFMT        UINT128_BASE(UFMT)

#define     INT128_(_)          INT128_ ## _
#define     INT128_SN(_)        _ ## qi
#define     INT128_TYPE         int128_t
#define     INT128_STG          QUAD_
#define     INT128_BASE         INT128_STG(I)
#define     INT128_SIZE         INT128_BASE(SIZE)
#define     INT128_WIDTH        INT128_BASE(WIDTH)
#define     INT128_DIG          INT128_BASE(DIG)
#define     INT128_ODIG         INT128_BASE(ODIG)
#define     INT128_XDIG         INT128_BASE(XDIG)
#define     INT128_SIGNEDNESS   INT128_BASE(SIGNEDNESS)

#ifndef SIZE_MAX
#error "SIZE_MAX is gone"
#elif  (SIZE_MAX>>15) == 1
#   define  ADDR_STG            HALF_
#   define  QUAD_NPTR   8
#   define  DWRD_NPTR   4
#   define  WORD_NPTR   2
#   define  HALF_NPTR   1
#elif (SIZE_MAX>>31) == 1
#   define  ADDR_STG            WORD_
#   define  QUAD_NPTR   4
#   define  DWRD_NPTR   2
#   define  WORD_NPTR   1
#   define  HALF_NPTR   0
#elif (SIZE_MAX>>63) == 1
#   define  ADDR_STG            DWRD_
#   define  QUAD_NPTR   2
#   define  DWRD_NPTR   1
#   define  WORD_NPTR   0
#   define  HALF_NPTR   0

#elif (SIZE_MAX>>64) == LONG_MAX
#   define  ADDR_STG            QUAD_
#   define  QUAD_NPTR   1
#   define  DWRD_NPTR   0
#   define  WORD_NPTR   0
#   define  HALF_NPTR   0
#else
#   error "invalid value of SIZE_MAX"
#endif

#define     ADDR_SN(_)          _ ## a
#define     ADDR_I              ADDR_STG(I)
#define     ADDR_U              ADDR_STG(U)
#define     ADDR_SIZE           ADDR_STG(SIZE)
#define     ADDR_WIDTH          ADDR_STG(WIDTH)
#define     ADDR_DEC            ADDR_STG(WIDTH)
#define     ADDR_UDIG           ADDR_STG(UDIG)
#define     ADDR_IDIG           ADDR_STG(IDIG)
#define     ADDR_XDIG           ADDR_STG(XDIG)
#define     ADDR_ODIG           ADDR_STG(ODIG)

#define     ADDR_FMTP           "p"

#define     UINTPTR_(_)         UINTPTR_ ## _
#define     UINTPTR_TYPE        uintptr_t
#define     UINTPTR_BASE        ADDR_U
#define     UINTPTR_STG         ADDR_STG
#define     UINTPTR_SIZE        ADDR_SIZE
#define     UINTPTR_WIDTH       ADDR_WIDTH
#define     UINTPTR_DIG         ADDR_UDIG
#define     UINTPTR_XDIG        ADDR_XDIG
#define     UINTPTR_ODIG        ADDR_STG(ODIG)
#define     UINTPTR_SIGNEDNESS  (0)
#define     UINTPTR_TGNAME      ADDR_U(TGNAME)
#ifndef     UINTPTR_C
#define     UINTPTR_C           ADDR_U(C)
#endif

#define     INTPTR_(_)          INTPTR_ ## _
#define     INTPTR_BASE         ADDR_I
#define     INTPTR_TYPE         intptr_t
#define     INTPTR_STG          ADDR_STG
#define     INTPTR_SIZE         ADDR_SIZE
#define     INTPTR_WIDTH        ADDR_WIDTH
#define     INTPTR_DIG          ADDR_DIG
#define     INTPTR_SIGNEDNESS   (1)
#define     INTPTR_TGNAME(_)    ADDR_I(TGNAME)
#ifndef     INTPTR_C
#define     INTPTR_C            ADDR_I(C)
#endif

#define     SIZE_(_)            SIZE_ ## _
#define     SIZE_BASE           ADDR_U
#define     SIZE_TYPE           size_t
#define     SIZE_STG            ADDR_STG
#define     SIZE_SIZE           ADDR_SIZE
#define     SIZE_WIDTH          ADDR_WIDTH
#define     SIZE_DIG            ADDR_DIG
#define     SIZE_XDIG           ADDR_XDIG
#define     SIZE_ODIG           ADDR_ODIG
#define     SIZE_FMTO           "zo"
#define     SIZE_FMTD           "zd"
#define     SIZE_FMTX           "zx"
#define     SIZE_SIGNEDNESS     (0)
#define     SIZE_TGNAME         ADDR_U(TGNAME)
#ifndef     SIZE_C
#define     SIZE_C              ADDR_U(C)
#endif

#define     PTRDIFF(_)          PTRDIFF_ ## _
#define     PTRDIFF_BASE        ADDR_I
#define     PTRDIFF_TYPE        ptrdiff_t
#define     PTRDIFF_STG         ADDR_STG
#define     PTRDIFF_SIZE        ADDR_SIZE
#define     PTRDIFF_WIDTH       ADDR_WIDTH
#define     PTRDIFF_DIG         ADDR_DIG
#define     PTRDIFF_SIGNEDNESS  (1)
#define     PTRDIFF_TGNAME(_)   ADDR_I(TGNAME)
#define     PTRDIFF_FMTO        "to"
#define     PTRDIFF_FMTD        "ti"
#define     PTRDIFF_FMTX        "tx"
#define     PTRDIFF_FMTU        "tX"
#ifndef     PTRDIFF_C
#define     PTRDIFF_C           ADDR_I(C)
#endif

#if defined(__ARM_FP16_ARGS)
#   define  HFLT_TYPE           __fp16
#elif defined(FLT16_MAX)
#   define  HFLT_TYPE           _Float16
#endif

#if defined(HFLT_TYPE)
#   define  HFLT_(_)            HFLT_ ## _
#   define  HFLT_SN             FLT16_SN
#   define  HFLT_STG            HALF_
#   define  HFLT_SIZE           HFLT_STG(SIZE)
#   define  HFLT_WIDTH          HFLT_STG(WIDTH)
#   define  HFLT_SIGNEDNESS     (1)
#   define  HFLT_C(C)           C ## f16
#   define  FLT16_BASE          HFLT_
#else
#   define  FLT16_BASE          XHF_
#endif

#define     FLT16_(_)           FLT16_ ## _
#define     FLT16_SN(_)         _ ## hf
#define     FLT16_TYPE          flt16_t
#define     FLT16_STG           FLT16_BASE(STG)
#define     FLT16_SIZE          FLT16_BASE(SIZE)
#define     FLT16_WIDTH         FLT16_BASE(WIDTH)
#define     FLT16_SIGNEDNESS    FLT16_BASE(SIGNEDNESS)
#if defined(FLT16_MAX)
#define     FLT16_C(C)          C ## F16
#endif

#define     FLT_(_)             FLT_ ## _
#define     FLT_SN              FLT32_SN
#define     FLT_TYPE            float
#define     FLT_STG             WORD_
#define     FLT_SIZE            FLT_STG(SIZE)
#define     FLT_WIDTH           FLT_STG(WIDTH)
#define     FLT_SIGNEDNESS      (1)
#define     FLT_C(C)            _Generic(C,double:C##F,int:C##.0F)

#define     FLT32_(_)           FLT32_ ## _
#define     FLT32_SN(_)         _ ## wf
#define     FLT32_TYPE          flt32_t
#define     FLT32_BASE          FLT_
#define     FLT32_STG           WORD_
#define     FLT32_SIZE          FLT32_BASE(SIZE)
#define     FLT32_WIDTH         FLT32_BASE(WIDTH)
#define     FLT32_SIGNEDNESS    FLT32_BASE(SIGNEDNESS)
#define     FLT32_C             FLT32_BASE(C)


#define     DBL_(_)             DBL_ ## _
#define     DBL_SN              FLT64_SN
#define     DBL_TYPE            double
#define     DBL_STG             DWRD_
#define     DBL_SIZE            DBL_STG(SIZE)
#define     DBL_WIDTH           DBL_STG(WIDTH)
#define     DBL_SIGNEDNESS      (1)
#define     DBL_C(C)            _Generic(C,double:C,int:C##.0)

#define     FLT64_(_)           FLT64_ ## _
#define     FLT64_SN(_)         _ ## df
#define     FLT64_TYPE          flt64_t
#define     FLT64_BASE          DBL_
#define     FLT64_STG           FLT64_BASE(STG)
#define     FLT64_SIZE          FLT64_BASE(SIZE)
#define     FLT64_WIDTH         FLT64_BASE(WIDTH)
#define     FLT64_SIGNEDNESS    FLT64_BASE(SIGNEDNESS)
#define     FLT64_C             FLT64_BASE(C)

#if LDBL_MANT_DIG == 113
#   define  QFLT_TYPE           long double
#   define  QFLT_C(C)           _Generic(C##L, long double:C##L, long:C##.0L)
#   define  QUAD_FTYPE          long double
#elif defined(FLT128_MAX)
#   define  QFLT_TYPE           _Float128
#   define  QUAD_FTYPE          _Float128
#   define  QFLT_C(C)           C ## f128
#endif

#if defined(QFLT_TYPE)
#   define  QFLT_(_)            QFLT_ ## _
#   define  QFLT_SN             FLT128_SN
#   define  QFLT_STG            QUAD_
#   define  QFLT_SIZE           QUAD_STG(SIZE)
#   define  QFLT_WIDTH          QUAD_STG(WIDTH)
#   define  QFLT_SIGNEDNESS     (1)
#   define  FLT128_BASE         QFLT_
#else
#   define  FLT128_BASE         XQF_
#   define  QUAD_FTYPE          struct Xqf
#endif

#define     FLT128_(_)          FLT128_ ## _
#define     FLT128_SN(_)        _ ## qf
#define     FLT128_TYPE         flt128_t
#define     FLT128_STG          FLT128_BASE(STG)
#define     FLT128_SIZE         FLT128_BASE(SIZE)
#define     FLT128_WIDTH        FLT128_BASE(WIDTH)
#define     FLT128_SIGNEDNESS   FLT128_BASE(SIGNEDNESS)
#if defined(QFLT_C)
#   define  FLT128_C            FLT128_BASE(C)
#endif

#define MY_BIG_PAIR(Lo, Hi, Z)  Hi Z, Lo Z
#define MY_LIL_PAIR(Lo, Hi, Z)  Lo Z, Hi Z

#define MY_BIG_XFLT(P, Q, L, R, Lo, Hi, Expo, Sign, ...)  \
_Alignas(L>>2) struct __VA_ARGS__  \
{                               \
    P  int ## L ## _t Q         \
        Hi:     R,              \
        Expo:   L-(R+1),        \
        Sign:   1,              \
        :       0;              \
    P uint ## L ## _t Q         \
        Lo:     L,              \
        :       0;              \
}

#define MY_LIL_XFLT(P, Q, L, R, Lo, Hi, Expo, Sign,...)  \
_Alignas(L>>2) struct __VA_ARGS__  \
{                               \
    P uint ## L ## _t Q         \
        Lo:     L,              \
        :       0;              \
    P  int ## L ## _t Q         \
        Hi:     R,              \
        Expo:   L-(R+1),        \
        Sign:   1,              \
        :       0;              \
}

#define MY_LIL_XINT(T, L, Z, ...)   \
_Alignas(L>>2) struct __VA_ARGS__       \
{T##nt##L##_t MY_LIL_PAIR(Lo, Hi, Z);}

#define MY_BIG_XINT(T, L, Z, ...)   \
_Alignas(L>>2) struct __VA_ARGS__       \
{T##nt##L##_t MY_BIG_PAIR(Lo, Hi, Z);}

#ifndef MY_ENDIAN
#   error "why ain't MY_ENDIAN defined?"
#elif MY_ENDIAN == ENDIAN_LIL
#   define  MY_NVX(N)           MY_LV ## N
#   define  MY_PAIR             MY_LIL_PAIR
#   define  MY_XFLT             MY_LIL_XFLT
#   define  MY_XINT             MY_LIL_XINT
#elif MY_ENDIAN == ENDIAN_BIG
#   define  MY_NVX(N)           MY_BV ## N
#   define  MY_PAIR             MY_BIG_PAIR
#   define  MY_XFLT             MY_BIG_XFLT
#   define  MY_XINT             MY_BIG_XINT
#endif

#define MY_NV1      MY_NVX(1)
#define MY_NV2      MY_NVX(2)
#define MY_NV4      MY_NVX(4)
#define MY_NV8      MY_NVX(8)
#define MY_NV16     MY_NVX(16)
#define MY_NV32     MY_NVX(32)
#define MY_NV64     MY_NVX(64)
#define MY_NV128    MY_NVX(128)


#define MY_LV1(M, N) M##0 N
#define MY_LV2(M, N) MY_LV1(M,N),M##1 N
#define MY_LV4(M, N) MY_LV2(M,N),M##2 N,M##3 N

#define MY_LV8(M, N) MY_LV4(M,N),M##4 N,M##5 N,M##6 N,M##7 N

#define MY_LV16(M,N) MY_LV8(M,N),\
M## 8 N,M## 9 N,M##10 N,M##11 N,M##12 N,M##13 N,M##14 N,M##15 N

#define MY_LV32(M,N) MY_LV16(M,N),\
M##16 N,M##17 N,M##18 N,M##19 N,M##20 N,M##21 N,M##22 N,M##23 N,\
M##24 N,M##25 N,M##26 N,M##27 N,M##28 N,M##29 N,M##30 N,M##31 N

#define MY_LV64(M,N) MY_LV32(M,N),\
M##32 N,M##33 N,M##34 N,M##35 N,M##36 N,M##37 N,M##38 N,M##39 N,\
M##40 N,M##41 N,M##42 N,M##43 N,M##44 N,M##45 N,M##46 N,M##47 N,\
M##48 N,M##49 N,M##50 N,M##51 N,M##52 N,M##53 N,M##54 N,M##55 N,\
M##56 N,M##57 N,M##58 N,M##59 N,M##60 N,M##61 N,M##62 N,M##63 N

#define MY_LV128(M,N) MY_LV64(M,N), \
M## 64 N,M## 65 N,M## 66 N,M## 67 N,M## 68 N,M## 69 N,M## 70 N,M## 71 N,\
M## 72 N,M## 73 N,M## 74 N,M## 75 N,M## 76 N,M## 77 N,M## 78 N,M## 79 N,\
M## 80 N,M## 81 N,M## 82 N,M## 83 N,M## 84 N,M## 85 N,M## 86 N,M## 87 N,\
M## 88 N,M## 89 N,M## 90 N,M## 91 N,M## 92 N,M## 93 N,M## 94 N,M## 95 N,\
M## 96 N,M## 97 N,M## 98 N,M## 99 N,M##100 N,M##101 N,M##102 N,M##103 N,\
M##104 N,M##105 N,M##106 N,M##107 N,M##108 N,M##109 N,M##110 N,M##111 N,\
M##112 N,M##113 N,M##114 N,M##115 N,M##116 N,M##117 N,M##118 N,M##119 N,\
M##120 N,M##121 N,M##122 N,M##123 N,M##124 N,M##125 N,M##126 N,M##127 N


#define MY_BV1(M, N)  M##0 N
#define MY_BV2(M, N)  M##1 N,MY_BV1(M,N)
#define MY_BV4(M, N)  M##3 N,M##2 N,MY_BV2(M,N)
#define MY_BV8(M, N)  M##7 N,M##6 N,M##5 N,M##4 N,MY_BV4(M,N)

#define MY_BV16(M, N) \
M##15 N,M##14 N,M##13 N,M##12 N,M##11 N,M##10 N,M## 9 N,M## 8 N,\
MY_BV8(M,N)

#define MY_BV32(M, N) \
M##31 N,M##30 N,M##29 N,M##28 N,M##27 N,M##26 N,M##25 N,M##24 N,\
M##23 N,M##22 N,M##21 N,M##20 N,M##19 N,M##18 N,M##17 N,M##16 N,\
MY_BV16(M,N)

#define MY_BV64(M, N) \
M##63 N,M##62 N,M##61 N,M##60 N,M##59 N,M##58 N,M##57 N,M##56 N,\
M##55 N,M##54 N,M##53 N,M##52 N,M##51 N,M##50 N,M##49 N,M##48 N,\
M##47 N,M##46 N,M##45 N,M##44 N,M##43 N,M##42 N,M##41 N,M##40 N,\
M##39 N,M##38 N,M##37 N,M##36 N,M##35 N,M##34 N,M##33 N,M##32 N,\
MY_BV32(M,N)

#define MY_BV128(M,N) \
M##127 N,M##126 N,M##125 N,M##124 N,M##123 N,M##122 N,M##121 N,M##120 N,\
M##119 N,M##118 N,M##117 N,M##116 N,M##115 N,M##114 N,M##113 N,M##112 N,\
M##111 N,M##110 N,M##109 N,M##108 N,M##107 N,M##106 N,M##105 N,M##104 N,\
M##103 N,M##102 N,M##101 N,M##100 N,M## 99 N,M## 98 N,M## 97 N,M## 96 N,\
M## 95 N,M## 94 N,M## 93 N,M## 92 N,M## 91 N,M## 90 N,M## 89 N,M## 88 N,\
M## 87 N,M## 86 N,M## 85 N,M## 84 N,M## 83 N,M## 82 N,M## 81 N,M## 80 N,\
M## 79 N,M## 78 N,M## 77 N,M## 76 N,M## 75 N,M## 74 N,M## 73 N,M## 72 N,\
M## 71 N,M## 70 N,M## 69 N,M## 68 N,M## 67 N,M## 66 N,M## 65 N,M## 64 N,\
MY_BV64(M,N)
    
/*  "Split" scalar types

    The integers are defined as structs containing two 
    members: 'Lo', which represents the least significant 
    bits, and 'Hi', which represents the most significant
    bits. The signed integers also have an unsigned 'Sign'
    member.

    The "split" floating point types are similar to the
    ints, each having the following members:

        'Lo', the part of the mantissa in which its least
        significant bit is stored

        'Hi', the part of the mantissa in which its most
        significant bit is stored

        'Expo', the float's exponent

        `Sign`: the float's sign

    Each float type's layout matches the corresponding
    IEE 756 format.

*/

typedef struct Xhu {MY_XINT(ui,  8,  );} Xhu;

typedef struct Xwu {MY_XINT(ui, 16,  );} Xwu;

typedef struct Xdu {MY_XINT(ui, 32,  );} Xdu;

typedef struct Xqu {MY_XINT(ui, 64,  );} Xqu;


typedef struct Xhi {
    union {
        MY_XINT( i,  8,  );
        struct {uint8_t  : 8, : 7, Sign:1, :0;};
    };
} Xhi;

typedef struct Xwi {
    union {
        MY_XINT( i, 16,  );
        struct {uint16_t :16, :15, Sign:1, :0;};
    };
} Xwi;

typedef struct Xdi {
    union {
        MY_XINT( i, 32,  );
        struct {uint32_t :32, :31, Sign:1, :0;};
    };
} Xdi;

typedef struct Xqi {
    union {
        MY_XINT( i, 64,  );
        struct {uint64_t :64, :63, Sign:1, :0;};
    };
} Xqi;


typedef struct Xhf {MY_XFLT( , , 8, 2,Lo,Hi,Expo,Sign);} Xhf;

typedef struct Xwf {MY_XFLT( , ,16, 7,Lo,Hi,Expo,Sign);} Xwf;

typedef struct Xdf {MY_XFLT( , ,32,20,Lo,Hi,Expo,Sign);} Xdf;

typedef struct Xqf {MY_XFLT( , ,64,48,Lo,Hi,Expo,Sign);} Xqf;

typedef             CHAR_TYPE   Bc;
typedef       UINT8_BASE(TYPE)  Bu,  uint8_t;
typedef        INT8_BASE(TYPE)  Bi,   int8_t;

typedef       UINT16_BASE(TYPE) Hu,  uint16_t;
typedef        INT16_BASE(TYPE) Hi,   int16_t;

typedef       UINT32_BASE(TYPE) Wu,  uint32_t;
typedef        INT32_BASE(TYPE) Wi,   int32_t;

typedef       UINT64_BASE(TYPE) Du,  uint64_t;
typedef        INT64_BASE(TYPE) Di,   int64_t;

typedef      UINT128_BASE(TYPE) Qu, uint128_t;
typedef       INT128_BASE(TYPE) Qi,  int128_t;


typedef        FLT16_BASE(TYPE) Hf,   flt16_t;
typedef        FLT32_BASE(TYPE) Wf,   flt32_t;
typedef        FLT64_BASE(TYPE) Df,   flt64_t;
typedef       FLT128_BASE(TYPE) Qf,  flt128_t;


#ifndef     WORD_LTYPE
#if defined(WORD_LFTYPE) || defined(WORD_LUTYPE) || defined(WORD_LITYPE)
#   define  WORD_LTYPE          union Wl
#endif
#endif

#ifndef     DWRD_LTYPE
#if defined(DWRD_LFTYPE) || defined(DWRD_LUTYPE) || defined(DWRD_LITYPE)
#   define  DWRD_LTYPE          union Dl
#endif
#endif

#ifndef     QUAD_LTYPE
#if defined(QUAD_LFTYPE) || defined(QUAD_LUTYPE) || defined(QUAD_LITYPE)
#   define  QUAD_LTYPE          union Ql
#endif
#endif

#if defined(WORD_LTYPE)
#   define MY_LONG_STG WORD_
#   define MY_LONG_BASE WORD_LI
#   define MY_ULONG_BASE WORD_LU
#   if  defined(WORD_LUTYPE)
typedef         WORD_LUTYPE     Lu;
#   endif

#   if  defined(WORD_LITYPE)
typedef         WORD_LITYPE     Li;
#   endif

typedef union Wl {
#   if defined(WORD_LUTYPE)
    WORD_LUTYPE     U;
#   endif

#   if defined(WORD_LITYPE)
    WORD_LITYPE     I;
#   endif

#   if defined(WORD_LFTYPE)
    WORD_LFTYPE     F;
#   endif

}          Wl;


#elif defined(DWRD_LTYPE)
#   define MY_LONG_STG DWRD_
#   define MY_LONG_BASE DWRD_LI
#   define MY_ULONG_BASE DWRD_LU
#   if  defined(DWRD_LUTYPE)
typedef         DWRD_LUTYPE     Lu;
#   endif

#   if defined(DWRD_LITYPE)
typedef         DWRD_LITYPE     Li;
#   endif

typedef union Dl {
#   if defined(DWRD_LUTYPE)
    DWRD_LUTYPE         U;
#   endif

#   if defined(DWRD_LITYPE)
    DWRD_LITYPE         I;
#   endif

#   if defined(DWRD_LFTYPE)
    DWRD_LFTYPE         F;
#   endif

}          Dl;

#elif QUAD_NLLONG == 1
#   define MY_LONG_STG QUAD_
#   define MY_LONG_BASE QUAD_LI
#   define MY_ULONG_BASE QUAD_LU
#   if  defined(QUAD_LUTYPE)
typedef         QUAD_LUTYPE     Lu;
#   endif

#   if  defined(QUAD_LITYPE)
typedef         QUAD_LITYPE     Li;
#   endif

#endif

#if defined(QUAD_LTYPE)
#   if  defined(QUAD_LFTYPE)
typedef         QUAD_LFTYPE     Lf;
#   endif

typedef union Ql {
#   if defined(QUAD_LUTYPE)
    QUAD_LUTYPE  U;
#   endif

#   if defined(QUAD_LITYPE)
    QUAD_LITYPE  I;
#   endif

#   if defined(QUAD_LFTYPE)
    QUAD_LFTYPE  F;
#   endif

}          Ql;

#endif

typedef union Xh {Xhu U; Xhi I; Xhf F;} Xh;
typedef union Xw {Xwu U; Xwi I; Xwf F;} Xw;
typedef union Xd {Xdu U; Xdi I; Xdf F;} Xd;
typedef union Xq {Xqu U; Xqi I; Xqf F;} Xq;

typedef union Byte {
    char    C[1];
    Bu      U;
    Bi      I;
    struct  {bool   MY_NV8(Y, :1), :0;  };
    struct  {char   MY_NV1(C,  );       };
    struct  {Bu     MY_NV1(U,  );       };
    struct  {Bi     MY_NV1(I,  );       };
} Byte;

typedef union Half {
    char    C[2];
    Byte    B[2];
    Hu      U;
    Hi      I;
    Hf      F;
    Xh      X;
    struct  {bool   MY_NV16(Y, :1), :0; };
    struct  {char   MY_NV2( C,  );      };
    struct  {Byte   MY_NV2( B,  );      };
    struct  {Byte   MY_PAIR(Lo, Hi,  ); };
#if HALF_NPTR
    void    *A[HALF_NPTR];
    struct  {void   MY_NV1(*A,  );      };
#endif

} Half;

typedef union Word {
    char    C[4];
    Byte    B[4];
    Half    H[2];
    Wu      U;
    Wi      I;
    Wf      F;
    Xw      X;
#if defined(WORD_LTYPE)
    Wl      L;
#endif

    struct  {bool   MY_NV32(Y, :1), :0; };
    struct  {char   MY_NV4( C,  );      };
    struct  {Byte   MY_NV4( B,  );      };
    struct  {Half   MY_NV2( H,  );      };
    struct  {Half   MY_PAIR(Lo, Hi,  ); };
#if WORD_NPTR
    void    *A[WORD_NPTR];
#   if WORD_NPTR == 2
    struct  {void   MY_NV2(*A,  );      };
#   else
    struct  {void   MY_NV1(*A,  );      };
#   endif

#endif

} Word;

typedef union Dwrd {
    char    C[8];
    Byte    B[8];
    Half    H[4];
    Word    W[2];
    Du      U;
    Di      I;
    Df      F;
    Xd      X;
#   if defined(DWRD_LTYPE)
    Dl      L;
#   endif

    struct  {bool    MY_NV64(Y, :1), :0; };
    struct  {char   MY_NV8( C,  );      };
    struct  {Byte   MY_NV8( B,  );      };
    struct  {Half   MY_NV4( H,  );      };
    struct  {Word   MY_NV2( W,  );      };
    struct  {Word   MY_PAIR(Lo, Hi,  ); };
#if DWRD_NPTR
    void    *A[DWRD_NPTR];
#   if   DWRD_NPTR == 4
    struct  {void   MY_NV4(*A,  );      };
#   elif DWRD_NPTR == 2
    struct  {void   MY_NV2(*A,  );      };
#   else
    struct  {void   MY_NV1(*A,  );      };
#   endif

#endif

} Dwrd;

typedef union Quad {
    char    C[16];
    Byte    B[16];
    Half    H[ 8];
    Word    W[ 4];
    Dwrd    D[ 2];
    Qu      U;
    Qi      I;
    Qf      F;
    Xq      X;
#   if defined(QUAD_LTYPE)
    Ql      L;
#   endif

    struct  {bool   MY_NV128(Y, :1), :0;};
    struct  {char   MY_NV16( C, );      };
    struct  {Byte   MY_NV16( B, );      };
    struct  {Half   MY_NV8(  H, );      };
    struct  {Word   MY_NV4(  W, );      };
    struct  {Dwrd   MY_NV2(  D, );      };
    struct  {Dwrd   MY_PAIR(Lo, Hi,  ); };

    void    *A[QUAD_NPTR];

#   if   QUAD_NPTR == 8
    struct  {void   MY_NV8(*A,  );      };
#   elif DWRD_NPTR == 4
    struct  {void   MY_NV4(*A,  );      };
#   elif DWRD_NPTR == 2
    struct  {void   MY_NV2(*A,  );      };
#   else
    struct  {void   MY_NV1(*A,  );      };
#   endif

} Quad;

typedef union Scalar {
    void   *A;
    Byte    B;
    Half    H;
    Word    W;
    Dwrd    D;
    Quad    Q;
    union {
        Byte *B;
        Half *H;
        Word *W;
        Dwrd *D;
        Quad *Q;
    } P;
} Scalar;

#define     REPR_BIG    0b0000000000000000 // n
#define     REPR_LIL    0b0000000000000001 // n
#define     REPR_NAT    ((MY_ENDIAN==ENDIAN_LIL)?REPR_LIL:REPR_BIG)

#define     REPR_R      0b0000000000000000 // t
#define     REPR_U      0b0000000000000010 // t
#define     REPR_I      0b0000000000000100 // t
#define     REPR_F      0b0000000000000110 // t

#define     REPR_L      0b0000000000001000 // l

#define     REPR_X      0b0000000010000000 // x
#define     REPR_XL     (REPR_X)
#define     REPR_XB     (REPR_X|REPR_L)
#define     REPR_XN     ((MY_ENDIAN==ENDIAN_LIL)?REPR_XL:REPR_XB)

#define     REPR_B      0b0000000000000000 // z
#define     REPR_H      0b0000000000010000 // z
#define     REPR_W      0b0000000000100000 // z
#define     REPR_D      0b0000000001100000 // z
#define     REPR_Q      0b0000000001000000 // z
#define     REPR_O      0b0000000001010000 // z
#define     REPR_S      0b0000000001100000 // z
#define     REPR_Y      0b0000000001110000 // z

#define     REPR_V      0b0000111100000000 // v
#define     REPR_V1     0b0000000100000000 // v
#define     REPR_V2     0b0000001000000000 // v
#define     REPR_V4     0b0000001100000000 // v
#define     REPR_V8     0b0000010000000000 // v
#define     REPR_V16    0b0000010100000000 // v
#define     REPR_V32    0b0000011000000000 // v
#define     REPR_V64    0b0000011100000000 // v
#define     REPR_V128   0b0000100000000000 // v
#define     REPR_V256   0b0000100100000000 // v
#define     REPR_V512   0b0000101000000000 // v

/*  An 'X' type with the 'L' bit set has its members ordered 
    in reverse.

*/
#define     XHU_REPR    (REPR_X|REPR_H|REPR_U|REPR_NAT)
#define     XHI_REPR    (REPR_X|REPR_H|REPR_I|REPR_NAT)
#define     XHF_REPR    (REPR_X|REPR_H|REPR_F|REPR_NAT)

#define     XWU_REPR    (REPR_X|REPR_W|REPR_U|REPR_NAT)
#define     XWI_REPR    (REPR_X|REPR_W|REPR_I|REPR_NAT)
#define     XWF_REPR    (REPR_X|REPR_W|REPR_F|REPR_NAT)

#define     XDU_REPR    (REPR_X|REPR_D|REPR_U|REPR_NAT)
#define     XDI_REPR    (REPR_X|REPR_D|REPR_I|REPR_NAT)
#define     XDF_REPR    (REPR_X|REPR_D|REPR_F|REPR_NAT)

#define     XQU_REPR    (REPR_X|REPR_Q|REPR_U|REPR_NAT)
#define     XQI_REPR    (REPR_X|REPR_Q|REPR_I|REPR_NAT)
#define     XQF_REPR    (REPR_X|REPR_Q|REPR_F|REPR_NAT)

#define     UINT8_REPR               (REPR_B|REPR_U)
#define     UINT16_REPR     (REPR_NAT|REPR_H|REPR_U)
#define     UINT32_REPR     (REPR_NAT|REPR_W|REPR_U)
#define     UINT64_REPR     (REPR_NAT|REPR_D|REPR_U)
#define     UINT128_REPR    (REPR_NAT|REPR_Q|REPR_U)

#define     INT8_REPR                (REPR_B|REPR_I)
#define     INT16_REPR      (REPR_NAT|REPR_H|REPR_I)
#define     INT32_REPR      (REPR_NAT|REPR_W|REPR_I)
#define     INT64_REPR      (REPR_NAT|REPR_D|REPR_I)
#define     INT128_REPR     (REPR_NAT|REPR_Q|REPR_I)

#define     FLT16_REPR      (REPR_NAT|REPR_H|REPR_F)
#define     FLT32_REPR      (REPR_NAT|REPR_W|REPR_F)
#define     FLT64_REPR      (REPR_NAT|REPR_D|REPR_F)
#define     FLT128_REPR     (REPR_NAT|REPR_Q|REPR_F)

#if defined(_MSC_VER)
#   define  CHAR_REPR       (REPR_B|(CHAR_MIN?REPR_I:REPR_U))
#else
#   define  CHAR_REPR       (REPR_NAT|REPR_B|(CHAR_MIN?REPR_I:REPR_U)|REPR_L)
#endif

#define     UCHAR_REPR      (REPR_B|REPR_U)
#define     SCHAR_REPR      (REPR_B|REPR_I)

#define     USHRT_REPR      (REPR_H|REPR_U)
#define     SHRT_REPR       (REPR_H|REPR_I)

#define     UINT_REPR       (REPR_W|REPR_U)
#define     INT_REPR        (REPR_W|REPR_I)

#if DWRD_NLONG == 2
#   define  ULONG_REPR      (REPR_W|REPR_U|REPR_L)
#   define  LONG_REPR       (REPR_W|REPR_I|REPR_L)
#   define  ULLONG_REPR     (REPR_D|REPR_I)
#   define  LLONG_REPR      (REPR_D|REPR_U)
#elif QUAD_NLLONG == 2
#   define  ULONG_REPR      (REPR_D|REPR_U)
#   define  LONG_REPR       (REPR_D|REPR_I)
#   define  ULLONG_REPR     (REPR_D|REPR_U|REPR_L)
#   define  LLONG_REPR      (REPR_D|REPR_I|REPR_L)
#endif

#define     VDBU_REPR       (REPR_V8|REPR_B|REPR_U|REPR_NAT)
#define     VDBI_REPR       (REPR_V8|REPR_B|REPR_I|REPR_NAT)

#define     VDHU_REPR       (REPR_V4|REPR_H|REPR_U|REPR_NAT)
#define     VDHI_REPR       (REPR_V4|REPR_H|REPR_I|REPR_NAT)
#define     VDHF_REPR       (REPR_V4|REPR_H|REPR_F|REPR_NAT)

#define     VDWU_REPR       (REPR_V2|REPR_W|REPR_U|REPR_NAT)
#define     VDWI_REPR       (REPR_V2|REPR_W|REPR_I|REPR_NAT)
#define     VDWF_REPR       (REPR_V2|REPR_W|REPR_F|REPR_NAT)

#define     VDDU_REPR       (REPR_V1|REPR_D|REPR_U|REPR_NAT)
#define     VDDI_REPR       (REPR_V1|REPR_D|REPR_I|REPR_NAT)
#define     VDDF_REPR       (REPR_V1|REPR_D|REPR_F|REPR_NAT)


#define     VQBU_REPR       (REPR_V16|REPR_B|REPR_U|REPR_NAT)
#define     VQBI_REPR       (REPR_V16|REPR_B|REPR_I|REPR_NAT)

#define     VQHU_REPR       (REPR_V8 |REPR_H|REPR_U|REPR_NAT)
#define     VQHI_REPR       (REPR_V8 |REPR_H|REPR_I|REPR_NAT)
#define     VQHF_REPR       (REPR_V8 |REPR_H|REPR_F|REPR_NAT)

#define     VQWU_REPR       (REPR_V4 |REPR_W|REPR_U|REPR_NAT)
#define     VQWI_REPR       (REPR_V4 |REPR_W|REPR_I|REPR_NAT)
#define     VQWF_REPR       (REPR_V4 |REPR_W|REPR_F|REPR_NAT)

#define     VQDU_REPR       (REPR_V2 |REPR_D|REPR_U|REPR_NAT)
#define     VQDI_REPR       (REPR_V2 |REPR_D|REPR_I|REPR_NAT)
#define     VQDF_REPR       (REPR_V2 |REPR_D|REPR_F|REPR_NAT)

#define     VQQU_REPR       (REPR_V1 |REPR_D|REPR_U|REPR_NAT)
#define     VQQI_REPR       (REPR_V1 |REPR_D|REPR_I|REPR_NAT)
#define     VQQF_REPR       (REPR_V1 |REPR_D|REPR_F|REPR_NAT)

#define     VOBU_REPR       (REPR_V32|REPR_B|REPR_U|REPR_NAT)
#define     VOBI_REPR       (REPR_V32|REPR_B|REPR_I|REPR_NAT)


#define     VOHU_REPR       (REPR_V16 |REPR_H|REPR_U|REPR_NAT)
#define     VOHI_REPR       (REPR_V16 |REPR_H|REPR_I|REPR_NAT)
#define     VOHF_REPR       (REPR_V16 |REPR_H|REPR_F|REPR_NAT)

#define     VOWU_REPR       (REPR_V8 |REPR_W|REPR_U|REPR_NAT)
#define     VOWI_REPR       (REPR_V8 |REPR_W|REPR_I|REPR_NAT)
#define     VOWF_REPR       (REPR_V8 |REPR_W|REPR_F|REPR_NAT)

#define     VODU_REPR       (REPR_V4 |REPR_D|REPR_U|REPR_NAT)
#define     VODI_REPR       (REPR_V4 |REPR_D|REPR_I|REPR_NAT)
#define     VODF_REPR       (REPR_V4 |REPR_D|REPR_F|REPR_NAT)

#define     VOQU_REPR       (REPR_V2 |REPR_Q|REPR_U|REPR_NAT)
#define     VOQI_REPR       (REPR_V2 |REPR_Q|REPR_I|REPR_NAT)
#define     VOQF_REPR       (REPR_V2 |REPR_Q|REPR_F|REPR_NAT)


#define     VSBU_REPR       (REPR_V64|REPR_B|REPR_U|REPR_NAT)
#define     VSBI_REPR       (REPR_V64|REPR_B|REPR_I|REPR_NAT)

#define     VSHU_REPR       (REPR_V32|REPR_H|REPR_U|REPR_NAT)
#define     VSHI_REPR       (REPR_V32|REPR_H|REPR_I|REPR_NAT)
#define     VSHF_REPR       (REPR_V32|REPR_H|REPR_F|REPR_NAT)

#define     VSWU_REPR       (REPR_V16|REPR_W|REPR_U|REPR_NAT)
#define     VSWI_REPR       (REPR_V16|REPR_W|REPR_I|REPR_NAT)
#define     VSWF_REPR       (REPR_V16|REPR_W|REPR_F|REPR_NAT)

#define     VSDU_REPR       (REPR_V8 |REPR_D|REPR_U|REPR_NAT)
#define     VSDI_REPR       (REPR_V8 |REPR_D|REPR_I|REPR_NAT)
#define     VSDF_REPR       (REPR_V8 |REPR_D|REPR_F|REPR_NAT)

#define     VSQU_REPR       (REPR_V4 |REPR_Q|REPR_U|REPR_NAT)
#define     VSQI_REPR       (REPR_V4 |REPR_Q|REPR_I|REPR_NAT)
#define     VSQF_REPR       (REPR_V4 |REPR_Q|REPR_F|REPR_NAT)

#if 1 // test sizes and offsets
typedef union {
    struct {Bu MY_LV128(L, );};
    struct {Bu MY_BV128(B, );};
} MY_SIZES_TEST;

ASSERT(0   == offsetof(MY_SIZES_TEST,L0));
ASSERT(1   == offsetof(MY_SIZES_TEST,L1));
ASSERT(2   == offsetof(MY_SIZES_TEST,L2));
ASSERT(3   == offsetof(MY_SIZES_TEST,L3));
ASSERT(4   == offsetof(MY_SIZES_TEST,L4));
ASSERT(5   == offsetof(MY_SIZES_TEST,L5));
ASSERT(6   == offsetof(MY_SIZES_TEST,L6));
ASSERT(7   == offsetof(MY_SIZES_TEST,L7));
ASSERT(8   == offsetof(MY_SIZES_TEST,L8));

ASSERT(8*14+0  == offsetof(MY_SIZES_TEST,L112));
ASSERT(8*14+7  == offsetof(MY_SIZES_TEST,L119));
ASSERT(8*15+0  == offsetof(MY_SIZES_TEST,L120));
ASSERT(8*15+7  == offsetof(MY_SIZES_TEST,L127));

ASSERT(127-0   == offsetof(MY_SIZES_TEST,B0));
ASSERT(127-1   == offsetof(MY_SIZES_TEST,B1));
ASSERT(127-2   == offsetof(MY_SIZES_TEST,B2));
ASSERT(127-3   == offsetof(MY_SIZES_TEST,B3));
ASSERT(127-4   == offsetof(MY_SIZES_TEST,B4));
ASSERT(127-5   == offsetof(MY_SIZES_TEST,B5));
ASSERT(127-6   == offsetof(MY_SIZES_TEST,B6));
ASSERT(127-7   == offsetof(MY_SIZES_TEST,B7));
ASSERT(127-8*1 == offsetof(MY_SIZES_TEST,B8));
ASSERT(127-8*2 == offsetof(MY_SIZES_TEST,B16));
ASSERT(127-8*3 == offsetof(MY_SIZES_TEST,B24));
ASSERT(127-8*4 == offsetof(MY_SIZES_TEST,B32));

ASSERT(1 == sizeof(Byte));
ASSERT(2 == sizeof(Half));
ASSERT(4 == sizeof(Word));
ASSERT(8 == sizeof(Dwrd));
ASSERT(16 == sizeof(Quad));

#endif // test sizes and offsets


#define     TGK_BI(_)   BYTE_ITYPE:BYTE_SNI(_),
#define     TGK_BU(_)   BYTE_UTYPE:BYTE_SNU(_),
#define     TGK_BF(_) 

#define     TGK_HI(_)   HALF_ITYPE:HALF_SNI(_),
#define     TGK_HU(_)   HALF_UTYPE:HALF_SNU(_),

#if 1
#   define  TGK_HF(_)   
#else
#   define  TGK_HF(_)   HALF_FTYPE:HALF_SNF(_),
#endif

#if defined(WORD_LITYPE)
#   define  TGK_WI(_)   WORD_ITYPE:WORD_SNI(_), WORD_LITYPE:_##li,
#else
#   define  TGK_WI(_)   WORD_ITYPE:WORD_SNI(_),
#endif

#if defined(WORD_LUTYPE)
#   define  TGK_WU(_)   WORD_UTYPE:WORD_SNU(_), WORD_LUTYPE:_##lu,
#else
#   define  TGK_WU(_)   WORD_UTYPE:WORD_SNU(_),
#endif

#if defined(WORD_LFTYPE)
#   define  TGK_WF(_)    WORD_FTYPE:WORD_SNF(_), WORD_LFTYPE:_##lf,
#else
#   define  TGK_WF(_)    WORD_FTYPE:WORD_SNF(_),
#endif


#if defined(DWRD_LITYPE)
#   define  TGK_DI(_)   DWRD_ITYPE:DWRD_SNI(_), DWRD_LITYPE:_##li,
#else
#   define  TGK_DI(_)   DWRD_ITYPE:DWRD_SNI(_),
#endif

#if defined(DWRD_LUTYPE)
#   define  TGK_DU(_)   DWRD_UTYPE:DWRD_SNU(_), DWRD_LUTYPE:_##lu,
#else
#   define  TGK_DU(_)   DWRD_UTYPE:DWRD_SNU(_),
#endif

#if defined(DWRD_LFTYPE)
#   define  TGK_DF(_)   DWRD_FTYPE:DWRD_SNF(_), DWRD_LFTYPE:_##lf,
#else
#   define  TGK_DF(_)   DWRD_FTYPE:DWRD_SNF(_),
#endif


#if defined(QUAD_LITYPE)
#   define  TGK_QI(_)   QUAD_ITYPE:QUAD_SNI(_), QUAD_LITYPE:_##li,
#else
#   define  TGK_QI(_)   QUAD_ITYPE:QUAD_SNI(_),
#endif

#if defined(QUAD_LUTYPE)
#   define  TGK_QU(_)   QUAD_UTYPE:QUAD_SNU(_), QUAD_LUTYPE:_##lu,
#else
#   define  TGK_QU(_)   QUAD_UTYPE:QUAD_SNU(_),
#endif

#if defined(QUAD_LFTYPE)
#   define  TGK_QF(_)   QUAD_FTYPE:QUAD_SNF(_), QUAD_LFTYPE:_##lf,
#else
#   define  TGK_QF(_)   QUAD_FTYPE:QUAD_SNF(_),
#endif


#define     TGK_BZ(_)               TGK_BU(_)   TGK_BI(_) 
#define     TGK_BS(_)   TGK_BF(_)               TGK_BI(_)
#define     TGK_BN(_)   TGK_BF(_)   TGK_BU(_)
#define     TGK_BR(_)   TGK_BF(_)   TGK_BU(_)   TGK_BI(_)

#define     TGK_HZ(_)               TGK_HU(_)   TGK_HI(_)
#define     TGK_HS(_)   TGK_HF(_)               TGK_HI(_)
#define     TGK_HN(_)   TGK_HF(_)   TGK_HU(_)
#define     TGK_HR(_)   TGK_HF(_)   TGK_HU(_)   TGK_HI(_)

#define     TGK_WZ(_)               TGK_WU(_)   TGK_WI(_)
#define     TGK_WS(_)   TGK_WF(_)               TGK_WI(_)
#define     TGK_WN(_)   TGK_WF(_)   TGK_WU(_)
#define     TGK_WR(_)   TGK_WF(_)   TGK_WU(_)   TGK_WI(_)

#define     TGK_DZ(_)               TGK_DU(_)   TGK_DI(_)
#define     TGK_DS(_)   TGK_DF(_)               TGK_DI(_)
#define     TGK_DN(_)   TGK_DF(_)   TGK_DU(_)
#define     TGK_DR(_)   TGK_DF(_)   TGK_DU(_)   TGK_DI(_)

#define     TGK_QZ(_)               TGK_QU(_)   TGK_QI(_)
#define     TGK_QS(_)   TGK_QF(_)               TGK_QI(_)
#define     TGK_QN(_)   TGK_QF(_)   TGK_QU(_)
#define     TGK_QR(_)   TGK_QF(_)   TGK_QU(_)   TGK_QI(_)

#define     TGK_B_HI(_) TGK_BI(_) TGK_HI(_)
#define     TGK_H_WI(_)           TGK_HI(_) TGK_WI(_) 
#define     TGK_W_DI(_)                     TGK_WI(_) TGK_DI(_)
#define     TGK_D_QI(_)                               TGK_DI(_) TGK_QI(_)
#define     TGK_B_WI(_) TGK_BI(_) TGK_HI(_) TGK_WI(_) 
#define     TGK_H_DI(_)           TGK_HI(_) TGK_WI(_) TGK_DI(_) 
#define     TGK_W_QI(_)                     TGK_WI(_) TGK_DI(_) TGK_QI(_)
#define     TGK_B_DI(_) TGK_BI(_) TGK_HI(_) TGK_WI(_) TGK_DI(_)
#define     TGK_H_QI(_)           TGK_HI(_) TGK_WI(_) TGK_DI(_) TGK_QI(_)
#define     TGK_B_QI(_) TGK_BI(_) TGK_HI(_) TGK_WI(_) TGK_DI(_) TGK_QI(_)

#define     TGK_B_HU(_) TGK_BU(_) TGK_HU(_)
#define     TGK_H_WU(_)           TGK_HU(_) TGK_WU(_) 
#define     TGK_W_DU(_)                     TGK_WU(_) TGK_DU(_)
#define     TGK_D_QU(_)                               TGK_DU(_) TGK_QU(_)
#define     TGK_B_WU(_) TGK_BU(_) TGK_HU(_) TGK_WU(_) 
#define     TGK_H_DU(_)           TGK_HU(_) TGK_WU(_) TGK_DU(_) 
#define     TGK_W_QU(_)                     TGK_WU(_) TGK_DU(_) TGK_QU(_)
#define     TGK_B_DU(_) TGK_BU(_) TGK_HU(_) TGK_WU(_) TGK_DU(_)
#define     TGK_H_QU(_)           TGK_HU(_) TGK_WU(_) TGK_DU(_) TGK_QU(_)
#define     TGK_B_QU(_) TGK_BU(_) TGK_HU(_) TGK_WU(_) TGK_DU(_) TGK_QU(_)

#define     TGK_B_HF(_) TGK_BF(_) TGK_HF(_)
#define     TGK_H_WF(_)           TGK_HF(_) TGK_WF(_) 
#define     TGK_W_DF(_)                     TGK_WF(_) TGK_DF(_)
#define     TGK_D_QF(_)                               TGK_DF(_) TGK_QF(_)
#define     TGK_B_WF(_) TGK_BF(_) TGK_HF(_) TGK_WF(_) 
#define     TGK_H_DF(_)           TGK_HF(_) TGK_WF(_) TGK_DF(_) 
#define     TGK_W_QF(_)                     TGK_WF(_) TGK_DF(_) TGK_QF(_)
#define     TGK_B_DF(_) TGK_BF(_) TGK_HF(_) TGK_WF(_) TGK_DF(_)
#define     TGK_H_QF(_)           TGK_HF(_) TGK_WF(_) TGK_DF(_) TGK_QF(_)
#define     TGK_B_QF(_) TGK_BF(_) TGK_HF(_) TGK_WF(_) TGK_DF(_) TGK_QF(_)

#define     TGK_B_HZ(_) TGK_BZ(_) TGK_HZ(_)
#define     TGK_H_WZ(_)           TGK_HZ(_) TGK_WZ(_) 
#define     TGK_W_DZ(_)                     TGK_WZ(_) TGK_DZ(_)
#define     TGK_D_QZ(_)                               TGK_DZ(_) TGK_QZ(_)
#define     TGK_B_WZ(_) TGK_BZ(_) TGK_HZ(_) TGK_WZ(_) 
#define     TGK_H_DZ(_)           TGK_HZ(_) TGK_WZ(_) TGK_DZ(_) 
#define     TGK_W_QZ(_)                     TGK_WZ(_) TGK_DZ(_) TGK_QZ(_)
#define     TGK_B_DZ(_) TGK_BZ(_) TGK_HZ(_) TGK_WZ(_) TGK_DZ(_)
#define     TGK_H_QZ(_)           TGK_HZ(_) TGK_WZ(_) TGK_DZ(_) TGK_QZ(_)
#define     TGK_B_QZ(_) TGK_BZ(_) TGK_HZ(_) TGK_WZ(_) TGK_DZ(_) TGK_QZ(_)

#define     TGK_B_HS(_) TGK_BS(_) TGK_HS(_)
#define     TGK_H_WS(_)           TGK_HS(_) TGK_WS(_) 
#define     TGK_W_DS(_)                     TGK_WS(_) TGK_DS(_)
#define     TGK_D_QS(_)                               TGK_DS(_) TGK_QS(_)
#define     TGK_B_WS(_) TGK_BS(_) TGK_HS(_) TGK_WS(_) 
#define     TGK_H_DS(_)           TGK_HS(_) TGK_WS(_) TGK_DS(_) 
#define     TGK_W_QS(_)                     TGK_WS(_) TGK_DS(_) TGK_QS(_)
#define     TGK_B_DS(_) TGK_BS(_) TGK_HS(_) TGK_WS(_) TGK_DS(_)
#define     TGK_H_QS(_)           TGK_HS(_) TGK_WS(_) TGK_DS(_) TGK_QS(_)
#define     TGK_B_QS(_) TGK_BS(_) TGK_HS(_) TGK_WS(_) TGK_DS(_) TGK_QS(_)

#define     TGK_B_HN(_) TGK_BN(_) TGK_HN(_)
#define     TGK_H_WN(_)           TGK_HN(_) TGK_WN(_) 
#define     TGK_W_DN(_)                     TGK_WN(_) TGK_DN(_)
#define     TGK_D_QN(_)                               TGK_DN(_) TGK_QN(_)
#define     TGK_B_WN(_) TGK_BN(_) TGK_HN(_) TGK_WN(_) 
#define     TGK_H_DN(_)           TGK_HN(_) TGK_WN(_) TGK_DN(_) 
#define     TGK_W_QN(_)                     TGK_WN(_) TGK_DN(_) TGK_QN(_)
#define     TGK_B_DN(_) TGK_BN(_) TGK_HN(_) TGK_WN(_) TGK_DN(_)
#define     TGK_H_QN(_)           TGK_HN(_) TGK_WN(_) TGK_DN(_) TGK_QN(_)
#define     TGK_B_QN(_) TGK_BN(_) TGK_HN(_) TGK_WN(_) TGK_DN(_) TGK_QN(_)

#define     TGK_B_HR(_) TGK_BR(_) TGK_HR(_)
#define     TGK_H_WR(_)           TGK_HR(_) TGK_WR(_) 
#define     TGK_W_DR(_)                     TGK_WR(_) TGK_DR(_)
#define     TGK_D_QR(_)                               TGK_DR(_) TGK_QR(_)
#define     TGK_B_WR(_) TGK_BR(_) TGK_HR(_) TGK_WR(_) 
#define     TGK_H_DR(_)           TGK_HR(_) TGK_WR(_) TGK_DR(_) 
#define     TGK_W_QR(_)                     TGK_WR(_) TGK_DR(_) TGK_QR(_)
#define     TGK_B_DR(_) TGK_BR(_) TGK_HR(_) TGK_WR(_) TGK_DR(_)
#define     TGK_H_QR(_)           TGK_HR(_) TGK_WR(_) TGK_DR(_) TGK_QR(_)
#define     TGK_B_QR(_) TGK_BR(_) TGK_HR(_) TGK_WR(_) TGK_DR(_) TGK_QR(_)

#ifndef MY_EXTVEC_H

#define     TGD_BI(_)
#define     TGD_BU(_)
#define     TGD_BF(_)

#define     TGD_HI(_)
#define     TGD_HU(_)
#define     TGD_HF(_)

#define     TGD_WI(_)
#define     TGD_WU(_)
#define     TGD_WF(_)

#define     TGD_DI(_)
#define     TGD_DU(_)
#define     TGD_DF(_)


#define     TGD_BZ(_)
#define     TGD_BS(_)
#define     TGD_BN(_)
#define     TGD_BR(_)

#define     TGD_HZ(_)
#define     TGD_HS(_)
#define     TGD_HN(_)
#define     TGD_HR(_)

#define     TGD_WZ(_)
#define     TGD_WS(_)
#define     TGD_WN(_)
#define     TGD_WR(_)

#define     TGD_DZ(_)
#define     TGD_DS(_)
#define     TGD_DN(_)
#define     TGD_DR(_)

#define     TGD_B_HI(_)
#define     TGD_H_WI(_)
#define     TGD_W_DI(_)
#define     TGD_D_QI(_)
#define     TGD_B_WI(_)
#define     TGD_H_DI(_)
#define     TGD_W_QI(_)
#define     TGD_B_DI(_)
#define     TGD_H_QI(_)

#define     TGD_B_HU(_)
#define     TGD_H_WU(_)
#define     TGD_W_DU(_)
#define     TGD_D_QU(_)
#define     TGD_B_WU(_)
#define     TGD_H_DU(_)
#define     TGD_W_QU(_)
#define     TGD_B_DU(_)
#define     TGD_H_QU(_)

#define     TGD_B_HF(_)
#define     TGD_H_WF(_)
#define     TGD_W_DF(_)
#define     TGD_D_QF(_)
#define     TGD_B_WF(_)
#define     TGD_H_DF(_)
#define     TGD_W_QF(_)
#define     TGD_B_DF(_)
#define     TGD_H_QF(_)

#define     TGD_B_HZ(_)
#define     TGD_H_WZ(_)
#define     TGD_W_DZ(_)
#define     TGD_D_QZ(_)
#define     TGD_B_WZ(_)
#define     TGD_H_DZ(_)
#define     TGD_W_QZ(_)
#define     TGD_B_DZ(_)
#define     TGD_H_QZ(_)

#define     TGD_B_HS(_)
#define     TGD_H_WS(_)
#define     TGD_W_DS(_)
#define     TGD_D_QS(_)
#define     TGD_B_WS(_)
#define     TGD_H_DS(_)
#define     TGD_W_QS(_)
#define     TGD_B_DS(_)
#define     TGD_H_QS(_)

#define     TGD_B_HN(_)
#define     TGD_H_WN(_)
#define     TGD_W_DN(_)
#define     TGD_D_QN(_)
#define     TGD_B_WN(_)
#define     TGD_H_DN(_)
#define     TGD_W_QN(_)
#define     TGD_B_DN(_)
#define     TGD_H_QN(_)

#define     TGD_B_HR(_)
#define     TGD_H_WR(_)
#define     TGD_W_DR(_)
#define     TGD_D_QR(_)
#define     TGD_B_WR(_)
#define     TGD_H_DR(_)
#define     TGD_W_QR(_)
#define     TGD_B_DR(_)
#define     TGD_H_QR(_)

#define     TGQ_BI(_)
#define     TGQ_BU(_)
#define     TGQ_BF(_)

#define     TGQ_HI(_)
#define     TGQ_HU(_)
#define     TGQ_HF(_)

#define     TGQ_WI(_)
#define     TGQ_WU(_)
#define     TGQ_WF(_)

#define     TGQ_DI(_)
#define     TGQ_DU(_)
#define     TGQ_DF(_)

#define     TGQ_QI(_)
#define     TGQ_QU(_)
#define     TGQ_QF(_)

#define     TGQ_BZ(_)
#define     TGQ_BS(_)
#define     TGQ_BN(_)
#define     TGQ_BR(_)

#define     TGQ_HZ(_)
#define     TGQ_HS(_)
#define     TGQ_HN(_)
#define     TGQ_HR(_)

#define     TGQ_WZ(_)
#define     TGQ_WS(_)
#define     TGQ_WN(_)
#define     TGQ_WR(_)

#define     TGQ_DZ(_)
#define     TGQ_DS(_)
#define     TGQ_DN(_)
#define     TGQ_DR(_)

#define     TGQ_QZ(_)
#define     TGQ_QS(_)
#define     TGQ_QN(_)
#define     TGQ_QR(_)

#define     TGQ_B_HI(_)
#define     TGQ_H_WI(_)
#define     TGQ_W_DI(_)
#define     TGQ_D_QI(_)
#define     TGQ_B_WI(_)
#define     TGQ_H_DI(_)
#define     TGQ_W_QI(_)
#define     TGQ_B_DI(_)
#define     TGQ_H_QI(_)
#define     TGQ_B_QI(_)

#define     TGQ_B_HU(_)
#define     TGQ_H_WU(_)
#define     TGQ_W_DU(_)
#define     TGQ_D_QU(_)
#define     TGQ_B_WU(_)
#define     TGQ_H_DU(_)
#define     TGQ_W_QU(_)
#define     TGQ_B_DU(_)
#define     TGQ_H_QU(_)
#define     TGQ_B_QU(_)


#define     TGQ_B_HF(_)
#define     TGQ_H_WF(_)
#define     TGQ_W_DF(_)
#define     TGQ_D_QF(_)
#define     TGQ_B_WF(_)
#define     TGQ_H_DF(_)
#define     TGQ_W_QF(_)
#define     TGQ_B_DF(_)
#define     TGQ_H_QF(_)
#define     TGQ_B_QF(_)

#define     TGQ_B_HZ(_)
#define     TGQ_H_WZ(_)
#define     TGQ_W_DZ(_)
#define     TGQ_D_QZ(_)
#define     TGQ_B_WZ(_)
#define     TGQ_H_DZ(_)
#define     TGQ_W_QZ(_)
#define     TGQ_B_DZ(_)
#define     TGQ_H_QZ(_)
#define     TGQ_B_QZ(_)

#define     TGQ_B_HS(_)
#define     TGQ_H_WS(_)
#define     TGQ_W_DS(_)
#define     TGQ_D_QS(_)
#define     TGQ_B_WS(_)
#define     TGQ_H_DS(_)
#define     TGQ_W_QS(_)
#define     TGQ_B_DS(_)
#define     TGQ_H_QS(_)
#define     TGQ_B_QS(_)

#define     TGQ_B_HN(_)
#define     TGQ_H_WN(_)
#define     TGQ_W_DN(_)
#define     TGQ_D_QN(_)
#define     TGQ_B_WN(_)
#define     TGQ_H_DN(_)
#define     TGQ_W_QN(_)
#define     TGQ_B_DN(_)
#define     TGQ_H_QN(_)
#define     TGQ_B_QN(_)

#define     TGQ_B_HR(_)
#define     TGQ_H_WR(_)
#define     TGQ_W_DR(_)
#define     TGQ_D_QR(_)
#define     TGQ_B_WR(_)
#define     TGQ_H_DR(_)
#define     TGQ_W_QR(_)
#define     TGQ_B_DR(_)
#define     TGQ_H_QR(_)
#define     TGQ_B_QR(_)

#define     TGO_BI(_)
#define     TGO_BU(_)
#define     TGO_BF(_)

#define     TGO_HI(_)
#define     TGO_HU(_)
#define     TGO_HF(_)

#define     TGO_WI(_)
#define     TGO_WU(_)
#define     TGO_WF(_)

#define     TGO_DI(_)
#define     TGO_DU(_)
#define     TGO_DF(_)

#define     TGO_QI(_)
#define     TGO_QU(_)
#define     TGO_QF(_)

#define     TGO_BZ(_)
#define     TGO_BS(_)
#define     TGO_BN(_)
#define     TGO_BR(_)

#define     TGO_HZ(_)
#define     TGO_HS(_)
#define     TGO_HN(_)
#define     TGO_HR(_)

#define     TGO_WZ(_)
#define     TGO_WS(_)
#define     TGO_WN(_)
#define     TGO_WR(_)

#define     TGO_DZ(_)
#define     TGO_DS(_)
#define     TGO_DN(_)
#define     TGO_DR(_)

#define     TGO_QZ(_)
#define     TGO_QS(_)
#define     TGO_QN(_)
#define     TGO_QR(_)

#define     TGO_B_HI(_)
#define     TGO_H_WI(_)
#define     TGO_W_DI(_)
#define     TGO_D_QI(_)
#define     TGO_B_WI(_)
#define     TGO_H_DI(_)
#define     TGO_W_QI(_)
#define     TGO_B_DI(_)
#define     TGO_H_QI(_)
#define     TGO_B_QI(_)

#define     TGO_B_HU(_)
#define     TGO_H_WU(_)
#define     TGO_W_DU(_)
#define     TGO_D_QU(_)
#define     TGO_B_WU(_)
#define     TGO_H_DU(_)
#define     TGO_W_QU(_)
#define     TGO_B_DU(_)
#define     TGO_H_QU(_)
#define     TGO_B_QU(_)


#define     TGO_B_HF(_)
#define     TGO_H_WF(_)
#define     TGO_W_DF(_)
#define     TGO_D_QF(_)
#define     TGO_B_WF(_)
#define     TGO_H_DF(_)
#define     TGO_W_QF(_)
#define     TGO_B_DF(_)
#define     TGO_H_QF(_)
#define     TGO_B_QF(_)

#define     TGO_B_HZ(_)
#define     TGO_H_WZ(_)
#define     TGO_W_DZ(_)
#define     TGO_D_QZ(_)
#define     TGO_B_WZ(_)
#define     TGO_H_DZ(_)
#define     TGO_W_QZ(_)
#define     TGO_B_DZ(_)
#define     TGO_H_QZ(_)
#define     TGO_B_QZ(_)

#define     TGO_B_HS(_)
#define     TGO_H_WS(_)
#define     TGO_W_DS(_)
#define     TGO_D_QS(_)
#define     TGO_B_WS(_)
#define     TGO_H_DS(_)
#define     TGO_W_QS(_)
#define     TGO_B_DS(_)
#define     TGO_H_QS(_)
#define     TGO_B_QS(_)

#define     TGO_B_HN(_)
#define     TGO_H_WN(_)
#define     TGO_W_DN(_)
#define     TGO_D_QN(_)
#define     TGO_B_WN(_)
#define     TGO_H_DN(_)
#define     TGO_W_QN(_)
#define     TGO_B_DN(_)
#define     TGO_H_QN(_)
#define     TGO_B_QN(_)

#define     TGO_B_HR(_)
#define     TGO_H_WR(_)
#define     TGO_W_DR(_)
#define     TGO_D_QR(_)
#define     TGO_B_WR(_)
#define     TGO_H_DR(_)
#define     TGO_W_QR(_)
#define     TGO_B_DR(_)
#define     TGO_H_QR(_)
#define     TGO_B_QR(_)


#define     TGS_BI(_)
#define     TGS_BU(_)
#define     TGS_BF(_)

#define     TGS_HI(_)
#define     TGS_HU(_)
#define     TGS_HF(_)

#define     TGS_WI(_)
#define     TGS_WU(_)
#define     TGS_WF(_)

#define     TGS_DI(_)
#define     TGS_DU(_)
#define     TGS_DF(_)

#define     TGS_QI(_)
#define     TGS_QU(_)
#define     TGS_QF(_)


#define     TGS_BZ(_)
#define     TGS_BS(_)
#define     TGS_BN(_)
#define     TGS_BR(_)

#define     TGS_HZ(_)
#define     TGS_HS(_)
#define     TGS_HN(_)
#define     TGS_HR(_)

#define     TGS_WZ(_)
#define     TGS_WS(_)
#define     TGS_WN(_)
#define     TGS_WR(_)

#define     TGS_DZ(_)
#define     TGS_DS(_)
#define     TGS_DN(_)
#define     TGS_DR(_)

#define     TGS_QZ(_)
#define     TGS_QS(_)
#define     TGS_QN(_)
#define     TGS_QR(_)

#define     TGS_B_HI(_)
#define     TGS_H_WI(_)
#define     TGS_W_DI(_)
#define     TGS_D_QI(_)
#define     TGS_B_WI(_)
#define     TGS_H_DI(_)
#define     TGS_W_QI(_)
#define     TGS_B_DI(_)
#define     TGS_H_QI(_)
#define     TGS_B_QI(_)

#define     TGS_B_HU(_)
#define     TGS_H_WU(_)
#define     TGS_W_DU(_)
#define     TGS_D_QU(_)
#define     TGS_B_WU(_)
#define     TGS_H_DU(_)
#define     TGS_W_QU(_)
#define     TGS_B_DU(_)
#define     TGS_H_QU(_)
#define     TGS_B_QU(_)


#define     TGS_B_HF(_)
#define     TGS_H_WF(_)
#define     TGS_W_DF(_)
#define     TGS_D_QF(_)
#define     TGS_B_WF(_)
#define     TGS_H_DF(_)
#define     TGS_W_QF(_)
#define     TGS_B_DF(_)
#define     TGS_H_QF(_)
#define     TGS_B_QF(_)

#define     TGS_B_HZ(_)
#define     TGS_H_WZ(_)
#define     TGS_W_DZ(_)
#define     TGS_D_QZ(_)
#define     TGS_B_WZ(_)
#define     TGS_H_DZ(_)
#define     TGS_W_QZ(_)
#define     TGS_B_DZ(_)
#define     TGS_H_QZ(_)
#define     TGS_B_QZ(_)

#define     TGS_B_HS(_)
#define     TGS_H_WS(_)
#define     TGS_W_DS(_)
#define     TGS_D_QS(_)
#define     TGS_B_WS(_)
#define     TGS_H_DS(_)
#define     TGS_W_QS(_)
#define     TGS_B_DS(_)
#define     TGS_H_QS(_)
#define     TGS_B_QS(_)

#define     TGS_B_HN(_)
#define     TGS_H_WN(_)
#define     TGS_W_DN(_)
#define     TGS_D_QN(_)
#define     TGS_B_WN(_)
#define     TGS_H_DN(_)
#define     TGS_W_QN(_)
#define     TGS_B_DN(_)
#define     TGS_H_QN(_)
#define     TGS_B_QN(_)

#define     TGS_B_HR(_)
#define     TGS_H_WR(_)
#define     TGS_W_DR(_)
#define     TGS_D_QR(_)
#define     TGS_B_WR(_)
#define     TGS_H_DR(_)
#define     TGS_W_QR(_)
#define     TGS_B_DR(_)
#define     TGS_H_QR(_)
#define     TGS_B_QR(_)
#endif

#define     TGK_NONE(_) 
#define     TGD_NONE(_) 
#define     TGQ_NONE(_) 
#define     TGO_NONE(_) 
#define     TGS_NONE(_) 

#define MY_FUNCOF(F, x, K, D, Q, O, S, ...) \
_Generic(       \
    x,          \
    TGK_##K(F)  \
    TGD_##D(F)  \
    TGQ_##Q(F)  \
    TGO_##O(F)  \
    TGS_##S(F)  \
    default:    \
    (NULL __VA_OPT__(,__VA_ARGS__)) \
)

#endif // EOF