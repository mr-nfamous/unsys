
#pragma once

int include_regex_h(Lib *self, FILE *file) {

    __basedef(regex_h, "<regex.h>")

    __dentr(enums, Enum[])
        __predef("REG")
            EDEF_(REG,BASIC)
            EDEF_(REG,EXTENDED)
            EDEF_(REG,ICASE)
            EDEF_(REG,NOSUB)
            EDEF_(REG,NEWLINE)
#           ifdef REG_NOSPEC 
            EDEF_(REG,NOSPEC)
#           endif
#           ifdef REG_PEND
            EDEF_(REG,PEND)
#           endif
#           ifdef REG_DUMP
            EDEF_(REG,DUMP)
#           endif
        __preend("REG", .fmt="x")
        __predef("REG")
            EDEF_(REG,NOMATCH)
            EDEF_(REG,BADPAT)
            EDEF_(REG,ECOLLATE)
            EDEF_(REG,ECTYPE)
            EDEF_(REG,EESCAPE)
            EDEF_(REG,ESUBREG)
            EDEF_(REG,EBRACK)
            EDEF_(REG,EPAREN)
            EDEF_(REG,EBRACE)
            EDEF_(REG,BADBR)
            EDEF_(REG,ERANGE)
            EDEF_(REG,ESPACE)
            EDEF_(REG,BADRPT)
#           ifdef REG_EMPTY
            EDEF_(REG,EMPTY)
#           endif
#           ifdef REG_ASSERT
            EDEF_(REG,ASSERT)
#           endif
#           ifdef REG_INVARG
            EDEF_(REG,INVARG)
#           endif
#           ifdef REG_ATOI
            EDEF_(REG,ATOI)
#           endif
#           ifdef REG_ITOA
            EDEF_(REG,ITOA)
#           endif
        __preend("REG")
        __predef("REG")
            EDEF_(REG,NOTBOL)
            EDEF_(REG,NOTEOL)
#           ifdef REG_STARTEND
            EDEF_(REG,STARTEND)
#           endif
#           ifdef REG_TRACE
            EDEF_(REG,TRACE)
#           endif
#           ifdef REG_LARGE
            EDEF_(REG,LARGE)
#           endif
#           ifdef REG_BACKR
            EDEF_(REG,BACKR)
#           endif
        __preend("REG", .fmt="x")
    __dexit(enums)

    __dentr(structs, Struct[])
        __memdef(regex_t)
        __member(regex_t, re_nsub, "size_t")
        __enddef(regex_t)
        __memdef(regmatch_t)
        __member(regmatch_t, rm_so, "regoff_t")
        __member(regmatch_t, rm_eo, "regoff_t")
        __enddef(regmatch_t)
    __dexit(structs)
    __baseret(regex_h)
}

int test_regex_h(Lib *self, FILE *file) {
#   ifndef BLTN_REGCOMP
#   define BLTN_REGCOMP regcomp
#   endif
#   ifndef BLTN_REGEXEC
#   define BLTN_REGEXEC regexec
#   endif
#   ifndef BLTN_REGERROR
#   define BLTN_REGERROR regerror
#   endif
#   ifndef BLTN_REGFREE
#   define BLTN_REGFREE regfree
#   endif
    self->regcomp   = BLTN_REGCOMP;
    self->regexec   = BLTN_REGEXEC;
    self->regerror  = BLTN_REGERROR;
    self->regfree   = BLTN_REGFREE;
    return 0;
}