#pragma once

#include "Hittable.hpp"

class Boost:public Hittable
{

    public:
        Boost(int x);
        Boost(int x, int y);
        Boost(int x, int y, int p);
        Boost();
        void moveDown();
        int getPoint();
};