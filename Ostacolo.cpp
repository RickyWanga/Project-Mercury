#include "Ostacolo.hpp"
#include "Partita.hpp"

Ostacolo::Ostacolo(int x, int hL):Entity(x, 0, 'O')
{
    heightLimit = hL;
}

Ostacolo::Ostacolo()
{

}

void Ostacolo::moveDown()
{
    setPos(getX(), getY()+1);
}