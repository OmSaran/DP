#include "socket.cpp"

#include <iostream>
using namespace std;

int main()
{
    string buff;
    mySocket client;
    client = mySocket();
    try {
        client.connect("127.0.0.1", 4000);
        cout << "Connected Successfully!\n";
        while(1)
        {
            string msg;
            cout << "Waiting for message from Server: " << endl;
            cout << client.recv(1024) << endl;

            cout << "Enter message to send to Server: " << endl;
            cin >> msg;
            client.send(msg);

            msg.clear();
        }
    }
    catch (runtime_error err)
    {
        cout << err.what() << endl;
    }
    // cout << client.getAddress() << endl;
}