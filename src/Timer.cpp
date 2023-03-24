#include <cassert>
#include <iostream>
#include <time.h>
#include "Timer.h"

using namespace std;



Timer::Timer(){
    val = 60;
    valMin = 0;
    valMax = 10;
    actifCompteur = true;
    debut =0;
}

Timer::Timer(int v, int vMin, int vMax, bool actif){
    val = v;
    valMin = vMin;
    valMax = vMax; 
    actifCompteur = actif;
    debut=int (time(nullptr));
}

void Timer::setVal(int v){
    val = v;
}

void Timer::setActif(bool b){
    actifCompteur = b;
}

int Timer::getValMax() const
{
    return valMax;
}

int Timer::getdebut() const
{
    return debut;
}






void Timer::reinitialiser(){
    setActif(true);
    
}


int Timer::ecoulementTimer(int debut) const
{
    
    int t =time(nullptr)-debut;
    float temps = int(t);
    if (actifCompteur==false) {temps=666;}
    return temps;

}