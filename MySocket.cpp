#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <iostream>
#include <string>
#include "MySocket.hpp"
using namespace std;

MySocket::MySocket()
{
    fd = ::socket(AF_INET, SOCK_STREAM, 0);
    if(fd < 0)
    {
        throw runtime_error("Failed to create socket");
    }
}
void MySocket::bind(int port)
{
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    address.sin_family = AF_INET;

    if(fd < 0)
    {
        throw runtime_error("Socket not initialized");
    }
    if( (::bind(fd, (const struct sockaddr*) &address, 
        sizeof(address)) ) < 0 )
    {
        throw runtime_error("Failed to bind");
    }
}

void MySocket::listen(int maxQueueSize)
{
    if( (::listen(fd, maxQueueSize)) < 0 )
    {
        cout << "Thrwoing in Listen!" << endl;
        throw runtime_error("Failed to listen");
    }
}

MySocket MySocket::accept()
{
    struct sockaddr_in clientAddress;
    int addrlen = sizeof(clientAddress);
    int clientFD = ::accept(fd, (struct sockaddr *) &clientAddress,
        (socklen_t *) &addrlen );
    if(clientFD < 0)
    {
        throw runtime_error("Could not accept connection");
    }
    MySocket client = MySocket();
    client.address = clientAddress;
    client.fd = clientFD;
    return client;
}

string MySocket::getAddress()
{
    const char* ip = inet_ntoa(address.sin_addr);
    return string(ip);
}

string MySocket::recv(int bufferSize)
{
    char * msg = (char *) calloc(bufferSize, sizeof(char));
    if( (::recv(fd, msg, bufferSize, 0)) < 0 )
    {
        throw runtime_error("Message receive error");
    }
    return string(msg);
}
void MySocket::send(string message)
{
    if( (::send(fd, message.c_str(), message.length(), 0)) <0 )
    {
        throw runtime_error("Failed to send");
    }
}

void MySocket::connect(string hostName, int port)
{

    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    if( (inet_pton(AF_INET, hostName.c_str(), &address.sin_addr.s_addr) < 0 ) )
    {
        throw runtime_error("Address conversion failure");
    }
    if( (::connect(fd, (const sockaddr *) &address, sizeof(address)) ) < 0 )
    {
        throw runtime_error("Connection failure");
    }
}

