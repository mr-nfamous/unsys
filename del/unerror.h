
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

#pragma once

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static const char *UN_CAUSE = NULL;

#ifdef SIGUSR1
static int UN_SIGEXC = SIGUSR1;
#else
static int UN_SIGEXC = SIGILL;
#endif

static void 
unthrow(int err, const char *msg,  ...) {
    va_list va;
    if (err != 0) {
        if (errno == 0) {
            errno = err;
        }
        else if (err != errno) {
            (void) fprintf(stderr, "unthrow: multiple errors detected");
            goto the_end;
        }
    }
    else {
        if (errno == 0) {
            errno = EINVAL;
        }
    }
    if (msg == NULL) {
        if (UN_CAUSE != NULL) {
            perror(UN_CAUSE);
        }
        else if (strerror(errno)) {
            perror("no cause specified");
        }
        else {
            (void) fprintf(stderr, "invalid errno: %d", errno);
            goto the_end;
        }
    }
    else {
        va_start(va, msg);
        if (vfprintf(stderr, msg, va) < 0) {
            perror("vfprintf failed");
        }
        va_end(va);
    }
    the_end: {
        raise(UN_SIGEXC);
    }
}

static inline void
UNABORT(const char *src, size_t lno, const char *msg) {
    if (msg != NULL) {
        if (!strnlen(msg, 1)) {
            msg = NULL;
        }
    }
    if (msg == NULL) {
        msg = strerror(errno ? errno : EINVAL);
    } 
    (void)
    (printf)
    ("called abort on line #%zu in file %s: (%s)\n", lno, src, msg);
    abort();
}

#define unabort(...) UNABORT(__FILE__, __LINE__, "" #__VA_ARGS__)

static inline void *
unexc_ERANGE(const char *msg) {
    UN_CAUSE = msg;
    errno = ERANGE;
    return NULL;
}
