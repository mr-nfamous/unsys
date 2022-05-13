#pragma once

int include_sys_times_h(Lib *self, FILE *file) {
    __basedef(sys_times_h, "<sys/times.h>")
    __dentr(structs, Struct[])
        __memdef(tms_s)
        __member(tms_s, tms_utime, "{clock_t}")
        __member(tms_s, tms_stime, "{clock_t}")
        __member(tms_s, tms_cutime, "{clock_t}")
        __member(tms_s, tms_cstime, "{clock_t}")
        __enddef(tms_s)
    __dexit(structs)
    __baseret(sys_times_h)
}

int test_sys_times_h(Lib *self, FILE *file) {
#   ifndef BLTN_TIMES
#   define BLTN_TIMES times 
#   endif
    self->times = BLTN_TIMES;
    return 0;
}