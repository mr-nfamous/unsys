/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

static inline void *
MEM_F(MEM)(const void *mem, size_t msz, const void *str, size_t len) {
#if   chr_width ==  8 && defined(bmemmem)
    return bmemmem(mem, msz, str, len);
#elif chr_width == 16 && defined(hmemmem)
    return hmemmem(mem, msz, str, len);
#elif chr_width == 32 && defined(umemmem)
    return umemmem(mem, msz, str, len);
#else
    if (len >= msz) {
        if (msz < len || MEM_F(CMP)(mem, str, len)) return NULL;
        goto ret;
    }
    if (len <= 001) {
        if (len) return MEM_F(CHR)(mem, *(chr_t *) str, msz);
        goto ret;
    }
    size_t      n = len-1;
    const char *l = mem;
    const char *r = str;
    msz -= len;
    for (; msz > 0; l++, msz--) {
        if (l[n] != r[n] || memcmp(l, r, chr_size*n)) continue;
        goto ret;
    }
    return 0;
    ret: {return (void *) l;}
#endif
}

static inline void *
MEM_F(STR)(const void *mem, size_t msz, const chr_t *str) {
    return MEM_F(MEM)(mem, msz, str, STR_F(LEN)(str));
}

static inline void *
MEM_F(RMEM)(const void *mem, size_t msz, const void *str, size_t len) {
    if (len >= msz) {
        if (msz < len || MEM_F(CMP)(mem, str, len)) return NULL;
        goto ret;
    }
    if (len <= 001) {
        if (len) return MEM_F(RCHR)(mem, *(char *) str, msz);
        goto ret;
    }
    size_t      n = len-1;
    msz -= len;
    const chr_t *l = mem+msz;
    const chr_t *r = str;
    for (; msz > 0; l--, msz--) {
        if (l[n] != r[n] || MEM_F(CMP)(l, r, n)) continue;
        goto ret;
    }
    return 0;
    ret: {return (void *) l;}
}

#if defined(TESTS_PASSED) && defined(MEMMEM_TEST)

static void
MEM_F(MEM_TEST)(void) {
    size_t ctr = 0;
    size_t len;
    size_t msz = 128;
    size_t i;

    char mem[257]={0};
    char repr[256];
    size_t t = BRANGE(mem, 0, 255, 1);

    if (t != 256) {
        printf("line %d: brange ret %zu, not 256\n",__LINE__, t);
        exit(1);
    };

    for (i=0; i < 256; i++) {
        if (mem[i] != i) {
            printf("line %d: brange[%zu] != %zu\n", __LINE__, i, i);
            exit(1);
        }
    }

    for (len=1; len < 16; len++) {
        char str[] = "0123456789:;<=>?";
        str[len] = 0;
        for (i=0; i < 48; i++) {
            char *q = memmem(mem+i, msz-i, str, len);
            if (!q) {
                printf(
                    "memmem(mem+%zu, %zu, %s, %zu) ret NULL\n",
                    i, msz-i,
                    BSTRREPR(repr, str, sizeof repr),
                    len
                );
                exit(1);
            }
            char *p = BMEMMEM(mem+i, msz-i, str, len);
            if (p == q) {
                ctr++;
                continue;
            }
            if (!p) {
                printf(
                    "BMEMMEM(mem+%zu, %zu, %s, %zu) ret NULL\n",
                    i, msz-i,
                    BSTRREPR(repr, str, sizeof repr),
                    len
                );
                exit(1);
            }

            printf(
                "BMEMMEM(mem+%zu, %zu, %s, %zu) ret ",
                i, msz-i,
                BSTRREPR(repr, str, sizeof repr),
                len
            );
            printf("mem+%td, not mem+%td\n", q-mem, p-mem);
            exit(1);
        }
    }
    TESTS_PASSED();
}

static void
MEM_F(RMEM_TEST)(void) {
    size_t ctr = 0;
    uint8_t mem[123-48];
    char repr[256];
    const uint8_t *res;
    uint8_t str[32] = "";
    ptrdiff_t n;
    uint8_t a;
    uint8_t b;
    int lno;
    const char *why;
    uint8_t len;
    size_t nch;
    size_t end = BRANGE(mem, 48, 'z', 1);
    for (b='z'; b >= 'k'; b--) {
        for (len=1; len < 17; ctr++, len++) {
            (void) memset(str, 0, sizeof str);
            a = b-(len-1);
            nch = BRANGE(str, a, b, 1);
            if (!nch) {
                why = "BRANGE ret 0";
                goto fail;
            }
            res = BMEMRMEM(mem, sizeof mem, str, nch);
            if (res == NULL) {
                why = "memrmem ret NULL";
                goto fail;
            }
            if (*res != a) {
                why = "*res != a";
                goto fail;
            }
        }
    }
    TESTS_PASSED();
    return;
    fail: {
        printf("failed cause: %s\n", why);
        printf("    nch = %zu\n", nch);
        printf("    str = %s\n", BSTRREPR(repr,(char*) str, sizeof repr));
        printf("      a = %s\n", BCHRREPR(repr,   a, sizeof repr));
        printf("      b = %s\n", BCHRREPR(repr,   b, sizeof repr));
    }
}

#endif // defined(TESTS_PASSED)
