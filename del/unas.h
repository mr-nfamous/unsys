
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
/* Typecode definitions 

All of the types required to implement the system call APIs 
implemented by unsys have been assigned a unique, positive
integer between [0..65535] which will never change. Names 
are chosen using one of 3 schemes, all beginning with the
prefix "AS_". For compiler builtins like int or long long, 
the name will match the corresponding limit. E.g:

    *   short     ->  SHRT_MIN -> AS_SHRT
    *   int       ->   INT_MIN -> AS_INT 
    *   long long -> LLONG_MIN -> AS_LLONG

Otherwise, the vast majority of type ids will be based on 
the capitalized type name, excluding the "_t":
    
    *   size_t    -> AS_SIZE 
    *   struct tm -> AS_TM 

In a few cases, type names are deemed needlessly verbose or 
expected to cause name conflicts:
    *   posix_spawn_file_actions_t -> AS_PSPAWN_FILE_ACTS 
    *   datum                      -> AS_NDBM_DATUM

*/
#pragma once

#include <stdalign.h>

#include "unptr.h"
#include "nb/rank.h"
#include "nb/signedness.h"

/* 
If an implementation supports the intn_t/uintn_t types, the
corresponding int_leastn_t type is by definition guaranteed
to use the same representation. Fixed width types without
power of 2 widths, e.g. int_least24_t, as well as the entire
int_fastn_t family, are excluded.

Anything explicitly defined as a typedef of the fixed width
integer types will be defined as a macro, unless the type is 
explicitly defined as a non-integer type. E.g. char16_t and
char32_t are aliases of uint_least16/32 but since they are
"character" types they are given a unique id.
*/


#define AS_IN_PORT_T        AS_UINT16
#define AS_IN_ADDR_T        AS_UINT32

#define AS_INT_LEAST8_T     AS_INT8_T
#define AS_INT_LEAST16_T    AS_INT16_T
#define AS_INT_LEAST32_T    AS_INT32_T
#define AS_INT_LEAST64_T    AS_INT64_T

#define AS_UINT_LEAST8_T    AS_INT8_T
#define AS_UINT_LEAST16_T   AS_INT16_T
#define AS_UINT_LEAST32_T   AS_INT32_T
#define AS_UINT_LEAST64_T   AS_INT64_T

#define AS_VOID_ABC         (AS_VOID)
#define AS_VOID_MAX         (AS_VOID+1)

#define AS_SCALAR_ABC       (AS_ADDR)
#define AS_POINTER_ABC      (AS_ADDR)
#define AS_POINTER_MAX      (AS_ADDRPTR+1)

#define AS_CHARACTER_ABC    (AS_CHAR)
#define AS_WIDE_ABC         (AS_WCHAR)
#define AS_WIDE_MAX         (AS_CHAR32+1)
#define AS_CHARACTER_MAX    (AS_WIDE_MAX)

#define AS_REAL_ABC         (AS_HALF)
#define AS_FLOATING_ABC     (AS_HALF)
#define AS_FLOATING_MAX     (AS_BIGFLT+1)
#define AS_INTEGER_ABC      (AS_BOOL)
#define AS_BOOLEAN_ABC      (AS_BOOL)
#define AS_BOOLEAN_MAX      (AS_BOOL+1)
#define AS_SIGNED_ABC       (AS_SCHAR)
#define AS_SIGNED_MAX       (AS_INTMAX+1)
#define AS_UNSIGNED_ABC     (AS_UCHAR)
#define AS_UNSIGNED_MAX     (AS_UINTMAX+1)
#define AS_INTEGER_MAX      (AS_WCTYPE+1)
#define AS_REAL_MAX         (AS_INTEGER_MAX)
#define AS_SCALAR_MAX       (AS_REAL_MAX)

#define AS_OBJECT_ABC       (AS_OBJECT)
#define AS_UNION_ABC        (AS_UNION)
#define AS_UNION_MAX        (AS_STRUCT_ABC)
#define AS_STRUCT_ABC       (AS_STRUCT)
#define AS_STRUCT_MAX       (AS_FUNCTION_ABC)
#define AS_OBJECT_MAX       (AS_FUNCTION_ABC)
#define AS_FUNCTION_ABC     (AS_FUNCTION)
#define AS_FUNCTION_MAX     (AS_SUBROUTINE+1)

#define AS_SHORT AS_SHRT
#define AS_USHORT AS_USHRT

typedef enum {

    /* {void} */
    AS_VOID=0,      /* 'x' void             */

    /* {scalar, {pointer}} */
    AS_ADDR,        /*  'a' void *              */
    AS_ADDRPTR,       /*  'A' void **             */

    /* {scalar, {character}} */
    AS_CHAR,        /* 'c' char  */

    /* {scalar, {character, {wide}}} */
    AS_WCHAR,       /* --- wchar_t          <stddef.h>      */
    AS_CHAR16,      /* --- char16_t         <uchar.h>       */
    AS_CHAR32,      /* --- char32_t         <uchar.h>       */

    /* {scalar, {real, {floating}}} */
    AS_HALF,        /*  'e' _Float16        */
    AS_FLT,         /*  'f' float           */
    AS_DBL,         /*  'd' double          */
    AS_LDBL,        /*  'D' long double     */
    AS_BIGFLT,      /*  ---                 */

    /* {scalar, {real, {integer, {boolean}}}} */
    AS_BOOL,        /* 'y' bool                 <stdbool.h>     */

    /* {scalar, {real, {integer, {signed}}}}                    */
    AS_SCHAR,       /* 'b' signed char          n/a             */
    AS_SHRT,        /* 'h' signed short         n/a             */
    AS_INT,         /* 'i' signed int           n/a             */
    AS_LONG,        /* 'l' signed long          n/a             */
    AS_LLONG,       /* 'q' signed long long     n/a             */
    AS_XLONG,       /* --- signed __int128      n/a             */
    AS_SSIZE,       /* 'Z' ssize_t              <sys/types.h>   */
    AS_INTPTR,      /* 'p' intptr_r             <stdint.h>      */
    AS_PTRDIFF,     /* 't' ptrdiff_t            <stddef.h>      */
    AS_INT8,        /* 'b' int8_t               <stdint.h>      */
    AS_INT16,       /* 'h' int8_t               <stdint.h>      */
    AS_INT32,       /* 'i' int8_t               <stdint.h>      */
    AS_INT64,       /* 'j' int8_t               <stdint.h>      */
    AS_INTMAX,      /* 'm' intmax_t             <stdint.h>      */

    /* {scalar, {real, {integer, {unsigned}}}}                  */
    AS_UCHAR,       /* 'B' unsigned char        n/a             */
    AS_USHRT,       /* 'H' unsigned short       n/a             */
    AS_UINT,        /* 'I' unsigned int         n/a             */
    AS_ULONG,       /* 'L' unsigned long        n/a             */
    AS_ULLONG,      /* 'Q' unsigned long long   n/a             */
    AS_UXLONG,      /* --- unsigned __int128    n/a             */
    AS_SIZE,        /* 'z' size_t               <stddef.h>      */
    AS_UINTPTR,     /* 'P' uintptr_t            <stdint.h>      */
    AS_UINT8,       /* 'B' uint8_t              <stdint.h>      */
    AS_UINT16,      /* 'H' uint16_t             <stdint.h>      */
    AS_UINT32,      /* 'I' uint32_t             <stdint.h>      */
    AS_UINT64,      /* 'J' uint64_t             <stdint.h>      */
    AS_UINTMAX,     /* 'M' intmax_t             <stdint.h>      */

    /* {scalar, {real, {integer}}} */
    AS_WINT,        /* 'C' wint_t               <wchar.h>       */
    AS_SIG_ATOMIC,  /* --- sig_atomic_t         <signal.h>      */
    AS_BIGINT,      /* 'Y' PyLongObject     */

#   define AS_BLTN_MAX (AS_BIGINT+1)

    /* {scalar, {real, {integer, {signed}}}} */
    AS_OFF,         /* --- off_t                <sys/types.h>   */
    AS_REGOFF,      /* --- regoff_t             <regex.h>       */
    AS_BLKCNT,      /* --- blkcnt_t             <sys/types.h>   */
    AS_BLKSIZE,     /* --- blksize_t            <sys/types.h>   */
    AS_PID,         /* --- pid_t                <sys/types.h>   */
    AS_SUSECONDS,   /* --- suseconds_t          <sys/types.h>   */

    /* {scalar, {real, {integer, {unsigned}}}} */
    AS_CC,          /* --- cc_t                 <termios.h>       */
    AS_SPEED,       /* --- speed_t              <termios.h>       */
    AS_TCFLAG,      /* --- tcflag_t             <termios.h>       */
    AS_INO,         /* --- ino_t                <sys/types.h>     */
    AS_FSBLKCNT,    /* --- fsblkcnt_t           <sys/types.h>     */
    AS_FSFILCNT,    /* --- fsfilcnt_t           <sys/types.h>     */
    AS_MSGQNUM,     /* --- msgqnum_t            <sys/msg.h>       */
    AS_MSGLEN,      /* --- msglen_t             <sys/msg.h>       */
    AS_SA_FAMILY,   /* --- sa_family_t          <sys/socket.h>    */
    AS_NFDS,        /* --- nfds_t               <poll.h>          */
    AS_RLIM,        /* --- rlim_t               <sys/resource.h>    */
    AS_SHMATT,      /* --- shmatt_t             <sys/shm.h> */

    /* {scalar, {real, {integer}}} */

    AS_TIME,        /* --- time_t               <time.h>       */
    AS_CLOCK,       /* --- clock_t              <time.h>       */
    AS_DEV,         /* --- dev_t                <sys/types.h>  */
    AS_IDTYPE,      /* --- idtype_t             <sys/wait.h>  */
    AS_ID,          /* --- id_t                 <sys/types.h>  */
    AS_GID,         /* --- gid_t                <sys/types.h>  */
    AS_UID,         /* --- uid_t                <sys/types.h>  */
    AS_NLINK,       /* --- nlink_t              <sys/types.h>  */
    AS_MODE,        /* --- mode_t               <sys/types.h>  */
    AS_KEY,         /* --- key_t                <sys/types.h>  */
    AS_SOCKLEN,     /* --- socklen_t            <sys/socket.h> */
    AS_NL_ITEM,     /* --- nl_item              <langinfo.h>   */
    AS_NDBM_VISIT,  /* --- VISIT                <search.h>     */
    AS_NDBM_ACTION, /* --- ACTION               <search.h>     */
    AS_WCTYPE,      /* --- wctype_t             <wchar.h> */

    /* {object} */
    AS_OBJECT,
    AS_VA_LIST, 
    AS_FILE,            /* FILE                 <stdio.h>       */
    AS_DIR,             /* DIR                  <dirent.h>      */
    AS_DBM,             /* DBM                  <ndbm.h>        */
    AS_FENV,            /* fenv_t               <fenv.h>        */
    AS_FEXCEPT,         /* fexcept_t            <fenv.h>        */
    AS_FPOS,            /* fpos_t               <stdio.h>       */
    AS_ICONV,           /* iconv_t              <iconv.h>       */
    AS_MBSTATE,         /* mbstate_t            <mbstate.h>     */
    AS_MQD,             /* mqd_t                <mqueue.h>      */
    AS_SIGSET,          /* sigset_t             <signal.h>      */
    AS_MCONTEXT,        /* mcontext_t           <signal.h>      */
    AS_TIMER,           /* timer_t              <time.h>        */
    AS_SEM,             /* sem_t                <semaphore.h>   */
    AS_WCTRANS,         /* wctrans_t            <wchar.h>       */
    AS_PTHREAD,         /* pthread_t            <pthread.h>     */
    AS_PTHREAD_BAR,     /* pthread_barrier_t    <pthread.h>    */
    AS_PTHREAD_CND,     /* pthread_cond_t       <pthread.h>    */
    AS_PTHREAD_ATTR,    /* pthread_attr_t       <pthread.h>    */
    AS_PTHREAD_MTX,     /* pthread_mutex_t      <pthread.h>    */
    AS_PTHREAD_RWLCK,   /* pthread_rwlock_t     <pthread.h>    */
    AS_PTHREAD_SPNLCK,  /* pthread_spinlock_t   <pthread.h>    */
    AS_PTHREAD_BARATTR, /* pthread_barrierattr_t<pthread.h>    */
    AS_PTHREAD_CNDATTR, /* pthread_condattr_t   <pthread.h>    */
    AS_PTHREAD_MTXATTR, /* pthread_mutexattr_t  <pthread.h>    */
    AS_PTHREAD_RWLCKATTR,/*pthread_rwlockattr_t <pthread.h>    */
    AS_PTHREAD_ONCE,    /* pthread_once_t       <pthread.h>    */
    AS_PTHREAD_KEY,     /* pthread_key_t        <pthread.h>    */
    AS_PSPAWN_ATTR,     /* posix_spawnattr_t    <spawn.h>       */
    AS_PSPAWN_FILEACTS, /* posix_spawn_file_actions_t */

    /* {union} */ 
    AS_UNION,
    AS_EPOLL_DATA,  /* epoll_data_t         <sys/epoll.h> */
    AS_SIGVAL,      /* union sigval         <signal.h> */

    /* {struct} */
    AS_STRUCT,
    AS_EPOLL_EVENT, /* struct epoll_event   <sys/epoll.h>   */
    AS_AIOCB,       /* struct aiocb         <aio.h>         */
    AS_DIRENT,      /* struct dirent        <dirent.h>      */
    AS_FLOCK,       /* struct flock         <fcntl.h>       */
    AS_F_OWNER_EX,  /* struct f_owner_ex    <fcntl.h>       */
    AS_FTW,         /* struct FTW           <ftw.h>         */
    AS_GLOB,        /* glob_t               <glob.h>        */
    AS_GROUP,       /* struct group         <grp.h>         */
    AS_LOCALE,      /* locale_t             <locale.h>      */
    AS_DIV,         /* div_t                <stdlib.h>      */
    AS_LDIV,        /* ldiv_t               <stdlib.h>      */
    AS_LLDIV,       /* lldiv_t              <stdlib.h>      */
    AS_IMAXDIV,     /* imaxdiv_t            <inttypes.h>    */
    AS_MQ_ATTR,     /* struct mq_attr       <mqueue.h>      */
    AS_TIMESPEC,    /* struct timespec      <time.h>        */
    AS_TIMEVAL,     /* struct timeval       <sys/time.h>    */
    AS_IN_ADDR,     /* struct in_addr       <netinet/in.h>  */
    AS_IN6_ADDR,    /* struct in_addr       <netinet/in.h>  */

    /* {struct, {sockaddr}} */
    AS_SOCKADDR,    /* struct sockaddr      <sys/socket.h>  */
    AS_SOCKADDR_STG,/* sockaddr_storage     <sys/socket.h>  */
    AS_SOCKADDR_IN, /* struct sockaddr_in   <netinet/in.h>  */
    AS_SOCKADDR_IN6,/* struct sockaddr_in6  <netinet/in.h>  */
    AS_SOCKADDR_UN, /* struct sockaddr_un   <sys/un.h>      */
    AS_IP_MREQ,     /* struct ip_mreq      */
    AS_IPV6_MREQ,
    AS_SOCK_EXT_ERR,/* struct sock_extended_err */
    AS_IP_MREQN,    /* struct ip_mreqn      */
    AS_IP_MREQ_SRC, /* struct ip_mreqn_source      */
    AS_IP_MSFILTER, /* struct ip_msfilter */
    AS_IN_PKTINFO, 
    AS_SOCK_FPROG,  /* struct sock_fprog    <linux/filter.h> */
    AS_UCRED,       /* struct ucred */
    AS_FD_SET,      /* fd_set               <sys/select.h>  */
    AS_LCONV,       /* struct lconv         <locale.h> */
    AS_REGEX,       /* regex_t              <regex.h> */
    AS_REGMATCH,    /* regmatch_t           <regex.h> */

    AS_IPC_PERM,    /* struct ipc_perm      <sys/ipc.h>   */
    AS_MSQID_DS,    /* struct msqid_ds      <sys/msg.h>   */
    AS_SEMID_DS,    /* struct semid_ds      <sys/sem.h>   */
    AS_SEMBUF,      /* struct sembuf        <sys/sem.h>   */
    AS_SHMID_DS,    /* struct shmid_ds      <sys/shm.h>   */
    AS_XSI_DATUM,   /* datum                <ndbm.h> XSI  */
    AS_IF_NAMEINDEX,/* struct if_nameindex  <net/if.h>    */
    AS_HOSTENT,     /* struct hostent       <netdb.h>     */
    AS_SERVENT,     /* struct servent       <netdb.h>     */
    AS_NETENT,      /* struct netent        <netdb.h>     */
    AS_PROTOENT,    /* struct protoent      <netdb.h>     */
    AS_ADDRINFO,    /* struct addrinfo      <netdb.h>     */
    AS_POLLFD,      /* struct pollfd        <poll.h>      */
    AS_PASSWD,      /* struct pwd           <pwd.h>       */
    AS_SCHED_PARAM, /* struct sched_param   <sched.h>     */
    AS_XSI_ENTRY,   /* struct entry         <search.h>    */
    AS_POSIX_TMI,   /* posix_typed_mem_info <sys/mman.h>*/
    AS_RLIMIT,      /* struct rlimit        <sys/resource.h>*/
    AS_RUSAGE,      /* struct rusage        <sys/resource.h>*/
    AS_LINGER,      /* struct linger        <sys/socket.h>  */
    AS_CMSGHDR,     /* struct cmsghdr       <sys/socket.h>  */
    AS_MSGHDR,      /* struct msghdr        <sys/socket.h>  */
    AS_MMSGHDR,     /* struct mmsghdr       <sys/socket.h>  */
    AS_IOVEC,       /* struct iovec         <sys/uio.h>     */
    AS_STAT,        /* struct stat          <sys/stat.h> */
    AS_STATVFS,     /* struct statvfs       <sys/statvfs.h> */
    AS_TMS,         /* struct tms           <sys/times.h>*/
    AS_TM,          /* struct tm            <time.h>*/
    AS_UTSNAME,     /* struct utsname       <sys/utsname.h>*/
    AS_TERMIOS,     /* struct termios       <termios.h> */
    AS_UTMPX,       /* struct utmpx         <utmpx.h>   */
    AS_UTIMBUF,     /* struct utimbuf       <utime.h>   */
    AS_WORDEXP,     /* wordexp_t            <wordexp.h> */
    AS_SIGEVENT,    /* struct sigevent      <signal.h>    */
    AS_SIGINFO,     /* struct siginfo       <signal.h>    */
    AS_SIGACTION,   /* struct sigaction     <signal.h> */
    AS_UCONTEXT,    /* ucontext_t           <signal.h> */
    AS_STACK,       /* stack_t              <signal.h> */
    AS_,     /* struct  @ <.h>*/
    AS_FUNCTION,
    AS_T_MAX,
} AS_T;

/*
    <aio.h> {
        <fcntl.h>
        <signal.h>
        <time.h>
    }
    <arpa/inet.h> {
        <netinet/in.h>
        <inttypes.h>
    }
    <fcntl.h> {
        <sys/stat.h>
        <unistd.h>
    }
    <ftw.h> {
        <sys/stat.h>
    }
    <langinfo.h> {
        <nl_types.h>
    }
    <mqueue.h> {
        <fcntl.h>
        <signal.h>
        <time.h>
    }
    <netdb.h> {
        <netinet/in.h>
        <sys/socket.h>
        <inttypes.h>
    }
    <pthread.h> {
        <sched.h>
        <time.h>
    }
    <sched.h> {
        <time.h>
    }
    <semaphore.h> {
        <fcntl.h>
        <time.h>
    }
    <signal.h> {
        <time.h>
    }
    <spawn.h> {
        <sched.h>
        <signal.h>
    }
    <stdio.h> {
        <stddef.h>
    }
    <stdlib.h> {
        <stddef.h>
        <limits.h>
        <math.h>
        <sys/wait.h>
    }
    <string.h> {
        <stddef.h>
    }
    <sys/resource.h> {
        <sys/time.h>
    }
    <sys/select.h> {
        <signal.h>
        <time.h>
    }
    <sys/sem.h> {
        <sys/ipc.h>
    }
    <sys/shm.h> {
        <sys/ipc.h>
    }
    <sys/socket.h> {
        <sys/uio.h>
    }
    <sys/stat.h> {
        <time.h>
    }
    <sys/time.h> {
        <sys/select.h>
    }
    <sys/times.h> {
        <time.h>
    }
    <sys/wait.h> {
        <signal.h>
    }
    <wchar.h> {
        <ctype.h>
        <string.h>
        <stdarg.h>
        <stddef.h>
        <stdio.h>
        <stdlib.h>
        <time.h>
    }
    <wctype.h> {
        <ctype.h>
        <stdarg.h>
        <stddef.h>
        <stdio.h>
        <stdlib.h>
        <string.h>
        <time.h>
        <wchar.h>
    }
    <unistd.h> {
        <stddef.h>
        <stdint.h>
        <stdio.h>
    }
    <utime.h> {
        <time.h>
    }

*/

struct unsys_type;

union unsys_as {

    void *list[AS_BLTN_MAX];

    struct {

        void                (*as_void)      (void *);

        void *              (*as_addr)      (void *);
        void **             (*as_addrptr)     (void *);

        char                (*as_char)      (void *);

        wchar_t             (*as_wchar)     (void *);
        char16_t            (*as_char16)    (void *);
        char32_t            (*as_char32)    (void *);

        void *              ( as_half);
        float               (*as_flt)       (void *);
        double              (*as_dbl)       (void *);
        long double         (*as_ldbl)      (void *);
        void *              (*as_bigflt)    (void *);

        _Bool               (*as_bool)      (void *);

        signed      char    (*as_schar)     (void *);
        signed short int    (*as_short)     (void *);
        signed       int    (*as_int)       (void *);
        signed long  int    (*as_long)      (void *);
        signed long long    (*as_llong)     (void *);
        void *              ( as_xlong);
        ssize_t             (*as_ssize)     (void *);
        intptr_t            (*as_intptr)    (void *);
        ptrdiff_t           (*as_ptrdiff)   (void *);
        int8_t              (*as_int8)      (void *);
        int16_t             (*as_int16)     (void *);
        int32_t             (*as_int32)     (void *);
        int64_t             (*as_int64)     (void *);
        intmax_t            (*as_intmax)    (void *);

        unsigned      char  (*as_uchar)     (void *);
        unsigned short int  (*as_ushort)    (void *);
        unsigned       int  (*as_uint)      (void *);
        unsigned long  int  (*as_ulong)     (void *);
        unsigned long long  (*as_ullong)    (void *);
        void *               (as_uxlong);
        size_t              (*as_size)      (void *);
        uintptr_t           (*as_uintptr)   (void *);
        uint8_t             (*as_uint8)     (void *);
        uint16_t            (*as_uint16)    (void *);
        uint32_t            (*as_uint32)    (void *);
        uint64_t            (*as_uint64)    (void *);
        uintmax_t           (*as_uintmax)   (void *);

        wint_t              (*as_wint)      (void *);
#if defined(SIG_ATOMIC_MAX)
        sig_atomic_t        (*as_sig_atomic)(void *);
#else
        int                 (*as_sig_atomic)(void *);
#endif
        void *              (*as_bigint)    (void *);
    };
};

/*
#define UNSYS_TPFLAGS_BODY \
    unsigned int\
        t_constant:     1,\
        t_volatile:     1,\
        t_restrict:     1,\
        t_vmax_callable:1,\
        t_vmin_callable:1,\
        :               (32-5);\
    unsigned int\
        t_reserved1:    2,\
        t_netorder:     1,\
        t_vlim_callable:2,\
        :               (32-5);\
    unsigned int\
        t_cvrflags:     3,\
        t_reserved2:    2,\
        :               (32-5);\
    unsigned int\
        t_cvnflags:     3,\
        t_reserved3:    2,\
        :               (32-5);

union unsys_tpflags {UNSYS_TPFLAGS_BODY};
*/
union unsys_tpflags_d {
#define UNSYS_TPFLAGS_DTYPE_BODY unsigned int\
    t_reservedd:29,\
    t_constant: 1,\
    t_volatile: 1,\
    t_netorder: 1,\
    :           0;
    UNSYS_TPFLAGS_DTYPE_BODY
};

union unsys_tpflags_p {
#define UNSYS_TPFLAGS_PTYPE_BODY unsigned int\
    t_reservedp:31,\
    t_restrict: 1,\
    :           0;
    UNSYS_TPFLAGS_PTYPE_BODY
};

union unsys_tpflags {
#define UNSYS_TPFLAGS_BODY \
    unsigned        t_flags_u;      \
    signed          t_flags_s;      \
    unsigned char   t_flags_r[4];   \
    struct {\
        unsigned int \
            t_vmin_callable:    1,  \
            t_vmax_callable:    1,  \
            t_reservedx:       30;  \
    };                              \
    struct {UNSYS_TPFLAGS_DTYPE_BODY};\
    struct {UNSYS_TPFLAGS_PTYPE_BODY};
    UNSYS_TPFLAGS_BODY
};

typedef struct unsys_ctype unsys_t;

struct unsys_ctype {
    /* The representation of a C data type

    The CVR type qualifiers [c]onst, [v]olatile, [r]estrict 
    are declared by setting .t_constant, .t_volatile, and 
    .t_restrict, respectively, to 1. 

    If .t_netorder == 1, values should interpreted using 
    "network" byteorder (i.e. big-endian). Note that because
    pointers are always represented in host byte order, the 
    restrict and unofficial "netorder" qualifiers can use the
    same bit in .t_flags.
    
    .t_vmin, if not NULL, is a function taking the address 
    at which to write the minimum valid value of the type.
    .t_vmin is identical to .t_vmin except for the maximum
    value. Both functions should return the number of bytes 
    stored in the address.

    IMPORTANT: .t_spec must be NULL unless .t_name is already
    a valid identifier (i.e. no spaces). 
    
    */

    const char     *t_name; /* C type's name */
    unsigned short  t_as;   /* typecode (one of AS_*) */
    unsigned short  t_repr; /* representation type (AS_*) */
    unsigned char   t_fmt;  /* format spec (one of *_FMT) */
    signed char     t_ndim; /* level of indirection */
    unsigned char   t_rank; /* conversion rank */
    signed char     t_signedness; /* signedness */
    union {
        UNSYS_TPFLAGS_BODY
        union unsys_tpflags t_flags;
    };
    void *t_vmin; /*size_t (*t_vmin)(void *); get type's minimum valid value */
    void *t_vmax; /*size_t (*t_vmax)(void *); get type's minimum valid value */
    size_t  t_size;     /* size in bytes of one object */ 
    size_t  t_align;    /* alignment requirement */
    size_t  t_length;   /* number of objects in array */
    void  (*t_free)(void *);    /* destroy the type  */
    struct unsys_ctype *t_next; /* type of pointer's contents */
    struct unsys_ctype *t_spec; /* type specifier for declarations */
};

static size_t unsys_GET_BOOL_MAX(_Bool *v) {
    return (*v=1), sizeof *v;
}
static size_t unsys_GET_BOOL_MIN(_Bool *v) {
    return (*v=0), sizeof *v;
}

static size_t unsys_GET_CHAR_MAX(char *v) {
    return (*v=CHAR_MAX), sizeof *v;
}
static size_t unsys_GET_CHAR_MIN(char *v) {
    return (*v=CHAR_MIN), sizeof *v;
}

static size_t unsys_GET_CHAR16_MAX(char16_t *v) {
    return (*v=UINT16_C(0xffff)), sizeof *v;
}
static size_t unsys_GET_CHAR16_MIN(char16_t *v) {
    return (*v=UINT16_C(0)), sizeof *v;
}

static size_t unsys_GET_CHAR32_MAX(char32_t *v) {
    return (*v=UINT32_C(0x10ffff)), sizeof *v;
}
static size_t unsys_GET_CHAR32_MIN(char32_t *v) {
    return (*v=UINT32_C(0)), sizeof *v;
}

static size_t unsys_GET_WCHAR_MAX(wchar_t *v) {
    return (*v=WCHAR_MAX), sizeof *v;
}
static size_t unsys_GET_WCHAR_MIN(wchar_t *v) {
    return (*v=WCHAR_MIN), sizeof *v;
}

static size_t unsys_GET_WINT_MAX(wint_t *v) {
    return (*v=WINT_MAX), sizeof *v;
}
static size_t unsys_GET_WINT_MIN(wint_t *v) {
    return (*v=WINT_MIN), sizeof *v;
}

static size_t unsys_GET_SCHAR_MIN(signed char *v) {
    return (*v=SCHAR_MIN), sizeof *v;
}
static size_t unsys_GET_SCHAR_MAX(signed char *v) {
    return (*v=SCHAR_MAX), sizeof *v;
}
static size_t unsys_GET_UCHAR_MAX(unsigned char *v) {
    return (*v=UCHAR_MAX), sizeof *v;
}

static size_t unsys_GET_SHRT_MIN(short *v) {
    return (*v=SHRT_MIN), sizeof *v;
}
static size_t unsys_GET_SHRT_MAX(short *v) {
    return (*v=SHRT_MAX), sizeof *v;
}
static size_t unsys_GET_USHRT_MAX(unsigned short *v) {
    return (*v=USHRT_MAX), sizeof *v;
}

static size_t unsys_GET_INT_MIN(int *v) {
    return (*v=INT_MIN), sizeof *v;
}
static size_t unsys_GET_INT_MAX(int *v) {
    return (*v=INT_MAX), sizeof *v;
}
static size_t unsys_GET_UINT_MAX(unsigned int *v) {
    return (*v=UINT_MAX), sizeof *v;
}

static size_t unsys_GET_LONG_MIN(long *v) {
    return (*v=LONG_MIN), sizeof *v;
}
static size_t unsys_GET_LONG_MAX(long *v) {
    return (*v=LONG_MAX), sizeof *v;
}
static size_t unsys_GET_ULONG_MAX(unsigned long *v) {
    return (*v=ULONG_MAX), sizeof *v;
}

static size_t unsys_GET_LLONG_MIN(long long *v) {
    return (*v=LLONG_MIN), sizeof *v;
}
static size_t unsys_GET_LLONG_MAX(long long *v) {
    return (*v=LLONG_MAX), sizeof *v;
}
static size_t unsys_GET_ULLONG_MAX(unsigned long long *v) {
    return (*v=ULLONG_MAX), sizeof *v;
}

static size_t unsys_GET_SSIZE_MAX(ssize_t *v) {
    return (*v=SSIZE_MAX), sizeof *v;
}
static size_t unsys_GET_SIZE_MAX(size_t *v) {
    return (*v=SIZE_MAX), sizeof *v;
}

static size_t unsys_GET_PTRDIFF_MAX(ptrdiff_t *v) {
    return (*v=PTRDIFF_MAX), sizeof *v;
}
static size_t unsys_GET_PTRDIFF_MIN(ptrdiff_t *v) {
    return (*v=PTRDIFF_MIN), sizeof *v;
}

static size_t unsys_GET_INTPTR_MIN(intptr_t *v) {
    return (*v=INTPTR_MIN), sizeof *v;
}
static size_t unsys_GET_INTPTR_MAX(intptr_t *v) {
    return (*v=INTPTR_MAX), sizeof *v;
}
static size_t unsys_GET_UINTPTR_MAX(uintptr_t *v) {
    return (*v=UINTPTR_MAX), sizeof *v;
}

static size_t unsys_GET_INT8_MIN(int8_t *v) {
    return (*v=INT8_MIN), sizeof *v;
}
static size_t unsys_GET_INT8_MAX(int8_t *v) {
    return (*v=INT8_MAX), sizeof *v;
}
static size_t unsys_GET_UINT8_MAX(uint8_t *v) {
    return (*v=UINT8_MAX), sizeof *v;
}

static size_t unsys_GET_INT16_MIN(int16_t *v) {
    return (*v=INT16_MIN), sizeof *v;
}
static size_t unsys_GET_INT16_MAX(int16_t *v) {
    return (*v=INT16_MAX), sizeof *v;
}
static size_t unsys_GET_UINT16_MAX(uint16_t *v) {
    return (*v=UINT16_MAX), sizeof *v;
}

static size_t unsys_GET_INT32_MIN(int32_t *v) {
    return (*v=INT32_MIN), sizeof *v;
}
static size_t unsys_GET_INT32_MAX(int32_t *v) {
    return (*v=INT32_MAX), sizeof *v;
}
static size_t unsys_GET_UINT32_MAX(uint32_t *v) {
    return (*v=UINT32_MAX), sizeof *v;
}

static size_t unsys_GET_INT64_MIN(int64_t *v) {
    return (*v=INT64_MIN), sizeof *v;
}
static size_t unsys_GET_INT64_MAX(int64_t *v) {
    return (*v=INT64_MAX), sizeof *v;
}
static size_t unsys_GET_UINT64_MAX(uint64_t *v) {
    return (*v=UINT64_MAX), sizeof *v;
}

static size_t unsys_GET_INTMAX_MIN(intmax_t *v) {
    return (*v=INTMAX_MIN), sizeof *v;
}
static size_t unsys_GET_INTMAX_MAX(intmax_t *v) {
    return (*v=INTMAX_MAX), sizeof *v;
}
static size_t unsys_GET_UINTMAX_MAX(uintmax_t *v) {
    return (*v=UINTMAX_MAX), sizeof *v;
}

static size_t unsys_GET_FLT_MIN(float *v) {
    return (*v=FLT_MIN), sizeof *v;
}
static size_t unsys_GET_FLT_MAX(float *v) {
    return (*v=FLT_MAX), sizeof *v;
}

static size_t unsys_GET_DBL_MIN(double *v) {
    return (*v=DBL_MIN), sizeof *v;
}
static size_t unsys_GET_DBL_MAX(double *v) {
    return (*v=DBL_MAX), sizeof *v;
}

static size_t unsys_GET_LDBL_MIN(long double *v) {
    return (*v=LDBL_MIN), sizeof *v;
}
static size_t unsys_GET_LDBL_MAX(long double *v) {
    return (*v=LDBL_MAX), sizeof *v;
}

static inline uintmax_t
unsys_umax(const int type) {
    switch (type) {
        case AS_VOID:   return UINTMAX_C(0);
        case AS_ADDR:   return (uintmax_t) INTPTR_MAX;
        case AS_ADDRPTR:return (uintmax_t) INTPTR_MAX;

        case AS_CHAR:   return (uintmax_t) CHAR_MAX;
        case AS_WCHAR:  return (uintmax_t) WCHAR_MAX;
        case AS_CHAR16: return (uintmax_t)     u'\uFFFF';
        case AS_CHAR32: return (uintmax_t) U'\U0010FFFF';
        
        case AS_BOOL:   return UINTMAX_C(1);

        case AS_HALF:   return UINTMAX_MAX;
        case AS_FLT:    return UINTMAX_MAX;
        case AS_DBL:    return UINTMAX_MAX;
        case AS_LDBL:   return UINTMAX_MAX;
        case AS_BIGFLT: return UINTMAX_MAX;

        case AS_SCHAR:  return (uintmax_t)   SCHAR_MAX;
        case AS_SHRT:   return (uintmax_t)    SHRT_MAX;
        case AS_INT:    return (uintmax_t)     INT_MAX;
        case AS_LONG:   return (uintmax_t)    LONG_MAX;
        case AS_LLONG:  return (uintmax_t)   LLONG_MAX;
        case AS_XLONG:  return UINTMAX_C(0);
        case AS_SSIZE:  return (uintmax_t)   SSIZE_MAX;
        case AS_INTPTR: return (uintmax_t)  INTPTR_MAX;
        case AS_PTRDIFF:return (uintmax_t) PTRDIFF_MAX;
        case AS_INT8:   return (uintmax_t)    INT8_MAX;
        case AS_INT16:  return (uintmax_t)   INT16_MAX;
        case AS_INT32:  return (uintmax_t)   INT32_MAX;
        case AS_INT64:  return (uintmax_t)   INT64_MAX;
        case AS_INTMAX: return (uintmax_t)  INTMAX_MAX;

        case AS_UCHAR:  return   UCHAR_MAX;
        case AS_USHRT:  return    SHRT_MAX;
        case AS_UINT:   return     INT_MAX;
        case AS_ULONG:  return    LONG_MAX;
        case AS_ULLONG: return   LLONG_MAX;
        case AS_UXLONG: return UINTMAX_C(0);
        case AS_SIZE:   return    SIZE_MAX;
        case AS_UINTPTR:return UINTPTR_MAX;
        case AS_UINT8:  return   UINT8_MAX;
        case AS_UINT16: return  UINT16_MAX;
        case AS_UINT32: return  UINT32_MAX;
        case AS_UINT64: return  UINT64_MAX;
        case AS_UINTMAX:return UINTMAX_MAX;
        case AS_WINT:   return    WINT_MAX;
#   ifdef SIG_ATOMIC_MAX
        case AS_SIG_ATOMIC: return (uintmax_t) SIG_ATOMIC_MAX;
#   else
        case AS_SIG_ATOMIC: return UINTMAX_C(0);
#   endif
        case AS_BIGINT: return UINTMAX_MAX;
        default: {
            printf("unsys_umax: %d is not a valid type", type);
            abort();
        }
    }
}
static inline unsigned short
unsys_impromo(const int type) {
    /* apply C's "implicit promotion" rules to type

    Anything small enough to fit in an int is converted to 
    int. Otherwise, types such as ptrdiff_t and uintmax_t 
    are converted to the builtin type on which they're based.
    
    AS_VOID is returned if type isn't a character or real.

    NOTE: AS_HALF and AS_FLOAT (_Float16, float) and any 
    types based on them are converted to AS_DBL.

    The result is guaranteed to be one of the following:
        AS_VOID
        AS_INT,     AS_UINT 
        AS_LONG,    AS_ULONG 
        AS_LLONG,   AS_ULLONG 
        AS_XLONG,   AS_UXLONG
        AS_DBL,     AS_LDBL
    */
    switch (type) {
        case AS_CHAR:
        case AS_WCHAR:
        case AS_CHAR16:
        case AS_CHAR32:
        case AS_BOOL: 
        case AS_SCHAR:
        case AS_UCHAR:
        case AS_SHRT:
        case AS_USHRT:
        case AS_INT8:
        case AS_UINT8:
        case AS_INT16:
        case AS_UINT16:
        case AS_INT32:
        case AS_INT: return AS_INT;
        case AS_SSIZE: {
#       if SSIZE_RANK <= INT_RANK
            return AS_INT;
#       elif SSIZE_RANK == LONG_RANK
            return AS_LONG;
#       else
#           return AS_LLONG;
#       endif
        }
        case AS_INTPTR: {
#       if INTPTR_RANK <= INT_RANK
            return AS_INT;
#       elif INTPTR_RANK == LONG_RANK
            return AS_LONG;
#       else
#           return AS_LLONG;
#       endif
        }
        case AS_PTRDIFF: {
#       if PTRDIFF_RANK <= INT_RANK
            return AS_INT;
#       elif PTRDIFF_RANK == LONG_RANK
            return AS_LONG;
#       else
#           return AS_LLONG;
#       endif
        }
        case AS_INT64: {
#       if INT64_MAX == LONG_MAX
            return AS_LONG;
#       else
            return AS_LLONG;
#       endif
        }
        case AS_INTMAX: {
#       if INTMAX_MAX == LONG_MAX
            return AS_LONG;
#       else
            return AS_LLONG;
#       endif
        }
        case AS_SIZE: {
#       if SIZE_RANK < UINT_RANK
            return AS_INT;
#       elif SIZE_RANK == UINT_RANK
            return AS_UINT;
#       elif SSIZE_RANK == ULONG_RANK
            return AS_ULONG;
#       else
#           return AS_ULLONG;
#       endif
        }
        case AS_UINTPTR: {
#       if UINTPTR_RANK < UINT_RANK
            return AS_INT;
#       elif UINTPTR_RANK == UINT_RANK
            return AS_UINT;
#       elif UINTPTR_RANK == ULONG_RANK
            return AS_ULONG;
#       else
#           return AS_ULLONG;
#       endif
        }
        case AS_UINT64: {
#       if UINT64_RANK  == ULONG_RANK
            return AS_ULONG;
#       else
            return AS_ULLONG;
#       endif
        }
        case AS_UINTMAX: {
#       if UINTMAX_RANK  == ULONG_RANK
            return AS_ULONG;
#       else
            return AS_ULLONG;
#       endif
        }
        case AS_HALF:
        case AS_FLT: 
        case AS_DBL: return AS_DBL;
        case AS_LDBL:
        case AS_BIGFLT:
        case AS_LONG:
        case AS_LLONG:
        case AS_UINT:
        case AS_ULONG:
        case AS_ULLONG:
        case AS_XLONG:
        case AS_VOID: return type;
        default: return AS_VOID;
    }
}


static const unsigned char 
unsys_rankof[] = {
    [AS_VOID]       = VOID_RANK,
    [AS_ADDR]       = ADDR_RANK,
    [AS_ADDRPTR]    = ADDRPTR_RANK,

    [AS_HALF]       = HALF_RANK,
    [AS_FLT]        = FLT_RANK,
    [AS_DBL]        = DBL_RANK,
    [AS_LDBL]       = LDBL_RANK,
    [AS_BIGFLT]     = BIGFLT_RANK,

    [AS_CHAR]       = CHAR_RANK,
    [AS_WCHAR]      = WCHAR_RANK,
    [AS_CHAR16]     = CHAR16_RANK,
    [AS_CHAR32]     = CHAR32_RANK,

    [AS_BOOL]       = BOOL_RANK,

    [AS_SCHAR]      = SCHAR_RANK,
    [AS_SHRT]       = SHRT_RANK,
    [AS_INT]        = INT_RANK,
    [AS_LONG]       = LONG_RANK,
    [AS_LLONG]      = LLONG_RANK,
    [AS_XLONG]      = XLONG_RANK,
    [AS_SSIZE]      = SSIZE_RANK,
    [AS_INTPTR]     = INTPTR_RANK,
    [AS_PTRDIFF]    = PTRDIFF_RANK,
    [AS_INT8]       = INT8_RANK,
    [AS_INT16]      = INT16_RANK,
    [AS_INT32]      = INT32_RANK,
    [AS_INT64]      = INT64_RANK,
    [AS_INTMAX]     = INTMAX_RANK,

    [AS_UCHAR]      = UCHAR_RANK,
    [AS_USHRT]      = USHRT_RANK,
    [AS_UINT]       = UINT_RANK,
    [AS_ULONG]      = ULONG_RANK,
    [AS_ULLONG]     = ULLONG_RANK,
    [AS_UXLONG]     = UXLONG_RANK,
    [AS_SIZE]       = SIZE_RANK,
    [AS_UINTPTR]    = UINTPTR_RANK,
    [AS_UINT8]      = UINT8_RANK,
    [AS_UINT16]     = UINT16_RANK,
    [AS_UINT32]     = UINT32_RANK,
    [AS_UINT64]     = UINT64_RANK,
    [AS_UINTMAX]    = UINTMAX_RANK,
    
    [AS_WINT]       = WINT_RANK,
    [AS_BIGINT]     = BIGINT_RANK,
};

static const signed char 
unsys_signednessof[] = {

    [AS_VOID]       =    VOID_SIGNEDNESS,

    [AS_ADDR]       =    ADDR_SIGNEDNESS,
    [AS_ADDRPTR]      =   ADDRPTR_SIGNEDNESS,

    [AS_HALF]       =    HALF_SIGNEDNESS,
    [AS_FLT]        =     FLT_SIGNEDNESS,
    [AS_DBL]        =     DBL_SIGNEDNESS,
    [AS_LDBL]       =    LDBL_SIGNEDNESS,
    [AS_BIGFLT]     =  BIGFLT_SIGNEDNESS,

    [AS_CHAR]       =    CHAR_SIGNEDNESS,
    [AS_WCHAR]      =   WCHAR_SIGNEDNESS,
    [AS_CHAR16]     =  CHAR16_SIGNEDNESS,
    [AS_CHAR32]     =  CHAR32_SIGNEDNESS,
    [AS_BOOL]       =    BOOL_SIGNEDNESS,
    [AS_SCHAR]      =   SCHAR_SIGNEDNESS,
    [AS_SHRT]       =    SHRT_SIGNEDNESS,
    [AS_INT]        =     INT_SIGNEDNESS,
    [AS_LONG]       =    LONG_SIGNEDNESS,
    [AS_LLONG]      =   LLONG_SIGNEDNESS,
    [AS_XLONG]      =   XLONG_SIGNEDNESS,
    [AS_SSIZE]      =   SSIZE_SIGNEDNESS,
    [AS_INTPTR]     =  INTPTR_SIGNEDNESS,
    [AS_PTRDIFF]    = PTRDIFF_SIGNEDNESS,
    [AS_INT8]       =    INT8_SIGNEDNESS,
    [AS_INT16]      =   INT16_SIGNEDNESS,
    [AS_INT32]      =   INT32_SIGNEDNESS,
    [AS_INT64]      =   INT64_SIGNEDNESS,
    [AS_INTMAX]     =  INTMAX_SIGNEDNESS,

    [AS_UCHAR]      =   UCHAR_SIGNEDNESS,
    [AS_USHRT]      =   USHRT_SIGNEDNESS,
    [AS_UINT]       =    UINT_SIGNEDNESS,
    [AS_ULONG]      =   ULONG_SIGNEDNESS,
    [AS_ULLONG]     =  ULLONG_SIGNEDNESS,
    [AS_UXLONG]     =  UXLONG_SIGNEDNESS,
    [AS_SIZE]       =    SIZE_SIGNEDNESS,
    [AS_UINTPTR]    = UINTPTR_SIGNEDNESS,
    [AS_UINT8]      =   UINT8_SIGNEDNESS,
    [AS_UINT16]     =  UINT16_SIGNEDNESS,
    [AS_UINT32]     =  UINT32_SIGNEDNESS,
    [AS_UINT64]     =  UINT64_SIGNEDNESS,
    [AS_UINTMAX]    = UINTMAX_SIGNEDNESS,
    [AS_WINT]       =    WINT_SIGNEDNESS,
    [AS_BIGINT]     =  BIGINT_SIGNEDNESS,
};

static const        char *
UNSYS_TYPE_NAME[] = {
    [AS_VOID]       = "void",
    [AS_ADDR]       = NULL,
    [AS_ADDRPTR]    = NULL,
    [AS_HALF]       = "half",
    [AS_FLT]        = "flt",
    [AS_DBL]        = "dbl",
    [AS_LDBL]       = "ldbl",
    [AS_BIGFLT]     = "bigflt",
    [AS_CHAR]       = "char",
    [AS_WCHAR]      = "wchar",
    [AS_CHAR16]     = "char16",
    [AS_CHAR32]     = "char32",
    [AS_BOOL]       = "bool",
    [AS_SCHAR]      = "schar",
    [AS_SHRT]       = "short",
    [AS_INT]        = "int",
    [AS_LONG]       = "long",
    [AS_LLONG]      = "llong",
    [AS_XLONG]      = "xlong",
    [AS_SSIZE]      = "ssize",
    [AS_INTPTR]     = "intptr",
    [AS_PTRDIFF]    = "ptrdiff",
    [AS_INT8]       = "int8",
    [AS_INT16]      = "int16",
    [AS_INT32]      = "int32",
    [AS_INT64]      = "int64",
    [AS_INTMAX]     = "intmax",
    [AS_UCHAR]      = "uchar",
    [AS_USHRT]      = "ushrt",
    [AS_UINT]       = "uint",
    [AS_ULONG]      = "ulong",
    [AS_ULLONG]     = "ullong",
    [AS_UXLONG]     = "uxlong",
    [AS_SIZE]       = "size",
    [AS_UINTPTR]    = "uintptr",
    [AS_UINT8]      = "uint8",
    [AS_UINT16]     = "uint16",
    [AS_UINT32]     = "uint32",
    [AS_UINT64]     = "uint64",
    [AS_UINTMAX]    = "uintmax",
    [AS_WINT]       = "wint",
    [AS_BIGINT]     = "bigint",
    [AS_OFF]        = "off",
    [AS_REGOFF]     = "regoff",
    [AS_BLKCNT]     = "blkcnt",
    [AS_BLKSIZE]    = "blksize",
    [AS_PID]        = "pid",
    [AS_SUSECONDS]  = "suseconds",
    [AS_CC]         = "cc",
    [AS_SPEED]      = "speed",
    [AS_TCFLAG]     = "tcflag",
    [AS_INO]        = "ino",
    [AS_FSBLKCNT]   = "fsblkcnt",
    [AS_FSFILCNT]   = "fsfilcnt",
    [AS_MSGQNUM]    = "msgqnum",
    [AS_MSGLEN]     = "msglen",
    [AS_SA_FAMILY]  = "sa_family",
    [AS_NFDS]       = "nfds",
    [AS_RLIM]       = "rlim",
    [AS_SHMATT]     = "shmatt",
    [AS_TIME]       = "time",
    [AS_CLOCK]      = "clock",
    [AS_DEV]        = "dev",
    [AS_IDTYPE]     = "idtype",
    [AS_ID]         = "id",
    [AS_GID]        = "gid",
    [AS_UID]        = "uid",
    [AS_NLINK]      = "nlink",
    [AS_MODE]       = "mode",
    [AS_KEY]        = "key",
    [AS_SOCKLEN]    = "socklen",
    [AS_NL_ITEM]    = "nl_item",
    [AS_NDBM_VISIT] = "NDBM_VISIT",
    [AS_NDBM_ACTION]= "NDBM_ACTION",
    [AS_WCTYPE]     = "WCTYPE",
};

static unsys_t *unsys_ctypes = (unsys_t[]){

    [AS_VOID] = {
        .t_name         = "void",
        .t_as           = AS_VOID,
        .t_fmt          = VOID_FMT,
        .t_size         = 1,
        .t_align        = 1,
        .t_rank         = VOID_RANK,
        .t_signedness   = VOID_SIGNEDNESS,
    },
    
    [AS_ADDR] = {
        .t_name         = NULL, 
        .t_as           = AS_ADDR, 
        .t_fmt          = ADDR_FMT,
        .t_size         = sizeof(void *),
        .t_align        = alignof(void *),
        .t_rank         = ADDR_RANK,
        .t_signedness   = ADDR_SIGNEDNESS,
    },
    [AS_ADDRPTR] = {
        .t_name         = NULL, 
        .t_as           = AS_ADDRPTR,
        .t_fmt          = ADDRPTR_FMT,
        .t_size         = sizeof(void **),
        .t_align        = alignof(void **),
        .t_rank         = ADDRPTR_RANK, 
        .t_signedness   = ADDRPTR_SIGNEDNESS,
    },
    [AS_FLT] = {
        .t_name         = "float", 
        .t_as           = AS_FLT,
        .t_fmt          = FLT_FMT,
        .t_vmax         = unsys_GET_FLT_MAX,
        .t_vmin         = unsys_GET_FLT_MIN,
        //.t_vmax         = {&unsys_c_limits.flt_max},
        .t_size         = sizeof(float),
        .t_align        = alignof(float),
        .t_rank         = FLT_RANK,
        .t_signedness   = FLT_SIGNEDNESS,
    },
    [AS_DBL] = {
        .t_name         = "double", 
        .t_as           = AS_DBL, 
        .t_fmt          = DBL_FMT,
        .t_vmax         = unsys_GET_DBL_MAX,
        .t_vmin         = unsys_GET_DBL_MIN,
//      .t_vmax         = {&unsys_c_limits.dbl_max},
        .t_size         = sizeof(double),
        .t_align        = alignof(double),
        .t_rank         = DBL_RANK,
        .t_signedness   = DBL_SIGNEDNESS,
    },
    [AS_LDBL] = {
        .t_name         = "long double", 
        .t_as           = AS_LDBL, 
        .t_fmt          = LDBL_FMT,
        .t_vmax         = unsys_GET_LDBL_MAX,
        .t_vmin         = unsys_GET_LDBL_MIN,
//      .t_vmax         = {&unsys_c_limits.dbl_max},
        .t_size         = sizeof(long double),
        .t_align        = alignof(long double),
        .t_rank         = LDBL_RANK,
        .t_signedness   = LDBL_SIGNEDNESS,
    },

    [AS_BOOL] = {
        .t_name         = "_Bool", 
        .t_as           = AS_BOOL, 
        .t_fmt          = BOOL_FMT, 
        .t_vmax         = unsys_GET_BOOL_MAX,
        .t_vmin         = unsys_GET_BOOL_MIN,
//      .t_vmax         = {&unsys_c_limits.bool_max},
//      .t_vmin         = {&unsys_c_limits.bool_min},
        .t_size         = sizeof(_Bool),
        .t_align        = alignof(_Bool),
        .t_rank         = BOOL_RANK,
        .t_signedness   = BOOL_SIGNEDNESS,
    },
    [AS_CHAR] = {
        .t_name         = "char",
        .t_as           = AS_CHAR,
        .t_fmt          = CHAR_FMT,
        .t_vmin         = unsys_GET_CHAR_MIN,
        .t_vmax         = unsys_GET_CHAR_MAX,
//      .t_vmax         = {&unsys_c_limits.char_max},
//      .t_vmin         = {&unsys_c_limits.char_min},
        .t_size         = sizeof(char),
        .t_align        = alignof(char),
        .t_rank         = CHAR_RANK,
        .t_signedness   = CHAR_SIGNEDNESS,
    },
    
    [AS_CHAR16] = {
        .t_name         = "char16_t", 
        .t_as           = AS_CHAR16, 
        .t_fmt          = CHAR16_FMT,
        .t_vmin         = unsys_GET_CHAR16_MIN,
        .t_vmax         = unsys_GET_CHAR16_MAX,
//      .t_vmax         = {&unsys_c_limits.char16_max},
        .t_size         = sizeof(char16_t),
        .t_align        = alignof(char16_t),
        .t_rank         = CHAR16_RANK,
        .t_signedness   = CHAR16_SIGNEDNESS,
    },
    [AS_CHAR32] = {
        .t_name         = "char32_t", 
        .t_as           = AS_CHAR32, .t_fmt = CHAR32_FMT,
        .t_vmin         = unsys_GET_CHAR32_MIN,
        .t_vmax         = unsys_GET_CHAR32_MAX,
//      .t_vmax         = {&unsys_c_limits.char32_max},
        .t_size         = sizeof(char32_t),
        .t_align        = alignof(char32_t),
        .t_rank         = CHAR32_RANK,
        .t_signedness   = CHAR32_SIGNEDNESS,
    },
    [AS_SCHAR] = {
        .t_name         = "signed char", 
        .t_as           = AS_SCHAR, 
        .t_fmt          = SCHAR_FMT,
        .t_vmin         = unsys_GET_SCHAR_MIN,
        .t_vmax         = unsys_GET_SCHAR_MAX,
//      .t_vmax         = {&unsys_c_limits.schar_max},
//      .t_vmin         = {&unsys_c_limits.schar_min},
        .t_size         = sizeof(signed char),
        .t_align        = alignof(signed char),
        .t_rank         = SCHAR_RANK,
        .t_signedness   = SCHAR_SIGNEDNESS,
    },
    [AS_SHRT] = {
        .t_name         = "short", 
        .t_as           = AS_SHRT,
        .t_fmt          = SHRT_FMT,
        .t_vmin         = unsys_GET_SHRT_MIN,
        .t_vmax         = unsys_GET_SHRT_MAX,
//      .t_vmax         = {&unsys_c_limits.shrt_max},
//      .t_vmin         = {&unsys_c_limits.shrt_min},
        .t_size         = sizeof(short),
        .t_align        = alignof(short),
        .t_rank         = SHRT_RANK,
        .t_signedness   = SHRT_SIGNEDNESS,
    },
    [AS_INT] = {
        .t_name         = "int", 
        .t_as           = AS_INT, 
        .t_fmt          = INT_FMT,
        .t_vmin         = unsys_GET_INT_MIN,
        .t_vmax         = unsys_GET_INT_MAX,
//      .t_vmax         = {&unsys_c_limits.int_max},
//      .t_vmin         = {&unsys_c_limits.int_min},
        .t_size         = sizeof(int),
        .t_align        = alignof(int),
        .t_rank         = INT_RANK,
        .t_signedness   = INT_SIGNEDNESS,
    },
    [AS_LONG] = {
        .t_name         = "long", 
        .t_as           = AS_LONG, 
        .t_fmt          = LONG_FMT,
        .t_vmin         = unsys_GET_LONG_MIN,
        .t_vmax         = unsys_GET_LONG_MAX,
//      .t_vmax         = {&unsys_c_limits.long_max},
//      .t_vmin         = {&unsys_c_limits.long_min},
        .t_size         = sizeof(long),
        .t_align        = alignof(long),
        .t_rank         = LONG_RANK,
        .t_signedness   = LONG_SIGNEDNESS,
    },
    [AS_LLONG] = {
        .t_name         = "long long", 
        .t_as           = AS_LLONG,
        .t_fmt          = LLONG_FMT,
        .t_vmin         = unsys_GET_LLONG_MIN,
        .t_vmax         = unsys_GET_LLONG_MAX,
//      .t_vmax         = {&unsys_c_limits.llong_max},
//      .t_vmin         = {&unsys_c_limits.llong_min},
        .t_size         = sizeof(long long),
        .t_align        = alignof(long long),
        .t_rank         = LLONG_RANK,
        .t_signedness   = LLONG_SIGNEDNESS,
    },
    [AS_SSIZE] = {
        .t_name         = "ssize_t",
        .t_as           = AS_SSIZE,
        .t_fmt          = SSIZE_FMT,
        .t_vmax         = unsys_GET_SSIZE_MAX,
//      .t_vmax         = {&unsys_c_limits.ssize_max},
        .t_size         = sizeof(ssize_t),
        .t_align        = alignof(ssize_t),
        .t_rank         = SSIZE_RANK,
        .t_signedness   = SSIZE_SIGNEDNESS,
    },
    [AS_INTPTR] = {
        .t_name         = "intptr_t", 
        .t_as           = AS_INTPTR, 
        .t_fmt          = INTPTR_FMT,
        .t_vmin         = unsys_GET_INTPTR_MIN,
        .t_vmax         = unsys_GET_INTPTR_MAX,
//      .t_vmax         = {&unsys_c_limits.intptr_max},
//      .t_vmin         = {&unsys_c_limits.intptr_min},
        .t_size         = sizeof(intptr_t),
        .t_align        = alignof(intptr_t),
        .t_rank         = INTPTR_RANK,
        .t_signedness   = INTPTR_SIGNEDNESS,
    },
    [AS_PTRDIFF] = {
        .t_name         = "ptrdiff_t",
        .t_as           = AS_PTRDIFF,
        .t_fmt          = PTRDIFF_FMT,
        .t_vmin         = unsys_GET_PTRDIFF_MIN,
        .t_vmax         = unsys_GET_PTRDIFF_MAX,
//      .t_vmax         = {&unsys_c_limits.ptrdiff_max},
//      .t_vmin         = {&unsys_c_limits.ptrdiff_min},
        .t_size         = sizeof(ptrdiff_t),
        .t_align        = alignof(ptrdiff_t),
        .t_rank         = PTRDIFF_RANK,
        .t_signedness   = PTRDIFF_SIGNEDNESS,
    },
    [AS_INT8] = {
        .t_name         = "int8_t", 
        .t_as           = AS_INT8, 
        .t_fmt          = INT8_FMT,
        .t_vmin         = unsys_GET_INT8_MIN,
        .t_vmax         = unsys_GET_INT8_MAX,
//      .t_vmax         = {&unsys_c_limits.int8_max},
//      .t_vmin         = {&unsys_c_limits.int8_min},
        .t_size         = sizeof(int8_t),
        .t_align        = alignof(int8_t),
        .t_rank         = INT8_RANK,
        .t_signedness   = INT8_SIGNEDNESS,
    },
    [AS_INT16] = {
        .t_name         = "int16_t", 
        .t_as           = AS_INT16, 
        .t_fmt          = INT16_FMT,
        .t_vmin         = unsys_GET_INT16_MIN,
        .t_vmax         = unsys_GET_INT16_MAX,
//      .t_vmax         = {&unsys_c_limits.int16_max},
//      .t_vmin         = {&unsys_c_limits.int16_min},
        .t_align        = alignof(int16_t),
        .t_size         = sizeof(int16_t),
        .t_rank         = INT16_RANK,
        .t_signedness   = INT16_SIGNEDNESS,
    },
    [AS_INT32] = {
        .t_name         = "int32_t",
        .t_as           = AS_INT32, 
        .t_fmt          = INT32_FMT,
        .t_vmin         = unsys_GET_INT32_MIN,
        .t_vmax         = unsys_GET_INT32_MAX,
//      .t_vmax         = {&unsys_c_limits.int32_max},
//      .t_vmin         = {&unsys_c_limits.int32_min},
        .t_align        = alignof(int32_t),
        .t_size         = sizeof(int32_t),
        .t_rank         = INT32_RANK,
        .t_signedness   = INT32_SIGNEDNESS,
    },
    [AS_INT64] = {
        .t_name         = "int64_t", 
        .t_as           = AS_INT64, 
        .t_fmt          = INT64_FMT,
        .t_vmin         = unsys_GET_INT64_MIN,
        .t_vmax         = unsys_GET_INT64_MAX,
//      .t_vmax         = {&unsys_c_limits.int64_max},
//      .t_vmin         = {&unsys_c_limits.int64_min},
        .t_size         = sizeof(int64_t),
        .t_align        = alignof(int64_t),
        .t_rank         = INT64_RANK,
        .t_signedness   = INT64_SIGNEDNESS,
    },
    [AS_INTMAX] = {
        .t_name         = "intmax_t", 
        .t_as           = AS_INTMAX, 
        .t_fmt          = INTMAX_FMT,
        .t_vmin         = unsys_GET_INTMAX_MIN,
        .t_vmax         = unsys_GET_INTMAX_MAX,
//      .t_vmax         = {&unsys_c_limits.intmax_max},
//      .t_vmin         = {&unsys_c_limits.intmax_min},
        .t_size         = sizeof(intmax_t),
        .t_align        = alignof(intmax_t),
        .t_rank         = INTMAX_RANK,
        .t_signedness   = INTMAX_SIGNEDNESS,
    },

    [AS_UCHAR] = {
        .t_name         = "unsigned char", 
        .t_as           = AS_UCHAR,
        .t_fmt          = UCHAR_FMT,
        .t_vmax         = unsys_GET_UCHAR_MAX,
//      .t_vmax         = {&unsys_c_limits.uchar_max},
        .t_size         = sizeof(unsigned char),
        .t_align        = alignof(unsigned char),
        .t_rank         = UCHAR_RANK,
        .t_signedness   = UCHAR_SIGNEDNESS,
    },
    [AS_USHRT] = {
        .t_name         = "unsigned short", 
        .t_as           = AS_USHORT, 
        .t_fmt          = USHRT_FMT,
        .t_vmax         = unsys_GET_USHRT_MAX,
//      .t_vmax         = {&unsys_c_limits.ushrt_max},
        .t_size         = sizeof(unsigned short),
        .t_align        = alignof(unsigned short),
        .t_rank         = USHRT_RANK,
        .t_signedness   = USHRT_SIGNEDNESS,
    },
    [AS_UINT] = {
        .t_name         = "unsigned int", 
        .t_as           = AS_UINT, 
        .t_fmt          = UINT_FMT,
        .t_vmax         = unsys_GET_UINT_MAX,
//      .t_vmax         = {&unsys_c_limits.uint_max},
        .t_size         = sizeof(unsigned int),
        .t_rank         = UINT_RANK,
        .t_signedness   = UINT_SIGNEDNESS,
    },
    [AS_ULONG] = {
        .t_name         = "unsigned long", 
        .t_as           = AS_ULONG,
        .t_fmt          = ULONG_FMT,
        .t_vmax         = unsys_GET_ULONG_MAX,
//      .t_vmax         = {&unsys_c_limits.ulong_max},
        .t_size         = sizeof(unsigned long),
        .t_rank         = ULONG_RANK,
        .t_signedness   = ULONG_SIGNEDNESS,
    },
    [AS_ULLONG] = {
        .t_name         = "unsigned long long", 
        .t_as           = AS_ULLONG, 
        .t_fmt          = ULLONG_FMT,
        .t_vmax         = unsys_GET_ULLONG_MAX,
//      .t_vmax         = {&unsys_c_limits.ullong_max},
        .t_size         = sizeof(unsigned long long),
        .t_rank         = ULLONG_RANK,
        .t_signedness   = ULLONG_SIGNEDNESS,
    },
    [AS_SIZE] = {
        .t_name         = "size_t",
        .t_as           = AS_SIZE,
        .t_fmt          = SIZE_FMT,
        .t_vmax         = unsys_GET_SIZE_MAX,
//      .t_vmax         = {&unsys_c_limits.size_max},
        .t_size         = sizeof(size_t),
        .t_rank         = SIZE_RANK,
        .t_signedness   = SIZE_SIGNEDNESS,
    },
    [AS_UINTPTR] = {
        .t_name         = "uintptr_t", 
        .t_as           = AS_UINTPTR, 
        .t_fmt          = UINTPTR_FMT,
        .t_vmax         = unsys_GET_UINTPTR_MAX,
//      .t_vmax         = {&unsys_c_limits.uintptr_max},
        .t_size         = sizeof(uintptr_t),
        .t_rank         = UINTPTR_RANK,
        .t_signedness   = UINTPTR_SIGNEDNESS,
    },

    [AS_UINT8] = {
        .t_name         = "uint8_t", 
        .t_as           = AS_UINT8, 
        .t_fmt          = UINT8_FMT,
        .t_vmax         = unsys_GET_UINT8_MAX,
//      .t_vmax         = {&unsys_c_limits.uint8_max},
        .t_size         = sizeof(uint8_t),
        .t_rank         = UINT8_RANK,
        .t_signedness   = UINT8_SIGNEDNESS,
    },
    [AS_UINT16] = {
        .t_name         = "uint16_t",
        .t_as           = AS_UINT16,
        .t_fmt          = UINT16_FMT,
        .t_vmax         = unsys_GET_UINT16_MAX,
//      .t_vmax         = {&unsys_c_limits.uint16_max},
        .t_size         = sizeof(uint16_t),
        .t_rank         = UINT16_RANK,
        .t_signedness   = UINT16_SIGNEDNESS,
    },
    [AS_UINT32] = {
        .t_name         = "uint32_t", 
        .t_as           = AS_UINT32,
        .t_fmt          = UINT32_FMT,
        .t_vmax         = unsys_GET_UINT32_MAX,
//      .t_vmax         = {&unsys_c_limits.uint32_max},
        .t_size         = sizeof(uint32_t),
        .t_rank         = UINT32_RANK,
        .t_signedness   = UINT32_SIGNEDNESS,
    },
    [AS_UINT64] = {
        .t_name         = "uint64_t", 
        .t_as           = AS_UINT64, 
        .t_fmt          = UINT64_FMT,
        .t_vmax         = unsys_GET_UINT64_MAX,
//      .t_vmax         = {&unsys_c_limits.uint64_max},
        .t_size         = sizeof(uint64_t),
        .t_rank         = UINT64_RANK,
        .t_signedness   = UINT64_SIGNEDNESS,
    },
    [AS_UINTMAX] = {
        .t_name         = "intmax_t", 
        .t_as           = AS_UINTMAX, 
        .t_fmt          = UINTMAX_FMT,
        .t_vmax         = unsys_GET_UINTMAX_MAX,
//      .t_vmax         = {&unsys_c_limits.uintmax_max},
        .t_size         = sizeof(uintmax_t),
        .t_rank         = UINTMAX_RANK,
        .t_signedness   = UINTMAX_SIGNEDNESS,
    },

    [AS_WINT] = {
        .t_name         = "wint_t", 
        .t_as           = AS_WINT,
        .t_fmt          = WINT_FMT,
        .t_vmax         = unsys_GET_WINT_MAX,
        .t_vmin         = unsys_GET_WINT_MIN,
//      .t_vmax         = {&unsys_c_limits.wint_max},
//      .t_vmin         = {&unsys_c_limits.wint_min},
        .t_size         = sizeof(wint_t),
        .t_align        = alignof(wint_t),
        .t_rank         = WINT_RANK,
        .t_signedness   = WINT_SIGNEDNESS,
    },
};

struct unsys_ctype_ex {
    unsys_t t;
    char name[1024];
};

enum {
    CVRF_C_SHIFT=0,
    CVRF_V_SHIFT=1,
    CVRF_R_SHIFT=2,
#   define CVRF_X   (0U)
#   define CVRF_C   (1U<<CVRF_C_SHIFT)
#   define CVRF_V   (1U<<CVRF_V_SHIFT)
#   define CVRF_R   (1U<<CVRF_R_SHIFT)
#   define CVRF_N   CVRF_R
#   define CVRF_XXX CVRF_X
#   define CVRF_CXX     (CVRF_C)
#   define CVRF_XVX            (CVRF_V)
#   define CVRF_XXR                   (CVRF_R)
#   define CVRF_XXN                   (CVRF_N)
#   define CVRF_XVR            (CVRF_V|CVRF_R)
#   define CVRF_XVN            (CVRF_V|CVRF_N)
#   define CVRF_CXR     (CVRF_C    |   CVRF_R)
#   define CVRF_CXN     (CVRF_C    |   CVRF_N)
#   define CVRF_CVX     (CVRF_C|CVRF_V)
#   define CVRF_CVR     (CVRF_C|CVRF_V|CVRF_R)
#   define CVRF_CVN     (CVRF_C|CVRF_V|CVRF_N)


};

static const char *
UNSYS_DTYPE_CVRS[] = {
    [CVRF_XXX] = "%s",
    [CVRF_CXX] = "const %s",
    [CVRF_XVX] = "volatile %s",
    [CVRF_CVX] = "volatile const %s",
    [CVRF_XXN] = "%s",
    [CVRF_CXN] = "const %s",
    [CVRF_XVN] = "volatile %s",
    [CVRF_CVN] = "volatile const %s",
};

static const char *
UNSYS_PTYPE_CVRS[] = {
    [CVRF_XXX] = "*",
    [CVRF_XXR] = "*" "restrict",
    [CVRF_XVX] = "*"             "volatile",
    [CVRF_XVR] = "*" "restrict " "volatile",
    [CVRF_CXX] = "*"                         "const",
    [CVRF_CXR] = "*" "restrict "             "const",
    [CVRF_CVX] = "*"             "volatile " "const",
    [CVRF_CVR] = "*" "restrict " "volatile " "const",
};

static const char *
UNSYS_DTYPE_SFX[] = {
    [CVRF_XXX] = "t", /*                char {ID}_t; */
    [CVRF_CXX] = "c", /*          const char {ID}_c; */
    [CVRF_XVX] = "v", /* volatile       char {ID}_v; */
    [CVRF_CVX] = "vc",/* volatile const char {ID}_vc; */
    [CVRF_XXN] = "n", /*                char {ID}_t; */
    [CVRF_CXN] = "nc", /*          const char {ID}_c; */
    [CVRF_XVN] = "nv", /* volatile       char {ID}_v; */
    [CVRF_CVN] = "nvc",/* volatile const char {ID}_vc; */
};

static const char *
UNSYS_PTYPE_SFX[] = {
    [CVRF_XXX] = "p", /* char *{ID}_p */
    [CVRF_CXX] = "cp",/* char *const {ID}_cp*/
    [CVRF_XVX] = "vp",/* char *volatile {ID}_vp */
    [CVRF_CVX] = "vcp",/* char *volatile const {ID}_cvp */
    [CVRF_XXR] = "rp",/* char *restrict {ID}_rp */
    [CVRF_CXR] = "rcp",/* char *restrict const {ID}_rcp */
    [CVRF_XVR] = "rvp",/* char *restrict volatile {ID}_rvp */
    [CVRF_CVR] = "rvcp",/* char *restrict volatile const {ID}_rvcp */
};

static inline void
unsys_TPFLAGS_IOR_CVRF(union unsys_tpflags *flags, unsigned cvf) {
    if ((cvf&CVRF_C) == CVRF_C) {
        flags->t_constant = 1;
    }
    if ((cvf&CVRF_V) == CVRF_V) {
        flags->t_volatile = 1;
    }
    if ((cvf&CVRF_R) == CVRF_R) {
        flags->t_restrict = 1;
    }
#   if CVRF_R != CVRF_N
    if ((cvf&CVRF_N) == CVRF_N) {
        flags->t_netorder = 1;
    }
#   endif
}

static inline unsigned
unsys_TPFLAGS_AS_CVRF(const union unsys_tpflags *flags, unsigned cvf) {
    if (flags->t_constant == 1U) {
        cvf |= CVRF_C;
    }
    if (flags->t_volatile == 1U) {
        cvf |= CVRF_V;
    }
    if (flags->t_restrict == 1U) {
        cvf |= CVRF_R;
    }
#   if CVRF_N != CVRF_R 
    if (flags->t_netorder == 1U) {
        cvf |= CVRF_N;
    }
#   endif 
    return cvf;
}

static inline const char *
unsys_TYPENAME(unsys_t *c) {
    return (!c->t_spec) ? UNSYS_TYPE_NAME[c->t_as] : c->t_name;
}

static inline unsys_t *
unsys_TYPEDEF(unsys_t *c, unsigned cvf, size_t length) {
    const char *head;
    const char**tail;
    struct unsys_ctype_ex *base = malloc(sizeof(struct unsys_ctype_ex));
    if (base == NULL) {
        return NULL;
    }
    unsys_t *t = memset(&base->t, 0, sizeof base->t);
    t->t_free = free;
    if (c->t_ndim == 0) {
        assert(c->t_next == NULL);
        assert(c->t_name != NULL);
        if (length == 0) {
            head = UNSYS_TYPE_NAME[c->t_as];
            tail = UNSYS_DTYPE_SFX;
            cvf = unsys_TPFLAGS_AS_CVRF(&c->t_flags, cvf);
            t->t_as         = c->t_as;
            t->t_fmt        = c->t_fmt;
            t->t_rank       = c->t_rank;
            t->t_vmin       = c->t_vmin;
            t->t_vmax       = c->t_vmax;
            t->t_size       = c->t_size;
            t->t_align      = c->t_align;
            t->t_signedness = c->t_signedness;
            t->t_spec       = c;
            unsys_TPFLAGS_IOR_CVRF(&t->t_flags, cvf);
        }
        else {
            if (c->t_spec == NULL) {
                head = UNSYS_TYPE_NAME[c->t_as];
            }
            else {
                if (unsys_TPFLAGS_AS_CVRF(&c->t_flags, 0)) {
                    head = c->t_name;
                }
                else {
                    head = UNSYS_TYPE_NAME[c->t_as];
                }
            }
            tail        = UNSYS_PTYPE_SFX;
            t->t_as     = AS_ADDR;
            t->t_fmt    = ADDR_FMT;
            t->t_ndim   = 1;
            t->t_length = length;
            t->t_size   = sizeof(void *),
            t->t_align  = alignof(void *),
            t->t_next   = c;
            t->t_spec   = c;
            if (cvf) {
                unsys_TPFLAGS_IOR_CVRF(&t->t_flags, cvf);
            }
        }
    }
    else {
        if (length == 0) {
            cvf = unsys_TPFLAGS_AS_CVRF(&c->t_flags, cvf);
            unsys_TPFLAGS_IOR_CVRF(&t->t_flags, cvf);
            head        = c->t_next->t_name;
            t->t_as     = c->t_as;
            t->t_fmt    = c->t_fmt;
            t->t_ndim   = c->t_ndim;
            t->t_length = c->t_length;
            t->t_next   = c->t_next;
        }
        else {
            if (c->t_ndim > 63) {
                errno = EINVAL;
                t->t_free(t);
                return NULL;
            }
            head        = c->t_name;
            t->t_as     = AS_ADDRPTR;
            t->t_fmt    = ADDRPTR_FMT;
            t->t_ndim   = c->t_ndim+1;
            t->t_length = length;
            t->t_next   = c;
            if (cvf) {
                unsys_TPFLAGS_IOR_CVRF(&t->t_flags, cvf);
            }
        }
        t->t_size   = c->t_size;
        t->t_align  = c->t_align;
        t->t_spec   = c->t_spec;
        tail = UNSYS_PTYPE_SFX;
    }
    char *end = base->name;
    while (*head) {*end++ = *head++;}
    *end++ = '_';
    head = tail[cvf];
    while (*head) {*end++ = *head++;}
    t->t_name = base->name;
    return t;
}

static unsys_t *
unsys_typedef(unsys_t *spec, unsigned cvf, size_t length) {
/*
Define a new type. cvf is, for data typedefs, any combo of
flags representing: 
    CVRF_C (const)
    CVRF_V (volatile)
    CVRF_N (netorder)
For pointers, substitute CVRF_R (restrict) for CVRF_N.
Qualifers can be added only, as in C:
    typedef const char char_c;
    typedef volatile char_c char_vc;
    // char_vc is const and volatile qualified
    typedef char *char_p;
    typedef restrict char_p char_rp;
    // char_rp is char *restrict 
    
    
Specifying a nonzero length creates a pointer to spec.

The result is actually a struct unsys_ctype_ex, which has 
extra space at the end for the t_name field.
*/
    return unsys_TYPEDEF(spec, cvf, length);
}

static inline bool
unsys_IS_SCALAR(AS_T t) {
    return (AS_SCALAR_ABC <= t) && (t < AS_SCALAR_MAX);
}

static inline bool
unsys_IS_CHAR(AS_T t) {
    return (AS_CHARACTER_ABC <= t) && (t < AS_CHARACTER_MAX);
}

static inline bool
unsys_IS_REAL(AS_T t) {
    return (AS_REAL_ABC <= t) && (t < AS_REAL_MAX);
}

static inline bool
unsys_IS_INTEGER(AS_T t) {
    return (AS_INTEGER_ABC <= t) && (t < AS_INTEGER_MAX);
}
static inline signed char
unsys_SIGNEDNESSOF(AS_T t) {
    return unsys_signednessof[t];
}
static inline signed char
unsys_RANKOF(AS_T t) {
    return unsys_rankof[t];
}

#define BI_IS_INPLACE(op) ((op%2) == 1)

typedef enum {
    /* in place ops must be odd 
    * If op is odd it's in place (BI_IS_INPLACE)
    * If op is even it's not in place
    * op-1 for in place op gets the not-in-place version 
    */
    BI_IGNORE,  BI_IIGNORE, // placeholder 
    BI_ADD,     BI_IADD,    // num addition, seq concatenation 
    BI_SUB,     BI_ISUB,    // num subtraction, set difference 
    BI_MUL,     BI_IMUL,    // num multiplication, seq repetition 
    BI_POW,     BI_IPOW,    // num exponentiation 
    BI_DIV,     BI_IDIV,    // num division, seq joining
    BI_FDIV,    BI_IFDIV,   // num fdivision
    BI_MOD,     BI_IMOD,    // num remainder, str format 
    BI_MAT,     BI_IMAT,    // mat multiplication 
    BI_AND,     BI_IAND,    // bit AND, set intersection 
    BI_OR,      BI_IOR,     // bit OR, set union
    BI_XOR,     BI_IXOR,    // bit XOR, set symmetric difference 
    BI_LSH,     BI_ILSH,    // bit left shift
    BI_RSH,     BI_IRSH,    // bit right shift
    BI_RCV,     BI_IRCV,    // dst <<< src, dst.recv(src)
    BI_SND,     BI_ISND,    // src >>> dst, src.send(dst)
    BI_LT,      BI_RES1,    // cmp a < b, set isstrsubset
    BI_LE,      BI_RES2,    // cmp a ≤ b, set issubset
    BI_AE,      BI_RES3,    // cmp a ≈ b
    BI_EQ,      BI_IASS,    // cmp a = b
    BI_NE,      BI_RES5,    // cmp a ≠ b
    BI_GT,      BI_RES6,    // cmp a > b, set isstrsupset 
    BI_GE,      BI_RES7,    // cmp a ≥ b, set issupsetc 
    BI_CONTAINS,BI_RES9,    // obj a contains item b
    BI_GETITEM, BI_RESA,    // a[b] 
    BI_T_MAX,
} BI_T;
