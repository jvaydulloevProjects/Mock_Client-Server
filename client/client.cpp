#include "client.hpp"

Net::Client::Client(const int & port, const std::string &ip_adress)
        :
        serverPort(port),
        serverIp(ip_adress)
{
    init();
}

Net::Client::~Client()
{
    close(sock);
}

void Net::Client::sendMessage(const std::string& message)
{
    ssize_t bytesSended = sendto(sock,message.c_str(),message.length(),0,(sockaddr*)&serverAddr,sizeof(serverAddr));
    if(bytesSended<0)
    {
        perror("Sendto failed");
        exit(EXIT_FAILURE);
    }
    std::cout<<"Sended to server: "<<message<<std::endl;
}

void Net::Client::recvMessage()
{
    socklen_t addrLen = sizeof(serverAddr);
    ssize_t bytesReceived =recvfrom(sock,buffer,1024,0,(sockaddr*)&serverAddr,&addrLen);
    if(bytesReceived<0)
    {
        perror("recvfrom failed");
        exit(EXIT_FAILURE);
    }
    buffer[bytesReceived] = '\0';
    std::cout<<"Received from server: "<<buffer<<std::endl;
}

void Net::Client::init()
{
    serverAddr.sin_family =AF_INET;
    serverAddr.sin_port = htons(serverPort);
    inet_pton(AF_INET,serverIp.c_str(),&serverAddr.sin_addr);

    sock = socket(AF_INET,SOCK_DGRAM,0);
}
