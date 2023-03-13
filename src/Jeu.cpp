#include "Jeu.h"

Jeu::Jeu() : v(), p() {
	
}

//const Vaisseau& Jeu::getVaisseau () const{ return v; }

//const Perso& Jeu::getPerso () const{	return p; }



bool Jeu::actionClavier (const char touche) {
	switch(touche) {
		case 'q' :
				p.gauche(v);
				break;
		case 'd' :
				p.droite(v);
				break;
		case 'z' :
				p.haut(v);
				break;
		case 's' :
				p.bas(v);
				break;
	}

	
	return false;
}

