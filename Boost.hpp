#pragma once
#include "Entity.hpp"

class Boost:public Entity
{
    protected:
        int points;

    public:
        Boost(int x);
        Boost();
        int getPoints();
        // Boost(int x, int y);
        // Boost(int x, int y, int p);
};