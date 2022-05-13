#pragma once

int include_sys_time_h(Lib *self, FILE *file) {

    __basedef(sys_time_h, "<sys/time.h>")

    __dentr(enums, Enum[])
        __predef("ITIMER")
            EDEF_(ITIMER,REAL)
            EDEF_(ITIMER,VIRTUAL)
            EDEF_(ITIMER,PROF)
        __preend("ITIMER")
    __dexit(enums)

    __dentr(structs, Struct[])
        __memdef(timeval_s)
        __member(timeval_s, tv_sec, "time_t")
        __member(timeval_s, tv_usec, "suseconds_t")
        __enddef(timeval_s)
    __dexit(structs)
    __baseret(sys_time_h)
}

int test_sys_time_h(Lib *self, FILE *file) {
#   ifndef BLTN_GETITIMER
#   define BLTN_GETITIMER 0
#   endif
#   ifndef BLTN_GETTIMEOFDAY
#   define BLTN_GETTIMEOFDAY 0
#   endif
#   ifndef BLTN_SETITIMER
#   define BLTN_SETITIMER 0
#   endif
#   ifndef BLTN_UTIMES
#   define BLTN_UTIMES utimes
#   endif
#   ifndef BLTN_LUTIMES
#   define BLTN_LUTIMES 0
#   endif
#   ifndef BLTN_FUTIMES
#   define BLTN_FUTIMES 0
#   endif
#   ifndef BLTN_FUTIMESAT
#   define BLTN_FUTIMESAT 0
#   endif
    self->getitimer     = BLTN_GETITIMER;
    self->gettimeofday  = BLTN_GETTIMEOFDAY;
    self->setitimer     = BLTN_SETITIMER;
    self->utimes        = BLTN_UTIMES;
    self->lutimes       = BLTN_LUTIMES;
    self->futimes       = BLTN_FUTIMES;
    self->futimesat     = BLTN_FUTIMESAT;
    return 0;
}