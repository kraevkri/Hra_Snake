#include "Jidlo.h"


void Jidlo::generujJidlo()

{
    pozice.X=(rand() % sirka-3) +3;
    pozice.Y=(rand() % vyska-3) +3;
}

COORD Jidlo::ziskatPozici(){return pozice;}
