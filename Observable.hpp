#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include "States.hpp"
#include "MySocket.hpp"
#include <iostream>
#include <fstream>

#include <unistd.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "Observer.hpp"


class Observable
{
private:
	MySocket socket;
	string text;
    string path;
	States state= NOT_READ;
	vector<Observer*> _observers;


public: 
	Observable(MySocket socket_in);
    Observable(MySocket socket_in, string path_in);

	void readInput();
	string getText();
	States getState();
	MySocket getSocket();
	void attach(Observer*); 
 	void detach(Observer*); 
	void notify();
    string getPath();
    // void sendResponse();
};
#endif
