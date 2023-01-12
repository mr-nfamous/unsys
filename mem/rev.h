/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

static inline void *
MEM_F(REV)(void *mem, size_t nel) 
{
    chr_t *l = mem;
    chr_t *r;
    chr_t  v;
    if (nel > 7) {
        r = l+(nel-1);
        do {
            v=*l, *l++=*r, *r--=v;
            v=*l, *l++=*r, *r--=v;
            v=*l, *l++=*r, *r--=v;
            v=*l, *l++=*r, *r--=v;
        }
        while ((nel-=8) >= 8);
    }
    r = l;
    switch (nel) {
        case 7: {
            v=l[0], l[0]=r[6], r[6]=v;
            v=l[1], l[1]=r[5], r[5]=v;
            v=l[2], l[2]=r[4], r[4]=v;
            return mem;
        }
        case 6: {
            v=l[0], l[0]=r[5], r[5]=v;
            v=l[1], l[1]=r[4], r[4]=v;
            v=l[2], l[2]=r[3], r[3]=v;
            return mem;
        }
        case 5: {
            v=l[0],l[0]=r[4],r[4]=v;
            v=l[1],l[1]=r[3],r[3]=v;
            return mem;
        }
        case 4: {
            v=l[0],l[0]=r[3],r[3]=v;
            v=l[1],l[1]=r[2],r[2]=v;
            return mem;
        }
        case 3: {v=l[0],l[0]=r[2],r[2]=v; return mem;}
        case 2: {v=l[0],l[0]=r[1],r[1]=v; return mem;}
    }
    return mem;
}

static inline chr_t *
STP_F(REV)(chr_t str[]) {
    size_t len = STR_F(LEN)(str);
    return MEM_F(REV)(str, len)+len;
}

static inline chr_t *
STR_F(REV)(chr_t str[]) {
#if   chr_width ==  8 && defined(bstrrev)
    return bstrrev(str);
#elif chr_width == 16 && defined(hstrrev)
    return hstrrev(str);
#elif chr_width == 32 && defined(ustrrev)
    return ustrrev(str);
#else
    return MEM_F(REV)(str, STR_F(LEN)(str));
#endif
}

#if defined(TESTS_PASSED) && defined(MEMREV_TEST)

static void
MEM_F(REV_TEST)(void) {
    size_t ctr = 0;
    char mem[256] = "0123456789";
    char str[256];
    printf(
        "%s\n",
        BSTRREPR(
            str,
            BMEMRMOV(mem, mem, strlen(mem)),
            //BMEMREV(mem, strlen(mem)),
            sizeof str
        )
    );
/*
    char    mem[256];
    char   repr[256];
    char   *str;
    char   *stp;
    const size_t dsz = sizeof mem;
    struct {
        const char *fwd;
        const char *rev;
        size_t      len;
        int         lno;}
    t, tests[] = {

#define test(s,r) {s, r, strlen(s), __LINE__}
        test("", ""),
        test("0", "0"),
        test("01", "10"),
        test("012", "210"),
        test("0123", "3210"),
        test("01234", "43210"),
        test("012345", "543210"),
        test("0123456", "6543210"),
        test("01234567", "76543210"),
        test("012345678", "876543210"),
        test("0123456789", "9876543210"),
        test("0123456789a", "a9876543210"),
        test("0123456789ab", "ba9876543210"),
        test("0123456789abc", "cba9876543210"),
        test("0123456789abcd", "dcba9876543210"),
        test("0123456789abcde", "edcba9876543210"),
        test("0123456789abcdef", "fedcba9876543210"),
        test("0123456789abcdefg", "gfedcba9876543210"),
        test("0123456789abcdefgh", "hgfedcba9876543210"),
        test("0123456789abcdefghi", "ihgfedcba9876543210"),
#undef  test
    };

    for (; ctr < lengthof(tests); ctr++) {
        t = tests[ctr];
        size_t msz = t.len+1;
        str = BSTRREV(mem, t.fwd, 0);
        if (str[t.len]) {
            printf("line %d: improperly terminated after STRREV" t.lno);
            exit(1);
        }
        (void) memcpy(mem, t.fwd, msz);
        BMEMREV(memcpy(memset(dst, 0, dsz), t.src, t.len), t.len);
        if (memcmp(dst, t.rev, t.len)) {
            why = "memrev";
            goto fail;
        }
        (void)   memset(dst, 00000, dsz);
        (void) BMEMRCPY(dst, t.src, t.len);
        if (memcmp(dst, t.rev, t.len)) {
            why = "memrcpy";
            printf("dst = %s\n", BSTRREPR(str,   dst, sizeof str));
            printf("src = %s\n", BSTRREPR(str, t.src, sizeof str));
            printf("rev = %s\n", BSTRREPR(str, t.rev, sizeof str));
            goto fail;
        }
    }
    */
    TESTS_PASSED();
    return;

}

#endif // defined(TESTS_PASSED)
