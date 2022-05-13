
#pragma once

int include_fcntl_h(Lib *self, FILE *file) {
    __basedef(fcntl_h, "<fcntl.h>")
    __dentr(enums, Enum[])
        __predef("F")
            EDEF_(F,DUPFD)
            EDEF_(F,DUPFD_CLOEXEC)
        __preend("F")
        __predef("F")
            EDEF_(F,GETFD)
            EDEF_(F,SETFD)
        __preend("F")
        __predef("FD")
            EDEF_(FD,CLOEXEC)
        __preend("FD", .fmt="x")
        __predef("F")
            EDEF_(F,GETFL) 
            EDEF_(F,SETFL)
        __preend("F")
#   if (_POSIX_FILE_LOCKING > 0)
        __predef("F")
            EDEF_(F,GETLK)
            EDEF_(F,SETLK)
            EDEF_(F,SETLKW)
        __preend("F")
        __predef("F")
            EDEF_(F,RDLCK)
            EDEF_(F,WRLCK)
            EDEF_(F,UNLCK)
        __preend("F", .fmt="x")
#   endif
#   ifdef F_GETOWN
        __predef("F")
            EDEF_(F,GETOWN)
            EDEF_(F,SETOWN)
        __preend("F")
#   endif
#   ifdef F_NOTIFY
        __predef("F")
            EDEF_(F,NOTIFY)
        __preend("F")
        __predef("DN")
            EDEF_(DN,ACCESS)
            EDEF_(DN,ATTRIB)
            EDEF_(DN,CREATE)
            EDEF_(DN,DELETE)
            EDEF_(DN,MODIFY)
            EDEF_(DN,RENAME)
            EDEF_(DN,MULTISHOT)
        __preend("DN", .fmt="x")
#   endif
        __predef("SEEK")
            EDEF_(SEEK,SET)
            EDEF_(SEEK,CUR)
            EDEF_(SEEK,END)
        __preend("SEEK")
/*
*/
#   if (_POSIX_HOLE_PUNCHED_FILES > 0)
            EDEF_(SEEK,DATA)
            EDEF_(SEEK,HOLE)
#   endif
/*
*/
        __predef("O")
            EDEF_(O,RDWR) 
            EDEF_(O,RDONLY)
            EDEF_(O,WRONLY)
            EDEF_(O,EXEC)
            EDEF_(O,SEARCH)
            EDEF_(O,ACCMODE)

            EDEF_(O,CLOEXEC)
            EDEF_(O,CREAT)
            EDEF_(O,DIRECTORY)
            EDEF_(O,EXCL)
            EDEF_(O,NOCTTY)
            EDEF_(O,NOFOLLOW)
            EDEF_(O,TRUNC)
            EDEF_(O,TTY_INIT)

            EDEF_(O,APPEND)
            EDEF_(O,NONBLOCK)
//#   if (_POSIX_SYNCHRONIZED_IO > 0)
            EDEF_(O,DSYNC)
            EDEF_(O,RSYNC)
            EDEF_(O,SYNC)
//#   elif defined(_XOPEN_UNIX)
            EDEF_(O,SYNC)
//#   endif
        __preend("O", .fmt="x", .sort=C__VSORT)

/*
*/
#   ifndef AT_FDCWD
#       define BLTN_OPENAT 0
#   else
#       ifndef BLTN_OPENAT
#       define BLTN_OPENAT openat
#       endif
        __predef("AT")
            EDEF_(AT,FDCWD)
        __preend("AT")
        __predef("AT")
            EDEF_(AT,EACCESS)
            EDEF_(AT,SYMLINK_NOFOLLOW)
            EDEF_(AT,SYMLINK_FOLLOW)
            EDEF_(AT,REMOVEDIR)
        __preend("AT", .fmt="x")
#   endif

#   if (_POSIX_ADVISORY_INFO < 1)
#        define BLTN_POSIX_FADVISE 0
#        define BLTN_POSIX_FALLOCATE 0

#   else

#       ifndef BLTN_POSIX_FALLOCATE
#       define BLTN_POSIX_FALLOCATE posix_fallocate
#       endif

#       ifndef BLTN_POSIX_FADVISE
#       define BLTN_POSIX_FADVISE posix_fadvise
#       endif

        __predef("POSIX")
            EDEF_(POSIX,FADV_DONTNEED)
            EDEF_(POSIX,FADV_RANDOM)
            EDEF_(POSIX,FADV_SEQUENTIAL)
            EDEF_(POSIX,FADV_WILLNEED)
            EDEF_(POSIX,FADV_NORMAL)
        __preend("POSIX")

#   endif            

    __dexit(enums)
    __dentr(structs, Struct[])

        __memdef(flock_s)
        __member(flock_s, l_type,   "h")
        __member(flock_s, l_whence, "h")
        __member(flock_s, l_start,  "o")
        __member(flock_s, l_len,    "o")
        __member(flock_s, l_pid,    "{pid_t}")
        __enddef(flock_s)

/*

#       ifndef BLTN_POSIX_MEMALIGN
#       define BLTN_POSIX_MEMALIGN posix_memalign
#       endif
*/

    __dexit(structs)
    __baseret(fcntl_h)
}

int test_fcntl_h(Lib *self, FILE *file) {

#   ifndef BLTN_OPEN
#   define BLTN_OPEN open
#   endif

#   ifndef BLTN_FCNTL
#   define BLTN_FCNTL fcntl
#   endif

#   ifndef BLTN_CREAT
#   define BLTN_CREAT creat
#   endif

    self->creat             = BLTN_CREAT;
    self->open              = BLTN_OPEN;
    self->openat            = BLTN_OPENAT;
    self->posix.fadvise     = BLTN_POSIX_FADVISE;
    self->posix.fallocate   = BLTN_POSIX_FALLOCATE;
    return 0;
}