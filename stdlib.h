#pragma once

int include_stdlib_h(Lib *self, FILE *file) {

    __basedef(stdlib_h, "<stdlib.h>")

    __dentr(enums, Enum[])
        __predef("EXIT")
            EDEF_(EXIT,SUCCESS)
            EDEF_(EXIT,FAILURE)
        __preend("EXIT", .fmt="x")
        __predef("")
            EREF(RAND_MAX)
            EREF(MB_CUR_MAX)
        __preend("")

    __dexit(enums)

    __dentr(structs, Struct[])
        __memdef(div_t)
        __member(div_t, quot,"{int_t}")
        __member(div_t, rem, "{int_t}")
        __enddef(div_t)
        __memdef(ldiv_t)
        __member(ldiv_t, quot,"{long_t}")
        __member(ldiv_t, rem, "{long_t}")
        __enddef(ldiv_t)
        __memdef(lldiv_t)
        __member(lldiv_t, quot,"{llong_t}")
        __member(lldiv_t, rem, "{llong_t}")
        __enddef(lldiv_t)
    __dexit(structs)
    __baseret(stdlib_h)
}

int test_stdlib_h(Lib *self, FILE *file) {
#   ifndef BLTN__EXIT
#   define BLTN__EXIT _Exit
#   endif
#   ifndef BLTN_ABORT
#   define BLTN_ABORT abort
#   endif
#   ifndef BLTN_EXIT
#   define BLTN_EXIT exit
#   endif
#   ifndef BLTN_FREE
#   define BLTN_FREE free
#   endif
#   ifndef BLTN_LCONG48
#   define BLTN_LCONG48 lcong48
#   endif
#   ifndef BLTN_QSORT
#   define BLTN_QSORT qsort
#   endif
#   ifndef BLTN_SETKEY
#   define BLTN_SETKEY setkey
#   endif
#   ifndef BLTN_SRAND
#   define BLTN_SRAND srand
#   endif
#   ifndef BLTN_SRAND48
#   define BLTN_SRAND48 srand48
#   endif
#   ifndef BLTN_SRANDOM
#   define BLTN_SRANDOM srandom
#   endif
#   ifndef BLTN_ABS
#   define BLTN_ABS abs
#   endif
#   ifndef BLTN_ATEXIT
#   define BLTN_ATEXIT atexit
#   endif
#   ifndef BLTN_ATOI
#   define BLTN_ATOI atoi
#   endif
#   ifndef BLTN_GETSUBOPT
#   define BLTN_GETSUBOPT getsubopt
#   endif
#   ifndef BLTN_GRANTPT
#   define BLTN_GRANTPT grantpt
#   endif
#   ifndef BLTN_MBLEN
#   define BLTN_MBLEN mblen
#   endif
#   ifndef BLTN_MBTOWC
#   define BLTN_MBTOWC mbtowc
#   endif
#   ifndef BLTN_MKSTEMP
#   define BLTN_MKSTEMP mkstemp
#   endif
#   ifndef BLTN_POSIX_MEMALIGN
#   define BLTN_POSIX_MEMALIGN posix_memalign
#   endif
#   ifndef BLTN_POSIX_OPENPT
#   define BLTN_POSIX_OPENPT posix_openpt
#   endif
#   ifndef BLTN_PUTENV
#   define BLTN_PUTENV putenv
#   endif
#   ifndef BLTN_RAND
#   define BLTN_RAND rand
#   endif
#   ifndef BLTN_RAND_R
#   define BLTN_RAND_R rand_r
#   endif
#   ifndef BLTN_SETENV
#   define BLTN_SETENV setenv
#   endif
#   ifndef BLTN_SYSTEM
#   define BLTN_SYSTEM system
#   endif
#   ifndef BLTN_UNLOCKPT
#   define BLTN_UNLOCKPT unlockpt
#   endif
#   ifndef BLTN_UNSETENV
#   define BLTN_UNSETENV unsetenv
#   endif
#   ifndef BLTN_WCTOMB
#   define BLTN_WCTOMB wctomb
#   endif
#   ifndef BLTN_ATOF
#   define BLTN_ATOF atof
#   endif
#   ifndef BLTN_DRAND48
#   define BLTN_DRAND48 drand48
#   endif
#   ifndef BLTN_ERAND48
#   define BLTN_ERAND48 erand48
#   endif
#   ifndef BLTN_A64L
#   define BLTN_A64L a64l
#   endif
#   ifndef BLTN_ATOL
#   define BLTN_ATOL atol
#   endif
#   ifndef BLTN_JRAND48
#   define BLTN_JRAND48 jrand48
#   endif
#   ifndef BLTN_LABS
#   define BLTN_LABS labs
#   endif
#   ifndef BLTN_LRAND48
#   define BLTN_LRAND48 lrand48
#   endif
#   ifndef BLTN_MRAND48
#   define BLTN_MRAND48 mrand48
#   endif
#   ifndef BLTN_NRAND48
#   define BLTN_NRAND48 nrand48
#   endif
#   ifndef BLTN_RANDOM
#   define BLTN_RANDOM random
#   endif
#   ifndef BLTN_STRTOL
#   define BLTN_STRTOL strtol
#   endif
#   ifndef BLTN_ATOLL
#   define BLTN_ATOLL atoll
#   endif
#   ifndef BLTN_LLABS
#   define BLTN_LLABS llabs
#   endif
#   ifndef BLTN_STRTOLL
#   define BLTN_STRTOLL strtoll
#   endif
#   ifndef BLTN_BSEARCH
#   define BLTN_BSEARCH bsearch
#   endif
#   ifndef BLTN_CALLOC
#   define BLTN_CALLOC calloc
#   endif
#   ifndef BLTN_MALLOC
#   define BLTN_MALLOC malloc
#   endif
#   ifndef BLTN_REALLOC
#   define BLTN_REALLOC realloc
#   endif
#   ifndef BLTN_GETENV
#   define BLTN_GETENV getenv
#   endif
#   ifndef BLTN_INITSTATE
#   define BLTN_INITSTATE initstate
#   endif
#   ifndef BLTN_L64A
#   define BLTN_L64A l64a
#   endif
#   ifndef BLTN_MKDTEMP
#   define BLTN_MKDTEMP mkdtemp
#   endif
#   ifndef BLTN_PTSNAME
#   define BLTN_PTSNAME ptsname
#   endif
#   ifndef BLTN_REALPATH
#   define BLTN_REALPATH realpath
#   endif
#   ifndef BLTN_SETSTATE
#   define BLTN_SETSTATE setstate
#   endif
#   ifndef BLTN_DIV
#   define BLTN_DIV div
#   endif
#   ifndef BLTN_LDIV
#   define BLTN_LDIV ldiv
#   endif
#   ifndef BLTN_LLDIV
#   define BLTN_LLDIV lldiv
#   endif
#   ifndef BLTN_STRTOUL
#   define BLTN_STRTOUL strtoul
#   endif
#   ifndef BLTN_STRTOULL
#   define BLTN_STRTOULL strtoull
#   endif
#   ifndef BLTN_WCSTOMBS
#   define BLTN_WCSTOMBS wcstombs
#   endif
#   ifndef BLTN_MBSTOWCS
#   define BLTN_MBSTOWCS mbstowcs
#   endif
#   ifndef BLTN_SEED48
#   define BLTN_SEED48 seed48
#   endif
#   ifndef BLTN_STRTOD
#   define BLTN_STRTOD strtod
#   endif
#   ifndef BLTN_STRTOF
#   define BLTN_STRTOF strtof
#   endif

#   ifndef BLTN_STRTOLD
#   define BLTN_STRTOLD strtold
#   endif
    
    self->_Exit     = BLTN__EXIT;
    self->abort     = BLTN_ABORT;
    self->exit      = BLTN_EXIT;
    self->free      = BLTN_FREE;
    self->lcong48   = BLTN_LCONG48;
    self->qsort     = BLTN_QSORT;
    self->setkey    = BLTN_SETKEY;
    self->srand     = BLTN_SRAND;
    self->srand48   = BLTN_SRAND48;
    self->srandom   = BLTN_SRANDOM;
    self->abs       = BLTN_ABS;
    self->atexit    = BLTN_ATEXIT;
    self->atoi      = BLTN_ATOI;
    self->getsubopt = BLTN_GETSUBOPT;
    self->grantpt   = BLTN_GRANTPT;
    self->mblen     = BLTN_MBLEN;
    self->mbtowc    = BLTN_MBTOWC;
    self->mkstemp   = BLTN_MKSTEMP;
    //self->posix_memalign= BLTN_POSIX_MEMALIGN;
    //self->posix_openpt= BLTN_POSIX_OPENPT;
    self->putenv    = BLTN_PUTENV;
    self->rand      = BLTN_RAND;
    self->rand_r    = BLTN_RAND_R;
    self->setenv    = BLTN_SETENV;
    self->system    = BLTN_SYSTEM;
    self->unlockpt  = BLTN_UNLOCKPT;
    self->unsetenv  = BLTN_UNSETENV;
    self->wctomb    = BLTN_WCTOMB;
    self->atof      = BLTN_ATOF;
    self->drand48   = BLTN_DRAND48;
    self->erand48   = BLTN_ERAND48;
    self->a64l      = BLTN_A64L;
    self->atol      = BLTN_ATOL;
    self->jrand48   = BLTN_JRAND48;
    self->labs      = BLTN_LABS;
    self->lrand48   = BLTN_LRAND48;
    self->mrand48   = BLTN_MRAND48;
    self->nrand48   = BLTN_NRAND48;
    self->random    = BLTN_RANDOM;
    self->strtol    = BLTN_STRTOL;
    self->atoll     = BLTN_ATOLL;
    self->llabs     = BLTN_LLABS;
    self->strtoll   = BLTN_STRTOLL;
    self->bsearch   = BLTN_BSEARCH;
    self->calloc    = BLTN_CALLOC;
    self->malloc    = BLTN_MALLOC;
    self->realloc   = BLTN_REALLOC;
    self->getenv    = BLTN_GETENV;
    self->initstate = BLTN_INITSTATE;
    self->l64a      = BLTN_L64A;
    self->mkdtemp   = BLTN_MKDTEMP;
    self->ptsname   = BLTN_PTSNAME;
    self->realpath  = BLTN_REALPATH;
    self->setstate  = BLTN_SETSTATE;
    self->div       = BLTN_DIV;
    self->ldiv      = BLTN_LDIV;
    self->lldiv     = BLTN_LLDIV;
    self->strtoul   = BLTN_STRTOUL;
    self->strtoull  = BLTN_STRTOULL;
    self->wcstombs  = BLTN_WCSTOMBS;
    self->mbstowcs  = BLTN_MBSTOWCS;
    self->seed48    = BLTN_SEED48;
    self->strtod    = BLTN_STRTOD;
    self->strtof    = BLTN_STRTOF;
    self->strtold   = BLTN_STRTOLD;

    return 0;
}