
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#pragma once

static inline PyObject *
pyunicode_ERR_NOT_CHAR(void) {
    PyErr_SetString(PyExc_TypeError, "len(string) != 1");
    return NULL;
}

static inline unptr_t
pyunicode_DATA(PyObject *obj) {
    return (unptr_t){ PyUnicode_DATA(obj) };
}

static inline _Bool
pyunicode_IS_CHAR(PyObject *obj) {
    if (PyUnicode_GET_LENGTH(obj) != 1) {
        return 0;
    }
    return PyUnicode_KIND(obj) == PyUnicode_1BYTE_KIND;
}

static inline _Bool
pyunicode_IS_CHAR16(PyObject *obj) {
    if (PyUnicode_GET_LENGTH(obj) != 1) {
        return 0;
    }
    return PyUnicode_KIND(obj) == PyUnicode_2BYTE_KIND;
}

static inline _Bool
pyunicode_IS_CHAR32(PyObject *obj) {
    if (PyUnicode_GET_LENGTH(obj) != 1) {
        return 0;
    }
    return PyUnicode_KIND(obj) == PyUnicode_4BYTE_KIND;
}

static inline unsigned char 
pyuchar_UCHAR(PyObject *obj) {
    return *pyunicode_DATA(obj).UCHAR_VAR;
}

static inline signed char 
pyuchar_SCHAR(PyObject *obj) {
    return *pyunicode_DATA(obj).SCHAR_VAR;
}

static inline char16_t
pyuchar_CHAR16(PyObject *obj) {
    return *pyunicode_DATA(obj).CHAR16_VAR;
}

static inline char32_t
pyuchar_CHAR32(PyObject *obj) {
    return *pyunicode_DATA(obj).CHAR32_VAR;
}

static inline int
pyuchar_INT(PyObject *obj) {
    switch (PyUnicode_KIND(obj)) {
       case PyUnicode_1BYTE_KIND: return (int) pyuchar_UCHAR(obj);
       case PyUnicode_2BYTE_KIND: return (int) pyuchar_CHAR16(obj);
       case PyUnicode_4BYTE_KIND: return (int) pyuchar_CHAR32(obj);
    }
    return 0-1;
}

static inline unsigned 
pyuchar_UINT(PyObject *obj) {
    switch (PyUnicode_KIND(obj)) {
       case PyUnicode_1BYTE_KIND: return pyuchar_UCHAR(obj);
       case PyUnicode_2BYTE_KIND: return pyuchar_CHAR16(obj);
       case PyUnicode_4BYTE_KIND: return pyuchar_CHAR32(obj);
    }
    return 0U-1U;
}

static inline double
pyuchar_DBL(PyObject *obj) {
    return pyuchar_INT(obj);
}

