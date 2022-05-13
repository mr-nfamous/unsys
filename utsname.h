#pragma once

int include_sys_utsname_h(Lib *self, FILE *file) {

    __basedef(sys_utsname_h, "<sys/utsname.h>")

    __dentr(enums, Enum[])
        __predef("")
            EREF(SYS_NMLN)
        __preend("")
    __dexit(enums)

    __dentr(structs, Struct[])
        __memdef(utsname_s)
        __member(utsname_s, sysname, "char[{SYS_NMLN}]")
        __member(utsname_s, nodename, "char[{SYS_NMLN}]")
        __member(utsname_s, release, "char[{SYS_NMLN}]")
        __member(utsname_s, version, "char[{SYS_NMLN}]")
        __member(utsname_s, machine, "char[{SYS_NMLN}]")
        __enddef(utsname_s)
    __dexit(structs)
    __baseret(sys_utsname_h)
}

int test_sys_utsname_h(Lib *self, FILE *file) {
#   ifndef BLTN_UNAME
#   define BLTN_UNAME uname
#   endif

    self->uname = BLTN_UNAME;
    return 0;
}