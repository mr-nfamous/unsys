#pragma once

_Thread_local char _dir[256];

char *bltn_basename(char *path) {
    return basename(path);
}
char *bltn_dirname(char *path) {
    size_t i=0, j=0, k=0;
    for ( ; path[i]; ++i)
        if (path[i] == '/')
            j = i;
    for ( ; k < j; ++k)
        _dir[k] = path[k];
    _dir[j] = 0;
    return _dir;
}

int include_libgen_h(Lib *self, FILE *file) {

    __basedef(libgen_h, "<libgen.h>")

    __baseret(libgen_h)
}

int test_libgen_h(Lib *self, FILE *file) {
#   ifndef BLTN_BASENAME
#   define BLTN_BASENAME bltn_basename
#   endif
#   ifndef BLTN_DIRNAME
#   define BLTN_DIRNAME bltn_dirname
#   endif
    self->dirname   = BLTN_DIRNAME;
    self->basename  = BLTN_BASENAME;
    return 0;
}