game: main.o Project.o
	g++ -o game main.o Project.o

main.o: main.cpp
	g++ -c main.cpp

Project.o: Project.cpp campo.hpp
	g++ -c Project.cpp