/*
void FD_CLR(int, fd_set *); 
int FD_ISSET(int, fd_set *);
void FD_SET(int, fd_set *); 
void FD_ZERO(fd_set *);
*/
void bltn_fd_clr(int fd, fds set) {
    FD_CLR(fd, set);
}

void bltn_fd_set(int fd, fds set) {
    FD_SET(fd, set);
}    

void bltn_fd_zero(fds set) {
    FD_ZERO(set);
}

int bltn_fd_isset(int fd, fds set) {
    return FD_ISSET(fd, set);
}

#pragma once

int include_sys_select_h(Lib *self, FILE *file) {

    __basedef(sys_select_h, "<sys/select.h>")

    __dentr(enums, Enum[])
        __predef("")
            EREF(FD_SETSIZE)
        __preend("")
    __dexit(enums)

    __baseret(sys_select_h)
}

int test_sys_select_h(Lib *self, FILE *file) {
#   ifndef BLTN_FD_CLR
#   define BLTN_FD_CLR bltn_fd_clr
#   endif
#   ifndef BLTN_FD_SET
#   define BLTN_FD_SET bltn_fd_set
#   endif
#   ifndef BLTN_FD_ZERO
#   define BLTN_FD_ZERO bltn_fd_zero
#   endif
#   ifndef BLTN_FD_ISSET
#   define BLTN_FD_ISSET bltn_fd_isset
#   endif
#   ifndef BLTN_SELECT
#   define BLTN_SELECT select
#   endif
#   ifndef BLTN_PSELECT
#   define BLTN_PSELECT pselect
#   endif
    self->FD_CLR    = BLTN_FD_CLR;
    self->FD_SET    = BLTN_FD_SET;
    self->FD_ZERO   = BLTN_FD_ZERO;
    self->FD_ISSET  = BLTN_FD_ISSET;
    self->select    = BLTN_SELECT;
    self->pselect   = BLTN_PSELECT;
    return 0;
}