game: main.o Entity.o Auto.o Ostacolo.o Partita.o Coda.o setCursorPosition.o
	g++ -o game main.o Entity.o Auto.o Ostacolo.o Partita.o Coda.o setCursorPosition.o

main.o: main.cpp
	g++ -c main.cpp

Auto.o: Auto.cpp Auto.hpp
	g++ -c Auto.cpp

Ostacolo.o: Ostacolo.cpp Ostacolo.hpp
	g++ -c Ostacolo.cpp

Entity.o: Entity.cpp Entity.hpp
	g++ -c Entity.cpp

Partita.o: Partita.cpp Partita.hpp
	g++ -c Partita.cpp

Coda.o: Coda.cpp Coda.hpp
	g++ -c Coda.cpp

setCursorPosition.o: setCursorPosition.cpp setCursorPosition.hpp
	g++ -c setCursorPosition.cpp