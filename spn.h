/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

static inline size_t
MEM_F(SPN)(const void *mem, size_t len, const chr_t *brk) {
    size_t k;
    if (!brk[0]) return 0;
    if (!brk[1]) {
        for (k=0;; k++, len--) {
            if (!len || UCA(mem)[k] != *brk) return k;
        }
    }
    size_t n = STR_F(LEN)(brk);
    for (k=0;; k++, len--) {
        if (!len || !STR_F(CHR)(brk, UCA(mem)[k])) return k;
    }
}

static inline size_t
MEM_F(CSPN)(const void *mem, size_t len, const chr_t *brk) {
    size_t k;
    if (!brk[0]) return len;
    if (!brk[1]) {
        for (k=0;; k++, len--) {
            if (!len || UCA(mem)[k] == *brk) return k;
        }
    }
    size_t n = STR_F(LEN)(brk);
    for (k=0;; k++, len--) {
        if (!len || STR_F(CHR)(brk, UCA(mem)[k])) return k;
    }
}

static inline size_t
STR_F(SPN)(const char str[], const chr_t set[]) {
#if   chr_width ==  8 && defined(bstrspn)
    return bstrspn(str, set);
#elif chr_width == 16 && defined(hstrspn)
    return hstrspn(str, set);
#elif chr_width == 32 && defined(ustrspn)
    return ustrspn(str, set);
#else
    if (!str[0]) return 0;
    size_t j;
    size_t i = 0;
    chr_t  a=set[0], b, c, d, e;
    if (str[i] == a) {
        for (i++;;) {
            if (str[i] != a) break; i++;
            if (str[i] != a) break; i++;
        }
        if (!str[i] || !set[1]) return i;
    }
    else {
        if (!a) return i;
    }
    if (str[i] == (b=set[1])) {
        for (i++;;) {
            if (str[i] != a && str[i] != b) break; i++;
            if (str[i] != a && str[i] != b) break; i++;
        }
        if (!str[i] || !set[2]) return i;
    }
    else {
        if (!b) return i;
    }
    if (str[i] == (c=set[2])) {
        for (i++;;) {
            if (a!=str[i] && b!=str[i] && c!=str[i]) break; i++;
            if (a!=str[i] && b!=str[i] && c!=str[i]) break; i++;
        }
        if (!str[i]) return i;
    }
    else {
        if (!c) return i;
    }
    d = set[3];
    if (!d) return i;
    BTRISORT(&a, &b, &c);
    e = d;
    if (d < b) {
        if (d < a) {d=c, c=b, b=a, a=e;}
        else       {d=c, c=b, b=e;}
    }
    else {
        if (e < c) {d=c, c=e;}
    }
    e = str[i];
    for (;;) {
        if ((e <= b) ? (e!=b&&e!=a) : (e!=c&&e!=d)) break; i++;
        e = str[i];
        if ((e <= b) ? (e!=b&&e!=a) : (e!=c&&e!=d)) break; i++;
        e = str[i];
    }
    if (!e || !set[4]) return i;
    size_t k = BSTRLEN(set);
    q: {j=4;}
    for (; j < k; j++) {
        if (e == set[j]) {
            i++;
            goto p;
        }
    }
    return i;
    p: {e = str[i];}
    if (!e) return i;
    for (;;) {
        if ((e<=b) ? (e!=b&&e!=a) : (e!=c&&e!=d)) break; i++;
        e = str[i];
        if ((e<=b) ? (e!=b&&e!=a) : (e!=c&&e!=d)) break; i++;
        e = str[i];
    }
    if (!str[i]) return i;
    goto q;
#endif
}

static inline size_t
STR_F(CSPN)(const char str[], const chr_t set[]) {
#if   chr_width ==  8 && defined(bstrcspn)
    return bstrcspn(str, set);
#elif chr_width == 16 && defined(hstrcspn)
    return hstrcspn(str, set);
#elif chr_width == 32 && defined(ustrcspn)
    return ustrcspn(str, set);
#else
    return MEM_F(CSPN)(str, STR_F(LEN)(str), set);
#endif
}


#if defined(TESTS_PASSED) && defined(MEMCHR_TEST)

static void
STR_F(CSPN_TEST)(void) {
    size_t ctr = 0;
    const char *set, *str, *end="~";
    size_t spn, ans, lim, max=0;
    char lhs[256];
    char rhs[256];
    struct {
        const char *str;
        const char *set;
        int         lno;
    } t, tests[] =
    {
#define test(s, b) {s, b, __LINE__}
        test("~", "~"),
        test("~", "0~"),
        test("1~", "0~"),
        test("11~", "0~"),
        test("111~", "0~"),
        test("1111~", "0~"),
        test("11111~", "0~"),
        test("111111~", "0~"),
        test("1111111~", "0~"),

        test("1~", "0~"), test("~0000000000", "0~"),
        test("11~", "0~"), test("~000000000", "0~"),
        test("111~", "0~"), test("~00000000", "0~"),
        test("1111~", "0~"), test("~0000000", "0~"),
        test("11111~", "0~"), test("~000000", "0~"),
        test("111111~", "0~"), test("~00000", "0~"),
        test("1111111~", "0~"), test("~0000", "0~"),
        test("11111111~", "0~"), test("~000", "0~"),
        test("111111111~", "0~"), test("~00", "0~"),
        test("1111111111~", "0~"), test("~0", "0~"),

        test(".~", "012~"), test(".........~", "01~"),
        test("..~", "012~"), test("........~", "01~"),
        test("...~", "012~"), test(".......~", "01~"),
        test("....~", "012~"), test("......~", "01~"),
        test(".....~", "012~"), test(".....~", "01~"),
        test("......~", "012~"), test("....~", "01~"),
        test(".......~", "012~"), test("...~", "01~"),
        test("........~", "012~"), test("..~", "01~"),
        test(".........~", "012~"), test(".~", "01~"),
//
        test(".~", "123~"), test("............~", "123~"),
        test("..~", "123~"), test("...........~", "123~"),
        test("...~", "123~"), test("..........~", "123~"),
        test("....~", "123~"), test(".........~", "123~"),
        test(".....~", "123~"), test("........~", "123~"),
        test("......~", "123~"), test(".......~", "123~"),

        test(".~", "~123"), test("............~", "~123"),
        test("..~", "~123"), test("...........~", "~123"),
        test("...~", "~123"), test("..........~", "~123"),
        test("....~", "~123"), test(".........~", "~123"),
        test(".....~", "~123"), test("........~", "~123"),
        test("......~", "~123"), test(".......~", "~123"),

        test(".~", "3~12"), test("............~", "3~12"),
        test("..~", "3~12"), test("...........~", "3~12"),
        test("...~", "3~12"), test("..........~", "3~12"),
        test("....~", "3~12"), test(".........~", "3~12"),
        test(".....~", "3~12"), test("........~", "3~12"),
        test("......~", "3~12"), test(".......~", "3~12"),

        test(".~", "23~1"), test("............~", "23~1"),
        test("..~", "23~1"), test("...........~", "23~1"),
        test("...~", "23~1"), test("..........~", "23~1"),
        test("....~", "23~1"), test(".........~", "23~1"),
        test(".....~", "23~1"), test("........~", "23~1"),
        test("......~", "23~1"), test(".......~", "23~1"),
//

        test(".~", "1234~"), test("............~", "1234~"),
        test("..~", "1234~"), test("...........~", "1234~"),
        test("...~", "1234~"), test("..........~", "1234~"),
        test("....~", "1234~"), test(".........~", "1234~"),
        test(".....~", "1234~"), test("........~", "1234~"),
        test("......~", "1234~"), test(".......~", "1234~"),

        test(".~", "43~12"), test("............~", "43~12"),
        test("..~", "43~12"), test("...........~", "43~12"),
        test("...~", "43~12"), test("..........~", "43~12"),
        test("....~", "43~12"), test(".........~", "43~12"),
        test(".....~", "43~12"), test("........~", "43~12"),
        test("......~", "43~12"), test(".......~", "43~12"),

        test(".~", "0123456789ABCDE~"),
        test(".~", "0123456789ABCDEF~"),
        test(".~", "0123456789ABCDEFG~"),
        test(".~", "0123456789ABCDEFGH~"),
        test(".~", "0123456789ABCDEFGHI~"),
        test(".~", "0123456789ABCDEFGHIJ~"),
        test(".~", "0123456789ABCDEFGHIJK~"),
        test(".~", "0123456789ABCDEFGHIJKL~"),
        test(".~", "0123456789ABCDEFGHIJKLM~"),
        test(".~", "0123456789ABCDEFGHIJKLMN~"),
        test(".~", "0123456789ABCDEFGHIJKLMNO~"),
        test(".~", "0123456789ABCDEFGHIJKLMNOP~"),
        test(".~", "0123456789ABCDEFGHIJKLMNOPQ~"),
        test(".~", "0123456789ABCDEFGHIJKLMNOPQR~"),
        test(".~", "0123456789ABCDEFGHIJKLMNOPQRS~"),
        test(".~", "0123456789ABCDEFGHIJKLMNOPQRST~"),
        test(".~", "0123456789ABCDEFGHIJKLMNOPQRSTU~"),
        test(".~", "0123456789ABCDEFGHIJKLMNOPQRSTUV~"),
        test(".~", "0123456789ABCDEFGHIJKLMNOPQRSTUVW~"),
        test(".~", "0123456789ABCDEFGHIJKLMNOPQRSTUVWX~"),
        test(".~", "0123456789ABCDEFGHIJKLMNOPQRSTUVWXY~"),
        test(".~", "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ~"),
#undef  test
    };

    for (int i=0; i < lengthof(tests); ctr++, i++) {
        t = tests[i];
        ans =  strcspn(t.str, t.set);
        spn = BSTRCPRL(t.str, t.set, max);
        if (spn != ans) {
            (void) printf(
                "line %d: STRCPRL(%s, %s, %zu) => %zu (expected %zu)\n",
                t.lno,
                BSTRREPR(lhs, t.str, sizeof lhs),
                BSTRREPR(rhs, t.str, sizeof rhs),
                max, spn, ans
            );
            exit(1);
        }
        while (spn > 0) {
            spn = BSTRCPRL(t.str, t.set, spn);
            if (spn == ans) break;
            goto fail;
        }
        while (ans > 1) {
            ans--;
            lim = BSTRCPRL(t.str, t.set, ans);
            if (ans == lim) break;
            fail: {
                (void) printf(
                    "line %d: STRCPRL(%s, %s, %zu) => %zu (expected %zu)\n",
                    t.lno,
                    BSTRREPR(lhs, t.str, sizeof lhs),
                    BSTRREPR(rhs, t.str, sizeof rhs),
                    ans, lim, spn
                );
                exit(1);
            }
        }
    }
    TESTS_PASSED();
}


#endif
