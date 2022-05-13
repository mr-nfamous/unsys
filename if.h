#pragma once

int include_net_if_h(Lib *self, FILE *file) {

    __basedef(net_if_h, "<net/if.h>")

    __dentr(enums, Enum[])
        __predef("IF")
            EDEF_(IF,NAMESIZE)
        __preend("IF")
    __dexit(enums)

    __dentr(structs, Struct[])
        __memdef(if_nameindex_s)
        __member(if_nameindex_s, if_index, "unsigned")
        __member(if_nameindex_s, if_name, "cp")
        __enddef(if_nameindex_s)
    __dexit(structs)
    __baseret(net_if_h)
}

int test_net_if_h(Lib *self, FILE *file) {
#   ifndef BLTN_IF_FREENAMEINDEX
#   define BLTN_IF_FREENAMEINDEX if_freenameindex
#   endif
#   ifndef BLTN_IF_INDEXTONAME
#   define BLTN_IF_INDEXTONAME if_indextoname
#   endif
#   ifndef BLTN_IF_NAMEINDEX
#   define BLTN_IF_NAMEINDEX if_nameindex
#   endif
#   ifndef BLTN_IF_NAMETOINDEX
#   define BLTN_IF_NAMETOINDEX if_nametoindex
#   endif
    self->if_freenameindex  = BLTN_IF_FREENAMEINDEX;
    self->if_indextoname    = BLTN_IF_INDEXTONAME;
    self->if_nametoindex    = BLTN_IF_NAMETOINDEX;
    self->if_nameindex      = BLTN_IF_NAMEINDEX;
    return 0;
}