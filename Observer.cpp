#include "Observer.hpp"
#include "Observable.hpp"
#include "MySocket.hpp"

void Observer::update(Observable *obs)
{
    if(obs->getState() == FINISHED_READING)
    {
        q.push(obs);    
    }
}
void Observer::observe() 
{
    while(true)
    {
        while(!q.empty())
        {
            q.front()->sendResponse();
            q.pop();
        }
    }
}