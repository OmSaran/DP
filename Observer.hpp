#ifndef OBSERVER_H
#define OBSERVER_H

#include <queue>
#include <map>
#include <utility>
#include "MySocket.hpp"

class Observable;

class Observer
{
private:
    std::queue< pair<MySocket, string> > q;
public:
    void update(Observable *obs);
    void observe();
};
#endif
