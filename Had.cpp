#include "Had.h"

Had::Had(COORD poz, int rychlost)
{
    this->poz=poz;
    this->rychlost=rychlost;
    delka=1;
    smerHada='n';

}

void Had::zmenaSmeru(char smer){smerHada=smer;}

void Had::pohniHada()
{
    switch(smerHada)
        {
            case 's': poz.Y -=rychlost; break;
            case 'j': poz.Y +=rychlost; break;
            case 'z': poz.X -=rychlost; break;
            case 'v': poz.X +=rychlost; break;

        }
}


COORD Had::ziskatPozici() {return poz;}
