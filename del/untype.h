
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

#pragma once

#include "unstddef.h"

typedef struct {
    size_t  len;
    size_t  ndim;
    size_t *dims;
    unsigned type:16, :0;
    union {
        void *addr;
        char *c;
        unsigned char       *ub;
        unsigned short      *uh;
        unsigned            *u;
        unsigned long       *ul;
        unsigned long long  *ull;
        signed char         *b;
        signed short        *ih;
        signed int          *i;
        signed long         *l;
        signed long long    *ll;
    };
} unarray_t;

typedef signed errno_t; // type of an E[A-Z]+
typedef signed signo_t; // type of SIG[A-Z]+ consts
typedef signed nchar_t; // return type of printf() etc
typedef signed fileno_t; // return type of fileno()

typedef unsigned hash_t; // type of hash values

typedef union {

    void 
        *addr,
       *(*malloc_fn)    (void *, size_t),
        (*free_fn)      (void *);

    size_t
        (*fread_fn)     (void *, size_t, size_t, FILE *),
        (*fwrite_fn)    (void *, size_t, size_t, FILE *),
        (*offsetof_fn)  (void *, const char *),
        (*alignof_fn)   (void *),
        (*sizeof_fn)    (void *);

    ssize_t
        (*read_fn)      (void *, void *, size_t),
        (*pread_fn)     (void *, void *, size_t, off_t),
        (*readv_fn)     (void *, const struct iovec *, int),
        (*preadv_fn)    (void *, const struct iovec *, int, off_t),
        (*preadv2_fn)   (void *, const struct iovec *, int, off_t, int),
        (*write_fn)     (void *, void *, size_t),
        (*pwrite_fn)    (void *, void *, size_t, off_t),
        (*writev_fn)    (void *, const struct iovec *, int),
        (*pwritev_fn)   (void *, const struct iovec *, int, off_t),
        (*pwritev2_fn)  (void *, const struct iovec *, int, off_t, int);

    nchar_t   
        (*fprintf_fn)   (void *, const char *, FILE *), 
        (*sprintf_fn)   (void *, const void *, void *),
        (*dprintf_fn)   (void *, const void *, fileno_t);
    hash_t
        (*hash_fn)      (void *);
    fileno_t
        (*fileno_fn)    (void *),
        (*dirfd_fn)     (void *);
    bool
        (*closed_fn)    (void *),
        (*seekable_fn)  (void *),
        (*readable_fn)  (void *),
        (*writable_fn)  (void *);
    int
        (*as_bool)      (void *, bool *),
        (*as_ldouble_t) (void *, long double *),
        (*as_double_t)  (void *, double *),
        (*as_float_t)   (void *, float *),
        (*as_char_t)    (void *, char *),
        (*as_schar_t)   (void *, signed char *),
        (*as_short_t)   (void *, signed short *),
        (*as_int_t)     (void *, signed *),
        (*as_long_t)    (void *, signed long *),
        (*as_llong_t)   (void *, signed long long *),
        (*as_uchar_t)   (void *, unsigned char *),
        (*as_ushort_t)  (void *, unsigned short *),
        (*as_uint_t)    (void *, unsigned *),
        (*as_ulong_t)   (void *, unsigned long *),
        (*as_ullong_t)  (void *, unsigned long long *),
        (*as_wchar_t)   (void *, wchar_t *),
        (*as_size_t)    (void *, size_t *),
        (*as_ssize_t)   (void *, ssize_t *),
        (*as_ptrdiff_t) (void *, ptrdiff_t *),
        (*as_intmax_t)  (void *, intmax_t *),
        (*as_uintmax_t) (void *, uintmax_t *),
        (*as_FILE)      (void *, FILE **),
        (*as_ospath)    (void *, void **),
        (*as_buffer)    (void *, void **),
        (*as_array)     (void *, unarray_t **),
        (*as_str)       (void *, char **),
        (*as_wcs)       (void *, wchar_t **),
        (*as_ucs)       (void *, char32_t **);
}   unroutine_t;

#define UNOBJ_FLAGS_DECL unsigned\
    ob_flags,       \
    ob_type:    16, \
    ob_dtor:    4,  \
    readonly:   1,  \
    has_hash:   1,  \
    has_size:   1

#define UNCONST_DECL \
    hash_t ob_hash; \
    size_t ob_size

#define UNOBJ_EXT(name) \
    name;\
    UNOBJ_FLAGS_DECL

#define UNOBJ_DEF(name) \
    name;\
    UNOBJ_FLAGS_DECL, : 0 

#define UNCONST_DEF(name) \
    name;\
    UNOBJ_FLAGS_DECL, : 0;\
    UNCONST_DECL

typedef struct unobj {
    void *UNOBJ_DEF(ob);
}   unobj_t;

typedef struct unconst {
    const void *UNCONST_DEF(cv);
}   unconst_t;
