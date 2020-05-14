#include "Ostacolo.hpp"
#include "Partita.hpp"

Ostacolo::Ostacolo(int x):Entity(x, 0, 254, 4)
{
    color=4;
}

// Ostacolo::Ostacolo(int x, int y):Hittable(x, y, 'O',4)
// {
// }

// Ostacolo::Ostacolo(int x, int y, int p):Hittable(x, y, p,'O',4)
// {
// }

// Ostacolo::Ostacolo()
// {
// }

// int Ostacolo::getPoint(){
//     return -(point);
// }
