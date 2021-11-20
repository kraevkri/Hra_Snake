#ifndef HAD_H
#define HAD_H

#include <windows.h>

#define sirka 50
#define vyska 25

class Had
{
    private:
        COORD pozice;
        int delka;
        int rychlost;
        char smerHada;

    public:
        Had(COORD pos, int rychlost);
        void zmenaSmeru(char smer);     //meni smer
        void pohniHada();               //dava pohyb
        void rust();

        COORD ziskatPozici();

        bool snezeno(COORD jidlo);
        bool narazil();

};

#endif // HAD_H
