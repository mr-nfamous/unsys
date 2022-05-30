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
};

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

enum {
        UNSYS_STRUCT    = 'T',
        UNSYS_FUNC      = '@',
        UNSYS_VOID      = 'x',
        UNSYS_ADDR      = 'P',
        UNSYS_BOOL      = '?', 
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
} dtype_t;

#define dt_flags _bstate[UNSYS_DT_FLAGS]
#define dt_layout _bstate[UNSYS_DT_LAYOUT]
#define dt_format _bstate[UNSYS_DT_FORMAT]
#define dt_ndim _bstate[UNSYS_DT_NDIM]
