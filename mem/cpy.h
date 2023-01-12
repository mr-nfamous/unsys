/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

static inline void *
MEM_F(CPY)(void *restrict dst, const void *restrict src, size_t len) {
#if   chr_width ==  8 && defined(bmemcpy)
    return bmemcpy(dst, src, len);
#elif chr_width == 16 && defined(hmemcpy)
    return hmemcpy(dst, src, len);
#elif chr_width == 16 && defined(bmemcpy)
    return bmemcpy(dst, src, len<<1);
#elif chr_width == 32 && defined(umemcpy)
    return umemcpy(dst, src, len);
#elif chr_width == 32 && defined(bmemcpy)
    return bmemcpy(dst, src, len<<2);
#else
    for (size_t i=0; i < len; i++) {
        UCA(dst)[i] = UCA(src)[i];
    }
    return dst;
#endif
}

static inline void *
MEM_F(RCPY)(void *restrict dst, const void *restrict src, size_t nel) {
    if (nel <= 1) {if (nel) *UCA(dst) = *UCA(src);}
    else for (size_t p=0, q=nel-1; p < nel; p++, q--) {
        UCA(dst)[p] = UCA(src)[q];
    }
    return dst;
}

static inline void *
MEM_F(CCPY)(void *restrict d, const void *restrict s, chr_t c, size_t n) {
#if   chr_width ==  8 && defined(bmemccpy)
    return bmemccpy(d, s, c, n);
#else
    for (size_t  i=0;; i++) {
        if (n == i) return NULL;
        if (c == ( UCA(d)[i]=UCA(s)[i])) {
            return UCA(d)+i+1;
        }
    }
#endif
}

static inline chr_t *
STP_F(CPY)(chr_t dst[restrict], const chr_t *restrict src) {
#if   chr_width ==  8 && defined(bstpcpy)
    return bstpcpy(dst, src);
#elif chr_width == 16 && defined(wstpcpy)
    return wstpcpy(dst, src);
#elif chr_width == 32 && defined(ustpcpy)
    return ustpcpy(dst, src);
#else
#   if chr_width == 8 && defined(bmemccpy)
    return bmemccpy(dst, src, 0, SIZE_MAX>>1)-1;
#   else
    for (;; dst++, src++) {if (!(*dst=*src)) {return dst;}}
#   endif
#endif
}

static inline chr_t *
STR_F(CPY)(chr_t *restrict dst, const chr_t *restrict src) {
#if   chr_width ==  8 && defined(bstrcpy)
    return    bstrcpy(dst, src);
#elif chr_width == 16 && defined(hstrcpy)
    return    hstrcpy(dst, src);
#elif chr_width == 32 && defined(ustrcpy)
    return    ustrcpy(dst, src);
#else
#   if chr_width == 8 && defined(bmemccpy)
    (void) bmemccpy(dst, src, 0, SIZE_MAX>>1);
    return dst;
#   else
    for (size_t i=0;; i++) {
        if (!(dst[i]=src[i])) return dst;
    }
#   endif
#endif
}

static inline chr_t *
STP_F(NCPY)(chr_t dst[restrict], const chr_t *restrict src, size_t len) {
#if   chr_width ==  8 && defined(bstpncpy)
    return bstpncpy(dst, src, len);
#elif chr_width == 16 && defined(hstpncpy)
    return hstpncpy(dst, src, len);
#elif chr_width == 32 && defined(ustpncpy)
    return ustpncpy(dst, src, len);
#else
    chr_t *const stp= dst+len;
    for (; dst < stp; dst++, src++) {
        if (!(*dst=*src)) {
            for (;++dst < stp;) *dst = 0;
            return stp;
        }
    }
    return stp;
#endif
}

static inline chr_t *
STR_F(NCPY)(chr_t dst[restrict], const chr_t *restrict src, size_t len) {
#if   chr_width ==  8 && defined(bstrncpy)
    return    bstrncpy(dst, src, len);
#elif chr_width == 16 && defined(hstrncpy)
    return    hstrncpy(dst, src, len);
#elif chr_width == 32 && defined(ustrncpy)
    return    ustrncpy(dst, src), len;
#else
    for (size_t i=0; i < len; i++) {
        if (!(dst[i]=src[i])) {
            while (--i < len) dst[i] = 0; break;
        }
    }
    return dst;
#endif
}

static inline chr_t *
STP_F(LCPY)(chr_t dst[restrict] , const chr_t *restrict src, size_t nel) {
#if   chr_width ==  8 && defined(bstrlcpy)
    return  bstrlcpy(dst, src, nel)+dst;
#elif chr_width == 16 && defined(hstrlcpy)
    return  hstrlcpy(dst, src, nel)+dst;
#elif chr_width == 32 && defined(ustrlcpy)
    return  ustrlcpy(dst, src, nel)+dst;
#else
    nel = STR_F(NLEN)(dst, nel);
    return MEM_F(CPY)(dst, src, nel)+nel;
#endif
}

static inline chr_t *
STR_F(LCPY)(chr_t dst[restrict], const chr_t *restrict src, size_t nel) {
#if   chr_width ==  8 && defined(bstrlcpy)
    return  bstrlcpy(dst, src, nel);
#elif chr_width == 16 && defined(hstrlcpy)
    return  hstrlcpy(dst, src, nel);
#elif chr_width == 32 && defined(ustrlcpy)
    return  ustrlcpy(dst, src, nel);
#else
    return MEM_F(CPY)(dst, src, STR_F(NLEN)(dst, nel));
#endif
}

static inline chr_t *
STP_F(SCPY)(chr_t *restrict dst, const chr_t *restrict src) {
    if (!dst || !src) {
        errno = ENOMEM;
        return NULL;
    }
    if (!dst[0]) {
        return src[0] ? ((errno=ENOSPC), NULL) : dst;
    }
    if (!src[0]) return dst;
    for (size_t i=1;; i++) {
        if (!src[i]) return i+MEM_F(CPY)(dst, src, i);
    }
}

static inline chr_t *
STR_F(SCPY)(chr_t *restrict dst, const chr_t *restrict src) {
    (void) STP_F(SCPY)(dst, src);
    return dst;
}


#if TESTS_PASSED && defined(MEMCPY_TEST)

static void
MEM_F(CPY_TEST)(void) {
    size_t ctr = 0;
#if chr_width == 8
    struct memcpy_test {
        const char     *lhs;
        size_t          lsz;
        const char     *rhs;
        size_t          rsz;
        int             lno;
    } t, tests[] = {
#define test(l,r) {l, strlen(l)+1, r, strlen(r)+1, __LINE__}
        test(" tmp/0123456789abcdef", "/"),
        test(" tmp/0123456789abcdef", "/"),
        test("  mp/0123456789abcdef", "/t"),
        test("   p/0123456789abcdef", "/tm"),
        test("    /0123456789abcdef", "/tmp"),
        test("     0123456789abcdef", "/tmp/"),
        test("      123456789abcdef", "/tmp/0"),
        test("       23456789abcdef", "/tmp/01"),
        test("        3456789abcdef", "/tmp/012"),
        test("         456789abcdef", "/tmp/0123"),
        test("          56789abcdef", "/tmp/01234"),
        test("           6789abcdef", "/tmp/012345"),
        test("            789abcdef", "/tmp/0123456"),
        test("             89abcdef", "/tmp/01234567"),
        test("              9abcdef", "/tmp/012345678"),
        test("               abcdef", "/tmp/0123456789"),
        test("                bcdef", "/tmp/0123456789a"),
        test("                 cdef", "/tmp/0123456789ab"),
        test("                  def", "/tmp/0123456789abc"),
        test("                   ef", "/tmp/0123456789abcd"),
        test("                    f", "/tmp/0123456789abcde"),
#undef  test
    };

    char lhs[256];
    char rhs[256];
    for (; ctr < lengthof(tests); ctr++) {
        t = tests[ctr];
        char a[256];
        char b[sizeof a];
        char *p;
        char *q;
        (void) memset(a, 255, sizeof a);
        (void) memset(b, 255, sizeof a);
        if (a != (p=memcpy(a, t.lhs,  t.lsz))) {
            (void) printf("line %d: memcpy ret %p, not %p\n",t.lno,p,a);
            exit(1);
        }
        if (b != (q=MEM_F(CPY)(b, t.lhs, t.lsz))) {
            (void) printf("line %d: MEMCPY ret %p, not %p\n", t.lno,q,b);
            exit(1);
        }
        p = memchr(a, 0, sizeof a);
        q = memchr(b, 0, sizeof b);
        (void) memcpy(p, t.rhs, t.rsz);
        (void) memcpy(q, t.rhs, t.rsz);
        if (memcmp(a, b, sizeof a)) {
            (void) printf("line %d: memcmp(a,b,n) (after memcpy)\n",t.lno);
            exit(1);
        }
        (void) memset(a, 255, sizeof a);
        (void) memset(b, 255, sizeof a);
        if (a != (p=memmove(a, t.lhs,  t.lsz))) {
            (void) printf("line %d: memmove ret %p, not %p\n",t.lno,p,a);
            exit(1);
        }
        if (b != (q=MEM_F(MOV)(b, t.lhs, t.lsz))) {
            (void) printf("line %d: MEMMOV ret %p, not %p\n", t.lno,q,b);
            exit(1);
        }
        if (memcmp(a, b, sizeof a)) {
            (void) printf("line %d: memcmp(a,b,n) (after memmove)\n",t.lno);
            exit(1);
        }
        /*
        size_t          len = t[ctr].len;
        const char *    lhs = t[ctr].lhs;
        const char *    rhs = t[i].rhs;
        const char *    chr = t[i].chr;
        test(0);
        */
        /*
        if (t.chr) {
            (void) BMEMCCPY(dst, t.rhs, *t.chr, t.len);
            (void)  memccpy(cpy, t.rhs, *t.chr, t.len);
            fn="memccpy";
        }
        else {
            (void) BMEMCPY(dst, t.rhs, t.len);
            (void)  memcpy(cpy, t.rhs, t.len);
            fn="memcpy";
        }
        if (memcmp(dst, cpy, sizeof dst)) {
            BFPUTS_ESCBOX(stdout, "dst => \"", dst, "\"\n");
            BFPUTS_ESCBOX(stdout, "cpy => \"", cpy, "\"\n");
            goto fail;
        }
        if (chr) {
            continue;
        }
        test(0);
        (void) BSTRCPY(dst, rhs);
        (void)  strcpy(cpy, rhs);
        f=f_strcpy, fn="strcpy";
        if (memcmp(dst, cpy, sizeof dst)) goto fail;
        test(0);
        f=f_stpcpy, fn="stpcpy";
        char *dsp = BSTPCPY(dst, rhs);
        char *csp =  stpcpy(cpy, rhs);
        if (memcmp(dst, cpy, sizeof dst)) {
            BFPUTS_ESCBOX(stdout, "rhs => \"", rhs, "\"\n");
            BFPUTS_ESCBOX(stdout, "dst => \"", dst, "\"\n");
            BFPUTS_ESCBOX(stdout, "cpy => \"", cpy, "\"\n");
            goto fail;
        }
        if ((dsp-dst) != (csp-cpy)) {
            fn = "stpcpy (wrong res)";
            goto fail;
        }
        */
    }

//#undef  test
#endif
    TESTS_PASSED();
/*
    return;
    fail: {
        (void) printf("line %d: failed %s\n", lno, fn);
        exit(1);
    }
*/
}

#endif // defined(TESTS_PASSED)
