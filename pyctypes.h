/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

#pragma once

#include "unptr.h"

typedef struct TypeAttrDict {
    PyDictObject    wrapped;
    unsys_t         *info;
    union unsys_as  *conv;
    PyObject *      t_name;
    PyObject *      t_as;
    PyObject *      t_fmt;
    PyObject *      t_ndim;
    PyObject *  (*  t_vget)(void *);
    int         (*  t_vset)(void *, void *);
    PyObject *      t_vmin;
    PyObject *      t_vmax;
    PyObject *      t_size;
    PyObject *      t_align;
    PyObject *      t_signedness;
    PyObject *      t_flags;
    PyObject *      t_length;
    PyTypeObject *  t_next;
    PyTypeObject *  t_decl;
} TypeAttrDict;

static int
TypeAttrDict_clear(TypeAttrDict *obj) {
    Py_CLEAR(obj->t_name);
    Py_CLEAR(obj->t_as);
    Py_CLEAR(obj->t_fmt);
    Py_CLEAR(obj->t_ndim);
    Py_CLEAR(obj->t_vmin);
    Py_CLEAR(obj->t_vmax);
    Py_CLEAR(obj->t_size);
    Py_CLEAR(obj->t_align);
    Py_CLEAR(obj->t_length);
    Py_CLEAR(obj->t_next);
    Py_CLEAR(obj->t_decl);
    obj->conv = NULL;
    return 0;
}

#define UnC_HEAD PyObject_HEAD Py_ssize_t bf_exports;

typedef struct {
    PyNumberMethods     nb;
    PySequenceMethods   sq;
    PyMappingMethods    mp;
    PyBufferProcs       bf;
    PyMethodDef        *ml;
    PyGetSetDef        *gs;
    union unsys_as     *as;
} UnCImpl;

typedef struct {
    UnC_HEAD
    union {UNBOOL_BODY};
#define UnBool_C(obj) ((UnBool *) obj)
#define UnBool_GET(x)           (UnBool_C(x)->yval)
#define UnBool_SET(x, y)        (UnBool_C(x)->yval=(y))
} UnBool;

typedef struct {
    UnC_HEAD 
    union {UNWINT_BODY};
#define UnWint_C(obj) ((UnWint *) obj)
#define UnWint_GET(x)       (UnWint_C(x)->ival)
#define UnWint_SET(x, y)    (UnWint_C(x)->ival=(y))
} UnWint;

typedef struct {
    UnC_HEAD
    union {UNCHAR_BODY};
#define UnChar_C(obj) ((UnChar *) obj)
#define UnChar_GET(x)           (UnChar_C(x)->cval)
#define UnChar_SET(x, y)        (UnChar_C(x)->cval=(y))
#define UnSchar_GET(x)          (UnChar_C(x)->sval)
#define UnSchar_SET(x, y)       (UnChar_C(x)->sval=(y))
#define UnUchar_GET(x)          (UnChar_C(x)->uval)
#define UnUchar_SET(x, y)       (UnChar_C(x)->uval=(y))
} UnChar;

typedef struct {
    UnC_HEAD 
    union {UNSHRT_BODY};
#define UnShort_C(obj) ((UnShort *) obj)
#define  UnShort_GET(x)     (UnShort_C(x)->sval)
#define  UnShort_SET(x, y)  (UnShort_C(x)->sval=(y))
#define UnUshort_GET(x)     (UnShort_C(x)->uval)
#define UnUshort_SET(x, y)  (UnShort_C(x)->uval=(y))

} UnShort;

typedef struct {
    UnC_HEAD
    union {UNINT_BODY};
#define  UnInt_C(obj) ((UnInt *) obj)
#define  UnInt_GET(x)       (UnInt_C(x)->sval)
#define  UnInt_SET(x, y)    (UnInt_C(x)->sval=(y))
#define UnUint_GET(x)       (UnInt_C(x)->uval)
#define UnUint_SET(x, y)    (UnInt_C(x)->uval=(y))
} UnInt;

typedef struct {
    UnC_HEAD 
    union {UNLONG_BODY};
#define  UnLong_C(obj) ((UnLong *) obj)
#define  UnLong_GET(x)      (UnLong_C(x)->sval)
#define  UnLong_SET(x, y)   (UnLong_C(x)->sval=(y))
#define UnUlong_GET(x)      (UnLong_C(x)->uval)
#define UnUlong_SET(x, y)   (UnLong_C(x)->uval=(y))
} UnLong;

typedef struct {
    UnC_HEAD
    union {UNLLONG_BODY};
#define UnLlong_C(obj) ((UnLlong *) obj)
#define UnLlong_GET(x)      (UnLlong_C(x)->sval)
#define UnLlong_SET(x, y)   (UnLlong_C(x)->sval=(y))
#define UnUllong_GET(x)     (UnLlong_C(x)->uval)
#define UnUllong_SET(x, y)  (UnLlong_C(x)->uval=(y))
} UnLlong;

typedef struct {
    UnC_HEAD
    union {UNSIZE_BODY};
#define UnSize_C(obj)       ((UnSize *) obj)
#define UnSsize_GET(x)      (UnSize_C(x)->sval)
#define UnSsize_SET(x, y)   (UnSize_C(x)->sval=(y))
#define UnSize_GET(x)       (UnSize_C(x)->uval)
#define UnSize_SET(x, y)    (UnSize_C(x)->uval=(y))
} UnSize;

typedef struct {
    UnC_HEAD
    union {UNPTR_BODY};
#define UnIntptr_C(obj) ((UnIntptr *) obj)
#define UnIntptr_GET(x)     (UnIntptr_C(x)->sval)
#define UnIntptr_SET(x, y)  (UnIntptr_C(x)->sval=(y))
#define UnUintptr_GET(x)    (UnIntptr_C(x)->uval)
#define UnUintptr_SET(x, y) (UnIntptr_C(x)->uval=(y))
} UnIntptr;

typedef struct {
    UnC_HEAD
    union {UNPTRDIFF_BODY};
#define UnPtrdiff_C(obj) ((UnPtrdiff *) obj)
#define UnPtrdiff_GET(x)    (UnPtrdiff_C(x)->sval)
#define UnPtrdiff_SET(x, y) (UnPtrdiff_C(x)->sval=(y))
} UnPtrdiff;

typedef struct {
    UnC_HEAD
    union {UNINT8_BODY};
#define UnInt8_C(obj) ((UnInt8 *) obj)
#define UnInt8_GET(x)       (UnInt8_C(x)->sval)
#define UnInt8_SET(x, y)    (UnInt8_C(x)->sval=(y))
#define UnUint8_GET(x)      (UnInt8_C(x)->uval)
#define UnUint8_SET(x, y)   (UnInt8_C(x)->uval=(y))
} UnInt8;

typedef struct {
    UnC_HEAD
    union {UNINT16_BODY};
#define UnInt16_C(obj) ((UnInt16 *) obj)
#define UnInt16_GET(x)      (UnInt16_C(x)->sval)
#define UnInt16_SET(x, y)   (UnInt16_C(x)->sval=(y))
#define UnUint16_GET(x)     (UnInt16_C(x)->uval)
#define UnUint16_SET(x, y)  (UnInt16_C(x)->uval=(y))
} UnInt16;

typedef struct {
    UnC_HEAD
    union {UNINT32_BODY};


#define  UnInt32_C(obj) ((UnInt32 *) obj)
#define  UnInt32_GET(x)     (UnInt32_C(x)->sval)
#define  UnInt32_SET(x, y)  (UnInt32_C(x)->sval=(y))
#define UnUint32_GET(x)     (UnInt32_C(x)->uval)
#define UnUint32_SET(x, y)  (UnInt32_C(x)->uval=(y))

} UnInt32;

typedef struct {
    UnC_HEAD
    union {UNINT64_BODY};
#define  UnInt64_C(obj) ((UnInt64 *) obj)
#define  UnInt64_GET(x)     (UnInt64_C(x)->sval)
#define  UnInt64_SET(x, y)  (UnInt64_C(x)->sval=(y))
#define UnUint64_GET(x)     (UnInt64_C(x)->uval)
#define UnUint64_SET(x, y)  (UnInt64_C(x)->uval=(y))
} UnInt64;

typedef struct {
    UnC_HEAD
    union {UNINTMAX_BODY};
#define  UnIntmax_C(obj) ((UnIntmax *) obj)
#define  UnIntmax_GET(x)    (UnIntmax_C(x)->sval)
#define  UnIntmax_SET(x, y) (UnIntmax_C(x)->sval=(y))
#define UnUintmax_GET(x)    (UnIntmax_C(x)->uval)
#define UnUintmax_SET(x, y) (UnIntmax_C(x)->uval=(y))
} UnIntmax;

typedef struct {
    UnC_HEAD
    union {UNFLT_BODY};
#define UnFloat_C(obj) ((UnFloat *) obj)
#define UnFloat_GET(x)    (UnFloat_C(x)->fval)
#define UnFloat_SET(x, y) (UnFloat_C(x)->fval=(y))
} UnFloat;

typedef struct {
    UnC_HEAD
    union {UNDBL_BODY};
#define UnDouble_C(obj) ((UnDouble *) obj)
#define UnDouble_GET(x)    (UnDouble_C(x)->fval)
#define UnDouble_SET(x, y) (UnDouble_C(x)->fval=(y))
} UnDouble;

typedef struct {
    UnC_HEAD
    union {UNLDBL_BODY};
#define UnLdouble_C(obj) ((UnLdouble *) obj)
#define UnLdouble_GET(x)    (UnLdouble_C(x)->fval)
#define UnLdouble_SET(x, y) (UnLdouble_C(x)->fval=(y))
} UnLdouble;

typedef struct UnPointer UnPointer;

struct UnPointer {
    /*
    In Python, the expression:
        >>> unsys.c_pointer(unsys.c_char)(b"abc")
    creates (if necessary) the unsys representation of the
    C type 'const void *' (as unsys.c_void_cp) and then
    initializes a UnPointer as (UnPointer){
        .ADDR_VAR = ((PyBytesObject *) v)->ob_sval,
        .ctx = v
    }
    
    */
    UnC_HEAD
    union {
        UNPTR_BODY;
        unsigned char *val;
    };
    union {
        void        *ctx;
        PyObject    *as_py;
        UnPointer   *as_pointer;
        UnBool      *as_bool;
        UnChar      *as_char;
        UnShort     *as_unshort;
        UnInt       *as_int;
        UnLong      *as_long;
        UnSize      *as_size;
        UnPtrdiff   *as_ptrdiff;
        UnIntptr    *as_intpr;
        UnInt8      *as_int8;
        UnInt16     *as_int16;
        UnInt32     *as_int32;
        UnInt64     *as_int64;
        UnIntmax    *as_intmax;
        UnFloat     *as_float;
        UnDouble    *as_double;
    };
};


#define UnC_GET_EXPORTS(o) (((UnChar *) o)->bf_exports)
#define UnC_SET_EXPORTS(o,n) (((UnChar *) o)->bf_exports=n)


static PyObject    *UnFloat_NEW(PyTypeObject *, float);
static PyObject    *UnDouble_NEW(PyTypeObject *, double);
static PyObject    *UnLdouble_NEW(PyTypeObject *, long double);

static PyObject    *UnWint_NEW(PyTypeObject *, wint_t);
static PyObject    *UnBool_NEW(PyTypeObject *, _Bool);
static PyObject   *UnSchar_NEW(PyTypeObject *, signed char);
static PyObject   *UnShort_NEW(PyTypeObject *, short);
static PyObject     *UnInt_NEW(PyTypeObject *, int);
static PyObject    *UnLong_NEW(PyTypeObject *, long);
static PyObject   *UnLlong_NEW(PyTypeObject *, long long);
static PyObject   *UnSsize_NEW(PyTypeObject *, ssize_t);
static PyObject  *UnIntptr_NEW(PyTypeObject *, intptr_t);
static PyObject *UnPtrdiff_NEW(PyTypeObject *, intptr_t);
static PyObject    *UnInt8_NEW(PyTypeObject *, int8_t);
static PyObject   *UnInt16_NEW(PyTypeObject *, int16_t);
static PyObject   *UnInt32_NEW(PyTypeObject *, int32_t);
static PyObject   *UnInt64_NEW(PyTypeObject *, int64_t);
static PyObject  *UnIntmax_NEW(PyTypeObject *, intmax_t);
static PyObject   *UnUchar_NEW(PyTypeObject *, unsigned char);
static PyObject  *UnUshort_NEW(PyTypeObject *, unsigned short);
static PyObject    *UnUint_NEW(PyTypeObject *, unsigned int);
static PyObject   *UnUlong_NEW(PyTypeObject *, unsigned long);
static PyObject  *UnUllong_NEW(PyTypeObject *, unsigned long long);
static PyObject    *UnSize_NEW(PyTypeObject *, size_t);
static PyObject *UnUintptr_NEW(PyTypeObject *, uintptr_t);
static PyObject   *UnUint8_NEW(PyTypeObject *, uint8_t);
static PyObject  *UnUint16_NEW(PyTypeObject *, uint16_t);
static PyObject  *UnUint32_NEW(PyTypeObject *, uint32_t);
static PyObject  *UnUint64_NEW(PyTypeObject *, uint64_t);
static PyObject *UnUintmax_NEW(PyTypeObject *, uintmax_t);

union UnC_ctors {

    void *list[AS_BLTN_MAX];

    struct {

        PyObject *(*as_void)    (PyTypeObject *,  PyObject *);
        PyObject *(*as_addr)    (PyTypeObject *, void *);
        PyObject *(*as_addrptr) (PyTypeObject *, void **);

        PyObject *(*as_char)    (PyTypeObject *, char);

        PyObject *(*as_wchar)   (PyTypeObject *, wchar_t);
        PyObject *(*as_char16)  (PyTypeObject *, char16_t);
        PyObject *(*as_char32)  (PyTypeObject *, char32_t);

        void *    ( as_half);
        PyObject *(*as_flt)     (PyTypeObject *, float);
        PyObject *(*as_dbl)     (PyTypeObject *, double);
        PyObject *(*as_ldbl)    (PyTypeObject *, long double);
        PyObject *(*as_bigflt)  (PyTypeObject *, void *);

        PyObject *(*as_bool)    (PyTypeObject *, _Bool);

        PyObject *(*as_schar)   (PyTypeObject *, signed      char);
        PyObject *(*as_short)   (PyTypeObject *, signed short int);
        PyObject *(*as_int)     (PyTypeObject *, signed       int);
        PyObject *(*as_long)    (PyTypeObject *, signed long  int);
        PyObject *(*as_llong)   (PyTypeObject *, signed long long);
        void *    ( as_xlong);
        PyObject *(*as_ssize)   (PyTypeObject *, ssize_t);
        PyObject *(*as_intptr)  (PyTypeObject *, intptr_t);
        PyObject *(*as_ptrdiff) (PyTypeObject *, ptrdiff_t);
        PyObject *(*as_int8)    (PyTypeObject *, int8_t);
        PyObject *(*as_int16)   (PyTypeObject *, int16_t);
        PyObject *(*as_int32)   (PyTypeObject *, int32_t);
        PyObject *(*as_int64)   (PyTypeObject *, int64_t);
        PyObject *(*as_intmax)  (PyTypeObject *, intmax_t);

        PyObject *(*as_uchar)   (PyTypeObject *, unsigned      char);
        PyObject *(*as_ushort)  (PyTypeObject *, unsigned short int);
        PyObject *(*as_uint)    (PyTypeObject *, unsigned       int);
        PyObject *(*as_ulong)   (PyTypeObject *, unsigned long  int);
        PyObject *(*as_ullong)  (PyTypeObject *, unsigned long long);
        void *     (as_uxlong);
        PyObject *(*as_size)    (PyTypeObject *, size_t);
        PyObject *(*as_uintptr) (PyTypeObject *, uintptr_t);
        PyObject *(*as_uint8)   (PyTypeObject *, uint8_t);
        PyObject *(*as_uint16)  (PyTypeObject *, uint16_t);
        PyObject *(*as_uint32)  (PyTypeObject *, uint32_t);
        PyObject *(*as_uint64)  (PyTypeObject *, uint64_t);
        PyObject *(*as_uintmax) (PyTypeObject *, uintmax_t);

        PyObject *(*as_wint)(PyTypeObject *, wint_t);

#if defined(SIG_ATOMIC_MAX)
        PyObject *(*as_sig_atomic)(PyTypeObject *, sig_atomic_t);
#else
        PyObject *(*as_sig_atomic)(PyTypeObject *, int);
#endif
        PyObject *(*as_bigint)    (PyTypeObject *, void *);
    };
};

static union UnC_ctors UnC_ctors = {
    .list = {
        [AS_VOID]       = 0,
        [AS_ADDR]       = 0,
        [AS_ADDRPTR]    = 0,
        [AS_CHAR]       = 0,
        [AS_WCHAR]      = 0,
        [AS_CHAR16]     = 0,
        [AS_CHAR32]     = 0,

        [AS_FLT]        = UnFloat_NEW,
        [AS_DBL]        = UnDouble_NEW,
        [AS_LDBL]       = UnLdouble_NEW,
        [AS_BIGFLT]     = 0,

        [AS_BOOL]       = UnBool_NEW,
        [AS_SCHAR]      = UnSchar_NEW,
        [AS_SHRT]       = UnShort_NEW,
        [AS_INT]        = UnInt_NEW,
        [AS_LONG]       = UnLong_NEW,
        [AS_LLONG]      = UnLlong_NEW,
        [AS_SSIZE]      = UnSsize_NEW,
        [AS_INTPTR]     = UnIntptr_NEW,
        [AS_PTRDIFF]    = UnPtrdiff_NEW,
        [AS_INT8]       = UnInt8_NEW,
        [AS_INT16]      = UnInt16_NEW,
        [AS_INT32]      = UnInt32_NEW,
        [AS_INT64]      = UnInt64_NEW,
        [AS_INTMAX]     = UnIntmax_NEW,
        [AS_UCHAR]      = UnUchar_NEW,
        [AS_USHRT]      = UnUshort_NEW,
        [AS_UINT]       = UnUint_NEW,
        [AS_ULONG]      = UnUlong_NEW,
        [AS_ULLONG]     = UnUllong_NEW,
        [AS_SIZE]       = UnSize_NEW,
        [AS_UINTPTR]    = UnUintptr_NEW,
        [AS_UINT8]      = UnUint8_NEW,
        [AS_UINT16]     = UnUint16_NEW,
        [AS_UINT32]     = UnUint32_NEW,
        [AS_UINT64]     = UnUint64_NEW,
        [AS_UINTMAX]    = UnUintmax_NEW,
        [AS_WINT]       = UnWint_NEW,
        [AS_BIGINT]     = 0,
    },
};

static inline void
UnC_DEC_EXPORTS(void *obj) {
    ((UnChar *) obj)->bf_exports--;
}

static inline void
UnC_INC_EXPORTS(void *obj) {
    ((UnChar *) obj)->bf_exports++;
}

static inline TypeAttrDict *
UnC_TAD(UnChar *obj) {
    return (TypeAttrDict *) ((PyObject *) obj)->ob_type->tp_dict;
}

static inline struct unsys_ctype *
UnC_GET_INFO(UnChar *obj) {
    return UnC_TAD(obj)->info;
}

static inline union unsys_as *
UnC_GET_CONV(UnChar *obj) {
    return UnC_TAD(obj)->conv;
}

static inline const char *
UnC_GET_NAME(UnChar *obj) {
    return UnC_GET_INFO(obj)->t_name;
}
static inline unsigned short
UnC_GET_AS(UnChar *obj) {
    return UnC_GET_INFO(obj)->t_as;
}
static inline unsigned char
UnC_GET_FMT(UnChar *obj) {
    return UnC_GET_INFO(obj)->t_fmt;
}
static inline unsigned char
UnC_GET_NDIM(UnChar *obj) {
    return UnC_GET_INFO(obj)->t_ndim;
}
static inline _Bool
UnC_GET_CQ(UnChar *obj) {
    return UnC_GET_INFO(obj)->t_constant;
}
static inline _Bool
UnC_GET_VQ(UnChar *obj) {
    return UnC_GET_INFO(obj)->t_volatile;
}
static inline _Bool
UnC_GET_RQ(UnChar *obj) {
    return UnC_GET_INFO(obj)->t_restrict;
}
static inline _Bool
UnC_GET_NQ(UnChar *obj) {
    return UnC_GET_INFO(obj)->t_netorder;
}
static inline size_t 
(*UnC_GET_VMIN(UnChar *obj))(void *) {
    return UnC_GET_INFO(obj)->t_vmin;
}
static inline size_t
(*UnC_GET_VMAX(UnChar *obj))(void *) {
    return UnC_GET_INFO(obj)->t_vmax;
}

static inline int
UnC_GET_SIGNEDNESS(UnChar *obj) {
    return UnC_GET_INFO(obj)->t_signedness;
}
static inline int
UnC_GET_RANK(UnChar *obj) {
    return UnC_GET_INFO(obj)->t_rank;
}
static inline size_t
UnC_GET_SIZE(UnChar *obj) {
    return UnC_GET_INFO(obj)->t_size;
}
static inline Py_ssize_t
UnC_GET_SSIZE(UnChar *obj) {
    return (Py_ssize_t) UnC_GET_SIZE(obj);
}
static inline size_t
UnC_GET_LENGTH(UnChar *obj) {
    return UnC_GET_INFO(obj)->t_length;
}
static inline unsys_t *
UnC_GET_NEXT(UnChar *obj) {
    return UnC_GET_INFO(obj)->t_next;
}
static inline unsys_t *
UnC_GET_SPEC(UnChar *obj) {
    return UnC_GET_INFO(obj)->t_spec;
}

static inline unsigned char *
UnC_GET_DATA(UnChar *obj) {
    return obj->rval;
}

static inline _Bool
TypeAttrDict_CHECK(void *dict) {
    return Py_TYPE(dict) == &TypeAttrDict_Type;
}

static inline _Bool
UnC_IS_DATA_TYPE(PyObject *ob) {
    return TypeAttrDict_CHECK(ob->ob_type->tp_dict);
}

static inline TypeAttrDict *
TypeAttrDict_GET(PyTypeObject *cls) {
    return (TypeAttrDict *) cls->tp_dict;
}

static inline PyObject *
TypeAttrDict_NEW(void) {
    return PyObject_CallNoArgs((PyObject *) &TypeAttrDict_Type);
}

static inline void 
TypeAttrDict_SET_VGET(TypeAttrDict *d, void *f) {
    d->t_vget = f;
}

static PyObject *
TypeAttrDict_get_t_name(TypeAttrDict *d, void *ctx) {
    if (d->t_name == NULL) {
        d->t_name = PyUnicode_FromString(d->info->t_name);
    }
    return Py_NewRef(d->t_name);
}

static int
TypeAttrDict_set_t_name(TypeAttrDict *d, PyObject *v, void *ctx) {
    printf("settin name\n");
    return 0;
}

static PyObject *
TypeAttrDict_get_t_as(TypeAttrDict *d, void *ctx) {
    if (d->t_as == NULL) {
        d->t_as = pylong_FROM_USHRT(d->info->t_as);
    }
    return Py_NewRef(d->t_as);
}

static PyObject *
TypeAttrDict_get_t_fmt(TypeAttrDict *d, void *ctx) {
    Py_RETURN_NONE;
}

static PyObject *
TypeAttrDict_get_t_ndim(TypeAttrDict *d, void *ctx) {
    if (d->t_ndim == NULL) {
        d->t_ndim = pylong_FROM_UCHAR(d->info->t_ndim);
    }
    return Py_NewRef(d->t_ndim);
}

PyObject *
TypeAttrDict_get_t_vmin(TypeAttrDict *d, void *ctx) {
    Py_RETURN_NOTIMPLEMENTED;
}

PyObject *
TypeAttrDict_get_t_vmax(TypeAttrDict *d, void *ctx) {
    Py_RETURN_NOTIMPLEMENTED;
    /*
    if (d->t_vmax == NULL) {
        void *addr = d->info->t_vmax.addr;
        if (addr == NULL) {
            Py_RETURN_NONE;
        }
        d->t_vmax = d->t_vget(addr);
        if (d->t_vmax == NULL) {
            return NULL;
        }
    }
    return Py_NewRef(d->t_vmax);
    */
}

static PyObject *
TypeAttrDict_get_t_size(TypeAttrDict *d, void *ctx) {
    Py_RETURN_NONE;
}

static PyObject *
TypeAttrDict_get_t_length(TypeAttrDict *d, void *ctx) {
    Py_RETURN_NONE;
}

static PyObject *
TypeAttrDict_get_t_next(TypeAttrDict *d, void *ctx) {
    Py_RETURN_NONE;
}

static int
TypeAttrDict_init(TypeAttrDict *obj, PyObject *args, PyObject *kwds) {
    TypeAttrDict_clear(obj);
    return PyDict_Type.tp_init((PyObject *) obj, args, kwds);
}

static void
TypeAttrDict_dealloc(TypeAttrDict *stg) {
    if (stg->info->t_free != NULL) {
        stg->info->t_free(stg->info);
    }
    (void) TypeAttrDict_clear(stg);
    PyDict_Type.tp_dealloc((PyObject *) stg);
}

static PyObject *
UnScalar_repr(PyObject *obj) {
    return 0;
}

static void 
UnScalar_dealloc(PyObject *obj) {
    Py_DECREF(obj->ob_type);
    PyMem_Free(obj);
}

static int
UnScalar_getbuffer(UnChar *obj, Py_buffer *view, int flags) {
    if (PyBuffer_FillInfo(
        view, 
        (PyObject*) obj, 
        obj->rval, 
        UnC_GET_SIZE(obj),
        UnC_GET_CQ(obj), 
        flags
    )) {
        return 0-1;
    }
    UnC_INC_EXPORTS(obj);
    return 0;
}

static void
UnScalar_releasebuffer(UnChar *obj, Py_buffer *view) {
    UnC_DEC_EXPORTS(obj);
}


static UnCImpl 
TypeAttrDict_impl = {
    .gs = (PyGetSetDef[]){
        {"t_name",(getter) TypeAttrDict_get_t_name},
        {"t_as",    (getter) TypeAttrDict_get_t_as},
        {"t_fmt",   (getter) TypeAttrDict_get_t_fmt},
        {"t_ndim",  (getter) TypeAttrDict_get_t_ndim},
        {"t_vmin",  (getter) TypeAttrDict_get_t_vmin},
        {"t_vmax",  (getter) TypeAttrDict_get_t_vmax},
        {"t_size",  (getter) TypeAttrDict_get_t_size},
        {"t_length",(getter) TypeAttrDict_get_t_length},
        {"t_next",  (getter) TypeAttrDict_get_t_size},
        {0},
    },
};

static UnCImpl UnScalar_impl = {
    .bf = {
        .bf_getbuffer=(getbufferproc) UnScalar_getbuffer,
        .bf_releasebuffer = (releasebufferproc) UnScalar_releasebuffer,
    }
};

#include "pytypes/bool.h"
#include "pytypes/schar.h"
#include "pytypes/short.h"
//#include "pytypes/int.h"
#include "unreal.h"
#include "pytypes/uint.h"
#include "pytypes/pointer.h"
#include "pyenum.h"

static inline _Bool
unsys_SCALAR_CHK(const PyTypeObject *cls) {
    return (&UnScalar_Meta <= cls) && (cls < &UnObject_Meta);
}

static inline PyObject *
UnReal_NEW(PyTypeObject *cls, const void *src, const int tag) {
    UnChar *obj = PyMem_Malloc((size_t) cls->tp_basicsize);
    if (obj == NULL) {
        return NULL;
    }
    Py_INCREF(cls);
    ((PyObject *) obj)->ob_refcnt = 1;
    ((PyObject *) obj)->ob_type = cls;
    UnC_SET_EXPORTS(obj, 0);
    const unref_t v = {src};
    switch (tag) {

        case AS_SCHAR:     UnSchar_SET(obj, *v.SCHAR_VAR);  break;
        case AS_UCHAR:     UnUchar_SET(obj, *v.UCHAR_VAR);  break;

        case AS_SHRT:      UnShort_SET(obj,  *v.SHRT_VAR);   break;
        case AS_USHRT:    UnUshort_SET(obj, *v.USHRT_VAR);  break;

        case AS_INT:         UnInt_SET(obj,  *v.INT_VAR);    break;
        case AS_UINT:       UnUint_SET(obj, *v.UINT_VAR);   break;

        case AS_LONG:       UnLong_SET(obj,  *v.LONG_VAR);   break;
        case AS_ULONG:     UnUlong_SET(obj, *v.ULONG_VAR);  break;

        case AS_LLONG:     UnLlong_SET(obj,  *v.LLONG_VAR);  break;
        case AS_ULLONG:   UnUllong_SET(obj, *v.ULLONG_VAR); break;

        case AS_INTPTR:   UnIntptr_SET(obj,  *v.INTPTR_VAR); break;
        case AS_UINTPTR: UnUintptr_SET(obj, *v.UINTPTR_VAR);break;

        case AS_SSIZE:     UnSsize_SET(obj, *v.SSIZE_VAR);  break;
        case AS_SIZE:       UnSize_SET(obj,  *v.SIZE_VAR);   break;
    
        case AS_PTRDIFF: UnPtrdiff_SET(obj, *v.PTRDIFF_VAR);break;
        
        case AS_BOOL:       UnBool_SET(obj, *v.BOOL_VAR);   break;
        case AS_WINT:       UnWint_SET(obj, *v.WINT_VAR);   break;

        case AS_INT8:       UnInt8_SET(obj,  *v.INT8_VAR);   break;
        case AS_UINT8:     UnUint8_SET(obj, *v.UINT8_VAR);  break;

        case AS_INT16:     UnInt16_SET(obj, *v.INT16_VAR);  break;
        case AS_UINT16:   UnUint16_SET(obj, *v.UINT16_VAR); break;

        case AS_INT32:     UnInt32_SET(obj,  *v.INT32_VAR); break;
        case AS_UINT32:   UnUint32_SET(obj, *v.UINT32_VAR); break;

        case AS_INT64:     UnInt64_SET(obj,  *v.INT64_VAR); break;
        case AS_UINT64:   UnUint64_SET(obj, *v.UINT64_VAR); break;

        case AS_INTMAX:   UnIntmax_SET(obj,  *v.INTMAX_VAR); break;
        case AS_UINTMAX: UnUintmax_SET(obj, *v.UINTMAX_VAR);break;
        
        case AS_FLT:       UnFloat_SET(obj,  *v.FLT_VAR);    break;
        case AS_DBL:      UnDouble_SET(obj,  *v.DBL_VAR);    break;
        case AS_LDBL:    UnLdouble_SET(obj, *v.LDBL_VAR);    break;

        default: Py_UNREACHABLE();
    }
    return (PyObject *) obj;
}

static PyObject *
UnWint_NEW(PyTypeObject *cls, wint_t ival) {
    return UnReal_NEW(cls, &ival, AS_WINT);
}

static PyObject *
UnSchar_NEW(PyTypeObject *cls, signed char sval) {
    return UnReal_NEW(cls, &sval, AS_SCHAR);
}

static PyObject *
UnUchar_NEW(PyTypeObject *cls, unsigned char uval) {
    return UnReal_NEW(cls, &uval, AS_UCHAR);
}

static PyObject *
UnShort_NEW(PyTypeObject *cls, short sval) {
    return UnReal_NEW(cls, &sval, AS_SHRT);
}

static PyObject *
UnUshort_NEW(PyTypeObject *cls, unsigned short uval) {
    return UnReal_NEW(cls, &uval, AS_USHRT);
}

static PyObject *
UnInt_NEW(PyTypeObject *cls, int sval) {
    return UnReal_NEW(cls, &sval, AS_INT);
}

static PyObject *
UnUint_NEW(PyTypeObject *cls, unsigned uval) {
    return UnReal_NEW(cls, &uval, AS_UINT);
}

static PyObject *
UnLong_NEW(PyTypeObject *cls, long sval) {
    return UnReal_NEW(cls, &sval, AS_LONG);
}

static PyObject *
UnUlong_NEW(PyTypeObject *cls, unsigned long uval) {
    return UnReal_NEW(cls, &uval, AS_ULONG);
}

static PyObject *
UnLlong_NEW(PyTypeObject *cls, long long sval) {
    return UnReal_NEW(cls, &sval, AS_LLONG);
}

static PyObject *
UnUllong_NEW(PyTypeObject *cls, unsigned long long uval) {
    return UnReal_NEW(cls, &uval, AS_ULLONG);
}

static PyObject *
UnSsize_NEW(PyTypeObject *cls, ssize_t sval) {
    return UnReal_NEW(cls, &sval, AS_SSIZE);
}

static PyObject *
UnSize_NEW(PyTypeObject *cls, size_t uval) {
    return UnReal_NEW(cls, &uval, AS_SIZE);
}

static PyObject *
UnIntptr_NEW(PyTypeObject *cls, intptr_t sval) {
    return UnReal_NEW(cls, &sval, AS_INTPTR);
}

static PyObject *
UnUintptr_NEW(PyTypeObject *cls, uintptr_t uval) {
    return UnReal_NEW(cls, &uval, AS_UINTPTR);
}

static PyObject *
UnPtrdiff_NEW(PyTypeObject *cls, ptrdiff_t sval) {
    return UnReal_NEW(cls, &sval, AS_PTRDIFF);
}

static PyObject *
UnInt8_NEW(PyTypeObject *cls, int8_t sval) {
    return UnReal_NEW(cls, &sval, AS_INT8);
}

static PyObject *
UnInt16_NEW(PyTypeObject *cls, int16_t sval) {
    return UnReal_NEW(cls, &sval, AS_INT16);
}

static PyObject *
UnInt32_NEW(PyTypeObject *cls, int32_t sval) {
    return UnReal_NEW(cls, &sval, AS_INT32);
}

static PyObject *
UnInt64_NEW(PyTypeObject *cls, int64_t sval) {
    return UnReal_NEW(cls, &sval, AS_INT64);
}

static PyObject *
UnIntmax_NEW(PyTypeObject *cls, intmax_t sval) {
    return UnReal_NEW(cls, &sval, AS_INTMAX);
}

static PyObject *
UnBool_NEW(PyTypeObject *cls, _Bool yval) {
    return UnReal_NEW(cls, &yval, AS_BOOL);
}

static PyObject *
UnUint8_NEW(PyTypeObject *cls, uint8_t uval) {
    return UnReal_NEW(cls, &uval, AS_UINT8);
}

static PyObject *
UnUint16_NEW(PyTypeObject *cls, uint16_t uval) {
    return UnReal_NEW(cls, &uval, AS_UINT16);
}

static PyObject *
UnUint32_NEW(PyTypeObject *cls, uint32_t uval) {
    return UnReal_NEW(cls, &uval, AS_UINT32);
}

static PyObject *
UnUint64_NEW(PyTypeObject *cls, uint64_t uval) {
    return UnReal_NEW(cls, &uval, AS_UINT64);
}

static PyObject *
UnUintmax_NEW(PyTypeObject *cls, uintmax_t uval) {
    return UnReal_NEW(cls, &uval, AS_UINTMAX);
}

static PyObject *
UnFloat_NEW(PyTypeObject *cls, float fval) {
    return UnReal_NEW(cls, &fval, AS_FLT);
}

static PyObject *
UnDouble_NEW(PyTypeObject *cls, double fval) {
    return UnReal_NEW(cls, &fval, AS_DBL);
}
static PyObject *
UnLdouble_NEW(PyTypeObject *cls, long double fval) {
    return UnReal_NEW(cls, &fval, AS_LDBL);
}

static PyObject *
UnScalarType_get_name(PyTypeObject *cls, void *ctx) {
    TypeAttrDict *stg = TypeAttrDict_GET(cls);
    if (!TypeAttrDict_CHECK(stg)) {
        Py_RETURN_NONE;
    }
    return PyUnicode_FromString(stg->info->t_name);
}
    
static PyObject *
UnScalarType_get_as(PyTypeObject *cls, void *ctx) {
    TypeAttrDict *stg = TypeAttrDict_GET(cls);
    if (!TypeAttrDict_CHECK(stg)) {
        Py_RETURN_NONE;
    }
    PyObject *res = unsys.enums.AS_[stg->info->t_as];
    Py_XINCREF(res);
    return res;
}
static PyObject *
UnScalarType_get_rank(PyTypeObject *cls, void *ctx)  {
    TypeAttrDict *stg = TypeAttrDict_GET(cls);
    if (!TypeAttrDict_CHECK(stg)) {
        Py_RETURN_NONE;
    }
    PyObject *res = unsys.enums.NB_RANK_[stg->info->t_rank];
    Py_XINCREF(res);
    return res;
}
static PyObject *
UnScalarType_get_signedness(PyTypeObject *cls, void *ctx)  {
    TypeAttrDict *stg = TypeAttrDict_GET(cls);
    if (!TypeAttrDict_CHECK(stg)) {
        Py_RETURN_NONE;
    }
    PyObject *res;
    switch (stg->info->t_signedness) {
        case NB_UNSIGNED: {
            res = unsys.enums.nb_unsigned;
            break;
        }
        case NB_SIGNED: {
            res = unsys.enums.nb_signed;
            break;
        }
        case NB_SIGNLESS: {
            res = unsys.enums.nb_signless;
            break;
        }
        default: {
            Py_UNREACHABLE();
        }
    }
    Py_XINCREF(res);
    return res;
}

static PyObject *
UnScalarType_get_conv(PyTypeObject *obj, void *ctx) {
    TypeAttrDict *stg = (TypeAttrDict *)obj->tp_dict;
    if (!TypeAttrDict_CHECK(stg)) {
        return pylong_FROM_UCHAR(0);
    }
    return pylong_FROM_UINTPTR((uintptr_t) stg->conv);
}

static UnCImpl 
UnScalarMeta_impl = {
    .gs = (PyGetSetDef[]){
        {"t_name",          (getter) UnScalarType_get_name},
        {"t_as",            (getter) UnScalarType_get_as},
        {"t_rank",          (getter) UnScalarType_get_rank},
        {"t_signedness",    (getter) UnScalarType_get_signedness},
        {"t_conv",          (getter) UnScalarType_get_conv},
        {0},
    },
};

/*
527791548608: {c_int}
527791548264: {c_ptrdiff}
527791549296
527791548264     
>>> unsys.c_long.t_conv 
527791548952     
>>> unsys.c_llong.t_conv

527791548952: {c_long, c_int64, c_intmax}

>>> unsys.c_ssize.t_conv    

*/