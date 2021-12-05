#include "Had.h"
#include<conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define sleeptime 100000

char Had::hadchar;

Had::Had(COORD pozice, int rychlost)
{
    this->pozice = pozice;
    this->rychlost = rychlost;
    delka = 1;
    smerHada = 'n';

    telo.push_back(pozice); //prida symbol do tela
}

void Had::zmenaSmeru(char smer){smerHada = smer;} // funkce void nevraci zadnou hodnotu

vector <COORD> Had::ziskat_telo()
{
    return telo;
}

void Had::pohniHada()
{
    switch(smerHada) //zjednoduseny podminky if,else
        {
            case 's': pozice.Y -= rychlost; usleep(sleeptime*0.5); break; //nahoru //break pouziva se u switch a okamzite ukonci aktualni cyklus
            case 'j': pozice.Y += rychlost; usleep(sleeptime*0.5); break; //dolu
            case 'z': pozice.X -= rychlost; usleep(sleeptime*0.2); break; //doleva
            case 'v': pozice.X += rychlost; usleep(sleeptime*0.2); break; //doprava
        }

        telo.push_back(pozice); //znova po nejakej cyklu
        if(telo.size() > delka) telo.erase(telo.begin()); //rust hada
}

COORD Had::ziskatPozici()
{
    return pozice;
} // had:: - je tam protože je ta funkce definovana v souboru had

bool Had::snezeno(COORD poziceJidla)
{
    if(poziceJidla.X==pozice.X && poziceJidla.Y==pozice.Y) return true;
    else return false;
}

void Had::rust() {delka++;}

bool Had::narazil() //bool podmínka do které lze uložit pouze true/false
{
    if(pozice.X<1 || pozice.X>sirka-1 || pozice.Y<1 || pozice.Y>vyska-1) return true;
    return false;
}
