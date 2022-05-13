#ifndef _XBD_H
#define _XBD_H
struct c_ffi;

#   define __basedef(var, paf)    \
    Header var = {.path = paf,

#   define __baseret(var) };return Header_print(&var, file);

#define __predef(p) {\
    .name=p,       \
    .defs=(Const[]) {
#define __preend(ignore, ...) {0}}, __VA_ARGS__},

#define __dentr(a, t) .a = (t) {
#define __dexit(a)     {0}},

#define __cstr(x) #x
#define EDEF_(e, m, ...) \
{   .key=#m,\
    .val=c__eval( e##_##m ),\
    __VA_ARGS__},
#define EREF(x, ...) {.key=#x, .val=x, __VA_ARGS__},

#define __memdef(type) \
{   .name = #type, \
    .size = sizeof(type),\
    .ml = (Member[]) {

#define __member(T, na, sp) \
        {   .name   = memdef_name(#na),\
            .spec   = sp,\
            .size   = memdef_size(T, na),\
            .offset = memdef_offs(T, na)},

#define __enddef(T) {0}}},

#if 1
/*
————————————————————————————————————————————————————————————————————————————————
The following library functions are historical and
will be NULL at runtime unless explicitly redefined
*/
// from <signal.h>
#   define BLTN_SIGVEC 0
#   define BLTN_SIGMASK 0
#   define BLTN_SIGBLOCK 0
#   define BLTN_SIGSETMASK 0
#   define BLTN_SIGGETMASK 0

#endif
/*

#include "arpa/inet.h"
#include <dirent.h>
#include <errno.h>
#include <dlfcn.h>
#include <fcntl.h>
#include <fnmatch.h>
#include <ftw.h>
#include <glob.h>
#include <grp.h>
#include <iconv.h>
#include <inttypes.h>
#include <libgen.h>
#include <limits.h>
#include <math.h>
#include <ndbm.h>
#include <nl_types.h>
#include <netdb.h>
#include <net/if.h>
#include <poll.h>
#include <pwd.h>
#include <pthread.h>
#include <regex.h>
#include <search.h>
#include <semaphore.h>
#include <signal.h>
#include <setjmp.h>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>

#include <sys/times.h>

#include "proxy/aio.h"
#include "proxy/sys/ipc.h"
#include "proxy/sys/msg.h"
#include "proxy/sys/sem.h"
#include "proxy/sys/shm.h"

#include <sys/socket.h>
#include <sys/statvfs.h>
#include <sys/wait.h>
#include <sys/uio.h>
#include <sys/un.h>
#include <sys/utsname.h>
#include <syslog.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
#include <utime.h>
#include <wchar.h>

*/


typedef double dbl, *double_p;
typedef long double ldbl, ldouble, *ldbl_p;
typedef float *float_p;

typedef       void  *buffer, **buffers;
typedef const void *memory, *cookie;

typedef uint8_t *uint8_p;

typedef char*const *execvs;

typedef                 char char_t, *chars, **strings, **char_pp;
typedef         signed  char schar,  schar_t, *schar_p;
typedef       unsigned  char uchar, uchar_t, *uchars;
typedef const           char char_c, *bytes, *fspath, *format;
typedef const   signed  char schar_c,*schar_cp;
typedef const unsigned  char uchar_c, *uchar_cp;
typedef char * const *char_pcp;
typedef const char **char_cpp;
typedef                short short_t,  *short_p;
typedef const          short short_c, *short_cp;

typedef       unsigned short ushrt_t,  *ushrt_p;
typedef const   signed short sshrt_c, *sshrt_cp;

typedef         signed short sshrt_t,  *sshrt_p;
typedef const unsigned short ushrt_c, *ushrt_cp;
 
typedef   signed   signed_t,  int_t;
typedef unsigned unsigned_t, uint_t;
 
typedef         signed      long  long_t,  *long_p;
typedef         signed long long llong_t, *llong_p;
typedef const   signed      long  long_c,  *long_cp;
typedef const   signed long long llong_c, *llong_cp;
typedef       unsigned      long  ulong_t,  *ulong_p;
typedef       unsigned long long ullong_t, *ullong_p;
typedef const unsigned      long  ulong_c,  *ulong_cp;
typedef const unsigned long long ullong_c, *ullong_cp;

typedef wchar_t       
    *wide_p, 
    *wchar_p, 
    **wide_pp,
    **wchar_pp;

typedef const wchar_t
    wide_c,
    wchar_c, 
    *wchar_cp, 
    *wide_cp,
    **wchar_cpp,
    **wide_cpp;

typedef signed
    *int_p,
    signed_t, *signed_p,
    EnumBase,
    sockaf,     // socket( [0] )
    socktype,   // socket( [1] )
    socklv,
    sockop,
    fd;         // file descriptor

typedef EnumBase
    Instr,
    IntCount,
    IntFlag;

typedef IntCount
    nfds,
    time_ms;

typedef IntFlag
    accmode,    // F_OK || R_OK || W_OK || X_OK
    atflag,     // AT_SYMLINK_NOFOLLOW
    prot_f,     // PROT_*
    map_f,      // MAP_*
    madv_f,     // MADV_*
    msg_f,      // MSG_*
    sock_f,     // SOCK_*
    shut_f,     // SHUT_*
    mcl_f,      // MCL_*
    mremap_f,   // MREMAP_*
    mlock_f,    // MLOCK_*
    ms_f;       // MS_*

typedef Instr
    iop,        // ioctl( [.request] )
    SEEK_t,     // lseek( [.how] )
    _CS_t,      // confstr( [.name] )
    _PC_t,      // pathconf( [.name] )
    _SC_t,      // sysconf( [.name] )
    fnm_t,      // fnmatch(
    wstatus, 
    *wstatus_p,
    waitop,
    signo,      // "signum" conflicts with the math function
    pfadv,      // POSIX_FADV_*
    pmadv,      // POSIX_MADV_*
    sigmask_t;  // sigprocmask(op=SIG_SETMASK)

typedef unsigned
    mfd_f, // memfd_create
    *uint_p;

typedef iop
    fiop,   // fileios ioctls
    siop,   // sockios ioctls
    tiop;   // termios ioctls

typedef fd
    at,         // S_ISDIR()
    filefd,     // S_ISREG
    sockfd,     // S_ISSOCK
    pipefd;     // S_ISFIFO()

typedef gid_t *gid_p;

typedef uid_t *uid_p;

typedef pid_t *pid_p;

typedef size_t *size_p;

typedef       off_t        *off_p;
typedef const off_t off_c, *off_cp;

typedef       fpos_t         *fpos_p;
typedef const fpos_t fpos_c, *fpos_cp;

typedef long double ldouble;

typedef fd_set *fds;

typedef       struct stat stat_s, *stat_p, **stat_pp;
typedef const struct stat stat_c, *stat_cp, **stat_cpp;

typedef FILE *file_p, *popen_p;

typedef DIR *dir_p;

typedef struct FTW ftw_s, *ftw_p;

typedef int 
    (*ftw_f) (fspath, stat_cp, int),
    (*nftw_f)(fspath, stat_cp, int, ftw_p);
typedef glob_t *glob_p;

typedef       struct dirent dirent_s, *dirent_p, **dirent_pp, ***dirent_ppp;
typedef const struct dirent dirent_c, *dirent_cp, **dirent_cpp;

typedef struct pollfd pollfd_s, *pollfds;
typedef struct msqid_ds *msqid_ds_p;

typedef ENTRY *ENTRY_p;
typedef ENTRY entry_s, *entry_p;
typedef void *dltab;

typedef void 
    (*exiter)(void),
    (*pthread_f)(void *),
    (*visitor)(memory, VISIT, int);

typedef int 
    itimer_t,
    (*bisector)(memory, memory);
 
typedef clockid_t *clockid_p;
typedef buffer (*pt_starter)(buffer);
typedef         pthread_t tid_t, *tid_p;
typedef  const  pthread_t tid_c, *tid_cp;
typedef pthread_once_t pt_once_t, *pt_once_p;


typedef void (*sig_f)(int);
typedef int(*globerr)(const char *, int);

typedef       struct dirent dirent_s, *dirent_p, **dirent_pp;
typedef const struct dirent dirent_c, *dirent_cp, **dirent_cpp;

typedef int SIG;
typedef       struct sigaction sigaction_s, *sigaction_p;
typedef const struct sigaction sigaction_c, *sigaction_cp;

typedef       siginfo_t *siginfo_p;
typedef const siginfo_t  siginfo_c, *siginfo_cp;

typedef       union sigval sigval_u, *sigval_p;
typedef const union sigval sigval_c, *sigval_cp;

typedef       struct sigevent sigevent_s, *sigevent_p;
typedef const struct sigevent sigevent_c, *sigevent_cp;

typedef       stack_t *stack_p;
typedef const stack_t *stack_cp, stack_c;

typedef       sigset_t *sigset_p;
typedef const sigset_t sigset_c, *sigset_cp;

typedef struct sigvec_ob {
    sig_f   sv_handler;
    int     sv_mask;
    int     sv_flags;
#   ifndef SV_INTERRUPT
#   define SV_INTERRUPT SA_RESTART
#   endif
#   ifndef SV_RESETHAND
#   define SV_RESETHAND SA_RESETHAND
#   endif
#   ifndef SV_ONSTACK
#   define SV_ONSTACK SA_ONSTACK
#   endif
} sigvec_s, *sigvec_p;

typedef const struct sigvec_ob sigvec_c, *sigvec_cp;
typedef       sigset_t *sigset_p;

typedef const sigset_t *sigset_cp;
typedef union sigval sigval_u;

typedef struct termios termios_s, *termios_p;
typedef const struct termios *termios_cp;

typedef struct tm tm_s, *tm_p;
typedef struct tms tms_s, *tms_p;

typedef time_t *time_p;
typedef const time_t time_c, *time_cp;
typedef timer_t *timer_p;
typedef clockid_t *clockid_p;

typedef struct utmpx *utmpx_p;
typedef struct utmpx const *utmpx_cp;

typedef int mqd_t;

typedef pipefd pipes[2];

typedef unsigned short rand48seed[3];
typedef char deskey[64];

typedef int
    (*entkey)(dirent_cp),
    (*entcmp)(dirent_cpp, dirent_cpp);

typedef const struct aiocb *const *aiocb_cpp;
typedef       struct aiocb aiocb_s, *aiocb_p;
typedef const struct aiocb aiocb_c, *aiocb_cp;
typedef aiocb_c *const aiocb_v[];

typedef       struct iovec iovec_s, *iovec_p;
typedef const struct iovec iovec_c, *iovec_cp;

typedef         mbstate_t *mbstate_p;
typedef   const mbstate_t  mbstate_c, *mbstate_cp;

typedef regmatch_t *regmatch_p;
typedef       regex_t *regex_p;
typedef const regex_t *regex_cp, regex_c;

typedef       struct rusage rusage_s, *rusage_p;
typedef const struct rusage rusage_c, *rusage_cp;

typedef       struct rlimit rlimit_s, *rlimit_p;
typedef const struct rlimit rlimit_c, *rlimit_cp;

typedef         struct timespec timespec_s, *timespec_p;
typedef   const struct timespec timespec_c, *timespec_cp;
typedef         struct timeval timeval_s, *timeval_p;
typedef   const struct timeval timeval_c, *timeval_cp;
typedef         struct itimerspec itimerspec_s, *itimerspec_p;
typedef   const struct itimerspec itimerspec_c, *itimerspec_cp;
typedef         struct itimerval itimerval_s, *itimerval_p;
typedef   const struct itimerval itimerval_c, *itimerval_cp;
typedef         struct  utimbuf utimbuf_s;
typedef   const struct  utimbuf ftimes[2], *utimbuf_cp;
typedef   const struct  timeval ftimeus[2];
typedef   const struct timespec ftimens[2];

typedef         struct tm tm_s, *tm_p;
typedef   const struct tm tm_c, *tm_cp;
typedef struct ipc_perm ipc_perm_s, *ipc_perm_p;
typedef struct shmid_ds shmid_ds_s, *shmid_ds_p;
typedef struct semid_ds semid_ds_s, *sdmid_ds_p;

typedef struct sembuf   sembuf_s, *sembuf_p;

typedef sem_t *sem_p;

typedef struct c_strbuf {
    char *buf;
    int len;
    int maxlen;
} strbuf_s, *strbuf_p;

typedef const struct c_strbuf strbuf_c, *strbuf_cp;

typedef struct statvfs statvfs_s, *statvfs_p;
typedef volatile void vvoid;

typedef enum {
    C__VOID,
    C__POINTER,
    C__BOOL,
    C__SCHAR,       C__UCHAR,
    C__SHORT,       C__USHRT,
    C__SIGNED,      C__UNSIGNED,
    C__LONG,        C__ULONG,
    C__INTMAX,        C__UINTMAX,
    C__FLOAT,       C__FCOMPLEX,
    C__DOUBLE,      C__DCOMPLEX,
    C__LDOUBLE,     C__LCOMPLEX,
    C__STRUCT,
    C__UNION,
    C__FUNC,
    C__NTYPECODES
} Typecode;

static const int C__TYPECODE[C__NTYPECODES] = {
    [C__VOID]   = 'x',
    [C__POINTER]= 'P',
    [C__BOOL]   = '?',
    [C__SCHAR]  = 'b', [C__UCHAR]       = 'B',
    [C__SHORT]  = 'h', [C__USHRT]       = 'H',
    [C__SIGNED] = 'i', [C__UNSIGNED]    = 'I',
    [C__LONG]   = 'l', [C__ULONG]       = 'L',
    [C__INTMAX] = 'q', [C__UINTMAX]     = 'Q',
    [C__FLOAT]  = 'f', [C__FCOMPLEX]    = 'D',
    [C__DOUBLE] = 'd', [C__DCOMPLEX]    = 'F',
    [C__LDOUBLE]= 'e', [C__LCOMPLEX]    = 'E',
    [C__STRUCT] = 't',
    [C__UNION]  = 'v',
    [C__FUNC]   = '$',

#define c_s8        C__SCHAR
#define c_s16       C__SHORT
#define c_s32       C__SIGNED
#define c_schar     C__SCHAR
#define c_short     C__SHORT
#define c_int       C__SIGNED
#define c_long      C__LONG
#define c_intmax    C__INTMAX

#define c_u8        C__UCHAR
#define c_u16       C__USHRT
#define c_u32       C__UNSIGNED
#define c_uchar     C__UCHAR
#define c_ushrt    C__USHRT
#define c_uint      C__UNSIGNED
#define c_ulong     C__ULONG
#define c_uintmax   C__UINTMAX

#define c_flt       C__FLOAT
#define c_dbl       C__DOUBLE
#define c_ldbl      C__LDOUBLE
#define c_void      C__VOID

#if CHAR_MIN < 0
#   define c_char C__SCHAR
#else
#   define c_char C__UCHAR
#endif

#if WCHAR_MIN < 0
#   define c_wchar C__SIGNED
#else
#   define c_wchar C__UNSIGNED
#endif

#if LONG_BIT == 64
#   define c_u64 C__ULONG
#   define c_s64 C__LONG
#else
#   define c_s64 C__INTMAX
#   define c_u64 C__UINTMAX
#endif

#define c_llong c_s64
#define c_ullong c_u64

#ifndef    _FILE_OFFSET_BITS
#   define _FILE_OFFSET_BITS 64
#endif

#if _FILE_OFFSET_BITS == 64
#   define c_off_t c_s64
#else
#   define c_off_t c_s32
#endif

#if SIZE_MAX <= UINT32_MAX
#   define c_size_t c_u32
#   define c_ssize_t c_s32
#else
#   define c_size_t c_u64
#   define c_ssize_t c_s64
#endif

};

enum {
    C__USORT=0,
    C__KSORT=1,
    C__VSORT=2,
    C__ESORT_MASK=3
};

struct c_item;
struct c_enum;
struct c_struct;
struct c_member;
struct c_basedef;

int Const_print(struct c_item *, file_p);
int Enum_print(struct c_enum *, file_p);
int Struct_print(struct c_struct *, file_p);
int Member_print(struct c_member *, file_p);
int Header_print(struct c_basedef *, file_p);

int Const_kcmp(const void *a, const void *b);
int Const_vcmp(const void *a, const void *b);

static int (*Const_cmp[4])(const void *, const void *) = {
    [C__USORT]=0,
    [C__KSORT]=&Const_kcmp,
    [C__VSORT]=&Const_vcmp,
    [C__ESORT_MASK]=0,
};

typedef struct c_item {
    bytes    key;
    intmax_t val;
    bytes    com;
} Const;

typedef struct c_enum {
    bytes   name;
    Const  *defs;
    size_t  size;
    int     ncol;
    char   *fmt;
    unsigned
        sort: 2
        ;
} Enum;

typedef struct c_member {
    bytes name;
    bytes spec;
    size_t size;
    size_t offset;
} Member;

typedef struct c_struct {
    bytes name;
    size_t size;
    size_t align;
    struct c_member *ml;
    unsigned
        ml_sorted: 1;
    unsigned ml_count;
} Struct;

typedef struct c_basedef {
    bytes path;
    Enum *enums;
    Const *consts;
    Struct *structs;
} Header;

#define memdef_size(t, a) sizeof( ((t*)0)->a)
#define memdef_offs(t, a) offsetof(t, a)
#define memdef_name(name) name

#define memdef(T, na, sp) \
{   .name   = memdef_name(#na),\
    .spec   = sp,\
    .size   = memdef_size(T, na),\
    .offset = memdef_offs(T, na),\
}
int Member_cmp(const void *a, const void *b) {
    const Member *z[2] = {a, b};
    size_t x = z[0]->offset;
    size_t y = z[1]->offset;
    return x == y ? 0 : x < y ? -1 : +1;

}

/*


#define structdef(k, ...) \
struct c_struct c_##k = {.name=#k, __VA_ARGS__}

static structdef(
    glob_t,
    memdef(glob_t, gl_pathc, "@N"),
    memdef(glob_t, gl_pathv, "@s*"),
    memdef(glob_t, gl_offs, "@N")
);


{
    "glob_t",
    {"gl_pathc", "<J", 0},
    {"gl_pathv", "<s*", 8},
    {"gl_offs",  "<J", 16},
}
    Slots to reserve at the beginning of gl_pathv.

}
*/


#ifdef MSG_ERRQUEUE

#include <linux/errqueue.h>
typedef struct sock_extended_err sock_extended_err_s, *sock_extended_err_p;
#endif

typedef struct utsname utsname_s, *utsname_p;
typedef struct tpacket_hdr tpacket_hdr_s, *tpacket_hdr_p;

typedef       struct sockaddr_un sockaddr_un_s, *sockaddr_un_p;
typedef const struct sockaddr_un sockaddr_un_c, *sockaddr_un_cp;

typedef struct ucred ucred_s, *ucred_p;

typedef struct linger linger_s, *linger_p;

typedef struct sockaddr_pkt sockaddr_pkt_s, *sockaddr_pkt_p;

typedef struct sockaddr_ll sockaddr_ll_s, *sockaddr_ll_p;

typedef         struct sockaddr sockaddr_s, *sockaddr_p;
typedef   const struct sockaddr sockaddr_c, *sockaddr_cp;

typedef         struct sockaddr_in  sockaddr_in_s,  *sockaddr_in_p;
typedef   const struct sockaddr_in  sockaddr_in_c,  *sockaddr_in_cp;

typedef         struct sockaddr_in6 sockaddr_in6_s, *sockaddr_in6_p;
typedef   const struct sockaddr_in6 sockaddr_in6_c, *sockaddr_in6_cp;

typedef struct in_pktinfo in_pktinfo_s;
typedef struct in_pktinfo in_pktinfo_s, *in_pktinfo_p;

typedef         struct in_addr in_addr_s, *in_addr_p;
typedef   const struct in_addr in_addr_c, *in_addr_cp;

typedef       struct  in6_addr     in6_addr_s,     *in6_addr_p;
typedef const struct  in6_addr     in6_addr_c,     *in6_addr_cp;

typedef       struct  packet_mreq  packet_mreq_s, *packet_mreq_p;
// IP_ADD_MEMBERSHIP
typedef struct  ip_mreq   ip_mreq_s, *ip_mreq_p;
typedef struct  ip_mreqn  ip_mreqn_s, *ip_mreqn_p;
// IP_ADD_SOURCE_MEMBERSHIP

typedef struct ip_mreq_source ip_mreq_source_s;
typedef struct ipv6_mreq ipv6_mreq_s, *ipv6_mreq_p;

typedef struct if_nameindex if_nameindex_s, *if_nameindex_p;

typedef struct ifmap ifmap_s, *ifmap_p;
typedef char ifreq_name_t[IFNAMSIZ];
typedef struct ifreq ifreq_s, *ifreq_p;
typedef struct in6_ifreq in6_ifreq_s, *in6_ifreq_p;


struct in6_flowlabel_req in6_flowlabel_req_s,*in6_flowlabel_req_p;

typedef       struct  hostent  hostent_s, * hostent_p;
typedef const struct  hostent  hostent_c, * hostent_cp;
typedef       struct   netent   netent_s, *  netent_p;
typedef const struct   netent   netent_c, *  netent_cp;
typedef       struct protoent protoent_s, *protoent_p;
typedef const struct protoent protoent_c, *protoent_cp;
typedef       struct  servent  servent_s, * servent_p;
typedef const struct  servent  servent_c, * servent_cp;

typedef struct sockaddr_storage sockaddr_storage_s, *sockaddr_storage_p;

/*

struct sockaddr_in6 {
    unsigned short  sin6_family;
    __be16          sin6_port;
    __be32          sin6_flowinfo;
    struct in6_addr sin6_addr;
    __u32           sin6_scope_id;
}
struct ip_mreqn {
    struct in_addr imr_multiaddr;
    struct in_addr imr_address;
    int             imr_ifindex;
};

#define IN6ADDR_ANY_INIT
extern const struct in6_addr in6addr_any = IN6ADDR_ANY_INIT;

#define IN6ADDR_LOOPBACK_INIT
extern const struct in6_addr in6addr_loopback = IN6ADDR_LOOPBACK_INIT

struct ipv6_mreq {
    struct in6_addr ipv6mr_multiaddr;
              ipv6mr_ifindex;
};


// getsockopti level

#define IPPROTO_IP
#define IPPROTO_IPV6
#define IPPROTO_ICMP
#define IPPROTO_RAW
#define IPPROTO_TCP
#   include <netinet/tcp.h>
#       define TCP_NODELAY

#define IPPROTO_UDP

// getsockopt option_name
#define IPV6_JOIN_GROUP
#define IPV6_LEAVE_GROUP
#define IPV6_MULTICAST_HOPS
#define IPV6_MULTICAST_IF
#define IPV6_MULTICAST_LOOP
#define IPV6_UNICAST_HOPS
#define IPV6_V6ONLY

#define INADDR_ANY
#define INADDR_BROADCAST
#define INET_ADDRSTRLEN 16
#define INET6_ADDRSTRLEN 46

getprotobyname("udp")
struct protoent {
    char *p_name;
    char **p_aliases;
    int p_proto;
}



struct addrinfo {
    int         ai_flags
    int         ai_family
    int         ai_socktype
    int         ai_protocol
    socklen_t   ai_addrlen
    sockaddr_p  ai_addr
    chars       ai_canonname
    addrinfo_p  ai_next
};
FD_SETSIZE
FIONREAD
getsockopt(
    fd,
    SO_ACCEPTCONN

size_t we_wordc Count of words matched by words. char **we_wordv Pointer to list of expanded words. size_t we_offs Slots to reserve at the beginning of we_wordv. 
*/
typedef struct lconv lconv_s, *lconv_p;
typedef struct mq_attr mq_attr_s, *mq_attr_p;
typedef const struct mq_attr mq_attr_c, *mq_attr_cp;

typedef DBM *db_t;
typedef struct passwd passwd_s, *passwd_p, **passwd_pp;
typedef struct group group_s, *group_p, **group_pp;
typedef struct linger linger_s, *linger_p;
typedef const struct linger linger_c, *linger_cp;
typedef struct ucred ucred_s, *ucred_p;
typedef struct wordexp_t *wordexp_p;
typedef       struct addrinfo addrinfo_s, *addrinfo_p, **addrinfo_pp;
typedef const struct addrinfo addrinfo_c, *addrinfo_cp;
typedef       pthread_attr_t pt_attr_t, *pt_attr_p;
typedef const pthread_attr_t pt_attr_c, *pt_attr_cp;
typedef       pthread_barrier_t pt_barrier_t, *pt_barrier_p;
typedef const pthread_barrier_t pt_barrier_c, *pt_barrier_cp;
typedef       pthread_barrierattr_t pt_barattr_t, *pt_barattr_p;
typedef const pthread_barrierattr_t pt_barattr_c, *pt_barattr_cp;
typedef       pthread_cond_t pt_cond_t, *pt_cond_p;
typedef const pthread_cond_t pt_cond_c, *pt_cond_cp;
typedef       pthread_condattr_t pt_condattr_t, *pt_condattr_p;
typedef const pthread_condattr_t pt_condattr_c, *pt_condattr_cp;
typedef       pthread_key_t pt_key_t, *pt_key_p;
typedef const pthread_key_t pt_key_c, *pt_key_cp;
typedef       pthread_mutex_t pt_mutex_t, *pt_mutex_p;
typedef const pthread_mutex_t pt_mutex_c, *pt_mutex_cp;
typedef       pthread_mutexattr_t pt_mutexattr_t, *pt_mutexattr_p;
typedef const pthread_mutexattr_t pt_mutexattr_c, *pt_mutexattr_cp;
typedef       pthread_rwlock_t pt_rwlock_t, *pt_rwlock_p;
typedef const pthread_rwlock_t pt_rwlock_c, *pt_rwlock_cp;
typedef       pthread_rwlockattr_t pt_rwlockattr_t, *pt_rwlockattr_p;
typedef const pthread_rwlockattr_t pt_rwlockattr_c, *pt_rwlockattr_cp;
typedef       pthread_spinlock_t pt_spinlock_t, *pt_spinlock_p;
typedef const pthread_spinlock_t pt_spinlock_c, *pt_spinlock_cp;
/*typedef       pthread_spinattr_t pt_spinattr_t, *pt_spinattr_p;
typedef const pthread_spinattr_t pt_spinattr_c, *pt_spinattr_cp;
*/

typedef       struct sched_param sched_param_s, *sched_param_p;
typedef const struct sched_param sched_param_c, *sched_param_cp;


typedef int MAXCON;
typedef int SOCKFD;
typedef int SOCKAF;
typedef int SOCKTP;
typedef int SOCKFL;

typedef int SHUTHOW;
typedef int SOCKLVL;
typedef int MSGFL;
typedef int SOCKOPT;

typedef socklen_t *socklen_p;
typedef       struct sockaddr sockaddr_s, *sockaddr_p;
typedef const struct sockaddr sockaddr_c, *sockaddr_cp;
typedef       struct msghdr  msghdr_s, *msghdr_p;
typedef const struct msghdr  msghdr_c, *msghdr_cp;
typedef       struct mmsghdr mmsghdr_s, *mmsghdr_p;
typedef const struct mmsghdr mmsghdr_c, *mmsghdr_cp;
typedef       struct cmsghdr cmsghdr_s, *cmsghdr_p;
typedef const struct cmsghdr cmsghdr_c, *cmsghdr_cp;

typedef struct ip_msfilter ip_msfilter_s, *ip_multifilter_p;

typedef struct tpacket_auxdata tpacket_auxdata_s;

#if _POSIX_TYPED_MEMORY_OBJECTS < 1
    typedef struct posix_typed_mem_info_hack {
        size_t posix_tmi_length;
    } tym_info_s, *tym_info_p;
#else
    typedef struct posix_typed_mem_info tym_info_s, *tym_info_p;
#endif
typedef struct flock flock_s, *flock_p;
typedef struct f_owner_ex f_owner_ex_s, *f_owner_ex_p;
        /*
        struct flock {
            short l_type;
            short l_whence;
            off_t l_start;
            off_t l_len;
            pid_t l_pid;

  
        struct f_owner_ex {
          int type;
          pid_t pid;
        };
        
        };*/
void fcntlbits(void ) {

    long LOCK_[] = {
        LOCK_SH,
        LOCK_EX,
        LOCK_NB,
        LOCK_UN,
#   ifdef LOCK_MAND
        LOCK_MAND,
#   endif
    };

    long FD_[] = {
        FD_CLOEXEC
    };

    long O_[] = {
        O_ACCMODE,
        O_RDONLY,
        O_WRONLY,
        O_RDWR,
        O_CREAT,
        O_EXCL,
        O_NOCTTY,
        O_TRUNC,
        O_APPEND,

#       ifdef O_NONBLOCK
        O_NONBLOCK,
#       endif

#       if _POSIX_SYNCHRONOUS_IO
        O_DSYNC, O_RSYNC, O_SYNC,
#       endif

#       ifdef O_ASYNC
        O_ASYNC,
#       endif

#       ifdef O_DIRECT
        O_DIRECT,
#       endif

#       ifdef O_LARGEfile_p
        O_LARGEfile_p,
#       endif

#       ifdef O_DIRECTORY
        O_DIRECTORY,
#       endif

#       ifdef O_NOFOLLOW
        O_NOFOLLOW,
#       endif

#       ifdef O_NOATIME
        O_NOATIME,
#       endif

#       ifdef O_CLOEXEC
        O_CLOEXEC,
#       endif

#       ifdef O_PATH
        O_PATH,
#       endif

#       ifdef O_TMPfile_p
        O_TMPfile_p,
#       endif
    };

    long _LCK[] = {
        F_RDLCK,
        F_WRLCK,
        F_UNLCK,

    };

    long F_[] = {
        F_DUPFD,
        F_GETFD,
        F_SETFD,
        F_GETFL,
        F_SETFL,
        F_GETOWN,
        F_SETOWN,
        F_GETLK,
        F_SETLK,
        F_SETLKW,
        F_DUPFD_CLOEXEC,

#   ifdef F_OFD_GETLK
        F_OFD_GETLK,
        F_OFD_SETLK,
        F_OFD_SETLKW,
        F_OWNER_TID,
        F_OWNER_PID,
        F_OWNER_PGRP,
#   endif

#       ifdef F_SETSIG
        F_GETSIG,
        F_SETSIG,
#       endif

#       ifdef F_GETLEASE
        F_GETLEASE,
        F_SETLEASE,
#       endif

#       ifdef F_GETPIPE_SZ
        F_GETPIPE_SZ,
        F_SETPIPE_SZ,
#       endif

#       ifdef F_CANCELLK
        F_CANCELLK,
#       endif

#       ifdef F_ADD_SEALS
        F_ADD_SEALS,
        F_GET_SEALS,
        F_SEAL_SEAL,
        F_SEAL_SHRINK,
        F_SEAL_GROW,
        F_SEAL_FUTURE_WRITE,
#       endif

#       ifdef F_GET_RW_HINT
        F_GET_RW_HINT,
        F_SET_RW_HINT,
        F_GET_FILE_RW_HINT,
        F_SET_FILE_RW_HINT,
#       endif

#       ifdef F_NOTIFY
        F_NOTIFY,
#       endif
    };

    long DN_[] = {
#       ifdef F_NOTIFY
        DN_ACCESS,
        DN_MODIFY,
        DN_CREATE,
        DN_DELETE,
        DN_RENAME,
        DN_ATTRIB,
        DN_MULTISHOT,
#       endif
        0
    };

    long RWF_WRITE_LIFE_[] = {
#       ifdef F_GET_RW_HINT
        RWH_WRITE_LIFE_NONE,
        RWH_WRITE_LIFE_SHORT,
        RWH_WRITE_LIFE_MEDIUM,
        RWH_WRITE_LIFE_LONG,
        RWH_WRITE_LIFE_EXTREME,
#       endif
        0
    };

    long POSIX_FADV_[] = {
        POSIX_FADV_DONTNEED,
        POSIX_FADV_WILLNEED,
        POSIX_FADV_SEQUENTIAL,
        POSIX_FADV_RANDOM,
        POSIX_FADV_NORMAL,
        POSIX_FADV_NOREUSE,
    };

    long AT_[] = {

        AT_EACCESS,
        AT_REMOVEDIR,
        AT_SYMLINK_FOLLOW,
        AT_SYMLINK_NOFOLLOW,

#       ifdef AT_EMPTY_PATH
        AT_EMPTY_PATH,
#       endif

#       ifdef AT_NO_AUTOMOUNT
        AT_NO_AUTOMOUNT,
#       endif

#       ifdef AT_RECURSIVE
        AT_RECURSIVE,
#       endif

#       ifdef AT_STATX_SYNC_TYPE
        AT_STATX_SYNC_TYPE,
#       endif

#       ifdef AT_STATX_SYNC_AS_STAT
        AT_STATX_SYNC_AS_STAT,
#       endif

#       ifdef AT_STATX_FORCE_SYNC
        AT_STATX_FORCE_SYNC,
#       endif

#       ifdef AT_STATX_DONT_SYNC
        AT_STATX_DONT_SYNC,
#       endif
    };
/*
#if __ANDROID_API__ >= __ANDROID_API_L__
#define SPLICE_F_MOVE 1
#define SPLICE_F_NONBLOCK 2
#define SPLICE_F_MORE 4
#define SPLICE_F_GIFT 8
#endif

#if __ANDROID_API__ >= __ANDROID_API_O__
#define SYNC_FILE_RANGE_WAIT_BEFORE 1
#define SYNC_FILE_RANGE_WRITE 2
#define SYNC_FILE_RANGE_WAIT_AFTER 4
*/

}

void pollbits(void) {
    /*
    pollfd {
        int fd;
        short events;
        short revents;
    }
    */
    long POLLs[]={
        POLLIN,
        POLLRDNORM,
        POLLRDBAND,
        POLLPRI,
        POLLOUT,
        POLLWRNORM,
        POLLWRBAND,
        POLLERR,
        POLLHUP,
        POLLNVAL
    };
}

void dlfcnbits(void) {

    long RTLD_[] = {
        RTLD_LAZY,
        RTLD_LOCAL,
        RTLD_GLOBAL,
        RTLD_NOW,

#       ifdef RTLD_NOLOAD
        RTLD_NOLOAD,
#       endif

#       ifdef RTLD_DELETE
        RTLD_NODELETE,
#       endif
    };

}

void syslogbits(void) {

    long LOG_priority[] = {
        LOG_EMERG,
        LOG_ALERT,
        LOG_CRIT,
        LOG_ERR,
        LOG_WARNING,
        LOG_NOTICE,
        LOG_INFO,
        LOG_DEBUG,
    };

    long LOG_opt[] = {
        LOG_PID,
        LOG_CONS,
        LOG_NDELAY,
        LOG_ODELAY,
        LOG_NOWAIT,
#       ifdef LOG_PERROR
        LOG_PERROR,
#       endif
    };

    long LOG_facility[] = {
        LOG_USER,
        LOG_LOCAL0,
        LOG_LOCAL1,
        LOG_LOCAL2,
        LOG_LOCAL3,
        LOG_LOCAL4,
        LOG_LOCAL5,
        LOG_LOCAL6,
        LOG_LOCAL7,

#       ifdef LOG_KERN
        LOG_KERN,
#       endif

#       ifdef LOG_USER
        LOG_USER,
#       endif

#       ifdef LOG_MAIL
        LOG_MAIL,
#       endif

#       ifdef LOG_DAEMON
        LOG_DAEMON,
#       endif

#       ifdef LOG_AUTH
        LOG_AUTH,
#       endif

#       ifdef LOG_SYSLOG
        LOG_SYSLOG,
#       endif

#       ifdef LOG_LPR
        LOG_LPR,
#       endif

#       ifdef LOG_NEWS
        LOG_NEWS,
#       endif

#       ifdef LOG_UUCP
        LOG_UUCP,
#       endif

#       ifdef LOG_CRON
        LOG_CRON,
#       endif

#       ifdef LOG_AUTHPRIV
        LOG_AUTHPRIV,
#       endif

#       ifdef LOG_FTP
        LOG_FTP,
#       endif

     };

}

void sys_statvfsbits(void) {

    Header c_sys_statvfs_h = {
        .path="<sys/statvfs.h>",
        .structs=(Struct[]) {
            __memdef(statvfs_s)
            __member(statvfs_s, f_bsize, "{ulong}")
            __member(statvfs_s, f_frsize, "{ulong}")
            __member(statvfs_s, f_blocks, "{fsblkcnt_t}")
            __member(statvfs_s, f_bfree, "{fsblkcnt_t}")
            __member(statvfs_s, f_bavail, "{fsblkcnt_t}")
            __member(statvfs_s, f_files, "{fsfilcnt_t}")
            __member(statvfs_s, f_ffree, "{fsfilcnt_t}")
            __member(statvfs_s, f_favail, "{fsfilcnt_t}")
            __member(statvfs_s, f_fsid, "{ulong}")
            __member(statvfs_s, f_flag, "{ulong}")
            __member(statvfs_s, f_namemax, "{ulong}")
            __enddef(statvfs_s)
            {0}
        }
    };
        /*
        struct statvfs {
        unsigned long f_bsize;
        unsigned long f_frsize;
        fsblkcnt_t f_blocks;
        fsblkcnt_t f_bfree;
        fsblkcnt_t f_bavail;
        fsfilcnt_t f_files;
        fsfilcnt_t f_ffree;
        fsfilcnt_t  f_favail;
        unsigned long f_fsid
        unsigned long f_flag
            ST_RDONLY
            ST_NOSUID
        unsigned long f_namemax
        };
        */
    long ST_[] = {

        ST_NOSUID,
        ST_RDONLY,

#       ifdef ST_NODEV
        ST_NODEV,
#       endif

#       ifdef ST_NOEXEC
        ST_NOEXEC,
#       endif

#       ifdef ST_SYNCHRONOUS
        ST_SYNCHRONOUS,
#       endif

#       ifdef ST_NODEV
        ST_NODEV,
#       endif

#       ifdef ST_MANDLOCK
        ST_MANDLOCK,
#       endif

#       ifdef ST_NOATIME
        ST_NOATIME,
#       endif

#       ifdef ST_NODIRATIME
        ST_NODIRATIME,
#       endif

#       ifdef ST_RELATIME
        ST_RELATIME,
#       endif

    };

}

int utmpx_bits(void) {
    Header head = {
        .path="<utmpx.h>",
        .enums=(Enum[]) {
            {
                .name="",
                .defs=(Const[]) {
#ifdef BOOT_TIME
                    C__EREF(EMPTY),
                    C__EREF(BOOT_TIME),
                    C__EREF(OLD_TIME),
                    C__EREF(USER_PROCESS),
                    C__EREF(INIT_PROCESS),
                    C__EREF(LOGIN_PROCESS),
                    C__EREF(DEAD_PROCESS),
                    C__EREF(NEW_TIME),
#endif
                    {0}
                }
            },
            
            {0}
        }
    };

    return Header_print(&head, NULL);
    
}

typedef void *const *memory_p;

typedef const struct kevent *kevent_cp;
typedef struct kevent *kevent_p;
typedef struct kqueue *kqueue_p;
typedef const struct kqueue *kqueue_cp;

#if _POSIX_SPAWN > 0
    typedef posix_spawn_file_actions_t *spnacts_p, spnacts_s;
    typedef const spnacts_s           *spnacts_cp;
    typedef posix_spawnattr_t          *spnattr_p;
    typedef const posix_spawnattr_t   *spnattr_cp;
#else
    struct _spawnattr;
    struct _spawn_file_action;
    typedef       struct _spawnattr         spnattr_s, *spnattr_p;
    typedef const struct _spawnattr         spnattr_c, *spnattr_cp;
    typedef       struct _spawn_file_action spnacts_s, *spnacts_p;
    typedef const struct _spawn_file_action spnacts_c, *spnacts_cp;
#endif

/*
Most (all?) modern operating systems implement a 
"directory notification" API which can be used to 
monitor a directory for various events such as the 
opening/resizing of a file by another process. 

Before this is taken further, the set of functions 
that would, based on their abstract definition 
generate an event from the following categories must 
be determined.
*/
enum {
    EV_ACCESS   = 1<<0, // read inode data
    EV_MODIFY   = 1<<1, // edit inode data
    EV_CHATTR   = 1<<2, // edit inode metadata*
    EV_CREATE   = 1<<3, // add inode in dir
    EV_REMOVE   = 1<<3, // del inode from dir
    EV_RENAME   = 1<<4, // edit inode name
    EV_RESIZE   = 1<<6, // edit inode size
    EV_EXTEND   = 1<<7, // write that grows file
    EV_RDOPEN   = 1<<8, // open(path, O_RDONLY, ...)
    EV_WROPEN   = 1<<9, // open(path, O_WRONLY, ...)
    EV_RWOPEN   = 1<<10,// open(path,  O_RDWR, ...)
    EV_SHLOCK   = 1<<11,// read lock (shared) obtained
    EV_EXLOCK   = 1<<12,// write lock (exclusive) set
    EV_UNLOCK   = 1<<13 // file can be ex-locked
};

enum {
    RET_DOESNT, // void 
    RET_EXCEPT, // returns 0 for success, (!0) for failure
    RET_LENGTH, // returns a length or count of some sort 
    RET_BORROW, // returns something that requires special cleanup
    RET_OFFSET, // returns an offset into the argument 
    
};

typedef struct {

    unsigned os_events;
    
    unsigned 
        async_unsafe:       1,
        thread_unsafe:      1,
        cancellation_point: 1;
} CFUNC;

typedef struct c_ffi {

    struct {
        //  <sys/event.h>
        //  struct kevent { 
        //      uintptr_t	ident;
        //      short       filter;
        //      ushrt      flags;
        //      unsigned    fflags;
        //      int64_t     data;
        //      void    *udata;
        //      uint64_t ext[4];
        // };
        int 
            (*kqueue)(void),
            (*kevent)(fd, kevent_cp, int, kevent_p, int, timespec_cp);
    
    } BSD;

    struct {

        int 
        //  <sys/file.h>
            (*flock)(fd, int),
            (*dup3)(fd, fd, int);

        ssize_t
        //  <fcntl.h>
            (*splice)    (fd, off_p, fd, off_p, size_t, uint),
            (*tee)       (fd, fd, size_t, uint),
            (*vmsplice)  (fd, iovec_cp, size_t, uint),
            (*fallocate) (fd, int, off_t, off_t),
            (*readahead) (fd, off_t, size_t),

        //  <unistd.h>
            (*copy_file_range)(fd, off_p, fd, off_p, size_t, uint),

        // <sys/sendfile.h>
            (*sendfile)(fd, fd, off_p, size_t);
    } GNU;

    struct {

        int
            (*madvise)   (buffer, size_t, pmadv),
            (*mem_offset)(memory, size_t, off_p, size_p, int_p),
            (*fadvise)   (fd, off_t, off_t, pfadv),
            (*fallocate) (fd, off_t, off_t),
            (*spawn) (pid_p, fspath, spnacts_cp, spnattr_cp, execvs, execvs),            
            (*spawnp)(pid_p, fspath, spnacts_cp, spnattr_cp, execvs, execvs);

        struct {

            int
                (*get_info) (int, tym_info_p),
                (*open)     (fspath, int, int);

        } typed_mem;

        struct { 

            int
                (*addclose) (spnacts_p, int),
                (*addopen)  (spnacts_p, int, bytes, int, mode_t),
                (*adddup2)  (spnacts_p, int, int),
                (*destroy)  (spnacts_p),
                (*init)     (spnacts_p);

        } spawn_file_actions;

        struct {

            int
                (*destroy)          (spnattr_p),
                (*init)             (spnattr_p),
                (*getpgroup)        (spnattr_p, pid_p),
                (*setpgroup)        (spnattr_p, pid_t),
                (*sigmask)          (spnattr_p, sigset_cp),
                (*getsigmask)       (spnattr_cp,sigset_p),
                (*getsigdefault)    (spnattr_cp,sigset_p),
                (*setsigdefault)    (spnattr_p, sigset_cp),
                (*getflags)         (spnattr_cp,short_p),
                (*setflags)         (spnattr_p, short),
                (*getschedpolicy)   (spnattr_cp,int_p),
                (*setschedpolicy)   (spnattr_p, int),
                (*getschedparam)    (spnattr_cp,sched_param_p),
                (*setschedparam)    (spnattr_p, sched_param_cp);

        } spawnattr;

    } posix;

    struct {

        int
            (*aio_cancel)   (int, aiocb_p),
            (*aio_error)    (aiocb_cp),
            (*aio_fsync)    (int, aiocb_p),
            (*aio_read)     (aiocb_p),
            (*aio_return)   (aiocb_p),
            (*aio_suspend)  (aiocb_v, int, timespec_cp),
            (*aio_write)    (aiocb_p),
            (*lio_listio)   (int, aiocb_cpp);            
    };           // <aio.h>

    struct {

        int
            (*isalnum)(int),
            (*isalpha)(int),
            (*isblank)(int),
            (*isascii)(int),
            (*iscntrl)(int),
            (*isdigit)(int),
            (*isgraph)(int),
            (*islower)(int),
            (*isprint)(int),
            (*ispunct)(int),
            (*isspace)(int),
            (*isupper)(int),
            (*isxdigit)(int),
            (*toascii)(int),
            (*tolower)(int),
            (*toupper)(int),
            (*isalnum_l)(int, locale_t),
            (*isalpha_l)(int, locale_t),
            (*isblank_l)(int, locale_t),
            (*iscntrl_l)(int, locale_t),
            (*isdigit_l)(int, locale_t),
            (*isgraph_l)(int, locale_t),
            (*islower_l)(int, locale_t),
            (*isprint_l)(int, locale_t),
            (*ispunct_l)(int, locale_t),
            (*isspace_l)(int, locale_t),
            (*isupper_l)(int, locale_t),
            (*isxdigit_l)(int, locale_t),
            (*tolower_l)(int, locale_t),
            (*toupper_l)(int, locale_t);
    };           // <ctype.h>  

    struct {

        int    
            (*dlclose)  (dltab);
            //(*dladdr)   (memory, Dl_info *info);
        chars   
            (*dlerror)  (void);

        dltab   
            (*dlopen)   (fspath, int),
            (*fdlopen)  (fd, int),
            (*dlopenat) (at, fspath, int, ...);

        buffer
            (*dlsym)    (dltab, bytes),
            (*dlvsym)   (dltab, bytes, bytes);

    };           // <dlfcn.h>

    struct {

        uint32_t 
            (*htonl)(uint32_t),
            (*ntohl)(uint32_t); 

        uint16_t
            (*htons)(uint16_t),
            (*ntohs)(uint16_t);

        struct {
            in_addr_t 
                (*addr)(bytes);
            chars     
                (*ntoa)(in_addr_s);
            bytes     
                (*ntop)(int, memory, chars, socklen_t);
            int      
                (*pton)(int, bytes, buffer);
        } inet;

    };           // <arpa/inet.h>

    struct {

        entcmp
            (alphasort);

        dir_p
            (*opendir)   (fspath),
            (*fdopendir) (at);

        int
            (*closedir)  (dir_p),
            (*readdir_r) (dir_p, dirent_p, dirent_pp),
            (*scandir)   (fspath, dirent_ppp, entkey, entcmp),
            (*scandirat) (at, fspath, dirent_ppp, entkey, entcmp);

        dirent_p
            (*readdir)   (dir_p);

        void
            (*rewinddir) (dir_p),
            (*seekdir)   (dir_p, long);

        long
            (*telldir)   (dir_p);

        at
            (*dirfd)(dir_p);
    };           // <dirent.h>

    struct {

        int 
            (*fmtmsg)(long, bytes, int, bytes, bytes, bytes); 
    };           // <fmtmsg.h>

    struct {

        int
            (*fcntl)    (fd, int, ...);
        fd
            (*creat)    (fspath, mode_t),
            (*open)     (fspath, int, ...),
            (*openat)   (at, fspath, int, ...);
    };           // <fcntl.h>

    struct {

        int
            (*fnmatch)  (fspath, fspath, fnm_t);
    };           // <fnmatch.h>

    struct {
        int 
            (*ftw)(fspath, ftw_f, int),
            (*nftw)(fspath, nftw_f, int, int);

    };           // <ftw.h>

    struct {

        int
            (*glob)(fspath, int, globerr, glob_p);

        void
            (*globfree)(glob_p);
    };           // <glob.h>

    struct {

        group_p
            (*getgrgid)(gid_t),
            (*getgrent)(void),
            (*getgrnam)(bytes); 

        int
            (*getgrgid_r)(gid_t, group_p, chars, size_t, group_pp);

        void   
            (*endgrent)(void),
            (*setgrent)(void);
    };           // <grp.h>;

    struct {

        size_t  
            (*iconv)      (iconv_t, chars, size_p, char_pp, size_p);

        int     
            (*iconv_close)(iconv_t); 

        iconv_t 
            (*iconv_open)(fspath, fspath);
    };           // <iconv.h>

    struct {

        imaxdiv_t   
            (*imaxdiv)  (intmax_t, intmax_t);

        intmax_t    
            (*imaxabs)  (intmax_t),
            (*strtoimax)(bytes,   char_pp, int),
            (*wcstoimax)(wide_cp, wide_pp, int);

        uintmax_t   
            (*strtoumax)(bytes,   char_pp, int),
            (*wcstoumax)(wide_cp, wide_pp, int);
    };           // <inttypes.h>

    // <iso646.h> 
    
    struct {

        chars 
            (*nl_langinfo)(nl_item),
            (*nl_langinfo_l)(nl_item, locale_t);
    };           // <langinfo.h>

    struct {

        chars
            (*basename)(chars),
            (*dirname)(chars);
    };           // <libgen.h>

    // <limits.h>

    struct {

        locale_t 
            (*duplocale)(locale_t),
            (*uselocale)(locale_t),
            (*newlocale)(int, bytes, locale_t); 

        void 
            (*freelocale)(locale_t); 

        lconv_p
            (*localeconv)(void);

        chars 
            (*setlocale)(int, bytes);
    };           // <locale.h>

    struct {
        struct {
            int
                (*ilogb)(dbl),
                (*ilogbl)(ldbl),
                (*ilogbf)(float);
        };
        struct {
            long
                (*lrint)(dbl),
                (*lround)(dbl),
                (*lrintf)(float),
                (*lroundf)(float),
                (*lrintl)(ldbl),
                (*lroundl)(ldbl);
        };
        struct {
            llong_t
                (*llrintl)  (ldbl),
                (*llroundl) (ldbl),
                (*llrint)   (dbl),
                (*llround)  (dbl),
                (*llrintf)  (float),
                (*llroundf) (float);
        };

        struct {
            ldouble
                (*acoshl)(ldbl),
                (*acosl)(ldbl),
                (*asinhl)(ldbl),
                (*asinl)(ldbl),
                (*atan2l)(ldbl, ldbl),
                (*atanhl)(ldbl),
                (*atanl)(ldbl),
                (*cbrtl)(ldbl),
                (*ceill)(ldbl),
                (*copysignl)(ldbl, ldbl),
                (*coshl)(ldbl),
                (*cosl)(ldbl),
                (*erfcl)(ldbl),
                (*erfl)(ldbl),
                (*exp2l)(ldbl),
                (*expl)(ldbl),
                (*expm1l)(ldbl),
                (*fabsl)(ldbl),
                (*fdiml)(ldbl, ldbl),
                (*floorl)(ldbl),
                (*fmal)(ldbl, ldbl, ldbl),
                (*fmaxl)(ldbl, ldbl),
                (*fminl)(ldbl, ldbl),
                (*fmodl)(ldbl, ldbl),
                (*frexpl)(ldbl, int_p),
                (*hypotl)(ldbl, ldbl),
                (*ldexpl)(ldbl, int),
                (*lgammal)(ldbl),
                (*log10l)(ldbl),
                (*log1pl)(ldbl),
                (*log2l)(ldbl),
                (*logbl)(ldbl),
                (*logl)(ldbl),
                (*modfl)(ldbl, ldbl_p),
                (*nearbyintl)(ldbl),
                (*nextafterl)(ldbl, ldbl),
                (*nexttowardl)(ldbl, ldbl),
                (*powl)(ldbl, ldbl),
                (*remainderl)(ldbl, ldbl),
                (*remquol)(ldbl, ldbl, int_p),
                (*rintl)(ldbl),
                (*roundl)(ldbl),
                (*scalblnl)(ldbl, long),
                (*scalbnl)(ldbl, int),
                (*sinhl)(ldbl),
                (*sinl)(ldbl),
                (*sqrtl)(ldbl),
                (*tanhl)(ldbl),
                (*tanl)(ldbl),
                (*tgammal)(ldbl),
                (*truncl)(ldbl),
                (*nanl)(bytes);
        };
        struct {
            double
                (*jn)(int, double),
                (*yn)(int, double),        
                (*acos)(double),
                (*acosh)(double),
                (*asin)(double),
                (*asinh)(double),
                (*atan)(double),
                (*atan2)(double, double),
                (*atanh)(double),
                (*cbrt)(double),
                (*ceil)(double),
                (*copysign)(double, double),
                (*cos)(double),
                (*cosh)(double),
                (*erf)(double),
                (*erfc)(double),
                (*exp)(double),
                (*exp2)(double),
                (*expm1)(double),
                (*fabs)(double),
                (*fdim)(double, double),
                (*floor)(double),
                (*fma)(double, double, double),
                (*fmax)(double, double),
                (*fmin)(double, double),
                (*fmod)(double, double),
                (*frexp)(double, int_p),
                (*hypot)(double, double),
                (*j0)(double),
                (*j1)(double),
                (*ldexp)(double, int),
                (*lgamma)(double),
                (*log)(double),
                (*log10)(double),
                (*log1p)(double),
                (*log2)(double),
                (*logb)(double),
                (*modf)(double, double_p),
                (*nearbyint)(double),
                (*nextafter)(double, double),
                (*nexttoward)(double, ldbl),
                (*pow)(double, double),
                (*remainder)(double, double),
                (*remquo)(double, double, int_p),
                (*rint)(double),
                (*round)(double),
                (*scalbln)(double, long),
                (*scalbn)(double, int),
                (*sin)(double),
                (*sinh)(double),
                (*sqrt)(double),
                (*tan)(double),
                (*tanh)(double),
                (*tgamma)(double),
                (*trunc)(double),
                (*y0)(double),
                (*y1)(double), 
                (*nan)(bytes);
        };
        struct {
            float
                (*acosf)    (float),
                (*acoshf)   (float),
                (*asinf)    (float),
                (*asinhf)   (float),
                (*atan2f)   (float, float),
                (*atanf)    (float),
                (*atanhf)   (float),
                (*cbrtf)    (float),
                (*ceilf)    (float),
                (*copysignf)(float, float),
                (*cosf)     (float),
                (*coshf)    (float),
                (*erfcf)    (float),
                (*erff)     (float),
                (*exp2f)    (float),
                (*expf)     (float),
                (*expm1f)   (float),
                (*fabsf)    (float),
                (*fdimf)    (float, float),
                (*floorf)   (float),
                (*fmaf)     (float, float, float),
                (*fmaxf)    (float, float),
                (*fminf)    (float, float),
                (*fmodf)    (float, float),
                (*frexpf)   (float, int_p),
                (*hypotf)   (float, float),
                (*ldexpf)   (float, int),
                (*lgammaf)  (float),
                (*log10f)   (float),
                (*log1pf)   (float),
                (*log2f)    (float),
                (*logbf)    (float),
                (*logf)     (float),
                (*modff)    (float, float_p),
                (*nanf)     (bytes),
                (*nearbyintf)(float),
                (*nextafterf)(float, float),
                (*nexttowardf)(float, ldbl),
                (*powf)     (float, float),
                (*remainderf)(float, float),
                (*remquof)  (float, float, int_p),
                (*rintf)    (float),
                (*roundf)   (float),
                (*scalblnf) (float, long),
                (*scalbnf)  (float, int),
                (*sinf)     (float),
                (*sinhf)    (float),
                (*sqrtf)    (float),
                (*tanf)     (float),
                (*tanhf)    (float),
                (*tgammaf)  (float),
                (*truncf)   (float);
        }; 
    };           // <math.h>

    struct {
        ssize_t 
            (*strfmon)(chars, size_t, bytes, ...),
            (*strfmon_l)(chars, size_t, locale_t, bytes, ...); 
    };           // <monetary.h>

    struct {
        int
            (*close)    (mqd_t),
            (*getattr)  (mqd_t, mq_attr_p),
            (*notify)   (mqd_t, sigevent_cp),
            (*send)     (mqd_t, fspath, size_t, unsigned),
            (*setattr)  (mqd_t, const mq_attr_p, mq_attr_p),
            (*timedsend)(mqd_t, bytes, size_t, unsigned, timespec_cp),
            (*unlink)   (fspath);
        mqd_t
            (*open)  (fspath, int, ...);
        ssize_t
            (*receive)      (mqd_t, chars, size_t, uint_p),
            (*timedreceive) (mqd_t, chars, size_t, uint_p, timespec_cp);
    } mq;        // <mqueue.h>

    struct {
        int
            (*clearerr) (DBM *),
            (*delete)   (db_t, datum),
            (*error)    (db_t),
            (*store)    (db_t, datum, datum, int),
            (*dirfno)   (db_t),
            (*pagfno)   (db_t),
            (*rdonly)   (db_t);
        void
            (*close)    (db_t);
        datum
            (*fetch)    (db_t, datum),
            (*firstkey) (db_t),
            (*nextkey)  (db_t);
        db_t
            (*open)     (fspath, int, mode_t);
    } dbm;       // <ndbm.h>

    struct {
        bytes
            (*gai_strerror)(int);
       int
            #define sa_cp sockaddr_cp, socklen_t
            #define charlen char *, socklen_t
            (*getaddrinfo)(bytes, bytes, addrinfo_cp, addrinfo_pp),
            (*getnameinfo)(sa_cp, charlen, charlen, int);
        hostent_p
            (*gethostent)(void);
        netent_p
            (*getnetbyaddr) (uint32_t, int),
            (*getnetbyname) (bytes),
            (*getnetent)    (void);
        protoent_p
            (*getprotobyname)   (bytes),
            (*getprotobynumber) (int),
            (*getprotoent)      (void);
        servent_p
            (*getservbyname)(bytes, bytes),
            (*getservbyport)(int, bytes),
            (*getservent)   (void);
        void
            (*endhostent)   (void),
            (*endnetent)    (void),
            (*endprotoent)  (void),
            (*endservent)   (void),
            (*freeaddrinfo) (addrinfo_p),
            (*sethostent)   (int),
            (*setnetent)    (int),
            (*setprotoent)  (int),
            (*setservent)   (int);
    };           // <netdb.h>

    struct {
        void
            (*if_freenameindex)(if_nameindex_p);
        chars 
            (*if_indextoname)(unsigned, chars);
        if_nameindex_p
            (*if_nameindex)(void); 
        unsigned 
            (*if_nametoindex)(fspath);
    };           // <net/if.h>

    struct {
        int
            (*UNSPECIFIED)  (in6_addr_cp),
            (*LOOPBACK)     (in6_addr_cp),
            (*MULTICAST)    (in6_addr_cp),
            (*V4MAPPED)     (in6_addr_cp),
            (*LINKLOCAL)    (in6_addr_cp),
            (*SITELOCAL)    (in6_addr_cp),
            (*V4COMPAT)     (in6_addr_cp),
            (*MC_NODELOCAL) (in6_addr_cp),
            (*MC_LINKLOCAL) (in6_addr_cp),
            (*MC_SITELOCAL) (in6_addr_cp),
            (*MC_GLOBAL)    (in6_addr_cp),
            (*MC_ORGLOCAL)  (in6_addr_cp);
    }IN6_IS_ADDR;// <netinet/in.h>

    struct {
        int 
            (*catclose)(nl_catd);
        chars
            (*catgets) (nl_catd, int, int, bytes); 
        nl_catd 
            (*catopen)(fspath, int);
    };           // <nl_types.h>

    struct {
        int
            (*poll)  (pollfds, nfds_t, time_ms),
            (*ppoll) (pollfds, nfds_t, timespec_cp, sigset_cp);
    };           // <poll.h>

    struct {
        struct {
            int
                (*getdetachstate)  (pt_attr_cp, int_p),
                (*getguardsize)    (pt_attr_cp, size_p),
                (*getinheritsched) (pt_attr_cp, int_p),
                (*getschedparam)   (pt_attr_cp, sched_param_p),
                (*getschedpolicy)  (pt_attr_cp, int_p),
                (*getscope)        (pt_attr_cp, int_p),
                (*getstack)        (pt_attr_cp, buffers, size_p),
                (*getstacksize)    (pt_attr_cp, size_p),
                (*init)            (pt_attr_p),
                (*destroy)         (pt_attr_p),
                (*setdetachstate)  (pt_attr_p, int),
                (*setguardsize)    (pt_attr_p, size_t),
                (*setinheritsched) (pt_attr_p, int),
                (*setschedparam)   (pt_attr_p, sched_param_cp),
                (*setschedpolicy)  (pt_attr_p, int),
                (*setscope)        (pt_attr_p, int),
                (*setstack)        (pt_attr_p, buffer, size_t),
                (*setstacksize)    (pt_attr_p, size_t);
        } attr;
        struct {
            int
                (*destroy)(pt_barrier_p),
                (*init)   (pt_barrier_p, pt_barattr_cp, unsigned),
                (*wait)   (pt_barrier_p);
        } barrier;
        struct {
            int
                (*destroy)   (pt_barattr_p),
                (*getpshared)(pt_barattr_cp, int_p),
                (*init)      (pt_barattr_p),
                (*setpshared)(pt_barattr_p, int);
        } barrierattr;
        struct {
            int
                (*broadcast)(pt_cond_p),
                (*destroy)  (pt_cond_p),
                (*init)     (pt_cond_p, pt_condattr_cp),
                (*signal)   (pt_cond_p),
                (*timedwait)(pt_cond_p, pt_mutex_p, timespec_cp),
                (*wait)     (pt_cond_p, pt_mutex_p);
        } cond;
        struct {
            int
                (*destroy)   (pt_condattr_p),
                (*getclock)  (pt_condattr_cp, clockid_p),
                (*getpshared)(pt_condattr_cp, int_p),
                (*init)      (pt_condattr_p),
                (*setclock)  (pt_condattr_p, clockid_t),
                (*setpshared)(pt_condattr_p, int);
        } condattr;
        struct {
            int
                (*create)   (pt_key_p, pthread_f),
                (*delete)   (pt_key_t);
        } key;
        struct {
            int
                (*consistent)       (pt_mutex_p),
                (*destroy)          (pt_mutex_p),
                (*getprioceiling)   (pt_mutex_p, int_p),
                (*init)             (pt_mutex_p, pt_mutexattr_cp),
                (*lock)             (pt_mutex_p),
                (*setprioceiling)   (pt_mutex_p, int, int_p),
                (*timedlock)        (pt_mutex_p, timespec_cp),
                (*trylock)          (pt_mutex_p),
                (*unlock)           (pt_mutex_p);
        } mutex;
        struct {
            int
                (*destroy)          (pt_mutexattr_p),
                (*getprioceiling)   (pt_mutexattr_cp, int_p),
                (*getprotocol)      (pt_mutexattr_cp, int_p),
                (*getpshared)       (pt_mutexattr_cp, int_p),
                (*getrobust)        (pt_mutexattr_cp, int_p),
                (*gettype)          (pt_mutexattr_cp, int_p),
                (*init)             (pt_mutexattr_p),
                (*setprioceiling)   (pt_mutexattr_p, int),
                (*setprotocol)      (pt_mutexattr_p, int),
                (*setpshared)       (pt_mutexattr_p, int),
                (*setrobust)        (pt_mutexattr_p, int),
                (*settype)          (pt_mutexattr_p, int);
        } mutexattr;
        struct {
            int
                (*destroy)          (pt_rwlockattr_p),
                (*getpshared)       (pt_rwlockattr_cp, int_p),
                (*init)             (pt_rwlockattr_p),
                (*setpshared)       (pt_rwlockattr_p, int);
        } rwlockattr;
        struct {
            int
                (*destroy)          (pt_rwlock_p),
                (*init)             (pt_rwlock_p, pt_rwlockattr_cp),
                (*rdlock)           (pt_rwlock_p),
                (*timedrdlock)      (pt_rwlock_p, timespec_cp),
                (*timedwrlock)      (pt_rwlock_p, timespec_cp),
                (*tryrdlock)        (pt_rwlock_p),
                (*trywrlock)        (pt_rwlock_p),
                (*unlock)           (pt_rwlock_p),
                (*wrlock)           (pt_rwlock_p);
        } rwlock;
        struct {
            int
                (*destroy)  (pt_spinlock_p),
                (*init)     (pt_spinlock_p, int),
                (*lock)     (pt_spinlock_p),
                (*trylock)  (pt_spinlock_p),
                (*unlock)   (pt_spinlock_p);
        } spin;
        int
            (*kill)             (tid_t, SIG),
            (*sigmask)          (sigmask_t, sigset_cp, sigset_p),
            (*sigqueue)         (tid_t, SIG, sigval_u),
            (*setconcurrency)   (int),
            (*getconcurrency)   (void),
            (*atfork)           (exiter, exiter, exiter),
            (*create)           (tid_p, pt_attr_cp, pt_starter, buffer),
            (*once)             (pt_once_p, exiter),
            (*cancel)           (tid_t),
            (*detach)           (tid_t),
            (*equal)            (tid_t, tid_t),
            (*getcpuclockid)    (tid_t, clockid_p),
            (*getschedparam)    (tid_t, int_p, sched_param_p),
            (*join)             (tid_t, buffers),
            (*setcancelstate)   (int, int_p),
            (*setcanceltype)    (int, int_p),
            (*setschedprio)     (tid_t, int),
            (*setschedparam)    (tid_t, int, sched_param_cp),
            (*setspecific)      (pt_key_t, memory);
        tid_t
            (*self) (void);
        buffer
            (*getspecific)  (pt_key_t);
        void
            (*testcancel)   (void),
            (*exit)         (buffer);
    } pthread;   // <pthread.h>

    struct {
        void 
            (*endpwent)(void),
            (*setpwent)(void);
        passwd_p
            (*getpwent)(void), 
            (*getpwnam)(fspath),
            (*getpwuid)(uid_t);
        int 
            (*getpwnam_r)(fspath, passwd_p, chars, size_t, passwd_pp),
            (*getpwuid_r)(uid_t, passwd_p, chars, size_t, passwd_pp);
    };           // <pwd.h>

    struct {
        int 
            (*regcomp)(regex_p, bytes, int),
            (*regexec)(regex_cp, bytes, size_t, regmatch_p, int);
        size_t
            (*regerror)(int, regex_cp, chars, size_t); 
        void 
            (*regfree)(regex_p);
    };           // <regex.h>

    struct {
        int
            (*get_priority_max) (int),
            (*get_priority_min) (int),
            (*getparam)         (pid_t, sched_param_p),
            (*getscheduler)     (pid_t),
            (*rr_get_interval)  (pid_t, timespec_p),
            (*setparam)         (pid_t, sched_param_cp),
            (*setscheduler)     (pid_t, int, sched_param_cp),
            (*yield)            (void);
    } sched;     // <sched.h>

    struct {
        int 
            (*hcreate)(size_t);
        void 
            (*hdestroy)(void),
            (*insque)(buffer, buffer),
            (*remque)(buffer),
            (*twalk)(memory, visitor);
        ENTRY_p
            (*hsearch)(ENTRY, ACTION); 
        buffer
            (*lfind)    (memory, memory, size_p, size_t, bisector),
            (*lsearch)  (memory, buffer, size_p, size_t, bisector),
            (*tdelete)  (memory, buffers, bisector),
            (*tfind)    (memory, memory_p, bisector),
            (*tsearch)  (memory, buffers, bisector);
    };           // <search.h>

    struct {
        int
            (*close)    (sem_p),
            (*getvalue) (sem_p, int_p),
            (*destroy)  (sem_p),
            (*init)     (sem_p, int, unsigned),
            (*post)     (sem_p),
            (*timedwait)(sem_p, timespec_cp),
            (*trywait)  (sem_p),
            (*unlink)   (fspath),
            (*wait)     (sem_p);
        sem_p 
            (*open)     (fspath, int, ...);

    } sem; // <semaphore.h>
    // <setjmp.h>
    struct {

        void 
            (*_longjmp)   (jmp_buf, int), 
            (*longjmp)    (jmp_buf, int),
            (*siglongjmp) (sigjmp_buf, int);

        int 
            (*_setjmp)    (jmp_buf),
            (*setjmp)     (jmp_buf),
            (*sigsetjmp)  (sigjmp_buf, int);
    };

    struct {

        int
            (*kill)         (pid_t, SIG),
            (*killpg)       (pid_t, SIG),
            (*sigqueue)     (pid_t, SIG, sigval_u),
            (*raise)        (SIG),
            (*sigaction)    (SIG, sigaction_cp, sigaction_p),
            (*sigaddset)    (sigset_p, SIG),
            (*sigaltstack)  (stack_cp, stack_p),
            (*sigdelset)    (sigset_p, SIG),
            (*sigemptyset)  (sigset_p),
            (*sigfillset)   (sigset_p),
            (*sigismember)  (sigset_cp, SIG),
            (*sigpending)   (sigset_p),
            (*sigprocmask)  (sigmask_t, sigset_cp, sigset_p),
            (*sigsuspend)   (sigset_cp),
            (*sigtimedwait) (sigset_cp, siginfo_p, timespec_cp),
            (*sigwait)      (sigset_cp, int_p),
            (*sigwaitinfo)  (sigset_cp, siginfo_p),
            (*siginterrupt) (int, int), // [ob]
            (*sighold)      (SIG), // [ob]
            (*sigignore)    (sig_f), // [ob]
            (*sigpause)     (SIG), // [ob]
            (*sigrelse)     (SIG), // [ob]
            // ultra obsolescent
            (*sigvec)       (SIG, sigvec_cp, sigvec_p),
            (*sigmask)      (SIG),
            (*sigblock)     (int),
            (*sigsetmask)   (int),
            (*siggetmask)   (void);

        void
            (*psiginfo) (siginfo_cp, format),
            (*psignal)  (SIG, format);

        sig_f
            (*sigset)(SIG, sig_f), // [ob]
            (*signal)(SIG, sig_f);
    };           // <signal.h>

    // <spawn.h> is in posix.spawn*

    // <stdarg.h>
    // <stdbool.h>
    // <stddef.h>
    // <stdint.h>

    struct {

        void
            (*_Exit)    (int),
            (*abort)    (void),
            (*exit)     (int),
            (*free)     (buffer),
            (*lcong48)  (ushrt_p),
            (*qsort)    (buffer, size_t, size_t, bisector),
            (*setkey)   (bytes),
            (*srand)    (unsigned),
            (*srand48)  (long),
            (*srandom)  (unsigned);

        int
            (*abs)      (int),
            (*atexit)   (exiter),
            (*atoi)     (bytes),
            (*getsubopt)(char_pp, char_pcp, char_pp),
            (*grantpt)  (int),
            (*mblen)(   bytes, size_t),
            (*mbtowc)   (wchar_p, bytes, size_t),
            (*mkstemp)  (chars),
            (*posix_memalign)(buffers, size_t, size_t),
            (*posix_openpt)(int),
            (*putenv)   (chars),
            (*rand)     (void),
            (*rand_r)   (uint_p),
            (*setenv)   (bytes, bytes, int),
            (*system)   (bytes),
            (*unlockpt) (int),
            (*unsetenv) (bytes),
            (*wctomb)   (chars, wchar_t);

        double
            (*atof)     (bytes),
            (*drand48)  (void),
            (*erand48)  (rand48seed);

        long
            (*a64l)     (bytes),
            (*atol)     (bytes),
            (*jrand48)  (rand48seed),
            (*labs)     (long),
            (*lrand48)  (void),
            (*mrand48)  (void),
            (*nrand48)  (rand48seed),
            (*random)   (void),
            (*strtol)   (bytes, char_pp, int);

        llong_t
            (*atoll)    (bytes),
            (*llabs)    (llong_t),
            (*strtoll)  (bytes, char_pp, int);

        buffer
            (*bsearch)  (memory, memory, size_t, size_t, bisector),
            (*calloc)   (size_t, size_t),
            (*malloc)   (size_t),
            (*realloc)  (buffer, size_t);

        chars
            (*getenv)   (bytes),
            (*initstate)(unsigned, chars, size_t),
            (*l64a)     (long),
            (*mkdtemp)  (chars),
            (*ptsname)  (int),
            (*realpath) (fspath, chars),
            (*setstate) (chars);

        div_t
            (*div)(int, int);

        ldiv_t
            (*ldiv)(long, long);

        lldiv_t
            (*lldiv)(llong_t, llong_t);

        ulong_t
            (*strtoul)(bytes, char_pp, int);

        ullong_t
            (*strtoull)(bytes, char_pp, int);

        size_t
            (*wcstombs)(chars, wchar_cp, size_t),
            (*mbstowcs)(wchar_p, bytes, size_t);

        ushrt_p 
            (*seed48)(rand48seed);

        double
            (*strtod)(bytes, char_pp);

        float
            (*strtof)(bytes, char_pp);

        ldouble
            (*strtold)(bytes, char_pp);

    };           // <stdlib.h>

    struct {

        void    
            (*clearerr)         (file_p),
            (*perror)           (format),
            (*rewind)           (file_p),
            (*setbuf)           (file_p, chars),    
            (*flockfile)        (file_p),
            (*funlockfile)      (file_p);
        file_p
            (*fmemopen)         (buffer, size_t, format),
            (*fopen)            (fspath, format),  
            (*freopen)          (fspath, format, file_p),
            (*tmpfile)          (void),
            (*fdopen)           (fd, format),
            (*open_memstream)   (char_pp, size_p);

        popen_p
            (*popen)            (fspath, format);

        fd  
            (*fileno)           (file_p);

        int
            (*fclose)           (file_p),
            (*feof)             (file_p),
            (*ferror)           (file_p),
            (*fflush)           (file_p),
            (*fgetc)            (file_p),
            (*fgetpos)          (file_p, fpos_p),
            (*fprintf)          (file_p, bytes, ...),  
            (*fputc)            (int, file_p),
            (*fputs)            (bytes, file_p),
            (*fscanf)           (file_p, format , ...),
            (*fseek)            (file_p, long, int),
            (*fsetpos)          (file_p, fpos_cp),
            (*getc)             (file_p),
            (*getchar)          (void),
            (*printf)           (format, ...),
            (*putc)             (int, file_p),
            (*putchar)          (int),
            (*puts)             (fspath),
            (*remove)           (fspath),
            (*rename)           (fspath, fspath),
            (*scanf)            (format, ...),
            (*setvbuf)          (file_p, chars, int, size_t),
            (*snprintf)         (chars, size_t, format, ...),
            (*sprintf)          (chars, format, ...),
            (*sscanf)           (bytes, format, ...),
            (*ungetc)           (int, file_p),
            (*vfprintf)         (file_p, format, va_list),
            (*vfscanf)          (file_p, format, va_list),
            (*vprintf)          (format, va_list),
            (*vscanf)           (format, va_list),
            (*vsnprintf)        (chars, size_t, format, va_list),
            (*vsprintf)         (chars, format, va_list),
            (*vsscanf)          (bytes, format, va_list),
            (*dprintf)          (fd, format, ...),
            (*fseeko)           (file_p, off_t, int),
            (*ftrylockfile)     (file_p),
            (*getc_unlocked)    (file_p),
            (*getchar_unlocked) (void),
            (*pclose)           (popen_p),
            (*putc_unlocked)    (int, file_p),
            (*putchar_unlocked) (int),
            (*renameat)         (at, fspath, at, fspath),
            (*vdprintf)         (fd, format, va_list);

        chars (
            *fgets)    (chars, int, file_p),
            (*ctermid) (chars);

        long   
            (*ftell) (file_p);

        size_t  
            (*fread) (buffer, size_t, size_t, file_p),
            (*fwrite)(memory, size_t, size_t, file_p);

        off_t   
            (*ftello)(file_p);

        ssize_t   
            (*getdelim)(char_pp, size_p, int, file_p),
            (*getline) (char_pp, size_p, file_p);
    };           // <stdio.h>

    struct {

        int
            (*ffs)          (int),
            (*strcasecmp)   (bytes, bytes),
            (*strcasecmp_l) (bytes, bytes, locale_t),
            (*strncasecmp)  (bytes, bytes, size_t),
            (*strncasecmp_l)(bytes, bytes, size_t, locale_t);
    };           // <string.h>

    struct {

        buffer
            (*memchr)   (memory,         int, size_t),
            (*memset)   (buffer,         int, size_t),
            (*memccpy)  (buffer, memory, int, size_t),
            (*memcpy)   (buffer, memory, size_t),
            (*memmove)  (buffer, memory, size_t);

        chars
            (*stpcpy)   (chars, bytes),
            (*stpncpy)  (chars, bytes, size_t),
            (*strcat)   (chars, bytes),
            (*strchr)   (bytes, int),
            (*strcpy)   (chars, bytes),
            (*strdup)   (bytes),
            (*strerror) (int),
            (*strerror_l)(int, locale_t),
            (*strncat)  (chars, bytes, size_t),
            (*strncpy)  (chars, bytes, size_t),
            (*strndup)  (bytes, size_t),
            (*strpbrk)  (bytes, bytes),
            (*strrchr)  (bytes, int),
            (*strsignal)(int),
            (*strstr)   (bytes, bytes),
            (*strtok)   (chars, bytes),
            (*strtok_r) (chars, bytes, char_pp);

        int
            (*memcmp)   (memory, memory, size_t),
            (*strcmp)   (bytes, bytes),
            (*strcoll)  (bytes, bytes),
            (*strcoll_l)(bytes, bytes, locale_t),
            (*strerror_r)(int,  chars, size_t),
            (*strncmp)  (bytes, bytes, size_t);

        size_t
            (*strcspn)  (bytes, bytes),
            (*strlen)   (bytes),
            (*strnlen)  (bytes, size_t),
            (*strspn)   (bytes, bytes),
            (*strxfrm)  (chars, bytes, size_t),
            (*strxfrm_l)(chars, bytes, size_t, locale_t);    
        };           // <strings.h>

    struct {

        int
            (*fattach)  (fd, fspath),
            (*fdetach)  (fspath),
            (*getmsg)   (fd, strbuf_p, strbuf_p, int *),
            (*getpmsg)  (fd, strbuf_p, strbuf_p, int *, int *),
            (*ioctl)    (fd, iop, ...),
            (*isastream)(fd),
            (*putmsg)   (fd, strbuf_cp, strbuf_cp, int),
            (*putpmsg)  (fd, strbuf_cp, strbuf_cp, int, int);
    };           // <stropts.h>

    struct {

        key_t 
            (*ftok) (fspath, int);
    };           // <sys/ipc.h>

    struct {

        buffer
            (*mremap)     (buffer, size_t, size_t, mremap_f, ...),
            (*mmap)       (buffer, size_t, prot_f, map_f, fd, off_t);

        int
            (*madvise)    (buffer, size_t, madv_f),
            (*mincore)    (buffer, size_t, uchars),
            (*munmap)     (buffer, size_t),
            (*mprotect)   (buffer, size_t, prot_f),
            (*msync)      (buffer, size_t, ms_f),
            (*mlock)      (memory, size_t),
            (*munlock)    (memory, size_t),
            (*mlockall)   (mcl_f),
            (*munlockall) (void),
            (*memfd_create)(fspath, mfd_f);

        // _POSIX_SHARED_MEMORY_OBJECTS [SHM]
        struct {

            int
                (*open)   (fspath, int, mode_t),
                (*unlink) (fspath);
        } shm;

    };           // <sys/mman.h>

    struct {

        int
            (*msgctl)(int, int, msqid_ds_p),
            (*msgget)(key_t, int),
            (*msgsnd)(int, memory, size_t, int);

        ssize_t
            (*msgrcv)(int, buffer, size_t, long, int);
    };           // <sys/msg.h>

    struct {

        int
            (*getpriority)  (int, id_t),
            (*setpriority)  (int, id_t, int),
            (*getrlimit)    (int, rlimit_p),
            (*getrusage)    (int, rusage_p),
            (*setrlimit)    (int, rlimit_cp),
            (*prlimit)      (pid_t, int, rlimit_cp, rlimit_p);
    };           // <sys/resource.h>

    struct {

        int 
            (*semctl)   (int, int, int, ...),
            (*semget)   (key_t, int, int),
            (*semop)    (int, sembuf_p, size_t);
    };           // <sys/sem.h>

    struct {

        buffer
            (*shmat)    (int, memory, int); 

        int 
            (*shmctl)   (int, int, shmid_ds_p),
            (*shmdt)    (memory),
            (*shmget)   (key_t, size_t, int);
    };           // <sys/shm.h>

    struct {

        ssize_t
            (*recv)    (sockfd, buffer, size_t, msg_f),
            (*send)    (sockfd, memory, size_t, msg_f),
            (*recvfrom)(sockfd, buffer, size_t, msg_f, sockaddr_p, socklen_p),
            (*sendto)  (sockfd, memory, size_t, msg_f, sockaddr_cp, socklen_t),
            (*recvmsg) (sockfd, msghdr_p, msg_f),
            (*sendmsg) (sockfd, msghdr_cp, msg_f);

        sockfd
            (*accept) (sockfd, sockaddr_p, socklen_p),
            (*socket) (sockaf, sock_f, int);

        int
            (*listen)       (sockfd, int),
            (*socketpair)   (sockaf, sock_f, int, pipes),
            (*bind)         (sockfd, sockaddr_cp, socklen_t),
            (*connect)      (sockfd, sockaddr_cp, socklen_t),
            (*getpeername)  (sockfd, sockaddr_p, socklen_p),
            (*getsockopt)   (sockfd, socklv, sockop, buffer, socklen_p),
            (*setsockopt)   (sockfd, socklv, sockop, memory, socklen_t),
            (*getsockname)  (sockfd, sockaddr_p, socklen_p),
            (*shutdown)     (sockfd, shut_f),
            (*sockatmark)   (sockfd);

        socklen_t 
            (*IP_MSFILTER_SIZE)(size_t);

        struct {

            uint8_p
                (*DATA)    (cmsghdr_p);

            cmsghdr_p
                (*NXTHDR)  (msghdr_p, cmsghdr_p),
                (*FIRSTHDR)(msghdr_p);

            size_t
                (*LEN)  (size_t),
                (*SPACE)(size_t),
                (*ALIGN)(size_t);
        } CMSG;
        };           // <sys/socket.h>

    struct {

        void
            (*FD_CLR)   (fd, fds),
            (*FD_SET)   (fd, fds),
            (*FD_ZERO)  (fds);

        int
            (*FD_ISSET) (fd, fds),
            (*select)   (nfds, fds, fds, fds, timeval_p),
            (*pselect)  (nfds, fds, fds, fds, timespec_cp, sigset_cp);
    };           // <sys/select.h>

    struct {

        int
            // (as boolean)
            (*S_ISPIPE)    (mode_t),
            (*S_ISCHR )    (mode_t),
            (*S_ISBLK)     (mode_t),
            (*S_ISDIR)     (mode_t),
            (*S_ISREG)     (mode_t),
            (*S_ISLNK)     (mode_t),
            (*S_ISSOCK)    (mode_t),
            (*S_TYPEISMQ)  (stat_cp),
            (*S_TYPEISSEM) (stat_cp),
            (*S_TYPEISSHM) (stat_cp),
            (*S_TYPEISTMO) (stat_cp),
            // (status)
            (*lstat)    (fspath, stat_p),
            (*stat)     (fspath, stat_p),
            (*chmod)    (fspath, mode_t),
            (*mkdir)    (fspath, mode_t),
            (*mkfifo)   (fspath, mode_t),
            (*mknod)    (fspath, mode_t, dev_t),
            (*fchmod)   (fd, mode_t),
            (*fstat)    (fd, stat_p),
            (*futimens) (fd, ftimens),
            (*fchmodat) (at, fspath, mode_t, atflag),
            (*fstatat)  (at, fspath, stat_p, atflag),
            (*mkdirat)  (at, fspath, mode_t),
            (*mkfifoat) (at, fspath, mode_t),
            (*mknodat)  (at, fspath, mode_t, dev_t),
            (*utimensat)(at, fspath, ftimens, atflag);

        mode_t
            (*umask) (mode_t);
        };           // <sys/stat.h>

    struct {

        int
            (*fstatvfs)     (fd, statvfs_p),
            (*statvfs)      (fspath, statvfs_p),
            (*fstatvfsat)   (at, fspath, statvfs_p, atflag);
    };           // <sys/statvfs.h>

    struct {

        int
            (*getitimer)    (itimer_t,   itimerval_p),
            (*gettimeofday) (timeval_p, buffer),
            (*setitimer)    (itimer_t, itimerval_cp, itimerval_p),
            (*utimes)   (fspath, ftimeus),
            (*lutimes)  (fspath, ftimeus),
            (*futimes)  (fd, ftimeus),
            (*futimesat)(at, fspath, ftimeus);
    };           // <sys/time.h>

    struct {

        clock_t 
            (*times)(tms_p); 
    };           // <sys/times.h>

    struct {

        ssize_t
            (*readv)    (fd, iovec_cp, int),
            (*writev)   (fd, iovec_cp, int),
            (*preadv)   (fd, iovec_cp, int, off_t),
            (*pwritev)  (fd, iovec_cp, int, off_t);
    };           // <sys/uio.h>

    struct {
        socklen_t 
            (*SUN_LEN)(sockaddr_un_p);
  
    /*
    #define UNIX_PATH_MAX 108
    
    #if defined(_BSD_SOURCE) || defined(_GNU_SOURCE)
    
    #   include <string.h>
    
    #   define SUN_LEN(addr) \
        (   offsetof(sockaddr_un_s, sun_path)\
        +   strlen((addr)->sun_path))
    
    #endif
    
    struct sockaddr_un {
      sa_family_t sun_family;
      char        sun_path[UNIX_PATH_MAX];
    */
    };           // <sys/un.h>

    struct {

        int 
            (*uname)(utsname_p);
    };           // <sys/utsname.h>

    struct {

        int
            (*WEXITSTATUS) (wstatus),
            (*WCOREDUMP)   (wstatus),
            (*WTERMSIG)    (wstatus),
            (*WSTOPSIG)    (wstatus),
            (*WIFEXITED)   (wstatus),
            (*WIFSTOPPED)  (wstatus),
            (*WIFSIGNALED) (wstatus),
            (*WIFCONTINUED)(wstatus),
            (*waitid)      (idtype_t, id_t, siginfo_p, waitop);

        pid_t
            (*wait)    (wstatus_p),
            (*wait3)   (wstatus_p, waitop, rusage_p),
            (*wait4)   (pid_t, wstatus_p, waitop, rusage_p),
            (*waitpid) (pid_t, wstatus_p, waitop);
    };           // <sys/wait.h>

    struct {

        void
            (*closelog)     (void),
            (*openlog)      (format, int, int),
            (*syslog)       (int, format, ...),
            (*vsyslog)      (int, format, va_list);

        int
            (*setlogmask)   (int);
    };           // <syslog.h>

    // <tar.h> 
 
    struct {

        speed_t 
            (*cfgetispeed)  (termios_cp),
            (*cfgetospeed)  (termios_cp); 

        int
            (*cfsetispeed)  (termios_p, speed_t),
            (*cfsetospeed)  (termios_p, speed_t),
            (*tcdrain)      (int),
            (*tcflow)       (int, int), 
            (*tcflush)      (int, int),
            (*tcgetattr)    (int, termios_p),
            (*tcsendbreak)  (int, int),
            (*tcsetattr)    (int, int, termios_cp);

        pid_t
            (*tcgetsid)(int);
    };           // <termios.h>

    // <tgmath.h>

    struct {

        int 
            (*clock_getcpuclockid)(pid_t, clockid_p),
            (*clock_getres)   (clockid_t, timespec_p),
            (*clock_gettime)  (clockid_t, timespec_p),
            (*clock_settime)  (clockid_t, timespec_cp),
            (*clock_nanosleep)(clockid_t, int, timespec_cp, timespec_p),
            (*nanosleep)    (timespec_cp, timespec_p);

        clock_t 
            (*clock)(void);

        double  
            (*difftime)     (time_t, time_t);

        tm_p   
            (*getdate)      (format),
            (*gmtime)       (time_cp),
            (*gmtime_r)     (time_cp, tm_p),
            (*localtime)    (time_cp),
            (*localtime_r)  (time_cp, tm_p);

        time_t  
            (*mktime) (tm_p),
            (*time)   (time_p);

        size_t 
            (*strftime)     (chars, size_t, format, tm_cp),
            (*strftime_l)   (chars, size_t, format, tm_cp, locale_t);  

        chars 
            (*strptime)     (format, format, tm_p); 

        void    
            (*tzset)        (void);

        struct {

            int
                (*create)     (clockid_t, sigevent_p, timer_p),
                (*delete)     (timer_t),
                (*getoverrun) (timer_t),
                (*gettime)    (timer_t, itimerspec_p),
                (*settime)    (timer_t, int, itimerspec_cp, itimerspec_p);
        } timer;

    };           // <time.h>

    // [OB]<trace.h>

    struct {
        
        long
            (*ulimit)(int, ...);

    };           // <ulimit.h> [OB]

    struct {

        int
            (*access)   (fspath, accmode),
            (*chdir)    (fspath),
            (*chown)    (fspath, uid_t, gid_t),
            (*chroot)   (fspath),
            (*close)    (fd),
            (*dup)      (fd),
            (*dup2)     (fd, fd),
            (*execl)    (fspath, fspath, ...),
            (*execle)   (fspath, fspath, ...),
            (*execlp)   (fspath, fspath, ...),
            (*execv)    (fspath, execvs),
            (*execve)   (fspath, execvs, execvs),
            (*execvp)   (fspath, execvs),
            (*faccessat)(at, fspath, accmode, atflag),
            (*fchdir)   (at),
            (*fchown)   (fd, uid_t, gid_t),
            (*fchownat) (at, fspath, uid_t, gid_t, int),
            (*fdatasync)(fd),
            (*fexecve)  (fd, execvs, execvs),
            (*fsync)    (fd),
            (*ftruncate)(fd, off_t),
            (*getgroups)(int, gid_p),
            (*gethostname)(chars, size_t),
            (*getlogin_r)(chars, size_t),
            (*getopt)   (int, execvs, fspath),
            (*isatty)   (fd),
            (*lchown)   (fspath, uid_t, gid_t),
            (*link)     (fspath, fspath),
            (*linkat)   (at, fspath, at, fspath, atflag),
            (*lockf)    (fd, fiop, off_t),
            (*nice)     (int),
            (*pause)    (void),
            (*pipe)     (pipes),
            (*rmdir)    (fspath),
            (*setegid)  (gid_t),
            (*seteuid)  (uid_t),
            (*setgid)   (gid_t),
            (*setpgid)  (pid_t, pid_t),
            (*setregid) (gid_t, gid_t),
            (*setreuid) (uid_t, uid_t),
            (*setuid)   (uid_t),
            (*symlink)  (fspath, fspath),
            (*symlinkat)(fspath, at, fspath),
            (*tcsetpgrp)(fd, pid_t),
            (*truncate) (fspath, off_t),
            (*ttyname_r)(fd, chars, size_t),
            (*unlink)   (fspath),
            (*unlinkat) (at, fspath, atflag),
            (*usleep)   (useconds_t);

        size_t
            (*confstr)(_CS_t, chars, size_t);

        long
            (*gethostid)   (void),
            (*fpathconf)   (fd,     _PC_t),
            (*pathconf)    (fspath, _PC_t),
            (*sysconf)     (_SC_t);

        gid_t
            (*getegid)  (void),
            (*getgid)   (void);

        uid_t
            (*geteuid)  (void),
            (*getuid)   (void);

        pid_t
            (*getpgid)  (pid_t),
            (*getsid)   (pid_t),
            (*fork)     (void),
            (*getpgrp)  (void),
            (*getpid)   (void),
            (*getppid)  (void),
            (*setpgrp)  (void),
            (*setsid)   (void),
            (*tcgetpgrp)(int),
            (*vfork)    (int);

        off_t
            (*lseek)(fd, off_t, SEEK_t);

        ssize_t
            (*pread)     (fd, buffer, size_t, off_t),
            (*pwrite)    (fd, memory, size_t, off_t),
            (*read)      (fd, buffer, size_t),
            (*write)     (fd, memory, size_t),
            (*readlink)  (fspath, chars, size_t),
            (*readlinkat)(at, fspath, chars, size_t);

        unsigned
            (*alarm)(unsigned),
            (*sleep)(unsigned);

        useconds_t
            (*ualarm)(useconds_t, useconds_t);

        chars
            (*crypt)    (bytes, bytes),
            (*getcwd)   (chars, size_t),
            (*getlogin) (void),
            (*ttyname)  (fd);

        void
            (*_exit)    (int),
            (*encrypt)  (deskey, int),
            (*swab)     (memory, memory, ssize_t),
            (*sync)     (void);
    };           // <unistd.h>

    struct {

        int
            (*utime)    (fspath, utimbuf_cp);
    };           // <utime.h>

    struct {

        void
            (*setutxent)(void),
            (*endutxent)(void); 

        utmpx_p 
            (*getutxent)  (void),
            (*getutxid)   (utmpx_cp),
            (*getutxline) (utmpx_cp),
            (*pututxline) (utmpx_cp);        
    };           // <utmpx.h>

    struct {

         int
            (*fputws)       (wchar_cp, file_p),
            (*fwide)        (file_p, int),
            (*fwprintf)     (file_p, wchar_cp, ...),
            (*fwscanf)      (file_p, wchar_cp, ...),
            (*iswalnum)     (wint_t),
            (*iswalpha)     (wint_t),
            (*iswcntrl)     (wint_t),
            (*iswctype)     (wint_t, wctype_t),
            (*iswdigit)     (wint_t),
            (*iswgraph)     (wint_t),
            (*iswlower)     (wint_t),
            (*iswprint)     (wint_t),
            (*iswpunct)     (wint_t),
            (*iswspace)     (wint_t),
            (*iswupper)     (wint_t),
            (*iswxdigit)    (wint_t),
            (*mbsinit)      (mbstate_cp),
            (*swprintf)     (wchar_p, size_t, wchar_cp, ...),
            (*swscanf)      (wchar_cp, wchar_cp, ...),
            (*vfwprintf)    (file_p, wchar_cp, va_list),
            (*vfwscanf)     (file_p, wchar_cp, va_list),
            (*vswprintf)    (wchar_p , size_t, wchar_cp, va_list),
            (*vswscanf)     (wchar_cp, wchar_cp, va_list),
            (*vwprintf)     (wchar_cp, va_list),
            (*vwscanf)      (wchar_cp, va_list),
            (*wcscmp)       (wchar_cp, wchar_cp),
            (*wcscoll)      (wchar_cp, wchar_cp),
            (*wcsncmp)      (wchar_cp, wchar_cp, size_t),
            (*wctob)        (wint_t),
            (*wmemcmp)      (wchar_cp, wchar_cp, size_t),
            (*wprintf)      (wchar_cp, ...),
            (*wscanf)       (wchar_cp, ...),
            (*wcscasecmp)   (wchar_cp, wchar_cp),
            (*wcscasecmp_l) (wchar_cp, wchar_cp, locale_t),
            (*wcscoll_l)    (wchar_cp, wchar_cp, locale_t),
            (*wcsncasecmp)  (wchar_cp, wchar_cp, size_t),
            (*wcsncasecmp_l)(wchar_cp, wchar_cp, size_t, locale_t),
            (*wcswidth)     (wchar_cp, size_t),
            (*wcwidth)      (wchar_t);

        wctype_t
            (*wctype)(bytes);

        file_p  
            (*open_wmemstream)(wchar_pp, size_p);

        size_t    
            (*mbrlen)       (bytes, size_t, mbstate_p),
            (*mbrtowc)      (wchar_p , bytes, size_t, mbstate_p),
            (*mbsrtowcs) (wchar_p, char_cpp, size_t, mbstate_p),

            (*wcrtomb)      (chars, wchar_t, mbstate_p),
            (*wcscspn)      (wchar_cp, wchar_cp),
            (*wcsftime)     (wchar_p , size_t, wchar_cp, tm_cp),
            (*wcslen)       (wchar_cp),
            (*wcsrtombs)    (chars, wchar_cpp, size_t, mbstate_p),
            (*wcsspn)       (wchar_cp, wchar_cp),
            (*wcsxfrm)      (wchar_p , wchar_cp, size_t),
            (*mbsnrtowcs)   (wchar_p, char_cpp, size_t, size_t, mbstate_p),
            (*wcsnlen)      (wchar_cp, size_t),
            (*wcsnrtombs)   (chars, wchar_cp*, size_t, size_t, mbstate_p),
            (*wcsxfrm_l)    (wchar_p , wchar_cp, size_t, locale_t);

        double  
            (*wcstod)       (wchar_cp, wchar_pp);

        float 
            (*wcstof)       (wchar_cp, wchar_pp);

        long   
            (*wcstol)       (wchar_cp, wchar_pp, int);

        ldouble 
            (*wcstold)      (wchar_cp, wchar_pp);

        llong_t
            (*wcstoll)      (wchar_cp, wchar_pp, int);

        ulong_t
            (*wcstoul)      (wchar_cp, wchar_pp, int);


        ullong_t
            (*wcstoull)     (wchar_cp, wchar_pp, int);

        wchar_p
            (*fgetws)       (wchar_p , int, file_p),
            (*wcscat)       (wchar_p , wchar_cp),
            (*wcschr)       (wchar_cp, wchar_t),
            (*wcscpy)       (wchar_p , wchar_cp),
            (*wcsncat)      (wchar_p , wchar_cp, size_t),
            (*wcsncpy)      (wchar_p , wchar_cp, size_t),
            (*wcspbrk)      (wchar_cp, wchar_cp),
            (*wcsrchr)      (wchar_cp, wchar_t),
            (*wcsstr)       (wchar_cp, wchar_cp),
            (*wcstok)       (wchar_p , wchar_cp, wchar_pp),
            (*wmemchr)      (wchar_cp, wchar_t, size_t),
            (*wmemcpy)      (wchar_p , wchar_cp, size_t),
            (*wmemmove)     (wchar_p , wchar_cp, size_t),
            (*wmemset)      (wchar_p , wchar_t, size_t),
            (*wcpcpy)       (wchar_p , wchar_cp),
            (*wcpncpy)      (wchar_p , wchar_cp, size_t),
            (*wcsdup)       (wchar_cp);

        wint_t
            (*btowc)        (int),
            (*fgetwc)       (file_p),
            (*fputwc)       (wchar_t, file_p),
            (*getwc)        (file_p),
            (*getwchar)     (void),
            (*putwc)        (wchar_t, file_p),
            (*putwchar)     (wchar_t),
            (*ungetwc)      (wint_t, file_p),
            (*towlower)     (wint_t),
            (*towupper)     (wint_t);
    };           // <wchar.h> && <wctype.h>

    struct {

        int 
            (*wordexp)(format, wordexp_p, int);

        void 
            (*wordfree)(wordexp_p);
    };           // <wordexp.h>

} Lib;

typedef struct kw_intdef{
    unsigned a: 1, n: 31;
} kw_intdef;

struct intdef {
#   define i_def(t, ...) {.name=#t, .size=sizeof(t), .i_sign=0, __VA_ARGS__}
#   define u_def(t, ...) {.name=#t, .size=sizeof(t), .i_sign=1, __VA_ARGS__}
#   define s_def(t, ...) {.name=#t, .size=sizeof(t), .i_sign=2, __VA_ARGS__}

#   define o_def(t, ...) { \
    .name=#t,               \
    .size=1,                \
    .i_sign=0,              \
    .o={.a=1, .n=sizeof(t)},\
    __VA_ARGS__             }

#   define uadef(t,q,...) { \
    .name=#t,               \
    .size=sizeof(t),        \
    .i_sign=1,              \
    .o={.a=1, .n=q}}        \
    __VA_ARGS__             }

#   define sadef(t, q,...) {\
    .name=#t,               \
    .size=sizeof(t),        \
    .i_sign=2,              \
    .o={.a=1, .n=q}         \
    __VA_ARGS__             }

#   define c_8 0
#   define c_16 1 
#   define c_32 2 
#   define c_64 3 
#   define c_le 1
#   define c_be 2

#   define c_i 0
#   define c_u 1 
#   define c_s 2

    const char *name;
    size_t size;
    unsigned 
        i_constant:     1,
        i_volatile:     1,
        i_atomic:       1,
        i_sign:         2,
        i_byteorder:    2;
    struct kw_intdef o;
};

#define INTDEF_BUF 256

void intdef(struct intdef *t, char *p) {
    if (t->i_volatile)  p = stpcpy(p, "v");
    if (t->i_atomic)    p = stpcpy(p, "a");
    if (t->i_byteorder < 0) exit(EXIT_FAILURE);
    else if (t->i_byteorder == c_le) p = stpcpy(p, "le");
    else if (t->i_byteorder == c_be) p = stpcpy(p, "be");
    else if (t->i_byteorder) exit(EXIT_FAILURE);
    if (t->i_sign < 0) exit(EXIT_FAILURE);
    else if (t->i_sign == c_i) p = stpcpy(p, "i");
    else if (t->i_sign == c_u) p = stpcpy(p, "u");
    else if (t->i_sign == c_s) p = stpcpy(p, "s");
    else exit(EXIT_FAILURE);
    if (t->size < 1) exit(EXIT_FAILURE);
    else if (t->size == 1) p = stpcpy(p, "8");
    else if (t->size == 2) p = stpcpy(p, "16");
    else if (t->size == 4) p = stpcpy(p, "32");
    else if (t->size == 8) p = stpcpy(p, "64");
    else exit(EXIT_FAILURE);
    if (t->i_constant) p = stpcpy(p, "c");
    if (t->o.a) snprintf(p, INTDEF_BUF, "#%u", t->o.n);
    
}

void include_ctypes(FILE *f) {

    char buf[INTDEF_BUF] = {0};
    struct intdef *x = (struct intdef[]) {
        i_def(char_t), 
        u_def(uchar_t), 
        s_def(schar_t),
        i_def(short_t),
        i_def(int_t),
        s_def(sshrt_t),
        s_def(signed_t),
        s_def(long_t), 
        s_def(llong_t),
        u_def(ushrt_t),
        u_def(unsigned_t),
        u_def(ulong_t), 
        u_def(ullong_t),
        s_def(blkcnt_t),
        s_def(blksize_t),
        u_def(cc_t),
        i_def(clock_t),
        i_def(clockid_t),
        i_def(dev_t),
        u_def(fsblkcnt_t), 
        u_def(fsfilcnt_t),
        i_def(gid_t),
        i_def(id_t),
        s_def(idtype_t),
        u_def(ino_t),
        u_def(in_addr_t),
        u_def(in_port_t),
        s_def(int8_t),
        s_def(int16_t),
        s_def(int32_t),
        s_def(int64_t),
        s_def(intmax_t),
        i_def(key_t),
        u_def(mode_t),
        u_def(nfds_t),
        u_def(nlink_t),
        s_def(off_t),
        s_def(pid_t),
        s_def(ptrdiff_t),
        u_def(rlim_t),
        u_def(shmatt_t),
        s_def(sig_atomic_t),
        u_def(size_t),
        u_def(sa_family_t),
        s_def(socklen_t),
        u_def(speed_t),
        s_def(ssize_t),
        s_def(suseconds_t),
        u_def(tcflag_t),        
        i_def(time_t),
        i_def(uid_t),
        u_def(uint8_t),
        u_def(uint16_t),
        u_def(uint32_t), 
        u_def(uint64_t),
        u_def(uintmax_t),
        i_def(wchar_t),
        s_def(wint_t),
        o_def(FILE),
        o_def(sem_t),
        //{.name="sem_t", .size=sizeof(sem_t), .o={.a=1,.n=sizeof(sem_t)}},
        {0}
    };
    for ( ;x->name; ++x)
        (void) intdef(x, buf),
        (void) fprintf(f, "    \042%s\042: \042%s\042,\n", x->name,  buf);
    
}


int include_sys_sem(Lib *self, FILE *file) {

    return 0;

}



#endif