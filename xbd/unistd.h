
#pragma once

/*
    P7:

        Option changes:
            ctermid():    [XSI] -> [CX]
            fchdir():     [XSI] -> [CX] 
            getsid():     [XSI] -> [CX]
            lchown():     [XSI] -> [CX]
            pread():      [XSI] -> [CX]
            pwrite():     [XSI] -> [CX]

        Removals:
            getwd() 
            ctermid() (moved to <stdio.h>)
    P6:

        Option changes:
            getwd():      [XSI] -> [XSI OB]

        Removals:
            chroot()
            ualarm()
            usleep()
            
*/
int _include_unistd_h(struct c_ffi *self) {

#   if (_XOPEN_VERSION >= 1) &&  (_XOPEN_VERSION <= 600)
#       ifndef BLTN_CTERMID
#       define BLTN_CTERMID ctermid
#       endif
#   endif// (_XOPEN_VERSION == 600)

#   ifndef BLTN_ACCESS
#   define BLTN_ACCESS access
#   endif

#   ifndef BLTN_CHDIR
#   define BLTN_CHDIR chdir
#   endif

#   ifndef BLTN_CHOWN
#   define BLTN_CHOWN chown
#   endif

#   ifndef BLTN_CLOSE
#   define BLTN_CLOSE close
#   endif

#   ifndef BLTN_DUP
#   define BLTN_DUP dup
#   endif

#   ifndef BLTN_DUP2
#   define BLTN_DUP2 dup2
#   endif

#   ifndef BLTN_EXECL
#   define BLTN_EXECL execl
#   endif

#   ifndef BLTN_EXECLE
#   define BLTN_EXECLE execle
#   endif

#   ifndef BLTN_EXECLP
#   define BLTN_EXECLP execlp
#   endif

#   ifndef BLTN_EXECV
#   define BLTN_EXECV execv
#   endif

#   ifndef BLTN_EXECVE
#   define BLTN_EXECVE execve
#   endif

#   ifndef BLTN_EXECVP
#   define BLTN_EXECVP execvp
#   endif

#   ifndef BLTN_FACCESSAT
#   define BLTN_FACCESSAT faccessat
#   endif

#   ifndef BLTN_FCHDIR
#   define BLTN_FCHDIR fchdir
#   endif

#   ifndef BLTN_FCHOWN
#   define BLTN_FCHOWN fchown
#   endif

#   ifndef BLTN_FCHOWNAT
#   define BLTN_FCHOWNAT fchownat
#   endif

#   ifndef BLTN_FEXECVE
#   define BLTN_FEXECVE fexecve
#   endif

#   ifndef BLTN_FORK
#   define BLTN_FORK fork
#   endif

#   if (_POSIX_FSYNC > 0)
#       ifndef BLTN_FSYNC
#       define BLTN_FSYNC fsync
#       endif
        self->fsync         = BLTN_FSYNC;
#   endif

#   if (_POSIX_SYNCHRONOUS_IO > 0)
#       ifndef BLTN_FDATASYNC
#       define BLTN_FDATASYNC fdatasync
#       endif
        self->fdatasync;
#   endif

#   ifndef BLTN_FTRUNCATE
#   define BLTN_FTRUNCATE ftruncate
#   endif

#   ifndef BLTN_GETGROUPS
#   define BLTN_GETGROUPS getgroups
#   endif

#   ifndef BLTN_GETHOSTNAME
#   define BLTN_GETHOSTNAME gethostname
#   endif

#   ifndef BLTN_GETLOGIN_R
#   define BLTN_GETLOGIN_R getlogin_r
#   endif

#   ifndef BLTN_GETOPT
#   define BLTN_GETOPT getopt
#   endif

#   ifndef BLTN_ISATTY
#   define BLTN_ISATTY isatty
#   endif

#   ifndef BLTN_LCHOWN
#   define BLTN_LCHOWN lchown
#   endif

#   ifndef BLTN_LINK
#   define BLTN_LINK link
#   endif

#   ifndef BLTN_LINKAT
#   define BLTN_LINKAT linkat
#   endif

#   ifndef BLTN_PAUSE
#   define BLTN_PAUSE pause
#   endif

#   ifndef BLTN_PIPE
#   define BLTN_PIPE pipe
#   endif

#   ifndef BLTN_RMDIR
#   define BLTN_RMDIR rmdir
#   endif

#   ifndef BLTN_SETEGID
#   define BLTN_SETEGID setegid
#   endif

#   ifndef BLTN_SETEUID
#   define BLTN_SETEUID seteuid
#   endif

#   ifndef BLTN_SETGID
#   define BLTN_SETGID setgid
#   endif

#   ifndef BLTN_SETPGID
#   define BLTN_SETPGID setpgid
#   endif

#   ifndef BLTN_SETUID
#   define BLTN_SETUID setuid
#   endif

#   ifndef BLTN_SYMLINK
#   define BLTN_SYMLINK symlink
#   endif

#   ifndef BLTN_SYMLINKAT
#   define BLTN_SYMLINKAT symlinkat
#   endif

#   ifndef BLTN_TCSETPGRP
#   define BLTN_TCSETPGRP tcsetpgrp
#   endif

#   ifndef BLTN_TRUNCATE
#   define BLTN_TRUNCATE truncate
#   endif

#   ifndef BLTN_TTYNAME_R
#   define BLTN_TTYNAME_R ttyname_r
#   endif

#   ifndef BLTN_UNLINK
#   define BLTN_UNLINK unlink
#   endif

#   ifndef BLTN_UNLINKAT
#   define BLTN_UNLINKAT unlinkat
#   endif

#   ifndef BLTN_CONFSTR
#   define BLTN_CONFSTR confstr
#   endif

#   ifndef BLTN_FPATHCONF
#   define BLTN_FPATHCONF fpathconf
#   endif

#   ifndef BLTN_PATHCONF
#   define BLTN_PATHCONF pathconf
#   endif

#   ifndef BLTN_SYSCONF
#   define BLTN_SYSCONF sysconf
#   endif

#   ifndef BLTN_GETEGID
#   define BLTN_GETEGID getegid
#   endif

#   ifndef BLTN_GETGID
#   define BLTN_GETGID getgid
#   endif

#   ifndef BLTN_GETEUID
#   define BLTN_GETEUID geteuid
#   endif

#   ifndef BLTN_GETUID
#   define BLTN_GETUID getuid
#   endif

#   ifndef BLTN_GETPGID
#   define BLTN_GETPGID getpgid
#   endif

#   ifndef BLTN_GETSID
#   define BLTN_GETSID getsid
#   endif

#   ifndef BLTN_GETPGRP
#   define BLTN_GETPGRP getpgrp
#   endif

#   ifndef BLTN_GETPID
#   define BLTN_GETPID getpid
#   endif

#   ifndef BLTN_GETPPID
#   define BLTN_GETPPID getppid
#   endif

#   ifndef BLTN_SETSID
#   define BLTN_SETSID setsid
#   endif

#   ifndef BLTN_TCGETPGRP
#   define BLTN_TCGETPGRP tcgetpgrp
#   endif

#   ifndef BLTN_LSEEK
#   define BLTN_LSEEK lseek
#   endif

#   ifndef BLTN_PREAD
#   define BLTN_PREAD pread
#   endif

#   ifndef BLTN_PWRITE
#   define BLTN_PWRITE pwrite
#   endif

#   ifndef BLTN_READ
#   define BLTN_READ read
#   endif

#   ifndef BLTN_WRITE
#   define BLTN_WRITE write
#   endif

#   ifndef BLTN_READLINK
#   define BLTN_READLINK readlink
#   endif

#   ifndef BLTN_READLINKAT
#   define BLTN_READLINKAT readlinkat
#   endif

#   ifndef BLTN_ALARM
#   define BLTN_ALARM alarm
#   endif

#   ifndef BLTN_SLEEP
#   define BLTN_SLEEP sleep
#   endif

#   ifndef BLTN_GETCWD
#   define BLTN_GETCWD getcwd
#   endif

#   ifndef BLTN_GETLOGIN
#   define BLTN_GETLOGIN getlogin
#   endif

#   ifndef BLTN_TTYNAME
#   define BLTN_TTYNAME ttyname
#   endif

#   ifndef BLTN__EXIT
#   define BLTN__EXIT _exit
#   endif

    self->access        = BLTN_ACCESS;
    self->chdir         = BLTN_CHDIR;
    self->chown         = BLTN_CHOWN;

    self->close         = BLTN_CLOSE;
    self->dup           = BLTN_DUP;
    self->dup2          = BLTN_DUP2;
    self->execl         = BLTN_EXECL;
    self->execle        = BLTN_EXECLE;
    self->execlp        = BLTN_EXECLP;
    self->execv         = BLTN_EXECV;
    self->execve        = BLTN_EXECVE;
    self->execvp        = BLTN_EXECVP;
    self->faccessat     = BLTN_FACCESSAT;
    self->fchdir        = BLTN_FCHDIR;
    self->fchown        = BLTN_FCHOWN;
    self->fchownat      = BLTN_FCHOWNAT;
    self->fexecve       = BLTN_FEXECVE;

    self->ftruncate     = BLTN_FTRUNCATE;
    self->getgroups     = BLTN_GETGROUPS;
    self->gethostname   = BLTN_GETHOSTNAME;
    self->getlogin_r    = BLTN_GETLOGIN_R;
    self->getopt        = BLTN_GETOPT;
    self->isatty        = BLTN_ISATTY;
    self->lchown        = BLTN_LCHOWN;
    self->link          = BLTN_LINK;
    self->linkat        = BLTN_LINKAT;
    self->pause         = BLTN_PAUSE;
    self->pipe          = BLTN_PIPE;
    self->rmdir         = BLTN_RMDIR;
    self->setegid       = BLTN_SETEGID;
    self->seteuid       = BLTN_SETEUID;
    self->setgid        = BLTN_SETGID;
    self->setpgid       = BLTN_SETPGID;
    self->setuid        = BLTN_SETUID;
    self->symlink       = BLTN_SYMLINK;
    self->symlinkat     = BLTN_SYMLINKAT;
    self->tcsetpgrp     = BLTN_TCSETPGRP;
    self->truncate      = BLTN_TRUNCATE;
    self->ttyname_r     = BLTN_TTYNAME_R;
    self->unlink        = BLTN_UNLINK;
    self->unlinkat      = BLTN_UNLINKAT;
    self->confstr       = BLTN_CONFSTR;
    self->fpathconf     = BLTN_FPATHCONF;
    self->pathconf      = BLTN_PATHCONF;
    self->sysconf       = BLTN_SYSCONF;
    self->getegid       = BLTN_GETEGID;
    self->getgid        = BLTN_GETGID;
    self->geteuid       = BLTN_GETEUID;
    self->getuid        = BLTN_GETUID;
    self->getpgid       = BLTN_GETPGID;
    self->getsid        = BLTN_GETSID;
    self->fork          = BLTN_FORK;
    self->getpgrp       = BLTN_GETPGRP;
    self->getpid        = BLTN_GETPID;
    self->getppid       = BLTN_GETPPID;
    self->setsid        = BLTN_SETSID;
    self->tcgetpgrp     = BLTN_TCGETPGRP;
    self->lseek         = BLTN_LSEEK;
    self->pread         = BLTN_PREAD;
    self->pwrite        = BLTN_PWRITE;
    self->read          = BLTN_READ;
    self->write         = BLTN_WRITE;
    self->readlink      = BLTN_READLINK;
    self->readlinkat    = BLTN_READLINKAT;
    self->alarm         = BLTN_ALARM;
    self->sleep         = BLTN_SLEEP;
    self->getcwd        = BLTN_GETCWD;
    self->getlogin      = BLTN_GETLOGIN;
    self->ttyname       = BLTN_TTYNAME;
    self->_exit         = BLTN__EXIT;

#   ifdef _XOPEN_UNIX

#       ifndef BLTN_LOCKF
#       define BLTN_LOCKF lockf
#       endif
        self->lockf         = BLTN_LOCKF;

#       ifndef BLTN_NICE
#       define BLTN_NICE nice
#       endif
        self->nice          = BLTN_NICE;

#       ifndef BLTN_SETPGRP
#       define BLTN_SETPGRP 0
#       endif
        self->setpgrp       = BLTN_SETPGRP;

#       ifndef BLTN_SETREGID
#       define BLTN_SETREGID setregid
#       endif
        self->setregid      = BLTN_SETREGID;

#       ifndef BLTN_SETREUID
#       define BLTN_SETREUID setreuid
#       endif
        self->setreuid      = BLTN_SETREUID;

#       ifndef BLTN_GETHOSTID
#       define BLTN_GETHOSTID gethostid
#       endif
        self->gethostid     = BLTN_GETHOSTID;

#       ifndef BLTN_CRYPT
#       define BLTN_CRYPT crypt
#       endif
        self->crypt         = BLTN_CRYPT;

#       ifndef BLTN_ENCRYPT
#       define BLTN_ENCRYPT encrypt
#       endif
        self->encrypt       = BLTN_ENCRYPT;

#       ifndef BLTN_SWAB
#       define BLTN_SWAB swab
#       endif
        self->swab          = BLTN_SWAB;

#       ifndef BLTN_SYNC
#       define BLTN_SYNC sync
#       endif
        self->sync          = BLTN_SYNC;

#   endif // defined(_XOPEN_UNIX)

#   ifdef BLTN_CHROOT
    self->chroot        = BLTN_CHROOT;
#   endif

#   ifdef BLTN_DUP3
    self->GNU.dup3     = BLTN_DUP3;
#   endif

#   ifdef BLTN_UALARM
    self->ualarm       = BLTN_UALARM;
#   endif

#   ifdef BLTN_USLEEP
    self->usleep       = BLTN_USLEEP;
#   endif

#   ifdef BLTN_VFORK
    self->vfork = BLTN_VFORK;
#   endif

    return 0;
}
int include_unistd_h(struct c_ffi *self, FILE *file) {

    __basedef(unistd_h, "<unistd.h>")
    
        __dentr(enums, Enum[])

        __predef("")
            EREF(F_OK)
            EREF(R_OK)
            EREF(W_OK)
            EREF(X_OK)
        __preend("")

        __predef("F")
            EDEF_(F,LOCK)
            EDEF_(F,TEST)
            EDEF_(F,TLOCK)
            EDEF_(F,ULOCK)
        __preend("F")

        __predef("")
            EREF(STDIN_FILENO)
            EREF(STDOUT_FILENO)
            EREF(STDERR_FILENO)
        __preend("")

        __predef("SEEK")
            EDEF_(SEEK, SET)
            EDEF_(SEEK, CUR)
            EDEF_(SEEK, END)
        __preend("SEEK", .fmt="x", .sort=C__VSORT)

        __predef("_POSIX")
            EDEF_(_POSIX,ADVISORY_INFO)
            EDEF_(_POSIX,ASYNCHRONOUS_IO)
            EDEF_(_POSIX,BARRIERS)
            EDEF_(_POSIX,CHOWN_RESTRICTED)
            EDEF_(_POSIX,CLOCK_SELECTION)
            EDEF_(_POSIX,CPUTIME)
            EDEF_(_POSIX,FSYNC)
            EDEF_(_POSIX,IPV6)
            EDEF_(_POSIX,JOB_CONTROL)
            EDEF_(_POSIX,MAPPED_FILES)
            EDEF_(_POSIX,MEMLOCK)
            EDEF_(_POSIX,MEMLOCK_RANGE)
            EDEF_(_POSIX,MEMORY_PROTECTION)
            EDEF_(_POSIX,MESSAGE_PASSING)
            EDEF_(_POSIX,MONOTONIC_CLOCK)
            EDEF_(_POSIX,NO_TRUNC)
            EDEF_(_POSIX,PRIORITIZED_IO)
            EDEF_(_POSIX,PRIORITY_SCHEDULING)
            EDEF_(_POSIX,RAW_SOCKETS)
            EDEF_(_POSIX,READER_WRITER_LOCKS)
            EDEF_(_POSIX,REALTIME_SIGNALS)
            EDEF_(_POSIX,REGEXP)
            EDEF_(_POSIX,SAVED_IDS)
            EDEF_(_POSIX,SEMAPHORES)
            EDEF_(_POSIX,SHARED_MEMORY_OBJECTS)
            EDEF_(_POSIX,SHELL)
            EDEF_(_POSIX,SPAWN)
            EDEF_(_POSIX,SPIN_LOCKS)
            EDEF_(_POSIX,SPORADIC_SERVER)
            EDEF_(_POSIX,SYNCHRONIZED_IO)
            EDEF_(_POSIX,THREAD_ATTR_STACKADDR)
            EDEF_(_POSIX,THREAD_ATTR_STACKSIZE)
            EDEF_(_POSIX,THREAD_CPUTIME)
            EDEF_(_POSIX,THREAD_PRIO_INHERIT)
            EDEF_(_POSIX,THREAD_PRIO_PROTECT)
            EDEF_(_POSIX,THREAD_PRIORITY_SCHEDULING)
            EDEF_(_POSIX,THREAD_PROCESS_SHARED)
            EDEF_(_POSIX,THREAD_ROBUST_PRIO_INHERIT)
            EDEF_(_POSIX,THREAD_ROBUST_PRIO_PROTECT)
            EDEF_(_POSIX,THREAD_SAFE_FUNCTIONS)
            EDEF_(_POSIX,THREAD_SPORADIC_SERVER)
            EDEF_(_POSIX,THREADS)
            EDEF_(_POSIX,TIMEOUTS)
            EDEF_(_POSIX,TIMERS)
            #ifdef _POSIX_TIMESTAMP_RESOLUTION
            EDEF_(_POSIX,TIMESTAMP_RESOLUTION)
            #endif
            EDEF_(_POSIX,TRACE)
            EDEF_(_POSIX,TRACE_EVENT_FILTER)
            EDEF_(_POSIX,TRACE_INHERIT)
            EDEF_(_POSIX,TRACE_LOG)
            EDEF_(_POSIX,TYPED_MEMORY_OBJECTS)
            EDEF_(_POSIX,V7_ILP32_OFF32)
            EDEF_(_POSIX,V7_ILP32_OFFBIG)
            EDEF_(_POSIX,V7_LP64_OFF64)
            EDEF_(_POSIX,V7_LPBIG_OFFBIG)
        __preend("_POSIX")


        __predef("_POSIX2")
        #ifdef _POSIX2_SYMLINKS
            EDEF_(_POSIX2,SYMLINKS)
        #endif
            EDEF_(_POSIX2,C_BIND)
            EDEF_(_POSIX2,C_DEV)
            EDEF_(_POSIX2,CHAR_TERM)
            EDEF_(_POSIX2,LOCALEDEF)
            EDEF_(_POSIX2,FORT_DEV)
            EDEF_(_POSIX2,FORT_RUN)
            EDEF_(_POSIX2,UPE)
            EDEF_(_POSIX2,SW_DEV)
        __preend("_POSIX2")


        __predef("_XOPEN")
#           ifdef _XOPEN_REALTIME
            EDEF_(_XOPEN,REALTIME)
#           endif
#           ifdef _XOPEN_REALTIME_THREADS
            EDEF_(_XOPEN,REALTIME_THREADS)
#           endif
#           ifdef _XOPEN_VERSION
            EDEF_(_XOPEN,VERSION)
#           endif
#           ifdef _XOPEN_CRYPT
            EDEF_(_XOPEN,CRYPT)
#           endif
#           ifdef _XOPEN_ENH_I18N
            EDEF_(_XOPEN,ENH_I18N)
#           endif
#           ifdef _XOPEN_STREAMS
            EDEF_(_XOPEN,STREAMS)
#           endif
#           ifdef _XOPEN_SHM
            EDEF_(_XOPEN,SHM)
#           endif
#           ifdef _XOPEN_UNIX
            EDEF_(_XOPEN,UNIX)
#           endif
#           ifdef _XOPEN_UUCP
            EDEF_(_XOPEN,UUCP)
#           endif
        __preend("_XOPEN")


        __predef("_PC")
            EDEF_(_PC,2_SYMLINKS)
            EDEF_(_PC,ALLOC_SIZE_MIN)
            EDEF_(_PC,ASYNC_IO)
            EDEF_(_PC,CHOWN_RESTRICTED)
            EDEF_(_PC,FILESIZEBITS)
            EDEF_(_PC,LINK_MAX)
            EDEF_(_PC,MAX_CANON)
            EDEF_(_PC,MAX_INPUT)
            EDEF_(_PC,NAME_MAX)
            EDEF_(_PC,NO_TRUNC)
            EDEF_(_PC,PATH_MAX)
            EDEF_(_PC,PIPE_BUF)
            EDEF_(_PC,PRIO_IO)
            EDEF_(_PC,REC_INCR_XFER_SIZE)
            EDEF_(_PC,REC_MAX_XFER_SIZE)
            EDEF_(_PC,REC_MIN_XFER_SIZE)
            EDEF_(_PC,REC_XFER_ALIGN)
            EDEF_(_PC,SYMLINK_MAX)
            EDEF_(_PC,SYNC_IO)
            EDEF_(_PC,VDISABLE)
        #ifdef _PC_TIMESTAMP_RESOLUTION
            EDEF_(_PC,TIMESTAMP_RESOLUTION)
        #endif
        __preend("_PC")

        __predef("_SC_2")
            EDEF_(_SC_2,C_BIND)
            EDEF_(_SC_2,C_DEV)
            EDEF_(_SC_2,CHAR_TERM)
            EDEF_(_SC_2,FORT_DEV)
            EDEF_(_SC_2,FORT_RUN)
            EDEF_(_SC_2,LOCALEDEF)
            EDEF_(_SC_2,SW_DEV)
            EDEF_(_SC_2,UPE)
        __preend("_SC_2")

        __predef("_SC")
            EDEF_(_SC,VERSION)
            EDEF_(_SC,ADVISORY_INFO)
            EDEF_(_SC,AIO_LISTIO_MAX)
            EDEF_(_SC,AIO_MAX)
            EDEF_(_SC,AIO_PRIO_DELTA_MAX)
            EDEF_(_SC,ARG_MAX)
            EDEF_(_SC,ASYNCHRONOUS_IO)
            EDEF_(_SC,ATEXIT_MAX)
            EDEF_(_SC,BARRIERS)
            EDEF_(_SC,BC_BASE_MAX)
            EDEF_(_SC,BC_DIM_MAX)
            EDEF_(_SC,BC_SCALE_MAX)
            EDEF_(_SC,BC_STRING_MAX)
            EDEF_(_SC,CHILD_MAX)
            EDEF_(_SC,CLK_TCK)
            EDEF_(_SC,CLOCK_SELECTION)
            EDEF_(_SC,COLL_WEIGHTS_MAX)
            EDEF_(_SC,CPUTIME)
            EDEF_(_SC,DELAYTIMER_MAX)
            EDEF_(_SC,EXPR_NEST_MAX)
            EDEF_(_SC,FSYNC)
            EDEF_(_SC,GETGR_R_SIZE_MAX)
            EDEF_(_SC,GETPW_R_SIZE_MAX)
            EDEF_(_SC,HOST_NAME_MAX)
            EDEF_(_SC,IOV_MAX)
            EDEF_(_SC,IPV6)
            EDEF_(_SC,JOB_CONTROL)
            EDEF_(_SC,LINE_MAX)
            EDEF_(_SC,LOGIN_NAME_MAX)
            EDEF_(_SC,MAPPED_FILES)
            EDEF_(_SC,MEMLOCK)
            EDEF_(_SC,MEMLOCK_RANGE)
            EDEF_(_SC,MEMORY_PROTECTION)
            EDEF_(_SC,MESSAGE_PASSING)
            EDEF_(_SC,MONOTONIC_CLOCK)
            EDEF_(_SC,MQ_OPEN_MAX)
            EDEF_(_SC,MQ_PRIO_MAX)
            EDEF_(_SC,NGROUPS_MAX)
            EDEF_(_SC,OPEN_MAX)
            EDEF_(_SC,PAGE_SIZE)
            EDEF_(_SC,PAGESIZE)
            EDEF_(_SC,PRIORITIZED_IO)
            EDEF_(_SC,PRIORITY_SCHEDULING)
            EDEF_(_SC,RAW_SOCKETS)
            EDEF_(_SC,RE_DUP_MAX)
            EDEF_(_SC,READER_WRITER_LOCKS)
            EDEF_(_SC,REALTIME_SIGNALS)
            EDEF_(_SC,REGEXP)
            EDEF_(_SC,RTSIG_MAX)
            EDEF_(_SC,SAVED_IDS)
            EDEF_(_SC,SEM_NSEMS_MAX)
            EDEF_(_SC,SEM_VALUE_MAX)
            EDEF_(_SC,SEMAPHORES)
            EDEF_(_SC,SHARED_MEMORY_OBJECTS)
            EDEF_(_SC,SHELL)
            EDEF_(_SC,SIGQUEUE_MAX)
            EDEF_(_SC,SPAWN)
            EDEF_(_SC,SPIN_LOCKS)
            EDEF_(_SC,SPORADIC_SERVER)
            EDEF_(_SC,SS_REPL_MAX)
            EDEF_(_SC,STREAM_MAX)
            EDEF_(_SC,SYMLOOP_MAX)
            EDEF_(_SC,SYNCHRONIZED_IO)
            EDEF_(_SC,THREAD_ATTR_STACKADDR)
            EDEF_(_SC,THREAD_ATTR_STACKSIZE)
            EDEF_(_SC,THREAD_CPUTIME)
            EDEF_(_SC,THREAD_DESTRUCTOR_ITERATIONS)
            EDEF_(_SC,THREAD_KEYS_MAX)
            EDEF_(_SC,THREAD_PRIO_INHERIT)
            EDEF_(_SC,THREAD_PRIO_PROTECT)
            EDEF_(_SC,THREAD_PRIORITY_SCHEDULING)
            EDEF_(_SC,THREAD_PROCESS_SHARED)
            EDEF_(_SC,THREAD_ROBUST_PRIO_INHERIT)
            EDEF_(_SC,THREAD_ROBUST_PRIO_PROTECT)
            EDEF_(_SC,THREAD_SAFE_FUNCTIONS)
            EDEF_(_SC,THREAD_SPORADIC_SERVER)
            EDEF_(_SC,THREAD_STACK_MIN)
            EDEF_(_SC,THREAD_THREADS_MAX)
            EDEF_(_SC,THREADS)
            EDEF_(_SC,TIMEOUTS)
            EDEF_(_SC,TIMER_MAX)
            EDEF_(_SC,TIMERS)
            EDEF_(_SC,TRACE)
            EDEF_(_SC,TRACE_EVENT_FILTER)
            EDEF_(_SC,TRACE_EVENT_NAME_MAX)
            EDEF_(_SC,TRACE_INHERIT)
            EDEF_(_SC,TRACE_LOG)
            EDEF_(_SC,TRACE_NAME_MAX)
            EDEF_(_SC,TRACE_SYS_MAX)
            EDEF_(_SC,TRACE_USER_EVENT_MAX)
            EDEF_(_SC,TTY_NAME_MAX)
            EDEF_(_SC,TYPED_MEMORY_OBJECTS)
            EDEF_(_SC,TZNAME_MAX)
            EDEF_(_SC,V7_ILP32_OFF32)
            EDEF_(_SC,V7_ILP32_OFFBIG)
            EDEF_(_SC,V7_LP64_OFF64)
            EDEF_(_SC,V7_LPBIG_OFFBIG)
            EDEF_(_SC,XOPEN_CRYPT)
            EDEF_(_SC,XOPEN_ENH_I18N)
            EDEF_(_SC,XOPEN_REALTIME)
            EDEF_(_SC,XOPEN_REALTIME_THREADS)
            EDEF_(_SC,XOPEN_SHM)
            EDEF_(_SC,XOPEN_STREAMS)
            EDEF_(_SC,XOPEN_UNIX)
            EDEF_(_SC,XOPEN_UUCP)
            EDEF_(_SC,XOPEN_VERSION)
        __preend("_SC")

        __dexit(enums)

        __dentr(structs, Struct[])
        __dexit(structs)

    __baseret(unistd_h)

}