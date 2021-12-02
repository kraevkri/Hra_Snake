#ifndef JIDLO_H
#define JIDLO_H
#include <windows.h>
#include <cstdio>


#include<cstdlib>
#define sirka 50
#define vyska 25

class Jidlo
{
    private:
        COORD pozice;
    public:
        void generujJidlo();
        COORD ziskatPozici();
        static char jidlochar;
};

#endif // JIDLO_H
