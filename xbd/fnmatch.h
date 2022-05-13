
#pragma once

int include_fnmatch_h(Lib *self, FILE *file) {
    __basedef(fnmatch_h, "<fnmatch.h>")
    __dentr(enums, Enum[])
        __predef("FNM")
            EDEF_(FNM,NOMATCH)
        __preend("FNM")
        __predef("FNM")
            EDEF_(FNM,PATHNAME)
            EDEF_(FNM,PERIOD)
            EDEF_(FNM,NOESCAPE)
#       ifdef FNM_CASEFOLD
            EDEF_(FNM,CASEFOLD)
#       endif
        __preend("FNM", .fmt="x")
    __dexit(enums)
    __baseret(fnmatch_h)
}

int test_fnmatch_h(Lib *self, FILE *file) {
#   ifndef BLTN_FNMATCH
#   define BLTN_FNMATCH fnmatch
#   endif
    self->fnmatch = BLTN_FNMATCH;
    return 0;
}