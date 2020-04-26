#pragma once

#include "Entity.hpp"

class Boost:public Entity
{

    public:
        Boost(int x);
        Boost(int x, int y);
        Boost();
        void moveDown();
};