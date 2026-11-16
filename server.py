#=================================#
# [ OWNER ]
#     CREATOR  : Vladislav Khudash
#     AGE      : 18
#     LOCATION : Ukraine
#
# [ PINFO ]
#     DATE     : 16.11.2026
#     PROJECT  : LINUX-RAT (SERVER)
#     PLATFORM : LINUX, WIN32
#=================================#




import sys    as libSys
import os     as libOs
import socket as libSock


LR_SERVER_IPV4 = b"127.0.0.1"
LR_SERVER_PORT = 12701
LR_SERVER_ID   = b"vkLR-SrS"

SOCK_ENCODING = b"ASCII"
SOCK_TIMEOUT  = 60




def start_server():
    with libSock.socket(
        family = libSock.AF_INET,
        type   = libSock.SOCK_STREAM,
        proto  = libSock.IPPROTO_TCP
    ) as sock:
        sock.setsockopt(libSock.SOL_SOCKET, libSock.SO_REUSEADDR, 1)
        sock.bind((LR_SERVER_IPV4, LR_SERVER_PORT))
        sock.listen()

        conn, addr = sock.accept()

        with conn:
            conn.sendall()



def main():
    start_server()




if (__name__ == '__main__'): main()
