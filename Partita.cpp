#include "Partita.hpp"
#include "Auto.hpp"
#include "Coda.hpp"
#include "listQueue.hpp"
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
        setCursorPosition(i, height,247);
        cout << "-";
    }
    for(int i = 0; i<height; i++)
    {
        setCursorPosition(length, i,247);
        cout << "|";
    }
}

Partita::Partita(int l, int h)
{
    length = l;
    height = h;
    cBoost = 0;

    a = Auto(length/2, 3*height/4);
    coda = Coda(100);
    boostQueue = Queue();

    punti = 0;
    x = length/2;
    y= height-1;
    input = 0;

    t = time();
    delay = 200;

    livello = 1;
    danno = 20;

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
		switch(c)
        {
			case 72:
                if (y<=0)
                    y=0;
                else
                    y--;
				break;

			case 80:
				if (y>=height-1)
                    y=height-1;
                else
                    y++;
				break;

			case 77:
				if (x>=length-1)
                    x=length-1;
                else
                    x++;
                break;

			case 75:
				if (x<=0)
                    x=0;
                else
                    x--;
				break;
		}
}

void Partita::stampaInfo()
{
    int l = 70;

    setCursorPosition(l,0,95);
	std::cout << "dimensione coda: " << coda.getDim();

    setCursorPosition(l, 1,95);
    cout << "dimensione lista: " << boostQueue.getDim();

    if(coda.checkCollisioni(a.getX(), a.getY()) || boostQueue.checkCollision(a.getX(), a.getY()))
    {
        setCursorPosition(l,2,95);
        std::cout << "collisione:  true";
    }
    else
    {
        setCursorPosition(l,2,95);
        std::cout << "collisione: false";
    }

    setCursorPosition(l,3,95);
    std::cout << "punteggio: " << punti << " ";

    setCursorPosition(l,4,95);
    std::cout << "livello: " << livello << " ";

    setCursorPosition(l,5,95);
    std::cout << "danno: " << danno << " ";
}

int Partita::getRandomX()
{
	int r = rand()%length;
	return r;
}


void Partita::start()
{
    // Ostacolo o1(2, 6);
	// Ostacolo o2(20, 4);
	// Ostacolo o3(12, 3);
	// Ostacolo o4(4, 2);
    // coda.enq(o1);
    // coda.enq(o2);
    // coda.enq(o3);
    // coda.enq(o4);
    // coda.enq(o5);
    Boost b(getRandomX());
    boostQueue.enQ(b);

    while (1)
	{
		//Sleep(50);
		int newInput = getInput();
		if (newInput != 0)
		{
			input = newInput;
		}

		setCursorPosition(0,0,0); //toglie i flickering
		coda.stampa();
		a.stampa();
        boostQueue.print();

		processInput(input);
		input = 0;
        
		a.setPos(x,y);

		if(time() - t > delay)
		{
            bordo();
			t = time();
            punti += 1;

            // spawn reduction work in progress
            if (cBoost >= 10)
            {
                Boost b(getRandomX());
                boostQueue.enQ(b);
                cBoost = 0;
            }
            cBoost += livello;

            boostQueue.move();
            boostQueue.checkLimit(getHeight());
            Ostacolo o(getRandomX());

            if (o.getX() != b.getX())
                coda.enq(o);

            coda.move();
            coda.checkLimite(getHeight());

            setCursorPosition(70, 20,0);
            if (boostQueue.checkCollision(a.getX(), a.getY()))
            {
                punti += danno;
            }
            if (coda.checkCollisioni(a.getX(), a.getY()))
            {
                punti -= danno;
            }

            if (punti >= 100)
            {
                punti = 0;
                livello += 1;
                danno += 20;
            }
            if (punti < 0)
            {
                punti = 0;
                livello -= 1;
                danno -= 20;
            }
		}

        if(livello < 1) break;

		stampaInfo();
	}

    cls();
    while(1)
    {
        setCursorPosition(length/2, height/2,42);
        cout << "perso sfigato gay";
    }
}