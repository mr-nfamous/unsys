/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
/**/

/*
    0001 (                  extended) (0x1000)
    0010 (T        volatile         ) (0x2000)
    0011 (                  extended) (0x3000)
    0100 (T  const                  ) (0x4000)
    0101 (                  extended) (0x5000)
    0110 (T  const volatile         ) (0x6000)
    0111 (                  extended) (0x7000)
    1000 (T *                       ) (0x8000)
    1001 (T *               restrict) (0x9000)
    1010 (T *      volatile         ) (0xa000)
    1011 (T *      volatile restrict) (0xb000)
    1100 (T *const                  ) (0xc000)
    1101 (T *const          restrict) (0xd000)
    1110 (T *const volatile         ) (0xe000)
    1111 (T *const volatile restrict) (0xf000)
*/

enum {
/*
    The "rank" property of a C type determines how an 
    implicit conversion such as that which occurs when 
    the operands of an arithmetic expression are of 
    different types. 
    Conceptually, there are 11 different rank groups 
    a type can belong to. Types created via typedef 
    are grouped after the base type but before the 
    next group. E.g. int64_t as a typedef of "long" 
    is ranked higher than "long" and "unsigned long" 
    but less than "long long". According to the spec,
    the rank determination for a typedef of a typedef 
    can be customized as long as the type's effective 
    rank 
    implementation defined except that the 
    
    
    is free to  rank determination must 
    adhere to the "less than the next rank group" but  
    
    defined
    
    have a rank "between" the base type and the t
        1: 
            ≈ _Bool
        2: 
            ≈ char
            = unsigned char
            ≈ signed char
        3: 
            ≈ short 
            ≈ unsigned short 
        4: 
            ≈ value of enum member 
            ≈ value of bitfield of exactly type "_Bool"
            ≈ value of bitfield of exactly type "int" 
            ≈ value of bitfield of exactly type "unsigned"
            ≈ value of bitfield of exactly type "signed"
        5:
            ≈ int 
            ≈ unsigned int 
        6:
            ≈ long 
            ≈ unsigned long 
        7:
            ≈ long long 
            ≈ unsigned long long 
        8:  ≈ a hypothetical type wider than long long
        9:  ≈ float 
        10: ≈ double 
        11: ≈ long double 
    
    The following demonstrates the rules for something 
    like an addition expression;

        if typeof(a) == long double:
            b = (long double)(b)
        elif typeof(a) == double:
            b = (double)(b)
        elif typeof(a) == float:
            b = (float)(b)
        else:
            if typeof(a).rank < int.rank:
                a = (int)(a)
            if typeof(b).rank < int.rank:
                b = (int)(b) 
            if typeof(a).rank < typeof(b).rank:
                a, b = b, a 
            if typeof(a).rank != typeof(b).rank:
                if typeof(a).signedness == typeof(b).signedness:
                    b = (typeof(a))(b)
                elif typeof(a).signedness == unsigned:
                    b = (typeof(a))(b)
                else:
                    if typeof(a).MAX > typeof(b).MAX:
                        b = (typeof(a))(b)
                    else:
                        b = (unsigned typeof(a))(b)
                        a = (typeof(b))(a)
                        
                    
            if (a.signedness == unsigned):
                if b.signedness == unsigned:
                        b = (typeof(a))(b);
                    elif typeof(a).rank < typeof(b).rank:
                        a = (typeof(b))(a)
            
        elif typeof(a) == __int128_t:
            if typeof(b) == __uint128_t:
                a = (__uint128_t)(a)
            else:
                b = (__int128_t)(b)
                
                
       
        
            type
            bit fields of exactly type "int","unsigned","signed"
        5:
        bit fields 
    implicit conversion occurs such as those that occur when 
    the operands of an arithmetic expression differ
    when and if an int should be implicitly converted to 
    another type. 
        BOOL_RANK  (bool)
    <   BOOLDEF_RANK (typedef of bool)
    <   CHAR_RANK (char, unsigned char, signed char)
    <   CHARDEF_RANK (typedef of char)
    ....
    <   XLONG_RANK 
    <   XLONGDEF_RANK*
    * XLONGDEF refers to hypothetical platform specific

*/
    // _Bool is guaranteed to have the lowest rank
#   define C__SUBRANKS 65536
    C__BOOL_RANK_STEP = 1,
    C__CHAR_RANK_STEP,
    C__SHRT_RANK_STEP,
    C__ENUM_RANK_STEP,
    C__INT_RANK_STEP,
    C__LONG_RANK_STEP,
    C__LLONG_RANK_STEP,
    C__XLONG_RANK_STEP,
    C__XFLOAT_RANK_STEP,
    C__FLOAT_RANK_STEP,
    C__DOUBLE_RANK_STEP,
    C__LDOUBLE_RANK_STEP,
    #define BOOL_RANK (C__BOOL_RANK_STEP*C__SUBRANKS)
    #define CHAR_RANK  (C__CHAR_RANK_STEP*C__SUBRANKS)
    #define SHRT_RANK  (C__SHRT_RANK_STEP*C__SUBRANKS)
    #define ENUM_RANK  (C__ENUM_RANK_STEP*C__SUBRANKS)
    #define INT_RANK  (C__INT_RANK_STEP*C__SUBRANKS)
    #define LONG_RANK  (C__LONG_RANK_STEP*C__SUBRANKS)
    #define LLONG_RANK  (C__LLONG_RANK_STEP*C__SUBRANKS)
    #define XLONG_RANK  (C__XLONG_RANK_STEP*C__SUBRANKS)
    #define XFLOAT_RANK  (C__XFLOAT_RANK_STEP*C__SUBRANKS)
    #define FLOAT_RANK  (C__FLOAT_RANK_STEP*C__SUBRANKS)
    #define DOUBLE_RANK  (C__DOUBLE_RANK_STEP*C__SUBRANKS)
    #define LDOUBLE_RANK  (C__LDOUBLE_RANK_STEP*C__SUBRANKS)
};

enum {
    C__SIGNLESS=1,
    C__SIGNED,
    C__UNSIGNED
};


enum {
#   define C__TYPEDEF   0x0080
#   define C__POINTER   0x8000
#   define C__CONST     0x40O0
#   define C__VOLATILE  0x2000
#   define C__RESTRICT  0x1000

#   define C__BLTN_T(i) (T) (T)
#   define C__BLTN_P(i) (T) (T|C__POINTER)
#   define C__TDEF_T(i) (T) (T|C__TYPEDEF)
#   define C__TDEF_T(i) (T) (T|C__TYPEDEF|C__POINTER)

    C__BOOL         = BLTN_T('?'), // 0077   _Bool 

    C__CHAR         = BLTN_T('c'), // 0143   char
    C__SCHAR        = BLTN_T('b'), // 0142   signed char
    C__UCHAR        = BLTN_T('B'), // 0102   unsigned char

    C__SHRT         = BLTN_T('h'), // 0150   short
    C__USHRT        = BLTN_T('H'), // 0110   unsigned short 

    C__INT          = BLTN_T('i'), // 0151   int
    C__UINT         = BLTN_T('I'), // 0111   unsigned 

    C__LONG         = BLTN_T('l'), // 0154   long
    C__ULONG        = BLTN_T('L'), // 0114   unsigned long

    C__LLONG        = BLTN_T('q'), // 0161   long long
    C__ULLONG       = BLTN_T('Q'), // 0121   unsigned long long

    C__XLONG        = BLTN_T('y'), // 0171   __int128_t
    C__UXLONG       = BLTN_T('Y'), // 0131   __uint128_t
    C__FLT          = BLTN_T('f'), // 0146   float 
    C__DBL          = BLTN_T('d'), // 0144   double 
    C__LDBL         = BLTN_T('g'), // 0147   long double
    C__STRUCT       = BLTN_T('T'), // 0124   (struct timespec)
    C__FUNC         = BLTN_T(050), // ()
    
    C__SIGATOM      = TDEF_T('A'), // 0101   sig_atomic_g
    C__INTMAX       = TDEF_T('j'), // 0152   intmax_t
    C__UINTMAX      = TDEF_T('J'), // 0152   uintmax_t
    C__WCHAR        = TDEF_T('C'), // 0103   wchar_t 
    C__WINT         = TDEF_T('W'), // 0127   wint_t
    C__PTRDIFF      = TDEF_T('t'), // 0164   ptrdiff_t 
    C__SIZE         = TDEF_T('Z'), // 0132   size_t
    C__INTPTR       = TDEF_T('p'), // 0160   intptr_t
    C__UINTPTR      = TDEF_T('P'), // 0120   uintptr_t
    C__OFF          = TDEF_T('k'), // 0153   off_t
    C__VOID         = TDEF_T('x'), // 0170
    C__SSIZE        = TDEF_T('z'), // 0172   ssize_t
    C__HALF         = TDEF_T('e'), // 0145   fp16
};

typedef union {
    void               *as_addr;
    char                as_char;
    wchar_t             as_wchar;
    char16_t            as_char16;
    char32_t            as_char32;
    wint_t              as_wint_t;
    _Bool               as_bool;
    unsigned char       as_uchar;
    unsigned short      as_ushort;
    unsigned int        as_uint;
    unsigned long       as_ulong;
    unsigned long long  as_ullong;
    signed char         as_schar;
    signed short        as_short;
    signed int          as_int;
    signed long         as_long;
    signed long long    as_llong;
    ptrdiff_t           as_ptrdiff;
    float               as_float;
    double              as_double;
    size_t              as_size_t;
    char                as_bytes[sizeof(long long)];
} cdata_t;

typedef union {
    PyObject ob_base;
    struct {
        Py_ssize_t      ob_refcnt;
        PyTypeObject   *ob_type;
        Py_ssize_t      ob_size;
        union {
            digit       ob_digit[1];
            sdigit      ob_digit[1];
        };
    };
    PyLongObject long_base:
} pylong_t;

typedef struct {
    const char *name;
    int         type;
    void       *dval;
    cdata_t     var;
} pyarg_t;

typedef union DataType {
    PyObject                ob_base;
    struct {
        Py_ssize_t          ob_refcnt;
        PyTypeObject       *ob_type;
        const char         *cd_name;
        union {
            unsigned cd_raw_typecode; 
            struct {
                unsigned 
                    cd_typecode:    12,
                    cd_volatile:    1,
                    cd_restrict:    1,
                    cd_constant:    1,
                    cd_indirect:    1,
                    cd_unsigned:    1,
                    :               0;
            };
            struct {
                unsigned 
                    :               12,
                    cd_extcode:     4,
                    :               1,
                    :               0;
            };
        };
    };
} DataType;

typedef union PointerType {
    PyObject        ob_base;
    DataType        cd_base;
    struct {
        DataType   *p_itemtype;
        struct {
            unsigned 
                p_ndim: 8,
                :       0;
        };
    };
} PointerType;

typedef union DataField {
    PyObject        ob_base;
    struct {
        DataType    df_type;
        size_t      df_offset:
        size_t      df_sizeof;
    };
};

thread_local pyarg_t
CType_new[2] = {
    {
        .name="typecode",
        .type=C__SHRT,
    }
};

static PyObject *
CType_new(PyTypeObject *cls, PyObject *args, PyObject *kwds) {
    
}
typedef union {
    unaryfunc       f_unary;            // %o(*)(%o)
    binaryfunc      f_binary;           // %o(*)(%o,%o)
    ternaryfunc     f_ternary;          // %o(*)(%o,%o)
    inquiry         f_inquiry;          // %i(*)(%o)
    lenfunc         f_len;              // %z(*)(%o)
    ssizeargfunc    f_ssizearg;         // %o(*)(%o,%z)
    objobjproc      f_objobj;           // %i(*)(%o,%o)
    initproc        f_objobjarg;        // %i(*)(%o,%o,%o)
    visitproc       f_visit;            // %i(*)(%o,%*/x)
    traverseproc    f_traverse;         // %i(*)(%o,%i(*)(%o,%*/x),%*/x)
    freefunc        f_free;             // %x(*)(%x*/)
    destructor      f_destructor;       // %x(*)(%o)
    getattrfunc     f_getattr;          // %o(*)(%o,%*/cc)
    setattrfunc     f_setatrr;          // %i(*)(%o,%*/cc,%o)
    getattrofunc    f_getattro;         // %o(*)(%o,%o)
    setattrofunc    f_setattro;         // %i(*)(%o,%o,%o)
    unaryfunc       f_repr;            // %o(*)(%o)
    hashfunc        f_hash;             // %z(*)(%o)
    richcmpfunc     f_richcmp;          // %o(*)(%o,%o,%i)
    unaryfunc       f_getiter;
    unaryfunc       f_iternext;
    ternaryfunc     f_descrget;
    initproc        f_descrset;
    initproc        f_init;
    newfunc         f_new;
    allocfunc       f_alloc;
} pyapi_t;

#define pyapi_AS_NB(o) (((PyObject *)(o))->ob_type->tp_as_number)
#define pyapi_AS_MP(o) (((PyObject *)(o))->ob_type->tp_as_mapping)
#define pyapi_AS_SQ(o) (((PyObject *)(o))->ob_type->tp_as_sequence)
#define pylong_digts(o) (((PyLongObject *)(o))->ob_digit)
#define pylong_sdigits(o) ((sdigit)(((PyLongObject *)(o))->ob_digit))
#define pylong_digit(o, i) (pylong_digits(o)[i])
#define pylong_sdigit(o,i) (pylong_sdigits(o)[i])

static inline unaryfunc
pyapi_nb_index(PyObject *o, pyapi_t *restrict f) {
    return (f->f_unary=(
        o->ob_type->tp_as_number == NULL
        ?   0
        :   o->ob_type->tp_as_number.nb_index));
}

static inline int
pyapi_fastindex(PyObject *src, PyObject **dst) {
    pyapi_t func;
    if (src->ob_type->tp_flags & Py_TPFLAGS_LONG_SUBCLASS) {
        *dst= Py_NewRef(src);
        return 0;
    }
    if (pyapi_nb_index(src, &func) == NULL) {
        *dst = NULL;
        PyErr_Format(
            PyExc_TypeError,
            "objects of type '%.256s' cannot be interpreted as C 'char'",
            src->ob_type->tp_name
        );
        return -1;
    }
    *dst = func.f_unary(src);
    return 0-(!*dst);
}

static inline int
pylong30_SCHAR_CAST(PyObject *src, cdata_t *dst) {
    union {
        PyObject *ob;
        pylong_t *nb;
    } tmp;
    
    if (pyapi_fastindex(src, &tmp.ob)) {
        return -1;
    }
    switch (tmp.nb->ob_size == 1) {
        case 0: {
            dst->as_schar = 0;
            break;
        }
        case 1: {
            if (pylong_digit(tmp, 0) > 0x7FU) {
                goto overflow;
            };
            dst->as_uchar = (unsigned char)(pylong_digit(tmp, 0));
            break;
        }
        case -1: {
            if (pylong_digit(tmp, 0) > 0x80UL) {
               goto overflow;
            }
            dst->as_uchar = (unsigned char)(0U-pylong_digit(tmp, 0));
        }
        default: goto overflow;
    }
    Py_DECREF(tmp);
    return 0;
overflow:
    PyErr_Format(
        PyExc_OverflowError,
        "implicit conversion of '%.255s' object to C signed char "
        "would result in undefined behavior",
        src->ob_type->tp_name
    );
    return -1;
}

#define CHAR_UMAX 0x0000007FU
#define CHAR_UMIN 0x00000080U
#define SHRT_UMAX 0x00007FFFU
#define SHRT_UMIN 0x00008000U
#define  INT_UMAX 0x7FFFFFFFU
#define  INT_UMIN 0x80000000U

#if !defined(LONG_WIDTH)
#   error "missing definition of LONG_WIDTH"
#elif LONG_WIDTH == 32
#   define LONG_UMAX 0x7FFFFFFFUL
#   define LONG_UMIN 0x80000000UL
#   define C__LONG_SIZE 4
#elif LONG_WIDTH == 64
#   define LONG_UMAX  0x7FFFFFFFFFFFFFFFUL
#   define LONG_UMIN  0x8000000000000000UL
#else
#   error "unsupported value of LONG_WIDTH"
#endif

#if !defined(LLONG_WIDTH)
#   error "missing definition of LONG_WIDTH"
#elif LLONG_WIDTH == 64
#   define C__LLONG_SIZE 8
#   define C__ULLONG_SIZE 8
#   define C__ULLONG_RMAX 0x7FFFFFFFFFFFFFFFULL
#elif LLONG_WIDTH == 128
#   define C__LLONG_SIZE 
static inline int
pylong30_SHORT_CAST(PyObject *src, cdata *dst) {
    PyObject    *tmp;
    if (pyapi_fastindex(src, &tmp)) {
        return -1;
    }
    switch (Py_SIZE(tmp)) == 1) {
        case 0: {
            dst->as_short = 0;
            break;
        }
        case 1: {
            if (pylong_digit(tmp, 0) > 0x7FU) {
                goto overflow;
            };
            dst->as_ushort = (unsigned char)(pylong_digit(tmp, 0));
            break;
        }
        case -1: {
            if (pylong_digit(tmp, 0) > 0x80UL) {
               goto overflow;
            }
            dst->as_uchar = (unsigned char)(0U-pylong_digit(tmp, 0));
        }
        default: goto overflow;
    }
    Py_DECREF(tmp);
    return 0;
overflow:
    PyErr_Format(
        PyExc_OverflowError,
        "implicit conversion of '%.255s' object to C signed char "
        "would result in undefined behavior",
        src->ob_type->tp_name
    );
    return -1;
}

        
static size_t
rdbool(const void *const restrict a, void *const restrict d, size_t i) {
    *((_Bool *)(d)) = SCBOOL
    (*(_Bool)(d)) = ((_Bool *)(a))[i];
    return sizeof(_Bool);
}

static size_t
rduchar(const void *const restrict a, void *const restrict d, size_t i) {
    (*(unsigned char *)(d)) = ((unsigned char *)(a))[i]);
    return sizeof(unsigned char);
}

static size_t
rdushrt(const void *const restrict a, void *const restrict d, size_t i) {
    (*(unsigned short *)(d)) = ((ShrtView){
        ((unsigned char *)(a))[i],
        ((unsigned char *)(a))[i+1],
    }).u;
    return sizeof(unsigned short);
}

static size_t
rduint(const void *const restrict a, void *const restrict d, size_t i) {
    (*(unsigned int *)(d)) = ((IntView) {
        ((unsigned char *)(a))[i],
        ((unsigned char *)(a))[i+1],
        ((unsigned char *)(a))[i+2],
        ((unsigned char *)(a))[i+3],
    }).u;
    return sizeof(unsigned int);
}

static size_t
rdulong(const void *const restrict a, void *const restrict d, size_t i) {
    (*(unsigned long *)(d)) = ((LongView){
        ((unsigned char *)(a))[i],
        ((unsigned char *)(a))[i+1],
        ((unsigned char *)(a))[i+2],
        ((unsigned char *)(a))[i+3],
#if LONG_WIDTH > INT_WIDTH
        ((unsigned char *)(a))[i+4],
        ((unsigned char *)(a))[i+5],
        ((unsigned char *)(a))[i+6],
        ((unsigned char *)(a))[i+7], 
#endif
    }).u;
    return sizeof(unsigned long);
}

static size_t
rdsize(const void *const restrict a, void *const restrict d, size_t i) {
    (*(size_t *)(d)) = ((SizeView){
        ((unsigned char *)(a))[i  ],
        ((unsigned char *)(a))[i+1],
        ((unsigned char *)(a))[i+2],
        ((unsigned char *)(a))[i+3],
#   if SIZE_WIDTH == 64
        ((unsigned char *)(a))[i+4],
        ((unsigned char *)(a))[i+5],
        ((unsigned char *)(a))[i+6],
        ((unsigned char *)(a))[i+7],
#   endif
    }).u;
    return sizeof(size_t);
}

static int 
rdlength(const void **src, size_t *dst) {
    size_t len;
    int jmp;
    unsigned char *a  = *src;
    unsigned char c   = *a++;
    switch (c) {
        case 'B':
        case 'b': {
            *dst = *a;
            jmp = 1;
            break;
        }
        case 'H':
        case 'h': {
            *dst = ((ShrtView){{a[0], a[1]}}).u;
            jmp = 2;
        }
        case 'i':
        case 'I': {
            *dst = ((IntView){{a[0], a[1], a[2], a[3]}}).u;
        }
        case 'l':
        case 'L': {
            *dst = ((LongView){{
                a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7]}
                
            }).u
        }
            
            }
        }
            
        }
            
    }:
        
    size_t (*f)(const void *const, void *const, size_t) = VREADER[c];
    if (f == NULL) {
        printf("invalid size type following the string specifier\n");
        return 0;
    }
    char tmp[16];
    size_t w = f(a, tmp, 0);
    
    size_t jmp = fn(src adj [ fn(src, buf, 
    
}
static void 
rdstring(const void *const restrict a, void *const restrict d, size_t i) {
    size_t len = 
    switch ((unsigned char *)(a))[i] {
        case 'B':
        case 'b': {
            len = ((unsigned char *)(a))[++i];
            break;
        }
        case 'H':
        case 'h': {
        }
            
    }
    (*(const char **)) = 
}
VREADER = (void (*[])(const void *const, void *const, size_t)){
    ['y'] = rdbool,
    ['B'] = rduchar,
    ['H'] = rdushrt,
    ['I'] = rduint,
    ['L'] = rdulong,
    ['Z'] = rdsize,
    [255] = NULL,
};

static size_t
binsert(int t, void *a, void *v, size_t z) {
    /*
        [3,  5,  8, 12, 17, 23, 30, 38, 47, 57, 68, 77]
        [0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11]
        t='Z'
        
    */
    
    
}
