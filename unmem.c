/*
    C X|G|B|M|W|U
     |S|N|S|A|I|N
     |I|U|D|C|N|S
    +|+|+|+|+|+|+   size_t strspn(string, chrset) 
     | | | | | |+   size_t strnspn(string, chrset, size_t)
    +|+|+|+|+|+|+   size_t strcspn(string, chrset)
     | | | | | |+   size_t strcnspn(string, chrset, size_t)
        strspn scans string one byte at a time until:
            the byte is NOT in chrset 
            the byte is the string's terminating nul 
        and then returns the number of bytes scanned.
        strcspn is identical except that it stops on the 
        first byte which IS in the chrset.
        eg: 
            strspn("aaabbbccc", "ac") returns 3 while 
            strcspn("aaabbbcc", "cd") returns 6 
        strnspn and strcnspn take a third argument which is
        used as in strnlen: if len characters are scanned 
        without locating the terminating nul or matching a 
        character from the given set, the function stops 
        scanning and returns len
    
    capitalize      strupr
    center          strcntr(char *, int)
    count           strcnt(char *, int)
    decode 
    endswith        
    expandtabs 
    find            strstr
    fromhex         strunhex
    hex 
    index 
    isalnum 
    isalpha 
    isascii 
    isdigit 
    islower 
    isspace 
    istitle
    isupper 
    join 
    ljust 
    lower 
    lstrip 
    maketrans 
    partition 
    replace 
    removeprefix 
    removesuffix 
    rfind 
    rindex 
    rjust 
    rpartition 
    rsplit 
    rstrip 
    split 
    splitlines 
    startswith 
    strip 
    swapcase 
    title
    translate upper zfill getbuffer nbytes itemsize

*/
#define ASCII_ISLWR_C(c) (('a' <= ((int)(c)) && (((int)(c)) <= 'z'))
#define ASCII_ISUPR_C(c) (('A' <= ((int)(c)) && (((int)(c)) <= 'Z'))

typedef const void *memory;
typedef const char *string;
typedef const char *format;


void *
unmem_memrchr(const void *mem, int chr, size_t len) {
    memory ptr = NULL;
    const unsigned char *p = mem;
    for (size_t i=0; i < len; ++i) {
        if (p[i] == chr) {
            ptr = (void *)(p+i);
        }
    }
    return ptr;
}

void *
unmem_memrev(void *mem, size_t len) {
    unsigned char *p;
    unsigned char chr;
    if (!len) {
        return mem;
    }
next:
    chr = ((unsigned char *)(mem))[--len];
    *p++= chr;
    if (len == 0) {
        return (void *)(p);
    }
    goto next;
}

struct lib_string {
    int 
        (*dprintf)      (int,    format, ...),
        (*fprintf)      (FILE *, format, ...),
        (*printf)       (format, ...),
        (*snprintf)     (char *, size_t, format, ...),
        (*vdprintf)     (int, format, va_list),
        (*vfprintf)     (FILE *, format, va_list),
        (*vprintf)      (FILE *, format, va_list),
        (*vsnprintf)    (char *, size_t, format, va_list),
        (*strcasecmp)   (string, string),
        (*strncasecmp)  (string, string, size_t),
        (*strcmp)       (string, string),
        (*strncmp)      (string, string, size_t),
        (*strcoll)      (string, string),
        (*memcmp)       (memory, memory, size_t);
        
    void *
        (*memchr)       (memory,            int, size_t),
        (*memrchr)      (memory,            int, size_t),
        (*memset)       (void *,            int, size_t),
        (*memmul)       (void *, memory, size_t, size_t),
        (*memcpy)       (void *, memory,         size_t),
        (*memccpy)      (void *, memory,    int, size_t),
        (*memmove)      (void *, memory,         size_t),
        (*memmem)       (memory, size_t, memory, size_t),
        (*memrmem)      (memory, size_t, memory, size_t),
        (*meminc)       (void *, size_t          size_t),
        (*memdec)       (void *, size_t,         size_t), 
        (*memmap)       (void *, memory, memory, size_t, size_t),
        (*memrev)       (void *, size_t);

    char *
        (*strcat)       (char *, string),
        (*strncat)      (char *, string, size_t),
        (*strcpy)       (char *, string),
        (*strncpy)      (char *, string, size_t),
        (*strpbrk)      (string, string),
        (*strchr)       (string,    int), 
        (*strnchr)      (string,    int),
        (*strrchr)      (string,    int),
        (*strstr)       (string, string),
        (*strnstr)      (string, string, size_t),
        (*strrstr)      (string, string),
        (*stpcpy)       (char *, string),
        (*stpncpy)      (char *, string, size_t),
        (*strdup)       (string),
        (*strndup)      (string, size_t),
        (*strinc)       (char *),
        (*strdec)       (char *),
        (*strupr)       (char *),
        (*strnupr)      (char *, size_t),
        (*strlwr)       (char *),
        (*strnlwr)      (char *, size_t),
        (*strrev)       (char *),
        (*strnrev)      (char *, size_t),
        
        ;
    size_t
        (*strlen)   (string),
        (*strnlen)  (string, size_t),
        (*strspn)   (string, string),
        (*strnspn)  (string, string, size_t),
        (*strcspn)  (string, string),
        (*strcnspn) (string, string, size_t),
        

void *
mktrns(void *tab, void *map, size_t maplen) {
    int i = 0;
    int c;
    if (maplen > 255U) {
        errno = EDOM;
        return NULL;
    }
    int end = (int)(maplen);
    for (; i < end; ++i) {
        c = ((unsigned char *)(tab))[i];
        ((unsigned char *)(tab))[i] = ((unsigned char *)(map))[c];
    }
    for (unsigned char r=(unsigned char)(i); r <= 0xFFU; ++r) {
        ((unsigned char *)(tab))[r] = r;
    }
    return tab;
}

size_t
memmap(void *mem, void *map, void *del, size_t memlen, size_t dellen) {
    size_t i;
    size_t p;
    const unsigned char *      dst = mem;
    const unsigned char *const src = map;
    int tab[restrict 256] = {0};
    int c;
    int r;
    for (i=0; i < 256; ++i) {
        tab[i] = src[i];
    }
    if (dellen > 1) {
        const unsigned char *const jmp = del;
        for (i=0; i < skiplen; ++i) {
            tab[jmp[i]] = 256;
        }
        p = 0;
        for (i=0; i < memlen; ++i) {
            c = dst[i];
            r = tab[c];
            if (r <= 0xFF) {
                dst[p++] = r;
            }
        }
    }
    else if (dellen == 1) {
        r = *((unsigned char *)(del));
        p = 0;
        for (i=0; i < memlen; ++i) {
            c = dst[i];
            if (c != r) {
                dst[p++] = tab[c];
            }
        }
    }
    else {
        for (i=0; i < memlen; ++i) {
            c = dst[i];
            r = tab[c];
            dst[i] = r;
        }
        p = i;
    }
    return p;
}

void *
meminc(void *mem, size_t nitem, size_t isize) {
    return (void *)(((char *)(mem))+(nitem*isize));
}
void *
memdec(void *mem, size_t nitem, size_t isize) {
    return (void *)(((char *)(mem))-(nitem*isize));
}

void *
memmul(void *dst, const void *const src, size_t n, size_t isize) {
    const unsigned char *restrict const obj = src;
    unsigned char *restrict buf = dst;
    for (size_t i=0; i < n; ++i) {
        memcpy(dst, obj, isize);
        buf += isize;
    }
    return (void *)(buf);
}

char *
strmul(char *buf, const char *str, size_t n) {
    size_t w;
    size_t i;
    if (!n) {
        return buf;
    }
    for (w=0; str[w]; ++w) {
        *buf++ = str[w];
    }
    if (!w--) {
        return buf;
    }
    if (!w) {
        memset(buf, *str, n);
        buf += n;
    }
    else {
        for (i=0; i < n; ++i) {
            memcpy(buf, str, w);
            buf += w;
        }
    }
    buf[0] = 0;
    return buf;
}

size_t
strupr(char *str) {
    size_t n = 0;
    for (int c=str[n]; c; c=str[++n]) {
        if (ASCII_ISLWR_C(c)) {
            str[n] -= 32;
        }
    }
    return n;
}

size_t
strnupr(char *str, size_t n) {
    size_t i = 0;
    if (n <= i) {
        return 0;
    }
    for (int c=str[i]; c > 0; c=str[++i]) {
        if (i >= n) {
            return i;
        }
        if (ASCII_ISLWR_C(c)) {
            str[i] -= 32;
        }
    }
}

size_t
strlwr(char *str) {
    size_t n = 0;
    int c = *str;
    for (; c; ++n) {
        if (ASCII_ISUPR_C(c)) {
            str[n] -= 32;
        }
    }
    return n;
}

size_t
strnlwr(char *str, size_t n) {
    size_t p = 0;
    int c;
next:
    if (p <= n) {
        return p;
    }
    c = str[p];
    if (c == 0) {
        return p;
    }
    if ('A' <= c && c <= 'Z') {
        str[p++] -= 32;
    }
    goto next;
}

static const unsigned char BASE64URL_ENCODE[] = {
    [000]='A','B','C','D','E','F','G','H',
    [010]='I','J','K','L','M','N','O','P',
    [020]='Q','R','S','T','U','V','W','X',
    [030]='Y','Z','a','b','c','d','e','f', 
    [040]='g','h','i','j','k','l','m','n',
    [050]='o','p','q','r','s','t','u','v',
    [060]='w','x','y','z','0','1','2','3', 
    [070]='4','5','6','7','8','9','-','_', 0
};

struct b64src {
    unsigned char x;
    unsigned char y;
    unsigned char z;
};

typedef struct {
    const void *memory;
    size_t      nbytes;
    unsigned char pad;
} base64url_encode_args;

void *
base64url_encode(base64url_encode_args *const args) {
    size_t xtra = args->nbytes%3;
    size_t need = args->nbytes/3;
    size_t stop = need;
    size_t i;
    if (xtra) {
        need += 1;
    }
    const struct b64src *r = args->memory;
    unsigned char *w = malloc(need*4+1);
    unsigned char *p;
    unsigned  int  v;
    if (w == NULL) {
        errno = ENOMEM;
        return NULL;
    }
    i = 0; 
next:
    if (stop == i) {
        switch (xtra) {
            case 1: {
               v = ((unsigned)(r->x))<<4;
               *p++ = BASE64URL_ENCODE[(v>>6)&077];
               *p++ = BASE64URL_ENCODE[(v)   &077];
               *p++ = args->pad;
               *p++ = args->pad;
               break;
            }
            case 2: {
                v = (((unsigned)(r->x))<<010)|r->y;
                *p++ = BASE64URL_ENCODE[(v>>12)&077];
                *p++ = BASE64URL_ENCODE[(v>> 6)&077];
                *p++ = BASE64URL_ENCODE[(v    )&077];
                *p++ = args->pad;
            }
        }
        *p = 0;
        return (void *)(w);
    }
    p = w+(i++)*4:
    r++;
    (v) = (
            ((unsigned)(r->x))<<020
        |   ((unsigned)(r->y))<<010
        |   ((unsigned)(r->z)));
    *p++ = BASE64URL_ENCODE[(v>>18)    ];
    *p++ = BASE64URL_ENCODE[(v>>12)&077];
    *p++ = BASE64URL_ENCODE[(v>>6 )&077];
    *p++ = BASE64URL_ENCODE[(v)    &077];
    goto next;
}

size_t 
binstr(char *str, size_t w) {
    
}