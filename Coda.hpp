#pragma once
#include "Ostacolo.hpp"

class Coda
{
    protected:
        Entity *arr;    //array
        int max_dim; //dimensione max
        int testa;   //puntatore alla testa
        int retro;    //puntatore al retro
        int dim;     //dimensione attuale

    public:
        Coda(int n);
        Coda();

        int getDim();
        bool isEmpty();
        bool isFull();
        void deq();
        void enq(Entity e);
        Entity getTesta();
        Entity getOstacolo(int pos);
        Entity& getOstacoloByRef(int pos);
        int getPosTesta();
        int getMaxDim();

        void checkLimite(int limite);
        void move();
        void stampa();

        bool checkCollisioni(int x, int y);
};