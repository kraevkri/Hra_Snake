#include <iostream>
#include <conio.h>
#include <ctime>
#include "Had.h"
#include "Jidlo.h"
// MAKROS

#define sirka 50
#define vyska 25



using namespace std;

Had had({sirka/2,vyska/2}, 1);
Jidlo jidlo;

int body;

void plocha()
{

    COORD poziceHada=had.ziskatPozici();
    COORD poziceJidla=jidlo.ziskatPozici();

    vector<COORD> had_telo = had.ziskat_telo();

    for(int i=0; i<vyska; i++)
    {
        cout<<"\t\t\t|";

        for(int j=0;j<sirka-2; j++)
        {
            if(i==0||i==vyska-1) cout<<'_';

            else if(i==poziceHada.Y && j+1==poziceHada.X) cout<<'o';
            else if(i==poziceJidla.Y&&j+1==poziceJidla.X) cout<<'@';

            else
            {
                bool telohada = false;
                for(int k = 0; k < had_telo.size()-1; k++)
                {
                    if(i== had_telo[k].Y && j+1 == had_telo[k].X)
                    {

                        cout << 'o';
                        telohada = true;
                        break;
                    }
            }

            if(!telohada) cout << ' ';
            }
        }

        cout<<"|\n";
    }
}


int main()
{
    body=0;


    srand(time(NULL));

    jidlo.generujJidlo();

    char konecHry = false;

    while(!konecHry)
    {
        plocha();


        if(kbhit())
        {
            switch(getch()){
                case 'w': had.zmenaSmeru('s'); break;
                case 's': had.zmenaSmeru('j'); break;
                case 'a': had.zmenaSmeru('z'); break;
                case 'd': had.zmenaSmeru('v'); break;
            }
        }

        if(had.narazil())
                {
                konecHry=true;

                cout<<"\n\n\n\t\t\tGAME OVER\n\t\t\tbody="; cout<<body;
                }

        if(had.snezeno(jidlo.ziskatPozici()))
        {
            jidlo.generujJidlo();
            had.rust();
            body=body+10;
        }

        had.pohniHada();

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});


    }






}
