#pragma once

int include_$_h(Lib *self, FILE *file) {

    __basedef($_h, "<$.h>")

    __dentr(enums, Enum[])
        __predef("@")
            EDEF_(@,)
        __preend("@", .fmt="x")
    __dexit(enums)

    __dentr(structs, Struct[])
        __memdef(&)
        __member(&, ..,    "o")
        __member(&, ..,    "{pid_t}")
        __enddef(&)
    __dexit(structs)
    __baseret($_h)
}

int test_$_h(Lib *self, FILE *file) {

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