#include "Partita.hpp"
#include "Auto.hpp"
#include "Coda.hpp"
#include "setCursorPosition.hpp"
#include <iostream>
#include <chrono>

using namespace std;

uint64_t Partita::time()
{
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

Partita::Partita(int l, int h)
{
    length = l;
    height = h;

    a = Auto(length/2, 2*height/3);
    coda = Coda(100);

    punti = 0;
    x = 45;
    y = 17;
    input = 0;

    t = time();
    delay = 200;

    setCursorPosition(0, getHeight());
	std::cout << "-----------------------------------------";
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

void Partita::start()
{
    Ostacolo o1(2, 6);
	Ostacolo o2(20, 4);
	Ostacolo o3(12, 3);
	Ostacolo o4(4, 2);
	Ostacolo o5(10, 1);

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
			if(coda.checkCollisioni(a.getX(), a.getY()))
			{
				setCursorPosition(60,1);
				std::cout << "collisione:  true";
			}
			else
			{
				setCursorPosition(60,1);
				std::cout << "collisione: false";
			}
			t = time();
			coda.move();
			coda.checkLimite(getHeight());
		}

		setCursorPosition(60,0);
		std::cout << "dimensione coda: " << coda.getDim();
	}
}