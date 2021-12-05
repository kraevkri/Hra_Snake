#include "Jidlo.h"

char Jidlo::jidlochar;

void Jidlo::generujJidlo()

{
    pozice.X = (rand() % (sirka-2)) +1;
    pozice.Y = (rand() % (vyska-2)) +1;
}

COORD Jidlo::ziskatPozici()
{
    return pozice;
}
