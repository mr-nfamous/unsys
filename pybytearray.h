
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#pragma once

static inline void *
pybytearray_DATA(PyObject *obj) {
    return ((PyByteArrayObject *) obj)->ob_start;
}

static inline char
pybytearray_CHAR(PyObject *obj) {
    return *((char *) pybytearray_DATA(obj));
}

static inline signed char
pybytearray_SCHAR(PyObject *obj) {
    return *((signed char *) pybytearray_DATA(obj));
}

static inline unsigned char
pybytearray_UCHAR(PyObject *obj) {
    return *((unsigned char *) pybytearray_DATA(obj));
}
