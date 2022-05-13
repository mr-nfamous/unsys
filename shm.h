#pragma once

int include_sys_shm_h(Lib *self, FILE *file) {

    __basedef(sys_shm_h, "<sys/shm.h>")

    __dentr(enums, Enum[])
        __predef("SHM")
            EDEF_(SHM,RDONLY)
            EDEF_(SHM,RND)
        __preend("SHM", .fmt="x")
        __predef("")
            EREF(SHMLBA)
        __preend("")
    __dexit(enums)
    __dentr(structs, Struct[])
        __memdef(shmid_ds_s)
        __member(shmid_ds_s, shm_perm, "ipc_perm_s")
        __member(shmid_ds_s, shm_segsz, "size_t")
        __member(shmid_ds_s, shm_lpid, "pid_t")
        __member(shmid_ds_s, shm_cpid, "pid_t")
        __member(shmid_ds_s, shm_nattch, "shmatt_t")
        __member(shmid_ds_s, shm_atime, "time_t")
        __member(shmid_ds_s, shm_dtime, "time_t")
        __member(shmid_ds_s, shm_ctime, "time_t")
        __enddef(shmid_ds_s)
    __dexit(structs)
    __baseret(sys_shm_h)
}

int test_sys_shm_h(Lib *self, FILE *file) {
#   ifndef BLTN_SHMAT
#   define BLTN_SHMAT shmat
#   endif
#   ifndef BLTN_SHMCTL
#   define BLTN_SHMCTL shmctl
#   endif
#   ifndef BLTN_SHMDT
#   define BLTN_SHMDT shmdt
#   endif
#   ifndef BLTN_SHMGET
#   define BLTN_SHMGET shmget
#   endif
    self->shmat  = BLTN_SHMAT;
    self->shmdt  = BLTN_SHMDT;
    self->shmctl = BLTN_SHMCTL;
    self->shmget = BLTN_SHMGET;
    return 0;
}
