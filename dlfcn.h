#pragma once

int include_dlfcn_h(Lib *self, FILE *file) {

    __basedef(dlfcn_h, "<dlfcn.h>")

    __dentr(enums, Enum[])
        __predef("RTLD")
            EDEF_(RTLD,LAZY)
            EDEF_(RTLD,LOCAL)
            EDEF_(RTLD,NOW)
            EDEF_(RTLD,GLOBAL)

#           ifdef RTLD_TRACE
            EDEF_(RTLD,TRACE)
#           endif

#           ifdef RTLD_NODELETE
            EDEF_(RTLD,NODELETE)
#           endif

#           ifdef RTLD_NOLOAD
            EDEF_(RTLD,NOLOAD)
#           endif

#           ifdef RTLD_DEEPBIND
            EDEF_(RTLD,DEEPBIND)
#           endif

        __preend("RTLD",.fmt="x")
    __dexit(enums)

    __baseret(dlfcn_h)
}

int test_dlfcn_h(Lib *self, FILE *file) {

#   ifdef BLTN_DLOPENAT
#   self->dlopenat = BLTN_DLOPENAT;
#   endif

#   ifdef BLTN_FDLOPEN
#   self->fdlopen = BLTN_FDLOPEN;
#   endif

#   ifdef BLTN_DLVSYM
    self->dlvsym    = BLTN_DLVSYM;
#   endif

#   ifndef BLTN_DLCLOSE
#   define BLTN_DLCLOSE dlclose
#   endif

#   ifndef BLTN_DLERROR
#   define BLTN_DLERROR dlerror
#   endif

#   ifndef BLTN_DLOPEN
#   define BLTN_DLOPEN dlopen
#   endif

#   ifndef BLTN_DLSYM
#   define BLTN_DLSYM dlsym
#   endif

    self->dlclose   = BLTN_DLCLOSE;
    self->dlerror   = BLTN_DLERROR;
    self->dlopen    = BLTN_DLOPEN;
    self->dlsym     = BLTN_DLSYM;
    return 0;
}