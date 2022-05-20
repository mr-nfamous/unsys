#pragma once

int include_stropts_h(Lib *self, FILE *file) {

    __basedef(stropts_h, "<stropts.h>")

    __dentr(enums, Enum[])
        __predef("@")
            EDEF_(@,)
        __preend("@", .fmt="x")
    __dexit(enums)

    __dentr(structs, Struct[])
        __memdef(bandinfo_s)
        __member(bandinfo_s, bi_flag, "int")
        __member(bandinfo_s, bi_pri, "uchar")
        __enddef(bandinfo_s)
    __dexit(structs)
    __baseret(stropts_h)
}

int test_stropts_h(Lib *self, FILE *file) {

// required
#   ifndef BLTN_
#   define BLTN_ <>
#   endif

// extensions
#   ifdef BLTN_
    self->    = BLTN_;
#   endif

    self->   = BLTN_;
    return 0;
}