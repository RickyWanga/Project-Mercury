class Campo
{
    private:
        const int row = 25;
        const int col = 60;
        char campo[25][60];
        void inizializza();
        void bordi();

    public:
        void stampa();
        //inserisce il carattere c nella riga x e colonna y
        void inserisci(char c, int x, int y);
        void aggiorna();
        bool checkCollisions(int x, int y);

        Campo();
};