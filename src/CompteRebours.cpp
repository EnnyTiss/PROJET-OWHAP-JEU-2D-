#include "CompteRebours.h"
#include <cassert>
#include <iostream>
#include <time.h>

using namespace std;



CompteRebours::CompteRebours(){
    val = 60;
    valMin = 0;
    valMax = 60;
    actifCompteur = true;
}

CompteRebours::CompteRebours(int v, int vMin, int vMax, bool actif){
    val = v;
    valMin = vMin;
    valMax = vMax; 
    actifCompteur = true;
}

void CompteRebours::setVal(int v){
    val = v;
}

void CompteRebours::setActif(bool b){
    assert(actifCompteur != b);
    actifCompteur = b;
}

int CompteRebours::getValMin() const{

}

int CompteRebours::getValMax() const{

}
void CompteRebours::GameOver() {
    assert(val==0);
    setActif(false);
    cout<<"Temps écoulé, vous avez perdu ! "<<endl;
}

void CompteRebours::reinitialiser(){
    assert(val == 0);
    setVal(valMax);
    setActif(true);
    
}

void CompteRebours::ecoulementRebours(){
    assert(actifCompteur==true);
    clock_t chrono;
    double temps = 0;
    int secondes_restantes;

    while (secondes_restantes > 0)
    {

        secondes_restantes = valMax - temps;

        //...Jeu
        temps = (int(clock() - temps) / 1000);

        system("cls");
        std::cout << "Temps restant : " << secondes_restantes << "\n";

    }
}