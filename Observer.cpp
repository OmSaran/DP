#include "Observer.hpp"
#include "Observable.hpp"
#include "MySocket.hpp"

void Observer::update(Observable *obs)
{
    if(obs->getState() == FINISHED_READING)
    {
        completedQ.push(obs);
    }
    if(obs->getState() == READING)
    {
        processingList.push_back(obs);
    }
    if(obs->getState() == FINISHED_READING)
    {
        for(auto it=processingList.begin(); it!=processingList.end();++it) {
            if((*it) == obs)
            {
                processingList.erase(it);
            }
        }
    }
}
void Observer::observe() 
{
    int size = processingList.size();
    while(true)
    {
        while(!completedQ.empty())
        {
            completedQ.front()->sendResponse();
            completedQ.pop();
        }

        if(size != processingList.size()) {
            cout << "Processing: " ;
            for(auto it=processingList.begin(); it!=processingList.end();++it)
                std::cout << (*it)->getPath() << " ";
            size = processingList.size();
            std::cout << "\n";
        }
    }
}