#pragma once
int include_arpa_inet_h(Lib *self, FILE *file) {
#   ifndef BLTN_HTONL
#   define BLTN_HTONL htonl
#   endif
#   ifndef BLTN_NTOHL
#   define BLTN_NTOHL ntohl
#   endif
#   ifndef BLTN_HTONS
#   define BLTN_HTONS htons
#   endif
#   ifndef BLTN_NTOHS
#   define BLTN_NTOHS ntohs
#   endif
#   ifndef BLTN_INET_ADDR
#   define BLTN_INET_ADDR inet_addr
#   endif
#   ifndef BLTN_INET_NTOA
#   define BLTN_INET_NTOA inet_ntoa
#   endif
#   ifndef BLTN_INET_NTOP
#   define BLTN_INET_NTOP inet_ntop
#   endif
#   ifndef BLTN_INET_PTON
#   define BLTN_INET_PTON inet_pton
#   endif
    self->htonl = BLTN_HTONL;
    self->ntohl = BLTN_NTOHL;
    self->htons = BLTN_HTONS;
    self->ntohs = BLTN_NTOHS;
    self->inet.addr = BLTN_INET_ADDR;
    self->inet.ntoa = BLTN_INET_NTOA;
    self->inet.ntop = BLTN_INET_NTOP;
    self->inet.pton = BLTN_INET_PTON;
    return 0;
}
