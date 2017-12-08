#include "Observer.hpp"
#include "Observable.hpp"
#include "MySocket.hpp"

void Observer::update(Observable *obs)
{
    if(obs->getState() == States::FINISHED_READING)
    {
        q.push(obs);    
    }
}
void Observer::observe() 
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