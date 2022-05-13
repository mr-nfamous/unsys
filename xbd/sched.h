#pragma once

int include_sched_h(Lib *self, FILE *file) {

    __basedef(sched_h, "<sched.h>")

    __dentr(enums, Enum[])
        __predef("SCHED")
            EDEF_(SCHED,FIFO)
            EDEF_(SCHED,RR)
            EDEF_(SCHED,OTHER)
#        ifdef SCHED_SPORADIC
            EDEF_(SCHED,SPORADIC)
#        endif
#        ifdef SCHED_NORMAL
            EDEF_(SCHED,NORMAL)
#        endif
#        ifdef SCHED_BATCH
            EDEF_(SCHED,BATCH)
#        endif
#        ifdef SCHED_IDLE
            EDEF_(SCHED,IDLE)
#        endif
#        ifdef SCHED_DEADLINE
            EDEF_(SCHED,DEADLINE)
#        endif
        __preend("SCHED")
    __dexit(enums)

    __dentr(structs, Struct[])
        __memdef(sched_param_s)
        __member(sched_param_s, sched_priority, "int")
#   if (_POSIX_SPORADIC_SERVER > 0)
        __member(sched_param_s, sched_ss_low_priority, "int")
        __member(sched_param_s, sched_ss_repl_period, "timespec_s")
        __member(sched_param_s, sched_ss_init_budget, "timespec_s")
        __member(sched_param_s, sched_ss_max_repl, "int")
#   endif
        __enddef(sched_param_s)
    __dexit(structs)
    __baseret(sched_h)
}

int test_sched_h(Lib *self, FILE *file) {
#   ifndef BLTN_SCHED_GET_PRIORITY_MAX
#   define BLTN_SCHED_GET_PRIORITY_MAX  sched_get_priority_max
#   endif
#   ifndef BLTN_SCHED_GET_PRIORITY_MIN
#   define BLTN_SCHED_GET_PRIORITY_MIN sched_get_priority_min
#   endif
#   ifndef BLTN_SCHED_GETPARAM
#   define BLTN_SCHED_GETPARAM sched_getparam
#   endif
#   ifndef BLTN_SCHED_GETSCHEDULER
#   define BLTN_SCHED_GETSCHEDULER sched_getscheduler
#   endif
#   ifndef BLTN_SCHED_RR_GET_INTERVAL
#   define BLTN_SCHED_RR_GET_INTERVAL sched_rr_get_interval
#   endif
#   ifndef BLTN_SCHED_SETPARAM
#   define BLTN_SCHED_SETPARAM sched_setparam
#   endif
#   ifndef BLTN_SCHED_SETSCHEDULER
#   define BLTN_SCHED_SETSCHEDULER sched_setscheduler
#   endif
#   ifndef BLTN_SCHED_YIELD
#   define BLTN_SCHED_YIELD sched_yield
#   endif
    self->sched.get_priority_max = BLTN_SCHED_GET_PRIORITY_MAX;
    self->sched.get_priority_min = BLTN_SCHED_GET_PRIORITY_MIN;
    self->sched.getparam         = BLTN_SCHED_GETPARAM;
    self->sched.getscheduler     = BLTN_SCHED_GETSCHEDULER;
    self->sched.rr_get_interval  = BLTN_SCHED_RR_GET_INTERVAL;
    self->sched.setparam         = BLTN_SCHED_SETPARAM;
    self->sched.setscheduler     = BLTN_SCHED_SETSCHEDULER;
    self->sched.yield            = BLTN_SCHED_YIELD;
    return 0;
}