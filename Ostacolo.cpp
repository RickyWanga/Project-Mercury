#include "Ostacolo.hpp"
#include "Partita.hpp"

Ostacolo::Ostacolo(int x, int y, int hL):Entity(x, y, 'O')
{
    heightLimit = hL;
}

void Ostacolo::moveDown()
{
    if(pos.y+1 < heightLimit)
    {
        setBuffer();
        pos.y++;
    }
}