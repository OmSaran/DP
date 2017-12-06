#include "socket.cpp"
//#include <pthread.h>
#include <unistd.h>

#include <iostream>
#include <string>
//#include <queue>
//#include <list>
#include <cstdlib>
using namespace std;

class Subject 
{ 
public: 
 Subject() {}; 
 virtual ~Subject() {}; 
 virtual void Attach(Observer*); 
 virtual void Detach(Observer*); 
 virtual void Notify();  
private: 
 vector<Observer*> _observers;
mySocket socket;
string text; 
}; 

void Subject::Attach (Observer* o) 
{ 
 _observers.push_back(o); 
} 

void Subject::Detach (Observer* o) 
{ 
 int count = _observers.size(); 
 int i; 

 for (i = 0; i < count; i++) { 
   if(_observers[i] == o) 
   break; 
 } 
 if(i < count) 
  _observers.erase(_observers.begin() + i); 

} 

void Subject::Notify () 
{ 
 int count = _observers.size(); 

 for (int i = 0; i < count; i++) 
   (_observers[i])->Update(this); 
}

