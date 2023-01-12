
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

Compute the maximal suffix length

*/

static inline size_t
MEM_F(SUL)(const void *mem, size_t len, const void *set, size_t nel) {
    if (len == 0) return 0;
    if (nel == 0) return len;
    size_t b = len-1;
    if (nel == 1) {
        for (;; b--) {
            if (UCA(mem)[b] != *UCA(set)) return len-(b+1);
            if (!b) return len;
        }
    }
    for (;; b--) {
        for (size_t e=0;;) {
            if (UCA(mem)[b] == UCA(set)[e]) break;
            if (nel == ++e) return len-(b+1);
        }
        if (!b) return len;
    }
}

static inline size_t
MEM_F(CSUL)(const void *mem, size_t len, const void *set, size_t nel) {
    if (len == 0) return 0;
    if (nel == 0) return len;
    for (size_t b=len-1, e;; b--) {
        for (e=0;;) {
            if (UCA(mem)[b] == UCA(set)[e]) return len-(b+1);
            if (nel == ++e) break;
        }
        if (!b) return len;
    }
}

#if defined(MEMSUL_TEST)
#endif // defined(TESTS_PASSED)
