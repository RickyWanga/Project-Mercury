#pragma once

#include "Entity.hpp"

class Hittable:public Entity
{
    private:
        int points;

    public:
        Hittable(int x, int p, bool ostacolo);
        Hittable();
        int getPoints();
        void setPoints(int p);
        void moveDown();
};