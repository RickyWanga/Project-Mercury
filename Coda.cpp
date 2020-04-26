#include "Coda.hpp"
#include "Ostacolo.hpp"
using namespace std;

Coda::Coda(int n)
{
    arr = new Ostacolo[n];
    max_dim = n;
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

void Coda::deq() //distruggere l'elemento?
{
    if(!isEmpty())
    {
        testa = (testa + 1) % max_dim;
        dim--;
    }
}

void Coda::enq(Ostacolo e)
{
    if(!isFull())
    {
        retro = (retro + 1) % max_dim;
        arr[retro] = e;
        dim++;
    }
}

Ostacolo Coda::getTesta()
{
    return arr[testa];
}

Ostacolo Coda::getOstacolo(int pos)
{
    return arr[pos];
}

Ostacolo& Coda::getOstacoloByRef(int pos)
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