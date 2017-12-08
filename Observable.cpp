#include "Observer.hpp"
#include "Observable.hpp"
#include "Exceptions.hpp"

using namespace std;

Observable::Observable (MySocket socket_in){
	socket = socket_in;
};

Observable::Observable (MySocket socket_in,string path_in)
{
	socket=socket_in;
	path=path_in;
}

void Observable::readInput()
{
	string line;
	ifstream myfile (path.c_str());
	state = READING;
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			text.append(line);
			text.append("\n");
		}
		myfile.close();

	}
	else
	{
		throw ResourceNotFoundException();
	}
	state = FINISHED_READING;
	notify(); 

}

string Observable::getText()
{
	return text;
}

MySocket Observable::getSocket()
{
	return socket;
}

string Observable::getPath()
{
	return path;
}

void Observable::sendResponse()
{
	socket.send(text);
}

States Observable::getState()
{
	return state;
}

void Observable::attach (Observer* o) 
{ 
	_observers.push_back(o); 
}

void Observable::detach (Observer* o) 
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

void Observable::notify () 
{ 
	int count = _observers.size(); 

	for (int i = 0; i < count; i++) 
		(_observers[i])->update(this); 
}