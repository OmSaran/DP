#include "observer.hpp"
#include "observable.hpp"
//#include "mySocket.hpp"
//#include "Subject.hpp"

using namespace std;


observable::observable (mySocket socket_in){
	socket = socket_in;
};
	 

observable::observable (mySocket socket_in,string path_in)
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
					text.append("\n");
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
void observable::Attach (observer* o) 
{ 
 _observers.push_back(o); 
} 

void observable::Detach (observer* o) 
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

void observable::Notify () 
{ 
 int count = _observers.size(); 

 for (int i = 0; i < count; i++) 
   (_observers[i])->update(this); 
}



