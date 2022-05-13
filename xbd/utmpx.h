#pragma once

int include_utmpx_h(Lib *self, FILE *file) {

    __basedef(utmpx_h, "<utmpx.h>")

    __dentr(enums, Enum[])
        __predef("")
            EREF(EMPTY)
            EREF(BOOT_TIME)
            EREF(OLD_TIME)
            EREF(NEW_TIME)
            EREF(USER_PROCESS)
            EREF(INIT_PROCESS)
            EREF(LOGIN_PROCESS)
            EREF(DEAD_PROCESS)
        __preend("")

    __dexit(enums)

    __dentr(structs, Struct[])
        __memdef(utmpx_s)
        __member(utmpx_s, ut_user,  "char []")
        __member(utmpx_s, ut_id,    "char []")
        __member(utmpx_s, ut_line,  "char []")
        __member(utmpx_s, ut_pid,   "pid_t")
        __member(utmpx_s, ut_type,  "short")
        __member(utmpx_s, ut_tv,    "timeval T")
        __enddef(utmpx_s)
    __dexit(structs)
    __baseret(utmpx_h)
}

int test_utmpx_h(Lib *self, FILE *file) {
#   ifndef BLTN_SETUTXENT
#   define BLTN_SETUTXENT setutxent
#   endif
#   ifndef BLTN_ENDUTXENT
#   define BLTN_ENDUTXENT endutxent
#   endif
#   ifndef BLTN_GETUTXENT
#   define BLTN_GETUTXENT getutxent
#   endif
#   ifndef BLTN_GETUTXID
#   define BLTN_GETUTXID getutxid
#   endif
#   ifndef BLTN_GETUTXLINE
#   define BLTN_GETUTXLINE getutxline
#   endif
#   ifndef BLTN_PUTUTXLINE
#   define BLTN_PUTUTXLINE pututxline
#   endif
    self->setutxent     = BLTN_SETUTXENT;
    self->endutxent     = BLTN_ENDUTXENT;
    self->getutxent     = BLTN_GETUTXENT;
    self->getutxid      = BLTN_GETUTXID;
    self->getutxline    = BLTN_GETUTXLINE;
    self->pututxline    = BLTN_PUTUTXLINE;
    return 0;
}