#pragma once

#if LONG_BIT == 32
#   define flag_t unsigned long
#else
#    define flag_t unsigned int
#endif

union hashstate {
    struct {
        uint16_t a;
        uint32_t b;
    };
    uint64_t v;
};

typedef enum {
    /* Representation in memory of C data */
    REPR_NONE, // unrepresentable 
    REPR_MULT, // n byte scalar
    REPR_BYTE, // 1 byte scalar
    REPR_HWRD, // 2 byte scalar
    REPR_WORD, // 4 byte scalar
    REPR_DWRD, // 8 byte scalar
    REPR_QWRD, // 16 byte scalar
    REPR_XWRD, // 32 byte scalar
    REPR_FP16, // 2 bytes as IEEE 754 binary16
    REPR_FP32, // 4 bytes as IEEE 754 binary32
    REPR_FP64, // 8 bytes as IEEE 754 binary64 
    REPR_ADDR, // used for pointer, size_t, ptrdiff_t, etc
    REPR_T_MAX,
} REPR_T;

void hwdswap(void *src, size_t len) {
    unsigned char *restrict p = src;
    unsigned char q;
    for (size_t i=0; i < len; ++i, ++p) {
        q=p[1], p[1]=*p, *p++=q;
    }
}

void wdswap(void *src, size_t len) {
    unsigned char *restrict p = src;
    unsigned char q;
    for (size_t i=0; i < len; ++i, p+=3) {
        q=p[3], p[3]=*p, *p++=q;
        q=p[1], p[1]=*p, *p=q;
    }
}

void dwdswap(void *src, size_t len) {
    unsigned char *restrict p = src;
    unsigned char q;
    for (size_t i=0; i < len; ++i,p+=5) {
        q=p[7], p[7]=*p, *p++=q;
        q=p[5], p[5]=*p, *p++=q;
        q=p[3], p[3]=*p, *p++=q;
        q=p[1], p[1]=*p, *p=q;
    }
}

#if LONG_WIDTH == 32
#   define lswap wdswap
#else
#   define lswap dwdswap
#endif

typedef enum {
    /* String encoding/character set
    
    This property is based on the IANA MIBenum value
    which is divided the sets into 4 discrete ranges:
        [   0..   2] (reserved)
        [   3.. 999] Standard setter's range
        [1000..1999] Unicode 
        [2000..2999] Vendor's range 
    
    */
    STR_RESERVED=0,
    STR_OTHER       =1,
    STR_UNKNOWN     =2,
    STR_ASCII       =3,
    STR_LATIN1      =4,
    STR_UTF_8       =106,
    STR_UTF_16      =1015,
    STR_UTF_32      =1017,
    STR_UTF_16BE    =1013,
    STR_UTF_16LE    =1014,
    STR_UTF_32BE    =1018,
    STR_UTF_32LE    =1018,
    STR_T_MAX,
} STR_T;

typedef enum {
    DUR_UNKNOWN,
    DUR_AUTO,       // auto var
    DUR_STATIC,     // static var
    DUR_THRD,       // _Thread_local var
    DUR_MALLOC,     // malloc/free
    DUR_MMAP_P,     // mmap/munmap (private/anon mapping )
    DUR_MMAP_S,     // mmap/munmap (private/anon mapping )
    DUR_CUSTOM,     // 
    DUR_T_MAX,
}   DUR_T;

typedef enum {
    BF_IMPL,    //  anything else 
    BF_BOOL,    // "_Bool"
    BF_WORD,    // "int"
    BF_SINT,    // "signed"
    BF_UINT,    // "unsigned"
    BF_T_MAX,
}   BF_T;

typedef enum {
    /*
    r|x     = read < exec (exec implies read)
    w|a|z   = write < grow < resize (grow can't shrink)
    c       = change access 
    
    */
    ACC_NONE, // ---
    ACC_READ, // r--
    ACC_EXEC, // x--
    ACC_EDIT, // rw-
    ACC_GROW, // ra- 
    ACC_FULL, // rzc
    ACC_T_MAX,
}   ACC_T;

enum {
    DUR_T_WIDTH = BITLEN(DUR_T_MAX),
    STR_T_WIDTH = BITLEN(STR_T_MAX),
    REPR_T_WIDTH = BITLEN(REPR_T_MAX),
};

enum {
    String_KIND_SHIFT,
    String_DUR_SHIFT    =16+String_KIND_SHIFT,
    String_HASHED_SHIFT = 4+String_DUR_SHIFT,
    String_SIZED_SHIFT  = 1+String_HASHED_SHIFT,
    String_FIXED_SHIFT  = 1+String_SIZED_SHIFT,
    String_READY_SHIFT  = 1+String_FIXED_SHIFT,

#   define String_KIND_MASK    (0xffffU<<String_KIND_SHIFT)
#   define String_DUR_MASK     (0x0007U<<String_DUR_SHIFT)
#   define String_HASHED_MASK  (0x0001U<<String_HASHED_SHIFT)
#   define String_SIZED_MASK   (0x0001U<<String_SIZED_SHIFT)
#   define String_FIXED_MASK   (0x0001U<<String_FIXED_SHIFT)
#   define String_READY_MASK   (0x0001U<<String_READY_SHIFT)

};

union Floatv {
    double          d;
    float           f;
    unsigned char   m[sizeof(double)];
};

union Bytev {
    unsigned char   u;
    signed char     s;
    unsigned char   m[1];
    char            c[1];
};

union Shortv {
    unsigned short  u;
    signed short    s;
    union Bytev     h[2];
    unsigned char   m[2];
    char            c[2];
};

union Intv {
    unsigned int    u;
    signed int      s;
    unsigned char   m[4];
    union Shortv    h[2];
};

union Longv {
    uintmax_t       u;
    intmax_t        s;
    unsigned char   m[sizeof(intmax_t)];
    union Intv      h[sizeof(intmax_t)/4];
};

union Indexv {
    size_t          u;
    ptrdiff_t       s;
    void           *addr;
    unsigned char   m[sizeof(size_t)];
};

union Pointerv {
    void       *any;
    _Bool      *boolean;
    intptr_t    iaddr;
    uintptr_t   uaddr;
    unsigned char m[sizeof(void *)];
    union {
        unsigned char   *u;
        char16_t        *u16;
        char32_t        *u32;
        char            *b;
        signed char     *s;
        union Bytev     *x;
        wchar_t         *w;
    } c;
    union {
        short           *s;
        unsigned short  *u;
        union Shortv    *x;
    } h;
    union {
        signed          *s;
        unsigned        *u;
        union Intv      *x;
    } i;
    union {
        intmax_t        *s;
        uintmax_t       *u;
        union Longv     *x;
    } l;
    union {
        ptrdiff_t       *s;
        size_t          *u;
        union Indexv    *x;
    } z;
    union Floatv *d;
};

/*         0|0  |  1|0  |  2|0  |  3|0  |  4|0
            |       |   |   |   |   |   |   |
            B
            H—
            I——–
            P——————–

    self    P——————–    |
    opts            I——–
    refs                I——–
    type                    P——————–
    size                            L...|...
    hash                                    I...

    
*/
typedef struct UObj {
    union {
        void       *self;
        size_t      addr;
        ptrdiff_t   addr_s;
    };
    union {
        unsigned    opts;
        unsigned 
            access: 4, // [ 0.. 3], 4,
            hashed: 1, // [ 4.. 4], 5,
            closed: 1, // [ 5.. 5], 6,
            locked: 1, // [ 6.. 6], 7,
            sized:  1, // [ 7.. 7], 8,
            :       0; // [ 8..31], 
    };
    union {
        unsigned    refcnt;
        signed      refcnt_s;
    };
    union {
        struct UType   *type;
        struct UObj    *type_o;
    };
} UObj;

struct _UObjx1 {
    UObj            ob;
    unsigned char   ob_ext[sizeof(void *[1])];
};

struct _UObjx2 {
    UObj            ob;
    unsigned char   ob_ext[sizeof(void *[2])];
};

struct _UObjx12 {
    UObj            ob;
    unsigned char   ob_ext[12];
};

struct varsize {
    union {
        size_t      u;
        ptrdiff_t   s;
    } base;
    union {
        size_t      u;
        ptrdiff_t   s;
    } item;
};
union Py {
    union {
        Py_ssize_t ob_refcnt
}
static int
pylong_as_byte()
struct {
    
}
struct {
    
    void *argv[];
    
}
typedef int (*UObjCall)(void *, voi )
typedef struct {
    unsigned 
        callable: 1, // [ 0.. 0] 1      obj.type.
        hashable: 1, // [ 1.. 1] 2      
        cardinal: 1, // [ 2.. 2] 3
    union {
        u
    }
} UnInterface;

typedef struct UnType {
    UnObj               ob;
    const char         *tp_name;
    struct varsize      tp_size;
    
} UnType;

struct String {
    struct {
        unsigned        hash;
        union {
            unsigned        flags;
            struct {
                unsigned
                    sized:      1,
                    hashed:     1,
                    cmaxed:     1,
                    :           0;
            };
        };
    };
    char32_t        cmax;
    union Indexv    nchr;
    union Indexv    size;
    union Pointerv *data;
};


static inline size_t 
String_strlen(String)

struct Objectv {
    struct Typev *ob_type;
    
};

struct Arrayv {
    struct Typev *ar_type;
    
};

/*
    Bool:    ( bool )
    Byte:    
    Int:   int16_t, uint16_t, int32_t, uint32_t )
    Long:    ( int64_t, uint64_t, intmax_t, uintmax_t )
    Index:   ( size_t, off_t, ptrdiff_t              )
    Float:   ( binary16 | binary32 | binary64        )
    Char:    ( char16_t, char32_t )
    Type: 
        struct Type {
            const char *t_name;
            size_t      t_basesize;
            size_t      t_itemsize;
            ...
        };
    Array: 
        struct Array {
            struct Type *a_type;
            
        }
        Type *a_type;
        Index a_size;
        Bool  a_rdonly;
        }
    String:
        Index len
        Char data[]
        
    proc:
        .pid: (pid_t)
            [g] getpid()
        .code: (const char [])
            [s] execve(path, argv, envp)
            [s] fexecve(fd, argv, envp)
        .fds: (int[])
        .sems: (sem_t []) 
        .thrds: (thrd_t [])
            .tid: 
                [g] thrd_current()
        .flocks: (struct flock [])        
        .mmaps: (void *[])
            .mlocked 
            
                pthread_self();
                --;
            
    SEM_VALUE_MAX
    sem_*
        int 
            wait        (sem_t *); 
            trywait     (sem_t *); 
            timedwait   (sem_t *, const struct timespec *restrict abs_timeout); 
            init        (sem_t *, int, unsigned); 

C90:
    __FILE__
    __LINE__
    __DATE__
    __TIME__

C95: 
    __STDC_VERSION__ == 199409L

C99: 
    __STDC_VERSION__ == 199901L
    __STDC_HOSTED__ 
C11: 
    __STDC_VERSION__ == 201112L
C17: 
    __STDC_VERSION__ == 201710L

    __STDC_ANALYZABLE__
    __STDC_ISO_10646__ 
    __STDC_UTF_16__
    __STDC_UTF_32__
    __STDC_LIB_EXT1__
    __STDC_MB_MIGHT_NEQ_WC__
    __STDC_NO_ATOMICS__
    __STDC_NO_COMPLEX__
    __STDC_NO_THREADS__
    __STDC_NO_VLA__
    __STDC_IEC_60559_DFP__
    __STDC_IEC_60559_BFP__
    

    BITLEN(unsigned int i)
        Get an integer constant expression that evaluates 
        to the number of bits needed to represent the  
        "unsigned int" argument. Useful for bitfields 
        

*/ 
#define BITLEN(i) (           \
    i  <  0x00000010U         \
    ?   i < 0x000004U         \
        ?   i < 0x02U ? i : 2 \
        :   i < 0x08U ? 3 : 4 \
    :   i < 0x000040U         \
        ?   i < 0x20U ? 5 : 6 \
        :   i < 0x80U ? 7 : 8 )
#define BOP_LSH(a, b) ((a)<<(b))
#define BOP_RSH(a, b) ((a)>>(b))
#define BOP_ROL(a, b) (((a)<<(b))|((a)>>(CHAR_BIT*sizeof(a)-(b))))
#define BOP_ROR(a, b) (((a)<<(b))|((a)>>(CHAR_BIT*sizeof(a)-(b))))
#define BOP_OR(p, q) ((p)|(q))
#define BOP_AND(p, q) ((p)&(q))
#define BOP_XOR(p, q) ((p)^(q))
#define BOP_SUB(p, q) ((p)-(q)) 
#define BOP_ADD(p, q) ((p)+(q))
#define BOP_MUL(p, q) ((p)*(q))
#define BOP_MOD(p, q) ((p)%(q))
#define BOP_DIV(p, q) ((p)/(q))
#define BOP_DOT(p, q) ((p).q)
#define BOP_GET(v, i) ((v)[i])
#define BOP_CAST(t,v) ((t)(v))
#define UOP_NOT(n) (~(n))
#define UOP_NEG(n) (-(n))
#define UOP_POS(n) (+(n))
#define UOP_REF(v) (*(v))
#define LOP_AND(a,b) ((a) && (b))
#define LOP_OR(a, b) ((a) || (b))
#define LOP_NOR(a,b) (!((a) || (b)))
#define LOP_NOT(v) (!(v))
#define LOP_XOR(a, b) ((a)?(!(b)):(b))
#define LOP_NAND(a, b) (!((a) && (b)))
#define LOP_LT(a, b) ((a) <  (b))
#define LOP_LE(a, b) ((a) <= (b))
#define LOP_EQ(a, b) ((a) == (b))
#define LOP_NE(a, b) ((a) != (b))
#define LOP_GT(a, b) ((a) >  (b))
#define LOP_GE(a, b) ((a) >= (b))


#ifdef sprintf
#undef sprintf
#endif


#define sprintf(buf, len, ...) (_Generic(\
    (len),                              \
    size_t:     snprintf,               \
    default:    sprintf                 \
    )(buf, len, __VA_ARGS__))
