#pragma once

int include_dirent_h(Lib *self, FILE *file) {

    __basedef(dirent_h, "<dirent.h>")

    __dentr(enums, Enum[])
    __dexit(enums)

    __dentr(structs, Struct[])
        __memdef(dirent_s)
        __member(dirent_s, d_ino, "ino_t")
        __member(dirent_s, d_name, DIRENT_D_NAME)
        __enddef(dirent_s)
    __dexit(structs)
    __baseret(dirent_h)
}

int test_dirent_h(Lib *self, FILE *file) {
#   ifndef BLTN_OPENDIR
#   define BLTN_OPENDIR opendir
#   endif
#   ifndef BLTN_CLOSEDIR
#   define BLTN_CLOSEDIR closedir
#   endif
#   ifndef BLTN_REWINDDIR
#   define BLTN_REWINDDIR rewinddir
#   endif
#   ifndef BLTN_ALPHASORT
#   define BLTN_ALPHASORT alphasort
#   endif
#   ifndef BLTN_SCANDIR
#   define BLTN_SCANDIR scandir
#   endif
#   ifndef BLTN_READDIR
#   define BLTN_READDIR readdir
#   endif

#   if (_POSIX_THREAD_SAFE_FUNCTIONS > 0)
#       ifndef BLTN_READDIR_R
#       define BLTN_READDIR_R readdir_r
#       endif
        self->readdir_r = BLTN_READDIR_R;
#   endif

#   ifdef AT_FDCWD
#       ifndef BLTN_DIRFD
#       define BLTN_DIRFD dirfd
#       endif
#       ifndef BLTN_FDOPENDIR
#       define BLTN_FDOPENDIR fdopendir
#       endif
#       ifndef BLTN_SCANDIRAT
#       define BLTN_SCANDIRAT 0
#       endif
        self->dirfd     = BLTN_DIRFD;
        self->fdopendir = BLTN_FDOPENDIR;
        self->scandirat = BLTN_SCANDIRAT;
#   endif

#   ifdef _XOPEN_UNIX
#       ifndef BLTN_SEEKDIR
#       define BLTN_SEEKDIR seekdir
#       endif
#       ifndef BLTN_TELLDIR
#       define BLTN_TELLDIR telldir
#       endif
        self->seekdir   = BLTN_SEEKDIR;
        self->telldir   = BLTN_TELLDIR;
#   endif

    self->opendir   = BLTN_OPENDIR;
    self->closedir  = BLTN_CLOSEDIR;
    self->readdir   = BLTN_READDIR;
    self->rewinddir = BLTN_REWINDDIR;
    self->scandir   = BLTN_SCANDIR;
    self->alphasort = BLTN_ALPHASORT;

    return 0;
}