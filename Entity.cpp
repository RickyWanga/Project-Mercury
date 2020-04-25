#include "Entity.hpp"

Entity::Entity(int x, int y, char _c)
{
    setPos(x,y);
    buffer.x = 0;
    buffer.y = 0;
    c = _c;
}

Entity::Entity()
{

}

int Entity::getX()
{
    return pos.x;
}

int Entity::getY()
{
    return pos.y;
}

int Entity::getBufferX()
{
    return buffer.x;
}

int Entity::getBufferY()
{
    return buffer.y;
}

void Entity::setPos(int x, int y)
{
    setBuffer();
    pos.x = x;
    pos.y = y;
}

void Entity::setBuffer()
{
    buffer.x = pos.x;
    buffer.y = pos.y;
}



char Entity::getChar()
{
    return c;
}
