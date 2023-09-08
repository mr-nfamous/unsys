
#pragma once

#include <dirent.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <linux/mqueue.h>
#include <net/if_packet.h>

#define PASSWD_PW_GECOS() "char *"
#define PASSWD_PW_PASSWD() "char *"

#define DIRENT_D_NAME "char[256]"
#define O_EXEC O_PATH
#define O_SEARCH O_PATH
#define O_TTY_INIT 0

#define _POSIX_FILE_LOCKING _POSIX_VERSION
#define _POSIX_MULTI_CURRENT_LOCALE _POSIX_VERSION
// Android/bionic doesn't define the following headers
#undef BLTN_FMTMSG_H
#undef BLTN_MONETARY_H
#undef BLTN_UTMPX_H
#undef BLTN_ULIMIT_H
#undef BLTN_STROPTS_H
#undef BLTN_WORDEXP_H
#undef BLTN_NDBM_H

typedef int     
    (*glob_errfunc_f)(const char *, int),
    (*glob_lstat_f)(const char *, struct stat *),
    (*glob_stat_f)(const char *, struct stat *);
typedef void    
    (*glob_closedir_f)(void *),
   *(*glob_opendir_f)(const char *);
typedef struct dirent
   *(*glob_readdir_f)(void *);

#define EXTENDED_GLOB_T() \
    __member(glob_t, gl_flags, "{int}")\
    __member(glob_t, gl_closedir, "{glob_closedir_f}")\
    __member(glob_t, gl_errfunc, "{glob_errfunc_f}")\
    __member(glob_t, gl_readdir, "{glob_readdir_f}")\
    __member(glob_t, gl_opendir, "{glob_opendir_f}")\
    __member(glob_t, gl_lstat, "{glob_lstat_f}")\
    __member(glob_t, gl_stat, "{glob_stat_f}")


// <netdb.h>
#ifndef NI_NUMERICSCOPE
#define NI_NUMERICSCOPE -1
#endif
// Android (wisely) doesn't implement pthread_cancel
#define BLTN_PTHREAD_CANCEL 0
#define BLTN_PTHREAD_TESTCANCEL 0
#define BLTN_PTHREAD_SETCANCELSTATE 0
#define BLTN_PTHREAD_SETCANCELTYPE 0

#define BLTN_PTHREAD_MUTEXATTR_SETPRIOCEILING 0
#define BLTN_PTHREAD_MUTEXATTR_GETPRIOCEILING 0
#define BLTN_PTHREAD_MUTEXATTR_SETROBUST 0
#define BLTN_PTHREAD_MUTEXATTR_GETROBUST 0
#define BLTN_PTHREAD_MUTEX_CONSISTENT 0
#define BLTN_PTHREAD_MUTEX_SETPRIOCEILING 0
#define BLTN_PTHREAD_MUTEX_GETPRIOCEILING 0

#if (_XOPEN_CRYPYT < 1)
#   define BLTN_CRYPT 0
#   define BLTN_SETKEY 0
#   define BLTN_ENCRYPT 0
#endif

#define BLTN_CHROOT chroot
#define BLTN_USLEEP usleep

#define BLTN_CONFSTR 0
#define BLTN_GETHOSTID 0

#define BLTN_READDIR_R 0
#define BLTN_A64L 0
#define BLTN_L64A 0

#define BLTN_GETDATE 0
#define BLTN_STRUCT_RUSAGE() \
    __member(rusage_s, ru_utime, "rlim_t")\
    __member(rusage_s, ru_stime, "rlim_t")\
    __member(rusage_s, ru_maxrss, "long_t")\
    __member(rusage_s, ru_ixrss, "long_t")\
    __member(rusage_s, ru_idrss, "long_t")\
    __member(rusage_s, ru_isrss, "long_t")\
    __member(rusage_s, ru_minflt, "long_t")\
    __member(rusage_s, ru_majflt, "long_t")\
    __member(rusage_s, ru_nswap, "long_t")\
    __member(rusage_s, ru_inblock, "long_t")\
    __member(rusage_s, ru_oublock, "long_t")\
    __member(rusage_s, ru_msgsnd, "long_t")\
    __member(rusage_s, ru_msgrcv, "long_t")\
    __member(rusage_s, ru_nsignals, "long_t")\
    __member(rusage_s, ru_nvcsw, "long_t")\
    __member(rusage_s, ru_nivcsw, "long_t")
      
/*

#define __ANDROID_API_L__   21 // (2014: 5.0 [L]ollipop )
#define __ANDROID_API_M__   23 // (2015: 6.0 [M]arshmallow)
#define __ANDROID_API_N__   24 // (2016: 7.0 [N]ougat ) 
#define __ANDROID_API_O__   26 // (2017: 8.0 [O]reo  )
#define __ANDROID_API_P__   28 // (2018: 9.0 [P]ie) 
#define __ANDROID_API_Q__   29 // (2019: 10.0)
#define __ANDROID_API_R__   30 // 
#define __ANDROID_API_S__   31 // 
#define __ANDROID_API_T__   32 //

*/
#if __ANDROID_API__ < 20
#   error("unsupported platform")
#endif//__ANDROID_API__ < 20

#if __ANDROID_API__ >= 20
#endif//__ANDROID_API__ < 21

/* 5.0 (2014, [L]ollipop) */ 
#if __ANDROID_API__  >= 21
#   define BLTN_DUP3 dup3
#   define BLTN_EXECVPE execvpe
#else
#   define BLTN_DPRINTF 0
#   define BLTN_LINKAT 0
#   define BLTN_READLINKAT 0
#   define BLTN_SYMLINKAT 0
#   define BLTN_TRUNCATE 0
#   define BLTN_VDPRINTF 0
#   define BLTN_VFWSCANF 0
#   define BLTN_VSWSCANF 0
#   define BLTN_VWSCANF 0
#endif // 21

#if (__ANDROID_API__ >= 23) // M
// <unistd.h>
#   if defined(_BSD_SOURCE) 
#       define BLTN_SETHOSTNAME sethostname
#   endif
#else
#   define BLTN_TELLDIR 0
#   define BLTN_SEEKDIR 0
// <stdio.h>
#   define BLTN_FMEMOPEN 0
#   define BLTN_OPEN_MEMSTREAM 0
#   define BLTN_CLEARERR_UNLOCKED 0
#   define BLTN_FEOF_UNLOCKED 0
#   define BLTN_FERROR_UNLOCKED 0
#   define BLTN_CLOCK_GETCPUCLOCKID 0
#   define BLTN_WCSCASECMP_L 0

#endif // 23

#if (__ANDROID_API__ >= 24) // N
#   define BLTN_SCANDIRAT scandirat
#   define BLTN_FUNOPEN funopen// <stdio.h>
#   define BLTN_PREADV preadv
#   define BLTN_PWRITEV pwritev
#else
//#   undef PTHREAD_BARRIER_SERIAL_THREAD
#   define BLTN_FGETPOS 0
#   define BLTN_FSETPOS 0
#   define BLTN_FTELLO 0
#   define BLTN_FSEEKO 0
#   define BLTN_IFNAMEINDEX 0
#   define BLTN_FREENAMEINDEX 0
#endif // 24

#if (__ANDROID_API__) >= 26 // O
#   define BLTN_GETDOMAINNAME getdomainname
#   define BLTN_SETDOMAINNAME setdomainname
#   define BLTN_FUTIMES futimes
#   define BLTN_LUTIMES lutimes
#   define BLTN_FUTIMESAT futimesat
#else 
    typedef unsigned long shmatt_t;
    typedef unsigned long msgqnum_t;
    typedef unsigned long msglen_t;
#   define BLTN_CATOPEN 0
#   define BLTN_CATCLOSE 0
#   define BLTN_CATGETS 0
#   define BLTN_GETPWENT 0
#   define BLTN_SETPWENT 0
#   define BLTN_GETSUBOPT 0
#   undef BLTN_SYS_MSG_H
#   undef BLTN_SYS_SEM_H
#   undef BLTN_SYS_SHM_H
#endif // 26

#if (__ANDROID_API__ >= 28) // P
#   define c_WCSTOD_L wcstod_l
#   ifdef _GNU_SOURCE
#       define BLTN_SYNCFS syncfs
#   endif
#else

#   undef BLTN_ICONV_H
#   include <iconv.h>
#   define BLTN_ENDHOSTENT 0
#   define BLTN_SETHOSTENT 0
#   define BLTN_ENDNETENT 0
#   define BLTN_GETNETENT 0
#   define BLTN_SETNETENT 0
#   define BLTN_ENDPROTOENT 0
#   define BLTN_GETPROTOENT 0
#   define BLTN_SETPROTOENT 0

#   define BLTN_HCREATE 0
#   define BLTN_HDESTROY 0
#   define BLTN_HSEARCH 0
#   define BLTN_PTHREAD_ATTR_GETINHERITSCHED 0
#   define BLTN_PTHREAD_ATTR_SETINHERITSCHED 0
#   define BLTN_PTHREAD_MUTEXATTR_GETPROTOCOL 0
#   define BLTN_PTHREAD_MUTEXATTR_SETPROTOCOL 0
#   define BLTN_PTHREAD_SETSCHEDPRIO 0
#   define BLTN_SWAB 0
#   define BLTN_FEXECVE 0
#   define BLTN_GETLOGIN_R 0
#endif // 28


// 10.0 (2019, Q) 
#if __ANDROID_API__ >= 29
#   define BLTN_PTHREAD_SIGQUEUE pthread_sigqueue
#else
#   define BLTN_TIMESPEC_GET 0
#endif // 29 


// 12.0 (2021, S)
#if __ANDROID_API__ >= 30
#   define BLTN_MEMFD_CREATE memfd_create
#endif // 30

#if __ANDROID_API__ >= 31
#endif // 31


// (2022, T)
#if __ANDROID_API__ >= 32
#   define BLTN_PREADV2 preadv2
#   define BLTN_PWRITEV2 pwritev2
#endif // 32

#   include <ndbm.h>
#if 0
//ifdef BLTN_NDBM_H
    int bltn_dbm_clearerr(DBM *self) {
        // "The return value of dbm_clearerr is unspecified"
        dbm_clearerr(self);
        return 0;
    }

    DBM *bltn_dbm_open(const char *path, int flag, mode_t mode) {
        return dbm_open((char*)path, flag, mode);
    }
#   define BLTN_DBM_CLEARERR bltn_dbm_clearerr
#   define BLTN_DBM_OPEN bltn_dbm_open
//#   undef BLTN_NDBM_H
//#   include "xbd/ndbm.h"

#endif
