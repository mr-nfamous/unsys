

/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

Custom PyLongObject API. 

Each builtin C type has a set of static inline functions of 
the following form:

    int         pylong_INT(PyObject *ob)
    int         pylong_DIGITS_TO_INT(digit *a, Py_ssize_t n)
    PyObject *  pylong_FROM_INT(int)

pylong_{T}:
    Converts a PyLongObject to a value of type T.

pylong_DIGITS_TO_{T}:
    Reinterpret the low order bits of a PyLongObject's 
    ob_digit and ob_size fields as a value of type T. I.e.
    no overflow checking is done, even for signed types.

pylong_FROM_{T}:
    Convert T value to PyLongObject.


*/
#pragma once 

static inline digit *
pylong_DIGITS(PyObject *v) {
    return ((PyLongObject *) v)->ob_digit;
}

static inline sdigit *
pylong_SDIGITS(PyObject *v) {
    return (sdigit *) pylong_DIGITS(v);
}

static inline PyLongObject *
pylong_NEW(size_t ndigit, Py_ssize_t ob_size) {
    /*
    An alternative to _PyLong_New that eliminates the following
    pointless checks:
    *   ndigit != 0
    *   ndigit < MAX_LONG_DIGITS 
    */
    void *v = PyObject_Malloc(
        offsetof(PyLongObject, ob_digit)
        +sizeof(digit)*ndigit
    );
    return PyObject_InitVar((PyVarObject*) v, &PyLong_Type, ob_size), v;
}

#if PyLong_SHIFT == 15

#   include "pylong15.h"

#   define pylong_DIGITS_TO_INT     pylong15_DIGITS_TO_INT
#   define pylong_DIGITS_TO_UINT    pylong15_DIGITS_TO_UINT
#   define pylong_DIGITS_TO_LONG    pylong15_DIGITS_TO_LONG
#   define pylong_DIGITS_TO_ULONG   pylong15_DIGITS_TO_ULONG
#   define pylong_DIGITS_TO_LLONG   pylong15_DIGITS_TO_LLONG
#   define pylong_DIGITS_TO_ULLONG  pylong15_DIGITS_TO_ULLONG
#   define pylong_FROM_UINT         pylong15_FROM_UINT
#   define pylong_FROM_INT          pylong15_FROM_INT
#   define pylong_FROM_ULONG        pylong15_FROM_ULONG
#   define pylong_FROM_LONG         pylong15_FROM_LONG
#   define pylong_FROM_ULLONG       pylong15_FROM_ULLONG
#   define pylong_FROM_LLONG        pylong15_FROM_LLONG

#else

#   include "pylong30.h"
#   define pylong_BIT_LENGTH        pylong30_BIT_LENGTH
#   define pylong_UCMP_DIGITS       pylong30_UCMP_DIGITS
#   define pylong_SCMP_DIGITS       pylong30_SCMP_DIGITS
#   define pylong_DIGITS_TO_FLT     pylong30_DIGITS_TO_FLT
#   define pylong_DIGITS_TO_DBL     pylong30_DIGITS_TO_DBL
#   define pylong_DIGITS_TO_LDBL    pylong30_DIGITS_TO_LDBL
#   define pylong_DIGITS_TO_INT     pylong30_DIGITS_TO_INT
#   define pylong_DIGITS_TO_UINT    pylong30_DIGITS_TO_UINT
#   define pylong_DIGITS_TO_LONG    pylong30_DIGITS_TO_LONG
#   define pylong_DIGITS_TO_ULONG   pylong30_DIGITS_TO_ULONG
#   define pylong_DIGITS_TO_LLONG   pylong30_DIGITS_TO_LLONG
#   define pylong_DIGITS_TO_ULLONG  pylong30_DIGITS_TO_ULLONG
#   define pylong_DIGITS_TO_INDEX   pylong30_DIGITS_TO_INDEX
#   define pylong_FROM_UINT         pylong30_FROM_UINT
#   define pylong_FROM_INT          pylong30_FROM_INT
#   define pylong_FROM_ULONG        pylong30_FROM_ULONG
#   define pylong_FROM_LONG         pylong30_FROM_LONG
#   define pylong_FROM_ULLONG       pylong30_FROM_ULLONG
#   define pylong_FROM_LLONG        pylong30_FROM_LLONG

#endif // PyLong_SHIFT == 15

#define pylong_DIGITS_TO_INT8       pylong_DIGITS_TO_SCHAR
#define pylong_DIGITS_TO_INT16      pylong_DIGITS_TO_SHRT
#define pylong_DIGITS_TO_INT32      pylong_DIGITS_TO_INT

#define pylong_DIGITS_TO_UINT8      pylong_DIGITS_TO_UCHAR
#define pylong_DIGITS_TO_UINT16     pylong_DIGITS_TO_USHRT
#define pylong_DIGITS_TO_UINT32     pylong_DIGITS_TO_UINT

#define pylong_FROM_INT8            pylong_FROM_SCHAR
#define pylong_FROM_INT16           pylong_FROM_SHRT
#define pylong_FROM_INT32           pylong_FROM_INT

#define pylong_FROM_UINT8           pylong_FROM_UCHAR
#define pylong_FROM_UINT16          pylong_FROM_USHRT
#define pylong_FROM_UINT32          pylong_FROM_UINT

#define pylong_INT8                 pylong_SCHAR
#define pylong_INT32                pylong_INT
#define pylong_INT16                pylong_SHRT

#define pylong_UINT8                pylong_UCHAR
#define pylong_UINT16               pylong_USHRT
#define pylong_UINT32               pylong_UINT

#if INT64_MAX == LONG_MAX
#   define pylong_INT64 pylong_LONG
#   define pylong_UINT64 pylong_ULONG
#   define pylong_DIGITS_TO_INT64   pylong_DIGITS_TO_LONG
#   define pylong_DIGITS_TO_UINT64  pylong_DIGITS_TO_ULONG
#   define pylong_FROM_INT64 pylong_FROM_LONG
#   define pylong_FROM_UINT64 pylong_FROM_ULONG
#else
#   define pylong_INT64 pylong_LLONG
#   define pylong_UINT64 pylong_ULLONG
#   define pylong_DIGITS_TO_INT64   pylong_DIGITS_TO_LLONG
#   define pylong_DIGITS_TO_UINT64  pylong_DIGITS_TO_ULLONG
#   define pylong_FROM_INT64 pylong_FROM_LLONG
#   define pylong_FROM_UINT64 pylong_FROM_ULLONG
#endif

#if WCHAR_SIGNEDNESS == NB_SIGNED
#   if   WCHAR_MAX == SCHAR_MAX
#       define pylong_DIGITS_TO_WCHAR   pylong_DIGITS_TO_SCHAR
#       define pylong_WCHAR             pylong_SCHAR
#       define pylong_FROM_WCHAR        pylong_FROM_SCHAR
#   elif WCHAR_MAX == SHRT_MAX
#       define pylong_DIGITS_TO_WCHAR   pylong_DIGITS_TO_SHRT
#       define pylong_WCHAR             pylong_SHRT
#       define pylong_FROM_WCHAR        pylong_FROM_SHRT
#   elif WCHAR_MAX == INT_MAX
#       define pylong_DIGITS_TO_WCHAR   pylong_DIGITS_TO_INT
#       define pylong_WCHAR             pylong_INT
#       define pylong_FROM_WCHAR        pylong_FROM_INT
#   elif WCHAR_MAX == LONG_MAX
#       define pylong_DIGITS_TO_WCHAR   pylong_DIGITS_TO_LONG
#       define pylong_WCHAR             pylong_LONG
#       define pylong_FROM_WCHAR        pylong_FROM_LONG
#   endif
#else
#   if   WCHAR_MAX == UCHAR_MAX
#       define pylong_DIGITS_TO_WCHAR   pylong_DIGITS_TO_UCHAR
#       define pylong_WCHAR             pylong_UCHAR
#       define pylong_FROM_WCHAR        pylong_FROM_UCHAR
#   elif WCHAR_MAX == USHRT_MAX
#       define pylong_DIGITS_TO_WCHAR   pylong_DIGITS_TO_USHRT
#       define pylong_WCHAR             pylong_USHRT
#       define pylong_FROM_WCHAR        pylong_FROM_USHRT
#   elif WCHAR_MAX == UINT_MAX
#       define pylong_DIGITS_TO_WCHAR   pylong_DIGITS_TO_UINT
#       define pylong_WCHAR             pylong_UINT
#       define pylong_FROM_WCHAR        pylong_FROM_UINT
#   elif WCHAR_MAX == ULONG_MAX
#       define pylong_DIGITS_TO_WCHAR   pylong_DIGITS_TO_ULONG
#       define pylong_WCHAR             pylong_ULONG
#       define pylong_FROM_WCHAR        pylong_FROM_ULONG
#   endif
#endif

#if WINT_SIGNEDNESS == NB_SIGNED
#   if WINT_MAX == SHRT_MAX
#       define pylong_DIGITS_TO_WINT    pylong_DIGITS_TO_SHRT
#       define pylong_WINT              pylong_SHRT
#       define pylong_FROM_WINT         pylong_FROM_SHRT
#   elif WINT_MAX == INT_MAX
#       define pylong_DIGITS_TO_WINT    pylong_DIGITS_TO_INT
#       define pylong_WINT              pylong_INT
#       define pylong_FROM_WINT         pylong_FROM_INT
#   elif WINT_MAX == LONG_MAX
#       define pylong_DIGITS_TO_WINT    pylong_DIGITS_TO_LONG
#       define pylong_WINT              pylong_LONG
#       define pylong_FROM_WINT         pylong_FROM_LONG
#   endif
#else
#   if WINT_MAX == USHRT_MAX
#       define pylong_DIGITS_TO_WINT    pylong_DIGITS_TO_USHRT
#       define pylong_WINT              pylong_USHRT
#       define pylong_FROM_WINT         pylong_FROM_USHRT
#   elif WINT_MAX == UINT_MAX
#       define pylong_DIGITS_TO_WINT    pylong_DIGITS_TO_UINT
#       define pylong_WINT              pylong_UINT
#       define pylong_FROM_WINT         pylong_FROM_UINT
#   elif WINT_MAX == ULONG_MAX
#       define pylong_DIGITS_TO_WINT    pylong_DIGITS_TO_ULONG
#       define pylong_WINT              pylong_ULONG
#       define pylong_FROM_WINT         pylong_FROM_ULONG
#   endif
#endif

#ifndef pylong_DIGITS_TO_WCHAR
#error "unsupported value defined for WCHAR_MAX"
#endif

#if   SIZE_MAX == USHRT_MAX
#   define pylong_DIGITS_TO_SIZE    pylong_DIGITS_TO_USHRT
#   define pylong_SIZE              pylong_USHRT
#   define pylong_FROM_SIZE         pylong_FROM_USHRT
#elif SIZE_MAX == UINT_MAX
#   define pylong_DIGITS_TO_SIZE    pylong_DIGITS_TO_UINT
#   define pylong_SIZE              pylong_UINT
#   define pylong_FROM_SIZE         pylong_FROM_UINT
#elif SIZE_MAX == ULONG_MAX
#   define pylong_DIGITS_TO_SIZE    pylong_DIGITS_TO_ULONG
#   define pylong_SIZE              pylong_ULONG
#   define pylong_FROM_SIZE         pylong_FROM_ULONG
#elif SIZE_MAX == ULLONG_MAX
#   define pylong_DIGITS_TO_SIZE    pylong_DIGITS_TO_ULLONG
#   define pylong_SIZE              pylong_ULLONG
#   define pylong_FROM_SIZE         pylong_FROM_ULLONG
#else
#   error "unsupported value defined for SIZE_MAX"
#endif

#if   SSIZE_MAX == SHRT_MAX
#   define pylong_DIGITS_TO_SSIZE   pylong_DIGITS_TO_SHRT
#   define pylong_SSIZE             pylong_SHRT
#   define pylong_FROM_SSIZE        pylong_FROM_SHRT
#elif SSIZE_MAX == INT_MAX
#   define pylong_DIGITS_TO_SSIZE   pylong_DIGITS_TO_INT
#   define pylong_SSIZE             pylong_INT
#   define pylong_FROM_SSIZE        pylong_FROM_INT
#elif SSIZE_MAX == LONG_MAX
#   define pylong_DIGITS_TO_SSIZE   pylong_DIGITS_TO_LONG
#   define pylong_SSIZE             pylong_LONG
#   define pylong_FROM_SSIZE        pylong_FROM_LONG
#elif SSIZE_MAX == LLONG_MAX
#   define pylong_DIGITS_TO_SSIZE   pylong_DIGITS_TO_LLONG
#   define pylong_SSIZE             pylong_LLONG
#   define pylong_FROM_SSIZE        pylong_FROM_LLONG
#else
#   error "unsupported value defined for SSIZE_MAX"
#endif

#if   UINTPTR_MAX == USHRT_MAX
#   define pylong_DIGITS_TO_UINTPTR pylong_DIGITS_TO_USHRT
#   define pylong_UINTPTR           pylong_USHRT
#   define pylong_FROM_UINTPTR      pylong_FROM_USHRT
#elif UINTPTR_MAX == UINT_MAX
#   define pylong_DIGITS_TO_UINTPTR pylong_DIGITS_TO_UINT
#   define pylong_UINTPTR           pylong_UINT
#   define pylong_FROM_UINTPTR      pylong_FROM_UINT
#elif UINTPTR_MAX == ULONG_MAX
#   define pylong_DIGITS_TO_UINTPTR pylong_DIGITS_TO_ULONG
#   define pylong_UINTPTR           pylong_ULONG
#   define pylong_FROM_UINTPTR      pylong_FROM_ULONG
#elif UINTPTR_MAX == ULLONG_MAX
#   define pylong_DIGITS_TO_UINTPTR pylong_DIGITS_TO_ULLONG
#   define pylong_UINTPTR           pylong_ULLONG
#   define pylong_FROM_UINTPTR      pylong_FROM_ULLONG
#else
#   error "unsupported value defined for UINTPTR_MAX"
#endif

#if   INTPTR_MAX == SHRT_MAX
#   define pylong_DIGITS_TO_INTPTR  pylong_DIGITS_TO_SHRT
#   define pylong_INTPTR            pylong_SHRT
#   define pylong_FROM_INTPTR       pylong_FROM_SHRT
#elif INTPTR_MAX == INT_MAX
#   define pylong_DIGITS_TO_INTPTR  pylong_DIGITS_TO_INT
#   define pylong_INTPTR            pylong_INT
#   define pylong_FROM_INTPTR       pylong_FROM_INT
#elif INTPTR_MAX == LONG_MAX
#   define pylong_DIGITS_TO_INTPTR  pylong_DIGITS_TO_LONG
#   define pylong_INTPTR            pylong_LONG
#   define pylong_FROM_INTPTR       pylong_FROM_LONG
#elif INTPTR_MAX == ULLONG_MAX
#   define pylong_DIGITS_TO_INTPTR  pylong_DIGITS_TO_LLONG
#   define pylong_INTPTR            pylong_LLONG
#   define pylong_FROM_INTPTR       pylong_FROM_LLONG
#else
#   error "unsupported value defined for INTPTR_MAX"
#endif

#if UINTMAX_MAX == ULONG_MAX
#   define pylong_DIGITS_TO_UINTMAX pylong_DIGITS_TO_ULONG
#   define pylong_UINTMAX           pylong_ULONG
#   define pylong_FROM_UINTMAX      pylong_FROM_ULONG
#elif UINTMAX_MAX == ULLONG_MAX
#   define pylong_DIGITS_TO_UINTMAX pylong_DIGITS_TO_ULLONG
#   define pylong_UINTMAX           pylong_ULLONG
#   define pylong_FROM_UINTMAX      pylong_FROM_ULONG
#else
#   error "unsupported value defined for UINTMAX_MAX"
#endif

#if INTMAX_MAX == LONG_MAX
#   define pylong_DIGITS_TO_INTMAX  pylong_DIGITS_TO_LONG
#   define pylong_INTMAX            pylong_LONG
#   define pylong_FROM_INTMAX       pylong_FROM_LONG
#elif INTMAX_MAX == ULLONG_MAX
#   define pylong_DIGITS_TO_INTMAX  pylong_DIGITS_TO_LLONG
#   define pylong_INTMAX            pylong_LLONG
#   define pylong_FROM_INTMAX       pylong_FROM_LLONG
#else
#   error "unsupported value defined for INTMAX_MAX"
#endif


#if   PTRDIFF_MAX == SHRT_MAX
#   define pylong_DIGITS_TO_PTRDIFF pylong_DIGITS_TO_SHRT
#   define pylong_PTRDIFF           pylong_SHRT
#   define pylong_FROM_PTRDIFF      pylong_FROM_SHRT
#elif PTRDIFF_MAX == INT_MAX
#   define pylong_DIGITS_TO_PTRDIFF pylong_DIGITS_TO_INT
#   define pylong_PTRDIFF           pylong_INT
#   define pylong_FROM_PTRDIFF      pylong_FROM_INT
#elif PTRDIFF_MAX == LONG_MAX
#   define pylong_DIGITS_TO_PTRDIFF pylong_DIGITS_TO_LONG
#   define pylong_PTRDIFF           pylong_LONG
#   define pylong_FROM_PTRDIFF      pylong_FROM_LONG
#elif PTRDIFF_MAX == ULLONG_MAX
#   define pylong_DIGITS_TO_PTRDIFF pylong_DIGITS_TO_LLONG
#   define pylong_PTRDIFF           pylong_LLONG
#   define pylong_FROM_PTRDIFF      pylong_FROM_LLONG
#else
#   error "unsupported value defined for PTRDIFF_MAX"
#endif

static               _Bool pylong_bool(PyObject *);
static                char pylong_char(PyObject *);
static unsigned       char pylong_uchar(PyObject *);
static   signed       char pylong_schar(PyObject *);
static   signed short int  pylong_short(PyObject *);
static unsigned short int  pylong_ushort(PyObject *);
static   signed       int  pylong_int(PyObject *);
static unsigned       int  pylong_uint(PyObject *);
static   signed  long int  pylong_long(PyObject *);
static unsigned  long int  pylong_ulong(PyObject *);
static   signed  long long pylong_llong(PyObject *);
static unsigned  long long pylong_ullong(PyObject *);

static       float pylong_flt(PyObject *);
static      double pylong_dbl(PyObject *);
static long double pylong_ldbl(PyObject *);

static inline void *
pylong_ADDR(PyObject *obj) {
    return PyLong_AsVoidPtr(obj);
}

static inline void **
pylong_ADDRPTR(PyObject *obj) {
    return (void **) PyLong_AsVoidPtr(obj);
}

static inline PyObject *
pylong_FROM_BOOL(_Bool x) {
    return Py_NewRef(unsys.ints[(int) x]);
}

static inline PyObject *
pylong_FROM_CHAR (char c) {
    return Py_NewRef(unsys.ints[(int) c]);
}

static inline PyObject *
pylong_FROM_UCHAR(unsigned char n) {
    return Py_NewRef(unsys.ints[n]);
}

static inline PyObject *
pylong_FROM_SCHAR(signed char m) {
    return Py_NewRef(unsys.ints[m]);
}

static inline PyObject *
pylong_FROM_USHRT(unsigned short n) {
    if (n < 257) {
        return Py_NewRef(unsys.ints[n]);
    }
    PyLongObject *v;
    v = pylong_NEW(1, 1);
    v->ob_digit[0] = (digit) n;
    return (PyObject *) v;
}

static inline PyObject *
pylong_FROM_SHRT (signed short m) {
    PyLongObject *v;
    if (m < 257) {
        if (m >= (0-128)) {
            return Py_NewRef(unsys.ints[m]);
        }
        if (m == SHRT_MIN) {
            return Py_NewRef(unsys.limits.py->shrt_min);
        }
        m = 0-m;
        v = pylong_NEW(1, 0-1);
    }
    else {
        if (m == SHRT_MAX) {
            return Py_NewRef(unsys.limits.py->shrt_max);
        }
        v = pylong_NEW(1, 1);
    }
    if (v == NULL) {
        return NULL;
    }
    v->ob_digit[0] = (digit) m;
    return (PyObject *) v;
}

static inline _Bool
pylong_DIGITS_TO_BOOL(const digit *b, Py_ssize_t n) {
    return n != 0; // ndigits can only be 0 if n is 0
}
static inline digit
pylong_DIGITS_TO_DIGIT(const digit *b, Py_ssize_t n) {
    if (n <= 0) {
        if (n == 0) {
            return 0;
        }
        return (digit) (0-(sdigit) b[0-(n+1)]);
    }
    return b[n-1];
}

static inline sdigit
pylong_DIGITS_TO_SDIGIT(const digit *b, Py_ssize_t n) {
    if (n <= 0) {
        if (n == 0) {
            return 0;
        }
        return (sdigit) (0-b[0+(n+1)]);
    }
    return (sdigit) b[n-1];
}

static inline char 
pylong_DIGITS_TO_CHAR(const digit *b, Py_ssize_t n) {
    return (char) pylong_DIGITS_TO_DIGIT(b, n);
}

static inline signed char 
pylong_DIGITS_TO_SCHAR(const digit *b, Py_ssize_t n) {
    return (signed char) pylong_DIGITS_TO_SDIGIT(b, n);
}

static inline unsigned char 
pylong_DIGITS_TO_UCHAR(const digit *b, Py_ssize_t n) {
    return (unsigned char) pylong_DIGITS_TO_DIGIT(b, n);
}

static inline short 
pylong_DIGITS_TO_SHRT(const digit *b, Py_ssize_t n) {
    return (signed short) pylong_DIGITS_TO_SDIGIT(b, n);
}

static inline unsigned short 
pylong_DIGITS_TO_USHRT(const digit *b, Py_ssize_t n) {
    return (unsigned short) pylong_DIGITS_TO_DIGIT(b, n);
}

static inline _Bool
pylong_BOOL(PyObject *a) {
    return Py_SIZE(a) != 0;
}

static inline char 
pylong_CHAR(PyObject *a) {
    return pylong_DIGITS_TO_CHAR(pylong_DIGITS(a), Py_SIZE(a));
}

static inline signed char
pylong_SCHAR(PyObject *a) {
    return pylong_DIGITS_TO_SCHAR(pylong_DIGITS(a), Py_SIZE(a));
}

static inline unsigned char
pylong_UCHAR(PyObject *a) {
    return pylong_DIGITS_TO_UCHAR(pylong_DIGITS(a), Py_SIZE(a));
}

static inline short
pylong_SHRT(PyObject *a) {
    return pylong_DIGITS_TO_SHRT(pylong_DIGITS(a), Py_SIZE(a));
}

static inline unsigned short
pylong_USHRT(PyObject *a) {
    return pylong_DIGITS_TO_USHRT(pylong_DIGITS(a), Py_SIZE(a));
}

static inline int
pylong_INT(PyObject *a) {
    return pylong_DIGITS_TO_INT(pylong_DIGITS(a), Py_SIZE(a));
}

static inline unsigned
pylong_UINT(PyObject *a) {
    return pylong_DIGITS_TO_UINT(pylong_DIGITS(a), Py_SIZE(a));
}

static inline long
pylong_LONG(PyObject *a) {
    return pylong_DIGITS_TO_LONG(pylong_DIGITS(a), Py_SIZE(a));
}

static inline unsigned long
pylong_ULONG(PyObject *a) {
    return pylong_DIGITS_TO_ULONG(pylong_DIGITS(a), Py_SIZE(a));
}

static inline long long
pylong_LLONG(PyObject *a) {
    return pylong_DIGITS_TO_LLONG(pylong_DIGITS(a), Py_SIZE(a));
}

static inline unsigned long long
pylong_ULLONG(PyObject *a) {
    return pylong_DIGITS_TO_ULLONG(pylong_DIGITS(a), Py_SIZE(a));
}

static inline int
pylong_DIGITS_CMP_INT(const digit *a, Py_ssize_t n, int b) {
    return pylong_DIGITS_TO_INT(a, n)-b;
}

static inline int
pylong_DIGITS_CMP_UINT(const digit *a, Py_ssize_t n, unsigned b) {
    if (n < 0) {
        return 0-1;
    }
    const unsigned l = pylong_DIGITS_TO_UINT(a, n);
    return (l < b) ? (0-1) : (l ==b) ? (000) : (001);
}

static inline int
uintmax_CMP_PYLONG(uintmax_t lhs, PyObject *rhs) {
    return pylong_UCMP_DIGITS(
        lhs,
        pylong_DIGITS(rhs),
        Py_SIZE(rhs)
    );
}

static inline int
intmax_CMP_PYLONG(intmax_t lhs, PyObject *rhs) {
    return pylong_SCMP_DIGITS(
        lhs,
        pylong_DIGITS(rhs),
        Py_SIZE(rhs)
    );
}

static inline PyObject *
pybool_LIKELY(_Bool x) {
    if (!x) {
        Py_RETURN_FALSE;
    }
    Py_RETURN_TRUE;
}

static inline PyObject *
pybool_UNLIKELY(_Bool x) {
    if (x) {
        Py_RETURN_TRUE;
    }
    Py_RETURN_FALSE;
}

static inline _Bool
bool_FROM_CMP(int cmp, int op) {
    switch (op) {
        case Py_LT: return cmp <  0;
        case Py_LE: return cmp <= 0;
        case Py_EQ: return cmp == 0;
        case Py_NE: return cmp != 0;
        case Py_GT: return cmp >  0;
        case Py_GE: return cmp >= 0;
        default: Py_UNREACHABLE();
    }
}

static inline PyObject *
pybool_FROM_CMP(int cmp, int op) {
    if (bool_FROM_CMP(cmp, op)) {
        Py_RETURN_TRUE;
    }
    Py_RETURN_FALSE;
}

static PyObject *
unsys_test_pylong_api2(PyObject *mod) {
    PyObject *bv = Py_BuildValue(
        "(iillllbbBhhHiiIllkLLKLLnKLLKLLK)",
        (CHAR_MIN),         (CHAR_MAX),
        (WCHAR_MIN+0L),     (WCHAR_MAX+0L),
        (WINT_MIN+0L),      (WINT_MAX+0L),
        (SCHAR_MIN),        (SCHAR_MAX),    (UCHAR_MAX),
        (SHRT_MIN),         (SHRT_MAX),     (USHRT_MAX),
        (INT_MIN),          (INT_MAX),      (UINT_MAX),
        (LONG_MIN),         (LONG_MAX),     (ULONG_MAX),
        (LLONG_MIN),        (LLONG_MAX),    (ULLONG_MAX),
        (PTRDIFF_MIN+0LL),  (PTRDIFF_MAX+0LL),
        (SSIZE_MAX),        (SIZE_MAX+0ULL),
        (INTPTR_MIN+0LL),   (INTPTR_MAX+0LL),(UINTPTR_MAX+0ULL),
        (INTMAX_MIN+0LL),   (INTMAX_MAX+0LL),(UINTMAX_MAX+0ULL)
    );
    PyObject **sq = ((PyTupleObject *) bv)->ob_item;
    printf("CHAR_MIN    = %+i\n",(int) pylong_CHAR(*sq++));
    printf("CHAR_MAX    = %+i\n",(int) pylong_CHAR(*sq++));
    printf("WCHAR_MIN   = %+li\n",(long)pylong_WCHAR(*sq++));
    printf("WCHAR_MAX   = %+li\n",(long)pylong_WCHAR(*sq++));
    printf("WINT_MIN    = %+li\n",(long)pylong_WINT(*sq++));
    printf("WINT_MAX    = %+li\n", (long)pylong_WINT(*sq++));
    printf("SCHAR_MIN   = %+hhi\n", pylong_SCHAR(*sq++));
    printf("SCHAR_MAX   = %+hhi\n", pylong_SCHAR(*sq++));
    printf("UCHAR_MAX   = +%hhu\n",pylong_UCHAR(*sq++));
    printf("SHRT_MIN    = %+hi\n",pylong_SHRT(*sq++));
    printf("SHRT_MAX    = %+hi\n",pylong_SHRT(*sq++));
    printf("USHRT_MAX   = +%hu\n",pylong_USHRT(*sq++));
    printf("INT_MIN     = %+i\n", pylong_INT(*sq++));
    printf("INT_MAX     = %+i\n", pylong_INT(*sq++));
    printf("UINT_MAX    = +%u\n", pylong_UINT(*sq++));
    printf("LONG_MIN    = %+li\n", pylong_LONG(*sq++));
    printf("LONG_MAX    = %+li\n", pylong_LONG(*sq++));
    printf("ULONG_MAX   = +%lu\n", pylong_ULONG(*sq++));
    printf("LLONG_MIN   = %+lli\n", pylong_LLONG(*sq++));
    printf("LLONG_MAX   = %+lli\n", pylong_LLONG(*sq++));
    printf("ULLONG_MAX  = +%llu\n", pylong_ULLONG(*sq++));
    printf("PTRDIFF_MIN = %+ti\n", pylong_PTRDIFF(*sq++));
    printf("PTRDIFF_MAX = %+ti\n", pylong_PTRDIFF(*sq++));
    printf("SSIZE_MAX   = %+zi\n", pylong_SSIZE(*sq++));
    printf("SIZE_MAX    = +%zu\n", pylong_SIZE(*sq++));
    printf("INTPTR_MIN  = %+ji\n", (intmax_t) pylong_INTPTR(*sq++));
    printf("INTPTR_MAX  = %+ji\n", (intmax_t) pylong_INTPTR(*sq++));
    printf("UINTPTR_MAX = +%ju\n", (uintmax_t) pylong_UINTPTR(*sq++));
    printf("INTMAX_MIN  = %+ji\n", pylong_INTPTR(*sq++));
    printf("INTMAX_MAX  = %+ji\n", pylong_INTPTR(*sq++));
    printf("UINTMAX_MAX = +%ju\n", pylong_UINTPTR(*sq++));
    Py_DECREF(bv);
    Py_RETURN_NONE;
    /*
    PyObject *ob = Py_BuildValue(
        "("
        "ii"    // c_min c_max
        "ll"    // s_min s_max 
        "ll"    // C_min C_max
        "iiI"   // b_min b_max B_max
        "hhH"   // h_min h_max H_max
        "iiI"   // i_min i_max I_max
        "llk"   // l_min l_max L_max
        "LLK"   // v_min v_max V_max
        "nK"    // Z_max z_max
        "LLK"   // p_min p_max P_max
        "LL"    // t_min t_max
        "LLK"   // j_min j_max J_max
        ")",
        
        (0+CHAR_MIN),         (0+CHAR_MAX),
        (0L+WCHAR_MIN),     (0L+WCHAR_MAX),
        (0L+WINT_MIN),      (0L+WINT_MAX),
        (0+SCHAR_MIN),      (0+SCHAR_MAX),      (0u+UCHAR_MAX),
        (SHRT_MIN),         (SHRT_MAX),         (USHRT_MAX),
        (INT_MIN),          (INT_MAX),          (UINT_MAX),
        (LONG_MIN),         (LONG_MAX),         (ULONG_MAX),
        (LLONG_MIN),        (LLONG_MAX),        (ULLONG_MAX),
        (SSIZE_MAX),        (0ULL+SIZE_MAX),
        (0LL+INTPTR_MIN),   ( 0LL+INTPTR_MAX),  (0ULL+UINTPTR_MAX),
        (0LL+PTRDIFF_MIN),  ( 0LL+PTRDIFF_MAX),
        (0LL+INTMAX_MIN),   ( 0LL+INTMAX_MAX),  (0ULL+UINTMAX_MAX)
    );
    int ctr = 0;
    PyObject **sq = ((PyTupleObject *) ob)->ob_item;

    char CHAR_VAR = pylong_CHAR(sq[ctr++]);
    printf("CHAR_MIN = %+i\n", (int) CHAR_VAR);
    printf("CHAR_MAX = %+i\n\n", (int) pylong_CHAR(sq[ctr++]));

    wchar_t WCHAR_VAR = pylong_WCHAR(sq[ctr++]);
    printf("WCHAR_MIN = %+li\n", (long) WCHAR_VAR);
    printf("WCHAR_MAX = %+li\n\n", (long) pylong_WCHAR(sq[ctr++]));

    wint_t WINT_VAR = pylong_WINT(sq[ctr++]);
    printf("WINT_MIN = %+li\n", (long) WINT_VAR);
    printf("WINT_MAX = %+li\n\n", (long) pylong_WINT(sq[ctr++]));

    signed      char SCHAR_VAR = pylong_SCHAR(sq[ctr++]);
    unsigned    char UCHAR_VAR = pylong_UCHAR(sq[ctr++]);
    printf("SCHAR_MIN   = %+hhi\n", SCHAR_VAR);
    SCHAR_VAR = pylong_SCHAR(sq[ctr++]);
    printf("SCHAR_MAX   = %+hhi\n", SCHAR_VAR);
    printf("UCHAR_MAX   = +%hhu\n\n", UCHAR_VAR);

    signed   short  SHRT_VAR = pylong_SHRT(sq[ctr++]);
    unsigned short USHRT_VAR = pylong_USHRT(sq[ctr++]);
    printf("SHRT_MIN    = %+hi\n", SHRT_VAR);
    printf("SHRT_MAX    = %+hi\n", pylong_SHRT(sq[ctr++]));
    printf("USHRT_MAX   = +%hu\n\n", USHRT_VAR);

    signed   int  INT_VAR = pylong_INT(sq[ctr++]);
    unsigned int UINT_VAR = pylong_UINT(sq[ctr++]);
    printf("INT_MIN     = %+i\n", INT_VAR);
    printf("INT_MAX     = %+i\n", pylong_INT(sq[ctr++]));
    printf("UINT_MAX    = +%u\n\n", UINT_VAR);

    signed   long  LONG_VAR = pylong_LONG(sq[ctr++]);
    unsigned long ULONG_VAR = pylong_ULONG(sq[ctr++]);
    printf("LONG_MIN    = %+li\n", LONG_VAR);
    printf("LONG_MAX    = %+li\n", pylong_LONG(sq[ctr++]));
    printf("ULONG_MAX   = +%lu\n\n", ULONG_VAR);

    signed   long long  LLONG_VAR = pylong_LLONG(sq[ctr++]);
    unsigned long long ULLONG_VAR = pylong_ULLONG(sq[ctr++]);
    printf("LLONG_MIN   = %+lli\n", LLONG_VAR);
    printf("LLONG_MAX   = %+lli\n", pylong_LLONG(sq[ctr++]));
    printf("ULLONG_MAX  = +%llu\n\n", ULLONG_VAR);

    ssize_t SSIZE_VAR = pylong_SSIZE(sq[ctr++]);
    size_t   SIZE_VAR = pylong_SIZE(sq[ctr++]);
    printf("SSIZE_MAX   = %+zi\n",  SSIZE_VAR);
    printf("SIZE_MAX    = +%zu\n\n", SIZE_VAR);

    intptr_t   INTPTR_VAR = pylong_INTPTR(sq[ctr++]);
    uintptr_t UINTPTR_VAR = pylong_UINTPTR(sq[ctr++]);
    printf("INTPTR_MIN  = %+ji\n",   (intmax_t) INTPTR_VAR);
    printf("INTPTR_MAX  = %+ji\n",   (intmax_t)pylong_INTPTR(sq[ctr++]));
    printf("UINTPTR_MAX = +%ju\n\n",(uintmax_t) UINTPTR_VAR);

    ptrdiff_t PTRDIFF_VAR = pylong_PTRDIFF(sq[ctr++]);
    printf("PTRDIFF_MAX = %+ti\n", PTRDIFF_VAR);
    printf("PTRDIFF_MIN = %+ti\n\n", pylong_PTRDIFF(sq[ctr++]));

    intmax_t INTMAX_VAR = pylong_INTMAX(sq[ctr++]);
    uintmax_t UINTMAX_VAR = pylong_UINTMAX(sq[ctr++]);
    printf("INTMAX_MAX  = %+ji\n", INTMAX_VAR);
    printf("INTMAX_MIN  = %+ji\n", pylong_INTMAX(sq[ctr++]));
    printf("UINTMAX_MAX = +%ju\n\n", UINTMAX_VAR);

    return ob;
    return 0;
    */
}

static PyObject *
unsys_test_pylong_api(PyObject *mod) {
    short h_case[] = {
        SHRT_MIN,   SHRT_MIN+1,
        SCHAR_MIN-1, SCHAR_MIN,
        0-1, 0, 0+1,
        SCHAR_MAX-1, SCHAR_MAX,
        SHRT_MAX-1,  SHRT_MAX,
    };
    Py_ssize_t n = (Py_ssize_t) unsys_ARRAYLEN(h_case);
    PyObject *h_res = PyTuple_New(n);
    PyObject**s = ((PyTupleObject *) h_res)->ob_item;
    for (int i=0; i < n; i++) {
        s[i] = pylong_FROM_SHRT(h_case[i]);
    }
    unsigned short H_case[] = {
        0, UCHAR_MAX-1, UCHAR_MAX, UCHAR_MAX+1,
        USHRT_MAX-1, USHRT_MAX,
    };
    n = (Py_ssize_t) unsys_ARRAYLEN(H_case);
    PyObject *H_res = PyTuple_New(n);
    s = ((PyTupleObject *) H_res)->ob_item;
    for (int i=0; i < n; i++) {
        s[i] = pylong_FROM_USHRT(H_case[i]);
    }
    int i_case[] = {
        INT_MIN, INT_MIN+1,
        SHRT_MIN, SHRT_MIN+1,
        SCHAR_MIN, SCHAR_MIN+1,
        0-1, 0, 0+1,
        UCHAR_MAX-1, UCHAR_MAX,
        USHRT_MAX-1, USHRT_MAX,
        INT_MAX-1, INT_MAX,
    };
    n = (Py_ssize_t) unsys_ARRAYLEN(i_case);
    PyObject *i_res = PyTuple_New(n);
    s = ((PyTupleObject *) i_res)->ob_item;
    for (int i=0; i < n; i++) {
        s[i] = pylong_FROM_INT(i_case[i]);
    }
    unsigned I_case[] = {
        0, UCHAR_MAX-1, UCHAR_MAX, UCHAR_MAX+1,
        USHRT_MAX-1, USHRT_MAX, 
        UINT_MAX-1, UINT_MAX,
    };
    n = (Py_ssize_t) unsys_ARRAYLEN(I_case);
    PyObject *I_res = PyTuple_New(n);
    s = ((PyTupleObject *) I_res)->ob_item;
    for (int i=0; i < n; i++) {
        s[i] = pylong_FROM_UINT(I_case[i]);
    }
    long l_case[] = {
        LONG_MIN, LONG_MIN+1,
        INT_MIN, INT_MIN+1,
        SHRT_MIN, SHRT_MIN+1,
        SCHAR_MIN, SCHAR_MIN+1,
        0-1, 0, 0+1,
        UCHAR_MAX-1, UCHAR_MAX,
        USHRT_MAX-1, USHRT_MAX,
        INT_MAX-1, INT_MAX,
        LONG_MAX-1, LONG_MAX,
    };
    n = (Py_ssize_t) unsys_ARRAYLEN(l_case);
    PyObject *l_res = PyTuple_New(n);
    s = ((PyTupleObject *) l_res)->ob_item;
    for (int i=0; i < n; i++) {
        s[i] = pylong_FROM_LONG(l_case[i]);
    }
    unsigned long L_case[] = {
        0, UCHAR_MAX-1, UCHAR_MAX, UCHAR_MAX+1,
        USHRT_MAX-1, USHRT_MAX, 
        UINT_MAX-1, UINT_MAX,
        ULONG_MAX-1, ULONG_MAX,
    };
    n = (Py_ssize_t) unsys_ARRAYLEN(L_case);
    PyObject *L_res = PyTuple_New(n);
    s = ((PyTupleObject *) L_res)->ob_item;
    for (int i=0; i < n; i++) {
        s[i] = pylong_FROM_ULONG(L_case[i]);
    }
    long long v_case[] = {
        LLONG_MIN,   LLONG_MIN+1,
        LONG_MIN,     LONG_MIN+1,
        INT_MIN,       INT_MIN+1,
        SHRT_MIN,     SHRT_MIN+1,
        SCHAR_MIN,   SCHAR_MIN+1,
        0-1, 0, 0+1,
        UCHAR_MAX-1, UCHAR_MAX,
        USHRT_MAX-1, USHRT_MAX,
        INT_MAX-1,     INT_MAX,
        UINT_MAX-1,   UINT_MAX,
        LONG_MAX-1,   LONG_MAX,
        LLONG_MAX-1, LLONG_MAX,
    };
    n = (Py_ssize_t) unsys_ARRAYLEN(v_case);
    PyObject *v_res = PyTuple_New(n);
    s = ((PyTupleObject *) v_res)->ob_item;
    for (int i=0; i < n; i++) {
        s[i] = pylong_FROM_LLONG(v_case[i]);
    }
    unsigned long long V_case[] = {
        0, 
        UCHAR_MAX-1,   UCHAR_MAX, UCHAR_MAX+1,
        USHRT_MAX-1,   USHRT_MAX, 
        UINT_MAX-1,     UINT_MAX,
        ULONG_MAX-1,   ULONG_MAX,
        ULLONG_MAX-1, ULLONG_MAX,
    };
    n = (Py_ssize_t) unsys_ARRAYLEN(V_case);
    PyObject *V_res = PyTuple_New(n);
    s = ((PyTupleObject *) V_res)->ob_item;
    for (int i=0; i < n; i++) {
        s[i] = pylong_FROM_ULLONG(V_case[i]);
    }
    return Py_BuildValue(
        "NN" "NN" "NN" "NN", 
        h_res, H_res, 
        i_res, I_res,
        l_res, L_res,
        v_res, V_res
    );
}

static inline int 
pylong_cmp_stest(intmax_t a, intmax_t b, int op, _Bool x) {
    PyObject *tmp = pylong_FROM_INTMAX(b);
    assert(tmp);
    int cmp = intmax_CMP_PYLONG(a, tmp);
    Py_DECREF(tmp);
    int r = bool_FROM_CMP(cmp, op);
    if (x == r) {
        return 0;
    }
    const char *fmt;
    switch (op) {
        case Py_LT: fmt = "%ji <  %ji:   %i\n"; break;
        case Py_LE: fmt = "%ji <= %ji:   %i\n"; break;
        case Py_EQ: fmt = "%ji == %ji:   %i\n"; break;
        case Py_NE: fmt = "%ji != %ji:   %i\n"; break;
        case Py_GT: fmt = "%ji >  %ji:   %i\n"; break;
        case Py_GE: fmt = "%ji >= %ji:   %i\n"; break;
        default: Py_UNREACHABLE();
    }
    return printf(fmt, a, b, r);
}

static inline int 
pylong_cmp_utest(uintmax_t a, uintmax_t b, int op, _Bool x) {
    PyObject *tmp = pylong_FROM_UINTMAX(b);
    assert(tmp);
    int cmp = uintmax_CMP_PYLONG(a, tmp);
    Py_DECREF(tmp);
    int r = bool_FROM_CMP(cmp, op);
    if (x == r) {
        return 0;
    }
    const char *fmt;
    switch (op) {
        case Py_LT: fmt = "%ju <  %ju:   %i\n"; break;
        case Py_LE: fmt = "%ju <= %ju:   %i\n"; break;
        case Py_EQ: fmt = "%ju == %ju:   %i\n"; break;
        case Py_NE: fmt = "%ju != %ju:   %i\n"; break;
        case Py_GT: fmt = "%ju >  %ju:   %i\n"; break;
        case Py_GE: fmt = "%ju >= %ju:   %i\n"; break;
        default: Py_UNREACHABLE();
    }
    return printf(fmt, a, b, r);
}

static PyObject *
pylong_cmp_test(PyObject *mod) {
#   define pylong_cmp_itest pylong_cmp_stest
    {
        intmax_t a = 0;
        intmax_t b = 0;
        intmax_t d1_min = (INTMAX_C(1));
        intmax_t d1_max = (INTMAX_C(1)<<30)-1;
        intmax_t d2_min = (INTMAX_C(1)<<30);
        intmax_t d2_max = (INTMAX_C(1)<<60)-1;
        intmax_t d3_min = (INTMAX_C(1)<<60);
        intmax_t d3_max = INTMAX_MAX;
        while (1) {
            if (pylong_cmp_itest(a, b, Py_LT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 1)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 1)) break;
            b = d1_min;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
            b = d1_max;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
            b = d2_min;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
            b = d2_max;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
    
            b = d3_min;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
    
            b = d3_max;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
    
            a = d1_max;
            b = (INTMAX_C(0));
            if (pylong_cmp_itest(a, b, Py_LT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 0)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 1)) break;
            
            b = d1_max;
            if (pylong_cmp_itest(a, b, Py_LT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 1)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 1)) break;
    
            b = d2_min;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
            
            b = d2_max;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
            
            b = d3_min;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
            
            b = d3_max;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
            
            a = d2_min;
            b = 0;
            if (pylong_cmp_itest(a, b, Py_LT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 0)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 1)) break;
    
            b = d1_max;
            if (pylong_cmp_itest(a, b, Py_LT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 0)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 1)) break;
    
            b = d2_min;
            if (pylong_cmp_itest(a, b, Py_LT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 1)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 1)) break;
            
            b = d2_max;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
            
            b = d3_min;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
            
            b = d3_max;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
            
            a = d3_min;
            b = 0;
            if (pylong_cmp_itest(a, b, Py_LT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 0)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 1)) break;
    
            b = d2_min;
            if (pylong_cmp_itest(a, b, Py_LT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 0)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 1)) break;
    
            b = d2_max;
            if (pylong_cmp_itest(a, b, Py_LT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 0)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 1)) break;
    
            b = d3_min;
            if (pylong_cmp_itest(a, b, Py_LT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 1)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 1)) break;
    
            b = d3_max;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
    
            a = d3_max;
            if (pylong_cmp_itest(a, b, Py_LT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 1)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 1)) break;
            
            a = INTMAX_MIN;
            b = INTMAX_MIN;
            if (pylong_cmp_itest(a, b, Py_LT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 1)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 1)) break;
    
            b = 0-d3_min;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
    
            b = 0-d2_max;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
    
            b = 0-d2_min;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
    
            b = 0-d1_max;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
    
            b = 0;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
    
            b = d1_min;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
    
            b = d1_max;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
    
            b = d2_min;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
    
            b = d2_max;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
    
            b = d3_min;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
    
            b = d3_max;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
            
            b = INTMAX_MIN;
            a = b+1;
            if (pylong_cmp_itest(a, b, Py_LT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 0)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 1)) break;
    
            b = a;
            if (pylong_cmp_itest(a, b, Py_LT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 1)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 1)) break;
    
            b = 0-d3_min;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
    
            b = 0-d2_min;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
    
            b = 0-d1_min;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
    
            a = 0-d3_min;
            b = a;
            if (pylong_cmp_itest(a, b, Py_LT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 1)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 1)) break;
    
            b = 0-d2_max;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
    
            break;
        }
    }
#   undef pylong_cmp_itest
#   define pylong_cmp_itest pylong_cmp_utest
    {
        uintmax_t a = 0;
        uintmax_t b = 0;
        uintmax_t d1_min = (UINTMAX_C(1));
        uintmax_t d1_max = (UINTMAX_C(1)<<30)-1;
        uintmax_t d2_min = (UINTMAX_C(1)<<30);
        uintmax_t d2_max = (UINTMAX_C(1)<<60)-1;
        uintmax_t d3_min = (UINTMAX_C(1)<<60);
        uintmax_t d3_max = (UINTMAX_MAX);
        while (1) {
            if (pylong_cmp_itest(a, b, Py_LT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 1)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 1)) break;
            a = d1_min;
            if (pylong_cmp_itest(a, b, Py_LT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 0)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 1)) break;
            a = d2_min;
            if (pylong_cmp_itest(a, b, Py_LT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 0)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 1)) break;
            a = d3_min;
            if (pylong_cmp_itest(a, b, Py_LT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 0)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 1)) break;
            a = d3_max;
            if (pylong_cmp_itest(a, b, Py_LT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 0)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 1)) break;
            a = 0;
            b = d1_min;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
            b = d2_min;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
            b = d3_min;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
            b = d3_max;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
            a = d2_max;
            b = d2_max;
            if (pylong_cmp_itest(a, b, Py_LT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 1)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 1)) break;
            b = d3_min;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
            a = d3_min;
            if (pylong_cmp_itest(a, b, Py_LT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 1)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 1)) break;
            b = d3_max;
            if (pylong_cmp_itest(a, b, Py_LT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 0)) break;
            a = d3_max;
            if (pylong_cmp_itest(a, b, Py_LT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 1)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 1)) break;
            b = d3_min;
            if (pylong_cmp_itest(a, b, Py_LT, 0)) break;
            if (pylong_cmp_itest(a, b, Py_LE, 0)) break;
            if (pylong_cmp_itest(a, b, Py_EQ, 0)) break;
            if (pylong_cmp_itest(a, b, Py_NE, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GT, 1)) break;
            if (pylong_cmp_itest(a, b, Py_GE, 1)) break;
            break;
        }
    }
    Py_RETURN_NONE;
}

static PyObject *pylong_rdy(_Bool *ptr) {
    return pylong_FROM_BOOL(*ptr);
}

static PyObject *pylong_rdc(char *ptr) {
    return pylong_FROM_CHAR(*ptr);
}

static PyObject *pylong_rdb(signed char *ptr) {
    return pylong_FROM_SCHAR(*ptr);
}

static PyObject *pylong_rdh(short *ptr) {
    return pylong_FROM_SHRT(*ptr);
}

static PyObject *pylong_rdi(int *ptr){
    return pylong_FROM_INT(*ptr);
}

static PyObject *pylong_rdl(long *ptr){
    return pylong_FROM_LONG(*ptr);
}

static PyObject *pylong_rdv(long long *ptr){
    return pylong_FROM_LLONG(*ptr);
}

static PyObject *pylong_rdB(unsigned char *ptr){
    return pylong_FROM_UCHAR(*ptr);
}

static PyObject *pylong_rdH(unsigned short*ptr){
    return pylong_FROM_USHRT(*ptr);
}

static PyObject *pylong_rdI(unsigned int *ptr){
    return pylong_FROM_UINT(*ptr);
}

static PyObject *pylong_rdL(unsigned long *ptr){
    return pylong_FROM_ULONG(*ptr);
}

static PyObject *pylong_rdV(unsigned long long *ptr){
    return pylong_FROM_ULLONG(*ptr);
}

static PyObject *pylong_rda(void **ptr) {
    return pylong_FROM_UINTPTR((uintptr_t) *ptr);
}

static PyObject *pylong_rdA(void ***ptr) {
    return pylong_FROM_UINTPTR((uintptr_t) *ptr);
}

static inline Py_ssize_t
pylong_LENGTH(PyObject *obj) {
    if (Py_SIZE(obj) < 0) {
        return 0-Py_SIZE(obj);
    }
    return Py_SIZE(obj);
}

static inline float 
pylong_FLT(PyObject *obj) {
    return (float) PyLong_AsDouble(obj);
}

static inline double
pylong_DBL(PyObject *obj) {
    return pylong_DIGITS_TO_DBL(pylong_DIGITS(obj), Py_SIZE(obj));
}

static inline int
pylong_INDEX(PyObject *obj, Py_ssize_t *index) {
    return pylong_DIGITS_TO_INDEX(index, pylong_DIGITS(obj), Py_SIZE(obj));
}

static inline long double
pylong_LDBL(PyObject *obj) {
    return PyLong_AsDouble(obj);
}

static inline PyObject *
pylong_FROM_FLT(float v) {
    return PyLong_FromDouble(v);
}

static inline PyObject *
pylong_FROM_DBL(double v) {
    return PyLong_FromDouble(v);
}

static inline PyObject *
pylong_FROM_LDBL(long double v) {
    return PyLong_FromDouble((double) v);
}
