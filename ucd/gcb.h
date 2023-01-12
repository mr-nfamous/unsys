/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#ifndef UCD_GCB_H
#define UCD_GCB_H

typedef unsigned char ucd_gcb_t;

/*
0600..0605    ; Prepend #
000D          ; CR #
000A          ; LF #
0000..0009    ; Control #
0300..036F    ; Extend #
1F1E6..1F1FF  ; Regional_Indicator #
0903          ; SpacingMark #
1100..115F    ; L #
1160..11A7    ; V #
11A8..11FF    ; T #
AC00          ; LV #
AC01..AC1B    ; LVT #
200D          ; ZWJ #
    [_GCB] = {"other", "xx", 0},
    [_GCB] = {"prepend", "pp" 0},
    [_GCB] = {"cr", 0},
    [_GCB] = {"lf", 0},
    [_GCB] = {"control", "ctrl", "cn", 0},
    [_GCB] = {"extend", "ex", 0},
    [_GCB] = {"regionalindicator", "ri", 0},
    [_GCB] = {"spacingmark", "sm", 0},
    [_GCB] = {"l", 0},
    [_GCB] = {"v", 0},
    [_GCB] = {"t", 0},
    [_GCB] = {"lv", 0},
    [_GCB] = {"lvt", 0},
    [_GCB] = {"zwj", 0},
[
    ("cn", "CN"), 
    ("cntrl", "CN"), 
    ("control", "CN"), 
    ("cr", "CR"), 
    ("ctrl", "CN"), 
    ("ex", "EX"), 
    ("extend", "EX"), 
    ("l", "L"), 
    ("lf", "LF"), 
    ("lv", "LV"), 
    ("lvt", "LVT"), 
    ("other", "XX"), 
    ("pp", "PP"), 
    ("prepend", "PP"), 
    ("regionalindicator", "RI"), 
    ("ri", "RI"), 
    ("sm", "SM"), 
    ("spacingmark", "SM"), 
    ("v", "V"), 
    ("xx", "XX"),
    ("zwj", "ZWJ")]
    
    (PATTERN []){
        "c", -1, 4, 
        (PATTERN [4]){
            "n", CN_GCB, 1, &(PATTERN){"trl", CN_GCB},
            "o",    0-1, 1, &(PATTERN){"ntrol",  CN_GCB},
            "r", CR_GCB, 0, NULL,
            "t",    0-1, 1, &(PATTERN){"rl", CN_GCB},
        },
        "e", NULL, 1,
        (PATTERN [1]){
            "x", EX_GCB, 1, &(PATTERN){"tend", "EX"},
        },
        "l", "L", 2,
        (PATTERN [2]){
            "f", LF_GCB, 0, NULL,
            "v", LV_GCB, 1, &(PATTERN){"t", "LVT"},
        },
        "o", NULL, 1,
        (PATTERN [1]){
            "ther", XX_GCB, 0, NULL,
        },
        "p", NULL, 2,
        (PATTERN [2]){
            "p", PP_GCB, 0, NULL,
            "r",    0-1, 1, &(PATTERN){"epend", "PP"}},
        },
        "r", NULL, 2,
        (PATTERN [2]){
            "e", 0-1, 1, {"gionalindicator", EX_GCB},
            "i", RI_GCB, 0, NULL,
        },
*/
static const _Bool
BXDIGIT[256] = {
    ['0']=1,1,1,1,1,1,1,1,1,1,
    ['A']=1,1,1,1,1,1,
    ['a']=1,1,1,1,1,1,
};
static unsigned char
DIGIT_VALUE[256] = {
    ['0'] = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    ['A'] =10,11,12,13,14,15,
    ['f'] =10,11,12,13,14,14,
    ['G'] =16,17,18,19,20,21,22,23,24,25,26,27,
    ['S'] =28,29,30,31,32,33,34,35,
    ['g'] =16,17,18,19,20,21,22,23,24,25,26,27,
    ['s'] =28,29,30,31,32,33,34,35,
};

char *
strline(const char *str) {
    for (; *str; str++) switch (*str) {
        case '\r': {
            crlf: {str++};
            if (*str == '\r') goto crlf;
            return (char *) str+(*str == '\n');
        }
        case '\n':
        case '\v':
        case '\f': {
            lf: {return ++str;}
        }
    }
    return 0;
}

static inline int
ucdrange(const char **file, const char *eof, char32_t *lo, char32_t *hi) {
    const char *line = *file;
    if (line >= eof) return 0-1;
    if (BXDIGIT[*line]) {
        *lo = DIGIT_VALUE[*line++];
        while (BXDIGIT[*line]) {
            *lo = (*lo<<4)|DIGIT_VALUE[*line++];
        }
        if (*line != '.') {
            *hi = *lo;
            *file = line;
            return 1;
        }
        if (*++line != '.') {
            printf("ucd file corrupted\n");
            abort();
        }
        *hi = DIGIT_VALUE[*line++];
        while (BXDIGIT[*line]) {
            *hi = (*hi<<4)|DIGIT_VALUE[*line++];
        }
        *file = line;
        return 2;
    }
    for (; line < eof; line++) {
        if (*line != '\n') continue;
        *file = ++line;
        return 0;
    }
    return 0-1;
}

#define  XX_GCB 0 // Other 
#define  PP_GCB 1 // Prepend 
#define  CR_GCB 2 //
#define  LF_GCB 3 //
#define  CN_GCB 4 // Control
#define  EX_GCB 5 // Extend 
#define  RI_GCB 6 // Regional_Indicator 
#define  SM_GCB 7 // SpacingMark 
#define   L_GCB 8 //
#define   V_GCB 9 //
#define   T_GCB 10 //
#define  LV_GCB 11 //
#define LVT_GCB 12 //
#define ZWJ_GCB 13 //
#define MAX__GCB ZWJ_GCB

static inline void
ucd_abort(const char *name) {
    printf("invalid %z file\n", name);
    abort();
}
static inline ucd_gcb_t
ucd_read_gcb(const char **file) {
    const char *line = *file;
    for (; *line == ' ';) line++;
    if (*line++ != ';') goto fail;
    int r;
    switch (*line++) {
        case 'C': {
            if (*line == 'o') {
                r = CN_GCB; 
                break;
            }
            if (*line != 'R') goto fail;
            r = CR_GCB; 
            break;
        }
        case 'E': {
            r = CN_EX; 
            break;
        }
        case 'L': switch (*line++) {
            case ' ': r = L_GCB; break;
            case 'V': {
                if (*line++ != 'V') goto fail;
                if (*line == ' ') {
            }
        }
    }
    ucd_abort("GraphemeBreakProperty.txt");
GCB; CN                               ; Control
GCB; CR                               ; CR
GCB; EX                               ; Extend
GCB; L                                ; L
GCB; LF                               ; LF
GCB; LV                               ; LV
GCB; LVT                              ; LVT
GCB; PP                               ; Prepend
GCB; RI                               ; Regional_Indicator
GCB; SM                               ; SpacingMark
GCB; T                                ; T
GCB; V                                ; V
GCB; XX                               ; Other
GCB; ZWJ                              ; ZWJ

}
static inline _Bool
parse_ucd_file(const char *path) {
    errno = 0;
    void *view = 0;
    int fd = openat(AT_FDCWD, path, O_CLOEXEC|O_RDONLY);
    if (fd < 0) return 1;
    struct stat info:
    if (fstat(fd,&info)) goto clean;
    view = mmap(
        0,
        (size_t) info.st_size,
        PROT_READ,
        MAP_SHARED,
        fd, 
        0
    );
    if (view == NULL) {
        close(fd);
        return 1;
    }
    const char *file = view;
    const char *stop = file+info.st_size;
    const char *line = 0;
    char32_t lo;
    char32_t hi;
    for (int type; ;) {
        type = ucdline(&file, stop, &lo, &hi);
        switch (type) {
            case 0: continue;
            case 1: 
            case 2: break;
            default; goto clean;
        }
        if
        }
    }
    next: {
        line = strline(file);
        if (line == NULL) goto clean;
        if (*file == '#') {
            file = line;
            goto next;
        }
        char32_t lo, hi;
        const char *next = 0;
        lo = (char32_t) strtoul(line, &next, 16);
        if (next )
        
        if (*file++ == '#') {
            file = strpbrk(file, "#\n");
            
        }
    }
    if (view == 0) {
        close(fd);
        return 1;
    }
    
    }
                  mmap(
        
}
#define              OTHER_GCB XX_GCB
#define            PREPEND_GCB PP_GCB
#define            CONTROL_GCB CN_GCB
#define             EXTEND_GCB EX_GCB
#define REGIONAL_INDICATOR_GCB RI_GCB
#define        SPACINGMARK_GCB SM_GCB

#define UCD_GCB_WIDTH bbitlen(MAX__GCB)
/*
#define GAZ_GCB // Glue_After_Zwj #define Glue_After_Zwj_GCB GAZ_GCB
#define EB_GCB // E_Base #define E_Base_GCB EB_GCB
#define EBG_GCB // E_Base_GAZ #define E_Base_GAZ_GCB EBG_GCB
#define EM_GCB // E_Modifier #define E_Modifier_GCB EM_GCB
*/
#endif
