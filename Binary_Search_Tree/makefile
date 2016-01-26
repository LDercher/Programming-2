 
 Lab08: main.o valuenotfoundexception.o
	g++ -g -std=c++11 -Wall main.o valuenotfoundexception.o -o Lab08

main.o: node.h node.hpp BSTI.h binarysearchtree.h binarysearchtree.hpp
	g++ -g -std=c++11 -Wall -c main.cpp
	
valuenotfoundexception.o: valuenotfoundexception.h valuenotfoundexception.cpp
	g++ -g -std=c++11 -Wall -c valuenotfoundexception.cpp	
	

clean:
	rm *.o Lab08

