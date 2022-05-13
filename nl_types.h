#pragma once

int include_nl_types_h(Lib *self, FILE *file) {

    __basedef(nl_types_h, "<nl_types.h>")

    __dentr(enums, Enum[])
        __predef("NL")
            EDEF_(NL,SETD)
            EDEF_(NL,CAT_LOCALE)
        __preend("NL")
    __dexit(enums)

    __dentr(structs, Struct[])
    __dexit(structs)
    __baseret(nl_types_h)
}

int test_nl_types_h(Lib *self, FILE *file) {
#   ifndef BLTN_CATCLOSE
#   define BLTN_CATCLOSE catclose?
#   endif
#   ifndef BLTN_CATGETS
#   define BLTN_CATGETS catgets?
#   endif
#   ifndef BLTN_CATOPEN
#   define BLTN_CATOPEN catopen?
#   endif
    self->catclose=BLTN_CATCLOSE;
    self->catgets=BLTN_CATGETS;
    self->catopen=BLTN_CATOPEN;
    return 0;
}