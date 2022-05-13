
#pragma once

int include_aio_h(Lib *self, FILE *file) {
    __basedef(aio_h, "<aio.h>")
    __dentr(enums, Enum[])
        __predef("AIO")
            EDEF_(AIO,ALLDONE)
            EDEF_(AIO,CANCELED)
            EDEF_(AIO,NOTCANCELED)
        __preend("AIO")
        __predef("LIO")
            EDEF_(LIO,NOP)
            EDEF_(LIO,NOWAIT)
            EDEF_(LIO,READ)
            EDEF_(LIO,WAIT)
            EDEF_(LIO,WRITE)
        __preend("LIO")
    __dexit(enums)
    __dentr(structs, Struct[])
        __memdef(aiocb_s)
        __member(aiocb_s, aio_filedes, "int")
        __member(aiocb_s, aio_offset, "off_t")
        __member(aiocb_s, aio_buf, "vvoid")
        __member(aiocb_s, aio_nbytes, "sizeaiot")
        __member(aiocb_s, aio_reqprio, "int")
        __member(aiocb_s, aio_sigevent, "sigevent_s")
        __member(aiocb_s, aio_lio_opcode, "int")
        __enddef(aiocb_s)
    __dexit(structs)
    __baseret(aio_h)
}

int test_aio_h(Lib *self, FILE *file) {
#   ifndef BLTN_AIO_CANCEL
#   define BLTN_AIO_CANCEL aio_cancel
#   endif
#   ifndef BLTN_AIO_ERROR
#   define BLTN_AIO_ERROR aio_error
#   endif
#   ifndef BLTN_AIO_FSYNC
#   define BLTN_AIO_FSYNC aio_fsync
#   endif
#   ifndef BLTN_AIO_READ
#   define BLTN_AIO_READ aio_read
#   endif
#   ifndef BLTN_AIO_RETURN
#   define BLTN_AIO_RETURN aio_return
#   endif
#   ifndef BLTN_AIO_SUSPEND
#   define BLTN_AIO_SUSPEND aio_suspend
#   endif
#   ifndef BLTN_AIO_WRITE
#   define BLTN_AIO_WRITE aio_write
#   endif
#   ifndef BLTN_LIO_LISTIO
#   define BLTN_LIO_LISTIO lio_listio
#   endif
    self->aio_cancel    = BLTN_AIO_CANCEL;
    self->aio_error     = BLTN_AIO_ERROR;
    self->aio_fsync     = BLTN_AIO_FSYNC;
    self->aio_read      = BLTN_AIO_READ;
    self->aio_return    = BLTN_AIO_RETURN;
    self->aio_suspend   = BLTN_AIO_SUSPEND;
    self->aio_write     = BLTN_AIO_WRITE;
    self->lio_listio    = BLTN_LIO_LISTIO;
    return 0;
}
