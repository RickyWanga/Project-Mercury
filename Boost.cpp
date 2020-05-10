#include "Boost.hpp"
#include "Partita.hpp"

Boost::Boost(int x):Hittable(x, 0, 'B',11)
{
    color=11;
}

Boost::Boost(int x, int y):Hittable(x, y, 'B',11)
{
}

Boost::Boost(int x, int y, int p):Hittable(x, y, p, 'B',11)
{
}


Boost::Boost()
{

}