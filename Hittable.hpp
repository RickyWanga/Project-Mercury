#pragma once

#include "Entity.hpp"

class Hittable:public Entity
{
    protected:
        int point;

    public:
        Hittable(int x, int y, char _c, int _color);
        Hittable(int x, int y, int p, char _c, int _color);
        Hittable();
        void moveDown();
        int getPoint();
};