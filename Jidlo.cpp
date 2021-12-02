#include "Jidlo.h"

char Jidlo::jidlochar = 0;

void Jidlo::generujJidlo()

{
    pozice.X=(rand() % (sirka-2)) +1; //-3 a +3 by mìlo fixnout mizení generování jídla z mapy
    pozice.Y=(rand() % (vyska-2)) +1;
}

COORD Jidlo::ziskatPozici(){return pozice;}
