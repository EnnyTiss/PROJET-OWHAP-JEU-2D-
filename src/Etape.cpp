#include "Etape.h"


    Etape::Etape() {
     timer=Timer();
     E1=Evenement();
     E2=Evenement();
     E3=Evenement();

    }


    Evenement Etape::getEvenement(int i)
    {
        if (i==1) {return E1;}
        if (i==2) {return E2;}
        if (i==3) {return E3;}
        else return E1;

    }

    bool Etape::estEtape(Timer t)
    {
        if (t.ecoulementTimer()==t.getValMax()/1000*1/3) {return true;}
        if (t.ecoulementTimer()==t.getValMax()/1000*2/3) {return true;}
        //if (timer.ecoulementTimer()==0) {return true;}
        else return false;
    }

