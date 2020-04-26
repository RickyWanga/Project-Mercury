#include "Ostacolo.hpp"

class Coda
{
    private:
        Entity *arr;    //array
        int max_dim; //dimensione max
        int testa;   //puntatore alla testa
        int retro;    //puntatore al retro
        int dim;     //dimensione attuale

    public:
        Coda(int n);

        void deq();
        void enq(Entity e);
        bool isEmpty();
        bool isFull();
        int getDim();
        int getMaxDim();
        int getPosTesta();
        Entity getTesta();
        Entity getOstacolo(int pos);
        Entity& getOstacoloByRef(int pos);

        void checkLimite(int limite);
        void move();
        void stampa();

        bool checkCollisioni(int x, int y);
};