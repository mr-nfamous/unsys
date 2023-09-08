/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

Real data wrapper types
:
    
*/
#pragma once


static PyObject *UnBool_binop(PyObject *, PyObject *, int);
static PyObject *UnSchar_binop(PyObject *, PyObject *, int);
static PyObject *UnUchar_binop(PyObject *, PyObject *, int);
static PyObject *UnShort_binop(PyObject *, PyObject *, int);
static PyObject *UnUshort_binop(PyObject *, PyObject *, int);
static PyObject *UnInt_binop(PyObject *, PyObject *, int);
static PyObject *UnUint_binop(PyObject *, PyObject *, int);
static PyObject *UnLong_binop(PyObject *, PyObject *, int);
static PyObject *UnUlong_binop(PyObject *, PyObject *, int);
static PyObject *UnLlong_binop(PyObject *, PyObject *, int);
static PyObject *UnUllong_binop(PyObject *, PyObject *, int);
static PyObject *UnFloat_binop(PyObject *, PyObject *, int);
static PyObject *UnDouble_binop(PyObject *, PyObject *, int);
static PyObject *UnLdouble_binop(PyObject *, PyObject *, int);

static PyObject *UnBool_inplace_binop(PyObject *, PyObject *, int);
static PyObject *UnSchar_inplace_binop(PyObject *, PyObject *, int);
static PyObject *UnUchar_inplace_binop(PyObject *, PyObject *, int);
static PyObject *UnShort_inplace_binop(PyObject *, PyObject *, int);
static PyObject *UnUshort_inplace_binop(PyObject *, PyObject *, int);
static PyObject *UnInt_inplace_binop(PyObject *, PyObject *, int);
static PyObject *UnUint_inplace_binop(PyObject *, PyObject *, int);
static PyObject *UnLong_inplace_binop(PyObject *, PyObject *, int);
static PyObject *UnUlong_inplace_binop(PyObject *, PyObject *, int);
static PyObject *UnLlong_inplace_binop(PyObject *, PyObject *, int);
static PyObject *UnUllong_inplace_binop(PyObject *, PyObject *, int);
static PyObject *UnFloat_inplace_binop(PyObject *, PyObject *, int);
static PyObject *UnDouble_inplace_binop(PyObject *, PyObject *, int);
static PyObject *UnLdouble_inplace_binop(PyObject *, PyObject *, int);

static PyObject *
(*UnReal_binops[AS_BLTN_MAX])
(PyObject *, PyObject *, int) = {
    [AS_FLT]        = UnFloat_binop,
    [AS_DBL]        = UnDouble_binop,
    [AS_LDBL]       = UnLdouble_binop,
    [AS_BOOL]       = UnBool_binop,
    [AS_SCHAR]      = UnSchar_binop,
    [AS_UCHAR]      = UnUchar_binop,
    [AS_SHRT]       = UnShort_binop,
    [AS_USHRT]      = UnUshort_binop,
    [AS_INT]        = UnInt_binop,
    [AS_UINT]       = UnUint_binop,
    [AS_LONG]       = UnLong_binop,
    [AS_ULONG]      = UnUlong_binop,
    [AS_LLONG]      = UnLlong_binop,
    [AS_ULLONG]     = UnUllong_binop,
    [AS_INT8]       = UnSchar_binop,
    [AS_INT16]      = UnShort_binop,
    [AS_INT32]      = UnInt_binop,
    [AS_UINT8]      = UnUchar_binop,
    [AS_UINT16]     = UnUshort_binop,
    [AS_UINT32]     = UnUint_binop,

#   define  UnInt8_impl UnSchar_impl
#   define UnUint8_impl UnUchar_impl

#   define  UnInt16_impl  UnShort_impl
#   define UnUint16_impl UnUshort_impl

#   define  UnInt32_impl  UnInt_impl
#   define UnUint32_impl UnUint_impl

#if INT64_RANK == LONG_RANK
#   define  UnInt64_impl  UnLong_impl
#   define UnUint64_impl UnUlong_impl
    [AS_INT64]      =  UnLong_binop,
    [AS_UINT64]     = UnUlong_binop,
#else
#   define  UnInt64_impl  UnLlong_impl
#   define UnUint64_impl UnUllong_impl
    [AS_INT64]      =  UnLlong_binop,
    [AS_UINT64]     = UnUllong_binop,
#endif

#if INTMAX_RANK == LONG_RANK
#   define  UnIntmax_impl  UnLong_impl
#   define UnUintmax_impl UnUlong_impl
    [AS_INTMAX]      =  UnLong_binop,
    [AS_UINTMAX]     = UnUlong_binop,
#else
#   define  UnIntmax_impl  UnLlong_impl
#   define UnUintmax_impl UnUllong_impl
    [AS_INTMAX]      =  UnLlong_binop,
    [AS_UINTMAX]     = UnUllong_binop,
#endif


#   if  (SIZE_RANK == USHRT_RANK)
#   define  UnSize_impl UnUshort_impl
#   define UnSsize_impl  UnShort_impl
    [AS_SIZE]       = UnInt_binop,
    [AS_SSIZE]      = UnInt_binop,

#   elif(SIZE_RANK == UINT_RANK)
#   define  UnSize_impl UnUint_impl
#   define UnSsize_impl  UnInt_impl
    [AS_SIZE]       = UnUint_binop,
    [AS_SSIZE]      =  UnInt_binop,

#   elif(SIZE_RANK == ULONG_RANK)
#   define  UnSize_impl UnUlong_impl
#   define UnSsize_impl  UnLong_impl
    [AS_SIZE]       = UnUlong_binop,
    [AS_SSIZE]      =  UnLong_binop,

#   elif(SIZE_RANK == ULLONG_RANK)
#   define UnSize_impl  UnUllong_impl
#   define UnSsize_impl  UnLlong_impl
    [AS_SIZE]       = UnUllong_binop,
    [AS_SSIZE]      =  UnLlong_binop,
#   endif


#if (INTPTR_RANK == SHRT_RANK)
#   define  UnIntptr_impl  UnShort_impl
#   define UnUintptr_impl UnUshort_impl
    [AS_INTPTR]     = UnInt_binop,
    [AS_UINTPTR]    = UnInt_binop,
#elif    (INTPTR_RANK == INT_RANK)
#   define  UnIntptr_impl  UnInt_impl
#   define UnUintptr_impl UnUint_impl
    [AS_INTPTR]     =  UnInt_binop,
    [AS_UINTPTR]    = UnUint_binop,
#elif    (INTPTR_RANK == LONG_RANK)
#   define  UnIntptr_impl  UnLong_impl
#   define UnUintptr_impl UnUlong_impl
    [AS_INTPTR]     =  UnLong_binop,
    [AS_UINTPTR]    = UnUlong_binop,
#elif    (INTPTR_RANK == LLONG_RANK) 
#   define  UnIntptr_impl  UnLlong_impl
#   define UnUintptr_impl UnUllong_impl
    [AS_INTPTR]     =  UnLlong_binop,
    [AS_UINTPTR]    = UnUllong_binop,
#endif

#if     (PTRDIFF_RANK == SHRT_RANK)
#   define UnPtrdiff_impl UnShort_impl
    [AS_PTRDIFF]    = UnInt_binop,
#elif   (PTRDIFF_RANK == INT_RANK)
#   define UnPtrdiff_impl UnInt_impl
    [AS_PTRDIFF]    = UnInt_binop,
#elif   (PTRDIFF_RANK == LONG_RANK)
#   define UnPtrdiff_impl UnLong_impl
    [AS_PTRDIFF]    = UnLong_binop,
#else
#   define UnPtrdiff_impl UnLlong_impl
    [AS_PTRDIFF]    = UnLlong_binop,
#endif

#if (WINT_SIGNEDNESS == NB_SIGNED)
#   if (WINT_RANK == SHRT_RANK)
#   define UnWint_impl UnShort_impl
    [AS_WINT]       = UnInt_binop,
#   elif (WINT_RANK == INT_RANK)
#   define UnWint_impl UnInt_impl
    [AS_WINT]       = UnInt_binop,
#   else
#   define UnWint_impl UnLong_impl
    [AS_WINT] = UnLong_binop,
#   endif
#else 
#   if (WINT_RANK == SHRT_RANK)
#   define UnWint_impl UnUshort_impl
    [AS_WINT]       = UnInt_binop,
#   elif (WINT_RANK == INT_RANK)
#   define UnWint_impl UnUint_impl
    [AS_WINT]       = UnUint_binop,
#   else
#   define UnWint_impl UnUlong_impl
    [AS_WINT]       = UnUlong_binop,
#   endif
#endif
};

static PyObject *
(*UnReal_inplace_binops[AS_BLTN_MAX])
(PyObject *, PyObject *, int) = {
    [AS_FLT]        = UnFloat_inplace_binop,
    [AS_DBL]        = UnDouble_inplace_binop,
    [AS_LDBL]       = UnLdouble_inplace_binop,
    [AS_BOOL]       = UnBool_inplace_binop,
    [AS_SCHAR]      = UnSchar_inplace_binop,
    [AS_UCHAR]      = UnUchar_inplace_binop,
    [AS_SHRT]       = UnShort_inplace_binop,
    [AS_USHRT]      = UnUshort_inplace_binop,
    [AS_INT]        = UnInt_inplace_binop,
    [AS_UINT]       = UnUint_inplace_binop,
    [AS_LONG]       = UnLong_inplace_binop,
    [AS_ULONG]      = UnUlong_inplace_binop,
    [AS_LLONG]      = UnLlong_inplace_binop,
    [AS_ULLONG]     = UnUllong_inplace_binop,
    [AS_INT8]       = UnSchar_inplace_binop,
    [AS_INT16]      = UnShort_inplace_binop,
    [AS_INT32]      = UnInt_inplace_binop,
    [AS_UINT8]      = UnUchar_inplace_binop,
    [AS_UINT16]     = UnUshort_inplace_binop,
    [AS_UINT32]     = UnUint_inplace_binop,

#if INT64_RANK == LONG_RANK
    [AS_INT64]      =  UnLong_inplace_binop,
    [AS_UINT64]     = UnUlong_inplace_binop,
#else
    [AS_INT64]      =  UnLlong_inplace_binop,
    [AS_UINT64]     = UnUllong_inplace_binop,
#endif

#if INTMAX_RANK == LONG_RANK
    [AS_INTMAX]      =  UnLong_inplace_binop,
    [AS_UINTMAX]     = UnUlong_inplace_binop,
#else
    [AS_INTMAX]      =  UnLlong_inplace_binop,
    [AS_UINTMAX]     = UnUllong_inplace_binop,
#endif

#   if  (SIZE_RANK == USHRT_RANK)
    [AS_SIZE]       = UnInt_inplace_binop,
    [AS_SSIZE]      = UnInt_inplace_binop,
#   elif(SIZE_RANK == UINT_RANK)
    [AS_SIZE]       = UnUint_inplace_binop,
    [AS_SSIZE]      =  UnInt_inplace_binop,
#   elif(SIZE_RANK == ULONG_RANK)
    [AS_SIZE]       = UnUlong_inplace_binop,
    [AS_SSIZE]      =  UnLong_inplace_binop,
#   elif(SIZE_RANK == ULLONG_RANK)
    [AS_SIZE]       = UnUllong_inplace_binop,
    [AS_SSIZE]      =  UnLlong_inplace_binop,
#   endif

#if (INTPTR_RANK == SHRT_RANK)
    [AS_INTPTR]     = UnInt_inplace_binop,
    [AS_UINTPTR]    = UnInt_inplace_binop,
#elif    (INTPTR_RANK == INT_RANK)
    [AS_INTPTR]     =  UnInt_inplace_binop,
    [AS_UINTPTR]    = UnUint_inplace_binop,
#elif    (INTPTR_RANK == LONG_RANK)
    [AS_INTPTR]     =  UnLong_inplace_binop,
    [AS_UINTPTR]    = UnUlong_inplace_binop,
#elif    (INTPTR_RANK == LLONG_RANK) 
    [AS_INTPTR]     =  UnLlong_inplace_binop,
    [AS_UINTPTR]    = UnUllong_inplace_binop,
#endif

#if     (PTRDIFF_RANK == SHRT_RANK)
    [AS_PTRDIFF]    = UnInt_inplace_binop,
#elif   (PTRDIFF_RANK == INT_RANK)
    [AS_PTRDIFF]    = UnInt_inplace_binop,
#elif   (PTRDIFF_RANK == LONG_RANK)
    [AS_PTRDIFF]    = UnLong_inplace_binop,
#else
    [AS_PTRDIFF]    = UnLlong_inplace_binop,
#endif

#if (WINT_SIGNEDNESS == NB_SIGNED)
#   if (WINT_RANK == SHRT_RANK)
    [AS_WINT]       = UnInt_inplace_binop,
#   elif (WINT_RANK == INT_RANK)
    [AS_WINT]       = UnInt_inplace_binop,
#   else
    [AS_WINT] = UnLong_inplace_binop,
#   endif
#else 
#   if (WINT_RANK == SHRT_RANK)
    [AS_WINT]       = UnInt_inplace_binop,
#   elif (WINT_RANK == INT_RANK)
    [AS_WINT]       = UnUint_inplace_binop,
#   else
    [AS_WINT]       = UnUlong_inplace_binop,
#   endif
#endif
};

#define unsys_FSUITE_DEF(src_t) \
unsys_FVAL_DEF(float,               src_t, FLT)\
unsys_FVAL_DEF(double,              src_t, DBL)\
unsys_FVAL_DEF(long double,         src_t, LDBL)\
unsys_FVAL_DEF(_Bool,               src_t, BOOL)\
unsys_FVAL_DEF(signed char,         src_t, SCHAR)\
unsys_FVAL_DEF(short,               src_t, SHRT)\
unsys_FVAL_DEF(int,                 src_t, INT)\
unsys_FVAL_DEF(long,                src_t, LONG)\
unsys_FVAL_DEF(long long,           src_t, LLONG)\
unsys_FVAL_DEF(ssize_t,             src_t, SSIZE)\
unsys_FVAL_DEF(intptr_t,            src_t, INTPTR)\
unsys_FVAL_DEF(ptrdiff_t,           src_t, PTRDIFF)\
unsys_FVAL_DEF(int8_t,              src_t, INT8)\
unsys_FVAL_DEF(int16_t,             src_t, INT16)\
unsys_FVAL_DEF(int32_t,             src_t, INT32)\
unsys_FVAL_DEF(int64_t,             src_t, INT64)\
unsys_FVAL_DEF(intmax_t,            src_t, INTMAX)\
unsys_FVAL_DEF(unsigned char,       src_t, UCHAR)\
unsys_FVAL_DEF(unsigned short,      src_t, USHRT)\
unsys_FVAL_DEF(unsigned int,        src_t, UINT)\
unsys_FVAL_DEF(unsigned long,       src_t, ULONG)\
unsys_FVAL_DEF(unsigned long long,  src_t, ULLONG)\
unsys_FVAL_DEF(size_t,              src_t, SIZE)\
unsys_FVAL_DEF(uintptr_t,           src_t, UINTPTR)\
unsys_FVAL_DEF(uint8_t,             src_t, UINT8)\
unsys_FVAL_DEF(uint16_t,            src_t, UINT16)\
unsys_FVAL_DEF(uint32_t,            src_t, UINT32)\
unsys_FVAL_DEF(uint64_t,            src_t, UINT64)\
unsys_FVAL_DEF(uintmax_t,           src_t, UINTMAX)\
unsys_FVAL_DEF(wint_t,              src_t, WINT)

#define unsys_SSUITE_DEF(src_t, stg_t) \
unsys_SVAL_DEF(char,                src_t, CHAR,    stg_t)\
unsys_SVAL_DEF(wchar_t,             src_t, WCHAR,   stg_t)\
unsys_SVAL_DEF(char16_t,            src_t, CHAR16,  stg_t)\
unsys_SVAL_DEF(char32_t,            src_t, CHAR32,  stg_t)\
unsys_SVAL_DEF(float,               src_t, FLT,     stg_t)\
unsys_SVAL_DEF(double,              src_t, DBL,     stg_t)\
unsys_SVAL_DEF(long double,         src_t, LDBL,    stg_t)\
unsys_SVAL_DEF(_Bool,               src_t, BOOL,    stg_t)\
unsys_SVAL_DEF(signed char,         src_t, SCHAR,   stg_t)\
unsys_SVAL_DEF(short,               src_t, SHRT,    stg_t)\
unsys_SVAL_DEF(int,                 src_t, INT,     stg_t)\
unsys_SVAL_DEF(long,                src_t, LONG,    stg_t)\
unsys_SVAL_DEF(long long,           src_t, LLONG,   stg_t)\
unsys_SVAL_DEF(ssize_t,             src_t, SSIZE,   stg_t)\
unsys_SVAL_DEF(intptr_t,            src_t, INTPTR,  stg_t)\
unsys_SVAL_DEF(ptrdiff_t,           src_t, PTRDIFF, stg_t)\
unsys_SVAL_DEF(int8_t,              src_t, INT8,    stg_t)\
unsys_SVAL_DEF(int16_t,             src_t, INT16,   stg_t)\
unsys_SVAL_DEF(int32_t,             src_t, INT32,   stg_t)\
unsys_SVAL_DEF(int64_t,             src_t, INT64,   stg_t)\
unsys_SVAL_DEF(intmax_t,            src_t, INTMAX,  stg_t)\
unsys_SVAL_DEF(unsigned char,       src_t, UCHAR,   stg_t)\
unsys_SVAL_DEF(unsigned short,      src_t, USHRT,   stg_t)\
unsys_SVAL_DEF(unsigned int,        src_t, UINT,    stg_t)\
unsys_SVAL_DEF(unsigned long,       src_t, ULONG,   stg_t)\
unsys_SVAL_DEF(unsigned long long,  src_t, ULLONG,  stg_t)\
unsys_SVAL_DEF(size_t,              src_t, SIZE,    stg_t)\
unsys_SVAL_DEF(uintptr_t,           src_t, UINTPTR, stg_t)\
unsys_SVAL_DEF(uint8_t,             src_t, UINT8,   stg_t)\
unsys_SVAL_DEF(uint16_t,            src_t, UINT16,  stg_t)\
unsys_SVAL_DEF(uint32_t,            src_t, UINT32,  stg_t)\
unsys_SVAL_DEF(uint64_t,            src_t, UINT64,  stg_t)\
unsys_SVAL_DEF(uintmax_t,           src_t, UINTMAX, stg_t)\
unsys_SVAL_DEF(wint_t,              src_t, WINT,    stg_t)

//#define unsys_UVAL_DEF(R, C, T, P) static R C##_AS_##T(P *o) {return (R) o->uval;}

#define unsys_USUITE_DEF(src_t, stg_t) \
unsys_UVAL_DEF(char,                src_t, CHAR,    stg_t)\
unsys_UVAL_DEF(wchar_t,             src_t, WCHAR,   stg_t)\
unsys_UVAL_DEF(char16_t,            src_t, CHAR16,  stg_t)\
unsys_UVAL_DEF(char32_t,            src_t, CHAR32,  stg_t)\
unsys_UVAL_DEF(float,               src_t, FLT,     stg_t)\
unsys_UVAL_DEF(double,              src_t, DBL,     stg_t)\
unsys_UVAL_DEF(long double,         src_t, LDBL,    stg_t)\
unsys_UVAL_DEF(_Bool,               src_t, BOOL,    stg_t)\
unsys_UVAL_DEF(signed char,         src_t, SCHAR,   stg_t)\
unsys_UVAL_DEF(short,               src_t, SHRT,    stg_t)\
unsys_UVAL_DEF(int,                 src_t, INT,     stg_t)\
unsys_UVAL_DEF(long,                src_t, LONG,    stg_t)\
unsys_UVAL_DEF(long long,           src_t, LLONG,   stg_t)\
unsys_UVAL_DEF(ssize_t,             src_t, SSIZE,   stg_t)\
unsys_UVAL_DEF(intptr_t,            src_t, INTPTR,  stg_t)\
unsys_UVAL_DEF(ptrdiff_t,           src_t, PTRDIFF, stg_t)\
unsys_UVAL_DEF(int8_t,              src_t, INT8,    stg_t)\
unsys_UVAL_DEF(int16_t,             src_t, INT16,   stg_t)\
unsys_UVAL_DEF(int32_t,             src_t, INT32,   stg_t)\
unsys_UVAL_DEF(int64_t,             src_t, INT64,   stg_t)\
unsys_UVAL_DEF(intmax_t,            src_t, INTMAX,  stg_t)\
unsys_UVAL_DEF(unsigned char,       src_t, UCHAR,   stg_t)\
unsys_UVAL_DEF(unsigned short,      src_t, USHRT,   stg_t)\
unsys_UVAL_DEF(unsigned int,        src_t, UINT,    stg_t)\
unsys_UVAL_DEF(unsigned long,       src_t, ULONG,   stg_t)\
unsys_UVAL_DEF(unsigned long long,  src_t, ULLONG,  stg_t)\
unsys_UVAL_DEF(size_t,              src_t, SIZE,    stg_t)\
unsys_UVAL_DEF(uintptr_t,           src_t, UINTPTR, stg_t)\
unsys_UVAL_DEF(uint8_t,             src_t, UINT8,   stg_t)\
unsys_UVAL_DEF(uint16_t,            src_t, UINT16,  stg_t)\
unsys_UVAL_DEF(uint32_t,            src_t, UINT32,  stg_t)\
unsys_UVAL_DEF(uint64_t,            src_t, UINT64,  stg_t)\
unsys_UVAL_DEF(uintmax_t,           src_t, UINTMAX, stg_t)\
unsys_UVAL_DEF(wint_t,              src_t, WINT,    stg_t)


static PyObject *UnSchar_AS_BIGINT(UnChar *o) {
    return pylong_FROM_SCHAR(o->sval);
}
static PyObject *UnShort_AS_BIGINT(UnShort *o) {
    return pylong_FROM_SHRT(o->sval);
}
static PyObject *  UnInt_AS_BIGINT(UnInt *o) {
    return pylong_FROM_INT(o->sval);
}
static PyObject * UnLong_AS_BIGINT(UnLong *o) {
    return pylong_FROM_LONG(o->sval);
}
static PyObject *UnLlong_AS_BIGINT(UnLlong *o) {
    return pylong_FROM_LLONG(o->sval);
}

static PyObject *  UnBool_AS_BIGINT(UnBool *o) {
    return pylong_FROM_BOOL(o->uval);
}

static PyObject * UnUchar_AS_BIGINT(UnChar *o) {
    return pylong_FROM_UCHAR(o->sval);
}
static PyObject *UnUshort_AS_BIGINT(UnShort *o) {
    return pylong_FROM_USHRT(o->uval);
}
static PyObject *  UnUint_AS_BIGINT(UnInt *o) {
    return pylong_FROM_UINT(o->uval);
}
static PyObject * UnUlong_AS_BIGINT(UnLong *o) {
    return pylong_FROM_ULONG(o->uval);
}
static PyObject *UnUllong_AS_BIGINT(UnLlong *o) {
    return pylong_FROM_ULLONG(o->uval);
}

static PyObject *  UnFloat_AS_BIGINT(UnFloat *o) {
    return pylong_FROM_FLT(o->fval);
}
static PyObject * UnDouble_AS_BIGINT(UnDouble *o) {
    return pylong_FROM_DBL(o->fval);
}
static PyObject *UnLdouble_AS_BIGINT(UnLdouble *o) {
    return pylong_FROM_LDBL(o->fval);
}

#define UnInteger_CONV_SUITE(T, O, A) \
static void * T##_AS_ADDR(O *i) {return (void *) (intptr_t) i->A;}\
static void ** T##_AS_ADDRPTR(O *i) {return (void **) (intptr_t) i->A;}\
static               char T##_AS_CHAR(O *i) {return (char) i->A;}\
static            wchar_t T##_AS_WCHAR(O *i) {return (wchar_t) i->A;}\
static           char16_t T##_AS_CHAR16(O *i) {return (char16_t) i->A;}\
static           char32_t T##_AS_CHAR32(O *i) {return (char32_t) i->A;}\
static              float T##_AS_FLT(O *i) {return (float) i->A;}\
static             double T##_AS_DBL(O *i) {return (double) i->A;}\
static        long double T##_AS_LDBL(O *i) {return (long double) i->A;}\
static   signed      char T##_AS_SCHAR(O *i) {return (signed char) i->A;}\
static   signed     short T##_AS_SHRT(O *i) {return (signed short) i->A;}\
static   signed       int T##_AS_INT(O *i) {return (signed int) i->A;}\
static   signed      long T##_AS_LONG(O *i) {return (signed long) i->A;}\
static   signed long long T##_AS_LLONG(O *i) {return (signed long long) i->A;}\
static            ssize_t T##_AS_SSIZE(O *i) {return (ssize_t) i->A;}\
static           intptr_t T##_AS_INTPTR(O *i) {return (intptr_t) i->A;}\
static          ptrdiff_t T##_AS_PTRDIFF(O *i) {return (ptrdiff_t) i->A;}\
static             int8_t T##_AS_INT8(O *i) {return (int8_t) i->A;}\
static            int16_t T##_AS_INT16(O *i) {return (int16_t) i->A;}\
static            int32_t T##_AS_INT32(O *i) {return (int32_t) i->A;}\
static            int64_t T##_AS_INT64(O *i) {return (int64_t) i->A;}\
static           intmax_t T##_AS_INTMAX(O *i) {return (intmax_t) i->A;}\
static              _Bool T##_AS_BOOL(O *i) {return (_Bool) i->A;}\
static unsigned      char T##_AS_UCHAR(O *i) {return (unsigned char) i->A;}\
static unsigned     short T##_AS_USHRT(O *i) {return (unsigned short) i->A;}\
static unsigned       int T##_AS_UINT(O *i) {return (unsigned int) i->A;}\
static unsigned      long T##_AS_ULONG(O *i) {return (unsigned long) i->A;}\
static unsigned long long T##_AS_ULLONG(O *i) {return (unsigned long long) i->A;}\
static             size_t T##_AS_SIZE(O *i) {return (size_t) i->A;}\
static          uintptr_t T##_AS_UINTPTR(O *i) {return (uintptr_t) i->A;}\
static            uint8_t T##_AS_UINT8(O *i) {return (uint8_t) i->A;}\
static           uint16_t T##_AS_UINT16(O *i) {return (uint16_t) i->A;}\
static           uint32_t T##_AS_UINT32(O *i) {return (uint32_t) i->A;}\
static           uint64_t T##_AS_UINT64(O *i) {return (uint64_t) i->A;}\
static          uintmax_t T##_AS_UINTMAX(O *i) {return (uintmax_t) i->A;}\
static             wint_t T##_AS_WINT(O *i) {return (wint_t) i->A;}\
static union unsys_as T##_AS = {\
    .list = {\
        [AS_ADDR]   = T##_AS_ADDR,\
        [AS_ADDRPTR]= T##_AS_ADDRPTR,\
        [AS_CHAR]   = T##_AS_CHAR,\
        [AS_WCHAR]  = T##_AS_WCHAR,\
        [AS_CHAR16] = T##_AS_CHAR16,\
        [AS_CHAR32] = T##_AS_CHAR32,\
        [AS_FLT]    = T##_AS_FLT,\
        [AS_DBL]    = T##_AS_DBL,\
        [AS_LDBL]   = T##_AS_LDBL,\
        [AS_SCHAR]  = T##_AS_SCHAR,\
        [AS_SHRT]   = T##_AS_SHRT,\
        [AS_INT]    = T##_AS_INT,\
        [AS_LONG]   = T##_AS_LONG,\
        [AS_LLONG]  = T##_AS_LLONG,\
        [AS_SSIZE]  = T##_AS_SSIZE,\
        [AS_INTPTR] = T##_AS_INTPTR,\
        [AS_PTRDIFF]= T##_AS_PTRDIFF,\
        [AS_INT8]   = T##_AS_INT8,\
        [AS_INT16]  = T##_AS_INT16,\
        [AS_INT32]  = T##_AS_INT32,\
        [AS_INT64]  = T##_AS_INT64,\
        [AS_INTMAX] = T##_AS_INTMAX,\
        [AS_BOOL]   = T##_AS_BOOL,\
        [AS_UCHAR]  = T##_AS_UCHAR,\
        [AS_USHRT]  = T##_AS_USHRT,\
        [AS_UINT]   = T##_AS_UINT,\
        [AS_ULONG]  = T##_AS_ULONG,\
        [AS_ULLONG] = T##_AS_ULLONG,\
        [AS_SIZE]   = T##_AS_SIZE,\
        [AS_UINTPTR]= T##_AS_UINTPTR,\
        [AS_UINT8]  = T##_AS_UINT8,\
        [AS_UINT16] = T##_AS_UINT16,\
        [AS_UINT32] = T##_AS_UINT32,\
        [AS_UINT64] = T##_AS_UINT64,\
        [AS_UINTMAX]= T##_AS_UINTMAX,\
        [AS_WINT]   = T##_AS_WINT,\
        [AS_BIGINT] = T##_AS_BIGINT\
    }}

UnInteger_CONV_SUITE(UnSchar,   UnChar,     sval);
UnInteger_CONV_SUITE(UnShort,   UnShort,    sval);
UnInteger_CONV_SUITE(UnInt,     UnInt,      sval);
UnInteger_CONV_SUITE(UnLong,    UnLong,     sval);
UnInteger_CONV_SUITE(UnLlong,   UnLlong,    sval);

UnInteger_CONV_SUITE(UnBool,    UnBool,     yval);

UnInteger_CONV_SUITE(UnUchar,   UnChar,     uval);
UnInteger_CONV_SUITE(UnUshort,  UnShort,    uval);
UnInteger_CONV_SUITE(UnUint,    UnInt,      uval);
UnInteger_CONV_SUITE(UnUlong,   UnLong,     uval);
UnInteger_CONV_SUITE(UnUllong,  UnLlong,    uval);


static char
    (*UnFloat_AS_CHAR)(UnFloat *)       = NULL,
    (*UnDouble_AS_CHAR)(UnDouble *)     = NULL,
    (*UnLdouble_AS_CHAR)(UnDouble *)    = NULL;

static wchar_t
    (*UnFloat_AS_WCHAR)(UnFloat *)      = NULL,
    (*UnDouble_AS_WCHAR)(UnDouble *)    = NULL,
    (*UnLdouble_AS_WCHAR)(UnLdouble *)   = NULL;

static char16_t
    (*UnFloat_AS_CHAR16)(UnFloat *)     = NULL,
    (*UnDouble_AS_CHAR16)(UnDouble *)   = NULL,
    (*UnLdouble_AS_CHAR16)(UnLdouble *)  = NULL;

static char32_t
    (*UnFloat_AS_CHAR32)(UnFloat *)     = NULL,
    (*UnDouble_AS_CHAR32)(UnDouble *)   = NULL,
    (*UnLdouble_AS_CHAR32)(UnLdouble *)  = NULL;
/*

static void * UnShort_AS_ADDR(UnShort *o) {
    return (void *) (intptr_t) o->sval;
}
static void **UnShort_AS_ADDRPTR(UnShort *o) {
    return (void **) (intptr_t) o->sval;
}

static void * UnInt_AS_ADDR(UnInt *o) {
    return (void *) (intptr_t) o->sval;
}
static void **UnInt_AS_ADDRPTR(UnInt *o) {
    return (void **) (intptr_t) o->sval;
}

static void *UnLong_AS_ADDR(UnLong *o) {
    return (void *) (intptr_t) o->sval;
}
static void **UnLong_AS_ADDRPTR(UnLong *o) {
    return (void **) (intptr_t) o->sval;
}

static void *UnLlong_AS_ADDR(UnLlong *o) {
    return (void *) (intptr_t) o->sval;
}
static void **UnLlong_AS_ADDRPTR(UnLlong *o) {
    return (void **) (intptr_t) o->sval;
}

static void *UnBool_AS_ADDR(UnBool *o) {
    return (void *) (uintptr_t) o->uval;
}
static void **UnBool_AS_ADDRPTR(UnBool *o) {
    return (void **) (uintptr_t) o->uval;
}
static void *UnUchar_AS_ADDR(UnChar *o) {
    return (void *) (uintptr_t) o->uval;
}
static void **UnUchar_AS_ADDRPTR(UnChar *o) {
    return (void **) (uintptr_t) o->uval;
}

static void *UnUshort_AS_ADDR(UnShort *o) {
    return (void *) (uintptr_t) o->uval;
}
static void **UnUshort_AS_ADDRPTR(UnShort *o) {
    return (void **) (uintptr_t) o->uval;
}

static void *UnUint_AS_ADDR(UnInt *o) {
    return (void *) (uintptr_t) o->uval;
}
static void **UnUint_AS_ADDRPTR(UnInt *o) {
    return (void **) (uintptr_t) o->uval;
}

static void *UnUlong_AS_ADDR(UnLong *o) {
    return (void *) (uintptr_t) o->uval;
}
static void **UnUlong_AS_ADDRPTR(UnLong *o) {
    return (void **) (uintptr_t) o->uval;
}

static void *UnUllong_AS_ADDR(UnLlong *o) {
    return (void *) (uintptr_t) o->uval;
}

static void **UnUllong_AS_ADDRPTR(UnLlong *o) {
    return (void **) (uintptr_t) o->uval;
}
*/

/*
unsys_SSUITE_DEF(UnSchar,       UnChar)
unsys_SSUITE_DEF(UnShort,       UnShort)
unsys_SSUITE_DEF(UnInt,         UnInt)
unsys_SSUITE_DEF(UnLong,        UnLong)
unsys_SSUITE_DEF(UnLlong,       UnLong)

unsys_USUITE_DEF(UnBool,        UnBool)
unsys_USUITE_DEF(UnUchar,       UnChar)
unsys_USUITE_DEF(UnUshort,      UnShort)
unsys_USUITE_DEF(UnUint,        UnInt)
unsys_USUITE_DEF(UnUlong,       UnLong)
unsys_USUITE_DEF(UnUllong,      UnLlong)
*/
unsys_FSUITE_DEF(UnFloat)
unsys_FSUITE_DEF(UnDouble)
unsys_FSUITE_DEF(UnLdouble)

unsys_ASTAB_FLT(UnFloat);
unsys_ASTAB_FLT(UnDouble);
unsys_ASTAB_FLT(UnLdouble);

#define UnReal_RD(UP, lo) static inline PyObject *\
UnReal_FROM_##UP##_DATA(PyTypeObject *, const lo *)
UnReal_RD(BOOL, _Bool);
UnReal_RD(SCHAR, signed char);
UnReal_RD(SHRT, short);
UnReal_RD(INT, int);
UnReal_RD(LONG, long);
UnReal_RD(LLONG, long long);
UnReal_RD(UCHAR, unsigned char);
UnReal_RD(USHRT, unsigned short);
UnReal_RD(UINT, unsigned int);
UnReal_RD(ULONG, unsigned long);
UnReal_RD(ULLONG, unsigned long long);
UnReal_RD(FLT, float);
UnReal_RD(DBL, double);
UnReal_RD(LDBL, long double);

static inline PyObject *
UnReal_FROM_CHAR_DATA(PyTypeObject *c, const unsys_t *as, const void *src) {
    if (as->t_signedness == NB_SIGNED) {
        return UnReal_FROM_SCHAR_DATA(c, src);
    }
    else {
        return UnReal_FROM_UCHAR_DATA(c, src);
    }
}

#define UnReal_FROM_WHAT(dtype) dtype v = *src;\
    switch (TypeAttrDict_GET(c)->info->t_as) {\
        case AS_BOOL:   return    UnBool_NEW(c, (_Bool) v);\
        case AS_WINT:   return    UnWint_NEW(c, (wint_t) v);\
        case AS_SCHAR:  return   UnSchar_NEW(c,   (signed char) v);\
        case AS_UCHAR:  return   UnUchar_NEW(c, (unsigned char) v);\
        case AS_SHRT:   return   UnShort_NEW(c,   (signed short) v);\
        case AS_USHRT:  return  UnUshort_NEW(c, (unsigned short) v);\
        case AS_INT:    return     UnInt_NEW(c,   (signed int) v);\
        case AS_UINT:   return    UnUint_NEW(c, (unsigned int) v);\
        case AS_LONG:   return    UnLong_NEW(c,   (signed long) v);\
        case AS_ULONG:  return   UnUlong_NEW(c, (unsigned long) v);\
        case AS_LLONG:  return   UnLlong_NEW(c,   (signed long long) v);\
        case AS_ULLONG: return  UnUllong_NEW(c, (unsigned long long) v);\
        case AS_SSIZE:  return   UnSsize_NEW(c, (ssize_t) v);\
        case AS_SIZE:   return    UnSize_NEW(c,  (size_t) v);\
        case AS_PTRDIFF:return UnPtrdiff_NEW(c, (ptrdiff_t) v);\
        case AS_INTPTR: return  UnIntptr_NEW(c,  (intptr_t) v);\
        case AS_UINTPTR:return UnUintptr_NEW(c, (uintptr_t) v);\
        case AS_INT8:   return    UnInt8_NEW(c,  (int8_t) v);\
        case AS_UINT8:  return   UnUint8_NEW(c, (uint8_t) v);\
        case AS_INT16:  return   UnInt16_NEW(c,  (int16_t) v);\
        case AS_UINT16: return  UnUint16_NEW(c, (uint16_t) v);\
        case AS_INT32:  return   UnInt32_NEW(c,  (int32_t) v);\
        case AS_UINT32: return  UnUint32_NEW(c, (uint32_t) v);\
        case AS_INT64:  return   UnInt64_NEW(c,  (int64_t) v);\
        case AS_UINT64: return  UnUint64_NEW(c, (uint64_t) v);\
        case AS_INTMAX: return  UnIntmax_NEW(c,  (intmax_t) v);\
        case AS_UINTMAX:return UnUintmax_NEW(c, (uintmax_t) v);\
        case AS_FLT:    return   UnFloat_NEW(c, (float) v);\
        case AS_DBL:    return  UnDouble_NEW(c,      (double) v);\
        case AS_LDBL:   return UnLdouble_NEW(c, (long double) v);\
        default: Py_UNREACHABLE();\
    }
    
static inline PyObject *
UnReal_FROM_BOOL_DATA(PyTypeObject *c, const _Bool *src) {
    UnReal_FROM_WHAT(_Bool)
}

static inline PyObject *
UnReal_FROM_SCHAR_DATA(PyTypeObject *c, const signed char *src) {
    UnReal_FROM_WHAT(signed char)
}

static inline PyObject *
UnReal_FROM_SHRT_DATA(PyTypeObject *c, const short *src) {
    UnReal_FROM_WHAT(short)
}

static inline PyObject *
UnReal_FROM_INT_DATA(PyTypeObject *c, const int *src) {
    UnReal_FROM_WHAT(int)
}

static inline PyObject *
UnReal_FROM_LONG_DATA(PyTypeObject *c, const long *src) {
    UnReal_FROM_WHAT(long)
}

static inline PyObject *
UnReal_FROM_LLONG_DATA(PyTypeObject *c, const long long *src) {
    UnReal_FROM_WHAT(long long)
    /*
    long long v = *src;
    switch (TypeAttrDict_GET(c)->info->t_as) {
        case AS_BOOL:   return    UnBool_NEW(c, (_Bool)                 v);
        case AS_SCHAR:  return   UnSchar_NEW(c, (signed char)           v);
        case AS_SHRT:   return   UnShort_NEW(c, (short)                 v);
        case AS_INT:    return     UnInt_NEW(c, (int)                   v);
        case AS_LONG:   return    UnLong_NEW(c, (long)                  v);
        case AS_LLONG:  return   UnLlong_NEW(c, (ssize_t)               v);
        case AS_SSIZE:  return   UnSsize_NEW(c, (ssize_t)               v);
        case AS_INTPTR: return  UnIntptr_NEW(c, (intptr_t)              v);
        case AS_PTRDIFF:return UnPtrdiff_NEW(c, (ptrdiff_t)             v);
        case AS_INT8:   return    UnInt8_NEW(c, (int8_t)                v);
        case AS_INT16:  return   UnInt16_NEW(c, (int16_t)               v);
        case AS_INT32:  return   UnInt32_NEW(c, (int32_t)               v);
        case AS_INT64:  return   UnInt64_NEW(c, (int64_t)               v);
        case AS_INTMAX: return  UnIntmax_NEW(c, (intmax_t)              v);
        case AS_UCHAR:  return   UnUchar_NEW(c, (unsigned char)         v);
        case AS_USHRT:  return  UnUshort_NEW(c, (unsigned short)        v);
        case AS_UINT:   return    UnUint_NEW(c, (unsigned int)          v);
        case AS_ULONG:  return   UnUlong_NEW(c, (unsigned long)         v);
        case AS_ULLONG: return  UnUllong_NEW(c, (unsigned long long)    v);
        case AS_SIZE:   return    UnSize_NEW(c, (size_t)                v);
        case AS_UINTPTR:return UnUintptr_NEW(c, (uintptr_t)             v);
        case AS_UINT8:  return   UnUint8_NEW(c, (uint8_t)               v);
        case AS_UINT16: return  UnUint16_NEW(c, (uint16_t)              v);
        case AS_UINT32: return  UnUint32_NEW(c, (uint32_t)              v);
        case AS_UINT64: return  UnUint64_NEW(c, (uint64_t)              v);
        case AS_UINTMAX:return UnUintmax_NEW(c, (uintmax_t)             v);
        case AS_FLT:    return   UnFloat_NEW(c, (float)                 v);
        case AS_DBL:    return  UnDouble_NEW(c, (double)                v);
        default: Py_UNREACHABLE();
    }
    */
}

static inline PyObject *
UnReal_FROM_UCHAR_DATA(PyTypeObject *c, const unsigned char *src) {
    UnReal_FROM_WHAT(unsigned char)
    /*
    signed char v = *src;
    switch (TypeAttrDict_GET(c)->info->t_as) {
        case AS_BOOL:   return    UnBool_NEW(c, v);
        case AS_SCHAR:  return   UnSchar_NEW(c, (signed char) v);
        case AS_SHRT:   return   UnShort_NEW(c, (short) v);
        case AS_INT:    return     UnInt_NEW(c, (int) v);
        case AS_LONG:   return    UnLong_NEW(c, (long) v);
        case AS_LLONG:  return   UnLlong_NEW(c, (ssize_t) v);
        case AS_SSIZE:  return   UnSsize_NEW(c, (ssize_t) v);
        case AS_INTPTR: return  UnIntptr_NEW(c, (intptr_t) v);
        case AS_PTRDIFF:return UnPtrdiff_NEW(c, (ptrdiff_t) v);
        case AS_INT8:   return    UnInt8_NEW(c, (int8_t) v);
        case AS_INT16:  return   UnInt16_NEW(c, (int16_t) v);
        case AS_INT32:  return   UnInt32_NEW(c, (int32_t) v);
        case AS_INT64:  return   UnInt64_NEW(c, (int64_t) v);
        case AS_INTMAX: return  UnIntmax_NEW(c, (intmax_t) v);
        case AS_UCHAR:  return   UnUchar_NEW(c, (unsigned char) v);
        case AS_USHRT:  return  UnUshort_NEW(c, (unsigned short) v);
        case AS_UINT:   return    UnUint_NEW(c, (unsigned int) v);
        case AS_ULONG:  return   UnUlong_NEW(c, (unsigned long) v);
        case AS_ULLONG: return  UnUllong_NEW(c, (unsigned long long) v);
        case AS_SIZE:   return    UnSize_NEW(c, (size_t) v);
        case AS_UINTPTR:return UnUintptr_NEW(c, (uintptr_t) v);
        case AS_UINT8:  return   UnUint8_NEW(c, (uint8_t) v);
        case AS_UINT16: return  UnUint16_NEW(c, (uint16_t) v);
        case AS_UINT32: return  UnUint32_NEW(c, (uint32_t) v);
        case AS_UINT64: return  UnUint64_NEW(c, (uint64_t) v);
        case AS_UINTMAX:return UnUintmax_NEW(c, (uintmax_t) v);
        case AS_FLT:    return   UnFloat_NEW(c, (float) v);
        case AS_DBL:    return  UnDouble_NEW(c, (double) v);
        default: Py_UNREACHABLE();
    }
    */
}

static inline PyObject *
UnReal_FROM_USHRT_DATA(PyTypeObject *c, const unsigned short *src) {
    UnReal_FROM_WHAT(unsigned short)
}

static inline PyObject *
UnReal_FROM_UINT_DATA(PyTypeObject *c, const unsigned int *src) {
    UnReal_FROM_WHAT(unsigned int)
}

static inline PyObject *
UnReal_FROM_ULONG_DATA(PyTypeObject *c, const unsigned long *src) {
    UnReal_FROM_WHAT(unsigned long)
}

static inline PyObject *
UnReal_FROM_ULLONG_DATA(PyTypeObject *c, const unsigned long long *src) {
    UnReal_FROM_WHAT(unsigned long long)
}

static inline PyObject *
UnReal_FROM_FLT_DATA(PyTypeObject *c, const float *src) {
    UnReal_FROM_WHAT(float)
}

static inline PyObject *
UnReal_FROM_DBL_DATA(PyTypeObject *c, const double *src) {
    UnReal_FROM_WHAT(double)
}

static inline PyObject *
UnReal_FROM_LDBL_DATA(PyTypeObject *c, const long double *src) {
    UnReal_FROM_WHAT(long double)
}

static inline PyObject *
UnReal_FROM_SIGNED_DATA(PyTypeObject *c, const int rank, const void *src) {
    switch (rank) {
        case BOOL_RANK: return UnReal_FROM_BOOL_DATA(c, src);
        case CHAR_RANK: return UnReal_FROM_SCHAR_DATA(c, src);
        case SHRT_RANK: return UnReal_FROM_SHRT_DATA(c, src);
        case INT_RANK:  return UnReal_FROM_INT_DATA(c, src);
        case LONG_RANK: return UnReal_FROM_LONG_DATA(c, src);
        case LLONG_RANK:return UnReal_FROM_LLONG_DATA(c, src);
        default: Py_UNREACHABLE();
    }
}

static inline PyObject *
UnReal_FROM_UNSIGNED_DATA(PyTypeObject *c, const int rank, const void *src) {
    switch (rank) {
        case BOOL_RANK: return UnReal_FROM_BOOL_DATA(c, src);
        case CHAR_RANK: return UnReal_FROM_UCHAR_DATA(c, src);
        case SHRT_RANK: return UnReal_FROM_USHRT_DATA(c, src);
        case INT_RANK:  return UnReal_FROM_UINT_DATA(c, src);
        case LONG_RANK: return UnReal_FROM_ULONG_DATA(c, src);
        case LLONG_RANK:return UnReal_FROM_ULLONG_DATA(c, src);
        default: Py_UNREACHABLE();
    }
}

static inline PyObject *
UnReal_FROM_FLOATING_DATA(PyTypeObject *c, const int rank, const void *src) {
    switch (rank) {
        case  FLT_RANK: return UnReal_FROM_FLT_DATA(c, src);
        case  DBL_RANK: return UnReal_FROM_DBL_DATA(c, src);
        case LDBL_RANK: return UnReal_FROM_LDBL_DATA(c, src);
        default: Py_UNREACHABLE();
    }
}
    
static inline PyObject *
UnReal_FROM_DATA(PyTypeObject *c, const unsys_t *as, const void *src) {
    if (as->t_signedness == NB_SIGNED) {
        return UnReal_FROM_SIGNED_DATA(c, as->t_rank, src);
    }
    if (as->t_rank >= FLT_RANK) {
        return UnReal_FROM_FLOATING_DATA(c, as->t_rank, src);
    }
    return UnReal_FROM_UNSIGNED_DATA(c, as->t_rank, src);
}

static inline PyObject *
UnReal_FROM_CHAR16(PyTypeObject *cls, char16_t chr, const int tag) {
    Py_RETURN_NOTIMPLEMENTED;
}

static inline PyObject *
UnReal_FROM_CHAR32(PyTypeObject *cls, char32_t chr, const int tag) {
    Py_RETURN_NOTIMPLEMENTED;
}

static inline PyObject *
UnReal_FROM_PYBYTE(PyTypeObject *cls, PyObject *obj) {
    if (!pybytes_IS_BYTE(obj)) {
        return pybytes_ERR_NOT_BYTE();
    }
    return UnReal_FROM_DATA(cls, unsys_ctypes+AS_UCHAR, pybytes_DATA(obj));
}
 
static inline PyObject *
UnReal_FROM_BIGINT(PyTypeObject *c, PyObject *o) {
    switch (TypeAttrDict_GET(c)->info->t_as) {
        case AS_BOOL:   return UnBool_NEW(c, pylong_BOOL(o));
        case AS_WINT:   return UnWint_NEW(c, pylong_WINT(o));
        case AS_SCHAR:  return UnSchar_NEW(c, pylong_SCHAR(o));
        case AS_SHRT:   return UnShort_NEW(c, pylong_SHRT(o));
        case AS_INT:    return UnInt_NEW(c, pylong_INT(o));
        case AS_LONG:   return UnLong_NEW(c, pylong_LONG(o));
        case AS_LLONG:  return UnLlong_NEW(c, pylong_LLONG(o));
        case AS_SSIZE:  return UnSsize_NEW(c, pylong_SSIZE(o));
        case AS_INTPTR: return UnIntptr_NEW(c, pylong_INTPTR(o));
        case AS_PTRDIFF:return UnPtrdiff_NEW(c, pylong_PTRDIFF(o));
        case AS_INT8:   return UnInt8_NEW(c, pylong_INT8(o));
        case AS_INT16:  return UnInt16_NEW(c, pylong_INT16(o));
        case AS_INT32:  return UnInt32_NEW(c, pylong_INT32(o));
        case AS_INT64:  return UnInt64_NEW(c, pylong_INT64(o));
        case AS_INTMAX: return UnIntmax_NEW(c, pylong_INTMAX(o));
        case AS_UCHAR:  return UnUchar_NEW(c, pylong_UCHAR(o));
        case AS_USHRT:  return UnUshort_NEW(c,  pylong_USHRT(o));
        case AS_UINT:   return UnUint_NEW(c, pylong_UINT(o));
        case AS_ULONG:  return UnUlong_NEW(c, pylong_ULONG(o));
        case AS_ULLONG: return UnUllong_NEW(c, pylong_ULLONG(o));
        case AS_SIZE:   return UnSize_NEW(c, pylong_SIZE(o));
        case AS_UINTPTR:return UnUintptr_NEW(c, pylong_UINTPTR(o));
        case AS_UINT8:  return UnUint8_NEW(c, pylong_UINT8(o));
        case AS_UINT16: return UnUint16_NEW(c, pylong_UINT16(o));
        case AS_UINT32: return UnUint16_NEW(c, pylong_UINT32(o));
        case AS_UINT64: return UnUint64_NEW(c, pylong_UINT64(o));
        case AS_UINTMAX:return UnUintmax_NEW(c, pylong_UINTMAX(o));
        case AS_FLT:    return UnFloat_NEW(c, pylong_FLT(o));
        case AS_DBL:    return UnDouble_NEW(c, pylong_DBL(o));
        case AS_LDBL:   return UnDouble_NEW(c, pylong_LDBL(o));
        default: Py_UNREACHABLE();
    }
}

static inline int
int_FROM_PYBYTE(PyObject *obj) {
    if (!pybytes_IS_BYTE(obj)) {
        return 0-1;
    }
    return pybyte_INT(obj);
}

static inline int
int_FROM_PYCHAR(PyObject *obj) {
    if (PyUnicode_GET_LENGTH(obj) != 1) {
        return 0-1;
    }
    switch (PyUnicode_KIND(obj)) {
        case PyUnicode_1BYTE_KIND: {
            return (int) *PyUnicode_1BYTE_DATA(obj);
        }
        case PyUnicode_2BYTE_KIND: {
            return (int) *PyUnicode_2BYTE_DATA(obj);
        }
        case PyUnicode_4BYTE_KIND: {
            return (int) *PyUnicode_4BYTE_DATA(obj);
        }
        default: {
            Py_UNREACHABLE();
        }
    }
}

static inline int
bool_FROM_NUMBER(PyObject *obj, _Bool *v) {
    if (Py_TYPE(Py_TYPE(obj)->tp_dict) == &TypeAttrDict_Type) {
        return (*v=UnC_GET_CONV((UnChar *) obj)->as_bool(obj)), 0;
    }
    unsigned long flags = 0xFF000000UL&Py_TYPE(obj)->tp_flags;
    switch (flags) {
        case 0: break;
        case Py_TPFLAGS_LONG_SUBCLASS: {
            return (*v=Py_SIZE(obj)), 0;
        }
        case Py_TPFLAGS_BYTES_SUBCLASS: {
            if (!pybytes_IS_BYTE(obj)) {
                return pybytes_ERR_NOT_BYTE(), (0-1);
            }
            return (*v=pybyte_BOOL(obj)), 0;
        }
        case Py_TPFLAGS_UNICODE_SUBCLASS: {
            int c = int_FROM_PYCHAR(obj);
            if (c < 0) {
                return pyunicode_ERR_NOT_CHAR(), (0-1);
            }
            return (*v=c), 0;
        }
        default: not_number: {
            return py_ERR_NOT_A_NUMBER(obj), (0-1);
        }
    }
    if (Py_TYPE(obj) == &PyFloat_Type) {
        return (*v=PyFloat_AsDouble(obj)), 0;
    }
    PyNumberMethods *ml = py_AS_NUMBER(obj);
    if (ml == NULL) {
        goto not_number;
    }
    if (ml->nb_bool != NULL) {
        *v = ml->nb_bool(obj);
        return PyErr_Occurred() ? (0-1) : 0;
    }
    if (ml->nb_index != NULL) {
        obj = ml->nb_index(obj);
        if (obj == NULL) {
            return 0-1;
        }
        *v = Py_SIZE(obj);
        Py_DECREF(obj);
        return 0;
    }
    if (ml->nb_float == NULL) {
        return py_ERR_NOT_A_NUMBER(obj), (0-1);
    }
    obj = ml->nb_float(obj);
    if (obj == NULL) {
        return 0-1;
    }
    return (*v=PyFloat_AsDouble(obj)), 0;
}

static inline int 
UnSchar_INDEX(PyObject *obj, Py_ssize_t *index) {
    *index = UnSchar_GET(obj);
    return 0;
}

static inline int 
UnShort_INDEX(PyObject *obj, Py_ssize_t *index) {
    *index = UnShort_GET(obj);
    return 0;
}

static inline int 
UnInt_INDEX(PyObject *obj, Py_ssize_t *index) {
#   if INT_MAX <= SSIZE_MAX
    return (*index=UnInt_GET(obj), 0);
#   else
    const int v = UnInt_GET(obj);
    if ((v > SSIZE_MAX) || (v < (0-SSIZE_MAX))) {
        return 0-1;
    }
    return (*index=(Py_ssize_t) v), 0;
#   endif
}

static inline int 
UnLong_INDEX(PyObject *obj, Py_ssize_t *index) {
#   if LONG_MAX <= SSIZE_MAX
    return (*index=UnLong_GET(obj), 0);
#   else
    const long v = UnLong_GET(obj);
    if ((v > SSIZE_MAX) || (v < (0-SSIZE_MAX))) {
        return 0-1;
    }
    return (*index=(Py_ssize_t) v), 0;
#   endif
}

static inline int 
UnLlong_INDEX(PyObject *obj, Py_ssize_t *index) {
#   if LLONG_MAX <= SSIZE_MAX
    return (*index=UnLlong_GET(obj), 0);
#   else
    const long long v = UnLlong_GET(obj);
    if ((v > SSIZE_MAX) || (v < (0-SSIZE_MAX))) {
        return 0-1;
    }
    return (*index=(Py_ssize_t) v), 0;
#   endif
}

static inline int
UnBool_INDEX(PyObject *obj, Py_ssize_t *index) {
    *index = UnBool_GET(obj);
    return 0;
}

static inline int
UnUchar_INDEX(PyObject *obj, Py_ssize_t *index) {
    *index = UnUchar_GET(obj);
    return 0;
}

static inline int 
UnUshort_INDEX(PyObject *obj, Py_ssize_t *index) {
#   if USHRT_MAX < SSIZE_MAX
    return (*index=UnUshort_GET(obj)), 0;
#   else 
    const unsigned short v = UnUshort_GET(obj);
    if (v > SSIZE_MAX) {
        return 0-1;
    }
    return (*index=(Py_ssize_t) v), 0;
#   endif
}

static inline int 
UnUint_INDEX(PyObject *obj, Py_ssize_t *index) {
#   if UINT_MAX < SSIZE_MAX
    return (*index=UnUint_GET(obj)), 0;
#   else 
    const unsigned int v = UnUint_GET(obj);
    if (v > SSIZE_MAX) {
        return 0-1;
    }
    return (*index=(Py_ssize_t) v), 0;
#   endif
}

static inline int 
UnUlong_INDEX(PyObject *obj, Py_ssize_t *index) {
    const unsigned long v = UnUlong_GET(obj);
    if (v > SSIZE_MAX) {
        return 0-1;
    }
    return (*index=(Py_ssize_t) v), 0;
}

static inline int 
UnUllong_INDEX(PyObject *obj, Py_ssize_t *index) {
    const unsigned long long v = UnUllong_GET(obj);
    if (v > SSIZE_MAX) {
        return 0-1;
    }
    return (*index=(Py_ssize_t) v), 0;
}

static inline int 
UnFloat_INDEX(PyObject *obj, Py_ssize_t *index) {
    float v = UnFloat_GET(obj);
    if (modff(UnFloat_GET(obj), &v)) {
        return 0-1;
    }
#   if SSIZE_MAX > 0xffffff
    if ((-16777216.f > v) || (v > +16777216.f)) {
        return 0-1;
    }
#   else
    if (((0-SSIZE_MAX) > v) || (v > SSIZE_MAX)) {
        return 0-1;
    }
#   endif
    *index = (Py_ssize_t) v;
    return 0;
}

static inline int 
UnDouble_INDEX(PyObject *obj, Py_ssize_t *index) {
    double v = UnDouble_GET(obj);
    if (modf(UnDouble_GET(obj), &v)) {
        return 0-1;
    }
#   if SSIZE_MAX > INTMAX_C(9007199254740992)
    if ((-9007199254740992.0 > v) || (v > +9007199254740992.0)) {
        return 0-1;
    }
#   else
    if (((0-SSIZE_MAX) > v) || (v > SSIZE_MAX)) {
        return 0-1;
    }
#   endif
    *index = (Py_ssize_t) v;
    return 0;
}

static inline int 
UnLdouble_INDEX(PyObject *obj, Py_ssize_t *index) {
    long double v = UnDouble_GET(obj);
    if (modfl(UnLdouble_GET(obj), &v)) {
        return 0-1;
    }
#if LDBL_MANT_DIGIT > 64
    if (((0-SSIZE_MAX) > v) || (v > SSIZE_MAX)) {
        return 0-1;
    }
#elif SSIZE_MAX > INTMAX_C(9007199254740992)
    if ((-9007199254740992.l > v) || (v > +9007199254740992.l)) {
        return 0-1;
    }
#else
    if (((0-SSIZE_MAX) > v) || (v > SSIZE_MAX)) {
        return 0-1;
    }
#endif
    *index = (Py_ssize_t) v;
    return 0;
}

static inline int
UnSigned_INDEX(PyObject *obj, Py_ssize_t *index) {
    switch (UnC_GET_RANK((UnChar *) obj)) {
        case  BOOL_RANK: return UnBool_INDEX(obj, index);
        case  CHAR_RANK:return UnSchar_INDEX(obj, index);
        case  SHRT_RANK:return UnShort_INDEX(obj, index);
        case   INT_RANK:return   UnInt_INDEX(obj, index);
        case  LONG_RANK:return  UnLong_INDEX(obj, index);
        case LLONG_RANK:return UnLlong_INDEX(obj, index);
        default: Py_UNREACHABLE();
    }
}

static inline int
UnUnsigned_INDEX(PyObject *obj, Py_ssize_t *index) {
    switch (UnC_GET_RANK((UnChar *) obj)) {
        case  BOOL_RANK:return   UnBool_INDEX(obj, index);
        case  CHAR_RANK:return  UnUchar_INDEX(obj, index);
        case  SHRT_RANK:return UnUshort_INDEX(obj, index);
        case   INT_RANK:return   UnUint_INDEX(obj, index);
        case  LONG_RANK:return  UnUlong_INDEX(obj, index);
        case LLONG_RANK:return UnUllong_INDEX(obj, index);
        default: Py_UNREACHABLE();
    }
}

static inline int
UnFloating_INDEX(PyObject *obj, Py_ssize_t *index) {
    switch (UnC_GET_RANK((UnChar *) obj)) {
        case FLT_RANK:    return UnFloat_INDEX(obj, index);
        case DBL_RANK:   return UnDouble_INDEX(obj, index);
        case LDBL_RANK: return UnLdouble_INDEX(obj, index);
        default: Py_UNREACHABLE();
    }
}

static inline int
UnReal_INDEX(PyObject *obj, Py_ssize_t *index) {
    UnDouble tmp;
    const char *src;
    if (UnC_IS_DATA_TYPE(obj)) {
        TypeAttrDict *stg = TypeAttrDict_GET(Py_TYPE(obj));
        switch (stg->info->t_signedness) {
            case NB_SIGNED: {
                if (UnSigned_INDEX(obj, index) == (0-1)) {
                    break;
                }
                return 0;
            }
            case NB_UNSIGNED: {
                if (UnUnsigned_INDEX(obj, index) == (0-1)) {
                    break;
                }
                return 0;
            }
            case NB_SIGNLESS: {
                if (UnFloating_INDEX(obj, index) == (0-1)) {
                    break;
                }
                return 0;
            }
            default: Py_UNREACHABLE();
        }
        src = py_TP_NAME(obj);
        cov: {
            (void) 
            py_ERR_WOULD_OVERFLOW("platform C ssize_t", src);
        }
        return 0-1;
    }
    unsigned long flags = 0xFF000000UL&Py_TYPE(obj)->tp_flags;
    switch (flags) {
        case Py_TPFLAGS_LONG_SUBCLASS: {
            return pylong_INDEX(obj, index);
        }
        case Py_TPFLAGS_BYTES_SUBCLASS: {
            if (!pybytes_IS_BYTE(obj)) {
                (void) pybytes_ERR_NOT_BYTE();
                return (0-1);
            }
            *index = pybyte_UCHAR(obj);
            return 0;
        }
        case Py_TPFLAGS_UNICODE_SUBCLASS: {
            int c = int_FROM_PYCHAR(obj);
            if (c < 0) {
                (void) pyunicode_ERR_NOT_CHAR();
                return (0-1);
            }
            *index = c;
            return 0;
        }
    }
    if (Py_TYPE(obj) == &PyFloat_Type) {
        UnDouble_SET(&tmp, PyFloat_AsDouble(obj));
        if (UnDouble_INDEX((PyObject *) &tmp, index) == (0-1)) {
            src = "Python float";
            goto cov;
        }
        return 0;
    }
    PyNumberMethods *ml = py_AS_NUMBER(obj);
    if (ml == NULL) {
        not_number: {
            (void) py_ERR_NOT_A_NUMBER(obj);
            return (0-1);
        }
    }
    if (ml->nb_index != NULL) {
        obj = ml->nb_index(obj);
        if (obj == NULL) {
            return 0-1;
        }
        *index = pylong_SSIZE(obj);
        Py_DECREF(obj);
        return 0;
    }
    if (ml->nb_float == NULL) {
        goto not_number;
    }
    src = py_TP_NAME(obj);
    obj = ml->nb_float(obj);
    if (obj == NULL) {
        return 0-1;
    }
    UnDouble_SET(&tmp, PyFloat_AsDouble(obj));
    Py_DECREF(obj);
    if (UnDouble_INDEX((PyObject *) &tmp, index) == (0-1)) {
        goto cov;
    }
    return 0;
}

static PyObject *
UnReal_index_test(PyObject *mod, PyObject *arg) {
    Py_ssize_t val;
    if (UnReal_INDEX(arg, &val)) {
        return NULL;
    }
    return pylong_FROM_SSIZE(val);
}

static inline PyObject *
UnReal_FROM_PYCHAR(PyTypeObject *cls, PyObject *obj) {
    if (PyUnicode_GET_LENGTH(obj) != 1) {
        return PyErr_Format(
            PyExc_TypeError,
            "%.512s argument can't be interpreted as a real number",
            py_TP_NAME(obj)
        );
    }
    switch (PyUnicode_KIND(obj)) {
        case PyUnicode_1BYTE_KIND: {
            return UnReal_FROM_UCHAR_DATA(
                cls, 
                PyUnicode_1BYTE_DATA(obj)
            );
        }
        case PyUnicode_2BYTE_KIND: {
            return UnReal_FROM_USHRT_DATA(
                cls,
                PyUnicode_2BYTE_DATA(obj)
            );
        }
        case PyUnicode_4BYTE_KIND: {
            return UnReal_FROM_UINT_DATA(
                cls,
                PyUnicode_4BYTE_DATA(obj)
            );
        }
        default: {
            Py_UNREACHABLE();
        }
    }
}

static inline PyObject *
UnReal_FROM_NUMBER(PyTypeObject *cls, PyObject *obj) {
    TypeAttrDict *stg = TypeAttrDict_GET(cls);
    unsigned long flags = 0xFF000000UL&Py_TYPE(obj)->tp_flags;
    switch (flags) {
        case Py_TPFLAGS_LONG_SUBCLASS: {
            return UnReal_FROM_BIGINT(cls, obj);
        }
        case Py_TPFLAGS_BYTES_SUBCLASS: {
            return UnReal_FROM_PYBYTE(cls, obj);
        }
        case Py_TPFLAGS_UNICODE_SUBCLASS: {
            return UnReal_FROM_PYCHAR(cls, obj);
        }
        case 0: {
            break;
        }
        default: cant_cast: { 
            return PyErr_Format(
                PyExc_TypeError,
                "can't create %.512s from %.512s object",
                cls->tp_name,
                py_TP_NAME(obj)
            );
        }
    }
    PyObject *num;
    if (Py_TYPE(obj) == &PyFloat_Type) {
        num = Py_NewRef(obj);
    }
    else {
        PyNumberMethods *ml = py_AS_NUMBER(obj);
        if (ml == NULL) {
            return py_ERR_NOT_A_NUMBER(obj);
        }
        if (ml->nb_index != NULL) {
            num = ml->nb_index(obj);
            if (num == NULL) {
                return NULL;
            }
            obj = UnReal_FROM_BIGINT(cls, num);
            Py_DECREF(num);
            return obj;
        }
        if (ml->nb_float == NULL) {
            return py_ERR_NOT_A_NUMBER(obj);
        }
        num = ml->nb_float(obj);
        if (num == NULL) {
            return NULL;
        }
    }
    double val = PyFloat_AsDouble(num);
    Py_DECREF(num);
    return UnReal_FROM_DBL_DATA(cls, &val);
}

static inline void
UnReal_ZERO(UnChar *obj) {
    switch (UnC_GET_RANK(obj)) {
        case  BOOL_RANK:    UnBool_SET(obj, 0); break;
        case  CHAR_RANK:   UnUchar_SET(obj, 0); break;
        case  SHRT_RANK:  UnUshort_SET(obj, 0); break;
        case   INT_RANK:    UnUint_SET(obj, 0); break;
        case  LONG_RANK:   UnUlong_SET(obj, 0); break;
        case LLONG_RANK:  UnUllong_SET(obj, 0); break;
        case   FLT_RANK:   UnFloat_SET(obj, 0); break;
        case   DBL_RANK:  UnDouble_SET(obj, 0); break;
        case  LDBL_RANK: UnLdouble_SET(obj, 0); break;
        default: Py_UNREACHABLE();
    }
}

/*

UnReal_CAST(cls, obj)

    Construct cls instance from an arbitrary value. Certain 
    Python objects are suitable arguments:

    *   Python's None is equivalent to ((void *) 0). Only 
        intptr_t, uintptr_t, and ptrdiff_t can accept it
        in that capacity.

    [UnReal_FROM_PYCHAR]
    *   A 1 character "str" is interpreted as either a "char",
        "char16_t", or "char32_t", depending on the str's
        representation ("kind")

    [UnReal_FROM_PYBYTE]
    *   A 1 byte "bytes" is interpreted as an "unsigned char"

    [UnReal_FROM_BIGINT]
    *   Python int objects are interpreted as AS_BIGINT

    [UnReal_FROM_NUMBER]
    *   Python float objects (not subtypes) are equivalent
        to "double"
    *   Any object with __index__ is equivalent to "ssize_t"
    *   Any object with __float__ is equivalent to "double"
        Subtypes of float are included in this category.

*/

static inline PyObject *
UnReal_CAST(PyTypeObject *cls, PyObject *obj) {
    PyObject *val;
    TypeAttrDict *dst = TypeAttrDict_GET(cls);
    TypeAttrDict *src = TypeAttrDict_GET(Py_TYPE(obj));
    if (Py_TYPE(src) != &TypeAttrDict_Type) {
        return UnReal_FROM_NUMBER(cls, obj);
    }
    if (src->conv->list[dst->info->t_as] == NULL) {
        return py_ERR_NOT_A_NUMBER(obj);
    }
    return UnReal_FROM_DATA(
        cls, 
        src->info, 
        UnC_GET_DATA((UnChar *) obj)
    );
}

static PyObject *
UnReal_new(PyTypeObject *cls, PyObject *args, PyObject *kwds) {
    struct unsys_arg_chk arg = {
        "Real.__new__",
        UNSYS_PARSE_ARGS("Real.__new__", 0, 1),
    };
    if (arg.seq == NULL) {
        return NULL;
    }
    if (Py_SIZE(args) == 0) {
        UnChar *obj = PyMem_Malloc((size_t) cls->tp_basicsize);
        if (obj == NULL) {
            return NULL;
        }
        Py_INCREF(cls);
        ((PyObject *) obj)->ob_refcnt = 1;
        ((PyObject *) obj)->ob_type = cls;
        UnC_SET_EXPORTS(obj, 0);
        UnReal_ZERO(obj);
        return (PyObject *) obj;
    }
    return UnReal_CAST(cls, *arg.seq);
}

static PyObject *
UnSigned_repr(UnChar *obj) {
    char s[512];
    const char *t = py_TP_NAME((PyObject *) obj);
    int n;
    switch (UnC_GET_RANK(obj)) {
        case CHAR_RANK: {
            n = snprintf(s, sizeof s, "%s(%hhi)", t, UnChar_GET(obj));
            break;
        }
        case SHRT_RANK: {
            n = snprintf(s, sizeof s, "%s(%hi)", t, UnShort_GET(obj));
            break;
        }
        case INT_RANK: {
            n = snprintf(s, sizeof s, "%s(%i)", t, UnInt_GET(obj));
            break;
        }
        case LONG_RANK: {
            n = snprintf(s, sizeof s, "%s(%li)", t, UnLong_GET(obj));
            break;
        }
        case LLONG_RANK: {
            n = snprintf(s, sizeof s, "%s(%lli)", t, UnLlong_GET(obj));
            break;
        }
        default: {
            Py_UNREACHABLE();
        }
    }
    if (n < 0) {
        return unsys_RAISE_FROM_ERRNO();
    }
    return PyUnicode_FromString(s);
}

static PyObject *
UnUnsigned_repr(UnChar *obj) {
    char s[512];
    const char *t = py_TP_NAME((PyObject *) obj);
    int n;
    switch (UnC_GET_RANK(obj)) {
        case BOOL_RANK: {
            if (UnBool_GET(obj)) {
                n = snprintf(s, sizeof s, "%s(True)", t);
            }
            else {
                n = snprintf(s, sizeof s, "%s(True)", t);
            }
             break;   
        }
        case CHAR_RANK: {
            n = snprintf(s, sizeof s, "%s(%hhu)", t, UnUchar_GET(obj));
            break;
        }
        case SHRT_RANK: {
            n = snprintf(s, sizeof s, "%s(%hu)", t, UnUshort_GET(obj));
            break;
        }
        case INT_RANK: {
            n = snprintf(s, sizeof s, "%s(%u)", t, UnUint_GET(obj));
            break;
        }
        case LONG_RANK: {
            n = snprintf(s, sizeof s, "%s(%lu)", t, UnUlong_GET(obj));
            break;
        }
        case LLONG_RANK: {
            n = snprintf(s, sizeof s, "%s(%llu)", t, UnUllong_GET(obj));
            break;
        }
        default: {
            Py_UNREACHABLE();
        }
    }
    if (n < 0) {
        return unsys_RAISE_FROM_ERRNO();
    }
    return PyUnicode_FromString(s);
}

static PyObject *
UnFloating_repr(UnChar *obj) {
    Py_RETURN_NONE;
}

static PyObject *
UnReal_repr(UnChar *obj) {
    char s[512];
    const char *t = py_TP_NAME((PyObject *) obj);
    int n;
    switch (UnC_GET_AS(obj)) {

        case AS_SCHAR: {
            n = snprintf(s, sizeof s, "%s(%hhi)", t, UnChar_GET(obj));
            break;
        }
        case AS_SHRT: {
            n = snprintf(s, sizeof s, "%s(%hi)", t, UnShort_GET(obj));
            break;
        }
        case AS_INT: {
            n = snprintf(s, sizeof s, "%s(%i)", t, UnInt_GET(obj));
            break;
        }
        case AS_LONG: {
            n = snprintf(s, sizeof s, "%s(%li)", t, UnLong_GET(obj));
            break;
        }
        case AS_LLONG: {
            n = snprintf(s, sizeof s, "%s(%lli)", t, UnLlong_GET(obj));
            break;
        }
        case AS_SSIZE: {
            n = snprintf(s, sizeof s, "%s(%zi)", t, UnSsize_GET(obj));
            break;
        }
        case AS_INTPTR: {
            n = snprintf(s, sizeof s,"%s(%" PRIiPTR ")",t, UnIntptr_GET(obj));
            break;
        }
        case AS_PTRDIFF: {
            n = snprintf(s, sizeof s, "%s(%ti)", t, UnPtrdiff_GET(obj));
            break;
        }
        case AS_INT8: {
            n = snprintf(s, sizeof s,"%s(%" PRIi8 ")",t, UnUint8_GET(obj));
            break;
        }
        case AS_INT16: {
            n = snprintf(s, sizeof s,"%s(%" PRIi16 ")",t, UnUint16_GET(obj));
            break;
        }
        case AS_INT32: {
            n = snprintf(s, sizeof s,"%s(%" PRIi32 ")",t, UnUint32_GET(obj));
            break;
        }
        case AS_INT64: {
            n = snprintf(s, sizeof s,"%s(%" PRIi64 ")",t, UnInt64_GET(obj));
            break;
        }
        case AS_INTMAX: {
            n = snprintf(s, sizeof s,"%s(%" PRIiMAX ")",t,UnIntmax_GET(obj));
            break;
        }
        case AS_BOOL: {
            if (UnBool_GET(obj)) {
                n = snprintf(s, sizeof s, "%s(True)", t);
            }
            else {
                n = snprintf(s, sizeof s, "%s(False)", t);
            }
             break;   
        }
        case AS_UCHAR: {
            n = snprintf(s, sizeof s, "%s(%hhu)", t, UnUchar_GET(obj));
            break;
        }
        case AS_USHRT: {
            n = snprintf(s, sizeof s, "%s(%hu)", t, UnUshort_GET(obj));
            break;
        }
        case AS_UINT: {
            n = snprintf(s, sizeof s, "%s(%u)", t, UnUint_GET(obj));
            break;
        }
        case AS_ULONG: {
            n = snprintf(s, sizeof s, "%s(%lu)", t, UnUlong_GET(obj));
            break;
        }
        case AS_ULLONG: {
            n = snprintf(s, sizeof s, "%s(%llu)", t, UnUllong_GET(obj));
            break;
        }
        case AS_SIZE: {
            n = snprintf(s, sizeof s, "%s(%zu)", t, UnSize_GET(obj));
            break;
        }
        case AS_UINTPTR: {
            n = snprintf(s, sizeof s,"%s(%" PRIuPTR ")",t,UnUintptr_GET(obj));
            break;
        }
        case AS_UINT8: {
            n = snprintf(s, sizeof s,"%s(%" PRIu8 ")",t, UnUint8_GET(obj));
            break;
        }
        case AS_UINT16: {
            n = snprintf(s, sizeof s,"%s(%" PRIu16 ")",t, UnUint16_GET(obj));
            break;
        }
        case AS_UINT32: {
            n = snprintf(s, sizeof s,"%s(%" PRIu32 ")",t, UnUint32_GET(obj));
            break;
        }
        case AS_UINT64: {
            n = snprintf(s, sizeof s,"%s(%" PRIu64 ")",t, UnUint64_GET(obj));
            break;
        }
        case AS_UINTMAX: {
            n = snprintf(s, sizeof s,"%s(%" PRIuMAX ")",t,UnUintmax_GET(obj));
            break;
        }
        case AS_FLT: {
            PyObject *tmp = PyFloat_FromDouble(UnFloat_GET(obj));
            if (tmp == NULL) {
                return NULL;
            }
            PyObject *str = PyUnicode_FromFormat("%s(%R)", t, tmp);
            Py_DECREF(tmp);
            return str;
        }
        case AS_DBL: {
            PyObject *tmp = PyFloat_FromDouble(UnDouble_GET(obj));
            if (tmp == NULL) {
                return NULL;
            }
            PyObject *str = PyUnicode_FromFormat("%s(%R)", t, tmp);
            Py_DECREF(tmp);
            return str;
        }
        case AS_LDBL: {
            Py_RETURN_NONE;
        }
        case AS_WINT: {
            n = snprintf(s, sizeof s, "%s(%u)", t, (unsigned) UnWint_GET(obj));
            break;
        }
        default: {
            goto generic;
        }
    }
    if (n < 0) {
        return unsys_RAISE_FROM_ERRNO();
    }
    else {
        return PyUnicode_FromString(s);
    }
    generic:
    switch (UnC_GET_SIGNEDNESS(obj)) {
        case NB_SIGNED:     return UnSigned_repr(obj);
        case NB_UNSIGNED:   return UnUnsigned_repr(obj);
        case NB_SIGNLESS:   switch (UnC_GET_RANK(obj)) {
            case FLT_RANK: 
            case DBL_RANK: 
            case LDBL_RANK: return UnFloating_repr(obj);
        }
    }
    Py_UNREACHABLE();
}

static PyObject *
UnSigned_nb_index(UnChar *obj) {
    ssize_t (*f)(void *) = UnC_GET_CONV(obj)->as_ssize;
    assert(f != NULL);
    return PyLong_FromSsize_t(f(obj));
}

static PyObject *
UnUnsigned_nb_index(UnChar *obj) {
    size_t (*f)(void *) = UnC_GET_CONV(obj)->as_size;
    assert(f != NULL);
    return PyLong_FromSize_t(f(obj));
}

static PyObject *
UnBoolean_nb_index(UnChar *obj) {
    _Bool (*f)(void *) = UnC_GET_CONV(obj)->as_bool;
    assert(f != NULL);
    return pylong_FROM_BOOL(f(obj));
}

static PyObject *
UnReal_nb_float(UnChar *obj) {
    double (*f)(void *) = UnC_GET_CONV(obj)->list[AS_DBL];
    assert(f != NULL);
    return PyFloat_FromDouble(f(obj));
}

static int
UnReal_nb_bool(UnChar *obj) {
    _Bool (*f)(void *) = UnC_GET_CONV(obj)->list[AS_BOOL];
    assert(f != NULL);
    return f(obj);
}

static PyObject *
UnReal_nb_int(UnChar *obj) {
    void * (*f)(void *) = UnC_GET_CONV(obj)->list[AS_BIGINT];
    assert(f != NULL);
    return f(obj);
}

static PyObject *
UnReal_nb_absolute(UnChar *obj) {
    int rank = UnC_GET_RANK(obj);
    int sgn = UnC_GET_SIGNEDNESS(obj);
    if (sgn == NB_UNSIGNED) {

        switch (rank) {

            case BOOL_RANK: {
                return UnUint_NEW(&UnUint_Type, UnBool_GET(obj));
            }

            case CHAR_RANK: {
                return UnUint_NEW(&UnUint_Type, UnUchar_GET(obj));
            }

            case SHRT_RANK: {
                return UnUint_NEW(&UnUint_Type, UnUshort_GET(obj));
            }

            case INT_RANK: {
                return UnUint_NEW(&UnUint_Type, UnUint_GET(obj));
            }

            case LONG_RANK: {
                return UnUlong_NEW(&UnUlong_Type, UnUlong_GET(obj));
            }

            case LLONG_RANK: {
                return UnUllong_NEW(&UnUllong_Type, UnUllong_GET(obj));
            }
            default: {
                Py_UNREACHABLE();
            }
        }
    }

    switch (rank) {

        case CHAR_RANK: {
            return UnInt_NEW(&UnInt_Type, abs((int) UnChar_GET(obj)));
        }

        case SHRT_RANK: {
            return UnInt_NEW(&UnInt_Type, abs(UnShort_GET(obj)));
        }

        case INT_RANK: {
            return UnInt_NEW(&UnInt_Type, abs(UnInt_GET(obj)));
        }

        case LONG_RANK: {
            return UnLong_NEW(&UnLong_Type, labs(UnLong_GET(obj)));
        }

        case LLONG_RANK: {
            return UnLlong_NEW(&UnLlong_Type, llabs(UnLlong_GET(obj)));
        }

        case FLT_RANK: {
            return UnFloat_NEW(&UnFloat_Type, fabsf(UnFloat_GET(obj)));
        }

        case DBL_RANK: {
            return UnFloat_NEW(&UnFloat_Type, fabs(UnDouble_GET(obj)));
        }

        default: {
            Py_UNREACHABLE();
        }
    }
}

static PyObject *
UnReal_nb_positive(UnChar *obj) {
    const int rank = UnC_GET_RANK(obj);
    const int sign = UnC_GET_SIGNEDNESS(obj);
    int v;
    switch (rank) {

        case BOOL_RANK: {
            v = UnBool_GET(obj);
            break;
        }

        case CHAR_RANK: {
            if (sign) {
                v = UnSchar_GET(obj);
            }
            else {
                v = UnSchar_GET(obj);
            }
            break;
        }

        case SHRT_RANK: {
            if (sign) {
                v = UnShort_GET(obj);
            }
            else {
                v = UnUshort_GET(obj);
            }
            break;
        }

        case INT_RANK: {
            if (sign) {
                v = UnInt_GET(obj);
                break;
            }
            return UnUint_NEW(&UnInt_Type, UnUint_GET(obj));
        }

        case LONG_RANK: {
            if (sign) {
                return UnLong_NEW(&UnLong_Type, UnLong_GET(obj));
            }
            return UnUlong_NEW(&UnUlong_Type, UnUlong_GET(obj));
        }

        case LLONG_RANK: {
            if (sign) {
                return UnLlong_NEW(&UnLlong_Type, UnLlong_GET(obj));
            }
            return UnUllong_NEW(&UnUllong_Type, UnUllong_GET(obj));
        }

        case FLT_RANK: {
            return UnFloat_NEW(&UnFloat_Type, UnFloat_GET(obj));
        }

        case DBL_RANK: {
            return UnDouble_NEW(&UnDouble_Type, UnDouble_GET(obj));
        }

        default: {
            Py_UNREACHABLE();
        }
    }
    return UnInt_NEW(&UnInt_Type, v);
}

static PyObject *
UnReal_nb_negative(UnChar *obj) {

    const int rank = UnC_GET_RANK(obj);
    const int sign = UnC_GET_SIGNEDNESS(obj);

    switch (rank) {

        case BOOL_RANK: {
            return UnInt_NEW(&UnInt_Type, -UnBool_GET(obj));
        }

        case CHAR_RANK: {
            if (sign == NB_UNSIGNED) {
                return UnInt_NEW(&UnInt_Type, -UnUchar_GET(obj));
            }
            return UnInt_NEW(&UnInt_Type, -UnSchar_GET(obj));
        }

        case SHRT_RANK: {
            if (sign == NB_UNSIGNED) {
                return UnInt_NEW(&UnInt_Type, -UnUshort_GET(obj));
            }
            return UnInt_NEW(&UnInt_Type, -UnShort_GET(obj));
        }

        case INT_RANK: {
            if (sign == NB_UNSIGNED) {
                return UnUint_NEW(&UnUint_Type, -UnUint_GET(obj));
            }
            return UnInt_NEW(&UnInt_Type, -UnInt_GET(obj));
        }

        case LONG_RANK: {
            if (sign == NB_UNSIGNED) {
                return UnUlong_NEW(&UnUlong_Type, -UnUlong_GET(obj));
            }
            return UnLong_NEW(&UnLong_Type, -UnLong_GET(obj));
        }

        case LLONG_RANK: {
            if (sign == NB_UNSIGNED) {
                return UnUllong_NEW(&UnUllong_Type, -UnUllong_GET(obj));
            }
            return UnLlong_NEW( &UnLlong_Type,  -UnLlong_GET(obj));
        }

        case FLT_RANK: {
            return UnFloat_NEW(&UnFloat_Type, -UnFloat_GET(obj));
        }

        case DBL_RANK: {
            return UnDouble_NEW(&UnDouble_Type, -UnDouble_GET(obj));
        }

        default: {
            Py_UNREACHABLE();
        }
    }
    
}

static PyObject *
UnInteger_nb_invert(UnChar *obj) {
    const int rank = UnC_GET_RANK(obj);
    const int sgn = UnC_GET_SIGNEDNESS(obj);
    assert(rank >= BOOL_RANK);
    union {
        int INT_VAR;
        long LONG_VAR;
        long long LLONG_VAR;
    } i;
    switch (rank) {
        case BOOL_RANK: {
            i.INT_VAR = UnBool_GET(obj);
            break;
        }
        case CHAR_RANK: {
            if (sgn == NB_SIGNED) {
                i.INT_VAR = ~UnSchar_GET(obj);
                break;
            }
            i.INT_VAR = ~UnUchar_GET(obj);
            break;
        }
        case SHRT_RANK: {
            if (sgn == NB_SIGNED) {
                i.INT_VAR = ~UnShort_GET(obj);
                break;
            }
            i.INT_VAR = UnUshort_GET(obj);
            break;
        }
        case INT_RANK: {
            if (sgn == NB_SIGNED) {
                i.INT_VAR = ~UnInt_GET(obj);
                break;
            }
            return UnUint_NEW(&UnUint_Type, ~UnUint_GET(obj));
        }
        case LONG_RANK: {
            if (sgn == NB_SIGNED) {
                i.LONG_VAR = ~UnLong_GET(obj);
                return UnLong_NEW(&UnLong_Type, i.LONG_VAR);
            }
            return UnUlong_NEW(&UnUlong_Type, ~UnUlong_GET(obj));
        }
        case LLONG_RANK: {
            if (sgn == NB_SIGNED) {
                i.LLONG_VAR = ~UnLlong_GET(obj);
                return UnLlong_NEW(&UnLlong_Type, i.LLONG_VAR);
            }
            return UnUllong_NEW(&UnUllong_Type, ~UnUllong_GET(obj));
        }
        default: {
            Py_UNREACHABLE();
        }
    }
    return UnInt_NEW(&UnInt_Type, i.INT_VAR);
}

#define UnReal_NO_CONST_LHS(targ, tp) do {\
        if (tp->t_constant) {\
            return PyErr_Format(\
                PyExc_TypeError,\
                "in place operation on const qualified %s",\
                py_TP_NAME(targ)\
            );\
        }\
    } while (0)

static inline PyObject *
UnBoolean_binop(PyObject *lhs, PyObject *rhs, int op) {
    if (!UnC_IS_DATA_TYPE(rhs)) {
        Py_RETURN_NOTIMPLEMENTED;
    }
    const unsys_t *btype = UnC_GET_INFO((UnChar *) rhs);
    return UnReal_binops[btype->t_as](lhs, rhs, op);
}

static inline PyObject *
UnBoolean_inplace_binop(PyObject *lhs, PyObject *rhs, int op) {
    PyObject *tmp;
    const unsys_t *atype = UnC_GET_INFO((UnChar *) lhs);
    UnReal_NO_CONST_LHS(lhs, atype);
    if (!UnC_IS_DATA_TYPE(rhs)) {
        if (!PyLong_Check(rhs)) {
            Py_RETURN_NOTIMPLEMENTED;
        }
        tmp = UnBool_NEW(&UnBool_Type, Py_SIZE(rhs) != 0);
    }
    else {
        return UnBool_inplace_binop(lhs, rhs, op);
    }
    if (tmp == NULL) {
        return NULL;
    }
    lhs = UnBool_inplace_binop(lhs, tmp, op);
    Py_DECREF(tmp);
    return lhs;
}

static inline PyObject *
UnUnsigned_binop(PyObject *lhs, PyObject *rhs, int op) {
    if (!UnC_IS_DATA_TYPE(rhs)) {
        Py_RETURN_NOTIMPLEMENTED;
    }
    const unsys_t *atype = UnC_GET_INFO((UnChar *) lhs);
    const unsys_t *btype = UnC_GET_INFO((UnChar *) rhs);
    if (atype->t_rank >= btype->t_rank) {
        return UnReal_binops[atype->t_as](lhs, rhs, op);
    }
    return UnReal_binops[btype->t_as](lhs, rhs, op);
}

static inline PyObject *
UnUnsigned_inplace_binop(PyObject *lhs, PyObject *rhs, int op) {
    const unsys_t *atype = UnC_GET_INFO((UnChar *) lhs);
    UnReal_NO_CONST_LHS(lhs, atype);
    PyObject *tmp;
    if (!UnC_IS_DATA_TYPE(rhs)) {
        if (!PyLong_Check(rhs)) {
            Py_RETURN_NOTIMPLEMENTED;
        }
        switch (atype->t_rank) {
            case CHAR_RANK: {
                tmp = UnReal_CAST(&UnSchar_Type, rhs);
                break;
            }
            case SHRT_RANK: {
                tmp = UnReal_CAST(&UnShort_Type, rhs);
                break;
            }
            case INT_RANK: {
                tmp = UnReal_CAST(&UnInt_Type, rhs);
                break;
            }
            case LONG_RANK: {
                tmp = UnReal_CAST(&UnLong_Type, rhs);
                break;
            }
            case LLONG_RANK: {
                tmp = UnReal_CAST(&UnLlong_Type, rhs);
                break;
            }
            default: {
                Py_UNREACHABLE();
            }
        }
    }
    else {
        const unsys_t *btype = UnC_GET_INFO((UnChar *) rhs);
        if (atype->t_rank >= btype->t_rank) {
            return UnReal_inplace_binops[atype->t_as](lhs, rhs, op);
        }
        return UnReal_binops[btype->t_as](lhs, rhs, op-1);
    }
    if (tmp == NULL) {
        return NULL;
    }
    lhs = UnReal_inplace_binops[atype->t_as](lhs, tmp, op);
    Py_DECREF(tmp);
    return lhs;
}

static const _Bool 
UnSigned_lhsops[NB_RANK_MAX][NB_RANK_MAX] = {
    [CHAR_RANK] = {
        [BOOL_RANK]     = 1,
    },
    [SHRT_RANK] = {
        [BOOL_RANK]     = 1,
        [UCHAR_RANK]    = (UCHAR_MAX <= SHRT_MAX),
    },
    [INT_RANK] = {
        [BOOL_RANK]     = 1,
        [UCHAR_RANK]    = (UCHAR_MAX <= INT_MAX),
        [USHRT_RANK]    = (USHRT_MAX <= INT_MAX),
    },
    [LONG_RANK] = {
        [BOOL_RANK]     = 1,
        [UCHAR_RANK]    = (UCHAR_MAX <= LONG_MAX),
        [USHRT_RANK]    = (USHRT_MAX <= LONG_MAX),
        [UINT_RANK]     = (UINT_MAX  <= LONG_MAX),
    },
    [LLONG_RANK] = {
        [BOOL_RANK]     = 1,
        [UCHAR_RANK]    = (UCHAR_MAX <= LLONG_MAX),
        [USHRT_RANK]    = (USHRT_MAX <= LLONG_MAX),
        [UINT_RANK]     = (UINT_MAX  <= LLONG_MAX),
        [ULONG_RANK]    = (ULONG_MAX <= LLONG_MAX),
    },
};

static inline PyObject *
UnSigned_binop(PyObject *lhs, PyObject *rhs, int op) {
    if (!UnC_IS_DATA_TYPE(rhs)) {
        Py_RETURN_NOTIMPLEMENTED;
    }
    const unsys_t *atype = UnC_GET_INFO((UnChar *) lhs);
    const unsys_t *btype = UnC_GET_INFO((UnChar *) rhs);
    if (btype->t_signedness == NB_SIGNED) {
        if (atype->t_rank >= btype->t_rank) {
            return UnReal_binops[atype->t_as](lhs, rhs, op);
        }
    }
    else {
        if (UnSigned_lhsops[atype->t_rank][btype->t_rank]) {
            return UnReal_binops[atype->t_as](lhs, rhs, op);
        }
    }
    return UnReal_binops[btype->t_as](lhs, rhs, op);
}

static inline PyObject *
UnSigned_inplace_binop(PyObject *lhs, PyObject *rhs, int op) {
    const unsys_t *atype = UnC_GET_INFO((UnChar *) lhs);
    UnReal_NO_CONST_LHS(lhs, atype);
    if (!UnC_IS_DATA_TYPE(rhs)) {
        Py_RETURN_NOTIMPLEMENTED;
    }
    const unsys_t *btype = UnC_GET_INFO((UnChar *) rhs);
    if (btype->t_signedness == NB_SIGNED) {
        if (atype->t_rank >= btype->t_rank) {
            return UnReal_inplace_binops[atype->t_as](lhs, rhs, op);
        }
    }
    else {
        if (UnSigned_lhsops[atype->t_rank][btype->t_rank]) {
            return UnReal_binops[atype->t_as](lhs, rhs, op);
        }
    }
    return UnReal_binops[btype->t_as](lhs, rhs, op-1);
}

static inline PyObject *
UnFloating_binop(PyObject *lhs, PyObject *rhs, int op) {
    const unsys_t *atype = UnC_GET_INFO((UnChar *) lhs);
    if (!UnC_IS_DATA_TYPE(rhs)) {
        PyObject *tmp = PyNumber_Float(rhs);
        if (tmp == NULL) {
            PyErr_Clear();
            Py_RETURN_NOTIMPLEMENTED;
        }
        double dbl = PyFloat_AsDouble(tmp);
        Py_DECREF(tmp);
        tmp = UnDouble_NEW(&UnDouble_Type, dbl);
        if (tmp == NULL) {
            return NULL;
        }
        rhs = tmp;
        if (atype->t_rank >= DBL_RANK) {
            tmp = UnReal_binops[atype->t_as](lhs, rhs, op);
        }
        else {
            tmp = UnReal_binops[AS_DBL](lhs, rhs, op);
        }
        Py_DECREF(rhs);
        return tmp;
    }
    const unsys_t *btype = UnC_GET_INFO((UnChar *) rhs);
    if (atype->t_rank < btype->t_rank) {
        return UnReal_binops[btype->t_as](lhs, rhs, op);
    }
    else {
        return UnReal_binops[atype->t_as](lhs, rhs, op);
    }
}

static inline PyObject *
UnFloating_inplace_binop(PyObject *lhs, PyObject *rhs, int op) {
    const unsys_t *atype = UnC_GET_INFO((UnChar *) lhs);
    UnReal_NO_CONST_LHS(lhs, atype);
    PyObject *tmp;
    if (!UnC_IS_DATA_TYPE(rhs)) {
        PyNumberMethods *ml = py_AS_NUMBER(rhs);
        if (ml == NULL) {
            Py_RETURN_NOTIMPLEMENTED;
        }
        if (ml->nb_float == NULL) {
            Py_RETURN_NOTIMPLEMENTED;
        }
        tmp = ml->nb_float(rhs);
        if (tmp == NULL) {
            return NULL;
        }
        rhs = UnDouble_NEW(&UnDouble_Type, PyFloat_AsDouble(rhs));
        Py_DECREF(tmp);
    }
    else {
        return UnReal_inplace_binops[atype->t_as](lhs, rhs, op);
    }
    if (rhs == NULL) {
        return NULL;
    }
    tmp = UnReal_inplace_binops[atype->t_as](lhs, rhs, op);
    Py_DECREF(rhs);
    return tmp;
}

#define UnInteger_binop_wrappers(ABC) static PyObject *\
Un##ABC##_nb_add(PyObject *a, PyObject *b) {\
    return Un##ABC##_binop(a, b, BI_ADD);\
}\
static PyObject *\
Un##ABC##_nb_subtract(PyObject *a, PyObject *b) {\
    return Un##ABC##_binop(a, b, BI_SUB);\
}\
static PyObject *\
Un##ABC##_nb_multiply(PyObject *a, PyObject *b) {\
    return Un##ABC##_binop(a, b, BI_MUL);\
}\
static PyObject *\
Un##ABC##_nb_true_divide(PyObject *a, PyObject *b) {\
    return Un##ABC##_binop(a, b, BI_DIV);\
}\
static PyObject *\
Un##ABC##_nb_remainder(PyObject *a, PyObject *b) {\
    return Un##ABC##_binop(a, b, BI_MOD);\
}\
static PyObject *\
Un##ABC##_nb_and(PyObject *a, PyObject *b) {\
    return Un##ABC##_binop(a, b, BI_AND);\
}\
static PyObject *\
Un##ABC##_nb_or(PyObject *a, PyObject *b) {\
    return Un##ABC##_binop(a, b, BI_OR);\
}\
static PyObject *\
Un##ABC##_nb_xor(PyObject *a, PyObject *b) {\
    return Un##ABC##_binop(a, b, BI_OR);\
}\
static PyObject *\
Un##ABC##_nb_inplace_add(PyObject *a, PyObject *b) {\
    return Un##ABC##_inplace_binop(a, b, BI_IADD);\
}\
static PyObject *\
Un##ABC##_nb_inplace_subtract(PyObject *a, PyObject *b) {\
    return Un##ABC##_inplace_binop(a, b, BI_ISUB);\
}\
static PyObject *\
Un##ABC##_nb_inplace_multiply(PyObject *a, PyObject *b) {\
    return Un##ABC##_inplace_binop(a, b, BI_IMUL);\
}\
static PyObject *\
Un##ABC##_nb_inplace_true_divide(PyObject *a, PyObject *b) {\
    return Un##ABC##_inplace_binop(a, b, BI_IDIV);\
}\
static PyObject *\
Un##ABC##_nb_inplace_remainder(PyObject *a, PyObject *b) {\
    return Un##ABC##_inplace_binop(a, b, BI_IMOD);\
}\
static PyObject *\
Un##ABC##_nb_inplace_and(PyObject *a, PyObject *b) {\
    return Un##ABC##_inplace_binop(a, b, BI_IAND);\
}\
static PyObject *\
Un##ABC##_nb_inplace_or(PyObject *a, PyObject *b) {\
    return Un##ABC##_inplace_binop(a, b, BI_IOR);\
}\
static PyObject *\
Un##ABC##_nb_inplace_xor(PyObject *a, PyObject *b) {\
    return Un##ABC##_inplace_binop(a, b, BI_IOR);\
}

#define UnFloating_binop_wrappers(ABC) \
static PyObject *\
Un##ABC##_nb_add(PyObject *a, PyObject *b) {\
    return Un##ABC##_binop(a, b, BI_ADD);\
}\
static PyObject *\
Un##ABC##_nb_subtract(PyObject *a, PyObject *b) {\
    return Un##ABC##_binop(a, b, BI_SUB);\
}\
static PyObject *\
Un##ABC##_nb_multiply(PyObject *a, PyObject *b) {\
    return Un##ABC##_binop(a, b, BI_MUL);\
}\
static PyObject *\
Un##ABC##_nb_true_divide(PyObject *a, PyObject *b) {\
    return Un##ABC##_binop(a, b, BI_DIV);\
}\
static PyObject *\
Un##ABC##_nb_inplace_add(PyObject *a, PyObject *b) {\
    return Un##ABC##_inplace_binop(a, b, BI_IADD);\
}\
static PyObject *\
Un##ABC##_nb_inplace_subtract(PyObject *a, PyObject *b) {\
    return Un##ABC##_inplace_binop(a, b, BI_ISUB);\
}\
static PyObject *\
Un##ABC##_nb_inplace_multiply(PyObject *a, PyObject *b) {\
    return Un##ABC##_inplace_binop(a, b, BI_IMUL);\
}\
static PyObject *\
Un##ABC##_nb_inplace_true_divide(PyObject *a, PyObject *b) {\
    return Un##ABC##_inplace_binop(a, b, BI_IDIV);\
}

UnInteger_binop_wrappers(Boolean)
UnInteger_binop_wrappers(Signed)
UnInteger_binop_wrappers(Unsigned)
UnFloating_binop_wrappers(Floating)

#define UnInteger_binops(v) \
switch(v) {\
    case BI_ADD:    a += b; break;\
    case BI_SUB:    a -= b; break;\
    case BI_MUL:    a *= b; break;\
    case BI_DIV:    a /= b; break;\
    case BI_MOD:    a %= b; break;\
    case BI_AND:    a &= b; break;\
    case BI_OR:     a |= b; break;\
    case BI_XOR:    a ^= b; break;\
    default: Py_UNREACHABLE();\
}

#define UnInteger_inplace_binops(obj, v) \
switch(v) {\
    case BI_IADD:   obj += b; break;\
    case BI_ISUB:   obj -= b; break;\
    case BI_IMUL:   obj *= b; break;\
    case BI_IDIV:   obj /= b; break;\
    case BI_IMOD:   obj %= b; break;\
    case BI_IAND:   obj &= b; break;\
    case BI_IOR:    obj |= b; break;\
    case BI_IXOR:   obj ^= b; break;\
    default: Py_UNREACHABLE();\
}

#define UnFloating_binops(v) \
switch (v) {\
    case BI_ADD:    a += b; break;\
    case BI_SUB:    a -= b; break;\
    case BI_MUL:    a *= b; break;\
    case BI_DIV:    a /= b; break;\
    case BI_MOD:\
    case BI_AND:\
    case BI_OR:\
    case BI_XOR:\
    case BI_IXOR: Py_RETURN_NOTIMPLEMENTED;\
    default: Py_UNREACHABLE();\
}

#define UnFloating_inplace_binops(obj, v) \
switch(v) {\
    case BI_IADD: obj += b; break;\
    case BI_ISUB: obj -= b; break;\
    case BI_IMUL: obj *= b; break;\
    case BI_IDIV: obj /= b; break;\
    case BI_IMOD:\
    case BI_IAND:\
    case BI_IOR:\
    case BI_IXOR:   Py_RETURN_NOTIMPLEMENTED;\
    default: Py_UNREACHABLE();\
}

static PyObject *
UnBool_binop(PyObject *lhs, PyObject *rhs, int op) {
    int a = UnC_GET_CONV((UnChar *) lhs)->as_bool(lhs);
    int b = UnC_GET_CONV((UnChar *) rhs)->as_bool(rhs);
    UnInteger_binops(op)
    return UnInt_NEW(&UnInt_Type, a);
}

static PyObject *
UnBool_inplace_binop(PyObject *lhs, PyObject *rhs, int op) {
    _Bool b = UnC_GET_CONV((UnChar *) rhs)->as_bool(rhs);
    UnInteger_inplace_binops(UnBool_C(lhs)->yval, op)
    return Py_NewRef(lhs);
}

static PyObject *
UnSchar_binop(PyObject *lhs, PyObject *rhs, int op) {
    int a = UnC_GET_CONV((UnChar *) lhs)->as_schar(lhs);
    int b = UnC_GET_CONV((UnChar *) rhs)->as_schar(rhs);
    UnInteger_binops(op)
    return UnInt_NEW(&UnInt_Type, a);
}

static PyObject *
UnSchar_inplace_binop(PyObject *lhs, PyObject *rhs, int op) {
    signed char b = UnC_GET_CONV((UnChar *) rhs)->as_schar(rhs);
    UnInteger_inplace_binops(UnChar_C(lhs)->sval, op)
    return Py_NewRef(lhs);
}

static PyObject *
UnShort_binop(PyObject *lhs, PyObject *rhs, int op) {
    int a = UnC_GET_CONV((UnChar *) lhs)->as_short(lhs);
    int b = UnC_GET_CONV((UnChar *) rhs)->as_short(rhs);
    UnInteger_binops(op)
    return UnInt_NEW(&UnInt_Type, a);
}

static PyObject *
UnShort_inplace_binop(PyObject *lhs, PyObject *rhs, int op) {
    short b = UnC_GET_CONV((UnChar *) rhs)->as_short(rhs);
    UnInteger_inplace_binops(UnShort_C(lhs)->sval, op)
    return Py_NewRef(lhs);
}

static PyObject *
UnInt_binop(PyObject *lhs, PyObject *rhs, int op) {
    int a = UnC_GET_CONV((UnChar *) lhs)->as_int(lhs);
    int b = UnC_GET_CONV((UnChar *) rhs)->as_int(rhs);
    UnInteger_binops(op)
    return UnInt_NEW(&UnInt_Type, a);
}

static PyObject *
UnInt_inplace_binop(PyObject *lhs, PyObject *rhs, int op) {
    int b = UnC_GET_CONV((UnChar *) rhs)->as_int(rhs);
    UnInteger_inplace_binops(UnInt_C(lhs)->sval, op)
    return Py_NewRef(lhs);
}

static PyObject *
UnLong_binop(PyObject *lhs, PyObject *rhs, int op) {
    long a = UnC_GET_CONV((UnChar *) lhs)->as_long(lhs);
    long b = UnC_GET_CONV((UnChar *) rhs)->as_long(rhs);
    UnInteger_binops(op)
    return UnLong_NEW(&UnLong_Type, a);
}

static PyObject *
UnLong_inplace_binop(PyObject *lhs, PyObject *rhs, int op) {
    long b = UnC_GET_CONV((UnChar *) rhs)->as_long(rhs);
    UnInteger_inplace_binops(UnLong_C(lhs)->sval, op)
    return Py_NewRef(lhs);
}

static PyObject *
UnLlong_binop(PyObject *lhs, PyObject *rhs, int op) {
    long long a = UnC_GET_CONV((UnChar *) lhs)->as_llong(lhs);
    long long b = UnC_GET_CONV((UnChar *) rhs)->as_llong(rhs);
    UnInteger_binops(op)
    return UnLlong_NEW(&UnLlong_Type, a);
}

static PyObject *
UnLlong_inplace_binop(PyObject *lhs, PyObject *rhs, int op) {
    long long b = UnC_GET_CONV((UnChar *) rhs)->as_llong(rhs);
    UnInteger_inplace_binops(UnLlong_C(lhs)->sval, op)
    return Py_NewRef(lhs);
}

static PyObject *
UnUchar_binop(PyObject *lhs, PyObject *rhs, int op) {
    int a = UnC_GET_CONV((UnChar *) lhs)->as_uchar(lhs);
    int b = UnC_GET_CONV((UnChar *) rhs)->as_uchar(rhs);
    UnInteger_binops(op)
    return UnInt_NEW(&UnInt_Type, a);
}

static PyObject *
UnUchar_inplace_binop(PyObject *lhs, PyObject *rhs, int op) {
    unsigned char b = UnC_GET_CONV((UnChar *) rhs)->as_uchar(rhs);
    UnInteger_inplace_binops(UnChar_C(lhs)->uval, op)
    return Py_NewRef(lhs);
}

static PyObject *
UnUshort_binop(PyObject *lhs, PyObject *rhs, int op) {
    int a = UnC_GET_CONV((UnChar *) lhs)->as_ushort(lhs);
    int b = UnC_GET_CONV((UnChar *) rhs)->as_ushort(rhs);
    UnInteger_binops(op)
    return UnInt_NEW(&UnInt_Type, a);
}

static PyObject *
UnUshort_inplace_binop(PyObject *lhs, PyObject *rhs, int op) {
    unsigned short b = UnC_GET_CONV((UnChar *) rhs)->as_ushort(rhs);
    UnInteger_inplace_binops(UnShort_C(lhs)->uval, op)
    return Py_NewRef(lhs);
}

static PyObject *
UnUint_binop(PyObject *lhs, PyObject *rhs, int op) {
    unsigned a = UnC_GET_CONV((UnChar *) lhs)->as_uint(lhs);
    unsigned b = UnC_GET_CONV((UnChar *) rhs)->as_uint(rhs);
    UnInteger_binops(op)
    return UnUint_NEW(&UnUint_Type, a);
}

static PyObject *
UnUint_inplace_binop(PyObject *lhs, PyObject *rhs, int op) {
    unsigned b = UnC_GET_CONV((UnChar *) rhs)->as_uint(rhs);
    UnInteger_inplace_binops(UnInt_C(lhs)->uval, op)
    return Py_NewRef(lhs);
}

static PyObject *
UnUlong_binop(PyObject *lhs, PyObject *rhs, int op) {
    unsigned long a = UnC_GET_CONV((UnChar *) lhs)->as_ulong(lhs);
    unsigned long b = UnC_GET_CONV((UnChar *) rhs)->as_ulong(rhs);
    UnInteger_binops(op)
    return UnUlong_NEW(&UnUlong_Type, a);
}

static PyObject *
UnUlong_inplace_binop(PyObject *lhs, PyObject *rhs, int op) {
    unsigned long b = UnC_GET_CONV((UnChar *) rhs)->as_ulong(rhs);
    UnInteger_inplace_binops(UnLong_C(lhs)->uval, op)
    return Py_NewRef(lhs);
}

static PyObject *
UnUllong_binop(PyObject *lhs, PyObject *rhs, int op) {
    unsigned long long a = UnC_GET_CONV((UnChar *) lhs)->as_ullong(lhs);
    unsigned long long b = UnC_GET_CONV((UnChar *) rhs)->as_ullong(rhs);
    UnInteger_binops(op)
    return UnUllong_NEW(&UnUllong_Type, a);
}

static PyObject *
UnUllong_inplace_binop(PyObject *lhs, PyObject *rhs, int op) {
    unsigned long long b = UnC_GET_CONV((UnChar *) rhs)->as_ulong(rhs);
    UnInteger_inplace_binops(UnLlong_C(lhs)->uval, op)
    return Py_NewRef(lhs);
}

static PyObject *
UnFloat_binop(PyObject *lhs, PyObject *rhs, int op) {
    double a = UnC_GET_CONV((UnChar *) lhs)->as_dbl(lhs);
    double b = UnC_GET_CONV((UnChar *) rhs)->as_dbl(rhs);
    UnFloating_binops(op)
    return UnDouble_NEW(&UnDouble_Type, a);
}

static PyObject *
UnDouble_binop(PyObject *lhs, PyObject *rhs, int op) {
    double a = UnC_GET_CONV((UnChar *) lhs)->as_dbl(lhs);
    double b = UnC_GET_CONV((UnChar *) rhs)->as_dbl(rhs);
    UnFloating_binops(op)
    return UnDouble_NEW(&UnDouble_Type, a);
}

static PyObject *
UnLdouble_binop(PyObject *lhs, PyObject *rhs, int op) {
    long double a = UnC_GET_CONV((UnChar *) lhs)->as_ldbl(lhs);
    long double b = UnC_GET_CONV((UnChar *) rhs)->as_ldbl(rhs);
    UnFloating_binops(op)
    return UnLdouble_NEW(&UnLdouble_Type, a);
}

static PyObject *
UnFloat_inplace_binop(PyObject *lhs, PyObject *rhs, int op) {
    float b = UnC_GET_CONV((UnChar *) rhs)->as_flt(rhs);
    UnFloating_inplace_binops(UnFloat_C(lhs)->fval, op)
    return Py_NewRef(lhs);
}

static PyObject *
UnDouble_inplace_binop(PyObject *lhs, PyObject *rhs, int op) {
    double b = UnC_GET_CONV((UnChar *) rhs)->as_dbl(rhs);
    UnFloating_inplace_binops(UnDouble_C(lhs)->fval, op)
    return Py_NewRef(lhs);
}

static PyObject *
UnLdouble_inplace_binop(PyObject *lhs, PyObject *rhs, int op) {
    long double b = UnC_GET_CONV((UnChar *) rhs)->as_ldbl(rhs);
    UnFloating_inplace_binops(UnLdouble_C(lhs)->fval, op)
    return Py_NewRef(lhs);
}

static inline PyObject *
UnInteger_NB_LSHIFT(UnChar *a, PyObject *b, int inplace, int sign) {
    int n;
    if (Py_TYPE(b)->tp_flags&Py_TPFLAGS_LONG_SUBCLASS) {
        n = pylong_INT(b);
    }
    else {
        TypeAttrDict *stg = UnC_TAD((UnChar *) b);
        if (stg->conv->as_int == NULL) {
            return py_ERR_NOT_AN_INT(b);
        }
        n = stg->conv->as_int(b);
    }
    if (n < 0) {
        return PyErr_Format(PyExc_ValueError, "negative shift count");
    }
    if (sign) {
        switch (UnC_GET_RANK(a)) {
            case CHAR_RANK: {
                if (inplace) {
                    UnChar_C(a)->sval <<= n;
                    return Py_NewRef((PyObject *) a);
                }
                n = UnSchar_GET(a)<<n;
                break;
            }
            case SHRT_RANK: {
                if (inplace) {
                    UnShort_C(a)->sval <<= n;
                    return Py_NewRef((PyObject *) a);
                }
                n = UnShort_GET(a)<<n;
                break;
            }
            case INT_RANK: {
                if (inplace) {
                    UnInt_C(a)->sval <<= n;
                    return Py_NewRef((PyObject *) a);
                }
                n = UnInt_GET(a)<<n;
                break;
            }
            case LONG_RANK: {
                if (inplace) {
                    UnLong_C(a)->sval <<= n;
                    return Py_NewRef((PyObject *) a);
                }
                return UnLong_NEW(&UnLong_Type, UnLong_GET(a)<<n);
            }
            case LLONG_RANK: {
                if (inplace) {
                    UnLlong_C(a)->sval <<= n;
                    return Py_NewRef((PyObject *) a);
                }
                return UnLlong_NEW(&UnLlong_Type, UnLlong_GET(a)<<n);
            }
            default: {
                Py_UNREACHABLE();
            }
        }
    }
    else {
        switch (UnC_GET_RANK(a)) {
            case BOOL_RANK: {
                if (inplace) {
                    UnBool_C(a)->yval <<= n;
                    return Py_NewRef((PyObject *) a);
                }
                n = UnBool_C(a)->yval<<n;
            }
            case CHAR_RANK: {
                if (inplace) {
                    UnChar_C(a)->uval <<= n;
                    return Py_NewRef((PyObject *) a);
                }
                n = UnUchar_GET(a)<<n;
                break;
            }
            case SHRT_RANK: {
                if (inplace) {
                    UnShort_C(a)->uval <<= n;
                    return Py_NewRef((PyObject *) a);
                }
                n = UnUshort_GET(a)<<n;
                break;
            }
            case INT_RANK: {
                if (inplace) {
                    UnInt_C(a)->uval <<= n;
                    return Py_NewRef((PyObject *) a);
                }
                return UnUint_NEW(&UnLong_Type, UnUint_GET(a)<<n);
            }
            case LONG_RANK: {
                if (inplace) {
                    UnLong_C(a)->uval <<= n;
                    return Py_NewRef((PyObject *) a);
                }
                return UnUlong_NEW(&UnUlong_Type, UnUlong_GET(a)<<n);
            }
            case LLONG_RANK: {
                if (inplace) {
                    UnLlong_C(a)->uval <<= n;
                    return Py_NewRef((PyObject *) a);
                }
                return UnUllong_NEW(&UnUllong_Type, UnUllong_GET(a)<<n);
            }
            default: {
                Py_UNREACHABLE();
            }
        }
    }
    return UnInt_NEW(&UnInt_Type, n);
}

static inline PyObject *
UnInteger_NB_RSHIFT(UnChar *a, PyObject *b, int inplace, int sign) {
    Py_RETURN_NOTIMPLEMENTED;
}

static PyObject *
UnSigned_nb_lshift(UnChar *a, PyObject *b) {
    return UnInteger_NB_LSHIFT(a, b, 0, 1);
}

static PyObject *
UnSigned_nb_rshift(UnChar *a, PyObject *b) {
    return UnInteger_NB_RSHIFT(a, b, 0, 1);
}

static PyObject *
UnSigned_nb_inplace_lshift(UnChar *a, PyObject *b) {
    return UnInteger_NB_LSHIFT(a, b, 1, 1);
}

static PyObject *
UnSigned_nb_inplace_rshift(UnChar *a, PyObject *b) {
    return UnInteger_NB_RSHIFT(a, b, 1, 1);
}

static PyObject *
UnUnsigned_nb_lshift(UnChar *a, PyObject *b) {
    return UnInteger_NB_LSHIFT(a, b, 0, 0);
}

static PyObject *
UnUnsigned_nb_inplace_lshift(UnChar *a, PyObject *b) {
    return UnInteger_NB_LSHIFT(a, b, 1, 0);
}

static PyObject *
UnUnsigned_nb_rshift(UnChar *a, PyObject *b) {
    return UnInteger_NB_RSHIFT(a, b, 0, 0);
}

static PyObject *
UnUnsigned_nb_inplace_rshift(UnChar *a, PyObject *b) {
    return UnInteger_NB_RSHIFT(a, b, 1, 0);
}

static inline PyObject *
UnReal_richcompare_id(UnChar *lhs, PyObject *rhs, int op) {
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

static PyObject *
UnUnsigned_richcompare(UnChar *lhs, PyObject *rhs, int op) {
    if ((PyObject *) lhs == rhs) {
        return UnReal_richcompare_id(lhs, rhs, op);
    }
    const unsys_t *atype = UnC_GET_INFO(lhs);
    unval_t a;
    unval_t b;
    int i;
    if (!UnC_IS_DATA_TYPE(rhs)) {
        unsigned long subtype = py_TP_FLAGS(rhs)&0xFF000000UL;
        switch (subtype) {
            case Py_TPFLAGS_LONG_SUBCLASS: {
                a.UINTMAX_VAR = UnC_GET_CONV(lhs)->as_uintmax(lhs);
                i = uintmax_CMP_PYLONG(a.UINTMAX_VAR, rhs);
                goto the_end;
            }
            case Py_TPFLAGS_UNICODE_SUBCLASS: {
                b.INT_VAR = int_FROM_PYCHAR(rhs);
                break;
            }
            case Py_TPFLAGS_BYTES_SUBCLASS: {
                b.INT_VAR = int_FROM_PYBYTE(rhs);
                break;
            }
            default: {
                if (!PyFloat_Check(rhs)) {
                    Py_RETURN_NOTIMPLEMENTED;
                }
                a.DBL_VAR = UnC_GET_CONV(lhs)->as_dbl(lhs);
                b.DBL_VAR = PyFloat_AsDouble(rhs);
                if (a.DBL_VAR == b.DBL_VAR) {
                    i = 0;
                    goto the_end;
                }
                i = (a.DBL_VAR > b.DBL_VAR) ? 1 : (0-1);
                goto the_end;
            }
        }
        if (b.INT_VAR < 0) {
            Py_RETURN_NOTIMPLEMENTED;
        }
        a.UINTMAX_VAR = UnC_GET_CONV(lhs)->as_uintmax(lhs);
        if (a.UINTMAX_VAR <= b.INT_VAR) {
            i = a.UINTMAX_VAR == b.INT_VAR ? 0 : (0-1);
        }
        else {
            i = 1;
        }
    }
    else {
        const unsys_t *btype = UnC_GET_INFO((UnChar *) rhs);
        if (btype->t_signedness == NB_UNSIGNED) {
            a.UINTMAX_VAR = UnC_GET_CONV(lhs)->as_uintmax(lhs);
            b.UINTMAX_VAR = UnC_GET_CONV((UnChar *) rhs)->as_uintmax(rhs);
            if (a.UINTMAX_VAR <= b.UINTMAX_VAR) {
                i = (a.UINTMAX_VAR == b.UINTMAX_VAR) ? 0 : (0-1);
            }
            else {
                i = 1;
            }
            goto the_end;
        }
        if (btype->t_signedness == NB_SIGNED) {
            b.INTMAX_VAR = UnC_GET_CONV((UnChar *) rhs)->as_intmax(rhs);
            if (b.INTMAX_VAR < 0) {
                i = 1;
            }
            else {
                a.UINTMAX_VAR = UnC_GET_CONV(lhs)->as_uintmax(lhs);
                if (a.UINTMAX_VAR <= (uintmax_t) b.INTMAX_VAR) {
                    i = (a.UINTMAX_VAR == b.UINTMAX_VAR) ? 0 : 1;
                }
                else {
                    i = 1;
                }
            }
            goto the_end;
        }
        a.DBL_VAR = UnC_GET_CONV(lhs)->as_dbl(lhs);
        b.DBL_VAR = UnC_GET_CONV((UnChar *) rhs)->as_dbl(rhs);
        if (a.DBL_VAR <= b.DBL_VAR) {
            i = (a.DBL_VAR == b.DBL_VAR) ? 0 : (0-1);
        }
        else {
            i = 1;
        }
    }
    the_end: {
        return pybool_FROM_CMP(i, op);
    }
}

static PyObject *
UnSigned_richcompare(UnChar *lhs, PyObject *rhs, int op) {
    if ((PyObject *) lhs == rhs) {
        return UnReal_richcompare_id(lhs, rhs, op);
    }
    const unsys_t *atype = UnC_GET_INFO(lhs);
    unval_t a;
    unval_t b;
    int i;
    if (!UnC_IS_DATA_TYPE(rhs)) {
        unsigned long subtype = py_TP_FLAGS(rhs)&0xFF000000UL;
        switch (subtype) {
            case Py_TPFLAGS_LONG_SUBCLASS: {
                a.INTMAX_VAR = UnC_GET_CONV(lhs)->as_intmax(lhs);
                i = intmax_CMP_PYLONG(a.INTMAX_VAR, rhs);
                goto the_end;
            }
            case Py_TPFLAGS_UNICODE_SUBCLASS: {
                b.INT_VAR = int_FROM_PYCHAR(rhs);
                break;
            }
            case Py_TPFLAGS_BYTES_SUBCLASS: {
                b.INT_VAR = int_FROM_PYBYTE(rhs);
                break;
            }
            default: {
                if (!PyFloat_Check(rhs)) {
                    Py_RETURN_NOTIMPLEMENTED;
                }
                a.DBL_VAR = UnC_GET_CONV(lhs)->as_dbl(lhs);
                b.DBL_VAR = PyFloat_AsDouble(rhs);
                if (a.DBL_VAR == b.DBL_VAR) {
                    i = 0;
                    goto the_end;
                }
                i = (a.DBL_VAR > b.DBL_VAR) ? 1 : (0-1);
                goto the_end;
            }
        }
        if (b.INT_VAR < 0) {
            Py_RETURN_NOTIMPLEMENTED;
        }
        a.INTMAX_VAR = UnC_GET_CONV(lhs)->as_intmax(lhs);
        if (a.INTMAX_VAR <= b.INT_VAR) {
            i = a.INTMAX_VAR == b.INT_VAR ? 0 : (0-1);
        }
        else {
            i = 1;
        }
    }
    else {
        const unsys_t *btype = UnC_GET_INFO((UnChar *) rhs);
        if (btype->t_signedness == NB_SIGNED) {
            a.INTMAX_VAR = UnC_GET_CONV(lhs)->as_intmax(lhs);
            b.INTMAX_VAR = UnC_GET_CONV((UnChar *) rhs)->as_intmax(rhs);
            if (a.INTMAX_VAR <= b.INTMAX_VAR) {
                i = (a.INTMAX_VAR == b.INTMAX_VAR) ? 0 : (0-1);
            }
            else {
                i = 1;
            }
            goto the_end;
        }
        if (btype->t_signedness == NB_UNSIGNED) {
            a.INTMAX_VAR = UnC_GET_CONV(lhs)->as_intmax(lhs);
            if (a.INTMAX_VAR < 0) {
                i = 0-1;
                goto the_end;
            }
            b.UINTMAX_VAR = UnC_GET_CONV((UnChar *) rhs)->as_uintmax(rhs);
            if ((uintmax_t) a.INTMAX_VAR <= b.UINTMAX_VAR) {
                i = (a.UINTMAX_VAR == b.UINTMAX_VAR) ? 0 : (0-1);
            }
            else {
                i = 1;
            }
            goto the_end;
        }
        a.DBL_VAR = UnC_GET_CONV(lhs)->as_dbl(lhs);
        b.DBL_VAR = UnC_GET_CONV((UnChar *) rhs)->as_dbl(rhs);
        if (a.DBL_VAR <= b.DBL_VAR) {
            i = (a.DBL_VAR == b.DBL_VAR) ? 0 : (0-1);
        }
        else {
            i = 1;
        }
    }
    the_end: {
        return pybool_FROM_CMP(i, op);
    }
}


static PyObject *
UnFloat_sign_getter(UnChar *obj, void *Py_UNUSED(ctx)) {
    return pylong_FROM_BOOL(GET_FLT_SIGN(UnC_GET_DATA(obj)));
}

static PyObject *
UnFloat_mant_getter(UnChar *obj, void *Py_UNUSED(ctx)) {
    return pylong_FROM_UINT32(GET_FLT_MANT(UnC_GET_DATA(obj)));
}

static PyObject *
UnFloat_expo_getter(UnChar *obj, void *Py_UNUSED(expo)) {
    return pylong_FROM_UINT32(GET_FLT_EXPO(UnC_GET_DATA(obj)));
}

static int
UnFloat_sign_setter(UnChar *obj, PyObject *val, void *Py_UNUSED(ctx)) {
    if (val == NULL) {
        SET_FLT_SIGN(UnC_GET_DATA(obj), 0);
    }
    else {
        _Bool sign;
        if (bool_FROM_NUMBER(val, &sign)) {
            return 0-1;
        }
        SET_FLT_SIGN(UnC_GET_DATA(obj), sign);
    }
    return 0;
}

static int 
UnFloat_mant_setter(UnChar *obj, PyObject *val, void *Py_UNUSED(ctx)) {
    Py_ssize_t mant;
    if (val == NULL) {
        mant = 0;
    }
    else {
        if (UnReal_INDEX(val, &mant) < 0) {
            return 0-1;
        }
        if ((mant < 0) || (mant > FLT_MANT_SIG)) {
            char src[64];
            (void) snprintf(src, sizeof src, "%zi", mant);
            (void) py_ERR_WOULD_OVERFLOW("float mantissa", src);
            return 0-1;
        }
    }
    SET_FLT_MANT(UnC_GET_DATA(obj), (uint32_t) mant);
    return 0;
}

static int 
UnFloat_expo_setter(UnChar *obj, PyObject *val, void *Py_UNUSED(ctx)) {
    Py_ssize_t expo;
    if (val == NULL) {
        expo = 0;
    }
    else {
        if (UnReal_INDEX(val, &expo) < 0) {
            return 0-1;
        }
        if ((expo < 0x0) || (expo > FLT_EXPO_SIG)) {
            char src[64];
            (void) snprintf(src, sizeof src, "%zi", expo);
            (void) py_ERR_WOULD_OVERFLOW("float exponent", src);
            return 0-1;
        }
    }
    SET_FLT_EXPO(UnC_GET_DATA(obj), (uint32_t) expo);
    return 0;
}

static PyObject *
UnReal_print_short(UnChar *obj) {
    short (*f)(void *) = UnC_GET_CONV(obj)->list[AS_SHRT];
    printf("conv->list[AS_SHRT] = %p\n", f);
    printf("conv->as_shrt       = %p\n", UnC_GET_CONV(obj)->as_short);
    printf("f() = %hi\n", f(obj));
    return Py_NewRef((PyObject *) obj);
}

static short
UnSchar_as_short(UnChar *i) {
    return (short) i->sval;
}

static PyObject *
UnSchar_to_short(UnChar *obj) {
    short a = UnC_GET_CONV(obj)->as_short(obj);
    short b = UnSchar_as_short(obj);
    printf("a = %hi\nb= %hi\n", a, b);
    Py_RETURN_NONE;
}

static PyObject *
unsys_bool_op_test(PyObject *mod) {
    volatile _Bool t = 1;
    volatile _Bool f = 0;
    volatile _Bool t_iadd_t = 1; t_iadd_t += t;
    volatile _Bool t_isub_t = 1; t_isub_t -= t;
    volatile _Bool t_imul_t = 1; t_imul_t *= t;
    volatile _Bool t_iand_t = 1; t_iand_t &= t;
    volatile _Bool t_ixor_t = 1; t_ixor_t ^= t;
    volatile _Bool t_ior_t  = 1; t_ior_t  |= t;
    volatile _Bool t_ilsh_t = 1; t_ilsh_t <<= t;
    volatile _Bool t_irsh_t = 1; t_irsh_t >>= t;
    volatile _Bool t_idiv_t = 1; t_idiv_t /= t;
    volatile _Bool t_imod_t = 1; t_imod_t %= t;
    volatile int tmp = t+t;
    printf("int i = t+t => %d\n", tmp);
    printf("(t+=t) => %d\n", t_iadd_t);
    printf("(t-=t) => %d\n", t_isub_t);
    printf("(t*=t) => %d\n", t_imul_t);
    printf("(t&=t) => %d\n", t_iand_t);
    printf("(t^=t) => %d\n", t_ixor_t);
    printf("(t|=t) => %d\n", t_ior_t);
    printf("(t<<=t) => %d\n", t_ilsh_t);
    printf("(t>>=t) => %d\n", t_irsh_t);
    printf("(t/=t) => %d\n", t_idiv_t);
    printf("(t%%=t) => %d\n", t_imod_t);
    Py_RETURN_NONE;
}

static UnCImpl 

UnSchar_impl = {
    .as = &UnSchar_AS,
    .ml = (PyMethodDef[]){
        {
            .ml_name = "schar_to_short",
            .ml_meth = (PyCFunction) UnSchar_to_short,
            .ml_flags = METH_NOARGS,
        },
        {0}
    },
},
UnShort_impl = {
    .as = &UnShort_AS,
},
UnInt_impl = {
    .as = &UnInt_AS,
},
UnLong_impl = {
    .as = &UnLong_AS,
},
UnLlong_impl = {
    .as = &UnLlong_AS,
},
UnBool_impl = {
    .as = &UnBool_AS,
},
UnUchar_impl = {
    .as = &UnUchar_AS,
},
UnUshort_impl = {
    .as = &UnUshort_AS,
},
UnUint_impl = {
    .as = &UnUint_AS,
},
UnUlong_impl = {
    .as = &UnUlong_AS,
},
UnUllong_impl = {
    .as = &UnUllong_AS,
},
UnFloat_impl = {
    .as = &UnFloat_AS,
    .gs = (PyGetSetDef[]){
        {
            "sign",
            (getter) UnFloat_sign_getter,
            (setter) UnFloat_sign_setter,
        },
        {
            "mant",
            (getter) UnFloat_mant_getter,
            (setter) UnFloat_mant_setter,
        },
        {
            "expo",
            (getter) UnFloat_expo_getter,
            (setter) UnFloat_expo_setter,
        },
        {0},
    },
},
UnDouble_impl = {
    .as = &UnDouble_AS,
},
UnLdouble_impl = {
    .as = &UnLdouble_AS,
},
UnReal_impl = {
    .ml = (PyMethodDef[]){
        {
            .ml_name    = "print_short",
            .ml_meth    = (PyCFunction) UnReal_print_short,
            .ml_flags   = METH_NOARGS,
            .ml_doc     = 0,
        },
        {0}
    },
    .nb = {
        .nb_bool                = (inquiry) UnReal_nb_bool,
        .nb_int                 = (unaryfunc) UnReal_nb_int,
        .nb_float               = (unaryfunc) UnReal_nb_float,
        .nb_positive            = (unaryfunc) UnReal_nb_positive,
        .nb_negative            = (unaryfunc) UnReal_nb_negative,
        .nb_absolute            = (unaryfunc) UnReal_nb_absolute,
    },
},
UnFloating_impl = {
    .nb = {
        .nb_divmod              = (binaryfunc) 0,
        .nb_add                 = (binaryfunc) UnFloating_nb_add,
        .nb_subtract            = (binaryfunc) UnFloating_nb_subtract,
        .nb_multiply            = (binaryfunc) UnFloating_nb_multiply,
        .nb_true_divide         = (binaryfunc) UnFloating_nb_true_divide,
        .nb_inplace_add         = (binaryfunc) UnFloating_nb_inplace_add,
        .nb_inplace_subtract    = (binaryfunc) UnFloating_nb_inplace_subtract,
        .nb_inplace_multiply    = (binaryfunc) UnFloating_nb_inplace_multiply,
        .nb_inplace_true_divide = (binaryfunc) UnFloating_nb_inplace_true_divide, 
    },
},
UnInteger_impl = {
    .nb = {
        .nb_invert = (unaryfunc) UnInteger_nb_invert,
    }
},

UnBoolean_impl = {
    .nb = {
        .nb_index               = (unaryfunc) UnBoolean_nb_index,
        .nb_divmod              = (binaryfunc) 0,
        .nb_lshift              = (binaryfunc) UnUnsigned_nb_lshift,
        .nb_rshift              = (binaryfunc) UnUnsigned_nb_rshift,
        .nb_inplace_lshift      = (binaryfunc) UnUnsigned_nb_inplace_lshift,
        .nb_inplace_rshift      = (binaryfunc) UnUnsigned_nb_inplace_rshift,
        .nb_add                 = (binaryfunc)         UnBoolean_nb_add,
        .nb_inplace_add         = (binaryfunc) UnBoolean_nb_inplace_add,
        .nb_subtract            = (binaryfunc)         UnBoolean_nb_subtract,
        .nb_inplace_subtract    = (binaryfunc) UnBoolean_nb_inplace_subtract,
        .nb_multiply            = (binaryfunc)         UnBoolean_nb_multiply,
        .nb_inplace_multiply    = (binaryfunc) UnBoolean_nb_inplace_multiply,
        .nb_true_divide         = (binaryfunc)         UnBoolean_nb_true_divide,
        .nb_inplace_true_divide = (binaryfunc) UnBoolean_nb_inplace_true_divide, 
        .nb_remainder           = (binaryfunc)         UnBoolean_nb_remainder,
        .nb_inplace_remainder   = (binaryfunc) UnBoolean_nb_inplace_remainder,
        .nb_or                  = (binaryfunc)         UnBoolean_nb_or,
        .nb_inplace_or          = (binaryfunc) UnBoolean_nb_inplace_or,
        .nb_and                 = (binaryfunc)         UnBoolean_nb_and,
        .nb_inplace_and         = (binaryfunc) UnBoolean_nb_inplace_and,
        .nb_xor                 = (binaryfunc)         UnBoolean_nb_xor,
        .nb_inplace_xor         = (binaryfunc) UnBoolean_nb_inplace_xor,
    },  
},

UnSigned_impl = {
    .nb = {
        .nb_divmod              = (binaryfunc) 0,
        .nb_index               = (unaryfunc) UnSigned_nb_index,
        .nb_lshift              = (binaryfunc) UnSigned_nb_lshift,
        .nb_rshift              = (binaryfunc) UnSigned_nb_rshift,
        .nb_inplace_lshift      = (binaryfunc) UnSigned_nb_inplace_lshift,
        .nb_inplace_rshift      = (binaryfunc) UnSigned_nb_inplace_rshift,
        .nb_add                 = (binaryfunc)         UnSigned_nb_add,
        .nb_inplace_add         = (binaryfunc) UnSigned_nb_inplace_add,
        .nb_subtract            = (binaryfunc)         UnSigned_nb_subtract,
        .nb_inplace_subtract    = (binaryfunc) UnSigned_nb_inplace_subtract,
        .nb_multiply            = (binaryfunc)         UnSigned_nb_multiply,
        .nb_inplace_multiply    = (binaryfunc) UnSigned_nb_inplace_multiply,
        .nb_true_divide         = (binaryfunc)         UnSigned_nb_true_divide,
        .nb_inplace_true_divide = (binaryfunc) UnSigned_nb_inplace_true_divide, 
        .nb_remainder           = (binaryfunc)         UnSigned_nb_remainder,
        .nb_inplace_remainder   = (binaryfunc) UnSigned_nb_inplace_remainder,
        .nb_or                  = (binaryfunc)         UnSigned_nb_or,
        .nb_inplace_or          = (binaryfunc) UnSigned_nb_inplace_or,
        .nb_and                 = (binaryfunc)         UnSigned_nb_and,
        .nb_inplace_and         = (binaryfunc) UnSigned_nb_inplace_and,
        .nb_xor                 = (binaryfunc)         UnSigned_nb_xor,
        .nb_inplace_xor         = (binaryfunc) UnSigned_nb_inplace_xor,
    },
},
UnUnsigned_impl = {
    .nb = {
        .nb_divmod              = (binaryfunc) 0,
        .nb_index               = (unaryfunc) UnUnsigned_nb_index,
        .nb_lshift              = (binaryfunc) UnUnsigned_nb_lshift,
        .nb_rshift              = (binaryfunc) UnUnsigned_nb_rshift,
        .nb_inplace_lshift      = (binaryfunc) UnUnsigned_nb_inplace_lshift,
        .nb_inplace_rshift      = (binaryfunc) UnUnsigned_nb_inplace_rshift,
        .nb_add                 = (binaryfunc)         UnUnsigned_nb_add,
        .nb_inplace_add         = (binaryfunc) UnUnsigned_nb_inplace_add,
        .nb_subtract            = (binaryfunc)         UnUnsigned_nb_subtract,
        .nb_inplace_subtract    = (binaryfunc) UnUnsigned_nb_inplace_subtract,
        .nb_multiply            = (binaryfunc)         UnUnsigned_nb_multiply,
        .nb_inplace_multiply    = (binaryfunc) UnUnsigned_nb_inplace_multiply,
        .nb_true_divide         = (binaryfunc)         UnUnsigned_nb_true_divide,
        .nb_inplace_true_divide = (binaryfunc) UnUnsigned_nb_inplace_true_divide, 
        .nb_remainder           = (binaryfunc)         UnUnsigned_nb_remainder,
        .nb_inplace_remainder   = (binaryfunc) UnUnsigned_nb_inplace_remainder,
        .nb_or                  = (binaryfunc)         UnUnsigned_nb_or,
        .nb_inplace_or          = (binaryfunc) UnUnsigned_nb_inplace_or,
        .nb_and                 = (binaryfunc)         UnUnsigned_nb_and,
        .nb_inplace_and         = (binaryfunc) UnUnsigned_nb_inplace_and,
        .nb_xor                 = (binaryfunc)         UnUnsigned_nb_xor,
        .nb_inplace_xor         = (binaryfunc) UnUnsigned_nb_inplace_xor,
    },
};

static PyObject *
unsys_float_info(PyObject *mod) {
    printf("FLT_RADIX:          %i\n", FLT_RADIX);
    printf("FLT_ROUNDS:         %i\n", FLT_ROUNDS);
    printf("FLT_EVAL_METHOD:    %i\n", FLT_EVAL_METHOD);
    
    printf("FLT_DECIMAL_DIG:    %i\n", FLT_DECIMAL_DIG);
    printf("FLT_MIN:            %g\n", FLT_MIN);
    printf("FLT_TRUE_MIN:       %g\n", FLT_TRUE_MIN);
    printf("FLT_MAX:            %g\n", FLT_MAX);
    printf("FLT_EPSILON:        %g\n", FLT_EPSILON);
    printf("FLT_DIG:            %i\n", FLT_DIG);
    printf("FLT_MANT_DIG:       %i\n", FLT_MANT_DIG);
    printf("FLT_MIN_EXP:        %i\n", FLT_MIN_EXP);
    printf("FLT_MIN_10_EXP:     %i\n", FLT_MIN_10_EXP);
    printf("FLT_MAX_EXP:        %i\n", FLT_MAX_EXP);
    printf("FLT_MAX_10_EXP:     %i\n", FLT_MAX_10_EXP);
    printf("FLT_HAS_SUBNORM:    %i\n", FLT_HAS_SUBNORM);
    printf("\n");
    printf("DBL_DECIMAL_DIG:    %i\n", DBL_DECIMAL_DIG);
    printf("DBL_MIN:            %g\n", DBL_MIN);
    printf("DBL_TRUE_MIN:       %g\n", DBL_TRUE_MIN);
    printf("DBL_MAX:            %g\n", DBL_MAX);
    printf("DBL_EPSILON:        %g\n", DBL_EPSILON);
    printf("DBL_DIG:            %i\n", DBL_DIG);
    printf("DBL_MANT_DIG:       %i\n", DBL_MANT_DIG);
    printf("DBL_MIN_EXP:        %i\n", DBL_MIN_EXP);
    printf("DBL_MIN_10_EXP:     %i\n", DBL_MIN_10_EXP);
    printf("DBL_MAX_EXP:        %i\n", DBL_MAX_EXP);
    printf("DBL_MAX_10_EXP:     %i\n", DBL_MAX_10_EXP);
    printf("DBL_HAS_SUBNORM:    %i\n", DBL_HAS_SUBNORM);
    printf("\n");
    printf("LDBL_DECIMAL_DIG:    %i\n", LDBL_DECIMAL_DIG);
    printf("LDBL_MIN:            %Lg\n", LDBL_MIN);
    printf("LDBL_TRUE_MIN:       %Lg\n", LDBL_TRUE_MIN);
    printf("LDBL_MAX:            %Lg\n", LDBL_MAX);
    printf("LDBL_EPSILON:        %Lg\n", LDBL_EPSILON);
    printf("LDBL_DIG:            %i\n", LDBL_DIG);
    printf("LDBL_MANT_DIG:       %i\n", LDBL_MANT_DIG);
    printf("LDBL_MIN_EXP:        %i\n", LDBL_MIN_EXP);
    printf("LDBL_MIN_10_EXP:     %i\n", LDBL_MIN_10_EXP);
    printf("LDBL_MAX_EXP:        %i\n", LDBL_MAX_EXP);
    printf("LDBL_MAX_10_EXP:     %i\n", LDBL_MAX_10_EXP);
    printf("LDBL_HAS_SUBNORM:    %i\n", LDBL_HAS_SUBNORM);
    Py_RETURN_NONE;
}
