#ifndef OBSERVABLE_H
#define OBSERVABLE_H
//#include "Subject.hpp"
#include "states.hpp"
#include "mySocket.hpp"
#include <iostream>
#include <fstream>


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


class observable //: public Subject
{
private:
	mySocket socket;
	string text;
    	string path;
	states state=notRead;
	vector< observer*> _observers;


public: 
	observable(mySocket socket_in);
    observable(mySocket socket_in, string path_in);
	// virtual ~observable(); 

	//void readInput(string path);
	void readInput();
	string getText();
	states getState();
	mySocket getSocket();
	void Attach(observer*); 
 	void Detach(observer*); 
	void Notify();  

    //void setPath();
    string getPath();
    void sendResponse();
};
#endif
