#ifndef HAD_H
#define HAD_H

#include <windows.h>
#include <vector>

#define sirka 50
#define vyska 25

using namespace std;

class Had
{
    private:
        COORD pozice;
        int delka;
        int rychlost;
        char smerHada; //nebo string (øetìzec)
        vector<COORD> telo;

    public:
        Had(COORD pos, int rychlost);
        void zmenaSmeru(char smer);     //meni smer
        void pohniHada();               //dava pohyb
        void rust();
        static char hadchar;

        vector<COORD> ziskat_telo();

        COORD ziskatPozici();

        bool snezeno(COORD jidlo);
        bool narazil();

};

#endif // HAD_H
