
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳

    Extends <stddef.h>

    -bi     [1] (SCHAR)
    -hi     [1] (SHRT)
    -wi     [1] (INT)
    -di     [2] (LONG|LLONG)
    -qi     [3] (LLONG|INT128X|XQI)

    -hf     [2] (FLT16|XHF)
    -wf     [1] (FLT)
    -df     [1] (DBL)
    -qf     [1] (LDBL|FLT128|XQF)

*/

#ifndef MY_EXTDEF_H
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

#ifndef __STDC_WANT_IEC_60559_TYPES_EXT__
#define __STDC_WANT_IEC_60559_TYPES_EXT__
#endif


#undef  CONCAT1
#undef  CONCAT2
#undef  CONCAT3

#undef  STRIZE0
#undef  STRIZE1
#undef  STRIZE2
#undef  STRIZE3
#undef  STRIZE4
#undef  STRIZE5
#undef  STRIZE6
#undef  STRIZE7
#undef  STRIZE8

#undef  EXPAND1
#undef  EXPAND2
#undef  EXPAND3
#undef  EXPAND4
#undef  EXPAND5
#undef  EXPAND6
#undef  EXPAND7
#undef  EXPAND8

#undef  LENGTHOF
#undef  ASSERT
#undef  UNREACHABLE
#undef  UNUSED
#undef  INLINE
#undef  IDENTITY
#undef  RESTRICT

#define IGNORED(...)
#define IDENTITY(...) __VA_ARGS__

#define VA_APPEND(_,...) __VA_OPT__(__VA_ARGS__,)_

/*  ENDIAN_@

    For each type there is an @_ENDIAN symbol defined, which
    indicates how values are represented in memory.

    `ENDIAN_LIL` means all or part of a value's first element
    is stored in the byte with the lowest address.

    `ENDIAN_BIG` means all or part of a value's first element
    is stored in the byte with the highest address.

    `ENDIAN_NAT` means `MY_ENDIAN` determines order.

    What the "first element" means depends on the type: for
    integers, it's the least significant bit; for floats,
    it's the mantissa; for vectors, it's the element at index
    0.

    Endianness is recursive. E.g. there are four unique ways
    a machine might represent a 32 bit float and in theory,
    16 unique ways to represent a 128 bit vector of four 32
    bit floats. In practice, the endianness of floats will
    always be ENDIAN_LIL, since we only support targets that
    allocate bitfields from least to most significant.

*/

#define ENDIAN_NAT  (0) // use value of MY_ENDIAN instead
#define ENDIAN_LIL  (1)
#define ENDIAN_BIG  (2)
#define ENDIAN_OTH  (3)

/*  Compile time assertions */

#if     __STDC_VERSION__ >= 201710L
#   define  ASSERT   static_assert
#else
#   define  ASSERT(C, ...) \
    _Static_assert((C), #C __VA_OPT__(" => \n" #__VA_ARGS__))
#endif

/*  Compute length of a C array, as a `size_t` expression

    LENGTHOF((int[]){0, 0, 0} ) => 3
*/

#define LENGTHOF(x) (sizeof(x)/sizeof((x)[0]))

/*  UNREACHABLE()

    Identify a branch that should never occur during normal
    program execution.

    E.g. since `c != 0` evaluates to `0` or `1`, the default
    case in the following switch statement could only occur
    if the register or memory in which it is stored was
    corrupted somehow:

        switch (c != 0)
        {
            case 0: return 0;
            case 1: return 1;
            default: UNREACHABLE()
        }
*/

#if defined(unreachable)
#   define  UNREACHABLE     unreachable
#elif defined(_MSC_VER)
#   define  UNREACHABLE()   __assume(0)
#elif defined(__clang__)
#   define  UNREACHABLE     __builtin_unreachable
#elif defined(__GNUC__)
#   define  UNREACHABLE     __builtin_unreachable
#else
#   ifndef MY_STDLIB_H
#   define MY_STDLIB_H
#   include <stdlib.h>
#   define  UNREACHABLE     abort
#   endif
#endif

/*  UNUSED(parameter)

    Prevent "unreferenced parameter" warnings. E.g. in MSVC,
    the /Wall option causes the following function to emit
    a warning that nothing references `self`.

        void *nothin(void *restrict self) {return 0;}

    To suppress this behavior, decorate the identifier of
    the parameter in the function definition as so:

        void *nothin(void *restrict UNUSED(self)) {return 0;}

*/
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

/*  Inline function function specifier */
#if defined(_MSC_VER)
#   define  INLINE __forceinline
#else
#   define  INLINE static inline
#endif

/*  Annotate a function parameter as not aliased */
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
#include <errno.h>
#endif

#ifndef MY_STDBOOL_H
#define MY_STDBOOL_H
#include  <stdbool.h>
#endif

#ifndef MY_STDDEF_H
#define MY_STDDEF_H
#include <stddef.h>
#endif

/*  SPC_@ : [S]upplementary [P]rocessor [C]apability

    Each ISA very likely has a set of supplementary features
    that are limited to only a subset of implementations.
*/

#define ISA_X86     1
#define ISA_ARM     3
#define ISA_RV      5
#define ISA_PPC     6
#define ISA_MIPS    7
#define ISA_IA64    8

#if defined(_MSC_VER)
/*  MSVC support is limited to 64 bit x86. This is because
    it doesn't implement ACLE, and even if did, the fact
    that the arm vector types are not unique is more than
    enough of a reason.
*/
/*  It'd be nice to know if there's a modern target with a
    default page size that isn't 4096
*/
/*
gcc:
    'mabi=sysv' || 'mabi=ms'
*/

#   if defined(_M_ARM64EC)
#       define MY_ISA       ISA_X86
#       define SPC_X86_X64
#   elif defined(_M_X64)
#       define MY_ISA       ISA_X86
#       define SPC_X86_X64
#   elif defined(_M_AMD64)
#       define MY_ISA       ISA_X86
#       define SPC_X86_X64
#   elif defined(_M_IA64)
#       define MY_ISA       ISA_IA64
#   elif defined(_M_IX86)
#       define MY_ISA       ISA_X86
#       define SPC_X86_X32
#   elif defined(_M_ARM64)
#       define MY_ISA       ISA_ARM
#   elif defined(_M_ARM)
#       define MY_ISA       ISA_ARM
#   elif defined(_M_ARMV7VE)
#       define MY_ISA       ISA_ARM
#   elif defined(_M_ALPHA)
#       define MY_ISA       ISA_ALPHA
#   elif defined(_M_PPC)
#       define MY_ISA       ISA_PPC
#   else //_M_MRX000
#       error "unable to detect MSVC compilation target"
#   endif

#   if MY_ISA == ISA_X86
#       ifndef _M_IX86_FP
#       error "_M_IX86_FP not defined"
#       endif

#       if   _M_IX86_FP == 0

#       elif _M_IX86_FP == 1
#           ifndef SPC_X86_SSE
#           define SPC_X86_SSE
#           endif

#       elif _M_IX86_FP == 2
#           ifndef SPC_X86_SSE2
#           define SPC_X86_SSE2
#           endif
#       endif

#   endif

#   ifndef MY_ENDIAN
#   define MY_ENDIAN  ENDIAN_LIL
#   endif

/*  The ACLE is expected on arm targets */
#elif defined(__ARM_ACLE)

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
#   error "float is required"
#   endif

#   if defined(__ARM_FP16_FORMAT_ALTERNATIVE) 
#   error "__fp16 must be binary16 based"
#   endif

#   define MY_ISA ISA_ARM

#   define SPC_ARM_NEON

#   define SPC_ARM_PROFILE  __ARM_ARCH_PROFILE

#   ifndef __ARM_FEATURE_LDREX
#   define SPC_ARM_LDREX    0
#   else
#   define SPC_ARM_LDREX    __ARM_FEATURE_LDREX
#   endif

#   define SPC_ARM_LDREX_B ((SPC_ARM_LDREX&0x01) != 0)
#   define SPC_ARM_LDREX_H ((SPC_ARM_LDREX&0x02) != 0)
#   define SPC_ARM_LDREX_W ((SPC_ARM_LDREX&0x04) != 0)
#   define SPC_ARM_LDREX_D ((SPC_ARM_LDREX&0x08) != 0)
#   define SPC_ARM_LDREX_Q ((SPC_ARM_LDREX&0x10) != 0)

#   ifndef __ARM_FEATURE_FP16_SCALAR_ARITHMETIC
#   define SPC_ARM_FP16_MATH    (-1)
#   else
#   define SPC_ARM_FP16_MATH    __ARM_FEATURE_FP16_SCALAR_ARITHMETIC
#   endif

#   ifndef __ARM_FEATURE_FP16_VECTOR_ARITHMETIC
#   define SPC_ARM_FP16_SIMD    (-1)
#   else
#   define SPC_ARM_FP16_SIMD    __ARM_FEATURE_FP16_VECTOR_ARITHMETIC
#   endif

#   ifndef __ARM_FP16_ARGS
#   define SPC_ARM_FP16_ARGS    (-1)
#   else
#   define SPC_ARM_FP16_ARGS    __ARM_FP16_ARGS
#   endif

#   ifndef __ARM_FP_FENV_ROUNDING
#   define SPC_ARM_FENV     (-1)
#   else
#   define SPC_ARM_FENV     __ARM_FP_FENV_ROUNDING
#   endif

#   ifndef __ARM_FEATURE_CLZ
#   define SPC_ARM_CLZ      (-1)
#   else
#   define SPC_ARM_CLZ      __ARM_FEATURE_CLZ
#   endif

#   ifndef __ARM_FEATURE_IDIV
#   define SPC_ARM_IDIV     (-1)
#   else
#   define SPC_ARM_IDIV     __ARM_FEATURE_IDIV
#   endif

#   ifndef __ARM_FEATURE_FMA
#   define SPC_ARM_FMA      (-1)
#   else
#   define SPC_ARM_FMA      __ARM_FEATURE_FMA
#   endif

#   ifndef __ARM_FEATURE_UNALIGNED_ACCESS
#   define SPC_ARM_UACC         (-1)
#   else
#   define SPC_ARM_UACC         __ARM_FEATURE_UNALIGNED_ACCESS
#   endif

#   ifndef __ARM_FEATURE_BTI_DEFAULT
#   define SPC_ARM_BTIDEF       (-1)
#   else
#   define SPC_ARM_BTIDEF       __ARM_FEATURE_BTI_DEFAULT
#   endif

#   ifndef __ARM_FEATURE_PAC_DEFAULT
#   define SPC_ARM_PACDEF       (-1)
#   else
#   define SPC_ARM_PACDEF       __ARM_FEATURE_PAC_DEFAULT
#   endif

#   ifndef __ARM_FEATURE_CRC32
#   define SPC_ARM_CRC32        (-1)
#   else
#   define  SPC_ARM_CRC32       __ARM_FEATURE_CRC32
#   endif

#   ifndef __ARM_FEATURE_AES
#   define SPC_ARM_AES          (-1)
#   else
#   define SPC_ARM_AES          __ARM_FEATURE_AES
#   endif

#   ifndef __ARM_FEATURE_SHA2
#   define SPC_ARM_SHA2         (-1)
#   else
#   define SPC_ARM_SHA2         __ARM_FEATURE_SHA2
#   endif

#   ifndef __ARM_FEATURE_SHA3
#   define SPC_ARM_SHA3         (-1)
#   else
#   define SPC_ARM_SHA3         __ARM_FEATURE_SHA3
#   endif

#   ifndef __ARM_FEATURE_SHA512
#   define SPC_ARM_SHA512       (-1)
#   else
#   define SPC_ARM_SHA512       __ARM_FEATURE_SHA512
#   endif

#   ifndef  __ARM_FEATURE_SM3
#   define SPC_ARM_SM3          (-1)
#   else
#   define SPC_ARM_SM3          __ARM_FEATURE_SM3
#   endif

#   ifndef  __ARM_FEATURE_SM4
#   define SPC_ARM_SM4          (-1)
#   else
#   define SPC_ARM_SM4          __ARM_FEATURE_SM4
#   endif

#   ifndef __ARM_FEATURE_DOTPROD
#   define SPC_ARM_DOTPROD          (-1)
#   else
#   define SPC_ARM_DOTPROD          __ARM_FEATURE_DOTPROD
#   endif

#   ifndef __ARM_FEATURE_COMPLEX
#   define SPC_ARM_COMPLEX       (-1)
#   else
#   define SPC_ARM_COMPLEX       __ARM_FEATURE_COMPLEX
#   endif

#   ifndef __ARM_FEATURE_JCVT
#   define SPC_ARM_JCVT       (-1)
#   else
#   define SPC_ARM_JCVT       __ARM_FEATURE_JCVT
#   endif

#   ifndef __ARM_FEATURE_RNG
#   define SPC_ARM_RNG       (-1)
#   else
#   define SPC_ARM_RNG       __ARM_FEATURE_RNG
#   endif

#   ifndef __ARM_FEATURE_TME
#   define SPC_ARM_TME       (-1)
#   else
#   define SPC_ARM_TME       __ARM_FEATURE_TME
#   endif

#   ifndef __ARM_FEATURE_MTE
#   define SPC_ARM_MTE       (-1)
#   else
#   define SPC_ARM_MTE       __ARM_FEATURE_MTE
#   endif

#   ifndef __ARM_FEATURE_FRINT
#   define SPC_ARM_FRINT       (-1)
#   else
#   define SPC_ARM_FRINT       __ARM_FEATURE_FRINT
#   endif

#   ifndef __ARM_64BIT_STATE
#   define SPC_ARM_A64          (-1)
#   else
#   define SPC_ARM_A64          __ARM_64BIT_STATE
#   endif

#   ifndef __ARM_FEATURE_MATMUL_INT8
#   define SPC_ARM_MATMULI8     (-1)
#   else
#   define SPC_ARM_MATMULI8     __ARM_FEATURE_MATMUL_INT8
#   endif

#   ifndef __ARM_FEATURE_DIRECTED_ROUNDING
#   define SPC_ARM_DR           (-1)
#   else
#   define SPC_ARM_DR           __ARM_FEATURE_DIRECTED_ROUNDING
#   endif

#   ifndef __ARM_FEATURE_FMA
#   define SPC_ARM_FMA          (-1)
#   else
#   define SPC_ARM_FMA          __ARM_FEATURE_FMA
#   endif

#   ifndef __ARM_FEATURE_NUMERIC_MAXMIN
#   define SPC_ARM_MAXMIN       (-1)
#   else
#   define SPC_ARM_MAXMIN       __ARM_FEATURE_NUMERIC_MAXMIN
#   endif

#   ifndef __ARM_FEATURE_LS64
#   define SPC_ARM_LS64         (-1)
#   else
#   define SPC_ARM_LS64         __ARM_FEATURE_LS64
#   endif

#   define SPC_ARM_V7   7
#   ifndef SPC_ARM_V8
#   define SPC_ARM_V8   2
#   endif

#   if   __ARM_ARCH >= 900
#       define SPC_ARM_V8   8
#       define SPC_ARM_V9   (__ARM_ARCH%100)
#   elif __ARM_ARCH >= 800
#       define SPC_ARM_V8   (__ARM_ARCH%100)
#       define SPC_ARM_V9   0
#   elif defined(SPC_ARM_V8)
#       define SPC_ARM_V9   0
#   else
#       error "if __ARM_ARCH < 800, SPC_ARM_V8 must be manually set"
#   endif

#   ifndef MY_ENDIAN
#   if  defined(__ARM_BIG_ENDIAN)
#       define MY_ENDIAN   ENDIAN_BIG
#   else
#       define MY_ENDIAN   ENDIAN_LIL
#   endif
#   endif

#elif defined(__riscv)

#   define MY_ISA   ISA_RV

#   if __BYTE_ORDER__  !=  __ORDER_BIG_ENDIAN__
#       define MY_ENDIAN   ENDIAN_LIL
#   else
#       define MY_ENDIAN   ENDIAN_BIG
#   endif

#   if  defined(__ILP32__)
#       define SPC_RV_I32
#   elif  defined(__LP64__)
#       define SPC_RV_I64
#       define MY_ISA       ISA_RV64
#   elif  (ULLONG_MAX>>63) > 18446744073709551615ull
#       define SPC_RV_I128
#   else
#       error "unknown risc-v ISA"
#   endif

#elif defined(__PPC64__)
#   define MY_ISA           ISA_PPC
#   define MY_PAGESZ        (4096)
#   if __BYTE_ORDER__  !=  __ORDER_BIG_ENDIAN__
#       define MY_ENDIAN   ENDIAN_LIL
#   else
#       define MY_ENDIAN   ENDIAN_BIG
#   endif

#elif defined(__PPC__)
#   define MY_ISA           ISA_PPC
#   define MY_PAGESZ        (4096)
#   if __BYTE_ORDER__  !=  __ORDER_BIG_ENDIAN__
#       define MY_ENDIAN   ENDIAN_LIL
#   else
#       define MY_ENDIAN   ENDIAN_BIG
#   endif

#elif defined(__mips__)
#   if defined(__MIPSEB__)
#       define MY_ENDIAN   ENDIAN_BIG
#   elif defined(__MIPSEL__)
#       define MY_ENDIAN   ENDIAN_LIL
#   endif

#   if   __PTRDIFF_WIDTH__ == 32
#       define MY_ISA       ISA_MIPS
#   elif __PTRDIFF_WIDTH__ == 64
#       define MY_ISA       ISA_MIPS
#   else
#       error "__mips__ defined but can't detect sizeof(void *)"
#   endif

#else
#   error "unable to detect target architecture"
#endif


#ifndef MY_PAGESZ
#define MY_PAGESZ    (4096)
#endif

#if MY_ISA == ISA_X86

/*  GCC: 'mavx512fp16'; 'march=graniterapids-d' || NULL */
#   if defined(__AVX512FP16__)
#       ifndef  SPC_X86_AVX512FP16
#       define  SPC_X86_AVX512FP16
#       endif
#   endif

/*  GCC: 'mavx512vl'; 'march=cannonlake' || 'march=znver4' */

/*  GCC:    'mavx512f'; 'cannonlake' :: 'znver4'
    MSVC:   'arch:AVX512'
*/

/*  GCC:    'mavx2' :: 'haswell' :: 'bdver2'
    MSVC:   'arch:AVX2'
*/

/*  GCC: 'mavx' :: 'sandybridge' 'bdver1'
    MSVC:   'arch:AVX'
*/

/*  GCC: 'msse4.2' :: 'nehalem' :: 'bdver1'
*/

/*  GCC: 'msse4.1' :: 'nehalem' :: 'bdver1'
*/

/*  GCC: 'mssse3' 'march=core2' || 'march=bdver1'
*/

/*  GCC: 'msse3'; 'march=prescott' || 'march=barcelona'
*/

/*  GCC:    'msse2'; 'march=pentium4' || 'march=k8'
    MSVC:'arch:SSE2' (ia32 only)
*/

/*  GCC:    'msse'; 'march=pentium3' || 'march=athlon-xp'
    MSVC:   'arch:SSE' (ia32 only)
*/

/*  GCC: 'mmx'; 'march=pentium3' || 'march=athlon-xp'
*/

#       if defined(__AVX512FP16__)
#           ifndef  SPC_X86_AVX512FP16
#           define  SPC_X86_AVX512FP16
#           endif
#       endif

#       if defined(__AVX512BF16__) || defined(SPC_X86_FP16)
#           ifndef  SPC_X86_AVX512BF16
#           define  SPC_X86_AVX512BF16
#           endif
#       endif

#       if defined(__AVX512VPOPCNTDQ__) || defined(SPC_X86_BF16)
#           ifndef  SPC_X86_AVX512VPOPCNTDQ
#           define  SPC_X86_AVX512VPOPCNTDQ
#           endif
#       endif

#       if defined(__AVX512BITALG__) || defined(SPC_X86_VPOPCNTDQ)
#           ifndef  SPC_X86_AVX512BITALG
#           define  SPC_X86_AVX512BITALG
#           endif
#       endif

#       if defined(__GFNI__) || defined(SPC_X86_AVX512BITALG)
#           ifndef  SPC_X86_AVX512GFNI
#           define  SPC_X86_AVX512GFNI
#           endif
#       endif

#       if defined(__AVX512VNNI__) || defined(SPC_X86_AVX512BITALG)
#           ifndef  SPC_X86_AVX512VNNI
#           define  SPC_X86_AVX512VNNI
#           endif
#       endif

#       if defined(__AVX512VBMI2__) || defined(SPC_X86_AVX512VNNI)
#           ifndef  SPC_X86_AVX512VBMI2
#           define  SPC_X86_AVX512VBMI2
#           endif
#       endif

#       if defined(__AVX512VBMI__) || defined(SPC_X86_AVX512VBMI2)
#           ifndef  SPC_X86_AVX512VBMI
#           define  SPC_X86_AVX512VBMI
#           endif
#       endif

#       if defined(__AVX512IFMA__) || defined(SPC_X86_AVX512VBMI)
#           ifndef  SPC_X86_AVX512IFMA
#           define  SPC_X86_AVX512IFMA
#           endif
#       endif

#       if defined(__AVX512VL__) || defined(SPC_X86_AVX512IFMA)
#           ifndef  SPC_X86_AVX512VL
#           define  SPC_X86_AVX512VL
#           endif
#       endif

#       if defined(__AVX512CD__) || defined(SPC_X86_AVX512VL)
#           ifndef  SPC_X86_AVX512CD
#           define  SPC_X86_AVX512CD
#           endif
#       endif

#       if defined(__AVX512BW__) || defined(SPC_X86_AVX512VL)
#           ifndef  SPC_X86_AVX512BW
#           define  SPC_X86_AVX512BW
#           endif
#       endif

#       if defined(__AVX512DQ__) || defined(SPC_X86_AVX512VL)
#           ifndef  SPC_X86_AVX512DQ
#           define  SPC_X86_AVX512DQ
#           endif
#       endif

#       if defined(__AVX512F__) || defined(SPC_X86_AVX512VL)
#           ifndef  SPC_X86_AVX512F
#           define  SPC_X86_AVX512F
#           endif
#       endif

#       if defined(__AVX2__) || defined(SPC_X86_AVX512F)
#           ifndef  SPC_X86_AVX2
#           define  SPC_X86_AVX2
#           endif
#       endif

#       if defined(__AVX__) || defined(SPC_X86_AVX2)
#           ifndef  SPC_X86_AVX
#           define  SPC_X86_AVX
#           endif
#       endif

#       if defined(__SSE4_2__) || defined(SPC_X86_AVX)
#           ifndef  SPC_X86_SSE42
#           define  SPC_X86_SSE42
#           endif
#       endif

#       if defined(__SSE4_1__) || defined(SPC_X86_SSE42)
#           ifndef  SPC_X86_SSE41
#           define  SPC_X86_SSE41
#           endif
#       endif

#       if defined(__SSSE3__) || defined(SPC_X86_SSE41)
#           ifndef  SPC_X86_SSSE3
#           define  SPC_X86_SSSE3
#           endif
#       endif

#       if defined(__SSE3__) || defined(SPC_X86_SSSE3)
#           ifndef  SPC_X86_SSE3
#           define  SPC_X86_SSE3
#           endif
#       endif

#       if defined(__SSE2__) || defined(SPC_X86_SSE3)
#           ifndef  SPC_X86_SSE2
#           define  SPC_X86_SSE2
#           endif
#       endif

#       if defined(__SSE__) || defined(SPC_X86_SSE2)
#           ifndef  SPC_X86_SSE
#           define  SPC_X86_SSE
#           endif
#       endif

#       if defined(__MMX__) || defined(SPC_X86_SSE)
#           ifndef  SPC_X86_MMX
#           define  SPC_X86_MMX
#           endif
#       endif


#elif MY_ISA == ISA_ARM

#   ifndef MY_ARM_ACLE_H
#   define MY_ARM_ACLE_H
#   include  <arm_acle.h>
#   endif

#endif // MY_ISA == X86


/*  Preprocessor symbol concatenation

    The last argument is inserted between each of the
    arguments preceding it.

    CONCAT1(a, .)           => a.
    CONCAT2(a, b, _)        => a_b
    CONCAT3(a, b, c, .)     => a.b.c
*/

#define CONCAT1(_0,         ...)    _0##__VA_ARGS__
#define CONCAT2(_0,_1,      ...)    _0##__VA_ARGS__##_1
#define CONCAT3(_0,_1,_2,   ...)    _0##__VA_ARGS__##_1##__VA_ARGS__##_2

#ifndef MY_CONCAT1
#define MY_CONCAT1(_0,      ...)    _0##__VA_ARGS__
#define MY_CONCAT2(_0,_1,   ...)    _0##__VA_ARGS__##_1
#define MY_CONCAT3(_0,_1,_2,...)    _0##__VA_ARGS__##_1##__VA_ARGS__##_2
#endif

/*  Stringification

    The suffix indicates the number of rounds of expansion
    to apply.

    E.g.:

    ```
    #   define  CHAR_MAX 255
    #   define UCHAR_MAX CHAR_MAX
    #   define UINT8_MAX UCHAR_MAX

    #   define MAXOF1(M) #M
    #   define MAXOFS(T, N) MAXOF1(EXPAND##N(T ## _MAX))
    char const maxof[] = MAXOF2(UINT8);
    ```

    `STRIZE0(UINT8_MAX)` expands to `"UINT8_MAX"`

    `STRIZE1(UINT8_MAX)` expands to `"UCHAR_MAX"`

    `STRIZE2(UINT8_MAX)` expands to `"CHAR_MAX"`

    `STRIZE3(UINT8_MAX)` expands to `"255"`

*/


#ifndef MY_STRIFY
#define MY_STRIFY(prefix, string) prefix ## string
#define MY_LCSIFY(...) MY_STRIFY(L, #__VA_ARGS__)
#define MY_UCSIFY(...) MY_STRIFY(u, #__VA_ARGS__)
#define MY_WCSIZE(...) MY_STRIFY(U, #__VA_ARGS__)
#endif

#ifndef MY_C32IZE0
#define MY_C16IZE0(...) MY_WCSIZE( u, #__VA_ARGS__)
#define MY_C16IZE1(...) MY_C16IZE0(__VA_ARGS__)
#define MY_C16IZE2(...) MY_C16IZE1(__VA_ARGS__)
#define MY_C16IZE3(...) MY_C16IZE2(__VA_ARGS__)
#define MY_C16IZE4(...) MY_C16IZE3(__VA_ARGS__)
#define MY_C16IZE5(...) MY_C16IZE4(__VA_ARGS__)
#define MY_C16IZE6(...) MY_C16IZE5(__VA_ARGS__)
#define MY_C16IZE7(...) MY_C16IZE6(__VA_ARGS__)
#define MY_C16IZE8(...) MY_C16IZE7(__VA_ARGS__)
#endif

#ifndef MY_C32IZE0
#define MY_C32IZE0(...) MY_WCSIZE( U, #__VA_ARGS__)
#define MY_C32IZE1(...) MY_C32IZE0(__VA_ARGS__)
#define MY_C32IZE2(...) MY_C32IZE1(__VA_ARGS__)
#define MY_C32IZE3(...) MY_C32IZE2(__VA_ARGS__)
#define MY_C32IZE4(...) MY_C32IZE3(__VA_ARGS__)
#define MY_C32IZE5(...) MY_C32IZE4(__VA_ARGS__)
#define MY_C32IZE6(...) MY_C32IZE5(__VA_ARGS__)
#define MY_C32IZE7(...) MY_C32IZE6(__VA_ARGS__)
#define MY_C32IZE8(...) MY_C32IZE7(__VA_ARGS__)
#endif

#ifndef MY_STRIZE0
#define MY_STRIZE0(...)           #__VA_ARGS__
#define MY_STRIZE1(...) MY_STRIZE0(__VA_ARGS__)
#define MY_STRIZE2(...) MY_STRIZE1(__VA_ARGS__)
#define MY_STRIZE3(...) MY_STRIZE2(__VA_ARGS__)
#define MY_STRIZE4(...) MY_STRIZE3(__VA_ARGS__)
#define MY_STRIZE5(...) MY_STRIZE4(__VA_ARGS__)
#define MY_STRIZE6(...) MY_STRIZE5(__VA_ARGS__)
#define MY_STRIZE7(...) MY_STRIZE6(__VA_ARGS__)
#define MY_STRIZE8(...) MY_STRIZE7(__VA_ARGS__)
#endif

#define STRIZE0(...)           #__VA_ARGS__
#define STRIZE1(...) MY_STRIZE0(__VA_ARGS__)
#define STRIZE2(...) MY_STRIZE1(__VA_ARGS__)
#define STRIZE3(...) MY_STRIZE2(__VA_ARGS__)
#define STRIZE4(...) MY_STRIZE3(__VA_ARGS__)
#define STRIZE5(...) MY_STRIZE4(__VA_ARGS__)
#define STRIZE6(...) MY_STRIZE5(__VA_ARGS__)
#define STRIZE7(...) MY_STRIZE6(__VA_ARGS__)
#define STRIZE8(...) MY_STRIZE7(__VA_ARGS__)


/*  Force repeated preprocessor expansions

    Identical to the `STRIZE` macros except the strize
    operator is not implicitly used
*/
#ifndef MY_EXPAND8
#define MY_EXPAND8(...) MY_EXPAND7(__VA_ARGS__)
#define MY_EXPAND7(...) MY_EXPAND6(__VA_ARGS__)
#define MY_EXPAND6(...) MY_EXPAND5(__VA_ARGS__)
#define MY_EXPAND5(...) MY_EXPAND4(__VA_ARGS__)
#define MY_EXPAND4(...) MY_EXPAND3(__VA_ARGS__)
#define MY_EXPAND3(...) MY_EXPAND2(__VA_ARGS__)
#define MY_EXPAND2(...) MY_EXPAND1(__VA_ARGS__)
#define MY_EXPAND1(...)            __VA_ARGS__
#endif

#define EXPAND8(...)    MY_EXPAND7(__VA_ARGS__)
#define EXPAND7(...)    MY_EXPAND6(__VA_ARGS__)
#define EXPAND6(...)    MY_EXPAND5(__VA_ARGS__)
#define EXPAND5(...)    MY_EXPAND4(__VA_ARGS__)
#define EXPAND4(...)    MY_EXPAND3(__VA_ARGS__)
#define EXPAND3(...)    MY_EXPAND2(__VA_ARGS__)
#define EXPAND2(...)    MY_EXPAND1(__VA_ARGS__)
#define EXPAND1(...)               __VA_ARGS__


#undef  SAFECALL
#undef  MY_CALL
#undef  MY_SWAP

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

#undef      uchar
typedef             unsigned char uchar;
//#define     uchar   unsigned char

#undef      schar
typedef             signed char schar;
//#define     schar   signed char

#undef      ushort
#undef      ushrt
typedef             unsigned short ushort, ushrt;
//#define     ushort  unsigned short
//#define     ushrt   unsigned short

#undef      shrt
typedef             short shrt;
//#define     shrt    short

#undef      uint
typedef             unsigned int uint;
//#define     uint    unsigned int

#undef      ulong
typedef             unsigned long ulong;
//#define     ulong   unsigned long

#undef      ullong
typedef             unsigned long long ullong;
//#define     ullong  unsigned long long

#undef      llong
typedef             long long llong;
//#define     llong   long long
typedef unsigned short ndig_t;
#define NDIG_MAX (65535)
#define NDIG_MIN (0)
#define NDIG_C(C) (C)

#define     MY_CALL1(F, ...)    F(__VA_ARGS__)
#define     MY_CALL2(F, ...)    MY_CALL1(F, __VA_ARGS__)
#define     MY_CALL3(F, ...)    MY_CALL2(F, __VA_ARGS__)
#define     MY_CALL4(F, ...)    MY_CALL3(F, __VA_ARGS__)

#endif // eof
