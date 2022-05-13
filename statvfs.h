#pragma once

int include_sys_statvfs_h(Lib *self, FILE *file) {

    __basedef(sys_statvfs_h, "<sys/statvfs.h>")

    __dentr(enums, Enum[])
        __predef("ST")
            EDEF_(ST,NOSUID)
            EDEF_(ST,RDONLY)
#           ifdef ST_NODEV
            EDEF_(ST,NODEV)
#           endif
#           ifdef ST_NOEXEC
            EDEF_(ST,NOEXEC)
#           endif
#           ifdef ST_SYNCHRONOUS
            EDEF_(ST,SYNCHRONOUS)
#           endif
#           ifdef ST_MANDLOCK
            EDEF_(ST,MANDLOCK)
#           endif
#           ifdef ST_NOATIME
            EDEF_(ST,NOATIME)
#           endif
#           ifdef ST_NODIRATIME
            EDEF_(ST,NODIRATIME)
#           endif
#           ifdef ST_RELATIME
            EDEF_(ST,RELATIME)
#           endif
        __preend("ST", .fmt="x")
    __dexit(enums)

    __dentr(structs, Struct[])
        __memdef(statvfs_s)
        __member(statvfs_s, f_bsize, "ulong_t")
        __member(statvfs_s, f_frsize, "ulong_t")
        __member(statvfs_s, f_blocks, "fsblkcnt_t")
        __member(statvfs_s, f_bfree, "fsblkcnt_t")
        __member(statvfs_s, f_bavail, "fsblkcnt_t")
        __member(statvfs_s, f_files, "fsfilcnt_t")
        __member(statvfs_s, f_ffree, "fsfilcnt_t")
        __member(statvfs_s, f_favail, "fsfilcnt_t")
        __member(statvfs_s, f_fsid, "ulong_t")
        __member(statvfs_s, f_flag, "ulong_t")
        __member(statvfs_s, f_namemax, "ulong_t")
        __enddef(statvfs_s)
    __dexit(structs)
    __baseret(sys_statvfs_h)
}

int test_sys_statvfs_h(Lib *self, FILE *file) {
#   ifndef BLTN_STATVFS
#   define BLTN_STATVFS statvfs
#   endif
#   ifndef BLTN_FSTATVFS
#   define BLTN_FSTATVFS fstatvfs
#   endif
    self->statvfs = BLTN_STATVFS;
    self->fstatvfs = BLTN_FSTATVFS;
    return 0;
}