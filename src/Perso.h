#ifndef _PERSO_H
#define _PERSO_H

#include "Vaisseau.h"
#include "Vec2D.h"


/**
@brief Un Perso = sa position 2D
*/
class Perso {

private :

	Vec2D posPerso;

public:

    Perso ();

    void gauche (const Vaisseau & t);
    void droite (const Vaisseau & t);
    void haut (const Vaisseau & t);
    void bas (const Vaisseau & t);

    Vec2D getPosPerso () const;
    void setPosPerso(int a, int b) ;

};


inline Vec2D Perso::getPosPerso () const { return posPerso; }
 


//inline int Perso::getY () const { return m_y; }


#endif