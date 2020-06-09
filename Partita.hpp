#pragma once

#include <iostream>
#include <stdint.h>
#include <chrono>
#include "Queue.hpp"
#include "Auto.hpp"
#include "Boost.hpp"
#include "Ostacolo.hpp"
#include "setCursorPosition.hpp"
//#include "Coda.hpp"

class Partita
{
    private:
        int length;
        int height;
        int punti;
        int x;
        int y;
        int input;
        int cstamp;
        Auto a;
        Queue obsQueue;
        Queue boostQueue;
        //Coda coda;

        uint64_t t;
        uint64_t delay;

        int livello;
        int danno;

        int getLength();
        int getHeight();
        void bordo();
        void stampaInfo();
        int getRandomX();
        int setRandomSpawn();

        void processInput(int c);
        uint64_t time();

    public:
        Partita(int l, int h);
        void start();
};