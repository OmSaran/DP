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
                q.front()->sendResponse();
                q.pop();
            }
        }
    }
}