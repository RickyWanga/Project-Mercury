#include "Coda.hpp"
#include "Ostacolo.hpp"
#include <windows.h>
#include "setCursorPosition.hpp"
#include <conio.h>
#include <iostream>
using namespace std;

Coda::Coda()
{
}

Coda::Coda(int n)
{
    arr = new Entity[n];
    stampArr[n];
    max_dim = n;
    k = 0;
    testa = 0;
    retro = -1;
    dim = 0;
}

int Coda::getDim()
{
    return dim;
}

bool Coda::isEmpty()
{
    return (dim == 0);
}

bool Coda::isFull()
{
    return (dim == max_dim);
}

void Coda::enq(Entity e)
{
    if(!isFull())
    {
        retro = (retro + 1) % max_dim;
        arr[retro] = e;
        dim++;
    }
}

void Coda::deq() //distruggere l'elemento(?)
{
    if(!isEmpty())
    {
        testa = (testa + 1) % max_dim;
        dim--;
    }
}

Entity Coda::getTesta()
{
    return arr[testa];
}

Entity Coda::getOstacolo(int pos)
{
    return arr[pos];
}

Entity& Coda::getOstacoloByRef(int pos)
{
    return arr[pos];
}

int Coda::getPosTesta()
{
    return testa;
}

int Coda::getMaxDim()
{
    return max_dim;
}

void Coda::checkLimite(int limite)
{
    if(getTesta().getY() > limite && getDim() > 0)
	{
		setCursorPosition(getTesta().getBufferX(), getTesta().getBufferY(),247);
		cout << "-";
		deq();
	}
}

void Coda::move() //fa il moveDown degli ostacoli
{
	for(int i = 0; i<getDim(); i++)
	{
		int pos = (getPosTesta()+i)%getMaxDim();
		getOstacoloByRef(pos).moveDown();
	}
}

void Coda::stampa()
{
    //bool found = false;

	for (int i = 0; i<getDim(); i++)
    {
        int pos = (getPosTesta()+i)%getMaxDim();

        // for (int j = 0; j<getMaxDim(); j++)
        // {
        //     if (pos == stampArr[j])
        //     {
        //         found = true;
        //         break;
        //     }
        // }

        //if (!(found))
        getOstacolo (pos).stampa();

        //found = false;
    }
}

bool Coda::checkCollisioni(int x, int y)
{
    for(int i = 0; i<getDim(); i++)
	{
		int pos = (getPosTesta()+i)%getMaxDim();
		if(getOstacolo(pos).getX() == x && getOstacolo(pos).getY() == y)
        {
            // if (k == getMaxDim())
            //     k = 0;

            // stampArr[k] = pos;
            // k++;
            return true;
        }
	}
    return false;
}