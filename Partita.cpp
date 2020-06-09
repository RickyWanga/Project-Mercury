#include "windows.h"
#include "Partita.hpp"

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
    obsQueue = Queue();
    boostQueue = Queue();
    bt = Boost();
    ot = Ostacolo();
    //coda = Coda(100);

    punti = 0;
    x = length/2;
    y = height-1;
    input = 0;
    cstamp = 0;

    t = time();
    delay = 200;

    livello = 1;

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
	cout << "dimensione coda: " << obsQueue.getDim() << " ";

    setCursorPosition(l, 1,95);
    cout << "dimensione lista: " << boostQueue.getDim() << " ";

    if(obsQueue.checkCollision(a.getX(), a.getY()) || boostQueue.checkCollision(a.getX(), a.getY()))
    {
        setCursorPosition(l,2,95);
        cout << "collisione:  true";
    }
    else
    {
        setCursorPosition(l,2,95);
        cout << "collisione: false";
    }

    setCursorPosition(l,3,95);
    cout << "punteggio: " << punti << " ";

    setCursorPosition(l,4,95);
    cout << "livello: " << livello << " ";

    setCursorPosition(l,5,95);
    cout << "danno: " << ot.getDamage() << " ";

    setCursorPosition(l,6,95);
    cout << "delay: " << delay << " ";

    // setCursorPosition(l,7,95);
    // cout << "spawn counter: " << cstamp << " ";
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
    // int maxspawn = 0;
    // int cstamp = 0;
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

		setCursorPosition(0, 0, 0); //toglie i flickering
		obsQueue.print();
        boostQueue.print();
		a.stampa();

		processInput(input);
		input = 0;

		a.setPos(x,y);

        if (delay <= 100)
            delay = 100;
        else if (delay >= 200)
            delay = 200;

        if(time() - t > delay)
        {
            bordo();
            t = time();
            punti += 1;

            // spawn method
            if (setRandomSpawn() == 1)
            {
                // if (cstamp > maxspawn)
                //     maxspawn = cstamp;
                cstamp = 0;
                Boost b(getRandomX());
                boostQueue.enQ(b);
            }
            if (livello < 21)
            { //spawn aggiuntivo in caso ci siano pochi boost all'inizio
                if (cstamp < 40)
                {
                    cstamp++;
                }
                else
                {
                    cstamp = 0;
                    Boost b(getRandomX());
                    boostQueue.enQ(b);
                }
            }
            //////////////////////////////////
            boostQueue.move();
            boostQueue.checkLimit(getHeight());

            // if (o.getX() != b.getX())
            // {
            // }
            Ostacolo o(getRandomX());
            obsQueue.enQ(o);
            obsQueue.move();
            obsQueue.checkLimit(getHeight());

            setCursorPosition(70, 20, 0);
            if (boostQueue.checkCollision(a.getX(), a.getY()))
            {
                punti += bt.getPoints();
            }
            if (obsQueue.checkCollision(a.getX(), a.getY()))
            {
                punti -= ot.getDamage();
            }

            if (punti >= 100)
            {
                ot.upDamage();
                punti = 0;
                livello += 1;
                delay -= 5;
            }
            if (punti < 0)
            {
                if (livello <= 20)
                {
                    ot.downDamage();
                    delay += 5;
                }
                punti = 0;
                livello -= 1;
            }
        }
        if(livello < 1) break;
        stampaInfo();
    }

    cls();
    setCursorPosition(length-10, height/2, 16);
    cout << "perso sfigato gay";
    // setCursorPosition(length-3, (height/2) + 1, 16);
    // cout << maxspawn;
    Sleep(1500);
}