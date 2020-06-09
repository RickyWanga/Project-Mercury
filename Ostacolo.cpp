#include "Ostacolo.hpp"

Ostacolo::Ostacolo(int x):Entity(x, 0, 178, 4)
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

void Ostacolo::setDamage(int d)
{
	damage = d;
}
