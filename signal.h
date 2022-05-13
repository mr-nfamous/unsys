
#pragma once

int include_signal_h(Lib *self, FILE *file) {
#   ifndef BLTN_KILL
#   define BLTN_KILL kill
#   endif
#   ifndef BLTN_KILLPG
#   define BLTN_KILLPG killpg
#   endif
#   ifndef BLTN_SIGQUEUE
#   define BLTN_SIGQUEUE sigqueue
#   endif
#   ifndef BLTN_RAISE
#   define BLTN_RAISE raise
#   endif
#   ifndef BLTN_SIGACTION
#   define BLTN_SIGACTION sigaction
#   endif
#   ifndef BLTN_SIGADDSET
#   define BLTN_SIGADDSET sigaddset
#   endif
#   ifndef BLTN_SIGALTSTACK
#   define BLTN_SIGALTSTACK sigaltstack
#   endif
#   ifndef BLTN_SIGDELSET
#   define BLTN_SIGDELSET sigdelset
#   endif
#   ifndef BLTN_SIGEMPTYSET
#   define BLTN_SIGEMPTYSET sigemptyset
#   endif
#   ifndef BLTN_SIGFILLSET
#   define BLTN_SIGFILLSET sigfillset
#   endif
#   ifndef BLTN_SIGISMEMBER
#   define BLTN_SIGISMEMBER sigismember
#   endif
#   ifndef BLTN_SIGPENDING
#   define BLTN_SIGPENDING sigpending
#   endif
#   ifndef BLTN_SIGPROCMASK
#   define BLTN_SIGPROCMASK sigprocmask
#   endif
#   ifndef BLTN_SIGSUSPEND
#   define BLTN_SIGSUSPEND sigsuspend
#   endif
#   ifndef BLTN_SIGTIMEDWAIT
#   define BLTN_SIGTIMEDWAIT sigtimedwait
#   endif
#   ifndef BLTN_SIGWAIT
#   define BLTN_SIGWAIT sigwait
#   endif
#   ifndef BLTN_SIGWAITINFO
#   define BLTN_SIGWAITINFO sigwaitinfo
#   endif
#   ifndef BLTN_SIGINTERRUPT
#   define BLTN_SIGINTERRUPT siginterrupt
#   endif
#   ifndef BLTN_SIGHOLD
#   define BLTN_SIGHOLD 0
#   endif
#   ifndef BLTN_SIGIGNORE
#   define BLTN_SIGIGNORE 0
#   endif
#   ifndef BLTN_SIGPAUSE
#   define BLTN_SIGPAUSE 0
#   endif
#   ifndef BLTN_SIGRELSE
#   define BLTN_SIGRELSE 0
#   endif
#   ifndef BLTN_SIGVEC
#   define BLTN_SIGVEC 0
#   endif
#   ifndef BLTN_SIGMASK
#   define BLTN_SIGMASK 0
#   endif
#   ifndef BLTN_SIGBLOCK
#   define BLTN_SIGBLOCK 0
#   endif
#   ifndef BLTN_SIGSETMASK
#   define BLTN_SIGSETMASK 0
#   endif
#   ifndef BLTN_SIGGETMASK
#   define BLTN_SIGGETMASK 0
#   endif
#   ifndef BLTN_PSIGINFO
#   define BLTN_PSIGINFO psiginfo
#   endif
#   ifndef BLTN_PSIGNAL
#   define BLTN_PSIGNAL psignal
#   endif
#   ifndef BLTN_SIGSET
#   define BLTN_SIGSET 0
#   endif
#   ifndef BLTN_SIGNAL
#   define BLTN_SIGNAL signal
#   endif

    self->kill          = BLTN_KILL;
    self->killpg        = BLTN_KILLPG;
    self->sigqueue      = BLTN_SIGQUEUE;
    self->raise         = BLTN_RAISE;
    self->sigaction     = BLTN_SIGACTION;
    self->sigaddset     = BLTN_SIGADDSET;
    self->sigaltstack   = BLTN_SIGALTSTACK;
    self->sigdelset     = BLTN_SIGDELSET;
    self->sigemptyset   = BLTN_SIGEMPTYSET;
    self->sigfillset    = BLTN_SIGFILLSET;
    self->sigismember   = BLTN_SIGISMEMBER;
    self->sigpending    = BLTN_SIGPENDING;
    self->sigprocmask   = BLTN_SIGPROCMASK;
    self->sigsuspend    = BLTN_SIGSUSPEND;
    self->sigtimedwait  = BLTN_SIGTIMEDWAIT;
    self->sigwait       = BLTN_SIGWAIT;
    self->sigwaitinfo   = BLTN_SIGWAITINFO;
    self->siginterrupt  = BLTN_SIGINTERRUPT;
    self->sighold       = BLTN_SIGHOLD;
    self->sigignore     = BLTN_SIGIGNORE;
    self->sigpause      = BLTN_SIGPAUSE;
    self->sigrelse      = BLTN_SIGRELSE;
    self->sigvec        = BLTN_SIGVEC;
    self->sigmask       = BLTN_SIGMASK;
    self->sigblock      = BLTN_SIGBLOCK;
    self->sigsetmask    = BLTN_SIGSETMASK;
    self->siggetmask    = BLTN_SIGGETMASK;
    self->psiginfo      = BLTN_PSIGINFO;
    self->psignal       = BLTN_PSIGNAL;
    self->sigset        = BLTN_SIGSET;
    self->signal        = BLTN_SIGNAL;

    __basedef(signal_h, "<signal.h>")
        __dentr(enums, Enum[])
            __predef("SIGEV")
                EDEF_(SIGEV,NONE)
                EDEF_(SIGEV,SIGNAL)
                EDEF_(SIGEV,THREAD)
            __preend("SIGEV")
            __predef("ILL")
                EDEF_(ILL, ILLOPC)
                EDEF_(ILL, ILLOPN)
                EDEF_(ILL, ILLADR)
                EDEF_(ILL, ILLTRP)
                EDEF_(ILL, PRVOPC)
                EDEF_(ILL, PRVREG)
                EDEF_(ILL, COPROC)
                EDEF_(ILL, BADSTK)
            __preend("ILL", .sort=C__VSORT)
            __predef("")
                EREF(SIGRTMIN)
                EREF(SIGRTMAX)
                EREF(SIGBUS)  // [a] 
                EREF(SIGFPE)  // [a] C
                EREF(SIGILL)  // [a] C
                EREF(SIGSEGV)  // [a] C
                EREF(SIGQUIT)  // [a]      QUIT character in terminal
                EREF(SIGSYS)  // [a] X
                EREF(SIGXCPU)  // [a]
                EREF(SIGXFSZ)  // [a]
                EREF(SIGTRAP)  // [a]
                EREF(SIGALRM)  // [t]
                EREF(SIGHUP)  // [t]
                EREF(SIGTERM)  // [t]
                EREF(SIGINT)  // [t] C    INTR character in terminal 
                EREF(SIGKILL)  // [T] 
                EREF(SIGPIPE)  // [t] C
                EREF(SIGUSR1)  // [t] 
                EREF(SIGUSR2)  // [t] 
                EREF(SIGPOLL)  // [t] 
                EREF(SIGPROF)  // [t] 
                EREF(SIGVTALRM)  // [t] X
                EREF(SIGSTOP)  // [S]
                EREF(SIGTSTP)  // [s] 
                EREF(SIGTTIN)  // [s]
                EREF(SIGTTOU)  // [s]
                EREF(SIGCONT)  // [c]
                EREF(SIGCHLD)  // [i]
            #ifdef SIGCLD
                EREF(SIGCLD)  // [i]
            #endif
                EREF(SIGURG)  // [i]
            #ifdef SIGSTKFLT
                EREF(SIGSTKFLT) 
            #endif
            #ifdef SIGWINCH
                EREF(SIGWINCH) 
            #endif
            #ifdef SIGIO
                EREF(SIGIO) 
            #endif
            #ifdef SIGPWR
                EREF(SIGPWR) 
            #endif
            #ifdef SIGUNUSED
                EREF(SIGUNUSED) 
            #endif
            __preend("", .sort=C__VSORT)
        __dexit(enums)

        __dentr(structs, Struct[])

            __memdef(sigevent_s)
            __member(sigevent_s, sigev_notify, "SIGEV")
            __member(sigevent_s, sigev_signo, "SIG")
            __member(sigevent_s, sigev_value, "sigval_u")
            __member(sigevent_s, sigev_notify_function, "sigevent_f")
            __member(sigevent_s, sigev_notify_attributes, "buffer")
            __enddef(sigevent_s)
            
            __memdef(sigval_u)
            __member(sigval_u, sival_int, "SIG")
            __member(sigval_u, sival_ptr, "buffer")
            __enddef(sigval_u)
            
            __memdef(sigaction_s)
            __member(sigaction_s, sa_handler, "sa_handler_f")
            __member(sigaction_s, sa_mask, "sigset_t")
            __member(sigaction_s, sa_flags, "int")
            __member(sigaction_s, sa_sigaction, "sa_sigaction_f")
            __enddef(sigaction_u)
            
        __dexit(structs)

    __baseret(signal_h)
 
}