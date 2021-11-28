#include "Had.h"
#include<conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

Had::Had(COORD pozice, int rychlost)
{
    this->pozice=pozice;
    this->rychlost=rychlost;
    delka=1;
    smerHada='n';

    telo.push_back(pozice); //pøidá symbol do tela

}

void Had::zmenaSmeru(char smer){smerHada=smer;} // funkce void nevrací žádnou hodnotu

vector<COORD> Had::ziskat_telo() { return telo; }

void Had::pohniHada()
{
    switch(smerHada) //zjednoduseny podminky if,else
        {
            case 's': pozice.Y -=rychlost;sleep(0.99999999); break; //nahoru //break používá se u switch a okamžitì ukonèí aktualni cyklus
            case 'j': pozice.Y +=rychlost;sleep(0.99999999); break; //dolu
            case 'z': pozice.X -=rychlost;sleep(0.4); break; //doleva
            case 'v': pozice.X +=rychlost;sleep(0.4); break; //doprava

        }

        telo.push_back(pozice); //znova po nejakej cyklu
        if(telo.size() > delka) telo.erase(telo.begin()); //rust hada
}


COORD Had::ziskatPozici() {return pozice;} // had:: - je tam protože je ta funkce definovana v souboru had

bool Had::snezeno(COORD poziceJidla)
{
    if(poziceJidla.X==pozice.X&&poziceJidla.Y==pozice.Y) return true;
    else return false;
}

void Had::rust() {delka++;}

bool Had::narazil() //bool podmínka do které lze uložit pouze true/false
{
    if(pozice.X<1||pozice.X>sirka-1||pozice.Y<1||pozice.Y>vyska-1) return true;
    return false;
}
