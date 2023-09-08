/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#pragma once

struct unsys_pyarg {
    unsys_t *t;
    void    *p;
};

struct unsys_arg_chk {
    const char *f;
    PyObject **seq;
};

struct unsys_pyargs {
    const char *fn;
    PyObject  *ob;
    Py_ssize_t lo;
    Py_ssize_t hi;
    Py_ssize_t nb;
    PyObject **sq;
  //  unsys_t   *as;
};

/*
    Check that an *args tuple contains the appropriate number 
    of arguments and if so, set sq to the tuple's ob_item.
    Returns false if no error occurs, otherwise true and sets
    the python error indicator to TypeError.
*/

static inline PyObject *
py_ERR_NOT_A_WHAT(PyObject *obj, const char *what) {
    return PyErr_Format(
        PyExc_TypeError,
        "expected %.512s (got %.512s)",
        what,
        py_TP_NAME(obj)
    );
}

static inline PyObject *
py_CHECK_FAST(PyObject *obj, unsigned long flags, const char *what) {
    if ((py_TP_FLAGS(obj)&flags) != flags) {
        return py_ERR_NOT_A_WHAT(obj, what);
    }
    return obj;
}

static inline PyObject *
py_CHECK_DICT(PyObject *obj) {
    return py_CHECK_FAST(obj, Py_TPFLAGS_DICT_SUBCLASS, "dict object");
}

static inline PyObject *
py_CHECK_TYPE(PyObject *obj) {
    return py_CHECK_FAST(obj, Py_TPFLAGS_TYPE_SUBCLASS, "type object");
}

static inline void
unsys_SWAP(void *vars[2]) {
    void *_ = vars[1];
    vars[1] = vars[0];
    vars[0] = _;
}

static inline bool
unsys_PARSE_ARGS(struct unsys_pyargs *args, PyObject ***sq) {
    if (args->sq == NULL) {
        args->sq = ((PyTupleObject *) args->ob)->ob_item;
        args->nb = Py_SIZE(args->ob);
    }
    if (args->hi < 0) {
        if (args->nb >= args->lo) {
            return (*sq=args->sq), false;
        }
        (void) PyErr_Format(
            PyExc_TypeError,
            "%s: expected %zd or more arguments (got %zd)",
            args->fn, args->lo, args->nb
        );
        return true;
    }
    if (args->lo == args->hi) {
        if (args->nb == args->lo) {
            return (*sq=args->sq), false;
        }
        if (args->lo == 1) {
            (void) PyErr_Format(
                PyExc_TypeError,
                "%s: expected 1 argument (got %zd)",
                args->fn, args->nb
            );
        }
        else {
            (void) PyErr_Format(
                PyExc_TypeError,
                "%s: expected exactly %zd arguments (got %zd)",
                args->fn, args->lo, args->nb
            );
        }
        return true;
    }
    if (args->nb >  args->hi) {
        if (args->hi == 1) {
            (void) PyErr_Format(
                PyExc_TypeError,
                "%s: expected at most 1 argument (got %zd)",
                args->fn, args->nb
            );
        }
        else {
            (void) PyErr_Format(
                PyExc_TypeError,
                "%s: expected at most %zd arguments (got %zd)",
                args->fn, args->hi, args->nb
            );
        }
        return true;
    }
    if (args->nb <  args->lo) {
        if (args->hi-args->lo == 1) {
            (void) PyErr_Format(
                PyExc_TypeError,
                "%s: expected %zd or %zd arguments (got %zd)",
                args->fn, args->lo, args->hi, args->nb
            );
        }
        else {
            (void) PyErr_Format(
                PyExc_TypeError,
                "%s: expected between %zd and %zd arguments (got %zd)",
                args->fn, args->lo, args->hi, args->nb
            );
        }
        return true;
    }
    return (*sq=args->sq), false;
}

static inline PyObject **
PARSE_ARGS_IMPL(const char *f, ssize_t lo, ssize_t hi, PyObject *args) {
    PyObject **seq = NULL;
    struct unsys_pyargs tmp = {f, args, lo, hi};
    (void) unsys_PARSE_ARGS(&tmp, &seq);
    return seq;
}

#define UNSYS_PARSE_ARGS(f, min, max) \
PARSE_ARGS_IMPL(\
    ((f == 0) ? __func__: f),\
    min,\
    max,\
    args\
)
    

static inline PyObject *
unsys_RAISE_FROM_ERRNO(void) {
    void *exc;
    if (errno == 0) {
        errno = EINVAL;
    }
    switch (errno) {
        
        case EPERM:         exc = PyExc_PermissionError; break;
        /*
        case ENOENT:        exc = PyExc_FileNotFoundError; break;
        case ESRCH:         exc = PyExc_ProcessLookupError;
        case EINTR:         exc = PyExc_InterruptedError;
        case ENXIO:
        case EIO:           exc = PyExc_IOError; break;
        case E2BIG:         exc = PyExc_EnvironmentError; break;
        
        case ECHILD:        exc = PyExc_ChildProcessError; break;
        case EAGAIN:        exc = PyExc_BlockingIOError; break;
        case ENOMEM:
        case EFAULT:        exc = PyExc_MemoryError; break;
        case EEXIST:        exc = PyExc_FileExistsError; break;
        case ENOTDIR:       exc =PyExc_NotADirectoryError; break;
        case EISDIR:        exc = PyExc_IsADirectoryError; break;
        case EPIPE:         exc = PyExc_BrokenPipeError;break;
        case ECONNABORTED:  exc = PyExc_ConnectionAbortedError; break;
        case ECONNREFUSED:  exc = PyExc_ConnectionRefusedError; break;
        case ECONNRESET:    exc = PyExc_ConnectionResetError; break;
        case ENOTCONN:      exc = PyExc_ConnectionError; break;
        case ETIMEDOUT:     exc = PyExc_TimeoutError; break;
        case EWOULDBLOCK:   exc = PyExc_BlockingIOError; break;
        */
        default:            exc = PyExc_OSError;
    }
    return PyErr_SetFromErrno(exc);
}


static inline PyObject *
unsys_ARG_CHK_FAST(struct unsys_arg_chk *args, int i, unsigned long t) {
    const unsigned long flags = 0xFF000000UL&PyType_GetFlags(
        (PyTypeObject *) args->seq[i]
    );
    if (t&flags) {
        return args->seq[i];
    }
    int n;
    const char *names[9] = {0};
    if (t&0xFF000000U) {
        n = 0;
    }
    else {
        return PyErr_Format(
            PyExc_SystemError, "%s: invalid type flag(s)", __func__
        );
    }
    if (t&Py_TPFLAGS_LONG_SUBCLASS) {
        names[n++] = "int";
    }
    if (t&Py_TPFLAGS_LIST_SUBCLASS) {
        names[n++] = "list";
    }
    if (t&Py_TPFLAGS_TUPLE_SUBCLASS) {
        names[n++] = "tuple";
    }
    if (t&Py_TPFLAGS_BYTES_SUBCLASS) {
        names[n++] = "bytes";
    }
    if (t&Py_TPFLAGS_UNICODE_SUBCLASS) {
        names[n++] = "str";
    }
    if (t&Py_TPFLAGS_DICT_SUBCLASS) {
        names[n++] = "dict";
    }
    if (t&Py_TPFLAGS_BASE_EXC_SUBCLASS) {
        names[n++] = "BaseException";
    }
    if (t&Py_TPFLAGS_TYPE_SUBCLASS) {
        names[n++] = "type";
    }
    if (n == 1) {
        return PyErr_Format(
            PyExc_TypeError,
            "%s: %s expected as args[%d] (got %s)",
            args->f,
            names[0],
            i,
            _PyType_Name(Py_TYPE(args->seq[i]))
        );
    }
    if (n == 2) {
        return PyErr_Format(
            PyExc_TypeError,
            "%s: expected %s or %s as args[%d] (got %s)",
            args->f,
            names[0], 
            names[1],
            i,
            _PyType_Name(Py_TYPE(args->seq[i]))
        );
    }
    char str[32*8+1];
    const char **last = &names[n-1];
    int off = 0;
    for (const char **name=names; name<last; name++) {
        assert(off < sizeof str);
        int adj = snprintf(str+off, (512-off), "%s, ", *name);
        if (adj < 0) {
            return unsys_RAISE_FROM_ERRNO();
        }
        off += adj;
    }
    if (snprintf(str+off, (512-off), ", or %s", *last) < 0) {
        return unsys_RAISE_FROM_ERRNO();
    }
    return PyErr_Format(
        PyExc_TypeError,
        "%s: expected %s as args[%d] (got %s)",
        args->f,
        str, i,
        _PyType_Name(Py_TYPE(args->seq[i]))
    );
}

static int unsys_PYOBJ_TO_INT(PyObject *obj);

static inline PyObject *
unsys_UNDEFINED_CAST(const char *dst, const char *src) {
    return PyErr_Format(
        PyExc_TypeError,
        "cast of %s to %s is undefined",
        src == NULL ? "<anonymous>" : src,
        dst == NULL ? "<anonymous>" : dst
    );
}

static inline PyObject *
py_ERR_NOT_AN_INT(PyObject *obj) {
    return py_ERR_NOT_A_WHAT(obj, "int object");
}

static inline PyObject *
py_ERR_NOT_A_NUMBER(PyObject *obj) {
    return py_ERR_NOT_A_WHAT(obj, "number");
}

static inline PyObject *
py_ERR_NOT_AN_INDEX(PyObject *obj) {
    return PyErr_Format(
        PyExc_TypeError,
        "can't convert %.512s object to platform ssize_t",
        py_TP_NAME(obj)
    );
}

static inline PyObject *
py_ERR_WOULD_OVERFLOW(const char *dst, const char *src) {
    return PyErr_Format(
        PyExc_OverflowError,
        "%.512s too large to assign to %.512s",
        src, 
        dst
   );
}

static inline PyObject *
py_ERR_NOT_A_DICT(PyObject *obj) {
    return py_ERR_NOT_A_WHAT(obj, "dict object");
}

static inline PyObject *
py_ERR_NOT_A_TYPE(PyObject *obj) {
    return py_ERR_NOT_A_WHAT(obj, "type object");
}
