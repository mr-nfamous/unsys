/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳    

Array duplication
    MEMDUP 
    MEMRDUP
    STRDUP
    STRNDUP
*/

static inline void *
MEM_F(DUP)(const void *mem, size_t nel) {
    if (!nel) {
        errno = ENOMEM;
        return NULL;
    }
#if   chr_width ==  8 && defined(bmemcpy)
    return bmemcpy(BMALLOC(nel), mem, nel);
#elif chr_width == 16 && defined(hmemcpy)
    return hmemcpy(HMALLOC(nel), mem, nel);
#elif chr_width == 32 && defined(umemcpy)
    return umemcpy(UMALLOC(nel), mem, nel);
#else
    nel *= chr_size;
    return memcpy(malloc(nel), mem, nel);
#endif
}

static inline chr_t *
STR_F(DUP)(const chr_t str[]) {
#if   chr_width ==  8 && defined(bstrdup)
    return bstrdup(str);
#elif chr_width == 16 && defined(hstrdup)
    return bstrdup(str);
#elif chr_width == 32 && defined(ustrdup)
    return ustrdup(str);
#else
    return MEM_F(DUP)(str, STR_F(LEN)(str)+1);
#endif
}

static inline chr_t *
STR_F(NDUP)(const chr_t str[], size_t len) {
#if   chr_width ==  8 && defined(bstrndup)
    return bstrndup(str, len);
#elif chr_width == 16 && defined(wstrndup)
    return bstrndup(str, len);
#elif chr_width == 32 && defined(ustrndup)
    return ustrndup(str, len);
#else
    size_t nel = 0;
    for (; nel < len; nel++) {
        if (!str[nel]) {
            return MEM_F(DUP)(str, nel+1);
        }
    }
    chr_t *dup = malloc((1+nel)*chr_size);
    dup[nel] = 0;
    return memcpy(dup, str, len);
#endif
}

#ifdef TESTS_PASSED

#endif // defined(TESTS_PASSED)
