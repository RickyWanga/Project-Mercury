#include "Auto.hpp"
#include "Coda.hpp"
#include <stdint.h>
class Partita
{
    int length;
    int height;
    Auto a;
    Coda coda;
    int punti;

    int x;
    int y;
    int input;

    uint64_t t;
    uint64_t delay;

    int getLength();
    int getHeight();

    void processInput(int c);
    uint64_t time();

    public:
        Partita(int l, int h);
        void start();
};