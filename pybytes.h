
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#pragma once

static inline PyObject *
pybytes_ERR_NOT_BYTE(void) {
    PyErr_SetString(PyExc_TypeError, "len(string) != 1");
    return NULL;
}

static inline _Bool
pybytes_IS_BYTE(PyObject *obj) {
    return Py_SIZE(obj) == 1;
}

static inline _Bool
pybytes_IS_EMPTY(PyObject *obj) {
    return !Py_SIZE(obj);
}

static inline const void *
pybytes_DATA(PyObject *obj) {
    return ((PyBytesObject *) obj)->ob_sval;
}

static inline const unsigned char *
pybytes_BYTES(PyObject *obj) {
    return pybytes_DATA(obj);
}

static inline char
pybyte_CHAR(PyObject *obj) {
    return *((PyBytesObject *) obj)->ob_sval;
}

static inline wchar_t
pybyte_WCHAR(PyObject *obj) {
    return (wchar_t) *pybytes_BYTES(obj);
}

static inline char16_t
pybyte_CHAR16(PyObject *obj) {
    return (char16_t) *pybytes_BYTES(obj);
}

static inline char32_t
pybyte_CHAR32(PyObject *obj) {
    return (char32_t) *pybytes_BYTES(obj);
}

static inline signed char
pybyte_SCHAR(PyObject *obj) {
    return (signed char) *pybytes_BYTES(obj);
}

static inline short
pybyte_SHRT(PyObject *obj) {
    return *pybytes_BYTES(obj);
}

static inline signed int
pybyte_INT(PyObject *obj) {
    return *pybytes_BYTES(obj);
}

static inline signed long
pybyte_LONG(PyObject *obj) {
    return *pybytes_BYTES(obj);
}

static inline signed long long
pybyte_LLONG(PyObject *obj) {
    return *pybytes_BYTES(obj);
}

static inline _Bool
pybyte_BOOL(PyObject *obj) {
    return *pybytes_BYTES(obj);
}

static inline unsigned char
pybyte_UCHAR(PyObject *obj) {
    return *pybytes_BYTES(obj);
}

static inline unsigned short
pybyte_USHRT(PyObject *obj) {
    return *pybytes_BYTES(obj);
}

static inline unsigned int
pybyte_UINT(PyObject *obj) {
    return *pybytes_BYTES(obj);
}

static inline unsigned long
pybyte_ULONG(PyObject *obj) {
    return *pybytes_BYTES(obj);
}

static inline unsigned long long
pybyte_ULLONG(PyObject *obj) {
    return *pybytes_BYTES(obj);
}

static inline float
pybyte_FLT(PyObject *obj) {
    return *pybytes_BYTES(obj);
}

static inline double
pybyte_DBL(PyObject *obj) {
    return *pybytes_BYTES(obj);
}

static inline long double
pybyte_LDBL(PyObject *obj) {
    return *pybytes_BYTES(obj);
}

static inline PyObject *
pybyte_NB_BOOL(PyObject *obj) {
    if (!pybyte_BOOL(obj)) {
        Py_RETURN_FALSE;
    }
    Py_RETURN_TRUE;
}

static inline PyObject *
pybyte_NB_INDEX(PyObject *obj) {
    const int i = pybyte_INT(obj);
    return Py_NewRef(unsys.ints[i]);
}

static inline PyObject *
pybyte_NB_FLOAT(PyObject *obj) {
    return PyFloat_FromDouble(pybyte_DBL(obj));
}
