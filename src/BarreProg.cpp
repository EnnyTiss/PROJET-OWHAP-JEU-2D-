#include "BarreProg.h"


BarreProg::BarreProg() 
{
    
    taille=19;
	const char tabX[20]= {

  "------0-----0-----0",

	};
    timerBR=Timer(0,0,10,true);



	for(int x=0;x<20;x++)
		{tab[x]=tabX[x];
		}

}

BarreProg::BarreProg(int temps) //constructeur (avec le temps modifiable)
{
    
    taille=19;
	const char tabX[20]= {

 "------0-----0-----0",

	};
    timerBR=Timer(0,0,temps,true);



	for(int x=0;x<21;x++)
		{tab[x]=tabX[x];
		}

}

unsigned char BarreProg::getC (const int x) const // affiche le charactère numéro x à sa place
{
	return tab[x];
}

int BarreProg::getNow() const //sert à connaitre la position sur la barre à l'instant t
{
    int result =777;
   if (timerBR.getActif())
    {result = (timerBR.ecoulementTimer(timerBR.getdebut()))*(taille)/timerBR.getValMax();}

    return result;
}