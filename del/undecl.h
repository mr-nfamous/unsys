
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#pragma once

#define unsys_ASDEF(R, C, T, P, K) static R C##_AS_##T(P *o) {return (R) o->K;}

#define unsys_UVAL_DEF(R, C, T, P) static R C##_AS_##T(P *o) {return (R) o->uval;}

#define unsys_SVAL_DEF(R, C, T, P) static R C##_AS_##T(P *o) {return (R) o->sval;}
#define unsys_YVAL_DEF(R, C, T, P) static R C##_AS_##T(P *o) {return (R) o->yval;}
#define unsys_FVAL_DEF(R, C, T) static R C##_AS_##T(C *o) {return (R) o->fval;}
#define unsys_ASTAB_DEF(C) static union unsys_as C##_AS = {\
    .list = {\
        [AS_ADDR]       = C##_AS_ADDR,\
        [AS_ADDRPTR]    = C##_AS_ADDRPTR,\
        [AS_CHAR]       = C##_AS_CHAR,\
        [AS_WCHAR]      = C##_AS_WCHAR,\
        [AS_CHAR16]     = C##_AS_CHAR16,\
        [AS_CHAR32]     = C##_AS_CHAR32,\
        [AS_FLT]        = C##_AS_FLT,\
        [AS_DBL]        = C##_AS_DBL,\
        [AS_SCHAR]      = C##_AS_SCHAR,\
        [AS_SHRT]       = C##_AS_SHRT,\
        [AS_INT]        = C##_AS_INT,\
        [AS_LONG]       = C##_AS_LONG,\
        [AS_LLONG]      = C##_AS_LLONG,\
        [AS_SSIZE]      = C##_AS_SSIZE,\
        [AS_INTPTR]     = C##_AS_INTPTR,\
        [AS_PTRDIFF]    = C##_AS_PTRDIFF,\
        [AS_INT8]       = C##_AS_INT8,\
        [AS_INT16]      = C##_AS_INT16,\
        [AS_INT32]      = C##_AS_INT32,\
        [AS_INT64]      = C##_AS_INT64,\
        [AS_INTMAX]     = C##_AS_INTMAX,\
        [AS_UCHAR]      = C##_AS_UCHAR,\
        [AS_USHRT]      = C##_AS_USHRT,\
        [AS_UINT]       = C##_AS_UINT,\
        [AS_ULONG]      = C##_AS_ULONG,\
        [AS_ULLONG]     = C##_AS_ULLONG,\
        [AS_SIZE]       = C##_AS_SIZE,\
        [AS_UINTPTR]    = C##_AS_UINTPTR,\
        [AS_UINT8]      = C##_AS_UINT8,\
        [AS_UINT16]     = C##_AS_UINT16,\
        [AS_UINT32]     = C##_AS_UINT32,\
        [AS_UINT64]     = C##_AS_UINT64,\
        [AS_UINTMAX]    = C##_AS_UINTMAX,\
        [AS_WINT]       = C##_AS_WINT,\
        [AS_BIGINT]     = C##_AS_BIGINT,\
    }}
#define unsys_ASTAB_FLT(C) static union unsys_as C##_AS = {\
    .list = {\
        [AS_ADDR]       = 0,\
        [AS_ADDRPTR]    = 0,\
        [AS_CHAR]       = 0,\
        [AS_WCHAR]      = 0,\
        [AS_CHAR16]     = 0,\
        [AS_CHAR32]     = 0,\
        [AS_FLT]        = C##_AS_FLT,\
        [AS_DBL]        = C##_AS_DBL,\
        [AS_SCHAR]      = C##_AS_SCHAR,\
        [AS_SHRT]       = C##_AS_SHRT,\
        [AS_INT]        = C##_AS_INT,\
        [AS_LONG]       = C##_AS_LONG,\
        [AS_LLONG]      = C##_AS_LLONG,\
        [AS_SSIZE]      = C##_AS_SSIZE,\
        [AS_INTPTR]     = C##_AS_INTPTR,\
        [AS_PTRDIFF]    = C##_AS_PTRDIFF,\
        [AS_INT8]       = C##_AS_INT8,\
        [AS_INT16]      = C##_AS_INT16,\
        [AS_INT32]      = C##_AS_INT32,\
        [AS_INT64]      = C##_AS_INT64,\
        [AS_INTMAX]     = C##_AS_INTMAX,\
        [AS_UCHAR]      = C##_AS_UCHAR,\
        [AS_USHRT]      = C##_AS_USHRT,\
        [AS_UINT]       = C##_AS_UINT,\
        [AS_ULONG]      = C##_AS_ULONG,\
        [AS_ULLONG]     = C##_AS_ULLONG,\
        [AS_SIZE]       = C##_AS_SIZE,\
        [AS_UINTPTR]    = C##_AS_UINTPTR,\
        [AS_UINT8]      = C##_AS_UINT8,\
        [AS_UINT16]     = C##_AS_UINT16,\
        [AS_UINT32]     = C##_AS_UINT32,\
        [AS_UINT64]     = C##_AS_UINT64,\
        [AS_UINTMAX]    = C##_AS_UINTMAX,\
        [AS_WINT]       = C##_AS_WINT,\
        [AS_BIGINT]     = C##_AS_BIGINT,\
    }}

typedef union unref unref_t;
typedef union unptr unptr_t;
typedef union unval unval_t;



/* <unsys/pyobject.h> */
static inline const char *          py_TP_NAME(PyObject *);
static inline unsigned long         py_TP_FLAGS(PyObject *);
static inline PyObject *            py_TP_DICT(PyObject *);
static inline PyNumberMethods *     py_AS_NUMBER(PyObject *);
static inline PySequenceMethods *   py_AS_SEQUENCE(PyObject *);
static inline PyObject *py_NEW_OBJ(PyTypeObject *);

/* <unsys/pybytes.h> */
static inline const void *pybytes_DATA(PyObject *);
static inline _Bool pybytes_IS_CHAR(PyObject *);
static inline char pybyte_CHAR(PyObject *);
static inline signed char pybyte_SCHAR(PyObject *);
static inline unsigned char pybyte_UCHAR(PyObject *);

/* <unsys/pybytearray.h> */
static inline void *pybytearray_DATA(PyObject *);
static inline char pybytearray_CHAR(PyObject *);
static inline signed char pybytearray_SCHAR(PyObject *);
static inline unsigned char pybytearray_UCHAR(PyObject *);

/* <unsys/pyunicode.h> */
static inline _Bool pyunicode_IS_CHAR(PyObject *);
static inline _Bool pyunicode_IS_CHAR16(PyObject *);
static inline _Bool pyunicode_IS_CHAR32(PyObject *);
static inline unsigned char pyuchar_UCHAR(PyObject *);
static inline signed char pyuchar_SCHAR(PyObject *);
static inline   signed pyuchar_INT(PyObject *);
static inline unsigned pyuchar_UINT(PyObject *);


static PyObject *UnInteger_int_binop(PyObject *, PyObject *, int, int);
static PyObject *UnInteger_uint_binop(PyObject *, PyObject *, int, int);
static PyObject *UnInteger_long_binop(PyObject *, PyObject *, int, int);
static PyObject *UnInteger_ulong_binop(PyObject *, PyObject *, int, int);
static PyObject *UnInteger_llong_binop(PyObject *, PyObject *, int, int);
static PyObject *UnInteger_ullong_binop(PyObject *, PyObject *, int, int);

