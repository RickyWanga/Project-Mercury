#pragma once
#include "Entity.hpp"

class Ostacolo:public Entity
{
    protected:
        int damage = 10;

    public:
        Ostacolo(int x);
        Ostacolo();
        int getDamage();
        void upDamage();
        void downDamage();
        void setDamage(int d);
        // Ostacolo(int x, int y);
        // Ostacolo(int x, int y, int p);
};