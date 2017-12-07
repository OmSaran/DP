#ifndef SUBJECT_H
#define SUBJECT_H
#include "mySocket.hpp"

//#include "socket.cpp"
//#include <pthread.h>
#include <unistd.h>
//#include "rough.cpp" 
#include <iostream>
#include <string>
//#include <queue>
//#include <list>
#include <cstdlib>
#include <vector>
#include "observer.hpp"

class Subject
{


private: 
 vector< observer*> _observers;
//mySocket socket;
//string text; 

public: 
 Subject() {}; 
 virtual ~Subject() {}; 
 virtual void Attach(observer*); 
 virtual void Detach(observer*); 
 virtual void Notify();  



};
#endif
