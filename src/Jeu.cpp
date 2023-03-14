#include "Jeu.h"
#include <iostream>
using namespace std;

Jeu::Jeu() : v(), p() {
	
}

//const Vaisseau& Jeu::getVaisseau () const{ return v; }

//const Perso& Jeu::getPerso () const{	return p; }

bool Jeu::PersoPresDeObjet(){
	
	int xP = getPerso().getX();
	int yP = getPerso().getY();

	for (int i=xP-1; i<xP+2; i++){
		for (int j=yP-1; j<yP+2; j++){
			assert(getVaisseau().getXY(i,j)!= 'P');
			if (getVaisseau().getXY(i,j)!='.' && getVaisseau().getXY(i,j) != '#' && getVaisseau().getXY(i,j) != ' '){
				return true;
				break;
			}
			
		}
	}  return false;
}

void Jeu::interationdemande(){
	if (PersoPresDeObjet())
	{
		cout<<"y'a un truc"<<endl;

		int b;
		int a;
		int xP = getPerso().getX();
		int yP = getPerso().getY();

		for (int i=xP-1; i<xP+2; i++){
			for (int j=yP-1; j<yP+2; j++){
				assert(getVaisseau().getXY(i,j)!= 'P');
				if (getVaisseau().getXY(i,j)!='.' && getVaisseau().getXY(i,j) != '#' && getVaisseau().getXY(i,j) != ' '){
				 a=i;
				 b=j;
				 cout<<a<<" "<<b<<"    "<<endl;
				}
			
			}
	}
	} else cout<<"ya r        "<<endl;
}


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
		case 'i' :
				interationdemande();
				break;
	}
	

	return false;
}

