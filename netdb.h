#pragma once

int include_netdb_h(Lib *self, FILE *file) {

    __basedef(netdb_h, "<netdb.h>")

    __dentr(enums, Enum[])

        __predef("IPPORT")
            EDEF_(IPPORT,RESERVED)
        __preend("IPPORT")

        __predef("AI")
            EDEF_(AI,PASSIVE) 
            EDEF_(AI,CANONNAME)
            EDEF_(AI,NUMERICHOST)
            EDEF_(AI,NUMERICSERV)
            EDEF_(AI,V4MAPPED)
            EDEF_(AI,ALL)
            EDEF_(AI,ADDRCONFIG)
        __preend("AI", .fmt="x")

        __predef("NI")
            EDEF_(NI,NOFQDN)
            EDEF_(NI,NUMERICHOST)
            EDEF_(NI,NAMEREQD)
            EDEF_(NI,NUMERICSERV)
            EDEF_(NI,NUMERICSCOPE)
            EDEF_(NI,DGRAM)
        __preend("NI")

        __predef("EAI")
            EDEF_(EAI,AGAIN)
            EDEF_(EAI,BADFLAGS)
            EDEF_(EAI,FAIL)
            EDEF_(EAI,FAMILY)
            EDEF_(EAI,MEMORY)
            EDEF_(EAI,NONAME)
            EDEF_(EAI,SERVICE)
            EDEF_(EAI,SOCKTYPE)
            EDEF_(EAI,SYSTEM)
            EDEF_(EAI,OVERFLOW)
        __preend("EAI")
    __dexit(enums)

    __dentr(structs, Struct[])
       
        __memdef(hostent_s)
        __member(hostent_s, h_name, "{char_p}")
        __member(hostent_s, h_aliases, "{char_pp}")
        __member(hostent_s, h_addrtype, "{int}")
        __member(hostent_s, h_length, "{int}")
        __member(hostent_s, h_addr_list, "{char_pp}")
        __enddef(hostent_s)
        
        __memdef(netent_s)
        __member(netent_s, n_name, "chars")
        __member(netent_s, n_aliases, "char_pp")
        __member(netent_s, n_addrtype, "int")
        __member(netent_s, n_net, "uint32")
        __enddef(netent_s)
        
        __memdef(servent_s)
        __member(servent_s, s_name, "chars")
        __member(servent_s, s_aliases, "char_pp")
        __member(servent_s, s_port, "int")
        __member(servent_s, s_proto, "chars")
        __enddef(servent_s)
        
        __memdef(protoent_s)
        __member(protoent_s, p_name, "chars")
        __member(protoent_s, p_aliases, "char_pp")
        __member(protoent_s, p_proto, "int")
        __enddef(protoent_s)
        
        __memdef(addrinfo_s)
        __member(addrinfo_s, ai_flags, "{int}")
        __member(addrinfo_s, ai_family, "{int}")
        __member(addrinfo_s, ai_socktype, "{int}")
        __member(addrinfo_s, ai_protocol, "{int}")
        __member(addrinfo_s, ai_addrlen, "{socklen_t}")
        __member(addrinfo_s, ai_canonname, "{chars}")
        __member(addrinfo_s, ai_addr, "{addrinfo_p}")
        __member(addrinfo_s, ai_next, "{addrinfo_p}")
        __enddef(addrinfo_s)

        __memdef(if_nameindex_s)
        __member(if_nameindex_s, if_index, "unsigned")
        __member(if_nameindex_s, if_name, "chars")
        __enddef(if_nameindex_s)

    __dexit(structs)
    __baseret(netdb_h)
}

int test_netdb_h(Lib *self, FILE *file) {

#   ifndef BLTN_GAI_STRERROR
#   define BLTN_GAI_STRERROR gai_strerror
#   endif

#   ifndef BLTN_GETADDRINFO
#   define BLTN_GETADDRINFO getaddrinfo
#   endif

#   ifndef BLTN_GETHOSTENT
#   define BLTN_GETHOSTENT gethostent
#   endif

#   ifndef BLTN_GETNETBYADDR
#   define BLTN_GETNETBYADDR getnetbyaddr
#   endif

#   ifndef BLTN_GETNETBYNAME
#   define BLTN_GETNETBYNAME getnetbyname
#   endif

#   ifndef BLTN_GETNETENT
#   define BLTN_GETNETENT getnetent
#   endif

#   ifndef BLTN_GETPROTOBYNAME
#   define BLTN_GETPROTOBYNAME getprotobyname
#   endif

#   ifndef BLTN_GETPROTOBYNUMBER
#   define BLTN_GETPROTOBYNUMBER getprotobynumber
#   endif

#   ifndef BLTN_GETPROTOENT
#   define BLTN_GETPROTOENT getprotoent
#   endif

#   ifndef BLTN_GETSERVBYNAME
#   define BLTN_GETSERVBYNAME getservbyname
#   endif

#   ifndef BLTN_GETSERVBYPORT
#   define BLTN_GETSERVBYPORT getservbyport
#   endif

#   ifndef BLTN_GETSERVENT
#   define BLTN_GETSERVENT getservent
#   endif

#   ifndef BLTN_ENDHOSTENT
#   define BLTN_ENDHOSTENT endhostent
#   endif

#   ifndef BLTN_ENDNETENT
#   define BLTN_ENDNETENT endnetent
#   endif

#   ifndef BLTN_ENDPROTOENT
#   define BLTN_ENDPROTOENT endprotoent
#   endif

#   ifndef BLTN_ENDSERVENT
#   define BLTN_ENDSERVENT endservent
#   endif

#   ifndef BLTN_FREEADDRINFO
#   define BLTN_FREEADDRINFO freeaddrinfo
#   endif

#   ifndef BLTN_SETHOSTENT
#   define BLTN_SETHOSTENT sethostent
#   endif

#   ifndef BLTN_SETNETENT
#   define BLTN_SETNETENT setnetent
#   endif

#   ifndef BLTN_SETPROTOENT
#   define BLTN_SETPROTOENT setprotoent
#   endif

#   ifndef BLTN_SETSERVENT
#   define BLTN_SETSERVENT setservent
#   endif
    
    self->gai_strerror      = BLTN_GAI_STRERROR;
    self->getaddrinfo       = BLTN_GETADDRINFO;
    self->gethostent        = BLTN_GETHOSTENT;
    self->getnetbyaddr      = BLTN_GETNETBYADDR;
    self->getnetbyname      = BLTN_GETNETBYNAME;
    self->getnetent         = BLTN_GETNETENT;
    self->getprotobyname    = BLTN_GETPROTOBYNAME;
    self->getprotobynumber  = BLTN_GETPROTOBYNUMBER;
    self->getprotoent       = BLTN_GETPROTOENT;
    self->getservbyname     = BLTN_GETSERVBYNAME;
    self->getservbyport     = BLTN_GETSERVBYPORT;
    self->getservent        = BLTN_GETSERVENT;
    self->endhostent        = BLTN_ENDHOSTENT;
    self->endnetent         = BLTN_ENDNETENT;
    self->endprotoent       = BLTN_ENDPROTOENT;
    self->endservent        = BLTN_ENDSERVENT;
    self->freeaddrinfo      = BLTN_FREEADDRINFO;
    self->sethostent        = BLTN_SETHOSTENT;
    self->setnetent         = BLTN_SETNETENT;
    self->setprotoent       = BLTN_SETPROTOENT;
    self->setservent        = BLTN_SETSERVENT;

    return 0;
}