#pragma once

int include_monetary_h(Lib *self, FILE *file) {

    __basedef(monetary_h, "<monetary.h>")

    __dentr(enums, Enum[])
    __dexit(enums)

    __dentr(structs, Struct[])
    __dexit(structs)
    
    __baseret(monetary_h)
}

int test_monetary_h(Lib *self, FILE *file) {
#   ifndef BLTN_STRFMON
#   define BLTN_STRFMON strfmon
#   endif
#   ifndef BLTN_STRFMON_L
#   define BLTN_STRFMON_L strfmon_l
#   endif
    self->strfmon=BLTN_STRFMON;
    self->strfmon_l=BLTN_STRFMON_L;
    return 0;
}