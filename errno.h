#pragma once

int include_errno_h(Lib *self, FILE *file) {

    __basedef(errno_h, "<errno.h>")

    __dentr(enums, Enum[])
        __predef("")
            EREF(ENODEV)
            EREF(EHOSTUNREACH)
            EREF(ENOMSG)
            EREF(ENODATA)
            EREF(ENOSYS)
            EREF(EPIPE)
            EREF(EINVAL)
            EREF(EOVERFLOW)
            EREF(EINTR)
            EREF(ENOTEMPTY)
            EREF(ENOBUFS)
            EREF(EPROTO)
            EREF(ECHILD)
            EREF(ELOOP)
            EREF(EXDEV)
            EREF(E2BIG)
            EREF(ESRCH)
            EREF(EMSGSIZE)
            EREF(EAFNOSUPPORT)
            EREF(ENOPROTOOPT)
            EREF(EBUSY)
            EREF(EAGAIN)
            EREF(EISCONN)
            EREF(EBADF)
            EREF(EMULTIHOP)
            EREF(EIO)
            EREF(EPROTOTYPE)
            EREF(ENOSPC)
            EREF(ENOEXEC)
            EREF(EALREADY)
            EREF(ENETDOWN)
            EREF(EACCES)
            EREF(EILSEQ)
            EREF(ENOTDIR)
            EREF(EPERM)
            EREF(EDOM)
            EREF(ECONNREFUSED)
            EREF(EISDIR)
            EREF(EPROTONOSUPPORT)
            EREF(EROFS)
            EREF(EADDRNOTAVAIL)
            EREF(EIDRM)
            EREF(EBADMSG)
            EREF(ENFILE)
            EREF(ESPIPE)
            EREF(ENOLINK)
            EREF(ENETRESET)
            EREF(ETIMEDOUT)
            EREF(ENOENT)
            EREF(EEXIST)
            EREF(EDQUOT)
            EREF(ENOSTR)
            EREF(EFAULT)
            EREF(EFBIG)
            EREF(ENOTCONN)
            EREF(EDESTADDRREQ)
            EREF(ENOLCK)
            EREF(ECONNABORTED)
            EREF(ENETUNREACH)
            EREF(ESTALE)
            EREF(ENOSR)
            EREF(ENOMEM)
            EREF(ENOTSOCK)
            EREF(EMLINK)
            EREF(ERANGE)
            EREF(ECONNRESET)
            EREF(EADDRINUSE)
            EREF(ENOTSUP)
            EREF(ENAMETOOLONG)
            EREF(ENOTTY)
            EREF(ETIME)
            EREF(EMFILE)
            EREF(ETXTBSY)
            EREF(EINPROGRESS)
            EREF(ENXIO)
            EREF(ECANCELED)
            EREF(EOWNERDEAD)
            EREF(ENOTRECOVERABLE)
#   ifdef ENOCSI
            EREF(ENOCSI)
#   endif
#   ifdef EUCLEAN
            EREF(EUCLEAN)
#   endif
#   ifdef EL2NSYNC
            EREF(EL2NSYNC)
#   endif
#   ifdef EL2HLT
            EREF(EL2HLT)
#   endif
#   ifdef ENOTBLK
            EREF(ENOTBLK)
#   endif
#   ifdef EADV
            EREF(EADV)
#   endif
#   ifdef EUSERS
            EREF(EUSERS)
#   endif
#   ifdef EREMOTE
            EREF(EREMOTE)
#   endif
#   ifdef ENAVAIL
            EREF(ENAVAIL)
#   endif
#   ifdef EBADR
            EREF(EBADR)
#   endif
#   ifdef EHOSTDOWN
            EREF(EHOSTDOWN)
#   endif
#   ifdef EPFNOSUPPORT
            EREF(EPFNOSUPPORT)
#   endif
#   ifdef EBADFD
            EREF(EBADFD)
#   endif
#   ifdef EDOTDOT
            EREF(EDOTDOT)
#   endif
#   ifdef ENOANO
            EREF(ENOANO)
#   endif
#   ifdef ESHUTDOWN
            EREF(ESHUTDOWN)
#   endif
#   ifdef ECHRNG
            EREF(ECHRNG)
#   endif
#   ifdef ELIBBAD
            EREF(ELIBBAD)
#   endif
#   ifdef ENONET
            EREF(ENONET)
#   endif
#   ifdef EBADE
            EREF(EBADE)
#   endif
#   ifdef EUNATCH
            EREF(EUNATCH)
#   endif
#   ifdef ENOTNAM
            EREF(ENOTNAM)
#   endif
#   ifdef ELNRNG
            EREF(ELNRNG)
#   endif
#   ifdef ENOTUNIQ
            EREF(ENOTUNIQ)
#   endif
#   ifdef EXFULL
            EREF(EXFULL)
#   endif
#   ifdef ECOMM
            EREF(ECOMM)
#   endif
#   ifdef ESRMNT
            EREF(ESRMNT)
#   endif
#   ifdef EREMOTEIO
            EREF(EREMOTEIO)
#   endif
#   ifdef EL3RST
            EREF(EL3RST)
#   endif
#   ifdef ELIBMAX
            EREF(ELIBMAX)
#   endif
#   ifdef EBADSLT
            EREF(EBADSLT)
#   endif
#   ifdef EBADRQC
            EREF(EBADRQC)
#   endif
#   ifdef ELIBACC
            EREF(ELIBACC)
#   endif
#   ifdef EDEADLOCK
            EREF(EDEADLOCK)
#   endif
#   ifdef ELIBSCN
            EREF(ELIBSCN)
#   endif
#   ifdef EISNAM
            EREF(EISNAM)
#   endif
#   ifdef ESTRPIPE
            EREF(ESTRPIPE)
#   endif
#   ifdef ELIBEXEC
            EREF(ELIBEXEC)
#   endif
#   ifdef EL3HLT
            EREF(EL3HLT)
#   endif
#   ifdef EREMCHG
            EREF(EREMCHG)
#   endif
#   ifdef ERESTART
            EREF(ERESTART)
#   endif
#   ifdef ESOCKTNOSUPPORT
            EREF(ESOCKTNOSUPPORT)
#   endif
#   ifdef EBFONT
            EREF(EBFONT)
#   endif
#   ifdef ETOOMANYREFS
            EREF(ETOOMANYREFS)
#   endif
#   ifdef ENOPKG
            EREF(ENOPKG)
#   endif
#   ifdef ENOMEDIUM
            EREF(ENOMEDIUM)
#   endif
#   ifdef EMEDIUMTYPE
            EREF(EMEDIUMTYPE)
#   endif
#   ifdef ENOKEY
            EREF(ENOKEY)
#   endif
#   ifdef EKEYEXPIRED
            EREF(EKEYEXPIRED)
#   endif
#   ifdef EKEYREVOKED
            EREF(EKEYREVOKED)
#   endif
#   ifdef EKEYREJECTED
            EREF(EKEYREJECTED)
#   endif
#   ifdef ERFKILL
            EREF(ERFKILL)
#   endif
        __preend("")
    __dexit(enums)

    __baseret(errno_h)
}
