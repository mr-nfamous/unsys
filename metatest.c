
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

/*
vars().update(
    SRC=f"/sdcard/Python/unsys/{NAME}.c",
    PYLIB="lpython3.10",
    DST="../usr/lib/python3.10/site-packages/unsys.cpython-310.so",
    INCLUDES="-I ../usr/include/python3.10 -I /sdcard/Python/unsys"
    )
os.system(f"clang {SRC} -o {DST} -shared -{PYLIB} {INCLUDES}")

*/

#include "pyunsys.h"

static int unsys_initialized = 0;

static struct unsys unsys;


static inline struct unsys * 
unsys_state(PyObject *mod) { 
    void *self = PyModule_GetState(mod); 
    assert(self != NULL); 
    return (struct unsys *) self;
}

/*
static PyObject *
unsys_convs(PyObject *mod) {
    TypeAttrDict *d0 = (TypeAttrDict *) UnSchar_Type.tp_dict;
    TypeAttrDict *d1 = (TypeAttrDict *) UnInt_Type.tp_dict;
    printf("UnSchar_Type.tp_dict->conv = %p\n", d0->conv);
    printf("UnInt_Type.tp_dict->conv = %p\n", d1->conv);
}
*/

/*

static PyObject *
unsys_typedef(PyObject *mod, PyObject *args) {
    struct unsys_arg_chk arg = {
        "typedef",
        UNSYS_PARSE_ARGS("typedef", 2, 3),
    };
    if (arg.seq == NULL) {
        return NULL;
    }
    PyObject *name = unsys_ARG_CHK_FAST(&arg, 0, Py_TPFLAGS_UNICODE_SUBCLASS);
    if (name == NULL) {
        return  NULL;
    }
    PyObject *tobj = unsys_ARG_CHK_FAST(&arg, 1, Py_TPFLAGS_LONG_SUBCLASS);
    if (tobj  == NULL) {
        return   NULL;
    }
    TypeAttrDict *d = (TypeAttrDict *) PyObject_CallNoArgs(
        (PyObject *) &TypeAttrDict
    );
    if (d == NULL) {
        return NULL;
    }

    //unsigned full_type = pylong_AS_UINT(tobj);
    //unsigned short type = full_type&0xFFFFU;
    
    return 0;
}
    */

static PyObject *
UnIntegerMeta_new(PyTypeObject *meta, PyObject *args, PyObject *kwds) {
    /*
    PyObject *dict = unsys_ARG_CHK_FAST(&arg, 2, Py_TPFLAGS_DICT_SUBCLASS);
    if (dict == NULL) {
        return  NULL;
    }
    
    PyObject *base = PyDict_GetItemString(dict, "__base__")
    }
    if (!PyUnicode_Check(name)) {
        return PyErr_Format(
            "args[%d] must be str (got %s)",
            _PyType_Name(Py_TYPE(seq[0]))
        );
    }
    PyTypeObject *cls;
    //PyObject *tmp = PyObject_Call((PyObject *) &PyType_Type, args, kwds);
    if (PyErr_Occurred()) {
        return NULL;
    }
    */
    return Py_NewRef((PyObject *) &PyType_Type);
}

static PyObject *
unsys_identity(PyObject *mod, PyObject *obj) {
    return Py_NewRef(obj);
}

static int 
unsys_clear(PyObject *mod) {
    return 0;
}

static void
unsys_free(void *mod) {
    (void) unsys_clear(mod);
}

static int
unsys_traverse(PyObject *mod, visitproc visit, void *arg) {
    return 0;
}
/*
    ScalarMeta.__instancecheck__(ScalarType)
    ScalarType.__instancecheck__(c_bool())
*/

static PyObject *
unsys_ctype_instancecheck(PyTypeObject *a, PyObject *b) {
    PyTypeObject *c = Py_TYPE(b);
    return Py_NewRef(
        (c < &UnC_Meta)          ? Py_False :
        (c > &UnFunction_Meta)   ? Py_False :
        Py_True
    );
}

static PyObject *
unsys_one(PyObject *mod) {
    return Py_NewRef(unsys.ints[1]);
}

static inline void
unsys_ADD_V(PyObject **dst, unsigned long long val) {
    *dst = PyLong_FromUnsignedLongLong(val);
}

static inline void
unsys_ADD_v(PyObject **dst,   signed long long val) {
    *dst = PyLong_FromLongLong(val);
}

static inline void
unsys_ADD_d(PyObject **dst,  double val) {
    *dst = PyFloat_FromDouble(val);
}

static inline void
unsys_INIT_PY_LIMITS(void) {
    struct unsys_limits *c = unsys.limits.c;
    unsys_ADD_v(&unsys.limits.py->char_min, c->char_min);
    unsys_ADD_v(&unsys.limits.py->char_max, c->char_max);
    unsys_ADD_v(&unsys.limits.py->wchar_min, c->wchar_min);
    unsys_ADD_v(&unsys.limits.py->wchar_max, c->wchar_max);
    unsys_ADD_v(&unsys.limits.py->wint_min, c->wint_min);
    unsys_ADD_v(&unsys.limits.py->wint_max, c->wint_max);
    unsys_ADD_v(&unsys.limits.py->bool_min, c->bool_min);
    unsys_ADD_v(&unsys.limits.py->bool_max, c->bool_max);
    unsys_ADD_V(&unsys.limits.py->char16_max, c->uint16_max);
    unsys_ADD_V(&unsys.limits.py->char32_max, c->uint32_max);
    unsys_ADD_v(&unsys.limits.py->schar_max, c->schar_max);
    unsys_ADD_v(&unsys.limits.py->shrt_max,   c->shrt_max);
    unsys_ADD_v(&unsys.limits.py->shrt_min,   c->shrt_min);
    unsys_ADD_V(&unsys.limits.py->ushrt_max, c->ushrt_max);
    unsys_ADD_v(&unsys.limits.py->int_max,   c->int_max);
    unsys_ADD_v(&unsys.limits.py->int_min,   c->int_min);
    unsys_ADD_V(&unsys.limits.py->uint_max, c->uint_max);
    unsys_ADD_v(&unsys.limits.py->long_max,   c->long_max);
    unsys_ADD_v(&unsys.limits.py->long_min, c->llong_min);
    unsys_ADD_V(&unsys.limits.py->ulong_max, c->ulong_max);
    unsys_ADD_v(&unsys.limits.py->llong_max,   c->llong_max);
    unsys_ADD_v(&unsys.limits.py->llong_min,   c->llong_min);
    unsys_ADD_V(&unsys.limits.py->ullong_max, c->ullong_max);
    unsys_ADD_v(&unsys.limits.py->int8_max, c->int8_max);
    unsys_ADD_v(&unsys.limits.py->int8_min, c->int8_min);
    unsys_ADD_V(&unsys.limits.py->uint8_max, c->uint8_max);
    unsys_ADD_v(&unsys.limits.py->int16_max, c->int16_max);
    unsys_ADD_v(&unsys.limits.py->int16_min, c->int16_min);
    unsys_ADD_V(&unsys.limits.py->uint16_max, c->uint16_max);
    unsys_ADD_v(&unsys.limits.py->int32_max, c->int32_max);
    unsys_ADD_v(&unsys.limits.py->int32_min, c->int32_min);
    unsys_ADD_V(&unsys.limits.py->uint32_max,c->uint32_max);
    unsys_ADD_v(&unsys.limits.py->int64_max, c->int64_max);
    unsys_ADD_v(&unsys.limits.py->int64_min, c->int64_min);
    unsys_ADD_V(&unsys.limits.py->uint64_max, c->uint64_max);
    unsys_ADD_v( &unsys.limits.py->intmax_max, c->intmax_max);
    unsys_ADD_v( &unsys.limits.py->intmax_min, c->intmax_min);
    unsys_ADD_V(&unsys.limits.py->uintmax_max, c->uintmax_max);
    unsys_ADD_v( &unsys.limits.py->intptr_max, c->intptr_max);
    unsys_ADD_v( &unsys.limits.py->intptr_min, c->intptr_min);
    unsys_ADD_V(&unsys.limits.py->uintptr_max, c->uintptr_max);
    unsys_ADD_v(&unsys.limits.py->ptrdiff_min, c->ptrdiff_min);
    unsys_ADD_V(&unsys.limits.py->ptrdiff_max, c->ptrdiff_max);
    unsys_ADD_v(  &unsys.limits.py->ssize_max,  c->ssize_max);
    unsys_ADD_V(   &unsys.limits.py->size_max,   c->size_max);
}

static inline bool
unsys_INIT_TINY_INTS(void) {
    unsys.ints_tuple = PyTuple_New(128+257);
    if (unsys.ints_tuple == NULL) {
        return 1;
    }
    PyObject **ints = ((PyTupleObject *) unsys.ints_tuple)->ob_item;
    unsys.ints = ints+128;
    for (long i=0L, v=0-128; i < Py_SIZE(unsys.ints_tuple); i++, v++) {
        ints[i] = PyLong_FromLong(v);
        if (ints[i] == NULL) {
            Py_DECREF(unsys.ints_tuple);
            return 1;
        }
    }
    return 0;
}

static PyObject *
unsys_qualname(PyObject *mod) {
    //unsys_t *c, unsigned cvf, size_t length) {
    struct {
        unsys_t 
            *c_char_t,  // typedef                __he8 c_char_t
            *c_char_c,  // typedef          const __he8 c_char_c
            *c_char_v,  // typedef volatile       __he8 c_char_v
            *c_char_n,  // typedef                __be8 c_char_n
            *c_char_vc, // typedef volatile const __he8 c_char_vc
            *c_char_nvc,// typedef volatile const __be8 c_char_vcn
            *c_char_p,  // typedef c_char_t  *          c_char_p
            *c_char_cp,
            *c_char_vp,
            *c_char_vcp,
            *c_char_c_p,// typedef c_char_c  *          c_char_c_p
            *c_char_v_p,// typedef c_char_v  c_char_v_p [1]
            *c_char_vc_p,//typedef c_char_vc c_char_vc_p[1]
            *c_char_rp, // typedef c_char_t  c_char_rp  [restrict 1]
            *c_char_p_p,// typedef c_char_p  c_char_p_p [1]
            *c_char_p_cp,//typedef c_char_p  c_char_p_cp[const 1]
            *c_char_p_vp,//typedef c_char_p  c_char_p_vp[volatile 1]
            *c_char_p_vcp//typedef const c_char_p_vp c_char_p_vcp
            ;
    } q;
    const unsigned 
        c   = CVRF_C,
        v   = CVRF_V,
        r   = CVRF_R,           
        n   = CVRF_N,
        vc  = v|c,
        rc  = r|c,    nc  = n|c,
        rv  = r|v,    nv  = n|v,
        rvc = r|v|c,  nvc = n|v|c,
        t   = 0;
    const union unsys_tpflags f_t = {.t_constant=0};
    const union unsys_tpflags f_c = {.t_constant=1};
    const union unsys_tpflags f_v = {.t_volatile=1};
    const union unsys_tpflags f_r = {.t_restrict=1};
    const union unsys_tpflags f_n = {.t_netorder=1};

    union unsys_tpflags tcf = f_t;
    const char **d_sfx = UNSYS_DTYPE_SFX;
    const char **p_sfx = UNSYS_PTYPE_SFX;

    #if 0
    printf("CVRF_C   -> %ji\n", (intmax_t) CVRF_C);
    printf("CVRF_V   -> %ji\n", (intmax_t) CVRF_V);
    printf("CVRF_R   -> %ji\n", (intmax_t) CVRF_R);
    printf("CVRF_N   -> %ji\n", (intmax_t) CVRF_N);
    printf("CVRF_CXX -> %ji\n", (intmax_t) CVRF_CXX);
    printf("CVRF_XVX -> %ji\n", (intmax_t) CVRF_XVX);
    printf("CVRF_XXR -> %ji\n", (intmax_t) CVRF_XXR);
    printf("CVRF_XXN -> %ji\n", (intmax_t) CVRF_XXN);
    printf("CVRF_CVR -> %ji\n", (intmax_t) CVRF_CVR);
    unsigned wtf = unsys_TPFLAGS_AS_CVRF(&tcf, 0);
    printf("wtf=%u\n", wtf);
    #endif

    q.c_char_t  = unsys_ctypes+AS_CHAR;
    printf("t   = \"%.64s\"\n", unsys_TYPENAME(q.c_char_t));

    q.c_char_c  = unsys_typedef(q.c_char_t, c, 0);
    printf("c   = \"%.64s\"\n", unsys_TYPENAME(q.c_char_c));

    q.c_char_v  = unsys_typedef(q.c_char_t, v, 0);
    printf("v   = \"%.64s\"\n", unsys_TYPENAME(q.c_char_v));

    q.c_char_vc = unsys_typedef(q.c_char_t, vc, 0);
    printf("vc  = \"%.64s\"\n", unsys_TYPENAME(q.c_char_vc));

    q.c_char_p  = unsys_typedef(q.c_char_t, t, 1);
    printf("p   = \"%.64s\"\n", unsys_TYPENAME(q.c_char_p));

    q.c_char_cp  = unsys_typedef(q.c_char_t, c, 1);
    printf("cp   = \"%.64s\"\n", unsys_TYPENAME(q.c_char_cp));
    
    q.c_char_rp = unsys_typedef(q.c_char_p, r, 0);
    printf("rp  = \"%.64s\"\n", unsys_TYPENAME(q.c_char_rp));
    Py_RETURN_NONE;
}
    
static int
unsys_exec(PyObject *mod) {
    if (unsys_initialized) {
        goto the_end;
    }
    unsys.limits.c = &unsys_c_limits;
    unsys.limits.py = &unsys_py_limits;
    //unsys_INIT_C_LIMITS();
    unsys_INIT_PY_LIMITS();

    if (unsys_INIT_TINY_INTS()) {
        return 0-1;
    }

    if (unsys_INIT_ABCS(mod)) {
        return 0-1;
    }
    if (unsys_INIT_CTYPES(mod)) {
        return 0-1;
    }
    //printf(
  //      "UnBool_Type.tp_dict.t_name = %.512s\n", 
//        ((TypeAttrDict *) UnBool_Type.tp_dict)->info->t_name
  //  );
  
    unsys_initialized = 1;
    the_end: return 0;
}

static struct PyModuleDef 
unsys_moduledef = { 
    PyModuleDef_HEAD_INIT, 
    .m_name = "unsys", 
    .m_size = sizeof(struct unsys),
    .m_doc  = "smfd",
    .m_methods = (PyMethodDef[]){
        {
            .ml_name    = "identity",
            .ml_meth    = (PyCFunction) unsys_identity,
            .ml_flags   = METH_O,
            .ml_doc     = "identity(i)",
        },
        {
            .ml_name    = "testq",
            .ml_meth    = (PyCFunction) unsys_qualname,
            .ml_flags   = METH_NOARGS,
        },
        {
            .ml_name    = "float_info",
            .ml_meth    = (PyCFunction) unsys_float_info,
            .ml_flags   = METH_NOARGS,
        },
        {
            .ml_name = "index_test",
            .ml_meth = (PyCFunction) UnReal_index_test,
            .ml_flags = METH_O,
        },
        {
            .ml_name    = "bool_op_test",
            .ml_meth    = (PyCFunction) unsys_bool_op_test,
            .ml_flags   = METH_NOARGS,
            
        },
        {
            .ml_name = "pylong_cmp_test",
            .ml_meth = (PyCFunction) pylong_cmp_test,
            .ml_flags = METH_NOARGS,
        },
        {
            .ml_name = "test",
            .ml_meth = (PyCFunction) unsys_test_pylong_api,
            .ml_flags = METH_NOARGS,
            .ml_doc = "one",
        },
        {
            .ml_name = "test2",
            .ml_meth = (PyCFunction) unsys_test_pylong_api2,
            .ml_flags = METH_NOARGS,
            .ml_doc = "test2",
        },
        {
            .ml_name = "one",
            .ml_meth = (PyCFunction) unsys_one,
            .ml_flags = METH_NOARGS,
            .ml_doc = "one",
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
