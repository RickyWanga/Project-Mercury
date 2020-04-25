#pragma once
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

        char c;

    public:
        Entity(int x, int y, char _c);
        Entity();

        int getX();
        int getY();
        int getBufferX();
        int getBufferY();
        void setPos(int x, int y);
        void setBuffer();
        char getChar();
};