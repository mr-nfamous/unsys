
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

This file is included when PyLong_SHIFT is defined as 15.
*/

#pragma once
#define pylong15_DIGITS_TO_BOOL     pylong_DIGITS_TO_BOOL
#define pylong15_DIGITS_TO_CHAR     pylong_DIGITS_TO_CHAR
#define pylong15_DIGITS_TO_UCHAR    pylong_DIGITS_TO_UCHAR
#define pylong15_DIGITS_TO_SCHAR    pylong_DIGITS_TO_SCHAR
#define pylong15_DIGITS_TO_SHORT    pylong_DIGITS_TO_SHORT
#define pylong15_DIGITS_TO_USHORT   pylong_DIGITS_TO_USHORT

#define pylong15_FROM_BOOL          pylong_FROM_BOOL
#define pylong15_FROM_UCHAR         pylong_FROM_UCHAR
#define pylong15_FROM_SCHAR         pylong_FROM_SCHAR
#define pylong15_FROM_SHORT         pylong_FROM_SHORT
#define pylong15_FROM_USHORT        pylong_FROM_USHORT


static inline PyObject *
pylong15_FROM_UINT (PyObject *mod, unsigned int n) {
    PyLongObject *v;
    if (n < 257) {
        return Py_NewRef(unsys_state(mod)->ints[n]);
    }
    if (n > 0x7fffU) {
        if (n > 0x3fffffffU) {
            if ((v=pylong_NEW(3, 3)) == NULL) {
                return NULL;
            }
            v->ob_digit[2] = (digit) (n>>30);
        }
        else {
            if ((v=pylong_NEW(2, 2)) == NULL) {
                return NULL;
            }
        }
        v->ob_digit[1] = (digit) (0x7fffU&(n>>15));
        v->ob_digit[0] = (digit) (0x7fffU&(n));
    }
    else {
        if ((v=pylong_NEW(1, 1)) == NULL) {
            return NULL;
        }
        v->ob_digit[0] = (digit) n;
    }
    return (PyObject *) v;
}

static inline PyObject *
pylong15_FROM_INT  (PyObject *mod,   signed int m) {
    PyLongObject *v;
    if (m < 0) {
        if (m < (0-128)) {
            if (m == INT_MIN) {
                return unsys_state(mod)->INT_MIN;
            }
            unsigned n = (unsigned) (0-m);
            if (n > 0x7fffU) {
                if (n > 0x3fffffffU) {
                    if ((v=pylong_NEW(3, 0-3)) == NULL) {
                        return NULL;
                    }
                    v->ob_digit[2] = (digit) (n>>30);
                }
                else {
                    if ((v=pylong_NEW(2, 0-2)) == NULL) {
                        return NULL;
                    }
                }
                v->ob_digit[1] = (digit) (0x7fffU&(n>>15));
                v->ob_digit[0] = (digit) (0x7fffU&(n));
            }
            else {
                if ((v=pylong_NEW(1, 0-1)) == NULL) {
                    return NULL;
                }
                v->ob_digit[0] = (digit) n;
            }
            return (PyObject *) v;
        }
        return Py_NewRef(unsys_state(mod)->ints[m]);
    }
    return pylong15_FROM_UINT(mod, (unsigned) m);
}

static inline int
pylong15_DIGITS_TO_INT(const digit *b, Py_ssize_t i) {
    switch (i) {
        case 000: return 0;
        case 001: return *b;
        case 002: return (int) (
                ((unsigned) b[0])
            |   ((unsigned) b[1]<<15));
        case 003: triple_pos: {
            return (int) (
                ((unsigned) b[0])
            |   ((unsigned) b[1]<<15)
            |   ((unsigned) b[2]<<30));
        }
        case 0-1: return 0-(int) *b;
        case 0-2: return 0-(int) (
                ((unsigned) b[0])
            |   ((unsigned) b[1]<<15));
        case 0-3: triple_neg: {
            return 0-(int) (
                ((unsigned) b[0])
            |   ((unsigned) b[1]<<15)
            |   ((unsigned) b[2]<<30));
        }
    }
    if (i < 0) {
        b += 0-(i+3);
        goto triple_neg;
    }
    b += i-3;
    goto triple_pos;
}

static inline unsigned int
pylong15_DIGITS_TO_UINT(const digit *b, Py_ssize_t i) {
    switch (i) {
        case 000: return 0;
        case 001: return *b;
        case 002: return (
                ((unsigned) b[0])
            |   ((unsigned) b[1]<<15));
        case 003: triple_pos: {
            return (
                ((unsigned) b[0])
            |   ((unsigned) b[1]<<15)
            |   ((unsigned) b[2]<<30));
        }
        case 0-1: return 0U-*b;
        case 0-2: return 0U-(
                ((unsigned) b[0])
            |   ((unsigned) b[1]<<15));
        case 0-3: triple_neg: {
            return 0U-(
                ((unsigned) b[0])
            |   ((unsigned) b[1]<<15)
            |   ((unsigned) b[2]<<30));
        }
    }
    if (i < 0) {
        b += 0-(i+3);
        goto triple_neg;
    }
    b += i-3;
    goto triple_pos;
}

