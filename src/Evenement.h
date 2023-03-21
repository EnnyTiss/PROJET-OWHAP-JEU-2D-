#ifndef _EVENEMENT_H
#define _EVENEMENT_H

#include "Timer.h"
#include "cassert"

class Evenement {
    private:

    int idEvent;
    bool actif;
    

    public:

    Evenement();
    Evenement(int id,  bool dejaAct);

    int getIdEvent() const;
    bool getActif() const;

    void setActif(bool b);

};

#endif