
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

This file is included when PyLong_SHIFT is defined as 30.
*/

#pragma once

#define pylong30_DIGITS_TO_BOOL     pylong_DIGITS_TO_BOOL
#define pylong30_DIGITS_TO_CHAR     pylong_DIGITS_TO_CHAR
#define pylong30_DIGITS_TO_UCHAR    pylong_DIGITS_TO_UCHAR
#define pylong30_DIGITS_TO_SCHAR    pylong_DIGITS_TO_SCHAR
#define pylong30_DIGITS_TO_SHORT    pylong_DIGITS_TO_SHORT
#define pylong30_DIGITS_TO_USHORT   pylong_DIGITS_TO_USHORT

#define pylong30_FROM_BOOL          pylong_FROM_BOOL
#define pylong30_FROM_CHAR          pylong_FROM_CHAR
#define pylong30_FROM_UCHAR         pylong_FROM_UCHAR
#define pylong30_FROM_SCHAR         pylong_FROM_SCHAR
#define pylong30_FROM_SHORT         pylong_FROM_SHORT
#define pylong30_FROM_USHORT        pylong_FROM_USHORT

static inline unsigned
pylong30_DIGITS_TO_UINT(const digit *b, Py_ssize_t i) {
    switch (i) {
        case 001: return *b;
        case 002: return *b|((unsigned) b[1]<<30);
        case 000: return 0U;
        case 0-1: return 0U-(*b);
        case 0-2: return 0U-(*b|((unsigned) b[1]<<30));
    }
    if (i < 0) {
        b = b+(0-(i+2));
        return 0U-(*b|((unsigned) b[1]<<30));
    }
    b += i-2;
    return *b|((unsigned) b[1]<<30);
}

static inline signed
pylong30_DIGITS_TO_INT (const digit *b, Py_ssize_t i) {
    switch (i) {
        case 001: return (int) *b;
        case 002: return ((int) *b)|((int) ((unsigned) b[1]<<30));
        case 000: return 0;
        case 0-1: return 0-((int) *b);
        case 0-2: return 0-(((int) *b)|((int) ((unsigned) b[1]<<30)));
    }
    if (i < 0) {
        b = b+(0-(i+2));
        return 0-(((int) *b)|((int) ((unsigned) b[1]<<30)));
    }
    b += i-2;
    return ((int) *b)|((int) ((unsigned) b[1]<<30));
}

static inline PyObject *
pylong30_FROM_UINT(PyObject *mod, unsigned int n) {
    if (n < 257) {
        return Py_NewRef(unsys_state(mod)->ints[n]);
    }
    PyLongObject *v;
    if (n > 0x3fffffffU) {
        if ((v=pylong_NEW(2, 2)) == NULL) {
            return NULL;
        }
        v->ob_digit[0] = (digit) (n&0x3fffffffU);
        v->ob_digit[1] = (digit) (n>>30);
        return (PyObject *) v;
    }
    v = pylong_NEW(1, 1);
    v->ob_digit[0] = (digit) n;
    return (PyObject *) v;
}

static inline PyObject *
pylong30_FROM_INT (PyObject *mod,   signed int m) {
    if (m < 0) {
        PyLongObject *v;
        if (m > (0-129)) {
            return Py_NewRef(unsys_state(mod)->ints[m]);
        }
        if (m == INT_MIN) {
            return unsys_state(mod)->int_min;
        }
        unsigned n = (unsigned) (0-m);
        if (n > 0x3fffffffU) {
            if ((v=pylong_NEW(2, 0-2)) == NULL) {
                return NULL;
            }
            v->ob_digit[0] = (digit) (n&0x3fffffffU);
            v->ob_digit[1] = (digit) (n>>30);
        }
        else {
            if ((v=pylong_NEW(1, 0-1)) == NULL) {
                return NULL;
            }
            v->ob_digit[0] = (digit) n;
        }
        return (PyObject *) v;
    }
    return pylong30_FROM_UINT(mod, (unsigned) m);
}

#if INT_MAX == LONG_MAX

#   define pylong30_DIGITS_TO_ULONG     pylong30_DIGITS_TO_UINT
#   define pylong30_DIGITS_TO_LONG      pylong30_DIGITS_TO_INT
#   define pylong30_FROM_ULONG          pylong30_FROM_UINT
#   define pylong30_FROM_LONG           pylong30_FROM_INT

static inline unsigned long long
pylong30_DIGITS_TO_ULLONG(const digit *b, Py_ssize_t i) {
    switch (i) {
        case 000: return 0ULL;
        case 001: return *b;
        case 002: return (
                ((unsigned long long) b[0])
            |   ((unsigned long long) b[1]<<30));
        case 003: triple_pos: {
            return (
                ((unsigned long long) b[0])
            |   ((unsigned long long) b[1]<<30)
            |   ((unsigned long long) b[2]<<60));
        }
        case 0-1: return 0ULL-*b;
        case 0-2: return 0ULL-(
                ((unsigned long long) b[0])
            |   ((unsigned long long) b[1]<<30));
        case 0-3: triple_neg: {
            return 0ULL-(
                ((unsigned long long) b[0])
            |   ((unsigned long long) b[1]<<30)
            |   ((unsigned long long) b[2]<<60));
        }
    }
    if (i < 0) {
        b += 0-(i+3);
        goto triple_neg;
    }
    b += i-3;
    goto triple_pos;
}

static inline long long
pylong30_DIGITS_TO_LLONG (const digit *b, Py_ssize_t i) {
    switch (i) {
        case 000: return 0LL;
        case 001: return (long long) *b;
        case 002: return (long long) (
                ((unsigned long long) b[0])
            |   ((unsigned long long) b[1]<<30));
        case 003: triple_pos: {
            return (long long) (
                ((unsigned long long) b[0])
            |   ((unsigned long long) b[1]<<30)
            |   ((unsigned long long) b[2]<<60));
        }
        case 0-1: return 0LL-*b;
        case 0-2: return 0LL-(long long) (
                ((unsigned long long) b[0])
            |   ((unsigned long long) b[1]<<30));
        case 0-3: triple_neg: {
            return 0LL-(long long) (
                ((unsigned long long) b[0])
            |   ((unsigned long long) b[1]<<30)
            |   ((unsigned long long) b[2]<<60));
        }
    }
    if (i < 0) {
        b += 0-(i+3);
        goto triple_neg;
    }
    b += i-3;
    goto triple_pos;
}

static inline PyObject *
pylong30_FROM_ULLONG(PyObject *mod, unsigned long long n) {
    if (n > 256ULL) {
        PyLongObject *v;
        if (n > 0x3fffffffULL) {
            if (n > 0xfffffffffffffffULL) {
                if ((v=pylong_NEW(3, 3)) ==  NULL) {
                    return NULL;
                }
                v->ob_digit[2] = (digit) (n>>60);
            }
            else {
                if ((v=pylong_NEW(2, 2)) == NULL) {
                    return NULL;
                }
            }
            v->ob_digit[1] = (digit) (0x3fffffffULL&(n>>30));
            v->ob_digit[0] = (digit) (0x3fffffffULL&(n));
        }
        else {
            if ((v=pylong_NEW(1, 1)) == NULL) {
                return NULL;
            }
            v->ob_digit[0] = (digit) n;
        }
        return (PyObject *) v;
    }
    return Py_NewRef(unsys_state(mod)->ints[n]);
}

static inline PyObject *
pylong30_FROM_LLONG (PyObject *mod,   signed long long m) {
    if (m < 0LL) {
        if (m == LLONG_MIN) {
            return Py_NewRef(unsys_state(mod)->llong_min);
        }
    }
    else {
        return pylong30_FROM_ULLONG(mod, (unsigned long long) m);
    }
    PyLongObject *v;
    unsigned long long n = (unsigned long long) (0LL-m);
    if (n > 0x3fffffffULL) {
        if (n > 0xfffffffffffffffULL) {
            if ((v=pylong_NEW(3, 0-3)) == NULL) {
                return NULL;
            }
            v->ob_digit[2] = (digit) (n>>60);
        }
        else {
            if ((v=pylong_NEW(2, 0-2)) == NULL) {
                return NULL;
            }
        }
        v->ob_digit[1] = (digit) (0x3fffffffULL&(n>>30));
        v->ob_digit[0] = (digit) (0x3fffffffULL&(n));
    }
    else {
        if ((v=pylong_NEW(1, 0-1)) == NULL) {
            return NULL;
        }
        v->ob_digit[0] = (digit) n;
    }
    return (PyObject *) v;
}

#else

#   define pylong30_DIGITS_TO_ULLONG    pylong30_DIGITS_TO_ULONG
#   define pylong30_DIGITS_TO_LLONG     pylong30_DIGITS_TO_LONG

#   define pylong30_FROM_ULLONG         pylong30_FROM_ULONG
#   define pylong30_FROM_LLONG          pylong30_FROM_LONG

static inline unsigned long
pylong30_DIGITS_TO_ULONG(const digit *b, Py_ssize_t i) {
    switch (i) {
        case 001: return *b;
        case 002: return *b|((unsigned long) b[1]<<30);
        case 003: triple_pos: {
            return (((unsigned long) b[0]) 
                |   ((unsigned long) b[1]<<30)
                |   ((unsigned long) b[2]<<60));
        }
        case 000: return 0UL;
        case 0-1: return 0UL-(*b);
        case 0-2: return 0UL-(*b|((unsigned long) b[1]<<30));
        case 0-3: triple_neg: {
            return 0UL-(
                    ((unsigned long) b[0])
                |   ((unsigned long) b[1]<<30)
                |   ((unsigned long) b[2]<<60));
        }
    }
    if (i < 0) {
        b = b+(0-(i+3));
        goto triple_neg;
    }
    b += i-3;
    goto triple_pos;
}

static inline long
pylong30_DIGITS_TO_LONG (const digit *b, Py_ssize_t i) {
    switch (i) {
        case 001: return *b;
        case 002: return *b|((long) b[1]<<30);
        case 003: triple_pos: {
            return (((long) b[0]) 
                |   ((long) b[1]<<30)
                |   ((long) b[2]<<60));
        }
        case 000: return 0L;
        case 0-1: return 0L-(*b);
        case 0-2: return 0L-(*b|((long) b[1]<<30));
        case 0-3: triple_neg: {
            return 0UL-(
                    ((long) b[0])
                |   ((long) b[1]<<30)
                |   ((long) b[2]<<60));
        }
    }
    if (i < 0) {
        b = b+(0-(i+3));
        goto triple_neg;
    }
    b += i-3;
    goto triple_pos;
}

static inline PyObject *
pylong30_FROM_ULONG(PyObject *mod, unsigned long n) {
    if (n > 256UL) {
        PyLongObject *v;
        if (n > 0x3fffffffUL) {
            if (n > 0xfffffffffffffffUL) {
                if ((v=pylong_NEW(3, 3)) ==  NULL) {
                    return NULL;
                }
                v->ob_digit[2] = (digit) (n>>60);
            }
            else {
                if ((v=pylong_NEW(2, 2)) == NULL) {
                    return NULL;
                }
            }
            v->ob_digit[1] = (digit) (0x3fffffffUL&(n>>30));
            v->ob_digit[0] = (digit) (0x3fffffffUL&(n));
        }
        else {
            if ((v=pylong_NEW(1, 1)) == NULL) {
                return NULL;
            }
            v->ob_digit[0] = (digit) n;
        }
        return (PyObject *) v;
    }
    return Py_NewRef(unsys_state(mod)->ints[n]);
}

static inline PyObject *
pylong30_FROM_LONG (PyObject *mod,   signed long m) {
    if (m < 0L) {
        if (m == LONG_MIN) {
            return Py_NewRef(unsys_state(mod)->long_min);
        }
    }
    else {
        return pylong30_FROM_ULONG(mod, (unsigned long) m);
    }
    PyLongObject *v;
    unsigned long n = (unsigned long) (0L-m);
    if (n > 0x3fffffffUL) {
        if (n > 0xfffffffffffffffUL) {
            if ((v=pylong_NEW(3, 0-3)) == NULL) {
                return NULL;
            }
            v->ob_digit[2] = (digit) (n>>60);
        }
        else {
            if ((v=pylong_NEW(2, 0-2)) == NULL) {
                return NULL;
            }
        }
        v->ob_digit[1] = (digit) (0x3fffffffUL&(n>>30));
        v->ob_digit[0] = (digit) (0x3fffffffUL&(n));
    }
    else {
        if ((v=pylong_NEW(1, 0-1)) == NULL) {
            return NULL;
        }
        v->ob_digit[0] = (digit) n;
    }
    return (PyObject *) v;
}

#endif // INT_MAX == LONG_MAX


