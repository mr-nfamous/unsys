/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳    

Compute the maximal array prefix length.

MEMPRL(mem, len, set, nel)
    The prefix contains only members in a set

MEMCPRL(mem, len, set, nel)
    The prefix contains only members not in a set

STRCPRL(str, set, nel)
STRPRL(str, set, nel)
    Identical to {strspn} and {strcspn} except {nel} can limit
    the comparison to at most {nel} elements of {str}.

STRLEN(str)
STRNLEN(str, nel)
    These are aliases of the standard {strlen} and {strnlen} 
    which are semantically identical to {strcspn(str, "")}.
STRSIZE(str, len)
    Get the size in bytes of the array needed to represent an 
    up to {len} element substring of {str}. This operation is
    semantically identical to {STRNLEN(str, len)+1}.
    
*/


static inline size_t
MEM_F(PFX)(const void *mem, chr_t chr, size_t nel) {
    for (size_t i=0;; i++) {
        if (nel==i || chr!=UCA(mem)[i]) return i;
    }
}

static inline size_t
MEM_F(SFX)(const void *mem, chr_t chr, size_t nel) {
    if (nel == 0) return 0;
    if (nel == 1) return chr == *UCA(mem);
    for (size_t i=nel-1;; i--) {
        if (chr != UCA(mem)[i]) return i;
    }
}

static inline size_t
MEM_F(PRL)(const void *mem, size_t len, const void *set, size_t nel) {
    if (len == 0) return 0;
    if (nel == 0) return 0;
    for (size_t b=0, e=0;;) {
        if (UCA(mem)[b] == UCA(set)[e]) {
            if (len == ++b) return b;
            e = 0;
        }
        else {
            if (nel == ++e) return b;
        }
    }
}

static inline size_t
MEM_F(CPRL)(const void *mem, size_t len, const void *set, size_t nel) {
    if (len == 0) return 0;
    if (nel == 0) return len;
    for (size_t b=0;;) {
        for (size_t e=0;;) {
            if (UCA(mem)[b] == UCA(set)[e]) return b;
            if (nel != ++e) continue;
            if (len == ++b) return b;
            break;
        }
    }
}

static inline size_t
STR_F(PRL)(const chr_t *str, const chr_t *brk, size_t nel) {
    if (!*str || !*brk || !nel) return 0;
    if (nel > PTRDIFF_MAX)
#   if   chr_width ==  8 && defined(bstrspn)
        return bstrspn(str, brk);
#   elif chr_width == 16 && defined(hstrspn)
        return hstrspn(str, brk);
#   elif chr_width == 32 && defined(ustrspn)
        return ustrspn(str, brk);
#   else
        nel = STR_F(LEN)(str);
#   endif
    size_t c = 0;
    if (!brk[1]) {
        for (const chr_t v=*brk; c < nel && str[c] == v; c++) {}
        return (size_t) c;
    }
    for (size_t i; c < nel; c++) {
        if (str[c] == *brk) continue;
        for (i=1;; i++) {
            if (str[c] == brk[i]) break;
            if (str[c] == 0) return (size_t) c;
        }
    }
    return (size_t) c;
}

static inline size_t
STR_F(CPRL)(const chr_t *str, const chr_t *brk, size_t nel) {
    if (nel > PTRDIFF_MAX)
#if   chr_width ==  8 && defined(bstrcspn)
        return bstrcspn(str, brk);
#elif chr_width == 16 && defined(hstrcspn)
        return hstrcspn(str, brk);
#elif chr_width == 16 && defined(ustrcspn)
        return ustrcspn(str, brk);
#else
        nel = 0;
#endif
    char b=*str, w, x, y, z;
    if (!b || b == (w=brk[0])) return 0;
    size_t c;
    if (!w) {
        if (nel) for (c=1; c<nel && str[c]; c++) {}
        else     for (c=1;          str[c]; c++) {}
        return c;
    }
    if (!(x=brk[1])) {
        if (nel) for(c=1; c<nel && (b=str[c]) && b!=w; c++) {}
        else     for(c=1;          (b=str[c]) && b!=w; c++) {}
        return c;
    }
    if (b == x) return 0;
    if (!(y=brk[2])) {
        if (nel) for(c=1; c<nel && (b=str[c]) && b!=w && b!=x; c++) {}
        else     for(c=1;          (b=str[c]) && b!=w && b!=x; c++) {}
        return c;
    }
    if (b == y) return 0;
    if (!(z=brk[3])) {
        if (nel) for(c=1; c<nel && (b=str[c]) && b!=w && b!=x && b!=y; c++) {}
        else     for(c=1;          (b=str[c]) && b!=w && b!=x && b!=y; c++) {}
        return c;
    }
    if (b == z) return 0;
    if (!brk[4]) {
        b = z;
        BTRISORT(&w, &x, &y);
        if (z < x) {
            if (z < w) {z=y, y=x, x=w, w=b;}
            else       {z=y, y=x, x=b;}
        }
        else {
            if (b < y) {z=y, y=b;}
        }
        if (nel) {
            for (c=1; c<nel && (b=str[c]); c++) {
                if (b<=x ? b==w || b==x : b==y || b==z) break;
            }
        }
        else {
            for (c=1; (b=str[c]); c++) {
                if (b<=x ? b==w || b==x : b==y || b==z) break;
            }
        }
        return c;
    }
    size_t i = 5;
    for (; brk[i]; i++) {
        if (b == brk[i]) return 0;
    }
    const size_t j = i;
    if (nel) {
        for (c=1; c<nel && (b=str[c]); c++) {
            if (b==w || b==x || b==y || b==z) return c;
            for (i=4; i < j; i++)
                if (b == brk[i]) return c;
        }
    }
    else {
        for (c=1; (b=str[c]); c++) {
            if (b==w || b==x || b==y || b==z) return c;
            for (i=4; i < j; i++)
                if (b == brk[i]) return c;
        }
    }
    return c;
}

static inline size_t
STR_F(LEN)(const chr_t *str) {
#if   chr_width ==  8 && defined(bstrlen)
    return bstrlen(str);
#elif chr_width == 16 && defined(hstrlen)
    return hstrlen(str);
#elif chr_width == 32 && defined(ustrlen)
    return ustrlen(str);
#else
    for (size_t i=0;; i++) {if (!str[i]) {return i;}}
#endif
}

static inline size_t
STR_F(NLEN)(const chr_t *str, size_t max) {
#if   chr_width ==  8 && defined(bstrnlen)
    return bstrnlen(str, max);
#elif chr_width == 16 && defined(hstrnlen)
    return hstrnlen(str, max);
#elif chr_width == 32 && defined(ustrnlen)
    return ustrnlen(str, max);
#else
    for (size_t i=0;; i++) {if (i == max || !str[i]) {return i;}}
#endif
}

static inline size_t
STR_F(SIZE)(const chr_t *str, size_t end) {
    return sizeof*str*(1+STR_F(NLEN)(str, end));
}


#if defined(TESTS_PASSED) && defined(STRPRL_TEST)

static void
MEM_F(CPRL_TEST)(void) {
    size_t ctr = 0;
#if chr_width == 8
    char set[256];
    char str[256];
    struct {
        const char *str;
        const char *set;
        size_t      prl;
        int         lno;
        size_t      sul;
    }
    tests[] = {
#define test(str,set,prl) {str,set,prl,__LINE__}
        //    0123456789abcdef
        test("................", "/",16),
        test("/...............", "/", 0),
        test("./..............", "/", 1),
        test("../.............", "/", 2),
        test(".../............", "/", 3),
        test("..../...........", "/", 4),
        test("...../..........", "/", 5),
        test("....../.........", "/", 6),
        test("......./........", "/", 7),
        test("......../.......", "/", 8),
        test("........./......", "/", 9),
        test("........../.....", "/",10),
        test(".........../....", "/",11),
        test("............/...", "/",12),
        test("............./..", "/",13),
        test("............../.", "/",14),
        test(".............../", "/",15),

        test("............/...", "/0",12),
        test("............/...", "0/",12),
        
        test("............./..", "/0",13),
        test("............./..", "0/",13),
        
        test("............../.", "/0",14),
        test("............../.", "0/",14),
        
        test(".............../", "/0",15),
        test(".............../", "0/",15),
        
        test("................", "/0",16),
        test("................", "0/",16),


        test("............/...", "/01",12),
        test("............/...", "0/1",12),
        test("............/...", "01/",12),
        
        test("............./..", "/01",13),
        test("............./..", "0/1",13),
        test("............./..", "01/",13),
        
        test("............../.", "/01",14),
        test("............../.", "0/1",14),
        test("............../.", "01/",14),
        
        test(".............../", "/01",15),
        test(".............../", "0/1",15),
        test(".............../", "01/",15),
        
        test("................", "/01",16),
        test("................", "0/1",16),
        test("................", "01/",16),
  

        test("............/...", "/012",12),
        test("............/...", "0/12",12),
        test("............/...", "01/2",12),
        test("............/...", "012/",12),
        
        test("............./..", "/012",13),
        test("............./..", "0/12",13),
        test("............./..", "01/2",13),
        test("............./..", "012/",13),
        
        test("............../.", "/012",14),
        test("............../.", "0/12",14),
        test("............../.", "01/2",14),
        test("............../.", "012/",14),
        
        test(".............../", "/012",15),
        test(".............../", "0/12",15),
        test(".............../", "01/2",15),
        test(".............../", "012/",15),

        test("................", "/012",16),
        test("................", "0/12",16),
        test("................", "01/2",16),
        test("................", "012/",16),
    

        test("............/...", "/0123",12),
        test("............/...", "0/123",12),
        test("............/...", "01/23",12),
        test("............/...", "012/3",12),
        test("............/...", "0123/",12),
        
        test("............./..", "/0123",13),
        test("............./..", "0/123",13),
        test("............./..", "01/23",13),
        test("............./..", "012/3",13),
        test("............./..", "0123/",13),
        
        test("............../.", "/0123",14),
        test("............../.", "0/123",14),
        test("............../.", "01/23",14),
        test("............../.", "012/3",14),
        test("............../.", "0123/",14),
        
        test(".............../", "/0123",15),
        test(".............../", "0/123",15),
        test(".............../", "01/23",15),
        test(".............../", "012/3",15),
        test(".............../", "0123/",15),
        
        test("................", "/0123",16),
        test("................", "0/123",16),
        test("................", "01/23",16),
        test("................", "012/3",16),
        test("................", "0123/",16),


#undef  test

    }, t;

    for (; ctr < lengthof(tests); ctr++) {
        t = tests[ctr];
        size_t len = STR_F(LEN)(t.str);
        size_t nel = STR_F(LEN)(t.set);
        size_t prl = MEM_F(CPRL)(t.str, len, t.set, nel);
        if (prl != t.prl) {
            (void) printf("line %d %s:", t.lno, __func__);
            (void) printf(
                "MEMCPRL(%s, %zu, %s, %zi) ret %zu, not %zu\n",
                BSTRREPR(str, t.str, sizeof str), len,
                BSTRREPR(set, t.set, sizeof set), nel,
                prl, t.prl
            );
            exit(1);
        }
        t.sul = (len == prl) ? len : len-(prl+1);
        size_t sul = MEM_F(CSUL)(t.str, len, t.set, nel);
        if (sul != t.sul) {
            (void) printf("line %d %s:\n", t.lno, __func__);
            (void) printf(
                "MEMCSUL(%s, %zu, %s, %zi) ret %zu, not %zu\n",
                BSTRREPR(str, t.str, sizeof str), len,
                BSTRREPR(set, t.set, sizeof set), nel,
                prl, t.prl
            );
            exit(1);
        }
    }
            
#endif
    TESTS_PASSED();
}

static void
MEM_F(PRL_TEST)(void) {
    size_t ctr = 0;
#if chr_width == 8
    char set[256];
    char str[256];
    struct {
        const char *str;
        const char *set;
        size_t      prl;
        int         lno;
        size_t      sul;
    }
    tests[] = {

#define test(str,set,prl) {str,set,prl,__LINE__}

        test("/...............", ".", 0),
        test("./..............", ".", 1),
        test("../.............", ".", 2),
        test(".../............", ".", 3),
        test("..../...........", ".", 4),
        test("...../..........", ".", 5),
        test("....../.........", ".", 6),
        test("......./........", ".", 7),
        test("......../.......", ".", 8),
        test("........./......", ".", 9),
        test("........../.....", ".",10),
        test(".........../....", ".",11),
        test("............/...", ".",12),
        test("............./..", ".",13),
        test("............../.", ".",14),
        test(".............../", ".",15),
        test("................", ".",16),

        test("............/...", ".01",12),
        test("............/...", "0.1",12),
        test("............/...", "01.",12),
        
        test("............./..", ".01",13),
        test("............./..", "0.1",13),
        test("............./..", "01.",13),
        
        test("............../.", ".01",14),
        test("............../.", "0.1",14),
        test("............../.", "01.",14),
        
        test(".............../", ".01",15),
        test(".............../", "0.1",15),
        test(".............../", "01.",15),
        
        test("................", ".01",16),
        test("................", "0.1",16),
        test("................", "01.",16),

        test("............/...", ".012",12),
        test("............/...", "0.12",12),
        test("............/...", "01.2",12),
        test("............/...", "012.",12),
        
        test("............./..", ".012",13),
        test("............./..", "0.12",13),
        test("............./..", "01.2",13),
        test("............./..", "012.",13),
        
        test("............../.", ".012",14),
        test("............../.", "0.12",14),
        test("............../.", "01.2",14),
        test("............../.", "012.",14),
        
        test(".............../", ".012",15),
        test(".............../", "0.12",15),
        test(".............../", "01.2",15),
        test(".............../", "012.",15),

        test("................", ".012",16),
        test("................", "0.12",16),
        test("................", "01.2",16),
        test("................", "012.",16),

        test("............/...", ".0123",12),
        test("............/...", "0.123",12),
        test("............/...", "01.23",12),
        test("............/...", "012.3",12),
        test("............/...", "0123.",12),
        
        test("............./..", ".0123",13),
        test("............./..", "0.123",13),
        test("............./..", "01.23",13),
        test("............./..", "012.3",13),
        test("............./..", "0123.",13),
        
        test("............../.", ".0123",14),
        test("............../.", "0.123",14),
        test("............../.", "01.23",14),
        test("............../.", "012.3",14),
        test("............../.", "0123.",14),
        
        test(".............../", ".0123",15),
        test(".............../", "0.123",15),
        test(".............../", "01.23",15),
        test(".............../", "012.3",15),
        test(".............../", "0123.",15),
        
        test("................", ".0123",16),
        test("................", "0.123",16),
        test("................", "01.23",16),
        test("................", "012.3",16),
        test("................", "0123.",16),

#undef  test

    }, t;

    for (; ctr < lengthof(tests); ctr++) {
        t = tests[ctr];
        size_t len = STR_F(LEN)(t.str);
        size_t nel = STR_F(LEN)(t.set);
        size_t prl = MEM_F(PRL)(t.str, len, t.set, nel);
        if (prl != t.prl) {
            (void) printf("line %d %s:", t.lno, __func__);
            (void) printf(
                "MEMPRL(%s, %zu, %s, %zi) ret %zu, not %zu\n",
                BSTRREPR(str, t.str, sizeof str), len,
                BSTRREPR(set, t.set, sizeof set), nel,
                prl, t.prl
            );
            exit(1);
        }
        t.sul = (len == prl) ? len : len-(prl+1);
        size_t sul = MEM_F(SUL)(t.str, len, t.set, nel);
        if (sul != t.sul) {
            (void) printf("line %d %s:\n", t.lno, __func__);
            (void) printf(
                "MEMSUL(%s, %zu, %s, %zi) ret %zu, not %zu\n",
                BSTRREPR(str, t.str, sizeof str), len,
                BSTRREPR(set, t.set, sizeof set), nel,
                prl, t.prl
            );
            exit(1);
        }
    }
            
#endif
    TESTS_PASSED();
}

static void
STR_F(PRL_TEST)(void) {
    size_t ctr = 0;
#if 0 && (chr_width == 8)
    const char *set, *str;
    size_t msz, len, spn, ans, max=0;
    int lno;
    char lhs[256];
    char rhs[256];
    struct strprl_test {
        const char *str;
        size_t      len;
        const char *set;
        size_t      nel;
        size_t      prl;
        int         lno;
    } tests[] = {
#define test(m,s,a) {m, strlen(m), s, strlen(s), a, __LINE__}
        test("0","", 0),
        test("1","0", 0),
        test("2","01", 0),
        test("3","012", 0),
        test("4","0123", 0),
        test("5","01234", 0),
        test("6","012345", 0),
        test("7","0123456", 0),
        test("8","01234567", 0),
        test("9","012345678", 0),
        test("a","0123456789", 0),
        test("b","0123456789a", 0),
        test("c","0123456789ab", 0),
        test("d","0123456789abc", 0),
        test("e","0123456789abcd", 0),
        test("f","0123456789abcde", 0),
        test("g","0123456789abcdef", 0),
        test("h","0123456789abcdefg", 0),
        test("i","0123456789abcdefgh", 0),
        test("j","0123456789abcdefghi", 0),
        test("_","0123456789abcdefghij", 0),
        test("_","0123456789abcdefghijk", 0),
        test("_","0123456789abcdefghijkl", 0),
        test("_","0123456789abcdefghijklm", 0),
        test("_","0123456789abcdefghijklmn", 0),
        test("_","0123456789abcdefghijklmno", 0),
        test("_","0123456789abcdefghijklmnop", 0),
        test("_","0123456789abcdefghijklmnopq", 0),
        test("_","0123456789abcdefghijklmnopqr", 0),
        test("_","0123456789abcdefghijklmnopqrs", 0),
        test("_","0123456789abcdefghijklmnopqrst", 0),
        test("_","0123456789abcdefghijklmnopqrstu", 0),
        test("_","0123456789abcdefghijklmnopqrstuv", 0),
        test("_","0123456789abcdefghijklmnopqrstuvw", 0),
        test("_","0123456789abcdefghijklmnopqrstuvwx", 0),
        test("_","0123456789abcdefghijklmnopqrstuvwxy", 0),
        test("_","0123456789abcdefghijklmnopqrstuvwxyz", 0),

#undef  test
#define test(m,s) {m, strlen(m), s, strlen(s), strlen(m), __LINE__}
        test("0","0"),
        test("00","0"),
        test("000","0"),
        test("0000","0"),
        test("00000","0"),
        test("000000","0"),
        test("0000000","0"),
        test("00000000","0"),
        test("000000000","0"),
        test("0","01"),
        test("1","01"),
        test("00","01"),
        test("01","01"),
        test("10","01"),
        test("11","01"),
        test("111","01"),
        test("1111","01"),
        test("11111","01"),
        test("111111","01"),
        test("111111","01"),
        test("1111111","01"),
        test("11111111","01"),
        test("0","012"),
        test("1","012"),
        test("2","012"),
        test("22","012"),
        test("222","012"),
        test("2222","012"),
        test("22222","012"),
        test("222222","012"),
        test("2222222","012"),
        test("22222222","012"),
        test("0","0123"),
        test("1","0123"),
        test("2","0123"),
        test("3","0123"),
        test("33","0123"),
        test("333","0123"),
        test("3333","0123"),
        test("33333","0123"),
        test("333333","0123"),
        test("3333333","0123"),
        test("33333333","0123"),
        test("0123", "0123"),
        test("1230", "0123"),
        test("2301", "0123"),
        test("3012", "0123"),
        test("4", "01234"),
        test("0", "01234"),
        test("1", "01234"),
        test("2", "01234"),
        test("3", "01234"),
        test("4", "01234"),
        test("44", "01234"),
        test("444", "01234"),
        test("4444", "01234"),
        test("44444", "01234"),
        test("444444", "01234"),
        test("4444444", "01234"),
        test("44444444", "01234"),
        test("01234", "01234"),
        test("40123", "01234"),
        test("34012", "01234"),
        test("23401", "01234"),
        test("12340", "01234"),
        test("5","012345"),
        test("012345","012345"),
        test("543210","012345"),
        test("6","0123456"),
        test("6543210","0123456"),
        test("7","01234567"),
        test("8","012345678"),
        test("9","0123456789"),
        test("a","0123456789a"),
        test("b","0123456789ab"),
        test("c","0123456789abc"),
        test("d","0123456789abcd"),
        test("e","0123456789abcde"),
        test("f","0123456789abcdef"),
        test("g","0123456789abcdefg"),
        test("h","0123456789abcdefgh"),
        test("i","0123456789abcdefghi"),
        test("ihgfedcba9876543210","0123456789abcdefghi"),

        test("_0","0_"),
        test("_1","01_'"),
        test("_2","012_"),
        test("_3","0123_"),
        test("_4","01234_"),
        test("_5","012345_"),
        test("_6","0123456_"),
        test("_7","01234567_"),
        test("_8","012345678_"),
        test("_9","0123456789_"),
        test("_a","0123456789_a"),
        test("_b","0123456789_ab"),
        test("_c","0123456789_abc"),
        test("_d","0123456789_abcd"),
        test("_e","0123456789_abcde"),
        test("_f","0123456789_abcdef"),
        test("_g","0123456789_abcdefg"),
        test("_h","0123456789_abcdefgh"),
        test("_i","0123456789_abcdefghi"),
#undef  test
    }, t;

    for (; ctr < lengthof(tests); ctr++) {
        t = tests[ctr];
        size_t prl = STR_F(PRL)(t.str, t.set);
        if (t.prl != prl)  {
            (void) printf(
                "line %d: STRPRL(%s, %s) ret %zu, not %zu\n",
                lno,
                BSTRREPR(lhs, str, sizeof lhs),
                BSTRREPR(rhs, str, sizeof rhs),
                prl, t.prl
            );
            exit(1);
        }
    }
#endif
    TESTS_PASSED();
}

static void
STR_F(LEN_TEST)(void) {
    size_t ctr = 0;
    char str[256];
    (void) memset(str, 255, sizeof str);
    for (size_t i=0; i < (sizeof str-1); ctr++, i++) {
        memset(str, ' ', i);
        str[i] = 0;
        size_t len = BSTRLEN(str);
        if (strlen(str) != len) {
            printf("BSTRLEN(str) => %zu, not %zu\n", len, strlen(str));
            exit(1);
        }
    }
    TESTS_PASSED();
}

#endif // defined(TEST_PASSED)
