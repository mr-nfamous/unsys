/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

Array element search

MEMCHR(a, c, n)
    Use linear search to find {c} within the first {n}

MEMBCHR(a, c, n)
    Use binary search to find {c} in the sorted array of {n}
  

*/

static inline void *
MEM_F(BCHR)(const void *mem, char32_t chr, size_t nel) {
    if (nel < 4) switch (nel) {
        case 3: if (UCA(mem)[2] == chr) return UCA(mem)+2;
        case 2: if (UCA(mem)[1] == chr) return UCA(mem)+1;
        case 1: if (UCA(mem)[0] == chr) return UCA(mem);
        case 0: return NULL;
    }
    size_t mid = nel>>1;
    size_t min = 0;
    for (char32_t v;;) {
        v = UCA(mem)[mid];
        if (chr == v)   return mid+UCA(mem);
        if (chr <  v)   nel = (mid);
        else            min = (mid+1);
        if (min < nel)  mid = (min+nel)>>1;
        else return NULL;
    }
}

static inline void *
MEM_F(CHR)(const void *m, chr_t c, size_t n) {
#if   chr_width ==  8 && defined(bmemchr)
    return bmemchr(m, c, n);
#elif chr_width == 16 && defined(hmemchr)
    return hmemchr(m, c, n);
#elif chr_width == 32 && defined(umemchr)
    return umemchr(m, c, n);
#else
    for (size_t i=0; i < n; i++) {
        if (c == UCA(m)[i]) return i+UCA(m);
    }
    return NULL;
#endif
}

static inline void *
MEM_F(RCHR)(const void *mem, chr_t chr, size_t len) {
#if   chr_width ==  8 && defined(bmemrchr)
    return bmemrchr(mem, chr, len);
#elif chr_width == 16 && defined(hmemrchr)
    return hmemrchr(mem, chr, len);
#elif chr_width == 32 && defined(umemrchr)
    return umemrchr(mem, chr, len);
#else
    while (len) {
        if (chr == UCA(mem)[--len]) return UCA(mem)+len;
    }
    return NULL;
#endif
}

static inline chr_t *
STR_F(CHR)(const chr_t str[], chr_t chr) {
#if   chr_width ==  8 && defined(bstrchr)
     return bstrchr(str, chr);
#elif chr_width == 16 && defined(hstrchr)
    return hstrchr(str, chr);
#elif chr_width == 32 && defined(ustrchr)
    return ustrchr(str, chr);
#else
    if (!chr) {for (; *str != 000; str++) {}}
    else      {for (; *str != chr; str++) {if (!*str) {return NULL;}}}
    return UCA(str);
#endif
}

static inline chr_t *
STR_F(LCHR)(const chr_t str[], chr_t chr, size_t len) {
    if (!str || !len) return NULL;
    if (len > PTRDIFF_MAX) return STR_F(CHR)(str, chr);
    if (*str) {
        if (!chr) {
            for (; --len; str++) {if (!*str) break;}
        }
        else {
            for (; --len; str++) {
                if (!*str || *str==chr) break;
            }
        }
    }
    return UCA(str);
}

static inline chr_t *
STR_F(RCHR)(const chr_t str[], chr_t chr) {
#if   chr_width ==  8 && defined(bstrrchr)
    return bstrrchr(str, chr);
#elif chr_width == 16 && defined(hstrrchr)
    return hstrrchr(str, chr);
#elif chr_width == 32 && defined(ustrrchr)
    return ustrrchr(str, chr);
#else
    if (!chr) for (;;  str++) {if (!*str) return UCA(str);}
    const chr_t *lhs = NULL;
    for (; ; str++) {
        if (*str == chr) break;
        if (*str == 000) {
            if (!lhs) return NULL; 
            goto the_end;
        }
    }
    if (!str[1]) return UCA(str);
    for (str++;; str++) {
        if (!str[1]) break;
    }
    the_end: {
        if (--str > lhs && chr == *str) return UCA(str);
        goto the_end;
    }
    return UCA(lhs);
#endif
}

static inline chr_t *
STR_F(LAST)(const char str[], size_t nel) {
    chr_t *end;
#if   chr_width ==  8 && defined(bstrchr)
    end = bstrchr(str, 0);
#elif chr_width == 16 && defined(hstrchr)
    end = hstrchr(str, 0);
#elif chr_width == 16 && defined(ustrchr)
    end = ustrchr(str, 0);
#else
    for (end=str; *end; end++) {}
#endif
    const ptrdiff_t   len = end-str;
    return end+(nel < len ? len-nel : 0);
}

#if defined(TESTS_PASSED) && defined(MEMCHR_TEST)

static void
MEM_F(CHR_TEST)(void) {
    size_t ctr = 0;
#if chr_width == 8
    chr_t mem[257];
    (void) BRANGE(mem, 0, 255, 1);
    mem[256] = 0;

    for (size_t len=1; len<48; ctr++, len++) {
        const char *str = mem+32;
        for (size_t i=0; i < len; i++) {
            char c = str[i];
            char *p =  memchr(str, str[i], len);
            if (p == NULL) {
                printf("memchr(str, str[%zu], %zu) ret NULL\n", i, len);
                exit(1);
            }
            char *m = MEM_F(CHR)(str, str[i], len);
            if (m == p) continue;
            if (m == NULL) {
                printf("MEMCHR(str, str[%zu], %zu) ret NULL\n", i, len);
                exit(1);
            }
            printf (
                "MEMCHR(str, str[%zu], %zu) ret str[%td], not str[%zu]\n",
                i, len,
                m-str, i
            );
            exit(1);
        }
    }
#endif
    TESTS_PASSED();
}

static void
MEM_F(RCHR_TEST)(void) {
    size_t ctr = 0;
    const char *mem = "0123456789abcdefghijklmnopqrstuvwxyz";
    size_t len = strlen(mem);
    for (ptrdiff_t i=0; i < len; ctr++, i++) {
        char chr = mem[i];
        const char *p = BMEMRCHR(mem, chr, len);
        if (p == NULL) {
            printf("BMEMRCHR(mem, '%c', %zu) ret NULL\n",chr,len);
            exit(1);
        }
        if (p != (mem+i)) {
            printf(
                "BMEMRCHR(mem, '%c', %zu) ret &mem[%td]\n",
               chr, len, p-mem
            );
            exit(1);
        }
    }
    TESTS_PASSED();
}

static void
MEM_F(BCHR_TEST)(void) {
    size_t ctr = 0;
    const chr_t *cntrl = (chr_t[]){
        1,2,3,4,5,6,7,
        8,9,10,11,12,13,14,15,
        16,17,18,19,20,21,22,23,
        24,25,26,27,28,29,30,31,127, 0};
    
    const chr_t upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const chr_t lower[] = "abcdefghijklmnopqrstuvwxyz";
    const chr_t digit[] = "0123456789";
    const chr_t blank[] = "\t ";
    const chr_t space[] = "\t\n\v\f\r ";
    const chr_t lnbrk[] = "\n\v\f\r";
    const chr_t punct[] = "!\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~";
    struct {
        size_t cntrl,upper,lower,digit,blank,lnbrk,space,punct;
    } 
    len = {
        .cntrl=strlen(cntrl),
        .upper=strlen(upper),
        .lower=strlen(lower),
        .digit=strlen(digit),
        .blank=strlen(blank),
        .lnbrk=strlen(lnbrk),
        .punct=strlen(punct),
        .space=strlen(space),
    };
    for (chr_t c=1; c < 128; ctr++, c++) {
        const chr_t *m;
#define test(ctype) \
        m = MEM_F(BCHR)(ctype, c, len.ctype);\
        if (is##ctype(c)) \
        {if (m == 0) {(void) printf(\
            "line %d: bmembis(%s, %zu, 0x%02x) ret NULL\n",\
            __LINE__, #ctype, len.ctype, c); exit(1);}\
        }\
        else \
        {if (m != 0) {(void) printf(\
            "bmembis(%s, 0x%02x, %zu) ret %s[%td], not 0\n",\
            #ctype, c, len.ctype,    #ctype, m-ctype);exit(1);}\
        }
        test(cntrl)
        test(upper)
        test(lower)
        test(digit)
        test(punct)
        test(blank)
        test(space)
#undef  test   
    }
    TESTS_PASSED();
}

static void
STR_F(CHR_TES)(void) {
    size_t ctr = 0;
    struct {
        char str[255];
        unsigned char len;
        char chr;
        ptrdiff_t lhs;
        ptrdiff_t rhs;
        int lno;
    } t[] = {
#define test(s, c, l, r) {s,(unsigned char) strlen(s),c,l,r,__LINE__}
        //                    0123
        test("0123456789abcdef0023", 'z', 0-1,  0-1),
        test("0123456789abcdef0023", '0', 0x00, 0x11),
        test("0123456789abcdef0023", '1', 0x01, 0x01),
        test("0123456789abcdef0023", '2', 0x02, 0x12),
        test("0123456789abcdef0023", '3', 0x03, 0x13),
        test("0123456789abcdef0023", '3', 0x03, 0x13),
        test("0123456789abcdef0023", '4', 0x04, 0x04),
        test("0123456789abcdef0023", '5', 0x05, 0x05),
        test("0123456789abcdef0023", '6', 0x06, 0x06),
        test("0123456789abcdef0023", '7', 0x07, 0x07),
        test("0123456789abcdef0023", '8', 0x08, 0x08),
        test("0123456789abcdef0023", '9', 0x09, 0x09),
        test("0123456789abcdef0023", 'a', 0x0a, 0x0a),
        test("0123456789abcdef0023", 'b', 0x0b, 0x0b),
        test("0123456789abcdef0023", 'c', 0x0c, 0x0c),
        test("0123456789abcdef0023", 'd', 0x0d, 0x0d),
        test("0123456789abcdef0023", 'e', 0x0e, 0x0e),
        test("0123456789abcdef0023", 'f', 0x0f, 0x0f),
    };
#undef test
    for (int i=0; i < lengthof(t); ctr++, i++) {
        const char *s = t[i].str;
        unsigned char n = t[i].len;
        char c = t[i].chr;
        int lno = t[i].lno;
        ptrdiff_t lhs = t[i].lhs;
        ptrdiff_t rhs = t[i].rhs;
        const char *g;
        const char *x =  strchr(s, c);

        if (x == NULL) {
            if (lhs >= 0) {
                printf("line %d: strchr ret NULL, not &s[%td]\n", lno, lhs);
                exit(1);
            }
            g = BSTRCHR(s, c);
            if (g) {
                printf("line %d: STRCHR ret &s[%td], not NULL\n", lno, g-s);
                exit(1);
            }
            g = BSTRRCHR(s, c);
            if (g) {
                printf("line %d: STRRCHR ret &s[%td], not NULL\n", lno, g-s);
                exit(1);
            }
            continue;
        }
        //printf("i => %d\n", i);
        //if (i == 0) printf("c => '%c', lhs => %td\n", c,lhs);
        if (lhs < 0) {
            printf("line %d: strchr ret &s[%td], not NULL\n", lno, g-s);
            exit(1);
        }
        if (x != s+lhs) {
            printf("line %d: strchr ret &s[%td], not &s[%td]\n", lno, x-s,lhs);
            exit(1);
        }
        g = BSTRCHR(s, c);
        if (g == NULL) {
            printf("x = &s[%td], c='%c'\n", x-s, c);
            printf("line %d: STRCHR ret NULL, not &s[%td]\n", lno, lhs);
            exit(1);
        }
        if (x != g) {
            printf("line %d: STRCHR ret &s[%td], not &s[%td]\n", lno,g-s,lhs);
            exit(1);
        }
        x = strrchr(s, c);
        if (x == NULL) {
            printf("line %d: strrchr ret NULL, not &s[%td]\n", lno, rhs);
            exit(1);
        }
        if (x != s+rhs) {
            printf("line %d: strrchr ret [%td], not &s[%td]\n",lno,x-s,rhs);
            exit(1);
        }
        g = BSTRRCHR(s, c);
        if (g == NULL) {
            printf("line %d: STRRCHR ret NULL, not [%td]\n", lno, rhs);
            exit(1);
        }

    }
    TESTS_PASSED();
}

#endif // defined(TESTS_PASSED)
