#pragma once

int include_sys_ipc_h(Lib *self, FILE *file) {

    __basedef(sys_ipc_h, "<sys/ipc.h>")

    __dentr(enums, Enum[])
        __predef("IPC")
            EDEF_(IPC,CREAT)
            EDEF_(IPC,EXCL)
            EDEF_(IPC,NOWAIT)
        __preend("IPC", .fmt="x")
        __predef("IPC")
            EDEF_(IPC,RMID)
            EDEF_(IPC,SET)
            EDEF_(IPC,STAT)
        __preend("IPC")
        //__predef("IPC")
        //    EDEF_(IPC,PRIVATE)
        //__preend("IPC")

    __dexit(enums)

    __dentr(structs, Struct[])
        __memdef(ipc_perm_s)
        __member(ipc_perm_s, uid, "{uid_t}")
        __member(ipc_perm_s, gid, "{gid_t}")
        __member(ipc_perm_s, uid, "{uid_t}")
        __member(ipc_perm_s, gid, "{gid_t}")
        __enddef(ipc_perm_s)
    __dexit(structs)
    __baseret(sys_ipc_h)
}

int test_sys_ipc_h(Lib *self, FILE *file) {
#   ifndef BLTN_FTOK
#   define BLTN_FTOK ftok
#   endif
    return 0;
}