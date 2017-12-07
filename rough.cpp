#include <pthread.h>
#include <unistd.h>

#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <cstdlib>

<<<<<<< HEAD
#include "observer.hpp"
#include "observable.hpp"
#include "mySocket.hpp"
using namespace std;
=======
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
>>>>>>> 61c8661741d30ccd0b7fa8a1317838e64422dc36

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

            pthread_t t;
            observable *req = new observable();
            req->socket = client;
            req->add(&obs);

            pthread_create(&t, NULL, job, (void *) req);
        }
    }
    catch (runtime_error err) {
        cout << err.what() << endl;
    }

}
