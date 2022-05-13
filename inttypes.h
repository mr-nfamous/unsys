#pragma once

int include_inttypes_h(Lib *self, FILE *file) {

    __basedef(inttypes_h, "<inttypes.h>")
    __dentr(structs, Struct[])
        __memdef(imaxdiv_t)
        __member(imaxdiv_t, quot, "intmax_t")
        __member(imaxdiv_t, rem, "intmax_t")
        __enddef(imaxdiv_t)
    __dexit(structs)
    __baseret(inttypes_h)
}

int test_inttypes_h(Lib *self, FILE *file) {
#   ifndef BLTN_IMAXDIV
#   define BLTN_IMAXDIV imaxdiv
#   endif
#   ifndef BLTN_IMAXABS
#   define BLTN_IMAXABS imaxabs
#   endif
#   ifndef BLTN_STRTOIMAX
#   define BLTN_STRTOIMAX strtoimax
#   endif
#   ifndef BLTN_WCSTOIMAX
#   define BLTN_WCSTOIMAX wcstoimax
#   endif
#   ifndef BLTN_STRTOUMAX
#   define BLTN_STRTOUMAX strtoumax
#   endif
#   ifndef BLTN_WCSTOUMAX
#   define BLTN_WCSTOUMAX wcstoumax
#   endif
    self->imaxdiv   = BLTN_IMAXDIV;
    self->imaxabs   = BLTN_IMAXABS;
    self->strtoimax = BLTN_STRTOIMAX;
    self->wcstoimax = BLTN_WCSTOIMAX;
    self->strtoumax = BLTN_STRTOUMAX;
    self->wcstoumax = BLTN_WCSTOUMAX;

    return 0;
}