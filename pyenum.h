
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#pragma once
typedef struct {
    PyObject        base;
    PyObject *      pyname;
    PyObject *      pyint;
    PyObject *      pyflt;
    PyObject *      pycmp;
    const char *    cname;
    unsys_t *       ctype;
    union {
        long double fval;
        intmax_t    sval;
        uintmax_t   uval;
    };
} UnEnum;

static PyObject *
UnEnum_repr(UnEnum *obj) {
    if (obj->pyname == NULL) {
        obj->pyname = PyUnicode_FromString(obj->cname);
    }
    Py_XINCREF(obj->pyname);
    return obj->pyname;
}

static PyObject *
UnEnum_float(UnEnum *obj) {
    if (obj->pyflt != NULL) {
        return Py_NewRef(obj->pyflt);
    }
    switch (obj->ctype->t_as) {
        case AS_INTMAX: {
            obj->pyint = pylong_FROM_INTMAX(obj->sval);
            obj->pyflt = PyFloat_FromDouble(obj->sval);
            obj->pycmp = Py_NewRef(obj->pyint);
            break;
        }
        case AS_UINTMAX: {
            obj->pyint = pylong_FROM_UINTMAX(obj->uval);
            obj->pyflt = PyFloat_FromDouble(obj->uval);
            obj->pycmp = Py_NewRef(obj->pyint);
            break;
        }
        case AS_LDBL: {
            obj->pyflt = PyFloat_FromDouble((double) obj->fval);
            obj->pycmp = Py_NewRef(obj->pyflt);
            break;
        }
        default: {
            Py_UNREACHABLE();
        }
    }
    Py_XINCREF(obj->pyflt);
    return obj->pyflt;
}

static PyObject *
UnIntEnum_index(UnEnum *obj) {
    if (obj->pyint != NULL) {
        return Py_NewRef(obj->pyint);
    }
    PyObject *tmp = UnEnum_float(obj);
    if (tmp != NULL) {
        Py_DECREF(tmp);
        return Py_NewRef(obj->pyint);
    }
    return NULL;
}

static Py_hash_t
UnEnum_hash(UnEnum *obj) {
    return (Py_hash_t) obj->sval;
}

static PyObject *
UnEnum_richcompare(UnEnum *lhs, PyObject *rhs, int op) {
    if (lhs == (UnEnum *) rhs) {
        switch (op) {
            case Py_LE:
            case Py_GE:
            case Py_EQ: {
                Py_RETURN_TRUE;
            }
            case Py_LT:
            case Py_GT:
            case Py_NE: {
                Py_RETURN_FALSE;
            }
            default: Py_UNREACHABLE();
        }
    }
    if (lhs->pycmp == NULL) {
        PyObject *tmp = UnEnum_float(lhs);
        if (tmp == NULL) {
            return NULL;
        }
        Py_DECREF(tmp);
        if (lhs->pycmp == NULL) {
            return NULL;
        }
    }
    return PyObject_RichCompare(lhs->pycmp, rhs, op);
}

static PyTypeObject 
UnEnum_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name        = "unsys.Enum",
    .tp_basicsize   = sizeof(UnEnum),
    .tp_flags       = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
    .tp_hash        = (hashfunc) UnEnum_hash,
    .tp_repr        = (reprfunc) UnEnum_repr,
    .tp_richcompare = (void *) UnEnum_richcompare,
    .tp_as_number   = &(PyNumberMethods){
        .nb_float   = (unaryfunc) UnEnum_float,
    },
};

static PyTypeObject
UnIntEnum_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name        = "unsys.IntEnum",
    .tp_base        = &UnEnum_Type,
    .tp_basicsize   = sizeof(UnEnum),
    .tp_as_number   = &(PyNumberMethods){
        .nb_index   = (unaryfunc) UnIntEnum_index,
    },
};

struct UnEnum_def {
#define UnEnum_sdef(nam) {.name=#nam, .type=AS_INTMAX, .sval=nam}
    const char *name;
    int type;
    union {
        intmax_t sval;
        uintmax_t uval;
        long double fval;
    };
};
static struct UnEnum_def
unsys_rank_enums[] = {
    [NB_RANK_0] = UnEnum_sdef(NB_RANK_0),
    [NB_RANK_1] = UnEnum_sdef(NB_RANK_1),
    [NB_RANK_2] = UnEnum_sdef(NB_RANK_2),
    [NB_RANK_3] = UnEnum_sdef(NB_RANK_3),
    [NB_RANK_4] = UnEnum_sdef(NB_RANK_4),
    [NB_RANK_5] = UnEnum_sdef(NB_RANK_5),
    [NB_RANK_6] = UnEnum_sdef(NB_RANK_6),
    [NB_RANK_7] = UnEnum_sdef(NB_RANK_7),
    [NB_RANK_8] = UnEnum_sdef(NB_RANK_8),
    [NB_RANK_9] = UnEnum_sdef(NB_RANK_9),
    [NB_RANK_A] = UnEnum_sdef(NB_RANK_A),
    [NB_RANK_B] = UnEnum_sdef(NB_RANK_B),
    [NB_RANK_C] = UnEnum_sdef(NB_RANK_C),
    [NB_RANK_D] = UnEnum_sdef(NB_RANK_D),
    [NB_RANK_E] = UnEnum_sdef(NB_RANK_E),
};
static struct {
    struct UnEnum_def nb_signed;
    struct UnEnum_def nb_unsigned;
    struct UnEnum_def nb_signless;
} unsys_signedness_enums = {
    .nb_signed      = UnEnum_sdef(NB_SIGNED),
    .nb_unsigned    = UnEnum_sdef(NB_UNSIGNED),
    .nb_signless    = UnEnum_sdef(NB_SIGNLESS),
};

static struct UnEnum_def 
unsys_as_enums[] = {
    [AS_VOID]       = UnEnum_sdef(AS_VOID),
    [AS_ADDR]       = UnEnum_sdef(AS_ADDR),
    [AS_ADDRPTR]    = UnEnum_sdef(AS_ADDRPTR),

    [AS_HALF]       = UnEnum_sdef(AS_HALF),
    [AS_FLT]        = UnEnum_sdef(AS_FLT),
    [AS_DBL]        = UnEnum_sdef(AS_DBL),
    [AS_LDBL]       = UnEnum_sdef(AS_LDBL),
    [AS_BIGFLT]     = UnEnum_sdef(AS_BIGFLT),

    [AS_CHAR]       = UnEnum_sdef(AS_CHAR),
    [AS_WCHAR]      = UnEnum_sdef(AS_WCHAR),
    [AS_CHAR16]     = UnEnum_sdef(AS_CHAR16),
    [AS_CHAR32]     = UnEnum_sdef(AS_CHAR32),

    [AS_BOOL]       = UnEnum_sdef(AS_BOOL),

    [AS_SCHAR]      = UnEnum_sdef(AS_SCHAR),
    [AS_SHRT]       = UnEnum_sdef(AS_SHRT),
    [AS_INT]        = UnEnum_sdef(AS_INT),
    [AS_LONG]       = UnEnum_sdef(AS_LONG),
    [AS_LLONG]      = UnEnum_sdef(AS_LLONG),
    [AS_XLONG]      = UnEnum_sdef(AS_XLONG),
    [AS_SSIZE]      = UnEnum_sdef(AS_SSIZE),
    [AS_INTPTR]     = UnEnum_sdef(AS_INTPTR),
    [AS_PTRDIFF]    = UnEnum_sdef(AS_PTRDIFF),
    [AS_INT8]       = UnEnum_sdef(AS_INT8),
    [AS_INT16]      = UnEnum_sdef(AS_INT16),
    [AS_INT32]      = UnEnum_sdef(AS_INT32),
    [AS_INT64]      = UnEnum_sdef(AS_INT64),
    [AS_INTMAX]     = UnEnum_sdef(AS_INTMAX),

    [AS_UCHAR]      = UnEnum_sdef(AS_UCHAR),
    [AS_USHRT]      = UnEnum_sdef(AS_USHRT),
    [AS_UINT]       = UnEnum_sdef(AS_UINT),
    [AS_ULONG]      = UnEnum_sdef(AS_ULONG),
    [AS_ULLONG]     = UnEnum_sdef(AS_ULLONG),
    [AS_UXLONG]     = UnEnum_sdef(AS_UXLONG),
    [AS_SIZE]       = UnEnum_sdef(AS_SIZE),
    [AS_UINTPTR]    = UnEnum_sdef(AS_UINTPTR),
    [AS_UINT8]      = UnEnum_sdef(AS_UINT8),
    [AS_UINT16]     = UnEnum_sdef(AS_UINT16),
    [AS_UINT32]     = UnEnum_sdef(AS_UINT32),
    [AS_UINT64]     = UnEnum_sdef(AS_UINT64),
    [AS_UINTMAX]    = UnEnum_sdef(AS_UINTMAX),
    
    [AS_WINT]       = UnEnum_sdef(AS_WINT),
    [AS_BIGINT]     = UnEnum_sdef(AS_BIGINT),
};

static PyObject *
unsys_DEF_ENUM(PyObject **cache, struct UnEnum_def *e) {
    UnEnum *v;
    switch (e->type) {
        case AS_INTMAX: {
            v = (UnEnum *) _PyObject_New(&UnIntEnum_Type);
            v->sval = e->sval;
            break;
        }
        case AS_UINTMAX: {
            v = (UnEnum *) _PyObject_New(&UnIntEnum_Type);
            v->uval = e->uval;
            break;
        }
        case AS_FLT:
        case AS_DBL: e->type = AS_LDBL;
        case AS_LDBL: {
            v = (UnEnum *) _PyObject_New(&UnEnum_Type);
            v->fval = e->fval;
            break;
        }
        default: Py_UNREACHABLE();
    }
    v->cname = e->name;
    v->ctype = unsys_ctypes+e->type;
    if (cache != NULL) {
        cache[0] = Py_NewRef((PyObject *) v);
    }
    return (PyObject *) v;
}

static bool
unsys_ADD_ENUM(PyObject *mod, PyObject **cache, struct UnEnum_def *edef) {
    if (cache != NULL) {
        cache += edef->sval;
    }
    PyObject *v = unsys_DEF_ENUM(cache, edef);
    if (PyModule_AddObject(mod, edef->name, v) < 0) {
        return 1;
    }
    return 0;
}
