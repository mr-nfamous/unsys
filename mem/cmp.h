/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳   

Array comparisons
    MEMCMP 
    MEM
*/

static inline int
MEM_F(CMP)(const void *a, const void *b, size_t n) 
{
#if   chr_width ==  8 && defined(bmemcmp)
    return hmemcmp(a, b, n);
#elif chr_width == 16 && defined(hmemcmp)
    return hmemcmp(a, b, n);
#elif chr_width == 32 && defined(umemcmp)
    return umemcmp(a, b, n);
#else
    if (a == b) return 0;
    for (size_t  i=0;; i++) {
        if (n == i) return 0;
        if (UCA(a)[i] != UCA(b)[i]) {
            return (uchr_t) UCA(a)[i]-(uchr_t) UCA(b)[i];
        }
    }
#endif
}

static inline int
MEM_F(RCMP)(const void *a, const void *b, size_t n) 
{
    if (a == b) return 0;
    for (;;) {
        if (!n) return 0;
        n--;
        if (UCA(a)[n] != UCA(b)[n]) return UCA(a)[n]-UCA(b)[n];
    }
}

static inline int
STR_F(CMP)(const chr_t *a, const chr_t *b) 
{
    if (a == b) return 0;
    for (;; a++, b++) {
        if (*a != *b) return *(uchr_t *) a-*(uchr_t *) b;
        if (*a == 00) return 0;
    }
}

static inline int
STR_F(NCMP)(const chr_t a[], const chr_t b[], size_t n) 
{
    if (a == b || n == 0) return 0;
    for (;; a++, b++) {
        if (*a != *b) return *(uchr_t *) a-*(uchr_t *) b;
        if (*a == 00 || !--n) return 0;
    }
}

#if defined(TESTS_PASSED) && defined(MEMCMP_TEST)

static void
MEM_F(CMP_TEST)(void) {
    const char *lhs, *rhs;
    size_t      len;
    int         lno;
    size_t      ctr = 0;
    struct {
        char al[256], ar[256];
        char bl[256], br[256];
    } repr;
    struct {
        const char *lhs, *rhs;
        size_t  len;
        int     lno;
    } t[] = {
#define test(l,r) {l,r,strlen(l),__LINE__}
        test("",""),
        test("a", "a"),
        test("a", "b"),
        test("b", "a"),
        test("a0", "a0"),
        test("a0", "b0"),
   //     test("b0", "a0"), // ?
        test("a01", "a01"),
        test("a01", "b01"),
        test("b02", "a02"),
        test("a012", "a012"),
        test("a012", "b012"),
    //    test("b012", "a012"),
        test("a0123", "a0123"),
        test("a0123", "b0123"),
        test("b0123", "a0123"),
        test("a01234", "a01234"),
     //   test("a01234", "b01234"),
        test("b01234", "a01234"),
        test("a012345", "a012345"),
        test("a012345", "b012345"),
        test("b012345", "a012345"),
        test("a0123456", "a0123456"),
        test("a0123456", "b0123456"),
        test("b0123456", "a0123456"),
        test("a01234567", "a01234567"),
        test("a01234567", "b01234567"),
        test("b01234567", "a01234567"),
        test("a012345678", "a012345678"),
        test("a012345678", "b012345678"),
        test("b012345678", "a012345678"),
        test("a0123456_", "a0123456."),
        test("a0123456_", "b0123456."),
        test("b0123456_", "a0123456."),
        test("a01234567_", "a01234567."),
        test("a01234567_", "b01234567_"),
        test("b01234567#", "a01234567%"),
        test("a012345678<", "a012345678>"),
        test("a012345678[", "b012345678]"),
        test("b012345678{", "a012345678}"),
        test("a0123456789abcdefghijklmnopq","a0123456789abcdefghijklmnop."),
        test("a0123456789abcdefghijklmnopq","a0123456789abcdefghijklmnop."),
        test("a0123456789abcdefghijklmnopq","a0123456789abcdefghijklmno.."),
        test("a0123456789abcdefghijklmnopq","a0123456789abcdefghijklmn..."),
        test("a0123456789abcdefghijklmnopq","a0123456789abcdefghijklm...."),
        test("a0123456789abcdefghijklmnopq","a0123456789abcdefghijkl....."),
        test("a0123456789abcdefghijklmnopq","a0123456789abcdefghijk......"),
        test("a0123456789abcdefghijklmnopq","a0123456789abcdefghij......."),
        test("a0123456789abcdefghijklmnopq","a0123456789abcdefghi........"),
        test("a0123456789abcdefghijklmnopq","a0123456789abcdefgh........."),
        test("a0123456789abcdefghijklmnopq","a0123456789abcdefg.........."),
        test("a0123456789abcdefghijklmnopq","a0123456789abcdef..........."),
        test("a0123456789abcdefghijklmnopq","a0123456789abcde............"),
        test("a0123456789abcdefghijklmnopq","a0123456789abcd............."),
        test("a0123456789abcdefghijklmnopq","a0123456789abc.............."),
        test("a0123456789abcdefghijklmnopq","a0123456789ab..............."),
        test("a0123456789abcdefghijklmnopq","a0123456789a................"),
        test("a0123456789abcdefghijklmnopq","a0123456789................."),
        test("a0123456789abcdefghijklmnopq","a012345678.................."),
        test("a0123456789abcdefghijklmnopq","a01234567..................."),
        test("a0123456789abcdefghijklmnopq","a0123456...................."),
        test("a0123456789abcdefghijklmnopq","a012345....................."),
        test("a0123456789abcdefghijklmnopq","a01234......................"),
        test("a0123456789abcdefghijklmnopq","a0123......................."),
        test("a0123456789abcdefghijklmnopq","a012........................"),
        test("a0123456789abcdefghijklmnopq","a01........................."),
        test("a0123456789abcdefghijklmnopq","a0.........................."),
        test("a0123456789abcdefghijklmnopq","a..........................."),
        test("a0123456789abcdefghijklmnopq","............................"),

        test("a0123456789abcdefghijklmnopq","a01........................."),
        test("a0123456789abcdefghijklmnopq","a0.........................."),
        test("a0123456789abcdefghijklmnopq","a..........................."),
        test("a0123456789abcdefghijklmnopq","..........................p."),
        test("a0123456789abcdefghijklmnopq",".........................op."),
        test("a0123456789abcdefghijklmnopq","........................nop."),
        test("a0123456789abcdefghijklmnopq",".......................mnop."),
        test("a0123456789abcdefghijklmnopq","......................lmnop."),
        test("a0123456789abcdefghijklmnopq",".....................klmnop."),
        test("a0123456789abcdefghijklmnopq","....................jklmnop."),
        test("a0123456789abcdefghijklmnopq","...................ijklmnop."),
        test("a0123456789abcdefghijklmnopq","..................hijklmnop."),
        test("a0123456789abcdefghijklmnopq",".................ghijklmnop."),
        test("a0123456789abcdefghijklmnopq","................fghijklmnop."),
        test("a0123456789abcdefghijklmnopq","...............efghijklmnop."),
        test("a0123456789abcdefghijklmnopq","..............defghijklmnop."),
        test("a0123456789abcdefghijklmnopq",".............cdefghijklmnop."),
        test("a0123456789abcdefghijklmnopq","............bcdefghijklmnop."),
        test("a0123456789abcdefghijklmnopq","...........abcdefghijklmnop."),
        test("a0123456789abcdefghijklmnopq","..........9abcdefghijklmnop."),
        test("a0123456789abcdefghijklmnopq",".........89abcdefghijklmnop."),
        test("a0123456789abcdefghijklmnopq","........789abcdefghijklmnop."),
        test("a0123456789abcdefghijklmnopq",".......6789abcdefghijklmnop."),
        test("a0123456789abcdefghijklmnopq","......56789abcdefghijklmnop."),
        test("a0123456789abcdefghijklmnopq",".....456789abcdefghijklmnop."),
        test("a0123456789abcdefghijklmnopq","....3456789abcdefghijklmnop."),
        test("a0123456789abcdefghijklmnopq","...23456789abcdefghijklmnop."),
        test("a0123456789abcdefghijklmnopq","..123456789abcdefghijklmnop."),
        test("a0123456789abcdefghijklmnopq",".0123456789abcdefghijklmnop."),
#undef  test
    };
    for (int i=0; i < lengthof(t); i++) {
        lhs = t[i].lhs;
        rhs = t[i].rhs;
        len = t[i].len;
        lno = t[i].lno;
        if (strlen(rhs) != len) {
            (void) printf(
                "line %d: strlen(rhs) != %zu\n",
                lno,len
            );
            exit(1);
        }
        int b =  memcmp(lhs, rhs, len);
        int g = BMEMCMP(lhs, rhs, len);
        if (g < 0 && b >= 0 || g > 0 && b <= 0) {
            (void) printf(
                "line %d: memcmp(...) => %d != BMEMCMP(...) => %d\n",
                lno, b, g
            );
            exit(1);
        }
        b =  strcmp(lhs, rhs);
        g = BSTRCMP(lhs, rhs);
        if (g < 0 && b >= 0 || g > 0 && b <= 0) {
            (void) printf(
                "line %d:\n"
                "    strcmp(%s, %s) => %d\n"
                " != BSTRCMP(%s,%s) => %d\n",
                lno,
                BSTRREPR(repr.al, lhs,256), BSTRREPR(repr.ar, rhs,256), b,
                BSTRREPR(repr.bl, lhs,256), BSTRREPR(repr.br, rhs,256), g
            );
            exit(1);
        }
        for (size_t n=0; n < len; n++) {
            b =  strncmp(lhs, rhs, n);
            g = BSTRNCMP(lhs, rhs, n);
            if ((b==g) || (b<0 && g<0) || (b>0 &&g>0)) continue;
            (void) printf(
                "line %d:\n"
                "    strncmp(%s, %s, %zu) => %d\n"
                " != BSTRNCMP(%s, %s, %zu) => %d\n",
                lno,
                BSTRREPR(repr.al, lhs,256), BSTRREPR(repr.ar, rhs,256), n, b,
                BSTRREPR(repr.bl, lhs,256), BSTRREPR(repr.br, rhs,256), n, g
            );
            exit(1);
        }
    }
    TESTS_PASSED();
}

#endif // defined(TESTS_PASSED)
