#ifndef _EVENEMENT_H
#define _EVENEMENT_H

#include "Timer.h"
#include "cassert"

class Evenement {
    public:

    int idEvent;
    Timer timer;
    bool dejaActive;

    private:

    Evenement();
    Evenement(int id, Timer t, bool dejaAct);

    int getIdEvent() const;
    Timer getTimer() const;
    bool getDejaActive() const;

    void setDejaActive(bool b);





};

#endif