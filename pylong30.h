
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

This file is included when PyLong_SHIFT is defined as 30.
*/

#pragma once

#define pylong30_DIGITS_TO_BOOL     pylong_DIGITS_TO_BOOL
#define pylong30_DIGITS_TO_CHAR     pylong_DIGITS_TO_CHAR
#define pylong30_DIGITS_TO_UCHAR    pylong_DIGITS_TO_UCHAR
#define pylong30_DIGITS_TO_SCHAR    pylong_DIGITS_TO_SCHAR
#define pylong30_DIGITS_TO_SHRT    pylong_DIGITS_TO_SHRT
#define pylong30_DIGITS_TO_USHRT   pylong_DIGITS_TO_USHRT

#define pylong30_FROM_BOOL          pylong_FROM_BOOL
#define pylong30_FROM_CHAR          pylong_FROM_CHAR
#define pylong30_FROM_UCHAR         pylong_FROM_UCHAR
#define pylong30_FROM_SCHAR         pylong_FROM_SCHAR
#define pylong30_FROM_SHRT         pylong_FROM_SHRT
#define pylong30_FROM_USHRT        pylong_FROM_USHRT

static inline bitlen_t
pylong30_BIT_LENGTH(PyObject *obj) {
    unsigned b;
    Py_ssize_t d = Py_SIZE(obj);
    if (d == 0) {
        return 0;
    }
    if (d < 0) {
        d = (0-1)-d;
        b = 1U+30U*(unsigned) d;
    }
    else {
        b = 30U*(unsigned) --d;
    }
    return b+BITLENI(pylong_DIGITS(obj)[d]);
}

static inline unsigned
pylong30_DIGITS_TO_UINT(const digit *b, Py_ssize_t n) {
    switch (n) {
        case 001: return *b;
        case 002: return *b|((unsigned) b[1]<<30);
        case 000: return 0U;
        case 0-1: return 0U-(*b);
        case 0-2: return 0U-(*b|((unsigned) b[1]<<30));
    }
    if (n < 0) {
        b = b+(0-(n+2));
        return 0U-(*b|((unsigned) b[1]<<30));
    }
    b += n-2;
    return *b|((unsigned) b[1]<<30);
}

static inline signed
pylong30_DIGITS_TO_INT (const digit *b, Py_ssize_t n) {
    switch (n) {
        case 001: return (int) *b;
        case 002: return ((int) *b)|((int) ((unsigned) b[1]<<30));
        case 000: return 0;
        case 0-1: return 0-((int) *b);
        case 0-2: return 0-(((int) *b)|((int) ((unsigned) b[1]<<30)));
    }
    if (n < 0) {
        b = b+(0-(n+2));
        return 0-(((int) *b)|((int) ((unsigned) b[1]<<30)));
    }
    b += n-2;
    return ((int) *b)|((int) ((unsigned) b[1]<<30));
}
#if LONG_MAX == INT_MAX

#   define pylong30_DIGITS_TO_ULONG pylong30_DIGITS_TO_UINT
#   define pylong30_DIGITS_TO_LONG  pylong30_DIGITS_TO_INT

#else

static inline unsigned long
pylong30_DIGITS_TO_ULONG(const digit *b, Py_ssize_t n) {
    switch (n) {
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
    if (n < 0) {
        b = b+(0-(n+3));
        goto triple_neg;
    }
    b += n-3;
    goto triple_pos;
}

static inline long
pylong30_DIGITS_TO_LONG (const digit *b, Py_ssize_t n) {
    switch (n) {
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
    if (n < 0) {
        b = b+(0-(n+3));
        goto triple_neg;
    }
    b += n-3;
    goto triple_pos;
}

#endif 

static inline unsigned long long
pylong30_DIGITS_TO_ULLONG(const digit *b, Py_ssize_t n) {
    switch (n) {
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
    if (n < 0) {
        b += 0-(n+3);
        goto triple_neg;
    }
    b += n-3;
    goto triple_pos;
}

static inline long long
pylong30_DIGITS_TO_LLONG (const digit *b, Py_ssize_t n) {
    switch (n) {
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
    if (n < 0) {
        b += 0-(n+3);
        goto triple_neg;
    }
    b += n-3;
    goto triple_pos;
}

static inline Py_ssize_t
pylong30_DIGITS_TO_INDEX(Py_ssize_t *v, const digit *b, Py_ssize_t n) {

#   if (SSIZE_MAX == INT16_MAX)

    if (n == 0) {
        return (*v=0), 0;
    }
    if (*b > SSIZE_MAX) {
        if (n < 0) {
            if ((*b-1) == SSIZE_MAX) {
                return (*v=(0-SSIZE_MAX)-1), 0;
            }
        }
        goto overflow;
    }
    else {
        return (*v=(n < 0) ? (0-*b) : *b), 0;
    }

#   elif (SSIZE_MAX == INT32_MAX)

    switch (n) {
        case 0*0: return (*v=(0)), 0;
        case 0-1: return (*v=(0-*b)), 0;
        case 0+1: return (*v=(*b)), 0;
        case 0+2: {
            if (b[1] != 1) {
                goto overflow;
            }
            return (*v=(*b|(1<<30))), 0;
        }
        case 0-2: {
            if (b[1] > 1) {
                if ((b[1] == 2) && (!*b)) {
                    return (*v=INT32_MIN), 0;
                }
                goto overflow;
            }
            return (*v=0-(*b|(1<<30))), 0;
        }
    }

#   else

    switch (n) {
        case 0*0: return (*v=0), 0;
        case 0+1: return (*v=*b), 0;
        case 0-1: return (*v=(0-*b)), 0;
        case 0+2: return (*v=*b|((Py_ssize_t) b[1]<<30)), 0;
        case 0+3: {
            if (b[2] > 7) {
                goto overflow;
            }
            *v = (  ((Py_ssize_t) b[0])
                |   ((Py_ssize_t) b[1]<<30)
                |   ((Py_ssize_t) b[2]<<60)
            );
            return 0;
        }
        case 0-3: {
            if (b[2] > 7) {
                if ((b[2] == 8) && (b[1] == 0) && (b[0] == 0)) {
                    return (*v=INT64_MIN), 0;
                }
            }
            *v = 0-(((Py_ssize_t) *b)
                |   ((Py_ssize_t) b[1]<<30)
                |   ((Py_ssize_t) b[2]<<60)
            );
            return 0;
        }
    }

#endif
    overflow: {
        PyErr_SetString(
            PyExc_OverflowError,
            "Python int too large to convert to platform ssize_t"
        );
    }
    return 0-1;
}

static inline PyObject *
pylong30_FROM_UINT(unsigned int n) {
    if (n < 257) {
        return Py_NewRef(unsys.ints[n]);
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
pylong30_FROM_INT (signed int m) {
    if (m < 0) {
        PyLongObject *v;
        if (m > (0-129)) {
            return Py_NewRef(unsys.ints[m]);
        }
        if (m == INT_MIN) {
            return Py_NewRef(unsys.limits.py->int_min);
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
    return pylong30_FROM_UINT((unsigned) m);
}

static inline PyObject *
pylong30_FROM_ULONG(unsigned long n) {
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
            v->ob_digit[0] = (digit) (0x3fffffffUL&(n));
            v->ob_digit[1] = (digit) (0x3fffffffUL&(n>>30));
        }
        else {
            if ((v=pylong_NEW(1, 1)) == NULL) {
                return NULL;
            }
            v->ob_digit[0] = (digit) n;
        }
        return (PyObject *) v;
    }
    return Py_NewRef(unsys.ints[n]);
}

static inline PyObject *
pylong30_FROM_LONG (signed long m) {
    if (m < 0L) {
        if (m == LONG_MIN) {
            return Py_NewRef(unsys.limits.py->long_min);
        }
    }
    else {
        return pylong30_FROM_ULONG((unsigned long) m);
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

static inline PyObject *
pylong30_FROM_ULLONG(unsigned long long n) {
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
    return Py_NewRef(unsys.ints[n]);
}

static inline PyObject *
pylong30_FROM_LLONG (signed long long m) {
    if (m < 0LL) {
        if (m == LLONG_MIN) {
            return Py_NewRef(unsys.limits.py->llong_min);
        }
    }
    else {
        return pylong30_FROM_ULLONG((unsigned long long) m);
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

static inline int
pylong30_UCMP_DIGITS(uintmax_t a, const digit *b, Py_ssize_t n) {
    uintmax_t r;
    switch (n) {
        case 0: {
            return (a == 0) ? 0 : 1;
        }
        case 1: {
            return (a > *b) ? 1 : (a == *b) ? 0 : (0-1);
        }
        case 2: {
            if (a < (UINTMAX_C(1)<<30)) {
                return 0-1;
            }
            r = (
                ((uintmax_t) b[0])
            |   ((uintmax_t) b[1]<<30)
            );
            break;
        }
        case 3: {
            if (b[2] > 15) {
                return 0-1;
            }
            if (a < (UINTMAX_C(1)<<60)) {
                return 0-1;
            }
            r = (
                ((uintmax_t) b[0])
            |   ((uintmax_t) b[1]<<30)
            |   ((uintmax_t) b[2]<<60)
            );
            break;
        }
        default: {
            return 0-1;
        }
    }
    if (a <= r) {
        return (a == r) ? 0 : (0-1);
    }
    return 1;
}
    
static inline int
pylong30_SCMP_DIGITS (intmax_t a, const digit *b, Py_ssize_t n) {
    intmax_t r;
    switch (n) {
        case 000: {
            return (a == 0) ? 0 : ((a < 0) ? (0-1) : 1);
        }
        case 001: {
            r = *b;
            break;
        }
        case 002: {
            if (a < (INTMAX_C(1)<<30)) {
                return 0-1;
            }
            r = (intmax_t)(
                ((uintmax_t) b[0])
            |   ((uintmax_t) b[1]<<30)
            );
            break;
        }
        case 003: {
            if (b[2] > 7) {
                return 0-1;
            }
            if (a < (INTMAX_C(1)<<60)) {
                return 0-1;
            }
            r = (intmax_t)(
                ((uintmax_t) b[0])
            |   ((uintmax_t) b[1]<<30)
            |   ((uintmax_t) b[2]<<60)
            );
            break;
        }
        case 0-1: {
            r = INTMAX_C(0)-*b;
            break;
        }
        case 0-2: {
            if (a > (0-(INTMAX_C(1)<<30))) {
                return 1;
            }
            r = 0-(intmax_t)(
                ((uintmax_t) b[0])
            |   ((uintmax_t) b[1]<<30)
            );
            break;
        }
        case 0-3: {
            if (a > (0-(INTMAX_C(1)<<60))) {
                return 1;
            }
            if (b[2] > 7) {
                if (b[2] == 8) {
                    if (b[1] == 0) {
                        if (b[0] == 0) {
                            return a != INTMAX_MIN;
                        }
                    }
                }
                return 1;
            }
            r = INTMAX_C(0)-(intmax_t)(
                ((uintmax_t) b[0])
            |   ((uintmax_t) b[1]<<30)
            |   ((uintmax_t) b[2]<<60)
            );
            break;
        }
    }
    if (a == r) {
        return 0;
    }
    return (a < r) ? (0-1) : 1;
}

static inline float
pylong30_DIGITS_TO_FLT(const digit *d, ssize_t len) {
    return HUGE_VALF;
}

static inline double
pylong30_DIGITS_TO_DBL(const digit *d, Py_ssize_t len) {
    Py_ssize_t  i;
    twodigits   m;
    int b;
    int s;
    int x;
    int l;
    switch (len) {
        case 0-1: return 0.0+(*d);
        case 0-2: return 0.0+(*d|(twodigits) d[1]<<30);
        case 000: return 0.0;
        case 001: return *d;
        case 002: return *d|((twodigits) d[1]<<30);        
    }
    if (len < 0) {
        i = (len=0-len)-1;
        if (i > DBL_MAX_EXP/30) {
            return HUGE_VAL;
        }
        s = BITLENI(m=d[i]);
        b = s+(int) i*30;
        if (b > DBL_MAX_EXP) {
            return HUGE_VAL;
        }
        if (s > 22) {
            x = s-23;
            l = 30-x;
            m = (m<<l)|(d[i-2]>>x);
        }
        else {
            x = 23-s;
            l = 53-s;
            m <<= l;
            m |= (twodigits) d[i-2]<<x;
            m |= d[i-3]>>(7+s);
        }
        return ldexp(0.0-m, b-53);
    }
    if (len > DBL_MAX_EXP/30) {
        return HUGE_VAL;
    }
    s = BITLENI(d[i=len-1]);
    b = s+(int) i*30;
    if (b < DBL_MAX_EXP/30) {
        return HUGE_VAL;
    }
    if (s > 22) {
        x = s-23;
        l = 30-x;
        m = (d[i]<<l)|((twodigits) d[i-2]>>x);
    }
    else {
        m = (
            ((twodigits) d[i  ]<<(53-s))
        |   ((twodigits) d[i-2]<<(23-s))
        |   ((twodigits) d[i-3]>>(8+s)));
    }
    return ldexp(m, b-53);
}

static inline long double
pylong30_DIGITS_TO_LDBL(const digit *d, ssize_t len) {
    return HUGE_VALL;
}