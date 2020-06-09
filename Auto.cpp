#include "Auto.hpp"

using namespace std;

Auto::Auto(int x, int y):Entity(x, y, 143, 10)
{
	for (int i = 0; i < 4; i++)
	{
		buf[i].x = 0;
		buf[i].y = 0;
		car[i].x = 0;
		car[i].y = 0;
	}
}

Auto::Auto()
{
}

void Auto::setCar(int x, int y)
{
	setPos(x, y);
	setBuf();

	car[0].x = x - 1;
	car[1].x = x - 1;
	car[2].x = x + 1;
	car[3].x = x + 1;

	car[0].y = y - 1;
	car[1].y = y + 1;
	car[2].y = y - 1;
	car[3].y = y + 1;
}

void Auto::setBuf()
{
	for (int i = 0; i < 4; i++)
	{
		buf[i].x = car[i].x;
		buf[i].y = car[i].y;
	}
}

void Auto::printCar()
{
	if(getBufferX() != getX() || getBufferY() != getY())
	{
		setCursorPosition(getBufferX(), getBufferY(), 6);
		cout << " ";

		for (int i = 0; i < 4; i++)
		{
			setCursorPosition(buf[i].x, buf[i].y, 6);
			cout << " ";
		}
	}
	setCursorPosition(getX(), getY(), getColor());
	cout << getChar();

	for (int i = 0; i < 4; i++)
	{
		setCursorPosition(car[i].x, car[i].y, getColor());
		cout << "*";
	}
}

bool Auto::checkBounds(int x, int y)
{
	if ((x >= car[0].x && x <= car[2].x) && (y >= car[0].y && y <= car[1].y))
	{
		return true;
	}

	// setCursorPosition(70, 10, 95);
	// cout << x << " " << y << " ";
	// setCursorPosition(70, 11, 95);
	// cout << car[0].x << " " << car[2].x << " ";

	return false;
}