/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

STDC:
    MEMCPY == memcpy
    MEMMOV == memmove
    STRCPY == strcpy
    STRNCPY == strcpy

POSIX:
    MEMCCPY
    STPCPY
    STPNCPY

UNSYS:
    MEMRCPY
        Reverse copy {src} into {dst}

    MEMREV
        Return an array after reversing its contents.

    STPLCPY/
    STRLCPY(d, s) 
        Copy elements from the nul terminated {s} to the {n} 
        element array {d}. If {strlen(s)} is less than {n}, 
        the result will not be properly terminated. These are
        almost identical to the BSD {strlcpy}, but it returns
        the number of elements copies rather than {d}.
    
    STPSCPY/
    STRSCPY(d, s)
        Copy the full contents of the nul terminated {s} to the
        nul terminated {d}. The operation fails by returning NULL
        and setting {errno=ENOMEM} if {s} or {d} was NULL, or if
        there's not enough room in {d} to fit all of {s}. A nul 
        is never added, so the operation won't "clobber" the rest
        of {d} if {s} is shorter the way strlcpy/strncpy do. 

*/
static inline void *
MEM_F(CPY)(void *restrict dst, const void *restrict src, size_t len) {
#if   chr_width ==  8 && defined(bmemcpy)
    return bmemcpy(dst, src, len);
#elif chr_width == 16 && defined(hmemcpy)
    return hmemcpy(dst, src, len);
#elif chr_width == 16 && defined(bmemcpy)
    return bmemcpy(dst, src, len<<1);
#elif chr_width == 32 && defined(umemcpy)
    return umemcpy(dst, src, len);
#elif chr_width == 32 && defined(bmemcpy)
    return bmemcpy(dst, src, len<<2);
#else
    for (size_t i=0; i < len; i++) {
        UCA(dst)[i] = UCA(src)[i];
    }
    return dst;
#endif
}

static inline void *
MEM_F(RCPY)(void *restrict dst, const void *restrict src, size_t nel) {
    if (nel <= 1) {if (nel) *UCA(dst) = *UCA(src);}
    else for (size_t p=0, q=nel-1; p < nel; p++, q--) {
        UCA(dst)[p] = UCA(src)[q];
    }
    return dst;
}

static inline void *
MEM_F(CCPY)(void *restrict d, const void *restrict s, chr_t c, size_t n) {
#if   chr_width ==  8 && defined(bmemccpy)
    return bmemccpy(d, s, c, n);
#else
    for (size_t  i=0;; i++) {
        if (n == i) return NULL;
        if (c == ( UCA(d)[i]=UCA(s)[i])) {
            return UCA(d)+i+1;
        }
    }
#endif
}

static inline void *
MEM_F(REV)(void *mem, size_t nel) {
    chr_t *l = mem;
    chr_t *r;
    chr_t  v;
    if (nel > 7) {
        r = l+(nel-1);
        do {
            v=*l, *l++=*r, *r--=v;
            v=*l, *l++=*r, *r--=v;
            v=*l, *l++=*r, *r--=v;
            v=*l, *l++=*r, *r--=v;
        }
        while ((nel-=8) >= 8);
    }
    r = l;
    switch (nel) {
        case 7: {
            v=l[0], l[0]=r[6], r[6]=v;
            v=l[1], l[1]=r[5], r[5]=v;
            v=l[2], l[2]=r[4], r[4]=v;
            return mem;
        }
        case 6: {
            v=l[0], l[0]=r[5], r[5]=v;
            v=l[1], l[1]=r[4], r[4]=v;
            v=l[2], l[2]=r[3], r[3]=v;
            return mem;
        }
        case 5: {
            v=l[0],l[0]=r[4],r[4]=v;
            v=l[1],l[1]=r[3],r[3]=v;
            return mem;
        }
        case 4: {
            v=l[0],l[0]=r[3],r[3]=v;
            v=l[1],l[1]=r[2],r[2]=v;
            return mem;
        }
        case 3: {v=l[0],l[0]=r[2],r[2]=v; return mem;}
        case 2: {v=l[0],l[0]=r[1],r[1]=v; return mem;}
    }
    return mem;
}

static inline void *
MEM_F(MOV)(void *dst, const void *src, size_t len) {
#if   chr_width ==  8 && defined(bmemmov)
    return bmemmov(dst, src, len);
#elif chr_width == 16 && defined(hmemmov)
    return hmemmov(dst, src, len);
#elif chr_width == 16 && defined(bmemmov)
    return bmemmov(dst, src, len<<1);
#elif chr_width == 32 && defined(umemmov)
    return umemmov(dst, src, len);
#elif chr_width == 32 && defined(bmemmov)
    return bmemmov(dst, src, len<<2);
#else
    if (dst <= src) return MEM_F(CPY)(dst, src, len);
    if (!len) return dst;
    for (;;) {
        const chr_t v = UCA(src)[--len];
        UCA(dst)[len] = v;
        if (!len) return dst;
    }
#endif
}

static inline void *
MEM_F(RMOV)(void *dst, const void *src, size_t nel) {
    if (src == dst) return MEM_F(REV)(dst, nel);
    if (nel == 0) return dst;
    const chr_t *s = src;
    size_t r = nel>>1;
    size_t p = 0;
    size_t q = nel-1;
    chr_t *d = dst;
    chr_t t;
    for (; p < r; p++, q--) t=s[p], d[p]=s[q], d[q]=t;
    if (nel%2) d[r] = s[r];
    return dst;
}

static inline chr_t *
STP_F(CPY)(chr_t dst[restrict], const chr_t src[restrict]) {
#if   chr_width ==  8 && defined(bstpcpy)
    return bstpcpy(dst, src);
#elif chr_width == 16 && defined(wstpcpy)
    return wstpcpy(dst, src);
#elif chr_width == 32 && defined(ustpcpy)
    return ustpcpy(dst, src);
#else
#   if chr_width == 8 && defined(bmemccpy)
    return bmemccpy(dst, src, 0, SIZE_MAX>>1)-1;
#   else
    for (;; dst++, src++) {if (!(*dst=*src)) {return dst;}}
#   endif
#endif
}

static inline chr_t *
STR_F(CPY)(chr_t dst[restrict], const chr_t src[restrict]) {
#if   chr_width ==  8 && defined(bstrcpy)
    return    bstrcpy(dst, src);
#elif chr_width == 16 && defined(hstrcpy)
    return    hstrcpy(dst, src);
#elif chr_width == 32 && defined(ustrcpy)
    return    ustrcpy(dst, src);
#else
#   if chr_width == 8 && defined(bmemccpy)
    (void) bmemccpy(dst, src, 0, SIZE_MAX>>1);
    return dst;
#   else
    for (size_t i=0;; i++) {
        if (!(dst[i]=src[i])) return dst;
    }
#   endif
#endif
}

static inline chr_t *
STP_F(NCPY)(chr_t dst[restrict], const chr_t src[restrict], size_t len) {
#if   chr_width ==  8 && defined(bstpncpy)
    return bstpncpy(dst, src, len);
#elif chr_width == 16 && defined(hstpncpy)
    return hstpncpy(dst, src, len);
#elif chr_width == 32 && defined(ustpncpy)
    return ustpncpy(dst, src, len);
#else
    chr_t *const stp= dst+len;
    for (; dst < stp; dst++, src++) {
        if (!(*dst=*src)) {
            for (;++dst < stp;) *dst = 0;
            return stp;
        }
    }
    return stp;
#endif
}

static inline chr_t *
STR_F(NCPY)(chr_t dst[restrict], const chr_t src[restrict], size_t len) {
#if   chr_width ==  8 && defined(bstrncpy)
    return    bstrncpy(dst, src, len);
#elif chr_width == 16 && defined(hstrncpy)
    return    hstrncpy(dst, src, len);
#elif chr_width == 32 && defined(ustrncpy)
    return    ustrncpy(dst, src), len;
#else
    for (size_t i=0; i < len; i++) {
        if (!(dst[i]=src[i])) {
            while (--i < len) dst[i] = 0; break;
        }
    }
    return dst;
#endif
}

static inline chr_t *
STP_F(LCPY)(chr_t dst[restrict], const chr_t *restrict src, size_t nel) {
#if   chr_width ==  8 && defined(bstrlcpy)
    return  bstrlcpy(dst, src, nel)+dst;
#elif chr_width == 16 && defined(hstrlcpy)
    return  hstrlcpy(dst, src, nel)+dst;
#elif chr_width == 32 && defined(ustrlcpy)
    return  ustrlcpy(dst, src, nel)+dst;
#else
    nel = STR_F(NLEN)(dst, nel);
    return MEM_F(CPY)(dst, src, nel)+nel;
#endif
}

static inline chr_t *
STR_F(LCPY)(chr_t dst[restrict], const chr_t *restrict src, size_t nel) {
#if   chr_width ==  8 && defined(bstrlcpy)
    return  bstrlcpy(dst, src, nel);
#elif chr_width == 16 && defined(hstrlcpy)
    return  hstrlcpy(dst, src, nel);
#elif chr_width == 32 && defined(ustrlcpy)
    return  ustrlcpy(dst, src, nel);
#else
    return MEM_F(CPY)(dst, src, STR_F(NLEN)(dst, nel));
#endif
}

static inline chr_t *
STP_F(SCPY)(chr_t *restrict dst, const chr_t *restrict src) {
    if (!dst || !src) {
        errno = ENOMEM;
        return NULL;
    }
    if (!dst[0]) {
        return src[0] ? ((errno=ENOSPC), NULL) : dst;
    }
    if (!src[0]) return dst;
    for (size_t i=1;; i++) {
        if (!src[i]) return i+MEMCPY(dst, src, i);
    }
}

static inline chr_t *
STR_F(SCPY)(chr_t *restrict dst, const chr_t *restrict src) {
    (void) STP_F(SCPY)(dst, src);
    return dst;
}

static inline chr_t *
STP_F(REV)(chr_t str[]) {
    size_t len = STR_F(LEN)(str);
    return MEM_F(REV)(str, len)+len;
}

static inline chr_t *
STR_F(REV)(chr_t str[]) {
#if   chr_width ==  8 && defined(bstrrev)
    return bstrrev(str);
#elif chr_width == 16 && defined(hstrrev)
    return hstrrev(str);
#elif chr_width == 32 && defined(ustrrev)
    return ustrrev(str);
#else
    return MEM_F(REV)(str, STR_F(LEN)(str));
#endif
}

