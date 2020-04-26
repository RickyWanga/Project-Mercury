#include "Ostacolo.hpp"
#include "Partita.hpp"

Ostacolo::Ostacolo(int x):Hittable(x, 0, 'O')
{
}

Ostacolo::Ostacolo(int x, int y):Hittable(x, y, 'O')
{
}

Ostacolo::Ostacolo()
{

}

int Ostacolo::getPoint(){
    return -(point);
}