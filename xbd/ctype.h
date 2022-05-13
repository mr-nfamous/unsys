#pragma once

int include_ctype_h(Lib *self, FILE *file) {

    __basedef(ctype_h, "<ctype.h>")

    __dentr(enums, Enum[])
    __dexit(enums)

    __dentr(structs, Struct[])
    __dexit(structs)
    __baseret(ctype_h)
}

int test_ctype_h(Lib *self, FILE *file) {
#   ifndef BLTN_ISALNUM
#   define BLTN_ISALNUM isalnum
#   endif
#   ifndef BLTN_ISALPHA
#   define BLTN_ISALPHA isalpha
#   endif
#   ifndef BLTN_ISBLANK
#   define BLTN_ISBLANK isblank
#   endif
#   ifndef BLTN_ISASCII
#   define BLTN_ISASCII isascii
#   endif
#   ifndef BLTN_ISCNTRL
#   define BLTN_ISCNTRL iscntrl
#   endif
#   ifndef BLTN_ISDIGIT
#   define BLTN_ISDIGIT isdigit
#   endif
#   ifndef BLTN_ISGRAPH
#   define BLTN_ISGRAPH isgraph
#   endif
#   ifndef BLTN_ISLOWER
#   define BLTN_ISLOWER islower
#   endif
#   ifndef BLTN_ISPRINT
#   define BLTN_ISPRINT isprint
#   endif
#   ifndef BLTN_ISPUNCT
#   define BLTN_ISPUNCT ispunct
#   endif
#   ifndef BLTN_ISSPACE
#   define BLTN_ISSPACE isspace
#   endif
#   ifndef BLTN_ISUPPER
#   define BLTN_ISUPPER isupper
#   endif
#   ifndef BLTN_ISXDIGIT
#   define BLTN_ISXDIGIT isxdigit
#   endif
#   ifndef BLTN_TOASCII
#   define BLTN_TOASCII toascii
#   endif
#   ifndef BLTN_TOLOWER
#   define BLTN_TOLOWER tolower
#   endif
#   ifndef BLTN_TOUPPER
#   define BLTN_TOUPPER toupper
#   endif
#   ifndef BLTN_ISALNUM_L
#   define BLTN_ISALNUM_L isalnum_l
#   endif
#   ifndef BLTN_ISALPHA_L
#   define BLTN_ISALPHA_L isalpha_l
#   endif
#   ifndef BLTN_ISBLANK_L
#   define BLTN_ISBLANK_L isblank_l
#   endif
#   ifndef BLTN_ISCNTRL_L
#   define BLTN_ISCNTRL_L iscntrl_l
#   endif
#   ifndef BLTN_ISDIGIT_L
#   define BLTN_ISDIGIT_L isdigit_l
#   endif
#   ifndef BLTN_ISGRAPH_L
#   define BLTN_ISGRAPH_L isgraph_l
#   endif
#   ifndef BLTN_ISLOWER_L
#   define BLTN_ISLOWER_L islower_l
#   endif
#   ifndef BLTN_ISPRINT_L
#   define BLTN_ISPRINT_L isprint_l
#   endif
#   ifndef BLTN_ISPUNCT_L
#   define BLTN_ISPUNCT_L ispunct_l
#   endif
#   ifndef BLTN_ISSPACE_L
#   define BLTN_ISSPACE_L isspace_l
#   endif
#   ifndef BLTN_ISUPPER_L
#   define BLTN_ISUPPER_L isupper_l
#   endif
#   ifndef BLTN_ISXDIGIT_L
#   define BLTN_ISXDIGIT_L isxdigit_l
#   endif
#   ifndef BLTN_TOLOWER_L
#   define BLTN_TOLOWER_L tolower_l
#   endif
#   ifndef BLTN_TOUPPER_L
#   define BLTN_TOUPPER_L toupper_l
#   endif
    self->isalnum=BLTN_ISALNUM;
    self->isalpha=BLTN_ISALPHA;
    self->isblank=BLTN_ISBLANK;
    self->iscntrl=BLTN_ISCNTRL;
    self->isdigit=BLTN_ISDIGIT;
    self->isgraph=BLTN_ISGRAPH;
    self->islower=BLTN_ISLOWER;
    self->isprint=BLTN_ISPRINT;
    self->ispunct=BLTN_ISPUNCT;
    self->isspace=BLTN_ISSPACE;
    self->isupper=BLTN_ISUPPER;
    self->isxdigit=BLTN_ISXDIGIT;
    self->tolower=BLTN_TOLOWER;
    self->toupper=BLTN_TOUPPER;
    self->isascii=BLTN_ISASCII;
    self->toascii=BLTN_TOASCII;
    self->isalnum_l=BLTN_ISALNUM_L;
    self->isalpha_l=BLTN_ISALPHA_L;
    self->isblank_l=BLTN_ISBLANK_L;
    self->iscntrl_l=BLTN_ISCNTRL_L;
    self->isdigit_l=BLTN_ISDIGIT_L;
    self->isgraph_l=BLTN_ISGRAPH_L;
    self->islower_l=BLTN_ISLOWER_L;
    self->isprint_l=BLTN_ISPRINT_L;
    self->ispunct_l=BLTN_ISPUNCT_L;
    self->isspace_l=BLTN_ISSPACE_L;
    self->isupper_l=BLTN_ISUPPER_L;
    self->isxdigit_l=BLTN_ISXDIGIT_L;
    self->tolower_l=BLTN_TOLOWER_L;
    self->toupper_l=BLTN_TOUPPER_L;

    return 0;
}