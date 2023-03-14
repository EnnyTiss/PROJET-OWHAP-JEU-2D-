#include "Timer.h"
#include <cassert>
#include <iostream>
#include <time.h>
#include "Timer.h"

using namespace std;



Timer::Timer(){
    val = 60;
    valMin = 0;
    valMax = 600000;
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


void Timer::GameOver() {
    assert(val==0);
    setActif(false);
    cout<<"Temps écoulé, vous avez perdu ! "<<endl;
}

void Timer::reinitialiser(){
    assert(val == 0);
    setVal(valMax);
    setActif(true);
    
}

int Timer::ecoulementTimer(){
    assert(actifCompteur==true);
    
    int temps=0;
    temps = (int(clock()) / 1000);
    return temps;
    /*do{
    
        temps = (int(clock()) / 1000);

        return temps;

        if (temps ==1000)
        {break;}

    }while(temps<60);*/
}