#pragma once

#include "Hittable.hpp"

class Boost:public Hittable
{

    public:
        Boost(int x);
        Boost(int x, int y);
        Boost();
        void moveDown();
        int getPoint();
};