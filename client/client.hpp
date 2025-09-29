#pragma once
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include "../common/protocol.hpp"

namespace Net
{
    class Client
    {
        private:
            int sock;
            std::string serverIp;
            int serverPort;
            sockaddr_in serverAddr;
            char buffer[1024];
        public:
            Client(const int&,const std::string&);
            ~Client();

            void sendMessage(const std::string&);
            void recvMessage();
        private:
            void init();



    };
}