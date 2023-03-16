#include "Timer.h"
#include <cassert>
#include <iostream>
#include <time.h>
#include "Timer.h"

using namespace std;



Timer::Timer(){
    val = 60;
    valMin = 0;
    valMax = 60;
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

int Timer::getValMin() const{

}

int Timer::getValMax() const{

}
void Timer::GameOver() {
    //assert(val==60);
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
    clock_t debut = clock() ;
    clock_t fin;
    double temps = 0;
    int secondes_restantes;

    while (secondes_restantes > 0)
    {

        secondes_restantes = valMax - temps;

        //...Jeu
        temps = (int(clock() - temps) / 1000);
        assert(secondes_restantes>=0);
        return secondes_restantes;

    }
}