
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#pragma once

#include <float.h>
#if FLT_RADIX != 2
#error "unknown floating point representation"
#endif

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <fenv.h>

typedef struct unslice {
    ptrdiff_t pos;
    ptrdiff_t end;
} unslice_t;

typedef struct {
    intmax_t    quot;
    void       *rem;
} undiv_t;

typedef struct {
    void *quot;
    void *rem;
} unldiv_t;

typedef unsigned char   char8_t;
typedef uint_least16_t  char16_t;
typedef uint_least32_t  char32_t;

typedef char FILENAME_T[FILENAME_MAX];

enum REPR {
    REPR_VOID,  /*  type of unfinished types    */
    REPR_JUNK,  /*  type of pad bytes           */
    REPR_BOOL,  /*  _Bool                       */
    REPR_BIT,   /*  _Bool bitfield              */
    REPR_BYTE,  /*  (reserved)                  */
    REPR_CHAR,  /*  char                        */
    REPR_S8,    /*  signed char                 */
    REPR_U8,    /*  unsigned char               */
    REPR_S16,   /*  signed short                */
    REPR_U16,   /*  unsigned short              */
    REPR_WORD,  /*  anything promoted to int    */
    REPR_PTR,   /*  pointer                     */
    REPR_S32,   /*  signed int                  */
    REPR_U32,   /*  unsigned int                */
    REPR_S64,
    REPR_U64,
    REPR_S128,
    REPR_U128,

    REPR_FP16,  /*  IEEE 754 binary16           */
    REPR_FP32,  /*  IEEE 754 binary32           */
    REPR_FP64,  /*  IEEE 754 binary64           */
    REPR_FP128, /*  IEEE 754 binary128          */

#   define    AS_INT8      AS_SCHAR
#   define    AS_UINT8     AS_UCHAR
#   define    AS_INT16     AS_SHORT
#   define    AS_UINT16    AS_USHORT
#   define    AS_INT32     AS_INT
#   define    AS_UINT32    AS_UINT
#   define OP_AS_INT8   OP_AS_SCHAR
#   define OP_AS_UINT8  OP_AS_UCHAR
#   define OP_AS_INT16  OP_AS_SHORT
#   define OP_AS_UINT16 OP_AS_USHORT
#   define OP_AS_INT32  OP_AS_INT
#   define OP_AS_UINT32 OP_AS_UINT

#   if (FLT_MANT_DIG == 24)
#       define   REPR_FLT  REPR_FP32
#       define    AS_FP32     AS_FLT
#       define OP_AS_FP32  OP_AS_FLT

#   elif (FLT_MANT_DIG == 53)
#       define  REPR_FLT  REPR_FP64
#   else
#       error "unsupported representation of C float type"
#   endif

#   if  (DBL_MANT_DIG == 53)
#       define REPR_DBL  REPR_FP64
#       define OP_AS_FP64 OP_AS_DBL
#       define    AS_FP64    AS_DBL
#   else
#       error "unsupported representation of C double type"
#   endif

#   if (LDBL_MANT_DIG == 53)
#       define REPR_LDBL REPR_FP64
#   elif (LDBL_MANT_DIG == 113)
#       define REPR_LDBL REPR_FP128
#       define OP_AS_FP128 OP_AS_LDBL
#       define    AS_FP128    AS_LDBL
#   else
#       error "unsupported representation of C long double type"
#   endif

#   define REPR_SCHAR  REPR_S8
#   define REPR_UCHAR  REPR_U8
#   define REPR_SHORT  REPR_S16
#   define REPR_USHORT REPR_U16
#   define REPR_INT    REPR_S32
#   define REPR_UINT   REPR_U32

#   if LONG_MAX == INT32_MAX

#       define REPR_LONG  REPR_S32
#       define REPR_ULONG REPR_U32

#   else

#       define REPR_LONG  REPR_S64
#       define REPR_ULONG REPR_U64

#       define  OP_AS_INT64  OP_AS_LONG
#       define     AS_INT64     AS_LONG

#       define OP_AS_UINT64 OP_AS_ULONG
#       define    AS_UINT64    AS_ULONG

#   endif

#   if LLONG_MAX == INT64_MAX

#       define REPR_LLONG  REPR_S64
#       define REPR_ULLONG REPR_U64

#       ifndef OP_AS_UINT64 

#           define OP_AS_UINT64 OP_AS_ULLONG
#           define    AS_UINT64    AS_LLONG

#           define  OP_AS_INT64 OP_AS_LLONG
#           define     AS_INT64    AS_LLONG

#       endif

#   else
#       define REPR_LLONG  REPR_S128
#       define REPR_ULLONG REPR_U128

#   endif

#   if INTMAX_MAX == LONG_MAX

#       define   REPR_INTMAX   REPR_LONG
#       define  REPR_UINTMAX  REPR_ULONG

#       define  OP_AS_INTMAX  OP_AS_LONG
#       define     AS_INTMAX     AS_LONG
#       define OP_AS_UINTMAX OP_AS_ULONG
#       define    AS_UINTMAX    AS_ULONG

#   else
#       define   REPR_INTMAX   REPR_LLONG
#       define  REPR_UINTMAX  REPR_ULLONG

#       define  OP_AS_INTMAX  OP_AS_LLONG
#       define     AS_INTMAX     AS_LLONG
#       define OP_AS_UINTMAX OP_AS_ULLONG
#       define    AS_UINTMAX    AS_ULLONG

#   endif

#   if SIZE_MAX == UINT16_MAX

#       define    SIZE_REPR REPR_U16
#       define PTRDIFF_REPR REPR_S16
#       define  INTPTR_REPR REPR_S16
#       define UINTPTR_REPR REPR_U16

#   elif SIZE_MAX == UINT32_MAX

#       define    SIZE_REPR REPR_U32
#       define PTRDIFF_REPR REPR_S32
#       define  INTPTR_REPR REPR_S32
#       define UINTPTR_REPR REPR_U32

#   elif SIZE_MAX == UINT64_MAX

#       define    SIZE_REPR REPR_U64
#       define PTRDIFF_REPR REPR_S64
#       define  INTPTR_REPR REPR_S64
#       define UINTPTR_REPR REPR_U64

#   endif

#   if WCHAR_MAX == UINT8_MAX
#       define WCHAR_REPR REPR_U8 

#   elif WCHAR_MAX == UINT16_MAX
#       define WCHAR_REPR REPR_U16

#   elif WCHAR_MAX == UINT32_MAX
#       define WCHAR_REPR REPR_U32

#   else 
#       error "compiler uses unsupported repr for wchar_t"
#   endif

#   define REPR_INT8    REPR_S8
#   define REPR_INT16   REPR_S16 
#   define REPR_INT32   REPR_S32 
#   define REPR_INT64   REPR_S64
#   define REPR_INT128  REPR_S128

#   define REPR_UINT8    REPR_U8
#   define REPR_UINT16   REPR_U16 
#   define REPR_UINT32   REPR_U32 
#   define REPR_UINT64   REPR_U64
#   define REPR_UINT128  REPR_U128
    
    REPR_DIV_T,
    REPR_LDIV_T,
    REPR_LLDIV_T,
    REPR_IMAXDIV_T,
    REPR_TIMESPEC,
    REPR_TIMEVAL,
    REPR_MAX,
};

typedef enum {
    /* C arithmetic operand conversion rank */
    NB_RANK_0,  /*  _Bool */
    NB_RANK_1,  /*  char == unsigned char == signed char */
    NB_RANK_2,  /*  short == unsigned short  */
    NB_RANK_3,  /*  int == unsigned int  */
    NB_RANK_4,  /*  long == unsigned long */
    NB_RANK_5,  /*  llong == unsigned llong  */
    NB_RANK_6,  /*  int128 == uint128_t  */
    NB_RANK_7,  /*  float */
    NB_RANK_8,  /*  double */
    NB_RANK_9,  /*  long double */
    NB_RANK_MAX,
} NB_RANK_T;

typedef enum {
    CMP_LT,     /*  a < b */
    CMP_LE,     /*  a ≤ b */
    CMP_EQ,     /*  a = b */
    CMP_NE,     /*  a ≠ b */
    CMP_GT,     /*  a > b */
    CMP_GE,     /*  a ≥ b */
    CMP_AE,     /*  a ≈ b */
    CMP_IN,     /*  a in b */
    CMP_T_MAX,
} CMP_T;

typedef enum {
    /* Rounding modes

    These correspond, semantically, with the symbolic
    constants used by fegetround and fesetround to control
    the current thread's default rounding behavior.

    Specifically:
        FE_TONEAREST    ≈ ROUND_NEAR (round)
        FE_UPWARDS      ≈ ROUND_CEIL (ceil)
        FE_DOWNWARDS    ≈ ROUND_DOWN (floor)
        FE_TOWARDSZERO  ≈ ROUND_ZERO (trunc) / cast
                         
                   func     | -1.4| -1.6| +1.4| +1.6*/
    ROUND_NEAR, /* round    | -1  | -2  | +1  | +2  */
    ROUND_CEIL, /* ceil     | -1  | -1  | +2  | +2  */
    ROUND_DOWN, /* floor    | -2  | -2  | +1  | +1  */
    ROUND_ZERO, /* trunc    | -1  | -1  | +1  | +1  */
    ROUND_NEXT, /*          | -2  | -2  | +2  | +2  */

    ROUND_T_MAX,

} ROUND_T;

typedef enum {
    SQ_GETLEN,      /*  sq.length       */
    SQ_SETLEN,      /*  sq.length = n   */
    SQ_GETITEM,     /*  v = sq[i]       */
    SQ_GETSLICE,    /*  v = sq[i:j]     */
    SQ_GETXSLICE,   /*  v = sq[i:j:k]   */
    SQ_SETITEM,     /*  sq[i] = v       */
    SQ_SETSLICE,    /*  sq[i:j] = v     */
    SQ_SETXSLICE,   /*  sq[i:j:k] = v   */
    SQ_T_MAX,
} SQ_T;

typedef enum {
    MP_GETSIZE,
    MP_SETSIZE,     
    MP_GETITEM,     /*  v = m[k]            */
    MP_ADDITEM,     /*  m[k] = v            */
    MP_POPITEM,     /*  v = m[k], del m[k]  */
    MP_T_MAX,
} MP_T;

typedef enum {
    UN_NOT,     /*  v = !x          */
    UN_IINC,    /*  v=x, x+=1       */
    UN_IDEC,    /*  v=x, x-=1       */
    UN_IABS,    /*  v=x, x=|x|      */
    UN_INEG,    /*  v=x, x=-x       */
    UN_IINV,    /*  v=x, x=~x       */
    UN_INC,     /*  v = x+=1        */
    UN_DEC,     /*  v = --x         */
    UN_ABS,     /*  v = |x|         */
    UN_NEG,     /*  v = -x          */
    UN_INV,     /*  v = ~x          */
    UN_POS,     /*  v = +x          */
    UN_T_MAX,
} UN_T;

typedef enum {
    BI_LSH,     /*  a << b */
    BI_ILSH,    /*  a <<= b */

    BI_RECV,    /*  char   a[] << FILE *b   */
    BI_SEND,    /*  FILE * a   << char  b[] */

    BI_XLSH,    /*  a <<< b */
    BI_IXLSH,   /*  a <<<= b */

    BI_RSH,     /*  a >> b */
    BI_IRSH,    /*  a >>= b */

    BI_XRSH,    /*  a >>> b */
    BI_IXRSH,   /*  a >>>= b */

    BI_AND,     /*  a & b    (OP_MP_AND) */
    BI_IAND,    /*  a &= b   (OP_MP_IAND) */
    BI_SAND,    /*  set intersection */
    BI_ISAND,

    BI_OR,      /*  a | b    (OP_MP_OR) */
    BI_IOR,     /*  a |= b   (OP_MP_IOR) */
    BI_SOR,     /*  set union */
    BI_ISOR,

    BI_XOR,     /*  bitwise XOR                 */
    BI_IXOR,    /*  inplace XOR                 */
    BI_SXOR,    /*  symmetric difference        */
    BI_ISXOR,   /*  inplace symmetric difference*/

    BI_ADD,     /*  v = (T)a + (T)b             */
    BI_FADD,    /*  v = (T)a + (double)b        */
    BI_LADD,    /*  v = (T)a + (long)b          */
    BI_TADD,    /*  v = (T)a + (timens_t *)b    */
    BI_IADD,    /*  a += (T)b                   */
    BI_IFADD,   /*  a += (double)b              */
    BI_ILADD,   /*  a += (long)b                */
    BI_ITADD,   /*  a += (timens_t *)b          */

    BI_SUB,     /*  a - b       */
    BI_FSUB,    /*  a - 2.0     */
    BI_LSUB,    /*  a - 10L     */
    BI_TSUB,    /*  a - <T+1s>  */
    BI_ISUB,    /*  b -= b      */
    BI_IFSUB,   /*  a -= 2.0    */
    BI_ILSUB,   /*  a -= 10L    */
    BI_ITSUB,   /*  a -= <T+1s> */

    BI_MUL,     /*  a * b       */
    BI_FMUL,    /*  a * 2.0     */
    BI_LMUL,    /*  a * 2L      */ 
    BI_IMUL,    /*  a *= b      */
    BI_IFMUL,   /*  a *= 2.0    */
    BI_ILMUL,   /*  a *= 2L     */

    BI_MOD,     /*  a % b       */
    BI_FMOD,    /*  a % 2.0     */
    BI_LMOD,    /*  a % 2L      */
    BI_IMOD,    /*  a %= b      */
    BI_IFMOD,   /*  a %= 2.0    */
    BI_ILMOD,   /*  a %= 2L     */

    BI_DIV,      /*  a / b      */
    BI_FDIV,     /*  a / 1.0    */
    BI_LDIV,     /*  a / 10L    */
    BI_IDIV,     /*  a /= b     */
    BI_IFDIV,    /*  a /= 2.0   */
    BI_ILDIV,    /*  a /= 1L    */

    BI_T_MAX,
} BI_T;

typedef enum {

    AS_ANY,     /*  void *                          */

    /* "Strings\0" */
    AS_BYTES,   /*  const char *        */
    AS_UNICODE, /*  const wchar_t *     */

    /* Characters   */
    AS_CHAR,    /*  char                            */
    AS_CHAR8,   /*  char8_t                         */
    AS_CHAR16,  /*  char16_t                        */
    AS_CHAR32,  /*  char32_t                        */
    AS_WCHAR,   /*  wchar_t                         */
    AS_WINT,    /*  wint_t                          */

    /* Unsigned integers */
    AS_BOOL,    /*  NB_RANK_0, REPR_BOOL            */
    AS_UCHAR,   /*  NB_RANK_1, REPR_U8              */
    AS_USHORT,  /*  NB_RANK_2, REPR_U16             */
    AS_UINT,    /*  NB_RANK_3, REPR_U32             */
    AS_ULONG,   /*  NB_RANK_4, REPR_U32|REPR_64     */
    AS_ULLONG,  /*  NB_RANK_5, REPR_U64|REPR_128    */
    AS_UXLONG,  /*  NB_RANK_6, REPR_U***            */

    /* Signed integers */
    AS_SCHAR,   /*  NB_RANK_0, REPR_S8              */
    AS_SHORT,   /*  NB_RANK_1, REPR_S16             */
    AS_INT,     /*  NB_RANK_2, REPR_S32             */
    AS_LONG,    /*  NB_RANK_3, REPR_S32|REPR_S64    */
    AS_LLONG,   /*  NB_RANK_4, REPR_S64|REPR_S128   */
    AS_XLONG,   /*  NB_RANK_6, REPR_S***            */

    /* Floats */
    AS_HALF,
    AS_FLT,     /* float                            */
    AS_DBL,     /* double                           */
    AS_LDBL,    /* long double                      */

    /*  Times  */
    AS_TIME,        /*  time_t                      */
    AS_FTIME,       /*  double (seconds)            */
    AS_TIMESPEC,    /*  struct timespec             */
    AS_TIMEVAL,     /*  struct timeval              */

    /* Streams */

    AS_FILE,            /*  FILE *                  */
    AS_DIR,             /*  DIR *                   */

    /* URI */
    AS_FILENAME,        /*  char[FILENAME_MAX]      */
    AS_SOCKADDR,        /*  struct sockaddr *       */

    /* File descriptors */
    AS_FILENO,          /*  fileno()                */
    AS_DIRFD,           /*  type S_IFDIR            */
    AS_SOCKFD,          /*  type S_IFSOCK           */

    /* pid_t: Process ID */
    AS_PID,

    /* thrd_t: Thread ID */
    AS_TID,

#   if _POSIX_VERSION >= 200809L
    /* gid_t: Group ID */
    AS_GID,
    /* uid_t: user id */
    AS_UID,
#   endif

    AS_HASH,        /* hash_t: index of hash table */
    AS_SIZEOF,      /* size_t: size in bytes of object */
    AS_INDEX,       /* ptrdiff_t: sequence index */
    AS_FPOS,        /* off_t/fpos_t: file/stream offset */
    AS_ABS, 

    AS_T_MAX,
} AS_T;

#define OP_UN_OFFSET    0
#define OP_BI_OFFSET    OP_UN_MAX
#define OP_SQ_OFFSET    OP_BI_MAX
#define OP_MP_OFFSET    OP_SQ_MAX
#define OP_CMP_OFFSET   OP_MP_MAX
#define OP_ROUND_OFFSET OP_CMP_MAX
#define OP_AS_OFFSET    OP_ROUND_MAX

enum {

    OP_UN_NOT           =  UN_NOT+OP_UN_OFFSET,
    OP_UN_IINC          = UN_IINC+OP_UN_OFFSET,
    OP_UN_IDEC          = UN_IDEC+OP_UN_OFFSET,
    OP_UN_INEG          = UN_INEG+OP_UN_OFFSET,
    OP_UN_IINV          = UN_IINV+OP_UN_OFFSET,
    OP_UN_INC           =  UN_INC+OP_UN_OFFSET,
    OP_UN_DEC           =  UN_DEC+OP_UN_OFFSET,
    OP_UN_NEG           =  UN_ABS+OP_UN_OFFSET,
    OP_UN_INV           =  UN_INV+OP_UN_OFFSET,
    OP_UN_POS           =  UN_POS+OP_UN_OFFSET,

    OP_UN_MAX,

    OP_BI_LSH           =   BI_LSH+OP_BI_OFFSET,
    OP_BI_ILSH          =  BI_ILSH+OP_BI_OFFSET,
    OP_BI_XLSH          =  BI_XLSH+OP_BI_OFFSET,
    OP_BI_IXLSH         = BI_IXLSH+OP_BI_OFFSET,
    OP_BI_RSH           =   BI_RSH+OP_BI_OFFSET,
    OP_BI_IRSH          =  BI_IRSH+OP_BI_OFFSET,
    OP_BI_XRSH          =  BI_XRSH+OP_BI_OFFSET,
    OP_BI_IXRSH         = BI_IXRSH+OP_BI_OFFSET,
    OP_BI_AND           =   BI_AND+OP_BI_OFFSET,
    OP_BI_IAND          =  BI_IAND+OP_BI_OFFSET,
    OP_BI_SAND          =  BI_SAND+OP_BI_OFFSET,
    OP_BI_ISAND         = BI_ISAND+OP_BI_OFFSET,
    OP_BI_OR            =    BI_OR+OP_BI_OFFSET,
    OP_BI_IOR           =   BI_IOR+OP_BI_OFFSET,
    OP_BI_SOR           =   BI_SOR+OP_BI_OFFSET,
    OP_BI_ISOR          =  BI_ISOR+OP_BI_OFFSET,
    OP_BI_XOR           =   BI_XOR+OP_BI_OFFSET,
    OP_BI_IXOR          =  BI_IXOR+OP_BI_OFFSET,
    OP_BI_SXOR          =  BI_SXOR+OP_BI_OFFSET,
    OP_BI_ISXOR         = BI_ISXOR+OP_BI_OFFSET,
    OP_BI_ADD           =   BI_ADD+OP_BI_OFFSET,
    OP_BI_FADD          =  BI_FADD+OP_BI_OFFSET,
    OP_BI_LADD          =  BI_LADD+OP_BI_OFFSET,
    OP_BI_TADD          =  BI_TADD+OP_BI_OFFSET,
    OP_BI_IADD          =  BI_IADD+OP_BI_OFFSET,
    OP_BI_IFADD         = BI_IFADD+OP_BI_OFFSET,
    OP_BI_ILADD         = BI_ILADD+OP_BI_OFFSET,
    OP_BI_ITADD         = BI_ITADD+OP_BI_OFFSET,
    OP_BI_SUB           =   BI_SUB+OP_BI_OFFSET,
    OP_BI_FSUB          =  BI_FSUB+OP_BI_OFFSET,
    OP_BI_LSUB          =  BI_LSUB+OP_BI_OFFSET,
    OP_BI_TSUB          =  BI_TSUB+OP_BI_OFFSET,
    OP_BI_ISUB          =  BI_ISUB+OP_BI_OFFSET,
    OP_BI_IFSUB         = BI_IFSUB+OP_BI_OFFSET,
    OP_BI_ILSUB         = BI_ILSUB+OP_BI_OFFSET,
    OP_BI_ITSUB         = BI_ITSUB+OP_BI_OFFSET,
    OP_BI_MUL           =   BI_MUL+OP_BI_OFFSET,
    OP_BI_FMUL          =  BI_FMUL+OP_BI_OFFSET,
    OP_BI_LMUL          =  BI_LMUL+OP_BI_OFFSET,
    OP_BI_IMUL          =  BI_IMUL+OP_BI_OFFSET,
    OP_BI_IFMUL         = BI_IFMUL+OP_BI_OFFSET,
    OP_BI_ILMUL         = BI_ILMUL+OP_BI_OFFSET,
    OP_BI_MOD           =   BI_MOD+OP_BI_OFFSET,
    OP_BI_FMOD          =  BI_FMOD+OP_BI_OFFSET,
    OP_BI_LMOD          =  BI_LMOD+OP_BI_OFFSET,
    OP_BI_IMOD          =  BI_IMOD+OP_BI_OFFSET,
    OP_BI_IFMOD         = BI_IFMOD+OP_BI_OFFSET,
    OP_BI_ILMOD         = BI_ILMOD+OP_BI_OFFSET,
    OP_BI_DIV           =   BI_DIV+OP_BI_OFFSET,
    OP_BI_FDIV          =  BI_FDIV+OP_BI_OFFSET,
    OP_BI_LDIV          =  BI_LDIV+OP_BI_OFFSET,
    OP_BI_IDIV          =  BI_IDIV+OP_BI_OFFSET,
    OP_BI_IFDIV         = BI_IFDIV+OP_BI_OFFSET,
    OP_BI_ILDIV         = BI_ILDIV+OP_BI_OFFSET,

    OP_BI_MAX,

    OP_SQ_GETLEN        =    SQ_GETLEN+OP_SQ_OFFSET,
    OP_SQ_SETLEN        =    SQ_SETLEN+OP_SQ_OFFSET,
    OP_SQ_GETITEM       =   SQ_GETITEM+OP_SQ_OFFSET,
    OP_SQ_GETSLICE      =  SQ_GETSLICE+OP_SQ_OFFSET,
    OP_SQ_GETXSLICE     = SQ_GETXSLICE+OP_SQ_OFFSET,
    OP_SQ_SETITEM       =   SQ_SETITEM+OP_SQ_OFFSET,
    OP_SQ_SETSLICE      =  SQ_SETSLICE+OP_SQ_OFFSET,
    OP_SQ_SETXSLICE     = SQ_SETXSLICE+OP_SQ_OFFSET,

    OP_SQ_MAX,

    OP_MP_GETSIZE       = MP_GETSIZE+OP_MP_OFFSET,
    OP_MP_SETSIZE       = MP_SETSIZE+OP_MP_OFFSET,
    OP_MP_GETITEM       = MP_GETITEM+OP_MP_OFFSET,
    OP_MP_POPITEM       = MP_POPITEM+OP_MP_OFFSET,
    OP_MP_ADDITEM       = MP_ADDITEM+OP_MP_OFFSET,

    OP_MP_MAX,

    OP_CMP_LT           = CMP_LT+OP_CMP_OFFSET,
    OP_CMP_LE           = CMP_LE+OP_CMP_OFFSET,
    OP_CMP_EQ           = CMP_EQ+OP_CMP_OFFSET,
    OP_CMP_NE           = CMP_NE+OP_CMP_OFFSET,
    OP_CMP_GT           = CMP_GT+OP_CMP_OFFSET,
    OP_CMP_GE           = CMP_GE+OP_CMP_OFFSET,
    OP_CMP_AE           = CMP_AE+OP_CMP_OFFSET,
    OP_CMP_IN           = CMP_IN+OP_CMP_OFFSET,

    OP_CMP_MAX,

    OP_ROUND_NEAR       = ROUND_NEAR+OP_ROUND_OFFSET,
    OP_ROUND_CEIL       = ROUND_CEIL+OP_ROUND_OFFSET,
    OP_ROUND_DOWN       = ROUND_DOWN+OP_ROUND_OFFSET,
    OP_ROUND_ZERO       = ROUND_ZERO+OP_ROUND_OFFSET,
    OP_ROUND_NEXT       = ROUND_NEXT+OP_ROUND_OFFSET,

    OP_ROUND_MAX,

    OP_AS_ANY       = AS_ANY        +OP_AS_OFFSET,
    OP_AS_BYTES     = AS_BYTES      +OP_AS_OFFSET,
    OP_AS_UNICODE   = AS_UNICODE    +OP_AS_OFFSET,
    OP_AS_CHAR8     = AS_CHAR8      +OP_AS_OFFSET,
    OP_AS_CHAR16    = AS_CHAR16     +OP_AS_OFFSET,
    OP_AS_CHAR32    = AS_CHAR32     +OP_AS_OFFSET,
    OP_AS_WCHAR     = AS_WCHAR      +OP_AS_OFFSET,
    OP_AS_WINT      = AS_WINT       +OP_AS_OFFSET,
    OP_AS_BOOL      = AS_BOOL       +OP_AS_OFFSET,
    OP_AS_UCHAR     = AS_UCHAR      +OP_AS_OFFSET,
    OP_AS_USHORT    = AS_USHORT     +OP_AS_OFFSET,
    OP_AS_UINT      = AS_UINT       +OP_AS_OFFSET,
    OP_AS_ULONG     = AS_ULONG      +OP_AS_OFFSET,
    OP_AS_ULLONG    = AS_ULLONG     +OP_AS_OFFSET,
    OP_AS_UXLONG    = AS_UXLONG     +OP_AS_OFFSET,
    OP_AS_SCHAR     = AS_SCHAR      +OP_AS_OFFSET,
    OP_AS_SHORT     = AS_SHORT      +OP_AS_OFFSET,
    OP_AS_INT       = AS_INT        +OP_AS_OFFSET,
    OP_AS_LONG      = AS_LONG       +OP_AS_OFFSET,
    OP_AS_LLONG     = AS_LLONG      +OP_AS_OFFSET,
    OP_AS_XLONG     = AS_XLONG      +OP_AS_OFFSET,
    OP_AS_HALF      = AS_HALF       +OP_AS_OFFSET,
    OP_AS_FLT       = AS_FLT        +OP_AS_OFFSET,
    OP_AS_DBL       = AS_DBL        +OP_AS_OFFSET,
    OP_AS_LDBL      = AS_LDBL       +OP_AS_OFFSET,
    OP_AS_TIME      = AS_TIME       +OP_AS_OFFSET,
    OP_AS_FTIME     = AS_FTIME      +OP_AS_OFFSET,
    OP_AS_TIMESPEC  = AS_TIMESPEC   +OP_AS_OFFSET,
    OP_AS_TIMEVAL   = AS_TIMEVAL    +OP_AS_OFFSET,
    OP_AS_FILE      = AS_FILE       +OP_AS_OFFSET,
    OP_AS_DIR       = AS_DIR        +OP_AS_OFFSET,
    OP_AS_FILENAME  = AS_FILENAME   +OP_AS_OFFSET,
    OP_AS_SOCKADDR  = AS_SOCKADDR   +OP_AS_OFFSET,
    OP_AS_FILENO    = AS_FILENO     +OP_AS_OFFSET,
    OP_AS_DIRFD     = AS_DIRFD      +OP_AS_OFFSET,
    OP_AS_SOCKFD    = AS_SOCKFD     +OP_AS_OFFSET,
    OP_AS_PID       = AS_PID        +OP_AS_OFFSET,
    OP_AS_TID       = AS_TID        +OP_AS_OFFSET,

#   if _POSIX_VERSION >= 200809L

    OP_AS_UID       = AS_UID        +OP_AS_OFFSET,
    OP_AS_GID       = AS_GID        +OP_AS_OFFSET,
    
#   endif

    OP_AS_HASH      = AS_HASH       +OP_AS_OFFSET,
    OP_AS_SIZEOF    = AS_SIZEOF     +OP_AS_OFFSET,
    OP_AS_INDEX     = AS_INDEX      +OP_AS_OFFSET,
    OP_AS_FPOS      = AS_FPOS       +OP_AS_OFFSET,
    OP_AS_ABS       = AS_ABS        +OP_AS_OFFSET,

    OP_AS_MAX,
};

typedef enum {
    DTOR_UNKNOWN,   //: 0
    DTOR_AUTO,      //:
    DTOR_FREE,      //: malloc / free
    DTOR_MUNMAP,    //: mmap / munmap
    DTOR_OTHER,     //: custom malloc
    DTOR_MAX,       // TODO: change to DTOR_T_MAX
}  DTOR_T;

typedef enum {
    /* String encoding/character set ids

    These are based on the IANA MIBenum value, which
    is divided into 4 discrete ranges:
        [   0..   2] (reserved)
        [   3.. 999] Standard setters' range
        [1000..1999] Unicode's range
        [2000..2999] Vendors' range
    */
    STR_RESERVED = 0,
    STR_OTHER    = 1,
    STR_UNKNOWN  = 2,
    STR_ASCII    = 3,
    STR_LATIN1   = 4,
    STR_UTF_8    = 106,
    STR_UTF_16   = 1015,
    STR_UTF_32   = 1017,
    STR_UTF_16BE = 1013,
    STR_UTF_16LE = 1014,
    STR_UTF_32BE = 1018,
    STR_UTF_32LE = 1018,
    STR_T_MAX,
}  STR_T;

typedef enum {
    /*  Bitfield categories */
    BF_IMPL,    //  anything else
    BF_BOOL,    // "_Bool"
    BF_WORD,    // "int"
    BF_SINT,    // "signed int"
    BF_UINT,    // "unsigned"
    BF_T_MAX,
}  BF_T;

typedef enum {
    /*  Memory access category
    */
    ACC_NONE, // --c
    ACC_READ, // r--  -> "r" = read
    ACC_EXEC, // x--  -> "x" = exec
    ACC_EDIT, // rw-  -> "w" = write (replace)
    ACC_GROW, // ra-  -> "a" = append (grow)
    ACC_FULL, // rzc  -> "z" = resize, "c" = change access
    ACC_T_MAX,
}  ACC_T;

union unop {
    void *addr;
    struct timespec
        (*timeround)(const void *, ROUND_T),
        (*timeround_mode)(const void *);
};

/*
union cmp_ops {
    void *list[CMP_T_MAX];
    struct {
        bool
            (*lt)(const void *, const void *),
            (*le)(const void *, const void *),
            (*eq)(const void *, const void *),
            (*ne)(const void *, const void *),
            (*gt)(const void *, const void *),
            (*ge)(const void *, const void *),
            (*ae)(const void *, const void *),
            (*in)(const void *, const void *);
    };
};

union round_ops {
    void *list[ROUND_T_MAX];
    struct {
        void *
            (*to)       (void *, const void *, ROUND_T),
            (*floor)    (void *, const void *),
            (*trunc)    (void *, const void *),
            (*near)     (void *, const void *),
            (*next)     (void *, const void *),
            (*ceil)     (void *, const void *);
    };
};

union cast_ops {
    void *list[AS_T_MAX];
    struct {
        void *              (*as_any)       (const void *, enum REPR);
        bool                (*as_bool)      (const void *);
        char                (*as_char8)     (const void *);
        char16_t            (*as_char16)    (const void *);
        char32_t            (*as_char32)    (const void *);
        void *              (*as_bytes)     (const void *);
        void *              (*as_unicode)   (const void *);
        int8_t              (*as_int8)      (const void *);
        int16_t             (*as_int16)     (const void *);
        int32_t             (*as_int32)     (const void *);
        int64_t             (*as_int64)     (const void *);
        intmax_t            (*as_intmax)    (const void *);
        intptr_t            (*as_intptr)    (const void *);
        uint8_t             (*as_uint8)     (const void *);
        uint16_t            (*as_uint16)    (const void *);
        uint32_t            (*as_uint32)    (const void *);
        uint64_t            (*as_uint64)    (const void *);
        uintmax_t           (*as_uintmax)   (const void *);
        uintptr_t           (*as_uintptr)   (const void *);
        void *              ( as_fp16);
        float               (*as_float)     (const void *);
        double              (*as_double)    (const void *);
        ldouble_t           (*as_ldouble)   (const void *);
        double              (*as_degrees)   (const void *);
        double              (*as_radians)   (const void *);
        time_t              (*as_time)      (const void *);
        double              (*as_ftime)     (const void *);
        struct timespec     (*as_timespec)  (const void *);
        struct timeval      (*as_timeval)   (const void *);
        FILE *              (*as_file)      (const void *);
        DIR *               (*as_dir)       (const void *);
        FILENAME_T *        (*as_filename)  (const void *);
        struct sockaddr *   (*as_sockaddr)  (const void *);
        fileno_t            (*as_fileno)    (const void *);
        dirfd_t             (*as_dirfd)     (const void *);
        sockfd_t            (*as_sockfd)    (const void *);
        hash_t              (*as_hash)      (const void *);
        size_t              (*as_sizeof)    (const void *);
        ptrdiff_t           (*as_offset)    (const void *);
        off_t               (*as_fpos)      (const void *);
    };
};

struct sq_methods {
    size_t (*getlen)    (const void *);
    size_t (*setlen)    (void *, size_t);
    void * (*getitem)   (const void *, ptrdiff_t);
    void * (*getslice)  (const void *, const unslice_t *);
    void * (*getxslice) (const void *, const unslice_t *, ptrdiff_t);
    void * (*setitem)   (void *, ptrdiff_t, void *);
    void * (*setslice)  (void *, const unslice_t *, void *);
    void * (*setxslice) (void *, const unslice_t *, ptrdiff_t, void *);
};

struct mp_methods {
    size_t  (*getsize)(const void *);
    size_t  (*setsize)(void *, size_t);
    void *  (*getitem)(void *, const void *);
    void *  (*setitem)(void *, const void *, void *);
    void *  (*popitem)(void *, const void *);
};

typedef union {

    void *list[OP_COUNT];

    struct {
        int    (*un_ok)  (const void *);
        bool   (*un_not) (const void *);
        void * (*un_clr) (void *);
        void * (*un_iinc)(void *);
        void * (*un_idec)(void *);
        void * (*un_iabs)(void *);
        void * (*un_ineg)(void *);
        void * (*un_iinv)(void *);
        void * (*un_inc) (void *restrict, const void *restrict);
        void * (*un_dec) (void *restrict, const void *restrict);
        void * (*un_abs) (void *restrict, const void *restrict);
        void * (*un_neg) (void *restrict, const void *restrict);
        void * (*un_inv) (void *restrict, const void *restrict);
        void * (*un_pos) (void *restrict, const void *restrict);

        union round_ops un_round;

        void    * (*bi_lsh)   (void *, const void *, int);
        void    * (*bi_ilsh)  (void *, int);

        void    * (*bi_xlsh)  (void *, const void *, const void *);
        void    * (*bi_ixlsh) (void *, const void *);

        void    * (*bi_rsh)   (void *, const void *, int);
        void    * (*bi_irsh)  (void *, int);

        void    * (*bi_xrsh)  (void *, const void *, const void *);
        void    * (*bi_ixrsh) (void *, const void *);

        void    * (*bi_and)   (void *, const void *, unsigned);
        void    * (*bi_iand)  (void *, unsigned);
        void    * (*bi_and)   (void *, void *, void *);
        void    * (*bi_iand)  (void *, void *);

        void    * (*bi_or)    (void *, const void *, unsigned);
        void    * (*bi_ior)   (void *, unsigned);
        void    * (*bi_sor)   (void *, void *, void *);
        void    * (*bi_isor)  (void *, void *);

        void    * (*bi_xor)   (void *, const void *, unsigned);
        void    * (*bi_ixor)  (void *, unsigned);
        void    * (*bi_sxor)  (void *, void *, void *);
        void    * (*bi_isxor) (void *, void *);

        void    * (*bi_add)   (void *, const void *, const void *);
        void    * (*bi_fadd)  (void *, const void *, double);
        void    * (*bi_ladd)  (void *, const void *, long);
        void    * (*bi_iadd)  (void *, const void *);
        void    * (*bi_ifadd) (void *, double);
        void    * (*bi_iladd) (void *, long);

        void    * (*bi_sub)   (void *, const void *, const void *);
        void    * (*bi_fsub)  (void *, const void *, double);
        void    * (*bi_lsub)  (void *, const void *, long);
        void    * (*bi_isub)  (void *, const void *);
        void    * (*bi_ifsub) (void *, double);
        void    * (*bi_ilsub) (void *, long);

        void    * (*bi_mul)   (void *, const void *, const void *);
        void    * (*bi_fmul)  (void *, const void *, double);
        void    * (*bi_lmul)  (void *, const void *, long);
        void    * (*bi_imul)  (void *, const void *);
        void    * (*bi_ifmul) (void *, double);
        void    * (*bi_ilmul) (void *, long);

        void    * (*bi_mod)   (void *, const void *, const void *);
        void    * (*bi_fmod)  (void *, const void *, double);
        void    * (*bi_lmod)  (void *, const void *, long);
        void    * (*bi_imod)  (void *, const void *);
        void    * (*bi_ifmod) (void *, double);
        void    * (*bi_ilmod) (void *, long);

        undiv_t * (*div)  (undiv_t *,  const void *, const void *);
        unldiv_t* (*ldiv) (unldiv_t *, const void *, long);
        void    * (*fdiv) (void *,     const void *, double);
        void    * (*idiv) (void *,  const void *);
        void    * (*ildiv)(void *   long);
        void    * (*ifdiv)(void *,  double);

        int       (*bi_cmp)   (const void *, const void *);

        union cmp_ops cmp;
        union cast_ops unbox;

    };
} opmap_t;

    x++, x--;
    x();
    x[];
    x.y;
    x->y;
    (x){};
    ++x, --x;
    +, -;
    ~, !;
    (t) x;
    *x;
    &x
    sizeof x
    _Alignof x
    x*y, x/y, x%y;
    x+y, x-y;
    x>>y, x<<y;
    x < y, x <= y, x > y, x >= y;
    x == y, x != y;
    x & y;
    x ^ y;
    x | y;
    x && y;
    x || y;
    x ? y : z;

*/

