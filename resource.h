
#pragma once

int include_sys_resource_h(Lib*self,FILE*file) {
#   ifndef BLTN_GETPRIORITY
#   define BLTN_GETPRIORITY getpriority
#   endif
#   ifndef BLTN_SETPRIORITY
#   define BLTN_SETPRIORITY setpriority
#   endif
#   ifndef BLTN_GETRLIMIT
#   define BLTN_GETRLIMIT getrlimit
#   endif
#   ifndef BLTN_GETRUSAGE
#   define BLTN_GETRUSAGE getrusage
#   endif
#   ifndef BLTN_SETRLIMIT
#   define BLTN_SETRLIMIT setrlimit
#   endif
#   ifndef BLTN_PRLIMIT
#       ifdef _GNU_SOURCE
#           define BLTN_PRLIMIT prlimit
#       else
#           define BLTN_PRLIMIT 0
#       endif
#   endif
    self->getpriority=BLTN_GETPRIORITY;
    self->setpriority=BLTN_SETPRIORITY;
    self->getrlimit=BLTN_GETRLIMIT;
    self->getrusage=BLTN_GETRUSAGE;
    self->setrlimit=BLTN_SETRLIMIT;
    self->prlimit=BLTN_PRLIMIT;

    __basedef(sys_resource_h, "<sys/resource.h>")
    
        __dentr(enums, Enum[])
 
            __predef("RUSAGE")
                EDEF_(RUSAGE, SELF)
                EDEF_(RUSAGE, CHILDREN)
            __preend("RUSAGE", .sort=C__VSORT)
 
            __predef("RLIMIT")
                EDEF_(RLIMIT,CORE)
                EDEF_(RLIMIT,CPU)
                EDEF_(RLIMIT,DATA)
                EDEF_(RLIMIT,FSIZE)
                EDEF_(RLIMIT,NOFILE)
                EDEF_(RLIMIT,STACK)
                EDEF_(RLIMIT,AS)
            __preend("RLIMIT", .sort=C__VSORT)

            __predef("PRIO")
                EDEF_(PRIO, PROCESS)
                EDEF_(PRIO, PGRP)
                EDEF_(PRIO, USER) 
            #ifdef PRIO_MIN
                EDEF_(PRIO, MIN) 
            #endif 
            #ifdef PRIO_MAX
                EDEF_(PRIO, MAX) 
            #endif 
            __preend("PRIO", .fmt="x", .sort=C__VSORT)

        __dexit(enums)

        __dentr(structs, Struct[])
            __memdef(rlimit_s)
            __member(rlimit_s, rlim_cur, "rlim_t")
            __member(rlimit_s, rlim_max, "rlim_t")
            __enddef(rlimit_s)
 
            __memdef(rusage_s)
            BLTN_STRUCT_RUSAGE()
            __enddef(rusage_s)
 
        __dexit(structs)

    __baseret(sys_resource_h)
    
}