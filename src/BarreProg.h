#ifndef _BARREPROG_H
#define _BARREPROG_H
#include "Timer.h"

class BarreProg {
private :
int temps;
Timer timer;
int taille;
char tab[19];


public :
BarreProg();
BarreProg(int temps);

int getNow() const;
const int getTaille()const;
unsigned char getC (const int x) const;

};


inline const int BarreProg::getTaille() const {return taille;}






#endif