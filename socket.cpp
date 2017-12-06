#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <iostream>
#include <string>
using namespace std;

class mySocket 
{

private:
    struct sockaddr_in address;
    int fd = -1;
    int port = -1;

public:
    mySocket()
    {
        fd = ::socket(AF_INET, SOCK_STREAM, 0);
        if(fd < 0)
        {
            throw runtime_error("Failed to create socket");
        }   
    }
    void bind(int port)
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

    void listen(int maxQueueSize)
    {
        if( (::listen(fd, maxQueueSize)) < 0 )
        {
            cout << "Thrwoing in Listen!" << endl;
            throw runtime_error("Failed to listen");
        }
    }

    mySocket accept()
    {
        struct sockaddr_in clientAddress;
        int addrlen = sizeof(clientAddress);
        int clientFD = ::accept(fd, (struct sockaddr *) &clientAddress,
            (socklen_t *) &addrlen );
        if(clientFD < 0)
        {
            throw runtime_error("Could not accept connection");
        }
        mySocket client = mySocket();
        client.address = clientAddress;
        client.fd = clientFD;
        return client;
    }

    string getAddress()
    {
        const char* ip = inet_ntoa(address.sin_addr);
        return string(ip);
    }

    string recv(int bufferSize)
    {
        char * msg = (char *) calloc(bufferSize, sizeof(char));
        if( (::recv(fd, msg, bufferSize, 0)) < 0 )
        {
            throw runtime_error("Message receive error");
        }
        return string(msg);
    }
    void send(string message)
    {
        if( (::send(fd, message.c_str(), message.length(), 0)) <0 )
        {
            throw runtime_error("Failed to send");
        }
    }

    void connect(string hostName, int port)
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
};

