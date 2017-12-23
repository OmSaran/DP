#include <pthread.h>
#include <unistd.h>

#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <vector>
#include <algorithm>
#include <cstdlib>

#include "Observer.hpp"
#include "Observable.hpp"
#include "MySocket.hpp"
#include "Exceptions.hpp"
using namespace std;

void * job(void * ptr)
{
    Observable* task = (Observable *)ptr;
    // sleep(2);
    try {
        task->readInput();
    }
    catch(exception &e)
    {
        cout << e.what();
    }
}

void * eventLoop( void * ptr)
{
    Observer* obs = (Observer *) ptr;
    obs->observe();
}

bool in_array(const string &value, const vector<string> &array)
{
    return find(array.begin(), array.end(), value) != array.end();
}

int main()
{
    vector<string> res {
            "resource1",
            "resource2",
            "resource3",
            "resource4",
            "resource5",
            "resource6",
            "resource7",
            "resource8",
            "resource9",
            "resource10"
        };

    string buffer;
    MySocket server;   
    Observer obs;

    pthread_t t;
    pthread_create(&t, NULL, eventLoop, (void *) &obs);

    server = MySocket();
    server.bind(4300);
    server.listen(1);

    try 
    {
        while(true){
            MySocket client = server.accept();
            // cout << "Client ip = " << client.getAddress() << endl;
            string p = client.recv(1024);

            if( !in_array(p, res) )
            {
                client.send("Invalid Request");
                continue;
            }

            pthread_t t;
            Observable *req = new Observable(client, p);
            req->attach(&obs);

            pthread_create(&t, NULL, job, (void *) req);
        }
    }
    catch (runtime_error err) {
        cout << err.what() << endl;
    }

}
