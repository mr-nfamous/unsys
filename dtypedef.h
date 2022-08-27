/*  |**************************************************************************/
#pragma once

#if !defined(UNSYS_BIG_ENDIAN)
#   error "UNSYS_BIG_ENDIAN must be defined at compile time"
#elif  UNSYS_BIG_ENDIAN
#   define UNSYS_IS_LE 0
#   define UNSYS_IS_BE 1
#else
#   define UNSYS_IS_LE 1
#   define UNSYS_IS_BE 0
#endif

#include <inttypes.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

typedef union charview {
    uint8_t     b[1];
    uint8_t     u;
    int8_t      s;
} CharView;

typedef union shortview {
    uint8_t     b[2];
    uint16_t    h[1];
    uint16_t    u;
    int16_t     s;
    CharView    cv[2];
} ShortView;

typedef union intview {
    uint8_t     b[4];
    uint16_t    h[2];
    uint32_t    i[1];
    uint32_t    u;
    int32_t     s;
    CharView    cv[4];
    ShortView   hv[2];
} IntView;

typedef union longview {
    uint8_t     b [8];
    CharView    cv[8];
    uint16_t    h [4];
    ShortView   hv[4];
    uint32_t    i [2];
    IntView     iv[2];
    uint64_t    q [1];
    uint64_t    u;
    int64_t     s;
    uintmax_t   x;
} LongView;

typedef union floatview {
    uint8_t     b[4];
    float       f;
    uint32_t    u;
    int32_t     s;
} FloatView;

typedef union doubleview {
    uint8_t     b[8];
    float       d;
    uint64_t    u;
    int64_t     s;
} DoubleView;

typedef union ptrview {
    void        *addr;
    uintptr_t   uint;
    _Bool       *bint;  
    char        *c;
    wchar_t     *w;
    uint8_t     *u8;
    uint16_t    *u16;
    uint32_t    *u32;
    uint64_t    *u64;
    uintmax_t   *umax;
    size_t      *usz;
    int8_t      *s8;
    int16_t     *s16;
    int32_t     *s32;
    int64_t     *s64;
    intmax_t    *smax;
    ssize_t     *ssz;
    float       *flt;
    double      *dbl;
} ptrview_t;

typedef union pyindex {
    ssize_t     s;
    size_t      u; 
    int         i;
} pyindex_t;

#define UNSYS_DTYPE {\
    uint8_t dt_layout;  \
    uint8_t dt_flags;   \
    uint8_t dt_format;  \
    uint8_t dt_ndim;    }

enum {
    UNSYS_DT_LAYOUT_LE,
    UNSYS_DT_FLAGS_LE,
    UNSYS_DT_FORMAT_LE,
    UNSYS_DT_NDIM_LE,
};

enum {
    UNSYS_DT_LAYOUT_BE  = 7-(4+UNSYS_DT_LAYOUT_LE),
    UNSYS_DT_FLAGS_BE   = 7-(4+UNSYS_DT_FLAGS_LE),
    UNSYS_DT_FORMAT_BE  = 7-(4+UNSYS_DT_FORMAT_LE),
    UNSYS_DT_NDIM_BE    = 7-(4+UNSYS_DT_NDIM_LE),

#if (UNSYS_IS_LE > 0)
#   define UNSYS_DT_LAYOUT UNSYS_DT_LAYOUT_LE
#   define UNSYS_DT_FLAGS  UNSYS_DT_FLAGS_LE
#   define UNSYS_DT_FORMAT UNSYS_DT_FORMAT_LE
#   define UNSYS_DT_NDIM   UNSYS_DT_NDIM_LE
#else
#   define UNSYS_DT_LAYOUT UNSYS_DT_LAYOUT_BE
#   define UNSYS_DT_FLAGS  UNSYS_DT_FLAGS_BE
#   define UNSYS_DT_FORMAT UNSYS_DT_FORMAT_BE
#   define UNSYS_DT_NDIM   UNSYS_DT_NDIM_BE
#endif
};

enum {
        UNSYS_STRUCT    = 'T',
        UNSYS_FUNC      = '@',
        UNSYS_VOID      = 'x',
        UNSYS_ADDR      = 'P',
        UNSYS_BOOL      = '?',
        UNSYS_MASK      = ':',
        UNSYS_UCHAR     = 'B', // UCHAR_MAX
        UNSYS_USHORT    = 'H', // USHRT_MAX
        UNSYS_UINT      = 'I', // UINT_MAX
        UNSYS_ULONG     = 'L', // ULONG_MAX
        UNSYS_ULLONG    = 'Q', // ULLONG_MAX
        UNSYS_SCHAR     = 'b', // SCHAR_MAX,    SCHAR_MIN
        UNSYS_SHORT     = 'h', // SHORT_MAX,    SHORT_MIN
        UNSYS_INT       = 'i', // INT_MAX,      INT_MIN
        UNSYS_LONG      = 'l', // LONG_MAX,     LONG_MIN
        UNSYS_LLONG     = 'q', // LLONG_MAX,    LLONG_MIN 
        UNSYS_CHAR      = 'c', // CHAR_MAX,     CHAR_MIN
        UNSYS_WCHAR     = 'u', // WCHAR_MAX,    WCHAR_MIN
        UNSYS_FLOAT     = 'f', // 
        UNSYS_DOUBLE    = 'd', //
#define UNSYS_BOOL      UNSYS_BOOL
#define UNSYS_UCHAR     UNSYS_UCHAR
#define UNSYS_USHORT    UNSYS_USHORT
#define UNSYS_UINT      UNSYS_UINT
#define UNSYS_ULONG     UNSYS_ULONG
#define UNSYS_ULLONG    UNSYS_ULLONG
#define UNSYS_SCHAR     UNSYS_SCHAR
#define UNSYS_SHORT     UNSYS_SHORT
#define UNSYS_INT       UNSYS_INT
#define UNSYS_LONG      UNSYS_LONG
#define UNSYS_LLONG     UNSYS_LLONG
#define UNSYS_CHAR      UNSYS_CHAR
#define UNSYS_WCHAR     UNSYS_WCHAR
#define UNSYS_FLOAT     UNSYS_FLOAT
#define UNSYS_DOUBLE    UNSYS_DOUBLE

#define UNSYS_UINT8     UNSYS_UCHAR
#define UNSYS_UINT16    UNSYS_USHORT 
#define UNSYS_UINT32    UNSYS_UINT
#define UNSYS_INT8      UNSYS_CHAR
#define UNSYS_INT16     UNSYS_SHORT 
#define UNSYS_INT32     UNSYS_INT

#if (_POSIX_V7_ILP32_OFF32 > 0)

#   define UNSYS_OFF       UNSYS_INT
#   define UNSYS_PTRDIF    UNSYS_INT
#   define UNSYS_SSIZE     UNSYS_INT
#   define UNSYS_SIZE      UNSYS_UINT
#   define UNSYS_UINT64    UNSYS_ULLONG
#   define UNSYS_INT64     UNSYS_LLONG
#   define UNSYS_INTMAX    UNSYS_LLONG
#   define UNSYS_UINTMAX   UNSYS_ULLONG      

#elif (_POSIX_V7_ILP32_OFFBIG > 0)

#   define UNSYS_OFF       UNSYS_LLONG
#   define UNSYS_PTRDIF    UNSYS_INT
#   define UNSYS_SSIZE     UNSYS_INT
#   define UNSYS_SIZE      UNSYS_UINT
#   define UNSYS_UINT64    UNSYS_ULLONG
#   define UNSYS_INT64     UNSYS_LLONG
#   define UNSYS_INTMAX    UNSYS_LLONG
#   define UNSYS_UINTMAX   UNSYS_ULLONG

#elif (_POSIX_V7_LP64_OFF64 > 0)

#   define UNSYS_OFF       UNSYS_LONG
#   define UNSYS_PTRDIF    UNSYS_LONG
#   define UNSYS_SSIZE     UNSYS_LONG
#   define UNSYS_SIZE      UNSYS_ULONG
#   define UNSYS_UINT64    UNSYS_ULONG
#   define UNSYS_INT64     UNSYS_LONG
#   define UNSYS_INTMAX    UNSYS_LONG
#   define UNSYS_UINTMAX   UNSYS_ULONG

#elif (_POSIX_V7_LPBIG_OFFBIG > 0)

#   error "unsupported data model: _POSIX_V7_LPBIG_OFFBIG"

#else

#   error "unknown data model: missing <unistd.h>?"

#endif

};

static const uint8_t
UNSYS_BITMASK_MAX[256] = {
    [UNSYS_BOOL]    = 8,
    [UNSYS_SCHAR]   = 8,
    [UNSYS_UCHAR]   = 8,
    [UNSYS_SHORT]   = 16,
    [UNSYS_USHORT]  = 16,
    [UNSYS_INT]     = 32,
    [UNSYS_UINT]    = 32,
};

static const uint8_t 
UNSYS_BASICSIZE[256] = {
    [UNSYS_VOID]    = 1,
    [UNSYS_ADDR]    = (uint8_t) sizeof(size_t),
    [UNSYS_BOOL]    = (uint8_t) sizeof(_Bool),
    [UNSYS_CHAR]    = (uint8_t) sizeof(char),
    [UNSYS_WCHAR]   = (uint8_t) sizeof(wchar_t),
    [UNSYS_FLOAT]   = (uint8_t) sizeof(float),
    [UNSYS_DOUBLE]  = (uint8_t) sizeof(double), 
    [UNSYS_UCHAR]   = (uint8_t) sizeof(unsigned char),
    [UNSYS_USHORT]  = (uint8_t) sizeof(unsigned short int),
    [UNSYS_UINT]    = (uint8_t) sizeof(unsigned int),
    [UNSYS_ULONG]   = (uint8_t) sizeof(unsigned long int),
    [UNSYS_ULLONG]  = (uint8_t) sizeof(unsigned long long int),
    [UNSYS_SCHAR]   = (uint8_t) sizeof(signed char),
    [UNSYS_SHORT]   = (uint8_t) sizeof(signed short int),
    [UNSYS_INT]     = (uint8_t) sizeof(signed int),
    [UNSYS_LONG]    = (uint8_t) sizeof(signed long int),
    [UNSYS_LLONG]   = (uint8_t) sizeof(signed long long int),
};

static const uint8_t
DT_LAYOUT_REPR[256][16] = {
    [UNSYS_VOID]    = "'x'",
    [UNSYS_ADDR]    = "'P'",
    [UNSYS_BOOL]    = "'?'",
    [UNSYS_CHAR]    = "'c'",
    [UNSYS_WCHAR]   = "'u'",
    [UNSYS_FLOAT]   = "'f'",
    [UNSYS_DOUBLE]  = "'d'", 
    [UNSYS_UCHAR]   = "'B'",
    [UNSYS_USHORT]  = "'h'",
    [UNSYS_UINT]    = "'U'",
    [UNSYS_ULONG]   = "'L'",
    [UNSYS_ULLONG]  = "'Q'",
    [UNSYS_SCHAR]   = "'b'",
    [UNSYS_SHORT]   = "'h'",
    [UNSYS_INT]     = "'i'",
    [UNSYS_LONG]    = "'l'",
    [UNSYS_LLONG]   = "'q'",
};

typedef 
struct dtype {

// C type qualifiers & forced big endian (dtype.dt_flags)
#   define UNSYS_VOLATILE   0x01
#   define UNSYS_CONSTANT   0x02
#   define UNSYS_BIGENDIAN  0x80

// for dtype.dt_format
#   define UNSYS_VALUE          0b00000000
#   define UNSYS_INDIRECT       0b00000001
#   define UNSYS_POINTER        0b00000011
#   define UNSYS_ADDRESS        0b00000111
#   define UNSYS_ARRAY          0b00001001
#   define UNSYS_POINTER_ARRAY  0b00001101
#   define UNSYS_BITFIELD_TYPE  0b00110001
#   define UNSYS_BITFIELD_NEXT  0b00010001
#   define UNSYS_BITFIELD_STOP  0b00100001
#   define dt_flags    _bstate[UNSYS_DT_FLAGS]
#   define dt_layout   _bstate[UNSYS_DT_LAYOUT]
#   define dt_format   _bstate[UNSYS_DT_FORMAT]
#   define dt_ndim     _bstate[UNSYS_DT_NDIM]
    union {
        struct UNSYS_DTYPE;
        uint8_t  _bstate[4];
        uint32_t _ustate;
        int32_t  _sstate;
    };
    union {
        struct {
            uint32_t    dt_bitmask;
            uint8_t     dt_bitshift;
        };
        pyindex_t       dt_length;
    };
    pyindex_t           dt_offset;
    struct dtype       *dt_element;
/*
    UNSYS_VALUE:
        ndim = 0 
        length = 1 
        element = NULL
    UNSYS_INDIRECT:
        int [1] (ndim=1, dt_length=1)
        int*[1] (ndim=2, dt_length=1)
        int:1   (ndim=1, bitmask=0b1, bitshift=0, length=0)
        
*/
} dtype_t;

static struct dtype 
DTYPE_BASE[128] = {
    [UNSYS_ADDR]    = {
        .bstate={[UNSYS_DT_LAYOUT] = UNSYS_ADDR}, 
        .dt_length = 1,
    },
    [UNSYS_BOOL]    = {
        .bstate={[UNSYS_DT_LAYOUT] = UNSYS_BOOL}, 
        .dt_length = 1,
    },
    [UNSYS_CHAR]    = {
        .bstate={[UNSYS_DT_LAYOUT] = UNSYS_CHAR}, 
        .dt_length = 1,
    },
    [UNSYS_WCHAR]   = {
        .bstate={[UNSYS_DT_LAYOUT] = UNSYS_WCHAR}, 
        .dt_length = 1,
    },
    [UNSYS_SCHAR]   = {
        .bstate={[UNSYS_DT_LAYOUT] = UNSYS_SCHAR}, 
        .dt_length = 1,
    },
    [UNSYS_UCHAR]   = {
        .bstate={[UNSYS_DT_LAYOUT] = UNSYS_UCHAR},
        .dt_length = 1,
    },
    [UNSYS_USHORT]  = {
        .bstate={[UNSYS_DT_LAYOUT] = UNSYS_USHORT},
        .dt_length = 1,
    },
    [UNSYS_UINT]    = {
        .bstate={[UNSYS_DT_LAYOUT] = UNSYS_UINT},
        .dt_length = 1,
    },
    [UNSYS_ULONG]   = {
        .bstate={[UNSYS_DT_LAYOUT] = UNSYS_ULONG},
        .dt_length = 1,
    },
    [UNSYS_ULLONG]  = {
        .bstate={[UNSYS_DT_LAYOUT] = UNSYS_ULLONG},
        .dt_length = 1,
    },
    [UNSYS_SHORT]   = {
        .bstate={[UNSYS_DT_LAYOUT] = UNSYS_SHORT},
        .dt_length = 1,
    },
    [UNSYS_INT]     = {
        .bstate={[UNSYS_DT_LAYOUT] = UNSYS_INT},
        .dt_length = 1,
    },
    [UNSYS_LONG]    = {
        .bstate={[UNSYS_DT_LAYOUT] = UNSYS_LONG},
        .dt_length = 1,
    },
    [UNSYS_LLONG]   = {
        .bstate={[UNSYS_DT_LAYOUT] = UNSYS_LLONG},
        .dt_length = 1,
    },
}
static const uintmax_t 
DECMAX[] ={
    1,                      // 0
    10,                     // 1
    100,                    // 2
    1000,                   // 3
    10000,                  // 4
    100000,                 // 5
    1000000,                // 6
    10000000,               // 7
    100000000,              // 8
    1000000000,             // 9
    10000000000,            // 10
    100000000000,           // 11
    1000000000000,          // 12
    10000000000000,         // 13
    100000000000000,        // 14
    1000000000000000,       // 15
    10000000000000000,      // 16
    100000000000000000,     // 17
    1000000000000000000,    // 18
};

size_t 
uintmax_bisearch(const uintmax_t *a, uintmax_t v, size_t i, size_t k) {
    size_t j;
    while (i < k) {
        j = (i+k)>>1;
        if (v < a[j])
            k = j;
        else 
            i = j+1;
    }
    return i;
}

static size_t 
ndecdigits(intmax_t n, int s) {
    size_t d;
    if (n < 0)
        n = ~n+1, d = 1;
    else 
        d = s != 0;
    if (n >= 1000000000000000000)
        return d+19;
    if (n)
        return d+uintmax_bisearch(DECMAX, (uintmax_t)n, 0, sizeof(DECMAX)/8);
    return d+1;
}

