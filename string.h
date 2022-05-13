#pragma once

int include_string_h(Lib *self, FILE *file) {

    __basedef(string_h, "<string.h>")

    __dentr(enums, Enum[])
    __dexit(enums)

    __dentr(structs, Struct[])
    __dexit(structs)
    __baseret(string_h)
}

int test_string_h(Lib *self, FILE *file) {
#   ifndef BLTN_MEMCHR
#   define BLTN_MEMCHR memchr
#   endif
#   ifndef BLTN_MEMSET
#   define BLTN_MEMSET memset
#   endif
#   ifndef BLTN_MEMCCPY
#   define BLTN_MEMCCPY memccpy
#   endif
#   ifndef BLTN_MEMCPY
#   define BLTN_MEMCPY memcpy
#   endif
#   ifndef BLTN_MEMMOVE
#   define BLTN_MEMMOVE memmove
#   endif
#   ifndef BLTN_STPCPY
#   define BLTN_STPCPY stpcpy
#   endif
#   ifndef BLTN_STPNCPY
#   define BLTN_STPNCPY stpncpy
#   endif
#   ifndef BLTN_STRCAT
#   define BLTN_STRCAT strcat
#   endif
#   ifndef BLTN_STRCHR
#   define BLTN_STRCHR strchr
#   endif
#   ifndef BLTN_STRCPY
#   define BLTN_STRCPY strcpy
#   endif
#   ifndef BLTN_STRDUP
#   define BLTN_STRDUP strdup
#   endif
#   ifndef BLTN_STRERROR
#   define BLTN_STRERROR strerror
#   endif
#   ifndef BLTN_STRERROR_L
#   define BLTN_STRERROR_L strerror_l
#   endif
#   ifndef BLTN_STRNCAT
#   define BLTN_STRNCAT strncat
#   endif
#   ifndef BLTN_STRNCPY
#   define BLTN_STRNCPY strncpy
#   endif
#   ifndef BLTN_STRNDUP
#   define BLTN_STRNDUP strndup
#   endif
#   ifndef BLTN_STRPBRK
#   define BLTN_STRPBRK strpbrk
#   endif
#   ifndef BLTN_STRRCHR
#   define BLTN_STRRCHR strrchr
#   endif
#   ifndef BLTN_STRSIGNAL
#   define BLTN_STRSIGNAL strsignal
#   endif
#   ifndef BLTN_STRSTR
#   define BLTN_STRSTR strstr
#   endif
#   ifndef BLTN_STRTOK
#   define BLTN_STRTOK strtok
#   endif
#   ifndef BLTN_STRTOK_R
#   define BLTN_STRTOK_R strtok_r
#   endif
#   ifndef BLTN_MEMCMP
#   define BLTN_MEMCMP memcmp
#   endif
#   ifndef BLTN_STRCMP
#   define BLTN_STRCMP strcmp
#   endif
#   ifndef BLTN_STRCOLL
#   define BLTN_STRCOLL strcoll
#   endif
#   ifndef BLTN_STRCOLL_L
#   define BLTN_STRCOLL_L strcoll_l
#   endif
#   ifndef BLTN_STRERROR_R
#   define BLTN_STRERROR_R strerror_r
#   endif
#   ifndef BLTN_STRNCMP
#   define BLTN_STRNCMP strncmp
#   endif
#   ifndef BLTN_STRCSPN
#   define BLTN_STRCSPN strcspn
#   endif
#   ifndef BLTN_STRLEN
#   define BLTN_STRLEN strlen
#   endif
#   ifndef BLTN_STRNLEN
#   define BLTN_STRNLEN strnlen
#   endif
#   ifndef BLTN_STRSPN
#   define BLTN_STRSPN strspn
#   endif
#   ifndef BLTN_STRXFRM
#   define BLTN_STRXFRM strxfrm
#   endif
#   ifndef BLTN_STRXFRM_L
#   define BLTN_STRXFRM_L strxfrm_l
#   endif
    self->memchr    = BLTN_MEMCHR;
    self->memset    = BLTN_MEMSET;
    self->memcpy    = BLTN_MEMCPY;
    self->memmove   = BLTN_MEMMOVE;
    self->strcat    = BLTN_STRCAT;
    self->strchr    = BLTN_STRCHR;
    self->strcpy    = BLTN_STRCPY;
    self->strerror  = BLTN_STRERROR;
    self->strncat   = BLTN_STRNCAT;
    self->strncpy   = BLTN_STRNCPY;
    self->strpbrk   = BLTN_STRPBRK;
    self->strrchr   = BLTN_STRRCHR;
    self->strstr    = BLTN_STRSTR;
    self->strtok    = BLTN_STRTOK;
    self->memcmp    = BLTN_MEMCMP;
    self->strcmp    = BLTN_STRCMP;
    self->strcoll   = BLTN_STRCOLL;
    self->strncmp   = BLTN_STRNCMP;
    self->strcspn   = BLTN_STRCSPN;
    self->strlen    = BLTN_STRLEN;
    self->strspn    = BLTN_STRSPN;
    self->strxfrm   = BLTN_STRXFRM;

#   if (_POSIX_VERSION >= 200809L)
    self->memccpy   = BLTN_MEMCCPY;
    self->stpcpy    = BLTN_STPCPY;
    self->stpncpy   = BLTN_STPNCPY;
    self->strdup    = BLTN_STRDUP;
    self->strndup   = BLTN_STRNDUP;
    self->strsignal = BLTN_STRSIGNAL;
    self->strnlen   = BLTN_STRNLEN;

#   if (_POSIX_MULTI_CONCURRENT_LOCALE > 0)
    self->strxfrm_l = BLTN_STRXFRM_L;
    self->strerror_l= BLTN_STRERROR_L;
    self->strcoll_l = BLTN_STRCOLL_L;
#   endif

#   if (_POSIX_THREADSAFE_FUNCTIONS > 0)
    self->strerror_r= BLTN_STRERROR_R;
    self->strtok_r  = BLTN_STRTOK_R;
#   endif

#   endif // _POSIX_VERSION > 200809L

    return 0;
}