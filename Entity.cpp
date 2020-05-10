#include "Entity.hpp"
#include <windows.h>
#include "setCursorPosition.hpp"
#include <conio.h>
#include <iostream>
using namespace std;

Entity::Entity(int x, int y, char _c, int _color)
{
    setPos(x,y);
    buffer.x = 10;
    buffer.y = 10;
    c = _c;
    int color=_color;
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

void Entity::moveDown()
{
    setPos(getX(), getY()+1);
}

int Entity::getColor()
{
    return color;
}

void Entity::stampa()
{
	if(getBufferX() != getX() || getBufferY() != getY())
	{
		setCursorPosition(getBufferX(), getBufferY(),6);
		cout << " ";
	}
	setCursorPosition(getX(), getY(), getColor());
	cout << getChar();
}

