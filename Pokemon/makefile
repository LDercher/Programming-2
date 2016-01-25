Lab01: main.o colosseum.o pokemon.o dice.o
	g++ -g -std=c++11 -Wall main.o colosseum.o pokemon.o dice.o -o Lab01
	
main.o: colosseum.h dice.h pokemon.h main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

colosseum.o: colosseum.h colosseum.cpp pokemon.h dice.h
	g++ -g -std=c++11 -Wall -c colosseum.cpp
	
pokemon.o: pokemon.h pokemon.cpp
	g++ -g -std=c++11 -Wall -c pokemon.cpp
	
dice.o: dice.h dice.cpp
	g++ -g -std=c++11 -Wall -c dice.cpp
	
clean:
	rm *.o Lab01
