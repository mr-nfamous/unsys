#pragma once

int include_iconv_h(Lib *self, FILE *file) {

    __basedef(iconv_h, "<iconv.h>")

    __dentr(enums, Enum[])
    __dexit(enums)

    __dentr(structs, Struct[])
    __dexit(structs)
    __baseret(iconv_h)
}

int test_iconv_h(Lib *self, FILE *file) {
#   ifndef BLTN_ICONV
#   define BLTN_ICONV iconv
#   endif
#   ifndef BLTN_ICONV_CLOSE
#   define BLTN_ICONV_CLOSE iconv_close
#   endif
#   ifndef BLTN_ICONV_OPEN
#   define BLTN_ICONV_OPEN iconv_open
#   endif
    self->iconv         = BLTN_ICONV;
    self->iconv_close   = BLTN_ICONV_CLOSE;
    self->iconv_open    = BLTN_ICONV_OPEN;
    return 0;
}