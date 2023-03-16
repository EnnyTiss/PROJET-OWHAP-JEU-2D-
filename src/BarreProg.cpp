#include "BarreProg.h"


BarreProg::BarreProg() 
{
    tempsfull=60;
    tempsEtape=20;
    taille=18;
	const char tabX[19]= {

 "-----0-----0-----0",

	};
    timer=Timer();


	for(int x=0;x<19;x++)
		{BarreProg::tab[x]=tabX[x];
		}

}

unsigned char BarreProg::getC (const int x) const
{
	return BarreProg::tab[x];
}

int BarreProg::getNow() const
{
    int result;
   // result=10;
    result = (timer.ecoulementTimer());//*taille*1000/timer.getValMax();

    return result;
}