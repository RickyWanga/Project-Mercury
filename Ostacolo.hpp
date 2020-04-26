#pragma once

#include "Hittable.hpp"

class Ostacolo:public Hittable
{

    public:
        Ostacolo(int x);
        Ostacolo(int x, int y);
        Ostacolo(int x, int y, int p);
        Ostacolo();
        void moveDown();
        int getPoint();
};