#pragma once

int include_wchar_h(Lib *self, FILE *file) {

    __basedef(wchar_h, "<wchar.h>")

    __dentr(enums, Enum[])
        __predef("")
            EREF(WCHAR_MIN)
            EREF(WCHAR_MAX)
        __preend("", .fmt="x")
    __dexit(enums)

    __dentr(structs, Struct[])
    __dexit(structs)
    __baseret(wchar_h)
}

int test_wchar_h(Lib *self, FILE *file) {
#   ifndef BLTN_FPUTWS
#   define BLTN_FPUTWS fputws
#   endif
#   ifndef BLTN_FWIDE
#   define BLTN_FWIDE fwide
#   endif
#   ifndef BLTN_FWPRINTF
#   define BLTN_FWPRINTF fwprintf
#   endif
#   ifndef BLTN_FWSCANF
#   define BLTN_FWSCANF fwscanf
#   endif
#   ifndef BLTN_ISWALNUM
#   define BLTN_ISWALNUM iswalnum
#   endif
#   ifndef BLTN_ISWALPHA
#   define BLTN_ISWALPHA iswalpha
#   endif
#   ifndef BLTN_ISWCNTRL
#   define BLTN_ISWCNTRL iswcntrl
#   endif
#   ifndef BLTN_ISWCTYPE
#   define BLTN_ISWCTYPE iswctype
#   endif
#   ifndef BLTN_ISWDIGIT
#   define BLTN_ISWDIGIT iswdigit
#   endif
#   ifndef BLTN_ISWGRAPH
#   define BLTN_ISWGRAPH iswgraph
#   endif
#   ifndef BLTN_ISWLOWER
#   define BLTN_ISWLOWER iswlower
#   endif
#   ifndef BLTN_ISWPRINT
#   define BLTN_ISWPRINT iswprint
#   endif
#   ifndef BLTN_ISWPUNCT
#   define BLTN_ISWPUNCT iswpunct
#   endif
#   ifndef BLTN_ISWSPACE
#   define BLTN_ISWSPACE iswspace
#   endif
#   ifndef BLTN_ISWUPPER
#   define BLTN_ISWUPPER iswupper
#   endif
#   ifndef BLTN_ISWXDIGIT
#   define BLTN_ISWXDIGIT iswxdigit
#   endif
#   ifndef BLTN_MBSINIT
#   define BLTN_MBSINIT mbsinit
#   endif
#   ifndef BLTN_SWPRINTF
#   define BLTN_SWPRINTF swprintf
#   endif
#   ifndef BLTN_SWSCANF
#   define BLTN_SWSCANF swscanf
#   endif
#   ifndef BLTN_VFWPRINTF
#   define BLTN_VFWPRINTF vfwprintf
#   endif
#   ifndef BLTN_VFWSCANF
#   define BLTN_VFWSCANF vfwscanf
#   endif
#   ifndef BLTN_VSWPRINTF
#   define BLTN_VSWPRINTF vswprintf
#   endif
#   ifndef BLTN_VSWSCANF
#   define BLTN_VSWSCANF vswscanf
#   endif
#   ifndef BLTN_VWPRINTF
#   define BLTN_VWPRINTF vwprintf
#   endif
#   ifndef BLTN_VWSCANF
#   define BLTN_VWSCANF vwscanf
#   endif
#   ifndef BLTN_WCSCMP
#   define BLTN_WCSCMP wcscmp
#   endif
#   ifndef BLTN_WCSCOLL
#   define BLTN_WCSCOLL wcscoll
#   endif
#   ifndef BLTN_WCSNCMP
#   define BLTN_WCSNCMP wcsncmp
#   endif
#   ifndef BLTN_WCTOB
#   define BLTN_WCTOB wctob
#   endif
#   ifndef BLTN_WMEMCMP
#   define BLTN_WMEMCMP wmemcmp
#   endif
#   ifndef BLTN_WPRINTF
#   define BLTN_WPRINTF wprintf
#   endif
#   ifndef BLTN_WSCANF
#   define BLTN_WSCANF wscanf
#   endif
#   ifndef BLTN_WCSCASECMP
#   define BLTN_WCSCASECMP wcscasecmp
#   endif
#   ifndef BLTN_WCSCASECMP_L
#   define BLTN_WCSCASECMP_L wcscasecmp_l
#   endif
#   ifndef BLTN_WCSCOLL_L
#   define BLTN_WCSCOLL_L wcscoll_l
#   endif
#   ifndef BLTN_WCSNCASECMP
#   define BLTN_WCSNCASECMP wcsncasecmp
#   endif
#   ifndef BLTN_WCSNCASECMP_L
#   define BLTN_WCSNCASECMP_L wcsncasecmp_l
#   endif
#   ifndef BLTN_WCSWIDTH
#   define BLTN_WCSWIDTH wcswidth
#   endif
#   ifndef BLTN_WCWIDTH
#   define BLTN_WCWIDTH wcwidth
#   endif
#   ifndef BLTN_WCTYPE
#   define BLTN_WCTYPE wctype
#   endif
#   ifndef BLTN_OPEN_WMEMSTREAM
#   define BLTN_OPEN_WMEMSTREAM open_wmemstream
#   endif
#   ifndef BLTN_MBRLEN
#   define BLTN_MBRLEN mbrlen
#   endif
#   ifndef BLTN_MBRTOWC
#   define BLTN_MBRTOWC mbrtowc
#   endif
#   ifndef BLTN_MBSRTOWCS
#   define BLTN_MBSRTOWCS mbsrtowcs
#   endif
#   ifndef BLTN_WCRTOMB
#   define BLTN_WCRTOMB wcrtomb
#   endif
#   ifndef BLTN_WCSCSPN
#   define BLTN_WCSCSPN wcscspn
#   endif
#   ifndef BLTN_WCSFTIME
#   define BLTN_WCSFTIME wcsftime
#   endif
#   ifndef BLTN_WCSLEN
#   define BLTN_WCSLEN wcslen
#   endif
#   ifndef BLTN_WCSRTOMBS
#   define BLTN_WCSRTOMBS wcsrtombs
#   endif
#   ifndef BLTN_WCSSPN
#   define BLTN_WCSSPN wcsspn
#   endif
#   ifndef BLTN_WCSXFRM
#   define BLTN_WCSXFRM wcsxfrm
#   endif
#   ifndef BLTN_MBSNRTOWCS
#   define BLTN_MBSNRTOWCS mbsnrtowcs
#   endif
#   ifndef BLTN_WCSNLEN
#   define BLTN_WCSNLEN wcsnlen
#   endif
#   ifndef BLTN_WCSNRTOMBS
#   define BLTN_WCSNRTOMBS wcsnrtombs
#   endif
#   ifndef BLTN_WCSXFRM_L
#   define BLTN_WCSXFRM_L wcsxfrm_l
#   endif
#   ifndef BLTN_WCSTOD
#   define BLTN_WCSTOD wcstod
#   endif
#   ifndef BLTN_WCSTOF
#   define BLTN_WCSTOF wcstof
#   endif
#   ifndef BLTN_WCSTOL
#   define BLTN_WCSTOL wcstol
#   endif
#   ifndef BLTN_WCSTOLD
#   define BLTN_WCSTOLD wcstold
#   endif
#   ifndef BLTN_WCSTOLL
#   define BLTN_WCSTOLL wcstoll
#   endif
#   ifndef BLTN_WCSTOUL
#   define BLTN_WCSTOUL wcstoul
#   endif
#   ifndef BLTN_WCSTOULL
#   define BLTN_WCSTOULL wcstoull
#   endif
#   ifndef BLTN_FGETWS
#   define BLTN_FGETWS fgetws
#   endif
#   ifndef BLTN_WCSCAT
#   define BLTN_WCSCAT wcscat
#   endif
#   ifndef BLTN_WCSCHR
#   define BLTN_WCSCHR wcschr
#   endif
#   ifndef BLTN_WCSCPY
#   define BLTN_WCSCPY wcscpy
#   endif
#   ifndef BLTN_WCSNCAT
#   define BLTN_WCSNCAT wcsncat
#   endif
#   ifndef BLTN_WCSNCPY
#   define BLTN_WCSNCPY wcsncpy
#   endif
#   ifndef BLTN_WCSPBRK
#   define BLTN_WCSPBRK wcspbrk
#   endif
#   ifndef BLTN_WCSRCHR
#   define BLTN_WCSRCHR wcsrchr
#   endif
#   ifndef BLTN_WCSSTR
#   define BLTN_WCSSTR wcsstr
#   endif
#   ifndef BLTN_WCSTOK
#   define BLTN_WCSTOK wcstok
#   endif
#   ifndef BLTN_WMEMCHR
#   define BLTN_WMEMCHR wmemchr
#   endif
#   ifndef BLTN_WMEMCPY
#   define BLTN_WMEMCPY wmemcpy
#   endif
#   ifndef BLTN_WMEMMOVE
#   define BLTN_WMEMMOVE wmemmove
#   endif
#   ifndef BLTN_WMEMSET
#   define BLTN_WMEMSET wmemset
#   endif
#   ifndef BLTN_WCPCPY
#   define BLTN_WCPCPY wcpcpy
#   endif
#   ifndef BLTN_WCPNCPY
#   define BLTN_WCPNCPY wcpncpy
#   endif
#   ifndef BLTN_WCSDUP
#   define BLTN_WCSDUP wcsdup
#   endif
#   ifndef BLTN_BTOWC
#   define BLTN_BTOWC btowc
#   endif
#   ifndef BLTN_FGETWC
#   define BLTN_FGETWC fgetwc
#   endif
#   ifndef BLTN_FPUTWC
#   define BLTN_FPUTWC fputwc
#   endif
#   ifndef BLTN_GETWC
#   define BLTN_GETWC getwc
#   endif
#   ifndef BLTN_GETWCHAR
#   define BLTN_GETWCHAR getwchar
#   endif
#   ifndef BLTN_PUTWC
#   define BLTN_PUTWC putwc
#   endif
#   ifndef BLTN_PUTWCHAR
#   define BLTN_PUTWCHAR putwchar
#   endif
#   ifndef BLTN_UNGETWC
#   define BLTN_UNGETWC ungetwc
#   endif
#   ifndef BLTN_TOWLOWER
#   define BLTN_TOWLOWER towlower
#   endif
#   ifndef BLTN_TOWUPPER
#   define BLTN_TOWUPPER towupper
#   endif
    self->fputws=BLTN_FPUTWS;
    self->fwide=BLTN_FWIDE;
    self->fwprintf=BLTN_FWPRINTF;
    self->fwscanf=BLTN_FWSCANF;
    self->iswalnum=BLTN_ISWALNUM;
    self->iswalpha=BLTN_ISWALPHA;
    self->iswcntrl=BLTN_ISWCNTRL;
    self->iswctype=BLTN_ISWCTYPE;
    self->iswdigit=BLTN_ISWDIGIT;
    self->iswgraph=BLTN_ISWGRAPH;
    self->iswlower=BLTN_ISWLOWER;
    self->iswprint=BLTN_ISWPRINT;
    self->iswpunct=BLTN_ISWPUNCT;
    self->iswspace=BLTN_ISWSPACE;
    self->iswupper=BLTN_ISWUPPER;
    self->iswxdigit=BLTN_ISWXDIGIT;
    self->mbsinit=BLTN_MBSINIT;
    self->swprintf=BLTN_SWPRINTF;
    self->swscanf=BLTN_SWSCANF;
    self->vfwprintf=BLTN_VFWPRINTF;
    self->vfwscanf=BLTN_VFWSCANF;
    self->vswprintf=BLTN_VSWPRINTF;
    self->vswscanf=BLTN_VSWSCANF;
    self->vwprintf=BLTN_VWPRINTF;
    self->vwscanf=BLTN_VWSCANF;
    self->wcscmp=BLTN_WCSCMP;
    self->wcscoll=BLTN_WCSCOLL;
    self->wcsncmp=BLTN_WCSNCMP;
    self->wctob=BLTN_WCTOB;
    self->wmemcmp=BLTN_WMEMCMP;
    self->wprintf=BLTN_WPRINTF;
    self->wscanf=BLTN_WSCANF;
    self->wcscasecmp=BLTN_WCSCASECMP;
    self->wcscasecmp_l=BLTN_WCSCASECMP_L;
    self->wcscoll_l=BLTN_WCSCOLL_L;
    self->wcsncasecmp=BLTN_WCSNCASECMP;
    self->wcsncasecmp_l=BLTN_WCSNCASECMP_L;
    self->wcswidth=BLTN_WCSWIDTH;
    self->wcwidth=BLTN_WCWIDTH;
    self->wctype=BLTN_WCTYPE;
    self->open_wmemstream=BLTN_OPEN_WMEMSTREAM;
    self->mbrlen=BLTN_MBRLEN;
    self->mbrtowc=BLTN_MBRTOWC;
    self->mbsrtowcs=BLTN_MBSRTOWCS;
    self->wcrtomb=BLTN_WCRTOMB;
    self->wcscspn=BLTN_WCSCSPN;
    self->wcsftime=BLTN_WCSFTIME;
    self->wcslen=BLTN_WCSLEN;
    self->wcsrtombs=BLTN_WCSRTOMBS;
    self->wcsspn=BLTN_WCSSPN;
    self->wcsxfrm=BLTN_WCSXFRM;
    self->mbsnrtowcs=BLTN_MBSNRTOWCS;
    self->wcsnlen=BLTN_WCSNLEN;
    self->wcsnrtombs=BLTN_WCSNRTOMBS;
    self->wcsxfrm_l=BLTN_WCSXFRM_L;
    self->wcstod=BLTN_WCSTOD;
    self->wcstof=BLTN_WCSTOF;
    self->wcstol=BLTN_WCSTOL;
    self->wcstold=BLTN_WCSTOLD;
    self->wcstoll=BLTN_WCSTOLL;
    self->wcstoul=BLTN_WCSTOUL;
    self->wcstoull=BLTN_WCSTOULL;
    self->fgetws=BLTN_FGETWS;
    self->wcscat=BLTN_WCSCAT;
    self->wcschr=BLTN_WCSCHR;
    self->wcscpy=BLTN_WCSCPY;
    self->wcsncat=BLTN_WCSNCAT;
    self->wcsncpy=BLTN_WCSNCPY;
    self->wcspbrk=BLTN_WCSPBRK;
    self->wcsrchr=BLTN_WCSRCHR;
    self->wcsstr=BLTN_WCSSTR;
    self->wcstok=BLTN_WCSTOK;
    self->wmemchr=BLTN_WMEMCHR;
    self->wmemcpy=BLTN_WMEMCPY;
    self->wmemmove=BLTN_WMEMMOVE;
    self->wmemset=BLTN_WMEMSET;
    self->wcpcpy=BLTN_WCPCPY;
    self->wcpncpy=BLTN_WCPNCPY;
    self->wcsdup=BLTN_WCSDUP;
    self->btowc=BLTN_BTOWC;
    self->fgetwc=BLTN_FGETWC;
    self->fputwc=BLTN_FPUTWC;
    self->getwc=BLTN_GETWC;
    self->getwchar=BLTN_GETWCHAR;
    self->putwc=BLTN_PUTWC;
    self->putwchar=BLTN_PUTWCHAR;
    self->ungetwc=BLTN_UNGETWC;
    self->towlower=BLTN_TOWLOWER;
    self->towupper=BLTN_TOWUPPER;

    return 0;
}