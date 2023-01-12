/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳   

Locate a member of a set in an array

MEMCHR
MEMRCHR
MEMLBRK

STRCHR
STRBRK
STRRBRK

*/

static inline void *
MEM_F(LBRK)(const void *mem, size_t len, const void *set, size_t nel) {
    if (len == 0) return NULL;
    if (nel == 0) return NULL;
    const chr_t *s = set;
    if (nel == 1) return MEM_F(CHR)(mem, *s, len);
    const chr_t *b = mem;
    for (size_t i;; b++) {
        for (i=0;;) {
            if (*b == s[i]) return (void *) b;
            if (++i == nel) break;
        }
        if (!--len) return NULL;
    }
}

static chr_t *
STR_F(BRK)(const chr_t *str, const chr_t *set) {
#if   chr_width ==  8 && defined(bstrbrk)
    return bstrbrk(str, set);
#elif chr_width == 16 && defined(wstrbrk)
    return wstrbrk(str, set);
#elif chr_width == 32 && defined(ustrbrk)
    return ustrbrk(str, set);
#else
    if (!*set || !*str) return 0;
    size_t i = 0;
    for (;;) {
        if (*str == set[i]) return (chr_t *) str;
        if (!set[++i]) break;
    }
    size_t j = i;
    for (str++; *str; str++) {
        for (i=0; i < j; i++) {
            if (*str == set[i]) return (chr_t *) str;
        }
    }
    return 0;
#endif
}

static chr_t *
STR_F(RBRK)(const chr_t *str, const chr_t *set) {
    if (!*str) return NULL;
    const chr_t *r;
    for (; *set; set++) {
        if ((r=STR_F(RCHR)(str, *set))) {
            for (set++; *set; set++) {
                str = STR_F(RCHR)(r, *set);
                if (str) r = str;
            }
            return (chr_t *) str;
        }
    }
    return NULL;
}

