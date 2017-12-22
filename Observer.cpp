#include "Observer.hpp"
#include "Observable.hpp"
#include "MySocket.hpp"

#include <iostream>
#include <map>
#include <utility>

using namespace std;

void Observer::update(Observable *obs)
{
    if(obs->getState() == FINISHED_READING)
    {
        q.push(make_pair(obs->getSocket(), obs->getText()));
    }
}
void Observer::observe() 
{
    while(true)
    {
        while(!q.empty())
        {
            MySocket* sock = &(q.front().first);
            string* text = &(q.front().second);
            
            sock->send(*text);
            q.pop();
        }
    }
}