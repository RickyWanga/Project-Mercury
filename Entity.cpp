#include "Entity.hpp"
using namespace std;

Entity::Entity(int x, int y, char _c)
{
    setPos(x,y);
    c = _c;
}

int Entity::getX()
{
    return pos.x;
}

int Entity::getY()
{
    return pos.y;
}

int Entity::setPos(int x, int y)
{
    pos.x = x;
    pos.y = y;
}

void Entity::moveDown()
{
    pos.y++;
}

char Entity::getChar()
{
    return c;
}
