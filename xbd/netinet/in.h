#pragma once

int in6_are_addr_equal(in6_addr_cp a, in6_addr_cp b)  {
    return !memcmp(a->s6_addr, b->s6_addr, sizeof(struct in6_addr));
}

int in6_is_addr_unspecified(in6_addr_cp a) {
    return !(
        a->s6_addr32[0]
    ||  a->s6_addr32[1]
    ||  a->s6_addr32[2]
    ||  a->s6_addr32[3]);
}

int in6_is_addr_loopback(in6_addr_cp a) {
    return !(
        (a->s6_addr32[0])
    ||  (a->s6_addr32[1])
    ||  (a->s6_addr32[2])
    ||  (a->s6_addr32[3]) == ntohl(1));
}

int in6_is_addr_v4mapped(in6_addr_cp a) {
    return !(
        (a->s6_addr32[0])
    ||  (a->s6_addr32[1])
    ||  (a->s6_addr32[2] == ntohl(0x0000ffff)));
}

int in6_is_addr_v4compat(in6_addr_cp a) {
    return IN6_IS_ADDR_V4COMPAT(a);
}

int in6_is_addr_linklocal(in6_addr_cp a) {
    return IN6_IS_ADDR_LINKLOCAL(a);
}

int in6_is_addr_sitelocal(in6_addr_cp a) {
    return IN6_IS_ADDR_SITELOCAL(a);
}

int in6_is_addr_multicast(in6_addr_cp a) {
    return IN6_IS_ADDR_MULTICAST(a);
}

int in6_is_addr_mc_nodelocal(in6_addr_cp a) {
    return IN6_IS_ADDR_MC_NODELOCAL(a);
}

int in6_is_addr_mc_linklocal(in6_addr_cp a) {
    return IN6_IS_ADDR_MC_LINKLOCAL(a);
}

int in6_is_addr_mc_sitelocal(in6_addr_cp a) {
    return IN6_IS_ADDR_MC_SITELOCAL(a);
}

int in6_is_addr_mc_global(in6_addr_cp a) {
    return IN6_IS_ADDR_MC_GLOBAL(a);
}

int in6_is_addr_mc_orglocal(in6_addr_cp a) {
    return IN6_IS_ADDR_MC_ORGLOCAL(a);
}

int include_netinet_in_h(Lib *self, FILE *file) {

    __basedef(netinet_in_h, "<netinet/in.h>")

    __dentr(enums, Enum[])
        __predef("")
            EREF(INET_ADDRSTRLEN)
        __preend("")
        __predef("")
            EREF(INET6_ADDRSTRLEN)
        __preend("")
        __predef("IPPROTO")
            EDEF_(IPPROTO,IP)
            EDEF_(IPPROTO,ICMP)
            EDEF_(IPPROTO,TCP)
            EDEF_(IPPROTO,UDP)
#       if (_POSIX_IPV6 > 0)
            EDEF_(IPPROTO,IPV6)
#       endif

#       if (_POSIX_RAW_SOCKETS > 0)
            EDEF_(IPPROTO,RAW)
#       endif
        __preend("IPPROTO")

#       if (_POSIX_IPV6 > 0)
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

    __dexit(enums)

    __dentr(structs, Struct[])

        __memdef(in_addr_s)
        __member(in_addr_s, s_addr, "{in_addr_t}")
        __enddef(in_addr_s)

        __memdef(sockaddr_in_s)
        __member(sockaddr_in_s, sin_family, "{sa_family_t}")
        __member(sockaddr_in_s, sin_port, "{uint16_t:>}")
        __member(sockaddr_in_s, sin_addr, "{in_addr_s:>}")
        __enddef(sockaddr_in_s)

#       if _POSIX_IPV6 > 0

        __memdef(in6_addr_s)
        __member(in6_addr_s, s6_addr, "{in_addr_t:>}")
        __enddef(in6_addr_s)

        __memdef(sockaddr_in6_s)
        __member(sockaddr_in6_s, sin6_family, "{sa_family_t}")
        __member(sockaddr_in6_s, sin6_port, "{uint16_t:>}")
        __member(sockaddr_in6_s, sin6_flowinfo, "{uint32_t:>}")
        __member(sockaddr_in6_s, sin6_addr, "{in6_addr_s:>}")
        __member(sockaddr_in6_s, sin6_scope_id, "{uint32_t:>}")
        __enddef(sockaddr_in6_s)

        __memdef(ipv6_mreq_s)
        __member(ipv6_mreq_s, ipv6mr_multiaddr, "{in6_addr_s}")
        __member(ipv6_mreq_s, ipv6mr_interface, "{unsigned}")
        __enddef(ipv6_mreq_s)
#       endif

    __dexit(structs)
    __baseret(netinet_in_h)
}

int test_netinet_in_h(Lib *self, FILE *file) {
#   ifndef BLTN_IN6_IS_ADDR_UNSPECIFIED
#   define BLTN_IN6_IS_ADDR_UNSPECIFIED in6_is_addr_unspecified
#   endif
#   ifndef BLTN_IN6_IS_ADDR_LOOPBACK
#   define BLTN_IN6_IS_ADDR_LOOPBACK in6_is_addr_loopback
#   endif
#   ifndef BLTN_IN6_IS_ADDR_V4MAPPED
#   define BLTN_IN6_IS_ADDR_V4MAPPED in6_is_addr_v4mapped
#   endif
#   ifndef BLTN_IN6_IS_ADDR_V4COMPAT
#   define BLTN_IN6_IS_ADDR_V4COMPAT in6_is_addr_v4compat
#   endif
#   ifndef BLTN_IN6_IS_ADDR_LINKLOCAL
#   define BLTN_IN6_IS_ADDR_LINKLOCAL in6_is_addr_linklocal
#   endif
#   ifndef BLTN_IN6_IS_ADDR_SITELOCAL
#   define BLTN_IN6_IS_ADDR_SITELOCAL in6_is_addr_sitelocal
#   endif
#   ifndef BLTN_IN6_IS_ADDR_MULTICAST
#   define BLTN_IN6_IS_ADDR_MULTICAST in6_is_addr_multicast
#   endif
#   ifndef BLTN_IN6_IS_ADDR_MC_LINKLOCAL
#   define BLTN_IN6_IS_ADDR_MC_LINKLOCAL in6_is_addr_mc_linklocal
#   endif
#   ifndef BLTN_IN6_IS_ADDR_MC_NODELOCAL
#   define BLTN_IN6_IS_ADDR_MC_NODELOCAL in6_is_addr_mc_nodelocal
#   endif
#   ifndef BLTN_IN6_IS_ADDR_MC_SITELOCAL
#   define BLTN_IN6_IS_ADDR_MC_SITELOCAL in6_is_addr_mc_sitelocal
#   endif
#   ifndef BLTN_IN6_IS_ADDR_MC_ORGLOCAL
#   define BLTN_IN6_IS_ADDR_MC_ORGLOCAL in6_is_addr_mc_orglocal
#   endif
#   ifndef BLTN_IN6_IS_ADDR_MC_GLOBAL
#   define BLTN_IN6_IS_ADDR_MC_GLOBAL in6_is_addr_mc_global
#   endif
    self->IN6_IS_ADDR.UNSPECIFIED   = BLTN_IN6_IS_ADDR_UNSPECIFIED;
    self->IN6_IS_ADDR.LOOPBACK      = BLTN_IN6_IS_ADDR_LOOPBACK;
    self->IN6_IS_ADDR.MULTICAST     = BLTN_IN6_IS_ADDR_MULTICAST;
    self->IN6_IS_ADDR.LINKLOCAL     = BLTN_IN6_IS_ADDR_LINKLOCAL;
    self->IN6_IS_ADDR.SITELOCAL     = BLTN_IN6_IS_ADDR_SITELOCAL;
    self->IN6_IS_ADDR.V4MAPPED      = BLTN_IN6_IS_ADDR_V4MAPPED;
    self->IN6_IS_ADDR.V4COMPAT      = BLTN_IN6_IS_ADDR_V4COMPAT;
    self->IN6_IS_ADDR.MC_NODELOCAL  = BLTN_IN6_IS_ADDR_MC_NODELOCAL;
    self->IN6_IS_ADDR.MC_LINKLOCAL  = BLTN_IN6_IS_ADDR_MC_LINKLOCAL;
    self->IN6_IS_ADDR.MC_SITELOCAL  = BLTN_IN6_IS_ADDR_MC_SITELOCAL;
    self->IN6_IS_ADDR.MC_GLOBAL     = BLTN_IN6_IS_ADDR_MC_GLOBAL;
    self->IN6_IS_ADDR.MC_ORGLOCAL   = BLTN_IN6_IS_ADDR_MC_ORGLOCAL; 
    return 0;
}
