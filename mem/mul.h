
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

Array repetition

MEMMUL(dst, src, nel, mul)
    Write {mul} end to end copies of the {nel} element array
    to {dst}.

STRMUL(dst, src, mul)
    Write {mul} end to end copies of the nul terminated {src}
    to {dst} followed by a nul.

STRSMUL(dst, src, mul)
    Identical to {STRMUL} except {dst} is a nul terminated
    array and if {STRSIZE(dst, -1) <= STRLEN(src)*mul}, the
    operation fails, setting {errno=ENOSPC} before returning
    NULL. A terminating nul *IS NOT* added to the end. This 
    isn't a problem since {dst} must be properly terminated
    from the start, but it does mean the contents in {dst} 
    following the copies don't get "clobbered".

*/


static inline void *
MEM_F(SET)(void *dst, chr_t b, size_t nel) {
#if   chr_width ==  8 && defined(bmemset)
    return bmemset(dst, b, nel);
#elif chr_width == 16 && defined(hmemset)
    return hmemset(dst, b, nel);
#elif chr_width == 32 && defined(umemset)
    return umemset(dst, b, nel);
#else
    chr_t *d = dst;
    for (; nel > 7; nel-=8, d+=8) {
        d[0]=b, d[1]=b, d[2]=b, d[3]=b, d[4]=b, d[5]=b, d[6]=b, d[7]=b;
    }
    if (nel < 4) {
        if (nel < 2) {if (nel == 0) {goto s0;} else {goto s1;}}
        else         {if (nel == 3) {goto s3;} else {goto s2;}}
    }
    if (nel < 6)     {if (nel == 5) {goto s5;} else {goto s4;}}
    else             {if (nel == 6) {goto s6;}}
    s7: {d[6]=b;}
    s6: {d[5]=b;}
    s5: {d[4]=b;}
    s4: {d[3]=b;}
    s3: {d[2]=b;}
    s2: {d[1]=b;}
    s1: {d[0]=b;}
    s0: {return dst;}
#endif
}

static inline void *
MEM_F(MUL)(void *dst, const void *src, size_t nel, size_t mul) {
    if (nel == 0 || mul == 0) return dst;
    if (nel == 1) return MEM_F(SET)(dst, *UCA(src), mul);
    (void) MEM_F(MOV)(dst, src, nel);
    if (mul == 1) return dst;
    for (size_t q, p=nel, r=mul*nel;; p=q) {
        q = p<<1;
        if (q >= r) {
            (void) MEM_F(CPY)(dst+p, dst, r-p);
            return dst;
        }
        (void) MEM_F(CPY)(dst+p, dst, p);
    }
}

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

static inline chr_t *
STR_F(SET)(chr_t str[], chr_t chr) {
#if   chr_width ==  8 && defined(bstrset)
    return bstrset(str, chr);
#elif chr_width == 16 && defined(hstrset)
    return hstrset(str, chr);
#elif chr_width == 32 && defined(ustrset)
    return ustrset(str, chr);
#else
    for (size_t i=0;; i++) {
        if (!str[i]) return str;
        str[i] = chr;
    }
#endif
}

static inline chr_t *
STR_F(LSET)(chr_t str[], chr_t chr, size_t len) {
#if   chr_width ==  8 && defined(bstrnset)
    return bstrnset(str, chr, len);
#elif chr_width == 16 && defined(hstrset)
    return hstrnset(str, chr, len);
#elif chr_width == 32 && defined(ustrset)
    return ustrnset(str, chr, len);
#else
    for (size_t i=0; i < len && str[i]; str[i++]=chr) {}
    return str;
#endif
}

static inline chr_t *
STP_F(SET)(chr_t str[], chr_t chr) {
    while (*str) *str++ = chr; return  str;
}

static inline chr_t *
STP_F(LSET)(chr_t str[], chr_t chr, size_t len) {
    for (;; len--) {
        if (!*str || !len) return str;
        *str++ = chr;
    }
}

#if defined(TESTS_PASSED) && defined(STRMUL_TEST)

static void
MEM_F(SET_TEST)(void) {
    size_t ctr = 0;
#if chr_width == 8
    size_t nchr;
    size_t nnul;
    char b[257] = {0};
    char m[sizeof b] = {0};
    for (nchr=0; nchr < sizeof b-1; ctr++, nchr++) {
        nnul = sizeof b-nchr;
        (void)     memset(memset(b, 255, nchr)+nchr, 0, nnul);
        (void) MEM_F(SET)(memset(m, 255, nchr)+nchr, 0, nnul);
        if (memcmp(b, m, sizeof b)) {
            printf("memset fail (len=%zu):\n", nchr);
            exit(1);
        }
    }
#endif
    TESTS_PASSED();
}

static void
MEM_F(MUL_TEST)(void) {

    size_t ctr = 0;
    
#if chr_width == 8

    struct {
        const chr_t*str;
        size_t      mul;
        const chr_t*res;
        int         lno;
    }

    tests[] = {

#define test(s,n,...) {.str=s, .mul=n, .res=__VA_ARGS__, .lno=__LINE__}
#define test0(s, ...) test(s, 0, #__VA_ARGS__)
#define test1(s) test(s, 1,                   s)
#define test2(s) test(s, 2,                 s s)
#define test3(s) test(s, 3,               s s s)
#define test4(s) test(s, 4,             s s s s)
#define test5(s) test(s, 5,           s s s s s)
#define test6(s) test(s, 6,         s s s s s s)
#define test7(s) test(s, 7,       s s s s s s s)
#define test8(s) test(s, 8,     s s s s s s s s)
#define test9(s) test(s, 9,   s s s s s s s s s)
#define testa(s) test(s,10, s s s s s s s s s s)

        test0(""), test0(".0123456789abcdef"),
        test0("."), test0(".0123456789abcde"),
        test0(".0"), test0(".0123456789abcd"),
        test0(".01"), test0(".0123456789abc"),
        test0(".012"), test0(".0123456789ab"),
        test0(".0123"), test0(".0123456789a"),
        test0(".01234"), test0(".0123456789"),
        test0(".012345"), test0(".012345678"),
        test0(".0123456"), test0(".01234567"),

        test1(""), test1(".0123456789abcdef"),
        test1("."), test1(".0123456789abcde"),
        test1(".0"), test1(".0123456789abcd"),
        test1(".01"), test1(".0123456789abc"),
        test1(".012"), test1(".0123456789ab"),
        test1(".0123"), test1(".0123456789a"),
        test1(".01234"), test1(".0123456789"),
        test1(".012345"), test1(".012345678"),
        test1(".0123456"), test1(".01234567"),

        test2(""), test2(".0123456789abcdef"),
        test2("."), test2(".0123456789abcde"),
        test2(".0"), test2(".0123456789abcd"),
        test2(".01"), test2(".0123456789abc"),
        test2(".012"), test2(".0123456789ab"),
        test2(".0123"), test2(".0123456789a"),
        test2(".01234"), test2(".0123456789"),
        test2(".012345"), test2(".012345678"),
        test2(".0123456"), test2(".01234567"),

        test3(""), test3(".0123456789abcdef"),
        test3("."), test3(".0123456789abcde"),
        test3(".0"), test3(".0123456789abcd"),
        test3(".01"), test3(".0123456789abc"),
        test3(".012"), test3(".0123456789ab"),
        test3(".0123"), test3(".0123456789a"),
        test3(".01234"), test3(".0123456789"),
        test3(".012345"), test3(".012345678"),
        test3(".0123456"), test3(".01234567"),

        test4(""), test4(".0123456789abcdef"),
        test4("."), test4(".0123456789abcde"),
        test4(".0"), test4(".0123456789abcd"),
        test4(".01"), test4(".0123456789abc"),
        test4(".012"), test4(".0123456789ab"),
        test4(".0123"), test4(".0123456789a"),
        test4(".01234"), test4(".0123456789"),
        test4(".012345"), test4(".012345678"),
        test4(".0123456"), test4(".01234567"),

        test5(""), test5(".0123456789abcdef"),
        test5("."), test5(".0123456789abcde"),
        test5(".0"), test5(".0123456789abcd"),
        test5(".01"), test5(".0123456789abc"),
        test5(".012"), test5(".0123456789ab"),
        test5(".0123"), test5(".0123456789a"),
        test5(".01234"), test5(".0123456789"),
        test5(".012345"), test5(".012345678"),
        test5(".0123456"), test5(".01234567"),

        test6(""), test6(".0123456789abcdef"),
        test6("."), test6(".0123456789abcde"),
        test6(".0"), test6(".0123456789abcd"),
        test6(".01"), test6(".0123456789abc"),
        test6(".012"), test6(".0123456789ab"),
        test6(".0123"), test6(".0123456789a"),
        test6(".01234"), test6(".0123456789"),
        test6(".012345"), test6(".012345678"),
        test6(".0123456"), test6(".01234567"),

        test7(""), test7(".0123456789abcdef"),
        test7("."), test7(".0123456789abcde"),
        test7(".0"), test7(".0123456789abcd"),
        test7(".01"), test7(".0123456789abc"),
        test7(".012"), test7(".0123456789ab"),
        test7(".0123"), test7(".0123456789a"),
        test7(".01234"), test7(".0123456789"),
        test7(".012345"), test7(".012345678"),
        test7(".0123456"), test7(".01234567"),

        test8(""), test8(".0123456789abcdef"),
        test8("."), test8(".0123456789abcde"),
        test8(".0"), test8(".0123456789abcd"),
        test8(".01"), test8(".0123456789abc"),
        test8(".012"), test8(".0123456789ab"),
        test8(".0123"), test8(".0123456789a"),
        test8(".01234"), test8(".0123456789"),
        test8(".012345"), test8(".012345678"),
        test8(".0123456"), test8(".01234567"),

        test9(""), test9(".0123456789abcdef"),
        test9("."), test9(".0123456789abcde"),
        test9(".0"), test9(".0123456789abcd"),
        test9(".01"), test9(".0123456789abc"),
        test9(".012"), test9(".0123456789ab"),
        test9(".0123"), test9(".0123456789a"),
        test9(".01234"), test9(".0123456789"),
        test9(".012345"), test9(".012345678"),
        test9(".0123456"), test9(".01234567"),

        testa(""), testa(".0123456789abcdef"),
        testa("."), testa(".0123456789abcde"),
        testa(".0"), testa(".0123456789abcd"),
        testa(".01"), testa(".0123456789abc"),
        testa(".012"), testa(".0123456789ab"),
        testa(".0123"), testa(".0123456789a"),
        testa(".01234"), testa(".0123456789"),
        testa(".012345"), testa(".012345678"),
        testa(".0123456"), testa(".01234567"),
#undef  test0
#undef  test1
#undef  test2
#undef  test3
#undef  test4
#undef  test5
#undef  test6
#undef  test7
#undef  test8
#undef  test9
#undef  testa
#undef  test
    }, t;
    
    for (; ctr < lengthof(tests); ctr++) {
        char buf[1024] = {0};
        char tmp[256];
        char lhs[1024];
        char rhs[1024];
        t = tests[ctr];
        size_t one = strlen(t.str);
        size_t all = strlen(t.res);
        if (all >= sizeof buf) {
            (void) printf(
                "line %d: strlen(t.res) >= sizeof buf (%zu > %zu)\n",
                t.lno, all, sizeof buf
            );
           exit(1);
        }
        void *pro;
        if (buf != (pro=MEM_F(MUL)(buf, t.str, one, t.mul))) {
            (void) printf(
                "%s line %d: MEMMUL(..., %s, %zu, %zu) ret %p, not %p\n", 
                __func__, t.lno, 
                BSTRREPR(lhs, t.str, sizeof lhs), one,
                t.mul,
                pro, buf
            );
            exit(1);
        }
        if (memcmp(buf, t.res, all)) {
            (void) printf("%s line %d:",__func__,t.lno);
            (void) printf("%s != ", BSTRREPR(tmp,   buf, sizeof tmp));
            (void) printf("%s\n",   BSTRREPR(tmp, t.res, sizeof tmp));
            exit(1);
        }
    }
#endif
    TESTS_PASSED();
}

#endif // defined(TESTS_PASSED)
