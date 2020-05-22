#include "Hittable.hpp"
#include "Partita.hpp"

Hittable::Hittable(int x, int y, char _c,int _color):Entity(x, y, _c, _color)
{
    point = 50;
}

// Hittable::Hittable(int x, int y, int p, char _c, int _color):Entity(x, y, _c, _color)
// {
//     point = p;
// }

// Hittable::Hittable()
// {

// }

// int Hittable::getPoint(){
//     return point;
// }