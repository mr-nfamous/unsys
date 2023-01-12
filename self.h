
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

/* 
BMEMBCHR
HMEMBCHR
UMEMBCHR
    Binary search of sorted array.
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
MEM_F(ICHR)(void *mem, size_t nel, ptrdiff_t pos, char32_t chr) {
    if (!nel) return NULL;
    if (pos < 0) {
        if ((pos+=nel) < 0) pos = 0;
        nel--;
    }
    else {
        if (pos > --nel) return NULL;
    }
    mem = &UCA(mem)[pos];
    if (pos != nel) (void) memmove(mem+1, mem, nel-pos);
    *UCA(mem) = (chr_t) chr;
    return mem;
}
