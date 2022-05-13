#pragma once

int include_sys_sem_h(Lib *self, FILE *file) {

    __basedef(sys_sem_h, "<sys_sem.h>")

    __dentr(enums, Enum[])
        __predef("SEM")
            EDEF_(SEM,UNDO)
        __preend("SEM", .fmt="x")
        __predef("")
            EREF(GETNCNT)
            EREF(GETPID)
            EREF(GETVAL)
            EREF(GETALL)
            EREF(SETVAL)
            EREF(SETALL)
            EREF(GETZCNT)
        __preend("", .fmt="x")

    __dexit(enums)

    __dentr(structs, Struct[])
        __memdef(semid_ds_s)
        __member(semid_ds_s, sem_perm, "ipc_perm_s")
        __member(semid_ds_s, sem_nsems, "ushrt_t")
        __member(semid_ds_s, sem_otime, "time_t")
        __member(semid_ds_s, sem_ctime, "time_t")
        __enddef(semid_ds_s)

        __memdef(sembuf_s)
        __member(sembuf_s, num, "ushrt_t")
        __member(sembuf_s, op, "short_t")
        __member(sembuf_s, flg, "short_t")
        __enddef(sembuf_s)

        __memdef(semun_s)
        __member(semun_s, val, "int_t")
        __member(semun_s, buf, "semid_ds_p")
        __member(semun_s, array, "ushrt_p")
        __enddef(semun_s)

    __dexit(structs)
    __baseret(sys_sem_h)
}

int test_sys_sem_h(Lib *self, FILE *file) {
#   ifndef BLTN_SEMCTL
#   define BLTN_SEMCTL semctl
#   endif
#   ifndef BLTN_SEMGET
#   define BLTN_SEMGET semget
#   endif
#   ifndef BLTN_SEMOP
#   define BLTN_SEMOP semop
#   endif
    self->semctl = BLTN_SEMCTL;
    self->semget = BLTN_SEMGET;
    self->semop  = BLTN_SEMOP;
    return 0;
}
