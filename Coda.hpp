#include "Ostacolo.hpp"

class Coda
{
    private:
        Ostacolo *arr;    //array
        int max_dim; //dimensione max
        int testa;   //puntatore alla testa
        int retro;    //puntatore al retro
        int dim;     //dimensione attuale

    public:
        Coda(int n);

        void deq();
        void enq(Ostacolo e);
        bool isEmpty();
        bool isFull();
        int getDim();
        int getMaxDim();
        int getPosTesta();
        Ostacolo getTesta();
        Ostacolo getOstacolo(int pos);
        Ostacolo& getOstacoloByRef(int pos);
};