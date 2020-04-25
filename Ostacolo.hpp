#include "Entity.hpp"

class Ostacolo:public Entity
{
    int heightLimit;

    public:
        Ostacolo(int x, int y, int hL);
        void moveDown();
};