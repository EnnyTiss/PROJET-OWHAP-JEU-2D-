#include "Timer.h"
#include <cassert>
#include <iostream>
#include <time.h>
#include "Timer.h"

using namespace std;



Timer::Timer(){
    val = 60;
    valMin = 0;
    valMax = 10000;
    actifCompteur = true;
}

Timer::Timer(int v, int vMin, int vMax, bool actif){
    val = v;
    valMin = vMin;
    valMax = vMax; 
    actifCompteur = actif;
}

void Timer::setVal(int v){
    val = v;
}

void Timer::setActif(bool b){
    assert(actifCompteur != b);
    actifCompteur = b;
}

int Timer::getValMax() const
{
    return valMax*1000;
}



void Timer::GameOver() {
    
    setActif(false);
    cout<<"Temps écoulé, vous avez perdu ! "<<endl;
}

void Timer::reinitialiser(){
    setActif(true);
    
}

int Timer::ecoulementTimer() const{
    assert(actifCompteur==true);
    
    int temps=0;
    temps = (int(clock()) / 1000);
    return temps/1000;
 
}