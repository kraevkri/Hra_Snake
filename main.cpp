#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "Had.h"

#define sirka 50
#define vyska 25

//had had had

using namespace std;

Had had({sirka/2,vyska/2}, 1);


void plocha()
{

    COORD poziceHada=had.ziskatPozici();

    for(int i=0; i<vyska; i++)
    {
        cout<<"\t\t\t#";
        for(int j=0;j<sirka-2; j++)
        {
            if(i==0||i==vyska-1) cout<<'#';
            else if(i==poziceHada.Y && j==poziceHada.X) cout<<'o';
            else cout<<' ';
        }
        cout<<"#\n";
    }
}


int main()
{
    while(true)
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
        had.pohniHada();

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});


    }






}
