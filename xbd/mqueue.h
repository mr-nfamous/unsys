
#pragma once

int include_mqueue_h(Lib *self, FILE *file) {
    __basedef(mqueue_h, "<mqueue.h>")
    __dentr(enums, Enum[])
    __dexit(enums)
    __dentr(structs, Struct[])
        __memdef(mq_attr_s)
        __member(mq_attr_s, mq_flags, "long")
        __member(mq_attr_s, mq_maxmsg, "long")
        __member(mq_attr_s, mq_msgsize, "long")
        __member(mq_attr_s, mq_curmsgs, "long")
        __enddef(mq_attr_s)
    __dexit(structs)
    __baseret(mqueue_h)
}
int test_mqueue_h(Lib *self, FILE *file) {
#   ifndef BLTN_MQ_CLOSE
#   define BLTN_MQ_CLOSE mq_close
#   endif
#   ifndef BLTN_MQ_GETATTR
#   define BLTN_MQ_GETATTR mq_getattr
#   endif
#   ifndef BLTN_MQ_NOTIFY
#   define BLTN_MQ_NOTIFY mq_notify
#   endif
#   ifndef BLTN_MQ_SEND
#   define BLTN_MQ_SEND mq_send
#   endif
#   ifndef BLTN_MQ_SETATTR
#   define BLTN_MQ_SETATTR mq_setattr
#   endif
#   ifndef BLTN_MQ_TIMEDSEND
#   define BLTN_MQ_TIMEDSEND mq_timedsend
#   endif
#   ifndef BLTN_MQ_UNLINK
#   define BLTN_MQ_UNLINK mq_unlink
#   endif
#   ifndef BLTN_MQ_OPEN
#   define BLTN_MQ_OPEN mq_open
#   endif
#   ifndef BLTN_MQ_RECEIVE
#   define BLTN_MQ_RECEIVE mq_receive
#   endif
#   ifndef BLTN_MQ_TIMEDRECEIVE
#   define BLTN_MQ_TIMEDRECEIVE mq_timedreceive
#   endif
    self->mq.close          = BLTN_MQ_CLOSE;
    self->mq.getattr        = BLTN_MQ_GETATTR;
    self->mq.notify         = BLTN_MQ_NOTIFY;
    self->mq.send           = BLTN_MQ_SEND;
    self->mq.setattr        = BLTN_MQ_SETATTR;
    self->mq.timedsend      = BLTN_MQ_TIMEDSEND;
    self->mq.unlink         = BLTN_MQ_UNLINK;
    self->mq.open           = BLTN_MQ_OPEN;
    self->mq.receive        = BLTN_MQ_RECEIVE;
    self->mq.timedreceive   = BLTN_MQ_TIMEDRECEIVE;
    return 0;
}