#pragma once
#include <iostream>
#include "Entity.hpp"

class Auto:public Entity
{
    public:
        Auto(int x, int y);
        Auto();
        void processInput(int c, int length);
};