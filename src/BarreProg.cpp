#include "BarreProg.h"


BarreProg::BarreProg() 
{
    
    taille=19;
	const char tabX[20]= {

 "0-----0-----0-----0",

	};
    timer=Timer(0,0,10,true);



	for(int x=0;x<20;x++)
		{BarreProg::tab[x]=tabX[x];
		}

}

BarreProg::BarreProg(int temps) 
{
    
    taille=18;
	const char tabX[20]= {

 "------0-----0-----0",

	};
    timer=Timer(0,0,temps,true);



	for(int x=0;x<20;x++)
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
    result = (timer.ecoulementTimer())*(taille*1000)/timer.getValMax();

    return result;
}