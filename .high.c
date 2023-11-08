/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

#if _ENTER_EXTDEF
{
#endif

/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳

    Extends:
    * <stddef.h>
    * <unistd.h>
    * <limits.h>
    * <errno.h>
    * <stdalign.h>
    * <stddef.h>
    * <stdbool.h>

*/

#ifndef MY_EXTDEF_H // BOF
#define MY_EXTDEF_H

#ifndef __STDC_VERSION__
#error "__STDC_VERSION__ is unavailable"
#endif

#if   __STDC_VERSION__ < 201112L
#error "C11 is required"
#endif

#if     __STDC_HOSTED__ != 1
#error "__STDC_HOSTED__ != 1"
#endif

#undef  SAFECALL
#undef  MY_CALL
#undef  MY_SWAP
#undef  uchar
#undef  schar
#undef  ushrt
#undef  ushort
#undef  shrt
#undef  uint
#undef  ulong
#undef  ullong
#undef  llong

#undef  IGNORED
#undef  IDENTITY
#undef  INLINE
#undef  INTRIN
#undef  PUBLIC
#undef  RESTRICT

#undef  ASSERT

#undef  UNUSED
#undef  UNREACHABLE

#define Rc(...) int const
#define Wc(...) unsigned const
#define Lc(...) unsigned long const

#define     MY_REQS(T,X,Y) _Generic(X,T:Y)

#define     BOOL_REQS(X)    MY_REQS(   BOOL_TYPE,(X),(X))
#define     CHAR_REQS(X)    MY_REQS(   CHAR_TYPE,(X),(X))
#define     UCHAR_REQS(X)   MY_REQS(  UCHAR_TYPE,(X),(X))
#define     SCHAR_REQS(X)   MY_REQS(  SCHAR_TYPE,(X),(X))
#define     USHRT_REQS(X)   MY_REQS(  USHRT_TYPE,(X),(X))
#define     SHRT_REQS(X)    MY_REQS(   SHRT_TYPE,(X),(X))
#define     UINT_REQS(X)    MY_REQS(   UINT_TYPE,(X),(X))
#define     INT_REQS(X)     MY_REQS(    INT_TYPE,(X),(X))
#define     ULONG_REQS(X)   MY_REQS(  ULONG_TYPE,(X),(X))
#define     LONG_REQS(X)    MY_REQS(   LONG_TYPE,(X),(X))
#define     ULLONG_REQS(X)  MY_REQS( ULLONG_TYPE,(X),(X))
#define     LLONG_REQS(X)   MY_REQS(   LONG_TYPE,(X),(X))
#define     FLT16_REQS(X)   MY_REQS(  FLT16_TYPE,(X),(X))
#define     FLT_REQS(X)     MY_REQS(    FLT_TYPE,(X),(X))
#define     DBL_REQS(X)     MY_REQS(    DBL_TYPE,(X),(X))

#define     UINT8_REQS(X)   MY_REQS(  UINT8_TYPE,(X),(X))
#define     UINT16_REQS(X)  MY_REQS( UINT16_TYPE,(X),(X))
#define     UINT32_REQS(X)  MY_REQS( UINT32_TYPE,(X),(X))
#define     UINT64_REQS(X)  MY_REQS( UINT64_TYPE,(X),(X))
#define     UINTMAX_REQS(X) MY_REQS(UINTMAX_TYPE,(X),(X))
#define     UINTPTR_REQS(X) MY_REQS(UINTPTR_TYPE,(X),(X))
#define     SIZE_REQS(X)    MY_REQS(   SIZE_TYPE,(X),(X))

#define     INT8_REQS(X)    MY_REQS(    INT8_TYPE,(X),(X))
#define     INT16_REQS(X)   MY_REQS(   INT16_TYPE,(X),(X))
#define     INT32_REQS(X)   MY_REQS(   INT32_TYPE,(X),(X))
#define     INT64_REQS(X)   MY_REQS(   INT64_TYPE,(X),(X))
#define     INTPTR_REQS(X)  MY_REQS( INTPTR_TYPE,(X),(X))
#define     INTMAX_REQS(X)  MY_REQS(  INTMAX_TYPE,(X),(X))
#define     PTRDIFF_REQS(X) MY_REQS( PTRDIFF_TYPE,(X),(X))

#define     VWBU_REQS(X)    MY_REQS(VWBU_TYPE,(X),(X))
#define     VWBI_REQS(X)    MY_REQS(VWBI_TYPE,(X),(X))
#define     VWHU_REQS(X)    MY_REQS(VWHU_TYPE,(X),(X))
#define     VWHI_REQS(X)    MY_REQS(VWHI_TYPE,(X),(X))
#define     VWHF_REQS(X)    MY_REQS(VWHF_TYPE,(X),(X))
#define     VWWU_REQS(X)    MY_REQS(VWWU_TYPE,(X),(X))
#define     VWWI_REQS(X)    MY_REQS(VWWI_TYPE,(X),(X))
#define     VWWF_REQS(X)    MY_REQS(VWWF_TYPE,(X),(X))

#define     VDBU_REQS(X)    MY_REQS(VDBU_TYPE,(X),(X))
#define     VDBI_REQS(X)    MY_REQS(VDBI_TYPE,(X),(X))
#define     VDHU_REQS(X)    MY_REQS(VDHU_TYPE,(X),(X))
#define     VDHI_REQS(X)    MY_REQS(VDHI_TYPE,(X),(X))
#define     VDHF_REQS(X)    MY_REQS(VDHF_TYPE,(X),(X))
#define     VDWU_REQS(X)    MY_REQS(VDWU_TYPE,(X),(X))
#define     VDWI_REQS(X)    MY_REQS(VDWI_TYPE,(X),(X))
#define     VDWF_REQS(X)    MY_REQS(VDWF_TYPE,(X),(X))
#define     VDDU_REQS(X)    MY_REQS(VDDU_TYPE,(X),(X))
#define     VDDI_REQS(X)    MY_REQS(VDDI_TYPE,(X),(X))
#define     VDDF_REQS(X)    MY_REQS(VDDF_TYPE,(X),(X))

#define     VQBU_REQS(X)    MY_REQS(VQBU_TYPE,(X),(X))
#define     VQBI_REQS(X)    MY_REQS(VQBI_TYPE,(X),(X))
#define     VQHU_REQS(X)    MY_REQS(VQHU_TYPE,(X),(X))
#define     VQHI_REQS(X)    MY_REQS(VQHI_TYPE,(X),(X))
#define     VQHF_REQS(X)    MY_REQS(VQHF_TYPE,(X),(X))
#define     VQWU_REQS(X)    MY_REQS(VQWU_TYPE,(X),(X))
#define     VQWI_REQS(X)    MY_REQS(VQWI_TYPE,(X),(X))
#define     VQWF_REQS(X)    MY_REQS(VQWF_TYPE,(X),(X))
#define     VQDU_REQS(X)    MY_REQS(VQDU_TYPE,(X),(X))
#define     VQDI_REQS(X)    MY_REQS(VQDI_TYPE,(X),(X))
#define     VQDF_REQS(X)    MY_REQS(VQDF_TYPE,(X),(X))

#define     VOBU_REQS(X)    MY_REQS(VOBU_TYPE,(X),(X))
#define     VOBI_REQS(X)    MY_REQS(VOBI_TYPE,(X),(X))
#define     VOHU_REQS(X)    MY_REQS(VOHU_TYPE,(X),(X))
#define     VOHI_REQS(X)    MY_REQS(VOHI_TYPE,(X),(X))
#define     VOHF_REQS(X)    MY_REQS(VOHF_TYPE,(X),(X))
#define     VOWU_REQS(X)    MY_REQS(VOWU_TYPE,(X),(X))
#define     VOWI_REQS(X)    MY_REQS(VOWI_TYPE,(X),(X))
#define     VOWF_REQS(X)    MY_REQS(VOWF_TYPE,(X),(X))
#define     VODU_REQS(X)    MY_REQS(VODU_TYPE,(X),(X))
#define     VODI_REQS(X)    MY_REQS(VODI_TYPE,(X),(X))
#define     VODF_REQS(X)    MY_REQS(VODF_TYPE,(X),(X))

#define     VSBU_REQS(X)    MY_REQS(VSBU_TYPE,(X),(X))
#define     VSBI_REQS(X)    MY_REQS(VSBI_TYPE,(X),(X))
#define     VSHU_REQS(X)    MY_REQS(VSHU_TYPE,(X),(X))
#define     VSHI_REQS(X)    MY_REQS(VSHI_TYPE,(X),(X))
#define     VSHF_REQS(X)    MY_REQS(VSHF_TYPE,(X),(X))
#define     VSWU_REQS(X)    MY_REQS(VSWU_TYPE,(X),(X))
#define     VSWI_REQS(X)    MY_REQS(VSWI_TYPE,(X),(X))
#define     VSWF_REQS(X)    MY_REQS(VSWF_TYPE,(X),(X))
#define     VSDU_REQS(X)    MY_REQS(VSDU_TYPE,(X),(X))
#define     VSDI_REQS(X)    MY_REQS(VSDI_TYPE,(X),(X))
#define     VSDF_REQS(X)    MY_REQS(VSDF_TYPE,(X),(X))

#ifndef MY_STDIO_H
#include  <stdio.h>
#define MY_STDIO_H
#endif

#ifndef MY_STDLIB_H
#include  <stdlib.h>
#define MY_STDLIB_H
#endif

static inline void 
MY_NOT_IMPLEMENTED(FILE *dst, char const *why, ...)
{
    va_list seq;
    va_start(seq, why);
    (void) vfprintf(!dst ? stdout : dst, why, seq);
    va_end(seq);
    abort();
}

#define REQZ(Z, X)              \
(                               \
    ((Z)==sizeof(X)) ? (X) :    \
    ((1)==sizeof(X)) ? _Generic((X), int:(X)) :\
    _Generic((X), char:(X)) \
)

#define IGNORED(...)
#define IDENTITY(...) __VA_ARGS__
#define VA_APPEND(_, ...) __VA_OPT__(__VA_ARGS__,) _
#define ENDIAN_OTH  (0)
#define ENDIAN_LIL  (1)
#define ENDIAN_BIG  (2)
#define ENDIAN_NAT  (3)

#if     __STDC_VERSION__ >= 201710L
#   define  ASSERT  static_assert
#endif

#ifndef ASSERT
#if defined(_MSC_VER)
#   define  ASSERT(C, ...) _Static_assert((C), #C)
#else
#   define  ASSERT(C, ...) \
    _Static_assert((C), #C __VA_OPT__(" => \n" #__VA_ARGS__))
#endif
#endif

#define LENGTHOF(x) (sizeof (x)\/sizeof *(x))

#if defined(unreachable)
#   define  UNREACHABLE     unreachable
#elif defined(_MSC_VER)
#   define  UNREACHABLE()   __assume(0)
#elif defined(__GNUC__)
#   define  UNREACHABLE     __builtin_unreachable
#else
#   ifndef  MY_STDLIB_H
#   define  MY_STDLIB_H
#   include   <stdlib.h>
#   define  UNREACHABLE     abort
#   endif
#endif

#if __STDC_VERSION__ <= 201710L
#   if defined(_MSC_VER)
#       define  UNUSED(...) _Pragma("warning(suppress:4100)\n") __VA_ARGS__
#   elif defined(__clang__) || !defined(__GNUC__)
#       define  UNUSED(...) __VA_ARGS__ __attribute__((unused))__
#   endif

#endif

#ifndef UNUSED
#define UNUSED(...) __VA_ARGS__ [[maybe_unused]]
#endif

#if defined(_MSC_VER)
#   define  INLINE(T, F)    static T __forceinline  F
#   define  PUBLIC(T, F)    extern T __vectorcall   F
#   define  INTRIN(T, F)    static T F
#else
#   define  INLINE(T, F)    static inline T F
#   define  PUBLIC(T, F)    extern T F
#   define  INTRIN(T, F)    static T F
#endif

#if defined(_MSC_VER)
#   define RESTRICT(...) __VA_OPT__(__restrict __VA_ARGS__)
#else
#   define RESTRICT(...) __VA_OPT__(  restrict __VA_ARGS__)
#endif

#ifndef MY_LIMITS_H
#define MY_LIMITS_H
#include  <limits.h>
#endif

#ifndef MY_ERRNO_H
#define MY_ERRNO_H
#include  <errno.h>
#endif

#ifndef MY_STDBOOL_H
#define MY_STDBOOL_H
#include  <stdbool.h>
#endif

#ifndef MY_STDDEF_H
#define MY_STDDEF_H
#include  <stddef.h>
#endif

#if _ENTER_EXTDEF_ISA
{
#endif

#define ISA_X86     1
#define ISA_ARM     3
#define ISA_RV      5
#define ISA_PPC     6
#define ISA_MIPS    7
#define ISA_IA64    8

#if defined(__x86_64__)
#   define  MY_ISA  ISA_X86
#   define  SPC_X86_X64

#elif defined(__ARM_ACLE)
#   define  MY_ISA  ISA_ARM

#elif defined(__riscv)
#   define  MY_ISA  ISA_RV

#   if  defined(__ILP32__)
#       define  SPC_RV_I32
#   elif  defined(__LP64__)
#       define  SPC_RV_I64
#   elif  (ULLONG_MAX>>63) > 18446744073709551615ull
#       define  SPC_RV_I128
#   else
#       error "unknown risc-v ISA"
#   endif

#elif defined(__PPC64__)
#   define  MY_ISA      ISA_PPC
#   define  MY_ENDIAN \
    ((__BYTE_ORDER__==__ORDER_BIG_ENDIAN__)?ENDIAN_BIG:ENDIAN_LIL)

#elif defined(__PPC__)
#   define  MY_ISA      ISA_PPC
#   define  MY_ENDIAN \
    ((__BYTE_ORDER__==__ORDER_BIG_ENDIAN__)?ENDIAN_BIG:ENDIAN_LIL)

#elif defined(__mips__)
#   define  MY_ISA       ISA_MIPS
#   ifdef   __MIPSEB__
#   define  MY_ENDIAN   ENDIAN_BIG
#   endif

#   ifdef   __MIPSEL__
#   define  MY_ENDIAN   ENDIAN_LIL
#   endif

#elif defined(_M_ARM64EC)
#   define  MY_ISA      ISA_X86
#   define  SPC_X86_X64

#elif defined(_M_X64) || defined(_M_AMD64)
#   define  MY_ISA      ISA_X86
#   define  SPC_X86_X64

#elif defined(_M_IA64)
#   define  MY_ISA      ISA_IA64

#elif defined(_M_IX86)
#   define  MY_ISA      ISA_X86

#elif defined(_M_ARM64)
#   define  MY_ISA      ISA_ARM

#elif defined(_M_ARM)
#   define  MY_ISA      ISA_ARM

#elif defined(_M_ARMV7VE)
#   define  MY_ISA      ISA_ARM

#elif defined(_M_ALPHA)
#   define  MY_ISA      ISA_ALPHA

#elif defined(_M_PPC)
#   define  MY_ISA      ISA_PPC

#elif defined(_M_MRX000)
#   error "wtf is this"

#else
#   error "unable to detect target instruction set architecture"
#endif

#if _LEAVE_EXTDEF_ISA
}
#endif

#if _ENTER_EXTDEF_SPC_ARM
{
#endif

#if MY_ISA == ISA_ARM

#   ifndef  MY_ARM_ACLE_H
#   define  MY_ARM_ACLE_H
#   include  <arm_acle.h>
#   endif

#   ifndef __ARM_ARCH_PROFILE
#   error "__ARM_ARCH_PROFILE undefined"
#   endif

#   ifndef __ARM_FP
#   error "__ARM_FP undefined"
#   endif

#   ifndef __ARM_NEON
#   error "__ARM_NEON undefined"
#   endif

#   if !(__ARM_FP&0x02)
#   error "hardware 'float' support is expected"
#   endif

#   if defined(__ARM_FP16_FORMAT_ALTERNATIVE)
#   error "__fp16 is expected to be based on binary16"
#   endif

#   if   __ARM_ARCH >= 900
#       define  SPC_ARM_V9  (__ARM_ARCH%100)
#       define  SPC_ARM_V8  (8)
#   elif __ARM_ARCH >= 800
#       define  SPC_ARM_V9  (0)
#       define  SPC_ARM_V8  (__ARM_ARCH%100)
#   elif defined(SPC_ARM_V8)
#       define  SPC_ARM_V9  (0)
#   else
#       define  SPC_ARM_V8  (1)
#       define  SPC_ARM_V9  (0)
#   endif

#   define  SPC_ARM_V7   (7)
#   define  SPC_ARM_ACLE
#   define  SPC_ARM_NEON
#   define  SPC_ARM_PROFILE  __ARM_ARCH_PROFILE

#   ifdef   __ARM_FEATURE_LDREX
#   define  SPC_ARM_LDREX    __ARM_FEATURE_LDREX
#   endif

#   ifndef  SPC_ARM_LDREX
#   define  SPC_ARM_LDREX   (0)
#   endif

#   define  SPC_ARM_LDREX_B ((0x01&SPC_ARM_LDREX) != 0)
#   define  SPC_ARM_LDREX_H ((0x02&SPC_ARM_LDREX) != 0)
#   define  SPC_ARM_LDREX_W ((0x04&SPC_ARM_LDREX) != 0)
#   define  SPC_ARM_LDREX_D ((0x08&SPC_ARM_LDREX) != 0)
#   define  SPC_ARM_LDREX_Q ((0x10&SPC_ARM_LDREX) != 0)

#   ifdef   __ARM_FEATURE_FP16_SCALAR_ARITHMETIC
#   define  SPC_ARM_FP16_MATH   __ARM_FEATURE_FP16_SCALAR_ARITHMETIC
#   endif

#   ifdef   __ARM_FEATURE_FP16_VECTOR_ARITHMETIC
#   define  SPC_ARM_FP16_SIMD   __ARM_FEATURE_FP16_VECTOR_ARITHMETIC
/*
vmulh_lane_f16, vmulh_laneq_f16
vabd_f16,   vabdq_f16
vabs_f16,   vabsq_f16
vadd_f16,   vaddq_f16
vbsl_f16,   vbslq_f16
vcage_f16,  vcageq_f16

vcagt_f16,  vcagtq_f16
vcale_f16,  vcaleq_f16
vcalt_f16,  vcaltq_f16
vceq_f16,   vceqq_f16
vceqz_f16,  vceqzq_f16
vcge_f16,   vcgeq_f16
vcgez_f16,  vcgezq_f16
vcgt_f16,   vcgtq_f16
vcgtz_f16,      vcgtzq_f16
vcle_f16,       vcleq_f16
vclez_f16,      vclezq_f16
vclt_f16,       vcltq_f16
vcltz_f16,      vcltzq_f16
vcvt_f16_u16,   vcvtq_f16_u16
vcvt_u16_f16,   vcvtq_u16_f16
vcvt_f16_s16,   vcvtq_f16_s16
vcvt_s16_f16,   vcvtq_s16_f16
vcvt_n_f16_s16, vcvtq_n_f16_s16
vcvt_n_f16_u16, vcvtq_n_f16_u16
vcvt_n_s16_f16, vcvtq_n_s16_f16
vcvt_n_u16_f16, vcvtq_n_u16_f16

vcvta_f16_u16,   vcvtaq_f16_u16
vcvta_u16_f16,   vcvtaq_u16_f16
vcvta_f16_s16,   vcvtaq_f16_s16
vcvta_s16_f16,   vcvtaq_s16_f16

vcvtm_f16_u16,   vcvtmq_f16_u16
vcvtm_u16_f16,   vcvtmq_u16_f16
vcvtm_f16_s16,   vcvtmq_f16_s16
vcvtm_s16_f16,   vcvtmq_s16_f16

vcvtn_f16_u16,   vcvtnq_f16_u16
vcvtn_u16_f16,   vcvtnq_u16_f16
vcvtn_f16_s16,   vcvtnq_f16_s16
vcvtn_s16_f16,   vcvtnq_s16_f16

vcvtp_f16_u16,   vcvtpq_f16_u16
vcvtp_u16_f16,   vcvtpq_u16_f16
vcvtp_f16_s16,   vcvtpq_f16_s16
vcvtp_s16_f16,   vcvtpq_s16_f16
vext_f16,       vextq_f16
vfma_f16,       vfmaq_f16
vfms_f16,       vfmsq_f16
vmax_f16,       vmaxq_f16
vmin_f16,       vminq_f16
vmul_f16,       vmulq_f16
vmul_lane_f16,  vmulq_lane_f16
vmul_n_f16,     vmulq_n_f16
vneg_f16,       vnegq_f16
vpadd_f16,      vpaddq_f16
vpmax_f16,      vpmaxq_f16
vpmin_f16,      vpminq_f16
vrecpe_f16,     vrecpeq_f16
vrecps_f16,     vrecpsq_f16
vrev64_f16,     vrev64q_f16

vrsqrte_f16,vrsqrteq_f16
vrsqrts_f16,vrsqrtsq_f16
vsub_f16,vsubq_f16
vtrn_f16,vtrnq_f16
vuzp_f16,vuzpq_f16
vzip_f16,vzipq_f16
vdiv_f16,vdivq_f16
vduph_lane_f16,vduph_laneq_f16
vfmah_lane_f16
vfma_lane_f16,vfmaq_lane_f16
vmaxv_f16,vmaxvq_f16
vminv_f16,vminq_f16
vmaxnmv_f16,vmaxnmvq_f16
vminnmv_f16,vminnmvq_f16
vmulq_laneq_f16
vmul_laneq_f16
vmulx_f16,vmulxq_f16
*/


#   endif

#   ifdef   __ARM_FP16_ARGS
#   define  SPC_ARM_FP16_ARGS   __ARM_FP16_ARGS
#   endif

#   ifdef   __ARM_FP_FENV_ROUNDING
#   define  SPC_ARM_FENV         __ARM_FP_FENV_ROUNDING
#   endif

#   ifdef   __ARM_FEATURE_CLZ
#   define  SPC_ARM_CLZ         __ARM_FEATURE_CLZ
#   endif

#   ifdef   __ARM_FEATURE_IDIV
#   define  SPC_ARM_IDIV        __ARM_FEATURE_IDIV
#   endif

#   ifdef   __ARM_FEATURE_FMA
#   define  SPC_ARM_FMA         __ARM_FEATURE_FMA
#   endif

#   ifdef   __ARM_FEATURE_FP16_FML
#   define  SPC_ARM_FP16_FML
#   endif

#   ifdef   __ARM_FEATURE_UNALIGNED_ACCESS
#   define  SPC_ARM_UNALIGNED   __ARM_FEATURE_UNALIGNED_ACCESS
#   endif

#   ifdef   __ARM_FEATURE_BTI_DEFAULT
#   define  SPC_ARM_BTIDEF      __ARM_FEATURE_BTI_DEFAULT
#   endif

#   ifdef   __ARM_FEATURE_PAC_DEFAULT
#   define  SPC_ARM_PACDEF      __ARM_FEATURE_PAC_DEFAULT
#   endif

#   ifdef   __ARM_FEATURE_CRC32
#   define  SPC_ARM_CRC32       __ARM_FEATURE_CRC32
#   endif

#   ifdef   __ARM_FEATURE_AES
#   define  SPC_ARM_AES         __ARM_FEATURE_AES
#   endif

#   ifdef   __ARM_FEATURE_SHA2
#   define  SPC_ARM_SHA2        __ARM_FEATURE_SHA2
#   endif

#   ifdef   __ARM_FEATURE_SHA3
#   define  SPC_ARM_SHA3        __ARM_FEATURE_SHA3
#   endif

#   ifdef   __ARM_FEATURE_SHA512
#   define  SPC_ARM_SHA512      __ARM_FEATURE_SHA512
#   endif

#   ifdef   __ARM_FEATURE_SM3
#   define  SPC_ARM_SM3         __ARM_FEATURE_SM3
#   endif

#   ifdef   __ARM_FEATURE_SM4
#   define  SPC_ARM_SM4         __ARM_FEATURE_SM4
#   endif

#   ifdef   __ARM_FEATURE_DOTPROD
#   define  SPC_ARM_DOTPROD     __ARM_FEATURE_DOTPROD
#   endif

#   ifdef   __ARM_FEATURE_COMPLEX
#   define  SPC_ARM_COMPLEX     __ARM_FEATURE_COMPLEX
#   endif

#   ifdef   __ARM_FEATURE_JCVT
#   define  SPC_ARM_JCVT        __ARM_FEATURE_JCVT
#   endif

#   ifdef   __ARM_FEATURE_RNG
#   define  SPC_ARM_RNG         __ARM_FEATURE_RNG
#   endif

#   ifdef   __ARM_FEATURE_TME
#   define  SPC_ARM_TME         __ARM_FEATURE_TME
#   endif

#   ifdef   __ARM_FEATURE_MTE
#   define  SPC_ARM_MTE         __ARM_FEATURE_MTE
#   endif

#   ifdef   __ARM_FEATURE_FRINT
#   define  SPC_ARM_FRINT       __ARM_FEATURE_FRINT
#   endif

#   ifdef   __ARM_64BIT_STATE
#   define  SPC_ARM_A64         __ARM_64BIT_STATE
#   endif

#   ifdef   __ARM_FEATURE_MATMUL_INT8
#   define  SPC_ARM_MATMUL_INT8 __ARM_FEATURE_MATMUL_INT8
#   endif

#   ifdef   __ARM_FEATURE_DIRECTED_ROUNDING
#   define  SPC_ARM_DR          __ARM_FEATURE_DIRECTED_ROUNDING
#   endif

#   ifdef   __ARM_FEATURE_FMA
#   define  SPC_ARM_FMA         __ARM_FEATURE_FMA
#   endif

#   ifdef   __ARM_FEATURE_NUMERIC_MAXMIN
#   define  SPC_ARM_MAXMIN      __ARM_FEATURE_NUMERIC_MAXMIN
#   endif

#   ifdef   __ARM_FEATURE_LS64
#   define  SPC_ARM_LS64        __ARM_FEATURE_LS64
#   endif

#   if  defined(__ARM_BIG_ENDIAN)
#       define MY_ENDIAN   ENDIAN_BIG
#   else
#       define MY_ENDIAN   ENDIAN_LIL
#   endif

#endif

#if _LEAVE_EXTDEF_SPC_ARM
}
#endif

#if _ENTER_EXTDEF_SPC_X86
{
#endif

#if defined(__AVX512FP16__)
#   ifndef  SPC_X86_AVX512FP16
#   define  SPC_X86_AVX512FP16
#   endif
#endif

#if defined(__AVX512BF16__) || defined(SPC_X86_FP16)
#   ifndef  SPC_X86_AVX512BF16
#   define  SPC_X86_AVX512BF16
#   endif
#endif

#if defined(__AVX512VPOPCNTDQ__) || defined(SPC_X86_BF16)
#   ifndef  SPC_X86_AVX512VPOPCNTDQ
#   define  SPC_X86_AVX512VPOPCNTDQ
#   endif
#endif

#if defined(__AVX512BITALG__) || defined(SPC_X86_VPOPCNTDQ)
#   ifndef  SPC_X86_AVX512BITALG
#   define  SPC_X86_AVX512BITALG
#   endif
#endif

#if defined(__GFNI__) || defined(SPC_X86_AVX512BITALG)
#   ifndef  SPC_X86_AVX512GFNI
#   define  SPC_X86_AVX512GFNI
#   endif
#endif

#if defined(__AVX512VNNI__) || defined(SPC_X86_AVX512BITALG)
#   ifndef  SPC_X86_AVX512VNNI
#   define  SPC_X86_AVX512VNNI
#   endif
#endif

#if defined(__AVX512VBMI2__) || defined(SPC_X86_AVX512VNNI)
#   ifndef  SPC_X86_AVX512VBMI2
#   define  SPC_X86_AVX512VBMI2
#   endif
#endif

#if defined(__AVX512VBMI__) || defined(SPC_X86_AVX512VBMI2)
#   ifndef  SPC_X86_AVX512VBMI
#   define  SPC_X86_AVX512VBMI
#   endif
#endif

#if defined(__AVX512IFMA__) || defined(SPC_X86_AVX512VBMI)
#   ifndef  SPC_X86_AVX512IFMA
#   define  SPC_X86_AVX512IFMA
#   endif
#endif

#if defined(__AVX512VL__) || defined(SPC_X86_AVX512IFMA)
#   ifndef  SPC_X86_AVX512VL
#   define  SPC_X86_AVX512VL
#   endif
#endif

#if defined(__AVX512CD__) || defined(SPC_X86_AVX512VL)
#   ifndef  SPC_X86_AVX512CD
#   define  SPC_X86_AVX512CD
#   endif
#endif

#if defined(__AVX512BW__) || defined(SPC_X86_AVX512VL)
#   ifndef  SPC_X86_AVX512BW
#   define  SPC_X86_AVX512BW
#   endif
#endif

#if defined(__AVX512DQ__) || defined(SPC_X86_AVX512VL)
#   ifndef  SPC_X86_AVX512DQ
#   define  SPC_X86_AVX512DQ
#   endif
#endif

#if defined(__AVX512F__) || defined(SPC_X86_AVX512VL)
#   ifndef  SPC_X86_AVX512F
#   define  SPC_X86_AVX512F
#   endif
#endif

#if defined(__AVX2__) || defined(SPC_X86_AVX512F)
#   ifndef  SPC_X86_AVX2
#   define  SPC_X86_AVX2
#   endif
#endif

#if defined(__AVX__) || defined(SPC_X86_AVX2)
#   ifndef  SPC_X86_AVX
#   define  SPC_X86_AVX
#   endif
#endif

#if defined(__SSE4_2__) || defined(SPC_X86_AVX)
#   ifndef  SPC_X86_SSE42
#   define  SPC_X86_SSE42
#   endif
#endif

#if defined(__SSE4_1__) || defined(SPC_X86_SSE42)
#   ifndef  SPC_X86_SSE41
#   define  SPC_X86_SSE41
#   endif
#endif

#if defined(__SSSE3__) || defined(SPC_X86_SSE41)
#   ifndef  SPC_X86_SSSE3
#   define  SPC_X86_SSSE3
#   endif
#endif

#if defined(__SSE3__) || defined(SPC_X86_SSSE3)
#   ifndef  SPC_X86_SSE3
#   define  SPC_X86_SSE3
#   endif
#endif

#if defined(__SSE2__) || defined(SPC_X86_SSE3)
#   ifndef  SPC_X86_SSE2
#   define  SPC_X86_SSE2
#   endif
#endif

#if defined(__SSE__) || defined(SPC_X86_SSE2)
#   ifndef  SPC_X86_SSE
#   define  SPC_X86_SSE
#   endif
#endif

#if defined(__MMX__) || defined(SPC_X86_SSE)
#   ifndef  SPC_X86_MMX
#   define  SPC_X86_MMX
#   endif
#endif

#if _LEAVE_EXTDEF_SPC_X86
}
#endif

#if (MY_ISA==ISA_RV) || (MY_ISA==ISA_PPC)
#   ifndef  MY_ENDIAN
#   define  MY_ENDIAN                       \
(                                           \
    (__BYTE_ORDER__==__ORDER_BIG_ENDIAN__)  \
    ?   ENDIAN_BIG                          \
    :   ENDIAN_LIL                          \
)
#   endif

#endif

#ifndef MY_ENDIAN
#define MY_ENDIAN   ENDIAN_LIL
#endif

#ifndef MY_VECTOR_ENDIAN
#define MY_VECTOR_ENDIAN    MY_ENDIAN
#endif

#if MY_VECTOR_ENDIAN == ENDIAN_NAT
#   undef   MY_VECTOR_ENDIAN
#   define  MY_VECTOR_ENDIAN    MY_ENDIAN
#endif

#ifndef MY_PAGESZ
#define MY_PAGESZ    (4096)
#endif

#define CONCAT1(_0,            ...) _0##__VA_ARGS__
#define CONCAT2(_0, _1,        ...) _0##__VA_ARGS__##_1
#define CONCAT3(_0, _1, _2,    ...) _0##__VA_ARGS__##_1##__VA_ARGS__##_2

#define MY_CONCAT1(_0,         ...) _0##__VA_ARGS__
#define MY_CONCAT2(_0, _1,     ...) _0##__VA_ARGS__##_1
#define MY_CONCAT3(_0, _1, _2, ...) _0##__VA_ARGS__##_1##__VA_ARGS__##_2

#define MY_STRIFY(prefix, string) prefix ## string
#define MY_LCSIFY(...) MY_STRIFY(L, #__VA_ARGS__)
#define MY_UCSIFY(...) MY_STRIFY(u, #__VA_ARGS__)
#define MY_WCSIZE(...) MY_STRIFY(U, #__VA_ARGS__)

#define MY_C16IZE0(...) MY_WCSIZE( u, #__VA_ARGS__)
#define MY_C16IZE1(...) MY_C16IZE0(__VA_ARGS__)
#define MY_C16IZE2(...) MY_C16IZE1(__VA_ARGS__)
#define MY_C16IZE3(...) MY_C16IZE2(__VA_ARGS__)
#define MY_C16IZE4(...) MY_C16IZE3(__VA_ARGS__)
#define MY_C16IZE5(...) MY_C16IZE4(__VA_ARGS__)
#define MY_C16IZE6(...) MY_C16IZE5(__VA_ARGS__)
#define MY_C16IZE7(...) MY_C16IZE6(__VA_ARGS__)
#define MY_C16IZE8(...) MY_C16IZE7(__VA_ARGS__)

#define MY_C32IZE0(...) MY_WCSIZE( U, #__VA_ARGS__)
#define MY_C32IZE1(...) MY_C32IZE0(__VA_ARGS__)
#define MY_C32IZE2(...) MY_C32IZE1(__VA_ARGS__)
#define MY_C32IZE3(...) MY_C32IZE2(__VA_ARGS__)
#define MY_C32IZE4(...) MY_C32IZE3(__VA_ARGS__)
#define MY_C32IZE5(...) MY_C32IZE4(__VA_ARGS__)
#define MY_C32IZE6(...) MY_C32IZE5(__VA_ARGS__)
#define MY_C32IZE7(...) MY_C32IZE6(__VA_ARGS__)
#define MY_C32IZE8(...) MY_C32IZE7(__VA_ARGS__)

#define MY_STRIZE0(...)           #__VA_ARGS__
#define MY_STRIZE1(...) MY_STRIZE0(__VA_ARGS__)
#define MY_STRIZE2(...) MY_STRIZE1(__VA_ARGS__)
#define MY_STRIZE3(...) MY_STRIZE2(__VA_ARGS__)
#define MY_STRIZE4(...) MY_STRIZE3(__VA_ARGS__)
#define MY_STRIZE5(...) MY_STRIZE4(__VA_ARGS__)
#define MY_STRIZE6(...) MY_STRIZE5(__VA_ARGS__)
#define MY_STRIZE7(...) MY_STRIZE6(__VA_ARGS__)
#define MY_STRIZE8(...) MY_STRIZE7(__VA_ARGS__)

#define STRIZE0(...)           #__VA_ARGS__
#define STRIZE1(...) MY_STRIZE0(__VA_ARGS__)
#define STRIZE2(...) MY_STRIZE1(__VA_ARGS__)
#define STRIZE3(...) MY_STRIZE2(__VA_ARGS__)
#define STRIZE4(...) MY_STRIZE3(__VA_ARGS__)
#define STRIZE5(...) MY_STRIZE4(__VA_ARGS__)
#define STRIZE6(...) MY_STRIZE5(__VA_ARGS__)
#define STRIZE7(...) MY_STRIZE6(__VA_ARGS__)
#define STRIZE8(...) MY_STRIZE7(__VA_ARGS__)

#define MY_EXPAND8(...) MY_EXPAND7(__VA_ARGS__)
#define MY_EXPAND7(...) MY_EXPAND6(__VA_ARGS__)
#define MY_EXPAND6(...) MY_EXPAND5(__VA_ARGS__)
#define MY_EXPAND5(...) MY_EXPAND4(__VA_ARGS__)
#define MY_EXPAND4(...) MY_EXPAND3(__VA_ARGS__)
#define MY_EXPAND3(...) MY_EXPAND2(__VA_ARGS__)
#define MY_EXPAND2(...) MY_EXPAND1(__VA_ARGS__)
#define MY_EXPAND1(...)            __VA_ARGS__

#define EXPAND8(...)    MY_EXPAND7(__VA_ARGS__)
#define EXPAND7(...)    MY_EXPAND6(__VA_ARGS__)
#define EXPAND6(...)    MY_EXPAND5(__VA_ARGS__)
#define EXPAND5(...)    MY_EXPAND4(__VA_ARGS__)
#define EXPAND4(...)    MY_EXPAND3(__VA_ARGS__)
#define EXPAND3(...)    MY_EXPAND2(__VA_ARGS__)
#define EXPAND2(...)    MY_EXPAND1(__VA_ARGS__)
#define EXPAND1(...)               __VA_ARGS__

#define SAFECALL(TYPE, _, FUNC, ...) \
_Generic((_), TYPE:FUNC(__VA_ARGS__))

#define MY_CALL(F, ...) F(__VA_ARGS__)
#define _SWAP(a, b) do                      \
{                                           \
    char _SWAP[sizeof(a)];                  \
    (void) memcpy(_SWAP, &(a), sizeof(a));  \
    (a)=(b);                                \
    (void) memcpy(&(b), _SWAP, sizeof(a));  \
} while(0)
#define MY_FILL2( x, _) x _ x
#define MY_FILL4( x, _) x _ x _ x _ x
#define MY_FILL8( x, _) MY_FILL4(x, _) _ MY_FILL4(x, _)
#define MY_FILL16(x, _) MY_FILL8(x, _) _ MY_FILL8(x, _)
#define MY_FILL32(x, _) MY_FILL16(x,_) _ MY_FILL16(x,_)
#define MY_FILL64(x, _) MY_FILL32(x,_) _ MY_FILL32(x,_)
#define MY_EXTZ1(c, v, i, x, ...)   c((v)[(i)+x*0])
#define MY_EXTZ2(c, v, i, x, ...)   \
    c((v)[(i)]), c((v)[(i)+x])
#define MY_EXTZ4(c, v, i, x, ...)   \
    c((v)[(i)    ]), c((v)[(i)+x  ]),\
    c((v)[(i)+x*2]), c((v)[(i)+x*3])
#define MY_EXTZ8(c, v, i, x, ...)   \
    c((v)[(i)    ]), c((v)[(i)+x  ]),\
    c((v)[(i)+x*2]), c((v)[(i)+x*3]),\
    c((v)[(i)+x*4]), c((v)[(i)+x*5]),\
    c((v)[(i)+x*6]), c((v)[(i)+x*7])
#define MY_EXTZ16(c, v, i, x, ...)  \
    MY_EXTZ8(c, v,  i,      x),     \
    MY_EXTZ8(c, v, (i)+x*8, x)
#define MY_EXTZ32(c, v, i, x, ...) \
    MY_EXTZ16(c, v,  i ,      x),   \
    MY_EXTZ16(c, v, (i)+x*16, x)
#define MY_EXTZ64(c, v, i, x, ...)  \
    MY_EXTZ32(c, v,  i ,      x),   \
    MY_EXTZ32(c, v, (i)+x*32, x)
#define MY_EXTC1(c, v, i, ...)  \
    MY_EXTZ1(c,  v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTC2(c, v, i, ...)  \
    MY_EXTZ2(c,  v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTC4(c, v, i, ...)  \
    MY_EXTZ4(c,  v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTC8(c, v, i, ...)  \
    MY_EXTZ8(c,  v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTC16(c, v, i, ...)  \
    MY_EXTZ16(c, v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTC32(c, v, i, ...)  \
    MY_EXTZ32(c, v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTC64(c, v, i, ...)  \
    MY_EXTZ64(c, v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTI1(v, i, ...)  \
    MY_EXTZ1(IDENTITY,  v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTI2(v, i, ...)  \
    MY_EXTZ2(IDENTITY,  v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTI4(v, i, ...)  \
    MY_EXTZ4(IDENTITY,  v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTI8(v, i, ...)  \
    MY_EXTZ8(IDENTITY,  v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTI16(v, i, ...)  \
    MY_EXTZ16(IDENTITY, v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTI32(v, i, ...)  \
    MY_EXTZ32(IDENTITY, v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTI64(v, i, ...)  \
    MY_EXTZ64(IDENTITY, v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_SEQC1( c, n, x, ...) c(n+x* 0)
#define MY_SEQC2( c, n, x, ...) c(n+x* 0),c(n+x* 1)
#define MY_SEQC4( c, n, x, ...) \
c(n+x* 0),c(n+x* 1),c(n+x* 2), c(n+x* 3)
#define MY_SEQC8( c,n,x,...)            \
c(n+x*0),c(n+x*1),c(n+x*2),c(n+x*3),    \
c(n+x*4),c(n+x*5),c(n+x*6),c(n+x*7)
#define MY_SEQC16(c,n,x,...)            \
c(n+x* 0),c(n+x* 1),c(n+x* 2),c(n+x* 3),\
c(n+x* 4),c(n+x* 5),c(n+x* 6),c(n+x* 7),\
c(n+x* 8),c(n+x* 9),c(n+x*10),c(n+x*11),\
c(n+x*12),c(n+x*13),c(n+x*14),c(n+x*15)
#define MY_SEQC32(c,n,x,...)            \
c(n+x* 0),c(n+x* 1),c(n+x* 2),c(n+x* 3),\
c(n+x* 4),c(n+x* 5),c(n+x* 6),c(n+x* 7),\
c(n+x* 8),c(n+x* 9),c(n+x*10),c(n+x*11),\
c(n+x*12),c(n+x*13),c(n+x*14),c(n+x*15),\
c(n+x*16),c(n+x*17),c(n+x*18),c(n+x*19),\
c(n+x*20),c(n+x*21),c(n+x*22),c(n+x*23),\
c(n+x*24),c(n+x*25),c(n+x*26),c(n+x*27),\
c(n+x*28),c(n+x*29),c(n+x*30),c(n+x*31)
#define MY_SEQC64(c,n,x,...)            \
c(n+x* 0),c(n+x* 1),c(n+x* 2),c(n+x* 3),\
c(n+x* 4),c(n+x* 5),c(n+x* 6),c(n+x* 7),\
c(n+x* 8),c(n+x* 9),c(n+x*10),c(n+x*11),\
c(n+x*12),c(n+x*13),c(n+x*14),c(n+x*15),\
c(n+x*16),c(n+x*17),c(n+x*18),c(n+x*19),\
c(n+x*20),c(n+x*21),c(n+x*22),c(n+x*23),\
c(n+x*24),c(n+x*25),c(n+x*26),c(n+x*27),\
c(n+x*28),c(n+x*29),c(n+x*30),c(n+x*31),\
c(n+x*32),c(n+x*33),c(n+x*34),c(n+x*35),\
c(n+x*36),c(n+x*37),c(n+x*38),c(n+x*39),\
c(n+x*40),c(n+x*41),c(n+x*42),c(n+x*43),\
c(n+x*44),c(n+x*45),c(n+x*46),c(n+x*47),\
c(n+x*48),c(n+x*49),c(n+x*50),c(n+x*51),\
c(n+x*52),c(n+x*53),c(n+x*54),c(n+x*55),\
c(n+x*56),c(n+x*57),c(n+x*58),c(n+x*59),\
c(n+x*60),c(n+x*61),c(n+x*62),c(n+x*63)
#define SEQC1( c,n,...)  MY_SEQC1( c,n,__VA_OPT__(__VA_ARGS__,) 1)
#define SEQC2( c,n,...)  MY_SEQC2( c,n,__VA_OPT__(__VA_ARGS__,) 1)
#define SEQC4( c,n,...)  MY_SEQC4( c,n,__VA_OPT__(__VA_ARGS__,) 1)
#define SEQC8( c,n,...)  MY_SEQC8( c,n,__VA_OPT__(__VA_ARGS__,) 1)
#define SEQC16(c,n,...)  MY_SEQC16(c,n,__VA_OPT__(__VA_ARGS__,) 1)
#define SEQC32(c,n,...)  MY_SEQC32(c,n,__VA_OPT__(__VA_ARGS__,) 1)
#define SEQC64(c,n,...)  MY_SEQC64(c,n,__VA_OPT__(__VA_ARGS__,) 1)
#define MY_SEQI(x) x
#define SEQI1( n,...)    MY_SEQC1( MY_SEQI,n,__VA_OPT__(__VA_ARGS__,) 1)
#define SEQI2( n,...)    MY_SEQC2( MY_SEQI,n,__VA_OPT__(__VA_ARGS__,) 1)
#define SEQI4( n,...)    MY_SEQC4( MY_SEQI,n,__VA_OPT__(__VA_ARGS__,) 1)
#define SEQI8( n,...)    MY_SEQC8( MY_SEQI,n,__VA_OPT__(__VA_ARGS__,) 1)
#define SEQI16(n,...)    MY_SEQC16(MY_SEQI,n,__VA_OPT__(__VA_ARGS__,) 1)
#define SEQI32(n,...)    MY_SEQC32(MY_SEQI,n,__VA_OPT__(__VA_ARGS__,) 1)
#define SEQI64(n,...)    MY_SEQC64(MY_SEQI,n,__VA_OPT__(__VA_ARGS__,) 1)
#define HALF_BYTEMASK(k)   (UINT16_C(0xff)<<((k)<<3))
#define WORD_BYTEMASK(k)   (UINT32_C(0x00ff)<<((k)<<3))
#define WORD_HALFMASK(k)   (UINT32_C(0xffff)<<((k)<<4))
#define DWRD_BYTEMASK(k)   (UINT64_C(0x000000ff)<<((k)<<3))
#define DWRD_HALFMASK(k)   (UINT64_C(0x0000ffff)<<((k)<<4))
#define DWRD_WORDMASK(k)   (UINT64_C(0xffffffff)<<((k)<<5))

typedef unsigned char        uchar;
typedef   signed char        schar;
typedef unsigned short       ushrt, ushort, ndig_t;
typedef   signed short        shrt;
typedef unsigned int          uint;
typedef unsigned long        ulong;
typedef unsigned long long  ullong;
typedef   signed long long   llong;

#define NDIG_MAX (65535)
#define NDIG_MIN (0)
#define NDIG_C(C) (C)
#define MY_CALL1(F, ...)    F(__VA_ARGS__)
#define MY_CALL2(F, ...)    MY_CALL1(F, __VA_ARGS__)
#define MY_CALL3(F, ...)    MY_CALL2(F, __VA_ARGS__)
#define MY_CALL4(F, ...)    MY_CALL3(F, __VA_ARGS__)

#endif // EOF

#if _LEAVE_EXTDEF
}
#endif

#if _ENTER_EXTNUM
{
#endif
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳

<extnum.h>

    This file combines and extends the following C11 standard
    library headers:

    * <float.h>
    * <stdalign.h>
    * <stdbool.h>
    * <stddef.h>
    * <stdint.h>
*/
#ifndef MY_EXTNUM_H // BOF("extnum.h")
#define MY_EXTNUM_H

#ifndef MY_FLOAT_H
#define MY_FLOAT_H
#define __STDC_WANT_IEC_60559_TYPES_EXT__
#include <float.h>
#endif

#ifndef MY_STDINT_H
#define MY_STDINT_H
#include  <stdint.h>
#endif

#ifndef MY_EXTDEF_H
#include  "extdef.h"
#endif

#define DEFINE_GBM(S,W,K,M) ((M>>(K-W))<<S)

#define DEFINE_YBM(I)   (1u<<I##_BFS)
#define DEFINE_BBM(I,W) DEFINE_GBM(I##_BFS, W, 0010, 0xffu)
#define DEFINE_HBM(I,W) DEFINE_GBM(I##_BFS, W, 0020, 0xffffu)
#define DEFINE_WBM(I,W) DEFINE_GBM(I##_BFS, W, 0040, 0xffffffffu)
#define DEFINE_DBM(I,W) DEFINE_GBM(I##_BFS, W, 0100, 0xffffffffffffffffu)

#define MY_TGSN(_, F) F(_)

#if _ENTER_EXTNUM_NB
{
#endif
/*  Numeric classification
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

#define NB_ZERO (0x00)              // zero
#define NB_NORM (0x01)              // normal
#define NB_TINY (0x02)              // subnormal
#define NB_HUGE (0x04)              // infinity
#define NB_QNAN (NB_TINY|NB_HUGE)   // NaN
#define NB_SNAN (NB_QNAN|NB_SIGN)   // NaN (signaling)
#define NB_SIGN (0x80)              // signed
#define NB_PINF (NB_HUGE)           // +∞
#define NB_NINF (NB_HUGE|NB_SIGN)   // -∞

#if _LEAVE_EXTNUM_NB
}
#endif

#if _ENTER_EXTNUM_DR
{
#endif
/*  Rounding mode

    Directed rounding types:

    * DR_ZERO
        Towards zero, aka 'trunc'
        -2.1 => -2.0
        -1.9 => -1.0
        +1.9 => +1.0
        +2.1 => +2.0

    * DR_NEXT
        Towards the integer furthest from zero, i.e. to ±∞
        -2.1 => -3.0
        -1.9 => -2.0
        +1.9 => +2.0
        +2.1 => +3.0

    * DR_PINF
        Towards +∞, aka 'ceil'
        -2.1 => -2.0
        -1.9 => -1.0
        +1.9 => +2.0
        +2.1 => +3.0

    * DR_NINF
        Towards -∞, aka 'floor'
        -2.1 => -3.0
        -1.9 => -2.0
        +1.9 => +1.0
        +2.1 => +2.0

    * DR_EVEN
        Towards the closest even integer
        -2.1 => -2.0
        -1.9 => -2.0
        +1.1 => +2.0
        +2.1 => +2.0

    * DR_ODD
        Towards the closest odd integer
        -1.9 => -1.0
        -2.1 => -3.0
        +1.9 => +1.0
        +2.1 => +3.0

    * DR_NEAR
        Towards the nearest integer. May be combined with
        one of the others to control what happens on ties.
        Alone, ties are broken according to the current
        floating point environment.


*/

#define DR_NONE (0)
#define DR_ODD  (0b0001)
#define DR_EVEN (0b0010)
#define DR_NINF (0b0011)
#define DR_PINF (0b0100)
#define DR_NEXT (0b0101)
#define DR_ZERO (0b0110)
#define DR_DONT (0b0111)

#define DR_NEAR (0b1000)

#if _LEAVE_EXTNUM_DR
}
#endif

#if _ENTER_EXTNUM_ATTRS
{
#endif

#define BYTE_(_)    BYTE_##_
#define BYTE_TYPE   union Byte
#define BYTE_UTYPE  unsigned char
#define BYTE_ITYPE  signed char
#define BYTE_U      UCHAR_
#define BYTE_I      SCHAR_
#define BYTE_SN(_)  _##b
#define BYTE_SNU(_) _##bu
#define BYTE_SNI(_) _##bi
#define BYTE_SNC(_) _##bc
#define BYTE_LOG2SZ (0)
#define BYTE_SIZE   SIZE_C(1)
#define BYTE_WIDTH  NDIG_C(8)
#define BYTE_UDIG   NDIG_C(3)   // "255"
#define BYTE_IDIG   NDIG_C(4)   // "-127"
#define BYTE_XDIG   NDIG_C(2)   // "7f"
#define BYTE_ODIG   NDIG_C(3)   // "377"
#define BYTE_IMIN   ((BYTE_TYPE){.I=BYTE_I(MIN)})
#define BYTE_IMAX   ((BYTE_TYPE){.I=BYTE_I(MAX)})
#define BYTE_UMAX   ((BYTE_TYPE){.U=BYTE_U(MAX)})

#define HALF_(_)    HALF_##_
#define HALF_UTYPE  unsigned short
#define HALF_ITYPE  short
#define HALF_FTYPE  flt16_t
#define HALF_TYPE   union Half
#define HALF_LOTYPE union Byte
#define HALF_HITYPE union Byte
#define HALF_U      USHRT_
#define HALF_I      SHRT_
#define HALF_F      FLT16_
#define HALF_LO     BYTE_
#define HALF_HI     BYTE_
#define HALF_SN(_)  _##h
#define HALF_SNU(_) _##hu
#define HALF_SNI(_) _##hi
#define HALF_SNF(_) _##hf
#define HALF_LOG2SZ (1)
#define HALF_SIZE   (WORD_SIZE>>1)
#define HALF_WIDTH  NDIG_C(16)
#define HALF_UDIG   NDIG_C(5)   // "65535"
#define HALF_IDIG   NDIG_C(6)   // "-32768"
#define HALF_XDIG   NDIG_C(4)   // "7fff"
#define HALF_ODIG   NDIG_C(6)   // "177777"
#define HALF_IMIN   ((HALF_TYPE){.I=HALF_I(MIN)})
#define HALF_IMAX   ((HALF_TYPE){.I=HALF_I(MAX)})
#define HALF_UMAX   ((HALF_TYPE){.U=HALF_U(MAX)})
#define HALF_NMIN   ((HALF_TYPE){.U=UINT16_C(0x8400)})
#define HALF_PMIN   ((HALF_TYPE){.U=UINT16_C(0x0400)})
#define HALF_NMAX   ((HALF_TYPE){.U=UINT16_C(0xfbff)})
#define HALF_PMAX   ((HALF_TYPE){.U=UINT16_C(0x7bff)})
#define HALF_NINF   ((HALF_TYPE){.U=UINT16_C(0xfc00)})
#define HALF_PINF   ((HALF_TYPE){.U=UINT16_C(0x7c00)})
#define HALF_QNAN   ((HALF_TYPE){.U=UINT16_C(0x7e00)})

#define WORD_(_)    WORD_ ## _
#define WORD_TYPE   union Word
#define WORD_LOTYPE union Half
#define WORD_HITYPE union Half
#define WORD_UTYPE  unsigned int
#define WORD_ITYPE  int
#define WORD_FTYPE  float
#define WORD_U      UINT_
#define WORD_I      INT_
#define WORD_F      FLT_
#define WORD_LO     HALF_
#define WORD_HI     HALF_
#define WORD_SN(_)  _##w
#define WORD_SNU(_) _##wu
#define WORD_SNI(_) _##wi
#define WORD_SNF(_) _##wf
#define WORD_LOG2SZ (2)
#define WORD_SIZE   SIZE_C(4)
#define WORD_WIDTH  NDIG_C(32)
#define WORD_UDIG   NDIG_C(10)  // "4294967295"
#define WORD_IDIG   NDIG_C(11)  // "-2147483648"
#define WORD_XDIG   NDIG_C(8)   // "7fffffff"
#define WORD_ODIG   NDIG_C(11)  // "37777777777"
#define WORD_IMIN   ((WORD_TYPE){.I=WORD_I(MIN)})
#define WORD_IMAX   ((WORD_TYPE){.I=WORD_I(MAX)})
#define WORD_UMAX   ((WORD_TYPE){.U=WORD_U(MAX)})
#define WORD_NMIN   ((WORD_TYPE){.U=UINT32_C(0x80800000)})
#define WORD_PMIN   ((WORD_TYPE){.U=UINT32_C(0x00800000)})
#define WORD_NMAX   ((WORD_TYPE){.U=UINT32_C(0xff7fffff)})
#define WORD_PMAX   ((WORD_TYPE){.U=UINT32_C(0x7f7fffff)})
#define WORD_NINF   ((WORD_TYPE){.U=UINT32_C(0xff800000)})
#define WORD_PINF   ((WORD_TYPE){.U=UINT32_C(0x7f800000)})
#define WORD_QNAN   ((WORD_TYPE){.U=UINT32_C(0x7fc00000)})

#define DWRD_(_)    DWRD_ ## _
#define DWRD_TYPE   union Dwrd
#define DWRD_LOTYPE union Word
#define DWRD_HITYPE union Word
#define DWRD_FTYPE  double
#define DWRD_LO     WORD_
#define DWRD_HI     WORD_
#define DWRD_F      DBL_
#define DWRD_SN(_)  _##d
#define DWRD_SNU(_) _##du
#define DWRD_SNI(_) _##di
#define DWRD_SNF(_) _##df
#define DWRD_LOG2SZ (3)
#define DWRD_SIZE   (2*WORD_SIZE)
#define DWRD_WIDTH  NDIG_C(64)
#define DWRD_ODIG   NDIG_C(22)  // "1777777777777777777777"
#define DWRD_UDIG   NDIG_C(20)  // "18446744073709551615"
#define DWRD_IDIG   NDIG_C(20)  // "±9223372036854775808"
#define DWRD_XDIG   NDIG_C(16)  // "7fffffffffffffff"
#define DWRD_FDIG   NDIG_C(17)  // "±9.99999999999999"
#define DWRD_EDIG   NDIG_C(21)  // "±9.9999999999999e-200"
#define DWRD_UMAX   ((DWRD_TYPE){.U=DWRD_U(MAX)})
#define DWRD_IMAX   ((DWRD_TYPE){.I=DWRD_I(MAX)})
#define DWRD_IMIN   ((DWRD_TYPE){.I=DWRD_I(MIN)})
#define DWRD_NMIN   ((DWRD_TYPE){.U=UINT64_C(0x8010000000000000)})
#define DWRD_PMIN   ((DWRD_TYPE){.U=UINT64_C(0x0010000000000000)})
#define DWRD_NMAX   ((DWRD_TYPE){.U=UINT64_C(0xffefffffffffffff)})
#define DWRD_PMAX   ((DWRD_TYPE){.U=UINT64_C(0x7fefffffffffffff)})
#define DWRD_NINF   ((DWRD_TYPE){.U=UINT64_C(0xfff0000000000000)})
#define DWRD_PINF   ((DWRD_TYPE){.U=UINT64_C(0x7ff0000000000000)})
#define DWRD_QNAN   ((DWRD_TYPE){.U=UINT64_C(0x7ff8000000000000)})

#define QUAD_(_)    QUAD_##_
#define QUAD_SN(_)  _##q
#define QUAD_SNU(_) _##qu
#define QUAD_SNI(_) _##qi
#define QUAD_SNF(_) _##qf
#define QUAD_TYPE   union Quad
#define QUAD_LOTYPE union Dwrd
#define QUAD_HITYPE union Dwrd
#define QUAD_F      FLT128_
#define QUAD_LO     DWRD_
#define QUAD_HI     DWRD_
#define QUAD_LOG2SZ (4)
#define QUAD_SIZE   (4*WORD_SIZE)
#define QUAD_WIDTH  NDIG_C(128)
// "-170141183460469231731687303715884105728"
// "340282366920938463463374607431768211455"
#define QUAD_IDIG   NDIG_C(40)
#define QUAD_UDIG   NDIG_C(39)
#define QUAD_FDIG   NDIG_C(33)
#define QUAD_IMIN   ((QUAD_TYPE){.I=QUAD_I(MIN)})
#define QUAD_IMAX   ((QUAD_TYPE){.I=QUAD_I(MAX)})
#define QUAD_UMAX   ((QUAD_TYPE){.I=QUAD_U(MAX)})

// Minimum negative normal number representation
#define QUAD_NMIN   \
(                   \
    (QUAD_TYPE)     \
    {               \
        .Lo.U=UINT64_C(0x0000000000000000), \
        .Hi.U=UINT64_C(0x8001000000000000), \
    }               \
)
// Minimum positive normal number representation
#define QUAD_PMIN   \
(                   \
    (QUAD_TYPE)     \
    {               \
        .Lo.U=UINT64_C(0x0000000000000000),   \
        .Hi.U=UINT64_C(0x0001000000000000),   \
    }               \
)


// Maximum negative normal number representation
#define QUAD_NMAX   \
(                   \
    (QUAD_TYPE)     \
    {               \
        .Lo.U=UINT64_C(0xffffffffffffffff),   \
        .Hi.U=UINT64_C(0xfffeffffffffffff),   \
    }               \
)

// Maximum positive normal number representation
#define QUAD_PMAX   \
(                   \
    (QUAD_TYPE)     \
    {               \
        .Lo.U=UINT64_C(0xffffffffffffffff),   \
        .Hi.U=UINT64_C(0x7ffeffffffffffff),   \
    }               \
)

// -∞ representation
#define QUAD_NINF   \
(                   \
    (QUAD_TYPE)     \
    {               \
        .Lo.U=UINT64_C(0x0000000000000000),   \
        .Hi.U=UINT64_C(0xffff000000000000)    \
    }               \
)

// +∞ representation
#define QUAD_PINF   \
(                   \
    (QUAD_TYPE)     \
    {               \
        .Lo.U=UINT64_C(0x0000000000000000),   \
        .Hi.U=UINT64_C(0x7fff000000000000),   \
    }               \
)
// default quiet NaN representation
#define QUAD_QNAN   \
(                   \
    (QUAD_TYPE)     \
    {               \
        .Lo.U=UINT64_C(0x0000000000000000), \
        .Hi.U=UINT64_C(0x7fff800000000000), \
    }               \
)

#define OCTA_(_)    OCTA_##_
#define OCTA_SN(_)  _##o
#define OCTA_LOG2SZ (5)
#define OCTA_SIZE   (8*WORD_SIZE)
#define OCTA_WIDTH  (BYTE_WIDTH<<OCTA_LOG2SZ)

#define OCTA_NLONG  (DWRD_NLONG<<2)
#define OCTA_SN(_)  _##o

#define SEXD_(_)    SEXD_##_
#define SEXD_SN(_)  _##s
#define SEXD_LOG2SZ (6)
#define SEXD_SIZE   (16*WORD_SIZE)
#define SEXD_WIDTH  (BYTE_WIDTH<<SEXD_LOG2SZ)

#define DWRD_NLONG  (1+(LONG_MAX==INT_MAX))
#define QUAD_NLONG  (2*DWRD_NLONG)
#define QUAD_NLLONG (1+(LONG_MAX==LLONG_MAX))

#if QUAD_NLONG == 4
#   define  ULONG_SN(_)     _##lu
#   define  LONG_SN(_)      _##li
#   define  ULLONG_SN       DWRD_SNU
#   define  LLONG_SN        DWRD_SNI
#   define  ULONG_STG       WORD_
#   define  LONG_STG        WORD_
#   define  ULLONG_STG      DWRD_
#   define  LLONG_STG       DWRD_
#   define  WORD_LU         ULONG_
#   define  WORD_LI         LONG_
#   define  WORD_LTYPE      union Wl
#   define  WORD_LUTYPE     unsigned long
#   define  WORD_LITYPE     long
#   define  DWRD_U          ULLONG_
#   define  DWRD_I          LLONG_
#   define  DWRD_UTYPE      unsigned long long
#   define  DWRD_ITYPE      long long
#elif QUAD_NLLONG == 2
#   define  ULONG_SN        DWRD_SNU
#   define  LONG_SN         DWRD_SNI
#   define  ULLONG_SN(_)    _##lu
#   define  LLONG_SN(_)     _##li
#   define  ULONG_STG       DWRD_
#   define  LONG_STG        DWRD_
#   define  ULLONG_STG      DWRD_
#   define  LLONG_STG       DWRD_
#   define  DWRD_I          LONG_
#   define  DWRD_LI         LLONG_
#   define  DWRD_U          ULONG_
#   define  DWRD_LU         ULLONG_
#   define  DWRD_ITYPE      long
#   define  DWRD_LITYPE     long long
#   define  DWRD_UTYPE      unsigned long
#   define  DWRD_LUTYPE     unsigned long long
#   define  DWRD_LTYPE      union Dl
#else
#   define  ULONG_SN        DWRD_SNU
#   define  LONG_SN         DWRD_SNI
#   define  ULLONG_SN       QUAD_SNU
#   define  LLONG_SN        QUAD_SNI
#   define  LONG_STG        DWRD_
#   define  ULONG_STG       DWRD_
#   define  LLONG_STG       QUAD_
#   define  ULLONG_STG      QUAD_
#   define  DWRD_I          LONG_
#   define  DWRD_U          ULONG_
#   define  DWRD_ITYPE      long
#   define  DWRD_UTYPE      unsigned long
#   define  QUAD_I          LLONG_
#   define  QUAD_U          ULLONG_
#   define  QUAD_ITYPE      long long
#   define  QUAD_UTYPE      unsigned long long
#endif

#if defined(__SIZEOF_INT128__) && (QUAD_NLLONG==2)
#   define  UINT128X_(_)    UINT128X_##_
#   define  UINT128X_TYPE   unsigned __int128
#   define  UINT128X_STG    QUAD_
#   define  UINT128X_SN     QUAD_SNU
#   define  INT128X_(_)     INT128X_##_
#   define  INT128X_TYPE    __int128
#   define  INT128X_STG     QUAD_
#   define  INT128X_SN      QUAD_SNI
#   define  QUAD_I          INT128X_
#   define  QUAD_U          UINT128X_
#   define  QUAD_ITYPE      __int128
#   define  QUAD_UTYPE      unsigned __int128
#endif

#define BOOL_ENDIAN         MY_ENDIAN
#define UCHAR_ENDIAN        MY_ENDIAN
#define SCHAR_ENDIAN        MY_ENDIAN
#define USHRT_ENDIAN        MY_ENDIAN
#define SHRT_ENDIAN         MY_ENDIAN
#define UINT_ENDIAN         MY_ENDIAN
#define INT_ENDIAN          MY_ENDIAN
#define ULONG_ENDIAN        MY_ENDIAN
#define LONG_ENDIAN         MY_ENDIAN
#define ULLONG_ENDIAN       MY_ENDIAN
#define LLONG_ENDIAN        MY_ENDIAN

#ifndef FLT16_ENDIAN
#define FLT16_ENDIAN        MY_ENDIAN
#endif

#ifndef FLT_ENDIAN
#define FLT_ENDIAN          MY_ENDIAN
#endif

#ifndef DBL_ENDIAN
#define DBL_ENDIAN          MY_ENDIAN
#endif


#define BOOL_(_)            BOOL_##_
#define BOOL_SN(_)          _##yu
#define BOOL_SIGNEDNESS     (0)
#define BOOL_TYPE           _Bool
#define BOOL_WIDTH          NDIG_C(1)

#define CHAR_(_)            CHAR_##_
#define CHAR_SN             BYTE_SNC
#define CHAR_TYPE           char
#define CHAR_STG            BYTE_
#define CHAR_SIZE           CHAR_STG(SIZE)
#define CHAR_WIDTH          CHAR_STG(WIDTH)
#define CHAR_SIGNEDNESS     (0!=CHAR_MIN)
#define CHAR_C(C)           #C

#define UCHAR_(_)           UCHAR_ ## _
#define UCHAR_STG           BYTE_
#define UCHAR_SN            UCHAR_STG(SNC)
#define UCHAR_SIZE          UCHAR_STG(SIZE)
#define UCHAR_WIDTH         UCHAR_STG(WIDTH)
#define UCHAR_DIG           UCHAR_STG(UDIG)
#define UCHAR_ODIG          UCHAR_STG(ODIG)
#define UCHAR_XDIG          UCHAR_STG(XDIG)
#define UCHAR_SIGNEDNESS    (0)
#define UCHAR_OFMT          "hho"
#define UCHAR_DFMT          "hhu"
#define UCHAR_XFMT          "hhx"
#define UCHAR_UFMT          "hhX"

#if defined(_MSC_VER)
#   define  UCHAR_C(C)      C ## ui8
#else
#   define  UCHAR_C(C)      (C&255)
#endif

#define SCHAR_(_)           SCHAR_##_
#define SCHAR_SN            _##bi
#define SCHAR_STG           BYTE_
#define SCHAR_SIZE          SCHAR_STG(SIZE)
#define SCHAR_WIDTH         SCHAR_STG(WIDTH)
#define SCHAR_DIG           SCHAR_STG(IDIG)
#define SCHAR_SIGNEDNESS    (1)
#define SCHAR_DFMT          "hhi"
#define SCHAR_C(C)          (C&255)

#if defined(_MSC_VER)
#   ifdef   _CHAR_UNSIGNED
#   define  UCHAR_TYPE      char
#   define  SCHAR_TYPE      signed char
#   endif

#   ifndef  _CHAR_UNSIGNED
#   define  UCHAR_TYPE      unsigned char
#   define  SCHAR_TYPE      char
#   endif

#else
#   define  CHAR_TYPE       char
#   define  UCHAR_TYPE      unsigned char
#   define  SCHAR_TYPE      signed char
#endif

#define USHRT_(_)           USHRT_##_
#define USHRT_TYPE          unsigned short
#define USHRT_STG           HALF_
#define USHRT_SN            HALF_SNU
#define USHRT_SIZE          USHRT_STG(SIZE)
#define USHRT_WIDTH         USHRT_STG(WIDTH)
#define USHRT_DIG           USHRT_STG(UDIG)
#define USHRT_ODIG          USHRT_STG(ODIG)
#define USHRT_XDIG          USHRT_STG(XDIG)
#define USHRT_SIGNEDNESS    (0)
#define USHRT_OFMT          "ho"
#define USHRT_DFMT          "hu"
#define USHRT_XFMT          "hx"
#define USHRT_UFMT          "hX"
#define USHRT_C(C)          (C&65535)

#define SHRT_(_)            SHRT_##_
#define SHRT_TYPE           short
#define SHRT_STG            HALF_
#define SHRT_SN             HALF_SNI
#define SHRT_SIZE           SHRT_STG(SIZE)
#define SHRT_WIDTH          SHRT_STG(WIDTH)
#define SHRT_DIG            SHRT_STG(IDIG)
#define SHRT_SIGNEDNESS     (1)
#define SHRT_TGNAME(_)      _ ## hi
#define SHRT_DFMT           "hi"
#define SHRT_C(C)           (C&65535)

#define UINT_(_)            UINT_##_
#define UINT_TYPE           unsigned int
#define UINT_SN             WORD_SNU
#define UINT_STG            WORD_
#define UINT_SIZE           UINT_STG(SIZE)
#define UINT_WIDTH          UINT_STG(WIDTH)
#define UINT_DIG            UINT_STG(UDIG)
#define UINT_ODIG           UINT_STG(ODIG)
#define UINT_XDIG           UINT_STG(XDIG)
#define UINT_SIGNEDNESS     (0)
#define UINT_C(C)           (C##U)
#define UINT_OFMT           "o"
#define UINT_DFMT           "u"
#define UINT_XFMT           "x"
#define UINT_UFMT           "X"

#define INT_(_)             INT_##_
#define INT_SN              WORD_SNI
#define INT_TYPE            int
#define INT_STG             WORD_
#define INT_SIZE            INT_STG(SIZE)
#define INT_WIDTH           INT_STG(WIDTH)
#define INT_DIG             INT_STG(IDIG)
#define INT_SIGNEDNESS      (1)
#define INT_DFMT            "i"
#define INT_C(C)            (C)

#define ULONG_(_)           ULONG_##_
#define ULONG_TYPE          unsigned long
#define ULONG_SIZE          ULONG_STG(SIZE)
#define ULONG_WIDTH         ULONG_STG(WIDTH)
#define ULONG_DIG           ULONG_STG(UDIG)
#define ULONG_ODIG          ULONG_STG(ODIG)
#define ULONG_XDIG          ULONG_STG(XDIG)
#define ULONG_SIGNEDNESS    (0)
#define ULONG_OFMT          "lo"
#define ULONG_DFMT          "lu"
#define ULONG_XFMT          "lx"
#define ULONG_UFMT          "lX"
#define ULONG_C(C)          (C##UL)

#define LONG_(_)            LONG_##_
#define LONG_TYPE           long
#define LONG_SIZE           LONG_STG(SIZE)
#define LONG_WIDTH          LONG_STG(WIDTH)
#define LONG_DIG            LONG_STG(IDIG)
#define LONG_SIGNEDNESS     (1)
#define LONG_DFMT           "li"
#define LONG_C(C)           (C##L)

#define ULLONG_(_)          ULLONG_##_
#define ULLONG_TYPE         unsigned long long
#define ULLONG_SIZE         ULLONG_STG(SIZE)
#define ULLONG_WIDTH        ULLONG_STG(WIDTH)
#define ULLONG_DIG          ULLONG_STG(UDIG)
#define ULLONG_ODIG         ULLONG_STG(ODIG)
#define ULLONG_XDIG         ULLONG_STG(XDIG)
#define ULLONG_OFMT         "llo"
#define ULLONG_DFMT         "llu"
#define ULLONG_XFMT         "llx"
#define ULLONG_UFMT         "llX"
#define ULLONG_SIGNEDNESS   (0)
#define ULLONG_C(C)         (C##ULL)

#define LLONG_(_)           LLONG_##_
#define LLONG_TYPE          long long
#define LLONG_SIZE          LLONG_STG(SIZE)
#define LLONG_WIDTH         LLONG_STG(WIDTH)
#define LLONG_DIG           LLONG_STG(IDIG)
#define LLONG_SIGNEDNESS    (1)
#define LLONG_DFMT          "lli"
#define LLONG_C(C)          (C##LL)

#define UINT8_(_)           UINT8_##_
#define UINT8_TYPE          uint8_t
#define UINT8_SN            BYTE_SNU
#define UINT8_STG           BYTE_
#define UINT8_BASE          UINT8_STG(U)
#define UINT8_SIZE          UINT8_BASE(SIZE)
#define UINT8_WIDTH         UINT8_BASE(WIDTH)
#define UINT8_DIG           UINT8_BASE(DIG)
#define UINT8_ODIG          UINT8_BASE(ODIG)
#define UINT8_XDIG          UINT8_BASE(XDIG)
#define UINT8_SIGNEDNESS    UINT8_BASE(SIGNEDNESS)
#define UINT8_DFMT          UINT8_BASE(DFMT)
#define UINT8_OFMT          UINT8_BASE(OFMT)
#define UINT8_XFMT          UINT8_BASE(XFMT)
#define UINT8_UFMT          UINT8_BASE(UFMT)
#define UINT8_ENDIAN        UINT8_BASE(ENDIAN)

#define INT8_(_)            INT8_##_
#define INT8_SN             BYTE_SNI
#define INT8_TYPE           int8_t
#define INT8_STG            BYTE_
#define INT8_BASE           INT8_STG(I)
#define INT8_SIZE           INT8_BASE(SIZE)
#define INT8_WIDTH          INT8_BASE(WIDTH)
#define INT8_DIG            INT8_BASE(DIG)
#define INT8_ODIG           INT8_BASE(ODIG)
#define INT8_XDIG           INT8_BASE(XDIG)
#define INT8_SIGNEDNESS     INT8_BASE(SIGNEDNESS)
#define INT8_DFMT           INT8_BASE(DFMT)
#define INT8_ENDIAN         INT8_BASE(ENDIAN)

#define UINT16_(_)          UINT16_##_
#define UINT16_SN           HALF_SNU
#define UINT16_TYPE         uint16_t
#define UINT16_STG          HALF_
#define UINT16_BASE         UINT16_STG(U)
#define UINT16_DFMT         UINT16_BASE(DFMT)
#define UINT16_OFMT         UINT16_BASE(OFMT)
#define UINT16_XFMT         UINT16_BASE(XFMT)
#define UINT16_UFMT         UINT16_BASE(UFMT)
#define UINT16_SIZE         UINT16_BASE(SIZE)
#define UINT16_WIDTH        UINT16_BASE(WIDTH)
#define UINT16_DIG          UINT16_BASE(DIG)
#define UINT16_ODIG         UINT16_BASE(ODIG)
#define UINT16_XDIG         UINT16_BASE(XDIG)
#define UINT16_SIGNEDNESS   UINT16_BASE(SIGNEDNESS)
#define UINT16_ENDIAN       UINT16_BASE(ENDIAN)

#define INT16_(_)           INT16_##_
#define INT16_SN            HALF_SNI
#define INT16_TYPE          int16_t
#define INT16_STG           HALF_
#define INT16_BASE          INT16_STG(I)
#define INT16_SIZE          INT16_BASE(SIZE)
#define INT16_WIDTH         INT16_BASE(WIDTH)
#define INT16_DIG           INT16_BASE(DIG)
#define INT16_ODIG          INT16_BASE(ODIG)
#define INT16_XDIG          INT16_BASE(XDIG)
#define INT16_SIGNEDNESS    INT16_BASE(SIGNEDNESS)
#define INT16_UFMT          INT16_BASE(DFMT)
#define INT16_ENDIAN        INT16_BASE(ENDIAN)

#define UINT32_(_)          UINT32_##_
#define UINT32_SN           WORD_SNU
#define UINT32_TYPE         uint32_t
#define UINT32_STG          WORD_
#define UINT32_BASE         UINT32_STG(U)
#define UINT32_DFMT         UINT32_BASE(DFMT)
#define UINT32_OFMT         UINT32_BASE(OFMT)
#define UINT32_XFMT         UINT32_BASE(XFMT)
#define UINT32_UFMT         UINT32_BASE(UFMT)
#define UINT32_SIZE         UINT32_BASE(SIZE)
#define UINT32_WIDTH        UINT32_BASE(WIDTH)
#define UINT32_DIG          UINT32_BASE(DIG)
#define UINT32_ODIG         UINT32_BASE(ODIG)
#define UINT32_XDIG         UINT32_BASE(XDIG)
#define UINT32_SIGNEDNESS   UINT32_BASE(SIGNEDNESS)
#define UINT32_ENDIAN       UINT_BASE(ENDIAN)

#define INT32_(_)           INT32_##_
#define INT32_SN            WORD_SNI
#define INT32_TYPE          int32_t
#define INT32_STG           WORD_
#define INT32_BASE          INT32_STG(I)
#define INT32_SIZE          INT32_BASE(SIZE)
#define INT32_WIDTH         INT32_BASE(WIDTH)
#define INT32_DIG           INT32_BASE(DIG)
#define INT32_ODIG          INT32_BASE(ODIG)
#define INT32_XDIG          INT32_BASE(XDIG)
#define INT32_SIGNEDNESS    INT32_BASE(SIGNEDNESS)
#define INT32_DFMT          INT32_BASE(DFMT)
#define INT32_ENDIAN        INT32_BASE(ENDIAN)

#define UINT64_(_)          UINT64_##_
#define UINT64_SN           DWRD_SNU
#define UINT64_TYPE         uint64_t
#define UINT64_STG          DWRD_
#define UINT64_BASE         UINT64_STG(U)
#define UINT64_DFMT         UINT64_BASE(DFMT)
#define UINT64_OFMT         UINT64_BASE(OFMT)
#define UINT64_XFMT         UINT64_BASE(XFMT)
#define UINT64_UFMT         UINT64_BASE(UFMT)
#define UINT64_SIZE         UINT64_BASE(SIZE)
#define UINT64_WIDTH        UINT64_BASE(WIDTH)
#define UINT64_DIG          UINT64_BASE(DIG)
#define UINT64_ODIG         UINT64_BASE(ODIG)
#define UINT64_XDIG         UINT64_BASE(XDIG)
#define UINT64_SIGNEDNESS   UINT64_BASE(SIGNEDNESS)
#define UINT64_ENDIAN       UINT64_BASE(ENDIAN)

#define INT64_(_)           INT64_##_
#define INT64_SN            DWRD_SNI
#define INT64_TYPE          int64_t
#define INT64_STG           DWRD_
#define INT64_BASE          INT64_STG(I)
#define INT64_SIZE          INT64_BASE(SIZE)
#define INT64_WIDTH         INT64_BASE(WIDTH)
#define INT64_DIG           INT64_BASE(DIG)
#define INT64_ODIG          INT64_BASE(ODIG)
#define INT64_XDIG          INT64_BASE(XDIG)
#define INT64_SIGNEDNESS    INT64_BASE(SIGNEDNESS)
#define INT64_DFMT          INT64_BASE(DFMT)
#define INT64_ENDIAN        INT64_BASE(ENDIAN)

#ifndef SIZE_MAX
#error "SIZE_MAX is gone"
#elif  (SIZE_MAX>>15) == 1
#   define  ADDR_STG    HALF_
#   define  QUAD_NPTR   8
#   define  DWRD_NPTR   4
#   define  WORD_NPTR   2
#   define  HALF_NPTR   1
#elif (SIZE_MAX>>31) == 1
#   define  ADDR_STG    WORD_
#   define  QUAD_NPTR   4
#   define  DWRD_NPTR   2
#   define  WORD_NPTR   1
#   define  HALF_NPTR   0
#elif (SIZE_MAX>>63) == 1
#   define  ADDR_STG    DWRD_
#   define  QUAD_NPTR   2
#   define  DWRD_NPTR   1
#   define  WORD_NPTR   0
#   define  HALF_NPTR   0
#elif (SIZE_MAX>>64) == LONG_MAX
#   define  ADDR_STG    QUAD_
#   define  QUAD_NPTR   1
#   define  DWRD_NPTR   0
#   define  WORD_NPTR   0
#   define  HALF_NPTR   0
#else
#   error "invalid value of SIZE_MAX"
#endif

#define ADDR_SN(_)          _##a
#define ADDR_SNU(_)         ADDR_STG(SNU)
#define ADDR_SNI(_)         ADDR_STG(SNI)
#define ADDR_I              ADDR_STG(I)
#define ADDR_U              ADDR_STG(U)
#define ADDR_SIZE           ADDR_STG(SIZE)
#define ADDR_WIDTH          ADDR_STG(WIDTH)
#define ADDR_DEC            ADDR_STG(WIDTH)
#define ADDR_UDIG           ADDR_STG(UDIG)
#define ADDR_IDIG           ADDR_STG(IDIG)
#define ADDR_XDIG           ADDR_STG(XDIG)
#define ADDR_ODIG           ADDR_STG(ODIG)

#define ADDR_FMTP           "p"

#define UINTPTR_(_)         UINTPTR_##_
#define UINTPTR_TYPE        uintptr_t
#define UINTPTR_BASE        ADDR_U
#define UINTPTR_STG         ADDR_STG
#define UINTPTR_SIZE        ADDR_SIZE
#define UINTPTR_WIDTH       ADDR_WIDTH
#define UINTPTR_DIG         ADDR_UDIG
#define UINTPTR_XDIG        ADDR_XDIG
#define UINTPTR_ODIG        ADDR_STG(ODIG)
#define UINTPTR_SIGNEDNESS  (0)
#define UINTPTR_SN          ADDR_SNU
#ifndef UINTPTR_C
#define UINTPTR_C           ADDR_U(C)
#endif

#define INTPTR_(_)          INTPTR_##_
#define INTPTR_BASE         ADDR_I
#define INTPTR_TYPE         intptr_t
#define INTPTR_STG          ADDR_STG
#define INTPTR_SIZE         ADDR_SIZE
#define INTPTR_WIDTH        ADDR_WIDTH
#define INTPTR_DIG          ADDR_DIG
#define INTPTR_SIGNEDNESS   (1)
#define INTPTR_SN(_)        ADDR_SNI
#ifndef INTPTR_C
#define INTPTR_C            ADDR_I(C)
#endif

#define SIZE_(_)            SIZE_##_
#define SIZE_BASE           ADDR_U
#define SIZE_TYPE           size_t
#define SIZE_STG            ADDR_STG
#define SIZE_SIZE           ADDR_SIZE
#define SIZE_WIDTH          ADDR_WIDTH
#define SIZE_DIG            ADDR_DIG
#define SIZE_XDIG           ADDR_XDIG
#define SIZE_ODIG           ADDR_ODIG
#define SIZE_FMTO           "zo"
#define SIZE_FMTD           "zd"
#define SIZE_FMTX           "zx"
#define SIZE_SIGNEDNESS     (0)
#define SIZE_SN             ADDR_SNU
#ifndef SIZE_C
#define SIZE_C              ADDR_U(C)
#endif

#define PTRDIFF(_)          PTRDIFF_##_
#define PTRDIFF_BASE        ADDR_I
#define PTRDIFF_TYPE        ptrdiff_t
#define PTRDIFF_STG         ADDR_STG
#define PTRDIFF_SIZE        ADDR_SIZE
#define PTRDIFF_WIDTH       ADDR_WIDTH
#define PTRDIFF_DIG         ADDR_DIG
#define PTRDIFF_SIGNEDNESS  (1)
#define PTRDIFF_SN          ADDR_SNI
#define PTRDIFF_FMTO        "to"
#define PTRDIFF_FMTD        "ti"
#define PTRDIFF_FMTX        "tx"
#define PTRDIFF_FMTU        "tX"
#ifndef PTRDIFF_C
#define PTRDIFF_C           ADDR_I(C)
#endif

#define FLT16_(_)           FLT16_##_
#define FLT16_TYPE          flt16_t
#define FLT16_STG           HALF_
#define FLT16_SN(_)         FLT16_STG(SNF)
#define FLT16_SIZE          FLT16_STG(SIZE)
#define FLT16_WIDTH         FLT16_STG(WIDTH)
#define FLT16_SIGNEDNESS    (1)

#if defined(SPC_X86_AVX512FP16)
#   define  FLT16_MTYPE _Float16
#   define  FLT16_C_DEF _Float16: C
#endif

#if defined(SPC_ARM_FP16_ARGS)
#   define  FLT16_MTYPE __fp16
#   define  FLT16_C(C)  ((__fp16) C##f16)
#endif

#if defined(FLT16_MTYPE)
#   ifndef  FLT16_C
#   define  FLT16_C(C)  C##f16
#   endif
#endif

#define FLT_(_)         FLT_##_
#define FLT_SN          FLT_STG(SNF)
#define FLT_TYPE        float
#define FLT_STG         WORD_
#define FLT_SIZE        FLT_STG(SIZE)
#define FLT_WIDTH       FLT_STG(WIDTH)
#define FLT_SIGNEDNESS  (1)
#define FLT_C(C)        C##f

#define DBL_(_)         DBL_##_
#define DBL_SN          DWRD_SNF
#define DBL_TYPE        double
#define DBL_STG         DWRD_
#define DBL_SIZE        DBL_STG(SIZE)
#define DBL_WIDTH       DBL_STG(WIDTH)
#define DBL_SIGNEDNESS  (1)
#define DBL_C(C)        _Generic(C, double:C)

#if _LEAVE_EXTNUM_ATTRS
}
#endif

#if _ENTER_EXTNUM_NV
{
#endif

#define MY_BIG_PAIR(Lo, Hi, Z)  Hi Z, Lo Z
#define MY_LIL_PAIR(Lo, Hi, Z)  Lo Z, Hi Z

#define MY_LV1(M, N) M##0 N
#define MY_LV2(M, N) MY_LV1(M,N),M##1 N
#define MY_LV3(M, N) MY_LV2(M,N),M##2 N
#define MY_LV4(M, N) MY_LV3(M,N),M##3 N
#define MY_LV5(M, N) MY_LV4(M,N),M##4 N
#define MY_LV6(M, N) MY_LV5(M,N),M##5 N
#define MY_LV7(M, N) MY_LV6(M,N),M##6 N
#define MY_LV8(M, N) MY_LV7(M,N),M##7 N

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
#define MY_BV3(M, N)  M##2 N,MY_BV2(M,N)
#define MY_BV4(M, N)  M##3 N,MY_BV3(M,N)
#define MY_BV5(M, N)  M##4 N,MY_BV4(M,N)
#define MY_BV6(M, N)  M##5 N,MY_BV5(M,N)
#define MY_BV7(M, N)  M##6 N,MY_BV6(M,N)
#define MY_BV8(M, N)  M##7 N,MY_BV7(M,N)

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

#define MY_BV128(M, N) \
M##127 N,M##126 N,M##125 N,M##124 N,M##123 N,M##122 N,M##121 N,M##120 N,\
M##119 N,M##118 N,M##117 N,M##116 N,M##115 N,M##114 N,M##113 N,M##112 N,\
M##111 N,M##110 N,M##109 N,M##108 N,M##107 N,M##106 N,M##105 N,M##104 N,\
M##103 N,M##102 N,M##101 N,M##100 N,M## 99 N,M## 98 N,M## 97 N,M## 96 N,\
M## 95 N,M## 94 N,M## 93 N,M## 92 N,M## 91 N,M## 90 N,M## 89 N,M## 88 N,\
M## 87 N,M## 86 N,M## 85 N,M## 84 N,M## 83 N,M## 82 N,M## 81 N,M## 80 N,\
M## 79 N,M## 78 N,M## 77 N,M## 76 N,M## 75 N,M## 74 N,M## 73 N,M## 72 N,\
M## 71 N,M## 70 N,M## 69 N,M## 68 N,M## 67 N,M## 66 N,M## 65 N,M## 64 N,\
MY_BV64(M,N)

#if MY_ENDIAN == ENDIAN_LIL
#   ifndef  MY_PAIR
#   define  MY_PAIR     MY_LIL_PAIR
#   endif

#   ifndef  MY_NVX
#   define  MY_NVX(N)   MY_LV##N
#   endif

#endif

#if MY_ENDIAN == ENDIAN_BIG
#   ifndef  MY_PAIR
#   define  MY_PAIR     MY_BIG_PAIR
#   endif

#   ifndef  MY_NVX
#   define  MY_NVX(N)   MY_BV##N
#   endif

#endif

#define MY_NV1      MY_NVX(1)
#define MY_NV2      MY_NVX(2)
#define MY_NV3      MY_NVX(3)
#define MY_NV4      MY_NVX(4)
#define MY_NV5      MY_NVX(5)
#define MY_NV6      MY_NVX(6)
#define MY_NV7      MY_NVX(7)
#define MY_NV8      MY_NVX(8)
#define MY_NV16     MY_NVX(16)
#define MY_NV32     MY_NVX(32)
#define MY_NV64     MY_NVX(64)
#define MY_NV128    MY_NVX(128)


#define MY_BZ {uint8_t  U; int8_t   I;}
#define MY_HZ {uint16_t U; int16_t  I;}
#define MY_WZ {uint32_t U; int32_t  I;}
#define MY_DZ {uint64_t U; int64_t  I;}

#if _LEAVE_EXTNUM_NV
}
#endif

#if _ENTER_EXTNUM_XFLT
{
#endif

#if FLT16_ENDIAN == ENDIAN_LIL
struct Xhfl {
    union {
        struct {uint8_t Mant;};
        union MY_BZ;
    };
};
struct Xhfr {
    union {
        struct {uint8_t  Mant: 2, Expo: 5, Sign:1, :0;};
        union MY_BZ;
    };
};
typedef struct Xhf {
    union {
        struct {struct Xhfl Lo; struct Xhfr Hi;};
        struct {uint16_t Mant: 10, Expo: 5, Sign: 1, :0;};
        union MY_HZ;
    };
} Xhf;
#else
#error "berg endian flt16"
#endif

#if FLT_ENDIAN == ENDIAN_LIL
struct Xwfl {
    union {
        struct {uint16_t Mant;};
        union MY_HZ;
    };
};
struct Xwfr {
    union {
        struct {uint16_t Mant: 7, Expo: 8, Sign:1, :0;};
        union MY_HZ;
    };
};
typedef struct Xwf {
    union {
        struct {struct Xwfl Lo; struct Xwfr Hi;};
        struct {uint32_t Mant:23, Expo: 8, Sign:1, :0;};
        union MY_WZ;
    };
} Xwf;
#else
#error "berg endian flt32"
#endif

#if DBL_ENDIAN == ENDIAN_LIL
struct Xdfl {
    union {
        struct {uint32_t Mant;};
        union MY_WZ;
    };
};
struct Xdfr {
    union {
        struct {uint32_t Mant:20,Expo:11, Sign: 1, :0;};
        union MY_WZ;
    };
};
typedef struct Xdf {
    union {
        struct {struct Xdfl Lo; struct Xdfr Hi;};
        struct {uint64_t Mant:52, Expo:11, Sign:1, :0;};
        union MY_DZ;
    };
} Xdf;
#else
#error "berg endian flt64"
#endif

struct Xqfl {
    union {
        struct {uint64_t Mant;};
        union MY_DZ;
    };
};
struct Xqfr {
    union {
        struct {uint64_t Mant:48, Expo:15, Sign:1, :0;};
        union MY_DZ;
    };
};
typedef struct Xqf {
    union {
        struct {struct Xqfl Lo; struct Xqfr Hi;};
    };
} Xqf;

#if defined(FLT16_MTYPE)
typedef FLT16_MTYPE flt16_t;
#else
typedef struct Xhf flt16_t;
#endif

typedef float  flt32_t;
typedef double flt64_t;

#if _LEAVE_XFLT
}
#endif

#if _ENTER_EXTNUM_HOMOGENOUS_AGGREGATES
{
#endif
/*
    Most (all?) call specs have special procedures for
    passing and returning small aggregate objects by value
    when all of its elements are of the same type. In all
    arm calling conventions, homogeneous aggregates with 1
    to 4 elements are recognized for all fundamental types,
    including the 64 and 128 bit vectors. There are too
    many different x86 calling conventions to list here but
    like with arm, one can expect homogeneous aggregates of
    1 to 4 elements for all fundamental types including the
    128, 256, and 512 bit vectors.

    IMPORTANT NOTE:
    Microsoft's default x86-64 calling convention does NOT
    have a concept of homogeneous aggregates. If a struct
    is 1, 2, 4, or 8 bytes it's passed in one of the
    general purpose registers. Otherwise, it's passed by
    reference or on the stack. Our operations always use
    the `__vectorcall` calling convention if it's available
    when Windows is targeted. This is accomplished with the
    PUBLIC function specifier so remember to use it or its
    complement STATIC, as in:

        // Convert 128 bit vector of 8 uint16_t to 64 bit
        // vector of 8 int8_t using signed saturation
        // PUBLIC expands to an implementation defined set
        // of symbols that modifies the function's calling
        // convention to the one we require and ensures it
        // has external linkage.

        #define QHU_CVS2(a) \
        _mm_cvtsd_f64(\
            _mm_castsi128_pd(\
                _mm_packs_epi16(\
                    _mm_packs_epi32(\
                        _mm_cvtepu16_epi32(a),\
                        _mm_cvtepu16_epi32(_mm_bsrli_si128((a), 8))\
                    )\
                )\
            )\
        )
        }
        #define VQHU_CVS2(x) _Generic((x), Vqhu: QHU_CVS2((x).V0))
        #define cvs2qhu     VQHU_CVS2

        #undef       cvs2qhu
        PUBLIC  Vdbi cvs2qhu(Vqhu x) {return VQHU_CVSW(x);}
typedef struct Yu2  {Yu MY_NV2(I, );}   Yu2;
typedef struct Yu3  {Yu MY_NV3(I, );}   Yu3;
typedef struct Yu4  {Yu MY_NV4(I, );}   Yu4;
typedef struct Yu8  {Yu MY_NV8(I, );}   Yu8;
typedef struct Yu16 {Yu MY_NV16(I,);}   Yu16;
typedef struct Yu32 {Yu MY_NV32(I,);}   Yu32;
typedef struct Yu64 {Yu MY_NV64(I,);}   Yu64;
*/
typedef _Bool       Yu;
typedef struct Yu8  {Yu MY_NV8(I,:1);}   Yu8;

typedef char        Bc;
typedef struct Bc1  {Bc MY_NV1(I, );}   Bc1;
typedef struct Bc2  {Bc MY_NV2(I, );}   Bc2;
typedef struct Bc3  {Bc MY_NV3(I, );}   Bc3;
typedef struct Bc4  {Bc MY_NV4(I, );}   Bc4;
typedef struct Bc8  {Bc MY_NV8(I, );}   Bc8;
typedef struct Bc16 {Bc MY_NV16(I,);}   Bc16;
typedef struct Bc32 {Bc MY_NV32(I,);}   Bc32;
typedef struct Bc64 {Bc MY_NV64(I,);}   Bc64;

typedef BYTE_UTYPE  Bu;
typedef struct Bu1  {Bu MY_NV1(U, );}   Bu1;
typedef struct Bu2  {Bu MY_NV2(U, );}   Bu2;
typedef struct Bu3  {Bu MY_NV3(U, );}   Bu3;
typedef struct Bu4  {Bu MY_NV4(U, );}   Bu4;
typedef struct Bu8  {Bu MY_NV8(U, );}   Bu8;
typedef struct Bu16 {Bu MY_NV16(U,);}   Bu16;
typedef struct Bu32 {Bu MY_NV32(U,);}   Bu32;
typedef struct Bu64 {Bu MY_NV64(U,);}   Bu64;

typedef BYTE_ITYPE  Bi;
typedef struct Bi1  {Bi MY_NV1(I, );}   Bi1;
typedef struct Bi2  {Bi MY_NV2(I, );}   Bi2;
typedef struct Bi3  {Bi MY_NV3(I, );}   Bi3;
typedef struct Bi4  {Bi MY_NV4(I, );}   Bi4;
typedef struct Bi8  {Bi MY_NV8(I, );}   Bi8;
typedef struct Bi16 {Bi MY_NV16(I,);}   Bi16;
typedef struct Bi32 {Bi MY_NV32(I,);}   Bi32;
typedef struct Bi64 {Bi MY_NV64(I,);}   Bi64;

typedef HALF_UTYPE  Hu;
typedef struct Hu1  {Hu MY_NV1(U, );}   Hu1;
typedef struct Hu2  {Hu MY_NV2(U, );}   Hu2;
typedef struct Hu3  {Hu MY_NV3(U, );}   Hu3;
typedef struct Hu4  {Hu MY_NV4(U, );}   Hu4;
typedef struct Hu8  {Hu MY_NV8(U, );}   Hu8;
typedef struct Hu16 {Hu MY_NV16(U,);}   Hu16;

typedef HALF_ITYPE  Hi;
typedef struct Hi1  {Hi MY_NV1(I, );}   Hi1;
typedef struct Hi2  {Hi MY_NV2(I, );}   Hi2;
typedef struct Hi3  {Hi MY_NV3(I, );}   Hi3;
typedef struct Hi4  {Hi MY_NV4(I, );}   Hi4;
typedef struct Hi8  {Hi MY_NV8(I, );}   Hi8;
typedef struct Hi16 {Hi MY_NV16(I,);}   Hi16;

typedef HALF_FTYPE  Hf;
typedef struct Hf1  {Hf MY_NV1(F, );}   Hf1;
typedef struct Hf2  {Hf MY_NV2(F, );}   Hf2;
typedef struct Hf3  {Hf MY_NV3(F, );}   Hf3;
typedef struct Hf4  {Hf MY_NV4(F, );}   Hf4;
typedef struct Hf8  {Hf MY_NV8(F, );}   Hf8;
typedef struct Hf16 {Hf MY_NV16(F,);}   Hf16;

typedef WORD_UTYPE  Wu;
typedef struct Wu1  {Wu MY_NV1(U, );}   Wu1;
typedef struct Wu2  {Wu MY_NV2(U, );}   Wu2;
typedef struct Wu3  {Wu MY_NV3(U, );}   Wu3;
typedef struct Wu4  {Wu MY_NV4(U, );}   Wu4;
typedef struct Wu8  {Wu MY_NV8(U, );}   Wu8;
typedef struct Wu16 {Wu MY_NV16(U,);}   Wu16;

typedef WORD_ITYPE  Wi;
typedef struct Wi1  {Wi MY_NV1(I, );}   Wi1;
typedef struct Wi2  {Wi MY_NV2(I, );}   Wi2;
typedef struct Wi3  {Wi MY_NV3(I, );}   Wi3;
typedef struct Wi4  {Wi MY_NV4(I, );}   Wi4;
typedef struct Wi8  {Wi MY_NV8(I, );}   Wi8;
typedef struct Wi16 {Wi MY_NV16(I, );}  Wi16;

typedef WORD_FTYPE  Wf;
typedef struct Wf1  {Wf MY_NV1(F, );}   Wf1;
typedef struct Wf2  {Wf MY_NV2(F, );}   Wf2;
typedef struct Wf3  {Wf MY_NV3(F, );}   Wf3;
typedef struct Wf4  {Wf MY_NV4(F, );}   Wf4;
typedef struct Wf8  {Wf MY_NV8(F, );}   Wf8;
typedef struct Wf16 {Wf MY_NV16(F,);}   Wf16;

typedef DWRD_UTYPE  Du;
typedef struct Du1  {Du MY_NV1(U, );}   Du1;
typedef struct Du2  {Du MY_NV2(U, );}   Du2;
typedef struct Du3  {Du MY_NV3(U, );}   Du3;
typedef struct Du4  {Du MY_NV4(U, );}   Du4;
typedef struct Du8  {Du MY_NV8(U, );}   Du8;

typedef DWRD_ITYPE  Di;
typedef struct Di1  {Di MY_NV1(I, );}   Di1;
typedef struct Di2  {Di MY_NV2(I, );}   Di2;
typedef struct Di3  {Di MY_NV3(I, );}   Di3;
typedef struct Di4  {Di MY_NV4(I, );}   Di4;
typedef struct Di8  {Di MY_NV8(I, );}   Di8;

typedef DWRD_FTYPE  Df;
typedef struct Df1  {Df MY_NV1(F, );}   Df1;
typedef struct Df2  {Df MY_NV2(F, );}   Df2;
typedef struct Df3  {Df MY_NV3(F, );}   Df3;
typedef struct Df4  {Df MY_NV4(F, );}   Df4;
typedef struct Df8  {Df MY_NV8(F, );}   Df8;

#if _LEAVE_EXTNUM_HOMOGENOUS_AGGREGATES
}
#endif

/*  Trying to design an efficient API based on only one C
    type for each of the 52 vector configurations is simply
    impossible. This seems like a good reason why not even
    C23 touches SIMD vectors despite their commonplace
    existence for over 20 years. So what is the solution?
    Define two types for each configuration! One for low
    level API / ABI design and another for higher level
    applications.

    Thankfully it was easy to add the "Machine Vector Types"
    to the project without changing very much. The way it
    works is simple:

    *   Virtual Vector Types have names like `Vqhf`, and are
        guaranteed to be unique types in the context of a C
        `_Generic` selection. User applications should be
        encouraged to restrict SIMD vector usage to the set
        of Virtual Vector types.

    *   Machine Vector Types have names like `Qhf` and not
        only aren't guaranteed to be _Generic unique but may
        not even be defined at all for a particular target.
        Unfortunately, designing new low level SIMD vector
        operations will require experience with the Machine
        Vector Types, at least if one wants to ensure the
        unavoidable performance overhead added by using HVA
        types for the Virtual Vectors. Since we go out of
        our way to ensure even these somewhat "private" types
        are well documented, this shouldn't be a problem.
        Not to mention, it is extremely unlikely to find a
        low level operation without an interface already
        available.

    Since they're incompatible with `_Generic`, the Machine
    Vector types don't have their own operation suffix.
    Instead, operations are always defined as `QHF_XXXX`,
    where `xxxxqhf` would be the corresponding operation on
    the Virtual Vector.

    For posterity, MSVC defines its __m64 in <mmintrin.h> as
    something similar to the following:

    typedef union __declspec(intrin_type) __declspec(align(8))
    __m64
    {
        unsigned __int64    m64_u64;
        float               m64_f32 [2];
        __int8              m64_i8  [8];
        __int16             m64_i16 [4];
        __int32             m64_i32 [2];
        __int64             m64_i64;
        unsigned __int8     m64_u8  [8];
        unsigned __int16    m64_u16 [4];
        unsigned __int32    m64_u32 [2];
    } __m64;

*/

typedef union Byte {
    char        C[1];
    uint8_t     U;
    int8_t      I;
    _Bool       Y;
    union       {Bu1 U; Bi1 I; Bc1 C;} M1;
    struct      {bool       MY_NV8(Y, :1), :0; };
    struct      {char       MY_NV1(C, );       };
    struct      {uint8_t    MY_NV1(U, );       };
    struct      {int8_t     MY_NV1(I, );       };
} Byte;

typedef union Half {
    char        C[2];
    Byte        B[2];
    union       {Hu1 U; Hi1 I; Hf1 F;} M1;
    union       {Bu2 U; Bi2 I; Bc2 C;} M2;
    uint16_t    U;
    int16_t     I;
    flt16_t     F;
    struct      {bool   MY_NV16(Y, :1), :0; };
    struct      {char   MY_NV2( C,  );      };
    struct      {Byte   MY_NV2( B,  );      };
    struct      {Byte   MY_PAIR(Lo, Hi,  ); };
#if HALF_NPTR
    void        *A[HALF_NPTR];
    struct      {void   MY_NV1(*A,  );      };
#endif

} Half;

typedef union Word {
    char        C[4];
    Byte        B[4];
    Half        H[2];
    union       {Wu1 U; Wi1 I; Wf1 F;} M1;
    union       {Hu2 U; Hi2 I; Hf2 F;} M2;
    union       {Bu4 U; Bi4 I; Bc4 C;} M4;
    uint32_t    U;
    int32_t     I;
    float       F;
    struct      {bool   MY_NV32(Y, :1), :0; };
    struct      {char   MY_NV4( C,  );      };
    struct      {Byte   MY_NV4( B,  );      };
    struct      {Half   MY_NV2( H,  );      };
    struct      {Half   MY_PAIR(Lo, Hi,  ); };
#if WORD_NPTR
    void        *A[WORD_NPTR];
#   if WORD_NPTR == 2
    struct      {void   MY_NV2(*A,  );      };
#   else
    struct      {void   MY_NV1(*A,  );      };
#   endif

#endif

} Word;

typedef union Dwrd {
    char        C[8];
    Byte        B[8];
    Half        H[4];
    Word        W[2];
    union       {Du1 U; Di1 I; Df1 F;} M1;
    union       {Wu2 U; Wi2 I; Wf2 F;} M2;
    union       {Hu4 U; Hi4 I; Hf4 F;} M4;
    union       {Bu8 U; Bi8 I; Bc8 C;} M8;
    uint64_t    U;
    int64_t     I;
    double      F;
    struct      {bool   MY_NV64(Y, :1), :0; };
    struct      {char   MY_NV8( C,  );      };
    struct      {Byte   MY_NV8( B,  );      };
    struct      {Half   MY_NV4( H,  );      };
    struct      {Word   MY_NV2( W,  );      };
    struct      {Word   MY_PAIR(Lo, Hi,  ); };
#if DWRD_NPTR
    void    *A[DWRD_NPTR];
#   if   DWRD_NPTR == 4
    struct      {void   MY_NV4(*A,  );      };
#   elif DWRD_NPTR == 2
    struct      {void   MY_NV2(*A,  );      };
#   else
    struct      {void   MY_NV1(*A,  );      };
#   endif

#endif

} Dwrd;

typedef union Quad {
    char        C[16];
    Byte        B[16];
    Half        H[ 8];
    Word        W[ 4];
    Dwrd        D[ 2];
    union       {Du2  U; Di2  I; Df2  F;} M2;
    union       {Wu4  U; Wi4  I; Wf4  F;} M4;
    union       {Hu8  U; Hi8  I; Hf8  F;} M8;
    union       {Bu16 U; Bi16 I; Bc16 C;} M16;
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


#if _ENTER_EXTNUM_SIZES_TEST
{
#endif

#if 1

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

ASSERT(127-0*1 == offsetof(MY_SIZES_TEST,B0));
ASSERT(127-1*1 == offsetof(MY_SIZES_TEST,B1));
ASSERT(127-2*1 == offsetof(MY_SIZES_TEST,B2));
ASSERT(127-3*1 == offsetof(MY_SIZES_TEST,B3));
ASSERT(127-4*1 == offsetof(MY_SIZES_TEST,B4));
ASSERT(127-5*1 == offsetof(MY_SIZES_TEST,B5));
ASSERT(127-6*1 == offsetof(MY_SIZES_TEST,B6));
ASSERT(127-7*1 == offsetof(MY_SIZES_TEST,B7));
ASSERT(127-8*1 == offsetof(MY_SIZES_TEST,B8));
ASSERT(127-8*2 == offsetof(MY_SIZES_TEST,B16));
ASSERT(127-8*3 == offsetof(MY_SIZES_TEST,B24));
ASSERT(127-8*4 == offsetof(MY_SIZES_TEST,B32));

ASSERT(sizeof(BYTE_TYPE) == 1);
ASSERT(sizeof(BYTE_ITYPE) == 1);
ASSERT(sizeof(BYTE_UTYPE) == 1);

ASSERT(sizeof(HALF_TYPE) == 2);
ASSERT(sizeof(HALF_ITYPE) == 2);
ASSERT(sizeof(HALF_UTYPE) == 2);
ASSERT(sizeof(HALF_FTYPE) == 2);
ASSERT(sizeof(HALF_LOTYPE) == 1);
ASSERT(sizeof(HALF_HITYPE) == 1);

ASSERT(sizeof(WORD_TYPE) == 4);
ASSERT(sizeof(WORD_ITYPE) == 4);
ASSERT(sizeof(WORD_UTYPE) == 4);
ASSERT(sizeof(WORD_FTYPE) == 4);
ASSERT(sizeof(WORD_LOTYPE) == 2);
ASSERT(sizeof(WORD_HITYPE) == 2);

ASSERT(sizeof(DWRD_TYPE) == 8);
ASSERT(sizeof(DWRD_ITYPE) == 8);
ASSERT(sizeof(DWRD_UTYPE) == 8);
ASSERT(sizeof(DWRD_FTYPE) == 8);
ASSERT(sizeof(DWRD_LOTYPE) == 4);
ASSERT(sizeof(DWRD_HITYPE) == 4);

ASSERT(sizeof(QUAD_TYPE) == 16);
ASSERT(sizeof(QUAD_LOTYPE) == 8);
ASSERT(sizeof(QUAD_HITYPE) == 8);

ASSERT( 1 == sizeof(Byte));
ASSERT( 2 == sizeof(Half));
ASSERT( 4 == sizeof(Word));
ASSERT( 8 == sizeof(Dwrd));
ASSERT(16 == sizeof(Quad));

#endif

#if _LEAVE_EXTNUM_SIZES_TEST
}
#endif

/*  The following constants specify the byte offset of a
    particular vector element. E.g. `QUAD_W1` identifies 
    the offset of the least significant byte of the 'W1'
    element of a quadword.
*/
#if MY_ENDIAN == ENDIAN_BIG

#   define  QUAD_B0     15  
#   define  QUAD_B1     14
#   define  QUAD_B2     13  
#   define  QUAD_B3     12 
#   define  QUAD_B4     11 
#   define  QUAD_B5     10
#   define  QUAD_B6     9
#   define  QUAD_B7     8
#   define  QUAD_B8     7 
#   define  QUAD_B9     6
#   define  QUAD_B10    5
#   define  QUAD_B11    4
#   define  QUAD_B12    3
#   define  QUAD_B13    2 
#   define  QUAD_B14    1
#   define  QUAD_B15    0

#   define  DWRD_B0     7
#   define  DWRD_B1     6
#   define  DWRD_B2     5
#   define  DWRD_B3     4
#   define  DWRD_B4     3
#   define  DWRD_B5     2
#   define  DWRD_B6     1
#   define  DWRD_B7     0

#   define  WORD_B0     3
#   define  WORD_B1     2
#   define  WORD_B2     1
#   define  WORD_B3     0

#   define  HALF_B0     1
#   define  HALF_B1     0

#else

#   define  QUAD_B0     0
#   define  QUAD_B1     1
#   define  QUAD_B2     2
#   define  QUAD_B3     3
#   define  QUAD_B4     4
#   define  QUAD_B5     5
#   define  QUAD_B6     6
#   define  QUAD_B7     7
#   define  QUAD_B8     8
#   define  QUAD_B9     9
#   define  QUAD_B10    10
#   define  QUAD_B11    11
#   define  QUAD_B12    12
#   define  QUAD_B13    13
#   define  QUAD_B14    14
#   define  QUAD_B15    15

#   define  DWRD_H0     0
#   define  DWRD_H1     2
#   define  DWRD_H2     4
#   define  DWRD_H3     6

#   define  WORD_B0     0
#   define  WORD_B1     1
#   define  WORD_B2     2
#   define  WORD_B3     3

#   define  HALF_B0     0
#   define  HALF_B1     1

#endif

#if MY_VECTOR_ENDIAN == ENDIAN_BIG

#   define  WORD_H0     2
#   define  WORD_H1     0

#   define  DWRD_H0     6
#   define  DWRD_H1     4
#   define  DWRD_H2     2
#   define  DWRD_H3     0

#   define  DWRD_W0     4
#   define  DWRD_W1     0

#   define  QUAD_H0     14
#   define  QUAD_H1     12
#   define  QUAD_H2     10
#   define  QUAD_H3     8
#   define  QUAD_H4     6
#   define  QUAD_H5     4 
#   define  QUAD_H6     2
#   define  QUAD_H7     0

#   define  QUAD_W3     12
#   define  QUAD_W2     8
#   define  QUAD_W1     4
#   define  QUAD_W0     0

#   define  QUAD_D0     8
#   define  QUAD_D1     0

#else

#   define  QUAD_H0     0
#   define  QUAD_H1     2
#   define  QUAD_H2     4
#   define  QUAD_H3     6
#   define  QUAD_H4     8
#   define  QUAD_H5     10
#   define  QUAD_H6     12
#   define  QUAD_H7     14

#   define  QUAD_W0     0
#   define  QUAD_W1     4
#   define  QUAD_W2     8
#   define  QUAD_W3     12

#   define  QUAD_D0     0
#   define  QUAD_D1     8

#   define  DWRD_B0     0
#   define  DWRD_B1     1
#   define  DWRD_B2     2
#   define  DWRD_B3     3
#   define  DWRD_B4     4
#   define  DWRD_B5     5
#   define  DWRD_B6     6
#   define  DWRD_B7     7

#   define  DWRD_W0     0
#   define  DWRD_W1     4

#   define  WORD_H0     0
#   define  WORD_H1     2

#endif

/*  The representation of 32 bit element K2 in a 128 bit
    bit vector can be obtained by copying the 4 bytes at:
        V.B[WORD_B0+QUAD_W2]
        V.B[WORD_B1+QUAD_W2]
        V.B[WORD_B2+QUAD_W2]
        V.B[WORD_B3+QUAD_W2]
    
    zle+vle: 8,9,10,11
    zle+vbe: 4,5,6,7
    zbe+vle: 11,10,9,8
    zbe+vbe: 7,6,5,4
    
    On a little endian target with little endian vectors,
    that would evaluate to bytes 8,9,10,and 11. Wi
#define     VWBU_PERS(v, ...)   WBU_ASTV(WBU_PERS(VWBU_ASTM(v),__VA_ARGS__))
#define     VWBI_PERS(v, ...)   WBI_ASTV(WBI_PERS(VWBI_ASTM(v),__VA_ARGS__))

#define     VWHU_PERS(v, ...)   WHU_ASTV(WHU_PERS(VWHU_ASTM(v),__VA_ARGS__))
#define     VWHI_PERS(v, ...)   WHI_ASTV(WHI_PERS(VWHI_ASTM(v),__VA_ARGS__))
#define     VWHF_PERS(v, ...)   WHF_ASTV(WHF_PERS(VWHF_ASTM(v),__VA_ARGS__))

#define     VDBU_PERS(v, ...)   DBU_ASTV(DBU_PERS(VDBU_ASTM(v),__VA_ARGS__))
#define     VDBI_PERS(v, ...)   DBI_ASTV(DBI_PERS(VDBI_ASTM(v),__VA_ARGS__))

#define     VDHU_PERS(v, ...)   DHU_ASTV(DHU_PERS(VDHU_ASTM(v),__VA_ARGS__))
#define     VDHI_PERS(v, ...)   DHI_ASTV(DHI_PERS(VDHI_ASTM(v),__VA_ARGS__))
#define     VDHF_PERS(v, ...)   DHF_ASTV(DHF_PERS(VDHF_ASTM(v),__VA_ARGS__))

#define     VDWU_PERS(v, ...)   DWU_ASTV(DWU_PERS(VDWU_ASTM(v),__VA_ARGS__))
#define     VDWI_PERS(v, ...)   DWI_ASTV(DWI_PERS(VDWI_ASTM(v),__VA_ARGS__))
#define     VDWF_PERS(v, ...)   DWF_ASTV(DWF_PERS(VDWF_ASTM(v),__VA_ARGS__))

*/


#endif // EOF("extnum.h")

#if _LEAVE_EXTNUM
}
#endif

#if _ENTER_EXTREPR
{
#endif
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳

    Symbolic constants used to identify a value's C type.

    This type system recognizes three value categories:

    *   (K) scalars, which includes ints and floats

    *   (V) vectors

    *   (A) aggregates, which consist of one or more vector
        or scalars arranged consecutively

    Encoded in the first 8 bits of a REPR type code are:

    *   for scalars and vectors, its numeric type, i.e. 
        signed, unsigned, or floating point

    *   the log2 of its bit width. E.g. for 64 bit types,
        the width field will be set to REPR_K64

    *   its integer byteorder

    *   its endianness, which is *not* the same thing as 
        the previously mentioned byteorder

    Note: If «REPR_K != ((T&0xff) >> 6)», the type is NOT
    a scalar type and thus requires at least one more byte
    to represent.

    The next 8 bits (8..16) contains:

    *   its total log2 size in bytes

    *   its homogeneous aggregate length

*/

#ifndef     MY_EXTREPR_H // BOF("extrepr.h")
#define     MY_EXTREPR_H    1

#ifndef     MY_EXTNUM_H
#include      "extnum.h"
#endif

#ifndef     MY_LIMITS_H
#define     MY_LIMITS_H
#include      <limits.h>
#endif

//                      (  mmmmzzzcckkkttt)
// Type (t)
#define     REPR_ZL     (0b000000000000000) // LIL_ENDIAN integer
#define     REPR_ZB     (0b000000000000001) // BIG_ENDIAN integer

#define     REPR_IL     (0b000000000000010) // LIL_ENDIAN signed int
#define     REPR_IB     (0b000000000000011) // BIG_ENDIAN signed int

#define     REPR_FLZL   (0b000000000000100) // le: Mant,Expo,Sign
#define     REPR_FBZL   (0b000000000000110) // le: Sign,Expo,Mant
#define     REPR_FLZB   (0b000000000000101) // be: Mant,Expo,Sign
#define     REPR_FBZB   (0b000000000000111) // be: Sign,Expo,Mant
//                      (           kkk   )
// Log2 element size (k)
#define     REPR_K1     (0b000000000000000) // (1<<0) = 1 bit
#define     REPR_K2     (0b000000000001000) // (1<<1) = 2 bit
#define     REPR_K4     (0b000000000010000) // (1<<2) = 4 bit
#define     REPR_K8     (0b000000000011000) // (1<<3) = 8 bit
#define     REPR_K16    (0b000000000100000) // (1<<4) = 16 bit
#define     REPR_K32    (0b000000000101000) // (1<<5) = 32 bit
#define     REPR_K64    (0b000000000110000) // (1<<6) = 64 bit
#define     REPR_K128   (0b000000000111000) // (1<<7) = 128 bit

// Category (c)
//                      (         cc      )
#define     REPR_K      (0b000000000000000) // scalar
#define     REPR_VL     (0b000000001000000) // v[0]=a[0]
#define     REPR_VB     (0b000000010000000) // v[0]=a[-1]
#define     REPR_A      (0b000000011000000) // aggregate

#if MY_ENDIAN == ENDIAN_BIG
#   define  REPR_U      REPR_ZB // be unsigned int
#   define  REPR_I      REPR_IB // be signed int
#   define  REPR_FL     REPR_FLZB // le bef.Mant
#   define  REPR_FB     REPR_FBZB // be bef.Mant
#else
#   define  REPR_U      REPR_ZL
#   define  REPR_I      REPR_IL
#   define  REPR_FL     REPR_FLZL
#   define  REPR_FB     REPR_FBZL
#endif

#if MY_VECTOR_ENDIAN == ENDIAN_BIG
#   define  REPR_V      REPR_VB
#else
#   define  REPR_V      REPR_VL
#endif

/*  Object log2 size (z)
*/

//                      (      zzz        )
#define     REPR_SZB    (0b000000000000000) // 1 byte
#define     REPR_SZH    (0b000000100000000) // 2 byte
#define     REPR_SZW    (0b000001000000000) // 4 byte
#define     REPR_SZD    (0b000001100000000) // 8 byte
#define     REPR_SZQ    (0b000010000000000) // 16 byte
#define     REPR_SZO    (0b000010100000000) // 32 byte
#define     REPR_SZS    (0b000011000000000) // 64 byte
#define     REPR_SZV    (0b000011100000000) // custom size

#define     REPR_SZL    ((INT_MAX==LONG_MAX)?REPR_SZW:REPR_SZD)
#define     REPR_SZLL   ((ULLONG_MAX>>64)?REPR_SZD:REPR_SZQ)

/*  Homogeneous aggregate length (m)
    If (m) is less than 8, it represents an exact amount.
    Otherwise, the formula is «8<<(m-8)», which means e.g.
        m=6     (6)
        m=7     (7)
        m=8     (8)     (8<<(8-8) == 8<<0 == 8)
        m=9     (16)    (8<<(9-8) == 8<<1 == 16)
        m=10    (32)
        ...
        m=15    (1024)
*/
//                      (  mmmm           )
#define     REPR_M0     (0b000000000000000) // nohomo aggr
#define     REPR_M1     (0b000100000000000) // 1 object
#define     REPR_M2     (0b001000000000000) // 2 objects
#define     REPR_M3     (0b001100000000000) // 3 objects
#define     REPR_M4     (0b010000000000000) // 4 objects
#define     REPR_M5     (0b010100000000000) // 5 objects
#define     REPR_M6     (0b011000000000000) // 6 objects
#define     REPR_M7     (0b011100000000000) // 7 objects
#define     REPR_M8     (0b100000000000000) // 8 objects
#define     REPR_M16    (0b100100000000000)
#define     REPR_M32    (0b101000000000000)
#define     REPR_M64    (0b101100000000000)
#define     REPR_M128   (0b110000000000000)
#define     REPR_M256   (0b110100000000000)
#define     REPR_M512   (0b111000000000000)
#define     REPR_M1024  (0b111100000000000)

//                      (  mmmmzzzcckkkttt)

#if INT_MAX == LONG_MAX
#   define  REPR_KL    REPR_K32
#else
#   define  REPR_KL    REPR_K64
#endif

#if (ULLONG_MAX>>63) > 1
#   define  REPR_KLL    REPR_K128
#else
#   define  REPR_KLL    REPR_K64
#endif

#define     REPR_YU     (REPR_U|REPR_K1)
#define     REPR_YU1    (REPR_YU|REPR_M1)
#define     REPR_YU2    (REPR_YU|REPR_M2)
#define     REPR_YU3    (REPR_YU|REPR_M3)
#define     REPR_YU4    (REPR_YU|REPR_M4)
#define     REPR_YU8    (REPR_YU|REPR_M8)
#define     REPR_YU16   (REPR_YU|REPR_M16)
#define     REPR_YU32   (REPR_YU|REPR_M32)
#define     REPR_YU64   (REPR_YU|REPR_M64)

#define     REPR_BU     (REPR_U|REPR_K8)
#define     REPR_BU1    (REPR_BU|REPR_M1)
#define     REPR_BU2    (REPR_BU|REPR_M2)
#define     REPR_BU3    (REPR_BU|REPR_M3)
#define     REPR_BU4    (REPR_BU|REPR_M4)
#define     REPR_BU8    (REPR_BU|REPR_M8)
#define     REPR_BU16   (REPR_BU|REPR_M16)
#define     REPR_BU32   (REPR_BU|REPR_M32)
#define     REPR_BU64   (REPR_BU|REPR_M64)

#define     REPR_BI     (REPR_I|REPR_K8)
#define     REPR_BI1    (REPR_BI|REPR_M1)
#define     REPR_BI2    (REPR_BI|REPR_M2)
#define     REPR_BI3    (REPR_BI|REPR_M3)
#define     REPR_BI4    (REPR_BI|REPR_M4)
#define     REPR_BI8    (REPR_BI|REPR_M8)
#define     REPR_BI16   (REPR_BI|REPR_M16)
#define     REPR_BI32   (REPR_BI|REPR_M32)
#define     REPR_BI64   (REPR_BI|REPR_M64)

#define     REPR_HU     (REPR_U|REPR_K16)
#define     REPR_HU1    (REPR_HU|REPR_M1)
#define     REPR_HU2    (REPR_HU|REPR_M2)
#define     REPR_HU3    (REPR_HU|REPR_M3)
#define     REPR_HU4    (REPR_HU|REPR_M4)
#define     REPR_HU8    (REPR_HU|REPR_M8)
#define     REPR_HU16   (REPR_HU|REPR_M16)
#define     REPR_HU32   (REPR_HU|REPR_M32)

#define     REPR_HI     (REPR_I|REPR_K16)
#define     REPR_HI1    (REPR_HI|REPR_M1)
#define     REPR_HI2    (REPR_HI|REPR_M2)
#define     REPR_HI3    (REPR_HI|REPR_M3)
#define     REPR_HI4    (REPR_HI|REPR_M4)
#define     REPR_HI8    (REPR_HI|REPR_M8)
#define     REPR_HI16   (REPR_HI|REPR_M16)
#define     REPR_HI32   (REPR_HI|REPR_M32)

#if FLT16_ENDIAN == ENDIAN_BIG
#   define  REPR_HF     (REPR_FB|REPR_K16)
#else
#   define  REPR_HF     (REPR_FL|REPR_K16)
#endif

#define     REPR_HF1    (REPR_HF|REPR_M1)
#define     REPR_HF2    (REPR_HF|REPR_M2)
#define     REPR_HF3    (REPR_HF|REPR_M3)
#define     REPR_HF4    (REPR_HF|REPR_M4)
#define     REPR_HF8    (REPR_HF|REPR_M8)
#define     REPR_HF16   (REPR_HF|REPR_M16)
#define     REPR_HF32   (REPR_HF|REPR_M32)


#define     REPR_WU     (REPR_U|REPR_K32)
#define     REPR_WU1    (REPR_WU|REPR_M1)
#define     REPR_WU2    (REPR_WU|REPR_M2)
#define     REPR_WU3    (REPR_WU|REPR_M3)
#define     REPR_WU4    (REPR_WU|REPR_M4)
#define     REPR_WU8    (REPR_WU|REPR_M8)
#define     REPR_WU16   (REPR_WU|REPR_M16)

#define     REPR_WI     (REPR_I|REPR_K32)
#define     REPR_WI1    (REPR_WI|REPR_M1)
#define     REPR_WI2    (REPR_WI|REPR_M2)
#define     REPR_WI3    (REPR_WI|REPR_M3)
#define     REPR_WI4    (REPR_WI|REPR_M4)
#define     REPR_WI8    (REPR_WI|REPR_M8)
#define     REPR_WI16   (REPR_WI|REPR_M16)

#if FLT16_ENDIAN == ENDIAN_BIG
#   define  REPR_WF     (REPR_FB|REPR_K32)
#else
#   define  REPR_WF     (REPR_FL|REPR_K32)
#endif

#define     REPR_WF1    (REPR_WF|REPR_M1)
#define     REPR_WF2    (REPR_WF|REPR_M2)
#define     REPR_WF3    (REPR_WF|REPR_M3)
#define     REPR_WF4    (REPR_WF|REPR_M4)
#define     REPR_WF8    (REPR_WF|REPR_M8)
#define     REPR_WF16   (REPR_WF|REPR_M16)

#define     REPR_DU     (REPR_U|REPR_K64)
#define     REPR_DU1    (REPR_DU|REPR_M1)
#define     REPR_DU2    (REPR_DU|REPR_M2)
#define     REPR_DU3    (REPR_DU|REPR_M3)
#define     REPR_DU4    (REPR_DU|REPR_M4)
#define     REPR_DU8    (REPR_DU|REPR_M8)

#define     REPR_DI     (REPR_I|REPR_K64)
#define     REPR_DI1    (REPR_DI|REPR_M1)
#define     REPR_DI2    (REPR_DI|REPR_M2)
#define     REPR_DI3    (REPR_DI|REPR_M3)
#define     REPR_DI4    (REPR_DI|REPR_M4)
#define     REPR_DI8    (REPR_DI|REPR_M8)

#if FLT16_ENDIAN == ENDIAN_BIG
#   define  REPR_DF     (REPR_FB|REPR_K32)
#else
#   define  REPR_DF     (REPR_FL|REPR_K32)
#endif

#define     REPR_DF1    (REPR_DF|REPR_M1)
#define     REPR_DF2    (REPR_DF|REPR_M2)
#define     REPR_DF3    (REPR_DF|REPR_M3)
#define     REPR_DF4    (REPR_DF|REPR_M4)
#define     REPR_DF8    (REPR_DF|REPR_M8)

#define     REPR_VW     (REPR_V|REPR_SZW)
#define     REPR_VD     (REPR_V|REPR_SZD)
#define     REPR_VQ     (REPR_V|REPR_SZQ)
#define     REPR_VO     (REPR_V|REPR_SZO)
#define     REPR_VS     (REPR_V|REPR_SZS)

#define     REPR_VWYU   (REPR_VW|REPR_YU)
#define     REPR_VDYU   (REPR_VD|REPR_YU)
#define     REPR_VQYU   (REPR_VQ|REPR_YU)
#define     REPR_VOYU   (REPR_VO|REPR_YU)
#define     REPR_VSYU   (REPR_VS|REPR_YU)

#define     REPR_VWBU   (REPR_VW|REPR_BU)
#define     REPR_VWBI   (REPR_VW|REPR_BI)
#define     REPR_VWHU   (REPR_VW|REPR_HU)
#define     REPR_VWHI   (REPR_VW|REPR_HI)
#define     REPR_VWHF   (REPR_VW|REPR_HF)
#define     REPR_VWWU   (REPR_VW|REPR_WU)
#define     REPR_VWWI   (REPR_VW|REPR_WI)
#define     REPR_VWWF   (REPR_VW|REPR_WF)

#define     REPR_VDBU   (REPR_VD|REPR_BU)
#define     REPR_VDBI   (REPR_VD|REPR_BI)
#define     REPR_VDHU   (REPR_VD|REPR_HU)
#define     REPR_VDHI   (REPR_VD|REPR_HI)
#define     REPR_VDHF   (REPR_VD|REPR_HF)
#define     REPR_VDWU   (REPR_VD|REPR_WU)
#define     REPR_VDWI   (REPR_VD|REPR_WI)
#define     REPR_VDWF   (REPR_VD|REPR_WF)
#define     REPR_VDDU   (REPR_VD|REPR_DU)
#define     REPR_VDDI   (REPR_VD|REPR_DI)
#define     REPR_VDDF   (REPR_VD|REPR_DF)

#define     REPR_VQBU   (REPR_VQ|REPR_BU)
#define     REPR_VQBI   (REPR_VQ|REPR_BI)
#define     REPR_VQHU   (REPR_VQ|REPR_HU)
#define     REPR_VQHI   (REPR_VQ|REPR_HI)
#define     REPR_VQHF   (REPR_VQ|REPR_HF)
#define     REPR_VQWU   (REPR_VQ|REPR_WU)
#define     REPR_VQWI   (REPR_VQ|REPR_WI)
#define     REPR_VQWF   (REPR_VQ|REPR_WF)
#define     REPR_VQDU   (REPR_VQ|REPR_DU)
#define     REPR_VQDI   (REPR_VQ|REPR_DI)
#define     REPR_VQDF   (REPR_VQ|REPR_DF)

#define     REPR_VOBU   (REPR_VO|REPR_BU)
#define     REPR_VOBI   (REPR_VO|REPR_BI)
#define     REPR_VOHU   (REPR_VO|REPR_HU)
#define     REPR_VOHI   (REPR_VO|REPR_HI)
#define     REPR_VOHF   (REPR_VO|REPR_HF)
#define     REPR_VOWU   (REPR_VO|REPR_WU)
#define     REPR_VOWI   (REPR_VO|REPR_WI)
#define     REPR_VOWF   (REPR_VO|REPR_WF)
#define     REPR_VODU   (REPR_VO|REPR_DU)
#define     REPR_VODI   (REPR_VO|REPR_DI)
#define     REPR_VODF   (REPR_VO|REPR_DF)

#define     REPR_VSBU   (REPR_VS|REPR_BU)
#define     REPR_VSBI   (REPR_VS|REPR_BI)
#define     REPR_VSHU   (REPR_VS|REPR_HU)
#define     REPR_VSHI   (REPR_VS|REPR_HI)
#define     REPR_VSHF   (REPR_VS|REPR_HF)
#define     REPR_VSWU   (REPR_VS|REPR_WU)
#define     REPR_VSWI   (REPR_VS|REPR_WI)
#define     REPR_VSWF   (REPR_VS|REPR_WF)
#define     REPR_VSDU   (REPR_VS|REPR_DU)
#define     REPR_VSDI   (REPR_VS|REPR_DI)
#define     REPR_VSDF   (REPR_VS|REPR_DF)

#define     BOOL_REPR   REPR_YU

#define     UCHAR_REPR  REPR_BU
#define     SCHAR_REPR  REPR_BI

#define     USHRT_REPR  REPR_HU
#define     SHRT_REPR   REPR_HI

#define     UINT_REPR   REPR_WU
#define     INT_REPR    REPR_WI

#if REPR_KL == REPR_K32
#   define  ULONG_REPR  REPR_WU
#   define  LONG_REPR   REPR_WI
#else
#   define  ULONG_REPR  REPR_DU
#   define  LONG_REPR   REPR_DI
#endif

#if REPR_KLL == REPR_K64
#   define  ULLONG_REPR REPR_DU
#   define  LLONG_REPR  REPR_DI
#else
#   define  ULLONG_REPR REPR_QU
#   define  LLONG_REPR  REPR_QI
#endif

#if defined(FLT16_MTYPE)
#   define  FLT16_REPR  REPR_HF
#else
#   define  FLT16_REPR  REPR_HU1
#endif

#define     FLT_REPR        REPR_WF
#define     DBL_REPR        REPR_DF

#define     UINT8_REPR      REPR_BU
#define     INT8_REPR       REPR_BI

#define     UINT16_REPR     REPR_HU
#define     INT16_REPR      REPR_HI

#define     UINT32_REPR     REPR_WU
#define     INT32_REPR      REPR_WI

#define     UINT64_REPR     REPR_DU
#define     INT64_REPR      REPR_DI

#if UINTMAX_MAX == UINT64_MAX
#   define  UINTMAX_REPR    REPR_DU
#   define  INTMAX_REPR     REPR_DI
#else
#   define  UINTMAX_REPR    REPR_QU
#   define  INTMAX_REPR     REPR_QI
#endif

#if ADDR_WIDTH == 16
#   define  UINTPTR_REPR    REPR_HU
#   define  INTPTR_REPR     REPR_HI
#elif ADDR_WIDTH == 32
#   define  UINTPTR_REPR    REPR_WU
#   define  INTPTR_REPR     REPR_WI
#elif ADDR_WIDTH == 64
#   define  UINTPTR_REPR    REPR_DU
#   define  INTPTR_REPR     REPR_DI
#elif ADDR_WIDTH == 128
#   define  UINTPTR_REPR    REPR_QU
#   define  INTPTR_REPR     REPR_QI
#endif

#endif // EOF("extrepr.h")

#if _LEAVE_EXTREPR
}
#endif


#if _ENTER_EXTVEC
{
#endif

#ifndef MY_EXTVEC_H // BOF("extvec.h")
#define MY_EXTVEC_H     1

#ifndef MY_EXTREPR_H
#include  "extrepr.h"
#endif

#if _ENTER_EXTVEC_VLANES
{
#endif


#define     VWYU_(_)    VWYU_##_
#define     VDYU_(_)    VDYU_##_
#define     VQYU_(_)    VOYU_##_
#define     VOYU_(_)    VOYU_##_
#define     VSYU_(_)    VSYU_##_

#define     VWBU_(_)    VWBU_##_
#define     VDBU_(_)    VDBU_##_
#define     VQBU_(_)    VQBU_##_
#define     VOBU_(_)    VOBU_##_
#define     VSBU_(_)    VSBU_##_

#define     VWBI_(_)    VWBI_##_
#define     VDBI_(_)    VDBI_##_
#define     VQBI_(_)    VQBI_##_
#define     VOBI_(_)    VOBI_##_
#define     VSBI_(_)    VSBI_##_

#define     VWBC_(_)    VWBC_##_
#define     VDBC_(_)    VDBC_##_
#define     VQBC_(_)    VQBC_##_
#define     VOBC_(_)    VOBC_##_
#define     VSBC_(_)    VSBC_##_


#define     VWHU_(_)    VWHU_##_
#define     VDHU_(_)    VDHU_##_
#define     VQHU_(_)    VQHU_##_
#define     VOHU_(_)    VOHU_##_
#define     VSHU_(_)    VSHU_##_

#define     VWHI_(_)    VWHI_##_
#define     VDHI_(_)    VDHI_##_
#define     VQHI_(_)    VQHI_##_
#define     VOHI_(_)    VOHI_##_
#define     VSHI_(_)    VSHI_##_

#define     VWHF_(_)    VWHF_##_
#define     VDHF_(_)    VDHF_##_
#define     VQHF_(_)    VQHF_##_
#define     VOHF_(_)    VOHF_##_
#define     VSHF_(_)    VSHF_##_

#define     VWWU_(_)    VWWU_##_
#define     VDWU_(_)    VDWU_##_
#define     VQWU_(_)    VQWU_##_
#define     VOWU_(_)    VOWU_##_
#define     VSWU_(_)    VSWU_##_

#define     VWWI_(_)    VWWI_##_
#define     VDWI_(_)    VDWI_##_
#define     VQWI_(_)    VQWI_##_
#define     VOWI_(_)    VOWI_##_
#define     VSWI_(_)    VSWI_##_

#define     VWWF_(_)    VWWF_##_
#define     VDWF_(_)    VDWF_##_
#define     VQWF_(_)    VQWF_##_
#define     VOWF_(_)    VOWF_##_
#define     VSWF_(_)    VSWF_##_

#define     VDDU_(_)    VDDU_##_
#define     VQDU_(_)    VQDU_##_
#define     VODU_(_)    VODU_##_
#define     VSDU_(_)    VSDU_##_

#define     VDDI_(_)    VDDI_##_
#define     VQDI_(_)    VQDI_##_
#define     VODI_(_)    VODI_##_
#define     VSDI_(_)    VSDI_##_

#define     VDDF_(_)    VDDF_##_
#define     VQDF_(_)    VQDF_##_
#define     VODF_(_)    VODF_##_
#define     VSDF_(_)    VSDF_##_

#if CHAR_SIGNEDNESS 
#   define  VWBC_BASE   VWBI_
#   define  VDBC_BASE   VDBI_
#   define  VQBC_BASE   VQBI_
#   define  VOBC_BASE   VOBI_
#   define  VSBC_BASE   VSBI_
#else
#   define  VWBC_BASE   VWBU_
#   define  VDBC_BASE   VDBU_
#   define  VQBC_BASE   VQBU_
#   define  VOBC_BASE   VOBU_
#   define  VSBC_BASE   VSBU_
#endif

#define     VWBU_STG    WORD_
#define     VDBU_STG    DWRD_
#define     VQBU_STG    QUAD_
#define     VOBU_STG    OCTA_
#define     VSBU_STG    SEXD_

#define     VWBI_STG    WORD_
#define     VDBI_STG    DWRD_
#define     VQBI_STG    QUAD_
#define     VOBI_STG    OCTA_
#define     VSBI_STG    SEXD_

#define     VWBC_STG    VWBC_BASE(STG)
#define     VDBC_STG    VDBC_BASE(STG)
#define     VQBC_STG    VQBC_BASE(STG)
#define     VOBC_STG    VOBC_BASE(STG)
#define     VSBC_STG    VSBC_BASE(STG)

#define     VWHU_STG    WORD_
#define     VDHU_STG    DWRD_
#define     VQHU_STG    QUAD_
#define     VOHU_STG    OCTA_
#define     VSHU_STG    SEXD_

#define     VWHI_STG    WORD_
#define     VDHI_STG    DWRD_
#define     VQHI_STG    QUAD_
#define     VOHI_STG    OCTA_
#define     VSHI_STG    SEXD_

#define     VWHF_STG    WORD_
#define     VDHF_STG    DWRD_
#define     VQHI_STG    QUAD_
#define     VOHI_STG    OCTA_
#define     VSHI_STG    SEXD_

#define     VWWU_STG    WORD_
#define     VDWU_STG    DWRD_
#define     VQWU_STG    QUAD_
#define     VOWU_STG    OCTA_
#define     VSWU_STG    SEXD_

#define     VWWI_STG    WORD_
#define     VDWI_STG    DWRD_
#define     VQWI_STG    QUAD_
#define     VOWI_STG    OCTA_
#define     VSWI_STG    SEXD_

#define     VWWF_STG    WORD_
#define     VDWF_STG    DWRD_
#define     VQWI_STG    QUAD_
#define     VOWI_STG    OCTA_
#define     VSWI_STG    SEXD_

#define     VDDU_STG    DWRD_
#define     VQDU_STG    QUAD_
#define     VODU_STG    OCTA_
#define     VSDU_STG    SEXD_

#define     VDDI_STG    DWRD_
#define     VQDI_STG    QUAD_
#define     VODI_STG    OCTA_
#define     VSDI_STG    SEXD_

#define     VDDF_STG    DWRD_
#define     VQDF_STG    QUAD_
#define     VODF_STG    OCTA_
#define     VSDF_STG    SEXD_


#define     VWYU_K      BOOL_
#define     VDYU_K      BOOL_
#define     VQYU_K      BOOL_
#define     VOYU_K      BOOL_
#define     VSYU_K      BOOL_

#define     VWBU_K      BYTE_U
#define     VDBU_K      BYTE_U
#define     VQBU_K      BYTE_U
#define     VOBU_K      BYTE_U
#define     VQBU_K      BYTE_U

#define     VWBI_K      BYTE_I
#define     VDBI_K      BYTE_I
#define     VQBI_K      BYTE_I
#define     VOBI_K      BYTE_I
#define     VSBI_K      BYTE_I

#if CHAR_SIGNEDNESS 
#   define  VWBC_K      BYTE_I
#   define  VDBC_K      BYTE_I
#   define  VQBC_K      BYTE_I
#   define  VOBC_K      BYTE_I
#   define  VSBC_K      BYTE_I
#else
#   define  VWBC_K      BYTE_U
#   define  VDBC_K      BYTE_U
#   define  VQBC_K      BYTE_U
#   define  VOBC_K      BYTE_U
#   define  VSBC_K      BYTE_U
#endif

#define     VWHU_K      HALF_U
#define     VDHU_K      HALF_U
#define     VQHU_K      HALF_U
#define     VOHU_K      HALF_U
#define     VSHU_K      HALF_U

#define     VWHI_K      HALF_I
#define     VDHI_K      HALF_I
#define     VQHI_K      HALF_I
#define     VOHI_K      HALF_I
#define     VSHI_K      HALF_I

#define     VWHF_K      HALF_F
#define     VDHF_K      HALF_F
#define     VQHF_K      HALF_F
#define     VOHF_K      HALF_F
#define     VSHF_K      HALF_F

#define     VWWU_K      WORD_U
#define     VDWU_K      WORD_U
#define     VQWU_K      WORD_U
#define     VOWU_K      WORD_U
#define     VSWU_K      WORD_U

#define     VWWI_K      WORD_I
#define     VDWI_K      WORD_I
#define     VQWI_K      WORD_I
#define     VOWI_K      WORD_I
#define     VSWI_K      WORD_I

#define     VWWF_K      WORD_F
#define     VDWF_K      WORD_F
#define     VQWF_K      WORD_F
#define     VOWF_K      WORD_F
#define     VSWF_K      WORD_F

#define     VDDU_K      DWRD_U
#define     VQDU_K      DWRD_U
#define     VODU_K      DWRD_U
#define     VSDU_K      DWRD_U

#define     VDDI_K      DWRD_I
#define     VQDI_K      DWRD_I
#define     VODI_K      DWRD_I
#define     VSDI_K      DWRD_I

#define     VDDF_K      DWRD_F
#define     VQDF_K      DWRD_F
#define     VODF_K      DWRD_F
#define     VSDF_K      DWRD_F

#define     VWYU_KTYPE  _Bool
#define     VDYU_KTYPE  _Bool
#define     VQYU_KTYPE  _Bool
#define     VOYU_KTYPE  _Bool
#define     VSYU_KTYPE  _Bool

#if CHAR_SIGNEDNESS || !defined(_MSC_VER)
#   define  VWBU_KTYPE  unsigned char
#   define  VDBU_KTYPE  unsigned char
#   define  VQBU_KTYPE  unsigned char
#   define  VOBU_KTYPE  unsigned char
#   define  VSBU_KTYPE  unsigned char
#else
#   define  VWBU_KTYPE  char
#   define  VDBU_KTYPE  char
#   define  VQBU_KTYPE  char
#   define  VOBU_KTYPE  char
#   define  VSBU_KTYPE  char
#endif

#if CHAR_SIGNEDNESS && defined(_MSC_VER)
#   define  VWBI_KTYPE  char
#   define  VDBI_KTYPE  char
#   define  VQBI_KTYPE  char
#   define  VOBI_KTYPE  char
#   define  VSBI_KTYPE  char
#else
#   define  VWBI_KTYPE  signed char
#   define  VDBI_KTYPE  signed char
#   define  VQBI_KTYPE  signed char
#   define  VOBI_KTYPE  signed char
#   define  VSBI_KTYPE  signed char
#endif

#define     VWHU_KTYPE  unsigned short
#define     VDHU_KTYPE  unsigned short
#define     VQHU_KTYPE  unsigned short
#define     VOHU_KTYPE  unsigned short
#define     VSHU_KTYPE  unsigned short

#define     VWHI_KTYPE  short
#define     VDHI_KTYPE  short
#define     VQHI_KTYPE  short
#define     VOHI_KTYPE  short
#define     VSHI_KTYPE  short

#define     VWHF_KTYPE  flt16_t
#define     VDHF_KTYPE  flt16_t
#define     VQHF_KTYPE  flt16_t
#define     VOHF_KTYPE  flt16_t
#define     VSHF_KTYPE  flt16_t

#define     VWWU_KTYPE  unsigned int
#define     VDWU_KTYPE  unsigned int
#define     VQWU_KTYPE  unsigned int
#define     VOWU_KTYPE  unsigned int
#define     VSWU_KTYPE  unsigned int

#define     VWWI_KTYPE  int
#define     VDWI_KTYPE  int
#define     VQWI_KTYPE  int
#define     VOWI_KTYPE  int
#define     VSWI_KTYPE  int

#define     VWWF_KTYPE  float
#define     VDWF_KTYPE  float
#define     VQWF_KTYPE  float
#define     VOWF_KTYPE  float
#define     VSWF_KTYPE  float

#if DWRD_NLONG == 2
#   define  VDDU_KTYPE  unsigned long long
#   define  VQDU_KTYPE  unsigned long long
#   define  VODU_KTYPE  unsigned long long
#   define  VSDU_KTYPE  unsigned long long

#   define  VDDI_KTYPE  long long
#   define  VQDI_KTYPE  long long
#   define  VODI_KTYPE  long long
#   define  VSDI_KTYPE  long long
#else
#   define  VDDU_KTYPE  unsigned long
#   define  VQDU_KTYPE  unsigned long
#   define  VODU_KTYPE  unsigned long
#   define  VSDU_KTYPE  unsigned long

#   define  VDDI_KTYPE  long
#   define  VQDI_KTYPE  long
#   define  VODI_KTYPE  long
#   define  VSDI_KTYPE  long
#endif

#define     VDDF_KTYPE  double
#define     VQDF_KTYPE  double
#define     VODF_KTYPE  double
#define     VSDF_KTYPE  double


#define     VWYU_WIDTH  32
#define     VDYU_WIDTH  64
#define     VQYU_WIDTH  128
#define     VOYU_WIDTH  256
#define     VSYU_WIDTH  512

#define     VWBU_WIDTH  32
#define     VDBU_WIDTH  64
#define     VQBU_WIDTH  128
#define     VOBU_WIDTH  256
#define     VSBU_WIDTH  512

#define     VWBI_WIDTH  32
#define     VDBI_WIDTH  64
#define     VQBI_WIDTH  128
#define     VOBI_WIDTH  256
#define     VSBI_WIDTH  512

#define     VWBC_WIDTH  32
#define     VDBC_WIDTH  64
#define     VQBC_WIDTH  128
#define     VOBC_WIDTH  256
#define     VSBC_WIDTH  512

#define     VWHU_WIDTH  32
#define     VDHU_WIDTH  64
#define     VQHU_WIDTH  128
#define     VOHU_WIDTH  256
#define     VSHU_WIDTH  512

#define     VWHI_WIDTH  32
#define     VDHI_WIDTH  64
#define     VQHI_WIDTH  128
#define     VOHI_WIDTH  256
#define     VSHI_WIDTH  512

#define     VWHF_WIDTH  32
#define     VDHF_WIDTH  64
#define     VQHF_WIDTH  128
#define     VOHF_WIDTH  256
#define     VSHF_WIDTH  512

#define     VWWU_WIDTH  32
#define     VDWU_WIDTH  64
#define     VQWU_WIDTH  128
#define     VOWU_WIDTH  256
#define     VSWU_WIDTH  512

#define     VWWI_WIDTH  32
#define     VDWI_WIDTH  64
#define     VQWI_WIDTH  128
#define     VOWI_WIDTH  256
#define     VSWI_WIDTH  512

#define     VWWF_WIDTH  32
#define     VDWF_WIDTH  64
#define     VQWF_WIDTH  128
#define     VOWF_WIDTH  256
#define     VSWF_WIDTH  512

#define     VDDU_WIDTH  64
#define     VQDU_WIDTH  128
#define     VODU_WIDTH  256
#define     VSDU_WIDTH  512

#define     VDDI_WIDTH  64
#define     VDDF_WIDTH  64
#define     VODI_WIDTH  256
#define     VSDI_WIDTH  512

#define     VQDI_WIDTH  128
#define     VQDF_WIDTH  128
#define     VODF_WIDTH  256
#define     VSDF_WIDTH  512


#define     VWYU_NEL    32
#define     VDYU_NEL    64
#define     VQYU_NEL    128
#define     VOYU_NEL    256
#define     VSYU_NEL    512

#define     VWBU_NEL    4
#define     VDBU_NEL    8
#define     VQBU_NEL    16
#define     VOBU_NEL    32
#define     VSBU_NEL    64

#define     VWBI_NEL    4
#define     VDBI_NEL    8
#define     VQBI_NEL    16
#define     VOBI_NEL    32
#define     VSBI_NEL    64

#define     VWBC_NEL    4
#define     VDBC_NEL    8
#define     VQBC_NEL    16
#define     VOBC_NEL    32
#define     VSBC_NEL    64

#define     VWHU_NEL    2
#define     VDHU_NEL    4
#define     VQHU_NEL    8
#define     VOHU_NEL    16
#define     VSHU_NEL    32

#define     VWHI_NEL    2
#define     VDHI_NEL    4
#define     VQHI_NEL    8
#define     VOHI_NEL    16
#define     VSHI_NEL    32

#define     VWWU_NEL    1
#define     VDWU_NEL    2
#define     VQWU_NEL    4
#define     VOWU_NEL    8
#define     VSWU_NEL    16

#define     VWWI_NEL    1
#define     VDWI_NEL    2
#define     VQWI_NEL    4
#define     VOWI_NEL    8
#define     VSWI_NEL    16

#define     VWWF_NEL    1
#define     VDWF_NEL    2
#define     VQWF_NEL    4
#define     VOWF_NEL    8
#define     VSWF_NEL    16

#define     VDDU_NEL    1
#define     VQDU_NEL    2
#define     VODU_NEL    4
#define     VSDU_NEL    8

#define     VDDI_NEL    1
#define     VQDI_NEL    2
#define     VODI_NEL    4
#define     VSDI_NEL    8

#define     VDDF_NEL    1
#define     VQDF_NEL    2
#define     VODF_NEL    4
#define     VSDF_NEL    8


#if MY_VECTOR_ENDIAN == ENDIAN_BIG

//  Use with Vwh*, Vdw*, Vqd
#   define  V2_K0   (0x1)
#   define  V2_K1   (0x0)

//  Use with Vwb*, Vdh*, Vqw*, Vod*
#   define  V4_K0   (0x3)
#   define  V4_K1   (0x2)
#   define  V4_K2   (0x1)
#   define  V4_K3   (0x0)

//  Use with Vdb*, Vqh*, Vow*, Vsd*
#   define  V8_K0   (0x7)
#   define  V8_K1   (0x6)
#   define  V8_K2   (0x5)
#   define  V8_K3   (0x4)
#   define  V8_K4   (0x3)
#   define  V8_K5   (0x2)
#   define  V8_K6   (0x1)
#   define  V8_K7   (0x0)

//  Use with Vqb*, Voh*, Vsw*
#   define  V16_K0  (0xf)
#   define  V16_K1  (0xe)
#   define  V16_K2  (0xd)
#   define  V16_K3  (0xc)
#   define  V16_K4  (0xb)
#   define  V16_K5  (0xa)
#   define  V16_K6  (0x9)
#   define  V16_K7  (0x8)
#   define  V16_K8  (0x7)
#   define  V16_K9  (0x6)
#   define  V16_K10 (0x5)
#   define  V16_K11 (0x4)
#   define  V16_K12 (0x3)
#   define  V16_K13 (0x2)
#   define  V16_K14 (0x1)
#   define  V16_K15 (0x0)

//  Use with Vob*, Vsh*
#   define  V32_K0  (0x1f)
#   define  V32_K1  (0x1e)
#   define  V32_K2  (0x1d)
#   define  V32_K3  (0x1c)
#   define  V32_K4  (0x1b)
#   define  V32_K5  (0x1a)
#   define  V32_K6  (0x19)
#   define  V32_K7  (0x18)
#   define  V32_K8  (0x17)
#   define  V32_K9  (0x16)
#   define  V32_K10 (0x15)
#   define  V32_K11 (0x14)
#   define  V32_K12 (0x13)
#   define  V32_K13 (0x12)
#   define  V32_K14 (0x11)
#   define  V32_K15 (0x10)
#   define  V32_K16 (0x0f)
#   define  V32_K17 (0x0e)
#   define  V32_K18 (0x0d)
#   define  V32_K19 (0x0c)
#   define  V32_K20 (0x0b)
#   define  V32_K21 (0x0a)
#   define  V32_K22 (0x09)
#   define  V32_K23 (0x08)
#   define  V32_K24 (0x07)
#   define  V32_K25 (0x06)
#   define  V32_K26 (0x05)
#   define  V32_K27 (0x04)
#   define  V32_K28 (0x03)
#   define  V32_K29 (0x02)
#   define  V32_K30 (0x01)
#   define  V32_K31 (0x00)

//  Use with Vsh*
#   define  V64_K0  (0x3f)
#   define  V64_K1  (0x3e)
#   define  V64_K2  (0x3d)
#   define  V64_K3  (0x3c)
#   define  V64_K4  (0x3b)
#   define  V64_K5  (0x3a)
#   define  V64_K6  (0x39)
#   define  V64_K7  (0x38)
#   define  V64_K8  (0x37)
#   define  V64_K9  (0x36)
#   define  V64_K10 (0x35)
#   define  V64_K11 (0x34)
#   define  V64_K12 (0x33)
#   define  V64_K13 (0x32)
#   define  V64_K14 (0x31)
#   define  V64_K15 (0x30)
#   define  V64_K16 (0x2f)
#   define  V64_K17 (0x2e)
#   define  V64_K18 (0x2d)
#   define  V64_K19 (0x2c)
#   define  V64_K20 (0x2b)
#   define  V64_K21 (0x2a)
#   define  V64_K22 (0x29)
#   define  V64_K23 (0x28)
#   define  V64_K24 (0x27)
#   define  V64_K25 (0x26)
#   define  V64_K26 (0x25)
#   define  V64_K27 (0x24)
#   define  V64_K28 (0x23)
#   define  V64_K29 (0x22)
#   define  V64_K30 (0x21)
#   define  V64_K31 (0x20)
#   define  V64_K32 (0x1f)
#   define  V64_K33 (0x1e)
#   define  V64_K34 (0x1d)
#   define  V64_K35 (0x1c)
#   define  V64_K36 (0x1b)
#   define  V64_K37 (0x1a)
#   define  V64_K38 (0x19)
#   define  V64_K39 (0x18)
#   define  V64_K40 (0x17)
#   define  V64_K41 (0x16)
#   define  V64_K42 (0x15)
#   define  V64_K43 (0x14)
#   define  V64_K44 (0x13)
#   define  V64_K45 (0x12)
#   define  V64_K46 (0x11)
#   define  V64_K47 (0x10)
#   define  V64_K48 (0x0f)
#   define  V64_K49 (0x0e)
#   define  V64_K50 (0x0d)
#   define  V64_K51 (0x0c)
#   define  V64_K52 (0x0b)
#   define  V64_K53 (0x0a)
#   define  V64_K54 (0x09)
#   define  V64_K55 (0x08)
#   define  V64_K56 (0x07)
#   define  V64_K57 (0x06)
#   define  V64_K58 (0x05)
#   define  V64_K59 (0x04)
#   define  V64_K60 (0x03)
#   define  V64_K61 (0x02)
#   define  V64_K62 (0x01)
#   define  V64_K63 (0x00)

#elif MY_VECTOR_ENDIAN == ENDIAN_LIL

#   define  V2_K0   (0x0)
#   define  V2_K1   (0x1)

#   define  V4_K0   (0x0)
#   define  V4_K1   (0x1)
#   define  V4_K2   (0x2)
#   define  V4_K3   (0x3)

#   define  V8_K0   (0x0)
#   define  V8_K1   (0x1)
#   define  V8_K2   (0x2)
#   define  V8_K3   (0x3)
#   define  V8_K4   (0x4)
#   define  V8_K5   (0x5)
#   define  V8_K6   (0x6)
#   define  V8_K7   (0x7)

#   define  V16_K0  (0x00)
#   define  V16_K1  (0x01)
#   define  V16_K2  (0x02)
#   define  V16_K3  (0x03)
#   define  V16_K4  (0x04)
#   define  V16_K5  (0x05)
#   define  V16_K6  (0x06)
#   define  V16_K7  (0x07)
#   define  V16_K8  (0x08)
#   define  V16_K9  (0x09)
#   define  V16_K10 (0x0a)
#   define  V16_K11 (0x0b)
#   define  V16_K12 (0x0c)
#   define  V16_K13 (0x0d)
#   define  V16_K14 (0x0e)
#   define  V16_K15 (0x0f)

#   define  V32_K0  (0x00)
#   define  V32_K1  (0x01)
#   define  V32_K2  (0x02)
#   define  V32_K3  (0x03)
#   define  V32_K4  (0x04)
#   define  V32_K5  (0x05)
#   define  V32_K6  (0x06)
#   define  V32_K7  (0x07)
#   define  V32_K8  (0x08)
#   define  V32_K9  (0x09)
#   define  V32_K10 (0x0a)
#   define  V32_K11 (0x0b)
#   define  V32_K12 (0x0c)
#   define  V32_K13 (0x0d)
#   define  V32_K14 (0x0e)
#   define  V32_K15 (0x0f)
#   define  V32_K16 (0x10)
#   define  V32_K17 (0x11)
#   define  V32_K18 (0x12)
#   define  V32_K19 (0x13)
#   define  V32_K20 (0x14)
#   define  V32_K21 (0x15)
#   define  V32_K22 (0x16)
#   define  V32_K23 (0x17)
#   define  V32_K24 (0x18)
#   define  V32_K25 (0x19)
#   define  V32_K26 (0x1a)
#   define  V32_K27 (0x1b)
#   define  V32_K28 (0x1c)
#   define  V32_K29 (0x1d)
#   define  V32_K30 (0x1e)
#   define  V32_K31 (0x1f)

#   define  V64_K0  (0x00)
#   define  V64_K1  (0x01)
#   define  V64_K2  (0x02)
#   define  V64_K3  (0x03)
#   define  V64_K4  (0x04)
#   define  V64_K5  (0x05)
#   define  V64_K6  (0x06)
#   define  V64_K7  (0x07)
#   define  V64_K8  (0x08)
#   define  V64_K9  (0x09)
#   define  V64_K10 (0x0a)
#   define  V64_K11 (0x0b)
#   define  V64_K12 (0x0c)
#   define  V64_K13 (0x0d)
#   define  V64_K14 (0x0e)
#   define  V64_K15 (0x0f)
#   define  V64_K16 (0x10)
#   define  V64_K17 (0x11)
#   define  V64_K18 (0x12)
#   define  V64_K19 (0x13)
#   define  V64_K20 (0x14)
#   define  V64_K21 (0x15)
#   define  V64_K22 (0x16)
#   define  V64_K23 (0x17)
#   define  V64_K24 (0x18)
#   define  V64_K25 (0x19)
#   define  V64_K26 (0x1a)
#   define  V64_K27 (0x1b)
#   define  V64_K28 (0x1c)
#   define  V64_K29 (0x1d)
#   define  V64_K30 (0x1e)
#   define  V64_K31 (0x1f)
#   define  V64_K32 (0x20)
#   define  V64_K33 (0x21)
#   define  V64_K34 (0x22)
#   define  V64_K35 (0x23)
#   define  V64_K36 (0x24)
#   define  V64_K37 (0x25)
#   define  V64_K38 (0x26)
#   define  V64_K39 (0x27)
#   define  V64_K40 (0x28)
#   define  V64_K41 (0x29)
#   define  V64_K42 (0x2a)
#   define  V64_K43 (0x2b)
#   define  V64_K44 (0x2c)
#   define  V64_K45 (0x2d)
#   define  V64_K46 (0x2e)
#   define  V64_K47 (0x2f)
#   define  V64_K48 (0x30)
#   define  V64_K49 (0x31)
#   define  V64_K50 (0x32)
#   define  V64_K51 (0x33)
#   define  V64_K52 (0x34)
#   define  V64_K53 (0x35)
#   define  V64_K54 (0x36)
#   define  V64_K55 (0x37)
#   define  V64_K56 (0x38)
#   define  V64_K57 (0x39)
#   define  V64_K58 (0x3a)
#   define  V64_K59 (0x3b)
#   define  V64_K60 (0x3c)
#   define  V64_K61 (0x3d)
#   define  V64_K62 (0x3e)
#   define  V64_K63 (0x3f)
#else
#   error "why !(MY_ENDIAN==ENDIAN_LIL || MY_ENDIAN==ENDIAN_BIG)?"
#endif

#if _LEAVE_EXTVEC_VLANES
}
#endif

#if _ENTER_EXTVEC_VSN
{
#endif

#define VWYU_SN(_)  _##wyu
#define VDYU_SN(_)  _##dyu
#define VQYU_SN(_)  _##qyu
#define VOYU_SN(_)  _##oyu
#define VSYU_SN(_)  _##syu

#define VWBU_SN(_)  _##wbu
#define VWBI_SN(_)  _##wbi
#define VWHU_SN(_)  _##whu
#define VWHI_SN(_)  _##whi
#define VWHF_SN(_)  _##whf
#define VWWU_SN(_)  _##wwu
#define VWWI_SN(_)  _##wwi
#define VWWF_SN(_)  _##wwf

#define VDBU_SN(_)  _##dbu
#define VDBI_SN(_)  _##dbi
#define VDHU_SN(_)  _##dhu
#define VDHI_SN(_)  _##dhi
#define VDHF_SN(_)  _##dhf
#define VDWU_SN(_)  _##dwu
#define VDWI_SN(_)  _##dwi
#define VDWF_SN(_)  _##dwf
#define VDDU_SN(_)  _##ddu
#define VDDI_SN(_)  _##ddi
#define VDDF_SN(_)  _##ddf

#define VQBU_SN(_)  _##qbu
#define VQBI_SN(_)  _##qbi
#define VQHU_SN(_)  _##qhu
#define VQHI_SN(_)  _##qhi
#define VQHF_SN(_)  _##qhf
#define VQWU_SN(_)  _##qwu
#define VQWI_SN(_)  _##qwi
#define VQWF_SN(_)  _##qwf
#define VQDU_SN(_)  _##qdu
#define VQDI_SN(_)  _##qdi
#define VQDF_SN(_)  _##qdf

#define VOBU_SN(_)  _##obu
#define VOBI_SN(_)  _##obi
#define VOHU_SN(_)  _##ohu
#define VOHI_SN(_)  _##ohi
#define VOHF_SN(_)  _##ohf
#define VOWU_SN(_)  _##owu
#define VOWI_SN(_)  _##owi
#define VOWF_SN(_)  _##owf
#define VODU_SN(_)  _##odu
#define VODI_SN(_)  _##odi
#define VODF_SN(_)  _##odf

#define VSBU_SN(_)  _##sbu
#define VSBI_SN(_)  _##sbi
#define VSHU_SN(_)  _##shu
#define VSHI_SN(_)  _##shi
#define VSHF_SN(_)  _##shf
#define VSWU_SN(_)  _##swu
#define VSWI_SN(_)  _##swi
#define VSWF_SN(_)  _##swf
#define VSDU_SN(_)  _##sdu
#define VSDI_SN(_)  _##sdi
#define VSDF_SN(_)  _##sdf

#if _LEAVE_EXTVEC_VSN
}
#endif

#if _ENTER_EXTVEC_X86_SIMD
{
#endif

#ifdef  SPC_X86_AVX512F

#ifndef SPC_X86_SSE2
#error "why is SPC_X86_AVX512F defined but SPC_X86_SSE2 ain't?"
#endif

#define     VOYU_REPR   REPR_VOYU
#define     VOYU_MTYPE  __m256i
#define     VOYU_TYPE   __m256i

#define     VOBU_REPR   (REPR_VOBU|REPR_M1)
#define     VOBU_MTYPE  __m256i
#define     VOBU_TYPE   struct Obu1

#define     VOBI_REPR   (REPR_VOBI|REPR_M1)
#define     VOBI_MTYPE  __m256i
#define     VOBI_TYPE   struct Obi1

#if CHAR_SIGNEDNESS
#   define  VOBC_REPR   VOBI_REPR
#   define  VOBC_TYPE   struct Obi1
#else
#   define  VOBC_REPR   VOBU_REPR
#   define  VOBC_TYPE   struct Obu1
#endif

#define     VOHU_REPR   (REPR_VOHU|REPR_M1)
#define     VOHU_MTYPE  __m256i
#define     VOHU_TYPE   struct Ohu1

#define     VOHI_REPR   (REPR_VOHI|REPR_M1)
#define     VOHI_MTYPE  __m256i
#define     VOHI_TYPE   struct Ohi1


#define     VOWU_REPR   (REPR_VOWU|REPR_M1)
#define     VOWU_MTYPE  __m256i
#define     VOWU_TYPE   struct Owu1

#define     VOWI_REPR   (REPR_VOWI|REPR_M1)
#define     VOWI_MTYPE  __m256i
#define     VOWI_TYPE   struct Owi1

#define     VOWF_REPR   REPR_VOWF
#define     VOWF_MTYPE  __m256
#define     VOWF_TYPE   __m256


#define     VODU_REPR   (REPR_VODU|REPR_M1)
#define     VODU_MTYPE  __m256i
#define     VODU_TYPE   struct Odu1

#define     VODI_REPR   (REPR_VODI|REPR_M1)
#define     VODI_MTYPE  __m256i
#define     VODI_TYPE   struct Odi1

#define     VODF_REPR   REPR_VODF
#define     VODF_MTYPE  __m256d
#define     VODF_TYPE   __m256d


#define     VSYU_REPR   REPR_VSYU
#define     VSYU_MTYPE  __m512i
#define     VSYU_TYPE   __m512i

#define     VSBU_REPR   (REPR_VSBU|REPR_M1)
#define     VSBU_MTYPE  __m512i
#define     VSBU_TYPE   struct Sbu1

#define     VSBI_REPR   (REPR_VSBI|REPR_M1)
#define     VSBI_MTYPE  __m512i
#define     VSBI_TYPE   struct Sbi1

#if CHAR_SIGNEDNESS
#   define  VSBC_REPR   VSBI_REPR
#   define  VSBC_TYPE   struct Sbi1
#else
#   define  VSBC_REPR   VSBU_REPR
#   define  VSBC_TYPE   struct Sbu1
#endif


#define     VSHU_REPR   (REPR_VSHU|REPR_M1)
#define     VSHU_MTYPE  __m512i
#define     VSHU_TYPE   struct Shu1

#define     VSHI_REPR   (REPR_VSHI|REPR_M1)
#define     VSHI_MTYPE  __m512i
#define     VSHI_TYPE   struct Shi1


#define     VSWU_REPR   (REPR_VSWU|REPR_M1)
#define     VSWU_MTYPE  __m512i
#define     VSWU_TYPE   struct Swu1

#define     VSWI_REPR   (REPR_VSWI|REPR_M1)
#define     VSWI_MTYPE  __m512i
#define     VSWI_TYPE   struct Swi1

#define     VSWF_REPR   REPR_VSWF
#define     VSWF_MTYPE  __m512
#define     VSWF_TYPE   __m512


#define     VSDU_REPR   (REPR_VSDU|REPR_M1)
#define     VSDU_MTYPE  __m512i
#define     VSDU_TYPE   struct Sdu1

#define     VSDI_REPR   (REPR_VSDI|REPR_M1)
#define     VSDI_MTYPE  __m512i
#define     VSDI_TYPE   struct Sdi1

#define     VSDF_REPR   REPR_VSDF
#define     VSDF_MTYPE  __m512d
#define     VSDF_TYPE   __m512d

#if defined(SPC_X86_AVX512FP16)
#   define  VQHF_REPR   REPR_VQHF
#   define  VQHF_MTYPE  __m128h
#   define  VQHF_TYPE   __m128h

#   define  VOHF_REPR   REPR_VOHF
#   define  VOHF_MTYPE  __m256h
#   define  VOHF_TYPE   __m256h

#   define  VSHF_REPR   REPR_VSHF
#   define  VSHF_MTYPE  __m512h
#   define  VSHF_TYPE   __m512h
#else
#   define  VQHF_REPR   (REPR_VQHU|REPR_M1)
#   define  VQHF_MTYPE  __m128i
#   define  VQHF_TYPE   struct Qhf1

#   define  VOHF_REPR   (REPR_VOHU|REPR_M1)
#   define  VOHF_MTYPE  __m256i
#   define  VOHF_TYPE   struct Ohf1

#   define  VSHF_REPR   (REPR_VOHU|REPR_M1)
#   define  VSHF_MTYPE  __m512i
#   define  VSHF_TYPE   struct Shf1
#endif

#endif

#if defined(SPC_X86_SSE2)

#   ifndef MY_IMMINTRIN_H
#   define MY_IMMINTRIN_H
#   include <immintrin.h>
#   endif

#   define  VWYU_REPR   REPR_WF1
#   define  VWYU_MTYPE  float
#   define  VWYU_TYPE   struct Wyu1

#   define  VWBU_REPR   REPR_WF1
#   define  VWBU_MTYPE  float
#   define  VWBU_TYPE   struct Wbu1

#   define  VWBI_REPR   REPR_WF1
#   define  VWBI_MTYPE  float
#   define  VWBI_TYPE   struct Wbi1

#   define  VWBC_MTYPE  float
#if CHAR_SIGNEDNESS
#   define  VWBC_REPR   REPR_VWBI
#   define  VWBC_TYPE   struct Wbi1
#else
#   define  VWBC_REPR   REPR_VWBU
#   define  VWBC_TYPE   struct Wbu1
#endif

#   define  VWHU_REPR   REPR_WF1
#   define  VWHU_MTYPE  float
#   define  VWHU_TYPE   struct Whu1

#   define  VWHI_REPR   REPR_WF1
#   define  VWHI_MTYPE  float
#   define  VWHI_TYPE   struct Whi1

#   define  VWHF_REPR   REPR_WF1
#   define  VWHF_MTYPE  float
#   define  VWHF_TYPE   struct Whf1


#   define  VWWU_REPR   REPR_WF1
#   define  VWWU_MTYPE  float
#   define  VWWU_TYPE   struct Wwu1

#   define  VWWI_REPR   REPR_WF1
#   define  VWWI_MTYPE  float
#   define  VWWI_TYPE   struct Wwi1

#   define  VWWF_REPR   REPR_WF1
#   define  VWWF_MTYPE  float
#   define  VWWF_TYPE   struct Wwf1


#   define  VDYU_REPR   REPR_DF1
#   define  VDYU_MTYPE  double
#   define  VDYU_TYPE   struct Dyu1

#   define  VDBU_REPR   REPR_DF1
#   define  VDBU_MTYPE  double
#   define  VDBU_TYPE   struct Dbu1

#   define  VDBI_REPR   REPR_DF1
#   define  VDBI_MTYPE  double
#   define  VDBI_TYPE   struct Dbi1

#   define  VDBC_MTYPE  double
#if CHAR_SIGNEDNESS
#   define  VDBC_REPR   REPR_VDBI
#   define  VDBC_TYPE   struct Dbi1
#else
#   define  VDBC_REPR   REPR_VDBU
#   define  VDBC_TYPE   struct Dbu1
#endif

#   define  VDHU_REPR   REPR_DF1
#   define  VDHU_MTYPE  double
#   define  VDHU_TYPE   struct Dhu1

#   define  VDHI_REPR   REPR_DF1
#   define  VDHI_MTYPE  double
#   define  VDHI_TYPE   struct Dhi1

#   define  VDHF_REPR   REPR_DF1
#   define  VDHF_MTYPE  double
#   define  VDHF_TYPE   struct Dhf1


#   define  VDWU_REPR   REPR_DF1
#   define  VDWU_MTYPE  double
#   define  VDWU_TYPE   struct Dwu1

#   define  VDWI_REPR   REPR_DF1
#   define  VDWI_MTYPE  double
#   define  VDWI_TYPE   struct Dwi1

#   define  VDWF_REPR   REPR_DF1
#   define  VDWF_MTYPE  double
#   define  VDWF_TYPE   struct Dwf1


#   define  VDDU_REPR   REPR_DF1
#   define  VDDU_MTYPE  double
#   define  VDDU_TYPE   struct Ddu1

#   define  VDDI_REPR   REPR_DF1
#   define  VDDI_MTYPE  double
#   define  VDDI_TYPE   struct Ddi1

#   define  VDDF_REPR   REPR_DF1
#   define  VDDF_MTYPE  double
#   define  VDDF_TYPE   struct Ddf1


#   define  VQYU_REPR   REPR_VQYU
#   define  VQYU_MTYPE  __m128i
#   define  VQYU_TYPE   __m128i

#   define  VQBU_REPR   (REPR_VQBU|REPR_M1)
#   define  VQBU_MTYPE  __m128i
#   define  VQBU_TYPE   struct Qbu1

#   define  VQBI_REPR   (REPR_VQBI|REPR_M1)
#   define  VQBI_MTYPE  __m128i
#   define  VQBI_TYPE   struct Qbi1

#   define  VQBC_MTYPE  __m128i
#if CHAR_SIGNEDNESS
#   define  VQBC_REPR   REPR_VQBI
#   define  VQBC_TYPE   struct Qbi1
#else
#   define  VQBC_REPR   REPR_VQBU
#   define  VQBC_TYPE   struct Qbu1
#endif


#   define  VQHU_REPR   (REPR_VQHU|REPR_M1)
#   define  VQHU_MTYPE  __m128i
#   define  VQHU_TYPE   struct Qhu1

#   define  VQHI_REPR   (REPR_VQHI|REPR_M1)
#   define  VQHI_MTYPE  __m128i
#   define  VQHI_TYPE   struct Qhi1

#   ifndef  SPC_X86_AVX512F
#   define  VQHF_REPR   (REPR_VQHU|REPR_M1)
#   define  VQHF_MTYPE  __m128i
#   define  VQHF_TYPE   struct Qhf1
#   endif


#   define  VQWU_REPR   (REPR_VQWU|REPR_M1)
#   define  VQWU_MTYPE  __m128i
#   define  VQWU_TYPE   struct Qwu1

#   define  VQWI_REPR   (REPR_VQWI|REPR_M1)
#   define  VQWI_MTYPE  __m128i
#   define  VQWI_TYPE   struct Qwi1

#   define  VQWF_REPR   REPR_VQWF
#   define  VQWF_MTYPE  __m128
#   define  VQWF_TYPE   __m128


#   define  VQDU_REPR   (REPR_VQDU|REPR_M1)
#   define  VQDU_MTYPE  __m128i
#   define  VQDU_TYPE   struct Qdu1

#   define  VQDI_REPR   (REPR_VQDI|REPR_M1)
#   define  VQDI_MTYPE  __m128i
#   define  VQDI_TYPE   struct Qdi1

#   define  VQDF_REPR   REPR_VQDF
#   define  VQDF_MTYPE  __m128d
#   define  VQDF_TYPE   __m128d

#   ifndef  SPC_X86_AVX512F

#   define  VOYU_REPR   (REPR_VQYU|REPR_M2)
#   define  VOYU_TYPE   struct Qyu2

#   define  VOBU_REPR   (REPR_VQBU|REPR_M2)
#   define  VOBU_TYPE   struct Qbu2

#   define  VOBI_REPR   (REPR_VQBI|REPR_M2)
#   define  VOBI_TYPE   struct Qbi2

#if CHAR_SIGNEDNESS
#   define  VOBC_REPR   REPR_VOBI
#   define  VOBC_TYPE   struct Qbi2
#else
#   define  VOBC_REPR   REPR_VOBU
#   define  VOBC_TYPE   struct Qbu2
#endif


#   define  VOHU_REPR   (REPR_VQHU|REPR_M2)
#   define  VOHU_TYPE   struct Qhu2

#   define  VOHI_REPR   (REPR_VQHI|REPR_M2)
#   define  VOHI_TYPE   struct Qhi2

#   define  VOHF_REPR   (REPR_VQHU|REPR_M2)
#   define  VOHF_TYPE   struct Qhf2


#   define  VOWU_REPR   (REPR_VQWU|REPR_M2)
#   define  VOWU_TYPE   struct Qwu2

#   define  VOWI_REPR   (REPR_VQWI|REPR_M2)
#   define  VOWI_TYPE   struct Qwi2

#   define  VOWF_REPR   (REPR_VQWF|REPR_M2)
#   define  VOWF_TYPE   struct Qwf2


#   define  VODU_REPR   (REPR_VQDU|REPR_M2)
#   define  VODU_TYPE   struct Qdu2

#   define  VODI_REPR   (REPR_VQDI|REPR_M2)
#   define  VODI_TYPE   struct Qdi2

#   define  VODF_REPR   (REPR_VQDF|REPR_M2)
#   define  VODF_TYPE   struct Qdf2


#   define  VSYU_REPR   (REPR_VQYU|REPR_M4)
#   define  VSYU_TYPE   struct Qyu4

#   define  VSBU_REPR   (REPR_VQBU|REPR_M4)
#   define  VSBU_TYPE   struct Qbu4

#   define  VSBI_REPR   (REPR_VQBI|REPR_M4)
#   define  VSBI_TYPE   struct Qbi4


#if CHAR_SIGNEDNESS
#   define  VSBC_REPR   REPR_VSBI
#   define  VSBC_TYPE   struct Qbi4
#else
#   define  VSBC_REPR   REPR_VSBU
#   define  VSBC_TYPE   struct Qbu4
#endif

#   define  VSHU_REPR   (REPR_VQHU|REPR_M4)
#   define  VSHU_TYPE   struct Qhu4

#   define  VSHI_REPR   (REPR_VQHI|REPR_M4)
#   define  VSHI_TYPE   struct Qhi4

#   define  VSHF_REPR   (REPR_VQHU|REPR_M4)
#   define  VSHF_TYPE   struct Qhf4


#   define  VSWU_REPR   (REPR_VQWU|REPR_M4)
#   define  VSWU_TYPE   struct Qwu4

#   define  VSWI_REPR   (REPR_VQWI|REPR_M4)
#   define  VSWI_TYPE   struct Qwi4

#   define  VSWF_REPR   (REPR_VQWF|REPR_M4)
#   define  VSWF_TYPE   struct Qwf4


#   define  VSDU_REPR   (REPR_VQDU|REPR_M4)
#   define  VSDU_TYPE   struct Qdu4

#   define  VSDI_REPR   (REPR_VQDI|REPR_M4)
#   define  VSDI_TYPE   struct Qdi4

#   define  VSDF_REPR   (REPR_VQDF|REPR_M4)
#   define  VSDF_TYPE   struct Qdf4

#   endif

#endif


#if _LEAVE_EXTVEC_X86_SIMD
}
#endif

#if _ENTER_EXTVEC_ARM_SIMD
{
#endif

#if defined(SPC_ARM_NEON)

/*  A clang/LLVM compiler is required for arm targets, at
    least until Microsoft implements the ACLE.
*/
#   ifndef  MY_ARM_NEON_H
#   define  MY_ARM_NEON_H
#   include   <arm_neon.h>
#   endif

#   define  VWYU_REPR       REPR_WF1
#   define  VWYU_MTYPE      float
#   define  VWYU_TYPE       struct Wyu1

#   define  VWBU_REPR       REPR_WF1
#   define  VWBU_MTYPE      float
#   define  VWBU_TYPE       struct Wbu1

#   define  VWBI_REPR       REPR_WF1
#   define  VWBI_MTYPE      float
#   define  VWBI_TYPE       struct Wbi1

#if CHAR_SIGNEDNESS
#   define  VWBC_REPR       REPR_VWBI
#   define  VWBC_MTYPE      float
#   define  VWBC_TYPE       struct Wbi1
#else
#   define  VWBC_REPR       REPR_VWBU
#   define  VWBC_MTYPE      float
#   define  VWBC_TYPE       struct Wbu1
#endif

#   define  VWHU_REPR       REPR_WF1
#   define  VWHU_MTYPE      float
#   define  VWHU_TYPE       struct Whu1

#   define  VWHI_REPR       REPR_WF1
#   define  VWHI_MTYPE      float
#   define  VWHI_TYPE       struct Whi1

#   define  VWHF_REPR       REPR_WF1
#   define  VWHF_MTYPE      float
#   define  VWHF_TYPE       struct Whf1


#   define  VWWU_REPR       REPR_WF1
#   define  VWWU_MTYPE      float
#   define  VWWU_TYPE       struct Wwu1

#   define  VWWI_REPR       REPR_WF1
#   define  VWWI_MTYPE      float
#   define  VWWI_TYPE       struct Wwi1

#   define  VWWF_REPR       REPR_WF1
#   define  VWWF_MTYPE      float
#   define  VWWF_TYPE       struct Wwf1


#   define  VDYU_REPR       (REPR_VDDU|REPR_M1)
#   define  VDYU_MTYPE      uint64x1_t
#   define  VDYU_TYPE       struct Dyu1
#   define  VDYU_M2TYPE     uint64x1x2_t
#   define  VDYU_M3TYPE     uint64x1x3_t
#   define  VDYU_M4TYPE     uint64x1x4_t

#   define  VDBU_REPR       REPR_VDBU
#   define  VDBU_TYPE       uint8x8_t
#   define  VDBU_MTYPE      uint8x8_t
#   define  VDBU_M2TYPE     uint8x8x2_t
#   define  VDBU_M3TYPE     uint8x8x3_t
#   define  VDBU_M4TYPE     uint8x8x4_t

#   define  VDBI_REPR       REPR_VDBI
#   define  VDBI_TYPE       int8x8_t
#   define  VDBI_MTYPE      int8x8_t
#   define  VDBI_M2TYPE     int8x8x2_t
#   define  VDBI_M3TYPE     int8x8x3_t
#   define  VDBI_M4TYPE     int8x8x4_t

#if CHAR_SIGNEDNESS

#   define  VDBC_REPR       REPR_VDBI
#   define  VDBC_TYPE       struct Dbi1
#   define  VDBC_MTYPE      int8x8_t
#   define  VDBC_M2TYPE     int8x8x2_t
#   define  VDBC_M3TYPE     int8x8x3_t
#   define  VDBC_M4TYPE     int8x8x4_t
#else
#   define  VDBC_REPR       REPR_VDBU
#   define  VDBC_TYPE       struct Dbu1
#   define  VDBC_MTYPE      uint8x8_t
#   define  VDBC_M2TYPE     uint8x8x2_t
#   define  VDBC_M3TYPE     uint8x8x3_t
#   define  VDBC_M4TYPE     uint8x8x4_t
#endif

#   define  VDHU_REPR       REPR_VDHU
#   define  VDHU_TYPE       uint16x4_t
#   define  VDHU_MTYPE      uint16x4_t
#   define  VDHU_M2TYPE     uint16x4x2_t
#   define  VDHU_M3TYPE     uint16x4x3_t
#   define  VDHU_M4TYPE     uint16x4x4_t

#   define  VDHI_REPR       REPR_VDHI
#   define  VDHI_TYPE       int16x4_t
#   define  VDHI_MTYPE      int16x4_t
#   define  VDHI_M2TYPE     int16x4x2_t
#   define  VDHI_M3TYPE     int16x4x3_t
#   define  VDHI_M4TYPE     int16x4x4_t

#   define  VDHF_REPR       REPR_VDHF
#   define  VDHF_TYPE       float16x4_t
#   define  VDHF_MTYPE      float16x4_t
#   define  VDHF_M2TYPE     float16x4x2_t
#   define  VDHF_M3TYPE     float16x4x3_t
#   define  VDHF_M4TYPE     float16x4x4_t


#   define  VDWU_REPR       REPR_VDWU
#   define  VDWU_TYPE       uint32x2_t
#   define  VDWU_MTYPE      uint32x2_t
#   define  VDWU_M2TYPE     uint32x2x2_t
#   define  VDWU_M3TYPE     uint32x2x3_t
#   define  VDWU_M4TYPE     uint32x2x4_t

#   define  VDWI_REPR       REPR_VDWI
#   define  VDWI_TYPE       int32x2_t
#   define  VDWI_MTYPE      int32x2_t
#   define  VDWI_M2TYPE     int32x2x2_t
#   define  VDWI_M3TYPE     int32x2x3_t
#   define  VDWI_M4TYPE     int32x2x4_t

#   define  VDWF_REPR       REPR_VDWF
#   define  VDWF_TYPE       float32x2_t
#   define  VDWF_MTYPE      float32x2_t
#   define  VDWF_M2TYPE     float32x2x2_t
#   define  VDWF_M3TYPE     float32x2x3_t
#   define  VDWF_M4TYPE     float32x2x4_t

#   define  VDDU_REPR       REPR_VDDU
#   define  VDDU_TYPE       uint64x1_t
#   define  VDDU_MTYPE      uint64x1_t
#   define  VDDU_M2TYPE     uint64x1x2_t
#   define  VDDU_M3TYPE     uint64x1x3_t
#   define  VDDU_M4TYPE     uint64x1x4_t

#   define  VDDI_REPR       REPR_VDDI
#   define  VDDI_TYPE       int64x1_t
#   define  VDDI_MTYPE      int64x1_t
#   define  VDDI_M2TYPE     int64x1x2_t
#   define  VDDI_M3TYPE     int64x1x3_t
#   define  VDDI_M4TYPE     int64x1x4_t

#   define  VDDF_REPR       REPR_VDDF
#   define  VDDF_TYPE       float64x1_t
#   define  VDDF_MTYPE      float64x1_t
#   define  VDDF_M2TYPE     float64x1x2_t
#   define  VDDF_M3TYPE     float64x1x3_t
#   define  VDDF_M4TYPE     float64x1x4_t

#   define  VQYU_REPR       REPR_VQDU
#   define  VQYU_TYPE       struct Qyu1
#   define  VQYU_MTYPE      uint64x2_t
#   define  VQYU_M2TYPE     uint64x2x2_t
#   define  VQYU_M3TYPE     uint64x2x3_t
#   define  VQYU_M4TYPE     uint64x2x4_t

#   define  VQBU_REPR       REPR_VQBU
#   define  VQBU_TYPE       uint8x16_t
#   define  VQBU_MTYPE      uint8x16_t
#   define  VQBU_M2TYPE     uint8x16x2_t
#   define  VQBU_M3TYPE     uint8x16x3_t
#   define  VQBU_M4TYPE     uint8x16x4_t

#   define  VQBI_REPR       REPR_VQBI
#   define  VQBI_TYPE       int8x16_t
#   define  VQBI_MTYPE      int8x16_t
#   define  VQBI_M2TYPE     int8x16x2_t
#   define  VQBI_M3TYPE     int8x16x3_t
#   define  VQBI_M4TYPE     int8x16x4_t

#if CHAR_SIGNEDNESS
#   define  VQBC_REPR       REPR_VQBI
#   define  VQBC_TYPE       struct Qbi1
#   define  VQBC_MTYPE      int8x16_t
#   define  VQBC_M2TYPE     int8x16x2_t
#   define  VQBC_M3TYPE     int8x16x3_t
#   define  VQBC_M4TYPE     int8x16x4_t
#else
#   define  VQBC_REPR       REPR_VQBU
#   define  VQBC_TYPE       struct Qbu1
#   define  VQBC_MTYPE      uint8x16_t
#   define  VQBC_M2TYPE     uint8x16x2_t
#   define  VQBC_M3TYPE     uint8x16x3_t
#   define  VQBC_M4TYPE     uint8x16x4_t
#endif

#   define  VQHU_REPR       REPR_VQHU
#   define  VQHU_TYPE       uint16x8_t
#   define  VQHU_MTYPE      uint16x8_t
#   define  VQHU_M2TYPE     uint16x8x2_t
#   define  VQHU_M3TYPE     uint16x8x3_t
#   define  VQHU_M4TYPE     uint16x8x4_t

#   define  VQHI_REPR       REPR_VQHI
#   define  VQHI_TYPE       int16x8_t
#   define  VQHI_MTYPE      int16x8_t
#   define  VQHI_M2TYPE     int16x8x2_t
#   define  VQHI_M3TYPE     int16x8x3_t
#   define  VQHI_M4TYPE     int16x8x4_t

#   define  VQHF_REPR       REPR_VQHF
#   define  VQHF_TYPE       float16x8_t
#   define  VQHF_MTYPE      float16x8_t
#   define  VQHF_M2TYPE     float16x8x2_t
#   define  VQHF_M3TYPE     float16x8x3_t
#   define  VQHF_M4TYPE     float16x8x4_t

#   define  VQWU_REPR       REPR_VQWU
#   define  VQWU_TYPE       uint32x4_t
#   define  VQWU_MTYPE      uint32x4_t
#   define  VQWU_M2TYPE     uint32x4x2_t
#   define  VQWU_M3TYPE     uint32x4x3_t
#   define  VQWU_M4TYPE     uint32x4x4_t

#   define  VQWI_REPR       REPR_VQWI
#   define  VQWI_TYPE       int32x4_t
#   define  VQWI_MTYPE      int32x4_t
#   define  VQWI_M2TYPE     int32x4x2_t
#   define  VQWI_M3TYPE     int32x4x3_t
#   define  VQWI_M4TYPE     int32x4x4_t

#   define  VQWF_REPR       REPR_VQWF
#   define  VQWF_TYPE       float32x4_t
#   define  VQWF_MTYPE      float32x4_t
#   define  VQWF_M2TYPE     float32x4x2_t
#   define  VQWF_M3TYPE     float32x4x3_t
#   define  VQWF_M4TYPE     float32x4x4_t

#   define  VQDU_REPR       REPR_VQDU
#   define  VQDU_TYPE       uint64x2_t
#   define  VQDU_MTYPE      uint64x2_t
#   define  VQDU_M2TYPE     uint64x2x2_t
#   define  VQDU_M3TYPE     uint64x2x3_t
#   define  VQDU_M4TYPE     uint64x2x4_t

#   define  VQDI_REPR       REPR_VQDI
#   define  VQDI_TYPE       int64x2_t
#   define  VQDI_MTYPE      int64x2_t
#   define  VQDI_M2TYPE     int64x2x2_t
#   define  VQDI_M3TYPE     int64x2x3_t
#   define  VQDI_M4TYPE     int64x2x4_t

#   define  VQDF_REPR       REPR_VQDF
#   define  VQDF_TYPE       float64x2_t
#   define  VQDF_MTYPE      float64x2_t
#   define  VQDF_M2TYPE     float64x2x2_t
#   define  VQDF_M3TYPE     float64x2x3_t
#   define  VQDF_M4TYPE     float64x2x4_t

#   define  VOYU_REPR       (REPR_VQYU|REPR_M2)
#   define  VOYU_TYPE       struct Qyu2

#   define  VOBU_REPR       (REPR_VQBU|REPR_M2)
#   define  VOBU_TYPE       struct Qbu2

#   define  VOBI_REPR       (REPR_VQBI|REPR_M2)
#   define  VOBI_TYPE       struct Qbi2

#if CHAR_SIGNEDNESS
#   define  VOBC_REPR       VOBI_REPR
#   define  VOBC_TYPE       struct Qbi2
#else
#   define  VOBC_REPR       VOBU_REPR
#   define  VOBC_TYPE       struct Qbu2
#endif

#   define  VOHU_REPR       (REPR_VQHU|REPR_M2)
#   define  VOHU_TYPE       struct Qhu2

#   define  VOHI_REPR       (REPR_VQHI|REPR_M2)
#   define  VOHI_TYPE       struct Qhi2

#   define  VOHF_REPR       (REPR_VQHF|REPR_M2)
#   define  VOHF_TYPE       struct Qhf2

#   define  VOWU_REPR       (REPR_VQWU|REPR_M2)
#   define  VOWU_TYPE       struct Qwu2

#   define  VOWI_REPR       (REPR_VQWI|REPR_M2)
#   define  VOWI_TYPE       struct Qwi2

#   define  VOWF_REPR       (REPR_VQWF|REPR_M2)
#   define  VOWF_TYPE       struct Qwf2

#   define  VODU_REPR       (REPR_VQDU|REPR_M2)
#   define  VODU_TYPE       struct Qdu2

#   define  VODI_REPR       (REPR_VQDI|REPR_M2)
#   define  VODI_TYPE       struct Qdi2

#   define  VODF_REPR       (REPR_VQDF|REPR_M2)
#   define  VODF_TYPE       struct Qdf2


#   define  VSYU_REPR       (REPR_VQYU|REPR_M4)
#   define  VSYU_TYPE       struct Qyu4

#   define  VSBU_REPR       (REPR_VQBU|REPR_M4)
#   define  VSBU_TYPE       struct Qbu4

#   define  VSBI_REPR       (REPR_VQBI|REPR_M4)
#   define  VSBI_TYPE       struct Qbi4

#if CHAR_SIGNEDNESS
#   define  VSBC_REPR       VSBI_REPR
#   define  VSBC_TYPE       struct Qbi4
#else
#   define  VSBC_REPR       VSBU_REPR
#   define  VSBC_TYPE       struct Qbu4
#endif

#   define  VSHU_REPR       (REPR_VQHU|REPR_M4)
#   define  VSHU_TYPE       struct Qhu4

#   define  VSHI_REPR       (REPR_VQHI|REPR_M4)
#   define  VSHI_TYPE       struct Qhi4

#   define  VSHF_REPR       (REPR_VQHF|REPR_M4)
#   define  VSHF_TYPE       struct Qhf4


#   define  VSWU_REPR       (REPR_VQWU|REPR_M4)
#   define  VSWU_TYPE       struct Qwu4

#   define  VSWI_REPR       (REPR_VQWI|REPR_M4)
#   define  VSWI_TYPE       struct Qwi4

#   define  VSWF_REPR       (REPR_VQWF|REPR_M4)
#   define  VSWF_TYPE       struct Qwf4


#   define  VSDU_REPR       (REPR_VQDU|REPR_M4)
#   define  VSDU_TYPE       struct Qdu4

#   define  VSDI_REPR       (REPR_VQDI|REPR_M4)
#   define  VSDI_TYPE       struct Qdi4

#   define  VSDF_REPR       (REPR_VQDF|REPR_M4)
#   define  VSDF_TYPE       struct Qdf4

#endif

#if _LEAVE_EXTVEC_ARM_SIMD
}
#endif

#if _ENTER_EXTVEC_PPC_SIMD
{
#endif

#if defined(SPC_PPC_ALTIVEC)
/*  Altivec is the name used by Motorola to refer to the
    VMX (Power Vector Media Extension), which initially was
    limited to char, short, int, and float vectors.
    In ISA 2.07, VSX (Vector-Scalar Extension) added
    support for 64 bit ints and floats.

    __VEC_ELEMENT_REG_ORDER__ is defined as
    __ORDER_BIG_ENDIAN__ or __ORDER_LITTLE_ENDIAN__

    The ELFv2 ABI for Power defines a `vector _Float16`
    type but as of 2023-10, no compiler actually implements
    it.

    The cast operator is semantically identical to the
    corresponding as** operation, i.e.:

        Vqdu asduqbi(Vwbi a)
        {
            return (Vqdu) a;
        }


*/


#   define  VQBU_REPR       REPR_VQBU
#   define  VQBU_TYPE       vector unsigned char
#   define  VQBU_MTYPE      vector unsigned char

#   define  VQBI_REPR       REPR_VQBI
#   define  VQBI_TYPE       vector signed char
#   define  VQBI_MTYPE      vector signed char

#if CHAR_SIGNEDNESS
#   define  VQBC_REPR       VQBI_REPR
#   define  VQBC_TYPE       vector signed char
#else
#   define  VQBC_REPR       VQBU_REPR
#   define  VQBC_TYPE       vector unsigned char
#endif

#   define  VQHU_REPR       REPR_VQHU
#   define  VQHU_TYPE       vector unsigned short
#   define  VQHU_MTYPE      vector unsigned short

#   define  VQHI_REPR       REPR_VQHI
#   define  VQHI_TYPE       vector signed short
#   define  VQHI_MTYPE      vector signed short

#   define  VQHF_REPR       REPR_VQHF
#   define  VQHF_TYPE       vector unsigned short
#   define  VQHF_MTYPE      vector unsigned short

#   define  VQWU_REPR       REPR_VQWU
#   define  VQWU_TYPE       vector unsigned int
#   define  VQWU_MTYPE      vector unsigned int

#   define  VQWI_REPR       REPR_VQWI
#   define  VQWI_TYPE       vector signed int
#   define  VQWI_MTYPE      vector signed int

#   define  VQWF_REPR       REPR_VQWF
#   define  VQWF_TYPE       vector float
#   define  VQWF_MTYPE      vector float

#   define  VQDU_REPR       REPR_VQDU
#   define  VQDU_TYPE       vector unsigned long long
#   define  VQDU_MTYPE      vector unsigned long long

#   define  VQDI_REPR       REPR_VQDI
#   define  VQDI_TYPE       vector signed long long
#   define  VQDI_MTYPE      vector signed long long

#   define  VQDF_REPR       REPR_VQDF
#   define  VQDF_TYPE       vector double
#   define  VQDF_MTYPE      vector double

#   define  VOBU_REPR       (REPR_VQBU|REPR_M2)
#   define  VOBU_TYPE       struct Qbu2

#   define  VOBI_REPR       (REPR_VQBI|REPR_M2)
#   define  VOBI_TYPE       struct Qbi2

#   define  VOHU_REPR       (REPR_VQHU|REPR_M2)
#   define  VOHU_TYPE       struct Qhu2

#   define  VOHI_REPR       (REPR_VQHI|REPR_M2)
#   define  VOHI_TYPE       struct Qhi2

#   define  VOHF_REPR       (REPR_VQHF|REPR_M2)
#   define  VOHF_TYPE       struct Qhf2

#   define  VOWU_REPR       (REPR_VQWU|REPR_M2)
#   define  VOWU_TYPE       struct Qwu2

#   define  VOWI_REPR       (REPR_VQWI|REPR_M2)
#   define  VOWI_TYPE       struct Qwi2

#   define  VOWF_REPR       (REPR_VQWF|REPR_M2)
#   define  VOWF_TYPE       struct Qwf2

#   define  VODU_REPR       (REPR_VQDU|REPR_M2)
#   define  VODU_TYPE       struct Qdu2

#   define  VODI_REPR       (REPR_VQDI|REPR_M2)
#   define  VODI_TYPE       struct Qdi2

#   define  VODF_REPR       (REPR_VQDF|REPR_M2)
#   define  VODF_TYPE       struct Qdf2


#   define  VSBU_REPR       (REPR_VQBU|REPR_M4)
#   define  VSBU_TYPE       struct Qbu4

#   define  VSBI_REPR       (REPR_VQBI|REPR_M4)
#   define  VSBI_TYPE       struct Qbi4


#   define  VSHU_REPR       (REPR_VQHU|REPR_M4)
#   define  VSHU_TYPE       struct Qhu4

#   define  VSHI_REPR       (REPR_VQHI|REPR_M4)
#   define  VSHI_TYPE       struct Qhi4

#   define  VSHF_REPR       (REPR_VQHF|REPR_M4)
#   define  VSHF_TYPE       struct Qhf4


#   define  VSWU_REPR       (REPR_VQWU|REPR_M4)
#   define  VSWU_TYPE       struct Qwu4

#   define  VSWI_REPR       (REPR_VQWI|REPR_M4)
#   define  VSWI_TYPE       struct Qwi4

#   define  VSWF_REPR       (REPR_VQWF|REPR_M4)
#   define  VSWF_TYPE       struct Qwf4


#   define  VSDU_REPR       (REPR_VQDU|REPR_M4)
#   define  VSDU_TYPE       struct Qdu4

#   define  VSDI_REPR       (REPR_VQDI|REPR_M4)
#   define  VSDI_TYPE       struct Qdi4

#   define  VSDF_REPR       (REPR_VQDF|REPR_M4)
#   define  VSDF_TYPE       struct Qdf4

#endif

#if _LEAVE_EXTVEC_PPC_SIMD
}
#endif

#if _ENTER_EXTVEC_VW_REPR
{
#endif


#ifndef     VWYU_REPR
#define     VWYU_REPR   REPR_YU32
#define     VWYU_TYPE   struct Yu32
#endif

#ifndef     VWBU_REPR
#define     VWBU_REPR   REPR_BU4
#define     VWBU_TYPE   struct  Bu4
#endif

#ifndef     VWBI_REPR
#define     VWBI_REPR   REPR_BI4
#define     VWBI_TYPE   struct  Bi4
#endif


#ifndef     VWHU_REPR
#define     VWHU_REPR   REPR_HU2
#define     VWHU_TYPE   struct  Hu2
#endif

#ifndef     VWHI_REPR
#define     VWHI_REPR   REPR_HI2
#define     VWHI_TYPE   struct  Hi2
#endif

#ifndef     VWHF_REPR
#define     VWHF_REPR   REPR_HF2
#define     VWHF_TYPE   struct  Hf2
#endif


#ifndef     VWWU_REPR
#define     VWWU_REPR   REPR_WU1
#define     VWWU_TYPE   struct  Wu1
#endif

#ifndef     VWWI_REPR
#define     VWWI_REPR   REPR_WI1
#define     VWWI_TYPE   struct  Wi1
#endif

#ifndef     VWWF_REPR
#define     VWWF_REPR   REPR_WF1
#define     VWWF_TYPE   struct  Wf1
#endif


#if _LEAVE_EXTVEC_VW_REPR
}
#endif

#if _ENTER_EXTVEC_VD_REPR
{
#endif

#ifndef     VDYU_REPR
#define     VDYU_REPR   REPR_YU64
#define     VDYU_TYPE   struct Yu64
#endif

#ifndef     VDBU_REPR
#define     VDBU_REPR   REPR_BU8
#define     VDBU_TYPE   struct  Bu8
#endif

#ifndef     VDBI_REPR
#define     VDBI_REPR   REPR_BI8
#define     VDBI_TYPE   struct  Bi8
#endif


#ifndef     VDHU_REPR
#define     VDHU_REPR   REPR_HU4
#define     VDHU_TYPE   struct  Hu4
#endif

#ifndef     VDHI_REPR
#define     VDHI_REPR   REPR_HI4
#define     VDHI_TYPE   struct  Hi4
#endif

#ifndef     VDHF_REPR
#define     VDHF_REPR   REPR_HF4
#define     VDHF_TYPE   struct  Hf4
#endif

#ifndef     VDWU_REPR
#define     VDWU_REPR   REPR_WU2
#define     VDWU_TYPE   struct  Wu2
#endif

#ifndef     VDWI_REPR
#define     VDWI_REPR   REPR_WI2
#define     VDWI_TYPE   struct  Wi2
#endif

#ifndef     VDWF_REPR
#define     VDWF_REPR   REPR_WF2
#define     VDWF_TYPE   struct  Wf2
#endif


#ifndef     VDDU_REPR
#define     VDDU_REPR   REPR_DU1
#define     VDDU_TYPE   struct  Du1
#endif

#ifndef     VDDI_REPR
#define     VDDI_REPR   REPR_DI1
#define     VDDI_TYPE   struct  Di1
#endif

#ifndef     VDDF_REPR
#define     VDDF_REPR   REPR_DF1
#define     VDDF_TYPE   struct  Df1
#endif

#if _LEAVE_EXTVEC_VD_REPR
}
#endif

#if _ENTER_EXTVEC_VQ_REPR
{
#endif

#ifndef     VQYU_REPR
#define     VQYU_REPR   REPR_YU128
#define     VQYU_TYPE   struct Yu128
#endif

#ifndef     VQBU_REPR
#define     VQBU_REPR   REPR_BU16
#define     VQBU_TYPE   struct  Bu16
#endif

#ifndef     VQBI_REPR
#define     VQBI_REPR   REPR_BI16
#define     VQBI_TYPE   struct  Bi16
#endif


#ifndef     VQHU_REPR
#define     VQHU_REPR   REPR_HU8
#define     VQHU_TYPE   struct  Hu8
#endif

#ifndef     VQHI_REPR
#define     VQHI_REPR   REPR_HI8
#define     VQHI_TYPE   struct  Hi8
#endif

#ifndef     VQHF_REPR
#define     VQHF_REPR   REPR_HF8
#define     VQHF_TYPE   struct  Hf8
#endif

#ifndef     VQWU_REPR
#define     VQWU_REPR   REPR_WU4
#define     VQWU_TYPE   struct  Wu4
#endif

#ifndef     VQWI_REPR
#define     VQWI_REPR   REPR_WI4
#define     VQWI_TYPE   struct  Wi4
#endif

#ifndef     VQWF_REPR
#define     VQWF_REPR   REPR_WF4
#define     VQWF_TYPE   struct  Wf4
#endif


#ifndef     VQDU_REPR
#define     VQDU_REPR   REPR_DU2
#define     VQDU_TYPE   struct  Du2
#endif

#ifndef     VQDI_REPR
#define     VQDI_REPR   REPR_DI2
#define     VQDI_TYPE   struct  Di2
#endif

#ifndef     VQDF_REPR
#define     VQDF_REPR   REPR_DF2
#define     VQDF_TYPE   struct  Df2
#endif

#if _LEAVE_EXTVEC_VQ_REPR
}
#endif

#if _ENTER_EXTVEC_VO_REPR
{
#endif

#ifndef     VOBU_REPR
#define     VOBU_REPR   REPR_BU32
#define     VOBU_TYPE   struct  Bu32
#endif

#ifndef     VOBI_REPR
#define     VOBI_REPR   REPR_BI32
#define     VOBI_TYPE   struct  Bi32
#endif


#ifndef     VOHU_REPR
#define     VOHU_REPR   REPR_HU16
#define     VOHU_TYPE   struct  Hu16
#endif

#ifndef     VOHI_REPR
#define     VOHI_REPR   REPR_HI16
#define     VOHI_TYPE   struct  Hi16
#endif

#ifndef     VOHF_REPR
#define     VOHF_REPR   REPR_HF16
#define     VOHF_TYPE   struct  Hf16
#endif


#ifndef     VOWU_REPR
#define     VOWU_REPR   REPR_WU8
#define     VOWU_TYPE   struct  Wu8
#endif

#ifndef     VOWI_REPR
#define     VOWI_REPR   REPR_WI8
#define     VOWI_TYPE   struct  Wi8
#endif

#ifndef     VOWF_REPR
#define     VOWF_REPR   REPR_WF8
#define     VOWF_TYPE   struct  Wf8
#endif


#ifndef     VODU_REPR
#define     VODU_REPR   REPR_DU4
#define     VODU_TYPE   struct  Du4
#endif

#ifndef     VODI_REPR
#define     VODI_REPR   REPR_DI4
#define     VODI_TYPE   struct  Di4
#endif

#ifndef     VODF_REPR
#define     VODF_REPR   REPR_DF4
#define     VODF_TYPE   struct  Df4
#endif

#if _LEAVE_EXTVEC_VO_REPR
}
#endif

#if _ENTER_EXTVEC_VS_REPR
{
#endif

#ifndef     VSBU_REPR
#define     VSBU_REPR   REPR_BU64
#define     VSBU_TYPE   struct  Bu64
#endif

#ifndef     VSBI_REPR
#define     VSBI_REPR   REPR_BI64
#define     VSBI_TYPE   struct  Bi64
#endif


#ifndef     VSHU_REPR
#define     VSHU_REPR   REPR_HU32
#define     VSHU_TYPE   struct  Hu32
#endif

#ifndef     VSHI_REPR
#define     VSHI_REPR   REPR_HI32
#define     VSHI_TYPE   struct  Hi32
#endif

#ifndef     VSHF_REPR
#define     VSHF_REPR   REPR_HF32
#define     VSHF_TYPE   struct  Hf32
#endif


#ifndef     VSWU_REPR
#define     VSWU_REPR   REPR_WU16
#define     VSWU_TYPE   struct  Wu16
#endif

#ifndef     VSWI_REPR
#define     VSWI_REPR   REPR_WI16
#define     VSWI_TYPE   struct  Wi16
#endif

#ifndef     VSWF_REPR
#define     VSWF_REPR   REPR_WF16
#define     VSWF_TYPE   struct  Wf16
#endif


#ifndef     VSDU_REPR
#define     VSDU_REPR   REPR_DU8
#define     VSDU_TYPE   struct  Du8
#endif

#ifndef     VSDI_REPR
#define     VSDI_REPR   REPR_DI8
#define     VSDI_TYPE   struct  Di8
#endif

#ifndef     VSDF_REPR
#define     VSDF_REPR   REPR_DF8
#define     VSDF_TYPE   struct  Df8
#endif

#if _LEAVE_EXTVEC_VS_REPR
}
#endif

#if _ENTER_EXTVEC_HWVA_REPR
{
#endif

#if  defined(VWYU_MTYPE)
typedef      VWYU_MTYPE Wyu;
struct Wyu1 {
    union {
#   if defined(VWYU_M1TYPE)
        VWYU_M1TYPE   M;
#   endif
        struct {VWYU_MTYPE MY_NV1(V,);};
    };
};
struct Wyu2 {
    union {
#   if defined(VWYU_M2TYPE)
        VWYU_M2TYPE   M;
#   endif
        struct {VWYU_MTYPE MY_NV2(V,);};
    };
};
struct Wyu3 {
    union {
#   if defined(VWYU_M3TYPE)
        VWYU_M3TYPE   M;
#   endif
        struct {VWYU_MTYPE MY_NV3(V,);};
    };
};
struct Wyu4 {
    union {
#   if defined(VWYU_M4TYPE)
        VWYU_M4TYPE   M;
#   endif
        struct {VWYU_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VWBU_MTYPE)
typedef      VWBU_MTYPE Wbu;
struct Wbu1 {
    union {
#   if defined(VWBU_M1TYPE)
        VWBU_M1TYPE   M;
#   endif
        struct {VWBU_MTYPE MY_NV1(V,);};
    };
};
struct Wbu2 {
    union {
#   if defined(VWBU_M2TYPE)
        VWBU_M2TYPE   M;
#   endif
        struct {VWBU_MTYPE MY_NV2(V,);};
    };
};
struct Wbu3 {
    union {
#   if defined(VWBU_M3TYPE)
        VWBU_M3TYPE   M;
#   endif
        struct {VWBU_MTYPE MY_NV3(V,);};
    };
};
struct Wbu4 {
    union {
#   if defined(VWBU_M4TYPE)
        VWBU_M4TYPE   M;
#   endif
        struct {VWBU_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VWBI_MTYPE)

typedef      VWBI_MTYPE Wbi;

struct Wbi1 {
    union {
#   if defined(VWBI_M1TYPE)
        VWBI_M1TYPE   M;
#   endif
        struct {VWBI_MTYPE MY_NV1(V,);};
    };
};

struct Wbi2 {
    union {
#   if defined(VWBI_M2TYPE)
        VWBI_M2TYPE   M;
#   endif
        struct {VWBI_MTYPE MY_NV2(V,);};
    };
};

struct Wbi3 {
    union {
#   if defined(VWBI_M3TYPE)
        VWBI_M3TYPE   M;
#   endif
        struct {VWBI_MTYPE MY_NV3(V,);};
    };
};

struct Wbi4 {
    union {
#   if defined(VWBI_M4TYPE)
        VWBI_M4TYPE   M;
#   endif
        struct {VWBI_MTYPE MY_NV4(V,);};
    };
};

#endif


#if  defined(VWBC_MTYPE)

typedef      VWBC_MTYPE Wbc;

struct Wbc1 {
    union {
#   if defined(VWBC_M1TYPE)
        VWBC_M1TYPE   M;
#   endif
        struct {VWBC_MTYPE MY_NV1(V,);};
    };
};

struct Wbc2 {
    union {
#   if defined(VWBC_M2TYPE)
        VWBC_M2TYPE   M;
#   endif
        struct {VWBC_MTYPE MY_NV2(V,);};
    };
};

struct Wbc3 {
    union {
#   if defined(VWBC_M3TYPE)
        VWBC_M3TYPE   M;
#   endif
        struct {VWBC_MTYPE MY_NV3(V,);};
    };
};

struct Wbc4 {
    union {
#   if defined(VWBC_M4TYPE)
        VWBC_M4TYPE   M;
#   endif
        struct {VWBC_MTYPE MY_NV4(V,);};
    };
};

#endif


#if  defined(VWHU_MTYPE)

typedef      VWHU_MTYPE Whu;

struct Whu1 {
    union {
#   if defined(VWHU_M1TYPE)
        VWHU_M1TYPE   M;
#   endif
        struct {VWHU_MTYPE MY_NV1(V,);};
    };
};

struct Whu2 {
    union {
#   if defined(VWHU_M2TYPE)
        VWHU_M2TYPE   M;
#   endif
        struct {VWHU_MTYPE MY_NV2(V,);};
    };
};

struct Whu3 {
    union {
#   if defined(VWHU_M3TYPE)
        VWHU_M3TYPE   M;
#   endif
        struct {VWHU_MTYPE MY_NV3(V,);};
    };
};

struct Whu4 {
    union {
#   if defined(VWHU_M4TYPE)
        VWHU_M4TYPE   M;
#   endif
        struct {VWHU_MTYPE MY_NV4(V,);};
    };
};

#endif


#if  defined(VWHI_MTYPE)
typedef      VWHI_MTYPE Whi;
struct Whi1 {
    union {
#   if defined(VWHI_M1TYPE)
        VWHI_M1TYPE   M;
#   endif
        struct {VWHI_MTYPE MY_NV1(V,);};
    };
};
struct Whi2 {
    union {
#   if defined(VWHI_M2TYPE)
        VWHI_M2TYPE   M;
#   endif
        struct {VWHI_MTYPE MY_NV2(V,);};
    };
};
struct Whi3 {
    union {
#   if defined(VWHI_M3TYPE)
        VWHI_M3TYPE   M;
#   endif
        struct {VWHI_MTYPE MY_NV3(V,);};
    };
};
struct Whi4 {
    union {
#   if defined(VWHI_M4TYPE)
        VWHI_M4TYPE   M;
#   endif
        struct {VWHI_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VWHF_MTYPE)
typedef      VWHF_MTYPE Whf;
struct Whf1 {
    union {
#   if defined(VWHF_M1TYPE)
        VWHF_M1TYPE   M;
#   endif
        struct {VWHF_MTYPE MY_NV1(V,);};
    };
};
struct Whf2 {
    union {
#   if defined(VWHF_M2TYPE)
        VWHF_M2TYPE   M;
#   endif
        struct {VWHF_MTYPE MY_NV2(V,);};
    };
};
struct Whf3 {
    union {
#   if defined(VWHF_M3TYPE)
        VWHF_M3TYPE   M;
#   endif
        struct {VWHF_MTYPE MY_NV3(V,);};
    };
};
struct Whf4 {
    union {
#   if defined(VWHF_M4TYPE)
        VWHF_M4TYPE   M;
#   endif
        struct {VWHF_MTYPE MY_NV4(V,);};
    };
};
#endif


#if  defined(VWWU_MTYPE)
typedef      VWWU_MTYPE Wwu;
struct Wwu1 {
    union {
#   if defined(VWWU_M1TYPE)
        VWWU_M1TYPE   M;
#   endif
        struct {VWWU_MTYPE MY_NV1(V,);};
    };
};
struct Wwu2 {
    union {
#   if defined(VWWU_M2TYPE)
        VWWU_M2TYPE   M;
#   endif
        struct {VWWU_MTYPE MY_NV2(V,);};
    };
};
struct Wwu3 {
    union {
#   if defined(VWWU_M3TYPE)
        VWWU_M3TYPE   M;
#   endif
        struct {VWWU_MTYPE MY_NV3(V,);};
    };
};
struct Wwu4 {
    union {
#   if defined(VWWU_M4TYPE)
        VWWU_M4TYPE   M;
#   endif
        struct {VWWU_MTYPE MY_NV4(V,);};
    };
};

#endif

#if  defined(VWWI_MTYPE)
typedef      VWWI_MTYPE Wwi;
struct Wwi1 {
    union {
#   if defined(VWWI_M1TYPE)
        VWWI_M1TYPE   M;
#   endif
        struct {VWWI_MTYPE MY_NV1(V,);};
    };
};
struct Wwi2 {
    union {
#   if defined(VWWI_M2TYPE)
        VWWI_M2TYPE   M;
#   endif
        struct {VWWI_MTYPE MY_NV2(V,);};
    };
};
struct Wwi3 {
    union {
#   if defined(VWWI_M3TYPE)
        VWWI_M3TYPE   M;
#   endif
        struct {VWWI_MTYPE MY_NV3(V,);};
    };
};
struct Wwi4 {
    union {
#   if defined(VWWI_M4TYPE)
        VWWI_M4TYPE   M;
#   endif
        struct {VWWI_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VWWF_MTYPE)
typedef      VWWF_MTYPE Wwf;
struct Wwf1 {
    union {
#   if defined(VWWF_M1TYPE)
        VWWF_M1TYPE   M;
#   endif
        struct {VWWF_MTYPE MY_NV1(V,);};
    };
};
struct Wwf2 {
    union {
#   if defined(VWWF_M2TYPE)
        VWWF_M2TYPE   M;
#   endif
        struct {VWWF_MTYPE MY_NV2(V,);};
    };
};
struct Wwf3 {
    union {
#   if defined(VWWF_M3TYPE)
        VWWF_M3TYPE   M;
#   endif
        struct {VWWF_MTYPE MY_NV3(V,);};
    };
};
struct Wwf4 {
    union {
#   if defined(VWWF_M4TYPE)
        VWWF_M4TYPE   M;
#   endif
        struct {VWWF_MTYPE MY_NV4(V,);};
    };
};
#endif

#if defined(TST_HA_V32_SIZES)
#   if 0
//      <ENTERTST=HA_V32_SIZES>
    {
#   endif

#   if defined(VWBU_MTYPE)
ASSERT(004 == sizeof(       Wbu));
ASSERT(004 == sizeof(struct Wbu1));
ASSERT(010 == sizeof(struct Wbu2));
ASSERT(014 == sizeof(struct Wbu3));
ASSERT(020 == sizeof(struct Wbu4));
#   endif

#   if defined(VWBI_MTYPE)
ASSERT(004 == sizeof(       Wbi));
ASSERT(004 == sizeof(struct Wbi1));
ASSERT(010 == sizeof(struct Wbi2));
ASSERT(014 == sizeof(struct Wbi3));
ASSERT(020 == sizeof(struct Wbi4));
#   endif


#   if defined(VWHU_MTYPE)
ASSERT(004 == sizeof(       Whu));
ASSERT(004 == sizeof(struct Whu1));
ASSERT(010 == sizeof(struct Whu2));
ASSERT(014 == sizeof(struct Whu3));
ASSERT(020 == sizeof(struct Whu4));
#   endif

#   if defined(VWHI_MTYPE)
ASSERT(004 == sizeof(       Whi));
ASSERT(004 == sizeof(struct Whi1));
ASSERT(010 == sizeof(struct Whi2));
ASSERT(014 == sizeof(struct Whi3));
ASSERT(020 == sizeof(struct Whi4));
#   endif

#   if defined(VWHF_MTYPE)
ASSERT(004 == sizeof(       Whf));
ASSERT(004 == sizeof(struct Whf1));
ASSERT(010 == sizeof(struct Whf2));
ASSERT(014 == sizeof(struct Whf3));
ASSERT(020 == sizeof(struct Whf4));
#   endif


#   if defined(VWWU_MTYPE)
ASSERT(004 == sizeof(       Wwu));
ASSERT(004 == sizeof(struct Wwu1));
ASSERT(010 == sizeof(struct Wwu2));
ASSERT(014 == sizeof(struct Wwu3));
ASSERT(020 == sizeof(struct Wwu4));
#   endif

#   if defined(VWWI_MTYPE)
ASSERT(004 == sizeof(       Wwi));
ASSERT(004 == sizeof(struct Wwi1));
ASSERT(010 == sizeof(struct Wwi2));
ASSERT(014 == sizeof(struct Wwi3));
ASSERT(020 == sizeof(struct Wwi4));
#   endif

#   if defined(VWWF_MTYPE)
ASSERT(004 == sizeof(       Wwf));
ASSERT(004 == sizeof(struct Wwf1));
ASSERT(010 == sizeof(struct Wwf2));
ASSERT(014 == sizeof(struct Wwf3));
ASSERT(020 == sizeof(struct Wwf4));
#   endif


#   if 0
    }
//      <LEAVETST=HA_V32_SIZES>
#   endif

#endif
//  defined(TST_HA_V32_SIZES)


#if _LEAVE_EXTVEC_HWVA_REPR
}
#endif

#if _ENTER_EXTVEC_HDVA_REPR
{
#endif

#if  defined(VDYU_MTYPE)
typedef      VDYU_MTYPE Dyu;
struct Dyu1 {
    union {
#   if defined(VDYU_M1TYPE)
        VDYU_M1TYPE   M;
#   endif
        struct {VDYU_MTYPE MY_NV1(V,);};
    };
};
struct Dyu2 {
    union {
#   if defined(VDYU_M2TYPE)
        VDYU_M2TYPE   M;
#   endif
        struct {VDYU_MTYPE MY_NV2(V,);};
    };
};
struct Dyu3 {
    union {
#   if defined(VDYU_M3TYPE)
        VDYU_M3TYPE   M;
#   endif
        struct {VDYU_MTYPE MY_NV3(V,);};
    };
};
struct Dyu4 {
    union {
#   if defined(VDYU_M4TYPE)
        VDBU_M4TYPE   M;
#   endif
        struct {VDYU_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VDBU_MTYPE)
typedef      VDBU_MTYPE Dbu;
struct Dbu1 {
    union {
#   if defined(VDBU_M1TYPE)
        VDBU_M1TYPE   M;
#   endif
        struct {VDBU_MTYPE MY_NV1(V,);};
    };
};
struct Dbu2 {
    union {
#   if defined(VDBU_M2TYPE)
        VDBU_M2TYPE   M;
#   endif
        struct {VDBU_MTYPE MY_NV2(V,);};
    };
};
struct Dbu3 {
    union {
#   if defined(VDBU_M3TYPE)
        VDBU_M3TYPE   M;
#   endif
        struct {VDBU_MTYPE MY_NV3(V,);};
    };
};
struct Dbu4 {
    union {
#   if defined(VDBU_M4TYPE)
        VDBU_M4TYPE   M;
#   endif
        struct {VDBU_MTYPE MY_NV4(V,);};
    };
};
#endif


#if  defined(VDBI_MTYPE)
typedef      VDBI_MTYPE Dbi;
struct Dbi1 {
    union {
#   if defined(VDBI_M1TYPE)
        VDBI_M1TYPE   M;
#   endif
        struct {VDBI_MTYPE MY_NV1(V,);};
    };
};
struct Dbi2 {
    union {
#   if defined(VDBI_M2TYPE)
        VDBI_M2TYPE   M;
#   endif
        struct {VDBI_MTYPE MY_NV2(V,);};
    };
};
struct Dbi3 {
    union {
#   if defined(VDBI_M3TYPE)
        VDBI_M3TYPE   M;
#   endif
        struct {VDBI_MTYPE MY_NV3(V,);};
    };
};
struct Dbi4 {
    union {
#   if defined(VDBI_M4TYPE)
        VDBI_M4TYPE   M;
#   endif
        struct {VDBI_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VDBC_MTYPE)
typedef      VDBC_MTYPE Dbc;
struct Dbc1 {
    union {
#   if defined(VDBC_M1TYPE)
        VDBC_M1TYPE   M;
#   endif
        struct {VDBC_MTYPE MY_NV1(V,);};
    };
};
struct Dbc2 {
    union {
#   if defined(VDBC_M2TYPE)
        VDBC_M2TYPE   M;
#   endif
        struct {VDBC_MTYPE MY_NV2(V,);};
    };
};
struct Dbc3 {
    union {
#   if defined(VDBC_M3TYPE)
        VDBC_M3TYPE   M;
#   endif
        struct {VDBC_MTYPE MY_NV3(V,);};
    };
};
struct Dbc4 {
    union {
#   if defined(VDBC_M4TYPE)
        VDBC_M4TYPE   M;
#   endif
        struct {VDBC_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VDHU_MTYPE)
typedef      VDHU_MTYPE Dhu;
struct Dhu1 {
    union {
#   if defined(VDHU_M1TYPE)
        VDHU_M1TYPE   M;
#   endif
        struct {VDHU_MTYPE MY_NV1(V,);};
    };
};
struct Dhu2 {
    union {
#   if defined(VDHU_M2TYPE)
        VDHU_M2TYPE   M;
#   endif
        struct {VDHU_MTYPE MY_NV2(V,);};
    };
};
struct Dhu3 {
    union {
#   if defined(VDHU_M3TYPE)
        VDHU_M3TYPE   M;
#   endif
        struct {VDHU_MTYPE MY_NV3(V,);};
    };
};
struct Dhu4 {
    union {
#   if defined(VDHU_M4TYPE)
        VDHU_M4TYPE   M;
#   endif
        struct {VDHU_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VDHI_MTYPE)
typedef      VDHI_MTYPE Dhi;
struct Dhi1 {
    union {
#   if defined(VDHI_M1TYPE)
        VDHI_M1TYPE   M;
#   endif
        struct {VDHI_MTYPE MY_NV1(V,);};
    };
};
struct Dhi2 {
    union {
#   if defined(VDHI_M2TYPE)
        VDHI_M2TYPE   M;
#   endif
        struct {VDHI_MTYPE MY_NV2(V,);};
    };
};
struct Dhi3 {
    union {
#   if defined(VDHI_M3TYPE)
        VDHI_M3TYPE   M;
#   endif
        struct {VDHI_MTYPE MY_NV3(V,);};
    };
};
struct Dhi4 {
    union {
#   if defined(VDHI_M4TYPE)
        VDHI_M4TYPE   M;
#   endif
        struct {VDHI_MTYPE MY_NV4(V,);};
    };
};
#endif


#if  defined(VDHF_MTYPE)
typedef      VDHF_MTYPE Dhf;
struct Dhf1 {
    union {
#   if defined(VDHF_M1TYPE)
        VDHF_M1TYPE   M;
#   endif
        struct {VDHF_MTYPE MY_NV1(V,);};
    };
};
struct Dhf2 {
    union {
#   if defined(VDHF_M2TYPE)
        VDHF_M2TYPE   M;
#   endif
        struct {VDHF_MTYPE MY_NV2(V,);};
    };
};
struct Dhf3 {
    union {
#   if defined(VDHF_M3TYPE)
        VDHF_M3TYPE   M;
#   endif
        struct {VDHF_MTYPE MY_NV3(V,);};
    };
};
struct Dhf4 {
    union {
#   if defined(VDHF_M4TYPE)
        VDHF_M4TYPE   M;
#   endif
        struct {VDHF_MTYPE MY_NV4(V,);};
    };
};
#endif


#if  defined(VDWU_MTYPE)
typedef      VDWU_MTYPE Dwu;
struct Dwu1 {
    union {
#   if defined(VDWU_M1TYPE)
        VDWU_M1TYPE   M;
#   endif
        struct {VDWU_MTYPE MY_NV1(V,);};
    };
};
struct Dwu2 {
    union {
#   if defined(VDWU_M2TYPE)
        VDWU_M2TYPE   M;
#   endif
        struct {VDWU_MTYPE MY_NV2(V,);};
    };
};
struct Dwu3 {
    union {
#   if defined(VDWU_M3TYPE)
        VDWU_M3TYPE   M;
#   endif
        struct {VDWU_MTYPE MY_NV3(V,);};
    };
};
struct Dwu4 {
    union {
#   if defined(VDWU_M4TYPE)
        VDWU_M4TYPE   M;
#   endif
        struct {VDWU_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VDWI_MTYPE)
typedef      VDWI_MTYPE Dwi;
struct Dwi1 {
    union {
#   if defined(VDWI_M1TYPE)
        VDWI_M1TYPE   M;
#   endif
        struct {VDWI_MTYPE MY_NV1(V,);};
    };
};
struct Dwi2 {
    union {
#   if defined(VDWI_M2TYPE)
        VDWI_M2TYPE   M;
#   endif
        struct {VDWI_MTYPE MY_NV2(V,);};
    };
};
struct Dwi3 {
    union {
#   if defined(VDWI_M3TYPE)
        VDWI_M3TYPE   M;
#   endif
        struct {VDWI_MTYPE MY_NV3(V,);};
    };
};
struct Dwi4 {
    union {
#   if defined(VDWI_M4TYPE)
        VDWI_M4TYPE   M;
#   endif
        struct {VDWI_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VDWF_MTYPE)
typedef      VDWF_MTYPE Dwf;
struct Dwf1 {
    union {
#   if defined(VDWF_M1TYPE)
        VDWF_M1TYPE   M;
#   endif
        struct {VDWF_MTYPE MY_NV1(V,);};
    };
};
struct Dwf2 {
    union {
#   if defined(VDWF_M2TYPE)
        VDWF_M2TYPE   M;
#   endif
        struct {VDWF_MTYPE MY_NV2(V,);};
    };
};
struct Dwf3 {
    union {
#   if defined(VDWF_M3TYPE)
        VDWF_M3TYPE   M;
#   endif
        struct {VDWF_MTYPE MY_NV3(V,);};
    };
};
struct Dwf4 {
    union {
#   if defined(VDWF_M4TYPE)
        VDWF_M4TYPE   M;
#   endif
        struct {VDWF_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VDDU_MTYPE)
typedef      VDDU_MTYPE Ddu;
struct Ddu1 {
    union {
#   if defined(VDDU_M1TYPE)
        VDDU_M1TYPE   M;
#   endif
        struct {VDDU_MTYPE MY_NV1(V,);};
    };
};
struct Ddu2 {
    union {
#   if defined(VDDU_M2TYPE)
        VDDU_M2TYPE   M;
#   endif
        struct {VDDU_MTYPE MY_NV2(V,);};
    };
};
struct Ddu3 {
    union {
#   if defined(VDDU_M3TYPE)
        VDDU_M3TYPE   M;
#   endif
        struct {VDDU_MTYPE MY_NV3(V,);};
    };
};
struct Ddu4 {
    union {
#   if defined(VDDU_M4TYPE)
        VDDU_M4TYPE   M;
#   endif
        struct {VDDU_MTYPE MY_NV4(V,);};
    };
};
#endif


#if  defined(VDDI_MTYPE)
typedef      VDDI_MTYPE Ddi;
struct Ddi1 {
    union {
#   if defined(VDDI_M1TYPE)
        VDDI_M1TYPE   M;
#   endif
        struct {VDDI_MTYPE MY_NV1(V,);};
    };
};
struct Ddi2 {
    union {
#   if defined(VDDI_M2TYPE)
        VDDI_M2TYPE   M;
#   endif
        struct {VDDI_MTYPE MY_NV2(V,);};
    };
};
struct Ddi3 {
    union {
#   if defined(VDDI_M3TYPE)
        VDDI_M3TYPE   M;
#   endif
        struct {VDDI_MTYPE MY_NV3(V,);};
    };
};
struct Ddi4 {
    union {
#   if defined(VDDI_M4TYPE)
        VDDI_M4TYPE   M;
#   endif
        struct {VDDI_MTYPE MY_NV4(V,);};
    };
};
#endif


#if  defined(VDDF_MTYPE)
typedef      VDDF_MTYPE Ddf;
struct Ddf1 {
    union {
#   if defined(VDDF_M1TYPE)
        VDDF_M1TYPE   M;
#   endif
        struct {VDDF_MTYPE MY_NV1(V,);};
    };
};
struct Ddf2 {
    union {
#   if defined(VDDF_M2TYPE)
        VDDF_M2TYPE   M;
#   endif
        struct {VDDF_MTYPE MY_NV2(V,);};
    };
};
struct Ddf3 {
    union {
#   if defined(VDDF_M3TYPE)
        VDDF_M3TYPE   M;
#   endif
        struct {VDDF_MTYPE MY_NV3(V,);};
    };
};
struct Ddf4 {
    union {
#   if defined(VDDF_M4TYPE)
        VDDF_M4TYPE   M;
#   endif
        struct {VDDF_MTYPE MY_NV4(V,);};
    };
};
#endif


#if defined(TST_HA_V64_SIZES)

#   if 0
//      <ENTERTST=HA_V64_SIZES>
    {
#   endif

#   if defined(VDBU_MTYPE)
ASSERT(010 == sizeof(       Dbu));
ASSERT(010 == sizeof(struct Dbu1));
ASSERT(020 == sizeof(struct Dbu2));
ASSERT(030 == sizeof(struct Dbu3));
ASSERT(040 == sizeof(struct Dbu4));
#   endif

#   if defined(VDBI_MTYPE)
ASSERT(010 == sizeof(       Dbi));
ASSERT(010 == sizeof(struct Dbi1));
ASSERT(020 == sizeof(struct Dbi2));
ASSERT(030 == sizeof(struct Dbi3));
ASSERT(040 == sizeof(struct Dbi4));
#   endif


#   if defined(VDHU_MTYPE)
ASSERT(010 == sizeof(       Dhu));
ASSERT(010 == sizeof(struct Dhu1));
ASSERT(020 == sizeof(struct Dhu2));
ASSERT(030 == sizeof(struct Dhu3));
ASSERT(040 == sizeof(struct Dhu4));
#   endif

#   if defined(VDHI_MTYPE)
ASSERT(010 == sizeof(       Dhi));
ASSERT(010 == sizeof(struct Dhi1));
ASSERT(020 == sizeof(struct Dhi2));
ASSERT(030 == sizeof(struct Dhi3));
ASSERT(040 == sizeof(struct Dhi4));
#   endif

#   if defined(VDHF_MTYPE)
ASSERT(010 == sizeof(       Dhf));
ASSERT(010 == sizeof(struct Dhf1));
ASSERT(020 == sizeof(struct Dhf2));
ASSERT(030 == sizeof(struct Dhf3));
ASSERT(040 == sizeof(struct Dhf4));
#   endif


#   if defined(VDWU_MTYPE)
ASSERT(010 == sizeof(       Dwu));
ASSERT(010 == sizeof(struct Dwu1));
ASSERT(020 == sizeof(struct Dwu2));
ASSERT(030 == sizeof(struct Dwu3));
ASSERT(040 == sizeof(struct Dwu4));
#   endif

#   if defined(VDWI_MTYPE)
ASSERT(010 == sizeof(       Dwi));
ASSERT(010 == sizeof(struct Dwi1));
ASSERT(020 == sizeof(struct Dwi2));
ASSERT(030 == sizeof(struct Dwi3));
ASSERT(040 == sizeof(struct Dwi4));
#   endif

#   if defined(VDWF_MTYPE)
ASSERT(010 == sizeof(       Dwf));
ASSERT(010 == sizeof(struct Dwf1));
ASSERT(020 == sizeof(struct Dwf2));
ASSERT(030 == sizeof(struct Dwf3));
ASSERT(040 == sizeof(struct Dwf4));
#   endif


#   if defined(VDDU_MTYPE)
ASSERT(010 == sizeof(       Ddu));
ASSERT(010 == sizeof(struct Ddu1));
ASSERT(020 == sizeof(struct Ddu2));
ASSERT(030 == sizeof(struct Ddu3));
ASSERT(040 == sizeof(struct Ddu4));
#   endif

#   if defined(VDDI_MTYPE)
ASSERT(010 == sizeof(       Ddi));
ASSERT(010 == sizeof(struct Ddi1));
ASSERT(020 == sizeof(struct Ddi2));
ASSERT(030 == sizeof(struct Ddi3));
ASSERT(040 == sizeof(struct Ddi4));
#   endif

#   if defined(VDDF_MTYPE)
ASSERT(010 == sizeof(       Ddf));
ASSERT(010 == sizeof(struct Ddf1));
ASSERT(020 == sizeof(struct Ddf2));
ASSERT(030 == sizeof(struct Ddf3));
ASSERT(040 == sizeof(struct Ddf4));
#   endif

#   if 0
    }
//      <LEAVETST=HA_V64_SIZES>
#   endif

#endif // defined(TST_HA_V64_SIZES)

#if _LEAVE_EXTVEC_HDVA_REPR
}
#endif

#if _ENTER_EXTVEC_HQVA_REPR
{
#endif


#if  defined(VQYU_MTYPE)

typedef      VQYU_MTYPE Qyu;

struct Qyu1 {
    union {
#   if defined(VQYU_M1TYPE)
        VQYU_M1TYPE   M;
#   endif
        struct {VQYU_MTYPE MY_NV1(V,);};
    };
};

struct Qyu2 {
    union {
#   if defined(VQYU_M2TYPE)
        VQYU_M2TYPE   M;
#   endif
        struct {VQYU_MTYPE MY_NV2(V,);};
    };
};

struct Qyu3 {
    union {
#   if defined(VQYU_M3TYPE)
        VQYU_M3TYPE   M;
#   endif
        struct {VQYU_MTYPE MY_NV3(V,);};
    };
};

struct Qyu4 {
    union {
#   if defined(VQYU_M4TYPE)
        VQYU_M4TYPE   M;
#   endif
        struct {VQYU_MTYPE MY_NV4(V,);};
    };
};

#endif


#if  defined(VQBU_MTYPE)

typedef      VQBU_MTYPE Qbu;

struct Qbu1 {
    union {
#   if defined(VQBU_M1TYPE)
        VQBU_M1TYPE   M;
#   endif
        struct {VQBU_MTYPE MY_NV1(V,);};
    };
};

struct Qbu2 {
    union {
#   if defined(VQBU_M2TYPE)
        VQBU_M2TYPE   M;
#   endif
        struct {VQBU_MTYPE MY_NV2(V,);};
    };
};

struct Qbu3 {
    union {
#   if defined(VQBU_M3TYPE)
        VQBU_M3TYPE   M;
#   endif
        struct {VQBU_MTYPE MY_NV3(V,);};
    };
};

struct Qbu4 {
    union {
#   if defined(VQBU_M4TYPE)
        VQBU_M4TYPE   M;
#   endif
        struct {VQBU_MTYPE MY_NV4(V,);};
    };
};

#endif


#if  defined(VQBI_MTYPE)

typedef      VQBI_MTYPE Qbi;

struct Qbi1 {
    union {
#   if defined(VQBI_M1TYPE)
        VQBI_M1TYPE   M;
#   endif
        struct {VQBI_MTYPE MY_NV1(V,);};
    };
};

struct Qbi2 {
    union {
#   if defined(VQBI_M2TYPE)
        VQBI_M2TYPE   M;
#   endif
        struct {VQBI_MTYPE MY_NV2(V,);};
    };
};

struct Qbi3 {
    union {
#   if defined(VQBI_M3TYPE)
        VQBI_M3TYPE   M;
#   endif
        struct {VQBI_MTYPE MY_NV3(V,);};
    };
};

struct Qbi4 {
    union {
#   if defined(VQBI_M4TYPE)
        VQBI_M4TYPE   M;
#   endif
        struct {VQBI_MTYPE MY_NV4(V,);};
    };
};

#endif


#if  defined(VQBC_MTYPE)

typedef      VQBC_MTYPE Qbc;

struct Qbc1 {
    union {
#   if defined(VQBC_M1TYPE)
        VQBC_M1TYPE   M;
#   endif
        struct {VQBC_MTYPE MY_NV1(V,);};
    };
};

struct Qbc2 {
    union {
#   if defined(VQBC_M2TYPE)
        VQBC_M2TYPE   M;
#   endif
        struct {VQBC_MTYPE MY_NV2(V,);};
    };
};

struct Qbc3 {
    union {
#   if defined(VQBC_M3TYPE)
        VQBC_M3TYPE   M;
#   endif
        struct {VQBC_MTYPE MY_NV3(V,);};
    };
};

struct Qbc4 {
    union {
#   if defined(VQBC_M4TYPE)
        VQBC_M4TYPE   M;
#   endif
        struct {VQBC_MTYPE MY_NV4(V,);};
    };
};

#endif


#if  defined(VQHU_MTYPE)
typedef      VQHU_MTYPE Qhu;
struct Qhu1 {
    union {
#   if defined(VQHU_M1TYPE)
        VQHU_M1TYPE   M;
#   endif
        struct {VQHU_MTYPE MY_NV1(V,);};
    };
};
struct Qhu2 {
    union {
#   if defined(VQHU_M2TYPE)
        VQHU_M2TYPE   M;
#   endif
        struct {VQHU_MTYPE MY_NV2(V,);};
    };
};
struct Qhu3 {
    union {
#   if defined(VQHU_M3TYPE)
        VQHU_M3TYPE   M;
#   endif
        struct {VQHU_MTYPE MY_NV3(V,);};
    };
};
struct Qhu4 {
    union {
#   if defined(VQHU_M4TYPE)
        VQHU_M4TYPE   M;
#   endif
        struct {VQHU_MTYPE MY_NV4(V,);};
    };
};
#endif


#if  defined(VQHI_MTYPE)
typedef      VQHI_MTYPE Qhi;
struct Qhi1 {
    union {
#   if defined(VQHI_M1TYPE)
        VQHI_M1TYPE   M;
#   endif
        struct {VQHI_MTYPE MY_NV1(V,);};
    };
};
struct Qhi2 {
    union {
#   if defined(VQHI_M2TYPE)
        VQHI_M2TYPE   M;
#   endif
        struct {VQHI_MTYPE MY_NV2(V,);};
    };
};
struct Qhi3 {
    union {
#   if defined(VQHI_M3TYPE)
        VQHI_M3TYPE   M;
#   endif
        struct {VQHI_MTYPE MY_NV3(V,);};
    };
};
struct Qhi4 {
    union {
#   if defined(VQHI_M4TYPE)
        VQHI_M4TYPE   M;
#   endif
        struct {VQHI_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VQHF_MTYPE)
typedef      VQHF_MTYPE Qhf;
struct Qhf1 {
    union {
#   if defined(VQHF_M1TYPE)
        VQHF_M1TYPE   M;
#   endif
        struct {VQHF_MTYPE MY_NV1(V,);};
    };
};
struct Qhf2 {
    union {
#   if defined(VQHF_M2TYPE)
        VQHF_M2TYPE   M;
#   endif
        struct {VQHF_MTYPE MY_NV2(V,);};
    };
};
struct Qhf3 {
    union {
#   if defined(VQHF_M3TYPE)
        VQHF_M3TYPE   M;
#   endif
        struct {VQHF_MTYPE MY_NV3(V,);};
    };
};
struct Qhf4 {
    union {
#   if defined(VQHF_M4TYPE)
        VQHF_M4TYPE   M;
#   endif
        struct {VQHF_MTYPE MY_NV4(V,);};
    };
};
#endif


#if  defined(VQWU_MTYPE)
typedef      VQWU_MTYPE Qwu;
struct Qwu1 {
    union {
#   if defined(VQWU_M1TYPE)
        VQWU_M1TYPE   M;
#   endif
        struct {VQWU_MTYPE MY_NV1(V,);};
    };
};
struct Qwu2 {
    union {
#   if defined(VQWU_M2TYPE)
        VQWU_M2TYPE   M;
#   endif
        struct {VQWU_MTYPE MY_NV2(V,);};
    };
};
struct Qwu3 {
    union {
#   if defined(VQWU_M3TYPE)
        VQWU_M3TYPE   M;
#   endif
        struct {VQWU_MTYPE MY_NV3(V,);};
    };
};
struct Qwu4 {
    union {
#   if defined(VQWU_M4TYPE)
        VQWU_M4TYPE   M;
#   endif
        struct {VQWU_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VQWI_MTYPE)
typedef      VQWI_MTYPE Qwi;
struct Qwi1 {
    union {
#   if defined(VQWI_M1TYPE)
        VQWI_M1TYPE   M;
#   endif
        struct {VQWI_MTYPE MY_NV1(V,);};
    };
};
struct Qwi2 {
    union {
#   if defined(VQWI_M2TYPE)
        VQWI_M2TYPE   M;
#   endif
        struct {VQWI_MTYPE MY_NV2(V,);};
    };
};
struct Qwi3 {
    union {
#   if defined(VQWI_M3TYPE)
        VQWI_M3TYPE   M;
#   endif
        struct {VQWI_MTYPE MY_NV3(V,);};
    };
};
struct Qwi4 {
    union {
#   if defined(VQWI_M4TYPE)
        VQWI_M4TYPE   M;
#   endif
        struct {VQWI_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VQWF_MTYPE)
typedef      VQWF_MTYPE Qwf;
struct Qwf1 {
    union {
#   if defined(VQWF_M1TYPE)
        VQWF_M1TYPE   M;
#   endif
        struct {VQWF_MTYPE MY_NV1(V,);};
    };
};
struct Qwf2 {
    union {
#   if defined(VQWF_M2TYPE)
        VQWF_M2TYPE   M;
#   endif
        struct {VQWF_MTYPE MY_NV2(V,);};
    };
};
struct Qwf3 {
    union {
#   if defined(VQWF_M3TYPE)
        VQWF_M3TYPE   M;
#   endif
        struct {VQWF_MTYPE MY_NV3(V,);};
    };
};
struct Qwf4 {
    union {
#   if defined(VQWF_M4TYPE)
        VQWF_M4TYPE   M;
#   endif
        struct {VQWF_MTYPE MY_NV4(V,);};
    };
};
#endif


#if  defined(VQDU_MTYPE)
typedef      VQDU_MTYPE Qdu;
struct Qdu1 {
    union {
#   if defined(VQDU_M1TYPE)
        VQDU_M1TYPE   M;
#   endif
        struct {VQDU_MTYPE MY_NV1(V,);};
    };
};
struct Qdu2 {
    union {
#   if defined(VQDU_M2TYPE)
        VQDU_M2TYPE   M;
#   endif
        struct {VQDU_MTYPE MY_NV2(V,);};
    };
};
struct Qdu3 {
    union {
#   if defined(VQDU_M3TYPE)
        VQDU_M3TYPE   M;
#   endif
        struct {VQDU_MTYPE MY_NV3(V,);};
    };
};
struct Qdu4 {
    union {
#   if defined(VQDU_M4TYPE)
        VQDU_M4TYPE   M;
#   endif
        struct {VQDU_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VQDI_MTYPE)
typedef      VQDI_MTYPE Qdi;
struct Qdi1 {
    union {
#   if defined(VQDI_M1TYPE)
        VQDI_M1TYPE   M;
#   endif
        struct {VQDI_MTYPE MY_NV1(V,);};
    };
};
struct Qdi2 {
    union {
#   if defined(VQDI_M2TYPE)
        VQDI_M2TYPE   M;
#   endif
        struct {VQDI_MTYPE MY_NV2(V,);};
    };
};
struct Qdi3 {
    union {
#   if defined(VQDI_M3TYPE)
        VQDI_M3TYPE   M;
#   endif
        struct {VQDI_MTYPE MY_NV3(V,);};
    };
};
struct Qdi4 {
    union {
#   if defined(VQDI_M4TYPE)
        VQDI_M4TYPE   M;
#   endif
        struct {VQDI_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VQDF_MTYPE)
typedef      VQDF_MTYPE Qdf;
struct Qdf1 {
    union {
#   if defined(VQDF_M1TYPE)
        VQDF_M1TYPE   M;
#   endif
        struct {VQDF_MTYPE MY_NV1(V,);};
    };
};
struct Qdf2 {
    union {
#   if defined(VQDF_M2TYPE)
        VQDF_M2TYPE   M;
#   endif
        struct {VQDF_MTYPE MY_NV2(V,);};
    };
};
struct Qdf3 {
    union {
#   if defined(VQDF_M3TYPE)
        VQDF_M3TYPE   M;
#   endif
        struct {VQDF_MTYPE MY_NV3(V,);};
    };
};
struct Qdf4 {
    union {
#   if defined(VQDF_M4TYPE)
        VQDF_M4TYPE   M;
#   endif
        struct {VQDF_MTYPE MY_NV4(V,);};
    };
};
#endif


#if defined(TST_HA_V128_SIZES)

#   if 0
//      <ENTERTST=HA_V128_SIZES>
    {
#   endif

#   if defined(VQBU_MTYPE)
ASSERT(0x10 == sizeof(       Qbu));
ASSERT(0x10 == sizeof(struct Qbu1));
ASSERT(0x20 == sizeof(struct Qbu2));
ASSERT(0x30 == sizeof(struct Qbu3));
ASSERT(0x40 == sizeof(struct Qbu4));
#   endif

#   if defined(VQBI_MTYPE)
ASSERT(0x10 == sizeof(       Qbi));
ASSERT(0x10 == sizeof(struct Qbi1));
ASSERT(0x20 == sizeof(struct Qbi2));
ASSERT(0x30 == sizeof(struct Qbi3));
ASSERT(0x40 == sizeof(struct Qbi4));
#   endif

#   if defined(VQHU_MTYPE)
ASSERT(0x10 == sizeof(       Qhu));
ASSERT(0x10 == sizeof(struct Qhu1));
ASSERT(0x20 == sizeof(struct Qhu2));
ASSERT(0x30 == sizeof(struct Qhu3));
ASSERT(0x40 == sizeof(struct Qhu4));
#   endif

#   if defined(VQHI_MTYPE)
ASSERT(0x10 == sizeof(       Qhi));
ASSERT(0x10 == sizeof(struct Qhi1));
ASSERT(0x20 == sizeof(struct Qhi2));
ASSERT(0x30 == sizeof(struct Qhi3));
ASSERT(0x40 == sizeof(struct Qhi4));
#   endif

#   if defined(VQHF_MTYPE)
ASSERT(0x10 == sizeof(       Qhf));
ASSERT(0x10 == sizeof(struct Qhf1));
ASSERT(0x20 == sizeof(struct Qhf2));
ASSERT(0x30 == sizeof(struct Qhf3));
ASSERT(0x40 == sizeof(struct Qhf4));
#   endif


#   if defined(VQWU_MTYPE)
ASSERT(0x10 == sizeof(       Qwu));
ASSERT(0x10 == sizeof(struct Qwu1));
ASSERT(0x20 == sizeof(struct Qwu2));
ASSERT(0x30 == sizeof(struct Qwu3));
ASSERT(0x40 == sizeof(struct Qwu4));
#   endif

#   if defined(VQWI_MTYPE)
ASSERT(0x10 == sizeof(       Qwi));
ASSERT(0x10 == sizeof(struct Qwi1));
ASSERT(0x20 == sizeof(struct Qwi2));
ASSERT(0x30 == sizeof(struct Qwi3));
ASSERT(0x40 == sizeof(struct Qwi4));
#   endif

#   if defined(VQWF_MTYPE)
ASSERT(0x10 == sizeof(       Qwf));
ASSERT(0x10 == sizeof(struct Qwf1));
ASSERT(0x20 == sizeof(struct Qwf2));
ASSERT(0x30 == sizeof(struct Qwf3));
ASSERT(0x40 == sizeof(struct Qwf4));
#   endif


#   if defined(VQDU_MTYPE)
ASSERT(0x10 == sizeof(       Qdu));
ASSERT(0x10 == sizeof(struct Qdu1));
ASSERT(0x20 == sizeof(struct Qdu2));
ASSERT(0x30 == sizeof(struct Qdu3));
ASSERT(0x40 == sizeof(struct Qdu4));
#   endif

#   if defined(VQDI_MTYPE)
ASSERT(0x10 == sizeof(       Qdi));
ASSERT(0x10 == sizeof(struct Qdi1));
ASSERT(0x20 == sizeof(struct Qdi2));
ASSERT(0x30 == sizeof(struct Qdi3));
ASSERT(0x40 == sizeof(struct Qdi4));
#   endif

#   if defined(VQDF_MTYPE)
ASSERT(0x10 == sizeof(       Qdf));
ASSERT(0x10 == sizeof(struct Qdf1));
ASSERT(0x20 == sizeof(struct Qdf2));
ASSERT(0x30 == sizeof(struct Qdf3));
ASSERT(0x40 == sizeof(struct Qdf4));
#   endif

#   if 0
    }
//      <LEAVETST=HA_V128_SIZES>
#   endif

#endif // defined(TST_HA_V128_SIZES)

#if _LEAVE_EXTVEC_HQVA_REPR
}
#endif

#if _ENTER_EXTVEC_HOVA_REPR
{
#endif

#if  defined(VOYU_MTYPE)
typedef      VOYU_MTYPE Oyu;
struct Oyu1 {
    union {
#   if defined(VOYU_M1TYPE)
        VOYU_M1TYPE   M;
#   endif
        struct {VOYU_MTYPE MY_NV1(V,);};
    };
};
struct Oyu2 {
    union {
#   if defined(VOYU_M2TYPE)
        VOYU_M2TYPE   M;
#   endif
        struct {VOYU_MTYPE MY_NV2(V,);};
    };
};
struct Oyu3 {
    union {
#   if defined(VOYU_M3TYPE)
        VOYU_M3TYPE   M;
#   endif
        struct {VOYU_MTYPE MY_NV3(V,);};
    };
};
struct Oyu4 {
    union {
#   if defined(VOYU_M4TYPE)
        VOYU_M4TYPE   M;
#   endif
        struct {VOYU_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VOBU_MTYPE)
typedef      VOBU_MTYPE Obu;
struct Obu1 {
    union {
#   if defined(VOBU_M1TYPE)
        VOBU_M1TYPE   M;
#   endif
        struct {VOBU_MTYPE MY_NV1(V,);};
    };
};
struct Obu2 {
    union {
#   if defined(VOBU_M2TYPE)
        VOBU_M2TYPE   M;
#   endif
        struct {VOBU_MTYPE MY_NV2(V,);};
    };
};
struct Obu3 {
    union {
#   if defined(VOBU_M3TYPE)
        VOBU_M3TYPE   M;
#   endif
        struct {VOBU_MTYPE MY_NV3(V,);};
    };
};
struct Obu4 {
    union {
#   if defined(VOBU_M4TYPE)
        VOBU_M4TYPE   M;
#   endif
        struct {VOBU_MTYPE MY_NV4(V,);};
    };
};
#endif


#if  defined(VOBI_MTYPE)

typedef      VOBI_MTYPE Obi;

struct Obi1 {
    union {
#   if defined(VOBI_M1TYPE)
        VOBI_M1TYPE   M;
#   endif
        struct {VOBI_MTYPE MY_NV1(V,);};
    };
};

struct Obi2 {
    union {
#   if defined(VOBI_M2TYPE)
        VOBI_M2TYPE   M;
#   endif
        struct {VOBI_MTYPE MY_NV2(V,);};
    };
};

struct Obi3 {
    union {
#   if defined(VOBI_M3TYPE)
        VOBI_M3TYPE   M;
#   endif
        struct {VOBI_MTYPE MY_NV3(V,);};
    };
};

struct Obi4 {
    union {
#   if defined(VOBI_M4TYPE)
        VOBI_M4TYPE   M;
#   endif
        struct {VOBI_MTYPE MY_NV4(V,);};
    };
};

#endif


#if  defined(VOBC_MTYPE)

typedef      VOBC_MTYPE Obc;

struct Obc1 {
    union {
#   if defined(VOBC_M1TYPE)
        VOBC_M1TYPE   M;
#   endif
        struct {VOBC_MTYPE MY_NV1(V,);};
    };
};

struct Obc2 {
    union {
#   if defined(VOBC_M2TYPE)
        VOBC_M2TYPE   M;
#   endif
        struct {VOBC_MTYPE MY_NV2(V,);};
    };
};

struct Obc3 {
    union {
#   if defined(VOBC_M3TYPE)
        VOBC_M3TYPE   M;
#   endif
        struct {VOBC_MTYPE MY_NV3(V,);};
    };
};

struct Obc4 {
    union {
#   if defined(VOBC_M4TYPE)
        VOBC_M4TYPE   M;
#   endif
        struct {VOBC_MTYPE MY_NV4(V,);};
    };
};

#endif



#if  defined(VOHU_MTYPE)
typedef      VOHU_MTYPE Ohu;
struct Ohu1 {
    union {
#   if defined(VOHU_M1TYPE)
        VOHU_M1TYPE   M;
#   endif
        struct {VOHU_MTYPE MY_NV1(V,);};
    };
};
struct Ohu2 {
    union {
#   if defined(VOHU_M2TYPE)
        VOHU_M2TYPE   M;
#   endif
        struct {VOHU_MTYPE MY_NV2(V,);};
    };
};
struct Ohu3 {
    union {
#   if defined(VOHU_M3TYPE)
        VOHU_M3TYPE   M;
#   endif
        struct {VOHU_MTYPE MY_NV3(V,);};
    };
};
struct Ohu4 {
    union {
#   if defined(VOHU_M4TYPE)
        VOHU_M4TYPE   M;
#   endif
        struct {VOHU_MTYPE MY_NV4(V,);};
    };
};
#endif


#if  defined(VOHI_MTYPE)
typedef      VOHI_MTYPE Ohi;
struct Ohi1 {
    union {
#   if defined(VOHI_M1TYPE)
        VOHI_M1TYPE   M;
#   endif
        struct {VOHI_MTYPE MY_NV1(V,);};
    };
};
struct Ohi2 {
    union {
#   if defined(VOHI_M2TYPE)
        VOHI_M2TYPE   M;
#   endif
        struct {VOHI_MTYPE MY_NV2(V,);};
    };
};
struct Ohi3 {
    union {
#   if defined(VOHI_M3TYPE)
        VOHI_M3TYPE   M;
#   endif
        struct {VOHI_MTYPE MY_NV3(V,);};
    };
};
struct Ohi4 {
    union {
#   if defined(VOHI_M4TYPE)
        VOHI_M4TYPE   M;
#   endif
        struct {VOHI_MTYPE MY_NV4(V,);};
    };
};
#endif


#if  defined(VOHF_MTYPE)
typedef      VOHF_MTYPE Ohf;
struct Ohf1 {
    union {
#   if defined(VOHF_M1TYPE)
        VOHF_M1TYPE   M;
#   endif
        struct {VOHF_MTYPE MY_NV1(V,);};
    };
};
struct Ohf2 {
    union {
#   if defined(VOHF_M2TYPE)
        VOHF_M2TYPE   M;
#   endif
        struct {VOHF_MTYPE MY_NV2(V,);};
    };
};
struct Ohf3 {
    union {
#   if defined(VOHF_M3TYPE)
        VOHF_M3TYPE   M;
#   endif
        struct {VOHF_MTYPE MY_NV3(V,);};
    };
};
struct Ohf4 {
    union {
#   if defined(VOHF_M4TYPE)
        VOHF_M4TYPE   M;
#   endif
        struct {VOHF_MTYPE MY_NV4(V,);};
    };
};
#endif


#if  defined(VOWU_MTYPE)
typedef      VOWU_MTYPE Owu;
struct Owu1 {
    union {
#   if defined(VOWU_M1TYPE)
        VOWU_M1TYPE   M;
#   endif
        struct {VOWU_MTYPE MY_NV1(V,);};
    };
};
struct Owu2 {
    union {
#   if defined(VOWU_M2TYPE)
        VOWU_M2TYPE   M;
#   endif
        struct {VOWU_MTYPE MY_NV2(V,);};
    };
};
struct Owu3 {
    union {
#   if defined(VOWU_M3TYPE)
        VOWU_M3TYPE   M;
#   endif
        struct {VOWU_MTYPE MY_NV3(V,);};
    };
};
struct Owu4 {
    union {
#   if defined(VOWU_M4TYPE)
        VOWU_M4TYPE   M;
#   endif
        struct {VOWU_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VOWI_MTYPE)
typedef      VOWI_MTYPE Owi;
struct Owi1 {
    union {
#   if defined(VOWI_M1TYPE)
        VOWI_M1TYPE   M;
#   endif
        struct {VOWI_MTYPE MY_NV1(V,);};
    };
};
struct Owi2 {
    union {
#   if defined(VOWI_M2TYPE)
        VOWI_M2TYPE   M;
#   endif
        struct {VOWI_MTYPE MY_NV2(V,);};
    };
};
struct Owi3 {
    union {
#   if defined(VOWI_M3TYPE)
        VOWI_M3TYPE   M;
#   endif
        struct {VOWI_MTYPE MY_NV3(V,);};
    };
};
struct Owi4 {
    union {
#   if defined(VOWI_M4TYPE)
        VOWI_M4TYPE   M;
#   endif
        struct {VOWI_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VOWF_MTYPE)

typedef      VOWF_MTYPE Owf;

struct Owf1 {
    union {
#   if defined(VOWF_M1TYPE)
        VOWF_M1TYPE   M;
#   endif
        struct {VOWF_MTYPE MY_NV1(V,);};
    };
};
struct Owf2 {
    union {
#   if defined(VOWF_M2TYPE)
        VOWF_M2TYPE   M;
#   endif
        struct {VOWF_MTYPE MY_NV2(V,);};
    };
};
struct Owf3 {
    union {
#   if defined(VOWF_M3TYPE)
        VOWF_M3TYPE   M;
#   endif
        struct {VOWF_MTYPE MY_NV3(V,);};
    };
};
struct Owf4 {
    union {
#   if defined(VOWF_M4TYPE)
        VOWF_M4TYPE   M;
#   endif
        struct {VOWF_MTYPE MY_NV4(V,);};
    };
};

#endif


#if  defined(VODU_MTYPE)

typedef      VODU_MTYPE Odu;

struct Odu1 {
    union {
#   if defined(VODU_M1TYPE)
        VODU_M1TYPE   M;
#   endif
        struct {VODU_MTYPE MY_NV1(V,);};
    };
};
struct Odu2 {
    union {
#   if defined(VODU_M2TYPE)
        VODU_M2TYPE   M;
#   endif
        struct {VODU_MTYPE MY_NV2(V,);};
    };
};
struct Odu3 {
    union {
#   if defined(VODU_M3TYPE)
        VODU_M3TYPE   M;
#   endif
        struct {VODU_MTYPE MY_NV3(V,);};
    };
};
struct Odu4 {
    union {
#   if defined(VODU_M4TYPE)
        VODU_M4TYPE   M;
#   endif
        struct {VODU_MTYPE MY_NV4(V,);};
    };
};

#endif

#if  defined(VODI_MTYPE)

typedef      VODI_MTYPE Odi;

struct Odi1 {
    union {
#   if defined(VODI_M1TYPE)
        VODI_M1TYPE   M;
#   endif
        struct {VODI_MTYPE MY_NV1(V,);};
    };
};
struct Odi2 {
    union {
#   if defined(VODI_M2TYPE)
        VODI_M2TYPE   M;
#   endif
        struct {VODI_MTYPE MY_NV2(V,);};
    };
};
struct Odi3 {
    union {
#   if defined(VODI_M3TYPE)
        VODI_M3TYPE   M;
#   endif
        struct {VODI_MTYPE MY_NV3(V,);};
    };
};
struct Odi4 {
    union {
#   if defined(VODI_M4TYPE)
        VODI_M4TYPE   M;
#   endif
        struct {VODI_MTYPE MY_NV4(V,);};
    };
};

#endif

#if  defined(VODF_MTYPE)

typedef      VODF_MTYPE Odf;

struct Odf1 {
    union {
#   if defined(VODF_M1TYPE)
        VODF_M1TYPE   M;
#   endif
        struct {VODF_MTYPE MY_NV1(V,);};
    };
};
struct Odf2 {
    union {
#   if defined(VODF_M2TYPE)
        VODF_M2TYPE   M;
#   endif
        struct {VODF_MTYPE MY_NV2(V,);};
    };
};
struct Odf3 {
    union {
#   if defined(VODF_M3TYPE)
        VODF_M3TYPE   M;
#   endif
        struct {VODF_MTYPE MY_NV3(V,);};
    };
};
struct Odf4 {
    union {
#   if defined(VODF_M4TYPE)
        VODF_M4TYPE   M;
#   endif
        struct {VODF_MTYPE MY_NV4(V,);};
    };
};

#endif

#if _ENTER_EXTVEC_HOVA_REPR_TEST
{
#endif

#ifdef TST_HA_V256_SIZES
#ifdef VOBU_MTYPE
ASSERT((1*32) == sizeof(       Obu));
ASSERT((1*32) == sizeof(struct Obu1));
ASSERT((2*32) == sizeof(struct Obu2));
ASSERT((3*32) == sizeof(struct Obu3));
ASSERT((4*32) == sizeof(struct Obu4));
#endif

#   if defined(VOBI_MTYPE)
ASSERT((1*32) == sizeof(       Obi));
ASSERT((1*32) == sizeof(struct Obi1));
ASSERT((2*32) == sizeof(struct Obi2));
ASSERT((3*32) == sizeof(struct Obi3));
ASSERT((4*32) == sizeof(struct Obi4));
#   endif


#   if defined(VOHU_MTYPE)
ASSERT((1*32) == sizeof(       Ohu));
ASSERT((1*32) == sizeof(struct Ohu1));
ASSERT((2*32) == sizeof(struct Ohu2));
ASSERT((3*32) == sizeof(struct Ohu3));
ASSERT((4*32) == sizeof(struct Ohu4));
#   endif

#   if defined(VOHI_MTYPE)
ASSERT((1*32) == sizeof(       Ohi));
ASSERT((1*32) == sizeof(struct Ohi1));
ASSERT((2*32) == sizeof(struct Ohi2));
ASSERT((3*32) == sizeof(struct Ohi3));
ASSERT((4*32) == sizeof(struct Ohi4));
#   endif

#   if defined(VOHF_MTYPE)
ASSERT((1*32) == sizeof(       Ohf));
ASSERT((1*32) == sizeof(struct Ohf1));
ASSERT((2*32) == sizeof(struct Ohf2));
ASSERT((3*32) == sizeof(struct Ohf3));
ASSERT((4*32) == sizeof(struct Ohf4));
#   endif


#   if defined(VOWU_MTYPE)
ASSERT((1*32) == sizeof(       Owu));
ASSERT((1*32) == sizeof(struct Owu1));
ASSERT((2*32) == sizeof(struct Owu2));
ASSERT((3*32) == sizeof(struct Owu3));
ASSERT((4*32) == sizeof(struct Owu4));
#   endif

#   if defined(VOWI_MTYPE)
ASSERT((1*32) == sizeof(       Owi));
ASSERT((1*32) == sizeof(struct Owi1));
ASSERT((2*32) == sizeof(struct Owi2));
ASSERT((3*32) == sizeof(struct Owi3));
ASSERT((4*32) == sizeof(struct Owi4));
#   endif

#   if defined(VOWF_MTYPE)
ASSERT((1*32) == sizeof(       Owf));
ASSERT((1*32) == sizeof(struct Owf1));
ASSERT((2*32) == sizeof(struct Owf2));
ASSERT((3*32) == sizeof(struct Owf3));
ASSERT((4*32) == sizeof(struct Owf4));
#   endif

#   if defined(VODU_MTYPE)
ASSERT((1*32) == sizeof(       Odu));
ASSERT((1*32) == sizeof(struct Odu1));
ASSERT((2*32) == sizeof(struct Odu2));
ASSERT((3*32) == sizeof(struct Odu3));
ASSERT((4*32) == sizeof(struct Odu4));
#   endif

#   if defined(VODI_MTYPE)
ASSERT((1*32) == sizeof(       Odi));
ASSERT((1*32) == sizeof(struct Odi1));
ASSERT((2*32) == sizeof(struct Odi2));
ASSERT((3*32) == sizeof(struct Odi3));
ASSERT((4*32) == sizeof(struct Odi4));
#   endif

#   if defined(VODF_MTYPE)
ASSERT((1*32) == sizeof(       Odf));
ASSERT((1*32) == sizeof(struct Odf1));
ASSERT((2*32) == sizeof(struct Odf2));
ASSERT((3*32) == sizeof(struct Odf3));
ASSERT((4*32) == sizeof(struct Odf4));
#   endif

#endif // defined(TST_HA_V256_SIZES)

#if _LEAVE_EXTVEC_HOVA_REPR_TEST
}
#endif


#if _LEAVE_EXTVEC_HOVA_REPR
}
#endif

#if _ENTER_EXTVEC_HSVA_REPR
{
#endif

#if  defined(VSYU_MTYPE)
typedef      VSYU_MTYPE Syu;
struct Syu1 {
    union {
#   if defined(VSYU_M1TYPE)
        VSYU_M1TYPE   M;
#   endif
        struct {VSYU_MTYPE MY_NV1(V,);};
    };
};
struct Syu2 {
    union {
#   if defined(VSYU_M2TYPE)
        VSYU_M2TYPE   M;
#   endif
        struct {VSYU_MTYPE MY_NV2(V,);};
    };
};
struct Syu3 {
    union {
#   if defined(VSYU_M3TYPE)
        VSYU_M3TYPE   M;
#   endif
        struct {VSYU_MTYPE MY_NV3(V,);};
    };
};
struct Syu4 {
    union {
#   if defined(VSYU_M4TYPE)
        VSYU_M4TYPE   M;
#   endif
        struct {VSYU_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VSBU_MTYPE)
typedef      VSBU_MTYPE Sbu;
struct Sbu1 {
    union {
#   if defined(VSBU_M1TYPE)
        VSBU_M1TYPE   M;
#   endif
        struct {VSBU_MTYPE MY_NV1(V,);};
    };
};
struct Sbu2 {
    union {
#   if defined(VSBU_M2TYPE)
        VSBU_M2TYPE   M;
#   endif
        struct {VSBU_MTYPE MY_NV2(V,);};
    };
};
struct Sbu3 {
    union {
#   if defined(VSBU_M3TYPE)
        VSBU_M3TYPE   M;
#   endif
        struct {VSBU_MTYPE MY_NV3(V,);};
    };
};
struct Sbu4 {
    union {
#   if defined(VSBU_M4TYPE)
        VSBU_M4TYPE   M;
#   endif
        struct {VSBU_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VSBI_MTYPE)
typedef      VSBI_MTYPE Sbi;
struct Sbi1 {
    union {
#   if defined(VSBI_M1TYPE)
        VSBI_M1TYPE   M;
#   endif
        struct {VSBI_MTYPE MY_NV1(V,);};
    };
};
struct Sbi2 {
    union {
#   if defined(VSBI_M2TYPE)
        VSBI_M2TYPE   M;
#   endif
        struct {VSBI_MTYPE MY_NV2(V,);};
    };
};
struct Sbi3 {
    union {
#   if defined(VSBI_M3TYPE)
        VSBI_M3TYPE   M;
#   endif
        struct {VSBI_MTYPE MY_NV3(V,);};
    };
};
struct Sbi4 {
    union {
#   if defined(VSBI_M4TYPE)
        VSBI_M4TYPE   M;
#   endif
        struct {VSBI_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VSBC_MTYPE)
typedef      VSBC_MTYPE Sbc;
struct Sbc1 {
    union {
#   if defined(VSBC_M1TYPE)
        VSBC_M1TYPE   M;
#   endif
        struct {VSBC_MTYPE MY_NV1(V,);};
    };
};
struct Sbc2 {
    union {
#   if defined(VSBC_M2TYPE)
        VSBC_M2TYPE   M;
#   endif
        struct {VSBC_MTYPE MY_NV2(V,);};
    };
};
struct Sbc3 {
    union {
#   if defined(VSBC_M3TYPE)
        VSBC_M3TYPE   M;
#   endif
        struct {VSBC_MTYPE MY_NV3(V,);};
    };
};
struct Sbc4 {
    union {
#   if defined(VSBC_M4TYPE)
        VSBC_M4TYPE   M;
#   endif
        struct {VSBC_MTYPE MY_NV4(V,);};
    };
};
#endif


#if  defined(VSHU_MTYPE)
typedef      VSHU_MTYPE Shu;
struct Shu1 {
    union {
#   if defined(VSHU_M1TYPE)
        VSHU_M1TYPE   M;
#   endif
        struct {VSHU_MTYPE MY_NV1(V,);};
    };
};
struct Shu2 {
    union {
#   if defined(VSHU_M2TYPE)
        VSHU_M2TYPE   M;
#   endif
        struct {VSHU_MTYPE MY_NV2(V,);};
    };
};
struct Shu3 {
    union {
#   if defined(VSHU_M3TYPE)
        VSHU_M3TYPE   M;
#   endif
        struct {VSHU_MTYPE MY_NV3(V,);};
    };
};
struct Shu4 {
    union {
#   if defined(VSHU_M4TYPE)
        VSHU_M4TYPE   M;
#   endif
        struct {VSHU_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VSHI_MTYPE)
typedef      VSHI_MTYPE Shi;
struct Shi1 {
    union {
#   if defined(VSHI_M1TYPE)
        VSHI_M1TYPE   M;
#   endif
        struct {VSHI_MTYPE MY_NV1(V,);};
    };
};
struct Shi2 {
    union {
#   if defined(VSHI_M2TYPE)
        VSHI_M2TYPE   M;
#   endif
        struct {VSHI_MTYPE MY_NV2(V,);};
    };
};
struct Shi3 {
    union {
#   if defined(VSHI_M3TYPE)
        VSHI_M3TYPE   M;
#   endif
        struct {VSHI_MTYPE MY_NV3(V,);};
    };
};
struct Shi4 {
    union {
#   if defined(VSHI_M4TYPE)
        VSHI_M4TYPE   M;
#   endif
        struct {VSHI_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VSHF_MTYPE)
typedef      VSHF_MTYPE Shf;
struct Shf1 {
    union {
#   if defined(VSHF_M1TYPE)
        VSHF_M1TYPE   M;
#   endif
        struct {VSHF_MTYPE MY_NV1(V,);};
    };
};
struct Shf2 {
    union {
#   if defined(VSHF_M2TYPE)
        VSHF_M2TYPE   M;
#   endif
        struct {VSHF_MTYPE MY_NV2(V,);};
    };
};
struct Shf3 {
    union {
#   if defined(VSHF_M3TYPE)
        VSHF_M3TYPE   M;
#   endif
        struct {VSHF_MTYPE MY_NV3(V,);};
    };
};
struct Shf4 {
    union {
#   if defined(VSHF_M4TYPE)
        VSHF_M4TYPE   M;
#   endif
        struct {VSHF_MTYPE MY_NV4(V,);};
    };
};
#endif


#if  defined(VSWU_MTYPE)
typedef      VSWU_MTYPE Swu;
struct Swu1 {
    union {
#   if defined(VSWU_M1TYPE)
        VSWU_M1TYPE   M;
#   endif
        struct {VSWU_MTYPE MY_NV1(V,);};
    };
};
struct Swu2 {
    union {
#   if defined(VSWU_M2TYPE)
        VSWU_M2TYPE   M;
#   endif
        struct {VSWU_MTYPE MY_NV2(V,);};
    };
};
struct Swu3 {
    union {
#   if defined(VSWU_M3TYPE)
        VSWU_M3TYPE   M;
#   endif
        struct {VSWU_MTYPE MY_NV3(V,);};
    };
};
struct Swu4 {
    union {
#   if defined(VSWU_M4TYPE)
        VSWU_M4TYPE   M;
#   endif
        struct {VSWU_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VSWI_MTYPE)
typedef      VSWI_MTYPE Swi;
struct Swi1 {
    union {
#   if defined(VSWI_M1TYPE)
        VSWI_M1TYPE   M;
#   endif
        struct {VSWI_MTYPE MY_NV1(V,);};
    };
};
struct Swi2 {
    union {
#   if defined(VSWI_M2TYPE)
        VSWI_M2TYPE   M;
#   endif
        struct {VSWI_MTYPE MY_NV2(V,);};
    };
};
struct Swi3 {
    union {
#   if defined(VSWI_M3TYPE)
        VSWI_M3TYPE   M;
#   endif
        struct {VSWI_MTYPE MY_NV3(V,);};
    };
};
struct Swi4 {
    union {
#   if defined(VSWI_M4TYPE)
        VSWI_M4TYPE   M;
#   endif
        struct {VSWI_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VSWF_MTYPE)
typedef      VSWF_MTYPE Swf;
struct Swf1 {
    union {
#   if defined(VSWF_M1TYPE)
        VSWF_M1TYPE   M;
#   endif
        struct {VSWF_MTYPE MY_NV1(V,);};
    };
};
struct Swf2 {
    union {
#   if defined(VSWF_M2TYPE)
        VSWF_M2TYPE   M;
#   endif
        struct {VSWF_MTYPE MY_NV2(V,);};
    };
};
struct Swf3 {
    union {
#   if defined(VSWF_M3TYPE)
        VSWF_M3TYPE   M;
#   endif
        struct {VSWF_MTYPE MY_NV3(V,);};
    };
};
struct Swf4 {
    union {
#   if defined(VSWF_M4TYPE)
        VSWF_M4TYPE   M;
#   endif
        struct {VSWF_MTYPE MY_NV4(V,);};
    };
};
#endif


#if  defined(VSDU_MTYPE)
typedef      VSDU_MTYPE Sdu;
struct Sdu1 {
    union {
#   if defined(VSDU_M1TYPE)
        VSDU_M1TYPE   M;
#   endif
        struct {VSDU_MTYPE MY_NV1(V,);};
    };
};
struct Sdu2 {
    union {
#   if defined(VSDU_M2TYPE)
        VSDU_M2TYPE   M;
#   endif
        struct {VSDU_MTYPE MY_NV2(V,);};
    };
};
struct Sdu3 {
    union {
#   if defined(VSDU_M3TYPE)
        VSDU_M3TYPE   M;
#   endif
        struct {VSDU_MTYPE MY_NV3(V,);};
    };
};
struct Sdu4 {
    union {
#   if defined(VSDU_M4TYPE)
        VSDU_M4TYPE   M;
#   endif
        struct {VSDU_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VSDI_MTYPE)
typedef      VSDI_MTYPE Sdi;
struct Sdi1 {
    union {
#   if defined(VSDI_M1TYPE)
        VSDI_M1TYPE   M;
#   endif
        struct {VSDI_MTYPE MY_NV1(V,);};
    };
};
struct Sdi2 {
    union {
#   if defined(VSDI_M2TYPE)
        VSDI_M2TYPE   M;
#   endif
        struct {VSDI_MTYPE MY_NV2(V,);};
    };
};
struct Sdi3 {
    union {
#   if defined(VSDI_M3TYPE)
        VSDI_M3TYPE   M;
#   endif
        struct {VSDI_MTYPE MY_NV3(V,);};
    };
};
struct Sdi4 {
    union {
#   if defined(VSDI_M4TYPE)
        VSDI_M4TYPE   M;
#   endif
        struct {VSDI_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VSDF_MTYPE)
typedef      VSDF_MTYPE Sdf;
struct Sdf1 {
    union {
#   if defined(VSDF_M1TYPE)
        VSDF_M1TYPE   M;
#   endif
        struct {VSDF_MTYPE MY_NV1(V,);};
    };
};
struct Sdf2 {
    union {
#   if defined(VSDF_M2TYPE)
        VSDF_M2TYPE   M;
#   endif
        struct {VSDF_MTYPE MY_NV2(V,);};
    };
};
struct Sdf3 {
    union {
#   if defined(VSDF_M3TYPE)
        VSDF_M3TYPE   M;
#   endif
        struct {VSDF_MTYPE MY_NV3(V,);};
    };
};
struct Sdf4 {
    union {
#   if defined(VSDF_M4TYPE)
        VSDF_M4TYPE   M;
#   endif
        struct {VSDF_MTYPE MY_NV4(V,);};
    };
};
#endif

#if defined(TST_HA_V512_SIZES)

#   if 0
//      <ENTERTST=HA_V512_SIZES>
    {
#   endif

#   if defined(VSBU_MTYPE)
ASSERT((1*64) == sizeof(       Sbu));
ASSERT((1*64) == sizeof(struct Sbu1));
ASSERT((2*64) == sizeof(struct Sbu2));
ASSERT((3*64) == sizeof(struct Sbu3));
ASSERT((4*64) == sizeof(struct Sbu4));
#   endif

#   if defined(VSBI_MTYPE)
ASSERT((1*64) == sizeof(       Sbi));
ASSERT((1*64) == sizeof(struct Sbi1));
ASSERT((2*64) == sizeof(struct Sbi2));
ASSERT((3*64) == sizeof(struct Sbi3));
ASSERT((4*64) == sizeof(struct Sbi4));
#   endif


#   if defined(VSHU_MTYPE)
ASSERT((1*64) == sizeof(       Shu));
ASSERT((1*64) == sizeof(struct Shu1));
ASSERT((2*64) == sizeof(struct Shu2));
ASSERT((3*64) == sizeof(struct Shu3));
ASSERT((4*64) == sizeof(struct Shu4));
#   endif

#   if defined(VSHI_MTYPE)
ASSERT((1*64) == sizeof(       Shi));
ASSERT((1*64) == sizeof(struct Shi1));
ASSERT((2*64) == sizeof(struct Shi2));
ASSERT((3*64) == sizeof(struct Shi3));
ASSERT((4*64) == sizeof(struct Shi4));
#   endif

#   if defined(VSHF_MTYPE)
ASSERT((1*64) == sizeof(       Shf));
ASSERT((1*64) == sizeof(struct Shf1));
ASSERT((2*64) == sizeof(struct Shf2));
ASSERT((3*64) == sizeof(struct Shf3));
ASSERT((4*64) == sizeof(struct Shf4));
#   endif


#   if defined(VSWU_MTYPE)
ASSERT((1*64) == sizeof(       Swu));
ASSERT((1*64) == sizeof(struct Swu1));
ASSERT((2*64) == sizeof(struct Swu2));
ASSERT((3*64) == sizeof(struct Swu3));
ASSERT((4*64) == sizeof(struct Swu4));
#   endif

#   if defined(VSWI_MTYPE)
ASSERT((1*64) == sizeof(       Swi));
ASSERT((1*64) == sizeof(struct Swi1));
ASSERT((2*64) == sizeof(struct Swi2));
ASSERT((3*64) == sizeof(struct Swi3));
ASSERT((4*64) == sizeof(struct Swi4));
#   endif

#   if defined(VSWF_MTYPE)
ASSERT((1*64) == sizeof(       Swf));
ASSERT((1*64) == sizeof(struct Swf1));
ASSERT((2*64) == sizeof(struct Swf2));
ASSERT((3*64) == sizeof(struct Swf3));
ASSERT((4*64) == sizeof(struct Swf4));
#   endif


#   if defined(VSDU_MTYPE)
ASSERT((1*64) == sizeof(       Sdu));
ASSERT((1*64) == sizeof(struct Sdu1));
ASSERT((2*64) == sizeof(struct Sdu2));
ASSERT((3*64) == sizeof(struct Sdu3));
ASSERT((4*64) == sizeof(struct Sdu4));
#   endif

#   if defined(VSDI_MTYPE)
ASSERT((1*64) == sizeof(       Sdi));
ASSERT((1*64) == sizeof(struct Sdi1));
ASSERT((2*64) == sizeof(struct Sdi2));
ASSERT((3*64) == sizeof(struct Sdi3));
ASSERT((4*64) == sizeof(struct Sdi4));
#   endif

#   if defined(VSDF_MTYPE)
ASSERT((1*64) == sizeof(       Sdf));
ASSERT((1*64) == sizeof(struct Sdf1));
ASSERT((2*64) == sizeof(struct Sdf2));
ASSERT((3*64) == sizeof(struct Sdf3));
ASSERT((4*64) == sizeof(struct Sdf4));
#   endif

#   if 0
    }
//      <LEAVETST=HA_V512_SIZES>
#   endif

#endif // defined(TST_HA_V512_SIZES)

#if _LEAVE_EXTVEC_HSVA_REPR
}
#endif

#if _ENTER_EXTVEC_TYPEDEFS
{
#endif

typedef VWYU_TYPE   Vwyu;
typedef VDYU_TYPE   Vdyu;
typedef VQYU_TYPE   Vqyu;
typedef VOYU_TYPE   Voyu;
typedef VSYU_TYPE   Vsyu;

typedef VWBU_TYPE   Vwbu;
typedef VWBI_TYPE   Vwbi;
typedef VWBC_TYPE   Vwbc;
typedef VWHU_TYPE   Vwhu;
typedef VWHI_TYPE   Vwhi;
typedef VWHF_TYPE   Vwhf;
typedef VWWU_TYPE   Vwwu;
typedef VWWI_TYPE   Vwwi;
typedef VWWF_TYPE   Vwwf;

typedef VDBU_TYPE   Vdbu;
typedef VDBI_TYPE   Vdbi;
typedef VDBC_TYPE   Vdbc;
typedef VDHU_TYPE   Vdhu;
typedef VDHI_TYPE   Vdhi;
typedef VDHF_TYPE   Vdhf;
typedef VDWU_TYPE   Vdwu;
typedef VDWI_TYPE   Vdwi;
typedef VDWF_TYPE   Vdwf;
typedef VDDU_TYPE   Vddu;
typedef VDDI_TYPE   Vddi;
typedef VDDF_TYPE   Vddf;

typedef VQBU_TYPE   Vqbu;
typedef VQBI_TYPE   Vqbi;
typedef VQBC_TYPE   Vqbc;
typedef VQHU_TYPE   Vqhu;
typedef VQHI_TYPE   Vqhi;
typedef VQHF_TYPE   Vqhf;
typedef VQWU_TYPE   Vqwu;
typedef VQWI_TYPE   Vqwi;
typedef VQWF_TYPE   Vqwf;
typedef VQDU_TYPE   Vqdu;
typedef VQDI_TYPE   Vqdi;
typedef VQDF_TYPE   Vqdf;

typedef VOBU_TYPE   Vobu;
typedef VOBI_TYPE   Vobi;
typedef VOBC_TYPE   Vobc;
typedef VOHU_TYPE   Vohu;
typedef VOHI_TYPE   Vohi;
typedef VOHF_TYPE   Vohf;
typedef VOWU_TYPE   Vowu;
typedef VOWI_TYPE   Vowi;
typedef VOWF_TYPE   Vowf;
typedef VODU_TYPE   Vodu;
typedef VODI_TYPE   Vodi;
typedef VODF_TYPE   Vodf;

typedef VSBU_TYPE   Vsbu;
typedef VSBI_TYPE   Vsbi;
typedef VSBC_TYPE   Vsbc;
typedef VSHU_TYPE   Vshu;
typedef VSHI_TYPE   Vshi;
typedef VSHF_TYPE   Vshf;
typedef VSWU_TYPE   Vswu;
typedef VSWI_TYPE   Vswi;
typedef VSWF_TYPE   Vswf;
typedef VSDU_TYPE   Vsdu;
typedef VSDI_TYPE   Vsdi;
typedef VSDF_TYPE   Vsdf;

typedef union Vwba {Bu U[ 4]; Bi I[ 4]; Bc C[ 4];} Vwba;
typedef union Vwha {Hu U[ 2]; Hi I[ 2]; Hf F[ 2];} Vwha;
typedef union Vwwa {Wu U[ 1]; Wi I[ 1]; Wf F[ 1];} Vwwa;

typedef union Vdba {Bu U[ 8]; Bi I[ 8]; Bc C[ 8];} Vdba;
typedef union Vdha {Hu U[ 4]; Hi I[ 4]; Hf F[ 4];} Vdha;
typedef union Vdwa {Wu U[ 2]; Wi I[ 2]; Wf F[ 2];} Vdwa;
typedef union Vdda {Du U[ 1]; Di I[ 1]; Df F[ 1];} Vdda;

typedef union Vqba {Bu U[16]; Bi I[16]; Bc C[16];} Vqba;
typedef union Vqha {Hu U[ 8]; Hi I[ 8]; Hf F[ 8];} Vqha;
typedef union Vqwa {Wu U[ 4]; Wi I[ 4]; Wf F[ 4];} Vqwa;
typedef union Vqda {Du U[ 2]; Di I[ 2]; Df F[ 2];} Vqda;

typedef union Voba {Bu U[32]; Bi I[32]; Bc C[32];} Voba;
typedef union Voha {Hu U[16]; Hi I[16]; Hf F[16];} Voha;
typedef union Vowa {Wu U[ 8]; Wi I[ 8]; Wf F[ 8];} Vowa;
typedef union Voda {Du U[ 4]; Di I[ 4]; Df F[ 4];} Voda;

typedef union Vsba {Bu U[64]; Bi I[64]; Bc C[64];} Vsba;
typedef union Vsha {Hu U[32]; Hi I[32]; Hf F[32];} Vsha;
typedef union Vswa {Wu U[16]; Wi I[16]; Wf F[16];} Vswa;
typedef union Vsda {Du U[ 8]; Di I[ 8]; Df F[ 8];} Vsda;


#if defined(VWBU_MTYPE) || defined(VWBI_MTYPE)

#   define  VWB_M1TYPE   union Vwb1

union Vwbm {
#   if defined(VWBU_MTYPE)
    VWBU_MTYPE      U;
#   endif

#   if defined(VWBI_MTYPE)
    VWBI_MTYPE      I;
#   endif

#   if defined(VWBC_MTYPE)
    VWBC_MTYPE      C;
#   endif

};

union Vwb1 {

#   if defined(VWBU_MTYPE)
    struct Wbu1    U;
#   endif

#   if defined(VWBI_MTYPE)
    struct Wbi1    I;
#   endif

#   if defined(VWBC_MTYPE)
    struct Wbc1    C;
#   endif

};

union Vwb2 {

#   if defined(VWBU_MTYPE)
    struct Wbu2    U;
#   endif

#   if defined(VWBI_MTYPE)
    struct Wbi2    I;
#   endif

#   if defined(VWBC_MTYPE)
    struct Wbc2    C;
#   endif

};

union Vwb3 {

#   if defined(VWBU_MTYPE)
    struct Wbu3    U;
#   endif

#   if defined(VWBI_MTYPE)
    struct Wbi3    I;
#   endif

#   if defined(VWBC_MTYPE)
    struct Wbc3    C;
#   endif

};

union Vwb4 {
#   if defined(VWBU_MTYPE)
    struct Wbu4    U;
#   endif

#   if defined(VWBI_MTYPE)
    struct Wbi4    I;
#   endif

#   if defined(VWBC_MTYPE)
    struct Wbc4    C;
#   endif

};

#endif

#if defined(VWHU_MTYPE) || defined(VWHI_MTYPE) || defined(VWHF_MTYPE)

#   define  VWH_M1TYPE   union Vwh1

union Vwhm {

#   if defined(VWHU_MTYPE)
    VWHU_MTYPE    U;
#   endif

#   if defined(VWHI_MTYPE)
    VWHI_MTYPE    I;
#   endif

#   if defined(VWHF_MTYPE)
    VWHF_MTYPE    F;
#   endif

};

union Vwh1 {

#   if defined(VWHU_MTYPE)
    struct Whu1    U;
#   endif

#   if defined(VWHI_MTYPE)
    struct Whi1    I;
#   endif

#   if defined(VWHF_MTYPE)
    struct Whf1    F;
#   endif

};

union Vwh2 {

#   if defined(VWHU_MTYPE)
    struct Whu2    U;
#   endif

#   if defined(VWHI_MTYPE)
    struct Whi2    I;
#   endif

#   if defined(VWHF_MTYPE)
    struct Whf2    F;
#   endif

};

union Vwh3 {

#   if defined(VWHU_MTYPE)
    struct Whu3    U;
#   endif

#   if defined(VWHI_MTYPE)
    struct Whi3    I;
#   endif

#   if defined(VWHF_MTYPE)
    struct Whf3    F;
#   endif

};

union Vwh4 {

#   if defined(VWHU_MTYPE)
    struct Whu4    U;
#   endif

#   if defined(VWHI_MTYPE)
    struct Whi4    I;
#   endif

#   if defined(VWHF_MTYPE)
    struct Whf4    F;
#   endif

};

#endif

#if defined(VWWU_MTYPE) || defined(VWWI_MTYPE) || defined(VWWF_MTYPE)

#   define  VWW_M1TYPE   union Vww1

union Vwwm {

#   if defined(VWWU_MTYPE)
    VWWU_MTYPE   U;
#   endif

#   if defined(VWWI_MTYPE)
    VWWI_MTYPE    I;
#   endif

#   if defined(VWWF_MTYPE)
    VWWF_MTYPE   F;
#   endif

};

union Vww1 {

#   if defined(VWWU_MTYPE)
    struct Wwu1    U;
#   endif

#   if defined(VWWI_MTYPE)
    struct Wwi1    I;
#   endif

#   if defined(VWWF_MTYPE)
    struct Wwf1    F;
#   endif

};

union Vww2 {

#   if defined(VWWU_MTYPE)
    struct Wwu2    U;
#   endif

#   if defined(VWWI_MTYPE)
    struct Wwi2    I;
#   endif

#   if defined(VWWF_MTYPE)
    struct Wwf2    F;
#   endif

};

union Vww3 {

#   if defined(VWWU_MTYPE)
    struct Wwu3    U;
#   endif

#   if defined(VWWI_MTYPE)
    struct Wwi3    I;
#   endif

#   if defined(VWWF_MTYPE)
    struct Wwf3    F;
#   endif

};

union Vww4 {

#   if defined(VWWU_MTYPE)
    struct Wwu4    U;
#   endif

#   if defined(VWWI_MTYPE)
    struct Wwi4    I;
#   endif

#   if defined(VWWF_MTYPE)
    struct Wwf4    F;
#   endif

};

#endif

typedef  union Vwb {

    Vwba        A;
    Vwbu        U;
    Vwbi        I;
    Vwbc        C;

#   if defined(VWB_M1TYPE)
    union Vwbm  M;
    union Vwb1  M1;
#   endif

    struct {
        union {uint8_t U0; int8_t I0; char C0;};
        union {uint8_t U1; int8_t I1; char C1;};
        union {uint8_t U2; int8_t I2; char C2;};
        union {uint8_t U3; int8_t I3; char C3;};
    };

} Vwb;

typedef  union Vwh {

    Vwha        A;
    Vwhu        U;
    Vwhi        I;
    Vwhf        F;

#   if defined(VWB_M1TYPE)
    union Vwhm  M;
    union Vwh1  M1;
#   endif

    struct {
        union {Half H0; uint16_t U0; int16_t I0; flt16_t F0;};
        union {Half H1; uint16_t U1; int16_t I1; flt16_t F1;};
    };

} Vwh;

typedef  union Vww {

    Vwwa        A;
    Vwwu        U;
    Vwwi        I;
    Vwwf        F;

#   if defined(VWB_M1TYPE)
    union Vwwm  M;
    union Vww1  M1;
#   endif

    struct {
        union {uint32_t U0; int32_t I0; float F0;};
    };

} Vww;

typedef  union Vw {
    Vwyu    Y;
    Vwb     B;
    Vwh     H;
    Vww     W;
} Vw;


#if defined(VDBU_MTYPE) || defined(VDBI_MTYPE) || defined(VDBC_MTYPE)

#   define  VDB_M1TYPE   union Vdb1

union Vdbm {

#   if defined(VDBU_MTYPE)
    VDBU_MTYPE      U;
#   endif

#   if defined(VDBI_MTYPE)
    VDBI_MTYPE      I;
#   endif

#   if defined(VDBC_MTYPE)
    VDBC_MTYPE      C;
#   endif

};

union Vdb1 {

#   if defined(VDBU_MTYPE)
    struct Dbu1    U;
#   endif

#   if defined(VDBI_MTYPE)
    struct Dbi1    I;
#   endif

#   if defined(VDBC_MTYPE)
    struct Dbc1      C;
#   endif

};

union Vdb2 {

#   if defined(VDBU_MTYPE)
    struct Dbu2    U;
#   endif

#   if defined(VDBI_MTYPE)
    struct Dbi2    I;
#   endif

#   if defined(VDBC_MTYPE)
    struct Dbc2      C;
#   endif

};

union Vdb3 {

#   if defined(VDBU_MTYPE)
    struct Dbu3    U;
#   endif

#   if defined(VDBI_MTYPE)
    struct Dbi3    I;
#   endif

#   if defined(VDBC_MTYPE)
    struct Dbc3      C;
#   endif

};

union Vdb4 {

#   if defined(VDBU_MTYPE)
    struct Dbu4    U;
#   endif

#   if defined(VDBI_MTYPE)
    struct Dbi4    I;
#   endif

#   if defined(VDBC_MTYPE)
    struct Dbc4      C;
#   endif

};

#endif

#if defined(VDHU_MTYPE) || defined(VDHI_MTYPE) || defined(VDHF_MTYPE)

#   define  VDH_M1TYPE   union Vdh1

union Vdhm {

#   if defined(VDHU_MTYPE)
    VDHU_MTYPE     U;
#   endif

#   if defined(VDHI_MTYPE)
    VDHI_MTYPE      I;
#   endif

#   if defined(VDHF_MTYPE)
    VDHF_MTYPE     F;
#   endif

};

union Vdh1 {

#   if defined(VDHU_MTYPE)
    struct Dhu1    U;
#   endif

#   if defined(VDHI_MTYPE)
    struct Dhi1    I;
#   endif

#   if defined(VDHF_MTYPE)
    struct Dhf1    F;
#   endif

};

union Vdh2 {

#   if defined(VDHU_MTYPE)
    struct Dhu2    U;
#   endif

#   if defined(VDHI_MTYPE)
    struct Dhi2    I;
#   endif

#   if defined(VDHF_MTYPE)
    struct Dhf2    F;
#   endif

};

union Vdh3 {

#   if defined(VDHU_MTYPE)
    struct Dhu3    U;
#   endif

#   if defined(VDHI_MTYPE)
    struct Dhi3    I;
#   endif

#   if defined(VDHF_MTYPE)
    struct Dhf3    F;
#   endif

};

union Vdh4 {

#   if defined(VDHU_MTYPE)
    struct Dhu4    U;
#   endif

#   if defined(VDHI_MTYPE)
    struct Dhi4    I;
#   endif

#   if defined(VDHF_MTYPE)
    struct Dhf4    F;
#   endif

};

#endif

#if defined(VDWU_MTYPE) || defined(VDWI_MTYPE) || defined(VDWF_MTYPE)

#   define  VDW_M1TYPE   union Vdw1

union Vdwm {

#   if defined(VDWU_MTYPE)
    VDWU_MTYPE     U;
#   endif

#   if defined(VDWI_MTYPE)
    VDWI_MTYPE     I;
#   endif

#   if defined(VDWF_MTYPE)
    VDWF_MTYPE     F;
#   endif

};

union Vdw1 {

#   if defined(VDWU_MTYPE)
    struct Dwu1    U;
#   endif

#   if defined(VDWI_MTYPE)
    struct Dwi1    I;
#   endif

#   if defined(VDWF_MTYPE)
    struct Dwf1    F;
#   endif

};

union Vdw2 {

#   if defined(VDWU_MTYPE)
    struct Dwu2    U;
#   endif

#   if defined(VDWI_MTYPE)
    struct Dwi2    I;
#   endif

#   if defined(VDWF_MTYPE)
    struct Dwf2    F;
#   endif

};

union Vdw3 {

#   if defined(VDWU_MTYPE)
    struct Dwu3    U;
#   endif

#   if defined(VDWI_MTYPE)
    struct Dwi3    I;
#   endif

#   if defined(VDWF_MTYPE)
    struct Dwf3    F;
#   endif

};

union Vdw4 {

#   if defined(VDWU_MTYPE)
    struct Dwu4    U;
#   endif

#   if defined(VDWI_MTYPE)
    struct Dwi4    I;
#   endif

#   if defined(VDWF_MTYPE)
    struct Dwf4    F;
#   endif

};

#endif

#if defined(VDDU_MTYPE) || defined(VDDI_MTYPE) || defined(VDDF_MTYPE)

#   define  VDD_M1TYPE   union Vdd1

union Vddm {

#   if defined(VDDU_MTYPE)
    VDDU_MTYPE      U;
#   endif

#   if defined(VDDI_MTYPE)
    VDDI_MTYPE     I;
#   endif

#   if defined(VDDF_MTYPE)
    VDDF_MTYPE     F;
#   endif

};

union Vdd1 {
    union Vddm      M;
#   if defined(VDDU_MTYPE)
    struct Ddu1     U;
#   endif

#   if defined(VDDI_MTYPE)
    struct Ddi1     I;
#   endif

#   if defined(VDDF_MTYPE)
    struct Ddf1     F;
#   endif

};

union Vdd2 {

#   if defined(VDDU_MTYPE)
    struct Ddu2    U;
#   endif

#   if defined(VDDI_MTYPE)
    struct Ddi2    I;
#   endif

#   if defined(VDDF_MTYPE)
    struct Ddf2    F;
#   endif

};

union Vdd3 {

#   if defined(VDDU_MTYPE)
    struct Ddu3    U;
#   endif

#   if defined(VDDI_MTYPE)
    struct Ddi3    I;
#   endif

#   if defined(VDDF_MTYPE)
    struct Ddf3    F;
#   endif

};

union Vdd4 {

#   if defined(VDDU_MTYPE)
    struct Ddu4    U;
#   endif

#   if defined(VDDI_MTYPE)
    struct Ddi4    I;
#   endif

#   if defined(VDDF_MTYPE)
    struct Ddf4    F;
#   endif

};

#endif

typedef  union Vdb {

    Vdba        A;
    Vdbu        U;
    Vdbi        I;
    Vdbc        C;

#   if defined(VWB_M1TYPE)
    union Vwb2  M2;
#   endif

#   if defined(VDB_M1TYPE)
    union Vdbm  M;
    union Vdb1  M1;
#   endif

    struct {
        union {
            struct {
                union {uint8_t U0; int8_t I0; char C0;};
                union {uint8_t U1; int8_t I1; char C1;};
                union {uint8_t U2; int8_t I2; char C2;};
                union {uint8_t U3; int8_t I3; char C3;};
            };
            Vwb Lo;
        };
        union {
            struct {
                union {uint8_t U4; int8_t I4; char C4;};
                union {uint8_t U5; int8_t I5; char C5;};
                union {uint8_t U6; int8_t I6; char C6;};
                union {uint8_t U7; int8_t I7; char C7;};
            };
            Vwb Hi;
        };
    };

} Vdb;

typedef  union Vdh {

    Vdha    A;
    Vdhu    U;
    Vdhi    I;
    Vdhf    F;

#   if defined(VWH_M1TYPE)
    union Vwh2  M2;
#   endif

#   if defined(VDH_M1TYPE)
    union Vdhm  M;
    union Vdh1  M1;
#   endif

    struct {
        union {
            struct {
                union {uint16_t U0; int16_t I0; flt16_t F0;};
                union {uint16_t U1; int16_t I1; flt16_t F1;};
            };
            Vwh Lo;
        };
        union {
            struct {
                union {uint16_t U2; int16_t I2; flt16_t F2;};
                union {uint16_t U3; int16_t I3; flt16_t F3;};
            };
            Vwh Hi;
        };
    };

} Vdh;

typedef  union Vdw {

    Vdwa    A;
    Vdwu    U;
    Vdwi    I;
    Vdwf    F;

#   if defined(VWW_M1TYPE)
    union Vww2  M2;
#   endif

#   if defined(VDW_M1TYPE)
    union Vdw1  M1;
    union Vdwm  M;
#   endif

    struct {
        union {
            struct {
                union {unsigned U0; int I0; float F0;};
            };
            Vww Lo;
        };
        union {
            struct {

                union {unsigned U1; int I1; float F1;};
            };
            Vww Hi;
        };
    };

} Vdw;

typedef  union Vdd {

    Vdda    A;
    Vddu    U;
    Vddi    I;
    Vddf    F;

#   if defined(VDD_M1TYPE)
    union Vdd1  M1;
    union Vddm  M;
#   endif

    struct {
        union {uint64_t U0; int64_t I0; double F0;};
    };

} Vdd;

typedef  union Vd {
    struct {Vw Lo, Hi;};
    Vdyu    Y;
    Vdb     B;
    Vdh     H;
    Vdw     W;
    Vdd     D;
} Vd;


#if defined(VQBU_MTYPE) || defined(VQBI_MTYPE) || defined(VQBC_MTYPE)

#   define  VQB_M1TYPE   union Vqb1

union Vqb1 {

#   if defined(VQBU_MTYPE)
    struct Qbu1    U;
#   endif

#   if defined(VQBI_MTYPE)
    struct Qbi1    I;
#   endif

#   if defined(VQBI_MTYPE)
    struct Qbc1    C;
#   endif

};

union Vqb2 {

#   if defined(VQBU_MTYPE)
    struct Qbu2    U;
#   endif

#   if defined(VQBI_MTYPE)
    struct Qbi2    I;
#   endif

#   if defined(VQBI_MTYPE)
    struct Qbc2    C;
#   endif

};

union Vqb3 {

#   if defined(VQBU_MTYPE)
    struct Qbu3    U;
#   endif

#   if defined(VQBI_MTYPE)
    struct Qbi3    I;
#   endif

#   if defined(VQBI_MTYPE)
    struct Qbc3    C;
#   endif

};

union Vqb4 {

#   if defined(VQBU_MTYPE)
    struct Qbu4    U;
#   endif

#   if defined(VQBI_MTYPE)
    struct Qbi4    I;
#   endif

#   if defined(VQBI_MTYPE)
    struct Qbc4    C;
#   endif

};

#endif


#if defined(VQHU_MTYPE) || defined(VQHI_MTYPE) || defined(VQHF_MTYPE)

#   define  VQH_M1TYPE   union Vqh1

union Vqh1 {

#   if defined(VQHU_MTYPE)
    struct Qhu1    U;
#   endif

#   if defined(VQHI_MTYPE)
    struct Qhi1    I;
#   endif

#   if defined(VQHF_MTYPE)
    struct Qhf1    F;
#   endif

};

union Vqh2 {

#   if defined(VQHU_MTYPE)
    struct Qhu2    U;
#   endif

#   if defined(VQHI_MTYPE)
    struct Qhi2    I;
#   endif

#   if defined(VQHF_MTYPE)
    struct Qhf2    F;
#   endif

};

union Vqh3 {

#   if defined(VQHU_MTYPE)
    struct Qhu3    U;
#   endif

#   if defined(VQHI_MTYPE)
    struct Qhi3    I;
#   endif

#   if defined(VQHF_MTYPE)
    struct Qhf3    F;
#   endif

};

union Vqh4 {

#   if defined(VQHU_MTYPE)
    struct Qhu4    U;
#   endif

#   if defined(VQHI_MTYPE)
    struct Qhi4    I;
#   endif

#   if defined(VQHF_MTYPE)
    struct Qhf4    F;
#   endif

};

#endif


#if defined(VQWU_MTYPE) || defined(VQWI_MTYPE) || defined(VQWF_MTYPE)
#   define  VQW_M1TYPE   union Vqw1

union Vqw1 {

#   if defined(VQWU_MTYPE)
    struct Qwu1    U;
#   endif

#   if defined(VQWI_MTYPE)
    struct Qwi1    I;
#   endif

#   if defined(VQWF_MTYPE)
    struct Qwf1    F;
#   endif

};

union Vqw2 {

#   if defined(VQWU_MTYPE)
    struct Qwu2    U;
#   endif

#   if defined(VQWI_MTYPE)
    struct Qwi2    I;
#   endif

#   if defined(VQWF_MTYPE)
    struct Qwf2    F;
#   endif

};

union Vqw3 {

#   if defined(VQWU_MTYPE)
    struct Qwu3    U;
#   endif

#   if defined(VQWI_MTYPE)
    struct Qwi3    I;
#   endif

#   if defined(VQWF_MTYPE)
    struct Qwf3    F;
#   endif

};

union Vqw4 {

#   if defined(VQWU_MTYPE)
    struct Qwu4    U;
#   endif

#   if defined(VQWI_MTYPE)
    struct Qwi4    I;
#   endif

#   if defined(VQWF_MTYPE)
    struct Qwf4    F;
#   endif

};

#endif


#if defined(VQDU_MTYPE) || defined(VQDI_MTYPE) || defined(VQDF_MTYPE)
#   define  VQD_M1TYPE   union Vqd1

union Vqd1 {

#   if defined(VQDU_MTYPE)
    struct Qdu1    U;
#   endif

#   if defined(VQDI_MTYPE)
    struct Qdi1    I;
#   endif

#   if defined(VQDF_MTYPE)
    struct Qdf1    F;
#   endif

};

union Vqd2 {

#   if defined(VQDU_MTYPE)
    struct Qdu2    U;
#   endif

#   if defined(VQDI_MTYPE)
    struct Qdi2    I;
#   endif

#   if defined(VQDF_MTYPE)
    struct Qdf2    F;
#   endif

};

union Vqd3 {

#   if defined(VQDU_MTYPE)
    struct Qdu3    U;
#   endif

#   if defined(VQDI_MTYPE)
    struct Qdi3    I;
#   endif

#   if defined(VQDF_MTYPE)
    struct Qdf3    F;
#   endif

};

union Vqd4 {

#   if defined(VQDU_MTYPE)
    struct Qdu4    U;
#   endif

#   if defined(VQDI_MTYPE)
    struct Qdi4    I;
#   endif

#   if defined(VQDF_MTYPE)
    struct Qdf4    F;
#   endif

};

#endif


typedef  union Vqb {

    Vqba    A;
    Vqbu    U;
    Vqbi    I;
    Vqbc    C;

#   if defined(VWB_M1TYPE)
    union Vwb4  M4;
#   endif

#   if defined(VDB_M1TYPE)
    union Vdb2  M2;
#   endif

#   if defined(VQB_M1TYPE)
    union Vqb1  M1;
#   endif

    struct {
        union {

            struct {

                union {uint8_t U0; int8_t I0; char C0;};
                union {uint8_t U1; int8_t I1; char C1;};
                union {uint8_t U2; int8_t I2; char C2;};
                union {uint8_t U3; int8_t I3; char C3;};
                union {uint8_t U4; int8_t I4; char C4;};
                union {uint8_t U5; int8_t I5; char C5;};
                union {uint8_t U6; int8_t I6; char C6;};
                union {uint8_t U7; int8_t I7; char C7;};
            };

            Vdb Lo;
        };
        union {

            struct {

                union {uint8_t U8;  int8_t I8;  char C8;};
                union {uint8_t U9;  int8_t I9;  char C9;};
                union {uint8_t U10; int8_t I10; char C10;};
                union {uint8_t U11; int8_t I11; char C11;};
                union {uint8_t U12; int8_t I12; char C12;};
                union {uint8_t U13; int8_t I13; char C13;};
                union {uint8_t U14; int8_t I14; char C14;};
                union {uint8_t U15; int8_t I15; char C15;};
            };
            Vdb Hi;
        };
    };

} Vqb;

typedef  union Vqh {

    Vqha    A;
    Vqhu    U;
    Vqhi    I;
    Vqhf    F;

#   if defined(VWH_M1TYPE)
    union Vwh4  M4;
#   endif

#   if defined(VDH_M1TYPE)
    union Vdh2  M2;
#   endif

#   if defined(VQH_M1TYPE)
    union Vqh1  M1;
#   endif

    struct {

        union {
            struct {
                union {uint16_t U0; int16_t I0; flt16_t F0;};
                union {uint16_t U1; int16_t I1; flt16_t F1;};
                union {uint16_t U2; int16_t I2; flt16_t F2;};
                union {uint16_t U3; int16_t I3; flt16_t F3;};
            };
            Vdh Lo;
        };

        union {
            struct {
                union {uint16_t U4; int16_t I4; flt16_t F4;};
                union {uint16_t U5; int16_t I5; flt16_t F5;};
                union {uint16_t U6; int16_t I6; flt16_t F6;};
                union {uint16_t U7; int16_t I7; flt16_t F7;};
            };
            Vdh Hi;
        };

    };

} Vqh;

typedef  union Vqw {

    Vqwa    A;
    Vqwu    U;
    Vqwi    I;
    Vqwf    F;

#   if defined(VWW_M1TYPE)
    union Vww4  M4;
#   endif

#   if defined(VDW_M1TYPE)
    union Vdw2  M2;
#   endif

#   if defined(VQW_M1TYPE)
    union Vqw1  M1;
#   endif

    struct {

        union {
            struct {
                union {unsigned U0; int I0; float F0;};
                union {unsigned U1; int I1; float F1;};
            };
            Vdw Lo;
        };

        union {
            struct {
                union {unsigned U2; int I2; float F2;};
                union {unsigned U3; int I3; float F3;};
            };
            Vdw Hi;
        };

    };

} Vqw;

typedef  union Vqd {

    Vqda        A;
    Vqdu        U;
    Vqdi        I;
    Vqdf        F;

#   if defined(VDD_M1TYPE)
    union Vdd2  M2;
#   endif

#   if defined(VQD_M1TYPE)
    union Vqd1  M1;
#   endif

    struct {

        union {
            union {uint64_t U0; int64_t I0; double F0;};
            Vdd Lo;
        };

        union {
            union {uint64_t U1; int64_t I1; double F1;};
            Vdd Hi;
        };

    };

} Vqd;

typedef  union Vq {
    struct {Vd Lo, Hi;};
    Vqyu    Y;
    Vqb     B;
    Vqh     H;
    Vqw     W;
    Vqd     D;
} Vq;


#if defined(VOBU_MTYPE) || defined(VOBI_MTYPE)

#   define  VOB_M1TYPE   union Vob1

union Vob1 {

#   if defined(VOBU_MTYPE)
    struct Obu1    U;
#   endif

#   if defined(VOBI_MTYPE)
    struct Obi1    I;
#   endif

#   if defined(VOBC_MTYPE)
    struct Obc1    C;
#   endif

};

union Vob2 {

#   if defined(VOBU_MTYPE)
    struct Obu2    U;
#   endif

#   if defined(VOBI_MTYPE)
    struct Obi2    I;
#   endif

#   if defined(VOBC_MTYPE)
    struct Obc2    I;
#   endif

};

union Vob3 {

#   if defined(VOBU_MTYPE)
    struct Obu3    U;
#   endif

#   if defined(VOBI_MTYPE)
    struct Obi3    I;
#   endif

#   if defined(VOBI_MTYPE)
    struct Obc3    C;
#   endif

};

union Vob4 {

#   if defined(VOBU_MTYPE)
    struct Obu4    U;
#   endif

#   if defined(VOBI_MTYPE)
    struct Obi4    I;
#   endif

#   if defined(VOBC_MTYPE)
    struct Obc4    I;
#   endif

};

#endif


#if defined(VOHU_MTYPE) || defined(VOHI_MTYPE) || defined(VOHF_MTYPE)

#   define  VOH_M1TYPE   union Voh1

union Voh1 {

#   if defined(VOHU_MTYPE)
    struct Ohu1    U;
#   endif

#   if defined(VOHI_MTYPE)
    struct Ohi1    I;
#   endif

#   if defined(VOHF_MTYPE)
    struct Ohf1    F;
#   endif

};

union Voh2 {

#   if defined(VOHU_MTYPE)
    struct Ohu2    U;
#   endif

#   if defined(VOHI_MTYPE)
    struct Ohi2    I;
#   endif

#   if defined(VOHF_MTYPE)
    struct Ohf2    F;
#   endif

};

union Voh3 {

#   if defined(VOHU_MTYPE)
    struct Ohu3    U;
#   endif

#   if defined(VOHI_MTYPE)
    struct Ohi3    I;
#   endif

#   if defined(VOHF_MTYPE)
    struct Ohf3    F;
#   endif

};

union Voh4 {

#   if defined(VOHU_MTYPE)
    struct Ohu4    U;
#   endif

#   if defined(VOHI_MTYPE)
    struct Ohi4    I;
#   endif

#   if defined(VOHF_MTYPE)
    struct Ohf4    F;
#   endif

};

#endif


#if defined(VOWU_MTYPE) || defined(VOWI_MTYPE) || defined(VOWF_MTYPE)

#   define  VOW_M1TYPE   union Vow1

union Vow1 {

#   if defined(VOWU_MTYPE)
    struct Owu1    U;
#   endif

#   if defined(VOWI_MTYPE)
    struct Owi1    I;
#   endif

#   if defined(VOWF_MTYPE)
    struct Owf1    F;
#   endif

};

union Vow2 {

#   if defined(VOWU_MTYPE)
    struct Owu2    U;
#   endif

#   if defined(VOWI_MTYPE)
    struct Owi2    I;
#   endif

#   if defined(VOWF_MTYPE)
    struct Owf2    F;
#   endif

};

union Vow3 {

#   if defined(VOWU_MTYPE)
    struct Owu3    U;
#   endif

#   if defined(VOWI_MTYPE)
    struct Owi3    I;
#   endif

#   if defined(VOWF_MTYPE)
    struct Owf3    F;
#   endif

};

union Vow4 {

#   if defined(VOWU_MTYPE)
    struct Owu4    U;
#   endif

#   if defined(VOWI_MTYPE)
    struct Owi4    I;
#   endif

#   if defined(VOWF_MTYPE)
    struct Owf4    F;
#   endif

};

#endif


#if defined(VODU_MTYPE) || defined(VODI_MTYPE) || defined(VODF_MTYPE)

#   define  VOD_M1TYPE   union Vod1

union Vod1 {

#   if defined(VODU_MTYPE)
    struct Odu1    U;
#   endif

#   if defined(VODI_MTYPE)
    struct Odi1    I;
#   endif

#   if defined(VODF_MTYPE)
    struct Odf1    F;
#   endif

};

union Vod2 {

#   if defined(VODU_MTYPE)
    struct Odu2    U;
#   endif

#   if defined(VODI_MTYPE)
    struct Odi2    I;
#   endif

#   if defined(VODF_MTYPE)
    struct Odf2    F;
#   endif

};

union Vod3 {

#   if defined(VODU_MTYPE)
    struct Odu3    U;
#   endif

#   if defined(VODI_MTYPE)
    struct Odi3    I;
#   endif

#   if defined(VODF_MTYPE)
    struct Odf3    F;
#   endif

};

union Vod4 {

#   if defined(VODU_MTYPE)
    struct Odu4    U;
#   endif

#   if defined(VODI_MTYPE)
    struct Odi4    I;
#   endif

#   if defined(VODF_MTYPE)
    struct Odf4    F;
#   endif

};
#endif

typedef  union Vob {

    Voba    A;
    Vobu    U;
    Vobi    I;
    Vobc    C;

#   if defined(VDB_M1TYPE)
    union Vdb4  M4;
#   endif

#   if defined(VQB_M1TYPE)
    union Vqb2  M2;
#   endif

#   if defined(VOB_M1TYPE)
    union Vob1  M1;
#   endif

    struct {
        union {
            struct {
                union {uint8_t U0;  int8_t I0;  char C0;};
                union {uint8_t U1;  int8_t I1;  char C1;};
                union {uint8_t U2;  int8_t I2;  char C2;};
                union {uint8_t U3;  int8_t I3;  char C3;};
                union {uint8_t U4;  int8_t I4;  char C4;};
                union {uint8_t U5;  int8_t I5;  char C5;};
                union {uint8_t U6;  int8_t I6;  char C6;};
                union {uint8_t U7;  int8_t I7;  char C7;};
                union {uint8_t U8;  int8_t I8;  char C8;};
                union {uint8_t U9;  int8_t I9;  char C9;};
                union {uint8_t U10; int8_t I10; char C10;};
                union {uint8_t U11; int8_t I11; char C11;};
                union {uint8_t U12; int8_t I12; char C12;};
                union {uint8_t U13; int8_t I13; char C13;};
                union {uint8_t U14; int8_t I14; char C14;};
                union {uint8_t U15; int8_t I15; char C15;};
            };
            Vqb     Lo;
        };
        union {
            struct {
                union {uint8_t U16; int8_t I16; char C16;};
                union {uint8_t U17; int8_t I17; char C17;};
                union {uint8_t U18; int8_t I18; char C18;};
                union {uint8_t U19; int8_t I19; char C19;};
                union {uint8_t U20; int8_t I20; char C20;};
                union {uint8_t U21; int8_t I21; char C21;};
                union {uint8_t U22; int8_t I22; char C22;};
                union {uint8_t U23; int8_t I23; char C23;};
                union {uint8_t U24; int8_t I24; char C24;};
                union {uint8_t U25; int8_t I25; char C25;};
                union {uint8_t U26; int8_t I26; char C26;};
                union {uint8_t U27; int8_t I27; char C27;};
                union {uint8_t U28; int8_t I28; char C28;};
                union {uint8_t U29; int8_t I29; char C29;};
                union {uint8_t U30; int8_t I30; char C30;};
                union {uint8_t U31; int8_t I31; char C31;};
            };
            Vqb     Hi;
        };
    };

} Vob;

typedef  union Voh {

    Voha    A;
    Vohu    U;
    Vohi    I;
    Vohf    F;

#   if defined(VDH_M1TYPE)
    union Vdh4  M4;
#   endif

#   if defined(VQH_M1TYPE)
    union Vqh2  M2;
#   endif

#   if defined(VOH_M1TYPE)
    union Voh1  M1;
#   endif

    struct {
        union {
            struct {
                union {uint16_t U0; int16_t I0; flt16_t F0;};
                union {uint16_t U1; int16_t I1; flt16_t F1;};
                union {uint16_t U2; int16_t I2; flt16_t F2;};
                union {uint16_t U3; int16_t I3; flt16_t F3;};
                union {uint16_t U4; int16_t I4; flt16_t F4;};
                union {uint16_t U5; int16_t I5; flt16_t F5;};
                union {uint16_t U6; int16_t I6; flt16_t F6;};
                union {uint16_t U7; int16_t I7; flt16_t F7;};
            };
            Vqh Lo;
        };

        union {
            struct {
                union {uint16_t U8;  int16_t I8; flt16_t F8;};
                union {uint16_t U9;  int16_t I9; flt16_t F9;};
                union {uint16_t U10; int16_t I10; flt16_t F10;};
                union {uint16_t U11; int16_t I11; flt16_t F11;};
                union {uint16_t U12; int16_t I12; flt16_t F12;};
                union {uint16_t U13; int16_t I13; flt16_t F13;};
                union {uint16_t U14; int16_t I14; flt16_t F14;};
                union {uint16_t U15; int16_t I15; flt16_t F15;};
            };
            Vqh Hi;
        };

    };

} Voh;

typedef  union Vow {

    Vowa        A;
    Vowu        U;
    Vowi        I;
    Vowf        F;

#   if defined(VDW_M1TYPE)
    union Vdw4  M4;
#   endif

#   if defined(VQW_M1TYPE)
    union Vqw2  M2;
#   endif

#   if defined(VOW_M1TYPE)
    union Vow1  M1;
#   endif

    struct {
        union {
            struct {
                union {uint32_t U0; int32_t I0; float F0;};
                union {uint32_t U1; int32_t I1; float F1;};
                union {uint32_t U2; int32_t I2; float F2;};
                union {uint32_t U3; int32_t I3; float F3;};
            };
            Vqw Lo;
        };

        union {
            struct {
                union {uint32_t U4; int32_t I4; float F4;};
                union {uint32_t U5; int32_t I5; float F5;};
                union {uint32_t U6; int32_t I6; float F6;};
                union {uint32_t U7; int32_t I7; float F7;};
            };
            Vqw Hi;
        };
    };

} Vow;

typedef  union Vod {

    Voda    A;
    Vodu    U;
    Vodi    I;
    Vodf    F;

#   if defined(VDD_M1TYPE)
    union Vdd4  M4;
#   endif

#   if defined(VQD_M1TYPE)
    union Vqd2  M2;
#   endif

#   if defined(VOD_M1TYPE)
    union Vod1  M1;
#   endif

    struct {
        union {
            struct {
                union {uint64_t U0; int64_t I0; double F0;};
                union {uint64_t U1; int64_t I1; double F1;};
            };
            Vqd Lo;
        };
        union {
            struct {
                union {uint64_t U2; int64_t I2; double F2;};
                union {uint64_t U3; int64_t I3; double F3;};
            };
            Vqd Hi;
        };
    };

} Vod;

typedef  union Vo {

    struct {Vq Lo, Hi;};
    Voyu    Y;
    Vob     B;
    Voh     H;
    Vow     W;
    Vod     D;

} Vo;


#if defined(VSBU_MTYPE) || defined(VSBI_MTYPE)
#   define  VSB_M1TYPE   union Vsb1

union Vsb1 {

#   if defined(VSBU_MTYPE)
    struct Sbu1    U;
#   endif

#   if defined(VSBI_MTYPE)
    struct Sbi1    I;
#   endif

};

union Vsb2 {

#   if defined(VSBU_MTYPE)
    struct Sbu2    U;
#   endif

#   if defined(VSBI_MTYPE)
    struct Sbi2    I;
#   endif

};

union Vsb3 {

#   if defined(VSBU_MTYPE)
    struct Sbu3    U;
#   endif

#   if defined(VSBI_MTYPE)
    struct Sbi3    I;
#   endif

};

union Vsb4 {

#   if defined(VSBU_MTYPE)
    struct Sbu4    U;
#   endif

#   if defined(VSBI_MTYPE)
    struct Sbi4    I;
#   endif

};

#endif

#if defined(VSHU_MTYPE) || defined(VSHI_MTYPE) || defined(VSHF_MTYPE)
#   define  VSH_M1TYPE   union Vsh1

union Vsh1 {

#   if defined(VSHU_MTYPE)
    struct Shu1    U;
#   endif

#   if defined(VSHI_MTYPE)
    struct Shi1    I;
#   endif

#   if defined(VSHF_MTYPE)
    struct Shf1    F;
#   endif

};

union Vsh2 {

#   if defined(VSHU_MTYPE)
    struct Shu2    U;
#   endif

#   if defined(VSHI_MTYPE)
    struct Shi2    I;
#   endif

#   if defined(VSHF_MTYPE)
    struct Shf2    F;
#   endif

};

union Vsh3 {

#   if defined(VSHU_MTYPE)
    struct Shu3    U;
#   endif

#   if defined(VSHI_MTYPE)
    struct Shi3    I;
#   endif

#   if defined(VSHF_MTYPE)
    struct Shf3    F;
#   endif

};

union Vsh4 {

#   if defined(VSHU_MTYPE)
    struct Shu4    U;
#   endif

#   if defined(VSHI_MTYPE)
    struct Shi4    I;
#   endif

#   if defined(VSHF_MTYPE)
    struct Shf4    F;
#   endif

};

#endif


#if defined(VSWU_MTYPE) || defined(VSWI_MTYPE) || defined(VSWF_MTYPE)
#   define  VSW_M1TYPE   union Vsw1

union Vsw1 {

#   if defined(VSWU_MTYPE)
    struct Swu1    U;
#   endif

#   if defined(VSWI_MTYPE)
    struct Swi1    I;
#   endif

#   if defined(VSWF_MTYPE)
    struct Swf1    F;
#   endif

};

union Vsw2 {

#   if defined(VSWU_MTYPE)
    struct Swu2    U;
#   endif

#   if defined(VSWI_MTYPE)
    struct Swi2    I;
#   endif

#   if defined(VSWF_MTYPE)
    struct Swf2    F;
#   endif

};

union Vsw3 {

#   if defined(VSWU_MTYPE)
    struct Swu3    U;
#   endif

#   if defined(VSWI_MTYPE)
    struct Swi3    I;
#   endif

#   if defined(VSWF_MTYPE)
    struct Swf3    F;
#   endif

};

union Vsw4 {

#   if defined(VSWU_MTYPE)
    struct Swu4    U;
#   endif

#   if defined(VSWI_MTYPE)
    struct Swi4    I;
#   endif

#   if defined(VSWF_MTYPE)
    struct Swf4    F;
#   endif

};

#endif


#if defined(VSDU_MTYPE) || defined(VSDI_MTYPE) || defined(VSDF_MTYPE)
#   define  VSD_M1TYPE   union Vsd1

union Vsd1 {

#   if defined(VSDU_MTYPE)
    struct Sdu1    U;
#   endif

#   if defined(VSDI_MTYPE)
    struct Sdi1    I;
#   endif

#   if defined(VSDF_MTYPE)
    struct Sdf1    F;
#   endif

};

union Vsd2 {

#   if defined(VSDU_MTYPE)
    struct Sdu2    U;
#   endif

#   if defined(VSDI_MTYPE)
    struct Sdi2    I;
#   endif

#   if defined(VSDF_MTYPE)
    struct Sdf2    F;
#   endif

};

union Vsd3 {

#   if defined(VSDU_MTYPE)
    struct Sdu3    U;
#   endif

#   if defined(VSDI_MTYPE)
    struct Sdi3    I;
#   endif

#   if defined(VSDF_MTYPE)
    struct Sdf3    F;
#   endif

};

union Vsd4 {

#   if defined(VSDU_MTYPE)
    struct Sdu4    U;
#   endif

#   if defined(VSDI_MTYPE)
    struct Sdi4    I;
#   endif

#   if defined(VSDF_MTYPE)
    struct Sdf4    F;
#   endif

};
#endif

typedef  union Vsb {

    Vsba        A;
    Vsbu        U;
    Vsbi        I;
    Vsbc        C;

#   if defined(VQB_M1TYPE)
    union Vqb4  M4;
#   endif

#   if defined(VOB_M1TYPE)
    union Vob2  M2;
#   endif

#   if defined(VSB_M1TYPE)
    union Vsb1  M1;
#   endif

    struct {

        union {
            struct {
                union {uint8_t U0;  int8_t I0;  char C0;};
                union {uint8_t U1;  int8_t I1;  char C1;};
                union {uint8_t U2;  int8_t I2;  char C2;};
                union {uint8_t U3;  int8_t I3;  char C3;};
                union {uint8_t U4;  int8_t I4;  char C4;};
                union {uint8_t U5;  int8_t I5;  char C5;};
                union {uint8_t U6;  int8_t I6;  char C6;};
                union {uint8_t U7;  int8_t I7;  char C7;};
                union {uint8_t U8;  int8_t I8;  char C8;};
                union {uint8_t U9;  int8_t I9;  char C9;};
                union {uint8_t U10; int8_t I10; char C10;};
                union {uint8_t U11; int8_t I11; char C11;};
                union {uint8_t U12; int8_t I12; char C12;};
                union {uint8_t U13; int8_t I13; char C13;};
                union {uint8_t U14; int8_t I14; char C14;};
                union {uint8_t U15; int8_t I15; char C15;};
                union {uint8_t U16; int8_t I16; char C16;};
                union {uint8_t U17; int8_t I17; char C17;};
                union {uint8_t U18; int8_t I18; char C18;};
                union {uint8_t U19; int8_t I19; char C19;};
                union {uint8_t U20; int8_t I20; char C20;};
                union {uint8_t U21; int8_t I21; char C21;};
                union {uint8_t U22; int8_t I22; char C22;};
                union {uint8_t U23; int8_t I23; char C23;};
                union {uint8_t U24; int8_t I24; char C24;};
                union {uint8_t U25; int8_t I25; char C25;};
                union {uint8_t U26; int8_t I26; char C26;};
                union {uint8_t U27; int8_t I27; char C27;};
                union {uint8_t U28; int8_t I28; char C28;};
                union {uint8_t U29; int8_t I29; char C29;};
                union {uint8_t U30; int8_t I30; char C30;};
                union {uint8_t U31; int8_t I31; char C31;};
            };
            Vob Lo;
        };

        union {
            struct {
                union {uint8_t U32; int8_t I32; char C32;};
                union {uint8_t U33; int8_t I33; char C33;};
                union {uint8_t U34; int8_t I34; char C34;};
                union {uint8_t U35; int8_t I35; char C35;};
                union {uint8_t U36; int8_t I36; char C36;};
                union {uint8_t U37; int8_t I37; char C37;};
                union {uint8_t U38; int8_t I38; char C38;};
                union {uint8_t U39; int8_t I39; char C39;};
                union {uint8_t U40; int8_t I40; char C40;};
                union {uint8_t U41; int8_t I41; char C41;};
                union {uint8_t U42; int8_t I42; char C42;};
                union {uint8_t U43; int8_t I43; char C43;};
                union {uint8_t U44; int8_t I44; char C44;};
                union {uint8_t U45; int8_t I45; char C45;};
                union {uint8_t U46; int8_t I46; char C46;};
                union {uint8_t U47; int8_t I47; char C47;};
                union {uint8_t U48; int8_t I48; char C48;};
                union {uint8_t U49; int8_t I49; char C49;};
                union {uint8_t U50; int8_t I50; char C50;};
                union {uint8_t U51; int8_t I51; char C51;};
                union {uint8_t U52; int8_t I52; char C52;};
                union {uint8_t U53; int8_t I53; char C53;};
                union {uint8_t U54; int8_t I54; char C54;};
                union {uint8_t U55; int8_t I55; char C55;};
                union {uint8_t U56; int8_t I56; char C56;};
                union {uint8_t U57; int8_t I57; char C57;};
                union {uint8_t U58; int8_t I58; char C58;};
                union {uint8_t U59; int8_t I59; char C59;};
                union {uint8_t U60; int8_t I60; char C60;};
                union {uint8_t U61; int8_t I61; char C61;};
                union {uint8_t U62; int8_t I62; char C62;};
                union {uint8_t U63; int8_t I63; char C63;};
            };
            Vob Hi;
        };

    };

} Vsb;

typedef  union Vsh {

    Vsha        A;
    Vshu        U;
    Vshi        I;
    Vshf        F;

#   if defined(VQH_M1TYPE)
    union Vqh4  M4;
#   endif

#   if defined(VOH_M1TYPE)
    union Voh2  M2;
#   endif

#   if defined(VSH_M1TYPE)
    union Vsh1  M1;
#   endif

    struct {
        union {
            struct {
                union {uint16_t U0;  int16_t I0;  flt16_t F0;};
                union {uint16_t U1;  int16_t I1;  flt16_t F1;};
                union {uint16_t U2;  int16_t I2;  flt16_t F2;};
                union {uint16_t U3;  int16_t I3;  flt16_t F3;};
                union {uint16_t U4;  int16_t I4;  flt16_t F4;};
                union {uint16_t U5;  int16_t I5;  flt16_t F5;};
                union {uint16_t U6;  int16_t I6;  flt16_t F6;};
                union {uint16_t U7;  int16_t I7;  flt16_t F7;};
                union {uint16_t U8;  int16_t I8;  flt16_t F8;};
                union {uint16_t U9;  int16_t I9;  flt16_t F9;};
                union {uint16_t U10; int16_t I10; flt16_t F10;};
                union {uint16_t U11; int16_t I11; flt16_t F11;};
                union {uint16_t U12; int16_t I12; flt16_t F12;};
                union {uint16_t U13; int16_t I13; flt16_t F13;};
                union {uint16_t U14; int16_t I14; flt16_t F14;};
                union {uint16_t U15; int16_t I15; flt16_t F15;};
            };
            Voh Lo;
        };
        union {
            struct {
                union {uint16_t U16; int16_t I16; flt16_t F16;};
                union {uint16_t U17; int16_t I17; flt16_t F17;};
                union {uint16_t U18; int16_t I18; flt16_t F18;};
                union {uint16_t U19; int16_t I19; flt16_t F19;};
                union {uint16_t U20; int16_t I20; flt16_t F20;};
                union {uint16_t U21; int16_t I21; flt16_t F21;};
                union {uint16_t U22; int16_t I22; flt16_t F22;};
                union {uint16_t U23; int16_t I23; flt16_t F23;};
                union {uint16_t U24; int16_t I24; flt16_t F24;};
                union {uint16_t U25; int16_t I25; flt16_t F25;};
                union {uint16_t U26; int16_t I26; flt16_t F26;};
                union {uint16_t U27; int16_t I27; flt16_t F27;};
                union {uint16_t U28; int16_t I28; flt16_t F28;};
                union {uint16_t U29; int16_t I29; flt16_t F29;};
                union {uint16_t U30; int16_t I30; flt16_t F30;};
                union {uint16_t U31; int16_t I31; flt16_t F31;};
            };
            Voh Hi;
        };
    };

} Vsh;
typedef  union Vsw {

    Vswa        A;
    Vswu        U;
    Vswi        I;
    Vswf        F;

#   if defined(VQW_M1TYPE)
    union Vqw4  M4;
#   endif

#   if defined(VOW_M1TYPE)
    union Vow2  M2;
#   endif

#   if defined(VSW_M1TYPE)
    union Vsw1  M1;
#   endif

    struct {
        union {
            struct {
                union {unsigned U0; int I0; float F0;};
                union {unsigned U1; int I1; float F1;};
                union {unsigned U2; int I2; float F2;};
                union {unsigned U3; int I3; float F3;};
                union {unsigned U4; int I4; float F4;};
                union {unsigned U5; int I5; float F5;};
                union {unsigned U6; int I6; float F6;};
                union {unsigned U7; int I7; float F7;};
            };
            Vow Lo;
        };
        union {
            struct {
                union {unsigned U8;  int I8;  float F8;};
                union {unsigned U9;  int I9;  float F9;};
                union {unsigned U10; int I10; float F10;};
                union {unsigned U11; int I11; float F11;};
                union {unsigned U12; int I12; float F12;};
                union {unsigned U13; int I13; float F13;};
                union {unsigned U14; int I14; float F14;};
                union {unsigned U15; int I15; float F15;};
            };
            Vow Hi;
        };
    };

} Vsw;
typedef  union Vsd {

    Vsda    A;
    Vsdu    U;
    Vsdi    I;
    Vsdf    F;

#   if defined(VQD_M1TYPE)
    union Vqd4  M4;
#   endif

#   if defined(VOD_M1TYPE)
    union Vod2  M2;
#   endif

#   if defined(VSD_M1TYPE)
    union Vsd1  M1;
#   endif

    struct {
        union {
            struct {
                union {uint64_t U0; int64_t I0; double F0;};
                union {uint64_t U1; int64_t I1; double F1;};
                union {uint64_t U2; int64_t I2; double F2;};
                union {uint64_t U3; int64_t I3; double F3;};
            };
            Vod Lo;
        };
        union {
            struct {
                union {uint64_t U4; int64_t I4; double F4;};
                union {uint64_t U5; int64_t I5; double F5;};
                union {uint64_t U6; int64_t I6; double F6;};
                union {uint64_t U7; int64_t I7; double F7;};
            };
            Vod Hi;
        };
    };

} Vsd;
typedef  union Vs {
    struct {Vo Lo, Hi;};
    Vsyu    Y;
    Vsb     B;
    Vsh     H;
    Vsw     W;
    Vsd     D;
} Vs;

#if _LEAVE_EXTVEC_TYPEDEFS
}
#endif


#endif // EOF("extvec.h")

#if _EXTVEC_HDR_LEAVE
}
#endif


#if _ENTER_EXTGOP
{
#endif

/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳

    One of our core features is a system that profoundly
    simplifies the implementation of a type generic C API.
    Users include this header, *AFTER* including <extnum.h>
    and/or <extvec.h>, and a few function macros are 
    defined that take a number of acronyms and expand them
    into a _Generic expression.
    
    By default, the following set of unique types are
    recognized. Each bullet point contains a list of types
    that have the same conversion rank according to the C 
    standard, or would, if the standard recognized the
    ubiquity of SIMD vectors:

    (from "extnum.h")
    * _Bool 
    * char, unsigned char, signed char
    * unsigned short, short
    * unsigned int, int
    * unsigned long, long
    * unsigned long long, long long
    * flt16_t
    * float 
    * double 

    (from "extvec.h")
    * Vwyu          (bool[32])
    * Vwbu, Vwbi    (int8[4])
    * Vwhu, Vwhi    (int16[2])
    * Vwwu, Vwwi    (int32[1])
    * Vwhf          (float16[2])
    * Vwwf          (float32[1])

    * Vdyu          (bool[64])
    * Vdbu, Vdbi    (int8[8])
    * Vdhu, Vdhi    (int16[4])
    * Vdwu, Vdwi    (int32[2])
    * Vddu, Vddi    (int64[1])
    * Vdhf          (float16[4])
    * Vdwf          (float32[2])
    * Vddf          (float64[1])

    * Vqyu          (bool[128])
    * Vqbu, Vqbi    (int8[16])
    * Vqhu, Vqhi    (int16[8])
    * Vqwu, Vqwi    (int32[4])
    * Vqdu, Vqdi    (int64[2])
    * Vqhf          (float16[8])
    * Vqwf          (float32[4])
    * Vqdf          (float64[2])

    * Voyu          (bool[256])
    * Vobu, Vobi    (int8[32])
    * Vohu, Vohi    (int16[16])
    * Vowu, Vowi    (int32[8])
    * Vodu, Vodi    (int64[4])
    * Vohf          (float16[16])
    * Vowf          (float32[8])
    * Vodf          (float64[4])

    * Vsyu          (bool[512])
    * Vsbu, Vsbi    (int8[64])
    * Vshu, Vshi    (int16[32])
    * Vswu, Vswi    (int32[16])
    * Vsdu, Vsdi    (int64[8])
    * Vshf          (float16[32])
    * Vswf          (float32[16])
    * Vsdf          (float64[8])

    NOTE: quoted symbols in the following should obvious not
    have quotes in code.

    FUNCOF(F, X, K, W, D, Q, O, S, DEFAULT)
        F:  base name, e.g. "astv"
        X:  the selecting expression 
        K:  "NONE" or one of the scalar set identifiers
        W:  like K, but for 32 bit vectors
        D:  like K, but for 64 bit vectors
        Q:  like K, but for 128 bit vectors
        O:  like K, but for 256 bit vectors
        S:  like K, but for 512 bit vectors

    NONE represents the empty set. Otherwise, the pattern for
    a type set is simple:

        YU  =  (Y   ) + U  => just 1(Y) bit unsigned(U)
        YBU =  (Y..B) + U  => 1(Y) to 8(B) bit unsigned(U)
        BWU =  (B..W) + U  => 8(B) to 32(W) bit unsigned(U)
        DI  =  (D   ) + I  => 64(D) signed(I)
        Y = 1 bit
        B = 8 bit
        H = 16 bit
        W = 32 bit
        D = 64 bit
        U = unsigned integer
        I = signed integer
        F = floating point 
        Z = integer (U+I)
        S = signed (I+F)
        N = natural (U+F)
        R = real (U+I+F, i.e. everything)
        
    The DEFAULT parameter is NOT optional; it must expand 
    to at least one generic case and must not end with a
    comma. 
  
*/

#ifndef MY_EXTGOP_H // BOF("extgop.h")
#define MY_EXTGOP_H


#if _ENTER_EXTGOP_TGK
{
#endif

#ifndef     TGK_NONE
#define     TGK_NONE(_)
#endif

#ifndef     TGK_YU
#define     TGK_YU(_)   _Bool: BOOL_SN(_),
#endif

#ifndef     TGK_YI
#define     TGK_YI(_)
#endif

#ifndef     TGK_YF
#define     TGK_YF(_)
#endif

#if defined(MY_BROKEN_CHAR)

#   ifndef  TGK_BU
#   define  TGK_BU(_)   BYTE_UTYPE:BYTE_SNU(_),
#   endif

#   ifndef  TGK_BI
#   define  TGK_BI(_)   BYTE_ITYPE:BYTE_SNI(_),
#   endif

#elif CHAR_MIN

#   ifndef  TGK_BU
#   define  TGK_BU(_)   BYTE_UTYPE:BYTE_SNU(_),
#   endif

#   ifndef  TGK_BI
#   define  TGK_BI(_)   BYTE_ITYPE:BYTE_SNI(_), char:_##bc,
#   endif

#else

#   ifndef  TGK_BU
#   define  TGK_BU(_)   BYTE_UTYPE:BYTE_SNU(_), char:_##bc,
#   endif

#   ifndef  TGK_BI
#   define  TGK_BI(_)   BYTE_ITYPE:BYTE_SNI(_),
#   endif

#endif

#ifndef     TGK_BF
#define     TGK_BF(_)
#endif

#ifndef     TGK_HU
#define     TGK_HU(_)   HALF_UTYPE:HALF_SNU(_),
#endif

#ifndef     TGK_HI
#define     TGK_HI(_)   HALF_ITYPE:HALF_SNI(_),
#endif

#ifndef     TGK_HF
#define     TGK_HF(_)   HALF_FTYPE:HALF_SNF(_),
#endif

#ifndef     TGK_WU
#ifdef      WORD_LUTYPE
#define     TGK_WU(_)   WORD_UTYPE:WORD_SNU(_), WORD_LUTYPE:_##lu,
#endif

#ifndef     TGK_WU
#define     TGK_WU(_)   WORD_UTYPE:WORD_SNU(_),
#endif

#endif

#ifndef     TGK_WI
#ifdef      WORD_LITYPE
#define     TGK_WI(_)   WORD_ITYPE:WORD_SNI(_), WORD_LITYPE:_##li,
#endif

#ifndef     TGK_WI
#define     TGK_WI(_)   WORD_ITYPE:WORD_SNI(_),
#endif

#endif

#ifndef     TGK_WF
#ifndef     WORD_LFTYPE
#define     TGK_WF(_)   WORD_FTYPE:WORD_SNF(_),
#endif

#ifndef     TGK_WF
#define     TGK_WF(_)   WORD_FTYPE:WORD_SNF(_), WORD_LFTYPE:_##lf,
#endif

#endif

#ifndef     TGK_DU
#ifdef      DWRD_LUTYPE
#define     TGK_DU(_)   DWRD_UTYPE:DWRD_SNU(_), DWRD_LUTYPE:_##lu,
#endif

#ifndef     TGK_DU
#define     TGK_DU(_)   DWRD_UTYPE:DWRD_SNU(_),
#endif

#endif

#ifndef     TGK_DI
#ifdef      DWRD_LITYPE
#define     TGK_DI(_)   DWRD_ITYPE:DWRD_SNI(_), DWRD_LITYPE:_##li,
#endif

#ifndef     TGK_DI
#define     TGK_DI(_)   DWRD_ITYPE:DWRD_SNI(_),
#endif

#endif

#ifndef     TGK_DF

#ifndef     DWRD_LFTYPE
#define     TGK_DF(_)   DWRD_FTYPE:DWRD_SNF(_),
#endif

#ifndef     TGK_DF
#define     TGK_DF(_)   DWRD_FTYPE:DWRD_SNF(_), DWRD_LFTYPE:_##lf,
#endif

#endif



#define     TGK_YZ(_)   TGK_YU(_)
#define     TGK_BZ(_)   TGK_BU(_) TGK_BI(_)
#define     TGK_HZ(_)   TGK_HU(_) TGK_HI(_)
#define     TGK_WZ(_)   TGK_WU(_) TGK_WI(_)
#define     TGK_DZ(_)   TGK_DU(_) TGK_DI(_)

#define     TGK_YN(_)   TGK_YU(_)
#define     TGK_BN(_)   TGK_BU(_) TGK_BF(_)
#define     TGK_HN(_)   TGK_HU(_) TGK_HF(_)
#define     TGK_WN(_)   TGK_WU(_) TGK_WF(_)
#define     TGK_DN(_)   TGK_DU(_) TGK_DF(_)

#define     TGK_YS(_)
#define     TGK_BS(_)   TGK_BI(_) TGK_BF(_)
#define     TGK_HS(_)   TGK_HI(_) TGK_HF(_)
#define     TGK_WS(_)   TGK_WI(_) TGK_WF(_)
#define     TGK_DS(_)   TGK_DI(_) TGK_DF(_)

#define     TGK_YR(_)   TGK_YU(_)
#define     TGK_BR(_)   TGK_BU(_) TGK_BF(_) TGK_BI(_)
#define     TGK_HR(_)   TGK_HU(_) TGK_HF(_) TGK_HI(_)
#define     TGK_WR(_)   TGK_WU(_) TGK_WF(_) TGK_WI(_)
#define     TGK_DR(_)   TGK_DU(_) TGK_DF(_) TGK_DI(_)


#define     TGK_YBU(_)  TGK_YU(_) TGK_BU(_)
#define     TGK_YHU(_)  TGK_YU(_) TGK_BU(_) TGK_HU(_)
#define     TGK_YWU(_)  TGK_YU(_) TGK_BU(_) TGK_HU(_) TGK_WU(_)
#define     TGK_YDU(_)  TGK_YU(_) TGK_BU(_) TGK_HU(_) TGK_WU(_) TGK_DU(_)
#define     TGK_BHU(_)            TGK_BU(_) TGK_HU(_)
#define     TGK_BWU(_)            TGK_BU(_) TGK_HU(_) TGK_WU(_)
#define     TGK_BDU(_)            TGK_BU(_) TGK_HU(_) TGK_WU(_) TGK_DU(_)
#define     TGK_HWU(_)                      TGK_HU(_) TGK_WU(_)
#define     TGK_HDU(_)                      TGK_HU(_) TGK_WU(_) TGK_DU(_)
#define     TGK_WDU(_)                                TGK_WU(_) TGK_DU(_)

#define     TGK_YBI(_)  TGK_YI(_) TGK_BI(_)
#define     TGK_YHI(_)  TGK_YI(_) TGK_BI(_) TGK_HI(_)
#define     TGK_YWI(_)  TGK_YI(_) TGK_BI(_) TGK_HI(_) TGK_WI(_)
#define     TGK_YDI(_)  TGK_YI(_) TGK_BI(_) TGK_HI(_) TGK_WI(_) TGK_DI(_)
#define     TGK_BHI(_)            TGK_BI(_) TGK_HI(_)
#define     TGK_BWI(_)            TGK_BI(_) TGK_HI(_) TGK_WI(_)
#define     TGK_BDI(_)            TGK_BI(_) TGK_HI(_) TGK_WI(_) TGK_DI(_)
#define     TGK_HWI(_)                      TGK_HI(_) TGK_WI(_)
#define     TGK_HDI(_)                      TGK_HI(_) TGK_WI(_) TGK_DI(_)
#define     TGK_WDI(_)                                TGK_WI(_) TGK_DI(_)

#define     TGK_YBF(_)  TGK_YF(_) TGK_BF(_) TGK_HF(_)
#define     TGK_YHF(_)  TGK_YF(_) TGK_BF(_) TGK_HF(_)
#define     TGK_YWF(_)  TGK_YF(_) TGK_BF(_) TGK_HF(_) TGK_WF(_)
#define     TGK_YDF(_)  TGK_YI(_) TGK_BF(_) TGK_HF(_) TGK_WF(_) TGK_DF(_)
#define     TGK_BHF(_)            TGK_BF(_) TGK_HF(_)
#define     TGK_BWF(_)            TGK_BF(_) TGK_HF(_) TGK_WF(_)
#define     TGK_BDF(_)            TGK_BF(_) TGK_HF(_) TGK_WF(_) TGK_DF(_)
#define     TGK_HWF(_)                      TGK_HF(_) TGK_WF(_)
#define     TGK_HDF(_)                      TGK_HF(_) TGK_WF(_) TGK_DF(_)
#define     TGK_WDF(_)                                TGK_WF(_) TGK_DF(_)


#define     TGK_YBZ(_)  TGK_YZ(_) TGK_BZ(_)
#define     TGK_YHZ(_)  TGK_YZ(_) TGK_BZ(_) TGK_HZ(_)
#define     TGK_YWZ(_)  TGK_YZ(_) TGK_BZ(_) TGK_HZ(_) TGK_WZ(_)
#define     TGK_YDZ(_)  TGK_YZ(_) TGK_BZ(_) TGK_HZ(_) TGK_WZ(_) TGK_DZ(_)
#define     TGK_BHZ(_)            TGK_BZ(_) TGK_HZ(_)
#define     TGK_BWZ(_)            TGK_BZ(_) TGK_HZ(_) TGK_WZ(_)
#define     TGK_BDZ(_)            TGK_BZ(_) TGK_HZ(_) TGK_WZ(_) TGK_DZ(_)
#define     TGK_HWZ(_)                      TGK_HZ(_) TGK_WZ(_)
#define     TGK_HDZ(_)                      TGK_HZ(_) TGK_WZ(_) TGK_DZ(_)
#define     TGK_WDZ(_)                                TGK_WZ(_) TGK_DZ(_)

#define     TGK_YBN(_)  TGK_YN(_) TGK_BN(_)
#define     TGK_YHN(_)  TGK_YN(_) TGK_BN(_) TGK_HN(_)
#define     TGK_YWN(_)  TGK_YN(_) TGK_BN(_) TGK_HN(_) TGK_WN(_)
#define     TGK_YDN(_)  TGK_YN(_) TGK_BN(_) TGK_HN(_) TGK_WN(_) TGK_DN(_)
#define     TGK_BHN(_)            TGK_BN(_) TGK_HN(_)
#define     TGK_BWN(_)            TGK_BN(_) TGK_HN(_) TGK_WN(_)
#define     TGK_BDN(_)            TGK_BN(_) TGK_HN(_) TGK_WN(_) TGK_DN(_)
#define     TGK_HWN(_)                      TGK_HN(_) TGK_WN(_)
#define     TGK_HDN(_)                      TGK_HN(_) TGK_WN(_) TGK_DN(_)
#define     TGK_WDN(_)                                TGK_WN(_) TGK_DN(_)

#define     TGK_YBS(_)  TGK_YS(_) TGK_BS(_) TGK_HS(_)
#define     TGK_YHS(_)  TGK_YS(_) TGK_BS(_) TGK_HS(_)
#define     TGK_YWS(_)  TGK_YS(_) TGK_BS(_) TGK_HS(_) TGK_WS(_)
#define     TGK_YDS(_)  TGK_YS(_) TGK_BS(_) TGK_HS(_) TGK_WS(_) TGK_DS(_)
#define     TGK_BHS(_)            TGK_BS(_) TGK_HS(_)
#define     TGK_BWS(_)            TGK_BS(_) TGK_HS(_) TGK_WS(_)
#define     TGK_BDS(_)            TGK_BS(_) TGK_HS(_) TGK_WS(_) TGK_DS(_)
#define     TGK_HWS(_)                      TGK_HS(_) TGK_WS(_)
#define     TGK_HDS(_)                      TGK_HS(_) TGK_WS(_) TGK_DS(_)
#define     TGK_WDS(_)                                TGK_WS(_) TGK_DS(_)

#define     TGK_YBR(_)  TGK_YR(_) TGK_BR(_) TGK_HR(_)
#define     TGK_YHR(_)  TGK_YR(_) TGK_BR(_) TGK_HR(_)
#define     TGK_YWR(_)  TGK_YR(_) TGK_BR(_) TGK_HR(_) TGK_WR(_)
#define     TGK_YDR(_)  TGK_YR(_) TGK_BR(_) TGK_HR(_) TGK_WR(_) TGK_DR(_)
#define     TGK_BHR(_)            TGK_BR(_) TGK_HR(_)
#define     TGK_BWR(_)            TGK_BR(_) TGK_HR(_) TGK_WR(_)
#define     TGK_BDR(_)            TGK_BR(_) TGK_HR(_) TGK_WR(_) TGK_DR(_)
#define     TGK_HWR(_)                      TGK_HR(_) TGK_WR(_)
#define     TGK_HDR(_)                      TGK_HR(_) TGK_WR(_) TGK_DR(_)
#define     TGK_WDR(_)                                TGK_WR(_) TGK_DR(_)

#if _LEAVE_EXTGOP_TGK
}
#endif

#if _ENTER_EXTGOP_TGW
{
#endif

#ifndef     TGW_NONE
#define     TGW_NONE(_)
#endif

#if MY_EXTVEC_H
#   define  TGW_YU(_)   VWYU_TYPE:VWYU_SN(_),
#   define  TGW_YI(_)
#   define  TGW_YF(_)
#   define  TGW_BU(_)   VWBU_TYPE:VWBU_SN(_),
#   define  TGW_BI(_)   VWBI_TYPE:VWBI_SN(_),
#   define  TGW_BF(_)
#   define  TGW_HU(_)   VWHU_TYPE:VWHU_SN(_),
#   define  TGW_HI(_)   VWHI_TYPE:VWHI_SN(_),
#   define  TGW_HF(_)   VWHF_TYPE:VWHF_SN(_),
#   define  TGW_WU(_)   VWWU_TYPE:VWWU_SN(_),
#   define  TGW_WI(_)   VWWI_TYPE:VWWI_SN(_),
#   define  TGW_WF(_)   VWWF_TYPE:VWWF_SN(_),
#else
#   define  TGW_YU(_) //VWYU_TYPE:VWYU_SN(_),
#   define  TGW_YI(_)
#   define  TGW_YF(_)
#   define  TGW_BU(_) //VWBU_TYPE:VWBU_SN(_),
#   define  TGW_BI(_) //VWBI_TYPE:VWBI_SN(_),
#   define  TGW_BF(_)
#   define  TGW_HU(_) //VWHU_TYPE:VWHU_SN(_),
#   define  TGW_HI(_) //VWHI_TYPE:VWHI_SN(_),
#   define  TGW_HF(_) //VWHF_TYPE:VWHF_SN(_),
#   define  TGW_WU(_) //VWWU_TYPE:VWWU_SN(_),
#   define  TGW_WI(_) //VWWI_TYPE:VWWI_SN(_),
#   define  TGW_WF(_) //VWWF_TYPE:VWWF_SN(_),
#endif

#ifndef     TGW_DU
#define     TGW_DU(_)
#endif

#ifndef     TGW_DI
#define     TGW_DI(_)
#endif

#ifndef     TGW_DF
#define     TGW_DF(_)
#endif

#define     TGW_YZ(_)   TGW_YU(_) TGW_YI(_)
#define     TGW_BZ(_)   TGW_BU(_) TGW_BI(_)
#define     TGW_HZ(_)   TGW_HU(_) TGW_HI(_)
#define     TGW_WZ(_)   TGW_WU(_) TGW_WI(_)
#define     TGW_DZ(_)   TGW_DU(_) TGW_DI(_)

#define     TGW_YN(_)   TGW_YU(_)           TGW_YF(_)
#define     TGW_BN(_)   TGW_BU(_)           TGW_BF(_)
#define     TGW_HN(_)   TGW_HU(_)           TGW_HF(_)
#define     TGW_WN(_)   TGW_WU(_)           TGW_WF(_)
#define     TGW_DN(_)   TGW_DU(_)           TGW_DF(_)

#define     TGW_YS(_)             TGW_YI(_) TGW_YF(_)
#define     TGW_BS(_)             TGW_BI(_) TGW_BF(_)
#define     TGW_HS(_)             TGW_HI(_) TGW_HF(_)
#define     TGW_WS(_)             TGW_WI(_) TGW_WF(_)
#define     TGW_DS(_)             TGW_DI(_) TGW_DF(_)

#define     TGW_YR(_)   TGW_YU(_) TGW_YI(_) TGW_YF(_)
#define     TGW_BR(_)   TGW_BU(_) TGW_BI(_) TGW_BF(_)
#define     TGW_HR(_)   TGW_HU(_) TGW_HI(_) TGW_HF(_)
#define     TGW_WR(_)   TGW_WU(_) TGW_WI(_) TGW_WF(_)
#define     TGW_DR(_)   TGW_DU(_) TGW_DI(_) TGW_DF(_)

#define     TGW_YBU(_)  TGW_YU(_) TGW_BU(_)
#define     TGW_YHU(_)  TGW_YU(_) TGW_BU(_) TGW_HU(_)
#define     TGW_YWU(_)  TGW_YU(_) TGW_BU(_) TGW_HU(_) TGW_WU(_)
#define     TGW_YDU(_)  TGW_YU(_) TGW_BU(_) TGW_HU(_) TGW_WU(_) TGW_DU(_)
#define     TGW_BHU(_)            TGW_BU(_) TGW_HU(_)
#define     TGW_BWU(_)            TGW_BU(_) TGW_HU(_) TGW_WU(_)
#define     TGW_BDU(_)            TGW_BU(_) TGW_HU(_) TGW_WU(_) TGW_DU(_)
#define     TGW_HWU(_)                      TGW_HU(_) TGW_WU(_)
#define     TGW_HDU(_)                      TGW_HU(_) TGW_WU(_) TGW_DU(_)
#define     TGW_WDU(_)                                TGW_WU(_) TGW_DU(_)

#define     TGW_YBI(_)  TGW_YI(_) TGW_BI(_)
#define     TGW_YHI(_)  TGW_YI(_) TGW_BI(_) TGW_HI(_)
#define     TGW_YWI(_)  TGW_YI(_) TGW_BI(_) TGW_HI(_) TGW_WI(_)
#define     TGW_YDI(_)  TGW_YI(_) TGW_BI(_) TGW_HI(_) TGW_WI(_) TGW_DI(_)
#define     TGW_BHI(_)            TGW_BI(_) TGW_HI(_)
#define     TGW_BWI(_)            TGW_BI(_) TGW_HI(_) TGW_WI(_)
#define     TGW_BDI(_)            TGW_BI(_) TGW_HI(_) TGW_WI(_) TGW_DI(_)
#define     TGW_HWI(_)                      TGW_HI(_) TGW_WI(_)
#define     TGW_HDI(_)                      TGW_HI(_) TGW_WI(_) TGW_DI(_)
#define     TGW_WDI(_)                                TGW_WI(_) TGW_DI(_)

#define     TGW_YBF(_)  TGW_YF(_) TGW_BF(_)
#define     TGW_YHF(_)  TGW_YF(_) TGW_BF(_) TGW_HF(_)
#define     TGW_YWF(_)  TGW_YF(_) TGW_BF(_) TGW_HF(_) TGW_WF(_)
#define     TGW_YDF(_)  TGW_YF(_) TGW_BF(_) TGW_HF(_) TGW_WF(_) TGW_DF(_)
#define     TGW_BHF(_)            TGW_BF(_) TGW_HF(_)
#define     TGW_BWF(_)            TGW_BF(_) TGW_HF(_) TGW_WF(_)
#define     TGW_BDF(_)            TGW_BF(_) TGW_HF(_) TGW_WF(_) TGW_DF(_)
#define     TGW_HWF(_)                      TGW_HF(_) TGW_WF(_)
#define     TGW_HDF(_)                      TGW_HF(_) TGW_WF(_) TGW_DF(_)
#define     TGW_WDF(_)                                TGW_WF(_) TGW_DF(_)

#define     TGW_YBZ(_)  TGW_YZ(_) TGW_BZ(_)
#define     TGW_YHZ(_)  TGW_YZ(_) TGW_BZ(_) TGW_HZ(_)
#define     TGW_YWZ(_)  TGW_YZ(_) TGW_BZ(_) TGW_HZ(_) TGW_WZ(_)
#define     TGW_YDZ(_)  TGW_YZ(_) TGW_BZ(_) TGW_HZ(_) TGW_WZ(_) TGW_DZ(_)
#define     TGW_BHZ(_)            TGW_BZ(_) TGW_HZ(_)
#define     TGW_BWZ(_)            TGW_BZ(_) TGW_HZ(_) TGW_WZ(_)
#define     TGW_BDZ(_)            TGW_BZ(_) TGW_HZ(_) TGW_WZ(_) TGW_DZ(_)
#define     TGW_HWZ(_)                      TGW_HZ(_) TGW_WZ(_)
#define     TGW_HDZ(_)                      TGW_HZ(_) TGW_WZ(_) TGW_DZ(_)
#define     TGW_WDZ(_)                                TGW_WZ(_) TGW_DZ(_)

#define     TGW_YBN(_)  TGW_YN(_) TGW_BN(_)
#define     TGW_YHN(_)  TGW_YN(_) TGW_BN(_) TGW_HN(_)
#define     TGW_YWN(_)  TGW_YN(_) TGW_BN(_) TGW_HN(_) TGW_WN(_)
#define     TGW_YDN(_)  TGW_YN(_) TGW_BN(_) TGW_HN(_) TGW_WN(_) TGW_DN(_)
#define     TGW_BHN(_)            TGW_BN(_) TGW_HN(_)
#define     TGW_BWN(_)            TGW_BN(_) TGW_HN(_) TGW_WN(_)
#define     TGW_BDN(_)            TGW_BN(_) TGW_HN(_) TGW_WN(_) TGW_DN(_)
#define     TGW_HWN(_)                      TGW_HN(_) TGW_WN(_)
#define     TGW_HDN(_)                      TGW_HN(_) TGW_WN(_) TGW_DN(_)
#define     TGW_WDN(_)                                TGW_WN(_) TGW_DN(_)

#define     TGW_YBS(_)  TGW_YS(_) TGW_BS(_)
#define     TGW_YHS(_)  TGW_YS(_) TGW_BS(_) TGW_HS(_)
#define     TGW_YWS(_)  TGW_YS(_) TGW_BS(_) TGW_HS(_) TGW_WS(_)
#define     TGW_YDS(_)  TGW_YS(_) TGW_BS(_) TGW_HS(_) TGW_WS(_) TGW_DS(_)
#define     TGW_BHS(_)            TGW_BS(_) TGW_HS(_)
#define     TGW_BWS(_)            TGW_BS(_) TGW_HS(_) TGW_WS(_)
#define     TGW_BDS(_)            TGW_BS(_) TGW_HS(_) TGW_WS(_) TGW_DS(_)
#define     TGW_HWS(_)                      TGW_HS(_) TGW_WS(_)
#define     TGW_HDS(_)                      TGW_HS(_) TGW_WS(_) TGW_DS(_)
#define     TGW_WDS(_)                                TGW_WS(_) TGW_DS(_)

#define     TGW_YBR(_)  TGW_YR(_) TGW_BR(_)
#define     TGW_YHR(_)  TGW_YR(_) TGW_BR(_) TGW_HR(_)
#define     TGW_YWR(_)  TGW_YR(_) TGW_BR(_) TGW_HR(_) TGW_WR(_)
#define     TGW_YDR(_)  TGW_YR(_) TGW_BR(_) TGW_HR(_) TGW_WR(_) TGW_DR(_)
#define     TGW_BHR(_)            TGW_BR(_) TGW_HR(_)
#define     TGW_BWR(_)            TGW_BR(_) TGW_HR(_) TGW_WR(_)
#define     TGW_BDR(_)            TGW_BR(_) TGW_HR(_) TGW_WR(_) TGW_DR(_)
#define     TGW_HWR(_)                      TGW_HR(_) TGW_WR(_)
#define     TGW_HDR(_)                      TGW_HR(_) TGW_WR(_) TGW_DR(_)
#define     TGW_WDR(_)                                TGW_WR(_) TGW_DR(_)

#if _LEAVE_EXTGOP_TGW
}
#endif

#if _ENTER_EXTGOP_TGD
{
#endif

#ifndef     TGD_NONE
#define     TGD_NONE(_)
#endif

#if MY_EXTVEC_H
#   define  TGD_YU(_)   VDYU_TYPE:VDYU_SN(_),
#   define  TGD_YI(_)
#   define  TGD_YF(_)
#   define  TGD_BU(_)   VDBU_TYPE:VDBU_SN(_),
#   define  TGD_BI(_)   VDBI_TYPE:VDBI_SN(_),
#   define  TGD_BF(_)
#   define  TGD_HU(_)   VDHU_TYPE:VDHU_SN(_),
#   define  TGD_HI(_)   VDHI_TYPE:VDHI_SN(_),
#   define  TGD_HF(_)   VDHF_TYPE:VDHF_SN(_),
#   define  TGD_WU(_)   VDWU_TYPE:VDWU_SN(_),
#   define  TGD_WI(_)   VDWI_TYPE:VDWI_SN(_),
#   define  TGD_WF(_)   VDWF_TYPE:VDWF_SN(_),
#   define  TGD_DU(_)   VDDU_TYPE:VDDU_SN(_),
#   define  TGD_DI(_)   VDDI_TYPE:VDDI_SN(_),
#   define  TGD_DF(_)   VDDF_TYPE:VDDF_SN(_),
#else
#   define  TGD_YU(_) //VDYU_TYPE:VDYU_SN(_),
#   define  TGD_YI(_)
#   define  TGD_YF(_)
#   define  TGD_BU(_) //VDBU_TYPE:VDBU_SN(_),
#   define  TGD_BI(_) //VDBI_TYPE:VDBI_SN(_),
#   define  TGD_BF(_)
#   define  TGD_HU(_) //VDHU_TYPE:VDHU_SN(_),
#   define  TGD_HI(_) //VDHI_TYPE:VDHI_SN(_),
#   define  TGD_HF(_) //VDHF_TYPE:VDHF_SN(_),
#   define  TGD_WU(_) //VDWU_TYPE:VDWU_SN(_),
#   define  TGD_WI(_) //VDWI_TYPE:VDWI_SN(_),
#   define  TGD_WF(_) //VDWF_TYPE:VDWF_SN(_),
#   define  TGD_DU(_) //VDDU_TYPE:VDDU_SN(_),
#   define  TGD_DI(_) //VDDI_TYPE:VDDI_SN(_),
#   define  TGD_DF(_) //VDDF_TYPE:VDDF_SN(_),
#endif

#define     TGD_YZ(_)   TGD_YU(_) TGD_YI(_)
#define     TGD_BZ(_)   TGD_BU(_) TGD_BI(_)
#define     TGD_HZ(_)   TGD_HU(_) TGD_HI(_)
#define     TGD_WZ(_)   TGD_WU(_) TGD_WI(_)
#define     TGD_DZ(_)   TGD_DU(_) TGD_DI(_)

#define     TGD_YN(_)   TGD_YU(_)           TGD_YF(_)
#define     TGD_BN(_)   TGD_BU(_)           TGD_BF(_)
#define     TGD_HN(_)   TGD_HU(_)           TGD_HF(_)
#define     TGD_WN(_)   TGD_WU(_)           TGD_WF(_)
#define     TGD_DN(_)   TGD_DU(_)           TGD_DF(_)

#define     TGD_YS(_)             TGD_YI(_) TGD_YF(_)
#define     TGD_BS(_)             TGD_BI(_) TGD_BF(_)
#define     TGD_HS(_)             TGD_HI(_) TGD_HF(_)
#define     TGD_WS(_)             TGD_WI(_) TGD_WF(_)
#define     TGD_DS(_)             TGD_DI(_) TGD_DF(_)

#define     TGD_YR(_)   TGD_YU(_) TGD_YI(_) TGD_YF(_)
#define     TGD_BR(_)   TGD_BU(_) TGD_BI(_) TGD_BF(_)
#define     TGD_HR(_)   TGD_HU(_) TGD_HI(_) TGD_HF(_)
#define     TGD_WR(_)   TGD_WU(_) TGD_WI(_) TGD_WF(_)
#define     TGD_DR(_)   TGD_DU(_) TGD_DI(_) TGD_DF(_)

#define     TGD_YBU(_)  TGD_YU(_) TGD_BU(_)
#define     TGD_YHU(_)  TGD_YU(_) TGD_BU(_) TGD_HU(_)
#define     TGD_YWU(_)  TGD_YU(_) TGD_BU(_) TGD_HU(_) TGD_WU(_)
#define     TGD_YDU(_)  TGD_YU(_) TGD_BU(_) TGD_HU(_) TGD_WU(_) TGD_DU(_)
#define     TGD_BHU(_)            TGD_BU(_) TGD_HU(_)
#define     TGD_BWU(_)            TGD_BU(_) TGD_HU(_) TGD_WU(_)
#define     TGD_BDU(_)            TGD_BU(_) TGD_HU(_) TGD_WU(_) TGD_DU(_)
#define     TGD_HWU(_)                      TGD_HU(_) TGD_WU(_)
#define     TGD_HDU(_)                      TGD_HU(_) TGD_WU(_) TGD_DU(_)
#define     TGD_WDU(_)                                TGD_WU(_) TGD_DU(_)

#define     TGD_YBI(_)  TGD_YI(_) TGD_BI(_)
#define     TGD_YHI(_)  TGD_YI(_) TGD_BI(_) TGD_HI(_)
#define     TGD_YWI(_)  TGD_YI(_) TGD_BI(_) TGD_HI(_) TGD_WI(_)
#define     TGD_YDI(_)  TGD_YI(_) TGD_BI(_) TGD_HI(_) TGD_WI(_) TGD_DI(_)
#define     TGD_BHI(_)            TGD_BI(_) TGD_HI(_)
#define     TGD_BWI(_)            TGD_BI(_) TGD_HI(_) TGD_WI(_)
#define     TGD_BDI(_)            TGD_BI(_) TGD_HI(_) TGD_WI(_) TGD_DI(_)
#define     TGD_HWI(_)                      TGD_HI(_) TGD_WI(_)
#define     TGD_HDI(_)                      TGD_HI(_) TGD_WI(_) TGD_DI(_)
#define     TGD_WDI(_)                                TGD_WI(_) TGD_DI(_)

#define     TGD_YBF(_)  TGD_YF(_) TGD_BF(_)
#define     TGD_YHF(_)  TGD_YF(_) TGD_BF(_) TGD_HF(_)
#define     TGD_YWF(_)  TGD_YF(_) TGD_BF(_) TGD_HF(_) TGD_WF(_)
#define     TGD_YDF(_)  TGD_YF(_) TGD_BF(_) TGD_HF(_) TGD_WF(_) TGD_DF(_)
#define     TGD_BHF(_)            TGD_BF(_) TGD_HF(_)
#define     TGD_BWF(_)            TGD_BF(_) TGD_HF(_) TGD_WF(_)
#define     TGD_BDF(_)            TGD_BF(_) TGD_HF(_) TGD_WF(_) TGD_DF(_)
#define     TGD_HWF(_)                      TGD_HF(_) TGD_WF(_)
#define     TGD_HDF(_)                      TGD_HF(_) TGD_WF(_) TGD_DF(_)
#define     TGD_WDF(_)                                TGD_WF(_) TGD_DF(_)

#define     TGD_YBZ(_)  TGD_YZ(_) TGD_BZ(_)
#define     TGD_YHZ(_)  TGD_YZ(_) TGD_BZ(_) TGD_HZ(_)
#define     TGD_YWZ(_)  TGD_YZ(_) TGD_BZ(_) TGD_HZ(_) TGD_WZ(_)
#define     TGD_YDZ(_)  TGD_YZ(_) TGD_BZ(_) TGD_HZ(_) TGD_WZ(_) TGD_DZ(_)
#define     TGD_BHZ(_)            TGD_BZ(_) TGD_HZ(_)
#define     TGD_BWZ(_)            TGD_BZ(_) TGD_HZ(_) TGD_WZ(_)
#define     TGD_BDZ(_)            TGD_BZ(_) TGD_HZ(_) TGD_WZ(_) TGD_DZ(_)
#define     TGD_HWZ(_)                      TGD_HZ(_) TGD_WZ(_)
#define     TGD_HDZ(_)                      TGD_HZ(_) TGD_WZ(_) TGD_DZ(_)
#define     TGD_WDZ(_)                                TGD_WZ(_) TGD_DZ(_)

#define     TGD_YBN(_)  TGD_YN(_) TGD_BN(_)
#define     TGD_YHN(_)  TGD_YN(_) TGD_BN(_) TGD_HN(_)
#define     TGD_YWN(_)  TGD_YN(_) TGD_BN(_) TGD_HN(_) TGD_WN(_)
#define     TGD_YDN(_)  TGD_YN(_) TGD_BN(_) TGD_HN(_) TGD_WN(_) TGD_DN(_)
#define     TGD_BHN(_)            TGD_BN(_) TGD_HN(_)
#define     TGD_BWN(_)            TGD_BN(_) TGD_HN(_) TGD_WN(_)
#define     TGD_BDN(_)            TGD_BN(_) TGD_HN(_) TGD_WN(_) TGD_DN(_)
#define     TGD_HWN(_)                      TGD_HN(_) TGD_WN(_)
#define     TGD_HDN(_)                      TGD_HN(_) TGD_WN(_) TGD_DN(_)
#define     TGD_WDN(_)                                TGD_WN(_) TGD_DN(_)

#define     TGD_YBS(_)  TGD_YS(_) TGD_BS(_)
#define     TGD_YHS(_)  TGD_YS(_) TGD_BS(_) TGD_HS(_)
#define     TGD_YWS(_)  TGD_YS(_) TGD_BS(_) TGD_HS(_) TGD_WS(_)
#define     TGD_YDS(_)  TGD_YS(_) TGD_BS(_) TGD_HS(_) TGD_WS(_) TGD_DS(_)
#define     TGD_BHS(_)            TGD_BS(_) TGD_HS(_)
#define     TGD_BWS(_)            TGD_BS(_) TGD_HS(_) TGD_WS(_)
#define     TGD_BDS(_)            TGD_BS(_) TGD_HS(_) TGD_WS(_) TGD_DS(_)
#define     TGD_HWS(_)                      TGD_HS(_) TGD_WS(_)
#define     TGD_HDS(_)                      TGD_HS(_) TGD_WS(_) TGD_DS(_)
#define     TGD_WDS(_)                                TGD_WS(_) TGD_DS(_)

#define     TGD_YBR(_)  TGD_YR(_) TGD_BR(_)
#define     TGD_YHR(_)  TGD_YR(_) TGD_BR(_) TGD_HR(_)
#define     TGD_YWR(_)  TGD_YR(_) TGD_BR(_) TGD_HR(_) TGD_WR(_)
#define     TGD_YDR(_)  TGD_YR(_) TGD_BR(_) TGD_HR(_) TGD_WR(_) TGD_DR(_)
#define     TGD_BHR(_)            TGD_BR(_) TGD_HR(_)
#define     TGD_BWR(_)            TGD_BR(_) TGD_HR(_) TGD_WR(_)
#define     TGD_BDR(_)            TGD_BR(_) TGD_HR(_) TGD_WR(_) TGD_DR(_)
#define     TGD_HWR(_)                      TGD_HR(_) TGD_WR(_)
#define     TGD_HDR(_)                      TGD_HR(_) TGD_WR(_) TGD_DR(_)
#define     TGD_WDR(_)                                TGD_WR(_) TGD_DR(_)

#if _LEAVE_EXTGOP_TGD
}
#endif

#if _ENTER_EXTGOP_TGQ
{
#endif

#ifndef     TGQ_NONE
#define     TGQ_NONE(_)
#endif


#if MY_EXTVEC_H
#   define  TGQ_YU(_)   VQYU_TYPE:VQYU_SN(_),
#   define  TGQ_YI(_)
#   define  TGQ_YF(_)
#   define  TGQ_BU(_)   VQBU_TYPE:VQBU_SN(_),
#   define  TGQ_BI(_)   VQBI_TYPE:VQBI_SN(_),
#   define  TGQ_BF(_)
#   define  TGQ_HU(_)   VQHU_TYPE:VQHU_SN(_),
#   define  TGQ_HI(_)   VQHI_TYPE:VQHI_SN(_),
#   define  TGQ_HF(_)   VQHF_TYPE:VQHF_SN(_),
#   define  TGQ_WU(_)   VQWU_TYPE:VQWU_SN(_),
#   define  TGQ_WI(_)   VQWI_TYPE:VQWI_SN(_),
#   define  TGQ_WF(_)   VQWF_TYPE:VQWF_SN(_),
#   define  TGQ_DU(_)   VQDU_TYPE:VQDU_SN(_),
#   define  TGQ_DI(_)   VQDI_TYPE:VQDI_SN(_),
#   define  TGQ_DF(_)   VQDF_TYPE:VQDF_SN(_),
#else
#   define  TGQ_YU(_) //VQYU_TYPE:VQYU_SN(_),
#   define  TGQ_YI(_)
#   define  TGQ_YF(_)
#   define  TGQ_BU(_) //VQBU_TYPE:VQBU_SN(_),
#   define  TGQ_BI(_) //VQBI_TYPE:VQBI_SN(_),
#   define  TGQ_BF(_)
#   define  TGQ_HU(_) //VQHU_TYPE:VQHU_SN(_),
#   define  TGQ_HI(_) //VQHI_TYPE:VQHI_SN(_),
#   define  TGQ_HF(_) //VQHF_TYPE:VQHF_SN(_),
#   define  TGQ_WU(_) //VQWU_TYPE:VQWU_SN(_),
#   define  TGQ_WI(_) //VQWI_TYPE:VQWI_SN(_),
#   define  TGQ_WF(_) //VQWF_TYPE:VQWF_SN(_),
#   define  TGQ_DU(_) //VQDU_TYPE:VQDU_SN(_),
#   define  TGQ_DI(_) //VQDI_TYPE:VQDI_SN(_),
#   define  TGQ_DF(_) //VQDF_TYPE:VQDF_SN(_),
#endif

#define     TGQ_YZ(_)   TGQ_YU(_) TGQ_YI(_)
#define     TGQ_BZ(_)   TGQ_BU(_) TGQ_BI(_)
#define     TGQ_HZ(_)   TGQ_HU(_) TGQ_HI(_)
#define     TGQ_WZ(_)   TGQ_WU(_) TGQ_WI(_)
#define     TGQ_DZ(_)   TGQ_DU(_) TGQ_DI(_)

#define     TGQ_YN(_)   TGQ_YU(_)           TGQ_YF(_)
#define     TGQ_BN(_)   TGQ_BU(_)           TGQ_BF(_)
#define     TGQ_HN(_)   TGQ_HU(_)           TGQ_HF(_)
#define     TGQ_WN(_)   TGQ_WU(_)           TGQ_WF(_)
#define     TGQ_DN(_)   TGQ_DU(_)           TGQ_DF(_)

#define     TGQ_YS(_)             TGQ_YI(_) TGQ_YF(_)
#define     TGQ_BS(_)             TGQ_BI(_) TGQ_BF(_)
#define     TGQ_HS(_)             TGQ_HI(_) TGQ_HF(_)
#define     TGQ_WS(_)             TGQ_WI(_) TGQ_WF(_)
#define     TGQ_DS(_)             TGQ_DI(_) TGQ_DF(_)

#define     TGQ_YR(_)   TGQ_YU(_) TGQ_YI(_) TGQ_YF(_)
#define     TGQ_BR(_)   TGQ_BU(_) TGQ_BI(_) TGQ_BF(_)
#define     TGQ_HR(_)   TGQ_HU(_) TGQ_HI(_) TGQ_HF(_)
#define     TGQ_WR(_)   TGQ_WU(_) TGQ_WI(_) TGQ_WF(_)
#define     TGQ_DR(_)   TGQ_DU(_) TGQ_DI(_) TGQ_DF(_)

#define     TGQ_YBU(_)  TGQ_YU(_) TGQ_BU(_)
#define     TGQ_YHU(_)  TGQ_YU(_) TGQ_BU(_) TGQ_HU(_)
#define     TGQ_YWU(_)  TGQ_YU(_) TGQ_BU(_) TGQ_HU(_) TGQ_WU(_)
#define     TGQ_YDU(_)  TGQ_YU(_) TGQ_BU(_) TGQ_HU(_) TGQ_WU(_) TGQ_DU(_)
#define     TGQ_BHU(_)            TGQ_BU(_) TGQ_HU(_)
#define     TGQ_BWU(_)            TGQ_BU(_) TGQ_HU(_) TGQ_WU(_)
#define     TGQ_BDU(_)            TGQ_BU(_) TGQ_HU(_) TGQ_WU(_) TGQ_DU(_)
#define     TGQ_HWU(_)                      TGQ_HU(_) TGQ_WU(_)
#define     TGQ_HDU(_)                      TGQ_HU(_) TGQ_WU(_) TGQ_DU(_)
#define     TGQ_WDU(_)                                TGQ_WU(_) TGQ_DU(_)

#define     TGQ_YBI(_)  TGQ_YI(_) TGQ_BI(_)
#define     TGQ_YHI(_)  TGQ_YI(_) TGQ_BI(_) TGQ_HI(_)
#define     TGQ_YWI(_)  TGQ_YI(_) TGQ_BI(_) TGQ_HI(_) TGQ_WI(_)
#define     TGQ_YDI(_)  TGQ_YI(_) TGQ_BI(_) TGQ_HI(_) TGQ_WI(_) TGQ_DI(_)
#define     TGQ_BHI(_)            TGQ_BI(_) TGQ_HI(_)
#define     TGQ_BWI(_)            TGQ_BI(_) TGQ_HI(_) TGQ_WI(_)
#define     TGQ_BDI(_)            TGQ_BI(_) TGQ_HI(_) TGQ_WI(_) TGQ_DI(_)
#define     TGQ_HWI(_)                      TGQ_HI(_) TGQ_WI(_)
#define     TGQ_HDI(_)                      TGQ_HI(_) TGQ_WI(_) TGQ_DI(_)
#define     TGQ_WDI(_)                                TGQ_WI(_) TGQ_DI(_)

#define     TGQ_YBF(_)  TGQ_YF(_) TGQ_BF(_)
#define     TGQ_YHF(_)  TGQ_YF(_) TGQ_BF(_) TGQ_HF(_)
#define     TGQ_YWF(_)  TGQ_YF(_) TGQ_BF(_) TGQ_HF(_) TGQ_WF(_)
#define     TGQ_YDF(_)  TGQ_YF(_) TGQ_BF(_) TGQ_HF(_) TGQ_WF(_) TGQ_DF(_)
#define     TGQ_BHF(_)            TGQ_BF(_) TGQ_HF(_)
#define     TGQ_BWF(_)            TGQ_BF(_) TGQ_HF(_) TGQ_WF(_)
#define     TGQ_BDF(_)            TGQ_BF(_) TGQ_HF(_) TGQ_WF(_) TGQ_DF(_)
#define     TGQ_HWF(_)                      TGQ_HF(_) TGQ_WF(_)
#define     TGQ_HDF(_)                      TGQ_HF(_) TGQ_WF(_) TGQ_DF(_)
#define     TGQ_WDF(_)                                TGQ_WF(_) TGQ_DF(_)

#define     TGQ_YBZ(_)  TGQ_YZ(_) TGQ_BZ(_)
#define     TGQ_YHZ(_)  TGQ_YZ(_) TGQ_BZ(_) TGQ_HZ(_)
#define     TGQ_YWZ(_)  TGQ_YZ(_) TGQ_BZ(_) TGQ_HZ(_) TGQ_WZ(_)
#define     TGQ_YDZ(_)  TGQ_YZ(_) TGQ_BZ(_) TGQ_HZ(_) TGQ_WZ(_) TGQ_DZ(_)
#define     TGQ_BHZ(_)            TGQ_BZ(_) TGQ_HZ(_)
#define     TGQ_BWZ(_)            TGQ_BZ(_) TGQ_HZ(_) TGQ_WZ(_)
#define     TGQ_BDZ(_)            TGQ_BZ(_) TGQ_HZ(_) TGQ_WZ(_) TGQ_DZ(_)
#define     TGQ_HWZ(_)                      TGQ_HZ(_) TGQ_WZ(_)
#define     TGQ_HDZ(_)                      TGQ_HZ(_) TGQ_WZ(_) TGQ_DZ(_)
#define     TGQ_WDZ(_)                                TGQ_WZ(_) TGQ_DZ(_)

#define     TGQ_YBN(_)  TGQ_YN(_) TGQ_BN(_)
#define     TGQ_YHN(_)  TGQ_YN(_) TGQ_BN(_) TGQ_HN(_)
#define     TGQ_YWN(_)  TGQ_YN(_) TGQ_BN(_) TGQ_HN(_) TGQ_WN(_)
#define     TGQ_YDN(_)  TGQ_YN(_) TGQ_BN(_) TGQ_HN(_) TGQ_WN(_) TGQ_DN(_)
#define     TGQ_BHN(_)            TGQ_BN(_) TGQ_HN(_)
#define     TGQ_BWN(_)            TGQ_BN(_) TGQ_HN(_) TGQ_WN(_)
#define     TGQ_BDN(_)            TGQ_BN(_) TGQ_HN(_) TGQ_WN(_) TGQ_DN(_)
#define     TGQ_HWN(_)                      TGQ_HN(_) TGQ_WN(_)
#define     TGQ_HDN(_)                      TGQ_HN(_) TGQ_WN(_) TGQ_DN(_)
#define     TGQ_WDN(_)                                TGQ_WN(_) TGQ_DN(_)

#define     TGQ_YBS(_)  TGQ_YS(_) TGQ_BS(_)
#define     TGQ_YHS(_)  TGQ_YS(_) TGQ_BS(_) TGQ_HS(_)
#define     TGQ_YWS(_)  TGQ_YS(_) TGQ_BS(_) TGQ_HS(_) TGQ_WS(_)
#define     TGQ_YDS(_)  TGQ_YS(_) TGQ_BS(_) TGQ_HS(_) TGQ_WS(_) TGQ_DS(_)
#define     TGQ_BHS(_)            TGQ_BS(_) TGQ_HS(_)
#define     TGQ_BWS(_)            TGQ_BS(_) TGQ_HS(_) TGQ_WS(_)
#define     TGQ_BDS(_)            TGQ_BS(_) TGQ_HS(_) TGQ_WS(_) TGQ_DS(_)
#define     TGQ_HWS(_)                      TGQ_HS(_) TGQ_WS(_)
#define     TGQ_HDS(_)                      TGQ_HS(_) TGQ_WS(_) TGQ_DS(_)
#define     TGQ_WDS(_)                                TGQ_WS(_) TGQ_DS(_)

#define     TGQ_YBR(_)  TGQ_YR(_) TGQ_BR(_)
#define     TGQ_YHR(_)  TGQ_YR(_) TGQ_BR(_) TGQ_HR(_)
#define     TGQ_YWR(_)  TGQ_YR(_) TGQ_BR(_) TGQ_HR(_) TGQ_WR(_)
#define     TGQ_YDR(_)  TGQ_YR(_) TGQ_BR(_) TGQ_HR(_) TGQ_WR(_) TGQ_DR(_)
#define     TGQ_BHR(_)            TGQ_BR(_) TGQ_HR(_)
#define     TGQ_BWR(_)            TGQ_BR(_) TGQ_HR(_) TGQ_WR(_)
#define     TGQ_BDR(_)            TGQ_BR(_) TGQ_HR(_) TGQ_WR(_) TGQ_DR(_)
#define     TGQ_HWR(_)                      TGQ_HR(_) TGQ_WR(_)
#define     TGQ_HDR(_)                      TGQ_HR(_) TGQ_WR(_) TGQ_DR(_)
#define     TGQ_WDR(_)                                TGQ_WR(_) TGQ_DR(_)

#if _LEAVE_EXTGOP_TGQ
}
#endif

#if _ENTER_EXTGOP_TGO
{
#endif

#ifndef     TGO_NONE
#define     TGO_NONE(_)
#endif

#if MY_EXTVEC_H
#   define  TGO_YU(_)   VOYU_TYPE:VOYU_SN(_),
#   define  TGO_YI(_)
#   define  TGO_YF(_)
#   define  TGO_BU(_)   VOBU_TYPE:VOBU_SN(_),
#   define  TGO_BI(_)   VOBI_TYPE:VOBI_SN(_),
#   define  TGO_BF(_)
#   define  TGO_HU(_)   VOHU_TYPE:VOHU_SN(_),
#   define  TGO_HI(_)   VOHI_TYPE:VOHI_SN(_),
#   define  TGO_HF(_)   VOHF_TYPE:VOHF_SN(_),
#   define  TGO_WU(_)   VOWU_TYPE:VOWU_SN(_),
#   define  TGO_WI(_)   VOWI_TYPE:VOWI_SN(_),
#   define  TGO_WF(_)   VOWF_TYPE:VOWF_SN(_),
#   define  TGO_DU(_)   VODU_TYPE:VODU_SN(_),
#   define  TGO_DI(_)   VODI_TYPE:VODI_SN(_),
#   define  TGO_DF(_)   VODF_TYPE:VODF_SN(_),
#else
#   define  TGO_YU(_) //VOYU_TYPE:VOYU_SN(_),
#   define  TGO_YI(_)
#   define  TGO_YF(_)
#   define  TGO_BU(_) //VOBU_TYPE:VOBU_SN(_),
#   define  TGO_BI(_) //VOBI_TYPE:VOBI_SN(_),
#   define  TGO_BF(_)
#   define  TGO_HU(_) //VOHU_TYPE:VOHU_SN(_),
#   define  TGO_HI(_) //VOHI_TYPE:VOHI_SN(_),
#   define  TGO_HF(_) //VOHF_TYPE:VOHF_SN(_),
#   define  TGO_WU(_) //VOWU_TYPE:VOWU_SN(_),
#   define  TGO_WI(_) //VOWI_TYPE:VOWI_SN(_),
#   define  TGO_WF(_) //VOWF_TYPE:VOWF_SN(_),
#   define  TGO_DU(_) //VODU_TYPE:VODU_SN(_),
#   define  TGO_DI(_) //VODI_TYPE:VODI_SN(_),
#   define  TGO_DF(_) //VODF_TYPE:VODF_SN(_),
#endif // #if MY_EXTVEC_H

#define     TGO_YZ(_)   TGO_YU(_) TGO_YI(_)
#define     TGO_BZ(_)   TGO_BU(_) TGO_BI(_)
#define     TGO_HZ(_)   TGO_HU(_) TGO_HI(_)
#define     TGO_WZ(_)   TGO_WU(_) TGO_WI(_)
#define     TGO_DZ(_)   TGO_DU(_) TGO_DI(_)

#define     TGO_YN(_)   TGO_YU(_)           TGO_YF(_)
#define     TGO_BN(_)   TGO_BU(_)           TGO_BF(_)
#define     TGO_HN(_)   TGO_HU(_)           TGO_HF(_)
#define     TGO_WN(_)   TGO_WU(_)           TGO_WF(_)
#define     TGO_DN(_)   TGO_DU(_)           TGO_DF(_)

#define     TGO_YS(_)             TGO_YI(_) TGO_YF(_)
#define     TGO_BS(_)             TGO_BI(_) TGO_BF(_)
#define     TGO_HS(_)             TGO_HI(_) TGO_HF(_)
#define     TGO_WS(_)             TGO_WI(_) TGO_WF(_)
#define     TGO_DS(_)             TGO_DI(_) TGO_DF(_)

#define     TGO_YR(_)   TGO_YU(_) TGO_YI(_) TGO_YF(_)
#define     TGO_BR(_)   TGO_BU(_) TGO_BI(_) TGO_BF(_)
#define     TGO_HR(_)   TGO_HU(_) TGO_HI(_) TGO_HF(_)
#define     TGO_WR(_)   TGO_WU(_) TGO_WI(_) TGO_WF(_)
#define     TGO_DR(_)   TGO_DU(_) TGO_DI(_) TGO_DF(_)

#define     TGO_YBU(_)  TGO_YU(_) TGO_BU(_)
#define     TGO_YHU(_)  TGO_YU(_) TGO_BU(_) TGO_HU(_)
#define     TGO_YWU(_)  TGO_YU(_) TGO_BU(_) TGO_HU(_) TGO_WU(_)
#define     TGO_YDU(_)  TGO_YU(_) TGO_BU(_) TGO_HU(_) TGO_WU(_) TGO_DU(_)
#define     TGO_BHU(_)            TGO_BU(_) TGO_HU(_)
#define     TGO_BWU(_)            TGO_BU(_) TGO_HU(_) TGO_WU(_)
#define     TGO_BDU(_)            TGO_BU(_) TGO_HU(_) TGO_WU(_) TGO_DU(_)
#define     TGO_HWU(_)                      TGO_HU(_) TGO_WU(_)
#define     TGO_HDU(_)                      TGO_HU(_) TGO_WU(_) TGO_DU(_)
#define     TGO_WDU(_)                                TGO_WU(_) TGO_DU(_)

#define     TGO_YBI(_)  TGO_YI(_) TGO_BI(_)
#define     TGO_YHI(_)  TGO_YI(_) TGO_BI(_) TGO_HI(_)
#define     TGO_YWI(_)  TGO_YI(_) TGO_BI(_) TGO_HI(_) TGO_WI(_)
#define     TGO_YDI(_)  TGO_YI(_) TGO_BI(_) TGO_HI(_) TGO_WI(_) TGO_DI(_)
#define     TGO_BHI(_)            TGO_BI(_) TGO_HI(_)
#define     TGO_BWI(_)            TGO_BI(_) TGO_HI(_) TGO_WI(_)
#define     TGO_BDI(_)            TGO_BI(_) TGO_HI(_) TGO_WI(_) TGO_DI(_)
#define     TGO_HWI(_)                      TGO_HI(_) TGO_WI(_)
#define     TGO_HDI(_)                      TGO_HI(_) TGO_WI(_) TGO_DI(_)
#define     TGO_WDI(_)                                TGO_WI(_) TGO_DI(_)

#define     TGO_YBF(_)  TGO_YF(_) TGO_BF(_)
#define     TGO_YHF(_)  TGO_YF(_) TGO_BF(_) TGO_HF(_)
#define     TGO_YWF(_)  TGO_YF(_) TGO_BF(_) TGO_HF(_) TGO_WF(_)
#define     TGO_YDF(_)  TGO_YF(_) TGO_BF(_) TGO_HF(_) TGO_WF(_) TGO_DF(_)
#define     TGO_BHF(_)            TGO_BF(_) TGO_HF(_)
#define     TGO_BWF(_)            TGO_BF(_) TGO_HF(_) TGO_WF(_)
#define     TGO_BDF(_)            TGO_BF(_) TGO_HF(_) TGO_WF(_) TGO_DF(_)
#define     TGO_HWF(_)                      TGO_HF(_) TGO_WF(_)
#define     TGO_HDF(_)                      TGO_HF(_) TGO_WF(_) TGO_DF(_)
#define     TGO_WDF(_)                                TGO_WF(_) TGO_DF(_)

#define     TGO_YBZ(_)  TGO_YZ(_) TGO_BZ(_)
#define     TGO_YHZ(_)  TGO_YZ(_) TGO_BZ(_) TGO_HZ(_)
#define     TGO_YWZ(_)  TGO_YZ(_) TGO_BZ(_) TGO_HZ(_) TGO_WZ(_)
#define     TGO_YDZ(_)  TGO_YZ(_) TGO_BZ(_) TGO_HZ(_) TGO_WZ(_) TGO_DZ(_)
#define     TGO_BHZ(_)            TGO_BZ(_) TGO_HZ(_)
#define     TGO_BWZ(_)            TGO_BZ(_) TGO_HZ(_) TGO_WZ(_)
#define     TGO_BDZ(_)            TGO_BZ(_) TGO_HZ(_) TGO_WZ(_) TGO_DZ(_)
#define     TGO_HWZ(_)                      TGO_HZ(_) TGO_WZ(_)
#define     TGO_HDZ(_)                      TGO_HZ(_) TGO_WZ(_) TGO_DZ(_)
#define     TGO_WDZ(_)                                TGO_WZ(_) TGO_DZ(_)

#define     TGO_YBN(_)  TGO_YN(_) TGO_BN(_)
#define     TGO_YHN(_)  TGO_YN(_) TGO_BN(_) TGO_HN(_)
#define     TGO_YWN(_)  TGO_YN(_) TGO_BN(_) TGO_HN(_) TGO_WN(_)
#define     TGO_YDN(_)  TGO_YN(_) TGO_BN(_) TGO_HN(_) TGO_WN(_) TGO_DN(_)
#define     TGO_BHN(_)            TGO_BN(_) TGO_HN(_)
#define     TGO_BWN(_)            TGO_BN(_) TGO_HN(_) TGO_WN(_)
#define     TGO_BDN(_)            TGO_BN(_) TGO_HN(_) TGO_WN(_) TGO_DN(_)
#define     TGO_HWN(_)                      TGO_HN(_) TGO_WN(_)
#define     TGO_HDN(_)                      TGO_HN(_) TGO_WN(_) TGO_DN(_)
#define     TGO_WDN(_)                                TGO_WN(_) TGO_DN(_)

#define     TGO_YBS(_)  TGO_YS(_) TGO_BS(_)
#define     TGO_YHS(_)  TGO_YS(_) TGO_BS(_) TGO_HS(_)
#define     TGO_YWS(_)  TGO_YS(_) TGO_BS(_) TGO_HS(_) TGO_WS(_)
#define     TGO_YDS(_)  TGO_YS(_) TGO_BS(_) TGO_HS(_) TGO_WS(_) TGO_DS(_)
#define     TGO_BHS(_)            TGO_BS(_) TGO_HS(_)
#define     TGO_BWS(_)            TGO_BS(_) TGO_HS(_) TGO_WS(_)
#define     TGO_BDS(_)            TGO_BS(_) TGO_HS(_) TGO_WS(_) TGO_DS(_)
#define     TGO_HWS(_)                      TGO_HS(_) TGO_WS(_)
#define     TGO_HDS(_)                      TGO_HS(_) TGO_WS(_) TGO_DS(_)
#define     TGO_WDS(_)                                TGO_WS(_) TGO_DS(_)

#define     TGO_YBR(_)  TGO_YR(_) TGO_BR(_)
#define     TGO_YHR(_)  TGO_YR(_) TGO_BR(_) TGO_HR(_)
#define     TGO_YWR(_)  TGO_YR(_) TGO_BR(_) TGO_HR(_) TGO_WR(_)
#define     TGO_YDR(_)  TGO_YR(_) TGO_BR(_) TGO_HR(_) TGO_WR(_) TGO_DR(_)
#define     TGO_BHR(_)            TGO_BR(_) TGO_HR(_)
#define     TGO_BWR(_)            TGO_BR(_) TGO_HR(_) TGO_WR(_)
#define     TGO_BDR(_)            TGO_BR(_) TGO_HR(_) TGO_WR(_) TGO_DR(_)
#define     TGO_HWR(_)                      TGO_HR(_) TGO_WR(_)
#define     TGO_HDR(_)                      TGO_HR(_) TGO_WR(_) TGO_DR(_)
#define     TGO_WDR(_)                                TGO_WR(_) TGO_DR(_)

#if _LEAVE_EXTGOP_TGO
}
#endif

#if _ENTER_EXTGOP_TGS
{
#endif

#ifndef     TGS_NONE
#define     TGS_NONE(_)
#endif

#if MY_EXTVEC_H
#   define  TGS_YU(_)   VSYU_TYPE:VSYU_SN(_),
#   define  TGS_YI(_)
#   define  TGS_YF(_)
#   define  TGS_BU(_)   VSBU_TYPE:VSBU_SN(_),
#   define  TGS_BI(_)   VSBI_TYPE:VSBI_SN(_),
#   define  TGS_BF(_)
#   define  TGS_HU(_)   VSHU_TYPE:VSHU_SN(_),
#   define  TGS_HI(_)   VSHI_TYPE:VSHI_SN(_),
#   define  TGS_HF(_)   VSHF_TYPE:VSHF_SN(_),
#   define  TGS_WU(_)   VSWU_TYPE:VSWU_SN(_),
#   define  TGS_WI(_)   VSWI_TYPE:VSWI_SN(_),
#   define  TGS_WF(_)   VSWF_TYPE:VSWF_SN(_),
#   define  TGS_DU(_)   VSDU_TYPE:VSDU_SN(_),
#   define  TGS_DI(_)   VSDI_TYPE:VSDI_SN(_),
#   define  TGS_DF(_)   VSDF_TYPE:VSDF_SN(_),
#else
#   define  TGS_YU(_) //VSYU_TYPE:VSYU_SN(_),
#   define  TGS_YI(_)
#   define  TGS_YF(_)
#   define  TGS_BU(_) //VSBU_TYPE:VSBU_SN(_),
#   define  TGS_BI(_) //VSBI_TYPE:VSBI_SN(_),
#   define  TGS_BF(_)
#   define  TGS_HU(_) //VSHU_TYPE:VSHU_SN(_),
#   define  TGS_HI(_) //VSHI_TYPE:VSHI_SN(_),
#   define  TGS_HF(_) //VSHF_TYPE:VSHF_SN(_),
#   define  TGS_WU(_) //VSWU_TYPE:VSWU_SN(_),
#   define  TGS_WI(_) //VSWI_TYPE:VSWI_SN(_),
#   define  TGS_WF(_) //VSWF_TYPE:VSWF_SN(_),
#   define  TGS_DU(_) //VSDU_TYPE:VSDU_SN(_),
#   define  TGS_DI(_) //VSDI_TYPE:VSDI_SN(_),
#   define  TGS_DF(_) //VSDF_TYPE:VSDF_SN(_),
#endif // #if MY_EXTVEC_H

#define     TGS_YZ(_)   TGS_YU(_) TGS_YI(_)
#define     TGS_BZ(_)   TGS_BU(_) TGS_BI(_)
#define     TGS_HZ(_)   TGS_HU(_) TGS_HI(_)
#define     TGS_WZ(_)   TGS_WU(_) TGS_WI(_)
#define     TGS_DZ(_)   TGS_DU(_) TGS_DI(_)

#define     TGS_YN(_)   TGS_YU(_)           TGS_YF(_)
#define     TGS_BN(_)   TGS_BU(_)           TGS_BF(_)
#define     TGS_HN(_)   TGS_HU(_)           TGS_HF(_)
#define     TGS_WN(_)   TGS_WU(_)           TGS_WF(_)
#define     TGS_DN(_)   TGS_DU(_)           TGS_DF(_)

#define     TGS_YS(_)             TGS_YI(_) TGS_YF(_)
#define     TGS_BS(_)             TGS_BI(_) TGS_BF(_)
#define     TGS_HS(_)             TGS_HI(_) TGS_HF(_)
#define     TGS_WS(_)             TGS_WI(_) TGS_WF(_)
#define     TGS_DS(_)             TGS_DI(_) TGS_DF(_)

#define     TGS_YR(_)   TGS_YU(_) TGS_YI(_) TGS_YF(_)
#define     TGS_BR(_)   TGS_BU(_) TGS_BI(_) TGS_BF(_)
#define     TGS_HR(_)   TGS_HU(_) TGS_HI(_) TGS_HF(_)
#define     TGS_WR(_)   TGS_WU(_) TGS_WI(_) TGS_WF(_)
#define     TGS_DR(_)   TGS_DU(_) TGS_DI(_) TGS_DF(_)

#define     TGS_YBU(_)  TGS_YU(_) TGS_BU(_)
#define     TGS_YHU(_)  TGS_YU(_) TGS_BU(_) TGS_HU(_)
#define     TGS_YWU(_)  TGS_YU(_) TGS_BU(_) TGS_HU(_) TGS_WU(_)
#define     TGS_YDU(_)  TGS_YU(_) TGS_BU(_) TGS_HU(_) TGS_WU(_) TGS_DU(_)
#define     TGS_BHU(_)            TGS_BU(_) TGS_HU(_)
#define     TGS_BWU(_)            TGS_BU(_) TGS_HU(_) TGS_WU(_)
#define     TGS_BDU(_)            TGS_BU(_) TGS_HU(_) TGS_WU(_) TGS_DU(_)
#define     TGS_HWU(_)                      TGS_HU(_) TGS_WU(_)
#define     TGS_HDU(_)                      TGS_HU(_) TGS_WU(_) TGS_DU(_)
#define     TGS_WDU(_)                                TGS_WU(_) TGS_DU(_)

#define     TGS_YBI(_)  TGS_YI(_) TGS_BI(_)
#define     TGS_YHI(_)  TGS_YI(_) TGS_BI(_) TGS_HI(_)
#define     TGS_YWI(_)  TGS_YI(_) TGS_BI(_) TGS_HI(_) TGS_WI(_)
#define     TGS_YDI(_)  TGS_YI(_) TGS_BI(_) TGS_HI(_) TGS_WI(_) TGS_DI(_)
#define     TGS_BHI(_)            TGS_BI(_) TGS_HI(_)
#define     TGS_BWI(_)            TGS_BI(_) TGS_HI(_) TGS_WI(_)
#define     TGS_BDI(_)            TGS_BI(_) TGS_HI(_) TGS_WI(_) TGS_DI(_)
#define     TGS_HWI(_)                      TGS_HI(_) TGS_WI(_)
#define     TGS_HDI(_)                      TGS_HI(_) TGS_WI(_) TGS_DI(_)
#define     TGS_WDI(_)                                TGS_WI(_) TGS_DI(_)

#define     TGS_YBF(_)  TGS_YF(_) TGS_BF(_)
#define     TGS_YHF(_)  TGS_YF(_) TGS_BF(_) TGS_HF(_)
#define     TGS_YWF(_)  TGS_YF(_) TGS_BF(_) TGS_HF(_) TGS_WF(_)
#define     TGS_YDF(_)  TGS_YF(_) TGS_BF(_) TGS_HF(_) TGS_WF(_) TGS_DF(_)
#define     TGS_BHF(_)            TGS_BF(_) TGS_HF(_)
#define     TGS_BWF(_)            TGS_BF(_) TGS_HF(_) TGS_WF(_)
#define     TGS_BDF(_)            TGS_BF(_) TGS_HF(_) TGS_WF(_) TGS_DF(_)
#define     TGS_HWF(_)                      TGS_HF(_) TGS_WF(_)
#define     TGS_HDF(_)                      TGS_HF(_) TGS_WF(_) TGS_DF(_)
#define     TGS_WDF(_)                                TGS_WF(_) TGS_DF(_)

#define     TGS_YBZ(_)  TGS_YZ(_) TGS_BZ(_)
#define     TGS_YHZ(_)  TGS_YZ(_) TGS_BZ(_) TGS_HZ(_)
#define     TGS_YWZ(_)  TGS_YZ(_) TGS_BZ(_) TGS_HZ(_) TGS_WZ(_)
#define     TGS_YDZ(_)  TGS_YZ(_) TGS_BZ(_) TGS_HZ(_) TGS_WZ(_) TGS_DZ(_)
#define     TGS_BHZ(_)            TGS_BZ(_) TGS_HZ(_)
#define     TGS_BWZ(_)            TGS_BZ(_) TGS_HZ(_) TGS_WZ(_)
#define     TGS_BDZ(_)            TGS_BZ(_) TGS_HZ(_) TGS_WZ(_) TGS_DZ(_)
#define     TGS_HWZ(_)                      TGS_HZ(_) TGS_WZ(_)
#define     TGS_HDZ(_)                      TGS_HZ(_) TGS_WZ(_) TGS_DZ(_)
#define     TGS_WDZ(_)                                TGS_WZ(_) TGS_DZ(_)

#define     TGS_YBN(_)  TGS_YN(_) TGS_BN(_)
#define     TGS_YHN(_)  TGS_YN(_) TGS_BN(_) TGS_HN(_)
#define     TGS_YWN(_)  TGS_YN(_) TGS_BN(_) TGS_HN(_) TGS_WN(_)
#define     TGS_YDN(_)  TGS_YN(_) TGS_BN(_) TGS_HN(_) TGS_WN(_) TGS_DN(_)
#define     TGS_BHN(_)            TGS_BN(_) TGS_HN(_)
#define     TGS_BWN(_)            TGS_BN(_) TGS_HN(_) TGS_WN(_)
#define     TGS_BDN(_)            TGS_BN(_) TGS_HN(_) TGS_WN(_) TGS_DN(_)
#define     TGS_HWN(_)                      TGS_HN(_) TGS_WN(_)
#define     TGS_HDN(_)                      TGS_HN(_) TGS_WN(_) TGS_DN(_)
#define     TGS_WDN(_)                                TGS_WN(_) TGS_DN(_)

#define     TGS_YBS(_)  TGS_YS(_) TGS_BS(_)
#define     TGS_YHS(_)  TGS_YS(_) TGS_BS(_) TGS_HS(_)
#define     TGS_YWS(_)  TGS_YS(_) TGS_BS(_) TGS_HS(_) TGS_WS(_)
#define     TGS_YDS(_)  TGS_YS(_) TGS_BS(_) TGS_HS(_) TGS_WS(_) TGS_DS(_)
#define     TGS_BHS(_)            TGS_BS(_) TGS_HS(_)
#define     TGS_BWS(_)            TGS_BS(_) TGS_HS(_) TGS_WS(_)
#define     TGS_BDS(_)            TGS_BS(_) TGS_HS(_) TGS_WS(_) TGS_DS(_)
#define     TGS_HWS(_)                      TGS_HS(_) TGS_WS(_)
#define     TGS_HDS(_)                      TGS_HS(_) TGS_WS(_) TGS_DS(_)
#define     TGS_WDS(_)                                TGS_WS(_) TGS_DS(_)

#define     TGS_YBR(_)  TGS_YR(_) TGS_BR(_)
#define     TGS_YHR(_)  TGS_YR(_) TGS_BR(_) TGS_HR(_)
#define     TGS_YWR(_)  TGS_YR(_) TGS_BR(_) TGS_HR(_) TGS_WR(_)
#define     TGS_YDR(_)  TGS_YR(_) TGS_BR(_) TGS_HR(_) TGS_WR(_) TGS_DR(_)
#define     TGS_BHR(_)            TGS_BR(_) TGS_HR(_)
#define     TGS_BWR(_)            TGS_BR(_) TGS_HR(_) TGS_WR(_)
#define     TGS_BDR(_)            TGS_BR(_) TGS_HR(_) TGS_WR(_) TGS_DR(_)
#define     TGS_HWR(_)                      TGS_HR(_) TGS_WR(_)
#define     TGS_HDR(_)                      TGS_HR(_) TGS_WR(_) TGS_DR(_)
#define     TGS_WDR(_)                                TGS_WR(_) TGS_DR(_)

#if _LEAVE_EXTGOP_TGS
}
#endif

#define FUNCOF(F, X, K, W, D, Q, O, S, ...) \
_Generic(       \
    (X),        \
    TGK_##K(F)  \
    TGW_##W(F)  \
    TGD_##D(F)  \
    TGQ_##Q(F)  \
    TGO_##O(F)  \
    TGS_##S(F)  \
    __VA_ARGS__ \
)

#endif // EOF("extgop.h")

#if _LEAVE_EXTGOP
}
#endif

#include <stdio.h>

#define    CHAR_ASTG(K)     (   (CHAR_STG(TYPE)){.C=(K)})
#define   UCHAR_ASTG(K)     (  (UCHAR_STG(TYPE)){.U=(K)})
#define   SCHAR_ASTG(K)     (  (SCHAR_STG(TYPE)){.I=(K)})
#define   USHRT_ASTG(K)     (  (USHRT_STG(TYPE)){.U=(K)})
#define    SHRT_ASTG(K)     (   (SHRT_STG(TYPE)){.I=(K)})
#define   FLT16_ASTG(K)     (  (FLT16_STG(TYPE)){.F=(K)})
#define    UINT_ASTG(K)     (   (UINT_STG(TYPE)){.U=(K)})
#define     INT_ASTG(K)     (    (INT_STG(TYPE)){.I=(K)})
#define     FLT_ASTG(K)     (    (FLT_STG(TYPE)){.F=(K)})
#define   ULONG_ASTG(K)     (  (ULONG_STG(TYPE)){.U=(K)})
#define    LONG_ASTG(K)     (   (LONG_STG(TYPE)){.I=(K)})
#define  ULLONG_ASTG(K)     ( (ULLONG_STG(TYPE)){.U=(K)})
#define   LLONG_ASTG(K)     (  (LLONG_STG(TYPE)){.I=(K)})
#define     DBL_ASTG(K)     (    (DBL_STG(TYPE)){.F=(K)})
#define    SIZE_ASTG(K)     (   (SIZE_STG(TYPE)){.U=(K)})
#define  INTPTR_ASTG(K)     ( (INTPTR_STG(TYPE)){.I=(K)})
#define UINTPTR_ASTG(K)     ((UINTPTR_STG(TYPE)){.U=(K)})
#define PTRDIFF_ASTG(K)     ((PTRDIFF_STG(TYPE)){.I=(K)})

INLINE(char,UCHAR_ASBC) (unsigned char u)
{
#define     UCHAR_ASBC(U)   ((char)(U))
    return  UCHAR_ASBC(u);
}

INLINE(char,SCHAR_ASBC) (signed char i)
{
#define     SCHAR_ASBC(I)   ((char)(I))
    return  SCHAR_ASBC(i);
}

INLINE(uint8_t,CHAR_ASBU) (char s)
{
#define     CHAR_ASBU(S)    CHAR_ASTG(S).U
#define     CHAR_ASTU       CHAR_ASBU
    return  CHAR_ASBU(s);
}

INLINE(uint8_t,SCHAR_ASBU) (signed char s)
{
#define     SCHAR_ASBU(S)   SCHAR_ASTG(S).U
#define     SCHAR_ASTU      SCHAR_ASBU
    return  SCHAR_ASBU(s);
}

INLINE(uint16_t,SHRT_ASHU) (short s)
{
#define     SHRT_ASHU(S)    SHRT_ASTG(S).U
#define     SHRT_ASTU       SHRT_ASHU
    return  SHRT_ASHU(s);
}

INLINE(uint32_t,INT_ASWU) (int s)
{
#define     INT_ASWU(S)     INT_ASTG(S).U
#define     INT_ASTU        INT_ASWU
    return  INT_ASWU(s);
}

#if DWRD_NLONG == 2

INLINE(uint32_t,LONG_ASWU) (long s)
{
#   define  LONG_ASWU(S)    LONG_ASTG(S).U
#   define  LONG_ASTU       LONG_ASWU
    return  LONG_ASWU(s);
}

INLINE(uint64_t,LLONG_ASDU) (long long s)
{
#   define  LLONG_ASDU(S)   LLONG_ASTG(S).U
#   define  LLONG_ASTU      LLONG_ASDU
    return  LLONG_ASDU(s);
}

#elif QUAD_NLLONG == 2

INLINE(uint64_t,LONG_ASDU) (long s)
{
#   define  LONG_ASDU(S)    LONG_ASTG(S).U
#   define  LONG_ASTU       LONG_ASDU
    return  LONG_ASDU(s);
}

INLINE(uint64_t,LLONG_ASDU) (long long s)
{
#   define  LLONG_ASDU(S)   LLONG_ASTG(S).U
#   define  LLONG_ASTU      LLONG_ASDU
    return  LLONG_ASDU(s);
}

#else

INLINE(uint64_t,LONG_ASDU) (long s)
{
#   define  LONG_ASDU(S)    LONG_ASTG(S).U
#   define  LONG_ASTU       LONG_ASDU
    return  LONG_ASDU(s);
}

INLINE(ullong,LLONG_ASQU) (long long s)
{
#   define  LLONG_ASQU(S)   LLONG_ASTG(S).U
#   define  LLONG_ASTU      LLONG_ASQU
    return  LLONG_ASQU(s);
}

#endif

INLINE(uint16_t,FLT16_ASHU) (flt16_t s)
{
#define     FLT16_ASHU(S)   FLT16_ASTG(S).U
#define     FLT16_ASTU      FLT16_ASHU
    return  FLT16_ASHU(s);
}

INLINE(uint32_t,FLT_ASWU) (float s)
{
#define     FLT_ASWU(S)     FLT_ASTG(S).U
#define     FLT_ASTU        FLT_ASWU
    return  FLT_ASWU(s);
}

INLINE(uint64_t,DBL_ASDU) (double s)
{
#define     DBL_ASDU(S)     DBL_ASTG(S).U
#define     DBL_ASTU        DBL_ASDU
    return  DBL_ASDU(s);
}


#define  INTPTR_ASTU    INTPTR_BASE(ASTU)
#define PTRDIFF_ASTU    PTRDIFF_BASE(ASTU)


INLINE(int8_t, UCHAR_ASBI) (unsigned char n)
{
#define     UCHAR_ASBI(N)   UCHAR_ASTG(N).I
#define     UCHAR_ASTI      UCHAR_ASBI
    return  UCHAR_ASBI(n);
}

INLINE(int8_t,  CHAR_ASBI) (char n)
{
#define     CHAR_ASBI(N)    CHAR_ASTG(N).I
#define     CHAR_ASTI       CHAR_ASBI
    return  CHAR_ASBI(n);
}

INLINE(int16_t,USHRT_ASHI) (unsigned short n)
{
#define     USHRT_ASHI(N)   USHRT_ASTG(N).I
#define     USHRT_ASTI      USHRT_ASHI  
    return  USHRT_ASHI(n);
}

INLINE(int32_t, UINT_ASWI) (unsigned int n)
{
#define     UINT_ASWI(N)    UINT_ASTG(N).I
#define     UINT_ASTI       UINT_ASWI
    return  UINT_ASWI(n);
}

#if DWRD_NLONG == 2

INLINE(int32_t,ULONG_ASWI) (unsigned long n)
{
#   define  ULONG_ASWI(N)   ULONG_ASTG(N).I
#   define  ULONG_ASTI      ULONG_ASWI
    return  ULONG_ASWI(n);
}

INLINE(int64_t,ULLONG_ASDI) (unsigned long long n)
{
#   define  ULLONG_ASDI(N)  ULLONG_ASTG(N).I
#   define  ULLONG_ASTI     ULLONG_ASDI
    return  ULLONG_ASDI(n);
}

#elif QUAD_NLLONG == 2

INLINE(int64_t,ULONG_ASDI) (unsigned long n)
{
#   define  ULONG_ASDI(N)   ULONG_ASTG(N).I
#   define  ULONG_ASTI      ULONG_ASDI
    return  ULONG_ASDI(n);
}

INLINE(int64_t,ULLONG_ASDI) (unsigned long long n)
{
#   define  ULLONG_ASDI(N)  ULLONG_ASTG(N).I
#   define  ULLONG_ASTI     ULLONG_ASDI
    return  ULLONG_ASDI(n);
}

#else

INLINE(int64_t,ULONG_ASDI) (unsigned long n)
{
#   define  ULONG_ASDI(N)   ULONG_ASTG(N).I
#   define  ULONG_ASTI      ULONG_ASDI
    return  ULONG_ASTI(n);
}

INLINE(llong,ULLONG_ASQI) (unsigned long long n)
{
#   define  LLONG_ASQI(N)   ULLONG_ASTG(N).I
#   define  LLONG_ASTI(N)   ULLONG_ASQI
    return  LLONG_ASQI(n);
}

#endif

INLINE(int16_t,FLT16_ASHI) (flt16_t n)
{
#define     FLT16_ASHI(N)   FLT16_ASTG(N).I
#define     FLT16_ASTI      FLT16_ASHI
    return  FLT16_ASTI(n);
}

INLINE(int32_t,FLT_ASWI) (float n)
{
#define     FLT_ASWI(N)     FLT_ASTG(N).I
#define     FLT_ASTI        FLT_ASWI
    return  FLT_ASWI(n);
}

INLINE(int64_t,DBL_ASDI) (double n)
{
#define     DBL_ASDI(N)     DBL_ASTG(N).I
#define     DBL_ASTI        DBL_ASDI
    return  DBL_ASDI(n);
}

#define    SIZE_ASTI    SIZE_BASE(ASTI)
#define UINTPTR_ASTI    UINTPTR_BASE(ASTI)


INLINE(flt16_t,USHRT_ASHF) (unsigned short z)
{
#define     USHRT_ASHF(Z)   USHRT_ASTG(Z).F
#define     USHRT_ASTF      USHRT_ASHF
    return  USHRT_ASHF(z);
}

INLINE(flt16_t,SHRT_ASHF) (short z)
{
#define     SHRT_ASHF(Z)    SHRT_ASTG(Z).F
#define     SHRT_ASTF       SHRT_ASHF
    return  SHRT_ASHF(z);
}

INLINE(float,UINT_ASWF) (unsigned int z)
{
#define     UINT_ASWF(Z)    UINT_ASTG(Z).F
#define     UINT_ASTF       UINT_ASWF
    return  UINT_ASWF(z);
}

INLINE(float,INT_ASWF) (int z)
{
#define     INT_ASWF(Z)    INT_ASTG(Z).F
#define     INT_ASTF       INT_ASWF
    return  INT_ASWF(z);
}

#if DWRD_NLONG == 2

INLINE(float,ULONG_ASWF) (unsigned long z)
{
#define     ULONG_ASWF(Z)   ULONG_ASTG(Z).F
#define     ULONG_ASTF      ULONG_ASWF
    return  ULONG_ASWF(z);
}

INLINE(float,LONG_ASWF) (long z)
{
#define     LONG_ASWF(Z)   LONG_ASTG(Z).F
#define     LONG_ASTF      LONG_ASWF
    return  LONG_ASWF(z);
}

#elif QUAD_NLLONG == 2

INLINE(double,ULONG_ASDF) (unsigned long z)
{
#define     ULONG_ASDF(Z)   ULONG_ASTG(Z).F
#define     ULONG_ASTF      ULONG_ASDF
    return  ULONG_ASDF(z);
}

INLINE(double,LONG_ASDF) (long z)
{
#define     LONG_ASDF(Z)    LONG_ASTG(Z).F
#define     LONG_ASTF       LONG_ASDF
    return  LONG_ASDF(z);
}

INLINE(double,ULLONG_ASDF) (unsigned long long z)
{
#define     ULLONG_ASDF(Z)  ULLONG_ASTG(Z).F
#define     ULLONG_ASTF     ULLONG_ASDF
    return  ULLONG_ASDF(z);
}

INLINE(double,LLONG_ASDF) (long long z)
{
#define     LLONG_ASDF(Z)   LLONG_ASTG(Z).F
#define     LLONG_ASTF      LLONG_ASDF
    return  LLONG_ASTF(z);
}

#else

INLINE(double,ULONG_ASDF) (unsigned long z)
{
#define     ULONG_ASDF(Z)   ULONG_ASTG(Z).F
#define     ULONG_ASTF      ULONG_ASDF
    return  ULONG_ASDF(z);
}

INLINE(double,LONG_ASDF) (long z)
{
#define     LONG_ASDF(Z)    LONG_ASTG(Z).F
#define     LONG_ASTF       LONG_ASDF
    return  LONG_ASDF(z);
}

INLINE(long double,ULLONG_ASQF) (unsigned long long z)
{
#define     ULLONG_ASQF(Z)  ULLONG_ASTG(Z).F
#define     ULLONG_ASTF     ULLONG_ASQF
    return  ULLONG_ASQF(z);
}

INLINE(long double,LLONG_ASQF) (long long z)
{
#define     LLONG_ASQF(Z)   LLONG_ASTG(Z).F
#define     LLONG_ASTF      LLONG_ASQF
    return  LLONG_ASQF(z);
}

#endif

#define    SIZE_ASTF    SIZE_BASE(ASTF)
#define  INTPTR_ASTF    INTPTR_BASE(ASTF)
#define UINTPTR_ASTF    UINTPTR_BASE(ASTF)
#define PTRDIFF_ASTF    PTRDIFF_BASE(ASTF)


#define     UINT8_ASTU      UINT8_BASE(ASTU)
#define     UINT8_ASTI      UINT8_BASE(ASTI)
#define     UINT8_ASBU      UINT8_BASE(ASBU)
#define     UINT8_ASBI      UINT8_BASE(ASBI)
#define     UINT8_ASBC      UINT8_BASE(ASBC)

#define     INT8_ASTU       INT8_BASE(ASTU)
#define     INT8_ASTI       INT8_BASE(ASTI)
#define     INT8_ASBU       INT8_BASE(ASBU)
#define     INT8_ASBI       INT8_BASE(ASBI)
#define     INT8_ASBC       INT8_BASE(ASBC)

#define     UINT16_ASTU     UINT16_BASE(ASTU)
#define     UINT16_ASTI     UINT16_BASE(ASTI)
#define     UINT16_ASTF     UINT16_BASE(ASTF)
#define     UINT16_ASHU     UINT16_BASE(ASHU)
#define     UINT16_ASHI     UINT16_BASE(ASHI)
#define     UINT16_ASHF     UINT16_BASE(ASHF)

#define     INT16_ASTU      INT16_BASE(ASTU)
#define     INT16_ASTI      INT16_BASE(ASTI)
#define     INT16_ASTF      INT16_BASE(ASTF)
#define     INT16_ASHU      INT16_BASE(ASHU)
#define     INT16_ASHI      INT16_BASE(ASHI)
#define     INT16_ASHF      INT16_BASE(ASHF)

#define     UINT32_ASTU     UINT32_BASE(ASTU)
#define     UINT32_ASTI     UINT32_BASE(ASTI)
#define     UINT32_ASTF     UINT32_BASE(ASTF)
#define     UINT32_ASWU     UINT32_BASE(ASWU)
#define     UINT32_ASWI     UINT32_BASE(ASWI)
#define     UINT32_ASWF     UINT32_BASE(ASWF)
#define     UINT32_ASTV     UINT32_BASE(ASTV)

#define     INT32_ASTU      INT32_BASE(ASTU)
#define     INT32_ASTI      INT32_BASE(ASTI)
#define     INT32_ASTF      INT32_BASE(ASTF)
#define     INT32_ASWU      INT32_BASE(ASWU)
#define     INT32_ASWI      INT32_BASE(ASWI)
#define     INT32_ASWF      INT32_BASE(ASWF)
#define     INT32_ASTV      INT32_BASE(ASTV)

#define     UINT64_ASTU     UINT64_BASE(ASTU)
#define     UINT64_ASTI     UINT64_BASE(ASTI)
#define     UINT64_ASTF     UINT64_BASE(ASTF)
#define     UINT64_ASDU     UINT64_BASE(ASDU)
#define     UINT64_ASDI     UINT64_BASE(ASDI)
#define     UINT64_ASDF     UINT64_BASE(ASDF)
#define     UINT64_ASTV     UINT64_BASE(ASTV)

#define     INT64_ASTU      INT64_BASE(ASTU)
#define     INT64_ASTI      INT64_BASE(ASTI)
#define     INT64_ASTF      INT64_BASE(ASTF)
#define     INT64_ASDU      INT64_BASE(ASDU)
#define     INT64_ASDI      INT64_BASE(ASDI)
#define     INT64_ASDF      INT64_BASE(ASDF)
#define     INT64_ASTV      INT64_BASE(ASTV)

/*
    VOID: constant representing an uninitialized value
    NEWL: create aggregate from arguments
    CAT1: combine two vectors into one twice the size
    ASTM: reinterpret virtual as machine
    ASTV: reinterpret machine as virtual
    ASTU: reinterpret as identical width unsigned
    ASTI: reinterpret as identical width signed
    ASTF: reinterpret as identical width float
    ASBU: reinterpret as *bu
    ASBI: reinterpret as *bi
    ASHU: reinterpret as *hu
    ASHI: reinterpret as *hi
    ASHF: reinterpret as *hf
    ASWU: reinterpret as *wu
    ASWI: reinterpret as *wi
    ASWF: reinterpret as *wf
    ASDU: reinterpret as *du
    ASDI: reinterpret as *di
    ASDF: reinterpret as *df
*/

#if _ENTER_EXTGOP_ARM
{
#endif

#ifdef SPC_ARM_NEON


/*  For some reason, clang generates a more efficient
    instruction sequence for vdup_n_u64 compared to 
    vcreate…?
*/

#define MY_VSET2(V, F, v, k0, k1) \
F(k1, F(k0, v, V##_K0), V##_K1)

#define MY_VSET4(V, F, v, k0, k1, k2, k3) \
F(k3, F(k2, MY_VSET2(V, F, v, k0, k1), V##_K2), V##_K3)

#define MY_VSET8(V, F, v, k0, k1, k2, k3, k4, k5, k6, k7) \
F(k7, F(k6, F(k5, F(k4, MY_VSET4(V, F, v, k0, k1, k2, k3), \
V##_K4), V##_K5), V##_K6), V##_K7)

#if _ENTER_EXTGOP_ARM_VOID
{
#endif

#define     WYU_VOID    (0.0f)
#define     WBU_VOID    (0.0f)
#define     WBI_VOID    (0.0f)
#define     WHU_VOID    (0.0f)
#define     WHI_VOID    (0.0f)
#define     WHF_VOID    (0.0f)
#define     WWU_VOID    (0.0f)
#define     WWI_VOID    (0.0f)
#define     WWF_VOID    (0.0f)

#define     DYU_VOID    vdup_n_u64(0)
#define     DBU_VOID    vdup_n_u8(0)
#define     DBI_VOID    vdup_n_s8(0)
#define     DHU_VOID    vdup_n_u16(0)
#define     DHI_VOID    vdup_n_s16(0)
#define     DHF_VOID    vdup_n_f16(0)
#define     DWU_VOID    vdup_n_u32(0)
#define     DWI_VOID    vdup_n_s32(0)
#define     DWF_VOID    vdup_n_f32(0)
#define     DDU_VOID    vdup_n_u64(0)
#define     DDI_VOID    vdup_n_s64(0)
#define     DDF_VOID    vdup_n_f64(0)

#define     QYU_VOID    vdupq_n_u64(0)
#define     QBU_VOID    vdupq_n_u8(0)
#define     QBI_VOID    vdupq_n_s8(0)
#define     QHU_VOID    vdupq_n_u16(0)
#define     QHI_VOID    vdupq_n_s16(0)
#define     QHF_VOID    vdupq_n_f16(0)
#define     QWU_VOID    vdupq_n_u32(0)
#define     QWI_VOID    vdupq_n_s32(0)
#define     QWF_VOID    vdupq_n_f32(0)
#define     QDU_VOID    vdupq_n_u64(0)
#define     QDI_VOID    vdupq_n_s64(0)
#define     QDF_VOID    vdupq_n_f64(0)

#define     VWYU_VOID   ((VWYU_TYPE){WYU_VOID})
#define     VWBU_VOID   ((VWBU_TYPE){WBU_VOID})
#define     VWBI_VOID   ((VWBI_TYPE){WBI_VOID})
#define     VWBC_VOID   ((VWBC_TYPE){WBI_VOID})
#define     VWHU_VOID   ((VWHU_TYPE){WHU_VOID})
#define     VWHI_VOID   ((VWHI_TYPE){WHI_VOID})
#define     VWHF_VOID   ((VWHF_TYPE){WHF_VOID})
#define     VWWU_VOID   ((VWWU_TYPE){WWU_VOID})
#define     VWWI_VOID   ((VWWI_TYPE){WWI_VOID})
#define     VWWF_VOID   ((VWWF_TYPE){WWF_VOID})

#define     VDYU_VOID   ((VDYU_TYPE){DYU_VOID})
#define     VDBU_VOID   DBU_VOID
#define     VDBI_VOID   DBI_VOID
#define     VDBC_VOID   ((VDBC_TYPE){DBC_VOID})
#define     VDHU_VOID   DHU_VOID
#define     VDHI_VOID   DHI_VOID
#define     VDHF_VOID   DHF_VOID
#define     VDWU_VOID   DWU_VOID
#define     VDWI_VOID   DWI_VOID
#define     VDWF_VOID   DWF_VOID
#define     VDDU_VOID   DWU_VOID
#define     VDDI_VOID   DWI_VOID
#define     VDDF_VOID   DWF_VOID

#define     VQYU_VOID   ((VQYU_TYPE){QYU_VOID})
#define     VQBU_VOID   QBU_VOID
#define     VQBI_VOID   QBI_VOID
#define     VQBC_VOID   ((VQBC_TYPE){QBC_VOID})
#define     VQHU_VOID   QHU_VOID
#define     VQHI_VOID   QHI_VOID
#define     VQHF_VOID   QHF_VOID
#define     VQWU_VOID   QWU_VOID
#define     VQWI_VOID   QWI_VOID
#define     VQWF_VOID   QWF_VOID
#define     VQDU_VOID   QWU_VOID
#define     VQDI_VOID   QWI_VOID
#define     VQDF_VOID   QWF_VOID

#if _LEAVE_EXTGOP_ARM_VOID
}
#endif

#if _ENTER_EXTGOP_ARM_AS__
{
#endif

#if _ENTER_EXTGOP_ARM_ASYU
{
#endif
//efine     DYU_ASYU
#define     DBU_ASYU        vreinterpret_u64_u8
#define     DBI_ASYU        vreinterpret_u64_s8
#define     DHU_ASYU        vreinterpret_u64_u16
#define     DHI_ASYU        vreinterpret_u64_s16
#define     DHF_ASYU        vreinterpret_u64_f16
#define     DWU_ASYU        vreinterpret_u64_u32
#define     DWI_ASYU        vreinterpret_u64_s32
#define     DWF_ASYU        vreinterpret_u64_f32
#define     DDU_ASYU        VDDU_REQS
#define     DDI_ASYU        vreinterpret_u64_s64
#define     DDF_ASYU        vreinterpret_u64_f64


//efine     QYU_ASYU
#define     QBU_ASYU        vreinterpretq_u64_u8
#define     QBI_ASYU        vreinterpretq_u64_s8
#define     QHU_ASYU        vreinterpretq_u64_u16
#define     QHI_ASYU        vreinterpretq_u64_s16
#define     QHF_ASYU        vreinterpretq_u64_f16
#define     QWU_ASYU        vreinterpretq_u64_u32
#define     QWI_ASYU        vreinterpretq_u64_s32
#define     QWF_ASYU        vreinterpretq_u64_f32
#define     QDU_ASYU        VQDU_REQS
#define     QDI_ASYU        vreinterpretq_u64_s64
#define     QDF_ASYU        vreinterpretq_u64_f64


//efine     VWYU_ASYU
#define     VWBU_ASYU(V)    WYU_ASTV(VWBU_ASTM(V))
#define     VWBI_ASYU(V)    WYU_ASTV(VWBI_ASTM(V))
#define     VWBC_ASYU(V)    WYU_ASTV(VWBC_ASTM(V))
#define     VWHU_ASYU(V)    WYU_ASTV(VWHU_ASTM(V))
#define     VWHI_ASYU(V)    WYU_ASTV(VWHI_ASTM(V))
#define     VWHF_ASYU(V)    WYU_ASTV(VWHF_ASTM(V))
#define     VWWU_ASYU(V)    WYU_ASTV(VWWU_ASTM(V))
#define     VWWI_ASYU(V)    WYU_ASTV(VWWI_ASTM(V))
#define     VWWF_ASYU(V)    WYU_ASTV(VWWF_ASTM(V))


//efine     VDYU_ASYU
#define     VDBU_ASYU(V)    DYU_ASTV(DBU_ASYU(VDBU_ASTM(V)))
#define     VDBI_ASYU(V)    DYU_ASTV(DBI_ASYU(VDBI_ASTM(V)))
#define     VDBC_ASYU(V)    DYU_ASTV(DBC_ASYU(VDBC_ASTM(V)))
#define     VDHU_ASYU(V)    DYU_ASTV(DHU_ASYU(VDHU_ASTM(V)))
#define     VDHI_ASYU(V)    DYU_ASTV(DHI_ASYU(VDHI_ASTM(V)))
#define     VDHF_ASYU(V)    DYU_ASTV(DHF_ASYU(VDHF_ASTM(V)))
#define     VDWU_ASYU(V)    DYU_ASTV(DWU_ASYU(VDWU_ASTM(V)))
#define     VDWI_ASYU(V)    DYU_ASTV(DWI_ASYU(VDWI_ASTM(V)))
#define     VDWF_ASYU(V)    DYU_ASTV(DWF_ASYU(VDWF_ASTM(V)))
#define     VDDU_ASYU(V)    DYU_ASTV(DDU_ASYU(VDDU_ASTM(V)))
#define     VDDI_ASYU(V)    DYU_ASTV(DDI_ASYU(VDDI_ASTM(V)))
#define     VDDF_ASYU(V)    DYU_ASTV(DDF_ASYU(VDDF_ASTM(V)))

//efine     VQYU_ASYU
#define     VQBU_ASYU(V)    QYU_ASTV(QBU_ASYU(VQBU_ASTM(V)))
#define     VQBI_ASYU(V)    QYU_ASTV(QBI_ASYU(VQBI_ASTM(V)))
#define     VQBC_ASYU(V)    QYU_ASTV(QBC_ASYU(VQBC_ASTM(V)))
#define     VQHU_ASYU(V)    QYU_ASTV(QHU_ASYU(VQHU_ASTM(V)))
#define     VQHI_ASYU(V)    QYU_ASTV(QHI_ASYU(VQHI_ASTM(V)))
#define     VQHF_ASYU(V)    QYU_ASTV(QHF_ASYU(VQHF_ASTM(V)))
#define     VQWU_ASYU(V)    QYU_ASTV(QWU_ASYU(VQWU_ASTM(V)))
#define     VQWI_ASYU(V)    QYU_ASTV(QWI_ASYU(VQWI_ASTM(V)))
#define     VQWF_ASYU(V)    QYU_ASTV(QWF_ASYU(VQWF_ASTM(V)))
#define     VQDU_ASYU(V)    QYU_ASTV(QDU_ASYU(VQDU_ASTM(V)))
#define     VQDI_ASYU(V)    QYU_ASTV(QDI_ASYU(VQDI_ASTM(V)))
#define     VQDF_ASYU(V)    QYU_ASTV(QDF_ASYU(VQDF_ASTM(V)))

#if _LEAVE_EXTGOP_ARM_ASYU
}
#endif

#if _ENTER_EXTGOP_ARM_ASB_
{
#endif

#if CHAR_MIN
#   define  DBC_ASYU        vreinterpret_u64_s8
#   define  DBC_ASBU        vreinterpret_u8_s8
#   define  DBC_ASBI(V)     (V)
//  define  DBC_ASBC
#   define  DBC_ASHU        vreinterpret_u16_s8
#   define  DBC_ASHI        vreinterpret_s16_s8
#   define  DBC_ASHF        vreinterpret_f16_s8
#   define  DBC_ASWU        vreinterpret_u32_s8
#   define  DBC_ASWI        vreinterpret_s32_s8
#   define  DBC_ASWF        vreinterpret_f32_s8
#   define  DBC_ASDU        vreinterpret_u64_s8
#   define  DBC_ASDI        vreinterpret_s64_s8
#   define  DBC_ASDF        vreinterpret_f64_s8

#   define  QBC_ASYU        vreinterpretq_u64_s8
#   define  QBC_ASBU        vreinterpretq_u8_s8
#   define  QBC_ASBI(V)     (V)
//  define  QBC_ASBC
#   define  QBC_ASHU        vreinterpretq_u16_s8
#   define  QBC_ASHI        vreinterpretq_s16_s8
#   define  QBC_ASHF        vreinterpretq_f16_s8
#   define  QBC_ASWU        vreinterpretq_u32_s8
#   define  QBC_ASWI        vreinterpretq_s32_s8
#   define  QBC_ASWF        vreinterpretq_f32_s8
#   define  QBC_ASDU        vreinterpretq_u64_s8
#   define  QBC_ASDI        vreinterpretq_s64_s8
#   define  QBC_ASDF        vreinterpretq_f64_s8

#else

#   define  DBC_ASYU        vreinterpret_u64_u8
#   define  DBC_ASBU(V)     (V)
#   define  DBC_ASBI        vreinterpret_s8_u8
//  define  DBC_ASBC
#   define  DBC_ASHU        vreinterpret_u16_u8
#   define  DBC_ASHI        vreinterpret_s16_u8
#   define  DBC_ASHF        vreinterpret_f16_u8
#   define  DBC_ASWU        vreinterpret_u32_u8
#   define  DBC_ASWI        vreinterpret_s32_u8
#   define  DBC_ASWF        vreinterpret_f32_u8
#   define  DBC_ASDU        vreinterpret_u64_u8
#   define  DBC_ASDI        vreinterpret_s64_u8
#   define  DBC_ASDF        vreinterpret_f64_u8

#   define  QBC_ASYU        vreinterpretq_u64_u8
#   define  QBC_ASBU(V)     (V)
#   define  QBC_ASBI        vreinterpretq_s8_u8
//  define  QBC_ASBC
#   define  QBC_ASHU        vreinterpretq_u16_u8
#   define  QBC_ASHI        vreinterpretq_s16_u8
#   define  QBC_ASHF        vreinterpretq_f16_u8
#   define  QBC_ASWU        vreinterpretq_u32_u8
#   define  QBC_ASWI        vreinterpretq_s32_u8
#   define  QBC_ASWF        vreinterpretq_f32_u8
#   define  QBC_ASDU        vreinterpretq_u64_u8
#   define  QBC_ASDI        vreinterpretq_s64_u8
#   define  QBC_ASDF        vreinterpretq_f64_u8
#endif

#define     VWBC_ASBU(V)    WBU_ASTV(VWBC_ASTM(V))
#define     VWBC_ASBI(V)    WBI_ASTV(VWBC_ASTM(V))
//efine     VWBC_ASBC
#define     VWBC_ASHU(V)    WHU_ASTV(VWBC_ASTM(V))
#define     VWBC_ASHI(V)    WHI_ASTV(VWBC_ASTM(V))
#define     VWBC_ASHF(V)    WHF_ASTV(VWBC_ASTM(V))
#define     VWBC_ASWU(V)    WWU_ASTV(VWBC_ASTM(V))
#define     VWBC_ASWI(V)    WWI_ASTV(VWBC_ASTM(V))
#define     VWBC_ASWF(V)    WWF_ASTV(VWBC_ASTM(V))

#define     VDBC_ASBU(V)    DBC_ASBU(VDBC_ASTM(V))
#define     VDBC_ASBI(V)    DBC_ASBI(VDBC_ASTM(V))
//efine     VDBC_ASBC
#define     VDBC_ASHU(V)    DBC_ASHU(VDBC_ASTM(V))
#define     VDBC_ASHI(V)    DBC_ASHI(VDBC_ASTM(V))
#define     VDBC_ASHF(V)    DBC_ASHF(VDBC_ASTM(V))
#define     VDBC_ASWU(V)    DBC_ASWU(VDBC_ASTM(V))
#define     VDBC_ASWI(V)    DBC_ASWI(VDBC_ASTM(V))
#define     VDBC_ASWF(V)    DBC_ASWF(VDBC_ASTM(V))
#define     VDBC_ASDU(V)    DBC_ASDU(VDBC_ASTM(V))
#define     VDBC_ASDI(V)    DBC_ASDI(VDBC_ASTM(V))
#define     VDBC_ASDF(V)    DBC_ASDF(VDBC_ASTM(V))

#define     VQBC_ASBU(V)    QBC_ASBU(VQBC_ASTM(V))
#define     VQBC_ASBI(V)    QBC_ASBI(VQBC_ASTM(V))
//efine     VQBC_ASBC
#define     VQBC_ASHU(V)    QBC_ASHU(VQBC_ASTM(V))
#define     VQBC_ASHI(V)    QBC_ASHI(VQBC_ASTM(V))
#define     VQBC_ASHF(V)    QBC_ASHF(VQBC_ASTM(V))
#define     VQBC_ASWU(V)    QBC_ASWU(VQBC_ASTM(V))
#define     VQBC_ASWI(V)    QBC_ASWI(VQBC_ASTM(V))
#define     VQBC_ASWF(V)    QBC_ASWF(VQBC_ASTM(V))
#define     VQBC_ASDU(V)    QBC_ASDU(VQBC_ASTM(V))
#define     VQBC_ASDI(V)    QBC_ASDI(VQBC_ASTM(V))
#define     VQBC_ASDF(V)    QBC_ASDF(VQBC_ASTM(V))

#if _ENTER_EXTGOP_ARM_ASBU
{
#endif

#define     DYU_ASBU        vreinterpret_u8_u64
//efine     DBU_ASBU
#define     DBI_ASBU        vreinterpret_u8_s8
//efine     DBC_ASBU
#define     DHU_ASBU        vreinterpret_u8_u16
#define     DHI_ASBU        vreinterpret_u8_s16
#define     DHF_ASBU        vreinterpret_u8_f16
#define     DWU_ASBU        vreinterpret_u8_u32
#define     DWI_ASBU        vreinterpret_u8_s32
#define     DWF_ASBU        vreinterpret_u8_f32
#define     DDU_ASBU        vreinterpret_u8_u64
#define     DDI_ASBU        vreinterpret_u8_s64
#define     DDF_ASBU        vreinterpret_u8_f64

#define     QYU_ASBU        vreinterpretq_u8_u64
//efine     QBU_ASBU
#define     QBI_ASBU        vreinterpretq_u8_s8
//efine     QBC_ASBU
#define     QHU_ASBU        vreinterpretq_u8_u16
#define     QHU_ASBU        vreinterpretq_u8_u16
#define     QHI_ASBU        vreinterpretq_u8_s16
#define     QHF_ASBU        vreinterpretq_u8_f16
#define     QWU_ASBU        vreinterpretq_u8_u32
#define     QWI_ASBU        vreinterpretq_u8_s32
#define     QWF_ASBU        vreinterpretq_u8_f32
#define     QDU_ASBU        vreinterpretq_u8_u64
#define     QDI_ASBU        vreinterpretq_u8_s64
#define     QDF_ASBU        vreinterpretq_u8_f64


#define     VWYU_ASBU(V)    WBU_ASTV(VWYU_ASTM(V))
//efine     VWBU_ASBU
#define     VWBI_ASBU(V)    WBU_ASTV(VWBI_ASTM(V))
//efine     VWBC_ASBU
#define     VWHU_ASBU(V)    WBU_ASTV(VWHU_ASTM(V))
#define     VWHI_ASBU(V)    WBU_ASTV(VWHI_ASTM(V))
#define     VWHF_ASBU(V)    WBU_ASTV(VWHF_ASTM(V))
#define     VWWU_ASBU(V)    WBU_ASTV(VWWU_ASTM(V))
#define     VWWI_ASBU(V)    WBU_ASTV(VWWI_ASTM(V))
#define     VWWF_ASBU(V)    WBU_ASTV(VWWF_ASTM(V))


#define     VDYU_ASBU(V)    DBU_ASTV(DYU_ASBU(VDYU_ASTM(V)))
//efine     VDBU_ASBU
#define     VDBI_ASBU       DBI_ASBU
//efine     VDBC_ASBU
#define     VDHU_ASBU       DHU_ASBU
#define     VDHI_ASBU       DHI_ASBU
#define     VDHF_ASBU       DHF_ASBU
#define     VDWU_ASBU       DWU_ASBU
#define     VDWI_ASBU       DWI_ASBU
#define     VDWF_ASBU       DWF_ASBU
#define     VDDU_ASBU       DDU_ASBU
#define     VDDI_ASBU       DDI_ASBU
#define     VDDF_ASBU       DDF_ASBU

#define     VQYU_ASBU(V)    QBU_ASTV(QYU_ASBU(VQYU_ASTM(V)))
//efine     VQBU_ASBU
//efine     VQBC_ASBU
#define     VQBI_ASBU       QBI_ASBU
#define     VQHU_ASBU       QHU_ASBU
#define     VQHI_ASBU       QHI_ASBU
#define     VQHF_ASBU       QHF_ASBU
#define     VQWU_ASBU       QWU_ASBU
#define     VQWI_ASBU       QWI_ASBU
#define     VQWF_ASBU       QWF_ASBU
#define     VQDU_ASBU       QDU_ASBU
#define     VQDI_ASBU       QDI_ASBU
#define     VQDF_ASBU       QDF_ASBU

#if _LEAVE_EXTGOP_ARM_ASBU
}
#endif

#if _ENTER_EXTGOP_ARM_ASBI
{
#endif

#define     DYU_ASBI        vreinterpret_s8_u64
#define     DBU_ASBI        vreinterpret_s8_u8
//efine     DBI_ASBI
//efine     DBC_ASBI
#define     DHU_ASBI        vreinterpret_s8_u16
#define     DHI_ASBI        vreinterpret_s8_s16
#define     DHF_ASBI        vreinterpret_s8_f16
#define     DWU_ASBI        vreinterpret_s8_u32
#define     DWI_ASBI        vreinterpret_s8_s32
#define     DWF_ASBI        vreinterpret_s8_f32
#define     DDU_ASBI        vreinterpret_s8_u64
#define     DDI_ASBI        vreinterpret_s8_s64
#define     DDF_ASBI        vreinterpret_s8_f64


#define     QYU_ASBI        vreinterpretq_s8_u64
#define     QBU_ASBI        vreinterpretq_s8_u8
//efine     QBI_ASBI
//efine     QBC_ASBI
#define     QHU_ASBI        vreinterpretq_s8_u16
#define     QHI_ASBI        vreinterpretq_s8_s16
#define     QHF_ASBI        vreinterpretq_s8_f16
#define     QWU_ASBI        vreinterpretq_s8_u32
#define     QWI_ASBI        vreinterpretq_s8_s32
#define     QWF_ASBI        vreinterpretq_s8_f32
#define     QDU_ASBI        vreinterpretq_s8_u64
#define     QDI_ASBI        vreinterpretq_s8_s64
#define     QDF_ASBI        vreinterpretq_s8_f64


#define     VWYU_ASBI(V)    WBI_ASTV(VWYU_ASTM(V))
#define     VWBU_ASBI(V)    WBI_ASTV(VWBU_ASTM(V))
//efine     VWBI_ASBI
//efine     VWBC_ASBI
#define     VWHU_ASBI(V)    WBI_ASTV(VWHU_ASTM(V))
#define     VWHI_ASBI(V)    WBI_ASTV(VWHI_ASTM(V))
#define     VWHF_ASBI(V)    WBI_ASTV(VWHF_ASTM(V))
#define     VWWU_ASBI(V)    WBI_ASTV(VWWU_ASTM(V))
#define     VWWI_ASBI(V)    WBI_ASTV(VWWI_ASTM(V))
#define     VWWF_ASBI(V)    WBI_ASTV(VWWF_ASTM(V))


#define     VDYU_ASBI(V)    DYU_ASBI(VDYU_ASTM(V))
#define     VDBU_ASBI       DBU_ASBI
//efine     VDBI_ASBI
//efine     VDBC_ASBI
#define     VDHU_ASBI       DHU_ASBI
#define     VDHI_ASBI       DHI_ASBI
#define     VDHF_ASBI       DHF_ASBI
#define     VDWU_ASBI       DWU_ASBI
#define     VDWI_ASBI       DWI_ASBI
#define     VDWF_ASBI       DWF_ASBI
#define     VDDU_ASBI       DDU_ASBI
#define     VDDI_ASBI       DDI_ASBI
#define     VDDF_ASBI       DDF_ASBI


#define     VQYU_ASBI(V)    QBI_ASTV(QYU_ASBI(VQYU_ASTM(V)))
#define     VQBU_ASBI       QBU_ASBI
//efine     VQBI_ASBI
//efine     VQBC_ASBI
#define     VQHU_ASBI       QHU_ASBI
#define     VQHI_ASBI       QHI_ASBI
#define     VQHF_ASBI       QHF_ASBI
#define     VQWU_ASBI       QWU_ASBI
#define     VQWI_ASBI       QWI_ASBI
#define     VQWF_ASBI       QWF_ASBI
#define     VQDU_ASBI       QDU_ASBI
#define     VQDI_ASBI       QDI_ASBI
#define     VQDF_ASBI       QDF_ASBI

#if _LEAVE_EXTGOP_ARM_ASBI
}
#endif

#if _ENTER_EXTGOP_ARM_ASBC
{
#endif

#if CHAR_MIN

#   define  DYU_ASBC        vreinterpret_s8_u64
#   define  DBU_ASBC        vreinterpret_s8_u8
#   define  DBI_ASBC(M)     (M)
//  define  DBC_ASBC
#   define  DHU_ASBC        vreinterpret_s8_u16
#   define  DHI_ASBC        vreinterpret_s8_s16
#   define  DHF_ASBC        vreinterpret_s8_f16
#   define  DWU_ASBC        vreinterpret_s8_u32
#   define  DWI_ASBC        vreinterpret_s8_s32
#   define  DWF_ASBC        vreinterpret_s8_f32
#   define  DDU_ASBC        vreinterpret_s8_u64
#   define  DDI_ASBC        vreinterpret_s8_s64
#   define  DDF_ASBC        vreinterpret_s8_f64

#   define  QYU_ASBC        vreinterpretq_s8_u64
#   define  QBU_ASBC        vreinterpretq_s8_u8
#   define  QBI_ASBC(M)     (M)
//  define  QBC_ASBC
#   define  QHU_ASBC        vreinterpretq_s8_u16
#   define  QHI_ASBC        vreinterpretq_s8_s16
#   define  QHF_ASBC        vreinterpretq_s8_f16
#   define  QWU_ASBC        vreinterpretq_s8_u32
#   define  QWI_ASBC        vreinterpretq_s8_s32
#   define  QWF_ASBC        vreinterpretq_s8_f32
#   define  QDU_ASBC        vreinterpretq_s8_u64
#   define  QDI_ASBC        vreinterpretq_s8_s64
#   define  QDF_ASBC        vreinterpretq_s8_f64

#else

#   define  DYU_ASBC        vreinterpret_u8_u64
#   define  DBU_ASBC(M)     (M)
#   define  DBI_ASBC        vreinterpret_u8_s8
//  define  DBC_ASBC        
#   define  DHU_ASBC        vreinterpret_u8_u16
#   define  DHI_ASBC        vreinterpret_u8_s16
#   define  DHF_ASBC        vreinterpret_u8_f16
#   define  DWU_ASBC        vreinterpret_u8_u32
#   define  DWI_ASBC        vreinterpret_u8_s32
#   define  DWF_ASBC        vreinterpret_u8_f32
#   define  DDU_ASBC        vreinterpret_u8_u64
#   define  DDI_ASBC        vreinterpret_u8_s64
#   define  DDF_ASBC        vreinterpret_u8_f64

#   define  QYU_ASBC        vreinterpretq_u8_u64
#   define  QBU_ASBC(M)     (M)
#   define  QBI_ASBC        vreinterpretq_u8_s8
//  define  QBC_ASBC        
#   define  QHU_ASBC        vreinterpretq_u8_u16
#   define  QHI_ASBC        vreinterpretq_u8_s16
#   define  QHF_ASBC        vreinterpretq_u8_f16
#   define  QWU_ASBC        vreinterpretq_u8_u32
#   define  QWI_ASBC        vreinterpretq_u8_s32
#   define  QWF_ASBC        vreinterpretq_u8_f32
#   define  QDU_ASBC        vreinterpretq_u8_u64
#   define  QDI_ASBC        vreinterpretq_u8_s64
#   define  QDF_ASBC        vreinterpretq_u8_f64

#endif

#define     VWYU_ASBC(V)    WBC_ASTV(VWYU_ASTM(V))
#define     VWBU_ASBC(V)    WBC_ASTV(VWBU_ASTM(V))
#define     VWBI_ASBC(V)    WBC_ASTV(VWBI_ASTM(V))
//efine     VWBC_ASBC
#define     VWHU_ASBC(V)    WBC_ASTV(VWHU_ASTM(V))
#define     VWHI_ASBC(V)    WBC_ASTV(VWHI_ASTM(V))
#define     VWHF_ASBC(V)    WBC_ASTV(VWHF_ASTM(V))
#define     VWWU_ASBC(V)    WBC_ASTV(VWWU_ASTM(V))
#define     VWWI_ASBC(V)    WBC_ASTV(VWWI_ASTM(V))
#define     VWWF_ASBC(V)    WBC_ASTV(VWWF_ASTM(V))

#define     VDYU_ASBC(V)    DBC_ASTV(DYU_ASBC(VDYU_ASTM(V)))
#define     VDBU_ASBC(V)    DBC_ASTV(DBU_ASBC(VDBU_ASTM(V)))
#define     VDBI_ASBC(V)    DBC_ASTV(DBI_ASBC(VDBI_ASTM(V)))
//efine     VDBC_ASBC
#define     VDHU_ASBC(V)    DBC_ASTV(DHU_ASBC(VDHU_ASTM(V)))
#define     VDHI_ASBC(V)    DBC_ASTV(DHI_ASBC(VDHI_ASTM(V)))
#define     VDHF_ASBC(V)    DBC_ASTV(DHF_ASBC(VDHF_ASTM(V)))
#define     VDWU_ASBC(V)    DBC_ASTV(DWU_ASBC(VDWU_ASTM(V)))
#define     VDWI_ASBC(V)    DBC_ASTV(DWI_ASBC(VDWI_ASTM(V)))
#define     VDWF_ASBC(V)    DBC_ASTV(DWF_ASBC(VDWF_ASTM(V)))
#define     VDDU_ASBC(V)    DBC_ASTV(DDU_ASBC(VDDU_ASTM(V)))
#define     VDDI_ASBC(V)    DBC_ASTV(DDI_ASBC(VDDI_ASTM(V)))
#define     VDDF_ASBC(V)    DBC_ASTV(DDF_ASBC(VDDF_ASTM(V)))


#define     VQYU_ASBC(V)    QBC_ASTV(QYU_ASBC(VQYU_ASTM(V)))
#define     VQBU_ASBC(V)    QBC_ASTV(QBU_ASBC(VQBU_ASTM(V)))
#define     VQBI_ASBC(V)    QBC_ASTV(QBI_ASBC(VQBI_ASTM(V)))
//efine     VQBC_ASBC
#define     VQHU_ASBC(V)    QBC_ASTV(QHU_ASBC(VQHU_ASTM(V)))
#define     VQHI_ASBC(V)    QBC_ASTV(QHI_ASBC(VQHI_ASTM(V)))
#define     VQHF_ASBC(V)    QBC_ASTV(QHF_ASBC(VQHF_ASTM(V)))
#define     VQWU_ASBC(V)    QBC_ASTV(QWU_ASBC(VQWU_ASTM(V)))
#define     VQWI_ASBC(V)    QBC_ASTV(QWI_ASBC(VQWI_ASTM(V)))
#define     VQWF_ASBC(V)    QBC_ASTV(QWF_ASBC(VQWF_ASTM(V)))
#define     VQDU_ASBC(V)    QBC_ASTV(QDU_ASBC(VQDU_ASTM(V)))
#define     VQDI_ASBC(V)    QBC_ASTV(QDI_ASBC(VQDI_ASTM(V)))
#define     VQDF_ASBC(V)    QBC_ASTV(QDF_ASBC(VQDF_ASTM(V)))

#if _LEAVE_EXTGOP_ARM_ASBC
}
#endif

#if _LEAVE_EXTGOP_ARM_ASB_
}
#endif

#if _ENTER_EXTGOP_ARM_ASH_
{
#endif

#if _ENTER_EXTGOP_ARM_ASHU
{
#endif

#define     DYU_ASHU        vreinterpret_u16_u64
#define     DBU_ASHU        vreinterpret_u16_u8
#define     DBI_ASHU        vreinterpret_u16_s8
//efine     DBC_ASHU
//efine     DHU_ASHU
#define     DHI_ASHU        vreinterpret_u16_s16
#define     DHF_ASHU        vreinterpret_u16_f16
#define     DWU_ASHU        vreinterpret_u16_u32
#define     DWI_ASHU        vreinterpret_u16_s32
#define     DWF_ASHU        vreinterpret_u16_f32
#define     DDU_ASHU        vreinterpret_u16_u64
#define     DDI_ASHU        vreinterpret_u16_s64
#define     DDF_ASHU        vreinterpret_u16_f64

#define     QYU_ASHU        vreinterpretq_u16_u64
#define     QBU_ASHU        vreinterpretq_u16_u8
#define     QBI_ASHU        vreinterpretq_u16_s8
//efine     QBC_ASHU
//efine     QHU_ASHU
#define     QHI_ASHU        vreinterpretq_u16_s16
#define     QHF_ASHU        vreinterpretq_u16_f16
#define     QWU_ASHU        vreinterpretq_u16_u32
#define     QWI_ASHU        vreinterpretq_u16_s32
#define     QWF_ASHU        vreinterpretq_u16_f32
#define     QDU_ASHU        vreinterpretq_u16_u64
#define     QDI_ASHU        vreinterpretq_u16_s64
#define     QDF_ASHU        vreinterpretq_u16_f64


#define     VWYU_ASHU(V)    WHU_ASTV(VWYU_ASTM(V))
#define     VWBU_ASHU(V)    WHU_ASTV(VWBU_ASTM(V))
#define     VWBI_ASHU(V)    WHU_ASTV(VWBI_ASTM(V))
//efine     VWBC_ASHU
//efine     VWHU_ASHU
#define     VWHI_ASHU(V)    WHU_ASTV(VWHI_ASTM(V))
#define     VWHF_ASHU(V)    WHU_ASTV(VWHF_ASTM(V))
#define     VWWU_ASHU(V)    WHU_ASTV(VWWU_ASTM(V))
#define     VWWI_ASHU(V)    WHU_ASTV(VWWI_ASTM(V))
#define     VWWF_ASHU(V)    WHU_ASTV(VWWF_ASTM(V))


#define     VDYU_ASHU(V)    vreinterpret_u16_u64(VDYU_ASTM(V))
#define     VDBU_ASHU       DBU_ASHU
#define     VDBI_ASHU       DBI_ASHU
//efine     VDBC_ASHU
//efine     VDHU_ASHU
#define     VDHI_ASHU       DHI_ASHU
#define     VDHF_ASHU       DHF_ASHU
#define     VDWU_ASHU       DWU_ASHU
#define     VDWI_ASHU       DWI_ASHU
#define     VDWF_ASHU       DWF_ASHU
#define     VDDU_ASHU       DDU_ASHU
#define     VDDI_ASHU       DDI_ASHU
#define     VDDF_ASHU       DDF_ASHU


#define     VQYU_ASHU(V)    vreinterpretq_u16_u64(VQYU_ASTM(V))
#define     VQBU_ASHU       QBU_ASHU
#define     VQBI_ASHU       QBI_ASHU
//efine     VQBC_ASHU
//efine     VQHU_ASHU
#define     VQHI_ASHU       QHI_ASHU
#define     VQHF_ASHU       QHF_ASHU
#define     VQWU_ASHU       QWU_ASHU
#define     VQWI_ASHU       QWI_ASHU
#define     VQWF_ASHU       QWF_ASHU
#define     VQDU_ASHU       QDU_ASHU
#define     VQDI_ASHU       QDI_ASHU
#define     VQDF_ASHU       QDF_ASHU

#if _LEAVE_EXTGOP_ARM_ASHU
}
#endif

#if _ENTER_EXTGOP_ARM_ASHI
{
#endif

#define     DYU_ASHI        vreinterpret_s16_u64
#define     DBU_ASHI        vreinterpret_s16_u8
#define     DBI_ASHI        vreinterpret_s16_s8
#define     DHU_ASHI        vreinterpret_s16_u16
//efine     DHI_ASHI
#define     DHF_ASHI        vreinterpret_s16_f16
#define     DWU_ASHI        vreinterpret_s16_u32
#define     DWI_ASHI        vreinterpret_s16_s32
#define     DWF_ASHI        vreinterpret_s16_f32
#define     DDU_ASHI        vreinterpret_s16_u64
#define     DDI_ASHI        vreinterpret_s16_s64
#define     DDF_ASHI        vreinterpret_s16_f64


#define     QYU_ASHI        vreinterpretq_s16_u64
#define     QBU_ASHI        vreinterpretq_s16_u8
#define     QBI_ASHI        vreinterpretq_s16_s8
#define     QHU_ASHI        vreinterpretq_s16_u16
//efine     QHI_ASHI
#define     QHF_ASHI        vreinterpretq_s16_f16
#define     QWU_ASHI        vreinterpretq_s16_u32
#define     QWI_ASHI        vreinterpretq_s16_s32
#define     QWF_ASHI        vreinterpretq_s16_f32
#define     QDU_ASHI        vreinterpretq_s16_u64
#define     QDI_ASHI        vreinterpretq_s16_s64
#define     QDF_ASHI        vreinterpretq_s16_f64

#define     VWYU_ASHI(V)    WHI_ASTV(VWYU_ASTM(V))
#define     VWBU_ASHI(V)    WHI_ASTV(VWBU_ASTM(V))
#define     VWBI_ASHI(V)    WHI_ASTV(VWBI_ASTM(V))
#define     VWHU_ASHI(V)    WHI_ASTV(VWHU_ASTM(V))
//efine     VWHI_ASHI
#define     VWHF_ASHI(V)    WHI_ASTV(VWHF_ASTM(V))
#define     VWWU_ASHI(V)    WHI_ASTV(VWWU_ASTM(V))
#define     VWWI_ASHI(V)    WHI_ASTV(VWWI_ASTM(V))
#define     VWWF_ASHI(V)    WHI_ASTV(VWWF_ASTM(V))


#define     VDYU_ASHI(V)    vreinterpret_s16_u64(VDYU_ASTM(V))
#define     VDBU_ASHI       DBU_ASHI
#define     VDBI_ASHI       DBI_ASHI
//efine     VDBC_ASHI
#define     VDHU_ASHI       DHU_ASHI
//efine     VDHI_ASHI
#define     VDHF_ASHI       DHF_ASHI
#define     VDWU_ASHI       DWU_ASHI
#define     VDWI_ASHI       DWI_ASHI
#define     VDWF_ASHI       DWF_ASHI
#define     VDDU_ASHI       DDU_ASHI
#define     VDDI_ASHI       DDI_ASHI
#define     VDDF_ASHI       DDF_ASHI


#define     VQYU_ASHI(V)    vreinterpretq_s16_u64(VQYU_ASTM(V))
#define     VQBU_ASHI       QBU_ASHI
#define     VQBI_ASHI       QBI_ASHI
//efine     VQBC_ASHI
#define     VQHU_ASHI       QHU_ASHI
//efine     VQHI_ASHI
#define     VQHF_ASHI       QHF_ASHI
#define     VQWU_ASHI       QWU_ASHI
#define     VQWI_ASHI       QWI_ASHI
#define     VQWF_ASHI       QWF_ASHI
#define     VQDU_ASHI       QDU_ASHI
#define     VQDI_ASHI       QDI_ASHI
#define     VQDF_ASHI       QDF_ASHI

#if _LEAVE_EXTGOP_ARM_ASHI
}
#endif

#if _ENTER_EXTGOP_ARM_ASHF
{
#endif

#define     DYU_ASHF        vreinterpret_f16_u64
#define     DBU_ASHF        vreinterpret_f16_u8
#define     DBI_ASHF        vreinterpret_f16_s8
#define     DHU_ASHF        vreinterpret_f16_u16
#define     DHI_ASHF        vreinterpret_f16_s16
//efine     DHF_ASHF
#define     DWU_ASHF        vreinterpret_f16_u32
#define     DWI_ASHF        vreinterpret_f16_s32
#define     DWF_ASHF        vreinterpret_f16_f32
#define     DDU_ASHF        vreinterpret_f16_u64
#define     DDI_ASHF        vreinterpret_f16_s64
#define     DDF_ASHF        vreinterpret_f16_f64


#define     QYU_ASHF        vreinterpretq_f16_u64
#define     QBU_ASHF        vreinterpretq_f16_u8
#define     QBI_ASHF        vreinterpretq_f16_s8
#define     QHU_ASHF        vreinterpretq_f16_u16
#define     QHI_ASHF        vreinterpretq_f16_s16
//efine     QHF_ASHF
#define     QWU_ASHF        vreinterpretq_f16_u32
#define     QWI_ASHF        vreinterpretq_f16_s32
#define     QWF_ASHF        vreinterpretq_f16_f32
#define     QDU_ASHF        vreinterpretq_f16_u64
#define     QDI_ASHF        vreinterpretq_f16_s64
#define     QDF_ASHF        vreinterpretq_f16_f64


#define     VWYU_ASHF(V)    WHF_ASTV(VWYU_ASTM(V))
#define     VWBU_ASHF(V)    WHF_ASTV(VWBU_ASTM(V))
#define     VWBI_ASHF(V)    WHF_ASTV(VWBI_ASTM(V))
#define     VWHU_ASHF(V)    WHF_ASTV(VWHU_ASTM(V))
#define     VWHI_ASHF(V)    WHF_ASTV(VWHI_ASTM(V))
//efine     VWHF_ASHF
#define     VWWU_ASHF(V)    WHF_ASTV(VWWU_ASTM(V))
#define     VWWI_ASHF(V)    WHF_ASTV(VWWI_ASTM(V))
#define     VWWF_ASHF(V)    WHF_ASTV(VWWF_ASTM(V))


#define     VDYU_ASHF(V)    vreinterpret_f16_u64(VDYU_ASTM(V))
#define     VDBU_ASHF       DBU_ASHF
#define     VDBI_ASHF       DBI_ASHF
//efine     VDBC_ASHF
#define     VDHU_ASHF       DHU_ASHF
#define     VDHI_ASHF       DHI_ASHF
//efine     VDHF_ASHF
#define     VDWU_ASHF       DWU_ASHF
#define     VDWI_ASHF       DWI_ASHF
#define     VDWF_ASHF       DWF_ASHF
#define     VDDU_ASHF       DDU_ASHF
#define     VDDI_ASHF       DDI_ASHF
#define     VDDF_ASHF       DDF_ASHF


#define     VQYU_ASHF(V)    vreinterpretq_f16_u64(VQYU_ASTM(V))
#define     VQBU_ASHF       QBU_ASHF
#define     VQBI_ASHF       QBI_ASHF
//efine     VQBC_ASHF
#define     VQHU_ASHF       QHU_ASHF
#define     VQHI_ASHF       QHI_ASHF
//efine     VQHF_ASHF
#define     VQWU_ASHF       QWU_ASHF
#define     VQWI_ASHF       QWI_ASHF
#define     VQWF_ASHF       QWF_ASHF
#define     VQDU_ASHF       QDU_ASHF
#define     VQDI_ASHF       QDI_ASHF
#define     VQDF_ASHF       QDF_ASHF

#if _LEAVE_EXTGOP_ARM_ASHF
}
#endif

#if _LEAVE_EXTGOP_ARM_ASH_
}
#endif


#if _ENTER_EXTGOP_ARM_ASW_
{
#endif

#if _ENTER_EXTGOP_ARM_ASWU
{
#endif

#define     DYU_ASWU        vreinterpret_u32_u64
#define     DBU_ASWU        vreinterpret_u32_u8
#define     DBI_ASWU        vreinterpret_u32_s8
//efine     DBC_ASWU
#define     DHU_ASWU        vreinterpret_u32_u16
#define     DHI_ASWU        vreinterpret_u32_s16
#define     DHF_ASWU        vreinterpret_u32_f16
//efine     DWU_ASWU
#define     DWI_ASWU        vreinterpret_u32_s32
#define     DWF_ASWU        vreinterpret_u32_f32
#define     DDU_ASWU        vreinterpret_u32_u64
#define     DDI_ASWU        vreinterpret_u32_s64
#define     DDF_ASWU        vreinterpret_u32_f64


#define     QYU_ASWU        vreinterpretq_u32_u64
#define     QBU_ASWU        vreinterpretq_u32_u8
#define     QBI_ASWU        vreinterpretq_u32_s8
//efine     QBC_ASWU
#define     QHU_ASWU        vreinterpretq_u32_u16
#define     QHI_ASWU        vreinterpretq_u32_s16
#define     QHF_ASWU        vreinterpretq_u32_f16
//efine     QWU_ASWU
#define     QWI_ASWU        vreinterpretq_u32_s32
#define     QWF_ASWU        vreinterpretq_u32_f32
#define     QDU_ASWU        vreinterpretq_u32_u64
#define     QDI_ASWU        vreinterpretq_u32_s64
#define     QDF_ASWU        vreinterpretq_u32_f64


#define     VWYU_ASWU(V)    WWU_ASTV(VWYU_ASTM(V))
#define     VWBU_ASWU(V)    WWU_ASTV(VWBU_ASTM(V))
#define     VWBI_ASWU(V)    WWU_ASTV(VWBI_ASTM(V))
//efine     VWBC_ASWU
#define     VWHU_ASWU(V)    WWU_ASTV(VWHU_ASTM(V))
#define     VWHI_ASWU(V)    WWU_ASTV(VWHI_ASTM(V))
#define     VWHF_ASWU(V)    WWU_ASTV(VWHF_ASTM(V))
//efine     VWWU_ASWU
#define     VWWI_ASWU(V)    WWU_ASTV(VWWI_ASTM(V))
#define     VWWF_ASWU(V)    WWU_ASTV(VWWF_ASTM(V))


#define     VDYU_ASWU(V)    vreinterpret_u32_u64(VDYU_ASTM(V))
#define     VDBU_ASWU       DBU_ASWU
#define     VDBU_ASWU       DBU_ASWU
#define     VDBI_ASWU       DBI_ASWU
//efine     VDBC_ASWU
#define     VDHU_ASWU       DHU_ASWU
#define     VDHI_ASWU       DHI_ASWU
#define     VDHF_ASWU       DHF_ASWU
//efine     VDWU_ASWU
#define     VDWI_ASWU       DWI_ASWU
#define     VDWF_ASWU       DWF_ASWU
#define     VDDU_ASWU       DDU_ASWU
#define     VDDI_ASWU       DDI_ASWU
#define     VDDF_ASWU       DDF_ASWU


#define     VQYU_ASWU(V)    vreinterpretq_u32_u64(VQYU_ASTM(V))
#define     VQBU_ASWU       QBU_ASWU
#define     VQBI_ASWU       QBI_ASWU
//efine     VQBC_ASWU
#define     VQHU_ASWU       QHU_ASWU
#define     VQHI_ASWU       QHI_ASWU
#define     VQHF_ASWU       QHF_ASWU
//efine     VQWU_ASWU
#define     VQWI_ASWU       QWI_ASWU
#define     VQWF_ASWU       QWF_ASWU
#define     VQDU_ASWU       QDU_ASWU
#define     VQDI_ASWU       QDI_ASWU
#define     VQDF_ASWU       QDF_ASWU

#if _LEAVE_EXTGOP_ARM_ASWU
}
#endif

#if _ENTER_EXTGOP_ARM_ASWI
{
#endif

#define     DYU_ASWI        vreinterpret_s32_u64
#define     DBU_ASWI        vreinterpret_s32_u8
#define     DBI_ASWI        vreinterpret_s32_s8
//efine     DBC_ASWI
#define     DHU_ASWI        vreinterpret_s32_u16
#define     DHI_ASWI        vreinterpret_s32_s16
#define     DHF_ASWI        vreinterpret_s32_f16
#define     DWU_ASWI        vreinterpret_s32_u32
//efine     DWI_ASWI
#define     DWF_ASWI        vreinterpret_s32_f32
#define     DDU_ASWI        vreinterpret_s32_u64
#define     DDI_ASWI        vreinterpret_s32_s64
#define     DDF_ASWI        vreinterpret_s32_f64


#define     QYU_ASWI        vreinterpretq_s32_u64
#define     QBU_ASWI        vreinterpretq_s32_u8
#define     QBI_ASWI        vreinterpretq_s32_s8
//efine     QBC_ASWI
#define     QHU_ASWI        vreinterpretq_s32_u16
#define     QHI_ASWI        vreinterpretq_s32_s16
#define     QHF_ASWI        vreinterpretq_s32_f16
#define     QWU_ASWI        vreinterpretq_s32_u32
//efine     QWI_ASWI
#define     QWF_ASWI        vreinterpretq_s32_f32
#define     QDU_ASWI        vreinterpretq_s32_u64
#define     QDI_ASWI        vreinterpretq_s32_s64
#define     QDF_ASWI        vreinterpretq_s32_f64


#define     VWYU_ASWI(V)    WWI_ASTV(VWYU_ASTM(V))
#define     VWBU_ASWI(V)    WWI_ASTV(VWBU_ASTM(V))
#define     VWBI_ASWI(V)    WWI_ASTV(VWBI_ASTM(V))
//efine     VWBC_ASWI
#define     VWHU_ASWI(V)    WWI_ASTV(VWHU_ASTM(V))
#define     VWHI_ASWI(V)    WWI_ASTV(VWHI_ASTM(V))
#define     VWHF_ASWI(V)    WWI_ASTV(VWHF_ASTM(V))
#define     VWWU_ASWI(V)    WWI_ASTV(VWWU_ASTM(V))
//efine     VWWI_ASWI
#define     VWWF_ASWI(V)    WWI_ASTV(VWWF_ASTM(V))


#define     VDYU_ASWI(V)    vreinterpret_s32_u64(VDYU_ASTM(V))
#define     VDBU_ASWI       DBU_ASWI
#define     VDBI_ASWI       DBI_ASWI
//efine     VDBC_ASWI
#define     VDHU_ASWI       DHU_ASWI
#define     VDHI_ASWI       DHI_ASWI
#define     VDHF_ASWI       DHF_ASWI
#define     VDWU_ASWI       DWU_ASWI
//efine     VDWI_ASWI
#define     VDWF_ASWI       DWF_ASWI
#define     VDDU_ASWI       DDU_ASWI
#define     VDDI_ASWI       DDI_ASWI
#define     VDDF_ASWI       DDF_ASWI


#define     VQYU_ASWI(V)    vreinterpretq_s32_u64(VQYU_ASTM(V))
#define     VQBU_ASWI       QBU_ASWI
#define     VQBI_ASWI       QBI_ASWI
//efine     VQBC_ASWI
#define     VQHU_ASWI       QHU_ASWI
#define     VQHI_ASWI       QHI_ASWI
#define     VQHF_ASWI       QHF_ASWI
#define     VQWU_ASWI       QWU_ASWI
//efine     VQWI_ASWI
#define     VQWF_ASWI       QWF_ASWI
#define     VQDU_ASWI       QDU_ASWI
#define     VQDI_ASWI       QDI_ASWI
#define     VQDF_ASWI       QDF_ASWI

#if _LEAVE_EXTGOP_ARM_ASWI
}
#endif

#if _ENTER_EXTGOP_ARM_ASWF
{
#endif

#define     DYU_ASWF        vreinterpret_f32_u64
#define     DBU_ASWF        vreinterpret_f32_u8
#define     DBI_ASWF        vreinterpret_f32_s8
//efine     DBC_ASWF
#define     DHU_ASWF        vreinterpret_f32_u16
#define     DHI_ASWF        vreinterpret_f32_s16
#define     DHF_ASWF        vreinterpret_f32_f16
#define     DWU_ASWF        vreinterpret_f32_u32
#define     DWI_ASWF        vreinterpret_f32_s32
//efine     DWF_ASWF
#define     DDU_ASWF        vreinterpret_f32_u64
#define     DDI_ASWF        vreinterpret_f32_s64
#define     DDF_ASWF        vreinterpret_f32_f64

#define     QBU_ASWF        vreinterpretq_f32_u8
#define     QBI_ASWF        vreinterpretq_f32_s8
//efine     QBC_ASWF
#define     QHU_ASWF        vreinterpretq_f32_u16
#define     QHI_ASWF        vreinterpretq_f32_s16
#define     QHF_ASWF        vreinterpretq_f32_f16
#define     QWU_ASWF        vreinterpretq_f32_u32
#define     QWI_ASWF        vreinterpretq_f32_s32
//efine     QWF_ASWF
#define     QDU_ASWF        vreinterpretq_f32_u64
#define     QDI_ASWF        vreinterpretq_f32_s64
#define     QDF_ASWF        vreinterpretq_f32_f64


#define     VWYU_ASWF(V)    WWF_ASTV(VWYU_ASTM(V))
#define     VWBU_ASWF(V)    WWF_ASTV(VWBU_ASTM(V))
#define     VWBI_ASWF(V)    WWF_ASTV(VWBI_ASTM(V))
//efine     VWBC_ASWF
#define     VWHU_ASWF(V)    WWF_ASTV(VWHU_ASTM(V))
#define     VWHI_ASWF(V)    WWF_ASTV(VWHI_ASTM(V))
#define     VWHF_ASWF(V)    WWF_ASTV(VWHF_ASTM(V))
#define     VWWU_ASWF(V)    WWF_ASTV(VWWU_ASTM(V))
#define     VWWI_ASWF(V)    WWF_ASTV(VWWI_ASTM(V))
//efine     VWWF_ASWF


#define     VDYU_ASWF(V)    vreinterpret_f32_u64(VDYU_ASTM(V))
#define     VDBU_ASWF       DBU_ASWF
#define     VDBI_ASWF       DBI_ASWF
//efine     VDBC_ASWF
#define     VDHU_ASWF       DHU_ASWF
#define     VDHI_ASWF       DHI_ASWF
#define     VDHF_ASWF       DHF_ASWF
#define     VDWU_ASWF       DWU_ASWF
#define     VDWI_ASWF       DWI_ASWF
//efine     VDWF_ASWF
#define     VDDU_ASWF       DDU_ASWF
#define     VDDI_ASWF       DDI_ASWF
#define     VDDF_ASWF       DDF_ASWF


#define     VQYU_ASWF(V)    vreinterpretq_f32_u64(VQYU_ASTM(V))
#define     VQBU_ASWF       QBU_ASWF
#define     VQBI_ASWF       QBI_ASWF
//efine     VQBC_ASWF
#define     VQHU_ASWF       QHU_ASWF
#define     VQHI_ASWF       QHI_ASWF
#define     VQHF_ASWF       QHF_ASWF
#define     VQWU_ASWF       QWU_ASWF
#define     VQWI_ASWF       QWI_ASWF
//efine     VQWF_ASWF
#define     VQDU_ASWF       QDU_ASWF
#define     VQDI_ASWF       QDI_ASWF
#define     VQDF_ASWF       QDF_ASWF

#if _LEAVE_EXTGOP_ARM_ASWF
}
#endif

#if _LEAVE_EXTGOP_ARM_ASW_
}
#endif


#if _ENTER_EXTGOP_ARM_ASD_
{
#endif

#if _ENTER_EXTGOP_ARM_ASDU
{
#endif

#define     DYU_ASDU        VDDU_REQS
#define     DBU_ASDU        vreinterpret_u64_u8
#define     DBI_ASDU        vreinterpret_u64_s8
//efine     DBC_ASDU
#define     DHU_ASDU        vreinterpret_u64_u16
#define     DHI_ASDU        vreinterpret_u64_s16
#define     DHF_ASDU        vreinterpret_u64_f16
#define     DWU_ASDU        vreinterpret_u64_u32
#define     DWI_ASDU        vreinterpret_u64_s32
#define     DWF_ASDU        vreinterpret_u64_f32
//efine     DDU_ASDU
#define     DDI_ASDU        vreinterpret_u64_s64
#define     DDF_ASDU        vreinterpret_u64_f64

#define     QYU_ASDU        VQDU_REQS
#define     QBU_ASDU        vreinterpretq_u64_u8
#define     QBI_ASDU        vreinterpretq_u64_s8
//efine     QBC_ASDU
#define     QHU_ASDU        vreinterpretq_u64_u16
#define     QHI_ASDU        vreinterpretq_u64_s16
#define     QHF_ASDU        vreinterpretq_u64_f16
#define     QWU_ASDU        vreinterpretq_u64_u32
#define     QWI_ASDU        vreinterpretq_u64_s32
#define     QWF_ASDU        vreinterpretq_u64_f32
//efine     QDU_ASDU
#define     QDI_ASDU        vreinterpretq_u64_s64
#define     QDF_ASDU        vreinterpretq_u64_f64

#define     VDYU_ASDU       VDYU_ASTM
#define     VDBU_ASDU       DBU_ASDU
#define     VDBI_ASDU       DBI_ASDU
//efine     VDBC_ASDU
#define     VDHU_ASDU       DHU_ASDU
#define     VDHI_ASDU       DHI_ASDU
#define     VDHF_ASDU       DHF_ASDU
#define     VDWU_ASDU       DWU_ASDU
#define     VDWI_ASDU       DWI_ASDU
#define     VDWF_ASDU       DWF_ASDU
//efine     VDDU_ASDU
#define     VDDI_ASDU       DDI_ASDU
#define     VDDF_ASDU       DDF_ASDU

#define     VQYU_ASDU       VQYU_ASTM
#define     VQBU_ASDU       QBU_ASDU
#define     VQBI_ASDU       QBI_ASDU
//efine     VQBC_ASDU
#define     VQHU_ASDU       QHU_ASDU
#define     VQHI_ASDU       QHI_ASDU
#define     VQHF_ASDU       QHF_ASDU
#define     VQWU_ASDU       QWU_ASDU
#define     VQWI_ASDU       QWI_ASDU
#define     VQWF_ASDU       QWF_ASDU
//efine     VDDU_ASDU
#define     VQDI_ASDU       QDI_ASDU
#define     VQDF_ASDU       QDF_ASDU

#if _LEAVE_EXTGOP_ARM_ASDU
}
#endif

#if _ENTER_EXTGOP_ARM_ASDI
{
#endif

#define     DYU_ASDI        vreinterpret_s64_u64
#define     DBU_ASDI        vreinterpret_s64_u8
#define     DBI_ASDI        vreinterpret_s64_s8
//efine     DBC_ASDI
#define     DHU_ASDI        vreinterpret_s64_u16
#define     DHI_ASDI        vreinterpret_s64_s16
#define     DHF_ASDI        vreinterpret_s64_f16
#define     DWU_ASDI        vreinterpret_s64_u32
#define     DWI_ASDI        vreinterpret_s64_s32
#define     DWF_ASDI        vreinterpret_s64_f32
#define     DDU_ASDI        vreinterpret_s64_u64
//efine     DDI_ASDI
#define     DDF_ASDI        vreinterpret_s64_f64

#define     QYU_ASDI        vreinterpretq_s64_u64
#define     QBU_ASDI        vreinterpretq_s64_u8
#define     QBI_ASDI        vreinterpretq_s64_s8
//efine     QBC_ASDI 
#define     QHU_ASDI        vreinterpretq_s64_u16
#define     QHI_ASDI        vreinterpretq_s64_s16
#define     QHF_ASDI        vreinterpretq_s64_f16
#define     QWU_ASDI        vreinterpretq_s64_u32
#define     QWI_ASDI        vreinterpretq_s64_s32
#define     QWF_ASDI        vreinterpretq_s64_f32
#define     QDU_ASDI        vreinterpretq_s64_u64
//efine     QDI_ASDI 
#define     QDF_ASDI        vreinterpretq_s64_f64


#define     VDYU_ASDI(V)    vreinterpret_s64_u64(VDYU_ASTM(V))
#define     VDBU_ASDI       DBU_ASDI
#define     VDBI_ASDI       DBI_ASDI
//efine     VDBC_ASDI 
#define     VDHU_ASDI       DHU_ASDI
#define     VDHI_ASDI       DHI_ASDI
#define     VDHF_ASDI       DHF_ASDI
#define     VDWU_ASDI       DWU_ASDI
#define     VDWI_ASDI       DWI_ASDI
#define     VDWF_ASDI       DWF_ASDI
#define     VDDU_ASDI       DDU_ASDI
//efine     VDDI_ASDI 
#define     VDDF_ASDI       DDF_ASDI


#define     VQYU_ASDI(V)    vreinterpretq_s64_u64(VQYU_ASTM(V))
#define     VQBU_ASDI       QBU_ASDI
#define     VQBI_ASDI       QBI_ASDI
//efine     VQBC_ASDI
#define     VQHU_ASDI       QHU_ASDI
#define     VQHF_ASDI       QHF_ASDI
#define     VQHI_ASDI       QHI_ASDI
#define     VQWU_ASDI       QWU_ASDI
#define     VQWI_ASDI       QWI_ASDI
#define     VQWF_ASDI       QWF_ASDI
#define     VQDU_ASDI       QDU_ASDI
//efine     VQDI_ASDI 
#define     VQDF_ASDI       QDF_ASDI

#if _LEAVE_EXTGOP_ARM_ASDI
}
#endif

#if _ENTER_EXTGOP_ARM_ASDF
{
#endif

#define     DYU_ASDF        vreinterpret_f64_u64
#define     DBU_ASDF        vreinterpret_f64_u8
#define     DBI_ASDF        vreinterpret_f64_s8
#define     DHU_ASDF        vreinterpret_f64_u16
#define     DHI_ASDF        vreinterpret_f64_s16
#define     DHF_ASDF        vreinterpret_f64_f16
#define     DWU_ASDF        vreinterpret_f64_u32
#define     DWI_ASDF        vreinterpret_f64_s32
#define     DWF_ASDF        vreinterpret_f64_f32
#define     DDU_ASDF        vreinterpret_f64_u64
#define     DDI_ASDF        vreinterpret_f64_u64
//efine     DDF_ASDF


#define     QYU_ASDF        vreinterpretq_f64_u64
#define     QBU_ASDF        vreinterpretq_f64_u8
#define     QBI_ASDF        vreinterpretq_f64_s8
#define     QHU_ASDF        vreinterpretq_f64_u16
#define     QHI_ASDF        vreinterpretq_f64_s16
#define     QHF_ASDF        vreinterpretq_f64_f16
#define     QWU_ASDF        vreinterpretq_f64_u32
#define     QWI_ASDF        vreinterpretq_f64_s32
#define     QWF_ASDF        vreinterpretq_f64_f32
#define     QDU_ASDF        vreinterpretq_f64_u64
#define     QDI_ASDF        vreinterpretq_f64_s64
//efine     QDF_ASDF


#define     VDYU_ASDF(V)    vreinterpret_f64_u64(VDYU_ASTM(V))
#define     VDBU_ASDF       DBU_ASDF
#define     VDBI_ASDF       DBI_ASDF
//efine     VDBC_ASDF
#define     VDHU_ASDF       DHU_ASDF
#define     VDHI_ASDF       DHI_ASDF
#define     VDHF_ASDF       DHF_ASDF
#define     VDWU_ASDF       DWU_ASDF
#define     VDWI_ASDF       DWI_ASDF
#define     VDWF_ASDF       DWF_ASDF
#define     VDDU_ASDF       DDU_ASDF
#define     VDDI_ASDF       DDI_ASDF
//efine     VDDF_ASDF


#define     VQYU_ASDF(V)    vreinterpretq_f64_u64(VQYU_ASTM(V))
#define     VQBU_ASDF       QBU_ASDF
#define     VQBI_ASDF       QBI_ASDF
//efine     VQBC_ASDF
#define     VQHU_ASDF       QHU_ASDF
#define     VQHI_ASDF       QHI_ASDF
#define     VQHF_ASDF       QHF_ASDF
#define     VQWU_ASDF       QWU_ASDF
#define     VQWI_ASDF       QWI_ASDF
#define     VQWF_ASDF       QWF_ASDF
#define     VQDU_ASDF       QDU_ASDF
#define     VQDI_ASDF       QDI_ASDF
//efine     VQDF_ASDF

#if _LEAVE_EXTGOP_ARM_ASDF
}
#endif

#if _LEAVE_EXTGOP_ARM_ASD_
}
#endif


#if _ENTER_EXTGOP_ARM_AST_
{
#endif


#if _ENTER_EXTGOP_ARM_ASTM
{
#endif

#define     VWYU_ASTM(V)    _Generic((V),VWYU_TYPE:(V).V0)
#define     VWBU_ASTM(V)    _Generic((V),VWBU_TYPE:(V).V0)
#define     VWBI_ASTM(V)    _Generic((V),VWBI_TYPE:(V).V0)
#define     VWBC_ASTM(V)    _Generic((V),VWBC_TYPE:(V).V0)
#define     VWHU_ASTM(V)    _Generic((V),VWHU_TYPE:(V).V0)
#define     VWHI_ASTM(V)    _Generic((V),VWHI_TYPE:(V).V0)
#define     VWHF_ASTM(V)    _Generic((V),VWHF_TYPE:(V).V0)
#define     VWWU_ASTM(V)    _Generic((V),VWWU_TYPE:(V).V0)
#define     VWWI_ASTM(V)    _Generic((V),VWWI_TYPE:(V).V0)
#define     VWWF_ASTM(V)    _Generic((V),VWWF_TYPE:(V).V0)


#define     VDYU_ASTM(V)    _Generic((V),VDYU_TYPE:(V).V0)
#define     VDBU_ASTM       VDBU_REQS
#define     VDBI_ASTM       VDBI_REQS
#define     VDBC_ASTM(V)    _Generic((V),VDBC_TYPE:(V).V0)
#define     VDHU_ASTM       VDHU_REQS
#define     VDHI_ASTM       VDHI_REQS
#define     VDHF_ASTM       VDHF_REQS
#define     VDWU_ASTM       VDWU_REQS
#define     VDWI_ASTM       VDWI_REQS
#define     VDWF_ASTM       VDWF_REQS
#define     VDDU_ASTM       VDDU_REQS
#define     VDDI_ASTM       VDDI_REQS
#define     VDDF_ASTM       VDDF_REQS


#define     VQYU_ASTM(V)    _Generic((V),VQYU_TYPE:(V).V0)
#define     VQBU_ASTM       VQBU_REQS
#define     VQBI_ASTM       VQBI_REQS
#define     VQBC_ASTM(V)    _Generic((V),VQBC_TYPE:(V).V0)
#define     VQHU_ASTM       VQHU_REQS
#define     VQHI_ASTM       VQHI_REQS
#define     VQHF_ASTM       VQHF_REQS
#define     VQWU_ASTM       VQWU_REQS
#define     VQWI_ASTM       VQWI_REQS
#define     VQWF_ASTM       VQWF_REQS
#define     VQDU_ASTM       VQDU_REQS
#define     VQDI_ASTM       VQDI_REQS
#define     VQDF_ASTM       VQDF_REQS

#if _LEAVE_EXTGOP_ARM_ASTM
}
#endif

#if _ENTER_EXTGOP_ARM_ASTV
{
#endif

INLINE(Vwwu,UINT_ASTV) (unsigned int m)
{
#define     UINT_ASTV(M)    \
(\
    (VWWU_TYPE)\
    {vget_lane_f32(vreinterpret_f32_u32(vdup_n_u32(M)),V2_K0)}\
)
    return  UINT_ASTV(m);
}

INLINE(Vwwi,INT_ASTV) (int m)
{
#define     INT_ASTV(M)     \
((VWWI_TYPE){vget_lane_f32(vreinterpret_f32_s32(vdup_n_s32(M)),V2_K0)})
    return  INT_ASTV(m);
}


INLINE(Vwwf,FLT_ASTV) (float m)
{
#define     FLT_ASTV(M)     ((VWWF_TYPE){M})
    return  FLT_ASTV(m);
}

INLINE(Vddf,DBL_ASTV) (double m)
{
#define     DBL_ASTV(M)     vdup_n_f64(M)
    return  DBL_ASTV(m);
}


#if DWRD_NLONG == 2

INLINE(Vwwu,ULONG_ASTV) (unsigned long m)
{
#define     ULONG_ASTV(M)    \
((VWWU_TYPE){vget_lane_f32(vreinterpret_f32_u32(vdup_n_u32(M)),V2_K0)})

    return  ULONG_ASTV(m);
}

INLINE(Vwwi,LONG_ASTV) (long m)
{
#define     LONG_ASTV(M)    \
((VWWI_TYPE){vget_lane_f32(vreinterpret_f32_s32(vdup_n_s32(M)),V2_K0)})
    return  LONG_ASTV(m);
}

#else

INLINE(Vddu,ULONG_ASTV) (unsigned long m)
{
#define     ULONG_ASTV(M)   vdup_n_u64(M)
    return  ULONG_ASTV(m);
}

INLINE(Vddi,LONG_ASTV) (long m)
{
#define     LONG_ASTV(M)    vdup_n_s64(M)
    return  LONG_ASTV(m);
}

#endif


INLINE(Vddu,ULLONG_ASTV) (unsigned long long m)
{
#define     ULLONG_ASTV(M)   vdup_n_u64(M)
    return  ULLONG_ASTV(m);
}

INLINE(Vddi,LLONG_ASTV) (long m)
{
#define     LLONG_ASTV(M)    vdup_n_s64(M)
    return  LLONG_ASTV(m);
}

#define     WYU_ASTV(M)     ((VWYU_TYPE){M})
#define     WBU_ASTV(M)     ((VWBU_TYPE){M})
#define     WBI_ASTV(M)     ((VWBI_TYPE){M})
#define     WBC_ASTV(M)     ((VWBC_TYPE){M})
#define     WHU_ASTV(M)     ((VWHU_TYPE){M})
#define     WHI_ASTV(M)     ((VWHI_TYPE){M})
#define     WHF_ASTV(M)     ((VWHF_TYPE){M})
#define     WWU_ASTV(M)     ((VWWU_TYPE){M})
#define     WWI_ASTV(M)     ((VWWI_TYPE){M})
#define     WWF_ASTV(M)     ((VWWF_TYPE){M})

#define     VWWU_ASTV(V)    (VWWU_REQS(V).V0)
#define     VWWI_ASTV(V)    (VWWI_REQS(V).V0)
#define     VWWF_ASTV(V)    (VWWF_REQS(V).V0)

#define     DYU_ASTV(M)     ((VDYU_TYPE){_Generic((M),VDYU_MTYPE:(M))})
#define     DBU_ASTV        VDBU_REQS
#define     DBI_ASTV        VDBI_REQS
#define     DBC_ASTV(M)     ((VDBC_TYPE){_Generic((M),VDBC_MTYPE:(M))})
#define     DHU_ASTV        VDHU_REQS
#define     DHI_ASTV        VDHI_REQS
#define     DHF_ASTV        VDHF_REQS
#define     DWU_ASTV        VDWU_REQS
#define     DWI_ASTV        VDWI_REQS
#define     DWF_ASTV        VDWF_REQS
#define     DDU_ASTV        VDDU_REQS
#define     DDI_ASTV        VDDI_REQS
#define     DDF_ASTV        VDDF_REQS

#define     VDDU_ASTV(V)    vget_lane_u64(V,0)
#define     VDDI_ASTV(V)    vget_lane_s64(V,0)
#define     VDDF_ASTV(V)    vget_lane_f64(V,0)

#define     QYU_ASTV(M)     ((VQYU_TYPE){M})
#define     QBU_ASTV        VQBU_REQS
#define     QBI_ASTV        VQBI_REQS
#define     QBC_ASTV(M)     ((VQBC_TYPE){M})
#define     QHU_ASTV        VQHU_REQS
#define     QHI_ASTV        VQHI_REQS
#define     QHF_ASTV        VQHF_REQS
#define     QWU_ASTV        VQWU_REQS
#define     QWI_ASTV        VQWI_REQS
#define     QWF_ASTV        VQWF_REQS
#define     QDU_ASTV        VQDU_REQS
#define     QDI_ASTV        VQDI_REQS
#define     QDF_ASTV        VQDF_REQS

#if _LEAVE_EXTGOP_ARM_ASTV
}
#endif

#if _ENTER_EXTGOP_ARM_ASTU
{
#endif

//efine     DBU_ASTU
#define     DBI_ASTU        DBI_ASBU
#define     DBC_ASTU        DBC_ASBU
//efine     DHU_ASTU
#define     DHI_ASTU        DHI_ASHU
#define     DHF_ASTU        DHF_ASHU
//efine     DWU_ASTU
#define     DWI_ASTU        DWI_ASWU
#define     DWF_ASTU        DWF_ASWU
//efine     DDU_ASTU
#define     DDI_ASTU        DDI_ASDU
#define     DDF_ASTU        DDF_ASDU


//efine     QBU_ASTU
#define     QBI_ASTU        QBI_ASBU
#define     QBC_ASTU        QBC_ASBU
//efine     QHU_ASTU
#define     QHI_ASTU        QHI_ASHU
#define     QHF_ASTU        QHF_ASHU
//efine     QWU_ASTU
#define     QWI_ASTU        QWI_ASWU
#define     QWF_ASTU        QWF_ASWU
//efine     QDU_ASTU
#define     QDI_ASTU        QDI_ASDU
#define     QDF_ASTU        QDF_ASDU


//efine     VWBU_ASTU
#define     VWBI_ASTU       VWBI_ASBU
#define     VWBC_ASTU       VWBC_ASBU
//efine     VWHU_ASTU
#define     VWHI_ASTU       VWHI_ASHU
#define     VWHF_ASTU       VWHF_ASHU
//efine     VWWU_ASTU
#define     VWWI_ASTU       VWWI_ASWU
#define     VWWF_ASTU       VWWF_ASWU

//efine     VDBU_ASTU
#define     VDBI_ASTU       VDBI_ASBU
#define     VDBC_ASTU       VDBC_ASBU
//efine     VDHU_ASTU
#define     VDHI_ASTU       VDHI_ASHU
#define     VDHF_ASTU       VDHF_ASHU
//efine     VDWU_ASTU
#define     VDWI_ASTU       VDWI_ASWU
#define     VDWF_ASTU       VDWF_ASWU
//efine     VDDU_ASTU
#define     VDDI_ASTU       VDDI_ASDU
#define     VDDF_ASTU       VDDF_ASDU

//efine     VQBU_ASTU
#define     VQBI_ASTU       VQBI_ASBU
#define     VQBC_ASTU       VQBC_ASBU
//efine     VQHU_ASTU
#define     VQHI_ASTU       VQHI_ASHU
#define     VQHF_ASTU       VQHF_ASHU
//efine     VQWU_ASTU
#define     VQWI_ASTU       VQWI_ASWU
#define     VQWF_ASTU       VQWF_ASWU
//efine     VQDU_ASTU
#define     VQDI_ASTU       VQDI_ASDU
#define     VQDF_ASTU       VQDF_ASDU

#if _LEAVE_EXTGOP_ARM_ASTU
}
#endif

#if _ENTER_EXTGOP_ARM_ASTI
{
#endif

#define     DBU_ASTI        DBU_ASBI
//efine     DBI_ASTI
#define     DBC_ASTI        DBC_ASBI
#define     DHU_ASTI        DHU_ASHI
//efine     DHI_ASTI
#define     DHF_ASTI        DHF_ASHI
#define     DWU_ASTI        DWU_ASWI
//efine     DWI_ASTI
#define     DWF_ASTI        DWF_ASWI
#define     DDU_ASTI        DDU_ASDI
//efine     DFI_ASTI
#define     DDF_ASTI        DDF_ASDI

#define     QBU_ASTI        QBU_ASBI
//efine     QBI_ASTI
#define     QBC_ASTI        QBC_ASBI
#define     QHU_ASTI        QHU_ASHI
//efine     QHI_ASTI
#define     QHF_ASTI        QHF_ASHI
#define     QWU_ASTI        QWU_ASWI
//efine     QWI_ASTI
#define     QWF_ASTI        QWF_ASWI
#define     QDU_ASTI        QDU_ASDI
//efine     QDI_ASTI
#define     QDF_ASTI        QDF_ASDI

#define     VWBU_ASTI       VWBU_ASBI
//efine     VWBI_ASTI
#define     VWBC_ASTI       VWBC_ASBI
#define     VWHU_ASTI       VWHU_ASHI
//efine     VWHI_ASTI
#define     VWHF_ASTI       VWHF_ASHI
#define     VWWU_ASTI       VWWU_ASWI
//efine     VWWI_ASTI
#define     VWWF_ASTI       VWWF_ASWI

#define     VDBU_ASTI       VDBU_ASBI
//efine     VDBI_ASTI
#define     VDBC_ASTI       VDBC_ASBI
#define     VDHU_ASTI       VDHU_ASHI
//efine     VDHI_ASTI
#define     VDHF_ASTI       VDHF_ASHI
#define     VDWU_ASTI       VDWU_ASWI
//efine     VDWI_ASTI
#define     VDWF_ASTI       VDWF_ASWI
#define     VDDU_ASTI       VDDU_ASDI
//efine     VDDI_ASTI
#define     VDDF_ASTI       VDDF_ASDI

#define     VQBU_ASTI       VQBU_ASBI
//efine     VQBI_ASTI
#define     VQBC_ASTI       VQBC_ASBI
#define     VQHU_ASTI       VQHU_ASHI
//efine     VQHI_ASTI
#define     VQHF_ASTI       VQHF_ASHI
#define     VQWU_ASTI       VQWU_ASWI
//efine     VQWI_ASTI
#define     VQWF_ASTI       VQWF_ASWI
#define     VQDU_ASTI       VQDU_ASDI
//efine     VQDI_ASTI
#define     VQDF_ASTI       VQDF_ASDI

#if _LEAVE_EXTGOP_ARM_ASTI
}
#endif

#if _ENTER_EXTGOP_ARM_ASTF
{
#endif

#define     DHU_ASTF        DHU_ASHF
#define     DHI_ASTF        DHI_ASHF
//efine     DHF_ASTF
#define     DWU_ASTF        DWU_ASWF
#define     DWI_ASTF        DWI_ASWF
//efine     DWF_ASTF
#define     DDU_ASTF        DDU_ASDF
#define     DDI_ASTF        DDI_ASDF
//efine     DDF_ASTF

#define     QHU_ASTF        QHU_ASHF
#define     QHI_ASTF        QHI_ASHF
//efine     QHF_ASTF
#define     QWU_ASTF        QWU_ASWF
#define     QWI_ASTF        QWI_ASWF
//efine     QWF_ASTF
#define     QDU_ASTF        QDU_ASDF
#define     QDI_ASTF        QDI_ASDF
//efine     QDF_ASTF

#define     VWHU_ASTF       VWHU_ASHF
#define     VWHI_ASTF       VWHI_ASHF
//efine     VWHF_ASTF
#define     VWWU_ASTF       VWWU_ASWF
#define     VWWI_ASTF       VWWI_ASWF
//efine     VWWF_ASTF

#define     VDHU_ASTF       VDHU_ASHF
#define     VDHI_ASTF       VDHI_ASHF
//efine     VDHF_ASTF
#define     VDWU_ASTF       VDWU_ASWF
#define     VDWI_ASTF       VDWI_ASWF
//efine     VDWF_ASTF
#define     VDDU_ASTF       VDDU_ASDF
#define     VDDI_ASTF       VDDI_ASDF
//efine     VDDF_ASTF

#define     VQHU_ASTF       VQHU_ASHF
#define     VQHI_ASTF       VQHI_ASHF
//efine     VQHF_ASTF
#define     VQWU_ASTF       VQWU_ASWF
#define     VQWI_ASTF       VQWI_ASWF
//efine     VQWF_ASTF
#define     VQDU_ASTF       VQDU_ASDF
#define     VQDI_ASTF       VQDI_ASDF
//efine     VQDF_ASTF

#if _LEAVE_EXTGOP_ARM_ASTF
}
#endif

#if _LEAVE_EXTGOP_ARM_AST_
}
#endif

#if _LEAVE_EXTGOP_ARM_AS__
}
#endif


#if _ENTER_EXTGOP_ARM_CV__
{
#endif

#if _ENTER_EXTGOP_ARM_CVB_
{
#endif

#if _ENTER_EXTGOP_ARM_CVBU
{
#endif

INLINE(uint8_t,   BOOL_CVBU) (_Bool x)
{
#define     BOOL_CVBU   BOOL_CVBU
    return  x;
}

#if _LEAVE_EXTGOP_ARM_CVBU
}
#endif

#if _ENTER_EXTGOP_ARM_CVBI
{
#endif
#if _LEAVE_EXTGOP_ARM_CVBI
}
#endif

#if _ENTER_EXTGOP_ARM_CVBZ
{
#endif


INLINE(uint8_t,  SCHAR_CVBZ) (signed char x)
{
#define     SCHAR_CVBZ  vqmovunh_s16
    return  SCHAR_CVBZ(x);
}

INLINE(uint8_t,   CHAR_CVBZ) (char x)
{
#if CHAR_MIN
#   define  CHAR_CVBZ   vqmovunh_s16
    return  SCHAR_CVBZ(x);
#else
#   define  CHAR_CVBZ   CHAR_CVBZ
    return  x;
#endif
}


INLINE(uint8_t,  USHRT_CVBZ) (unsigned short x)
{
#define     USHRT_CVBZ      vqmovnh_u16
    return  USHRT_CVBZ(x);
}

INLINE(uint8_t,   SHRT_CVBZ) (short x)
{
#define     SHRT_CVBZ       vqmovunh_s16
    return  SHRT_CVBZ(x);
}


INLINE(uint8_t,   UINT_CVBZ) (unsigned int x)
{
#   define  UINT_CVBZ   UINT_CVBZ
    return  x|vtstd_u64(x, UINT64_MAX-UINT8_MAX);
}

INLINE(uint8_t,    INT_CVBZ) (int x)
{
#   define  INT_CVBZ(X)     vqmovunh_s16(vqmovns_s32(X))
    return  INT_CVBZ(x);
}


INLINE(uint8_t,  ULONG_CVBZ) (unsigned long x)
{
#if DWRD_NLONG == 2
#   define  ULONG_CVBZ  UINT_CVBZ
    return  ULONG_CVBZ(x);
#else
#   define  ULONG_CVBZ  ULONG_CVBZ
    return  x|vtstd_u64(x, UINT64_MAX-UINT8_MAX);
#endif
}

INLINE(uint8_t,   LONG_CVBZ) (long x)
{
#if DWRD_NLONG == 2
#   define  LONG_CVBZ   INT_CVBZ
    return  LONG_CVBZ(x);
#else
    uint32_t m = vqmovund_s64(x);
    return  m|vtstd_u64(m, UINT64_MAX-UINT8_MAX);
#endif
}


INLINE(uint8_t, ULLONG_CVBZ) (unsigned long long x)
{
#   define  ULLONG_CVBZ     ULLONG_CVBZ
    return  x|vtstd_u64(x, UINT64_MAX-UINT8_MAX);
}

INLINE(uint8_t,  LLONG_CVBZ) (long long x)
{
#   define  LLONG_CVBZ      LLONG_CVBZ
    uint32_t m = vqmovund_s64(x);
    return  m|vtstd_u64(m, UINT64_MAX-UINT8_MAX);
}

INLINE(uint8_t,  FLT16_CVBZ) (flt16_t x)
{
#define     FLT16_CVBZ  FLT16_CVBZ
    uint32_t m = vcvts_u32_f32(x);
    return   m|vtstd_u64(m, UINT64_MAX-UINT8_MAX);
}

INLINE(uint8_t,    FLT_CVBZ) (float x)
{
#define     FLT_CVBZ    FLT_CVBZ
    uint32_t m = vcvts_u32_f32(x);
    return m|vtstd_u64(m, UINT64_MAX-UINT8_MAX);
}

INLINE(uint8_t,    DBL_CVBZ) (double x)
{
#define     DBL_CVBZ    DBL_CVBZ 
    uint64_t m = vcvtd_u64_f64(x);
    return m|vtstd_u64(m, UINT64_MAX-UINT8_MAX);
}

#define     INT8_CVBZ         INT8_BASE(CVBZ)
#define     UINT16_CVBZ     UINT16_BASE(CVBZ)
#define     INT16_CVBZ       INT16_BASE(CVBZ)
#define     UINT32_CVBZ     UINT32_BASE(CVBZ)
#define     INT32_CVBZ       INT32_BASE(CVBZ)
#define     UINT64_CVBZ     UINT32_BASE(CVBZ)
#define     INT64_CVBZ       INT64_BASE(CVBZ)

INLINE( Wbu, WBI_CVBZ) ( Wbi m)
{
    float32x2_t d = vset_lane_f32(m, d, V2_K0);
    int16x8_t   q = vmovl_s8(vreinterpret_s8_f32(d));
    d = vreinterpret_f32_u8(vqmovun_s16(q));
    return vget_lane_f32(d, V2_K0);
}

INLINE(Vwbu,VWBI_CVBZ) (Vwbi v)
{
#define     VWBI_CVBZ(V)    WBU_ASTV(WBI_CVBZ(VWBI_ASTM(V)))
    return  VWBI_CVBZ(v);
}

INLINE(Vwbu,VWBC_CVBZ) (Vwbc v)
{
#if CHAR_MIN
#   define  VWBC_CVBZ(V)    WBU_ASTV(WBI_CVBZ(VWBC_ASTM(V)))
#else
#   define  VWBC_CVBZ   VWBC_ASBU
#endif
    return  VWBC_CVBZ(v);
}


INLINE(Vdbu,VDBI_CVBZ) (Vdbi v)
{
#define     DBI_CVBZ(M) vqmovun_s16(vmovl_s8(M))
#define     VDBI_CVBZ DBI_CVBZ
    return  VDBI_CVBZ(v);
}

INLINE(Vdbu,VDBC_CVBZ) (Vdbc v)
{
#if CHAR_MIN
#   define  VDBC_CVBZ(V)    VDBI_CVBZ(VDBC_ASTM(V))
#else
#   define  VDBC_CVBZ   VDBC_ASBU
#endif
    return  VDBC_CVBZ(v);
}


INLINE(Vwbu,VDHU_CVBZ) (Vdhu v)
{
#define     DHU_CVBZ(V)     \
vget_lane_f32(              \
    vreinterpret_f32_u8(    \
        vqmovn_u16(         \
            vcombine_u16(   \
                V,          \
                VDHU_VOID   \
            )               \
        )                   \
    ),                      \
    V2_K0                   \
)

#define     VDHU_CVBZ(V)    WBU_ASTV(DHU_CVBZ(V))
    return  VDHU_CVBZ(v);
}

INLINE(Vwbu,VDHI_CVBZ) (Vdhi v)
{
#define     DHI_CVBZ(V)     \
vget_lane_f32(              \
    vreinterpret_f32_s8(    \
        vqmovn_s16(         \
            vcombine_s16(   \
                V,          \
                VDHI_VOID   \
            )               \
        )                   \
    ),                      \
    V2_K0                   \
)

#define     VDHI_CVBZ(V)    WBU_ASTV(DHI_CVBZ(V))
    return  VDHI_CVBZ(v);
}

INLINE(Vwbu,VDHF_CVBZ) (Vdhf v)
{
#if defined(SPC_ARM_FP16_SIMD)
#   define  DHF_CVBZ(M)             \
vget_lane_f32(                      \
    vreinterpret_f32_u8(            \
        vqmovn_u16(                 \
            vcombine_u16(           \
                vcvt_u16_f16(M),    \
                vdup_n_u16(0)       \
            )                       \
        )                           \
    ),                              \
    V2_K0                           \
)
#   define  VDHF_CVBZ(V)        WBU_ASTV(DHF_CVBZ(VDHF_ASTM(V)))
    return  VDHF_CVBZ(v);
#else
#   define  VDHF_CVBZ           VDHF_CVBZ
    float32x4_t qwf = vcvt_f32_f16(v);
    uint32x4_t  qwu = vcvtq_u32_f32(qwf);
    uint16x4_t  dhu = vqmovn_u32(qwu);
    uint16x8_t  qhu = vcombine_u16(dhu, VDHU_VOID);
    uint8x8_t   dbu = vqmovn_u16(qhu);
    float32x2_t dwf = vreinterpret_f32_u8(dbu);
    return  WBU_ASTV(vget_lane_f32(dwf, V2_K0));
#endif
}

INLINE(Vdbu,VQHU_CVBZ) (Vqhu v)
{
#define     QHU_CVBZ        vqmovn_u16
#define     VQHU_CVBZ       VQHU_CVBZ
    return  QHU_CVBZ(v);
}

INLINE(Vdbu,VQHI_CVBZ) (Vqhi v)
{
#define     QHI_CVBZ        vqmovun_s16
#define     VQHI_CVBZ       VQHI_CVBZ
    return  QHI_CVBZ(v);
}


INLINE(Vwbu,VQWU_CVBZ) (Vqwu v)
{
#define     QWU_CVBZ(M)     DHU_CVBZ(vqmovn_u32(M))
#define     VQWU_CVBZ(V)    WBU_ASTV(QWU_CVBZ(V))
    return  VQWU_CVBZ(v);
}

INLINE(Vwbu,VQWI_CVBZ) (Vqwi v)
{
#define     QWI_CVBZ(M)     DHU_CVBZ(vqmovun_s32(M))
#define     VQWI_CVBZ(V)    WBU_ASTV(QWI_CVBZ(V))
    return  VQWI_CVBZ(v);
}

INLINE(Vwbu,VQWF_CVBZ) (Vqwf v)
{
#define     QWF_CVBZ(M)             \
vget_lane_f32(                      \
    vreinterpret_f32_u8(            \
        vqmovn_u16(                 \
            vcombine_u16(           \
                vqmovn_u32(         \
                    vcvtq_u32_f32(M)\
                ),                  \
                VDHU_VOID           \
            )                       \
        )                           \
    ),                              \
    V2_K0                           \
)

#define     VQWF_CVBZ(V)            WBU_ASTV(QWF_CVBZ(VQWF_ASTM(V)))
    return  VQWI_CVBZ(v);
}


#if _LEAVE_EXTGOP_ARM_CVBZ
}
#endif

#if _ENTER_EXTGOP_ARM_CVBS
{
#endif

#if _LEAVE_EXTGOP_ARM_CVBS
}
#endif

#if _LEAVE_EXTGOP_ARM_CVB_
}
#endif

#if _ENTER_EXTGOP_ARM_CVH_
{
#endif

#if _ENTER_EXTGOP_ARM_CVHU
{
#endif
#if _LEAVE_EXTGOP_ARM_CVHU
}
#endif

#if _ENTER_EXTGOP_ARM_CVHI
{
#endif
#if _LEAVE_EXTGOP_ARM_CVHI
}
#endif

#if _ENTER_EXTGOP_ARM_CVHZ
{
#endif

INLINE(Vwhu,VDWU_CVHZ) (Vdwu x)
{
#define     DWU_CVHZ(V)     \
vget_lane_f32(              \
    vreinterpret_f32_u16(   \
        vqmovn_u32(         \
            vcombine_u32(   \
                V,          \
                VDWU_VOID   \
            )               \
        )                   \
    ),                      \
    V2_K0                   \
)
#define     VDWU_CVHZ(X)    WHU_ASTV(DWU_CVHZ(X))
    return  VDWU_CVHZ(x);
}

INLINE(Vwhu,VDWI_CVHZ) (Vdwi x)
{
#define     DWI_CVHZ(V)     \
vget_lane_f32(              \
    vreinterpret_f32_s16(   \
        vqmovun_s32(        \
            vcombine_s32(   \
                V,          \
                VDWI_VOID   \
            )               \
        )                   \
    ),                      \
    V2_K0                   \
)
#define     VDWI_CVHZ(X)    WHU_ASTV(DWI_CVHZ(X))
    return  VDWI_CVHZ(x);
}

#if _LEAVE_EXTGOP_ARM_CVHZ
}
#endif

#if _ENTER_EXTGOP_ARM_CVHS
{
#endif
#if _LEAVE_EXTGOP_ARM_CVHS
}
#endif

#if _LEAVE_EXTGOP_ARM_CVH_
}
#endif

#if _ENTER_EXTGOP_ARM_CVW_
{
#endif

#if _ENTER_EXTGOP_ARM_CVWU
{
#endif
#if _LEAVE_EXTGOP_ARM_CVWU
}
#endif

#if _ENTER_EXTGOP_ARM_CVWI
{
#endif
#if _LEAVE_EXTGOP_ARM_CVWI
}
#endif

#if _ENTER_EXTGOP_ARM_CVWZ
{
#endif

INLINE(uint32_t,   INT_CVWZ) (int x)
{
#define     INT_CVWZ(X)     vqmovund_s64(X)
    return  INT_CVWZ(x);
}

INLINE(uint32_t, ULONG_CVWZ)( unsigned long x)
{
#if DWRD_NLONG == 2
#   define  ULONG_CVWZ      ULONG_CVWZ
    return  x;
#else
#   define  ULONG_CVWZ(X)   vqmovnd_u64(X)
    return  ULONG_CVWZ(x);
#endif
}

INLINE(uint32_t,  LONG_CVWZ) (long x)
{
#define     LONG_CVWZ(X)    vqmovund_s64(X)
    return  LONG_CVWZ(x);
}

INLINE(uint32_t,ULLONG_CVWZ) (unsigned long long x)
{
#define     ULLONG_CVWZ(X)  vqmovnd_u64(X)
    return  ULLONG_CVWZ(x);
}

INLINE(uint32_t, LLONG_CVWZ) (long long x)
{
#define     LLONG_CVWZ(X)   vqmovund_s64(X)
    return  LLONG_CVWZ(x);
}

INLINE(uint32_t,   FLT_CVWZ) (float x)
{
#define     FLT_CVWZ(X)     vcvts_u32_f32(X)
    return  FLT_CVWZ(x);
}

INLINE(uint32_t,   DBL_CVWZ) (double x)
{
#define     DBL_CVWZ(X) vqmovnd_u64(vcvtd_u64_f64(X))
    return  DBL_CVWZ(x);
}

#define     INT32_CVWZ       INT32_BASE(CVWZ)
#define     UINT64_CVWZ     UINT64_BASE(CVWZ)
#define     INT64_CVWZ       INT64_BASE(CVWZ)

INLINE( Wwu, WWI_CVWZ) ( Wwi m)
{
    float32x2_t f = vset_lane_f32(m, f, V2_K0);
    int64x2_t   q = vmovl_s32(vreinterpret_s32_f32(f));
    uint32x2_t  d = vqmovun_s64(q);
    f = vreinterpret_f32_u32(d);
    return vget_lane_f32(f, V2_K0);
}

INLINE(Vwwu,VWWI_CVWZ) (Vwwi v)
{
#define     VWWI_CVWZ(V)    WWU_ASTV(WWI_CVWZ(VWWI_ASTM(V)))
    return  VWWI_CVWZ(v);
}

INLINE( Wwu, WWF_CVWZ) ( Wwf m)
{
    float32x2_t d = vset_lane_f32(m, d, V2_K0);
    uint32x2_t  u = vcvt_u32_f32(d);
    d = vreinterpret_f32_u32(u);
    return vget_lane_f32(d, V2_K0);
}

INLINE(Vwwu,VWWF_CVWZ) (Vwwf v)
{
#define     VWWF_CVWZ(V) WWU_ASTV(WWF_CVWZ(VWWF_ASTM(V))) 
    return  VWWF_CVWZ(v);
}

INLINE(Vwwu,VDDU_CVWZ) (Vddu v)
{
#define     DDU_CVWZ(V)     \
vget_lane_f32(              \
    vreinterpret_f32_u32(   \
        vqmovn_u64(         \
            vcombine_u64(   \
                V,          \
                VDDU_VOID   \
            )               \
        )                   \
    ),                      \
    V2_K0                   \
)

#define     VDDU_CVWZ(V)    WWU_ASTV(DDU_CVWZ(V))
    return  VDDU_CVWZ(v);
}

INLINE(Vwwu,VDDI_CVWZ) (Vddi v)
{
#define     DDI_CVWZ(M)     \
vget_lane_f32(              \
    vreinterpret_f32_u32(   \
        vqmovun_s64(        \
            vcombine_s64(   \
                M,          \
                VDDI_VOID   \
            )               \
        )                   \
    ),                      \
    V2_K0                   \
)

#define     VDDI_CVWZ(V)    WWU_ASTV(DDI_CVWZ(V))
    return  VDDI_CVWZ(v);
}

INLINE(Vdwu,VQDU_CVWZ) (Vqdu v)
{
#define      QDU_CVWZ       vqmovn_u64
#define     VQDU_CVWZ(V)    QDU_CVWZ(V)
    return  VQDU_CVWZ(v);
}

INLINE(Vdwu,VQDI_CVWZ) (Vqdi v)
{
#define      QDI_CVWZ       vqmovun_s64
#define     VQDI_CVWZ(V)    QDI_CVWZ(V)
    return  VQDI_CVWZ(v);
}

#if _LEAVE_EXTGOP_ARM_CVWZ
}
#endif

#if _ENTER_EXTGOP_ARM_CVWS
{
#endif
#if _LEAVE_EXTGOP_ARM_CVWS
}
#endif

#if _LEAVE_EXTGOP_ARM_CVW_
}
#endif

#if _ENTER_EXTGOP_ARM_CVD_
{
#endif

#if _ENTER_EXTGOP_ARM_CVDU
{
#endif
#if _LEAVE_EXTGOP_ARM_CVDU
}
#endif

#if _ENTER_EXTGOP_ARM_CVDI
{
#endif
#if _LEAVE_EXTGOP_ARM_CVDI
}
#endif

#if _ENTER_EXTGOP_ARM_CVDZ
{
#endif
#if _LEAVE_EXTGOP_ARM_CVDZ
}
#endif

#if _ENTER_EXTGOP_ARM_CVDS
{
#endif
#if _LEAVE_EXTGOP_ARM_CVDS
}
#endif

#if _LEAVE_EXTGOP_ARM_CVD_
}
#endif

#if _LEAVE_EXTGOP_ARM_CV__
}
#endif



#if _ENTER_EXTGOP_ARM_DUP_
{
#endif

#if _ENTER_EXTGOP_ARM_DUPW
{
#endif

INLINE(Vwyu,BOOL_DUPW) (_Bool x)
{
#define     BOOL_DUPW(X)        \
WYU_ASTV(                       \
    vget_lane_f32(              \
        vreinterpret_f32_u64(   \
            vdup_n_u64(         \
                0ull-(_Bool)(X) \
            )                   \
        ),                      \
        V2_K0                   \
    )                           \
)
    return  BOOL_DUPW(x);
}

INLINE(Vwyu,VWYU_DUPW) (Vwyu v, Rc(0, 31) k)
{
#define     WYU_DUPW(M, K)              \
vget_lane_f32(                          \
    vreinterpret_f32_u32(               \
        vtst_u32(                       \
            vreinterpret_u32_f32(       \
                vdup_n_f32(M)           \
            ),                          \
            vreinterpret_u32_u64(       \
                vdup_n_u64(1<<(31&(K))) \
            )                           \
        )                               \
    ),                                  \
    V2_K0                               \
)
#define     VWYU_DUPW(V, K) WYU_ASTV(WYU_DUPW(VWYU_ASTM(V), K))
    return  VWYU_DUPW(v, k);
}

INLINE(Vwyu,VDYU_DUPW) (Vdyu v, Rc(0, 63) k)
{
#define     DYU_DUPW(M, K)          \
vget_lane_f32(                      \
    vreinterpret_f32_u64(           \
        vtst_u64(                   \
            M,                      \
            vdup_n_u64(1<<(63&(K))) \
        )                           \
    ),                              \
    V2_K0                           \
)
#define     VDYU_DUPW(V, K) WYU_ASTV(DYU_DUPW(VDYU_ASTM(V),K))
    return  VDYU_DUPW(v, k);
}

INLINE(Vwyu,VQYU_DUPW) (Vqyu x, Rc(0,127) k)
{
#define     QYU_DUPW(M, K)                          \
vget_lane_f32(                                      \
    vreinterpret_f32_u64(                           \
        vdup_lane_u64(                              \
            (                                       \
                ((K)>63)                            \
                ?   vtst_u64(                       \
                        vget_high_u64(M),           \
                        vdup_n_u64(1<<(63&K))       \
                    )                               \
                :   vtst_u64(                       \
                        vget_low_u64(M),            \
                        vdup_n_u64(1<<K)            \
                    )                               \
            ),                                      \
            0                                       \
        )                                           \
    ),                                              \
    V2_K0                                           \
)
#define     VQYU_DUPW(V, K) WYU_ASTV(QYU_DUPW(VQYU_ASTM(V),K))
    return  VQYU_DUPW(x, k);
}


INLINE(Vwbu,UCHAR_DUPW) (unsigned char x)
{
#define     UCHAR_DUPW(X)   \
WBU_ASTV(                   \
    vget_lane_f32(          \
        vreinterpret_f32_u8(\
            vdup_n_u8(X)    \
        ),                  \
        V2_K0               \
    )                       \
)
    return  UCHAR_DUPW(x);
}

INLINE(Vwbu,VWBU_DUPW) (Vwbu v, Rc(0, 3) k)
{
#define     WBU_DUPW(M, K)          \
vget_lane_f32(                      \
    vreinterpret_f32_u8(            \
        vdup_lane_u8(               \
            vreinterpret_u8_f32(    \
                vdup_n_f32(M)       \
            ),                      \
            3&(K)                   \
        )                           \
    ),                              \
    V2_K0                           \
)

#define     VWBU_DUPW(V, K) WBU_ASTV(WBU_DUPW(VWBU_ASTM(V), K))
    float32x2_t m = vset_lane_f32(VWBU_ASTM(v), m, V2_K0);
    return  WBU_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u8(
                vtbl1_u8(
                    vreinterpret_u8_f32(m),
                    vdup_n_u8(3&k)
                )
            ),
            V2_K0
        )
    );
}

INLINE(Vwbu,VDBU_DUPW) (Vdbu v, Rc(0, 7) k)
{
#define     DBU_DUPW(M, K)      \
vget_lane_f32(                  \
    vreinterpret_f32_u8(        \
        vdup_lane_u8(M, 7&(K))  \
    ),                          \
    V2_K0                       \
)

#define     VDBU_DUPW(V, K) WBU_ASTV(DBU_DUPW(V, K))
    return  WBU_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u8(
                vtbl1_u8(v, vdup_n_u8(7&k))
            ),
            V2_K0
        )
    );
}

INLINE(Vwbu,VQBU_DUPW) (Vqbu v, Rc(0, 15) k)
{
#define     QBU_DUPW(M, K)      \
vget_lane_f32(                  \
    vreinterpret_f32_u8(        \
        vdup_laneq_u8(M, 15&(K))\
    ),                          \
    V2_K0                       \
)

#define     VQBU_DUPW(V, K) WBU_ASTV(QBU_DUPW(V, K))
    return WBU_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u8(
                vqtbl1_u8(v, vdup_n_u8(15&k))
            ),
            V2_K0
        )
    );
}


INLINE(Vwbi,SCHAR_DUPW) (signed char x)
{
#define     SCHAR_DUPW(X)   \
WBI_ASTV(                   \
    vget_lane_f32(          \
        vreinterpret_f32_s8(\
            vdup_n_s8(X)    \
        ),                  \
        V2_K0               \
    )                       \
)
    return  SCHAR_DUPW(x);
}

INLINE(Vwbi,VWBI_DUPW) (Vwbi v, Rc(0, 3) k)
{
#define     WBI_DUPW(M, K)          \
vget_lane_f32(                      \
    vreinterpret_f32_s8(            \
        vdup_lane_s8(               \
            vreinterpret_s8_f32(    \
                vdup_n_f32(M)       \
            ),                      \
            3&(K)                   \
        )                           \
    ),                              \
    V2_K0                           \
)

#define     VWBI_DUPW(V, K) WBI_ASTV(WBI_DUPW(VWBI_ASTM(V), K))
    float32x2_t m = vset_lane_f32(VWBI_ASTM(v), m, V2_K0);
    return  WBI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_s8(
                vtbl1_s8(
                    vreinterpret_s8_f32(m),
                    vdup_n_u8(3&k)
                )
            ),
            V2_K0
        )
    );
}

INLINE(Vwbi,VDBI_DUPW) (Vdbi v, Rc(0, 7) k)
{
#define     DBI_DUPW(M, K)      \
vget_lane_f32(                  \
    vreinterpret_f32_s8(        \
        vdup_lane_s8(M, 7&(K))  \
    ),                          \
    V2_K0                       \
)

#define     VDBI_DUPW(V, K) WBI_ASTV(DBI_DUPW(V,K))
    return WBI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_s8(
                vtbl1_s8(v, vdup_n_u8(7&k))
            ),
            V2_K0
        )
    );
}

INLINE(Vwbi,VQBI_DUPW) (Vqbi v, Rc(0, 15) k)
{
#define     QBI_DUPW(M, K)      \
vget_lane_f32(                  \
    vreinterpret_f32_s8(        \
        vdup_laneq_s8(M, 15&(K))\
    ),                          \
    V2_K0                       \
)

#define     VQBI_DUPW(V, K) WBI_ASTV(QBI_DUPW(V,K))
    return WBI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_s8(
                vqtbl1_s8(v, vdup_n_u8(15&k))
            ),
            V2_K0
        )
    );
}


INLINE(Vwbc,CHAR_DUPW) (char x)
{
#   define  CHAR_DUPW   CHAR_DUPW
    return  WBC_ASTV(
        vget_lane_f32(
#if CHAR_MIN
            vreinterpret_f32_s8(vdup_n_s8(x)),
#else
            vreinterpret_f32_s8(vdup_n_u8(x)),
#endif
            V2_K0
        )
    );
}

INLINE(Vwbc,VWBC_DUPW) (Vwbc v, Rc(0,  3) k)
{
    float32x2_t m = vset_lane_f32(VWBC_ASTM(v), m, V2_K0);
    uint8x8_t   t = vdup_n_u8(3&k);
    return  WBC_ASTV(
        vget_lane_f32(
#if CHAR_MIN
#   define  WBC_DUPW(X, K)  WBI_DUPW(X,K)  
            vreinterpret_f32_s8(
                vtbl1_s8(vreinterpret_s8_f32(m), t)
            ),
#else
#   define  WBC_DUPW(X, K)  WBU_DUPW(X,K)
            vreinterpret_f32_u8(
                vtbl1_u8(vreinterpret_u8_f32(m), t)
            ),
#endif
            V2_K0
        )
    );
}

INLINE(Vwbc,VDBC_DUPW) (Vdbc v, Rc(0,  7) k)
{
#define     VDBC_DUPW(V, K) WBC_ASTV(DBC_DUPW(VDBC_ASTM(V), K))
    Dbc m = VDBC_ASTM(v);
    return   WBC_ASTV(
        vget_lane_f32(
#if CHAR_MIN
#   define  DBC_DUPW(M, K)  DBI_DUPW(M, K)
            vreinterpret_f32_s8(
                vtbl1_s8(m, vdup_n_u8(7&k))
            ),
#else
#   define  DBC_DUPW(M, K)  DBU_DUPW(M, K)
            vreinterpret_f32_u8(
                vtbl1_u8(m, vdup_n_u8(7&k))
            ),
#endif
            V2_K0
        )
    );
}

INLINE(Vwbc,VQBC_DUPW) (Vqbc v, Rc(0, 15) k)
{
    Qbc m = VQBC_ASTM(v);
    return   WBC_ASTV(
        vget_lane_f32(
#if CHAR_MIN
#   define  QBC_DUPW(M, K)  QBI_DUPW(M,K)
            vreinterpret_f32_s8(
                vqtbl1_s8(m, vdupq_n_u8(15&k))
            ),
#else
#   define  QBC_DUPW(M, K)  QBU_DUPW(M,K)
            vreinterpret_f32_s8(
                vqtbl1_u8(m, vdup_n_u8(15&k))
            ),
#endif
            V2_K0
        )
    );
#define     VQBC_DUPW(V, K) WBC_ASTV(QBC_DUPW(VQBC_ASTM(V),K))
}


INLINE(Vwhu,USHRT_DUPW) (unsigned short x)
{
#define     USHRT_DUPW(X)       \
WHU_ASTV(                       \
    vget_lane_f32(              \
        vreinterpret_f32_u16(   \
            vdup_n_u16(X)       \
        ),                      \
        V2_K0                   \
    )                           \
)
    return  USHRT_DUPW(x);
}

INLINE(Vwhu,VWHU_DUPW) (Vwhu v, Rc(0, 1) k)
{
/*  TODO:
    Runtime variant won't work in big endian mode and
    testing needs to be done to confirm zip-shuffling is 
    faster than shift-and-dupping
*/
#define     WHU_DUPW(M, K)          \
vget_lane_f32(                      \
    vreinterpret_f32_u16(           \
        vdup_lane_u16(              \
            vreinterpret_u16_f32(   \
                vdup_n_f32(M)       \
            ),                      \
            3&(K)                   \
        )                           \
    ),                              \
    V2_K0                           \
)

#define     VWHU_DUPW(V, K)     WHU_ASTV(WHU_DUPW(VWHU_ASTM(V),K))
    float32x2_t m = vset_lane_f32(VWHU_ASTM(v), m, V2_K0);
    uint8x8_t   t = vzip1_u8(vdup_n_u8(k*2), vdup_n_u8(k*2+1));
    t = vtbl1_u8(vreinterpret_u8_f32(m), t);
    return  WHU_ASTV(vget_lane_f32(vreinterpret_f32_u8(t), V2_K0));
}

INLINE(Vwhu,VDHU_DUPW) (Vdhu v, Rc(0, 3) k)
{
#define     DHU_DUPW(M, K)      \
vget_lane_f32(                  \
    vreinterpret_f32_u16(       \
        vdup_lane_u16(M, 3&(K)) \
    ),                          \
    V2_K0                       \
)
#define     VDHU_DUPW(V, K) WHU_ASTV(DHU_DUPW(V,K))
    uint8x8_t   m = vreinterpret_u8_u16(v);
    uint8x8_t   t = vzip1_u8(vdup_n_u8(k*2), vdup_n_u8(k*2+1));
    t = vtbl1_u8(m, t);
    return  WHU_ASTV(
        vget_lane_f32(vreinterpret_f32_u8(t), V2_K0)
    );
}

INLINE(Vwhu,VQHU_DUPW) (Vqhu v, Rc(0, 7) k)
{
#define     QHU_DUPW(M, K)      \
vget_lane_f32(                  \
    vreinterpret_f32_u16(       \
        vdup_laneq_u16(M, 7&(K))\
    ),                          \
    V2_K0                       \
)
/*
    l = {4,4,4,4, 4,4,4,4}
    r = {5,5,5,5, 5,5,5,5}
    t = {4,5,4,5, 4,5,4,5}
    t = {m[4], m[5], m[4], m[5], ...}
*/
#define     VQHU_DUPW(V, K) WHU_ASTV(QHU_DUPW(V,K))
    uint8x8_t   l = vdup_n_u8(2*k);
    uint8x8_t   r = vdup_n_u8(2*k+1);
    uint8x8_t   t = vzip1_u8(l, r);
    t = vqtbl1_u8(vreinterpretq_u8_u16(v), t);
    return  WHU_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u8(t),
            V2_K0
        )
    );
}


INLINE(Vwhi,SHRT_DUPW) (short x)
{
#define     SHRT_DUPW(X)        \
WHI_ASTV(                       \
    vget_lane_f32(              \
        vreinterpret_f32_s16(   \
            vdup_n_s16(X)       \
        ),                      \
        V2_K0                   \
    )                           \
)
    return  SHRT_DUPW(x);
}

INLINE(Vwhi,VWHI_DUPW) (Vwhi v, Rc(0, 1) k)
{
#define     WHI_DUPW(M, K)          \
vget_lane_f32(                      \
    vreinterpret_f32_s16(           \
        vdup_lane_s16(              \
            vreinterpret_s16_f32(   \
                vdup_n_f32(M)       \
            ),                      \
            3&(K)                   \
        )                           \
    ),                              \
    V2_K0                           \
)

#define     VWHI_DUPW(V, K)     WHI_ASTV(WHI_DUPW(VWHI_ASTM(V),K))
    float32x2_t m = vset_lane_f32(VWHI_ASTM(v), m, V2_K0);
    uint8x8_t   t = vzip1_u8(
        vdup_n_u8(2*k), 
        vdup_n_u8(2*k+1)
    );
    t = vtbl1_u8(vreinterpret_u8_f32(m), t);
    return  WHI_ASTV(
        vget_lane_f32(vreinterpret_f32_u8(t), V2_K0)
    );
}

INLINE(Vwhi,VDHI_DUPW) (Vdhi v, Rc(0, 3) k)
{
#define     DHI_DUPW(M, K)      \
vget_lane_f32(                  \
    vreinterpret_f32_s16(       \
        vdup_lane_s16(M, 3&(K)) \
    ),                          \
    V2_K0                       \
)
#define     VDHI_DUPW(V, K) WHI_ASTV(DHI_DUPW(V,K))
    uint8x8_t   m = vreinterpret_u8_s16(v);
    uint8x8_t   t = vzip1_u8(
        vdup_n_u8(2*k), 
        vdup_n_u8(2*k+1)
    );
    t = vtbl1_u8(m, t);
    return  WHI_ASTV(
        vget_lane_f32(vreinterpret_f32_u8(t), V2_K0)
    );
}

INLINE(Vwhi,VQHI_DUPW) (Vqhi v, Rc(0, 7) k)
{
#define     QHI_DUPW(M, K)      \
vget_lane_f32(                  \
    vreinterpret_f32_s16(       \
        vdup_laneq_s16(M, 7&(K))\
    ),                          \
    V2_K0                       \
)
#define     VQHI_DUPW(V, K) WHI_ASTV(QHI_DUPW(V,K))
    uint8x8_t   l = vdup_n_u8(2*k);
    uint8x8_t   r = vdup_n_u8(2*k+1);
    uint8x8_t   t = vzip1_u8(l, r);
    t = vqtbl1_u8(vreinterpretq_u8_s16(v), t);
    return WHI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u8(t),
            V2_K0
        )
    );
}


INLINE(Vwhf,FLT16_DUPW) (flt16_t x)
{
#define     FLT16_DUPW(X)       \
WHF_ASTV(                       \
    vget_lane_f32(              \
        vreinterpret_f32_f16(   \
            vdup_n_f16(X)       \
        ),                      \
        V2_K0                   \
    )                           \
)
    return  FLT16_DUPW(x);
}

INLINE(Vwhf,VWHF_DUPW) (Vwhf v, Rc(0, 1) k)
{
#define     WHF_DUPW(M, K)          \
vget_lane_f32(                      \
    vreinterpret_f32_f16(           \
        vdup_lane_f16(              \
            vreinterpret_f16_f32(   \
                vdup_n_f32(M)       \
            ),                      \
            3&(K)                   \
        )                           \
    ),                              \
    V2_K0                           \
)

#define     VWHF_DUPW(V, K)     WHF_ASTV(WHF_DUPW(VWHF_ASTM(V),K))
    float32x2_t m = vset_lane_f32(VWHF_ASTM(v), m, V2_K0);
    uint8x8_t   t = vzip1_u8(
        vdup_n_u8(2*k), 
        vdup_n_u8(2*k+1)
    );
    t = vtbl1_u8(vreinterpret_u8_f32(m), t);
    return  WHF_ASTV(
        vget_lane_f32(vreinterpret_f32_u8(t), V2_K0)
    );
}

INLINE(Vwhf,VDHF_DUPW) (Vdhf v, Rc(0, 3) k)
{
#define     DHF_DUPW(M, K)      \
vget_lane_f32(                  \
    vreinterpret_f32_f16(       \
        vdup_lane_f16(M, 3&(K)) \
    ),                          \
    V2_K0                       \
)
#define     VDHF_DUPW(V, K) WHF_ASTV(DHF_DUPW(V,K))
    uint8x8_t   m = vreinterpret_u8_f16(v);
    uint8x8_t   t = vzip1_u8(
        vdup_n_u8(2*k), 
        vdup_n_u8(2*k+1)
    );
    t = vtbl1_u8(m, t);
    return  WHF_ASTV(
        vget_lane_f32(vreinterpret_f32_u8(t), V2_K0)
    );
}

INLINE(Vwhf,VQHF_DUPW) (Vqhf v, Rc(0, 7) k)
{
#define     QHF_DUPW(M, K)      \
vget_lane_f32(                  \
    vreinterpret_f32_f16(       \
        vdup_laneq_f16(M, 7&(K))\
    ),                          \
    V2_K0                       \
)
#define     VQHF_DUPW(V, K) WHF_ASTV(QHF_DUPW(V,K))
    uint8x8_t   l = vdup_n_u8(2*k);
    uint8x8_t   r = vdup_n_u8(2*k+1);
    uint8x8_t   t = vzip1_u8(l, r);
    t = vqtbl1_u8(vreinterpretq_u8_f16(v), t);
    return WHF_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u8(t),
            V2_K0
        )
    );
}




#if _LEAVE_EXTGOP_ARM_DUPW
}
#endif

#if _ENTER_EXTGOP_ARM_DUPD
{
#endif

INLINE(Vdyu,BOOL_DUPD) (_Bool x)
{
#define     BOOL_DUPD   BOOL_DUPD 
    return  DYU_ASTV(vdup_n_u64(0ull-x));
}

INLINE(Vdyu,VWYU_DUPD) (Vwyu v, Rc(0, 31) k)
{
#define     WYU_DUPD(M, K)          \
vdup_n_u64(                         \
    vtstd_u64(                      \
        UINT64_C(1)<<(K),           \
        vget_lane_u32(              \
            vreinterpret_u32_f32(   \
                vdup_n_f32(M)       \
            ),                      \
            V2_K0                   \
        )                           \
    )                               \
)

#define     VWYU_DUPD(V, K) DYU_ASTV(WYU_DUPD(VWYU_ASTM(V), K))
    return  VWYU_DUPD(v, k);
}

INLINE(Vdyu,VDYU_DUPD) (Vdyu v, Rc(0, 63) k)
{
#define     DYU_DUPD(M, K)  \
vdup_n_u64(                 \
    vtstd_u64(              \
        UINT64_C(1)<<(K),   \
        vget_lane_u64(      \
            M,              \
            V2_K0           \
        )                   \
    )                       \
)

#define     VDYU_DUPD(V, K) DYU_ASTV(DYU_DUPD(VDYU_ASTM(V), K))
    return  VDYU_DUPD(v, k);
}

INLINE(Vdyu,VQYU_DUPD) (Vqyu v, Rc(0,127) k)
{
#define     VQYU_DUPD   VQYU_DUPD
    uint64x2_t  q = VQYU_ASTM(v);
    uint64_t    d;
    if (k > 63) {
        d = vget_lane_u64(vget_high_u64(q), 0);
        d = vtstd_u64(d, UINT64_C(1)<<(k-64));
    }
    else {
        d = vget_lane_u64(vget_low_u64(q), 0);
        d = vtstd_u64(d, UINT64_C(1)<<k);
    }
    return DYU_ASTV(vdup_n_u64(d));
}


INLINE(Vdbu,UCHAR_DUPD) (unsigned char x)
{
#define     UCHAR_DUPD      vdup_n_u8
    return  UCHAR_DUPD(x);
}

INLINE(Vdbu,VWBU_DUPD) (Vwbu v, Rc(0,  3) k)
{
#define     WBU_DUPD(M, K) \
vdup_lane_u8(vreinterpret_u8_f32(vdup_n_f32(M)), K)

#define     VWBU_DUPD(V, K) WBU_DUPD(VWBU_ASTM(V), K)
    return  vtbl1_u8(
        vreinterpret_u8_f32(vdup_n_f32(VWBU_ASTM(v))),
        vdup_n_u8(k)
    );
}

INLINE(Vdbu,VDBU_DUPD) (Vdbu v, Rc(0,  7) k)
{
#define     DBU_DUPD            vdup_lane_u8
#define     VDBU_DUPD(V, K)     DBU_DUPD(V, K)
    return  vtbl1_u8(v, vdup_n_u8(k));
}

INLINE(Vdbu,VQBU_DUPD) (Vqbu v, Rc(0, 15) k)
{
#define     QBU_DUPD            vdup_laneq_u8
#define     VQBU_DUPD(V, K)     QBU_DUPD(V, K)
    return  vqtbl1_u8(v, vdup_n_u8(k));
}


INLINE(Vdbi,SCHAR_DUPD) (signed char x)
{
#define     SCHAR_DUPD      vdup_n_s8
    return  SCHAR_DUPD(x);
}

INLINE(Vdbi,VWBI_DUPD) (Vwbi v, Rc(0,  3) k)
{
#define     WBI_DUPD(M, K) \
vdup_lane_s8(vreinterpret_s8_f32(vdup_n_f32(M)), K)

#define     VWBI_DUPD(V, K) WBI_DUPD(VWBI_ASTM(V), K)
    return  vtbl1_s8(
        vreinterpret_s8_f32(vdup_n_f32(VWBI_ASTM(v))),
        vdup_n_u8(k)
    );
}

INLINE(Vdbi,VDBI_DUPD) (Vdbi v, Rc(0,  7) k)
{
#define     DBI_DUPD            vdup_lane_s8
#define     VDBI_DUPD(V, K)     DBI_DUPD(V, K)
    return  vtbl1_s8(v, vdup_n_s8(k));
}

INLINE(Vdbi,VQBI_DUPD) (Vqbi v, Rc(0, 15) k)
{
#define     QBU_DUPD            vdup_laneq_u8
#define     VQBU_DUPD(V, K)     QBU_DUPD(V, K)
    return  vqtbl1_u8(v, vdup_n_u8(k));
}


INLINE(Vdbc, CHAR_DUPD) (char x)
{
#if CHAR_MIN
#   define  CHAR_DUPD(X) DBC_ASTV(vdup_n_s8(X))
#else
#   define  CHAR_DUPD(X) DBC_ASTV(vdup_n_u8(X))
#endif
    return  CHAR_DUPD(x);
}

INLINE(Vdbc,VWBC_DUPD) (Vwbc v, Rc(0,  3) k)
{
#define     VWBC_DUPD(V, K) DBC_ASTV(WBU_DUPD(VWBC_ASTM(V), K))
    return  VDBU_ASBC((VWBU_DUPD)(VWBC_ASBU(v), k));
}

INLINE(Vdbc,VDBC_DUPD) (Vdbc v, Rc(0,  7) k)
{
#define     VDBC_DUPD(V, K) VDBU_ASBC(DBU_DUPD(VDBC_ASBU(V), K))
    return VDBU_ASBC((VDBU_DUPD)(VDBC_ASBU(v), k));
}

INLINE(Vdbc,VQBC_DUPD) (Vqbc v, Rc(0, 15) k)
{
#define     VQBC_DUPD(V, K) VDBU_ASBC(QBU_DUPD(VQBC_ASBU(V), K))
    return VDBU_ASBC((VQBU_DUPD)(VQBC_ASBU(v), k));
}


INLINE(Vdhu, USHRT_DUPD) (unsigned short x)
{
#define     USHRT_DUPD(X)   vdup_n_u16(X)
    return  USHRT_DUPD(x);
}

INLINE(Vdhu,VWHU_DUPD) (Vwhu x, Rc(0, 1) k)
{
#define     WHU_DUPD(M, K)  \
vdup_lane_u16(              \
    vreinterpret_u16_f32(   \
        vdup_n_f32(M)       \
    ),                      \
    1&(K)                   \
)

#define     VWHU_DUPD(V, K) WHU_DUPD(VWHU_ASTM(V), K)
    return vreinterpret_u16_u8(
        vtbl1_u8(
            vreinterpret_u8_f32(vdup_n_f32(VWHU_ASTM(x))),
            vzip1_u8(
                vdup_n_u8(2*k),
                vdup_n_u8(2*k+1)
            )
        )
    );
}

INLINE(Vdhu,VDHU_DUPD) (Vdhu x, Rc(0, 3) k)
{
#define     DHU_DUPD        vdup_lane_u16
#define     VDHU_DUPD(V, K) DHU_DUPD(V, K)
    return vreinterpret_u16_u8(
        vtbl1_u8(
            vreinterpret_u8_u16(x),
            vzip1_u8(
                vdup_n_u8(2*k),
                vdup_n_u8(2*k+1)
            )
        )
    );
}

INLINE(Vdhu,VQHU_DUPD) (Vqhu x, Rc(0, 7) k)
{
#define     QHU_DUPD        vdup_laneq_u16
#define     VQHU_DUPD(V, K) QHU_DUPD(V, K)
    return vreinterpret_u16_u8(
        vqtbl1_u8(
            vreinterpretq_u8_u16(x),
            vzip1_u8(
                vdup_n_u8(2*k),
                vdup_n_u8(2*k+1)
            )
        )
    );
}


INLINE(Vdhi,  SHRT_DUPD) (short x)
{
#define     SHRT_DUPD(X)    vdup_n_s16(X)
    return  SHRT_DUPD(x);
}

INLINE(Vdhi,VWHI_DUPD) (Vwhi x, Rc(0, 1) k)
{
#define     WHI_DUPD(M, K)  \
vdup_lane_s16(vreinterpret_s16_f32(vdup_n_f32(M)),1&(K))

#define     VWHI_DUPD(V, K) WHI_DUPD(VWHI_ASTM(V), K)
    return vreinterpret_s16_u8(
        vtbl1_u8(
            vreinterpret_u8_f32(vdup_n_f32(VWHI_ASTM(x))),
            vzip1_u8(
                vdup_n_u8(2*k),
                vdup_n_u8(2*k+1)
            )
        )
    );
}

INLINE(Vdhi,VDHI_DUPD) (Vdhi x, Rc(0, 3) k)
{
#define     DHI_DUPD        vdup_lane_s16
#define     VDHI_DUPD(V, K) DHI_DUPD(V, K)
    return vreinterpret_s16_u8(
        vtbl1_u8(
            vreinterpret_u8_s16(x),
            vzip1_u8(
                vdup_n_u8(2*k),
                vdup_n_u8(2*k+1)
            )
        )
    );
}

INLINE(Vdhi,VQHI_DUPD) (Vqhi x, Rc(0, 7) k)
{
#define     QHI_DUPD        vdup_laneq_s16
#define     VQHI_DUPD(V, K) QHI_DUPD(V, K)
    return  vreinterpret_s16_u8(
        vqtbl1_u8(
            vreinterpretq_u8_s16(x),
            vzip1_u8(
                vdup_n_u8(2*k),
                vdup_n_u8(2*k+1)
            )
        )
    );
}


INLINE(Vdhf, FLT16_DUPD) (flt16_t x)
{
#define     FLT16_DUPD(X)   vdup_n_f16(X)
    return  FLT16_DUPD(x);
}

INLINE(Vdhf,VWHF_DUPD) (Vwhf x, Rc(0, 1) k)
{
#define     WHF_DUPD(M, K)  \
vdup_lane_f16(vreinterpret_f16_f32(vdup_n_f32(M)),1&(K))

#define     VWHF_DUPD(V, K) WHF_DUPD(VWHF_ASTM(V), K)
    return vreinterpret_f16_u8(
        vtbl1_u8(
            vreinterpret_u8_f32(vdup_n_f32(VWHF_ASTM(x))),
            vzip1_u8(
                vdup_n_u8(2*k),
                vdup_n_u8(2*k+1)
            )
        )
    );
}

INLINE(Vdhf,VDHF_DUPD) (Vdhf x, Rc(0, 3) k)
{
#define     DHF_DUPD        vdup_lane_f16
#define     VDHF_DUPD(V, K) DHF_DUPD(V, K)
    return vreinterpret_f16_u8(
        vtbl1_u8(
            vreinterpret_u8_f16(x),
            vzip1_u8(
                vdup_n_u8(2*k),
                vdup_n_u8(2*k+1)
            )
        )
    );
}

INLINE(Vdhf,VQHF_DUPD) (Vqhf x, Rc(0, 7) k)
{
#define     QHF_DUPD        vdup_laneq_f16
#define     VQHF_DUPD(V, K) QHF_DUPD(V, K)
    return  vreinterpret_f16_u8(
        vqtbl1_u8(
            vreinterpretq_u8_f16(x),
            vzip1_u8(
                vdup_n_u8(2*k),
                vdup_n_u8(2*k+1)
            )
        )
    );
}


INLINE(Vdwu, UINT_DUPD) (unsigned int x)
{
#define     UINT_DUPD(X)    vdup_n_u32(X)
    return  UINT_DUPD(x);
}

INLINE(Vdwu,VWWU_DUPD) (Vwwu v, int const k)
{
#define     WWU_DUPD(M, K)  vreinterpret_u32_f32(vdup_n_f32(M))
#define     VWWU_DUPD(V, K) WWU_DUPD(VWWU_ASTM(V), K)
    return  VWWU_DUPD(v, k);
}

INLINE(Vdwu,VDWU_DUPD) (Vdwu v, Rc(0, 1) k)
{
#define     DWU_DUPD        vdup_lane_u32
#define     VDWU_DUPD(V, K) DWU_DUPD(V, K)
    uint64x1_t m = vreinterpret_u64_u32(v);
    m = vshl_u64(m, vdup_n_s64(0-32*k));
    return  vdup_lane_u32(
        vreinterpret_u32_u64(m),
        V2_K0
    );
}

INLINE(Vdwu,VQWU_DUPD) (Vqwu v, Rc(0, 3) k)
{
#define     QWU_DUPD        vdup_laneq_u32
#define     VQWU_DUPD(V, K) QWU_DUPD(V, K)
    uint64x1_t  m;
    if (k > 1) {
        m = vshl_u64(
            vget_high_u64(vreinterpretq_u64_u32(v)),
            vdup_n_s64(0-(k-2)*32)
        );
    }
    else {
        m = vshl_u64(
            vget_low_u64(vreinterpretq_u64_u32(v)),
            vdup_n_s64(0-k*32)
        );
    }
    return  vdup_lane_u32(
        vreinterpret_u32_u64(m), 
        V2_K0
    );
}


INLINE(Vdwi, INT_DUPD) (int x)
{
#define     INT_DUPD(X)    vdup_n_s32(X)
    return  INT_DUPD(x);
}

INLINE(Vdwi,VWWI_DUPD) (Vwwi v, int const k)
{
#define     WWI_DUPD(M, K)  vreinterpret_s32_f32(vdup_n_f32(M))
#define     VWWI_DUPD(V, K) WWI_DUPD(VWWI_ASTM(V), K)
    return  VWWI_DUPD(v, k);
}

INLINE(Vdwi,VDWI_DUPD) (Vdwi v, Rc(0, 1) k)
{
#define     DWI_DUPD        vdup_lane_s32
#define     VDWI_DUPD(V, K) DWI_DUPD(V, K)
    uint64x1_t m = vreinterpret_u64_s32(v);
    m = vshl_u64(m, vdup_n_s64(0-32*k));
    return  vdup_lane_s32(
        vreinterpret_s32_u64(m),
        V2_K0
    );
}

INLINE(Vdwi,VQWI_DUPD) (Vqwi v, Rc(0, 3) k)
{
#define     QWI_DUPD        vdup_laneq_s32(V, K)
#define     VQWI_DUPD(V, K) QWI_DUPD(V, K)
    uint64x1_t  m;
    if (k > 1) {
        m = vshl_u64(
            vget_high_u64(vreinterpretq_u64_s32(v)),
            vdup_n_s64(0-(k-2)*32)
        );
    }
    else {
        m = vshl_u64(
            vget_low_u64(vreinterpretq_u64_s32(v)),
            vdup_n_s64(0-k*32)
        );
    }
    return  vdup_lane_s32(
        vreinterpret_s32_u64(m),
        V2_K0
    );
}


INLINE(Vdwf, FLT_DUPD) (float x)
{
#define     FLT_DUPD(X)    vdup_n_f32(X)
    return  FLT_DUPD(x);
}

INLINE(Vdwf,VWWF_DUPD) (Vwwf v, int const k)
{
#define     WWF_DUPD        vdup_n_f32
#define     VWWF_DUPD(V, K) WWF_DUPD(VWWF_ASTM(V))
    return  VWWF_DUPD(v, k);
}

INLINE(Vdwf,VDWF_DUPD) (Vdwf v, Rc(0, 1) k)
{
#define     DWF_DUPD        vdup_lane_f32
#define     VDWF_DUPD(V, K) DWF_DUPD(V, K)
    uint64x1_t m = vreinterpret_u64_f32(v);
    m = vshl_u64(m, vdup_n_s64(0-32*k));
    return  vdup_lane_f32(
        vreinterpret_f32_u64(m),
        V2_K0
    );
}

INLINE(Vdwf,VQWF_DUPD) (Vqwf v, Rc(0, 3) k)
{
#define     QWF_DUPD        vdup_laneq_f32(V, K)
#define     VQWF_DUPD(V, K) QWF_DUPD(V, K)
    uint64x2_t  q = vreinterpretq_u64_f32(v);
    uint64x1_t  m;
    if (k > 1)  m = vshl_u64(vget_high_u64(q), vdup_n_s64(0-(k-2)*32));
    else        m = vshl_u64(vget_low_u64( q), vdup_n_s64(0-(k  )*32));
    return  vdup_lane_f32(vreinterpret_f32_u64(m), V2_K0);
}

#if _LEAVE_EXTGOP_ARM_DUPD
}
#endif


#if _ENTER_EXTGOP_ARM_DUPQ
{
#endif

#define     QYU_DUPQ(X)     vdupq_n_u64(0ull-(_Bool)(X))
#define     QBU_DUPQ(X)     vdupq_n_u8(X)
#define     QBI_DUPQ(X)     vdupq_n_s8(X)
#if CHAR_MIN
#   define  QBC_DUPQ(X)     vdupq_n_s8(X)
#else
#   define  QBC_DUPQ(X)     vdupq_n_u8(X)
#endif

#define     QHU_DUPQ(X)     vdupq_n_u16(X)
#define     QHI_DUPQ(X)     vdupq_n_s16(X)
#define     QHF_DUPQ(X)     vdupq_n_f16(X)

#define     QWU_DUPQ(X)     vdupq_n_u32(X)
#define     QWI_DUPQ(X)     vdupq_n_s32(X)
#define     QWF_DUPQ(X)     vdupq_n_f32(X)

#define     QDU_DUPQ(X)     vdupq_n_u64(X)
#define     QDI_DUPQ(X)     vdupq_n_s64(X)
#define     QDF_DUPQ(X)     vdupq_n_f64(X)


INLINE(Vqyu,VQYU_DUPQ) (_Bool x)
{
#define     VQYU_DUPQ(X)    QYU_ASTV(QYU_DUPQ(X))
    return  VQYU_DUPQ(x);
}


INLINE(Vqbu,VQBU_DUPQ) (uint8_t x)
{
#define     VQBU_DUPQ       QBU_DUPQ
    return  VQBU_DUPQ(x);
}

INLINE(Vqbi,VQBI_DUPQ) (int8_t x)
{
#define     VQBI_DUPQ       QBI_DUPQ
    return  VQBI_DUPQ(x);
}

INLINE(Vqbc,VQBC_DUPQ) (char x)
{
#define     VQBC_DUPQ(X)    QBC_ASTV(QBC_DUPQ(X))
    return  VQBC_DUPQ(x);
}


INLINE(Vqhu,VQHU_DUPQ) (uint16_t x)
{
#define     VQHU_DUPQ       QHU_DUPQ
    return  VQHU_DUPQ(x);
}

INLINE(Vqhi,VQHI_DUPQ) (int16_t x)
{
#define     VQHI_DUPQ       QHI_DUPQ
    return  VQHI_DUPQ(x);
}

INLINE(Vqhf,VQHF_DUPQ) (flt16_t x)
{
#define     VQHF_DUPQ       QHF_DUPQ
    return  VQHF_DUPQ(x);
}


INLINE(Vqwu,VQWU_DUPQ) (uint32_t x)
{
#define     VQWU_DUPQ       QWU_DUPQ
    return  VQWU_DUPQ(x);
}

INLINE(Vqwi,VQWI_DUPQ) (int32_t x)
{
#define     VQWI_DUPQ       QWI_DUPQ
    return  VQWI_DUPQ(x);
}

INLINE(Vqwf,VQWF_DUPQ) (float x)
{
#define     VQWF_DUPQ       QWF_DUPQ
    return  VQWF_DUPQ(x);
}

INLINE(Vqdu,VQDU_DUPQ) (uint64_t x)
{
#define     VQDU_DUPQ       QDU_DUPQ
    return  VQDU_DUPQ(x);
}

INLINE(Vqdi,VQDI_DUPQ) (int64_t x)
{
#define     VQDI_DUPQ       QDI_DUPQ
    return  VQDI_DUPQ(x);
}

INLINE(Vqdf,VQDF_DUPQ) (double x)
{
#define     VQDF_DUPQ       QDF_DUPQ
    return  VQDF_DUPQ(x);
}

#if _LEAVE_EXTGOP_ARM_DUPQ
}
#endif


#if _LEAVE_EXTGOP_ARM_DUP_
}
#endif



#if _ENTER_EXTGOP_ARM_ZIP_
{
#endif

#if _ENTER_EXTGOP_ARM_ZIPL
{
#endif

INLINE(float, MY_ZIPLW) (float a, float b)
{
    float32x2_t c;
    c = vset_lane_f32(a, c, V2_K0);
    c = vset_lane_f32(b, c, V2_K1);
    return vget_lane_f32(vzip1_f32(c, c), V2_K0);
}

//efine     WYU_ZIPL
#define     WBU_ZIPL    MY_ZIPLW
#define     WBI_ZIPL    MY_ZIPLW
#define     WBC_ZIPL    MY_ZIPLW
#define     WHU_ZIPL    MY_ZIPLW
#define     WHI_ZIPL    MY_ZIPLW
#define     WHF_ZIPL    MY_ZIPLW
//efine     WWU_ZIPL
//efine     WWI_ZIPL
//efine     WWF_ZIPL

#define     DBU_ZIPL    vzip1_u8
#define     DBI_ZIPL    vzip1_s8
#if CHAR_MIN
#   define  DBC_ZIPL    vzip1_s8
#else
#   define  DBC_ZIPL    vzip1_u8
#endif

#define     DHU_ZIPL    vzip1_u16
#define     DHI_ZIPL    vzip1_s16
#if defined(SPC_ARM_FP16_SIMD)
#   define  DHF_ZIPL    vzip1_f16
#else
#   define  DHF_ZIPL(A, B)      \
vreinterpret_f16_u16(           \
    vzip1_u16(                  \
        vreinterpret_u16_f16(A),\
        vreinterpret_u16_f16(A) \
    )                           \
)
#endif

#define     DWU_ZIPL    vzip1_u32
#define     DWI_ZIPL    vzip1_s32
#define     DWF_ZIPL    vzip1_f32
//efine     DDU_ZIPL
//efine     DDI_ZIPL
//efine     DDF_ZIPL


#define     QBU_ZIPL    vzip1q_u8
#define     QBI_ZIPL    vzip1q_s8
#if CHAR_MIN
#   define  QBC_ZIPL    vzip1q_s8
#else
#   define  QBC_ZIPL    vzip1q_u8
#endif

#define     QHU_ZIPL    vzip1q_u16
#define     QHI_ZIPL    vzip1q_s16

#if defined(SPC_ARM_FP16_SIMD)
#   define  QHF_ZIPL    vzip1q_f16
#else
#   define  QHF_ZIPL(A, B)          \
vreinterpretq_f16_u16(              \
    vzip1q_u16(                     \
        vreinterpretq_u16_f16(A),   \
        vreinterpretq_u16_f16(A)    \
    )                               \
)
#endif

#define     QWU_ZIPL    vzip1q_u32
#define     QWI_ZIPL    vzip1q_s32
#define     QWF_ZIPL    vzip1q_f32
#define     QDU_ZIPL    vzip1q_u64
#define     QDI_ZIPL    vzip1q_s64
#define     QDF_ZIPL    vzip1q_f64


INLINE(Vwbu,VWBU_ZIPL) (Vwbu a, Vwbu b)
{
#define     VWBU_ZIPL(A, B) WBU_ASTV(WBU_ZIPL(VWBU_ASTM(A), VWBU_ASTM(B)))
    return  VWBU_ZIPL(a, b);
}

INLINE(Vwbi,VWBI_ZIPL) (Vwbi a, Vwbi b)
{
#define     VWBI_ZIPL(A, B) WBI_ASTV(WBI_ZIPL(VWBI_ASTM(A), VWBI_ASTM(B)))
    return  VWBI_ZIPL(a, b);
}

INLINE(Vwbc,VWBC_ZIPL) (Vwbc a, Vwbc b)
{
#define     VWBC_ZIPL(A, B) WBC_ASTV(WBC_ZIPL(VWBC_ASTM(A), VWBC_ASTM(B)))
    return  VWBC_ZIPL(a, b);
}


INLINE(Vwhu,VWHU_ZIPL) (Vwhu a, Vwhu b)
{
#define     VWHU_ZIPL(A, B) WHU_ASTV(WHU_ZIPL(VWHU_ASTM(A), VWHU_ASTM(B)))
    return  VWHU_ZIPL(a, b);
}

INLINE(Vwhi,VWHI_ZIPL) (Vwhi a, Vwhi b)
{
#define     VWHI_ZIPL(A, B) WHI_ASTV(WHI_ZIPL(VWHI_ASTM(A), VWHI_ASTM(B)))
    return  VWHI_ZIPL(a, b);
}

INLINE(Vwhf,VWHF_ZIPL) (Vwhf a, Vwhf b)
{
#define     VWHF_ZIPL(A, B) WHF_ASTV(WHF_ZIPL(VWHF_ASTM(A), VWHF_ASTM(B)))
    return  VWHF_ZIPL(a, b);
}


INLINE(Vdbu,VDBU_ZIPL) (Vdbu a, Vdbu b)
{
#define     VDBU_ZIPL   DBU_ZIPL
    return  VDBU_ZIPL(a, b);
}

INLINE(Vdbi,VDBI_ZIPL) (Vdbi a, Vdbi b)
{
#define     VDBI_ZIPL   DBI_ZIPL
    return  VDBI_ZIPL(a, b);
}

INLINE(Vdbc,VDBC_ZIPL) (Vdbc a, Vdbc b)
{
#define     VDBC_ZIPL(A, B)  DBC_ASTV(DBC_ZIPL(VDBC_ASTM(A), VDBC_ASTM(B)))
    return  VDBC_ZIPL(a, b);
}


INLINE(Vdhu,VDHU_ZIPL) (Vdhu a, Vdhu b)
{
#define     VDHU_ZIPL   DHU_ZIPL
    return  VDHU_ZIPL(a, b);
}

INLINE(Vdhi,VDHI_ZIPL) (Vdhi a, Vdhi b)
{
#define     VDHI_ZIPL   DHI_ZIPL
    return  VDHI_ZIPL(a, b);
}

INLINE(Vdhf,VDHF_ZIPL) (Vdhf a, Vdhf b)
{
#define     VDHF_ZIPL   DHF_ZIPL
    return  VDHF_ZIPL(a, b);
}


INLINE(Vdwu,VDWU_ZIPL) (Vdwu a, Vdwu b)
{
#define     VDWU_ZIPL   DWU_ZIPL
    return  VDWU_ZIPL(a, b);
}

INLINE(Vdwi,VDWI_ZIPL) (Vdwi a, Vdwi b)
{
#define     VDWI_ZIPL   DWI_ZIPL
    return  VDWI_ZIPL(a, b);
}

INLINE(Vdwf,VDWF_ZIPL) (Vdwf a, Vdwf b)
{
#define     VDWF_ZIPL   DWF_ZIPL
    return  VDWF_ZIPL(a, b);
}


INLINE(Vqbu,VQBU_ZIPL) (Vqbu a, Vqbu b)
{
#define     VQBU_ZIPL   QBU_ZIPL
    return  VQBU_ZIPL(a, b);
}

INLINE(Vqbi,VQBI_ZIPL) (Vqbi a, Vqbi b)
{
#define     VQBI_ZIPL   QBI_ZIPL
    return  VQBI_ZIPL(a, b);
}

INLINE(Vqbc,VQBC_ZIPL) (Vqbc a, Vqbc b)
{
#define     VQBC_ZIPL(A, B)  QBC_ASTV(QBC_ZIPL(VQBC_ASTM(A), VQBC_ASTM(B)))
    return  VQBC_ZIPL(a, b);
}


INLINE(Vqhu,VQHU_ZIPL) (Vqhu a, Vqhu b)
{
#define     VQHU_ZIPL   QHU_ZIPL
    return  VQHU_ZIPL(a, b);
}

INLINE(Vqhi,VQHI_ZIPL) (Vqhi a, Vqhi b)
{
#define     VQHI_ZIPL   QHI_ZIPL
    return  VQHI_ZIPL(a, b);
}

INLINE(Vqhf,VQHF_ZIPL) (Vqhf a, Vqhf b)
{
#define     VQHF_ZIPL   QHF_ZIPL
    return  VQHF_ZIPL(a, b);
}


INLINE(Vqwu,VQWU_ZIPL) (Vqwu a, Vqwu b)
{
#define     VQWU_ZIPL   QWU_ZIPL
    return  VQWU_ZIPL(a, b);
}

INLINE(Vqwi,VQWI_ZIPL) (Vqwi a, Vqwi b)
{
#define     VQWI_ZIPL   QWI_ZIPL
    return  VQWI_ZIPL(a, b);
}

INLINE(Vqwf,VQWF_ZIPL) (Vqwf a, Vqwf b)
{
#define     VQWF_ZIPL   QWF_ZIPL
    return  VQWF_ZIPL(a, b);
}


INLINE(Vqdu,VQDU_ZIPL) (Vqdu a, Vqdu b)
{
#define     VQDU_ZIPL   QDU_ZIPL
    return  VQDU_ZIPL(a, b);
}

INLINE(Vqdi,VQDI_ZIPL) (Vqdi a, Vqdi b)
{
#define     VQDI_ZIPL   QDI_ZIPL
    return  VQDI_ZIPL(a, b);
}

INLINE(Vqdf,VQDF_ZIPL) (Vqdf a, Vqdf b)
{
#define     VQDF_ZIPL   QDF_ZIPL
    return  VQDF_ZIPL(a, b);
}

#if _LEAVE_EXTGOP_ARM_ZIPL
}
#endif

#if _ENTER_EXTGOP_ARM_ZIPR
{
#endif

INLINE(float, MY_ZIPRW) (float a, float b)
{
    float32x2_t c;
    c = vset_lane_f32(a, c, V2_K0);
    c = vset_lane_f32(b, c, V2_K1);
    return vget_lane_f32(vzip2_f32(c, c), V2_K0);
}

//efine     WYU_ZIPR
#define     WBU_ZIPR    MY_ZIPRW
#define     WBI_ZIPR    MY_ZIPRW
#define     WBC_ZIPR    MY_ZIPRW
#define     WHU_ZIPR    MY_ZIPRW
#define     WHI_ZIPR    MY_ZIPRW
#define     WHF_ZIPR    MY_ZIPRW
//efine     WWU_ZIPR
//efine     WWI_ZIPR
//efine     WWF_ZIPR

#define     DBU_ZIPR    vzip2_u8
#define     DBI_ZIPR    vzip2_s8
#if CHAR_MIN
#   define  DBC_ZIPR    vzip2_s8
#else
#   define  DBC_ZIPR    vzip2_u8
#endif

#define     DHU_ZIPR    vzip2_u16
#define     DHI_ZIPR    vzip2_s16
#if defined(SPC_ARM_FP16_SIMD)
#   define  DHF_ZIPR    vzip2_f16
#else
#   define  DHF_ZIPR(A, B)      \
vreinterpret_f16_u16(           \
    vzip2_u16(                  \
        vreinterpret_u16_f16(A),\
        vreinterpret_u16_f16(A) \
    )                           \
)
#endif

#define     DWU_ZIPR    vzip2_u32
#define     DWI_ZIPR    vzip2_s32
#define     DWF_ZIPR    vzip2_f32
//efine     DDU_ZIPR
//efine     DDI_ZIPR
//efine     DDF_ZIPR


#define     QBU_ZIPR    vzip2q_u8
#define     QBI_ZIPR    vzip2q_s8
#if CHAR_MIN
#   define  QBC_ZIPR    vzip2q_s8
#else
#   define  QBC_ZIPR    vzip2q_u8
#endif

#define     QHU_ZIPR    vzip2q_u16
#define     QHI_ZIPR    vzip2q_s16

#if defined(SPC_ARM_FP16_SIMD)
#   define  QHF_ZIPR    vzip2q_f16
#else
#   define  QHF_ZIPR(A, B)          \
vreinterpretq_f16_u16(              \
    vzip2q_u16(                     \
        vreinterpretq_u16_f16(A),   \
        vreinterpretq_u16_f16(A)    \
    )                               \
)
#endif

#define     QWU_ZIPR    vzip2q_u32
#define     QWI_ZIPR    vzip2q_s32
#define     QWF_ZIPR    vzip2q_f32
#define     QDU_ZIPR    vzip2q_u64
#define     QDI_ZIPR    vzip2q_s64
#define     QDF_ZIPR    vzip2q_f64


INLINE(Vwbu,VWBU_ZIPR) (Vwbu a, Vwbu b)
{
#define     VWBU_ZIPR(A, B) WBU_ASTV(WBU_ZIPR(VWBU_ASTM(A), VWBU_ASTM(B)))
    return  VWBU_ZIPR(a, b);
}

INLINE(Vwbi,VWBI_ZIPR) (Vwbi a, Vwbi b)
{
#define     VWBI_ZIPR(A, B) WBI_ASTV(WBI_ZIPR(VWBI_ASTM(A), VWBI_ASTM(B)))
    return  VWBI_ZIPR(a, b);
}

INLINE(Vwbc,VWBC_ZIPR) (Vwbc a, Vwbc b)
{
#define     VWBC_ZIPR(A, B) WBC_ASTV(WBC_ZIPR(VWBC_ASTM(A), VWBC_ASTM(B)))
    return  VWBC_ZIPR(a, b);
}


INLINE(Vwhu,VWHU_ZIPR) (Vwhu a, Vwhu b)
{
#define     VWHU_ZIPR(A, B) WHU_ASTV(WHU_ZIPR(VWHU_ASTM(A), VWHU_ASTM(B)))
    return  VWHU_ZIPR(a, b);
}

INLINE(Vwhi,VWHI_ZIPR) (Vwhi a, Vwhi b)
{
#define     VWHI_ZIPR(A, B) WHI_ASTV(WHI_ZIPR(VWHI_ASTM(A), VWHI_ASTM(B)))
    return  VWHI_ZIPR(a, b);
}

INLINE(Vwhf,VWHF_ZIPR) (Vwhf a, Vwhf b)
{
#define     VWHF_ZIPR(A, B) WHF_ASTV(WHF_ZIPR(VWHF_ASTM(A), VWHF_ASTM(B)))
    return  VWHF_ZIPR(a, b);
}


INLINE(Vdbu,VDBU_ZIPR) (Vdbu a, Vdbu b)
{
#define     VDBU_ZIPR   DBU_ZIPR
    return  VDBU_ZIPR(a, b);
}

INLINE(Vdbi,VDBI_ZIPR) (Vdbi a, Vdbi b)
{
#define     VDBI_ZIPR   DBI_ZIPR
    return  VDBI_ZIPR(a, b);
}

INLINE(Vdbc,VDBC_ZIPR) (Vdbc a, Vdbc b)
{
#define     VDBC_ZIPR(A, B)  DBC_ASTV(DBC_ZIPR(VDBC_ASTM(A), VDBC_ASTM(B)))
    return  VDBC_ZIPR(a, b);
}


INLINE(Vdhu,VDHU_ZIPR) (Vdhu a, Vdhu b)
{
#define     VDHU_ZIPR   DHU_ZIPR
    return  VDHU_ZIPR(a, b);
}

INLINE(Vdhi,VDHI_ZIPR) (Vdhi a, Vdhi b)
{
#define     VDHI_ZIPR   DHI_ZIPR
    return  VDHI_ZIPR(a, b);
}

INLINE(Vdhf,VDHF_ZIPR) (Vdhf a, Vdhf b)
{
#define     VDHF_ZIPR   DHF_ZIPR
    return  VDHF_ZIPR(a, b);
}


INLINE(Vdwu,VDWU_ZIPR) (Vdwu a, Vdwu b)
{
#define     VDWU_ZIPR   DWU_ZIPR
    return  VDWU_ZIPR(a, b);
}

INLINE(Vdwi,VDWI_ZIPR) (Vdwi a, Vdwi b)
{
#define     VDWI_ZIPR   DWI_ZIPR
    return  VDWI_ZIPR(a, b);
}

INLINE(Vdwf,VDWF_ZIPR) (Vdwf a, Vdwf b)
{
#define     VDWF_ZIPR   DWF_ZIPR
    return  VDWF_ZIPR(a, b);
}


INLINE(Vqbu,VQBU_ZIPR) (Vqbu a, Vqbu b)
{
#define     VQBU_ZIPR   QBU_ZIPR
    return  VQBU_ZIPR(a, b);
}

INLINE(Vqbi,VQBI_ZIPR) (Vqbi a, Vqbi b)
{
#define     VQBI_ZIPR   QBI_ZIPR
    return  VQBI_ZIPR(a, b);
}

INLINE(Vqbc,VQBC_ZIPR) (Vqbc a, Vqbc b)
{
#define     VQBC_ZIPR(A, B)  QBC_ASTV(QBC_ZIPR(VQBC_ASTM(A), VQBC_ASTM(B)))
    return  VQBC_ZIPR(a, b);
}


INLINE(Vqhu,VQHU_ZIPR) (Vqhu a, Vqhu b)
{
#define     VQHU_ZIPR   QHU_ZIPR
    return  VQHU_ZIPR(a, b);
}

INLINE(Vqhi,VQHI_ZIPR) (Vqhi a, Vqhi b)
{
#define     VQHI_ZIPR   QHI_ZIPR
    return  VQHI_ZIPR(a, b);
}

INLINE(Vqhf,VQHF_ZIPR) (Vqhf a, Vqhf b)
{
#define     VQHF_ZIPR   QHF_ZIPR
    return  VQHF_ZIPR(a, b);
}


INLINE(Vqwu,VQWU_ZIPR) (Vqwu a, Vqwu b)
{
#define     VQWU_ZIPR   QWU_ZIPR
    return  VQWU_ZIPR(a, b);
}

INLINE(Vqwi,VQWI_ZIPR) (Vqwi a, Vqwi b)
{
#define     VQWI_ZIPR   QWI_ZIPR
    return  VQWI_ZIPR(a, b);
}

INLINE(Vqwf,VQWF_ZIPR) (Vqwf a, Vqwf b)
{
#define     VQWF_ZIPR   QWF_ZIPR
    return  VQWF_ZIPR(a, b);
}


INLINE(Vqdu,VQDU_ZIPR) (Vqdu a, Vqdu b)
{
#define     VQDU_ZIPR   QDU_ZIPR
    return  VQDU_ZIPR(a, b);
}

INLINE(Vqdi,VQDI_ZIPR) (Vqdi a, Vqdi b)
{
#define     VQDI_ZIPR   QDI_ZIPR
    return  VQDI_ZIPR(a, b);
}

INLINE(Vqdf,VQDF_ZIPR) (Vqdf a, Vqdf b)
{
#define     VQDF_ZIPR   QDF_ZIPR
    return  VQDF_ZIPR(a, b);
}

#if _LEAVE_EXTGOP_ARM_ZIPR
}
#endif

#if _LEAVE_EXTGOP_ARM_ZIP_
}
#endif

#if _ENTER_EXTGOP_ARM_PER_
{
#endif

#if _ENTER_EXTGOP_ARM_PERM_
{
#endif
/*
    TBX <Vd>.<Ta>, { <Vn>.16B }, <Vm>.<Ta>
    TBX <Vd>.<Ta>, { <Vn>.16B, <Vn+1>.16B }, <Vm>.<Ta>
    TBX <Vd>.<Ta>, { <Vn>.16B, <Vn+1>.16B, <Vn+2>.16B }, <Vm>.<Ta>
    TBX <Vd>.<Ta>, { <Vn>.16B, <Vn+1>.16B, <Vn+2>.16B, <Vn+3>.16B }, <Vm>.<Ta>

uint8x16t vqtbx1q_u8(
    uint8x16_t      a (  <Vd.16B>  ),
    uint8x16_t      t ( {<Vn.16B>} ),
    uint8x16_t      i (  <Vm.16B>  )
) => TBX <Vd.16B>, {<Vn.16B>}, <Vm.16B>

uint8x16t vqtbx2q_u8(
    uint8x16_t      a (  <Vd.16B>  ),
    uint8x16_t      t ( {<Vn.16B>, <Vn+1.16B} ),
    uint8x16_t      i (  <Vm.16B>  )
) => TBX <Vd.16B>, {<Vn.16B>}, <Vm.16B>

*/

#define     V2_PERM(F,A,B,K0,K1)        F((A),(B),(K0),(K1))
#define     V4_PERM(F,A,B,K0,K1,K2,K3)  F((A),(B),(K0),(K1),(K2),(K3))
#define     V8_PERM(F,A,B,                  \
    K0,  K1,  K2,  K3,  K4,  K5,  K6,  K7)  \
F(                                          \
    (A),(B),                                \
    (K0),(K1),(K2),(K3),(K4),(K5),(K6),(K7) \
)

#define     V16_PERM(                               \
    F,A,B,                                          \
    K0,  K1,  K2,  K3,  K4,  K5,  K6,  K7,          \
    K8,  K9,  K10, K11, K12, K13, K14, K15  )       \
F(                                                  \
    (A),(B),                                         \
    (K0 ),(K1 ),(K2 ),(K3 ),(K4 ),(K5 ),(K6 ),(K7 ),\
    (K8 ),(K9 ),(K10),(K11),(K12),(K13),(K14),(K15) \
)

#define     V32_PERM(                   \
    F, A, B,                            \
    K0, K1, K2, K3, K4, K5, K6, K7,     \
    K8, K9, K10,K11,K12,K13,K14,K15,    \
    K16,K17,K18,K19,K20,K21,K22,K23,    \
    K24,K25,K26,K27,K28,K29,K30,K31)    \
F(                                      \
    (A),(B),                            \
    (K0 ),(K1 ),(K2 ),(K3 ),            \
    (K4 ),(K5 ),(K6 ),(K7 ),            \
    (K8 ),(K9 ),(K10),(K11),            \
    (K12),(K13),(K14),(K15),            \
    (K16),(K17),(K18),(K19),            \
    (K20),(K21),(K22),(K23),            \
    (K24),(K25),(K26),(K27),            \
    (K28),(K29),(K30),(K31)             \
)

#define     V64_PERM(                   \
    F, A, B,                            \
    K0, K1, K2, K3, K4, K5, K6, K7,     \
    K8, K9, K10,K11,K12,K13,K14,K15,    \
    K16,K17,K18,K19,K20,K21,K22,K23,    \
    K24,K25,K26,K27,K28,K29,K30,K31,    \
    K32,K33,K34,K35,K36,K37,K38,K39,    \
    K40,K41,K42,K43,K44,K45,K46,K47,    \
    K48,K49,K50,K51,K52,K53,K54,K55,    \
    K56,K57,K58,K59,K60,K61,K62,K63)    \
F(                                      \
    (A),(B),                            \
    (K0 ),(K1 ),(K2 ),(K3 ),(K4 ),(K5 ),(K6 ),(K7 ),\
    (K8 ),(K9 ),(K10),(K11),(K12),(K13),(K14),(K15),\
    (K16),(K17),(K18),(K19),(K20),(K21),(K22),(K23),\
    (K24),(K25),(K26),(K27),(K28),(K29),(K30),(K31),\
    (K32),(K33),(K34),(K35),(K36),(K37),(K38),(K39),\
    (K40),(K41),(K42),(K43),(K44),(K45),(K46),(K47),\
    (K48),(K49),(K50),(K51),(K52),(K53),(K54),(K55),\
    (K56),(K57),(K58),(K59),(K60),(K61),(K62),(K63) \
)

#define     WB_PERM(A,B, K0,K1,K2,K3)           \
vget_lane_f32(                                  \
    vreinterpret_f32_u8(                        \
        DB_PERM(                                \
            vreinterpret_u8_f32(vdup_n_f32(A)), \
            vreinterpret_u8_f32(vdup_n_f32(B)), \
            K0, K1, K2, K3,                     \
            -1, -1, -1, -1                      \
        )                                       \
    ),                                          \
    V2_K0                                       \
)

#define     WH_PERM(A, B, K0, K1)               \
vget_lane_f32(                                  \
    vreinterpret_f32_u8(                        \
        DH_PERM(                                \
            vreinterpret_u8_f32(vdup_n_f32(A)), \
            vreinterpret_u8_f32(vdup_n_f32(B)), \
            K0, K1, -1, -1                      \
        )                                       \
    ),                                          \
    V2_K0                                       \
)


#define     DB_PERM(                \
    A, B,                           \
    K0, K1, K2, K3, K4, K5, K6, K7) \
vtbx1_u8(                           \
    A, B,                           \
    vreinterpret_u8_u64(            \
        vdup_n_u64(                 \
            ((0xffull&K0)<<000)     \
        |   ((0xffull&K1)<<010)     \
        |   ((0xffull&K2)<<020)     \
        |   ((0xffull&K3)<<030)     \
        |   ((0xffull&K4)<<040)     \
        |   ((0xffull&K5)<<050)     \
        |   ((0xffull&K6)<<060)     \
        |   ((0xffull&K7)<<070)     \
        )                           \
    )                               \
)

#define     DH_PERM(A, B, K0, K1, K2, K3)           \
vtbx1_u8(                                           \
    A, B,                                           \
    vreinterpret_u8_u64(                            \
        vdup_n_u64(                                 \
            (                                       \
                (K0&0xfc) ? 0xffffull :             \
                (                                   \
                    ((HALF_B0+2ull*K0)<<000)        \
                |   ((HALF_B1+2ull*K0)<<010)        \
                )                                   \
            )                                       \
        |   (                                       \
                (K1&0xfc) ? (0xffffull<<020) :      \
                (                                   \
                    ((HALF_B0+2ull*K1)<<020)        \
                |   ((HALF_B1+2ull*K1)<<030)        \
                )                                   \
            )                                       \
        |   (                                       \
                (K2&0xfc) ? (0xffffull<<040) :      \
                (                                   \
                    ((HALF_B0+2ull*K2)<<040)        \
                |   ((HALF_B1+2ull*K2)<<050)        \
                )                                   \
            )                                       \
        |   (                                       \
                (K3&0xfc) ? (0xffffull<<060) :      \
                (                                   \
                    ((HALF_B0+2ull*K3)<<060)        \
                |   ((HALF_B1+2ull*K3)<<070)        \
                )                                   \
            )                                       \
        )                                           \
    )                                               \
)

#define     DW_PERM(A, B, K0, K1)                   \
vtbx1_u8(                                           \
    A, B,                                           \
    vreinterpret_u8_u64(                            \
        vdup_n_u64(                                 \
            (                                       \
                (K0&0xfe) ? (0xffffffffull<<000) :  \
                (                                   \
                    ((WORD_B0+K0*4ull)<<000)        \
                |   ((WORD_B1+K0*4ull)<<010)        \
                |   ((WORD_B2+K0*4ull)<<020)        \
                |   ((WORD_B3+K0*4ull)<<030)        \
                )                                   \
            )                                       \
        |   (                                       \
                (K1&0xfe) ? (0xffffffffull<<040) :  \
                (                                   \
                    ((WORD_B0+K1*4ull)<<040)        \
                |   ((WORD_B1+K1*4ull)<<050)        \
                |   ((WORD_B2+K1*4ull)<<060)        \
                |   ((WORD_B3+K1*4ull)<<070)        \
                )                                   \
            )                                       \
        )                                           \
    )                                               \
)

#define     QB_PERM(                \
    A, B,                           \
    K0,  K1,  K2,  K3,              \
    K4,  K5,  K6,  K7,              \
    K8,  K9,  K10, K11,             \
    K12, K13, K14, K15)             \
vqtbx1q_u8(                         \
    A,B,                            \
    vreinterpretq_u8_u64(           \
        vcombine_u64(               \
            vdup_n_u64(             \
                ((K0 &255ull)<<000) \
            |   ((K1 &255ull)<<010) \
            |   ((K2 &255ull)<<020) \
            |   ((K3 &255ull)<<030) \
            |   ((K4 &255ull)<<040) \
            |   ((K5 &255ull)<<050) \
            |   ((K6 &255ull)<<060) \
            |   ((K7 &255ull)<<070) \
            ),                      \
            vdup_n_u64(             \
                ((K8 &255ull)<<000) \
            |   ((K9 &255ull)<<010) \
            |   ((K10&255ull)<<020) \
            |   ((K11&255ull)<<030) \
            |   ((K12&255ull)<<040) \
            |   ((K13&255ull)<<050) \
            |   ((K14&255ull)<<060) \
            |   ((K15&255ull)<<070) \
            )                       \
        )                           \
    )                               \
)

#define     QH_PERM(                \
    A, B,                           \
    K0, K1, K2, K3, K4, K5, K6, K7) \
vqtbx1q_u8(                                         \
    A,B,                                            \
    vreinterpretq_u8_u64(                           \
        vcombine_u64(                               \
            vdup_n_u64(                             \
                (                                   \
                    (K0&0xf8) ? 0xffffull :         \
                    (                               \
                        ((HALF_B0+2ull*K0)<<000)    \
                    |   ((HALF_B1+2ull*K0)<<010)    \
                    )                               \
                )                                   \
                |                                   \
                (                                   \
                    (K1&0xf8) ? (0xffffull<<020) :  \
                    (                               \
                        ((HALF_B0+2ull*K1)<<020)    \
                    |   ((HALF_B1+2ull*K1)<<030)    \
                    )                               \
                )                                   \
                |                                   \
                (                                   \
                    (K2&0xf8) ? (0xffffull<<040) :  \
                    (                               \
                        ((HALF_B0+2ull*K2)<<040)    \
                    |   ((HALF_B1+2ull*K2)<<050)    \
                    )                               \
                )                                   \
                |                                   \
                (                                   \
                    (K3&0xf8) ? (0xffffull<<060) :  \
                    (                               \
                        ((HALF_B0+2ull*K3)<<060)    \
                    |   ((HALF_B1+2ull*K3)<<070)    \
                    )                               \
                )                                   \
            ),                                      \
            vdup_n_u64(                             \
                (                                   \
                    (K4&0xf8) ? 0xffffull :         \
                    (                               \
                        ((HALF_B0+2ull*K4)<<000)    \
                    |   ((HALF_B1+2ull*K4)<<010)    \
                    )                               \
                )                                   \
                |                                   \
                (                                   \
                    (K5&0xf8) ? (0xffffull<<020) :  \
                    (                               \
                        ((HALF_B0+2ull*K5)<<020)    \
                    |   ((HALF_B1+2ull*K5)<<030)    \
                    )                               \
                )                                   \
                |                                   \
                (                                   \
                    (K6&0xf8) ? (0xffffull<<040) :  \
                    (                               \
                        ((HALF_B0+2ull*K6)<<040)    \
                    |   ((HALF_B1+2ull*K6)<<050)    \
                    )                               \
                )                                   \
                |                                   \
                (                                   \
                    (K7&0xf8) ? (0xffffull<<060) :  \
                    (                               \
                        ((HALF_B0+2ull*K7)<<060)    \
                    |   ((HALF_B1+2ull*K7)<<070)    \
                    )                               \
                )                                   \
            )                                       \
        )                                           \
    )                                               \
)

#define     QW_PERM(A, B, K0, K1, K2, K3)               \
vqtbx1q_u8(                                             \
    A, B,                                               \
    vreinterpretq_u8_u64(                               \
        vcombine_u64(                                   \
            vdup_n_u64(                                 \
                (                                       \
                    (K0&0x80) ? (0xffffffffull<<000) :  \
                    (                                   \
                        ((WORD_B0+K0*4ull)<<000)        \
                    |   ((WORD_B1+K0*4ull)<<010)        \
                    |   ((WORD_B2+K0*4ull)<<020)        \
                    |   ((WORD_B3+K0*4ull)<<030)        \
                    )                                   \
                )                                       \
                |                                       \
                (                                       \
                    (K1&0x80) ? (0xffffffffull<<040) :  \
                    (                                   \
                        ((WORD_B0+K1*4ull)<<040)        \
                    |   ((WORD_B1+K1*4ull)<<050)        \
                    |   ((WORD_B2+K1*4ull)<<060)        \
                    |   ((WORD_B3+K1*4ull)<<070)        \
                    )                                   \
                )                                       \
            ),                                          \
            vdup_n_u64(                                 \
                (                                       \
                    (K2&0x80) ? (0xffffffffull<<000) :  \
                    (                                   \
                        ((WORD_B0+K2*4ull)<<000)        \
                    |   ((WORD_B1+K2*4ull)<<010)        \
                    |   ((WORD_B2+K2*4ull)<<020)        \
                    |   ((WORD_B3+K2*4ull)<<030)        \
                    )                                   \
                )                                       \
                |                                       \
                (                                       \
                    (K3&0x80) ? (0xffffffffull<<040) :  \
                    (                                   \
                        ((WORD_B0+K3*4ull)<<040)        \
                    |   ((WORD_B1+K3*4ull)<<050)        \
                    |   ((WORD_B2+K3*4ull)<<060)        \
                    |   ((WORD_B3+K3*4ull)<<070)        \
                    )                                   \
                )                                       \
            )                                           \
        )                                               \
    )                                                   \
)

#define     QD_PERM(A, B, K0, K1)   \
vqtbx1q_u8(                         \
    A, B,                           \
    vcombine_u8(                    \
        vdup_n_u8(254&K0 ? -1 : K0),\
        vdup_n_u8(254&K1 ? -1 : K1) \
    )                               \
)

#define     WBU_PERM(A, B, ...)     V4_PERM(WB_PERM,(A),(B),__VA_ARGS__)
#define     WBI_PERM(A, B, ...)     V4_PERM(WB_PERM,(A),(B),__VA_ARGS__)
#define     WBC_PERM(A, B, ...)     V4_PERM(WB_PERM,(A),(B),__VA_ARGS__)

#define     WHU_PERM(A, B, ...)     V2_PERM(WH_PERM,(A),(B),__VA_ARGS__)
#define     WHI_PERM(A, B, ...)     V2_PERM(WH_PERM,(A),(B),__VA_ARGS__)
#define     WHF_PERM(A, B, ...)     V2_PERM(WH_PERM,(A),(B),__VA_ARGS__)

#define     DBU_PERM(A, B, ...) \
         V8_PERM(DB_PERM,        (A),         (B), __VA_ARGS__)

#define     DBI_PERM(A, B, ...) \
DBU_ASBI(V8_PERM(DB_PERM,DBI_ASBU(A), DBI_ASBU(B), __VA_ARGS__))

#define     DBC_PERM(A, B, ...) \
DBU_ASBC(V8_PERM(DB_PERM,DBC_ASBU(A), DBC_ASBU(B), __VA_ARGS__))


#define     DHU_PERM(A, B, ...) \
DBU_ASHU(V4_PERM(DH_PERM,DHU_ASBU(A), DHU_ASBU(B), __VA_ARGS__))

#define     DHI_PERM(A, B, ...) \
DBU_ASHI(V4_PERM(DH_PERM,DHI_ASBU(A), DHI_ASBU(B), __VA_ARGS__))

#define     DHF_PERM(A, B, ...) \
DBU_ASHF(V4_PERM(DH_PERM,DHF_ASBU(A), DHF_ASBU(B), __VA_ARGS__))


#define     DWU_PERM(A, B, ...) \
DBU_ASWU(V2_PERM(DW_PERM,DWU_ASBU(A), DWU_ASBU(B), __VA_ARGS__))

#define     DWI_PERM(A, B, ...) \
DBU_ASWI(V2_PERM(DW_PERM,DWI_ASBU(A), DWI_ASBU(B), __VA_ARGS__))

#define     DWF_PERM(A, B, ...) \
DBU_ASWF(V2_PERM(DW_PERM,DWF_ASBU(A), DWF_ASBU(B), __VA_ARGS__))


#define     QBU_PERM(A, B, ...) \
         V16_PERM(QB_PERM,         (A),         (B), __VA_ARGS__)

#define     QBI_PERM(A, B, ...) \
QBU_ASBI(V16_PERM(QB_PERM, QBI_ASBU(A), QBI_ASBU(B), __VA_ARGS__))

#define     QBC_PERM(A, B, ...) \
QBU_ASBC(V16_PERM(QB_PERM, QBC_ASBU(A), QBC_ASBU(B), __VA_ARGS__))


#define     QHU_PERM(A, B, ...) \
QBU_ASHU( V8_PERM(QH_PERM, QHU_ASBU(A), QHU_ASBU(B), __VA_ARGS__))

#define     QHI_PERM(A, B, ...) \
QBU_ASHI( V8_PERM(QH_PERM, QHI_ASBU(A), QHI_ASBU(B), __VA_ARGS__))

#define     QHF_PERM(A, B, ...) \
QBU_ASHF( V8_PERM(QH_PERM, QHF_ASBU(A), QHU_ASBU(B), __VA_ARGS__))


#define     QWU_PERM(A, B, ...) \
QBU_ASWU( V4_PERM(QW_PERM, QWU_ASBU(A), QWU_ASBU(B), __VA_ARGS__))

#define     QWI_PERM(A, B, ...) \
QBU_ASWI( V4_PERM(QW_PERM, QWI_ASBU(A), QWI_ASBU(B), __VA_ARGS__))

#define     QWF_PERM(A, B, ...) \
QBU_ASWF( V4_PERM(QW_PERM, QWF_ASBU(A), QWF_ASBU(B), __VA_ARGS__))


#define     QDU_PERM(A, B, ...) \
QBU_ASDU( V2_PERM(QD_PERM, QDU_ASBU(A), QDU_ASBU(B), __VA_ARGS__))

#define     QDI_PERM(A, B, ...) \
QBU_ASDI( V2_PERM(QD_PERM, QDI_ASBU(A), QDI_ASBU(B), __VA_ARGS__))

#define     QDF_PERM(A, B, ...) \
QBU_ASDF( V2_PERM(QD_PERM, QDF_ASBU(A), QDF_ASBU(B), __VA_ARGS__))

INLINE(Vwbu,VWBU_PERM)
(
    Vwbu a, Vwbu b,
    Rc(-1,+3) k0, Rc(-1,+3) k1, Rc(-1,+3) k2, Rc(-1,+3) k3
)
{
#define     VWBU_PERM(A, B, ...)    \
WBU_ASTV(                           \
    WBU_PERM(                       \
        VWBU_ASTM(A),               \
        VWBU_ASTM(B),               \
        __VA_ARGS__                 \
    )                               \
)
    return  VWBU_PERM(a, b, k0,k1,k2,k3);
}

INLINE(Vwbi,VWBI_PERM)
(
    Vwbi a, Vwbi b,
    Rc(-1,3) k0, Rc(-1,3) k1, Rc(-1,3) k2, Rc(-1,3) k3
)
{
#define     VWBI_PERM(A, B, ...)    \
WBI_ASTV(                           \
    WBI_PERM(                       \
        VWBI_ASTM(A),               \
        VWBI_ASTM(B),               \
        __VA_ARGS__                 \
    )                               \
)
    return  VWBI_PERM(a, b, k0,k1,k2,k3);
}

INLINE(Vwbc,VWBC_PERM)
(
    Vwbc a, Vwbc b,
    Rc(-1,+3) k0, Rc(-1,+3) k1, Rc(-1,+3) k2, Rc(-1,+3) k3
)
{
#define     VWBC_PERM(A, B, ...)    \
WBC_ASTV(                           \
    WBC_PERM(                       \
        VWBC_ASTM(A),               \
        VWBC_ASTM(B),               \
        __VA_ARGS__                 \
    )                               \
)
    return  VWBC_PERM(a, b, k0,k1,k2,k3);
}


INLINE(Vwhu,VWHU_PERM) 
(
    Vwhu a, Vwhu b,
    Rc(-1,+1) k0, Rc(-1,+1) k1
)
{
#define     VWHU_PERM(A, B, ...)    \
WHU_ASTV(                           \
    WHU_PERM(                       \
        VWHU_ASTM(A),               \
        VWHU_ASTM(B),               \
        __VA_ARGS__                 \
    )                               \
)
    return  VWHU_PERM(a, b, k0,k1);
}


INLINE(Vwhi,VWHI_PERM) 
(
    Vwhi a, Vwhi b, 
    Rc(-1,+1) k0, Rc(-1,+1) k1
)
{
#define     VWHI_PERM(A, B, ...)    \
WHI_ASTV(                           \
    WHI_PERM(                       \
        VWHI_ASTM(A),               \
        VWHI_ASTM(B),               \
        __VA_ARGS__                 \
    )                               \
)
    return  VWHI_PERM(a, b, k0,k1);
}

INLINE(Vwhf,VWHF_PERM) 
(
    Vwhf a, Vwhf b,
    Rc(-1,+1) k0, Rc(-1,+1) k1
)
{
#define     VWHF_PERM(A, B, ...)    \
WHF_ASTV(                           \
    WHF_PERM(                       \
        VWHF_ASTM(A),               \
        VWHF_ASTM(B),               \
        __VA_ARGS__                 \
    )                               \
)
    return  VWHF_PERM(a, b, k0,k1);
}


INLINE(Vdbu,VDBU_PERM)
(
    Vdbu a, Vdbu b,
    Rc(-1,+7) k0, Rc(-1,+7) k1, Rc(-1,+7) k2, Rc(-1,+7) k3,
    Rc(-1,+7) k4, Rc(-1,+7) k5, Rc(-1,+7) k6, Rc(-1,+7) k7
)
{
#define     VDBU_PERM   DBU_PERM
    return  VDBU_PERM(a,b, k0,k1,k2,k3,k4,k5,k6,k7);
}

INLINE(Vdbi,VDBI_PERM)
(
    Vdbi a, Vdbi b,
    Rc(-1,+7) k0, Rc(-1,+7) k1, Rc(-1,+7) k2, Rc(-1,+7) k3,
    Rc(-1,+7) k4, Rc(-1,+7) k5, Rc(-1,+7) k6, Rc(-1,+7) k7
)
{
#define     VDBI_PERM   DBI_PERM
    return  VDBI_PERM(a,b, k0,k1,k2,k3,k4,k5,k6,k7);
}

INLINE(Vdbc,VDBC_PERM)
(
    Vdbc a, Vdbc b,
    Rc(-1,+7) k0, Rc(-1,+7) k1, Rc(-1,+7) k2, Rc(-1,+7) k3,
    Rc(-1,+7) k4, Rc(-1,+7) k5, Rc(-1,+7) k6, Rc(-1,+7) k7
)
{
#define     VDBC_PERM(A, B, ...)    \
DBC_ASTV(                           \
    DBC_PERM(                       \
        VDBC_ASTM(A),               \
        VDBC_ASTM(B),               \
        __VA_ARGS__                 \
    )                               \
)
    return  VDBC_PERM(a,b, k0,k1,k2,k3,k4,k5,k6,k7);
}


INLINE(Vdhu,VDHU_PERM)
(
    Vdhu a, Vdhu b,
    Rc(-1,+3) k0, Rc(-1,+3) k1, Rc(-1,+3) k2, Rc(-1,+3) k3
)
{
#define     VDHU_PERM   DHU_PERM
    return  VDHU_PERM(a,b, k0,k1,k2,k3);
}

INLINE(Vdhi,VDHI_PERM)
(
    Vdhi a, Vdhi b,
    Rc(-1,+3) k0, Rc(-1,+3) k1, Rc(-1,+3) k2, Rc(-1,+3) k3
)
{
#define     VDHI_PERM   DHI_PERM
    return  VDHI_PERM(a,b, k0,k1,k2,k3);
}

INLINE(Vdhf,VDHF_PERM)
(
    Vdhf a, Vdhf b,
    Rc(-1,+3) k0, Rc(-1,+3) k1, Rc(-1,+3) k2, Rc(-1,+3) k3
)
{
#define     VDHF_PERM   DHF_PERM
    return  VDHF_PERM(a,b, k0,k1,k2,k3);
}


INLINE(Vdwu,VDWU_PERM) 
(
    Vdwu a, Vdwu b,
    Rc(-1,+1) k0, Rc(-1,+1) k1
)
{
#define     VDWU_PERM   DWU_PERM
    return  VDWU_PERM(a,b, k0,k1);
}

INLINE(Vdwi,VDWI_PERM) 
(
    Vdwi a, Vdwi b,
    Rc(-1,+1) k0, Rc(-1,+1) k1
)
{
#define     VDWI_PERM   DWI_PERM
    return  VDWI_PERM(a,b, k0,k1);
}

INLINE(Vdwf,VDWF_PERM)
(
    Vdwf a, Vdwf b,
    Rc(-1,+1) k0, Rc(-1,+1) k1
)
{
#define     VDWF_PERM   DWF_PERM
    return  VDWF_PERM(a,b, k0,k1);
}


INLINE(Vqbu,VQBU_PERM)
(
    Vqbu a, Vqbu b,
    Rc(-1,+15)  k0, Rc(-1,+15)  k1, Rc(-1,+15)  k2, Rc(-1,+15)  k3,
    Rc(-1,+15)  k4, Rc(-1,+15)  k5, Rc(-1,+15)  k6, Rc(-1,+15)  k7,
    Rc(-1,+15)  k8, Rc(-1,+15)  k9, Rc(-1,+15) k10, Rc(-1,+15) k11,
    Rc(-1,+15) k12, Rc(-1,+15) k13, Rc(-1,+15) k14, Rc(-1,+15) k15
)
{
#define     VQBU_PERM   QBU_PERM
    return  VQBU_PERM(
        a, b,
        k0, k1, k2, k3,  k4, k5, k6, k7,
        k8, k9,k10,k11,  k12,k14,k14,k15
    );
}

INLINE(Vqbi,VQBI_PERM)
(
    Vqbi a, Vqbi b,
    Rc(-1,+15)  k0, Rc(-1,+15)  k1, Rc(-1,+15)  k2, Rc(-1,+15)  k3,
    Rc(-1,+15)  k4, Rc(-1,+15)  k5, Rc(-1,+15)  k6, Rc(-1,+15)  k7,
    Rc(-1,+15)  k8, Rc(-1,+15)  k9, Rc(-1,+15) k10, Rc(-1,+15) k11,
    Rc(-1,+15) k12, Rc(-1,+15) k13, Rc(-1,+15) k14, Rc(-1,+15) k15
)
{
#define     VQBI_PERM   QBI_PERM
    return  VQBI_PERM(
        a, b,
        k0, k1, k2, k3,  k4, k5, k6, k7,
        k8, k9,k10,k11,  k12,k14,k14,k15
    );
}

INLINE(Vqbc,VQBC_PERM)
(
    Vqbc a, Vqbc b,
    Rc(-1,+15)  k0, Rc(-1,+15)  k1, Rc(-1,+15)  k2, Rc(-1,+15)  k3,
    Rc(-1,+15)  k4, Rc(-1,+15)  k5, Rc(-1,+15)  k6, Rc(-1,+15)  k7,
    Rc(-1,+15)  k8, Rc(-1,+15)  k9, Rc(-1,+15) k10, Rc(-1,+15) k11,
    Rc(-1,+15) k12, Rc(-1,+15) k13, Rc(-1,+15) k14, Rc(-1,+15) k15
)
{
#define     VQBC_PERM(A, B, ...)    \
QBC_ASTV(                           \
    QBC_PERM(                       \
        VQBC_ASTM(A),               \
        VQBC_ASTM(B),               \
        __VA_ARGS__                 \
    )                               \
)
    return  VQBC_PERM(
        a,b,
        k0, k1, k2, k3,  k4, k5, k6, k7,
        k8, k9,k10,k11,  k12,k14,k14,k15
    );
}

INLINE(Vqhu,VQHU_PERM)
(
    Vqhu a, Vqhu b,
    Rc(-1,+7) k0, Rc(-1,+7) k1, Rc(-1,+7) k2, Rc(-1,+7) k3,
    Rc(-1,+7) k4, Rc(-1,+7) k5, Rc(-1,+7) k6, Rc(-1,+7) k7
)
{
#define     VQHU_PERM   QHU_PERM
    return  VQHU_PERM(a,b, k0,k1,k2,k3,k4,k5,k6,k7);
}

INLINE(Vqhi,VQHI_PERM)
(
    Vqhi a, Vqhi b,
    Rc(-1,+7) k0, Rc(-1,+7) k1, Rc(-1,+7) k2, Rc(-1,+7) k3,
    Rc(-1,+7) k4, Rc(-1,+7) k5, Rc(-1,+7) k6, Rc(-1,+7) k7
)
{
#define     VQHI_PERM   QHI_PERM
    return  VQHI_PERM(a,b, k0,k1,k2,k3,k4,k5,k6,k7);
}

INLINE(Vqhf,VQHF_PERM)
(
    Vqhf a, Vqhf b,
    Rc(-1,+7) k0, Rc(-1,+7) k1, Rc(-1,+7) k2, Rc(-1,+7) k3,
    Rc(-1,+7) k4, Rc(-1,+7) k5, Rc(-1,+7) k6, Rc(-1,+7) k7
)
{
#define     VQHF_PERM   QHF_PERM
    return  VQHF_PERM(a,b, k0,k1,k2,k3, k4,k5,k6,k7);
}


INLINE(Vqwu,VQWU_PERM)
(
    Vqwu a, Vqwu b,
    Rc(-1,+3) k0, Rc(-1,+3) k1, Rc(-1,+3) k2, Rc(-1,+3) k3
)
{
#define     VQWU_PERM   QWU_PERM
    return  VQWU_PERM(a,b, k0,k1,k2,k3);
}

INLINE(Vqwi,VQWI_PERM)
(
    Vqwi a, Vqwi b,
    Rc(-1,+3) k0, Rc(-1,+3) k1, Rc(-1,+3) k2, Rc(-1,+3) k3
)
{
#define     VQWI_PERM   QWI_PERM
    return  VQWI_PERM(a,b, k0,k1,k2,k3);
}

INLINE(Vqwf,VQWF_PERM)
(
    Vqwf a, Vqwf b,
    Rc(-1,+3) k0, Rc(-1,+3) k1, Rc(-1,+3) k2, Rc(-1,+3) k3
)
{
#define     VQWF_PERM   QWF_PERM
    return  VQWF_PERM(a,b, k0,k1,k2,k3);
}

INLINE(Vqdu,VQDU_PERM) 
(
    Vqdu a, Vqdu b, 
    Rc(-1,+1) k0, Rc(-1,+1) k1
)
{
#define     VQDU_PERM   QDU_PERM
    return  VQDU_PERM(a,b, k0,k1);
}

INLINE(Vqdi,VQDI_PERM)
(
    Vqdi a, Vqdi b, 
    Rc(-1,+1) k0, Rc(-1,+1) k1
)
{
#define     VQDI_PERM   QDI_PERM
    return  VQDI_PERM(a,b, k0,k1);
}

INLINE(Vqdf,VQDF_PERM)
(
    Vqdf a, Vqdf b, 
    Rc(-1,+1) k0, Rc(-1,+1) k1
)
{
#define     VQDF_PERM   QDF_PERM
    return  VQDF_PERM(a,b, k0,k1);
}
#if 0 // ice cream cone
#endif // ice cream cone

#if _LEAVE_EXTGOP_ARM_PERM_
}
#endif

#if _ENTER_EXTGOP_ARM_PERS_
{
#endif

#define     V2_PERS(f, v, k0, k1)           f((v),(k0),(k1))
#define     V4_PERS(f, v, k0, k1, k2, k3)   f((v),(k0),(k1),(k2),(k3))
#define     V8_PERS(f, v,                   \
    k0,  k1,  k2,  k3,  k4,  k5,  k6,  k7)  \
f(                                          \
    (v),                                    \
    (k0),(k1),(k2),(k3),(k4),(k5),(k6),(k7) \
)

#define     V16_PERS(                               \
    f, v,                                           \
    k0,  k1,  k2,  k3,  k4,  k5,  k6,  k7,          \
    k8,  k9,  k10, k11, k12, k13, k14, k15  )       \
f(                                                  \
    (v),                                            \
    (k0 ),(k1 ),(k2 ),(k3 ),(k4 ),(k5 ),(k6 ),(k7 ),\
    (k8 ),(k9 ),(k10),(k11),(k12),(k13),(k14),(k15) \
)

#define     V32_PERS(                   \
    f, v,                               \
    k0, k1, k2, k3, k4, k5, k6, k7,     \
    k8, k9, k10,k11,k12,k13,k14,k15,    \
    k16,k17,k18,k19,k20,k21,k22,k23,    \
    k24,k25,k26,k27,k28,k29,k30,k31)    \
f(                                      \
    (v),                                \
    (k0 ),(k1 ),(k2 ),(k3 ),(k4 ),(k5 ),(k6 ),(k7 ),\
    (k8 ),(k9 ),(k10),(k11),(k12),(k13),(k14),(k15),\
    (k16),(k17),(k18),(k19),(k20),(k21),(k22),(k23),\
    (k24),(k25),(k26),(k27),(k28),(k29),(k30),(k31) \
)

#define     V64_PERS(                   \
    f, v,                               \
    k0, k1, k2, k3, k4, k5, k6, k7,     \
    k8, k9, k10,k11,k12,k13,k14,k15,    \
    k16,k17,k18,k19,k20,k21,k22,k23,    \
    k24,k25,k26,k27,k28,k29,k30,k31,    \
    k32,k33,k34,k35,k36,k37,k38,k39,    \
    k40,k41,k42,k43,k44,k45,k46,k47,    \
    k48,k49,k50,k51,k52,k53,k54,k55,    \
    k56,k57,k58,k59,k60,k61,k62,k63)    \
f(                                      \
    v,                                  \
    (k0 ),(k1 ),(k2 ),(k3 ),(k4 ),(k5 ),(k6 ),(k7 ),\
    (k8 ),(k9 ),(k10),(k11),(k12),(k13),(k14),(k15),\
    (k16),(k17),(k18),(k19),(k20),(k21),(k22),(k23),\
    (k24),(k25),(k26),(k27),(k28),(k29),(k30),(k31),\
    (k32),(k33),(k34),(k35),(k36),(k37),(k38),(k39),\
    (k40),(k41),(k42),(k43),(k44),(k45),(k46),(k47),\
    (k48),(k49),(k50),(k51),(k52),(k53),(k54),(k55),\
    (k56),(k57),(k58),(k59),(k60),(k61),(k62),(k63) \
)

#define     WB_PERS(v, B0, B1, B2, B3)          \
vget_lane_f32(                                  \
    vreinterpret_f32_u8(                        \
        DB_PERS(                                \
            vreinterpret_u8_f32(vdup_n_f32(v)), \
            B0, B1, B2, B3,                     \
            -1, -1, -1, -1                      \
        )                                       \
    ),                                          \
    V2_K0                                       \
)

#define     WH_PERS(v, H0, H1)                  \
vget_lane_f32(                                  \
    vreinterpret_f32_u8(                        \
        DH_PERS(                                \
            vreinterpret_u8_f32(vdup_n_f32(v)), \
            H0, H1, -1, -1                      \
        )                                       \
    ),                                          \
    V2_K0                                       \
)


#define     DB_PERS(v, B0,B1,B2,B3,B4,B5,B6,B7) \
vtbl1_u8(                       \
    v,                          \
    vreinterpret_u8_u64(        \
        vdup_n_u64(             \
            ((0xffull&B0)<<000) \
        |   ((0xffull&B1)<<010) \
        |   ((0xffull&B2)<<020) \
        |   ((0xffull&B3)<<030) \
        |   ((0xffull&B4)<<040) \
        |   ((0xffull&B5)<<050) \
        |   ((0xffull&B6)<<060) \
        |   ((0xffull&B7)<<070) \
        )                       \
    )                           \
)

#define     DH_PERS(v, H0, H1, H2, H3)              \
vtbl1_u8(                                           \
    v,                                              \
    vreinterpret_u8_u64(                            \
        vdup_n_u64(                                 \
            (                                       \
                (H0&0x80) ? 0xffffull :             \
                (                                   \
                    ((HALF_B0+2ull*H0)<<000)        \
                |   ((HALF_B1+2ull*H0)<<010)        \
                )                                   \
            )                                       \
        |   (                                       \
                (H1&0x80) ? (0xffffull<<020) :      \
                (                                   \
                    ((HALF_B0+2ull*H1)<<020)        \
                |   ((HALF_B1+2ull*H1)<<030)        \
                )                                   \
            )                                       \
        |   (                                       \
                (H2&0x80) ? (0xffffull<<040) :      \
                (                                   \
                    ((HALF_B0+2ull*H2)<<040)        \
                |   ((HALF_B1+2ull*H2)<<050)        \
                )                                   \
            )                                       \
        |   (                                       \
                (H3&0x80) ? (0xffffull<<060) :      \
                (                                   \
                    ((HALF_B0+2ull*H3)<<060)        \
                |   ((HALF_B1+2ull*H3)<<070)        \
                )                                   \
            )                                       \
        )                                           \
    )                                               \
)

#define     DW_PERS(v, W0, W1)                      \
vtbl1_u8(                                           \
    v,                                              \
    vreinterpret_u8_u64(                            \
        vdup_n_u64(                                 \
            (                                       \
                (W0&0x80) ? (0xffffffffull<<000) :  \
                (                                   \
                    ((WORD_B0+W0*4ull)<<000)        \
                |   ((WORD_B1+W0*4ull)<<010)        \
                |   ((WORD_B2+W0*4ull)<<020)        \
                |   ((WORD_B3+W0*4ull)<<030)        \
                )                                   \
            )                                       \
        |   (                                       \
                (W1&0x80) ? (0xffffffffull<<040) :  \
                (                                   \
                    ((WORD_B0+W1*4ull)<<040)        \
                |   ((WORD_B1+W1*4ull)<<050)        \
                |   ((WORD_B2+W1*4ull)<<060)        \
                |   ((WORD_B3+W1*4ull)<<070)        \
                )                                   \
            )                                       \
        )                                           \
    )                                               \
)

#define     QB_PERS(                \
    v,                              \
    B0,  B1,  B2,  B3,              \
    B4,  B5,  B6,  B7,              \
    B8,  B9,  B10, B11,             \
    B12, B13, B14, B15              \
)                                   \
vqtbl1q_u8(                         \
    v,                              \
    vreinterpretq_u8_u64(           \
        vcombine_u64(               \
            vdup_n_u64(             \
                ((B0 &255ull)<<000) \
            |   ((B1 &255ull)<<010) \
            |   ((B2 &255ull)<<020) \
            |   ((B3 &255ull)<<030) \
            |   ((B4 &255ull)<<040) \
            |   ((B5 &255ull)<<050) \
            |   ((B6 &255ull)<<060) \
            |   ((B7 &255ull)<<070) \
            ),                      \
            vdup_n_u64(             \
                ((B8 &255ull)<<000) \
            |   ((B9 &255ull)<<010) \
            |   ((B10&255ull)<<020) \
            |   ((B11&255ull)<<030) \
            |   ((B12&255ull)<<040) \
            |   ((B13&255ull)<<050) \
            |   ((B14&255ull)<<060) \
            |   ((B15&255ull)<<070) \
            )                       \
        )                           \
    )                               \
)

#define     QH_PERS(v, H0,H1,H2,H3,H4,H5,H6,H7)     \
vqtbl1q_u8(                                         \
    v,                                              \
    vreinterpretq_u8_u64(                           \
        vcombine_u64(                               \
            vdup_n_u64(                             \
                (                                   \
                    (H0&0x80) ? 0xffffull :         \
                    (                               \
                        ((HALF_B0+2ull*H0)<<000)    \
                    |   ((HALF_B1+2ull*H0)<<010)    \
                    )                               \
                )                                   \
                |                                   \
                (                                   \
                    (H1&0x80) ? (0xffffull<<020) :  \
                    (                               \
                        ((HALF_B0+2ull*H1)<<020)    \
                    |   ((HALF_B1+2ull*H1)<<030)    \
                    )                               \
                )                                   \
                |                                   \
                (                                   \
                    (H2&0x80) ? (0xffffull<<040) :  \
                    (                               \
                        ((HALF_B0+2ull*H2)<<040)    \
                    |   ((HALF_B1+2ull*H2)<<050)    \
                    )                               \
                )                                   \
                |                                   \
                (                                   \
                    (H3&0x80) ? (0xffffull<<060) :  \
                    (                               \
                        ((HALF_B0+2ull*H3)<<060)    \
                    |   ((HALF_B1+2ull*H3)<<070)    \
                    )                               \
                )                                   \
            ),                                      \
            vdup_n_u64(                             \
                (                                   \
                    (H4&0x80) ? 0xffffull :         \
                    (                               \
                        ((HALF_B0+2ull*H4)<<000)    \
                    |   ((HALF_B1+2ull*H4)<<010)    \
                    )                               \
                )                                   \
                |                                   \
                (                                   \
                    (H5&0x80) ? (0xffffull<<020) :  \
                    (                               \
                        ((HALF_B0+2ull*H5)<<020)    \
                    |   ((HALF_B1+2ull*H5)<<030)    \
                    )                               \
                )                                   \
                |                                   \
                (                                   \
                    (H6&0x80) ? (0xffffull<<040) :  \
                    (                               \
                        ((HALF_B0+2ull*H6)<<040)    \
                    |   ((HALF_B1+2ull*H6)<<050)    \
                    )                               \
                )                                   \
                |                                   \
                (                                   \
                    (H7&0x80) ? (0xffffull<<060) :  \
                    (                               \
                        ((HALF_B0+2ull*H7)<<060)    \
                    |   ((HALF_B1+2ull*H7)<<070)    \
                    )                               \
                )                                   \
            )                                       \
        )                                           \
    )                                               \
)

#define     QW_PERS(v, W0, W1, W2, W3)                  \
vqtbl1q_u8(                                             \
    v,                                                  \
    vreinterpretq_u8_u64(                                \
        vcombine_u64(                                   \
            vdup_n_u64(                                 \
                (                                       \
                    (W0&0x80) ? (0xffffffffull<<000) :  \
                    (                                   \
                        ((WORD_B0+W0*4ull)<<000)        \
                    |   ((WORD_B1+W0*4ull)<<010)        \
                    |   ((WORD_B2+W0*4ull)<<020)        \
                    |   ((WORD_B3+W0*4ull)<<030)        \
                    )                                   \
                )                                       \
                |                                       \
                (                                       \
                    (W1&0x80) ? (0xffffffffull<<040) :  \
                    (                                   \
                        ((WORD_B0+W1*4ull)<<040)        \
                    |   ((WORD_B1+W1*4ull)<<050)        \
                    |   ((WORD_B2+W1*4ull)<<060)        \
                    |   ((WORD_B3+W1*4ull)<<070)        \
                    )                                   \
                )                                       \
            ),                                          \
            vdup_n_u64(                                 \
                (                                       \
                    (W2&0x80) ? (0xffffffffull<<000) :  \
                    (                                   \
                        ((WORD_B0+W2*4ull)<<000)        \
                    |   ((WORD_B1+W2*4ull)<<010)        \
                    |   ((WORD_B2+W2*4ull)<<020)        \
                    |   ((WORD_B3+W2*4ull)<<030)        \
                    )                                   \
                )                                       \
                |                                       \
                (                                       \
                    (W3&0x80) ? (0xffffffffull<<040) :  \
                    (                                   \
                        ((WORD_B0+W3*4ull)<<040)        \
                    |   ((WORD_B1+W3*4ull)<<050)        \
                    |   ((WORD_B2+W3*4ull)<<060)        \
                    |   ((WORD_B3+W3*4ull)<<070)        \
                    )                                   \
                )                                       \
            )                                           \
        )                                               \
    )                                                   \
)

#define     QD_PERS(v, D0, D1)      \
vqtbl1q_u8(                         \
    v,                              \
    vcombine_u8(                    \
        vdup_n_u8(128&D0 ? -1 : D0),\
        vdup_n_u8(128&D1 ? -1 : D1) \
    )                               \
)

#define     WBU_PERS(M, ...)    V4_PERS(WB_PERS,(M),__VA_ARGS__)
#define     WBI_PERS(M, ...)    V4_PERS(WB_PERS,(M),__VA_ARGS__)
#define     WBC_PERS(M, ...)    V4_PERS(WB_PERS,(M),__VA_ARGS__)

#define     WHU_PERS(M, ...)    V2_PERS(WH_PERS,(M),__VA_ARGS__)
#define     WHI_PERS(M, ...)    V2_PERS(WH_PERS,(M),__VA_ARGS__)
#define     WHF_PERS(M, ...)    V2_PERS(WH_PERS,(M),__VA_ARGS__)


#define     DBU_PERS(M, ...)    \
        V8_PERS(DB_PERS,          (M), __VA_ARGS__)

#define     DBI_PERS(M, ...)    \
DBU_ASBI(V8_PERS(DB_PERS, DBI_ASBU(M), __VA_ARGS__))

#define     DBC_PERS(M, ...)    \
DBU_ASBC(V8_PERS(DB_PERS, DBC_ASBU(M), __VA_ARGS__))


#define     DHU_PERS(M, ...)    \
DBU_ASHU(V4_PERS(DH_PERS, DHU_ASBU(M), __VA_ARGS__))

#define     DHI_PERS(M, ...)    \
DBU_ASHI(V4_PERS(DH_PERS, DHI_ASBU(M), __VA_ARGS__))

#define     DHF_PERS(M, ...)    \
DBU_ASHF(V4_PERS(DH_PERS, DHF_ASBU(M), __VA_ARGS__))


#define     DWU_PERS(M, ...)    \
DBU_ASWU(V2_PERS(DW_PERS, DWU_ASBU(M), __VA_ARGS__))

#define     DWI_PERS(M, ...)    \
DBU_ASWI(V2_PERS(DW_PERS, DWI_ASBU(M), __VA_ARGS__))

#define     DWF_PERS(M,...)     \
DBU_ASWF(V2_PERS(DW_PERS, DWF_ASBU(M), __VA_ARGS__))


#define     QBU_PERS(M, ...)    \
         V16_PERS(QB_PERS,         (M), __VA_ARGS__)

#define     QBI_PERS(M, ...)    \
QBU_ASBI(V16_PERS(QB_PERS, QBI_ASBU(M), __VA_ARGS__))

#define     QBC_PERS(M, ...)    \
QBU_ASBC(V16_PERS(QB_PERS, QBC_ASBU(M), __VA_ARGS__))


#define     QHU_PERS(M, ...)    \
QBU_ASHU(V8_PERS(QH_PERS, QHU_ASBU(M),__VA_ARGS__))

#define     QHI_PERS(M, ...)    \
QBU_ASHI(V8_PERS(QH_PERS, QHI_ASBU(M),__VA_ARGS__))

#define     QHF_PERS(M, ...)    \
QBU_ASHF(V8_PERS(QH_PERS, QHF_ASBU(M), __VA_ARGS__))


#define     QWU_PERS(M, ...)    \
QBU_ASWU(V4_PERS(QW_PERS, QWU_ASBU(M), __VA_ARGS__))

#define     QWI_PERS(M, ...)    \
QBU_ASWI(V4_PERS(QW_PERS, QWI_ASBU(M), __VA_ARGS__))

#define     QWF_PERS(M, ...)    \
QBU_ASWF(V4_PERS(QW_PERS, QWF_ASBU(M), __VA_ARGS__))


#define     QDU_PERS(M, ...)    \
QBU_ASDU(V2_PERS(QD_PERS, QDU_ASBU(M), __VA_ARGS__))

#define     QDI_PERS(M, ...)    \
QBU_ASDI(V2_PERS(QD_PERS, QDI_ASBU(M), __VA_ARGS__))

#define     QDF_PERS(M, ...)    \
QBU_ASDF(V2_PERS(QD_PERS, QDF_ASBU(M), __VA_ARGS__))


INLINE(Vwbu,VWBU_PERS) 
(
    Vwbu v, 
    Rc(-1,+3) k0, Rc(-1,+3) k1, Rc(-1,+3) k2, Rc(-1,+3) k3
)
{
#define     VWBU_PERS(V, ...) WBU_ASTV(WBU_PERS(VWBU_ASTM(V),__VA_ARGS__))
    return  VWBU_PERS(v, k0,k1,k2,k3);
}

INLINE(Vwbi,VWBI_PERS) 
(
    Vwbi v, 
    Rc(-1,3) k0, Rc(-1,3) k1, Rc(-1,3) k2, Rc(-1,3) k3
)
{
#define     VWBI_PERS(V, ...) WBI_ASTV(WBI_PERS(VWBI_ASTM(V),__VA_ARGS__))

    return  VWBI_PERS(v, k0,k1,k2,k3);
}

INLINE(Vwbc,VWBC_PERS)
(
    Vwbc v, 
    Rc(-1,+3) k0, Rc(-1,+3) k1, Rc(-1,+3) k2, Rc(-1,+3) k3
)
{
#define     VWBC_PERS(V, ...) WBC_ASTV(WBC_PERS(VWBC_ASTM(V),__VA_ARGS__))
    return  VWBC_PERS(v, k0,k1,k2,k3);
}

INLINE(Vwhu,VWHU_PERS) (Vwhu v, Rc(-1,+1) k0, Rc(-1,+1) k1)
{
#define     VWHU_PERS(V, ...) WHU_ASTV(WHU_PERS(VWHU_ASTM(V),__VA_ARGS__))

    return VWHU_PERS(v, k0,k1);
}

INLINE(Vwhi,VWHI_PERS) (Vwhi v, Rc(-1,+1) k0, Rc(-1,+1) k1)
{
#define     VWHI_PERS(V, ...) WHI_ASTV(WHI_PERS(VWHI_ASTM(V),__VA_ARGS__))

    return VWHI_PERS(v, k0,k1);
}

INLINE(Vwhf,VWHF_PERS) (Vwhf v, Rc(-1,+1) k0, Rc(-1,+1) k1)
{
#define     VWHF_PERS(V, ...) WHF_ASTV(WHF_PERS(VWHF_ASTM(V),__VA_ARGS__))
    return  VWHF_PERS(v, k0,k1);
}


INLINE(Vdbu,VDBU_PERS) 
(
    Vdbu v, 
    Rc(-1,+7) k0, Rc(-1,+7) k1, Rc(-1,+7) k2, Rc(-1,+7) k3,
    Rc(-1,+7) k4, Rc(-1,+7) k5, Rc(-1,+7) k6, Rc(-1,+7) k7
)
{
#define     VDBU_PERS   DBU_PERS
    return  VDBU_PERS(v, k0,k1,k2,k3,k4,k5,k6,k7);
}

INLINE(Vdbi,VDBI_PERS) 
(
    Vdbi v, 
    Rc(-1,+7) k0, Rc(-1,+7) k1, Rc(-1,+7) k2, Rc(-1,+7) k3,
    Rc(-1,+7) k4, Rc(-1,+7) k5, Rc(-1,+7) k6, Rc(-1,+7) k7
)
{
#define     VDBI_PERS   DBI_PERS
    return  VDBI_PERS(v, k0,k1,k2,k3,k4,k5,k6,k7);
}

INLINE(Vdbc,VDBC_PERS) 
(
    Vdbc v, 
    Rc(-1,+7) k0, Rc(-1,+7) k1, Rc(-1,+7) k2, Rc(-1,+7) k3,
    Rc(-1,+7) k4, Rc(-1,+7) k5, Rc(-1,+7) k6, Rc(-1,+7) k7
)
{
#define     VDBC_PERS(v, ...)  \
DBC_ASTV(DBC_PERS(VDBC_ASTM(v),__VA_ARGS__))
    return  VDBC_PERS(v, k0,k1,k2,k3,k4,k5,k6,k7);
}


INLINE(Vdhu,VDHU_PERS) 
(
    Vdhu v,
    Rc(-1,+3) k0, Rc(-1,+3) k1, Rc(-1,+3) k2, Rc(-1,+3) k3
)
{
#define     VDHU_PERS   DHU_PERS
    return  VDHU_PERS(v, k0,k1,k2,k3);
}

INLINE(Vdhi,VDHI_PERS) 
(
    Vdhi v, 
    Rc(-1,+3) k0, Rc(-1,+3) k1, Rc(-1,+3) k2, Rc(-1,+3) k3
)
{
#define     VDHI_PERS   DHI_PERS
    return  VDHI_PERS(v, k0,k1,k2,k3);
}

INLINE(Vdhf,VDHF_PERS) 
(
    Vdhf v, 
    Rc(-1,+3) k0, Rc(-1,+3) k1, Rc(-1,+3) k2, Rc(-1,+3) k3
)
{
#define     VDHF_PERS   DHF_PERS
    return  VDHF_PERS(v, k0,k1,k2,k3);
}


INLINE(Vdwu,VDWU_PERS) (Vdwu v, Rc(-1,+1) k0, Rc(-1,+1) k1)
{
#define     VDWU_PERS   DWU_PERS
    return  VDWU_PERS(v, k0,k1);
}

INLINE(Vdwi,VDWI_PERS) (Vdwi v, Rc(-1,+1) k0, Rc(-1,+1) k1)
{
#define     VDWI_PERS   DWI_PERS
    return  VDWI_PERS(v, k0,k1);
}

INLINE(Vdwf,VDWF_PERS) (Vdwf v, Rc(-1,+1) k0, Rc(-1,+1) k1)
{
#define     VDWF_PERS   DWF_PERS
    return  VDWF_PERS(v, k0,k1);
}


INLINE(Vqbu,VQBU_PERS)
(
    Vqbu v, 
    Rc(-1,+15)  k0, Rc(-1,+15)  k1, Rc(-1,+15)  k2, Rc(-1,+15)  k3,
    Rc(-1,+15)  k4, Rc(-1,+15)  k5, Rc(-1,+15)  k6, Rc(-1,+15)  k7,
    Rc(-1,+15)  k8, Rc(-1,+15)  k9, Rc(-1,+15) k10, Rc(-1,+15) k11,
    Rc(-1,+15) k12, Rc(-1,+15) k13, Rc(-1,+15) k14, Rc(-1,+15) k15
)
{
#define     VQBU_PERS   QBU_PERS
    return  VQBU_PERS(
        v, 
        k0, k1, k2, k3,  k4, k5, k6, k7,
        k8, k9,k10,k11,  k12,k14,k14,k15
    );
}

INLINE(Vqbi,VQBI_PERS)
(
    Vqbi v, 
    Rc(-1,+15)  k0, Rc(-1,+15)  k1, Rc(-1,+15)  k2, Rc(-1,+15)  k3,
    Rc(-1,+15)  k4, Rc(-1,+15)  k5, Rc(-1,+15)  k6, Rc(-1,+15)  k7,
    Rc(-1,+15)  k8, Rc(-1,+15)  k9, Rc(-1,+15) k10, Rc(-1,+15) k11,
    Rc(-1,+15) k12, Rc(-1,+15) k13, Rc(-1,+15) k14, Rc(-1,+15) k15
)
{
#define     VQBI_PERS   QBI_PERS
    return  VQBI_PERS(
        v, 
        k0, k1, k2, k3,  k4, k5, k6, k7,
        k8, k9,k10,k11,  k12,k14,k14,k15
    );
}

INLINE(Vqbc,VQBC_PERS)
(
    Vqbc v, 
    Rc(-1,+15)  k0, Rc(-1,+15)  k1, Rc(-1,+15)  k2, Rc(-1,+15)  k3,
    Rc(-1,+15)  k4, Rc(-1,+15)  k5, Rc(-1,+15)  k6, Rc(-1,+15)  k7,
    Rc(-1,+15)  k8, Rc(-1,+15)  k9, Rc(-1,+15) k10, Rc(-1,+15) k11,
    Rc(-1,+15) k12, Rc(-1,+15) k13, Rc(-1,+15) k14, Rc(-1,+15) k15
)
{
#define     VQBC_PERS(V, ...)  \
    QBC_ASTV(QBC_PERS(VQBC_ASTM(V),__VA_ARGS__))
    return  VQBC_PERS(
        v, 
        k0, k1, k2, k3,  k4, k5, k6, k7,
        k8, k9,k10,k11,  k12,k14,k14,k15
    );
}

INLINE(Vqhu,VQHU_PERS) 
(
    Vqhu v, 
    Rc(-1,+7) k0, Rc(-1,+7) k1, Rc(-1,+7) k2, Rc(-1,+7) k3,
    Rc(-1,+7) k4, Rc(-1,+7) k5, Rc(-1,+7) k6, Rc(-1,+7) k7
)
{
#define     VQHU_PERS   QHU_PERS
    return  VQHU_PERS(v, k0,k1,k2,k3,k4,k5,k6,k7);
}

INLINE(Vqhi,VQHI_PERS) 
(
    Vqhi v, 
    Rc(-1,+7) k0, Rc(-1,+7) k1, Rc(-1,+7) k2, Rc(-1,+7) k3,
    Rc(-1,+7) k4, Rc(-1,+7) k5, Rc(-1,+7) k6, Rc(-1,+7) k7
)
{
#define     VQHI_PERS   QHI_PERS
    return  VQHI_PERS(v, k0,k1,k2,k3,k4,k5,k6,k7);
}

INLINE(Vqhf,VQHF_PERS) 
(
    Vqhf v, 
    Rc(-1,+7) k0, Rc(-1,+7) k1, Rc(-1,+7) k2, Rc(-1,+7) k3,
    Rc(-1,+7) k4, Rc(-1,+7) k5, Rc(-1,+7) k6, Rc(-1,+7) k7
)
{
#define     VQHF_PERS   QHF_PERS
    return  VQHF_PERS(v, k0,k1,k2,k3,k4,k5,k6,k7);
}


INLINE(Vqwu,VQWU_PERS) 
(
    Vqwu v,
    Rc(-1,+3) k0, Rc(-1,+3) k1, Rc(-1,+3) k2, Rc(-1,+3) k3
)
{
#define     VQWU_PERS   QWU_PERS
    return  VQWU_PERS(v, k0,k1,k2,k3);
}

INLINE(Vqwi,VQWI_PERS) 
(
    Vqwi v,
    Rc(-1,+3) k0, Rc(-1,+3) k1, Rc(-1,+3) k2, Rc(-1,+3) k3
)
{
#define     VQWI_PERS   QWI_PERS
    return  VQWI_PERS(v, k0,k1,k2,k3);
}

INLINE(Vqwf,VQWF_PERS) 
(
    Vqwf v,
    Rc(-1,+3) k0, Rc(-1,+3) k1, Rc(-1,+3) k2, Rc(-1,+3) k3
)
{
#define     VQWF_PERS   QWF_PERS
    return  VQWF_PERS(v, k0,k1,k2,k3);
}

INLINE(Vqdu,VQDU_PERS) (Vqdu v, Rc(-1,+1) k0, Rc(-1,+1) k1)
{
#define     VQDU_PERS   QDU_PERS
    return  VQDU_PERS(v, k0,k1);
}

INLINE(Vqdi,VQDI_PERS) (Vqdi v, Rc(-1,+1) k0, Rc(-1,+1) k1)
{
#define     VQDI_PERS   QDI_PERS
    return  VQDI_PERS(v, k0,k1);
}

INLINE(Vqdf,VQDF_PERS) (Vqdf v, Rc(-1,+1) k0, Rc(-1,+1) k1)
{
#define     VQDF_PERS   QDF_PERS
    return  VQDF_PERS(v, k0,k1);
}

#if 0 // ice cream cone
#endif // ice cream cone

#if _LEAVE_EXTGOP_ARM_PERS_
}
#endif

#if _LEAVE_EXTGOP_ARM_PER_
}
#endif



#if _ENTER_EXTGOP_ARM_VST_
{
#endif

#if _ENTER_EXTGOP_ARM_VSTL
{
#endif

INLINE(Vdyu,VDYU_VSTL) (Vdyu c, Vwyu l)
{
#define     VDYU_VSTL(C, L) \
VDWF_ASYU(vset_lane_f32(VWYU_ASTM(L), VDYU_ASWF(C), V2_K0))
    return  VDYU_VSTL(c, l);
}


INLINE(Vdbu,VDBU_VSTL) (Vdbu c, Vwbu l)
{
#define     VDBU_VSTL(C, L) \
VDWF_ASBU(vset_lane_f32(VWBU_ASTM(L), VDBU_ASWF(C), V2_K0))
    return  VDBU_VSTL(c, l);
}

INLINE(Vdbi,VDBI_VSTL) (Vdbi c, Vwbi l)
{
#define     VDBI_VSTL(C, L) \
VDWF_ASBI(vset_lane_f32(VWBI_ASTM(L), VDBI_ASWF(C), V2_K0))
    return  VDBI_VSTL(c, l);
}

INLINE(Vdbc,VDBC_VSTL) (Vdbc c, Vwbu l)
{
#define     VDBC_VSTL(C, L) \
VDWF_ASBC(vset_lane_f32(VWBC_ASTM(L), VDBC_ASWF(C), V2_K0))
    return  VDBC_VSTL(c, l);
}


INLINE(Vdhu,VDHU_VSTL) (Vdhu c, Vwhu l)
{
#define     VDHU_VSTL(C, L) \
VDWF_ASHU(vset_lane_f32(VWHU_ASTM(L), VDHU_ASWF(C), V2_K0))
    return  VDHU_VSTL(c, l);
}

INLINE(Vdhi,VDHI_VSTL) (Vdhi c, Vwhi l)
{
#define     VDHI_VSTL(C, L) \
VDWF_ASHI(vset_lane_f32(VWHI_ASTM(L), VDHI_ASWF(C), V2_K0))
    return  VDHI_VSTL(c, l);
}

INLINE(Vdhf,VDHF_VSTL) (Vdhf c, Vwhf l)
{
#define     VDHF_VSTL(C, L) \
VDWF_ASHF(vset_lane_f32(VWHF_ASTM(L), VDHF_ASWF(C), V2_K0))
    return  VDHF_VSTL(c, l);
}


INLINE(Vdwu,VDWU_VSTL) (Vdwu c, Vwwu l)
{
#define     VDWU_VSTL(C, L) \
VDWF_ASWU(vset_lane_f32(VWWU_ASTM(L), VDWU_ASWF(C), V2_K0))
    return  VDWU_VSTL(c, l);
}

INLINE(Vdwi,VDWI_VSTL) (Vdwi c, Vwwi l)
{
#define     VDWI_VSTL(C, L) \
VDWF_ASWI(vset_lane_f32(VWWI_ASTM(L), VDWI_ASWF(C), V2_K0))
    return  VDWI_VSTL(c, l);
}

INLINE(Vdwf,VDWF_VSTL) (Vdwf c, Vwwf l)
{
#define     VDWF_VSTL(C, L) vset_lane_f32(VWWF_ASTM(L), C, V2_K0)
    return  VDWF_VSTL(c, l);
}


INLINE(Vqyu,VQYU_VSTL) (Vqyu c, Vdyu l)
{
#define     VQYU_VSTL(C, L) \
QYU_ASTV(vcombine_u64(VDYU_ASTM(L), vget_low_u64(VQYU_ASTM(C))))
    return  VQYU_VSTL(c, l);
}

INLINE(Vqbu,VQBU_VSTL) (Vqbu c, Vdbu l)
{
#define     VQBU_VSTL(C, L) vcombine_u8(L, vget_high_u8(C))
    return  VQBU_VSTL(c, l);
}

INLINE(Vqbi,VQBI_VSTL) (Vqbi c, Vdbi l)
{
#define     VQBI_VSTL(C, L) vcombine_s8(L, vget_high_s8(C))
    return  VQBI_VSTL(c, l);
}

INLINE(Vqbc,VQBC_VSTL) (Vqbc c, Vdbc l)
{
#define     VQBC_VSTL(C, L)         \
VQDU_ASBC(                          \
    vcombine_u64(                   \
        VDBC_ASDU(L),               \
        vget_high_u64(VQBC_ASDU(C)) \
    )                               \
)
    return  VQBC_VSTL(c, l);
}


INLINE(Vqhu,VQHU_VSTL) (Vqhu c, Vdhu l)
{
#define     VQHU_VSTL(C, L) vcombine_u16(L, vget_high_u16(C))
    return  VQHU_VSTL(c, l);
}

INLINE(Vqhi,VQHI_VSTL) (Vqhi c, Vdhi l)
{
#define     VQHI_VSTL(C, L) vcombine_s16(L, vget_high_s16(C))
    return  VQHI_VSTL(c, l);
}

INLINE(Vqhf,VQHF_VSTL) (Vqhf c, Vdhf l)
{
#define     VQHF_VSTL(C, L) vcombine_f16(L, vget_high_f16(C))
    return  VQHF_VSTL(c, l);
}


INLINE(Vqwu,VQWU_VSTL) (Vqwu c, Vdwu l)
{
#define     VQWU_VSTL(C, L) vcombine_u32(L, vget_high_u32(C))
    return  VQWU_VSTL(c, l);
}

INLINE(Vqwi,VQWI_VSTL) (Vqwi c, Vdwi l)
{
#define     VQWI_VSTL(C, L) vcombine_s32(L, vget_high_s32(C))
    return  VQWI_VSTL(c, l);
}

INLINE(Vqwf,VQWF_VSTL) (Vqwf c, Vdwf l)
{
#define     VQWF_VSTL(C, L) vcombine_f32(L, vget_high_f32(C))
    return  VQWF_VSTL(c, l);
}


INLINE(Vqdu,VQDU_VSTL) (Vqdu c, Vddu l)
{
#define     VQDU_VSTL(C, L) vcombine_u64(L, vget_high_u64(C))
    return  VQDU_VSTL(c, l);
}

INLINE(Vqdi,VQDI_VSTL) (Vqdi c, Vddi l)
{
#define     VQDI_VSTL(C, L) vcombine_s64(L, vget_high_s64(C))
    return  VQDI_VSTL(c, l);
}

INLINE(Vqdf,VQDF_VSTL) (Vqdf c, Vddf l)
{
#define     VQDF_VSTL(C, L) vcombine_f64(L, vget_high_f64(C))
    return  VQDF_VSTL(c, l);
}

#if _LEAVE_EXTGOP_ARM_VSTL
}
#endif

#if _ENTER_EXTGOP_ARM_VSTR
{
#endif

INLINE(Vdyu,VDYU_VSTR) (Vdyu c, Vwyu r)
{
#define     VDYU_VSTR(C, R) \
VDWF_ASYU(vset_lane_f32(VWYU_ASTM(R), VDYU_ASWF(C), V2_K1))
    return  VDYU_VSTR(c, r);
}

INLINE(Vdbu,VDBU_VSTR) (Vdbu c, Vwbu r)
{
#define     VDBU_VSTR(C, R) \
VDWF_ASBU(vset_lane_f32(VWBU_ASTM(R), VDBU_ASWF(C), V2_K1))
    return  VDBU_VSTR(c, r);
}

INLINE(Vdbi,VDBI_VSTR) (Vdbi c, Vwbi r)
{
#define     VDBI_VSTR(C, R) \
VDWF_ASBI(vset_lane_f32(VWBI_ASTM(R), VDBI_ASWF(C), V2_K1))
    return  VDBI_VSTR(c, r);
}

INLINE(Vdbc,VDBC_VSTR) (Vdbc c, Vwbu r)
{
#define     VDBC_VSTR(C, R) \
VDWF_ASBC(vset_lane_f32(VWBC_ASTM(R), VDBC_ASWF(C), V2_K1))
    return  VDBC_VSTR(c, r);
}


INLINE(Vdhu,VDHU_VSTR) (Vdhu c, Vwhu r)
{
#define     VDHU_VSTR(C, R) \
VDWF_ASHU(vset_lane_f32(VWHU_ASTM(R), VDHU_ASWF(C), V2_K1))
    return  VDHU_VSTR(c, r);
}

INLINE(Vdhi,VDHI_VSTR) (Vdhi c, Vwhi r)
{
#define     VDHI_VSTR(C, R) \
VDWF_ASHI(vset_lane_f32(VWHI_ASTM(R), VDHI_ASWF(C), V2_K1))
    return  VDHI_VSTR(c, r);
}

INLINE(Vdhf,VDHF_VSTR) (Vdhf c, Vwhf r)
{
#define     VDHF_VSTR(C, R) \
VDWF_ASHF(vset_lane_f32(VWHF_ASTM(R), VDHF_ASWF(C), V2_K1))
    return  VDHF_VSTR(c, r);
}


INLINE(Vdwu,VDWU_VSTR) (Vdwu c, Vwwu r)
{
#define     VDWU_VSTR(C, R) \
VDWF_ASWU(vset_lane_f32(VWWU_ASTM(R), VDWU_ASWF(C), V2_K1))
    return  VDWU_VSTR(c, r);
}

INLINE(Vdwi,VDWI_VSTR) (Vdwi c, Vwwi r)
{
#define     VDWI_VSTR(C, R) \
VDWF_ASWI(vset_lane_f32(VWWI_ASTM(R), VDWI_ASWF(C), V2_K1))
    return  VDWI_VSTR(c, r);
}

INLINE(Vdwf,VDWF_VSTR) (Vdwf c, Vwwf r)
{
#define     VDWF_VSTR(C, R) vset_lane_f32(VWWF_ASTM(R), C, V2_K1)
    return  VDWF_VSTR(c, r);
}


INLINE(Vqyu,VQYU_VSTR) (Vqyu c, Vdyu r)
{
#define     VQYU_VSTR(C, R)         \
QYU_ASTV(                           \
    vcombine_u64(                   \
        vget_low_u64(VQYU_ASTM(C)), \
        VDYU_ASTM(R)                \
    )                               \
)

    return  VQYU_VSTR(c, r);
}

INLINE(Vqbu,VQBU_VSTR) (Vqbu c, Vdbu r)
{
#define     VQBU_VSTR(C, R)     vcombine_u8(vget_low_u8(C), R)
    return  VQBU_VSTR(c, r);
}

INLINE(Vqbi,VQBI_VSTR) (Vqbi c, Vdbi r)
{
#define     VQBI_VSTR(C, R)     vcombine_s8(vget_low_s8(C), R)
    return  VQBI_VSTR(c, r);
}

INLINE(Vqbc,VQBC_VSTR) (Vqbc c, Vdbc r)
{
#define     VQBC_VSTR(C, R)         \
VQDU_ASBC(                          \
    vcombine_u64(                   \
        vget_low_u64(VQBC_ASDU(C)), \
        VDBC_ASDU(R)                \
    )                               \
)
    return  VQBC_VSTR(c, r);
}


INLINE(Vqhu,VQHU_VSTR) (Vqhu c, Vdhu r)
{
#define     VQHU_VSTR(C, R)     vcombine_u16(vget_low_u16(C), R)
    return  VQHU_VSTR(c, r);
}

INLINE(Vqhi,VQHI_VSTR) (Vqhi c, Vdhi r)
{
#define     VQHI_VSTR(C, R)     vcombine_s16(vget_low_s16(C), R)
    return  VQHI_VSTR(c, r);
}

INLINE(Vqhf,VQHF_VSTR) (Vqhf c, Vdhf r)
{
#define     VQHF_VSTR(C, R)     vcombine_f16(vget_low_f16(C), R)
    return  VQHF_VSTR(c, r);
}


INLINE(Vqwu,VQWU_VSTR) (Vqwu c, Vdwu r)
{
#define     VQWU_VSTR(C, R)     vcombine_u32(vget_low_u32(C), R)
    return  VQWU_VSTR(c, r);
}

INLINE(Vqwi,VQWI_VSTR) (Vqwi c, Vdwi r)
{
#define     VQWI_VSTR(C, R)     vcombine_s32(vget_low_s32(C), R)
    return  VQWI_VSTR(c, r);
}

INLINE(Vqwf,VQWF_VSTR) (Vqwf c, Vdwf r)
{
#define     VQWF_VSTR(C, R)     vcombine_f32(vget_low_f32(C), R)
    return  VQWF_VSTR(c, r);
}


INLINE(Vqdu,VQDU_VSTR) (Vqdu c, Vddu r)
{
#define     VQDU_VSTR(C, R)     vcombine_u64(vget_low_u64(C), R)
    return  VQDU_VSTR(c, r);
}

INLINE(Vqdi,VQDI_VSTR) (Vqdi c, Vddi r)
{
#define     VQDI_VSTR(C, R)     vcombine_s64(vget_low_s64(C), R)
    return  VQDI_VSTR(c, r);
}

INLINE(Vqdf,VQDF_VSTR) (Vqdf c, Vddf r)
{
#define     VQDF_VSTR(C, R)     vcombine_f64(vget_low_f64(C), R)
    return  VQDF_VSTR(c, r);
}

#if _LEAVE_EXTGOP_ARM_VSTR
}
#endif


#if _ENTER_EXTGOP_ARM_VST1
{
#endif

INLINE(Vwyu,VWYU_VST1) (Vwyu d, Rc(0,31) k, _Bool v)
{
#define     VWYU_VST1   VWYU_VST1
    float32x2_t w = vdup_n_f32(VWYU_ASTM(d));
    int64x1_t   s = vdup_n_s64(k);
    uint64x1_t  m = vshl_u64(vdup_n_u64(1), s);
    uint64x1_t  y = vbic_u64(VDWF_ASDU(w), m);
    y = vorr_u64(y, vshl_u64(vdup_n_u64(v), s));
    return  WYU_ASTV(vget_lane_f32(VDDU_ASWF(y), V2_K0));
}

INLINE(Vwbu,VWBU_VST1) (Vwbu d, Rc(0, 3) k, uint8_t v)
{
#define     WBU_VST1(D, K, V)   \
vget_lane_f32(                  \
    vreinterpret_f32_u8(        \
        vset_lane_u8(           \
            (V),                \
            vreinterpret_u8_f32(\
                vdup_n_f32(D)   \
            ),                  \
            (K)                 \
        )                       \
    ),                          \
    V2_K0                       \
)

#define     VWBU_VST1(D, K, V)  WBU_ASTV(WBU_VST1(VWBU_ASTM(D), K, V))
    float32x2_t w = vdup_n_f32(VWBU_ASTM(d));
    int64x1_t   s = vdup_n_s64(k*8);
    uint64x1_t  m = vdup_n_u64(0xffull);
    m = vshl_u64(m, s);
    m = vbic_u64(m, vreinterpret_u64_f32(w));
    m = vorr_u64(m, vshl_u64(vdup_n_u64(v), s));
    return  WBU_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u64(m),
            V2_K0
        )
    );
}

INLINE(Vwbi,VWBI_VST1) (Vwbi d, Rc(0, 3) k, int8_t v)
{
#define     WBI_VST1(D, K, V)   \
vget_lane_f32(                  \
    vreinterpret_f32_s8(        \
        vset_lane_s8(           \
            (V),                \
            vreinterpret_s8_f32(\
                vdup_n_f32(D)   \
            ),                  \
            (K)                 \
        )                       \
    ),                          \
    V2_K0                       \
)

#define     VWBI_VST1(D, K, V)  WBI_ASTV(WBI_VST1(VWBI_ASTM(D), K, V))
    float32x2_t w = vdup_n_f32(VWBI_ASTM(d));
    int64x1_t   s = vdup_n_s64(k*8);
    uint64x1_t  m = vdup_n_u64(0xffull);
    m = vshl_u64(m, s);
    m = vbic_u64(m, vreinterpret_u64_f32(w));
    m = vorr_u64(m, vshl_u64(vdup_n_u64(v), s));
    return  WBI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u64(m),
            V2_K0
        )
    );
}

INLINE(Vwbc,VWBC_VST1) (Vwbc d, Rc(0, 3) k, char v)
{
#if CHAR_MIN
#   define  WBC_VST1(D, K, V)   \
vget_lane_f32(                  \
    vreinterpret_f32_s8(        \
        vset_lane_s8(           \
            (V),                \
            vreinterpret_s8_f32(\
                vdup_n_f32(D)   \
            ),                  \
            (K)                 \
        )                       \
    ),                          \
    V2_K0                       \
)

#else
#   define  WBC_VST1(D, K, V)   \
vget_lane_f32(                  \
    vreinterpret_f32_u8(        \
        vset_lane_u8(           \
            (V),                \
            vreinterpret_u8_f32(\
                vdup_n_f32(D)   \
            ),                  \
            (K)                 \
        )                       \
    ),                          \
    V2_K0                       \
)

#endif

#define     VWBC_VST1(D, K, V)  WBC_ASTV(WBC_VST1(VWBC_ASTM(D), K, V))
    float32x2_t w = vdup_n_f32(VWBC_ASTM(d));
    int64x1_t   s = vdup_n_s64(k*8);
    uint64x1_t  m = vdup_n_u64(0xffull);
    m = vshl_u64(m, s);
    m = vbic_u64(m, vreinterpret_u64_f32(w));
    m = vorr_u64(m, vshl_u64(vdup_n_u64(v), s));
    return  WBC_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u64(m),
            V2_K0
        )
    );
}

INLINE(Vwhu,VWHU_VST1) (Vwhu d, Rc(0, 1) k, uint16_t v)
{
#define     WHU_VST1(D, K, V)   \
vget_lane_f32(                  \
    vreinterpret_f32_u16(       \
        vset_lane_u16(          \
            (V),                \
            VDWF_ASHU(          \
                vdup_n_f32(D)   \
            ),                  \
            (K)                 \
        )                       \
    ),                          \
    V2_K0                       \
)

#define     VWHU_VST1(D, K, V)  WHU_ASTV(WHU_VST1(VWHU_ASTM(D), K, V))
    float32x2_t w = vdup_n_f32(VWHU_ASTM(d));
    int64x1_t   s = vdup_n_s64(k*16);
    uint64x1_t  m = vdup_n_u64(0xffffull);
    m = vshl_u64(m, s);
    m = vbic_u64(m, vreinterpret_u64_f32(w));
    m = vorr_u64(m, vshl_u64(vdup_n_u64(v), s));
    return  WHU_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u64(m),
            V2_K0
        )
    );
}

INLINE(Vwhi,VWHI_VST1) (Vwhi d, Rc(0, 1) k, int16_t v)
{
#define     WHI_VST1(D, K, V)   \
vget_lane_f32(                  \
    vreinterpret_f32_s16(       \
        vset_lane_s16(          \
            (V),                \
            VDWF_ASHI(          \
                vdup_n_f32(D)   \
            ),                  \
            (K)                 \
        )                       \
    ),                          \
    V2_K0                       \
)

#define     VWHI_VST1(D, K, V)  WHI_ASTV(WHI_VST1(VWHI_ASTM(D), K, V))
    float32x2_t w = vdup_n_f32(VWHI_ASTM(d));
    int64x1_t   s = vdup_n_s64(k*16);
    uint64x1_t  m = vdup_n_u64(0xffffull);
    m = vshl_u64(m, s);
    m = vbic_u64(m, vreinterpret_u64_f32(w));
    m = vorr_u64(m, vshl_u64(vdup_n_u64(v), s));
    return  WHI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u64(m),
            V2_K0
        )
    );
}

INLINE(Vwhf,VWHF_VST1) (Vwhf d, Rc(0, 1) k, flt16_t v)
{
#define     WHF_VST1(D, K, V)   \
vget_lane_f32(                  \
    vreinterpret_f32_f16(       \
        vset_lane_f16(          \
            (V),                \
            VDWF_ASHF(          \
                vdup_n_f32(D)   \
            ),                  \
            (K)                 \
        )                       \
    ),                          \
    V2_K0                       \
)

#define     VWHF_VST1(D, K, V)  WHF_ASTV(WHF_VST1(VWHF_ASTM(D), K, V))
    float32x2_t w = vdup_n_f32(VWHF_ASTM(d));
    int64x1_t   s = vdup_n_s64(k*16);
    uint64x1_t  m = vdup_n_u64(0xffffull);
    uint64x1_t  h = vdup_n_u64(FLT16_ASHU(v));
    m = vshl_u64(m, s);
    m = vbic_u64(m, vreinterpret_u64_f32(w));
    m = vorr_u64(m, vshl_u64(h, s));
    return  WHF_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u64(m),
            V2_K0
        )
    );
}


INLINE(Vdyu,VDYU_VST1) (Vdyu d, Rc(0,63) k, _Bool v)
{
#define     VDYU_VST1   VDYU_VST1
    int64x1_t   s = vdup_n_s64(k);
    uint64x1_t  m = vshl_u64(vdup_n_u64(1), s);
    uint64x1_t  y = vbic_u64(m, VDYU_ASTM(d));
    return DYU_ASTV(vorr_u64(y, vshl_u64(vdup_n_u64(v), s)));
}

INLINE(Vdbu,VDBU_VST1) (Vdbu d, Rc(0, 7) k, uint8_t v)
{
#define     VDBU_VST1(D, K, V)  vset_lane_u8(V, D, K)
    int64x1_t  s = vdup_n_s64(k*8);
    uint64x1_t m = vdup_n_u64(0xffull);
    m = vshl_u64(m, s);
    m = vbic_u64(vreinterpret_u64_u8(d), m);
    m = vorr_u64(vshl_u64(vdup_n_u64(v), s), m);
    return  vreinterpret_u8_u64(m);
}

INLINE(Vdbi,VDBI_VST1) (Vdbi d, Rc(0, 7) k, int8_t v)
{
#define     VDBI_VST1(D, K, V)  vset_lane_u8(V, D, K)
    int64x1_t  s = vdup_n_s64(k*8);
    uint64x1_t m = vdup_n_u64(0xffull);
    m = vshl_u64(m, s);
    m = vbic_u64(vreinterpret_u64_s8(d), m);
    m = vorr_u64(vshl_u64(vdup_n_u64(v), s), m);
    return  vreinterpret_s8_u64(m);
}

INLINE(Vdbc,VDBC_VST1) (Vdbc d, Rc(0, 7) k, char v)
{
#if CHAR_MIN
#   define  VDBC_VST1(D, K, V)  DBC_ASTV(vset_lane_s8(V, VDBC_ASTM(D), K))
#else
#   define  VDBC_VST1(D, K, V)  DBC_ASTV(vset_lane_u8(V, VDBC_ASTM(D), K))
#endif

    int64x1_t   s = vdup_n_s64(k*8);
    uint64x1_t  m = VDBC_ASDU(d);
    uint64x1_t  x;
    x = vshl_u64(vdup_n_u64(0xffull), s);
    x = vbic_u64(m, x);
    x = vorr_u64(x, vshl_u64(vdup_n_u64(v), s));
    return VDDU_ASBC(x);
}


INLINE(Vdhu,VDHU_VST1) (Vdhu d, Rc(0, 3) k, uint16_t v)
{
#define     VDHU_VST1(D, K, V)  vset_lane_u16(V, D, K)
    int64x1_t  s = vdup_n_s64(k*16);
    uint64x1_t m = vdup_n_u64(0xffffull);
    m = vshl_u64(m, s);
    m = vbic_u64(vreinterpret_u64_u16(d), m);
    m = vorr_u64(vshl_u64(vdup_n_u64(v), s), m);
    return vreinterpret_u16_u64(m);
}

INLINE(Vdhi,VDHI_VST1) (Vdhi d, Rc(0, 3) k, int16_t v)
{
#define     VDHI_VST1(D, K, V)  vset_lane_s16(V, D, K)
    int64x1_t   s = vdup_n_s64(k*16);
    uint64x1_t  x = vdup_n_u64(0xffffull);
    x = vshl_u64(x, s);
    x = vbic_u64(x, vreinterpret_u64_s16(d));
    x = vorr_u64(x, vshl_u64(vdup_n_u64(0xffffull&v), s));
    return vreinterpret_s16_u64(x);
}

INLINE(Vdhf,VDHF_VST1) (Vdhf d, Rc(0, 3) k, flt16_t v)
{
#define     VDHF_VST1(D, K, V)  vset_lane_f16(V, D, K)
    int64x1_t   s = vdup_n_s64(k*16);
    uint64x1_t  m = vdup_n_u64(0xffffull);
    uint64x1_t  h = vdup_n_u64(FLT16_ASHU(v));
    m = vshl_u64(m, s);
    m = vbic_u64(vreinterpret_u64_u16(d), m);
    m = vorr_u64(vshl_u64(h, s), m);
    return  vreinterpret_f16_u64(m);
}


INLINE(Vdwu,VDWU_VST1) (Vdwu d, Rc(0, 1) k, uint32_t v)
{
#define     VDWU_VST1(D, K, V)  vset_lane_u32(V, D, K)
    int64x1_t  s = vdup_n_s64(k*32);
    uint64x1_t m = vdup_n_u64(0xffffffffull);
    m = vshl_u64(m, s);
    m = vbic_u64(vreinterpret_u64_u32(d), m);
    m = vorr_u64(vshl_u64(vdup_n_u64(v), s), m);
    return  vreinterpret_u32_u64(m);
}

INLINE(Vdwi,VDWI_VST1) (Vdwi d, Rc(0, 1) k, int32_t v)
{
#define     VDWI_VST1(D, K, V)  vset_lane_s32(V, D, K)
    int64x1_t  s = vdup_n_s64(k*32);
    uint64x1_t m = vdup_n_u64(0xffffffffull);
    m = vshl_u64(m, s);
    m = vbic_u64(vreinterpret_u64_s32(d), m);
    m = vorr_u64(vshl_u64(vdup_n_u64(v), s), m);
    return  vreinterpret_s32_u64(m);
}

INLINE(Vdwf,VDWF_VST1) (Vdwf d, Rc(0, 1) k, float v)
{
#define     VDWF_VST1(D, K, V)  vset_lane_f32(V, D, K)
    int64x1_t  s = vdup_n_s64(k*32);
    uint64x1_t m = vdup_n_u64(0xffffffffull);
    WORD_TYPE  w = {.F=v};
    m = vshl_u64(m, s);
    m = vbic_u64(vreinterpret_u64_f32(d), m);
    m = vorr_u64(vshl_u64(vdup_n_u64(w.U), s), m);
    return  vreinterpret_f32_u64(m);
}


INLINE(Vqyu,VQYU_VST1) (Vqyu d, Rc(0,127) k, _Bool v)
{
#define     VQYU_VST1   VQYU_VST1
    Vqdu  q = VQYU_ASTM(d);
    Vddu  l =  vget_low_u64(q);
    Vddu  r =  vget_high_u64(q);
    if (k > 63) 
        r = VDYU_ASTM(VDYU_VST1(DYU_ASTV(r), 63&k, v));
    else 
        l = VDYU_ASTM(VDYU_VST1(DYU_ASTV(l), k,    v));
    q = vcombine_u64(l, r);
    return  QYU_ASTV(q);
}

INLINE(Vqbu,VQBU_VST1) (Vqbu d, Rc(0, 15) k, uint8_t v)
{
#define     VQBU_VST1(D, K, V)  vsetq_lane_u8(V, D, K)
    uint8x8_t l = vget_low_u8(d);
    uint8x8_t r = vget_high_u8(d);
    if (k > 7)
        r = (VDBU_VST1)(r, 7&k, v);
    else 
        l = (VDBU_VST1)(l,   k, v);
    return  vcombine_u8(l, r);
}

INLINE(Vqbi,VQBI_VST1) (Vqbi d, Rc(0, 15) k, int8_t v)
{
#define     VQBI_VST1(D, K, V)  vsetq_lane_s8(V, D, K)
    int8x8_t l = vget_low_s8(d);
    int8x8_t r = vget_high_s8(d);
    if (k > 7)
        r = (VDBI_VST1)(r, 7&k, v);
    else 
        l = (VDBI_VST1)(l,   k, v);
    return  vcombine_u8(l, r);
}

INLINE(Vqbc,VQBC_VST1) (Vqbc d, Rc(0, 15) k, char v)
{
#if CHAR_MIN
#   define  QBC_VST1(M, K, V)   vsetq_lane_s8(V, M, K)
#else
#   define  QBC_VST1(M, K, V)   vsetq_lane_u8(V, M, K)
#endif

#define     VQBC_VST1(D, K, V)  QBC_ASTV(QBC_VST1(VQBC_ASTM(D), K, V))
    uint8x16_t  q = VQBC_ASBU(d);
    uint8x8_t   l = vget_low_u8(q);
    uint8x8_t   r = vget_high_u8(q);
    if (k > 7)
        r = (VDBU_VST1)(r, 7&k, v);
    else 
        l = (VDBU_VST1)(l,   k, v);
    return  VQBU_ASBC(vcombine_u8(l, r));
}


INLINE(Vqhu,VQHU_VST1) (Vqhu d, Rc(0, 7) k, uint16_t v)
{
#define     VQHU_VST1(D, K, V)  vsetq_lane_u16(V, D, K)
    uint16x4_t l = vget_low_u16(d);
    uint16x4_t r = vget_high_u16(d);
    if (k > 3)
        r = (VDHU_VST1)(r, 3&k, v);
    else 
        l = (VDHU_VST1)(l,  k,  v);
    return  vcombine_u16(l, r);
}

INLINE(Vqhi,VQHI_VST1) (Vqhi d, Rc(0, 7) k, int16_t v)
{
#define     VQHI_VST1(D, K, V)  vsetq_lane_s16(V, D, K)
    int16x4_t l = vget_low_s16(d);
    int16x4_t r = vget_high_s16(d);
    if (k > 3)
        r = (VDHI_VST1)(r, 3&k, v);
    else 
        l = (VDHI_VST1)(l,  k,  v);
    return  vcombine_s16(l, r);
}

INLINE(Vqhf,VQHF_VST1) (Vqhf d, Rc(0, 7) k, flt16_t v)
{
#define     VQHF_VST1(D, K, V)  vsetq_lane_f16(V, D, K)
    float16x4_t l = vget_low_f16(d);
    float16x4_t r = vget_high_f16(d);
    if (k > 3)
        r = (VDHF_VST1)(r, 3&k, v);
    else 
        l = (VDHF_VST1)(l,  k,  v);
    return  vcombine_f16(l, r);
}



INLINE(Vqwu,VQWU_VST1) (Vqwu d, Rc(0, 3) k, uint32_t v)
{
#define     VQWU_VST1(D, K, V)  vsetq_lane_u32(V, D, K)
    uint32x2_t l = vget_low_u32(d);
    uint32x2_t r = vget_high_u32(d);
    if (k > 1)
        r = (VDWU_VST1)(r, 1&k, v);
    else 
        l = (VDWU_VST1)(l,  k,  v);
    return  vcombine_u32(l, r);
}

INLINE(Vqwi,VQWI_VST1) (Vqwi d, Rc(0, 3) k, int32_t v)
{
#define     VQWI_VST1(D, K, V)  vsetq_lane_s32(V, D, K)
    int32x2_t l = vget_low_s32(d);
    int32x2_t r = vget_high_s32(d);
    if (k > 1)
        r = (VDWI_VST1)(r, 1&k, v);
    else 
        l = (VDWI_VST1)(l,  k,  v);
    return  vcombine_s32(l, r);
}

INLINE(Vqwf,VQWF_VST1) (Vqwf d, Rc(0, 3) k, float v)
{
#define     VQWF_VST1(D, K, V)  vsetq_lane_f32(V, D, K)
    float32x2_t l = vget_low_f32(d);
    float32x2_t r = vget_high_f32(d);
    if (k > 1)
        r = (VDWF_VST1)(r, 1&k, v);
    else 
        l = (VDWF_VST1)(l,  k,  v);
    return  vcombine_f32(l, r);
}

INLINE(Vqdu,VQDU_VST1) (Vqdu d, Rc(0, 1) k, uint64_t v)
{
#define     VQDU_VST1(D, K, V) vsetq_lane_u64(V, D, K)
    return k
    ?   vsetq_lane_u64(v, d, V2_K1)
    :   vsetq_lane_u64(v, d, V2_K0);
}

INLINE(Vqdi,VQDI_VST1) (Vqdi d, Rc(0, 1) k, int64_t v)
{
#define     VQDI_VST1(D, K, V) vsetq_lane_s64(V, D, K)
    return k
    ?   vsetq_lane_s64(v, d, V2_K1)
    :   vsetq_lane_s64(v, d, V2_K0);
}

INLINE(Vqdf,VQDF_VST1) (Vqdf d, Rc(0, 1) k, double v)
{
#define     VQDF_VST1(D, K, V) vsetq_lane_f64(V, D, K)
    return k
    ?   vsetq_lane_f64(v, d, V2_K1)
    :   vsetq_lane_f64(v, d, V2_K0);
}

#if _LEAVE_EXTGOP_ARM_VST1
}
#endif

#if _LEAVE_EXTGOP_ARM_VST_
}
#endif




#if _ENTER_EXTGOP_ARM_LDR1
{
#endif

INLINE(Vwyu,VWYU_LDR1) (Vwyu v, Rc(0, 31) k, _Bool volatile const a[1])
{
#define     VWYU_LDR1   VWYU_LDR1
    uint32x2_t  m = vreinterpret_u32_f32(vdup_n_f32(VWYU_ASTM(v)));
    m = vbic_u32(m, vdup_n_u32(1u<<k));
    m = vorr_u32(m, vdup_n_u32((uint32_t) *a<<k));
    return WYU_ASTV(vget_lane_f32(vreinterpret_f32_u32(m), V2_K0));
}

INLINE(Vwbu,VWBU_LDR1) (Vwbu v, Rc(0, 3) k, uint8_t volatile const a[1])
{
#define     WBU_LDR1(M, K, A)       \
vget_lane_f32(                      \
    vreinterpet_f32_u8(             \
        vld1_lane_u8(               \
            (uint8_t *)(A),         \
            vreinterpret_u8_f32(    \
                vdup_n_f32(M)       \
            ),                      \
            K                       \
        )                           \
    ),                              \
    V2_K0                           \
)

#define     VWBU_LDR1(V,K,A)        \
WBU_ASTV(WBU_LDR1(VWBU_ASTM(V), K, A))

    int64x1_t   s = vdup_n_s64(0ll-8*k);
    float32x2_t m = vdup_n_f32(VWBU_ASTM(v));
    uint64x1_t  d = vreinterpret_u64_f32(m);
    uint8x8_t   b = vset_lane_u8(*a, vdup_n_u8(0), 0);
    d = vbic_u64(d, vshl_u64(vdup_n_u64(255ull), s));
    d = vorr_u64(d, vshl_u64(vreinterpret_u64_u8(b), s));
    m = vreinterpret_f32_u64(d);
    return WBU_ASTV(vget_lane_f32(m, V2_K0));
}

#if _LEAVE_EXTGOP_ARM_LDR1
}
#endif

#if _ENTER_EXTGOP_ARM_LDRW
{
#endif

INLINE(Vwyu,BOOL_LDRW) (_Bool volatile const src[4])
{
#define     BOOL_LDRW      BOOL_LDRW
    return  *(VWYU_TYPE volatile *) src;
}

INLINE(Vwbu,UCHAR_LDRW) (unsigned char volatile const src[4])
{
#define     UCHAR_LDRW      UCHAR_LDRW
    return  *(VWBU_TYPE volatile *) src;
}

INLINE(Vwbi,SCHAR_LDRW) (signed char volatile const src[4])
{
#define     SCHAR_LDRW      SCHAR_LDRW
    return  *(VWBI_TYPE volatile *) src;
}

INLINE(Vwbc,CHAR_LDRW) (char volatile const src[4])
{
#define     CHAR_LDRW       CHAR_LDRW
    return  *(VWBC_TYPE volatile *) src;
}

INLINE(Vwhu,USHRT_LDRW) (unsigned short volatile const src[2])
{
#define     USHRT_LDRW      USHRT_LDRW
    return *(VWHU_TYPE volatile *) src;
}

INLINE(Vwhi,SHRT_LDRW) (short volatile const src[2])
{
#define     SHRT_LDRW       SHRT_LDRW
    return  *(VWHI_TYPE volatile *) src;
}

INLINE(Vwwu,UINT_LDRW) (unsigned int volatile const src[1])
{
#define     UINT_LDRW      UINT_LDRW
    return *(VWWU_TYPE volatile *) src;
}

INLINE(Vwwi,INT_LDRW) (int volatile const src[1])
{
#define     INT_LDRW       INT_LDRW
    return  *(VWWI_TYPE volatile *) src;
}

INLINE(Vwhf,FLT16_LDRW) (flt16_t volatile const src[2])
{
#define     FLT16_LDRW      FLT16_LDRW
    return  *(VWHF_TYPE volatile *) src;
}

INLINE(Vwwf,FLT_LDRW) (float volatile const src[1])
{
#define     FLT_LDRW        FLT_LDRW
    return  *(VWWF_TYPE volatile *) src;
}

#if DWRD_NLONG == 2

INLINE(Vwwu,ULONG_LDRW) (unsigned long volatile const src[1])
{
#define     ULONG_LDRW  ULONG_LDRW
    return *(VWWU_TYPE volatile *) src;
}

INLINE(Vwwi,LONG_LDRW) (long volatile const src[1])
{
#define     LONG_LDRW    LONG_LDRW
    return  *(VWWI_TYPE volatile *) src;
}

#endif

#if _LEAVE_EXTGOP_ARM_LDRW
}
#endif


#if _ENTER_EXTGOP_ARM_LDRD
{
#endif


INLINE(Vdyu,BOOL_LDRD) (void volatile const *src)
{
#define MY_LDRD(a)  vdup_n_u64(*(uint64_t volatile *)(a))
    return  DYU_ASTV(MY_LDRD(src));
}


INLINE(Vdbu,UCHAR_LDRD) (unsigned char volatile const src[8])
{
#define     UCHAR_LDRD      UCHAR_LDRD
    return  vreinterpret_u8_u64(MY_LDRD(src));
}

INLINE(Vdbi,SCHAR_LDRD) (signed char volatile const src[8])
{
#define     SCHAR_LDRD      SCHAR_LDRD
    return  vreinterpret_s8_u64(MY_LDRD(src));
}

INLINE(Vdbc,CHAR_LDRD) (char volatile const src[8])
{
#define     CHAR_LDRD       CHAR_LDRD
    return  VDBU_ASBC(vreinterpret_u8_u64(MY_LDRD(src)));
}


INLINE(Vdhu,USHRT_LDRD) (unsigned short volatile const src[4])
{
#define     USHRT_LDRD      USHRT_LDRD
    return  vreinterpret_u16_u64(MY_LDRD(src));
}

INLINE(Vdhi,SHRT_LDRD) (short volatile const src[4])
{
#define     SHRT_LDRD       SHRT_LDRD
    return  vreinterpret_s16_u64(MY_LDRD(src));
}


INLINE(Vdwu,UINT_LDRD) (unsigned int volatile const src[2])
{
#define     UINT_LDRD      UINT_LDRD
    return  vreinterpret_u32_u64(MY_LDRD(src));
}

INLINE(Vdwi,INT_LDRD) (int volatile const src[2])
{
#define     INT_LDRD       INT_LDRD
    return  vreinterpret_s32_u64(MY_LDRD(src));
}


#if DWRD_NLONG == 2

INLINE(Vdwu,ULONG_LDRD) (unsigned long volatile const src[2])
{
#define     ULONG_LDRD  ULONG_LDRD
    return  vreinterpret_u32_u64(MY_LDRD(src));
}

INLINE(Vdwi, LONG_LDRD) (long volatile const src[2])
{
#define     LONG_LDRD    LONG_LDRD
    return  vreinterpret_s32_u64(MY_LDRD(src));
}

#else

INLINE(Vddu,ULONG_LDRD) (unsigned long volatile const src[1])
{
#define     ULONG_LDRD  ULONG_LDRD
    return  MY_LDRD(src);
}

INLINE(Vddi, LONG_LDRD) (long volatile const src[1])
{
#define     LONG_LDRD    LONG_LDRD
    return  vreinterpret_s64_u64(MY_LDRD(src));
}

#endif

INLINE(Vddu,ULLONG_LDRD) (unsigned long long volatile const src[1])
{
#define     ULLONG_LDRD  ULLONG_LDRD
    return  MY_LDRD(src);
}

INLINE(Vddi,LLONG_LDRD) (long long volatile const src[1])
{
#define     LONG_LDRD    LONG_LDRD
    return  vreinterpret_s64_u64(MY_LDRD(src));
}


INLINE(Vdhf,FLT16_LDRD) (flt16_t volatile const src[4])
{
#define     FLT16_LDRD      FLT16_LDRD
    return  vreinterpret_f16_u64(MY_LDRD(src));
}

INLINE(Vdwf,FLT_LDRD) (float volatile const src[2])
{
#define     FLT_LDRD        FLT_LDRD
    return  vreinterpret_s64_u64(MY_LDRD(src));
}

INLINE(Vddf,DBL_LDRD) (double volatile const src[1])
{
#define     DBL_LDRD        DBL_LDRD
    return  vreinterpret_f64_u64(MY_LDRD(src));
}

#if _LEAVE_EXTGOP_ARM_LDRD
}
#endif


#if _ENTER_EXTGOP_ARM_LDRQ
{
#endif

INLINE(Vqyu,BOOL_LDRQ) (void volatile const *src)
{
#define MY_LDRQ(a)  (*(unsigned __int128 volatile *)(a))
    return  QYU_ASTV(vreinterpretq_u64_p128(MY_LDRQ(src)));
}

INLINE(Vqbu,UCHAR_LDRQ) (unsigned char volatile const src[16])
{
#define     UCHAR_LDRQ      UCHAR_LDRQ
    return  vreinterpretq_u8_p128(MY_LDRQ(src));
}

INLINE(Vqbi,SCHAR_LDRQ) (signed char volatile const src[16])
{
#define     SCHAR_LDRQ      SCHAR_LDRQ
    return  vreinterpretq_s8_p128(MY_LDRQ(src));
}

INLINE(Vqbc,CHAR_LDRQ) (char volatile const src[16])
{
#define     CHAR_LDRQ       CHAR_LDRQ
    return  VQBU_ASBC(vreinterpretq_u8_p128(MY_LDRQ(src)));
}


INLINE(Vqhu,USHRT_LDRQ) (unsigned short volatile const src[8])
{
#define     USHRT_LDRQ      USHRT_LDRQ
    return  vreinterpretq_u16_p128(MY_LDRQ(src));
}

INLINE(Vqhi,SHRT_LDRQ) (short volatile const src[8])
{
#define     SHRT_LDRQ       SHRT_LDRQ
    return  vreinterpretq_s16_p128(MY_LDRQ(src));
}


INLINE(Vqwu,UINT_LDRQ) (unsigned int volatile const src[4])
{
#define     UINT_LDRQ      UINT_LDRQ
    return  vreinterpretq_u32_p128(MY_LDRQ(src));
}

INLINE(Vqwi,INT_LDRQ) (int volatile const src[4])
{
#define     INT_LDRQ       INT_LDRQ
    return  vreinterpretq_s32_p128(MY_LDRQ(src));
}

#if DWRD_NLONG == 2

INLINE(Vqwu,ULONG_LDRQ) (unsigned long volatile const src[4])
{
#define     ULONG_LDRQ  ULONG_LDRQ
    return  vreinterpretq_u32_p128(MY_LDRQ(src));
}

INLINE(Vqwi, LONG_LDRQ) (long volatile const src[4])
{
#define     LONG_LDRQ    LONG_LDRQ
    return  vreinterpretq_s32_p128(MY_LDRQ(src));
}

#else

INLINE(Vqdu,ULONG_LDRQ) (unsigned long volatile const src[2])
{
#define     ULONG_LDRQ  ULONG_LDRQ
    return  vreinterpretq_u64_p128(MY_LDRQ(src));
}

INLINE(Vqdi, LONG_LDRQ) (long volatile const src[2])
{
#define     LONG_LDRQ    LONG_LDRQ
    return  vreinterpretq_s64_p128(MY_LDRQ(src));
}

#endif

INLINE(Vqdu,ULLONG_LDRQ) (unsigned long long volatile const src[2])
{
#define     ULLONG_LDRQ  ULLONG_LDRQ
    return  vreinterpretq_u64_p128(MY_LDRQ(src));
}

INLINE(Vqdi,LLONG_LDRQ) (long long volatile const src[2])
{
#define     LONG_LDRQ    LONG_LDRQ
    return  vreinterpretq_s64_p128(MY_LDRQ(src));
}


INLINE(Vqhf,FLT16_LDRQ) (flt16_t volatile const src[8])
{
#define     FLT16_LDRQ      FLT16_LDRQ
    return  vreinterpretq_f16_p128(MY_LDRQ(src));
}

INLINE(Vqwf,FLT_LDRQ) (float volatile const src[4])
{
#define     FLT_LDRQ        FLT_LDRQ
    return  vreinterpretq_f32_p128(MY_LDRQ(src));
}

INLINE(Vqdf,DBL_LDRQ) (double volatile const src[2])
{
#define     DBL_LDRQ        DBL_LDRQ
    return  vreinterpretq_f64_p128(MY_LDRQ(src));
}

#if _LEAVE_EXTGOP_ARM_LDRQ
}
#endif

#if _ENTER_EXTGOP_ARM_LDRO
{
#endif

#if CHAR_SIGNEDNESS
#   define  ABC_LDRO(p)     ((VOBI_TYPE){vld1q_s8_x2( (void const *)(p))})
#else
#   define  ABC_LDRO(p)     ((VOBU_TYPE){vld1q_u8_x2( (void const *)(p))})
#endif
#define     ABU_LDRO(p)     ((VOBU_TYPE){vld1q_u8_x2( (void const *)(p))})
#define     ABI_LDRO(p)     ((VOBI_TYPE){vld1q_s8_x2( (void const *)(p))})

#define     AHU_LDRO(p)     ((VOHU_TYPE){vld1q_u16_x2((void const *)(p))})
#define     AHI_LDRO(p)     ((VOHI_TYPE){vld1q_s16_x2((void const *)(p))})
#define     AHF_LDRO(p)     ((VOHF_TYPE){vld1q_f16_x2((void const *)(p))})

#define     AWU_LDRO(p)     ((VOWU_TYPE){vld1q_u32_x2((void const *)(p))})
#define     AWI_LDRO(p)     ((VOWI_TYPE){vld1q_s32_x2((void const *)(p))})
#define     AWF_LDRO(p)     ((VOWF_TYPE){vld1q_f32_x2((void const *)(p))})

#define     ADU_LDRO(p)     ((VODU_TYPE){vld1q_u64_x2((void const *)(p))})
#define     ADI_LDRO(p)     ((VODI_TYPE){vld1q_s64_x2((void const *)(p))})
#define     ADF_LDRO(p)     ((VODF_TYPE){vld1q_f64_x2((void const *)(p))})

#if _LEAVE_EXTGOP_ARM_LDRO
}
#endif

#if _ENTER_EXTGOP_ARM_LDRS
{
#endif

#if CHAR_SIGNEDNESS
#   define  ABC_LDRS(p)     ((VOBI_TYPE){vld1q_s8_x4( (void const *)(p))})
#else
#   define  ABC_LDRS(p)     ((VOBU_TYPE){vld1q_u8_x4( (void const *)(p))})
#endif
#define     ABU_LDRS(p)     ((VOBU_TYPE){vld1q_u8_x4( (void const *)(p))})
#define     ABI_LDRS(p)     ((VOBI_TYPE){vld1q_s8_x4( (void const *)(p))})

#define     AHU_LDRS(p)     ((VOHU_TYPE){vld1q_u16_x4((void const *)(p))})
#define     AHI_LDRS(p)     ((VOHI_TYPE){vld1q_s16_x4((void const *)(p))})
#define     AHF_LDRS(p)     ((VOHF_TYPE){vld1q_f16_x4((void const *)(p))})

#define     AWU_LDRS(p)     ((VOWU_TYPE){vld1q_u32_x4((void const *)(p))})
#define     AWI_LDRS(p)     ((VOWI_TYPE){vld1q_s32_x4((void const *)(p))})
#define     AWF_LDRS(p)     ((VOWF_TYPE){vld1q_f32_x4((void const *)(p))})

#define     ADU_LDRS(p)     ((VODU_TYPE){vld1q_u64_x4((void const *)(p))})
#define     ADI_LDRS(p)     ((VODI_TYPE){vld1q_s64_x4((void const *)(p))})
#define     ADF_LDRS(p)     ((VODF_TYPE){vld1q_f64_x4((void const *)(p))})

#if _LEAVE_EXTGOP_ARM_LDRS
}
#endif

#if _ENTER_EXTGOP_ARM_NEW_
{
#endif

#if _ENTER_EXTGOP_ARM_NEWL
{
#endif

#define     WBZ_NEWL(K0, K1, K2, K3)    \
vget_lane_f32(                          \
    vreinterpret_f32_u64(               \
        vdup_n_u64(                     \
            ((0xffull&(K0))<<000)       \
        |   ((0xffull&(K1))<<010)       \
        |   ((0xffull&(K2))<<020)       \
        |   ((0xffull&(K3))<<030)       \
        )                               \
    ),                                  \
    V2_K0                               \
)
#define     WBU_NEWL(K0, K1, K2, K3) WBZ_NEWL(K0, K1, K2, K3)
#define     WBI_NEWL(K0, K1, K2, K3) WBZ_NEWL(K0, K1, K2, K3)
#define     WBC_NEWL(K0, K1, K2, K3) WBZ_NEWL(K0, K1, K2, K3)

#define     WHZ_NEWL(K0, K1)        \
vget_lane_f32(                      \
    vreinterpret_f32_u64(           \
        vdup_n_u64(                 \
            ((0xffffull&(K0))<<000) \
        |   ((0xffffull&(K1))<<020) \
        )                           \
    ),                              \
    V2_K0                           \
)
#define     WHU_NEWL(...)   WHZ_NEWL(__VA_ARGS__)
#define     WHI_NEWL(...)   WHZ_NEWL(__VA_ARGS__)
#define     WHF_NEWL(K0, K1)    \
vget_lane_f32(                  \
    vreinterpret_f32_f16(       \
        MY_VSET2(               \
            V4,                 \
            vset_lane_f16,      \
            DHF_VOID,           \
            K0, K1              \
        )                       \
    ),                          \
    V2_K0                       \
)

#define     WWU_NEWL(K0)    ((union Word){.U=K0}).F
#define     WWI_NEWL(K0)    ((union Word){.I=K0}).F
#define     WWF_NEWL(K0)    ((union Word){.F=K0}).F

#define     DBZ_NEWL(T, K0, K1, K2, K3, K4, K5, K6, K7) \
vreinterpret##T(                \
    vdup_n_u64(                 \
        ((0xffull&(K0))<<000)   \
    |   ((0xffull&(K1))<<010)   \
    |   ((0xffull&(K2))<<020)   \
    |   ((0xffull&(K3))<<030)   \
    |   ((0xffull&(K4))<<040)   \
    |   ((0xffull&(K5))<<050)   \
    |   ((0xffull&(K6))<<060)   \
    |   ((0xffull&(K7))<<070)   \
    )\
)

#define     DBU_NEWL(...)   DBZ_NEWL(_u8_u64, __VA_ARGS__)
#define     DBI_NEWL(...)   DBZ_NEWL(_s8_u64, __VA_ARGS__)
#if CHAR_MIN
#   define  DBC_NEWL(...)   DBI_NEWL(__VA_ARGS__)
#else
#   define  DBC_NEWL(...)   DBU_NEWL(__VA_ARGS__)
#endif

#define     DHZ_NEWL(T, K0, K1, K2, K3) \
vreinterpret_##T(                       \
    vdup_n_u64(                         \
        ((0xffffull&(K0))<<000)         \
    |   ((0xffffull&(K1))<<020)         \
    |   ((0xffffull&(K2))<<040)         \
    |   ((0xffffull&(K3))<<060)         \
    )\
)


#define     DHU_NEWL(...)   DHZ_NEWL(u16_u64, __VA_ARGS__)
#define     DHI_NEWL(...)   DHZ_NEWL(s16_u64, __VA_ARGS__)
#define     DHF_NEWL(...)   MY_VSET4(V4, vset_lane_f16, DHF_VOID, __VA_ARGS__)

#define     DWZ_NEWL(T, K0, K1)     \
vreinterpret_##T(                   \
    vdup_n_u64(                     \
        ((0xffffffffull&(K0))<<000) \
    |   ((0xffffffffull&(K1))<<040) \
    )\
)

#define     DWU_NEWL(...)   DWZ_NEWL(u32_u64, __VA_ARGS__)
#define     DWI_NEWL(...)   DWZ_NEWL(s32_u64, __VA_ARGS__)
#define     DWF_NEWL(...)   MY_VSET2(V2, vset_lane_f32, DWF_VOID, __VA_ARGS__)

#define     DDU_NEWL        vdup_n_u64
#define     DDI_NEWL        vdup_n_s64
#define     DDF_NEWL        vdup_n_f64


#define     QBZ_NEWL(T,             \
    K0, K1, K2, K3, K4, K5, K6, K7, \
    K8, K9, K10,K11,K12,K13,K14,K15 \
)                                   \
vreinterpretq_##T(                  \
    vcombine_u64(                   \
        vdup_n_u64(                 \
            ((0xffull&(K0 ))<<000)  \
        |   ((0xffull&(K1 ))<<010)  \
        |   ((0xffull&(K2 ))<<020)  \
        |   ((0xffull&(K3 ))<<030)  \
        |   ((0xffull&(K4 ))<<040)  \
        |   ((0xffull&(K5 ))<<050)  \
        |   ((0xffull&(K6 ))<<060)  \
        |   ((0xffull&(K7 ))<<070)  \
        ),                          \
        vdup_n_u64(                 \
            ((0xffull&(K8 ))<<000)  \
        |   ((0xffull&(K9 ))<<010)  \
        |   ((0xffull&(K10))<<020)  \
        |   ((0xffull&(K11))<<030)  \
        |   ((0xffull&(K12))<<040)  \
        |   ((0xffull&(K13))<<050)  \
        |   ((0xffull&(K14))<<060)  \
        |   ((0xffull&(K15))<<070)  \
        )                           \
    )                               \
)
#define     QBU_NEWL(...)       QBZ_NEWL(u8_u64, __VA_ARGS__)
#define     QBI_NEWL(...)       QBZ_NEWL(s8_u64, __VA_ARGS__)
#if CHAR_MIN
#   define  QBC_NEWL(...)   QBI_NEWL(__VA_ARGS__)
#else
#   define  QBC_NEWL(...)   QBU_NEWL(__VA_ARGS__)
#endif

#define     QHZ_NEWL(T, K0, K1, K2, K3, K4, K5, K6, K7) \
vreinterpretq_##T(                  \
    vcombine_u64(                   \
        vdup_n_u64(                 \
            ((0xffffull&(K0))<<000) \
        |   ((0xffffull&(K1))<<020) \
        |   ((0xffffull&(K2))<<040) \
        |   ((0xffffull&(K3))<<060) \
        ),                          \
        vdup_n_u64(                 \
            ((0xffffull&(K4))<<000) \
        |   ((0xffffull&(K5))<<020) \
        |   ((0xffffull&(K6))<<040) \
        |   ((0xffffull&(K7))<<060) \
        )                           \
    )                               \
)
#define     QHU_NEWL(...)       QHZ_NEWL(u16_u64, __VA_ARGS__)
#define     QHI_NEWL(...)       QHZ_NEWL(s16_u64, __VA_ARGS__)
#define     QHF_NEWL(...)       \
MY_VSET8(V8, vsetq_lane_f16, QHF_VOID, __VA_ARGS__)

#define     QWZ_NEWL(T, K0, K1, K2, K3) \
vreinterpretq_##T(                      \
    vcombine_u64(                       \
        vdup_n_u64(                     \
            ((0xffffffffull&(K0))<<000) \
        |   ((0xffffffffull&(K1))<<040) \
        ),                              \
        vdup_n_u64(                     \
            ((0xffffffffull&(K2))<<000) \
        |   ((0xffffffffull&(K3))<<040) \
        )                               \
    )                                   \
)
#define     QWU_NEWL(...)       QWZ_NEWL(u32_u64, __VA_ARGS__)
#define     QWI_NEWL(...)       QWZ_NEWL(s32_u64, __VA_ARGS__)
#define     QWF_NEWL(...)       \
MY_VSET4(V4, vsetq_lane_f32, QWF_VOID, __VA_ARGS__)

#define     QDU_NEWL(K0, K1)    vcombine_u64(vdup_n_u64(K0), vdup_n_u64(K1))
#define     QDI_NEWL(K0, K1)    vcombine_s64(vdup_n_s64(K0), vdup_n_s64(K1))
#define     QDF_NEWL(K0, K1)    vcombine_f64(vdup_n_f64(K0), vdup_n_f64(K1))

#define     VWBU_NEWL(...)      ((VWBU_TYPE){WBU_NEWL(__VA_ARGS__)})
#define     VWBI_NEWL(...)      ((VWBI_TYPE){WBI_NEWL(__VA_ARGS__)})
#define     VWBC_NEWL(...)      ((VWBC_TYPE){WBC_NEWL(__VA_ARGS__)})

#define     VWHU_NEWL(...)      ((VWHU_TYPE){WHU_NEWL(__VA_ARGS__)})
#define     VWHI_NEWL(...)      ((VWHI_TYPE){WHI_NEWL(__VA_ARGS__)})
#define     VWHF_NEWL(...)      ((VWHF_TYPE){WHF_NEWL(__VA_ARGS__)})

#define     VDBU_NEWL       DBU_NEWL
#define     VDBI_NEWL       DBI_NEWL
#define     VDBC_NEWL(...)  ((VDBC_TYPE){DBC_NEWL(__VA_ARGS__)})
#define     VDHU_NEWL       DHU_NEWL
#define     VDHI_NEWL       DHI_NEWL
#define     VDHF_NEWL       DHF_NEWL
#define     VDWU_NEWL       DWU_NEWL
#define     VDWI_NEWL       DWI_NEWL
#define     VDWF_NEWL       DWF_NEWL
#if 0
#define     VDDU_NEWL   DDU_NEWL
#define     VDDI_NEWL   DDI_NEWL
#define     VDDF_NEWL   DDF_NEWL
#endif

#define     VQBU_NEWL   QBU_NEWL
#define     VQBI_NEWL   QBI_NEWL
#define     VQBC_NEWL(...)  ((VQBC_TYPE){QBC_NEWL(__VA_ARGS__)})
#define     VQHU_NEWL   QHU_NEWL
#define     VQHI_NEWL   QHI_NEWL
#define     VQHF_NEWL   QHF_NEWL
#define     VQWU_NEWL   QWU_NEWL
#define     VQWI_NEWL   QWI_NEWL
#define     VQWF_NEWL   QWF_NEWL
#define     VQDU_NEWL   QDU_NEWL
#define     VQDI_NEWL   QDI_NEWL
#define     VQDF_NEWL   QDF_NEWL

#if _LEAVE_EXTGOP_ARM_NEWL
}
#endif

#if _LEAVE_EXTGOP_ARM_NEW_
}
#endif

#if _ENTER_EXTGOP_ARM_CAT_
{
#endif

#if _ENTER_EXTGOP_ARM_CATL
{
#endif

INLINE( Dwf,WWF_CATL)( Wwf l, Wwf r)
{
#define     WWF_CATL        WWF_CATL
    Dwf m = vset_lane_f32(l, m, V2_K0);
    return  vset_lane_f32(r, m, V2_K1);
}

#define     WYU_CATL(L, R)  vreinterpret_u64_f32(WWF_CATL(L,R))
#define     WBU_CATL(L, R)  vreinterpret_u8_f32( WWF_CATL(L,R))
#define     WBI_CATL(L, R)  vreinterpret_s8_f32( WWF_CATL(L,R))
#if CHAR_MIN
#   define  WBC_CATL(L, R)  WBI_CATL(L,R)
#else
#   define  WBC_CATL(L, R)  WBU_CATL(L,R)
#endif

#define     WHU_CATL(L, R)  vreinterpret_u16_f32(WWF_CATL(L,R))
#define     WHI_CATL(L, R)  vreinterpret_s16_f32(WWF_CATL(L,R))
#define     WHF_CATL(L, R)  vreinterpret_f16_f32(WWF_CATL(L,R))
#define     WWU_CATL(L, R)  vreinterpret_u32_f32(WWF_CATL(L,R))
#define     WWI_CATL(L, R)  vreinterpret_s32_f32(WWF_CATL(L,R))

// leave the "pointless" arguments alone for now 
#define     DYU_CATL(L, R)  vcombine_u64(L,R)
#define     DBU_CATL(L, R)  vcombine_u8( L,R)
#define     DBI_CATL(L, R)  vcombine_s8( L,R)
#if CHAR_MIN
#   define  DBC_CATL(L, R)  DBI_CATL(L,R)
#else
#   define  DBC_CATL(L, R)  DBU_CATL(L,R)
#endif

#define     DHU_CATL(L, R)  vcombine_u16(L,R)
#define     DHI_CATL(L, R)  vcombine_s16(L,R)
#define     DHF_CATL(L, R)  vcombine_f16(L,R)
#define     DWU_CATL(L, R)  vcombine_u32(L,R)
#define     DWI_CATL(L, R)  vcombine_s32(L,R)
#define     DWF_CATL(L, R)  vcombine_f32(L,R)
#define     DDU_CATL(L, R)  vcombine_u64(L,R)
#define     DDI_CATL(L, R)  vcombine_s64(L,R)
#define     DDF_CATL(L, R)  vcombine_f64(L,R)

#define     VWYU_CATL(L, R) DYU_ASTV(WYU_CATL(VWYU_ASTM(L),VWYU_ASTM(R)))
#define     VWBU_CATL(L, R)          WBU_CATL(VWBU_ASTM(L),VWBU_ASTM(R))
#define     VWBI_CATL(L, R)          WBI_CATL(VWBI_ASTM(L),VWBI_ASTM(R))
#define     VWBC_CATL(L, R) DBC_ASTV(WBC_CATL(VWBC_ASTM(L),VWBC_ASTM(R)))
#define     VWHU_CATL(L, R)          WHU_CATL(VWHU_ASTM(L),VWHU_ASTM(R))
#define     VWHI_CATL(L, R)          WHI_CATL(VWHI_ASTM(L),VWHI_ASTM(R))
#define     VWHF_CATL(L, R)          WHF_CATL(VWHF_ASTM(L),VWHF_ASTM(R))
#define     VWWU_CATL(L, R)          WWU_CATL(VWWU_ASTM(L),VWWU_ASTM(R))
#define     VWWI_CATL(L, R)          WWI_CATL(VWWI_ASTM(L),VWWI_ASTM(R))
#define     VWWF_CATL(L, R)          WWU_CATL(VWWF_ASTM(L),VWWF_ASTM(R))

#define     VDYU_CATL(L, R) QYU_ASTV(DYU_CATL(VDYU_ASTM(L),VDYU_ASTM(R)))
#define     VDBU_CATL       DBU_CATL
#define     VDBI_CATL       DBI_CATL
#define     VDBC_CATL(L, R) QBC_ASTV(DBC_CATL(VDBC_ASTM(L),VDBC_ASTM(R)))
#define     VDHU_CATL       DHU_CATL
#define     VDHI_CATL       DHI_CATL
#define     VDHF_CATL       DHF_CATL
#define     VDWU_CATL       DWU_CATL
#define     VDWI_CATL       DWI_CATL
#define     VDWF_CATL       DWF_CATL
#define     VDDU_CATL       DDU_CATL
#define     VDDI_CATL       DDI_CATL
#define     VDDF_CATL       DDF_CATL

#if _LEAVE_EXTGOP_ARM_CATL
}
#endif

#if _ENTER_EXTGOP_ARM_CATR
{
#endif

INLINE( Dyu,WYU_CATR)(Wyu l, Wyu r)
{
#define     WYU_CATR    WYU_CATR
    Dwf m;
    m = vset_lane_f32(l, m, V2_K0);
    m = vset_lane_f32(r, m, V2_K1);
    Dyu y = vreinterpret_u64_f32(m);
    return vdup_n_u64(__rbitll(vget_lane_u64(y, 0)));
}

INLINE( Dbu,WBU_CATR)(Wbu l, Wbu r)
{
#define     WBU_CATR    WBU_CATR
    Dwf v;
    v = vset_lane_f32(r, v, V2_K0);
    v = vset_lane_f32(l, v, V2_K1);
    return  vrev32_u8(vreinterpret_u8_f32(v));
}

INLINE( Dbi,WBI_CATR)(Wbi l, Wbi r)
{
#define     WBI_CATR    WBI_CATR
    Dwf v;
    v = vset_lane_f32(r, v, V2_K0);
    v = vset_lane_f32(l, v, V2_K1);
    return  vrev32_s8(vreinterpret_s8_f32(v));
}


INLINE( Dhu,WHU_CATR)(Whu l, Whu r)
{
#define     WHU_CATR    WHU_CATR
    Dwf v;
    v = vset_lane_f32(r, v, V2_K0);
    v = vset_lane_f32(l, v, V2_K1);
    return  vrev32_u16(vreinterpret_u16_f32(v));
}

INLINE( Dhi,WHI_CATR)(Whi l, Whi r)
{
#define     WHI_CATR    WHI_CATR
    Dwf m;
    m = vset_lane_f32(r, m, V2_K0);
    m = vset_lane_f32(l, m, V2_K1);
    return  vrev32_s16(vreinterpret_s16_f32(m));
}

INLINE( Dhf,WHF_CATR)(Whf l, Whf r)
{
#define     WHF_CATR    WHF_CATR
    Dwf v;
    v = vset_lane_f32(r, v, V2_K0);
    v = vset_lane_f32(l, v, V2_K1);
    return  vreinterpret_f16_u16(vrev32_u16(vreinterpret_u16_f32(v)));
}


INLINE( Dwu,WWU_CATR)(Wwu l, Wwu r)
{
#define     WWU_CATR    WWU_CATR
    Dwf v = vset_lane_f32(l, v, V2_K1);
    return  vreinterpret_u32_f32(vset_lane_f32(r, v, V2_K0));
}

INLINE( Dwi,WWI_CATR)(Wwi l, Wwi r)
{
#define     WWI_CATR    WWI_CATR
    Dwf v = vset_lane_f32(l, v, V2_K1);
    return  vreinterpret_s32_f32(vset_lane_f32(r, v, V2_K0));
}

INLINE( Dwf,WWF_CATR)(Wwf l, Wwf r)
{
#define     WWF_CATR    WWF_CATR
    Dwf v = vset_lane_f32(l, v, V2_K1);
    return  vset_lane_f32(r, v, V2_K0);
}

#define     WYU_CATR        WYU_CATR

#define     DYU_CATR(l, r)                      \
vcombine_u64(                                   \
    vdup_n_u64(__rbitll(vget_lane_u64(r,0))),   \
    vdup_n_u64(__rbitll(vget_lane_u64(l,0))),   \
)

#define     DBU_CATR(l, r)  vcombine_u8( vrev64_u8(r), vrev64_u8(l))               
#define     DBI_CATR(l, r)  vcombine_s8( vrev64_s8(r), vrev64_s8(l))                
#define     DHU_CATR(l, r)  vcombine_u16(vrev64_u16(r),vrev64_u16(l))                  
#define     DHI_CATR(l, r)  vcombine_s16(vrev64_s16(r),vrev64_s16(l))                  
#define     DHF_CATR(l, r)  vcombine_f16(vrev64_f16(r),vrev64_f16(l))
#define     DWU_CATR(l, r)  vcombine_u32(vrev64_u32(r),vrev64_u32(l))              
#define     DWI_CATR(l, r)  vcombine_s32(vrev64_s32(r),vrev64_s32(l))                  
#define     DWF_CATR(l, r)  vcombine_f32(vrev64_f32(r),vrev64_f32(l))
#define     DDU_CATR(l, r)  vcombine_u64(r,l)
#define     DDI_CATR(l, r)  vcombine_s64(r,l)
#define     DDF_CATR(l, r)  vcombine_f64(r,l)

#define     VWBU_CATR(l, r) WBU_ASTV(WBU_CATR(VWBU_ASTM(l),VWBU_ASTM(r)))
#define     VWBI_CATR(l, r) WBI_ASTV(WBI_CATR(VWBI_ASTM(l),VWBI_ASTM(r)))
#define     VWHU_CATR(l, r) WHU_ASTV(WHU_CATR(VWHU_ASTM(l),VWHU_ASTM(r)))
#define     VWHI_CATR(l, r) WHI_ASTV(WHI_CATR(VWHI_ASTM(l),VWHI_ASTM(r)))
#define     VWHF_CATR(l, r) WHF_ASTV(WHF_CATR(VWHF_ASTM(l),VWHF_ASTM(r)))
#define     VWWU_CATR(l, r) WWI_ASTV(WWU_CATR(VWWU_ASTM(l),VWWU_ASTM(r)))
#define     VWWI_CATR(l, r) WWU_ASTV(WWI_CATR(VWWI_ASTM(l),VWWI_ASTM(r)))
#define     VWWF_CATR(l, r) WWF_ASTV(WWF_CATR(VWWF_ASTM(l),VWWF_ASTM(r)))

#define     VDYU_CATR(l, r) DYU_ASTV(DYU_CATR(VDYU_ASTM(l),VDYU_ASTM(r)))
#define     VDBU_CATR(l, r) DBU_ASTV(DBU_CATR(VDBU_ASTM(l),VDBU_ASTM(r)))
#define     VDBI_CATR(l, r) DBI_ASTV(DBI_CATR(VDBI_ASTM(l),VDBI_ASTM(r)))
#define     VDHU_CATR(l, r) DHU_ASTV(DHU_CATR(VDHU_ASTM(l),VDHU_ASTM(r)))
#define     VDHI_CATR(l, r) DHI_ASTV(DHI_CATR(VDHI_ASTM(l),VDHI_ASTM(r)))
#define     VDHF_CATR(l, r) DHF_ASTV(DHF_CATR(VDHF_ASTM(l),VDHF_ASTM(r)))
#define     VDWU_CATR(l, r) DWU_ASTV(DWU_CATR(VDWU_ASTM(l),VDWU_ASTM(r)))
#define     VDWI_CATR(l, r) DWI_ASTV(DWI_CATR(VDWI_ASTM(l),VDWI_ASTM(r)))
#define     VDWF_CATR(l, r) DWF_ASTV(DWF_CATR(VDWF_ASTM(l),VDWF_ASTM(r)))
#define     VDDU_CATR(l, r) DDU_ASTV(DDU_CATR(VDDU_ASTM(l),VDDU_ASTM(r)))
#define     VDDI_CATR(l, r) DDI_ASTV(DDI_CATR(VDDI_ASTM(l),VDDI_ASTM(r)))
#define     VDDF_CATR(l, r) DDF_ASTV(DDF_CATR(VDDF_ASTM(l),VDDF_ASTM(r)))

#if _LEAVE_EXTGOP_ARM_CATR
}
#endif

#if _LEAVE_EXTGOP_ARM_CAT_
}
#endif

#if _ENTER_EXTGOP_ARM_REV_
{
#endif

#if _ENTER_EXTGOP_ARM_REVS
{
#endif

INLINE( Wyu,WYU_REVS) ( Wyu m)
{
#define     WYU_REVS    WYU_REVS
    Dwf f = vset_lane_f32(m, f, V2_K0);
    Dwu v = vreinterpret_u32_f32(f);
    uint32_t u = vget_lane_u32(v, V2_K0);
    v = vset_lane_u32(__rbit(u), v, V2_K0);
    f = vreinterpret_f32_u32(v);
    return  vget_lane_f32(f, V2_K0);
}

INLINE( Wbu,WBU_REVS) ( Wbu v)
{
#define     WBU_REVS    WBU_REVS
    Dwf f = vset_lane_f32(v, f, V2_K0);
    Dbu u = vreinterpret_u8_f32(f);
    u = vrev32_u8(u);
    return vget_lane_f32(vreinterpret_f32_u8(u), V2_K0);
}

INLINE( Wbi,WBI_REVS) ( Wbi v)
{
#define     WBI_REVS    WBI_REVS
    Dwf f = vset_lane_f32(v, f, V2_K0);
    Dbi i = vrev32_s8(vreinterpret_s8_f32(f));
    return vget_lane_f32(vreinterpret_f32_s8(i), V2_K0);
}

INLINE( Wbc,WBC_REVS) ( Wbc m)
{
#define     WBC_REVS    WBC_REVS
    Dwf f = vset_lane_f32(m, f, V2_K0);
    Dbi c = vrev32_u8(vreinterpret_u8_f32(f));
    return  vget_lane_f32(vreinterpret_f32_u8(c), V2_K0);
}

INLINE( Whu,WHU_REVS) ( Whu m)
{
#define     WHU_REVS    WHU_REVS
    Dwf f = vset_lane_f32(m, f, V2_K0);
    Dhu v = vrev32_u16(vreinterpret_u16_f32(f));
    return vget_lane_f32(vreinterpret_f32_u16(v), V2_K0);
}

INLINE( Whi,WHI_REVS) (Whi m)
{
#define     WHI_REVS    WHI_REVS
    Dwf f = vset_lane_f32(m, f, V2_K0);
    Dhi v = vrev32_s16(vreinterpret_s16_f32(f));
    return vget_lane_f32(vreinterpret_f32_s16(v), V2_K0);
}

INLINE( Whf,WHF_REVS) (Whf m)
{
#define     WHF_REVS    WHF_REVS
/*  see notes at QHF_REVS for why this looks so gross */
    Dwf f = vset_lane_f32(m, f, V2_K0);
    Dhu v = vrev32_u16(vreinterpret_u16_f32(f));
    return vget_lane_f32(vreinterpret_f32_u16(v), V2_K0);
}


#define     DYU_REVS(M)     vdup_n_u64(__rbitll(vget_lane_u64(M,0)))
#define     DBU_REVS        vrev64_u8
#define     DBI_REVS        vrev64_s8
#if CHAR_MIN
#   define  DBC_REVS        vrev64_s8
#else
#   define  DBC_REVS        vrev64_u8
#endif

#define     DHU_REVS        vrev64_u16
#define     DHI_REVS        vrev64_s16
#define     DHF_REVS(M)     \
vreinterpret_f16_u16(vrev64_u16(vreinterpret_u16_f16(M)))


#define     DWU_REVS        vrev64_u32
#define     DWI_REVS        vrev64_s32
#define     DWF_REVS        vrev64_f32
#define     QYU_REVS(M)     \
vcombine_u64(\
    vdup_n_u64(__rbitll(vgetq_lane_u64(M, V2_K0))),\
    vdup_n_u64(__rbitll(vgetq_lane_u64(M, V2_K1)))\
)

#define     QBU_REVS(M) \
vrev64q_u8(vcombine_u8(vget_high_u8(M),vget_low_u8(M)))

#define     QBI_REVS(M) \
vrev64q_s8(vcombine_s8(vget_high_s8(M),vget_low_s8(M)))

#if CHAR_MIN
#   define  QBC_REVS(M)  \
vrev64q_s8(vcombine_s8(vget_high_s8(M),vget_low_s8(M)))

#else
#   define  QBC_REVS(M) \
vrev64q_u8(vcombine_u8(vget_high_u8(M),vget_low_u8(M)))

#endif

#define     QHU_REVS(M) \
vrev64q_u16(vcombine_u16(vget_high_u16(M),vget_low_u16(M)))

#define     QHI_REVS(M) \
vrev64q_s16(vcombine_s16(vget_high_s16(M),vget_low_s16(M)))

// fuggit
#define     QHF_REVS(M)             \
vreinterpretq_f16_u16(              \
    vrev64q_u16(                    \
        vreinterpretq_u16_f16(      \
            vcombine_f16(           \
                vget_high_f16(M),   \
                vget_low_f16( M)    \
            )                       \
        )                           \
    )                               \
)

#define     QWU_REVS(M) \
vrev64q_u32(vcombine_u32(vget_high_u32(M),vget_low_u32(M)))

#define     QWI_REVS(M) \
vrev64q_s32(vcombine_s32(vget_high_s32(M),vget_low_s32(M)))

#define     QWF_REVS(M) \
vrev64q_f32(vcombine_f32(vget_high_f32(M),vget_low_f32(M)))


#define     QDU_REVS(M) \
vcombine_u64(vget_high_u64(M),vget_low_u64(M))

#define     QDI_REVS(M) \
vcombine_s64(vget_high_s64(M),vget_low_s64(M))

#define     QDF_REVS(M) \
vcombine_f64(vget_high_f64(M),vget_low_f64(M))

INLINE(Vwyu,VWYU_REVS)(Vwyu v)
{
#define     VWYU_REVS(V) WYU_ASTV(WYU_REVS(VWYU_ASTM(V)))
    return  VWYU_REVS(v);
}

INLINE(Vwbu,VWBU_REVS)(Vwbu v)
{
#define     VWBU_REVS(V) WBU_ASTV(WBU_REVS(VWBU_ASTM(V)))
    return  VWBU_REVS(v);
}

INLINE(Vwbi,VWBI_REVS)(Vwbi v)
{
#define     VWBI_REVS(V) WBI_ASTV(WBI_REVS(VWBI_ASTM(V)))
    return  VWBI_REVS(v);
}

INLINE(Vwbc,VWBC_REVS)(Vwbc v)
{
#define     VWBC_REVS(V) WBC_ASTV(WBC_REVS(VWBC_ASTM(V)))
    return  VWBC_REVS(v);
}

INLINE(Vwhu,VWHU_REVS)(Vwhu v)
{
#define     VWHU_REVS(V) WHU_ASTV(WHU_REVS(VWHU_ASTM(V)))
    return  VWHU_REVS(v);
}

INLINE(Vwhi,VWHI_REVS)(Vwhi v)
{
#define     VWHI_REVS(V) WHI_ASTV(WHI_REVS(VWHI_ASTM(V)))
    return  VWHI_REVS(v);
}

INLINE(Vwhf,VWHF_REVS)(Vwhf v)
{
#define     VWHF_REVS(V) WHF_ASTV(WHF_REVS(VWHF_ASTM(V)))
    return  VWHF_REVS(v);
}


INLINE(Vdyu,VDYU_REVS)(Vdyu v)
{
#define     VDYU_REVS(V)    DYU_ASTV(DYU_REVS(VDYU_ASTM(V)))
    return  VDYU_REVS(v);
}

INLINE(Vdbu,VDBU_REVS)(Vdbu v)
{
#define     VDBU_REVS(V)    DBU_REVS(V)
    return  VDBU_REVS(v);
}

INLINE(Vdbi,VDBI_REVS)(Vdbi v)
{
#define     VDBI_REVS(V)    DBI_REVS(V)
    return  VDBI_REVS(v);
}

INLINE(Vdbc,VDBC_REVS)(Vdbc v)
{
#define     VDBC_REVS(V) DBC_ASTV(DBC_REVS(VDBC_ASTM(V)))
    return  VDBC_REVS(v);
}

INLINE(Vdhu,VDHU_REVS)(Vdhu v)
{
#define     VDHU_REVS(V)    DHU_REVS(V)
    return  VDHU_REVS(v);
}

INLINE(Vdhi,VDHI_REVS)(Vdhi v)
{
#define     VDHI_REVS(V)    DHI_REVS(V)
    return  VDHI_REVS(v);
}

INLINE(Vdhf,VDHF_REVS)(Vdhf v)
{
#define     VDHF_REVS(V)    DHF_REVS(V)
    return  VDHF_REVS(v);
}

INLINE(Vdwu,VDWU_REVS)(Vdwu v)
{
#define     VDWU_REVS(V)    DWU_REVS(V)
    return  VDWU_REVS(v);
}

INLINE(Vdwi,VDWI_REVS)(Vdwi v)
{
#define     VDWI_REVS(V)    DWI_REVS(V)
    return  VDWI_REVS(v);
}

INLINE(Vdwf,VDWF_REVS)(Vdwf v)
{
#define     VDWF_REVS(V)    DWF_REVS(V)
    return  VDWF_REVS(v);
}

INLINE(Vqyu,VQYU_REVS)(Vqyu v)
{
#define     VQYU_REVS(V)    QYU_ASTV(QYU_REVS(VQYU_ASTM(V)))
    return  VQYU_REVS(v);
}

INLINE(Vqbu,VQBU_REVS)(Vqbu v)
{
#define     VQBU_REVS(V)    QBU_REVS(V)
    return  VQBU_REVS(v);
}

INLINE(Vqbi,VQBI_REVS)(Vqbi v)
{
#define     VQBI_REVS(V)    QBI_REVS(V)
    return  VQBI_REVS(v);
}

INLINE(Vqbc,VQBC_REVS)(Vqbc v)
{
#define     VQBC_REVS(V)    QBC_ASTV(QBC_REVS(VQBC_ASTM(V)))
    return  VQBC_REVS(v);
}

INLINE(Vqhu,VQHU_REVS)(Vqhu v)
{
#define     VQHU_REVS(V)    QHU_REVS(V)
    return  VQHU_REVS(v);
}

INLINE(Vqhi,VQHI_REVS)(Vqhi v)
{
#define     VQHI_REVS(V)    QHI_REVS(V)
    return  VQHI_REVS(v);
}

INLINE(Vqhf,VQHF_REVS)(Vqhf v)
{
#define     VQHF_REVS(V)    QHF_REVS(V)
    return  VQHF_REVS(v);
}

INLINE(Vqwu,VQWU_REVS)(Vqwu v)
{
#define     VQWU_REVS(V)    QWU_REVS(V)
    return  VQWU_REVS(v);
}

INLINE(Vqwi,VQWI_REVS)(Vqwi v)
{
#define     VQWI_REVS(V)    QWI_REVS(V)
    return  VQWI_REVS(v);
}

INLINE(Vqwf,VQWF_REVS)(Vqwf v)
{
#define     VQWF_REVS(V)    QWF_REVS(V)
    return  VQWF_REVS(v);
}

INLINE(Vqdu,VQDU_REVS)(Vqdu v)
{
#define     VQDU_REVS(V)    QDU_REVS(V)
    return  VQDU_REVS(v);
}

INLINE(Vqdi,VQDI_REVS)(Vqdi v)
{
#define     VQDI_REVS(V)    QDI_REVS(V)
    return  VQDI_REVS(v);
}

INLINE(Vqdf,VQDF_REVS)(Vqdf v)
{
#define     VQDF_REVS(V)    QDF_REVS(V)
    return  VQDF_REVS(v);
}

#if _LEAVE_EXTGOP_ARM_REVS
}
#endif

#if _LEAVE_EXTGOP_ARM_REV_
}
#endif

#if _ENTER_EXTGOP_ARM_VXT_
{
#endif

#if _ENTER_EXTGOP_ARM_VXTL
{
#endif


#define     DYU_VXTL(V)     vget_lane_f32(vreinterpret_f32_u64(V),V2_K0)
#define     DBU_VXTL(V)     vget_lane_f32(vreinterpret_f32_u8( V),V2_K0)
#define     DBI_VXTL(V)     vget_lane_f32(vreinterpret_f32_s8( V),V2_K0)
#if CHAR_MIN
#   define  DBC_VXTL(M)     DBI_VXTL(M)
#else
#   define  DBC_VXTL(M)     DBU_VXTL(M)
#endif

#define     DHU_VXTL(V)     vget_lane_f32(vreinterpret_f32_u16(V),V2_K0)
#define     DHI_VXTL(V)     vget_lane_f32(vreinterpret_f32_s16(V),V2_K0)
#define     DHF_VXTL(V)     vget_lane_f32(vreinterpret_f32_f16(V),V2_K0)
#define     DWU_VXTL(V)     vget_lane_f32(vreinterpret_f32_u32(V),V2_K0)
#define     DWI_VXTL(V)     vget_lane_f32(vreinterpret_f32_s32(V),V2_K0)
#define     DWF_VXTL(V)     vget_lane_f32(_Generic((V),VDWF_MTYPE:(V)),V2_K0)

#define     QYU_VXTL        vget_low_u64
#define     QBU_VXTL        vget_low_u8
#define     QBI_VXTL        vget_low_s8
#if CHAR_MIN
#   define  QBC_VXTL(M)     QBI_VXTL(M)
#else
#   define  QBC_VXTL(M)     QBU_VXTL(M)
#endif

#define     QHU_VXTL        vget_low_u16
#define     QHI_VXTL        vget_low_s16
#define     QHF_VXTL        vget_low_f16
#define     QWU_VXTL        vget_low_u32
#define     QWI_VXTL        vget_low_s32
#define     QWF_VXTL        vget_low_f32
#define     QDU_VXTL        vget_low_u64
#define     QDI_VXTL        vget_low_s64
#define     QDF_VXTL        vget_low_f64

#define     VDYU_VXTL(V)    WYU_ASTV(DYU_VXTL(VDYU_ASTM(V)))
#define     VDBU_VXTL(V)    WBU_ASTV(DBU_VXTL(VDBU_ASTM(V)))
#define     VDBI_VXTL(V)    WBI_ASTV(DBI_VXTL(VDBI_ASTM(V)))
#define     VDBC_VXTL(V)    WBC_ASTV(DBC_VXTL(VDBC_ASTM(V)))
#define     VDHU_VXTL(V)    WHU_ASTV(DHU_VXTL(VDHU_ASTM(V)))
#define     VDHI_VXTL(V)    WHI_ASTV(DHI_VXTL(VDHI_ASTM(V)))
#define     VDHF_VXTL(V)    WHF_ASTV(DHF_VXTL(VDHF_ASTM(V)))
#define     VDWU_VXTL(V)    WWU_ASTV(DWU_VXTL(VDWU_ASTM(V)))
#define     VDWI_VXTL(V)    WWI_ASTV(DWI_VXTL(VDWI_ASTM(V)))
#define     VDWF_VXTL(V)    WWF_ASTV(DWF_VXTL(VDWF_ASTM(V)))

#define     VQYU_VXTL(V)    DYU_ASTV(QYU_VXTL(VQYU_ASTM(V)))
#define     VQBU_VXTL(V)    DBU_ASTV(QBU_VXTL(VQBU_ASTM(V)))
#define     VQBI_VXTL(V)    DBI_ASTV(QBI_VXTL(VQBI_ASTM(V)))
#define     VQBC_VXTL(V)    DBC_ASTV(QBC_VXTL(VQBC_ASTM(V)))
#define     VQHU_VXTL(V)    DHU_ASTV(QHU_VXTL(VQHU_ASTM(V)))
#define     VQHI_VXTL(V)    DHI_ASTV(QHI_VXTL(VQHI_ASTM(V)))
#define     VQHF_VXTL(V)    DHF_ASTV(QHF_VXTL(VQHF_ASTM(V)))
#define     VQWU_VXTL(V)    DWU_ASTV(QWU_VXTL(VQWU_ASTM(V)))
#define     VQWI_VXTL(V)    DWI_ASTV(QWI_VXTL(VQWI_ASTM(V)))
#define     VQWF_VXTL(V)    DWF_ASTV(QWF_VXTL(VQWF_ASTM(V)))
#define     VQDU_VXTL(V)    DDU_ASTV(QDU_VXTL(VQDU_ASTM(V)))
#define     VQDI_VXTL(V)    DDI_ASTV(QDI_VXTL(VQDI_ASTM(V)))
#define     VQDF_VXTL(V)    DDF_ASTV(QDF_VXTL(VQDF_ASTM(V)))

#if _LEAVE_EXTGOP_ARM_VXTL
}
#endif

#if _ENTER_EXTGOP_ARM_VXTR
{
#endif

#define     DYU_VXTR(V)     vget_lane_f32(vreinterpret_f32_u64(V),V2_K1)
#define     DBU_VXTR(V)     vget_lane_f32(vreinterpret_f32_u8( V),V2_K1)
#define     DBI_VXTR(V)     vget_lane_f32(vreinterpret_f32_s8( V),V2_K1)
#if CHAR_MIN
#   define  DBC_VXTR(M)     DBI_VXTR(M)
#else
#   define  DBC_VXTR(M)     DBU_VXTR(M)
#endif

#define     DHU_VXTR(V)     vget_lane_f32(vreinterpret_f32_u16(V),V2_K1)
#define     DHI_VXTR(V)     vget_lane_f32(vreinterpret_f32_s16(V),V2_K1)
#define     DHF_VXTR(V)     vget_lane_f32(vreinterpret_f32_f16(V),V2_K1)
#define     DWU_VXTR(V)     vget_lane_f32(vreinterpret_f32_u32(V),V2_K1)
#define     DWI_VXTR(V)     vget_lane_f32(vreinterpret_f32_s32(V),V2_K1)
#define     DWF_VXTR(M)     vget_lane_f32(_Generic((M),VDWF_TYPE:(M)),V2_K1)

#define     QYU_VXTR        vget_high_u64
#define     QBU_VXTR        vget_high_u8
#define     QBI_VXTR        vget_high_s8
#if CHAR_MIN
#   define  QBC_VXTR(M)     QBI_VXTR(M)
#else
#   define  QBC_VXTR(M)     QBU_VXTR(M)
#endif

#define     QHU_VXTR        vget_high_u16
#define     QHI_VXTR        vget_high_s16
#define     QHF_VXTR        vget_high_f16
#define     QWU_VXTR        vget_high_u32
#define     QWI_VXTR        vget_high_s32
#define     QWF_VXTR        vget_high_f32
#define     QDU_VXTR        vget_high_u64
#define     QDI_VXTR        vget_high_s64
#define     QDF_VXTR        vget_high_f64

#define     VDYU_VXTR(V)    WYU_ASTV(DYU_VXTR(VDYU_ASTM(V)))

#define     VDBU_VXTR(V)    WBU_ASTV(DBU_VXTR(VDBU_ASTM(V)))
#define     VDBI_VXTR(V)    WBI_ASTV(DBI_VXTR(VDBI_ASTM(V)))
#define     VDBC_VXTR(V)    WBC_ASTV(DBC_VXTR(VDBC_ASTM(V)))
#define     VDHU_VXTR(V)    WHU_ASTV(DHU_VXTR(VDHU_ASTM(V)))
#define     VDHI_VXTR(V)    WHI_ASTV(DHI_VXTR(VDHI_ASTM(V)))
#define     VDHF_VXTR(V)    WHF_ASTV(DHF_VXTR(VDHF_ASTM(V)))
#define     VDWU_VXTR(V)    WWU_ASTV(DWU_VXTR(VDWU_ASTM(V)))
#define     VDWI_VXTR(V)    WWI_ASTV(DWI_VXTR(VDWI_ASTM(V)))
#define     VDWF_VXTR(V)    WWF_ASTV(DWF_VXTR(VDWF_ASTM(V)))

#define     VQYU_VXTR(V)    DYU_ASTV(QYU_VXTR(VQYU_ASTM(V)))
#define     VQBU_VXTR(V)    DBU_ASTV(QBU_VXTR(VQBU_ASTM(V)))
#define     VQBI_VXTR(V)    DBI_ASTV(QBI_VXTR(VQBI_ASTM(V)))
#define     VQBC_VXTR(V)    DBC_ASTV(QBC_VXTR(VQBC_ASTM(V)))
#define     VQHU_VXTR(V)    DHU_ASTV(QHU_VXTR(VQHU_ASTM(V)))
#define     VQHI_VXTR(V)    DHI_ASTV(QHI_VXTR(VQHI_ASTM(V)))
#define     VQHF_VXTR(V)    DHF_ASTV(QHF_VXTR(VQHF_ASTM(V)))
#define     VQWU_VXTR(V)    DWU_ASTV(QWU_VXTR(VQWU_ASTM(V)))
#define     VQWI_VXTR(V)    DWI_ASTV(QWI_VXTR(VQWI_ASTM(V)))
#define     VQWF_VXTR(V)    DWF_ASTV(QWF_VXTR(VQWF_ASTM(V)))
#define     VQDU_VXTR(V)    DDU_ASTV(QDU_VXTR(VQDU_ASTM(V)))
#define     VQDI_VXTR(V)    DDI_ASTV(QDI_VXTR(VQDI_ASTM(V)))
#define     VQDF_VXTR(V)    DDF_ASTV(QDF_VXTR(VQDF_ASTM(V)))

#if _LEAVE_EXTGOP_ARM_VXTR
}
#endif

#if _ENTER_EXTGOP_ARM_VXT1
{
#endif

INLINE(_Bool, VWYU_VXT1) (Vwyu v, Rc(0, 31) k)
{
#define     WYU_VXT1(V, K) ((_Bool)(1&(FLT_ASTG(V).U>>(K))))
#define     VWYU_VXT1(V, K)   WYU_VXT1(VWYU_ASTM(V), K)
    return  VWYU_VXT1(v, k);
}

INLINE( uint8_t,VWBU_VXT1) (Vwbu v, Rc(0,3) k)
{
#define     WBU_VXT1(a, b)  \
vget_lane_u8(vreinterpret_u8_f32(vdup_n_f32(a)), (3&(b)))

#define     VWBU_VXT1(a, b)     WBU_VXT1(VWBU_ASTM(a), b)
    float32x2_t t = vset_lane_f32(VWBU_ASTM(v),t, V2_K0);
    return  vget_lane_u32(vreinterpret_u32_f32(t),V2_K0)>>(k*8);
}

INLINE(  int8_t,VWBI_VXT1) (Vwbi v, Rc(0,3) k)
{
#define     WBI_VXT1(a, b)  \
vget_lane_s8(vreinterpret_s8_f32(vdup_n_f32(a)), (3&(b)))

#define     VWBI_VXT1(a, b)     WBI_VXT1(VWBI_ASTM(a), b)
    float32x2_t t = vset_lane_f32(VWBI_ASTM(v),t, V2_K0);
    return  vget_lane_u32(vreinterpret_u32_f32(t),V2_K0)>>(k*8);
}

INLINE(    char,VWBC_VXT1) (Vwbc v, Rc(0,3) k)
{
#define     WBC_VXT1(a, b)  \
((char) vget_lane_u8(vreinterpret_u8_f32(vdup_n_f32(a)),(3&(b))))

#define     VWBC_VXT1(a, b)     WBC_VXT1(VWBC_ASTM(a), b)
    float32x2_t f = vset_lane_f32(VWBC_ASTM(v),f, V2_K0);
    uint32x2_t  u = vreinterpret_u32_f32(f);
    u = vshl_u32(u, vdup_n_s32(-8*k));
    return  vget_lane_u32(u, V2_K0);
}


INLINE(uint16_t,VWHU_VXT1) (Vwhu v, Rc(0,1) k)
{
#define     WHU_VXT1(a, b)  \
vget_lane_u16(vreinterpret_u16_f32(vdup_n_f32(a)), (1&(b)))

#define     VWHU_VXT1(a, b)     WHU_VXT1(VWHU_ASTM(a), b)
    float32x2_t f = vset_lane_f32(VWHU_ASTM(v),f, V2_K0);
    uint32x2_t  u = vreinterpret_u32_f32(f);
    u = vshl_u32(u, vdup_n_s32(-16*k));
    return  vget_lane_u16(vreinterpret_u16_u32(u), V4_K0);
}

INLINE( int16_t,VWHI_VXT1) (Vwhi v, Rc(0,1) k)
{
#define     WHI_VXT1(a, b)  \
vget_lane_s16(vreinterpret_s16_f32(vdup_n_f32(a)), (1&(b)))

#define     VWHI_VXT1(a, b)     WHI_VXT1(VWHI_ASTM(a), b)
    float32x2_t f = vset_lane_f32(VWHI_ASTM(v),f, V2_K0);
    uint32x2_t  u = vreinterpret_u32_f32(f);
    u = vshl_u32(u, vdup_n_s32(-16*k));
    return  vget_lane_s16(vreinterpret_u16_u32(u), V4_K0);
}

INLINE( flt16_t,VWHF_VXT1) (Vwhf v, Rc(0,1) k)
{
#define     WHF_VXT1(a, b)  \
vget_lane_f16(vreinterpret_f16_f32(vdup_n_f32(a)), (1&(b)))

#define     VWHF_VXT1(a, b)     WHF_VXT1(VWHF_ASTM(a), b)
    float32x2_t f = vset_lane_f32(VWHF_ASTM(v),f, V2_K0);
    uint32x2_t  u = vreinterpret_u32_f32(f);
    u = vshl_u32(u, vdup_n_s32(-16*k));
    return  vget_lane_f16(vreinterpret_f16_u32(u), V4_K0);
}



INLINE(_Bool, VDYU_VXT1) (Vdyu v, Rc(0, 63) k)
{
#define      DYU_VXT1(V, K)                 \
(                                           \
    (_Bool)                                 \
    (1&(vget_lane_u64((V), 0)>>((K)%64)))   \
)

#define     VDYU_VXT1(V, K)   DYU_VXT1(VDYU_ASTM(V), K)
    return  VDYU_VXT1(v, k);
}

INLINE( uint8_t,VDBU_VXT1) (Vdbu v, Rc(0,7) k)
{
#define     VDBU_VXT1(a, b)   vget_lane_u8(a, 07&(b))
    return  vget_lane_u64(vreinterpret_u64_u8(v),0)>>(k*8);
}

INLINE(  int8_t,VDBI_VXT1) (Vdbi v, Rc(0,7) k)
{
#define     VDBI_VXT1(a, b)   vget_lane_s8(a, 07&(b))
    uint64x1_t t = vreinterpret_u64_s8(v);
    t = vshl_u64(t, vdup_n_s64(0-8*k));
    return  vget_lane_s8(vreinterpret_s8_u64(t), 0);
}

INLINE(    char,VDBC_VXT1) (Vdbc v, Rc(0,7) k)
{
#   define  VDBC_VXT1(a, b) ((char) vget_lane_u8(VDBC_ASBU(a), (k)))
    return  vget_lane_u64(VDBC_ASDU(v), 0)>>(k*8);
}


INLINE(uint16_t,VDHU_VXT1) (Vdhu v, Rc(0,3) k)
{
#define     VDHU_VXT1(a, b)   vget_lane_u16((a),(03&(b)))
    return  vget_lane_u64(vreinterpret_u64_u16(v),0)>>(k*16);
}

INLINE( int16_t,VDHI_VXT1) (Vdhi v, Rc(0,3) k)
{
#define     VDHI_VXT1(a, b)   vget_lane_s16((a),(03&(b)))
    uint64x1_t t = vreinterpret_u64_s16(v);
    t = vshl_u64(t, vdup_n_s64(0-16*k));
    return  vget_lane_s16(vreinterpret_s16_u64(t), 0);
}

INLINE( flt16_t,VDHF_VXT1) (Vdhf v, Rc(0,3) k)
{
#define     VDHF_VXT1(a, b)   vget_lane_f16((a),(03&(b)))
    uint64x1_t t = vreinterpret_u64_f16(v);
    t = vshl_u64(t, vdup_n_s64(0-16*k));
    return  vget_lane_f16(vreinterpret_f16_u64(t), 0);
}


INLINE(uint32_t,VDWU_VXT1) (Vdwu v, Rc(0,1) k)
{
#define     VDWU_VXT1(a, b)   vget_lane_u32((a),(01&(b)))
    return  vget_lane_u64(vreinterpret_u64_u32(v),0)>>(k*32);
}

INLINE( int32_t,VDWI_VXT1) (Vdwi v, Rc(0,1) k)
{
#define     VDWI_VXT1(a, b)   vget_lane_s32((a),(01&(b)))
    uint64x1_t t = vreinterpret_u64_s32(v);
    t = vshl_u64(t, vdup_n_s64(0-32*k));
    return  vget_lane_s32(vreinterpret_s32_u64(t), 0);
}

INLINE(   float,VDWF_VXT1) (Vdwf v, Rc(0,1) k)
{
#define     VDWF_VXT1(a, b)   vget_lane_f32((a),(01&(b)))
    uint64x1_t t = vreinterpret_u64_f32(v);
    t = vshl_u64(t, vdup_n_s64(0-32*k));
    return vget_lane_s32(vreinterpret_f32_u64(t), 0);
}

INLINE(_Bool, VQYU_VXT1) (Vqyu v, Rc(0, 127) k)
{
#define      QYU_VXT1(V, K)     \
(                               \
    (_Bool)                     \
    (                           \
        (                       \
            (                   \
                vget_lane_u64(  \
                    V,          \
                    1&(K)/64    \
                )               \
            )>>(K)%64           \
        )&1                     \
    )                           \
)

#define     VQYU_VXT1(V, K)   QYU_VXT1(VQYU_ASTM(V), K)
    uint64_t y;
    if (k > 63) {
        y = vgetq_lane_u64(VQYU_ASTM(v), V2_K0);
        return (y>>(k-64))&1;
    }
    return (vgetq_lane_u64(VQYU_ASTM(v), V2_K1)>>k)&1;
}

INLINE( uint8_t,VQBU_VXT1) (Vqbu v, Rc(0,15) k)
{
#define     VQBU_VXT1(a, b) vgetq_lane_u8(a, (0xf&(b)))
    return (VDBU_VXT1)
    (
        k > 7
        ?   VQBU_VXTR(v)
        :   VQBU_VXTL(v),
        k
    );
}

INLINE(  int8_t,VQBI_VXT1) (Vqbi v, Rc(0,15) k)
{
#define     VQBI_VXT1(a, b) vgetq_lane_u8(a, (0xf&(b)))
    return (VDBI_VXT1)
    (
        k > 7
        ?   VQBI_VXTR(v)
        :   VQBI_VXTL(v),
        k
    );
}

INLINE(    char,VQBC_VXT1) (Vqbc v, Rc(0,15) k)
{
#if CHAR_MIN
#   define  VQBC_VXT1(a, b) \
((char) vgetq_lane_u8(VQBC_ASTM(a), (0xf&(b))))
    int8x16_t   q = VQBC_ASTM(v);
    int8x8_t    d = k > 7 
        ?   vget_high_s8(q)
        :   vget_low_s8(q);
    uint64x1_t  t = vreinterpret_u64_s8(d);
    t = vshl_u64(t, vdup_n_s64(-8*k));
    d = vreinterpret_s8_u64(t);
    return  vget_lane_s8(d, V8_K0);
#else
#   define  VQBC_VXT1(a, b) \
((char) vgetq_lane_u8(VQBC_ASTM(a), (0xf&(b))))
    uint8x16_t  q = VQBC_ASTM(v);
    uint8x8_t   d = k > 7 
        ?   vget_high_u8(q)
        :   vget_low_u8(q);
    uint64x1_t  t = vreinterpret_u64_u8(d);
    t = vshl_u64(t, vdup_n_s64(-8*k));
    d = vreinterpret_u8_u64(t);
    return  vget_lane_s8(d, V8_K0);

#endif
}


INLINE(uint16_t,VQHU_VXT1) (Vqhu v, Rc(0,7) k)
{
#define     VQHU_VXT1(a, b) vgetq_lane_u16(a, (07&(b)))
    return (VDHU_VXT1)
    (
        k > 3
        ?   VQHU_VXTR(v)
        :   VQHU_VXTL(v),
        k
    );
}

INLINE( int16_t,VQHI_VXT1) (Vqhi v, Rc(0,7) k)
{
#define     VQHI_VXT1(a, b) vgetq_lane_s16(a, (07&(b)))
    return (VDHU_VXT1)
    (
        k > 3
        ?   VQHI_VXTR(v)
        :   VQHI_VXTL(v),
        k
    );
}

INLINE( flt16_t,VQHF_VXT1) (Vqhf v, Rc(0,7) k)
{
#define     VQHF_VXT1(a, b) vgetq_lane_f16(a, (07&(b)))
    return (VDHF_VXT1)
    (
        k > 3
        ?   VQHF_VXTR(v)
        :   VQHF_VXTL(v),
        k
    );
}

INLINE(uint32_t,VQWU_VXT1) (Vqwu v, Rc(0,3) k)
{
#define     VQWU_VXT1(a, b) vgetq_lane_u32(a, (03&(b)))
    return (VDWU_VXT1)
    (
        k > 1
        ?   VQWU_VXTR(v)
        :   VQWU_VXTL(v),
        k
    );
}
    

INLINE( int32_t,VQWI_VXT1) (Vqwi v, Rc(0,3) k)
{
#define     VQWI_VXT1(a, b) vgetq_lane_s32(a, (03&(b)))
    return (VDWI_VXT1)
    (
        k > 1
        ?   VQWI_VXTR(v)
        :   VQWI_VXTL(v),
        k
    );
}

INLINE(  float,VQWF_VXT1) (Vqwf v, Rc(0,3) k)
{
#define     VQWF_VXT1(a, b) vgetq_lane_f32(a, (03&(b)))
    return (VDWF_VXT1)
    (
        k > 1
        ?   VQWF_VXTR(v)
        :   VQWF_VXTL(v),
        k
    );
}

INLINE(uint64_t,VQDU_VXT1) (Vqdu v, Rc(0,1) k)
{
#define     VQDU_VXT1(a, b)     vgetq_lane_u64(a, (01&(b)))
    return  k 
    ?   vgetq_lane_u64(v, 1)
    :   vgetq_lane_u64(v, 0);
}

INLINE( int64_t,VQDI_VXT1) (Vqdi v, Rc(0,1) k)
{
#define     VQDI_VXT1(a, b)     vgetq_lane_s64(a, (01&(b)))
    return  k 
    ?   vgetq_lane_s64(v, 1)
    :   vgetq_lane_s64(v, 0);
}

INLINE( int64_t,VQDF_VXT1) (Vqdf v, Rc(0,1) k)
{
#define     VQDF_VXT1(a, b)     vgetq_lane_f64(a, (01&(b)))
    return  k 
    ?   vgetq_lane_f64(v, 1)
    :   vgetq_lane_f64(v, 0);
}

#if _LEAVE_EXTGOP_ARM_VXT1
}
#endif

#if _LEAVE_EXTGOP_ARM_VXT_
}
#endif

#if _ENTER_EXTGOP_ARM_NOTY
{
#endif

#define     DYU_NOTY(M)     \
vreinterpret_u64_u8(vmvn_u8(vreinterpret_u8_u64(M)))

#define     DBU_NOTY        vmvn_u8
#define     DBI_NOTY        vmvn_s8
#define     DBC_NOTY        VQBC_BASE(NOTY)
#define     DHU_NOTY        vmvn_u16
#define     DHI_NOTY        vmvn_s16
#define     DHF_NOTY(M)     \
vreinterpret_f16_u8(vmvn_u8(vreinterpret_u8_f16(M)))

#define     DWU_NOTY        vmvn_u32
#define     DWI_NOTY        vmvn_s32
#define     DWF_NOTY(M)     \
vreinterpret_f32_u8(vmvn_u8(vreinterpret_u8_f32(M)))

#define     DDU_NOTY(M)     \
vreinterpret_u64_u8(vmvn_u8(vreinterpret_u8_u64(M)))

#define     DDI_NOTY(M)     \
vreinterpret_s64_u8(vmvn_u8(vreinterpret_u8_s64(M)))

#define     DDF_NOTY(M)     \
vreinterpret_f64_u8(vmvn_u8(vreinterpret_u8_f64(M)))



#define     QYU_NOTY(M)     \
vreinterpretq_u64_u8(vmvnq_u8(vreinterpretq_u8_u64(M)))

#define     QBU_NOTY        vmvnq_u8
#define     QBI_NOTY        vmvnq_s8
#define     QBC_NOTY        VQBC_BASE(NOTY)
#define     QHU_NOTY        vmvnq_u16
#define     QHI_NOTY        vmvnq_s16
#define     QHF_NOTY(M)     \
vreinterpretq_f16_u8(vmvnq_u8(vreinterpretq_u8_f16(M)))

#define     QWU_NOTY        vmvnq_u32
#define     QWI_NOTY        vmvnq_s32
#define     QWF_NOTY(M)     \
vreinterpretq_f32_u8(vmvnq_u8(vreinterpretq_u8_f32(M)))

#define     QDU_NOTY(M)     \
vreinterpretq_u64_u8(vmvnq_u8(vreinterpretq_u8_u64(M)))

#define     QDI_NOTY(M)     \
vreinterpretq_s64_u8(vmvnq_u8(vreinterpretq_u8_s64(M)))

#define     QDF_NOTY(M)     \
vreinterpretq_f64_u8(vmvnq_u8(vreinterpretq_u8_f64(M)))


INLINE(Vwyu,VWYU_NOTY) (Vwyu v)
{
#define     VWYU_NOTY   VWYU_NOTY
    float32x2_t f = vset_lane_f32(VWYU_ASTM(v),f,V2_K0);
    uint8x8_t   u = vmvn_u8(vreinterpret_u8_f32(f));
    return  WYU_ASTV(vget_lane_f32(vreinterpret_f32_u8(u), V2_K0));
}

INLINE(Vwbu,VWBU_NOTY) (Vwbu v)
{
#define     VWBU_NOTY   VWBU_NOTY
    float32x2_t f = vset_lane_f32(VWBU_ASTM(v),f,V2_K0);
    uint8x8_t   u = vmvn_u8(vreinterpret_u8_f32(f));
    return  WBU_ASTV(vget_lane_f32(vreinterpret_f32_u8(u), V2_K0));
}

INLINE(Vwbi,VWBI_NOTY) (Vwbi v)
{
#define     VWBI_NOTY   VWBI_NOTY
    float32x2_t f = vset_lane_f32(VWBI_ASTM(v),f,V2_K0);
    uint8x8_t   u = vmvn_u8(vreinterpret_u8_f32(f));
    return  WBI_ASTV(vget_lane_f32(vreinterpret_f32_u8(u), V2_K0));
}

INLINE(Vwbc,VWBC_NOTY) (Vwbc v)
{
#define     VWBC_NOTY   VWBC_NOTY
    float32x2_t f = vset_lane_f32(VWBC_ASTM(v),f,V2_K0);
    uint8x8_t   u = vmvn_u8(vreinterpret_u8_f32(f));
    return  WBC_ASTV(vget_lane_f32(vreinterpret_f32_u8(u), V2_K0));
}


INLINE(Vwhu,VWHU_NOTY) (Vwhu v)
{
#define     VWHU_NOTY   VWHU_NOTY
    float32x2_t f = vset_lane_f32(VWHU_ASTM(v),f,V2_K0);
    uint8x8_t   u = vmvn_u8(vreinterpret_u8_f32(f));
    return  WHU_ASTV(vget_lane_f32(vreinterpret_f32_u8(u), V2_K0));
}

INLINE(Vwhi,VWHI_NOTY) (Vwhi v)
{
#define     VWHI_NOTY   VWHI_NOTY
    float32x2_t f = vset_lane_f32(VWHI_ASTM(v),f,V2_K0);
    uint8x8_t   u = vmvn_u8(vreinterpret_u8_f32(f));
    return  WHI_ASTV(vget_lane_f32(vreinterpret_f32_u8(u), V2_K0));
}

INLINE(Vwhf,VWHF_NOTY) (Vwhf v)
{
#define     VWHF_NOTY   VWHF_NOTY
    float32x2_t f = vset_lane_f32(VWHF_ASTM(v),f,V2_K0);
    uint8x8_t   u = vmvn_u8(vreinterpret_u8_f32(f));
    return  WHF_ASTV(vget_lane_f32(vreinterpret_f32_u8(u), V2_K0));
}


INLINE(Vwwu,VWWU_NOTY) (Vwwu v)
{
#define     VWWU_NOTY   VWWU_NOTY
    float32x2_t f = vset_lane_f32(VWWU_ASTM(v),f,V2_K0);
    uint8x8_t   u = vmvn_u8(vreinterpret_u8_f32(f));
    return  WWU_ASTV(vget_lane_f32(vreinterpret_f32_u8(u), V2_K0));
}

INLINE(Vwwi,VWWI_NOTY) (Vwwi v)
{
#define     VWWI_NOTY   VWWI_NOTY
    float32x2_t f = vset_lane_f32(VWWI_ASTM(v),f,V2_K0);
    uint8x8_t   u = vmvn_u8(vreinterpret_u8_f32(f));
    return  WWI_ASTV(vget_lane_f32(vreinterpret_f32_u8(u), V2_K0));
}

INLINE(Vwwf,VWWF_NOTY) (Vwwf v)
{
#define     VWWF_NOTY   VWWF_NOTY
    float32x2_t f = vset_lane_f32(VWWF_ASTM(v),f,V2_K0);
    uint8x8_t   u = vmvn_u8(vreinterpret_u8_f32(f));
    return  WWF_ASTV(vget_lane_f32(vreinterpret_f32_u8(u), V2_K0));
}


INLINE(Vdyu,VDYU_NOTY) (Vdyu v)
{
#define     VDYU_NOTY   VDYU_NOTY
    uint8x8_t   m = vmvn_u8(vreinterpret_u8_u64(VDYU_ASTM(v)));
    return  DYU_ASTV(vreinterpret_u64_u8(m));
}


INLINE(Vdbu,VDBU_NOTY) (Vdbu v)
{
#define     VDBU_NOTY   DBU_NOTY
    return  VDBU_NOTY(v);
}

INLINE(Vdbi,VDBI_NOTY) (Vdbi v)
{
#define     VDBI_NOTY   DBI_NOTY
    return  VDBI_NOTY(v);
}

INLINE(Vdbc,VDBC_NOTY) (Vdbc v)
{
#define     VDBC_NOTY   VDBC_NOTY
    uint8x8_t   m = vmvn_u8(vreinterpret_u8_f16(VDBC_ASTM(v)));
    return  DBC_ASTV(DBU_ASBC(m));
}


INLINE(Vdhu,VDHU_NOTY) (Vdhu v)
{
#define     VDHU_NOTY   DHU_NOTY
    return  VDHU_NOTY(v);
}

INLINE(Vdhi,VDHI_NOTY) (Vdhi v)
{
#define     VDHI_NOTY   DHI_NOTY
    return  VDHI_NOTY(v);
}

INLINE(Vdhf,VDHF_NOTY) (Vdhf v)
{
#define     VDHF_NOTY   VDHF_NOTY
    uint8x8_t   m = vmvn_u8(vreinterpret_u8_f16(VDHF_ASTM(v)));
    return  DHF_ASTV(vreinterpret_f16_u8(m));
}


INLINE(Vdwu,VDWU_NOTY) (Vdwu v)
{
#define     VDWU_NOTY   DWU_NOTY
    return  VDWU_NOTY(v);
}

INLINE(Vdwi,VDWI_NOTY) (Vdwi v)
{
#define     VDWI_NOTY   DWI_NOTY
    return  VDWI_NOTY(v);
}

INLINE(Vdwf,VDWF_NOTY) (Vdwf v)
{
#define     VDWF_NOTY   VDWF_NOTY
    uint8x8_t   m = vmvn_u8(vreinterpret_u8_f32(VDWF_ASTM(v)));
    return  DWF_ASTV(vreinterpret_f32_u8(m));
}


INLINE(Vddu,VDDU_NOTY) (Vddu v)
{
#define     VDDU_NOTY   DDU_NOTY
    return  VDDU_NOTY(v);
}

INLINE(Vddi,VDDI_NOTY) (Vddi v)
{
#define     VDDI_NOTY   DDI_NOTY
    return  VDDI_NOTY(v);
}

INLINE(Vddf,VDDF_NOTY) (Vddf v)
{
#define     VDDF_NOTY   VDDF_NOTY
    uint8x8_t   m = vmvn_u8(vreinterpret_u8_f64(VDDF_ASTM(v)));
    return  DDF_ASTV(vreinterpret_f64_u8(m));
}


INLINE(Vqyu,VQYU_NOTY) (Vqyu v)
{
#define     VQYU_NOTY   VQYU_NOTY
    uint8x16_t   m = vmvnq_u8(vreinterpretq_u8_u64(VQYU_ASTM(v)));
    return  QYU_ASTV(vreinterpretq_u64_u8(m));
}


INLINE(Vqbu,VQBU_NOTY) (Vqbu v)
{
#define     VQBU_NOTY   QBU_NOTY
    return  VQBU_NOTY(v);
}

INLINE(Vqbi,VQBI_NOTY) (Vqbi v)
{
#define     VQBI_NOTY   QBI_NOTY
    return  VQBI_NOTY(v);
}

INLINE(Vqbc,VQBC_NOTY) (Vqbc v)
{
#define     VQBC_NOTY   VQBC_NOTY
    uint8x16_t   m = vmvnq_u8(vreinterpretq_u8_f16(VQBC_ASTM(v)));
    return  QBC_ASTV(QBU_ASBC(m));
}


INLINE(Vqhu,VQHU_NOTY) (Vqhu v)
{
#define     VQHU_NOTY   QHU_NOTY
    return  VQHU_NOTY(v);
}

INLINE(Vqhi,VQHI_NOTY) (Vqhi v)
{
#define     VQHI_NOTY   QHI_NOTY
    return  VQHI_NOTY(v);
}

INLINE(Vqhf,VQHF_NOTY) (Vqhf v)
{
#define     VQHF_NOTY   VQHF_NOTY
    uint8x16_t   m = vmvnq_u8(vreinterpretq_u8_f16(VQHF_ASTM(v)));
    return  QHF_ASTV(vreinterpretq_f16_u8(m));
}


INLINE(Vqwu,VQWU_NOTY) (Vqwu v)
{
#define     VQWU_NOTY   QWU_NOTY
    return  VQWU_NOTY(v);
}

INLINE(Vqwi,VQWI_NOTY) (Vqwi v)
{
#define     VQWI_NOTY   QWI_NOTY
    return  VQWI_NOTY(v);
}

INLINE(Vqwf,VQWF_NOTY) (Vqwf v)
{
#define     VQWF_NOTY   VQWF_NOTY
    uint8x16_t   m = vmvnq_u8(vreinterpretq_u8_f32(VQWF_ASTM(v)));
    return  QWF_ASTV(vreinterpretq_f32_u8(m));
}


INLINE(Vqdu,VQDU_NOTY) (Vqdu v)
{
#define     VQDU_NOTY   QDU_NOTY
    return  VQDU_NOTY(v);
}

INLINE(Vqdi,VQDI_NOTY) (Vqdi v)
{
#define     VQDI_NOTY   QDI_NOTY
    return  VQDI_NOTY(v);
}

INLINE(Vqdf,VQDF_NOTY) (Vqdf v)
{
#define     VQDF_NOTY   VQDF_NOTY
    uint8x16_t   m = vmvnq_u8(vreinterpretq_u8_f64(VQDF_ASTM(v)));
    return  QDF_ASTV(vreinterpretq_f64_u8(m));
}

#if _LEAVE_EXTGOP_ARM_NOTY
}
#endif

#if _ENTER_EXTGOP_ARM_CE__
{
#endif

#if _ENTER_EXTGOP_ARM_CEQ_
{
#endif

#if _ENTER_EXTGOP_ARM_CEQS
{
#endif

INLINE(uintptr_t, ADDR_CEQS) (void const *a, void const *b)
{
    return UINTPTR_C(0)-(a==b);
}

INLINE(uchar, UCHAR_CEQS) (uchar a,  uchar b)
{
    return a==b ? 0xff : 0;
}

INLINE(schar, SCHAR_CEQS) (schar a, schar b)
{
    return a==b ? -1 : 0;
}

INLINE(char, CHAR_CEQS) (char a, char b)
{
    return a==b ? '\xff' : '\x00';
}


INLINE(ushort, USHRT_CEQS) (ushort a, ushort b)
{
    return a==b ? 0xffff : 0;
}

INLINE(short, SHRT_CEQS) (short a, short b)
{
    return a==b ? -1 : 0;
}

INLINE(uint, UINT_CEQS) (uint a, uint b)
{
    return 0u-(a==b);
}

INLINE(int, INT_CEQS) (int a, int b)
{
    return 0-(a==b);
}

INLINE(ulong, ULONG_CEQS) (ulong a, ulong b)
{
    return 0ul-(a==b);
}

INLINE(long, LONG_CEQS) (long a, long b)
{
    return 0l-(a==b);
}

INLINE(ullong, ULLONG_CEQS) (ullong a, ullong b)
{
    return 0ull-(a==b);
}

INLINE(llong, LLONG_CEQS) (llong a, llong b)
{
    return 0ll-(a==b);
}

INLINE(int16_t, FLT16_CEQS) (flt16_t a, flt16_t b)
{
    return INT16_C(0)-(a==b);
}

INLINE(int32_t, FLT_CEQS) (float a, float b)
{
    return  vceqs_f32(a, b);
}

INLINE(int64_t, DBL_CEQS) (double a, double b)
{
    return  vceqd_f64(a, b);
}

#define MY_CEQD(U, S, F, A, B)  \
vreinterpret_##S(               \
    vceq_u##F(                  \
        vreinterpret_##U(A),    \
        vreinterpret_##U(B)     \
    )                           \
)

#define MY_CEQQ(U, S, F, A, B)  \
vreinterpretq_##S(              \
    vceqq_u##F(                 \
        vreinterpretq_##U(A),   \
        vreinterpretq_##U(B)    \
    )                           \
)
// *YU_CEQS would be semantically identical to *YU_ANDS

//efine     DYU_CEQS(A, B)      vceq_u64(A,B)
#define     DBU_CEQS(A, B)      vceq_u8(A,B)

#define     DBI_CEQS(A, B)      MY_CEQD(s8_u8,u8_s8,u8,A,B)
#if CHAR_MIN
#   define  DBC_CEQS(A, B)      MY_CEQD(s8_u8,u8_s8,u8,A,B)
#else
#   define  DBC_CEQS(A, B)      vceq_u8(A,B)
#endif

#define     DHU_CEQS(A, B)      vceq_u16(A,B)
#define     DHI_CEQS(A, B)      MY_CEQD(s16_u16,u16_s16,u16,A,B)
#define     DHF_CEQS(A, B)      MY_CEQD(f16_u16,u16_s16,u16,A,B)
#define     DWU_CEQS(A, B)      vceq_u32(A,B)
#define     DWI_CEQS(A, B)      MY_CEQD(s32_u32,u32_s32,u32,A,B)
#define     DWF_CEQS(A, B)      MY_CEQD(f32_u32,u32_s32,u32,A,B)
#define     DDU_CEQS(A, B)      vceq_u64(A,B)
#define     DDI_CEQS(A, B)      MY_CEQD(s64_u64,u64_s64,u64,A,B)
#define     DDF_CEQS(A, B)      MY_CEQD(f64_u64,u64_s64,u64,A,B)

#define     QYU_CEQS(A, B)      vceq_u64(A,B)
#define     QBU_CEQS(A, B)      vceq_u8(A,B)
#define     QBI_CEQS(A, B)      MY_CEQQ(s8_u8,u8_s8,u8,A,B)
#define     QHU_CEQS(A, B)      vceq_u16
#define     QHI_CEQS(A, B)      MY_CEQQ(s16_u16,u16_s16,u16,A,B)
#define     QHF_CEQS(A, B)      MY_CEQQ(f16_u16,u16_s16,u16,A,B)
#define     QWU_CEQS            vceq_u32
#define     QWI_CEQS(A, B)      MY_CEQQ(s32_u32,u32_s32,u32,A,B)
#define     QWF_CEQS(A, B)      MY_CEQQ(f32_u32,u32_s32,u32,A,B)
#define     QDU_CEQS            vceq_u64
#define     QDI_CEQS(A, B)      MY_CEQQ(s64_u64,u64_s64,u64,A,B)
#define     QDF_CEQS(A, B)      MY_CEQQ(f64_u64,u64_s64,u64,A,B)


INLINE(Vwbu,VWBU_CEQS) (Vwbu a, Vwbu b)
{
    float32x2_t l = vset_lane_f32(VWBU_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWBU_ASTM(a), r, V2_K0);
    uint8x8_t   p = vreinterpret_u8_f32(l);
    uint8x8_t   q = vreinterpret_u8_f32(r);
    return WBU_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u8(DBU_CEQS(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwbi,VWBI_CEQS) (Vwbi a, Vwbi b)
{
    float32x2_t l = vset_lane_f32(VWBI_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWBI_ASTM(a), r, V2_K0);
    uint8x8_t   p = vreinterpret_u8_f32(l);
    uint8x8_t   q = vreinterpret_u8_f32(r);
    return  WBI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u8(DBU_CEQS(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwbc,VWBC_CEQS) (Vwbc a, Vwbc b)
{
    float32x2_t l = vset_lane_f32(VWBC_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWBC_ASTM(a), r, V2_K0);
    uint8x8_t   p = vreinterpret_u8_f32(l);
    uint8x8_t   q = vreinterpret_u8_f32(r);
    return  WBC_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u8(DBU_CEQS(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwhu,VWHU_CEQS) (Vwhu a, Vwhu b)
{
    float32x2_t l = vset_lane_f32(VWHU_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWHU_ASTM(a), r, V2_K0);
    uint16x4_t  p = vreinterpret_u16_f32(l);
    uint16x4_t  q = vreinterpret_u16_f32(r);
    return  WHU_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u16(DHU_CEQS(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwhi,VWHI_CEQS) (Vwhi a, Vwhi b)
{
    float32x2_t l = vset_lane_f32(VWHI_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWHI_ASTM(a), r, V2_K0);
    uint16x4_t  p = vreinterpret_u16_f32(l);
    uint16x4_t  q = vreinterpret_u16_f32(r);
    return  WHI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u16(DHU_CEQS(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwhf,VWHF_CEQS) (Vwhf a, Vwhf b)
{
    float32x2_t l = vset_lane_f32(VWHF_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWHF_ASTM(a), r, V2_K0);
    uint16x4_t  p = vreinterpret_u16_f32(l);
    uint16x4_t  q = vreinterpret_u16_f32(r);
    return  WHF_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u16(DHU_CEQS(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwwu,VWWU_CEQS) (Vwwu a, Vwwu b)
{
    float32x2_t l = vset_lane_f32(VWWU_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWWU_ASTM(a), r, V2_K0);
    uint32x2_t  p = vreinterpret_u32_f32(l);
    uint32x2_t  q = vreinterpret_u32_f32(r);
    return  WWU_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u32(DWU_CEQS(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwwi,VWWI_CEQS) (Vwwi a, Vwwi b)
{
    float32x2_t l = vset_lane_f32(VWWI_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWWI_ASTM(a), r, V2_K0);
    uint32x2_t  p = vreinterpret_u32_f32(l);
    uint32x2_t  q = vreinterpret_u32_f32(r);
    return  WWI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u32(DWU_CEQS(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwwf,VWWF_CEQS) (Vwwf a, Vwwf b)
{
    float32x2_t l = vset_lane_f32(VWWF_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWWF_ASTM(a), r, V2_K0);
    uint32x2_t  p = vreinterpret_u32_f32(l);
    uint32x2_t  q = vreinterpret_u32_f32(r);
    return  WWF_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u32(DWU_CEQS(p, q)),
            V2_K0
        )
    );
}

#define     VDBU_CEQS       DBU_CEQS
#define     VDBI_CEQS       DBI_CEQS
#define     VDBC_CEQS(A, B) \
DBC_ASTV(                   \
    DBC_CEQS(               \
        VDBC_ASTM(A),       \
        VDBC_ASTM(B)        \
    )                       \
)
#define     VDHU_CEQS       DHU_CEQS
#define     VDHI_CEQS       DHI_CEQS
#define     VDHF_CEQS       DHF_CEQS
#define     VDWU_CEQS       DWU_CEQS
#define     VDWI_CEQS       DWI_CEQS
#define     VDWF_CEQS       DWF_CEQS
#define     VDDU_CEQS       DDU_CEQS
#define     VDDI_CEQS       DDI_CEQS
#define     VDDF_CEQS       DDF_CEQS

#define     VQBU_CEQS       QBU_CEQS
#define     VQBI_CEQS       QBI_CEQS
#define     VQBC_CEQS(A, B) \
QBC_ASTV(                   \
    QBC_CEQS(               \
        VQBC_ASTM(A),       \
        VQBC_ASTM(B)        \
    )                       \
)
#define     VQHU_CEQS       QHU_CEQS
#define     VQHI_CEQS       QHI_CEQS
#define     VQHF_CEQS       QHF_CEQS
#define     VQWU_CEQS       QWU_CEQS
#define     VQWI_CEQS       QWI_CEQS
#define     VQWF_CEQS       QWF_CEQS
#define     VQDU_CEQS       QDU_CEQS
#define     VQDI_CEQS       QDI_CEQS
#define     VQDF_CEQS       QDF_CEQS

#if _LEAVE_EXTGOP_ARM_CEQS
}
#endif

#if _ENTER_EXTGOP_ARM_CEQY
{
#endif

//efine     WYU_CEQY
INLINE( Wbu,WBU_CEQY) (Wbu a, Wbu b)
{
#define     WBU_CEQY    WBU_CEQY
    float32x2_t p = vset_lane_f32(a, p, V2_K0);
    float32x2_t q = vset_lane_f32(b, q, V2_K0);
    uint8x8_t   r = vceq_u8(
        vreinterpret_u8_f32(p),
        vreinterpret_u8_f32(q)
    );
    return  vget_lane_f32(
        vreinterpret_f32_u8(vshr_n_u8(r, 7)),
        V2_K0
    );
}

INLINE( Wbu,WBI_CEQY) (Wbi a, Wbi b)
{
#define     WBI_CEQY    WBI_CEQY
    float32x2_t p = vset_lane_f32(a, p, V2_K0);
    float32x2_t q = vset_lane_f32(b, q, V2_K0);
    return  vget_lane_f32(
        vreinterpret_f32_u8(
            vshr_n_u8(
                vceq_s8(
                    vreinterpret_s8_f32(p), 
                    vreinterpret_s8_f32(q)
                ),
                7
            )
        ),
        V2_K0
    );
}
#if CHAR_MIN
#   define  WBC_CEQY    WBI_CEQY
#else
#   define  WBC_CEQY    WBU_CEQY
#endif

INLINE( Whu,WHU_CEQY) (Whu a, Whu b)
{
#define     WHU_CEQY    WHU_CEQY
    float32x2_t p = vset_lane_f32(a, p, V2_K0);
    float32x2_t q = vset_lane_f32(b, q, V2_K0);
    return  vget_lane_f32(
        vreinterpret_f32_u16(
            vshr_n_u16(
                vceq_u16(
                    vreinterpret_u16_f32(p), 
                    vreinterpret_u16_f32(q)
                ),
                15
            )
        ),
        V2_K0
    );
}

INLINE( Whu,WHI_CEQY) (Whi a, Whi b)
{
#define     WHI_CEQY    WHI_CEQY
    float32x2_t p = vset_lane_f32(a, p, V2_K0);
    float32x2_t q = vset_lane_f32(b, q, V2_K0);
    return  vget_lane_f32(
        vreinterpret_f32_u16(
            vshr_n_u16(
                vceq_s16(
                    vreinterpret_s16_f32(p), 
                    vreinterpret_s16_f32(q)
                ),
                15
            )
        ),
        V2_K0
    );
}

INLINE( Whu,WHF_CEQY) (Whf a, Whf b)
{
#define     WHF_CEQY    WHF_CEQY
    float32x2_t p = vset_lane_f32(a, p, V2_K0);
    float32x2_t q = vset_lane_f32(b, q, V2_K0);
#if defined(SPC_ARM_FP16_SIMD)
    return  vget_lane_f32(
        vreinterpret_f32_u16(
            vshr_n_u16(
                vceq_s16(
                    vreinterpret_s16_f32(p), 
                    vreinterpret_s16_f32(q)
                ),
                15
            )
        ),
        V2_K0
    );
#else
    float32x4_t l = vcvt_f32_f16(vreinterpret_f16_f32(p));
    float32x4_t r = vcvt_f32_f16(vreinterpret_f16_f32(q));
    uint16x4_t  v = vshr_n_u16(vmovn_u32(vceqq_f32(l, r)), 15);
    return  vget_lane_f32(vreinterpret_f32_u16(v), V2_K0);
#endif
}


INLINE( Wwu,WWU_CEQY) (Wwu a, Wwu b)
{
#define     WWU_CEQY    WWU_CEQY
    float32x2_t p = vset_lane_f32(a, p, V2_K0);
    float32x2_t q = vset_lane_f32(b, q, V2_K0);
    return  vget_lane_f32(
        vreinterpret_f32_u32(
            vshr_n_u32(
                vceq_u32(
                    vreinterpret_u32_f32(p), 
                    vreinterpret_u32_f32(q)
                ),
                31
            )
        ),
        V2_K0
    );
}

INLINE( Wwu,WWI_CEQY) (Wwi a, Wwi b)
{
#define     WWI_CEQY    WWI_CEQY
    float32x2_t p = vset_lane_f32(a, p, V2_K0);
    float32x2_t q = vset_lane_f32(b, q, V2_K0);
    return  vget_lane_f32(
        vreinterpret_f32_u32(
            vshr_n_u32(
                vceq_s32(
                    vreinterpret_s32_f32(p), 
                    vreinterpret_s32_f32(q)
                ),
                31
            )
        ),
        V2_K0
    );
}

INLINE( Wwu,WWF_CEQY) (Wwf a, Wwf b)
{
#define     WWF_CEQY    WWF_CEQY
    float32x2_t p = vset_lane_f32(a, p, V2_K0);
    float32x2_t q = vset_lane_f32(b, q, V2_K0);
    return  vget_lane_f32(
        vreinterpret_f32_u32(vshr_n_u32(vceq_f32(p, q), 31)),
        V2_K0
    );
}

#define     DBU_CEQY(A, B)  vshr_n_u8(vceq_u8(A,B), 7)
#define     DBI_CEQY(A, B)  vshr_n_u8(vceq_s8(A,B), 7)
#if CHAR_MIN
#   define  DBC_CEQY(A, B)  DBI_CEQY(A, B)
#else
#   define  DBC_CEQY(A, B)  DBU_CEQY(A, B)
#endif

#define     DHU_CEQY(A, B)  vshr_n_u16(vceq_u16(A,B),15)
#define     DHI_CEQY(A, B)  vshr_n_u16(vceq_s16(A,B),15)
#if defined(SPC_ARM_FP16_SIMD)
#   define  DHF_CEQY(A, B)  vshr_n_u16(vceq_f16(A,B),15)
#else
#   define  DHF_CEQY(A, B)  \
vshr_n_u16(                 \
    vmovn_u32(              \
        vceqq_f32(          \
            vcvt_f32_f16(a),\
            vcvt_f32_f16(b) \
        )                   \
    ),                      \
    15                      \
)

#endif

#define     DWU_CEQY(A, B)  vshr_n_u32(vceq_u32(A,B),31)
#define     DWI_CEQY(A, B)  vshr_n_u32(vceq_s32(A,B),31)
#define     DWF_CEQY(A, B)  vshr_n_u32(vceq_f32(A,B),31)
#define     DDU_CEQY(A, B)  vshr_n_u64(vceq_u64(A,B),63)
#define     DDI_CEQY(A, B)  vshr_n_u64(vceq_s64(A,B),63)
#define     DDF_CEQY(A, B)  vshr_n_u64(vceq_f64(A,B),63)

#define     QBU_CEQY(A, B)  vshrq_n_u8(vceqq_u8(A,B), 7)
#define     QBI_CEQY(A, B)  vshrq_n_u8(vceqq_s8(A,B), 7)
#if CHAR_MIN
#   define  QBC_CEQY(A, B)  QBI_CEQY(A, B)
#else
#   define  QBC_CEQY(A, B)  QBU_CEQY(A, B)
#endif

#define     QHU_CEQY(A, B)  vshrq_n_u16(vceqq_u16(A,B),15)
#define     QHI_CEQY(A, B)  vshrq_n_u16(vceqq_s16(A,B),15)
#if defined(SPC_ARM_FP16_SIMD)
#   define  QHF_CEQY(A, B)  vshrq_n_u16(vceqq_f16(A,B),15)
#else
#   define  QHF_CEQY(A, B)                      \
vshrq_n_u16(                                    \
    vcombine_u16(                               \
        vmovn_u32(                              \
            vceqq_f32(                          \
                vcvt_f32_f16(vget_low_f16(A)),  \
                vcvt_f32_f16(vget_low_f16(B))   \
            )                                   \
        ),                                      \
        vmovn_u32(                              \
            vceqq_f32(                          \
                vcvt_f32_f16(vget_high_f16(A)), \
                vcvt_f32_f16(vget_high_f16(B))  \
            )                                   \
        )                                       \
    ),                                          \
    15                                          \
)
#endif

#define     QWU_CEQY(A, B)  vshrq_n_u32(vceqq_u32(A,B),31)
#define     QWI_CEQY(A, B)  vshrq_n_u32(vceqq_s32(A,B),31)
#define     QWF_CEQY(A, B)  vshrq_n_u32(vceqq_f32(A,B),31)

#define     QDU_CEQY(A, B)  vshrq_n_u64(vceqq_u64(A,B),63)
#define     QDI_CEQY(A, B)  vshrq_n_u64(vceqq_s64(A,B),63)
#define     QDF_CEQY(A, B)  vshrq_n_u64(vceqq_f64(A,B),63)


INLINE(Vwbu,VWBU_CEQY)(Vwbu a, Vwbu b)
{
#define     VWBU_CEQY(A, B) WBU_ASTV(WBU_CEQY(VWBU_ASTM(A),VWBU_ASTM(B)))
    return  VWBU_CEQY(a, b);
}

INLINE(Vwbu,VWBI_CEQY)(Vwbi a, Vwbi b)
{
#define     VWBI_CEQY(A, B) WBU_ASTV(WBI_CEQY(VWBI_ASTM(A),VWBI_ASTM(B)))
    return  VWBI_CEQY(a, b);
}

INLINE(Vwbu,VWBC_CEQY)(Vwbc a, Vwbc b)
{
#define     VWBC_CEQY(A, B) WBU_ASTV(WBC_CEQY(VWBC_ASTM(A),VWBC_ASTM(B)))
    return  VWBC_CEQY(a, b);
}


INLINE(Vwhu,VWHU_CEQY)(Vwhu a, Vwhu b)
{
#define     VWHU_CEQY(A, B) WHU_ASTV(WHU_CEQY(VWHU_ASTM(A),VWHU_ASTM(B)))
    return  VWHU_CEQY(a, b);
}

INLINE(Vwhu,VWHI_CEQY)(Vwhi a, Vwhi b)
{
#define     VWHI_CEQY(A, B) WHU_ASTV(WHI_CEQY(VWHI_ASTM(A),VWHI_ASTM(B)))
    return  VWHI_CEQY(a, b);
}

INLINE(Vwhu,VWHF_CEQY)(Vwhf a, Vwhf b)
{
#define     VWHF_CEQY(A, B) WHU_ASTV(WHF_CEQY(VWHF_ASTM(A),VWHF_ASTM(B)))
    return  VWHF_CEQY(a, b);
}


INLINE(Vwwu,VWWU_CEQY)(Vwwu a, Vwwu b)
{
#define     VWWU_CEQY(A, B) WWU_ASTV(WWU_CEQY(VWWU_ASTM(A),VWWU_ASTM(B)))
    return  VWWU_CEQY(a, b);
}

INLINE(Vwwu,VWWI_CEQY)(Vwwi a, Vwwi b)
{
#define     VWWI_CEQY(A, B) WWU_ASTV(WWI_CEQY(VWWI_ASTM(A),VWWI_ASTM(B)))
    return  VWWI_CEQY(a, b);
}

INLINE(Vwwu,VWWF_CEQY)(Vwwf a, Vwwf b)
{
#define     VWWF_CEQY(A, B) WWU_ASTV(WWF_CEQY(VWWF_ASTM(A),VWWF_ASTM(B)))
    return  VWWF_CEQY(a, b);
}


INLINE(Vdbu,VDBU_CEQY)(Vdbu a, Vdbu b)
{
#define     VDBU_CEQY(A, B) DBU_ASTV(DBU_CEQY(VDBU_ASTM(A),VDBU_ASTM(B)))
    return  VDBU_CEQY(a, b);
}

INLINE(Vdbu,VDBI_CEQY)(Vdbi a, Vdbi b)
{
#define     VDBI_CEQY(A, B) DBU_ASTV(DBI_CEQY(VDBI_ASTM(A),VDBI_ASTM(B)))
    return  VDBI_CEQY(a, b);
}

INLINE(Vdbu,VDBC_CEQY)(Vdbc a, Vdbc b)
{
#define     VDBC_CEQY(A, B) DBU_ASTV(DBC_CEQY(VDBC_ASTM(A),VDBC_ASTM(B)))
    return  VDBC_CEQY(a, b);
}


INLINE(Vdhu,VDHU_CEQY)(Vdhu a, Vdhu b)
{
#define     VDHU_CEQY(A, B) DHU_ASTV(DHU_CEQY(VDHU_ASTM(A),VDHU_ASTM(B)))
    return  VDHU_CEQY(a, b);
}

INLINE(Vdhu,VDHI_CEQY)(Vdhi a, Vdhi b)
{
#define     VDHI_CEQY(A, B) DHU_ASTV(DHI_CEQY(VDHI_ASTM(A),VDHI_ASTM(B)))
    return  VDHI_CEQY(a, b);
}

INLINE(Vdhu,VDHF_CEQY)(Vdhf a, Vdhf b)
{
#define     VDHF_CEQY(A, B) DHU_ASTV(DHF_CEQY(VDHF_ASTM(A),VDHF_ASTM(B)))
    return  VDHF_CEQY(a, b);
}


INLINE(Vdwu,VDWU_CEQY)(Vdwu a, Vdwu b)
{
#define     VDWU_CEQY(A, B) DWU_ASTV(DWU_CEQY(VDWU_ASTM(A),VDWU_ASTM(B)))
    return  VDWU_CEQY(a, b);
}

INLINE(Vdwu,VDWI_CEQY)(Vdwi a, Vdwi b)
{
#define     VDWI_CEQY(A, B) DWU_ASTV(DWI_CEQY(VDWI_ASTM(A),VDWI_ASTM(B)))
    return  VDWI_CEQY(a, b);
}

INLINE(Vdwu,VDWF_CEQY)(Vdwf a, Vdwf b)
{
#define     VDWF_CEQY(A, B) DWU_ASTV(DWF_CEQY(VDWF_ASTM(A),VDWF_ASTM(B)))
    return  VDWF_CEQY(a, b);
}


INLINE(Vddu,VDDU_CEQY)(Vddu a, Vddu b)
{
#define     VDDU_CEQY(A, B) DDU_ASTV(DDU_CEQY(VDDU_ASTM(A),VDDU_ASTM(B)))
    return  VDDU_CEQY(a, b);
}

INLINE(Vddu,VDDI_CEQY)(Vddi a, Vddi b)
{
#define     VDDI_CEQY(A, B) DDU_ASTV(DDI_CEQY(VDDI_ASTM(A),VDDI_ASTM(B)))
    return  VDDI_CEQY(a, b);
}

INLINE(Vddu,VDDF_CEQY)(Vddf a, Vddf b)
{
#define     VDDF_CEQY(A, B) DDU_ASTV(DDF_CEQY(VDDF_ASTM(A),VDDF_ASTM(B)))
    return  VDDF_CEQY(a, b);
}


INLINE(Vqbu,VQBU_CEQY)(Vqbu a, Vqbu b)
{
#define     VQBU_CEQY(A, B) QBU_ASTV(QBU_CEQY(VQBU_ASTM(A),VQBU_ASTM(B)))
    return  VQBU_CEQY(a, b);
}

INLINE(Vqbu,VQBI_CEQY)(Vqbi a, Vqbi b)
{
#define     VQBI_CEQY(A, B) QBU_ASTV(QBI_CEQY(VQBI_ASTM(A),VQBI_ASTM(B)))
    return  VQBI_CEQY(a, b);
}

INLINE(Vqbu,VQBC_CEQY)(Vqbc a, Vqbc b)
{
#define     VQBC_CEQY(A, B) QBU_ASTV(QBC_CEQY(VQBC_ASTM(A),VQBC_ASTM(B)))
    return  VQBC_CEQY(a, b);
}


INLINE(Vqhu,VQHU_CEQY)(Vqhu a, Vqhu b)
{
#define     VQHU_CEQY(A, B) QHU_ASTV(QHU_CEQY(VQHU_ASTM(A),VQHU_ASTM(B)))
    return  VQHU_CEQY(a, b);
}

INLINE(Vqhu,VQHI_CEQY)(Vqhi a, Vqhi b)
{
#define     VQHI_CEQY(A, B) QHU_ASTV(QHI_CEQY(VQHI_ASTM(A),VQHI_ASTM(B)))
    return  VQHI_CEQY(a, b);
}

INLINE(Vqhu,VQHF_CEQY)(Vqhf a, Vqhf b)
{
#define     VQHF_CEQY(A, B) QHU_ASTV(QHF_CEQY(VQHF_ASTM(A),VQHF_ASTM(B)))
    return  VQHF_CEQY(a, b);
}


INLINE(Vqwu,VQWU_CEQY)(Vqwu a, Vqwu b)
{
#define     VQWU_CEQY(A, B) QWU_ASTV(QWU_CEQY(VQWU_ASTM(A),VQWU_ASTM(B)))
    return  VQWU_CEQY(a, b);
}

INLINE(Vqwu,VQWI_CEQY)(Vqwi a, Vqwi b)
{
#define     VQWI_CEQY(A, B) QWU_ASTV(QWI_CEQY(VQWI_ASTM(A),VQWI_ASTM(B)))
    return  VQWI_CEQY(a, b);
}

INLINE(Vqwu,VQWF_CEQY)(Vqwf a, Vqwf b)
{
#define     VQWF_CEQY(A, B) QWU_ASTV(QWF_CEQY(VQWF_ASTM(A),VQWF_ASTM(B)))
    return  VQWF_CEQY(a, b);
}


INLINE(Vqdu,VQDU_CEQY)(Vqdu a, Vqdu b)
{
#define     VQDU_CEQY(A, B) QDU_ASTV(QDU_CEQY(VQDU_ASTM(A),VQDU_ASTM(B)))
    return  VQDU_CEQY(a, b);
}

INLINE(Vqdu,VQDI_CEQY)(Vqdi a, Vqdi b)
{
#define     VQDI_CEQY(A, B) QDU_ASTV(QDI_CEQY(VQDI_ASTM(A),VQDI_ASTM(B)))
    return  VQDI_CEQY(a, b);
}

INLINE(Vqdu,VQDF_CEQY)(Vqdf a, Vqdf b)
{
#define     VQDF_CEQY(A, B) QDU_ASTV(QDF_CEQY(VQDF_ASTM(A),VQDF_ASTM(B)))
    return  VQDF_CEQY(a, b);
}


#if _LEAVE_EXTGOP_ARM_CEQY
}
#endif


#if _ENTER_EXTGOP_ARM_CEQZ_
{
#endif

//efine     DYU_CEQZ(M)  
#define     DBU_CEQZ(M)         vceqz_u8(M)
#define     DBI_CEQZ(M)         vreinterpret_s8_u8(vceqz_s8(M))
#define     DBC_CEQZ            VDBC_BASE(CEQZ)
#define     DHU_CEQZ(M)         vceqz_u16(M)
#define     DHI_CEQZ(M)         vreinterpret_s16_u16(vceqz_s16(M))
#if defined(SPC_ARM_FP16_SIMD)
#   define  DHF_CEQZ(M)         vreinterpret_s16_u16(vceqz_f16(M))
#else
#   define  DHF_CEQZ(M)         \
vreinterpret_s16_u16(vmovn_u32(vceqzq_f32(vcvt_f32_f16(M))))
#endif

#define     DWU_CEQZ(M)         vceqz_u32(M)
#define     DWI_CEQZ(M)         vreinterpret_s32_u32(vceqz_s32(M))
#define     DWF_CEQZ(M)         vreinterpret_s32_u32(vceqz_f32(M))
#define     DDU_CEQZ(M)         vceqz_u64(M)
#define     DDI_CEQZ(M)         vreinterpret_s64_u64(vceqz_s64(M))
#define     DDF_CEQZ(M)         vreinterpret_s64_u64(vceqz_f64(M))


#define     QBU_CEQZ(M)         vceqzq_u8(M)
#define     QBI_CEQZ(M)         vreinterpretq_s8_u8(vceqzq_s8(M))
#define     QBC_CEQZ            VQBC_BASE(CEQZ)
#define     QHU_CEQZ(M)         vceqzq_u16(M)
#define     QHI_CEQZ(M)         vreinterpretq_s16_u16(vceqzq_s16(M))
#if defined(SPC_ARM_FP16_SIMD)
#   define  QHF_CEQZ(M)         vreinterpretq_s16_u16(vceqzq_f16(M))
#else
#   define  QHF_CEQZ(M)         \
vcombine_s16(                   \
    DHF_CEQZ(vget_low_f16( M)), \
    DHF_CEQZ(vget_high_f16(M))  \
)
#endif

#define     QWU_CEQZ(M)         vceqzq_u32(M)
#define     QWI_CEQZ(M)         vreinterpretq_s32_u32(vceqzq_s32(M))
#define     QWF_CEQZ(M)         vreinterpretq_s32_u32(vceqzq_f32(M))
#define     QDU_CEQZ(M)         vceqzq_u64(M)
#define     QDI_CEQZ(M)         vreinterpretq_s64_u64(vceqzq_s64(M))
#define     QDF_CEQZ(M)         vreinterpretq_s64_u64(vceqzq_f64(M))


INLINE(Vdbu,VDBU_CEQZ) (Vdbu v)
{
#define     VDBU_CEQZ   DBU_CEQZ
    return  VDBU_CEQZ(v);
}

INLINE(Vdbi,VDBI_CEQZ) (Vdbi v)
{
#define     VDBI_CEQZ   DBI_CEQZ
    return  VDBI_CEQZ(v);
}

INLINE(Vdbc,VDBC_CEQZ) (Vdbc v)
{
#define     VDBC_CEQZ(V)   DBC_ASTV(DBC_CEQZ(VDBC_ASTM(V)))
    return  VDBC_CEQZ(v);
}


INLINE(Vdhu,VDHU_CEQZ) (Vdhu v)
{
#define     VDHU_CEQZ   DHU_CEQZ
    return  VDHU_CEQZ(v);
}

INLINE(Vdhi,VDHI_CEQZ) (Vdhi v)
{
#define     VDHI_CEQZ   DHI_CEQZ
    return  VDHI_CEQZ(v);
}

INLINE(Vdhi,VDHF_CEQZ) (Vdhf v)
{
#define     VDHF_CEQZ   DHF_CEQZ
    return  VDHF_CEQZ(v);
}


INLINE(Vdwu,VDWU_CEQZ) (Vdwu v)
{
#define     VDWU_CEQZ   DWU_CEQZ
    return  VDWU_CEQZ(v);
}

INLINE(Vdwi,VDWI_CEQZ) (Vdwi v)
{
#define     VDWI_CEQZ   DWI_CEQZ
    return  VDWI_CEQZ(v);
}

INLINE(Vdwi,VDWF_CEQZ) (Vdwf v)
{
#define     VDWF_CEQZ   DWF_CEQZ
    return  VDWF_CEQZ(v);
}


INLINE(Vddu,VDDU_CEQZ) (Vddu v)
{
#define     VDDU_CEQZ   DDU_CEQZ
    return  VDDU_CEQZ(v);
}

INLINE(Vddi,VDDI_CEQZ) (Vddi v)
{
#define     VDDI_CEQZ   DDI_CEQZ
    return  VDDI_CEQZ(v);
}

INLINE(Vddi,VDDF_CEQZ) (Vddf v)
{
#define     VDDF_CEQZ   DDF_CEQZ
    return  VDDF_CEQZ(v);
}


INLINE(Vqbu,VQBU_CEQZ) (Vqbu v)
{
#define     VQBU_CEQZ   QBU_CEQZ
    return  VQBU_CEQZ(v);
}

INLINE(Vqbi,VQBI_CEQZ) (Vqbi v)
{
#define     VQBI_CEQZ   QBI_CEQZ
    return  VQBI_CEQZ(v);
}

INLINE(Vqbc,VQBC_CEQZ) (Vqbc v)
{
#define     VQBC_CEQZ(V)   QBC_ASTV(QBC_CEQZ(VQBC_ASTM(V)))
    return  VQBC_CEQZ(v);
}


INLINE(Vqhu,VQHU_CEQZ) (Vqhu v)
{
#define     VQHU_CEQZ   QHU_CEQZ
    return  VQHU_CEQZ(v);
}

INLINE(Vqhi,VQHI_CEQZ) (Vqhi v)
{
#define     VQHI_CEQZ   QHI_CEQZ
    return  VQHI_CEQZ(v);
}

INLINE(Vqhi,VQHF_CEQZ) (Vqhf v)
{
#define     VQHF_CEQZ   QHF_CEQZ
    return  VQHF_CEQZ(v);
}


INLINE(Vqwu,VQWU_CEQZ) (Vqwu v)
{
#define     VQWU_CEQZ   QWU_CEQZ
    return  VQWU_CEQZ(v);
}

INLINE(Vqwi,VQWI_CEQZ) (Vqwi v)
{
#define     VQWI_CEQZ   QWI_CEQZ
    return  VQWI_CEQZ(v);
}

INLINE(Vqwi,VQWF_CEQZ) (Vqwf v)
{
#define     VQWF_CEQZ   QWF_CEQZ
    return  VQWF_CEQZ(v);
}


INLINE(Vqdu,VQDU_CEQZ) (Vqdu v)
{
#define     VQDU_CEQZ   QDU_CEQZ
    return  VQDU_CEQZ(v);
}

INLINE(Vqdi,VQDI_CEQZ) (Vqdi v)
{
#define     VQDI_CEQZ   QDI_CEQZ
    return  VQDI_CEQZ(v);
}

INLINE(Vqdi,VQDF_CEQZ) (Vqdf v)
{
#define     VQDF_CEQZ   QDF_CEQZ
    return  VQDF_CEQZ(v);
}

#if _LEAVE_EXTGOP_ARM_CEQZ_
}
#endif

#if _LEAVE_EXTGOP_ARM_CEQ_
}
#endif

#if _LEAVE_EXTGOP_ARM_CE__
}
#endif


#if _ENTER_EXTGOP_ARM_NEQ_
{
#endif

#if _ENTER_EXTGOP_ARM_NEQS
{
#endif

#define MY_NEQD(R, S, A, B)  \
vreinterpret_##R##_u8(             \
    vmvn_u8(                       \
        vceq_u8(                   \
            vreinterpret_u8_##S(A),\
            vreinterpret_u8_##S(B) \
        )                           \
    )                               \
)

#define     DBU_NEQS(A, B)      vmvn_u8(vceq_u8(A,B))
#define     DBI_NEQS(A, B)      MY_NEQD(s8,s8,A,B)
#if CHAR_MIN
#   define  DBC_NEQS(A, B)      MY_NEQD(s8,u8,A,B)
#else
#   define  DBC_NEQS(A, B)      vmvn_u8(vceq_u8(A,B))
#endif

#define     DHU_NEQS(A, B)      vmvn_u16(vceq_u16(A,B))
#define     DHI_NEQS(A, B)      MY_NEQD(s16,s16,A,B)
#define     DHF_NEQS(A, B)      MY_NEQD(s16,f16,A,B)

#define     DWU_NEQS(A, B)      vmvn_u32(vceq_u32(A,B))
#define     DWI_NEQS(A, B)      MY_NEQD(s32,s32,A,B)
#define     DWF_NEQS(A, B)      MY_NEQD(s32,f32,A,B)
#define     DDU_NEQS(A, B)      MY_NEQD(u64,u64,A,B)
#define     DDI_NEQS(A, B)      MY_NEQD(s64,s64,A,B)
#define     DDF_NEQS(A, B)      MY_NEQD(s64,f64,A,B)


#define MY_NEQQ(R, S, A, B)         \
vreinterpretq_##R##_u8(             \
    vmvnq_u8(                       \
        vceqq_u8(                   \
            vreinterpretq_u8_##S(A),\
            vreinterpretq_u8_##S(B) \
        )                           \
    )                               \
)
#define     QBU_NEQS(A, B)      vmvnq_u8(vceqq_u8(A,B))
#define     QBI_NEQS(A, B)      MY_NEQQ(s8,s8,A,B)
#if CHAR_MIN
#   define  QBC_NEQS(A, B)      MY_NEQQ(s8,s8,A,B)
#else
#   define  QBC_NEQS(A, B)      vmvnq_u8(vceqq_u8(A,B))
#endif

#define     QHU_NEQS(A, B)      vmvnq_u16(vceqq_u8(A,B))
#define     QHI_NEQS(A, B)      MY_NEQQ(s16,s16,A,B)
#define     QHF_NEQS(A, B)      MY_NEQQ(s16,f16,A,B)

#define     QWU_NEQS(A, B)      vmvnq_u32(vceqq_u8(A,B))
#define     QWI_NEQS(A, B)      MY_NEQQ(s32,s32,A,B)
#define     QWF_NEQS(A, B)      MY_NEQQ(s32,f32,A,B)
#define     QDU_NEQS(A, B)      MY_NEQQ(u64,u64,A,A)
#define     QDI_NEQS(A, B)      MY_NEQQ(s64,s64,A,B)
#define     QDF_NEQS(A, B)      MY_NEQQ(s64,f64,A,B)


INLINE(Vwbu,VWBU_NEQS) (Vwbu a, Vwbu b)
{
    float32x2_t l = vset_lane_f32(VWBU_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWBU_ASTM(a), r, V2_K0);
    uint8x8_t   p = vreinterpret_u8_f32(l);
    uint8x8_t   q = vreinterpret_u8_f32(r);
    return WBU_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u8(DBU_NEQS(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwbi,VWBI_NEQS) (Vwbi a, Vwbi b)
{
    float32x2_t l = vset_lane_f32(VWBI_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWBI_ASTM(a), r, V2_K0);
    uint8x8_t   p = vreinterpret_u8_f32(l);
    uint8x8_t   q = vreinterpret_u8_f32(r);
    return  WBI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u8(DBU_NEQS(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwbc,VWBC_NEQS) (Vwbc a, Vwbc b)
{
    float32x2_t l = vset_lane_f32(VWBC_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWBC_ASTM(a), r, V2_K0);
    uint8x8_t   p = vreinterpret_u8_f32(l);
    uint8x8_t   q = vreinterpret_u8_f32(r);
    return  WBC_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u8(DBU_NEQS(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwhu,VWHU_NEQS) (Vwhu a, Vwhu b)
{
    float32x2_t l = vset_lane_f32(VWHU_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWHU_ASTM(a), r, V2_K0);
    uint16x4_t  p = vreinterpret_u16_f32(l);
    uint16x4_t  q = vreinterpret_u16_f32(r);
    return  WHU_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u16(DHU_NEQS(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwhi,VWHI_NEQS) (Vwhi a, Vwhi b)
{
    float32x2_t l = vset_lane_f32(VWHI_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWHI_ASTM(a), r, V2_K0);
    uint16x4_t  p = vreinterpret_u16_f32(l);
    uint16x4_t  q = vreinterpret_u16_f32(r);
    return  WHI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u16(DHU_NEQS(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwhf,VWHF_NEQS) (Vwhf a, Vwhf b)
{
    float32x2_t l = vset_lane_f32(VWHF_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWHF_ASTM(a), r, V2_K0);
    uint16x4_t  p = vreinterpret_u16_f32(l);
    uint16x4_t  q = vreinterpret_u16_f32(r);
    return  WHF_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u16(DHU_NEQS(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwwu,VWWU_NEQS) (Vwwu a, Vwwu b)
{
    float32x2_t l = vset_lane_f32(VWWU_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWWU_ASTM(a), r, V2_K0);
    uint32x2_t  p = vreinterpret_u32_f32(l);
    uint32x2_t  q = vreinterpret_u32_f32(r);
    return  WWU_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u32(DWU_NEQS(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwwi,VWWI_NEQS) (Vwwi a, Vwwi b)
{
    float32x2_t l = vset_lane_f32(VWWI_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWWI_ASTM(a), r, V2_K0);
    uint32x2_t  p = vreinterpret_u32_f32(l);
    uint32x2_t  q = vreinterpret_u32_f32(r);
    return  WWI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u32(DWU_NEQS(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwwf,VWWF_NEQS) (Vwwf a, Vwwf b)
{
    float32x2_t l = vset_lane_f32(VWWF_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWWF_ASTM(a), r, V2_K0);
    uint32x2_t  p = vreinterpret_u32_f32(l);
    uint32x2_t  q = vreinterpret_u32_f32(r);
    return  WWF_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u32(DWU_NEQS(p, q)),
            V2_K0
        )
    );
}


INLINE(Vdbu,VDBU_NEQS)(Vdbu a, Vdbu b)
{
#define     VDBU_NEQS       DBU_NEQS
    return  VDBU_NEQS(a, b);
}

INLINE(Vdbi,VDBI_NEQS)(Vdbi a, Vdbi b)
{
#define     VDBI_NEQS       DBI_NEQS
    return  VDBI_NEQS(a, b);
}

INLINE(Vdbc,VDBC_NEQS)(Vdbc a, Vdbc b)
{
#define     VDBC_NEQS(A, B) DBC_ASTV(DBC_NEQS(VDBC_ASTM(A),VDBC_ASTM(B)))
    return  VDBC_NEQS(a, b);
}

INLINE(Vdhu,VDHU_NEQS)(Vdhu a, Vdhu b)
{
#define     VDHU_NEQS       DHU_NEQS
    return  VDHU_NEQS(a, b);
}

INLINE(Vdhi,VDHI_NEQS)(Vdhi a, Vdhi b)
{
#define     VDHI_NEQS       DHI_NEQS
    return  VDHI_NEQS(a, b);
}

INLINE(Vdhi,VDHF_NEQS)(Vdhf a, Vdhf b)
{
#define     VDHF_NEQS       DHF_NEQS
    return  VDHF_NEQS(a, b);
}


INLINE(Vdwu,VDWU_NEQS)(Vdwu a, Vdwu b)
{
#define     VDWU_NEQS       DWU_NEQS
    return  VDWU_NEQS(a, b);
}

INLINE(Vdwi,VDWI_NEQS)(Vdwi a, Vdwi b)
{
#define     VDWI_NEQS       DWI_NEQS
    return  VDWI_NEQS(a, b);
}

INLINE(Vdwi,VDWF_NEQS)(Vdwf a, Vdwf b)
{
#define     VDWF_NEQS       DWF_NEQS
    return  VDWF_NEQS(a, b);
}


INLINE(Vddu,VDDU_NEQS)(Vddu a, Vddu b)
{
#define     VDDU_NEQS       DDU_NEQS
    return  VDDU_NEQS(a, b);
}

INLINE(Vddi,VDDI_NEQS)(Vddi a, Vddi b)
{
#define     VDDI_NEQS       DDI_NEQS
    return  VDDI_NEQS(a, b);
}

INLINE(Vddi,VDDF_NEQS)(Vddf a, Vddf b)
{
#define     VDDF_NEQS       DDF_NEQS
    return  VDDF_NEQS(a, b);
}


INLINE(Vqbu,VQBU_NEQS)(Vqbu a, Vqbu b)
{
#define     VQBU_NEQS       QBU_NEQS
    return  VQBU_NEQS(a, b);
}

INLINE(Vqbi,VQBI_NEQS)(Vqbi a, Vqbi b)
{
#define     VQBI_NEQS       QBI_NEQS
    return  VQBI_NEQS(a, b);
}

INLINE(Vqbc,VQBC_NEQS)(Vqbc a, Vqbc b)
{
#define     VQBC_NEQS(A, B) QBC_ASTV(QBC_NEQS(VQBC_ASTM(A),VQBC_ASTM(B)))
    return  VQBC_NEQS(a, b);
}


INLINE(Vqhu,VQHU_NEQS)(Vqhu a, Vqhu b)
{
#define     VQHU_NEQS       QHU_NEQS
    return  VQHU_NEQS(a, b);
}

INLINE(Vqhi,VQHI_NEQS)(Vqhi a, Vqhi b)
{
#define     VQHI_NEQS       QHI_NEQS
    return  VQHI_NEQS(a, b);
}

INLINE(Vqhi,VQHF_NEQS)(Vqhf a, Vqhf b)
{
#define     VQHF_NEQS       QHF_NEQS
    return  VQHF_NEQS(a, b);
}


INLINE(Vqwu,VQWU_NEQS)(Vqwu a, Vqwu b)
{
#define     VQWU_NEQS       QWU_NEQS
    return  VQWU_NEQS(a, b);
}

INLINE(Vqwi,VQWI_NEQS)(Vqwi a, Vqwi b)
{
#define     VQWI_NEQS       QWI_NEQS
    return  VQWI_NEQS(a, b);
}

INLINE(Vqwi,VQWF_NEQS)(Vqwf a, Vqwf b)
{
#define     VQWF_NEQS       QWF_NEQS
    return  VQWF_NEQS(a, b);
}


INLINE(Vqdu,VQDU_NEQS)(Vqdu a, Vqdu b)
{
#define     VQDU_NEQS       QDU_NEQS
    return  VQDU_NEQS(a, b);
}

INLINE(Vqdi,VQDI_NEQS)(Vqdi a, Vqdi b)
{
#define     VQDI_NEQS       QDI_NEQS
    return  VQDI_NEQS(a, b);
}

INLINE(Vqdi,VQDF_NEQS)(Vqdf a, Vqdf b)
{
#define     VQDF_NEQS       QDF_NEQS
    return  VQDF_NEQS(a, b);
}


#if _LEAVE_EXTGOP_ARM_NEQS
}
#endif

// neqy

#if _ENTER_EXTGOP_ARM_NEQZ_
{
#endif

INLINE( Wbu,WBU_NEQZ)(Wbu m)
{
#define     WBU_NEQZ    WBU_NEQZ
    float32x2_t f = vset_lane_f32(m, f, V2_K0);
    uint8x8_t   v = vtst_u8(
        vreinterpret_u8_f32(f), 
        vdup_n_u8(0xff)
    );
    return  vget_lane_f32(vreinterpret_f32_u8(v), V2_K0);
}

INLINE( Wbi,WBI_NEQZ)(Wbu m)
{
#define     WBI_NEQZ    WBI_NEQZ
    float32x2_t f = vset_lane_f32(m, f, V2_K0);
    int8x8_t    v = vtst_s8(
        vreinterpret_s8_f32(f),
        vdup_n_s8(-1)
    );
    return  vget_lane_f32(vreinterpret_f32_s8(v), V2_K0);
}

#if CHAR_MIN
#   define  WBC_NEQZ    WBI_NEQZ
#else
#   define  WBC_NEQZ    WBU_NEQZ
#endif


INLINE( Whu,WHU_NEQZ)(Whu m)
{
#define     WHU_NEQZ    WHU_NEQZ
    float32x2_t f = vset_lane_f32(m, f, V2_K0);
    uint16x4_t  v = vtst_u16(
        vreinterpret_u16_f32(f), 
        vdup_n_u16(0xffff)
    );
    return  vget_lane_f32(vreinterpret_f32_u16(v), V2_K0);
}

INLINE( Whi,WHI_NEQZ)(Whi m)
{
#define     WHI_NEQZ    WHI_NEQZ
    float32x2_t f = vset_lane_f32(m, f, V2_K0);
    int16x4_t   v = vtst_s16(
        vreinterpret_s16_f32(f),
        vdup_n_s16(-1)
    );
    return  vget_lane_f32(vreinterpret_f32_s16(v), V2_K0);
}

INLINE( Whi,WHF_NEQZ)(Whf m)
{
#   define  WHF_NEQZ    WHF_NEQZ
    float32x2_t f = vset_lane_f32(m, f, V2_K0);

#if defined(SPC_ARM_FP16_SIMD)
    float16x4_t t = vreinterpret_f16_f32(f);
    f = vreinterpret_f32_u16(vmvn_u16(vceqz_f16(t)));
#else
    uint16x4_t t = vmovn_u32(vceqzq_f32(vcvt_f32_f16(f)));
    f = vreinterpret_f32_u16(vmvn_u16(t));
#endif
    return  vget_lane_f32(f, V2_K0);
}


INLINE( Wwu,WWU_NEQZ)(Wwu m)
{
#define     WWU_NEQZ    WWU_NEQZ
    float32x2_t f = vset_lane_f32(m, f, V2_K0);
    uint32x2_t  v = vtst_u32(
        vreinterpret_u32_f32(f),
        vdup_n_u32(0xffffffffu)
    );
    return  vget_lane_f32(vreinterpret_f32_u32(v), V2_K0);
}

INLINE( Wwi,WWI_NEQZ)(Wwi m)
{
#define     WWI_NEQZ    WWI_NEQZ
    float32x2_t f = vset_lane_f32(m, f, V2_K0);
    int32x2_t   v = vtst_s32(
        vreinterpret_s32_f32(f),
        vdup_n_s32(-1)
    );
    return  vget_lane_f32(vreinterpret_f32_s32(v), V2_K0);
}

INLINE( Wwi,WWF_NEQZ)(Wwf m)
{
#define     WWF_NEQZ    WWF_NEQZ
    float32x2_t f = vceqz_f32(vset_lane_f32(m, f, V2_K0));
    int32x2_t   v = vmvn_s32(vreinterpret_s32_f32(f));
    return  vget_lane_f32(vreinterpret_f32_s32(v), V2_K0);
}


//efine     DYU_NEQZ(M)  
#define     DBU_NEQZ(M) vtst_u8(M,vdup_n_u8(0xff))
#define     DBI_NEQZ(M) vtst_s8(M,vdup_n_s8(-1))
#if CHAR_MIN
#   define  DBC_NEQZ(M) DBI_NEQZ(M)
#else
#   define  DBC_NEQZ(M) DBU_NEQZ(M)
#endif

#define     DHU_NEQZ(M) vtst_u16(M,vdup_n_u16(0xffff))
#define     DHI_NEQZ(M) vtst_s16(M,vdup_n_s16(-1))
#if defined(SPC_ARM_FP16_SIMD)
#   define  DHF_NEQZ(M)         \
vreinterpret_s16_u16(vmvn_u16(vceqz_f16(M)))

#else
#   define  DHF_NEQZ(M)         \
vmvn_s16(vreinterpret_s16_u16(vmovn_u32(vceqzq_f32(vcvt_f32_f16(M)))))

#endif

#define     DWU_NEQZ(M) vtst_u32(M,vdup_n_u32(0xffffffffu))
#define     DWI_NEQZ(M) vtst_s32(M,vdup_n_s32(-1))
#define     DWF_NEQZ(M) \
vmvn_s32(vreinterpret_s32_u32(vceqz_f32(M)))

#define     DDU_NEQZ(M) vtst_u64(M,vdup_n_u64(0xffffffffffffffffull))
#define     DDI_NEQZ(M) vtst_s64(M,vdup_n_s64(-1ll))
#define     DDF_NEQZ(M) \
vreinterpret_s64_u8(vmvn_u8(vreinterpret_u8_u64(vceqz_f64(M))))

//efine     QYU_NEQZ(M)  
#define     QBU_NEQZ(M) vtstq_u8(M,vdupq_n_u8(0xff))
#define     QBI_NEQZ(M) vtstq_s8(M,vdupq_n_s8(-1))
#define     QBC_NEQZ    VQBC_BASE(NEQZ)
#define     QHU_NEQZ(M) vtstq_u16(M,vdupq_n_u16(0xffff))
#define     QHI_NEQZ(M) vtstq_s16(M,vdupq_n_s16(-1))
#if defined(SPC_ARM_FP16_SIMD)
#   define  QHF_NEQZ(M) vreinterpretq_s16_u16(vtstq_f16(M))
#else
#   define  QHF_NEQZ(M)         \
vcombine_s16(                   \
    DHF_NEQZ(vget_low_f16( M)), \
    DHF_NEQZ(vget_high_f16(M))  \
)
#endif

#define     QWU_NEQZ(M) vtstq_u32(M,vdupq_n_u32(0xffffffffu))
#define     QWI_NEQZ(M) vtstq_s32(M,vdupq_n_s32(         -1))
#define     QWF_NEQZ(M) \
vmvnq_s32(vreinterpretq_s32_u32(vceqzq_f32(M)))

#define     QDU_NEQZ(M) vtstq_u64(M,vdupq_n_u64(0xffffffffffffffffull)) 
#define     QDI_NEQZ(M) vtstq_s64(M,vdupq_n_s64(                 -1ll))
#define     QDF_NEQZ(M)         \
vreinterpretq_s64_u8(vmvnq_u8(vreinterpretq_u8_u64(vceqzq_f64(M))))


INLINE(Vwbu,VWBU_NEQZ)(Vwbu v)
{
#define     VWBU_NEQZ(V)    WBU_ASTV(WBU_NEQZ(VWBU_ASTM(V)))
    return  VWBU_NEQZ(v);
}

INLINE(Vwbi,VWBI_NEQZ)(Vwbi v)
{
#define     VWBI_NEQZ(V)    WBI_ASTV(WBI_NEQZ(VWBI_ASTM(V)))
    return  VWBI_NEQZ(v);
}

INLINE(Vwbc,VWBC_NEQZ)(Vwbc v)
{
#define     VWBC_NEQZ(V)    WBC_ASTV(WBC_NEQZ(VWBC_ASTM(V)))
    return  VWBC_NEQZ(v);
}


INLINE(Vwhu,VWHU_NEQZ)(Vwhu v)
{
#define     VWHU_NEQZ(V)    WHU_ASTV(WHU_NEQZ(VWHU_ASTM(V)))
    return  VWHU_NEQZ(v);
}

INLINE(Vwhi,VWHI_NEQZ)(Vwhi v)
{
#define     VWHI_NEQZ(V)    WHI_ASTV(WHI_NEQZ(VWHI_ASTM(V)))
    return  VWHI_NEQZ(v);
}

INLINE(Vwhi,VWHF_NEQZ)(Vwhf v)
{
#define     VWHF_NEQZ(V)    WHI_ASTV(WHF_NEQZ(VWHF_ASTM(V)))
    return  VWHF_NEQZ(v);
}


INLINE(Vwwu,VWWU_NEQZ)(Vwwu v)
{
#define     VWWU_NEQZ(V)    WWU_ASTV(WWU_NEQZ(VWWU_ASTM(V)))
    return  VWWU_NEQZ(v);
}

INLINE(Vwwi,VWWI_NEQZ)(Vwwi v)
{
#define     VWWI_NEQZ(V)    WWI_ASTV(WWI_NEQZ(VWWI_ASTM(V)))
    return  VWWI_NEQZ(v);
}

INLINE(Vwwi,VWWF_NEQZ)(Vwwf v)
{
#define     VWWF_NEQZ(V)    WWI_ASTV(WWF_NEQZ(VWWF_ASTM(V)))
    return  VWWF_NEQZ(v);
}


INLINE(Vdbu,VDBU_NEQZ) (Vdbu v)
{
#define     VDBU_NEQZ   DBU_NEQZ
    return  VDBU_NEQZ(v);
}

INLINE(Vdbi,VDBI_NEQZ) (Vdbi v)
{
#define     VDBI_NEQZ   DBI_NEQZ
    return  VDBI_NEQZ(v);
}

INLINE(Vdbc,VDBC_NEQZ) (Vdbc v)
{
#define     VDBC_NEQZ(V)   DBC_ASTV(DBC_NEQZ(VDBC_ASTM(V)))
    return  VDBC_NEQZ(v);
}


INLINE(Vdhu,VDHU_NEQZ) (Vdhu v)
{
#define     VDHU_NEQZ   DHU_NEQZ
    return  VDHU_NEQZ(v);
}

INLINE(Vdhi,VDHI_NEQZ) (Vdhi v)
{
#define     VDHI_NEQZ   DHI_NEQZ
    return  VDHI_NEQZ(v);
}

INLINE(Vdhi,VDHF_NEQZ) (Vdhf v)
{
#define     VDHF_NEQZ   DHF_NEQZ
    return  VDHF_NEQZ(v);
}


INLINE(Vdwu,VDWU_NEQZ) (Vdwu v)
{
#define     VDWU_NEQZ   DWU_NEQZ
    return  VDWU_NEQZ(v);
}

INLINE(Vdwi,VDWI_NEQZ) (Vdwi v)
{
#define     VDWI_NEQZ   DWI_NEQZ
    return  VDWI_NEQZ(v);
}

INLINE(Vdwi,VDWF_NEQZ) (Vdwf v)
{
#define     VDWF_NEQZ   DWF_NEQZ
    return  VDWF_NEQZ(v);
}


INLINE(Vddu,VDDU_NEQZ) (Vddu v)
{
#define     VDDU_NEQZ   DDU_NEQZ
    return  VDDU_NEQZ(v);
}

INLINE(Vddi,VDDI_NEQZ) (Vddi v)
{
#define     VDDI_NEQZ   DDI_NEQZ
    return  VDDI_NEQZ(v);
}

INLINE(Vddi,VDDF_NEQZ) (Vddf v)
{
#define     VDDF_NEQZ   DDF_NEQZ
    return  VDDF_NEQZ(v);
}


INLINE(Vqbu,VQBU_NEQZ) (Vqbu v)
{
#define     VQBU_NEQZ   QBU_NEQZ
    return  VQBU_NEQZ(v);
}

INLINE(Vqbi,VQBI_NEQZ) (Vqbi v)
{
#define     VQBI_NEQZ   QBI_NEQZ
    return  VQBI_NEQZ(v);
}

INLINE(Vqbc,VQBC_NEQZ) (Vqbc v)
{
#define     VQBC_NEQZ(V)   QBC_ASTV(QBC_NEQZ(VQBC_ASTM(V)))
    return  VQBC_NEQZ(v);
}


INLINE(Vqhu,VQHU_NEQZ) (Vqhu v)
{
#define     VQHU_NEQZ   QHU_NEQZ
    return  VQHU_NEQZ(v);
}

INLINE(Vqhi,VQHI_NEQZ) (Vqhi v)
{
#define     VQHI_NEQZ   QHI_NEQZ
    return  VQHI_NEQZ(v);
}

INLINE(Vqhi,VQHF_NEQZ) (Vqhf v)
{
#define     VQHF_NEQZ   QHF_NEQZ
    return  VQHF_NEQZ(v);
}


INLINE(Vqwu,VQWU_NEQZ) (Vqwu v)
{
#define     VQWU_NEQZ   QWU_NEQZ
    return  VQWU_NEQZ(v);
}

INLINE(Vqwi,VQWI_NEQZ) (Vqwi v)
{
#define     VQWI_NEQZ   QWI_NEQZ
    return  VQWI_NEQZ(v);
}

INLINE(Vqwi,VQWF_NEQZ) (Vqwf v)
{
#define     VQWF_NEQZ   QWF_NEQZ
    return  VQWF_NEQZ(v);
}


INLINE(Vqdu,VQDU_NEQZ) (Vqdu v)
{
#define     VQDU_NEQZ   QDU_NEQZ
    return  VQDU_NEQZ(v);
}

INLINE(Vqdi,VQDI_NEQZ) (Vqdi v)
{
#define     VQDI_NEQZ   QDI_NEQZ
    return  VQDI_NEQZ(v);
}

INLINE(Vqdi,VQDF_NEQZ) (Vqdf v)
{
#define     VQDF_NEQZ   QDF_NEQZ
    return  VQDF_NEQZ(v);
}

#if _LEAVE_EXTGOP_ARM_NEQZ_
}
#endif

#if _LEAVE_EXTGOP_ARM_NEQ_
}
#endif

#if _ENTER_EXTGOP_ARM_NL__
{
#endif

#if _ENTER_EXTGOP_ARM_NLT_
{
#endif

// nlts
// nlty
// nltz

#if _LEAVE_EXTGOP_ARM_NLT_
}
#endif

#if _ENTER_EXTGOP_ARM_NLE_
{
#endif

// nles
// nley
// nlez

#if _LEAVE_EXTGOP_ARM_NLE_
}
#endif

#if _LEAVE_EXTGOP_ARM_NL_
}
#endif

#if _ENTER_EXTGOP_ARM_NG__
{
#endif

#if _ENTER_EXTGOP_ARM_NGT_
{
#endif

// nges
// ngey
// ngez

#if _LEAVE_EXTGOP_ARM_NGT_
}
#endif

#if _ENTER_EXTGOP_ARM_NGE_
{
#endif

//  nges
//  ngey
//  ngez

#if _LEAVE_EXTGOP_ARM_NGE_
}
#endif

#if _LEAVE_EXTGOP_ARM_NG_
}
#endif

#if _ENTER_EXTGOP_ARM_CL__
{
#endif

#if _ENTER_EXTGOP_ARM_CLT_
{
#endif

#if _ENTER_EXTGOP_ARM_CLTS
{
#endif

#define     DBU_CLTS                             vclt_u8
#define     DBI_CLTS(A, B)  vreinterpret_s16_u16(vclt_s8(A,B))
#define     DBC_CLTS        VDBC_BASE(CLTS)
#define     DHU_CLTS                             vclt_u16
#define     DHI_CLTS(A, B)  vreinterpret_s16_u16(vclt_s16(A,B))
#if defined(SPC_ARM_FP16_SIMD)
#   define  DHF_CLTS(A, B)  vreinterpret_s16_u16(vclt_f16(A,B))
#else
INLINE(float16x4_t,DHF_CLTS)(float16x4_t a, float16x4_t b)
{
#   define  DHF_CLTS    DHF_CLTS
    MY_NOT_IMPLEMENTED(0, __func__);
    return  DHF_VOID;
}
#endif
#define     DWU_CLTS                             vclt_u32
#define     DWI_CLTS(A, B)  vreinterpret_s32_u32(vclt_s32(A,B))
#define     DWF_CLTS(A, B)  vreinterpret_s32_u32(vclt_f32(A,B))
#define     DDU_CLTS                             vclt_u64
#define     DDI_CLTS(A, B)  vreinterpret_s64_u64(vclt_s32(A,B))
#define     DDF_CLTS(A, B)  vreinterpret_s64_u64(vclt_f32(A,B))


#define     QBU_CLTS                              vcltq_u8
#define     QBI_CLTS(A, B)  vreinterpretq_s16_u16(vcltq_s8(A,B))
#define     QBC_CLTS        VQBC_BASE(CLTS)
#define     QHU_CLTS                              vcltq_u16
#define     QHI_CLTS(A, B)  vreinterpretq_s16_u16(vcltq_s16(A,B))
#if defined(SPC_ARM_FP16_SIMD)
#   define  QHF_CLTS(A, B)  vreinterpretq_s16_u16(vcltq_f16(A,B))
#else
INLINE(float16x8_t,QHF_CLTS)(float16x8_t a, float16x8_t b)
{
#   define  QHF_CLTS    QHF_CLTS
    MY_NOT_IMPLEMENTED(0, __func__);
    return  QHF_VOID;
}
#endif

#define     QWU_CLTS                              vcltq_u32
#define     QWI_CLTS(A, B)  vreinterpretq_s32_u32(vcltq_s32(A,B))
#define     QWF_CLTS(A, B)  vreinterpretq_s32_u32(vcltq_f32(A,B))
#define     QDU_CLTS                              vcltq_u64
#define     QDI_CLTS(A, B)  vreinterpretq_s64_u64(vcltq_s32(A,B))
#define     QDF_CLTS(A, B)  vreinterpretq_s64_u64(vcltq_f32(A,B))


INLINE(Vwbu,VWBU_CLTS) (Vwbu a, Vwbu b)
{
    float32x2_t l = vset_lane_f32(VWBU_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWBU_ASTM(a), r, V2_K0);
    uint8x8_t   p = vreinterpret_u8_f32(l);
    uint8x8_t   q = vreinterpret_u8_f32(r);
    return WBU_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u8(DBU_CLTS(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwbi,VWBI_CLTS) (Vwbi a, Vwbi b)
{
    float32x2_t l = vset_lane_f32(VWBI_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWBI_ASTM(a), r, V2_K0);
    int8x8_t    p = vreinterpret_s8_f32(l);
    int8x8_t    q = vreinterpret_s8_f32(r);
    return  WBI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u8(vclt_s8(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwbc,VWBC_CLTS) (Vwbc a, Vwbc b)
{
    float32x2_t x = vset_lane_f32(VWBC_ASTM(a), x, V2_K0);
    float32x2_t y = vset_lane_f32(VWBC_ASTM(a), y, V2_K0);
    float32x2_t r;
#if CHAR_MIN
    int8x8_t    p = vreinterpret_s8_f32(x);
    int8x8_t    q = vreinterpret_s8_f32(y);
    r = vreinterpret_f32_u8(vclt_s8(p, q));
#else
    uint8x8_t   p = vreinterpret_u8_f32(x);
    uint8x8_t   q = vreinterpret_u8_f32(y);
    r = vreinterpret_f32_u8(vclt_u8(p, q));
#endif
    return  WBC_ASTV(vget_lane_f32(r, V2_K0));
}


INLINE(Vwhu,VWHU_CLTS) (Vwhu a, Vwhu b)
{
    float32x2_t l = vset_lane_f32(VWHU_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWHU_ASTM(a), r, V2_K0);
    uint16x4_t  p = vreinterpret_u16_f32(l);
    uint16x4_t  q = vreinterpret_u16_f32(r);
    return  WHU_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u16(vclt_u16(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwhi,VWHI_CLTS) (Vwhi a, Vwhi b)
{
    float32x2_t l = vset_lane_f32(VWHI_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWHI_ASTM(a), r, V2_K0);
    int16x4_t   p = vreinterpret_s16_f32(l);
    int16x4_t   q = vreinterpret_s16_f32(r);
    return  WHI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u16(vclt_s16(p, q)),
            V2_K0
        )
    );
}

#if defined(SPC_ARM_FP16_SIMD)
INLINE(Vwhi,VWHF_CLTS) (Vwhf a, Vwhf b)
{
#   define  VWHF_CLTS VWHF_CLTS
    float32x2_t l = vset_lane_f32(VWHF_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWHF_ASTM(a), r, V2_K0);
    float16x4_t p = vreinterpret_f16_f32(l);
    float16x4_t q = vreinterpret_f16_f32(r);
    return  WHI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u16(vclt_f16(p, q)),
            V2_K0
        )
    );
}
#else
INLINE(Vwhf,VWHF_CLTS)(Vwhf a, Vwhf b)
{
#   define  VWHF_CLTS    VWHF_CLTS
    MY_NOT_IMPLEMENTED(0, __func__);
    return  VWHF_VOID;
}
#endif


INLINE(Vwwu,VWWU_CLTS) (Vwwu a, Vwwu b)
{
    float32x2_t l = vset_lane_f32(VWWU_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWWU_ASTM(a), r, V2_K0);
    uint32x2_t  p = vreinterpret_u32_f32(l);
    uint32x2_t  q = vreinterpret_u32_f32(r);
    return  WWU_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u16(vclt_u32(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwwi,VWWI_CLTS) (Vwwi a, Vwwi b)
{
    float32x2_t l = vset_lane_f32(VWWI_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWWI_ASTM(a), r, V2_K0);
    int32x2_t   p = vreinterpret_s32_f32(l);
    int32x2_t   q = vreinterpret_s32_f32(r);
    return WWI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u32(vclt_s32(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwwi,VWWF_CLTS) (Vwwf a, Vwwf b)
{
    float32x2_t p = vset_lane_f32(VWWF_ASTM(a), p, V2_K0);
    float32x2_t q = vset_lane_f32(VWWF_ASTM(a), q, V2_K0);
    return WWI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u32(vclt_f32(p, q)),
            V2_K0
        )
    );
}


INLINE(Vdbu,VDBU_CLTS) (Vdbu a, Vdbu b)
{
#define     VDBU_CLTS   DBU_CLTS
    return   DBU_CLTS(a, b);
}

INLINE(Vdbi,VDBI_CLTS) (Vdbi a, Vdbi b)
{
#define     VDBI_CLTS   DBI_CLTS
    return   DBI_CLTS(a, b);
}

INLINE(Vdbc,VDBC_CLTS) (Vdbc a, Vdbc b)
{
#define     VDBC_CLTS   VDBC_CLTS
    VDBC_MTYPE l = VDBC_ASTM(a);
    VDBC_MTYPE r = VDBC_ASTM(b);
    return  DBC_ASTV(DBC_CLTS(l, r));
}


INLINE(Vdhu,VDHU_CLTS) (Vdhu a, Vdhu b)
{
#define     VDHU_CLTS   DHU_CLTS
    return   DHU_CLTS(a, b);
}

INLINE(Vdhi,VDHI_CLTS) (Vdhi a, Vdhi b)
{
#define     VDHI_CLTS   DHI_CLTS
    return   DHI_CLTS(a, b);
}

INLINE(Vdhi,VDHF_CLTS) (Vdhf a, Vdhf b)
{
#define     VDHF_CLTS   DHF_CLTS
    return   DHF_CLTS(a, b);
}


INLINE(Vdwu,VDWU_CLTS) (Vdwu a, Vdwu b)
{
#define     VDWU_CLTS   DWU_CLTS
    return   DWU_CLTS(a, b);
}

INLINE(Vdwi,VDWI_CLTS) (Vdwi a, Vdwi b)
{
#define     VDWI_CLTS   DWI_CLTS
    return   DWI_CLTS(a, b);
}

INLINE(Vdwi,VDWF_CLTS) (Vdwf a, Vdwf b)
{
#define     VDWF_CLTS   DWF_CLTS
    return   DWF_CLTS(a, b);
}


INLINE(Vddu,VDDU_CLTS) (Vddu a, Vddu b)
{
#define     VDDU_CLTS   DDU_CLTS
    return   DDU_CLTS(a, b);
}

INLINE(Vddi,VDDI_CLTS) (Vddi a, Vddi b)
{
#define     VDDI_CLTS   DDI_CLTS
    return   DDI_CLTS(a, b);
}

INLINE(Vddi,VDDF_CLTS) (Vddf a, Vddf b)
{
#define     VDDF_CLTS   DDF_CLTS
    return   DDF_CLTS(a, b);
}


INLINE(Vqbu,VQBU_CLTS) (Vqbu a, Vqbu b)
{
#define     VQBU_CLTS   QBU_CLTS
    return   QBU_CLTS(a, b);
}

INLINE(Vqbi,VQBI_CLTS) (Vqbi a, Vqbi b)
{
#define     VQBI_CLTS   QBI_CLTS
    return   QBI_CLTS(a, b);
}

INLINE(Vqbc,VQBC_CLTS) (Vqbc a, Vqbc b)
{
#define     VQBC_CLTS   VQBC_CLTS
    VQBC_MTYPE l = VQBC_ASTM(a);
    VQBC_MTYPE r = VQBC_ASTM(b);
    return  QBC_ASTV(QBC_CLTS(l, r));
}


INLINE(Vqhu,VQHU_CLTS) (Vqhu a, Vqhu b)
{
#define     VQHU_CLTS   QHU_CLTS
    return   QHU_CLTS(a, b);
}

INLINE(Vqhi,VQHI_CLTS) (Vqhi a, Vqhi b)
{
#define     VQHI_CLTS   QHI_CLTS
    return   QHI_CLTS(a, b);
}

INLINE(Vqhi,VQHF_CLTS) (Vqhf a, Vqhf b)
{
#define     VQHF_CLTS   QHF_CLTS
    return   QHF_CLTS(a, b);
}


INLINE(Vqwu,VQWU_CLTS) (Vqwu a, Vqwu b)
{
#define     VQWU_CLTS   QWU_CLTS
    return   QWU_CLTS(a, b);
}

INLINE(Vqwi,VQWI_CLTS) (Vqwi a, Vqwi b)
{
#define     VQWI_CLTS   QWI_CLTS
    return   QWI_CLTS(a, b);
}

INLINE(Vqwi,VQWF_CLTS) (Vqwf a, Vqwf b)
{
#define     VQWF_CLTS   QWF_CLTS
    return   QWF_CLTS(a, b);
}


INLINE(Vqdu,VQDU_CLTS) (Vqdu a, Vqdu b)
{
#define     VQDU_CLTS   QDU_CLTS
    return   QDU_CLTS(a, b);
}

INLINE(Vqdi,VQDI_CLTS) (Vqdi a, Vqdi b)
{
#define     VQDI_CLTS   QDI_CLTS
    return   QDI_CLTS(a, b);
}

INLINE(Vqdi,VQDF_CLTS) (Vqdf a, Vqdf b)
{
#define     VQDF_CLTS   QDF_CLTS
    return   QDF_CLTS(a, b);
}


#if _LEAVE_EXTGOP_ARM_CLTS
}
#endif

// clty
// cltz

#if _LEAVE_EXTGOP_ARM_CLT_
}
#endif

#if _ENTER_EXTGOP_ARM_CLE_
{
#endif

#if _ENTER_EXTGOP_ARM_CLES
{
#endif

#define     DBU_CLES                             vcle_u8
#define     DBI_CLES(A, B)  vreinterpret_s16_u16(vcle_s8(A,B))
#define     DBC_CLES        VDBC_BASE(CLES)
#define     DHU_CLES                             vcle_u16
#define     DHI_CLES(A, B)  vreinterpret_s16_u16(vcle_s16(A,B))
#if defined(SPC_ARM_FP16_SIMD)
#   define  DHF_CLES(A, B)  vreinterpret_s16_u16(vcle_f16(A,B))
#else
INLINE(float16x4_t,DHF_CLES)(float16x4_t a, float16x4_t b)
{
#   define  DHF_CLES    DHF_CLES
    MY_NOT_IMPLEMENTED(0, __func__);
    return  DHF_VOID;
}
#endif
#define     DWU_CLES                             vcle_u32
#define     DWI_CLES(A, B)  vreinterpret_s32_u32(vcle_s32(A,B))
#define     DWF_CLES(A, B)  vreinterpret_s32_u32(vcle_f32(A,B))
#define     DDU_CLES                             vcle_u64
#define     DDI_CLES(A, B)  vreinterpret_s64_u64(vcle_s32(A,B))
#define     DDF_CLES(A, B)  vreinterpret_s64_u64(vcle_f32(A,B))


#define     QBU_CLES                              vcleq_u8
#define     QBI_CLES(A, B)  vreinterpretq_s16_u16(vcleq_s8(A,B))
#define     QBC_CLES        VQBC_BASE(CLES)
#define     QHU_CLES                              vcleq_u16
#define     QHI_CLES(A, B)  vreinterpretq_s16_u16(vcleq_s16(A,B))
#if defined(SPC_ARM_FP16_SIMD)
#   define  QHF_CLES(A, B)  vreinterpretq_s16_u16(vcleq_f16(A,B))
#else
INLINE(float16x8_t,QHF_CLES)(float16x8_t a, float16x8_t b)
{
#   define  QHF_CLES    QHF_CLES
    MY_NOT_IMPLEMENTED(0, __func__);
    return  QHF_VOID;
}
#endif

#define     QWU_CLES                              vcleq_u32
#define     QWI_CLES(A, B)  vreinterpretq_s32_u32(vcleq_s32(A,B))
#define     QWF_CLES(A, B)  vreinterpretq_s32_u32(vcleq_f32(A,B))
#define     QDU_CLES                              vcleq_u64
#define     QDI_CLES(A, B)  vreinterpretq_s64_u64(vcleq_s32(A,B))
#define     QDF_CLES(A, B)  vreinterpretq_s64_u64(vcleq_f32(A,B))


INLINE(Vwbu,VWBU_CLES) (Vwbu a, Vwbu b)
{
    float32x2_t l = vset_lane_f32(VWBU_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWBU_ASTM(a), r, V2_K0);
    uint8x8_t   p = vreinterpret_u8_f32(l);
    uint8x8_t   q = vreinterpret_u8_f32(r);
    return WBU_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u8(DBU_CLES(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwbi,VWBI_CLES) (Vwbi a, Vwbi b)
{
    float32x2_t l = vset_lane_f32(VWBI_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWBI_ASTM(a), r, V2_K0);
    int8x8_t    p = vreinterpret_s8_f32(l);
    int8x8_t    q = vreinterpret_s8_f32(r);
    return  WBI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u8(vcle_s8(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwbc,VWBC_CLES) (Vwbc a, Vwbc b)
{
    float32x2_t x = vset_lane_f32(VWBC_ASTM(a), x, V2_K0);
    float32x2_t y = vset_lane_f32(VWBC_ASTM(a), y, V2_K0);
    float32x2_t r;
#if CHAR_MIN
    int8x8_t    p = vreinterpret_s8_f32(x);
    int8x8_t    q = vreinterpret_s8_f32(y);
    r = vreinterpret_f32_u8(vcle_s8(p, q));
#else
    uint8x8_t   p = vreinterpret_u8_f32(x);
    uint8x8_t   q = vreinterpret_u8_f32(y);
    r = vreinterpret_f32_u8(vcle_u8(p, q));
#endif
    return  WBC_ASTV(vget_lane_f32(r, V2_K0));
}


INLINE(Vwhu,VWHU_CLES) (Vwhu a, Vwhu b)
{
    float32x2_t l = vset_lane_f32(VWHU_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWHU_ASTM(a), r, V2_K0);
    uint16x4_t  p = vreinterpret_u16_f32(l);
    uint16x4_t  q = vreinterpret_u16_f32(r);
    return  WHU_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u16(vcle_u16(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwhi,VWHI_CLES) (Vwhi a, Vwhi b)
{
    float32x2_t l = vset_lane_f32(VWHI_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWHI_ASTM(a), r, V2_K0);
    int16x4_t   p = vreinterpret_s16_f32(l);
    int16x4_t   q = vreinterpret_s16_f32(r);
    return  WHI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u16(vcle_s16(p, q)),
            V2_K0
        )
    );
}

#if defined(SPC_ARM_FP16_SIMD)
INLINE(Vwhi,VWHF_CLES) (Vwhf a, Vwhf b)
{
#   define  VWHF_CLES VWHF_CLES
    float32x2_t l = vset_lane_f32(VWHF_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWHF_ASTM(a), r, V2_K0);
    float16x4_t p = vreinterpret_f16_f32(l);
    float16x4_t q = vreinterpret_f16_f32(r);
    return  WHI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u16(vcle_f16(p, q)),
            V2_K0
        )
    );
}
#else
INLINE(Vwhf,VWHF_CLES)(Vwhf a, Vwhf b)
{
#   define  VWHF_CLES    VWHF_CLES
    MY_NOT_IMPLEMENTED(0, __func__);
    return  VWHF_VOID;
}
#endif


INLINE(Vwwu,VWWU_CLES) (Vwwu a, Vwwu b)
{
    float32x2_t l = vset_lane_f32(VWWU_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWWU_ASTM(a), r, V2_K0);
    uint32x2_t  p = vreinterpret_u32_f32(l);
    uint32x2_t  q = vreinterpret_u32_f32(r);
    return  WWU_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u16(vcle_u32(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwwi,VWWI_CLES) (Vwwi a, Vwwi b)
{
    float32x2_t l = vset_lane_f32(VWWI_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWWI_ASTM(a), r, V2_K0);
    int32x2_t   p = vreinterpret_s32_f32(l);
    int32x2_t   q = vreinterpret_s32_f32(r);
    return WWI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u32(vcle_s32(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwwi,VWWF_CLES) (Vwwf a, Vwwf b)
{
    float32x2_t p = vset_lane_f32(VWWF_ASTM(a), p, V2_K0);
    float32x2_t q = vset_lane_f32(VWWF_ASTM(a), q, V2_K0);
    return WWI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u32(vcle_f32(p, q)),
            V2_K0
        )
    );
}


INLINE(Vdbu,VDBU_CLES) (Vdbu a, Vdbu b)
{
#define     VDBU_CLES   DBU_CLES
    return   DBU_CLES(a, b);
}

INLINE(Vdbi,VDBI_CLES) (Vdbi a, Vdbi b)
{
#define     VDBI_CLES   DBI_CLES
    return   DBI_CLES(a, b);
}

INLINE(Vdbc,VDBC_CLES) (Vdbc a, Vdbc b)
{
#define     VDBC_CLES   VDBC_CLES
    VDBC_MTYPE l = VDBC_ASTM(a);
    VDBC_MTYPE r = VDBC_ASTM(b);
    return  DBC_ASTV(DBC_CLES(l, r));
}


INLINE(Vdhu,VDHU_CLES) (Vdhu a, Vdhu b)
{
#define     VDHU_CLES   DHU_CLES
    return   DHU_CLES(a, b);
}

INLINE(Vdhi,VDHI_CLES) (Vdhi a, Vdhi b)
{
#define     VDHI_CLES   DHI_CLES
    return   DHI_CLES(a, b);
}

INLINE(Vdhi,VDHF_CLES) (Vdhf a, Vdhf b)
{
#define     VDHF_CLES   DHF_CLES
    return   DHF_CLES(a, b);
}


INLINE(Vdwu,VDWU_CLES) (Vdwu a, Vdwu b)
{
#define     VDWU_CLES   DWU_CLES
    return   DWU_CLES(a, b);
}

INLINE(Vdwi,VDWI_CLES) (Vdwi a, Vdwi b)
{
#define     VDWI_CLES   DWI_CLES
    return   DWI_CLES(a, b);
}

INLINE(Vdwi,VDWF_CLES) (Vdwf a, Vdwf b)
{
#define     VDWF_CLES   DWF_CLES
    return   DWF_CLES(a, b);
}


INLINE(Vddu,VDDU_CLES) (Vddu a, Vddu b)
{
#define     VDDU_CLES   DDU_CLES
    return   DDU_CLES(a, b);
}

INLINE(Vddi,VDDI_CLES) (Vddi a, Vddi b)
{
#define     VDDI_CLES   DDI_CLES
    return   DDI_CLES(a, b);
}

INLINE(Vddi,VDDF_CLES) (Vddf a, Vddf b)
{
#define     VDDF_CLES   DDF_CLES
    return   DDF_CLES(a, b);
}


INLINE(Vqbu,VQBU_CLES) (Vqbu a, Vqbu b)
{
#define     VQBU_CLES   QBU_CLES
    return   QBU_CLES(a, b);
}

INLINE(Vqbi,VQBI_CLES) (Vqbi a, Vqbi b)
{
#define     VQBI_CLES   QBI_CLES
    return   QBI_CLES(a, b);
}

INLINE(Vqbc,VQBC_CLES) (Vqbc a, Vqbc b)
{
#define     VQBC_CLES   VQBC_CLES
    VQBC_MTYPE l = VQBC_ASTM(a);
    VQBC_MTYPE r = VQBC_ASTM(b);
    return  QBC_ASTV(QBC_CLES(l, r));
}


INLINE(Vqhu,VQHU_CLES) (Vqhu a, Vqhu b)
{
#define     VQHU_CLES   QHU_CLES
    return   QHU_CLES(a, b);
}

INLINE(Vqhi,VQHI_CLES) (Vqhi a, Vqhi b)
{
#define     VQHI_CLES   QHI_CLES
    return   QHI_CLES(a, b);
}

INLINE(Vqhi,VQHF_CLES) (Vqhf a, Vqhf b)
{
#define     VQHF_CLES   QHF_CLES
    return   QHF_CLES(a, b);
}


INLINE(Vqwu,VQWU_CLES) (Vqwu a, Vqwu b)
{
#define     VQWU_CLES   QWU_CLES
    return   QWU_CLES(a, b);
}

INLINE(Vqwi,VQWI_CLES) (Vqwi a, Vqwi b)
{
#define     VQWI_CLES   QWI_CLES
    return   QWI_CLES(a, b);
}

INLINE(Vqwi,VQWF_CLES) (Vqwf a, Vqwf b)
{
#define     VQWF_CLES   QWF_CLES
    return   QWF_CLES(a, b);
}


INLINE(Vqdu,VQDU_CLES) (Vqdu a, Vqdu b)
{
#define     VQDU_CLES   QDU_CLES
    return   QDU_CLES(a, b);
}

INLINE(Vqdi,VQDI_CLES) (Vqdi a, Vqdi b)
{
#define     VQDI_CLES   QDI_CLES
    return   QDI_CLES(a, b);
}

INLINE(Vqdi,VQDF_CLES) (Vqdf a, Vqdf b)
{
#define     VQDF_CLES   QDF_CLES
    return   QDF_CLES(a, b);
}

#if _LEAVE_EXTGOP_ARM_CLES
}
#endif
// cley
// clez

#if _LEAVE_EXTGOP_ARM_CLE_
}
#endif

#if _LEAVE_EXTGOP_ARM_CL__
}
#endif

#if _ENTER_EXTGOP_ARM_CG__
{
#endif

#if _ENTER_EXTGOP_ARM_CGT_
{
#endif

#if _ENTER_EXTGOP_ARM_CGTS
{
#endif

#define     DBU_CGTS                             vcgt_u8
#define     DBI_CGTS(A, B)  vreinterpret_s16_u16(vcgt_s8(A,B))
#define     DBC_CGTS        VDBC_BASE(CGTS)
#define     DHU_CGTS                             vcgt_u16
#define     DHI_CGTS(A, B)  vreinterpret_s16_u16(vcgt_s16(A,B))
#if defined(SPC_ARM_FP16_SIMD)
#   define  DHF_CGTS(A, B)  vreinterpret_s16_u16(vcgt_f16(A,B))
#else
INLINE(float16x4_t,DHF_CGTS)(float16x4_t a, float16x4_t b)
{
#   define  DHF_CGTS    DHF_CGTS
    MY_NOT_IMPLEMENTED(0, __func__);
    return  DHF_VOID;
}
#endif
#define     DWU_CGTS                             vcgt_u32
#define     DWI_CGTS(A, B)  vreinterpret_s32_u32(vcgt_s32(A,B))
#define     DWF_CGTS(A, B)  vreinterpret_s32_u32(vcgt_f32(A,B))
#define     DDU_CGTS                             vcgt_u64
#define     DDI_CGTS(A, B)  vreinterpret_s64_u64(vcgt_s32(A,B))
#define     DDF_CGTS(A, B)  vreinterpret_s64_u64(vcgt_f32(A,B))


#define     QBU_CGTS                              vcgtq_u8
#define     QBI_CGTS(A, B)  vreinterpretq_s16_u16(vcgtq_s8(A,B))
#define     QBC_CGTS        VQBC_BASE(CGTS)
#define     QHU_CGTS                              vcgtq_u16
#define     QHI_CGTS(A, B)  vreinterpretq_s16_u16(vcgtq_s16(A,B))
#if defined(SPC_ARM_FP16_SIMD)
#   define  QHF_CGTS(A, B)  vreinterpretq_s16_u16(vcgtq_f16(A,B))
#else
INLINE(float16x8_t,QHF_CGTS)(float16x8_t a, float16x8_t b)
{
#   define  QHF_CGTS    QHF_CGTS
    MY_NOT_IMPLEMENTED(0, __func__);
    return  QHF_VOID;
}
#endif

#define     QWU_CGTS                              vcgtq_u32
#define     QWI_CGTS(A, B)  vreinterpretq_s32_u32(vcgtq_s32(A,B))
#define     QWF_CGTS(A, B)  vreinterpretq_s32_u32(vcgtq_f32(A,B))
#define     QDU_CGTS                              vcgtq_u64
#define     QDI_CGTS(A, B)  vreinterpretq_s64_u64(vcgtq_s32(A,B))
#define     QDF_CGTS(A, B)  vreinterpretq_s64_u64(vcgtq_f32(A,B))


INLINE(Vwbu,VWBU_CGTS) (Vwbu a, Vwbu b)
{
    float32x2_t l = vset_lane_f32(VWBU_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWBU_ASTM(a), r, V2_K0);
    uint8x8_t   p = vreinterpret_u8_f32(l);
    uint8x8_t   q = vreinterpret_u8_f32(r);
    return WBU_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u8(DBU_CGTS(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwbi,VWBI_CGTS) (Vwbi a, Vwbi b)
{
    float32x2_t l = vset_lane_f32(VWBI_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWBI_ASTM(a), r, V2_K0);
    int8x8_t    p = vreinterpret_s8_f32(l);
    int8x8_t    q = vreinterpret_s8_f32(r);
    return  WBI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u8(vcgt_s8(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwbc,VWBC_CGTS) (Vwbc a, Vwbc b)
{
    float32x2_t x = vset_lane_f32(VWBC_ASTM(a), x, V2_K0);
    float32x2_t y = vset_lane_f32(VWBC_ASTM(a), y, V2_K0);
    float32x2_t r;
#if CHAR_MIN
    int8x8_t    p = vreinterpret_s8_f32(x);
    int8x8_t    q = vreinterpret_s8_f32(y);
    r = vreinterpret_f32_u8(vcgt_s8(p, q));
#else
    uint8x8_t   p = vreinterpret_u8_f32(x);
    uint8x8_t   q = vreinterpret_u8_f32(y);
    r = vreinterpret_f32_u8(vcgt_u8(p, q));
#endif
    return  WBC_ASTV(vget_lane_f32(r, V2_K0));
}


INLINE(Vwhu,VWHU_CGTS) (Vwhu a, Vwhu b)
{
    float32x2_t l = vset_lane_f32(VWHU_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWHU_ASTM(a), r, V2_K0);
    uint16x4_t  p = vreinterpret_u16_f32(l);
    uint16x4_t  q = vreinterpret_u16_f32(r);
    return  WHU_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u16(vcgt_u16(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwhi,VWHI_CGTS) (Vwhi a, Vwhi b)
{
    float32x2_t l = vset_lane_f32(VWHI_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWHI_ASTM(a), r, V2_K0);
    int16x4_t   p = vreinterpret_s16_f32(l);
    int16x4_t   q = vreinterpret_s16_f32(r);
    return  WHI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u16(vcgt_s16(p, q)),
            V2_K0
        )
    );
}

#if defined(SPC_ARM_FP16_SIMD)
INLINE(Vwhi,VWHF_CGTS) (Vwhf a, Vwhf b)
{
#   define  VWHF_CGTS VWHF_CGTS
    float32x2_t l = vset_lane_f32(VWHF_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWHF_ASTM(a), r, V2_K0);
    float16x4_t p = vreinterpret_f16_f32(l);
    float16x4_t q = vreinterpret_f16_f32(r);
    return  WHI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u16(vcgt_f16(p, q)),
            V2_K0
        )
    );
}
#else
INLINE(Vwhf,VWHF_CGTS)(Vwhf a, Vwhf b)
{
#   define  VWHF_CGTS    VWHF_CGTS
    MY_NOT_IMPLEMENTED(0, __func__);
    return  VWHF_VOID;
}
#endif


INLINE(Vwwu,VWWU_CGTS) (Vwwu a, Vwwu b)
{
    float32x2_t l = vset_lane_f32(VWWU_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWWU_ASTM(a), r, V2_K0);
    uint32x2_t  p = vreinterpret_u32_f32(l);
    uint32x2_t  q = vreinterpret_u32_f32(r);
    return  WWU_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u16(vcgt_u32(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwwi,VWWI_CGTS) (Vwwi a, Vwwi b)
{
    float32x2_t l = vset_lane_f32(VWWI_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWWI_ASTM(a), r, V2_K0);
    int32x2_t   p = vreinterpret_s32_f32(l);
    int32x2_t   q = vreinterpret_s32_f32(r);
    return WWI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u32(vcgt_s32(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwwi,VWWF_CGTS) (Vwwf a, Vwwf b)
{
    float32x2_t p = vset_lane_f32(VWWF_ASTM(a), p, V2_K0);
    float32x2_t q = vset_lane_f32(VWWF_ASTM(a), q, V2_K0);
    return WWI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u32(vcgt_f32(p, q)),
            V2_K0
        )
    );
}


INLINE(Vdbu,VDBU_CGTS) (Vdbu a, Vdbu b)
{
#define     VDBU_CGTS   DBU_CGTS
    return   DBU_CGTS(a, b);
}

INLINE(Vdbi,VDBI_CGTS) (Vdbi a, Vdbi b)
{
#define     VDBI_CGTS   DBI_CGTS
    return   DBI_CGTS(a, b);
}

INLINE(Vdbc,VDBC_CGTS) (Vdbc a, Vdbc b)
{
#define     VDBC_CGTS   VDBC_CGTS
    VDBC_MTYPE l = VDBC_ASTM(a);
    VDBC_MTYPE r = VDBC_ASTM(b);
    return  DBC_ASTV(DBC_CGTS(l, r));
}


INLINE(Vdhu,VDHU_CGTS) (Vdhu a, Vdhu b)
{
#define     VDHU_CGTS   DHU_CGTS
    return   DHU_CGTS(a, b);
}

INLINE(Vdhi,VDHI_CGTS) (Vdhi a, Vdhi b)
{
#define     VDHI_CGTS   DHI_CGTS
    return   DHI_CGTS(a, b);
}

INLINE(Vdhi,VDHF_CGTS) (Vdhf a, Vdhf b)
{
#define     VDHF_CGTS   DHF_CGTS
    return   DHF_CGTS(a, b);
}


INLINE(Vdwu,VDWU_CGTS) (Vdwu a, Vdwu b)
{
#define     VDWU_CGTS   DWU_CGTS
    return   DWU_CGTS(a, b);
}

INLINE(Vdwi,VDWI_CGTS) (Vdwi a, Vdwi b)
{
#define     VDWI_CGTS   DWI_CGTS
    return   DWI_CGTS(a, b);
}

INLINE(Vdwi,VDWF_CGTS) (Vdwf a, Vdwf b)
{
#define     VDWF_CGTS   DWF_CGTS
    return   DWF_CGTS(a, b);
}


INLINE(Vddu,VDDU_CGTS) (Vddu a, Vddu b)
{
#define     VDDU_CGTS   DDU_CGTS
    return   DDU_CGTS(a, b);
}

INLINE(Vddi,VDDI_CGTS) (Vddi a, Vddi b)
{
#define     VDDI_CGTS   DDI_CGTS
    return   DDI_CGTS(a, b);
}

INLINE(Vddi,VDDF_CGTS) (Vddf a, Vddf b)
{
#define     VDDF_CGTS   DDF_CGTS
    return   DDF_CGTS(a, b);
}


INLINE(Vqbu,VQBU_CGTS) (Vqbu a, Vqbu b)
{
#define     VQBU_CGTS   QBU_CGTS
    return   QBU_CGTS(a, b);
}

INLINE(Vqbi,VQBI_CGTS) (Vqbi a, Vqbi b)
{
#define     VQBI_CGTS   QBI_CGTS
    return   QBI_CGTS(a, b);
}

INLINE(Vqbc,VQBC_CGTS) (Vqbc a, Vqbc b)
{
#define     VQBC_CGTS   VQBC_CGTS
    VQBC_MTYPE l = VQBC_ASTM(a);
    VQBC_MTYPE r = VQBC_ASTM(b);
    return  QBC_ASTV(QBC_CGTS(l, r));
}


INLINE(Vqhu,VQHU_CGTS) (Vqhu a, Vqhu b)
{
#define     VQHU_CGTS   QHU_CGTS
    return   QHU_CGTS(a, b);
}

INLINE(Vqhi,VQHI_CGTS) (Vqhi a, Vqhi b)
{
#define     VQHI_CGTS   QHI_CGTS
    return   QHI_CGTS(a, b);
}

INLINE(Vqhi,VQHF_CGTS) (Vqhf a, Vqhf b)
{
#define     VQHF_CGTS   QHF_CGTS
    return   QHF_CGTS(a, b);
}


INLINE(Vqwu,VQWU_CGTS) (Vqwu a, Vqwu b)
{
#define     VQWU_CGTS   QWU_CGTS
    return   QWU_CGTS(a, b);
}

INLINE(Vqwi,VQWI_CGTS) (Vqwi a, Vqwi b)
{
#define     VQWI_CGTS   QWI_CGTS
    return   QWI_CGTS(a, b);
}

INLINE(Vqwi,VQWF_CGTS) (Vqwf a, Vqwf b)
{
#define     VQWF_CGTS   QWF_CGTS
    return   QWF_CGTS(a, b);
}


INLINE(Vqdu,VQDU_CGTS) (Vqdu a, Vqdu b)
{
#define     VQDU_CGTS   QDU_CGTS
    return   QDU_CGTS(a, b);
}

INLINE(Vqdi,VQDI_CGTS) (Vqdi a, Vqdi b)
{
#define     VQDI_CGTS   QDI_CGTS
    return   QDI_CGTS(a, b);
}

INLINE(Vqdi,VQDF_CGTS) (Vqdf a, Vqdf b)
{
#define     VQDF_CGTS   QDF_CGTS
    return   QDF_CGTS(a, b);
}


#if _LEAVE_EXTGOP_ARM_CGTS
}
#endif

#if _LEAVE_EXTGOP_ARM_CGT_
}
#endif

#if _ENTER_EXTGOP_ARM_CGE_
{
#endif

#if _ENTER_EXTGOP_ARM_CGES
{
#endif

#define     DBU_CGES                             vcge_u8
#define     DBI_CGES(A, B)  vreinterpret_s16_u16(vcge_s8(A,B))
#define     DBC_CGES        VDBC_BASE(CGES)
#define     DHU_CGES                             vcge_u16
#define     DHI_CGES(A, B)  vreinterpret_s16_u16(vcge_s16(A,B))
#if defined(SPC_ARM_FP16_SIMD)
#   define  DHF_CGES(A, B)  vreinterpret_s16_u16(vcge_f16(A,B))
#else
INLINE(float16x4_t,DHF_CGES)(float16x4_t a, float16x4_t b)
{
#   define  DHF_CGES    DHF_CGES
    MY_NOT_IMPLEMENTED(0, __func__);
    return  DHF_VOID;
}
#endif
#define     DWU_CGES                             vcge_u32
#define     DWI_CGES(A, B)  vreinterpret_s32_u32(vcge_s32(A,B))
#define     DWF_CGES(A, B)  vreinterpret_s32_u32(vcge_f32(A,B))
#define     DDU_CGES                             vcge_u64
#define     DDI_CGES(A, B)  vreinterpret_s64_u64(vcge_s32(A,B))
#define     DDF_CGES(A, B)  vreinterpret_s64_u64(vcge_f32(A,B))


#define     QBU_CGES                              vcgeq_u8
#define     QBI_CGES(A, B)  vreinterpretq_s16_u16(vcgeq_s8(A,B))
#define     QBC_CGES        VQBC_BASE(CGES)
#define     QHU_CGES                              vcgeq_u16
#define     QHI_CGES(A, B)  vreinterpretq_s16_u16(vcgeq_s16(A,B))
#if defined(SPC_ARM_FP16_SIMD)
#   define  QHF_CGES(A, B)  vreinterpretq_s16_u16(vcgeq_f16(A,B))
#else
INLINE(float16x8_t,QHF_CGES)(float16x8_t a, float16x8_t b)
{
#   define  QHF_CGES    QHF_CGES
    MY_NOT_IMPLEMENTED(0, __func__);
    return  QHF_VOID;
}
#endif

#define     QWU_CGES                              vcgeq_u32
#define     QWI_CGES(A, B)  vreinterpretq_s32_u32(vcgeq_s32(A,B))
#define     QWF_CGES(A, B)  vreinterpretq_s32_u32(vcgeq_f32(A,B))
#define     QDU_CGES                              vcgeq_u64
#define     QDI_CGES(A, B)  vreinterpretq_s64_u64(vcgeq_s32(A,B))
#define     QDF_CGES(A, B)  vreinterpretq_s64_u64(vcgeq_f32(A,B))


INLINE(Vwbu,VWBU_CGES) (Vwbu a, Vwbu b)
{
    float32x2_t l = vset_lane_f32(VWBU_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWBU_ASTM(a), r, V2_K0);
    uint8x8_t   p = vreinterpret_u8_f32(l);
    uint8x8_t   q = vreinterpret_u8_f32(r);
    return WBU_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u8(DBU_CGES(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwbi,VWBI_CGES) (Vwbi a, Vwbi b)
{
    float32x2_t l = vset_lane_f32(VWBI_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWBI_ASTM(a), r, V2_K0);
    int8x8_t    p = vreinterpret_s8_f32(l);
    int8x8_t    q = vreinterpret_s8_f32(r);
    return  WBI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u8(vcge_s8(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwbc,VWBC_CGES) (Vwbc a, Vwbc b)
{
    float32x2_t x = vset_lane_f32(VWBC_ASTM(a), x, V2_K0);
    float32x2_t y = vset_lane_f32(VWBC_ASTM(a), y, V2_K0);
    float32x2_t r;
#if CHAR_MIN
    int8x8_t    p = vreinterpret_s8_f32(x);
    int8x8_t    q = vreinterpret_s8_f32(y);
    r = vreinterpret_f32_u8(vcge_s8(p, q));
#else
    uint8x8_t   p = vreinterpret_u8_f32(x);
    uint8x8_t   q = vreinterpret_u8_f32(y);
    r = vreinterpret_f32_u8(vcge_u8(p, q));
#endif
    return  WBC_ASTV(vget_lane_f32(r, V2_K0));
}


INLINE(Vwhu,VWHU_CGES) (Vwhu a, Vwhu b)
{
    float32x2_t l = vset_lane_f32(VWHU_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWHU_ASTM(a), r, V2_K0);
    uint16x4_t  p = vreinterpret_u16_f32(l);
    uint16x4_t  q = vreinterpret_u16_f32(r);
    return  WHU_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u16(vcge_u16(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwhi,VWHI_CGES) (Vwhi a, Vwhi b)
{
    float32x2_t l = vset_lane_f32(VWHI_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWHI_ASTM(a), r, V2_K0);
    int16x4_t   p = vreinterpret_s16_f32(l);
    int16x4_t   q = vreinterpret_s16_f32(r);
    return  WHI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u16(vcge_s16(p, q)),
            V2_K0
        )
    );
}

#if defined(SPC_ARM_FP16_SIMD)
INLINE(Vwhi,VWHF_CGES) (Vwhf a, Vwhf b)
{
#   define  VWHF_CGES VWHF_CGES
    float32x2_t l = vset_lane_f32(VWHF_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWHF_ASTM(a), r, V2_K0);
    float16x4_t p = vreinterpret_f16_f32(l);
    float16x4_t q = vreinterpret_f16_f32(r);
    return  WHI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u16(vcge_f16(p, q)),
            V2_K0
        )
    );
}
#else
INLINE(Vwhf,VWHF_CGES)(Vwhf a, Vwhf b)
{
#   define  VWHF_CGES    VWHF_CGES
    MY_NOT_IMPLEMENTED(0, __func__);
    return  VWHF_VOID;
}
#endif


INLINE(Vwwu,VWWU_CGES) (Vwwu a, Vwwu b)
{
    float32x2_t l = vset_lane_f32(VWWU_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWWU_ASTM(a), r, V2_K0);
    uint32x2_t  p = vreinterpret_u32_f32(l);
    uint32x2_t  q = vreinterpret_u32_f32(r);
    return  WWU_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u16(vcge_u32(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwwi,VWWI_CGES) (Vwwi a, Vwwi b)
{
    float32x2_t l = vset_lane_f32(VWWI_ASTM(a), l, V2_K0);
    float32x2_t r = vset_lane_f32(VWWI_ASTM(a), r, V2_K0);
    int32x2_t   p = vreinterpret_s32_f32(l);
    int32x2_t   q = vreinterpret_s32_f32(r);
    return WWI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u32(vcge_s32(p, q)),
            V2_K0
        )
    );
}

INLINE(Vwwi,VWWF_CGES) (Vwwf a, Vwwf b)
{
    float32x2_t p = vset_lane_f32(VWWF_ASTM(a), p, V2_K0);
    float32x2_t q = vset_lane_f32(VWWF_ASTM(a), q, V2_K0);
    return WWI_ASTV(
        vget_lane_f32(
            vreinterpret_f32_u32(vcge_f32(p, q)),
            V2_K0
        )
    );
}


INLINE(Vdbu,VDBU_CGES) (Vdbu a, Vdbu b)
{
#define     VDBU_CGES   DBU_CGES
    return   DBU_CGES(a, b);
}

INLINE(Vdbi,VDBI_CGES) (Vdbi a, Vdbi b)
{
#define     VDBI_CGES   DBI_CGES
    return   DBI_CGES(a, b);
}

INLINE(Vdbc,VDBC_CGES) (Vdbc a, Vdbc b)
{
#define     VDBC_CGES   VDBC_CGES
    VDBC_MTYPE l = VDBC_ASTM(a);
    VDBC_MTYPE r = VDBC_ASTM(b);
    return  DBC_ASTV(DBC_CGES(l, r));
}


INLINE(Vdhu,VDHU_CGES) (Vdhu a, Vdhu b)
{
#define     VDHU_CGES   DHU_CGES
    return   DHU_CGES(a, b);
}

INLINE(Vdhi,VDHI_CGES) (Vdhi a, Vdhi b)
{
#define     VDHI_CGES   DHI_CGES
    return   DHI_CGES(a, b);
}

INLINE(Vdhi,VDHF_CGES) (Vdhf a, Vdhf b)
{
#define     VDHF_CGES   DHF_CGES
    return   DHF_CGES(a, b);
}


INLINE(Vdwu,VDWU_CGES) (Vdwu a, Vdwu b)
{
#define     VDWU_CGES   DWU_CGES
    return   DWU_CGES(a, b);
}

INLINE(Vdwi,VDWI_CGES) (Vdwi a, Vdwi b)
{
#define     VDWI_CGES   DWI_CGES
    return   DWI_CGES(a, b);
}

INLINE(Vdwi,VDWF_CGES) (Vdwf a, Vdwf b)
{
#define     VDWF_CGES   DWF_CGES
    return   DWF_CGES(a, b);
}


INLINE(Vddu,VDDU_CGES) (Vddu a, Vddu b)
{
#define     VDDU_CGES   DDU_CGES
    return   DDU_CGES(a, b);
}

INLINE(Vddi,VDDI_CGES) (Vddi a, Vddi b)
{
#define     VDDI_CGES   DDI_CGES
    return   DDI_CGES(a, b);
}

INLINE(Vddi,VDDF_CGES) (Vddf a, Vddf b)
{
#define     VDDF_CGES   DDF_CGES
    return   DDF_CGES(a, b);
}


INLINE(Vqbu,VQBU_CGES) (Vqbu a, Vqbu b)
{
#define     VQBU_CGES   QBU_CGES
    return   QBU_CGES(a, b);
}

INLINE(Vqbi,VQBI_CGES) (Vqbi a, Vqbi b)
{
#define     VQBI_CGES   QBI_CGES
    return   QBI_CGES(a, b);
}

INLINE(Vqbc,VQBC_CGES) (Vqbc a, Vqbc b)
{
#define     VQBC_CGES   VQBC_CGES
    VQBC_MTYPE l = VQBC_ASTM(a);
    VQBC_MTYPE r = VQBC_ASTM(b);
    return  QBC_ASTV(QBC_CGES(l, r));
}


INLINE(Vqhu,VQHU_CGES) (Vqhu a, Vqhu b)
{
#define     VQHU_CGES   QHU_CGES
    return   QHU_CGES(a, b);
}

INLINE(Vqhi,VQHI_CGES) (Vqhi a, Vqhi b)
{
#define     VQHI_CGES   QHI_CGES
    return   QHI_CGES(a, b);
}

INLINE(Vqhi,VQHF_CGES) (Vqhf a, Vqhf b)
{
#define     VQHF_CGES   QHF_CGES
    return   QHF_CGES(a, b);
}


INLINE(Vqwu,VQWU_CGES) (Vqwu a, Vqwu b)
{
#define     VQWU_CGES   QWU_CGES
    return   QWU_CGES(a, b);
}

INLINE(Vqwi,VQWI_CGES) (Vqwi a, Vqwi b)
{
#define     VQWI_CGES   QWI_CGES
    return   QWI_CGES(a, b);
}

INLINE(Vqwi,VQWF_CGES) (Vqwf a, Vqwf b)
{
#define     VQWF_CGES   QWF_CGES
    return   QWF_CGES(a, b);
}


INLINE(Vqdu,VQDU_CGES) (Vqdu a, Vqdu b)
{
#define     VQDU_CGES   QDU_CGES
    return   QDU_CGES(a, b);
}

INLINE(Vqdi,VQDI_CGES) (Vqdi a, Vqdi b)
{
#define     VQDI_CGES   QDI_CGES
    return   QDI_CGES(a, b);
}

INLINE(Vqdi,VQDF_CGES) (Vqdf a, Vqdf b)
{
#define     VQDF_CGES   QDF_CGES
    return   QDF_CGES(a, b);
}


#if _LEAVE_EXTGOP_ARM_CGES
}
#endif

#if _LEAVE_EXTGOP_ARM_CGE_
}
#endif

#if _LEAVE_EXTGOP_ARM_CG__
}
#endif

#endif // #ifdef SPC_ARM_NEON

#if _LEAVE_EXTGOP_ARM
}
#endif


#if _ENTER_EXTGOP_X86
{
#endif

#ifdef SPC_X86_SSE2


#if _ENTER_EXTGOP_X86_VOID
{
#endif

#define     WBU_VOID    (0.0f)
#define     WBI_VOID    (0.0f)
#define     WHU_VOID    (0.0f)
#define     WHI_VOID    (0.0f)
#define     WHF_VOID    (0.0f)
#define     WWU_VOID    (0.0f)
#define     WWI_VOID    (0.0f)
#define     WWF_VOID    (0.0f)

#define     DBU_VOID    (0.0)
#define     DBI_VOID    (0.0)
#define     DHU_VOID    (0.0)
#define     DHI_VOID    (0.0)
#define     DHF_VOID    (0.0)
#define     DWU_VOID    (0.0)
#define     DWI_VOID    (0.0)
#define     DWF_VOID    (0.0)
#define     DDU_VOID    (0.0)
#define     DDI_VOID    (0.0)
#define     DDF_VOID    (0.0)

#define     QYU_VOID    (_mm_undefined_si128())
#define     QBU_VOID    (_mm_undefined_si128())
#define     QBI_VOID    (_mm_undefined_si128())
#define     QHU_VOID    (_mm_undefined_si128())
#define     QHI_VOID    (_mm_undefined_si128())
#if defined(SPC_X86_AVX512FP16)
#   define  QHF_VOID    (_mm_undefined_ph())
#else
#   define  QHF_VOID    (_mm_undefined_si128())
#endif
#define     QWU_VOID    (_mm_undefined_si128())
#define     QWI_VOID    (_mm_undefined_si128())
#define     QWF_VOID    (_mm_undefined_ps())
#define     QDU_VOID    (_mm_undefined_si128())
#define     QDI_VOID    (_mm_undefined_si128())
#define     QDF_VOID    (_mm_undefined_pd())

#define     VWYU_VOID   ((VWYU_TYPE){WYU_VOID})
#define     VWBU_VOID   ((VWBU_TYPE){WBU_VOID})
#define     VWBI_VOID   ((VWBI_TYPE){WBI_VOID})
#define     VWHU_VOID   ((VWHU_TYPE){WHU_VOID})
#define     VWHI_VOID   ((VWHI_TYPE){WHI_VOID})
#define     VWHF_VOID   ((VWHF_TYPE){WHF_VOID})
#define     VWWU_VOID   ((VWWU_TYPE){WWU_VOID})
#define     VWWI_VOID   ((VWWI_TYPE){WWI_VOID})
#define     VWWF_VOID   ((VWWF_TYPE){WWF_VOID})

#define     VDYU_VOID   ((VDYU_TYPE){DYU_VOID})
#define     VDBU_VOID   ((VDBU_TYPE){DBU_VOID})
#define     VDBI_VOID   ((VDBI_TYPE){DBI_VOID})
#define     VDHU_VOID   ((VDHU_TYPE){DHU_VOID})
#define     VDHI_VOID   ((VDHI_TYPE){DHI_VOID})
#define     VDHF_VOID   ((VDHF_TYPE){DHF_VOID})
#define     VDWU_VOID   ((VDWU_TYPE){DWU_VOID})
#define     VDWI_VOID   ((VDWI_TYPE){DWI_VOID})
#define     VDWF_VOID   ((VDWF_TYPE){DWF_VOID})
#define     VDDU_VOID   ((VDDU_TYPE){DDU_VOID})
#define     VDDI_VOID   ((VDDI_TYPE){DDI_VOID})
#define     VDDF_VOID   ((VDDF_TYPE){DDF_VOID})


#define     VQYU_VOID   QYU_VOID
#define     VQBU_VOID   ((VQBU_TYPE){QBU_VOID})
#define     VQBI_VOID   ((VQBI_TYPE){QBI_VOID})

#define     VQHU_VOID   ((VQHU_TYPE){QHU_VOID})
#define     VQHI_VOID   ((VQHI_TYPE){QHI_VOID})
#if defined(SPC_X86_AVX512FP16)
#   define  VQHF_VOID   QHF_VOID
#else
#   define  VQHF_VOID   ((VQHF_TYPE){QHF_VOID})
#endif

#define     VQWU_VOID   ((VQWU_TYPE){QWU_VOID})
#define     VQWI_VOID   ((VQWI_TYPE){QWI_VOID})
#define     VQWF_VOID   QWF_VOID
#define     VQDU_VOID   ((VQDU_TYPE){QDU_VOID})
#define     VQDI_VOID   ((VQDI_TYPE){QDI_VOID})
#define     VQDF_VOID   QDF_VOID


#if _LEAVE_EXTGOP_X86_VOID
}
#endif

#if _ENTER_EXTGOP_X86_ASTM
{
#endif

// astm
#define     MY_HVA1_ASTM(T,V)   _Generic((V),T:(V).V0)

#define     VWBU_ASTM(V)        MY_HVA1_ASTM(VWBU_TYPE,V)
#define     VWBI_ASTM(V)        MY_HVA1_ASTM(VWBI_TYPE,V)
#define     VWBC_ASTM(V)        MY_HVA1_ASTM(VWBC_TYPE,V)
#define     VWHU_ASTM(V)        MY_HVA1_ASTM(VWHU_TYPE,V)
#define     VWHI_ASTM(V)        MY_HVA1_ASTM(VWHI_TYPE,V)
#define     VWHF_ASTM(V)        MY_HVA1_ASTM(VWHF_TYPE,V)
#define     VWWU_ASTM(V)        MY_HVA1_ASTM(VWWU_TYPE,V)
#define     VWWI_ASTM(V)        MY_HVA1_ASTM(VWWI_TYPE,V)
#define     VWWF_ASTM(V)        MY_HVA1_ASTM(VWWF_TYPE,V)

#define     VDBU_ASTM(V)        MY_HVA1_ASTM(VDBU_TYPE,V)
#define     VDBI_ASTM(V)        MY_HVA1_ASTM(VDBI_TYPE,V)
#define     VDBC_ASTM(V)        MY_HVA1_ASTM(VDBC_TYPE,V)
#define     VDHU_ASTM(V)        MY_HVA1_ASTM(VDHU_TYPE,V)
#define     VDHI_ASTM(V)        MY_HVA1_ASTM(VDHI_TYPE,V)
#define     VDHF_ASTM(V)        MY_HVA1_ASTM(VDHF_TYPE,V)
#define     VDWU_ASTM(V)        MY_HVA1_ASTM(VDWU_TYPE,V)
#define     VDWI_ASTM(V)        MY_HVA1_ASTM(VDWI_TYPE,V)
#define     VDWF_ASTM(V)        MY_HVA1_ASTM(VDWF_TYPE,V)
#define     VDDU_ASTM(V)        MY_HVA1_ASTM(VDDU_TYPE,V)
#define     VDDI_ASTM(V)        MY_HVA1_ASTM(VDDI_TYPE,V)
#define     VDDF_ASTM(V)        MY_HVA1_ASTM(VDDF_TYPE,V)

#define     VQBU_ASTM(V)        MY_HVA1_ASTM(VQBU_TYPE,V)
#define     VQBI_ASTM(V)        MY_HVA1_ASTM(VQBI_TYPE,V)
#define     VQBC_ASTM(V)        MY_HVA1_ASTM(VQBC_TYPE,V)

#define     VQHU_ASTM(V)        MY_HVA1_ASTM(VQHU_TYPE,V)
#define     VQHI_ASTM(V)        MY_HVA1_ASTM(VQHI_TYPE,V)
#if defined(SPC_X86_AVX512FP16)
#   define  VQHF_ASTM           VQHF_REQS
#else
#define     VQHF_ASTM(V)        MY_HVA1_ASTM(VQHF_TYPE,V)
#endif

#define     VQWU_ASTM(V)        MY_HVA1_ASTM(VQWU_TYPE,V)
#define     VQWI_ASTM(V)        MY_HVA1_ASTM(VQWI_TYPE,V)
#define     VQWF_ASTM           VQWF_REQS
#define     VQDU_ASTM(V)        MY_HVA1_ASTM(VQDU_TYPE,V)
#define     VQDI_ASTM(V)        MY_HVA1_ASTM(VQDI_TYPE,V)
#define     VQDF_ASTM(V)        MY_HVA1_ASTM(VQDF_TYPE,V)
#define     VQDF_ASTM           VQDF_REQS

#if _LEAVE_EXTGOP_X86_ASTM
}
#endif

#if _ENTER_EXTGOP_X86_ASTV
{
#endif

#define     MY_HVA1_NEWL(T,M)   ((T){.V0=(M)})

#define     WYU_ASTV(M)         MY_HVA1_NEWL(VWYU_TYPE,M)
#define     WBU_ASTV(M)         MY_HVA1_NEWL(VWBU_TYPE,M)
#define     WBI_ASTV(M)         MY_HVA1_NEWL(VWBI_TYPE,M)
#define     WBC_ASTV(M)         MY_HVA1_NEWL(VWBC_TYPE,M)
#define     WHU_ASTV(M)         MY_HVA1_NEWL(VWHU_TYPE,M)
#define     WHI_ASTV(M)         MY_HVA1_NEWL(VWHI_TYPE,M)
#define     WHF_ASTV(M)         MY_HVA1_NEWL(VWHF_TYPE,M)
#define     WWU_ASTV(M)         MY_HVA1_NEWL(VWWU_TYPE,M)
#define     WWI_ASTV(M)         MY_HVA1_NEWL(VWWI_TYPE,M)
#define     WWF_ASTV(M)         MY_HVA1_NEWL(VWWF_TYPE,M)

#define     VWWU_ASTV(V)        ((WORD_TYPE){.F=(VWWU_REQS(V).V0)}).U
#define     VWWI_ASTV(V)        ((WORD_TYPE){.F=(VWWI_REQS(V).V0)}).I
#define     VWWF_ASTV(V)                        (VWWU_REQS(V).V0)

#define     DYU_ASTV(M)         MY_HVA1_NEWL(VDYU_TYPE,M)
#define     DBU_ASTV(M)         MY_HVA1_NEWL(VDBU_TYPE,M)
#define     DBI_ASTV(M)         MY_HVA1_NEWL(VDBI_TYPE,M)
#define     DBC_ASTV(M)         MY_HVA1_NEWL(VDBC_TYPE,M)
#define     DHU_ASTV(M)         MY_HVA1_NEWL(VDHU_TYPE,M)
#define     DHI_ASTV(M)         MY_HVA1_NEWL(VDHI_TYPE,M)
#define     DHF_ASTV(M)         MY_HVA1_NEWL(VDHF_TYPE,M)
#define     DWU_ASTV(M)         MY_HVA1_NEWL(VDWU_TYPE,M)
#define     DWI_ASTV(M)         MY_HVA1_NEWL(VDWI_TYPE,M)
#define     DWF_ASTV(M)         MY_HVA1_NEWL(VDWF_TYPE,M)
#define     DDU_ASTV(M)         MY_HVA1_NEWL(VDDU_TYPE,M)
#define     DDI_ASTV(M)         MY_HVA1_NEWL(VDDI_TYPE,M)
#define     DDF_ASTV(M)         MY_HVA1_NEWL(VDDF_TYPE,M)

#define     VDYU_ASTV(V)        ((DWRD_TYPE){.F=(VDDU_REQS(V).V0)}).U
#define     VDDU_ASTV(V)        ((DWRD_TYPE){.F=(VDDU_REQS(V).V0)}).U
#define     VDDI_ASTV(V)        ((DWRD_TYPE){.F=(VDDI_REQS(V).V0)}).I
#define     VDDF_ASTV(V)                        (VDDU_REQS(V).V0)

#define     QYU_ASTV(M)         _Generic((M),__m128i:(M))
#define     QBU_ASTV(M)         MY_HVA1_NEWL(VDBU_TYPE,M)
#define     QBI_ASTV(M)         MY_HVA1_NEWL(VQBI_TYPE,M)
#define     QBC_ASTV(M)         MY_HVA1_NEWL(VQBC_TYPE,M)
#define     QHU_ASTV(M)         MY_HVA1_NEWL(VQHU_TYPE,M)
#define     QHI_ASTV(M)         MY_HVA1_NEWL(VQHI_TYPE,M)
#if defined(SPC_X86_AVX512FP16)
#   define  QHF_ASTV(M)         _Generic((M),__m128h:(M))
#else
#   define  QHF_ASTV(M)         MY_HVA1_NEWL(VQHF_TYPE,M)
#endif
#define     QWU_ASTV(M)         MY_HVA1_NEWL(VQWU_TYPE,M)
#define     QWI_ASTV(M)         MY_HVA1_NEWL(VQWI_TYPE,M)
#define     QWF_ASTV(M)         _Generic((M),__m128: (M))
#define     QDU_ASTV(M)         MY_HVA1_NEWL(VQDU_TYPE,M)
#define     QDI_ASTV(M)         MY_HVA1_NEWL(VQDI_TYPE,M)
#define     QDF_ASTV(M)         _Generic((M),__m128d:(M))

#if _LEAVE_EXTGOP_X86_ASTV
}
#endif

#if _ENTER_EXTGOP_X86_ASYU
{
#endif

#define     QBU_ASYU(M)     (M)
#define     QBI_ASYU(M)     (M)
#define     QBC_ASYU(M)     (M)
#define     QHU_ASYU(M)     (M)
#define     QHU_ASYU(M)     (M)
#define     QHI_ASYU(M)     (M)
#if defined(SPC_X86_AVX512FP16)
#   define  QHF_ASYU        _mm_castph_si128
#else
#   define  QHF_ASYU(M)     (M)
#endif

#define     QWU_ASYU(M)     (M)
#define     QWI_ASYU(M)     (M)
#define     QWF_ASYU        _mm_castps_si128
#define     QDU_ASYU(M)     (M)
#define     QDI_ASYU(M)     (M)
#define     QDF_ASYU        _mm_castpd_si128

#define     VWBU_ASYU(V)    WYU_ASTV(VWBU_ASTM(V))
#define     VWBI_ASYU(V)    WYU_ASTV(VWBI_ASTM(V))
#define     VWBC_ASYU(V)    WYU_ASTV(VWBC_ASTM(V))
#define     VWHU_ASYU(V)    WYU_ASTV(VWHU_ASTM(V))
#define     VWHI_ASYU(V)    WYU_ASTV(VWHI_ASTM(V))
#define     VWHF_ASYU(V)    WYU_ASTV(VWHF_ASTM(V))
#define     VWWU_ASYU(V)    WYU_ASTV(VWWU_ASTM(V))
#define     VWWI_ASYU(V)    WYU_ASTV(VWWI_ASTM(V))
#define     VWWF_ASYU(V)    WYU_ASTV(VWWF_ASTM(V))

#define     VDBU_ASYU(V)    DYU_ASTV(VDBU_ASTM(V))
#define     VDBI_ASYU(V)    DYU_ASTV(VDBI_ASTM(V))
#define     VDBC_ASYU(V)    DYU_ASTV(VDBC_ASTM(V))
#define     VDHU_ASYU(V)    DYU_ASTV(VDHU_ASTM(V))
#define     VDHI_ASYU(V)    DYU_ASTV(VDHI_ASTM(V))
#define     VDHF_ASYU(V)    DYU_ASTV(VDHF_ASTM(V))
#define     VDWU_ASYU(V)    DYU_ASTV(VDWU_ASTM(V))
#define     VDWI_ASYU(V)    DYU_ASTV(VDWI_ASTM(V))
#define     VDWF_ASYU(V)    DYU_ASTV(VDWF_ASTM(V))
#define     VDDU_ASYU(V)    DYU_ASTV(VDDU_ASTM(V))
#define     VDDI_ASYU(V)    DYU_ASTV(VDDI_ASTM(V))
#define     VDDF_ASYU(V)    DYU_ASTV(VDWF_ASTM(V))

#define     VQBU_ASYU(M)    QYU_ASTV(QBU_ASYU(VQBU_ASTM(V)))
#define     VQBI_ASYU(V)    QYU_ASTV(QBI_ASYU(VQBI_ASTM(V)))
#define     VQBC_ASYU(V)    QYU_ASTV(QBC_ASYU(VQBC_ASTM(V)))
#define     VQHU_ASYU(M)    QYU_ASTV(QHU_ASYU(VQHU_ASTM(V)))
#define     VQHI_ASYU(M)    QYU_ASTV(QHI_ASYU(VQHI_ASTM(V)))
#define     VQHF_ASYU(M)    QYU_ASTV(QHF_ASYU(VQHF_ASTM(V)))
#define     VQWU_ASYU(M)    QYU_ASTV(QWU_ASYU(VQWU_ASTM(V)))
#define     VQWI_ASYU(M)    QYU_ASTV(QWI_ASYU(VQWI_ASTM(V)))
#define     VQWF_ASYU(M)    QYU_ASTV(QWF_ASYU(VQWF_ASTM(V)))
#define     VQDU_ASYU(M)    QYU_ASTV(QDU_ASYU(VQDU_ASTM(V)))
#define     VQDI_ASYU(M)    QYU_ASTV(QDI_ASYU(VQDI_ASTM(V)))
#define     VQDF_ASYU(M)    QYU_ASTV(QDF_ASYU(VQDF_ASTM(V)))

#if _LEAVE_EXTGOP_X86_ASYU
}
#endif

#if _ENTER_EXTGOP_X86_ASBU
{
#endif

#define     QYU_ASBU(M)     (M)
#define     QBI_ASBU(M)     (M)
#define     QBC_ASBU(M)     (M)
#define     QHU_ASBU(M)     (M)
#define     QHU_ASBU(M)     (M)
#define     QHI_ASBU(M)     (M)
#if defined(SPC_X86_AVX512FP16)
#   define  QHF_ASBU        _mm_castph_si128
#else
#   define  QHF_ASBU(M)     (M)
#endif

#define     QWU_ASBU(M)     (M)
#define     QWI_ASBU(M)     (M)
#define     QWF_ASBU        _mm_castps_si128
#define     QDU_ASBU(M)     (M)
#define     QDI_ASBU(M)     (M)
#define     QDF_ASBU        _mm_castpd_si128

#define     VWYU_ASBU(V)    WBU_ASTV(VWYU_ASTM(V))
#define     VWBI_ASBU(V)    WBU_ASTV(VWBI_ASTM(V))
#define     VWBC_ASBU(V)    WBU_ASTV(VWBC_ASTM(V))
#define     VWHU_ASBU(V)    WBU_ASTV(VWHU_ASTM(V))
#define     VWHI_ASBU(V)    WBU_ASTV(VWHI_ASTM(V))
#define     VWHF_ASBU(V)    WBU_ASTV(VWHF_ASTM(V))
#define     VWWU_ASBU(V)    WBU_ASTV(VWWU_ASTM(V))
#define     VWWI_ASBU(V)    WBU_ASTV(VWWI_ASTM(V))
#define     VWWF_ASBU(V)    WBU_ASTV(VWWF_ASTM(V))

#define     VDYU_ASBU(V)    DBU_ASTV(VDYU_ASTM(V))
#define     VDBI_ASBU(V)    DBU_ASTV(VDBI_ASTM(V))
#define     VDBC_ASBU(V)    DBU_ASTV(VDBC_ASTM(V))
#define     VDHU_ASBU(V)    DBU_ASTV(VDHU_ASTM(V))
#define     VDHI_ASBU(V)    DBU_ASTV(VDHI_ASTM(V))
#define     VDHF_ASBU(V)    DBU_ASTV(VDHF_ASTM(V))
#define     VDWU_ASBU(V)    DBU_ASTV(VDWU_ASTM(V))
#define     VDWI_ASBU(V)    DBU_ASTV(VDWI_ASTM(V))
#define     VDWF_ASBU(V)    DBU_ASTV(VDWF_ASTM(V))
#define     VDDU_ASBU(V)    DBU_ASTV(VDDU_ASTM(V))
#define     VDDI_ASBU(V)    DBU_ASTV(VDDI_ASTM(V))
#define     VDDF_ASBU(V)    DBU_ASTV(VDWF_ASTM(V))

#define     VQYU_ASBU(V)    QBU_ASTV(QYU_ASBU(VQYU_ASTM(V)))
#define     VQBI_ASBU(M)    QBU_ASTV(QBI_ASBU(VQBI_ASTM(V)))
#define     VQBC_ASBU(M)    QBU_ASTV(QBC_ASBU(VQBC_ASTM(V)))
#define     VQHU_ASBU(M)    QBU_ASTV(QHU_ASBU(VQHU_ASTM(V)))
#define     VQHI_ASBU(M)    QBU_ASTV(QHI_ASBU(VQHI_ASTM(V)))
#define     VQHF_ASBU(M)    QBU_ASTV(QHF_ASBU(VQHF_ASTM(V)))
#define     VQWU_ASBU(M)    QBU_ASTV(QWU_ASBU(VQWU_ASTM(V)))
#define     VQWI_ASBU(M)    QBU_ASTV(QWI_ASBU(VQWI_ASTM(V)))
#define     VQWF_ASBU(M)    QBU_ASTV(QWF_ASBU(VQWF_ASTM(V)))
#define     VQDU_ASBU(M)    QBU_ASTV(QDU_ASBU(VQDU_ASTM(V)))
#define     VQDI_ASBU(M)    QBU_ASTV(QDI_ASBU(VQDI_ASTM(V)))
#define     VQDF_ASBU(M)    QBU_ASTV(QDF_ASBU(VQDF_ASTM(V)))

#if _LEAVE_EXTGOP_X86_ASBU
}
#endif

#if _ENTER_EXTGOP_X86_ASBI
{
#endif

#define     QYU_ASBI(M)     (M)
#define     QBU_ASBI(M)     (M)
#define     QBC_ASBI(M)     (M)
#define     QHU_ASBI(M)     (M)
#define     QHU_ASBI(M)     (M)
#define     QHI_ASBI(M)     (M)
#if defined(SPC_X86_AVX512FP16)
#   define  QHF_ASBI        _mm_castph_si128
#else
#   define  QHF_ASBI(M)     (M)
#endif

#define     QWU_ASBI(M)     (M)
#define     QWI_ASBI(M)     (M)
#define     QWF_ASBI        _mm_castps_si128
#define     QDU_ASBI(M)     (M)
#define     QDI_ASBI(M)     (M)
#define     QDF_ASBI        _mm_castpd_si128

#define     VWYU_ASBI(V)    WBI_ASTV(VWYU_ASTM(V))
#define     VWBU_ASBI(V)    WBI_ASTV(VWBU_ASTM(V))
#define     VWBC_ASBI(V)    WBI_ASTV(VWBC_ASTM(V))
#define     VWHU_ASBI(V)    WBI_ASTV(VWHU_ASTM(V))
#define     VWHI_ASBI(V)    WBI_ASTV(VWHI_ASTM(V))
#define     VWHF_ASBI(V)    WBI_ASTV(VWHF_ASTM(V))
#define     VWWU_ASBI(V)    WBI_ASTV(VWWU_ASTM(V))
#define     VWWI_ASBI(V)    WBI_ASTV(VWWI_ASTM(V))
#define     VWWF_ASBI(V)    WBI_ASTV(VWWF_ASTM(V))

#define     VDYU_ASBI(V)    DBI_ASTV(VDYU_ASTM(V))
#define     VDBU_ASBI(V)    DBI_ASTV(VDBU_ASTM(V))
#define     VDBC_ASBI(V)    DBI_ASTV(VDBC_ASTM(V))
#define     VDHU_ASBI(V)    DBI_ASTV(VDHU_ASTM(V))
#define     VDHI_ASBI(V)    DBI_ASTV(VDHI_ASTM(V))
#define     VDHF_ASBI(V)    DBI_ASTV(VDHF_ASTM(V))
#define     VDWU_ASBI(V)    DBI_ASTV(VDWU_ASTM(V))
#define     VDWI_ASBI(V)    DBI_ASTV(VDWI_ASTM(V))
#define     VDWF_ASBI(V)    DBI_ASTV(VDWF_ASTM(V))
#define     VDDU_ASBI(V)    DBI_ASTV(VDDU_ASTM(V))
#define     VDDI_ASBI(V)    DBI_ASTV(VDDI_ASTM(V))
#define     VDDF_ASBI(V)    DBI_ASTV(VDWF_ASTM(V))

#define     VQYU_ASBI(V)    QBI_ASTV(QYU_ASBI(VQYU_ASTM(V)))
#define     VQBU_ASBI(M)    QBI_ASTV(QBU_ASBI(VQBU_ASTM(V)))
#define     VQBC_ASBI(M)    QBI_ASTV(QBC_ASBI(VQBC_ASTM(V)))
#define     VQHU_ASBI(M)    QBI_ASTV(QHU_ASBI(VQHU_ASTM(V)))
#define     VQHI_ASBI(M)    QBI_ASTV(QHI_ASBI(VQHI_ASTM(V)))
#define     VQHF_ASBI(M)    QBI_ASTV(QHF_ASBI(VQHF_ASTM(V)))
#define     VQWU_ASBI(M)    QBI_ASTV(QWU_ASBI(VQWU_ASTM(V)))
#define     VQWI_ASBI(M)    QBI_ASTV(QWI_ASBI(VQWI_ASTM(V)))
#define     VQWF_ASBI(M)    QBI_ASTV(QWF_ASBI(VQWF_ASTM(V)))
#define     VQDU_ASBI(M)    QBI_ASTV(QDU_ASBI(VQDU_ASTM(V)))
#define     VQDI_ASBI(M)    QBI_ASTV(QDI_ASBI(VQDI_ASTM(V)))
#define     VQDF_ASBI(M)    QBI_ASTV(QDF_ASBI(VQDF_ASTM(V)))

#if _LEAVE_EXTGOP_X86_ASBI
}
#endif

#if _ENTER_EXTGOP_X86_ASBC
{
#endif

#define     QYU_ASBC(M)     (M)
#define     QBU_ASBC(M)     (M)
#define     QBI_ASBC(M)     (M)
#define     QHU_ASBC(M)     (M)
#define     QHI_ASBC(M)     (M)
#if defined(SPC_X86_AVX512FP16)
#   define  QHF_ASBC        _mm_castph_si128
#else
#   define  QHI_ASBC(M)     (M)
#endif

#define     QWU_ASBC(M)     (M)
#define     QWI_ASBC(M)     (M)
#define     QWF_ASBC        _mm_castps_si128
#define     QDU_ASBC(M)     (M)
#define     QDI_ASBC(M)     (M)
#define     QDF_ASBC        _mm_castpd_si128

#define     VWYU_ASBC(V)    WBC_ASTV(VWYU_ASTM(V))
#define     VWBU_ASBC(V)    WBC_ASTV(VWBU_ASTM(V))
#define     VWBI_ASBC(V)    WBC_ASTV(VWBI_ASTM(V))

#define     VWHU_ASBC(V)    WBC_ASTV(VWHU_ASTM(V))
#define     VWHI_ASBC(V)    WBC_ASTV(VWHI_ASTM(V))
#define     VWHF_ASBC(V)    WBC_ASTV(VWHF_ASTM(V))
#define     VWWU_ASBC(V)    WBC_ASTV(VWWU_ASTM(V))
#define     VWWI_ASBC(V)    WBC_ASTV(VWWI_ASTM(V))
#define     VWWF_ASBC(V)    WBC_ASTV(VWWF_ASTM(V))

#define     VDYU_ASBC(V)    DBC_ASTV(VDYU_ASTM(V))
#define     VDBU_ASBC(V)    DBC_ASTV(VDBU_ASTM(V))
#define     VDBI_ASBC(V)    DBC_ASTV(VDBI_ASTM(V))

#define     VDHU_ASBC(V)    DBC_ASTV(VDHU_ASTM(V))
#define     VDHI_ASBC(V)    DBC_ASTV(VDHI_ASTM(V))
#define     VDHF_ASBC(V)    DBC_ASTV(VDHF_ASTM(V))
#define     VDWU_ASBC(V)    DBC_ASTV(VDWU_ASTM(V))
#define     VDWI_ASBC(V)    DBC_ASTV(VDWI_ASTM(V))
#define     VDWF_ASBC(V)    DBC_ASTV(VDWF_ASTM(V))
#define     VDDU_ASBC(V)    DBC_ASTV(VDDU_ASTM(V))
#define     VDDI_ASBC(V)    DBC_ASTV(VDDI_ASTM(V))
#define     VDDF_ASBC(V)    DBC_ASTV(VDWF_ASTM(V))

#define     VQYU_ASBC(V)    QBC_ASTV(QYU_ASBC(VQYU_ASTM(V)))
#define     VQBU_ASBC(M)    QBC_ASTV(QBU_ASBC(VQBU_ASTM(V)))
#define     VQBI_ASBC(M)    QBC_ASTV(QBI_ASBC(VQBI_ASTM(V)))

#define     VQHU_ASBC(M)    QBC_ASTV(QHU_ASBC(VQHU_ASTM(V)))
#define     VQHI_ASBC(M)    QBC_ASTV(QHI_ASBC(VQHI_ASTM(V)))
#define     VQHF_ASBC(M)    QBC_ASTV(QHF_ASBC(VQHF_ASTM(V)))
#define     VQWU_ASBC(M)    QBC_ASTV(QWU_ASBC(VQWU_ASTM(V)))
#define     VQWI_ASBC(M)    QBC_ASTV(QWI_ASBC(VQWI_ASTM(V)))
#define     VQWF_ASBC(M)    QBC_ASTV(QWF_ASBC(VQWF_ASTM(V)))
#define     VQDU_ASBC(M)    QBC_ASTV(QDU_ASBC(VQDU_ASTM(V)))
#define     VQDI_ASBC(M)    QBC_ASTV(QDI_ASBC(VQDI_ASTM(V)))
#define     VQDF_ASBC(M)    QBC_ASTV(QDF_ASBC(VQDF_ASTM(V)))

#if _LEAVE_EXTGOP_X86_ASBC
}
#endif

#if _ENTER_EXTGOP_X86_ASHU
{
#endif

#define     QYU_ASHU(M)     (M)
#define     QBU_ASHU(M)     (M)
#define     QBI_ASHU(M)     (M)
#define     QBC_ASHU(M)     (M)
#define     QHI_ASHU(M)     (M)
#if defined(SPC_X86_AVX512FP16)
#   define  QHF_ASHU        _mm_castph_si128
#else
#   define  QHI_ASHU(M)     (M)
#endif

#define     QWU_ASHU(M)     (M)
#define     QWI_ASHU(M)     (M)
#define     QWF_ASHU        _mm_castps_si128
#define     QDU_ASHU(M)     (M)
#define     QDI_ASHU(M)     (M)
#define     QDF_ASHU        _mm_castpd_si128

#define     VWYU_ASHU(V)    WHU_ASTV(VWYU_ASTM(V))
#define     VWBU_ASHU(V)    WHU_ASTV(VWBU_ASTM(V))
#define     VWBI_ASHU(V)    WHU_ASTV(VWBI_ASTM(V))
#define     VWBC_ASHU(V)    WHU_ASTV(VWBC_ASTM(V))

#define     VWHI_ASHU(V)    WHU_ASTV(VWHI_ASTM(V))
#define     VWHF_ASHU(V)    WHU_ASTV(VWHF_ASTM(V))
#define     VWWU_ASHU(V)    WHU_ASTV(VWWU_ASTM(V))
#define     VWWI_ASHU(V)    WHU_ASTV(VWWI_ASTM(V))
#define     VWWF_ASHU(V)    WHU_ASTV(VWWF_ASTM(V))

#define     VDYU_ASHU(V)    DHU_ASTV(VDYU_ASTM(V))
#define     VDBU_ASHU(V)    DHU_ASTV(VDBU_ASTM(V))
#define     VDBI_ASHU(V)    DHU_ASTV(VDBI_ASTM(V))

#define     VDHI_ASHU(V)    DHU_ASTV(VDHI_ASTM(V))
#define     VDHF_ASHU(V)    DHU_ASTV(VDHF_ASTM(V))
#define     VDWU_ASHU(V)    DHU_ASTV(VDWU_ASTM(V))
#define     VDWI_ASHU(V)    DHU_ASTV(VDWI_ASTM(V))
#define     VDWF_ASHU(V)    DHU_ASTV(VDWF_ASTM(V))
#define     VDDU_ASHU(V)    DHU_ASTV(VDDU_ASTM(V))
#define     VDDI_ASHU(V)    DHU_ASTV(VDDI_ASTM(V))
#define     VDDF_ASHU(V)    DHU_ASTV(VDWF_ASTM(V))

#define     VQYU_ASHU(V)    QHU_ASTV(QYU_ASHU(VQYU_ASTM(V)))
#define     VQBU_ASHU(M)    QHU_ASTV(QBU_ASHU(VQBU_ASTM(V)))
#define     VQBI_ASHU(M)    QHU_ASTV(QBI_ASHU(VQBI_ASTM(V)))
#define     VQBC_ASHU(M)    QHU_ASTV(QBC_ASHU(VQBC_ASTM(V)))

#define     VQHI_ASHU(M)    QHU_ASTV(QHI_ASHU(VQHI_ASTM(V)))
#define     VQHF_ASHU(M)    QHU_ASTV(QHF_ASHU(VQHF_ASTM(V)))
#define     VQWU_ASHU(M)    QHU_ASTV(QWU_ASHU(VQWU_ASTM(V)))
#define     VQWI_ASHU(M)    QHU_ASTV(QWI_ASHU(VQWI_ASTM(V)))
#define     VQWF_ASHU(M)    QHU_ASTV(QWF_ASHU(VQWF_ASTM(V)))
#define     VQDU_ASHU(M)    QHU_ASTV(QDU_ASHU(VQDU_ASTM(V)))
#define     VQDI_ASHU(M)    QHU_ASTV(QDI_ASHU(VQDI_ASTM(V)))
#define     VQDF_ASHU(M)    QHU_ASTV(QDF_ASHU(VQDF_ASTM(V)))

#if _LEAVE_EXTGOP_X86_ASHU
}
#endif

#if _ENTER_EXTGOP_X86_ASHI
{
#endif

#define     QYU_ASHI(M)     (M)
#define     QBU_ASHI(M)     (M)
#define     QBI_ASHI(M)     (M)
#define     QBC_ASHI(M)     (M)
#define     QHU_ASHI(M)     (M)

#if defined(SPC_X86_AVX512FP16)
#   define  QHF_ASHI        _mm_castph_si128
#else
#   define  QHF_ASHI(M)     (M)
#endif

#define     QWU_ASHI(M)     (M)
#define     QWI_ASHI(M)     (M)
#define     QWF_ASHI        _mm_castps_si128
#define     QDU_ASHI(M)     (M)
#define     QDI_ASHI(M)     (M)
#define     QDF_ASHI        _mm_castpd_si128

#define     VWYU_ASHI(V)    WHI_ASTV(VWYU_ASTM(V))
#define     VWBU_ASHI(V)    WHI_ASTV(VWBU_ASTM(V))
#define     VWBI_ASHI(V)    WHI_ASTV(VWBI_ASTM(V))
#define     VWBC_ASHI(V)    WHI_ASTV(VWBC_ASTM(V))
#define     VWHU_ASHI(V)    WHI_ASTV(VWHU_ASTM(V))

#define     VWHF_ASHI(V)    WHI_ASTV(VWHF_ASTM(V))
#define     VWWU_ASHI(V)    WHI_ASTV(VWWU_ASTM(V))
#define     VWWI_ASHI(V)    WHI_ASTV(VWWI_ASTM(V))
#define     VWWF_ASHI(V)    WHI_ASTV(VWWF_ASTM(V))

#define     VDYU_ASHI(V)    DHI_ASTV(VDYU_ASTM(V))
#define     VDBU_ASHI(V)    DHI_ASTV(VDBU_ASTM(V))
#define     VDBI_ASHI(V)    DHI_ASTV(VDBI_ASTM(V))
#define     VDBC_ASHI(V)    DHI_ASTV(VDBC_ASTM(V))
#define     VDHU_ASHI(V)    DHI_ASTV(VDHU_ASTM(V))

#define     VDHF_ASHI(V)    DHI_ASTV(VDHF_ASTM(V))
#define     VDWU_ASHI(V)    DHI_ASTV(VDWU_ASTM(V))
#define     VDWI_ASHI(V)    DHI_ASTV(VDWI_ASTM(V))
#define     VDWF_ASHI(V)    DHI_ASTV(VDWF_ASTM(V))
#define     VDDU_ASHI(V)    DHI_ASTV(VDDU_ASTM(V))
#define     VDDI_ASHI(V)    DHI_ASTV(VDDI_ASTM(V))
#define     VDDF_ASHI(V)    DHI_ASTV(VDWF_ASTM(V))

#define     VQYU_ASHI(V)    QHI_ASTV(QYU_ASHI(VQYU_ASTM(V)))
#define     VQBU_ASHI(M)    QHI_ASTV(QBU_ASHI(VQBU_ASTM(V)))
#define     VQBI_ASHI(M)    QHI_ASTV(QBI_ASHI(VQBI_ASTM(V)))
#define     VQBC_ASHI(M)    QHI_ASTV(QBC_ASHI(VQBC_ASTM(V)))
#define     VQHU_ASHI(M)    QHI_ASTV(QHU_ASHI(VQHU_ASTM(V)))

#define     VQHF_ASHI(M)    QHI_ASTV(QHF_ASHI(VQHF_ASTM(V)))
#define     VQWU_ASHI(M)    QHI_ASTV(QWU_ASHI(VQWU_ASTM(V)))
#define     VQWI_ASHI(M)    QHI_ASTV(QWI_ASHI(VQWI_ASTM(V)))
#define     VQWF_ASHI(M)    QHI_ASTV(QWF_ASHI(VQWF_ASTM(V)))
#define     VQDU_ASHI(M)    QHI_ASTV(QDU_ASHI(VQDU_ASTM(V)))
#define     VQDI_ASHI(M)    QHI_ASTV(QDI_ASHI(VQDI_ASTM(V)))
#define     VQDF_ASHI(M)    QHI_ASTV(QDF_ASHI(VQDF_ASTM(V)))

#if _LEAVE_EXTGOP_X86_ASHI
}
#endif

#if _ENTER_EXTGOP_X86_ASHF
{
#endif

#if defined(SPC_X86_AVX512FP16)
#   define  QYU_ASHF        _mm_castsi128_ph
#   define  QBU_ASHF        _mm_castsi128_ph
#   define  QBI_ASHF        _mm_castsi128_ph
#   define  QBC_ASHF        _mm_castsi128_ph
#   define  QHU_ASHF        _mm_castsi128_ph
#   define  QHI_ASHF        _mm_castsi128_ph
#   define  QWU_ASHF        _mm_castsi128_ph
#   define  QWI_ASHF        _mm_castsi128_ph
#   define  QWF_ASHF        _mm_castps_ph
#   define  QDU_ASHF        _mm_castsi128_ph
#   define  QDI_ASHF        _mm_castsi128_ph
#   define  QDF_ASHF        _mm_castpd_ph
#else
#   define  QBU_ASHF(M)     (M)
#   define  QBI_ASHF(M)     (M)
#   define  QBC_ASHF(M)     (M)
#   define  QHU_ASHF(M)     (M)
#   define  QHI_ASHF(M)     (M)
#   define  QWU_ASHF(M)     (M)
#   define  QWI_ASHF(M)     (M)
#   define  QWF_ASHF        _mm_castps_si128
#   define  QDU_ASHF(M)     (M)
#   define  QDI_ASHF(M)     (M)
#   define  QDF_ASHF        _mm_castpd_si128
#endif

#define     VWYU_ASHF(V)    WHF_ASTV(VWYU_ASTM(V))
#define     VWBU_ASHF(V)    WHF_ASTV(VWBU_ASTM(V))
#define     VWBI_ASHF(V)    WHF_ASTV(VWBI_ASTM(V))
#define     VWBC_ASHF(V)    WHF_ASTV(VWBC_ASTM(V))
#define     VWHU_ASHF(V)    WHF_ASTV(VWHU_ASTM(V))
#define     VWHI_ASHF(V)    WHF_ASTV(VWHI_ASTM(V))

#define     VWWU_ASHF(V)    WHF_ASTV(VWWU_ASTM(V))
#define     VWWI_ASHF(V)    WHF_ASTV(VWWI_ASTM(V))
#define     VWWF_ASHF(V)    WHF_ASTV(VWWF_ASTM(V))

#define     VDYU_ASHF(V)    DHF_ASTV(VDYU_ASTM(V))
#define     VDBU_ASHF(V)    DHF_ASTV(VDBU_ASTM(V))
#define     VDBI_ASHF(V)    DHF_ASTV(VDBI_ASTM(V))
#define     VDBC_ASHF(V)    DHF_ASTV(VDBC_ASTM(V))
#define     VDHU_ASHF(V)    DHF_ASTV(VDHU_ASTM(V))
#define     VDHI_ASHF(V)    DHF_ASTV(VDHI_ASTM(V))

#define     VDWU_ASHF(V)    DHF_ASTV(VDWU_ASTM(V))
#define     VDWI_ASHF(V)    DHF_ASTV(VDWI_ASTM(V))
#define     VDWF_ASHF(V)    DHF_ASTV(VDWF_ASTM(V))
#define     VDDU_ASHF(V)    DHF_ASTV(VDDU_ASTM(V))
#define     VDDI_ASHF(V)    DHF_ASTV(VDDI_ASTM(V))
#define     VDDF_ASHF(V)    DHF_ASTV(VDWF_ASTM(V))

#define     VQYU_ASHF(V)    QHF_ASTV(QYU_ASHF(VQYU_ASTM(V)))
#define     VQBU_ASHF(M)    QHF_ASTV(QBU_ASHF(VQBU_ASTM(V)))
#define     VQBI_ASHF(M)    QHF_ASTV(QBI_ASHF(VQBI_ASTM(V)))
#define     VQBC_ASHF(M)    QHF_ASTV(QBC_ASHF(VQBC_ASTM(V)))
#define     VQHU_ASHF(M)    QHF_ASTV(QHU_ASHF(VQHU_ASTM(V)))
#define     VQHI_ASHF(M)    QHF_ASTV(QHI_ASHF(VQHI_ASTM(V)))

#define     VQWU_ASHF(M)    QHF_ASTV(QWU_ASHF(VQWU_ASTM(V)))
#define     VQWI_ASHF(M)    QHF_ASTV(QWI_ASHF(VQWI_ASTM(V)))
#define     VQWF_ASHF(M)    QHF_ASTV(QWF_ASHF(VQWF_ASTM(V)))
#define     VQDU_ASHF(M)    QHF_ASTV(QDU_ASHF(VQDU_ASTM(V)))
#define     VQDI_ASHF(M)    QHF_ASTV(QDI_ASHF(VQDI_ASTM(V)))
#define     VQDF_ASHF(M)    QHF_ASTV(QDF_ASHF(VQDF_ASTM(V)))

#if _LEAVE_EXTGOP_X86_ASHF
}
#endif

#if _ENTER_EXTGOP_X86_ASWU
{
#endif

#define     QYU_ASWU(M)     (M)
#define     QBU_ASWU(M)     (M)
#define     QBI_ASWU(M)     (M)
#define     QBC_ASWU(M)     (M)
#define     QHU_ASWU(M)     (M)
#define     QHI_ASWU(M)     (M)

#if defined(SPC_X86_AVX512FP16)
#   define  QHF_ASWU        _mm_castph_si128
#else
#   define  QHF_ASWU(M)     (M)
#endif

#define     QWI_ASWU(M)     (M)
#define     QWF_ASWU        _mm_castps_si128
#define     QDU_ASWU(M)     (M)
#define     QDI_ASWU(M)     (M)
#define     QDF_ASWU        _mm_castpd_si128

#define     VWYU_ASWU(V)    WWU_ASTV(VWYU_ASTM(V))
#define     VWBU_ASWU(V)    WWU_ASTV(VWBU_ASTM(V))
#define     VWBI_ASWU(V)    WWU_ASTV(VWBI_ASTM(V))
#define     VWBC_ASWU(V)    WWU_ASTV(VWBC_ASTM(V))
#define     VWHU_ASWU(V)    WWU_ASTV(VWHU_ASTM(V))
#define     VWHI_ASWU(V)    WWU_ASTV(VWHI_ASTM(V))
#define     VWHF_ASWU(V)    WWU_ASTV(VWHF_ASTM(V))

#define     VWWI_ASWU(V)    WWU_ASTV(VWWI_ASTM(V))
#define     VWWF_ASWU(V)    WWU_ASTV(VWWF_ASTM(V))

#define     VDYU_ASWU(V)    DWU_ASTV(VDYU_ASTM(V))
#define     VDBU_ASWU(V)    DWU_ASTV(VDBU_ASTM(V))
#define     VDBI_ASWU(V)    DWU_ASTV(VDBI_ASTM(V))
#define     VDBC_ASWU(V)    DWU_ASTV(VDBC_ASTM(V))
#define     VDHU_ASWU(V)    DWU_ASTV(VDHU_ASTM(V))
#define     VDHI_ASWU(V)    DWU_ASTV(VDHI_ASTM(V))
#define     VDHF_ASWU(V)    DWU_ASTV(VDHF_ASTM(V))

#define     VDWI_ASWU(V)    DWU_ASTV(VDWI_ASTM(V))
#define     VDWF_ASWU(V)    DWU_ASTV(VDWF_ASTM(V))
#define     VDDU_ASWU(V)    DWU_ASTV(VDDU_ASTM(V))
#define     VDDI_ASWU(V)    DWU_ASTV(VDDI_ASTM(V))
#define     VDDF_ASWU(V)    DWU_ASTV(VDWF_ASTM(V))

#define     VQYU_ASWU(V)    QWU_ASTV(QYU_ASWU(VQYU_ASTM(V)))
#define     VQBU_ASWU(M)    QWU_ASTV(QBU_ASWU(VQBU_ASTM(V)))
#define     VQBI_ASWU(M)    QWU_ASTV(QBI_ASWU(VQBI_ASTM(V)))
#define     VQBC_ASWU(M)    QWU_ASTV(QBC_ASWU(VQBC_ASTM(V)))
#define     VQHU_ASWU(M)    QWU_ASTV(QHU_ASWU(VQHU_ASTM(V)))
#define     VQHI_ASWU(M)    QWU_ASTV(QHI_ASWU(VQHI_ASTM(V)))
#define     VQHF_ASWU(M)    QWU_ASTV(QHF_ASWU(VQHF_ASTM(V)))

#define     VQWI_ASWU(M)    QWU_ASTV(QWI_ASWU(VQWI_ASTM(V)))
#define     VQWF_ASWU(M)    QWU_ASTV(QWF_ASWU(VQWF_ASTM(V)))
#define     VQDU_ASWU(M)    QWU_ASTV(QDU_ASWU(VQDU_ASTM(V)))
#define     VQDI_ASWU(M)    QWU_ASTV(QDI_ASWU(VQDI_ASTM(V)))
#define     VQDF_ASWU(M)    QWU_ASTV(QDF_ASWU(VQDF_ASTM(V)))

#if _LEAVE_EXTGOP_X86_ASWU
}
#endif

#if _ENTER_EXTGOP_X86_ASWI
{
#endif

#define     QYU_ASWI(M)     (M)
#define     QBU_ASWI(M)     (M)
#define     QBI_ASWI(M)     (M)
#define     QBC_ASWI(M)     (M)
#define     QHU_ASWI(M)     (M)
#define     QHI_ASWI(M)     (M)

#if defined(SPC_X86_AVX512FP16)
#   define  QHF_ASWI        _mm_castph_si128
#else
#   define  QHF_ASWI(M)     (M)
#endif

#define     QWI_ASWI(M)     (M)
#define     QWF_ASWI        _mm_castps_si128
#define     QDU_ASWI(M)     (M)
#define     QDI_ASWI(M)     (M)
#define     QDF_ASWI        _mm_castpd_si128

#define     VWYU_ASWI(V)    WWI_ASTV(VWYU_ASTM(V))
#define     VWBU_ASWI(V)    WWI_ASTV(VWBU_ASTM(V))
#define     VWBI_ASWI(V)    WWI_ASTV(VWBI_ASTM(V))
#define     VWBC_ASWI(V)    WWI_ASTV(VWBC_ASTM(V))
#define     VWHU_ASWI(V)    WWI_ASTV(VWHU_ASTM(V))
#define     VWHI_ASWI(V)    WWI_ASTV(VWHI_ASTM(V))
#define     VWHF_ASWI(V)    WWI_ASTV(VWHF_ASTM(V))
#define     VWWU_ASWI(V)    WWI_ASTV(VWWU_ASTM(V))

#define     VWWF_ASWI(V)    WWI_ASTV(VWWF_ASTM(V))

#define     VDYU_ASWI(V)    DWI_ASTV(VDYU_ASTM(V))
#define     VDBU_ASWI(V)    DWI_ASTV(VDBU_ASTM(V))
#define     VDBI_ASWI(V)    DWI_ASTV(VDBI_ASTM(V))
#define     VDBC_ASWI(V)    DWI_ASTV(VDBC_ASTM(V))
#define     VDHU_ASWI(V)    DWI_ASTV(VDHU_ASTM(V))
#define     VDHI_ASWI(V)    DWI_ASTV(VDHI_ASTM(V))
#define     VDHF_ASWI(V)    DWI_ASTV(VDHF_ASTM(V))
#define     VDWU_ASWI(V)    DWI_ASTV(VDWU_ASTM(V))

#define     VDWF_ASWI(V)    DWI_ASTV(VDWF_ASTM(V))
#define     VDDU_ASWI(V)    DWI_ASTV(VDDU_ASTM(V))
#define     VDDI_ASWI(V)    DWI_ASTV(VDDI_ASTM(V))
#define     VDDF_ASWI(V)    DWI_ASTV(VDWF_ASTM(V))

#define     VQYU_ASWI(V)    QWI_ASTV(QYU_ASWI(VQYU_ASTM(V)))
#define     VQBU_ASWI(M)    QWI_ASTV(QBU_ASWI(VQBU_ASTM(V)))
#define     VQBI_ASWI(M)    QWI_ASTV(QBI_ASWI(VQBI_ASTM(V)))
#define     VQBC_ASWI(M)    QWI_ASTV(QBC_ASWI(VQBC_ASTM(V)))
#define     VQHU_ASWI(M)    QWI_ASTV(QHU_ASWI(VQHU_ASTM(V)))
#define     VQHI_ASWI(M)    QWI_ASTV(QHI_ASWI(VQHI_ASTM(V)))
#define     VQHF_ASWI(M)    QWI_ASTV(QHF_ASWI(VQHF_ASTM(V)))
#define     VQWU_ASWI(M)    QWI_ASTV(QWI_ASWU(VQWU_ASTM(V)))

#define     VQWF_ASWI(M)    QWI_ASTV(QWF_ASWI(VQWF_ASTM(V)))
#define     VQDU_ASWI(M)    QWI_ASTV(QDU_ASWI(VQDU_ASTM(V)))
#define     VQDI_ASWI(M)    QWI_ASTV(QDI_ASWI(VQDI_ASTM(V)))
#define     VQDF_ASWI(M)    QWI_ASTV(QDF_ASWI(VQDF_ASTM(V)))

#if _LEAVE_EXTGOP_X86_ASWI
}
#endif

#if _ENTER_EXTGOP_X86_ASWF
{
#endif

#define     QYU_ASWF        _mm_castsi128_ps
#define     QBU_ASWF        _mm_castsi128_ps
#define     QBI_ASWF        _mm_castsi128_ps
#define     QBC_ASWF        _mm_castsi128_ps
#define     QHU_ASWF        _mm_castsi128_ps
#define     QHI_ASWF        _mm_castsi128_ps
#if defined(SPC_X86_AVX512FP16)
#   define  QHF_ASWF        _mm_castph_ps
#else
#   define  QHF_ASWF        _mm_castsi128_ps
#endif

#define     QWU_ASWF        _mm_castsi128_ps
#define     QWI_ASWF        _mm_castsi128_ps

#define     QDU_ASWF        _mm_castsi128_ps
#define     QDI_ASWF        _mm_castsi128_ps
#define     QDF_ASWF        _mm_castpd_ps

#define     VWYU_ASWF(V)    WWF_ASTV(VWYU_ASTM(V))
#define     VWBU_ASWF(V)    WWF_ASTV(VWBU_ASTM(V))
#define     VWBI_ASWF(V)    WWF_ASTV(VWBI_ASTM(V))
#define     VWBC_ASWF(V)    WWF_ASTV(VWBC_ASTM(V))
#define     VWHU_ASWF(V)    WWF_ASTV(VWHU_ASTM(V))
#define     VWHI_ASWF(V)    WWF_ASTV(VWHI_ASTM(V))

#define     VWWU_ASWF(V)    WWF_ASTV(VWWU_ASTM(V))
#define     VWWI_ASWF(V)    WWF_ASTV(VWWI_ASTM(V))
#define     VWWF_ASWF(V)    WWF_ASTV(VWWF_ASTM(V))


#define     VDYU_ASWF(V)    DWF_ASTV(VDYU_ASTM(V))
#define     VDBU_ASWF(V)    DWF_ASTV(VDBU_ASTM(V))
#define     VDBI_ASWF(V)    DWF_ASTV(VDBI_ASTM(V))
#define     VDBC_ASWF(V)    DWF_ASTV(VDBC_ASTM(V))
#define     VDHU_ASWF(V)    DWF_ASTV(VDHU_ASTM(V))
#define     VDHI_ASWF(V)    DWF_ASTV(VDHI_ASTM(V))
#define     VDHF_ASWF(V)    DWF_ASTV(VDHF_ASTM(V))
#define     VDWU_ASWF(V)    DWF_ASTV(VDWU_ASTM(V))
#define     VDWI_ASWF(V)    DWF_ASTV(VDWI_ASTM(V))

#define     VDDU_ASWF(V)    DWF_ASTV(VDDU_ASTM(V))
#define     VDDI_ASWF(V)    DWF_ASTV(VDDI_ASTM(V))
#define     VDDF_ASWF(V)    DWF_ASTV(VDDF_ASTM(V))


#define     VQYU_ASWF(V)    QWF_ASTV(QYU_ASWF(VQYU_ASTM(V)))
#define     VQBU_ASWF(M)    QWF_ASTV(QBU_ASWF(VQBU_ASTM(V)))
#define     VQBI_ASWF(M)    QWF_ASTV(QBI_ASWF(VQBI_ASTM(V)))
#define     VQBC_ASWF(M)    QWF_ASTV(QBC_ASWF(VQBC_ASTM(V)))
#define     VQHU_ASWF(M)    QWF_ASTV(QHU_ASWF(VQHU_ASTM(V)))
#define     VQHI_ASWF(M)    QWF_ASTV(QHI_ASWF(VQHI_ASTM(V)))
#define     VQHF_ASWF(M)    QWF_ASTV(QWF_ASWF(VQHF_ASTM(V)))
#define     VQWU_ASWF(M)    QWF_ASTV(QWU_ASWF(VQWU_ASTM(V)))
#define     VQWI_ASWF(M)    QWF_ASTV(QWI_ASWF(VQWI_ASTM(V)))

#define     VQDU_ASWF(M)    QWF_ASTV(QDU_ASWF(VQDU_ASTM(V)))
#define     VQDI_ASWF(M)    QWF_ASTV(QDI_ASWF(VQDI_ASTM(V)))
#define     VQDF_ASWF(M)    QWF_ASTV(QDF_ASWF(VQDF_ASTM(V)))

#if _LEAVE_EXTGOP_X86_ASWF
}
#endif

#if _ENTER_EXTGOP_X86_ASDU
{
#endif

#define     QYU_ASDU(M)     (M)
#define     QBU_ASDU(M)     (M)
#define     QBI_ASDU(M)     (M)
#define     QBC_ASDU(M)     (M)
#define     QHU_ASDU(M)     (M)
#define     QHI_ASDU(M)     (M)

#if defined(SPC_X86_AVX512FP16)
#   define  QHF_ASDU        _mm_castph_si128
#else
#   define  QHF_ASDU(M)     (M)
#endif

#define     QDI_ASDU(M)     (M)
#define     QWF_ASDU        _mm_castps_si128
#define     QDU_ASDU(M)     (M)
#define     QDI_ASDU(M)     (M)
#define     QDF_ASDU        _mm_castpd_si128

#define     VDYU_ASDU(V)    DDU_ASTV(VDYU_ASTM(V))
#define     VDBU_ASDU(V)    DDU_ASTV(VDBU_ASTM(V))
#define     VDBI_ASDU(V)    DDU_ASTV(VDBI_ASTM(V))
#define     VDBC_ASDU(V)    DDU_ASTV(VDBC_ASTM(V))
#define     VDHU_ASDU(V)    DDU_ASTV(VDHU_ASTM(V))
#define     VDHI_ASDU(V)    DDU_ASTV(VDHI_ASTM(V))
#define     VDHF_ASDU(V)    DDU_ASTV(VDHF_ASTM(V))
#define     VDWU_ASDU(V)    DDU_ASTV(VDWU_ASTM(V))
#define     VDWI_ASDU(V)    DDU_ASTV(VDWI_ASTM(V))
#define     VDWF_ASDU(V)    DDU_ASTV(VDWF_ASTM(V))

#define     VDDI_ASDU(V)    DDU_ASTV(VDDI_ASTM(V))
#define     VDDF_ASDU(V)    DDU_ASTV(VDDF_ASTM(V))

#define     VQYU_ASDU(V)    QDU_ASTV(QYU_ASDU(VQYU_ASTM(V)))
#define     VQBU_ASDU(M)    QDU_ASTV(QBU_ASDU(VQBU_ASTM(V)))
#define     VQBI_ASDU(M)    QDU_ASTV(QBI_ASDU(VQBI_ASTM(V)))
#define     VQBC_ASDU(M)    QDU_ASTV(QBC_ASDU(VQBC_ASTM(V)))
#define     VQHU_ASDU(M)    QDU_ASTV(QHU_ASDU(VQHU_ASTM(V)))
#define     VQHI_ASDU(M)    QDU_ASTV(QHI_ASDU(VQHI_ASTM(V)))
#define     VQHF_ASDU(M)    QDU_ASTV(QHF_ASDU(VQHF_ASTM(V)))
#define     VQWU_ASDU(M)    QDU_ASTV(QWU_ASDU(VQWU_ASTM(V)))
#define     VQWI_ASDU(M)    QDU_ASTV(QWI_ASDU(VQWI_ASTM(V)))
#define     VQWF_ASDU(M)    QDU_ASTV(QWF_ASDU(VQWF_ASTM(V)))

#define     VQDI_ASDU(M)    QDU_ASTV(QDI_ASDU(VQDI_ASTM(V)))
#define     VQDF_ASDU(M)    QDU_ASTV(QDF_ASDU(VQDF_ASTM(V)))

#if _LEAVE_EXTGOP_X86_ASDU
}
#endif

#if _ENTER_EXTGOP_X86_ASDI
{
#endif

#define     QYU_ASDI(M)     (M)
#define     QBU_ASDI(M)     (M)
#define     QBI_ASDI(M)     (M)
#define     QBC_ASDI(M)     (M)
#define     QHU_ASDI(M)     (M)
#define     QHI_ASDI(M)     (M)

#if defined(SPC_X86_AVX512FP16)
#   define  QHF_ASDI        _mm_castph_si128
#else
#   define  QHF_ASDI(M)     (M)
#endif

#define     QDI_ASDI(M)     (M)
#define     QWF_ASDI        _mm_castps_si128
#define     QDU_ASDI(M)     (M)
#define     QDI_ASDI(M)     (M)
#define     QDF_ASDI        _mm_castpd_si128

#define     VDYU_ASDI(V)    DDI_ASTV(VDYU_ASTM(V))
#define     VDBU_ASDI(V)    DDI_ASTV(VDBU_ASTM(V))
#define     VDBI_ASDI(V)    DDI_ASTV(VDBI_ASTM(V))
#define     VDBC_ASDI(V)    DDI_ASTV(VDBC_ASTM(V))
#define     VDHU_ASDI(V)    DDI_ASTV(VDHU_ASTM(V))
#define     VDHI_ASDI(V)    DDI_ASTV(VDHI_ASTM(V))
#define     VDHF_ASDI(V)    DDI_ASTV(VDHF_ASTM(V))
#define     VDWU_ASDI(V)    DDI_ASTV(VDWU_ASTM(V))
#define     VDWI_ASDI(V)    DDI_ASTV(VDWI_ASTM(V))
#define     VDWF_ASDI(V)    DDI_ASTV(VDWF_ASTM(V))
#define     VDDU_ASDI(V)    DDI_ASTV(VDDU_ASTM(V))

#define     VDDF_ASDI(V)    DDI_ASTV(VDDF_ASTM(V))

#define     VQYU_ASDI(V)    QDI_ASTV(QYU_ASDI(VQYU_ASTM(V)))
#define     VQBU_ASDI(M)    QDI_ASTV(QBU_ASDI(VQBU_ASTM(V)))
#define     VQBI_ASDI(M)    QDI_ASTV(QBI_ASDI(VQBI_ASTM(V)))
#define     VQBC_ASDI(M)    QDI_ASTV(QBC_ASDI(VQBC_ASTM(V)))
#define     VQHU_ASDI(M)    QDI_ASTV(QHU_ASDI(VQHU_ASTM(V)))
#define     VQHI_ASDI(M)    QDI_ASTV(QHI_ASDI(VQHI_ASTM(V)))
#define     VQHF_ASDI(M)    QDI_ASTV(QHF_ASDI(VQHF_ASTM(V)))
#define     VQWU_ASDI(M)    QDI_ASTV(QWU_ASDI(VQWU_ASTM(V)))
#define     VQWI_ASDI(M)    QDI_ASTV(QWI_ASDI(VQWI_ASTM(V)))
#define     VQWF_ASDI(M)    QDI_ASTV(QWF_ASDI(VQWF_ASTM(V)))
#define     VQDU_ASDI(M)    QDI_ASTV(QDU_ASDI(VQDU_ASTM(V)))

#define     VQDF_ASDI(M)    QDI_ASTV(QDF_ASDI(VQDF_ASTM(V)))

#if _LEAVE_EXTGOP_X86_ASDI
}
#endif

#if _ENTER_EXTGOP_X86_ASDF
{
#endif

#define     QYU_ASDF        _mm_castsi128_pd
#define     QBU_ASDF        _mm_castsi128_pd
#define     QBI_ASDF        _mm_castsi128_pd
#define     QBC_ASDF        _mm_castsi128_pd
#define     QHU_ASDF        _mm_castsi128_pd
#define     QHI_ASDF        _mm_castsi128_pd
#if defined(SPC_X86_AVX512FP16)
#   define  QHF_ASDF        _mm_castph_pd
#else
#   define  QHF_ASDF        _mm_castsi128_pd
#endif

#define     QWU_ASDF        _mm_castsi128_pd
#define     QWI_ASDF        _mm_castsi128_pd
#define     QWF_ASDF        _mm_castps_pd
#define     QDU_ASDF        _mm_castsi128_pd
#define     QDI_ASDF        _mm_castsi128_pd


#define     VDYU_ASDF(V)    DDF_ASTV(VDYU_ASTM(V))
#define     VDBU_ASDF(V)    DDF_ASTV(VDBU_ASTM(V))
#define     VDBI_ASDF(V)    DDF_ASTV(VDBI_ASTM(V))
#define     VDBC_ASDF(V)    DDF_ASTV(VDBC_ASTM(V))
#define     VDHU_ASDF(V)    DDF_ASTV(VDHU_ASTM(V))
#define     VDHI_ASDF(V)    DDF_ASTV(VDHI_ASTM(V))
#define     VDHF_ASDF(V)    DDF_ASTV(VDHF_ASTM(V))
#define     VDWU_ASDF(V)    DDF_ASTV(VDWU_ASTM(V))
#define     VDWI_ASDF(V)    DDF_ASTV(VDWI_ASTM(V))
#define     VDWF_ASDF(V)    DDF_ASTV(VDWF_ASTM(V))
#define     VDDU_ASDF(V)    DDF_ASTV(VDDU_ASTM(V))
#define     VDDI_ASDF(V)    DDF_ASTV(VDDI_ASTM(V))


#define     VQYU_ASDF(V)    QDF_ASTV(QYU_ASDF(VQYU_ASTM(V)))
#define     VQBU_ASDF(M)    QDF_ASTV(QBU_ASDF(VQBU_ASTM(V)))
#define     VQBI_ASDF(M)    QDF_ASTV(QBI_ASDF(VQBI_ASTM(V)))
#define     VQBC_ASDF(M)    QDF_ASTV(QBC_ASDF(VQBC_ASTM(V)))
#define     VQHU_ASDF(M)    QDF_ASTV(QHU_ASDF(VQHU_ASTM(V)))
#define     VQHI_ASDF(M)    QDF_ASTV(QHI_ASDF(VQHI_ASTM(V)))
#define     VQHF_ASDF(M)    QDF_ASTV(QHF_ASDF(VQHF_ASTM(V)))
#define     VQWU_ASDF(M)    QDF_ASTV(QWU_ASDF(VQWU_ASTM(V)))
#define     VQWI_ASDF(M)    QDF_ASTV(QWI_ASDF(VQWI_ASTM(V)))
#define     VQWF_ASDF(M)    QDF_ASTV(QWF_ASDF(VQWF_ASTM(V)))
#define     VQDU_ASDF(M)    QDF_ASTV(QDU_ASDF(VQDU_ASTM(V)))
#define     VQDI_ASDF(M)    QDF_ASTV(QDI_ASDF(VQDI_ASTM(V)))


#if _LEAVE_EXTGOP_X86_ASDF
}
#endif

#if _ENTER_EXTGOP_X86_ASTU
{
#endif

#define     QBI_ASTU        QBI_ASBU
#define     QHI_ASTU        QHI_ASHU
#define     QHF_ASTU        QHF_ASHU
#define     QWI_ASTU        QWI_ASWU
#define     QWF_ASTU        QWF_ASWU
#define     QDI_ASTU        QDI_ASDU
#define     QDF_ASTU        QDF_ASDU

#define     VWBI_ASTU       VWBI_ASBU
#define     VWHI_ASTU       VWHI_ASHU
#define     VWHF_ASTU       VWHF_ASHU
#define     VWWI_ASTU       VWWI_ASWU
#define     VWWF_ASTU       VWWF_ASWU

#define     VDBI_ASTU       VDBU_ASBU
#define     VDHI_ASTU       VDHI_ASHU

#define     VQBI_ASTU       VQBI_ASBU
#define     VQHI_ASTU       VQHI_ASHU
#define     VQHF_ASTU       VQHF_ASHU
#define     VQWI_ASTU       VQWI_ASWU
#define     VQWF_ASTU       VQWF_ASWU
#define     VQDI_ASTU       VQDI_ASDU
#define     VQDF_ASTU       VQDF_ASDU

#if _LEAVE_EXTGOP_X86_ASTU
}
#endif

#if _ENTER_EXTGOP_X86_ASTI
{
#endif

#define     DBU_ASTI        DBU_ASBI
#define     DHU_ASTI        DHU_ASHI
#define     DHF_ASTI        DHF_ASHI
#define     DWU_ASTI        DWU_ASWI
#define     DWF_ASTI        DWF_ASWI
#define     DDU_ASTI        DDU_ASDI
#define     DDF_ASTI        DDF_ASDI

#define     QBU_ASTI        QBU_ASBI
#define     QHU_ASTI        QHU_ASHI
#define     QHF_ASTI        QHF_ASHI
#define     QWU_ASTI        QWU_ASWI
#define     QWF_ASTI        QWF_ASWI
#define     QDU_ASTI        QDU_ASDI
#define     QDF_ASTI        QDF_ASDI

#define     VWBU_ASTI       VWBU_ASBI
#define     VWHU_ASTI       VWHU_ASHI
#define     VWHF_ASTI       VWHF_ASHI
#define     VWWU_ASTI       VWWU_ASWI
#define     VWWF_ASTI       VWWF_ASWI

#define     VDBU_ASTI       VDBU_ASBI
#define     VDHU_ASTI       VDHU_ASHI
#define     VDHF_ASTI       VDHF_ASHI
#define     VDWU_ASTI       VDWU_ASWI
#define     VDWF_ASTI       VDWF_ASWI
#define     VDDU_ASTI       VDDU_ASDI
#define     VDDF_ASTI       VDDF_ASDI

#define     VQBU_ASTI       VQBU_ASBI
#define     VQHU_ASTI       VQHU_ASHI
#define     VQHF_ASTI       VQHF_ASHI
#define     VQWU_ASTI       VQWU_ASWI
#define     VQWF_ASTI       VQWF_ASWI
#define     VQDU_ASTI       VQDU_ASDI
#define     VQDF_ASTI       VQDF_ASDI

#if _LEAVE_EXTGOP_X86_ASTI
}
#endif

#if _ENTER_EXTGOP_X86_ASTF
{
#endif

#define     DHU_ASTF        DHU_ASHF
#define     DHI_ASTF        DHI_ASHF
#define     DWU_ASTF        DWU_ASWF
#define     DWI_ASTF        DWI_ASWF
#define     DDU_ASTF        DDU_ASDF
#define     DDI_ASTF        DDI_ASDF

#define     QHU_ASTF        QHU_ASHF
#define     QHI_ASTF        QHI_ASHF
#define     QWU_ASTF        QWU_ASWF
#define     QWI_ASTF        QWI_ASWF
#define     QDU_ASTF        QDU_ASDF
#define     QDI_ASTF        QDI_ASDF

#define     VWHU_ASTF       VWHU_ASHF
#define     VWHI_ASTF       VWHI_ASHF
#define     VWWU_ASTF       VWWU_ASWF
#define     VWWI_ASTF       VWWI_ASWF

#define     VDHU_ASTF       VDHU_ASHF
#define     VDHI_ASTF       VDHI_ASHF
#define     VDWU_ASTF       VDWU_ASWF
#define     VDWI_ASTF       VDWI_ASWF
#define     VDDU_ASTF       VDDU_ASDF
#define     VDDI_ASTF       VDDI_ASDF

#define     VQHU_ASTF       VQHU_ASHF
#define     VQHI_ASTF       VQHI_ASHF
#define     VQWU_ASTF       VQWU_ASWF
#define     VQWI_ASTF       VQWI_ASWF
#define     VQDU_ASTF       VQDU_ASDF
#define     VQDI_ASTF       VQDI_ASDF

#if _LEAVE_EXTGOP_X86_ASTF
}
#endif

#if _ENTER_EXTGOP_X86_CV__
{
#endif

#if _ENTER_EXTGOP_X86_CVB_
{
#endif

#if _ENTER_EXTGOP_X86_CVBU
{
#endif
#if _LEAVE_EXTGOP_X86_CVBU
}
#endif

#if _ENTER_EXTGOP_X86_CVBI
{
#endif
#if _LEAVE_EXTGOP_X86_CVBI
}
#endif

#if _ENTER_EXTGOP_X86_CVBZ
{
#endif
#if _LEAVE_EXTGOP_X86_CVBZ
}
#endif

#if _ENTER_EXTGOP_X86_CVBS
{
#endif
#if _LEAVE_EXTGOP_X86_CVBS
}
#endif

#if _LEAVE_EXTGOP_X86_CVB_
}
#endif

#if _ENTER_EXTGOP_X86_CVH_
{
#endif

#if _ENTER_EXTGOP_X86_CVHU
{
#endif
#if _LEAVE_EXTGOP_X86_CVHU
}
#endif

#if _ENTER_EXTGOP_X86_CVHI
{
#endif
#if _LEAVE_EXTGOP_X86_CVHI
}
#endif

#if _ENTER_EXTGOP_X86_CVHZ
{
#endif
#if _LEAVE_EXTGOP_X86_CVHZ
}
#endif

#if _ENTER_EXTGOP_X86_CVHS
{
#endif
#if _LEAVE_EXTGOP_X86_CVHS
}
#endif

#if _LEAVE_EXTGOP_X86_CVH_
}
#endif

#if _ENTER_EXTGOP_X86_CVW_
{
#endif

#if _ENTER_EXTGOP_X86_CVWU
{
#endif
#if _LEAVE_EXTGOP_X86_CVWU
}
#endif

#if _ENTER_EXTGOP_X86_CVWI
{
#endif
#if _LEAVE_EXTGOP_X86_CVWI
}
#endif

#if _ENTER_EXTGOP_X86_CVWZ
{
#endif
#if _LEAVE_EXTGOP_X86_CVWZ
}
#endif

#if _ENTER_EXTGOP_X86_CVWS
{
#endif
#if _LEAVE_EXTGOP_X86_CVWS
}
#endif

#if _LEAVE_EXTGOP_X86_CVW_
}
#endif

#if _ENTER_EXTGOP_X86_CVD_
{
#endif

#if _ENTER_EXTGOP_X86_CVDU
{
#endif
#if _LEAVE_EXTGOP_X86_CVDU
}
#endif

#if _ENTER_EXTGOP_X86_CVDI
{
#endif
#if _LEAVE_EXTGOP_X86_CVDI
}
#endif

#if _ENTER_EXTGOP_X86_CVDZ
{
#endif
#if _LEAVE_EXTGOP_X86_CVDZ
}
#endif

#if _ENTER_EXTGOP_X86_CVDS
{
#endif
#if _LEAVE_EXTGOP_X86_CVDS
}
#endif

#if _LEAVE_EXTGOP_X86_CVD_
}
#endif

#if _LEAVE_EXTGOP_X86_CV__
}
#endif

#if _ENTER_EXTGOP_X86_LDMW
{
#endif

INLINE(VWBU_MTYPE, ABU_LDMW)(uint8_t const a[4])
{
    return *(VWBU_MTYPE volatile const *) a;
}

INLINE(VWBI_MTYPE, ABI_LDMW)(int8_t const a[4])
{
    return *(VWBI_MTYPE volatile const *) a;
}

#if CHAR_SIGNEDNESS
INLINE(VWBI_MTYPE, ABC_LDMW)(char const a[4])
{
    return ABI_LDMW((void *) a);
}
#else
INLINE(VWBU_MTYPE, ABC_LDMW)(char const a[4])
{
    return ABU_LDMW((void *) a);
}
#endif

INLINE(VWHU_MTYPE, AHU_LDMW)(uint16_t a[2])
{
    return *(VWHU_MTYPE volatile const *) a;
}

INLINE(VWHI_MTYPE, AHI_LDMW)(int16_t a[2])
{
    return *(VWHI_MTYPE volatile const *) a;
}

INLINE(VWHF_MTYPE, AHF_LDMW)(flt16_t a[2])
{
    return *(VWHF_MTYPE volatile const *) a;
}


INLINE(VWWU_MTYPE, AWU_LDMW)(uint32_t a[1])
{
    return *(VWWU_MTYPE volatile const *) a;
}

INLINE(VWWI_MTYPE, AWI_LDMW)(int32_t a[1])
{
    return *(VWWI_MTYPE volatile const *) a;
}

INLINE(VWWF_MTYPE, AWF_LDMW)(float a[1])
{
    return *(VWWF_MTYPE volatile const *) a;
}

#if _LEAVE_EXTGOP_X86_LDMW
}
#endif

#if _ENTER_EXTGOP_X86_LDRW
{
#endif

#define     ABU_LDRW(a)     ((VWBU_TYPE){ABU_LDMW(a)})
#define     ABI_LDRW(a)     ((VWBI_TYPE){ABI_LDMW(a)})
#if CHAR_SIGNEDNESS
#   define  ABC_LDRW(a)     ((VWBI_TYPE){ABC_LDMW(a)})
#else
#   define  ABC_LDRW(a)     ((VWBU_TYPE){ABC_LDMW(a)})
#endif
#define     AHU_LDRW(a)     ((VWHU_TYPE){AHU_LDMW(a)})
#define     AHI_LDRW(a)     ((VWHI_TYPE){AHI_LDMW(a)})
#define     AHF_LDRW(a)     ((VWHF_TYPE){AHF_LDMW(a)})
#define     AWU_LDRW(a)     ((VWWU_TYPE){AWU_LDMW(a)})
#define     AWI_LDRW(a)     ((VWWI_TYPE){AWI_LDMW(a)})
#define     AWF_LDRW(a)     ((VWWF_TYPE){AWF_LDMW(a)})

#if _LEAVE_EXTGOP_X86_LDRW
}
#endif

#if _ENTER_EXTGOP_X86_LDMD
{
#endif

INLINE(VDBU_MTYPE, ABU_LDMD)(uint8_t const a[8])
{
    return *(VDBU_MTYPE const *) a;
}

INLINE(VDBI_MTYPE, ABI_LDMD)(int8_t const a[8])
{
    return *(VDBI_MTYPE const *) a;
}

#if CHAR_SIGNEDNESS
INLINE(VDBI_MTYPE, ABC_LDMD)(char const a[8])
{
    return ABI_LDMD((void *) a);
}
#else
INLINE(VDBU_MTYPE, ABC_LDMD)(char const a[8])
{
    return ABU_LDMD((void *) a);
}
#endif

INLINE(VDHU_MTYPE, AHU_LDMD)(uint16_t a[4])
{
    return *(VDHU_MTYPE const *) a;
}

INLINE(VDHI_MTYPE, AHI_LDMD)(int16_t a[4])
{
    return *(VDHI_MTYPE const *) a;
}

INLINE(VDHF_MTYPE, AHF_LDMD)(flt16_t a[4])
{
    return *(VDHF_MTYPE const *) a;
}


INLINE(VDWU_MTYPE, AWU_LDMD)(uint32_t a[2])
{
    return *(VDWU_MTYPE const *) a;
}

INLINE(VDWI_MTYPE, AWI_LDMD)(int32_t a[2])
{
    return *(VDWI_MTYPE const *) a;
}

INLINE(VDWF_MTYPE, AWF_LDMD)(float a[2])
{
    return *(VDWF_MTYPE const *) a;
}


INLINE(VDDU_MTYPE, ADU_LDMD)(uint64_t a[1])
{
    return *(VDDU_MTYPE const *) a;
}

INLINE(VDDI_MTYPE, ADI_LDMD)(int64_t a[1])
{
    return *(VDDI_MTYPE const *) a;
}

INLINE(VDDF_MTYPE, ADF_LDMD)(double a[1])
{
    return *(VDDF_MTYPE const *) a;
}

#if _LEAVE_EXTGOP_X86_LDMD
}
#endif

#if _ENTER_EXTGOP_X86_LDRD
{
#endif

#define     ABU_LDRD(a)     ((VDBU_TYPE){ABU_LDMD(a)})
#define     ABI_LDRD(a)     ((VDBI_TYPE){ABI_LDMD(a)})
#if CHAR_SIGNEDNESS
#   define  ABC_LDRD(a)     ((VDBI_TYPE){ABC_LDMD(a)})
#else
#   define  ABC_LDRD(a)     ((VDBU_TYPE){ABC_LDMD(a)})
#endif
#define     AHU_LDRD(a)     ((VDHU_TYPE){AHU_LDMD(a)})
#define     AHI_LDRD(a)     ((VDHI_TYPE){AHI_LDMD(a)})
#define     AHF_LDRD(a)     ((VDHF_TYPE){AHF_LDMD(a)})

#define     AWU_LDRD(a)     ((VDWU_TYPE){AWU_LDMD(a)})
#define     AWI_LDRD(a)     ((VDWI_TYPE){AWI_LDMD(a)})
#define     AWF_LDRD(a)     ((VDWF_TYPE){AWF_LDMD(a)})

#define     ADU_LDRD(a)     ((VDDU_TYPE){ADU_LDMD(a)})
#define     ADI_LDRD(a)     ((VDDI_TYPE){ADI_LDMD(a)})
#define     ADF_LDRD(a)     ((VDDF_TYPE){ADF_LDMD(a)})

#if _LEAVE_EXTGOP_X86_LDRD
}
#endif

#if _ENTER_EXTGOP_X86_LDMQ
{
#endif

INLINE(VQBU_MTYPE, ABU_LDMQ) (uint8_t const a[16])
{
    return  _mm_load_si128((void const *) a);
}

INLINE(VQBI_MTYPE, ABI_LDMQ) (int8_t  const a[16])
{
    return  _mm_load_si128((void const *) a);
}

#if CHAR_SIGNEDNESS
INLINE(VQBI_MTYPE, ABC_LDMQ)(char const a[16])
{
    return  ABI_LDMQ((void *) a);
}
#else
INLINE(VQBU_MTYPE, ABC_LDMQ)(char const a[16])
{
    return ABU_LDMD((void *) a);
}
#endif

INLINE(VQHU_MTYPE, AHU_LDMQ)(uint16_t const a[8])
{
    return  _mm_load_si128((void const *) a);
}

INLINE(VQHI_MTYPE, AHI_LDMQ)(int16_t const a[8])
{
    return  _mm_load_si128((void const *) a);
}

INLINE(VQHF_MTYPE, AHF_LDMQ)(flt16_t const a[8])
{
#if defined(SPC_X86_AVX512FP16)
    return  _mm_load_ph(a);
#else
    return  _mm_load_si128((void const *) a);
#endif
}


INLINE(VQWU_MTYPE, AWU_LDMQ)(uint32_t const a[4])
{
    return  _mm_load_si128((void const *) a);
}

INLINE(VQWI_MTYPE, AWI_LDMQ)(int32_t const a[4])
{
    return  _mm_load_si128((void const *) a);
}

INLINE(VQWF_MTYPE, AWF_LDMQ)(float const a[4])
{
    return  _mm_load_ps((void const *) a);
}


INLINE(VQDU_MTYPE, ADU_LDMQ)(uint64_t const a[2])
{
    return  _mm_load_si128((void const *) a);
}

INLINE(VQDI_MTYPE, ADI_LDMQ)(int64_t const a[2])
{
    return  _mm_load_si128((void const *) a);
}

INLINE(VQDF_MTYPE, ADF_LDMQ)(double const a[2])
{
    return  _mm_load_pd((void const *) a);
}

#if _LEAVE_EXTGOP_X86_LDMQ
}
#endif

#if _ENTER_EXTGOP_X86_LDRQ
{
#endif

#define     ABU_LDRQ(a)     ((Vqbu){ABU_LDMQ(a)})
#define     ABI_LDRQ(a)     ((Vqbi){ABI_LDMQ(a)})
#if CHAR_SIGNEDNESS
#   define  ABC_LDRQ(a)     ((Vqbi){ABC_LDMQ(a)})
#else
#   define  ABC_LDRQ(a)     ((Vqbu){ABC_LDMQ(a)})
#endif

#define     AHU_LDRQ(a)     ((Vqhu){AHU_LDMQ(a)})
#define     AHI_LDRQ(a)     ((Vqhi){AHI_LDMQ(a)})
#if defined(SPC_X86_AVX512FP16)
#   define  AHF_LDRQ                AHF_LDMQ
#else
#   define  AHF_LDRQ(a)     ((Vqhf){AHF_LDMQ(a)})
#endif

#define     AWU_LDRQ(a)     ((Vqwu){AWU_LDMQ(a)})
#define     AWI_LDRQ(a)     ((Vqwi){AWI_LDMQ(a)})
#define     AWF_LDRQ                AWF_LDMQ

#define     AQU_LDRQ(a)     ((Vqdu){AQU_LDMQ(a)})
#define     AQI_LDRQ(a)     ((Vqdi){AQI_LDMQ(a)})
#define     AQF_LDRQ                AQF_LDMQ

#if _LEAVE_EXTGOP_X86_LDRQ
}
#endif

#if _ENTER_EXTGOP_X86_LDRO
{
#endif

#if _LEAVE_EXTGOP_X86_LDRO
}
#endif

#if _ENTER_EXTGOP_X86_LDRS
{
#endif

#if _LEAVE_EXTGOP_X86_LDRS
}
#endif

#if _ENTER_EXTGOP_X86_STRW
{
#endif

#if _LEAVE_EXTGOP_X86_STRW
}
#endif

#if _ENTER_EXTGOP_X86_STRD
{
#endif

#if _LEAVE_EXTGOP_X86_STRD
}
#endif

#if _ENTER_EXTGOP_X86_STRQ
{
#endif

#if _LEAVE_EXTGOP_X86_STRQ
}
#endif

#if _ENTER_EXTGOP_X86_STRO
{
#endif

#if _LEAVE_EXTGOP_X86_STRO
}
#endif

#if _ENTER_EXTGOP_X86_STRS
{
#endif

#if _LEAVE_EXTGOP_X86_STRS
}
#endif

#if _ENTER_EXTGOP_X86_NEWL
{
#endif

#define     WBZ_NEWL(T, k0, k1, k2, k3)         \
_mm_cvtss_f32(                                  \
    _mm_castsi128_ps(                           \
        _mm_setr_epi8(                          \
            (T)(k0), (T)(k1), (T)(k2), (T)(k3), \
            ('\x00'),('\x00'),('\x00'),('\x00'),\
            ('\x00'),('\x00'),('\x00'),('\x00'),\
            ('\x00'),('\x00'),('\x00'),('\x00') \
        )                                       \
    )                                           \
)

#define     WBU_NEWL(k0,k1,k2,k3) WBZ_NEWL(UINT8_TYPE, k0,k1,k2,k3)
#define     WBI_NEWL(k0,k1,k2,k3) WBZ_NEWL( INT8_TYPE, k0,k1,k2,k3)

#define     WHZ_NEWL(T, k0, k1)                 \
_mm_cvtss_f32(                                  \
    _mm_castsi128_ps(                           \
        _mm_setr_epi16(                         \
            (T)(k0), (T)(k1), (0x0000),(0x0000),\
            (0x0000),(0x0000),(0x0000),(0x0000) \
        )                                       \
    )                                           \
)

#define     WHU_NEWL(k0, k1) WHZ_NEWL(UINT16_TYPE, k0, k1)
#define     WHI_NEWL(k0, k1) WHZ_NEWL( INT16_TYPE, k0, k1)
#if defined(SPC_X86_AVX512FP16)
#   define  WHF_NEWL(k0, k1)                \
_mm_cvtss_f32(                              \
    _mm_castph_ps(                          \
        _mm_setr_ph(                        \
            (k0),   (k1),   0.0f16, 0.0f16, \
            0.0f16, 0.0f16, 0.0f16, 0.f16   \
        )                                   \
    )                                       \
)

#else
#   define  WHF_NEWL(k0, k1)                \
_mm_cvtss_f32(                              \
    _mm_castsi128_ps(                       \
        _mm_setr_epi16(                     \
            (k0).I, (k1).I, (0x00), (0x00), \
            (0x00), (0x00), (0x00), (0x00)  \
        )                                   \
    )                                       \
)

#endif

/*  Inb4 _mm_cvtsi32_si128 results in a less efficient
    instruction sequence compared to _mm_setr_epi32 with
    3 trailing zeros, similar to neon's vdup_n and vcreate
*/

#define     WWZ_NEWL(T, k0)                 \
_mm_cvtss_f32(_mm_castsi128_ps(_mm_cvtsi32_si128((T)(k0))))

#define     WWU_NEWL(k0)    WWZ_NEWL(UINT32_TYPE, k0)
#define     WWI_NEWL(k0)    WWZ_NEWL( INT32_TYPE, k0)
#define     WWF_NEWL(k0)    ((VWWF_MTYPE)(k0))

#define     DBZ_NEWL(T,k0,k1,k2,k3,k4,k5,k6,k7) \
_mm_cvtsd_f64(                                  \
    _mm_castsi128_pd(                           \
        _mm_setr_epi8(                          \
            (T)(k0), (T)(k1), (T)(k2), (T)(k3), \
            (T)(k4), (T)(k5), (T)(k6), (T)(k7), \
            ('\x00'),('\x00'),('\x00'),('\x00'),\
            ('\x00'),('\x00'),('\x00'),('\x00') \
        )                                       \
    )                                           \
)

#define     DBU_NEWL(...) DBZ_NEWL( UINT8_TYPE, __VA_ARGS__)
#define     DBI_NEWL(...) DBZ_NEWL(  INT8_TYPE, __VA_ARGS__)

#define     DHZ_NEWL(T,k0,k1,k2,k3)             \
_mm_cvtsd_f64(                                  \
    _mm_castsi128_pd(                           \
        _mm_setr_epi16(                         \
            (T)(k0), (T)(k1), (T)(k2), (T)(k3), \
            (0x0000),(0x0000),(0x0000),(0x0000) \
        )                                       \
    )                                           \
)

#define     DHU_NEWL(...) DHZ_NEWL(UINT16_TYPE, __VA_ARGS__)
#define     DHI_NEWL(...) DHZ_NEWL( INT16_TYPE, __VA_ARGS__)

#if defined(SPC_X86_AVX512FP16)
#   define  DHF_NEWL(k0, k1, k2, k3)        \
_mm_cvtsd_f64(                              \
    _mm_castph_pd(                         \
        _mm_setr_ph(                        \
            (k0),   (k1),   (k2),   (k3),   \
            0.0f16, 0.0f16, 0.0f16, 0.f16   \
        )                                   \
    )                                       \
)

#else
#   define  DHF_NEWL(k0, k1, k2, k3)        \
_mm_cvtsd_f64(                              \
    _mm_castsi128_pd(                       \
        _mm_setr_epi16(                     \
            (k0).I, (k1).I, (k2).I, (k3).I, \
            (0x00), (0x00), (0x00), (0x00)  \
        )                                   \
    )                                       \
)
#endif

#define     DWZ_NEWL(T, k0, k1)         \
_mm_cvtsd_f64(                          \
    _mm_castsi128_pd(                   \
        _mm_setr_epi32(                 \
            (T)(k0), (T)(k1),           \
            (0x00000000),(0x00000000)   \
        )                               \
    )                                   \
)

#define     DWU_NEWL(...)   DWZ_NEWL(UINT32_TYPE, __VA_ARGS__)
#define     DWI_NEWL(...)   DWZ_NEWL( INT32_TYPE, __VA_ARGS__)
#define     DWF_NEWL(k0, k1)        \
_mm_cvtsd_f64(                      \
    _mm_castps_pd(                  \
        _mm_setr_ps(                \
            (k0), (k1), 0.0f, 0.0f  \
        )                           \
    )                               \
)

#define     DDZ_NEWL(T, k0) \
_mm_cvtsd_f64(_mm_castsi128_pd(_mm_cvtsi64_si128((T)(k0))))

#define     DDU_NEWL(k0)    DDZ_NEWL(UINT64_TYPE, k0)
#define     DDI_NEWL(k0)    DDZ_NEWL( INT64_TYPE, k0)
#define     DDF_NEWL(k0)    ((VDDF_MTYPE)(k0))


#define     QBU_NEWL        _mm_setr_epi8
#define     QBI_NEWL        _mm_setr_epi8

#define     QHU_NEWL        _mm_setr_epi16
#define     QHI_NEWL        _mm_setr_epi16
#if defined(SPC_X86_AVX512FP16)
#   define  QHF_NEWL        _mm_setr_ph
#else
#   define  QHF_NEWL(h0,h1,h2,h3,h4,h5,h6,h7)   \
_mm_setr_epi16(                                 \
    (h0).I, (h1).I, (h2).I, (h3).I,             \
    (h4).I, (h5).I, (h6).I, (h7).I              \
)
#endif

#define     QWU_NEWL        _mm_setr_epi32
#define     QWI_NEWL        _mm_setr_epi32
#define     QWF_NEWL        _mm_setr_ps

#define     QDU_NEWL(k0,k1) _mm_set_epi64x(k1, k0)
#define     QDI_NEWL(k0,k1) _mm_set_epi64x(k1, k0)
#define     QDF_NEWL        _mm_setr_pd

#define     VWBU_NEWL(...)  ((Vwbu){WBU_NEWL(__VA_ARGS__)})
#define     VWBI_NEWL(...)  ((Vwbi){WBI_NEWL(__VA_ARGS__)})

#define     VWHU_NEWL(...)  ((Vwhu){WHU_NEWL(__VA_ARGS__)})
#define     VWHI_NEWL(...)  ((Vwhi){WHI_NEWL(__VA_ARGS__)})
#define     VWHF_NEWL(...)  ((Vwhf){WHF_NEWL(__VA_ARGS__)})
#define     VWWU_NEWL(...)  ((Vwwu){WWU_NEWL(__VA_ARGS__)})
#define     VWWI_NEWL(...)  ((Vwwi){WWI_NEWL(__VA_ARGS__)})
#define     VWWF_NEWL(...)  ((Vwwf){WWF_NEWL(__VA_ARGS__)})

#define     VDBU_NEWL(...)  ((Vdbu){DBU_NEWL(__VA_ARGS__)})
#define     VDBI_NEWL(...)  ((Vdbi){DBI_NEWL(__VA_ARGS__)})
#define     VDHU_NEWL(...)  ((Vdhu){DHU_NEWL(__VA_ARGS__)})
#define     VDHI_NEWL(...)  ((Vdhi){DHI_NEWL(__VA_ARGS__)})
#define     VDHF_NEWL(...)  ((Vdhf){DHF_NEWL(__VA_ARGS__)})
#define     VDWU_NEWL(...)  ((Vdwu){DWU_NEWL(__VA_ARGS__)})
#define     VDWI_NEWL(...)  ((Vdwi){DWI_NEWL(__VA_ARGS__)})
#define     VDWF_NEWL(...)  ((Vdwf){DWF_NEWL(__VA_ARGS__)})
#define     VDDU_NEWL(...)  ((Vddu){DDU_NEWL(__VA_ARGS__)})
#define     VDDI_NEWL(...)  ((Vddi){DDI_NEWL(__VA_ARGS__)})
#define     VDDF_NEWL(...)  ((Vddf){DDF_NEWL(__VA_ARGS__)})

#define     VQBU_NEWL(...)  ((Vqbu){QBU_NEWL(__VA_ARGS__)})
#define     VQBI_NEWL(...)  ((Vqbi){QBI_NEWL(__VA_ARGS__)})
#define     VQHU_NEWL(...)  ((Vqhu){QHU_NEWL(__VA_ARGS__)})
#define     VQHI_NEWL(...)  ((Vqhi){QHI_NEWL(__VA_ARGS__)})
#if defined(SPC_X86_AVX512FP16)
#   define  VQHF_NEWL               QHF_NEWL
#else
#   define  VQHF_NEWL(...)  ((Vqhf){QHF_NEWL(__VA_ARGS__)})
#endif
#define     VQWU_NEWL(...)  ((Vqwu){QWU_NEWL(__VA_ARGS__)})
#define     VQWI_NEWL(...)  ((Vqwi){QWI_NEWL(__VA_ARGS__)})
#define     VQWF_NEWL               QWF_NEWL
#define     VQDU_NEWL(...)  ((Vqdu){QDU_NEWL(__VA_ARGS__)})
#define     VQDI_NEWL(...)  ((Vqdi){QDI_NEWL(__VA_ARGS__)})
#define     VQDF_NEWL               QDF_NEWL


#if _LEAVE_EXTGOP_X86_NEWL
}
#endif

#if _ENTER_EXTGOP_X86_CATL
{
#endif

#define     VW_CAT(W, l, r)         \
_mm_cvtsd_f64(                      \
    _mm_castps_pd(                  \
        _mm_setr_ps(                \
            _Generic((l), W: (l)),  \
            _Generic((r), W: (r)),  \
            0, 0                    \
        )                           \
    )                               \
)

#define     WBU_CATL(l, r)  VW_CAT(VWBU_MTYPE, l, r)
#define     WBI_CATL(l, r)  VW_CAT(VWBI_MTYPE, l, r)
#define     WHU_CATL(l, r)  VW_CAT(VWHU_MTYPE, l, r)
#define     WHI_CATL(l, r)  VW_CAT(VWHI_MTYPE, l, r)
#define     WHF_CATL(l, r)  VW_CAT(VWHF_MTYPE, l, r)
#define     WWU_CATL(l, r)  VW_CAT(VWWU_MTYPE, l, r)
#define     WWI_CATL(l, r)  VW_CAT(VWWI_MTYPE, l, r)
#define     WWF_CATL(l, r)  VW_CAT(VWWF_MTYPE, l, r)

#define     VD_CAT(Q, D, l, r)  \
_mm_castpd_##Q(                 \
    _mm_setr_pd(                \
        _Generic((l), D: (l)),  \
        _Generic((r), D: (r))   \
    )                           \
)

#define     VDZ_CAT(D,l,r)  VD_CAT(si128, D, l, r)

#define     DBU_CATL(l, r)  VDZ_CAT(   VDBU_MTYPE, l, r)
#define     DBI_CATL(l, r)  VDZ_CAT(   VDBI_MTYPE, l, r)
#define     DHU_CATL(l, r)  VDZ_CAT(   VDHU_MTYPE, l, r)
#define     DHI_CATL(l, r)  VDZ_CAT(   VDHI_MTYPE, l, r)
#if defined(SPC_X86_AVX512FP16)
#   define  DHF_CATL(l, r)  VD_CAT(ph, VDHF_MTYPE, l, r)
#else
#   define  DHF_CATL(l, r)  VDZ_CAT(   VDHF_MTYPE, l, r)
#endif

#define     DWU_CATL(l, r)  VDZ_CAT(   VDWU_MTYPE, l, r)
#define     DWI_CATL(l, r)  VDZ_CAT(   VDWI_MTYPE, l, r)
#define     DWF_CATL(l, r)  VD_CAT(ps, VDWF_MTYPE, l, r)
#define     DDU_CATL(l, r)  VDZ_CAT(   VDDU_MTYPE, l, r)
#define     DDI_CATL(l, r)  VDZ_CAT(   VDDI_MTYPE, l, r)
#define     DDF_CATL(l, r)          \
_mm_setr_pd(                        \
    _Generic((l), VDDF_MTYPE: (l)), \
    _Generic((r), VDDF_MTYPE: (r))  \
)

// catl
#define     VWBU_CATL(l, r) ((Vdbu){WBU_CATL((l).V0, (r).V0)})
#define     VWBI_CATL(l, r) ((Vdbi){WBI_CATL((l).V0, (r).V0)})
#define     VWHU_CATL(l, r) ((Vdhu){WHU_CATL((l).V0, (r).V0)})
#define     VWHI_CATL(l, r) ((Vdhi){WHI_CATL((l).V0, (r).V0)})
#define     VWHF_CATL(l, r) ((Vdhf){WHF_CATL((l).V0, (r).V0)})
#define     VWWU_CATL(l, r) ((Vdwu){WWU_CATL((l).V0, (r).V0)})
#define     VWWI_CATL(l, r) ((Vdwi){WWI_CATL((l).V0, (r).V0)})
#define     VWWF_CATL(l, r) ((Vdwf){WWF_CATL((l).V0, (r).V0)})

#define     VDBU_CATL(l, r) ((Vqbu){DBU_CATL((l).V0, (r).V0)})
#define     VDBI_CATL(l, r) ((Vqbi){DBI_CATL((l).V0, (r).V0)})
#define     VDHU_CATL(l, r) ((Vqhu){DHU_CATL((l).V0, (r).V0)})
#define     VDHI_CATL(l, r) ((Vqhi){DHI_CATL((l).V0, (r).V0)})
#if defined(SPC_X86_AVX512FP16)
#   define  VDHF_CATL(l, r) DHF_CATL((l).V0, (r).V0)
#else
#   define  VDHF_CATL(l, r) ((Vqhf){DHI_CATL((l).V0, (r).V0)})
#endif

#define     VDWU_CATL(l, r) ((Vqwu){DWU_CATL((l).V0, (r).V0)})
#define     VDWI_CATL(l, r) ((Vqwi){DWI_CATL((l).V0, (r).V0)})
#define     VDWF_CATL(l, r)         DWF_CATL((l).V0, (r).V0)

#define     VDDU_CATL(l, r) ((Vqdu){DDU_CATL((l).V0, (r).V0)})
#define     VDDI_CATL(l, r) ((Vqdi){DDI_CATL((l).V0, (r).V0)})
#define     VDDF_CATL(l, r)         DDF_CATL((l).V0, (r).V0)

#if _LEAVE_EXTGOP_X86_CATL
}
#endif

#if _ENTER_EXTGOP_X86_REVS
{
#endif

#if _LEAVE_EXTGOP_X86_REVS
}
#endif

#if _ENTER_EXTGOP_X86_VXTL
{
#endif

#define     VD_VXTL(V)      _mm_cvtss_f32(_mm_castpd_ps(_mm_set_sd(V)))

#define     DBU_VXTL        VD_VXTL
#define     DBI_VXTL        VD_VXTL
#define     DHU_VXTL        VD_VXTL
#define     DHI_VXTL        VD_VXTL
#define     DHF_VXTL        VD_VXTL
#define     DWU_VXTL        VD_VXTL
#define     DWI_VXTL        VD_VXTL
#define     DWF_VXTL        VD_VXTL

#define     VQ_VXTL(T, V)   _mm_cvtsd_f64(_mm_cast##T(V))
#define     VQZ_VXTL(V)     VQ_VXTL(si128_pd, V)

#define     QBU_VXTL        VQZ_VXTL
#define     QBI_VXTL        VQZ_VXTL
#define     QHU_VXTL        VQZ_VXTL
#define     QHI_VXTL        VQZ_VXTL
#if defined(SPC_X86_AVX512FP16)
#   define  QHF_VXTL(V)     VQ_VXTL(ph_pd, V)
#else
#   define  QHF_VXTL        VQZ_VXTL
#endif

#define     QWU_VXTL        VQZ_VXTL
#define     QWI_VXTL        VQZ_VXTL
#define     QWF_VXTL(V)     VQ_VXTL(ps_pd, V)
#define     QDU_VXTL        VQZ_VXTL
#define     QDI_VXTL        VQZ_VXTL
#define     QDF_VXTL        _mm_cvtsd_f64

#define     VDBU_VXTL(V)    ((Vwbu){DBU_VXTL(VDBU_ASTM(V))})
#define     VDBI_VXTL(V)    ((Vwbi){DBI_VXTL(VDBI_ASTM(V))})
#define     VDHU_VXTL(V)    ((Vwhu){DHU_VXTL(VDHU_ASTM(V))})
#define     VDHI_VXTL(V)    ((Vwhi){DHI_VXTL(VDHI_ASTM(V))})
#define     VDHF_VXTL(V)    ((Vwhf){DHF_VXTL(VDHF_ASTM(V))})
#define     VDWU_VXTL(V)    ((Vwwu){DWU_VXTL(VDWU_ASTM(V))})
#define     VDWI_VXTL(V)    ((Vwwi){DWI_VXTL(VDWI_ASTM(V))})
#define     VDWF_VXTL(V)    ((Vwwf){DWF_VXTL(VDWF_ASTM(V))})

#define     VQBU_VXTL(V)    ((Vdbu){QBU_VXTL(VQBU_ASTM(V))})
#define     VQBI_VXTL(V)    ((Vdbi){QBI_VXTL(VQBI_ASTM(V))})
#define     VQHU_VXTL(V)    ((Vdhu){QHU_VXTL(VQHU_ASTM(V))})
#define     VQHI_VXTL(V)    ((Vdhi){QHI_VXTL(VQHI_ASTM(V))})
#define     VQHF_VXTL(V)    ((Vdhf){QHF_VXTL(VQHF_ASTM(V))})
#define     VQWU_VXTL(V)    ((Vdwu){QWU_VXTL(VQWU_ASTM(V))})
#define     VQWI_VXTL(V)    ((Vdwi){QWI_VXTL(VQWI_ASTM(V))})
#define     VQWF_VXTL(V)    ((Vdwf){QWF_VXTL(VQWF_ASTM(V))})
#define     VQDU_VXTL(V)    ((Vddu){QDU_VXTL(VQDU_ASTM(V))})
#define     VQDI_VXTL(V)    ((Vddi){QDI_VXTL(VQDI_ASTM(V))})
#define     VQDF_VXTL(V)    ((Vddf){QDF_VXTL(VQDF_ASTM(V))})

#if _LEAVE_EXTGOP_X86_VXTL
}
#endif

#if _ENTER_EXTGOP_X86_VXTR
{
#endif

#define     VD_VXTR(V)                      \
_mm_cvtss_f32(                              \
    _mm_castsi128_ps(                       \
        _mm_shuffle_epi32(                  \
            _mm_castpd_si128(_mm_set_sd(V)),\
            0b01                            \
        )                                   \
    )                                       \
)

#define     DBU_VXTR    VD_VXTR
#define     DBI_VXTR    VD_VXTR
#define     DHU_VXTR    VD_VXTR
#define     DHI_VXTR    VD_VXTR
#define     DHF_VXTR    VD_VXTR
#define     DWU_VXTR    VD_VXTR
#define     DWI_VXTR    VD_VXTR
#define     DWF_VXTR    VD_VXTR

#define     VQ_VXTR(T, V)   \
_mm_cvtsd_f64(              \
    _mm_unpackhi_pd(        \
        _mm_cast ##T(V),    \
        _mm_undefined_pd()  \
    )                       \
)

#define     VQZ_VXTR(a)     VQ_VXTR(si128_pd, a)
#define     QBU_VXTR        VQZ_VXTR
#define     QBI_VXTR        VQZ_VXTR
#define     QHU_VXTR        VQZ_VXTR
#define     QHI_VXTR        VQZ_VXTR
#if defined(SPC_X86_AVX512FP16)
#   define  QHF_VXTR(a)     VQ_VXTR(ph_pd, a)
#else
#   define  QHF_VXTR        VQZ_VXTR
#endif

#define     QWU_VXTR        VQZ_VXTR
#define     QWI_VXTR        VQZ_VXTR
#define     QWF_VXTR(a)     VQ_VXTR(ps_pd, a)
#define     QDU_VXTR        VQZ_VXTR
#define     QDI_VXTR        VQZ_VXTR
#define     QDF_VXTR(c)     \
_mm_cvtsd_f64(_mm_unpackhi_pd(c, _mm_undefined_pd()))

#define     VDBU_VXTR(V)    ((Vwbu){DBU_VXTR(VDBU_ASTM(V))})
#define     VDBI_VXTR(V)    ((Vwbi){DBI_VXTR(VDBI_ASTM(V))})
#define     VDHU_VXTR(V)    ((Vwhu){DHU_VXTR(VDHU_ASTM(V))})
#define     VDHI_VXTR(V)    ((Vwhi){DHI_VXTR(VDHI_ASTM(V))})
#define     VDHF_VXTR(V)    ((Vwhf){DHF_VXTR(VDHF_ASTM(V))})
#define     VDWU_VXTR(V)    ((Vwwu){DWU_VXTR(VDWU_ASTM(V))})
#define     VDWI_VXTR(V)    ((Vwwi){DWI_VXTR(VDWI_ASTM(V))})
#define     VDWF_VXTR(V)    ((Vwwf){DWF_VXTR(VDWF_ASTM(V))})

#define     VQBU_VXTR(V)    ((Vdbu){QBU_VXTR(VQBU_ASTM(V))})
#define     VQBI_VXTR(V)    ((Vdbi){QBI_VXTR(VQBI_ASTM(V))})
#define     VQHU_VXTR(V)    ((Vdhu){QHU_VXTR(VQHU_ASTM(V))})
#define     VQHI_VXTR(V)    ((Vdhi){QHI_VXTR(VQHI_ASTM(V))})
#define     VQHF_VXTR(V)    ((Vdhf){QHF_VXTR(VQHF_ASTM(V))})
#define     VQWU_VXTR(V)    ((Vdwu){QWU_VXTR(VQWU_ASTM(V))})
#define     VQWI_VXTR(V)    ((Vdwi){QWI_VXTR(VQWI_ASTM(V))})
#define     VQWF_VXTR(V)    ((Vdwf){QWF_VXTR(VQWF_ASTM(V))})
#define     VQDU_VXTR(V)    ((Vddu){QDU_VXTR(VQDU_ASTM(V))})
#define     VQDI_VXTR(V)    ((Vddi){QDI_VXTR(VQDI_ASTM(V))})
#define     VQDF_VXTR(V)    ((Vddf){QDF_VXTR(VQDF_ASTM(V))})

#if _LEAVE_EXTGOP_X86_VXTR
}
#endif


#endif

#if _LEAVE_EXTGOP_X86
}
#endif

/*
    catldbu(l, r) takes two Df1 HVAs and returns a Qdf1.
    The __vectorcall spec says this means 'l' and 'r'
    should be passed in xmm0, and xmm1, respectively, and
    the result returned in xmm0, yet the following is what
    godbolt outputs with '-O2 -std:c11 -arch:SSE2 -Gv',
    the last argument supposedly implicitly declaring all
    functions `__vectorcall`. When that didn't work,
    PUBLIC was changed from an object macro to the current
    form, which formats the declaration in whatever screwed
    up method is syntactically valid, and this of course
    had no effect:

        catldbu PROC
            ms x64 -Gv (msvc)
                mov         QWORD PTR [rsp+24], r8
                mov         rax,                rcx
                vmovsd      xmm1,               QWORD PTR r$[rsp]
                mov         QWORD PTR [rsp+16], rdx
                vmovsd      xmm0,               QWORD PTR l$[rsp]
                vunpcklpd   xmm1, xmm0, xmm1
                vmovdqu     XMMWORD PTR [rcx], xmm1
                ret 0

            sysv x64 (clang)
                vmovlhps        xmm0, xmm0, xmm1

    The output should be identical to clang's, which uses
    vmovlhps to move the lower half of xmm1 to the upper
    half of xmm0, which is exactly what catl is supposed
    to for 64 bit operands...
*/

#if _ENTER_DECL
{
#endif

#define     TGV_BDU(_) TGW_BDU(_) TGD_BDU(_) TGQ_BDU(_) TGO_BDU(_) TGS_BDU(_)
#define     TGV_BDI(_) TGW_BDI(_) TGD_BDI(_) TGQ_BDI(_) TGO_BDI(_) TGS_BDI(_)
#define     TGV_BDF(_) TGW_BDF(_) TGD_BDF(_) TGQ_BDF(_) TGO_BDF(_) TGS_BDF(_)
#define     TGV_BDZ(_) TGW_BDZ(_) TGD_BDZ(_) TGQ_BDZ(_) TGO_BDZ(_) TGS_BDZ(_)
#define     TGV_BDS(_) TGW_BDS(_) TGD_BDS(_) TGQ_BDS(_) TGO_BDS(_) TGS_BDS(_)
#define     TGV_BDR(_) TGW_BDR(_) TGD_BDR(_) TGQ_BDR(_) TGO_BDR(_) TGR_BDR(_)

#if _ENTER_AS__
{
#endif

#if _ENTER_AST_
{
#endif

#if _ENTER_ASTV
{
#endif


PUBLIC(Vwwu,astvwu) (uint32_t x);
PUBLIC(Vwwi,astvwi) ( int32_t x);
PUBLIC(Vwwf,astvwf) (   float x);
PUBLIC(Vddu,astvdu) (uint64_t x);
PUBLIC(Vddi,astvdi) ( int64_t x);
PUBLIC(Vddf,astvdf) (  double x);

#if DWRD_NLONG == 2
PUBLIC(Vwwu,astvlu) (   ulong x);
PUBLIC(Vwwi,astvli) (    long x);
#elif QUAD_NLLONG == 2
PUBLIC(Vddu,astvlu) (  ullong x);
PUBLIC(Vddi,astvli) (   llong x);
#endif

PUBLIC(uint32_t,astvwwu)(Vwwu x);
PUBLIC( int32_t,astvwwi)(Vwwi x);
PUBLIC(   float,astvwwf)(Vwwf x);

PUBLIC(uint64_t,astvddu)(Vddu x);
PUBLIC( int64_t,astvddi)(Vddi x);
PUBLIC(  double,astvddf)(Vddf x);

#define     astv_funcof(X)  \
FUNCOF(                     \
    astv,   (   X   ),      \
    WDR,    /* TGK */       \
    WR,     /* TGW */       \
    DR,     /* TGD */       \
    NONE,   /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGO */       \
    default: NULL           \
)
#define     astv(X) (astv_funcof(X)(X))

PUBLIC(Vwwu,astvwu) (uint32_t x) {return UINT32_ASTV(x);}
PUBLIC(Vwwi,astvwi) ( int32_t x) {return  INT32_ASTV(x);}
PUBLIC(Vwwf,astvwf) (   float x) {return    FLT_ASTV(x);}
PUBLIC(Vddu,astvdu) (uint64_t x) {return UINT64_ASTV(x);}
PUBLIC(Vddi,astvdi) ( int64_t x) {return  INT64_ASTV(x);}
PUBLIC(Vddf,astvdf) (  double x) {return    DBL_ASTV(x);}

#if DWRD_NLONG == 2
PUBLIC(Vwwu,astvlu) (   ulong x) {return  ULONG_ASTV(x);}
PUBLIC(Vwwi,astvli) (    long x) {return   LONG_ASTV(x);}
#elif QUAD_NLLONG == 2
PUBLIC(Vddu,astvlu) (  ullong x) {return ULLONG_ASTV(x);}
PUBLIC(Vddi,astvli) (   llong x) {return  LLONG_ASTV(x);}
#endif

PUBLIC(uint32_t,astvwwu)(Vwwu x) {return   VWWU_ASTV(x);}
PUBLIC( int32_t,astvwwi)(Vwwi x) {return   VWWI_ASTV(x);}
PUBLIC(   float,astvwwf)(Vwwf x) {return   VWWF_ASTV(x);}
PUBLIC(uint64_t,astvddu)(Vddu x) {return   VDDU_ASTV(x);}
PUBLIC( int64_t,astvddi)(Vddi x) {return   VDDI_ASTV(x);}
PUBLIC(  double,astvddf)(Vddf x) {return   VDDF_ASTV(x);}

#define     astvwu(X)   UINT32_ASTV(X)
#define     astvwi(X)    INT32_ASTV(X)
#define     astvwf(X)      FLT_ASTV(X)
#if DWRD_NLONG == 2
#define     astvlu(X)    ULONG_ASTV(X)
#define     astvli(X)     LONG_ASTV(X)
#elif QUAD_NLLONG == 2
#define     astvlu(X)   ULLONG_ASTV(X)
#define     astvli(X)    LLONG_ASTV(X)
#endif

#define     astvdu(X)   UINT64_ASTV(X)
#define     astvdi(X)    INT64_ASTV(X)
#define     astvdf(X)      DBL_ASTV(X)

#define     astvwwu(X)    VWWU_ASTV(X)
#define     astvwwi(X)    VWWI_ASTV(X)
#define     astvwwf(X)    VWWF_ASTV(X)

#define     astvddu(X)    VDDU_ASTV(X)
#define     astvddi(X)    VDDI_ASTV(X)
#define     astvddf(X)    VDDF_ASTV(X)

#if _LEAVE_ASTV
}
#endif

#if _ENTER_ASTU
{
#endif

//  astu: KV_BDS
PUBLIC( uint8_t,astubi) ( int8_t x);
PUBLIC( uint8_t,astubc) (   char x);
PUBLIC(uint16_t,astuhi) (int16_t x);
PUBLIC(uint16_t,astuhf) (flt16_t x);
PUBLIC(uint32_t,astuwi) (int32_t x);
PUBLIC(uint32_t,astuwf) (  float x);
PUBLIC(uint64_t,astudi) (int64_t x);
PUBLIC(uint64_t,astudf) ( double x);
#if DWRD_NLONG == 2
PUBLIC(uint32_t,astuli) (   long x);
#elif QUAD_NLLONG == 4
PUBLIC(uint64_t,astuli) (  llong x);
#endif

PUBLIC(Vwbu,astuwbi) (Vwbi x);
PUBLIC(Vwbu,astuwbc) (Vwbc x);
PUBLIC(Vwhu,astuwhi) (Vwhi x);
PUBLIC(Vwhu,astuwhf) (Vwhf x);
PUBLIC(Vwwu,astuwwi) (Vwwi x);
PUBLIC(Vwwu,astuwwf) (Vwwf x);

PUBLIC(Vdbu,astudbi) (Vdbi x);
PUBLIC(Vdbu,astudbc) (Vdbc x);
PUBLIC(Vdhu,astudhi) (Vdhi x);
PUBLIC(Vdhu,astudhf) (Vdhf x);
PUBLIC(Vdwu,astudwi) (Vdwi x);
PUBLIC(Vdwu,astudwf) (Vdwf x);
PUBLIC(Vddu,astuddi) (Vddi x);
PUBLIC(Vddu,astuddf) (Vddf x);

PUBLIC(Vqbu,astuqbi) (Vqbi x);
PUBLIC(Vqbu,astuqbc) (Vqbc x);
PUBLIC(Vqhu,astuqhi) (Vqhi x);
PUBLIC(Vqhu,astuqhf) (Vqhf x);
PUBLIC(Vqwu,astuqwi) (Vqwi x);
PUBLIC(Vqwu,astuqwf) (Vqwf x);
PUBLIC(Vqdu,astuqdi) (Vqdi x);
PUBLIC(Vqdf,astuqdf) (Vqdf x);

#define     astu_funcof(X)  \
FUNCOF(                     \
    astu,   (   X   ),      \
    BDS,    /* TGK */       \
    BWS,    /* TGW */       \
    BDS,    /* TGD */       \
    BDS,    /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGO */       \
    default: NULL           \
)
#define     astu(X) (astu_funcof(X)(X))

//  astu: KV_BDS
PUBLIC( uint8_t,astubi) ( int8_t x) {return  INT8_ASTU(x);}
PUBLIC( uint8_t,astubc) (   char x) {return  CHAR_ASTU(x);}
PUBLIC(uint16_t,astuhi) (int16_t x) {return INT16_ASTU(x);}
PUBLIC(uint16_t,astuhf) (flt16_t x) {return FLT16_ASTU(x);}
PUBLIC(uint32_t,astuwi) (int32_t x) {return INT32_ASTU(x);}
PUBLIC(uint32_t,astuwf) (  float x) {return   FLT_ASTU(x);}
PUBLIC(uint64_t,astudi) (int64_t x) {return INT64_ASTU(x);}
PUBLIC(uint64_t,astudf) ( double x) {return   DBL_ASTU(x);}
#if DWRD_NLONG == 2
PUBLIC(uint32_t,astuli) (   long x) {return  LONG_ASTU(x);}
#elif QUAD_NLLONG == 2
PUBLIC(uint64_t,astuli) (  llong x) {return LLONG_ASTU(x);}
#endif

PUBLIC(Vwbu,astuwbi) (Vwbi x) {return VWBI_ASTU(x);}
PUBLIC(Vwbu,astuwbc) (Vwbc x) {return VWBC_ASTU(x);}
PUBLIC(Vwhu,astuwhi) (Vwhi x) {return VWHI_ASTU(x);}
PUBLIC(Vwhu,astuwhf) (Vwhf x) {return VWHF_ASTU(x);}
PUBLIC(Vwwu,astuwwi) (Vwwi x) {return VWWI_ASTU(x);}
PUBLIC(Vwwu,astuwwf) (Vwwf x) {return VWWF_ASTU(x);}

PUBLIC(Vdbu,astudbi) (Vdbi x) {return VDBI_ASTU(x);}
PUBLIC(Vdbu,astudbc) (Vdbc x) {return VDBC_ASTU(x);}
PUBLIC(Vdhu,astudhi) (Vdhi x) {return VDHI_ASTU(x);}
PUBLIC(Vdhu,astudhf) (Vdhf x) {return VDHF_ASTU(x);}
PUBLIC(Vdwu,astudwi) (Vdwi x) {return VDWI_ASTU(x);}
PUBLIC(Vdwu,astudwf) (Vdwf x) {return VDWF_ASTU(x);}
PUBLIC(Vddu,astuddi) (Vddi x) {return VDDI_ASTU(x);}
PUBLIC(Vddu,astuddf) (Vddf x) {return VDDF_ASTU(x);}

PUBLIC(Vqbu,astuqbi) (Vqbi x) {return VQBI_ASTU(x);}
PUBLIC(Vqbu,astuqbc) (Vqbc x) {return VQBC_ASTU(x);}
PUBLIC(Vqhu,astuqhi) (Vqhi x) {return VQHI_ASTU(x);}
PUBLIC(Vqhu,astuqhf) (Vqhf x) {return VQHF_ASTU(x);}
PUBLIC(Vqwu,astuqwi) (Vqwi x) {return VQWI_ASTU(x);}
PUBLIC(Vqwu,astuqwf) (Vqwf x) {return VQWF_ASTU(x);}
PUBLIC(Vqdu,astuqdi) (Vqdi x) {return VQDI_ASTU(x);}
PUBLIC(Vqdf,astuqdf) (Vqdf x) {return VQDF_ASTU(x);}

#define     astubi  SCHAR_ASBU
#define     astubc   CHAR_ASBU
#define     astuhi   SHRT_ASHU
#define     astuhf  FLT16_ASHU
#define     astuwi    INT_ASWU
#define     astuwf    FLT_ASWU
#if DWRD_NLONG == 2
#   define  astuli   LONG_ASWU
#   define  astudi  LLONG_ASDU
#elif QUAD_NLLONG == 2
#   define  astudi   LONG_ASDU
#   define  astuli  LLONG_ASWU
#endif
#define     astudf    DBL_ASDU

#define     astuwbi  VWBI_ASTU
#define     astuwbc  VWBC_ASTU(X)
#define     astuwhi  VWHI_ASTU(X)
#define     astuwhf  VWHF_ASTU(X)
#define     astuwwi  VWWI_ASTU(X)
#define     astuwwf  VWWU_ASTU(X)

#define     astudbi(X)  VDBI_ASTU(X)
#define     astudbc(X)  VDBC_ASTU(X)
#define     astudhi(X)  VDHI_ASTU(X)
#define     astudhf(X)  VDHF_ASTU(X)
#define     astudwi(X)  VDWI_ASTU(X)
#define     astudwf(X)  VDWF_ASTU(X)
#define     astuddi(X)  VDDI_ASTU(X)
#define     astuddf(X)  VDDF_ASTU(X)

#define     astuqbi(X)  VQBI_ASTU(X)
#define     astuqbc(X)  VQBC_ASTU(X)
#define     astuqhi(X)  VQHI_ASTU(X)
#define     astuqhf(X)  VQHF_ASTU(X)
#define     astuqwi(X)  VQWI_ASTU(X)
#define     astuqwf(X)  VQWF_ASTU(X)
#define     astuqdi(X)  VQDI_ASTU(X)
#define     astuqdf(X)  VQDF_ASTU(X)

#if _LEAVE_ASTU
}
#endif

#if _ENTER_ASTI
{
#endif

#define     UINT8_ASTI      UINT8_BASE(ASTI)
#define     UINT16_ASTI     UINT16_BASE(ASTI)
#define     UINT32_ASTI     UINT32_BASE(ASTI)
#define     UINT64_ASTI     UINT64_BASE(ASTI)

PUBLIC(int8_t, astibu) ( uint8_t n);
PUBLIC(int8_t, astibc) (    char n);
PUBLIC(int16_t,astihu) (uint16_t n);
PUBLIC(int16_t,astihf) ( flt16_t n);
PUBLIC(int32_t,astiwu) (uint32_t n);
PUBLIC(int32_t,astiwf) (   float n);
PUBLIC(int64_t,astidu) (uint64_t n);
PUBLIC(int64_t,astidf) (  double n);
#if DWRD_NLONG == 2
PUBLIC(int32_t,astilu) (   ulong n);
#elif QUAD_NLLONG == 2
PUBLIC(int64_t,astilu) (  ullong n);
#endif

PUBLIC(Vwbi,astiwbu) (Vwbu n);
PUBLIC(Vwbi,astiwbc) (Vwbc n);
PUBLIC(Vwhi,astiwhu) (Vwhu n);
PUBLIC(Vwhi,astiwhf) (Vwhf n);
PUBLIC(Vwwi,astiwwu) (Vwwu n);
PUBLIC(Vwwi,astiwwf) (Vwwf n);

PUBLIC(Vdbi,astidbu) (Vdbu n);
PUBLIC(Vdbi,astidbc) (Vdbc n);
PUBLIC(Vdhi,astidhu) (Vdhu n);
PUBLIC(Vdhi,astidhf) (Vdhf n);
PUBLIC(Vdwi,astidwu) (Vdwu n);
PUBLIC(Vdwi,astidwf) (Vdwf n);
PUBLIC(Vddi,astiddu) (Vddu n);
PUBLIC(Vddi,astiddf) (Vddf n);

PUBLIC(Vqbi,astiqbu) (Vqbu n);
PUBLIC(Vqbi,astiqbc) (Vqbc n);
PUBLIC(Vqhi,astiqhu) (Vqhu n);
PUBLIC(Vqhi,astiqhf) (Vqhf n);
PUBLIC(Vqwi,astiqwu) (Vqwu n);
PUBLIC(Vqwi,astiqwf) (Vqwf n);
PUBLIC(Vqdi,astiqdu) (Vqdu n);
PUBLIC(Vqdi,astiqdf) (Vqdf n);

#define     asti_funcof(N)  \
FUNCOF(                     \
    asti,   (   N   ),      \
    BDN,    /* TGK */       \
    BWN,    /* TGW */       \
    BDN,    /* TGD */       \
    BDN,    /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGO */       \
    default: NULL           \
)

#define     asti(C, L)  (asti_funcof(C)(C,L))
PUBLIC(int8_t, astibu) ( uint8_t n) {return  UINT8_ASTI(n);}
PUBLIC(int8_t, astibc) (    char n) {return   CHAR_ASTI(n);}
PUBLIC(int16_t,astihu) (uint16_t n) {return UINT16_ASTI(n);}
PUBLIC(int16_t,astihf) ( flt16_t n) {return  FLT16_ASTI(n);}
PUBLIC(int32_t,astiwu) (uint32_t n) {return UINT32_ASTI(n);}
PUBLIC(int32_t,astiwf) (   float n) {return    FLT_ASTI(n);}
PUBLIC(int64_t,astidu) (uint64_t n) {return UINT64_ASTI(n);}
PUBLIC(int64_t,astidf) (  double n) {return    DBL_ASTI(n);}
#if DWRD_NLONG == 2
PUBLIC(int32_t,astilu) (   ulong n) {return  ULONG_ASTI(n);}
#elif QUAD_NLLONG == 2
PUBLIC(int64_t,astilu) (  ullong n) {return ULLONG_ASTI(n);}
#endif

PUBLIC(Vwbi,astiwbu) (Vwbu n) {return VWBU_ASTI(n);}
PUBLIC(Vwbi,astiwbc) (Vwbc n) {return VWBC_ASTI(n);}
PUBLIC(Vwhi,astiwhu) (Vwhu n) {return VWHU_ASTI(n);}
PUBLIC(Vwhi,astiwhf) (Vwhf n) {return VWHF_ASTI(n);}
PUBLIC(Vwwi,astiwwu) (Vwwu n) {return VWWU_ASTI(n);}
PUBLIC(Vwwi,astiwwf) (Vwwf n) {return VWWF_ASTI(n);}

PUBLIC(Vdbi,astidbu) (Vdbu n) {return VDBU_ASTI(n);}
PUBLIC(Vdbi,astidbc) (Vdbc n) {return VDBC_ASTI(n);}
PUBLIC(Vdhi,astidhu) (Vdhu n) {return VDHU_ASTI(n);}
PUBLIC(Vdhi,astidhf) (Vdhf n) {return VDHF_ASTI(n);}
PUBLIC(Vdwi,astidwu) (Vdwu n) {return VDWU_ASTI(n);}
PUBLIC(Vdwi,astidwf) (Vdwf n) {return VDWF_ASTI(n);}
PUBLIC(Vddi,astiddu) (Vddu n) {return VDDU_ASTI(n);}
PUBLIC(Vddi,astiddf) (Vddf n) {return VDDF_ASTI(n);}

PUBLIC(Vqbi,astiqbu) (Vqbu n) {return VQBU_ASTI(n);}
PUBLIC(Vqbi,astiqbc) (Vqbc n) {return VQBC_ASTI(n);}
PUBLIC(Vqhi,astiqhu) (Vqhu n) {return VQHU_ASTI(n);}
PUBLIC(Vqhi,astiqhf) (Vqhf n) {return VQHF_ASTI(n);}
PUBLIC(Vqwi,astiqwu) (Vqwu n) {return VQWU_ASTI(n);}
PUBLIC(Vqwi,astiqwf) (Vqwf n) {return VQWF_ASTI(n);}
PUBLIC(Vqdi,astiqdu) (Vqdu n) {return VQDU_ASTI(n);}
PUBLIC(Vqdi,astiqdf) (Vqdf n) {return VQDF_ASTI(n);}

#if _LEAVE_ASTI
}
#endif

#if _ENTER_ASTF
{
#endif

PUBLIC(flt16_t,astfhu) (uint16_t z);
PUBLIC(flt16_t,astfhi) ( int16_t z);
PUBLIC(  float,astfwu) (uint32_t z);
PUBLIC(  float,astfwi) ( int32_t z);
PUBLIC( double,astfdu) (uint64_t z);
PUBLIC( double,astfdi) ( int64_t z);
#if DWRD_NLONG == 2
PUBLIC(  float,astflu) (   ulong z);
PUBLIC(  float,astfli) (    long z);
#elif QUAD_NLLONG == 2
PUBLIC( double,astflu) (  ullong z);
PUBLIC( double,astfli) (   llong z);
#endif

PUBLIC(Vwhf,astfwhu) (Vwhu z);
PUBLIC(Vwhf,astfwhi) (Vwhi z);
PUBLIC(Vwwf,astfwwu) (Vwwu z);
PUBLIC(Vwwf,astfwwi) (Vwwi z);

PUBLIC(Vdhf,astfdhu) (Vdhu z);
PUBLIC(Vdhf,astfdhi) (Vdhi z);
PUBLIC(Vdwf,astfdwu) (Vdwu z);
PUBLIC(Vdwf,astfdwi) (Vdwi z);
PUBLIC(Vddf,astfddu) (Vddu z);
PUBLIC(Vddf,astfddi) (Vddi z);

PUBLIC(Vqhf,astfqhu) (Vqhu z);
PUBLIC(Vqhf,astfqhi) (Vqhi z);
PUBLIC(Vqwf,astfqwu) (Vqwu z);
PUBLIC(Vqwf,astfqwi) (Vqwi z);
PUBLIC(Vqdf,astfqdu) (Vqdu z);
PUBLIC(Vqdf,astfqdi) (Vqdi z);

PUBLIC(flt16_t,astfhu) (uint16_t z) {return UINT16_ASTF(z);}
PUBLIC(flt16_t,astfhi) ( int16_t z) {return  INT16_ASTF(z);}
PUBLIC(  float,astfwu) (uint32_t z) {return UINT32_ASTF(z);}
PUBLIC(  float,astfwi) ( int32_t z) {return  INT32_ASTF(z);}
PUBLIC( double,astfdu) (uint64_t z) {return UINT64_ASTF(z);}
PUBLIC( double,astfdi) ( int64_t z) {return  INT64_ASTF(z);}
#if DWRD_NLONG == 2
PUBLIC(  float,astflu) (   ulong z) {return  ULONG_ASTF(z);}
PUBLIC(  float,astfli) (    long z) {return   LONG_ASTF(z);}
#elif QUAD_NLLONG == 2
PUBLIC( double,astflu) (  ullong z) {return ULLONG_ASTF(z);}
PUBLIC( double,astfli) (   llong z) {return  LLONG_ASTF(z);}
#endif

PUBLIC(Vwhf,astfwhu) (Vwhu z) {return VWHU_ASTF(z);}
PUBLIC(Vwhf,astfwhi) (Vwhi z) {return VWHI_ASTF(z);}
PUBLIC(Vwwf,astfwwu) (Vwwu z) {return VWWU_ASTF(z);}
PUBLIC(Vwwf,astfwwi) (Vwwi z) {return VWWI_ASTF(z);}

PUBLIC(Vdhf,astfdhu) (Vdhu z) {return VDHU_ASTF(z);}
PUBLIC(Vdhf,astfdhi) (Vdhi z) {return VDHI_ASTF(z);}
PUBLIC(Vdwf,astfdwu) (Vdwu z) {return VDWU_ASTF(z);}
PUBLIC(Vdwf,astfdwi) (Vdwi z) {return VDWI_ASTF(z);}
PUBLIC(Vddf,astfddu) (Vddu z) {return VDDU_ASTF(z);}
PUBLIC(Vddf,astfddi) (Vddi z) {return VDDI_ASTF(z);}

PUBLIC(Vqhf,astfqhu) (Vqhu z) {return VQHU_ASTF(z);}
PUBLIC(Vqhf,astfqhi) (Vqhi z) {return VQHI_ASTF(z);}
PUBLIC(Vqwf,astfqwu) (Vqwu z) {return VQWU_ASTF(z);}
PUBLIC(Vqwf,astfqwi) (Vqwi z) {return VQWI_ASTF(z);}
PUBLIC(Vqdf,astfqdu) (Vqdu z) {return VQDU_ASTF(z);}
PUBLIC(Vqdf,astfqdi) (Vqdi z) {return VQDI_ASTF(z);}


#define     astfhu    UINT16_ASTF
#define     astfhi     INT16_ASTF
#define     astfwu    UINT32_ASTF
#define     astfwi     INT32_ASTF
#define     astfdu    UINT64_ASTF
#define     astfdi     INT64_ASTF
#if DWRD_NLONG == 2
#   define  astflu     ULONG_ASTF
#   define  astfli      LONG_ASTF
#elif QUAD_NLLONG == 2
#   define  astflu    ULLONG_ASTF
#   define  astfli     LLONG_ASTF
#endif

#define     astfwhu     VWHU_ASTF
#define     astfwhi     VWHI_ASTF
#define     astfwwu     VWWU_ASTF
#define     astfwwi     VWWI_ASTF

#define     astfdhu     VDHU_ASTF
#define     astfdhi     VDHI_ASTF
#define     astfdwu     VDWU_ASTF
#define     astfdwi     VDWI_ASTF
#define     astfddu     VDDU_ASTF
#define     astfddi     VDDI_ASTF

#define     astfqhu     VQHU_ASTF
#define     astfqhi     VQHI_ASTF
#define     astfqwu     VQWU_ASTF
#define     astfqwi     VQWI_ASTF
#define     astfqdu     VQDU_ASTF
#define     astfqdi     VQDI_ASTF

#if _LEAVE_ASTF
}
#endif

#if _LEAVE_AST_
}
#endif

#if _ENTER_ASYU
{
#endif

PUBLIC(Vwyu,asyuwyu) (Vwyu x);
PUBLIC(Vwyu,asyuwbu) (Vwbu x);
PUBLIC(Vwyu,asyuwbi) (Vwbi x);
PUBLIC(Vwyu,asyuwbc) (Vwbc x);
PUBLIC(Vwyu,asyuwhu) (Vwhu x);
PUBLIC(Vwyu,asyuwhi) (Vwhi x);
PUBLIC(Vwyu,asyuwhf) (Vwhf x);
PUBLIC(Vwyu,asyuwwu) (Vwwu x);
PUBLIC(Vwyu,asyuwwi) (Vwwi x);
PUBLIC(Vwyu,asyuwwf) (Vwwf x);

PUBLIC(Vdyu,asyudyu) (Vdyu x);
PUBLIC(Vdyu,asyudbu) (Vdbu x);
PUBLIC(Vdyu,asyudbi) (Vdbi x);
PUBLIC(Vdyu,asyudbc) (Vdbc x);
PUBLIC(Vdyu,asyudhu) (Vdhu x);
PUBLIC(Vdyu,asyudhi) (Vdhi x);
PUBLIC(Vdyu,asyudhf) (Vdhf x);
PUBLIC(Vdyu,asyudwu) (Vdwu x);
PUBLIC(Vdyu,asyudwi) (Vdwi x);
PUBLIC(Vdyu,asyudwf) (Vdwf x);
PUBLIC(Vdyu,asyuddu) (Vddu x);
PUBLIC(Vdyu,asyuddi) (Vddi x);
PUBLIC(Vdyu,asyuddf) (Vddf x);

PUBLIC(Vqyu,asyuqyu) (Vqyu x);
PUBLIC(Vqyu,asyuqbu) (Vqbu x);
PUBLIC(Vqyu,asyuqbi) (Vqbi x);
PUBLIC(Vqyu,asyuqbc) (Vqbc x);
PUBLIC(Vqyu,asyuqhu) (Vqhu x);
PUBLIC(Vqyu,asyuqhi) (Vqhi x);
PUBLIC(Vqyu,asyuqhf) (Vqhf x);
PUBLIC(Vqyu,asyuqwu) (Vqwu x);
PUBLIC(Vqyu,asyuqwi) (Vqwi x);
PUBLIC(Vqyu,asyuqwf) (Vqwf x);
PUBLIC(Vqyu,asyuqdu) (Vqdu x);
PUBLIC(Vqyu,asyuqdi) (Vqdi x);
PUBLIC(Vqyu,asyuqdf) (Vqdf x);

#if 0
#define     asyu_funcof(X)  \
FUNCOF(                     \
    asyu,   (   X   ),      \
    NONE,   /* TGK */       \
    BWR,    /* TGW */       \
    BDR,    /* TGD */       \
    BDR,    /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGO */       \
    Vwyu:asyuwyu,           \
    Vdyu:asyudyu,           \
    Vqyu:asyuqyu,           \
    default: NULL           \
)
#endif
#define     asyu_funcof(X)  \
FUNCOF(                     \
    asyu,   (   X   ),      \
    NONE,   /* TGK */       \
    YWR,    /* TGW */       \
    YDR,    /* TGD */       \
    YDR,    /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGO */       \
    default: NULL           \
)
#define     astv(X) (astv_funcof(X)(X))

PUBLIC(Vwyu,asyuwyu) (Vwyu x) {return x;}
PUBLIC(Vwyu,asyuwbu) (Vwbu x) {return VWBU_ASYU(x);}
PUBLIC(Vwyu,asyuwbi) (Vwbi x) {return VWBI_ASYU(x);}
PUBLIC(Vwyu,asyuwbc) (Vwbc x) {return VWBC_ASYU(x);}
PUBLIC(Vwyu,asyuwhu) (Vwhu x) {return VWHU_ASYU(x);}
PUBLIC(Vwyu,asyuwhi) (Vwhi x) {return VWHI_ASYU(x);}
PUBLIC(Vwyu,asyuwhf) (Vwhf x) {return VWHF_ASYU(x);}
PUBLIC(Vwyu,asyuwwu) (Vwwu x) {return VWWU_ASYU(x);}
PUBLIC(Vwyu,asyuwwi) (Vwwi x) {return VWWI_ASYU(x);}
PUBLIC(Vwyu,asyuwwf) (Vwwf x) {return VWWF_ASYU(x);}

PUBLIC(Vdyu,asyudyu) (Vdyu x) {return x;}
PUBLIC(Vdyu,asyudbu) (Vdbu x) {return VDBU_ASYU(x);}
PUBLIC(Vdyu,asyudbi) (Vdbi x) {return VDBI_ASYU(x);}
PUBLIC(Vdyu,asyudbc) (Vdbc x) {return VDBC_ASYU(x);}
PUBLIC(Vdyu,asyudhu) (Vdhu x) {return VDHU_ASYU(x);}
PUBLIC(Vdyu,asyudhi) (Vdhi x) {return VDHI_ASYU(x);}
PUBLIC(Vdyu,asyudhf) (Vdhf x) {return VDHF_ASYU(x);}
PUBLIC(Vdyu,asyudwu) (Vdwu x) {return VDWU_ASYU(x);}
PUBLIC(Vdyu,asyudwi) (Vdwi x) {return VDWI_ASYU(x);}
PUBLIC(Vdyu,asyudwf) (Vdwf x) {return VDWF_ASYU(x);}
PUBLIC(Vdyu,asyuddu) (Vddu x) {return VDDU_ASYU(x);}
PUBLIC(Vdyu,asyuddi) (Vddi x) {return VDDI_ASYU(x);}
PUBLIC(Vdyu,asyuddf) (Vddf x) {return VDDF_ASYU(x);}

PUBLIC(Vqyu,asyuqyu) (Vqyu x) {return x;}
PUBLIC(Vqyu,asyuqbu) (Vqbu x) {return VQBU_ASYU(x);}
PUBLIC(Vqyu,asyuqbi) (Vqbi x) {return VQBI_ASYU(x);}
PUBLIC(Vqyu,asyuqbc) (Vqbc x) {return VQBC_ASYU(x);}
PUBLIC(Vqyu,asyuqhu) (Vqhu x) {return VQHU_ASYU(x);}
PUBLIC(Vqyu,asyuqhi) (Vqhi x) {return VQHI_ASYU(x);}
PUBLIC(Vqyu,asyuqhf) (Vqhf x) {return VQHF_ASYU(x);}
PUBLIC(Vqyu,asyuqwu) (Vqwu x) {return VQWU_ASYU(x);}
PUBLIC(Vqyu,asyuqwi) (Vqwi x) {return VQWI_ASYU(x);}
PUBLIC(Vqyu,asyuqwf) (Vqwf x) {return VQWF_ASYU(x);}
PUBLIC(Vqyu,asyuqdu) (Vqdu x) {return VQDU_ASYU(x);}
PUBLIC(Vqyu,asyuqdi) (Vqdi x) {return VQDI_ASYU(x);}
PUBLIC(Vqyu,asyuqdf) (Vqdf x) {return VQDF_ASYU(x);}

#if _LEAVE_ASYU
}
#endif


#if _ENTER_ASBU
{
#endif

PUBLIC(uint8_t,asbubi) (int8_t x);
PUBLIC(uint8_t,asbubc) (char x);

PUBLIC(Vwbu,asbuwyu) (Vwyu x);
PUBLIC(Vwbu,asbuwbu) (Vwbu x);
PUBLIC(Vwbu,asbuwbi) (Vwbi x);
PUBLIC(Vwbu,asbuwbc) (Vwbc x);
PUBLIC(Vwbu,asbuwhu) (Vwhu x);
PUBLIC(Vwbu,asbuwhi) (Vwhi x);
PUBLIC(Vwbu,asbuwhf) (Vwhf x);
PUBLIC(Vwbu,asbuwwu) (Vwwu x);
PUBLIC(Vwbu,asbuwwi) (Vwwi x);
PUBLIC(Vwbu,asbuwwf) (Vwwf x);

PUBLIC(Vdbu,asbudyu) (Vdyu x);
PUBLIC(Vdbu,asbudbu) (Vdbu x);
PUBLIC(Vdbu,asbudbi) (Vdbi x);
PUBLIC(Vdbu,asbudbc) (Vdbc x);
PUBLIC(Vdbu,asbudhu) (Vdhu x);
PUBLIC(Vdbu,asbudhi) (Vdhi x);
PUBLIC(Vdbu,asbudhf) (Vdhf x);
PUBLIC(Vdbu,asbudwu) (Vdwu x);
PUBLIC(Vdbu,asbudwi) (Vdwi x);
PUBLIC(Vdbu,asbudwf) (Vdwf x);
PUBLIC(Vdbu,asbuddu) (Vddu x);
PUBLIC(Vdbu,asbuddi) (Vddi x);
PUBLIC(Vdbu,asbuddf) (Vddf x);

PUBLIC(Vqbu,asbuqyu) (Vqyu x);
PUBLIC(Vqbu,asbuqbu) (Vqbu x);
PUBLIC(Vqbu,asbuqbi) (Vqbi x);
PUBLIC(Vqbu,asbuqbc) (Vqbc x);
PUBLIC(Vqbu,asbuqhu) (Vqhu x);
PUBLIC(Vqbu,asbuqhi) (Vqhi x);
PUBLIC(Vqbu,asbuqhf) (Vqhf x);
PUBLIC(Vqbu,asbuqwu) (Vqwu x);
PUBLIC(Vqbu,asbuqwi) (Vqwi x);
PUBLIC(Vqbu,asbuqwf) (Vqwf x);
PUBLIC(Vqbu,asbuqdu) (Vqdu x);
PUBLIC(Vqbu,asbuqdi) (Vqdi x);
PUBLIC(Vqbu,asbuqdf) (Vqdf x);

#define     asbu_funcof(X)  \
FUNCOF(                     \
    asbu,   (   X   ),      \
    BR,     /* TGK */       \
    YWR,    /* TGW */       \
    YDR,    /* TGD */       \
    YDR,    /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGO */       \
    default: NULL           \
)
#define     asbu(X) (asbu_funcof(X)(X))

PUBLIC(uint8_t,asbubu) (uint8_t x) {return x;}
PUBLIC(uint8_t,asbubi) (int8_t x) {return INT8_ASBU(x);}
PUBLIC(uint8_t,asbubc) (char x) {return CHAR_ASBU(x);}

PUBLIC(Vwbu,asbuwyu) (Vwyu x) {return VWYU_ASBU(x);}
PUBLIC(Vwbu,asbuwbu) (Vwbu x) {return x;}
PUBLIC(Vwbu,asbuwbi) (Vwbi x) {return VWBI_ASBU(x);}
PUBLIC(Vwbu,asbuwbc) (Vwbc x) {return VWBC_ASBU(x);}
PUBLIC(Vwbu,asbuwhu) (Vwhu x) {return VWHU_ASBU(x);}
PUBLIC(Vwbu,asbuwhi) (Vwhi x) {return VWHI_ASBU(x);}
PUBLIC(Vwbu,asbuwhf) (Vwhf x) {return VWHF_ASBU(x);}
PUBLIC(Vwbu,asbuwwu) (Vwwu x) {return VWWU_ASBU(x);}
PUBLIC(Vwbu,asbuwwi) (Vwwi x) {return VWWI_ASBU(x);}
PUBLIC(Vwbu,asbuwwf) (Vwwf x) {return VWWF_ASBU(x);}

PUBLIC(Vdbu,asbudyu) (Vdyu x) {return VDYU_ASBU(x);}
PUBLIC(Vdbu,asbudbu) (Vdbu x) {return (x);}
PUBLIC(Vdbu,asbudbi) (Vdbi x) {return VDBI_ASBU(x);}
PUBLIC(Vdbu,asbudbc) (Vdbc x) {return VDBC_ASBU(x);}
PUBLIC(Vdbu,asbudhu) (Vdhu x) {return VDHU_ASBU(x);}
PUBLIC(Vdbu,asbudhi) (Vdhi x) {return VDHI_ASBU(x);}
PUBLIC(Vdbu,asbudhf) (Vdhf x) {return VDHF_ASBU(x);}
PUBLIC(Vdbu,asbudwu) (Vdwu x) {return VDWU_ASBU(x);}
PUBLIC(Vdbu,asbudwi) (Vdwi x) {return VDWI_ASBU(x);}
PUBLIC(Vdbu,asbudwf) (Vdwf x) {return VDWF_ASBU(x);}
PUBLIC(Vdbu,asbuddu) (Vddu x) {return VDDU_ASBU(x);}
PUBLIC(Vdbu,asbuddi) (Vddi x) {return VDDI_ASBU(x);}
PUBLIC(Vdbu,asbuddf) (Vddf x) {return VDDF_ASBU(x);}

PUBLIC(Vqbu,asbuqyu) (Vqyu x) {return VQYU_ASBU(x);}
PUBLIC(Vqbu,asbuqbu) (Vqbu x) {return (x);}
PUBLIC(Vqbu,asbuqbi) (Vqbi x) {return VQBI_ASBU(x);}
PUBLIC(Vqbu,asbuqbc) (Vqbc x) {return VQBC_ASBU(x);}
PUBLIC(Vqbu,asbuqhu) (Vqhu x) {return VQHU_ASBU(x);}
PUBLIC(Vqbu,asbuqhi) (Vqhi x) {return VQHI_ASBU(x);}
PUBLIC(Vqbu,asbuqhf) (Vqhf x) {return VQHF_ASBU(x);}
PUBLIC(Vqbu,asbuqwu) (Vqwu x) {return VQWU_ASBU(x);}
PUBLIC(Vqbu,asbuqwi) (Vqwi x) {return VQWI_ASBU(x);}
PUBLIC(Vqbu,asbuqwf) (Vqwf x) {return VQWF_ASBU(x);}
PUBLIC(Vqbu,asbuqdu) (Vqdu x) {return VQDU_ASBU(x);}
PUBLIC(Vqbu,asbuqdi) (Vqdi x) {return VQDI_ASBU(x);}
PUBLIC(Vqbu,asbuqdf) (Vqdf x) {return VQDF_ASBU(x);}

#if _LEAVE_ASBU
}
#endif

#if _ENTER_ASBI
{
#endif

PUBLIC(int8_t,asbibu) (uint8_t x);
PUBLIC(int8_t,asbibi) (int8_t x);
PUBLIC(int8_t,asbibc) (char x);

PUBLIC(Vwbi,asbiwyu) (Vwyu x);
PUBLIC(Vwbi,asbiwbu) (Vwbu x);
PUBLIC(Vwbi,asbiwbi) (Vwbi x);
PUBLIC(Vwbi,asbiwbc) (Vwbc x);
PUBLIC(Vwbi,asbiwhu) (Vwhu x);
PUBLIC(Vwbi,asbiwhi) (Vwhi x);
PUBLIC(Vwbi,asbiwhf) (Vwhf x);
PUBLIC(Vwbi,asbiwwu) (Vwwu x);
PUBLIC(Vwbi,asbiwwi) (Vwwi x);
PUBLIC(Vwbi,asbiwwf) (Vwwf x);

PUBLIC(Vdbi,asbidyu) (Vdyu x);
PUBLIC(Vdbi,asbidbu) (Vdbu x);
PUBLIC(Vdbi,asbidbi) (Vdbi x);
PUBLIC(Vdbi,asbidbc) (Vdbc x);
PUBLIC(Vdbi,asbidhu) (Vdhu x);
PUBLIC(Vdbi,asbidhi) (Vdhi x);
PUBLIC(Vdbi,asbidhf) (Vdhf x);
PUBLIC(Vdbi,asbidwu) (Vdwu x);
PUBLIC(Vdbi,asbidwi) (Vdwi x);
PUBLIC(Vdbi,asbidwf) (Vdwf x);
PUBLIC(Vdbi,asbiddu) (Vddu x);
PUBLIC(Vdbi,asbiddi) (Vddi x);
PUBLIC(Vdbi,asbiddf) (Vddf x);

PUBLIC(Vqbi,asbiqyu) (Vqyu x);
PUBLIC(Vqbi,asbiqbu) (Vqbu x);
PUBLIC(Vqbi,asbiqbi) (Vqbi x);
PUBLIC(Vqbi,asbiqbc) (Vqbc x);
PUBLIC(Vqbi,asbiqhu) (Vqhu x);
PUBLIC(Vqbi,asbiqhi) (Vqhi x);
PUBLIC(Vqbi,asbiqhf) (Vqhf x);
PUBLIC(Vqbi,asbiqwu) (Vqwu x);
PUBLIC(Vqbi,asbiqwi) (Vqwi x);
PUBLIC(Vqbi,asbiqwf) (Vqwf x);
PUBLIC(Vqbi,asbiqdu) (Vqdu x);
PUBLIC(Vqbi,asbiqdi) (Vqdi x);
PUBLIC(Vqbi,asbiqdf) (Vqdf x);

#define     asbi_funcof(X)  \
FUNCOF(                     \
    asbi,   (   X   ),      \
    BR,     /* TGK */       \
    YWR,    /* TGW */       \
    YDR,    /* TGD */       \
    YDR,    /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGO */       \
    default: NULL           \
)
#define     asbi(X) (asbi_funcof(X)(X))

#if 0
#if defined(_MSC_VER)
#   define  asbi_funcof(X)      \
_Generic(                       \
    (X),                        \
    TGW_YU(asbi) TGW_HWR(asbi)  \
    TGD_YU(asbi) TGD_HDR(asbi)  \
    TGQ_YU(asbi) TGQ_HDR(asbi)  \
    uint8_t: asbibu,            \
    Vwbu:asbiwbu,Vwbc:asbiwbc,  \
    Vdbu:asbidbu,Vdbc:asbidbc,  \
    Vqbu:asbiqbu,Vqbc:asbiqbc,  \
    default: NULL               \
)
#else
#define  asbi_funcof(X)         \
_Generic(                       \
    (X),                        \
    TGW_YU(asbi) TGW_HWR(asbi)  \
    TGD_YU(asbi) TGD_HDR(asbi)  \
    TGQ_YU(asbi) TGQ_HDR(asbi)  \
    char:      asbibc,          \
    uint8_t:   asbibu,          \
    Vwbi:asbiwbu,Vwbc:asbiwbc,  \
    Vdbi:asbidbu,Vdbc:asbidbc,  \
    Vqbi:asbiqbu,Vqbc:asbiqbc,  \
    default: NULL               \
)
#endif
#endif

#define     asbi(X) (asbi_funcof(X)(X))

PUBLIC(int8_t,asbibu) (uint8_t x) {return UINT8_ASBI(x);}
PUBLIC(int8_t,asbibi) (int8_t x) {return (x);}
PUBLIC(int8_t,asbibc) (char x) {return CHAR_ASBI(x);}

PUBLIC(Vwbi,asbiwyu) (Vwyu x) {return VWYU_ASBI(x);}
PUBLIC(Vwbi,asbiwbu) (Vwbu x) {return VWBU_ASBI(x);}
PUBLIC(Vwbi,asbiwbi) (Vwbi x) {return (x);}
PUBLIC(Vwbi,asbiwbc) (Vwbc x) {return VWBC_ASBI(x);}
PUBLIC(Vwbi,asbiwhu) (Vwhu x) {return VWHU_ASBI(x);}
PUBLIC(Vwbi,asbiwhi) (Vwhi x) {return VWHI_ASBI(x);}
PUBLIC(Vwbi,asbiwhf) (Vwhf x) {return VWHF_ASBI(x);}
PUBLIC(Vwbi,asbiwwu) (Vwwu x) {return VWWU_ASBI(x);}
PUBLIC(Vwbi,asbiwwi) (Vwwi x) {return VWWI_ASBI(x);}
PUBLIC(Vwbi,asbiwwf) (Vwwf x) {return VWWF_ASBI(x);}

PUBLIC(Vdbi,asbidyu) (Vdyu x) {return VDYU_ASBI(x);}
PUBLIC(Vdbi,asbidbu) (Vdbu x) {return VDBU_ASBI(x);}
PUBLIC(Vdbi,asbidbi) (Vdbi x) {return (x);}
PUBLIC(Vdbi,asbidbc) (Vdbc x) {return VDBC_ASBI(x);}
PUBLIC(Vdbi,asbidhu) (Vdhu x) {return VDHU_ASBI(x);}
PUBLIC(Vdbi,asbidhi) (Vdhi x) {return VDHI_ASBI(x);}
PUBLIC(Vdbi,asbidhf) (Vdhf x) {return VDHF_ASBI(x);}
PUBLIC(Vdbi,asbidwu) (Vdwu x) {return VDWU_ASBI(x);}
PUBLIC(Vdbi,asbidwi) (Vdwi x) {return VDWI_ASBI(x);}
PUBLIC(Vdbi,asbidwf) (Vdwf x) {return VDWF_ASBI(x);}
PUBLIC(Vdbi,asbiddu) (Vddu x) {return VDDU_ASBI(x);}
PUBLIC(Vdbi,asbiddi) (Vddi x) {return VDDI_ASBI(x);}
PUBLIC(Vdbi,asbiddf) (Vddf x) {return VDDF_ASBI(x);}

PUBLIC(Vqbi,asbiqyu) (Vqyu x) {return VQYU_ASBI(x);}
PUBLIC(Vqbi,asbiqbu) (Vqbu x) {return VQBU_ASBI(x);}
PUBLIC(Vqbi,asbiqbi) (Vqbi x) {return (x);}
PUBLIC(Vqbi,asbiqbc) (Vqbc x) {return VQBC_ASBI(x);}
PUBLIC(Vqbi,asbiqhu) (Vqhu x) {return VQHU_ASBI(x);}
PUBLIC(Vqbi,asbiqhi) (Vqhi x) {return VQHI_ASBI(x);}
PUBLIC(Vqbi,asbiqhf) (Vqhf x) {return VQHF_ASBI(x);}
PUBLIC(Vqbi,asbiqwu) (Vqwu x) {return VQWU_ASBI(x);}
PUBLIC(Vqbi,asbiqwi) (Vqwi x) {return VQWI_ASBI(x);}
PUBLIC(Vqbi,asbiqwf) (Vqwf x) {return VQWF_ASBI(x);}
PUBLIC(Vqbi,asbiqdu) (Vqdu x) {return VQDU_ASBI(x);}
PUBLIC(Vqbi,asbiqdi) (Vqdi x) {return VQDI_ASBI(x);}
PUBLIC(Vqbi,asbiqdf) (Vqdf x) {return VQDF_ASBI(x);}

#if _ENTER_ASBI
{
#endif


#if _ENTER_ASBC
{
#endif

PUBLIC(char,asbcbu) (uint8_t x);
PUBLIC(char,asbcbi) ( int8_t x);
PUBLIC(char,asbcbc) (   char x);

PUBLIC(Vwbc,asbcwyu) (Vwyu x);
PUBLIC(Vwbc,asbcwbu) (Vwbu x);
PUBLIC(Vwbc,asbcwbi) (Vwbi x);
PUBLIC(Vwbc,asbcwbc) (Vwbc x);
PUBLIC(Vwbc,asbcwhu) (Vwhu x);
PUBLIC(Vwbc,asbcwhi) (Vwhi x);
PUBLIC(Vwbc,asbcwhf) (Vwhf x);
PUBLIC(Vwbc,asbcwwu) (Vwwu x);
PUBLIC(Vwbc,asbcwwi) (Vwwi x);
PUBLIC(Vwbc,asbcwwf) (Vwwf x);

PUBLIC(Vdbc,asbcdyu) (Vdyu x);
PUBLIC(Vdbc,asbcdbu) (Vdbu x);
PUBLIC(Vdbc,asbcdbi) (Vdbi x);
PUBLIC(Vdbc,asbcdbc) (Vdbc x);
PUBLIC(Vdbc,asbcdhu) (Vdhu x);
PUBLIC(Vdbc,asbcdhi) (Vdhi x);
PUBLIC(Vdbc,asbcdhf) (Vdhf x);
PUBLIC(Vdbc,asbcdwu) (Vdwu x);
PUBLIC(Vdbc,asbcdwi) (Vdwi x);
PUBLIC(Vdbc,asbcdwf) (Vdwf x);
PUBLIC(Vdbc,asbcddu) (Vddu x);
PUBLIC(Vdbc,asbcddi) (Vddi x);
PUBLIC(Vdbc,asbcddf) (Vddf x);

PUBLIC(Vqbc,asbcqyu) (Vqyu x);
PUBLIC(Vqbc,asbcqbu) (Vqbu x);
PUBLIC(Vqbc,asbcqbi) (Vqbi x);
PUBLIC(Vqbc,asbcqbc) (Vqbc x);
PUBLIC(Vqbc,asbcqhu) (Vqhu x);
PUBLIC(Vqbc,asbcqhi) (Vqhi x);
PUBLIC(Vqbc,asbcqhf) (Vqhf x);
PUBLIC(Vqbc,asbcqwu) (Vqwu x);
PUBLIC(Vqbc,asbcqwi) (Vqwi x);
PUBLIC(Vqbc,asbcqwf) (Vqwf x);
PUBLIC(Vqbc,asbcqdu) (Vqdu x);
PUBLIC(Vqbc,asbcqdi) (Vqdi x);
PUBLIC(Vqbc,asbcqdf) (Vqdf x);
#if 0
#define  asbc_funcof(X)         \
_Generic(                       \
    (X),                        \
    TGW_YU(asbc) TGW_HWR(asbc)  \
    TGD_YU(asbc) TGD_HDR(asbc)  \
    TGQ_YU(asbc) TGQ_HDR(asbc)  \
    uint8_t: asbcbu,            \
    int8_t:  asbcbi,            \
    Vwbu:asbcwbu,Vwbi:asbcwbi,  \
    Vdbu:asbcdbu,Vdbi:asbcdbi,  \
    Vqbu:asbcqbu,Vqbi:asbcqbi,  \
    default: NULL               \
)
#endif

#define     asbc_funcof(X)  \
FUNCOF(                     \
    asbc,   (   X   ),      \
    BR,     /* TGK */       \
    YWR,    /* TGW */       \
    YDR,    /* TGD */       \
    YDR,    /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGO */       \
    default: NULL           \
)
#define     asbc(X) (asbc_funcof(X)(X))

PUBLIC(char,asbcbu) (uint8_t x) {return UINT8_ASBC(x);}
PUBLIC(char,asbcbi) ( int8_t x) {return  INT8_ASBC(x);}
PUBLIC(char,asbcbc) (   char x) {return  (x);}

PUBLIC(Vwbc,asbcwyu) (Vwyu x) {return VWYU_ASBC(x);}
PUBLIC(Vwbc,asbcwbu) (Vwbu x) {return VWBU_ASBC(x);}
PUBLIC(Vwbc,asbcwbi) (Vwbi x) {return VWBI_ASBC(x);}
PUBLIC(Vwbc,asbcwbc) (Vwbc x) {return (x);}
PUBLIC(Vwbc,asbcwhu) (Vwhu x) {return VWHU_ASBC(x);}
PUBLIC(Vwbc,asbcwhi) (Vwhi x) {return VWHI_ASBC(x);}
PUBLIC(Vwbc,asbcwhf) (Vwhf x) {return VWHF_ASBC(x);}
PUBLIC(Vwbc,asbcwwu) (Vwwu x) {return VWWU_ASBC(x);}
PUBLIC(Vwbc,asbcwwi) (Vwwi x) {return VWWI_ASBC(x);}
PUBLIC(Vwbc,asbcwwf) (Vwwf x) {return VWWF_ASBC(x);}

PUBLIC(Vdbc,asbcdyu) (Vdyu x) {return VDYU_ASBC(x);}
PUBLIC(Vdbc,asbcdbu) (Vdbu x) {return VDBU_ASBC(x);}
PUBLIC(Vdbc,asbcdbi) (Vdbi x) {return VDBI_ASBC(x);}
PUBLIC(Vdbc,asbcdbc) (Vdbc x) {return (x);}
PUBLIC(Vdbc,asbcdhu) (Vdhu x) {return VDHU_ASBC(x);}
PUBLIC(Vdbc,asbcdhi) (Vdhi x) {return VDHI_ASBC(x);}
PUBLIC(Vdbc,asbcdhf) (Vdhf x) {return VDHF_ASBC(x);}
PUBLIC(Vdbc,asbcdwu) (Vdwu x) {return VDWU_ASBC(x);}
PUBLIC(Vdbc,asbcdwi) (Vdwi x) {return VDWI_ASBC(x);}
PUBLIC(Vdbc,asbcdwf) (Vdwf x) {return VDWF_ASBC(x);}
PUBLIC(Vdbc,asbcddu) (Vddu x) {return VDDU_ASBC(x);}
PUBLIC(Vdbc,asbcddi) (Vddi x) {return VDDI_ASBC(x);}
PUBLIC(Vdbc,asbcddf) (Vddf x) {return VDDF_ASBC(x);}

PUBLIC(Vqbc,asbcqyu) (Vqyu x) {return VQYU_ASBC(x);}
PUBLIC(Vqbc,asbcqbu) (Vqbu x) {return VQBU_ASBC(x);}
PUBLIC(Vqbc,asbcqbi) (Vqbi x) {return VQBI_ASBC(x);}
PUBLIC(Vqbc,asbcqbc) (Vqbc x) {return (x);}
PUBLIC(Vqbc,asbcqhu) (Vqhu x) {return VQHU_ASBC(x);}
PUBLIC(Vqbc,asbcqhi) (Vqhi x) {return VQHI_ASBC(x);}
PUBLIC(Vqbc,asbcqhf) (Vqhf x) {return VQHF_ASBC(x);}
PUBLIC(Vqbc,asbcqwu) (Vqwu x) {return VQWU_ASBC(x);}
PUBLIC(Vqbc,asbcqwi) (Vqwi x) {return VQWI_ASBC(x);}
PUBLIC(Vqbc,asbcqwf) (Vqwf x) {return VQWF_ASBC(x);}
PUBLIC(Vqbc,asbcqdu) (Vqdu x) {return VQDU_ASBC(x);}
PUBLIC(Vqbc,asbcqdi) (Vqdi x) {return VQDI_ASBC(x);}
PUBLIC(Vqbc,asbcqdf) (Vqdf x) {return VQDF_ASBC(x);}

#if _LEAVE_ASBC
}
#endif


#if _ENTER_ASHU
{
#endif

PUBLIC(uint16_t,ashuhu) (uint16_t x);
PUBLIC(uint16_t,ashuhi) ( int16_t x);
PUBLIC(uint16_t,ashuhf) ( flt16_t x);

PUBLIC(Vwhu,ashuwyu) (Vwyu x);
PUBLIC(Vwhu,ashuwbu) (Vwbu x);
PUBLIC(Vwhu,ashuwbi) (Vwbi x);
PUBLIC(Vwhu,ashuwbc) (Vwbc x);
PUBLIC(Vwhu,ashuwhu) (Vwhu x);
PUBLIC(Vwhu,ashuwhi) (Vwhi x);
PUBLIC(Vwhu,ashuwhf) (Vwhf x);
PUBLIC(Vwhu,ashuwwu) (Vwwu x);
PUBLIC(Vwhu,ashuwwi) (Vwwi x);
PUBLIC(Vwhu,ashuwwf) (Vwwf x);

PUBLIC(Vdhu,ashudyu) (Vdyu x);
PUBLIC(Vdhu,ashudbu) (Vdbu x);
PUBLIC(Vdhu,ashudbi) (Vdbi x);
PUBLIC(Vdhu,ashudbc) (Vdbc x);
PUBLIC(Vdhu,ashudhu) (Vdhu x);
PUBLIC(Vdhu,ashudhi) (Vdhi x);
PUBLIC(Vdhu,ashudhf) (Vdhf x);
PUBLIC(Vdhu,ashudwu) (Vdwu x);
PUBLIC(Vdhu,ashudwi) (Vdwi x);
PUBLIC(Vdhu,ashudwf) (Vdwf x);
PUBLIC(Vdhu,ashuddu) (Vddu x);
PUBLIC(Vdhu,ashuddi) (Vddi x);
PUBLIC(Vdhu,ashuddf) (Vddf x);

PUBLIC(Vqhu,ashuqyu) (Vqyu x);
PUBLIC(Vqhu,ashuqbu) (Vqbu x);
PUBLIC(Vqhu,ashuqbi) (Vqbi x);
PUBLIC(Vqhu,ashuqbc) (Vqbc x);
PUBLIC(Vqhu,ashuqhu) (Vqhu x);
PUBLIC(Vqhu,ashuqhi) (Vqhi x);
PUBLIC(Vqhu,ashuqhf) (Vqhf x);
PUBLIC(Vqhu,ashuqwu) (Vqwu x);
PUBLIC(Vqhu,ashuqwi) (Vqwi x);
PUBLIC(Vqhu,ashuqwf) (Vqwf x);
PUBLIC(Vqhu,ashuqdu) (Vqdu x);
PUBLIC(Vqhu,ashuqdi) (Vqdi x);
PUBLIC(Vqhu,ashuqdf) (Vqdf x);
#if 0
#define  ashu_funcof(X) \
_Generic(               \
    (X),                \
    TGK_HS( ashu)       \
    TGW_YBR(ashu) TGW_HS(ashu) TGW_WR( ashu)\
    TGD_YBR(ashu) TGD_HS(ashu) TGD_WDR(ashu)\
    TGQ_YBR(ashu) TGQ_HS(ashu) TGQ_WDR(ashu)\
    default: NULL       \
)
#endif
#define     ashu_funcof(X)  \
FUNCOF(                     \
    ashu,   (   X   ),      \
    HR,     /* TGK */       \
    YWR,    /* TGW */       \
    YDR,    /* TGD */       \
    YDR,    /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGO */       \
    default: NULL           \
)
#define     ashu(X) (ashu_funcof(X)(X))

PUBLIC(uint16_t,ashuhu) (uint16_t x) {return (x);}
PUBLIC(uint16_t,ashuhi) (int16_t x) {return INT16_ASHU(x);}
PUBLIC(uint16_t,ashuhf) (flt16_t x) {return FLT16_ASHU(x);}

PUBLIC(Vwhu,ashuwyu) (Vwyu x) {return VWYU_ASHU(x);}
PUBLIC(Vwhu,ashuwbu) (Vwbu x) {return VWBU_ASHU(x);}
PUBLIC(Vwhu,ashuwbi) (Vwbi x) {return VWBI_ASHU(x);}
PUBLIC(Vwhu,ashuwbc) (Vwbc x) {return VWBC_ASHU(x);}
PUBLIC(Vwhu,ashuwhu) (Vwhu x) {return (x);}
PUBLIC(Vwhu,ashuwhi) (Vwhi x) {return VWHI_ASHU(x);}
PUBLIC(Vwhu,ashuwhf) (Vwhf x) {return VWHF_ASHU(x);}
PUBLIC(Vwhu,ashuwwu) (Vwwu x) {return VWWU_ASHU(x);}
PUBLIC(Vwhu,ashuwwi) (Vwwi x) {return VWWI_ASHU(x);}
PUBLIC(Vwhu,ashuwwf) (Vwwf x) {return VWWF_ASHU(x);}

PUBLIC(Vdhu,ashudyu) (Vdyu x) {return VDYU_ASHU(x);}
PUBLIC(Vdhu,ashudbu) (Vdbu x) {return VDBU_ASHU(x);}
PUBLIC(Vdhu,ashudbi) (Vdbi x) {return VDBI_ASHU(x);}
PUBLIC(Vdhu,ashudbc) (Vdbc x) {return VDBC_ASHU(x);}
PUBLIC(Vdhu,ashudhu) (Vdhu x) {return (x);}
PUBLIC(Vdhu,ashudhi) (Vdhi x) {return VDHI_ASHU(x);}
PUBLIC(Vdhu,ashudhf) (Vdhf x) {return VDHF_ASHU(x);}
PUBLIC(Vdhu,ashudwu) (Vdwu x) {return VDWU_ASHU(x);}
PUBLIC(Vdhu,ashudwi) (Vdwi x) {return VDWI_ASHU(x);}
PUBLIC(Vdhu,ashudwf) (Vdwf x) {return VDWF_ASHU(x);}
PUBLIC(Vdhu,ashuddu) (Vddu x) {return VDDU_ASHU(x);}
PUBLIC(Vdhu,ashuddi) (Vddi x) {return VDDI_ASHU(x);}
PUBLIC(Vdhu,ashuddf) (Vddf x) {return VDDF_ASHU(x);}

PUBLIC(Vqhu,ashuqyu) (Vqyu x) {return VQYU_ASHU(x);}
PUBLIC(Vqhu,ashuqbu) (Vqbu x) {return VQBU_ASHU(x);}
PUBLIC(Vqhu,ashuqbi) (Vqbi x) {return VQBI_ASHU(x);}
PUBLIC(Vqhu,ashuqbc) (Vqbc x) {return VQBC_ASHU(x);}
PUBLIC(Vqhu,ashuqhu) (Vqhu x) {return (x);}
PUBLIC(Vqhu,ashuqhi) (Vqhi x) {return VQHI_ASHU(x);}
PUBLIC(Vqhu,ashuqhf) (Vqhf x) {return VQHF_ASHU(x);}
PUBLIC(Vqhu,ashuqwu) (Vqwu x) {return VQWU_ASHU(x);}
PUBLIC(Vqhu,ashuqwi) (Vqwi x) {return VQWI_ASHU(x);}
PUBLIC(Vqhu,ashuqwf) (Vqwf x) {return VQWF_ASHU(x);}
PUBLIC(Vqhu,ashuqdu) (Vqdu x) {return VQDU_ASHU(x);}
PUBLIC(Vqhu,ashuqdi) (Vqdi x) {return VQDI_ASHU(x);}
PUBLIC(Vqhu,ashuqdf) (Vqdf x) {return VQDF_ASHU(x);}

#if _LEAVE_ASHU
}
#endif

#if _ENTER_ASHI
{
#endif
// ashi:
PUBLIC(int16_t, ashihu)(uint16_t a);
PUBLIC(int16_t, ashihf)(flt16_t a);

PUBLIC(Vwhi, ashiwyu)(Vwyu a);
PUBLIC(Vwhi, ashiwbu)(Vwbu a);
PUBLIC(Vwhi, ashiwbi)(Vwbi a);
PUBLIC(Vwhi, ashiwbc)(Vwbc a);
PUBLIC(Vwhi, ashiwhu)(Vwhu a);
PUBLIC(Vwhi, ashiwhi)(Vwhi a);
PUBLIC(Vwhi, ashiwhf)(Vwhf a);
PUBLIC(Vwhi, ashiwwu)(Vwwu a);
PUBLIC(Vwhi, ashiwwi)(Vwwi a);
PUBLIC(Vwhi, ashiwwf)(Vwwf a);

PUBLIC(Vdhi, ashidyu)(Vdyu a);
PUBLIC(Vdhi, ashidbu)(Vdbu a);
PUBLIC(Vdhi, ashidbi)(Vdbi a);
PUBLIC(Vdhi, ashidbc)(Vdbc a);
PUBLIC(Vdhi, ashidhu)(Vdhu a);
PUBLIC(Vdhi, ashidhi)(Vdhi a);
PUBLIC(Vdhi, ashidhf)(Vdhf a);
PUBLIC(Vdhi, ashidwu)(Vdwu a);
PUBLIC(Vdhi, ashidwi)(Vdwi a);
PUBLIC(Vdhi, ashidwf)(Vdwf a);
PUBLIC(Vdhi, ashiddu)(Vddu a);
PUBLIC(Vdhi, ashiddi)(Vddi a);
PUBLIC(Vdhi, ashiddf)(Vddf a);

PUBLIC(Vqhi, ashiqyu)(Vqyu a);
PUBLIC(Vqhi, ashiqbu)(Vqbu a);
PUBLIC(Vqhi, ashiqbi)(Vqbi a);
PUBLIC(Vqhi, ashiqbc)(Vqbc a);
PUBLIC(Vqhi, ashiqhu)(Vqhu a);
PUBLIC(Vqhi, ashiqhi)(Vqhi a);
PUBLIC(Vqhi, ashiqhf)(Vqhf a);
PUBLIC(Vqhi, ashiqwu)(Vqwu a);
PUBLIC(Vqhi, ashiqwi)(Vqwi a);
PUBLIC(Vqhi, ashiqwf)(Vqwf a);
PUBLIC(Vqhi, ashiqdu)(Vqdu a);
PUBLIC(Vqhi, ashiqdi)(Vqdi a);
PUBLIC(Vqhi, ashiqdf)(Vqdf a);

#if _LEAVE_ASHI
}
#endif


#if _ENTER_ASHF
{
#endif

// ashf:
PUBLIC(flt16_t, ashfhu)(uint16_t a);
PUBLIC(flt16_t, ashfhi)(int16_t a);

PUBLIC(Vwhf, ashfwyu)(Vwyu a);
PUBLIC(Vwhf, ashfwbu)(Vwbu a);
PUBLIC(Vwhf, ashfwbi)(Vwbi a);
PUBLIC(Vwhf, ashfwbc)(Vwbc a);
PUBLIC(Vwhf, ashfwhu)(Vwhu a);
PUBLIC(Vwhf, ashfwhi)(Vwhi a);
PUBLIC(Vwhf, ashfwhf)(Vwhf a);
PUBLIC(Vwhf, ashfwwu)(Vwwu a);
PUBLIC(Vwhf, ashfwwi)(Vwwi a);
PUBLIC(Vwhf, ashfwwf)(Vwwf a);

PUBLIC(Vdhf, ashfdyu)(Vdyu a);
PUBLIC(Vdhf, ashfdbu)(Vdbu a);
PUBLIC(Vdhf, ashfdbi)(Vdbi a);
PUBLIC(Vdhf, ashfdbc)(Vdbc a);
PUBLIC(Vdhf, ashfdhu)(Vdhu a);
PUBLIC(Vdhf, ashfdhi)(Vdhi a);
PUBLIC(Vdhf, ashfdhf)(Vdhf a);
PUBLIC(Vdhf, ashfdwu)(Vdwu a);
PUBLIC(Vdhf, ashfdwi)(Vdwi a);
PUBLIC(Vdhf, ashfdwf)(Vdwf a);
PUBLIC(Vdhf, ashfddu)(Vddu a);
PUBLIC(Vdhf, ashfddi)(Vddi a);
PUBLIC(Vdhf, ashfddf)(Vddf a);

PUBLIC(Vqhf, ashfqyu)(Vqyu a);
PUBLIC(Vqhf, ashfqbu)(Vqbu a);
PUBLIC(Vqhf, ashfqbi)(Vqbi a);
PUBLIC(Vqhf, ashfqbc)(Vqbc a);
PUBLIC(Vqhf, ashfqhu)(Vqhu a);
PUBLIC(Vqhf, ashfqhi)(Vqhi a);
PUBLIC(Vqhf, ashfqhf)(Vqhf a);
PUBLIC(Vqhf, ashfqwu)(Vqwu a);
PUBLIC(Vqhf, ashfqwi)(Vqwi a);
PUBLIC(Vqhf, ashfqwf)(Vqwf a);
PUBLIC(Vqhf, ashfqdu)(Vqdu a);
PUBLIC(Vqhf, ashfqdi)(Vqdi a);
PUBLIC(Vqhf, ashfqdf)(Vqdf a);

#if _LEAVE_ASHF
}
#endif


#if _ENTER_ASWU
{
#endif
// aswu:
PUBLIC(uint32_t, aswuwi)(int32_t a);
PUBLIC(uint32_t, aswuwf)(float a);

PUBLIC(Vwwu, aswuwyu)(Vwyu a);
PUBLIC(Vwwu, aswuwbu)(Vwbu a);
PUBLIC(Vwwu, aswuwbi)(Vwbi a);
PUBLIC(Vwwu, aswuwbc)(Vwbc a);
PUBLIC(Vwwu, aswuwhu)(Vwhu a);
PUBLIC(Vwwu, aswuwhi)(Vwhi a);
PUBLIC(Vwwu, aswuwhf)(Vwhf a);
PUBLIC(Vwwu, aswuwwu)(Vwwu a);
PUBLIC(Vwwu, aswuwwi)(Vwwi a);
PUBLIC(Vwwu, aswuwwf)(Vwwf a);

PUBLIC(Vdwu, aswudyu)(Vdyu a);
PUBLIC(Vdwu, aswudbu)(Vdbu a);
PUBLIC(Vdwu, aswudbi)(Vdbi a);
PUBLIC(Vdwu, aswudbc)(Vdbc a);
PUBLIC(Vdwu, aswudhu)(Vdhu a);
PUBLIC(Vdwu, aswudhi)(Vdhi a);
PUBLIC(Vdwu, aswudhf)(Vdhf a);
PUBLIC(Vdwu, aswudwu)(Vdwu a);
PUBLIC(Vdwu, aswudwi)(Vdwi a);
PUBLIC(Vdwu, aswudwf)(Vdwf a);
PUBLIC(Vdwu, aswuddu)(Vddu a);
PUBLIC(Vdwu, aswuddi)(Vddi a);
PUBLIC(Vdwu, aswuddf)(Vddf a);

PUBLIC(Vqwu, aswuqbu)(Vqbu a);
PUBLIC(Vqwu, aswuqbi)(Vqbi a);
PUBLIC(Vqwu, aswuqhu)(Vqhu a);
PUBLIC(Vqwu, aswuqhi)(Vqhi a);
PUBLIC(Vqwu, aswuqhf)(Vqhf a);
PUBLIC(Vqwu, aswuqwu)(Vqwu a);
PUBLIC(Vqwu, aswuqwi)(Vqwi a);
PUBLIC(Vqwu, aswuqwf)(Vqwf a);
PUBLIC(Vqwu, aswuqdu)(Vqdu a);
PUBLIC(Vqwu, aswuqdi)(Vqdi a);
PUBLIC(Vqwu, aswuqdf)(Vqdf a);

#if _LEAVE_ASWU
}
#endif


#if _ENTER_ASWI
{
#endif

#if _LEAVE_ASWI
}
#endif


#if _ENTER_ASWF
{
#endif

#if _LEAVE_ASWF
}
#endif


#if _ENTER_ASDU
{
#endif

#if _LEAVE_ASDU
}
#endif


#if _ENTER_ASDI
{
#endif

#if _LEAVE_ASDI
}
#endif


#if _ENTER_ASDF
{
#endif

#if _LEAVE_ASDF
}
#endif



// aswi:
PUBLIC(int32_t, aswiwu)(uint32_t a);
PUBLIC(int32_t, aswiwf)(float a);

PUBLIC(Vwwi, aswiwyu)(Vwyu a);
PUBLIC(Vwwi, aswiwbu)(Vwbu a);
PUBLIC(Vwwi, aswiwbi)(Vwbi a);
PUBLIC(Vwwi, aswiwbc)(Vwbc a);
PUBLIC(Vwwi, aswiwhu)(Vwhu a);
PUBLIC(Vwwi, aswiwhi)(Vwhi a);
PUBLIC(Vwwi, aswiwhf)(Vwhf a);
PUBLIC(Vwwi, aswiwwu)(Vwwu a);
PUBLIC(Vwwi, aswiwwi)(Vwwi a);
PUBLIC(Vwwi, aswiwwf)(Vwwf a);

PUBLIC(Vdwi, aswidyu)(Vdyu a);
PUBLIC(Vdwi, aswidbu)(Vdbu a);
PUBLIC(Vdwi, aswidbi)(Vdbi a);
PUBLIC(Vdwi, aswidbc)(Vdbc a);
PUBLIC(Vdwi, aswidhu)(Vdhu a);
PUBLIC(Vdwi, aswidhi)(Vdhi a);
PUBLIC(Vdwi, aswidhf)(Vdhf a);
PUBLIC(Vdwi, aswidwu)(Vdwu a);
PUBLIC(Vdwi, aswidwi)(Vdwi a);
PUBLIC(Vdwi, aswidwf)(Vdwf a);
PUBLIC(Vdwi, aswiddu)(Vddu a);
PUBLIC(Vdwi, aswiddi)(Vddi a);
PUBLIC(Vdwi, aswiddf)(Vddf a);

PUBLIC(Vqwi, aswiqyu)(Vqyu a);
PUBLIC(Vqwi, aswiqbu)(Vqbu a);
PUBLIC(Vqwi, aswiqbi)(Vqbi a);
PUBLIC(Vqwi, aswiqbc)(Vqbc a);
PUBLIC(Vqwi, aswiqhu)(Vqhu a);
PUBLIC(Vqwi, aswiqhi)(Vqhi a);
PUBLIC(Vqwi, aswiqhf)(Vqhf a);
PUBLIC(Vqwi, aswiqwu)(Vqwu a);
PUBLIC(Vqwi, aswiqwi)(Vqwi a);
PUBLIC(Vqwi, aswiqwf)(Vqwf a);
PUBLIC(Vqwi, aswiqdu)(Vqdu a);
PUBLIC(Vqwi, aswiqdi)(Vqdi a);
PUBLIC(Vqwi, aswiqdf)(Vqdf a);

// aswf:
PUBLIC(float, aswfwu)(uint32_t a);
PUBLIC(float, aswfwi)(int32_t a);

PUBLIC(Vwwf, aswfwyu)(Vwyu a);
PUBLIC(Vwwf, aswfwbu)(Vwbu a);
PUBLIC(Vwwf, aswfwbi)(Vwbi a);
PUBLIC(Vwwf, aswfwbc)(Vwbc a);
PUBLIC(Vwwf, aswfwhu)(Vwhu a);
PUBLIC(Vwwf, aswfwhi)(Vwhi a);
PUBLIC(Vwwf, aswfwhf)(Vwhf a);
PUBLIC(Vwwf, aswfwwu)(Vwwu a);
PUBLIC(Vwwf, aswfwwi)(Vwwi a);
PUBLIC(Vwwf, aswfwwf)(Vwwf a);

PUBLIC(Vdwf, aswfdyu)(Vdbu a);
PUBLIC(Vdwf, aswfdbu)(Vdbu a);
PUBLIC(Vdwf, aswfdbi)(Vdbi a);
PUBLIC(Vdwf, aswfdbc)(Vdbc a);
PUBLIC(Vdwf, aswfdhu)(Vdhu a);
PUBLIC(Vdwf, aswfdhi)(Vdhi a);
PUBLIC(Vdwf, aswfdhf)(Vdhf a);
PUBLIC(Vdwf, aswfdwu)(Vdwu a);
PUBLIC(Vdwf, aswfdwi)(Vdwi a);
PUBLIC(Vdwf, aswfdwf)(Vdwf a);
PUBLIC(Vdwf, aswfddu)(Vddu a);
PUBLIC(Vdwf, aswfddi)(Vddi a);
PUBLIC(Vdwf, aswfddf)(Vddf a);

PUBLIC(Vqwf, aswfqyu)(Vqyu a);
PUBLIC(Vqwf, aswfqbu)(Vqbu a);
PUBLIC(Vqwf, aswfqbi)(Vqbi a);
PUBLIC(Vqwf, aswfqbc)(Vqbc a);
PUBLIC(Vqwf, aswfqhu)(Vqhu a);
PUBLIC(Vqwf, aswfqhi)(Vqhi a);
PUBLIC(Vqwf, aswfqhf)(Vqhf a);
PUBLIC(Vqwf, aswfqwu)(Vqwu a);
PUBLIC(Vqwf, aswfqwi)(Vqwi a);
PUBLIC(Vqwf, aswfqwf)(Vqwf a);
PUBLIC(Vqwf, aswfqdu)(Vqdu a);
PUBLIC(Vqwf, aswfqdi)(Vqdi a);
PUBLIC(Vqwf, aswfqdf)(Vqdf a);

// asdu:
PUBLIC(uint64_t, asdudi)(int64_t a);
PUBLIC(uint64_t, asdudf)(double a);

PUBLIC(Vddu, asdudyu)(Vdyu a);
PUBLIC(Vddu, asdudbu)(Vdbu a);
PUBLIC(Vddu, asdudbi)(Vdbi a);
PUBLIC(Vddu, asdudbc)(Vdbc a);
PUBLIC(Vddu, asdudhu)(Vdhu a);
PUBLIC(Vddu, asdudhi)(Vdhi a);
PUBLIC(Vddu, asdudhf)(Vdhf a);
PUBLIC(Vddu, asdudwu)(Vdwu a);
PUBLIC(Vddu, asdudwi)(Vdwi a);
PUBLIC(Vddu, asdudwf)(Vdwf a);
PUBLIC(Vddu, asduddu)(Vddu a);
PUBLIC(Vddu, asduddi)(Vddi a);
PUBLIC(Vddu, asduddf)(Vddf a);

PUBLIC(Vqdu, asduqyu)(Vqyu a);
PUBLIC(Vqdu, asduqbu)(Vqbu a);
PUBLIC(Vqdu, asduqbi)(Vqbi a);
PUBLIC(Vqdu, asduqbc)(Vqbc a);
PUBLIC(Vqdu, asduqhu)(Vqhu a);
PUBLIC(Vqdu, asduqhi)(Vqhi a);
PUBLIC(Vqdu, asduqhf)(Vqhf a);
PUBLIC(Vqdu, asduqwu)(Vqwu a);
PUBLIC(Vqdu, asduqwi)(Vqwi a);
PUBLIC(Vqdu, asduqwf)(Vqwf a);
PUBLIC(Vqdu, asduqdu)(Vqdu a);
PUBLIC(Vqdu, asduqdi)(Vqdi a);
PUBLIC(Vqdu, asduqdf)(Vqdf a);

// asdi:
PUBLIC(int64_t, asdidu)(uint64_t a);
PUBLIC(int64_t, asdidf)(double a);

PUBLIC(Vddi, asdidyu)(Vdyu a);
PUBLIC(Vddi, asdidbu)(Vdbu a);
PUBLIC(Vddi, asdidbi)(Vdbi a);
PUBLIC(Vddi, asdidbc)(Vdbc a);
PUBLIC(Vddi, asdidhu)(Vdhu a);
PUBLIC(Vddi, asdidhi)(Vdhi a);
PUBLIC(Vddi, asdidhf)(Vdhf a);
PUBLIC(Vddi, asdidwu)(Vdwu a);
PUBLIC(Vddi, asdidwi)(Vdwi a);
PUBLIC(Vddi, asdidwf)(Vdwf a);
PUBLIC(Vddi, asdiddu)(Vddu a);
PUBLIC(Vddi, asdiddi)(Vddi a);
PUBLIC(Vddi, asdiddf)(Vddf a);

PUBLIC(Vqdi, asdiqyu)(Vqyu a);
PUBLIC(Vqdi, asdiqbu)(Vqbu a);
PUBLIC(Vqdi, asdiqbi)(Vqbi a);
PUBLIC(Vqdi, asdiqbc)(Vqbc a);
PUBLIC(Vqdi, asdiqhu)(Vqhu a);
PUBLIC(Vqdi, asdiqhi)(Vqhi a);
PUBLIC(Vqdi, asdiqhf)(Vqhf a);
PUBLIC(Vqdi, asdiqwu)(Vqwu a);
PUBLIC(Vqdi, asdiqwi)(Vqwi a);
PUBLIC(Vqdi, asdiqwf)(Vqwf a);
PUBLIC(Vqdi, asdiqdu)(Vqdu a);
PUBLIC(Vqdi, asdiqdi)(Vqdi a);
PUBLIC(Vqdi, asdiqdf)(Vqdf a);

// asdf:
PUBLIC(double, asdfdu)(uint64_t a);
PUBLIC(double, asdfdi)(int64_t a);

PUBLIC(Vddf, asdfdyu)(Vdyu a);
PUBLIC(Vddf, asdfdbu)(Vdbu a);
PUBLIC(Vddf, asdfdbi)(Vdbi a);
PUBLIC(Vddf, asdfdbc)(Vdbc a);
PUBLIC(Vddf, asdfdhu)(Vdhu a);
PUBLIC(Vddf, asdfdhi)(Vdhi a);
PUBLIC(Vddf, asdfdhf)(Vdhf a);
PUBLIC(Vddf, asdfdwu)(Vdwu a);
PUBLIC(Vddf, asdfdwi)(Vdwi a);
PUBLIC(Vddf, asdfdwf)(Vdwf a);
PUBLIC(Vddf, asdfddu)(Vddu a);
PUBLIC(Vddf, asdfddi)(Vddi a);
PUBLIC(Vddf, asdfddf)(Vddf a);

PUBLIC(Vqdf, asdfqyu)(Vqyu a);
PUBLIC(Vqdf, asdfqbu)(Vqbu a);
PUBLIC(Vqdf, asdfqbi)(Vqbi a);
PUBLIC(Vqdf, asdfqbc)(Vqbc a);
PUBLIC(Vqdf, asdfqhu)(Vqhu a);
PUBLIC(Vqdf, asdfqhi)(Vqhi a);
PUBLIC(Vqdf, asdfqhf)(Vqhf a);
PUBLIC(Vqdf, asdfqwu)(Vqwu a);
PUBLIC(Vqdf, asdfqwi)(Vqwi a);
PUBLIC(Vqdf, asdfqwf)(Vqwf a);
PUBLIC(Vqdf, asdfqdu)(Vqdu a);
PUBLIC(Vqdf, asdfqdi)(Vqdi a);
PUBLIC(Vqdf, asdfqdf)(Vqdf a);

#if 0
PUBLIC(uint8_t, asbubi)(int8_t a) {return INT8_ASBU(a);}
PUBLIC(uint8_t, asbubc)(char a) {return CHAR_ASBU(a);}

PUBLIC(Vwbu, asbuwyu)(Vwyu a) {return VWYU_ASBU(a);}
PUBLIC(Vwbu, asbuwbi)(Vwbi a) {return VWBI_ASBU(a);}
PUBLIC(Vwbu, asbuwbc)(Vwbc a) {return VWBC_ASBU(a);}
PUBLIC(Vwbu, asbuwhu)(Vwhu a) {return VWHU_ASBU(a);}
PUBLIC(Vwbu, asbuwhi)(Vwhi a) {return VWHI_ASBU(a);}
PUBLIC(Vwbu, asbuwhf)(Vwhf a) {return VWHF_ASBU(a);}
PUBLIC(Vwbu, asbuwwu)(Vwwu a) {return VWWU_ASBU(a);}
PUBLIC(Vwbu, asbuwwi)(Vwwi a) {return VWWI_ASBU(a);}
PUBLIC(Vwbu, asbuwwf)(Vwwf a) {return VWWF_ASBU(a);}

PUBLIC(Vdbu, asbudyu)(Vdyu a) {return VDYU_ASBU(a);}
PUBLIC(Vdbu, asbudbi)(Vdbi a) {return VDBI_ASBU(a);}
PUBLIC(Vdbu, asbudbc)(Vdbc a) {return VDBC_ASBU(a);}
PUBLIC(Vdbu, asbudhu)(Vdhu a) {return VDHU_ASBU(a);}
PUBLIC(Vdbu, asbudhi)(Vdhi a) {return VDHI_ASBU(a);}
PUBLIC(Vdbu, asbudhf)(Vdhf a) {return VDHF_ASBU(a);}
PUBLIC(Vdbu, asbudwu)(Vdwu a) {return VDWU_ASBU(a);}
PUBLIC(Vdbu, asbudwi)(Vdwi a) {return VDWI_ASBU(a);}
PUBLIC(Vdbu, asbudwf)(Vdwf a) {return VDWF_ASBU(a);}
PUBLIC(Vdbu, asbuddu)(Vddu a) {return VDDU_ASBU(a);}
PUBLIC(Vdbu, asbuddi)(Vddi a) {return VDDI_ASBU(a);}
PUBLIC(Vdbu, asbuddf)(Vddf a) {return VDDF_ASBU(a);}

PUBLIC(Vqbu, asbuqyu)(Vqyu a) {return VQYU_ASBU(a);}
PUBLIC(Vqbu, asbuqbi)(Vqbi a) {return VQBI_ASBU(a);}
PUBLIC(Vqbu, asbuqbc)(Vqbc a) {return VQBC_ASBU(a);}
PUBLIC(Vqbu, asbuqhu)(Vqhu a) {return VQHU_ASBU(a);}
PUBLIC(Vqbu, asbuqhi)(Vqhi a) {return VQHI_ASBU(a);}
PUBLIC(Vqbu, asbuqhf)(Vqhf a) {return VQHF_ASBU(a);}
PUBLIC(Vqbu, asbuqwu)(Vqwu a) {return VQWU_ASBU(a);}
PUBLIC(Vqbu, asbuqwi)(Vqwi a) {return VQWI_ASBU(a);}
PUBLIC(Vqbu, asbuqwf)(Vqwf a) {return VQWF_ASBU(a);}
PUBLIC(Vqbu, asbuqdu)(Vqdu a) {return VQDU_ASBU(a);}
PUBLIC(Vqbu, asbuqdi)(Vqdi a) {return VQDI_ASBU(a);}
PUBLIC(Vqbu, asbuqdf)(Vqdf a) {return VQDF_ASBU(a);}

#define     asbu_funcof(X)  \
_Generic(               \
    (X),                \
    signed char: asbubi,\
    char: asbubc,       \
    Vwyu: asbuwyu, Vwbi: asbuwbi, Vwbc:asbuwbc, \
    Vdyu: asbuwyu, Vdbi: asbuwbi, Vdbc:asbudbc, \
    Vqyu: asbuwyu, Vqbi: asbuwbi, Vqbc:asbudbc, \
    TGW_HWR(asbu)                               \
    TGD_HDR(asbu)                               \
    TGQ_HDR(asbu)                               \
    default:NULL                                \
)
#define     asbu(X) (asbu_funcof(X)(X))
#endif

#if _LEAVE_AS__
}
#endif

#define     catl(X)  (catl_funcof(X)(X))

/*
Misc:
{
    pass
        (): tell the scheduler that the caller is spinning
}

ast: Reinterpret value's representation as another type
{
    astu: As unsigned

}
// newl: k_hdr w_ywr d_ydr q_ydr o_ydr s_ydr
// newr: k_hdr w_ywr d_ydr q_ydr o_ydr s_ydr
new: Reconstruct from individual elements
{
    newl: left to right (least sig to most sig)

    newr: right to left (most sig to least sig)

}

cmb: Compiler Memory Barrier
{
    Compiler memory barriers inhibit the compiler's
    ability to reorder memory accesses across the barrier.
    No special instructions are emitted by their presence.

    For more information, refer to the C11 documentation
    for atomic_signal_fence

    cmba
        (): atomic_signal_fence(memory_order_acquire)

    cmbr
        (): atomic_signal_fence(memory_order_release)

    cmbt
        (): atomic_signal_fence(memory_order_seq_cst)
}

hmb: Hardware Memory Barrier
{
    Hardware Memory Barriers are more restricting than the
    corresponding Compiler Memory Barrier, by generating
    instructions that prevent the processing element from
    rearranging the relevant accesses at runtime.

    For more information, refer to the C11 documentation
    for atomic_thread_fence

    hmba
        (): atomic_thread_fence(memory_order_acquire)

    hmbr
        (): atomic_thread_fence(memory_order_release)

    hmbt
        (): atomic_thread_fence(memory_order_seq_cst)
}

smb: Synchronizing Memory Barrier
{
    A Synchronizing Memory Barrier delays execution of
    memory access instructions until all memory accesses
    of the type implied by the barrier operation, which
    began executing before the barrier, have "completed".

    What qualifies as "completed" and exactly who all is
    guaranteed a coherent view of the caller's shared
    memory is obviously implementation defined.

    We use a consistent set of operation suffixes to
    represent the corresponding C11 memory_order:

        xxx1: memory_order_relaxed
        *   Atomicity without order constraints

        xxxa: memory_order_acquire
        *   Loads and stores in the calling thread cannot
            be reordered before the acquiring operation.
            Releasing stores and their side effects are
            complete before the acquiring operation occurs

        xxxr: memory_order_release
        *   Loads and stores in the calling thread cannot
            be reordered after the releasing operation.
            Acquiring loads occur only after the releasing
            operation is completed

        xxxt: memory_order_seq_cst
        *   No reordering across the operation can occur.
            Loads are acquiring, stores are relasing, and
            read-modify-writes are both. This is the only
            ordering that has to be available. The others
            exist as optimization hints.

    Since `memory_order_consume` isn't implemented by any
    of our supported architectures we don't have a suffix
    for it, although 'c' would be perfect and is one of the
    few unused letters.

    The difference between `memory_order_acq_rel` and
    `memory_order_seq_cst` doesn't seem significant enough
    to justify its existence, therefore it's missing too.

    All of this is here in the smb docs because although
    it uses the 'a', 'r', and 't' suffixes and is an
    operation intended to aid in memory sharing, the
    semantics are slightly different. 'a' means all loads
    and their side effects are complete by the time smba
    returns. 'r' means all stores and their side effects
    are complete by the time smbr returns. 't' means both
    loads and stores are done by the time smbt returns.

    smba
        (): synchronized loads + hmbt()

    smbr
        (): synchronize stored + hmbt()

    smbt
        (): all access synchronization + hmbt()
}

ldr: Load Register (from aligned ENDIAN_NAT)
{
    ldr1*_atomic
    ldra*_atomic
    ldrt*_atomic
        1 if the op uses lock free atomic instructions

    ldr1
        *z (A_YDZ src[1]):
            r = atomic_load_explicit(src, memory_order_relaxed)
        Vw*r (W_BWR dst, k, src[1])
        Vd*r (D_BDR dst, k, src[1])
        Vq*r (Q_BDR dst, k, src[1])
        Vo*r (O_BDR dst, k, src[1])
        Vs*r (S_BDR dst, k, src[1]):
            dst.k = ldr1(src)

    ldra
        *z (A_YDZ src[1]):
            r = atomic_load_explicit(src, memory_order_acquire)
        Vw*r (W_BWR dst, k, src[1])
        Vd*r (D_BDR dst, k, src[1])
        Vq*r (Q_BDR dst, k, src[1])
        Vo*r (O_BDR dst, k, src[1])
        Vs*r (S_BDR dst, k, src[1])
            dst.k = ldra(src)

    ldrt
        *z (A_YDZ src[1]):
            r = atomic_load_explicit(src, memory_order_seq_cst)
        Vw*r (W_BWR dst, k, src[1])
        Vd*r (D_BDR dst, k, src[1])
        Vq*r (Q_BDR dst, k, src[1])
        Vo*r (O_BDR dst, k, src[1])
        Vs*r (S_BDR dst, k, src[1])
            dst.k = ldrt(src)

    ldrw
        Vw*r (A_BWR <*4>src):         dst.W = (*src)[0:32]

    ldrd
        Vd*r (A_BDR <*8>src):         dst.D = (*src)[0:64]

    ldrq
        Vq*r (A_BDR <*16>src):        dst.Q = (*src)[0:128]

    ldro
        Vo*r (A_BDR <*32>src):        dst.O = (*src)[0:256]

    ldrs
        Vs*r (A_BDR <*32>src):        dst.S = (*src)[0:512]
}

rdn: Load Register (from unaligned ENDIAN_NAT)
rdl: Load Register (from unaligned ENDIAN_LIL)
rdb: Load Register (from unaligned ENDIAN_BIG)
{
    The following example contains a stupid example where
    a 64 bit int is loaded from an off-by-5 address:

        Quad src = {"0123456789abcde"};
        uint64_t off = rdn1((uint64_t *)(&src.B.U));

    rdn* should always be used if atomicity is not needed
    and there's any chance at all that the source won't
    necessarily be aligned.

    NOTE: the rdn operations should be defined as aliases
    of rdl or rdb depending on the target byteorder. On a
    system with MY_ENDIAN == ENDIAN_LIL, rdbq is identical
    to rdlq except that rvb* is automatically called to
    reverse the bytes in each element. The converse is
    true if MY_ENDIAN == ENDIAN_BIG.

    rdn1
    rdl1
    rdb1
        *r (A_YDR *src): *memcpy(&dst, src, sizeof *src);
        Vw*r (W_BWR dst, k, *src)
        Vd*r (D_BDR dst, k, *src)
        Vq*r (Q_BDR dst, k, *src)
            dst.k = rd*1(src)

    rdnw
    rdlw
    rdbw
        Vw*r (A_BWR *src): dst[0:32] = src->W

    rdnd
    rdld
    rdbd
        Vd*r (A_BDR *src): dst[0:64] = src->D

    rdnq
    rdlq
    rdbq
        Vq*r (A_BDR *src): dst[0:128] = src->Q

}

str1dwu(Vdwu src, Rc(0,1) k, Wu dst[2]);
str1wu(   Wu src, Wu dst[2]);

strvdbu(Vdbu src, Bu dst[8]);

str: Store Register (to aligned)
{
    str1
        (A_YDZ dst[1], src):
            atomic_store_explicit(dst, src, memory_order_relaxed)
        (W_BWR src, k, dst[1])
        (D_BDR src, k, dst[1])
        (Q_BDR src, k, dst[1]):
            str1(dst, vxt1(dst, k))

    strr
        (A_YDZ dst[1], src):
            atomic_store_explicit(dst, src, memory_order_release)
        (W_BWR src, k, dst[1])
        (D_BDR src, k, dst[1])
        (Q_BDR src, k, dst[1]):
            strr(dst, vxt1(dst, k))

    strt
        (A_YDZ dst[1], src):
            atomic_store_explicit(dst, src, memory_order_seq_cst)
        (W_BWR src, k, dst[1])
        (D_BDR src, k, dst[1])
        (Q_BDR src, k, dst[1]):
            strt(dst, vxt1(dst, k))

    strw
        (A_BWR <*4>dst, src): dst->W = src[0:32]

    strd
        (A_BDR <*8>dst, src): dst->D = src[0:64]

    strq
        (A_BDR <*16>dst,src): dst->Q = src[0:128]
}

wrn: Store Register (to unaligned ENDIAN_NAT)
wrl: Store Register (to unaligned ENDIAN_LIL)
wrb: Store Register (to unaligned ENDIAN_BIG)
{
    wrn1
    wrl1
    wrb1
        (A_YDZ *dst, src): memcpy(dst, &src, sizeof src)
        (W_BWR src, k, *dst)
        (D_BDR src, k, *dst)
        (Q_BDR src, k, *dst)
            wr*1(dst, vxt1(dst, k))

    wrnw
    wrlw
    wrbw
        (A_BWR *dst, src): dst->W = src[0:32]

    wrnd
    wrld
    wrbd
        (A_BDR *dst, src): dst->D = src[0:64]

    wrnq
    wrlq
    wrbq
        (A_BDR *dst, src): dst->Q = src[0:128]
}

cat: Concatenate
{
    catl:
        Vdtr    (W_BWR l, r):
            ret = l ## r

    catr:
        Vdtr (W_YWR l, r):
        Vqtr (D_YDR l, r):
        Votr (D_YDR l, r):
            ret = revs(r) ## revs(l)

    cats:

}

rev: Reverse
{

    The revs and revt array operations take three
    parameters: a sequence 'src' to reverse, the address
    of an array 'dst' into which the reversed source is
    is to be copied, and the number of elements 'n' to
    reverse. If 'dst' is NULL, the reversal is performed
    in place. If 'dst' points to NULL, a block of memory
    sufficient to store the reversed result is allocated
    and stored at '*dst' and once this assignment occurs
    it becomes the caller's responsibility to ensure it is
    freed at the appropriate time. For convenience, these
    operations return a pointer to the first element in
    the reversed array.

    revy, revb, revh, and revw reverses the bits, bytes,
    halfwords, or words, respectively, of each element in
    the operand.

    HISTORY: the boolean vector types were added initially
    to reduce the number of necessary reverse ops. 

    revs: reverse sequence 
        $b (A_BDR src[], *dst[n], n)
            ret = memmove(
                !dst ? src : *dst ? *dst : malloc(n*sizeof *src),
                reverse(src, n*8*sizeof*src, 8*sizeof*a),
                n*sizeof*src
            )

        Vw*r (W_YHR a)
        Vd*r (D_YWR a)
        Vq*r (Q_YDR a)
        Vo*r (O_YDR a)
        Vs*r (S_YDR a):
            reverse(a, 8*sizeof a, sizeof a.K0)

    rvrt:
        (A_BWU t, n):
            reverse(a, ffzl(t)*sizeof *txt, 8*sizeof *a)
        Vw*u (W_BHU a)
            reverse(a, 32, sizeof a.K0)
        Vd*u (D_BHU txt)

        (K_BDR a): reverse(a[:], 8*sizeof a, 1)
        (W_BWR a)
        (D_BDR a)
        (Q_BDR a)
            each element's bits are reversed

    revy:
        Kr (K_BDR a)
            Kr = reverse(a, 8*sizeof a, 1)
        Vwtr (W_BWR a)
        Vdtr (D_BDR a)
        Vqtr (Q_BDR a)
        Votr (O_BDR a)
        Vstr (S_BDR a)
            V r;
            for (int i=0; i < LENGTHOF(a); i++)
                r[i] = revy(r[i]);
    revb:
        Kr (K_HDR a)
            Kr = reverse(a, 8*sizeof a, 8)
        Vwtr (W_HWR a)
        Vdtr (D_HDR a)
        Vqtr (Q_HDR a)
        Votr (O_HDR a)
        Vstr (S_HDR a)
            V r;
            for (int i=0; i < LENGTHOF(a); i++)
                r[i] = revb(r[i]);
    revh:
        Kr (K_WDR a)
            Kr = reverse(a, 8*sizeof a, 16)
        Vwwr (W_WR a)
        Vdtr (D_WDR a)
        Vqtr (Q_WDR a)
        Votr (O_WDR a)
        Vstr (S_WDR a)
            V r;
            for (int i=0; i < LENGTHOF(a); i++)
                r[i] = revh(r[i]);
    revw:
        Dr (K_DR a)
            Dr = reverse(a, 64, 32)
        Vddr (D_DR a)
        Vqtr (Q_WDR a)
        Votr (O_WDR a)
        Vstr (S_WDR a)
            V r;
            for (int i=0; i < LENGTHOF(a); i++)
                r[i] = revw(r[i]);

}

vps: Vector Permute Single

    Shuffle a 32, 64, 128, 256, or 512 SIMD vector with
    elements selected by signed 8 bit indices specified 
    as the same number of function parameters as there 
    are elements in the vector. Indexes with bit 7 set 
    result in the selection of a zero element instead of 
    one of the elements in the vector. If the index is 
    greater than the maximum vector element, the result
    is undefined.

    Note that for maximum performance, the type specific
    macros should always be used. If the compiler fails
    to inline the function call properly, the operation
    could potentially be hundreds of times slower.
    
    A more powerful operation is vpp, which takes two 
    vectors and instead of inserting zero when the index
    is negative simply copies the corresponding element 
    from the second vector.
    

        Vqwu 
        persqwu(Vqwu src, Bi k0, Bi k1, Bi k2, Bi k3)
        {
            Vqwu dst = {0};
            dst = vstq(dst, 0, (k0 < 0 ? 0 : vxtq(dst, k0)));
            dst = vstq(dst, 1, (k1 < 0 ? 0 : vxtq(dst, k1)));
            dst = vstq(dst, 2, (k2 < 0 ? 0 : vxtq(dst, k2)));
            dst = vstq(dst, 3, (k3 < 0 ? 0 : vxtq(dst, k3)));
            return dst;
        }
        Vqwu
        vpssqwu(Vqwu src, Vqwi map)
        {
            return pers(
                src,
                vxtq(map, 0),
                vxtq(map, 1),
                vxtq(map, 2),
                vxtq(map, 3)
            )
        }

vpp: Vector Permute Pair
    
    vpp takes two vectors - the fg and the bg - and 
    constructs a new vector as in the following example:

        Vqwu 
        vppmqwu(Vqwu fg, Vqwu bg, Bi k0, Bi k1, Bi k2, Bi k3)
        {
            Vqwu dst = bg;
            if (k0 >= 0) 
                dst = vstq(dst, 0, vxtq(fg, k0));
            if (k1 >= 0) 
                dst = vstq(dst, 1, vxtq(fg, k1));
            if (k2 >= 0) 
                dst = vstq(dst, 2, vxtq(fg, k2));
            if (k3 >= 0) 
                dst = vstq(dst, 3, vxtq(fg, k3));
            return dst;
        }
    
    As with vps, vpp has two variants: vppm, which takes 
    a parameter list, and vpps, which takes a vector. To 
    guarantee the most efficient instruction sequence for
    a vector of type T, call the macro corresponding to 
    the vppm operation for T directly. E.g. use vppmqwu to
    shuffle a 128 bit uint32_t vector.
    
vxt: Extract
{
    vxtl: Lower half

        Bz (K_HZ src):
            dst = vxtb(src, 0, 8)

        Hz (K_WZ src):
            dst = vxth(src, 0, 16)

        Wz (K_DZ src):
            dst = vxtw(src, 0, 32)

        Vwtr (D_BWR src):
            dst = src[0:32]

        Vdtr (Q_BDR src):
            dst = src[0:64]

        Vqtr (O_BDR src):
            dst = src[0:128]

        Votr (S_BDR src):
            dst = src[0:256]


    vxtr: Upper half

        Bz (K_HZ src):
            dst = vxtb(src, 8, 8)

        Hz (K_WZ src):
            dst = vxth(src, 16, 16)

        Wz (K_DZ src):
            dst = vxtw(src, 32, 32)

        Vwtr (D_BWR src):
            dst = src[32:64]

        Vdtr (Q_BDR src):
            dst = src[64:128]

        Vqtr (O_BDR src):
            dst = src[128:256]

        Votr (S_BDR src):
            dst = src[256:512]

    vxty: _Bool bit field / Vector bit subsequence

        Yu (K_BDZ src, bit)
            dst = src[bit:bit+1]

        Vwyu (W_YU src, bit, len)
        Vdyu (D_YU src, bit, len)
        Vqyu (Q_YU src, bit, len
        Voyu (O_YU src, bit, len)
        Vsyu (S_YU src, bit, len):
            dst[0:len] = src[bit:bit+len]

    vxtb: Bz bit field
        Bz (K_BZ src, bit, len):
            dst = src[bit:bit+len]

    vxth: Hz bit field
        Hz (K_HZ src, bit, len):
            dst = src[bit:bit+len]

    vxtw: Wz bit field / Vw element
        Wz (K_WZ src, bit, len):
            dst = src[bit:bit+len]

        Tr (W_YWR src, k):
            dst = src.k

    vxtd: Dz bit field / Single Vd element
        Dz (K_DZ src, bit, len):
            dst = src[bit:bit+len]

        Tr (D_YDR src, k):
            dst = src.k

    vxtq: Single Vq element
        Tr (Q_YDR src, k):
            dst = src.k

    vxto: Single Vo element
        Tr (O_YDR src, k):
            dst = src.k
}

vst: Vector/Bitfield "store"
{

    HISTORY: the vector operations were separated into
    'w', 'd', 'q', 'o', and 's' suffixes because it was
    mistakenly assumed that the "vector set" intrinsics,
    which require a compiler constant to identify the lane,
    could then be used directly with _Generic. Even though
    that turned out to be hilariously untrue, the suffixes
    didn't *not* make sense for this particular operation
    and allowed reducing the number of operation prefixes
    significantly.

    vstl: Lower half
        Hz (K_HZ dst, K_BZ src)
        Wz (K_WZ dst, K_HZ src)
        Dz (K_DZ dst, K_WZ src):
            dst[0:8*sizeof src] = src

        Vdtr (D_YDR dst, W_YWR src)
        Vqtr (Q_YDR dst, D_YWR src)
        Votr (O_YDR dst, Q_YWR src)
        Vstr (S_YDR dst, O_YWR src):
            dst[0:8*sizeof src] = src

    vstr: Upper half
        Hz (K_HZ dst, K_BZ src)
        Wz (K_WZ dst, K_HZ src)
        Dz (K_DZ dst, K_WZ src):
            dst[8*sizeof src:8*sizeof dst] = src

        Vdtr (D_YDR dst, W_YWR src)
        Vqtr (Q_YDR dst, D_YWR src)
        Votr (O_YDR dst, Q_YWR src)
        Vstr (S_YDR dst, O_YWR src):
            dst[8*sizeof src:8*sizeof dst] = src

    vsty: _Bool / vector bitfield

        Tr (K_BDR dst, src, bit)
            dst[bit:bit+1] = (_Bool) src

        Vwyu (W_YU dst, bit, len, src)
        Vdyu (D_YU dst, bit, len, src)
        Vqyu (Q_YU dst, bit, len, src)
        Voyu (O_YU dst, bit, len, src)
        Vsyu (S_YU dst, bit, len, src):
            dst[bit:bit+len] = src[0:len]

    vstb: Bz bitfield

        Bz (K_BZ dst, bit, len, src)
            dst[bit:bit+len] = src[0:len]

    vsth: Hz bitfield

        Hz (K_HZ dst, bit, len, src)
            dst[bit:bit+len] = src[0:len]

    vstw: Wz bitfield / Vw element

        Wz (K_WZ dst, bit, len, src)
            dst[bit:bit+len] = src[0:len]

        Vwtr (W_YWR dst, src, k)
            dst.k = src

    vstd: Dz bitfield / Vd element

        Dz (K_DZ dst, bit, len, src)
            dst[bit:bit+len] = src[0:len]

        Vdtr (D_YDR dst, k, src)
            dst.k = src

    vstq: Vq element

        Vqtr (Q_YDR dst, k, src)
            dst.k = src

    vsto: Vo element

        Votr (O_YDR dst, k, src)
            dst.k = src

    vsts: Vs element

        Vstr (S_YDR dst, k, src)
            dst.k = src




}

PUBLIC(void,str1ayu)(  _Bool dst[1], _Bool src);
PUBLIC(void,str1abu)(uint8_t dst[1], uint8_t src);
PUBLIC(void,str1adi)(uint8_t dst[1], uint8_t src);

PUBLIC(void,strrayu)(  _Bool dst[1], _Bool src);
PUBLIC(void,strrabu)(uint8_t dst[1], uint8_t src);
PUBLIC(void,strradi)(uint8_t dst[1], uint8_t src);

PUBLIC(void,strtayu)(  _Bool dst[1], _Bool src);
PUBLIC(void,strtabu)(uint8_t dst[1], uint8_t src);
PUBLIC(void,strtadi)(uint8_t dst[1], uint8_t src);

PUBLIC(voic)

PUBLIC(void *, revtabu)(uint8_t  src[], void **dst, size_t len);
PUBLIC(void *, revtahu)(uint16_t src[], void **dst, size_t len);
PUBLIC(void *, revtawu)(uint32_t src[], void **dst, size_t len);

PUBLIC(   _Bool *, revsayu)(   _Bool a[], ptrdiff_t b);
PUBLIC(    char *, revsabc)(    char a[], ptrdiff_t b);
PUBLIC( uint8_t *, revsabu)( uint8_t a[], ptrdiff_t b);
PUBLIC(  int8_t *, revsabi)(  int8_t a[], ptrdiff_t b);
PUBLIC(uint16_t *, revsahu)(uint16_t a[], ptrdiff_t b);
PUBLIC( int16_t *, revsahi)( int16_t a[], ptrdiff_t b);
PUBLIC( flt16_t *, revsahf)( flt16_t a[], ptrdiff_t b);
PUBLIC(uint32_t *, revsawu)(uint32_t a[], ptrdiff_t b);
PUBLIC( int32_t *, revsawi)( int32_t a[], ptrdiff_t b);
PUBLIC(   float *, revsawf)(   float a[], ptrdiff_t b);
PUBLIC(uint64_t *, revsawu)(uint32_t a[], ptrdiff_t b);
PUBLIC( int64_t *, revsawi)( int32_t a[], ptrdiff_t b);
PUBLIC(  double *, revsawf)(  double a[], ptrdiff_t b);


*/

#if _ENTER_VST_
{
#endif

#if _ENTER_VSTL
{
#endif

PUBLIC(Vdyu,vstldyu) (Vdyu c, Vwyu l);

PUBLIC(Vdbu,vstldbu) (Vdbu c, Vwbu l);
PUBLIC(Vdbi,vstldbi) (Vdbi c, Vwbi l);
PUBLIC(Vdbc,vstldbc) (Vdbc c, Vwbc l);

PUBLIC(Vdhu,vstldhu) (Vdhu c, Vwhu l);
PUBLIC(Vdhi,vstldhi) (Vdhi c, Vwhi l);
PUBLIC(Vdhf,vstldhf) (Vdhf c, Vwhf l);

PUBLIC(Vdwu,vstldwu) (Vdwu c, Vwwu l);
PUBLIC(Vdwi,vstldwi) (Vdwi c, Vwwi l);
PUBLIC(Vdwf,vstldwf) (Vdwf c, Vwwf l);


PUBLIC(Vqyu,vstlqyu) (Vqyu c, Vdyu l);
PUBLIC(Vqbu,vstlqbu) (Vqbu c, Vdbu l);
PUBLIC(Vqbi,vstlqbi) (Vqbi c, Vdbi l);
PUBLIC(Vqbc,vstlqbc) (Vqbc c, Vdbc l);

PUBLIC(Vqhu,vstlqhu) (Vqhu c, Vdhu l);
PUBLIC(Vqhi,vstlqhi) (Vqhi c, Vdhi l);
PUBLIC(Vqhf,vstlqhf) (Vqhf c, Vdhf l);

PUBLIC(Vqwu,vstlqwu) (Vqwu c, Vdwu l);
PUBLIC(Vqwi,vstlqwi) (Vqwi c, Vdwi l);
PUBLIC(Vqwf,vstlqwf) (Vqwf c, Vdwf l);

PUBLIC(Vqdu,vstlqdu) (Vqdu c, Vddu l);
PUBLIC(Vqdi,vstlqdi) (Vqdi c, Vddi l);
PUBLIC(Vqdf,vstlqdf) (Vqdf c, Vddf l);

#define     vstl_funcof(C)  \
FUNCOF(                     \
    vstl,   (   C   ),      \
    NONE,   /* TGK */       \
    NONE,   /* TGW */       \
    YWR,    /* TGD */       \
    YDR,    /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGO */       \
    default: NULL           \
)
#define     vstl(C, L)  (vstl_funcof(C)(C,L))

PUBLIC(Vdyu,vstldyu) (Vdyu c, Vwyu l)
{
    return  VDYU_VSTL(c, l);
}

PUBLIC(Vdbu,vstldbu) (Vdbu c, Vwbu l)
{
    return  VDBU_VSTL(c, l);
}

PUBLIC(Vdbi,vstldbi) (Vdbi c, Vwbi l)
{
    return  VDBI_VSTL(c, l);
}

PUBLIC(Vdbc,vstldbc) (Vdbc c, Vwbc l)
{
    return  VDBC_VSTL(c, l);
}


PUBLIC(Vdhu,vstldhu) (Vdhu c, Vwhu l)
{
    return  VDHU_VSTL(c, l);
}

PUBLIC(Vdhi,vstldhi) (Vdhi c, Vwhi l)
{
    return  VDHI_VSTL(c, l);
}

PUBLIC(Vdhf,vstldhf) (Vdhf c, Vwhf l)
{
    return  VDHF_VSTL(c, l);
}


PUBLIC(Vdwu,vstldwu) (Vdwu c, Vwwu l)
{
    return  VDWU_VSTL(c, l);
}

PUBLIC(Vdwi,vstldwi) (Vdwi c, Vwwi l)
{
    return  VDWI_VSTL(c, l);
}

PUBLIC(Vdwf,vstldwf) (Vdwf c, Vwwf l)
{
    return  VDWF_VSTL(c, l);
}



PUBLIC(Vqyu,vstlqyu) (Vqyu c, Vdyu l)
{
    return  VQYU_VSTL(c, l);
}

PUBLIC(Vqbu,vstlqbu) (Vqbu c, Vdbu l)
{
    return  VQBU_VSTL(c, l);
}

PUBLIC(Vqbi,vstlqbi) (Vqbi c, Vdbi l)
{
    return  VQBI_VSTL(c, l);
}

PUBLIC(Vqbc,vstlqbc) (Vqbc c, Vdbc l)
{
    return  VQBC_VSTL(c, l);
}


PUBLIC(Vqhu,vstlqhu) (Vqhu c, Vdhu l)
{
    return  VQHU_VSTL(c, l);
}

PUBLIC(Vqhi,vstlqhi) (Vqhi c, Vdhi l)
{
    return  VQHI_VSTL(c, l);
}

PUBLIC(Vqhf,vstlqhf) (Vqhf c, Vdhf l)
{
    return  VQHF_VSTL(c, l);
}


PUBLIC(Vqwu,vstlqwu) (Vqwu c, Vdwu l)
{
    return  VQWU_VSTL(c, l);
}

PUBLIC(Vqwi,vstlqwi) (Vqwi c, Vdwi l)
{
    return  VQWI_VSTL(c, l);
}

PUBLIC(Vqwf,vstlqwf) (Vqwf c, Vdwf l)
{
    return  VQWF_VSTL(c, l);
}


PUBLIC(Vqdu,vstlqdu) (Vqdu c, Vddu l)
{
    return  VQDU_VSTL(c, l);
}

PUBLIC(Vqdi,vstlqdi) (Vqdi c, Vddi l)
{
    return  VQDI_VSTL(c, l);
}

PUBLIC(Vqdf,vstlqdf) (Vqdf c, Vddf l)
{
    return  VQDF_VSTL(c, l);
}


#define     vstldyu     VDYU_VSTL
#define     vstldbu     VDBU_VSTL
#define     vstldbi     VDBI_VSTL
#define     vstldbc     VDBC_VSTL
#define     vstldhu     VDHU_VSTL
#define     vstldhi     VDHI_VSTL
#define     vstldhf     VDHF_VSTL
#define     vstldwu     VDWU_VSTL
#define     vstldwi     VDWI_VSTL
#define     vstldwf     VDWF_VSTL

#define     vstlqyu     VQYU_VSTL
#define     vstlqbu     VQBU_VSTL
#define     vstlqbi     VQBI_VSTL
#define     vstlqbc     VQBC_VSTL
#define     vstlqhu     VQHU_VSTL
#define     vstlqhi     VQHI_VSTL
#define     vstlqhf     VQHF_VSTL
#define     vstlqwu     VQWU_VSTL
#define     vstlqwi     VQWI_VSTL
#define     vstlqwf     VQWF_VSTL
#define     vstlqdu     VQDU_VSTL
#define     vstlqdi     VQDI_VSTL
#define     vstlqdf     VQDF_VSTL

#if _LEAVE_VSTL
}
#endif

#if _ENTER_VSTR
{
#endif

PUBLIC(Vdyu,vstrdyu) (Vdyu c, Vwyu r);
PUBLIC(Vdbu,vstrdbu) (Vdbu c, Vwbu r);
PUBLIC(Vdbi,vstrdbi) (Vdbi c, Vwbi r);
PUBLIC(Vdbc,vstrdbc) (Vdbc c, Vwbc r);
PUBLIC(Vdhu,vstrdhu) (Vdhu c, Vwhu r);
PUBLIC(Vdhi,vstrdhi) (Vdhi c, Vwhi r);
PUBLIC(Vdhf,vstrdhf) (Vdhf c, Vwhf r);
PUBLIC(Vdwu,vstrdwu) (Vdwu c, Vwwu r);
PUBLIC(Vdwi,vstrdwi) (Vdwi c, Vwwi r);
PUBLIC(Vdwf,vstrdwf) (Vdwf c, Vwwf r);

PUBLIC(Vqyu,vstrqyu) (Vqyu c, Vdyu r);
PUBLIC(Vqbu,vstrqbu) (Vqbu c, Vdbu r);
PUBLIC(Vqbi,vstrqbi) (Vqbi c, Vdbi r);
PUBLIC(Vqbc,vstrqbc) (Vqbc c, Vdbc r);
PUBLIC(Vqhu,vstrqhu) (Vqhu c, Vdhu r);
PUBLIC(Vqhi,vstrqhi) (Vqhi c, Vdhi r);
PUBLIC(Vqhf,vstrqhf) (Vqhf c, Vdhf r);
PUBLIC(Vqwu,vstrqwu) (Vqwu c, Vdwu r);
PUBLIC(Vqwi,vstrqwi) (Vqwi c, Vdwi r);
PUBLIC(Vqwf,vstrqwf) (Vqwf c, Vdwf r);
PUBLIC(Vqdu,vstrqdu) (Vqdu c, Vddu r);
PUBLIC(Vqdi,vstrqdi) (Vqdi c, Vddi r);
PUBLIC(Vqdf,vstrqdf) (Vqdf c, Vddf r);

#define     vstr_funcof(C)  \
FUNCOF(                     \
    vstr,   (   C   ),      \
    NONE,   /* TGK */       \
    NONE,   /* TGW */       \
    YWR,    /* TGD */       \
    YDR,    /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGO */       \
    default: NULL           \
)
#define     vstr(C, L)  (vstr_funcof(C)(C,L))

PUBLIC(Vdyu,vstrdyu) (Vdyu c, Vwyu r)
{
    return  VDYU_VSTL(c, r);
}

PUBLIC(Vdbu,vstrdbu) (Vdbu c, Vwbu r)
{
    return  VDBU_VSTL(c, r);
}

PUBLIC(Vdbi,vstrdbi) (Vdbi c, Vwbi r)
{
    return  VDBI_VSTL(c, r);
}

PUBLIC(Vdbc,vstrdbc) (Vdbc c, Vwbc r)
{
    return  VDBC_VSTL(c, r);
}


PUBLIC(Vdhu,vstrdhu) (Vdhu c, Vwhu r)
{
    return  VDHU_VSTL(c, r);
}

PUBLIC(Vdhi,vstrdhi) (Vdhi c, Vwhi r)
{
    return  VDHI_VSTL(c, r);
}

PUBLIC(Vdhf,vstrdhf) (Vdhf c, Vwhf r)
{
    return  VDHF_VSTL(c, r);
}


PUBLIC(Vdwu,vstrdwu) (Vdwu c, Vwwu r)
{
    return  VDWU_VSTL(c, r);
}

PUBLIC(Vdwi,vstrdwi) (Vdwi c, Vwwi r)
{
    return  VDWI_VSTL(c, r);
}

PUBLIC(Vdwf,vstrdwf) (Vdwf c, Vwwf r)
{
    return  VDWF_VSTL(c, r);
}


PUBLIC(Vqyu,vstrqyu) (Vqyu c, Vdyu r)
{
    return  VQYU_VSTR(c, r);
}

PUBLIC(Vqbu,vstrqbu) (Vqbu c, Vdbu r)
{
    return  VQBU_VSTR(c, r);
}

PUBLIC(Vqbi,vstrqbi) (Vqbi c, Vdbi r)
{
    return  VQBI_VSTR(c, r);
}

PUBLIC(Vqbc,vstrqbc) (Vqbc c, Vdbc r)
{
    return  VQBC_VSTR(c, r);
}


PUBLIC(Vqhu,vstrqhu) (Vqhu c, Vdhu r)
{
    return  VQHU_VSTR(c, r);
}

PUBLIC(Vqhi,vstrqhi) (Vqhi c, Vdhi r)
{
    return  VQHI_VSTR(c, r);
}

PUBLIC(Vqhf,vstrqhf) (Vqhf c, Vdhf r)
{
    return  VQHF_VSTR(c, r);
}


PUBLIC(Vqwu,vstrqwu) (Vqwu c, Vdwu r)
{
    return  VQWU_VSTR(c, r);
}

PUBLIC(Vqwi,vstrqwi) (Vqwi c, Vdwi r)
{
    return  VQWI_VSTR(c, r);
}

PUBLIC(Vqwf,vstrqwf) (Vqwf c, Vdwf r)
{
    return  VQWF_VSTR(c, r);
}


PUBLIC(Vqdu,vstrqdu) (Vqdu c, Vddu r)
{
    return  VQDU_VSTR(c, r);
}

PUBLIC(Vqdi,vstrqdi) (Vqdi c, Vddi r)
{
    return  VQDI_VSTR(c, r);
}

PUBLIC(Vqdf,vstrqdf) (Vqdf c, Vddf r)
{
    return  VQDF_VSTR(c, r);
}


#define     vstrdyu     VDYU_VSTR
#define     vstrdbu     VDBU_VSTR
#define     vstrdbi     VDBI_VSTR
#define     vstrdbc     VDBC_VSTR
#define     vstrdhu     VDHU_VSTR
#define     vstrdhi     VDHI_VSTR
#define     vstrdhf     VDHF_VSTR
#define     vstrdwu     VDWU_VSTR
#define     vstrdwi     VDWI_VSTR
#define     vstrdwf     VDWF_VSTR

#define     vstrqyu     VQYU_VSTR
#define     vstrqbu     VQBU_VSTR
#define     vstrqbi     VQBI_VSTR
#define     vstrqbc     VQBC_VSTR
#define     vstrqhu     VQHU_VSTR
#define     vstrqhi     VQHI_VSTR
#define     vstrqhf     VQHF_VSTR
#define     vstrqwu     VQWU_VSTR
#define     vstrqwi     VQWI_VSTR
#define     vstrqwf     VQWF_VSTR
#define     vstrqdu     VQDU_VSTR
#define     vstrqdi     VQDI_VSTR
#define     vstrqdf     VQDF_VSTR


#if _LEAVE_VSTR
}
#endif


#if _ENTER_VST1
{
#endif

PUBLIC(Vwyu,vst1wyu) (Vwyu d, Rc(0, 31) k,    _Bool v);
PUBLIC(Vwbu,vst1wbu) (Vwbu d, Rc(0,  3) k,  uint8_t v);
PUBLIC(Vwbi,vst1wbi) (Vwbi d, Rc(0,  3) k,   int8_t v);
PUBLIC(Vwbc,vst1wbc) (Vwbc d, Rc(0,  3) k,     char v);
PUBLIC(Vwhu,vst1whu) (Vwhu d, Rc(0,  1) k, uint16_t v);
PUBLIC(Vwhi,vst1whi) (Vwhi d, Rc(0,  1) k,  int16_t v);
PUBLIC(Vwhf,vst1whf) (Vwhf d, Rc(0,  1) k,  flt16_t v);

PUBLIC(Vdyu,vst1dyu) (Vdyu d, Rc(0, 63) k,    _Bool v);
PUBLIC(Vdbu,vst1dbu) (Vdbu d, Rc(0,  7) k,  uint8_t v);
PUBLIC(Vdbi,vst1dbi) (Vdbi d, Rc(0,  7) k,   int8_t v);
PUBLIC(Vdbc,vst1dbc) (Vdbc d, Rc(0,  7) k,     char v);
PUBLIC(Vdhu,vst1dhu) (Vdhu d, Rc(0,  3) k, uint16_t v);
PUBLIC(Vdhi,vst1dhi) (Vdhi d, Rc(0,  3) k,  int16_t v);
PUBLIC(Vdhf,vst1dhf) (Vdhf d, Rc(0,  3) k,  flt16_t v);
PUBLIC(Vdwu,vst1dwu) (Vdwu d, Rc(0,  1) k, uint32_t v);
PUBLIC(Vdwi,vst1dwi) (Vdwi d, Rc(0,  1) k,  int32_t v);
PUBLIC(Vdwf,vst1dwf) (Vdwf d, Rc(0,  1) k,    float v);

PUBLIC(Vqyu,vst1qyu) (Vqyu d, Rc(0,127) k,    _Bool v);
PUBLIC(Vqbu,vst1qbu) (Vqbu d, Rc(0, 15) k,  uint8_t v);
PUBLIC(Vqbi,vst1qbi) (Vqbi d, Rc(0, 15) k,   int8_t v);
PUBLIC(Vqbc,vst1qbc) (Vqbc d, Rc(0, 15) k,     char v);
PUBLIC(Vqhu,vst1qhu) (Vqhu d, Rc(0,  7) k, uint16_t v);
PUBLIC(Vqhi,vst1qhi) (Vqhi d, Rc(0,  7) k,  int16_t v);
PUBLIC(Vqhf,vst1qhf) (Vqhf d, Rc(0,  7) k,  flt16_t v);
PUBLIC(Vqwu,vst1qwu) (Vqwu d, Rc(0,  3) k, uint32_t v);
PUBLIC(Vqwi,vst1qwi) (Vqwi d, Rc(0,  3) k,  int32_t v);
PUBLIC(Vqwf,vst1qwf) (Vqwf d, Rc(0,  3) k,    float v);
PUBLIC(Vqdu,vst1qdu) (Vqdu d, Rc(0,  1) k, uint64_t v);
PUBLIC(Vqdi,vst1qdi) (Vqdi d, Rc(0,  1) k,  int64_t v);
PUBLIC(Vqdf,vst1qdf) (Vqdf d, Rc(0,  1) k,   double v);

#define     vst1_funcof(D)  \
FUNCOF(                     \
    vst1,   (   D   ),      \
    NONE,   /* TGK */       \
    YHR,    /* TGW */       \
    YWR,    /* TGD */       \
    YDR,    /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGO */       \
    default: NULL           \
)
#define     vst1(D, K, V)    (vst1_funcof(D)(D,K,V))

PUBLIC(Vwyu,vst1wyu) (Vwyu d, Rc(0, 31) k,     _Bool v)
{
    return  (VWYU_VST1)(d, k, v);
}

PUBLIC(Vwbu,vst1wbu) (Vwbu d, Rc(0,  3) k,   uint8_t v)
{
    return (VWBU_VST1)(d, k, v);
}

PUBLIC(Vwbi,vst1wbi) (Vwbi d, Rc(0,  3) k,    int8_t v)
{
    return (VWBI_VST1)(d, k, v);
}

PUBLIC(Vwbc,vst1wbc) (Vwbc d, Rc(0,  3) k,      char v)
{
    return (VWBC_VST1)(d, k, v);
}

PUBLIC(Vwhu,vst1whu) (Vwhu d, Rc(0,  1) k,  uint16_t v)
{
    return (VWHU_VST1)(d, k, v);
}

PUBLIC(Vwhi,vst1whi) (Vwhi d, Rc(0,  1) k,   int16_t v)
{
    return (VWHI_VST1)(d, k, v);
}

PUBLIC(Vwhf,vst1whf) (Vwhf d, Rc(0,  1) k,   flt16_t v)
{
    return (VWHF_VST1)(d, k, v);
}


PUBLIC(Vdyu,vst1dyu) (Vdyu d, Rc(0, 63) k,     _Bool v)
{
    return  (VDYU_VST1)(d, k, v);
}

PUBLIC(Vdbu,vst1dbu) (Vdbu d, Rc(0,  7) k,   uint8_t v)
{
    return  (VDBU_VST1)(d, k, v);
}

PUBLIC(Vdbi,vst1dbi) (Vdbi d, Rc(0,  7) k,    int8_t v)
{
    return  (VDBI_VST1)(d, k, v);
}

PUBLIC(Vdbc,vst1dbc) (Vdbc d, Rc(0,  7) k,      char v)
{
    return  (VDBC_VST1)(d, k, v);
}

PUBLIC(Vdhu,vst1dhu) (Vdhu d, Rc(0,  3) k,  uint16_t v)
{
    return  (VDHU_VST1)(d, k, v);
}

PUBLIC(Vdhi,vst1dhi) (Vdhi d, Rc(0,  3) k,   int16_t v)
{
    return  (VDHI_VST1)(d, k, v);
}

PUBLIC(Vdhf,vst1dhf) (Vdhf d, Rc(0,  3) k,   flt16_t v)
{
    return  (VDHF_VST1)(d, k, v);
}

PUBLIC(Vdwu,vst1dwu) (Vdwu d, Rc(0,  1) k,  uint32_t v)
{
    return  (VDWU_VST1)(d, k, v);
}

PUBLIC(Vdwi,vst1dwi) (Vdwi d, Rc(0,  1) k,   int32_t v)
{
    return  (VDWI_VST1)(d, k, v);
}

PUBLIC(Vdwf,vst1dwf) (Vdwf d, Rc(0,  1) k,     float v)
{
    return  (VDWF_VST1)(d, k, v);
}


PUBLIC(Vqyu,vst1qyu) (Vqyu d, Rc(0,127) k,    _Bool v)
{
    return (VQYU_VST1)(d, k, v);
}

PUBLIC(Vqbu,vst1qbu) (Vqbu d, Rc(0, 15) k,  uint8_t v)
{
    return (VQBU_VST1)(d, k, v);
}

PUBLIC(Vqbi,vst1qbi) (Vqbi d, Rc(0, 15) k,   int8_t v)
{
    return (VQBI_VST1)(d, k, v);
}

PUBLIC(Vqbc,vst1qbc) (Vqbc d, Rc(0, 15) k,     char v)
{
    return (VQBC_VST1)(d, k, v);
}

PUBLIC(Vqhu,vst1qhu) (Vqhu d, Rc(0,  7) k, uint16_t v)
{
    return (VQHU_VST1)(d, k, v);
}

PUBLIC(Vqhi,vst1qhi) (Vqhi d, Rc(0,  7) k,  int16_t v)
{
    return (VQHI_VST1)(d, k, v);
}

PUBLIC(Vqhf,vst1qhf) (Vqhf d, Rc(0,  7) k,  flt16_t v)
{
    return (VQHF_VST1)(d, k, v);
}

PUBLIC(Vqwu,vst1qwu) (Vqwu d, Rc(0,  3) k, uint32_t v)
{
    return (VQWU_VST1)(d, k, v);
}

PUBLIC(Vqwi,vst1qwi) (Vqwi d, Rc(0,  3) k,  int32_t v)
{
    return (VQWI_VST1)(d, k, v);
}

PUBLIC(Vqwf,vst1qwf) (Vqwf d, Rc(0,  3) k,    float v)
{
    return (VQWF_VST1)(d, k, v);
}

PUBLIC(Vqdu,vst1qdu) (Vqdu d, Rc(0,  1) k, uint64_t v)
{
    return (VQDU_VST1)(d, k, v);
}

PUBLIC(Vqdi,vst1qdi) (Vqdi d, Rc(0,  1) k,  int64_t v)
{
    return (VQDI_VST1)(d, k, v);
}

PUBLIC(Vqdf,vst1qdf) (Vqdf d, Rc(0,  1) k,   double v)
{
    return (VQDF_VST1)(d, k, v);
}


#define     vst1wyu     VWYU_VST1
#define     vst1wbu     VWBU_VST1
#define     vst1wbi     VWBI_VST1
#define     vst1wbc     VWBC_VST1
#define     vst1whu     VWHU_VST1
#define     vst1whi     VWHI_VST1
#define     vst1whf     VWHF_VST1


#define     vst1dyu     VDYU_VST1
#define     vst1dbu     VDBU_VST1
#define     vst1dbi     VDBI_VST1
#define     vst1dbc     VDBC_VST1
#define     vst1dhu     VDHU_VST1
#define     vst1dhi     VDHI_VST1
#define     vst1dhf     VDHF_VST1
#define     vst1dwu     VDWU_VST1
#define     vst1dwi     VDWI_VST1
#define     vst1dwf     VDWF_VST1

#define     vst1qyu     VQYU_VST1
#define     vst1qbu     VQBU_VST1
#define     vst1qbi     VQBI_VST1
#define     vst1qbc     VQBC_VST1
#define     vst1qhu     VQHU_VST1
#define     vst1qhi     VQHI_VST1
#define     vst1qhf     VQHF_VST1
#define     vst1qwu     VQWU_VST1
#define     vst1qwi     VQWI_VST1
#define     vst1qwf     VQWF_VST1
#define     vst1qdu     VQDU_VST1
#define     vst1qdi     VQDI_VST1
#define     vst1qdf     VQDF_VST1


#if _LEAVE_VST1
}
#endif

#if _LEAVE_VST_
}
#endif

#if _ENTER_DUP_
{
#endif

#if _ENTER_DUPW
{
#endif

/*  dupw:
    Set each lane of a 32 bit multielement SIMD vector to
    to the same value. Other names used for this operation
    include "splat" and "broadcast".
*/

#define  UINT8_DUPW      UINT8_BASE(DUPW)
#define   INT8_DUPW       INT8_BASE(DUPW)
#define UINT16_DUPW     UINT16_BASE(DUPW)
#define  INT16_DUPW      INT16_BASE(DUPW)

// K=YHR
PUBLIC(Vwyu,dupwyu) ( _Bool   x);
PUBLIC(Vwbu,dupwbu) ( uint8_t x);
PUBLIC(Vwbi,dupwbi) (  int8_t x);
PUBLIC(Vwbc,dupwbc) (  char   x);
PUBLIC(Vwhu,dupwhu) (uint16_t x);
PUBLIC(Vwhi,dupwhi) ( int16_t x);
PUBLIC(Vwhf,dupwhf) ( flt16_t x);

// W=YHR
PUBLIC(Vwyu,dupwwyu)(Vwyu v, Rc(0, 31) k);
PUBLIC(Vwbu,dupwwbu)(Vwbu v, Rc(0,  3) k);
PUBLIC(Vwbi,dupwwbi)(Vwbi v, Rc(0,  3) k);
PUBLIC(Vwbc,dupwwbc)(Vwbc v, Rc(0,  3) k);
PUBLIC(Vwhu,dupwwhu)(Vwhu v, Rc(0,  1) k);
PUBLIC(Vwhi,dupwwhi)(Vwhi v, Rc(0,  1) k);
PUBLIC(Vwhf,dupwwhf)(Vwhf v, Rc(0,  1) k);

// D=YHR
PUBLIC(Vwyu,dupwdyu)(Vdyu v, Rc(0, 63) k);
PUBLIC(Vwbu,dupwdbu)(Vdbu v, Rc(0,  7) k);
PUBLIC(Vwbi,dupwdbi)(Vdbi v, Rc(0,  7) k);
PUBLIC(Vwbc,dupwdbc)(Vdbc v, Rc(0,  7) k);
PUBLIC(Vwhu,dupwdhu)(Vdhu v, Rc(0,  3) k);
PUBLIC(Vwhi,dupwdhi)(Vdhi v, Rc(0,  3) k);
PUBLIC(Vwhf,dupwdhf)(Vdhf v, Rc(0,  3) k);

// Q=YHR
PUBLIC(Vwyu,dupwqyu)(Vqyu v, Rc(0,127) k);
PUBLIC(Vwbu,dupwqbu)(Vqbu v, Rc(0, 15) k);
PUBLIC(Vwbi,dupwqbi)(Vqbi v, Rc(0, 15) k);
PUBLIC(Vwbc,dupwqbc)(Vqbc v, Rc(0, 15) k);
PUBLIC(Vwhu,dupwqhu)(Vqhu v, Rc(0,  7) k);
PUBLIC(Vwhi,dupwqhi)(Vqhi v, Rc(0,  7) k);
PUBLIC(Vwhf,dupwqhf)(Vqhf v, Rc(0,  7) k);

// O=YHR
PUBLIC(Vwyu,dupwoyu)(Vqyu v, Rc(0,255) k);
PUBLIC(Vwbu,dupwobu)(Vqbu v, Rc(0, 31) k);
PUBLIC(Vwbi,dupwobi)(Vqbi v, Rc(0, 31) k);
PUBLIC(Vwbc,dupwobc)(Vqbc v, Rc(0, 31) k);
PUBLIC(Vwhu,dupwohu)(Vqhu v, Rc(0, 15) k);
PUBLIC(Vwhi,dupwohi)(Vqhi v, Rc(0, 15) k);
PUBLIC(Vwhf,dupwohf)(Vqhf v, Rc(0, 15) k);

// S=YHR
PUBLIC(Vwyu,dupwsyu)(Vqyu v, Rc(0,512) k);
PUBLIC(Vwbu,dupwsbu)(Vqbu v, Rc(0, 63) k);
PUBLIC(Vwbi,dupwsbi)(Vqbi v, Rc(0, 63) k);
PUBLIC(Vwbc,dupwsbc)(Vqbc v, Rc(0, 63) k);
PUBLIC(Vwhu,dupwshu)(Vqhu v, Rc(0, 31) k);
PUBLIC(Vwhi,dupwshi)(Vqhi v, Rc(0, 31) k);
PUBLIC(Vwhf,dupwshf)(Vqhf v, Rc(0, 31) k);

#define     dupw_funcof(X)  \
FUNCOF(                     \
    dupw,   (   X   ),      \
    YHR,    /* TGK */       \
    YHR,    /* TGW */       \
    YHR,    /* TGD */       \
    YHR,    /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGO */       \
    default: NULL           \
)
#define     dupw(X)     (dupw_funcof(X)(X))

// K=YHR
PUBLIC(Vwyu,dupwyu) ( _Bool   x)    {return   (BOOL_DUPW)(x);}
PUBLIC(Vwbu,dupwbu) ( uint8_t x)    {return  (UINT8_DUPW)(x);}
PUBLIC(Vwbi,dupwbi) (  int8_t x)    {return   (INT8_DUPW)(x);}
PUBLIC(Vwbc,dupwbc) (  char   x)    {return   (CHAR_DUPW)(x);}
PUBLIC(Vwhu,dupwhu) (uint16_t x)    {return (UINT16_DUPW)(x);}
PUBLIC(Vwhi,dupwhi) ( int16_t x)    {return  (INT16_DUPW)(x);}
PUBLIC(Vwhf,dupwhf) ( flt16_t x)    {return  (FLT16_DUPW)(x);}

// W=YHR
PUBLIC(Vwyu,dupwwyu)(Vwyu v, Rc(0, 31) k) {return (VWYU_DUPW)(v, k);}
PUBLIC(Vwbu,dupwwbu)(Vwbu v, Rc(0,  3) k) {return (VWBU_DUPW)(v, k);}
PUBLIC(Vwbi,dupwwbi)(Vwbi v, Rc(0,  3) k) {return (VWBI_DUPW)(v, k);}
PUBLIC(Vwbc,dupwwbc)(Vwbc v, Rc(0,  3) k) {return (VWBC_DUPW)(v, k);}
PUBLIC(Vwhu,dupwwhu)(Vwhu v, Rc(0,  1) k) {return (VWHU_DUPW)(v, k);}
PUBLIC(Vwhi,dupwwhi)(Vwhi v, Rc(0,  1) k) {return (VWHI_DUPW)(v, k);}
PUBLIC(Vwhf,dupwwhf)(Vwhf v, Rc(0,  1) k) {return (VWHF_DUPW)(v, k);}

// D=YHR
PUBLIC(Vwyu,dupwdyu)(Vdyu v, Rc(0, 63) k) {return (VDYU_DUPW)(v, k);}
PUBLIC(Vwbu,dupwdbu)(Vdbu v, Rc(0,  7) k) {return (VDBU_DUPW)(v, k);}
PUBLIC(Vwbi,dupwdbi)(Vdbi v, Rc(0,  7) k) {return (VDBI_DUPW)(v, k);}
PUBLIC(Vwbc,dupwdbc)(Vdbc v, Rc(0,  7) k) {return (VDBC_DUPW)(v, k);}
PUBLIC(Vwhu,dupwdhu)(Vdhu v, Rc(0,  3) k) {return (VDHU_DUPW)(v, k);}
PUBLIC(Vwhi,dupwdhi)(Vdhi v, Rc(0,  3) k) {return (VDHI_DUPW)(v, k);}
PUBLIC(Vwhf,dupwdhf)(Vdhf v, Rc(0,  3) k) {return (VDHF_DUPW)(v, k);}

// Q=YHR
PUBLIC(Vwyu,dupwqyu)(Vqyu v, Rc(0,127) k) {return (VQYU_DUPW)(v, k);}
PUBLIC(Vwbu,dupwqbu)(Vqbu v, Rc(0, 15) k) {return (VQBU_DUPW)(v, k);}
PUBLIC(Vwbi,dupwqbi)(Vqbi v, Rc(0, 15) k) {return (VQBI_DUPW)(v, k);}
PUBLIC(Vwbc,dupwqbc)(Vqbc v, Rc(0, 15) k) {return (VQBC_DUPW)(v, k);}
PUBLIC(Vwhu,dupwqhu)(Vqhu v, Rc(0,  7) k) {return (VQHU_DUPW)(v, k);}
PUBLIC(Vwhi,dupwqhi)(Vqhi v, Rc(0,  7) k) {return (VQHI_DUPW)(v, k);}
PUBLIC(Vwhf,dupwqhf)(Vqhf v, Rc(0,  7) k) {return (VQHF_DUPW)(v, k);}


#if _LEAVE_DUPW
}
#endif

#if _ENTER_DUPD
{
#endif
/*  dupd:
    Set each lane of a multielement 64 bit SIMD vector to
    to the same value. Other names used for this operation
    include "splat" and "broadcast".
*/

#define  UINT8_DUPD      UINT8_BASE(DUPD)
#define   INT8_DUPD       INT8_BASE(DUPD)
#define UINT16_DUPD     UINT16_BASE(DUPD)
#define  INT16_DUPD      INT16_BASE(DUPD)
#define UINT32_DUPD     UINT32_BASE(DUPD)
#define  INT32_DUPD      INT32_BASE(DUPD)

PUBLIC(Vdyu,dupdyu) (   _Bool x) {return   BOOL_DUPD(x);}
PUBLIC(Vdbu,dupdbu) ( uint8_t x) {return  UINT8_DUPD(x);}
PUBLIC(Vdbi,dupdbi) (  int8_t x) {return   INT8_DUPD(x);}
PUBLIC(Vdbc,dupdbc) (    char x) {return   CHAR_DUPD(x);}
PUBLIC(Vdhu,dupdhu) (uint16_t x) {return UINT16_DUPD(x);}
PUBLIC(Vdhi,dupdhi) ( int16_t x) {return  INT16_DUPD(x);}
PUBLIC(Vdhf,dupdhf) ( flt16_t x) {return  FLT16_DUPD(x);}
PUBLIC(Vdwu,dupdwu) (uint32_t x) {return UINT32_DUPD(x);}
PUBLIC(Vdwi,dupdwi) ( int32_t x) {return  INT32_DUPD(x);}
PUBLIC(Vdwf,dupdwf) (   float x) {return    FLT_DUPD(x);}

PUBLIC(Vdyu,dupdwyu) (Vwyu v, Rc(0, 32) k) {return (VWYU_DUPD)(v, k);}
PUBLIC(Vdbu,dupdwbu) (Vwbu v, Rc(0,  3) k) {return (VWBU_DUPD)(v, k);}
PUBLIC(Vdbi,dupdwbi) (Vwbi v, Rc(0,  3) k) {return (VWBI_DUPD)(v, k);}
PUBLIC(Vdbc,dupdwbc) (Vwbc v, Rc(0,  3) k) {return (VWBC_DUPD)(v, k);}
PUBLIC(Vdhu,dupdwhu) (Vwhu v, Rc(0,  1) k) {return (VWHU_DUPD)(v, k);}
PUBLIC(Vdhi,dupdwhi) (Vwhi v, Rc(0,  1) k) {return (VWHI_DUPD)(v, k);}
PUBLIC(Vdhf,dupdwhf) (Vwhf v, Rc(0,  1) k) {return (VWHF_DUPD)(v, k);}
PUBLIC(Vdwu,dupdwwu) (Vwwu v, int const k) {return (VWWU_DUPD)(v, k);}
PUBLIC(Vdwi,dupdwwi) (Vwwi v, int const k) {return (VWWI_DUPD)(v, k);}
PUBLIC(Vdwf,dupdwwf) (Vwwf v, int const k) {return (VWWF_DUPD)(v, k);}

PUBLIC(Vdyu,dupddyu) (Vdyu v, Rc(0, 63) k) {return (VDYU_DUPD)(v, k);}
PUBLIC(Vdbu,dupddbu) (Vdbu v, Rc(0,  7) k) {return (VDBU_DUPD)(v, k);}
PUBLIC(Vdbi,dupddbi) (Vdbi v, Rc(0,  7) k) {return (VDBI_DUPD)(v, k);}
PUBLIC(Vdbc,dupddbc) (Vdbc v, Rc(0,  7) k) {return (VDBC_DUPD)(v, k);}
PUBLIC(Vdhu,dupddhu) (Vdhu v, Rc(0,  3) k) {return (VDHU_DUPD)(v, k);}
PUBLIC(Vdhi,dupddhi) (Vdhi v, Rc(0,  3) k) {return (VDHI_DUPD)(v, k);}
PUBLIC(Vdhf,dupddhf) (Vdhf v, Rc(0,  3) k) {return (VDHF_DUPD)(v, k);}
PUBLIC(Vdwu,dupddwu) (Vdhu v, Rc(0,  1) k) {return (VDWU_DUPD)(v, k);}
PUBLIC(Vdwi,dupddwi) (Vdhi v, Rc(0,  1) k) {return (VDWI_DUPD)(v, k);}
PUBLIC(Vdwf,dupddwf) (Vdhf v, Rc(0,  1) k) {return (VDWF_DUPD)(v, k);}

PUBLIC(Vdyu,dupdqyu) (Vqyu v, Rc(0,127) k) {return (VQYU_DUPD)(v, k);}
PUBLIC(Vdbu,dupdqbu) (Vqbu v, Rc(0, 15) k) {return (VQBU_DUPD)(v, k);}
PUBLIC(Vdbi,dupdqbi) (Vqbi v, Rc(0, 15) k) {return (VQBI_DUPD)(v, k);}
PUBLIC(Vdbc,dupdqbc) (Vqbc v, Rc(0, 15) k) {return (VQBC_DUPD)(v, k);}
PUBLIC(Vdhu,dupdqhu) (Vqhu v, Rc(0,  7) k) {return (VQHU_DUPD)(v, k);}
PUBLIC(Vdhi,dupdqhi) (Vqhi v, Rc(0,  7) k) {return (VQHI_DUPD)(v, k);}
PUBLIC(Vdhf,dupdqhf) (Vqhf v, Rc(0,  7) k) {return (VQHF_DUPD)(v, k);}
PUBLIC(Vdhu,dupdqwu) (Vqwu v, Rc(0,  3) k) {return (VQWU_DUPD)(v, k);}
PUBLIC(Vdhi,dupdqwi) (Vqwi v, Rc(0,  3) k) {return (VQWI_DUPD)(v, k);}
PUBLIC(Vdhf,dupdqwf) (Vqwf v, Rc(0,  3) k) {return (VQWF_DUPD)(v, k);}

#define     dupd_funcof(X)  \
FUNCOF(                     \
    dupw,   (   X   )       \
    YWR,    /* TGK */       \
    YWR,    /* TGW */       \
    YWR,    /* TGD */       \
    YWR,    /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGO */       \
    default: NULL           \
)
#define     dupw(X)     (dupw_funcof(X)(X))


#define     dupdyu    BOOL_DUPD
#define     dupdbu   UINT8_DUPD
#define     dupdbi    INT8_DUPD
#define     dupdbc    CHAR_DUPD
#define     dupdhu  UINT16_DUPD
#define     dupdhi   INT16_DUPD
#define     dupdhf   FLT16_DUPD
#define     dupdwu  UINT32_DUPD
#define     dupdwi   INT32_DUPD
#define     dupdwf   FLT32_DUPD


#define     dupdwyu  VWYU_DUPD
#define     dupdwbu  VWBU_DUPD
#define     dupdwbi  VWBI_DUPD
#define     dupdwbc  VWBC_DUPD
#define     dupdwhu  VWHU_DUPD
#define     dupdwhi  VWHI_DUPD
#define     dupdwhf  VWHF_DUPD
#define     dupdwwu  VWWU_DUPD
#define     dupdwwi  VWWI_DUPD
#define     dupdwwf  VWWF_DUPD

#define     dupddyu  VDYU_DUPD
#define     dupddbu  VDBU_DUPD
#define     dupddbi  VDBI_DUPD
#define     dupddbc  VDBC_DUPD
#define     dupddhu  VDHU_DUPD
#define     dupddhi  VDHI_DUPD
#define     dupddhf  VDHF_DUPD
#define     dupddwu  VDWU_DUPD
#define     dupddwi  VDWI_DUPD
#define     dupddwf  VDWF_DUPD

#define     dupdqyu  VQYU_DUPD
#define     dupdqbu  VQBU_DUPD
#define     dupdqbi  VQBI_DUPD
#define     dupdqbc  VQBC_DUPD
#define     dupdqhu  VQHU_DUPD
#define     dupdqhi  VQHI_DUPD
#define     dupdqhf  VQHF_DUPD
#define     dupdqwu  VQWU_DUPD
#define     dupdqwi  VQWI_DUPD
#define     dupdqwf  VQWF_DUPD

#if _LEAVE_DUPD
}
#endif

#if _LEAVE_DUP_
}
#endif


#if _ENTER_CV__
{
#endif

/*  
cvyu:
cvbu, cvbi, cvbc:
cvhu, cvhi:
cvwu, cvwi:
cvdu, cvdi:
    Convert each scalar in the operand to the type implied
    by the last two letters of the operation name with the
    same semantics as a C cast. SIMD vectors are resized 
    to fit the same number of elements that were in the
    original operand. E.g. cvhiqwu takes a 128 bit vector 
    consisting of 4×uint32_t and returns a 64 bit vector 
    consisting of 4×int16_t. The result of converting an 
    unsigned value to a signed type that is to narrow to
    represent it is implementation defined. For the
    record, all known C implementations for hosted systems
    simply reinterpret the operand's least significant 
    bits.
    TODO: debate requiring that the conversion of a value 
    to a signed type too small to represent it be 
    implemented by simply reinterpreting the operand's 
    least significant bits.

cvhf, cvwf, cvdf:
    Convert each scalar in the operand to a float. 

cvbz, cvhz, cvwz, cvdz:
    Convert each scalar in the operand to the
    corresponding unsigned type. Negative values are 
    clamped to zero and positive values greater than the
    maximum representable by the type are clamped to the 
    maximum. 

cvbs, cvhs, cvws, cvds:
    Convert each scalar in the operand to the
    corresponding signed type. Values outside the range 
    of what the type can represent are clamped to the
    minimum or maximum, whichever is closer. 
    E.g. cvbshu(60000) returns (int8_t){127} 

cvhm, cvwm, cvdm, cvbf:
    These are reserved


*/

#if _ENTER_CVB_
{
#endif

#if _ENTER_CVBU
{
#endif
#if _LEAVE_CVBU
}
#endif

#if _ENTER_CVBI
{
#endif
#if _LEAVE_CVBI
}
#endif

#if _ENTER_CVBZ
{
#endif

PUBLIC(uint8_t,cvbzbi )(  int8_t x);
PUBLIC(uint8_t,cvbzbc )(    char x);
PUBLIC(uint8_t,cvbzhu )(uint16_t x);
PUBLIC(uint8_t,cvbzhi )( int16_t x);
PUBLIC(uint8_t,cvbzwu )(uint32_t x);
PUBLIC(uint8_t,cvbzwi )( int32_t x);
PUBLIC(uint8_t,cvbzdu )(uint64_t x);
PUBLIC(uint8_t,cvbzdi )( int64_t x);
PUBLIC(uint8_t,cvbzhf )( flt16_t x);
PUBLIC(uint8_t,cvbzwf )(   float x);
PUBLIC(uint8_t,cvbzdf )(  double x);

PUBLIC(   Vwbu,cvbzdhu)(    Vdhu x);
PUBLIC(   Vwbu,cvbzdhi)(    Vdhi x);
PUBLIC(   Vdbu,cvbzqhu)(    Vqhu x);
PUBLIC(   Vdbu,cvbzqhi)(    Vqhi x);

PUBLIC(uint8_t,cvbzhu )(uint16_t x) {return UINT16_CVBZ(x);}
PUBLIC(uint8_t,cvbzhi )( int16_t x) {return  INT16_CVBZ(x);}
PUBLIC(uint8_t,cvbzwu )(uint32_t x) {return UINT32_CVBZ(x);}
PUBLIC(uint8_t,cvbzwi )( int32_t x) {return  INT32_CVBZ(x);}
PUBLIC(uint8_t,cvbzdu )(uint64_t x) {return UINT64_CVBZ(x);}
PUBLIC(uint8_t,cvbzdi )( int64_t x) {return  INT64_CVBZ(x);}
PUBLIC(uint8_t,cvbzhf )( flt16_t x) {return  FLT16_CVBZ(x);}
PUBLIC(uint8_t,cvbzwf )(   float x) {return    FLT_CVBZ(x);}
PUBLIC(uint8_t,cvbzdf )(  double x) {return    DBL_CVBZ(x);}
PUBLIC(   Vwbu,cvbzdhu)(    Vdhu x) {return   VDHU_CVBZ(x);}
PUBLIC(   Vwbu,cvbzdhi)(    Vdhi x) {return   VDHI_CVBZ(x);}
PUBLIC(   Vdbu,cvbzqhu)(    Vqhu x) {return   VQHU_CVBZ(x);}
PUBLIC(   Vdbu,cvbzqhi)(    Vqhi x) {return   VQHI_CVBZ(x);}
PUBLIC(   Vwbu,cvbzqwu)(    Vqwu x) {return   VQWU_CVBZ(x);}
PUBLIC(   Vwbu,cvbzqwi)(    Vqwi x) {return   VQWI_CVBZ(x);}
PUBLIC(   Vwbu,cvbzqwf)(    Vqwf x) {return   VQWF_CVBZ(x);}

#define     cvbz_funcof(X)  \
FUNCOF(                     \
    cvbz,                   \
    (X),                    \
    HDZ,    /* TGK */       \
    NONE,   /* TGW */       \
    HDZ,    /* TGD */       \
    HDZ,    /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGO */       \
    default: NULL           \
)
#define cvbz(X)  (cvbz_funcof(X)(X))
#if _LEAVE_CVBZ
}
#endif

#if _ENTER_CVBS
{
#endif
#if _LEAVE_CVBS
}
#endif



#if _LEAVE_CVB_
}
#endif

#if _ENTER_CVH_
{
#endif
#if _ENTER_CVHU
{
#endif
#if _LEAVE_CVHU
}
#endif

#if _ENTER_CVHI
{
#endif
#if _LEAVE_CVHI
}
#endif

#if _ENTER_CVHZ
{
#endif
#if _LEAVE_CVHZ
}
#endif

#if _ENTER_CVHS
{
#endif
#if _LEAVE_CVHS
}
#endif

#if _LEAVE_CVH_
}
#endif

#if _ENTER_CVW_
{
#endif

#if _ENTER_CVWU
{
#endif
#if _LEAVE_CVWU
}
#endif

#if _ENTER_CVWI
{
#endif
#if _LEAVE_CVWI
}
#endif

#if _ENTER_CVWZ
{
#endif

INLINE(uint32_t,cvwzwi ) ( int32_t x);
INLINE(uint32_t,cvwzwf ) (   float x);
INLINE(uint32_t,cvwzdu ) (uint64_t x);
INLINE(uint32_t,cvwzdi ) ( int64_t x);
INLINE(uint32_t,cvwzlu ) (   ulong x);
INLINE(uint32_t,cvwzli ) (    long x);

INLINE(    Vwwu,cvwzwwu) (    Vwwu x);
INLINE(    Vwwu,cvwzwwi) (    Vwwi x);
INLINE(    Vwwu,cvwzwwf) (    Vwwf x);

INLINE(    Vwwu,cvwzdhu) (    Vdhu x);
INLINE(    Vwwu,cvwzdhi) (    Vdhi x);
INLINE(    Vwwu,cvwzdhf) (    Vdhf x);

INLINE(    Vwwu,cvwzdhu) (    Vdhu x);
INLINE(    Vwwu,cvwzdhi) (    Vdhi x);
INLINE(    Vwwu,cvwzdhf) (    Vdhf x);

INLINE(    Vwwu,cvwzqwu) (    Vqwu x);
INLINE(    Vwwu,cvwzqwi) (    Vqwi x);
INLINE(    Vwwu,cvwzqwf) (    Vqwf x);


#if _LEAVE_CVWZ
}
#endif

#if _ENTER_CVWS
{
#endif
#if _LEAVE_CVWS
}
#endif

#if _LEAVE_CVW_
}
#endif

#if _ENTER_CVD_
{
#endif

#if _ENTER_CVDU
{
#endif
#if _LEAVE_CVDU
}
#endif

#if _ENTER_CVDI
{
#endif
#if _LEAVE_CVDI
}
#endif

#if _ENTER_CVDZ
{
#endif
#if _LEAVE_CVDZ
}
#endif

#if _ENTER_CVDS
{
#endif
#if _LEAVE_CVDS
}
#endif

#if _LEAVE_CVD_
}
#endif

#if _LEAVE_CV
}
#endif



#if _ENTER_VXTL
{
#endif

INLINE(uint8_t,USHRT_VXTL) (unsigned short c)
{
#define     USHRT_VXTL(C)   (USHRT_ASTG(c).Lo.U)
    return  USHRT_VXTL(c);
}

INLINE( int8_t, SHRT_VXTL) (short c)
{
#define     SHRT_VXTL(C)    (SHRT_ASTG(C).Lo.I)
    return  SHRT_VXTL(c);
}

INLINE(uint16_t,UINT_VXTL) (unsigned int c)
{
#define     UINT_VXTL(C)    (UINT_ASTG(C).Lo.U)
    return  UINT_VXTL(c);
}

INLINE( int16_t, INT_VXTL) (int c)
{
#define     INT_VXTL(C)     (INT_ASTG(C).Lo.I)
    return  INT_VXTL(c);
}

#if DWRD_NLONG == 2

INLINE(uint16_t, ULONG_VXTL) (unsigned long c)
{
#   define  ULONG_VXTL(C)  (ULONG_ASTG(C).Lo.U)
    return  ULONG_VXTL(c);
}

INLINE( int16_t,  LONG_VXTL) (long c)
{
#   define  LONG_VXTL(C)  (LONG_ASTG(C).Lo.I)
    return  LONG_VXTL(c);
}

#else

INLINE(uint32_t, ULONG_VXTL) (unsigned long c)
{
#   define  ULONG_VXTL(C)  (ULONG_ASTG(C).Lo.U)
    return  ULONG_VXTL(c);
}

INLINE( int32_t, LONG_VXTL) (long c)
{
#   define  LONG_VXTL(C)  (LONG_ASTG(C).Lo.I)
    return  LONG_VXTL(c);
}

#endif

#if QUAD_NLLONG == 2

INLINE(uint32_t,ULLONG_VXTL) (unsigned long long c)
{
#define     ULLONG_VXTL(C)  (ULLONG_ASTG(C).Lo.U)
    return  ULLONG_VXTL(c);
}

INLINE( int32_t, LLONG_VXTL) (long long c)
{
#define     LLONG_VXTL(C)  (LLONG_ASTG(C).Lo.I)
    return  LLONG_VXTL(c);
}

#else

INLINE(uint64_t,ULLONG_VXTL) (unsigned long long c)
{
#define     ULLONG_VXTL(C)  (ULLONG_ASTG(C).Lo.U)
    return  ULLONG_VXTL(c);
}

INLINE(int64_t, LLONG_VXTL) (long long c)
{
#define     LLONG_VXTL(C)  (LLONG_ASTG(C).Lo.I)
    return  LLONG_VXTL(c);
}

#endif

#define     UINT16_VXTL UINT16_BASE(VXTL)
#define     INT16_VXTL  INT16_BASE(VXTL)
#define     UINT32_VXTL UINT32_BASE(VXTL)
#define     INT32_VXTL  INT32_BASE(VXTL)
#define     UINT64_VXTL UINT64_BASE(VXTL)
#define     INT64_VXTL  INT64_BASE(VXTL)

PUBLIC(uint8_t, vxtlhu)(uint16_t c);
PUBLIC( int8_t, vxtlhi) (int16_t c);
PUBLIC(uint16_t,vxtlwu)(uint32_t c);
PUBLIC( int16_t,vxtlwi) (int32_t c);
PUBLIC(uint32_t,vxtldu)(uint64_t c);
PUBLIC( int32_t,vxtldi) (int64_t c);
#if DWRD_NLONG == 2
PUBLIC(uint16_t,vxtllu)(ulong c);
PUBLIC( int16_t,vxtlli) (long c);
#elif QUAD_NLLONG == 2
PUBLIC(uint32_t,vxtllu)(ullong c);
PUBLIC( int32_t,vxtlli) (llong c);
#elif QUAD_NLLONG == 1
PUBLIC(uint64_t,vxtlqu)(ullong c);
PUBLIC( int64_t,vxtlqi) (llong c);
#endif

PUBLIC(Vwyu,vxtldyu)(Vdyu c);
PUBLIC(Vwbu,vxtldbu)(Vdbu c);
PUBLIC(Vwbi,vxtldbi)(Vdbi c);
PUBLIC(Vwbc,vxtldbc)(Vdbc c);
PUBLIC(Vwhu,vxtldhu)(Vdhu c);
PUBLIC(Vwhi,vxtldhi)(Vdhi c);
PUBLIC(Vwhf,vxtldhf)(Vdhf c);
PUBLIC(Vwwu,vxtldwu)(Vdwu c);
PUBLIC(Vwwi,vxtldwi)(Vdwi c);
PUBLIC(Vwwf,vxtldwf)(Vdwf c);

PUBLIC(Vdyu,vxtlqyu)(Vqyu c);
PUBLIC(Vdbu,vxtlqbu)(Vqbu c);
PUBLIC(Vdbi,vxtlqbi)(Vqbi c);
PUBLIC(Vdbc,vxtlqbc)(Vqbc c);
PUBLIC(Vdhu,vxtlqhu)(Vqhu c);
PUBLIC(Vdhi,vxtlqhi)(Vqhi c);
PUBLIC(Vdhf,vxtlqhf)(Vqhf c);
PUBLIC(Vdwu,vxtlqwu)(Vqwu c);
PUBLIC(Vdwi,vxtlqwi)(Vqwi c);
PUBLIC(Vdwf,vxtlqwf)(Vqwf c);
PUBLIC(Vddu,vxtlqdu)(Vqdu c);
PUBLIC(Vddi,vxtlqdi)(Vqdi c);
PUBLIC(Vddf,vxtlqdf)(Vqdf c);

PUBLIC(uint8_t, vxtlhu)(uint16_t c) {return UINT16_VXTL(c);}
PUBLIC( int8_t, vxtlhi) (int16_t c) {return  INT16_VXTL(c);}
PUBLIC(uint16_t,vxtlwu)(uint32_t c) {return UINT32_VXTL(c);}
PUBLIC( int16_t,vxtlwi) (int32_t c) {return  INT32_VXTL(c);}
PUBLIC(uint32_t,vxtldu)(uint64_t c) {return UINT64_VXTL(c);}
PUBLIC( int32_t,vxtldi) (int64_t c) {return  INT64_VXTL(c);}
#if DWRD_NLONG == 2
PUBLIC(uint16_t,vxtllu)(ulong c)    {return ULONG_VXTL(c);}
PUBLIC( int16_t,vxtlli) (long c)    {return  LONG_VXTL(c);}
#elif QUAD_NLLONG == 2
PUBLIC(uint32_t,vxtllu)(ullong c)   {return ULLONG_VXTL(c);}
PUBLIC( int32_t,vxtlli) (llong c)   {return  LLONG_VXTL(c);}
#elif QUAD_NLLONG == 1
PUBLIC(uint64_t,vxtlqu)(ullong c)   {return ULLONG_VXTL(c);}
PUBLIC( int64_t,vxtlqi) (llong c)   {return  LLONG_VXTL(c);}
#endif

PUBLIC(Vwyu,vxtldyu)(Vdyu c) {return VDYU_VXTL(c);}
PUBLIC(Vwbu,vxtldbu)(Vdbu c) {return VDBU_VXTL(c);}
PUBLIC(Vwbi,vxtldbi)(Vdbi c) {return VDBI_VXTL(c);}
PUBLIC(Vwbc,vxtldbc)(Vdbc c) {return VDBC_VXTL(c);}
PUBLIC(Vwhu,vxtldhu)(Vdhu c) {return VDHU_VXTL(c);}
PUBLIC(Vwhi,vxtldhi)(Vdhi c) {return VDHI_VXTL(c);}
PUBLIC(Vwhf,vxtldhf)(Vdhf c) {return VDHF_VXTL(c);}
PUBLIC(Vwwu,vxtldwu)(Vdwu c) {return VDWU_VXTL(c);}
PUBLIC(Vwwi,vxtldwi)(Vdwi c) {return VDWI_VXTL(c);}
PUBLIC(Vwwf,vxtldwf)(Vdwf c) {return VDWF_VXTL(c);}

PUBLIC(Vdyu,vxtlqyu)(Vqyu c) {return VQYU_VXTL(c);}
PUBLIC(Vdbu,vxtlqbu)(Vqbu c) {return VQBU_VXTL(c);}
PUBLIC(Vdbi,vxtlqbi)(Vqbi c) {return VQBI_VXTL(c);}
PUBLIC(Vdbc,vxtlqbc)(Vqbc c) {return VQBC_VXTL(c);}
PUBLIC(Vdhu,vxtlqhu)(Vqhu c) {return VQHU_VXTL(c);}
PUBLIC(Vdhi,vxtlqhi)(Vqhi c) {return VQHI_VXTL(c);}
PUBLIC(Vdhf,vxtlqhf)(Vqhf c) {return VQHF_VXTL(c);}
PUBLIC(Vdwu,vxtlqwu)(Vqwu c) {return VQWU_VXTL(c);}
PUBLIC(Vdwi,vxtlqwi)(Vqwi c) {return VQWI_VXTL(c);}
PUBLIC(Vdwf,vxtlqwf)(Vqwf c) {return VQWF_VXTL(c);}
PUBLIC(Vddu,vxtlqdu)(Vqdu c) {return VQDU_VXTL(c);}
PUBLIC(Vddi,vxtlqdi)(Vqdi c) {return VQDI_VXTL(c);}
PUBLIC(Vddf,vxtlqdf)(Vqdf c) {return VQDF_VXTL(c);}


#define     vxtl_funcof(X)  \
FUNCOF(                     \
    vxtl,                   \
    (X),                    \
    HDZ,    /* TGK */       \
    NONE,   /* TGW */       \
    YWR,    /* TGD */       \
    YDR,    /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGO */       \
    default: NULL           \
)
#define     vxtl(X)  (vxtl_funcof(X)(X))


#if _LEAVE_VXTL
}
#endif

#if _ENTER_VXTR
{
#endif

INLINE(uint8_t,USHRT_VXTR) (unsigned short c)
{
#define     USHRT_VXTR(C)   (USHRT_ASTG(C).Hi.U)
    return  USHRT_VXTR(c);
}

INLINE( int8_t, SHRT_VXTR) (short c)
{
#define     SHRT_VXTR(C)   (SHRT_ASTG(C).Hi.I)
    return  SHRT_VXTR(c);
}

INLINE(uint16_t,UINT_VXTR) (unsigned int c)
{
#define     UINT_VXTR(C)   (UINT_ASTG(C).Hi.U)
    return  UINT_VXTR(c);
}

INLINE( int16_t, INT_VXTR) (int c)
{
#define     INT_VXTR(C)   (INT_ASTG(C).Hi.I)
    return  INT_VXTR(c);
}

#if DWRD_NLONG == 2

INLINE(uint16_t, ULONG_VXTR) (unsigned long c)
{
#   define  ULONG_VXTR(C)   (ULONG_ASTG(C).Hi.U)
    return  ULONG_VXTR(c);
}

INLINE( int16_t,  LONG_VXTR) (long c)
{
#   define  LONG_VXTR(C)   (LONG_ASTG(C).Hi.I)
    return  LONG_VXTR(c);
}

#else

INLINE(uint32_t, ULONG_VXTR) (unsigned long c)
{
#   define  ULONG_VXTR(C)   (ULONG_ASTG(C).Hi.U)
    return  ULONG_VXTR(c);
}

INLINE( int32_t, LONG_VXTR) (long c)
{
#   define  LONG_VXTR(C)   (LONG_ASTG(C).Hi.I)
    return  LONG_VXTR(c);
}

#endif

#if QUAD_NLLONG == 2

INLINE(uint32_t,ULLONG_VXTR) (unsigned long long x)
{
#define     ULLONG_VXTR(C)   (ULLONG_ASTG(C).Hi.U)
    return  ULLONG_VXTR(x);
}

INLINE( int32_t, LLONG_VXTR) (long long x)
{
#define     LLONG_VXTR(C)   (LLONG_ASTG(C).Hi.I)
    return  LLONG_VXTR(x);
}

#else

INLINE(uint64_t,ULLONG_VXTR) (unsigned long long x)
{
#define     ULLONG_VXTR(C)   (ULLONG_ASTG(C).Hi.U)
    return  ULLONG_VXTR(x);
}

INLINE(int64_t, LLONG_VXTR) (long long x)
{
#define     LLONG_VXTR(C)   (LLONG_ASTG(C).Hi.I)
    return  LLONG_VXTR(x);
}

#endif

#define     UINT16_VXTR UINT16_BASE(VXTR)
#define     INT16_VXTR  INT16_BASE(VXTR)
#define     UINT32_VXTR UINT32_BASE(VXTR)
#define     INT32_VXTR  INT32_BASE(VXTR)
#define     UINT64_VXTR UINT64_BASE(VXTR)
#define     INT64_VXTR  INT64_BASE(VXTR)

PUBLIC(uint8_t, vxtrhu)(uint16_t c);
PUBLIC( int8_t, vxtrhi) (int16_t c);
PUBLIC(uint16_t,vxtrwu)(uint32_t c);
PUBLIC( int16_t,vxtrwi) (int32_t c);
PUBLIC(uint32_t,vxtrdu)(uint64_t c);
PUBLIC( int32_t,vxtrdi) (int64_t c);
#if DWRD_NLONG == 2
PUBLIC(uint16_t,vxtrlu)(ulong c);
PUBLIC( int16_t,vxtrli) (long c);
#elif QUAD_NLLONG == 2
PUBLIC(uint32_t,vxtrlu)(ullong c);
PUBLIC( int32_t,vxtrli) (llong c);
#elif QUAD_NLLONG == 1
PUBLIC(uint64_t,vxtrqu)(ullong c);
PUBLIC( int64_t,vxtrqi) (llong c);
#endif

PUBLIC(Vwyu,vxtrdyu)(Vdyu c);
PUBLIC(Vwbc,vxtrdbc)(Vdbc c);
PUBLIC(Vwbu,vxtrdbu)(Vdbu c);
PUBLIC(Vwbi,vxtrdbi)(Vdbi c);
PUBLIC(Vwhu,vxtrdhu)(Vdhu c);
PUBLIC(Vwhi,vxtrdhi)(Vdhi c);
PUBLIC(Vwhf,vxtrdhf)(Vdhf c);
PUBLIC(Vwwu,vxtrdwu)(Vdwu c);
PUBLIC(Vwwi,vxtrdwi)(Vdwi c);
PUBLIC(Vwwf,vxtrdwf)(Vdwf c);

PUBLIC(Vdyu,vxtrqyu)(Vqyu c);
PUBLIC(Vdbu,vxtrqbu)(Vqbu c);
PUBLIC(Vdbi,vxtrqbi)(Vqbi c);
PUBLIC(Vdbc,vxtrqbc)(Vqbc c);
PUBLIC(Vdhu,vxtrqhu)(Vqhu c);
PUBLIC(Vdhi,vxtrqhi)(Vqhi c);
PUBLIC(Vdhf,vxtrqhf)(Vqhf c);
PUBLIC(Vdwu,vxtrqwu)(Vqwu c);
PUBLIC(Vdwi,vxtrqwi)(Vqwi c);
PUBLIC(Vdwf,vxtrqwf)(Vqwf c);
PUBLIC(Vddu,vxtrqdu)(Vqdu c);
PUBLIC(Vddi,vxtrqdi)(Vqdi c);
PUBLIC(Vddf,vxtrqdf)(Vqdf c);
PUBLIC(uint8_t, vxtrhu)(uint16_t c) {return UINT16_VXTR(c);}
PUBLIC( int8_t, vxtrhi) (int16_t c) {return  INT16_VXTR(c);}
PUBLIC(uint16_t,vxtrwu)(uint32_t c) {return UINT32_VXTR(c);}
PUBLIC( int16_t,vxtrwi) (int32_t c) {return  INT32_VXTR(c);}
PUBLIC(uint32_t,vxtrdu)(uint64_t c) {return UINT64_VXTR(c);}
PUBLIC( int32_t,vxtrdi) (int64_t c) {return  INT64_VXTR(c);}
#if DWRD_NLONG == 2
PUBLIC(uint16_t,vxtrlu)(ulong c)    {return ULONG_VXTR(c);}
PUBLIC( int16_t,vxtrli) (long c)    {return  LONG_VXTR(c);}
#elif QUAD_NLLONG == 2
PUBLIC(uint32_t,vxtrlu)(ullong c)   {return ULLONG_VXTR(c);}
PUBLIC( int32_t,vxtrli) (llong c)   {return  LLONG_VXTR(c);}
#elif QUAD_NLLONG == 1
PUBLIC(uint64_t,vxtrqu)(ullong c)   {return ULLONG_VXTR(c);}
PUBLIC( int64_t,vxtrqi) (llong c)   {return  LLONG_VXTR(c);}
#endif

PUBLIC(Vwyu,vxtrdyu)(Vdyu c) {return VDYU_VXTR(c);}
PUBLIC(Vwbu,vxtrdbu)(Vdbu c) {return VDBU_VXTR(c);}
PUBLIC(Vwbi,vxtrdbi)(Vdbi c) {return VDBI_VXTR(c);}
PUBLIC(Vwbc,vxtrdbc)(Vdbc c) {return VDBC_VXTR(c);}
PUBLIC(Vwhu,vxtrdhu)(Vdhu c) {return VDHU_VXTR(c);}
PUBLIC(Vwhi,vxtrdhi)(Vdhi c) {return VDHI_VXTR(c);}
PUBLIC(Vwhf,vxtrdhf)(Vdhf c) {return VDHF_VXTR(c);}
PUBLIC(Vwwu,vxtrdwu)(Vdwu c) {return VDWU_VXTR(c);}
PUBLIC(Vwwi,vxtrdwi)(Vdwi c) {return VDWI_VXTR(c);}
PUBLIC(Vwwf,vxtrdwf)(Vdwf c) {return VDWF_VXTR(c);}

PUBLIC(Vdyu,vxtrqyu)(Vqyu c) {return VQYU_VXTR(c);}
PUBLIC(Vdbu,vxtrqbu)(Vqbu c) {return VQBU_VXTR(c);}
PUBLIC(Vdbi,vxtrqbi)(Vqbi c) {return VQBI_VXTR(c);}
PUBLIC(Vdbc,vxtrqbc)(Vqbc c) {return VQBC_VXTR(c);}
PUBLIC(Vdhu,vxtrqhu)(Vqhu c) {return VQHU_VXTR(c);}
PUBLIC(Vdhi,vxtrqhi)(Vqhi c) {return VQHI_VXTR(c);}
PUBLIC(Vdhf,vxtrqhf)(Vqhf c) {return VQHF_VXTR(c);}
PUBLIC(Vdwu,vxtrqwu)(Vqwu c) {return VQWU_VXTR(c);}
PUBLIC(Vdwi,vxtrqwi)(Vqwi c) {return VQWI_VXTR(c);}
PUBLIC(Vdwf,vxtrqwf)(Vqwf c) {return VQWF_VXTR(c);}
PUBLIC(Vddu,vxtrqdu)(Vqdu c) {return VQDU_VXTR(c);}
PUBLIC(Vddi,vxtrqdi)(Vqdi c) {return VQDI_VXTR(c);}
PUBLIC(Vddf,vxtrqdf)(Vqdf c) {return VQDF_VXTR(c);}
#define     vxtr_funcof(X)  \
FUNCOF(                     \
    vxtr,                   \
    (X),                    \
    HDZ,    /* TGK */       \
    NONE,   /* TGW */       \
    YWR,    /* TGD */       \
    YDR,    /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGO */       \
    default: NULL           \
)
#define     vxtr(X)  (vxtr_funcof(X)(X))


#if _LEAVE_VXTR
}
#endif



#if DWRD_NLONG == 2
PUBLIC(ulong, ldr1alu)(ulong volatile const a[1]);
PUBLIC( long, ldr1ali)( long volatile const a[1]);
#else
PUBLIC(ullong, ldr1alu)(ullong volatile const a[1]);
PUBLIC( llong, ldr1ali)( llong volatile const a[1]);
#endif


PUBLIC(Vwbu, ldrwabu)( uint8_t const a[4]);
PUBLIC(Vwbi, ldrwabi)(  int8_t const a[4]);
PUBLIC(Vwbc, ldrwabc)(    char const a[4]);
PUBLIC(Vwhu, ldrwahu)(uint16_t const a[2]);
PUBLIC(Vwhi, ldrwahi)( int16_t const a[2]);
PUBLIC(Vwhf, ldrwahf)( flt16_t const a[2]);
PUBLIC(Vwwu, ldrwawu)(uint32_t const a[1]);
PUBLIC(Vwwi, ldrwawi)( int32_t const a[1]);
PUBLIC(Vwwf, ldrwawf)(   float const a[1]);

PUBLIC(Vdbc, ldrdabc)(    char const a[8]);
PUBLIC(Vdbu, ldrdabu)( uint8_t const a[8]);
PUBLIC(Vdbi, ldrdabi)(  int8_t const a[8]);
PUBLIC(Vdhu, ldrdahu)(uint16_t const a[4]);
PUBLIC(Vdhi, ldrdahi)( int16_t const a[4]);
PUBLIC(Vdhf, ldrdahf)( flt16_t const a[4]);
PUBLIC(Vdwu, ldrdawu)(uint32_t const a[2]);
PUBLIC(Vdwi, ldrdawi)( int32_t const a[2]);
PUBLIC(Vdwf, ldrdawf)(   float const a[2]);
PUBLIC(Vddu, ldrdadu)(uint64_t const a[1]);
PUBLIC(Vddi, ldrdadi)( int64_t const a[1]);
PUBLIC(Vddf, ldrdadf)(  double const a[1]);

PUBLIC(Vqbc, ldrqabc)(    char const a[16]);
PUBLIC(Vqbu, ldrqabu)( uint8_t const a[16]);
PUBLIC(Vqbi, ldrqabi)(  int8_t const a[16]);
PUBLIC(Vqhu, ldrqahu)(uint16_t const a[8]);
PUBLIC(Vqhi, ldrqahi)( int16_t const a[8]);
PUBLIC(Vqhf, ldrqahf)( flt16_t const a[8]);
PUBLIC(Vqwu, ldrqawu)(uint32_t const a[4]);
PUBLIC(Vqwi, ldrqawi)( int32_t const a[4]);
PUBLIC(Vqwf, ldrqawf)(   float const a[4]);
PUBLIC(Vqdu, ldrqadu)(uint64_t const a[2]);
PUBLIC(Vqdi, ldrqadi)( int64_t const a[2]);
PUBLIC(Vqdf, ldrqadf)(  double const a[2]);

#if DWRD_NLONG == 2

PUBLIC(Vwwu, ldrwalu)(ulong const a[1]);
PUBLIC(Vwwi, ldrwali)( long const a[1]);

PUBLIC(Vdwu, ldrdalu)(ulong const a[2]);
PUBLIC(Vdwi, ldrdali)( long const a[2]);

PUBLIC(Vqwu, ldrqalu)(ulong const a[4]);
PUBLIC(Vqwi, ldrqali)( long const a[4]);

#else

PUBLIC(Vddu, ldrdalu)(ullong const a[1]);
PUBLIC(Vddi, ldrdali)( llong const a[1]);

PUBLIC(Vqdu, ldrqalu)(ullong const a[2]);
PUBLIC(Vqdi, ldrqali)( llong const a[2]);

#endif

#if _LEAVE_DECL
}
#endif

#if _ENTER_REVS
{
#endif

PUBLIC(Vwyu, revswyu)(Vwyu a);
PUBLIC(Vwbu, revswbu)(Vwbu a);
PUBLIC(Vwbi, revswbi)(Vwbi a);
PUBLIC(Vwbc, revswbc)(Vwbc a);
PUBLIC(Vwhu, revswhu)(Vwhu a);
PUBLIC(Vwhi, revswhi)(Vwhi a);
PUBLIC(Vwhf, revswhf)(Vwhf a);

PUBLIC(Vdyu, revsdyu)(Vdyu a); // a.Y[63..0]
PUBLIC(Vdbu, revsdbu)(Vdbu a);
PUBLIC(Vdbi, revsdbi)(Vdbi a); // a.B[7..0]
PUBLIC(Vdbc, revsdbc)(Vdbc a); // a.B[7..0]
PUBLIC(Vdhu, revsdhu)(Vdhu a);
PUBLIC(Vdhi, revsdhi)(Vdhi a);
PUBLIC(Vdhf, revsdhf)(Vdhf a); // a.H[3..0]
PUBLIC(Vdwu, revsdwu)(Vdwu a);
PUBLIC(Vdwi, revsdwi)(Vdwi a);
PUBLIC(Vdwf, revsdwf)(Vdwf a); // a.W[1..0]


PUBLIC(Vqyu, revsqyu)(Vqyu a); // a.Y[127..0]
PUBLIC(Vqbu, revsqbu)(Vqbu a); // a.B[15..0]
PUBLIC(Vqbi, revsqbi)(Vqbi a);
PUBLIC(Vqbc, revsqbc)(Vqbc a);
PUBLIC(Vqhu, revsqhu)(Vqhu a); // a.H[7..0]
PUBLIC(Vqhi, revsqhi)(Vqhi a);
PUBLIC(Vqhf, revsqhf)(Vqhf a);
PUBLIC(Vqwu, revsqwu)(Vqwu a); // a.W[3..0]
PUBLIC(Vqwi, revsqwi)(Vqwi a);
PUBLIC(Vqwf, revsqwf)(Vqwf a);
PUBLIC(Vqdu, revsqdu)(Vqdu a); // a.D[1..0]
PUBLIC(Vqdi, revsqdi)(Vqdi a);
PUBLIC(Vqdf, revsqdf)(Vqdf a);

#define     revs_funcof(S)  \
FUNCOF(                     \
    revs,   (   S   ),      \
    NONE,   /* TGK */       \
    YHR,    /* TGW */       \
    YWR,    /* TGD */       \
    YDR,    /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGO */       \
    default: NULL           \
)
#define     revs(S)     (revs_funcof(S)(S))

PUBLIC(Vwyu,revswyu)(Vwyu v) {return  VWYU_REVS(v);}
PUBLIC(Vwbu,revswbu)(Vwbu v) {return  VWBU_REVS(v);}
PUBLIC(Vwbi,revswbi)(Vwbi v) {return  VWBI_REVS(v);}
PUBLIC(Vwbc,revswbc)(Vwbc v) {return  VWBC_REVS(v);}
PUBLIC(Vwhu,revswhu)(Vwhu v) {return  VWHU_REVS(v);}
PUBLIC(Vwhi,revswhi)(Vwhi v) {return  VWHI_REVS(v);}
PUBLIC(Vwhf,revswhf)(Vwhf v) {return  VWHF_REVS(v);}

PUBLIC(Vdyu,revsdyu)(Vdyu s) {return VDYU_REVS(s);}
PUBLIC(Vdbu,revsdbu)(Vdbu s) {return VDBU_REVS(s);}
PUBLIC(Vdbi,revsdbi)(Vdbi s) {return VDBI_REVS(s);}
PUBLIC(Vdbc,revsdbc)(Vdbc s) {return VDBC_REVS(s);}
PUBLIC(Vdhu,revsdhu)(Vdhu s) {return VDHU_REVS(s);}
PUBLIC(Vdhi,revsdhi)(Vdhi s) {return VDHI_REVS(s);}
PUBLIC(Vdhf,revsdhf)(Vdhf s) {return VDHF_REVS(s);}
PUBLIC(Vdwu,revsdwu)(Vdwu s) {return VDWU_REVS(s);}
PUBLIC(Vdwi,revsdwi)(Vdwi s) {return VDWI_REVS(s);}
PUBLIC(Vdwf,revsdwf)(Vdwf s) {return VDWF_REVS(s);}

PUBLIC(Vqyu,revsqyu)(Vqyu s) {return VQYU_REVS(s);}
PUBLIC(Vqbu,revsqbu)(Vqbu s) {return VQBU_REVS(s);}
PUBLIC(Vqbi,revsqbi)(Vqbi s) {return VQBI_REVS(s);}
PUBLIC(Vqbc,revsqbc)(Vqbc s) {return VQBC_REVS(s);}
PUBLIC(Vqhu,revsqhu)(Vqhu s) {return VQHU_REVS(s);}
PUBLIC(Vqhi,revsqhi)(Vqhi s) {return VQHI_REVS(s);}
PUBLIC(Vqhf,revsqhf)(Vqhf s) {return VQHF_REVS(s);}
PUBLIC(Vqwu,revsqwu)(Vqwu s) {return VQWU_REVS(s);}
PUBLIC(Vqwi,revsqwi)(Vqwi s) {return VQWI_REVS(s);}
PUBLIC(Vqwf,revsqwf)(Vqwf s) {return VQWF_REVS(s);}
PUBLIC(Vqdu,revsqdu)(Vqdu s) {return VQDU_REVS(s);}
PUBLIC(Vqdi,revsqdi)(Vqdi s) {return VQDI_REVS(s);}
PUBLIC(Vqdf,revsqdf)(Vqdf s) {return VQDF_REVS(s);}


#define     revswyu(...)    VWYU_REVS(__VA_ARGS__)
#define     revswbu(...)    VWBU_REVS(__VA_ARGS__)
#define     revswbi(...)    VWBI_REVS(__VA_ARGS__)
#define     revswbc(...)    VWBI_REVS(__VA_ARGS__)
#define     revswhu(...)    VWHU_REVS(__VA_ARGS__)
#define     revswhi(...)    VWHI_REVS(__VA_ARGS__)
#define     revswhf(...)    VWHF_REVS(__VA_ARGS__)

#define     revsdyu(...)    VDYU_REVS(__VA_ARGS__)
#define     revsdbu(...)    VDBU_REVS(__VA_ARGS__)
#define     revsdbi(...)    VDBI_REVS(__VA_ARGS__)
#define     revsdbc(...)    VDBC_REVS(__VA_ARGS__)
#define     revsdhu(...)    VDHU_REVS(__VA_ARGS__)
#define     revsdhi(...)    VDHI_REVS(__VA_ARGS__)
#define     revsdhf(...)    VDHF_REVS(__VA_ARGS__)
#define     revsdwu(...)    VDWU_REVS(__VA_ARGS__)
#define     revsdwi(...)    VDWI_REVS(__VA_ARGS__)
#define     revsdwf(...)    VDWF_REVS(__VA_ARGS__)


#define     revsqyu(...)    VQYU_REVS(__VA_ARGS__)
#define     revsqbu(...)    VQBU_REVS(__VA_ARGS__)
#define     revsqbi(...)    VQBI_REVS(__VA_ARGS__)
#define     revsqbc(...)    VQBC_REVS(__VA_ARGS__)
#define     revsqhu(...)    VQHU_REVS(__VA_ARGS__)
#define     revsqhi(...)    VQHI_REVS(__VA_ARGS__)
#define     revsqhf(...)    VQHF_REVS(__VA_ARGS__)
#define     revsqwu(...)    VQWU_REVS(__VA_ARGS__)
#define     revsqwi(...)    VQWI_REVS(__VA_ARGS__)
#define     revsqwf(...)    VQWF_REVS(__VA_ARGS__)
#define     revsqdu(...)    VQDU_REVS(__VA_ARGS__)
#define     revsqdi(...)    VQDI_REVS(__VA_ARGS__)
#define     revsqdf(...)    VQDF_REVS(__VA_ARGS__)

#if _LEAVE_REVS
}
#endif

#if defined(_MSC_VER)
#   include "winsync.h"
#elif defined(__GNUC__)
#   include "gnusync.h"
#endif

#if _ENTER_LDR1
{
#endif

PUBLIC(   _Bool,ldr1yu) (   _Bool volatile const a[1]);
PUBLIC( uint8_t,ldr1bu) ( uint8_t volatile const a[1]);
PUBLIC(  int8_t,ldr1bi) (  int8_t volatile const a[1]);
PUBLIC(    char,ldr1bc) (    char volatile const a[1]);
PUBLIC(uint16_t,ldr1hu) (uint16_t volatile const a[1]);
PUBLIC( int16_t,ldr1hi) ( int16_t volatile const a[1]);
PUBLIC(uint32_t,ldr1wu) (uint32_t volatile const a[1]);
PUBLIC( int32_t,ldr1wi) ( int32_t volatile const a[1]);
PUBLIC(uint64_t,ldr1du) (uint64_t volatile const a[1]);
PUBLIC( int64_t,ldr1di) ( int64_t volatile const a[1]);
#if DWRD_NLONG == 2
PUBLIC(uint32_t,ldr1lu) (   ulong volatile const a[1]);
PUBLIC( int32_t,ldr1l1) (    long volatile const a[1]);
#elif QUAD_NLLONG == 2
PUBLIC(uint64_t,ldr1lu) (  ullong volatile const a[1]);
PUBLIC( int32_t,ldr1l1) (   llong volatile const a[1]);
#endif
PUBLIC(  void *,ldr1ap) (void const * volatile const a[1]);

#define      UINT8_LDR1  UINT8_BASE(LDR1)
#define       INT8_LDR1   INT8_BASE(LDR1)
#define     UINT16_LDR1 UINT16_BASE(LDR1)
#define      INT16_LDR1  INT16_BASE(LDR1)
#define     UINT32_LDR1 UINT32_BASE(LDR1)
#define      INT32_LDR1  INT32_BASE(LDR1)
#define     UINT64_LDR1 UINT64_BASE(LDR1)
#define      INT64_LDR1  INT64_BASE(LDR1)


#define ldr1_funcof(T)      \
FUNCOF(                     \
    ldr1,   ((T){0}),       \
    YDZ,    /* TGK */       \
    NONE,   /* TGW */       \
    NONE,   /* TGD */       \
    NONE,   /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGS */       \
    default: ldr1ap         \
)

#define ldr1(T, A) (ldr1_funcof( T )((void volatile *)(A)))


PUBLIC(   _Bool,ldr1yu) (   _Bool volatile const a[1]) {return   BOOL_LDR1(a);}
PUBLIC( uint8_t,ldr1bu) ( uint8_t volatile const a[1]) {return  UINT8_LDR1(a);}
PUBLIC(  int8_t,ldr1bi) (  int8_t volatile const a[1]) {return   INT8_LDR1(a);}
PUBLIC(    char,ldr1bc) (    char volatile const a[1]) {return   CHAR_LDR1(a);}
PUBLIC(uint16_t,ldr1hu) (uint16_t volatile const a[1]) {return UINT16_LDR1(a);}
PUBLIC( int16_t,ldr1hi) ( int16_t volatile const a[1]) {return  INT16_LDR1(a);}
//              ldr1hf
PUBLIC(uint32_t,ldr1wu) (uint32_t volatile const a[1]) {return UINT32_LDR1(a);}
PUBLIC( int32_t,ldr1wi) ( int32_t volatile const a[1]) {return  INT32_LDR1(a);}
//              ldr1wf
PUBLIC(uint64_t,ldr1du) (uint64_t volatile const a[1]) {return UINT64_LDR1(a);}
PUBLIC( int64_t,ldr1di) ( int64_t volatile const a[1]) {return  INT64_LDR1(a);}
//              ldr1df
#if DWRD_NLONG == 2
PUBLIC(uint32_t,ldr1lu) (   ulong volatile const a[1]) {return  ULONG_LDR1(a);}
PUBLIC( int32_t,ldr1l1) (    long volatile const a[1]) {return   LONG_LDR1(a);}
#elif QUAD_NLLONG == 2
PUBLIC(uint64_t,ldr1lu) (  ullong volatile const a[1]) {return ULLONG_LDR1(a);}
PUBLIC( int32_t,ldr1l1) (   llong volatile const a[1]) {return  LLONG_LDR1(a);}
#endif

PUBLIC(  void *,ldr1ap) (void const * volatile const a[1])
{
    return ADDR_LDR1(a);
}

#define     ldr1bu   UINT8_LDR1
#define     ldr1bi    INT8_LDR1
#define     ldr1bc    CHAR_LDR1
#define     ldr1hu  UINT16_LDR1
#define     ldr1hi   INT16_LDR1
#define     ldr1wu  UINT32_LDR1
#define     ldr1wi   INT32_LDR1
#define     ldr1du  UINT32_LDR1
#define     ldr1di   INT32_LDR1
#if DWRD_NLONG == 2
#   define  ldr1lu   ULONG_LDR1
#   define  ldr1li    LONG_LDR1
#else
#   define  ldr1lu  ULLONG_LDR1
#   define  ldr1li   LLONG_LDR1
#endif

#if _LEAVE_LDR1
}
#endif


#if _ENTER_LDRA
{
#endif

PUBLIC(   _Bool,ldrayu) (   _Bool volatile const a[1]);
PUBLIC( uint8_t,ldrabu) ( uint8_t volatile const a[1]);
PUBLIC(  int8_t,ldrabi) (  int8_t volatile const a[1]);
PUBLIC(    char,ldrabc) (    char volatile const a[1]);
PUBLIC(uint16_t,ldrahu) (uint16_t volatile const a[1]);
PUBLIC( int16_t,ldrahi) ( int16_t volatile const a[1]);
PUBLIC(uint32_t,ldrawu) (uint32_t volatile const a[1]);
PUBLIC( int32_t,ldrawi) ( int32_t volatile const a[1]);
PUBLIC(uint64_t,ldradu) (uint64_t volatile const a[1]);
PUBLIC( int64_t,ldradi) ( int64_t volatile const a[1]);
#if DWRD_NLONG == 2
PUBLIC(uint32_t,ldralu) (   ulong volatile const a[1]);
PUBLIC( int32_t,ldral1) (    long volatile const a[1]);
#elif QUAD_NLLONG == 2
PUBLIC(uint64_t,ldralu) (  ullong volatile const a[1]);
PUBLIC( int32_t,ldral1) (   llong volatile const a[1]);
#endif
PUBLIC(  void *,ldraap) (void const * volatile const a[1]);

#define      UINT8_LDRA  UINT8_BASE(LDRA)
#define       INT8_LDRA   INT8_BASE(LDRA)
#define     UINT16_LDRA UINT16_BASE(LDRA)
#define      INT16_LDRA  INT16_BASE(LDRA)
#define     UINT32_LDRA UINT32_BASE(LDRA)
#define      INT32_LDRA  INT32_BASE(LDRA)
#define     UINT64_LDRA UINT64_BASE(LDRA)
#define      INT64_LDRA  INT64_BASE(LDRA)


#define ldra_funcof(T)      \
FUNCOF(                     \
    ldra,   ((T){0}),       \
    YDZ,    /* TGK */       \
    NONE,   /* TGW */       \
    NONE,   /* TGD */       \
    NONE,   /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGS */       \
    default: ldraap         \
)

#define ldra(T, A) (ldra_funcof( T )((void volatile *)(A)))


PUBLIC(   _Bool,ldrayu) (   _Bool volatile const a[1]) {return   BOOL_LDRA(a);}
PUBLIC( uint8_t,ldrabu) ( uint8_t volatile const a[1]) {return  UINT8_LDRA(a);}
PUBLIC(  int8_t,ldrabi) (  int8_t volatile const a[1]) {return   INT8_LDRA(a);}
PUBLIC(    char,ldrabc) (    char volatile const a[1]) {return   CHAR_LDRA(a);}
PUBLIC(uint16_t,ldrahu) (uint16_t volatile const a[1]) {return UINT16_LDRA(a);}
PUBLIC( int16_t,ldrahi) ( int16_t volatile const a[1]) {return  INT16_LDRA(a);}
//              ldrahf
PUBLIC(uint32_t,ldrawu) (uint32_t volatile const a[1]) {return UINT32_LDRA(a);}
PUBLIC( int32_t,ldrawi) ( int32_t volatile const a[1]) {return  INT32_LDRA(a);}
//              ldrawf
PUBLIC(uint64_t,ldradu) (uint64_t volatile const a[1]) {return UINT64_LDRA(a);}
PUBLIC( int64_t,ldradi) ( int64_t volatile const a[1]) {return  INT64_LDRA(a);}
//              ldradf
#if DWRD_NLONG == 2
PUBLIC(uint32_t,ldralu) (   ulong volatile const a[1]) {return  ULONG_LDRA(a);}
PUBLIC( int32_t,ldral1) (    long volatile const a[1]) {return   LONG_LDRA(a);}
#elif QUAD_NLLONG == 2
PUBLIC(uint64_t,ldralu) (  ullong volatile const a[1]) {return ULLONG_LDRA(a);}
PUBLIC( int32_t,ldral1) (   llong volatile const a[1]) {return  LLONG_LDRA(a);}
#endif

PUBLIC(  void *,ldraap) (void const * volatile const a[1])
{
    return ADDR_LDRA(a);
}

#define     ldrabu   UINT8_LDRA
#define     ldrabi    INT8_LDRA
#define     ldrabc    CHAR_LDRA
#define     ldrahu  UINT16_LDRA
#define     ldrahi   INT16_LDRA
#define     ldrawu  UINT32_LDRA
#define     ldrawi   INT32_LDRA
#define     ldradu  UINT32_LDRA
#define     ldradi   INT32_LDRA
#if DWRD_NLONG == 2
#   define  ldralu   ULONG_LDRA
#   define  ldrali    LONG_LDRA
#else
#   define  ldralu  ULLONG_LDRA
#   define  ldrali   LLONG_LDRA
#endif

#if _LEAVE_LDRA
}
#endif


#if _ENTER_LDRT
{
#endif

PUBLIC(   _Bool,ldrtyu) (   _Bool volatile const a[1]);
PUBLIC( uint8_t,ldrtbu) ( uint8_t volatile const a[1]);
PUBLIC(  int8_t,ldrtbi) (  int8_t volatile const a[1]);
PUBLIC(    char,ldrtbc) (    char volatile const a[1]);
PUBLIC(uint16_t,ldrthu) (uint16_t volatile const a[1]);
PUBLIC( int16_t,ldrthi) ( int16_t volatile const a[1]);
PUBLIC(uint32_t,ldrtwu) (uint32_t volatile const a[1]);
PUBLIC( int32_t,ldrtwi) ( int32_t volatile const a[1]);
PUBLIC(uint64_t,ldrtdu) (uint64_t volatile const a[1]);
PUBLIC( int64_t,ldrtdi) ( int64_t volatile const a[1]);
#if DWRD_NLONG == 2
PUBLIC(uint32_t,ldrtlu) (   ulong volatile const a[1]);
PUBLIC( int32_t,ldrtl1) (    long volatile const a[1]);
#elif QUAD_NLLONG == 2
PUBLIC(uint64_t,ldrtlu) (  ullong volatile const a[1]);
PUBLIC( int32_t,ldrtl1) (   llong volatile const a[1]);
#endif
PUBLIC(  void *,ldrtap) (void const * volatile const a[1]);

#define      UINT8_LDRT  UINT8_BASE(LDRT)
#define       INT8_LDRT   INT8_BASE(LDRT)
#define     UINT16_LDRT UINT16_BASE(LDRT)
#define      INT16_LDRT  INT16_BASE(LDRT)
#define     UINT32_LDRT UINT32_BASE(LDRT)
#define      INT32_LDRT  INT32_BASE(LDRT)
#define     UINT64_LDRT UINT64_BASE(LDRT)
#define      INT64_LDRT  INT64_BASE(LDRT)


#define ldrt_funcof(T)      \
FUNCOF(                     \
    ldrt,   ((T){0}),       \
    YDZ,    /* TGK */       \
    NONE,   /* TGW */       \
    NONE,   /* TGD */       \
    NONE,   /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGS */       \
    default: ldrtap         \
)

#define ldrt(T, A) (ldrt_funcof( T )((void volatile *)(A)))


PUBLIC(   _Bool,ldrtyu) (   _Bool volatile const a[1]) {return   BOOL_LDRT(a);}
PUBLIC( uint8_t,ldrtbu) ( uint8_t volatile const a[1]) {return  UINT8_LDRT(a);}
PUBLIC(  int8_t,ldrtbi) (  int8_t volatile const a[1]) {return   INT8_LDRT(a);}
PUBLIC(    char,ldrtbc) (    char volatile const a[1]) {return   CHAR_LDRT(a);}
PUBLIC(uint16_t,ldrthu) (uint16_t volatile const a[1]) {return UINT16_LDRT(a);}
PUBLIC( int16_t,ldrthi) ( int16_t volatile const a[1]) {return  INT16_LDRT(a);}
//              ldrthf
PUBLIC(uint32_t,ldrtwu) (uint32_t volatile const a[1]) {return UINT32_LDRT(a);}
PUBLIC( int32_t,ldrtwi) ( int32_t volatile const a[1]) {return  INT32_LDRT(a);}
//              ldrtwf
PUBLIC(uint64_t,ldrtdu) (uint64_t volatile const a[1]) {return UINT64_LDRT(a);}
PUBLIC( int64_t,ldrtdi) ( int64_t volatile const a[1]) {return  INT64_LDRT(a);}
//              ldrtdf
#if DWRD_NLONG == 2
PUBLIC(uint32_t,ldrtlu) (   ulong volatile const a[1]) {return  ULONG_LDRT(a);}
PUBLIC( int32_t,ldrtl1) (    long volatile const a[1]) {return   LONG_LDRT(a);}
#elif QUAD_NLLONG == 2
PUBLIC(uint64_t,ldrtlu) (  ullong volatile const a[1]) {return ULLONG_LDRT(a);}
PUBLIC( int32_t,ldrtl1) (   llong volatile const a[1]) {return  LLONG_LDRT(a);}
#endif

PUBLIC(  void *,ldrtap) (void const * volatile const a[1])
{
    return ADDR_LDRT(a);
}

#define     ldrtbu   UINT8_LDRT
#define     ldrtbi    INT8_LDRT
#define     ldrtbc    CHAR_LDRT
#define     ldrthu  UINT16_LDRT
#define     ldrthi   INT16_LDRT
#define     ldrtwu  UINT32_LDRT
#define     ldrtwi   INT32_LDRT
#define     ldrtdu  UINT32_LDRT
#define     ldrtdi   INT32_LDRT
#if DWRD_NLONG == 2
#   define  ldrtlu   ULONG_LDRT
#   define  ldrtli    LONG_LDRT
#else
#   define  ldrtlu  ULLONG_LDRT
#   define  ldrtli   LLONG_LDRT
#endif

#if _LEAVE_LDRT
}
#endif

#if _ENTER_LDRW
{
#endif

PUBLIC(Vwyu,ldrwyu) (   _Bool volatile const a[8]);
PUBLIC(Vwbu,ldrwbu) ( uint8_t volatile const a[8]);
PUBLIC(Vwbi,ldrwbi) (  int8_t volatile const a[8]);
PUBLIC(Vwbc,ldrwbc) (    char volatile const a[8]);
PUBLIC(Vwhu,ldrwhu) (uint16_t volatile const a[4]);
PUBLIC(Vwhi,ldrwhi) ( int16_t volatile const a[4]);
PUBLIC(Vwhf,ldrwhf) ( flt16_t volatile const a[4]);
PUBLIC(Vwwu,ldrwwu) (uint32_t volatile const a[2]);
PUBLIC(Vwwi,ldrwwi) ( int32_t volatile const a[2]);
PUBLIC(Vwwf,ldrwwf) (   float volatile const a[2]);

#if DWRD_NLONG == 2
PUBLIC(Vwwu,ldrwlu) (   ulong volatile const a[4]);
PUBLIC(Vwwi,ldrwl1) (    long volatile const a[4]);
#endif

#define      UINT8_LDRW  UINT8_BASE(LDRW)
#define       INT8_LDRW   INT8_BASE(LDRW)
#define     UINT16_LDRW UINT16_BASE(LDRW)
#define      INT16_LDRW  INT16_BASE(LDRW)
#define     UINT32_LDRW UINT32_BASE(LDRW)
#define      INT32_LDRW  INT32_BASE(LDRW)

#define ldrw_funcof(T)      \
FUNCOF(                     \
    ldrw,   ((T){0}),       \
    YWZ,    /* TGK */       \
    NONE,   /* TGW */       \
    NONE,   /* TGD */       \
    NONE,   /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGS */       \
    default: ldrwap         \
)

#define ldrw(T, A) (ldrw_funcof( T )((void volatile *)(A)))


PUBLIC(Vwyu,ldrwyu) (   _Bool volatile const a[8]) {return   BOOL_LDRW(a);}
PUBLIC(Vwbu,ldrwbu) ( uint8_t volatile const a[8]) {return  UINT8_LDRW(a);}
PUBLIC(Vwbi,ldrwbi) (  int8_t volatile const a[8]) {return   INT8_LDRW(a);}
PUBLIC(Vwbc,ldrwbc) (    char volatile const a[8]) {return   CHAR_LDRW(a);}
PUBLIC(Vwhu,ldrwhu) (uint16_t volatile const a[4]) {return UINT16_LDRW(a);}
PUBLIC(Vwhi,ldrwhi) ( int16_t volatile const a[4]) {return  INT16_LDRW(a);}
PUBLIC(Vwhf,ldrwhf) ( flt16_t volatile const a[4]) {return  FLT16_LDRW(a);}
PUBLIC(Vwwu,ldrwwu) (uint32_t volatile const a[2]) {return UINT32_LDRW(a);}
PUBLIC(Vwwi,ldrwwi) ( int32_t volatile const a[2]) {return  INT32_LDRW(a);}
PUBLIC(Vwwf,ldrwwf) (   float volatile const a[2]) {return    FLT_LDRW(a);}

#if DWRD_NLONG == 2
PUBLIC(Vwwu,ldrwlu) (   ulong volatile const a[4]) {return  ULONG_LDRW(a);}
PUBLIC(Vwwi,ldrwl1) (    long volatile const a[4]) {return   LONG_LDRW(a);}
#endif

#define     ldrwyu    BOOL_LDRW
#define     ldrwbu   UINT8_LDRW
#define     ldrwbi    INT8_LDRW
#define     ldrwbc    CHAR_LDRW
#define     ldrwhu  UINT16_LDRW
#define     ldrwhi   INT16_LDRW
#define     ldrwhf   FLT16_LDRW
#define     ldrwwu  UINT32_LDRW
#define     ldrwwi   INT32_LDRW
#define     ldrwwf     FLT_LDRW
#if DWRD_NLONG == 2
#   define  ldrwlu   ULONG_LDRW
#   define  ldrwli    LONG_LDRW
#endif

#if _LEAVE_LDRW
}
#endif

#if _ENTER_LDRD
{
#endif

PUBLIC(Vdyu,ldrdyu) (   _Bool volatile const a[8]);

PUBLIC(Vdbu,ldrdbu) ( uint8_t volatile const a[8]);
PUBLIC(Vdbi,ldrdbi) (  int8_t volatile const a[8]);
PUBLIC(Vdbc,ldrdbc) (    char volatile const a[8]);
PUBLIC(Vdhu,ldrdhu) (uint16_t volatile const a[4]);
PUBLIC(Vdhi,ldrdhi) ( int16_t volatile const a[4]);
PUBLIC(Vdhf,ldrdhf) ( flt16_t volatile const a[4]);
PUBLIC(Vdwu,ldrdwu) (uint32_t volatile const a[2]);
PUBLIC(Vdwi,ldrdwi) ( int32_t volatile const a[2]);
PUBLIC(Vdwf,ldrdwf) (   float volatile const a[2]);
PUBLIC(Vddu,ldrddu) (uint64_t volatile const a[1]);
PUBLIC(Vddi,ldrddi) ( int64_t volatile const a[1]);
PUBLIC(Vddf,ldrddf) (  double volatile const a[1]);

#if DWRD_NLONG == 2
PUBLIC(Vdwu,ldrdlu) (   ulong volatile const a[4]);
PUBLIC(Vdwi,ldrdl1) (    long volatile const a[4]);
#elif QUAD_NLLONG == 2
PUBLIC(Vddu,ldrdlu) (  ullong volatile const a[2]);
PUBLIC(Vddi,ldrdl1) (   llong volatile const a[2]);
#endif

#define      UINT8_LDRD  UINT8_BASE(LDRD)
#define       INT8_LDRD   INT8_BASE(LDRD)
#define     UINT16_LDRD UINT16_BASE(LDRD)
#define      INT16_LDRD  INT16_BASE(LDRD)
#define     UINT32_LDRD UINT32_BASE(LDRD)
#define      INT32_LDRD  INT32_BASE(LDRD)
#define     UINT64_LDRD UINT64_BASE(LDRD)
#define      INT64_LDRD  INT64_BASE(LDRD)


#define ldrd_funcof(T)      \
FUNCOF(                     \
    ldrd,   ((T){0}),       \
    YDZ,    /* TGK */       \
    NONE,   /* TGW */       \
    NONE,   /* TGD */       \
    NONE,   /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGS */       \
    default: ldrdap         \
)

#define ldrd(T, A) (ldrd_funcof( T )((void volatile *)(A)))


PUBLIC(Vdyu,ldrdyu) (   _Bool volatile const a[8]) {return   BOOL_LDRD(a);}
PUBLIC(Vdbu,ldrdbu) ( uint8_t volatile const a[8]) {return  UINT8_LDRD(a);}
PUBLIC(Vdbi,ldrdbi) (  int8_t volatile const a[8]) {return   INT8_LDRD(a);}
PUBLIC(Vdbc,ldrdbc) (    char volatile const a[8]) {return   CHAR_LDRD(a);}
PUBLIC(Vdhu,ldrdhu) (uint16_t volatile const a[4]) {return UINT16_LDRD(a);}
PUBLIC(Vdhi,ldrdhi) ( int16_t volatile const a[4]) {return  INT16_LDRD(a);}
PUBLIC(Vdhf,ldrdhf) ( flt16_t volatile const a[4]) {return  FLT16_LDRD(a);}
PUBLIC(Vdwu,ldrdwu) (uint32_t volatile const a[2]) {return UINT32_LDRD(a);}
PUBLIC(Vdwi,ldrdwi) ( int32_t volatile const a[2]) {return  INT32_LDRD(a);}
PUBLIC(Vdwf,ldrdwf) (   float volatile const a[2]) {return    FLT_LDRD(a);}
PUBLIC(Vddu,ldrddu) (uint64_t volatile const a[1]) {return UINT64_LDRD(a);}
PUBLIC(Vddi,ldrddi) ( int64_t volatile const a[1]) {return  INT64_LDRD(a);}
PUBLIC(Vddf,ldrddf) (  double volatile const a[1]) {return    DBL_LDRD(a);}

#if DWRD_NLONG == 2
PUBLIC(Vdwu,ldrdlu) (   ulong volatile const a[4]) {return  ULONG_LDRD(a);}
PUBLIC(Vdwi,ldrdl1) (    long volatile const a[4]) {return   LONG_LDRD(a);}
#elif QUAD_NLLONG == 2
PUBLIC(Vddu,ldrdlu) (  ullong volatile const a[2]) {return ULLONG_LDRD(a);}
PUBLIC(Vddi,ldrdl1) (   llong volatile const a[2]) {return  LLONG_LDRD(a);}
#endif

#define     ldrdyu    BOOL_LDRD
#define     ldrdbu   UINT8_LDRD
#define     ldrdbi    INT8_LDRD
#define     ldrdbc    CHAR_LDRD
#define     ldrdhu  UINT16_LDRD
#define     ldrdhi   INT16_LDRD
#define     ldrdhf   FLT16_LDRD
#define     ldrdwu  UINT32_LDRD
#define     ldrdwi   INT32_LDRD
#define     ldrdwf     FLT_LDRD
#define     ldrddu  UINT64_LDRD
#define     ldrddi   INT64_LDRD
#define     ldrddf     DBL_LDRD

#if DWRD_NLONG == 2
#   define  ldrdlu   ULONG_LDRD
#   define  ldrdli    LONG_LDRD
#else
#   define  ldrdlu  ULLONG_LDRD
#   define  ldrdli   LLONG_LDRD
#endif

#if _LEAVE_LDRD
}
#endif

#if _ENTER_LDRQ
{
#endif

PUBLIC(Vqyu,ldrqyu) (   _Bool volatile const a[16]);
PUBLIC(Vqbu,ldrqbu) ( uint8_t volatile const a[16]);
PUBLIC(Vqbi,ldrqbi) (  int8_t volatile const a[16]);
PUBLIC(Vqbc,ldrqbc) (    char volatile const a[16]);
PUBLIC(Vqhu,ldrqhu) (uint16_t volatile const a[8]);
PUBLIC(Vqhi,ldrqhi) ( int16_t volatile const a[8]);
PUBLIC(Vqhf,ldrqhf) ( flt16_t volatile const a[8]);
PUBLIC(Vqwu,ldrqwu) (uint32_t volatile const a[4]);
PUBLIC(Vqwi,ldrqwi) ( int32_t volatile const a[4]);
PUBLIC(Vqwf,ldrqwf) (   float volatile const a[4]);
PUBLIC(Vqdu,ldrqdu) (uint64_t volatile const a[2]);
PUBLIC(Vqdi,ldrqdi) ( int64_t volatile const a[2]);
PUBLIC(Vqdf,ldrqdf) (  double volatile const a[2]);

#if DWRD_NLONG == 2
PUBLIC(Vqwu,ldrqlu) (   ulong volatile const a[4]);
PUBLIC(Vqwi,ldrql1) (    long volatile const a[4]);
#elif QUAD_NLLONG == 2
PUBLIC(Vqdu,ldrqlu) (  ullong volatile const a[2]);
PUBLIC(Vqdi,ldrql1) (   llong volatile const a[2]);
#endif

#define      UINT8_LDRQ  UINT8_BASE(LDRQ)
#define       INT8_LDRQ   INT8_BASE(LDRQ)
#define     UINT16_LDRQ UINT16_BASE(LDRQ)
#define      INT16_LDRQ  INT16_BASE(LDRQ)
#define     UINT32_LDRQ UINT32_BASE(LDRQ)
#define      INT32_LDRQ  INT32_BASE(LDRQ)
#define     UINT64_LDRQ UINT64_BASE(LDRQ)
#define      INT64_LDRQ  INT64_BASE(LDRQ)


#define ldrq_funcof(T)      \
FUNCOF(                     \
    ldrq,   ((T){0}),       \
    YDZ,    /* TGK */       \
    NONE,   /* TGW */       \
    NONE,   /* TGD */       \
    NONE,   /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGS */       \
    default: ldrqap         \
)

#define ldrq(T, A) (ldrq_funcof( T )((void volatile *)(A)))


PUBLIC(Vqyu,ldrqyu) (   _Bool volatile const a[16]) {return  BOOL_LDRQ(a);}

PUBLIC(Vqbu,ldrqbu) ( uint8_t volatile const a[16]) {return UINT8_LDRQ(a);}
PUBLIC(Vqbi,ldrqbi) (  int8_t volatile const a[16]) {return  INT8_LDRQ(a);}
PUBLIC(Vqbc,ldrqbc) (    char volatile const a[16]) {return  CHAR_LDRQ(a);}
PUBLIC(Vqhu,ldrqhu) (uint16_t volatile const a[8]) {return UINT16_LDRQ(a);}
PUBLIC(Vqhi,ldrqhi) ( int16_t volatile const a[8]) {return  INT16_LDRQ(a);}
PUBLIC(Vqhf,ldrqhf) ( flt16_t volatile const a[8]) {return  FLT16_LDRQ(a);}
PUBLIC(Vqwu,ldrqwu) (uint32_t volatile const a[4]) {return UINT32_LDRQ(a);}
PUBLIC(Vqwi,ldrqwi) ( int32_t volatile const a[4]) {return  INT32_LDRQ(a);}
PUBLIC(Vqwf,ldrqwf) (   float volatile const a[4]) {return    FLT_LDRQ(a);}
PUBLIC(Vqdu,ldrqdu) (uint64_t volatile const a[2]) {return UINT64_LDRQ(a);}
PUBLIC(Vqdi,ldrqdi) ( int64_t volatile const a[2]) {return  INT64_LDRQ(a);}
PUBLIC(Vqdf,ldrqdf) (  double volatile const a[2]) {return    DBL_LDRQ(a);}

#if DWRD_NLONG == 2
PUBLIC(Vqwu,ldrqlu) (   ulong volatile const a[4]) {return  ULONG_LDRQ(a);}
PUBLIC(Vqwi,ldrql1) (    long volatile const a[4]) {return   LONG_LDRQ(a);}
#elif QUAD_NLLONG == 2
PUBLIC(Vqdu,ldrqlu) (  ullong volatile const a[2]) {return ULLONG_LDRQ(a);}
PUBLIC(Vqdi,ldrql1) (   llong volatile const a[2]) {return  LLONG_LDRQ(a);}
#endif


#define     ldrqbu   UINT8_LDRQ
#define     ldrqbi    INT8_LDRQ
#define     ldrqbc    CHAR_LDRQ

#define     ldrqhu  UINT16_LDRQ
#define     ldrqhi   INT16_LDRQ
#define     ldrqhf   FLT16_LDRQ

#define     ldrqwu  UINT32_LDRQ
#define     ldrqwi   INT32_LDRQ
#define     ldrqwf     FLT_LDRQ

#define     ldrqdu  UINT64_LDRQ
#define     ldrqdi   INT64_LDRQ
#define     ldrqdf     DBL_LDRQ

#if DWRD_NLONG == 2
#   define  ldrqlu   ULONG_LDRQ
#   define  ldrqli    LONG_LDRQ
#else
#   define  ldrqlu  ULLONG_LDRQ
#   define  ldrqli   LLONG_LDRQ
#endif

#if _LEAVE_LDRQ
}
#endif

#if _ENTER_STRD
{
#endif

#if _LEAVE_STRD
}
#endif

#define     str1_funcof(X)  \
FUNCOF(                     \
    dupw,   (   X   )       \
    YWR,    /* TGK */       \
    YWR,    /* TGW */       \
    YWR,    /* TGD */       \
    YWR,    /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGO */       \
    default: NULL           \
)


#if _ENTER_NEWL
{
#endif

PUBLIC(Vwbu,newlwbu)(uint8_t  k0, uint8_t  k1, uint8_t k2, uint8_t k3);
PUBLIC(Vwbi,newlwbi)( int8_t  k0,  int8_t  k1,  int8_t k2,  int8_t k3);
PUBLIC(Vwbc,newlwbc)(   char  k0,    char  k1,    char k2,    char k3);
PUBLIC(Vwhu,newlwhu)(uint16_t k0, uint16_t k1);
PUBLIC(Vwhi,newlwhi)( int16_t k0,  int16_t k1);
PUBLIC(Vwhf,newlwhf)( flt16_t k0,  flt16_t k1);

PUBLIC(Vdbu,newldbu)
(
    uint8_t k0, uint8_t k1, uint8_t k2, uint8_t k3,
    uint8_t k4, uint8_t k5, uint8_t k6, uint8_t k7
);

PUBLIC(Vdbi,newldbi)
(
    int8_t  k0, int8_t  k1, int8_t  k2, int8_t  k3,
    int8_t  k4, int8_t  k5, int8_t  k6, int8_t  k7
);

PUBLIC(Vdbc,newldbc)
(
    char   k0, char   k1, char   k2, char   k3,
    char   k4, char   k5, char   k6, char   k7
);

PUBLIC(Vdhu,newldhu)(uint16_t k0, uint16_t k1, uint16_t k2, uint16_t k3);
PUBLIC(Vdhi,newldhi)( int16_t k0,  int16_t k1,  int16_t k2,  int16_t k3);
PUBLIC(Vdhf,newldhf)( flt16_t k0,  flt16_t k1,  flt16_t k2,  flt16_t k3);
PUBLIC(Vdwu,newldwu)(uint32_t k0, uint32_t k1);
PUBLIC(Vdwi,newldwi)( int32_t k0,  int32_t k1);
PUBLIC(Vdwf,newldwf)(   float k0,    float k1);


PUBLIC(Vqbu,newlqbu)
(
    uint8_t  k0, uint8_t  k1, uint8_t  k2, uint8_t  k3,
    uint8_t  k4, uint8_t  k5, uint8_t  k6, uint8_t  k7,
    uint8_t  k8, uint8_t  k9, uint8_t k10, uint8_t k11,
    uint8_t k12, uint8_t k13, uint8_t k14, uint8_t k15
);

PUBLIC(Vqbi,newlqbi)
(
    int8_t   k0, int8_t   k1, int8_t   k2, int8_t   k3,
    int8_t   k4, int8_t   k5, int8_t   k6, int8_t   k7,
    int8_t   k8, int8_t   k9, int8_t  k10, int8_t  k11,
    int8_t  k12, int8_t  k13, int8_t  k14, int8_t  k15
);

PUBLIC(Vqbc,newlqbc)
(
    char   k0, char   k1, char   k2, char   k3,
    char   k4, char   k5, char   k6, char   k7,
    char   k8, char   k9, char  k10, char  k11,
    char  k12, char  k13, char  k14, char  k15
);


PUBLIC(Vqhu,newlqhu)
(
    uint16_t  k0, uint16_t  k1, uint16_t  k2, uint16_t  k3,
    uint16_t  k4, uint16_t  k5, uint16_t  k6, uint16_t  k7
);

PUBLIC(Vqhi,newlqhi)
(
    int16_t  k0, int16_t  k1, int16_t  k2, int16_t  k3,
    int16_t  k4, int16_t  k5, int16_t  k6, int16_t  k7
);

PUBLIC(Vqhf,newlqhf)
(
    flt16_t  k0, flt16_t  k1, flt16_t  k2, flt16_t  k3,
    flt16_t  k4, flt16_t  k5, flt16_t  k6, flt16_t  k7
);

PUBLIC(Vqwu,newlqwu)(uint32_t k0, uint32_t k1, uint32_t k2, uint32_t k3);
PUBLIC(Vqwi,newlqwi)( int32_t k0,  int32_t k1,  int32_t k2,  int32_t k3);
PUBLIC(Vqwf,newlqwf)(   float k0,    float k1,    float k2,    float k3);
PUBLIC(Vqdu,newlqdu)(uint64_t k0, uint64_t k1);
PUBLIC(Vqdi,newlqdi)( int64_t k0,  int64_t k1);
PUBLIC(Vqdf,newlqdf)(  double k0,   double k1);

#define     newl_funcof(T)  \
FUNCOF(                     \
    newl,   ((T){0}),       \
    NONE,   /* TGK */       \
    BHR,    /* TGW */       \
    BWR,    /* TGD */       \
    BDR,    /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGO */       \
    default: NULL           \
)
#define newl(T, ...)    (newl_funcof(T)(__VA_ARGS__))


PUBLIC(Vwbu,newlwbu)
(
    uint8_t k0, uint8_t k1, uint8_t k2, uint8_t k3
)
{
    return  VWBU_NEWL(k0, k1, k2, k3);
}

PUBLIC(Vwbi,newlwbi)
(
    int8_t k0, int8_t k1, int8_t k2, int8_t k3
)
{
    return  VWBI_NEWL(k0, k1, k2, k3);
}

PUBLIC(Vwbc,newlwbc)
(
    char k0, char k1, char k2, char k3
)
{
    return  VWBC_NEWL(k0, k1, k2, k3);
}


PUBLIC(Vwhu,newlwhu)
(
    uint16_t k0, uint16_t k1
)
{
    return  newlwhu(k0, k1);
}


PUBLIC(Vwhi,newlwhi)
(
    int16_t k0, int16_t k1
)
{
    return  VWHI_NEWL(k0, k1);
}

PUBLIC(Vwhf,newlwhf)
(
    flt16_t k0, flt16_t k1
)
{
    return  VWHF_NEWL(k0, k1);
}




PUBLIC(Vdbu,newldbu)
(
    uint8_t k0, uint8_t k1, uint8_t k2, uint8_t k3,
    uint8_t k4, uint8_t k5, uint8_t k6, uint8_t k7
)
{
    return  VDBU_NEWL(k0, k1, k2, k3, k4, k5, k6, k7);
}

PUBLIC(Vdbi,newldbi)
(
    int8_t k0, int8_t k1, int8_t k2, int8_t k3,
    int8_t k4, int8_t k5, int8_t k6, int8_t k7
)
{
    return VDBI_NEWL(k0, k1, k2, k3, k4, k5, k6, k7);
}

PUBLIC(Vdbc,newldbc)
(
    char k0, char k1, char k2, char k3,
    char k4, char k5, char k6, char k7
)
{
    return VDBC_NEWL(k0, k1, k2, k3, k4, k5, k6, k7);
}


PUBLIC(Vdhu,newldhu)
(
    uint16_t k0, uint16_t k1, uint16_t k2, uint16_t k3
)
{
    return  VDHU_NEWL(k0, k1, k2, k3);
}

PUBLIC(Vdhi,newldhi)
(
    int16_t k0, int16_t k1, int16_t k2, int16_t k3
)
{
    return  VDHI_NEWL(k0, k1, k2, k3);
}

PUBLIC(Vdhf,newldhf)
(
    flt16_t k0, flt16_t k1, flt16_t k2, flt16_t k3
)
{
    return  VDHF_NEWL(k0, k1, k2, k3);
}


PUBLIC(Vdwu,newldwu)
(
    uint32_t k0, uint32_t k1
)
{
    return  VDWU_NEWL(k0, k1);
}

PUBLIC(Vdwi,newldwi)
(
    int32_t k0, int32_t k1
)
{
    return  VDWI_NEWL(k0, k1);
}

PUBLIC(Vdwf,newldwf)
(
    float k0, float k1
)
{
    return  VDWF_NEWL(k0, k1);
}


PUBLIC(Vqbu,newlqbu)
(
    uint8_t  k0, uint8_t  k1, uint8_t  k2, uint8_t  k3,
    uint8_t  k4, uint8_t  k5, uint8_t  k6, uint8_t  k7,
    uint8_t  k8, uint8_t  k9, uint8_t k10, uint8_t k11,
    uint8_t k12, uint8_t k13, uint8_t k14, uint8_t k15
)
{
    return  VQBU_NEWL(
        k0,  k1,  k2,  k3,  k4,  k5,  k6,  k7,
        k8,  k9, k10, k11, k12, k13, k14, k15
    );
}

PUBLIC(Vqbi,newlqbi)
(
    int8_t  k0, int8_t  k1, int8_t  k2, int8_t  k3,
    int8_t  k4, int8_t  k5, int8_t  k6, int8_t  k7,
    int8_t  k8, int8_t  k9, int8_t k10, int8_t k11,
    int8_t k12, int8_t k13, int8_t k14, int8_t k15
)
{
    return  VQBI_NEWL(
        k0,  k1,  k2,  k3,  k4,  k5,  k6,  k7,
        k8,  k9, k10, k11, k12, k13, k14, k15
    );
}

PUBLIC(Vqbc,newlqbc)
(
    char  k0, char  k1, char  k2, char  k3,
    char  k4, char  k5, char  k6, char  k7,
    char  k8, char  k9, char k10, char k11,
    char k12, char k13, char k14, char k15
)
{
    return  VQBC_NEWL(
        k0,  k1,  k2,  k3,  k4,  k5,  k6,  k7,
        k8,  k9, k10, k11, k12, k13, k14, k15
    );
}

PUBLIC(Vqhu,newlqhu)
(
    uint16_t k0, uint16_t k1, uint16_t k2, uint16_t k3,
    uint16_t k4, uint16_t k5, uint16_t k6, uint16_t k7
)
{
    return VQHU_NEWL(k0, k1, k2, k3, k4, k5, k6, k7);
}

PUBLIC(Vqhi,newlqhi)
(
    int16_t k0, int16_t k1, int16_t k2, int16_t k3,
    int16_t k4, int16_t k5, int16_t k6, int16_t k7
)
{
    return VQHI_NEWL(k0, k1, k2, k3, k4, k5, k6, k7);
}

PUBLIC(Vqhf,newlqhf)
(
    flt16_t k0, flt16_t k1, flt16_t k2, flt16_t k3,
    flt16_t k4, flt16_t k5, flt16_t k6, flt16_t k7
)
{
    return VQHF_NEWL(k0, k1, k2, k3, k4, k5, k6, k7);
}

PUBLIC(Vqwu,newlqwu)
(
    uint32_t k0, uint32_t k1, uint32_t k2, uint32_t k3
)
{
    return  VQWU_NEWL(k0, k1, k2, k3);
}

PUBLIC(Vqwi,newlqwi)
(
    int32_t k0, int32_t k1, int32_t k2, int32_t k3
)
{
    return  VQWI_NEWL(k0, k1, k2, k3);
}

PUBLIC(Vqwf,newlqwf)
(
    float k0, float k1, float k2, float k3
)
{
    return  VQWF_NEWL(k0, k1, k2, k3);
}

PUBLIC(Vqdu,newlqdu)
(
    uint64_t k0, uint64_t k1
)
{
    return  VQDU_NEWL(k0, k1);
}

PUBLIC(Vqdi,newlqdi)
(
    int64_t k0, int64_t k1
)
{
    return  VQDI_NEWL(k0, k1);
}

PUBLIC(Vqdf,newlqdf)
(
    double k0, double k1
)
{
    return  VQDF_NEWL(k0, k1);
}

#define     newlwbu(...)    VWBU_NEWL(__VA_ARGS__)
#define     newlwbi(...)    VWBI_NEWL(__VA_ARGS__)
#define     newlwbc(...)    VWBC_NEWL(__VA_ARGS__)
#define     newlwhu(...)    VWHU_NEWL(__VA_ARGS__)
#define     newlwhi(...)    VWHI_NEWL(__VA_ARGS__)
#define     newlwhf(...)    VWHF_NEWL(__VA_ARGS__)

#define     newldbu(...)    VDBU_NEWL(__VA_ARGS__)
#define     newldbi(...)    VDBI_NEWL(__VA_ARGS__)
#define     newldbc(...)    VDBC_NEWL(__VA_ARGS__)
#define     newldhu(...)    VDHU_NEWL(__VA_ARGS__)
#define     newldhi(...)    VDHI_NEWL(__VA_ARGS__)
#define     newldhf(...)    VDHF_NEWL(__VA_ARGS__)
#define     newldwu(...)    VDWU_NEWL(__VA_ARGS__)
#define     newldwi(...)    VDWI_NEWL(__VA_ARGS__)
#define     newldwf(...)    VDWF_NEWL(__VA_ARGS__)

#define     newlqbu(...)    VQBU_NEWL(__VA_ARGS__)
#define     newlqbi(...)    VQBI_NEWL(__VA_ARGS__)
#define     newlqbc(...)    VQBC_NEWL(__VA_ARGS__)
#define     newlqhu(...)    VQHU_NEWL(__VA_ARGS__)
#define     newlqhi(...)    VQHI_NEWL(__VA_ARGS__)
#define     newlqhf(...)    VQHF_NEWL(__VA_ARGS__)
#define     newlqwu(...)    VQWU_NEWL(__VA_ARGS__)
#define     newlqwi(...)    VQWI_NEWL(__VA_ARGS__)
#define     newlqwf(...)    VQWF_NEWL(__VA_ARGS__)
#define     newlqdu(...)    VQDU_NEWL(__VA_ARGS__)
#define     newlqdi(...)    VQDI_NEWL(__VA_ARGS__)
#define     newlqdf(...)    VQDF_NEWL(__VA_ARGS__)

#if _LEAVE_NEWL
}
#endif

#if _ENTER_CATL
{
#endif

PUBLIC(Vdyu,catlwyu)(Vwyu l, Vwyu r);
PUBLIC(Vdbu,catlwbu)(Vwbu l, Vwbu r);
PUBLIC(Vdbi,catlwbi)(Vwbi l, Vwbi r);
PUBLIC(Vdbc,catlwbc)(Vwbc l, Vwbc r);

PUBLIC(Vdhu,catlwhu)(Vwhu l, Vwhu r);
PUBLIC(Vdhi,catlwhi)(Vwhi l, Vwhi r);
PUBLIC(Vdhf,catlwhf)(Vwhf l, Vwhf r);
PUBLIC(Vdwu,catlwwu)(Vwwu l, Vwwu r);
PUBLIC(Vdwi,catlwwi)(Vwwi l, Vwwi r);
PUBLIC(Vdwf,catlwwf)(Vwwf l, Vwwf r);

PUBLIC(Vqyu,catldyu)(Vdyu l, Vdyu r);
PUBLIC(Vqbu,catldbu)(Vdbu l, Vdbu r);
PUBLIC(Vqbi,catldbi)(Vdbi l, Vdbi r);
PUBLIC(Vqbc,catldbc)(Vdbc l, Vdbc r);
PUBLIC(Vqhu,catldhu)(Vdhu l, Vdhu r);
PUBLIC(Vqhi,catldhi)(Vdhi l, Vdhi r);
PUBLIC(Vqhf,catldhf)(Vdhf l, Vdhf r);
PUBLIC(Vqwu,catldwu)(Vdwu l, Vdwu r);
PUBLIC(Vqwi,catldwi)(Vdwi l, Vdwi r);
PUBLIC(Vqwf,catldwf)(Vdwf l, Vdwf r);
PUBLIC(Vqdu,catlddu)(Vddu l, Vddu r);
PUBLIC(Vqdi,catlddi)(Vddi l, Vddi r);
PUBLIC(Vqdf,catlddf)(Vddf l, Vddf r);
#define     catl_funcof(X)  \
FUNCOF(                     \
    catl,                   \
    (X),                    \
    NONE,   /* TGK */       \
    YWR,    /* TGW */       \
    YDR,    /* TGD */       \
    NONE,   /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGO */       \
    default: NULL           \
)
#define     catl(X)  (catl_funcof(X)(X))

PUBLIC(Vdyu,catlwyu)(Vwyu l, Vwyu r) {return VWYU_CATL(l, r);}
PUBLIC(Vdbu,catlwbu)(Vwbu l, Vwbu r) {return VWBU_CATL(l, r);}
PUBLIC(Vdbi,catlwbi)(Vwbi l, Vwbi r) {return VWBI_CATL(l, r);}
PUBLIC(Vdbc,catlwbc)(Vwbc l, Vwbc r) {return VWBC_CATL(l, r);}
PUBLIC(Vdhu,catlwhu)(Vwhu l, Vwhu r) {return VWHU_CATL(l, r);}
PUBLIC(Vdhi,catlwhi)(Vwhi l, Vwhi r) {return VWHI_CATL(l, r);}
PUBLIC(Vdhf,catlwhf)(Vwhf l, Vwhf r) {return VWHF_CATL(l, r);}
PUBLIC(Vdwu,catlwwu)(Vwwu l, Vwwu r) {return VWWU_CATL(l, r);}
PUBLIC(Vdwi,catlwwi)(Vwwi l, Vwwi r) {return VWWI_CATL(l, r);}
PUBLIC(Vdwf,catlwwf)(Vwwf l, Vwwf r) {return VWWF_CATL(l, r);}

PUBLIC(Vqyu,catldyu)(Vdyu l, Vdyu r) {return VDYU_CATL(l, r);}
PUBLIC(Vqbu,catldbu)(Vdbu l, Vdbu r) {return VDBU_CATL(l, r);}
PUBLIC(Vqbi,catldbi)(Vdbi l, Vdbi r) {return VDBI_CATL(l, r);}
PUBLIC(Vqbc,catldbc)(Vdbc l, Vdbc r) {return VDBC_CATL(l, r);}
PUBLIC(Vqhu,catldhu)(Vdhu l, Vdhu r) {return VDHU_CATL(l, r);}
PUBLIC(Vqhi,catldhi)(Vdhi l, Vdhi r) {return VDHI_CATL(l, r);}
PUBLIC(Vqhf,catldhf)(Vdhf l, Vdhf r) {return VDHF_CATL(l, r);}
PUBLIC(Vqwu,catldwu)(Vdwu l, Vdwu r) {return VDWU_CATL(l, r);}
PUBLIC(Vqwi,catldwi)(Vdwi l, Vdwi r) {return VDWI_CATL(l, r);}
PUBLIC(Vqwf,catldwf)(Vdwf l, Vdwf r) {return VDWF_CATL(l, r);}
PUBLIC(Vqdu,catlddu)(Vddu l, Vddu r) {return VDDU_CATL(l, r);}
PUBLIC(Vqdi,catlddi)(Vddi l, Vddi r) {return VDDI_CATL(l, r);}
PUBLIC(Vqdf,catlddf)(Vddf l, Vddf r) {return VDDF_CATL(l, r);}



#define     catlwyu(...)   VWYU_CATL(__VA_ARGS__)
#define     catlwbu(...)   VWBU_CATL(__VA_ARGS__)
#define     catlwbi(...)   VWBI_CATL(__VA_ARGS__)
#define     catlwbi(...)   VWBI_CATL(__VA_ARGS__)
#define     catlwhu(...)   VWHU_CATL(__VA_ARGS__)
#define     catlwhi(...)   VWHI_CATL(__VA_ARGS__)
#define     catlwhf(...)   VWHF_CATL(__VA_ARGS__)
#define     catlwwu(...)   VWWU_CATL(__VA_ARGS__)
#define     catlwwi(...)   VWWI_CATL(__VA_ARGS__)
#define     catlwwf(...)   VWWF_CATL(__VA_ARGS__)

#define     catldyu(...)   VDYU_CATL(__VA_ARGS__)
#define     catldbu(...)   VDBU_CATL(__VA_ARGS__)
#define     catldbi(...)   VDBI_CATL(__VA_ARGS__)
#define     catldbi(...)   VDBI_CATL(__VA_ARGS__)
#define     catldhu(...)   VDHU_CATL(__VA_ARGS__)
#define     catldhi(...)   VDHI_CATL(__VA_ARGS__)
#define     catldhf(...)   VDHF_CATL(__VA_ARGS__)
#define     catldwu(...)   VDWU_CATL(__VA_ARGS__)
#define     catldwi(...)   VDWI_CATL(__VA_ARGS__)
#define     catldwf(...)   VDWF_CATL(__VA_ARGS__)
#define     catlddu(...)   VDDU_CATL(__VA_ARGS__)
#define     catlddi(...)   VDDI_CATL(__VA_ARGS__)
#define     catlddf(...)   VDDF_CATL(__VA_ARGS__)

#if _LEAVE_CATL
}
#endif

#if _ENTER_PERS
{
#endif

/*  pers: Permute Single

    Identical to calling 'perm' with garbage values as the 
    second parameter ('B'), and indexes outside the bounds
    of the first operand result in undefined behavior.

*/ 

PUBLIC(Vwbu,perswbu)(Vwbu v, Rc(0,3) k0, Rc(0,3) k1, Rc(0,3) k2, Rc(0,3) k3);
PUBLIC(Vwbi,perswbi)(Vwbi v, Rc(0,3) k0, Rc(0,3) k1, Rc(0,3) k2, Rc(0,3) k3);
PUBLIC(Vwbc,perswbc)(Vwbc v, Rc(0,3) k0, Rc(0,3) k1, Rc(0,3) k2, Rc(0,3) k3);
PUBLIC(Vwhu,perswhu)(Vwhu v, Rc(0,1) k0, Rc(0,1) k1);
PUBLIC(Vwhi,perswhi)(Vwhi v, Rc(0,1) k0, Rc(0,1) k1);
PUBLIC(Vwhf,perswhf)(Vwhf v, Rc(0,1) k0, Rc(0,1) k1);

PUBLIC(Vdbu,persdbu)
(
    Vdbu v, 
    Rc(0,7) k0, Rc(0,7) k1, Rc(0,7) k2, Rc(0,7) k3,
    Rc(0,7) k4, Rc(0,7) k5, Rc(0,7) k6, Rc(0,7) k7
);

PUBLIC(Vdbi,persdbi)
(
    Vdbi v, 
    Rc(0,7) k0, Rc(0,7) k1, Rc(0,7) k2, Rc(0,7) k3,
    Rc(0,7) k4, Rc(0,7) k5, Rc(0,7) k6, Rc(0,7) k7
);

PUBLIC(Vdbc,persdbc)
(
    Vdbc v, 
    Rc(0,7) k0, Rc(0,7) k1, Rc(0,7) k2, Rc(0,7) k3,
    Rc(0,7) k4, Rc(0,7) k5, Rc(0,7) k6, Rc(0,7) k7
);

PUBLIC(Vdhu,persdhu)(Vdhu v, Rc(0,3) k0, Rc(0,3) k1, Rc(0,3) k2, Rc(0,3) k3);
PUBLIC(Vdhi,persdhi)(Vdhi v, Rc(0,3) k0, Rc(0,3) k1, Rc(0,3) k2, Rc(0,3) k3);
PUBLIC(Vdhf,persdhf)(Vdhf v, Rc(0,3) k0, Rc(0,3) k1, Rc(0,3) k2, Rc(0,3) k3);
PUBLIC(Vdwu,persdwu)(Vdwu v, Rc(0,1) k0, Rc(0,1) k1);
PUBLIC(Vdwi,persdwi)(Vdwi v, Rc(0,1) k0, Rc(0,1) k1);
PUBLIC(Vdwf,persdwf)(Vdwf v, Rc(0,1) k0, Rc(0,1) k1);

PUBLIC(Vqbu,persqbu)
(
    Vqbu v, 
    Rc(0,15) k0, Rc(0,15) k1, Rc(0,15) k2, Rc(0,15) k3,
    Rc(0,15) k4, Rc(0,15) k5, Rc(0,15) k6, Rc(0,15) k7,
    Rc(0,15) k8, Rc(0,15) k9, Rc(0,15) k10,Rc(0,15) k11,
    Rc(0,15) k12,Rc(0,15) k13,Rc(0,15) k14,Rc(0,15) k15
);

PUBLIC(Vqbi,persqbi)
(
    Vqbi v, 
    Rc(0,15) k0, Rc(0,15) k1, Rc(0,15) k2, Rc(0,15) k3,
    Rc(0,15) k4, Rc(0,15) k5, Rc(0,15) k6, Rc(0,15) k7,
    Rc(0,15) k8, Rc(0,15) k9, Rc(0,15) k10,Rc(0,15) k11,
    Rc(0,15) k12,Rc(0,15) k13,Rc(0,15) k14,Rc(0,15) k15
);

PUBLIC(Vqbc,persqbc)
(
    Vqbc v, 
    Rc(0,15) k0, Rc(0,15) k1, Rc(0,15) k2, Rc(0,15) k3,
    Rc(0,15) k4, Rc(0,15) k5, Rc(0,15) k6, Rc(0,15) k7,
    Rc(0,15) k8, Rc(0,15) k9, Rc(0,15) k10,Rc(0,15) k11,
    Rc(0,15) k12,Rc(0,15) k13,Rc(0,15) k14,Rc(0,15) k15
);


PUBLIC(Vqhu,persqhu)
(
    Vqhu v, 
    Rc(0,7) k0, Rc(0,7) k1, Rc(0,7) k2, Rc(0,7) k3,
    Rc(0,7) k4, Rc(0,7) k5, Rc(0,7) k6, Rc(0,7) k7
);

PUBLIC(Vqhi,persqhi)
(
    Vqhi v, 
    Rc(0,7) k0, Rc(0,7) k1, Rc(0,7) k2, Rc(0,7) k3,
    Rc(0,7) k4, Rc(0,7) k5, Rc(0,7) k6, Rc(0,7) k7
);

PUBLIC(Vqhf,persqhf)
(
    Vqhf v, 
    Rc(0,7) k0, Rc(0,7) k1, Rc(0,7) k2, Rc(0,7) k3,
    Rc(0,7) k4, Rc(0,7) k5, Rc(0,7) k6, Rc(0,7) k7
);

PUBLIC(Vqwu,persqwu)(Vqwu v, Rc(0,3) k0, Rc(0,3) k1, Rc(0,3) k2, Rc(0,3) k3);
PUBLIC(Vqwi,persqwi)(Vqwi v, Rc(0,3) k0, Rc(0,3) k1, Rc(0,3) k2, Rc(0,3) k3);
PUBLIC(Vqwf,persqwf)(Vqwf v, Rc(0,3) k0, Rc(0,3) k1, Rc(0,3) k2, Rc(0,3) k3);

PUBLIC(Vqdu,persqdu)(Vqdu v, Rc(0,1) k0, Rc(0,1) k1);
PUBLIC(Vqdi,persqdi)(Vqdi v, Rc(0,1) k0, Rc(0,1) k1);
PUBLIC(Vqdf,persqdf)(Vqdf v, Rc(0,1) k0, Rc(0,1) k1);

#define     pers_funcof(X)  \
FUNCOF(                     \
    pers,   (   X   ),      \
    NONE,   /* TGK */       \
    BR,     /* TGW */       \
    NONE,   /* TGD */       \
    NONE,   /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGO */       \
    default: NULL           \
)
#define     pers(V, ...)    (pers_funcof(V)(V,__VA_ARGS__))


PUBLIC(Vwbu,perswbu)
(
    Vwbu v,
    Rc(0,3) k0, Rc(0,3) k1, Rc(0,3) k2, Rc(0,3) k3
)
{
    return  VWBU_PERS(v, k0, k1, k2, k3);
}

PUBLIC(Vwbi,perswbi)
(
    Vwbi v, 
    Rc(0,3) k0, Rc(0,3) k1, Rc(0,3) k2, Rc(0,3) k3
)
{
    return  VWBI_PERS(v, k0, k1, k2, k3);
}

PUBLIC(Vwbc,perswbc)
(
    Vwbc v, 
    Rc(0,3) k0, Rc(0,3) k1, Rc(0,3) k2, Rc(0,3) k3
)
{
    return  VWBC_PERS(v, k0, k1, k2, k3);
}

PUBLIC(Vwhu,perswhu)(Vwhu v, Rc(0,1) k0, Rc(0,1) k1)
{
    return  VWHU_PERS(v, k0, k1);
}

PUBLIC(Vwhi,perswhi)(Vwhi v, Rc(0,1) k0, Rc(0,1) k1)
{
    return  VWHI_PERS(v, k0, k1);
}

PUBLIC(Vwhf,perswhf)(Vwhf v, Rc(0,1) k0, Rc(0,1) k1)
{
    return  VWHF_PERS(v, k0, k1);
}


PUBLIC(Vdbu,persdbu)
(
    Vdbu v, 
    Rc(0,7) k0, Rc(0,7) k1, Rc(0,7) k2, Rc(0,7) k3,
    Rc(0,7) k4, Rc(0,7) k5, Rc(0,7) k6, Rc(0,7) k7
)
{
    return  VDBU_PERS(v,k0,k1,k2,k3,k4,k5,k6,k7);
}

PUBLIC(Vdbi,persdbi)
(
    Vdbi v, 
    Rc(0,7) k0, Rc(0,7) k1, Rc(0,7) k2, Rc(0,7) k3,
    Rc(0,7) k4, Rc(0,7) k5, Rc(0,7) k6, Rc(0,7) k7
)
{
    return  VDBI_PERS(v,k0,k1,k2,k3,k4,k5,k6,k7);
}

PUBLIC(Vdbc,persdbc)
(
    Vdbc v, 
    Rc(0,7) k0, Rc(0,7) k1, Rc(0,7) k2, Rc(0,7) k3,
    Rc(0,7) k4, Rc(0,7) k5, Rc(0,7) k6, Rc(0,7) k7
)
{
    return  VDBC_PERS(v,k0,k1,k2,k3,k4,k5,k6,k7);
}

PUBLIC(Vdhu,persdhu)
(
    Vdhu v, 
    Rc(0,3) k0, Rc(0,3) k1, Rc(0,3) k2, Rc(0,3) k3
)
{
    return  VDHU_PERS(v, k0, k1, k2, k3);
}

PUBLIC(Vdhi,persdhi)
(
    Vdhi v, 
    Rc(0,3) k0, Rc(0,3) k1, Rc(0,3) k2, Rc(0,3) k3
)
{
    return  VDHI_PERS(v, k0, k1, k2, k3);
}

PUBLIC(Vdhf,persdhf)
(
    Vdhf v, 
    Rc(0,3) k0, Rc(0,3) k1, Rc(0,3) k2, Rc(0,3) k3
)
{
    return  VDHF_PERS(v, k0, k1, k2, k3);
}

PUBLIC(Vdwu,persdwu)(Vdwu v, Rc(0,1) k0, Rc(0,1) k1)
{
    return  VDWU_PERS(v, k0, k1);
}

PUBLIC(Vdwi,persdwi)(Vdwi v, Rc(0,1) k0, Rc(0,1) k1)
{
    return  VDWI_PERS(v, k0, k1);
}

PUBLIC(Vdwf,persdwf)(Vdwf v, Rc(0,1) k0, Rc(0,1) k1)
{
    return  VDWF_PERS(v, k0, k1);
}

PUBLIC(Vqbu,persqbu)
(
    Vqbu v, 
    Rc(0,15) k0, Rc(0,15) k1, Rc(0,15) k2, Rc(0,15) k3,
    Rc(0,15) k4, Rc(0,15) k5, Rc(0,15) k6, Rc(0,15) k7,
    Rc(0,15) k8, Rc(0,15) k9, Rc(0,15) k10,Rc(0,15) k11,
    Rc(0,15) k12,Rc(0,15) k13,Rc(0,15) k14,Rc(0,15) k15
)
{
    return  VQBU_PERS(
        v,
        k0, k1, k2,  k3,  k4,  k5,  k6,  k7,
        k8, k9, k10, k11, k12, k13, k14, k15
    );
}

PUBLIC(Vqbi,persqbi)
(
    Vqbi v, 
    Rc(0,15) k0, Rc(0,15) k1, Rc(0,15) k2, Rc(0,15) k3,
    Rc(0,15) k4, Rc(0,15) k5, Rc(0,15) k6, Rc(0,15) k7,
    Rc(0,15) k8, Rc(0,15) k9, Rc(0,15) k10,Rc(0,15) k11,
    Rc(0,15) k12,Rc(0,15) k13,Rc(0,15) k14,Rc(0,15) k15
)
{
    return  VQBI_PERS(
        v,
        k0, k1, k2,  k3,  k4,  k5,  k6,  k7,
        k8, k9, k10, k11, k12, k13, k14, k15
    );
}

PUBLIC(Vqbc,persqbc)
(
    Vqbc v, 
    Rc(0,15) k0, Rc(0,15) k1, Rc(0,15) k2, Rc(0,15) k3,
    Rc(0,15) k4, Rc(0,15) k5, Rc(0,15) k6, Rc(0,15) k7,
    Rc(0,15) k8, Rc(0,15) k9, Rc(0,15) k10,Rc(0,15) k11,
    Rc(0,15) k12,Rc(0,15) k13,Rc(0,15) k14,Rc(0,15) k15
)
{
    return  VQBC_PERS(
        v,
        k0, k1, k2,  k3,  k4,  k5,  k6,  k7,
        k8, k9, k10, k11, k12, k13, k14, k15
    );
}

PUBLIC(Vqhu,persqhu)
(
    Vqhu v, 
    Rc(0,7) k0, Rc(0,7) k1, Rc(0,7) k2, Rc(0,7) k3,
    Rc(0,7) k4, Rc(0,7) k5, Rc(0,7) k6, Rc(0,7) k7
)
{
    return  VQHU_PERS(v, k0, k1, k2, k3, k4, k5, k6, k7);
}

PUBLIC(Vqhi,persqhi)
(
    Vqhi v, 
    Rc(0,7) k0, Rc(0,7) k1, Rc(0,7) k2, Rc(0,7) k3,
    Rc(0,7) k4, Rc(0,7) k5, Rc(0,7) k6, Rc(0,7) k7
)
{
    return  VQHI_PERS(v, k0, k1, k2, k3, k4, k5, k6, k7);
}

PUBLIC(Vqhf,persqhf)
(
    Vqhf v, 
    Rc(0,7) k0, Rc(0,7) k1, Rc(0,7) k2, Rc(0,7) k3,
    Rc(0,7) k4, Rc(0,7) k5, Rc(0,7) k6, Rc(0,7) k7
)
{
    return  VQHF_PERS(v, k0, k1, k2, k3, k4, k5, k6, k7);
}


PUBLIC(Vqwu,persqwu)(Vqwu v, Rc(0,3) k0, Rc(0,3) k1, Rc(0,3) k2, Rc(0,3) k3)
{
    return  VQWU_PERS(v, k0, k1, k2, k3);
}

PUBLIC(Vqwi,persqwi)(Vqwi v, Rc(0,3) k0, Rc(0,3) k1, Rc(0,3) k2, Rc(0,3) k3)
{
    return  VQWI_PERS(v, k0, k1, k2, k3);
}

PUBLIC(Vqwf,persqwf)(Vqwf v, Rc(0,3) k0, Rc(0,3) k1, Rc(0,3) k2, Rc(0,3) k3)
{
    return  VQWF_PERS(v, k0, k1, k2, k3);
}


PUBLIC(Vqdu,persqdu)(Vqdu v, Rc(0,1) k0, Rc(0,1) k1)
{
    return  VQDU_PERS(v, k0, k1);
}

PUBLIC(Vqdi,persqdi)(Vqdi v, Rc(0,1) k0, Rc(0,1) k1)
{
    return  VQDI_PERS(v, k0, k1);
}

PUBLIC(Vqdf,persqdf)(Vqdf v, Rc(0,1) k0, Rc(0,1) k1)
{
    return  VQDF_PERS(v, k0, k1);
}

#define     perswbu(...)    VWBU_PERS(__VA_ARGS__)
#define     perswbi(...)    VWBI_PERS(__VA_ARGS__)
#define     perswbc(...)    VWBC_PERS(__VA_ARGS__)
#define     perswhu(...)    VWHU_PERS(__VA_ARGS__)
#define     perswhi(...)    VWHI_PERS(__VA_ARGS__)
#define     perswhf(...)    VWHF_PERS(__VA_ARGS__)

#define     persdbu(...)    VDBU_PERS(__VA_ARGS__)
#define     persdbi(...)    VDBI_PERS(__VA_ARGS__)
#define     persdbc(...)    VDBC_PERS(__VA_ARGS__)
#define     persdhu(...)    VDHU_PERS(__VA_ARGS__)
#define     persdhi(...)    VDHI_PERS(__VA_ARGS__)
#define     persdhf(...)    VDHF_PERS(__VA_ARGS__)
#define     persdwu(...)    VDWU_PERS(__VA_ARGS__)
#define     persdwi(...)    VDWI_PERS(__VA_ARGS__)
#define     persdwf(...)    VDWF_PERS(__VA_ARGS__)

#define     persqbu(...)    VQBU_PERS(__VA_ARGS__)
#define     persqbi(...)    VQBI_PERS(__VA_ARGS__)
#define     persqbc(...)    VQBC_PERS(__VA_ARGS__)
#define     persqhu(...)    VQHU_PERS(__VA_ARGS__)
#define     persqhi(...)    VQHI_PERS(__VA_ARGS__)
#define     persqhf(...)    VQHF_PERS(__VA_ARGS__)
#define     persqwu(...)    VQWU_PERS(__VA_ARGS__)
#define     persqwi(...)    VQWI_PERS(__VA_ARGS__)
#define     persqwf(...)    VQWF_PERS(__VA_ARGS__)
#define     persqdu(...)    VQDU_PERS(__VA_ARGS__)
#define     persqdi(...)    VQDI_PERS(__VA_ARGS__)
#define     persqdf(...)    VQDF_PERS(__VA_ARGS__)

#if _LEAVE_PERS
}
#endif

#if _ENTER_VXT1
{
#endif

PUBLIC(uint8_t,vxt1wbu) (Vwbu v, Rc(0,+3) k)
{
#define vxt1wbu VWBU_VXT1
    return (VWBU_VXT1)(v, k);
}

PUBLIC(int8_t,vxt1wbi) (Vwbi v, Rc(0,+3) k)
{
#define vxt1wbi VWBI_VXT1
    return (VWBI_VXT1)(v, k);
}

PUBLIC(char,vxt1wbc) (Vwbc v, Rc(0,+3) k)
{
#define vxt1wbc VWBC_VXT1
    return (VWBC_VXT1)(v, k);
}

#if _LEAVE_VXT1
}
#endif

#define     vxt1_funcof(T)  \
FUNCOF(                     \
    vxt1, (T){0},           \
    NONE,   /* TGK */       \
    YWR,    /* TGW */       \
    YDR,    /* TGD */       \
    YDR,    /* TGQ */       \
    NONE,   /* TGO */       \
    NONE,   /* TGO */       \
    default: NULL           \
)

#ifdef SPC_ARM_NEON
int TEST_ARM_VXT1(FILE *f)
{
    if (f == NULL)
        f = stdout;
    int res;
    int sum = 0;
#define MY_TEST(...)                \
    res = fprintf(f, __VA_ARGS__);  \
    if (res < 0) goto FAIL;         \
    sum += res

    MY_TEST("TEST_ARM_VXT1()\n");
    
    Vdhu dh = newl(Vdhu, '0','1','2','3');
    dh = VDHU_PERS(dh, 3,0,1, 2);
    MY_TEST(
        "%c%c%c%c\n",
        VDHU_VXT1(dh, 0),
        VDHU_VXT1(dh, 1),
        VDHU_VXT1(dh, 2),
        VDHU_VXT1(dh, 3)
    );

#undef MY_TEST
    SUCC: return sum;
    FAIL: return res;
}
void TEST_ARM_PERS(void)
{
    float32x2_t df = vreinterpret_f32_s32(vdup_n_s32(0));
    Vwbu w0123 = newl(Vwbu, '0', '1','2','3');
    Vwbu w3012 = VWBU_PERS(w0123, 3,0,1,2);
    uint8_t s16[17] = {0};
    df = vset_lane_f32(VWBU_ASTM(w3012), df, 0);
    vst1_u8(s16, VDWF_ASBU(df));
    (void) printf(
        "%.16s\n",
        s16
    );
   
}
#endif

int main(int argc, char *argv[], char *envp[])
{
    Vdbu l;
    Vdbu r;
    Vqbu c = vstl(c, l);
    asbu(argv[0][0]);
    asbc(argv[0][0]);
    asbi(argv[0][0]);
    ashu((int16_t){0});
#if 0
    flt16_t k0=1.2, k1=3.4, k2=5.6, k3=7.8;
    Vdhf dhfv = vdup_n_f16(0);
    dhfv = vst1(dhfv, V4_K0, k0);
    //(VDHF_VST1)(dhfv, V4_K0, k0);
    dhfv = (VDHF_VST1)(dhfv, V4_K1, k1);
    dhfv = (VDHF_VST1)(dhfv, V4_K2, k2);
    dhfv = (VDHF_VST1)(dhfv, V4_K3, k3);
    printf(
        "dhfv => {%g,%g,%g,%g}\n", 
        vget_lane_f16(dhfv, V4_K0),
        vget_lane_f16(dhfv, V4_K1),
        vget_lane_f16(dhfv, V4_K2),
        vget_lane_f16(dhfv, V4_K3)
    );
    Vdhu dhfm = vdup_n_f16(0);
    dhfm =  vst1dhf(dhfm, V4_K0, k0);
    dhfm =  vst1dhf(dhfm, V4_K1, k1);
    dhfm =  vst1dhf(dhfm, V4_K2, k2);
    dhfm =  vst1dhf(dhfm, V4_K3, k3);
    printf(
        "dhfm => {%g,%g,%g,%g}\n", 
        vget_lane_f16(dhfm, V4_K0),
        vget_lane_f16(dhfm, V4_K1),
        vget_lane_f16(dhfm, V4_K2),
        vget_lane_f16(dhfm, V4_K3)
    );

#endif

#if 0

    Vdwf dwfv = vdup_n_f32(0);
    Vdwf dwfm = vdup_n_f32(0);
    float l = 123.4f;
    float r = 567.8f;
    dwfv = (VDWF_VST1)(dwfv, V2_K1, r);
    dwfv = (VDWF_VST1)(dwfv, V2_K0, l);
    dwfm =  VDWF_VST1( dwfm, V2_K1, r);
    dwfm =  VDWF_VST1( dwfm, V2_K0, l);
    printf(
        "dwfv => {%g, %g}\n",
        vget_lane_f32(dwfv, V2_K0),
        vget_lane_f32(dwfv, V2_K1)
    );
    printf(
        "dwfm => {%g, %g}\n",
        vget_lane_f32(dwfm, V2_K0),
        vget_lane_f32(dwfm, V2_K1)
    );
#endif

#if 0
    //dhf = (VDHF_VST1)(dhf, V4_K2, 123.4f16);
    dhf =   (VDHF_VST1)(dhf, V4_K2, 123.4F16);
    printf("dhf[2] => %g\n", (double) vget_lane_f16(dhf, V4_K2));
    Vddu ddu = astvdu(UINT64_MAX);
    Vdyu dyu = asyu(ddu);
    ddu = vbic_u64(ddu, astvdu(0xff));
    printf("vbic(0xffffffff, 0xff) => %llx\n", (ullong) astvddu(ddu));
    Vdbu dbu = asbu(astv((uint64_t){0}));
    dbu = (VDBU_VST1)(dbu, 0,'0');
    dbu = (VDBU_VST1)(dbu, 1,'1');
    dbu = (VDBU_VST1)(dbu, 2,'2');
    dbu = (VDBU_VST1)(dbu, 3,'3');
    dbu = (VDBU_VST1)(dbu, 4,'4');
    dbu = (VDBU_VST1)(dbu, 5,'5');
    dbu = (VDBU_VST1)(dbu, 6,'6');
    dbu = (VDBU_VST1)(dbu, 7,'7');
    dbu = VDBU_VST1(dbu, 0,'0');
    dbu = VDBU_VST1(dbu, 1,'1');
    dbu = VDBU_VST1(dbu, 2,'2');
    dbu = VDBU_VST1(dbu, 3,'3');
    dbu = VDBU_VST1(dbu, 4,'4');
    dbu = VDBU_VST1(dbu, 5,'5');
    dbu = VDBU_VST1(dbu, 6,'6');
    dbu = VDBU_VST1(dbu, 7,'7');
#endif
#if 0
    char str[17] = {0};
    vst1_u8((void *) str, dbu);
    printf("str[:] => %.16s\n", str);
    printf("ldr1(str) => %hhu\n", ldr1(unsigned char, str));
    printf("vcvtd_u64_f64(%g) => %llu\n",DBL_MAX,(ullong)vcvtd_u64_f64(DBL_MAX));
    printf("vcvtd_u64_f64(-%g) => %llu\n",-DBL_MAX,(ullong)vcvtd_u64_f64(-DBL_MAX));
    
    printf("vcvth_u32_f32(%gf) => %u\n",FLT_MAX,vcvts_u32_f32(FLT_MAX));

    printf("vcvtd_s64_f64(+%g) => %+lli\n", DBL_MAX,(llong)vcvtd_s64_f64( DBL_MAX));
    printf("vcvtd_s64_f64(-%g) => %+lli\n",-DBL_MAX,(llong)vcvtd_s64_f64(-DBL_MAX));

    uint16_t khu = vxtr(0xffff0000u);
    printf("asbu((int8_t){-1}) => %hhu\n", asbu((int8_t){-1}));
    printf("vxtr(0xffff0000) => %hu\n", khu);
    Vwhu vhu = dupw((uint16_t){12345});
    printf("%hu, %hu\n", VWHU_VXT1(vhu, 0), VWHU_VXT1(vhu, 1));
    vhu = USHRT_DUPW(54321);
    printf("%hu, %hu\n", VWHU_VXT1(vhu, 0), VWHU_VXT1(vhu, 1));
#endif
#if 0
    printf("saz1((uint32_t){555555}) => %u\n", saz1(555555u));
    float16x4_t ihf = VDHF_NEWL(
        0.0f16,
        1.0f16,
        2.0f16,
        3.0f16
    );
    float32x4_t iwf = vcvt_f32_f16(ihf);
    printf("wfi[2] => %g\n", VQWF_VXT1(iwf, 2));
    
    void *p = (
        &newlwbu && &newlwbi &&
        &newlwhu && &newlwhi && &newlwhf &&

        &newldbu && &newldbi &&
        &newldhu && &newldhi && &newldhf &&
        &newldwu && &newldwi && &newldwf &&

        &newldbu && &newlqbi &&
        &newlqhu && &newlqhi && &newlqhf &&
        &newlqwu && &newlqwi && &newlqwf &&
        &newlqdu && &newlqdi && &newlqdf &&

        &catlwbu && &catlwbi &&
        &catlwhu && &catlwhi && &catlwhf &&
        &catlwwu && &catlwwi && &catlwwf &&

        &catldbu && &catldbi &&
        &catldhu && &catldhi && &catldhf &&
        &catldwu && &catldwi && &catldwf &&
        &catlddu && &catlddi && &catlddf

    ) ? NULL : (intptr_t) 0;
    if (0) TEST_ARM_PERS();
    if (1) TEST_ARM_VXT1(0);
#endif
#if 0
    Vwbu m = newl(__typeof__(m), 0,1,2,3);
    Vdbu d = VWBU_CATL(m, VWBU_VOID);
    uint8_t s[17];
    (void) VDBU_STRD(d, s);
    return printf(
        "{0, 1, 2, 3} => {%hhu, %hhu, %hhu, %hhu}\n",
        s[0],s[1],s[2],s[3]
    ) < 0;
        
    Dwu m = newldwu('a','a');
    m = persdwu(m, 1,0);
    uint32_t s[9] = {0};
    return printf("%c,%c\n", s[0], s[1]) < 0;
    return printf("%c,%c,%c,%c\n", s[0],s[1],s[2],s[3]) < 0;
    Dhu m = newldhu('0','1','2','3');
    m = persdhu(m, 3, 0, 2, 1);
    return printf("%.8s\n", s) < 0;
    
    Vdbu v = DW_PERS(vdup_n_u8(0), 0, 1);
    Vdbi v = DBI_ASTV(m);
    int x = ldr1(&argc);
    Vdbu c = ldrd("smfd pls");
    vst1_u8(s, c);
#endif
/*
    Vdbu c = newl(Vdbu, 's', 'm', 'f', 'd', ' ', 'p', 'l', 's');
*/
}