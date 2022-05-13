#pragma once

int include_poll_h(Lib *self, FILE *file) {

    __basedef(poll_h, "<poll.h>")

    __dentr(enums, Enum[])
        __predef("")
            EREF(POLLIN)
            EREF(POLLOUT)
            EREF(POLLPRI)
            EREF(POLLERR)
            EREF(POLLHUP)
            EREF(POLLRDNORM)
            EREF(POLLRDBAND)
            EREF(POLLWRNORM)
            EREF(POLLWRBAND)
        __preend("", .fmt="x")
    __dexit(enums)

    __dentr(structs, Struct[])
        __memdef(pollfd_s)
        __member(pollfd_s, fd, "int_t")
        __member(pollfd_s, events, "short_t")
        __member(pollfd_s, revents, "short_t")
        __enddef(pollfd_s)
    __dexit(structs)
    __baseret(poll_h)
}

int test_poll_h(Lib *self, FILE *file) {
#   ifndef BLTN_POLL
#   define BLTN_POLL poll
#   endif
#   ifndef BLTN_PPOLL
#   define BLTN_PPOLL 0
#   endif

    self->poll = BLTN_POLL;
    self->ppoll = BLTN_PPOLL;
    return 0;
}