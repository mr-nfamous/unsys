#pragma once

int include_utime_h(Lib *self, FILE *file) {

    __basedef(utime_h, "<utime.h>")

    __dentr(structs, Struct[])
        __memdef(utimbuf_s)
        __member(utimbuf_s, actime, "{time_t}")
        __member(utimbuf_s, modtime, "{time_t}")
        __enddef(utimbuf_s)
    __dexit(structs)
    __baseret(utime_h)
}

int test_utime_h(Lib *self, FILE *file) {

// required
#   ifndef BLTN_UTIME
#   define BLTN_UTIME utime
#   endif
    self->utime = utime;
    return 0;
}