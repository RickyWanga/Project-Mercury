#pragma once
#include <iostream>
#include "Entity.hpp"

class Auto:public Entity
{
    protected:
        struct Car
        {
            int x;
            int y;
        };

        Car car[4];
        Car buf[4];

    public:
        Auto(int x, int y);
        Auto();
        void setCar(int x, int y);
        void setBuf();
        void printCar();
        bool checkBounds(int x, int y);
};