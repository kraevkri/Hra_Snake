#include <iostream>
#include <conio.h>
#include <ctime>
#include "Had.h"
#include "Jidlo.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define sirka 50
#define vyska 25


using namespace std;

Had had({sirka/2, vyska/2}, 1); //vykresleni hada (1 je rychlost - po jednom policku)
Jidlo jidlo;

int body;

void nazev()
{
    cout << "\t\t\t\t#           #" << "\t        ##        " << "\t##########   " << endl;
    cout << "\t\t\t\t#           #" << "\t       #  #       " << "\t#         #  " << endl;
    cout << "\t\t\t\t#           #" << "\t      #    #      " << "\t#          # " << endl;
    cout << "\t\t\t\t#           #" << "\t     #      #     " << "\t#          # " << endl;
    cout << "\t\t\t\t#############" << "\t    ##########    " << "\t#          # " << endl;
    cout << "\t\t\t\t#           #" << "\t   #          #   " << "\t#          # " << endl;
    cout << "\t\t\t\t#           #" << "\t  #            #  " << "\t#          # " << endl;
    cout << "\t\t\t\t#           #" << "\t #              # " << "\t#         #  " << endl;
    cout << "\t\t\t\t#           #" << "\t#                #" << "\t##########   " << endl;

    cout << "Zadejte symbol hada. (#,@)" << endl;
    cin >> Had::hadchar;
    if (Had::hadchar!= '#' && Had::hadchar!= '@'){
        exit(1);
    }

    cout << "Zadejte symbol jidla. (0,1)" << endl;
    cin >> Jidlo::jidlochar;
    if (Jidlo::jidlochar!= '0' && Jidlo::jidlochar!= '1'){
        exit(1);
    }

    system("CLS");

    //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
}

void plocha()
{

    COORD poziceHada = had.ziskatPozici();
    COORD poziceJidla = jidlo.ziskatPozici();

    vector <COORD> telo_hada = had.ziskat_telo();

    for(int i = 0; i < vyska; i++) // skript pro plochu
    {
        cout << "\t\t\t|";

        for(int j = 0; j < sirka-2; j++) // protože to má 2 steny (2 hrany proto -2) // skript pro plochu
        {
            bool telohada = false;

            if(i==0 || i==vyska-1) cout << '-'; // -1 protože to je vykreslení spodní a horní stìny

            else if(i==poziceHada.Y && j+1==poziceHada.X) cout << Had::hadchar; // objekt hada po y a x
            else if(i==poziceJidla.Y && j+1==poziceJidla.X) cout << Jidlo::jidlochar; // objekt hada po y a x

            else
            {
                for(int k = 0; k < telo_hada.size()-1; k++)
                {
                    if(i==telo_hada[k].Y && j+1==telo_hada[k].X)
                    {
                        cout << Had::hadchar;
                        telohada = true;
                        break;
                    }
                }
                if(!telohada) cout << ' ';
            }

        }

        cout << "|\n";
    }
}


int main()
{
    nazev();

    body = 0;

    srand(time(NULL)); //random generator cisel

    jidlo.generujJidlo();

    bool konecHry = false;

    while(!konecHry)
    {
        plocha();

        if(kbhit()) // stisknuty klavesy
        {
            switch(getch()) //getch nám dá klávesu kterou zmackneme
            {
                case 'w': had.zmenaSmeru('s'); break;
                case 's': had.zmenaSmeru('j'); break;
                case 'a': had.zmenaSmeru('z'); break;
                case 'd': had.zmenaSmeru('v'); break;
            }
        }

        if(had.narazil())
        {
            konecHry = true;
            cout << "\n\n\n\t\t\tKONEC HRY\n\t\t\tbody=";
            cout << body;
        }

        if(had.snezeno(jidlo.ziskatPozici()))
        {
            jidlo.generujJidlo();
            had.rust();
            body = body+1;
        }

        had.pohniHada();

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0}); //místo cls, kde bliká obrazovka

    }
}
