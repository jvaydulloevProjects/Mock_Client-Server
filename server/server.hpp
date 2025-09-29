#pragma once
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include "../common/protocol.hpp"

namespace Net
{
    class Server
    {
        private:
            uint16_t port;
            std::string ip_adress;
            sockaddr_in addr{};
            char buff[1024];
            int sock;
            int logStats;
            Protocol::MsgType messageType;
            std::string reply;
            sockaddr_in clientAddr;
        public:
            Server(const uint16_t&,const char*);
            ~Server();
            void start();
        
        private:
            void init();
            void handleMessage();
            void recv();
            void send();

    };
};