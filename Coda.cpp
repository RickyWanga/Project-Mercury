#include "Coda.hpp"
using namespace std;

Coda::Coda(int n)
{
    arr = new int[n];
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

void Coda::enq(int i)
{
    if(!isFull())
    {
        retro = (retro + 1) % max_dim;
        arr[retro] = i;
        dim++;
    }
}

int Coda::getRetro()
{
    return arr[retro];
}