#pragma once

int include_semaphore_h(Lib *self, FILE *file) {

    __basedef(semaphore_h, "<semaphore.h>")

    __dentr(enums, Enum[])
    __dexit(enums)

    __dentr(structs, Struct[])
    __dexit(structs)

    __baseret(semaphore_h)
}

int test_semaphore_h(Lib *self, FILE *file) {
#   ifndef BLTN_SEM_CLOSE
#   define BLTN_SEM_CLOSE sem_close
#   endif
#   ifndef BLTN_SEM_DESTROY
#   define BLTN_SEM_DESTROY sem_destroy
#   endif
#   ifndef BLTN_SEM_GETVALUE
#   define BLTN_SEM_GETVALUE sem_getvalue
#   endif
#   ifndef BLTN_SEM_INIT
#   define BLTN_SEM_INIT sem_init
#   endif
#   ifndef BLTN_SEM_POST
#   define BLTN_SEM_POST sem_post
#   endif
#   ifndef BLTN_SEM_TIMEDWAIT
#   define BLTN_SEM_TIMEDWAIT sem_timedwait
#   endif
#   ifndef BLTN_SEM_TRYWAIT
#   define BLTN_SEM_TRYWAIT sem_trywait
#   endif
#   ifndef BLTN_SEM_UNLINK
#   define BLTN_SEM_UNLINK sem_unlink
#   endif
#   ifndef BLTN_SEM_WAIT
#   define BLTN_SEM_WAIT sem_wait
#   endif
#   ifndef BLTN_SEM_OPEN
#   define BLTN_SEM_OPEN sem_open
#   endif
    self->sem.close     = BLTN_SEM_CLOSE;
    self->sem.destroy   = BLTN_SEM_DESTROY;
    self->sem.getvalue  = BLTN_SEM_GETVALUE;
    self->sem.init      = BLTN_SEM_INIT;
    self->sem.post      = BLTN_SEM_POST;
    self->sem.timedwait = BLTN_SEM_TIMEDWAIT;
    self->sem.trywait   = BLTN_SEM_TRYWAIT;
    self->sem.unlink    = BLTN_SEM_UNLINK;
    self->sem.wait      = BLTN_SEM_WAIT;
    self->sem.open      = BLTN_SEM_OPEN;
    return 0;
}
