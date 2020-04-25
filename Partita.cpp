#include "Partita.hpp"

Partita::Partita(int l, int h)
{
    length = l;
    height = h;
}

int Partita::getLength()
{
    return length;
}

int Partita::getHeight()
{
    return height;
}