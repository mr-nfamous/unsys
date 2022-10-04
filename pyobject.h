/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#pragma once

static inline const char *
py_TP_NAME(PyObject *obj) {
    return Py_TYPE(obj)->tp_name;
}

static inline PyObject *
py_TP_DICT(PyObject *obj) {
    return Py_TYPE(obj)->tp_dict;
}

static inline unsigned long
py_TP_FLAGS(PyObject *obj) {
    return (unsigned long) Py_TYPE(obj)->tp_flags;
}

static inline PyNumberMethods *
py_AS_NUMBER(PyObject *obj) {
    return Py_TYPE(obj)->tp_as_number;
}

static inline PySequenceMethods *
py_AS_SEQUENCE(PyObject *obj) {
    return Py_TYPE(obj)->tp_as_sequence;
}

static inline PyObject *
py_NEW_OBJ(PyTypeObject *cls) {
    Py_INCREF(cls);
    PyObject *obj = PyMem_Malloc((size_t) cls->tp_basicsize);
    if (obj == NULL) {
        Py_DECREF(cls);
        return PyErr_NoMemory();
    }
    Py_SET_TYPE(obj, cls);
    Py_SET_REFCNT(obj, 1);
    return obj;
}

static PyObject *
py_lt(PyObject *a, PyObject *b) {
    return PyObject_RichCompare(a, b, Py_LT);
}

static PyObject *
py_le(PyObject *a, PyObject *b) {
    return PyObject_RichCompare(a, b, Py_LE);
}

static PyObject *
py_eq(PyObject *a, PyObject *b) {
    return PyObject_RichCompare(a, b, Py_EQ);
}

static PyObject *
py_ne(PyObject *a, PyObject *b) {
    return PyObject_RichCompare(a, b, Py_NE);
}

static PyObject *
py_gt(PyObject *a, PyObject *b) {
    return PyObject_RichCompare(a, b, Py_GT);
}

static PyObject *
py_ge(PyObject *a, PyObject *b) {
    return PyObject_RichCompare(a, b, Py_GT);
}

static PyObject *
py_pow(PyObject *a, PyObject *b) {
    return PyNumber_Power(a, b, Py_None);
}

static PyObject *
py_ipow(PyObject *a, PyObject *b) {
    return PyNumber_InPlacePower(a, b, Py_None);
}

static PyObject *(*py_binops[])(PyObject *, PyObject *) = {
    [BI_IGNORE] = 0,
    [BI_ADD]    = PyNumber_Add,
    [BI_SUB]    = PyNumber_Subtract,
    [BI_MUL]    = PyNumber_Multiply,
    [BI_POW]    = py_pow,
    [BI_DIV]    = PyNumber_TrueDivide,
    [BI_FDIV]   = PyNumber_FloorDivide,
    [BI_MOD]    = PyNumber_Remainder,
    [BI_MAT]    = PyNumber_MatrixMultiply,
    [BI_AND]    = PyNumber_And,
    [BI_OR]     = PyNumber_Or,
    [BI_XOR]    = PyNumber_Xor,
    [BI_LSH]    = PyNumber_Lshift,
    [BI_RSH]    = PyNumber_Rshift,
    [BI_SND]    = 0,
    [BI_RCV]    = 0,
    [BI_IADD]   = PyNumber_InPlaceAdd,
    [BI_ISUB]   = PyNumber_InPlaceSubtract,
    [BI_IMUL]   = PyNumber_InPlaceMultiply,
    [BI_IPOW]   = py_ipow,
    [BI_IDIV]   = PyNumber_InPlaceTrueDivide,
    [BI_IFDIV]  = PyNumber_InPlaceFloorDivide,
    [BI_IMOD]   = PyNumber_InPlaceRemainder,
    [BI_IMAT]   = PyNumber_InPlaceMatrixMultiply,
    [BI_IAND]   = PyNumber_InPlaceAnd,
    [BI_IOR]    = PyNumber_InPlaceOr,
    [BI_IXOR]   = PyNumber_InPlaceXor,
    [BI_ILSH]   = PyNumber_InPlaceLshift,
    [BI_IRSH]   = PyNumber_InPlaceRshift,
    [BI_IRCV]   = 0,
    [BI_ISND]   = 0,
    [BI_LT]     = py_lt,
    [BI_LE]     = py_le,
    [BI_EQ]     = py_eq,
    [BI_AE]     = 0,
    [BI_NE]     = py_ne,
    [BI_GT]     = py_gt,
    [BI_GE]     = py_ge,
};
