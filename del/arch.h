/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#ifndef UNSYS_ARCH_H
#define UNSYS_ARCH_H

#include <stdint.h>
#include <limits.h>

#define ISA_P32 1
#define ISA_P64 2
//                                          ELF e_machine
#define ISA_X86_32 ((1<<ISA_P_SHIFT)|ISA_P32) // EM_386
#define ISA_X86_64 ((2<<ISA_P_SHIFT)|ISA_P64) // EM_X86_64
#define ISA_ARM_32 ((3<<ISA_P_SHIFT)|ISA_P32) // EM_ARM
#define ISA_ARM_64 ((4<<ISA_P_SHIFT)|ISA_P64) // EM_AARCH64
#if  (defined(__i386__)||defined(_M_IX86))
#   define HOST_ISA     ISA_X86_32 
#elif (defined(__x86_64__) || defined(_M_IX64))
#   define HOST_ISA     ISA_X86_64
#elif (defined(__aarch64__) || defined(__arm64__) || defined(_M_ARM64))
#   define HOST_ISA     ISA_ARM_64
#elif (defined(__arm__) || defined(_M_ARM))
#   define HOST_ISA     ISA_ARM_32
#else
#   error "unable to determine the host instruction set architecture"
#endif

/*

HOST_SIGN   (INT32_MIN)             (INT64_MIN)
HOST_EXPO   (INT32_C(0xff) << 23)   (INT64_C(0x7ff) <<52 )
HOST_MANT   (INT32_MAX     >>  8)   (INT64_MAX      >>11 )
HOST_SNAN   (INT32_MAX     >>  9)   (INT64_MAX      >>12 ) 
HOST_QNAN   (INT32_C(0x1)  << 22)   (INT64_C(0x1)   <<51 )

+0.f = 0
-0.f = *(fltn_t *) &(intn_t){HOST_SIGN}
+INF = *(fltn_t *) &(intn_t){HOST_EXPO}
-INF = *(fltn_t *) &(intn_t){HOST_EXPO|HOST_SIGN}
qNAN = *(fltn_t *) &(intn_t){HOST_EXPO|HOST_QNAN}
sNAN = *(fltn_t *) &(intn_t){HOST_EXPO|HOST_SNAN}

DBL_MAX = (2046<<52)|mant 

*/

#define HOST_SIGNF (INT32_MIN)
#define HOST_MANTF (INT32_MAX>>8)
#define HOST_SNANF (INT32_MAX>>9)
#define HOST_EXPOF (INT32_C(0xff)<<23)
#define HOST_QNANF (INT32_C(0x01)<<22)

#define HOST_SIGN (INT64_MIN)
#define HOST_MANT (INT64_MAX>>11)
#define HOST_SNAN (INT64_MAX>>12)
#define HOST_EXPO (INT64_C(0x7ff)<<52)
#define HOST_QNAN (INT64_C(0x001)<<51)

#define HOST_PINF (HOST_EXPO)
#define HOST_NINF (HOST_EXPO|HOST_SIGN)

#define mksnan(i) ((i)<0 ? (HOST_NINF|(0-(i))) : (HOST_PINF|(i)))

#define  BOOL_C(x) (!!x)
#define  BYTE_C(x) (x)
#define HWORD_C(x) (x)
#define SWORD_C(x) WORD_C(x)

#define  BYTE_MAX    BYTE_C(0x000000ff)
#define HWORD_MAX   HWORD_C(0x0000ffff)
#define  WORD_MAX    WORD_C(0xffffffff)
#define DWORD_MAX   DWORD_C(0xffffffffffffffff)
#define SWORD_MAX    WORD_MAX

#define  BYTE_WIDTH 8
#define HWORD_WIDTH ( BYTE_WIDTH*2)
#define  WORD_WIDTH (HWORD_WIDTH*2)
#define DWORD_WIDTH ( WORD_WIDTH*2)
#define QWORD_WIDTH (DWORD_WIDTH*2)

typedef unsigned char   byte_t;
typedef unsigned short hword_t;

#if LONG_MAX == INT_MAX
    typedef unsigned long       word_t;
    typedef unsigned long long  dword_t;
#   define HOST_L32 1
#   define HOST_L64 0
#   define  WORD_C(x) (x##UL)
#   define DWORD_C(x) (x##ULL)
#else
    typedef unsigned int    word_t;
    typedef unsigned long  dword_t;
#   define HOST_L32 0
#   define HOST_L64 1
#   define  WORD_C(x) x##U
#   define DWORD_C(x) x##UL
#endif

#if (INTPTR_MAX == INT64_MAX) || defined(__LP64__) || defined(_WIN64)
#   define HOST_P64 1
#   define HOST_P32 0



#else
#   define HOST_P64 0
#   define HOST_P32 1

#endif

#if HOST_L32
#   if HOST_P64
#       ifndef INTPTR_C
#       define INTPTR_C(x)  x##LL
#       endif
#       ifndef UINTPTR_C
#       define UINTPTR_C(x) x##ULL
#       endif
#       ifndef PTRDIFF_C
#       define PTRDIFF_C(x) x##LL 
#       endif
#       ifndef SIZE_C
#       define SIZE_C(x)    x#ULL
#       endif
#   else
#       ifndef INTPTR_C
#       define INTPTR_C(x)  x##L
#       endif
#       ifndef UINTPTR_C
#       define UINTPTR_C(x) x##UL
#       endif
#       ifndef PTRDIFF_C
#       define PTRDIFF_C(x) x##L
#       endif
#       ifndef SIZE_C
#       define SIZE_C(x)    x#UL
#       endif
#   endif
#else // sizeof(long) == 8
#   if HOST_P64
#       ifndef INTPTR_C
#       define INTPTR_C(x)  x##L
#       endif
#       ifndef UINTPTR_C
#       define UINTPTR_C(x) x##UL
#       endif
#       ifndef PTRDIFF_C
#       define PTRDIFF_C(x) x##L
#       endif
#       ifndef SIZE_C
#       define SIZE_C(x)    x##UL
#       endif
#   else
#       ifndef INTPTR_C
#       define INTPTR_C(x)  x
#       endif
#       ifndef UINTPTR_C
#       define UINTPTR_C(x) x##U
#       endif
#       ifndef PTRDIFF_C
#       define PTRDIFF_C(x) x
#       endif
#       ifndef SIZE_C
#       define SIZE_C(x)    x#U
#       endif
#   endif
#endif // HOST_L32

#if defined(__SIZEOF_INT128__)
    typedef unsigned __int128 qword_t; // i.e. 4 × 32 bit words
#else
    typedef struct {
        word_t v[4];
    } qword_t;
#endif

#endif // !defined(UNSYS_ARCH_H)

