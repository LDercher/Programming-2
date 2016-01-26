Lab09: main.o mazereader.o mazecreationexception.o position.o mazewalker.o
	g++ -g -std=c++11 -Wall main.o mazereader.o mazecreationexception.o mazewalker.o position.o -o Lab09

main.o: mazereader.h mazereader.cpp mazewalker.h mazewalker.cpp mazecreationexception.h mazecreationexception.cpp position.h position.cpp main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp
	
mazereader.o: mazereader.h mazereader.cpp
	g++ -g -std=c++11 -Wall -c mazereader.cpp	
	
position.o: position.h position.cpp
	g++ -g -std=c++11 -Wall -c position.cpp

mazewalker.o: mazewalker.h mazewalker.cpp
	g++ -g -std=c++11 -Wall -c mazewalker.cpp

mazecreationexception.o: mazecreationexception.h mazecreationexception.cpp
	g++ -g -std=c++11 -Wall -c mazecreationexception.cpp

clean:
	rm *.o Lab09
