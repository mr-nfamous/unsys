
#pragma once


int include_ftw_h(Lib *self, FILE *file) {

#   ifndef BLTN_FTW
#   define BLTN_FTW 0
#   endif

#   ifndef BLTN_NFTW
#   define BLTN_NFTW nftw
#   endif

    self->ftw   = BLTN_FTW;
    self->nftw  = BLTN_NFTW;

    __basedef(ftw_h, "<ftw.h>")

    __dentr(enums, Enum[])
        __predef("FTW")
            EDEF_(FTW,F)        // nondir
            EDEF_(FTW,D)        // dir
            EDEF_(FTW,DNR)      // private dir
            EDEF_(FTW,DP)       // leaf dir
            EDEF_(FTW,NS)       // stat failed
            EDEF_(FTW,SL)       // symlink
            EDEF_(FTW,SLN)      // dead symlink
        __preend("FTW", .sort=C__VSORT)
        __predef("FTW")
            EDEF_(FTW,PHYS)     // nondir
            EDEF_(FTW,MOUNT)    // dir
            EDEF_(FTW,DEPTH)    // private dir
            EDEF_(FTW,CHDIR)    // leaf dir         
        __preend("FTW", .fmt="x", .sort=C__VSORT)
    __dexit(enums)

    __dentr(structs, Struct[])
        __memdef(ftw_s)
        __member(ftw_s, base, "int")
        __member(ftw_s, level, "int")
        __enddef(ftw_s)
    __dexit(structs)
    __baseret(ftw_h)
}