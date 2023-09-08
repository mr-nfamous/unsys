/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

#pragma once

#define CHASTE_DICTS 1
#define HASH_MAX (2147483647U)

#define DICT_OP_SUCCESS ((hash_t) 0)
#define DICT_OP_FAILURE ((hash_t) HASH_MAX+1U)

struct UCD_block {
    char32_t    lo;
    char32_t    hi;
    char        id[17];
    char        na[80-17];
};


struct unitem;

typedef int (*keycmp_t)(const char *, const char*);
typedef hash_t(*strhash_t)(const char *);

typedef struct unitem {
    const char     *k;
    const void     *v;
    hash_t          i;
    struct unitem  *next;
} unitem;

typedef struct {
    uint8_t     bits;
    hash_t      used;
    hash_t      size;
    unitem    **staq;
    unitem     *imap[1];
} undict;

typedef union ptrview {
    void        *addr;
    uintptr_t   uint;
    char        *c;
    wchar_t     *w;
    uint8_t     *u8;
    uint16_t    *u16;
    uint32_t    *u32;
    uint64_t    *u64;
    uintmax_t   *umax;
    size_t      *usz;
    int8_t      *s8;
    int16_t     *s16;
    int32_t     *s32;
    int64_t     *s64;
    intmax_t    *smax;
    ssize_t     *ssz;
    float       *flt;
    double      *dbl;
} ptrview_t;

typedef struct dict_item {
    const char *key;
    void       *val;
    struct dict_item *next;
} DictItem;

typedef struct {
    size_t              size;
    struct timespec     ctime;
    struct timespec     mtime;
    struct timespec     atime;
    hash_t              nkey;
    hash_t              used;
    int                 type;
    uint8_t             lsh;
    uint8_t             rsh;
    keycmp_t            kcmp;
    strhash_t           hash;
#   if CHASTE_DICTS
    pthread_rwlock_t    lock;
#   endif
    DictItem **         map;
    DictItem  *         data;
} Dict;
