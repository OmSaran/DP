#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "mySocket.hpp"
class observable : public Subject
{
private:
	mySocket socket;
	string text;
    string path;

public: 
	observable(mySocket * socket_in);
    observable(mySocket * socket_in, string path);
	virtual ~observable(); 

	void readInput();
	string getText();
	mySocket getSocket();
    void setPath();
    void getPath();
    void sendResponse();
};
#endif