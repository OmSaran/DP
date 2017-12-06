#include "socket.cpp"
//#include <pthread.h>
#include <unistd.h>
#include "rough.cpp" 
#include <iostream>
#include <string>
//#include <queue>
//#include <list>
#include <cstdlib>
#include <vector>

using namespace std;

class Subject 
{ 
public: 
 Subject() {}; 
 virtual ~Subject() {}; 
 virtual void Attach(observer*); 
 virtual void Detach(observer*); 
 virtual void Notify();  
private: 
 vector< observer*> _observers;
mySocket socket;
string text; 
}; 

void Subject::Attach (observer* o) 
{ 
 _observers.push_back(o); 
} 

void Subject::Detach (observer* o) 
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

