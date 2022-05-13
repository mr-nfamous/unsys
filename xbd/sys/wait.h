
#pragma once

int bltn_wexitstatus(int status) {
    return (status&0xff00)>>8;
}
int bltn_wcoredump(int status) {
    return status&0x80;
}
int bltn_wtermsig(int status) {
    return status&0x7f;
} 
int bltn_wstopsig(int status) {
    return (status&0xff00)>>8;
}
int bltn_wifexited(int status) {
    return !(0x7f&status);
}
int bltn_wifstopped(int status) {
    return (0x7f&status) == 0x7f;
}
int bltn_wifsignaled(int status) {
    return (0x7f&(status+1)) >= 2;
}
int bltn_wifcontinued(int status) {
    return status == 0xffff;
}
int bltn_w_exitcode(int xcode, int signo) {
    return xcode<<8|signo;
}
int bltn_w_stopcode(int signo) {
    return signo<<8|0x7f;
}

int include_sys_wait_h(Lib *self, FILE *file) {

#   ifndef BLTN_WEXITSTATUS
#   define BLTN_WEXITSTATUS bltn_wexitstatus
#   endif

#   ifndef BLTN_WIFSTOPPED
#   define BLTN_WIFSTOPPED bltn_wifstopped
#   endif 

#   ifndef BLTN_WIFCONTINUED
#   define BLTN_WIFCONTINUED bltn_wifcontinued
#   endif

#   ifndef BLTN_WIFEXITED
#   define BLTN_WIFEXITED bltn_wifexited
#   endif

#   ifndef BLTN_WIFSIGNALED
#   define BLTN_WIFSIGNALED bltn_wifsignaled
#   endif
    
#   ifndef BLTN_WSTOPSIG
#   define BLTN_WSTOPSIG bltn_wstopsig
#   endif

#   ifndef BLTN_WTERMSIG
#   define BLTN_WTERMSIG bltn_wtermsig
#   endif

#   ifndef BLTN_WCOREDUMP
#   define BLTN_WCOREDUMP bltn_wcoredump
#   endif

#   ifndef BLTN_WAIT
#   define BLTN_WAIT wait
#   endif

#   ifndef BLTN_WAITPID
#   define BLTN_WAITPID waitpid
#   endif

#   ifndef BLTN_WAITID
#   define BLTN_WAITID waitid
#   endif

#   ifndef BLTN_WAIT3
#   define BLTN_WAIT3 0
#   endif

#   ifndef BLTN_WAIT4
#   define BLTN_WAIT4 0
#   endif

    self->WEXITSTATUS = BLTN_WEXITSTATUS;
    self->WIFSTOPPED  = BLTN_WIFSTOPPED;
    self->WIFCONTINUED= BLTN_WIFCONTINUED;
    self->WIFEXITED   = BLTN_WIFEXITED;
    self->WIFSIGNALED = BLTN_WIFSIGNALED;
    self->WSTOPSIG    = BLTN_WSTOPSIG;
    self->WTERMSIG    = BLTN_WTERMSIG;
    self->WCOREDUMP   = BLTN_WCOREDUMP;
    self->wait        = BLTN_WAIT;
    self->waitpid     = BLTN_WAITPID;
    self->waitid      = BLTN_WAITID;
    self->wait3       = BLTN_WAIT3;
    self->wait4       = BLTN_WAIT4;

    __basedef(sys_wait_h, "<sys/wait.h>")
        __dentr(enums, Enum[])
            __predef("P")
                EDEF_(P,PID)
                EDEF_(P,PGID)
                EDEF_(P,ALL)
            __preend("P", .sort=C__VSORT)
            __predef("")
                EREF(WCONTINUED)
                EREF(WNOHANG)
                EREF(WNOWAIT)
                EREF(WUNTRACED)
                EREF(WEXITED)
                EREF(WSTOPPED)
            __preend("", .fmt="x")
        __dexit(enums)
    __baseret(sys_wait_h)
}
