
#pragma once

int include_setjmp_h(Lib *self, FILE *file) {

    __basedef(setjmp_h, "<setjmp.h>")

    __dentr(enums, Enum[])
    __dexit(enums)

    __dentr(structs, Struct[])
    __dexit(structs)
    __baseret(setjmp_h)
}

int test_setjmp_h(Lib *self, FILE *file) {
#   if (_XOPEN_VERSION > 0)
#       if (_XOPEN_VERSION == 700)
#           ifndef BLTN__LONGJMP
#           define BLTN__LONGJMP 0
#           endif
#           ifndef BLTN__SETJMP
#           define BLTN__SETJMP 0
#           endif
#       else
#           ifndef BLTN__LONGJMP
#           define BLTN__LONGJMP _longjmp 
#           endif
#           ifndef BLTN__SETJMP
#           define BLTN__SETJMP _setjmp
#           endif
#       endif
        self->_longjmp = BLTN__LONGJMP;
        self->_setjmp  = BLTN__SETJMP;
#   endif
#   if (_POSIX_VERSION > 0)
#       ifndef BLTN_SIGLONGJMP
#       define BLTN_SIGLONGJMP siglongjmp
#       endif
#       ifndef BLTN_SIGSETJMP
#       define BLTN_SIGSETJMP sigsetjmp
#       endif
        self->siglongjmp = BLTN_SIGLONGJMP;
        self->sigsetjmp  = BLTN_SIGSETJMP;
#   endif
#   ifndef BLTN_SETJMP
#   define BLTN_SETJMP setjmp
#   endif
#   ifndef BLTN_LONGJMP
#   define BLTN_LONGJMP longjmp
#   endif
    self->longjmp = BLTN_LONGJMP;
    self->setjmp  = BLTN_SETJMP;
    return 0;
}