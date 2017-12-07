#include "observer.hpp"
#include "observable.hpp"
#include "mySocket.hpp"

void observer::update(observable *obs)
{
    q.push(obs);
}
void observer::observe() 
{
    while(true)
    {
        if(!q.empty())
        {
            while(!q.empty())
            {
                mySocket client = q.front()->socket;
                client.send(q.front()->text);
                q.pop();
            }
        }
    }
}