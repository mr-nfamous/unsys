/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳   
Compile time host (operating system) identification 

Issue 1 - X/Open Portability Guide, July 1985:
    (ISBN: 0-444-87839-4)

Issue 2 - X/Open Portability Guide, January 1987:
    Volume 1: XVS Commands and Utilities    (ISBN: 0-444-70174-5)
    Volume 2: XVS System Calls and Libraries(ISBN: 0-444-70175-3)

Issue 3 - X/Open Specification, 1988, 1989, February 1992:
    Commands and Utilities              (ISBN: 1-872630-36-7, C211); 
    System Interfaces and Headers       (ISBN: 1-872630-37-5, C212);
    Curses Interface                    (ISBN: 1-872630-38-3, C213);
    Headers Interface                   (ISBN: 1-872630-38-3, C213);

Issue 4 - CAE Specification, July 1992:
    (XBD) System Interface Definitions  (ISBN: 1-872630-46-4, C204)
    (XSH) System Interfaces and Headers (ISBN: 1-872630-47-2, C202)
    (XCU) Commands and Utilities        (ISBN: 1-872630-48-0, C203)

Issue 4 Version 2, August 1994:
    (XBD) System Interface Definitions  (ISBN: 1-85912-036-9, C434)
    (XSH) System Interfaces and Headers (ISBN: 1-85912-037-7, C435)
    (XCU) Commands and Utilities        (ISBN: 1-85912-034-2, C436)

Issue 5 - Technical Standard, February 1997
    (XBD) System Interface Definitions  (ISBN: 1-85912-186-1, C605)
    (XSH) System Interfaces and Headers (ISBN: 1-85912-191-8, C604)
    (XCU) Commands and Utilities        (ISBN: 1-85912-181-0, C606)

Issue 6 - Technical Standard, April 2004
    (XBD) System Interface Definitions  (ISBN: 1-931624-43-7, C046)
    (XSH) System Interfaces and Headers (ISBN: 1-931624-44-5, C047)
    (XCU) Commands and Utilities        (ISBN: 1-931624-453-, C048)
 */
 
#pragma once

#if __STDC_HOSTED__ != 1
#error "an OS is required"
#endif

#define HOST_STDC_API __STDC_VERSION__
#define STDC_95   199409L
#define STDC_99   199901L
#define STDC_11   201112L
#define STDC_17   201710L

#ifdef _MSC_VER
#define HOST_MSVC_API _MSC_VER
#endif

#define MSVC_15     1900L // [2015-11]
#define MSVC_17     1910L // [2017-03]
#define MSVC_19     1920L // [2019-04]
#define MSVC_22     1930L // [2021-11]

#define POSIX_1        1
#define POSIX_2        2
#define POSIX_3        3
#define POSIX_4        4
#define POSIX_5        5
#define POSIX_6   200112L
#define POSIX_7   200809L

#define XOPEN_3        3L // [1989-??] XPG3 (X/Open Portability Guide 3)
#define XOPEN_4        4L // [1992-??] XPG4 (X/Open Portability Guide 4)
//  if _XOPEN_UNIX ==  1L    [1994-??] SUS (Single Unix Specification)
#define XOPEN_5      500L // [1997-??] SUSv2/POSIX.1-1995
#define XOPEN_6      600L // [2002-01] SUSv3/POSIX.1-2001
#define XOPEN_7      700L // [2008-12] SUSv4/POSIX.1-2008 

#define WINNT_4     0x400L // [1996-08] Windows NT 4.0
#define WINNT_2K    0x500L // [2000-02] Windows 2000
#define WINNT_XP    0x501L // [2001-10] Windows XP 
#define WINNT_S03   0x502L // [2003-04] Windows Server 2003
#define WINNT_VISTA 0x600L // [2006-11] Windows Vista
#define WINNT_S08   0x600L // [2008-02] Windows Server 2008
#define WINNT_7     0x601L // [2009-07] Windows 7
#define WINNT_8     0X602L // [2012-10] Windows 8
#define WINNT_8_1   0x603L // [2013-10] Windows 8.1
#define WINNT_10    0xA00L // [2015-07] Windows 10
#define BIONIC_K      19L // [2013-10] Android 4.4 "KitKat"
#define BIONIC_L      21L // [2014-11] Android 5.0 "Lollipop"
#define BIONIC_M      23L // [2015-09] Android 6.0 "Marshmallow"
#define BIONIC_N      24L // [2016-08] Android 7.0 "Nougat"
#define BIONIC_O      26L // [2017-08] Android 8.0 "Oreo"
#define BIONIC_P      28L // [2018-08] Android 9.0 "Pie"
#define BIONIC_Q      29L // [2019-09] Android 10.0 "Q"
#define BIONIC_R      30L // [2020-09] Android 11.0 "R"
#define BIONIC_S      31L // [2021-10] Android 12.0 "S"
#define BIONIC_T      33L // [2022-08] Android 13.0 "T"

#if defined(_WIN32)
#   define HOST_TMPDIR_VAR  u"TMP"
#   define HOST_TMPDIR_ALT  u"TMP"
#   define HOST_SEP         u'\\'
#   define HOST_ALTSEP      u'/'
#   ifndef WINVER
#   define WINVER       0x0602L
#   endif
#   ifndef _WIN32_WINNT 
#   define _WIN32_WINNT 0x0602L
#   endif

#   if !defined(WINVER)
#       define  WINVER 0x0602
#   endif
#   if !defined(_WIN32_WINNT)
#       define  _WIN32_WINNT 0x0602
#   endif

#   define HOST_WIN32_API      WINVER

/*
#   define WIN32_LEAN_AND_MEAN
#define WINVER:
    _WIN32_WINNT_WIN10      0x0A00 // 10
    _WIN32_WINNT_WINBLUE    0x0603 // 8.1
    _WIN32_WINNT_WIN8       0x0602 // 8 
    _WIN32_WINNT_WIN7       0x0601 // 7 
    _WIN32_WINNT_WS08       0x0600 // Server 2008 
    _WIN32_WINNT_VISTA      0x0600 // Vista
    _WIN32_WINNT_WS03       0x0502 // XP SP2, Server 2003
    _WIN32_WINNT_WINXP      0x0501 // XP 
#   if !defined(_WIN32_WINNT)
#       define  _WIN32_WINNT 0x0502
*/

#else // !defined(_WIN32)
#   define HOST_TMPDIR_VAR "TMPDIR"

#   ifdef __linux__
#       define HOST_LINUX_API 1
#       ifndef _GNU_SOURCE
#       define _GNU_SOURCE
#       endif
#       ifndef _BSD_SOURCE
#       define _BSD_SOURCE
#       endif
#   endif

#   include <unistd.h>

#endif

#ifdef _POSIX_VERSION
#define HOST_POSIX_API _POSIX_VERSION
#endif

#ifdef _XOPEN_VERSION
#define HOST_XOPEN_API _XOPEN_VERSION
#endif

#if defined(__BIONIC__)

#   define HOST_BIONIC_API __ANDROID_API__

#   if __ANDROID_API__  >= 21
#       define os_accept          accept4 
#       define os_atof            atof
#       define os_dprintf         dprintf
#       define os_dup3            dup3
#       define os_epoll_create1   epoll_create1
#       define os_epoll_pwait     epoll_pwait
#       define os_execvpe         execvpe
#       define os_ffs             ffs
#       define os_futimens        futimens
#       define os_getpagesize     getpagesize
#       define os_getsid          getsid
#       define os_htons           htons
#       define os_htonl           htonl
#       define os_ntohs           ntohs
#       define os_ntohl           ntohl
#       define os_imaxabs         imaxabs
#       define os_imaxdiv         imaxdiv
#       define os_linkat          linkat
#       define os_symlinkat       symlinkat
#   endif

#   if __ANDROID_API__ >= 22
#   endif

#   if __ANDROID_API__  >= 21
#       define os_accept4         accept4 
#       define os_atof            atof
#       define os_dprintf         dprintf
#       define os_dup3            dup3
#       define os_epoll_create1   epoll_create1
#       define os_epoll_pwait     epoll_pwait
#       define os_execvpe         execvpe
#       define os_ffs             ffs
#       define os_futimens        futimens
#       define os_getsid          getsid
#       define os_linkat          linkat
#       define os_recvfrom        recvfrom
#       define os_readlinkat      readlinkat
#       define os_symlinkat       symlinkat
#   endif

#   if __ANDROID_API__ >= 22
#   endif

#   if __ANDROID_API__ >= 23
#       define os_seekdir seekdir
#   endif
#endif // defined(__BIONIC__)

/*
Hopefully, Darwin major version number is a logical way to
detect at compile time which system calls are available.
*/
// N/A (Darwin C)                      macOS  iOS 
#define DARWIN_16 101200L // [2016-09] 10.12  10.0  
#define DARWIN_17 101300L // [2017-09] 10.13  11.0
#define DARWIN_18 101400L // [2018-09] 10.14  12.0
#define DARWIN_19 101500L // [2019-09] 10.15  13.0
#define DARWIN_20 110000L // [2020-09] 11.00  14.0
#define DARWIN_21 120000L // [2021-10] 11.00  15.0
#define DARWIN_22 130000L // [2022-10] 13.00  16.0

#if defined(__APPLE__)

#   if __MAC_OS_X_VERSION_MIN_REQUIRED >= 101200
#      define HOST_DARWIN_API __MAC_OS_X_VERSION_MIN_REQUIRED

#   elif    __IPHONE_OS_VERSION_MIN_REQUIRED >= 100000
#       if  __IPHONE_OS_VERSION_MIN_REQUIRED >= 160000
#          define HOST_DARWIN_API 130000L
#      elif __IPHONE_OS_VERSION_MIN_REQUIRED >= 150000
#          define HOST_DARWIN_API 120000L
#      elif __IPHONE_OS_VERSION_MIN_REQUIRED >= 140000
#          define HOST_DARWIN_API 110000L
#      elif __IPHONE_OS_VERSION_MIN_REQUIRED >= 130000
#          define HOST_DARWIN_API 101500L
#      elif __IPHONE_OS_VERSION_MIN_REQUIRED >= 120000
#          define HOST_DARWIN_API 101400L
#      elif __IPHONE_OS_VERSION_MIN_REQUIRED >= 110000
#          define HOST_DARWIN_API 101300L
#      else 
#          define HOST_DARWIN_API 101200L
#      endif

#   elif    __TV_OS_VERSION_MIN_REQUIRED >= 100000
#      if   __TV_OS_VERSION_MIN_REQUIRED >= 160000
#          define HOST_DARWIN_API 130000L
#      elif __TV_OS_VERSION_MIN_REQUIRED >= 150000
#          define HOST_DARWIN_API 120000L
#      elif __TV_OS_VERSION_MIN_REQUIRED >= 140000
#          define HOST_DARWIN_API 110000L
#      elif __TV_OS_VERSION_MIN_REQUIRED >= 130000
#          define HOST_DARWIN_API 101500L
#      elif __TV_OS_VERSION_MIN_REQUIRED >= 120000
#          define HOST_DARWIN_API 101400L
#      elif __TV_OS_VERSION_MIN_REQUIRED >= 110000
#          define HOST_DARWIN_API 101300L
#      else 
#          define HOST_DARWIN_API 101200L
#      endif

#   elif    __WATCH_OS_VERSION_MIN_REQUIRED >= 30000
#      if   __WATCH_OS_VERSION_MIN_REQUIRED >= 90000
#          define HOST_DARWIN_API 130000L
#      elif __WATCH_OS_VERSION_MIN_REQUIRED >= 80000
#          define HOST_DARWIN_API 120000L
#      elif __WATCH_OS_VERSION_MIN_REQUIRED >= 70000
#          define HOST_DARWIN_API 110000L
#      elif __WATCH_OS_VERSION_MIN_REQUIRED >= 60000
#          define HOST_DARWIN_API 101500L
#      elif __WATCH_OS_VERSION_MIN_REQUIRED >= 50000
#          define HOST_DARWIN_API 101400L
#      elif __WATCH_OS_VERSION_MIN_REQUIRED >= 40000
#          define HOST_DARWIN_API 101300L
#      else 
#          define HOST_DARWIN_API 101200L
#      endif

#   elif    __BRIDGE_OS_VERSION_MIN_REQUIRED >= 10000
#      if   __BRIDGE_OS_VERSION_MIN_REQUIRED >= 60000
#          define HOST_DARWIN_API 130000L
#      elif __BRIDGE_OS_VERSION_MIN_REQUIRED >= 50000
#          define HOST_DARWIN_API 120000L
#      elif __BRIDGE_OS_VERSION_MIN_REQUIRED >= 40000
#          define HOST_DARWIN_API 110000L
#      elif __BRIDGE_OS_VERSION_MIN_REQUIRED >= 30000
#          define HOST_DARWIN_API 101500L
#      elif __BRIDGE_OS_VERSION_MIN_REQUIRED >= 20000
#          define HOST_DARWIN_API 101400L
#      elif __BRIDGE_OS_VERSION_MIN_REQUIRED >= 10000
#          define HOST_DARWIN_API 101300L
#      else 
#          define HOST_DARWIN_API 101200L
#      endif
#   endif // __MAC_OS_X_VERSION_MIN_REQUIRED >= 101200
#   ifndef HOST_DARWIN_API
#       error "unknown operating system"
#   endif
#   if HOST_DARWIN_API >= DARWIN_22
#       define os_freadlink freadlink
#       define os_mknodat mknodat
#   endif
#   if !defined(os_clock_gettime) && HOST_DARWIN_API > DARWIN_16
#       define os_clock_gettime clock_gettime
#       define os_clock_gettime clock_getres
#       define os_clock_settime clock_settime
#   else
#       error "missing clock_gettime"
#   endif

#endif // !defined(__APPLE__)
/*
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <float.h>
#include <fenv.h>
#include <inttypes.h>
#include <iso646.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdalign.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <uchar.h>
#include <wchar.h>

#if HOST_POSIX_API
#   include <arpa/inet.h>
#   include <dirent.h>
#   include <dlfcn.h>
#   include <net/if.h>
#   include <netinet/in.h>
#   include <netinet/tcp.h>
#   include <pthread.h>
#   include <sched.h>
#   include <sys/mman.h>
#   include <sys/socket.h>
#   include <sys/wait.h>
static pthread_mutex_t UNSYS_GLOBAL_LOCK = PTHREAD_MUTEX_INITIALIZER;
#define ENTER_CRITICAL_SECTION() ((void)   pthread_mutex_lock(&UNSYS_GLOBAL_LOCK))
#define LEAVE_CRITICAL_SECTION() ((void) pthread_mutex_unlock(&UNSYS_GLOBAL_LOCK))

#endif


typedef struct {
    unsigned lo_s;
    unsigned hi_s;
    unsigned ns;
} OSTime;

*/
