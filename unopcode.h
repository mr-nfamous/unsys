
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#pragma once

enum {
    REPR_VOID,      // 
    REPR_VOID_EX,   // unfinished type
    REPR_JUNK,      // the "type" of the junk between struct members 
    REPR_BOOL,      // _Bool 
    REPR_BOOL_EX,   // _Bool typedef 
    REPR_BIT,       // type of _Bool bitfield member
    // Why is this still here when we require unsigned 
    // char types?
#   if CHAR_MIN
    REPR_CHAR,    REPR_SCHAR,    REPR_UCHAR,
    REPR_CHAR_EX, REPR_SCHAR_EX, REPR_UCHAR_EX,
#   else
    REPR_SCHAR,   REPR_CHAR,    REPR_UCHAR,
    REPR_SCHAR_EX,REPR_CHAR_EX, REPR_UCHAR_EX,
#   endif
    REPR_BYTE,      // 
    REPR_USHRT,     // unsigned short
    REPR_SHRT,      // signed short
    REPR_USHRT_EX,  // unsigned short typedef
    REPR_SHRT_EX,   // signed short typedef
    REPR_UINT,      // unsigned 
    REPR_INT,       // signed 
    REPR_UINT_EX,   // unsigned typedef
    REPR_INT_EX,    // signed typedef
    REPR_ULONG,     // unsigned long
    REPR_LONG,      // signed long
    REPR_ULONG_EX,  // unsigned long typedef
    REPR_LONG_EX,   // signed long typedef
    REPR_ULLONG,    // unsigned long long 
    REPR_LLONG,     //   signed long long 
    REPR_ULLONG_EX, // unsigned long long typedef
    REPR_LLONG_EX,  //   signed long long typedef
    REPR_XINTN,     // int128_t
    REPR_XUINTN,    // uint128_t
    REPR_XINTN_EX,  // int128_t typedef
    REPR_XUINTN_EX, // uint128_t typedef
    REPR_FP16,      // 2 bytes as IEEE 754 binary16
    REPR_FP16_EX,   // 2 bytes as IEEE 754 binary16
    REPR_FP32,      // 4 bytes as IEEE 754 binary32
    REPR_FP64_EX,   // 8 bytes as IEEE 754 binary64 
#   if     SIZE_WIDTH == INT_WIDTH
#       define REPR_ADDR REPR_UINT
#       define REPR_IPTR REPR_INT
#       define REPR_UPTR REPR_UINT
#   elif   SIZE_WIDTH == LONG_WIDTH 
#       define REPR_ADDR REPR_ULONG
#       define REPR_IPTR REPR_LONG
#       define REPR_UPTR REPR_ULONG
#   else
#       define REPR_ADDR REPR_ULLONG
#       define REPR_IPTR REPR_LLONG
#       define REPR_UPTR REPR_ULLONG
#   endif 
    REPR_STRUCT,      // 
    REPR_ARRAY,
    REPR_MAX,
};

enum {
    OP_UN_SIZEOF,   // 
    OP_UN_ALIGNOF,  //
    OP_UN_ADDROF,   // box(_, x)    _ = &x
    OP_UN_UNPACK,   // ref(_, x)    _ = *x
    OP_UN_POS,      // pos(_, x)    _ = +x
    OP_UN_ABS,      // abs(_, x)    _ = abs(x)
    OP_UN_NEG,      // neg(_, x)    _ = -x
    OP_UN_INV,      // inv(_, x)    _ = ~x
    OP_UN_INC,      // inc(_, x)    _ = ++x
    OP_UN_DEC,      // dec(_, x)    _ = --x
    OP_UN_HASH,     // hash(x)      #v 
    OP_UN_LEN,      // len(x)
    OP_UN_INDEX,    // index(x)
    OP_UN_IS,       // is(x)    (_Bool) x
    OP_UN_NOT,      // not(x)   (_Bool) !x
    OP_UN_NIL,      // nil(x)
    OP_UN_RESERVED0,
};

enum {
    OP_BI_RESERVED1 = OP_UN_RESERVED0-1,
    OP_BI_LSH,      // a<<b
    OP_BI_ILSH,     // a<<=b
    OP_BI_XLSH,     // a<<<b 
    OP_BI_IXLSH,    // a<<<= b
    OP_BI_RSH,      // a>>b
    OP_BI_IRSH,     // a>>=b
    OP_BI_XRSH,     // a>>>b
    OP_BI_IXRSH,    // a>>>=b
    OP_BI_AND,      // a&b
    OP_BI_IAND,     // a&=b
    OP_BI_OR,       // a|b
    OP_BI_IOR,      // a|=b
    OP_BI_XOR,      // a^b
    OP_BI_IXOR,     // a^=b
    OP_BI_ADD,      // a+b
    OP_BI_IADD,     // a+=b
    OP_BI_SUB,      // a-b
    OP_BI_ISUB,     // a-=b
    OP_BI_MUL,      // a*b
    OP_BI_IMUL,     // a*=b
    OP_BI_LMUL,     // a*2L
    OP_BI_ILMUL,    // a*=2L
    OP_BI_FMUL,     // a*2.0
    OP_BI_IFMUL,    // a*=2.0
    OP_BI_MOD,      // a%b
    OP_BI_IMOD,     // a%=b
    OP_BI_LMOD,     // a%2L
    OP_BI_ILMOD,    // a%=2L
    OP_BI_FMOD,     // a%2.0
    OP_BI_IFMOD,    // a%=2.0
    OP_BI_DIV,      // a/b
    OP_BI_IDIV,     // a/=b
    OP_BI_LDIV,     // a/1L
    OP_BI_ILDIV,    // a/=1L
    OP_BI_FDIV,     // a/1.0
    OP_BI_IFDIV,    // a/=1.0
    OP_BI_CAST,     // (a) b
    OP_BI_GETITEM,  // a[b]
    OP_BI_CMP,      // a < b ? -1 : a != b
    OP_BI_RESERVED0,
};

enum {
    OP_CMP_RESERVED1 = OP_BI_RESERVED0-1,
    OP_CMP_LT,  // lt(a, b)     a < b
    OP_CMP_LE,  // le(a, b)     a ≤ b
    OP_CMP_EQ,  // eq(a, b)     a = b
    OP_CMP_NE,  // ne(a, b)     a ≠ b
    OP_CMP_GT,  // gt(a, b)     a > b
    OP_CMP_GE,  // ge(a, b)     a ≥ b
    OP_CMP_AE,  // ae(a, b)     a ≈ b
    OP_CMP_IN,  // in(a, b)     a in b
    OP_CMP_RESERVED0,
};

typedef enum {
    DTOR_UNKNOWN,   //: 0
    DTOR_AUTO,      //: 
    DTOR_FREE,      //: malloc / free
    DTOR_MUNMAP,    //: mmap / munmap 
    DTOR_OTHER,     //: custom malloc
    DTOR_MAX
}  DTOR_T;

typedef enum {
    /* Rounding modes        -1.7| -1.3| +1.3| +1.7 */
    ROUND_TO_PINF, // ceil : -1  | -1  | +2  | +2
    ROUND_TO_NINF, // floor: -2  | -2  | +1  | +1
    ROUND_TO_ZERO, // trunc: -1  | -1  | +1  | +1
    ROUND_TO_NEAR, // round: -2  | -1  | +1  | +2
    ROUND_TO_T_MAX,
}  ROUND_TO_T;

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

typedef 
struct {
    size_t    (*un_sizeof)(const void *);
    size_t    (*un_alignof)(const void *);
    void   ** (*un_addrof) (void **, const void *);
    void    * ( un_unpack);
    void    * (*un_pos)   (void *, const void *);
    void    * (*un_abs)   (void *, const void *);
    void    * (*un_neg)   (void *, const void *);
    void    * (*un_inv)   (void *, const void *);
    void    * (*un_inc)   (void *, const void *);
    void    * (*un_dec)   (void *, const void *);
    hash_t    (*un_hash)  (const void *);
    size_t    (*un_len)   (const void *);
    size_t    (*un_index) (const void *);
    bool      (*un_not)   (const void *);
    void    * (*bi_lsh)   (void *, const void *, int);
    void    * (*bi_ilsh)  (void *, int);
    void    * (*bi_xlsh)  (void *, const void *, const void *);
    void    * (*bi_ixlsh) (void *, const void *);
    void    * (*bi_rsh)   (void *, const void *, int);
    void    * (*bi_irsh)  (void *, int);
    void    * (*bi_xrsh)  (void *, const void *, const void *);
    void    * (*bi_ixrsh) (void *, const void *);
    void    * (*bi_and)   (void *, const void *, const void *);
    void    * (*bi_iand)  (void *, const void *);
    void    * (*bi_or)    (void *, const void *, const void *);
    void    * (*bi_ior)   (void *, const void *);
    void    * (*bi_xor)   (void *, const void *, const void *);
    void    * (*bi_ixor)  (void *, const void *);
    void    * (*bi_add)   (void *, const void *, const void *);
    void    * (*bi_iadd)  (void *, const void *);
    void    * (*bi_sub)   (void *, const void *, const void *);
    void    * (*bi_isub)  (void *, const void *);
    void    * (*bi_mul)   (void *, const void *, const void *);
    void    * (*bi_imul)  (void *, const void *);
    void    * (*bi_lmul)  (void *, const void *, long);
    void    * (*bi_ilmul) (void *, long);
    void    * (*bi_fmul)  (void *, const void *, ldouble_t);
    void    * (*bi_ifmul) (void *, ldouble_t);
    void    * (*bi_mod)   (void *, const void *);
    void    * (*bi_imod)  (void *, const void *);
    void    * (*bi_lmod)  (void *, const void *, long);
    void    * (*bi_ilmod) (void *, long);
    void    * (*bi_fmod)  (void *, const void *, long double);
    void    * (*bi_ifmod) (void *, long double);
    long      (*bi_div)   (void *, const void *, const void *);
    long      (*bi_idiv)  (void *, const void *);
    void    * (*bi_ldiv)  (void *, const void *, long);
    void    * (*bi_ildiv) (void *, long);
    ldouble_t (*bi_fdiv)  (void *, const void *, ldouble_t);
    ldouble_t (*bi_ifdiv) (void *, ldouble_t);
    void    * (*bi_getitem)(void *, const void *, size_t);
    int       (*bi_cmp)   (const void *, const void *);
    bool      (*cmp_lt)   (const void *, const void *);
    bool      (*cmp_le)   (const void *, const void *);
    bool      (*cmp_eq)   (const void *, const void *);
    bool      (*cmp_ne)   (const void *, const void *);
    bool      (*cmp_gt)   (const void *, const void *);
    bool      (*cmp_ge)   (const void *, const void *);
    bool      (*cmp_ae)   (const void *, const void *);
    bool      (*cmp_is)   (const void *, const void *);
    bool      (*cmp_in)   (const void *, const void *);
}   oplist_t;

/*
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