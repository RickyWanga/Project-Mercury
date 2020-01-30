class ObjectOnTrack{
    private:
        int x;
        int y = 0;
        char c;

    public:
        void updateY();
        void updateY(int y);
        void stampa();

        ObjectOnTrack(bool type);
};