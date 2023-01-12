/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 
Copy overlapping sequences of memory

MEMMOV
    Identical to {memmove}

MEMRMOV
    Identical to {memmove} except that the reverse of {src} 
    is copied.
*/

static inline void *
MEM_F(MOV)(void *dst, const void *src, size_t len) {
#if   chr_width ==  8 && defined(bmemmov)
    return bmemmov(dst, src, len);
#elif chr_width == 16 && defined(hmemmov)
    return hmemmov(dst, src, len);
#elif chr_width == 16 && defined(bmemmov)
    return bmemmov(dst, src, len<<1);
#elif chr_width == 32 && defined(umemmov)
    return umemmov(dst, src, len);
#elif chr_width == 32 && defined(bmemmov)
    return bmemmov(dst, src, len<<2);
#else
    if (dst <= src) return MEM_F(CPY)(dst, src, len);
    if (!len) return dst;
    for (;;) {
        const chr_t v = UCA(src)[--len];
        UCA(dst)[len] = v;
        if (!len) return dst;
    }
#endif
}

static inline void *
MEM_F(RMOV)(void *dst, const void *src, size_t nel) {
    if (src == dst) return MEM_F(REV)(dst, nel);
    if (nel == 0) return dst;
    const chr_t *s = src;
    size_t r = nel>>1;
    size_t p = 0;
    size_t q = nel-1;
    chr_t *d = dst;
    chr_t t;
    for (; p < r; p++, q--) t=s[p], d[p]=s[q], d[q]=t;
    if (nel%2) d[r] = s[r];
    return dst;
}

#if defined(TESTS_PASSED) && defined(MEMMOV_TEST)

static void
MEM_F(MOV_TEST)(void) {
    //char s[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    size_t ctr = 0;
    char s[128] = {0};
    char r[sizeof s];
    char b[sizeof s];
    char m[sizeof s];
    (void) BRANGE(s, '0', 'z', 1);
    for (size_t len=0; len < 32; len++) {
        for (size_t off=0; off < 32; ctr++, off++) {
            (void) memcpy(b, s, sizeof s);
            (void) memcpy(m, s, sizeof s);
            (void) memmove(b+off+4, b+off, len);
            (void) BMEMMOV(m+off+4, m+off, len);
            if (memcmp(b, m, sizeof s)) {
                printf("failed with len=%zu, off=%zu\n", len, off);
                printf("b = %s\n", BSTRREPR(r, b, sizeof r));
                printf("m = %s\n", BSTRREPR(r, m, sizeof r));
                exit(1);
            }
        }
    }
    TESTS_PASSED();
}

#endif // defined(TESTS_PASSED)