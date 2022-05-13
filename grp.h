#pragma once

int include_grp_h(Lib *self, FILE *file) {

    __basedef(grp_h, "<grp.h>")

    __dentr(enums, Enum[])
    __dexit(enums)

    __dentr(structs, Struct[])
        __memdef(group_s)
        __member(group_s, gr_name, "{char *}")
        __member(group_s, gr_gid, "{gid_t}")
        __member(group_s, gr_mem, "{char *}")
        __enddef(group_s)
    __dexit(structs)
    __baseret(grp_h)
}

int test_grp_h(Lib *self, FILE *file) {
#   ifdef _XOPEN_UNIX
#       ifndef BLTN_GETGRENT
#       define BLTN_GETGRENT getgrent
#       endif
#       ifndef BLTN_SETGRENT
#       define BLTN_SETGRENT setgrent
#       endif
#       ifndef BLTN_ENDGRENT
#       define BLTN_ENDGRENT endgrent
#       endif
        self->getgrent = BLTN_GETGRENT;
        self->setgrent = BLTN_SETGRENT;
        self->endgrent = BLTN_ENDGRENT;
#   endif
#   if (_POSIX_THREADSAFE_FUNCTIONS > 0)
#       ifndef BLTN_GETGRGID_R
#       define BLTN_GETGRGID_R getgrgid_r
#       endif
        self->getgrgid_r = BLTN_GETGRGID_R;
#   endif
#   ifndef BLTN_GETGRGID
#   define BLTN_GETGRGID getgrgid
#   endif
#   ifndef BLTN_GETGRNAM
#   define BLTN_GETGRNAM getgrnam
#   endif
    self->getgrgid=BLTN_GETGRGID;
    self->getgrnam=BLTN_GETGRNAM;
    return 0;
}
