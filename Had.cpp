#include "Had.h"
#include<conio.h>

Had::Had(COORD pozice, int rychlost)
{
    this->pozice=pozice;
    this->rychlost=rychlost;
    delka=1;
    smerHada='n';

    telo.push_back(pozice);

}

void Had::zmenaSmeru(char smer){smerHada=smer;}

vector<COORD> Had::ziskat_telo() { return telo; }

void Had::pohniHada()
{
    switch(smerHada)
        {
            case 's': pozice.Y -=rychlost; break;
            case 'j': pozice.Y +=rychlost; break;
            case 'z': pozice.X -=rychlost; break;
            case 'v': pozice.X +=rychlost; break;

        }

        telo.push_back(pozice);
        if(telo.size() > delka) telo.erase(telo.begin());
}


COORD Had::ziskatPozici() {return pozice;}

bool Had::snezeno(COORD poziceJidla)
{
    if(poziceJidla.X==pozice.X&&poziceJidla.Y==pozice.Y) return true;
    else return false;
}

void Had::rust() {delka++;}

bool Had::narazil()
{
    if(pozice.X<1||pozice.X>sirka-1||pozice.Y<1||pozice.Y>vyska-1) return true;
    return false;
}
