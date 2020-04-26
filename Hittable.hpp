#pragma once

#include "Entity.hpp"

class Hittable:public Entity
{
    protected:
        int point;

    public:
        Hittable(int x, int y, char _c);
        Hittable();
        void moveDown();
        int getPoint();
};