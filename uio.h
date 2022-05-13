#pragma once
/*
————————————————————————————————————————————————————————————————————————————————
*/


int include_sys_uio_h(Lib *self, FILE *file) {

    __basedef(sys_uio_h, "<sys_uio.h>")

    __dentr(structs, Struct[])
        __memdef(iovec_s)
        __member(iovec_s, iov_base, "{buffer}")
        __member(iovec_s, iov_len,  "{size_t}")
        __enddef(iovec_s)
    __dexit(structs)
    __baseret(sys_uio_h)
}

int test_sys_uio_h(Lib *self, FILE *file) {

#   ifndef BLTN_READV
#   define BLTN_READV readv
#   endif

#   ifndef BLTN_WRITEV
#   define BLTN_WRITEV writev
#   endif

#   ifndef BLTN_PREADV
#   define BLTN_PREADV 0
#   endif

#   ifndef BLTN_PWRITEV
#   define BLTN_PWRITEV 0
#   endif

    self->readv     = BLTN_READV;
    self->writev    = BLTN_WRITEV;
    self->preadv    = BLTN_PREADV;
    self->pwritev   = BLTN_PWRITEV;

#   ifdef BLTN_PREADV2
    self->readv2    = BLTN_READV2;
#   endif

#   ifdef BLTN_PWRITEV2
    self->pwritev2  = BLTN_PWRITEV2;
#   endif
    return 0;

}