#ifndef _JEU_H
#define _JEU_H
#include "cassert"
#include "Perso.h"
#include "Vaisseau.h"
#include "Objet.h"
#include "Timer.h"


class Jeu {

private :

	Vaisseau v;
	Perso p;
    Objet tabo[8];
    Timer timer;
	

public :

    Jeu ();

    const Vaisseau& getVaisseau () const;                        //< \brief accesseur nécesseaire pour l'affichage
    const Perso& getPerso () const;                          //< \brief accesseur nécesseaire pour l'affichage
    Objet getObjet (int id) const; 
    Objet& getObjet (int id);
    Timer getTimer() const ;
    Timer& getTimer();

    bool actionClavier(const char touche);   
    bool PersoPresDeObjet();       
    void interationdemande();
};

inline const Vaisseau& Jeu::getVaisseau () const { return v; }         // du code court comme ca doit être en inline

inline const Perso& Jeu::getPerso () const { return p; }

inline Objet& Jeu::getObjet(int id) { return tabo[id]; }

inline Timer& Jeu::getTimer() {return timer;}

#endif