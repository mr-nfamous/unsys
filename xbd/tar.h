
#pragma once

int include_tar_h(Lib *self, FILE *file) {
    __basedef(tar_h, "<tar.h>")
    __dentr(enums, Enum[])
        __predef("")
           // EREF(TMAGIC)
            EREF(TMAGLEN)
           // EREF(TVERSION)
            EREF(TVERSLEN)
            EREF(REGTYPE)
            EREF(AREGTYPE)
            EREF(LNKTYPE)
            EREF(SYMTYPE)
            EREF(CHRTYPE)
            EREF(BLKTYPE)
            EREF(DIRTYPE)
            EREF(FIFOTYPE)
            EREF(CONTTYPE)
            EREF(TSUID)
            EREF(TSGID)
            EREF(TSVTX)
            EREF(TUREAD)
            EREF(TUWRITE)
            EREF(TUEXEC)
            EREF(TGREAD)
            EREF(TGWRITE)
            EREF(TGEXEC)
            EREF(TOREAD)
            EREF(TOWRITE)
            EREF(TOEXEC)
        __preend("")
    __dexit(enums)
    __baseret(tar_h)
}