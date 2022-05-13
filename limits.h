#pragma once

int include_limits_h(Lib *self, FILE *file) {

    __basedef(limits_h, "<limits.h>")

    __dentr(enums, Enum[])
        __predef("_POSIX")
            EDEF_(_POSIX,AIO_LISTIO_MAX)
            EDEF_(_POSIX,AIO_MAX)
            EDEF_(_POSIX,ARG_MAX)
            EDEF_(_POSIX,CHILD_MAX)
            EDEF_(_POSIX,CLOCKRES_MIN)
            EDEF_(_POSIX,DELAYTIMER_MAX)
            EDEF_(_POSIX,HOST_NAME_MAX)
            EDEF_(_POSIX,LINK_MAX)
            EDEF_(_POSIX,LOGIN_NAME_MAX)
            EDEF_(_POSIX,MAX_CANON)
            EDEF_(_POSIX,MAX_INPUT)
            EDEF_(_POSIX,MQ_OPEN_MAX)
            EDEF_(_POSIX,MQ_PRIO_MAX)
            EDEF_(_POSIX,NAME_MAX)
            EDEF_(_POSIX,NGROUPS_MAX)
            EDEF_(_POSIX,OPEN_MAX)
            EDEF_(_POSIX,PATH_MAX)
            EDEF_(_POSIX,PIPE_BUF)
            EDEF_(_POSIX,RE_DUP_MAX)
            EDEF_(_POSIX,RTSIG_MAX)
            EDEF_(_POSIX,SEM_NSEMS_MAX)
            EDEF_(_POSIX,SEM_VALUE_MAX)
            EDEF_(_POSIX,SIGQUEUE_MAX)
            EDEF_(_POSIX,SSIZE_MAX)
            EDEF_(_POSIX,STREAM_MAX)
            EDEF_(_POSIX,SS_REPL_MAX)
            EDEF_(_POSIX,SYMLINK_MAX)
            EDEF_(_POSIX,SYMLOOP_MAX)
            EDEF_(_POSIX,THREAD_DESTRUCTOR_ITERATIONS)
            EDEF_(_POSIX,THREAD_KEYS_MAX)
            EDEF_(_POSIX,THREAD_THREADS_MAX)
            EDEF_(_POSIX,TIMER_MAX)
            EDEF_(_POSIX,TRACE_EVENT_NAME_MAX)
            EDEF_(_POSIX,TRACE_NAME_MAX)
            EDEF_(_POSIX,TRACE_SYS_MAX)
            EDEF_(_POSIX,TRACE_USER_EVENT_MAX)
            EDEF_(_POSIX,TTY_NAME_MAX)
            EDEF_(_POSIX,TZNAME_MAX)
        __preend("_POSIX")


        __predef("_POSIX2")
            EDEF_(_POSIX2,BC_BASE_MAX)
            EDEF_(_POSIX2,BC_DIM_MAX)
            EDEF_(_POSIX2,BC_SCALE_MAX)
            EDEF_(_POSIX2,BC_STRING_MAX)
            EDEF_(_POSIX2,CHARCLASS_NAME_MAX)
            EDEF_(_POSIX2,COLL_WEIGHTS_MAX)
            EDEF_(_POSIX2,EXPR_NEST_MAX)
            EDEF_(_POSIX2,LINE_MAX)
            EDEF_(_POSIX2,RE_DUP_MAX)
        __preend("_POSIX2")


        __predef("_XOPEN")
            EDEF_(_XOPEN,IOV_MAX)
            EDEF_(_XOPEN,NAME_MAX)
            EDEF_(_XOPEN,PATH_MAX)
        __preend("_XOPEN")

        __predef("")
            EREF(CHAR_BIT)
            EREF(WORD_BIT)
            EREF(LONG_BIT)
            EREF(CHAR_MIN)
            EREF(CHAR_MAX)
            EREF(INT_MIN)
            EREF(INT_MAX)
            EREF(LLONG_MIN)
            EREF(LLONG_MAX)
            EREF(LONG_MIN)
            EREF(LONG_MAX)
            EREF(MB_LEN_MAX)
            EREF(SCHAR_MIN)
            EREF(SCHAR_MAX)
            EREF(SHRT_MIN)
            EREF(SHRT_MAX)
            
            EREF(SSIZE_MAX)

            EREF(UCHAR_MAX)
            EREF(USHRT_MAX)
            EREF(UINT_MAX)
            EREF(ULLONG_MAX)
            EREF(ULONG_MAX)
            
            EREF(NL_ARGMAX)
            EREF(NL_SETMAX)
            EREF(NL_MSGMAX)
            EREF(NL_TEXTMAX)

#       ifdef _XOPEN_UNIX
            EREF(NL_LANGMAX)
            EREF(NZERO)
#       endif
            
        __preend("")

        __predef("")
#       if _POSIX_ASYNCHRONOUS_IO > 0
#           ifdef AIO_LISTIO_MAX
            EREF( AIO_LISTIO_MAX)
#           endif
#           ifdef AIO_MAX
            EREF( AIO_MAX)
#           endif
#           ifdef AIO_PRIO_DELTA_MAX
            EREF( AIO_PRIO_DELTA_MAX)
#           endif
#       endif

#           ifdef ARG_MAX
            EREF( ARG_MAX)
#           endif

#           ifdef ATEXIT_MAX
            EREF( ATEXIT_MAX)
#           endif

#           ifdef BC_BASE_MAX
            EREF( BC_BASE_MAX)
#           endif

#           ifdef BC_DIM_MAX
            EREF( BC_DIM_MAX)
#           endif

#           ifdef BC_SCALE_MAX
            EREF( BC_SCALE_MAX)
#           endif

#           ifdef BC_STRING_MAX
            EREF( BC_STRING_MAX)
#           endif

#           ifdef CHARCLASS_NAME_MAX
            EREF( CHARCLASS_NAME_MAX)
#           endif

#           ifdef CHILD_MAX
            EREF( CHILD_MAX)
#           endif

#           ifdef CLOCKRES_MIN
            EREF( CLOCKRES_MIN)
#           endif

#           ifdef COLL_WEIGHTS_MAX
            EREF( COLL_WEIGHTS_MAX)
#           endif

#           ifdef DELAYTIMER_MAX
            EREF( DELAYTIMER_MAX)
#           endif

#           ifdef EXPR_MAX
            EREF( EXPR_MAX)
#           endif

#           ifdef HOST_NAME_MAX
            EREF( HOST_NAME_MAX)
#           endif

#       ifdef _XOPEN_UNIX
#           ifdef IOV_MAX
            EREF( IOV_MAX)
#           endif
#       endif

#           ifdef LINE_MAX
            EREF( LINE_MAX)
#           endif

#           ifdef LINK_MAX
            EREF( LINK_MAX)
#           endif

#           ifdef LOGIN_NAME_MAX
            EREF( LOGIN_NAME_MAX)
#           endif

#           ifdef MAX_CANON
            EREF( MAX_CANON)
#           endif

#           ifdef MAX_INPUT
            EREF( MAX_INPUT)
#           endif

#       if _POSIX_MESSAGE_PASSING > 0
#           ifdef MQ_OPEN_MAX
            EREF( MQ_OPEN_MAX)
#           endif
#           ifdef MQ_PRIO_MAX
            EREF( MQ_PRIO_MAX)
#           endif
#       endif

#           ifdef NAME_MAX
            EREF( NAME_MAX)
#           endif

#           ifdef NGROUPS_MAX
            EREF( NGROUPS_MAX)
#           endif

#           ifdef OPEN_MAX
            EREF( OPEN_MAX)
#           endif

#           ifdef PAGESIZE
            EREF( PAGESIZE)
#           endif

#       ifdef _XOPEN_UNIX
#           ifdef PAGE_SIZE
            EREF( PAGE_SIZE)
#           endif
#       endif

#           ifdef PATH_MAX
            EREF( PATH_MAX)
#           endif

#           ifdef PIPE_BUF
            EREF( PIPE_BUF)
#           endif

#       if _POSIX_ADVISORY_INFO > 0
#           ifdef POSIX_ALLOC_SIZE_MIN
            EREF( POSIX_ALLOC_SIZE_MIN)
#           endif

#           ifdef POSIX_REC_INCR_XFER_SIZE
            EREF( POSIX_REC_INCR_XFER_SIZE)
#           endif

#           ifdef POSIX_REC_MAX_XFER_SIZE
            EREF( POSIX_REC_MAX_XFER_SIZE)
#           endif

#           ifdef POSIX_REC_MIN_XFER_SIZE
            EREF( POSIX_REC_MIN_XFER_SIZE)
#           endif

#           ifdef POSIX_REC_XFER_ALIGN
            EREF( POSIX_REC_XFER_ALIGN)
#           endif
#       endif

#       if _POSIX_REGEX > 0
#           ifdef RE_DUP_MAX
            EREF( RE_DUP_MAX)
#           endif
#       endif

#           ifdef RTSIG_MAX
            EREF( RTSIG_MAX)
#           endif

#       if _POSIX_SEMAPHORES > 0
#           ifdef SEM_NSEMS_MAX
            EREF( SEM_NSEMS_MAX)
#           endif
#           ifdef SEM_VALUE_MAX
            EREF( SEM_VALUE_MAX)
#           endif
#       endif // _POSIX_SEMAPHORES > 0

#           ifdef SIGQUEUE_MAX
            EREF( SIGQUEUE_MAX)
#           endif
#           ifdef SSIZE_MAX
            EREF( SSIZE_MAX)
#           endif
#           ifdef STREAM_MAX
            EREF( STREAM_MAX)
#           endif
#           ifdef SS_REPL_MAX
            EREF( SS_REPL_MAX)
#           endif
#           ifdef SYMLINK_MAX
            EREF( SYMLINK_MAX)
#           endif
#           ifdef SYMLOOP_MAX
            EREF( SYMLOOP_MAX)
#           endif
#           ifdef THREAD_DESTRUCTOR_ITERATIONS
            EREF( THREAD_DESTRUCTOR_ITERATIONS)
#           endif
#           ifdef THREAD_KEYS_MAX
            EREF( THREAD_KEYS_MAX)
#           endif
#           ifdef THREAD_THREADS_MAX
            EREF( THREAD_THREADS_MAX)
#           endif
#           ifdef TIMER_MAX
            EREF( TIMER_MAX)
#           endif
#           ifdef TTY_NAME_MAX
            EREF(TTY_NAME_MAX)
#           endif
#           ifdef TZNAME_MAX
            EREF(TZNAME_MAX)
#           endif
        __preend("")


    __dexit(enums)

    __baseret(limits_h)
}
