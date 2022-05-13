/*
    
    ¦——————————¦————————¦—————————————————————————————————————
    | S_IXOTH  | 000001 | --x oth
    | S_IWOTH  | 000002 | -w- oth
    | S_IROTH  | 000004 | r-- oth
    | S_IRWXO  | 00p007 | rwx oth
    ¦——————————¦————————¦—————————————————————————————————————
    | S_IXGRP  | 000010 | --x grp
    | S_IWGRP  | 000020 | -w- grp
    | S_IRGRP  | 000040 | r-- grp
    | S_IRWXG  | 000070 | rwx grp
    ¦——————————¦————————¦—————————————————————————————————————
    | S_IXUSR  | 000100 | --x usr
    | S_IWUSR  | 000200 | -w- usr
    | S_IRUSR  | 000400 | r-- usr
    | S_IRWXU  | 000700 | rwx usr
    ¦——————————¦————————¦—————————————————————————————————————
    | S_ISVTX  | 001000 | no delete
    | S_ISGID  | 002000 | setgid-on-exec
    | S_ISUID  | 004000 | setuid-on-exec 
    ¦——————————¦————————¦—————————————————————————————————————
    | S_IFMODE | 0xf000 |
    | S_IFIFO  | 0x1000 |
    | S_IFCHR  | 0x4000 |
    | S_IFBLK  | 0x6000 |
    | S_IFDIR  | 0x4000 |
    | S_IFREG  ¦ 0x8000 |
    | S_IFLNK  ¦ 0xA000 |
    | S_IFSOCK | 0xC000 |
    ¦——————————¦————————¦—————————————————————————————————————

    */

#pragma once

int c_iffifo(mode_t mode) {
    return S_ISFIFO(mode);
}

int c_ifblk(mode_t mode) {
    return S_ISBLK(mode);
}

int c_ifchr(mode_t mode) {
    return S_ISCHR(mode);
}

int c_ifdir(mode_t mode) {
    return S_ISDIR(mode);
}

int c_ifreg(mode_t mode) {
    return S_ISREG(mode);
}

int c_iflnk(mode_t mode) {
    return S_ISLNK(mode);
}

int c_ifsock(mode_t mode) {
    return S_ISSOCK(mode);
}

int c_typeismq(const struct stat *buf) {
#   if (_POSIX_MESSAGE_PASSING > 0)
        return S_TYPEISMQ(buf);
#   else
        return 0;
#   endif
}

int c_typeissem(const struct stat *buf) {
#   if (_POSIX_SEMAPHORES > 0)
        return S_TYPEISSEM(buf);
#   else
        return 0;
#   endif
}

int c_typeisshm(const struct stat *buf) {
#   if (_POSIX_SHARED_MEMORY > 0)
        return S_TYPEISSHM(buf);
#   else
        return 0;
#   endif
}

int c_typeistmo(const struct stat *buf) {
#   if (_POSIX_TYPED_MEMORY_OBJECTS > 0)
        return S_TYPEISTMO(buf);
#   else
        return 0;
#   endif
}

int include_sys_stat_h(Lib *self, FILE *file) {
    // File types in st_mode (S_IFMT) is [XSI]  
#   ifndef _XOPEN_UNIX
#       ifndef BLTN_MKNOD
#       define BLTN_MKNOD 0
#       endif
#       ifndef BLTN_MKNODAT
#       define BLTN_MKNODAT 0
#       endif
#   endif

#   ifndef BLTN_S_ISPIPE
#   define BLTN_S_ISPIPE c_iffifo
#   endif

#   ifndef BLTN_S_ISCHR
#   define BLTN_S_ISCHR c_ifchr
#   endif

#   ifndef BLTN_S_ISBLK
#   define BLTN_S_ISBLK c_ifblk
#   endif

#   ifndef BLTN_S_ISDIR
#   define BLTN_S_ISDIR c_ifdir
#   endif

#   ifndef BLTN_S_ISREG
#   define BLTN_S_ISREG c_ifreg
#   endif

#   ifndef BLTN_S_ISLNK
#   define BLTN_S_ISLNK c_iflnk
#   endif

#   ifndef BLTN_S_ISSOCK
#   define BLTN_S_ISSOCK c_ifsock
#   endif

#   ifndef BLTN_S_TYPEISMQ
#   define BLTN_S_TYPEISMQ c_typeismq
#   endif

#   ifndef BLTN_S_TYPEISSEM
#   define BLTN_S_TYPEISSEM c_typeissem
#   endif

#   ifndef BLTN_S_TYPEISSHM
#   define BLTN_S_TYPEISSHM c_typeisshm
#   endif

#   ifndef BLTN_S_TYPEISTMO
#   define BLTN_S_TYPEISTMO c_typeistmo
#   endif

#   ifndef BLTN_LSTAT
#   define BLTN_LSTAT lstat
#   endif

#   ifndef BLTN_STAT
#   define BLTN_STAT stat
#   endif

#   ifndef BLTN_CHMOD
#   define BLTN_CHMOD chmod
#   endif

#   ifndef BLTN_MKDIR
#   define BLTN_MKDIR mkdir
#   endif

#   ifndef BLTN_MKFIFO
#   define BLTN_MKFIFO mkfifo
#   endif

#   ifndef BLTN_MKNOD
#   define BLTN_MKNOD mknod
#   endif

#   ifndef BLTN_FCHMOD
#   define BLTN_FCHMOD fchmod
#   endif

#   ifndef BLTN_FSTAT
#   define BLTN_FSTAT fstat
#   endif

#   ifndef BLTN_FUTIMENS
#   define BLTN_FUTIMENS futimens
#   endif

#   ifdef AT_FDCWD

#       ifndef BLTN_FCHMODAT
#       define BLTN_FCHMODAT fchmodat
#       endif

#       ifndef BLTN_FSTATAT
#       define BLTN_FSTATAT fstatat
#       endif

#       ifndef BLTN_MKDIRAT
#       define BLTN_MKDIRAT mkdirat
#       endif

#       ifndef BLTN_MKFIFOAT
#       define BLTN_MKFIFOAT mkfifoat
#       endif

#       ifndef BLTN_MKNODAT
#       define BLTN_MKNODAT mknodat
#       endif

#       ifndef BLTN_UTIMENSAT
#       define BLTN_UTIMENSAT utimensat
#       endif

#   else
#       define BLTN_FCHMODAT 0
#       define BLTN_FSTATAT 0
#       define BLTN_MKDIRAT 0
#       define BLTN_MKFIFOAT 0
#       define BLTN_MKNODAT 0
#       define BLTN_UTIMENSAT 0
#   endif
#       
#   ifndef BLTN_UMASK
#   define BLTN_UMASK umask
#   endif

    self->S_ISPIPE      = BLTN_S_ISPIPE;
    self->S_ISCHR       = BLTN_S_ISCHR;
    self->S_ISBLK       = BLTN_S_ISBLK;
    self->S_ISDIR       = BLTN_S_ISDIR;
    self->S_ISREG       = BLTN_S_ISREG;
    self->S_ISLNK       = BLTN_S_ISLNK;
    self->S_ISSOCK      = BLTN_S_ISSOCK;
    self->S_TYPEISMQ    = BLTN_S_TYPEISMQ;
    self->S_TYPEISSEM   = BLTN_S_TYPEISSEM;
    self->S_TYPEISSHM   = BLTN_S_TYPEISSHM;
    self->S_TYPEISTMO   = BLTN_S_TYPEISTMO;
    self->lstat         = BLTN_LSTAT;
    self->stat          = BLTN_STAT;
    self->chmod         = BLTN_CHMOD;
    self->mkdir         = BLTN_MKDIR;
    self->mkfifo        = BLTN_MKFIFO;
    self->mknod         = BLTN_MKNOD;
    self->fchmod        = BLTN_FCHMOD;
    self->fstat         = BLTN_FSTAT;
    self->futimens      = BLTN_FUTIMENS;
    self->fchmodat      = BLTN_FCHMODAT;
    self->fstatat       = BLTN_FSTATAT;
    self->mkdirat       = BLTN_MKDIRAT;
    self->mkfifoat      = BLTN_MKFIFOAT;
    self->mknodat       = BLTN_MKNODAT;
    self->utimensat     = BLTN_UTIMENSAT;
    self->umask         = BLTN_UMASK;

    __basedef(sys_stat_h, "<sys/stat.h>")
        __dentr(enums, Enum[])
            __predef("UTIME")
                EDEF_(UTIME,NOW)
                EDEF_(UTIME,OMIT)
            __preend("P", .sort=C__VSORT)
            __predef("S")
            EDEF_(S, IROTH)
            EDEF_(S, IWOTH)
            EDEF_(S, IXOTH)
            EDEF_(S, IRWXO)
            EDEF_(S, IRGRP)
            EDEF_(S, IWGRP)
            EDEF_(S, IXGRP)
            EDEF_(S, IRWXG)
            EDEF_(S, IRUSR)
            EDEF_(S, IWUSR)
            EDEF_(S, IXUSR)
            EDEF_(S, IRWXU)
            EDEF_(S, ISGID)
            EDEF_(S, ISUID)
#       ifdef _XOPEN_UNIX
            EDEF_(S, ISVTX)
            EDEF_(S, IFMT)
            EDEF_(S, IFIFO)
            EDEF_(S, IFBLK)
            EDEF_(S, IFCHR)
            EDEF_(S, IFDIR)
            EDEF_(S, IFREG)
            EDEF_(S, IFLNK)
            EDEF_(S, IFSOCK)
 #      endif
            __preend("S", .fmt="x")
        __dexit(enums)
        __dentr(structs, Struct[])
        __memdef(stat_s)
        __member(stat_s, st_dev,    "dev_t")
        __member(stat_s, st_ino,    "ino_t")
        __member(stat_s, st_mode,   "mode_t")
        __member(stat_s, st_nlink,  "nlink_t")
        __member(stat_s, st_uid,    "uid_t")
        __member(stat_s, st_gid,    "gid_t")
        __member(stat_s, st_size,   "off_t")
        __member(stat_s, st_atim,   "timespec_s")
        __member(stat_s, st_mtim,   "timespec_s")
        __member(stat_s, st_ctim,   "timespec_s")
#       ifdef _XOPEN_UNIX
        __member(stat_s, st_rdev,   "dev_t")
        __member(stat_s, st_blksize,"blksize_t")
        __member(stat_s, st_blocks, "blkcnt_t")
#       endif
        __enddef(stat_s)
    __dexit(structs)
    __baseret(sys_stat_h)
}
