/*  |*************************************************************************
"clang "
"/sdcard/Python/unsys/unsys.c "
"-shared "
"-lpython3.10 "
"-D UNSYS_BIG_ENDIAN=0 "
"-I ../usr/include/python3.10 "
"-I /sdcard/Python/unsys "
"-o ../usr/lib/python3.10/site-packages/unsys.cpython-310.so"

*/

#define PY_SSIZE_T_CLEAN
#include "Python.h"
#include "structmember.h"
#include "dtypedef.h"

#define fastsubclass(obj) ((obj)->ob_type->tp_flags&0xFF000000UL)
#define seterror(exc, msg) PyErr_SetString(PyExc_##exc, msg)
  
#define TypeError(msg) seterror(TypeError, msg)
#define IndexError(msg) seterror(IndexError, msg)
#define SystemError(msg) seterror(SystemError, msg)
#define ValueError(msg) seterror(ValueError, msg)

typedef union charview {
    uint8_t     b[1];
    uint8_t     u;
    int8_t      s;
} CharView;

typedef union shortview {
    uint8_t     b[2];
    uint16_t    h[1];
    uint16_t    u;
    int16_t     s;
    CharView    cv[2];
} ShortView;

typedef union intview {
    uint8_t     b[4];
    uint16_t    h[2];
    uint32_t    i[1];
    uint32_t    u;
    int32_t     s;
    CharView    cv[4];
    ShortView   hv[2];
} IntView;

typedef union longview {
    uint8_t     b [8];
    CharView    cv[8];
    uint16_t    h [4];
    ShortView   hv[4];
    uint32_t    i [2];
    IntView     iv[2];
    uint64_t    q [1];
    uint64_t    u;
    int64_t     s;
    uintmax_t   x;
} LongView;

typedef union floatview {
    uint8_t     b[4];
    float       f;
    uint32_t    u;
    int32_t     s;
} FloatView;

typedef union doubleview {
    uint8_t     b[8];
    float       d;
    uint64_t    u;
    int64_t     s;
} DoubleView;

typedef union pyalias {
    void            *as_any;
    uintptr_t       addr;
    PyObject        *as_object;
    PyObject       **as_objects;
    PyLongObject    *as_long;
    PyVarObject     *as_varobject;
    PyTupleObject   *as_tuple;
    PyListObject    *as_list;
    PyBytesObject   *as_bytes;
} pyalias_t;

typedef PyObject *Py;

typedef PyObject *(*pydecoder)(const ptrview_t, const pyindex_t);

typedef struct {
    ssize_t         ob_refcnt;
    PyTypeObject   *ob_type;
    Py              dt_name;
    dtype_t         dt_type;
} DtypeObject;

typedef uint64_t hash_t;

static  
uint8_t NBIT[256] = {0, 1, 2, 2};

hash_t
string_hash(const void *ptr, size_t *restrict len) {
    const uint8_t *restrict str = ptr;
    size_t i = 0;
    union {
        uint64_t v;
        struct {
            uint16_t a;
            uint32_t b;
        };
    } hash = {.a=1, .b=0};
    for (; str[i]; i++) {
        hash.a += str[i];
        hash.b += hash.a;
    }
    if (len)
        len[0] = i;
    if (hash.v) {
        hash.v ^= hash.v>>12;
        hash.v ^= hash.v<<25;
        hash.v ^= hash.v>>27;
    }
    return hash.v>>33;
}

static void
init_nbit(void) {
    memset(NBIT+0x04, 3, 0x04);
    memset(NBIT+0x08, 4, 0x08);
    memset(NBIT+0x10, 5, 0x10);
    memset(NBIT+0x20, 6, 0x20);
    memset(NBIT+0x40, 7, 0x40);
    memset(NBIT+0x80, 8, 0x80);
}

static inline uint8_t
hashbits(hash_t i) {
    if (i <  0x00000004) return 003;
    if (i <= 0x000000FF) return 001+NBIT[i];
    if (i <= 0x0000FFFF) return 011+NBIT[i>>010];
    if (i <= 0x00FFFFFF) return 021+NBIT[i>>020];
    else                 return 031+NBIT[i>>030];
}

static inline int
pytoumax(pyalias_t arg, uintmax_t *restrict val) {
    *val = PyLong_AsUnsignedLongLongMask(arg.as_object);
    return PyErr_Occurred() ? -1 : 0;
}

static Py 
unsys_identity(Py module, Py arg) { 
    Py_INCREF(arg);
    return arg;
}

static Py
char_decode(const ptrview_t buf, const pyindex_t i) {
    return Py_BuildValue("c", (int)(buf.u8[i.u]));
}

static Py
wchar_decode(const ptrview_t buf, const pyindex_t i) {
    return Py_BuildValue("C", (int)(buf.u32[i.u]));
}

static Py
uchar_decode(const ptrview_t buf, const pyindex_t i) {
    return PyLong_FromUnsignedLong((unsigned long)buf.u8[i.u]);
}


static Py
ushort_decode(const ptrview_t buf, const pyindex_t i) {
    if (buf.uint%sizeof(short) == 0)
        return PyLong_FromUnsignedLong(buf.u16[i.u]);
    const uint8_t *restrict b =  buf.u8+i.u*sizeof(short);
    const ShortView r = {{b[0], b[1]}};
    return PyLong_FromUnsignedLong(r.u);
}


static Py
uint_decode(const ptrview_t buf, const pyindex_t i) {
    if (buf.uint%sizeof(unsigned) == 0)
        return PyLong_FromUnsignedLong(buf.u32[i.u]);
    const uint8_t *restrict b =  buf.u8+i.u*sizeof(unsigned);
    const IntView r = {{b[0], b[1], b[2], b[3]}};
    return PyLong_FromUnsignedLong(r.u);
}


static Py
int_decode(const ptrview_t buf, const pyindex_t i) {
    if (buf.uint%sizeof(int) == 0)
        return PyLong_FromLong(buf.s32[i.u]);
    const uint8_t *restrict b =  buf.u8+i.u*sizeof(int);
    const IntView r = {{b[0], b[1], b[2], b[3]}};
    return PyLong_FromLong(r.s);
}

#if ULLONG_MAX > ULONG_MAX

static Py 
    (*long_decode) (const ptrview_t, const pyindex_t) = int_decode,
    (*ulong_decode)(const ptrview_t, const pyindex_t) = uint_decode;
#define long_decode int_decode
#define ulong_decode uint_decode

static Py
llong_decode(const ptrview_t buf, const pyindex_t i) {
    if (buf.uint%sizeof(long long) == 0)
        return PyLong_FromLongLong(buf.s64[i.u]);
    const uint8_t *restrict b =  buf.u8+i.u*sizeof(long long);
    const LongView r = {{b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7]}};
    return PyLong_FromLongLong(r.s);
}

static Py
ullong_decode(const ptrview_t buf, const pyindex_t i) {
    if (buf.uint%sizeof(long long) == 0)
        return PyLong_FromUnsignedLongLong(buf.u64[i.u]);
    const uint8_t *restrict b =  buf.u8+i.u*sizeof(long long);
    const LongView r = {{b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7]}};
    return PyLong_FromUnsignedLongLong(r.u);
}

#else

static Py
long_decode(const ptrview_t buf, const pyindex_t i) {
    Py_RETURN_NONE;
}

static Py
ulong_decode(const ptrview_t buf, const pyindex_t i) {
    if (buf.uint%sizeof(long) == 0)
        return PyLong_FromUnsignedLong(buf.u64[i.u]);
    const uint8_t *restrict b =  buf.u8+i.u*sizeof(long);
    const LongView r = {{b[0], b[1], b[2], b[3], b[4], b[5], b[6], b[7]}};
    return PyLong_FromUnsignedLong(r.u);
}

static Py 
    (*llong_decode) (const ptrview_t, const pyindex_t) = long_decode,
    (*ullong_decode)(const ptrview_t, const pyindex_t) = ulong_decode;
#define llong_decode long_decode
#define ullong_decode ulong_decode
#endif

static Py
schar_decode(const ptrview_t buf, const pyindex_t i) {
    return PyLong_FromLong(buf.s8[i.u]);
}

static Py
short_decode(const ptrview_t buf, const pyindex_t i) {
    if (buf.uint%sizeof(short) == 0) 
        return PyLong_FromLong((long)(buf.s16[i.u]));
    const uint8_t *restrict b =  buf.u8+i.u*sizeof(short);
    const ShortView r = {{b[0], b[1]}};
    return PyLong_FromLong(r.s);
}

static Py
bool_decode(const ptrview_t buf, const pyindex_t i) {
    if (buf.bint[i.u])
        Py_RETURN_TRUE;
    else 
        Py_RETURN_FALSE;
}

static Py
float_decode(const ptrview_t buf, const pyindex_t i) {
    if (buf.uint%sizeof(float) == 0)
        return PyFloat_FromDouble((double)(buf.flt[i.u]));
    const uint8_t *restrict f = buf.u8+sizeof(float)*i.u;
    const FloatView v = {{f[0], f[1], f[2], f[3]}};
    return PyFloat_FromDouble((double) v.f);
}

static Py
double_decode(const ptrview_t buf, const pyindex_t i) {
    if (buf.uint%sizeof(double) == 0)
        return PyFloat_FromDouble(buf.dbl[i.u]);
    const uint8_t *restrict f = buf.u8+sizeof(double)*i.u;
    const DoubleView v = {{f[0], f[1], f[2], f[3]}};
    return PyFloat_FromDouble(v.d);
}

static Py
unsys_testbit(Py mod, Py unused) {
    union bx {
        struct {
            unsigned char 
            bit0: 1,
            bit1: 1,
            bit2: 1,
            bit3: 1,
            bit4: 1,
            bit5: 1,
            bit6: 1,
            b7: 1;
        } bf;
        unsigned char b;
        struct {
            unsigned char 
            :   1,
            b1: 1;
        };
    };
    union bx a = {.bf = {.b7=1}};
    union bx b = {.b = 0xff};
    union bx c = {.b1 = 1};
    return Py_BuildValue(
        "[[i,i],[i,i],[i,i]]",
        (int)(a.b),     (int)(a.bf.b7), 
        (int)(b.b),     (int)(b.b1),
        (int)(c.b),     (int)(c.b1)
        // [[128, 1], [255, 1], [2, 1]]
        
   );
    
}

static pydecoder UNSYS_DECODERS[256] = {
    [UNSYS_CHAR]    = char_decode,
    [UNSYS_WCHAR]   = wchar_decode,
    [UNSYS_FLOAT]   = float_decode,
    [UNSYS_DOUBLE]  = double_decode,   
    [UNSYS_BOOL]    = bool_decode,
    [UNSYS_UCHAR]   = uchar_decode,
    [UNSYS_USHORT]  = ushort_decode,
    [UNSYS_UINT]    = uint_decode,
    [UNSYS_ULONG]   = ulong_decode,
    [UNSYS_ULLONG]  = ullong_decode,
    [UNSYS_SCHAR]   = schar_decode,
    [UNSYS_SHORT]   = short_decode,
    [UNSYS_INT]     = int_decode,
    [UNSYS_LONG]    = long_decode,
    [UNSYS_LLONG]   = llong_decode,
};

static const uint8_t 
UNSYS_BASICSIZE[256] = {
    [UNSYS_VOID]    = 1,
    [UNSYS_ADDR]    = (uint8_t) sizeof(size_t),
    [UNSYS_BOOL]    = (uint8_t) sizeof(_Bool),
    [UNSYS_CHAR]    = (uint8_t) sizeof(char),
    [UNSYS_WCHAR]   = (uint8_t) sizeof(wchar_t),
    [UNSYS_FLOAT]   = (uint8_t) sizeof(float),
    [UNSYS_DOUBLE]  = (uint8_t) sizeof(double), 
    [UNSYS_UCHAR]   = (uint8_t) sizeof(unsigned char),
    [UNSYS_USHORT]  = (uint8_t) sizeof(unsigned short int),
    [UNSYS_UINT]    = (uint8_t) sizeof(unsigned int),
    [UNSYS_ULONG]   = (uint8_t) sizeof(unsigned long int),
    [UNSYS_ULLONG]  = (uint8_t) sizeof(unsigned long long int),
    [UNSYS_SCHAR]   = (uint8_t) sizeof(signed char),
    [UNSYS_SHORT]   = (uint8_t) sizeof(signed short int),
    [UNSYS_INT]     = (uint8_t) sizeof(signed int),
    [UNSYS_LONG]    = (uint8_t) sizeof(signed long int),
    [UNSYS_LLONG]   = (uint8_t) sizeof(signed long long int),
};

static const uint8_t
UNSYS_BITMASK_MAX[256] = {
    [UNSYS_BOOL]    = 8,
    [UNSYS_SCHAR]   = 8,
    [UNSYS_UCHAR]   = 8,
    [UNSYS_SHORT]   = 16,
    [UNSYS_USHORT]  = 16,
    [UNSYS_INT]     = 32,
    [UNSYS_UINT]    = 32,
};

static wint_t
pywcs_to_wint_t(Py src) {
    if (PyUnicode_GET_LENGTH(src) != 1) {
        TypeError("expected a single unicode character");
        return -1;
    }
    switch (PyUnicode_KIND(src)) {
        case PyUnicode_1BYTE_KIND:
            return (wint_t) PyUnicode_1BYTE_DATA(src)[0];
        case PyUnicode_2BYTE_KIND:
            return (wint_t) PyUnicode_2BYTE_DATA(src)[0];
        case PyUnicode_4BYTE_KIND:
            return (wint_t) PyUnicode_4BYTE_DATA(src)[0];
    }
    if (!PyErr_Occurred()) 
        SystemError("invalid 'kind' field of PyUnicodeObject");
    return -1;
}

static wint_t
pychar_to_wint_t(Py src) {
    if (PyBytes_GET_SIZE(src) != 1) {
        TypeError("expected a single character bytes object");
        return -1;
    }
    return (wint_t) PyBytes_AS_STRING(src)[0];
}

static Py 
unsys_decode(Py mod, Py args) {
    /*
    (buf, 'T')
    (buf, 'T', pos)
    (buf, 'T', pos, dt_length)
    (buf, 'T', pos, dt_bitshift, dt_bitmask) 
    */
    Py*seq;
    Py res = NULL;
    Py_buffer buf;
    pydecoder get;
    pyalias_t arg = {args};
    pyalias_t fmt;
    pyindex_t off;
    pyindex_t end;
    unsigned type;

    if (!PyTuple_Check(args)) {
        TypeError("a tuple is required");
        return NULL;
    }

    if (arg.as_varobject->ob_size < 2) {
        TypeError("a tuple of at least 2 objects is required");
        return NULL;
    }

    seq = arg.as_tuple->ob_item;
    fmt.as_object = seq[0];

    if (PyObject_GetBuffer(seq[1], &buf, PyBUF_SIMPLE) == -1)
        return NULL;

    if (arg.as_varobject->ob_size == 2) {
        off.s = 0;
        goto the_beginning;
    }
    

    if (PyErr_Occurred())
        goto the_end;

    if (off.s < 0) {
        off.s += buf.len;
        if (off.s < 0)
            goto out_of_bounds;
    }
    else {
the_beginning:
        if (buf.len <= off.s)
            goto out_of_bounds;
    }

    if ((get=UNSYS_DECODERS[type&0xff]))
        res = get((ptrview_t){buf.buf}, off);
    else 
        ValueError("unknown fmt code");
    goto the_end;
    
out_of_bounds:
    IndexError("memory offset out of bounds");
the_end:
    PyBuffer_Release(&buf);
    return res;
}

static inline void *
jalloc(PyTypeObject *tp) {
    pyalias_t obj = {PyObject_Malloc(tp->tp_basicsize)};
    if (!obj.as_object)
        return PyErr_NoMemory();
    obj.as_object->ob_refcnt   = 1;
    obj.as_object->ob_type     = tp;
    return obj.as_any;
}

static Py
Dtype_new(PyTypeObject *tp, Py args, Py kwds) {

    /*
    (name, spec)
    (name, spec, offset)
    (name, spec, offset, arraylen)
    (name, spec, offset, bitshift, bitmask)
    */
    DtypeObject    *self;
    Py              name;
    dtype_t         type = {0};
    pyalias_t       arg  = {args};
    PyObject      **seq  = arg.as_tuple->ob_item;
    size_t          narg = (size_t) arg.as_varobject->ob_size;

    if ((narg < 2) || (narg > 5)) {
        TypeError("__new__ requires 3-5 positional only arguments");
        return NULL;
    }

    if ((name=*seq++) != Py_None) {
        if (!PyUnicode_CheckExact(name)) {
            TypeError("the name of the type must be a str or None");
            return NULL;
        }
    }
    Py_INCREF(name);
    
    switch (fastsubclass(seq[0])) {
        case 0:
        case Py_TPFLAGS_LONG_SUBCLASS:
            type._ustate = (uint32_t) PyLong_AsUnsignedLongMask(*seq++);
            if (PyErr_Occurred())
                return NULL;
            break;
        case Py_TPFLAGS_UNICODE_SUBCLASS:
            type._sstate = pywcs_to_wint_t(*seq++);
            break;
        case Py_TPFLAGS_BYTES_SUBCLASS:
            type._sstate = pychar_to_wint_t(*seq++);
            break;
        default:
            TypeError("invalid layout: must be int or (w)char");
            return NULL;
    }

    if (type._ustate > 0xffff) {
        TypeError("invalid typecode for primitive data type");
        goto fail;
    }

    if (!UNSYS_DECODERS[type.dt_layout]) {
        TypeError("invalid typecode");
        goto fail;
    }

    if (narg > 2) {
        type.dt_offset.s = PyLong_AsSsize_t(*seq);
        if (PyErr_Occurred())
            goto fail;
        if (type.dt_offset.s < 0) {
            ValueError("offset must be >= 0");
            return NULL;
        }
        else if (narg == 4) {
            type.dt_length.s = PyLong_AsSsize_t(*(++seq));
            if (PyErr_Occurred())
                goto fail;
            type.dt_ndim = 1;
        }
        else if (narg == 5) {
            size_t bitmax = UNSYS_BITMASK_MAX[type.dt_layout];
            if (!bitmax) 
                TypeError("unsuitable bit field layout");
            size_t sht = PyLong_AsSize_t(*(++seq));
            uint8_t bit;
            if (PyErr_Occurred())
                goto fail;
            if (bitmax <= sht) {
                bitmax -= sht;
                type.dt_bitmask = (uint32_t) PyLong_AsSize_t(*seq);
                if (PyErr_Occurred())
                    goto fail;
                if (type.dt_bitmask > 0xFFFFFFFF) 
                    bit = 33;
                else if (type.dt_bitmask > 0x0000FFFF) {
                    if  (type.dt_bitmask > 0x00FFFFFF)
                        bit = 030+NBIT[type.dt_bitmask>>030];
                    else 
                        bit = 020+NBIT[type.dt_bitmask>>020];
                }
                else {
                    if  (type.dt_bitmask > 0x000000FF)
                        bit = 010+NBIT[type.dt_bitmask>>010];
                    else 
                        bit =     NBIT[type.dt_bitmask];
                }
            }
            else 
                bit = 65,
                sht = 0;
            if (bit > sht) {
                TypeError("bitfield spilled out of its allocation unit");
                goto fail;
                }
            type.dt_bitshift = (uint8_t) sht;
        }
    }

    self = jalloc(tp);
    if (!self)
        goto fail;
    self->dt_name = name;
    self->dt_type = type;
    return (Py)self;
    fail:
    Py_DECREF(name);
    return NULL;

}

static void
Dtype_dealloc(Py self) {
    Py_XDECREF(((DtypeObject*)self)->dt_name);
    PyObject_Del(self);
}

static PyTypeObject 
DtypeType = {
    .tp_name                = "Dtype",
    .tp_basicsize           = sizeof(DtypeObject),
    .tp_itemsize            = 0,
    .tp_dealloc             = (&Dtype_dealloc),  
    .tp_getattr             = (getattrfunc)(0),            
    .tp_setattr             = (setattrfunc)(0), 
    .tp_as_async            = (PyAsyncMethods *)(0),
    .tp_repr                = (reprfunc)(0),
    .tp_as_number           = (PyNumberMethods *)(0),
    .tp_as_sequence         = (PySequenceMethods *)(0),
    .tp_as_mapping          = (PyMappingMethods *)(0),
    .tp_hash                = (hashfunc)(0),
    .tp_call                = (ternaryfunc)(0),
    .tp_str                 = (reprfunc)(0),
    .tp_getattro            = (getattrofunc)(0),
    .tp_setattro            = (setattrofunc)(0),
    .tp_as_buffer           = (PyBufferProcs *)(0),
    .tp_flags               = Py_TPFLAGS_DEFAULT,
    .tp_doc                 = (const char *)(0),
    .tp_traverse            = (traverseproc)(0),
    .tp_clear               = (inquiry)(0),
    .tp_richcompare         = (richcmpfunc)(0),
    .tp_weaklistoffset      = 0,
    .tp_iter                = (getiterfunc)(0),
    .tp_iternext            = (iternextfunc)(0),
  /*.tp_methods             = (struct PyMethodDef []){{0}},
*//*.tp_members             = (struct PyMemberDef []){
        [0] = {
            .name   = (const char *)(0),
            .type   = (int)(0),
            .offset = (ssize_t)(0),
            .flags  = (int)(0),
            .doc    = (const char *)(0),
        },
    }, 
*//*.tp_getset              = (struct PyGetSetDef []){{0}},
*/  .tp_base                = (PyTypeObject *)(0),
    .tp_dict                = (PyObject *)(0),
    .tp_descr_get           = (descrgetfunc)(0),
    .tp_descr_set           = (descrsetfunc)(0),
    .tp_dictoffset          = 0,
    .tp_init                = (initproc)(0),
    .tp_alloc               = (allocfunc)(0),
    .tp_new                 = (newfunc)(Dtype_new),
    .tp_free                = (freefunc)(0),
    .tp_is_gc               = (inquiry)(0),
};

static struct PyModuleDef 
unsys_module = {
    .m_base     = PyModuleDef_HEAD_INIT, 
    .m_name     = "martin", 
    .m_doc      = "mar", 
    .m_size     = -1,
    .m_methods  = (struct PyMethodDef []) {
        {"identity", &unsys_identity, METH_O, (
            "The identity function: f(x) -> x\n")
        },
        {"testbit", &unsys_testbit, METH_NOARGS, ""},
        {
            "decode", &unsys_decode, METH_O,
            "decode((fmt, buffer, *[offset, *[bitmask]]))\n"
            "\n"
            "Get an instance of a C data type as a Python object.\n"
            "Requires a tuple of 1-4 items:\n"
            "\n"
            "   *   An int or a single character str or bytes object\n"
            "       that is to be converted to an int as if used as\n"
            "       the argument of ord(x)\n"
            "\n"
            "       The following lists the mapping of typecodes to\n"
            "       the corresponding C data type:\n"
            "\n"
            "       *  '?' -> (_Bool)"               "\n"
            "       *  'B' -> (unsigned char)"       "\n"
            "       *  'H' -> (unsigned short)"      "\n"
            "       *  'I' -> (unsigned int)"        "\n"
            "       *  'L' -> (unsigned long)"       "\n"
            "       *  'Q' -> (unsigned long long)"  "\n"
            "       *  'b' -> (signed char)"         "\n"
            "       *  'h' -> (signed short)"        "\n"
            "       *  'i' -> (signed int)"          "\n"
            "       *  'l' -> (signed long)"         "\n"
            "       *  'q' -> (signed long long)"    "\n"
            "       *  'f' -> (float)"               "\n"
            "       *  'd' -> (double)"              "\n"
            "       Note: the type codes are actually 32 bits, with\n"
            "       the least significant byte reserved for the base\n"
            "       type. The upper 24 bits are irrelevant for this\n"
            "       particular function, which is why 'characters'\n"
            "       are accepted.\n"  
            "\n"
            "   *   The buffer in which the object is located.\n"
            "\n"
            "   *   An offset in the buffer of the most significant\n"
            "       byte of the value. Negative offsets are handled\n"
            "       as they are with any other sequence\n"
            "\n"
            "   *   A 2 tuple describing a bit field\n"
        },
        {0},
    },
};

PyMODINIT_FUNC 
PyInit_unsys(void) { 
    Py m;
    if (PyType_Ready(&DtypeType) < 0)
        return NULL;
    if (!(m=PyModule_Create(&unsys_module)))
        return NULL;
    PyModule_AddObject(m, "Dtype", (Py)&DtypeType);
    PyModule_AddIntMacro(m, UNSYS_SSIZE);
    PyModule_AddIntMacro(m, UNSYS_SIZE);
    PyModule_AddIntMacro(m, UNSYS_OFF);
    PyModule_AddIntMacro(m, UNSYS_PTRDIF);
    PyModule_AddIntMacro(m, UNSYS_CHAR);
    PyModule_AddIntMacro(m, UNSYS_UCHAR);
    PyModule_AddIntMacro(m, UNSYS_USHORT);
    PyModule_AddIntMacro(m, UNSYS_UINT);
    PyModule_AddIntMacro(m, UNSYS_ULONG);
    PyModule_AddIntMacro(m, UNSYS_ULLONG);
    PyModule_AddIntMacro(m, UNSYS_UINT8);
    PyModule_AddIntMacro(m, UNSYS_UINT16);
    PyModule_AddIntMacro(m, UNSYS_UINT32);
    PyModule_AddIntMacro(m, UNSYS_UINT64);
    PyModule_AddIntMacro(m, UNSYS_UINT64);
    PyModule_AddIntMacro(m, UNSYS_UINTMAX);
    PyModule_AddIntMacro(m, UNSYS_SCHAR);
    PyModule_AddIntMacro(m, UNSYS_VOID);
    PyModule_AddIntMacro(m, UNSYS_ADDR);
    
    PyModule_AddIntMacro(m, UNSYS_SHORT);
    PyModule_AddIntMacro(m, UNSYS_INT);
    PyModule_AddIntMacro(m, UNSYS_LONG);
    PyModule_AddIntMacro(m, UNSYS_LLONG);
    PyModule_AddIntMacro(m, UNSYS_INT8);
    PyModule_AddIntMacro(m, UNSYS_INT16);
    PyModule_AddIntMacro(m, UNSYS_INT32);
    PyModule_AddIntMacro(m, UNSYS_INT64);
    PyModule_AddIntMacro(m, UNSYS_INT64);
    PyModule_AddIntMacro(m, UNSYS_INTMAX);
    
    return m;
}
