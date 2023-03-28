#ifndef _ETAPE_H
#define _ETAPE_H

#include "Timer.h"
#include "Evenement.h"
#include "cassert"

class Etape {
    private:
    Timer timer;
    Evenement E1;
    Evenement E2;
    Evenement E3;

    public:

    Etape();
    Etape(int temp);

    Evenement getEvenement(int i);
    bool estEtape(Timer t);
    int getEtapenum();
    Timer getTimerEtape();


};

#endif