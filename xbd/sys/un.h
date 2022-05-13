#pragma once

int include_sys_un_h(Lib *self, FILE *file) {

    __basedef(sys_un_h, "<sys_un.h>")

    __dentr(enums, Enum[])
        __predef("")
            EREF(UNIX_PATH_MAX)
        __preend("")
    __dexit(enums)

    __dentr(structs, Struct[])
        __memdef(sockaddr_un_s)
        __member(sockaddr_un_s, sun_family, "{sa_family_t}")
        __member(sockaddr_un_s, sun_family, "{char[{UNIX_PATH_MAX}]}")
        __enddef(sockaddr_un_s)
    __dexit(structs)
    __baseret(sys_un_h)
}
