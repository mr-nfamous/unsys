#pragma once

int include_strings_h(Lib *self, FILE *file) {
    __basedef(strings_h, "<strings.h>")
    __dentr(enums, Enum[])
    __dexit(enums)
    __dentr(structs, Struct[])
    __dexit(structs)
    __baseret(strings_h)
}

int test_strings_h(Lib *self, FILE *file) {
#   ifndef BLTN_FFS
#   define BLTN_FFS ffs
#   endif
#   ifndef BLTN_STRCASECMP
#   define BLTN_STRCASECMP strcasecmp
#   endif
#   ifndef BLTN_STRCASECMP_L
#   define BLTN_STRCASECMP_L strcasecmp_l
#   endif
#   ifndef BLTN_STRNCASECMP
#   define BLTN_STRNCASECMP strncasecmp
#   endif
#   ifndef BLTN_STRNCASECMP_L
#   define BLTN_STRNCASECMP_L strncasecmp_l
#   endif
#   ifdef _XOPEN_UNIX
    self->ffs = BLTN_FFS;
#   endif
    self->strcasecmp    = BLTN_STRCASECMP;
    self->strncasecmp   = BLTN_STRNCASECMP;
    self->strcasecmp_l  = BLTN_STRCASECMP_L;
    self->strncasecmp_l = BLTN_STRNCASECMP_L;
    return 0;
}