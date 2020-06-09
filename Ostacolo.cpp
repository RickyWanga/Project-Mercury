#include "Ostacolo.hpp"

Ostacolo::Ostacolo(int x):Entity(x, 0, 254, 4)
{
}

Ostacolo::Ostacolo()
{
}

int Ostacolo::getDamage()
{
	return damage;
}

void Ostacolo::upDamage()
{
	damage += 5;
}

void Ostacolo::downDamage()
{
	damage -= 5;
}
// Ostacolo::Ostacolo(int x, int y):Hittable(x, y, 'O',4)
// {
// }

// Ostacolo::Ostacolo(int x, int y, int p):Hittable(x, y, p,'O',4)
// {
// }
