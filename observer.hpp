#ifndef OBSERVER_H
#define OBSERVER_H

#include <queue>

class Observable;

class Observer
{
private:
    std::queue<Observable* > q;
public:
    void update(Observable *obs);
    void observe();
};
#endif
