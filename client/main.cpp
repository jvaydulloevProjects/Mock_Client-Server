#include "client.hpp"


int main()
{


    Net::Client client(8888,"127.0.0.1");
    std::string message;
    while(message != "exit")
    {
        std::cout<<"Enter: ";
        std::cin>>message;
        client.sendMessage(message);
        client.recvMessage();
        sleep(1);
    }

    return 0;
}