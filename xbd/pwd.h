#pragma once

int include_pwd_h(Lib *self, FILE *file) {

    __basedef(pwd_h, "<pwd.h>")

    __dentr(enums, Enum[])
    __dexit(enums)

    __dentr(structs, Struct[])
        __memdef(passwd_s)
        __member(passwd_s, pw_name, "char *")
        __member(passwd_s, pw_uid, "uid_t")
        __member(passwd_s, pw_gid, "gid_t")
        __member(passwd_s, pw_dir, "char *")
        __member(passwd_s, pw_shell, "char *")
#   ifdef PASSWD_PW_GECOS
        __member(passwd_s, pw_gecos, PASSWD_PW_GECOS())
#   endif
#   ifdef PASSWD_PW_PASSWD
        __member(passwd_s, pw_passwd, PASSWD_PW_PASSWD())
       
#   endif
        __enddef(passwd_s)
    __dexit(structs)
    __baseret(pwd_h)
}

int test_pwd_h(Lib *self, FILE *file) {
#   ifdef _XOPEN_UNIX
#       ifndef BLTN_GETPWENT
#       define BLTN_GETPWENT getpwent
#       endif
#       ifndef BLTN_SETPWENT
#       define BLTN_SETPWENT setpwent
#       endif
#       ifndef BLTN_ENDPWENT
#       define BLTN_ENDPWENT endpwent
#       endif
        self->getpwent=BLTN_GETPWENT;
        self->setpwent=BLTN_SETPWENT;
        self->endpwent=BLTN_ENDPWENT;
#   endif

#   if (_POSIX_THREADSAFE_FUNCTIONS > 0)
#       ifndef BLTN_GETPWNAM_R
#       define BLTN_GETPWNAM_R getpwnam_r
#       endif
#       ifndef BLTN_GETPWUID_R
#       define BLTN_GETPWUID_R getpwuid_r
#       endif
        self->getpwnam_r=BLTN_GETPWNAM_R;
        self->getpwuid_r=BLTN_GETPWUID_R;
#   endif

#   ifndef BLTN_GETPWNAM
#   define BLTN_GETPWNAM getpwnam
#   endif
#   ifndef BLTN_GETPWUID
#   define BLTN_GETPWUID getpwuid
#   endif
    self->getpwnam=BLTN_GETPWNAM;
    self->getpwuid=BLTN_GETPWUID;
    return 0;
}