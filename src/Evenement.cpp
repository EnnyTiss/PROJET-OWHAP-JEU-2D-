#include "Evenement.h"
#include <iostream>

    Evenement::Evenement(){
        idEvent=0;
        timer=Timer();
    }

    Evenement::Evenement(int id, Timer t, bool dejaAct){
        idEvent = id;
        timer = t;

    }

    int Evenement::getIdEvent() const{
        return idEvent;
    }

    Timer Evenement::getTimer() const{
        return timer;
    }



    void Evenement::setDejaActive(bool b){
        
    }
