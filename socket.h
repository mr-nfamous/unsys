
#pragma once

#include <netinet/in.h>
#include <sys/ioctl.h>

typedef struct { 
    sa_family_t sa_family; 
    uint32_t    dev_idx; 
    uint32_t    target_idx; 
    uint32_t    nfc_protocol; 
} sockaddr_nfc_s;


int sockatmark_impl(sockfd sock) { 
    int v;
    return ioctl(sock, SIOCATMARK, &v), v;
}
#define BLTN_SOCKATMARK sockatmark_impl

socklen_t ip_msfilter_size(size_t n) {
    return (socklen_t)(sizeof(struct ip_msfilter)-4+n*4);
}
cmsghdr_p 
c_CMSG_NXTHDR(msghdr_p m, cmsghdr_p c) {
    return CMSG_NXTHDR(m, c);
}

size_t   
c_CMSG_SPACE(size_t n) {
    return CMSG_SPACE(n);
}

uint8_t *    
c_CMSG_DATA(cmsghdr_p c) {
    return ((uint8_p) (c)
        +   (sizeof(cmsghdr_s))
        +   (sizeof(size_t)-1&~(sizeof(size_t)-1))
    );
}

size_t      
c_CMSG_LEN(size_t n) {
    return n+(sizeof(cmsghdr_s)+sizeof(size_t)-1&~(sizeof(size_t)-1));
}

size_t      
c_CMSG_ALIGN(size_t n) {
    return n+sizeof(size_t)-1&~(sizeof(size_t)-1);
}

cmsghdr_p   
c_CMSG_FIRSTHDR(msghdr_p m) {
    return ((m)->msg_controllen >= sizeof(cmsghdr_s)
        ?   (m)->msg_control
        :   0   
    );
}

int c_CMSG_OK(msghdr_p m, cmsghdr_p c) {
    return (
        (c)->cmsg_len >= sizeof(cmsghdr_s) &&
        (c)->cmsg_len <= (size_t) (
        (m)->msg_controllen-((char*)(c)-(char*)(m)->msg_control)));
}




/*
int builin_in6_isattr_h(Lib *self, FILE *file) {


    self->IN6_IS_ADDR.MULTICAST     = in6_is_addr_multicast;

#define IN6_IS_ADDR_V4COMPAT(a) \
  ((((a)->s6_addr32[0]) == 0) && \
   (((a)->s6_addr32[1]) == 0) && \
   (((a)->s6_addr32[2]) == 0) && \
   (((a)->s6_addr32[3]) != 0) && (((a)->s6_addr32[3]) != ntohl(1)))
    self->IN6_IS_ADDR.V4COMPAT      = in6_is_addr_v4compat;
    self->IN6_IS_ADDR.LINKLOCAL     = in6_is_addr_linklocal;
    self->IN6_IS_ADDR.SITELOCAL     = in6_is_addr_sitelocal;
    self->IN6_IS_ADDR.MC.NODELOCAL  = in6_is_addr_mc_nodelocal;
    self->IN6_IS_ADDR.MC.LINKLOCAL  = in6_is_addr_mc_linklocal;
    self->IN6_IS_ADDR.MC.SITELOCAL  = in6_is_addr_mc_sitelocal;
    self->IN6_IS_ADDR.MC.GLOBAL     = in6_is_addr_mc_global;
    self->IN6_IS_ADDR.MC.ORGLOCAL   = in6_is_addr_mc_orglocal;
    #define IN6_IS_ADDR_UNSPECIFIED
#   ifndef BLTN_UNSPECIFIED
#   define BLTN_UNSPECIFIED UNSPECIFIED _is_addr_unspecified
#   endif
*/

/*
    self->IN6_IS_ADDR.MC.NODELOCAL=    self->IN6_IS_ADDR.UNSPECIFIED=BLTN_IN6_IS_ADDR_UNSPECIFIED;
    self->IN6_IS_ADDR.LOOPBACK = BLTN_IN6_IS_ADDR_LOOPBACK;
    self->IN6_IS_ADDR.MULTICAST=BLTN_IN6_IS_ADDR_MULTICAST;
    self->IN6_IS_ADDR.V4MAPPED=BLTN_IN6_IS_ADDR_V4MAPPED;
    self->IN6_IS_ADDR.LINKLOCAL=BLTN_IN6_IS_ADDR_LINKLOCAL;
    self->IN6_IS_ADDR.SITELOCAL=BLTN_IN6_IS_ADDR_SITELOCAL;
    self->IN6_IS_ADDR.V4COMPAT=BLTN_IN6_IS_ADDR_V4COMPAT;
    self->IN6_IS_ADDR.MC.NODELOCAL=BLTN_IN6_IS_ADDR_MC_NODELOCAL;
    self->IN6_IS_ADDR.MC.LINKLOCAL=BLTN_IN6_IS_ADDR_MC_LINKLOCAL;
    self->IN6_IS_ADDR.MC.SITELOCAL=BLTN_IN6_IS_ADDR_MC_SITELOCAL;
    self->IN6_IS_ADDR.MC.GLOBAL=BLTN_IN6_IS_ADDR_MC_GLOBAL;
    self->IN6_IS_ADDR.MC.ORGLOCAL=BLTN_IN6_IS_ADDR_MC_ORGLOCAL;


#   ifndef BLTN_SITELOCAL
#   define BLTN_SITELOCAL SITELOCAL
#   endif
#   ifndef BLTN_V4COMPAT
#   define BLTN_V4COMPAT V4COMPAT
#   endif
#   ifndef BLTN_MC_NODELOCAL
#   define BLTN_MC_NODELOCAL MC_NODELOCAL
#   endif
#   ifndef BLTN_LINKLOCAL
#   define BLTN_LINKLOCAL LINKLOCAL
#   endif
#   ifndef BLTN_SITELOCAL
#   define BLTN_SITELOCAL SITELOCAL
#   endif
#   ifndef BLTN_GLOBAL
#   define BLTN_GLOBAL GLOBAL
#   endif
#   ifndef BLTN_ORGLOCAL
#   define BLTN_ORGLOCAL ORGLOCAL
#   endif
    self->IN6_IS_ADDR.UNSPECIFIED=BLTN_UNSPECIFIED;
*/

/*  
    self->IN6_IS_ADDR.LOOPBACK=BLTN_LOOPBACK;
    self->IN6_IS_ADDR.MULTICAST=BLTN_MULTICAST;
    self->IN6_IS_ADDR.V4MAPPED=BLTN_V4MAPPED;
    self->IN6_IS_ADDR.LINKLOCAL=BLTN_LINKLOCAL;
    self->IN6_IS_ADDR.SITELOCAL=BLTN_SITELOCAL;
    self->IN6_IS_ADDR.V4COMPAT=BLTN_V4COMPAT;
    self->IN6_IS_ADDR.MC.NODELOCAL=BLTN_MC_NODELOCAL;
    self->IN6_IS_ADDR.MC.LINKLOCAL=BLTN_LINKLOCAL;
    self->IN6_IS_ADDR.MC.SITELOCAL=BLTN_SITELOCAL;
    self->IN6_IS_ADDR.MC.GLOBAL=BLTN_GLOBAL;
    self->IN6_IS_ADDR.MC.ORGLOCAL=BLTN_ORGLOCAL;
*/
 


int bltn_sys_socket(Lib *self, FILE *file)  {

#   ifndef BLTN_CMSG_LEN
#   define BLTN_CMSG_LEN c_CMSG_LEN
#   endif
#   ifndef BLTN_CMSG_NXTHDR
#   define BLTN_CMSG_NXTHDR c_CMSG_NXTHDR 
#   endif
#   ifndef BLTN_CMSG_SPACE
#   define BLTN_CMSG_SPACE c_CMSG_SPACE
#   endif
#   ifndef BLTN_CMSG_DATA
#   define BLTN_CMSG_DATA c_CMSG_DATA
#   endif
#   ifndef BLTN_CMSG_FIRSTHDR
#   define BLTN_CMSG_FIRSTHDR c_CMSG_FIRSTHDR
#   endif
#   ifndef BLTN_SOCKET
#   define BLTN_SOCKET socket
#   endif
#   ifndef BLTN_RECV
#   define BLTN_RECV recv
#   endif
#   ifndef BLTN_SEND
#   define BLTN_SEND send
#   endif
#   ifndef BLTN_RECVFROM
#   define BLTN_RECVFROM recvfrom
#   endif
#   ifndef BLTN_SENDTO
#   define BLTN_SENDTO sendto
#   endif
#   ifndef BLTN_RECVMSG
#   define BLTN_RECVMSG recvmsg
#   endif
#   ifndef BLTN_SENDMSG 
#   define BLTN_SENDMSG sendmsg
#   endif
#   ifndef BLTN_SOCKETPAIR
#   define BLTN_SOCKETPAIR socketpair
#   endif
#   ifndef BLTN_ACCEPT
#   define BLTN_ACCEPT accept
#   endif
#   ifndef BLTN_BIND
#   define BLTN_BIND bind
#   endif
#   ifndef BLTN_CONNECT
#   define BLTN_CONNECT connect 
#   endif 
#   ifndef BLTN_GETPEERNAME 
#   define BLTN_GETPEERNAME getpeername
#   endif
#   ifndef BLTN_LISTEN
#   define BLTN_LISTEN listen
#   endif
#   ifndef BLTN_GETSOCKOPT
#   define BLTN_GETSOCKOPT getsockopt
#   endif
#   ifndef BLTN_LISTEN
#   define BLTN_LISTEN listen
#   endif
#   ifndef BLTN_SETSOCKOPT
#   define BLTN_SETSOCKOPT setsockopt
#   endif
#   ifndef BLTN_GETSOCKNAME
#   define BLTN_GETSOCKNAME getsockname
#   endif
#   ifndef BLTN_SHUTDOWN
#   define BLTN_SHUTDOWN shutdown
#   endif
#   ifndef BLTN_SOCKATMARK
#   define BLTN_SOCKATMARK sockatmark
#   endif
 
    self->IP_MSFILTER_SIZE  = ip_msfilter_size;

    self->IN6_IS_ADDR.UNSPECIFIED   = in6_is_addr_unspecified;
    self->IN6_IS_ADDR.LOOPBACK      = in6_is_addr_loopback;
    self->IN6_IS_ADDR.V4MAPPED      = in6_is_addr_v4mapped;

    self->CMSG.DATA     = BLTN_CMSG_DATA;
    self->CMSG.FIRSTHDR = BLTN_CMSG_FIRSTHDR;
    self->CMSG.NXTHDR   = BLTN_CMSG_NXTHDR;
    self->CMSG.SPACE    = BLTN_CMSG_SPACE;
    self->CMSG.LEN      = BLTN_CMSG_LEN;
  
    self->recv          = BLTN_RECV;
    self->send          = BLTN_SEND;
    self->recvfrom      = BLTN_RECVFROM;
    self->sendto        = BLTN_SENDTO;
    self->recvmsg       = BLTN_RECVMSG;
    self->sendmsg       = BLTN_SENDMSG;
    self->socketpair    = BLTN_SOCKETPAIR;
    self->accept        = BLTN_ACCEPT;
    self->bind          = BLTN_BIND;
    self->connect       = BLTN_CONNECT;
    self->getpeername   = BLTN_GETPEERNAME;
    self->listen        = BLTN_LISTEN;
    self->getsockopt    = BLTN_GETSOCKOPT;
    self->listen        = BLTN_LISTEN;
    self->setsockopt    = BLTN_SETSOCKOPT;
    self->getsockname   = BLTN_GETSOCKNAME;
    self->shutdown      = BLTN_SHUTDOWN;
    self->sockatmark    = BLTN_SOCKATMARK;
  
    return 0;
}

int include_sys_socket_h(Lib *self, FILE *file) {

    __basedef(sys_socket_h, "<sys/socket.h>")

    __dentr(enums, Enum[])

        __predef("SOCK")
            EDEF_(SOCK, CLOEXEC)
            EDEF_(SOCK, NONBLOCK)
        __preend("SOCK", .fmt="x", .sort=C__VSORT)

        __predef("SOCK")
            EDEF_(SOCK,DGRAM)
            EDEF_(SOCK,STREAM)
            EDEF_(SOCK,SEQPACKET)
#       if _POSIX_RAW_SOCKETS > 0
            EDEF_(SOCK,RAW)
#       endif
        __preend("SOCK", .fmt="x", .sort=C__VSORT)

        __predef("SHUT")
            EDEF_(SHUT,RD)
            EDEF_(SHUT,RDWR)
            EDEF_(SHUT,WR)
        __preend("SHUT", .sort=C__VSORT)

        __predef("MSG")
#           ifdef MSG_
            EDEF_(MSG,)
#           endif
#           ifdef MSG_CMSG_COMPAT
            EDEF_(MSG,CMSG_COMPAT)
#           endif
#           ifdef MSG_FASTOPEN
            EDEF_(MSG,FASTOPEN)
#           endif
#           ifdef MSG_BATCH
            EDEF_(MSG,BATCH)
#           endif
#           ifdef MSG_SYN
            EDEF_(MSG,SYN)
#           endif

#           ifdef MSG_EOF
            EDEF_(MSG,EOF)
#           endif
#           ifdef MSG_PROBE
            EDEF_(MSG,PROBE)
#           endif
#           ifdef MSG_CONFIRM
            EDEF_(MSG,CONFIRM)
#           endif
            EDEF_(MSG,CTRUNC)
            EDEF_(MSG,DONTROUTE)
#           ifdef MSG_DONTWAIT
            EDEF_(MSG,DONTWAIT)
#           endif
            EDEF_(MSG,EOR)
            EDEF_(MSG,OOB)
#           ifdef MSG_RST
            EDEF_(MSG,RST)
#           endif
#           ifdef MSG_MORE
            EDEF_(MSG,MORE)
#           endif
            EDEF_(MSG,NOSIGNAL)
            EDEF_(MSG,PEEK)
            EDEF_(MSG,WAITALL)
            EDEF_(MSG,TRUNC)
#           ifdef MSG_WAITFORONE
            EDEF_(MSG,WAITFORONE)
#           endif
#           ifdef MSG_CMSG_CLOEXEC
            EDEF_(MSG,CMSG_CLOEXEC)
#           endif
#           ifdef MSG_ERRQUEUE
            EDEF_(MSG,ERRQUEUE)
#           endif
#           ifdef MSG__
            EDEF_(MSG,)
#           endif
        __preend("MSG", .fmt="x", .sort=C__VSORT)

        __predef("AF")
            EDEF_(AF, UNSPEC)
            EDEF_(AF, UNIX)
            EDEF_(AF, INET)
#       if _POSIX_IPV6 > 0
            EDEF_(AF,INET6)
#       endif
        __preend("AF")

        __predef("IPPROTO")
            EDEF_(IPPROTO,IP)
            EDEF_(IPPROTO,TCP)
            EDEF_(IPPROTO,ICMP)
            EDEF_(IPPROTO,UDP)
#       if _POSIX_IPV6 > 0
            EDEF_(IPPROTO,IPV6)
#       endif
#       if _POSIX_RAW_SOCKETS > 0
            EDEF_(IPPROTO,RAW)
#       endif
        __preend("IPPROTO")

        __predef("IP")
#           ifdef IP_ADD_MEMBERSHIP
            EDEF_(IP,ADD_MEMBERSHIP)
#           endif
#           ifdef IP_ADD_SOURCE_MEMBERSHIP
            EDEF_(IP,ADD_SOURCE_MEMBERSHIP)
#           endif
#           ifdef IP_BIND_ADDRESS_NO_PORT
            EDEF_(IP,BIND_ADDRESS_NO_PORT)
#           endif
#           ifdef IP_BLOCK_SOURCE
            EDEF_(IP,BLOCK_SOURCE)
#           endif
#           ifdef IP_DROP_MEMBERSHIP
            EDEF_(IP,DROP_MEMBERSHIP)
#           endif
#           ifdef IP_DROP_SOURCE_MEMBERSHIP
            EDEF_(IP,DROP_SOURCE_MEMBERSHIP)
#           endif
#           ifdef IP_FREEBIND
            EDEF_(IP,FREEBIND)
#           endif
#           ifdef IP_HDRINCL
            EDEF_(IP,HDRINCL)
#           endif
#           ifdef IP_MSFILTER
            EDEF_(IP,MSFILTER)
#           endif
#           ifdef IP_MULTICAST_ALL
            EDEF_(IP,MULTICAST_ALL)
#           endif
#           ifdef IP_MULTICAST_IF
            EDEF_(IP,MULTICAST_IF)
#           endif
#           ifdef IP_MULTICAST_LOOP
            EDEF_(IP,MULTICAST_LOOP)
#           endif
#           ifdef IP_MULTICAST_TTL
            EDEF_(IP,MULTICAST_TTL)
#           endif
#           ifdef IP_NODEFRAG
            EDEF_(IP,NODEFRAG)
#           endif
#           ifdef IP_OPTIONS
            EDEF_(IP,OPTIONS)
#           endif
#           ifdef IP_PASSSEC
            EDEF_(IP,PASSSEC)
#           endif
#           ifdef IP_PKTINFO
            EDEF_(IP,PKTINFO)
#           endif
#           ifdef IP_RECVERR
            EDEF_(IP,RECVERR)
#           endif
#           ifdef IP_RECVOPTS
            EDEF_(IP,RECVOPTS)
#           endif
#           ifdef IP_RECVORIGDSTADDR
            EDEF_(IP,RECVORIGDSTADDR)
#           endif
#           ifdef IP_RECVTOS
            EDEF_(IP,RECVTOS)
#           endif
#           ifdef IP_RECVTTL
            EDEF_(IP,RECVTTL)
#           endif
#           ifdef IP_RETOPTS
            EDEF_(IP,RETOPTS)
#           endif
#           ifdef IP_ROUTER_ALERT
            EDEF_(IP,ROUTER_ALERT)
#           endif
#           ifdef IP_TOS
            EDEF_(IP,TOS)
#           endif
#           ifdef IP_TRANSPARENT
            EDEF_(IP,TRANSPARENT)
#           endif
#           ifdef IP_TTL
            EDEF_(IP,TTL)
#           endif
#           ifdef IP_UNBLOCK_SOURCE
            EDEF_(IP,UNBLOCK_SOURCE)
#           endif

        __preend("IP")

        __predef("INET")
            EDEF_(INET,ADDRSTRLEN)
        __preend("INET")

#       if _POSIX_IPV6 > 0

        __predef("INET6")
            EDEF_(INET6,ADDRSTRLEN)
        __preend("INET6")

        __predef("IPV6")
            EDEF_(IPV6,JOIN_GROUP)
            EDEF_(IPV6,LEAVE_GROUP)
            EDEF_(IPV6,MULTICAST_HOPS)
            EDEF_(IPV6,MULTICAST_IF)
            EDEF_(IPV6,MULTICAST_LOOP)
            EDEF_(IPV6,UNICAST_HOPS)
            EDEF_(IPV6,V6ONLY)
        __preend("IPV6")
#       endif

        __predef("SCM")
            EDEF_(SCM,RIGHTS)
#       ifdef SCM_CREDENTIALS
            EDEF_(SCM, CREDENTIALS)
#       endif
#       ifdef SCM_SECURITY
            EDEF_(SCM, SECURITY)
#       endif
        __preend("SCM")

        // rfc 3376
        __predef("MCAST")
            EDEF_(MCAST,INCLUDE)
            EDEF_(MCAST,EXCLUDE)
        __preend("MCAST")

        __predef("SOL")
            EDEF_(SOL,SOCKET)
#           ifdef SOL_AX25
            EDEF_(SOL,AX25)
#           endif
#           ifdef SOL_ATALK
            EDEF_(SOL,ATALK)
#           endif
#           ifdef SOL_IP
            EDEF_(SOL,IP)
#           endif
#           ifdef SOL_TCP
            EDEF_(SOL,TCP)
#           endif
#           ifdef SOL_UDP
            EDEF_(SOL,UDP)
#           endif
#           ifdef SOL_IPV6
            EDEF_(SOL,IPV6)
#           endif
#           ifdef SOL_ICMPV6
            EDEF_(SOL,ICMPV6)
#           endif
#           ifdef SOL_SCTP
            EDEF_(SOL,SCTP)
#           endif
#           ifdef SOL_RAW
            EDEF_(SOL,RAW)
#           endif
#           ifdef SOL_IPX
            EDEF_(SOL,IPX)
#           endif
#           ifdef SOL_NETROM
            EDEF_(SOL,NETROM)
#           endif
#           ifdef SOL_ROSE
            EDEF_(SOL,ROSE)
#           endif
#           ifdef SOL_DECNET
            EDEF_(SOL,DECNET)
#           endif
#           ifdef SOL_X25
            EDEF_(SOL,X25)
#           endif
#           ifdef SOL_PACKET
            EDEF_(SOL,PACKET)
#           endif
#           ifdef SOL_ATM
            EDEF_(SOL,ATM)
#           endif
#           ifdef SOL_AAL
            EDEF_(SOL,AAL)
#           endif
#           ifdef SOL_LLC
            EDEF_(SOL,LLC)
#           endif
#           ifdef SOL_DCCP
            EDEF_(SOL,DCCP)
#           endif
#           ifdef SOL_NETLINK
            EDEF_(SOL,NETLINK)
#           endif
#           ifdef SOL_TIPC
            EDEF_(SOL,TIPC)
#           endif
#           ifdef SOL_RXRPC
            EDEF_(SOL,RXRPC)
#           endif
#           ifdef SOL_PPPOL2TP
            EDEF_(SOL,PPPOL2TP)
#           endif
#           ifdef SOL_BLUETOOTH
            EDEF_(SOL,BLUETOOTH)
#           endif
#           ifdef SOL_PNPIPE
            EDEF_(SOL,PNPIPE)
#           endif
#           ifdef SOL_RDS
            EDEF_(SOL,RDS)
#           endif
#           ifdef SOL_IUCV
            EDEF_(SOL,IUCV)
#           endif
#           ifdef SOL_CAIF
            EDEF_(SOL,CAIF)
#           endif
#           ifdef SOL_ALG
            EDEF_(SOL,ALG)
#           endif
#           ifdef SOL_NFC
            EDEF_(SOL,NFC)
#           endif
#           ifdef SOL_KCM
            EDEF_(SOL,KCM)
#           endif
#           ifdef SOL_TLS
            EDEF_(SOL,TLS)
#           endif

        __preend("SOL")

        __predef("")
            EREF(SOMAXCONN)
        __preend("")

        __predef("")
#       ifdef    SIOCGIFNAME
            EREF(SIOCGIFNAME)
            EREF(SIOCGIFINDEX)
            EREF(SIOCGIFFLAGS)
            EREF(SIOCSIFFLAGS)
            EREF(SIOCGIFPFLAGS)
            EREF(SIOCSIFPFLAGS)
            EREF(SIOCGIFMAP)
            EREF(SIOCSIFMAP)
            EREF(SIOCGIFADDR)
            EREF(SIOCSIFADDR)
            EREF(SIOCDIFADDR)
            EREF(SIOCGIFDSTADDR) // ifr_dstaddr
            EREF(SIOCSIFDSTADDR) // ifr_dstaddr
            EREF(SIOCGIFBRDADDR) // ifr_brdaddr
            EREF(SIOCSIFBRDADDR) // ifr_brdaddr
#       endif
        __preend("", .fmt="x")
 
        __predef("")
            EREF(UNIX_PATH_MAX)
        __preend("")
 
        __predef("SO")
            EDEF_(SO,ACCEPTCONN)
            EDEF_(SO,BROADCAST)
            EDEF_(SO,DEBUG)
            EDEF_(SO,DONTROUTE)
            EDEF_(SO,ERROR)
            EDEF_(SO,KEEPALIVE)
            EDEF_(SO,LINGER)
            EDEF_(SO,OOBINLINE)
            EDEF_(SO,RCVLOWAT)
            EDEF_(SO,RCVTIMEO)
            EDEF_(SO,RCVBUF)
            EDEF_(SO,REUSEADDR)
            EDEF_(SO,SNDBUF)
            EDEF_(SO,SNDLOWAT)
            EDEF_(SO,SNDTIMEO)
            EDEF_(SO,TYPE)

#           ifdef SO_ATTACH_FILTER
            EDEF_(SO,ATTACH_FILTER)
#           endif

#           ifdef SO_BUSY_POLL
            EDEF_(SO,BUSY_POLL)
#           endif

#           ifdef SO_DETACH_FILTER
            EDEF_(SO,DETACH_FILTER)
#           endif

#           ifdef SO_NO_CHECK
            EDEF_(SO,NO_CHECK)
#           endif

#           ifdef SO_BSDCOMPAT
            EDEF_(SO,BSDCOMPAT)
#           endif

#           ifdef SO_SECURITY_AUTHENTICATION 
            EDEF_(SO,SECURITY_AUTHENTICATION)
#           endif

#           ifdef SO_SECURITY_ENCRYPTION_TRANSPORT 
            EDEF_(SO,SECURITY_ENCRYPTION_TRANSPORT) 
#           endif 

#           ifdef SO_SECURITY_ENCRYPTION_NETWORK
            EDEF_(SO,SECURITY_ENCRYPTION_NETWORK) 
#           endif 

#           ifdef SO_BINDTODEVICE
            EDEF_(SO,BINDTODEVICE) 
#           endif 

#           ifdef SO_PEERNAME 
            EDEF_(SO,PEERNAME) 
#           endif 

#           ifdef SO_WIFI_STATUS 
            EDEF_(SO,WIFI_STATUS) 
#           endif 

#           ifdef SO_NOFCS
            EDEF_(SO,NOFCS) 
#           endif 

#           ifdef SO_MAX_PACING_RATE
            EDEF_(SO,MAX_PACING_RATE) 
#           endif 

#           ifdef SO_BPF_EXTENSIONS 
            EDEF_(SO,BPF_EXTENSIONS)
#           endif

#           ifdef SO_ATTACH_BPF
            EDEF_(SO,ATTACH_BPF) 
#           endif 

#           ifdef SO_ATTACH_REUSEPORT_CBPF 
            EDEF_(SO,ATTACH_REUSEPORT_CBPF)
#           endif 

#           ifdef SO_ATTACH_REUSEPORT_EBPF 
            EDEF_(SO,ATTACH_REUSEPORT_EBPF) 
#           endif 

#           ifdef SO_CNX_ADVICE 
            EDEF_(SO,CNX_ADVICE) 
#           endif 

#           ifdef SO_MEMINFO 
            EDEF_(SO,MEMINFO) 
#           endif 

#           ifdef SO_COOKIE 
            EDEF_(SO,COOKIE) 
#           endif 

#           ifdef SO_PEERGROUPS 
            EDEF_(SO,PEERGROUPS) 
#           endif 

#           ifdef SO_ZEROCOPY 
            EDEF_(SO,ZEROCOPY) 
#           endif 

#           ifdef SO_TXTIME 
            EDEF_(SO,TXTIME) 
#           endif 

#           ifdef SO_BINDTOIFINDEX 
            EDEF_(SO,BINDTOIFINDEX) 
#           endif

#           ifdef SO_DOMAIN
            EDEF_(SO,DOMAIN)
#           endif

#           ifdef SO_INCOMING_CPU
            EDEF_(SO,INCOMING_CPU)
#           endif

#           ifdef SO_INCOMING_NAPI_ID
            EDEF_(SO,INCOMING_NAPI_ID)
#           endif

#           ifdef SO_LOCK_FILTER
            EDEF_(SO,LOCK_FILTER)
#           endif

#           ifdef SO_MARK
            EDEF_(SO,MARK)
#           endif

#           ifdef SO_PASSCRED
            EDEF_(SO,PASSCRED)
#           endif

#           ifdef SO_PASSSEC
            EDEF_(SO,PASSSEC)
#           endif

#           ifdef SO_PEEK_OFF
            EDEF_(SO,PEEK_OFF)
#           endif

#           ifdef SO_PEERCRED
            EDEF_(SO,PEERCRED)
#           endif

#           ifdef SO_PEERSEC
            EDEF_(SO,PEERSEC)
#           endif

#           ifdef SO_PRIORITY
            EDEF_(SO,PRIORITY)
#           endif

#           ifdef SO_PROTOCOL
            EDEF_(SO,PROTOCOL)
#           endif

#           ifdef SO_RCVBUFFORCE
            EDEF_(SO,RCVBUFFORCE)
#           endif

#           ifdef SO_REUSEPORT
            EDEF_(SO,REUSEPORT)
#           endif

#           ifdef SO_RXQ_OVFL
            EDEF_(SO,RXQ_OVFL)
#           endif

#           ifdef SO_SELECT_ERR_QUEUE
            EDEF_(SO,SELECT_ERR_QUEUE)
#           endif

#           ifdef SO_SNDBUFFORCE
            EDEF_(SO,SNDBUFFORCE)
#           endif

#           ifdef SO_TIMESTAMP
            EDEF_(SO,TIMESTAMP)
#           endif

#           ifdef SO_TIMESTAMPNS
            EDEF_(SO,TIMESTAMPNS)
#           endif

        __preend("SO", .sort=C__VSORT)
        __predef("TCP")
#           ifdef TCP_NODELAY
            EDEF_(TCP,NODELAY)
#           endif
#           ifdef TCP_MAXSEG
            EDEF_(TCP,MAXSEG)
#           endif
#           ifdef TCP_CORK
            EDEF_(TCP,CORK)
#           endif
#           ifdef TCP_KEEPIDLE
            EDEF_(TCP,KEEPIDLE)
#           endif
#           ifdef TCP_KEEPINTVL
            EDEF_(TCP,KEEPINTVL)
#           endif
#           ifdef TCP_KEEPCNT
            EDEF_(TCP,KEEPCNT)
#           endif
#           ifdef TCP_SYNCNT
            EDEF_(TCP,SYNCNT)
#           endif
#           ifdef TCP_LINGER2
            EDEF_(TCP,LINGER2)
#           endif
#           ifdef TCP_DEFER_ACCEPT
            EDEF_(TCP,DEFER_ACCEPT)
#           endif
#           ifdef TCP_WINDOW_CLAMP
            EDEF_(TCP,WINDOW_CLAMP)
#           endif
#           ifdef TCP_INFO
            EDEF_(TCP,INFO)
#           endif
#           ifdef TCP_QUICKACK
            EDEF_(TCP,QUICKACK)
#           endif
#           ifdef TCP_CONGESTION
            EDEF_(TCP,CONGESTION)
#           endif
#           ifdef TCP_MD5SIG
            EDEF_(TCP,MD5SIG)
#           endif
#           ifdef TCP_THIN_LINEAR_TIMEOUTS
            EDEF_(TCP,THIN_LINEAR_TIMEOUTS)
#           endif
#           ifdef TCP_THIN_DUPACK
            EDEF_(TCP,THIN_DUPACK)
#           endif
#           ifdef TCP_USER_TIMEOUT
            EDEF_(TCP,USER_TIMEOUT)
#           endif
#           ifdef TCP_REPAIR
            EDEF_(TCP,REPAIR)
#           endif
#           ifdef TCP_REPAIR_QUEUE
            EDEF_(TCP,REPAIR_QUEUE)
#           endif
#           ifdef TCP_QUEUE_SEQ
            EDEF_(TCP,QUEUE_SEQ)
#           endif
#           ifdef TCP_REPAIR_OPTIONS
            EDEF_(TCP,REPAIR_OPTIONS)
#           endif
#           ifdef TCP_FASTOPEN
            EDEF_(TCP,FASTOPEN)
#           endif
#           ifdef TCP_TIMESTAMP
            EDEF_(TCP,TIMESTAMP)
#           endif
#           ifdef TCP_NOTSENT_LOWAT
            EDEF_(TCP,NOTSENT_LOWAT)
#           endif
#           ifdef TCP_CC_INFO
            EDEF_(TCP,CC_INFO)
#           endif
#           ifdef TCP_SAVE_SYN
            EDEF_(TCP,SAVE_SYN)
#           endif
#           ifdef TCP_SAVED_SYN
            EDEF_(TCP,SAVED_SYN)
#           endif
#           ifdef TCP_REPAIR_WINDOW
            EDEF_(TCP,REPAIR_WINDOW)
#           endif
#           ifdef TCP_FASTOPEN_CONNECT
            EDEF_(TCP,FASTOPEN_CONNECT)
#           endif
#           ifdef TCP_ULP
            EDEF_(TCP,ULP)
#           endif
#           ifdef TCP_MD5SIG_EXT
            EDEF_(TCP,MD5SIG_EXT)
#           endif
#           ifdef TCP_FASTOPEN_KEY
            EDEF_(TCP,FASTOPEN_KEY)
#           endif
#           ifdef TCP_FASTOPEN_NO_COOKIE
            EDEF_(TCP,FASTOPEN_NO_COOKIE)
#           endif
#           ifdef TCP_ZEROCOPY_RECEIVE
            EDEF_(TCP,ZEROCOPY_RECEIVE)
#           endif
#           ifdef TCP_INQ
            EDEF_(TCP,INQ)
#           endif
#           ifdef TCP_CM_INQ
            EDEF_(TCP,CM_INQ)
#           endif
#           ifdef TCP_TX_DELAY
            EDEF_(TCP,TX_DELAY)
#           endif
        __preend("TCP")
    __dexit(enums)

    __dentr(structs, Struct[])    

        __memdef(netent_s)
        __member(netent_s, n_name, "cp")
        __member(netent_s, n_aliases, "cpp")
        __member(netent_s, n_addrtype, "i32")
        __member(netent_s, n_net, "u32")
        __enddef(netent_s)
        
        __memdef(servent_s)
        __member(servent_s, s_name, "cp")
        __member(servent_s, s_aliases, "cpp")
        __member(servent_s, s_port, "i32")
        __member(servent_s, s_proto, "cp")
        __enddef(servent_s)
        
        __memdef(protoent_s)
        __member(protoent_s, p_name, "cp")
        __member(protoent_s, p_aliases, "cpp")
        __member(protoent_s, p_proto, "i32")
        __enddef(protoent_s)
        
        __memdef(addrinfo_s)
        __member(addrinfo_s, ai_flags,      "i32")
        __member(addrinfo_s, ai_family,     "i32")
        __member(addrinfo_s, ai_socktype,   "i32")
        __member(addrinfo_s, ai_protocol,   "i32")
        __member(addrinfo_s, ai_addrlen,    "socklen_t")
        __member(addrinfo_s, ai_canonname,  "cp")
        __member(addrinfo_s, ai_addr,       "addrinfo_p")
        __member(addrinfo_s, ai_next,       "addrinfo_p")
        __enddef(addrinfo_s)

#   ifdef MSG_ERRQUEUE
        __memdef(sock_extended_err_s)
        __member(sock_extended_err_s, ee_errno, "u32")
        __member(sock_extended_err_s, ee_origin,"u8")
        __member(sock_extended_err_s, ee_type,  "u8")
        __member(sock_extended_err_s, ee_code,  "u8")
        __member(sock_extended_err_s, ee_pad,   "u8")
        __member(sock_extended_err_s, ee_info,  "u32")
        __member(sock_extended_err_s, ee_data,  "u32")
        __enddef(sock_extended_err_s)
#   endif//MSG_ERRQUEUE

        __memdef(sockaddr_s)
        __member(sockaddr_s, sa_family, "sa_family_t")
        __member(sockaddr_s, sa_data,   "char#14")
        __enddef(sockaddr_s)

        __memdef(sockaddr_storage_s)
        __member(sockaddr_storage_s, ss_family, "sa_family_t")
        __enddef(sockaddr_storage_s)

        __memdef(msghdr_s)
        __member(msghdr_s, msg_name,      "buffer")
        __member(msghdr_s, msg_namelen,   "socklen_t")
        __member(msghdr_s, msg_iov,       "iovec_p")
        __member(msghdr_s, msg_iovlen,    "size_t")
        __member(msghdr_s, msg_control,   "buffer")
        __member(msghdr_s, msg_controllen,"size_t")
        __member(msghdr_s, msg_flags,     "i32")
        __enddef(msghdr_s)

        __memdef(cmsghdr_s)
        __member(cmsghdr_s, cmsg_len, "size_t")
        __member(cmsghdr_s, cmsg_level, "i32")
        __member(cmsghdr_s, cmsg_type, "i32")
        __enddef(cmsghdr_s)

        __memdef(ucred_s)
        __member(ucred_s, pid, "pid_t")
        __member(ucred_s, uid, "uid_t")
        __member(ucred_s, gid, "gid_t")
        __enddef(ucred_s)

        __memdef(linger_s)
        __member(linger_s, l_onoff, "i32")
        __member(linger_s, l_linger, "i32")
        __enddef(linger_s)

        __memdef(ifmap_s)
        __member(ifmap_s, mem_start,"long_t")
        __member(ifmap_s, mem_end,  "long_t")
        __member(ifmap_s, base_addr,"short_t")
        __member(ifmap_s, irq,      "char")
        __member(ifmap_s, dma,      "char")
        __member(ifmap_s, port,     "char")
        __enddef(ifmap_s)
        
        __memdef(ifreq_s)
        __member(ifreq_s, ifr_name,     "ifreq_name_t")
        __member(ifreq_s, ifr_addr,     "sockaddr_s")
        __member(ifreq_s, ifr_dstaddr,  "sockaddr_s")
        __member(ifreq_s, ifr_broadaddr,"sockaddr_s")
        __member(ifreq_s, ifr_netmask,  "sockaddr_s")
        __member(ifreq_s, ifr_hwaddr,   "sockaddr_s")
        __member(ifreq_s, ifr_flags,    "short_t")
        __member(ifreq_s, ifr_ifindex,  "i32")
        __member(ifreq_s, ifr_metric,   "i32")
        __member(ifreq_s, ifr_mtu,      "i32")
        __member(ifreq_s, ifr_map,      "ifmap_s")
        __member(ifreq_s, ifr_slave,    "ifreq_name_t")
        __member(ifreq_s, ifr_data,     "cp")
        __enddef(ifreq_s)

        __memdef(sockaddr_un_s)
        __member(sockaddr_un_s, sun_family, "sa_family_t")
        __member(sockaddr_un_s, sun_path,   "char#1")
        __enddef(sockaddr_un_s)

        __memdef(in_addr_s)
        __member(in_addr_s, s_addr, "in_addr_t")
        __enddef(in_addr_s)

        __memdef(ip_mreqn_s)
        __member(ip_mreqn_s, imr_multiaddr, "in_addr_s")
        __member(ip_mreqn_s, imr_address,   "in_addr_s")
        __member(ip_mreqn_s, imr_ifindex,   "i32")
        __enddef(ip_mreqn_s)

        __memdef(ip_mreq_source_s)
        __member(ip_mreq_source_s, imr_multiaddr, "in_addr_s")
        __member(ip_mreq_source_s, imr_interface, "in_addr_s")
        __member(ip_mreq_source_s, imr_sourceaddr, "in_addr_s")
        __enddef(ip_mreq_source_s)
  
        __memdef(ip_msfilter_s)
        __member(ip_msfilter_s, imsf_multiaddr, "in_addr_s")
        __member(ip_msfilter_s, imsf_interface, "in_addr_s")
        __member(ip_msfilter_s, imsf_fmode,     "u32")
        __member(ip_msfilter_s, imsf_numsrc,    "u32")
        __member(ip_msfilter_s, imsf_slist,     "in_addr_s#1")
        __enddef(ip_msfilter_s)

#       if _POSIX_IPV6 > 0

        __memdef(in6_addr_s)
        __member(in6_addr_s, s6_addr, "in_addr_t")
        __enddef(in6_addr_s)

        __memdef(in6_ifreq_s)
        __member(in6_ifreq_s, ifr6_addr, "in6_addr_s")
        __member(in6_ifreq_s, ifr6_prefixlen, "u32")
        __member(in6_ifreq_s, ifr6_ifindex, "i32")
        __enddef(in6_ifreq_s)

        __memdef(ipv6_mreq_s)
        __member(ipv6_mreq_s, ipv6mr_multiaddr, "in6_addr_s")
        __member(ipv6_mreq_s, ipv6mr_ifindex, "i32")
        __enddef(ipv6_mreq_s)
#       endif // _POSIX_IPV6 > 0

#       if _POSIX_RAW_SOCKETS > 0
        __memdef(sockaddr_ll_s)
        __member(sockaddr_ll_s, sll_family,  "ushrt_t")
        __member(sockaddr_ll_s, sll_protocol,"ushrt_t")
        __member(sockaddr_ll_s, sll_ifindex, "i32")
        __member(sockaddr_ll_s, sll_hatype,  "ushrt_t")
        __member(sockaddr_ll_s, sll_pkttype, "uchar_t")
        __member(sockaddr_ll_s, sll_halen,   "uchar_t")
        __member(sockaddr_ll_s, sll_addr,    "uchar_t#8")
        __enddef(sockaddr_ll_s)

        __memdef(in_pktinfo_s)
        __member(in_pktinfo_s, ipi_ifindex, "unsigned_t")
        __member(in_pktinfo_s, ipi_spec_dst,"in_addr")
        __member(in_pktinfo_s, ipi_addr,    "in_addr")
        __enddef(in_pktinfo_s)

        __memdef(packet_mreq_s)
        __member(packet_mreq_s, mr_ifindex, "i32")
        __member(packet_mreq_s, mr_type,    "ushrt_t")
        __member(packet_mreq_s, mr_alen,    "ushrt_r")
        __member(packet_mreq_s, mr_address, "uchar_t#8")
        __enddef(packet_mreq_s)

        __memdef(tpacket_auxdata_s)
        __member(tpacket_auxdata_s, tp_status,  "u32")
        __member(tpacket_auxdata_s, tp_len,     "u32")
        __member(tpacket_auxdata_s, tp_snaplen, "u32")
        __member(tpacket_auxdata_s, tp_mac,     "u16")
        __member(tpacket_auxdata_s, tp_net,     "u16")
        __member(tpacket_auxdata_s, tp_vlan_tci,"u16")
        __member(tpacket_auxdata_s, tp_vlan_tpid,"u16")
        __enddef(tpacket_auxdata_s)
#       endif // _POSIX_RAW_SOCKETS > 0
    __dexit(structs)
    
    __baseret(sys_socket_h)
}