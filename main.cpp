#include <pthread.h>
#include <unistd.h>

#include <iostream>
#include <string>
#include <queue>
#include <list>
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

int main()
{
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
            cout << "Client ip = " << client.getAddress() << endl;
            string p = client.recv(1024);

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
