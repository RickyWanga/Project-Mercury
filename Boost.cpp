#include "Boost.hpp"
#include "Partita.hpp"

Boost::Boost(int x):Hittable(x, 0, 'B')
{
}

Boost::Boost(int x, int y):Hittable(x, y, 'B')
{
}

Boost::Boost(int x, int y, int p):Hittable(x, y, p, 'B')
{
}


Boost::Boost()
{

}