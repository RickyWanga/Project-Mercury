game: main.o Campo.o
	g++ -o game main.o Campo.o

main.o: main.cpp
	g++ -c main.cpp

Project.o: Campo.cpp campo.hpp
	g++ -c Project.cpp