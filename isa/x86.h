/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳
x86 builtins

MMX: <mmintrin.h>
    typedef llong   __v1di      __attribute__((__vector_size__(8)));
    typedef int     __v2si      __attribute__((__vector_size__(8)));
    typedef short   __v4hi      __attribute__((__vector_size__(8)));
    typedef char    __v8qi      __attribute__((__vector_size__(8)));
    
    typedef llong   __m64       __attribute__((__vector_size__(8), __aligned__(8)));

MM3DNOW: <mm3dnowintrin.h>
    typedef float   __v2sf      __attribute__((__vector_size__(8)));

SSE: <xmmintrin.h>
    typedef int     __v4si      __attribute__((__vector_size__(16)));
    typedef float   __v4sf      __attribute__((__vector_size__(16)));
    typedef float   __m128      __attribute__((__vector_size__(16), __aligned__(16)));

    typedef float   __m128_u    __attribute__((__vector_size__(16), __aligned__(1)));
    typedef uint    __v4su      __attribute__((__vector_size__(16)));

SSE2: <emmintrin.h>
    typedef double  __m128d     __attribute__((vector_size(16), __aligned__(16)));
    typedef double  __m128d_u   __attribute__((vector_size(16), __aligned__(1)));

    typedef llong   __m128i     __attribute__((vector_size(16), __aligned__(16)));
    typedef llong   __m128i_u   __attribute__((vector_size(16), __aligned__(1)));

    typedef double  __v2df      __attribute__((vector_size(16)));
    typedef llong   __v2di      __attribute__((vector_size(16)));
    typedef short   __v8hi      __attribute__((vector_size(16)));
    typedef char    __v16qi     __attribute__((vector_size(16)));

    typedef ullong  __v2du      __attribute__((vector_size(16)));
    typedef ushort  __v8hu      __attribute__((vector_size(16)));
    typedef uchar   __v16qu     __attribute__((vector_size(16)));

    typedef schar   __v16qs     __attribute__((vector_size(16)));

AVX: <avxintrin.h>
    typedef double  __v4df      __attribute__ ((__vector_size__ (32)));
    typedef float   __v8sf __attribute__ ((__vector_size__ (32)));

    typedef llong   __v4di __attribute__ ((__vector_size__ (32)));
    typedef int     __v8si __attribute__ ((__vector_size__ (32)));
    typedef short   __v16hi __attribute__ ((__vector_size__ (32)));
    typedef char    __v32qi __attribute__ ((__vector_size__ (32)));
    
    typedef ullong  __v4du __attribute__ ((__vector_size__ (32)));
    typedef uint    __v8su __attribute__ ((__vector_size__ (32)));
    typedef ushort  __v16hu __attribute__ ((__vector_size__ (32)));
    typedef uchar   __v32qu __attribute__ ((__vector_size__ (32)));
    
    typedef schar   __v32qs __attribute__((__vector_size__(32)));
    
    typedef float   __m256 __attribute__ ((__vector_size__ (32), __aligned__(32)));
    typedef double  __m256d __attribute__((__vector_size__(32), __aligned__(32)));
    typedef llong   __m256i __attribute__((__vector_size__(32), __aligned__(32)));
    
    typedef float   __m256_u  __attribute__ ((__vector_size__ (32), __aligned__(1)));
    typedef double  __m256d_u __attribute__((__vector_size__(32), __aligned__(1)));
    typedef llong   __m256i_u __attribute__((__vector_size__(32), __aligned__(1)));

AVX512: <avx512fintrin.h>

    typedef char    __v64qi __attribute__((__vector_size__(64)));
    typedef short   __v32hi __attribute__((__vector_size__(64)));
    typedef int     __v16si __attribute__((__vector_size__(64)));
    typedef llong   __v8di __attribute__((__vector_size__(64)));
    typedef double  __v8df __attribute__((__vector_size__(64)));
    typedef float   __v16sf __attribute__((__vector_size__(64)));

    typedef uchar   __v64qu __attribute__((__vector_size__(64)));
    typedef ushort  __v32hu __attribute__((__vector_size__(64)));
    typedef ullong  __v8du __attribute__((__vector_size__(64)));
    typedef uint    __v16su __attribute__((__vector_size__(64)));

    typedef schar   __v64qs __attribute__((__vector_size__(64)));

    typedef float   __m512 __attribute__((__vector_size__(64), __aligned__(64)));
    typedef double  __m512d __attribute__((__vector_size__(64), __aligned__(64)));
    typedef llong   __m512i __attribute__((__vector_size__(64), __aligned__(64)));

    typedef float   __m512_u __attribute__((__vector_size__(64), __aligned__(1)));
    typedef double  __m512d_u __attribute__((__vector_size__(64), __aligned__(1)));
    typedef llong   __m512i_u __attribute__((__vector_size__(64), __aligned__(1)));

    typedef uchar   __mmask8;
    typedef ushort  __mmask16;

AVX512BF16: <avx512bf16intrin.h>

    typedef ushort  __bfloat16;
    typedef  short  __m256bh __attribute__((__vector_size__(32), __aligned__(32)));
    typedef  short  __m512bh __attribute__((__vector_size__(64), __aligned__(64)));

AVX512FP16: <avx51fp16intrin.h>

    typedef _Float16 __v8hf __attribute__((__vector_size__(16), __aligned__(16)));
    typedef _Float16 __v16hf __attribute__((__vector_size__(32), __aligned__(32)));
    typedef _Float16 __v32hf __attribute__((__vector_size__(64), __aligned__(64)));

    typedef _Float16 __m128h __attribute__((__vector_size__(16), __aligned__(16)));
    typedef _Float16 __m512h __attribute__((__vector_size__(64), __aligned__(64)));
    typedef _Float16 __m256h __attribute__((__vector_size__(32), __aligned__(32)));

    typedef _Float16 __m128h_u __attribute__((__vector_size__(16), __aligned__(1)));
    typedef _Float16 __m256h_u __attribute__((__vector_size__(32), __aligned__(1)));
    typedef _Float16 __m512h_u __attribute__((__vector_size__(64), __aligned__(1)));


typedef struct DECLSPEC_ALIGN(16) _M128A {
    ULONGLONG Low;
    LONGLONG High;
} M128A, *PM128A;

typedef struct DECLSPEC_ALIGN(16) _XSAVE_FORMAT {
    WORD                ControlWord;
    WORD                StatusWord;
    BYTE                TagWord;
    BYTE                Reserved1;
    WORD                ErrorOpcode;
    DWORD               ErrorOffset;
    WORD                ErrorSelector;
    WORD                Reserved2;
    DWORD               DataOffset;
    WORD                DataSelector;
    WORD                Reserved3;
    DWORD               MxCsr;
    DWORD               MxCsr_Mask;
    M128A               FloatRegisters[8];
#if defined(_WIN64)
    M128A               XmmRegisters[16];
    BYTE                Reserved4[96];
#else
    M128A               XmmRegisters[8];
    BYTE                Reserved4[224];
#endif
}   XSAVE_FORMAT, *PXSAVE_FORMAT;

typedef struct _XSAVE_CET_U_FORMAT {
    DWORD64             Ia32CetUMsr;
    DWORD64             Ia32Pl3SspMsr;
}   XSAVE_CET_U_FORMAT;

typedef struct DECLSPEC_ALIGN(8) _XSAVE_AREA_HEADER {
    DWORD64             Mask;
    DWORD64             CompactionMask;
    DWORD64             Reserved2[6];
}   XSAVE_AREA_HEADER;

typedef struct DECLSPEC_ALIGN(16) _XSAVE_AREA {
    XSAVE_FORMAT        LegacyState;
    XSAVE_AREA_HEADER   Header;
}   XSAVE_AREA;

typedef struct _XSTATE_CONTEXT {
    DWORD64             Mask;
    DWORD               Length;
    DWORD               Reserved1;
    PXSAVE_AREA         Area;
#if defined(_X86_)
    DWORD               Reserved2;
#endif
    PVOID               Buffer;
#if defined(_X86_)
    DWORD               Reserved3;
#endif
}   XSTATE_CONTEXT, *PXSTATE_CONTEXT;

typedef struct _SCOPE_TABLE_AMD64 {
    DWORD Count;
    struct {
        DWORD   BeginAddress;
        DWORD   EndAddress;
        DWORD   HandlerAddress;
        DWORD   JumpTarget;
    } ScopeRecord[1];
} SCOPE_TABLE_AMD64, *PSCOPE_TABLE_AMD64;

// The following flags control the contents of the CONTEXT structure.

//


#if !defined(RC_INVOKED)

#define CONTEXT_AMD64   0x00100000L

// end_wx86

#define CONTEXT_CONTROL         (CONTEXT_AMD64 | 0x00000001L)
#define CONTEXT_INTEGER         (CONTEXT_AMD64 | 0x00000002L)
#define CONTEXT_SEGMENTS        (CONTEXT_AMD64 | 0x00000004L)
#define CONTEXT_FLOATING_POINT  (CONTEXT_AMD64 | 0x00000008L)
#define CONTEXT_DEBUG_REGISTERS (CONTEXT_AMD64 | 0x00000010L)

#define CONTEXT_FULL            (CONTEXT_CONTROL | CONTEXT_INTEGER | \
                                 CONTEXT_FLOATING_POINT)

#define CONTEXT_ALL             (CONTEXT_CONTROL | CONTEXT_INTEGER | \
                                 CONTEXT_SEGMENTS | CONTEXT_FLOATING_POINT | \
                                 CONTEXT_DEBUG_REGISTERS)

#define CONTEXT_XSTATE          (CONTEXT_AMD64 | 0x00000040L)

#if defined(XBOX_SYSTEMOS)

#define CONTEXT_KERNEL_DEBUGGER     0x04000000L

#endif

#define CONTEXT_EXCEPTION_ACTIVE    0x08000000L
#define CONTEXT_SERVICE_ACTIVE      0x10000000L
#define CONTEXT_EXCEPTION_REQUEST   0x40000000L
#define CONTEXT_EXCEPTION_REPORTING 0x80000000L

// begin_wx86

#endif // !defined(RC_INVOKED)

//
// Define initial MxCsr and FpCsr control.
//

#define INITIAL_MXCSR 0x1f80            // initial MXCSR value
#define INITIAL_FPCSR 0x027f            // initial FPCSR value

// end_ntddk
// begin_wdm begin_ntosp
// begin_ntoshvp

typedef XSAVE_FORMAT XMM_SAVE_AREA32, *PXMM_SAVE_AREA32;

// end_wdm end_ntosp
// begin_ntddk

//
// Context Frame
//
//  This frame has a several purposes: 1) it is used as an argument to
//  NtContinue, 2) it is used to constuct a call frame for APC delivery,
//  and 3) it is used in the user level thread creation routines.
//
//
// The flags field within this record controls the contents of a CONTEXT
// record.
//
// If the context record is used as an input parameter, then for each
// portion of the context record controlled by a flag whose value is
// set, it is assumed that that portion of the context record contains
// valid context. If the context record is being used to modify a threads
// context, then only that portion of the threads context is modified.
//
// If the context record is used as an output parameter to capture the
// context of a thread, then only those portions of the thread's context
// corresponding to set flags will be returned.
//
// CONTEXT_CONTROL specifies SegSs, Rsp, SegCs, Rip, and EFlags.
//
// CONTEXT_INTEGER specifies Rax, Rcx, Rdx, Rbx, Rbp, Rsi, Rdi, and R8-R15.
//
// CONTEXT_SEGMENTS specifies SegDs, SegEs, SegFs, and SegGs.
//
// CONTEXT_FLOATING_POINT specifies Xmm0-Xmm15.
//
// CONTEXT_DEBUG_REGISTERS specifies Dr0-Dr3 and Dr6-Dr7.
//

typedef struct DECLSPEC_ALIGN(16) DECLSPEC_NOINITALL _CONTEXT {

    DWORD64 P1Home;
    DWORD64 P2Home;
    DWORD64 P3Home;
    DWORD64 P4Home;
    DWORD64 P5Home;
    DWORD64 P6Home;

    DWORD   ContextFlags;
    DWORD   MxCsr;

    DWORD64 Dr0;
    DWORD64 Dr1;
    DWORD64 Dr2;
    DWORD64 Dr3;
    DWORD64 Dr6;
    DWORD64 Dr7;

    DWORD64 Rax;
    DWORD64 Rcx;
    DWORD64 Rdx;
    DWORD64 Rbx;
    DWORD64 Rsp;
    DWORD64 Rbp;
    DWORD64 Rsi;
    DWORD64 Rdi;

    DWORD64 R8;
    DWORD64 R9;
    DWORD64 R10;
    DWORD64 R11;
    DWORD64 R12;
    DWORD64 R13;
    DWORD64 R14;
    DWORD64 R15;
    DWORD64 Rip;

    union {
        struct {
            WORD                ControlWord;
            WORD                StatusWord;
            BYTE                TagWord;
            BYTE                Reserved1;
            WORD                ErrorOpcode;
            DWORD               ErrorOffset;
            WORD                ErrorSelector;
            WORD                Reserved2;
        };
        M128A   Header[2];
    };
    union {
        struct {

        }
    }
            DWORD               DataOffset;
            WORD                DataSelector;
            WORD                Reserved3;
            DWORD               MxCsr;
            DWORD               MxCsr_Mask;

            M128A               FloatRegisters[8];

#if defined(_WIN64)
            M128A               XmmRegisters[16];
            BYTE                Reserved4[96];
#else
            M128A               XmmRegisters[8];
            BYTE                Reserved4[224];
#endif

}   XSAVE_FORMAT, *PXSAVE_FORMAT;

        struct {

            M128A   Legacy[8];
            M128A       Xmm0;
            M128A       Xmm1;
            M128A       Xmm2;
            M128A       Xmm3;
            M128A       Xmm4;
            M128A       Xmm5;
            M128A       Xmm6;
            M128A       Xmm7;
            M128A       Xmm8;
            M128A       Xmm9;
            M128A       Xmm10;
            M128A       Xmm11;
            M128A       Xmm12;
            M128A       Xmm13;
            M128A       Xmm14;
            M128A       Xmm15;
        } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME;

    M128A VectorRegister[26];
    DWORD64 VectorControl;

    DWORD64 DebugControl;
    DWORD64 LastBranchToRip;
    DWORD64 LastBranchFromRip;
    DWORD64 LastExceptionToRip;
    DWORD64 LastExceptionFromRip;
} CONTEXT, *PCONTEXT;

struct context_winnt_x64 {

//  Accumulator for operands and results data
    union {
        struct {uint64_t    rax;}  // x accum (nt=ret)
        struct {uint32_t    eax;}
        struct {uint16_t     ax;}
        struct {uint8_t      al, ah;}
    };

//  Pointer to data in the DS segment
    union {
        struct {uint64_t    rbx;}  // !
        struct {uint32_t    ebx;}
        struct {uint16_t     bx;}
        struct {uint8_t      bl, bh;}
    };

//  Counter for string and loop operations
    union {
        struct {uint64_t    rcx;}  // !
        struct {uint32_t    ecx;}
        struct {uint16_t     cx;}
        struct {uint8_t      cl, ch;}
    };

//  I/O pointer
    union {
        struct {uint64_t    rdx;}  // !
        struct {uint32_t    edx;}
        struct {uint16_t     dx;}
        struct {uint8_t      dl, dh;}
    };

    uint64_t rdx;  // x (nt=g[1])
    uint64_t r8;   // x (nt=g[2])
    uint64_t r9;   // x (nt=g[3])
    uint64_t r10;  // x (nt=syscall)
    uint64_t r11;  // x (nt=sysret)
    uint64_t r12;  // !
    uint64_t r13;  // !
    uint64_t r14;  // !
    uint64_t r15;  // !

    uint64_t rbp;  // ! (nt=frame)
    uint64_t rsp;  // ! (nt=stack)


    uint64_t rsi;  //
    uint64_t rdi;  //
    uint64_t orig_rax;
    uint64_t rip;
    uint64_t cs;
    uint64_t eflags;
    uint64_t ss;
    uint64_t fs_base;
    uint64_t gs_base;
    uint64_t ds;
    uint64_t es;
    uint64_t fs;
    uint64_t gs;
     WORD   SegCs;
    WORD   SegDs;
    WORD   SegEs;
    WORD   SegFs;
    WORD   SegGs;
    WORD   SegSs;
    DWORD EFlags;

};


struct  x86_xsave_header {
    _Alignas(64) struct {
        uint64_t
            Xstate,
            Xspec:  63,
            Xcomp:  1,
            :64, :64, :64, :64, :64, :64;
    };
};

struct  x86_xsave_area {
    XSAVE_FORMAT        LegacyState;
    XSAVE_AREA_HEADER   Header;
};

typedef struct _XSTATE_CONTEXT {
    DWORD64             Mask;
    DWORD               Length;
    DWORD               Reserved1;
    PXSAVE_AREA         Area;
#if defined(_X86_)
    DWORD               Reserved2;
#endif
    PVOID               Buffer;
#if defined(_X86_)
    DWORD               Reserved3;
#endif
}   XSTATE_CONTEXT, *PXSTATE_CONTEXT;

typedef struct _SCOPE_TABLE_AMD64 {
    DWORD Count;
    struct {
        DWORD   BeginAddress;
        DWORD   EndAddress;
        DWORD   HandlerAddress;
        DWORD   JumpTarget;
    } ScopeRecord[1];
} SCOPE_TABLE_AMD64, *PSCOPE_TABLE_AMD64;


struct x87reg {
    uint16_t    Sig[4];
    uint16_t    Exp;
    uint16_t    Pad[3];
};

union xmmreg {
    __m128  F;
    __m128i I;
    __m128d D;
};

typedef union {
    uint8_t             B[8];
    uint16_t            H[4];
    uint32_t            W[2];
    uint64_t            D[1];
    struct {uint8_t     B0,B1,B2,B3,B4,B5,B6,B7;}
    struct {uint16_t    H0,H1,H2,H3;}
    struct {uint32_t    W0,W1;}
    struct {uint64_t    D0;}
} dvecu_t;

typedef union {
    int8_t              B[16];
    int16_t             H[8];
    int32_t             W[4];
    int64_t             D[2];
    struct {int8_t      B0,B1,B2,B3,B4,B5,B6,B7;}
    struct {int16_t     H0,H1,H2,H3;}
    struct {int32_t     W0,W1;}
    struct {int64_t     D0;}
} dveci_t;

typedef union {
    _Float16    H[4];
    float       F[2];
    double      D[1];
    __m64       Vf;
} dvecf_t;

typedef union {
    char        C[8];
    dvecu_t     U;
    dveci_t     I;
    dvecf_t     F;
}   dvec_t;

typedef   signed __int128  int128_t;
typedef unsigned __int128 uint128_t;

typedef union {
    uint8_t             B[16];
    uint16_t            H[8];
    uint32_t            W[4];
    uint64_t            D[2];
    struct {uint8_t     B0,B1,B2,B3,B4,B5,B6,B7,B8,B9,Ba,Bb,Bc,Bd,Be,Bf;}
    struct {uint16_t    H0,H1,H2,H3,H4,H5,H6,H7;}
    struct {uint32_t    W0,W1,W2,W3;}
    struct {uint64_t    D0,D1;}
    struct {uint128_t   Q0;}
    __m128i             Vb,Vh,Vw,Vd,Vq;
} qvecu_t;

typedef union {
    int8_t              B[16];
    int16_t             H[8];
    int32_t             W[4];
    int64_t             D[2];
    int128_t            Q[1];
    struct {int8_t      B0,B1,B2,B3,B4,B5,B6,B7,B8,B9,Ba,Bb,Bc,Bd,Be,Bf;}
    struct {int16_t     H0,H1,H2,H3,H4,H5,H6,H7;}
    struct {int32_t     W0,W1,W2,W3;}
    struct {int64_t     D0,D1;}
    struct {int128_t    Q0;}
    __m128i             Vb,Vh,Vw,Vd,Vq;
} qveci_t;

typedef union {
    _Float16            H[8];
    float               F[4];
    double              D[2];
    long double         Q[1];
    __m128              Vf;
    __m128d             Vd;
} qvecf_t;

typedef union {
    char                C[16];
    qvecu_t             U;
    qveci_t             I;
    qvecf_t             F;
}   qvec_t;

struct context {
    uint16_t            Fcw;    // [ 0: 2] Control Word
    uint16_t            Fsw;    // [ 2: 4] Status Word
    _Alignas(2)
    uint8_t             Ftw;    // [ 4: 6] Tag Word
    uint16_t            Fop;    // [ 6: 8] Opcode

    uint64_t            Fip;    // [ 8:16] Instruction Pointer
    uint64_t            Fdp;    // [16:24] FDP: Data Pointer Offset
    uint32_t            Mxcsr;  // [24:28]
    uint32_t            Mxcsm;  // [28:32]

    union {
        qvec_t          Mm[8];
        struct {
            qvec_t      Mm0, Mm1, Mm2, Mm3, Mm4, Mm5, Mm6, Mm7;
        };
    };

    union {

#if MY_ISA == ISA_X64
        qvec_t          Xmm[16];
        struct {
            qvec_t
                Xmm0,   Xmm1,   Xmm2,   Xmm3,
                Xmm4,   Xmm5,   Xmm6,   Xmm7,
                Xmm8,   Xmm9,   Xmm10,  Xmm11,
                Xmm12,  Xmm13,  Xmm14,  Xmm15;
            char        R0[96];
        };
#else
        qvec_t  Xmm[8];
        struct {
            qvec_t
                Xmm0, Xmm1, Xmm2, Xmm3,
                Xmm4, Xmm5, Xmm6, Xmm7;
            char        R0[224];
        };
#endif

    };
#if defined(_WIN64)

    M128A XmmRegisters[16];
    BYTE  Reserved4[96];

#else

    M128A XmmRegisters[8];
    BYTE  Reserved4[224];

#endif

};

struct user_regs_struct {
    uint64_t r15;
    uint64_t r14;
    uint64_t r13;
    uint64_t r12;
    uint64_t rbp;
    uint64_t rbx;
    uint64_t r11;
    uint64_t r10;
    uint64_t r9;
    uint64_t r8;
    uint64_t rax;
    uint64_t rcx;
    uint64_t rdx;
    uint64_t rsi;
    uint64_t rdi;
    uint64_t orig_rax;
    uint64_t rip;
    uint64_t cs;
    uint64_t eflags;
    uint64_t rsp;
    uint64_t ss;
    uint64_t fs_base;
    uint64_t gs_base;
    uint64_t ds;
    uint64_t es;
    uint64_t fs;
    uint64_t gs;
};
struct user {
  struct user_regs_struct regs;
  int u_fpvalid;
  int pad0;
  struct user_fpregs_struct i387;
  unsigned long int u_tsize;
  unsigned long int u_dsize;
  unsigned long int u_ssize;
  unsigned long start_code;
  unsigned long start_stack;
  long int signal;
  int reserved;
  int pad1;
  struct user_regs_struct* u_ar0;
  struct user_fpregs_struct* u_fpstate;
  unsigned long magic;
  char u_comm[32];
  unsigned long u_debugreg[8];
  unsigned long error_code;
  unsigned long fault_address;
};

typedef char        __v64qi __attribute__((__vector_size__(64)));
typedef short       __v32hi __attribute__((__vector_size__(64)));
typedef double      __v8df  __attribute__((__vector_size__(64)));
typedef float       __v16sf __attribute__((__vector_size__(64)));
typedef long long   __v8di  __attribute__((__vector_size__(64)));
typedef int         __v16si __attribute__((__vector_size__(64)));

typedef unsigned char __v64qu __attribute__((__vector_size__(64)));
typedef unsigned short __v32hu __attribute__((__vector_size__(64)));
typedef unsigned long long __v8du __attribute__((__vector_size__(64)));
typedef unsigned int __v16su __attribute__((__vector_size__(64)));

typedef signed char __v64qs __attribute__((__vector_size__(64)));

//  avx512fintrin.h
typedef float __m512 __attribute__((__vector_size__(64), __aligned__(64)));
typedef double __m512d __attribute__((__vector_size__(64), __aligned__(64)));
typedef int64_t __m512i __attribute__((__vector_size__(64), __aligned__(64)));

typedef float       __m512_u __attribute__((vector_size(64), __aligned__(1)));
typedef double      __m512d_u __attribute__((vector_size(64), __aligned__(1)));
typedef int64_t     __m512i_u __attribute__((vector_size(64), __aligned__(1)));

typedef uint8_t             __mmask8;
typedef uint16_t            __mmask16;

//  <avx512bwintrin.h>
typedef unsigned int        __mmask32;
typedef unsigned long long  __mmask64;


8B / 64b
    vubd_t  uint8x8_t       __m64       *
    vuhd_t  uint16x4_t      __m64       *
    vuwd_t  uint32x2_t      __m64       *
    vudd_t  uint64x1_t      __m64       *
    
    vibd_t   int8x8_t       __m64       *
    vihd_t   int16x4_t      __m64       *
    viwd_t   int32x2_t      __m64       *
    vidd_t   int64x1_t      __m64       *
    
    vfhd_t   flt16x4_t      __m64       *
    vfwd_t   flt32x2_t      __m64       *
    vfdd_t   flt64x1_t      __m64       *

16B / 128b
    vubq_t  uint8x16_t      __m128i     vector uchar
    vuhq_t  uint16x8_t      __m128i     vector ushort
    vuwq_t  uint32x4_t      __m128i     vector uint
    vudq_t  uint64x2_t      __m128i     vector ullong
    vuqq_t  *               *           *

    vibq_t   int8x16_t      __m128i     vector schar
    vihq_t   int16x8_t      __m128i     vector short
    viwq_t   int32x4_t      __m128i     vector int
    vidq_t   int64x2_t      __m128i     vector llong
    viqq_t   *              *           *

    vfhq_t   float16x8_t    __m128h     *
    vfwq_t   float32x4_t    __m128      vector float
    vfdq_t   float64x2_t    __m128d     vector double
    vfqq_t   *              *           vector uchar

32B / 256b
    vubo_t  uint8x16x2_t    __m256i     *
    vuho_t  uint16x8x2_t    __m256i     *
    vuwo_t  uint32x4x2_t    __m256i     *
    vudo_t  uint64x2x2_t    __m256i     *
    vuqo_t  *               *
    
    vibo_t   int8x32_t      __m256i     *
    viho_t   int16x16_t     __m256i     *
    viwo_t   int32x8_t      __m256i     *
    vido_t   int64x4_t      __m256i     *
    viqo_t   int128x2_t     __m256i     *

    vfho_t   float16x8x2_t  __m256h     *
    vfwo_t   float32x4x2_t  __m256      *
    vfdo_t   float64x2x2_t  __m256d     *
    vfqo_t   *              *
    
64B / 512b
    vubs_t  uint8x64_t      __m512i
    vuhs_t  uint16x32_t     __m512i
    vuws_t  uint32x16_t     __m512i
    vuds_t  uint64x8_t      __m512i
    vuqs_t  uint64x2x4_t    __m512i

    vibs_t   int8x64_t      __m512i
    vihs_t   int16x32_t     __m512i
    viws_t   int32x16_t     __m512i
    vids_t   int64x8_t      __m512i
    viqs_t   int128x8_t     __m512i

    vfhs_t  float16x32_t    __m512h
    vfws_t  float32x16_t    __m512
    vfds_t  *               __m512d
    vdqs_t  *               *
    

zip:    interleave two vectors of the same type 
zipd:   interleave two vd vectors
zipdb:  interleave two v

zipl:   interleave the lower ½ of two vectors 
zipl:  interleave the lower half of two 8B vectors
zipldb: interleave the lower half of two 1Bx8 vectors
zipldh: interleave the lower half of two 2Bx4 vectors
zipldw: interleave the lower half of two 4Bx2 vectors

zipr:   interleave the upper ½ of two vectors 
ziprd:  interleave the upper half of two vec8_t
ziprdb: interleave the upper half of two dg8b_t
ziprdh: interleave the upper half of two vd4h_t
ziprdw: interleave the upper half of two vg2w_t

ziprdih:interleave two vi4h_t as vi8

i8x16   zipxdib( i8x8,  i8x8) => {a[0], b[0], ..., a[7], b[7]}
i8x8    zipldib( i8x8,  i8x8) => {a[0], b[0], ..., a[3], b[3]}
i8x8    zipxrdib( i8x8,  i8x8) => {a[4], b[4], ..., a[7], b[7]}
i8x8    zipxsib(i16x4, i16x4) => saturated 

cat:     concatenate two vectors
catl:    concatenate the lower ½ of two vectors
catr:    concatenate the upper ½ of two vectors
cats:    concatenate two wide vectors with saturation


___ = (add|sub|dif)

i8           ___ib  (i8     a,  i8    b)
i8x8        d___ib  (i8x8   a,  i8x8  b)
i8x16       q___ib  (i8x16  a,  i8x16 b)
i8x32       o___ib  (i8x32  a,  i8x32 b)
i8x64       s___ib  (i8x64  a,  i8x64 b)

i64x8       s___id  (i64x8  a,  i64x8 b)

i8          ___cib  (i8     a,  i8    b, i8 *c)

i8          ___sib  (i8     a,  i8    b)
i8x8       d___sib  (i8x8   a,  i8x8  b)
i8x16      q___sib  (i8x16  a,  i8x16 b)
i8x32      o___sib  (i8x32  a,  i8x32 b)
i8x64      s___sib  (i8x64  a,  i8x64 b)

i16         ___wib  (i8    a,   i8    b)
i16x8      d___wib  (i8x8  a,   i8x8  b)
i16x16     q___wib  (i8x16 a,   i8x16 b)
i16x32     o___wib  (i8x32 a,   i8x32 b)

i16     addih   ( i16 a,  i16 b)

i16     addsih  ( i16 a,  i16 b)
i16     addcih  ( i16 a,  i16 b, i16_t *c)
i32     addwih  ( i16 a,  i16 b)

i32     addi    ( i32 a,  i32 b)
i32     addsi   ( i32 a,  i32 b)
i32     addci   ( i32 a,  i32 b, i32_t *c)
i64     addwi   ( i32 a,  i32 b)

i64     addid   ( i64 a,  i64 b)
i64     addsid  ( i64 a,  i64 b)
i64     addcid  ( i64 a,  i64 b, i64_t *c)
i128    addwid  ( i64 a,  i64 b)

i128_t    addiq   (i128_t a, i128_t b)


int8_t      addsib  (  int8_t a,   int8_t b)
int8_t      addcib  (  int8_t a,   int8_t b, int8_t *c)
int16_t     addwib  (  int8_t a,   int8_t b)

int16_t     addih   ( int16_t a,  int16_t b)
int16_t     addsih  ( int16_t a,  int16_t b)
int16_t     addcih  ( int16_t a,  int16_t b, int16_t *c)
int32_t     addwih  ( int16_t a,  int16_t b)

int32_t     addi    ( int32_t a,  int32_t b)
int32_t     addsi   ( int32_t a,  int32_t b)
int32_t     addci   ( int32_t a,  int32_t b, int32_t *c)
int64_t     addwi   ( int32_t a,  int32_t b)

int64_t     addid   ( int64_t a,  int64_t b)
int64_t     addsid  ( int64_t a,  int64_t b)
int64_t     addcid  ( int64_t a,  int64_t b, int64_t *c)
int128_t    addwid  ( int64_t a,  int64_t b)

int128_t    addiq   (int128_t a, int128_t b)





int8_t      idivb   (int8_t a,   int8_t b)
int16_t     idivh   (int16_t a, int16_t b)
int32_t     idiv    (int32_t a, int32_t b)
int64_t     idivd   (int64_t a, int64_t b)

int8_t      idivc   (int8_t a,   int8_t b, int8_t *c)
int16_t     idivc   (int16_t a,  int16_t b, int16_t *c)
int32_t     idivc   (int32_t a,  int32_t b, int32_t *c)
int64_t     idivcd  (int64_t a,  int64_t b, int64_t *c)
int128_t    idivcd  (int128_t a, int128_t b, int128_t *c)

div8_t      idivwb  (int8_t a,  int8_t b)
div16_t     idivwh  (int16_t a, int16_t b)
div32_t     idivw   (int32_t a, int32_t b)
div64_t     idivwd  (int64_t a, int64_t b)
div128_t    idivwq  (int128_t a, int128_t b)

//  t   add     Int scalar addition (w/ undefined overflow)
//  t   adds    Int scalar addition (w/ saturation)
//  tx2 addw    Int scalar addition (w/ widened result)
//  t   addc    Int scalar addition (w/ carry flag)


//  t   div
//  v   vadds      Vector addition (w/ saturation)
    i8   iaddsb     (i8  a, i8  b)
    i16  iaddsh     (i16 a, i16 b)
    i32  iadds      (i32 a, i32 b)
    i64  iaddsd     (i64 a, i64 b)

    qih  addsibq    (qib a, qib b, qib c, msk m)
    qih  addsqih    (qih a, qih b, qih c, msk m)
    qiw  addsqi     (qiw a, qiw b, qiw c, msk m)
    qiw  addsqid    (qid a, qid b, qid c, msk m)

        {m[x] ? addsi(a[x], b[x]) : qiw[x], ...}

    i32     iadds   (i32 A, i32 B) => (A+B)
    qwi     qiadds  (qwi A, qwi B, ) => {A[a]+B[a], ...}

    qwi     qadds  (qwi A, qwi B) => {A[a]+

    Lx2 LaddwR  (L, R)      Signed "+"; result expanded
    Lx2 LsubwR  (L, R)

    Lx1 LaddcR  (L, R, C*)  Signed "+"; overflow carried

    Lx1 LsubcR  (L, R, C*)

    Lx1 LmulR   (L, R)
    Lx1 LmulsR  (L, R)
    Lx2 LmulwR  (L, R)
    Lx1 LmulcR  (L, R, C*)



    i32 iaddu(i32, u32)
    faddf(i32, i32)
    faddf(f32, f32)
    vaddi(i8q, i)
    tmp[31:0] := ((a[i+15:i] << 16)[31:0] | b[i+15:i]) << imm8[3:0]
	dst[i+15:
*/


#if MY_CPU_VENDOR == CPU_VENDOR_AMD
/*  Lightweight Profiling
*/
#   if defined(X86_LWP) //                      -mlwp
#   endif

/*  Advanced Bit Manipulation
    -march=barcelona
*/
#   if defined(X86_ABM) //                      -mabm
#       ifndef X86_POPCNT
#       define X86_POPCNT
#       endif

#       ifndef X86_LZCNT
#       define X86_LZCNT
#       endif

#       ifndef X86_BMI1
#       define X86_BMI1
#       endif

#   endif

/*  eXtended Operations
    -march=bdver1 
#   include <xopintrin.h> */
#   if defined(X86_XOP) //                      -mxop
#   endif

/*  Streaming SIMD 4a
    -march=barcelona
#   include <ammintrin.h> */
#   if defined(X86_SSE4A) //                    -msse4a
#   endif

/*  Fused Multiply Add 4
    -march=bdver1
#   include <fma4intrin.h> */
#   if defined(X86_FMA4) //                     -mfma4
#   endif

/*  Timed MONITOR & MWAIT
    -march=znver2
*/
#   if defined(X86_MWAITX) //                   -mmwaitx
        Intrin void     __builtin_ia32_monitorx(void *, unsigned, unsigned);
        Intrin void     __builtin_ia32_mwaitx(unsigned, unsigned, unsigned);
#   endif

/*  Cache Line Zero
    -march=znver1
#   include <clzerointrin.h> */
#   if defined(X86_CLZERO) //                   -mclzero
        Intrin void     _mm_clzero(void *);
#   endif

#elif MY_CPU_VENDOR == CPU_VENDOR_INTEL

/*  Software Guard Extensions 1 & 2 
#   include <sgxintrin.h> */
#   if defined(X86_SGX) //                      -msgx
#       ifndef X86_SGX1
#       define X86_SGX1
#       endif

#       ifndef X86_SGX2
#       define X86_SGX2
#       endif

#       ifndef X86_OVERSUB
#       define X86_OVERSUB
#       endif

#   endif

/*  -march=skylake
    -march=goldmont-plus
*/
#   if defined(X86_SGX1)
        Intrin unsigned _encls_u32(unsigned, size_t[]);
#   endif

/*  -march=skylake
    -march=goldmont-plus
*/
#   if defined(X86_SGX2)
        Intrin unsigned _enclu_u32(unsigned, size_t[]);
#   endif

/*  Oversubscription of Secure Memory in a Virtualized Environment
    -march=skylake
    -march=goldmont-plus
*/
#   if defined(X86_OVERSUB)
        Intrin unsigned _enclv_u32(unsigned, size_t[]);
#   endif

/*  Cache Line Demotion Hint
    -march=tremont
#   include <cldemoteintrin.h> */
#   if defined(X86_CLDEMOTE) //                 -mcldemote
        Intrin void     _cldemote(void const *);
#   endif

/*  History Reset
    -march=alderlake
#   include <hresetintrin.h> */
#   if defined(X86_HRESET) //                   -mhreset
        Intrin void     _hreset(int);
#   endif

/*  "User Interprocessor Interrupts"
    -march=sapphirerapids
#   include <uintrintrin.h> */
#   if defined(X86_UINTR) //                    -muintr
        Intrin void     _clui(void);
        Intrin void     _stui(void);
        Intrin void     _testui(void);
        Intrin void     _senduipi(uint64_t);
#   endif

/*  Direct Store 
    -march=tigerlake|tremont
#   include <movdirintrin.h> */
#   if defined(X86_MOVDIRI) //                  -mmovdiri
        Intrin void     _directstoreu_u32(void *, uint32_t);
#       if MY_ISA == ISA_X64        
        Intrin void     _directstoreu_u64(void *, uint64_t);
#       endif
#   endif

/*  Atomic direct move 64B
    -march=tigerlake
    -march=tremont
#   include <movdirintrin.h> */
#   if defined(X86_MOVDIR64B) //                -mmovdir64b
        Intrin void     _movdir64b(void *, void const *);
#   endif

/*  "Instruction Execution Serialization"
    -march=alderlake 
#   include <serializeintrin.h> */
#   if defined(X86_SERIALIZE) //                -mserialize
        Intrin void     _serialize(void);
#   endif

/*  "Enqueue Store"
    -march=sapphirerapids
#   include <enqcmdintrin.h> */
#   if defined(X86_ENQCMD) //                   -menqcmd
        Intrin int      _enqcmd (void *, void const *);
        Intrin int      _enqcmds(void *, void const *);
#   endif

/*  Transactional Synchronization Extensions
    -march=haswell
*/
#   if defined(X86_TSX)

/*      Hardware Lock Elision */
#       if defined(X86_HLE) //                  -mhle
#       endif

/*      Restricted Transactional Memory */
#       if defined(X86_RTM) //                  -mrtm
#           define _XBEGIN_STARTED   (~0u)
#           define _XABORT_EXPLICIT  (1 << 0)
#           define _XABORT_RETRY     (1 << 1)
#           define _XABORT_CONFLICT  (1 << 2)
#           define _XABORT_CAPACITY  (1 << 3)
#           define _XABORT_DEBUG     (1 << 4)
#           define _XABORT_NESTED    (1 << 5)
#           define _XABORT_CODE(x)   (((x) >> 24) & 0xFF)
            Intrin void     _xabort(unsigned const);
            Intrin unsigned _xbegin(void);
            Intrin void     _xend(void);
#       endif

/*      Transactional Synchronization Extensions: Load Address Tracking
        -march=sapphirerapids
#       include <tsxldtrkintrin.h> */
#       if defined(X86_TSXLDTRK) //             -mtsxldtrk
            Intrin void     _xresldtrk(void);
            Intrin void     _xsusldtrk(void);
#       endif

#   endif // defined(X86_TSX)


/*  Platform Configuration
    -march=icelake-server
#   include <pconfigintrin.h> */  
#   if defined(X86_PCONFIG) //                  -mpconfig
        Inline unsigned _pconfig_u32(unsigned, size_t[]);
#   endif

#else
#   error "unknown CPU vendor"
#endif

/*  Matrix Math Extensions?
    -march=pentium2
    -march=k6
#   include <mmintrin.h> */
#if defined(X86_MMX) //                         -mmmx

    // scvt(v) => ((T) v)
    INLINE int     _mm_cvtsi64_si32(__m64);
    INLINE llong   _mm_cvtm64_si64(__m64);

    // vcvt(s) => ((t){[0]=s})
    INLINE __m64   _mm_cvtsi32_si64(int);
    INLINE __m64d  _mm_cvtsi64_m64(llong);

    INLINE __m64b   _mm_packs_pi16(__m64h, __m64h);
    INLINE __m64h   _mm_packs_pi32(__m64,  __m64);
    INLINE __m64b   _mm_packs_pu16(__m64h, __m64h);

    INLINE __m64b   _mm_unpackhi_pi8 (__m64b, __m64b);  // dziprib
    INLINE __m64h   _mm_unpackhi_pi16(__m64h, __m64h);  // dziprih
    INLINE __m64    _mm_unpackhi_pi32(__m64,  __m64);   // dzipri

    INLINE __m64b   _mm_unpacklo_pi8 (__m64b, __m64b);  // dziplib
    INLINE __m64h   _mm_unpacklo_pi16(__m64b, __m64b);  // dziplih
    INLINE __m64h   _mm_unpacklo_pi32(__m64b, __m64b);  // dzipli

    // dadd
    INLINE __m64b   _mm_add_pi8 (__m64b, __m64b);       // daddib
    INLINE __m64h   _mm_add_pi16(__m64h, __m64h);       // daddih
    INLINE __m64    _mm_add_pi32(__m64,  __m64);        // daddi

    // dadds
    INLINE __m64b   _mm_adds_pi8 (__m64b, __m64b);      // daddsib
    INLINE __m64h   _mm_adds_pi16(__m64h, __m64h);      // daddsih

    // dceq 
    INLINE __m64    _mm_cmpeq_pi8 (__m64, __m64);       // dceqib
    
    // 
#endif

/*  "Streaming SIMD"
    -march=pentium3
    -march=k8
*/
#if defined(X86_SSE) //                         -msse

#   include <xmmintrin.h>

#   ifndef X86_PREFETCH
#   define X86_PREFETCH
#   endif

#   ifndef X86_FXSR
#   define X86_FXSR
#   endif

#endif

/*  "Streaming SIMD 2"
    -march=pentium4
    -march=k8
#   include <emmintrin.h>
*/
#if defined(X86_SSE2) //                        -msse2
    INLINE __m64d   _mm_add_pi64(__m64d, __m64d);       // daddid
    
#endif

/*  "Streaming SIMD 3"
    -march=prescott
    -march=k8-sse3
#   include <pmmintrin.h>
*/
#if defined(X86_SSE3) //                        -msse3
    INLINE __m128   _mm_lddqu_si128 (__m128i const *);
    INLINE __m128   _mm_hadd_ps     (__m128, __m128);
    INLINE __m128d  _mm_hadd_pd     (__m128d, __m128d);
    INLINE __m128   _mm_hsub_ps     (__m128, __m128);

#   if defined(X86_MONITOR)
        INLINE void _mm_mwait       (unsigned, unsigned);
        INLINE void _mm_monitor     (void const *, unsigned, unsigned);
#   endif

#endif

/*  "SSE3 supplement"
    -march=core2
    -march=bdver1
#   include <tmmintrin.h>
*/
#if defined(X86_SSSE3) //                       -mssse3
    INLINE __m64    _mm_abs_pi8 (__m64);
    INLINE __m64    _mm_abs_pi16(__m64);
    INLINE __m64    _mm_abs_pi32(__m64);
    INLINE __m128i  _mm_abs_epi8(__m128i);
    INLINE __m128i  _mm_abs_epi16(__m128i);

    INLINE __m64    _mm_hadd_pi16 (__m64,   __m64);
    INLINE __m128i  _mm_hadd_epi16(__m128i, __m128i);
#endif

/*  "Streaming SIMD 4.1"
    -march=nehalem
    -march=bdver1
*/
#if defined(X86_SSE41) //                       -msse4.1
#   include <nmmintrin.h>
#endif

/*  "Streaming SIMD 4.2"
*/
#if defined(X86_SSE42) //                       -msse4.2
#   include <smmintrin.h>
#   ifndef X86_CRC32C
#   define X86_CRC32C
#   endif

    Intrin int          _mm_cmpistra(__m128i, __m128i, int const op);
/*
    op[0:2] == 0b00: AS_UINT8X16
    op[0:2] == 0b01: AS_UINT16X8
    op[0:2] == 0b10: AS_INT8X16
    op[0:2] == 0b11: AS_INT16X8

    op  [2:4] == 0b00:
        [4:6] == 0b00: OP_STRSPN
        [4:6] == 0b01: OP_STRCSPN

    op[2:4] == 0b01: OP_STRICR
    op[4:6] == 0b00: OP_STRICR
    op[2:4] == 0b10: OP_STRCMP
    op[2:4] == 0b11: OP_STRSTR

    op[4:6] == 0b00: {+[0], +[1], +[2]}
    op[4:6] == 0b01: {~[0], ~[1], ~[2]}
    op[4:6] == 0b11: same as 00 but don't negate past strlen
*/

#endif

#if defined(X86_CRC32C)
    Intrin uint32_t     _mm_crc32_u8(uint32_t, uint8_t);
    Intrin uint32_t     _mm_crc32_u16(uint32_t, uint16_t);
    Intrin uint32_t     _mm_crc32_u32(uint32_t, uint32_t);
    Intrin uint64_t     _mm_crc32_u64(uint64_t, uint64_t);
#endif

/*  "Advanced Vector Extensions"
    -march=sandybridge
    -march=bdver1
#   include <avxintrin.h>
*/
#if defined(X86_AVX) //                         -mavx
#endif

/*  "Advanced Vector Extensions 2"
    -march=haswell
    -march=bdver4
#   include <avx2intrin.h>
*/
#if defined(X86_AVX2) //                        -mavx2
#endif

/*  Control-Flow Enforcement Technology: Shadow Stack
    -march=tigerlake
    -march=znver3

    Note: the CET_SS feature is available in tigerlake and
    znver3 onward but never by default.
    Also, -mcet-switch enables branch tracing for C switch
    statements implemented as a lookup table.
*/
#if defined(X86_CETSS) //                       -mshstk
    Intrin void         _incsspd(int);
    Intrin void         _saveprevssp(void);
    Intrin void         _rstorssp(void *);
    Intrin void         _wrssd(uint32_t, void *);
    Intrin void         _wrussd(uint32_t, void *);
    Intrin void         _setssbsy(void);
    Intrin void         _clrssbsy(void *);
    Intrin void         _inc_ssp(uint8_t);
    Intrin uint32_t     _rdsspd(uint32_t);
    Intrin uint32_t     _rdsspd_i32(void);

#   if MY_ISA == ISA_X32
        Intrin uint32_t _get_ssp(void);
#   elif MY_ISA == ISA_X64
        Intrin uint64_t _get_ssp(void);
#   else
#       error "why is MY_ISA no longer in {ISA_X32, ISA_X64}"
#   endif

#   if MY_ISA == ISA_X64
    Intrin void         _incsspq(uint64_t);
    Intrin uint64_t     _rdsspq(uint64_t);
    Intrin uint64_t     _rdsspq_i64(void);
    Intrin void         _wrssq(uint64_t, void *);
    Intrin void         _wrussq(uint64_t, void *);
#   endif

/*  16 byte atomic CAS
    -march=core2
    -march=bdver1
*/
#if defined(X86_CX16)
#   error "the CMPXCHG16B instruction is required"
#endif

/*  "Bit Manipulation Instruction Set 1"
    -march=haswell
    -march=bdver2
*/
#if defined(X86_BMI1) //                        -mbmi
#   include <bmiintrin.h>

#   ifndef  X86_TZCNT
#   define  X86_TZCNT
#   endif

#   ifndef  X86_LZCNT
#   define  X86_LZCNT
#   endif

//  f(a, b) => (~a&b)
/*  MSVC says the origin of _andn_uN is ammintrin.h (sse4a),
    implying it's only available on AMD.
*/
    Intrin uint32_t     _andn_u32(uint32_t, uint32_t);
    Intrin uint64_t     _andn_u64(uint64_t, uint64_t);

//  f(i, j, k) => (i[j:j+k])
    Intrin uint32_t     _bextr_u32(uint32_t, unsigned, unsigned);
    Intrin uint64_t     _bextr_u64(uint64_t, unsigned, unsigned);

//  f(i, j) => (i[j[:8]:j[:8]+j[8:16]])
    Intrin uint32_t     _bextr2_u32(uint32_t, unsigned const j);
    Intrin uint64_t     _bextr2_u64(uint64_t, unsigned const j);

//  f(i) => ((i-1)&i)
    Intrin uint32_t     _blsr_u32(uint32_t);
    Intrin uint64_t     _blsr_u64(uint64_t);

//  f(i) => ((i-1)^i)
    Intrin uint32_t     _blsmsk_u32(uint32_t);
    Intrin uint64_t     _blsmsk_u64(uint64_t);

//  f(i) => ctz(i)
    Intrin uint16_t     _tzcnt_u16(uint16_t);
    Intrin uint32_t     _tzcnt_u32(uint32_t);
    Intrin uint64_t     _tzcnt_u64(uint64_t);

#endif

/*  "Bit Manipulation Instruction Set 2"
    -march=haswell
    -march=bdver4
*/
#if defined(X86_BMI2) //                        -mbmi2

#   include <bmi2intrin.h>
//  f(i, j) => (i[:widthof(i)-j])
    Intrin uint32_t     _bzhi_u32(uint32_t, unsigned);

//  f(a,b,c) => (mulcu(a, b, c))
    Intrin uint32_t     _mulx_u32(uint32_t, uint32_t, uint32_t *);

//  f(b, m) => ({
//  b[next(j)] if m[i] else '0'
//  for k in [range(widthof(a))]
//  for j in [iter(k)]
//  for i in (k)})
    Intrin uint32_t     _pdep_u32(uint32_t, unsigned);

//  f(b, m) => ({b[i] for i in range(widthof(b)) if m[i]})
    Intrin uint32_t     _pext_u32(uint32_t, unsigned);
#   if MY_ISA == ISA_X64
    Intrin uint64_t     _bzhi_u64(uint64_t, unsigned);
    Intrin uint64_t     _mulx_u64(uint64_t, uint64_t, uint64_t *);
    Intrin uint64_t     _pdep_u64(uint64_t, unsigned);
    Intrin uint64_t     _pext_u64(uint64_t, unsigned);
#   endif

#endif

/*  "Population Count" (Hamming weight)
    -march=nehalem
    -march=barcelona
*/
#if defined(X86_POPCNT) //                      -mpopcnt
#   include <popcntintrin.h>
    Intrin int32_t      _mm_popcnt_u32(uint32_t);
    Intrin int64_t      _mm_popcnt_u64(uint64_t);
#endif

/*  "Count Leading Zeros"
    -march=haswell
    -march=barcelona
*/
#if defined(X86_LZCNT) //                       -mlzcnt
#   include <lzcntintrin.h>
    Intrin uint32_t     _lzcnt_u32(uint32_t);
    Intrin uint64_t     _lzcnt_u64(uint64_t);
#endif

/*  AES128
    -march=westmere
    -march=bdver1
*/
#if defined(X86_AES) //                         -maes
#   ifndef X86_CLMUL
#   define X86_CLMUL
#   endif
    Intrin __m128i          _mm_aesimc_si128(__m128i);
    Intrin __m128i          _mm_aesenc_si128(__m128i, __m128i);
    Intrin __m128i          _mm_aesdec_si128(__m128i, __m128i);
    Intrin __m128i      _mm_aesenclast_si128(__m128i, __m128i);
    Intrin __m128i      _mm_aesdeclast_si128(__m128i, __m128i);
    Intrin __m128i _mm_aeskeygenassist_si128(__m128i, int const);
#endif

/*  "Carry-less Multiplication"
    -march=westmere
    -march=bdver1
*/
#if defined(X86_PCLMULQDQ) //                       -mpclmul
#   include <wmmintrin.h>
    Intrin __m128i      _mm_clmulepi64_si128(__m128i, __m128i, int const);
/*
    m[0:5] == 0b00000: a[ 0: 64]*b[ 0: 64]
    m[0:5] == 0b00001: a[ 0: 64]*b[64:128]
    m[0:5] == 0b10000: a[ 0: 64]*b[64:128]
    m[0:5] == 0b10001: a[64:128]*b[64:128]
*/
#endif

/*  "Carry-less Multiplication"
VPCLMULQDQ
*/
#if defined(X86_VPCLMULQDQ)
    Intrin __m512i      _mm512_clmulepi64_epi128(__m512i, __m512i, int const);
#   if defined(X86_AVX512VL)
/*  -march=znver2
    -march=sierraforest
*/
    Intrin __m256i      _mm256_clmulepi64_epi128(__m256i, __m256i, int const);
#   endif
#endif

/*  SHA-1
-march=icelake|goldmont
-march=znver1
*/
#if defined(X86_SHA) //                         -msha
#   ifndef  X86_SHA1
#   define  X86_SHA1
#   endif

#   ifndef  X86_SHA2
#   define  X86_SHA2
#   endif

#endif

#if defined(X86_SHA1)
#   ifndef X86_SHA
#   define X86_SHA
#   endif
    Intrin __m128i      _mm_sha1msg1_epu32(__m128i, __m128i);
    Intrin __m128i      _mm_sha1msg2_epu32(__m128i, __m128i);
    Intrin __m128i      _mm_sha1nexte_epu32(__m128i, __m128i);
    Intrin __m128i      _mm_sha1rnds4_epu32(__m128i, __m128i, int);
#endif

#if defined(X86_SHA2)
#   ifndef X86_SHA
#   define X86_SHA
#   endif
    Intrin __m128i      _mm_sha256msg1_epu32(__m128i, __m128i);
    Intrin __m128i      _mm_sha256msg2_epu32(__m128i, __m128i);
    Intrin __m128i      _mm_sha256rnds2_epu32(__m128i, __m128i, __m128i);
#endif

//# include <shaintrin.h>

/*  "Fused Multiply Add 3"
    -march=haswell
    -march=bdver2
*/
#if defined(X86_FMA) //                         -mfma
#   include <fmaintrin.h>
#endif

/*  "Cache Line Flush Optimized"
    -march=skylake | goldmont
    -march=znver1
*/
#if defined(X86_CLFLUSHOPT) //                  -mclflushopt
    #include <clflushoptintrin.h>
    Intrin void         _mm_clflushopt(void const *);
#endif

/*  "Cache Line Write Back"
    -march=skylake-avx512 | icelake-client
    -march=znver2
*/
#if defined(X86_CLWB) //                        -mclwb
#   include <clwbintrin.h>
    Intrin void         _mm_clwb(void const *);
#endif

/*  "Half-precision floating point conversion"
    -march=ivybridge
    -march=bdver1
*/
#if defined(X86_F16C) //                        -mf16c
#   include <f16cintrin.h>
    Intrin __m128       _mm_cvtph_ps(__m128i);
    Intrin float        _cvtsh_ss(uint16_t);
    Intrin uint16_t     _cvtss_sh(float, int const mode);
/*
    mode==000: near; (+1.9 -> +2.0) || (-1.9 -> -2.0)
    mode==001: ninf; (+1.9 -> +1.0) || (-1.9 -> -2.0)
    mode==010: pinf; (+1.9 -> +2.0) || (-1.9 -> -1.0)
    mode==011: zero; (+1.9 -> +1.0) || (-1.9 -> -1.0)
    mode==1xx: MXCSR.RC:
        0x0000 = near
        0x2000 = ninf
        0x4000 = pinf
        0x6000 = zero
*/
#endif

/*  CSPRNG seed generator
    -march=broadwell
    -march=znver1
*/
#if defined(X86_RDSEED) //                      -rdseed
#   include <rdseedintrin.h>
    Intrin int          _rdseed16_step(uint16_t *);
    Intrin int          _rdseed32_step(uint32_t *);
    Intrin int          _rdseed64_step(uint64_t *);
#   ifndef X86_RDRAND
#   define X86_RDRAND
#   endif
#endif

/*  HWPRNG
    -march=ivybridge
    -march=znver1
*/
#if defined(X86_RDRAND) //                      -rdrand
    Intrin int          _rdrand16_step(uint16_t *);
    Intrin int          _rdrand32_step(uint32_t *);
    Intrin int          _rdrand64_step(uint64_t *);
#endif

/*  Get executing processor's id
    -march=goldmont-plus
    -march=znver2
*/
#if defined(X86_RDPID)
    Intrin unsigned     _rdpid_u32(void);
#endif

/*  Programmatic FS/GS ("segment register") access
    -march=ivybridge
    -march=bdver3
*/
#if defined(X86_FSGSBASE) //                    -mfsgsbase

    Intrin unsigned     _readfsbase_u32(void);
    Intrin void         _writefsbase_u32(unsigned);

    Intrin unsigned     _readgsbase_u32(void);
    Intrin void         _writegsbase_u32(unsigned);

    Intrin uint64_t     _readfsbase_u64(void);
    Intrin void         _writefsbase_u64(uint64_t);

    Intrin uint64_t     _readgsbase_u64(void);
    Intrin void         _writegsbase_u64(uint64_t);
#endif

/*  Insert 32 bit PTW
*/
#if defined(X86_PTWRITE) //                 -mptwrite
    Intrin void         _ptwrite32(uint32_t);
    Intrin void         _ptwrite64(uint64_t);
#endif

/*  "Instruction Prefetch" */
#if defined(X86_PREFETCH)

    Intrin void         _mm_prefetch (char const *, int const i);

    _Static_assert(1|_MM_HINT_NTA, "...");
    _Static_assert(1|_MM_HINT_T0,  "...");
    _Static_assert(1|_MM_HINT_T1,  "...");
    _Static_assert(1|_MM_HINT_T2,  "...");

#   if defined(X86_PREFETCHWT1) //          -mprefetchwt1
        _Static_assert(1|_MM_HINT_ET1,  "...");
#   endif

#   if defined(X86_PREFETCHW) //            -mprfchw
        _Static_assert(1|_MM_HINT_ET0,  "...");
#   endif

#endif

#if defined(X86_PREFETCHI) //               -mprefetchi
    Intrin void         _m_prefetchit0(void const *);
    Intrin void         _m_prefetchit1(void const *);
#endif

/*  "Cache Writeback No Invalidate"
    -march=icelake-server
    -march=znver2
*/
#if defined(X86_WBNOINVD) //                -mwbnoinvd
    Intrin void         _wbnoinvd(void);
#endif

#if defined(X86_ADX) //                     -madx
#   ifndef  X86_ADCX
#   define  X86_ADCX
#   endif

#endif

/*  "Advanced Add-with-carry"
    -march=broadwell
    -march=znver2
*/
#if defined(X86_ADCX) //                    -madcx
    Intrin uint8_t      _addcarryx_u32(uint8_t, uint32_t, uint32_t, uint32_t *);
    Intrin uint8_t      _subborrow_u32(uint8_t, uint32_t, uint32_t, uint32_t *);
    Intrin uint8_t      _addcarryx_u64(uint8_t, uint64_t, uint64_t, uint64_t *);
    Intrin uint8_t      _subborrow_u64(uint8_t, uint64_t, uint64_t, uint64_t *);
#endif

#if defined(X86_XSS)
#   ifndef  X86_XSAVE
#   define  X86_XSAVE
#   endif
#endif

#if defined(X86_XSAVEC)
#   ifndef  X86_XSAVE
#   define  X86_XSAVE
#   endif
#endif

#if defined(X86_XSAVEOPT)
#   ifndef  X86_XSAVE
#   define  X86_XSAVE
#   endif
#endif

/*  Processor Extended State Save/Restore.
    -march=sandybridge
    -march=bdver1
*/
#if defined(X86_XSAVE) //                   -mxsave
    Inline void         _xsave(void *, uint64_t);
    Inline void         _xrstor(void *, uint64_t);
    Inline void         _xsave64(void *, uint64_t);
    Inline void         _xrstor64(void *, uint64_t);
    Intrin uint64_t     _xgetbv(uint32_t);
    Intrin void         _xsetbv(uint32_t, uint64_t);

/*  Processor Extended State save/restore with compaction
    -march=skylake|goldmont
    -march=znver1
*/
#   if defined(X86_XSAVEC) //               -mxsavec
        Intrin void     _xsavec(void *, uint64_t);
        Intrin void     _xsavec64(void *, uint64_t);
#   endif

/*  Processor Extended State save/restore, supervisor state
    -march=skylake|goldmont
    -march=znver1
*/
#   if defined(X86_XSS) //                  -mxsaves
        Intrin void     _xsaves(void *, uint64_t);
        Intrin void     _xsaves64(void *, uint64_t);
#   endif

/*  Processor Extended State save/restore, supervisor state
    -march=skylake|goldmont
    -march=znver1
*/
#   if defined(X86_XSAVEOPT) //             -mxsaveopt
        Intrin void     _xsaves(void *, uint64_t);
        Intrin void     _xsaves64(void *, uint64_t);
#   endif

#endif

/*  Save x87, MMX, XMM, & MXCSR in 64B-aligned 512B struct
*/
#if defined(X86_FXSR) //                    -mfxsr
    Intrin void         _fxsave(void *);
    Intrin void         _fxrstor(void *);
    Intrin void         _fxsave64(void *);
    Intrin void         _fxrstor64(void *);
#endif

#if defined(X86_PKU) //                     -mpku
    Intrin void         _wrpkru(unsigned);
    Intrin void         _rdpkru_32(void);
#endif

#if defined(X86_CMPCCXADD) //               -mcmpccxadd

    typedef enum {
        _CMPCCX_O,   /* Overflow.  */
        _CMPCCX_NO,  /* No overflow.  */
        _CMPCCX_B,   /* Below.  */
        _CMPCCX_NB,  /* Not below.  */
        _CMPCCX_Z,   /* Zero.  */
        _CMPCCX_NZ,  /* Not zero.  */
        _CMPCCX_BE,  /* Below or equal.  */
        _CMPCCX_NBE, /* Neither below nor equal.  */
        _CMPCCX_S,   /* Sign.  */
        _CMPCCX_NS,  /* No sign.  */
        _CMPCCX_P,   /* Parity.  */
        _CMPCCX_NP,  /* No parity.  */
        _CMPCCX_L,   /* Less.  */
        _CMPCCX_NL,  /* Not less.  */
        _CMPCCX_LE,  /* Less or equal.  */
        _CMPCCX_NLE, /* Neither less nor equal.  */
    }   _CMPCCX_ENUM;

    Intrin int32_t      _cmpccxadd_epi32(void *, int32_t, int32_t, int const);
#   if MY_ISA == ISA_X64
    Intrin int64_t      _cmpccxadd_epi64(void *, int64_t, int64_t, int const);
#   endif

#endif

/*
*/
#if defined(X86_RAOINT)         //          -mraoint
#   include <raointintrin.h>    // clang/llvm
#   include <x86gprintrin.h>    // intel
    Intrin void         _aadd_i32(int32_t *, int32_t);
    Intrin void         _aand_i32(int32_t *, int32_t);
    Intrin void          _aor_i32(int32_t *, int32_t);
    Intrin void         _axor_i32(int32_t *, int32_t);
#   if MY_ISA == ISA_X64
    Intrin void         _aadd_i64(int64_t *, int64_t);
    Intrin void         _aand_i64(int64_t *, int64_t);
    Intrin void          _aor_i64(int64_t *, int64_t);
    Intrin void         _axor_i64(int64_t *, int64_t);
#   endif

#endif

/*  Galois Field New Instructions
    -march=tremont
    -march=znver4
*/
#if defined(X86_GFNI) //                    -mgfni
#   if defined(X86_AVX512VL)
        Intrin __m128i  _mm_gf2p8affine_epi64_epi8(__m128i, __m128i, int);
#   endif
#endif

#if defined(X86_AMXCOMPLEX) //              -mamx-complex
#endif


#if !(defined(_MSC_VER) || defined(X86_SCE)) || __has_feature(modules) ||      \
    defined(X86_PTWRITE)
#include <ptwriteintrin.h>
#endif

#if !(defined(_MSC_VER) || defined(X86_SCE)) || __has_feature(modules) ||      \
    defined(X86_INVPCID)
#   include <invpcidintrin.h>
#endif

#if defined(X86_KL) || defined(X86_WIDEKL)
#   include <keylockerintrin.h>
#endif

#if defined(X86_AMX)
#   include <amxintrin.h>
//  -mamx-tile              X86_AMXTILE
//  -mamx-bf16              X86_AMXBF16
//  -mamx-int8              X86_AMXINT8
//  -mamx-fp16              X86_AMX_FP16

#endif

#if !(defined(_MSC_VER) || defined(X86_SCE)) || __has_feature(modules) ||      \
    defined(X86_AVX512VP2INTERSECT)
#include <avx512vp2intersectintrin.h>
#endif

#if !(defined(_MSC_VER) || defined(X86_SCE)) || __has_feature(modules) ||      \
    (defined(X86_AVX512VL) && defined(X86_AVX512VP2INTERSECT))
#include <avx512vlvp2intersectintrin.h>
#endif





#       endif // X86_SSE3
#   endif // X86_SSE2
#endif // X86_SSE

-mkl                    X86_KL
-mwidekl                X86_WIDEKL
-mavx512vnni            X86_AVX512VNNI
-mhle                   X86_HLE

-mvaes                  X86_VAES

/*  User-mode memory monitoring and waiting
    -tremont|alderlake
*/
#if defined(X86_WAITPKG) //                 -mwaitpkg
    Intrin uint8_t      _tpause(uint32_t, uint64_t);
    Intrin void         _umonitor(void *);
    Intrin uint8_t      _umwait(uint32_t, uint64_t);
#endif


-mvpclmulqdq            X86_VPCLMULQDQ

-mavxvnni               X86_AVXVNNI
-mavxifma               X86_AVXIFMA
-mavxvnniint8           X86_AVXVNNIINT8
-mavxneconvert          X86_AVXNECONVERT

vaes+avx512f
__m512i _mm512_aesdec_epi128(__m512i a, __m512i RoundKey)
__m512i _mm512_aesenc_epi128(__m512i a, __m512i RoundKey)
__m512i _mm512_aesenclast_epi128(__m512i a, __m512i RoundKey)
__m512i _mm512_aesdeclast_epi128(__m512i a, __m512i RoundKey)

vaes+avx512vl
__m256i _mm256_aesdec_epi128(__m256i a, __m256i RoundKey)
__m256i _mm256_aesenc_epi128(__m256i a, __m256i RoundKey)
__m256i _mm256_aesenclast_epi128(__m256i a, __m256i RoundKey)
__m256i _mm256_aesdeclast_epi128(__m256i a, __m256i RoundKey)

/*  Trailing Bit Manipulation
-march=bdver2
*/
#if defined(X86_TBM) //                         -mtbm
#   define __bextri_u32(a, b) __builtin_ia32_bextri_u32((a),(b))
    Inline unsigned __blcfill_u32(unsigned a) {return a&(a+1);}
    Inline unsigned __blci_u32(unsigned  a) {return a|~(a+1);}
    Inline unsigned __blcic_u32(unsigned a) {return ~a&(a+1);}
    Inline unsigned __blcmsk_u32(unsigned a) {return a^(a+1);}
    Inline unsigned __blcs_u32(unsigned a) {return a|(a+1);}
    Inline unsigned __blsfill_u32(unsigned a) {return a|(a-1);}
    Inline unsigned __blsic_u32(unsigned a) {return ~a|(a-1);}
    Inline unsigned __t1mskc_u32(unsigned a) {return ~a | (a + 1);}
    Inline unsigned __tzmsk_u32(unsigned a) {return ~a & (a - 1);}
#   if MY_ISA == ISA_X64
#       define  __bextri_u64(b)     __builtin_ia32_bextri_u32((a),(b))
#       define __blcfill_u64(a)    ( (ullong)(a)&((ullong)(a)+1) )
#       define    __blci_u64(a)    ( (ullong)(a)|~((ullong)(a)+1 )
#       define   __blcic_u64(a)    (~(ullong)(a)&((ullong)(a)+1) )
#       define  __blcmsk_u64(a)    ( (ullong)(a)^((ullong)(a)+1) )
#       define    __blcs_u64(a)    ( (ullong)(a)|((ullong)(a)+1) )
#       define __blsfill_u64(a)    ( (ullong)(a)|((ullong)(a)-1) )
#       define   __blsic_u64(a)    (~(ullong)(a)|((ullong)(a)-1) )
#       define  __t1mskc_u64(a)    (~(ullong)(a)|((ullong)(a)+1) )
#       define   __tzmsk_u64(a)    ( (ullong)(a)&((ullong)(a)-1) )
#   endif
#endif
