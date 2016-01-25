Lab09: main.o node.o linkedlist.o
	g++ -g -std=c++11 -Wall main.o node.o linkedlist.o -o Lab02


main.o: linkedlist.h node.h main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

linkedlist.o: linkedlist.h linkedlist.cpp
	g++ -g -std=c++11 -Wall -c linkedlist.cpp

node.o: node.h node.cpp
	g++ -g -std=c++11 -Wall -c node.cpp

clean:
	rm *.o Lab02
