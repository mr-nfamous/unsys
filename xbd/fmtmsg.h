#pragma once
int include_fmtmsg_h(Lib *self, FILE *file) {

    __basedef(fmtmsg_h, "<fmtmsg.h>")

    __dentr(enums, Enum[])
        __predef("MM")
            EDEF_(MM,HARD)
            EDEF_(MM,SOFT)
            EDEF_(MM,FIRM)
            EDEF_(MM,APPL)
            EDEF_(MM,UTIL)
            EDEF_(MM,OPSYS)
            EDEF_(MM,RECOVER)
            EDEF_(MM,NRECOV)
            EDEF_(MM,HALT)
            EDEF_(MM,ERROR)
            EDEF_(MM,WARNING)
            EDEF_(MM,INFO)
            EDEF_(MM,NOSEV)
            EDEF_(MM,PRINT)
            EDEF_(MM,CONSOLE)
        __preend("MM", .fmt="x")
        __predef("MM")
            EDEF_(MM,NOTOK)
            EDEF_(MM,NOMSG)
            EDEF_(MM,NOCON)
            EDEF_(MM,OK)
        __preend("MM", .fmt="x")
        __predef("MM")
            EDEF_(MM,NULLLBL)
            EDEF_(MM,NULLSEV)
            EDEF_(MM,NULLMC)
            EDEF_(MM,NULLACT)
            EDEF_(MM,NULLTXT)
            EDEF_(MM,NULLTAG)
            EDEF_(MM,NOMSG)
            EDEF_(MM,NOCON)
            EDEF_(MM,OK)
        __preend("MM", .fmt="x")
    __dexit(enums)
    __dentr(structs, Struct[])
    __dexit(structs)
    __baseret(fmtmsg_h)
}

int test_fmtmsg_h(Lib *self, FILE *file) {
#   ifndef BLTN_FMTMSG
#   define BLTN_FMTMSG fmtmsg
#   endif
    self->fmtmsg = BLTN_FMTMSG;
    return 0;
}