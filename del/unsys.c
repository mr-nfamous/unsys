
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */


/*
vars().update(
    SRC="/sdcard/Python/unsys/unsys.c",
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
#include "structmember.h"

#include <stdbool.h>
#include <wchar.h>
#include <uchar.h>

#include "unuchar.h"

#define un_tp_subclass(ob) (Py_TYPE(ob)->tp_flags&0xFF000000UL)
#define UN_IS_LONG(ob)  (Py_TPFLAGS_LONG_SUBCLASS&un_tp_subclass(ob))
#define UN_IS_LIST(ob)  (Py_TPFLAGS_LIST_SUBCLASS&un_tp_subclass(ob))
#define UN_IS_TUPLE(ob) (Py_TPFLAGS_TUPLE_SUBCLASS&un_tp_subclass(ob))
#define UN_IS_BYTES(ob) (Py_TPFLAGS_BYTES_SUBCLASS&un_tp_subclass(ob))
#define UN_IS_STR(ob)   (Py_TPFLAGS_UNICODE_SUBCLASS&un_tp_subclass(ob))
#define UN_IS_DICT(ob)  (Py_TPFLAGS_DICT_SUBCLASS&un_tp_subclass(ob))
#define UN_IS_TYPE(ob)  (Py_TPFLAGS_TYPE_SUBCLASS&un_tp_subclass(ob))


static PyObject *unsys_fsdecode(PyObject *, PyObject *);

typedef union pyref pyref_t;



typedef struct {
    PyObject_HEAD
    union {
        unsigned char   data[sizeof(char)];
        char            cval;
        unsigned char   uval;
        signed   char   sval;
    };
} Char_t;

typedef struct {
    PyObject_HEAD 
    union {
        unsigned char  data[sizeof(short)];
        signed   short sval;
        unsigned short uval;
    };
} Short_t;

typedef struct {
    PyObject_HEAD
    union {
        unsigned char data[sizeof(int)];
        unsigned  int uval;
        signed    int sval;
    };
} Int_t;

typedef struct {
    PyObject_HEAD
    union {
        unsigned char data[sizeof(long)];
        unsigned long uval;
        signed   long sval;
    };
} Long_t;

typedef struct {
    PyObject_HEAD
    union {
        unsigned char data[sizeof(long long)];
        unsigned long long uval;
        signed   long long sval;
    };
} LLong_t;

union pyref {
    void *any, *as_any;
    PyObject        *as_obj;
    PyVarObject     *as_var;
    PyLongObject    *as_long;
    PyListObject    *as_list;
    PyTupleObject   *as_tuple;
    PyBytesObject   *as_bytes;
    PyDictObject    *as_dict;
    PyUnicodeObject *as_unicode;
    PyASCIIObject   *as_ascii;
    PyTypeObject    *as_type;
    Char_t          *as_unchar;
    Short_t         *as_unshort;
    Int_t           *as_unint;
    Long_t          *as_unlong;
    LLong_t         *as_unllong;
};

struct unsys {
    /*
    Of the many different scalar types, "only" the following 
    are actually implemented as a Python type:
    
        C type              C struct      Py module
        name                field         attribute   typecode 
        ————————————————————————————————————————————
        char                py_char       char_t      'c' 
        wint_t              py_wint       wint_t      'C'
        char16_t            py_char16     char16_t    'u'
        char32_t            py_char32     char32_t    'U'
        bool                py_bool       bool_t      'y'
        signed char         py_schar      schar_t     'b'
        unsigned char       py_uchar      uchar_t     'B'
        short               py_short      short_t     'h'
        unsigned short      py_ushort     ushort_t    'H'
        int                 py_int        int_t       'i'
        unsigned int        py_uint       uint_t      'I'
        long                py_long       long_t      'l'
        unsigned long       py_ulong      ulong_t     'L'
        long long           py_llong      llong_t     'q'
        unsigned long long  py_ullong     ullong_t    'Q'
        float               py_flt        flt_t       'f'
        double              py_dbl        dbl_t       'd'
        long double         py_ldbl       ldbl_t      'D'
        size_t              py_size       size_t      'z'
        ptrdiff_t           py_ptrdiff    ptrdiff_t   't'
        void *              py_void       void_p      'x'

    Other builtin types, e.g. intmax_t or uintptr_t, are simply 
    aliases for the lowest ranked type from the previous list 
    with the same attributes. I.e. if INTMAX_MAX == LONG_MAX 
    as well as LLONG_MAX, intmax_t is based on long instead of 
    long long, even if the implementation (for some odd reason) 
    defines intmax_t as a typedef of long long. 
    
    When used in arithmetic expressions, unsys scalars behave
    identically to the corresponding C types. E.g. integer 
    promotions are applied, common type determination is made,
    then the result is computed. Python int, when used as an 
    operand, is considered to have a rank higher than any C int 
    but less than any C float. Python floats and unsys.dbl_t 
    are indistinguishable.
    
    +|y|b|B|h|H|i|I|l|L|q|Q|o|f|d|D
    —|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—
    y i i i i i i I|l L q Q o f d D
    —|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—
    b i i i i i i I|l L q Q o f d D 
    —|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—
    h i i i i i i I|l L q Q o f d D 
    —|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—
    i i i i i i i I|l L q Q o f d D 
    —|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—
    I I I I I I I I|l L q Q o f d D 
    —|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—
    l l l l l l l l|l L q Q o f d D 
    —|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—
    q q q q q q q q|q q q Q o f d D 
    —|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—
    f f f f f f f f|f f f f f f d D 
    
    */
    //              char      char *
    PyTypeObject *py_wint,   *py_wint_p;
    PyTypeObject *py_char,   *py_char_p; 
    PyTypeObject *py_char16, *py_char16_p;
    PyTypeObject *py_char32, *py_char32_p;
    PyTypeObject *py_bool,   *py_bool_p;
    PyTypeObject *py_schar,  *py_schar_p;
    PyTypeObject *py_uchar,  *py_uchar_p;
    PyTypeObject *py_short,  *py_short_p;
    PyTypeObject *py_ushort, *py_ushort_p;
    PyTypeObject *py_int,    *py_int_p;
    PyTypeObject *py_uint,   *py_uint_p;
    PyTypeObject *py_long,   *py_long_p;
    PyTypeObject *py_ulong,  *py_ulong_p;
    PyTypeObject *py_llong,  *py_llong_p;
    PyTypeObject *py_ullong, *py_ullong_p;
    PyTypeObject *py_flt,    *py_flt_p;
    PyTypeObject *py_dbl,    *py_dbl_p;
    PyTypeObject *py_ldbl,   *py_ldbl_p;
    PyTypeObject *py_ptrdiff,*py_ptrdiff_p;
    PyTypeObject *py_size,   *py_size_p;
    PyTypeObject             *py_void_p;
    PyTypeObject *py_timens, *py_timens_p;
    PyTypeObject *py_stat,   *py_stat_p;
    PyTypeObject *py_file,   *py_file_p;
    PyTypeObject *py_dir,    *py_dir_p;
    PyTypeObject *py_dirent, *py_dirent_p;
    PyTypeObject *py_pollfd, *py_pollfd_p;
    
    PyObject    *memorycast;// memoryview.cast ref
    PyObject    *decoders;  // {}
    union {
        PyObject *ints_obj;
        PyTupleObject *ints_tuple;
    };
    PyObject    **ints;
};

struct unsys_local {
    struct {
        char32_t buf[4096];
    } fsdecode;
    struct {
        char    path[4096];
        char    link[4096];
    } fdpath;
};

static struct unsys_local local = {0};


static inline const char *
unsys_FDPATH(int fd) {
    if (snprintf(local.fdpath.link, 4095, "/proc/self/fd/%d", fd) < 0) {
        return NULL;
    }
    ssize_t n = readlink(local.fdpath.link, local.fdpath.path, 4095);
    if (n < 0) {
        return NULL;
    }
    local.fdpath.path[n] = 0;
    return local.fdpath.path;
}

static PyObject *
unsys_fdpath(PyObject *mod, PyObject *obj) {
    PyObject *tmp;
    int fd;
    if (PyLong_CheckExact(obj)) {
        tmp = NULL;
        pylong_obj: switch (Py_SIZE(obj)) {
            case 0: 
            case 1: {
                fd = *((PyLongObject *) obj)->ob_digit;
                break;
            }
            default: {
                goto not_filelike;
            }
        }
        const char *path = unsys_FDPATH(fd);
        Py_XDECREF(tmp);
        if (path == NULL) {
            return PyErr_SetFromErrno(PyExc_OSError);
        }
        return PyBytes_FromString(path);
    }
    _Py_IDENTIFIER(fileno);
    PyObject *fno = _PyObject_LookupSpecial(obj, &PyId_fileno);
    if (fno == NULL) {
        PyErr_Clear();
        tmp = PyNumber_Index(obj);
        if (tmp == NULL) {
            return NULL;
        }
    } 
    else {
        tmp = _PyObject_CallNoArg(fno);
        Py_DECREF(fno);
        if (tmp == NULL) {
            return NULL;
        }
        if (!PyLong_CheckExact(tmp)) {
            goto not_filelike;
        }
    }
    obj = tmp;
    goto pylong_obj;
    not_filelike: {
        Py_XDECREF(tmp);
    }
    return PyErr_Format(
        PyExc_OSError, 
        "fdpath: argument must be os.FileLike, not %s",
        _PyType_Name(Py_TYPE(obj))
    );
    /*
    }
        }
        obj = tmp;
    }
    if ()
        }
            tmp = PyNumber_Index(obj);
    }
    return fno;
    PyObject *tmp = NULL;
    if (PyLong_CheckExact(obj)) {
        pylong_obj: 
        switch (Py_SIZE(obj)) {
            case 1: {
                fd = *((PyLongObject *) obj)->ob_digit;
                break;
            }
            case 0: {
                fd = 0;
                break;
            }
            default: goto not_a_fileno;
        }
    }
    else {
        return fno;
        
        if (fno != NULL) {
            tmp = _PyObject_CallNoArg(fno);
            Py_DECREF(fno);
            if (tmp == NULL) {
                return NULL;
            }
            obj = tmp;
        }
        else {
            PyErr_Clear();
            tmp = NULL;
        }
        if (!UN_IS_LONG(obj)) {
            fno = PyNumber_Index(obj);
            Py_XDECREF(tmp);
            if (PyErr_Occurred()) {
                return NULL;
            }
            tmp = fno;
            obj = fno;
            goto pylong_obj;
        }
    }
    const char *path = unsys_FDPATH(fd);
    Py_XDECREF(tmp);
    if (path == NULL) {
        
    }
    else {
        return PyBytes_FromString(path);
    }
    not_a_fileno: {
        Py_XDECREF(tmp);
    }

    */
}

static PyObject *
unsys_fsdecode(PyObject *mod, PyObject *obj) {
    _Bool ref;
    PyObject *paf;
    switch (un_tp_subclass(obj)) {
        case Py_TPFLAGS_UNICODE_SUBCLASS: {
            return Py_NewRef(obj);
        }
        case Py_TPFLAGS_BYTES_SUBCLASS: {
            ref = false;
            paf = obj;
            break;
        }
        default: {
            _Py_IDENTIFIER(__fspath__);
            PyObject *f = _PyObject_LookupSpecial(obj, &PyId___fspath__);
            if (f == NULL) {
                return PyErr_Format(
                    PyExc_TypeError, 
                    "fsdecode: argument should be str, bytes, or os.PathLi"
                    "ke, not %s",
                    _PyType_Name(Py_TYPE(obj))
                );
            }
            paf = _PyObject_CallNoArg(f);
            Py_DECREF(f);
            if (paf == NULL) {
                return NULL;
            }
            if (UN_IS_BYTES(paf)) {
                ref = true;
                break;
            }
            if (UN_IS_STR(paf)) {
                return paf;
            }
            Py_DECREF(paf);
            return PyErr_Format(
                PyExc_TypeError,
                "fsdecode: __fspath__ didn't return str/bytes"
            );
        }
    }
    const char *src = ((PyBytesObject *) paf)->ob_sval;
    char32_t *dst = local.fsdecode.buf;
    ptrdiff_t pos = 0;
    ptrdiff_t end = PyBytes_GET_SIZE(paf);
    PyObject *str;
    for (; pos < end; dst++) {
        if (src[pos] == 0) {
            *dst=0, pos++;
            continue;
        }
        *dst = UTF_8_DECODE(src, &pos);
        if (*dst == WEOF) {
            PyObject *e = PyUnicodeDecodeError_Create(
                "utf-8",//  const char *encoding,
                src,    //  const char *object,
                end,    //  Py_ssize_t length,
                pos,    //  Py_ssize_t start,
                pos+1,  //  Py_ssize_t end,
                "invalid start byte"
            ); //    const char *reason)
            PyErr_SetObject((PyObject *) Py_TYPE(e), e);
            str = NULL;
            goto the_end;
        }
    }
    str = PyUnicode_FromKindAndData(
        PyUnicode_4BYTE_KIND, 
        local.fsdecode.buf,
        dst-local.fsdecode.buf
    );
    the_end: {
        if (ref) {
            Py_DECREF(paf);
        }
    }
    return str;
}

static PyObject *
sit_on_it(PyObject *mod) {
    PyObject *e = PyUnicodeDecodeError_Create(
        "utf-8",//  const char *encoding,
        "pain",//  const char *object,
        4,      //  Py_ssize_t length,
        0,    //  Py_ssize_t start,
        1,  //  Py_ssize_t end,
        "invalid start byte"
    ); //    const char *reason)
    PyErr_SetObject((PyObject *) Py_TYPE(e), e);
    return NULL;
}

static PyObject *
unsys_isbuffer(PyObject *mod, PyObject *obj) {
    if (PyObject_CheckBuffer(obj)) {
        Py_RETURN_FALSE;
    }
    else {
        Py_RETURN_TRUE;
    }
}

static PyObject *
unsys_digits(PyObject *mod, PyObject *obj) {
    PyObject *res;
    if (!UN_IS_LONG(obj)) {
        return PyErr_Format(PyExc_TypeError, "\"%s\" object not an int");
    }
    PyLongObject *nb = (PyLongObject *) obj;
    int sgn;
    Py_ssize_t len = Py_SIZE(obj);
    if (len < 0) {
        sgn = 0-1;
        len = 0-len;
    }
    else {
        sgn = 0;
    }
    res = PyTuple_New(len+1);
    PyObject **seq = ((PyTupleObject *) res)->ob_item;
    *seq = PyLong_FromLong(sgn);
    if (*seq++ == NULL) {
        error: {
            Py_DECREF(res);
            return NULL;
        }
    }
    for (Py_ssize_t i=0; i < len; i++) {
        *seq = PyLong_FromLong(nb->ob_digit[i]);
        if (*seq++ == NULL) {
            goto error;
        }
    }
    return res;
}

static void
char_dealloc(Char_t *self) {
    Py_TYPE(self)->tp_free(self);
    Py_DECREF(Py_TYPE(self));
}

static PyObject *
char_pylong(Char_t *obj) {
    struct unsys *mod = PyType_GetModuleState(Py_TYPE(obj));
    return Py_NewRef(mod->ints[(int) obj->cval]);
}

static PyObject *
schar_pylong(Char_t *obj) {
    struct unsys *mod = PyType_GetModuleState(Py_TYPE(obj));
    return Py_NewRef(mod->ints[(int) obj->sval]);
}

static PyObject *
uchar_pylong(Char_t *obj) {
    struct unsys *mod = PyType_GetModuleState(Py_TYPE(obj));
    return Py_NewRef(mod->ints[(int) obj->uval]);
}

static PyObject *
schar_repr(const Char_t *obj) {
    return PyUnicode_FromFormat(
        "%s(%d)",
        _PyType_Name(((PyObject *) obj)->ob_type),
        obj->sval 
    );
}

static PyObject *
schar_new(PyTypeObject *cls, PyObject *args, PyObject *kwds) {
    const struct unsys *mod = PyType_GetModuleState(cls);
    pyref_t self;
    signed v;
    _Bool dec;
    if (!_PyArg_NoKeywords(_PyType_Name(cls), kwds)) {
        return NULL;
    }
    if (Py_SIZE(args) == 0) {
        v = 0;
        goto the_obj;
    }
    if (Py_SIZE(args) > 1) {
        return PyErr_Format(
            PyExc_TypeError,
            "%s: expected at most 1 argument; got %zi",
            _PyType_Name(cls),
            Py_SIZE(args)
        );
    }
    pyref_t arg = {.any=*((PyTupleObject *) args)->ob_item};
    if (!PyLong_Check(arg.as_obj)) {
        arg.as_obj = PyNumber_Index(arg.as_obj);
        if (arg.as_obj == NULL) {
            return NULL;
        }
        dec = 1;
    }
    else {
        dec = 0;
    }
    const Py_ssize_t n = arg.as_var->ob_size;
    switch (n) {
        case 0*0: {
            v = 0;
            break;
        }
        case 0+1: {
            v =   *arg.as_long->ob_digit;
            break;
        }
        case 0-1: {
            v = 0-*arg.as_long->ob_digit;
            break;
        }
        default: {
            if (n < 0) {
                v = (0-1)-arg.as_long->ob_digit[0-(n+1)];
            }
            else {
                v = arg.as_long->ob_digit[n-1];
            }
        }
    }
    if (dec) {
        Py_DECREF(arg.as_obj);
    }
    the_obj: {
        self.as_any = PyObject_Malloc(cls->tp_basicsize);
    }
    if (self.as_any == NULL) {
        return NULL;
    }
    self.as_obj->ob_refcnt  = 1;
    self.as_obj->ob_type    = (PyTypeObject *) Py_NewRef((PyObject *) cls);
    self.as_unchar->sval    = (signed char) v;
    return self.as_obj;
}

static int
unsys_traverse(PyObject *mod, visitproc visit, void *arg) {
    struct unsys *self = PyModule_GetState(mod);
    Py_VISIT(self->py_schar);
    Py_VISIT(self->ints_obj);
    return 0;
}

static int
unsys_clear(PyObject *mod) {
    struct unsys *self = PyModule_GetState(mod);
    Py_CLEAR(self->py_schar);
    Py_DECREF(self->ints_obj);
    return 0;
}

static void
unsys_free(void *mod) {
    (void) unsys_clear(mod);
}

static PyType_Spec 
schar_spec = { 
    .name       = "unsys.schar_t", 
    .basicsize  = sizeof(Char_t), 
    .itemsize   = 0, 
    .flags      = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_IMMUTABLETYPE), 
    .slots = (PyType_Slot []){
        {
            Py_tp_doc,     
            "Python representation of a C 'signed char'\n"
        }, 
        {Py_tp_dealloc,     char_dealloc},
        {Py_tp_new,         schar_new}, 
        {Py_tp_getattro,    PyObject_GenericGetAttr}, 
        {Py_tp_repr,        schar_repr}, 
        {0},
    },
};

static int 
unsys_exec(void *mod) {
    int i = 0;
    struct unsys *self = PyModule_GetState(mod);
    if (!(self->ints_obj=PyTuple_New(384))) {
        return 0-1;
    }
    PyObject **ints = self->ints_tuple->ob_item;
    self->ints = ints+128;
    for (long v=-128; i < 384; v++) {
        if (!(ints[i++]=PyLong_FromLong(v))) {
            Py_DECREF(self->ints_obj);
            return 0-1;
        }
    }
    self->py_schar = (PyTypeObject *)
        PyType_FromModuleAndSpec(mod, &schar_spec, 0);
    if (PyModule_AddType(mod, self->py_schar) < 0) { 
        return 0-1;
    }
    return 0;
}

static 
struct PyModuleDef unsys_moduledef = { 
    PyModuleDef_HEAD_INIT, 
    .m_name = "unsys", 
    .m_size = sizeof(struct unsys),
    .m_doc  = (
        "[Un]iversal [sys]tem call interface\n"
        "\n"
        "Functions:\n"
        "   * isbuffer()\n"
        "Classes:\n"
        "   * CData\n"
        "   * CPointer\n"
        "   * CStruct\n"
        "   * CFunction\n"
    ),
    .m_methods = (PyMethodDef[]){
        {
            .ml_name    = "isbuffer",
            .ml_meth    = (PyCFunction) unsys_isbuffer,
            .ml_flags   = METH_O,
            .ml_doc     = (
            "isbuffer(x: object, /) -> bool\n"
            "\n"
            "Check if an object implements the buffer protocol"
            ),
        },
        {
            .ml_name = "sitonit",
            .ml_meth = (PyCFunction) sit_on_it,
            .ml_flags = METH_NOARGS,
            .ml_doc = "fruit",
        },
        {
            .ml_name = "fdpath",
            .ml_meth = (PyCFunction) unsys_fdpath,
            .ml_flags = METH_O,
            .ml_doc = 
            "fdpath(x: os.FileLike) -> str\n\n"
            "Obtain the path used to open the os.FileLike object x.",
        },
        {
            .ml_name    = "fsdecode",
            .ml_meth    = (PyCFunction) unsys_fsdecode,
            .ml_flags   = METH_O,
            .ml_doc     = 
            "fsdecode(x: os.PathLike) -> str\n"
            "\n"
            "Obtain the path representation of an object and then if "
            "necessary, decode it as x.decode('utf-8', 'surrogatepass')"
        },
        {
            .ml_name    = "digits",
            .ml_meth    = (PyCFunction) unsys_digits,
            .ml_flags   = METH_O,
            .ml_doc     = "digits(x: int, /) -> tuple[int]\n",
        },
        {0},
    },
    .m_slots    = (PyModuleDef_Slot []){
        {Py_mod_exec, unsys_exec},
        {0},
    },
    //.m_traverse = unsys_traverse,
    .m_clear    = unsys_clear, 
    .m_free     = unsys_free,
};

PyMODINIT_FUNC 
PyInit_unsys(void) {
    return PyModuleDef_Init(&unsys_moduledef);
}
