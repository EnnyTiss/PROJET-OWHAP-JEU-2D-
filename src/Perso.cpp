#include "Perso.h"

Perso::Perso () {
	posPerso.x=5;
	posPerso.y=16;
}

void Perso::haut (const Vaisseau & t) {
	if (t.estPositionPersoValide(posPerso.x-1,posPerso.y)) posPerso.x--;
}

void Perso::bas (const Vaisseau & t) {
	if (t.estPositionPersoValide(posPerso.x+1,posPerso.y)) posPerso.x++;
}

void Perso::droite (const Vaisseau & t) {
	if (t.estPositionPersoValide(posPerso.x,posPerso.y+1)) posPerso.y++;
}

void Perso::gauche(const Vaisseau & t) {
	if (t.estPositionPersoValide(posPerso.x,posPerso.y-1)) posPerso.y--;
}

