/*  |**************************************************************************/

#include <inttypes.h>
#include <stdlib.h>

typedef uint64_t hash_t;

typedef union intview {
    uint32_t    u;
    int32_t     s;
    uint8_t     b[4];
    uint16_t    h[2];
    uint32_t    i[1];
} IntView;

typedef union longview {
    uint64_t    u;
    int64_t     s;
    uint8_t     b[8];
    uint16_t    h[4];
    uint32_t    i[2];
    uint64_t    q[1];
    uintmax_t   x;
} LongView;

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

typedef struct {
    const void *str;
    size_t      size;
    hash_t      hash;
} DictKey;

typedef struct dict_item {
    const void       *key;
    void             *val;
    struct dict_item *next;
} DictItem;

typedef struct {
    size_t  nkey;
    size_t  size;
    size_t  used;
    int     type;
    uint8_t lsh;
    uint8_t rsh;
    uint8_t __res1[2];
    DictItem **map;
    DictItem *data;
} Dict;

typedef struct {
    Dict *dict;
    size_t pos;
} DictIter;

static  
uint8_t NBIT[256] = {0, 1, 2, 2};

hash_t
string_hash(const void *ptr, size_t *restrict len) {
    const uint8_t *restrict str = ptr;
    size_t i = 0;
    union {
        uint64_t v;
        struct {
            uint16_t a;
            uint32_t b;
        };
    } hash = {.a=1, .b=0};
    for (; str[i]; i++)
        hash.a += str[i],
        hash.b += hash.a;
    if (len)
        len[0] = i;
    if (!hash.v)
        return 0;
    hash.v ^= hash.v>>12;
    hash.v ^= hash.v<<25;
    hash.v ^= hash.v>>27;
    return    hash.v>>33;
}

static 
void
init_nbit(void) {
    memset(NBIT+0x04, 3, 0x04);
    memset(NBIT+0x08, 4, 0x08);
    memset(NBIT+0x10, 5, 0x10);
    memset(NBIT+0x20, 6, 0x20);
    memset(NBIT+0x40, 7, 0x40);
    memset(NBIT+0x80, 8, 0x80);
}

static inline 
uint8_t
hashbits(hash_t i) {
    if (i <  0x00000004) return 003;
    if (i <= 0x000000FF) return 001+NBIT[i];
    if (i <= 0x0000FFFF) return 011+NBIT[i>>010];
    if (i <= 0x00FFFFFF) return 021+NBIT[i>>020];
    else                 return 031+NBIT[i>>030];
}

Dict *
Dict_new(size_t nkey, int type) {
    Dict dict           = {.nkey=nkey, .type=type};
    dict.lsh            = hashbits((hash_t)(nkey));
    dict.rsh            = 31-dict.lsh;
    dict.size           = 1<<dict.lsh;
    const size_t ptrs   = sizeof(DictItem*)*dict.size;
    const size_t data   = sizeof(DictItem)*nkey;
    const size_t xtra   = data+ptrs;
    const size_t need   = sizeof(Dict)+xtra;
    ptrview_t buf       = {malloc(need)};
    Dict *self          = buf.addr;
    memcpy(self, &dict, sizeof(Dict));
    buf.addr            = self+1;
    memset(buf.addr, 0, xtra);
    self->map           = buf.addr;
    self->data          = (void *)(buf.c+ptrs);
    return self;
}

void *
Dict_gethashed(Dict *self, const DictKey *restrict k) {
    DictItem *item  = self->map[k->hash>>self->rsh];
    while (item) {
        if (!strncmp(item->key, key->str, k->size))
            return   item->val;
        item = item->next;
    }
    return 0;
}

void *
Dict_get(Dict *self, const void *restrict key) {
    // Get the value associated with `key`, or NULL if 
    // no such entry has been added to the dict.
    // Dict_gethashed takes a DictKey *argument if the 
    // key's hash and size have already been computed
    size_t size     = 0;
    hash_t hash     = string_hash(key, &size);
    DictItem *item  = self->map[hash>>self->rsh];
    while (item) {
        if (!strncmp(item->key, key, size))
            return   item->val;
        item = item->next;
    }
    return 0;
}

Dict *
Dict_puthashed(Dict *dict, const DictKey *restrict key, void *val) {
    hash_t slot = key->hash>>self->rsh;
    DictItem *p = self->map[slot];
    DictItem *q;
    if (p) {
        next:
        if ((p->key == key->str) || !strncmp(p->key, key->str, key->size)) {
            (p->val=val);
            return self;
        }
        if (p->next) {
            q = p->next;
            p = q;
            goto next;
        }
        if (self->used >= self->size)
            return 0;
        q = self->used+++self->data;
        p->next = q;
        p = q;
    }
    else {
        if (self->used >= self->size)
            return 0;
        self->map[slot] = self->used+++self->data;
        p = self->map[slot];
    }
    p->next = 0;
    p->val = val;
    p->key = key->str;
    return self;
}

Dict *
Dict_put(Dict *dict, const void *k, void *val) {
    DictKey key = {.str=k};
    key.hash    = string_hash(k, &key.size);
    return Dict_puthashed(dict, &key, val);
}

DictItem *
DictIter_next(DictIter *it) {
    return (it->pos < it->dict->used) ? it->pos+++it->dict->data : 0;
        return 0;
}

uintmax_t 
getint8(const ptrview_t p, void *restrict d) {
    if (d)
        ++((ptrview_t *)&d)->u8;
    return (uintmax_t)p.u8[0];
}

uintmax_t
getint16(const ptrview_t p, void *restrict d) {
    if (d)
        ((ptrview_t *)&d)->u8 += 2;
    if (p.uint&1) {
        uintmax_t r =  p.u8[0];
        return    r<<8|p.u8[1];
    }
    return (uintmax_t)p.u16[0];
}

uintmax_t
getint32(const ptrview_t p, void *restrict d) {
    if (d)
        ((ptrview_t *)&d)->u8 += 4;
    if (p.uint%4 == 0)
        return (uintmax_t) p.u32[0];
    return (uintmax_t)((IntView){
        .b = {
            p.u8[0], 
            p.u8[1], 
            p.u8[2], 
            p.u8[3],
        }
    }).u;
}

uintmax_t
getint64(const ptrview_t p, void *restrict d) {
    if (d)
        ((ptrview_t *)&d)->u8 += 8;
    if (p.uint%8 == 0)
        return (uintmax_t) p.u64[0];
    return ((LongView){
        .b = {
            p.u8[0], 
            p.u8[1],
            p.u8[2], 
            p.u8[3],
            p.u8[4], 
            p.u8[5],
            p.u8[6], 
            p.u8[7],
        }
    }).x;
}

