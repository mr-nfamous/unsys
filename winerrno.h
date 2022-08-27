
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
enum {
    SDFX_UPDATE_FS_ATIME,
    SDFX_UPDATE_FS_BTIME,
    SDFX_UPDATE_FS_CTIME,
    SDFX_UPDATE_FS_MTIME,
    SDFX_UPDATE_FS_UID,
    SDFX_UPDATE_FS_GID,
    SDFX_UPDATE_FS_NLINK,
    SDFX_UPDATE_FS_SIZE,
    SDFX_
    
}
enum {
    aio_h,
    arpa_inet_h,
    assert_h,
    complex_h,
    cpio_h,
    ctype_h,
    dirent_h,
    dlfcn_h,
    errno_h,
    fcntl_h,
    fenv_h,
    float_h,
    fmtmsg_h,
    fnmatch_h,
    ftw_h,
    glob_h,
    grp_h,
    iconv_h,
    inttypes_h,
    iso646_h,
    langinfo_h,
    libgen_h,
    limits_h,
    locale_h,
    math_h,
    monetary_h,
    mqueue_h,
    ndbm_h,
    net_if_h,
    netdb_h,
    netinet_in_h,
    netinet_tcp_h,
    nl_types_h,
    poll_h,
    pthread_h,
    pwd_h,
    regex_h,
    sched_h,
    search_h,
    semaphore_h,
    setjmp_h,
    signal_h,
    spawn_h,
    stdarg_h,
    stdbool_h,
    stddef_h,
    stdint_h,
    stdio_h,
    stdlib_h,
    string_h,
    strings_h,
    stropts_h,
    sys_file_h, // flock
    sys_ipc_h,
    sys_mman_h,
    sys_msg_h,
    sys_resource_h,
    sys_select_h,
    sys_sem_h,
    sys_shm_h,
    sys_socket_h,
    sys_stat_h,
    sys_statvfs_h,
    sys_time_h,
    sys_times_h,
    sys_types_h,
    sys_uio_h,
    sys_un_h,
    sys_utsname_h,
    sys_wait_h,
    syslog_h,
    tar_h,
    termios_h,
    tgmath_h,
    time_h,
    trace_h,
    ulimit_h,
    unistd_h,
    utime_h,
    utmpx_h,
    wchar_h,
    wctype_h,
    wordexp_h,
}
    
enum {
    EPERM           = 1,    /* PyExc_PermissionError */
    ENOENT          = 2,    /* FileNotFoundError */
    ESRCH           = 3,    /* ProcessLookupError */
    EINTR           = 4,    /* InterruptedError */
    EIO             = 5,    /* IOError  */
    ENXIO           = 6,    /* IOError */
    E2BIG           = 7,    /* EnvironmentError */
    ENOEXEC         = 8,    /* ExecutableError */
    EBADF           = 9,    /* BadFileDescriptor */
    ECHILD          = 10,   /* ChildProcessError */
    EAGAIN          = 11,   /* BlockingIOError */
    ENOMEM          = 12,   /* MemoryError */
    EACCESS         = 13,   /* PermissionError */
    EFAULT          = 14,   /* MemoryError */
    
    EBUSY           = 16,   /* */
    EEXIST          = 17,   /* FileExistsError */
    EXDEV           = 18,   /* */
    ENODEV          = 19,   /* */
    ENOTDIR         = 20,   /* NotADirectoryError */
    EISDIR          = 21,   /* IsADirectoryError */
    EINVAL          = 22,   /* */
    ENFILE          = 23,   /**/
    EMFILE          = 24,   /**/
    ENOTTY          = 25,   /**/

    EFBIG           = 27,   /**/
    ENOSPC          = 28,   /**/
    ESPIPE          = 29,   /* UnseekableFile */
    EROFS           = 30,   /* ReadOnlyFilesystem */
    EMLINK          = 31,   /* TooManyLinksError */
    EPIPE           = 32,   /* BrokenPipeError */
    EDOM            = 33,   /* DomainError */
    ERANGE          = 34,   /* RangeError */

    EDEADLK         = 36,   /* DeadlockError */

    ENAMETOOLONG    = 38,   /* FilenameError */
    ENOLCK          = 39,   /* NoFreeLocks */
    ENOSYS          = 40,   /* */
    ENOTEMPTY       = 41,   /* DirectoryNotEmptyError */
    EILSEQ          = 42,   /* IllegalSequenceError */
    
    EADDRINUSE      = 100,
    EADDRNOTAVAIL   = 101,
    EAFNOSUPPORT    = 102,
    EALREADY        = 103,
    EBADMSG         = 104,
    ECANCELED       = 105,
    ECONNABORTED    = 106, /* ConnectionAbortedError */
    ECONNREFUSED    = 107, /* ConnectionRefusedError */
    ECONNRESET      = 108, /* ConnectionResetError */
    EDESTADDRREQ    = 109,
    EHOSTUNREACH    = 110,
    EIDRM           = 111,
    EINPROGRESS     = 112,
    EISCONN         = 113,
    ELOOP           = 114,
    EMSGSIZE        = 115,
    ENETDOWN        = 116,
    ENETRESET       = 117,
    ENETUNREACH     = 118,
    ENOBUFS         = 119,
    ENODATA         = 120,
    ENOLINK         = 121,
    ENOMSG          = 122,
    ENOPROTOOPT     = 123,
    ENOSR           = 124,
    ENOSTR          = 125,
    ENOTCONN        = 126, /* ConnectionError */
    ENOTRECOVERABLE = 127,
    ENOTSOCK        = 128,
    ENOTSUP         = 129,
    EOPNOTSUPP      = 130,
    EOTHER          = 131,
    EOVERFLOW       = 132,
    EOWNERDEAD      = 133,
    EPROTO          = 134,
    EPROTONOSUPPORT = 135,
    EPROTOTYPE      = 136,
    ETIME           = 137,
    ETIMEDOUT       = 138, /* TimeoutError */
    ETXTBSY         = 139,
    EWOULDBLOCK     = 140, /* BlockingIOError */
    // EDQUOT=122
    
    BlockingIOError         // EAGAIN, EWOULDBLOCK
    BrokenPipeError         // EPIPE
    ChildProcessError       // ECHILD
    ConnectionAbortedError  // ECONNABORTED
    ConnectionError         // ENOTCONN
    ConnectionRefusedError  // ECONNREFUSED
    ConnectionResetError    // ECONNRESET
    EnvironmentError 
    FileExistsError         // EEXIST
    FileNotFoundError       // ENOENT
    IOError                 // EIO
    InterruptedError IsADirectoryError NotADirectoryError OSError PermissionError ProcessLookupError TimeoutError
    
    
    ArithmeticError 
    AssertionError 
    AttributeError 
    BaseException 
    BlockingIOError 
    
    BufferError 
    BytesWarning 
    ChildProcessError 
    ConnectionAbortedError 
    ConnectionError 
    ConnectionRefusedError 
    ConnectionResetError
    DeprecationWarning 
    EOFError 
    EncodingWarning 
    EnvironmentError 
    Exception 
    FileExistsError 
    FileNotFoundError 
    FloatingPointError 
    FutureWarning 
    GeneratorExit 
    IOError 
    ImportError 
    ImportWarning 
    IndentationError 
    IndexError 
    
    IsADirectoryError 
    KeyError 
    KeyboardInterrupt LookupError MemoryError 
    ModuleNotFoundError NameError NotADirectoryError 
    NotImplementedError OSError OverflowError 
    PendingDeprecationWarning PermissionError 
    ProcessLookupError RecursionError ReferenceError 
    ResourceWarning 
    RuntimeError 
    RuntimeWarning 
    StopAsyncIteration 
    StopIteration
    SyntaxError 
    SyntaxWarning 
    SystemError 
    SystemExit TabError 
    TimeoutError 
    TypeError UnboundLocalError 
    UnicodeDecodeError 
    UnicodeEncodeError 
    UnicodeError 
    UnicodeTranslateError 
    UnicodeWarning UserWarning ValueError 
    Warning ZeroDivisionError
  
};

struct syscall_info {
    const char     *name;
    char            head;
    unsigned char  *errs;
};

enum unsyscall {

    // <math.h>
    OS_NANF,        /* (string) */
    OS_FABSF,       /* (float)  */
    OS_NAN,         /* (string) */
    OS_FABS,        /* (double) */
    OS_FABSL,       /* (lngdbl) */
    OS_NANL,        /* (string) */

    // <inttypes.h>
    OS_STRTOIMAX,   /* (string, strptr, strtob) */
    OS_STRTOUMAX,   /* (string, strptr, strtob) */
    OS_WCSTOIMAX,   /* (wcsstr, wcsptr, strtob) */
    OS_WCSTOUMAX,   /* (wcsstr, wcsptr, strtob) */
    OS_ATOIMAX,     /* (string) */
    OS_IMAXABS,     /* (intmax) */
    OS_IMAXDIV,     /* (intmax, intmax) */
    // <stdlib.h>

    OS_STRTOI,      /* (string, strptr, strtob) */
    OS_STRTOU,      /* (string, strptr, strtob) */
    OS_WCSTOI,      /* (wcsstr, wcsptr, strtob) */
    OS_WCSTOU,      /* (wcsstr, wcsptr, strtob) */
    OS_ATOI,        /* (string) */
    OS_ABS,         /* (int)    */
    OS_DIV,         /* (int)    */

    OS_STRTOL,      /* (string, strptr, strtob) */
    OS_STRTOUL,     /* (string, strptr, strtob) */
    OS_WCSTOL,      /* (wcsstr, wcsptr, strtob) */
    OS_WCSTOUL,     /* (wcsstr, wcsptr, strtob) */
    OS_ATOL,        /* (string) */
    OS_LABS,        /* (long)   */
    OS_LDIV,        /* (long, long) */

    OS_STRTOLL,     /* (string, strptr, strtob) */
    OS_STRTOULL,    /* (string, strptr, strtob) */
    OS_WCSTOLL,     /* (wcsstr, wcsptr, strtob) */
    OS_WCSTOULL,    /* (wcsstr, wcsptr, strtob) */
    OS_ATOLL,       /* (string) */
    OS_LLABS,       /* (llong)  */
    OS_LLDIV,       /* (llong, llong)  */
    
    OS_STRTOF,      /* (string, strptr) */
    OS_WCSTOF,      /* (wcsstr, wcsptr) */

    OS_STRTOD,      /* (string, strptr) */
    OS_WCSTOD,      /* (wcsstr, wcsptr) */

    OS_WCSTOLD,     /* (wcsstr, wcsptr) */
    OS_STRTOLD,     /* (string, strptr) */

    OS_ABORT,       /* () */
    OS_ATEXIT,      /* (exhand) */
    OS_EXIT,        /* (exstat)             */
    OS_GETENV,      /* (string)             */
    OS_SETENV,      /* (string, string, bint)   */
    OS_PUTENV,      /* (string) */
    OS_UNSETENV,    /* (string) */
    OS_MBSTOWCS,    /* (wcsbuf, string, nbytes) */
    OS_MBTOWC,      /* (wcsbuf, string, nbytes) */
    OS_WCTOMB,      /* (buffer, wchar_t) */
    OS_WCSTOMBS,    /* (buffer, wcsstr, nbytes) */
    OS_MKSTEMP,     /* (fspath) */
    OS_MKDTEMP,     /* (fspath) */
    OS_TMPFILE,     /* (fspath) */
    OS_REALPATH,    /* (fspath, buffer) */
    OS_SYSTEM,      /* (string) */

    // <signal.h>
    OS_SIGNALSTACK, /* (staq_t, staq_t) */
    OS_SIGPROCMASK, /* (sighow, sigset, sigset) */
    OS_SIGTHRDMASK, /* (sighow, sigset, sigset) */
    OS_KILLTHRD,    /* (thrd_t, signal) */
    OS_KILL,        /* (pid_t,  signal) */
    OS_KILLPG,      /* (pid_t,  signal) */
    OS_SIGQUEUE,    /* (pid_t,  signal, sigval) */
    OS_RAISE,       /* (signal) */
    OS_SIGNAL,      /* (signal, sihand) */
    OS_SIGACTION,   /* (signal, sigact, sigact) */
    OS_SIGSUSPEND,  /* (sigset) */
    OS_SIGPENDING,  /* (sigset) */
    OS_SIGEMPTYSET, /* (sigset) */
    OS_SIGFILLSET,  /* (sigset) */
    OS_SIGISMEMBER, /* (sigset, signal) */
    OS_SIGADDSET,   /* (sigset, signal) */
    OS_SIGDELSET,   /* (sigset, signal) */
    OS_SIGWAITINFO, /* (sigset, siinfo) */
    OS_SIGTIMEDWAIT,/* (sigset, siinfo, timens) */

    // <sched.h> 
    OS_YIELD,       /* () */
    // <unistd.h>

    OS_ALARM,       /* (sec)*/
    OS_PAUSE,       /* ()   */
    OS_FORK,        /* ()   */
    OS_GETPID,      /* ()   */
    OS_GETPPID,     /* ()   */
    OS_GETUID,      /* ()   */
    OS_GETEUID,     /* ()   */
    OS_GETGID,      /* ()   */
    OS_GETEGID,     /* ()   */
    OS_SYNC,        /* ()   */
    OS_SYSCONF,     /* (sysconf) */
    OS_GETCWD,      /* (fspath)             */
    OS_CHDIR,       /* (fspath)                                 */
    OS_FCHDIR,      /* (dirfd)                                  */
    OS_FCHDIRAT,    /* (dirfd,  fspath)                         */
    OS_ACCESS,      /* (fspath, okflag)                         */
    OS_FACCESS,     /* (fileno, okflag)                         */
    OS_FACCESSAT,   /* (dirfd,  fspath, okflag, atflag)         */
    OS_CHOWN,       /* (fspath, uid,    gid)                    */
    OS_LCHOWN,      /* (fspath, uid,    gid)                    */
    OS_FCHOWN,      /* (fileno, uid,    gid)                    */
    OS_FCHOWNAT,    /* (dirfd,  fspath, uid, gid, atflag)       */
    OS_CHROOT,      /* (fspath)                                 */
    OS_FCHROOT,     /* (fileno)                                 */
    OS_FCHROOTAT,   /* (dirfd,  fspath, atflag)                 */
    OS_CLOSE,       /* (fileno)                                 */
    OS_DUP,         /* (fileno)                                 */
    OS_DUP2,        /* (fileno, fileno)                         */
    OS_DUP3,        /* (fileno, fileno, open_t)                 */
    OS_EXECV,       /* (fspath, argv_t)                         */
    OS_EXECVE,      /* (fspath, argv_t, envp_t)                 */
    OS_FEXECVE,     /* (fileno, argv,   envp_t)                 */
    OS_EXECVEAT,    /* (dirfd,  fspath, argv_t, envp_t, atflag) */
    OS_FDATASYNC,   /* (fileno)                                 */
    OS_FSYNC,       /* (fileno)                                 */
    OS_PATHCONF,    /* (fspath)                                 */ 
    OS_FPATHCONF,   /* (fileno)                                 */
    OS_FPATHCONFAT, /* (dirfd,  fspath, atflag)                 */
    OS_TRUNCATE,    /* (fspath, fpos_t)                         */
    OS_FTRUNCATE,   /* (fileno, fpos_t)                         */
    OS_FTRUNCATEAT, /* (dirfd,  fspath, fpos_t, atflag)         */
    OS_ISATTY,      /* (fileno)                                 */
    OS_LINK,        /* (fspath, fspath)                         */
    OS_LINKAT,      /* (dirfd,  fspath, dirfd, fspath, atflag)  */
    /* 
                | S |
                | Y |
                | M | S |
                | L | Y |
                | I | M |   |   |   | N
                | N | L |   |   |   | O
                | K | I |   |   | E | _
                | _ | N | R |   | M | A
                | N | K | E |   | P | U
                | O | _ | M | E | T | T
                | F | F | O | A | Y | O
                | O | O | V | C | _ | M
                | L | L | E | C | P | O
                | L | L | D | E | A | U
                | O | O | I | S | T | N
                | W | W | R | S | H | T
                |   |   |   |   |   |   |
    ————————————|———|———|———|———|———|———|———|
    FACCESSAT   | × |   |   | × |   |   |
    ————————————|———|———|———|———|———|———|———|
    LINKAT      |   | × |   |   | × |   |
    ————————————|———|———|———|———|———|———|———|
    EXECVEAT    | × |   |   |   | × |   |
    ————————————|———|———|———|———|———|———|———|
    CHOWNAT     | × |   |   |   | × |   |
    ————————————|———|———|———|———|———|———|———|
    CHMODAT     | × |   |   |   |   |   |   
    ————————————|———|———|———|———|———|———|———|
    FSTATAT     | × |   |   |   | × | × |
    ————————————|———|———|———|———|———|———|———|
    UTIMENSAT   | × |   |   |   |   |   |
    ————————————|———|———|———|———|———|———|———|
    UNLINKAT    |   |   | × |   |   |   |
    ————————————|———|———|———|———|———|———|———|

    SYMLINKAT 
    MKFIFOAT 
    MKNODAT 
    MKDIRAT
    RENAMEAT 
    OPENAT 
    READLINKAT
    SCANDIRAT 
    FTRUNCATEAT*
    FDOPENAT*
    */
    OS_LOCKF,       /* (fileno, lock_t, fpos_t)                 */
    OS_LSEEK,       /* (fileno, fpos_t, seek_t)                 */
    OS_READLINK,    /* (fspath, buffer, nbytes)                 */
    OS_READLINKAT,  /* (dirfd,  fspath, buffer, nbytes)         */
    OS_SYMLINK,     /* (string, fspath)                         */
    OS_SYMLINKAT,   /* (fspath, dirfd,  fspath)                 */
    OS_RMDIR,       /* (fspath)                                 */
    OS_READ,        /* (fileno, buffer, nbytes)                 */
    OS_PREAD,       /* (fileno, buffer, nbytes, fpos_t)         */
    OS_WRITE,       /* (fileno, memory, nbytes)                 */
    OS_PWRITE,      /* (fileno, memory, nbytes, fpos_t)         */ 
    OS_TTYNAME,     /* (fileno, buffer, nbytes)                 */
    OS_UNLINK,      /* (fspath)                                 */
    OS_UNLINKAT,    /* (dirfd,  fspath, atflag)                 */

    // <fcntl.h> 
    OS_CREAT,       /* (fspath, mode_t)                 */
    OS_FCNTL,       /* (fileno, fctl_t, ...)            */
    OS_OPEN,        /* (fspath, open_t, mode_t)         */
    OS_OPENAT,      /* (dirfd,  fspath, open_t, mode_t) */
    OS_FADVISE,     /* (fileno, fpos_t, fpos_t, fadv_t) */
    OS_FALLOCATE,   /* (fileno, fpos_t, fpos_t)         */

    // <fnmatch.h>
    OS_FNMATCH,     /* (fspath, string, fnm_t)  */
    OS_WFNMATCH,    /* (wfpath, widecs, fnm_t)  */
    // <dirent.h>
    OS_CLOSEDIR,    /* (dir)            */
    OS_DIRFD,       /* (dir)            */
    OS_FDOPENDIR,   /* (fileno)         */
    OS_OPENDIR,     /* (fspath)         */
    OS_OPENDIRAT,   /* (dirfd, fspath)  */
    OS_READDIR,     /* (dir)            */
    OS_REWINDDIR,   /* (dir)            */
    OS_SEEKDIR,     /* (dir,   long_t)  */
    OS_TELLDIR,     /* (dir)            */
    // <stdio.h> && <wchar.h>

    OS_DPRINTF,     /* (fileno, string, ...)                    */
    OS_DWPRINTF,    /* (fileno, widecs, ...)                    */

    OS_FPRINTF,     /* (file,   string, ...)                    */
    OS_FWPRINTF,    /* (file,   widecs, ...)                    */

    OS_SPRINTF,     /* (buffer, string, ...)                    */
    OS_SWPRINTF,    /* (wcsbuf, widecs, ...)                    */

    OS_DSCANF,      /* (fileno, string, ...)                    */
    OS_DWSCANF,     /* (fileno, string, ...)                    */

    OS_FSCANF,      /* (file,   string, ...)                    */
    OS_FWSCANF,     /* (file,   widecs, ...)                    */

    OS_SSCANF,      /* (buffer, string, ...)                    */
    OS_SWSCANF,     /* (widecs, widecs, ...)                    */

    OS_FOPEN,       /* (fspath, string)                     */
    OS_FDOPEN,      /* (fileno, string)                     */
    OS_FDOPENAT,    /* (dirfd,  fspath, string)             */
    OS_FREOPEN,     /* (fspath, string, file)               */
    OS_FREOPENAT,   /* (dirfd,  fspath, string, file)       */
    OS_POPEN,       /* (string, string)                     */

    OS_PCLOSE,      /* (file)                               */
    OS_FCLOSE,      /* (file)                               */
    OS_FFLUSH,      /* (file)                               */
    OS_FPUTC,       /* (char,   file)                       */
    OS_FPUTWC,      /* (widech, file)                       */

    OS_FPUTS,       /* (string, file)                       */
    OS_FPUTWS,      /* (widecs, file)                       */

    OS_FGETC,       /* (file)                               */
    OS_FGETWC,      /* (file)                               */

    OS_FGETS,       /* (file,   nchars, buffer)             */
    OS_FGETWS,      /* (file,   nchars, wcsbuf)             */

    OS_SETBUF,      /* (file,   buffer)                     */
    OS_SETVBUF,     /* (file,   buffer, _IO_T, nbytes)      */

    OS_FGETPOS,     /* (file,   fpos_t)                     */
    OS_FSETPOS,     /* (file,   fpos_t)                     */

    OS_FTELL,       /* (file)                               */
    OS_FSEEK,       /* (file,   long_t, seek_t)             */
    OS_FSEEKO,      /* (file,   fpos_t, seek_f)             */
    OS_REWIND,      /* (file)                               */
    OS_CLEARERR,    /* (file)                               */
    OS_FEOF,        /* (file)                               */
    OS_FERROR,      /* (file)                               */
    OS_FILENO,      /* (file)                               */

    // <sys/ioctl.h>
    OS_IOCTL,       /* (fileno, ictl_t, ...)                            */

    // sys_socket,
    OS_ACCEPT,      /* (sockfd, addr_t, addlen)                         */
    OS_BIND,        /* (sockfd, addr_t, addlen)                         */
    OS_CONNECT,     /* (sockfd, addr_t, addlen)                         */
    OS_GETPEERNAME, /* (sockfd, addr_t, addlen)                         */
    OS_GETSOCKNAME, /* (sockfd, addr_t, addlen)                         */

    OS_GETSOCKOPT,  /* (sockfd, socklv, sockop, buffer, nbytes)         */
    OS_SETSOCKOPT,  /* (sockfd, socklv, sockop, buffer, nbytes)         */
    /*

    [IPPROTO_ICMP:1] | [SOL_SOCKET]
        [SO_ACCEPTCONN]
        [SO_BROADCAST]
        [SO_DEBUG]
        [SO_DONTROUTE]
        [SO_ERROR]
        [SO_KEEPALIVE]
        [SO_LINGER]
        [SO_OOBINLINE]
        [SO_RCVBUF]
        [SO_RCVLOWAT]
        [SO_RCVTIMEO]
        [SO_REUSEADDR]
        [SO_SNDBUF]
        [SO_SNDLOWAT]
        [SO_SNDTIMEO]
        [SO_TYPE]

    [IPPROTO_IP         :  0] | [SOL_IP] | [IPPROTO_HOPOPTS:0]
    [IPPROTO_IGMP       :  2]
    [IPPROTO_TCP        :  6] | [SOL_TCP]:
        [TCP_CONGESTION]
        [TCP_CORK]
        [TCP_DEFER_ACCEPT]
        [TCP_FASTOPEN]
        [TCP_INFO]
        [TCP_KEEPCNT]
        [TCP_KEEPIDLE]
        [TCP_KEEPINTVL]
        [TCP_LINGER2]
        [TCP_MAXSEG]
        [TCP_NODELAY]
        [TCP_NOTSENT_LOWAT]
        [TCP_QUICKACK]
        [TCP_SYNCNT]
        [TCP_USER_TIMEOUT]
        [TCP_WINDOW_CLAMP]
    [IPPROTO_EGP        :  8]
    [IPPROTO_IPIP       :  4]
    [IPPROTO_TCP        :  6]  
    [IPPROTO_PUP        : 12]
    [IPPROTO_UDP        : 17] | |SOL_UDP]
    [IPPROTO_IDP        : 22]
    [IPPROTO_TP         : 29]
    [IPPROTO_IPV6       : 41]:
        [IPV6_CHECKSUM]
        [IPV6_DONTFRAG]
        [IPV6_DSTOPTS]
        [IPV6_HOPLIMIT]
        [IPV6_HOPOPTS]
        [IPV6_JOIN_GROUP]
        [IPV6_LEAVE_GROUP]
        [IPV6_MULTICAST_HOPS]
        [IPV6_MULTICAST_IF]
        [IPV6_MULTICAST_LOOP]
        [IPV6_NEXTHOP]
        [IPV6_PATHMTU]
        [IPV6_PKTINFO]
        [IPV6_RECVDSTOPTS]
        [IPV6_RECVHOPLIMIT]
        [IPV6_RECVHOPOPTS]
        [IPV6_RECVPATHMTU]
        [IPV6_RECVPKTINFO]
        [IPV6_RECVRTHDR]
        [IPV6_RECVTCLASS]
        [IPV6_RTHDR]
        [IPV6_RTHDRDSTOPTS]
        [IPV6_TCLASS]
        [IPV6_UNICAST_HOPS]
        [IPV6_V6ONLY]
    [IPPROTO_ROUTING    : 43]
    [IPPROTO_FRAGMENT   : 44]
    [IPPROTO_GRE        : 47]
    [IPPROTO_RSVP       : 46]
    [IPPROTO_ESP        : 50]
    [IPPROTO_AH         : 51]
    [IPPROTO_ICMPV6     : 58]
    [IPPROTO_NONE       : 59]
    [IPPROTO_DSTOPTS    : 60]
    [IPPROTO_PIM        :103]
    [IPPROTO_SCTP       :132]
    [IPPROTO_UDPLITE    :136]
    [SOL_CAN_BASE       :100]
    [SOL_CAN_RAW        :101]
    [IPPROTO_RAW        :255]
    [SOL_IPX            :256]
    [SOL_AX25           :257]
    [SOL_ATALK          :258]
    [SOL_NETROM         :259]
    [SOL_ROSE           :260]
    [IPPROTO_MPTCP      :262]
    [SOL_TIPC           :271]
    [SOL_RDS            :276]
    [SOL_ALG            :279]


    */
    OS_LISTEN,      /* (sockfd, maxcon)                                 */
    OS_RECV,        /* (sockfd, buffer, nbytes, msg_t)                  */
    OS_SEND,        /* (sockfd, buffer, nbytes, msg_t)                  */
    OS_RECVFROM,    /* (sockfd, buffer, nbytes, msg_t,  addr_t, addlen) */
    OS_SENDTO,      /* (sockfd, buffer, nbytes, msg_t,  addr_t, addlen) */
    OS_RECVMSG,     /* (sockfd, msghdr,         msg_t)                  */
    OS_SENDMSG,     /* (sockfd, msghdr,         msg_t)                  */
    OS_SOCKATMARK   /* (sockfd)                                         */
    OS_SHUTDOWN,    /* (sockfd, shut_t)                                 */
    OS_SOCKET,      /* (sockaf, sock_t, soprot)                         */
    OS_SOCKETPAIR,  /* (sockaf, sock_t, soprot, sockfd[2])              */
    /*
                    STR DGR SEQ RAW RDM PKT
 
    blth_sock = (AF_BTH,   SOCK_STREAM, BTHPROTO_RFCOMM)
    tcp6_sock = (AF_INET6, SOCK_STREAM, 0); 
    raw6_sock = (AF_INET6, SOCK_RAW, protocol); 
    udp6_sock = (AF_INET6, SOCK_DGRAM, IPPROTO_UDPLITE);

    */

    // <sys/stat.h>
    OS_CHMOD,       /* (fspath, mode_t)                         */
    OS_LCHMOD,      /* (fspath, mode_t)                         */
    OS_FCHMOD,      /* (fileno, mode_t)                         */
    OS_FCHMODAT,    /* (dirfd,  fspath, mode_t, atflag)         */
    OS_STAT,        /* (fspath, stat_t)                         */
    OS_LSTAT,       /* (fspath, stat_t)                         */
    OS_FSTAT,       /* (fileno, stat_t)                         */
    OS_FSTATAT,     /* (dirfd,  fspath, stat_t, atflag)         */
    OS_UTIME,       /* (fspath, timbuf[2])                      */
    OS_UTIMES,      /* (fspath, timeus[2])                      */
    OS_LUTIMES,     /* (fspath, timeus[2])                      */
    OS_FUTIMES,     /* (fileno, timeus[2])                      */
    OS_FUTIMENS,    /* (fileno, timens[2])                      */
    OS_UTIMENSAT,   /* (dirfd,  fspath, timens[2], atflag)      */
    OS_MKDIR,       /* (fspath, mode_t)                         */
    OS_MKDIRAT,     /* (dirfd,  fspath, mode_t)                 */
    OS_MKNOD,       /* (fspath, mode_t, dev_t)                  */
    OS_MKNODAT,     /* (dirfd,  fspath, mode_t, dev_t)          */
    OS_MKFIFO,      /* (fspath, mode_t)                         */
    OS_MKFIFOAT,    /* (fspath, mode)   */

    // <sys/statvfs.h>
    OS_FSTATVFS,    /* (fileno, statfs)         */
    OS_FSTATVFSAT,  /* (dirfd,  fspath, statfs) */
    OS_STATVFS,     /* (fspath, statfs) */

    // <sys/uio.h>
    OS_READV,       /* (fileno, iobvec, iobcnt)                 */
    OS_PREADV,      /* (fileno, iobvec, iobcnt, fpos_t)         */
    OS_PREADV2,     /* (fileno, iobvec, iobcnt, fpos_t, uiob_t) */
    OS_WRITEV,      /* (fileno, iobvec, iobcnt)                 */
    OS_PWRITEV,     /* (fileno, iobvec, iobcnt, fpos_t)         */
    OS_PWRITEV2,    /* (fileno, iobvec, iobcnt, fpos_t, uiob_t) */
    // <sys/wait.h>
    OS_WAIT,        /* (intptr) */
    OS_WAITPID,     /* (pid_t,  intptr, wait_t) */
    OS_WAITID,      /* (idtype, id_t,   siinfo, */
}
struct syscall_info_list {
    struct syscall_info
        // unistd_h
        access,                 faccessat,
        chdir,      fchdir,
        chown,      fchown,     fchownat,
        chroot,     fchroot,
                    close,  
                    dup,
                    dup2,
        execv,
        execl,
        execve,     fexecve,    execveat,
                    fdatasync,
        pathconf,   fpathconf,
                    fsync,
        truncate,   ftruncate,
                    isatty,
        lchown,    
        link,                   linkat,
                    lockf,
                    lseek,
                    
        readlink,               readlinkat,
        rmdir,                  rmdirat,
        symlink,                symlinkat,
                    read,
                    readv,
                    pread,
                    preadv,
                    write,
                    writev,
                    pwrite,
                    pwritev,
                    ttyname,
        unlink,                 unlinkat,
        // fcntl 
        creat,
                    fcntl,
        open,                   openat,
                    posix_fadvise,
                    posix_fallocate,
        //          stropts
                    ioctl,
        // sys_stat
        chmod,      fchmod,     fchmodat,
        stat,       fstat,      fstatat,
        lstat,
                    futimens,   utimensat,
        mkdir,                  mkdirat,
        mknod,                  mknodat,
        mkfifo,                 mkfifoat,
        // sys_statvfs 
        statvfs,    fstatvfs,
        
}