#include "observer.hpp"
#include "observable.hpp"
//#include "mySocket.hpp"
#include "Subject.hpp"

using namespace std;


 observable (mySocket &socket_in):socket(socket_in){};
	 

observable (mySocket &socket_in,string path_in)
	 { 
		socket=socket_in; 
		path=path_in;
	 }

 ///~observable() {}; 
 
 /*void readInput();
 string getText();
mySocket getSocket();*/
   


void observable::readInput()
	{
		 
		string line;
  		ifstream myfile (path.c_str());
		state=reading;
  		if (myfile.is_open())
  			{
    				while ( getline (myfile,line) )
    				{
      					text.append(line);
    				}
    			myfile.close();

  			}
			state=finishedReading;
			Notify(); 

	}
string observable::getText()
	{
		return text;
	
	}
mySocket observable::getSocket()

	{
		return socket;
	}


string observable::getPath()
	{
		return path;
	}
void observable::sendResponse()
	{
		socket.send(text);
}

states observable::getState()
{
	return state;
}



