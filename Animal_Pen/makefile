 Lab05: main.o PreconditionViolationException.o FarmAnimal.o cow.o chicken.o cyberchicken.o animalpen.o
	g++ -g -std=c++11 -Wall main.o PreconditionViolationException.o FarmAnimal.o chicken.o cow.o cyberchicken.o animalpen.o -o Lab05

main.o: main.cpp stack.h StackInterface.h stack.hpp FarmAnimal.h cow.h chicken.h animalpen.h  cyberchicken.h node.h node.hpp
	g++ -g -std=c++11 -Wall -c main.cpp

animalpen.o: animalpen.h animalpen.cpp stack.h StackInterface.h
	g++ -g -std=c++11 -Wall -c animalpen.cpp
	
FarmAnimal.o: FarmAnimal.h FarmAnimal.cpp
	g++ -g -std=c++11 -Wall -c FarmAnimal.cpp

cow.o: cow.h cow.cpp
	g++ -g -std=c++11 -Wall -c  cow.cpp
	
chicken.o: chicken.h chicken.cpp
	g++ -g -std=c++11 -Wall -c  chicken.cpp
	
cyberchicken.o: cyberchicken.h cyberchicken.cpp
	g++ -g -std=c++11 -Wall -c  cyberchicken.cpp
	
PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -std=c++11 -Wall -c PreconditionViolationException.cpp

clean:
	rm *.o Lab05
