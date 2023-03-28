#ifndef _BARREPROG_H
#define _BARREPROG_H
#include "Timer.h"

class BarreProg {
private :
int temps;
Timer timerBR;
int taille;
char tab[19];


public :
BarreProg();
BarreProg(int temps);

int getNow() const;
const int getTaille()const;
unsigned char getC (const int x) const;
Timer& getTimerBR() ;
const Timer& getTimerBR() const;
};


inline const int BarreProg::getTaille() const {return taille;}
inline Timer& BarreProg::getTimerBR()  {return timerBR;}
inline const Timer& BarreProg::getTimerBR() const {return timerBR;}






#endif