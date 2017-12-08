server.o : main.cpp Observable.cpp Observer.cpp MySocket.cpp States.hpp Exceptions.cpp client.cpp MySocket.cpp
	   g++-7 -lpthread main.cpp Observable.cpp Observer.cpp MySocket.cpp Exceptions.cpp -o server
	   g++-7  client.cpp MySocket.cpp -o client
