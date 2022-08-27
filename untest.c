
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

/*
vars().update(
    SRC="/sdcard/Python/unsys/untest.c",
    PYLIB="lpython3.10",
    DST="../usr/lib/python3.10/site-packages/unsys.cpython-310.so",
    INCLUDES="-I ../usr/include/python3.10 -I /sdcard/Python/unsys"
    )
"clang "
"-shared "
"-lpython3.10 "
"-I ../usr/include/python3.10 "
"-I /sdcard/Python/unsys "

os.system(f"clang {SRC} -o {DST} -shared -{PYLIB} {INCLUDES}")

*/

#define PY_SSIZE_T_CLEAN


#include "Python.h"
#include <assert.h>
#include <inttypes.h>

#include "structmember.h"


struct unsys {
    PyObject *ints_tuple;
    PyObject **ints;
    PyObject 
        *char_min,      *char_max, 
        *wchar_min,     *wchar_max,
        *schar_min,     *schar_max,     *uchar_max,
        *shrt_min,      *shrt_max,      *ushrt_max,
        *int_min,       *int_max,       *uint_max,
        *long_min,      *long_max,      *ulong_max,
        *llong_min,     *llong_max,     *ullong_max,
        *intmax_min,    *intmax_max,    *uintmax_max,
        *intptr_min,    *intptr_max,    *uintptr_max,
        *ptrdiff_min,   *ptrdiff_max,   *size_max,
        *int8_min,      *int8_max,      *uint8_max,
        *int16_min,     *int16_max,     *uint16_max,
        *int32_min,     *int32_max,     *uint32_max,
        *int64_min,     *int64_max,     *uint64_max;
};

static inline struct unsys * 
unsys_state(PyObject *mod) { 
    void *self = PyModule_GetState(mod); 
    assert(self != NULL); 
    return (struct unsys *) self;
}



#include "pylong.h"

static int
unsys_exec(void *mod) {
    struct unsys *_ = unsys_state(mod);
    _->ints_tuple = PyTuple_New(128+257);
    if (_->ints_tuple == NULL) {
        return 0-1;
    }
    PyObject **ints = ((PyTupleObject *) _->ints_tuple)->ob_item;
    _->ints = ints+128;
    for (long i=0L, v=0-128; i < Py_SIZE(_->ints_tuple); i++, v++) {
        ints[i] = PyLong_FromLong(v);
        if (ints[i] == NULL) {
            Py_DECREF(_->ints_tuple);
            return 0-1;
        }
    }
#   define UNSYS_SSYM(a, v) ((_->a=PyLong_FromLongLong(v)) == NULL)
#   define UNSYS_USYM(a, v) ((_->a=PyLong_FromUnsignedLongLong(v)) == NULL)
    if (
            UNSYS_USYM(   char_min,    CHAR_MIN)
        ||  UNSYS_USYM(   char_max,    CHAR_MAX)
        ||  UNSYS_SSYM(  schar_min,   SCHAR_MIN)
        ||  UNSYS_SSYM(  schar_max,   SCHAR_MAX)
        ||  UNSYS_USYM(  uchar_max,   UCHAR_MAX)
        ||  UNSYS_SSYM(   shrt_min,    SHRT_MIN)
        ||  UNSYS_SSYM(   shrt_max,    SHRT_MAX)
        ||  UNSYS_USYM(  ushrt_max,   USHRT_MAX)
        ||  UNSYS_SSYM(    int_min,     INT_MIN)
        ||  UNSYS_SSYM(    int_max,     INT_MAX)
        ||  UNSYS_USYM(   uint_max,    UINT_MAX)
        ||  UNSYS_SSYM(   long_min,    LONG_MIN)
        ||  UNSYS_SSYM(   long_max,    LONG_MAX)
        ||  UNSYS_SSYM(  llong_min,   LLONG_MIN)
        ||  UNSYS_SSYM(  llong_max,   LLONG_MAX)
        ||  UNSYS_SSYM(ptrdiff_min, PTRDIFF_MIN)
        ||  UNSYS_SSYM(ptrdiff_max, PTRDIFF_MAX)
        ||  UNSYS_USYM(   size_max,    SIZE_MAX)
        ||  UNSYS_SSYM( intmax_min,  INTMAX_MIN)
        ||  UNSYS_SSYM( intmax_max,  INTMAX_MAX)
        ||  UNSYS_USYM(uintmax_max, UINTMAX_MAX)
        ||  UNSYS_SSYM( intptr_min,  INTPTR_MIN)
        ||  UNSYS_SSYM( intptr_max,  INTPTR_MAX)
        ||  UNSYS_USYM(uintptr_max, UINTPTR_MAX)
        ||  UNSYS_SSYM(   int8_min,    INT8_MIN)
        ||  UNSYS_SSYM(   int8_max,    INT8_MAX)
        ||  UNSYS_USYM(  uint8_max,   UINT8_MAX)
        ||  UNSYS_SSYM(  int16_min,   INT16_MIN)
        ||  UNSYS_SSYM(  int16_max,   INT16_MAX)
        ||  UNSYS_USYM( uint16_max,  UINT16_MAX)
        ||  UNSYS_SSYM(  int32_min,   INT32_MIN)
        ||  UNSYS_SSYM(  int32_max,   INT32_MAX)
        ||  UNSYS_USYM( uint32_max,  UINT32_MAX)
        ||  UNSYS_SSYM(  int64_min,   INT64_MIN)
        ||  UNSYS_SSYM(  int64_max,   INT64_MAX)
        ||  UNSYS_USYM( uint64_max,  UINT64_MAX)
    )
    {
        return 0-1;
    }
    /*


        ||  (UNSYS_INIT_SSYM( INTMAX_MIN) == NULL)
        ||  (UNSYS_INIT_SSYM( INTMAX_MAX) == NULL)
        ||  (UNSYS_INIT_USYM(UINTMAX_MAX) == NULL)
        ||  (UNSYS_INIT_SSYM( INTPTR_MIN) == NULL)
        ||  (UNSYS_INIT_SSYM( INTPTR_MAX) == NULL)
        ||  (UNSYS_INIT_USYM(UINTPTR_MAX) == NULL)
        ||  (UNSYS_INIT_SSYM(   INT8_MIN) == NULL)
        ||  (UNSYS_INIT_SSYM(   INT8_MAX) == NULL)
        ||  (UNSYS_INIT_USYM(  UINT8_MAX) == NULL)
        ||  (UNSYS_INIT_SSYM(  INT16_MIN) == NULL)
        ||  (UNSYS_INIT_SSYM(  INT16_MAX) == NULL)
        ||  (UNSYS_INIT_USYM( UINT16_MAX) == NULL)
        ||  (UNSYS_INIT_SSYM(  INT32_MIN) == NULL)
        ||  (UNSYS_INIT_SSYM(  INT32_MAX) == NULL)
        ||  (UNSYS_INIT_USYM( UINT32_MAX) == NULL)
        ||  (UNSYS_INIT_SSYM(  INT64_MIN) == NULL)
        ||  (UNSYS_INIT_SSYM(  INT64_MAX) == NULL)
        ||  (UNSYS_INIT_USYM( UINT64_MAX) == NULL)
        ||  (UNSYS_INIT_SSYM(PTRDIFF_MIN) == NULL)
        ||  (UNSYS_INIT_SSYM(PTRDIFF_MAX) == NULL)
        ||  (UNSYS_INIT_USYM(   SIZE_MAX) == NULL)) {
        return 0-1;
    }
    */
    return 0;
}

static int
unsys_clear(PyObject *mod) {
    struct unsys *self = unsys_state(mod);
    Py_CLEAR(self->ints_tuple);
    return 0;
}

static int
unsys_traverse(PyObject *mod, visitproc visit, void *arg) {
    struct unsys *self = unsys_state(mod);
    Py_VISIT(self->ints_tuple);
    return 0;
}

static void
unsys_free(void *mod) {
    unsys_clear((PyObject *) mod);
}

static char
pylong_char(PyObject *obj) {
    return pylong_CHAR(obj);
}

static signed char
pylong_schar(PyObject *obj) {
    return pylong_SCHAR(obj);
}

static unsigned char
pylong_uchar(PyObject *obj) {
    return pylong_UCHAR(obj);
}

static short
pylong_short(PyObject *obj) {
    return pylong_SHORT(obj);
}

static unsigned short
pylong_ushort(PyObject *obj) {
    return pylong_USHORT(obj);
}

static int
pylong_int(PyObject *obj) {
    return pylong_INT(obj);
}

static unsigned
pylong_uint(PyObject *obj) {
    return pylong_UINT(obj);
}

static long
pylong_long(PyObject *obj) {
    return pylong_LONG(obj);
}

static unsigned long
pylong_ulong(PyObject *obj) {
    return pylong_ULONG(obj);
}

static long long
pylong_llong(PyObject *obj) {
    return pylong_LLONG(obj);
}

static unsigned long long
pylong_ullong(PyObject *obj) {
    return pylong_ULLONG(obj);
}

static PyObject *
unsys_schar(PyObject *mod, PyObject *obj) {
    if (!PyLong_Check(obj)) {
        return PyErr_Format(PyExc_TypeError, "expected an int");
    }
    signed char n = pylong_schar(obj);
    return Py_NewRef(unsys_state(mod)->ints[(ptrdiff_t) n]);
}

static PyObject *
unsys_uchar(PyObject *mod, PyObject *obj) {
    if (!PyLong_Check(obj)) {
        return PyErr_Format(PyExc_TypeError, "expected an int");
    }
    unsigned char n = pylong_schar(obj);
    return Py_NewRef(unsys_state(mod)->ints[(ptrdiff_t) n]);
}

static PyObject *
unsys_ushort(PyObject *mod, PyObject *obj) {
    if (!PyLong_Check(obj)) {
        return PyErr_Format(PyExc_TypeError, "expected int");
    }
    unsigned short n = pylong_ushort(obj);
    if (n < 257) {
        return Py_NewRef(unsys_state(mod)->ints[(ptrdiff_t) n]);
    }
    PyLongObject *res = _PyLong_New(1);
    *res->ob_digit = n;
    return (PyObject *) res;
}

static PyObject *
unsys_int(PyObject *mod, PyObject *obj) {
    if (!PyLong_Check(obj)) {
        return PyErr_Format(PyExc_TypeError, "expected int");
    }
    int n = pylong_int(obj);
    if (n < 257) {
        if (n >= (0-128)) {
            return Py_NewRef(unsys_state(mod)->ints[n]);
        }
        PyObject *tmp = pylong_FROM_UINT(mod, (unsigned) 0-n);
        if (tmp == NULL) {
            return NULL;
        }
        ((PyVarObject *) tmp)->ob_size = 0-Py_SIZE(tmp);
        return tmp;
    }
    return pylong_FROM_UINT(mod, (unsigned) n);
}


static PyObject *
unsys_uint(PyObject *mod, PyObject *obj) {
    if (!PyLong_Check(obj)) {
        return PyErr_Format(PyExc_TypeError, "expected int");
    }
    return pylong_FROM_UINT(mod, pylong_uint(obj));
}

static struct PyModuleDef 
unsys_moduledef = { 
    PyModuleDef_HEAD_INIT, 
    .m_name = "unsys", 
    .m_size = sizeof(struct unsys),
    .m_doc  = "smfd",
    .m_methods = (PyMethodDef[]){
        {
            .ml_name    = "schar",
            .ml_meth    = (PyCFunction) unsys_schar,
            .ml_flags   = METH_O,
            .ml_doc     = "schar(i)",
        },
        {
            .ml_name    = "ushort",
            .ml_meth    = (PyCFunction) unsys_ushort,
            .ml_flags   = METH_O,
            .ml_doc     = "ushort(i)",
        },
        {
            .ml_name    = "uint",
            .ml_meth    = (PyCFunction) unsys_uint,
            .ml_flags   = METH_O,
            .ml_doc     = "uint(i)",
        },
        {
            .ml_name    = "int",
            .ml_meth    = (PyCFunction) unsys_int,
            .ml_flags   = METH_O,
            .ml_doc     = "int(i)",
        },
        {0},
    },
    .m_slots = (PyModuleDef_Slot []){
        {Py_mod_exec, unsys_exec},
        {0},
    },
    .m_traverse = unsys_traverse,
    .m_clear    = unsys_clear, 
    .m_free     = unsys_free,
};

PyMODINIT_FUNC 
PyInit_unsys(void) {
    return PyModuleDef_Init(&unsys_moduledef);
}
