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
        setCursorPosition(i, height, 247);
        cout << "-";
    }
    for(int i = 0; i<=height; i++)
    {
        setCursorPosition(length, i, 247);
        cout << "|";
    }
}

Partita::Partita(int l, int h)
{
    length = l;
    height = h;

    a = Auto(length/2, 3*height/4);
    coda = Coda(100);
    boostQueue = Queue();

    punti = 0;
    x = length/2;
    y= height-1;
    input = 0;
    cstamp = 0;

    t = time();
    delay = 200;

    livello = 1;
    danno = 10;

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
		switch(c)   // Gli spostamenti sono limitati all'asse X
        {   
			// case 72:
            //     if (y<=0)
            //         y=0;
            //     else
            //         y--;
			// 	break;

			// case 80:
			// 	if (y>=height-1)
            //         y=height-1;
            //     else
            //         y++;
			// 	break;

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

            case 27:
                livello = 0;
                break;
		}
}

void Partita::stampaInfo()
{
    int l = 70;

    setCursorPosition(l,0,95);
	std::cout << "dimensione coda: " << coda.getDim() << " ";

    setCursorPosition(l, 1,95);
    cout << "dimensione lista: " << boostQueue.getDim() << " ";

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

    setCursorPosition(l,6,95);
    cout << "delay: " << delay << " ";

    setCursorPosition(l,7,95);
    cout << "spawn counter: " << cstamp << " ";
}

int Partita::getRandomX()
{
	int r = rand()%length;
	return r;
}

int Partita::setRandomSpawn()
{
    int level;
    level = livello - 1;

    if (level >= 18)
        level = 18;

    int r = rand()% (21 - level) + 1;
    return r;
}


void Partita::start()
{
    int maxspawn = 0;
    //int cstamp = 0;
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
        boostQueue.print();
		a.stampa();

		processInput(input);
		input = 0;

		a.setPos(x,y);

        if (danno >= 100)
            danno = 100;

        if (delay <= 100)
            delay = 100;
        else if (delay >= 200)
            delay = 200;

        if(time() - t > delay)
        {
            bordo();
            t = time();
            punti += 1;

            // spawn method work in progress
            if (setRandomSpawn() == 1)
            {
                if (cstamp > maxspawn)
                    maxspawn = cstamp;

                cstamp = 0;
                Boost b(getRandomX());
                boostQueue.enQ(b);
            }
            if (cstamp < 50)
            {
                cstamp++;
            }
            else
            {
                cstamp = 0;
                Boost b(getRandomX());
                boostQueue.enQ(b);
            }
            //////////////////////////////////
            boostQueue.move();
            boostQueue.checkLimit(getHeight());

            Ostacolo o(getRandomX());
            if (o.getX() != b.getX())
            {
                coda.enq(o);
            }
            coda.move();
            coda.checkLimite(getHeight());

            setCursorPosition(70, 20, 0);
            if (boostQueue.checkCollision(a.getX(), a.getY()))
            {
                punti += 15;
            }
            if (coda.checkCollisioni(a.getX(), a.getY()))
            {
                punti -= danno;
            }

            if (punti >= 100)
            {
                punti = 0;
                livello += 1;
                danno += 5;
                if ((livello % 5) == 0)
                    delay -= 25;
            }
            if (punti < 0)
            {
                if (livello <= 20)
                {
                    danno -= 5;
                    if ((livello % 5) == 0)
                        delay += 25;
                }
                punti = 0;
                livello -= 1;
            }
        }

        if(livello < 1) break;

        stampaInfo();
    }

    cls();
    while(1)
    {
        setCursorPosition(length-10, height/2, 16);
        cout << "perso sfigato gay";
        // setCursorPosition(length-3, (height/2) + 1, 16);
        // cout << maxspawn;
    }
}