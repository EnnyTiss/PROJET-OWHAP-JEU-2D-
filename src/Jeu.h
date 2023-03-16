#ifndef _JEU_H
#define _JEU_H
#include "cassert"
#include "Perso.h"
#include "Vaisseau.h"
#include "Objet.h"
#include "Timer.h"
#include "BarreProg.h"
#include "Etape.h"


class Jeu {

private :

	Vaisseau v;
	Perso p;
    Objet tabo[8];
    Timer timer;
    BarreProg BP;
    Etape E;


public :

    Jeu ();

    const Vaisseau& getVaisseau () const;                        //< \brief accesseur nécesseaire pour l'affichage
    const Perso& getPerso () const;                          //< \brief accesseur nécesseaire pour l'affichage
    Objet& getObjet (int id); 
    Objet getObjet (int id) const; 
    const BarreProg& getBarreProg() const;
    Etape getEtape () const;                          //< \brief accesseur nécesseaire pour l'affichage


    Timer& getTimer (); 
    Timer getTimer () const; 

    bool actionClavier(const char touche);   
    bool PersoPresDeObjet();       
    void interationdemande();
};

inline const Vaisseau& Jeu::getVaisseau () const { return v; }         // du code court comme ca doit être en inline

inline const Perso& Jeu::getPerso () const { return p; }
inline  Etape Jeu::getEtape () const { return E; }


inline Objet& Jeu::getObjet(int id)  { return tabo[id]; }
inline Objet Jeu::getObjet(int id) const { return tabo[id]; }

inline Timer& Jeu::getTimer () {return timer;}
inline Timer Jeu::getTimer () const {return timer;}

inline const BarreProg& Jeu::getBarreProg() const { return BP; }         // du code court comme ca doit être en inline




#endif