#ifndef _BARREPROG_H
#define _BARREPROG_H
#include "Timer.h"

class BarreProg {
private :
int tempsfull;
int tempsEtape;
Timer timer;
int taille;
char tab[19];


public :
BarreProg();
int getTemps();
int getTempsEtape ();
int getNow() const;
const int getTaille()const;
unsigned char getC (const int x) const;




};

inline int BarreProg::getTemps() {return tempsfull;}
inline int BarreProg::getTempsEtape() {return tempsEtape;}
inline const int BarreProg::getTaille() const {return taille;}






#endif