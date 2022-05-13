#ifndef _XBD_WAIT_H
#define _XBD_WAIT_H

typedef struct rusage *rusage_p;
typedef int wstatus, *wstatus_p;
typedef int waitop;

struct c_sys_wait_ffi {
    int   (*waitid)     (idtype_t, id_t, siginfo_p, waitop); 
    pid_t (*wait)       (wstatus_p); 
    pid_t (*wait3)      (wstatus_p, waitop, rusage_p);
    pid_t (*wait4)      (pid_t, wstatus_p, waitop, rusage_p); 
    pid_t (*waitpid)    (pid_t, wstatus_p, waitop);
    int (*WEXITSTATUS)  (wstatus);
    int (*WCOREDUMP)    (wstatus);
    int (*WTERMSIG)     (wstatus);
    int (*WSTOPSIG)     (wstatus);
    int (*WIFEXITED)    (wstatus);
    int (*WIFSTOPPED)   (wstatus);
    int (*WIFSIGNALED)  (wstatus);
    int (*WIFCONTINUED) (wstatus);
};

void print_sys_wait_h(void) {

    Header c_sys_wait_h = {
        .path = "<sys/wait.h>",
        .enums = (Enum[]) {

            // idtype_t (aka P_*)
            {
                .name="P",
                .defs= (Const[]) {
                    C__EDEF(P, PGID),
                    C__EDEF(P, ALL),
                    C__EDEF(P, PID),
                    {0}
                },
            },

            // "waitop"
            {
                .name = "",
                .defs = (Const[]) {
                    // wait[p]id
                    // wait[i]d
                    C__EREF(WUNTRACED),   //  [-p]
                    C__EREF(WCONTINUED),  //  [ip]
                    C__EREF(WNOHANG),    //  [ip]
                    C__EREF(WEXITED),     //  [i-]
                    C__EREF(WNOWAIT),     //  [i-]
                    C__EREF(WSTOPPED),    //  [i-]
                    {0}
                },
                .fmt="x",
            },

            // STOP
            {0}
        }
    };
    Header_print(&c_sys_wait_h);
    
}



int c_WEXITSTATUS(int status) {
    return (status&0xff00)>>8;
};

int c_WCOREDUMP(int status) {
    return status&0x80;
}

int c_WTERMSIG(int status) {
    return status&0x7f;
} 

int c_WSTOPSIG(int status) {
    return (status&0xff00)>>8;
}

int c_WIFEXITED(int status) {
    return !(0x7f&status);
}

int c_WIFSTOPPED(int status) {
    return (0x7f&status) == 0x7f;
}

int c_WIFSIGNALED(int status) {
    return (0x7f&(status+1)) >= 2;
}

int c_WIFCONTINUED(int status) {
    return status == 0xffff;
}

int c_W_EXITCODE(int xcode, int signo) {
    return xcode<<8|signo;
}

int c_W_STOPCODE(int signo) {
    return signo<<8|0x7f;
}

#endif
