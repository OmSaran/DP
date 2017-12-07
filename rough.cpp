#include <pthread.h>
#include <unistd.h>

#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <cstdlib>

#include "observer.hpp"
#include "observable.hpp"
#include "mySocket.hpp"
using namespace std;

void * job(void * ptr)
{
    observable* task = (observable *)ptr;
    sleep(2);
    task->readInput();
}

void * eventLoop( void * ptr)
{
    observer* obs = (observer *) ptr;
    obs->observe();
}

int main()
{
    string buffer;
    mySocket server;   
    observer obs;

    pthread_t t;
    pthread_create(&t, NULL, eventLoop, (void *) &obs);

    server = mySocket();
    server.bind(4000);
    server.listen(1);

    try 
    {
        while(true){
            mySocket client = server.accept();
            cout << "Client ip = " << client.getAddress() << endl;
            string p = client.recv(1024);

            pthread_t t;
            observable *req = new observable(client, p);
            req->Attach(&obs);

            pthread_create(&t, NULL, job, (void *) req);
        }
    }
    catch (runtime_error err) {
        cout << err.what() << endl;
    }

}