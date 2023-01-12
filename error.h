/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#pragma once

#include "unstddef.h"

static inline const char *
errno_NAME(int err) {
#define errno_NAME(e) case e: return #e
    switch (err) {
    // This first batch of errno values are numerically equal
    // on all known platforms (not that this should matter)
    errno_NAME(E2BIG);  //  7  ARG_MAX exceeded
    errno_NAME(EACCES); //  13
    errno_NAME(EBADF);  //  9
    errno_NAME(ECHILD); //  10
    errno_NAME(EDOM);   //  33
    errno_NAME(EFAULT); //  14
    errno_NAME(EEXIST); //  17
    errno_NAME(EFBIG);  //  27
    errno_NAME(EBUSY);  //  16
    errno_NAME(EINTR);  //  4   Interrupted by signal handler
    errno_NAME(EINVAL); //  22
    errno_NAME(EIO);    //  5
    errno_NAME(EISDIR); //  21
    errno_NAME(EMFILE); //  24  // OPEN_MAX exceeded
    errno_NAME(EMLINK); //  31  // LINK_MAX exceeded
    errno_NAME(ENFILE); //  23
    errno_NAME(ENODEV); //  19
    errno_NAME(ENOENT); //  2
    errno_NAME(ENOEXEC);//  8
    errno_NAME(ENOMEM); //  12
    errno_NAME(ENOSPC); //  28
    errno_NAME(ENOTDIR);//  20  // not S_ISDIR(stat.st_mode)
    errno_NAME(ENOTTY); //  25  // not isatty(fd)
    errno_NAME(ENXIO);  //  6
    errno_NAME(EPERM);  //  1
    errno_NAME(EPIPE);  //  32
    errno_NAME(ERANGE); //  34
    errno_NAME(EROFS);  //  30
    errno_NAME(ESPIPE); //  29
    errno_NAME(ESRCH);  //  3
    errno_NAME(EXDEV);  //  18
    // The remaining POSIX errno values which are numerically
    // unique for each platform 
    //                              W   L   D
    errno_NAME(EBADMSG);//          104 74  94
    errno_NAME(ELOOP);  //          114 40  62
    errno_NAME(EADDRINUSE); //      100 98  48
    errno_NAME(EADDRNOTAVAIL); //   101 99  49
    errno_NAME(EAFNOSUPPORT); //    102 97  47
    errno_NAME(EAGAIN); //          11  11  35
    errno_NAME(EALREADY); //        103 114 37
    errno_NAME(ECANCELED); //       105 125 89
    errno_NAME(ECONNABORTED); //    106 103 53
    errno_NAME(ECONNREFUSED); //    107 111 61
    errno_NAME(ECONNRESET); //      108 102 54
    errno_NAME(EDEADLK); //         36  35  11
    errno_NAME(EDESTADDRREQ); //    109 89  39
    errno_NAME(EHOSTUNREACH); //    110 113 65
    errno_NAME(EIDRM); //           111 43  90
    errno_NAME(EILSEQ); //          42  84  92
    errno_NAME(EINPROGRESS); //     112 115 36
    errno_NAME(EISCONN); //         113 106 56
    errno_NAME(EPROTO); //          134 71  41
    errno_NAME(EPROTONOSUPPORT); // 135 93  43
    errno_NAME(EPROTOTYPE); //      136 91  41
    errno_NAME(ETIME); //           137 62  102
    errno_NAME(ETIMEDOUT); //       138 110 60
    errno_NAME(ETXTBSY); //         139 26  26
#if EWOULDBLOCK != EAGAIN
    errno_NAME(EWOULDBLOCK); //     140 11  35
#endif
    errno_NAME(EMSGSIZE); //        115 90  40
    errno_NAME(ENAMETOOLONG); //    38  36  63
    errno_NAME(ENETDOWN); //        116 100 50
    errno_NAME(ENETRESET); //       117 102 52
    errno_NAME(ENETUNREACH); //     118 101 51
    errno_NAME(ENOBUFS); //         119 105 55
    errno_NAME(ENODATA); //         120 61  96
    errno_NAME(ENOLINK); //         121 67  31
    errno_NAME(ENOLCK); //          39  37  77
    errno_NAME(ENOMSG); //          122 42  91
    errno_NAME(ENOPROTOOPT); //     123 92  42
    errno_NAME(ENOSR); //           124 63  98
    errno_NAME(ENOSTR); //          125 60  99
    errno_NAME(ENOSYS); //          40  38  78 
    errno_NAME(ENOTCONN); //        126 107 57
    errno_NAME(ENOTEMPTY); //       41  39  66
    errno_NAME(ENOTRECOVERABLE); // 127 131 104
    errno_NAME(ENOTSOCK); //        128 88  38
    errno_NAME(EOVERFLOW); //       132 75  84
    errno_NAME(EOWNERDEAD); //      133 130 105
// Windows exclusive 
#   ifdef _WIN32                 // ### ### ###
    errno_NAME(EOTHER); //          131 0   0
#   else                        //  ### ### ###
    errno_NAME(EDQUOT); //          0   122 69
    errno_NAME(EMULTIHOP); //       0   72  95
    errno_NAME(EHOSTDOWN); //       0   112 64
    errno_NAME(ENOTBLK); //         0   15  15
    errno_NAME(EPFNOSUPPORT); //    0   96  46
    errno_NAME(ESOCKTNOSUPPORT); // 0   94  44
    errno_NAME(ESHUTDOWN); //       0   108 58
    errno_NAME(ESTALE); //          0   116 70
    errno_NAME(ETOOMANYREFS); //    0   109 59
    errno_NAME(EUSERS); //          0   87  68
    //errno_NAME(EREMOTE); //       0   66  71
#   endif
                                //  ### ### ###
// Darwin exclusive 
#   ifdef __APPLE__
    errno_NAME(EAUTH); //           0   0   80
    errno_NAME(EBADARCH); //        0   0   86
    errno_NAME(EBADEXEC); //        0   0   85
    errno_NAME(EBADMACHO); //       0   0   88
    errno_NAME(EBADRPC); //         0   0   72
    errno_NAME(EDEVERR); //         0   0   83
    errno_NAME(EFTYPE); //          0   0   79
    errno_NAME(ELAST); //           0   0   106
    errno_NAME(ENEEDAUTH); //       0   0   81
    errno_NAME(ENOATTR); //         0   0   93
    errno_NAME(EPWROFF); //         0   0   82
    errno_NAME(ESHLIBVERS); //      0   0   87
    errno_NAME(EPROCLIM); //        0   0   67
    errno_NAME(EPROCUNAVAIL); //    0   0   76
    errno_NAME(EPROGMISMATCH); //   0   0   75
    errno_NAME(EPROGUNAVAIL); //    0   0   74
    errno_NAME(EREMCHG); //         0   0   78
    errno_NAME(EQFULL); //          0   0   106
    errno_NAME(EREMOTEIO); //       0   0   121
    errno_NAME(ERESTART); //        0   0   85
    errno_NAME(ERFKILL); //         0   0   132
    errno_NAME(ERPCMISMATCH); //    0   0   73
    #else // defined(_WIN32) || defined(__linux__)

    #endif
    //                              ### ### ###
    #ifdef __linux__
    errno_NAME(EADV); //            0   68  0
    errno_NAME(EBADE); //           0   52  0
    errno_NAME(EBADFD); //          0   71  0
    errno_NAME(EBADR); //           0   53  0
    errno_NAME(EBADRQC); //         0   56  0
    errno_NAME(EBADSLT); //         0   57  0
    errno_NAME(EBFONT); //          0   59  0
    errno_NAME(ECHRNG); //          0   44  0
    errno_NAME(ECOMM); //           0   70  0
    errno_NAME(EDOTDOT); //         0   73  0
    errno_NAME(EHWPOISON); //       0   133 0
    errno_NAME(EISNAM); //          0   120 0
    errno_NAME(EKEYREJECTED); //    0   129 0
    errno_NAME(EKEYEXPIRED); //     0   127 0
    errno_NAME(EKEYREVOKED); //     0   128 0
    errno_NAME(EL2NSYNC); //        0   45  0
    errno_NAME(EL3HLT); //          0   46  0
    errno_NAME(EL3RST); //          0   47  0
    errno_NAME(ELNRNG); //          0   48  0
    errno_NAME(EL2HLT); //          0   51  0
    errno_NAME(ELIBACC); //         0   79  0
    errno_NAME(ELIBBAD); //         0   80  0
    errno_NAME(ELIBEXEC); //        0   83  0
    errno_NAME(ELIBMAX); //         0   82  0
    errno_NAME(ELIBSCN); //         0   81  0
    errno_NAME(EMEDIUMTYPE); //     0   124 0
    errno_NAME(ENAVAIL); //         0   119 0
    errno_NAME(ENOTNAM); //         0   118 0
    errno_NAME(ENOTUNIQ); //        0   76  0
    errno_NAME(ENOKEY); //          0   126 0
    errno_NAME(ENOMEDIUM); //       0   123 0
    errno_NAME(ENOANO); //          0   55  0
    errno_NAME(ENOCSI); //          0   50  0
    errno_NAME(ENONET); //          0   64  0
    errno_NAME(ENOPKG); //          0   65  0
    errno_NAME(ESTRPIPE); //        0   86  0
    errno_NAME(ESRMNT); //          0   69  0
    errno_NAME(EUCLEAN); //         0   117 0
    errno_NAME(EUNATCH); //         0   49  0
    errno_NAME(EXFULL); //          0   54  0
#else // defined(_WIN32) || defined(__linux__)
#endif
#undef errno_NAME
    default: return "<INVALID ERRNO>";
    }
}

static inline void 
FPERROR_CALL(FILE *dst, const char *src, const char *fn, int ln) {
    (void) fprintf(
        !dst ? stdout : dst,
        "errno set to %s (%d), on line %d of %s (in function %s)",
        errno_NAME(errno), (errno),
        ln, src,
        fn
    );
}

#define FPERROR(d) FPERROR_CALL(d,__FILE__,__func__,__LINE__)
#define  PERROR()  FPERROR_CALL(stdout,__FILE__,__func__,__LINE__)

#define FPERROR_EXIT(d,y) FPERROR(d), exit(y)
#define  PERROR_EXIT(y)    PERROR(),  exit(y)
