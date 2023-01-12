/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳   
Apply a stable sort to an array.

MEMSORT(mem, nel, rev)
    If {rev==true}, the contents of {mem} will be reversed.
    
STRSORT(str, nel, rev)
    Same as MEMSORT but only at most the first {nel} elements
    of {str} are sorted.

STPSORT(str, nel, rev)
    Same as {STRSORT} except the result is a pointer to the
    element after the last element in the sorted subsequence.
*/


static int CHR_F(FWDCMP)(const void *, const void *);
static int CHR_F(REVCMP)(const void *, const void *);

static inline void *
MEM_F(SORT)(void *mem, size_t nel, _Bool rev) {
    qsort(mem, nel, chr_size, rev ? CHR_F(REVCMP) : CHR_F(FWDCMP));
    return mem;
}

static inline chr_t *
STP_F(SORT)(chr_t str[], size_t nel, _Bool rev) {
    nel  =  nel > PTRDIFF_MAX ? STR_F(LEN)(str) : STR_F(NLEN)(str, nel);
    return  nel+MEM_F(SORT)(str, nel, rev);
}

static inline chr_t *
STR_F(SORT)(chr_t str[], size_t nel, _Bool rev) {
    (void) STP_F(SORT)(str, nel, rev);
    return str;
}

#if defined(TESTS_PASSED) && defined(MEMSORT_TEST)

#endif
