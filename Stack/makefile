Lab04: main.o PreconditionViolationException.o
	g++ -g -std=c++11 -Wall main.o PreconditionViolationException.o -o Lab04

main.o: StackInterface.h Stack.h Stack.hpp node.h node.hpp main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -std=c++11 -Wall -c PreconditionViolationException.cpp

clean:
	rm *.o Lab04


