#ifndef HAD_H
#define HAD_H

#include <windows.h>

class Had
{
    private:
        COORD poz;
        int delka;
        int rychlost;
        char smerHada;

    public:
        Had(COORD pos, int rychlost);
        void zmenaSmeru(char smer);     //meni smer
        void pohniHada();               //dava pohyb

        COORD ziskatPozici();
};

#endif // HAD_H
