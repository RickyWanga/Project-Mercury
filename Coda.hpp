class Coda
{
    private:
        int *arr;    //array
        int max_dim; //dimensione max
        int testa;   //puntatore alla testa
        int retro;    //puntatore al retro
        int dim;     //dimensione attuale

    public:
        Coda(int n);

        void deq();
        void enq(int i);
        bool isEmpty();
        bool isFull();
        int getDim();
        int getRetro();
};
