#include "MySocket.hpp"

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    string buff;
    MySocket client;
    client = MySocket();
    try {
        client.connect("127.0.0.1", 4300);
        cout << "Connected Successfully!\n";

        string path = string(argv[1]);
        client.send(path);

        string resp = client.recv(2048);
        cout << "Response: " << resp << endl;
    }
    catch (runtime_error err)
    {
        cout << err.what() << endl;
    }
}
