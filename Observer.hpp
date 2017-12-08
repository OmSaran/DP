#ifndef OBSERVER_H
#define OBSERVER_H

#include <queue>
#include <deque>
#include <list>

class Observable;

class Observer
{
private:
    std::queue<Observable *> completedQ;
    std::list<Observable *> processingList;
public:
    void update(Observable *obs);
    void observe();
};
#endif
