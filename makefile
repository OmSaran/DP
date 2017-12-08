server.o : main.cpp Observable.cpp Observer.cpp MySocket.cpp States.hpp Exceptions.cpp client.cpp MySocket.cpp
	   g++ -w -pthread main.cpp Observable.cpp Observer.cpp MySocket.cpp Exceptions.cpp -o server
	   g++ -w client.cpp MySocket.cpp -o client
