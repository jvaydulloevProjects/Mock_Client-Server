#include "server.hpp"

Net::Server::Server(const uint16_t & port, const char * ip_adress)
        :
        port(port),
        ip_adress(ip_adress){}

Net::Server::~Server()
{
    if(sock>=0)
    {
        close(sock);
        sock=-1;
    }
}

void Net::Server::start()
{
    init();

    while(true)
    {
        std::cout<<"Server listen \n";
        recv();
        handleMessage();
        send();
    }
}

void Net::Server::init()
{
    addr.sin_family =AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET,ip_adress.c_str(),&addr.sin_addr);

    sock = socket(AF_INET,SOCK_DGRAM,0);
    bind(sock,(sockaddr*)&addr,sizeof(addr));
}

void Net::Server::handleMessage()
{
    messageType = Protocol::decode(buff);
    if(messageType ==Protocol::MsgType::Ping)
        reply = "PONG";
    else if(messageType ==Protocol::MsgType::Pong)
        reply = "PING";
}

void Net::Server::recv()
{   
    socklen_t clientLen = sizeof(clientAddr);
    ssize_t bytesReceived = recvfrom(sock, buff, 1024, 0,
                                    (sockaddr*)&clientAddr, &clientLen);

    if(bytesReceived<0)
    {
        perror("recvfrom failed");
        exit(EXIT_FAILURE);
    }
    buff[bytesReceived] = '\0';
    std::cout<<"Received: "<<buff<<std::endl;
}

void Net::Server::send()
{
    ssize_t bytesSended = sendto(sock, reply.c_str(), reply.length(), 0,
                             (sockaddr*)&clientAddr, sizeof(clientAddr));

    if(bytesSended<0)
    {
        perror("Sendto failed");
        exit(EXIT_FAILURE);
    }
    std::cout<<"Sended: "<<reply<<std::endl;
}

