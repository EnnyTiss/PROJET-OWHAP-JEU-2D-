#ifndef _PERSO_H
#define _PERSO_H

#include "Vaisseau.h"

/**
@brief Un Perso = sa position 2D
*/
class Perso {

private :

	int m_x, m_y;

public:

    Perso ();

    void gauche (const Vaisseau & t);
    void droite (const Vaisseau & t);
    void haut (const Vaisseau & t);
    void bas (const Vaisseau & t);

    int getX () const;
    int getY () const;

};


inline int Perso::getX () const { return m_x; }

inline int Perso::getY () const { return m_y; }


#endif