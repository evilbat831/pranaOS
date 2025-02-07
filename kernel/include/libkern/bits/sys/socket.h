#pragma once

enum SOCK_DOMAINS {
    PF_LOCAL,
    PF_INET,
    PF_INET6,
    PF_IPX,
    PF_NETLINK,
    PF_X25,
    PF_AX25,
    PF_ATMPVC,
    PF_APPLETALK,
    PF_PACKET,
};

enum SOCK_TYPES {
    SOCK_STREAM,
    SOCK_DGRAM,
    SOCK_SEQPACKET,
    SOCK_RAW,
    SOCK_RDM,
    SOCK_PACKET,
};