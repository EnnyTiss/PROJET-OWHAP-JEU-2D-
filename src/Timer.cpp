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
    decalage=0;
}

Timer::Timer(int v, int vMin, int vMax, bool actif){
    val = v;
    valMin = vMin;
    valMax = vMax; 
    actifCompteur = actif;
    debut=int (time(nullptr));
    decalage=0;
}

void Timer::setVal(int v){
    val = v;
}

void Timer::setDecalage(int v){
    decalage = decalage+v;
}

bool Timer::getActif() const{
    return actifCompteur;
}

int Timer::getDecalage() const{
    return decalage;
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
    setDecalage(0);
    setVal(60);
    
}


int Timer::ecoulementTimer(int debut) const
{
    
    int t =time(nullptr)-debut;
    float temps = int(t);
    if (actifCompteur==false) {temps=666;}
    return temps;

}