#include "Evenement.h"
#include <iostream>
using namespace std;

    Evenement::Evenement(){
        idEvent=0;
        actif=false;
    }

    Evenement::Evenement(int id, bool dejaAct){
        idEvent = id;
        actif=dejaAct;

    }

    int Evenement::getIdEvent() const{
        return idEvent;
    }

    bool Evenement::getActif() const {
        if (actif) return true;
        else return false;

    }



    void Evenement::setActif(bool b){
        actif=b;
    }
