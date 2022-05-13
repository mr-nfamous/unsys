
#pragma once

int include_glob_h(Lib *self, FILE *file) {
    __basedef(glob_h, "<glob.h>")
    __dentr(enums, Enum[])
        __predef("GLOB")
            EDEF_(GLOB,APPEND)
            EDEF_(GLOB,DOOFFS)
            EDEF_(GLOB,ERR)
            EDEF_(GLOB,MARK)
            EDEF_(GLOB,NOCHECK)
            EDEF_(GLOB,NOESCAPE)
            EDEF_(GLOB,NOSORT)
#           ifdef GLOB_ALTDIRFUNC
            EDEF_(GLOB,ALTDIRFUNC)
#           endif
#           ifdef GLOB_BRACE
            EDEF_(GLOB,BRACE)
#           endif
#           ifdef GLOB_MAGCHAR
            EDEF_(GLOB,MAGCHAR)
#           endif
#           ifdef GLOB_TILDE
            EDEF_(GLOB,TILDE)
#           endif
#           ifdef GLOB_LIMIT
            EDEF_(GLOB,LIMIT)
#           endif
#           ifdef GLOB_NOMAGIC
            EDEF_(GLOB,NOMAGIC)
#           endif
#           ifdef GLOB_QUOTE
            EDEF_(GLOB,QUOTE)
#           endif
        __preend("GLOB", .fmt="x")
        __predef("GLOB")
            EDEF_(GLOB,ABORTED)
            EDEF_(GLOB,NOMATCH)
            EDEF_(GLOB,NOSPACE)
        __preend("GLOB")
    __dexit(enums)

    __dentr(structs, Struct[])
        __memdef(glob_t)
        __member(glob_t, gl_pathc, "{size_t}")
        __member(glob_t, gl_pathv, "{char_pp}")
        __member(glob_t, gl_offs, "{size_t}")
#       ifdef EXTENDED_GLOB_T
        EXTENDED_GLOB_T()
#       endif
        __enddef(glob_t)
    __dexit(structs)
    __baseret(glob_h)
}

int test_glob_h(Lib *self, FILE *file) {
#   ifndef BLTN_GLOB
#   define BLTN_GLOB glob
#   endif
#   ifndef BLTN_GLOBFREE
#   define BLTN_GLOBFREE globfree
#   endif
    self->glob = glob;
    self->globfree=globfree;
    return 0;
}