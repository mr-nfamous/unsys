#pragma once

int include_ulimit_h(Lib *self, FILE *file) {

    __basedef(ulimit_h, "<ulimit.h>")

    __dentr(enums, Enum[])
        __predef("UL")
            EDEF_(UL,GETFSIZE)
            EDEF_(UL,SETFSIZE)
        __preend("UL")
    __dexit(enums)

    __dentr(structs, Struct[])
    __dexit(structs)
    __baseret(ulimit_h)
}

int test_ulimit_h(Lib *self, FILE *file) {
#   ifndef BLTN_ULIMIT
#   define BLTN_ULIMIT ulimit
#   endif
    self->ulimit   = BLTN_ULIMIT;
    return 0;
}