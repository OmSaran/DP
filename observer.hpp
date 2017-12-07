#ifndef OBSERVER_H
#define OBSERVER_H

#include <queue>

class observable;

class observer
{
private:
    std::queue<observable* > q;
public:
    void update(observable *obs);
    void observe();
};
#endif