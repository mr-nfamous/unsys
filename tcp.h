#pragma once

int include_netinet_tcp_h(Lib *self, FILE *file) {

    __basedef(netinet_tcp_h, "<netinet_tcp.h>")

    __dentr(enums, Enum[])

        __predef("TCP")
            EDEF_(TCP,CORK)
#           ifdef TCP_MSS_DEFAULT
            EDEF_(TCP,MSS_DEFAULT)
#           endif
#           ifdef TCP_MSS_DESIRED
            EDEF_(TCP,MSS_DESIRED)
#           endif
#           ifdef TCP_NODELAY
            EDEF_(TCP,NODELAY)
#           endif
#           ifdef TCP_MAXSEG
            EDEF_(TCP,MAXSEG)
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

        __predef("TCPI")
#           ifdef TCPI_OPT_TIMESTAMPS
            EDEF_(TCPI,OPT_TIMESTAMPS)
#           endif
#           ifdef TCPI_OPT_SACK
            EDEF_(TCPI,OPT_SACK)
#           endif
#           ifdef TCPI_OPT_WSCALE
            EDEF_(TCPI,OPT_WSCALE)
#           endif
#           ifdef TCPI_OPT_ECN
            EDEF_(TCPI,OPT_ECN)
#           endif
#           ifdef TCPI_OPT_ECN_SEEN
            EDEF_(TCPI,OPT_ECN_SEEN)
#           endif
#           ifdef TCPI_OPT_SYN_DATA
            EDEF_(TCPI,OPT_SYN_DATA)
#           endif
        __preend("TCPI", .fmt="x")

        __predef("TCP")
#           ifdef TCP_FLAG_CWR
            EDEF_(TCP,FLAG_CWR)
#           endif
#           ifdef TCP_FLAG_ECE
            EDEF_(TCP,FLAG_ECE)
#           endif
#           ifdef TCP_FLAG_URG
            EDEF_(TCP,FLAG_URG)
#           endif
#           ifdef TCP_FLAG_ACK
            EDEF_(TCP,FLAG_ACK)
#           endif
#           ifdef TCP_FLAG_PSH
            EDEF_(TCP,FLAG_PSH)
#           endif
#           ifdef TCP_FLAG_RST
            EDEF_(TCP,FLAG_RST)
#           endif
#           ifdef TCP_FLAG_SYN
            EDEF_(TCP,FLAG_SYN)
#           endif
#           ifdef TCP_FLAG_FIN
            EDEF_(TCP,FLAG_FIN)
#           endif
#           ifdef TCP_RESERVED_BITS
            EDEF_(TCP,RESERVED_BITS)
#           endif
#           ifdef TCP_DATA_OFFSET
            EDEF_(TCP,DATA_OFFSET)
#           endif
        __preend("TCP", .fmt="x")

        __predef("TCP")
#           ifdef TCP_REPAIR_ON
            EDEF_(TCP,REPAIR_ON)
#           endif
#           ifdef TCP_REPAIR_OFF
            EDEF_(TCP,REPAIR_OFF)
#           endif
#           ifdef TCP_REPAIR_OFF_NO_WP
            EDEF_(TCP,REPAIR_OFF_NO_WP)
#           endif
#           ifdef TCP_NO_QUEUE
            EDEF_(TCP,NO_QUEUE)
#           endif
#           ifdef TCP_RECV_QUEUE
            EDEF_(TCP,RECV_QUEUE)
#           endif
#           ifdef TCP_SEND_QUEUE
            EDEF_(TCP,SEND_QUEUE)
#           endif
#           ifdef TCP_QUEUES_NR
            EDEF_(TCP,QUEUES_NR)
#           endif
        __preend("TCP")

        __predef("TCPF")
#           ifdef TCPF_CA_Disorder
            EDEF_(TCPF,CA_Disorder)
#           endif
#           ifdef TCPF_CA_CWR
            EDEF_(TCPF,CA_CWR)
#           endif
#           ifdef TCPF_CA_Recovery
            EDEF_(TCPF,CA_Recovery)
#           endif
#           ifdef TCPF_CA_Loss
            EDEF_(TCPF,CA_Loss)
#           endif
#           ifdef TCPF_CA_Open
            EDEF_(TCPF,CA_Open)
#           endif
        __preend("TCPF")
        __predef("TCP")
#           ifdef TCP_CA_Open
            EDEF_(TCP,CA_Open)
#           endif
#           ifdef TCP_CA_Disorder
            EDEF_(TCP,CA_Disorder)
#           endif
#           ifdef TCP_CA_CWR
            EDEF_(TCP,CA_CWR)
#           endif
#           ifdef TCP_CA_Recovery
            EDEF_(TCP,CA_Recovery)
#           endif
#           ifdef TCP_CA_Loss
            EDEF_(TCP,CA_Loss)
#           endif
        __preend("TCP")

        __predef("TCP")
#           ifdef TCP_NLA_PAD
            EDEF_(TCP,NLA_PAD)
#           endif
#           ifdef TCP_NLA_BUSY
            EDEF_(TCP,NLA_BUSY)
#           endif
#           ifdef TCP_NLA_RWND_LIMITED
            EDEF_(TCP,NLA_RWND_LIMITED)
#           endif
#           ifdef TCP_NLA_SNDBUF_LIMITED
            EDEF_(TCP,NLA_SNDBUF_LIMITED)
#           endif
#           ifdef TCP_NLA_DATA_SEGS_OUT
            EDEF_(TCP,NLA_DATA_SEGS_OUT)
#           endif
#           ifdef TCP_NLA_TOTAL_RETRANS
            EDEF_(TCP,NLA_TOTAL_RETRANS)
#           endif
#           ifdef TCP_NLA_PACING_RATE
            EDEF_(TCP,NLA_PACING_RATE)
#           endif
#           ifdef TCP_NLA_DELIVERY_RATE
            EDEF_(TCP,NLA_DELIVERY_RATE)
#           endif
#           ifdef TCP_NLA_SND_CWND
            EDEF_(TCP,NLA_SND_CWND)
#           endif
#           ifdef TCP_NLA_REORDERING
            EDEF_(TCP,NLA_REORDERING)
#           endif
#           ifdef TCP_NLA_MIN_RTT
            EDEF_(TCP,NLA_MIN_RTT)
#           endif
#           ifdef TCP_NLA_RECUR_RETRANS
            EDEF_(TCP,NLA_RECUR_RETRANS)
#           endif
#           ifdef TCP_NLA_DELIVERY_RATE_APP_LMT
            EDEF_(TCP,NLA_DELIVERY_RATE_APP_LMT)
#           endif
#           ifdef TCP_NLA_SNDQ_SIZE
            EDEF_(TCP,NLA_SNDQ_SIZE)
#           endif
#           ifdef TCP_NLA_CA_STATE
            EDEF_(TCP,NLA_CA_STATE)
#           endif
#           ifdef TCP_NLA_SND_SSTHRESH
            EDEF_(TCP,NLA_SND_SSTHRESH)
#           endif
#           ifdef TCP_NLA_DELIVERED
            EDEF_(TCP,NLA_DELIVERED)
#           endif
#           ifdef TCP_NLA_DELIVERED_CE
            EDEF_(TCP,NLA_DELIVERED_CE)
#           endif
#           ifdef TCP_NLA_BYTES_SENT
            EDEF_(TCP,NLA_BYTES_SENT)
#           endif
#           ifdef TCP_NLA_BYTES_RETRANS
            EDEF_(TCP,NLA_BYTES_RETRANS)
#           endif
#           ifdef TCP_NLA_DSACK_DUPS
            EDEF_(TCP,NLA_DSACK_DUPS)
#           endif
#           ifdef TCP_NLA_REORD_SEEN
            EDEF_(TCP,NLA_REORD_SEEN)
#           endif
#           ifdef TCP_NLA_SRTT
            EDEF_(TCP,NLA_SRTT)
#           endif
        __preend("TCP")

        __predef("TCP")
#           ifdef TCP_MD5SIG_MAXKEYLEN
            EDEF_(TCP,MD5SIG_MAXKEYLEN)
#           endif
#           ifdef TCP_MD5SIG_FLAG_PREFIX
            EDEF_(TCP,MD5SIG_FLAG_PREFIX)
#           endif
        __preend("TCP")
  
        __predef("TH")
#           ifdef TH_FIN
            EDEF_(TH,FIN)
#           endif
#           ifdef TH_SYN
            EDEF_(TH,SYN)
#           endif
#           ifdef TH_RST
            EDEF_(TH,RST)
#           endif
#           ifdef TH_PUSH
            EDEF_(TH,PUSH)
#           endif
#           ifdef TH_ACK
            EDEF_(TH,ACK)
#           endif
#           ifdef TH_URG
            EDEF_(TH,URG)
#           endif
        __preend("TH")

        __predef("TCP")
#           ifdef TCP_ESTABLISHED
            EDEF_(TCP,ESTABLISHED)
#           endif
#           ifdef TCP_SYN_SENT
            EDEF_(TCP,SYN_SENT)
#           endif
#           ifdef TCP_SYN_RECV
            EDEF_(TCP,SYN_RECV)
#           endif
#           ifdef TCP_FIN_WAIT1
            EDEF_(TCP,FIN_WAIT1)
#           endif
#           ifdef TCP_FIN_WAIT2
            EDEF_(TCP,FIN_WAIT2)
#           endif
#           ifdef TCP_TIME_WAIT
            EDEF_(TCP,TIME_WAIT)
#           endif
#           ifdef TCP_CLOSE
            EDEF_(TCP,CLOSE)
#           endif
#           ifdef TCP_CLOSE_WAIT
            EDEF_(TCP,CLOSE_WAIT)
#           endif
#           ifdef TCP_LAST_ACK
            EDEF_(TCP,LAST_ACK)
#           endif
#           ifdef TCP_LISTEN
            EDEF_(TCP,LISTEN)
#           endif
#           ifdef TCP_CLOSING
            EDEF_(TCP,CLOSING)
#           endif
        __preend("TCP")

        __predef("TCPOPT")
#           ifdef TCPOPT_EOL
            EDEF_(TCPOPT,EOL)
#           endif
#           ifdef TCPOPT_NOP
            EDEF_(TCPOPT,NOP)
#           endif
#           ifdef TCPOPT_MAXSEG
            EDEF_(TCPOPT,MAXSEG)
#           endif
#           ifdef TCPOPT_WINDOW
            EDEF_(TCPOPT,WINDOW)
#           endif
#           ifdef TCPOPT_SACK_PERMITTED
            EDEF_(TCPOPT,SACK_PERMITTED)
#           endif
#           ifdef TCPOPT_SACK
            EDEF_(TCPOPT,SACK)
#           endif
#           ifdef TCPOPT_TIMESTAMP
            EDEF_(TCPOPT,TIMESTAMP)
#           endif
#           ifdef TCPOPT_TSTAMP_HDR
            EDEF_(TCPOPT,TSTAMP_HDR)
#           endif
        __preend("TCPOPT")
        __predef("TCPOLEN")
#           ifdef TCPOLEN_MAXSEG
            EDEF_(TCPOLEN,MAXSEG)
#           endif
#           ifdef TCPOLEN_WINDOW
            EDEF_(TCPOLEN,WINDOW)
#           endif
#           ifdef TCPOLEN_SACK_PERMITTED
            EDEF_(TCPOLEN,SACK_PERMITTED)
#           endif
#           ifdef TCPOLEN_TIMESTAMP
            EDEF_(TCPOLEN,TIMESTAMP)
#           endif
#           ifdef TCPOLEN_TSTAMP_APPA
            EDEF_(TCPOLEN,TSTAMP_APPA)
#           endif
        __preend("TCPOLEN")
  
    __dexit(enums)

    __dentr(structs, Struct[])
    
#   ifdef BLTN_NETINET_TCP_ZEROCOPY_RECV
/*    struct tcp_zerocopy_receive {
        __u64 address;
        __u32 length;
        __u32 recv_skip_hint;
    }; */
        __memdef(tcp_zerocopy_receive_s)
        __member(tcp_zerocopy_receive_s, address, "uint64_t")
        __member(tcp_zerocopy_receive_s, length,    "uint32_t")
        __member(tcp_zerocopy_receive_s, recv_skip_hint, "uint32_t")
        __enddef(tcp_zerocopy_receive_s)
#   endif    

    __dexit(structs)
    __baseret(netinet_tcp_h)
}

int test_netinet_tcp_h(Lib *self, FILE *file) {
    return 0;
}