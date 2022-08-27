/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

#pragma once

#include "unthrd.h"

enum typecode {
    C__BOOL     = 'Y',
    C__CHAR     = 'c',  C__WCHAR    = 'C',
    C__CHAR16   = 'u',  C__CHAR32   = 'U',
    C__SCHAR    = 'b',  C__UCHAR    = 'B',
    C__SHORT    = 'h',  C__USHORT   = 'H',
    C__INT      = 'i',  C__UINT     = 'I',
    C__LONG     = 'l',  C__ULONG    = 'L',
    C__LLONG    = 'q',  C__ULLONG   = 'Q',
    C__INTMAX   = 'j',  C__UINTMAX  = 'J',
    C__INTPTR   = 'p',  C__UINTPTR  = 'P',
    C__PTRDIFF  = 't',
    C__ADDR     = 'x',
    C__HALF     = 'g',
    C__FLT      = 'f',
    C__DBL      = 'd',
    C__LDBL     = 'e',
    C__SIZE     = 'z',
    C__URANGE   = '\x80',
#   define C__INT8        C__SCHAR
#   define C__UINT8       C__UCHAR
#   define C__INT16       C__SHORT
#   define C__UINT16      C__USHORT
#   define C__INT32       C__INT
#   define C__UINT32      C__UINT
#   if LONG_MAX > INT_MAX
#       define C__INT64   C__LONG
#       define C__UINT64  C__ULONG
#       define C__TIME    C__LONG
#   else
#       define C__UINT64  C__LLONG
#       define C__UINT64  C__ULLONG 
#       define C__TIME    C__LLONG
#   endif
};
#define Array_STRINGIFY(x) #x

#define REPR_NAMES(x) [C__##x] = Array_STRINGIFY(C__##x)

static const char *REPR_NAME[] = {
    REPR_NAMES(BOOL),
    REPR_NAMES(CHAR),   REPR_NAMES(WCHAR),
    REPR_NAMES(CHAR16), REPR_NAMES(CHAR32),
    REPR_NAMES(SCHAR),  REPR_NAMES(UCHAR),
    REPR_NAMES(SHORT),  REPR_NAMES(USHORT),
    REPR_NAMES(INT),    REPR_NAMES(UINT),
    REPR_NAMES(LONG),   REPR_NAMES(ULONG),
    REPR_NAMES(LLONG),  REPR_NAMES(ULLONG),
    REPR_NAMES(INTMAX), REPR_NAMES(UINTMAX),
    REPR_NAMES(INTPTR), REPR_NAMES(UINTPTR),
    REPR_NAMES(PTRDIFF),REPR_NAMES(SIZE),
    REPR_NAMES(ADDR),   
    REPR_NAMES(HALF),
    REPR_NAMES(FLT),
    REPR_NAMES(DBL),
    REPR_NAMES(LDBL),
    REPR_NAMES(URANGE),
};
#undef REPR_NAMES

typedef union {
    void                *x;
    char                *c;
    char               **s;
    wchar_t             *C;
    wchar_t            **S;
    char16_t            *u;
    char32_t            *U;
    _Bool               *Y;
    ptrdiff_t           *t;
    size_t              *z;
    signed   char       *b;
    signed   short      *h;
    signed   int        *i;
    signed   long       *l;
    signed   long long  *q;
    intmax_t            *j;
    unsigned char       *B;
    unsigned short      *H;
    unsigned int        *I;
    unsigned long       *L;
    unsigned long long  *Q;
    uintmax_t           *J;
    float               *f;
    double              *d;
    long double         *D;
    intptr_t            *p;
    uintptr_t           *P;
}   ptr_t;

typedef 
struct Array {
    ptr_t           data;
    size_t          used;
    size_t          size;
    enum typecode   type;
    SRWLock         lock;
}   Array;

Array * Array_new    (enum typecode, size_t);
void    Array_destroy(Array *);
Array * Array_append (Array *,            const void *);
Array * Array_insert (Array *,    size_t, const void *);
void *  Array_getitem(Array *, ptrdiff_t,       void *);
Array * Array_delitem(Array *, ptrdiff_t,       void *);
Array * Array_setitem(Array *, ptrdiff_t, const void *);

static 
const signed char Struct_ALIGN[128] = {
    [C__BOOL]     = sizeof(_Bool),
    [C__CHAR]     = sizeof(char),
    [C__WCHAR]    = sizeof(wchar_t),
    [C__CHAR16]   = sizeof(char16_t),
    [C__CHAR32]   = sizeof(char32_t),
    [C__SCHAR]    = sizeof(signed char),
    [C__UCHAR]    = sizeof(unsigned char),
    [C__SHORT]    = sizeof(signed short),
    [C__USHORT]   = sizeof(unsigned short),
    [C__INT]      = sizeof(signed int),
    [C__UINT]     = sizeof(unsigned int),
    [C__LONG]     = sizeof(signed long),
    [C__ULONG]    = sizeof(unsigned long),
    [C__LLONG]    = sizeof(signed long long),
    [C__ULLONG]   = sizeof(unsigned long long),
    [C__INTMAX]   = sizeof(intmax_t),
    [C__UINTMAX]  = sizeof(uintmax_t),
    [C__INTPTR]   = sizeof(intptr_t),
    [C__UINTPTR]  = sizeof(uintptr_t),
    [C__SIZE]     = sizeof(size_t),
    [C__ADDR]     = sizeof(void *),
    [C__PTRDIFF]  = sizeof(ptrdiff_t),
    [C__FLT]      = sizeof(float),
    [C__DBL]      = sizeof(double),
    [C__LDBL]     = sizeof(long double),
};

static 
const unsigned *Struct_SIZE = (const unsigned[128]){
    [C__BOOL]     = sizeof(_Bool),
    [C__CHAR]     = sizeof(char),
    [C__WCHAR]    = sizeof(wchar_t),
    [C__CHAR16]   = sizeof(char16_t),
    [C__CHAR32]   = sizeof(char32_t),
    [C__SCHAR]    = sizeof(signed char),
    [C__UCHAR]    = sizeof(unsigned char),
    [C__SHORT]    = sizeof(signed short),
    [C__USHORT]   = sizeof(unsigned short),
    [C__INT]      = sizeof(signed int),
    [C__UINT]     = sizeof(unsigned int),
    [C__LONG]     = sizeof(signed long),
    [C__ULONG]    = sizeof(unsigned long),
    [C__LLONG]    = sizeof(signed long long),
    [C__ULLONG]   = sizeof(unsigned long long),
    [C__INTMAX]   = sizeof(intmax_t),
    [C__UINTMAX]  = sizeof(uintmax_t),
    [C__INTPTR]   = sizeof(intptr_t),
    [C__UINTPTR]  = sizeof(uintptr_t),
    [C__SIZE]     = sizeof(size_t),
    [C__ADDR]     = sizeof(void *),
    [C__PTRDIFF]  = sizeof(ptrdiff_t),
    [C__FLT]      = sizeof(float),
    [C__DBL]      = sizeof(double),
    [C__LDBL]     = sizeof(long double),
};



static inline void *
Array_GET_LOCK(Array *array) {
    return    &array->lock;
}

static inline int
Array_RDLOCK(Array *array) {
    return SRWLock_acquiresh(Array_GET_LOCK(array));
//    return pthread_rwlock_rdlock(Array_GET_LOCK(array));
}

static inline int
Array_WRLOCK(Array *array) {
    return SRWLock_acquireex(Array_GET_LOCK(array));
   // return pthread_rwlock_wrlock(Array_GET_LOCK(array));
}

static inline int
Array_WRUNLOCK(Array *array) {
    return SRWLock_releaseex(Array_GET_LOCK(array));
}

static inline int
Array_RDUNLOCK(Array *array) {
    return SRWLock_releasesh(Array_GET_LOCK(array));
}

static inline enum typecode 
Array_GET_TYPE(Array *array) {
    assert((0 <= array->type) && (array->type < 128));
    assert(Struct_SIZE[array->type] > 0);
    return     array->type;
}

static inline const char *
Array_GET_TYPE_NAME(Array *array) {
    return REPR_NAME[Array_GET_TYPE(array)];
}

static inline void
Array_SET_TYPE(Array *array, enum typecode type) {
    array->type = type;
}

static inline size_t
Array_GET_USED(Array *array) {
    return     array->used;
}

static inline void
Array_SET_USED(Array *array, size_t used) {
    array->used = used;
}

static inline size_t
Array_PREFINC_USED(Array *array) {
    return ++array->used;
}

static inline size_t
Array_PREFDEC_USED(Array *array) {
    return --array->used;
}

static inline size_t 
Array_POSTINC_USED(Array *array) {
    return array->used++;
}

static inline size_t
Array_POSTDEC_USED(Array *array) {
    return array->used--;
}

static inline size_t
Array_GET_SIZE(Array *array) {
    return     array->size;
}

static inline void
Array_SET_SIZE(Array *array, size_t size) {
    array->size = size;
}

static inline unsigned
Array_GET_ITEMSIZE(Array *array) {
    return Struct_SIZE[Array_GET_TYPE(array)];
}

static inline size_t
Array_GET_NBYTES(Array *array) {
    return Array_GET_ITEMSIZE(array)*Array_GET_SIZE(array);
}

static inline ptr_t
Array_GET_POINTER(Array *array) {
    return array->data;
}

static inline void *
Array_GET_DATA(Array *array) {
    return array->data.x;
}

static inline void
Array_SET_DATA(Array *array, void *data) {
    array->data.x = data;
}

static inline ptrdiff_t
Array_REPR(Array *array, FILE *dst) {
    if (dst == NULL) {
        dst = stdout;
    }
    ptrdiff_t r = 0;
    int n = fprintf(dst, "(Array){");
    if (n < 0) {
        return n;
    }
    r += n; 
    if ((n=fprintf(dst, ".addr=%p, ", Array_GET_DATA(array))) < 0) {
        return n;
    }
    r += n;
    if ((n=fprintf(dst, ".used=%zu, ", Array_GET_USED(array))) < 0) {
        return n;
    }
    r += n;
    if ((n=fprintf(dst, ".size=%zu, ", Array_GET_SIZE(array))) < 0) {
        return n;
    }
    r += n;
    if ((n=fprintf(dst, ".type=%s, ", Array_GET_TYPE_NAME(array))) < 0) {
        return n;
    }
    r += n;
    if ((n=fprintf(dst, "}")) < 0) {
        return n;
    }
    return r+n;
}   

static inline void *
Array_GET_END(Array *array) {
    size_t end = Array_GET_USED(array)*Array_GET_ITEMSIZE(array);
    return Array_GET_DATA(array)+end;
}

static inline void *
Array_RESIZE_DATA(Array *array, size_t size, bool zero) {
    void *data = Array_GET_DATA(array);
    if (size  == Array_GET_SIZE(array)) {
        return data;
    }
    assert(Array_GET_USED(array) < size);
    const size_t isize = Array_GET_ITEMSIZE(array);
    const size_t nbytes = size*isize;
    data = realloc(data, nbytes);
    Array_SET_DATA(array, data);
    assert(data != NULL);
    if (zero) {
        unsigned char *dst = Array_GET_END(array);
        unsigned char *end = data+nbytes;
        do {*dst++ = 0;} while (dst < end);
    }
    Array_SET_SIZE(array, size);
    return data;
}

static inline void *
Array_CLEAR_DATA(Array *array) {
    return memset(Array_GET_DATA(array), 0, Array_GET_NBYTES(array));
}

static inline ptrdiff_t
Array_CHECK_INDEX(Array *restrict a, ptrdiff_t *restrict i) {
    const ptrdiff_t used = (ptrdiff_t) Array_GET_USED(a);
    if (*i < PTRDIFF_C(0)) {
        *i += used;
        if (*i < PTRDIFF_C(0)) {
            index_error: {
                errno = ERANGE;
                return *i;
            }
        }
    }
    else {
        if (*i >= used) {
            *i = PTRDIFF_C(0)-1;
            goto index_error;
        }
    }
    return *i;
}

static inline Array *
Array_APPEND(Array *array, const void *value) {
    const size_t size = Array_GET_SIZE(array);
    const size_t used = Array_GET_USED(array)+1;
    const size_t item = Array_GET_ITEMSIZE(array);
    if (used == size) {
        if (Array_RESIZE_DATA(array, size<<1, false) == NULL) {
            perror("Array_RESIZE_DATA returnd null");
            exit(EXIT_FAILURE);
        }
    }
    if (memmove(Array_GET_END(array), value, item) == NULL) {
        perror("memmove returned null"), exit(EXIT_FAILURE);
    }
    Array_SET_USED(array, used);
    return array;
}

static inline Array *
Array_INSERT(Array *array, size_t index, const void *value) {
    const size_t tail = Array_GET_USED(array);
    if (index >= tail) {
        return Array_APPEND(array, value);
    }
    const size_t item = Array_GET_ITEMSIZE(array);
    const size_t used = (tail+1);
    void *data = Array_GET_DATA(array);
    if (used  == Array_GET_SIZE(array)) {
        data  =  Array_RESIZE_DATA(array, Array_GET_SIZE(array)<<1, true);
        if (data == NULL) {
            return  NULL;
        }
    }
    size_t pos = item*index;
    size_t end = item*tail;
    void *src = data+pos;
    void *dst = src+item;
    if (memmove(dst, src, end-pos) == NULL) {
        return NULL;
    }
    if (memcpy(src, value, item) == NULL) {
        return NULL;
    }
    Array_SET_USED(array, used);
    return array;
}

static inline void *
Array_GET(Array *array, ptrdiff_t index) {
    return (Array_CHECK_INDEX(array, &index) < PTRDIFF_C(0))
        ?   NULL
        :   Array_GET_DATA(array)+Array_GET_ITEMSIZE(array)*index;
}

static inline Array *
Array_SET(Array *array, ptrdiff_t index, const void *value) {
    ptrdiff_t used = (ptrdiff_t) Array_GET_USED(array);
    if (index < PTRDIFF_C(0)) {
        ptrdiff_t j = index+used;
        if (j < PTRDIFF_C(0)) {
            index = PTRDIFF_C(0)-(index-used);
        }
    }
    void *data = Array_GET_DATA(array);
    const unsigned item = Array_GET_ITEMSIZE(array);
    if (index >= used)  {
        data = Array_RESIZE_DATA(array, (size_t) index+2, true);
        if (data == NULL) {
            return NULL;
        }
        Array_SET_USED(array, index+1);
    }
    if (memcpy(data+(index-1)*item, value, item) == NULL) {
        return NULL;
    }
    return array;
}

static inline Array *
Array_DEL(Array *array, ptrdiff_t index, void *v) {
    void *target = Array_GET(array, index);
    if (target == NULL) {
        return NULL;
    }
    const size_t item = Array_GET_ITEMSIZE(array);
    if (v != NULL) {
        if (memcpy(v, target, item) == NULL) {
            return NULL;
        }
    }
    void *end = Array_GET_END(array);
    assert(end != NULL);
    ptrdiff_t lsh = end-target;
    if (memmove(target, target+item, (size_t) lsh) == NULL) {
        return NULL;
    }
    if (memset(end, 0, item) == NULL) {
        return NULL;
    }
    return Array_POSTDEC_USED(array), array;
}

#if 0

static bool
Array_GET_BOOL(Array *array, ptrdiff_t index) {
    return  Array_GET_POINTER(array).Y[index];
}

static char
Array_GET_CHAR(Array *array, ptrdiff_t index) {
    return  Array_GET_POINTER(array).c[index];
}

static wchar_t
Array_GET_WCHAR(Array *array, ptrdiff_t index) {
    return Array_GET_POINTER(array).C[index];
}

#endif