#pragma once

#include <iostream>
#include "setCursorPosition.hpp"

class Entity
{
    protected:
        struct Pos
        {
            int x;
            int y;
        };

        Pos pos;
        Pos buffer;
        int color;
        char c;
        void setChar(char _c);
        void setColor(int _color);

    public:
        Entity(int x, int y, char _c, int _color);
        Entity(int x);
        Entity();

        int getX();
        int getY();
        int getBufferX();
        int getBufferY();
        void setPos(int x, int y);
        void setPos(int x);
        void setBuffer();
        char getChar();

        void stampa();
        int getColor();
};