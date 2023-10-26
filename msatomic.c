/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#include <limits.h>
#include <stddef.h>
#include <stdint.h>

#ifndef UNREACHABLE
#define UNREACHABLE() __assume(0)
#endif

#ifndef INLINE
#define INLINE(t, f) t inline f
#endif

#ifndef PUBLIC
#define PUBLIC(t, f) t f
#endif

#define     ATOMIC_FLAG_INIT            {0}
#define     ATOMIC_BOOL_LOCK_FREE       (2)
#define     ATOMIC_CHAR_LOCK_FREE       (2)
#define     ATOMIC_CHAR16_T_LOCK_FREE   (2)
#define     ATOMIC_CHAR32_T_LOCK_FREE   (2)
#define     ATOMIC_WCHAR_T_LOCK_FREE    (2)
#define     ATOMIC_SHORT_LOCK_FREE      (2)
#define     ATOMIC_INT_LOCK_FREE        (2)
#define     ATOMIC_LONG_LOCK_FREE       (2)
#define     ATOMIC_LLONG_LOCK_FREE      (2)
#define     ATOMIC_POINTER_LOCK_FREE    (2)

typedef enum memory_order {
    memory_order_relaxed,
    memory_order_consume,
    memory_order_acquire,
    memory_order_release,
    memory_order_acq_rel,
    memory_order_seq_cst
} memory_order;

typedef long my_atomic_flag;

typedef struct {my_atomic_flag Self;} atomic_flag;

INLINE(memory_order, my_cas_check)
(
    memory_order succ,
    memory_order fail
)
{
    switch (fail)
    {
        case memory_order_relaxed:
        case memory_order_consume:
        case memory_order_acquire:
        case memory_order_seq_cst:
        {
            if (fail > succ) break;
            if (succ > memory_order_seq_cst) break;
            return succ;
        }
    }
    UNREACHABLE();
    return -1;
}

#define     MY_ILOCKED2(  ...)  __VA_ARGS__
#define     MY_ILOCKED1(F,...)  MY_ILOCKED2(F(__VA_ARGS__))
#define     MY_ILOCKED(F, ...)  MY_ILOCKED1(_Interlocked##F,__VA_ARGS__)

#if defined(_M_ARM) || defined(_M_ARM64)
#   define  MY_RELAXED(F, ...)  MY_ILOCKED(F## _nf,__VA_ARGS__)
#   define  MY_ACQUIRE(F, ...)  MY_ILOCKED(F##_acq,__VA_ARGS__)
#   define  MY_RELEASE(F, ...)  MY_ILOCKED(F##_rel,__VA_ARGS__)
#   define  MY_SEQ_CST(F, ...)  MY_ILOCKED(      F,__VA_ARGS__)
#else
#   define  MY_RELAXED(F, ...)  MY_ILOCKED(F,__VA_ARGS__)
#   define  MY_ACQUIRE(F, ...)  MY_ILOCKED(F,__VA_ARGS__)
#   define  MY_RELEASE(F, ...)  MY_ILOCKED(F,__VA_ARGS__)
#   define  MY_SEQ_CST(F, ...)  MY_ILOCKED(F,__VA_ARGS__)
#endif


PUBLIC(void, cmba) () {_ReadWriteBarrier();}

PUBLIC(void, cmbe) () {_ReadWriteBarrier();}

PUBLIC(void, cmbt) () {_ReadWriteBarrier();}


PUBLIC(void, hmba) ()
{
#if     defined(_M_ARM)
    __dmb(_ARM_BARRIER_ISHLD);
#elif   defined(_M_ARM64)
    __dmb(_ARM64_BARRIER_ISHLD);
#else
    _ReadWriteBarrier();
#endif
}

PUBLIC(void, hmbe) ()
{
#if     defined(_M_ARM)
    __dmb(_ARM_BARRIER_ISHST);
#elif   defined(_M_ARM64)
    __dmb(_ARM64_BARRIER_ISHST);
#else
    _ReadWriteBarrier();
#endif
}

PUBLIC(void, hmbt) ()
{
#if     defined(_M_ARM)
    __dmb(_ARM_BARRIER_ISHST);
#elif   defined(_M_ARM64)
    __dmb(_ARM64_BARRIER_ISHST);
#else
    static long t[1];
    _ReadWriteBarrier();
    (void) _InterlockedExchange(t, 0);
    _ReadWriteBarrier();
#endif
}


PUBLIC(void, smba) ()
{
#if defined(_M_ARM)
    __dsb(_ARM_BARRIER_ISHLD);
#elif defined(_M_ARM64)
    __dsb(_ARM64_BARRIER_ISHLD);
#else
    _mm_lfence();
#endif
}

PUBLIC(void, smbr) ()
{
#if defined(_M_ARM)
    __dsb(_ARM_BARRIER_ISHST);
#elif defined(_M_ARM64)
    __dsb(_ARM64_BARRIER_ISHST);
#else
    _mm_sfence();
#endif
}

PUBLIC(void, smbt) ()
{
#if defined(_M_ARM)
    __dsb(_ARM_BARRIER_ISH);
#elif defined(_M_ARM64)
    __dsb(_ARM64_BARRIER_ISH);
#else
    _mm_mfence();
#endif
}



#if _ENTER_MSVC_LDR1
{
#endif

INLINE(unsigned char,       ABU_LDR1)
(
    unsigned char volatile const src[1]
)
{
    unsigned char ret;
#if defined(_M_ARM)
    ret = __iso_volatile_load8((char volatile *) src);
#elif defined(_M_ARM64)
    ret = __iso_volatile_load8((char volatile *) src);
#elif defined(_M_X64)
    ret = *src;
#else defined(_M_X64)
    ret = *src;
#endif
    return ret;
}

INLINE(unsigned short,      AHU_LDR1)
(
    unsigned short volatile const src[1]
)
{
    unsigned short ret;
#if defined(_M_ARM)
    ret = __iso_volatile_load16((short volatile *) src);
#elif defined(_M_ARM64)
    ret = __iso_volatile_load16((short volatile *) src);
#elif defined(_M_X64)
    ret = *src;
#endif
    return ret;
}

INLINE(unsigned int,        AWU_LDR1)
(
    unsigned int volatile const src[1]
)
{
    unsigned int ret;
#if defined(_M_ARM)
    ret = __iso_volatile_load32((int volatile *) src);
#elif defined(_M_ARM64)
    ret = __iso_volatile_load32((int volatile *) src);
#elif defined(_M_X64)
    ret = *src;
#else
    ret = *src;
#endif
    return ret;
}

INLINE(unsigned long long,  ADU_LDR1)
(
    unsigned long long volatile src[1]
)
{
    unsigned long long ret;
#if     defined(_M_ARM)
    ret = __ldrexd((long long volatile *) src);
#elif   defined(_M_ARM64)
    ret = __iso_volatile_load64((long long volatile *) src);
#elif   defined(_M_X64)
    ret = *src;
#else
    ret = _InterlockedOr64((long long volatile *) src, 0);
#endif
    return ret;
}

#if _LEAVE_MSVC_LDR1
}
#endif


#if _ENTER_MSVC_LDRA
{
#endif

INLINE(unsigned char,       ABU_LDRA)
(
    unsigned char volatile const src[1]
)
{
    unsigned char ret;
#if defined(_M_ARM)
    ret = __iso_volatile_load8((char volatile *) src);
    __dmb(_ARM_BARRIER_ISH);
#elif defined(_M_ARM64)
    ret = __iso_volatile_load8((char volatile *) src);
    __dmb(_ARM64_BARRIER_ISH);
#elif defined(_M_X64)
    ret = *src;
    _ReadWriteBarrier();
#else
    ret = *src;
    _ReadWriteBarrier();
#endif
    return ret;
}

INLINE(unsigned short,      AHU_LDRA)
(
    unsigned short volatile const src[1]
)
{
    unsigned short ret;
#if defined(_M_ARM)
    ret = __iso_volatile_load16((short volatile *) src);
    __dmb(_ARM_BARRIER_ISH);
#elif defined(_M_ARM64)
    ret = __iso_volatile_load16((short volatile *) src);
    __dmb(_ARM64_BARRIER_ISH);
#elif defined(_M_X64)
    ret = *src;
    _ReadWriteBarrier();
#else
    ret = *src;
    _ReadWriteBarrier();
#endif
    return ret;
}

INLINE(unsigned int,        AWU_LDRA)
(
    unsigned int volatile const src[1]
)
{
    unsigned int ret;
#if defined(_M_ARM)
    ret = __iso_volatile_load32((int volatile *) src);
    __dmb(_ARM_BARRIER_ISH);
#elif defined(_M_ARM64)
    ret = __iso_volatile_load32((int volatile *) src);
    __dmb(_ARM64_BARRIER_ISH);
#elif defined(_M_X64)
    ret = *src;
    _ReadWriteBarrier();
#else
    ret = *src;
    _ReadWriteBarrier();
#endif
    return ret;
}

INLINE(unsigned long long,  ADU_LDRA)
(
    unsigned long long volatile src[1]
)
{
    unsigned long long ret;
#if defined(_M_ARM)
    ret = __ldrexd((long long volatile *) src);
    __dmb(_ARM_BARRIER_ISH);
#elif defined(_M_ARM64)
    ret = __iso_volatile_load64((long long volatile *) src);
    __dmb(_ARM64_BARRIER_ISH);
#elif defined(_M_X64)
    ret = *src;
    _ReadWriteBarrier();
#else
    ret = _InterlockedOr64((long long volatile *) src, 0);
#endif
    return ret;
}

#if _LEAVE_MSVC_LDRA
}
#endif

#if _ENTER_MSVC_LDRT
{
#endif


INLINE(unsigned char,       ABU_LDRT)
(

    unsigned char volatile const src[1]
)
{
    unsigned char  ret;
#if defined(_M_ARM) 
    ret = __iso_volatile_load8((char volatile *) src);
    __dmb(_ARM_BARRIER_ISH);
#elif defined(_M_ARM64)
    ret = __iso_volatile_load8((char volatile *) src);
    __dmb(_ARM64_BARRIER_ISH);
#elif defined(_M_X64)
    ret = *src;
    _ReadWriteBarrier();
#else
    ret = *src;
    _ReadWriteBarrier();
#endif
    return ret;
}

INLINE(unsigned short,      AHU_LDRT)
(
    unsigned short volatile const src[1]
)
{
    unsigned short ret;
#if defined(_M_ARM) 
    ret = __iso_volatile_load16((short volatile *) src);
    __dmb(_ARM_BARRIER_ISH);
#elif defined(_M_ARM64)
    ret = __iso_volatile_load16((char volatile *) src);
    __dmb(_ARM64_BARRIER_ISH);
#elif defined(_M_X64)
    ret = *src;
    _ReadWriteBarrier();
#else
    ret = *src;
    _ReadWriteBarrier();
#endif
    return ret;
}

INLINE(unsigned int,        AWU_LDRT)
(
    unsigned int volatile const src[1]
)
{
    unsigned int ret;
#if defined(_M_ARM) 
    ret = __iso_volatile_load32((int volatile *) src);
    __dmb(_ARM_BARRIER_ISH);
#elif defined(_M_ARM64)
    ret = __iso_volatile_load32((int volatile *) src);
    __dmb(_ARM64_BARRIER_ISH);
#elif defined(_M_X64)
    ret = *src;
    _ReadWriteBarrier();
#else
    ret = *src;
    _ReadWriteBarrier();
#endif
    return ret;
}

INLINE(unsigned long long,  ADU_LDRT)
(
    unsigned long long volatile src[1]
)
{
    unsigned long long ret;
#if defined(_M_ARM)
    ret = __ldrexd((long long volatile *) src);
    __dmb(_ARM_BARRIER_ISH);
#elif defined(_M_ARM64)
    ret = __iso_volatile_load64((long long volatile *) src);
    __dmb(_ARM64_BARRIER_ISH);
#elif defined(_M_X64)
    ret = *src;
    _ReadWriteBarrier();
#else
    ret = _InterlockedOr64((long long volatile *) src, 0);
#endif
    return ret;
}

INLINE(signed char,         ABI_LDRT) (void volatile *src)
{
    return  ABU_LDRT((unsigned char volatile *) src);
}

INLINE(short,               AHI_LDRT) (short volatile src[1])
{
    return  AHU_LDRT((unsigned short volatile *) src);
}

INLINE(int,                 AWI_LDRT) (int volatile src[1])
{
    return  AWU_LDRT((unsigned int volatile *) src);
}

INLINE(long long,           ADI_LDRT) (long long volatile src[1])
{
    return  ADU_LDRT((unsigned long long volatile *) src);
}

#if _LEAVE_MSVC_LDRT

}

#endif

INLINE(unsigned char, UCHAR_STR1)
(
    unsigned char           src,
    unsigned char volatile  dst[1]
)
{
#if defined(_M_ARM) || defined(_M_ARM64)
    __iso_volatile_store8((char volatile *) dst, src);
#else
    *dst = src;
#endif
    return src;
}

INLINE(unsigned short, USHRT_STR1)
(
    unsigned short          src,
    unsigned short volatile dst[1]
)
{
#if defined(_M_ARM) || defined(_M_ARM64)
    __iso_volatile_store16((short volatile *) dst, src);
#else
    *dst = src;
#endif
    return src;
}

INLINE(unsigned int, UINT_STR1)
(
    unsigned int          src,
    unsigned int volatile dst[1]
)
{
#if defined(_M_ARM) || defined(_M_ARM64)
    __iso_volatile_store32((int volatile *) dst, src);
#else
    *dst = src;
#endif
    return src;
}

INLINE(unsigned long, ULONG_STR1)
(
    unsigned long          src,
    unsigned long volatile dst[1]
)
{
#if defined(_M_ARM) || defined(_M_ARM64)
    __iso_volatile_store32((int volatile *) dst, src);
#else
    *dst = src;
#endif
    return src;
}

INLINE(unsigned long long, ULLONG_STR1)
(
    unsigned long long          src,
    unsigned long long volatile dst[1]
)
{
#if defined(_M_ARM64)
    __iso_volatile_store64((long long volatile  *) dst, src);
#elif defined(_M_X64)
    *dst = src;
#else
    MY_RELAXED(Exchange64, ((long long volatile *) dst), src);
#endif
    return src;
}

INLINE(unsigned char, UCHAR_STRE)
(
    unsigned char           src,
    unsigned char volatile  dst[1]
)
{
#if defined(_M_ARM64)
    __dmb(_ARM64_BARRIER_ISH);
    __iso_volatile_store8((char volatile *) dst, src);
#elif defined(_M_ARM)
    __dmb(_ARM_BARRIER_ISH);
    __iso_volatile_store8((char volatile *) dst, src);
#else
    _ReadWriteBarrier();
    *dst = src;
#endif
    return src;
}


INLINE(unsigned long long, ULLONG_STRE)

(
    unsigned long long          src,
    unsigned long long volatile dst[1]
)
{
#if defined(_M_ARM64)
    __dmb(_ARM64_BARRIER_ISH);
    __iso_volatile_store64((long long volatile *) dst, src);
#elif defined(_M_X64)
    _ReadWriteBarrier();
    *dst = val;
#else
    MY_RELEASE(Exchange64, ((long long volatile *) dst), src);
#endif
    return src;
}


INLINE(unsigned char, UCHAR_STRT)
(
    unsigned char           src,
    unsigned char volatile  dst[1]
)
{
#if defined(_M_ARM64)
    __dmb(_ARM64_BARRIER_ISH);
    __iso_volatile_store8((char volatile *) dst, src);
    __dmb(_ARM64_BARRIER_ISH);
#elif defined(_M_ARM)
    __dmb(_ARM_BARRIER_ISH);
    __iso_volatile_store8((char volatile *) dst, src);
    __dmb(_ARM_BARRIER_ISH);
#else
    MY_SEQ_CST(Exchange8, ((char volatile *) dst), src);
#endif
    return src;
}

INLINE(unsigned long long, ULLONG_STRT)
(
    unsigned long long          src,
    unsigned long long volatile dst[1]
)
{
#if defined(_M_ARM64)
    __dmb(_ARM64_BARRIER_ISH);
    __iso_volatile_store64((long long volatile *) dst, src);
    __dmb(_ARM64_BARRIER_ISH);
#else
    MY_SEQ_CST(Exchange64, ((long long volatile *) dst), src);
#endif
    return src;
}



INLINE(unsigned char, UCHAR_SWP1)
(
    unsigned char           a,
    unsigned char volatile  b[1]
)
{
    return  MY_RELAXED(Exchange8, ((char volatile *) b), a);
}

INLINE(unsigned char, UCHAR_SWPA)
(
    unsigned char           a,
    unsigned char volatile  b[1]
)
{
    return  MY_ACQUIRE(Exchange8, ((char volatile *) b), a);
}

INLINE(unsigned char, UCHAR_SWPE)
(
    unsigned char           a,
    unsigned char volatile  b[1]
)
{
    return  MY_RELEASE(Exchange8, ((char volatile *) b), a);
}

INLINE(unsigned char, UCHAR_SWPT)
(
    unsigned char           a,
    unsigned char volatile  b[1]
)
{
    return  MY_SEQ_CST(Exchange8, ((char volatile *) b), a);
}


/*

char
_InterlockedCompareExchange8
(
    char volatile   ptr[1],  // a
    char            desired, // b
    char            expected // c
)

bool
__atomic_compare_exchange_n
(
    type *  ptr,        // a
    type *  expected,   // b
    type    desired,    // c
    bool    weak,
    int     succ,
    int     fail
)

*/


INLINE(unsigned char,UCHAR_XEQ1)
(
    unsigned char           c,
    unsigned char volatile  a[1],
    unsigned char           b
)
{
    return  MY_RELAXED(CompareExchange8, ((char volatile *) a), b, c);
}

INLINE(unsigned char,UCHAR_XEQA)
(
    unsigned char           c,
    unsigned char volatile  a[1],
    unsigned char           b
)
{
    return  MY_ACQUIRE(CompareExchange8, ((char volatile *) a), b, c);
}

INLINE(unsigned char,UCHAR_XEQE)
(
    unsigned char           c,
    unsigned char volatile  a[1],
    unsigned char           b
)
{
    return  MY_RELEASE(CompareExchange8, ((char volatile *) a), b, c);
}

INLINE(unsigned char,UCHAR_XEQT)
(
    unsigned char           c,
    unsigned char volatile  a[1],
    unsigned char           b
)
{
    return  MY_SEQ_CST(CompareExchange8, ((char volatile *) a), b, c);
}


INLINE(unsigned char,UCHAR_ADD1)
(
    unsigned char           b,
    unsigned char volatile  a[1]
)
{
    return  MY_RELAXED(ExchangeAdd8, ((char volatile *) a), b);
}

INLINE(unsigned char,UCHAR_ADDA)
(
    unsigned char           b,
    unsigned char volatile  a[1]
)
{
    return  MY_ACQUIRE(ExchangeAdd8, ((char volatile *) a), b);
}

INLINE(unsigned char,UCHAR_ADDE)
(
    unsigned char           b,
    unsigned char volatile  a[1]
)
{
    return  MY_RELEASE(ExchangeAdd8, ((char volatile *) a), b);
}

INLINE(unsigned char,UCHAR_ADDT)
(
    unsigned char           b,
    unsigned char volatile  a[1]
)
{
    return  MY_SEQ_CST(ExchangeAdd8, ((char volatile *) a), b);
}


INLINE(unsigned char,UCHAR_SUB1)
(
    unsigned char           b,
    unsigned char volatile  a[1]
)
{
    return  MY_RELAXED(ExchangeAdd8, ((char volatile *) a),(0-b));
}

INLINE(unsigned char,UCHAR_SUBA)
(
    unsigned char           b,
    unsigned char volatile  a[1]
)
{
    return  MY_ACQUIRE(ExchangeAdd8, ((char volatile *) a),(0-b));
}

INLINE(unsigned char,UCHAR_SUBE)
(
    unsigned char           b,
    unsigned char volatile  a[1]
)
{
    return  MY_RELEASE(ExchangeAdd8, ((char volatile *) a),(0-b));
}

INLINE(unsigned char,UCHAR_SUBT)
(
    unsigned char           b,
    unsigned char volatile  a[1]
)
{
    return  MY_SEQ_CST(ExchangeAdd8, ((char volatile *) a),(0-b));
}


INLINE(unsigned char,UCHAR_AND1)
(
    unsigned char           b,
    unsigned char volatile  a[1]
)
{
    return  MY_RELAXED(ExchangeAnd8, ((char volatile *) a), b);
}

INLINE(unsigned char,UCHAR_ANDA)
(
    unsigned char           b,
    unsigned char volatile  a[1]
)
{
    return  MY_ACQUIRE(ExchangeAnd8, ((char volatile *) a), b);
}

INLINE(unsigned char,UCHAR_ANDE)
(
    unsigned char           b,
    unsigned char volatile  a[1]
)
{
    return  MY_RELEASE(ExchangeAnd8, ((char volatile *) a), b);
}

INLINE(unsigned char,UCHAR_ANDT)
(
    unsigned char           b,
    unsigned char volatile  a[1]
)
{
    return  MY_SEQ_CST(ExchangeAnd8, ((char volatile *) a), b);
}


INLINE(unsigned char,UCHAR_ORR1)
(
    unsigned char           b,
    unsigned char volatile  a[1]
)
{
    return  MY_RELAXED(Or8, ((char volatile *) a), b);
}

INLINE(unsigned char,UCHAR_ORRA)
(
    unsigned char           b,
    unsigned char volatile  a[1]
)
{
    return  MY_ACQUIRE(Or8, ((char volatile *) a), b);
}

INLINE(unsigned char,UCHAR_ORRE)
(
    unsigned char           b,
    unsigned char volatile  a[1]
)
{
    return  MY_RELEASE(Or8, ((char volatile *) a), b);
}

INLINE(unsigned char,UCHAR_ORRT)
(
    unsigned char           b,
    unsigned char volatile  a[1]
)
{
    return  MY_SEQ_CST(Or8, ((char volatile *) a), b);
}


INLINE(unsigned char,UCHAR_XOR1)
(
    unsigned char           b,
    unsigned char volatile  a[1]
)
{
    return  MY_RELAXED(Xor8, ((char volatile *) a), b);
}

INLINE(unsigned char,UCHAR_XORA)
(
    unsigned char           b,
    unsigned char volatile  a[1]
)
{
    return  MY_ACQUIRE(Xor8, ((char volatile *) a), b);
}

INLINE(unsigned char,UCHAR_XORE)
(
    unsigned char           b,
    unsigned char volatile  a[1]
)
{
    return  MY_RELEASE(Xor8, ((char volatile *) a), b);
}

INLINE(unsigned char,UCHAR_XORT)
(
    unsigned char           b,
    unsigned char volatile  a[1]
)
{
    return  MY_SEQ_CST(Xor8, ((char volatile *) a), b);
}


INLINE(void, my_atomic_signal_fence) (memory_order order)
{
    if (order == memory_order_seq_cst) cmbt();
}

INLINE(void, my_atomic_thread_fence) (memory_order order)
{
/*  'hmbt(); return' is necessary because otherwise, MSVC
    erroneously warns that a something is being returned
*/
    switch (order)
    {
        case memory_order_acquire: hmba();  break;
        case memory_order_release: hmbe();  break;
        case memory_order_acq_rel:
        case memory_order_seq_cst: hmbt();  break;
    }
}

#define     _Interlocked_my_bts _interlockedbittestandset

INLINE(_Bool, my_atomic_flag_test_and_set_explicit)
(
    atomic_flag volatile    flag[1],
    memory_order            order
)
{
    switch (order)
    {
        default: UNREACHABLE();
        case memory_order_relaxed:  return MY_RELAXED(_my_bts, &flag->Self, 0);
        case memory_order_consume:
        case memory_order_acquire:  return MY_ACQUIRE(_my_bts, &flag->Self, 0);
        case memory_order_release:  return MY_RELEASE(_my_bts, &flag->Self, 0);
        case memory_order_acq_rel:
        case memory_order_seq_cst:  return MY_SEQ_CST(_my_bts, &flag->Self, 0);
    }
}

INLINE(void, my_atomic_flag_clear_explicit)
(
    atomic_flag volatile    flag[1],
    memory_order            order
)
{
    switch (order)
    {
        default: UNREACHABLE();
        case memory_order_relaxed: ULONG_STR1(0, &flag->Self);
        case memory_order_consume:
        case memory_order_acquire:
        case memory_order_release: ULONG_STRE(0, &flag->Self);
        case memory_order_acq_rel:
        case memory_order_seq_cst: ULONG_STRT(0, &flag->Self);
    }
}

INLINE(void, my_atomic_flag_test_and_set)
(
    atomic_flag volatile flag[1]
)
{
    my_atomic_flag_test_and_set_explicit(flag, memory_order_seq_cst);
}

INLINE(void, my_atomic_flag_clear)
(
    atomic_flag volatile flag[1]
)
{
    my_atomic_flag_clear_explicit(flag, memory_order_seq_cst);
}

INLINE(unsigned char, my_atomic_load_explicit8)
(
    unsigned char volatile const    src[1],
    memory_order                    order
)
{
    switch (order)
    {
        default: UNREACHABLE();
        case memory_order_relaxed: return ABU_LDR1(src);
        case memory_order_consume:
        case memory_order_acquire: return ABU_LDRA(src);
        case memory_order_seq_cst: return ABU_LDRT(src);
    }
}

INLINE(void, my_atomic_store_explicit8)
(
    unsigned char volatile      b[1],
    unsigned char               a,
    memory_order                order
)
{
    switch (order)
    {
        case memory_order_relaxed: (void) UCHAR_STR1(a, b); return;
        case memory_order_release: (void) UCHAR_STRE(a, b); return;
        case memory_order_seq_cst: (void) UCHAR_STRT(a, b); return;
    }
    UNREACHABLE();
}

INLINE(unsigned char, my_atomic_exchange_explicit8)
(
    unsigned char volatile      b[1],
    unsigned char               a,
    memory_order                order
)
{
    switch (order)
    {
        default: UNREACHABLE();
        case memory_order_relaxed: return UCHAR_SWP1(a, b);
        case memory_order_consume:
        case memory_order_acquire: return UCHAR_SWPA(a, b);
        case memory_order_release: return UCHAR_SWPR(a, b);
        case memory_order_acq_rel:
        case memory_order_seq_cst: return UCHAR_SWPT(a, b);
    }
}


INLINE(_Bool, my_atomic_compare_exchange_strong_explicit8)
(
    unsigned char volatile  a[1], // "obj"
    unsigned char           b[1], // "expected"
    unsigned char           c,    // "desired"
    memory_order            succ,
    memory_order            fail
)
{
    unsigned char r = *b;
    unsigned char l;
    switch (my_cas_check(succ, fail))
    {
        default:                    UNREACHABLE();
        case memory_order_relaxed:  l = UCHAR_XEQ1(c, a, l); break;
        case memory_order_consume:
        case memory_order_acquire:  l = UCHAR_XEQA(c, a, l); break;
        case memory_order_release:  l = UCHAR_XEQR(c, a, l); break;
        case memory_order_acq_rel:
        case memory_order_seq_cst:  l = UCHAR_XEQT(c, a, l); break;
    }
    if (l != r) *b = l;
    else return 1;
    return 0;
}

INLINE(_Bool, my_atomic_compare_exchange_weak_explicit8)
(
    unsigned char volatile  a[1],
    unsigned char           b[1],
    unsigned char           c,
    memory_order            succ,
    memory_order            fail
)
{
    return my_atomic_compare_exchange_strong_explicit8(a,b,c,succ,fail);
}


INLINE(unsigned char, my_atomic_fetch_add_explicit8)
(
    unsigned char volatile  b[1],
    unsigned char           a,
    memory_order            order
)
{
    switch (order)
    {
        default: UNREACHABLE();
        case memory_order_relaxed: return UCHAR_ADD1(a, b);
        case memory_order_consume:
        case memory_order_acquire: return UCHAR_ADDA(a, b);
        case memory_order_release: return UCHAR_ADDE(a, b);
        case memory_order_acq_rel:
        case memory_order_seq_cst: return UCHAR_ADDT(a, b);
    }
}

INLINE(unsigned char, my_atomic_fetch_sub_explicit8)
(
    unsigned char volatile  b[1],
    unsigned char           a,
    memory_order            order
)
{
    switch (order)
    {
        default:                    UNREACHABLE();
        case memory_order_relaxed:  return UCHAR_SUB1(a, b);
        case memory_order_consume:
        case memory_order_acquire:  return UCHAR_SUBA(a, b);
        case memory_order_release:  return UCHAR_SUBE(a, b);
        case memory_order_acq_rel:
        case memory_order_seq_cst:  return UCHAR_SUBT(a, b);
    }
}

INLINE(unsigned char, my_atomic_fetch_and_explicit8)
(
    unsigned char volatile  b[1],
    unsigned char           a,
    memory_order            order
)
{
    switch (order)
    {
        default:                    UNREACHABLE();
        case memory_order_relaxed:  return UCHAR_AND1(a, b);
        case memory_order_consume:
        case memory_order_acquire:  return UCHAR_ANDA(a, b);
        case memory_order_release:  return UCHAR_ANDE(a, b);
        case memory_order_acq_rel:
        case memory_order_seq_cst:  return UCHAR_ANDT(a, b);
    }
}

INLINE(unsigned char, my_atomic_fetch_or_explicit8)
(
    unsigned char volatile  b[1],
    unsigned char           a,
    memory_order            order
)
{
    switch (order)
    {
        default:                    UNREACHABLE();
        case memory_order_relaxed:  return UCHAR_ORR1(a, b);
        case memory_order_consume:
        case memory_order_acquire:  return UCHAR_ORRA(a, b);
        case memory_order_release:  return UCHAR_ORRE(a, b);
        case memory_order_acq_rel:
        case memory_order_seq_cst:  return UCHAR_ORRT(a, b);
    }
}

INLINE(unsigned char, my_atomic_fetch_xor_explicit8)
(
    unsigned char volatile  b[1],
    unsigned char           a,
    memory_order            order
)
{
    switch (order)
    {
        default:                    UNREACHABLE();
        case memory_order_relaxed:  return UCHAR_XOR1(a, b);
        case memory_order_consume:
        case memory_order_acquire:  return UCHAR_XORA(a, b);
        case memory_order_release:  return UCHAR_XORE(a, b);
        case memory_order_acq_rel:
        case memory_order_seq_cst:  return UCHAR_XORT(a, b);
    }
}




