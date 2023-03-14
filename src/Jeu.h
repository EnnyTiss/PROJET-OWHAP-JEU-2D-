#ifndef _JEU_H
#define _JEU_H

#include "Perso.h"
#include "Vaisseau.h"
#include "cassert"


class Jeu {

private :

	Vaisseau v;
	Perso p;
	

public :

    Jeu ();

    const Vaisseau& getVaisseau () const;                        //< \brief accesseur nécesseaire pour l'affichage
    const Perso& getPerso () const;                          //< \brief accesseur nécesseaire pour l'affichage

    bool actionClavier(const char touche);         //< \brief rend vrai si mange une pastille, faux sinon
    bool PersoPresDeObjet(); //< \brief vérifie qu'il y a un objet proche du personnage
};

inline const Vaisseau& Jeu::getVaisseau () const { return v; }         // du code court comme ca doit être en inline

inline const Perso& Jeu::getPerso () const { return p; }



#endif