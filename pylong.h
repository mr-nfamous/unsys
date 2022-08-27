

/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

In house PyLongObject API.
*/

#ifndef _UNSYS_PYLONG_H
#define _UNSYS_PYLONG_H

static inline PyLongObject *
pylong_NEW(size_t ndigit, Py_ssize_t ob_size) {
    /*
    An alternative to _PyLong_New that doesn't waste time with
    the following checks which in practice are never true:
    *   ndigit != 0
    *   ndigit < MAX_LONG_DIGITS 
    */
    void *v = PyObject_Malloc(
            offsetof(PyLongObject, ob_digit)
        +   sizeof(digit)*ndigit
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

#   define pylong_DIGITS_TO_INT     pylong30_DIGITS_TO_INT
#   define pylong_DIGITS_TO_UINT    pylong30_DIGITS_TO_UINT
#   define pylong_DIGITS_TO_LONG    pylong30_DIGITS_TO_LONG
#   define pylong_DIGITS_TO_ULONG   pylong30_DIGITS_TO_ULONG
#   define pylong_DIGITS_TO_LLONG   pylong30_DIGITS_TO_LLONG
#   define pylong_DIGITS_TO_ULLONG  pylong30_DIGITS_TO_ULLONG
#   define pylong_FROM_UINT         pylong30_FROM_UINT
#   define pylong_FROM_INT          pylong30_FROM_INT
#   define pylong_FROM_ULONG        pylong30_FROM_ULONG
#   define pylong_FROM_LONG         pylong30_FROM_LONG
#   define pylong_FROM_ULLONG       pylong30_FROM_ULLONG
#   define pylong_FROM_LLONG        pylong30_FROM_LLONG
#endif // PyLong_SHIFT == 15

#define pylong_DIGITS_TO_INT8       pylong_DIGITS_TO_SCHAR
#define pylong_DIGITS_TO_UINT8      pylong_DIGITS_TO_UCHAR
#define pylong_DIGITS_TO_UINT16     pylong_DIGITS_TO_USHORT
#define pylong_DIGITS_TO_UINT32     pylong_DIGITS_TO_UINT

#if INT64_MAX == LONG_MAX

#   define pylong_DIGITS_TO_INT64   pylong_DIGITS_TO_LONG
#   define pylong_DIGITS_TO_UINT64  pylong_DIGITS_TO_ULONG

#else

#   define pylong_DIGITS_TO_INT64   pylong_DIGITS_TO_LLONG
#   define pylong_DIGITS_TO_UINT64  pylong_DIGITS_TO_ULLONG

#endif

#if SIZE_MAX == UINT32_MAX

#   define pylong_DIGITS_TO_SIZE    pylong_DIGITS_TO_UINT32
#   define pylong_DIGITS_TO_PTRDIFF pylong_DIGITS_TO_INT32
#   define pylong_DIGITS_TO_INTPTR  pylong_DIGITS_TO_INT32
#   define pylong_DIGITS_TO_UINTPTR pylong_DIGITS_TO_UINT32

#elif SIZE_MAX == UINT64_MAX

#   define pylong_DIGITS_TO_SIZE    pylong_DIGITS_TO_UINT64
#   define pylong_DIGITS_TO_PTRDIFF pylong_DIGITS_TO_INT64
#   define pylong_DIGITS_TO_INTPTR  pylong_DIGITS_TO_INT64
#   define pylong_DIGITS_TO_UINTPTR pylong_DIGITS_TO_UINT64

#else

#   error "unsupported value defined for SIZE_MAX"

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

static inline digit *
pylong_DIGITS(PyObject *v) {
    return ((PyLongObject *) v)->ob_digit;
}

static inline _Bool
pylong_DIGITS_TO_BOOL(const digit *b, Py_ssize_t i) {
    return i != 0;
}

static inline char 
pylong_DIGITS_TO_CHAR(const digit *b, Py_ssize_t i) {
    if (i == 0) {
        return 0;
    }
    return (char) ((i < 0) ? b[0-(i+1)] : b[i-1]);
}

static inline signed char 
pylong_DIGITS_TO_SCHAR(const digit *b, Py_ssize_t i) {
    if (i == 0) {
        return 0;
    }
    return (signed char) ((i < 0) ? 0-b[0-(i+1)] : b[i-1]);
}

static inline unsigned char 
pylong_DIGITS_TO_UCHAR(const digit *b, Py_ssize_t i) {
    if (i <= 0) {
        return !i ? 0 : ((unsigned char) (0-(sdigit) b[0-(i+1)]));
    }
    return (unsigned char) b[i-1];
}

static inline short 
pylong_DIGITS_TO_SHORT(const digit *b, Py_ssize_t i) {
    if (i <= 0) {
        return !i ? 0 : ((short) (0-(sdigit) b[0-(i+1)]));
    }
    return (short) b[i-1];
}

static inline unsigned short 
pylong_DIGITS_TO_USHORT(const digit *b, Py_ssize_t i) {
    if (i <= 0) {
        return !i ? 0 : ((unsigned short) (0-(sdigit) b[0-(i+1)]));
    }
    return (unsigned short) b[i-1];
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
pylong_SHORT(PyObject *a) {
    return pylong_DIGITS_TO_SHORT(pylong_DIGITS(a), Py_SIZE(a));
}

static inline unsigned short
pylong_USHORT(PyObject *a) {
    return pylong_DIGITS_TO_USHORT(pylong_DIGITS(a), Py_SIZE(a));
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

static inline PyObject *
pylong_FROM_BOOL (PyObject *mod, _Bool x) {
    return Py_NewRef(unsys_state(mod)->ints[x]);
}

static inline PyObject *
pylong_FROM_CHAR (PyObject *mod,          char c) {
    return Py_NewRef(unsys_state(mod)->ints[(int) c]);
}

static inline PyObject *
pylong_FROM_UCHAR(PyObject *mod, unsigned char n) {
    return Py_NewRef(unsys_state(mod)->ints[n]);
}

static inline PyObject *
pylong_FROM_SCHAR(PyObject *mod,   signed char m) {
    return Py_NewRef(unsys_state(mod)->ints[m]);
}


#endif // ifndef _UNSYS_PYLONG_H