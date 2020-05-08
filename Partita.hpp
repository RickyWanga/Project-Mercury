#pragma once

#include "Auto.hpp"
#include "Coda.hpp"
#include "listQueue.hpp"
#include "Boost.hpp"
#include <stdint.h>
class Partita
{
    private:
        int length;
        int height;
        int punti;
        int x;
        int y;
        int input;
        Auto a;
        Coda coda;
        Queue boostQueue;

        uint64_t t;
        uint64_t delay;

        int livello;
        int danno;

        int getLength();
        int getHeight();
        void bordo();
        void stampaInfo();
        int getRandomX();

        void processInput(int c);
        uint64_t time();

    public:
        Partita(int l, int h);
        void start();
};