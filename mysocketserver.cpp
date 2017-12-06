#include "socket.cpp"

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string buffer;
    mySocket server;   

    try {
        server = mySocket();
        server.bind(4000);
        server.listen(1);

        mySocket client = server.accept();
        cout << "Client ip = " << client.getAddress() << endl;

        while(1)
        {
            string msg;

            cout << "Enter message to send to Client: " << endl;
            cin >> msg;
            client.send(msg);
            msg.clear();

            cout << "Waiting for message from Client: " << endl;
            cout << client.recv(1024) << endl;
        }
    } 
    catch (runtime_error err) {
        cout << err.what() << endl;
    }

}