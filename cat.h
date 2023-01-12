
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

Array concatenation

Most of these should never be used 
*/

static inline chr_t *
STP_F(CAT)(chr_t dst[restrict], const chr_t src[restrict]) {
    return STP_F(CPY)(STR_F(CHR)(dst, 0), src);
}

static inline chr_t *
STR_F(CAT)(chr_t dst[restrict], const chr_t src[restrict]) {
#if   chr_width ==  8 && defined(bstrcat)
    return bstrcat(dst, src);
#elif chr_width == 16 && defined(hstrcat)
    return hstrcat(dst, src);
#elif chr_width == 32 && defined(ustrcat)
    return ustrcat(dst, src);
#else
    (void) STR_F(CPY)(STR_F(CHR)(dst, 0), src);
    return dst;
#endif
}

static inline chr_t *
STP_F(NCAT)(chr_t dst[restrict], const chr_t src[restrict], size_t len) {
    dst = STR_F(CHR)(dst, 0);
    if (!len) return dst;
    for (size_t i=0;;) {
        if (!(*dst=src[i])) return dst;
        dst++;
        if (++i == len) {
            *dst = 0;
            return dst;
        }
    }
}

static inline chr_t *
STR_F(NCAT)(chr_t dst[restrict], const chr_t src[restrict], size_t nel) {
#if   chr_width ==  8 && defined(bstrncat)
    return bstrncat(dst, src, nel);
#elif chr_width == 16 && defined(hstrncat)
    return hstrncat(dst, src, nel);
#elif chr_width == 32 && defined(ustrncat)
    return ustrncat(dst, src, nel);
#else
    if (!(nel=STR_F(NLEN)(src, nel))) return dst;
    dst = STR_F(CHR)(dst, 0);
    (void) MEM_F(CPY)(dst, src, nel);
    dst[nel] = 0;
    (void) STR_F(CPY)(STR_F(CHR)(dst, 0), src);
    return dst;
#endif
}

/*
static inline chr_t *
STP_F(MUL)(chr_t dst[], const chr_t str[], size_t mul) {
    size_t len = mul;
    if (!mul) {
        stop: {dst[len] = 0;}
        return dst+len;
    }
    size_t nel = STR_F(LEN)(str);
    if (nel == 0) {
        mul = 0;
        goto stop;
    }
    if (nel == 1) {
        (void) MEM_F(SET)(dst, *str, mul);
        goto stop;
    }
    (void) MEM_F(MOV)(dst, str, nel);
    len *= nel;
    if (mul == 1) goto stop;
    for (size_t q, p=nel, r=len;; p=q) {
        q = p<<1;
        if (q >= r) {
            (void) MEM_F(CPY)(dst+p, dst, r-p);
            goto stop;
        }
        else {
            (void) MEM_F(CPY)(dst+p, dst, p);
        }
    }
}

static inline chr_t *
STR_F(MUL)(chr_t dst[], const chr_t str[], size_t mul) {
    (void) STP_F(MUL)(dst, str, mul);
    return dst;
}
*/

#if defined(TESTS_PASSED) && defined(STRCAT_TEST)

static void
STR_F(CAT_TEST)(void) {
    size_t ctr = 0;
    char str[256]={0};
    for (char dex='a'; dex <= 'z'; dex++) {
        char rhs[32] = {0};
        (void) BRANGE(rhs, 'a', dex, 1);
        int i = 0;
        int c;
        for (c='a'; c <= dex; c++, i++) {
            if (rhs[i] != c) {
                printf("brange fail:\n");
                printf(
                    "rhs[%d] == 0x%02x, not 0x%02x\n",
                    i, rhs[i], c
                );
                exit(1);
            }
        }
        for (char lev='A'; lev <= 'Z'; lev++) {
            char lhs[32] = {0};
            (void) BRANGE(lhs, 'A', lev, 1);
            char dst[64] = {0};
            char cat[64] = {0};
            (void) strcat(cat, lhs);
            (void) strcat(cat, rhs);
            (void) BSTRCAT(dst, lhs);
            (void) BSTRCAT(dst, rhs);
            if (memcmp(cat,dst, sizeof dst)) {
                printf("failed strcat:\n");
                printf("    dex=%s\n",  BCHRREPR(str, dex, 255));
                printf("    lev=%s\n",  BCHRREPR(str, lev, 255));
                printf("    cat=%s\n", BSTRREPR(str, cat, 255));
                printf("    dst=%s\n", BSTRREPR(str, dst, 255));
                exit(1);
            }
        }
    }
    TESTS_PASSED();
}

#endif // defined(TESTS_PASSED)