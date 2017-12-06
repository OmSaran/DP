#include "socket.cpp"
#include <pthread.h>
#include <unistd.h>

#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <cstdlib>
using namespace std;

//class Subject;
//class observable;
class observer
{
public:
    queue<observable> q;
// public:
    void Update(observable *obs)
    {
        q.push(*obs);
    }
};
/*class observable
{
private:        
    list<observer*> observersList;
public:
    mySocket socket;
    string text;
    void add(observer* o)
    {
        observersList.push_back(o);
    }
    void notif()
    {
        list<observer*>::iterator iterator;
        for(iterator = observersList.begin(); iterator != observersList.end(); ++iterator) {
            (*iterator)->update(this);
        }
    }
};*/

void * job(void * ptr)
{
    observable* task = (observable *)ptr;
    sleep(2);
    task->text = "Hello worldzzz " + to_string(rand());
    task->notif();
}


void * eventLoop( void * ptr)
{
    observer* obs = (observer *) ptr;
    while(true)
    {
        if(!obs->q.empty())
        {
            while(!obs->q.empty())
            {
                mySocket client = obs->q.front().socket;
                client.send(obs->q.front().text);
                obs->q.pop();
            }
        }
    }
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

    // mySocket client = server.accept();
    // cout << "Client ip = " << client.getAddress() << endl;


    try 
    {
        while(true){
            mySocket client = server.accept();
            cout << "Client ip = " << client.getAddress() << endl;

            pthread_t t;
            observable *req = new observable();
            req->socket = client;
            req->add(&obs);

            pthread_create(&t, NULL, job, (void *) req);
        }
    }

    // try
    // {
    //     while(1)
    //     {
    //         string msg;
    
    //         cout << "Enter message to send to Client: " << endl;
    //         cin >> msg;
    //         client.send(msg);
    //         msg.clear();
    
    //         cout << "Waiting for message from Client: " << endl;
    //         cout << client.recv(1024) << endl;
    //     }
    // }
    catch (runtime_error err) {
        cout << err.what() << endl;
    }

}
