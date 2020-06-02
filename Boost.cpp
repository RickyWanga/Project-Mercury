#include "Boost.hpp"

Boost::Boost(int x):Entity(x, 0, 248, 11)
{
    points = 15;
}

Boost::Boost()
{
}

int Boost::getPoints()
{
	return points;
}

// Boost::Boost(int x, int y):Hittable(x, y, 'B', 11)
// {
// }

// Boost::Boost(int x, int y, int p):Hittable(x, y, p, 'B', 11)
// {
// }