#include "Partita.hpp"
#include "Auto.hpp"
#include "Coda.hpp"
#include "Boost.hpp"
#include "setCursorPosition.hpp"
#include <iostream>
#include <chrono>

using namespace std;

uint64_t Partita::time()
{
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

void Partita::bordo()
{
    for(int i = 0; i<length; i++)
    {
        setCursorPosition(i, height);
        cout << "-";
    }
    for(int i = 0; i<height; i++)
    {
        setCursorPosition(length, i);
        cout << "|";
    }
}

Partita::Partita(int l, int h)
{
    length = l;
    height = h;

    a = Auto(length/2, 3*height/4);
    coda = Coda(100);

    punti = 0;
    x = length/2;
    y = 3*height/4;
    input = 0;

    t = time();
    delay = 200;

    bordo();
}

int Partita::getLength()
{
    return length;
}

int Partita::getHeight()
{
    return height;
}

void Partita::processInput(int c)
{
		// cout << c;
		switch(c) {
			case 72:
				y--;
				break;
			case 80:
				y++;
				break;
			case 77:
				x++;
				break;
			case 75:
				x--;
				break;
		}
}

void Partita::stampaInfo()
{
    int l = 70;

    setCursorPosition(l,0);
	std::cout << "dimensione coda: " << coda.getDim();

    if(coda.checkCollisioni(a.getX(), a.getY()))
    {
        setCursorPosition(l,1);
        std::cout << "collisione:  true";
    }
    else
    {
        setCursorPosition(l,1);
        std::cout << "collisione: false";
    }

    setCursorPosition(l,2);
    std::cout << "punteggio: " << punti;
}


void Partita::start()
{
    Ostacolo o1(2, 6);
	Ostacolo o2(20, 4);
	Ostacolo o3(12, 3);
	Ostacolo o4(4, 2);
	Boost o5(10, 1);

    coda.enq(o1);
    coda.enq(o2);
    coda.enq(o3);
    coda.enq(o4);
    coda.enq(o5);

    while (1)
	{
		//Sleep(50);
		int newInput = getInput();
		if (newInput != 0)
		{
			input = newInput;
		}

		setCursorPosition(0,0); //toglie i flickering

		coda.stampa();
		a.stampa();

		processInput(input);
		input = 0;

		a.setPos(x,y);

		if(time() - t > delay)
		{
			t = time();
			coda.move();
			coda.checkLimite(getHeight());
            bordo();
		}

		stampaInfo();
	}
}