#ifndef _JEU_H
#define _JEU_H
#include "cassert"
#include "Perso.h"
#include "Vaisseau.h"
#include "Objet.h"


class Jeu {

private :

	Vaisseau v;
	Perso p;
    Objet tabo[8];

	

public :

    Jeu ();

    const Vaisseau& getVaisseau () const;                        //< \brief accesseur nécesseaire pour l'affichage
    const Perso& getPerso () const;                          //< \brief accesseur nécesseaire pour l'affichage
    Objet getObjet (int id) const; 

    bool actionClavier(const char touche);   
    bool PersoPresDeObjet();       
    void interationdemande();
};

inline const Vaisseau& Jeu::getVaisseau () const { return v; }         // du code court comme ca doit être en inline

inline const Perso& Jeu::getPerso () const { return p; }

inline Objet Jeu::getObjet(int id) const { return tabo[id]; }


#endif