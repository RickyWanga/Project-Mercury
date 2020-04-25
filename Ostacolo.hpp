#pragma once

#include "Entity.hpp"

class Ostacolo:public Entity
{
    int heightLimit;

    public:
        Ostacolo(int x, int hL);
        Ostacolo();
        void moveDown();
};