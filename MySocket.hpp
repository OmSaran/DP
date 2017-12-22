#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <netinet/in.h>
#include <sys/socket.h>
#include <iostream>

using namespace std;


class MySocket 
{

private:
    struct sockaddr_in address;
    int fd = -1;
    int port = -1;
public:
    MySocket();
    void bind(int port);
    void listen(int maxQueueSize);
    MySocket accept();
    std::string getAddress();
    std::string recv(int bufferSize);
    void send(std::string message);
    void connect(std::string hostName, int port);
};
#endif