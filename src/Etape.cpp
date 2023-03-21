#include "Etape.h"
#include <random>
#include <ctime>

    Etape::Etape() {
     timer=Timer(); timer = Timer(60,0,10,true);
     E1=Evenement();
     E2=Evenement();
     E3=Evenement();

    }

    Etape::Etape(int temp) {
     srand(time(0));
     timer=Timer(); timer = Timer(60,0,temp,true);
     E1=Evenement(rand() % 10,true);
     E2=Evenement(rand() % 10,true);
     E3=Evenement(rand() % 10,true);

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

    int Etape::getEtape()
    {
        int etape;
				 if (getTimerEtape().ecoulementTimer()<=(getTimerEtape().getValMax()/1000)*1/3) {etape=1;}
				 if (getTimerEtape().ecoulementTimer()<=(getTimerEtape().getValMax()/1000)*2/3 && getTimerEtape().ecoulementTimer()>=(getTimerEtape().getValMax()/1000)*1/3) {etape=2;}
				 if (getTimerEtape().ecoulementTimer()>=(getTimerEtape().getValMax()/1000)*2/3) {etape=3;}
        return etape;
    }

    Timer Etape::getTimerEtape()
    {
        return timer;
    }

