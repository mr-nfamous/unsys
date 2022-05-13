/*


    Missing headers that lack a dedicated feature test 
    must be undefined in "caveats.h". The following list 
    contains the headers defined in the Base Definitions 
    volume of POSIX.1-2017 that are (or were) associated 
    with a feature test macro from <unistd.h>:

    # <aio.h>                   _POSIX_ASYNCHRONOUS_IO > 0    
    # <cpio.h>                  _POSIX_VERSION >= 200809
    # <dlfcn.h>                 _POSIX_VERSION >= 200809
    # <langinfo.h>              _POSIX_VERSION >= 200809
    # <monetary.h>              _POSIX_VERSION >= 200809
    # <nl_types.h>              _POSIX_VERSION >= 200809
    # <poll.h>                  _POSIX_VERSION >= 200809
    # <regex.h>                 _POSIX_REGEXP > 0
    # <sched.h>     [*]         _POSIX_VERSION >= 200809
    # <sys/statvfs.h>           _POSIX_VERSION >= 200809
    # <mqueue.h>                _POSIX_MESSAGE_PASSING > 0
    # <pthread.h>               _POSIX_THREADS > 0
    # <semaphore.h>             _POSIX_SEMAPHORES > 0       
    # <spawn.h>                 _POSIX_SPAWN > 0       
    # <sys/mmap.h>              _POSIX_MAPPED_FILES > 0
    # <stropts.h>   [OB]        _XOPEN_STREAMS > 0
    # <trace.h>     [OB]        _POSIX_TRACE > 0
    # <ndbm.h>                  _XOPEN_UNIX
    # <fmtmsg.h>                _XOPEN_UNIX
    # <ftw.h>                   _XOPEN_UNIX
    # <libgen.h>                _XOPEN_UNIX
    # <ulimit.h>                _XOPEN_UNIX
    # <utmpx.h>                 _XOPEN_UNIX
    # <search.h>                _XOPEN_UNIX
    # <syslog.h>                _XOPEN_UNIX
    # <sys/ipc.h>               _XOPEN_SHM
    # <sys/msg.h>               _XOPEN_SHM
    # <sys/resource.h>          _XOPEN_UNIX
    # <sys/sem.h>               _XOPEN_SHM
    # <sys/shm.h>               _XOPEN_SHM
    # <sys/uio.h>               _XOPEN_UNIX
    # <sys/time.h>              _XOPEN_UNIX
    # <utime.h>     [OB]

    Lke functions, headers marked "obsolescent" in the 
    current standard are "opt-in". E.g. <ulimit.h> is 
    ignored unless "caveats.h" includes an explicit 
    definition of BLTN_ULIMIT_H.
    
    [*] <sched.h> was moved to base POSIX in issue 7 but 
    without _POSIX_PRIORITY_SCHEDULING > 0, the header 
    includes nothing but the prototype for sched_yield()
    
static const char *RESERVED_IDENTIFIERS[] = {

    {"<aio.h>", "^aio_*", "^lio_*", "^AIO_*", "^LIO_*", 0},
    {"<arpa/inet.h>", "^inet_*", 0},
    {"<ctype.h>", "^is[a-z]*", "^to[a-z]*", 0},
    {"<dirent.h>", "^d_*", 0},
    {"<dlfcn.h", "^RTLD_*", 0},
    {"<.h>", "*", 0},
    {"<fcntl.h", "^l_*", 0},
    {"<fmtmsg.h>", "MM_*", 0},
    {"<.h>", "*", 0},
*/  
// 
#   ifdef BLTN_AIO_H
#   include   <aio.h>
#   endif

#   ifdef BLTN_ARPA_INET_H
#   include   <arpa/inet.h>
#   endif

#   ifdef BLTN_CTYPE_H
#   include   <ctype.h>
#   endif

#   ifdef BLTN_CPIO_H
#   include   <cpio.h>
#   endif

#   ifdef BLTN_DIRENT_H
#   include   <dirent.h>
#   endif

#   ifdef BLTN_DLFCN_H
#   include   <dlfcn.h>
#   endif

#   ifdef BLTN_ERRNO_H
#   include   <errno.h>
#   endif

#   ifdef BLTN_FCNTL_H
#   include   <fcntl.h>
#   endif

#   ifdef BLTN_FMTMSG_H
#   include   <fmtmsg.h>
#   endif

#   ifdef BLTN_FNMATCH_H
#   include   <fnmatch.h>
#   endif

#ifdef BLTN_FTW_H
#   include <ftw.h>
#endif

#ifdef BLTN_GLOB_H
#   include <glob.h>
#endif

#ifdef BLTN_GRP_H
#   include <grp.h>
#endif

#ifdef BLTN_ICONV_H
#   include <iconv.h>
#endif

#ifdef BLTN_INTTYPES_H
#   include <inttypes.h>
#endif

#ifdef BLTN_LIBGEN_H
#   include <libgen.h>
#endif

#ifdef BLTN_LIMITS_H
#   include <limits.h>
#endif

#ifdef BLTN_LANGINFO_H
#   include <langinfo.h>
#endif

#ifdef BLTN_LOCALE_H
#   include <locale.h>
#endif

#ifdef BLTN_MATH_H
#   include <math.h>
#endif

#ifdef BLTN_MONETARY_H
#   include <monetary.h>
#endif

#ifdef BLTN_NDBM_H
#   include <ndbm.h>
#endif

#ifdef BLTN_NETDB_H
#   include <netdb.h>
#endif

#ifdef BLTN_NETINET_IN_H
#   include <netinet/in.h>
#endif

#ifdef BLTN_NETINET_TCP_H
#   include <netinet/tcp.h>
#endif

#ifdef BLTN_NET_IF_H
#   include <net/if.h>
#endif

#ifdef BLTN_NL_TYPES_H
#   include <nl_types.h>
#endif

#ifdef BLTN_POLL_H
#   include <poll.h>
#endif

#ifdef BLTN_PTHREAD_H
#   include <pthread.h>
#endif

#ifdef BLTN_PWD_H
#   include <pwd.h>
#endif

#ifdef BLTN_REGEX_H
#   include <regex.h>
#endif

#ifdef BLTN_SCHED_H
#   include <sched.h>
#endif

#ifdef BLTN_SEARCH_H
#   include <search.h>
#endif

#ifdef BLTN_SEMAPHORE_H
#   include <semaphore.h>
#endif

#ifdef BLTN_SETJMP_H
#   include <setjmp.h>
#endif

#ifdef BLTN_SIGNAL_H
#   include <signal.h>
#endif

#ifdef BLTN_SPAWN_H
#   include <spawn.h>
#endif

#ifdef BLTN_STDINT_H
#   include <stdint.h>
#endif

#ifdef BLTN_STDIO_H
#   include <stdio.h>
#endif

#ifdef BLTN_STDLIB_H
#   include <stdlib.h>
#endif

#ifdef BLTN_STRING_H
#   include <string.h>
#endif

#ifdef BLTN_STRINGS_H
#   include <strings.h>
#endif

#ifdef BLTN_SYS_IPC_H
#   include <sys/ipc.h>
#endif

#ifdef BLTN_SYS_MMAN_H
#   include <sys/mman.h>
#endif

#ifdef BLTN_SYS_MSG_H
#   include <sys/msg.h>
#endif

#ifdef BLTN_SYS_RESOURCE_H
#   include <sys/resource.h>
#endif

#ifdef BLTN_SYS_SELECT_H
#   include <sys/select.h>
#endif

#ifdef BLTN_SYS_SEM_H
#   include <sys/sem.h>
#endif

#ifdef BLTN_SYS_SHM_H
#   include <sys/shm.h>
#endif

#ifdef BLTN_SYS_SOCKET_H
#   include <sys/socket.h>
#endif

#ifdef BLTN_SYS_STAT_H
#   include <sys/stat.h>
#endif

#ifdef BLTN_SYS_STATVFS_H
#   include <sys/statvfs.h>
#endif

#ifdef BLTN_SYS_TIME_H
#   include <sys/time.h>
#endif

#ifdef BLTN_SYS_TIMES_H
#   include <sys/times.h>
#endif

#ifdef BLTN_SYS_UIO_H
#   include <sys/uio.h>
#endif

#ifdef BLTN_SYS_UTSNAME_H
#   include <sys/utsname.h>
#endif

#ifdef BLTN_SYS_UN_H
#   include <sys/un.h>
#endif

#ifdef BLTN_SYS_WAIT_H
#   include <sys/wait.h>
#endif

#ifdef BLTN_SYSLOG_H
#   include <syslog.h>
#endif

#ifdef BLTN_TAR_H
#   include <tar.h>
#endif

#ifdef BLTN_TERMIOS_H
#   include <termios.h>
#endif

#ifdef BLTN_TIME_H
#   include <time.h>
#endif

#ifdef BLTN_ULIMIT_H
#   include <ulimit.h>
#endif

#ifdef BLTN_UTIME_H
#   include <utime.h>
#endif

#ifdef BLTN_WCHAR_H
#   include <wchar.h>
#endif

#   ifdef BLTN_WORDEXP_H
#   include <wordexp.h>
#   endif

#include "xbd.h"

int as_do_nothing(Lib *self, FILE *file) {
    return 0;
}

#ifdef BLTN_AIO_H
#   include "xbd/aio.h"
#else
#   define include_aio_h as_do_nothing
#endif

#ifdef BLTN_CTYPE_H
#   include "xbd/ctype.h"
#else
#   define include_ctype_h as_do_nothing
#endif

#ifdef BLTN_CPIO_H
#   include "xbd/cpio.h"
#else
#   define include_cpio_h as_do_nothing
#endif

#ifdef BLTN_ARPA_INET_H
#   include "xbd/arpa/inet.h"
#else
#   define include_arpa_inet_h as_do_nothing
#endif

#ifdef BLTN_DIRENT_H
#   include "xbd/dirent.h"
#else
#   define include_dirent_h as_do_nothing
#endif

#ifdef BLTN_DLFCN_H
#   include "xbd/dlfcn.h"
#else
#   define include_dlfcn_h as_do_nothing
#endif

#ifdef BLTN_ERRNO_H
#   include "xbd/errno.h"
#else
#   define include_errno_h as_do_nothing
#endif

#ifdef BLTN_FCNTL_H
#   include "xbd/fcntl.h"
#else
#   define include_fcntl_h as_do_nothing
#endif

#ifdef BLTN_FMTMSG_H
#   include "xbd/fmtmsg.h"
#else
#   define include_fmtmsg_h as_do_nothing
#endif

#ifdef BLTN_FNMATCH_H
#   include "xbd/fnmatch.h"
#else
#   define include_fnmatch_h as_do_nothing
#endif

#ifdef BLTN_FTW_H
#   include "xbd/ftw.h"
#else
#   define include_ftw_h as_do_nothing
#endif

#ifdef BLTN_GLOB_H
#   include "xbd/glob.h"
#else
#   define include_glob_h as_do_nothing
#endif

#ifdef BLTN_GRP_H
#   include "xbd/grp.h"
#else
#   define include_grp_h as_do_nothing
#endif

#ifdef BLTN_ICONV_H
#   include "xbd/iconv.h"
#else
#   define include_iconv_h as_do_nothing
#endif

#ifdef BLTN_INTTYPES_H
#   include "xbd/inttypes.h"
#else
#   define include_inttypes_h as_do_nothing
#endif

#ifdef BLTN_LANGINFO_H
#   include "xbd/langinfo.h"
#else
#   define include_langinfo_h as_do_nothing
#endif

#ifdef BLTN_LIBGEN_H
#   include "xbd/libgen.h"
#else
#   define include_libgen_h as_do_nothing
#endif

#ifdef BLTN_LIMITS_H
#   include "xbd/limits.h"
#else
#   define include_limits_h as_do_nothing
#endif

#ifdef BLTN_LOCALE_H
#   include "xbd/locale.h"
#else
#   define include_locale_h as_do_nothing
#endif

#ifndef BLTN_MQUEUE_H
#   define include_mqueue_h as_do_nothing
#else
#   include "xbd/mqueue.h"
#endif

#ifndef BLTN_MONETARY_H
#   define include_monetary_h as_do_nothing
#else
#   include "xbd/monetary.h"
#endif

#ifdef BLTN_MATH_H
#   include "xbd/math.h"
#else
#   define include_math_h as_do_nothing
#endif

#ifdef BLTN_NDBM_H
#   include "xbd/ndbm.h"
#else
#   define include_ndbm_h as_do_nothing
#endif

#ifdef BLTN_NETDB_H
#   include "xbd/netdb.h"
#else
#   define include_netdb_h as_do_nothing
#endif

#ifdef BLTN_NETINET_IN_H
#   include "xbd/netinet/in.h"
#else
#   define include_netinet_in_h as_do_nothing
#endif

#ifdef BLTN_NETINET_TCP_H
#   include "xbd/netinet/tcp.h"
#else
#   define include_netinet_tcp_h as_do_nothing
#endif

#ifdef BLTN_NET_IF_H
#   include "xbd/net/if.h"
#else
#   define include_net_if_h as_do_nothing
#endif

#ifdef BLTN_NL_TYPES_H
#   include "xbd/nl_types.h"
#else
#   define include_nl_types_h as_do_nothing
#endif

#ifdef BLTN_POLL_H
#   include "xbd/poll.h"
#else
#   define include_poll_h as_do_nothing
#endif

#ifdef BLTN_PTHREAD_H
#   include "xbd/pthread.h"
#else
#   define include_pthread_h as_do_nothing
#endif

#ifdef BLTN_PWD_H
#   include "xbd/pwd.h"
#else
#   define include_pwd_h as_do_nothing
#endif

#ifdef BLTN_REGEX_H
#   include "xbd/regex.h"
#else
#   define include_regex_h as_do_nothing
#endif

#ifdef BLTN_SCHED_H
#   include "xbd/sched.h"
#else
#   define include_sched_h as_do_nothing
#endif

#ifdef BLTN_SEARCH_H
#   include "xbd/search.h"
#else
#   define include_search_h as_do_nothing
#endif

#ifndef BLTN_SEMAPHORE_H
#   define include_semaphore_h as_do_nothing
#else
#   include "xbd/semaphore.h"
#endif

#ifndef BLTN_SETJMP_H
#   define include_setjmp_h as_do_nothing
#else
#   include "xbd/setjmp.h"
#endif

#ifndef BLTN_SPAWN_H
#   define include_spawn_h as_do_nothing
#else
#   include "xbd/spawn.h"
#endif

#ifdef BLTN_SIGNAL_H
#   include "xbd/signal.h"
#else
#   define include_signal_h as_do_nothing
#endif

#ifdef BLTN_STDINT_H
#   include "xbd/stdint.h"
#else
#   define include_stdint_h as_do_nothing
#endif

#ifdef BLTN_STDIO_H
#   include "xbd/stdio.h"
#else
#   define include_stdio_h as_do_nothing
#endif

#ifdef BLTN_STRING_H
#   include "xbd/string.h"
#else
#   define include_string_h as_do_nothing
#endif

#ifdef BLTN_STRINGS_H
#   include "xbd/strings.h"
#else
#   define include_strings_h as_do_nothing
#endif

#ifdef BLTN_STDLIB_H
#   include "xbd/stdlib.h"
#else
#   define include_stdlib_h as_do_nothing
#endif

#ifdef BLTN_SYS_IPC_H
#   include "xbd/sys/ipc.h"
#else
#   define include_sys_ipc_h as_do_nothing
#endif

#ifdef BLTN_SYS_MMAN_H
#   include "xbd/sys/mman.h"
#else
#   define include_sys_mman_h as_do_nothing
#endif

#ifndef BLTN_SYS_MSG_H
#   define include_sys_msg_h as_do_nothing
#else
#   include "xbd/sys/msg.h"
#endif

#ifdef BLTN_SYS_RESOURCE_H
#   include "xbd/sys/resource.h"
#else
#   define include_sys_resource_h as_do_nothing
#endif

#ifdef BLTN_SYS_SELECT_H
#   include "xbd/sys/select.h"
#else
#   define include_sys_select_h as_do_nothing
#endif

#ifndef BLTN_SYS_SEM_H
#   define include_sys_sem_h as_do_nothing
#else
#   include "xbd/sys/sem.h"
#endif

#ifndef BLTN_SYS_SHM_H
#   define include_sys_shm_h as_do_nothing
#else
#   include "xbd/sys/shm.h"
#endif

#ifdef BLTN_SYS_SOCKET_H
#   include "xbd/sys/socket.h"
#else
#   define include_sys_socket_h as_do_nothing
#endif

#ifdef BLTN_SYS_STAT_H
#   include "xbd/sys/stat.h"
#else
#   define include_sys_stat_h as_do_nothing
#endif

#ifdef BLTN_SYS_STATVFS_H
#   include "xbd/sys/statvfs.h"
#else
#   define include_sys_statvfs_h as_do_nothing
#endif

#ifdef BLTN_SYS_TIME_H
#   include "xbd/sys/time.h"
#else
#   define include_sys_time_h as_do_nothing
#endif

#ifdef BLTN_SYS_TIMES_H
#   include "xbd/sys/times.h"
#else
#   define include_sys_times_h as_do_nothing
#endif

#ifdef BLTN_SYS_UIO_H
#   include "xbd/sys/uio.h"
#else
#   define include_sys_uio_h as_do_nothing
#endif

#ifdef BLTN_SYS_UTSNAME_H
#   include "xbd/sys/utsname.h"
#else
#   define include_sys_utsname_h as_do_nothing
#endif

#ifdef BLTN_SYS_UN_H
#   include "xbd/sys/un.h"
#else
#   define include_sys_un_h as_do_nothing
#endif

#ifdef BLTN_SYS_WAIT_H
#   include "xbd/sys/wait.h"
#else
#   define include_sys_wait_h as_do_nothing
#endif

#ifdef BLTN_SYSLOG_H
#   include "xbd/syslog.h"
#else
#   define include_syslog_h as_do_nothing
#endif

#ifdef BLTN_TAR_H
#   include "xbd/tar.h"
#else
#   define include_tar_h as_do_nothing
#endif

#ifdef BLTN_TERMIOS_H
#   include "xbd/termios.h"
#else
#   define include_termios_h as_do_nothing
#endif

#ifdef BLTN_TIME_H
#   include "xbd/time.h"
#else
#   define include_time_h as_do_nothing
#endif

// BLTN_TGMATH_H
// BLTN_TRACE_H

#ifdef BLTN_ULIMIT_H
#   include "xbd/ulimit.h"
#else
#   define include_ulimit_h as_do_nothing
#endif

#ifdef BLTN_UTIME_H
#   include "xbd/utime.h"
#else
#   define include_utime_h as_do_nothing
#endif

#ifdef BLTN_UTMPX_H
#   include "xbd/utmpx.h"
#else
#   define include_utmpx_h as_do_nothing
#endif

#ifdef BLTN_WCHAR_H
#   include "xbd/wchar.h"
#else
#   define include_wchar_h as_do_nothing
#endif

#ifdef BLTN_WORDEXP_H
#   include "xbd/wordexp.h"
#else
#   define include_wordexp_h as_do_nothing
#endif

#include "xbd/unistd.h"