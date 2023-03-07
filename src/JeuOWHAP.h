#ifndef _JEUOWHAP_H
#define _JEUOWHAP_H

//#include "Personnage.h"
#include "Vaisseau.h"
//#include "Danger.h"
//#include "CompteRebours.h"

class JeuOWHAP {
    private:
    //Personage P;
    Vaisseau V;
    //BarreProgression BP;
    //Danger D;
    //CompteRebours CR;

    public:
    JeuOWHAP();
    ~JeuOWHAP();

    //const Personnage& getPersonnage();
    //const Danger& getDanger();
    //const CompteRebours& getCompteRebours();
    const Vaisseau& getConstVaisseau() const;
    JeuOWHAP resetJeuOWHAP();

 

 
};


#endif