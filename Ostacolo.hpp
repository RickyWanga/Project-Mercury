#pragma once

#include "Entity.hpp"

class Ostacolo:public Entity
{

    public:
        Ostacolo(int x);
        Ostacolo(int x, int y);
        Ostacolo();
        void moveDown();
};