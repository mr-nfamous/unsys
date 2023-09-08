
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

#define PY_SSIZE_T_CLEAN

#include   "Python.h"

static PyTypeObject TypeAttrDict_Type;

#include        "undecl.h"

#include    "unsys.h"
#include    "pyarg.h"
#include    "pyobject.h"

struct py_limits {
    PyObject 
        *   char_max, *   char_min,
        *  wchar_max, *  wchar_min,
        * char16_max,
        * char32_max,
        *   wint_max, *   wint_min,
                         *   bool_min, *    bool_max,
        *  schar_max, *  schar_min, *   uchar_max,
        *   shrt_max, *   shrt_min, *   ushrt_max,
        *    int_max, *    int_min, *    uint_max,
        *   long_max, *   long_min, *   ulong_max,
        *  llong_max, *  llong_min, *  ullong_max,
        *  ssize_max,                  *    size_max,
        * intptr_max, * intptr_min, * uintptr_max,
        *ptrdiff_max, *ptrdiff_min,
        *   int8_max, *   int8_min, *      uint8_max, 
        *  int16_max, *  int16_min, *     uint16_max,
        *  int32_max, *  int32_min, *     uint32_max,
        *  int64_max, *  int64_min, *     uint64_max,
        * intmax_max, * intmax_min, * uintmax_max;
};

static struct py_limits unsys_py_limits;

struct unsys_types {
#define unsys_bases      unsys.types.base
#define unsys_scalars    unsys_bases.scalars
#define unsys_objects    unsys_bases.objects
#define unsys_funcs      unsys_bases.funcs
#define unsys_chars      unsys_scalars.chars
#define unsys_reals      unsys_scalars.reals
#define unsys_ptrs       unsys_scalars.ptrs
#define unsys_wides      unsys_chars.wides
#define unsys_ints       unsys_reals.ints
#define unsys_bools      unsys_ints.bools
#define unsys_signeds    unsys_ints.signeds
#define unsys_unsigneds  unsys_ints.unsigneds
#define unsys_floats     unsys_reals.floats
#define unsys_unions     unsys_objects.unions
#define unsys_structs    unsys_objects.structs

#define         UnC_Meta    unsys.types.meta.C_
#define      UnVoid_Meta    unsys.types.meta.Void_
#define    UnScalar_Meta    unsys.types.meta.Scalar_
#define UnCharacter_Meta    unsys.types.meta.Character_
#define      UnWide_Meta    unsys.types.meta.Wide_
#define      UnReal_Meta    unsys.types.meta.Real_
#define  UnFloating_Meta    unsys.types.meta.Floating_
#define   UnInteger_Meta    unsys.types.meta.Integer_
#define   UnBoolean_Meta    unsys.types.meta.Boolean_
#define    UnSigned_Meta    unsys.types.meta.Signed_
#define  UnUnsigned_Meta    unsys.types.meta.Unsigned_
#define   UnPointer_Meta    unsys.types.meta.Pointer_
#define    UnObject_Meta    unsys.types.meta.Object_
#define     UnUnion_Meta    unsys.types.meta.Union_
#define    UnStruct_Meta    unsys.types.meta.Struct_
#define  UnFunction_Meta    unsys.types.meta.Function_

#define         UnC_Type    unsys_bases.C_
#define      UnVoid_Type    unsys_bases.Void_
#define    UnScalar_Type    unsys_scalars.Scalar_

#define UnCharacter_Type    unsys_chars.Character_
#define      UnChar_Type    unsys_chars.Char_
#define      UnWide_Type    unsys_chars.Wide_
#define     UnWchar_Type    unsys_chars.Wchar_
#define    UnChar16_Type    unsys_chars.Char16_
#define    UnChar32_Type    unsys_chars.Char32_

#define      UnReal_Type    unsys_reals.Real_

#define  UnFloating_Type    unsys_floats.Floating_
#define      UnHalf_Type    unsys_floats.Half_
#define     UnFloat_Type    unsys_floats.Float_
#define    UnDouble_Type    unsys_floats.Double_
#define   UnLdouble_Type    unsys_floats.Ldouble_

#define   UnInteger_Type    unsys_ints.Integer_
#define    UnBigInt_Type    unsys_ints.Big_
#define      UnWint_Type    unsys_ints.Wint_
#define UnSigAtomic_Type    unsys_ints.SigAtomic_

#define   UnBoolean_Type    unsys_bools.Boolean_
#define      UnBool_Type    unsys_bools.Bool_

#define    UnSigned_Type    unsys_signeds.Signed_
#define     UnSchar_Type    unsys_signeds.Schar_
#define     UnShort_Type    unsys_signeds.Short_
#define       UnInt_Type    unsys_signeds.Int_
#define      UnLong_Type    unsys_signeds.Long_
#define     UnLlong_Type    unsys_signeds.Llong_
#define     UnXlong_Type    unsys_signeds.Xlong_
#define     UnSsize_Type    unsys_signeds.Ssize_
#define    UnIntptr_Type    unsys_signeds.Intptr_
#define   UnPtrdiff_Type    unsys_signeds.Ptrdiff_
#define      UnInt8_Type    unsys_signeds.Int8_
#define     UnInt16_Type    unsys_signeds.Int16_
#define     UnInt32_Type    unsys_signeds.Int32_
#define     UnInt64_Type    unsys_signeds.Int64_

#define    UnIntmax_Type    unsys_signeds.Intmax_

#define  UnUnsigned_Type    unsys_unsigneds.Unsigned_
#define     UnUchar_Type    unsys_unsigneds.Uchar_
#define    UnUshort_Type    unsys_unsigneds.Ushort_
#define      UnUint_Type    unsys_unsigneds.Uint_
#define     UnUlong_Type    unsys_unsigneds.Ulong_
#define    UnUllong_Type    unsys_unsigneds.Ullong_
#define    UnUxlong_Type    unsys_unsigneds.Uxlong_
#define      UnSize_Type    unsys_unsigneds.Size_
#define   UnUintptr_Type    unsys_unsigneds.Uintptr_
#define     UnUint8_Type    unsys_unsigneds.Uint8_
#define    UnUint16_Type    unsys_unsigneds.Uint16_
#define    UnUint32_Type    unsys_unsigneds.Uint32_
#define    UnUint64_Type    unsys_unsigneds.Uint64_
#define   UnUintmax_Type    unsys_unsigneds.Uintmax_

#define   UnPointer_Type    unsys_ptrs.Pointer_

#define    UnObject_Type    unsys_objects.Object_
#define     UnUnion_Type    unsys_objects.Union_
#define    UnStruct_Type    unsys_objects.Struct_

#define  UnFunction_Type    unsys_funcs.Function_

    /* DO NOT REORDER */

    struct unsys_meta_types {
        PyTypeObject
            C_,         /* tp_base = PyType_Type        */
            Void_,      /* tp_base = UnC_Meta           */
            Scalar_,    /* tp_base = UnC_Meta           */
            Pointer_,   /* tp_base = UnScalar_Meta      */
            Address_,   /* tp_base = Pointer_Meta       */
            Character_, /* tp_base = UnScalar_Meta      */
            Wide_,      /* tp_base = UnCharacter_Meta   */
            Real_,      /* tp_base = UnScalar_Meta      */
            Floating_,  /* tp_base = UnReal_Meta        */
            Integer_,   /* tp_base = UnReal_Meta        */
            Boolean_,   /* tp_base = UnInteger_Meta     */
            Signed_,    /* tp_base = UnInteger_Meta     */
            Unsigned_,  /* tp_base = UnInteger_Meta     */
            Object_,    /* tp_base = UnC_Meta           */
            Union_,     /* tp_base = UnObject_Meta      */
            Struct_,    /* tp_base = UnObject_Meta      */
            Function_;  /* tp_base = UnC_Meta           */
    } meta;

    struct unsys_base_types {
        PyTypeObject C_;
        PyTypeObject Void_;
        struct unsys_scalar_types {
            PyTypeObject Scalar_;
            struct unsys_ptr_types {
                PyTypeObject Pointer_;
                PyTypeObject Addr_;         /*  AS_ADDR */
                PyTypeObject AddrPointer_;  /*  AS_ADDRPTR */
            } ptrs;
            struct unsys_char_types {
                PyTypeObject Character_;
                PyTypeObject Char_;         /*  AS_CHAR */
                struct unsys_wide_char_types {
                    PyTypeObject Wide_;
                    PyTypeObject Wchar_;    /*  AS_WCHAR */
                    PyTypeObject Char16_;   /*  AS_CHAR16 */
                    PyTypeObject Char32_;   /*  AS_CHAR32 */
                } wides;
            } chars;
            struct unsys_real_types {
                PyTypeObject Real_;
                struct unsys_floating_types {
                    PyTypeObject Floating_;
                    PyTypeObject Half_;         /* AS_HALF  */
                    PyTypeObject Float_;        /* AS_FLT   */
                    PyTypeObject Double_;       /* AS_DBL   */
                    PyTypeObject Ldouble_;      /* AS_LDBL  */
                } floats;
                struct unsys_int_types {
                    PyTypeObject Integer_;
                    struct unsys_boolean_types {
                        PyTypeObject Boolean_;
                        PyTypeObject Bool_;     /* AS_BOOL      */
                    } bools;
                    struct unsys_signed_int_types {
                        PyTypeObject Signed_;
                        PyTypeObject Schar_;    /* AS_SCHAR     */
                        PyTypeObject Short_;    /* AS_SHORT     */
                        PyTypeObject Int_;      /* AS_INT       */
                        PyTypeObject Long_;     /* AS_LONG      */
                        PyTypeObject Llong_;    /* AS_LLONG     */
                        PyTypeObject Xlong_;    /* AS_XLONG     */
                        PyTypeObject Ssize_;    /* AS_SSIZE     */
                        PyTypeObject Intptr_;   /* AS_INTPTR    */
                        PyTypeObject Ptrdiff_;  /* AS_PTRDIFF   */
                        PyTypeObject Int8_;     /* AS_INT8      */
                        PyTypeObject Int16_;    /* AS_INT16     */
                        PyTypeObject Int32_;    /* AS_INT32     */
                        PyTypeObject Int64_;    /* AS_INT64     */
                        PyTypeObject Intmax_;   /* AS_INTMAX    */
                    } signeds;
                    struct unsys_unsigned_int_types {
                        PyTypeObject Unsigned_;
                        PyTypeObject Uchar_;    /* AS_UCHAR     */
                        PyTypeObject Ushort_;   /* AS_USHORT    */
                        PyTypeObject Uint_;     /* AS_UINT      */
                        PyTypeObject Ulong_;    /* AS_ULONG     */
                        PyTypeObject Ullong_;   /* AS_ULLONG    */
                        PyTypeObject Uxlong_;   /* AS_UXLONG    */
                        PyTypeObject Size_;     /* AS_SIZE      */
                        PyTypeObject Uintptr_;  /* AS_UINTPTR   */
                        PyTypeObject Uint8_;    /* AS_UINT8     */
                        PyTypeObject Uint16_;   /* AS_UINT16    */
                        PyTypeObject Uint32_;   /* AS_UINT32    */
                        PyTypeObject Uint64_;   /* AS_UINT64    */
                        PyTypeObject Uintmax_;  /* AS_UINTMAX   */
                    } unsigneds;
                    PyTypeObject Wint_;         /* AS_WINT      */
                    PyTypeObject SigAtomic_;    /* AS_SIG_ATOMIC */
                    PyTypeObject BigInt_;       /* AS_BIGINT    */
                } ints;
            } reals;
        } scalars;
        struct unsys_object_types {
            PyTypeObject UnObject_;
            struct unsys_union_types {
                PyTypeObject UnUnion_;
            } unions;
            struct unsys_struct_types {
                PyTypeObject UnStruct_;
            } structs;
        } objects;
        struct unsys_function_types {
            PyTypeObject Function_;
        } funcs;
        PyTypeObject reserved_1;
    } base;

};

struct unsys_enums {
    PyObject *AS_[AS_T_MAX];
    PyObject *NB_RANK_[NB_RANK_MAX];
    PyObject *nb_signed, *nb_signless, *nb_unsigned;
};

static struct unsys {
    /*
    CPython privately caches [-5..256]. We extend the range to
    [-128..256]
    */
    PyObject *ints_tuple;
    PyObject **ints;
    struct {
        struct py_limits *py;
        struct unsys_limits *c;
    } limits; 
    struct unsys_types types;
    struct unsys_enums enums;
    PyObject *ctypes;
} unsys = {
    .types = {
        .meta = {
            .C_ = {
                PyVarObject_HEAD_INIT(NULL, 0)
                .tp_name = "unsys.CMeta",
                .tp_base = &PyType_Type,
                .tp_flags= (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
            },
            .Void_ = {
                PyVarObject_HEAD_INIT(NULL, 0)
                .tp_name = "unsys.VoidMeta",
                .tp_base = &unsys.types.meta.C_,
                .tp_flags = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
            },
            .Scalar_ = {
                PyVarObject_HEAD_INIT(NULL, 0)
                .tp_name = "unsys.ScalarMeta",
                .tp_base = &UnC_Meta,
                .tp_flags = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
            },
            .Character_ = {
                PyVarObject_HEAD_INIT(NULL, 0)
                .tp_name = "unsys.CharacterMeta",
                .tp_base = &UnScalar_Meta,
                .tp_flags = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
            },
            .Wide_ = {
                PyVarObject_HEAD_INIT(NULL, 0)
                .tp_name = "unsys.WideMeta",
                .tp_base = &UnCharacter_Meta,
                .tp_flags = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
            },
            .Real_ = {
                PyVarObject_HEAD_INIT(NULL, 0)
                .tp_name = "unsys.RealMeta",
                .tp_base = &UnScalar_Meta,
                .tp_flags = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
            },
            .Floating_ = {
                PyVarObject_HEAD_INIT(NULL, 0)
                .tp_name = "unsys.FloatingMeta",
                .tp_base = &UnReal_Meta,
                .tp_flags = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
            },
            
            .Integer_ = {
                PyVarObject_HEAD_INIT(NULL, 0)
                .tp_name = "unsys.IntegerMeta",
                .tp_base = &UnReal_Meta,
                .tp_flags = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
            },
            .Boolean_ = {
                PyVarObject_HEAD_INIT(NULL, 0)
                .tp_name = "unsys.BooleanMeta",
                .tp_base = &UnInteger_Meta,
                .tp_flags = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
            },
            .Signed_ = {
                PyVarObject_HEAD_INIT(NULL, 0)
                .tp_name = "unsys.SignedMeta",
                .tp_base = &UnInteger_Meta,
                .tp_flags = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
            },
            .Unsigned_ = {
                PyVarObject_HEAD_INIT(NULL, 0)
                .tp_name = "unsys.UnsignedMeta",
                .tp_base = &UnInteger_Meta,
                .tp_flags = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
            },
            .Pointer_ = {
                PyVarObject_HEAD_INIT(NULL, 0)
                .tp_name = "unsys.PointerMeta",
                .tp_base = &UnScalar_Meta,
                .tp_flags = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
            },
            .Object_ = {
                PyVarObject_HEAD_INIT(NULL, 0)
                .tp_name = "unsys.ObjectMeta",
                .tp_base = &UnC_Meta,
                .tp_flags = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
            },
            .Union_ = {
                PyVarObject_HEAD_INIT(NULL, 0)
                .tp_name = "unsys.UnionMeta",
                .tp_base = &UnObject_Meta,
                .tp_flags = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
            },
            .Struct_ = {
                PyVarObject_HEAD_INIT(NULL, 0)
                .tp_name = "unsys.StructMeta",
                .tp_base = &UnObject_Meta,
                .tp_flags = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
            },
            .Function_ = {
                PyVarObject_HEAD_INIT(NULL, 0)
                .tp_name = "unsys.FunctionMeta",
                .tp_base = &UnC_Meta,
                .tp_flags = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
            },
        },
    },
};


#include        "pylong.h"
#include       "pybytes.h"
#include   "pybytearray.h"
#include     "pyunicode.h"
#include      "pyctypes.h"



/*
static PyObject *UnPointer_IMPL(PyTypeObject *, UnChar *);
static PyObject *   UnChar_IMPL(PyTypeObject *, UnChar *);
static PyObject *  UnWchar_IMPL(PyTypeObject *, UnChar *);
static PyObject * UnChar16_IMPL(PyTypeObject *, UnChar *);
static PyObject * UnChar32_IMPL(PyTypeObject *, UnChar *);
static PyObject *  UnSchar_IMPL(PyTypeObject *, UnChar *);
static PyObject * UnFloat_IMPL(PyTypeObject *, UnChar *);
static PyObject * UnDouble_IMPL(PyTypeObject *, UnChar *);

static PyObject *  UnShort_IMPL(PyTypeObject *, UnChar *);
static PyObject *    UnInt_IMPL(PyTypeObject *, UnChar *);
static PyObject *   UnLong_IMPL(PyTypeObject *, UnChar *);
static PyObject *  UnLlong_IMPL(PyTypeObject *, UnChar *);
static PyObject *  UnSsize_IMPL(PyTypeObject *, UnChar *);
static PyObject * UnIntptr_IMPL(PyTypeObject *, UnChar *);
static PyObject *UnPtrdiff_IMPL(PyTypeObject *, UnChar *);
static PyObject *   UnInt8_IMPL(PyTypeObject *, UnChar *);
static PyObject *  UnInt16_IMPL(PyTypeObject *, UnChar *);
static PyObject *  UnInt32_IMPL(PyTypeObject *, UnChar *);
static PyObject *  UnInt64_IMPL(PyTypeObject *, UnChar *);
static PyObject * UnIntmax_IMPL(PyTypeObject *, UnChar *);
static PyObject *  UnUchar_IMPL(PyTypeObject *, UnChar *);
static PyObject * UnUshort_IMPL(PyTypeObject *, UnChar *);
static PyObject *   UnUint_IMPL(PyTypeObject *, UnChar *);
static PyObject *  UnUlong_IMPL(PyTypeObject *, UnChar *);
static PyObject * UnUllong_IMPL(PyTypeObject *, UnChar *);
static PyObject *   UnSize_IMPL(PyTypeObject *, UnChar *);
static PyObject * UnUintpr_IMPL(PyTypeObject *, UnChar *);
static PyObject *  UnUint8_IMPL(PyTypeObject *, UnChar *);
static PyObject * UnUint16_IMPL(PyTypeObject *, UnChar *);
static PyObject * UnUint32_IMPL(PyTypeObject *, UnChar *);
static PyObject * UnUint64_IMPL(PyTypeObject *, UnChar *);
static PyObject *UnUintmax_IMPL(PyTypeObject *, UnChar *);
static PyObject *   UnWint_IMPL(PyTypeObject *, UnChar *);

static 
union UnC_reinterpret {
    void *list[AS_BLTN_MAX];
    struct {
        void *(*to_void)        (PyTypeObject *, UnChar *);
        void *(*to_addr)        (PyTypeObject *, UnChar *);
        void *(*to_addrptr)     (PyTypeObject *, UnChar *);
        void *(*to_char)        (PyTypeObject *, UnChar *);

        void *(*to_wchar)       (PyTypeObject *, UnChar *);
        void *(*to_char16)      (PyTypeObject *, UnChar *);
        void *(*to_char32)      (PyTypeObject *, UnChar *);

        void *(*as_half)        (PyTypeObject *, UnChar *);
        void *(*to_flt)         (PyTypeObject *, UnChar *);
        void *(*to_dbl)         (PyTypeObject *, UnChar *);
        void *(*to_ldbl)        (PyTypeObject *, UnChar *);
        void *(*to_bigflt)      (PyTypeObject *, UnChar *);

        void *(*to_bool)        (PyTypeObject *, UnChar *);

        void *(*to_schar)       (PyTypeObject *, UnChar *);
        void *(*to_short)       (PyTypeObject *, UnChar *);
        void *(*to_int)         (PyTypeObject *, UnChar *);
        void *(*to_long)        (PyTypeObject *, UnChar *);
        void *(*to_llong)       (PyTypeObject *, UnChar *);
        void *(*to_xlong)       (PyTypeObject *, UnChar *);
        void *(*to_ssize)       (PyTypeObject *, UnChar *);
        void *(*to_intptr)      (PyTypeObject *, UnChar *);
        void *(*to_ptrdiff)     (PyTypeObject *, UnChar *);
        void *(*to_int8)        (PyTypeObject *, UnChar *);
        void *(*to_int16)       (PyTypeObject *, UnChar *);
        void *(*to_int32)       (PyTypeObject *, UnChar *);
        void *(*to_int64)       (PyTypeObject *, UnChar *);
        void *(*to_intmax)      (PyTypeObject *, UnChar *);

        void *(*to_uchar)       (PyTypeObject *, UnChar *);
        void *(*to_ushort)      (PyTypeObject *, UnChar *);
        void *(*to_uint)        (PyTypeObject *, UnChar *);
        void *(*to_ulong)       (PyTypeObject *, UnChar *);
        void *(*to_ullong)      (PyTypeObject *, UnChar *);
        void *(*as_uxlong)      (PyTypeObject *, UnChar *);
        void *(*to_size)        (PyTypeObject *, UnChar *);
        void *(*to_uintptr)     (PyTypeObject *, UnChar *);
        void *(*to_uint8)       (PyTypeObject *, UnChar *);
        void *(*to_uint16)      (PyTypeObject *, UnChar *);
        void *(*to_uint32)      (PyTypeObject *, UnChar *);
        void *(*to_uint64)      (PyTypeObject *, UnChar *);
        void *(*to_uintmax)     (PyTypeObject *, UnChar *);
        void *(*to_wint)        (PyTypeObject *, UnChar *);
        void *(*to_sig_atomic)  (PyTypeObject *, UnChar *);
        void *(*to_bigint)      (PyTypeObject *, UnChar *);
    };
} UnC_reinterpret = {
    .list = {
        [AS_ADDR]       = UnPointer_IMPL,
        [AS_ADDRPTR]    = 0,
        [AS_CHAR]       = UnChar_IMPL,
        [AS_WCHAR]      = UnWchar_IMPL,
        [AS_CHAR16]     = UnChar16_IMPL,
        [AS_CHAR32]     = UnChar32_IMPL,
        [AS_FLT]        = UnFloat_IMPL,
        [AS_DBL]        = UnDouble_IMPL,
        [AS_SCHAR]      = UnSchar_IMPL,
        [AS_SHRT]       = UnShort_IMPL,
        [AS_INT]        = UnInt_IMPL,
        [AS_LONG]       = UnLong_IMPL,
        [AS_LLONG]      = UnLlong_IMPL,
        [AS_SSIZE]      = UnSsize_IMPL,
        [AS_INTPTR]     = UnIntptr_IMPL,
        [AS_PTRDIFF]    = UnPtrdiff_IMPL,
        [AS_INT8]       = UnInt8_IMPL,
        [AS_INT16]      = UnInt16_IMPL,
        [AS_INT32]      = UnInt32_IMPL,
        [AS_INT64]      = UnInt64_IMPL,
        [AS_INTMAX]     = UnIntmax_IMPL,
        [AS_UCHAR]      = UnUchar_IMPL,
        [AS_USHRT]      = UnUshort_IMPL,
        [AS_UINT]       = UnUint_IMPL,
        [AS_ULONG]      = UnUlong_IMPL,
        [AS_ULLONG]     = UnLlong_IMPL,
        [AS_SIZE]       = UnSize_IMPL,
        [AS_UINTPTR]    = UnIntptr_IMPL,
        [AS_UINT8]      = UnInt8_IMPL,
        [AS_UINT16]     = UnUint16_IMPL,
        [AS_UINT32]     = UnUint32_IMPL,
        [AS_UINT64]     = UnUint64_IMPL,
        [AS_UINTMAX]    = UnUintmax_IMPL,
        [AS_WINT]       = UnWint_IMPL,
        [AS_BIGINT]     = 0,
    },
};
*/

/*
static inline PyObject *
UnScalar_CAST_SCHAR(const void *val, PyTypeObject *cls, int as) {
    PyObject *obj;
    switch (as) {
        case AS_SCHAR: {
            obj = py_NEW_OBJ(cls);
            Schar_
        }
    }
}
static PyObject *
UnSigned_CAST(UnChar *obj, PyTypeObject *cls) {
    TypeAttrDict *dst = (TypeAttrDict *) cls->tp_dict;
    TypeAttrDict *src = UnC_GET_INFO(obj);
    switch (src->info->t_rank) {
        case CHAR_RANK: {
            
            switch (dst->t_rank) {
                case BOOL_RANK: {
                    return UnBool_NEW(&UnBool_Type, )
                }
            }
            tmp = UnSchar_GET(obj); break;
        case SHRT_RANK: tmp = UnShort_GET(obj); break;
        case INT_RANK: tmp = UnInt_GET(obj); break;
        case LONG_RANK: tmp = UnLong_GET(obj); break;
        case LLONG_RANK: tmp = UnLlong_GET(obj); break;
        default: Py_UNREACHABLE();
    }
    switch (dst)
    switch(dst->info->t_rank) {
        case BOOL_RANK: {
            switch (src->info)
        }
    }
}
*/
/*
static inline PyObject *
UnC_CAST(PyTypeObject *dst, UnChar *src) {
    TypeAttrDict *dtype = ((TypeAttrDict *) dst->tp_dict);
    TypeAttrDict *stype = UnC_TAD(src);
    const int type = dtype->info->t_as;
    union unsys_as *conv = stype->conv;
    if (conv->list[type] == NULL) {
        error:{
            return unsys_UNDEFINED_CAST(
                dtype->info->t_name,
                stype->info->t_name
            );
        }
    }
    switch (type) {
        case AS_VOID:   break;
        case AS_CHAR:   return UnChar_NEW(dst, conv->to_int(src));
        case AS_WCHAR:  return UnWchar_NEW(dst, conv->to_wchar(src));
        case AS_CHAR16: return UnChar32_NEW(dst, conv->to_char16(src));
        case AS_CHAR32: return UnChar32_NEW(dst, conv->to_char32(src));
        case AS_FLT:    return UnFloat_NEW(dst, conv->to_flt(src));
        case AS_DBL:    return UnDouble_NEW(dst, conv->to_dbl(src));
        case AS_BOOL:   return   UnInt_NEW(dst, conv->to_bool(src));
        case AS_SCHAR:  return UnSchar_NEW(dst, conv->to_schar(src));
        case AS_SHRT:   return UnShort_NEW(dst, conv->to_short(src));
        case AS_INT:    return   UnInt_NEW(dst, conv->to_int(src));
        case AS_LONG:   return  UnLong_NEW(dst, conv->to_long(src));
        case AS_LLONG:  return UnLlong_NEW(dst, conv->to_llong(src));
    }
    goto error;
}
*/


static inline bool
unsys_ADD_ABC(PyObject *mod, PyTypeObject *cls) {
    if (PyType_Ready(cls) < 0) {
        return 1;
    }
    if (PyModule_AddType(mod, cls) < 0) {
        return 1;
    }
    return 0;
}

static inline bool
unsys_INIT_ABCS(PyObject *mod) {
    if (PyType_Ready(&UnEnum_Type) < 0) {
        return 1;
    }
    if (PyType_Ready(&UnIntEnum_Type) < 0) {
        return 1;
    }
    PyObject **ec = unsys.enums.AS_;
    if (
        unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_ADDRPTR])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_VOID])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_ADDR])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_ADDRPTR])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_HALF])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_FLT])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_DBL])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_LDBL])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_BIGFLT])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_CHAR])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_WCHAR])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_CHAR16])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_CHAR32])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_BOOL])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_SCHAR])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_SHRT])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_INT])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_LONG])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_LLONG])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_XLONG])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_SSIZE])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_INTPTR])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_PTRDIFF])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_INT8])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_INT16])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_INT32])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_INT64])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_INTMAX])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_UCHAR])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_USHRT])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_UINT])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_ULONG])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_ULLONG])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_UXLONG])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_SIZE])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_UINTPTR])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_UINT8])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_UINT16])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_UINT32])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_UINT64])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_UINTMAX])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_WINT])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_as_enums[AS_BIGINT])
    ) {return 1;}

    ec = unsys.enums.NB_RANK_;
    if (
        unsys_ADD_ENUM(mod, ec, &unsys_rank_enums[NB_RANK_0])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_rank_enums[NB_RANK_1])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_rank_enums[NB_RANK_2])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_rank_enums[NB_RANK_3])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_rank_enums[NB_RANK_4])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_rank_enums[NB_RANK_5])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_rank_enums[NB_RANK_6])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_rank_enums[NB_RANK_7])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_rank_enums[NB_RANK_8])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_rank_enums[NB_RANK_9])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_rank_enums[NB_RANK_A])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_rank_enums[NB_RANK_B])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_rank_enums[NB_RANK_C])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_rank_enums[NB_RANK_D])
    ||  unsys_ADD_ENUM(mod, ec, &unsys_rank_enums[NB_RANK_E])
    ) { return 1; }
    PyObject **li = (PyObject *[]){
        unsys_DEF_ENUM(
            &unsys.enums.           nb_signed,
            &unsys_signedness_enums.nb_signed
        ),
        unsys_DEF_ENUM(
            &unsys.enums.           nb_unsigned,
            &unsys_signedness_enums.nb_unsigned
        ),
        unsys_DEF_ENUM(
            &unsys.enums.           nb_signless,
            &unsys_signedness_enums.nb_signless
        ),
    };
    if (
        (PyModule_AddObject(mod, "NB_SIGNED", li[0]) < 0)
    ||  (PyModule_AddObject(mod, "NB_UNSIGNED", li[1]) < 0)
    ||  (PyModule_AddObject(mod, "NB_SIGNLESS", li[2]) < 0)
    ) { return 1; }


    TypeAttrDict_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(NULL, 0)
        .tp_name        = "unsys.TypeAttrDict",
        .tp_basicsize   = sizeof(TypeAttrDict),
        .tp_base        = &PyDict_Type,
        .tp_dealloc     = (destructor) TypeAttrDict_dealloc,
        .tp_init        = (initproc) TypeAttrDict_init,
        .tp_getattro    = PyObject_GenericGetAttr,
        .tp_getset      = TypeAttrDict_impl.gs,
    };
    
    if (PyType_Ready(&TypeAttrDict_Type) < 0) {
        return 1;
    }

    if (PyModule_AddType(mod, &TypeAttrDict_Type) < 0) {
        return 1;
    }
/*
    UnC_Meta = (PyTypeObject){
        PyVarObject_HEAD_INIT(NULL, 0)
        .tp_name = "unsys.CMeta",
        .tp_base = &PyType_Type,
        .tp_flags= (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
    };
    UnVoid_Meta = (PyTypeObject){
    };

    UnScalar_Meta = (PyTypeObject){
    };
*/
    UnScalar_Meta.tp_getset = UnScalarMeta_impl.gs;
    if (unsys_ADD_ABC(mod, &UnC_Meta)) return 1;
    if (unsys_ADD_ABC(mod, &UnVoid_Meta)) return 1;
    if (unsys_ADD_ABC(mod, &UnScalar_Meta)) return 1;
    if (unsys_ADD_ABC(mod, &UnCharacter_Meta)) return 1;
    if (unsys_ADD_ABC(mod, &UnWide_Meta)) return 1;
    if (unsys_ADD_ABC(mod, &UnReal_Meta)) return 1;
    if (unsys_ADD_ABC(mod, &UnReal_Meta)) return 1;
    if (unsys_ADD_ABC(mod, &UnInteger_Meta)) return 1;
    if (unsys_ADD_ABC(mod, &UnBoolean_Meta)) return 1;
    if (unsys_ADD_ABC(mod, &UnSigned_Meta)) return 1;
    if (unsys_ADD_ABC(mod, &UnUnsigned_Meta)) return 1;
    if (unsys_ADD_ABC(mod, &UnPointer_Meta)) return 1;
    if (unsys_ADD_ABC(mod, &UnObject_Meta)) return 1;
    if (unsys_ADD_ABC(mod, &UnUnion_Meta)) return 1;
    if (unsys_ADD_ABC(mod, &UnStruct_Meta)) return 1;;
    if (unsys_ADD_ABC(mod, &UnFunction_Meta)) return 1;
    UnC_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnC_Meta, 0)
        .tp_name = "unsys.CType",
        .tp_flags = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
    };
    if (unsys_ADD_ABC(mod, &UnC_Type)) return 1;

    UnVoid_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnVoid_Meta, 0)
        .tp_name = "unsys.Void",
        .tp_base = &UnC_Type,
        .tp_dict = TypeAttrDict_NEW(),
        .tp_flags = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
    };
    if (unsys_ADD_ABC(mod, &UnVoid_Type)) return 1;

#define UnC_IMPL_FOOT \
        .tp_as_number   = &impl->nb,\
        .tp_as_sequence = &impl->sq,\
        .tp_as_mapping  = &impl->mp,\
        .tp_as_buffer   = &impl->bf,\
        .tp_methods     = impl->ml,\
        .tp_getset      = impl->gs,

    UnCImpl *impl = &UnScalar_impl;
    
    UnScalar_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnScalar_Meta, 0)
        .tp_name        = "unsys.Scalar",
        .tp_base        = &UnC_Type,
        .tp_flags       = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
        .tp_dealloc     = UnScalar_dealloc,
        .tp_free        = PyMem_Free,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnScalar_Type)) return 1;
    
    impl = &UnReal_impl;
    UnReal_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnReal_Meta, 0)
        .tp_name        = "unsys.Real",
        .tp_base        = &UnScalar_Type,
        .tp_flags       = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
        .tp_new         = (newfunc) UnReal_new,
        .tp_repr        = (reprfunc) UnReal_repr,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnReal_Type)) return 1;
    
    impl = &UnFloating_impl;
    UnFloating_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnFloating_Meta, 0)
        .tp_name    = "unsys.Floating",
        .tp_base    = &UnReal_Type,
        .tp_flags   = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnFloating_Type)) return 1;

    impl = &UnInteger_impl;
    UnInteger_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnInteger_Meta, 0)
        .tp_name        = "unsys.Integer",
        .tp_base        = &UnReal_Type,
        .tp_flags       = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnInteger_Type)) return 1;

    impl = &UnBoolean_impl;
    UnBoolean_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnBoolean_Meta, 0)
        .tp_name    = "unsys.Boolean",
        .tp_base    = &UnInteger_Type,
        .tp_flags   = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
        
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnBoolean_Type)) return 1;

    impl = &UnSigned_impl;
    UnSigned_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnSigned_Meta, 0)
        .tp_name        = "unsys.Signed",
        .tp_base        = &UnInteger_Type,
        .tp_flags       = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
        .tp_richcompare = (void *) UnSigned_richcompare,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnSigned_Type)) return 1;

    impl = &UnUnsigned_impl;
    UnUnsigned_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnUnsigned_Meta, 0)
        .tp_name        = "unsys.Unsigned",
        .tp_base        = &UnInteger_Type,
        .tp_flags       = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
        .tp_richcompare = (void *) UnUnsigned_richcompare,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnUnsigned_Type)) return 1;
    
    TypeAttrDict *dict;

    impl = &UnSchar_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_SCHAR;
    dict->conv = impl->as;
    UnSchar_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnSigned_Meta, 0)
        .tp_name        = "unsys.c_schar",
        .tp_basicsize   = sizeof(UnChar),
        .tp_base        = &UnSigned_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnSchar_Type)) return 1;

    impl = &UnShort_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_SHRT;
    dict->conv = impl->as;
    UnShort_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnSigned_Meta, 0)
        .tp_name        = "unsys.c_short",
        .tp_basicsize   = sizeof(UnShort),
        .tp_base        = &UnSigned_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnShort_Type)) return 1;

    impl = &UnInt_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_INT;
    dict->conv = impl->as;
    TypeAttrDict_SET_VGET(dict, pylong_rdi);
    UnInt_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnSigned_Meta, 0)
        .tp_name        = "unsys.c_int",
        .tp_basicsize   = sizeof(UnInt),
        .tp_base        = &UnSigned_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnInt_Type)) return 1;

    impl = &UnLong_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_LONG;
    dict->conv = impl->as;
    UnLong_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnSigned_Meta, 0)
        .tp_name        = "unsys.c_long",
        .tp_basicsize   = sizeof(UnLong),
        .tp_base        = &UnSigned_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnLong_Type)) return 1;

    impl = &UnLlong_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_LLONG;
    dict->conv = impl->as;
    UnLlong_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnSigned_Meta, 0)
        .tp_name        = "unsys.c_llong",
        .tp_basicsize   = sizeof(UnLlong),
        .tp_base        = &UnSigned_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnLlong_Type)) return 1;

    impl = &UnSsize_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_SSIZE;
    dict->conv = impl->as;
    UnSsize_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnSigned_Meta, 0)
        .tp_name        = "unsys.c_ssize",
        .tp_basicsize   = sizeof(UnSize),
        .tp_base        = &UnSigned_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnSsize_Type)) return 1;

    impl = &UnIntptr_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_INTPTR;
    dict->conv = impl->as;
    UnIntptr_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnSigned_Meta, 0)
        .tp_name        = "unsys.c_intptr",
        .tp_basicsize   = sizeof(UnIntptr),
        .tp_base        = &UnSigned_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnIntptr_Type)) return 1;

    impl = &UnPtrdiff_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_PTRDIFF;
    dict->conv = impl->as;
    UnPtrdiff_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnSigned_Meta, 0)
        .tp_name = "unsys.c_ptrdiff",
        .tp_basicsize = sizeof(UnPtrdiff),
        .tp_base      = &UnSigned_Type,
        .tp_dict      = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnPtrdiff_Type)) return 1;

    impl = &UnInt8_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_INT8;
    dict->conv = impl->as;
    UnInt8_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnSigned_Meta, 0)
        .tp_name = "unsys.c_int8",
        .tp_basicsize = sizeof(UnInt8),
        .tp_base      = &UnSigned_Type,
        .tp_dict      = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnInt8_Type)) return 1;

    impl = &UnInt16_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_INT16;
    dict->conv = impl->as;
    UnInt16_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnSigned_Meta, 0)
        .tp_name        = "unsys.c_int16",
        .tp_basicsize =  sizeof(UnInt16),
        .tp_base        = &UnSigned_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnInt16_Type)) return 1;

    impl = &UnInt32_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_INT32;
    dict->conv = impl->as;
    UnInt32_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnSigned_Meta, 0)
        .tp_name        = "unsys.c_int32",
        .tp_basicsize   = sizeof(UnInt32),
        .tp_base        = &UnSigned_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnInt32_Type)) return 1;

    impl = &UnInt64_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_INT64;
    dict->conv = impl->as;
    UnInt64_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnSigned_Meta, 0)
        .tp_name        = "unsys.c_int64",
        .tp_basicsize   = sizeof(UnInt64),
        .tp_base        = &UnSigned_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnInt64_Type)) return 1;

    impl = &UnIntmax_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_INTMAX;
    dict->conv = impl->as;
    UnIntmax_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnSigned_Meta, 0)
        .tp_name        = "unsys.c_intmax",
        .tp_basicsize   = sizeof(UnIntmax),
        .tp_base        = &UnSigned_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnIntmax_Type)) return 1;

    impl = &UnBool_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_BOOL;
    dict->conv = impl->as;
    UnBool_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnBoolean_Meta, 0)
        .tp_name        = "unsys.c_bool",
        .tp_basicsize   = sizeof(UnBool),
        .tp_base        = &UnBoolean_Type,
        .tp_dict        = (PyObject *) dict,
        .tp_flags       = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnBool_Type)) return 1;

    impl = &UnUchar_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_UCHAR;
    dict->conv = impl->as;
    UnUchar_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnUnsigned_Meta, 0)
        .tp_name        = "unsys.c_uchar",
        .tp_basicsize   = sizeof(UnChar),
        .tp_base        = &UnUnsigned_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnUchar_Type)) return 1;

    impl = &UnUshort_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_USHRT;
    dict->conv = impl->as;
    UnUshort_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnUnsigned_Meta, 0)
        .tp_name        = "unsys.c_ushort",
        .tp_basicsize   = sizeof(UnShort),
        .tp_base        = &UnUnsigned_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnUshort_Type)) return 1;

    impl = &UnUint_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_UINT;
    dict->conv = impl->as;
    UnUint_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnUnsigned_Meta, 0)
        .tp_name        = "unsys.c_uint",
        .tp_basicsize   = sizeof(UnInt),
        .tp_base        = &UnUnsigned_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnUint_Type)) return 1;

    impl = &UnUlong_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_ULONG;
    dict->conv = impl->as;
    UnUlong_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnUnsigned_Meta, 0)
        .tp_name        = "unsys.c_ulong",
        .tp_basicsize   = sizeof(UnLong),
        .tp_base        = &UnUnsigned_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnUlong_Type)) return 1;

    impl = &UnUllong_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_ULLONG;
    dict->conv = impl->as;
    UnUllong_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnUnsigned_Meta, 0)
        .tp_name        = "unsys.c_ullong",
        .tp_basicsize   = sizeof(UnLlong),
        .tp_base        = &UnUnsigned_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnUllong_Type)) return 1;

    impl = &UnSize_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_SIZE;
    dict->conv = impl->as;
    UnSize_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnUnsigned_Meta, 0)
        .tp_name        = "unsys.c_size",
        .tp_basicsize   = sizeof(UnSize),
        .tp_base        = &UnUnsigned_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnSize_Type)) return 1;

    impl = &UnUintptr_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_UINTPTR;
    dict->conv = impl->as;
    UnUintptr_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnSigned_Meta, 0)
        .tp_name        = "unsys.c_uintptr",
        .tp_basicsize   = sizeof(UnIntptr),
        .tp_base        = &UnSigned_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnUintptr_Type)) return 1;

    impl = &UnUint8_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_UINT8;
    dict->conv = impl->as;
    UnUint8_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnUnsigned_Meta, 0)
        .tp_name        = "unsys.c_uint8",
        .tp_basicsize   = sizeof(UnInt8),
        .tp_base        = &UnUnsigned_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnUint8_Type)) return 1;

    impl = &UnUint16_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_UINT16;
    dict->conv = impl->as;
    UnUint16_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnUnsigned_Meta, 0)
        .tp_name        = "unsys.c_uint16",
        .tp_basicsize   = sizeof(UnInt16),
        .tp_base        = &UnUnsigned_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnUint16_Type)) return 1;

    impl = &UnUint32_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_UINT32;
    dict->conv = impl->as;
    UnUint32_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnUnsigned_Meta, 0)
        .tp_name        = "unsys.c_uint32",
        .tp_basicsize   = sizeof(UnInt32),
        .tp_base         = &UnUnsigned_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnUint32_Type)) return 1;

    impl = &UnUint64_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_UINT64;
    dict->conv = impl->as;
    UnUint64_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnUnsigned_Meta, 0)
        .tp_name        = "unsys.c_uint64",
        .tp_basicsize   = sizeof(UnInt64),
        .tp_base        = &UnUnsigned_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnUint64_Type)) return 1;

    impl = &UnUintmax_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_UINTMAX;
    dict->conv = impl->as;
    UnUintmax_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnUnsigned_Meta, 0)
        .tp_name        = "unsys.c_uintmax",
        .tp_basicsize   = sizeof(UnIntmax),
        .tp_base        = &UnUnsigned_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnUintmax_Type)) return 1;

    impl = &UnWint_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_WINT;
    dict->conv = impl->as;
    UnWint_Type = (PyTypeObject){
#if WINT_SIGNEDNESS == NB_UNSIGNED
        PyVarObject_HEAD_INIT(&UnUnsigned_Meta, 0)
        .tp_base    = &UnUnsigned_Type,
#else
        PyVarObject_HEAD_INIT(&UnSigned_Meta, 0)
        .tp_base = &UnSigned_Type,
#endif
        .tp_name    = "unsys.c_wint",
        .tp_flags   = (Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE),
        .tp_dict    = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnWint_Type)) return 1;

    impl = &UnFloat_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_FLT;
    dict->conv = impl->as;
    UnFloat_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnFloating_Meta, 0)
        .tp_name        = "unsys.c_float",
        .tp_basicsize   = sizeof(UnFloat),
        .tp_base        = &UnFloating_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnFloat_Type)) return 1;

    impl = &UnDouble_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_DBL;
    dict->conv = impl->as;
    UnDouble_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnFloating_Meta, 0)
        .tp_name        = "unsys.c_double",
        .tp_basicsize   = sizeof(UnDouble),
        .tp_base        = &UnFloating_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnDouble_Type)) return 1;

    impl = &UnLdouble_impl;
    dict = (TypeAttrDict *) TypeAttrDict_NEW();
    dict->info = unsys_ctypes+AS_LDBL;
    dict->conv = impl->as;
    UnLdouble_Type = (PyTypeObject){
        PyVarObject_HEAD_INIT(&UnFloating_Meta, 0)
        .tp_name        = "unsys.c_ldouble",
        .tp_basicsize   = sizeof(UnLdouble),
        .tp_base        = &UnFloating_Type,
        .tp_dict        = (PyObject *) dict,
        UnC_IMPL_FOOT
    };
    if (unsys_ADD_ABC(mod, &UnLdouble_Type)) return 1;

    return 0;
}

static inline bool
unsys_INIT_CTYPES(PyObject *mod) {
    unsys.ctypes = PyDict_New();
    return 0;
}
