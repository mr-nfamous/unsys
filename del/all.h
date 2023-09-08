
#pragma once

// C89
#define BLTN_ASSERT_H       // C89
#define BLTN_CTYPE_H        // C89
#define BLTN_ERRNO_H        // C89
#define BLTN_FLOAT_H        // C89
#define BLTN_LIMITS_H       // C89
#define BLTN_MATH_H         // C89
#define BLTN_SETJMP_H       // C89
#define BLTN_SIGNAL_H       // C89
#define BLTN_STDIO_H        // C89
#define BLTN_STRING_H       // C89
#define BLTN_TIME_H         // C89
#define BLTN_LOCALE_H       // C89
#define BLTN_STDLIB_H       // C89
#define BLTN_STDARG_H       // C89
#define BLTN_STDDEF_H       // C89
#define BLTN_WCHAR_H        // C95
#define BLTN_ISO646_H 5     // C95
#define BLTN_WCTYPE_H       // C95
#define BLTN_FENV_H         // C99
#define BLTN_INTTYPES_H     // C99
#define BLTN_TGMATH_H       // C99
#define BLTN_COMPLEX_H      // C99*
#define BLTN_STDBOOL_H      // C99*
#define BLTN_STDINT_H       // C99*
#define BLTN_STDALIGN_H     // C11
#define BLTN_STDNORETURN_N  // C11
#define BLTN_UCHAR_H        // C11
#define BLTN_STDATOMIC_H    // C11*
#define BLTN_THREADS_H      // C11*
#define BLTN_FCNTL_H        // P1
#define BLTN_GRP_H          // P1
#define BLTN_PWD_H          // P1
#define BLTN_SEARCH_H       // P1
#define BLTN_SYS_STAT_H     // P1 
#define BLTN_SYS_TYPES_H    // P1
#define BLTN_SYS_UTSNAME_H  // P1
#define BLTN_SYS_TIMES_H    // P1
#define BLTN_LANGINFO_H     // P2
#define BLTN_DIRENT_H       // P2
#define BLTN_CPIO_H         // P3
#define BLTN_TAR_H          // P3

#define BLTN_SYS_STATVFS_H  // P4

#define BLTN_FMTMSG_H       // P4
#define BLTN_ICONV_H        // P4
#define BLTN_MONETARY_H     // P4
#define BLTN_NDBM_H         // P4
#define BLTN_STRINGS_H      // P4
#define BLTN_FTW_H          // P1

#define BLTN_STROPTS_H      // P4

#define BLTN_WORDEXP_H      // P4
#define BLTN_SYS_WAIT_H     // P3
#define BLTN_TERMIOS_H      // P3

#define BLTN_LIBGEN_H       // P4
#define BLTN_FNMATCH_H      // P4
#define BLTN_GLOB_H         // P4
#define BLTN_UTIME_H        // P3
#define BLTN_SYS_MMAN_H     // P4

#define BLTN_DLFCN_H        // P5
#define BLTN_NET_IF_H       // P6
#define BLTN_NETINET_IN_H   // P6
#define BLTN_NETINET_TCP_H  // P6
#define BLTN_SYS_SELECT_H   // P6
#define BLTN_SYS_SOCKET_H   // P6
#define BLTN_ARPA_INET_H    // P6
#define BLTN_SYS_UN_H       // P6
#define BLTN_NETDB_H        // P6
#define BLTN_POLL_H         // P6
#define BLTN_NL_TYPES_H     // P6

#ifdef _XOPEN_UNIX
#   if (_XOPEN_REALTIME > 0)
#       if (_POSIX_SPAWN > 0)
#           define BLTN_SPAWN_H     // P6
#       endif
#   endif
#   define BLTN_SYS_RESOURCE_H // P4
#   if (_XOPEN_SHM > 0)
#       define BLTN_SYS_IPC_H   // P2
#       define BLTN_SYS_MSG_H   // P2
#       define BLTN_SYS_SEM_H   // P2 
#       define BLTN_SYS_SHM_H   // P2
#   endif
#   define BLTN_SYS_TIME_H     // P4
#   define BLTN_SYS_UIO_H      // P4
#   define BLTN_SYSLOG_H       // P4
#   if _XOPEN_VERSION < 700
#       define BLTN_ULIMIT_H   // P3
#   endif
#   define BLTN_UTMPX_H        // P4
#endif

#if (_POSIX_REGEXP > 0)
#   define BLTN_REGEX_H     // P4
#endif

#if (_POSIX_THREADS > 0)
#   define BLTN_PTHREAD_H   // P5
#endif

#if (_POSIX_PRIORITY_SCHEDULING > 0)
// <sched.h> doesn't actually require [PS]... does it?
// However, sched_yield() would be all it exposed
#   define BLTN_SCHED_H         // P5 
#endif

#if (_POSIX_SEMAPHORES > 0)
#   define BLTN_SEMAPHORE_H     // P5
#endif

#if (_POSIX_MESSAGE_PASSING > 0)
#   define BLTN_MQUEUE_H        // P5
#endif

#if (_POSIX_ASYNCHRONOUS_IO > 0)
#   define BLTN_AIO_H           // P5
#endif

#if (_POSIX_TRACE > 0)
#   define BLTN_TRACE_H     // P6
#endif
