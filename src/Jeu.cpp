#include "Jeu.h"
#include <iostream>
using namespace std;

Jeu::Jeu() : v(), p() {
	
}

//const Vaisseau& Jeu::getVaisseau () const{ return v; }

//const Perso& Jeu::getPerso () const{	return p; }

void Jeu::interationdemande(){
	//if (j.PersoPresDeObjet())
	//{
		int b;
		int a;
		int x =getPerso().getX();int xmax =x;
		int y =  getPerso().getY(); int ymax=y;
		for (int i =x-1; i<xmax+1;i++)
		{for (int j=y-1; j<ymax+1;j++)
			{if (getVaisseau().getXY(i,j)!='.' && getVaisseau().getXY(i,j)!='#' && getVaisseau().getXY(i,j)!='P')
				a=i;
				b=j;
				cout<<a<<b<<endl;
			}
		
		}
		

	//}
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

bool Jeu::PersoPresDeObjet(){
	
	int xP = getPerso().getX();
	int yP = getPerso().getY();

	for (int i=xP-1; i<xP+1; i++){
		for (int j=yP-1; j<yP+1; j++){
			assert(getVaisseau().getXY(i,j)!= 'P');
			if (getVaisseau().getXY(i,j) != '.' && getVaisseau().getXY(i,j) != '#' && getVaisseau().getXY(i,j) != ' '){
				return true;
				break;
			}
			else return false;
		}
	} 
}