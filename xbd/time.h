#pragma once

int include_time_h(Lib *self, FILE *file) {

    __basedef(time_h, "<time.h>")

    __dentr(enums, Enum[])
        __predef("")
            EREF(CLOCKS_PER_SEC)
            EREF(MAX_CLOCKS)
        __preend("")

#   if (_POSIX_CLOCK_SELECTION > 0)

        __predef("")
            EREF(TIMER_ABSTIME)
        __preend("", .fmt="x")

        __predef("CLOCK")

            EDEF_(CLOCK,REALTIME)

#           ifdef CLOCK_REALTIME_COARSE
            EDEF_(CLOCK,REALTIME_COARSE)
#           endif

#           ifdef CLOCK_REALTIME_ALARM
            EDEF_(CLOCK,REALTIME_ALARM)
#           endif

#           ifdef CLOCK_BOOTTIME
            EDEF_(CLOCK,BOOTTIME)
#           endif

#           ifdef CLOCK_BOOTTIME_ALARM
            EDEF_(CLOCK,BOOTTIME_ALARM)
#           endif

#           ifdef CLOCK_SGI_CYCLE
            EDEF_(CLOCK,SGI_CYCLE)
#           endif

#           ifdef CLOCK_TAI
            EDEF_(CLOCK,TAI)
#           endif

#       if (_POSIX_MONOTONIC_CLOCK > 0)
            EDEF_(CLOCK,MONOTONIC)
#           ifdef CLOCK_MONOTONIC_RAW
            EDEF_(CLOCK,MONOTONIC_RAW)
#           endif
#           ifdef CLOCK_MONOTONIC_COURSE
            EDEF_(CLOCK,MONOTONIC_COURSE)
#           endif
#       endif

#       if (_POSIX_CPUTIME > 0)
            EDEF_(CLOCK,PROCESS_CPUTIME_ID)
#       endif

#       if (_POSIX_THREAD_CPUTIME_ > 0)
            EDEF_(CLOCK,THREAD_CPUTIME_ID)
#       endif

        __preend("CLOCK")

#   endif // _POSIX_CLOCK_SELECTION 


    __dexit(enums)

    __dentr(structs, Struct[])
        __memdef(tm_s)
        __member(tm_s, tm_sec, "{int_t}")
        __member(tm_s, tm_min, "{int_t}")
        __member(tm_s, tm_hour, "{int_t}")
        __member(tm_s, tm_mday, "{int_t}")
        __member(tm_s, tm_mon, "{int_t}")
        __member(tm_s, tm_year, "{int_t}")
        __member(tm_s, tm_wday, "{int_t}")
        __member(tm_s, tm_yday, "{int_t}")
        __member(tm_s, tm_isdst, "{int_t}")
        __enddef(tm_s)
        __memdef(timespec_s)
        __member(timespec_s, tv_sec, "{time_t}")
        __member(timespec_s, tv_nsec, "{long}")
        __enddef(timespec_s)
        __memdef(itimerspec_s)
        __member(itimerspec_s, it_interval, "{timespec_s")
        __member(itimerspec_s, it_value, "{timespec_s}")
        __enddef(itimerspec_s)
    __dexit(structs)
    __baseret(time_h)
}

int test_time_h(Lib *self, FILE *file) {
#   ifndef BLTN_CLOCK_GETCPUCLOCKID
#   define BLTN_CLOCK_GETCPUCLOCKID clock_getcpuclockid
#   endif
#   ifndef BLTN_CLOCK_GETRES
#   define BLTN_CLOCK_GETRES clock_getres
#   endif
#   ifndef BLTN_CLOCK_GETTIME
#   define BLTN_CLOCK_GETTIME clock_gettime
#   endif
#   ifndef BLTN_CLOCK_SETTIME
#   define BLTN_CLOCK_SETTIME clock_settime
#   endif
#   ifndef BLTN_CLOCK_NANOSLEEP
#   define BLTN_CLOCK_NANOSLEEP clock_nanosleep
#   endif
#   ifndef BLTN_NANOSLEEP
#   define BLTN_NANOSLEEP nanosleep
#   endif
#   ifndef BLTN_CLOCK
#   define BLTN_CLOCK clock
#   endif
#   ifndef BLTN_DIFFTIME
#   define BLTN_DIFFTIME difftime
#   endif
#   ifndef BLTN_GETDATE
#   define BLTN_GETDATE getdate
#   endif
#   ifndef BLTN_GMTIME
#   define BLTN_GMTIME gmtime
#   endif
#   ifndef BLTN_GMTIME_R
#   define BLTN_GMTIME_R gmtime_r
#   endif
#   ifndef BLTN_LOCALTIME
#   define BLTN_LOCALTIME localtime
#   endif
#   ifndef BLTN_LOCALTIME_R
#   define BLTN_LOCALTIME_R localtime_r
#   endif
#   ifndef BLTN_MKTIME
#   define BLTN_MKTIME mktime
#   endif
#   ifndef BLTN_TIME
#   define BLTN_TIME time
#   endif
#   ifndef BLTN_STRFTIME
#   define BLTN_STRFTIME strftime
#   endif
#   ifndef BLTN_STRFTIME_L
#   define BLTN_STRFTIME_L strftime_l
#   endif
#   ifndef BLTN_STRPTIME
#   define BLTN_STRPTIME strptime
#   endif
#   ifndef BLTN_TZSET
#   define BLTN_TZSET tzset
#   endif
#   ifndef BLTN_GET_TIMESPEC
#   define BLTN_GET_TIMESPEC 0
#   endif
#   ifndef BLTN_TIMER_CREATE
#   define BLTN_TIMER_CREATE timer_create
#   endif
#   ifndef BLTN_TIMER_DELETE
#   define BLTN_TIMER_DELETE timer_delete
#   endif
#   ifndef BLTN_TIMER_GETOVERRUN
#   define BLTN_TIMER_GETOVERRUN timer_getoverrun
#   endif
#   ifndef BLTN_TIMER_GETTIME
#   define BLTN_TIMER_GETTIME timer_gettime
#   endif
#   ifndef BLTN_TIMER_SETTIME
#   define BLTN_TIMER_SETTIME timer_settime
#   endif
    self->clock     = BLTN_CLOCK;
    self->difftime  = BLTN_DIFFTIME;
    self->gmtime    = BLTN_GMTIME;
    self->localtime = BLTN_LOCALTIME;
    self->mktime    = BLTN_MKTIME;
    self->time      = BLTN_TIME;
    self->strftime  = BLTN_STRFTIME;

    self->nanosleep     = BLTN_NANOSLEEP;
    self->getdate       = BLTN_GETDATE;
    self->gmtime_r      = BLTN_GMTIME_R;
    self->localtime_r   = BLTN_LOCALTIME_R;
    self->strftime_l    = BLTN_STRFTIME_L;
    self->strptime      = BLTN_STRPTIME;
    self->tzset         = BLTN_TZSET;
    self->clock_getcpuclockid   = BLTN_CLOCK_GETCPUCLOCKID;
    self->clock_getres          = BLTN_CLOCK_GETRES;
    self->clock_gettime         = BLTN_CLOCK_GETTIME;
    self->clock_settime         = BLTN_CLOCK_SETTIME;
    self->clock_nanosleep       = BLTN_CLOCK_NANOSLEEP;

    self->timer.create      = BLTN_TIMER_CREATE;
    self->timer.delete      = BLTN_TIMER_DELETE;
    self->timer.getoverrun  = BLTN_TIMER_GETOVERRUN;
    self->timer.gettime     = BLTN_TIMER_GETTIME;
    self->timer.settime     = BLTN_TIMER_SETTIME;

    return 0;
}