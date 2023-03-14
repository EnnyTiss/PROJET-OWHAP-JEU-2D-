#include "Perso.h"

Perso::Perso () {
    
	m_x = 1;
	m_y = 1;
}

void Perso::haut (const Vaisseau & t) {
	if (t.estPositionPersoValide(m_x-1,m_y)) m_x--;
}

void Perso::bas (const Vaisseau & t) {
	if (t.estPositionPersoValide(m_x+1,m_y)) m_x++;
}

void Perso::droite (const Vaisseau & t) {
	if (t.estPositionPersoValide(m_x,m_y+1)) m_y++;
}

void Perso::gauche(const Vaisseau & t) {
	if (t.estPositionPersoValide(m_x,m_y-1)) m_y--;
}
