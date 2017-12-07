#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include "Subject.hpp"
#include "states.hpp"
#include "mySocket.hpp"
#include <iostream>
#include <fstream>


class observable : public Subject
{
private:
	mySocket &socket;
	string text;
    	string path;
	states state=notRead;


public: 
	observable(mySocket &socket_in);
    observable(mySocket &socket_in, string path_in);
	virtual ~observable(); 

	//void readInput(string path);
	void readInput();
	string getText();
	states getState();
	mySocket getSocket();

    //void setPath();
    string getPath();
    void sendResponse();
};
#endif
