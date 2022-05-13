
#pragma once

int c_wexitstatus(int status) {
    return (status&0xff00)>>8;
}
int c_wcoredump(int status) {
    return status&0x80;
}
int c_wtermsig(int status) {
    return status&0x7f;
} 
int c_wstopsig(int status) {
    return (status&0xff00)>>8;
}
int c_wifexited(int status) {
    return !(0x7f&status);
}
int c_wifstopped(int status) {
    return (0x7f&status) == 0x7f;
}
int c_wifsignaled(int status) {
    return (0x7f&(status+1)) >= 2;
}
int c_wifcontinued(int status) {
    return status == 0xffff;
}
int c_w_exitcode(int xcode, int signo) {
    return xcode<<8|signo;
}
int c_w_stopcode(int signo) {
    return signo<<8|0x7f;
}

int include_sys_wait_h(Lib *self, FILE *file) {

#   ifndef BLTN_WEXITSTATUS
#   define BLTN_WEXITSTATUS c_wexitstatus
#   endif

#   ifndef BLTN_WIFSTOPPED
#   define BLTN_WIFSTOPPED c_wifstopped
#   endif 

#   ifndef BLTN_WIFCONTINUED
#   define BLTN_WIFCONTINUED c_wifcontinued
#   endif

#   ifndef BLTN_WIFEXITED
#   define BLTN_WIFEXITED c_wifexited
#   endif

#   ifndef BLTN_WIFSIGNALED
#   define BLTN_WIFSIGNALED c_wifsignaled
#   endif
    
#   ifndef BLTN_WSTOPSIG
#   define BLTN_WSTOPSIG c_wstopsig
#   endif

#   ifndef BLTN_WTERMSIG
#   define BLTN_WTERMSIG c_wtermsig
#   endif

#   ifndef BLTN_WCOREDUMP
#   define BLTN_WCOREDUMP c_wcoredump
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

    self[0].WEXITSTATUS = BLTN_WEXITSTATUS;
    self[0].WIFSTOPPED  = BLTN_WIFSTOPPED;
    self[0].WIFCONTINUED= BLTN_WIFCONTINUED;
    self[0].WIFEXITED   = BLTN_WIFEXITED;
    self[0].WIFSIGNALED = BLTN_WIFSIGNALED;
    self[0].WSTOPSIG    = BLTN_WSTOPSIG;
    self[0].WTERMSIG    = BLTN_WTERMSIG;
    self[0].WCOREDUMP   = BLTN_WCOREDUMP;
    self[0].wait        = BLTN_WAIT;
    self[0].waitpid     = BLTN_WAITPID;
    self[0].waitid      = BLTN_WAITID;
    self[0].wait3       = BLTN_WAIT3;
    self[0].wait4       = BLTN_WAIT4;

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
