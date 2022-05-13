#pragma once

int include_sys_msg_h(Lib *self, FILE *file) {
    __basedef(sys_msg_h, "<sys/msg.h>")
    __dentr(enums, Enum[])
        __predef("MSG")
            EDEF_(MSG,NOERROR)
        __preend("MSG", .fmt="x")
    __dexit(enums)
    __dentr(structs, Struct[])
        __memdef(msqid_ds)
        __member(msqid_ds, msg_perm, "ipc_perm_s")
        __member(msqid_ds, msg_qnum, "msgqnum_t")
        __member(msqid_ds, msg_qbytes, "msglen_t")
        __member(msqid_ds, msg_lspid, "pid_t")
        __member(msqid_ds, msg_lrpid, "pid_t")
        __member(msqid_ds, msg_stime, "time_t")
        __member(msqid_ds, msg_rtime, "time_t")
        __member(msqid_ds, msg_ctime, "time_t")
        __enddef(msqid_ds)
    __dexit(structs)
    __baseret(sys_msg_h)
}

int test_sys_msg_h(Lib *self, FILE *file) {
#   ifndef BLTN_MSGCTL
#   define BLTN_MSGCTL msgctl
#   endif
#   ifndef BLTN_MSGGET
#   define BLTN_MSGGET msgget
#   endif
#   ifndef BLTN_MSGSND
#   define BLTN_MSGSND msgsnd
#   endif
#   ifndef BLTN_MSGRCV
#   define BLTN_MSGRCV msgrcv
#   endif
    self->msgctl = BLTN_MSGCTL;
    self->msgget = BLTN_MSGGET;
    self->msgsnd = BLTN_MSGSND;
    self->msgrcv = BLTN_MSGRCV;
    return 0;
}
