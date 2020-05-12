#pragma once
#include "Ostacolo.hpp"

class Coda
{
    protected:
        Entity *arr;    //array
        int max_dim; //dimensione max
        int testa;   //indicie della testa
        int retro;    //indice del retro
        int dim;     //dimensione attuale
        int k;      //indice globale di stampArr
        int stampArr[]; //array dedicato alle posizioni degli elementi che collidono

    public:
        Coda();
        Coda(int n);

        int getDim();
        bool isEmpty();
        bool isFull();
        void enq(Entity e);
        void deq();
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