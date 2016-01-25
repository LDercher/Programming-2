 Lab07: main.o numberfiledriver.o numberfilegenerator.o sortdriver.o
	g++ -g -std=c++11 -Wall main.o numberfiledriver.o sortdriver.o numberfilegenerator.o -o Lab07

main.o: sorts.h sorts.hpp numberfiledriver.h numberfiledriver.cpp numberfilegenerator.h numberfilegenerator.cpp sortdriver.h sortdriver.cpp main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp
	
sortdriver.o: sortdriver.h sortdriver.cpp sorts.h sorts.hpp
	g++ -g -std=c++11 -Wall -c sortdriver.cpp	
	
numberfiledriver.o: numberfiledriver.h numberfiledriver.cpp numberfilegenerator.h numberfilegenerator.cpp
	g++ -g -std=c++11 -Wall -c numberfiledriver.cpp
	
numberfilegenerator.o: numberfilegenerator.h numberfilegenerator.cpp
	g++ -g -std=c++11 -Wall -c numberfilegenerator.cpp	

clean:
	rm *.o Lab07
