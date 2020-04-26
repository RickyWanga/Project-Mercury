#include "Hittable.hpp"
#include "Partita.hpp"

Hittable::Hittable(int x, int y, char _c):Entity(x, y, _c)
{
    point = 50;
}

Hittable::Hittable()
{

}


int Hittable::getPoint(){
    return point;
}