#include <iostream>
#include <fstream>
using namespace std;

class observable : public Subject
{
public: 
 observable (mysocket * socket_in)
	 { 
		socket=socket_in; 
	 };
virtual ~observable() {}; 
 
 void readInput();
 string getText();
mySocket getSocket();
   
private: 
 //vector<Observer*> _observers;
	mySocket socket;
	string text; 

void observable::readInput(string path)
	{
		 
		string line;
  		ifstream myfile (path);
  		if (myfile.is_open())
  			{
    				while ( getline (myfile,line) )
    				{
      					text.append(line)
    				}
    			myfile.close();

  			}
			Notify(); 

	}
string observable::gettext()
	{
		return text;
	
	}
mysocket socket::getsocket()

	{
		return socket;
	}


}
