class Entity
{
    protected:
        struct Pos
        {
            int x;
            int y;
        };

        Pos pos;

        char c;

    public:
        Entity(int x, int y, char _c);

        int getX();
        int getY();
        int setPos(int x, int y);
        void moveDown();
        char getChar();
};