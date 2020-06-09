#pragma once

#include <iostream>
#include <stdint.h>
#include <chrono>
#include "Queue.hpp"
#include "Boost.hpp"
#include "Ostacolo.hpp"
#include "setCursorPosition.hpp"

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
        Boost bt;
        Ostacolo ot;
        //Coda coda;

        uint64_t t;
        uint64_t delay;

        int livello;
        // int danno;

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