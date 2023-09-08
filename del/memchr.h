/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳  
MEMCHR
MEMRCHR
STRCHR
STRLCHR
STRRCHR
STRLEN
STRNLEN
STRSIZE

Get a pointer to the first (MEMCHR) or final (MEMRCHR)
occurrence of the element {c} in the {n} elememt array {m}.

STRCHR, STRLCHR, and STRRCHR operate on nul terminated code 
unit arrays. STRLCHR limits the search to at most the first
{n} elements and returns a pointer to the last element it 
checks instead of NULL, which is reserved for when {s} or {n}
are 0.

STRLEN etc is here because it's essentially nothing more than
{(size_t)(memchr(s, 0, SIZE_MAX)-s)}.

STRSIZE returns the number of bytes needed to represent {s} 
including its terminator. {STRSIZE(U"xyz", -1)} would thus
return {sizeof (char32_t[]){U"xyz"}} or 16, enough to store
{char32_t[4]}

*/

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
    if (*str) {
        if (!chr) {
            for (; --len; str++) {
                if (!*str) break;
            }
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

static inline size_t
STR_F(LEN)(const chr_t str[]) {
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
STR_F(NLEN)(const chr_t str[], size_t max) {
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
STR_F(SIZE)(const chr_t str[], size_t end) {
    return sizeof*str*(1+STR_F(NLEN)(str, end));
}
