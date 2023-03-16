#include "Evenement.h"
#include <iostream>

    Evenement::Evenement(){
        idEvent=0;
        timer=Timer();
        dejaActive=false;
    }

    Evenement::Evenement(int id, Timer t, bool dejaAct){
        idEvent = id;
        timer = t;
        dejaActive=dejaAct;

    }

    int Evenement::getIdEvent() const{
        return idEvent;
    }

    Timer Evenement::getTimer() const{
        return timer;
    }

    bool Evenement::getDejaActive() const{
        return dejaActive;
    }

    void Evenement::setDejaActive(bool b){
        
    }
