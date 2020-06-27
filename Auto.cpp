#include "Auto.hpp"

using namespace std;

Auto::Auto(int x, int y):Entity(x, y, 143, 10)
{

}

Auto::Auto()
{
}

void Auto::processInput(int c, int length)
{
    int x = Entity::getX();
    switch(c)   // Gli spostamenti sono limitati all'asse X
    {
        case 77:
            if (x>=length)
                x=length;
            else
                x++;
            break;

        case 75:
            if (x<=0)
                x=0;
            else
                x--;
            break;
    }

    Entity::setPos(x);
}