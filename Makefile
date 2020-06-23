game: main.o Entity.o Auto.o Partita.o setCursorPosition.o Queue.o Hittable.o
	g++ -o game main.o Entity.o Auto.o Partita.o setCursorPosition.o Queue.o Hittable.o

main.o: main.cpp
	g++ -c main.cpp

Auto.o: Auto.cpp Auto.hpp
	g++ -c Auto.cpp

Entity.o: Entity.cpp Entity.hpp
	g++ -c Entity.cpp

Partita.o: Partita.cpp Partita.hpp
	g++ -c Partita.cpp

setCursorPosition.o: setCursorPosition.cpp setCursorPosition.hpp
	g++ -c setCursorPosition.cpp

listQueue.o: Queue.cpp Queue.hpp
	g++ -c Queue.cpp

Hittable.o: Hittable.cpp Hittable.hpp
	g++ -c Hittable.cpp

# Coda.o: Coda.cpp Coda.hpp
# 	g++ -c Coda.cpp