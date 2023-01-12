/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳   

Delete a slice of an array

MEMDEL(mem, len, del, chr)
    Deletes up to {del} elements of the {len} element array
    {mem}. The elements from after the deletion to the end of
    the array are copied to the {mem}, not unlike the way the
    delete key deletes a highlighted region of text in a text 
    editor. If {del} was indeed less than {len}, this leaves 
    the yet another region of {mem} undefined. If {chr} is not
    NUL, this region is automatically filled with the value of 
    {*chr}.
    Returns {mem}.

STRDEL(s, n, c)
    Identical to {MEMDEL(s, strlen(s), n, c)}.

STPDEL(s, n, c)
    Identical to STRDEL except the result is a pointer to the
    first element of the region that is or would be filled in
    with copies of the first element of {c} if not NULL.

*/

static inline void *
MEM_F(DEL)
(void *restrict mem, size_t nel, size_t del, const chr_t *restrict chr) {
    if (!nel || !del) return mem;
    if ( del >=  nel) {
        return chr ? MEM_F(SET)(mem, *chr, nel) : mem;
    }
    size_t mov = nel-del;
    (void) MEM_F(MOV)(mem, mem+del, mov);
    if (chr) {
        (void) MEM_F(SET)(mem+mov, *chr, del);
    }
    return mem;
}


static inline chr_t *
STP_F(DEL)(chr_t *stp, size_t del, chr_t chr) {
    size_t len = STR_F(LEN)(stp);
    if (!del) return (stp+len);
    if (!len) return (stp);
    if (del >= len) {
        (void) MEM_F(SET)(stp, chr, len);
        return chr ? stp+len : stp;
    }
    size_t mov = len-del;
    (void) MEM_F(MOV)(stp, stp+del, mov);
    (void) MEM_F(SET)(stp+mov, chr, del);
    return stp+(chr ? len : mov);
}

static inline chr_t *
STR_F(DEL)(chr_t *str, size_t del, chr_t chr) {
    if (!del) return str;
    size_t len = STR_F(LEN)(str);
    if (!str) return str;
    if (del >= len) return MEM_F(SET)(str, chr, len);
    size_t mov = len-del;
    (void) MEM_F(MOV)(str, str+del, mov);
    (void) MEM_F(SET)(str+mov, chr, del);
    return str;
}

#if defined(TESTS_PASSED) && defined(MEMDEL_TEST)

static void
MEM_F(DEL_TEST)(void) {
    size_t ctr = 0;
#if chr_width == 8
    struct {
        ptrdiff_t       off;
        chr_t           str[32];
        size_t          nel;
        size_t          del;
        const chr_t*    chr;
        chr_t           res[32];
        int             lno;
    }
    tests[] = {

#define test(s,n,c,r) {0,s, strlen(s), n,c, r, __LINE__}
        test("/a/b",    0, "", "/a/b"),
        test("/a/b",    1, "", "a/b"),
        test("//a/b",   2, "", "a/b"),
        test("///a/b",  3, "", "a/b"),
        test("/a/b",    1, "", "a/b"),

        test("/a/b",    0, " ", "/a/b"),
        test("/a/b",    1, " ", "a/b "),
        test("//a/b",   2, " ", "a/b  "),
        test("///a/b",  3, " ", "a/b   "),
#undef  test
#define test(s,n,c,r) {1, s, strlen(s)-1, n,c, r, __LINE__}
        test("/a/b",  0, "", "/a/b"),
        test("//a/b",  1, "", "/a/b"),
        test("///a/b",  2, "", "/a/b"),
        test("////a/b",  3, "", "/a/b"),
        
#undef  test

    },
    t;
    for (; ctr < lengthof(tests); ctr++) {
        t = tests[ctr];
        chr_t dst[sizeof t.res] = {0};
        (void) memcpy(dst, t.str, sizeof t.res);
        chr_t *arg = dst+t.off;
        chr_t *ret = MEM_F(DEL)(arg, t.nel, t.del, t.chr);
        if (ret != arg) {
            (void) printf(
                "line %d: memdel ret %p, not %p\n",
                t.lno, ret, arg
            );
            exit(1);
        }
        if (memcmp(dst, t.res, sizeof t.res)) {
            chr_t dst_repr[256];
            chr_t res_repr[256];
            (void) printf(
                "line %d: memdel resulted in %s, not %s\n",
                t.lno, 
                STR_F(REPR)(dst_repr,   dst, sizeof dst_repr),
                STR_F(REPR)(res_repr, t.res, sizeof res_repr)
            );
            exit(1);
        }
    }
#endif
    TESTS_PASSED();
}

#endif // defined(TESTS_PASSED)
