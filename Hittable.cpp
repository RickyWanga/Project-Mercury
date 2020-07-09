#include "Hittable.hpp"
#include "Partita.hpp"

Hittable::Hittable(int x, int p, bool ostacolo):Entity(x)
{
    if(ostacolo)
    {
        Entity::setChar(178);
        Entity::setColor(4);
    }
    else
    {
        Entity::setChar('o');
        Entity::setColor(11);
    }

    points = p;
}

Hittable::Hittable()
{

}

void Hittable::moveDown()
{
    Entity::setPos(getX(), getY()+1);
}

int Hittable::getPoints()
{
    return points;
}

void Hittable::setPoints(int p)
{
    points = p;
}