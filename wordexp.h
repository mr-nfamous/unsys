

#pragma once

int include_wordexp_h(Lib *self, FILE *file) {

    __basedef(wordexp_h, "<wordexp.h>")

    __dentr(enums, Enum[])
        __predef("WRDE")
            EDEF_(WRDE,UNDEF)
            EDEF_(WRDE,SHOWERR)
            EDEF_(WRDE,REUSE)
            EDEF_(WRDE,NOCMD)
            EDEF_(WRDE,DOOFFS)
            EDEF_(WRDE,APPEND)
        __preend("WRDE", .fmt="x")
        __predef("WRDE")
            EDEF_(WRDE,UNDEF)
            EDEF_(WRDE,BADCHAR)
            EDEF_(WRDE,BADVAL)
            EDEF_(WRDE,CMDSUB)
            EDEF_(WRDE,NOSPACE)
            EDEF_(WRDE,SYNTAX)
        __preend("WRDE")
    __dexit(enums)
    __dentr(structs, Struct[])
        __memdef(wordexp_t)
        __member(wordexp_t, we_wordc, "size_t")
        __member(wordexp_t, we_wordv, "char **")
        __member(wordexp_t, we_offs, "size_t")
        __enddef(wordexp_t)
    __dexit(structs)
    __baseret(wordexp_h)
}

int test_wordexp_h(Lib *self, FILE *file) {
#   ifndef BLTN_WORDEXP
#   define BLTN_WORDEXP wordexp
#   endif
#   ifndef BLTN_WORDFREE
#   define BLTN_WORDFREE wordfree
#   endif
    self->wordexp=BLTN_WORDEXP;
    self->wordfree=BLTN_WORDFREE;
    return 0;
}